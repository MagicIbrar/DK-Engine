// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x5e0000-0x5effff

// ==== FUN_005e0000 @ 0x005e0000 ====

int FUN_005e0000(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_005e0010 @ 0x005e0010 ====

int FUN_005e0010(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_005e0020 @ 0x005e0020 ====

undefined4 FUN_005e0020(undefined4 *param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = *param_1;
  local_c = param_1[1];
  local_8 = param_1[2];
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x110) + 0x30))(&local_10);
  if (piVar1 == (int *)0x0) {
    return *(undefined4 *)(in_ECX + 0x118);
  }
  return *(undefined4 *)(*piVar1 + 0xc);
}


// ==== __break @ 0x005e006c ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_005e0070 @ 0x005e0070 ====

bool FUN_005e0070(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = *param_1;
  local_c = param_1[1];
  local_8 = param_1[2];
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x110) + 0x30))(&local_10);
  return iVar1 != 0;
}


// ==== FUN_005e00b0 @ 0x005e00b0 ====

undefined4 FUN_005e00b0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x110) + 8))();
  *(int **)(in_ECX + 0x114) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0xc);
}


// ==== FUN_005e00d0 @ 0x005e00d0 ====

undefined4 FUN_005e00d0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x110) + 0x48))(*(undefined4 *)(in_ECX + 0x114));
  *(int **)(in_ECX + 0x114) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0xc);
}


// ==== FUN_005e0100 @ 0x005e0100 ====

undefined4 FUN_005e0100(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  char unaff_BL;
  
  cVar1 = FUN_005e0070(param_1);
  if (cVar1 != '\0') {
    return 0;
  }
  puVar2 = operator_new(0x134);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar3 = puVar2;
    for (iVar4 = 0x4d; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar3 = *param_1;
      param_1 = param_1 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 0x10c) + 0xc))(1,0);
  *puVar3 = *puVar2;
  puVar3[1] = puVar2[1];
  puVar3[2] = puVar2[2];
  puVar3[3] = puVar2;
  (**(code **)(**(int **)(in_ECX + 0x110) + 0x28))(puVar3);
  if (unaff_BL != '\0') {
    *(undefined4 **)(in_ECX + 0x118) = puVar2;
  }
  return 1;
}


// ==== FUN_005e0190 @ 0x005e0190 ====

void FUN_005e0190(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983278;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c3bc0;
  in_ECX[0x46] = 0;
  local_4 = 0;
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[0x44] + 8))();
  while( true ) {
    if (piVar1 == (int *)0x0) {
      if ((undefined4 *)in_ECX[0x44] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[0x44])(1);
      }
      in_ECX[0x44] = 0;
      if ((undefined4 *)in_ECX[0x43] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[0x43])(1);
      }
      in_ECX[0x43] = 0;
      *in_ECX = &PTR_FUN_009c3a84;
      ExceptionList = pvStack_c;
      return;
    }
    if (*(void **)(*piVar1 + 0xc) != (void *)0x0) break;
    piVar1 = (int *)(**(code **)(*(int *)in_ECX[0x44] + 0x40))(piVar1);
  }
  _free(*(void **)(*piVar1 + 0xc));
  return;
}


// ==== FUN_005e0240 @ 0x005e0240 ====

void FUN_005e0240(undefined4 *param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 8);
    *(char *)(uVar2 + 0xc + in_ECX) = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_005e0270 @ 0x005e0270 ====

void FUN_005e0270(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009832a0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3bc0;
  in_ECX[1] = 0x11;
  *(undefined2 *)(in_ECX + 2) = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  local_4 = 0;
  in_ECX[0x45] = 0;
  pvVar1 = operator_new(0x1c18);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e0410();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x43] = uVar2;
  pvVar1 = operator_new(0x2028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e08f0(in_ECX[0x43]);
  }
  in_ECX[0x44] = uVar2;
  in_ECX[0x46] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e0330 @ 0x005e0330 ====

void FUN_005e0330(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3aa4;
  return;
}


// ==== FUN_005e0340 @ 0x005e0340 ====

void FUN_005e0340(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3afc;
  return;
}


// ==== FUN_005e0350 @ 0x005e0350 ====

void FUN_005e0350(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3b14;
  return;
}


// ==== FUN_005e0360 @ 0x005e0360 ====

void FUN_005e0360(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3aa4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e0380 @ 0x005e0380 ====

void FUN_005e0380(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3afc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e03a0 @ 0x005e03a0 ====

void FUN_005e03a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3b14;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e03c0 @ 0x005e03c0 ====

void FUN_005e03c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3b2c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_005e03e0 @ 0x005e03e0 ====

void FUN_005e03e0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e03c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e0410 @ 0x005e0410 ====

void FUN_005e0410(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983238;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3b34;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c3b2c;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x1c,0x100,(_func_void_void_ptr *)&LAB_005e0400,FUN_006ef6d0);
  in_ECX[0x702] = 0;
  in_ECX[0x702] = in_ECX[0x702] + 0x100;
  in_ECX[0x705] = in_ECX + 2;
  in_ECX[0x703] = 0;
  in_ECX[0x704] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[6] = puVar1 + 9;
    puVar1[7] = 0;
    puVar1[8] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 7;
  } while (iVar2 != 0);
  in_ECX[0x6ff] = 0;
  in_ECX[0x700] = 0;
  in_ECX[0x701] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e04c0 @ 0x005e04c0 ====

undefined4 FUN_005e04c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1c0c);
}


// ==== FUN_005e04d0 @ 0x005e04d0 ====

void FUN_005e04d0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e04f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e04f0 @ 0x005e04f0 ====

void FUN_005e04f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983263;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3b34;
  local_4 = 1;
  if ((void *)in_ECX[0x704] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c3b2c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c3afc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x704]);
  return;
}


// ==== FUN_005e0570 @ 0x005e0570 ====

undefined1 * FUN_005e0570(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined1 *)0x0) {
    if (*(int *)(param_2 + 0x18) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3b48,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x18) = *(int *)(param_2 + 0x18) + param_1;
    return param_2;
  }
  puVar2 = *(undefined1 **)(in_ECX + 0x1c14);
  *(int *)(in_ECX + 0x1c0c) = *(int *)(in_ECX + 0x1c0c) + 1;
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = operator_new(0x1c);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = (undefined1 *)0x0;
    }
    else {
      *puVar2 = 0;
      *(undefined4 *)(puVar2 + 4) = 0x20;
    }
    *(undefined4 *)(puVar2 + 0x14) = *(undefined4 *)(in_ECX + 0x1c10);
    *(undefined1 **)(in_ECX + 0x1c10) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1c14) = *(undefined4 *)(puVar2 + 0x10);
  }
  *(undefined4 *)(puVar2 + 0x10) = 0;
  *(int *)(puVar2 + 0x18) = param_1;
  return puVar2;
}


// ==== FUN_005e0640 @ 0x005e0640 ====

undefined4 FUN_005e0640(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3b48,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x18);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x18);
    }
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x1c14);
    *(int *)(in_ECX + 0x1c0c) = *(int *)(in_ECX + 0x1c0c) + -1;
    *(int *)(in_ECX + 0x1c14) = param_2;
  }
  return 0;
}


// ==== FUN_005e06c0 @ 0x005e06c0 ====

void FUN_005e06c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3bb8;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_005e06e0 @ 0x005e06e0 ====

void FUN_005e06e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009832c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3bdc;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c3bb8;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c3b14;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_005e0760 @ 0x005e0760 ====

undefined4 FUN_005e0760(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3b48,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x2014);
    *(int *)(in_ECX + 0x200c) = *(int *)(in_ECX + 0x200c) + -1;
    *(int *)(in_ECX + 0x2014) = param_2;
  }
  return 0;
}


// ==== FUN_005e07e0 @ 0x005e07e0 ====

void FUN_005e07e0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e06c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e0800 @ 0x005e0800 ====

void FUN_005e0800(byte param_1)

{
  void *in_ECX;
  
  FUN_005e06e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e0820 @ 0x005e0820 ====

void FUN_005e0820(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009832d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3bdc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c3bb8;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x100,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x802] = 0;
  in_ECX[0x802] = in_ECX[0x802] + 0x100;
  in_ECX[0x805] = in_ECX + 2;
  in_ECX[0x803] = 0;
  in_ECX[0x804] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x7ff] = 0;
  in_ECX[0x800] = 0;
  in_ECX[0x801] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e08d0 @ 0x005e08d0 ====

void FUN_005e08d0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e0190();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e08f0 @ 0x005e08f0 ====

void FUN_005e08f0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009832f8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3bf4;
  FUN_005e0820();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e0950 @ 0x005e0950 ====

void FUN_005e0950(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e0970(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e0970 @ 0x005e0970 ====

void FUN_005e0970(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005e0970(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005e0970(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e09b0 @ 0x005e09b0 ====

undefined4 * FUN_005e09b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int *unaff_EBP;
  
  iVar1 = in_ECX + 0x10;
  piVar3 = (int *)(**(code **)(*(int *)(in_ECX + 0x10) + 0xc))(1,0);
  *piVar3 = iVar1;
  piVar3[2] = 0;
  piVar3[3] = 0;
  piVar3[4] = 0;
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (puVar2 == (undefined4 *)0x0) {
    *(int **)(in_ECX + 4) = piVar3;
    return (undefined4 *)0x0;
  }
  iVar4 = FUN_005e0a60(iVar1,*puVar2);
  do {
    if (iVar4 == 0) {
      (**(code **)(*unaff_EBP + 0x10))(1,piVar3);
      return puVar2;
    }
    if (iVar4 < 1) {
      puVar5 = (undefined4 *)puVar2[2];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[2] = piVar3;
        goto LAB_005e0a49;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
LAB_005e0a49:
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_005e0a60(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_005e0a60 @ 0x005e0a60 ====

uint FUN_005e0a60(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = FUN_005e0aa0(param_2);
  if (cVar1 == '\0') {
    cVar1 = FUN_005e0aa0(param_1);
    return (uint)(cVar1 != '\0');
  }
  return 0xffffffff;
}


// ==== FUN_005e0aa0 @ 0x005e0aa0 ====

uint FUN_005e0aa0(byte *param_1)

{
  byte bVar1;
  undefined4 in_EAX;
  uint uVar2;
  byte *in_ECX;
  
  bVar1 = *in_ECX;
  uVar2 = CONCAT31((int3)((uint)in_EAX >> 8),bVar1);
  if (bVar1 < *param_1) {
LAB_005e0aad:
    return CONCAT31((int3)(uVar2 >> 8),1);
  }
  if (bVar1 <= *param_1) {
    uVar2 = *(uint *)(in_ECX + 4);
    if (((int)uVar2 < *(int *)(param_1 + 4)) ||
       (((int)uVar2 <= *(int *)(param_1 + 4) && (*(uint *)(in_ECX + 8) < *(uint *)(param_1 + 8)))))
    goto LAB_005e0aad;
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_005e0ad0 @ 0x005e0ad0 ====

void FUN_005e0ad0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e0af0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e0af0 @ 0x005e0af0 ====

void FUN_005e0af0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005e0af0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005e0af0(param_1[3]);
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


// ==== FUN_005e0b60 @ 0x005e0b60 ====

undefined4 * FUN_005e0b60(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(undefined4 **)(in_ECX + 4) == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  do {
    puVar3 = puVar4;
    cVar1 = FUN_005e0aa0(*puVar3);
    if (cVar1 == '\0') {
      cVar1 = FUN_005e0aa0(param_1);
      if (cVar1 == '\0') {
        FUN_0061f0e0(puVar3,*(undefined4 *)(in_ECX + 4));
        return puVar3;
      }
      iVar2 = 1;
    }
    else {
      iVar2 = -1;
    }
    if (iVar2 < 0) {
      puVar4 = (undefined4 *)puVar3[2];
    }
    else {
      puVar4 = (undefined4 *)puVar3[3];
    }
  } while (puVar4 != (undefined4 *)0x0);
  FUN_0061f0e0(puVar3,*(undefined4 *)(in_ECX + 4));
  return (undefined4 *)0x0;
}


// ==== FUN_005e0bf0 @ 0x005e0bf0 ====

void FUN_005e0bf0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e0c10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e0c10 @ 0x005e0c10 ====

void FUN_005e0c10(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00983323;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3bf4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005e0af0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005e06e0();
  *in_ECX = &PTR_FUN_009c3aa4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e0c90 @ 0x005e0c90 ====

undefined2 * FUN_005e0c90(void)

{
  undefined2 uVar1;
  undefined2 *unaff_retaddr;
  
  uVar1 = (**(code **)(*DAT_00b5af40 + 4))();
  *unaff_retaddr = uVar1;
  return unaff_retaddr;
}


// ==== FUN_005e0cb0 @ 0x005e0cb0 ====

void FUN_005e0cb0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00983372;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x10);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f9ef0();
  }
  local_4 = 0xffffffff;
  *in_ECX = uVar2;
  pvVar1 = operator_new(0x3c);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f9d10();
  }
  local_4 = 0xffffffff;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x44);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f9c50();
  }
  local_4 = 0xffffffff;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f9380();
  }
  local_4 = 0xffffffff;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f8920();
  }
  local_4 = 0xffffffff;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 5;
  if (pvVar1 == (void *)0x0) {
    in_ECX[5] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_005f7ea0();
  in_ECX[5] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e0e00 @ 0x005e0e00 ====

void FUN_005e0e00(void)

{
  int *in_ECX;
  
  if ((int *)in_ECX[5] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[5] + 0x10))(1);
  }
  in_ECX[5] = 0;
  if ((int *)in_ECX[4] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[4] + 0x10))(1);
  }
  in_ECX[4] = 0;
  if ((int *)in_ECX[3] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[3] + 0x10))(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*in_ECX)(1);
  }
  *in_ECX = 0;
  return;
}


// ==== FUN_005e0e70 @ 0x005e0e70 ====

void FUN_005e0e70(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098338f;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3c4c;
  pvVar1 = operator_new(0x18);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_005e0cb0();
  in_ECX[1] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e0ef0 @ 0x005e0ef0 ====

void FUN_005e0ef0(void)

{
  void *_Memory;
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_009833a1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3c4c;
  _Memory = (void *)in_ECX[1];
  local_4 = 0;
  if (_Memory == (void *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_009c3574;
    ExceptionList = pvVar1;
    return;
  }
  FUN_005e0e00();
  _free(_Memory);
  return;
}


// ==== FUN_005e0f60 @ 0x005e0f60 ====

void FUN_005e0f60(byte param_1)

{
  void *in_ECX;
  
  FUN_005e0ef0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e0f90 @ 0x005e0f90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e0f90(void)

{
  undefined4 in_ECX;
  
  _DAT_00b5b014 = in_ECX;
  return;
}


// ==== FUN_005e0fa0 @ 0x005e0fa0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e0fa0(void)

{
  _DAT_00b5b014 = 0;
  return;
}


// ==== FUN_005e10a0 @ 0x005e10a0 ====

void FUN_005e10a0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00983434;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(8);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005ff0a0();
  }
  local_4 = 0xffffffff;
  *in_ECX = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fe5c0();
  }
  local_4 = 0xffffffff;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fdf20();
  }
  local_4 = 0xffffffff;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fd400();
  }
  local_4 = 0xffffffff;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fd0a0();
  }
  local_4 = 0xffffffff;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fcbd0();
  }
  local_4 = 0xffffffff;
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fc210();
  }
  local_4 = 0xffffffff;
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fbae0();
  }
  local_4 = 0xffffffff;
  in_ECX[7] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 8;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fb1d0();
  }
  local_4 = 0xffffffff;
  in_ECX[8] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 9;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fa750();
  }
  local_4 = 0xffffffff;
  in_ECX[9] = uVar2;
  pvVar1 = operator_new(0x50);
  local_4 = 10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fa260();
  }
  local_4 = 0xffffffff;
  in_ECX[10] = uVar2;
  pvVar1 = operator_new(0x18);
  local_4 = 0xb;
  if (pvVar1 == (void *)0x0) {
    in_ECX[0xb] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_005fa0c0();
  in_ECX[0xb] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e12f0 @ 0x005e12f0 ====

void FUN_005e12f0(void)

{
  int *in_ECX;
  
  if ((undefined4 *)in_ECX[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xb])(1);
  }
  in_ECX[0xb] = 0;
  if ((undefined4 *)in_ECX[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[10])(1);
  }
  in_ECX[10] = 0;
  if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[9])(1);
  }
  in_ECX[9] = 0;
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
  }
  in_ECX[8] = 0;
  if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[7])(1);
  }
  in_ECX[7] = 0;
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*in_ECX)(1);
  }
  *in_ECX = 0;
  return;
}


// ==== FUN_005e13c0 @ 0x005e13c0 ====

void FUN_005e13c0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983451;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3c6c;
  pvVar1 = operator_new(0x30);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_005e10a0();
  in_ECX[1] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e1440 @ 0x005e1440 ====

void FUN_005e1440(void)

{
  void *_Memory;
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_00983463;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3c6c;
  _Memory = (void *)in_ECX[1];
  local_4 = 0;
  if (_Memory == (void *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_009c3574;
    ExceptionList = pvVar1;
    return;
  }
  FUN_005e12f0();
  _free(_Memory);
  return;
}


// ==== FUN_005e14b0 @ 0x005e14b0 ====

void FUN_005e14b0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e1440();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e14d0 @ 0x005e14d0 ====

void FUN_005e14d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3cb8;
  return;
}


// ==== FUN_005e14e0 @ 0x005e14e0 ====

void FUN_005e14e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3cb8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e1500 @ 0x005e1500 ====

void FUN_005e1500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3cc8;
  return;
}


// ==== FUN_005e1510 @ 0x005e1510 ====

void FUN_005e1510(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3ce4;
  return;
}


// ==== FUN_005e1520 @ 0x005e1520 ====

void FUN_005e1520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3d3c;
  return;
}


// ==== FUN_005e1530 @ 0x005e1530 ====

void FUN_005e1530(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3cc8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e1550 @ 0x005e1550 ====

void FUN_005e1550(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3ce4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e1570 @ 0x005e1570 ====

void FUN_005e1570(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3d3c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e1590 @ 0x005e1590 ====

undefined4 FUN_005e1590(undefined4 *param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = *param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_005e15c0 @ 0x005e15c0 ====

void FUN_005e15c0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983478;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c3d5c;
  DAT_00b5ab58 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar1)) {
    (**(code **)(*DAT_00b5ab5c + 0x10))(1,*(undefined4 *)(*piVar1 + 4));
  }
  (**(code **)(*(int *)in_ECX[2] + 0x20))();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c3cb8;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005e1670 @ 0x005e1670 ====

void FUN_005e1670(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 unaff_retaddr;
  uint uStack_10c;
  undefined4 *puStack_4;
  
  uStack_10c = 0;
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1);
  *puVar1 = *puStack_4;
  puVar1[1] = unaff_retaddr;
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(puVar1);
  if (iVar2 != 0) {
    uStack_10c = uStack_10c & 0xffffff00;
    uVar3 = FUN_0044a580(&uStack_10c,s__ERROR__Duplicate_Index_in_Quest_009c3c74,
                         *(undefined2 *)puStack_4,*(undefined2 *)((int)puStack_4 + 2));
    FUN_00797b80(uVar3);
  }
  return;
}


// ==== FUN_005e16e0 @ 0x005e16e0 ====

void FUN_005e16e0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009834a0;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3d5c;
  pvVar2 = operator_new(0x14018);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e1800();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x20028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e1db0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab58 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab58 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e17b0 @ 0x005e17b0 ====

void FUN_005e17b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3d54;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x1000,FUN_006ef6d0);
  return;
}


// ==== FUN_005e17d0 @ 0x005e17d0 ====

void FUN_005e17d0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e17b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e1800 @ 0x005e1800 ====

void FUN_005e1800(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009834b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3d6c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c3d54;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x14,0x1000,(_func_void_void_ptr *)&LAB_005e17f0,FUN_006ef6d0);
  in_ECX[0x5002] = 0;
  in_ECX[0x5002] = in_ECX[0x5002] + 0x1000;
  in_ECX[0x5005] = in_ECX + 2;
  in_ECX[0x5003] = 0;
  in_ECX[0x5004] = 0;
  iVar2 = 0xfff;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x4fff] = 0;
  in_ECX[0x5000] = 0;
  in_ECX[0x5001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e18b0 @ 0x005e18b0 ====

undefined4 FUN_005e18b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1400c);
}


// ==== FUN_005e18c0 @ 0x005e18c0 ====

void FUN_005e18c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e18e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e18e0 @ 0x005e18e0 ====

void FUN_005e18e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009834e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3d6c;
  local_4 = 1;
  if ((void *)in_ECX[0x5004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c3d54;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x1000,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c3cc8;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x5004]);
  return;
}


// ==== FUN_005e1960 @ 0x005e1960 ====

undefined2 * FUN_005e1960(int param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined2 *)0x0) {
    if (*(int *)(param_2 + 8) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3d80,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + param_1;
    return param_2;
  }
  puVar2 = *(undefined2 **)(in_ECX + 0x14014);
  *(int *)(in_ECX + 0x1400c) = *(int *)(in_ECX + 0x1400c) + 1;
  if (puVar2 == (undefined2 *)0x0) {
    puVar2 = operator_new(0x14);
    if (puVar2 == (undefined2 *)0x0) {
      puVar2 = (undefined2 *)0x0;
    }
    else {
      *puVar2 = 0;
      puVar2[1] = 0;
    }
    *(undefined4 *)(puVar2 + 6) = *(undefined4 *)(in_ECX + 0x14010);
    *(undefined2 **)(in_ECX + 0x14010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x14014) = *(undefined4 *)(puVar2 + 4);
  }
  *(undefined4 *)(puVar2 + 4) = 0;
  *(int *)(puVar2 + 8) = param_1;
  return puVar2;
}


// ==== FUN_005e1a30 @ 0x005e1a30 ====

undefined4 FUN_005e1a30(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3d80,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x14014);
    *(int *)(in_ECX + 0x1400c) = *(int *)(in_ECX + 0x1400c) + -1;
    *(int *)(in_ECX + 0x14014) = param_2;
  }
  return 0;
}


// ==== FUN_005e1ab0 @ 0x005e1ab0 ====

void FUN_005e1ab0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e15c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e1ad0 @ 0x005e1ad0 ====

void FUN_005e1ad0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3df4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x1000,FUN_006ef6d0);
  return;
}


// ==== FUN_005e1af0 @ 0x005e1af0 ====

void FUN_005e1af0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983503;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3dfc;
  local_4 = 1;
  if ((void *)in_ECX[0x8004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c3df4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x1000,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c3d3c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x8004]);
  return;
}


// ==== FUN_005e1b70 @ 0x005e1b70 ====

undefined4 FUN_005e1b70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2000c);
}


// ==== FUN_005e1b80 @ 0x005e1b80 ====

undefined4 FUN_005e1b80(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3d80,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x20014);
    *(int *)(in_ECX + 0x2000c) = *(int *)(in_ECX + 0x2000c) + -1;
    *(int *)(in_ECX + 0x20014) = param_2;
  }
  return 0;
}


// ==== FUN_005e1c00 @ 0x005e1c00 ====

undefined4 * FUN_005e1c00(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3d80,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x20014);
  *(int *)(in_ECX + 0x2000c) = *(int *)(in_ECX + 0x2000c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x20010);
    *(undefined4 **)(in_ECX + 0x20010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x20014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005e1cc0 @ 0x005e1cc0 ====

void FUN_005e1cc0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e1ad0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e1ce0 @ 0x005e1ce0 ====

void FUN_005e1ce0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e1af0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e1d00 @ 0x005e1d00 ====

void FUN_005e1d00(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983518;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3dfc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c3df4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x1000,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x8002] = 0;
  in_ECX[0x8002] = in_ECX[0x8002] + 0x1000;
  in_ECX[0x8005] = in_ECX + 2;
  in_ECX[0x8003] = 0;
  in_ECX[0x8004] = 0;
  iVar2 = 0xfff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x7fff] = 0;
  in_ECX[0x8000] = 0;
  in_ECX[0x8001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e1db0 @ 0x005e1db0 ====

void FUN_005e1db0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983538;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3e14;
  FUN_005e1d00();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e1e10 @ 0x005e1e10 ====

void FUN_005e1e10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e1e30(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e1e30 @ 0x005e1e30 ====

void FUN_005e1e30(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005e1e30(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005e1e30(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e1e70 @ 0x005e1e70 ====

undefined4 * FUN_005e1e70(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int *unaff_EBP;
  
  iVar1 = in_ECX + 0x10;
  piVar3 = (int *)(**(code **)(*(int *)(in_ECX + 0x10) + 0xc))(1,0);
  *piVar3 = iVar1;
  piVar3[2] = 0;
  piVar3[3] = 0;
  piVar3[4] = 0;
  puVar2 = *(undefined4 **)(in_ECX + 4);
  if (puVar2 == (undefined4 *)0x0) {
    *(int **)(in_ECX + 4) = piVar3;
    return (undefined4 *)0x0;
  }
  iVar4 = FUN_005eebf0(iVar1,*puVar2);
  do {
    if (iVar4 == 0) {
      (**(code **)(*unaff_EBP + 0x10))(1,piVar3);
      return puVar2;
    }
    if (iVar4 < 1) {
      puVar5 = (undefined4 *)puVar2[2];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[2] = piVar3;
        goto LAB_005e1f09;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
LAB_005e1f09:
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_005eebf0(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_005e1f20 @ 0x005e1f20 ====

void FUN_005e1f20(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e1f40(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e1f40 @ 0x005e1f40 ====

void FUN_005e1f40(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005e1f40(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005e1f40(param_1[3]);
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


// ==== FUN_005e1fc0 @ 0x005e1fc0 ====

void FUN_005e1fc0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e1fe0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e1fe0 @ 0x005e1fe0 ====

void FUN_005e1fe0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00983563;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3e14;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005e1f40(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005e1af0();
  *in_ECX = &PTR_FUN_009c3ce4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e2050 @ 0x005e2050 ====

void FUN_005e2050(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005e2055. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_005e2060 @ 0x005e2060 ====

void FUN_005e2060(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005e2065. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_005e2070 @ 0x005e2070 ====

void FUN_005e2070(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005e2075. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_005e2080 @ 0x005e2080 ====

void FUN_005e2080(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005e2085. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_005e2090 @ 0x005e2090 ====

void FUN_005e2090(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009835c3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3ebc;
  pvVar1 = operator_new(0x28018);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e2220();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ab5c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab5c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e2120 @ 0x005e2120 ====

void FUN_005e2120(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009835d5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3ebc;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  DAT_00b5ab5c = 0;
  *in_ECX = &PTR_FUN_009c3e6c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e2180 @ 0x005e2180 ====

void FUN_005e2180(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3e84;
  return;
}


// ==== FUN_005e2190 @ 0x005e2190 ====

void FUN_005e2190(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3e84;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e21c0 @ 0x005e21c0 ====

void FUN_005e21c0(void)

{
  FUN_005ff5a0();
  return;
}


// ==== FUN_005e21d0 @ 0x005e21d0 ====

void FUN_005e21d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3e6c;
  return;
}


// ==== FUN_005e21e0 @ 0x005e21e0 ====

void FUN_005e21e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3e6c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e2200 @ 0x005e2200 ====

void FUN_005e2200(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3e9c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x28,0x1000,(_func_void_void_ptr *)&LAB_005e21b0);
  return;
}


// ==== FUN_005e2220 @ 0x005e2220 ====

void FUN_005e2220(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983578;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3ea4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c3e9c;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x28,0x1000,FUN_005e21c0,(_func_void_void_ptr *)&LAB_005e21b0);
  in_ECX[0xa002] = 0;
  in_ECX[0xa002] = in_ECX[0xa002] + 0x1000;
  in_ECX[0xa005] = in_ECX + 2;
  in_ECX[0xa003] = 0;
  in_ECX[0xa004] = 0;
  iVar2 = 0xfff;
  puVar1 = in_ECX;
  do {
    puVar1[9] = puVar1 + 0xc;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 10;
  } while (iVar2 != 0);
  in_ECX[0x9fff] = 0;
  in_ECX[0xa000] = 0;
  in_ECX[0xa001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e22d0 @ 0x005e22d0 ====

undefined4 FUN_005e22d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2800c);
}


// ==== FUN_005e22e0 @ 0x005e22e0 ====

void FUN_005e22e0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e2200();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e2300 @ 0x005e2300 ====

void FUN_005e2300(byte param_1)

{
  void *in_ECX;
  
  FUN_005e2320();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e2320 @ 0x005e2320 ====

void FUN_005e2320(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009835a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3ea4;
  _Memory = (void *)in_ECX[0xa004];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c3e9c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x28,0x1000,(_func_void_void_ptr *)&LAB_005e21b0);
    *in_ECX = &PTR_FUN_009c3e84;
    ExceptionList = local_c;
    return;
  }
  FUN_005ff530();
  _free(_Memory);
  return;
}


// ==== FUN_005e23c0 @ 0x005e23c0 ====

void * FUN_005e23c0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009835f9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x28014);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x2800c) = *(int *)(in_ECX + 0x2800c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x28);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_005ff5a0();
      }
      *(undefined4 *)((int)param_2 + 0x20) = *(undefined4 *)(in_ECX + 0x28010);
      *(void **)(in_ECX + 0x28010) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x28014) = *(undefined4 *)((int)param_2 + 0x1c);
    }
    *(undefined4 *)((int)param_2 + 0x1c) = 0;
    *(int *)((int)param_2 + 0x24) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x24) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3d80,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x24) = *(int *)((int)param_2 + 0x24) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005e24d0 @ 0x005e24d0 ====

undefined4 FUN_005e24d0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x24) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3d80,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x24);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x24);
    }
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(in_ECX + 0x28014);
    *(int *)(in_ECX + 0x2800c) = *(int *)(in_ECX + 0x2800c) + -1;
    *(int *)(in_ECX + 0x28014) = param_2;
  }
  return 0;
}


// ==== FUN_005e2550 @ 0x005e2550 ====

void FUN_005e2550(byte param_1)

{
  void *in_ECX;
  
  FUN_005e2120();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e2570 @ 0x005e2570 ====

void FUN_005e2570(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3ed4;
  return;
}


// ==== FUN_005e2580 @ 0x005e2580 ====

void FUN_005e2580(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3ed4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e25a0 @ 0x005e25a0 ====

void FUN_005e25a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3ee8;
  return;
}


// ==== FUN_005e25b0 @ 0x005e25b0 ====

void FUN_005e25b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3ee8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e25e0 @ 0x005e25e0 ====

void FUN_005e25e0(void)

{
  FUN_005ff670();
  return;
}


// ==== FUN_005e25f0 @ 0x005e25f0 ====

void FUN_005e25f0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_005ff640();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e2610 @ 0x005e2610 ====

void FUN_005e2610(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983663;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3f20;
  pvVar1 = operator_new(0xb8);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e2780();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b018 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5b018 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e26a0 @ 0x005e26a0 ====

void FUN_005e26a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983675;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3f20;
  DAT_00b5b018 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c3ed4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e2700 @ 0x005e2700 ====

undefined4 FUN_005e2700(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  FUN_005ff620(unaff_ESI);
  return uVar1;
}


// ==== FUN_005e2730 @ 0x005e2730 ====

undefined4 FUN_005e2730(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  FUN_005ff630(unaff_ESI);
  return uVar1;
}


// ==== FUN_005e2760 @ 0x005e2760 ====

void FUN_005e2760(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3f00;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,8,(_func_void_void_ptr *)&LAB_005e25d0);
  return;
}


// ==== FUN_005e2780 @ 0x005e2780 ====

void FUN_005e2780(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983618;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3f08;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c3f00;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x14,8,FUN_005e25e0,(_func_void_void_ptr *)&LAB_005e25d0);
  in_ECX[0x2a] = 0;
  in_ECX[0x2a] = in_ECX[0x2a] + 8;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x2d] = in_ECX + 2;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[4] = in_ECX + 7;
  in_ECX[9] = in_ECX + 0xc;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xe] = in_ECX + 0x11;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x13] = in_ECX + 0x16;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x18] = in_ECX + 0x1b;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1d] = in_ECX + 0x20;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x22] = in_ECX + 0x25;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e2860 @ 0x005e2860 ====

void FUN_005e2860(byte param_1)

{
  void *in_ECX;
  
  FUN_005e2760();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e2880 @ 0x005e2880 ====

void FUN_005e2880(byte param_1)

{
  void *in_ECX;
  
  FUN_005e28a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e28a0 @ 0x005e28a0 ====

void FUN_005e28a0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983643;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3f08;
  _Memory = (void *)in_ECX[0x2c];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c3f00;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,8,(_func_void_void_ptr *)&LAB_005e25d0);
    *in_ECX = &PTR_FUN_009c3ee8;
    ExceptionList = local_c;
    return;
  }
  FUN_005ff610();
  _free(_Memory);
  return;
}


// ==== FUN_005e2930 @ 0x005e2930 ====

void * FUN_005e2930(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00983699;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0xb4);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xac) = *(int *)(in_ECX + 0xac) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_005ff670();
      }
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0xb0);
      *(void **)(in_ECX + 0xb0) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0xb4) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c3f30,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005e2a40 @ 0x005e2a40 ====

undefined4 FUN_005e2a40(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3f30,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0xb4);
    *(int *)(in_ECX + 0xac) = *(int *)(in_ECX + 0xac) + -1;
    *(int *)(in_ECX + 0xb4) = param_2;
  }
  return 0;
}


// ==== FUN_005e2ac0 @ 0x005e2ac0 ====

void FUN_005e2ac0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e26a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e2ae0 @ 0x005e2ae0 ====

void FUN_005e2ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3fa4;
  return;
}


// ==== FUN_005e2af0 @ 0x005e2af0 ====

void FUN_005e2af0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3fa4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e2b10 @ 0x005e2b10 ====

void FUN_005e2b10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3fc4;
  return;
}


// ==== FUN_005e2b20 @ 0x005e2b20 ====

void FUN_005e2b20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c401c;
  return;
}


// ==== FUN_005e2b30 @ 0x005e2b30 ====

void FUN_005e2b30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4034;
  return;
}


// ==== FUN_005e2b40 @ 0x005e2b40 ====

void FUN_005e2b40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3fc4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e2b60 @ 0x005e2b60 ====

void FUN_005e2b60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c401c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e2b80 @ 0x005e2b80 ====

void FUN_005e2b80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4034;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e2ba0 @ 0x005e2ba0 ====

undefined4 FUN_005e2ba0(undefined2 param_1)

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


// ==== FUN_005e2bd0 @ 0x005e2bd0 ====

undefined4 FUN_005e2bd0(undefined2 param_1)

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


// ==== FUN_005e2c00 @ 0x005e2c00 ====

undefined4 FUN_005e2c00(void)

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


// ==== FUN_005e2c20 @ 0x005e2c20 ====

undefined4 FUN_005e2c20(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 4);
    }
  }
  return 0;
}


// ==== FUN_005e2c50 @ 0x005e2c50 ====

void FUN_005e2c50(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009836b8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c4054;
  DAT_00b5ab14 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c3fa4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005e2cf0 @ 0x005e2cf0 ====

void FUN_005e2cf0(undefined2 *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined2 *puVar3;
  int in_ECX;
  void *unaff_EDI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009836cd;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0xff8);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_005ff840();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 0x14))(param_1);
  puVar3 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = *param_1;
  *(int **)(puVar3 + 2) = piVar2;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  ExceptionList = unaff_EDI;
  return;
}


// ==== FUN_005e2d80 @ 0x005e2d80 ====

void FUN_005e2d80(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009836f5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4054;
  pvVar2 = operator_new(0x298);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e2e90();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x428);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e3430(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab14 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab14 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e2e50 @ 0x005e2e50 ====

void FUN_005e2e50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c404c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x20,FUN_006ef6d0);
  return;
}


// ==== FUN_005e2e70 @ 0x005e2e70 ====

void FUN_005e2e70(byte param_1)

{
  void *in_ECX;
  
  FUN_005e2e50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e2e90 @ 0x005e2e90 ====

void FUN_005e2e90(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983708;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4070;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c404c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x20,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0xa2] = 0;
  in_ECX[0xa2] = in_ECX[0xa2] + 0x20;
  in_ECX[0xa5] = in_ECX + 2;
  in_ECX[0xa3] = 0;
  in_ECX[0xa4] = 0;
  iVar2 = 0x1f;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x9f] = 0;
  in_ECX[0xa0] = 0;
  in_ECX[0xa1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e2f40 @ 0x005e2f40 ====

void FUN_005e2f40(byte param_1)

{
  void *in_ECX;
  
  FUN_005e2f60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e2f60 @ 0x005e2f60 ====

void FUN_005e2f60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983733;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4070;
  local_4 = 1;
  if ((void *)in_ECX[0xa4] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c404c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x20,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c401c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xa4]);
  return;
}


// ==== FUN_005e2fe0 @ 0x005e2fe0 ====

void * FUN_005e2fe0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098374b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x294);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x28c) = *(int *)(in_ECX + 0x28c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x290);
      *(void **)(in_ECX + 0x290) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x294) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c4088,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005e30c0 @ 0x005e30c0 ====

undefined4 FUN_005e30c0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4088,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x294);
    *(int *)(in_ECX + 0x28c) = *(int *)(in_ECX + 0x28c) + -1;
    *(int *)(in_ECX + 0x294) = param_2;
  }
  return 0;
}


// ==== FUN_005e3140 @ 0x005e3140 ====

void FUN_005e3140(byte param_1)

{
  void *in_ECX;
  
  FUN_005e2c50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e3160 @ 0x005e3160 ====

void FUN_005e3160(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c40f4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x20,FUN_006ef6d0);
  return;
}


// ==== FUN_005e3180 @ 0x005e3180 ====

void FUN_005e3180(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983773;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c40fc;
  local_4 = 1;
  if ((void *)in_ECX[0x104] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c40f4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x20,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c4034;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x104]);
  return;
}


// ==== FUN_005e3200 @ 0x005e3200 ====

undefined4 FUN_005e3200(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4088,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x414);
    *(int *)(in_ECX + 0x40c) = *(int *)(in_ECX + 0x40c) + -1;
    *(int *)(in_ECX + 0x414) = param_2;
  }
  return 0;
}


// ==== FUN_005e3280 @ 0x005e3280 ====

undefined4 * FUN_005e3280(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4088,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x414);
  *(int *)(in_ECX + 0x40c) = *(int *)(in_ECX + 0x40c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x410);
    *(undefined4 **)(in_ECX + 0x410) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x414) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005e3340 @ 0x005e3340 ====

void FUN_005e3340(byte param_1)

{
  void *in_ECX;
  
  FUN_005e3160();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e3360 @ 0x005e3360 ====

void FUN_005e3360(byte param_1)

{
  void *in_ECX;
  
  FUN_005e3180();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e3380 @ 0x005e3380 ====

void FUN_005e3380(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983788;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c40fc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c40f4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x20,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x102] = 0;
  in_ECX[0x102] = in_ECX[0x102] + 0x20;
  in_ECX[0x105] = in_ECX + 2;
  in_ECX[0x103] = 0;
  in_ECX[0x104] = 0;
  iVar2 = 0x1f;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0xff] = 0;
  in_ECX[0x100] = 0;
  in_ECX[0x101] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e3430 @ 0x005e3430 ====

void FUN_005e3430(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009837a8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4114;
  FUN_005e3380();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e3490 @ 0x005e3490 ====

void FUN_005e3490(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e34b0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e34b0 @ 0x005e34b0 ====

void FUN_005e34b0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005e34b0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005e34b0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e34f0 @ 0x005e34f0 ====

void FUN_005e34f0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e3510(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e3510 @ 0x005e3510 ====

void FUN_005e3510(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005e3510(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005e3510(param_1[3]);
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


// ==== FUN_005e3580 @ 0x005e3580 ====

void FUN_005e3580(byte param_1)

{
  void *in_ECX;
  
  FUN_005e35a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e35a0 @ 0x005e35a0 ====

void FUN_005e35a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009837d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4114;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005e3510(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005e3180();
  *in_ECX = &PTR_FUN_009c3fc4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e3610 @ 0x005e3610 ====

void FUN_005e3610(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c416c;
  return;
}


// ==== FUN_005e3620 @ 0x005e3620 ====

void FUN_005e3620(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c416c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e3640 @ 0x005e3640 ====

void FUN_005e3640(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c417c;
  return;
}


// ==== FUN_005e3650 @ 0x005e3650 ====

void FUN_005e3650(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c417c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e3680 @ 0x005e3680 ====

void FUN_005e3680(void)

{
  FUN_006003e0();
  return;
}


// ==== FUN_005e3690 @ 0x005e3690 ====

void FUN_005e3690(int *param_1)

{
  int in_ECX;
  
  (**(code **)(*param_1 + 8))();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e36b0 @ 0x005e36b0 ====

void FUN_005e36b0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983833;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c41b4;
  pvVar1 = operator_new(0x48);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e37f0();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ab18 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab18 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e3740 @ 0x005e3740 ====

void FUN_005e3740(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983845;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c41b4;
  DAT_00b5ab18 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c416c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e37a0 @ 0x005e37a0 ====

uint FUN_005e37a0(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  undefined4 unaff_ESI;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  cVar1 = (**(code **)(*piVar2 + 4))(unaff_ESI);
  return -(uint)(cVar1 != '\0') & (uint)piVar2;
}


// ==== FUN_005e37d0 @ 0x005e37d0 ====

void FUN_005e37d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4194;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x30,1,(_func_void_void_ptr *)&LAB_005e3670);
  return;
}


// ==== FUN_005e37f0 @ 0x005e37f0 ====

void FUN_005e37f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009837e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c419c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c4194;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x30,1,FUN_005e3680,(_func_void_void_ptr *)&LAB_005e3670);
  in_ECX[0xe] = 0;
  in_ECX[0xe] = in_ECX[0xe] + 1;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = in_ECX + 2;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e3870 @ 0x005e3870 ====

void FUN_005e3870(byte param_1)

{
  void *in_ECX;
  
  FUN_005e37d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e3890 @ 0x005e3890 ====

void FUN_005e3890(byte param_1)

{
  void *in_ECX;
  
  FUN_005e38b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e38b0 @ 0x005e38b0 ====

void FUN_005e38b0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983813;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c419c;
  _Memory = (void *)in_ECX[0x10];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c4194;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x30,1,(_func_void_void_ptr *)&LAB_005e3670);
    *in_ECX = &PTR_FUN_009c417c;
    ExceptionList = local_c;
    return;
  }
  FUN_005fffb0();
  _free(_Memory);
  return;
}


// ==== FUN_005e3940 @ 0x005e3940 ====

void * FUN_005e3940(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00983869;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x44);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x3c) = *(int *)(in_ECX + 0x3c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x30);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_006003e0();
      }
      *(undefined4 *)((int)param_2 + 0x28) = *(undefined4 *)(in_ECX + 0x40);
      *(void **)(in_ECX + 0x40) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)((int)param_2 + 0x24);
    }
    *(undefined4 *)((int)param_2 + 0x24) = 0;
    *(int *)((int)param_2 + 0x2c) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x2c) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c41c0,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x2c) = *(int *)((int)param_2 + 0x2c) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005e3a40 @ 0x005e3a40 ====

undefined4 FUN_005e3a40(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x2c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c41c0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x2c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x2c);
    }
    *(undefined4 *)(param_2 + 0x24) = *(undefined4 *)(in_ECX + 0x44);
    *(int *)(in_ECX + 0x3c) = *(int *)(in_ECX + 0x3c) + -1;
    *(int *)(in_ECX + 0x44) = param_2;
  }
  return 0;
}


// ==== FUN_005e3ac0 @ 0x005e3ac0 ====

void FUN_005e3ac0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e3740();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e3ae0 @ 0x005e3ae0 ====

void FUN_005e3ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4280;
  return;
}


// ==== FUN_005e3af0 @ 0x005e3af0 ====

void FUN_005e3af0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4280;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e3b10 @ 0x005e3b10 ====

void FUN_005e3b10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c429c;
  return;
}


// ==== FUN_005e3b20 @ 0x005e3b20 ====

void FUN_005e3b20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c42f4;
  return;
}


// ==== FUN_005e3b30 @ 0x005e3b30 ====

void FUN_005e3b30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c430c;
  return;
}


// ==== FUN_005e3b40 @ 0x005e3b40 ====

void FUN_005e3b40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c429c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e3b60 @ 0x005e3b60 ====

void FUN_005e3b60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c42f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e3b80 @ 0x005e3b80 ====

void FUN_005e3b80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c430c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e3ba0 @ 0x005e3ba0 ====

undefined4 FUN_005e3ba0(undefined2 param_1)

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


// ==== FUN_005e3bd0 @ 0x005e3bd0 ====

undefined4 FUN_005e3bd0(void)

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


// ==== FUN_005e3bf0 @ 0x005e3bf0 ====

undefined4 FUN_005e3bf0(void)

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


// ==== FUN_005e3c10 @ 0x005e3c10 ====

void FUN_005e3c10(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983888;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c432c;
  DAT_00b5ab10 = 0;
  local_4 = 0;
  for (piVar3 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar3 != (int *)0x0;
      piVar3 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar3)) {
    iVar1 = *piVar3;
    puVar2 = *(undefined4 **)(iVar1 + 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c4280;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005e3cb0 @ 0x005e3cb0 ====

void FUN_005e3cb0(undefined2 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined2 *puVar4;
  int in_ECX;
  undefined2 local_214 [2];
  undefined1 auStack_210 [256];
  undefined1 auStack_110 [244];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009838a0;
  pvStack_c = ExceptionList;
  local_214[0] = *param_1;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_214);
  if (iVar1 != 0) {
    auStack_210[0] = 0;
    uVar2 = FUN_0044a580(auStack_210,s_Duplicate_Cell_Flyweight____d_009c4220,*param_1);
    FUN_00797b80(uVar2);
    auStack_110[0] = 0;
    uVar2 = FUN_0044a580(auStack_110,s_File___s__Line___d_009c4268,
                         s___Arrange_Cell_Flyweight_Contain_009c4240,0x2c);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  pvVar3 = operator_new(0x16c);
  puStack_8 = (undefined1 *)0x0;
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00600a30();
  }
  puStack_8 = (undefined1 *)0xffffffff;
  FUN_00600a40(param_1);
  puVar4 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar4 = *param_1;
  *(undefined4 *)(puVar4 + 2) = uVar2;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar4);
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_005e3dc0 @ 0x005e3dc0 ====

void FUN_005e3dc0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009838c8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c432c;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e3ed0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x1028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e4440(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab10 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab10 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e3e90 @ 0x005e3e90 ====

void FUN_005e3e90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4324;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005e3eb0 @ 0x005e3eb0 ====

void FUN_005e3eb0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e3e90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e3ed0 @ 0x005e3ed0 ====

void FUN_005e3ed0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009838e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4344;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c4324;
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


// ==== FUN_005e3f80 @ 0x005e3f80 ====

undefined4 FUN_005e3f80(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4358,0xa9);
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


// ==== FUN_005e4000 @ 0x005e4000 ====

void FUN_005e4000(byte param_1)

{
  void *in_ECX;
  
  FUN_005e4020();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e4020 @ 0x005e4020 ====

void FUN_005e4020(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983913;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4344;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c4324;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c42f4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_005e40a0 @ 0x005e40a0 ====

void * FUN_005e40a0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4358,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0xa14);
  *(int *)(in_ECX + 0xa0c) = *(int *)(in_ECX + 0xa0c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0xa10);
    *(void **)(in_ECX + 0xa10) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0xa14) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_005e4150 @ 0x005e4150 ====

void FUN_005e4150(byte param_1)

{
  void *in_ECX;
  
  FUN_005e3c10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e4170 @ 0x005e4170 ====

void FUN_005e4170(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c43d0;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005e4190 @ 0x005e4190 ====

void FUN_005e4190(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983933;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c43d8;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c43d0;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c430c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_005e4210 @ 0x005e4210 ====

undefined4 FUN_005e4210(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4358,0xa9);
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


// ==== FUN_005e4290 @ 0x005e4290 ====

undefined4 * FUN_005e4290(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4358,0x85);
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


// ==== FUN_005e4350 @ 0x005e4350 ====

void FUN_005e4350(byte param_1)

{
  void *in_ECX;
  
  FUN_005e4170();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e4370 @ 0x005e4370 ====

void FUN_005e4370(byte param_1)

{
  void *in_ECX;
  
  FUN_005e4190();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e4390 @ 0x005e4390 ====

void FUN_005e4390(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983948;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c43d8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c43d0;
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


// ==== FUN_005e4440 @ 0x005e4440 ====

void FUN_005e4440(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983968;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c43f4;
  FUN_005e4390();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e44a0 @ 0x005e44a0 ====

void FUN_005e44a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e44c0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e44c0 @ 0x005e44c0 ====

void FUN_005e44c0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005e44c0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005e44c0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e4500 @ 0x005e4500 ====

void FUN_005e4500(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e4520(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e4520 @ 0x005e4520 ====

void FUN_005e4520(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005e4520(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005e4520(param_1[3]);
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


// ==== FUN_005e4590 @ 0x005e4590 ====

void FUN_005e4590(byte param_1)

{
  void *in_ECX;
  
  FUN_005e45b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e45b0 @ 0x005e45b0 ====

void FUN_005e45b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00983993;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c43f4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005e4520(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005e4190();
  *in_ECX = &PTR_FUN_009c429c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e4620 @ 0x005e4620 ====

void FUN_005e4620(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c448c;
  return;
}


// ==== FUN_005e4630 @ 0x005e4630 ====

void FUN_005e4630(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c448c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e4650 @ 0x005e4650 ====

void FUN_005e4650(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c44a4;
  return;
}


// ==== FUN_005e4660 @ 0x005e4660 ====

void FUN_005e4660(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c44fc;
  return;
}


// ==== FUN_005e4670 @ 0x005e4670 ====

void FUN_005e4670(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4514;
  return;
}


// ==== FUN_005e4680 @ 0x005e4680 ====

void FUN_005e4680(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c44a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e46a0 @ 0x005e46a0 ====

void FUN_005e46a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c44fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e46c0 @ 0x005e46c0 ====

void FUN_005e46c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4514;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e46e0 @ 0x005e46e0 ====

undefined4 FUN_005e46e0(undefined2 param_1)

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


// ==== FUN_005e4710 @ 0x005e4710 ====

undefined4 FUN_005e4710(void)

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


// ==== FUN_005e4730 @ 0x005e4730 ====

undefined4 FUN_005e4730(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 4);
    }
  }
  return 0;
}


// ==== FUN_005e4760 @ 0x005e4760 ====

void FUN_005e4760(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009839a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c4534;
  DAT_00b5ab48 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c448c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005e4800 @ 0x005e4800 ====

void FUN_005e4800(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int *piVar6;
  undefined1 auStack_10e [242];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined2 *puStack_4;
  
  puStack_4 = (undefined2 *)0xffffffff;
  puStack_8 = &LAB_009839c0;
  pvStack_c = ExceptionList;
  piVar6 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar3 = operator_new(0x10);
  pvStack_c = (void *)0x0;
  if (pvVar3 != (void *)0x0) {
    piVar6 = (int *)FUN_00600b40();
  }
  puVar1 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar6 + 8))(puStack_4);
  *puVar2 = *puVar1;
  *(int **)(puVar2 + 2) = piVar6;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009c4474,
                         s___Arrange_Warp_Flyweight_Contain_009c444c,0x3b);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_005e48d0 @ 0x005e48d0 ====

void FUN_005e48d0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009839e8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4534;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e49e0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x1028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e4f50(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab48 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab48 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e49a0 @ 0x005e49a0 ====

void FUN_005e49a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c452c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005e49c0 @ 0x005e49c0 ====

void FUN_005e49c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e49a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e49e0 @ 0x005e49e0 ====

void FUN_005e49e0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983a08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c454c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c452c;
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


// ==== FUN_005e4a90 @ 0x005e4a90 ====

void FUN_005e4a90(byte param_1)

{
  void *in_ECX;
  
  FUN_005e4ab0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e4ab0 @ 0x005e4ab0 ====

void FUN_005e4ab0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983a33;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c454c;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c452c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c44fc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_005e4b30 @ 0x005e4b30 ====

void * FUN_005e4b30(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4560,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0xa14);
  *(int *)(in_ECX + 0xa0c) = *(int *)(in_ECX + 0xa0c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0xa10);
    *(void **)(in_ECX + 0xa10) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0xa14) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_005e4be0 @ 0x005e4be0 ====

undefined4 FUN_005e4be0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4560,0xa9);
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


// ==== FUN_005e4c60 @ 0x005e4c60 ====

void FUN_005e4c60(byte param_1)

{
  void *in_ECX;
  
  FUN_005e4760();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e4c80 @ 0x005e4c80 ====

void FUN_005e4c80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c45d8;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005e4ca0 @ 0x005e4ca0 ====

void FUN_005e4ca0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983a53;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c45e0;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c45d8;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c4514;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_005e4d20 @ 0x005e4d20 ====

undefined4 FUN_005e4d20(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4560,0xa9);
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


// ==== FUN_005e4da0 @ 0x005e4da0 ====

undefined4 * FUN_005e4da0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4560,0x85);
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


// ==== FUN_005e4e60 @ 0x005e4e60 ====

void FUN_005e4e60(byte param_1)

{
  void *in_ECX;
  
  FUN_005e4c80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e4e80 @ 0x005e4e80 ====

void FUN_005e4e80(byte param_1)

{
  void *in_ECX;
  
  FUN_005e4ca0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e4ea0 @ 0x005e4ea0 ====

void FUN_005e4ea0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983a68;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c45e0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c45d8;
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


// ==== FUN_005e4f50 @ 0x005e4f50 ====

void FUN_005e4f50(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983a88;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c45fc;
  FUN_005e4ea0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e4fb0 @ 0x005e4fb0 ====

void FUN_005e4fb0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e4fd0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e4fd0 @ 0x005e4fd0 ====

void FUN_005e4fd0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005e4fd0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005e4fd0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e5010 @ 0x005e5010 ====

void FUN_005e5010(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e5030(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e5030 @ 0x005e5030 ====

void FUN_005e5030(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005e5030(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005e5030(param_1[3]);
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


// ==== FUN_005e50a0 @ 0x005e50a0 ====

void FUN_005e50a0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e50c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e50c0 @ 0x005e50c0 ====

void FUN_005e50c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00983ab3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c45fc;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005e5030(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005e4ca0();
  *in_ECX = &PTR_FUN_009c44a4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e5130 @ 0x005e5130 ====

void FUN_005e5130(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00983be9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(8);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060cef0();
  }
  local_4 = 0xffffffff;
  *in_ECX = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060c8e0();
  }
  local_4 = 0xffffffff;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060c2f0();
  }
  local_4 = 0xffffffff;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060bcf0();
  }
  local_4 = 0xffffffff;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060b970();
  }
  local_4 = 0xffffffff;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060b5f0();
  }
  local_4 = 0xffffffff;
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060b000();
  }
  local_4 = 0xffffffff;
  in_ECX[7] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060ac80();
  }
  local_4 = 0xffffffff;
  in_ECX[8] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 8;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060a690();
  }
  local_4 = 0xffffffff;
  in_ECX[9] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 9;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060a0b0();
  }
  local_4 = 0xffffffff;
  in_ECX[0xe] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00609ad0();
  }
  local_4 = 0xffffffff;
  in_ECX[10] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0xb;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006094e0();
  }
  local_4 = 0xffffffff;
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0xc;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00608eb0();
  }
  local_4 = 0xffffffff;
  in_ECX[0xb] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0xd;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006088d0();
  }
  local_4 = 0xffffffff;
  in_ECX[0xc] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0xe;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00608530();
  }
  local_4 = 0xffffffff;
  in_ECX[0xd] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0xf;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00607c60();
  }
  local_4 = 0xffffffff;
  in_ECX[0xf] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00607140();
  }
  local_4 = 0xffffffff;
  in_ECX[0x13] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x11;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006065c0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x10] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x12;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00605ab0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x11] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x13;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00604fa0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x12] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x14;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00604460();
  }
  local_4 = 0xffffffff;
  in_ECX[0x14] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x15;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00603850();
  }
  local_4 = 0xffffffff;
  in_ECX[0x15] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x16;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00602d40();
  }
  local_4 = 0xffffffff;
  in_ECX[0x16] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x17;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00602250();
  }
  local_4 = 0xffffffff;
  in_ECX[0x17] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0x18;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00601bf0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x18] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0x19;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00601710();
  }
  local_4 = 0xffffffff;
  in_ECX[0x19] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x1a;
  if (pvVar1 == (void *)0x0) {
    in_ECX[0x1a] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00600de0();
  in_ECX[0x1a] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e5620 @ 0x005e5620 ====

void FUN_005e5620(void)

{
  int *in_ECX;
  
  if ((undefined4 *)in_ECX[0x19] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x19])(1);
  }
  in_ECX[0x19] = 0;
  if ((undefined4 *)in_ECX[0x18] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x18])(1);
  }
  in_ECX[0x18] = 0;
  if ((undefined4 *)in_ECX[0x17] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x17])(1);
  }
  in_ECX[0x17] = 0;
  if ((undefined4 *)in_ECX[0x16] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x16])(1);
  }
  in_ECX[0x16] = 0;
  if ((undefined4 *)in_ECX[0x15] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x15])(1);
  }
  in_ECX[0x15] = 0;
  if ((undefined4 *)in_ECX[0x14] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x14])(1);
  }
  in_ECX[0x14] = 0;
  if ((undefined4 *)in_ECX[0x12] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x12])(1);
  }
  in_ECX[0x12] = 0;
  if ((undefined4 *)in_ECX[0x11] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x11])(1);
  }
  in_ECX[0x11] = 0;
  if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x10])(1);
  }
  in_ECX[0x10] = 0;
  if ((undefined4 *)in_ECX[0x13] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x13])(1);
  }
  in_ECX[0x13] = 0;
  if ((undefined4 *)in_ECX[0xf] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xf])(1);
  }
  in_ECX[0xf] = 0;
  if ((undefined4 *)in_ECX[0x1a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1a])(1);
  }
  in_ECX[0x1a] = 0;
  if ((undefined4 *)in_ECX[0xd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xd])(1);
  }
  in_ECX[0xd] = 0;
  if ((undefined4 *)in_ECX[0xc] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xc])(1);
  }
  in_ECX[0xc] = 0;
  if ((undefined4 *)in_ECX[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xb])(1);
  }
  in_ECX[0xb] = 0;
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
  if ((undefined4 *)in_ECX[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[10])(1);
  }
  in_ECX[10] = 0;
  if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[9])(1);
  }
  in_ECX[9] = 0;
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
  }
  in_ECX[8] = 0;
  if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[7])(1);
  }
  in_ECX[7] = 0;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*in_ECX)(1);
  }
  *in_ECX = 0;
  return;
}


// ==== FUN_005e57d0 @ 0x005e57d0 ====

void FUN_005e57d0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983c06;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4654;
  pvVar1 = operator_new(0x6c);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_005e5130();
  in_ECX[1] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e5850 @ 0x005e5850 ====

void FUN_005e5850(void)

{
  void *_Memory;
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_00983c18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4654;
  _Memory = (void *)in_ECX[1];
  local_4 = 0;
  if (_Memory == (void *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_009c3574;
    ExceptionList = pvVar1;
    return;
  }
  FUN_005e5620();
  _free(_Memory);
  return;
}


// ==== FUN_005e58c0 @ 0x005e58c0 ====

void FUN_005e58c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e5850();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e58e0 @ 0x005e58e0 ====

void FUN_005e58e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c465c;
  return;
}


// ==== FUN_005e58f0 @ 0x005e58f0 ====

void FUN_005e58f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c465c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e5910 @ 0x005e5910 ====

void FUN_005e5910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4674;
  return;
}


// ==== FUN_005e5920 @ 0x005e5920 ====

void FUN_005e5920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c46cc;
  return;
}


// ==== FUN_005e5930 @ 0x005e5930 ====

void FUN_005e5930(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c46e4;
  return;
}


// ==== FUN_005e5940 @ 0x005e5940 ====

void FUN_005e5940(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4674;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e5960 @ 0x005e5960 ====

void FUN_005e5960(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c46cc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e5980 @ 0x005e5980 ====

void FUN_005e5980(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c46e4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e59a0 @ 0x005e59a0 ====

undefined4 FUN_005e59a0(undefined2 param_1)

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


// ==== FUN_005e59d0 @ 0x005e59d0 ====

undefined4 FUN_005e59d0(void)

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


// ==== FUN_005e59f0 @ 0x005e59f0 ====

undefined4 FUN_005e59f0(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 4);
    }
  }
  return 0;
}


// ==== FUN_005e5a20 @ 0x005e5a20 ====

void FUN_005e5a20(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983c38;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c4704;
  DAT_00b5ab4c = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c465c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005e5ac0 @ 0x005e5ac0 ====

void FUN_005e5ac0(undefined2 *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined2 *puVar3;
  int in_ECX;
  void *unaff_EDI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00983c4d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x14);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0060d500();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 4))(param_1);
  puVar3 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = *param_1;
  *(int **)(puVar3 + 2) = piVar2;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  ExceptionList = unaff_EDI;
  return;
}


// ==== FUN_005e5b50 @ 0x005e5b50 ====

void FUN_005e5b50(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00983c75;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4704;
  pvVar2 = operator_new(0x158);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e5c60();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x228);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e6210(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab4c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab4c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e5c20 @ 0x005e5c20 ====

void FUN_005e5c20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c46fc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x10,FUN_006ef6d0);
  return;
}


// ==== FUN_005e5c40 @ 0x005e5c40 ====

void FUN_005e5c40(byte param_1)

{
  void *in_ECX;
  
  FUN_005e5c20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e5c60 @ 0x005e5c60 ====

void FUN_005e5c60(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983c88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c471c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c46fc;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x10,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x52] = 0;
  in_ECX[0x52] = in_ECX[0x52] + 0x10;
  in_ECX[0x55] = in_ECX + 2;
  in_ECX[0x53] = 0;
  in_ECX[0x54] = 0;
  iVar2 = 0xf;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x4f] = 0;
  in_ECX[0x50] = 0;
  in_ECX[0x51] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e5d10 @ 0x005e5d10 ====

void FUN_005e5d10(byte param_1)

{
  void *in_ECX;
  
  FUN_005e5d30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e5d30 @ 0x005e5d30 ====

void FUN_005e5d30(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983cb3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c471c;
  local_4 = 1;
  if ((void *)in_ECX[0x54] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c46fc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x10,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c46cc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x54]);
  return;
}


// ==== FUN_005e5db0 @ 0x005e5db0 ====

void * FUN_005e5db0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00983ccb;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x154);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x14c) = *(int *)(in_ECX + 0x14c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x150);
      *(void **)(in_ECX + 0x150) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x154) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c4730,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005e5e90 @ 0x005e5e90 ====

undefined4 FUN_005e5e90(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4730,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x154);
    *(int *)(in_ECX + 0x14c) = *(int *)(in_ECX + 0x14c) + -1;
    *(int *)(in_ECX + 0x154) = param_2;
  }
  return 0;
}


// ==== FUN_005e5f10 @ 0x005e5f10 ====

void FUN_005e5f10(byte param_1)

{
  void *in_ECX;
  
  FUN_005e5a20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e5f30 @ 0x005e5f30 ====

void FUN_005e5f30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c47b4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x10,FUN_006ef6d0);
  return;
}


// ==== FUN_005e5f50 @ 0x005e5f50 ====

void FUN_005e5f50(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983cf3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c47bc;
  local_4 = 1;
  if ((void *)in_ECX[0x84] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c47b4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x10,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c46e4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x84]);
  return;
}


// ==== FUN_005e5fd0 @ 0x005e5fd0 ====

undefined4 FUN_005e5fd0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x20c);
}


// ==== FUN_005e5fe0 @ 0x005e5fe0 ====

undefined4 FUN_005e5fe0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4730,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x214);
    *(int *)(in_ECX + 0x20c) = *(int *)(in_ECX + 0x20c) + -1;
    *(int *)(in_ECX + 0x214) = param_2;
  }
  return 0;
}


// ==== FUN_005e6060 @ 0x005e6060 ====

undefined4 * FUN_005e6060(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4730,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x214);
  *(int *)(in_ECX + 0x20c) = *(int *)(in_ECX + 0x20c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x210);
    *(undefined4 **)(in_ECX + 0x210) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x214) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005e6120 @ 0x005e6120 ====

void FUN_005e6120(byte param_1)

{
  void *in_ECX;
  
  FUN_005e5f30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6140 @ 0x005e6140 ====

void FUN_005e6140(byte param_1)

{
  void *in_ECX;
  
  FUN_005e5f50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6160 @ 0x005e6160 ====

void FUN_005e6160(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983d08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c47bc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c47b4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x10,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x82] = 0;
  in_ECX[0x82] = in_ECX[0x82] + 0x10;
  in_ECX[0x85] = in_ECX + 2;
  in_ECX[0x83] = 0;
  in_ECX[0x84] = 0;
  iVar2 = 0xf;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x7f] = 0;
  in_ECX[0x80] = 0;
  in_ECX[0x81] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e6210 @ 0x005e6210 ====

void FUN_005e6210(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983d28;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c47d4;
  FUN_005e6160();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e6270 @ 0x005e6270 ====

void FUN_005e6270(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e6290(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e6290 @ 0x005e6290 ====

void FUN_005e6290(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005e6290(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005e6290(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e62d0 @ 0x005e62d0 ====

void FUN_005e62d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e62f0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e62f0 @ 0x005e62f0 ====

void FUN_005e62f0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005e62f0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005e62f0(param_1[3]);
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


// ==== FUN_005e6360 @ 0x005e6360 ====

void FUN_005e6360(byte param_1)

{
  void *in_ECX;
  
  FUN_005e6380();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6380 @ 0x005e6380 ====

void FUN_005e6380(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00983d53;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c47d4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005e62f0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005e5f50();
  *in_ECX = &PTR_FUN_009c4674;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e63f0 @ 0x005e63f0 ====

void FUN_005e63f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c482c;
  return;
}


// ==== FUN_005e6400 @ 0x005e6400 ====

void FUN_005e6400(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c482c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6420 @ 0x005e6420 ====

void FUN_005e6420(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4844;
  return;
}


// ==== FUN_005e6430 @ 0x005e6430 ====

void FUN_005e6430(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c489c;
  return;
}


// ==== FUN_005e6440 @ 0x005e6440 ====

void FUN_005e6440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c48b4;
  return;
}


// ==== FUN_005e6450 @ 0x005e6450 ====

void FUN_005e6450(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4844;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6470 @ 0x005e6470 ====

void FUN_005e6470(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c489c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6490 @ 0x005e6490 ====

void FUN_005e6490(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c48b4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e64b0 @ 0x005e64b0 ====

undefined4 FUN_005e64b0(undefined2 param_1)

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


// ==== FUN_005e64e0 @ 0x005e64e0 ====

undefined4 FUN_005e64e0(void)

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


// ==== FUN_005e6500 @ 0x005e6500 ====

undefined4 FUN_005e6500(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 4);
    }
  }
  return 0;
}


// ==== FUN_005e6530 @ 0x005e6530 ====

void FUN_005e6530(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983d68;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c48d4;
  DAT_00b5ab50 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c482c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005e65d0 @ 0x005e65d0 ====

void FUN_005e65d0(void)

{
  undefined2 *puVar1;
  int in_ECX;
  undefined2 unaff_SI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar1 = unaff_SI;
  *(undefined4 *)(puVar1 + 2) = unaff_retaddr;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar1);
  return;
}


// ==== FUN_005e6600 @ 0x005e6600 ====

void FUN_005e6600(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00983d90;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c48d4;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e6710();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x1028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e6cb0(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab50 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab50 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e66d0 @ 0x005e66d0 ====

void FUN_005e66d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c48cc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005e66f0 @ 0x005e66f0 ====

void FUN_005e66f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e66d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6710 @ 0x005e6710 ====

void FUN_005e6710(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983da8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c48ec;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c48cc;
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


// ==== FUN_005e67c0 @ 0x005e67c0 ====

void FUN_005e67c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e67e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e67e0 @ 0x005e67e0 ====

void FUN_005e67e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983dd3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c48ec;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c48cc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c489c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_005e6860 @ 0x005e6860 ====

void * FUN_005e6860(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00983deb;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c4900,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005e6940 @ 0x005e6940 ====

undefined4 FUN_005e6940(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4900,0xa9);
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


// ==== FUN_005e69c0 @ 0x005e69c0 ====

void FUN_005e69c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e6530();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e69e0 @ 0x005e69e0 ====

void FUN_005e69e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c497c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005e6a00 @ 0x005e6a00 ====

void FUN_005e6a00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983e13;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4984;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c497c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c48b4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_005e6a80 @ 0x005e6a80 ====

undefined4 FUN_005e6a80(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4900,0xa9);
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


// ==== FUN_005e6b00 @ 0x005e6b00 ====

undefined4 * FUN_005e6b00(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4900,0x85);
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


// ==== FUN_005e6bc0 @ 0x005e6bc0 ====

void FUN_005e6bc0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e69e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6be0 @ 0x005e6be0 ====

void FUN_005e6be0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e6a00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6c00 @ 0x005e6c00 ====

void FUN_005e6c00(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983e28;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4984;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c497c;
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


// ==== FUN_005e6cb0 @ 0x005e6cb0 ====

void FUN_005e6cb0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983e48;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c499c;
  FUN_005e6c00();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e6d10 @ 0x005e6d10 ====

void FUN_005e6d10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e6d30(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e6d30 @ 0x005e6d30 ====

void FUN_005e6d30(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005e6d30(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005e6d30(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e6d70 @ 0x005e6d70 ====

void FUN_005e6d70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e6d90(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e6d90 @ 0x005e6d90 ====

void FUN_005e6d90(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005e6d90(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005e6d90(param_1[3]);
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


// ==== FUN_005e6e00 @ 0x005e6e00 ====

void FUN_005e6e00(byte param_1)

{
  void *in_ECX;
  
  FUN_005e6e20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6e20 @ 0x005e6e20 ====

void FUN_005e6e20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00983e73;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c499c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005e6d90(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005e6a00();
  *in_ECX = &PTR_FUN_009c4844;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e6e90 @ 0x005e6e90 ====

void FUN_005e6e90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c49f4;
  return;
}


// ==== FUN_005e6ea0 @ 0x005e6ea0 ====

void FUN_005e6ea0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c49f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6ec0 @ 0x005e6ec0 ====

void FUN_005e6ec0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4a0c;
  return;
}


// ==== FUN_005e6ed0 @ 0x005e6ed0 ====

void FUN_005e6ed0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4a64;
  return;
}


// ==== FUN_005e6ee0 @ 0x005e6ee0 ====

void FUN_005e6ee0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4a7c;
  return;
}


// ==== FUN_005e6ef0 @ 0x005e6ef0 ====

void FUN_005e6ef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4a0c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6f10 @ 0x005e6f10 ====

void FUN_005e6f10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4a64;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6f30 @ 0x005e6f30 ====

void FUN_005e6f30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4a7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e6f50 @ 0x005e6f50 ====

undefined4 FUN_005e6f50(undefined2 param_1)

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


// ==== FUN_005e6f80 @ 0x005e6f80 ====

undefined4 FUN_005e6f80(void)

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


// ==== FUN_005e6fa0 @ 0x005e6fa0 ====

undefined4 FUN_005e6fa0(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 4);
    }
  }
  return 0;
}


// ==== FUN_005e6fd0 @ 0x005e6fd0 ====

void FUN_005e6fd0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983e88;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c4a9c;
  DAT_00b5ab54 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c49f4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005e7070 @ 0x005e7070 ====

void FUN_005e7070(undefined2 *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined2 *puVar3;
  int in_ECX;
  void *unaff_EDI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00983e9d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x10);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0060d5a0();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 8))(param_1);
  puVar3 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = *param_1;
  *(int **)(puVar3 + 2) = piVar2;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  ExceptionList = unaff_EDI;
  return;
}


// ==== FUN_005e7100 @ 0x005e7100 ====

void FUN_005e7100(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00983ec5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4a9c;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e7210();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x1028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e77b0(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab54 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab54 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e71d0 @ 0x005e71d0 ====

void FUN_005e71d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4a94;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005e71f0 @ 0x005e71f0 ====

void FUN_005e71f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e71d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e7210 @ 0x005e7210 ====

void FUN_005e7210(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983ed8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4ab4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c4a94;
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


// ==== FUN_005e72c0 @ 0x005e72c0 ====

void FUN_005e72c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e72e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e72e0 @ 0x005e72e0 ====

void FUN_005e72e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983f03;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4ab4;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c4a94;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c4a64;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_005e7360 @ 0x005e7360 ====

void * FUN_005e7360(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00983f1b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c4ac8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005e7440 @ 0x005e7440 ====

undefined4 FUN_005e7440(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4ac8,0xa9);
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


// ==== FUN_005e74c0 @ 0x005e74c0 ====

void FUN_005e74c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e6fd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e74e0 @ 0x005e74e0 ====

void FUN_005e74e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4b44;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005e7500 @ 0x005e7500 ====

void FUN_005e7500(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983f43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4b4c;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c4b44;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c4a7c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_005e7580 @ 0x005e7580 ====

undefined4 FUN_005e7580(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4ac8,0xa9);
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


// ==== FUN_005e7600 @ 0x005e7600 ====

undefined4 * FUN_005e7600(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4ac8,0x85);
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


// ==== FUN_005e76c0 @ 0x005e76c0 ====

void FUN_005e76c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e74e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e76e0 @ 0x005e76e0 ====

void FUN_005e76e0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e7500();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e7700 @ 0x005e7700 ====

void FUN_005e7700(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983f58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4b4c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c4b44;
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


// ==== FUN_005e77b0 @ 0x005e77b0 ====

void FUN_005e77b0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983f78;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4b64;
  FUN_005e7700();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e7810 @ 0x005e7810 ====

void FUN_005e7810(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e7830(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e7830 @ 0x005e7830 ====

void FUN_005e7830(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005e7830(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005e7830(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e7870 @ 0x005e7870 ====

void FUN_005e7870(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e7890(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e7890 @ 0x005e7890 ====

void FUN_005e7890(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005e7890(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005e7890(param_1[3]);
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


// ==== FUN_005e7900 @ 0x005e7900 ====

void FUN_005e7900(byte param_1)

{
  void *in_ECX;
  
  FUN_005e7920();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e7920 @ 0x005e7920 ====

void FUN_005e7920(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00983fa3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4b64;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005e7890(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005e7500();
  *in_ECX = &PTR_FUN_009c4a0c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e7990 @ 0x005e7990 ====

void FUN_005e7990(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4bbc;
  return;
}


// ==== FUN_005e79a0 @ 0x005e79a0 ====

void FUN_005e79a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4bbc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e79c0 @ 0x005e79c0 ====

void FUN_005e79c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4bcc;
  return;
}


// ==== FUN_005e79d0 @ 0x005e79d0 ====

void FUN_005e79d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4be4;
  return;
}


// ==== FUN_005e79e0 @ 0x005e79e0 ====

void FUN_005e79e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4c3c;
  return;
}


// ==== FUN_005e79f0 @ 0x005e79f0 ====

void FUN_005e79f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4bcc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e7a10 @ 0x005e7a10 ====

void FUN_005e7a10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4be4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e7a30 @ 0x005e7a30 ====

void FUN_005e7a30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4c3c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e7a50 @ 0x005e7a50 ====

undefined4 FUN_005e7a50(undefined2 param_1)

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


// ==== FUN_005e7a80 @ 0x005e7a80 ====

void FUN_005e7a80(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983fb8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c4c5c;
  DAT_00b5ab60 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c4bbc;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005e7b20 @ 0x005e7b20 ====

void FUN_005e7b20(undefined4 param_1,void *param_2)

{
  void *pvVar1;
  int *piVar2;
  undefined2 *puVar3;
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00983fcd;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x28);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0060d670();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 8))();
  puVar3 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = puStack_8._0_2_;
  *(int **)(puVar3 + 2) = piVar2;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  ExceptionList = param_2;
  return;
}


// ==== FUN_005e7bb0 @ 0x005e7bb0 ====

void FUN_005e7bb0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00983ff5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4c5c;
  pvVar2 = operator_new(0x5018);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e7cc0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x8028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e8260(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab60 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab60 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e7c80 @ 0x005e7c80 ====

void FUN_005e7c80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4c54;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_005e7ca0 @ 0x005e7ca0 ====

void FUN_005e7ca0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e7c80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e7cc0 @ 0x005e7cc0 ====

void FUN_005e7cc0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984008;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4c6c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c4c54;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x400,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x1402] = 0;
  in_ECX[0x1402] = in_ECX[0x1402] + 0x400;
  in_ECX[0x1405] = in_ECX + 2;
  in_ECX[0x1403] = 0;
  in_ECX[0x1404] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x13ff] = 0;
  in_ECX[0x1400] = 0;
  in_ECX[0x1401] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e7d70 @ 0x005e7d70 ====

void FUN_005e7d70(byte param_1)

{
  void *in_ECX;
  
  FUN_005e7d90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e7d90 @ 0x005e7d90 ====

void FUN_005e7d90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984033;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4c6c;
  local_4 = 1;
  if ((void *)in_ECX[0x1404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c4c54;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x400,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c4bcc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1404]);
  return;
}


// ==== FUN_005e7e10 @ 0x005e7e10 ====

void * FUN_005e7e10(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098404b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x5014);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x500c) = *(int *)(in_ECX + 0x500c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x5010);
      *(void **)(in_ECX + 0x5010) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x5014) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c4c80,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005e7ef0 @ 0x005e7ef0 ====

undefined4 FUN_005e7ef0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4c80,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x5014);
    *(int *)(in_ECX + 0x500c) = *(int *)(in_ECX + 0x500c) + -1;
    *(int *)(in_ECX + 0x5014) = param_2;
  }
  return 0;
}


// ==== FUN_005e7f70 @ 0x005e7f70 ====

void FUN_005e7f70(byte param_1)

{
  void *in_ECX;
  
  FUN_005e7a80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e7f90 @ 0x005e7f90 ====

void FUN_005e7f90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4d10;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_005e7fb0 @ 0x005e7fb0 ====

void FUN_005e7fb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984073;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4d18;
  local_4 = 1;
  if ((void *)in_ECX[0x2004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c4d10;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x400,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c4c3c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x2004]);
  return;
}


// ==== FUN_005e8030 @ 0x005e8030 ====

undefined4 FUN_005e8030(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4c80,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x8014);
    *(int *)(in_ECX + 0x800c) = *(int *)(in_ECX + 0x800c) + -1;
    *(int *)(in_ECX + 0x8014) = param_2;
  }
  return 0;
}


// ==== FUN_005e80b0 @ 0x005e80b0 ====

undefined4 * FUN_005e80b0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4c80,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x8014);
  *(int *)(in_ECX + 0x800c) = *(int *)(in_ECX + 0x800c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x8010);
    *(undefined4 **)(in_ECX + 0x8010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x8014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005e8170 @ 0x005e8170 ====

void FUN_005e8170(byte param_1)

{
  void *in_ECX;
  
  FUN_005e7f90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8190 @ 0x005e8190 ====

void FUN_005e8190(byte param_1)

{
  void *in_ECX;
  
  FUN_005e7fb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e81b0 @ 0x005e81b0 ====

void FUN_005e81b0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984088;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4d18;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c4d10;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x400,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x2002] = 0;
  in_ECX[0x2002] = in_ECX[0x2002] + 0x400;
  in_ECX[0x2005] = in_ECX + 2;
  in_ECX[0x2003] = 0;
  in_ECX[0x2004] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x1fff] = 0;
  in_ECX[0x2000] = 0;
  in_ECX[0x2001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e8260 @ 0x005e8260 ====

void FUN_005e8260(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009840a8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4d34;
  FUN_005e81b0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e82c0 @ 0x005e82c0 ====

void FUN_005e82c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e82e0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e82e0 @ 0x005e82e0 ====

void FUN_005e82e0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005e82e0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005e82e0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e8320 @ 0x005e8320 ====

void FUN_005e8320(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e8340(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e8340 @ 0x005e8340 ====

void FUN_005e8340(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005e8340(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005e8340(param_1[3]);
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


// ==== FUN_005e83b0 @ 0x005e83b0 ====

void FUN_005e83b0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e83d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e83d0 @ 0x005e83d0 ====

void FUN_005e83d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009840d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4d34;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005e8340(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005e7fb0();
  *in_ECX = &PTR_FUN_009c4be4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e8440 @ 0x005e8440 ====

void FUN_005e8440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4d8c;
  return;
}


// ==== FUN_005e8450 @ 0x005e8450 ====

void FUN_005e8450(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4d8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8470 @ 0x005e8470 ====

void FUN_005e8470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4d9c;
  return;
}


// ==== FUN_005e8480 @ 0x005e8480 ====

void FUN_005e8480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4db4;
  return;
}


// ==== FUN_005e8490 @ 0x005e8490 ====

void FUN_005e8490(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4e0c;
  return;
}


// ==== FUN_005e84a0 @ 0x005e84a0 ====

void FUN_005e84a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4d9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e84c0 @ 0x005e84c0 ====

void FUN_005e84c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4db4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e84e0 @ 0x005e84e0 ====

void FUN_005e84e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4e0c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8500 @ 0x005e8500 ====

undefined4 FUN_005e8500(undefined2 param_1)

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


// ==== FUN_005e8530 @ 0x005e8530 ====

void FUN_005e8530(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009840e8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c4e2c;
  DAT_00b5ab64 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c4d8c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005e85d0 @ 0x005e85d0 ====

void FUN_005e85d0(undefined4 param_1,void *param_2)

{
  void *pvVar1;
  int *piVar2;
  undefined2 *puVar3;
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009840fd;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0xb0);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0060d710();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 8))();
  puVar3 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = puStack_8._0_2_;
  *(int **)(puVar3 + 2) = piVar2;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  ExceptionList = param_2;
  return;
}


// ==== FUN_005e8660 @ 0x005e8660 ====

void FUN_005e8660(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00984125;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4e2c;
  pvVar2 = operator_new(0x5018);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e8770();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x8028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e8d10(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab64 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab64 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e8730 @ 0x005e8730 ====

void FUN_005e8730(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4e24;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_005e8750 @ 0x005e8750 ====

void FUN_005e8750(byte param_1)

{
  void *in_ECX;
  
  FUN_005e8730();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8770 @ 0x005e8770 ====

void FUN_005e8770(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984138;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4e3c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c4e24;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x400,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x1402] = 0;
  in_ECX[0x1402] = in_ECX[0x1402] + 0x400;
  in_ECX[0x1405] = in_ECX + 2;
  in_ECX[0x1403] = 0;
  in_ECX[0x1404] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x13ff] = 0;
  in_ECX[0x1400] = 0;
  in_ECX[0x1401] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e8820 @ 0x005e8820 ====

void FUN_005e8820(byte param_1)

{
  void *in_ECX;
  
  FUN_005e8840();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8840 @ 0x005e8840 ====

void FUN_005e8840(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984163;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4e3c;
  local_4 = 1;
  if ((void *)in_ECX[0x1404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c4e24;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x400,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c4d9c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1404]);
  return;
}


// ==== FUN_005e88c0 @ 0x005e88c0 ====

void * FUN_005e88c0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098417b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x5014);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x500c) = *(int *)(in_ECX + 0x500c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x5010);
      *(void **)(in_ECX + 0x5010) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x5014) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c4e50,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005e89a0 @ 0x005e89a0 ====

undefined4 FUN_005e89a0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4e50,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x5014);
    *(int *)(in_ECX + 0x500c) = *(int *)(in_ECX + 0x500c) + -1;
    *(int *)(in_ECX + 0x5014) = param_2;
  }
  return 0;
}


// ==== FUN_005e8a20 @ 0x005e8a20 ====

void FUN_005e8a20(byte param_1)

{
  void *in_ECX;
  
  FUN_005e8530();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8a40 @ 0x005e8a40 ====

void FUN_005e8a40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c4ed0;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_005e8a60 @ 0x005e8a60 ====

void FUN_005e8a60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009841a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4ed8;
  local_4 = 1;
  if ((void *)in_ECX[0x2004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c4ed0;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x400,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c4e0c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x2004]);
  return;
}


// ==== FUN_005e8ae0 @ 0x005e8ae0 ====

undefined4 FUN_005e8ae0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4e50,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x8014);
    *(int *)(in_ECX + 0x800c) = *(int *)(in_ECX + 0x800c) + -1;
    *(int *)(in_ECX + 0x8014) = param_2;
  }
  return 0;
}


// ==== FUN_005e8b60 @ 0x005e8b60 ====

undefined4 * FUN_005e8b60(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c4e50,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x8014);
  *(int *)(in_ECX + 0x800c) = *(int *)(in_ECX + 0x800c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x8010);
    *(undefined4 **)(in_ECX + 0x8010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x8014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005e8c20 @ 0x005e8c20 ====

void FUN_005e8c20(byte param_1)

{
  void *in_ECX;
  
  FUN_005e8a40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8c40 @ 0x005e8c40 ====

void FUN_005e8c40(byte param_1)

{
  void *in_ECX;
  
  FUN_005e8a60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8c60 @ 0x005e8c60 ====

void FUN_005e8c60(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009841b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4ed8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c4ed0;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x400,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x2002] = 0;
  in_ECX[0x2002] = in_ECX[0x2002] + 0x400;
  in_ECX[0x2005] = in_ECX + 2;
  in_ECX[0x2003] = 0;
  in_ECX[0x2004] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x1fff] = 0;
  in_ECX[0x2000] = 0;
  in_ECX[0x2001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e8d10 @ 0x005e8d10 ====

void FUN_005e8d10(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009841d8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4ef4;
  FUN_005e8c60();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e8d70 @ 0x005e8d70 ====

void FUN_005e8d70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e8d90(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e8d90 @ 0x005e8d90 ====

void FUN_005e8d90(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005e8d90(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005e8d90(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e8dd0 @ 0x005e8dd0 ====

void FUN_005e8dd0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e8df0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e8df0 @ 0x005e8df0 ====

void FUN_005e8df0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005e8df0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005e8df0(param_1[3]);
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


// ==== FUN_005e8e60 @ 0x005e8e60 ====

void FUN_005e8e60(byte param_1)

{
  void *in_ECX;
  
  FUN_005e8e80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8e80 @ 0x005e8e80 ====

void FUN_005e8e80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00984203;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c4ef4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005e8df0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005e8a60();
  *in_ECX = &PTR_FUN_009c4db4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e8ef0 @ 0x005e8ef0 ====

void FUN_005e8ef0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c500c;
  return;
}


// ==== FUN_005e8f00 @ 0x005e8f00 ====

void FUN_005e8f00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c500c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8f20 @ 0x005e8f20 ====

void FUN_005e8f20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5024;
  return;
}


// ==== FUN_005e8f30 @ 0x005e8f30 ====

void FUN_005e8f30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c507c;
  return;
}


// ==== FUN_005e8f40 @ 0x005e8f40 ====

void FUN_005e8f40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5094;
  return;
}


// ==== FUN_005e8f50 @ 0x005e8f50 ====

void FUN_005e8f50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5024;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8f70 @ 0x005e8f70 ====

void FUN_005e8f70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c507c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8f90 @ 0x005e8f90 ====

void FUN_005e8f90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5094;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e8fb0 @ 0x005e8fb0 ====

undefined4 FUN_005e8fb0(undefined1 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_8 [8];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_005e8fe0 @ 0x005e8fe0 ====

void FUN_005e8fe0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984218;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c50b4;
  DAT_00b5ab70 = 0;
  local_4 = 0;
  for (piVar3 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar3 != (int *)0x0;
      piVar3 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar3)) {
    iVar1 = *piVar3;
    puVar2 = *(undefined4 **)(iVar1 + 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c500c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005e9080 @ 0x005e9080 ====

void FUN_005e9080(undefined1 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined1 *puVar4;
  int in_ECX;
  undefined1 local_214 [4];
  undefined1 auStack_210 [244];
  undefined1 auStack_11c [256];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00984230;
  pvStack_c = ExceptionList;
  local_214[0] = *param_1;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_214);
  if (iVar1 != 0) {
    auStack_210[0] = 0;
    uVar2 = FUN_0044a580(auStack_210,s_Duplicate_FishingSkill_Data____c_009c4f4c,*param_1);
    FUN_00797b80(uVar2);
    auStack_210[0] = 0;
    uVar2 = FUN_0044a580(auStack_210,s_File___s__Line___d_009c4fac,
                         s___Article_Fish_FishingSkill_Flyw_009c4f78,0x31);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  pvVar3 = operator_new(8);
  puStack_8 = (undefined1 *)0x0;
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060d8f0();
  }
  puStack_8 = (undefined1 *)0xffffffff;
  FUN_0060d8e0(param_1);
  puVar4 = (undefined1 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar4 = *param_1;
  *(undefined4 *)(puVar4 + 4) = uVar2;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar4);
  if (iVar1 != 0) {
    auStack_11c[0] = 0;
    uVar2 = FUN_0044a580(auStack_11c,s_File___s__Line___d_009c4ff4,
                         s___Article_Fish_FishingSkill_Flyw_009c4fc0,0x3c);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_005e91b0 @ 0x005e91b0 ====

uint FUN_005e91b0(int param_1)

{
  int *piVar1;
  int *piVar2;
  undefined1 *puVar3;
  int iVar4;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x40) + 0x20))();
  if (*(int **)(param_1 + 4) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0x18))();
  }
  puVar3 = (undefined1 *)(**(code **)(*piVar2 + 8))();
  piVar2 = (int *)(**(code **)(*in_ECX + 8))(*puVar3);
  iVar4 = (**(code **)(*piVar2 + 4))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x18))(*(undefined2 *)(iVar4 + 2));
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
  puVar3 = (undefined1 *)(**(code **)(*piVar1 + 0xc))();
  return CONCAT31((int3)((uint)puVar3 >> 8),*puVar3) & 0xffffff0f;
}


// ==== FUN_005e9220 @ 0x005e9220 ====

void FUN_005e9220(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00984258;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c50b4;
  pvVar2 = operator_new(0x2818);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e9330();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x4028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e98a0(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab70 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab70 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e92f0 @ 0x005e92f0 ====

void FUN_005e92f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c50ac;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_005e9310 @ 0x005e9310 ====

void FUN_005e9310(byte param_1)

{
  void *in_ECX;
  
  FUN_005e92f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e9330 @ 0x005e9330 ====

void FUN_005e9330(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984278;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c50c8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c50ac;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x200,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0xa02] = 0;
  in_ECX[0xa02] = in_ECX[0xa02] + 0x200;
  in_ECX[0xa05] = in_ECX + 2;
  in_ECX[0xa03] = 0;
  in_ECX[0xa04] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x9ff] = 0;
  in_ECX[0xa00] = 0;
  in_ECX[0xa01] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e93e0 @ 0x005e93e0 ====

void FUN_005e93e0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e9400();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e9400 @ 0x005e9400 ====

void FUN_005e9400(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009842a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c50c8;
  local_4 = 1;
  if ((void *)in_ECX[0xa04] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c50ac;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x200,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c507c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xa04]);
  return;
}


// ==== FUN_005e9480 @ 0x005e9480 ====

void * FUN_005e9480(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c50e0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x2814);
  *(int *)(in_ECX + 0x280c) = *(int *)(in_ECX + 0x280c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0x2810);
    *(void **)(in_ECX + 0x2810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x2814) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_005e9530 @ 0x005e9530 ====

undefined4 FUN_005e9530(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c50e0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x2814);
    *(int *)(in_ECX + 0x280c) = *(int *)(in_ECX + 0x280c) + -1;
    *(int *)(in_ECX + 0x2814) = param_2;
  }
  return 0;
}


// ==== FUN_005e95b0 @ 0x005e95b0 ====

void FUN_005e95b0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e8fe0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e95d0 @ 0x005e95d0 ====

void FUN_005e95d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5168;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_005e95f0 @ 0x005e95f0 ====

void FUN_005e95f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009842c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5170;
  local_4 = 1;
  if ((void *)in_ECX[0x1004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c5168;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x200,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c5094;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1004]);
  return;
}


// ==== FUN_005e9670 @ 0x005e9670 ====

undefined4 FUN_005e9670(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c50e0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x4014);
    *(int *)(in_ECX + 0x400c) = *(int *)(in_ECX + 0x400c) + -1;
    *(int *)(in_ECX + 0x4014) = param_2;
  }
  return 0;
}


// ==== FUN_005e96f0 @ 0x005e96f0 ====

undefined4 * FUN_005e96f0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c50e0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x4014);
  *(int *)(in_ECX + 0x400c) = *(int *)(in_ECX + 0x400c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x4010);
    *(undefined4 **)(in_ECX + 0x4010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x4014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005e97b0 @ 0x005e97b0 ====

void FUN_005e97b0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e95d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e97d0 @ 0x005e97d0 ====

void FUN_005e97d0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e95f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e97f0 @ 0x005e97f0 ====

void FUN_005e97f0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009842d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5170;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c5168;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x200,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x1002] = 0;
  in_ECX[0x1002] = in_ECX[0x1002] + 0x200;
  in_ECX[0x1005] = in_ECX + 2;
  in_ECX[0x1003] = 0;
  in_ECX[0x1004] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0xfff] = 0;
  in_ECX[0x1000] = 0;
  in_ECX[0x1001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e98a0 @ 0x005e98a0 ====

void FUN_005e98a0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009842f8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c518c;
  FUN_005e97f0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e9900 @ 0x005e9900 ====

void FUN_005e9900(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e9920(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e9920 @ 0x005e9920 ====

void FUN_005e9920(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005e9920(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005e9920(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005e9960 @ 0x005e9960 ====

void FUN_005e9960(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005e9980(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005e9980 @ 0x005e9980 ====

void FUN_005e9980(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005e9980(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005e9980(param_1[3]);
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


// ==== FUN_005e9a00 @ 0x005e9a00 ====

void FUN_005e9a00(byte param_1)

{
  void *in_ECX;
  
  FUN_005e9a20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e9a20 @ 0x005e9a20 ====

void FUN_005e9a20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00984323;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c518c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005e9980(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005e95f0();
  *in_ECX = &PTR_FUN_009c5024;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e9a90 @ 0x005e9a90 ====

void FUN_005e9a90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c529c;
  return;
}


// ==== FUN_005e9aa0 @ 0x005e9aa0 ====

void FUN_005e9aa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c529c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e9ac0 @ 0x005e9ac0 ====

void FUN_005e9ac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c52ac;
  return;
}


// ==== FUN_005e9ad0 @ 0x005e9ad0 ====

void FUN_005e9ad0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5304;
  return;
}


// ==== FUN_005e9ae0 @ 0x005e9ae0 ====

void FUN_005e9ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c531c;
  return;
}


// ==== FUN_005e9af0 @ 0x005e9af0 ====

void FUN_005e9af0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c52ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e9b10 @ 0x005e9b10 ====

void FUN_005e9b10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5304;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e9b30 @ 0x005e9b30 ====

void FUN_005e9b30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c531c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e9b50 @ 0x005e9b50 ====

undefined4 FUN_005e9b50(undefined2 param_1)

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


// ==== FUN_005e9b80 @ 0x005e9b80 ====

void FUN_005e9b80(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984338;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c533c;
  DAT_00b5ab74 = 0;
  local_4 = 0;
  for (piVar3 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar3 != (int *)0x0;
      piVar3 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar3)) {
    iVar1 = *piVar3;
    puVar2 = *(undefined4 **)(iVar1 + 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c529c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005e9c20 @ 0x005e9c20 ====

void FUN_005e9c20(undefined2 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined2 *puVar4;
  int in_ECX;
  undefined2 local_214 [2];
  undefined1 auStack_210 [240];
  undefined1 auStack_120 [256];
  void *pvStack_20;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00984350;
  pvStack_c = ExceptionList;
  local_214[0] = *param_1;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_214);
  if (iVar1 != 0) {
    auStack_210[0] = 0;
    uVar2 = FUN_0044a580(auStack_210,s_Duplicate_Fish_Data____index__d_009c51e4,*param_1);
    FUN_00797b80(uVar2);
    auStack_210[0] = 0;
    uVar2 = FUN_0044a580(auStack_210,s_File___s__Line___d_009c523c,
                         s___Article_Fish_FishingRod_Flywei_009c5208,0x2c);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  pvVar3 = operator_new(0x118);
  puStack_8 = (undefined1 *)0x0;
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060d960();
  }
  puStack_8 = (undefined1 *)0xffffffff;
  FUN_0060d970(param_1);
  puVar4 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar4 = *param_1;
  *(undefined4 *)(puVar4 + 2) = uVar2;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar4);
  if (iVar1 != 0) {
    auStack_120[0] = 0;
    uVar2 = FUN_0044a580(auStack_120,s_File___s__Line___d_009c5284,
                         s___Article_Fish_FishingRod_Flywei_009c5250,0x37);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  ExceptionList = pvStack_20;
  return;
}


// ==== FUN_005e9d60 @ 0x005e9d60 ====

void FUN_005e9d60(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00984378;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c533c;
  pvVar2 = operator_new(0x2818);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005e9e70();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x4028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005ea3e0(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab74 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab74 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e9e30 @ 0x005e9e30 ====

void FUN_005e9e30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5334;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_005e9e50 @ 0x005e9e50 ====

void FUN_005e9e50(byte param_1)

{
  void *in_ECX;
  
  FUN_005e9e30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e9e70 @ 0x005e9e70 ====

void FUN_005e9e70(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984398;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c534c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c5334;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x200,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0xa02] = 0;
  in_ECX[0xa02] = in_ECX[0xa02] + 0x200;
  in_ECX[0xa05] = in_ECX + 2;
  in_ECX[0xa03] = 0;
  in_ECX[0xa04] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x9ff] = 0;
  in_ECX[0xa00] = 0;
  in_ECX[0xa01] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005e9f20 @ 0x005e9f20 ====

undefined4 FUN_005e9f20(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5360,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x2814);
    *(int *)(in_ECX + 0x280c) = *(int *)(in_ECX + 0x280c) + -1;
    *(int *)(in_ECX + 0x2814) = param_2;
  }
  return 0;
}


// ==== FUN_005e9fa0 @ 0x005e9fa0 ====

void FUN_005e9fa0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e9fc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005e9fc0 @ 0x005e9fc0 ====

void FUN_005e9fc0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009843c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c534c;
  local_4 = 1;
  if ((void *)in_ECX[0xa04] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c5334;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x200,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c5304;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xa04]);
  return;
}


// ==== FUN_005ea040 @ 0x005ea040 ====

void * FUN_005ea040(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5360,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x2814);
  *(int *)(in_ECX + 0x280c) = *(int *)(in_ECX + 0x280c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0x2810);
    *(void **)(in_ECX + 0x2810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x2814) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_005ea0f0 @ 0x005ea0f0 ====

void FUN_005ea0f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005e9b80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ea110 @ 0x005ea110 ====

void FUN_005ea110(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c53e8;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_005ea130 @ 0x005ea130 ====

void FUN_005ea130(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009843e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c53f0;
  local_4 = 1;
  if ((void *)in_ECX[0x1004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c53e8;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x200,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c531c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1004]);
  return;
}


// ==== FUN_005ea1b0 @ 0x005ea1b0 ====

undefined4 FUN_005ea1b0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5360,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x4014);
    *(int *)(in_ECX + 0x400c) = *(int *)(in_ECX + 0x400c) + -1;
    *(int *)(in_ECX + 0x4014) = param_2;
  }
  return 0;
}


// ==== FUN_005ea230 @ 0x005ea230 ====

undefined4 * FUN_005ea230(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5360,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x4014);
  *(int *)(in_ECX + 0x400c) = *(int *)(in_ECX + 0x400c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x4010);
    *(undefined4 **)(in_ECX + 0x4010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x4014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005ea2f0 @ 0x005ea2f0 ====

void FUN_005ea2f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ea110();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ea310 @ 0x005ea310 ====

void FUN_005ea310(byte param_1)

{
  void *in_ECX;
  
  FUN_005ea130();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ea330 @ 0x005ea330 ====

void FUN_005ea330(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009843f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c53f0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c53e8;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x200,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x1002] = 0;
  in_ECX[0x1002] = in_ECX[0x1002] + 0x200;
  in_ECX[0x1005] = in_ECX + 2;
  in_ECX[0x1003] = 0;
  in_ECX[0x1004] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0xfff] = 0;
  in_ECX[0x1000] = 0;
  in_ECX[0x1001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ea3e0 @ 0x005ea3e0 ====

void FUN_005ea3e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984418;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c540c;
  FUN_005ea330();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ea440 @ 0x005ea440 ====

void FUN_005ea440(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005ea460(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005ea460 @ 0x005ea460 ====

void FUN_005ea460(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005ea460(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005ea460(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005ea4a0 @ 0x005ea4a0 ====

void FUN_005ea4a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005ea4c0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005ea4c0 @ 0x005ea4c0 ====

void FUN_005ea4c0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005ea4c0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005ea4c0(param_1[3]);
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


// ==== FUN_005ea530 @ 0x005ea530 ====

void FUN_005ea530(byte param_1)

{
  void *in_ECX;
  
  FUN_005ea550();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ea550 @ 0x005ea550 ====

void FUN_005ea550(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00984443;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c540c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005ea4c0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005ea130();
  *in_ECX = &PTR_FUN_009c52ac;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ea5c0 @ 0x005ea5c0 ====

void FUN_005ea5c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5504;
  return;
}


// ==== FUN_005ea5d0 @ 0x005ea5d0 ====

void FUN_005ea5d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5504;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ea5f0 @ 0x005ea5f0 ====

void FUN_005ea5f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5514;
  return;
}


// ==== FUN_005ea600 @ 0x005ea600 ====

void FUN_005ea600(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c556c;
  return;
}


// ==== FUN_005ea610 @ 0x005ea610 ====

void FUN_005ea610(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5584;
  return;
}


// ==== FUN_005ea620 @ 0x005ea620 ====

void FUN_005ea620(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5514;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ea640 @ 0x005ea640 ====

void FUN_005ea640(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c556c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ea660 @ 0x005ea660 ====

void FUN_005ea660(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5584;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ea680 @ 0x005ea680 ====

undefined4 FUN_005ea680(undefined2 param_1)

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


// ==== FUN_005ea6b0 @ 0x005ea6b0 ====

void FUN_005ea6b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984458;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c55a4;
  DAT_00b5ab78 = 0;
  local_4 = 0;
  for (piVar3 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar3 != (int *)0x0;
      piVar3 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar3)) {
    iVar1 = *piVar3;
    puVar2 = *(undefined4 **)(iVar1 + 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c5504;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005ea750 @ 0x005ea750 ====

void FUN_005ea750(undefined2 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined2 *puVar4;
  int in_ECX;
  undefined2 local_214 [2];
  undefined1 auStack_210 [244];
  undefined1 auStack_11c [256];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00984470;
  pvStack_c = ExceptionList;
  local_214[0] = *param_1;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_214);
  if (iVar1 != 0) {
    auStack_210[0] = 0;
    uVar2 = FUN_0044a580(auStack_210,s_Duplicate_Fish_Data____index__d_009c5464,*param_1);
    FUN_00797b80(uVar2);
    auStack_210[0] = 0;
    uVar2 = FUN_0044a580(auStack_210,s_File___s__Line___d_009c54b0,
                         s___Article_Fish_Flyweight_Contain_009c5488,0x2c);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  pvVar3 = operator_new(0xb0);
  puStack_8 = (undefined1 *)0x0;
  if (pvVar3 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0060da80();
  }
  puStack_8 = (undefined1 *)0xffffffff;
  FUN_0060da40(param_1);
  puVar4 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar4 = *param_1;
  *(undefined4 *)(puVar4 + 2) = uVar2;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar4);
  if (iVar1 != 0) {
    auStack_11c[0] = 0;
    uVar2 = FUN_0044a580(auStack_11c,s_File___s__Line___d_009c54ec,
                         s___Article_Fish_Flyweight_Contain_009c54c4,0x37);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_005ea890 @ 0x005ea890 ====

void FUN_005ea890(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00984498;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c55a4;
  pvVar2 = operator_new(0x2818);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005ea9a0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x4028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005eaf10(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab78 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab78 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ea960 @ 0x005ea960 ====

void FUN_005ea960(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c559c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_005ea980 @ 0x005ea980 ====

void FUN_005ea980(byte param_1)

{
  void *in_ECX;
  
  FUN_005ea960();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ea9a0 @ 0x005ea9a0 ====

void FUN_005ea9a0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009844b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c55b4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c559c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x200,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0xa02] = 0;
  in_ECX[0xa02] = in_ECX[0xa02] + 0x200;
  in_ECX[0xa05] = in_ECX + 2;
  in_ECX[0xa03] = 0;
  in_ECX[0xa04] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x9ff] = 0;
  in_ECX[0xa00] = 0;
  in_ECX[0xa01] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eaa50 @ 0x005eaa50 ====

void FUN_005eaa50(byte param_1)

{
  void *in_ECX;
  
  FUN_005eaa70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eaa70 @ 0x005eaa70 ====

void FUN_005eaa70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009844e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c55b4;
  local_4 = 1;
  if ((void *)in_ECX[0xa04] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c559c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x200,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c556c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xa04]);
  return;
}


// ==== FUN_005eaaf0 @ 0x005eaaf0 ====

void * FUN_005eaaf0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c55c8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x2814);
  *(int *)(in_ECX + 0x280c) = *(int *)(in_ECX + 0x280c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0x2810);
    *(void **)(in_ECX + 0x2810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x2814) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_005eaba0 @ 0x005eaba0 ====

undefined4 FUN_005eaba0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c55c8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x2814);
    *(int *)(in_ECX + 0x280c) = *(int *)(in_ECX + 0x280c) + -1;
    *(int *)(in_ECX + 0x2814) = param_2;
  }
  return 0;
}


// ==== FUN_005eac20 @ 0x005eac20 ====

void FUN_005eac20(byte param_1)

{
  void *in_ECX;
  
  FUN_005ea6b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eac40 @ 0x005eac40 ====

void FUN_005eac40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5640;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_005eac60 @ 0x005eac60 ====

void FUN_005eac60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984503;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5648;
  local_4 = 1;
  if ((void *)in_ECX[0x1004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c5640;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x200,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c5584;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1004]);
  return;
}


// ==== FUN_005eace0 @ 0x005eace0 ====

undefined4 FUN_005eace0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c55c8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x4014);
    *(int *)(in_ECX + 0x400c) = *(int *)(in_ECX + 0x400c) + -1;
    *(int *)(in_ECX + 0x4014) = param_2;
  }
  return 0;
}


// ==== FUN_005ead60 @ 0x005ead60 ====

undefined4 * FUN_005ead60(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c55c8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x4014);
  *(int *)(in_ECX + 0x400c) = *(int *)(in_ECX + 0x400c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x4010);
    *(undefined4 **)(in_ECX + 0x4010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x4014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005eae20 @ 0x005eae20 ====

void FUN_005eae20(byte param_1)

{
  void *in_ECX;
  
  FUN_005eac40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eae40 @ 0x005eae40 ====

void FUN_005eae40(byte param_1)

{
  void *in_ECX;
  
  FUN_005eac60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eae60 @ 0x005eae60 ====

void FUN_005eae60(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984518;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5648;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c5640;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x200,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x1002] = 0;
  in_ECX[0x1002] = in_ECX[0x1002] + 0x200;
  in_ECX[0x1005] = in_ECX + 2;
  in_ECX[0x1003] = 0;
  in_ECX[0x1004] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0xfff] = 0;
  in_ECX[0x1000] = 0;
  in_ECX[0x1001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eaf10 @ 0x005eaf10 ====

void FUN_005eaf10(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984538;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5664;
  FUN_005eae60();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eaf70 @ 0x005eaf70 ====

void FUN_005eaf70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005eaf90(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005eaf90 @ 0x005eaf90 ====

void FUN_005eaf90(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005eaf90(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005eaf90(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005eafd0 @ 0x005eafd0 ====

void FUN_005eafd0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005eaff0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005eaff0 @ 0x005eaff0 ====

void FUN_005eaff0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005eaff0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005eaff0(param_1[3]);
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


// ==== FUN_005eb060 @ 0x005eb060 ====

void FUN_005eb060(byte param_1)

{
  void *in_ECX;
  
  FUN_005eb080();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eb080 @ 0x005eb080 ====

void FUN_005eb080(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00984563;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5664;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005eaff0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005eac60();
  *in_ECX = &PTR_FUN_009c5514;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eb0f0 @ 0x005eb0f0 ====

void FUN_005eb0f0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005eb0f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_005eb100 @ 0x005eb100 ====

void FUN_005eb100(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005eb105. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_005eb110 @ 0x005eb110 ====

void FUN_005eb110(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005eb115. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_005eb120 @ 0x005eb120 ====

void FUN_005eb120(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005eb125. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_005eb130 @ 0x005eb130 ====

void FUN_005eb130(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009845c3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c570c;
  pvVar1 = operator_new(0x34);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005eb2c0();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b01c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5b01c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eb1c0 @ 0x005eb1c0 ====

void FUN_005eb1c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009845d5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c570c;
  DAT_00b5b01c = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c56bc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eb220 @ 0x005eb220 ====

void FUN_005eb220(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c56d4;
  return;
}


// ==== FUN_005eb230 @ 0x005eb230 ====

void FUN_005eb230(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c56d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eb260 @ 0x005eb260 ====

void FUN_005eb260(void)

{
  FUN_0060db60();
  return;
}


// ==== FUN_005eb270 @ 0x005eb270 ====

void FUN_005eb270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c56bc;
  return;
}


// ==== FUN_005eb280 @ 0x005eb280 ====

void FUN_005eb280(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c56bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eb2a0 @ 0x005eb2a0 ====

void FUN_005eb2a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c56ec;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,1,(_func_void_void_ptr *)&LAB_005eb250);
  return;
}


// ==== FUN_005eb2c0 @ 0x005eb2c0 ====

void FUN_005eb2c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984578;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c56f4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c56ec;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x1c,1,FUN_005eb260,(_func_void_void_ptr *)&LAB_005eb250);
  in_ECX[9] = 0;
  in_ECX[9] = in_ECX[9] + 1;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = in_ECX + 2;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eb340 @ 0x005eb340 ====

void FUN_005eb340(byte param_1)

{
  void *in_ECX;
  
  FUN_005eb2a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eb360 @ 0x005eb360 ====

void FUN_005eb360(byte param_1)

{
  void *in_ECX;
  
  FUN_005eb380();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eb380 @ 0x005eb380 ====

void FUN_005eb380(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009845a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c56f4;
  _Memory = (void *)in_ECX[0xb];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c56ec;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,1,(_func_void_void_ptr *)&LAB_005eb250);
    *in_ECX = &PTR_FUN_009c56d4;
    ExceptionList = local_c;
    return;
  }
  FUN_0060db00();
  _free(_Memory);
  return;
}


// ==== FUN_005eb410 @ 0x005eb410 ====

void * FUN_005eb410(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009845f9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x30);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x1c);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0060db60();
      }
      *(undefined4 *)((int)param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x2c);
      *(void **)(in_ECX + 0x2c) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)((int)param_2 + 0x10);
    }
    *(undefined4 *)((int)param_2 + 0x10) = 0;
    *(int *)((int)param_2 + 0x18) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x18) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5720,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x18) = *(int *)((int)param_2 + 0x18) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005eb510 @ 0x005eb510 ====

undefined4 FUN_005eb510(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5720,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x18);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x18);
    }
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x30);
    *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + -1;
    *(int *)(in_ECX + 0x30) = param_2;
  }
  return 0;
}


// ==== FUN_005eb590 @ 0x005eb590 ====

void FUN_005eb590(byte param_1)

{
  void *in_ECX;
  
  FUN_005eb1c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eb5b0 @ 0x005eb5b0 ====

void FUN_005eb5b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5798;
  return;
}


// ==== FUN_005eb5c0 @ 0x005eb5c0 ====

void FUN_005eb5c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5798;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eb5e0 @ 0x005eb5e0 ====

void FUN_005eb5e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c57a8;
  return;
}


// ==== FUN_005eb5f0 @ 0x005eb5f0 ====

void FUN_005eb5f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c57c4;
  return;
}


// ==== FUN_005eb600 @ 0x005eb600 ====

void FUN_005eb600(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c581c;
  return;
}


// ==== FUN_005eb610 @ 0x005eb610 ====

void FUN_005eb610(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c57a8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eb630 @ 0x005eb630 ====

void FUN_005eb630(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c57c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eb650 @ 0x005eb650 ====

void FUN_005eb650(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c581c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eb670 @ 0x005eb670 ====

undefined4 FUN_005eb670(undefined2 param_1)

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


// ==== FUN_005eb6a0 @ 0x005eb6a0 ====

void FUN_005eb6a0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984618;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c583c;
  DAT_00b5ab90 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c5798;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005eb740 @ 0x005eb740 ====

void FUN_005eb740(undefined2 *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined2 *puVar3;
  int in_ECX;
  void *unaff_EDI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098462d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x128);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0060dc30();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 8))(param_1);
  puVar3 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = *param_1;
  *(int **)(puVar3 + 2) = piVar2;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  ExceptionList = unaff_EDI;
  return;
}


// ==== FUN_005eb7d0 @ 0x005eb7d0 ====

void FUN_005eb7d0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00984655;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c583c;
  pvVar2 = operator_new(0x5018);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005eb8e0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x8028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005ebe80(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab90 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab90 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eb8a0 @ 0x005eb8a0 ====

void FUN_005eb8a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5834;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_005eb8c0 @ 0x005eb8c0 ====

void FUN_005eb8c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005eb8a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eb8e0 @ 0x005eb8e0 ====

void FUN_005eb8e0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984668;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c584c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c5834;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x400,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x1402] = 0;
  in_ECX[0x1402] = in_ECX[0x1402] + 0x400;
  in_ECX[0x1405] = in_ECX + 2;
  in_ECX[0x1403] = 0;
  in_ECX[0x1404] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x13ff] = 0;
  in_ECX[0x1400] = 0;
  in_ECX[0x1401] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eb990 @ 0x005eb990 ====

void FUN_005eb990(byte param_1)

{
  void *in_ECX;
  
  FUN_005eb9b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eb9b0 @ 0x005eb9b0 ====

void FUN_005eb9b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984693;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c584c;
  local_4 = 1;
  if ((void *)in_ECX[0x1404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c5834;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x400,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c57a8;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1404]);
  return;
}


// ==== FUN_005eba30 @ 0x005eba30 ====

void * FUN_005eba30(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009846ab;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x5014);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x500c) = *(int *)(in_ECX + 0x500c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x5010);
      *(void **)(in_ECX + 0x5010) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x5014) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c5860,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005ebb10 @ 0x005ebb10 ====

undefined4 FUN_005ebb10(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5860,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x5014);
    *(int *)(in_ECX + 0x500c) = *(int *)(in_ECX + 0x500c) + -1;
    *(int *)(in_ECX + 0x5014) = param_2;
  }
  return 0;
}


// ==== FUN_005ebb90 @ 0x005ebb90 ====

void FUN_005ebb90(byte param_1)

{
  void *in_ECX;
  
  FUN_005eb6a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ebbb0 @ 0x005ebbb0 ====

void FUN_005ebbb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c58dc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_005ebbd0 @ 0x005ebbd0 ====

void FUN_005ebbd0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009846d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c58e4;
  local_4 = 1;
  if ((void *)in_ECX[0x2004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c58dc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x400,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c581c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x2004]);
  return;
}


// ==== FUN_005ebc50 @ 0x005ebc50 ====

undefined4 FUN_005ebc50(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5860,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x8014);
    *(int *)(in_ECX + 0x800c) = *(int *)(in_ECX + 0x800c) + -1;
    *(int *)(in_ECX + 0x8014) = param_2;
  }
  return 0;
}


// ==== FUN_005ebcd0 @ 0x005ebcd0 ====

undefined4 * FUN_005ebcd0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5860,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x8014);
  *(int *)(in_ECX + 0x800c) = *(int *)(in_ECX + 0x800c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x8010);
    *(undefined4 **)(in_ECX + 0x8010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x8014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005ebd90 @ 0x005ebd90 ====

void FUN_005ebd90(byte param_1)

{
  void *in_ECX;
  
  FUN_005ebbb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ebdb0 @ 0x005ebdb0 ====

void FUN_005ebdb0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ebbd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ebdd0 @ 0x005ebdd0 ====

void FUN_005ebdd0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009846e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c58e4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c58dc;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x400,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x2002] = 0;
  in_ECX[0x2002] = in_ECX[0x2002] + 0x400;
  in_ECX[0x2005] = in_ECX + 2;
  in_ECX[0x2003] = 0;
  in_ECX[0x2004] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x1fff] = 0;
  in_ECX[0x2000] = 0;
  in_ECX[0x2001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ebe80 @ 0x005ebe80 ====

void FUN_005ebe80(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984708;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c58fc;
  FUN_005ebdd0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ebee0 @ 0x005ebee0 ====

void FUN_005ebee0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005ebf00(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005ebf00 @ 0x005ebf00 ====

void FUN_005ebf00(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005ebf00(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005ebf00(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005ebf40 @ 0x005ebf40 ====

void FUN_005ebf40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005ebf60(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005ebf60 @ 0x005ebf60 ====

void FUN_005ebf60(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005ebf60(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005ebf60(param_1[3]);
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


// ==== FUN_005ebfd0 @ 0x005ebfd0 ====

void FUN_005ebfd0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ebff0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ebff0 @ 0x005ebff0 ====

void FUN_005ebff0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00984733;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c58fc;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005ebf60(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005ebbd0();
  *in_ECX = &PTR_FUN_009c57c4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ec060 @ 0x005ec060 ====

void FUN_005ec060(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5954;
  return;
}


// ==== FUN_005ec070 @ 0x005ec070 ====

void FUN_005ec070(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5954;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ec090 @ 0x005ec090 ====

void FUN_005ec090(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5964;
  return;
}


// ==== FUN_005ec0a0 @ 0x005ec0a0 ====

void FUN_005ec0a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c597c;
  return;
}


// ==== FUN_005ec0b0 @ 0x005ec0b0 ====

void FUN_005ec0b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c59d4;
  return;
}


// ==== FUN_005ec0c0 @ 0x005ec0c0 ====

void FUN_005ec0c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5964;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ec0e0 @ 0x005ec0e0 ====

void FUN_005ec0e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c597c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ec100 @ 0x005ec100 ====

void FUN_005ec100(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c59d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ec120 @ 0x005ec120 ====

undefined4 FUN_005ec120(undefined1 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_8 [8];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_005ec150 @ 0x005ec150 ====

void FUN_005ec150(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984748;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c59f4;
  DAT_00b5ab8c = 0;
  local_4 = 0;
  for (piVar3 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar3 != (int *)0x0;
      piVar3 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar3)) {
    iVar1 = *piVar3;
    puVar2 = *(undefined4 **)(iVar1 + 4);
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
    *(undefined4 *)(iVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c5954;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005ec1f0 @ 0x005ec1f0 ====

uint FUN_005ec1f0(undefined1 *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined1 *puVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  void *unaff_EDI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098475d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0060dd70();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 8))(param_1);
  puVar3 = (undefined1 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1);
  *puVar3 = *param_1;
  *(int **)(puVar3 + 4) = piVar2;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(puVar3);
  if (iVar4 == 0) {
    ExceptionList = unaff_EDI;
    return 1;
  }
  (**(code **)*piVar2)(1);
  uVar5 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,puVar3);
  ExceptionList = (void *)0x0;
  return uVar5 & 0xffffff00;
}


// ==== FUN_005ec2b0 @ 0x005ec2b0 ====

void FUN_005ec2b0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00984785;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c59f4;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005ec3c0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x2028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005ec960(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab8c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab8c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ec380 @ 0x005ec380 ====

void FUN_005ec380(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c59ec;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_005ec3a0 @ 0x005ec3a0 ====

void FUN_005ec3a0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ec380();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ec3c0 @ 0x005ec3c0 ====

void FUN_005ec3c0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984798;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5a04;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c59ec;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x100,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x502] = 0;
  in_ECX[0x502] = in_ECX[0x502] + 0x100;
  in_ECX[0x505] = in_ECX + 2;
  in_ECX[0x503] = 0;
  in_ECX[0x504] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x4ff] = 0;
  in_ECX[0x500] = 0;
  in_ECX[0x501] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ec470 @ 0x005ec470 ====

void FUN_005ec470(byte param_1)

{
  void *in_ECX;
  
  FUN_005ec490();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ec490 @ 0x005ec490 ====

void FUN_005ec490(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009847c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5a04;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c59ec;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c5964;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_005ec510 @ 0x005ec510 ====

void * FUN_005ec510(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009847db;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x1414);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x140c) = *(int *)(in_ECX + 0x140c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x1410);
      *(void **)(in_ECX + 0x1410) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x1414) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c5a18,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005ec5f0 @ 0x005ec5f0 ====

undefined4 FUN_005ec5f0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5a18,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x1414);
    *(int *)(in_ECX + 0x140c) = *(int *)(in_ECX + 0x140c) + -1;
    *(int *)(in_ECX + 0x1414) = param_2;
  }
  return 0;
}


// ==== FUN_005ec670 @ 0x005ec670 ====

void FUN_005ec670(byte param_1)

{
  void *in_ECX;
  
  FUN_005ec150();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ec690 @ 0x005ec690 ====

void FUN_005ec690(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5a9c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_005ec6b0 @ 0x005ec6b0 ====

void FUN_005ec6b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984803;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5aa4;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c5a9c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c59d4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_005ec730 @ 0x005ec730 ====

undefined4 FUN_005ec730(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5a18,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x2014);
    *(int *)(in_ECX + 0x200c) = *(int *)(in_ECX + 0x200c) + -1;
    *(int *)(in_ECX + 0x2014) = param_2;
  }
  return 0;
}


// ==== FUN_005ec7b0 @ 0x005ec7b0 ====

undefined4 * FUN_005ec7b0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5a18,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x2014);
  *(int *)(in_ECX + 0x200c) = *(int *)(in_ECX + 0x200c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x2010);
    *(undefined4 **)(in_ECX + 0x2010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x2014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005ec870 @ 0x005ec870 ====

void FUN_005ec870(byte param_1)

{
  void *in_ECX;
  
  FUN_005ec690();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ec890 @ 0x005ec890 ====

void FUN_005ec890(byte param_1)

{
  void *in_ECX;
  
  FUN_005ec6b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ec8b0 @ 0x005ec8b0 ====

void FUN_005ec8b0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984818;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5aa4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c5a9c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x100,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x802] = 0;
  in_ECX[0x802] = in_ECX[0x802] + 0x100;
  in_ECX[0x805] = in_ECX + 2;
  in_ECX[0x803] = 0;
  in_ECX[0x804] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x7ff] = 0;
  in_ECX[0x800] = 0;
  in_ECX[0x801] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ec960 @ 0x005ec960 ====

void FUN_005ec960(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984838;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5abc;
  FUN_005ec8b0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ec9c0 @ 0x005ec9c0 ====

void FUN_005ec9c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005ec9e0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005ec9e0 @ 0x005ec9e0 ====

void FUN_005ec9e0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005ec9e0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005ec9e0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005eca20 @ 0x005eca20 ====

undefined4 * FUN_005eca20(void)

{
  undefined4 *puVar1;
  int in_ECX;
  byte *unaff_EBP;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(in_ECX + 0x10) + 0xc))(1,0);
  *puVar1 = unaff_EBP;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  if (*(undefined4 **)(in_ECX + 4) == (undefined4 *)0x0) {
    *(undefined4 **)(in_ECX + 4) = puVar1;
    return (undefined4 *)0x0;
  }
  puVar2 = *(undefined4 **)(in_ECX + 4);
  while( true ) {
    while (*unaff_EBP < *(byte *)*puVar2) {
      if ((undefined4 *)puVar2[2] == (undefined4 *)0x0) {
        puVar1[4] = puVar2;
        puVar2[2] = puVar1;
        FUN_0061f0e0(puVar1,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
      puVar2 = (undefined4 *)puVar2[2];
    }
    if (*unaff_EBP <= *(byte *)*puVar2) break;
    if ((undefined4 *)puVar2[3] == (undefined4 *)0x0) {
      puVar1[4] = puVar2;
      puVar2[3] = puVar1;
      FUN_0061f0e0(puVar1,*(undefined4 *)(in_ECX + 4));
      return (undefined4 *)0x0;
    }
    puVar2 = (undefined4 *)puVar2[3];
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,puVar1);
  return puVar2;
}


// ==== FUN_005ecad0 @ 0x005ecad0 ====

void FUN_005ecad0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005ecaf0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005ecaf0 @ 0x005ecaf0 ====

void FUN_005ecaf0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005ecaf0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005ecaf0(param_1[3]);
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


// ==== FUN_005ecb60 @ 0x005ecb60 ====

undefined4 * FUN_005ecb60(byte *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar4 = puVar1;
  do {
    puVar3 = puVar4;
    if (*param_1 < *(byte *)*puVar3) {
      iVar2 = -1;
    }
    else {
      if (*param_1 <= *(byte *)*puVar3) {
        FUN_0061f0e0(puVar3,puVar1);
        return puVar3;
      }
      iVar2 = 1;
    }
    if (iVar2 < 0) {
      puVar4 = (undefined4 *)puVar3[2];
    }
    else {
      puVar4 = (undefined4 *)puVar3[3];
    }
  } while (puVar4 != (undefined4 *)0x0);
  FUN_0061f0e0(puVar3,puVar1);
  return (undefined4 *)0x0;
}


// ==== FUN_005ecbd0 @ 0x005ecbd0 ====

void FUN_005ecbd0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ecbf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ecbf0 @ 0x005ecbf0 ====

void FUN_005ecbf0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00984863;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5abc;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005ecaf0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005ec6b0();
  *in_ECX = &PTR_FUN_009c597c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ecc60 @ 0x005ecc60 ====

void FUN_005ecc60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5b14;
  return;
}


// ==== FUN_005ecc70 @ 0x005ecc70 ====

void FUN_005ecc70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5b14;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ecc90 @ 0x005ecc90 ====

void FUN_005ecc90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5b2c;
  return;
}


// ==== FUN_005ecca0 @ 0x005ecca0 ====

void FUN_005ecca0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5b84;
  return;
}


// ==== FUN_005eccb0 @ 0x005eccb0 ====

void FUN_005eccb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5b9c;
  return;
}


// ==== FUN_005eccc0 @ 0x005eccc0 ====

void FUN_005eccc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5b2c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ecce0 @ 0x005ecce0 ====

void FUN_005ecce0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5b84;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ecd00 @ 0x005ecd00 ====

void FUN_005ecd00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5b9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ecd20 @ 0x005ecd20 ====

undefined4 FUN_005ecd20(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_005ecd50 @ 0x005ecd50 ====

undefined4 FUN_005ecd50(void)

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


// ==== FUN_005ecd70 @ 0x005ecd70 ====

undefined4 FUN_005ecd70(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 4);
    }
  }
  return 0;
}


// ==== FUN_005ecda0 @ 0x005ecda0 ====

void FUN_005ecda0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984878;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c5bbc;
  DAT_00b5abac = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c5b14;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005ece40 @ 0x005ece40 ====

void FUN_005ece40(byte *param_1)

{
  void *pvVar1;
  int *piVar2;
  uint *puVar3;
  int in_ECX;
  void *unaff_EDI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098488d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0xcc);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0060dde0();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 8))(param_1);
  puVar3 = (uint *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = (uint)*param_1;
  puVar3[1] = (uint)piVar2;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  ExceptionList = unaff_EDI;
  return;
}


// ==== FUN_005eced0 @ 0x005eced0 ====

void FUN_005eced0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009848b5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5bbc;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005ecfe0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x1028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005ed580(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abac = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abac = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ecfa0 @ 0x005ecfa0 ====

void FUN_005ecfa0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5bb4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005ecfc0 @ 0x005ecfc0 ====

void FUN_005ecfc0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ecfa0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ecfe0 @ 0x005ecfe0 ====

void FUN_005ecfe0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009848c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5bd4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c5bb4;
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


// ==== FUN_005ed090 @ 0x005ed090 ====

void FUN_005ed090(byte param_1)

{
  void *in_ECX;
  
  FUN_005ed0b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ed0b0 @ 0x005ed0b0 ====

void FUN_005ed0b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009848f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5bd4;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c5bb4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c5b84;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_005ed130 @ 0x005ed130 ====

void * FUN_005ed130(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098490b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c5be8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005ed210 @ 0x005ed210 ====

undefined4 FUN_005ed210(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5be8,0xa9);
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


// ==== FUN_005ed290 @ 0x005ed290 ====

void FUN_005ed290(byte param_1)

{
  void *in_ECX;
  
  FUN_005ecda0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ed2b0 @ 0x005ed2b0 ====

void FUN_005ed2b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5c64;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005ed2d0 @ 0x005ed2d0 ====

void FUN_005ed2d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984933;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5c6c;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c5c64;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c5b9c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_005ed350 @ 0x005ed350 ====

undefined4 FUN_005ed350(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5be8,0xa9);
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


// ==== FUN_005ed3d0 @ 0x005ed3d0 ====

undefined4 * FUN_005ed3d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5be8,0x85);
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


// ==== FUN_005ed490 @ 0x005ed490 ====

void FUN_005ed490(byte param_1)

{
  void *in_ECX;
  
  FUN_005ed2b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ed4b0 @ 0x005ed4b0 ====

void FUN_005ed4b0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ed2d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ed4d0 @ 0x005ed4d0 ====

void FUN_005ed4d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984948;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5c6c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c5c64;
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


// ==== FUN_005ed580 @ 0x005ed580 ====

void FUN_005ed580(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984968;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5c84;
  FUN_005ed4d0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ed5e0 @ 0x005ed5e0 ====

void FUN_005ed5e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005ed600(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005ed600 @ 0x005ed600 ====

void FUN_005ed600(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005ed600(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005ed600(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005ed640 @ 0x005ed640 ====

void FUN_005ed640(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005ed660(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005ed660 @ 0x005ed660 ====

void FUN_005ed660(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005ed660(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005ed660(param_1[3]);
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


// ==== FUN_005ed6d0 @ 0x005ed6d0 ====

void FUN_005ed6d0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ed6f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ed6f0 @ 0x005ed6f0 ====

void FUN_005ed6f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00984993;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5c84;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005ed660(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005ed2d0();
  *in_ECX = &PTR_FUN_009c5b2c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ed760 @ 0x005ed760 ====

void FUN_005ed760(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005ed765. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_005ed770 @ 0x005ed770 ====

void FUN_005ed770(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005ed775. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_005ed780 @ 0x005ed780 ====

void FUN_005ed780(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005ed785. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_005ed790 @ 0x005ed790 ====

void FUN_005ed790(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005ed795. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_005ed7a0 @ 0x005ed7a0 ====

void FUN_005ed7a0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009849f3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5d2c;
  pvVar1 = operator_new(0x18f0);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005ed930();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5abe8 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abe8 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ed830 @ 0x005ed830 ====

void FUN_005ed830(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984a05;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5d2c;
  DAT_00b5abe8 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c5cdc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ed890 @ 0x005ed890 ====

void FUN_005ed890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5cf4;
  return;
}


// ==== FUN_005ed8a0 @ 0x005ed8a0 ====

void FUN_005ed8a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5cf4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ed8d0 @ 0x005ed8d0 ====

void FUN_005ed8d0(void)

{
  FUN_0060e0a0();
  return;
}


// ==== FUN_005ed8e0 @ 0x005ed8e0 ====

void FUN_005ed8e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5cdc;
  return;
}


// ==== FUN_005ed8f0 @ 0x005ed8f0 ====

void FUN_005ed8f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5cdc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ed910 @ 0x005ed910 ====

void FUN_005ed910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5d0c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x27c,10,(_func_void_void_ptr *)&LAB_005ed8c0);
  return;
}


// ==== FUN_005ed930 @ 0x005ed930 ====

void FUN_005ed930(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009849a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5d14;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c5d0c;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x27c,10,FUN_005ed8d0,(_func_void_void_ptr *)&LAB_005ed8c0);
  in_ECX[0x638] = 0;
  in_ECX[0x638] = in_ECX[0x638] + 10;
  in_ECX[0x639] = 0;
  in_ECX[0x63a] = 0;
  in_ECX[0x63b] = in_ECX + 2;
  in_ECX[0x9f] = 0;
  in_ECX[0xa0] = 0;
  in_ECX[0x9e] = in_ECX + 0xa1;
  in_ECX[0x13d] = in_ECX + 0x140;
  in_ECX[0x13e] = 0;
  in_ECX[0x13f] = 0;
  in_ECX[0x1dc] = in_ECX + 0x1df;
  in_ECX[0x1dd] = 0;
  in_ECX[0x1de] = 0;
  in_ECX[0x27b] = in_ECX + 0x27e;
  in_ECX[0x27c] = 0;
  in_ECX[0x27d] = 0;
  in_ECX[0x31a] = in_ECX + 0x31d;
  in_ECX[0x31b] = 0;
  in_ECX[0x31c] = 0;
  in_ECX[0x3b9] = in_ECX + 0x3bc;
  in_ECX[0x3ba] = 0;
  in_ECX[0x3bb] = 0;
  in_ECX[0x458] = in_ECX + 0x45b;
  in_ECX[0x459] = 0;
  in_ECX[0x45a] = 0;
  in_ECX[0x4f7] = in_ECX + 0x4fa;
  in_ECX[0x4f8] = 0;
  in_ECX[0x4f9] = 0;
  in_ECX[0x596] = in_ECX + 0x599;
  in_ECX[0x597] = 0;
  in_ECX[0x598] = 0;
  in_ECX[0x635] = 0;
  in_ECX[0x636] = 0;
  in_ECX[0x637] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005edaa0 @ 0x005edaa0 ====

undefined4 FUN_005edaa0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18e4);
}


// ==== FUN_005edab0 @ 0x005edab0 ====

void FUN_005edab0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ed910();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005edad0 @ 0x005edad0 ====

void FUN_005edad0(byte param_1)

{
  void *in_ECX;
  
  FUN_005edaf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005edaf0 @ 0x005edaf0 ====

void FUN_005edaf0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009849d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5d14;
  _Memory = (void *)in_ECX[0x63a];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c5d0c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x27c,10,(_func_void_void_ptr *)&LAB_005ed8c0);
    *in_ECX = &PTR_FUN_009c5cf4;
    ExceptionList = local_c;
    return;
  }
  FUN_0060e050();
  _free(_Memory);
  return;
}


// ==== FUN_005edb90 @ 0x005edb90 ====

void * FUN_005edb90(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00984a29;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x18ec);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x18e4) = *(int *)(in_ECX + 0x18e4) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x27c);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0060e0a0();
      }
      *(undefined4 *)((int)param_2 + 0x274) = *(undefined4 *)(in_ECX + 0x18e8);
      *(void **)(in_ECX + 0x18e8) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x18ec) = *(undefined4 *)((int)param_2 + 0x270);
    }
    *(undefined4 *)((int)param_2 + 0x270) = 0;
    *(int *)((int)param_2 + 0x278) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x278) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5d40,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x278) = *(int *)((int)param_2 + 0x278) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005edcb0 @ 0x005edcb0 ====

undefined4 FUN_005edcb0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x278) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5d40,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x278);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x278);
    }
    *(undefined4 *)(param_2 + 0x270) = *(undefined4 *)(in_ECX + 0x18ec);
    *(int *)(in_ECX + 0x18e4) = *(int *)(in_ECX + 0x18e4) + -1;
    *(int *)(in_ECX + 0x18ec) = param_2;
  }
  return 0;
}


// ==== FUN_005edd40 @ 0x005edd40 ====

void FUN_005edd40(byte param_1)

{
  void *in_ECX;
  
  FUN_005ed830();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005edd60 @ 0x005edd60 ====

void FUN_005edd60(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005edd65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_005edd70 @ 0x005edd70 ====

void FUN_005edd70(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005edd75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_005edd80 @ 0x005edd80 ====

void FUN_005edd80(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005edd85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_005edd90 @ 0x005edd90 ====

void FUN_005edd90(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005edd95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_005edda0 @ 0x005edda0 ====

void FUN_005edda0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984a93;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5dfc;
  pvVar1 = operator_new(0x1a18);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005edf30();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5abe4 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abe4 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ede30 @ 0x005ede30 ====

void FUN_005ede30(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984aa5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5dfc;
  DAT_00b5abe4 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c5dac;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ede90 @ 0x005ede90 ====

void FUN_005ede90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5dc4;
  return;
}


// ==== FUN_005edea0 @ 0x005edea0 ====

void FUN_005edea0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5dc4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eded0 @ 0x005eded0 ====

void FUN_005eded0(void)

{
  FUN_0060e280();
  return;
}


// ==== FUN_005edee0 @ 0x005edee0 ====

void FUN_005edee0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5dac;
  return;
}


// ==== FUN_005edef0 @ 0x005edef0 ====

void FUN_005edef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5dac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005edf10 @ 0x005edf10 ====

void FUN_005edf10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5ddc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x34,0x80,(_func_void_void_ptr *)&LAB_005edec0);
  return;
}


// ==== FUN_005edf30 @ 0x005edf30 ====

void FUN_005edf30(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984a48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5de4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c5ddc;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x34,0x80,FUN_005eded0,(_func_void_void_ptr *)&LAB_005edec0);
  in_ECX[0x682] = 0;
  in_ECX[0x682] = in_ECX[0x682] + 0x80;
  in_ECX[0x685] = in_ECX + 2;
  in_ECX[0x683] = 0;
  in_ECX[0x684] = 0;
  iVar2 = 0x7f;
  puVar1 = in_ECX;
  do {
    puVar1[0xc] = puVar1 + 0xf;
    puVar1[0xd] = 0;
    puVar1[0xe] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0xd;
  } while (iVar2 != 0);
  in_ECX[0x67f] = 0;
  in_ECX[0x680] = 0;
  in_ECX[0x681] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005edfe0 @ 0x005edfe0 ====

undefined4 FUN_005edfe0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1a0c);
}


// ==== FUN_005edff0 @ 0x005edff0 ====

void FUN_005edff0(byte param_1)

{
  void *in_ECX;
  
  FUN_005edf10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ee010 @ 0x005ee010 ====

void FUN_005ee010(byte param_1)

{
  void *in_ECX;
  
  FUN_005ee030();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ee030 @ 0x005ee030 ====

void FUN_005ee030(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984a73;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5de4;
  _Memory = (void *)in_ECX[0x684];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c5ddc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x34,0x80,(_func_void_void_ptr *)&LAB_005edec0);
    *in_ECX = &PTR_FUN_009c5dc4;
    ExceptionList = local_c;
    return;
  }
  FUN_0060e270();
  _free(_Memory);
  return;
}


// ==== FUN_005ee0d0 @ 0x005ee0d0 ====

void * FUN_005ee0d0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00984ac9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x1a14);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x1a0c) = *(int *)(in_ECX + 0x1a0c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x34);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0060e280();
      }
      *(undefined4 *)((int)param_2 + 0x2c) = *(undefined4 *)(in_ECX + 0x1a10);
      *(void **)(in_ECX + 0x1a10) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x1a14) = *(undefined4 *)((int)param_2 + 0x28);
    }
    *(undefined4 *)((int)param_2 + 0x28) = 0;
    *(int *)((int)param_2 + 0x30) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x30) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5e10,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x30) = *(int *)((int)param_2 + 0x30) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005ee1e0 @ 0x005ee1e0 ====

undefined4 FUN_005ee1e0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x30) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5e10,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x30);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x30);
    }
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(in_ECX + 0x1a14);
    *(int *)(in_ECX + 0x1a0c) = *(int *)(in_ECX + 0x1a0c) + -1;
    *(int *)(in_ECX + 0x1a14) = param_2;
  }
  return 0;
}


// ==== FUN_005ee260 @ 0x005ee260 ====

void FUN_005ee260(byte param_1)

{
  void *in_ECX;
  
  FUN_005ede30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ee280 @ 0x005ee280 ====

void FUN_005ee280(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5ec4;
  return;
}


// ==== FUN_005ee290 @ 0x005ee290 ====

void FUN_005ee290(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5ec4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ee2b0 @ 0x005ee2b0 ====

void FUN_005ee2b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5ed4;
  return;
}


// ==== FUN_005ee2c0 @ 0x005ee2c0 ====

void FUN_005ee2c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5eec;
  return;
}


// ==== FUN_005ee2d0 @ 0x005ee2d0 ====

void FUN_005ee2d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5f44;
  return;
}


// ==== FUN_005ee2e0 @ 0x005ee2e0 ====

void FUN_005ee2e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5ed4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ee300 @ 0x005ee300 ====

void FUN_005ee300(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5eec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ee320 @ 0x005ee320 ====

void FUN_005ee320(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5f44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ee340 @ 0x005ee340 ====

undefined4 FUN_005ee340(undefined4 *param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = *param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_005ee370 @ 0x005ee370 ====

void FUN_005ee370(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984ae8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c5f64;
  DAT_00b5ab94 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar1)) {
    (**(code **)(*DAT_00b5ab98 + 0x10))(1,*(undefined4 *)(*piVar1 + 4));
  }
  (**(code **)(*(int *)in_ECX[2] + 0x20))();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c5ec4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005ee420 @ 0x005ee420 ====

void FUN_005ee420(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 unaff_retaddr;
  uint uStack_10c;
  undefined4 *puStack_4;
  
  uStack_10c = 0;
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1);
  *puVar1 = *puStack_4;
  puVar1[1] = unaff_retaddr;
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(puVar1);
  if (iVar2 != 0) {
    uStack_10c = uStack_10c & 0xffffff00;
    uVar3 = FUN_0044a580(&uStack_10c,s__ERROR__Duplicate_Index_in_Quest_009c5e80,
                         *(undefined2 *)puStack_4,*(undefined2 *)((int)puStack_4 + 2));
    FUN_00797b80(uVar3);
  }
  return;
}


// ==== FUN_005ee490 @ 0x005ee490 ====

void FUN_005ee490(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00984b10;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5f64;
  pvVar2 = operator_new(0x14018);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005ee5a0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x20028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005eeb30(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab94 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab94 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ee560 @ 0x005ee560 ====

void FUN_005ee560(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5f5c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x1000,FUN_006ef6d0);
  return;
}


// ==== FUN_005ee580 @ 0x005ee580 ====

void FUN_005ee580(byte param_1)

{
  void *in_ECX;
  
  FUN_005ee560();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ee5a0 @ 0x005ee5a0 ====

void FUN_005ee5a0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984b28;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5f74;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c5f5c;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x14,0x1000,(_func_void_void_ptr *)&LAB_005e17f0,FUN_006ef6d0);
  in_ECX[0x5002] = 0;
  in_ECX[0x5002] = in_ECX[0x5002] + 0x1000;
  in_ECX[0x5005] = in_ECX + 2;
  in_ECX[0x5003] = 0;
  in_ECX[0x5004] = 0;
  iVar2 = 0xfff;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x4fff] = 0;
  in_ECX[0x5000] = 0;
  in_ECX[0x5001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ee650 @ 0x005ee650 ====

void FUN_005ee650(byte param_1)

{
  void *in_ECX;
  
  FUN_005ee670();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ee670 @ 0x005ee670 ====

void FUN_005ee670(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984b53;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c5f74;
  local_4 = 1;
  if ((void *)in_ECX[0x5004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c5f5c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x1000,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c5ed4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x5004]);
  return;
}


// ==== FUN_005ee6f0 @ 0x005ee6f0 ====

undefined2 * FUN_005ee6f0(int param_1,undefined2 *param_2)

{
  undefined4 uVar1;
  undefined2 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined2 *)0x0) {
    if (*(int *)(param_2 + 8) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5f88,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + param_1;
    return param_2;
  }
  puVar2 = *(undefined2 **)(in_ECX + 0x14014);
  *(int *)(in_ECX + 0x1400c) = *(int *)(in_ECX + 0x1400c) + 1;
  if (puVar2 == (undefined2 *)0x0) {
    puVar2 = operator_new(0x14);
    if (puVar2 == (undefined2 *)0x0) {
      puVar2 = (undefined2 *)0x0;
    }
    else {
      *puVar2 = 0;
      puVar2[1] = 0;
    }
    *(undefined4 *)(puVar2 + 6) = *(undefined4 *)(in_ECX + 0x14010);
    *(undefined2 **)(in_ECX + 0x14010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x14014) = *(undefined4 *)(puVar2 + 4);
  }
  *(undefined4 *)(puVar2 + 4) = 0;
  *(int *)(puVar2 + 8) = param_1;
  return puVar2;
}


// ==== FUN_005ee7c0 @ 0x005ee7c0 ====

undefined4 FUN_005ee7c0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5f88,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x14014);
    *(int *)(in_ECX + 0x1400c) = *(int *)(in_ECX + 0x1400c) + -1;
    *(int *)(in_ECX + 0x14014) = param_2;
  }
  return 0;
}


// ==== FUN_005ee840 @ 0x005ee840 ====

void FUN_005ee840(byte param_1)

{
  void *in_ECX;
  
  FUN_005ee370();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ee860 @ 0x005ee860 ====

void FUN_005ee860(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c5ffc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x1000,FUN_006ef6d0);
  return;
}


// ==== FUN_005ee880 @ 0x005ee880 ====

void FUN_005ee880(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984b73;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6004;
  local_4 = 1;
  if ((void *)in_ECX[0x8004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c5ffc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x1000,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c5f44;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x8004]);
  return;
}


// ==== FUN_005ee900 @ 0x005ee900 ====

undefined4 FUN_005ee900(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5f88,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x20014);
    *(int *)(in_ECX + 0x2000c) = *(int *)(in_ECX + 0x2000c) + -1;
    *(int *)(in_ECX + 0x20014) = param_2;
  }
  return 0;
}


// ==== FUN_005ee980 @ 0x005ee980 ====

undefined4 * FUN_005ee980(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5f88,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x20014);
  *(int *)(in_ECX + 0x2000c) = *(int *)(in_ECX + 0x2000c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x20010);
    *(undefined4 **)(in_ECX + 0x20010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x20014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005eea40 @ 0x005eea40 ====

void FUN_005eea40(byte param_1)

{
  void *in_ECX;
  
  FUN_005ee860();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eea60 @ 0x005eea60 ====

void FUN_005eea60(byte param_1)

{
  void *in_ECX;
  
  FUN_005ee880();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eea80 @ 0x005eea80 ====

void FUN_005eea80(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984b88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6004;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c5ffc;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x1000,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x8002] = 0;
  in_ECX[0x8002] = in_ECX[0x8002] + 0x1000;
  in_ECX[0x8005] = in_ECX + 2;
  in_ECX[0x8003] = 0;
  in_ECX[0x8004] = 0;
  iVar2 = 0xfff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x7fff] = 0;
  in_ECX[0x8000] = 0;
  in_ECX[0x8001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eeb30 @ 0x005eeb30 ====

void FUN_005eeb30(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984ba8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c601c;
  FUN_005eea80();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eeb90 @ 0x005eeb90 ====

void FUN_005eeb90(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005eebb0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005eebb0 @ 0x005eebb0 ====

void FUN_005eebb0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005eebb0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005eebb0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005eebf0 @ 0x005eebf0 ====

uint FUN_005eebf0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = FUN_0054f9a0(param_2);
  if (cVar1 == '\0') {
    cVar1 = FUN_0054f9a0(param_1);
    return (uint)(cVar1 != '\0');
  }
  return 0xffffffff;
}


// ==== FUN_005eec30 @ 0x005eec30 ====

void FUN_005eec30(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005eec50(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005eec50 @ 0x005eec50 ====

void FUN_005eec50(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005eec50(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005eec50(param_1[3]);
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


// ==== FUN_005eecc0 @ 0x005eecc0 ====

undefined4 * FUN_005eecc0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(undefined4 **)(in_ECX + 4) == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  do {
    puVar3 = puVar4;
    cVar1 = FUN_0054f9a0(*puVar3);
    if (cVar1 == '\0') {
      cVar1 = FUN_0054f9a0(param_1);
      if (cVar1 == '\0') {
        FUN_0061f0e0(puVar3,*(undefined4 *)(in_ECX + 4));
        return puVar3;
      }
      iVar2 = 1;
    }
    else {
      iVar2 = -1;
    }
    if (iVar2 < 0) {
      puVar4 = (undefined4 *)puVar3[2];
    }
    else {
      puVar4 = (undefined4 *)puVar3[3];
    }
  } while (puVar4 != (undefined4 *)0x0);
  FUN_0061f0e0(puVar3,*(undefined4 *)(in_ECX + 4));
  return (undefined4 *)0x0;
}


// ==== FUN_005eed40 @ 0x005eed40 ====

void FUN_005eed40(byte param_1)

{
  void *in_ECX;
  
  FUN_005eed60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eed60 @ 0x005eed60 ====

void FUN_005eed60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00984bd3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c601c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005eec50(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005ee880();
  *in_ECX = &PTR_FUN_009c5eec;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eedd0 @ 0x005eedd0 ====

void FUN_005eedd0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005eedd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_005eede0 @ 0x005eede0 ====

void FUN_005eede0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005eede5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_005eedf0 @ 0x005eedf0 ====

void FUN_005eedf0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005eedf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_005eee00 @ 0x005eee00 ====

void FUN_005eee00(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005eee05. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_005eee10 @ 0x005eee10 ====

void FUN_005eee10(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984c33;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c60c4;
  pvVar1 = operator_new(0x28018);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005eefa0();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ab98 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab98 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eeea0 @ 0x005eeea0 ====

void FUN_005eeea0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984c45;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c60c4;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  DAT_00b5ab98 = 0;
  *in_ECX = &PTR_FUN_009c6074;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005eef00 @ 0x005eef00 ====

void FUN_005eef00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c608c;
  return;
}


// ==== FUN_005eef10 @ 0x005eef10 ====

void FUN_005eef10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c608c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eef40 @ 0x005eef40 ====

void FUN_005eef40(void)

{
  FUN_0060e3e0();
  return;
}


// ==== FUN_005eef50 @ 0x005eef50 ====

void FUN_005eef50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6074;
  return;
}


// ==== FUN_005eef60 @ 0x005eef60 ====

void FUN_005eef60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6074;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eef80 @ 0x005eef80 ====

void FUN_005eef80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c60a4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x28,0x1000,(_func_void_void_ptr *)&LAB_005eef30);
  return;
}


// ==== FUN_005eefa0 @ 0x005eefa0 ====

void FUN_005eefa0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984be8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c60ac;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c60a4;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x28,0x1000,FUN_005eef40,(_func_void_void_ptr *)&LAB_005eef30);
  in_ECX[0xa002] = 0;
  in_ECX[0xa002] = in_ECX[0xa002] + 0x1000;
  in_ECX[0xa005] = in_ECX + 2;
  in_ECX[0xa003] = 0;
  in_ECX[0xa004] = 0;
  iVar2 = 0xfff;
  puVar1 = in_ECX;
  do {
    puVar1[9] = puVar1 + 0xc;
    puVar1[10] = 0;
    puVar1[0xb] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 10;
  } while (iVar2 != 0);
  in_ECX[0x9fff] = 0;
  in_ECX[0xa000] = 0;
  in_ECX[0xa001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ef050 @ 0x005ef050 ====

undefined4 FUN_005ef050(void)

{
  return 0x1000;
}


// ==== FUN_005ef060 @ 0x005ef060 ====

void FUN_005ef060(byte param_1)

{
  void *in_ECX;
  
  FUN_005eef80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ef080 @ 0x005ef080 ====

void FUN_005ef080(byte param_1)

{
  void *in_ECX;
  
  FUN_005ef0a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ef0a0 @ 0x005ef0a0 ====

void FUN_005ef0a0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984c13;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c60ac;
  _Memory = (void *)in_ECX[0xa004];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c60a4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x28,0x1000,(_func_void_void_ptr *)&LAB_005eef30);
    *in_ECX = &PTR_FUN_009c608c;
    ExceptionList = local_c;
    return;
  }
  FUN_0060e370();
  _free(_Memory);
  return;
}


// ==== FUN_005ef140 @ 0x005ef140 ====

void * FUN_005ef140(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00984c69;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x28014);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x2800c) = *(int *)(in_ECX + 0x2800c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x28);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0060e3e0();
      }
      *(undefined4 *)((int)param_2 + 0x20) = *(undefined4 *)(in_ECX + 0x28010);
      *(void **)(in_ECX + 0x28010) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x28014) = *(undefined4 *)((int)param_2 + 0x1c);
    }
    *(undefined4 *)((int)param_2 + 0x1c) = 0;
    *(int *)((int)param_2 + 0x24) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x24) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5f88,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x24) = *(int *)((int)param_2 + 0x24) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005ef250 @ 0x005ef250 ====

undefined4 FUN_005ef250(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x24) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c5f88,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x24);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x24);
    }
    *(undefined4 *)(param_2 + 0x1c) = *(undefined4 *)(in_ECX + 0x28014);
    *(int *)(in_ECX + 0x2800c) = *(int *)(in_ECX + 0x2800c) + -1;
    *(int *)(in_ECX + 0x28014) = param_2;
  }
  return 0;
}


// ==== FUN_005ef2d0 @ 0x005ef2d0 ====

void FUN_005ef2d0(byte param_1)

{
  void *in_ECX;
  
  FUN_005eeea0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ef2f0 @ 0x005ef2f0 ====

void FUN_005ef2f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c610c;
  return;
}


// ==== FUN_005ef300 @ 0x005ef300 ====

void FUN_005ef300(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c610c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ef320 @ 0x005ef320 ====

void FUN_005ef320(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6124;
  return;
}


// ==== FUN_005ef330 @ 0x005ef330 ====

void FUN_005ef330(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c617c;
  return;
}


// ==== FUN_005ef340 @ 0x005ef340 ====

void FUN_005ef340(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6194;
  return;
}


// ==== FUN_005ef350 @ 0x005ef350 ====

void FUN_005ef350(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6124;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ef370 @ 0x005ef370 ====

void FUN_005ef370(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c617c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ef390 @ 0x005ef390 ====

void FUN_005ef390(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6194;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ef3b0 @ 0x005ef3b0 ====

undefined4 FUN_005ef3b0(undefined2 param_1)

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


// ==== FUN_005ef3e0 @ 0x005ef3e0 ====

undefined4 FUN_005ef3e0(void)

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


// ==== FUN_005ef400 @ 0x005ef400 ====

undefined4 FUN_005ef400(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 4);
    }
  }
  return 0;
}


// ==== FUN_005ef430 @ 0x005ef430 ====

void FUN_005ef430(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984c88;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c61b4;
  DAT_00b5ab9c = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar1)) {
    (**(code **)(*DAT_00b5aba0 + 0x10))(1,*(undefined4 *)(*piVar1 + 4));
  }
  (**(code **)(*(int *)in_ECX[2] + 0x20))();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c610c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005ef4e0 @ 0x005ef4e0 ====

void FUN_005ef4e0(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 auStack_fe [250];
  int *piStack_4;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  puVar2 = (undefined2 *)(**(code **)(*piStack_4 + 8))();
  *puVar1 = *puVar2;
  *(int **)(puVar1 + 2) = piStack_4;
  iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(puVar1);
  if (iVar3 != 0) {
    uVar4 = FUN_0044a580(auStack_fe + -0xe,&DAT_009c60dc,*puVar1);
    FUN_00797b80(uVar4);
  }
  return;
}


// ==== FUN_005ef550 @ 0x005ef550 ====

void FUN_005ef550(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00984cb0;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c61b4;
  pvVar2 = operator_new(0x5018);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005ef660();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x8028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005efbd0(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab9c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab9c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ef620 @ 0x005ef620 ====

void FUN_005ef620(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c61ac;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_005ef640 @ 0x005ef640 ====

void FUN_005ef640(byte param_1)

{
  void *in_ECX;
  
  FUN_005ef620();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ef660 @ 0x005ef660 ====

void FUN_005ef660(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984cc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c61cc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c61ac;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x400,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x1402] = 0;
  in_ECX[0x1402] = in_ECX[0x1402] + 0x400;
  in_ECX[0x1405] = in_ECX + 2;
  in_ECX[0x1403] = 0;
  in_ECX[0x1404] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x13ff] = 0;
  in_ECX[0x1400] = 0;
  in_ECX[0x1401] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ef710 @ 0x005ef710 ====

void FUN_005ef710(byte param_1)

{
  void *in_ECX;
  
  FUN_005ef730();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ef730 @ 0x005ef730 ====

void FUN_005ef730(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984cf3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c61cc;
  local_4 = 1;
  if ((void *)in_ECX[0x1404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c61ac;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x400,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c617c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1404]);
  return;
}


// ==== FUN_005ef7b0 @ 0x005ef7b0 ====

void * FUN_005ef7b0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c61e0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x5014);
  *(int *)(in_ECX + 0x500c) = *(int *)(in_ECX + 0x500c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0x5010);
    *(void **)(in_ECX + 0x5010) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x5014) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_005ef860 @ 0x005ef860 ====

undefined4 FUN_005ef860(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c61e0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x5014);
    *(int *)(in_ECX + 0x500c) = *(int *)(in_ECX + 0x500c) + -1;
    *(int *)(in_ECX + 0x5014) = param_2;
  }
  return 0;
}


// ==== FUN_005ef8e0 @ 0x005ef8e0 ====

void FUN_005ef8e0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ef430();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ef900 @ 0x005ef900 ====

void FUN_005ef900(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c625c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_005ef920 @ 0x005ef920 ====

void FUN_005ef920(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984d13;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6264;
  local_4 = 1;
  if ((void *)in_ECX[0x2004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c625c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x400,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c6194;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x2004]);
  return;
}


// ==== FUN_005ef9a0 @ 0x005ef9a0 ====

undefined4 FUN_005ef9a0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c61e0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x8014);
    *(int *)(in_ECX + 0x800c) = *(int *)(in_ECX + 0x800c) + -1;
    *(int *)(in_ECX + 0x8014) = param_2;
  }
  return 0;
}


// ==== FUN_005efa20 @ 0x005efa20 ====

undefined4 * FUN_005efa20(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c61e0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x8014);
  *(int *)(in_ECX + 0x800c) = *(int *)(in_ECX + 0x800c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x8010);
    *(undefined4 **)(in_ECX + 0x8010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x8014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005efae0 @ 0x005efae0 ====

void FUN_005efae0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ef900();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005efb00 @ 0x005efb00 ====

void FUN_005efb00(byte param_1)

{
  void *in_ECX;
  
  FUN_005ef920();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005efb20 @ 0x005efb20 ====

void FUN_005efb20(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984d28;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6264;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c625c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x400,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x2002] = 0;
  in_ECX[0x2002] = in_ECX[0x2002] + 0x400;
  in_ECX[0x2005] = in_ECX + 2;
  in_ECX[0x2003] = 0;
  in_ECX[0x2004] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x1fff] = 0;
  in_ECX[0x2000] = 0;
  in_ECX[0x2001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005efbd0 @ 0x005efbd0 ====

void FUN_005efbd0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984d48;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c627c;
  FUN_005efb20();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005efc30 @ 0x005efc30 ====

void FUN_005efc30(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005efc50(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005efc50 @ 0x005efc50 ====

void FUN_005efc50(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005efc50(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005efc50(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005efc90 @ 0x005efc90 ====

void FUN_005efc90(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005efcb0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005efcb0 @ 0x005efcb0 ====

void FUN_005efcb0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005efcb0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005efcb0(param_1[3]);
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


// ==== FUN_005efd20 @ 0x005efd20 ====

void FUN_005efd20(byte param_1)

{
  void *in_ECX;
  
  FUN_005efd40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005efd40 @ 0x005efd40 ====

void FUN_005efd40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00984d73;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c627c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005efcb0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005ef920();
  *in_ECX = &PTR_FUN_009c6124;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005efdb0 @ 0x005efdb0 ====

void FUN_005efdb0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005efdb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_005efdc0 @ 0x005efdc0 ====

void FUN_005efdc0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005efdc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_005efdd0 @ 0x005efdd0 ====

void FUN_005efdd0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005efdd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_005efde0 @ 0x005efde0 ====

void FUN_005efde0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005efde5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_005efdf0 @ 0x005efdf0 ====

void FUN_005efdf0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984dd3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6324;
  pvVar1 = operator_new(0x7018);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005eff80();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aba0 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aba0 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005efe80 @ 0x005efe80 ====

void FUN_005efe80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984de5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6324;
  DAT_00b5aba0 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c62d4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005efee0 @ 0x005efee0 ====

void FUN_005efee0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c62ec;
  return;
}


// ==== FUN_005efef0 @ 0x005efef0 ====

void FUN_005efef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c62ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eff20 @ 0x005eff20 ====

void FUN_005eff20(void)

{
  FUN_0060e480();
  return;
}


// ==== FUN_005eff30 @ 0x005eff30 ====

void FUN_005eff30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c62d4;
  return;
}


// ==== FUN_005eff40 @ 0x005eff40 ====

void FUN_005eff40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c62d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005eff60 @ 0x005eff60 ====

void FUN_005eff60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6304;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,0x400,(_func_void_void_ptr *)&LAB_005eff10);
  return;
}


// ==== FUN_005eff80 @ 0x005eff80 ====

void FUN_005eff80(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984d88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c630c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c6304;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x1c,0x400,FUN_005eff20,(_func_void_void_ptr *)&LAB_005eff10);
  in_ECX[0x1c02] = 0;
  in_ECX[0x1c02] = in_ECX[0x1c02] + 0x400;
  in_ECX[0x1c05] = in_ECX + 2;
  in_ECX[0x1c03] = 0;
  in_ECX[0x1c04] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[6] = puVar1 + 9;
    puVar1[7] = 0;
    puVar1[8] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 7;
  } while (iVar2 != 0);
  in_ECX[0x1bff] = 0;
  in_ECX[0x1c00] = 0;
  in_ECX[0x1c01] = 0;
  ExceptionList = local_c;
  return;
}


