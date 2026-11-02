// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x5a0000-0x5affff

// ==== FUN_005a00e0 @ 0x005a00e0 ====

void FUN_005a00e0(byte param_1)

{
  void *in_ECX;
  
  FUN_005a0100();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a0100 @ 0x005a0100 ====

void FUN_005a0100(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009c0be0;
  if (in_ECX[0xba03] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0030,
                         s_d__usa_24_0_1_2__develop_module__009bffc8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x5e;
  iVar3 = 0x200;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c00b0,
                           s_d__usa_24_0_1_2__develop_module__009c0048,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x5d;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0xba04];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009c0b60;
    *in_ECX = &PTR_FUN_009c0aa0;
    return;
  }
  if (*(int *)((int)_Memory + 0x170) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0130,
                         s_d__usa_24_0_1_2__develop_module__009c00c8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a01f0 @ 0x005a01f0 ====

void FUN_005a01f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005a0210();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a0210 @ 0x005a0210 ====

void FUN_005a0210(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009c0bf8;
  if (in_ECX[0x6603] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c01b0,
                         s_d__usa_24_0_1_2__develop_module__009c0148,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x34;
  iVar3 = 0x200;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0230,
                           s_d__usa_24_0_1_2__develop_module__009c01c8,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x33;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x6604];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009c0b68;
    *in_ECX = &PTR_FUN_009c0ab8;
    return;
  }
  if (*(int *)((int)_Memory + 200) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c02b0,
                         s_d__usa_24_0_1_2__develop_module__009c0248,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a0300 @ 0x005a0300 ====

void FUN_005a0300(byte param_1)

{
  void *in_ECX;
  
  FUN_005a0320();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a0320 @ 0x005a0320 ====

void FUN_005a0320(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009c0c10;
  if (in_ECX[0x11403] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0330,
                         s_d__usa_24_0_1_2__develop_module__009c02c8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x8b;
  iVar3 = 0x200;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c03b0,
                           s_d__usa_24_0_1_2__develop_module__009c0348,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x8a;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x11404];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009c0b70;
    *in_ECX = &PTR_FUN_009c0ad0;
    return;
  }
  if (*(int *)((int)_Memory + 0x224) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0430,
                         s_d__usa_24_0_1_2__develop_module__009c03c8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a0410 @ 0x005a0410 ====

void FUN_005a0410(byte param_1)

{
  void *in_ECX;
  
  FUN_005a0430();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a0430 @ 0x005a0430 ====

void FUN_005a0430(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009c0c28;
  if (in_ECX[0x1403] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c04b0,
                         s_d__usa_24_0_1_2__develop_module__009c0448,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x29;
  iVar3 = 0x80;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0530,
                           s_d__usa_24_0_1_2__develop_module__009c04c8,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x28;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x1404];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009c0b78;
    *in_ECX = &PTR_FUN_009c0ae8;
    return;
  }
  if (*(int *)((int)_Memory + 0x9c) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c05b0,
                         s_d__usa_24_0_1_2__develop_module__009c0548,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a0520 @ 0x005a0520 ====

void FUN_005a0520(byte param_1)

{
  void *in_ECX;
  
  FUN_005a0540();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a0540 @ 0x005a0540 ====

void FUN_005a0540(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009c0c40;
  if (in_ECX[0x1503] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0630,
                         s_d__usa_24_0_1_2__develop_module__009c05c8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x2b;
  iVar3 = 0x80;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c06b0,
                           s_d__usa_24_0_1_2__develop_module__009c0648,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x2a;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x1504];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009c0b80;
    *in_ECX = &PTR_FUN_009c0b00;
    return;
  }
  if (*(int *)((int)_Memory + 0xa4) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0730,
                         s_d__usa_24_0_1_2__develop_module__009c06c8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a0630 @ 0x005a0630 ====

void FUN_005a0630(byte param_1)

{
  void *in_ECX;
  
  FUN_005a0650();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a0650 @ 0x005a0650 ====

void FUN_005a0650(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009c0c58;
  if (in_ECX[0x6d3] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c07b0,
                         s_d__usa_24_0_1_2__develop_module__009c0748,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x6e;
  iVar3 = 0x10;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0830,
                           s_d__usa_24_0_1_2__develop_module__009c07c8,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x6d;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x6d4];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009c0b88;
    *in_ECX = &PTR_FUN_009c0b18;
    return;
  }
  if (*(int *)((int)_Memory + 0x1b0) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c08b0,
                         s_d__usa_24_0_1_2__develop_module__009c0848,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a0740 @ 0x005a0740 ====

void FUN_005a0740(byte param_1)

{
  void *in_ECX;
  
  FUN_005a0760();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a0760 @ 0x005a0760 ====

void FUN_005a0760(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009c0c70;
  if (in_ECX[0x1603] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0930,
                         s_d__usa_24_0_1_2__develop_module__009c08c8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x2d;
  iVar3 = 0x80;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c09b0,
                           s_d__usa_24_0_1_2__develop_module__009c0948,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x2c;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x1604];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009c0b90;
    *in_ECX = &PTR_FUN_009c0b30;
    return;
  }
  if (*(int *)((int)_Memory + 0xac) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0a30,
                         s_d__usa_24_0_1_2__develop_module__009c09c8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a0850 @ 0x005a0850 ====

void FUN_005a0850(byte param_1)

{
  void *in_ECX;
  
  FUN_0059e7c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a0870 @ 0x005a0870 ====

void FUN_005a0870(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0d44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a0890 @ 0x005a0890 ====

void FUN_005a0890(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005a0892. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 4))();
  return;
}


// ==== FUN_005a08a0 @ 0x005a08a0 ====

void FUN_005a08a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x24))(*param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1c))(*param_2,*param_3,param_1,param_4);
  }
  return;
}


// ==== FUN_005a08e0 @ 0x005a08e0 ====

void FUN_005a08e0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x24))(*param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x20))(*param_2,*param_3,param_1,param_4);
  }
  return;
}


// ==== FUN_005a0920 @ 0x005a0920 ====

void FUN_005a0920(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x24))(*param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x24))(*param_2,*param_3,param_1,param_4);
  }
  return;
}


// ==== FUN_005a0960 @ 0x005a0960 ====

void FUN_005a0960(undefined4 *param_1)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x24))(*param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x28))();
  }
  return;
}


// ==== FUN_005a0980 @ 0x005a0980 ====

void FUN_005a0980(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 param_6)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x24))(*param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x2c))(*param_4,*param_5,param_1,param_6,param_2,param_3);
  }
  return;
}


// ==== FUN_005a09c0 @ 0x005a09c0 ====

void FUN_005a09c0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x24))(*param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x30))(param_2,param_3,param_4,param_1,param_5,param_6);
  }
  return;
}


// ==== FUN_005a0a00 @ 0x005a0a00 ====

void FUN_005a0a00(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x24))(*param_1);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x34))(param_2,param_3,param_4,param_1,param_5,param_6);
  }
  return;
}


// ==== FUN_005a0a40 @ 0x005a0a40 ====

void FUN_005a0a40(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_ECX;
  
  iVar5 = (**(code **)(*param_1 + 4))();
  if (iVar5 == 0x40001) {
    puVar1 = *(undefined4 **)(in_ECX + 0x34);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      puVar3 = (undefined4 *)puVar2[4];
      for (puVar4 = (undefined4 *)*puVar3; puVar4 != puVar3; puVar4 = (undefined4 *)*puVar4) {
        FUN_005a0890(param_1);
      }
    }
  }
  return;
}


// ==== FUN_005a0ab0 @ 0x005a0ab0 ====

undefined4 FUN_005a0ab0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0xc);
}


// ==== FUN_005a0ae0 @ 0x005a0ae0 ====

void FUN_005a0ae0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009c0d80;
  *(undefined1 *)(in_ECX + 1) = local_5;
  uVar1 = FUN_005a11b0();
  in_ECX[3] = uVar1;
  in_ECX[4] = 0;
  local_4 = in_ECX[3];
  FUN_005a17b0(9,&local_4);
  in_ECX[9] = 1;
  in_ECX[10] = 1;
  *(undefined1 *)(in_ECX + 0xb) = local_5;
  uVar1 = FUN_005a12d0();
  in_ECX[0xd] = uVar1;
  in_ECX[0xe] = 0;
  local_4 = in_ECX[0xd];
  FUN_005a17b0(9,&local_4);
  in_ECX[0x13] = 1;
  in_ECX[0x14] = 1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5afc8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afc8 = in_ECX;
  return;
}


// ==== FUN_005a0b90 @ 0x005a0b90 ====

/* WARNING: Removing unreachable block (ram,0x005a0c25) */

void FUN_005a0b90(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *_Memory;
  int in_ECX;
  int *piVar3;
  int *local_4;
  
  local_4 = *(int **)(in_ECX + 0x34);
  piVar3 = (int *)*local_4;
  if (piVar3 != local_4) {
    do {
      puVar1 = (undefined4 *)piVar3[4];
      for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
        (**(code **)(*DAT_00b5afc4 + 4))(puVar2[2]);
      }
      puVar1 = (undefined4 *)piVar3[4];
      _Memory = (void *)*puVar1;
      *puVar1 = puVar1;
      *(int *)(piVar3[4] + 4) = piVar3[4];
      piVar3[5] = 0;
      if (_Memory != (void *)piVar3[4]) {
        _free(_Memory);
        return;
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != local_4);
  }
  FUN_005a1d70();
  FUN_005a14f0();
  local_4 = *(int **)(in_ECX + 0x34);
  if (*(int *)(in_ECX + 0x40) != *(int *)(in_ECX + 0x44)) {
    *(int *)(in_ECX + 0x44) = *(int *)(in_ECX + 0x40);
  }
  FUN_005a1560(*(undefined4 *)(in_ECX + 0x40),9,&local_4);
  *(undefined4 *)(in_ECX + 0x4c) = 1;
  *(undefined4 *)(in_ECX + 0x50) = 1;
  return;
}


// ==== FUN_005a0c60 @ 0x005a0c60 ====

void FUN_005a0c60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0d80;
  DAT_00b5afc8 = 0;
  FUN_005a0b90();
  if ((void *)in_ECX[0x10] == (void *)0x0) {
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    FUN_005a14f0();
    _free((void *)in_ECX[0xd]);
    return;
  }
  _free((void *)in_ECX[0x10]);
  return;
}


// ==== FUN_005a0ce0 @ 0x005a0ce0 ====

int * FUN_005a0ce0(undefined4 param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *in_ECX;
  int unaff_ESI;
  undefined1 uStack00000000;
  undefined1 auStack_2 [2];
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x24))(param_1);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  FUN_005a1e60(&uStack00000000);
  (**(code **)(*piVar2 + 8))();
  FUN_00897340(auStack_2 + -6,&uStack00000000);
  if (unaff_ESI != in_ECX[0xd]) {
    for (puVar1 = (undefined4 *)**(undefined4 **)(unaff_ESI + 0x10);
        (puVar1 != *(undefined4 **)(unaff_ESI + 0x10) && ((int *)puVar1[2] != piVar2));
        puVar1 = (undefined4 *)*puVar1) {
    }
    if (puVar1 != *(undefined4 **)(unaff_ESI + 0x10)) {
      FUN_005171c0(&uStack00000000,puVar1);
    }
    if (*(int *)(unaff_ESI + 0x14) == 0) {
      FUN_005a1900(&uStack00000000,unaff_ESI);
    }
  }
  return piVar2;
}


// ==== FUN_005a0d80 @ 0x005a0d80 ====

void FUN_005a0d80(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *_Memory;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  int *piVar6;
  int *local_2c;
  int local_28;
  int *piStack_24;
  int *piStack_20;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  local_28 = in_ECX + 0x2c;
  FUN_00897340(&local_2c,&param_1);
  piVar4 = local_2c;
  if (local_2c == *(int **)(in_ECX + 0x34)) {
    FUN_00401740(s__Effect__Doll__d_No_Exist__009c0d24,0x1a);
    uVar5 = FUN_00404230(local_1c);
    FUN_00796d50(uVar5);
    if (local_4 < 0x10) {
      return;
    }
    _free(local_18);
    return;
  }
  local_2c = (int *)local_2c[4];
  piVar6 = (int *)*local_2c;
  if (piVar6 != local_2c) {
    do {
      piVar1 = (int *)piVar6[2];
      param_1 = (**(code **)(*piVar1 + 0xc))();
      FUN_005a8440(&piStack_24,&param_1);
      for (piVar2 = piStack_24; piVar2 != piStack_20; piVar2 = (int *)*piVar2) {
      }
      FUN_005a1dd0(&param_1,piStack_24,piStack_20);
      (**(code **)(*DAT_00b5afc4 + 4))(piVar1);
      piVar6 = (int *)*piVar6;
    } while (piVar6 != local_2c);
  }
  puVar3 = (undefined4 *)piVar4[4];
  _Memory = (void *)*puVar3;
  *puVar3 = puVar3;
  *(int *)(piVar4[4] + 4) = piVar4[4];
  piVar4[5] = 0;
  if (_Memory == (void *)piVar4[4]) {
    FUN_005a1900(&param_1,piVar4);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a0ec0 @ 0x005a0ec0 ====

undefined4 FUN_005a0ec0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int iVar3;
  int *in_ECX;
  undefined1 uStack00000000;
  undefined1 auStack_2e [6];
  undefined1 auStack_28 [8];
  undefined4 uStack_20;
  void *pvStack_1c;
  uint uStack_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x24))(param_1);
  if (iVar1 == 0) {
    FUN_005a1b40(auStack_28,auStack_2e + -6);
    FUN_00897340(&uStack00000000,&param_1);
    if (_uStack00000000 == in_ECX[0xd]) {
      iVar1 = FUN_005a10a0();
      iVar3 = FUN_005a1130(iVar1,*(undefined4 *)(iVar1 + 4),&param_2);
      FUN_00517200(1);
      *(int *)(iVar1 + 4) = iVar3;
      uStack_20 = param_1;
      **(int **)(iVar3 + 4) = iVar3;
      FUN_005a1aa0(auStack_2e + -6);
      FUN_005a1f60(auStack_28,&uStack_20);
      FUN_008984a0();
      FUN_008984a0();
      return 1;
    }
    iVar1 = *(int *)(_uStack00000000 + 0x10);
    iVar3 = FUN_005a1130(iVar1,*(undefined4 *)(iVar1 + 4),&param_2);
    FUN_00517200(1);
    *(int *)(iVar1 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
    return 1;
  }
  FUN_00401740(s__Effect__Doll__d__d_Not_Empty__009c0d04,0x1e);
  uVar2 = FUN_00404230(&uStack_20);
  FUN_00796d50(uVar2);
  if (uStack_8 < 0x10) {
    return 0;
  }
  _free(pvStack_1c);
  return extraout_EAX;
}


// ==== FUN_005a1030 @ 0x005a1030 ====

int FUN_005a1030(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009825f0;
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


// ==== Catch@005a1096 @ 0x005a1096 ====

void Catch_005a1096(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005a10a0 @ 0x005a10a0 ====

void FUN_005a10a0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982600;
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


// ==== Catch@005a110f @ 0x005a110f ====

void Catch_005a110f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005a1130 @ 0x005a1130 ====

void FUN_005a1130(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982610;
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


// ==== Catch@005a1199 @ 0x005a1199 ====

void Catch_005a1199(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005a11b0 @ 0x005a11b0 ====

void FUN_005a11b0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982620;
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


// ==== Catch@005a121f @ 0x005a121f ====

void Catch_005a121f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005a1240 @ 0x005a1240 ====

void * FUN_005a1240(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982630;
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


// ==== Catch@005a12ad @ 0x005a12ad ====

void Catch_005a12ad(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005a12d0 @ 0x005a12d0 ====

void FUN_005a12d0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982640;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x18);
  if (pvVar1 != (void *)0x0) {
    *(void **)pvVar1 = pvVar1;
  }
  if ((undefined4 *)((int)pvVar1 + 4) != (undefined4 *)0x0) {
    *(undefined4 *)((int)pvVar1 + 4) = pvVar1;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005a133f @ 0x005a133f ====

void Catch_005a133f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005a1360 @ 0x005a1360 ====

void FUN_005a1360(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982650;
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


// ==== Catch@005a13c6 @ 0x005a13c6 ====

void Catch_005a13c6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005a13d0 @ 0x005a13d0 ====

void FUN_005a13d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005a1030(param_1,param_2,param_3);
  return;
}


// ==== FUN_005a13f0 @ 0x005a13f0 ====

int FUN_005a13f0(int param_1,int param_2,undefined4 param_3)

{
  FUN_005a1360(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_005a1420 @ 0x005a1420 ====

void FUN_005a1420(uint param_1)

{
  int in_ECX;
  undefined1 local_44 [4];
  undefined1 local_40;
  undefined4 local_30;
  undefined4 local_2c;
  undefined **local_28 [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  if (0xfffffffU - *(int *)(in_ECX + 8) < param_1) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = 0;
    FUN_00401740(s_list<T>_too_long_0099d1d0,0x10);
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
  *(uint *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return;
}


// ==== FUN_005a14b0 @ 0x005a14b0 ====

void FUN_005a14b0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_005a1130(param_1,*(undefined4 *)(param_1 + 4),param_2);
  FUN_00517200(1);
  *(int *)(param_1 + 4) = iVar1;
  **(int **)(iVar1 + 4) = iVar1;
  return;
}


// ==== __break @ 0x005a14ed ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_005a14f0 @ 0x005a14f0 ====

void FUN_005a14f0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  void *_Memory;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 4);
  iVar2 = *piVar1;
  *piVar1 = (int)piVar1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  if (iVar2 == *(int *)(in_ECX + 4)) {
    return;
  }
  puVar3 = *(undefined4 **)(iVar2 + 0x10);
  _Memory = (void *)*puVar3;
  *puVar3 = puVar3;
  *(int *)(*(int *)(iVar2 + 0x10) + 4) = *(int *)(iVar2 + 0x10);
  *(undefined4 *)(iVar2 + 0x14) = 0;
  if (_Memory == *(void **)(iVar2 + 0x10)) {
    _free(*(void **)(iVar2 + 0x10));
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a1560 @ 0x005a1560 ====

void FUN_005a1560(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982660;
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
      uVar5 = FUN_005a13d0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_005a13f0(uVar5,param_2,&local_18);
      FUN_005a13d0(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_005a1030(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_005a13f0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_005a1030(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005a16c1 @ 0x005a16c1 ====

void Catch_005a16c1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005a17b0 @ 0x005a17b0 ====

void FUN_005a17b0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982670;
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
    uVar2 = FUN_005a13f0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005a1844 @ 0x005a1844 ====

void Catch_005a1844(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005a1860 @ 0x005a1860 ====

void FUN_005a1860(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982680;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != param_3; param_2 = (undefined4 *)*param_2) {
    FUN_005a14b0(param_1,param_2 + 2);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005a18c8 @ 0x005a18c8 ====

void Catch_005a18c8(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int unaff_EBP;
  
  puVar2 = *(undefined4 **)(unaff_EBP + 0xc);
  for (puVar1 = *(undefined4 **)(unaff_EBP + -0x14); puVar1 != puVar2;
      puVar1 = (undefined4 *)*puVar1) {
    FUN_005171c0(unaff_EBP + -0x1c,*(undefined4 *)(*(int *)(unaff_EBP + 8) + 4));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005a1900 @ 0x005a1900 ====

void FUN_005a1900(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  void *_Memory;
  int in_ECX;
  uint uVar5;
  
  uVar5 = (param_2[2] ^ 0xdeadbeefU) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar5) {
    uVar5 = uVar5 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  iVar3 = *(int *)(in_ECX + 0x14);
  iVar1 = uVar5 * 4;
  piVar2 = *(int **)(iVar1 + iVar3);
  while ((param_2 == piVar2 &&
         (*(undefined4 *)(iVar1 + iVar3) = **(undefined4 **)(iVar1 + iVar3), uVar5 != 0))) {
    iVar3 = *(int *)(in_ECX + 0x14);
    uVar5 = uVar5 - 1;
    iVar1 = uVar5 * 4;
    piVar2 = *(int **)(iVar1 + iVar3);
  }
  if (param_2 == *(int **)(in_ECX + 8)) {
    *param_1 = *param_2;
    return;
  }
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  puVar4 = (undefined4 *)param_2[4];
  _Memory = (void *)*puVar4;
  *puVar4 = puVar4;
  *(int *)(param_2[4] + 4) = param_2[4];
  param_2[5] = 0;
  if (_Memory == (void *)param_2[4]) {
    _free((void *)param_2[4]);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a19c0 @ 0x005a19c0 ====

void FUN_005a19c0(uint param_1,undefined1 param_2)

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
    FUN_005a1560(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_005a1a30 @ 0x005a1a30 ====

/* WARNING: Removing unreachable block (ram,0x005a1a4b) */
/* WARNING: Removing unreachable block (ram,0x005a1a50) */
/* WARNING: Removing unreachable block (ram,0x005a1a5e) */

void FUN_005a1a30(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_005a1560(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_005a1a80 @ 0x005a1a80 ====

void FUN_005a1a80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005a1860(param_1,param_2,param_3,param_3);
  return;
}


// ==== FUN_005a1aa0 @ 0x005a1aa0 ====

void FUN_005a1aa0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982690;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_005a10a0();
  *(undefined4 *)(in_ECX + 4) = uVar1;
  *(undefined4 *)(in_ECX + 8) = 0;
  local_8 = 0;
  FUN_005a1a80(**(undefined4 **)(in_ECX + 4),**(undefined4 **)(param_1 + 4),
               *(undefined4 **)(param_1 + 4));
  ExceptionList = local_10;
  return;
}


// ==== Catch@005a1b29 @ 0x005a1b29 ====

void Catch_005a1b29(void)

{
  FUN_008984a0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005a1b40 @ 0x005a1b40 ====

/* WARNING: Removing unreachable block (ram,0x005a1c28) */

void FUN_005a1b40(int *param_1,uint *param_2)

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
      FUN_005a19c0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_005a1240(puVar7,puVar7[1],param_2);
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


// ==== FUN_005a1d70 @ 0x005a1d70 ====

void FUN_005a1d70(void)

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
    FUN_005a1a30(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a1dd0 @ 0x005a1dd0 ====

void FUN_005a1dd0(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  
  piVar3 = param_3;
  piVar2 = param_2;
  if ((param_2 == (int *)**(int **)(in_ECX + 8)) && (param_3 == *(int **)(in_ECX + 8))) {
    FUN_005a1d70();
    *param_1 = **(undefined4 **)(in_ECX + 8);
    return;
  }
  while (piVar2 != piVar3) {
    piVar1 = (int *)*piVar2;
    FUN_00598f60(&param_2,piVar2);
    piVar2 = piVar1;
  }
  *param_1 = piVar2;
  return;
}


// ==== FUN_005a1e30 @ 0x005a1e30 ====

void FUN_005a1e30(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = *param_3;
  FUN_005a1aa0(param_3 + 1);
  return;
}


// ==== FUN_005a1e60 @ 0x005a1e60 ====

int FUN_005a1e60(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *local_8;
  undefined4 *local_4;
  
  FUN_005a8440(&local_8,param_1);
  iVar2 = 0;
  for (puVar1 = local_8; puVar1 != local_4; puVar1 = (undefined4 *)*puVar1) {
    iVar2 = iVar2 + 1;
  }
  FUN_005a1dd0(&param_1,local_8,local_4);
  return iVar2;
}


// ==== FUN_005a1eb0 @ 0x005a1eb0 ====

void * FUN_005a1eb0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009826a0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x18);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_005a1e30(param_1,param_2,param_3);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@005a1f1d @ 0x005a1f1d ====

void Catch_005a1f1d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005a1f40 @ 0x005a1f40 ====

void FUN_005a1f40(byte param_1)

{
  void *in_ECX;
  
  FUN_005a0c60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a1f60 @ 0x005a1f60 ====

/* WARNING: Removing unreachable block (ram,0x005a2048) */

void FUN_005a1f60(int *param_1,uint *param_2)

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
      FUN_005a19c0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_005a1eb0(puVar7,puVar7[1],param_2);
  FUN_005a1420(1);
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


// ==== FUN_005a2190 @ 0x005a2190 ====

void FUN_005a2190(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0dbc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a21c0 @ 0x005a21c0 ====

void FUN_005a21c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0dcc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5afcc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afcc = in_ECX;
  return;
}


// ==== FUN_005a21f0 @ 0x005a21f0 ====

undefined4 FUN_005a21f0(int param_1)

{
  undefined1 *puVar1;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = *(undefined4 *)(param_1 + 0xc);
  local_4 = *(undefined4 *)(param_1 + 8);
  puVar1 = (undefined1 *)(param_1 + 0x10);
  param_1 = *(undefined4 *)(param_1 + 4);
  (**(code **)(*DAT_00b5afc4 + 8))(&local_4,&local_8,&param_1,*puVar1);
  return 1;
}


// ==== FUN_005a2240 @ 0x005a2240 ====

undefined4 FUN_005a2240(int param_1)

{
  param_1 = *(undefined4 *)(param_1 + 4);
  (**(code **)(*DAT_00b5afc4 + 0x10))(&param_1);
  return 1;
}


// ==== FUN_005a2260 @ 0x005a2260 ====

undefined4 FUN_005a2260(int param_1)

{
  int iVar1;
  undefined4 *puStack_20;
  undefined4 *puStack_1c;
  undefined4 uStack_18;
  undefined4 local_10;
  undefined4 local_c [3];
  
  iVar1 = param_1;
  local_c[0] = *(undefined4 *)(param_1 + 8);
  local_10 = *(undefined4 *)(param_1 + 0xc);
  param_1 = *(undefined4 *)(param_1 + 4);
  uStack_18 = 1;
  puStack_1c = &param_1;
  puStack_20 = &local_10;
  (**(code **)(*DAT_00b5afc4 + 8))(local_c);
  local_c[0] = *(undefined4 *)(iVar1 + 0x14);
  puStack_20 = *(undefined4 **)(iVar1 + 0x18);
  uStack_18 = *(undefined4 *)(iVar1 + 0x10);
  puStack_1c = (undefined4 *)0x0;
  (**(code **)(*DAT_00b5afc8 + 8))(local_c + -2,&uStack_18,&puStack_20,&puStack_1c,local_c);
  return 1;
}


// ==== FUN_005a22f0 @ 0x005a22f0 ====

undefined4 FUN_005a22f0(int param_1)

{
  int iVar1;
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = *(undefined4 *)(param_1 + 0xc);
  local_4 = *(undefined4 *)(param_1 + 8);
  iVar1 = param_1 + 0x10;
  param_1 = *(undefined4 *)(param_1 + 4);
  (**(code **)(*DAT_00b5afc4 + 0xc))(&local_4,&local_8,&param_1,iVar1);
  return 1;
}


// ==== FUN_005a2340 @ 0x005a2340 ====

undefined4 FUN_005a2340(int param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = *(undefined4 *)(param_1 + 0x14);
  local_c = *(undefined4 *)(param_1 + 0x10);
  local_8 = *(undefined4 *)(param_1 + 8);
  local_4 = *(undefined4 *)(param_1 + 4);
  param_1 = *(undefined4 *)(param_1 + 0xc);
  (**(code **)(*DAT_00b5afc8 + 8))(&local_4,&local_8,&local_c,&local_10,&param_1);
  return 1;
}


// ==== FUN_005a23a0 @ 0x005a23a0 ====

undefined4 FUN_005a23a0(int param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = *(undefined4 *)(param_1 + 0x14);
  local_c = *(undefined4 *)(param_1 + 0x10);
  local_8 = *(undefined4 *)(param_1 + 8);
  local_4 = *(undefined4 *)(param_1 + 4);
  param_1 = *(undefined4 *)(param_1 + 0xc);
  (**(code **)(*DAT_00b5afc8 + 0xc))(&local_4,&local_8,&local_c,&local_10,&param_1);
  return 1;
}


// ==== FUN_005a2400 @ 0x005a2400 ====

undefined4 FUN_005a2400(int param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = *(undefined4 *)(param_1 + 0x14);
  local_c = *(undefined4 *)(param_1 + 0x10);
  local_8 = *(undefined4 *)(param_1 + 8);
  local_4 = *(undefined4 *)(param_1 + 4);
  param_1 = *(undefined4 *)(param_1 + 0xc);
  (**(code **)(*DAT_00b5afc8 + 0x10))(&local_4,&local_8,&local_c,&local_10,&param_1);
  return 1;
}


// ==== FUN_005a2460 @ 0x005a2460 ====

undefined4 FUN_005a2460(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = *(undefined4 *)(param_1 + 0x28);
  local_c = *(undefined4 *)(param_1 + 0x24);
  iVar1 = param_1 + 0x18;
  local_4 = *(undefined4 *)(param_1 + 4);
  local_8 = *(undefined4 *)(param_1 + 8);
  iVar2 = param_1 + 0xc;
  param_1 = *(undefined4 *)(param_1 + 0x2c);
  (**(code **)(*DAT_00b5afc8 + 0x18))(&local_4,&local_8,iVar2,iVar1,&local_c,&local_10,&param_1);
  return 1;
}


// ==== FUN_005a24c0 @ 0x005a24c0 ====

undefined4 FUN_005a24c0(int param_1)

{
  param_1 = *(undefined4 *)(param_1 + 4);
  (**(code **)(*DAT_00b5afc8 + 0x14))(&param_1);
  return 1;
}


// ==== FUN_005a24e0 @ 0x005a24e0 ====

undefined4 FUN_005a24e0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = *(undefined4 *)(param_1 + 0x2c);
  local_c = *(undefined4 *)(param_1 + 0x24);
  iVar1 = param_1 + 0x18;
  local_4 = *(undefined4 *)(param_1 + 4);
  local_8 = *(undefined4 *)(param_1 + 8);
  iVar2 = param_1 + 0xc;
  param_1 = *(undefined4 *)(param_1 + 0x28);
  (**(code **)(*DAT_00b5afc8 + 0x1c))(&local_4,&local_8,iVar2,iVar1,&local_c,&local_10,&param_1);
  return 1;
}


// ==== FUN_005a2540 @ 0x005a2540 ====

undefined4 FUN_005a2540(int param_1)

{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_14 = *(undefined4 *)(param_1 + 0x24);
  local_10 = *(undefined4 *)(param_1 + 0x1c);
  local_c = *(undefined4 *)(param_1 + 0x18);
  local_8 = *(undefined4 *)(param_1 + 8);
  local_4 = *(undefined4 *)(param_1 + 4);
  iVar1 = param_1 + 0xc;
  param_1 = *(undefined4 *)(param_1 + 0x20);
  (**(code **)(*DAT_00b5afc8 + 0x20))(&local_4,&local_8,iVar1,&local_c,&local_10,&local_14,&param_1)
  ;
  return 1;
}


// ==== FUN_005a25b0 @ 0x005a25b0 ====

void FUN_005a25b0(void)

{
                    /* WARNING: Could not recover jumptable at 0x005a25b8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5afc8 + 0x34))();
  return;
}


// ==== FUN_005a25e0 @ 0x005a25e0 ====

uint FUN_005a25e0(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  switch(uVar1) {
  case 0x60010000:
    uVar2 = FUN_005a21f0(param_1);
    return uVar2;
  case 0x60010001:
    uVar2 = FUN_005a2240(param_1);
    return uVar2;
  case 0x60010002:
    uVar2 = FUN_005a2260(param_1);
    return uVar2;
  case 0x60010003:
    uVar2 = FUN_005a2340(param_1);
    return uVar2;
  case 0x60010004:
    uVar2 = FUN_005a24e0(param_1);
    return uVar2;
  case 0x60010005:
    uVar2 = FUN_005a2540(param_1);
    return uVar2;
  case 0x60010006:
    uVar2 = FUN_005a24c0(param_1);
    return uVar2;
  case 0x60010007:
    uVar2 = FUN_005a22f0(param_1);
    return uVar2;
  case 0x60010008:
    uVar2 = FUN_005a2400(param_1);
    return uVar2;
  case 0x60010009:
    uVar2 = FUN_005a2460(param_1);
    return uVar2;
  case 0x6001000a:
    uVar2 = FUN_005a23a0(param_1);
    return uVar2;
  default:
    uVar2 = (**(code **)(*DAT_00b5afc8 + 4))(param_1);
    return uVar2 & 0xffffff00;
  }
}


// ==== FUN_005a26e0 @ 0x005a26e0 ====

void FUN_005a26e0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5afcc = 0;
  *in_ECX = &PTR_FUN_009c0dbc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a2710 @ 0x005a2710 ====

void FUN_005a2710(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0f78;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a2730 @ 0x005a2730 ====

void FUN_005a2730(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0f90;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a2750 @ 0x005a2750 ====

void FUN_005a2750(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0fa8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a2770 @ 0x005a2770 ====

void FUN_005a2770(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00803725(param_1,0,&Framework::DollStage::IEffect::RTTI_Type_Descriptor,
                       &Framework::DollStage::Effect::Provider::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,iVar1);
  }
  return;
}


// ==== FUN_005a27b0 @ 0x005a27b0 ====

void FUN_005a27b0(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5afc8 + 0x30))(*param_1);
  if ((iVar1 != 0) || (*param_1 == 0xe)) {
    (**(code **)(*in_ECX + 4))(iVar1);
  }
  return;
}


// ==== FUN_005a27e0 @ 0x005a27e0 ====

void FUN_005a27e0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0fc8;
  pvVar1 = operator_new(0x23018);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005a2a30();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5afc4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afc4 = in_ECX;
  return;
}


// ==== FUN_005a2830 @ 0x005a2830 ====

void FUN_005a2830(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0fc8;
  DAT_00b5afc4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c0f78;
  return;
}


// ==== FUN_005a2860 @ 0x005a2860 ====

void FUN_005a2860(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 unaff_EBX;
  int *unaff_EBP;
  undefined4 *unaff_EDI;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5afc8 + 0x24))(*param_2);
  if (piVar2 == (int *)0x0) {
    iVar3 = (**(code **)(*(int *)in_ECX[1] + 0xc))(1,0);
    if (iVar3 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(iVar3 + 0x20);
    }
  }
  else {
    iVar3 = (**(code **)(*piVar2 + 0x10))();
    if (iVar3 == *param_2) {
      return;
    }
    uVar4 = (**(code **)(*DAT_00b5afc8 + 0x30))(*param_2);
    (**(code **)(*in_ECX + 4))(uVar4);
    iVar3 = (**(code **)(*(int *)in_ECX[1] + 0xc))(1,0);
    unaff_EBP = param_2;
    if (iVar3 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(iVar3 + 0x20);
    }
  }
  cVar1 = (**(code **)(*piVar2 + 0x18))(unaff_EDI,param_2,unaff_EBP,unaff_EBX);
  if (cVar1 == '\0') {
    (**(code **)(*in_ECX + 4))();
    return;
  }
  (**(code **)(*DAT_00b5afc8 + 0x2c))(*param_2,*unaff_EDI,piVar2);
  return;
}


// ==== FUN_005a2930 @ 0x005a2930 ====

void FUN_005a2930(undefined4 param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  int *piVar4;
  undefined4 unaff_retaddr;
  undefined4 uStack_1c;
  undefined4 *puStack_8;
  
  iVar2 = (**(code **)(*DAT_00b5afc8 + 0x24))(*param_2);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(*(int *)in_ECX[1] + 0xc))(1,0);
    if (iVar2 == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(iVar2 + 0x20);
    }
    cVar1 = (**(code **)(*piVar4 + 0x14))(puStack_8,param_2,unaff_retaddr,param_1);
    if (cVar1 == '\0') {
      (**(code **)(*in_ECX + 4))();
      return;
    }
    (**(code **)(*DAT_00b5afc8 + 0x2c))(*param_2,*puStack_8,piVar4);
  }
  else {
    FUN_00401740(&DAT_009c0ddc,0x2c);
    uVar3 = FUN_00404230((int)register0x00000010 + -0x20);
    FUN_00403e50(uVar3);
    if ((undefined4 *)0xf < puStack_8) {
      _free(uStack_1c);
      return;
    }
  }
  return;
}


// ==== FUN_005a2a30 @ 0x005a2a30 ====

void FUN_005a2a30(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009c0fb0;
  in_ECX[1] = &PTR_FUN_009c0fa8;
  in_ECX[0x8c02] = 0;
  in_ECX[0x8c02] = in_ECX[0x8c02] + 0x200;
  in_ECX[0x8c05] = in_ECX + 2;
  in_ECX[0x8c03] = 0;
  in_ECX[0x8c04] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[0x45] = puVar1 + 0x48;
    puVar1[0x46] = 0;
    puVar1[0x47] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x46;
  } while (iVar2 != 0);
  in_ECX[0x8bff] = 0;
  in_ECX[0x8c00] = 0;
  in_ECX[0x8c01] = 0;
  return;
}


// ==== FUN_005a2aa0 @ 0x005a2aa0 ====

undefined4 FUN_005a2aa0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2300c);
}


// ==== FUN_005a2ab0 @ 0x005a2ab0 ====

int FUN_005a2ab0(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x114) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0fe0,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x114) = *(int *)(param_2 + 0x114) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x23014);
  *(int *)(in_ECX + 0x2300c) = *(int *)(in_ECX + 0x2300c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x118);
    *(undefined4 *)((int)pvVar2 + 0x110) = *(undefined4 *)(in_ECX + 0x23010);
    *(void **)(in_ECX + 0x23010) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x23014) = *(undefined4 *)((int)pvVar2 + 0x10c);
  }
  *(undefined4 *)((int)pvVar2 + 0x10c) = 0;
  *(int *)((int)pvVar2 + 0x114) = param_1;
  iVar3 = FUN_005ba5b0();
  return iVar3;
}


// ==== FUN_005a2b80 @ 0x005a2b80 ====

undefined4 FUN_005a2b80(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[0x45] < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c0fe0,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = param_2 + 0x45;
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return param_2[0x45];
    }
    (**(code **)*param_2)(0);
    param_2[0x43] = *(undefined4 *)(in_ECX + 0x23014);
    *(int *)(in_ECX + 0x2300c) = *(int *)(in_ECX + 0x2300c) + -1;
    *(undefined4 **)(in_ECX + 0x23014) = param_2;
  }
  return 0;
}


// ==== FUN_005a2c10 @ 0x005a2c10 ====

void FUN_005a2c10(byte param_1)

{
  void *in_ECX;
  
  FUN_005a2c30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a2c30 @ 0x005a2c30 ====

void FUN_005a2c30(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009c0fb0;
  if (in_ECX[0x8c03] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0e70,
                         s_d__usa_24_0_1_2__develop_module__009c0e10,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x47;
  iVar3 = 0x200;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0ee8,
                           s_d__usa_24_0_1_2__develop_module__009c0e88,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x46;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x8c04];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009c0fa8;
    *in_ECX = &PTR_FUN_009c0f90;
    return;
  }
  if (*(int *)((int)_Memory + 0x114) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c0f60,
                         s_d__usa_24_0_1_2__develop_module__009c0f00,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a2d20 @ 0x005a2d20 ====

void FUN_005a2d20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c0fc8;
  DAT_00b5afc4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c0f78;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a2d70 @ 0x005a2d70 ====

void FUN_005a2d70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c11cc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a2d90 @ 0x005a2d90 ====

void FUN_005a2d90(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005a2db0 @ 0x005a2db0 ====

void FUN_005a2db0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  return;
}


// ==== FUN_005a2dc0 @ 0x005a2dc0 ====

void FUN_005a2dc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c11fc;
  DAT_00b5b000 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c11cc;
  return;
}


// ==== FUN_005a2df0 @ 0x005a2df0 ====

void FUN_005a2df0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *in_ECX = &PTR_FUN_009c11fc;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5b000 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5b000 = in_ECX;
  }
  pvVar2 = operator_new(0x13018);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    return;
  }
  uVar3 = FUN_005a2ea0();
  *puVar1 = uVar3;
  return;
}


// ==== FUN_005a2e40 @ 0x005a2e40 ====

void FUN_005a2e40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c11dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a2e60 @ 0x005a2e60 ====

void FUN_005a2e60(byte param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_009c11f4;
  iVar1 = 0x400;
  do {
    FUN_005bae40();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a2ea0 @ 0x005a2ea0 ====

void FUN_005a2ea0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009c120c;
  in_ECX[1] = &PTR_FUN_009c11f4;
  iVar2 = 0x400;
  do {
    FUN_005bafe0();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  in_ECX[0x4c02] = 0;
  in_ECX[0x4c02] = in_ECX[0x4c02] + 0x400;
  in_ECX[0x4c05] = in_ECX + 2;
  in_ECX[0x4c03] = 0;
  in_ECX[0x4c04] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[0x12] = puVar1 + 0x15;
    puVar1[0x13] = 0;
    puVar1[0x14] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x13;
  } while (iVar2 != 0);
  in_ECX[0x4bff] = 0;
  in_ECX[0x4c00] = 0;
  in_ECX[0x4c01] = 0;
  return;
}


// ==== FUN_005a2f30 @ 0x005a2f30 ====

undefined4 FUN_005a2f30(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1300c);
}


// ==== FUN_005a2f40 @ 0x005a2f40 ====

void * FUN_005a2f40(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x48) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c1220,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x48) = *(int *)((int)param_2 + 0x48) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x13014);
  *(int *)(in_ECX + 0x1300c) = *(int *)(in_ECX + 0x1300c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x4c);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_005bafe0();
    }
    *(undefined4 *)((int)pvVar2 + 0x44) = *(undefined4 *)(in_ECX + 0x13010);
    *(void **)(in_ECX + 0x13010) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x13014) = *(undefined4 *)((int)pvVar2 + 0x40);
  }
  *(int *)((int)pvVar2 + 0x48) = param_1;
  *(undefined4 *)((int)pvVar2 + 0x40) = 0;
  FUN_005bae80();
  return pvVar2;
}


// ==== FUN_005a3010 @ 0x005a3010 ====

undefined4 FUN_005a3010(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x48) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009c1220,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x48);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x48);
    }
    FUN_005bac80();
    *(undefined4 *)(param_2 + 0x40) = *(undefined4 *)(in_ECX + 0x13014);
    *(int *)(in_ECX + 0x1300c) = *(int *)(in_ECX + 0x1300c) + -1;
    *(int *)(in_ECX + 0x13014) = param_2;
  }
  return 0;
}


// ==== FUN_005a30a0 @ 0x005a30a0 ====

void FUN_005a30a0(byte param_1)

{
  void *in_ECX;
  
  FUN_005a30c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a30c0 @ 0x005a30c0 ====

void FUN_005a30c0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_100 [256];
  
  *in_ECX = &PTR_FUN_009c120c;
  if (in_ECX[0x4c03] != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c10b4,
                         s_d__usa_24_0_1_2__develop_module__009c1048,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x14;
  iVar3 = 0x400;
  do {
    if (*piVar2 != 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c1134,
                           s_d__usa_24_0_1_2__develop_module__009c10c8,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x13;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x4c04];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009c11f4;
    iVar3 = 0x400;
    do {
      FUN_005bae40();
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    *in_ECX = &PTR_FUN_009c11dc;
    return;
  }
  if (*(int *)((int)_Memory + 0x48) != 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c11b4,
                         s_d__usa_24_0_1_2__develop_module__009c1148,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_005bae40();
  _free(_Memory);
  return;
}


// ==== FUN_005a31e0 @ 0x005a31e0 ====

void FUN_005a31e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c11fc;
  DAT_00b5b000 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c11cc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a3230 @ 0x005a3230 ====

void FUN_005a3230(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1290;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a3250 @ 0x005a3250 ====

void FUN_005a3250(void)

{
  return;
}


// ==== FUN_005a32a0 @ 0x005a32a0 ====

int * FUN_005a32a0(int param_1,undefined4 param_2)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  int *extraout_EAX;
  int in_ECX;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [2];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  int *piStack_c;
  
  iVar1 = param_1;
  FUN_0069a470(&param_1,param_1);
  if (param_1 != *(int *)(in_ECX + 8)) {
    return *(int **)(param_1 + 0x28);
  }
  pvVar2 = operator_new(0x74);
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_005bbfe0();
  }
  (**(code **)(*piVar3 + 4))(iVar1,param_2);
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401660(iVar1,0,0xffffffff);
  piStack_c = piVar3;
  FUN_005a3800(auStack_28 + -8,auStack_28);
  if (uStack_10 < 0x10) {
    return piVar3;
  }
  _free(pvStack_24);
  return extraout_EAX;
}


// ==== FUN_005a3350 @ 0x005a3350 ====

void FUN_005a3350(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_009c12a0;
  local_4 = in_ECX;
  if (in_ECX[3] != 0) {
    local_4 = (undefined4 *)((uint)in_ECX & 0xffffff00);
    FUN_0082c4f0(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2],local_4);
    FUN_005a35c0(*(undefined4 *)(in_ECX[2] + 4));
    *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
    in_ECX[3] = 0;
    *(undefined4 *)in_ECX[2] = in_ECX[2];
    *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  }
  DAT_00b5affc = 0;
  FUN_005a3970(&local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_005a33e0 @ 0x005a33e0 ====

void FUN_005a33e0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c12a0;
  iVar1 = FUN_005a3490();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5affc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5affc = in_ECX;
  return;
}


// ==== FUN_005a3430 @ 0x005a3430 ====

void FUN_005a3430(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x2d) == '\0') {
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


// ==== FUN_005a3490 @ 0x005a3490 ====

void FUN_005a3490(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009826b0;
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


// ==== Catch@005a351a @ 0x005a351a ====

void Catch_005a351a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005a3530 @ 0x005a3530 ====

void * FUN_005a3530(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009826c0;
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


// ==== Catch@005a35a5 @ 0x005a35a5 ====

void Catch_005a35a5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005a35c0 @ 0x005a35c0 ====

void FUN_005a35c0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_005a35c0(*(undefined4 *)((int)param_1 + 8));
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


// ==== FUN_005a3620 @ 0x005a3620 ====

void FUN_005a3620(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_005a3530(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_005a3725:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_005a3725;
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


// ==== FUN_005a3800 @ 0x005a3800 ====

/* WARNING: Removing unreachable block (ram,0x005a385f) */

void FUN_005a3800(undefined4 *param_1,undefined4 *param_2)

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
LAB_005a3890:
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
        if (uVar5 == 0) goto LAB_005a3890;
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
      puVar6 = (undefined4 *)FUN_005a3620(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_005a3620(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_005a3970 @ 0x005a3970 ====

void FUN_005a3970(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_005a35c0(piVar6[1]);
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


// ==== FUN_005a3a30 @ 0x005a3a30 ====

void FUN_005a3a30(byte param_1)

{
  void *in_ECX;
  
  FUN_005a3350();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a3a50 @ 0x005a3a50 ====

void FUN_005a3a50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c12c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a3a70 @ 0x005a3a70 ====

void FUN_005a3a70(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009826d0;
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


// ==== Catch@005a3afa @ 0x005a3afa ====

void Catch_005a3afa(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005a3b10 @ 0x005a3b10 ====

void FUN_005a3b10(int *param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = param_1;
  if (param_1 != (int *)0x0) {
    iVar2 = (**(code **)(*param_1 + 4))();
    FUN_0069a470(&param_1,iVar2 + 0x10);
    if (param_1 != *(int **)(in_ECX + 8)) {
      (**(code **)(*piVar1 + 0x10))();
    }
  }
  return;
}


// ==== FUN_005a3b50 @ 0x005a3b50 ====

int * FUN_005a3b50(undefined4 param_1)

{
  void *pvVar1;
  int *piVar2;
  int *extraout_EAX;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_28 = 0;
  local_2c = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_24 = 0;
  local_20 = 0;
  FUN_00401660(param_1,0,0xffffffff);
  pvVar1 = operator_new(0x3c);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_005bd190();
  }
  FUN_005bd1f0(&local_2c);
  (**(code **)(*piVar2 + 0xc))();
  if (local_4 < 0x10) {
    return piVar2;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_005a3c10 @ 0x005a3c10 ====

void FUN_005a3c10(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  int iVar8;
  int *piVar9;
  void *pvVar10;
  undefined4 uVar11;
  uint uVar12;
  float10 fVar13;
  char *pcStack_270;
  undefined1 auStack_260 [4];
  void *pvStack_25c;
  undefined4 uStack_24c;
  uint uStack_248;
  int iStack_244;
  int iStack_240;
  int aiStack_23c [2];
  undefined1 auStack_234 [4];
  void *pvStack_230;
  undefined4 uStack_220;
  uint uStack_21c;
  undefined4 uStack_218;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  pcStack_270 = local_100;
  local_208[0] = '\0';
  FUN_0044a580();
  uVar4 = 0;
  do {
    local_208[uVar4] = local_100[uVar4];
    if (local_100[uVar4] == '\0') goto LAB_005a3c5e;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  local_208[0] = '\0';
LAB_005a3c5e:
  local_108 = param_1;
  pcStack_270 = local_208;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar5 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  uVar12 = 1;
  uVar4 = (**(code **)(*piVar5 + 8))();
  if (uVar4 < 2) {
LAB_005a3ec3:
    (**(code **)(*DAT_00b5aa34 + 0xc))(piVar5);
    return;
  }
  do {
    pcVar6 = (char *)(**(code **)(*piVar5 + 0x10))(uVar12,0);
    FUN_0044a580(local_208 + 0xfc,&DAT_009c12bc,&DAT_009c12ba);
    uVar4 = 0;
    iVar2 = 0xfc - (int)pcVar6;
    while (*pcVar6 == pcVar6[(int)(local_208 + iVar2)]) {
      if (*pcVar6 == '\0') goto LAB_005a3eaf;
      uVar4 = uVar4 + 1;
      pcVar6 = pcVar6 + 1;
      if (0xff < uVar4) goto LAB_005a3eaf;
    }
    uStack_248 = 0xf;
    uStack_24c = 0;
    pvStack_25c = (void *)((uint)pvStack_25c & 0xffffff00);
    pcVar7 = (char *)(**(code **)(*piVar5 + 0x10))(uVar12,0);
    pcVar6 = pcVar7;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(pcVar7,(int)pcVar6 - (int)(pcVar7 + 1));
    iVar3 = iStack_244;
    iVar2 = *(int *)(iStack_244 + 8);
    aiStack_23c[0] = FUN_004bb4d0(auStack_260);
    if (aiStack_23c[0] == *(int *)(iVar3 + 8)) {
LAB_005a3d92:
      iStack_240 = *(int *)(iVar3 + 8);
      piVar9 = &iStack_240;
    }
    else {
      if (*(uint *)(aiStack_23c[0] + 0x24) < 0x10) {
        iVar8 = aiStack_23c[0] + 0x10;
      }
      else {
        iVar8 = *(int *)(aiStack_23c[0] + 0x10);
      }
      iVar8 = FUN_00403620(0,uStack_24c,iVar8,*(undefined4 *)(aiStack_23c[0] + 0x20));
      if (iVar8 < 0) goto LAB_005a3d92;
      piVar9 = aiStack_23c;
    }
    if (*piVar9 == iVar2) {
      fVar13 = (float10)FUN_00477510(uVar12,1);
      pcStack_270 = (char *)(float)fVar13;
      FUN_00477510(uVar12,2);
      FUN_00477510(uVar12,3);
      FUN_00477510(uVar12,4);
      pvVar10 = operator_new(0x3c);
      if (pvVar10 == (void *)0x0) {
        uVar11 = 0;
      }
      else {
        uVar11 = FUN_005bd190();
      }
      FUN_005bd1f0(&pcStack_270);
      uStack_21c = 0xf;
      uStack_220 = 0;
      pvStack_230 = (void *)((uint)pvStack_230 & 0xffffff00);
      FUN_00401660(auStack_260,0,0xffffffff);
      uStack_218 = uVar11;
      FUN_005a4620(aiStack_23c,auStack_234);
      if (0xf < uStack_21c) {
        _free(pvStack_230);
        return;
      }
      uStack_21c = 0xf;
      uStack_220 = 0;
      pvStack_230 = (void *)((uint)pvStack_230 & 0xffffff00);
      if (0xf < uStack_248) {
        _free(pvStack_25c);
        return;
      }
    }
    else if (0xf < uStack_248) {
      _free(pvStack_25c);
      return;
    }
    uStack_248 = 0xf;
    uStack_24c = 0;
    pvStack_25c = (void *)((uint)pvStack_25c & 0xffffff00);
LAB_005a3eaf:
    uVar12 = uVar12 + 1;
    uVar4 = (**(code **)(*piVar5 + 8))();
    if (uVar4 <= uVar12) goto LAB_005a3ec3;
  } while( true );
}


// ==== FUN_005a3ee0 @ 0x005a3ee0 ====

int * FUN_005a3ee0(int param_1)

{
  int iVar1;
  int *piVar2;
  int *extraout_EAX;
  int in_ECX;
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  int *local_4;
  
  iVar1 = param_1;
  FUN_0069a470(&param_1,param_1);
  if (param_1 != *(int *)(in_ECX + 8)) {
    piVar2 = *(int **)(param_1 + 0x28);
    (**(code **)(*piVar2 + 0xc))();
    return piVar2;
  }
  piVar2 = (int *)FUN_005a3b50(iVar1);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(iVar1,0,0xffffffff);
  local_4 = piVar2;
  FUN_005a4620(local_28,local_20);
  if (local_8 < 0x10) {
    return piVar2;
  }
  _free(local_1c);
  return extraout_EAX;
}


// ==== FUN_005a3f90 @ 0x005a3f90 ====

void FUN_005a3f90(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_009c12d8;
  local_4 = in_ECX;
  if (in_ECX[3] != 0) {
    local_4 = (undefined4 *)((uint)in_ECX & 0xffffff00);
    FUN_0082c4f0(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2],local_4);
    FUN_005a43e0(*(undefined4 *)(in_ECX[2] + 4));
    *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
    in_ECX[3] = 0;
    *(undefined4 *)in_ECX[2] = in_ECX[2];
    *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  }
  DAT_00b5ae50 = 0;
  FUN_005a4790(&local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_005a4020 @ 0x005a4020 ====

void FUN_005a4020(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c12d8;
  iVar1 = FUN_005a3a70();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae50 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae50 = in_ECX;
  return;
}


// ==== FUN_005a4070 @ 0x005a4070 ====

void * FUN_005a4070(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009826e0;
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


// ==== Catch@005a40e5 @ 0x005a40e5 ====

void Catch_005a40e5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005a4100 @ 0x005a4100 ====

/* WARNING: Removing unreachable block (ram,0x005a4219) */
/* WARNING: Removing unreachable block (ram,0x005a422a) */
/* WARNING: Removing unreachable block (ram,0x005a4233) */
/* WARNING: Removing unreachable block (ram,0x005a4236) */
/* WARNING: Removing unreachable block (ram,0x005a4226) */
/* WARNING: Removing unreachable block (ram,0x005a4244) */
/* WARNING: Removing unreachable block (ram,0x005a4251) */
/* WARNING: Removing unreachable block (ram,0x005a425c) */
/* WARNING: Removing unreachable block (ram,0x005a4258) */
/* WARNING: Removing unreachable block (ram,0x005a424c) */
/* WARNING: Removing unreachable block (ram,0x005a425f) */

void FUN_005a4100(undefined4 param_1,int *param_2)

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
            goto LAB_005a4334;
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
LAB_005a4334:
            *(undefined1 *)(piVar5 + 0xb) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xb) = 1;
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


// ==== FUN_005a43e0 @ 0x005a43e0 ====

void FUN_005a43e0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_005a43e0(*(undefined4 *)((int)param_1 + 8));
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


// ==== FUN_005a4440 @ 0x005a4440 ====

void FUN_005a4440(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_005a4070(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_005a4545:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_005a4545;
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


// ==== FUN_005a4620 @ 0x005a4620 ====

/* WARNING: Removing unreachable block (ram,0x005a467f) */

void FUN_005a4620(undefined4 *param_1,undefined4 *param_2)

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
LAB_005a46b0:
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
        if (uVar5 == 0) goto LAB_005a46b0;
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
      puVar6 = (undefined4 *)FUN_005a4440(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_005a4440(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_005a4790 @ 0x005a4790 ====

void FUN_005a4790(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_005a43e0(piVar6[1]);
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


// ==== FUN_005a4850 @ 0x005a4850 ====

void FUN_005a4850(byte param_1)

{
  void *in_ECX;
  
  FUN_005a3f90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a4870 @ 0x005a4870 ====

void FUN_005a4870(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c12ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a4890 @ 0x005a4890 ====

undefined4 FUN_005a4890(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_005bd7a0();
  return uVar2;
}


// ==== FUN_005a48b0 @ 0x005a48b0 ====

void FUN_005a48b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c12fc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aff4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aff4 = in_ECX;
  return;
}


// ==== FUN_005a48e0 @ 0x005a48e0 ====

void FUN_005a48e0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005a48f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)();
  return;
}


// ==== FUN_005a4920 @ 0x005a4920 ====

void FUN_005a4920(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5aff4 = 0;
  *in_ECX = &PTR_FUN_009c12ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a4950 @ 0x005a4950 ====

void FUN_005a4950(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1314;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a4970 @ 0x005a4970 ====

void FUN_005a4970(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005a4975. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x28) + 4))();
  return;
}


// ==== FUN_005a4980 @ 0x005a4980 ====

void FUN_005a4980(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005a4985. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x28) + 8))();
  return;
}


// ==== FUN_005a4990 @ 0x005a4990 ====

void FUN_005a4990(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  for (iVar1 = 9; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_ECX = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_005a49b0 @ 0x005a49b0 ====

int FUN_005a49b0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_005a49c0 @ 0x005a49c0 ====

void FUN_005a49c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005a49c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x28) + 0xc))();
  return;
}


// ==== FUN_005a49d0 @ 0x005a49d0 ====

void FUN_005a49d0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_004d8980(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0x30)) {
    *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(local_4 + 0x10);
  }
  return;
}


// ==== FUN_005a4a00 @ 0x005a4a00 ====

void FUN_005a4a00(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_009c1334;
  DAT_00b5add8 = 0;
  local_4 = in_ECX;
  if (in_ECX[0xd] != 0) {
    local_4 = (undefined4 *)((uint)in_ECX & 0xffffff00);
    FUN_00409660(*(undefined4 *)in_ECX[0xc],(undefined4 *)in_ECX[0xc],local_4);
    FUN_005a4d30(*(undefined4 *)(in_ECX[0xc] + 4));
    *(undefined4 *)(in_ECX[0xc] + 4) = in_ECX[0xc];
    in_ECX[0xd] = 0;
    *(undefined4 *)in_ECX[0xc] = in_ECX[0xc];
    *(undefined4 *)(in_ECX[0xc] + 8) = in_ECX[0xc];
  }
  FUN_005a5010(&local_4,*(undefined4 *)in_ECX[0xc],(undefined4 *)in_ECX[0xc]);
  _free((void *)in_ECX[0xc]);
  return;
}


// ==== FUN_005a4a90 @ 0x005a4a90 ====

void FUN_005a4a90(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  undefined4 *in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  *in_ECX = &PTR_FUN_009c1334;
  iVar4 = FUN_005a4c90();
  in_ECX[0xc] = iVar4;
  *(undefined1 *)(iVar4 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0xc] + 4) = in_ECX[0xc];
  *(undefined4 *)in_ECX[0xc] = in_ECX[0xc];
  *(undefined4 *)(in_ECX[0xc] + 8) = in_ECX[0xc];
  in_ECX[0xd] = 0;
  uVar2 = DAT_009c1350;
  uVar1 = DAT_0099d080;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5add8 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5add8 = in_ECX;
  }
  in_ECX[4] = DAT_009c1354;
  uVar3 = DAT_009b2dbc;
  in_ECX[1] = uVar2;
  uVar2 = DAT_0099d0b4;
  in_ECX[5] = uVar3;
  uVar3 = DAT_009a09bc;
  in_ECX[2] = uVar2;
  in_ECX[3] = uVar1;
  in_ECX[6] = uVar2;
  in_ECX[7] = uVar3;
  in_ECX[8] = uVar2;
  in_ECX[9] = uVar1;
  pvVar5 = operator_new(4);
  if (pvVar5 == (void *)0x0) {
    local_c = 0;
  }
  else {
    local_c = FUN_005bde90();
  }
  local_10 = 2;
  FUN_005a4f50(local_8,&local_10);
  pvVar5 = operator_new(8);
  if (pvVar5 == (void *)0x0) {
    local_c = 0;
  }
  else {
    local_c = FUN_005bdda0();
  }
  local_10 = 0;
  FUN_005a4f50(local_8,&local_10);
  pvVar5 = operator_new(4);
  if (pvVar5 == (void *)0x0) {
    local_c = 0;
  }
  else {
    local_c = FUN_005bdcf0();
  }
  local_10 = 1;
  FUN_005a4f50(local_8,&local_10);
  in_ECX[10] = DAT_00b5b008;
  return;
}


// ==== FUN_005a4c00 @ 0x005a4c00 ====

void * FUN_005a4c00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009826f0;
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


// ==== Catch@005a4c75 @ 0x005a4c75 ====

void Catch_005a4c75(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005a4c90 @ 0x005a4c90 ====

void FUN_005a4c90(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982700;
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


// ==== Catch@005a4d1a @ 0x005a4d1a ====

void Catch_005a4d1a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005a4d30 @ 0x005a4d30 ====

void FUN_005a4d30(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_005a4d30(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_005a4d70 @ 0x005a4d70 ====

void FUN_005a4d70(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_005a4c00(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_005a4e75:
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
      if ((char)piVar6[5] == '\0') goto LAB_005a4e75;
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


// ==== FUN_005a4f50 @ 0x005a4f50 ====

void FUN_005a4f50(undefined4 *param_1,int *param_2)

{
  undefined4 uVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  piVar3 = param_2;
  puVar5 = *(undefined4 **)(in_ECX + 4);
  bVar2 = true;
  if (*(char *)((int)puVar5[1] + 0x15) == '\0') {
    puVar4 = (undefined4 *)puVar5[1];
    do {
      puVar5 = puVar4;
      bVar2 = *param_2 < (int)puVar5[3];
      if (bVar2) {
        puVar4 = (undefined4 *)*puVar5;
      }
      else {
        puVar4 = (undefined4 *)puVar5[2];
      }
    } while (*(char *)((int)puVar4 + 0x15) == '\0');
  }
  param_2 = puVar5;
  if (bVar2) {
    if (puVar5 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar5 = (undefined4 *)FUN_005a4d70(&param_2,1,puVar5,piVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *piVar3) {
    puVar5 = (undefined4 *)FUN_005a4d70(&param_2,bVar2,puVar5,piVar3);
    *param_1 = *puVar5;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_005a5010 @ 0x005a5010 ====

void FUN_005a5010(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_005a4d30(piVar6[1]);
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


// ==== FUN_005a50d0 @ 0x005a50d0 ====

void FUN_005a50d0(byte param_1)

{
  void *in_ECX;
  
  FUN_005a4a00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a50f0 @ 0x005a50f0 ====

void FUN_005a50f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c13e8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a5110 @ 0x005a5110 ====

undefined1 FUN_005a5110(void)

{
  return 0;
}


// ==== FUN_005a5160 @ 0x005a5160 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a5160(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1418;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aea4 = (undefined4 *)0x0;
    _DAT_00000000 = DAT_0099e170;
    return;
  }
  DAT_00b5aea4 = in_ECX;
  in_ECX[1] = DAT_0099e170;
  return;
}


// ==== FUN_005a51a0 @ 0x005a51a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a51a0(int *param_1,int *param_2)

{
  float fVar1;
  float *pfVar2;
  int *in_ECX;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pfVar2 = (float *)(**(code **)(*DAT_00b5a988 + 0x14))();
  FUN_0040d600(&fStack_18,pfVar2[2]);
  FUN_0040d600(&fStack_10,pfVar2[2] + _DAT_00af47dc);
  fVar1 = *pfVar2;
  fStack_8 = fStack_10 * (float)(*param_2 - *param_1) * fVar1 * DAT_0099d0ec -
             fStack_18 * (float)(param_2[1] - param_1[1]) * fVar1 * DAT_0099d0ec;
  fStack_4 = fStack_c * (float)(*param_2 - *param_1) * fVar1 * DAT_0099d0ec -
             fStack_14 * (float)(param_2[1] - param_1[1]) * fVar1 * DAT_0099d0ec;
  (**(code **)(*in_ECX + 8))(&fStack_8);
  return;
}


// ==== FUN_005a5280 @ 0x005a5280 ====

void FUN_005a5280(float *param_1)

{
  float *pfVar1;
  float10 fVar2;
  float *pfVar3;
  float fStack_14;
  undefined1 *puStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pfVar3 = &fStack_14;
  pfVar1 = (float *)(**(code **)(*DAT_00b5ad14 + 0x14))();
  fStack_c = *pfVar1;
  fStack_8 = pfVar1[1];
  fStack_4 = pfVar1[2];
  fStack_14 = *param_1 + fStack_c;
  puStack_10 = (undefined1 *)(param_1[1] + fStack_4);
  fVar2 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(&fStack_14);
  fStack_c = (float)fVar2;
  fStack_8 = fStack_14;
  puStack_10 = (undefined1 *)pfVar3;
  (**(code **)(*DAT_00b5ad14 + 0x10))(&puStack_10);
  return;
}


// ==== FUN_005a5310 @ 0x005a5310 ====

void FUN_005a5310(int *param_1,int *param_2)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x10))
            ((float)in_ECX[1] * (float)(*param_2 - *param_1),
             (float)in_ECX[1] * (float)(param_2[1] - param_1[1]));
  return;
}


// ==== FUN_005a5360 @ 0x005a5360 ====

void FUN_005a5360(float param_1,float param_2)

{
  undefined4 *puVar1;
  undefined4 uStack_14;
  float fStack_10;
  float fStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a988 + 0xc))();
  uStack_14 = *puVar1;
  uStack_8 = puVar1[3];
  fStack_c = (float)puVar1[2] + param_1;
  uStack_4 = puVar1[4];
  fStack_10 = (float)puVar1[1] + param_2;
  (**(code **)(*DAT_00b5a988 + 0x10))(&uStack_14);
  return;
}


// ==== FUN_005a53d0 @ 0x005a53d0 ====

void FUN_005a53d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = (**(code **)(*DAT_00b5a988 + 0xc))();
  uStack_8 = *(undefined4 *)(iVar1 + 0xc);
  uStack_4 = *(undefined4 *)(iVar1 + 0x10);
  uStack_c = param_1;
  uStack_10 = param_2;
  uStack_14 = param_3;
  (**(code **)(*DAT_00b5a988 + 0x10))(&uStack_14);
  return;
}


// ==== FUN_005a5440 @ 0x005a5440 ====

void FUN_005a5440(undefined4 param_1)

{
  float *pfVar1;
  float *pfVar2;
  float10 fVar3;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pfVar1 = (float *)(**(code **)(*DAT_00b5a988 + 0xc))();
  pfVar2 = (float *)(**(code **)(*DAT_00b5ae24 + 8))();
  fVar3 = (float10)FUN_0040d530(0x40000000,param_1);
  fStack_10 = pfVar1[1];
  fStack_14 = (float)(fVar3 * (float10)*pfVar1);
  fStack_c = pfVar1[2];
  fStack_8 = pfVar1[3];
  fStack_4 = pfVar1[4];
  if (pfVar2[1] < fStack_14) {
    fStack_14 = pfVar2[1];
  }
  if (fStack_14 < *pfVar2) {
    fStack_14 = *pfVar2;
  }
  (**(code **)(*DAT_00b5a988 + 0x10))(&fStack_14);
  return;
}


// ==== FUN_005a5500 @ 0x005a5500 ====

void FUN_005a5500(undefined4 param_1)

{
  char cVar1;
  byte bVar2;
  undefined4 *puVar3;
  float *pfVar4;
  void *pvVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  uint uVar11;
  int unaff_ESI;
  byte ****ppppbVar12;
  byte *pbVar13;
  bool bVar14;
  bool bVar15;
  float10 fVar16;
  byte ****ppppbStack_260;
  byte ***pppbStack_25c;
  uint uStack_250;
  uint uStack_24c;
  float fStack_248;
  float fStack_244;
  float fStack_240;
  float fStack_23c;
  float fStack_238;
  float fStack_234;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  float fStack_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  char acStack_208 [256];
  byte ***pppbStack_108;
  undefined1 uStack_104;
  undefined1 uStack_103;
  undefined1 uStack_102;
  char acStack_100 [256];
  
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a988 + 0xc))();
  uStack_230 = *puVar3;
  uStack_22c = puVar3[1];
  uStack_228 = puVar3[2];
  uStack_224 = puVar3[3];
  uStack_220 = puVar3[4];
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5ae24 + 8))();
  uStack_21c = *puVar3;
  fStack_218 = (float)puVar3[1];
  uStack_214 = puVar3[2];
  uStack_210 = puVar3[3];
  uStack_20c = puVar3[4];
  pfVar4 = (float *)(**(code **)(*DAT_00b5ad14 + 0x14))();
  fStack_23c = *pfVar4;
  fStack_238 = pfVar4[1];
  fStack_234 = pfVar4[2];
  pvVar5 = operator_new(0x10);
  uVar11 = 0;
  if (pvVar5 == (void *)0x0) {
    pppbStack_25c = (byte ***)0x0;
  }
  else {
    pppbStack_25c = (byte ***)FUN_0081d550(param_1);
  }
  ppppbVar12 = (byte ****)pppbStack_25c;
  acStack_208[0] = '\0';
  FUN_0044a580(acStack_100,&DAT_009c13dc,s_ImportCamera_009c139c);
  uVar6 = 0;
  do {
    acStack_208[uVar6] = acStack_100[uVar6];
    if (acStack_100[uVar6] == '\0') goto LAB_005a55ee;
    uVar6 = uVar6 + 1;
  } while (uVar6 < 0x100);
  acStack_208[0] = '\0';
LAB_005a55ee:
  uStack_104 = 10;
  uStack_103 = 0x2c;
  uStack_102 = 1;
  pppbStack_108 = (byte ***)ppppbVar12;
  piVar7 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(acStack_208);
  iVar8 = (**(code **)(*piVar7 + 8))();
  if (iVar8 != 0) {
    do {
      pcVar9 = (char *)(**(code **)(*piVar7 + 0x10))(uVar11,0);
      uStack_24c = 0xf;
      uStack_250 = 0;
      ppppbStack_260 = (byte ****)((uint)ppppbStack_260 & 0xffffff00);
      pcVar10 = pcVar9;
      do {
        cVar1 = *pcVar10;
        pcVar10 = pcVar10 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(pcVar9,(int)pcVar10 - (int)(pcVar9 + 1));
      if (uStack_250 == 0) {
LAB_005a56d5:
        iVar8 = FUN_00403620(0,uStack_250,s_horizon_009c13b8,7);
        if (iVar8 == 0) {
          fVar16 = (float10)FUN_00477510(uVar11,1);
          fStack_234 = (float)fVar16;
        }
        else {
          iVar8 = FUN_00403620(0,uStack_250,s_vertical_009c13c0,8);
          if (iVar8 == 0) {
            fVar16 = (float10)FUN_00477510(uVar11,1);
            fStack_238 = (float)fVar16;
          }
          else {
            iVar8 = FUN_00403620(0,uStack_250,s_height_009c13cc,6);
            if (iVar8 == 0) {
              fVar16 = (float10)FUN_00477510(uVar11,1);
              fStack_218 = (float)fVar16;
            }
            else {
              iVar8 = FUN_00403620(0,uStack_250,s_target_009c13d4,6);
              if (iVar8 == 0) {
                fVar16 = (float10)FUN_00477510(uVar11,1);
                fStack_248 = (float)fVar16;
                fVar16 = (float10)FUN_00477510(uVar11,2);
                fStack_244 = (float)fVar16;
                fVar16 = (float10)FUN_00477510(uVar11,3);
                fStack_240 = (float)fVar16;
              }
            }
          }
        }
      }
      else {
        uVar6 = uStack_250;
        if (7 < uStack_250) {
          uVar6 = 8;
        }
        ppppbVar12 = ppppbStack_260;
        if (uStack_24c < 0x10) {
          ppppbVar12 = (byte ****)&ppppbStack_260;
        }
        bVar14 = false;
        iVar8 = 0;
        bVar15 = true;
        pbVar13 = (byte *)s_distance_009c13ac;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar14 = *(byte *)ppppbVar12 < *pbVar13;
          bVar15 = *(byte *)ppppbVar12 == *pbVar13;
          ppppbVar12 = (byte ****)((int)ppppbVar12 + 1);
          pbVar13 = pbVar13 + 1;
        } while (bVar15);
        if (!bVar15) {
          iVar8 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
        }
        if (((iVar8 != 0) || (uStack_250 < 8)) || (uStack_250 != 8)) goto LAB_005a56d5;
        fVar16 = (float10)FUN_00477510(uVar11,1);
        fStack_23c = (float)fVar16;
      }
      if (0xf < uStack_24c) {
        _free(ppppbStack_260);
        return;
      }
      bVar2 = (char)((uint)unaff_ESI >> 0x18) + 1;
      uStack_24c = 0xf;
      uStack_250 = 0;
      ppppbStack_260 = (byte ****)((uint)ppppbStack_260 & 0xffffff00);
      unaff_ESI = (uint)bVar2 << 0x18;
      uVar11 = (uint)bVar2;
      uVar6 = (**(code **)(*piVar7 + 8))();
    } while (uVar11 < uVar6);
    ppppbVar12 = ppppbStack_260;
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar7);
  if (ppppbVar12 != (byte ****)0x0) {
    (*(code *)**ppppbVar12)(1);
  }
  (**(code **)(*DAT_00b5a988 + 0x10))(&fStack_238);
  (**(code **)(*DAT_00b5ae24 + 4))(&uStack_228);
  (**(code **)(*DAT_00b5ad14 + 0x10))(&uStack_24c);
  return;
}


// ==== FUN_005a5840 @ 0x005a5840 ====

void FUN_005a5840(void)

{
  undefined **appuStack_78 [4];
  undefined4 uStack_68;
  undefined4 uStack_64;
  void *pvStack_60;
  undefined1 auStack_5c [12];
  undefined4 uStack_50;
  uint uStack_4c;
  void *pvStack_44;
  uint uStack_30;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  uint uStack_c;
  
  (**(code **)(*DAT_00b5a988 + 0x14))();
  FUN_00404890();
  FUN_004045b0();
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  FUN_00405bd0();
  appuStack_78[0] = &PTR_FUN_0099d55c;
  uStack_68 = 0;
  uStack_64 = 0;
  pvStack_60 = (void *)0x0;
  FUN_00401740(s_distance__f_009c135c,0xb);
  FUN_00797530(auStack_24);
  FUN_00411630();
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  FUN_00401740(s_horizon__f_009c1368,10);
  FUN_00797530(auStack_24);
  FUN_00411630();
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  FUN_00401740(s_vertical__f_009c1374,0xb);
  FUN_00797530(auStack_24);
  FUN_00411630();
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  FUN_00401740(s_height__f_009c1380,9);
  FUN_00797530(auStack_24);
  FUN_00411630();
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  FUN_00401740(s_target__f__f__f_009c138c,0xf);
  FUN_00797530(auStack_24);
  FUN_00411630();
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  (**(code **)(*DAT_00b5a740 + 0xc))(auStack_5c,appuStack_78);
  FUN_004137c0();
  if (0xf < uStack_4c) {
    _free(pvStack_60);
    return;
  }
  uStack_4c = 0xf;
  uStack_50 = 0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  if (uStack_30 < 0x10) {
    return;
  }
  _free(pvStack_44);
  return;
}


// ==== FUN_005a5ac0 @ 0x005a5ac0 ====

void FUN_005a5ac0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_005a5ad0 @ 0x005a5ad0 ====

void FUN_005a5ad0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5aea4 = 0;
  *in_ECX = &PTR_FUN_009c13e8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a5b00 @ 0x005a5b00 ====

void FUN_005a5b00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1450;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a5b20 @ 0x005a5b20 ====

void FUN_005a5b20(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  *(undefined4 *)(in_ECX + 0x14) = param_1[4];
  return;
}


// ==== FUN_005a5b50 @ 0x005a5b50 ====

int FUN_005a5b50(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_005a5b60 @ 0x005a5b60 ====

void FUN_005a5b60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1464;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ae24 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ae24 = in_ECX;
  }
  in_ECX[1] = DAT_0099d080;
  in_ECX[2] = DAT_009c145c;
  in_ECX[3] = DAT_009a09b8;
  in_ECX[4] = DAT_00af489c * DAT_0099d0e4;
  in_ECX[5] = 0;
  return;
}


// ==== FUN_005a5bf0 @ 0x005a5bf0 ====

void FUN_005a5bf0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ae24 = 0;
  *in_ECX = &PTR_FUN_009c1450;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a5c20 @ 0x005a5c20 ====

void FUN_005a5c20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1474;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a5c40 @ 0x005a5c40 ====

void FUN_005a5c40(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_005a5c50 @ 0x005a5c50 ====

int FUN_005a5c50(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_005a5c60 @ 0x005a5c60 ====

void FUN_005a5c60(undefined4 *param_1)

{
  int in_ECX;
  float fVar1;
  
  *(undefined4 *)(in_ECX + 8) = *param_1;
  *(undefined4 *)(in_ECX + 0xc) = param_1[1];
  *(undefined4 *)(in_ECX + 0x10) = param_1[2];
  *(undefined4 *)(in_ECX + 0x14) = param_1[3];
  fVar1 = *(float *)(in_ECX + 0x10) - DAT_009bfa74;
  (**(code **)(*DAT_00b5afb4 + 0x14))(fVar1);
  FUN_00596540(fVar1);
  return;
}


// ==== FUN_005a5cb0 @ 0x005a5cb0 ====

float * FUN_005a5cb0(void)

{
  float *pfVar1;
  float *pfVar2;
  float *pfVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    return (float *)(in_ECX + 0x18);
  }
  pfVar3 = (float *)(**(code **)(*DAT_00b5a988 + 0x18))();
  pfVar1 = (float *)(in_ECX + 0x38);
  *pfVar1 = pfVar3[3] + *pfVar3;
  *(float *)(in_ECX + 0x3c) = pfVar3[7] + pfVar3[4];
  *(float *)(in_ECX + 0x40) = pfVar3[8] + pfVar3[0xb];
  *(float *)(in_ECX + 0x44) = pfVar3[0xf] + pfVar3[0xc];
  thunk_FUN_007a1034(pfVar1,pfVar1);
  pfVar1 = (float *)(in_ECX + 0x48);
  *pfVar1 = pfVar3[3] - *pfVar3;
  *(float *)(in_ECX + 0x4c) = pfVar3[7] - pfVar3[4];
  *(float *)(in_ECX + 0x50) = pfVar3[0xb] - pfVar3[8];
  *(float *)(in_ECX + 0x54) = pfVar3[0xf] - pfVar3[0xc];
  thunk_FUN_007a1034(pfVar1,pfVar1);
  pfVar1 = (float *)(in_ECX + 0x58);
  *pfVar1 = pfVar3[3] - pfVar3[1];
  *(float *)(in_ECX + 0x5c) = pfVar3[7] - pfVar3[5];
  *(float *)(in_ECX + 0x60) = pfVar3[0xb] - pfVar3[9];
  *(float *)(in_ECX + 100) = pfVar3[0xf] - pfVar3[0xd];
  thunk_FUN_007a1034(pfVar1,pfVar1);
  pfVar1 = (float *)(in_ECX + 0x68);
  *pfVar1 = pfVar3[3] + pfVar3[1];
  *(float *)(in_ECX + 0x6c) = pfVar3[7] + pfVar3[5];
  *(float *)(in_ECX + 0x70) = pfVar3[9] + pfVar3[0xb];
  *(float *)(in_ECX + 0x74) = pfVar3[0xf] + pfVar3[0xd];
  thunk_FUN_007a1034(pfVar1,pfVar1);
  pfVar1 = (float *)(in_ECX + 0x18);
  *pfVar1 = pfVar3[2];
  *(float *)(in_ECX + 0x1c) = pfVar3[6];
  *(float *)(in_ECX + 0x20) = pfVar3[10];
  *(float *)(in_ECX + 0x24) = pfVar3[0xe];
  thunk_FUN_007a1034(pfVar1,pfVar1);
  pfVar2 = (float *)(in_ECX + 0x28);
  *pfVar2 = pfVar3[3] - pfVar3[2];
  *(float *)(in_ECX + 0x2c) = pfVar3[7] - pfVar3[6];
  *(float *)(in_ECX + 0x30) = pfVar3[0xb] - pfVar3[10];
  *(float *)(in_ECX + 0x34) = pfVar3[0xf] - pfVar3[0xe];
  thunk_FUN_007a1034(pfVar2,pfVar2);
  return pfVar1;
}


// ==== FUN_005a5e50 @ 0x005a5e50 ====

void FUN_005a5e50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c148c;
  *(undefined1 *)(in_ECX + 1) = 1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5afd0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5afd0 = in_ECX;
  }
  in_ECX[2] = DAT_009bf3cc;
  in_ECX[3] = DAT_009b2dc0;
  in_ECX[4] = DAT_0099de80;
  return;
}


// ==== FUN_005a5ec0 @ 0x005a5ec0 ====

void FUN_005a5ec0(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5afd0 = 0;
  *in_ECX = &PTR_FUN_009c1474;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a5ef0 @ 0x005a5ef0 ====

void FUN_005a5ef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c14a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a5f10 @ 0x005a5f10 ====

void FUN_005a5f10(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_005a5f20 @ 0x005a5f20 ====

void FUN_005a5f20(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0xffffffff;
  return;
}


// ==== FUN_005a5f30 @ 0x005a5f30 ====

undefined4 FUN_005a5f30(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_005a5f40 @ 0x005a5f40 ====

void FUN_005a5f40(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = *param_1;
  *(undefined4 *)(in_ECX + 0xc) = param_1[1];
  *(undefined4 *)(in_ECX + 0x10) = param_1[2];
  return;
}


// ==== FUN_005a5f60 @ 0x005a5f60 ====

void FUN_005a5f60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c14c0;
  in_ECX[1] = 0xffffffff;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ad14 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad14 = in_ECX;
  return;
}


// ==== FUN_005a5fa0 @ 0x005a5fa0 ====

undefined4 * FUN_005a5fa0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 auStack_a [10];
  
  if (*(int *)(in_ECX + 4) != -1) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a728 + 0xc))(*(int *)(in_ECX + 4));
    if (piVar1 != (int *)0x0) {
      puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x10))(auStack_a + -6);
      *(undefined4 *)(in_ECX + 8) = *puVar2;
      *(undefined4 *)(in_ECX + 0xc) = puVar2[1];
      *(undefined4 *)(in_ECX + 0x10) = puVar2[2];
      return (undefined4 *)(in_ECX + 8);
    }
  }
  return (undefined4 *)(in_ECX + 8);
}


// ==== FUN_005a6010 @ 0x005a6010 ====

void FUN_005a6010(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad14 = 0;
  *in_ECX = &PTR_FUN_009c14a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a6040 @ 0x005a6040 ====

void FUN_005a6040(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1544;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a6060 @ 0x005a6060 ====

int FUN_005a6060(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_005a6070 @ 0x005a6070 ====

int FUN_005a6070(void)

{
  int in_ECX;
  
  return in_ECX + 0x30;
}


// ==== FUN_005a6080 @ 0x005a6080 ====

int FUN_005a6080(void)

{
  int in_ECX;
  
  return in_ECX + 0x88;
}


// ==== FUN_005a6090 @ 0x005a6090 ====

void FUN_005a6090(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xe4) = param_1;
  FUN_005ae6d0();
  return;
}


// ==== FUN_005a60b0 @ 0x005a60b0 ====

void FUN_005a60b0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xe5) = param_1;
  FUN_005ae6e0();
  return;
}


// ==== FUN_005a6120 @ 0x005a6120 ====

void FUN_005a6120(float *param_1)

{
  float *pfVar1;
  int in_ECX;
  float10 fVar2;
  float fVar3;
  
  pfVar1 = (float *)(**(code **)(*DAT_00b5ae24 + 8))();
  if (*param_1 < pfVar1[1] || *param_1 == pfVar1[1]) {
    fVar3 = *param_1;
  }
  else {
    fVar3 = pfVar1[1];
  }
  if (fVar3 < *pfVar1) {
    fVar3 = *pfVar1;
  }
  *(float *)(in_ECX + 8) = fVar3;
  if (param_1[1] < pfVar1[3] || param_1[1] == pfVar1[3]) {
    fVar3 = param_1[1];
  }
  else {
    fVar3 = pfVar1[3];
  }
  if (fVar3 < pfVar1[2]) {
    fVar3 = pfVar1[2];
  }
  *(float *)(in_ECX + 0xc) = fVar3;
  fVar2 = (float10)FUN_0040d0f0(param_1[2]);
  *(float *)(in_ECX + 0x10) = (float)fVar2;
  *(float *)(in_ECX + 0x14) = param_1[3];
  *(float *)(in_ECX + 0x18) = param_1[4];
  return;
}


// ==== FUN_005a61b0 @ 0x005a61b0 ====

undefined4 FUN_005a61b0(undefined4 param_1,int param_2)

{
  int iVar1;
  int *in_ECX;
  float fStack_8;
  float fStack_4;
  
  iVar1 = (**(code **)(*DAT_00b5a6e4 + 8))();
  fStack_4 = DAT_0099d080 -
             ((float)*(int *)(param_2 + 0x14) / (float)*(int *)(iVar1 + 0x54)) * DAT_0099d0f8;
  fStack_8 = ((float)*(int *)(param_2 + 0x10) / (float)*(int *)(iVar1 + 0x50)) * DAT_0099d0f8 -
             DAT_0099d080;
  (**(code **)(*in_ECX + 0x1c))(param_1,&fStack_8);
  return param_1;
}


// ==== FUN_005a6230 @ 0x005a6230 ====

undefined4 FUN_005a6230(float param_1,float *param_2)

{
  int iVar1;
  int *in_ECX;
  float fVar2;
  float fVar3;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  fVar2 = *(float *)(iVar1 + 0x34) - *param_2;
  fVar3 = *(float *)(iVar1 + 0x3c) - param_2[1];
  if (*(float *)(iVar1 + 0x14) - param_1 <= SQRT(fVar3 * fVar3 + fVar2 * fVar2)) {
    return 1;
  }
  return 0;
}


// ==== FUN_005a6290 @ 0x005a6290 ====

undefined4 FUN_005a6290(float param_1,float *param_2)

{
  int iVar1;
  int *in_ECX;
  float fVar2;
  float fVar3;
  
  iVar1 = (**(code **)(*in_ECX + 0x14))();
  fVar2 = *(float *)(iVar1 + 0x28) - *param_2;
  fVar3 = *(float *)(iVar1 + 0x30) - param_2[1];
  if (param_1 <= SQRT(fVar3 * fVar3 + fVar2 * fVar2)) {
    return 1;
  }
  return 0;
}


// ==== FUN_005a62f0 @ 0x005a62f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a62f0(int param_1)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  float *pfVar3;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float afStack_c [2];
  float fStack_4;
  
  iVar1 = (**(code **)(*DAT_00b5afb4 + 0x10))();
  if (*(char *)(iVar1 + 0xd8) != '\x02') {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    return;
  }
  *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + *(int *)(param_1 + 4);
  if (*(uint *)(in_ECX + 0x2c) < *(uint *)(in_ECX + 0x28)) {
    *(undefined4 *)(in_ECX + 0x28) = 0;
  }
  fStack_18 = *(float *)(in_ECX + 0x58) - *(float *)(in_ECX + 100);
  fStack_14 = *(float *)(in_ECX + 0x5c) - *(float *)(in_ECX + 0x68);
  pfVar3 = &fStack_18;
  fStack_10 = *(float *)(in_ECX + 0x60) - *(float *)(in_ECX + 0x6c);
  thunk_FUN_0079e1ba(afStack_c,pfVar3);
  fStack_4 = (afStack_c[0] + fStack_14) * 0.0 + fStack_10;
  if (fStack_4 <= 0.0) {
    fStack_4 = 0.0;
  }
  fStack_4 = (DAT_0099d080 - fStack_4) * *(float *)(in_ECX + 0x1c);
  fVar2 = (float10)FUN_0040d4c0(DAT_00af4ae0 * (float)pfVar3);
  *(float *)(in_ECX + 0x20) = (float)(fVar2 * (float10)fStack_4);
  return;
}


// ==== FUN_005a6400 @ 0x005a6400 ====

void FUN_005a6400(void)

{
  int *in_ECX;
  float *pfVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined1 *puStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  undefined1 auStack_70 [12];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [12];
  undefined1 auStack_40 [24];
  float *pfStack_28;
  undefined4 *puStack_4;
  
  uStack_98 = 0x5a640b;
  uStack_98 = (**(code **)(*in_ECX + 0x18))();
  uStack_9c = 0;
  puStack_a0 = auStack_40;
  thunk_FUN_0079f3a1();
  uStack_58 = *puStack_4;
  uStack_54 = puStack_4[1];
  uStack_50 = 0;
  uStack_64 = *puStack_4;
  uStack_60 = puStack_4[1];
  uStack_5c = DAT_0099d080;
  thunk_FUN_0079e5a0(&puStack_a0,&uStack_58,auStack_4c);
  pfVar1 = &fStack_88;
  thunk_FUN_0079e5a0();
  fStack_88 = fStack_94 - (float)pfVar1;
  fStack_84 = fStack_90 - (float)auStack_70;
  fStack_80 = fStack_8c - (float)&uStack_58;
  puVar2 = auStack_70;
  puVar3 = &uStack_58;
  thunk_FUN_0079e1ba(&puStack_a0,&fStack_88);
  *pfStack_28 = (float)auStack_70;
  pfStack_28[1] = (float)&uStack_58;
  pfStack_28[2] = (float)pfVar1;
  pfStack_28[3] = (float)puVar2;
  pfStack_28[4] = (float)puVar3;
  pfStack_28[5] = (float)puStack_a0;
  return;
}


// ==== FUN_005a6520 @ 0x005a6520 ====

undefined1 FUN_005a6520(int *param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  cVar2 = (**(code **)(*DAT_00b5aea4 + 4))(param_1);
  if (cVar2 == '\x01') {
    return 1;
  }
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 == 0x40001) {
    FUN_005a62f0(param_1);
  }
  puVar4 = *(undefined4 **)(in_ECX + 0xcc);
  puVar1 = *(undefined4 **)(in_ECX + 0xd0);
  while( true ) {
    if (puVar4 == puVar1) {
      return 0;
    }
    cVar2 = (**(code **)(*(int *)*puVar4 + 4))(param_1);
    if (cVar2 == '\x01') break;
    puVar4 = puVar4 + 1;
  }
  return 1;
}


// ==== FUN_005a6590 @ 0x005a6590 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a6590(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  int iVar4;
  float *pfVar5;
  int *piVar6;
  float *pfVar7;
  int *piVar8;
  float10 fVar9;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  float fStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined1 auStack_b8 [8];
  undefined1 auStack_b0 [4];
  float afStack_ac [2];
  undefined1 auStack_a4 [48];
  float fStack_74;
  int aiStack_54 [2];
  undefined1 auStack_4c [76];
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5ad14 + 0x14))();
  puVar2 = (undefined4 *)(**(code **)(*in_ECX + 0xc))();
  uStack_d8 = *puVar2;
  uStack_d4 = puVar2[1];
  uStack_d0 = puVar2[2];
  fStack_cc = (float)puVar2[3];
  uStack_c8 = puVar2[4];
  uStack_c4 = *puVar1;
  uStack_c0 = puVar1[1];
  uStack_bc = puVar1[2];
  iVar4 = *DAT_00b5add8;
  uVar3 = (**(code **)(*in_ECX + 0x14))(auStack_b8);
  (**(code **)(iVar4 + 8))(&uStack_d8,uVar3);
  FUN_005a6ae0(&uStack_c4,auStack_b0,auStack_a4);
  FUN_005a6a60(auStack_a4,auStack_4c);
  fVar9 = (float10)(**(code **)(*DAT_00b5add8 + 0xc))(auStack_a4,auStack_4c);
  afStack_ac[0] = (float)fVar9 - afStack_ac[0];
  if (afStack_ac[0] <= 0.0) {
    afStack_ac[0] = 0.0 - afStack_ac[0];
  }
  if (_DAT_009c1534 < afStack_ac[0]) {
    fStack_cc = (float)fVar9;
    FUN_005a6ae0(&fStack_cc,auStack_b8,afStack_ac);
  }
  puVar2 = (undefined4 *)in_ECX[0x34];
  for (puVar1 = (undefined4 *)in_ECX[0x33]; puVar1 != puVar2; puVar1 = puVar1 + 1) {
    (**(code **)(*(int *)*puVar1 + 8))(afStack_ac);
  }
  FUN_005a6a60(afStack_ac,aiStack_54);
  fStack_74 = (float)in_ECX[8] + fStack_74;
  pfVar5 = afStack_ac;
  pfVar7 = (float *)(in_ECX + 0xc);
  for (iVar4 = 0x16; iVar4 != 0; iVar4 = iVar4 + -1) {
    *pfVar7 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar7 = pfVar7 + 1;
  }
  piVar6 = aiStack_54;
  piVar8 = in_ECX + 0x22;
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar8 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar8 = piVar8 + 1;
  }
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5afd0 + 8))();
  uVar3 = (**(code **)(*DAT_00b5afd0 + 0xc))();
  FUN_005ae630(in_ECX + 0x16,in_ECX + 0x19,in_ECX + 0x1c,*puVar1,puVar1[1],puVar1[2],uVar3);
  *(int *)(in_ECX[0x36] + 0x50) = in_ECX[6];
  return;
}


// ==== FUN_005a6760 @ 0x005a6760 ====

void FUN_005a6760(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c158c;
  DAT_00b5a988 = 0;
  if (in_ECX[0x36] != 0) {
    (**(code **)(*DAT_00b5afac + 8))(in_ECX[1],1);
    if ((undefined4 *)in_ECX[0x36] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[0x36])(1);
    }
    in_ECX[0x36] = 0;
  }
  if (in_ECX[1] != -1) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    (**(code **)(*piVar1 + 8))(s___Camera_CameraImpl_cpp_009c14f4,0x39,0,in_ECX[1]);
    in_ECX[1] = 0xffffffff;
  }
  FUN_004eb890(in_ECX + 0x32);
  if ((void *)in_ECX[0x33] == (void *)0x0) {
    in_ECX[0x33] = 0;
    in_ECX[0x34] = 0;
    in_ECX[0x35] = 0;
    *in_ECX = &PTR_FUN_009c1544;
    return;
  }
  _free((void *)in_ECX[0x33]);
  return;
}


// ==== FUN_005a6800 @ 0x005a6800 ====

/* WARNING: Removing unreachable block (ram,0x005a68ab) */
/* WARNING: Removing unreachable block (ram,0x005a6853) */

void FUN_005a6800(float param_1,float param_2)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = __isnan((double)param_1);
  if (iVar2 != 0) {
    FUN_00401740(s___isnan_i_v2Pos_x__009c150c,0x12);
    FUN_00406880();
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  iVar2 = __isnan((double)param_2);
  if (iVar2 == 0) {
    *(float *)(in_ECX + 0xe0) = param_2;
    *(float *)(in_ECX + 0xdc) = param_1;
    FUN_005ae6b0(param_1,param_2);
    return;
  }
  FUN_00401740(s___isnan_i_v2Pos_y__009c1520,0x12);
  FUN_00406880();
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_005a68f0 @ 0x005a68f0 ====

void FUN_005a68f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 uVar5;
  void *pvVar6;
  undefined4 *in_ECX;
  char *pcStack_1c;
  undefined4 uStack_18;
  
  uVar5 = DAT_009b02a8;
  *in_ECX = &PTR_FUN_009c158c;
  in_ECX[10] = 0;
  in_ECX[0xb] = 5000;
  in_ECX[9] = 0;
  in_ECX[7] = uVar5;
  in_ECX[8] = 0;
  puVar2 = in_ECX + 1;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0;
  if (puVar2 == (undefined4 *)0x0) {
    DAT_00b5a988 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a988 = in_ECX;
  }
  uStack_18 = 0x5a695a;
  piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  uStack_18 = 0x1c;
  pcStack_1c = s___Camera_CameraImpl_cpp_009c14dc;
  uVar5 = (**(code **)(*piVar4 + 4))(0);
  *puVar2 = uVar5;
  pvVar6 = operator_new(0x120);
  if (pvVar6 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_005ae710();
  }
  in_ECX[0x36] = uVar5;
  (**(code **)(*DAT_00b5afac + 4))(*puVar2,uVar5,1);
  uVar3 = DAT_009c15cc;
  in_ECX[2] = DAT_0099d100;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  uVar5 = DAT_0099d0f4;
  in_ECX[3] = uVar3;
  in_ECX[6] = uVar5;
  pvVar6 = operator_new(0x20);
  if (pvVar6 == (void *)0x0) {
    pcStack_1c = (char *)0x0;
  }
  else {
    pcStack_1c = (char *)FUN_005beb30();
  }
  iVar1 = in_ECX[0x33];
  if ((iVar1 == 0) || ((uint)(in_ECX[0x35] - iVar1 >> 2) <= (uint)(in_ECX[0x34] - iVar1 >> 2))) {
    FUN_005a6e00(in_ECX[0x34],1,&pcStack_1c);
    *(undefined1 *)(in_ECX + 0x39) = 0;
    *(undefined1 *)((int)in_ECX + 0xe5) = 0;
    return;
  }
  puVar2 = (undefined4 *)in_ECX[0x34];
  *puVar2 = pcStack_1c;
  in_ECX[0x34] = puVar2 + 1;
  *(undefined1 *)(in_ECX + 0x39) = 0;
  *(undefined1 *)((int)in_ECX + 0xe5) = 0;
  return;
}


// ==== FUN_005a6a60 @ 0x005a6a60 ====

void FUN_005a6a60(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  float fVar3;
  undefined1 auStack_80 [64];
  undefined1 auStack_40 [64];
  
  iVar1 = (**(code **)(*DAT_00b5a6e4 + 8))();
  fVar3 = (float)*(int *)(iVar1 + 0x50) / (float)*(int *)(iVar1 + 0x54);
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5afd0 + 8))(fVar3);
  FUN_007a0693(auStack_80,*puVar2,fVar3,puVar2[1],puVar2[2]);
  FUN_007a053b(auStack_40,param_1 + 0x28,param_1 + 0x34,param_1 + 0x40);
  thunk_FUN_0079ee7b(param_2,auStack_40,auStack_80);
  return;
}


// ==== FUN_005a6ae0 @ 0x005a6ae0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a6ae0(float *param_1,float *param_2,float *param_3)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float10 fVar10;
  float fVar11;
  float fVar12;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  undefined4 auStack_80 [16];
  undefined4 auStack_40 [16];
  
  fVar6 = (float)(**(code **)(*DAT_00b5a6ac + 0x18))();
  fVar3 = *param_2;
  fVar4 = param_2[1];
  fVar12 = param_1[1];
  fVar5 = param_2[2];
  fVar11 = param_1[2];
  iVar7 = (**(code **)(*DAT_00b5ae24 + 8))();
  *param_3 = *param_1;
  if (*(float *)(iVar7 + 0xc) <= fVar12 && fVar12 != *(float *)(iVar7 + 0xc)) {
    fVar12 = *(float *)(iVar7 + 0xc);
  }
  if (fVar12 < *(float *)(iVar7 + 8)) {
    fVar12 = *(float *)(iVar7 + 8);
  }
  param_3[1] = fVar12;
  param_3[2] = fVar11;
  param_3[3] = param_1[3];
  param_3[4] = *(float *)(iVar7 + 0x10);
  iVar7 = (**(code **)(*DAT_00b5afd0 + 8))();
  fVar12 = *(float *)(iVar7 + 0xc);
  param_3[7] = fVar3;
  param_3[8] = fVar4;
  param_3[5] = fVar12;
  param_3[9] = fVar5;
  param_3[6] = fVar6;
  FUN_0040d600(&fStack_88,param_3[2]);
  param_3[0xd] = param_3[7];
  param_3[0xe] = param_3[8] + param_3[4];
  param_3[0xf] = param_3[9];
  pfVar1 = param_3 + 0x13;
  fVar10 = (float10)FUN_0040d4d0(param_3[1]);
  *pfVar1 = (float)-(fVar10 * (float10)fStack_88);
  fVar10 = (float10)FUN_0040d4c0(param_3[1]);
  param_3[0x14] = (float)-fVar10;
  fVar10 = (float10)FUN_0040d4d0(param_3[1]);
  fVar12 = *param_3;
  param_3[0x15] = (float)-(fVar10 * (float10)fStack_84);
  param_3[10] = param_3[0xd] - *pfVar1 * fVar12;
  fVar11 = param_3[2] + _DAT_00af4adc;
  param_3[0xb] = param_3[0xe] - param_3[0x14] * fVar12;
  param_3[0xc] = param_3[0xf] - param_3[0x15] * fVar12;
  FUN_0040d600(&fStack_90,fVar11);
  pfVar2 = param_3 + 0x10;
  *pfVar2 = (0.0 - param_3[0x14]) * fStack_8c - (0.0 - param_3[0x15]) * 0.0;
  param_3[0x11] = (0.0 - param_3[0x15]) * fStack_90 - (0.0 - *pfVar1) * fStack_8c;
  param_3[0x12] = (0.0 - *pfVar1) * 0.0 - (0.0 - param_3[0x14]) * fStack_90;
  fVar12 = param_3[3];
  if (fVar12 <= 0.0) {
    fVar12 = 0.0 - param_3[3];
  }
  if (_DAT_009c1534 < fVar12) {
    thunk_FUN_0079fa6c(auStack_80,pfVar1,0.0 - param_3[3]);
    puVar8 = auStack_80;
    puVar9 = auStack_40;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    thunk_FUN_0079e6b3(pfVar2,pfVar2,auStack_40);
  }
  return;
}


// ==== FUN_005a6d90 @ 0x005a6d90 ====

void * FUN_005a6d90(void *param_1,int param_2,void *param_3)

{
  size_t _Size;
  void *pvVar1;
  
  _Size = (param_2 - (int)param_1 >> 2) * 4;
  pvVar1 = _memmove(param_3,param_1,_Size);
  return (void *)((int)pvVar1 + _Size);
}


// ==== FUN_005a6dc0 @ 0x005a6dc0 ====

undefined1 FUN_005a6dc0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xe4);
}


// ==== FUN_005a6dd0 @ 0x005a6dd0 ====

undefined1 FUN_005a6dd0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xe5);
}


// ==== FUN_005a6de0 @ 0x005a6de0 ====

void FUN_005a6de0(byte param_1)

{
  void *in_ECX;
  
  FUN_005a6760();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a6e00 @ 0x005a6e00 ====

void FUN_005a6e00(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982710;
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


// ==== Catch@005a6f61 @ 0x005a6f61 ====

void Catch_005a6f61(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005a7050 @ 0x005a7050 ====

void FUN_005a7050(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1664;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a7090 @ 0x005a7090 ====

void FUN_005a7090(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  char cVar2;
  
  for (; param_1 != param_2; param_1 = (undefined4 *)*param_1) {
    piVar1 = (int *)param_1[3];
    cVar2 = (**(code **)(*piVar1 + 4))(param_3,param_4);
    if (cVar2 == '\0') {
      (**(code **)(*piVar1 + 0x10))(1);
    }
    else {
      (**(code **)(*piVar1 + 0x10))(0);
    }
  }
  return;
}


// ==== FUN_005a7170 @ 0x005a7170 ====

void FUN_005a7170(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x14c);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if ((char)((int *)puVar2[3])[7] == '\0') {
      (**(code **)(*(int *)puVar2[3] + 0xc))(param_1);
    }
  }
  puVar1 = *(undefined4 **)(in_ECX + 0xfc);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if ((char)((int *)puVar2[3])[7] == '\0') {
      (**(code **)(*(int *)puVar2[3] + 0xc))(param_1);
    }
  }
  return;
}


// ==== FUN_005a71d0 @ 0x005a71d0 ====

void FUN_005a71d0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xac);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[3] + 0xc))(param_1);
  }
  if (*(int *)(in_ECX + 0x198) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x198) + 0xc))(param_1);
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x5c);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if ((char)((int *)puVar2[3])[7] == '\0') {
      (**(code **)(*(int *)puVar2[3] + 0xc))(param_1);
    }
  }
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if ((char)((int *)puVar2[3])[7] == '\0') {
      (**(code **)(*(int *)puVar2[3] + 0xc))(param_1);
    }
  }
  FUN_005a7170(param_1);
  return;
}


// ==== FUN_005a7260 @ 0x005a7260 ====

void FUN_005a7260(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  char cVar8;
  
  uVar6 = param_4;
  iVar5 = param_1;
  puVar1 = *(undefined4 **)(param_2 + 4);
  puVar2 = (undefined4 *)*puVar1;
  while (puVar2 != puVar1) {
    param_2 = puVar2[3];
    FUN_00897340(&param_1,&param_2);
    if (param_1 != *(int *)(iVar5 + 8)) {
      piVar3 = *(int **)(param_1 + 0xc);
      cVar8 = (**(code **)(*piVar3 + 4))(param_3,uVar6);
      if (cVar8 == '\0') {
        (**(code **)(*piVar3 + 0x10))(1);
      }
      else {
        (**(code **)(*piVar3 + 0x10))(0);
      }
    }
    if (*(char *)((int)puVar2 + 0x11) == '\0') {
      puVar4 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar4 + 0x11) == '\0') {
        cVar8 = *(char *)((int)*puVar4 + 0x11);
        puVar2 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar8 == '\0') {
          cVar8 = *(char *)((int)*puVar4 + 0x11);
          puVar2 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar8 = *(char *)((int)puVar2[1] + 0x11);
        puVar7 = (undefined4 *)puVar2[1];
        puVar4 = puVar2;
        while ((puVar2 = puVar7, cVar8 == '\0' && (puVar4 == (undefined4 *)puVar2[2]))) {
          cVar8 = *(char *)((int)puVar2[1] + 0x11);
          puVar7 = (undefined4 *)puVar2[1];
          puVar4 = puVar2;
        }
      }
    }
  }
  return;
}


// ==== FUN_005a7320 @ 0x005a7320 ====

undefined4 FUN_005a7320(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 8)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0xc);
}


// ==== FUN_005a7350 @ 0x005a7350 ====

void FUN_005a7350(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int *piVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x194) != 0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18._1_3_ << 8);
    FUN_00401740(s_m_dwMapID____0_009c15d4,0xe);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_18);
    return;
  }
  if (*(int *)(in_ECX + 0x198) == 0) {
    *(undefined4 *)(in_ECX + 0x194) = param_1;
    *(undefined4 *)(in_ECX + 0x198) = param_2;
    piVar2 = (int *)FUN_005bf540(param_3);
    *(int **)(in_ECX + 0x19c) = piVar2;
    (**(code **)(*piVar2 + 4))(in_ECX + 4);
    piVar2 = (int *)FUN_005bf540(param_3);
    *(int **)(in_ECX + 0x1a0) = piVar2;
    (**(code **)(*piVar2 + 4))(in_ECX + 0x54);
    piVar2 = (int *)FUN_005bf540(param_3);
    *(int **)(in_ECX + 0x1a4) = piVar2;
    (**(code **)(*piVar2 + 4))(in_ECX + 0xf4);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18._1_3_ << 8);
  FUN_00401740(s_m_pRenderMapUnit____NULL_009c15e4,0x18);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005a7470 @ 0x005a7470 ====

void FUN_005a7470(int param_1)

{
  code *pcVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x194) != param_1) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18._1_3_ << 8);
    FUN_00401740(s_m_dwMapID____i_dwOwnerID_009c1600,0x18);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_18);
    return;
  }
  if (*(int *)(in_ECX + 0x198) != 0) {
    *(undefined4 *)(in_ECX + 0x194) = 0;
    *(undefined4 *)(in_ECX + 0x198) = 0;
    FUN_005bf560(*(undefined4 *)(in_ECX + 0x19c));
    *(undefined4 *)(in_ECX + 0x19c) = 0;
    FUN_005bf560(*(undefined4 *)(in_ECX + 0x1a0));
    *(undefined4 *)(in_ECX + 0x1a0) = 0;
    FUN_005bf560(*(undefined4 *)(in_ECX + 0x1a4));
    *(undefined4 *)(in_ECX + 0x1a4) = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18._1_3_ << 8);
  FUN_00401740(s_m_pRenderMapUnit____NULL_009c161c,0x18);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005a7560 @ 0x005a7560 ====

void FUN_005a7560(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1684;
  DAT_00b5afac = 0;
  if ((void *)in_ECX[0x60] != (void *)0x0) {
    _free((void *)in_ECX[0x60]);
    return;
  }
  in_ECX[0x60] = 0;
  in_ECX[0x61] = 0;
  in_ECX[0x62] = 0;
  FUN_008984a0();
  if ((void *)in_ECX[0x56] != (void *)0x0) {
    _free((void *)in_ECX[0x56]);
    return;
  }
  in_ECX[0x56] = 0;
  in_ECX[0x57] = 0;
  in_ECX[0x58] = 0;
  FUN_008984a0();
  if ((void *)in_ECX[0x4c] != (void *)0x0) {
    _free((void *)in_ECX[0x4c]);
    return;
  }
  in_ECX[0x4c] = 0;
  in_ECX[0x4d] = 0;
  in_ECX[0x4e] = 0;
  FUN_008984a0();
  if ((void *)in_ECX[0x42] != (void *)0x0) {
    _free((void *)in_ECX[0x42]);
    return;
  }
  in_ECX[0x42] = 0;
  in_ECX[0x43] = 0;
  in_ECX[0x44] = 0;
  FUN_008984a0();
  if ((void *)in_ECX[0x38] != (void *)0x0) {
    _free((void *)in_ECX[0x38]);
    return;
  }
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  in_ECX[0x3a] = 0;
  FUN_008984a0();
  if ((void *)in_ECX[0x2e] != (void *)0x0) {
    _free((void *)in_ECX[0x2e]);
    return;
  }
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  FUN_008984a0();
  if ((void *)in_ECX[0x24] != (void *)0x0) {
    _free((void *)in_ECX[0x24]);
    return;
  }
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  FUN_008984a0();
  if ((void *)in_ECX[0x1a] != (void *)0x0) {
    _free((void *)in_ECX[0x1a]);
    return;
  }
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  FUN_008984a0();
  if ((void *)in_ECX[0x10] != (void *)0x0) {
    _free((void *)in_ECX[0x10]);
    return;
  }
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  FUN_008984a0();
  if ((void *)in_ECX[6] == (void *)0x0) {
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    FUN_008984a0();
    *in_ECX = &PTR_FUN_009c1664;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_005a7730 @ 0x005a7730 ====

void FUN_005a7730(undefined4 param_1)

{
  int *piVar1;
  code *pcVar2;
  int in_ECX;
  undefined4 local_2c;
  undefined1 auStack_28 [12];
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  FUN_00897340(&local_2c,&param_1);
  if ((local_2c != (int *)*(int *)(in_ECX + 8)) &&
     (piVar1 = *(int **)((int)local_2c + 0xc), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x10))(0);
    local_2c = piVar1;
    FUN_005a88d0(auStack_28,auStack_28 + -8);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pRenderUnit____NULL_009c1638,0x13);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005a7810 @ 0x005a7810 ====

void FUN_005a7810(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  local_10 = param_1;
  local_c = param_2;
  FUN_005a88d0(local_8,&local_10);
  return;
}


// ==== FUN_005a7840 @ 0x005a7840 ====

void FUN_005a7840(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1684;
  FUN_005a8bc0();
  FUN_005a8bc0();
  FUN_005a8bc0();
  FUN_005a8bc0();
  FUN_005a8bc0();
  in_ECX[0x65] = 0;
  in_ECX[0x66] = 0;
  in_ECX[0x67] = 0;
  in_ECX[0x68] = 0;
  in_ECX[0x69] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5afac = (undefined4 *)0x0;
    return;
  }
  DAT_00b5afac = in_ECX;
  return;
}


// ==== FUN_005a78c0 @ 0x005a78c0 ====

void FUN_005a78c0(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  undefined4 unaff_retaddr;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  uVar1 = param_1;
  if (param_3 == 0) {
    FUN_00897340(&param_3,&param_1);
    if ((param_3 != in_ECX[0x17]) && (*(int *)(param_3 + 0xc) != 0)) {
      (**(code **)(*in_ECX + 8))(uVar1,0);
    }
    uVar2 = param_2;
    local_10 = uVar1;
    local_c = param_2;
    FUN_005a88d0(local_8,&local_10);
    if (in_ECX[0x68] != 0) {
      (**(code **)(*(int *)in_ECX[0x68] + 8))(uVar1,uVar2);
      return;
    }
  }
  else if ((param_3 == 2) || (param_3 == 5)) {
    FUN_00897340(&param_3,&param_1);
    if ((param_3 != in_ECX[3]) && (*(int *)(param_3 + 0xc) != 0)) {
      (**(code **)(*in_ECX + 8))(uVar1,2);
    }
    uVar2 = param_2;
    local_10 = uVar1;
    local_c = param_2;
    FUN_005a88d0(local_8,&local_10);
    if (in_ECX[0x67] != 0) {
      (**(code **)(*(int *)in_ECX[0x67] + 8))(uVar1,uVar2);
    }
  }
  else {
    if (param_3 == 1) {
      iVar3 = FUN_005a7320(param_1);
      if (iVar3 != 0) {
        (**(code **)(*in_ECX + 8))(uVar1,1);
      }
      FUN_005a7810(uVar1,param_2);
      return;
    }
    if (param_3 == 3) {
      (**(code **)(*in_ECX + 8))(param_1,3);
      FUN_005a7810(uVar1,unaff_retaddr);
      if (in_ECX[0x69] != 0) {
        (**(code **)(*(int *)in_ECX[0x69] + 8))(uVar1,unaff_retaddr);
        return;
      }
    }
    else if (param_3 == 4) {
      (**(code **)(*in_ECX + 8))(param_1,4);
      FUN_005a7810(uVar1,unaff_retaddr);
      return;
    }
  }
  return;
}


// ==== FUN_005a7a80 @ 0x005a7a80 ====

void FUN_005a7a80(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x84);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[3] + 0x10))(1);
  }
  FUN_005a8b00();
  puVar1 = *(undefined4 **)(in_ECX + 0x34);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[3] + 0x10))(1);
  }
  FUN_005a8b00();
  puVar1 = *(undefined4 **)(in_ECX + 0x124);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[3] + 0x10))(1);
  }
  FUN_005a8b00();
  return;
}


// ==== FUN_005a7b00 @ 0x005a7b00 ====

void FUN_005a7b00(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 8)) {
    FUN_00598f60(&local_4,local_4);
    FUN_005a8c50(&param_1);
  }
  return;
}


// ==== FUN_005a7b40 @ 0x005a7b40 ====

void FUN_005a7b40(undefined4 param_1)

{
  code *pcVar1;
  int in_ECX;
  undefined1 uStack00000000;
  undefined4 local_24;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_24 = param_1;
  FUN_00897340(&local_20,&local_24);
  if ((local_20 != *(int *)(in_ECX + 8)) && (*(int **)(local_20 + 0xc) != (int *)0x0)) {
    (**(code **)(**(int **)(local_20 + 0xc) + 0x10))(1);
    FUN_005a8c50(&uStack00000000);
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pRenderUnit____NULL_009c164c,0x13);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005a7be0 @ 0x005a7be0 ====

void FUN_005a7be0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  char cVar5;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    piVar3 = (int *)puVar2[3];
    uVar4 = puVar2[2];
    cVar5 = (**(code **)(*piVar3 + 4))(param_1,param_2);
    if (cVar5 == '\0') {
      FUN_005a7b40(uVar4);
      (**(code **)(*piVar3 + 0x10))(1);
    }
    else {
      FUN_005a7730(uVar4);
      (**(code **)(*piVar3 + 0x10))(0);
    }
  }
  return;
}


// ==== FUN_005a7cb0 @ 0x005a7cb0 ====

void FUN_005a7cb0(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = param_1;
  if (param_2 == 0) {
    FUN_00897340(&param_2,&param_1);
    if (param_2 != *(int *)(in_ECX + 0x5c)) {
      FUN_00598f60(&param_2,param_2);
      FUN_005a8c50(&param_1);
    }
    if (*(int *)(in_ECX + 0x1a0) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x1a0) + 0xc))(uVar1);
      return;
    }
  }
  else if ((param_2 == 2) || (param_2 == 5)) {
    FUN_00897340(&param_2,&param_1);
    if (param_2 != *(int *)(in_ECX + 0xc)) {
      FUN_00598f60(&param_2,param_2);
      FUN_005a8c50(&param_1);
    }
    if (*(int *)(in_ECX + 0x19c) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x19c) + 0xc))(uVar1);
    }
  }
  else {
    if (param_2 == 1) {
      FUN_005a7b00(param_1);
      return;
    }
    if (param_2 == 3) {
      FUN_005a7b00(param_1);
      if (*(int *)(in_ECX + 0x1a4) != 0) {
        (**(code **)(**(int **)(in_ECX + 0x1a4) + 0xc))(uVar1);
        return;
      }
    }
    else if (param_2 == 4) {
      FUN_005a7b00(param_1);
      return;
    }
  }
  return;
}


// ==== FUN_005a7e40 @ 0x005a7e40 ====

void FUN_005a7e40(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  char cVar6;
  int *piVar7;
  
  iVar4 = param_1;
  piVar1 = *(int **)(param_2 + 4);
  piVar7 = (int *)*piVar1;
  if (piVar7 != piVar1) {
    do {
      iVar2 = piVar7[3];
      param_2 = iVar2;
      FUN_00897340(&param_1,&param_2);
      if (param_1 != *(int *)(iVar4 + 8)) {
        piVar3 = *(int **)(param_1 + 0xc);
        cVar6 = (**(code **)(*piVar3 + 4))(param_3,param_4);
        if (cVar6 == '\0') {
          FUN_005a7b40(iVar2);
          (**(code **)(*piVar3 + 0x10))(1);
        }
        else {
          FUN_005a7730(iVar2);
          (**(code **)(*piVar3 + 0x10))(0);
        }
      }
      if (*(char *)((int)piVar7 + 0x11) == '\0') {
        piVar3 = (int *)piVar7[2];
        if (*(char *)((int)piVar3 + 0x11) == '\0') {
          cVar6 = *(char *)(*piVar3 + 0x11);
          piVar7 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar6 == '\0') {
            cVar6 = *(char *)(*piVar3 + 0x11);
            piVar7 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar6 = *(char *)(piVar7[1] + 0x11);
          piVar5 = (int *)piVar7[1];
          piVar3 = piVar7;
          while ((piVar7 = piVar5, cVar6 == '\0' && (piVar3 == (int *)piVar7[2]))) {
            cVar6 = *(char *)(piVar7[1] + 0x11);
            piVar5 = (int *)piVar7[1];
            piVar3 = piVar7;
          }
        }
      }
    } while (piVar7 != piVar1);
  }
  return;
}


// ==== FUN_005a7f10 @ 0x005a7f10 ====

void FUN_005a7f10(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 *puVar5;
  undefined4 unaff_retaddr;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x198) + 0x18))();
  puVar1 = *(undefined4 **)(iVar2 + 8);
  for (puVar5 = *(undefined4 **)(iVar2 + 4); puVar5 != puVar1; puVar5 = puVar5 + 1) {
    uVar4 = *puVar5;
    uVar3 = (**(code **)(**(int **)(in_ECX + 0x19c) + 0x10))(uVar4);
    FUN_005a7e40(in_ECX + 4,uVar3,unaff_retaddr,param_2);
    uVar3 = (**(code **)(**(int **)(in_ECX + 0x1a0) + 0x10))(uVar4);
    FUN_005a7e40(in_ECX + 0x54,uVar3,puVar1,param_2);
    uVar4 = (**(code **)(**(int **)(in_ECX + 0x1a4) + 0x10))(uVar4);
    FUN_005a7260(in_ECX + 0xf4,uVar4,param_1,param_2);
  }
  return;
}


// ==== FUN_005a7fb0 @ 0x005a7fb0 ====

void FUN_005a7fb0(void)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined1 *puStack_160;
  undefined4 uStack_15c;
  undefined1 auStack_14a [2];
  undefined4 local_148;
  undefined4 local_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined4 uStack_114;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined1 auStack_f8 [8];
  undefined1 auStack_f0 [8];
  undefined4 auStack_e8 [2];
  undefined1 local_e0 [220];
  
  uStack_15c = &local_148;
  puStack_160 = local_e0;
  local_148 = DAT_0099d0dc;
  local_144 = DAT_0099d0dc;
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a988 + 0x1c))();
  local_148 = *puVar3;
  local_144 = puVar3[1];
  uStack_140 = puVar3[2];
  uStack_13c = puVar3[3];
  uStack_138 = puVar3[4];
  uStack_134 = puVar3[5];
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a988 + 0x1c))(auStack_e8,auStack_14a + -6);
  uStack_138 = *puVar3;
  uStack_134 = puVar3[1];
  uStack_130 = puVar3[2];
  uStack_12c = puVar3[3];
  uStack_128 = puVar3[4];
  uStack_124 = puVar3[5];
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a988 + 0x1c))(auStack_f0,auStack_14a + -0xe);
  uStack_128 = *puVar3;
  uStack_124 = puVar3[1];
  uStack_120 = puVar3[2];
  uStack_11c = puVar3[3];
  uStack_118 = puVar3[4];
  uStack_114 = puVar3[5];
  puStack_160 = DAT_0099d080;
  uStack_15c = (undefined4 *)DAT_0099d080;
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a988 + 0x1c))(auStack_f8,&puStack_160);
  uStack_118 = *puVar3;
  uStack_114 = puVar3[1];
  uStack_110 = puVar3[2];
  uStack_10c = puVar3[3];
  uStack_108 = puVar3[4];
  uStack_104 = puVar3[5];
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5afd0 + 0xc))();
  iVar1 = *(int *)(in_ECX + 0x19c);
  puVar5 = auStack_e8;
  for (iVar4 = 0x30; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  if (iVar1 == 0) {
    FUN_005a7090(**(undefined4 **)(in_ECX + 0xc),*(undefined4 **)(in_ECX + 0xc),auStack_e8,
                 &puStack_160);
    FUN_005a7090(**(undefined4 **)(in_ECX + 0x5c),*(undefined4 **)(in_ECX + 0x5c),auStack_e8,
                 &puStack_160);
    FUN_005a7090(**(undefined4 **)(in_ECX + 0xfc),*(undefined4 **)(in_ECX + 0xfc),auStack_e8,
                 &puStack_160);
  }
  else {
    cVar2 = (**(code **)(**(int **)(in_ECX + 0x198) + 4))(auStack_e8,&puStack_160);
    if (cVar2 == '\0') {
      FUN_005a7be0(auStack_e8,&puStack_160);
      FUN_005a7be0(auStack_e8,&puStack_160);
      FUN_005a7be0(auStack_e8,&puStack_160);
    }
    else {
      FUN_005a7a80();
      FUN_005a7f10(auStack_e8,&puStack_160);
    }
  }
  FUN_005a7be0(auStack_e8,&puStack_160);
  return;
}


// ==== FUN_005a8220 @ 0x005a8220 ====

int FUN_005a8220(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982720;
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


// ==== Catch@005a8286 @ 0x005a8286 ====

void Catch_005a8286(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005a8290 @ 0x005a8290 ====

void FUN_005a8290(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982730;
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


// ==== Catch@005a82ff @ 0x005a82ff ====

void Catch_005a82ff(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005a8320 @ 0x005a8320 ====

void * FUN_005a8320(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982740;
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


// ==== Catch@005a838d @ 0x005a838d ====

void Catch_005a838d(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005a83b0 @ 0x005a83b0 ====

void FUN_005a83b0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982750;
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


// ==== Catch@005a8416 @ 0x005a8416 ====

void Catch_005a8416(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005a8420 @ 0x005a8420 ====

void FUN_005a8420(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005a8220(param_1,param_2,param_3);
  return;
}


// ==== FUN_005a8440 @ 0x005a8440 ====

void FUN_005a8440(undefined4 *param_1,uint *param_2)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  
  uVar2 = *param_2;
  uVar4 = (uVar2 ^ 0xdeadbeef) & *(uint *)(in_ECX + 0x20);
  if (*(uint *)(in_ECX + 0x24) <= uVar4) {
    uVar4 = uVar4 + (-1 - (*(uint *)(in_ECX + 0x20) >> 1));
  }
  piVar1 = (int *)(*(int *)(in_ECX + 0x14) + uVar4 * 4);
  piVar5 = (int *)*piVar1;
  if (piVar5 != (int *)piVar1[1]) {
    do {
      if (uVar2 <= (uint)piVar5[2]) {
        if (piVar5 != (int *)piVar1[1]) {
          piVar6 = piVar5;
          goto LAB_005a8498;
        }
        break;
      }
      piVar5 = (int *)*piVar5;
    } while (piVar5 != (int *)piVar1[1]);
  }
  goto LAB_005a847d;
  while (piVar6 = (int *)*piVar6, piVar6 != (int *)piVar1[1]) {
LAB_005a8498:
    if (uVar2 < (uint)piVar6[2]) break;
  }
  if (piVar5 != piVar6) {
    *param_1 = piVar5;
    param_1[1] = piVar6;
    return;
  }
LAB_005a847d:
  uVar3 = *(undefined4 *)(in_ECX + 8);
  *param_1 = uVar3;
  param_1[1] = uVar3;
  return;
}


// ==== FUN_005a84c0 @ 0x005a84c0 ====

int FUN_005a84c0(int param_1,int param_2,undefined4 param_3)

{
  FUN_005a83b0(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_005a84f0 @ 0x005a84f0 ====

void FUN_005a84f0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982760;
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
      uVar5 = FUN_005a8420(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_005a84c0(uVar5,param_2,&local_18);
      FUN_005a8420(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_005a8220(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_005a84c0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_005a8220(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005a8651 @ 0x005a8651 ====

void Catch_005a8651(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005a8740 @ 0x005a8740 ====

void FUN_005a8740(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982770;
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
    uVar2 = FUN_005a84c0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005a87d4 @ 0x005a87d4 ====

void Catch_005a87d4(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005a87f0 @ 0x005a87f0 ====

void FUN_005a87f0(uint param_1,undefined1 param_2)

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
    FUN_005a84f0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_005a8860 @ 0x005a8860 ====

/* WARNING: Removing unreachable block (ram,0x005a887b) */
/* WARNING: Removing unreachable block (ram,0x005a8880) */
/* WARNING: Removing unreachable block (ram,0x005a888e) */

void FUN_005a8860(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_005a84f0(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_005a88b0 @ 0x005a88b0 ====

void FUN_005a88b0(byte param_1)

{
  void *in_ECX;
  
  FUN_005a7560();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a88d0 @ 0x005a88d0 ====

/* WARNING: Removing unreachable block (ram,0x005a89b8) */

void FUN_005a88d0(int *param_1,uint *param_2)

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
      FUN_005a87f0(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_005a8320(puVar7,puVar7[1],param_2);
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


// ==== FUN_005a8b00 @ 0x005a8b00 ====

void FUN_005a8b00(void)

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
    FUN_005a8860(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_005a8b60 @ 0x005a8b60 ====

void FUN_005a8b60(undefined4 *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  
  piVar3 = param_3;
  piVar2 = param_2;
  if ((param_2 == (int *)**(int **)(in_ECX + 8)) && (param_3 == *(int **)(in_ECX + 8))) {
    FUN_005a8b00();
    *param_1 = **(undefined4 **)(in_ECX + 8);
    return;
  }
  while (piVar2 != piVar3) {
    piVar1 = (int *)*piVar2;
    FUN_00598f60(&param_2,piVar2);
    piVar2 = piVar1;
  }
  *param_1 = piVar2;
  return;
}


// ==== FUN_005a8bc0 @ 0x005a8bc0 ====

void FUN_005a8bc0(void)

{
  undefined4 uVar1;
  undefined1 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  *in_ECX = local_5;
  uVar1 = FUN_005a8290();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  local_4 = *(undefined4 *)(in_ECX + 8);
  FUN_005a8740(9,&local_4);
  *(undefined4 *)(in_ECX + 0x20) = 1;
  *(undefined4 *)(in_ECX + 0x24) = 1;
  in_ECX[0x28] = local_5;
  uVar1 = FUN_005a8290();
  *(undefined4 *)(in_ECX + 0x30) = uVar1;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  local_4 = *(undefined4 *)(in_ECX + 0x30);
  FUN_005a8740(9,&local_4);
  *(undefined4 *)(in_ECX + 0x48) = 1;
  *(undefined4 *)(in_ECX + 0x4c) = 1;
  return;
}


// ==== FUN_005a8c50 @ 0x005a8c50 ====

int FUN_005a8c50(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *local_8;
  undefined4 *local_4;
  
  FUN_005a8440(&local_8,param_1);
  iVar2 = 0;
  for (puVar1 = local_8; puVar1 != local_4; puVar1 = (undefined4 *)*puVar1) {
    iVar2 = iVar2 + 1;
  }
  FUN_005a8b60(&param_1,local_8,local_4);
  return iVar2;
}


// ==== FUN_005a8cb0 @ 0x005a8cb0 ====

void FUN_005a8cb0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  uVar3 = DAT_009c16c0;
  uVar2 = DAT_009b0e8c;
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_009c16a8;
  *(undefined1 *)(in_ECX + 8) = 0;
  in_ECX[0x10] = uVar1;
  in_ECX[0x11] = uVar1;
  in_ECX[0x12] = uVar1;
  in_ECX[0x13] = uVar3;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = uVar2;
  in_ECX[0x18] = DAT_009c16a0;
  in_ECX[0x19] = DAT_0099de78;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = uVar1;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  *(undefined1 *)(in_ECX + 0x25) = 0;
  *(undefined1 *)((int)in_ECX + 0x91) = 0;
  *(undefined1 *)(in_ECX + 0x1f) = 0;
  return;
}


// ==== FUN_005a8d50 @ 0x005a8d50 ====

void FUN_005a8d50(int *param_1)

{
  float fVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_8c;
  undefined4 *puStack_88;
  undefined4 *puStack_84;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_60 = *(undefined4 *)(in_ECX + 0x4c);
  local_6c = *(undefined4 *)(in_ECX + 0x40);
  local_68 = *(undefined4 *)(in_ECX + 0x44);
  local_64 = *(undefined4 *)(in_ECX + 0x48);
  puStack_84 = &local_6c;
  puStack_88 = (undefined4 *)0x5a8d8c;
  (**(code **)(*param_1 + 0x20))();
  uStack_24 = *(undefined4 *)(in_ECX + 0x3c);
  uStack_30 = *(undefined4 *)(in_ECX + 0x30);
  uStack_2c = *(undefined4 *)(in_ECX + 0x34);
  uStack_28 = *(undefined4 *)(in_ECX + 0x38);
  uStack_3c = *(undefined4 *)(in_ECX + 0x24);
  uStack_38 = *(undefined4 *)(in_ECX + 0x28);
  uStack_34 = *(undefined4 *)(in_ECX + 0x2c);
  puStack_88 = &uStack_3c;
  uStack_8c = (undefined4 *)0x5a8dd1;
  (**(code **)(*param_1 + 0x28))();
  uStack_58 = *(undefined4 *)(in_ECX + 0x5c);
  local_64 = *(undefined4 *)(in_ECX + 0x50);
  local_60 = *(undefined4 *)(in_ECX + 0x54);
  uStack_5c = *(undefined4 *)(in_ECX + 0x58);
  uStack_8c = &local_64;
  (**(code **)(*param_1 + 0x30))();
  uStack_54 = *(undefined4 *)(in_ECX + 0x80);
  uStack_50 = *(undefined4 *)(in_ECX + 0x84);
  uStack_4c = *(undefined4 *)(in_ECX + 0x88);
  uStack_48 = *(undefined4 *)(in_ECX + 0x8c);
  uStack_58 = CONCAT31(uStack_58._1_3_,*(undefined1 *)(in_ECX + 0x7c));
  (**(code **)(*param_1 + 0x40))(&uStack_58);
  fVar1 = *(float *)(in_ECX + 0x60);
  if (*(float *)(in_ECX + 100) <= fVar1 && fVar1 != *(float *)(in_ECX + 100)) {
    *(float *)(in_ECX + 100) = fVar1 + DAT_0099d080;
  }
  uStack_18 = *(undefined4 *)(in_ECX + 100);
  uStack_2c = *(undefined4 *)(in_ECX + 0x70);
  uStack_28 = *(undefined4 *)(in_ECX + 0x74);
  uStack_24 = *(undefined4 *)(in_ECX + 0x78);
  uStack_1c = *(undefined4 *)(in_ECX + 0x60);
  uStack_20 = *(undefined4 *)(in_ECX + 0x6c);
  uStack_14 = *(undefined4 *)(in_ECX + 0x68);
  (**(code **)(*param_1 + 0x38))(&uStack_2c);
  uStack_8c._0_2_ = CONCAT11(*(undefined1 *)(in_ECX + 0x90),*(undefined1 *)(in_ECX + 0x21));
  (**(code **)(*param_1 + 0x48))(&uStack_8c);
  uStack_8c._0_2_ = CONCAT11(*(undefined1 *)(in_ECX + 0x93),*(undefined1 *)(in_ECX + 0x91));
  uStack_8c = (undefined4 *)
              CONCAT13(*(undefined1 *)(in_ECX + 0x94),
                       CONCAT12(*(undefined1 *)(in_ECX + 0x92),(undefined2)uStack_8c));
  puStack_88 = (undefined4 *)CONCAT31(puStack_88._1_3_,*(undefined1 *)(in_ECX + 0x95));
  iVar2 = (**(code **)(*DAT_00b5afb4 + 0x10))();
  if (*(char *)(iVar2 + 0xd8) == '\x01') {
    uStack_8c = (undefined4 *)CONCAT31(uStack_8c._1_3_,1);
  }
  (**(code **)(*param_1 + 0x50))(&uStack_8c);
  return;
}


// ==== FUN_005a8f40 @ 0x005a8f40 ====

void FUN_005a8f40(void)

{
  return;
}


// ==== FUN_005a8f50 @ 0x005a8f50 ====

undefined1 FUN_005a8f50(void)

{
  return 1;
}


// ==== FUN_005a8f60 @ 0x005a8f60 ====

undefined1 FUN_005a8f60(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x74);
}


// ==== FUN_005a8f70 @ 0x005a8f70 ====

void FUN_005a8f70(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x74) = param_1;
  return;
}


// ==== FUN_005a8f80 @ 0x005a8f80 ====

void FUN_005a8f80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x5c) = param_1;
  *(undefined4 *)(in_ECX + 0x60) = param_2;
  *(undefined4 *)(in_ECX + 100) = param_3;
  return;
}


// ==== FUN_005a8fa0 @ 0x005a8fa0 ====

undefined1 FUN_005a8fa0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x75);
}


// ==== FUN_005a8fb0 @ 0x005a8fb0 ====

void FUN_005a8fb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1724;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005a8fd0 @ 0x005a8fd0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a8fd0(void)

{
  uint uVar1;
  int iVar2;
  float fVar3;
  int in_ECX;
  char cVar4;
  
  uVar1 = *(uint *)(in_ECX + 0xec);
  if (1 < uVar1) {
    iVar2 = **(int **)(in_ECX + 0x98);
    cVar4 = '\0';
    if (iVar2 != 0) {
      cVar4 = (iVar2 != 1) + '\x01';
    }
    fVar3 = (float)(int)uVar1;
    if ((int)uVar1 < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    FUN_0081d860(cVar4,0,fVar3,(*(int **)(in_ECX + 0x98))[0x10]);
  }
  return;
}


// ==== FUN_005a9030 @ 0x005a9030 ====

void FUN_005a9030(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x75) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(in_ECX + 0x7c);
  return;
}


// ==== FUN_005a9050 @ 0x005a9050 ====

void FUN_005a9050(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(in_ECX + 0x5c);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(in_ECX + 0x60);
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(in_ECX + 100);
  return;
}


// ==== FUN_005a90a0 @ 0x005a90a0 ====

undefined4 FUN_005a90a0(void)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0xf0) != '\x01') {
    if (*(int **)(in_ECX + 0xc4) == (int *)0x0) {
      cVar1 = (**(code **)(**(int **)(in_ECX + 200) + 0x2c))();
      if (cVar1 == '\0') {
        return 0;
      }
      uVar2 = FUN_004b3b40();
      *(undefined4 *)(in_ECX + 0xec) = uVar2;
      FUN_005a8fd0();
    }
    else {
      cVar1 = (**(code **)(**(int **)(in_ECX + 0xc4) + 0x2c))();
      if (cVar1 == '\0') {
        return 0;
      }
    }
    *(undefined1 *)(in_ECX + 0xf0) = 1;
  }
  return 1;
}


// ==== FUN_005a9100 @ 0x005a9100 ====

void FUN_005a9100(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1764;
  if (in_ECX[0x32] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x32]);
    in_ECX[0x32] = 0;
  }
  if (in_ECX[0x31] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x31]);
    in_ECX[0x31] = 0;
  }
  if ((void *)in_ECX[0x34] == (void *)0x0) {
    in_ECX[0x34] = 0;
    in_ECX[0x35] = 0;
    in_ECX[0x36] = 0;
    *in_ECX = &PTR_FUN_009c1724;
    return;
  }
  _free((void *)in_ECX[0x34]);
  return;
}


// ==== FUN_005a9180 @ 0x005a9180 ====

void FUN_005a9180(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  uVar3 = DAT_0099d080;
  *(undefined1 *)(in_ECX + 0xf0) = 0;
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x9c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x94) = 0xff000000;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x88) = uVar3;
  *(undefined4 *)(in_ECX + 0x8c) = uVar3;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = 0;
  iVar1 = *(int *)(param_1 + 0x20);
  if (*(int *)(iVar1 + 0x1c) != 0) {
    uVar3 = FUN_005aa1b0(iVar1 + 8);
    *(undefined4 *)(in_ECX + 0xc4) = uVar3;
    *(undefined4 *)(in_ECX + 0xec) = 1;
    return;
  }
  if (*(int *)(iVar1 + 0x38) != 0) {
    uVar3 = FUN_005aa220(iVar1 + 0x24);
    *(undefined4 *)(in_ECX + 200) = uVar3;
    *(undefined4 *)(in_ECX + 0xec) = 1;
    return;
  }
  FUN_00401830(s_false_009c16c8);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005a9290 @ 0x005a9290 ====

void FUN_005a9290(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_005a9180(param_1);
  *(undefined4 *)(in_ECX + 4) = param_2;
  return;
}


// ==== FUN_005a92b0 @ 0x005a92b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a92b0(float param_1)

{
  int iVar1;
  float *pfVar2;
  undefined4 uVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  float10 fVar6;
  float fVar7;
  float fVar8;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  uVar4 = (uint)param_1;
  if ((uint)param_1 < *(uint *)(in_ECX + 0x80)) {
    *(uint *)(in_ECX + 0x80) = *(uint *)(in_ECX + 0x80) - (int)param_1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x80) = 0;
  }
  iVar5 = *(int *)(in_ECX + 0x80);
  iVar1 = *(int *)(in_ECX + 0x7c);
  fVar7 = (float)iVar5;
  if (iVar5 < 0) {
    fVar7 = fVar7 + _DAT_0099d104;
  }
  fVar8 = (float)iVar1;
  if (iVar1 < 0) {
    fVar8 = fVar8 + _DAT_0099d104;
  }
  fVar7 = DAT_0099d080 - fVar7 / fVar8;
  if (DAT_0099d080 <= fVar7) {
    fVar7 = DAT_0099d080;
  }
  else {
    if (fVar7 < 0.0) {
      fVar7 = 0.0;
    }
  }
  iVar1 = iVar1 - iVar5;
  iVar5 = (int)(fVar7 * DAT_009bf5a0);
  param_1 = DAT_0099d080;
  local_c = DAT_0099d080;
  local_8 = DAT_0099d080;
  local_4 = DAT_0099d080;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x58) != 0) {
    fVar6 = (float10)FUN_005aa2a0(iVar5,iVar1);
    param_1 = (float)fVar6;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0x90) != 0) {
    pfVar2 = (float *)FUN_005aa3a0(&local_1c,iVar5,iVar1);
    local_c = *pfVar2;
    local_8 = pfVar2[1];
    local_4 = pfVar2[2];
  }
  local_1c = local_c;
  local_18 = local_8;
  local_14 = local_4;
  local_10 = param_1;
  uVar3 = FUN_0040ead0(&local_1c);
  fVar7 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x94) = uVar3;
  fVar8 = fVar7;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x70) != 0) {
    FUN_005aa3a0(&local_c,iVar5,iVar1);
    local_1c = local_c;
    local_18 = local_4;
    fVar7 = local_4;
    fVar8 = local_c;
  }
  local_c = *(float *)(in_ECX + 0x84) * fVar8;
  local_8 = fVar7 * *(float *)(in_ECX + 0x84);
  *(float *)(in_ECX + 0x88) = local_c;
  *(float *)(in_ECX + 0x8c) = local_8;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x40) != 0) {
    fVar6 = (float10)FUN_005aa2a0(iVar5,iVar1);
    *(float *)(in_ECX + 0x90) = (float)(fVar6 * (float10)_DAT_00af4c3c);
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0xb0) != 0) {
    FUN_005aa3a0(&local_1c,iVar5,iVar1);
    local_c = *(float *)(in_ECX + 0x68) + local_1c;
    local_8 = *(float *)(in_ECX + 0x6c) + local_18;
    local_4 = *(float *)(in_ECX + 0x70) + local_14;
    *(float *)(in_ECX + 0x68) = local_c;
    *(float *)(in_ECX + 0x6c) = local_8;
    *(float *)(in_ECX + 0x70) = local_4;
  }
  if (1 < *(uint *)(in_ECX + 0xec)) {
    FUN_0081d6b0(uVar4);
    uVar4 = FUN_00802534();
    *(uint *)(in_ECX + 0xc0) = uVar4;
    if (*(uint *)(in_ECX + 0xec) <= uVar4) {
      *(uint *)(in_ECX + 0xc0) = *(uint *)(in_ECX + 0xec) - 1;
    }
  }
  return;
}


// ==== FUN_005a9550 @ 0x005a9550 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005a9550(int param_1,float param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  float10 fVar4;
  
  in_ECX[2] = param_1;
  in_ECX[0x14] = *(int *)(param_1 + 8);
  *(undefined1 *)((int)in_ECX + 0x75) = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x17] = *(int *)(param_1 + 0x18);
  in_ECX[0x18] = *(int *)(param_1 + 0x1c);
  in_ECX[0x19] = *(int *)(param_1 + 0x20);
  if (*(char *)(param_1 + 0x32) != '\0') {
    fVar1 = (float)in_ECX[0x15];
    if (in_ECX[0x15] < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar4 = (float10)FUN_0040d0a0(0,fVar1 * DAT_0099d0ec);
    in_ECX[0x15] = (int)ROUND(fVar4 * (float10)DAT_009b012c);
  }
  fVar1 = (float)*(int *)(in_ECX[2] + 0xc);
  if (*(int *)(in_ECX[2] + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[0x15] = (int)ROUND(fVar1 * param_2);
  iVar2 = FUN_00802534();
  iVar3 = param_3 - in_ECX[0x15];
  in_ECX[0x1f] = iVar2;
  if (-1 < iVar3) {
    if (iVar2 <= iVar3) {
      in_ECX[0x20] = 0;
      goto LAB_005a965a;
    }
    iVar2 = iVar2 - iVar3;
  }
  in_ECX[0x20] = iVar2;
LAB_005a965a:
  in_ECX[0x16] = param_3;
  (**(code **)(*in_ECX + 0x38))();
  FUN_005a92b0(0);
  return;
}


// ==== FUN_005a9680 @ 0x005a9680 ====

void FUN_005a9680(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1764;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined1 *)((int)in_ECX + 0x75) = 0;
  in_ECX[0x16] = 0;
  return;
}


// ==== FUN_005a96c0 @ 0x005a96c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_005a96c0(void)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  int iVar8;
  float fVar9;
  float local_b4;
  float local_b0;
  float local_ac;
  undefined1 local_8c [12];
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  int local_70;
  float local_6c;
  float local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_54;
  undefined1 local_53;
  
  piVar5 = *(int **)(in_ECX + 0x9c);
  if (*piVar5 != 0) {
    piVar5 = (int *)0x0;
    if ((*(int *)(in_ECX + 0xd0) != 0) &&
       (iVar6 = *(int *)(in_ECX + 0xd4) - *(int *)(in_ECX + 0xd0),
       piVar5 = (int *)(iVar6 * 0x38e38e39), iVar6 / 0x24 != 0)) {
      local_70 = *(int *)(in_ECX + 0xc4);
      local_6c = DAT_0099d080;
      local_68 = DAT_0099d080;
      local_64 = 0xffffffff;
      local_60 = 0;
      local_53 = 0;
      if (local_70 == 0) {
        local_70 = FUN_004b3ff0(*(undefined4 *)(in_ECX + 0xc0));
      }
      local_5c = *(undefined4 *)(in_ECX + 0x78);
      local_58 = *(undefined4 *)(*(int *)(in_ECX + 0x98) + 4);
      local_54 = *(undefined1 *)(*(int *)(in_ECX + 0x98) + 0x44);
      piVar5 = (int *)0x0;
      if (*(int *)(in_ECX + 0xd0) != 0) {
        piVar5 = (int *)((*(int *)(in_ECX + 0xd4) - *(int *)(in_ECX + 0xd0)) / 0x24);
      }
      local_b4 = *(float *)(in_ECX + 0x68);
      local_b0 = *(float *)(in_ECX + 0x6c);
      local_ac = *(float *)(in_ECX + 0x70);
      if (0 < (int)piVar5) {
        piVar7 = piVar5;
        iVar6 = (int)piVar5 * 0x24;
        do {
          iVar8 = iVar6 + -0x24;
          iVar2 = *(int *)(in_ECX + 0xd0);
          if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0xd4) - iVar2) / 0x24) <= (int)piVar7 - 1U)
             ) {
                    /* WARNING: Subroutine does not return */
            FUN_0085b340();
          }
          fVar4 = (float)*(int *)(iVar6 + -0x20 + iVar2);
          if (*(int *)(iVar6 + -0x20 + iVar2) < 0) {
            fVar4 = fVar4 + _DAT_0099d104;
          }
          fVar3 = (float)*(int *)(iVar8 + iVar2);
          if (*(int *)(iVar8 + iVar2) < 0) {
            fVar3 = fVar3 + _DAT_0099d104;
          }
          fVar4 = fVar4 / fVar3;
          FUN_0040ec60(local_8c,*(undefined4 *)(iVar6 + -0x1c + iVar2));
          local_80 = local_80 * fVar4;
          pfVar1 = (float *)(iVar6 + -0xc + iVar2);
          fVar3 = SQRT((*pfVar1 - local_b4) * (*pfVar1 - local_b4) +
                       (pfVar1[1] - local_b0) * (pfVar1[1] - local_b0) +
                       (pfVar1[2] - local_ac) * (pfVar1[2] - local_ac));
          if ((*(float *)(*(int *)(in_ECX + 0x9c) + 8) < fVar3) &&
             (fVar9 = *(float *)(*(int *)(in_ECX + 0x9c) + 8), DAT_0099cdc8 < fVar9)) {
            fVar9 = fVar9 / fVar3;
            *pfVar1 = (*pfVar1 - local_b4) * fVar9 + local_b4;
            pfVar1[1] = (pfVar1[1] - local_b0) * fVar9 + local_b0;
            pfVar1[2] = (pfVar1[2] - local_ac) * fVar9 + local_ac;
          }
          local_b4 = *pfVar1;
          local_b0 = pfVar1[1];
          local_ac = pfVar1[2];
          local_7c = *pfVar1;
          local_78 = pfVar1[1];
          local_74 = pfVar1[2];
          if (*(char *)(*(int *)(in_ECX + 0x9c) + 0x10) == '\0') {
            local_6c = *(float *)(iVar6 + -0x14 + iVar2);
            local_68 = *(float *)(iVar6 + -0x10 + iVar2);
          }
          else {
            local_6c = fVar4 * *(float *)(iVar6 + -0x14 + iVar2);
            local_68 = *(float *)(iVar6 + -0x10 + iVar2) * fVar4;
          }
          local_64 = FUN_0040ead0(local_8c);
          local_60 = *(undefined4 *)(iVar6 + -0x18 + iVar2);
          piVar5 = (int *)FUN_005aaba0(&local_7c);
          piVar7 = (int *)((int)piVar7 + -1);
          iVar6 = iVar8;
        } while (0 < (int)piVar7);
      }
    }
  }
  return piVar5;
}


// ==== FUN_005a99e0 @ 0x005a99e0 ====

void FUN_005a99e0(int param_1)

{
  uint *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int in_ECX;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar5 = 0;
  if (*(int *)(in_ECX + 0xd0) != 0) {
    uVar5 = (*(int *)(in_ECX + 0xd4) - *(int *)(in_ECX + 0xd0)) / 0x24;
  }
  puVar1 = *(uint **)(in_ECX + 0x9c);
  if (((uVar5 < *puVar1) &&
      (*(int *)(in_ECX + 0xe8) = *(int *)(in_ECX + 0xe8) + param_1,
      puVar1[1] <= *(uint *)(in_ECX + 0xe8))) &&
     (((float)puVar1[2] <= DAT_0099cdc8 ||
      (fVar2 = *(float *)(in_ECX + 0x68) - *(float *)(in_ECX + 0xdc),
      fVar3 = *(float *)(in_ECX + 0x6c) - *(float *)(in_ECX + 0xe0),
      fVar4 = *(float *)(in_ECX + 0x70) - *(float *)(in_ECX + 0xe4),
      (float)puVar1[2] <= SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4))))) {
    local_24 = puVar1[3];
    local_14 = *(undefined4 *)(in_ECX + 0x88);
    local_18 = *(undefined4 *)(in_ECX + 0x90);
    local_10 = *(undefined4 *)(in_ECX + 0x8c);
    local_1c = *(undefined4 *)(in_ECX + 0x94);
    local_c = *(undefined4 *)(in_ECX + 0x68);
    local_8 = *(undefined4 *)(in_ECX + 0x6c);
    local_4 = *(undefined4 *)(in_ECX + 0x70);
    local_20 = local_24;
    FUN_005aac30(&local_24);
    *(undefined4 *)(in_ECX + 0xdc) = *(undefined4 *)(in_ECX + 0x68);
    *(undefined4 *)(in_ECX + 0xe0) = *(undefined4 *)(in_ECX + 0x6c);
    *(undefined4 *)(in_ECX + 0xe4) = *(undefined4 *)(in_ECX + 0x70);
    *(undefined4 *)(in_ECX + 0xe8) = 0;
  }
  return;
}


// ==== FUN_005a9b00 @ 0x005a9b00 ====

void FUN_005a9b00(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  undefined4 *unaff_retaddr;
  undefined4 uStack_88;
  undefined1 local_7c [4];
  undefined4 uStack_78;
  undefined4 uStack_74;
  int local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_54;
  undefined1 local_53;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 *puStack_4;
  
  if (*(uint *)(in_ECX + 0x54) <= *(uint *)(in_ECX + 0x58)) {
    cVar1 = FUN_005a90a0();
    if (cVar1 != '\0') {
      local_5c = *(undefined4 *)(in_ECX + 0x78);
      local_6c = DAT_0099d080;
      local_68 = DAT_0099d080;
      local_64 = 0xffffffff;
      local_60 = 0;
      local_54 = 0;
      local_53 = 0;
      local_58 = *(undefined4 *)(*(int *)(in_ECX + 0x98) + 4);
      local_70 = *(int *)(in_ECX + 0xc4);
      if (local_70 == 0) {
        uStack_88 = 0x5a9b7e;
        local_70 = FUN_004b3ff0();
      }
      uStack_88 = param_1;
      thunk_FUN_0079e5a0(local_7c,in_ECX + 0x68);
      local_70 = *(undefined4 *)(in_ECX + 0x94);
      uStack_78 = *(undefined4 *)(in_ECX + 0x88);
      uStack_74 = *(undefined4 *)(in_ECX + 0x8c);
      local_6c = *(undefined4 *)(in_ECX + 0x90);
      uStack_1c = *puStack_4;
      uStack_18 = puStack_4[1];
      uStack_14 = *unaff_retaddr;
      uStack_10 = unaff_retaddr[1];
      local_60 = CONCAT31(local_60._1_3_,*(undefined1 *)(*(int *)(in_ECX + 0x98) + 0x44));
      FUN_005aaba0(&uStack_88);
      FUN_005a96c0(param_1);
    }
  }
  return;
}


// ==== FUN_005a9c20 @ 0x005a9c20 ====

void FUN_005a9c20(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (((*(int *)(in_ECX + 0xd0) != 0) &&
      ((*(int *)(in_ECX + 0xd4) - *(int *)(in_ECX + 0xd0)) / 0x24 != 0)) &&
     (puVar6 = *(undefined4 **)(in_ECX + 0xd0), puVar6 != *(undefined4 **)(in_ECX + 0xd4))) {
    do {
      if ((uint)puVar6[1] < param_1) {
        puVar1 = *(undefined4 **)(in_ECX + 0xd4);
        if (puVar6 + 9 != puVar1) {
          puVar2 = puVar6 + 9;
          puVar5 = puVar6;
          do {
            puVar3 = puVar2 + 9;
            puVar7 = puVar5;
            for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar7 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar2 = puVar3;
            puVar5 = puVar5 + 9;
          } while (puVar3 != puVar1);
        }
        *(int *)(in_ECX + 0xd4) = *(int *)(in_ECX + 0xd4) + -0x24;
      }
      else {
        puVar6[1] = puVar6[1] - param_1;
        puVar6 = puVar6 + 9;
      }
    } while (puVar6 != *(undefined4 **)(in_ECX + 0xd4));
  }
  FUN_005a99e0();
  return;
}


// ==== FUN_005a9cc0 @ 0x005a9cc0 ====

void FUN_005a9cc0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_005a9b00(param_2,param_3,param_4,param_1 + 0x60);
  return;
}


// ==== FUN_005a9ce0 @ 0x005a9ce0 ====

void FUN_005a9ce0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_005a9b00(param_2,param_3,param_4,param_1 + 100);
  return;
}


// ==== FUN_005a9d00 @ 0x005a9d00 ====

uint FUN_005a9d00(int param_1)

{
  uint in_EAX;
  int *in_ECX;
  
  if (in_ECX[0x20] == 0) {
    *(undefined1 *)((int)in_ECX + 0x75) = 1;
    return in_EAX & 0xffffff00;
  }
  in_ECX[0x16] = in_ECX[0x16] + param_1;
  if ((uint)in_ECX[0x16] < (uint)in_ECX[0x15]) {
    return CONCAT31((int3)((uint)in_ECX[0x16] >> 8),1);
  }
  (**(code **)(*in_ECX + 0x38))();
  FUN_005a92b0(param_1);
  if (*(int *)in_ECX[0x27] != 0) {
    FUN_005a9c20(param_1);
  }
  return (uint)(*(char *)((int)in_ECX + 0x75) == '\0');
}


// ==== FUN_005a9d60 @ 0x005a9d60 ====

int FUN_005a9d60(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x7c;
}


// ==== FUN_005a9d90 @ 0x005a9d90 ====

void FUN_005a9d90(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 0x1f;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 0x1f; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_005a9dc0 @ 0x005a9dc0 ====

void FUN_005a9dc0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -0x1f;
    param_3 = param_3 + -0x1f;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_005a9df0 @ 0x005a9df0 ====

undefined4 * FUN_005a9df0(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar2[1] + 0x19) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if (((int)puVar2[3] < *param_1) && ((int)puVar2[4] <= param_1[1])) {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x19) == '\0');
  }
  return puVar2;
}


// ==== FUN_005a9e30 @ 0x005a9e30 ====

undefined4 * FUN_005a9e30(int *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar2[1] + 0x21) == '\0') {
    puVar1 = puVar2;
    puVar3 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar3;
      if (((int)puVar2[3] < *param_1) && ((int)puVar2[4] <= param_1[1])) {
        puVar3 = (undefined4 *)puVar2[2];
        puVar2 = puVar1;
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar3 + 0x21) == '\0');
  }
  return puVar2;
}


// ==== FUN_005a9e70 @ 0x005a9e70 ====

void FUN_005a9e70(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (iVar1 = 0x1f; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_005a9e90 @ 0x005a9e90 ====

int FUN_005a9e90(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982780;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x7c) {
    FUN_005a9e70(param_3,param_1);
    param_3 = param_3 + 0x7c;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005a9ef6 @ 0x005a9ef6 ====

void Catch_005a9ef6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005a9f00 @ 0x005a9f00 ====

int FUN_005a9f00(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982790;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x24) {
    FUN_00868690(param_3,param_1);
    param_3 = param_3 + 0x24;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005a9f66 @ 0x005a9f66 ====

void Catch_005a9f66(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005a9f70 @ 0x005a9f70 ====

void FUN_005a9f70(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009827a0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005a9e70(param_1,param_3);
    param_1 = param_1 + 0x7c;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005a9fd6 @ 0x005a9fd6 ====

void Catch_005a9fd6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005a9fe0 @ 0x005a9fe0 ====

void FUN_005a9fe0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009827b0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00868690(param_1,param_3);
    param_1 = param_1 + 0x24;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005aa046 @ 0x005aa046 ====

void Catch_005aa046(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005aa050 @ 0x005aa050 ====

void FUN_005aa050(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005a9e90(param_1,param_2,param_3);
  return;
}


// ==== FUN_005aa070 @ 0x005aa070 ====

void FUN_005aa070(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005a9f00(param_1,param_2,param_3);
  return;
}


// ==== FUN_005aa090 @ 0x005aa090 ====

void FUN_005aa090(int *param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_005a9df0(param_2);
  if ((iVar1 == *(int *)(in_ECX + 4)) ||
     ((*param_2 < *(int *)(iVar1 + 0xc) && (param_2[1] <= *(int *)(iVar1 + 0x10))))) {
    *param_1 = *(int *)(in_ECX + 4);
    return;
  }
  *param_1 = iVar1;
  return;
}


// ==== FUN_005aa0f0 @ 0x005aa0f0 ====

void FUN_005aa0f0(int *param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_005a9e30(param_2);
  if ((iVar1 == *(int *)(in_ECX + 4)) ||
     ((*param_2 < *(int *)(iVar1 + 0xc) && (param_2[1] <= *(int *)(iVar1 + 0x10))))) {
    *param_1 = *(int *)(in_ECX + 4);
    return;
  }
  *param_1 = iVar1;
  return;
}


// ==== FUN_005aa150 @ 0x005aa150 ====

int FUN_005aa150(int param_1,int param_2,undefined4 param_3)

{
  FUN_005a9f70(param_1,param_2,param_3);
  return param_1 + param_2 * 0x7c;
}


// ==== FUN_005aa180 @ 0x005aa180 ====

int FUN_005aa180(int param_1,int param_2,undefined4 param_3)

{
  FUN_005a9fe0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_005aa1b0 @ 0x005aa1b0 ====

undefined4 FUN_005aa1b0(undefined4 param_1)

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
  local_8 = 0xf;
  local_c = 0;
  local_1c = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  uVar2 = (**(code **)(*piVar1 + 0xc))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_005aa220 @ 0x005aa220 ====

undefined4 FUN_005aa220(undefined4 param_1)

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
  local_4 = 0x10;
  uVar2 = (**(code **)(*piVar1 + 0xc))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_005aa280 @ 0x005aa280 ====

void FUN_005aa280(byte param_1)

{
  void *in_ECX;
  
  FUN_005a9100();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005aa2a0 @ 0x005aa2a0 ====

float10 FUN_005aa2a0(int param_1,int param_2)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  float *pfVar5;
  float10 extraout_ST0;
  float10 fVar6;
  int local_24;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 8) == 1) {
    return (float10)*(float *)(in_ECX + 0x14);
  }
  iVar4 = param_1;
  if (*(int *)(in_ECX + 0xc) != 0) {
    iVar4 = param_2;
  }
  if (*(int *)(in_ECX + 0x10) <= iVar4) {
    iVar4 = iVar4 % *(int *)(in_ECX + 0x10);
  }
  local_24 = iVar4;
  local_20 = iVar4;
  FUN_005aa090(&param_1,&local_24);
  iVar3 = param_1;
  if (param_1 == *(int *)(in_ECX + 4)) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_citKeyVariable____mapVariable_en_009c16d0,0x23);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar2 = (code *)swi(3);
      fVar6 = (float10)(*pcVar2)();
      return fVar6;
    }
    _free(local_18);
    return extraout_ST0;
  }
  piVar1 = (int *)(param_1 + 0xc);
  pfVar5 = (float *)(param_1 + 0x14);
  FUN_00832d10();
  if (param_1 == *(int *)(in_ECX + 4)) {
    return (float10)*pfVar5;
  }
  fVar6 = (float10)(iVar4 - *piVar1) / (float10)(*(int *)(iVar3 + 0x10) - *piVar1);
  return fVar6 * (float10)*(float *)(param_1 + 0x14) +
         ((float10)DAT_0099d080 - fVar6) * (float10)*pfVar5;
}


// ==== FUN_005aa3a0 @ 0x005aa3a0 ====

void FUN_005aa3a0(float *param_1,int param_2,int param_3)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  code *pcVar6;
  int iVar7;
  int in_ECX;
  int iVar8;
  float *pfVar9;
  float fVar10;
  float fVar11;
  int local_24;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 8) == 1) {
    *param_1 = *(float *)(in_ECX + 0x14);
    param_1[1] = *(float *)(in_ECX + 0x18);
    param_1[2] = *(float *)(in_ECX + 0x1c);
    return;
  }
  iVar8 = param_2;
  if (*(int *)(in_ECX + 0xc) != 0) {
    iVar8 = param_3;
  }
  if (*(int *)(in_ECX + 0x10) <= iVar8) {
    iVar8 = iVar8 % *(int *)(in_ECX + 0x10);
  }
  local_24 = iVar8;
  local_20 = iVar8;
  FUN_005aa0f0(&param_2,&local_24);
  iVar7 = param_2;
  if (param_2 == *(int *)(in_ECX + 4)) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_citKeyVariable____mapVariable_en_009c16f4,0x23);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar6 = (code *)swi(3);
      (*pcVar6)();
      return;
    }
    _free(local_18);
    return;
  }
  piVar1 = (int *)(param_2 + 0xc);
  pfVar9 = (float *)(param_2 + 0x14);
  FUN_004dde50();
  if (param_2 == *(int *)(in_ECX + 4)) {
    *param_1 = *pfVar9;
    param_1[1] = *(float *)(iVar7 + 0x18);
    param_1[2] = *(float *)(iVar7 + 0x1c);
    return;
  }
  fVar2 = *(float *)(param_2 + 0x18);
  fVar3 = *(float *)(param_2 + 0x1c);
  fVar4 = *(float *)(iVar7 + 0x18);
  fVar5 = *(float *)(iVar7 + 0x1c);
  fVar10 = (float)(iVar8 - *piVar1) / (float)(*(int *)(iVar7 + 0x10) - *piVar1);
  fVar11 = DAT_0099d080 - fVar10;
  *param_1 = *pfVar9 * fVar11 + *(float *)(param_2 + 0x14) * fVar10;
  param_1[1] = fVar4 * fVar11 + fVar2 * fVar10;
  param_1[2] = fVar5 * fVar11 + fVar3 * fVar10;
  return;
}


// ==== FUN_005aa510 @ 0x005aa510 ====

void FUN_005aa510(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  uint extraout_ECX;
  undefined4 *puVar3;
  undefined4 local_b0;
  uint local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  void *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009827c0;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0xbc);
  puVar3 = &local_b0;
  for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    local_2c = 0;
  }
  else {
    local_2c = (*(int *)(in_ECX + 0xc) - iVar2) / 0x7c;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x7c;
    }
    ExceptionList = &local_10;
    if (0x2108421U - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_2c = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x7c;
    }
    if (local_2c < iVar2 + param_2) {
      if (0x2108421 - (local_2c >> 1) < local_2c) {
        local_2c = 0;
      }
      else {
        local_2c = local_2c + (local_2c >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x7c;
      }
      if (local_2c < iVar2 + param_2) {
        iVar2 = FUN_005a9d60();
        local_2c = iVar2 + param_2;
      }
      local_2c = local_2c * 0x7c;
      local_1c = operator_new(local_2c);
      local_8 = 0;
      local_28 = FUN_005aa050(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_28 = FUN_005aa150(local_28,param_2,&local_b0);
      FUN_005aa050(param_1,*(undefined4 *)(in_ECX + 8),local_28);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x7c;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_2c + (int)local_1c;
        *(void **)(in_ECX + 8) = (void *)((int)local_1c + (param_2 + iVar2) * 0x7c);
        *(void **)(in_ECX + 4) = local_1c;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_24 = *(int *)(in_ECX + 8);
    local_20 = local_24 - param_1;
    if ((uint)(local_20 / 0x7c) < param_2) {
      local_18 = param_2 * 0x7c;
      FUN_005a9e90(param_1,local_24,local_18 + param_1);
      local_8 = 2;
      FUN_005aa150(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x7c,
                   &local_b0);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_005a9d90(param_1,*(int *)(in_ECX + 8) - local_18,&local_b0);
      ExceptionList = local_10;
      return;
    }
    local_18 = param_2 * 0x7c;
    iVar2 = local_24 + param_2 * -0x7c;
    uVar1 = FUN_005a9e90(iVar2,local_24,local_24);
    *(undefined4 *)(in_ECX + 8) = uVar1;
    FUN_005a9dc0(param_1,iVar2,local_24);
    FUN_005a9d90(param_1,local_18 + param_1,&local_b0);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005aa6d8 @ 0x005aa6d8 ====

void Catch_005aa6d8(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005aa800 @ 0x005aa800 ====

void FUN_005aa800(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  uint extraout_ECX;
  undefined4 *puVar4;
  undefined4 local_58;
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
  puStack_c = &LAB_009827d0;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -100);
  puVar4 = &local_58;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_3;
    param_3 = param_3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x24;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
    }
    ExceptionList = &local_10;
    if (0x71c71c7U - iVar1 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_20 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
    }
    if (local_20 < iVar1 + param_2) {
      if (0x71c71c7 - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_0066e7e0();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0x24;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_005aa070(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_005aa180(local_1c,param_2,&local_58);
      FUN_005aa070(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x24;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0x24);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0x24) < param_2) {
      local_24 = param_2 * 0x24;
      FUN_005a9f00(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_005aa180(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,&local_58)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_008684a0(param_1,*(int *)(in_ECX + 8) - local_24,&local_58);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x24;
    uVar2 = FUN_005a9f00(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    FUN_004ab860(param_1,local_2c,local_28);
    FUN_008684a0(param_1,param_2 * 0x24 + param_1,&local_58);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005aa9a6 @ 0x005aa9a6 ====

void Catch_005aa9a6(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005aaab0 @ 0x005aaab0 ====

void FUN_005aaab0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x7c != 0) {
      iVar1 = (param_2 - iVar1) / 0x7c;
      goto LAB_005aaaf9;
    }
  }
  iVar1 = 0;
LAB_005aaaf9:
  FUN_005aa510(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x7c;
  return;
}


// ==== FUN_005aab30 @ 0x005aab30 ====

void FUN_005aab30(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x24 != 0) {
      iVar1 = (param_2 - iVar1) / 0x24;
      goto LAB_005aab75;
    }
  }
  iVar1 = 0;
LAB_005aab75:
  FUN_005aa800(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x24;
  return;
}


// ==== FUN_005aaba0 @ 0x005aaba0 ====

void FUN_005aaba0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x7c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x7c))) {
    FUN_005aaab0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005a9f70(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x7c;
  return;
}


// ==== FUN_005aac30 @ 0x005aac30 ====

void FUN_005aac30(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x24) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x24))) {
    FUN_005aab30(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005a9fe0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x24;
  return;
}


// ==== FUN_005aacc0 @ 0x005aacc0 ====

void FUN_005aacc0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  return;
}


// ==== FUN_005aacd0 @ 0x005aacd0 ====

void FUN_005aacd0(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float fVar7;
  
  iVar4 = *(int *)(in_ECX + 0xf4);
  fVar1 = *(float *)(iVar4 + 0x5c);
  fVar2 = *(float *)(iVar4 + 0x60);
  fVar3 = *param_1;
  fVar7 = DAT_0099d080 - *param_1;
  *(float *)(param_2 + 0xc) = *(float *)(param_2 + 0xb4) * fVar7 + *(float *)(iVar4 + 0x58) * fVar3;
  *(float *)(param_2 + 0x10) = *(float *)(param_2 + 0xb8) * fVar7 + fVar1 * fVar3;
  *(float *)(param_2 + 0x14) = *(float *)(param_2 + 0xbc) * fVar7 + fVar2 * fVar3;
  puVar5 = (undefined4 *)(in_ECX + 0x148);
  puVar6 = (undefined4 *)(param_2 + 0xdc);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  return;
}


// ==== FUN_005aadc0 @ 0x005aadc0 ====

undefined4 FUN_005aadc0(void)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x1c8) != '\x01') {
    if (*(int **)(in_ECX + 0x78) == (int *)0x0) {
      cVar1 = (**(code **)(**(int **)(in_ECX + 0x7c) + 0x2c))();
      if (cVar1 == '\0') {
        return 0;
      }
      uVar2 = FUN_004b3b40();
      *(undefined4 *)(in_ECX + 0x80) = uVar2;
    }
    else {
      cVar1 = (**(code **)(**(int **)(in_ECX + 0x78) + 0x2c))();
      if (cVar1 == '\0') {
        return 0;
      }
    }
    *(undefined1 *)(in_ECX + 0x1c8) = 1;
  }
  return 1;
}


// ==== FUN_005aae10 @ 0x005aae10 ====

void FUN_005aae10(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xec) = 0;
  *(undefined4 *)(in_ECX + 0xe8) = 0;
  *(undefined4 *)(in_ECX + 0xe4) = 0;
  *(undefined4 *)(in_ECX + 0xe0) = 0;
  *(undefined4 *)(in_ECX + 0xd8) = 0;
  *(undefined4 *)(in_ECX + 0xd4) = 0;
  *(undefined4 *)(in_ECX + 0xd0) = 0;
  *(undefined4 *)(in_ECX + 0xcc) = 0;
  *(undefined4 *)(in_ECX + 0xc4) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = 0;
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  uVar2 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0xf0) = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0xdc) = uVar2;
  *(undefined4 *)(in_ECX + 200) = uVar2;
  *(undefined4 *)(in_ECX + 0xb4) = uVar2;
  *(undefined4 *)(in_ECX + 0x9c) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xa4) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x40);
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  iVar1 = *(int *)(param_1 + 0x24);
  *(int *)(in_ECX + 0xf4) = iVar1;
  *(float *)(in_ECX + 0x120) =
       SQRT(*(float *)(iVar1 + 0x48) * *(float *)(iVar1 + 0x48) +
            *(float *)(iVar1 + 0x44) * *(float *)(iVar1 + 0x44) +
            *(float *)(iVar1 + 0x40) * *(float *)(iVar1 + 0x40));
  return;
}


// ==== FUN_005aaf00 @ 0x005aaf00 ====

void FUN_005aaf00(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x75) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x124) = 0;
  *(undefined4 *)(in_ECX + 0x128) = 0;
  *(undefined4 *)(in_ECX + 300) = 0;
  *(undefined4 *)(in_ECX + 0x11c) = *(undefined4 *)(in_ECX + 0x118);
  return;
}


// ==== FUN_005aaf50 @ 0x005aaf50 ====

void FUN_005aaf50(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_40 [6];
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
  
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  local_1c = 0;
  local_20 = 0;
  local_24 = 0;
  local_28 = 0;
  local_40[4] = 0;
  local_40[3] = 0;
  local_40[2] = 0;
  local_40[1] = 0;
  local_4 = DAT_0099d080;
  local_18 = DAT_0099d080;
  local_40[5] = DAT_0099d080;
  local_40[0] = DAT_0099d080;
  puVar2 = local_40;
  puVar3 = (undefined4 *)(in_ECX + 0xb4);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = local_40;
  puVar3 = (undefined4 *)(in_ECX + 0x188);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(in_ECX + 0x5c);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(in_ECX + 0x60);
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(in_ECX + 100);
  *(undefined4 *)(in_ECX + 0x1c0) = 0;
  *(undefined4 *)(in_ECX + 0x1bc) = 0;
  *(undefined4 *)(in_ECX + 0x1b8) = 0;
  if (*(int *)(*(int *)(in_ECX + 0xf4) + 4) == 3) {
    *(undefined4 *)(in_ECX + 0x13c) = *(undefined4 *)(in_ECX + 0x5c);
    *(undefined4 *)(in_ECX + 0x140) = *(undefined4 *)(in_ECX + 0x60);
    *(undefined4 *)(in_ECX + 0x144) = *(undefined4 *)(in_ECX + 100);
  }
  return;
}


// ==== FUN_005ab040 @ 0x005ab040 ====

void FUN_005ab040(int param_1,undefined4 param_2,float *param_3,float *param_4,float *param_5)

{
  float fVar1;
  int in_ECX;
  int iVar2;
  float unaff_EBX;
  float unaff_ESI;
  float *pfVar3;
  float unaff_EDI;
  float *pfVar4;
  float local_1c;
  float local_18;
  float fStack_14;
  undefined4 uStack_10;
  
  fVar1 = *(float *)(in_ECX + 0x78);
  if (fVar1 == 0.0) {
    if (*(int *)(in_ECX + 0x80) == 0) {
      param_5[3] = 0.0;
      goto LAB_005ab07c;
    }
    fVar1 = (float)FUN_004b3ff0(*(undefined4 *)(param_1 + 0x38));
  }
  param_5[3] = fVar1;
LAB_005ab07c:
  param_5[9] = *(float *)(in_ECX + 0x98);
  param_5[8] = *(float *)(in_ECX + 0x88);
  param_5[6] = *(float *)(param_1 + 0x34);
  param_5[7] = *(float *)(param_1 + 0x24);
  param_5[0x1b] = *param_3;
  param_5[0x1c] = param_3[1];
  param_5[0x1d] = *param_4;
  param_5[0x1e] = param_4[1];
  fVar1 = *(float *)(param_1 + 0x2c);
  local_18 = *(float *)(param_1 + 0x20);
  local_1c = fVar1 * *(float *)(param_1 + 0x18);
  param_5[4] = local_1c;
  local_18 = local_18 * fVar1;
  param_5[5] = local_18;
  thunk_FUN_0079e5a0(param_5,param_1 + 0xc,param_2);
  if (*(char *)(param_1 + 0xa0) != '\0') {
    local_1c = *param_5;
    local_18 = param_5[1];
    fStack_14 = param_5[2];
    uStack_10 = DAT_0099d080;
    thunk_FUN_0079ebf5(&local_1c,&local_1c,param_1 + 0xdc);
    *param_5 = unaff_EDI;
    param_5[1] = unaff_ESI;
    param_5[2] = unaff_EBX;
  }
  pfVar3 = (float *)(param_1 + 0x40);
  pfVar4 = param_5 + 0xb;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *pfVar4 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    pfVar4 = pfVar4 + 1;
  }
  return;
}


// ==== FUN_005ab1a0 @ 0x005ab1a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ab1a0(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  undefined4 uVar6;
  float *pfVar7;
  int in_ECX;
  float10 fVar8;
  float local_18;
  float local_14;
  float local_10;
  undefined1 local_c [12];
  
  if (((*(float *)(in_ECX + 0x124) != 0.0) || (*(float *)(in_ECX + 0x128) != 0.0)) ||
     (*(float *)(in_ECX + 300) != 0.0)) {
    fVar1 = *(float *)(in_ECX + 0x120);
    local_18 = *(float *)(in_ECX + 0x124) * fVar1;
    local_14 = *(float *)(in_ECX + 0x128) * fVar1;
    local_10 = *(float *)(in_ECX + 300);
    *(float *)(param_1 + 0xc4) = local_18;
    local_10 = local_10 * fVar1;
    *(float *)(param_1 + 200) = local_14;
    *(float *)(param_1 + 0xcc) = local_10;
  }
  pfVar7 = (float *)(param_1 + 0xc);
  *pfVar7 = *(float *)(in_ECX + 0x68);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(in_ECX + 0x6c);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(in_ECX + 0x70);
  if (((param_2 == 1) || (param_2 == 5)) || ((param_2 == 7 || (param_2 == 6)))) {
    fVar8 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x28),
                                  *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x24));
    fVar3 = (float)fVar8;
    pfVar5 = (float *)FUN_0040ecc0(local_c);
    fVar1 = *pfVar5;
    fVar2 = pfVar5[2];
    *(float *)(param_1 + 0x10) = *(float *)(param_1 + 0x10) + pfVar5[1] * fVar3;
    *pfVar7 = *pfVar7 + fVar1 * fVar3;
    *(float *)(param_1 + 0x14) = *(float *)(param_1 + 0x14) + fVar2 * fVar3;
    if ((param_2 == 5) || (param_2 == 6)) {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(in_ECX + 0x6c);
    }
  }
  iVar4 = *(int *)(in_ECX + 0xf4);
  fVar1 = (float)*(int *)(iVar4 + 0xc);
  if (*(int *)(iVar4 + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar2 = (float)*(int *)(iVar4 + 0x10);
  if (*(int *)(iVar4 + 0x10) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  FUN_0040d0a0(fVar2,fVar1);
  uVar6 = FUN_00802534();
  local_18 = *(float *)(param_1 + 0xc4);
  *(undefined4 *)(param_1 + 0xa4) = uVar6;
  *(undefined4 *)(param_1 + 0xa8) = uVar6;
  local_14 = *(float *)(param_1 + 200);
  local_10 = *(float *)(param_1 + 0xcc);
  if (((param_2 == 2) || (param_2 == 7)) || (param_2 == 6)) {
    pfVar7 = (float *)FUN_0040ecc0(local_c);
    local_18 = *pfVar7 + local_18;
    local_14 = pfVar7[1] + local_14;
    local_10 = pfVar7[2] + local_10;
  }
  if (_DAT_009c1830 < local_10 * local_10 + local_14 * local_14 + local_18 * local_18) {
    thunk_FUN_0079e1ba(&local_18,&local_18);
  }
  if (*(char *)(*(int *)(in_ECX + 0xf4) + 10) == '\0') {
    thunk_FUN_0079e6b3((float *)(param_1 + 0xc4),&local_18,in_ECX + 0xb4);
  }
  fVar8 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x30),
                                *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x2c));
  *(float *)(param_1 + 0xc0) = (float)fVar8;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  return;
}


// ==== FUN_005ab460 @ 0x005ab460 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ab460(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  undefined4 uVar5;
  int in_ECX;
  float10 fVar6;
  undefined4 local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  *(float *)(param_1 + 0xc) = *(float *)(in_ECX + 0x68);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(in_ECX + 0x6c);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(in_ECX + 0x70);
  fVar6 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x28),
                                *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x24));
  fVar2 = (float)fVar6;
  *(float *)(param_1 + 0xb0) = (float)fVar6;
  pfVar4 = (float *)FUN_0040ecc0(&local_c);
  fVar1 = pfVar4[2];
  local_c = *(float *)(in_ECX + 0x68) + *pfVar4 * fVar2;
  local_8 = *(float *)(in_ECX + 0x6c) + pfVar4[1] * fVar2;
  local_4 = *(float *)(in_ECX + 0x70);
  *(float *)(param_1 + 0xc) = local_c;
  *(float *)(param_1 + 0x10) = local_8;
  local_4 = local_4 + fVar1 * fVar2;
  *(float *)(param_1 + 0x14) = local_4;
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(in_ECX + 0x6c);
  iVar3 = *(int *)(in_ECX + 0xf4);
  fVar1 = (float)*(int *)(iVar3 + 0xc);
  if (*(int *)(iVar3 + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar2 = (float)*(int *)(iVar3 + 0x10);
  if (*(int *)(iVar3 + 0x10) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  FUN_0040d0a0(fVar2,fVar1);
  uVar5 = FUN_00802534();
  *(undefined4 *)(param_1 + 0xa4) = uVar5;
  *(undefined4 *)(param_1 + 0xa8) = uVar5;
  if (((*(float *)(in_ECX + 0x124) != 0.0) || (*(float *)(in_ECX + 0x128) != 0.0)) ||
     (*(float *)(in_ECX + 300) != 0.0)) {
    fVar1 = *(float *)(in_ECX + 0x120);
    local_c = *(float *)(in_ECX + 0x124) * fVar1;
    local_8 = *(float *)(in_ECX + 0x128) * fVar1;
    local_4 = *(float *)(in_ECX + 300);
    *(float *)(param_1 + 0xc4) = local_c;
    local_4 = local_4 * fVar1;
    *(float *)(param_1 + 200) = local_8;
    *(float *)(param_1 + 0xcc) = local_4;
  }
  pfVar4 = (float *)FUN_0040ecc0(&local_c);
  local_14 = pfVar4[1] + *(float *)(param_1 + 200);
  local_10 = pfVar4[2] + *(float *)(param_1 + 0xcc);
  local_18 = *pfVar4 + *(float *)(param_1 + 0xc4);
  if (_DAT_009c1830 < local_14 * local_14 + local_10 * local_10 + local_18 * local_18) {
    thunk_FUN_0079e1ba(&local_18,&local_18);
  }
  thunk_FUN_0079e1ba(&local_18,&local_18);
  local_10 = 0.0;
  local_c = local_18;
  if (*(char *)(*(int *)(in_ECX + 0xf4) + 10) == '\0') {
    thunk_FUN_0079e6b3(param_1 + 0xc4,(int)register0x00000010 + -0x20,in_ECX + 0xb4);
  }
  fVar6 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x30),
                                *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x2c));
  *(float *)(param_1 + 0xc0) = (float)fVar6;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  return;
}


// ==== FUN_005ab740 @ 0x005ab740 ====

void FUN_005ab740(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  undefined4 uVar5;
  int in_ECX;
  float10 fVar6;
  undefined1 local_c [12];
  
  fVar6 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x30),
                                *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x2c));
  *(float *)(param_1 + 0xac) = (float)fVar6;
  fVar6 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x28),
                                *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x24));
  fVar3 = (float)fVar6;
  *(float *)(param_1 + 0xb0) = (float)fVar6;
  pfVar4 = (float *)FUN_0040ecc0(local_c);
  fVar1 = pfVar4[1];
  fVar2 = pfVar4[2];
  *(float *)(param_1 + 0xc) = *pfVar4 * fVar3;
  *(float *)(param_1 + 0x10) = fVar1 * fVar3;
  *(float *)(param_1 + 0x14) = fVar2 * fVar3;
  fVar1 = *(float *)(in_ECX + 0x140);
  fVar2 = *(float *)(in_ECX + 0x144);
  *(float *)(param_1 + 0xb4) = *(float *)(in_ECX + 0x13c) + *(float *)(param_1 + 0xc);
  *(float *)(param_1 + 0xb8) = fVar1 + *(float *)(param_1 + 0x10);
  *(float *)(param_1 + 0xbc) = fVar2 + *(float *)(param_1 + 0x14);
  uVar5 = FUN_00802534();
  *(undefined4 *)(param_1 + 0xa4) = uVar5;
  *(undefined4 *)(param_1 + 0xa8) = uVar5;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined4 *)(param_1 + 200) = 0;
  *(undefined1 *)(param_1 + 0xa0) = 1;
  *(undefined4 *)(param_1 + 0xcc) = 0;
  return;
}


// ==== FUN_005ab8a0 @ 0x005ab8a0 ====

void FUN_005ab8a0(float *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int in_ECX;
  float fVar3;
  float fVar4;
  
  fVar3 = *(float *)(param_2 + 0xc0) - *(float *)(*(int *)(in_ECX + 0xf4) + 0x34) * *param_1;
  if (fVar3 < 0.0) {
    fVar3 = 0.0;
  }
  *(float *)(param_2 + 0xc0) = fVar3;
  iVar2 = *(int *)(in_ECX + 0xf4);
  fVar3 = *param_1;
  fVar4 = *(float *)(iVar2 + 0x50);
  fVar1 = *(float *)(iVar2 + 0x54);
  *(float *)(param_2 + 0xd0) = *(float *)(param_2 + 0xd0) + *(float *)(iVar2 + 0x4c) * fVar3;
  *(float *)(param_2 + 0xd4) = *(float *)(param_2 + 0xd4) + fVar4 * fVar3;
  *(float *)(param_2 + 0xd8) = *(float *)(param_2 + 0xd8) + fVar1 * fVar3;
  fVar4 = *param_1 * *(float *)(param_2 + 0xc0);
  fVar3 = *param_1;
  *(float *)(param_2 + 0xc) =
       *(float *)(param_2 + 0xc) + *(float *)(param_2 + 0xc4) * fVar4 +
       *(float *)(param_2 + 0xd0) * fVar3;
  *(float *)(param_2 + 0x10) =
       *(float *)(param_2 + 0x10) + *(float *)(param_2 + 200) * fVar4 +
       *(float *)(param_2 + 0xd4) * fVar3;
  *(float *)(param_2 + 0x14) =
       *(float *)(param_2 + 0x14) + *(float *)(param_2 + 0xcc) * fVar4 +
       *(float *)(param_2 + 0xd8) * fVar3;
  return;
}


// ==== FUN_005ab9f0 @ 0x005ab9f0 ====

void FUN_005ab9f0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  int in_ECX;
  
  if (*(void **)(in_ECX + 0xf8) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0xf8));
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x10c);
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 0x10c) + 4) = *(int *)(in_ECX + 0x10c);
  *(undefined4 *)(in_ECX + 0x110) = 0;
  if (pvVar2 != *(void **)(in_ECX + 0x10c)) {
    _free(pvVar2);
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x100);
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 0x100) + 4) = *(int *)(in_ECX + 0x100);
  *(undefined4 *)(in_ECX + 0x104) = 0;
  if (pvVar2 == *(void **)(in_ECX + 0x100)) {
    return;
  }
  _free(pvVar2);
  return;
}


// ==== FUN_005aba90 @ 0x005aba90 ====

void FUN_005aba90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c183c;
  if (in_ECX[0x1f] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x1f]);
    in_ECX[0x1f] = 0;
  }
  if (in_ECX[0x1e] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x1e]);
    in_ECX[0x1e] = 0;
  }
  FUN_005ab9f0();
  FUN_008984a0();
  FUN_008984a0();
  *in_ECX = &PTR_FUN_009c1724;
  return;
}


// ==== FUN_005abb00 @ 0x005abb00 ====

void FUN_005abb00(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c183c;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x3e] = 0;
  uVar1 = FUN_005ace10();
  in_ECX[0x40] = uVar1;
  in_ECX[0x41] = 0;
  uVar1 = FUN_005ace10();
  in_ECX[0x43] = uVar1;
  in_ECX[0x44] = 0;
  in_ECX[0x49] = 0;
  in_ECX[0x4a] = 0;
  in_ECX[0x45] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x16] = 0;
  *(undefined1 *)((int)in_ECX + 0x75) = 0;
  in_ECX[0x4b] = 0;
  return;
}


// ==== FUN_005abba0 @ 0x005abba0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005abba0(undefined4 *param_1)

{
  float *pfVar1;
  int iVar2;
  undefined4 *puVar3;
  char cVar4;
  float *pfVar5;
  undefined4 uVar6;
  int in_ECX;
  float10 fVar7;
  float fVar8;
  float fVar9;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  puVar3 = param_1;
  local_1c = DAT_0099d080;
  pfVar1 = (float *)(param_1 + 6);
  param_1[10] = 0;
  param_1[9] = 0;
  *pfVar1 = local_1c;
  param_1[0xe] = 0;
  param_1[0xc] = 0;
  param_1[7] = local_1c;
  param_1[8] = local_1c;
  param_1[0xb] = *(undefined4 *)(in_ECX + 0x9c);
  *(undefined1 *)(param_1 + 0xf) = 0;
  *(undefined1 *)(param_1 + 0x28) = 0;
  param_1[0xe] = 0;
  iVar2 = *(int *)(in_ECX + 0xf4);
  param_1[0x31] = *(undefined4 *)(iVar2 + 0x40);
  param_1[0x32] = *(undefined4 *)(iVar2 + 0x44);
  param_1[0x33] = *(undefined4 *)(iVar2 + 0x48);
  if ((0.0 < *(float *)(*(int *)(in_ECX + 0xf4) + 0x3c)) ||
     (0.0 < *(float *)(*(int *)(in_ECX + 0xf4) + 0x38))) {
    fVar7 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x3c),
                                  *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x38));
    param_1[0xb] = (float)fVar7;
    local_1c = DAT_0099d080;
  }
  if (*(float *)(*(int *)(in_ECX + 0xf4) + 0x1c) != 0.0) {
    fVar7 = (float10)FUN_0040d0a0(0,*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x1c));
    param_1[9] = (float)fVar7;
    local_1c = DAT_0099d080;
  }
  param_1 = (undefined4 *)local_1c;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x58) != 0) {
    fVar7 = (float10)FUN_005aa2a0(0,0);
    param_1 = (undefined4 *)(float)fVar7;
  }
  local_18 = local_1c;
  local_14 = local_1c;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x90) != 0) {
    pfVar5 = (float *)FUN_005aa3a0(&local_10,0,0);
    local_1c = *pfVar5;
    local_18 = pfVar5[1];
    local_14 = pfVar5[2];
  }
  iVar2 = *(int *)(in_ECX + 0xf4);
  if (*(float *)(iVar2 + 0x20) <= 0.0) goto LAB_005abdaa;
  fVar7 = (float10)FUN_0040d0a0(0.0 - *(float *)(iVar2 + 0x20),*(undefined4 *)(iVar2 + 0x20));
  fVar9 = (float)fVar7;
  fVar8 = local_1c + fVar9;
  if (fVar8 < DAT_0099d080) {
    local_1c = 0.0;
    if (0.0 <= fVar8) goto LAB_005abd5c;
  }
  else {
    fVar8 = DAT_0099d080;
LAB_005abd5c:
    local_1c = fVar8;
  }
  fVar8 = local_18 + fVar9;
  if (fVar8 < DAT_0099d080) {
    local_18 = 0.0;
    if (0.0 <= fVar8) goto LAB_005abd81;
  }
  else {
    fVar8 = DAT_0099d080;
LAB_005abd81:
    local_18 = fVar8;
  }
  fVar9 = local_14 + fVar9;
  fVar8 = DAT_0099d080;
  if ((DAT_0099d080 <= fVar9) || (local_14 = 0.0, fVar8 = fVar9, 0.0 <= fVar9)) {
    local_14 = fVar8;
  }
LAB_005abdaa:
  local_10 = local_1c;
  local_c = local_18;
  local_8 = local_14;
  local_4 = (float)param_1;
  uVar6 = FUN_0040ead0(&local_10);
  puVar3[0xd] = uVar6;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x70) != 0) {
    pfVar5 = (float *)FUN_005aa3a0(&local_10,0,0);
    *pfVar1 = *pfVar5;
    puVar3[7] = pfVar5[1];
    puVar3[8] = pfVar5[2];
  }
  uVar6 = *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 4);
  switch(uVar6) {
  case 1:
  case 2:
  case 5:
  case 6:
  case 7:
    FUN_005ab1a0(puVar3,uVar6);
    break;
  case 3:
    FUN_005ab740(puVar3);
    break;
  case 4:
    FUN_005ab460(puVar3);
  }
  *puVar3 = puVar3[3];
  puVar3[1] = puVar3[4];
  puVar3[2] = puVar3[5];
  fVar9 = (float)*(int *)(in_ECX + 0x80);
  if (*(int *)(in_ECX + 0x80) < 0) {
    fVar9 = fVar9 + _DAT_0099d104;
  }
  if ((**(int **)(in_ECX + 0xf4) == 0) && (DAT_0099d080 < fVar9)) {
    if (*(int *)(in_ECX + 0xa4) != 0) {
      cVar4 = '\0';
      if (*(int *)(in_ECX + 0x94) != 0) {
        cVar4 = (*(int *)(in_ECX + 0x94) != 1) + '\x01';
      }
      FUN_0081d860(cVar4,0,fVar9,*(int *)(in_ECX + 0xa4));
      return;
    }
    fVar7 = (float10)FUN_0040d0a0(0,fVar9);
    puVar3[0xe] = (int)ROUND(fVar7);
  }
  return;
}


// ==== FUN_005abf30 @ 0x005abf30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005abf30(float *param_1,float *param_2)

{
  float fVar1;
  code *pcVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  int iVar4;
  float fVar5;
  float *pfVar6;
  int in_ECX;
  int iVar7;
  float *pfVar8;
  float10 fVar9;
  float fVar10;
  float fVar11;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  void *local_58;
  float local_54;
  float local_50;
  undefined4 local_48;
  uint local_44;
  undefined1 auStack_40 [64];
  
  if (param_2 == (float *)0x0) {
    local_44 = 0xf;
    local_48 = 0;
    local_58 = (void *)((uint)local_58 & 0xffffff00);
    FUN_00401740(s_i_pElement____NULL_009c17d4,0x12);
    FUN_00406880(&local_5c);
    if (local_44 < 0x10) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    _free(local_58);
    return extraout_EAX;
  }
  fVar5 = param_2[0x2a];
  if (fVar5 == 0.0) {
    return 0;
  }
  if ((uint)*param_1 < (uint)fVar5) {
    param_2[0x2a] = (float)((int)fVar5 - (int)*param_1);
  }
  else {
    param_2[0x2a] = 0.0;
  }
  fVar5 = param_2[0x2a];
  fVar1 = param_2[0x29];
  fVar11 = (float)(int)fVar5;
  if ((int)fVar5 < 0) {
    fVar11 = fVar11 + _DAT_0099d104;
  }
  fVar10 = (float)(int)fVar1;
  if ((int)fVar1 < 0) {
    fVar10 = fVar10 + _DAT_0099d104;
  }
  param_2[10] = fVar11 / fVar10;
  local_7c = (float)(int)*param_1;
  if ((int)*param_1 < 0) {
    local_7c = local_7c + _DAT_0099d104;
  }
  local_7c = local_7c * DAT_0099d0ec;
  fVar10 = DAT_0099d080 - fVar11 / fVar10;
  fVar11 = DAT_0099d080;
  if ((DAT_0099d080 <= fVar10) || (local_80 = 0.0, fVar11 = fVar10, 0.0 <= fVar10)) {
    local_80 = fVar11;
  }
  iVar4 = (int)fVar1 - (int)fVar5;
  iVar7 = (int)(local_80 * DAT_009bf5a0);
  FUN_0040ec60(&local_6c,param_2[0xd]);
  if (*(int *)(*(int *)(in_ECX + 8) + 0x58) != 0) {
    fVar9 = (float10)FUN_005aa2a0(iVar7,iVar4);
    local_60 = (float)fVar9;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0x90) != 0) {
    FUN_005aa3a0(&local_78,iVar7,iVar4);
    local_5c = local_78;
    local_58 = (void *)local_74;
    local_54 = local_70;
    local_50 = local_60;
    local_6c = local_78;
    local_68 = local_74;
    local_64 = local_70;
  }
  fVar5 = (float)FUN_0040ead0(&local_6c);
  param_2[0xd] = fVar5;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x70) != 0) {
    pfVar6 = (float *)FUN_005aa3a0(&local_78,iVar7,iVar4);
    param_2[6] = *pfVar6;
    param_2[7] = pfVar6[1];
    param_2[8] = pfVar6[2];
  }
  fVar5 = *(float *)(*(int *)(in_ECX + 0xf4) + 0x1c);
  if (fVar5 != DAT_0099cdc8) {
    param_2[9] = fVar5 * local_80;
  }
  switch(*(int *)(*(int *)(in_ECX + 0xf4) + 4) + -1) {
  case 0:
  case 1:
  case 4:
  case 5:
  case 6:
    FUN_005ab8a0(&local_7c,param_2);
    break;
  case 2:
    FUN_005aacd0(&local_80,param_2);
    break;
  case 3:
    FUN_005ab8a0(&local_7c,param_2);
    param_2[4] = *(float *)(in_ECX + 0x6c);
    break;
  default:
    return 0;
  }
  if (*(char *)(*(int *)(in_ECX + 0xf4) + 9) != '\0') {
    local_78 = param_2[3] - *param_2;
    local_74 = param_2[4] - param_2[1];
    local_70 = param_2[5] - param_2[2];
    if (DAT_009a09b8 < SQRT(local_78 * local_78 + local_74 * local_74 + local_70 * local_70)) {
      thunk_FUN_0079e1ba(&local_78,&local_78);
      FUN_0040d620(&local_5c,&local_78);
      pfVar6 = (float *)FUN_005acde0(auStack_40,&local_5c);
      fVar5 = param_2[3];
      fVar1 = param_2[4];
      pfVar8 = param_2 + 0x10;
      for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
        *pfVar8 = *pfVar6;
        pfVar6 = pfVar6 + 1;
        pfVar8 = pfVar8 + 1;
      }
      *param_2 = fVar5;
      param_2[1] = fVar1;
      param_2[2] = param_2[5];
    }
  }
  if (((**(int **)(in_ECX + 0xf4) == 0) && (1 < *(uint *)(in_ECX + 0x80))) &&
     (*(int *)(in_ECX + 0xa4) != 0)) {
    FUN_0081d6b0(*param_1);
    fVar5 = (float)FUN_00802534();
    param_2[0xe] = fVar5;
    if ((uint)*(float *)(in_ECX + 0x80) <= (uint)fVar5) {
      param_2[0xe] = (float)((int)*(float *)(in_ECX + 0x80) + -1);
    }
  }
  if (*(int *)(*(int *)(in_ECX + 0xf4) + 4) == 3) {
    if (((*(float *)(in_ECX + 0x124) == 0.0) && (*(float *)(in_ECX + 0x128) == 0.0)) &&
       (*(float *)(in_ECX + 300) == 0.0)) {
      return 1;
    }
    FUN_0040d620(&local_5c,in_ECX + 0x124);
    FUN_005acde0(auStack_40,&local_5c);
    thunk_FUN_0079e5a0(param_2 + 3,param_2 + 3,auStack_40);
  }
  return 1;
}


// ==== FUN_005ac340 @ 0x005ac340 ====

void FUN_005ac340(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_80;
  undefined1 local_7c [16];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_54;
  undefined1 local_53;
  
  if ((*(int *)(in_ECX + 0x110) != 0) &&
     ((*(int *)(in_ECX + 0x78) != 0 || (*(int *)(in_ECX + 0x80) != 0)))) {
    puVar1 = *(undefined4 **)(in_ECX + 0x10c);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      uVar3 = puVar2[2];
      local_64 = 0xffffffff;
      local_60 = 0;
      local_54 = 0;
      local_53 = 0;
      local_6c = DAT_0099d080;
      local_68 = DAT_0099d080;
      FUN_005aaab0(&local_80,*(undefined4 *)(param_1 + 0x68),local_7c);
      FUN_005ab040(uVar3,param_2,param_3,param_4,local_80);
    }
  }
  return;
}


// ==== FUN_005ac400 @ 0x005ac400 ====

void FUN_005ac400(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char cVar4;
  int in_ECX;
  undefined4 local_80;
  undefined1 local_7c [16];
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined1 local_54;
  undefined1 local_53;
  
  if ((*(int *)(in_ECX + 0x110) != 0) && (cVar4 = FUN_005aadc0(), cVar4 != '\0')) {
    puVar1 = *(undefined4 **)(in_ECX + 0x10c);
    for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
      uVar3 = puVar2[2];
      local_64 = 0xffffffff;
      local_60 = 0;
      local_54 = 0;
      local_53 = 0;
      local_6c = DAT_0099d080;
      local_68 = DAT_0099d080;
      FUN_005aaab0(&local_80,*(undefined4 *)(param_1 + 0x6c),local_7c);
      FUN_005ab040(uVar3,param_2,param_3,param_4,local_80);
    }
  }
  return;
}


// ==== FUN_005ac4c0 @ 0x005ac4c0 ====

void FUN_005ac4c0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int local_4;
  
  FUN_005ab9f0();
  uVar2 = FUN_005acf40(param_1);
  *(undefined4 *)(in_ECX + 0xf8) = uVar2;
  if (param_1 != 0) {
    iVar4 = 0;
    do {
      iVar1 = *(int *)(in_ECX + 0x100);
      local_4 = *(int *)(in_ECX + 0xf8) + iVar4;
      iVar3 = FUN_005acea0(iVar1,*(undefined4 *)(iVar1 + 4),&local_4);
      FUN_00517200(1);
      *(int *)(iVar1 + 4) = iVar3;
      iVar4 = iVar4 + 0x11c;
      param_1 = param_1 + -1;
      **(int **)(iVar3 + 4) = iVar3;
    } while (param_1 != 0);
  }
  return;
}


// ==== FUN_005ac550 @ 0x005ac550 ====

void FUN_005ac550(void)

{
  int iVar1;
  undefined4 *puVar2;
  void *_Memory;
  int iVar3;
  int in_ECX;
  int *piVar4;
  int local_c;
  int *local_8;
  int local_4;
  
  if (*(int *)(in_ECX + 0x110) != 0) {
    local_8 = *(int **)(in_ECX + 0x10c);
    piVar4 = (int *)*local_8;
    local_4 = in_ECX;
    if (piVar4 != local_8) {
      do {
        iVar1 = *(int *)(in_ECX + 0x100);
        local_c = piVar4[2];
        iVar3 = FUN_005acea0(iVar1,*(undefined4 *)(iVar1 + 4),&local_c);
        FUN_00517200(1);
        *(int *)(iVar1 + 4) = iVar3;
        **(int **)(iVar3 + 4) = iVar3;
        piVar4 = (int *)*piVar4;
      } while (piVar4 != local_8);
      in_ECX = local_4;
    }
    puVar2 = *(undefined4 **)(in_ECX + 0x10c);
    _Memory = (void *)*puVar2;
    *puVar2 = puVar2;
    *(int *)(*(int *)(in_ECX + 0x10c) + 4) = *(int *)(in_ECX + 0x10c);
    *(undefined4 *)(in_ECX + 0x110) = 0;
    if (_Memory != *(void **)(in_ECX + 0x10c)) {
      _free(_Memory);
      return;
    }
  }
  return;
}


// ==== FUN_005ac600 @ 0x005ac600 ====

void FUN_005ac600(int param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int in_ECX;
  int *local_2c;
  int local_28;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  piVar1 = *(int **)(in_ECX + 0x100);
  local_28 = 0;
  local_2c = (int *)*piVar1;
  if (0 < param_1) {
    do {
      if (local_2c == piVar1) {
        return;
      }
      local_20 = local_2c[2];
      if (local_20 == 0) {
        local_4 = 0xf;
        local_8 = 0;
        local_18 = (void *)((uint)local_18 & 0xffffff00);
        FUN_00401740(s_pElement____NULL_009c17c0,0x10);
        FUN_00406880(local_1c);
        if (local_4 < 0x10) {
          local_4 = 0xf;
          local_8 = 0;
          local_18 = (void *)((uint)local_18 & 0xffffff00);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        _free(local_18);
        return;
      }
      FUN_005abba0(local_20);
      iVar2 = *(int *)(in_ECX + 0x10c);
      iVar4 = FUN_005acea0(iVar2,*(undefined4 *)(iVar2 + 4),&local_20);
      FUN_00517200(1);
      *(int *)(iVar2 + 4) = iVar4;
      **(int **)(iVar4 + 4) = iVar4;
      if (local_2c != *(int **)(in_ECX + 0x100)) {
        *(int *)local_2c[1] = *local_2c;
        *(int *)(*local_2c + 4) = local_2c[1];
        _free(local_2c);
        return;
      }
      local_28 = local_28 + 1;
      local_2c = (int *)*local_2c;
    } while (local_28 < param_1);
  }
  return;
}


// ==== FUN_005ac730 @ 0x005ac730 ====

void FUN_005ac730(int param_1,undefined4 param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  *(undefined1 *)(in_ECX + 0x1c8) = 0;
  *(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(param_1 + 4);
  if (*(int *)(*(int *)(param_1 + 0x20) + 0x1c) == 0) {
    if (*(int *)(*(int *)(param_1 + 0x20) + 0x38) == 0) {
      FUN_00401830(s_false_009c17a4);
      FUN_00406880(local_1c);
      if (local_4 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(local_18);
      return;
    }
    uVar2 = FUN_005aa220(*(int *)(param_1 + 0x20) + 0x24);
    *(undefined4 *)(in_ECX + 0x7c) = uVar2;
    *(undefined4 *)(in_ECX + 0x80) = 1;
  }
  else {
    uVar2 = FUN_005aa1b0(*(int *)(param_1 + 0x20) + 8);
    *(undefined4 *)(in_ECX + 0x78) = uVar2;
    *(undefined4 *)(in_ECX + 0x80) = 1;
  }
  FUN_005aae10(param_1);
  *(undefined4 *)(in_ECX + 4) = param_2;
  FUN_005ac4c0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x18));
  return;
}


// ==== FUN_005ac800 @ 0x005ac800 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ac800(int param_1,float param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  FUN_005ac550();
  iVar2 = DAT_0099d080;
  in_ECX[0x70] = 0;
  in_ECX[0x6f] = 0;
  in_ECX[0x6e] = 0;
  in_ECX[0x6d] = 0;
  in_ECX[0x6b] = 0;
  in_ECX[0x6a] = 0;
  in_ECX[0x69] = 0;
  in_ECX[0x68] = 0;
  in_ECX[0x66] = 0;
  in_ECX[0x65] = 0;
  in_ECX[100] = 0;
  in_ECX[99] = 0;
  in_ECX[0x71] = iVar2;
  in_ECX[0x6c] = iVar2;
  in_ECX[0x67] = iVar2;
  in_ECX[0x62] = iVar2;
  in_ECX[2] = param_1;
  in_ECX[0x14] = *(int *)(param_1 + 8);
  *(undefined1 *)((int)in_ECX + 0x75) = 0;
  in_ECX[0x17] = *(int *)(param_1 + 0x18);
  in_ECX[0x18] = *(int *)(param_1 + 0x1c);
  in_ECX[0x19] = *(int *)(param_1 + 0x20);
  fVar1 = (float)*(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[0x15] = (int)ROUND(fVar1 * param_2);
  fVar1 = (float)*(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x10) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[0x28] = (int)ROUND(fVar1 * param_2);
  in_ECX[0x4f] = 0;
  in_ECX[0x50] = 0;
  in_ECX[0x51] = 0;
  if (*(char *)(param_1 + 0x32) != '\0') {
    fVar1 = (float)in_ECX[0x15];
    if (in_ECX[0x15] < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar3 = (float10)FUN_0040d0a0(0,fVar1 * DAT_0099d0ec);
    in_ECX[0x15] = (int)ROUND(fVar3 * (float10)DAT_009b012c);
  }
  in_ECX[0x46] = in_ECX[0x28] - in_ECX[0x15];
  in_ECX[0x47] = in_ECX[0x28] - in_ECX[0x15];
  in_ECX[0x16] = param_3;
  in_ECX[0x49] = 0;
  in_ECX[0x4a] = 0;
  in_ECX[0x4b] = 0;
  if (0 < *(int *)(in_ECX[0x3d] + 0x14)) {
    in_ECX[0x21] = *(int *)(in_ECX[0x3d] + 0x14);
  }
  (**(code **)(*in_ECX + 0x38))();
  return;
}


// ==== FUN_005aca20 @ 0x005aca20 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005aca20(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  float fVar4;
  undefined4 *puVar5;
  int in_ECX;
  int iVar6;
  int iVar7;
  float10 fVar8;
  float fVar9;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  iVar7 = 0;
  if (*(int *)(*(int *)(in_ECX + 0xf4) + 0x14) != 0) {
    if (*param_1 < *(uint *)(in_ECX + 0x11c)) {
      *(uint *)(in_ECX + 0x11c) = *(uint *)(in_ECX + 0x11c) - *param_1;
    }
    else {
      *(undefined4 *)(in_ECX + 0x11c) = 0;
    }
    uVar1 = *(uint *)(*(int *)(in_ECX + 0xf4) + 0x14);
    if ((int)uVar1 < 0) {
      param_1 = (uint *)-uVar1;
    }
    else {
      *(int *)(in_ECX + 0x84) = *(int *)(in_ECX + 0x84) + *param_1;
      uVar2 = *(uint *)(in_ECX + 0x84);
      if (uVar2 < uVar1) {
        return;
      }
      param_1 = (uint *)(uVar2 / uVar1);
      *(uint *)(in_ECX + 0x84) = uVar2 % uVar1;
    }
    if (10 < param_1) {
      param_1 = (uint *)0xa;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if (iVar3 != 0) {
      iVar6 = 0;
      if ((*(int *)(iVar3 + 0x40) != 0) || (*(int *)(iVar3 + 0xb0) != 0)) {
        iVar6 = *(int *)(in_ECX + 0x11c);
        iVar7 = *(int *)(in_ECX + 0x118);
        fVar9 = (float)iVar6;
        if (iVar6 < 0) {
          fVar9 = fVar9 + _DAT_0099d104;
        }
        fVar4 = (float)iVar7;
        if (iVar7 < 0) {
          fVar4 = fVar4 + _DAT_0099d104;
        }
        fVar9 = DAT_0099d080 - fVar9 / fVar4;
        if (DAT_0099d080 <= fVar9) {
          fVar9 = DAT_0099d080;
        }
        else if (fVar9 < 0.0) {
          fVar9 = 0.0;
        }
        iVar7 = iVar7 - iVar6;
        iVar6 = (int)(fVar9 * DAT_009bf5a0);
      }
      if (*(int *)(iVar3 + 0x40) != 0) {
        fVar8 = (float10)FUN_005aa2a0(iVar6,iVar7);
        FUN_0040d600(&local_24,(float)(fVar8 * (float10)_DAT_00af4c78));
        local_1c = local_24;
        local_18 = 0;
        puVar5 = (undefined4 *)(in_ECX + 0x124);
        local_14 = local_20;
        *puVar5 = local_24;
        *(undefined4 *)(in_ECX + 0x128) = 0;
        *(undefined4 *)(in_ECX + 300) = local_20;
        local_10 = *puVar5;
        local_c = *(undefined4 *)(in_ECX + 0x128);
        local_8 = *(undefined4 *)(in_ECX + 300);
        local_4 = DAT_0099d080;
        thunk_FUN_0079ebf5(&local_10,&local_10,in_ECX + 0x188);
        local_1c = local_10;
        local_18 = local_c;
        local_14 = local_8;
        *puVar5 = local_10;
        *(undefined4 *)(in_ECX + 0x128) = local_c;
        *(undefined4 *)(in_ECX + 300) = local_8;
      }
      if (*(int *)(*(int *)(in_ECX + 8) + 0xb0) != 0) {
        puVar5 = (undefined4 *)FUN_005aa3a0(&local_1c,iVar6,iVar7);
        *(undefined4 *)(in_ECX + 0x68) = *puVar5;
        *(undefined4 *)(in_ECX + 0x6c) = puVar5[1];
        *(undefined4 *)(in_ECX + 0x70) = puVar5[2];
      }
      FUN_005ac600(param_1);
    }
  }
  return;
}


// ==== FUN_005acc70 @ 0x005acc70 ====

uint FUN_005acc70(int param_1)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  char cVar4;
  uint extraout_EAX;
  uint uVar5;
  int iVar6;
  uint extraout_EAX_00;
  int *in_ECX;
  int *piStack_28;
  int iStack_24;
  int *piStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  int iStack_8;
  uint uStack_4;
  
  in_ECX[0x16] = in_ECX[0x16] + param_1;
  in_ECX[0x45] = param_1;
  (**(code **)(*in_ECX + 0x38))();
  if (((uint)in_ECX[0x15] < (uint)in_ECX[0x16]) && ((uint)in_ECX[0x16] < (uint)in_ECX[0x28])) {
    FUN_005aca20(&param_1);
  }
  piStack_20 = (int *)in_ECX[0x43];
  piStack_28 = (int *)*piStack_20;
  if (piStack_28 != piStack_20) {
    do {
      iStack_24 = piStack_28[2];
      if (iStack_24 == 0) {
        uStack_4 = 0xf;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        iStack_8 = iStack_24;
        FUN_00401740(s_pElement____NULL_009c17ac,0x10);
        FUN_00406880(auStack_1c);
        if (uStack_4 < 0x10) {
          uStack_4 = 0xf;
          iStack_8 = 0;
          pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
          pcVar2 = (code *)swi(3);
          uVar5 = (*pcVar2)();
          return uVar5;
        }
        _free(pvStack_18);
        return extraout_EAX;
      }
      cVar4 = FUN_005abf30(&param_1,iStack_24);
      if (cVar4 == '\0') {
        iVar1 = in_ECX[0x40];
        iVar6 = FUN_005acea0(iVar1,*(undefined4 *)(iVar1 + 4),&iStack_24);
        FUN_00517200(1);
        *(int *)(iVar1 + 4) = iVar6;
        **(int **)(iVar6 + 4) = iVar6;
        piVar3 = (int *)*piStack_28;
        if (piStack_28 != (int *)in_ECX[0x43]) {
          *(int *)piStack_28[1] = *piStack_28;
          *(int *)(*piStack_28 + 4) = piStack_28[1];
          _free(piStack_28);
          return extraout_EAX_00;
        }
      }
      else {
        piVar3 = (int *)*piStack_28;
      }
      piStack_28 = piVar3;
    } while (piStack_28 != piStack_20);
  }
  if (((uint)in_ECX[0x15] < (uint)in_ECX[0x16]) && (in_ECX[0x44] == 0)) {
    *(undefined1 *)((int)in_ECX + 0x75) = 1;
  }
  return (uint)(*(char *)((int)in_ECX + 0x75) == '\0');
}


// ==== FUN_005acde0 @ 0x005acde0 ====

void FUN_005acde0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 local_40 [4];
  undefined4 auStack_3c [14];
  undefined4 *puStack_4;
  
  thunk_FUN_0079fb96(local_40,param_2);
  puVar2 = (undefined4 *)(local_40 + -8);
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puStack_4 = *puVar2;
    puVar2 = puVar2 + 1;
    puStack_4 = puStack_4 + 1;
  }
  return;
}


// ==== FUN_005ace10 @ 0x005ace10 ====

void FUN_005ace10(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009827e0;
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


// ==== Catch@005ace7f @ 0x005ace7f ====

void Catch_005ace7f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005acea0 @ 0x005acea0 ====

void FUN_005acea0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009827f0;
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


// ==== Catch@005acf09 @ 0x005acf09 ====

void Catch_005acf09(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005acf20 @ 0x005acf20 ====

void FUN_005acf20(byte param_1)

{
  void *in_ECX;
  
  FUN_005aba90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005acf40 @ 0x005acf40 ====

void FUN_005acf40(int param_1)

{
  code *pcVar1;
  void *pvVar2;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(param_1 * 0x11c);
  if (pvVar2 != (void *)0x0) {
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


// ==== FUN_005acfc0 @ 0x005acfc0 ====

void FUN_005acfc0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x75) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(in_ECX + 0x80);
  return;
}


// ==== FUN_005acfe0 @ 0x005acfe0 ====

void FUN_005acfe0(void)

{
  return;
}


// ==== FUN_005ad020 @ 0x005ad020 ====

void FUN_005ad020(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c18cc;
  if (in_ECX[0x2e] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x2e]);
    in_ECX[0x2e] = 0;
  }
  *in_ECX = &PTR_FUN_009c1724;
  return;
}


// ==== FUN_005ad060 @ 0x005ad060 ====

void FUN_005ad060(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x78);
  if (iVar1 != 0) {
    *(undefined1 *)(iVar1 + 0x60) = 1;
    *(undefined4 *)(iVar1 + 0x78) = *(undefined4 *)(in_ECX + 0xb8);
    *(undefined4 *)(iVar1 + 100) = *(undefined4 *)(in_ECX + 0xa4);
    *(undefined4 *)(iVar1 + 0x68) = *(undefined4 *)(in_ECX + 0xa8);
    *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(in_ECX + 0xb4);
    *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(in_ECX + 0xac);
    *(undefined4 *)(iVar1 + 0x70) = *(undefined4 *)(in_ECX + 0xb0);
  }
  return;
}


// ==== FUN_005ad0b0 @ 0x005ad0b0 ====

void FUN_005ad0b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c18cc;
  *(undefined1 *)(in_ECX + 0x1e) = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x16] = 0;
  *(undefined1 *)((int)in_ECX + 0x75) = 0;
  in_ECX[0x2e] = 0;
  return;
}


// ==== FUN_005ad0d0 @ 0x005ad0d0 ====

void FUN_005ad0d0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x58);
  for (iVar2 = *(int *)(param_1 + 0x54); iVar2 != iVar1; iVar2 = iVar2 + 0x7c) {
    *(undefined1 *)(iVar2 + 0x60) = 1;
    *(undefined4 *)(iVar2 + 0x78) = *(undefined4 *)(in_ECX + 0xb8);
    *(undefined4 *)(iVar2 + 100) = *(undefined4 *)(in_ECX + 0xa4);
    *(undefined4 *)(iVar2 + 0x68) = *(undefined4 *)(in_ECX + 0xa8);
    *(undefined4 *)(iVar2 + 0x74) = *(undefined4 *)(in_ECX + 0xb4);
    *(undefined4 *)(iVar2 + 0x6c) = *(undefined4 *)(in_ECX + 0xac);
    *(undefined4 *)(iVar2 + 0x70) = *(undefined4 *)(in_ECX + 0xb0);
  }
  return;
}


// ==== FUN_005ad130 @ 0x005ad130 ====

void FUN_005ad130(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(in_ECX + 4) = param_2;
  *(undefined1 *)(in_ECX + 0x98) = *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x1c);
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0xac) = *puVar1;
  *(undefined4 *)(in_ECX + 0xb0) = puVar1[1];
  *(undefined4 *)(in_ECX + 0xb4) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x18);
  iVar3 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(iVar3 + 8);
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(iVar3 + 0xc);
  *(undefined4 *)(in_ECX + 0x90) = *(undefined4 *)(iVar3 + 0x10);
  local_10 = *(undefined4 *)(in_ECX + 0x88);
  local_c = *(undefined4 *)(in_ECX + 0x8c);
  local_8 = *(undefined4 *)(in_ECX + 0x90);
  *(undefined4 *)(in_ECX + 0x94) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14);
  local_4 = *(undefined4 *)(in_ECX + 0x94);
  uVar2 = FUN_0040ead0(&local_10);
  *(undefined4 *)(in_ECX + 0xa4) = uVar2;
  *(undefined4 *)(in_ECX + 0x9c) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
  *(undefined1 *)(in_ECX + 0xa0) = *(undefined1 *)(*(int *)(param_1 + 0x20) + 0x44);
  *(undefined4 *)(in_ECX + 0xa8) = *(undefined4 *)(param_1 + 8);
  iVar3 = FUN_00403620(0,*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1c),&DAT_009c187a,0);
  if (iVar3 != 0) {
    uVar2 = FUN_004b4e70(*(int *)(param_1 + 0x20) + 8);
    *(undefined4 *)(in_ECX + 0xb8) = uVar2;
  }
  return;
}


// ==== FUN_005ad240 @ 0x005ad240 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ad240(float param_1)

{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  float10 fVar7;
  float fVar8;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  if ((uint)param_1 < *(uint *)(in_ECX + 0x84)) {
    *(uint *)(in_ECX + 0x84) = *(uint *)(in_ECX + 0x84) - (int)param_1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x84) = 0;
  }
  iVar6 = *(int *)(in_ECX + 0x84);
  iVar3 = *(int *)(in_ECX + 0x80);
  fVar2 = (float)iVar6;
  if (iVar6 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  fVar8 = (float)iVar3;
  if (iVar3 < 0) {
    fVar8 = fVar8 + _DAT_0099d104;
  }
  fVar2 = DAT_0099d080 - fVar2 / fVar8;
  if (DAT_0099d080 <= fVar2) {
    fVar2 = DAT_0099d080;
  }
  else {
    fVar8 = 0.0;
    if (fVar2 < 0.0) goto LAB_005ad2c7;
  }
  fVar8 = fVar2;
LAB_005ad2c7:
  iVar3 = iVar3 - iVar6;
  iVar6 = (int)(fVar8 * DAT_009bf5a0);
  if (*(int *)(*(int *)(in_ECX + 8) + 0x70) != 0) {
    FUN_005aa3a0(&local_1c,iVar6,iVar3);
    *(undefined4 *)(in_ECX + 0xa8) = local_1c;
  }
  iVar1 = *(int *)(in_ECX + 8);
  if ((*(int *)(iVar1 + 0x90) != 0) || (*(int *)(iVar1 + 0x58) != 0)) {
    param_1 = *(float *)(in_ECX + 0x94);
    local_1c = *(undefined4 *)(in_ECX + 0x88);
    local_18 = *(undefined4 *)(in_ECX + 0x8c);
    local_14 = *(undefined4 *)(in_ECX + 0x90);
    if (*(int *)(iVar1 + 0x58) != 0) {
      fVar7 = (float10)FUN_005aa2a0(iVar6,iVar3);
      param_1 = (float)fVar7;
    }
    if (*(int *)(*(int *)(in_ECX + 8) + 0x90) != 0) {
      puVar4 = (undefined4 *)FUN_005aa3a0(&local_10,iVar6,iVar3);
      local_1c = *puVar4;
      local_18 = puVar4[1];
      local_14 = puVar4[2];
    }
    local_10 = local_1c;
    local_c = local_18;
    local_8 = local_14;
    local_4 = param_1;
    uVar5 = FUN_0040ead0(&local_10);
    *(undefined4 *)(in_ECX + 0xa4) = uVar5;
  }
  return;
}


// ==== FUN_005ad3e0 @ 0x005ad3e0 ====

uint FUN_005ad3e0(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0x58);
  if (*(uint *)(in_ECX + 0x7c) <= uVar1) {
    *(undefined1 *)(in_ECX + 0x75) = 1;
    return uVar1 & 0xffffff00;
  }
  uVar1 = uVar1 + param_1;
  *(uint *)(in_ECX + 0x58) = uVar1;
  if (uVar1 < *(uint *)(in_ECX + 0x54)) {
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  FUN_005ad240(param_1);
  return (uint)(*(char *)(in_ECX + 0x75) == '\0');
}


// ==== FUN_005ad420 @ 0x005ad420 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ad420(int param_1,float param_2,undefined4 param_3)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  
  *(int *)(in_ECX + 8) = param_1;
  *(undefined1 *)(in_ECX + 0x75) = 0;
  fVar2 = (float)*(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xc) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  *(int *)(in_ECX + 0x54) = (int)ROUND(fVar2 * param_2);
  iVar3 = FUN_00802534();
  iVar1 = *(int *)(in_ECX + 0x54);
  *(int *)(in_ECX + 0x7c) = iVar3;
  *(int *)(in_ECX + 0x80) = iVar3 - iVar1;
  if (*(char *)(param_1 + 0x32) != '\0') {
    fVar2 = (float)iVar1;
    if (iVar1 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar4 = (float10)FUN_0040d0a0(0,fVar2 * DAT_0099d0ec);
    *(int *)(in_ECX + 0x54) = (int)ROUND(fVar4 * (float10)DAT_009b012c);
  }
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(in_ECX + 0x80);
  *(undefined4 *)(in_ECX + 0x58) = param_3;
  *(undefined1 *)(in_ECX + 0x78) = 0;
  FUN_005ad240(0);
  return;
}


// ==== FUN_005ad510 @ 0x005ad510 ====

void FUN_005ad510(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c18cc;
  if (in_ECX[0x2e] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x2e]);
    in_ECX[0x2e] = 0;
  }
  *in_ECX = &PTR_FUN_009c1724;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ad560 @ 0x005ad560 ====

void FUN_005ad560(int param_1,int param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(param_1 + 0x28);
  *(int *)(in_ECX + 4) = param_2;
  *(undefined4 *)(in_ECX + 0x94) = *(undefined4 *)(param_2 + 4);
  return;
}


// ==== FUN_005ad580 @ 0x005ad580 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ad580(int param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  in_ECX[2] = param_1;
  in_ECX[0x17] = *(int *)(param_1 + 0x18);
  in_ECX[0x18] = *(int *)(param_1 + 0x1c);
  in_ECX[0x19] = *(int *)(param_1 + 0x20);
  in_ECX[0x14] = *(int *)(param_1 + 8);
  in_ECX[0x17] = *(int *)(param_1 + 0x18);
  in_ECX[0x18] = *(int *)(param_1 + 0x1c);
  in_ECX[0x19] = *(int *)(param_1 + 0x20);
  iVar2 = FUN_00802534();
  in_ECX[0x15] = iVar2;
  if (*(char *)(param_1 + 0x32) != '\0') {
    fVar1 = (float)iVar2;
    if (iVar2 < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar3 = (float10)FUN_0040d0a0(0,fVar1 * DAT_0099d0ec);
    in_ECX[0x15] = (int)ROUND(fVar3 * (float10)DAT_009b012c);
  }
  iVar2 = *(int *)(in_ECX[0x1e] + 0x28) * *(int *)(in_ECX[0x1e] + 0x1c);
  in_ECX[0x16] = param_3;
  in_ECX[0x23] = in_ECX[0x15] + iVar2;
  in_ECX[0x24] = iVar2;
  in_ECX[0x1f] = in_ECX[0x1a];
  in_ECX[0x20] = in_ECX[0x1b];
  in_ECX[0x21] = in_ECX[0x1c];
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  *(undefined1 *)(in_ECX + 0x22) = 0;
  (**(code **)(*in_ECX + 0x18))(0);
  *(undefined1 *)((int)in_ECX + 0x75) = 0;
  return;
}


// ==== FUN_005ad6b0 @ 0x005ad6b0 ====

void FUN_005ad6b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c190c;
  *(undefined1 *)(in_ECX + 0x22) = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x16] = 0;
  *(undefined1 *)((int)in_ECX + 0x75) = 0;
  return;
}


// ==== FUN_005ad6d0 @ 0x005ad6d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ad6d0(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (param_1 == 0) {
    if (*(char *)(in_ECX + 0x88) != '\0') {
      iVar2 = (**(code **)(*DAT_00b5a6a8 + 4))();
      if (iVar2 == 0) {
        uVar3 = 0;
      }
      else {
        FUN_00765c50(*(undefined4 *)(in_ECX + 0x78));
        uVar3 = FUN_005ad9a0(*(undefined4 *)(in_ECX + 0x94));
      }
      FUN_00797a20(uVar3);
      *(undefined1 *)(in_ECX + 0x88) = 0;
    }
  }
  else if ((param_1 == 1) && (*(char *)(in_ECX + 0x88) == '\0')) {
    iVar2 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar2 == 0) {
      FUN_00797a20(0);
      *(undefined1 *)(in_ECX + 0x88) = 1;
      return;
    }
    iVar2 = *(int *)(in_ECX + 0x78);
    FUN_00765c50(iVar2);
    fVar1 = (float)*(int *)(iVar2 + 0x20);
    if (*(int *)(iVar2 + 0x20) < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    uVar3 = FUN_005ad8e0(*(undefined4 *)(in_ECX + 0x94),*(undefined4 *)(in_ECX + 0x68),
                         *(undefined4 *)(in_ECX + 0x6c),*(undefined4 *)(in_ECX + 0x70),
                         *(undefined4 *)(iVar2 + 0x1c),fVar1,*(undefined4 *)(iVar2 + 0x24));
    FUN_00797a20(uVar3);
    *(undefined1 *)(in_ECX + 0x88) = 1;
    return;
  }
  return;
}


// ==== FUN_005ad7e0 @ 0x005ad7e0 ====

void FUN_005ad7e0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x75) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  if ((*(int *)(in_ECX + 0x8c) == 0) && (*(int *)(in_ECX + 0x90) != 0)) {
    FUN_005ad6d0(0);
    FUN_005ad6d0(1);
  }
  return;
}


// ==== FUN_005ad810 @ 0x005ad810 ====

uint FUN_005ad810(int param_1)

{
  uint uVar1;
  uint in_EAX;
  int *in_ECX;
  
  if (*(char *)((int)in_ECX + 0x75) == '\x01') {
    return in_EAX & 0xffffff00;
  }
  in_ECX[0x16] = in_ECX[0x16] + param_1;
  uVar1 = in_ECX[0x16];
  if (uVar1 < (uint)in_ECX[0x15]) {
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  if ((uVar1 < (uint)in_ECX[0x23]) || (in_ECX[0x24] == 0)) {
    (**(code **)(*in_ECX + 0x38))();
    FUN_005ad6d0(1);
    return (uint)(*(char *)((int)in_ECX + 0x75) == '\0');
  }
  FUN_005ad6d0(0);
  *(undefined1 *)((int)in_ECX + 0x75) = 1;
  return (uint)(*(char *)((int)in_ECX + 0x75) == '\0');
}


// ==== FUN_005ad880 @ 0x005ad880 ====

void FUN_005ad880(void)

{
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 0x8c) <= *(uint *)(in_ECX + 0x58)) || (*(int *)(in_ECX + 0x90) == 0)) {
    FUN_005ad6d0(0);
  }
  *(undefined1 *)(in_ECX + 0x75) = 1;
  return;
}


// ==== FUN_005ad8b0 @ 0x005ad8b0 ====

void FUN_005ad8b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c190c;
  FUN_005ad6d0(0);
  *in_ECX = &PTR_FUN_009c1724;
  return;
}


// ==== FUN_005ad8d0 @ 0x005ad8d0 ====

void FUN_005ad8d0(void)

{
  return;
}


// ==== FUN_005ad8e0 @ 0x005ad8e0 ====

void FUN_005ad8e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined1 param_8,
                 void *param_9)

{
  undefined4 *in_ECX;
  uint in_stack_00000038;
  
  in_ECX[1] = param_1;
  in_ECX[2] = param_5;
  in_ECX[5] = param_2;
  in_ECX[6] = param_3;
  in_ECX[7] = param_4;
  in_ECX[3] = param_6;
  *in_ECX = &PTR_FUN_009c194c;
  in_ECX[4] = param_7;
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  FUN_00401660(&param_8,0,0xffffffff);
  if (in_stack_00000038 < 0x10) {
    return;
  }
  _free(param_9);
  return;
}


// ==== FUN_005ad960 @ 0x005ad960 ====

undefined4 FUN_005ad960(void)

{
  return 0x60050001;
}


// ==== FUN_005ad970 @ 0x005ad970 ====

void FUN_005ad970(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c194c;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_005ad9a0 @ 0x005ad9a0 ====

void FUN_005ad9a0(undefined4 param_1,undefined1 param_2,void *param_3)

{
  undefined4 *in_ECX;
  uint in_stack_00000020;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009c1960;
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


// ==== FUN_005ad9f0 @ 0x005ad9f0 ====

undefined4 FUN_005ad9f0(void)

{
  return 0x60050002;
}


// ==== FUN_005ada00 @ 0x005ada00 ====

void FUN_005ada00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1960;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_005ada30 @ 0x005ada30 ====

void FUN_005ada30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c190c;
  FUN_005ad6d0(0);
  *in_ECX = &PTR_FUN_009c1724;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ada60 @ 0x005ada60 ====

undefined4 FUN_005ada60(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x74);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005c1a90();
  }
  pvVar1 = operator_new(0x54);
  if (pvVar1 == (void *)0x0) {
    FUN_005bf5b0(param_1);
    return 0;
  }
  uVar2 = FUN_005bfe30(uVar2);
  FUN_005bf5b0(param_1);
  return uVar2;
}


// ==== FUN_005adac0 @ 0x005adac0 ====

undefined4 FUN_005adac0(undefined4 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x10))(param_1);
  pvVar2 = operator_new(0x7c);
  if (pvVar2 == (void *)0x0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_005c2680(uVar1);
  }
  FUN_005c2520(param_1);
  FUN_005c2730();
  return uVar1;
}


// ==== FUN_005adb10 @ 0x005adb10 ====

int * FUN_005adb10(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  int *piVar4;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0xc))(param_1 + 0x48,*(undefined1 *)(param_1 + 0x40));
  uVar2 = (**(code **)(*in_ECX + 8))(*(undefined1 *)(param_1 + 0x40));
  pvVar3 = operator_new(0x5c);
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_005c30d0(param_1 + 4,uVar1,uVar2);
  }
  (**(code **)(*piVar4 + 0x54))(*(undefined4 *)(param_1 + 0x3c),*(undefined4 *)(param_1 + 0x44));
  return piVar4;
}


// ==== FUN_005adb80 @ 0x005adb80 ====

void FUN_005adb80(void)

{
                    /* WARNING: Could not recover jumptable at 0x005adb88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aff0 + 4))();
  return;
}


// ==== FUN_005adc20 @ 0x005adc20 ====

void FUN_005adc20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1988;
  return;
}


// ==== FUN_005adc90 @ 0x005adc90 ====

int FUN_005adc90(int *param_1,int *param_2)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  
  puVar1 = param_1;
  uVar4 = param_1[0xe];
  uVar5 = param_1[0xd];
  pvVar2 = operator_new(0xc);
  if (pvVar2 == (void *)0x0) {
    param_1 = (int *)0x0;
  }
  else {
    param_1 = (int *)FUN_005c51c0();
  }
  FUN_005c5160(puVar1 + 5,puVar1 + 7,uVar5,uVar4);
  uVar4 = puVar1[0xe];
  uVar5 = puVar1[0xd];
  pvVar2 = operator_new(0x58);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (**(code **)(*DAT_00b5aff0 + 4))(param_2);
    uVar3 = FUN_005c5740(uVar3);
  }
  FUN_005c5850(puVar1 + 5,puVar1 + 7,uVar5,uVar4);
  pvVar2 = operator_new(0x30);
  if (pvVar2 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_005c4c50(uVar3);
  }
  FUN_005c4bc0();
  pvVar2 = operator_new(0x4c);
  if (pvVar2 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_005c87c0();
  }
  pvVar2 = operator_new(0xe8);
  if (pvVar2 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_005c74c0(uVar4,uVar3,param_1,uVar5);
  }
  FUN_005c7a10(*puVar1,0,puVar1[1],*param_2 == 5);
  FUN_005c7930(param_2);
  if (iVar6 == 0) {
    iVar7 = 0;
  }
  else {
    iVar7 = iVar6 + 0x10;
  }
  (**(code **)(*param_1 + 4))(iVar7);
  return iVar6;
}


// ==== FUN_005ade00 @ 0x005ade00 ====

undefined4 FUN_005ade00(int *param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iStack_48;
  int iStack_44;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  int iStack_14;
  int iStack_10;
  
  iVar1 = (**(code **)(*param_1 + 0x10))();
  if (iVar1 != 1) {
    return 0;
  }
  iStack_48 = param_1[1];
  iStack_44 = param_1[2];
  iStack_34 = param_1[4];
  iStack_14 = param_1[8];
  iStack_30 = param_1[5];
  iStack_2c = param_1[6];
  iStack_28 = param_1[7];
  iStack_10 = param_1[9];
  pvVar2 = operator_new(0x5c);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005adc90(&iStack_48,param_1 + 10);
    uVar3 = FUN_005ca3f0(uVar3);
  }
  FUN_005c8ee0(iStack_48,(char)param_1[3],param_1 + 0xc);
  FUN_005c90f0(*(undefined1 *)((int)param_1 + 0x35),(char)param_1[0xd]);
  return uVar3;
}


// ==== FUN_005adec0 @ 0x005adec0 ====

void FUN_005adec0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005aded2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)();
  return;
}


// ==== FUN_005adee0 @ 0x005adee0 ====

void FUN_005adee0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1974;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005adf00 @ 0x005adf00 ====

void FUN_005adf00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c199c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005adf20 @ 0x005adf20 ====

int FUN_005adf20(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_005adf30 @ 0x005adf30 ====

int FUN_005adf30(undefined1 *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int in_ECX;
  undefined1 local_c [4];
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int **)(in_ECX + 0x74) == (int *)0x0) {
    return 0;
  }
  local_c[0] = *param_1;
  local_8 = *(undefined4 *)(param_1 + 4);
  local_4 = *(undefined4 *)(param_1 + 8);
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x74) + 0xc))(local_c);
  if (iVar2 == 0) {
    return 0;
  }
  pcVar3 = (char *)(iVar2 + 0xc);
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar2 + 0xc),(int)pcVar3 - (iVar2 + 0xd));
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(iVar2 + 0x10c);
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(iVar2 + 0x114);
  return in_ECX + 0x50;
}


// ==== FUN_005adfc0 @ 0x005adfc0 ====

void FUN_005adfc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c19ac;
  if (0xf < (uint)in_ECX[0x1a]) {
    _free((void *)in_ECX[0x15]);
    return;
  }
  in_ECX[0x1a] = 0xf;
  in_ECX[0x19] = 0;
  *(undefined1 *)(in_ECX + 0x15) = 0;
  FUN_005ae530();
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[6] = 0;
    in_ECX[7] = 0xf;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009c199c;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_005ae020 @ 0x005ae020 ====

void FUN_005ae020(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  undefined4 *in_ECX;
  char *pcVar4;
  
  *in_ECX = &PTR_FUN_009c19ac;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_005ae590();
  in_ECX[0x1a] = 0xf;
  in_ECX[0x19] = 0;
  *(undefined1 *)(in_ECX + 0x15) = 0;
  piVar2 = (int *)(**(code **)(*DAT_00b5a780 + 8))(param_1);
  in_ECX[0x1d] = piVar2;
  if (piVar2 != (int *)0x0) {
    pcVar3 = (char *)(**(code **)(*piVar2 + 8))();
    pcVar4 = pcVar3;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(pcVar3,(int)pcVar4 - (int)(pcVar3 + 1));
  }
  return;
}


// ==== FUN_005ae090 @ 0x005ae090 ====

void FUN_005ae090(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982800;
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


// ==== Catch@005ae11a @ 0x005ae11a ====

void Catch_005ae11a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005ae130 @ 0x005ae130 ====

/* WARNING: Removing unreachable block (ram,0x005ae249) */
/* WARNING: Removing unreachable block (ram,0x005ae25a) */
/* WARNING: Removing unreachable block (ram,0x005ae263) */
/* WARNING: Removing unreachable block (ram,0x005ae266) */
/* WARNING: Removing unreachable block (ram,0x005ae256) */
/* WARNING: Removing unreachable block (ram,0x005ae274) */
/* WARNING: Removing unreachable block (ram,0x005ae281) */
/* WARNING: Removing unreachable block (ram,0x005ae28c) */
/* WARNING: Removing unreachable block (ram,0x005ae288) */
/* WARNING: Removing unreachable block (ram,0x005ae27c) */
/* WARNING: Removing unreachable block (ram,0x005ae28f) */

void FUN_005ae130(undefined4 param_1,int *param_2)

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
            goto LAB_005ae364;
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
LAB_005ae364:
            *(undefined1 *)(piVar5 + 0xb) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xb) = 1;
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


// ==== FUN_005ae410 @ 0x005ae410 ====

void FUN_005ae410(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_005ae410(*(undefined4 *)((int)param_1 + 8));
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


// ==== FUN_005ae470 @ 0x005ae470 ====

void FUN_005ae470(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_005ae410(piVar6[1]);
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
    FUN_005ae130(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_005ae530 @ 0x005ae530 ====

void FUN_005ae530(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_005ae470(local_4,**(undefined4 **)(in_ECX + 0x28),*(undefined4 **)(in_ECX + 0x28));
  _free(*(void **)(in_ECX + 0x28));
  return;
}


// ==== FUN_005ae590 @ 0x005ae590 ====

void FUN_005ae590(void)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401740(&DAT_0099cf70,0);
  *(undefined4 *)(in_ECX + 0x1c) = DAT_0099de78;
  *(undefined4 *)(in_ECX + 0x20) = DAT_0099d080;
  iVar1 = FUN_005ae090();
  *(int *)(in_ECX + 0x28) = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(int *)(*(int *)(in_ECX + 0x28) + 4) = *(int *)(in_ECX + 0x28);
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(in_ECX + 0x28);
  *(int *)(*(int *)(in_ECX + 0x28) + 8) = *(int *)(in_ECX + 0x28);
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  return;
}


// ==== FUN_005ae600 @ 0x005ae600 ====

void FUN_005ae600(byte param_1)

{
  void *in_ECX;
  
  FUN_005adfc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ae630 @ 0x005ae630 ====

void FUN_005ae630(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(in_ECX + 0x20) = *param_1;
  *(undefined4 *)(in_ECX + 0x24) = param_1[1];
  *(undefined4 *)(in_ECX + 0x28) = param_1[2];
  *(undefined4 *)(in_ECX + 0x2c) = *param_2;
  *(undefined4 *)(in_ECX + 0x30) = param_2[1];
  *(undefined4 *)(in_ECX + 0x34) = param_2[2];
  *(undefined4 *)(in_ECX + 0x38) = *param_3;
  *(undefined4 *)(in_ECX + 0x3c) = param_3[1];
  uVar1 = param_3[2];
  *(undefined4 *)(in_ECX + 0x44) = param_4;
  *(undefined4 *)(in_ECX + 0x48) = param_5;
  *(undefined4 *)(in_ECX + 0x4c) = param_6;
  *(undefined4 *)(in_ECX + 0x40) = uVar1;
  puVar3 = (undefined4 *)(in_ECX + 0x54);
  for (iVar2 = 0x30; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_7;
    param_7 = param_7 + 1;
    puVar3 = puVar3 + 1;
  }
  return;
}


// ==== FUN_005ae6b0 @ 0x005ae6b0 ====

void FUN_005ae6b0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x114) = param_1;
  *(undefined4 *)(in_ECX + 0x118) = param_2;
  return;
}


// ==== FUN_005ae6d0 @ 0x005ae6d0 ====

void FUN_005ae6d0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x11c) = param_1;
  return;
}


// ==== FUN_005ae6e0 @ 0x005ae6e0 ====

void FUN_005ae6e0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x11d) = param_1;
  return;
}


// ==== FUN_005ae6f0 @ 0x005ae6f0 ====

void FUN_005ae6f0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = *param_1;
  *(undefined4 *)(in_ECX + 0x28) = param_1[1];
  return;
}


// ==== FUN_005ae710 @ 0x005ae710 ====

void FUN_005ae710(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d100;
  *in_ECX = &PTR_FUN_009c1a5c;
  in_ECX[9] = uVar1;
  uVar1 = DAT_0099d080;
  in_ECX[8] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = uVar1;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = uVar1;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = uVar1;
  in_ECX[0x10] = 0;
  in_ECX[0x45] = 0;
  in_ECX[0x46] = 0;
  *(undefined1 *)(in_ECX + 0x47) = 0;
  return;
}


// ==== FUN_005ae770 @ 0x005ae770 ====

void FUN_005ae770(int *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 auStack_10a [10];
  undefined4 local_100;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc [50];
  
  local_dc = *(undefined4 *)(in_ECX + 0x44);
  local_100 = *(undefined4 *)(in_ECX + 0x20);
  local_fc = *(undefined4 *)(in_ECX + 0x24);
  local_f8 = *(undefined4 *)(in_ECX + 0x28);
  local_f4 = *(undefined4 *)(in_ECX + 0x2c);
  local_f0 = *(undefined4 *)(in_ECX + 0x30);
  local_ec = *(undefined4 *)(in_ECX + 0x34);
  local_d8 = *(undefined4 *)(in_ECX + 0x48);
  local_e8 = *(undefined4 *)(in_ECX + 0x38);
  local_e4 = *(undefined4 *)(in_ECX + 0x3c);
  local_e0 = *(undefined4 *)(in_ECX + 0x40);
  local_d4 = *(undefined4 *)(in_ECX + 0x4c);
  local_d0 = *(undefined4 *)(in_ECX + 0x50);
  puVar2 = (undefined4 *)(in_ECX + 0x54);
  puVar3 = local_cc;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  (**(code **)(*param_1 + 8))(&local_100);
  (**(code **)(*param_1 + 0x58))(auStack_10a + -6);
  return;
}


// ==== FUN_005ae850 @ 0x005ae850 ====

void FUN_005ae850(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1a78;
  if ((uint)in_ECX[0x11] < 0x10) {
    in_ECX[0x11] = 0xf;
    in_ECX[0x10] = 0;
    *(undefined1 *)(in_ECX + 0xc) = 0;
    *in_ECX = &PTR_FUN_009bf514;
    return;
  }
  _free((void *)in_ECX[0xc]);
  return;
}


// ==== FUN_005ae890 @ 0x005ae890 ====

void FUN_005ae890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1a78;
  *(undefined1 *)(in_ECX + 8) = 0;
  in_ECX[0x11] = 0xf;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  FUN_00401740(s_normal_009c19bc,6);
  return;
}


// ==== FUN_005ae8c0 @ 0x005ae8c0 ====

void FUN_005ae8c0(int *param_1)

{
  int in_ECX;
  undefined4 local_24;
  undefined4 local_20;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  local_8 = 0;
  local_18 = 0;
  local_4 = 0xf;
  FUN_00401660(in_ECX + 0x2c,0,0xffffffff);
  local_24 = *(undefined4 *)(in_ECX + 0x24);
  local_20 = *(undefined4 *)(in_ECX + 0x28);
  (**(code **)(*param_1 + 0x18))(&local_24);
  if (local_8 < 0x10) {
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_005ae920 @ 0x005ae920 ====

void FUN_005ae920(undefined4 *param_1)

{
  switch(*param_1) {
  case 0:
    FUN_00403810();
    return;
  case 1:
    FUN_00403810();
    return;
  case 2:
    FUN_00403810();
    return;
  case 3:
    FUN_00403810();
    return;
  case 4:
    FUN_00403810();
    return;
  case 5:
    FUN_00403810();
    return;
  case 6:
    FUN_00403810();
    return;
  case 7:
    FUN_00403810();
    return;
  case 8:
    FUN_00403810();
    return;
  case 9:
    FUN_00403810();
    return;
  case 10:
    FUN_00403810();
    return;
  case 0xb:
    FUN_00403810();
    return;
  case 0xc:
    FUN_00403810();
    return;
  default:
    FUN_00401740(s_normal_009c1a50,6);
    return;
  }
}


// ==== FUN_005aea50 @ 0x005aea50 ====

void FUN_005aea50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bf514;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005aea70 @ 0x005aea70 ====

void FUN_005aea70(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x20) = param_1;
  return;
}


// ==== FUN_005aea80 @ 0x005aea80 ====

undefined1 FUN_005aea80(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x20);
}


// ==== FUN_005aea90 @ 0x005aea90 ====

void FUN_005aea90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1a78;
  if (0xf < (uint)in_ECX[0x11]) {
    _free((void *)in_ECX[0xc]);
    return;
  }
  in_ECX[0x11] = 0xf;
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  *in_ECX = &PTR_FUN_009bf514;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005aeae0 @ 0x005aeae0 ====

void FUN_005aeae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1a98;
  return;
}


// ==== FUN_005aeb00 @ 0x005aeb00 ====

void FUN_005aeb00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b655c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005aeb20 @ 0x005aeb20 ====

undefined1 FUN_005aeb20(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x78);
}


// ==== FUN_005aeb30 @ 0x005aeb30 ====

void FUN_005aeb30(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x78) = param_1;
  return;
}


// ==== FUN_005aeb40 @ 0x005aeb40 ====

void FUN_005aeb40(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_005aeb50 @ 0x005aeb50 ====

void FUN_005aeb50(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x60) = param_1;
  *(undefined4 *)(in_ECX + 100) = param_2;
  *(undefined4 *)(in_ECX + 0x68) = param_3;
  return;
}


// ==== FUN_005aeb70 @ 0x005aeb70 ====

void FUN_005aeb70(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined1 *)(in_ECX + 0x79) = 1;
  return;
}


// ==== FUN_005aeb80 @ 0x005aeb80 ====

void FUN_005aeb80(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x6c);
  param_1[1] = *(undefined4 *)(in_ECX + 0x70);
  param_1[2] = *(undefined4 *)(in_ECX + 0x74);
  return;
}


// ==== FUN_005aeba0 @ 0x005aeba0 ====

undefined1 FUN_005aeba0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x79);
}


// ==== FUN_005aebb0 @ 0x005aebb0 ====

void FUN_005aebb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1afc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005aebd0 @ 0x005aebd0 ====

void FUN_005aebd0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x79) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(in_ECX + 0x7c);
  return;
}


// ==== FUN_005aebf0 @ 0x005aebf0 ====

bool FUN_005aebf0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_10 [16];
  
  uVar1 = (**(code **)(*in_ECX + 0x40))(local_10,param_1);
  iVar2 = FUN_0040d570(uVar1);
  return iVar2 != 1;
}


// ==== FUN_005aec20 @ 0x005aec20 ====

void FUN_005aec20(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_8 = *(float *)(in_ECX + 0x6c) - *(float *)(in_ECX + 0x84);
  local_4 = *(float *)(in_ECX + 0x74) - *(float *)(in_ECX + 0x84);
  local_10 = *(float *)(in_ECX + 0x84) + *(float *)(in_ECX + 0x6c);
  local_c = *(float *)(in_ECX + 0x84) + *(float *)(in_ECX + 0x74);
  FUN_004a8890(&local_8,&local_10,param_2);
  return;
}


// ==== FUN_005aece0 @ 0x005aece0 ====

void FUN_005aece0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1b4c;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  FUN_005caa30();
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x17] = 0;
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  return;
}


// ==== FUN_005aed20 @ 0x005aed20 ====

void FUN_005aed20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1b4c;
  if (in_ECX[0x36] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x36]);
    in_ECX[0x36] = 0;
  }
  if (in_ECX[0x37] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x37]);
    in_ECX[0x37] = 0;
  }
  FUN_005caa70();
  *in_ECX = &PTR_FUN_009c1afc;
  return;
}


// ==== FUN_005aed80 @ 0x005aed80 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005aed80(void)

{
  float *pfVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  float10 fVar11;
  float fVar12;
  undefined1 auStack_e6 [10];
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  undefined4 local_c0 [16];
  undefined1 local_80 [64];
  undefined4 local_40 [16];
  
  FUN_005ba1f0(local_c0);
  piVar2 = *(int **)(in_ECX + 200);
  if (*piVar2 != 0) {
    uVar6 = piVar2[0x10];
    uVar8 = *(uint *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x58);
    if (uVar6 == 0) {
      if ((char)piVar2[0xf] == '\x01') {
        uVar6 = *(uint *)(in_ECX + 0xd4);
        uVar8 = *(uint *)(in_ECX + 0x5c);
      }
      else {
        uVar6 = *(uint *)(in_ECX + 0x7c);
      }
    }
    if (piVar2[0x11] != 0) {
      uVar8 = uVar8 % uVar6;
    }
    fVar3 = (float)(int)uVar8;
    if ((int)uVar8 < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    fVar4 = (float)(int)uVar6;
    if ((int)uVar6 < 0) {
      fVar4 = fVar4 + _DAT_0099d104;
    }
    fVar12 = fVar3 / fVar4;
    if (DAT_0099d080 <= fVar3 / fVar4) {
      fVar12 = DAT_0099d080;
    }
    FUN_005ca8b0(fVar12,0x3f800000,0);
    FUN_005ca9e0(**(undefined4 **)(in_ECX + 200),local_80);
    thunk_FUN_0079ee7b(local_40,local_80,local_c0);
    puVar9 = local_40;
    puVar10 = local_c0;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
  }
  if (*(char *)(in_ECX + 0x125) == '\0') {
    fStack_d0 = *(float *)(in_ECX + 0x94) + *(float *)(in_ECX + 0x60);
    fStack_cc = *(float *)(in_ECX + 0x98) + *(float *)(in_ECX + 100);
    fStack_c8 = *(float *)(in_ECX + 0x9c) + *(float *)(in_ECX + 0x68);
    fStack_dc = fStack_d0;
    fStack_d8 = fStack_cc;
    fStack_d4 = fStack_c8;
  }
  else {
    fStack_d0 = *(float *)(in_ECX + 0x60);
    fStack_cc = *(float *)(in_ECX + 100);
    fStack_c8 = *(float *)(in_ECX + 0x68);
  }
  fStack_c4 = DAT_0099d080;
  thunk_FUN_0079ebf5(&fStack_d0,&fStack_d0);
  pfVar1 = (float *)(in_ECX + 0x6c);
  *pfVar1 = fStack_dc;
  *(float *)(in_ECX + 0x70) = fStack_d8;
  *(float *)(in_ECX + 0x74) = fStack_d4;
  if (*(char *)(in_ECX + 0x125) != '\0') {
    *pfVar1 = *(float *)(in_ECX + 0x94) + *pfVar1;
    *(float *)(in_ECX + 0x70) = *(float *)(in_ECX + 0x98) + *(float *)(in_ECX + 0x70);
    *(float *)(in_ECX + 0x74) = *(float *)(in_ECX + 0x9c) + *(float *)(in_ECX + 0x74);
  }
  uVar5 = FUN_005b94b0(auStack_e6 + -0xe);
  fVar11 = (float10)FUN_0040d5f0(uVar5);
  *(float *)(in_ECX + 0x120) = (float)fVar11;
  return;
}


// ==== FUN_005aefe0 @ 0x005aefe0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005aefe0(void)

{
  int iVar1;
  float fVar2;
  char cVar3;
  uint uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x124) != '\x01') {
    if (*(int **)(in_ECX + 0xdc) == (int *)0x0) {
      cVar3 = (**(code **)(**(int **)(in_ECX + 0xd8) + 0x2c))();
      if (cVar3 == '\0') {
        return 0;
      }
      uVar4 = FUN_004b3b40();
      *(uint *)(in_ECX + 0xd0) = uVar4;
      if (1 < uVar4) {
        iVar1 = **(int **)(in_ECX + 0xc4);
        cVar3 = '\0';
        if (iVar1 != 0) {
          cVar3 = (iVar1 != 1) + '\x01';
        }
        fVar2 = (float)(int)uVar4;
        if ((int)uVar4 < 0) {
          fVar2 = fVar2 + _DAT_0099d104;
        }
        FUN_0081d860(cVar3,0,fVar2,(*(int **)(in_ECX + 0xc4))[0x10]);
      }
    }
    else {
      cVar3 = (**(code **)(**(int **)(in_ECX + 0xdc) + 0x2c))();
      if (cVar3 == '\0') {
        return 0;
      }
    }
    *(undefined1 *)(in_ECX + 0x124) = 1;
  }
  return 1;
}


// ==== FUN_005af080 @ 0x005af080 ====

void FUN_005af080(int *param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x58) <= *(uint *)(in_ECX + 0x5c)) {
    cVar2 = FUN_005aefe0();
    if ((cVar2 != '\0') && (0.0 < *(float *)(in_ECX + 0x84))) {
      puVar3 = (undefined4 *)(**(code **)(*param_1 + 0xb4))();
      uVar1 = *(undefined4 *)(in_ECX + 0x74);
      *puVar3 = *(undefined4 *)(in_ECX + 0x6c);
      puVar3[1] = uVar1;
      puVar3[6] = *(undefined4 *)(*(int *)(in_ECX + 0xc4) + 4);
      puVar3[5] = *(undefined4 *)(in_ECX + 0xa0);
      puVar3[2] = *(undefined4 *)(in_ECX + 0x84);
      puVar3[4] = *(undefined4 *)(in_ECX + 0x88);
      iVar4 = *(int *)(in_ECX + 0xdc);
      if (iVar4 == 0) {
        iVar4 = FUN_004b3ff0(*(undefined4 *)(in_ECX + 0xcc));
      }
      puVar3[3] = iVar4;
      (**(code **)(*param_1 + 0x8c))(puVar3);
    }
  }
  return;
}


// ==== FUN_005af140 @ 0x005af140 ====

void FUN_005af140(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xc);
  uVar2 = *(undefined4 *)(in_ECX + 0x70);
  uVar3 = *(undefined4 *)(in_ECX + 0x74);
  *param_1 = *(undefined4 *)(in_ECX + 0x6c);
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  return;
}


// ==== FUN_005af180 @ 0x005af180 ====

void FUN_005af180(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  *(undefined1 *)(in_ECX + 0x124) = 0;
  *(undefined4 *)(in_ECX + 0xa0) = 0xff000000;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined4 *)(in_ECX + 0xc4) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0xcc) = 0;
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0x84);
  iVar1 = *(int *)(param_1 + 0x20);
  if (*(int *)(iVar1 + 0x1c) != 0) {
    uVar3 = FUN_005aa1b0(iVar1 + 8);
    *(undefined4 *)(in_ECX + 0xdc) = uVar3;
    *(undefined4 *)(in_ECX + 0xd0) = 1;
    return;
  }
  if (*(int *)(iVar1 + 0x38) != 0) {
    uVar3 = FUN_005aa220(iVar1 + 0x24);
    *(undefined4 *)(in_ECX + 0xd8) = uVar3;
    *(undefined4 *)(in_ECX + 0xd0) = 1;
    return;
  }
  FUN_00401830(s_false_009c1aa4);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005af280 @ 0x005af280 ====

void FUN_005af280(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_005af180(param_1);
  *(undefined4 *)(in_ECX + 4) = param_2;
  return;
}


// ==== FUN_005af2a0 @ 0x005af2a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005af2a0(float param_1)

{
  float fVar1;
  int iVar2;
  float *pfVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  uint uVar6;
  int in_ECX;
  int iVar7;
  float10 fVar8;
  float fVar9;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  uVar6 = (uint)param_1;
  if ((uint)param_1 < *(uint *)(in_ECX + 0x80)) {
    *(uint *)(in_ECX + 0x80) = *(uint *)(in_ECX + 0x80) - (int)param_1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x80) = 0;
  }
  iVar7 = *(int *)(in_ECX + 0x80);
  iVar2 = *(int *)(in_ECX + 0x7c);
  fVar9 = (float)iVar7;
  if (iVar7 < 0) {
    fVar9 = fVar9 + _DAT_0099d104;
  }
  fVar1 = (float)iVar2;
  if (iVar2 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar9 = DAT_0099d080 - fVar9 / fVar1;
  if (DAT_0099d080 <= fVar9) {
    fVar9 = DAT_0099d080;
  }
  else {
    if (fVar9 < 0.0) {
      fVar9 = 0.0;
    }
  }
  iVar2 = iVar2 - iVar7;
  iVar7 = (int)(fVar9 * DAT_009bf5a0);
  param_1 = DAT_0099d080;
  local_1c = DAT_0099d080;
  local_18 = DAT_0099d080;
  local_14 = DAT_0099d080;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x58) != 0) {
    fVar8 = (float10)FUN_005aa2a0(iVar7,iVar2);
    param_1 = (float)fVar8;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0x90) != 0) {
    pfVar3 = (float *)FUN_005aa3a0(&local_10,iVar7,iVar2);
    local_1c = *pfVar3;
    local_18 = pfVar3[1];
    local_14 = pfVar3[2];
  }
  local_10 = local_1c;
  local_c = local_18;
  local_8 = local_14;
  local_4 = param_1;
  uVar4 = FUN_0040ead0(&local_10);
  *(undefined4 *)(in_ECX + 0xa0) = uVar4;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x40) == 0) {
    *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(in_ECX + 0x120);
  }
  else {
    fVar8 = (float10)FUN_005aa2a0(iVar7,iVar2);
    *(float *)(in_ECX + 0x88) =
         (float)(fVar8 * (float10)_DAT_00af4ef8 + (float10)*(float *)(in_ECX + 0x120));
  }
  fVar9 = DAT_0099d080;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x70) != 0) {
    FUN_005aa3a0(&local_1c,iVar7,iVar2);
    fVar9 = local_1c;
  }
  *(float *)(in_ECX + 0x84) = *(float *)(in_ECX + 0xc) * fVar9;
  if (*(int *)(*(int *)(in_ECX + 8) + 0xb0) != 0) {
    puVar5 = (undefined4 *)FUN_005aa3a0(&local_10,iVar7,iVar2);
    *(undefined4 *)(in_ECX + 0x60) = *puVar5;
    *(undefined4 *)(in_ECX + 100) = puVar5[1];
    *(undefined4 *)(in_ECX + 0x68) = puVar5[2];
  }
  fVar9 = local_18;
  if (*(char *)(in_ECX + 0x125) == '\0') {
    iVar7 = *(int *)(in_ECX + 4);
    local_1c = *(float *)(iVar7 + 0xbc);
    local_18 = *(float *)(iVar7 + 0xc4);
    local_14 = local_18;
    if (((local_1c != 0.0) || (*(float *)(iVar7 + 0xc0) != 0.0)) ||
       (fVar9 = *(float *)(iVar7 + 0xc0), local_18 != 0.0)) {
      fVar8 = (float10)FUN_0040d5f0(&local_1c);
      *(float *)(in_ECX + 0x88) = (float)(fVar8 + (float10)_DAT_009c1af4);
      fVar9 = local_18;
    }
  }
  local_18 = fVar9;
  if ((1 < *(uint *)(in_ECX + 0xd0)) && (*(int *)(*(int *)(in_ECX + 0xc4) + 0x40) != 0)) {
    FUN_0081d6b0(uVar6);
    uVar6 = FUN_00802534();
    *(uint *)(in_ECX + 0xcc) = uVar6;
    if (*(uint *)(in_ECX + 0xd0) <= uVar6) {
      *(uint *)(in_ECX + 0xcc) = *(uint *)(in_ECX + 0xd0) - 1;
    }
  }
  return;
}


// ==== FUN_005af550 @ 0x005af550 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005af550(int param_1,float param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  float10 fVar4;
  
  fVar1 = param_2 * DAT_009b012c;
  in_ECX[2] = param_1;
  in_ECX[0x15] = *(int *)(param_1 + 8);
  in_ECX[0x18] = *(int *)(param_1 + 0x18);
  in_ECX[0x19] = *(int *)(param_1 + 0x1c);
  in_ECX[0x1a] = *(int *)(param_1 + 0x20);
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x33] = 0;
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  *(undefined1 *)((int)in_ECX + 0x125) = *(undefined1 *)(param_1 + 0x31);
  in_ECX[0x35] = (int)ROUND(fVar1);
  iVar2 = FUN_00802534();
  in_ECX[0x16] = iVar2;
  iVar3 = *(int *)(param_1 + 0x10) - *(int *)(param_1 + 0xc);
  fVar1 = (float)iVar3;
  if (iVar3 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  iVar3 = (int)ROUND(fVar1 * param_2);
  if (*(char *)(param_1 + 0x32) != '\0') {
    fVar1 = (float)iVar2;
    if (iVar2 < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar4 = (float10)FUN_0040d0a0(0,fVar1 * DAT_0099d0ec);
    in_ECX[0x16] = (int)ROUND(fVar4 * (float10)DAT_009b012c);
  }
  iVar2 = param_3 - in_ECX[0x16];
  in_ECX[0x1f] = iVar3;
  if (iVar2 < 0) {
    in_ECX[0x20] = iVar3;
  }
  else if (iVar2 < iVar3) {
    in_ECX[0x20] = iVar3 - iVar2;
  }
  else {
    in_ECX[0x20] = 0;
  }
  iVar2 = *(int *)(in_ECX[2] + 0x34);
  in_ECX[0x32] = iVar2;
  if ((*(int *)(iVar2 + 0x18) != 0) && (*(int *)(iVar2 + 0x34) != 0)) {
    FUN_005ca850(iVar2 + 4);
    FUN_005caad0();
    FUN_005cab40(in_ECX[0x32] + 0x20);
  }
  in_ECX[0x17] = param_3;
  (**(code **)(*in_ECX + 0x44))();
  FUN_005af2a0(0);
  return;
}


// ==== FUN_005af730 @ 0x005af730 ====

uint FUN_005af730(int param_1)

{
  uint in_EAX;
  int *in_ECX;
  
  if (in_ECX[0x20] == 0) {
    *(undefined1 *)((int)in_ECX + 0x79) = 1;
    return in_EAX & 0xffffff00;
  }
  in_ECX[0x17] = in_ECX[0x17] + param_1;
  if ((uint)in_ECX[0x17] < (uint)in_ECX[0x16]) {
    return CONCAT31((int3)((uint)in_ECX[0x17] >> 8),1);
  }
  (**(code **)(*in_ECX + 0x44))();
  FUN_005af2a0(param_1);
  return (uint)(*(char *)((int)in_ECX + 0x79) == '\0');
}


// ==== FUN_005af780 @ 0x005af780 ====

void FUN_005af780(byte param_1)

{
  void *in_ECX;
  
  FUN_005aed20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005af7a0 @ 0x005af7a0 ====

void FUN_005af7a0(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_2;
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  *(undefined4 **)(in_ECX + 0x7c) = puVar1;
  *(undefined4 *)(in_ECX + 0xc) = *puVar1;
  return;
}


// ==== FUN_005af7c0 @ 0x005af7c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005af7c0(int param_1,float param_2,int param_3)

{
  float fVar1;
  int *in_ECX;
  float10 fVar2;
  
  in_ECX[2] = param_1;
  in_ECX[0x15] = *(int *)(param_1 + 8);
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  in_ECX[0x18] = *(int *)(param_1 + 0x18);
  in_ECX[0x19] = *(int *)(param_1 + 0x1c);
  in_ECX[0x1a] = *(int *)(param_1 + 0x20);
  fVar1 = (float)*(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[0x16] = (int)ROUND(fVar1 * param_2);
  fVar1 = (float)*(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x10) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[0x24] = (int)ROUND(fVar1 * param_2);
  if (*(char *)(param_1 + 0x32) != '\0') {
    fVar1 = (float)in_ECX[0x16];
    if (in_ECX[0x16] < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar2 = (float10)FUN_0040d0a0(0,fVar1 * DAT_0099d0ec);
    in_ECX[0x16] = (int)ROUND(fVar2 * (float10)DAT_009b012c);
  }
  in_ECX[0x17] = param_3;
  *(undefined1 *)(in_ECX + 0x23) = 0;
  (**(code **)(*in_ECX + 0x44))();
  return;
}


// ==== FUN_005af8d0 @ 0x005af8d0 ====

void FUN_005af8d0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x79) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined1 *)(in_ECX + 0x8c) = 0;
  return;
}


// ==== FUN_005af8e0 @ 0x005af8e0 ====

bool FUN_005af8e0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_10 [16];
  
  uVar1 = (**(code **)(*in_ECX + 0x40))(local_10,param_1);
  iVar2 = FUN_0040d570(uVar1);
  return iVar2 != 1;
}


// ==== FUN_005af910 @ 0x005af910 ====

void FUN_005af910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1bc4;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x17] = 0;
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  return;
}


// ==== FUN_005af930 @ 0x005af930 ====

void FUN_005af930(void)

{
  int in_ECX;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  FUN_005ba1f0(local_40,*(undefined4 *)(in_ECX + 0x54));
  local_50 = *(undefined4 *)(in_ECX + 0x60);
  local_4c = *(undefined4 *)(in_ECX + 100);
  local_48 = *(undefined4 *)(in_ECX + 0x68);
  local_44 = DAT_0099d080;
  thunk_FUN_0079ebf5(&local_50,&local_50,local_40);
  *(undefined4 *)(in_ECX + 0x6c) = uStack_5c;
  *(undefined4 *)(in_ECX + 0x70) = uStack_58;
  *(undefined4 *)(in_ECX + 0x74) = uStack_54;
  return;
}


// ==== FUN_005af9d0 @ 0x005af9d0 ====

void FUN_005af9d0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xc);
  uVar2 = *(undefined4 *)(in_ECX + 0x70);
  uVar3 = *(undefined4 *)(in_ECX + 0x74);
  *param_1 = *(undefined4 *)(in_ECX + 0x6c);
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  return;
}


// ==== FUN_005afa10 @ 0x005afa10 ====

void FUN_005afa10(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *in_ECX;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  undefined4 auStack_a4 [7];
  undefined4 auStack_88 [8];
  undefined4 uStack_68;
  undefined4 *puStack_64;
  uint uStack_50;
  undefined4 auStack_44 [4];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 auStack_28 [4];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (in_ECX[1] == 0) {
    return;
  }
  if (param_1 == 0) {
    puStack_64 = (undefined4 *)0x5afbb4;
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar3 == (undefined4 *)0x0) {
      return;
    }
    puStack_64 = (undefined4 *)0x5afbc6;
    uVar4 = (**(code **)(*(int *)(in_ECX[1] + 0x20) + 0xc))();
    puVar3[1] = uVar4;
    *puVar3 = &PTR_FUN_009c1bac;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    puStack_64 = (undefined4 *)0x5afa3e;
    (**(code **)(*in_ECX + 0x44))();
    in_ECX[0x20] = in_ECX[0x1b];
    in_ECX[0x21] = in_ECX[0x1c];
    iVar1 = in_ECX[0x1f];
    in_ECX[0x22] = in_ECX[0x1d];
    auStack_44[0]._0_1_ = *(undefined1 *)(iVar1 + 0x40);
    auStack_44[2] = *(undefined4 *)(iVar1 + 0x48);
    uStack_34 = *(undefined4 *)(iVar1 + 0x50);
    uStack_30 = *(undefined4 *)(iVar1 + 0x54);
    uStack_2c = *(undefined4 *)(iVar1 + 0x58);
    iVar6 = in_ECX[0x24] - in_ECX[0x16];
    auStack_44[1] = *(undefined4 *)(iVar1 + 0x44);
    auStack_44[3] = *(undefined4 *)(iVar1 + 0x4c);
    uVar4 = *(undefined4 *)(iVar1 + 0x38);
    auStack_28[0]._0_1_ = *(undefined1 *)(iVar1 + 0xc);
    uStack_50 = (uint)*(byte *)(iVar1 + 0x34);
    uVar14 = *(undefined4 *)(iVar1 + 0x3c);
    auStack_28[1] = *(undefined4 *)(iVar1 + 0x10);
    auStack_28[3] = *(undefined4 *)(iVar1 + 0x1c);
    auStack_28[2] = *(undefined4 *)(iVar1 + 0x14);
    uStack_18 = *(undefined4 *)(iVar1 + 0x20);
    uStack_14 = *(undefined4 *)(iVar1 + 0x24);
    uStack_10 = *(undefined4 *)(iVar1 + 0x18);
    uStack_c = *(undefined4 *)(iVar1 + 0x28);
    uStack_8 = *(undefined4 *)(iVar1 + 0x2c);
    uStack_4 = *(undefined4 *)(iVar1 + 0x30);
    puStack_64 = (undefined4 *)0x5afb24;
    iVar1 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar1 == 0) {
      return;
    }
    puVar3 = (undefined4 *)in_ECX[0x1f];
    iVar1 = in_ECX[1];
    puVar7 = auStack_28;
    puVar8 = auStack_88;
    for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    puVar7 = auStack_44;
    puVar8 = auStack_a4;
    for (iVar5 = 7; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    uVar13 = puVar3[1];
    uVar12 = *puVar3;
    uVar11 = puVar3[2];
    iVar5 = in_ECX[0x1b];
    iVar9 = in_ECX[0x1c];
    iVar10 = in_ECX[0x1d];
    uVar2 = (**(code **)(*(int *)(iVar1 + 0x20) + 0xc))
                      (iVar5,iVar9,iVar10,uVar11,uVar12,uVar13,iVar6,uStack_50,uVar4,uVar14);
    puVar3 = (undefined4 *)
             FUN_005afc80(uVar2,iVar5,iVar9,iVar10,uVar11,uVar12,uVar13,iVar6,uStack_50,uVar4,uVar14
                         );
  }
  if (puVar3 != (undefined4 *)0x0) {
    uStack_68 = 0x5afbdb;
    puStack_64 = puVar3;
    FUN_00797a20();
  }
  return;
}


// ==== FUN_005afbf0 @ 0x005afbf0 ====

bool FUN_005afbf0(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x5c) + param_1;
  if (*(uint *)(in_ECX + 0x5c) < *(uint *)(in_ECX + 0x58)) {
    return true;
  }
  if ((*(uint *)(in_ECX + 0x90) <= *(uint *)(in_ECX + 0x5c)) && (*(uint *)(in_ECX + 0x90) < 1000000)
     ) {
    FUN_005afa10(0);
    *(undefined1 *)(in_ECX + 0x79) = 1;
  }
  if (*(char *)(in_ECX + 0x8c) == '\0') {
    FUN_005afa10(1);
    *(undefined1 *)(in_ECX + 0x8c) = 1;
  }
  return *(char *)(in_ECX + 0x79) == '\0';
}


// ==== FUN_005afc50 @ 0x005afc50 ====

void FUN_005afc50(void)

{
  int in_ECX;
  
  FUN_005afa10(0);
  *(undefined1 *)(in_ECX + 0x79) = 1;
  return;
}


// ==== FUN_005afc60 @ 0x005afc60 ====

void FUN_005afc60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1bc4;
  FUN_005afa10(0);
  *in_ECX = &PTR_FUN_009c1afc;
  return;
}


// ==== FUN_005afc80 @ 0x005afc80 ====

void FUN_005afc80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 uStack0000004c;
  
  in_ECX[1] = param_1;
  in_ECX[3] = param_5;
  in_ECX[2] = param_8;
  in_ECX[6] = param_2;
  in_ECX[7] = param_3;
  in_ECX[8] = param_4;
  in_ECX[9] = param_9;
  in_ECX[10] = param_10;
  in_ECX[0xb] = param_11;
  puVar2 = &param_12;
  puVar3 = in_ECX + 0xc;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = &uStack0000004c;
  puVar3 = in_ECX + 0x13;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  in_ECX[4] = param_6;
  *in_ECX = &PTR_FUN_009c1b98;
  in_ECX[5] = param_7;
  return;
}


// ==== FUN_005afd10 @ 0x005afd10 ====

undefined4 FUN_005afd10(void)

{
  return 0x60040010;
}


// ==== FUN_005afd20 @ 0x005afd20 ====

undefined4 FUN_005afd20(void)

{
  return 0x60040011;
}


// ==== FUN_005afd30 @ 0x005afd30 ====

void FUN_005afd30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1bc4;
  FUN_005afa10(0);
  *in_ECX = &PTR_FUN_009c1afc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005afd60 @ 0x005afd60 ====

void FUN_005afd60(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x88) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0xac) = 0;
  *(undefined4 *)(in_ECX + 0x94) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xb0) = 0;
  *(undefined4 *)(in_ECX + 0xb4) = 0;
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0x9c) = 0;
  uVar2 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0xa0) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x18);
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0xa4) = *puVar1;
  *(undefined4 *)(in_ECX + 0xa8) = puVar1[1];
  *(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0xb8) = uVar2;
  *(undefined4 *)(in_ECX + 0xbc) = uVar2;
  *(undefined4 *)(in_ECX + 0xc0) = uVar2;
  *(undefined4 *)(in_ECX + 0xd4) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0xdc) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0xd0) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x90) = *(undefined4 *)(*(int *)(param_1 + 0x1c) + 4);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0x98);
  return;
}


// ==== FUN_005afe60 @ 0x005afe60 ====

undefined4 FUN_005afe60(void)

{
  char cVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x7f) == '\x01') {
    return 1;
  }
  cVar1 = (**(code **)(**(int **)(in_ECX + 0x1e8) + 0x2c))();
  if ((cVar1 == '\0') || (cVar1 = (**(code **)(**(int **)(in_ECX + 0x1ec) + 0x2c))(), cVar1 == '\0')
     ) {
    return 0;
  }
  *(undefined1 *)(in_ECX + 0x7f) = 1;
  return 1;
}


// ==== FUN_005afea0 @ 0x005afea0 ====

void FUN_005afea0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x79) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(in_ECX + 0x88);
  return;
}


// ==== FUN_005afec0 @ 0x005afec0 ====

bool FUN_005afec0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_10 [16];
  
  uVar1 = (**(code **)(*in_ECX + 0x40))(local_10,param_1);
  iVar2 = FUN_0040d570(uVar1);
  return iVar2 != 1;
}


// ==== FUN_005afef0 @ 0x005afef0 ====

void FUN_005afef0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_8 = *(float *)(in_ECX + 0x6c) - DAT_0099d080;
  local_4 = *(float *)(in_ECX + 0x74) - DAT_0099d080;
  local_10 = *(float *)(in_ECX + 0x6c) + DAT_0099d080;
  local_c = *(float *)(in_ECX + 0x74) + DAT_0099d080;
  FUN_004a8890(&local_8,&local_10,param_2);
  return;
}


// ==== FUN_005affa0 @ 0x005affa0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005affa0(void)

{
  int *piVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  uint uVar4;
  float *pfVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fStack_90;
  float afStack_8c [3];
  undefined1 local_80 [64];
  undefined1 local_40 [64];
  
  FUN_005ba1f0(local_80,*(undefined4 *)(in_ECX + 0x54));
  piVar1 = *(int **)(in_ECX + 0xd8);
  if (*piVar1 != 0) {
    uVar2 = piVar1[0x10];
    uVar4 = *(uint *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x58);
    if (uVar2 == 0) {
      if ((char)piVar1[0xf] == '\x01') {
        uVar2 = *(uint *)(in_ECX + 0xe4);
        uVar4 = *(uint *)(in_ECX + 0x5c);
      }
      else {
        uVar2 = *(uint *)(in_ECX + 0x88);
      }
    }
    if (piVar1[0x11] != 0) {
      uVar4 = uVar4 % uVar2;
    }
    fVar7 = (float)(int)uVar4;
    if ((int)uVar4 < 0) {
      fVar7 = fVar7 + _DAT_0099d104;
    }
    fVar8 = (float)(int)uVar2;
    if ((int)uVar2 < 0) {
      fVar8 = fVar8 + _DAT_0099d104;
    }
    fVar9 = fVar7 / fVar8;
    if (DAT_0099d080 <= fVar7 / fVar8) {
      fVar9 = DAT_0099d080;
    }
    FUN_005ca8b0(fVar9,0x3f800000,0);
    FUN_005ca9e0(**(undefined4 **)(in_ECX + 0xd8),local_40);
    thunk_FUN_0079ee7b(local_80,local_40,local_80);
  }
  if (*(char *)(in_ECX + 0x1d4) == '\0') {
    fVar7 = *(float *)(in_ECX + 0x60) + *(float *)(in_ECX + 0xc4);
    fVar8 = *(float *)(in_ECX + 100) + *(float *)(in_ECX + 200);
    fVar9 = *(float *)(in_ECX + 0x68) + *(float *)(in_ECX + 0xcc);
  }
  else {
    fVar7 = *(float *)(in_ECX + 0x60);
    fVar8 = *(float *)(in_ECX + 100);
    fVar9 = *(float *)(in_ECX + 0x68);
  }
  afStack_8c[2] = DAT_0099d080;
  fStack_90 = fVar7;
  afStack_8c[0] = fVar8;
  afStack_8c[1] = fVar9;
  thunk_FUN_0079ebf5(&fStack_90,&fStack_90,local_80);
  pfVar5 = (float *)(in_ECX + 0x6c);
  *pfVar5 = fVar7;
  *(float *)(in_ECX + 0x70) = fVar8;
  *(float *)(in_ECX + 0x74) = fVar9;
  if (*(char *)(in_ECX + 0x1d4) != '\0') {
    *pfVar5 = *pfVar5 + *(float *)(in_ECX + 0xc4);
    *(float *)(in_ECX + 0x70) = *(float *)(in_ECX + 200) + *(float *)(in_ECX + 0x70);
    *(float *)(in_ECX + 0x74) = *(float *)(in_ECX + 0xcc) + *(float *)(in_ECX + 0x74);
  }
  pfVar5 = afStack_8c;
  pfVar6 = (float *)(in_ECX + 300);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *pfVar6 = *pfVar5;
    pfVar5 = pfVar5 + 1;
    pfVar6 = pfVar6 + 1;
  }
  *(undefined4 *)(in_ECX + 0x164) = 0;
  *(undefined4 *)(in_ECX + 0x160) = 0;
  *(undefined4 *)(in_ECX + 0x15c) = 0;
  return;
}


