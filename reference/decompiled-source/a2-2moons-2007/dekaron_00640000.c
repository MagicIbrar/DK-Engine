// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x640000-0x64ffff

// ==== FUN_00640000 @ 0x00640000 ====

void FUN_00640000(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098b160;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3284;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_006401d0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x1028);
  local_4._0_1_ = 2;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00640760(*puVar1);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  pvVar2 = operator_new(0x1028);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00640ab0();
  }
  in_ECX[4] = uVar3;
  in_ECX[5] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aa30 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa30 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00640100 @ 0x00640100 ====

void FUN_00640100(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d327c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00640120 @ 0x00640120 ====

void FUN_00640120(byte param_1)

{
  void *in_ECX;
  
  FUN_00640100();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640140 @ 0x00640140 ====

void FUN_00640140(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined1 auStack_fe [254];
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x30))(param_1);
  if (iVar1 != 0) {
    uVar2 = FUN_0044a580(auStack_fe + -6,s_File___s__Line___d_0099f0a0,
                         s___Article_Skill_Flyweight_Contai_009d32a8,0xc0);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  puVar3 = operator_new(0x100);
  if (puVar3 == (undefined4 *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x10) + 0x28))(0);
    return;
  }
  puVar4 = puVar3;
  for (iVar1 = 0x40; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *param_1;
    param_1 = param_1 + 1;
    puVar4 = puVar4 + 1;
  }
  (**(code **)(**(int **)(in_ECX + 0x10) + 0x28))(puVar3);
  return;
}


// ==== FUN_006401d0 @ 0x006401d0 ====

void FUN_006401d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b178;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d32d4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d327c;
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


// ==== FUN_00640280 @ 0x00640280 ====

void FUN_00640280(byte param_1)

{
  void *in_ECX;
  
  FUN_006402a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006402a0 @ 0x006402a0 ====

void FUN_006402a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b1a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d32d4;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d327c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d31dc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_00640320 @ 0x00640320 ====

void * FUN_00640320(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d32e8,0x85);
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


// ==== FUN_006403d0 @ 0x006403d0 ====

undefined4 FUN_006403d0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d32e8,0xa9);
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


// ==== FUN_00640450 @ 0x00640450 ====

void FUN_00640450(byte param_1)

{
  void *in_ECX;
  
  FUN_0063fd20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640470 @ 0x00640470 ====

void FUN_00640470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3364;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00640490 @ 0x00640490 ====

void FUN_00640490(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b1c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d336c;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d3364;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d31f4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_00640510 @ 0x00640510 ====

undefined4 FUN_00640510(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d32e8,0xa9);
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


// ==== FUN_00640590 @ 0x00640590 ====

void FUN_00640590(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3384;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_006405b0 @ 0x006405b0 ====

void FUN_006405b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b1e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d338c;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d3384;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d3264;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_00640630 @ 0x00640630 ====

void FUN_00640630(byte param_1)

{
  void *in_ECX;
  
  FUN_00640470();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640650 @ 0x00640650 ====

void FUN_00640650(byte param_1)

{
  void *in_ECX;
  
  FUN_00640490();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640670 @ 0x00640670 ====

void FUN_00640670(byte param_1)

{
  void *in_ECX;
  
  FUN_00640590();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640690 @ 0x00640690 ====

void FUN_00640690(byte param_1)

{
  void *in_ECX;
  
  FUN_006405b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006406b0 @ 0x006406b0 ====

void FUN_006406b0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b1f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d336c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d3364;
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


// ==== FUN_00640760 @ 0x00640760 ====

void FUN_00640760(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b218;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d33a4;
  FUN_006406b0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006407c0 @ 0x006407c0 ====

void FUN_006407c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006407e0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006407e0 @ 0x006407e0 ====

void FUN_006407e0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_006407e0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_006407e0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00640820 @ 0x00640820 ====

void FUN_00640820(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00640840(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00640840 @ 0x00640840 ====

void FUN_00640840(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00640840(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00640840(param_1[3]);
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


// ==== FUN_006408b0 @ 0x006408b0 ====

undefined4 * FUN_006408b0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d32e8,0x85);
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


// ==== FUN_00640970 @ 0x00640970 ====

void FUN_00640970(byte param_1)

{
  void *in_ECX;
  
  FUN_00640990();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640990 @ 0x00640990 ====

void FUN_00640990(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098b243;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d33a4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00640840(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00640490();
  *in_ECX = &PTR_FUN_009d3184;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00640a00 @ 0x00640a00 ====

void FUN_00640a00(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b258;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d338c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d3384;
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


// ==== FUN_00640ab0 @ 0x00640ab0 ====

void FUN_00640ab0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b278;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d33fc;
  FUN_00640a00();
  in_ECX[2] = 0;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00640b10 @ 0x00640b10 ====

void FUN_00640b10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00640b30(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00640b30 @ 0x00640b30 ====

void FUN_00640b30(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00640b30(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00640b30(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00640b70 @ 0x00640b70 ====

undefined4 * FUN_00640b70(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  int unaff_EBP;
  undefined4 *puVar4;
  
  piVar2 = (int *)(**(code **)(*(int *)(in_ECX + 0x10) + 0xc))(1,0);
  *piVar2 = in_ECX;
  piVar2[2] = 0;
  piVar2[3] = 0;
  piVar2[4] = 0;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(undefined4 **)(in_ECX + 4) == (undefined4 *)0x0) {
    *(int **)(in_ECX + 4) = piVar2;
    return (undefined4 *)0x0;
  }
  do {
    cVar1 = FUN_00473020(*puVar4);
    if (cVar1 == '\0') {
      cVar1 = FUN_00473020(in_ECX);
      if (cVar1 == '\0') {
        (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,piVar2);
        return puVar4;
      }
      puVar3 = (undefined4 *)puVar4[3];
      if (puVar3 == (undefined4 *)0x0) {
        piVar2[4] = (int)puVar4;
        puVar4[3] = piVar2;
LAB_00640bee:
        FUN_0061f0e0(piVar2,*(undefined4 *)(unaff_EBP + 4));
        return (undefined4 *)0x0;
      }
    }
    else {
      puVar3 = (undefined4 *)puVar4[2];
      if (puVar3 == (undefined4 *)0x0) {
        piVar2[4] = (int)puVar4;
        puVar4[2] = piVar2;
        goto LAB_00640bee;
      }
    }
    puVar4 = puVar3;
  } while( true );
}


// ==== FUN_00640c20 @ 0x00640c20 ====

void FUN_00640c20(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00640c40(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00640c40 @ 0x00640c40 ====

void FUN_00640c40(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00640c40(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00640c40(param_1[3]);
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


// ==== FUN_00640cb0 @ 0x00640cb0 ====

void FUN_00640cb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00640cd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640cd0 @ 0x00640cd0 ====

void FUN_00640cd0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098b2a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d33fc;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00640c40(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_006405b0();
  *in_ECX = &PTR_FUN_009d320c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00640d40 @ 0x00640d40 ====

void FUN_00640d40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3454;
  return;
}


// ==== FUN_00640d50 @ 0x00640d50 ====

void FUN_00640d50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3454;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640d70 @ 0x00640d70 ====

undefined4 FUN_00640d70(int *param_1)

{
  int in_ECX;
  
  (**(code **)(*param_1 + 0xc))();
  (**(code **)(**(int **)(in_ECX + 4) + 8))(param_1);
  return 1;
}


// ==== FUN_00640d90 @ 0x00640d90 ====

void FUN_00640d90(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098b2ce;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3464;
  pvVar1 = operator_new(8);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00657a50();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(4);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00657890();
  }
  in_ECX[2] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5abd8 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abd8 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00640e50 @ 0x00640e50 ====

uint FUN_00640e50(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  cVar1 = (**(code **)(**(int **)(in_ECX + 8) + 4))(uVar2,param_1);
  return -(uint)(cVar1 != '\0') & uVar2;
}


// ==== FUN_00640e80 @ 0x00640e80 ====

void FUN_00640e80(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b2e0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d3464;
  DAT_00b5abd8 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d3454;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00640ef0 @ 0x00640ef0 ====

void FUN_00640ef0(byte param_1)

{
  void *in_ECX;
  
  FUN_00640e80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640f10 @ 0x00640f10 ====

void FUN_00640f10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3474;
  return;
}


// ==== FUN_00640f20 @ 0x00640f20 ====

void FUN_00640f20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3474;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640f40 @ 0x00640f40 ====

void FUN_00640f40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3484;
  return;
}


// ==== FUN_00640f50 @ 0x00640f50 ====

void FUN_00640f50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d349c;
  return;
}


// ==== FUN_00640f60 @ 0x00640f60 ====

void FUN_00640f60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d34f4;
  return;
}


// ==== FUN_00640f70 @ 0x00640f70 ====

void FUN_00640f70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3484;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640f90 @ 0x00640f90 ====

void FUN_00640f90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d349c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640fb0 @ 0x00640fb0 ====

void FUN_00640fb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d34f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00640fd0 @ 0x00640fd0 ====

undefined4 FUN_00640fd0(undefined2 param_1)

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


// ==== FUN_00641000 @ 0x00641000 ====

void FUN_00641000(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b2f8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d3514;
  DAT_00b5ab68 = 0;
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
  *in_ECX = &PTR_FUN_009d3474;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006410a0 @ 0x006410a0 ====

void FUN_006410a0(undefined4 param_1,void *param_2)

{
  void *pvVar1;
  int *piVar2;
  undefined2 *puVar3;
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098b30d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(8);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00657e80();
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


// ==== FUN_00641130 @ 0x00641130 ====

void FUN_00641130(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098b335;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3514;
  pvVar2 = operator_new(0x5018);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00641240();
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
    uVar3 = FUN_006417f0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab68 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab68 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00641200 @ 0x00641200 ====

void FUN_00641200(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d350c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_00641220 @ 0x00641220 ====

void FUN_00641220(byte param_1)

{
  void *in_ECX;
  
  FUN_00641200();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00641240 @ 0x00641240 ====

void FUN_00641240(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b348;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3524;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d350c;
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


// ==== FUN_006412f0 @ 0x006412f0 ====

undefined4 FUN_006412f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x500c);
}


// ==== FUN_00641300 @ 0x00641300 ====

void FUN_00641300(byte param_1)

{
  void *in_ECX;
  
  FUN_00641320();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00641320 @ 0x00641320 ====

void FUN_00641320(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b373;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3524;
  local_4 = 1;
  if ((void *)in_ECX[0x1404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d350c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x400,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d3484;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1404]);
  return;
}


// ==== FUN_006413a0 @ 0x006413a0 ====

void * FUN_006413a0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098b38b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009d3538,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00641480 @ 0x00641480 ====

undefined4 FUN_00641480(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3538,0xa9);
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


// ==== FUN_00641500 @ 0x00641500 ====

void FUN_00641500(byte param_1)

{
  void *in_ECX;
  
  FUN_00641000();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00641520 @ 0x00641520 ====

void FUN_00641520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d35b8;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_00641540 @ 0x00641540 ====

void FUN_00641540(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b3b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d35c0;
  local_4 = 1;
  if ((void *)in_ECX[0x2004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d35b8;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x400,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d34f4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x2004]);
  return;
}


// ==== FUN_006415c0 @ 0x006415c0 ====

undefined4 FUN_006415c0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3538,0xa9);
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


// ==== FUN_00641640 @ 0x00641640 ====

undefined4 * FUN_00641640(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3538,0x85);
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


// ==== FUN_00641700 @ 0x00641700 ====

void FUN_00641700(byte param_1)

{
  void *in_ECX;
  
  FUN_00641520();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00641720 @ 0x00641720 ====

void FUN_00641720(byte param_1)

{
  void *in_ECX;
  
  FUN_00641540();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00641740 @ 0x00641740 ====

void FUN_00641740(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b3c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d35c0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d35b8;
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


// ==== FUN_006417f0 @ 0x006417f0 ====

void FUN_006417f0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b3e8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d35dc;
  FUN_00641740();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00641850 @ 0x00641850 ====

void FUN_00641850(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00641870(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00641870 @ 0x00641870 ====

void FUN_00641870(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00641870(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00641870(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_006418b0 @ 0x006418b0 ====

undefined4 * FUN_006418b0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  ushort *unaff_EBX;
  undefined4 *puVar2;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(in_ECX + 0x10) + 0xc))(1,0);
  *puVar1 = unaff_EBX;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[4] = 0;
  if (*(undefined4 **)(in_ECX + 4) == (undefined4 *)0x0) {
    *(undefined4 **)(in_ECX + 4) = puVar1;
    return (undefined4 *)0x0;
  }
  puVar2 = *(undefined4 **)(in_ECX + 4);
  while( true ) {
    while (*unaff_EBX < *(ushort *)*puVar2) {
      if ((undefined4 *)puVar2[2] == (undefined4 *)0x0) {
        puVar1[4] = puVar2;
        puVar2[2] = puVar1;
        FUN_0061f0e0(puVar1,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
      puVar2 = (undefined4 *)puVar2[2];
    }
    if (*unaff_EBX <= *(ushort *)*puVar2) break;
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


// ==== FUN_00641960 @ 0x00641960 ====

void FUN_00641960(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00641980(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00641980 @ 0x00641980 ====

void FUN_00641980(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00641980(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00641980(param_1[3]);
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


// ==== FUN_006419f0 @ 0x006419f0 ====

void FUN_006419f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00641a10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00641a10 @ 0x00641a10 ====

void FUN_00641a10(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098b413;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d35dc;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00641980(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00641540();
  *in_ECX = &PTR_FUN_009d349c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00641a80 @ 0x00641a80 ====

void FUN_00641a80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3634;
  return;
}


// ==== FUN_00641a90 @ 0x00641a90 ====

void FUN_00641a90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3634;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00641ab0 @ 0x00641ab0 ====

void FUN_00641ab0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3644;
  return;
}


// ==== FUN_00641ac0 @ 0x00641ac0 ====

void FUN_00641ac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d365c;
  return;
}


// ==== FUN_00641ad0 @ 0x00641ad0 ====

void FUN_00641ad0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d36b4;
  return;
}


// ==== FUN_00641ae0 @ 0x00641ae0 ====

void FUN_00641ae0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3644;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00641b00 @ 0x00641b00 ====

void FUN_00641b00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d365c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00641b20 @ 0x00641b20 ====

void FUN_00641b20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d36b4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00641b40 @ 0x00641b40 ====

undefined4 FUN_00641b40(undefined2 param_1)

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


// ==== FUN_00641b70 @ 0x00641b70 ====

void FUN_00641b70(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b428;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d36d4;
  DAT_00b5ab6c = 0;
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
  *in_ECX = &PTR_FUN_009d3634;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00641c10 @ 0x00641c10 ====

void FUN_00641c10(undefined4 param_1,void *param_2)

{
  void *pvVar1;
  int *piVar2;
  undefined2 *puVar3;
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098b43d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x224);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00658120();
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


// ==== FUN_00641ca0 @ 0x00641ca0 ====

void FUN_00641ca0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098b465;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d36d4;
  pvVar2 = operator_new(0x5018);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00641db0();
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
    uVar3 = FUN_00642350(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab6c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab6c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00641d70 @ 0x00641d70 ====

void FUN_00641d70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d36cc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_00641d90 @ 0x00641d90 ====

void FUN_00641d90(byte param_1)

{
  void *in_ECX;
  
  FUN_00641d70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00641db0 @ 0x00641db0 ====

void FUN_00641db0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b478;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d36e4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d36cc;
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


// ==== FUN_00641e60 @ 0x00641e60 ====

void FUN_00641e60(byte param_1)

{
  void *in_ECX;
  
  FUN_00641e80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00641e80 @ 0x00641e80 ====

void FUN_00641e80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b4a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d36e4;
  local_4 = 1;
  if ((void *)in_ECX[0x1404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d36cc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x400,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d3644;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1404]);
  return;
}


// ==== FUN_00641f00 @ 0x00641f00 ====

void * FUN_00641f00(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098b4bb;
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
                           s_d__usa_24_0_1_2__develop_share_l_009d36f8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00641fe0 @ 0x00641fe0 ====

undefined4 FUN_00641fe0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d36f8,0xa9);
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


// ==== FUN_00642060 @ 0x00642060 ====

void FUN_00642060(byte param_1)

{
  void *in_ECX;
  
  FUN_00641b70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00642080 @ 0x00642080 ====

void FUN_00642080(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d377c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_006420a0 @ 0x006420a0 ====

void FUN_006420a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b4e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3784;
  local_4 = 1;
  if ((void *)in_ECX[0x2004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d377c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x400,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d36b4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x2004]);
  return;
}


// ==== FUN_00642120 @ 0x00642120 ====

undefined4 FUN_00642120(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d36f8,0xa9);
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


// ==== FUN_006421a0 @ 0x006421a0 ====

undefined4 * FUN_006421a0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d36f8,0x85);
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


// ==== FUN_00642260 @ 0x00642260 ====

void FUN_00642260(byte param_1)

{
  void *in_ECX;
  
  FUN_00642080();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00642280 @ 0x00642280 ====

void FUN_00642280(byte param_1)

{
  void *in_ECX;
  
  FUN_006420a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006422a0 @ 0x006422a0 ====

void FUN_006422a0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b4f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3784;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d377c;
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


// ==== FUN_00642350 @ 0x00642350 ====

void FUN_00642350(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b518;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d379c;
  FUN_006422a0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006423b0 @ 0x006423b0 ====

void FUN_006423b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006423d0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006423d0 @ 0x006423d0 ====

void FUN_006423d0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_006423d0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_006423d0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00642410 @ 0x00642410 ====

void FUN_00642410(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00642430(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00642430 @ 0x00642430 ====

void FUN_00642430(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00642430(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00642430(param_1[3]);
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


// ==== FUN_006424a0 @ 0x006424a0 ====

void FUN_006424a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006424c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006424c0 @ 0x006424c0 ====

void FUN_006424c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098b543;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d379c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00642430(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_006420a0();
  *in_ECX = &PTR_FUN_009d365c;
  ExceptionList = local_c;
  return;
}


// ==== __break @ 0x0064252e ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00642530 @ 0x00642530 ====

void FUN_00642530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d383c;
  return;
}


// ==== __break @ 0x0064253a ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00642540 @ 0x00642540 ====

void FUN_00642540(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d383c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== __break @ 0x0064255f ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00642560 @ 0x00642560 ====

void FUN_00642560(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d384c;
  return;
}


// ==== FUN_00642570 @ 0x00642570 ====

void FUN_00642570(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3864;
  return;
}


// ==== __break @ 0x00642579 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== __break @ 0x0064257a ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00642580 @ 0x00642580 ====

void FUN_00642580(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d38bc;
  return;
}


// ==== FUN_00642590 @ 0x00642590 ====

void FUN_00642590(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d384c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006425b0 @ 0x006425b0 ====

void FUN_006425b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3864;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006425d0 @ 0x006425d0 ====

void FUN_006425d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d38bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006425f0 @ 0x006425f0 ====

undefined4 FUN_006425f0(undefined2 param_1)

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


// ==== FUN_00642620 @ 0x00642620 ====

void FUN_00642620(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b558;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d38dc;
  DAT_00b5ab88 = 0;
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
  *in_ECX = &PTR_FUN_009d383c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006426c0 @ 0x006426c0 ====

void FUN_006426c0(void)

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
  puStack_8 = &LAB_0098b570;
  pvStack_c = ExceptionList;
  piVar6 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar3 = operator_new(0x150);
  pvStack_c = (void *)0x0;
  if (pvVar3 != (void *)0x0) {
    piVar6 = (int *)FUN_00658270();
  }
  puVar1 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar6 + 8))(puStack_4);
  *puVar2 = *puVar1;
  *(int **)(puVar2 + 2) = piVar6;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009d3824,
                         s___Article_Item_Shop_Set_flyweigh_009d37f4,0x38);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_00642790 @ 0x00642790 ====

void FUN_00642790(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098b598;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d38dc;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_006428a0();
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
    uVar3 = FUN_00642e10(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab88 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab88 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00642860 @ 0x00642860 ====

void FUN_00642860(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d38d4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00642880 @ 0x00642880 ====

void FUN_00642880(byte param_1)

{
  void *in_ECX;
  
  FUN_00642860();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006428a0 @ 0x006428a0 ====

void FUN_006428a0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b5b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d38ec;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d38d4;
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


// ==== FUN_00642950 @ 0x00642950 ====

void FUN_00642950(byte param_1)

{
  void *in_ECX;
  
  FUN_00642970();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00642970 @ 0x00642970 ====

void FUN_00642970(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b5e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d38ec;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d38d4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d384c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_006429f0 @ 0x006429f0 ====

void * FUN_006429f0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3900,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x1414);
  *(int *)(in_ECX + 0x140c) = *(int *)(in_ECX + 0x140c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0x1410);
    *(void **)(in_ECX + 0x1410) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1414) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_00642aa0 @ 0x00642aa0 ====

undefined4 FUN_00642aa0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3900,0xa9);
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


// ==== FUN_00642b20 @ 0x00642b20 ====

void FUN_00642b20(byte param_1)

{
  void *in_ECX;
  
  FUN_00642620();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00642b40 @ 0x00642b40 ====

void FUN_00642b40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3988;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00642b60 @ 0x00642b60 ====

void FUN_00642b60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b603;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3990;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d3988;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d38bc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_00642be0 @ 0x00642be0 ====

undefined4 FUN_00642be0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3900,0xa9);
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


// ==== FUN_00642c60 @ 0x00642c60 ====

undefined4 * FUN_00642c60(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3900,0x85);
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


// ==== FUN_00642d20 @ 0x00642d20 ====

void FUN_00642d20(byte param_1)

{
  void *in_ECX;
  
  FUN_00642b40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00642d40 @ 0x00642d40 ====

void FUN_00642d40(byte param_1)

{
  void *in_ECX;
  
  FUN_00642b60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00642d60 @ 0x00642d60 ====

void FUN_00642d60(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b618;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3990;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d3988;
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


// ==== FUN_00642e10 @ 0x00642e10 ====

void FUN_00642e10(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b638;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d39ac;
  FUN_00642d60();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00642e70 @ 0x00642e70 ====

void FUN_00642e70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00642e90(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00642e90 @ 0x00642e90 ====

void FUN_00642e90(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00642e90(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00642e90(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00642ed0 @ 0x00642ed0 ====

void FUN_00642ed0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00642ef0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00642ef0 @ 0x00642ef0 ====

void FUN_00642ef0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00642ef0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00642ef0(param_1[3]);
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


// ==== FUN_00642f60 @ 0x00642f60 ====

void FUN_00642f60(byte param_1)

{
  void *in_ECX;
  
  FUN_00642f80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00642f80 @ 0x00642f80 ====

void FUN_00642f80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098b663;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d39ac;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00642ef0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00642b60();
  *in_ECX = &PTR_FUN_009d3864;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00642ff0 @ 0x00642ff0 ====

void FUN_00642ff0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3a04;
  return;
}


// ==== FUN_00643000 @ 0x00643000 ====

void FUN_00643000(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3a04;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00643020 @ 0x00643020 ====

undefined4 FUN_00643020(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098b67b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x90);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_00658460(pvVar1);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_00643080 @ 0x00643080 ====

undefined4 FUN_00643080(undefined2 param_1)

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


// ==== FUN_006430b0 @ 0x006430b0 ====

void FUN_006430b0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b68d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d3aac;
  DAT_00b5abb4 = 0;
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
  *in_ECX = &PTR_FUN_009d3a04;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00643150 @ 0x00643150 ====

void FUN_00643150(void)

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


// ==== FUN_00643180 @ 0x00643180 ====

void FUN_00643180(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098b6b5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3aac;
  pvVar2 = operator_new(0x2c);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00643310();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x48);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00643780(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abb4 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abb4 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00643240 @ 0x00643240 ====

void FUN_00643240(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3a18;
  return;
}


// ==== FUN_00643250 @ 0x00643250 ====

void FUN_00643250(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3a34;
  return;
}


// ==== FUN_00643260 @ 0x00643260 ====

void FUN_00643260(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3a8c;
  return;
}


// ==== FUN_00643270 @ 0x00643270 ====

void FUN_00643270(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3a18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00643290 @ 0x00643290 ====

void FUN_00643290(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3a34;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006432b0 @ 0x006432b0 ====

void FUN_006432b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3a8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006432d0 @ 0x006432d0 ====

void FUN_006432d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3aa4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,1,FUN_006ef6d0);
  return;
}


// ==== FUN_006432f0 @ 0x006432f0 ====

void FUN_006432f0(byte param_1)

{
  void *in_ECX;
  
  FUN_006432d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00643310 @ 0x00643310 ====

void FUN_00643310(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b6c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3ac0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d3aa4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,1,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[7] = 0;
  in_ECX[7] = in_ECX[7] + 1;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = in_ECX + 2;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00643390 @ 0x00643390 ====

void FUN_00643390(byte param_1)

{
  void *in_ECX;
  
  FUN_006433b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006433b0 @ 0x006433b0 ====

void FUN_006433b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b6f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3ac0;
  local_4 = 1;
  if ((void *)in_ECX[9] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d3aa4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,1,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d3a18;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[9]);
  return;
}


// ==== FUN_00643430 @ 0x00643430 ====

void * FUN_00643430(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098b70b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x28);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x24);
      *(void **)(in_ECX + 0x24) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009d3ad8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00643500 @ 0x00643500 ====

undefined4 FUN_00643500(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ad8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x28);
    *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + -1;
    *(int *)(in_ECX + 0x28) = param_2;
  }
  return 0;
}


// ==== FUN_00643580 @ 0x00643580 ====

void FUN_00643580(byte param_1)

{
  void *in_ECX;
  
  FUN_006430b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006435a0 @ 0x006435a0 ====

void FUN_006435a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3b5c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,1,FUN_006ef6d0);
  return;
}


// ==== FUN_006435c0 @ 0x006435c0 ====

void FUN_006435c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b733;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3b64;
  local_4 = 1;
  if ((void *)in_ECX[0xc] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d3b5c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,1,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d3a8c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xc]);
  return;
}


// ==== FUN_00643640 @ 0x00643640 ====

undefined4 FUN_00643640(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ad8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x34);
    *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + -1;
    *(int *)(in_ECX + 0x34) = param_2;
  }
  return 0;
}


// ==== FUN_006436c0 @ 0x006436c0 ====

void FUN_006436c0(byte param_1)

{
  void *in_ECX;
  
  FUN_006435a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006436e0 @ 0x006436e0 ====

void FUN_006436e0(byte param_1)

{
  void *in_ECX;
  
  FUN_006435c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00643700 @ 0x00643700 ====

void FUN_00643700(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b748;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3b64;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d3b5c;
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


// ==== FUN_00643780 @ 0x00643780 ====

void FUN_00643780(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b768;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3b7c;
  FUN_00643700();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006437e0 @ 0x006437e0 ====

void FUN_006437e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00643800(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00643800 @ 0x00643800 ====

void FUN_00643800(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00643800(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00643800(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00643840 @ 0x00643840 ====

void FUN_00643840(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00643860(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00643860 @ 0x00643860 ====

void FUN_00643860(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00643860(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00643860(param_1[3]);
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


// ==== FUN_006438d0 @ 0x006438d0 ====

int FUN_006438d0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0xc);
  if (iVar3 == 0) {
    iVar2 = *(int *)(param_1 + 0x10);
    iVar1 = param_1;
    while ((iVar3 = iVar2, iVar3 != 0 && (*(int *)(iVar3 + 0xc) == iVar1))) {
      iVar1 = iVar3;
      iVar2 = *(int *)(iVar3 + 0x10);
    }
  }
  else {
    for (iVar1 = *(int *)(iVar3 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
      iVar3 = iVar1;
    }
  }
  FUN_005fee40(param_1);
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return iVar3;
}


// ==== FUN_00643930 @ 0x00643930 ====

void FUN_00643930(byte param_1)

{
  void *in_ECX;
  
  FUN_00643950();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00643950 @ 0x00643950 ====

void FUN_00643950(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098b793;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3b7c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00643860(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_006435c0();
  *in_ECX = &PTR_FUN_009d3a34;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006439c0 @ 0x006439c0 ====

void FUN_006439c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3c18;
  return;
}


// ==== FUN_006439d0 @ 0x006439d0 ====

void FUN_006439d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3c18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006439f0 @ 0x006439f0 ====

void FUN_006439f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3c28;
  return;
}


// ==== FUN_00643a00 @ 0x00643a00 ====

void FUN_00643a00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3c44;
  return;
}


// ==== FUN_00643a10 @ 0x00643a10 ====

void FUN_00643a10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3c9c;
  return;
}


// ==== FUN_00643a20 @ 0x00643a20 ====

void FUN_00643a20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3c28;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00643a40 @ 0x00643a40 ====

void FUN_00643a40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3c44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00643a60 @ 0x00643a60 ====

void FUN_00643a60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3c9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00643a80 @ 0x00643a80 ====

undefined4 FUN_00643a80(undefined2 param_1)

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


// ==== FUN_00643ab0 @ 0x00643ab0 ====

void FUN_00643ab0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b7a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d3cbc;
  DAT_00b5aa2c = 0;
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
  *in_ECX = &PTR_FUN_009d3c18;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00643b50 @ 0x00643b50 ====

void FUN_00643b50(void)

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
  puStack_8 = &LAB_0098b7c0;
  pvStack_c = ExceptionList;
  piVar6 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar3 = operator_new(500);
  pvStack_c = (void *)0x0;
  if (pvVar3 != (void *)0x0) {
    piVar6 = (int *)FUN_00658d70();
  }
  puVar1 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar6 + 8))(puStack_4);
  *puVar2 = *puVar1;
  *(int **)(puVar2 + 2) = piVar6;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009d3c00,
                         s___Article_Item_Shop_flyweight_Co_009d3bd4,0x38);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_00643c20 @ 0x00643c20 ====

void FUN_00643c20(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098b7e8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3cbc;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00643d30();
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
    uVar3 = FUN_006442a0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aa2c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa2c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00643cf0 @ 0x00643cf0 ====

void FUN_00643cf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3cb4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00643d10 @ 0x00643d10 ====

void FUN_00643d10(byte param_1)

{
  void *in_ECX;
  
  FUN_00643cf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00643d30 @ 0x00643d30 ====

void FUN_00643d30(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b808;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3ccc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d3cb4;
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


// ==== FUN_00643de0 @ 0x00643de0 ====

void FUN_00643de0(byte param_1)

{
  void *in_ECX;
  
  FUN_00643e00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00643e00 @ 0x00643e00 ====

void FUN_00643e00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b833;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3ccc;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d3cb4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d3c28;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_00643e80 @ 0x00643e80 ====

void * FUN_00643e80(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ce0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x1414);
  *(int *)(in_ECX + 0x140c) = *(int *)(in_ECX + 0x140c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0x1410);
    *(void **)(in_ECX + 0x1410) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1414) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_00643f30 @ 0x00643f30 ====

undefined4 FUN_00643f30(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ce0,0xa9);
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


// ==== FUN_00643fb0 @ 0x00643fb0 ====

void FUN_00643fb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00643ab0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00643fd0 @ 0x00643fd0 ====

void FUN_00643fd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3d60;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00643ff0 @ 0x00643ff0 ====

void FUN_00643ff0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b853;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3d68;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d3d60;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d3c9c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_00644070 @ 0x00644070 ====

undefined4 FUN_00644070(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ce0,0xa9);
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


// ==== FUN_006440f0 @ 0x006440f0 ====

undefined4 * FUN_006440f0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ce0,0x85);
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


// ==== FUN_006441b0 @ 0x006441b0 ====

void FUN_006441b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00643fd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006441d0 @ 0x006441d0 ====

void FUN_006441d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00643ff0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006441f0 @ 0x006441f0 ====

void FUN_006441f0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b868;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3d68;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d3d60;
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


// ==== FUN_006442a0 @ 0x006442a0 ====

void FUN_006442a0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b888;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3d84;
  FUN_006441f0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00644300 @ 0x00644300 ====

void FUN_00644300(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00644320(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00644320 @ 0x00644320 ====

void FUN_00644320(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00644320(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00644320(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00644360 @ 0x00644360 ====

void FUN_00644360(undefined4 *param_1)

{
  int *in_ECX;
  
  FUN_00625950(*param_1);
  (**(code **)(*in_ECX + 0x3c))(param_1);
  return;
}


// ==== FUN_00644380 @ 0x00644380 ====

void FUN_00644380(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006443a0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006443a0 @ 0x006443a0 ====

void FUN_006443a0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_006443a0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_006443a0(param_1[3]);
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


// ==== FUN_00644410 @ 0x00644410 ====

void FUN_00644410(byte param_1)

{
  void *in_ECX;
  
  FUN_00644430();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00644430 @ 0x00644430 ====

void FUN_00644430(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098b8b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3d84;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_006443a0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00643ff0();
  *in_ECX = &PTR_FUN_009d3c44;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006444a0 @ 0x006444a0 ====

void FUN_006444a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3e1c;
  return;
}


// ==== FUN_006444b0 @ 0x006444b0 ====

void FUN_006444b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3e1c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006444d0 @ 0x006444d0 ====

void FUN_006444d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3e34;
  return;
}


// ==== FUN_006444e0 @ 0x006444e0 ====

void FUN_006444e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3e8c;
  return;
}


// ==== FUN_006444f0 @ 0x006444f0 ====

void FUN_006444f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3ea4;
  return;
}


// ==== FUN_00644500 @ 0x00644500 ====

void FUN_00644500(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3e34;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00644520 @ 0x00644520 ====

void FUN_00644520(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3e8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00644540 @ 0x00644540 ====

void FUN_00644540(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3ea4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00644560 @ 0x00644560 ====

undefined4 FUN_00644560(undefined2 param_1)

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


// ==== FUN_00644590 @ 0x00644590 ====

undefined4 FUN_00644590(void)

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


// ==== FUN_006445b0 @ 0x006445b0 ====

undefined4 FUN_006445b0(void)

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


// ==== FUN_006445d0 @ 0x006445d0 ====

void FUN_006445d0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b8c8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d3ec4;
  DAT_00b5a760 = 0;
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
  *in_ECX = &PTR_FUN_009d3e1c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00644670 @ 0x00644670 ====

void FUN_00644670(undefined2 *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined2 *puVar3;
  int iVar4;
  int in_ECX;
  undefined1 auStack_10e [242];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098b8e0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x410);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00658ff0();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 8))(param_1);
  puVar3 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = *param_1;
  *(int **)(puVar3 + 2) = piVar2;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  if (iVar4 != 0) {
    FUN_0044a580(auStack_10e + -0xe,&DAT_009d3e14,s_LogicObject_Article_Item_Set_Fly_009d3ddc);
    FUN_00797b80(auStack_10e + -0xe);
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_00644740 @ 0x00644740 ====

void FUN_00644740(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098b908;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3ec4;
  pvVar2 = operator_new(0x2818);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00644850();
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
    uVar3 = FUN_00644dc0(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a760 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a760 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00644810 @ 0x00644810 ====

void FUN_00644810(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3ebc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_00644830 @ 0x00644830 ====

void FUN_00644830(byte param_1)

{
  void *in_ECX;
  
  FUN_00644810();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00644850 @ 0x00644850 ====

void FUN_00644850(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b928;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3edc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d3ebc;
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


// ==== FUN_00644900 @ 0x00644900 ====

void FUN_00644900(byte param_1)

{
  void *in_ECX;
  
  FUN_00644920();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00644920 @ 0x00644920 ====

void FUN_00644920(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b953;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3edc;
  local_4 = 1;
  if ((void *)in_ECX[0xa04] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d3ebc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x200,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d3e8c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xa04]);
  return;
}


// ==== FUN_006449a0 @ 0x006449a0 ====

void * FUN_006449a0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ef0,0x85);
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


// ==== FUN_00644a50 @ 0x00644a50 ====

undefined4 FUN_00644a50(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ef0,0xa9);
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


// ==== FUN_00644ad0 @ 0x00644ad0 ====

void FUN_00644ad0(byte param_1)

{
  void *in_ECX;
  
  FUN_006445d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00644af0 @ 0x00644af0 ====

void FUN_00644af0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d3f70;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_00644b10 @ 0x00644b10 ====

void FUN_00644b10(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b973;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3f78;
  local_4 = 1;
  if ((void *)in_ECX[0x1004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d3f70;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x200,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d3ea4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1004]);
  return;
}


// ==== FUN_00644b90 @ 0x00644b90 ====

undefined4 FUN_00644b90(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ef0,0xa9);
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


// ==== FUN_00644c10 @ 0x00644c10 ====

undefined4 * FUN_00644c10(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d3ef0,0x85);
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


// ==== FUN_00644cd0 @ 0x00644cd0 ====

void FUN_00644cd0(byte param_1)

{
  void *in_ECX;
  
  FUN_00644af0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00644cf0 @ 0x00644cf0 ====

void FUN_00644cf0(byte param_1)

{
  void *in_ECX;
  
  FUN_00644b10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00644d10 @ 0x00644d10 ====

void FUN_00644d10(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b988;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3f78;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d3f70;
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


// ==== FUN_00644dc0 @ 0x00644dc0 ====

void FUN_00644dc0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b9a8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3f94;
  FUN_00644d10();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00644e20 @ 0x00644e20 ====

void FUN_00644e20(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00644e40(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00644e40 @ 0x00644e40 ====

void FUN_00644e40(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00644e40(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00644e40(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00644e80 @ 0x00644e80 ====

void FUN_00644e80(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00644ea0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00644ea0 @ 0x00644ea0 ====

void FUN_00644ea0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00644ea0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00644ea0(param_1[3]);
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


// ==== FUN_00644f10 @ 0x00644f10 ====

void FUN_00644f10(byte param_1)

{
  void *in_ECX;
  
  FUN_00644f30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00644f30 @ 0x00644f30 ====

void FUN_00644f30(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098b9d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d3f94;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00644ea0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00644b10();
  *in_ECX = &PTR_FUN_009d3e34;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00644fa0 @ 0x00644fa0 ====

void FUN_00644fa0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d407c;
  return;
}


// ==== FUN_00644fb0 @ 0x00644fb0 ====

void FUN_00644fb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d407c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00644fd0 @ 0x00644fd0 ====

void FUN_00644fd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4090;
  return;
}


// ==== FUN_00644fe0 @ 0x00644fe0 ====

void FUN_00644fe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d40ac;
  return;
}


// ==== FUN_00644ff0 @ 0x00644ff0 ====

void FUN_00644ff0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4104;
  return;
}


// ==== FUN_00645000 @ 0x00645000 ====

void FUN_00645000(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d411c;
  return;
}


// ==== FUN_00645010 @ 0x00645010 ====

void FUN_00645010(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4174;
  return;
}


// ==== FUN_00645020 @ 0x00645020 ====

void FUN_00645020(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4090;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00645040 @ 0x00645040 ====

void FUN_00645040(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d40ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00645060 @ 0x00645060 ====

void FUN_00645060(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4104;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00645080 @ 0x00645080 ====

void FUN_00645080(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d411c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006450a0 @ 0x006450a0 ====

void FUN_006450a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4174;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006450c0 @ 0x006450c0 ====

undefined4 FUN_006450c0(undefined2 param_1)

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


// ==== FUN_006450f0 @ 0x006450f0 ====

undefined4 FUN_006450f0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_1c [12];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098b9e8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00659250(param_1);
  local_4 = 0;
  iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x30))(local_1c);
  puStack_8 = (undefined1 *)0xffffffff;
  FUN_00659270();
  if (iVar1 == 0) {
    ExceptionList = pvStack_10;
    return 0;
  }
  uVar2 = FUN_00659300();
  ExceptionList = pvStack_10;
  return uVar2;
}


// ==== FUN_00645180 @ 0x00645180 ====

void FUN_00645180(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098b9fa;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d4194;
  DAT_00b5abb8 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
  }
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
  *in_ECX = &PTR_FUN_009d407c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00645230 @ 0x00645230 ====

void FUN_00645230(undefined2 *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined4 uVar5;
  undefined2 extraout_var;
  undefined2 uVar6;
  int in_ECX;
  undefined2 extraout_var_00;
  undefined1 auStack_11e [2];
  undefined1 auStack_11c [252];
  void *pvStack_20;
  undefined4 uStack_18;
  undefined4 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098ba2b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x94);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_006593b0();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 8))(param_1);
  puVar3 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = param_1[1];
  *(int **)(puVar3 + 2) = piVar2;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  uVar6 = 0;
  if (iVar4 != 0) {
    auStack_11c[0] = 0;
    uVar5 = FUN_0044a580(auStack_11c,s_LogicObject_Article_Item_Option_F_009d3ff0,param_1[1]);
    FUN_00797b80(uVar5);
    auStack_11c[0] = 0;
    uVar5 = FUN_0044a580(auStack_11c,s_File___s__Line___d_009d4064,
                         s___Article_Item_Option_Flyweight__009d4034,0x3c);
    FUN_00797b80(uVar5);
    FUN_00797a40();
    uVar6 = extraout_var;
  }
  FUN_00659250(CONCAT22(uVar6,*param_1));
  uStack_14 = 1;
  iVar4 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x30))(auStack_11e + -0xe);
  uStack_18 = 0xffffffff;
  FUN_00659270();
  if (iVar4 == 0) {
    pvVar1 = operator_new(0x10);
    uStack_18 = 2;
    if (pvVar1 == (void *)0x0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_00659250(CONCAT22(extraout_var_00,*param_1));
    }
    uStack_18 = 0xffffffff;
    FUN_00659290(piVar2);
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x28))(uVar5);
  }
  else {
    FUN_00659290(piVar2);
  }
  ExceptionList = pvStack_20;
  return;
}


// ==== FUN_006453c0 @ 0x006453c0 ====

void FUN_006453c0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098ba5e;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4194;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_006454f0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x1028);
  local_4._0_1_ = 2;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00645a80(*puVar1);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar3;
  pvVar2 = operator_new(0x1028);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00645dd0();
  }
  in_ECX[3] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abb8 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abb8 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006454b0 @ 0x006454b0 ====

void FUN_006454b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d418c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_006454d0 @ 0x006454d0 ====

void FUN_006454d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006454b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006454f0 @ 0x006454f0 ====

void FUN_006454f0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098ba78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d41a8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d418c;
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


// ==== FUN_006455a0 @ 0x006455a0 ====

void FUN_006455a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006455c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006455c0 @ 0x006455c0 ====

void FUN_006455c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098baa3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d41a8;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d418c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d4090;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_00645640 @ 0x00645640 ====

void * FUN_00645640(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d41c0,0x85);
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


// ==== FUN_006456f0 @ 0x006456f0 ====

undefined4 FUN_006456f0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d41c0,0xa9);
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


// ==== FUN_00645770 @ 0x00645770 ====

void FUN_00645770(byte param_1)

{
  void *in_ECX;
  
  FUN_00645180();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00645790 @ 0x00645790 ====

void FUN_00645790(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4238;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_006457b0 @ 0x006457b0 ====

void FUN_006457b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bac3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4240;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d4238;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d4104;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_00645830 @ 0x00645830 ====

void FUN_00645830(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4258;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00645850 @ 0x00645850 ====

void FUN_00645850(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bae3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4260;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d4258;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d4174;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_006458d0 @ 0x006458d0 ====

undefined4 FUN_006458d0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d41c0,0xa9);
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


// ==== FUN_00645950 @ 0x00645950 ====

void FUN_00645950(byte param_1)

{
  void *in_ECX;
  
  FUN_00645790();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00645970 @ 0x00645970 ====

void FUN_00645970(byte param_1)

{
  void *in_ECX;
  
  FUN_006457b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00645990 @ 0x00645990 ====

void FUN_00645990(byte param_1)

{
  void *in_ECX;
  
  FUN_00645830();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006459b0 @ 0x006459b0 ====

void FUN_006459b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00645850();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006459d0 @ 0x006459d0 ====

void FUN_006459d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098baf8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4240;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d4238;
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


// ==== FUN_00645a80 @ 0x00645a80 ====

void FUN_00645a80(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bb18;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d427c;
  FUN_006459d0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00645ae0 @ 0x00645ae0 ====

void FUN_00645ae0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00645b00(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00645b00 @ 0x00645b00 ====

void FUN_00645b00(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00645b00(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00645b00(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00645b40 @ 0x00645b40 ====

void FUN_00645b40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00645b60(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00645b60 @ 0x00645b60 ====

void FUN_00645b60(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00645b60(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00645b60(param_1[3]);
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


// ==== FUN_00645bd0 @ 0x00645bd0 ====

undefined4 * FUN_00645bd0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d41c0,0x85);
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


// ==== FUN_00645c90 @ 0x00645c90 ====

void FUN_00645c90(byte param_1)

{
  void *in_ECX;
  
  FUN_00645cb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00645cb0 @ 0x00645cb0 ====

void FUN_00645cb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098bb43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d427c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00645b60(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_006457b0();
  *in_ECX = &PTR_FUN_009d40ac;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00645d20 @ 0x00645d20 ====

void FUN_00645d20(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bb58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4260;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d4258;
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


// ==== FUN_00645dd0 @ 0x00645dd0 ====

void FUN_00645dd0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bb78;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d42d4;
  FUN_00645d20();
  in_ECX[2] = 0;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00645e30 @ 0x00645e30 ====

void FUN_00645e30(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00645e50(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00645e50 @ 0x00645e50 ====

void FUN_00645e50(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00645e50(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00645e50(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00645e90 @ 0x00645e90 ====

undefined4 * FUN_00645e90(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  int unaff_EBP;
  undefined4 *puVar4;
  
  piVar2 = (int *)(**(code **)(*(int *)(in_ECX + 0x10) + 0xc))(1,0);
  *piVar2 = in_ECX;
  piVar2[2] = 0;
  piVar2[3] = 0;
  piVar2[4] = 0;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(undefined4 **)(in_ECX + 4) == (undefined4 *)0x0) {
    *(int **)(in_ECX + 4) = piVar2;
    return (undefined4 *)0x0;
  }
  do {
    cVar1 = FUN_00659210(*puVar4);
    if (cVar1 == '\0') {
      cVar1 = FUN_00659210(in_ECX);
      if (cVar1 == '\0') {
        (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,piVar2);
        return puVar4;
      }
      puVar3 = (undefined4 *)puVar4[3];
      if (puVar3 == (undefined4 *)0x0) {
        piVar2[4] = (int)puVar4;
        puVar4[3] = piVar2;
LAB_00645f0e:
        FUN_0061f0e0(piVar2,*(undefined4 *)(unaff_EBP + 4));
        return (undefined4 *)0x0;
      }
    }
    else {
      puVar3 = (undefined4 *)puVar4[2];
      if (puVar3 == (undefined4 *)0x0) {
        piVar2[4] = (int)puVar4;
        puVar4[2] = piVar2;
        goto LAB_00645f0e;
      }
    }
    puVar4 = puVar3;
  } while( true );
}


// ==== FUN_00645f40 @ 0x00645f40 ====

void FUN_00645f40(undefined4 *param_1)

{
  int *in_ECX;
  
  FUN_00645f60(*param_1);
  (**(code **)(*in_ECX + 0x3c))(param_1);
  return;
}


// ==== FUN_00645f60 @ 0x00645f60 ====

void FUN_00645f60(undefined4 *param_1)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    if (param_1 != (undefined4 *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00645f88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)*param_1)();
      return;
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,param_1);
  }
  return;
}


// ==== FUN_00645f90 @ 0x00645f90 ====

void FUN_00645f90(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00645fb0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00645fb0 @ 0x00645fb0 ====

void FUN_00645fb0(int *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00645fb0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00645fb0(param_1[3]);
  }
  puVar1 = (undefined4 *)*param_1;
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,puVar1);
    (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
    return;
  }
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)(1);
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00646030 @ 0x00646030 ====

undefined4 * FUN_00646030(undefined4 param_1)

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
    cVar1 = FUN_00659210(*puVar3);
    if (cVar1 == '\0') {
      cVar1 = FUN_00659210(param_1);
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


// ==== FUN_006460b0 @ 0x006460b0 ====

void FUN_006460b0(byte param_1)

{
  void *in_ECX;
  
  FUN_006460d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006460d0 @ 0x006460d0 ====

void FUN_006460d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098bba3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d42d4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00645fb0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00645850();
  *in_ECX = &PTR_FUN_009d411c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00646140 @ 0x00646140 ====

void FUN_00646140(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d43a4;
  return;
}


// ==== FUN_00646150 @ 0x00646150 ====

void FUN_00646150(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d43a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== __break @ 0x0064616f ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00646170 @ 0x00646170 ====

void FUN_00646170(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00646175. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_00646180 @ 0x00646180 ====

undefined4 FUN_00646180(void)

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


// ==== FUN_006461a0 @ 0x006461a0 ====

undefined4 FUN_006461a0(void)

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


// ==== FUN_006461d0 @ 0x006461d0 ====

undefined4 FUN_006461d0(undefined2 param_1)

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


// ==== FUN_00646200 @ 0x00646200 ====

void FUN_00646200(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bbb8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d4454;
  DAT_00b5a738 = 0;
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
  *in_ECX = &PTR_FUN_009d43a4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006462a0 @ 0x006462a0 ====

void FUN_006462a0(undefined2 *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined1 auStack_20e [242];
  undefined1 auStack_11c [256];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098bbd0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x130);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00659550();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 8))(param_1);
  puVar3 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = *param_1;
  *(int **)(puVar3 + 2) = piVar2;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_20e + -0xe,s_LogicObjet_Article_Item__u__Flyw_009d432c,*param_1);
    FUN_00797b80(uVar5);
    auStack_11c[0] = 0;
    uVar5 = FUN_0044a580(auStack_11c,s_File___s__Line___d_009d438c,
                         s___Article_Item_Flyweight_Contain_009d4364,0x38);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_00646390 @ 0x00646390 ====

void FUN_00646390(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098bbf8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4454;
  pvVar2 = operator_new(0x2818);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00646530();
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
    uVar3 = FUN_00646aa0(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a738 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a738 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00646460 @ 0x00646460 ====

void FUN_00646460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d43c4;
  return;
}


// ==== FUN_00646470 @ 0x00646470 ====

void FUN_00646470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d441c;
  return;
}


// ==== FUN_00646480 @ 0x00646480 ====

void FUN_00646480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4434;
  return;
}


// ==== FUN_00646490 @ 0x00646490 ====

void FUN_00646490(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d43c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006464b0 @ 0x006464b0 ====

void FUN_006464b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d441c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006464d0 @ 0x006464d0 ====

void FUN_006464d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4434;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006464f0 @ 0x006464f0 ====

void FUN_006464f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d444c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_00646510 @ 0x00646510 ====

void FUN_00646510(byte param_1)

{
  void *in_ECX;
  
  FUN_006464f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00646530 @ 0x00646530 ====

void FUN_00646530(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bc18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4470;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d444c;
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


// ==== FUN_006465e0 @ 0x006465e0 ====

void FUN_006465e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00646600();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00646600 @ 0x00646600 ====

void FUN_00646600(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bc43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4470;
  local_4 = 1;
  if ((void *)in_ECX[0xa04] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d444c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x200,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d441c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xa04]);
  return;
}


// ==== FUN_00646680 @ 0x00646680 ====

void * FUN_00646680(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d4488,0x85);
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


// ==== FUN_00646730 @ 0x00646730 ====

undefined4 FUN_00646730(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d4488,0xa9);
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


// ==== FUN_006467b0 @ 0x006467b0 ====

void FUN_006467b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00646200();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006467d0 @ 0x006467d0 ====

void FUN_006467d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4500;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_006467f0 @ 0x006467f0 ====

void FUN_006467f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bc63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4508;
  local_4 = 1;
  if ((void *)in_ECX[0x1004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009d4500;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x200,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009d4434;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1004]);
  return;
}


// ==== FUN_00646870 @ 0x00646870 ====

undefined4 FUN_00646870(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d4488,0xa9);
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


// ==== FUN_006468f0 @ 0x006468f0 ====

undefined4 * FUN_006468f0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d4488,0x85);
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


// ==== FUN_006469b0 @ 0x006469b0 ====

void FUN_006469b0(byte param_1)

{
  void *in_ECX;
  
  FUN_006467d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006469d0 @ 0x006469d0 ====

void FUN_006469d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006467f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006469f0 @ 0x006469f0 ====

void FUN_006469f0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bc78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4508;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d4500;
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


// ==== FUN_00646aa0 @ 0x00646aa0 ====

void FUN_00646aa0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bc98;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4524;
  FUN_006469f0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00646b00 @ 0x00646b00 ====

void FUN_00646b00(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00646b20(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00646b20 @ 0x00646b20 ====

void FUN_00646b20(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00646b20(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00646b20(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00646b60 @ 0x00646b60 ====

void FUN_00646b60(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00646b80(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00646b80 @ 0x00646b80 ====

void FUN_00646b80(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00646b80(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00646b80(param_1[3]);
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


// ==== FUN_00646bf0 @ 0x00646bf0 ====

void FUN_00646bf0(byte param_1)

{
  void *in_ECX;
  
  FUN_00646c10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00646c10 @ 0x00646c10 ====

void FUN_00646c10(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098bcc3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4524;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00646b80(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_006467f0();
  *in_ECX = &PTR_FUN_009d43c4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00646c80 @ 0x00646c80 ====

void FUN_00646c80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4614;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00646ca0 @ 0x00646ca0 ====

undefined1 FUN_00646ca0(void)

{
  return 0;
}


// ==== FUN_00646cb0 @ 0x00646cb0 ====

undefined2 FUN_00646cb0(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x14))();
  switch(*(undefined1 *)(iVar1 + 0x20)) {
  default:
    return 0;
  case 1:
    piVar2 = (int *)(**(code **)(*param_1 + 0x48))();
    iVar1 = (**(code **)(*piVar2 + 4))();
    return *(undefined2 *)(iVar1 + 0x80);
  case 2:
    piVar2 = (int *)(**(code **)(*param_1 + 0x48))();
    iVar1 = (**(code **)(*piVar2 + 4))();
    return *(undefined2 *)(iVar1 + 0x82);
  case 3:
    piVar2 = (int *)(**(code **)(*param_1 + 0x48))();
    iVar1 = (**(code **)(*piVar2 + 4))();
    return *(undefined2 *)(iVar1 + 0x84);
  }
}


// ==== FUN_00646d30 @ 0x00646d30 ====

bool FUN_00646d30(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x48))();
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (*(char *)(iVar2 + 0x7e) == '\0') {
    return false;
  }
  iVar2 = (**(code **)(*param_1 + 0x14))();
  return *(short *)(iVar2 + 2) == 0;
}


// ==== FUN_00646d80 @ 0x00646d80 ====

void FUN_00646d80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4664;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a734 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a734 = in_ECX;
  return;
}


// ==== FUN_00646db0 @ 0x00646db0 ====

uint FUN_00646db0(int *param_1)

{
  uint in_EAX;
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x2c))();
    in_EAX = *(uint *)(iVar1 + 8);
    if (((int)in_EAX < 0x40f) || (0x410 < (int)in_EAX)) {
      return CONCAT31((int3)(in_EAX >> 8),1);
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00646de0 @ 0x00646de0 ====

bool FUN_00646de0(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int *in_ECX;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    cVar3 = (**(code **)(*in_ECX + 8))(param_1);
    if (cVar3 == '\x01') {
      return true;
    }
    cVar3 = (**(code **)(*in_ECX + 8))(param_2);
    return cVar3 == '\x01';
  }
  iVar4 = (**(code **)(*param_1 + 0x2c))();
  uVar1 = *(undefined4 *)(iVar4 + 8);
  iVar4 = (**(code **)(*param_2 + 0x2c))();
  uVar2 = *(undefined4 *)(iVar4 + 8);
  cVar3 = FUN_00647830(uVar1,uVar2);
  if (cVar3 == '\0') {
    return false;
  }
  cVar3 = FUN_00647830(uVar2,uVar1);
  return cVar3 != '\0';
}


// ==== FUN_00646e60 @ 0x00646e60 ====

char FUN_00646e60(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  
  iVar2 = FUN_00803725(param_1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (iVar2 == 0) {
    return '\0';
  }
  piVar1 = *(int **)(iVar2 + 0x24);
  iVar2 = (**(code **)(*piVar1 + 0x2c))(4);
  iVar3 = (**(code **)(*piVar1 + 0x2c))(5);
  cVar4 = iVar2 != 0;
  if (iVar3 != 0) {
    cVar4 = cVar4 + '\x01';
  }
  return cVar4;
}


// ==== FUN_00646ec0 @ 0x00646ec0 ====

undefined4 FUN_00646ec0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = FUN_00803725(param_1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (iVar2 == 0) {
    return 0;
  }
  piVar1 = *(int **)(iVar2 + 0x24);
  iVar2 = (**(code **)(*piVar1 + 0x20))(4);
  iVar3 = (**(code **)(*piVar1 + 0x20))(5);
  iVar4 = (**(code **)(*piVar1 + 0x20))(0xd);
  iVar5 = (**(code **)(*piVar1 + 0x20))(0xe);
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x24))(0xd,iVar2);
  }
  if (iVar3 != 0) {
    (**(code **)(*piVar1 + 0x24))(0xe,iVar3);
  }
  if (iVar4 != 0) {
    (**(code **)(*piVar1 + 0x24))(4,iVar4);
  }
  if (iVar5 != 0) {
    (**(code **)(*piVar1 + 0x24))(5,iVar5);
  }
  return 1;
}


// ==== FUN_00646ee4 @ 0x00646ee4 ====

undefined4 FUN_00646ee4(void)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = *(int **)(in_EAX + 0x24);
  iVar2 = (**(code **)(*piVar1 + 0x20))(4);
  iVar3 = (**(code **)(*piVar1 + 0x20))(5);
  iVar4 = (**(code **)(*piVar1 + 0x20))(0xd);
  iVar5 = (**(code **)(*piVar1 + 0x20))(0xe);
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x24))(0xd,iVar2);
  }
  if (iVar3 != 0) {
    (**(code **)(*piVar1 + 0x24))(0xe,iVar3);
  }
  if (iVar4 != 0) {
    (**(code **)(*piVar1 + 0x24))(4,iVar4);
  }
  if (iVar5 != 0) {
    (**(code **)(*piVar1 + 0x24))(5,iVar5);
  }
  return 1;
}


// ==== FUN_00646f60 @ 0x00646f60 ====

char FUN_00646f60(undefined4 param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 local_4;
  
  iVar3 = FUN_00803725(param_1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (iVar3 == 0) {
    return '\x02';
  }
  if (param_2 == 0) {
    return '\x02';
  }
  piVar1 = *(int **)(iVar3 + 0x20);
  if ((*(int **)(iVar3 + 0x24) == (int *)0x0) || (piVar1 == (int *)0x0)) {
    return '\x02';
  }
  cVar2 = (**(code **)(**(int **)(iVar3 + 0x24) + 0x30))(param_2,&local_4);
  if (cVar2 == '\x01') {
    return '\0';
  }
  local_4 = (uint)local_4._3_1_ << 0x18;
  cVar2 = (**(code **)(*piVar1 + 0x38))(param_2,&local_4);
  return (cVar2 != '\x01') + '\x01';
}


// ==== FUN_00647000 @ 0x00647000 ====

undefined4 FUN_00647000(undefined4 param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  undefined4 unaff_EDI;
  undefined1 auStackY_a8 [128];
  
  iVar3 = FUN_00803725(param_1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if ((iVar3 != 0) && (param_2 != 0)) {
    iVar4 = (**(code **)(*in_ECX + 0x24))(param_1,param_2);
    if (iVar4 == 0) {
      piVar1 = *(int **)(iVar3 + 0x24);
      cVar2 = (**(code **)(*piVar1 + 0x30))(param_2,auStackY_a8 + 0xa4);
      if (cVar2 != '\0') {
        (**(code **)(*piVar1 + 0x24))(unaff_EDI,param_2);
        return 2;
      }
    }
    else if (iVar4 == 1) {
      piVar1 = *(int **)(iVar3 + 0x20);
      cVar2 = (**(code **)(*piVar1 + 0x38))(param_2,auStackY_a8 + 0xa4);
      if (cVar2 != '\0') {
        (**(code **)(*piVar1 + 0x1c))(auStackY_a8 + 0x9c,param_2);
      }
    }
  }
  return 2;
}


// ==== FUN_006470b0 @ 0x006470b0 ====

uint FUN_006470b0(uint param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x24) == 0)) {
    return param_1 & 0xffffff00;
  }
  piVar4 = *(int **)(param_1 + 0x24);
  piVar1 = (int *)(**(code **)(*piVar4 + 0x2c))(4);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x2c))();
    uVar3 = *(uint *)(iVar2 + 8);
    if ((uVar3 == 0x40a) || (uVar3 == 0x40b)) goto LAB_006470ec;
  }
  piVar4 = (int *)(**(code **)(*piVar4 + 0x2c))(5);
  uVar3 = 0;
  if (piVar4 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar4 + 0x2c))();
    uVar3 = *(uint *)(iVar2 + 8);
    if ((uVar3 == 0x40a) || (uVar3 == 0x40b)) {
LAB_006470ec:
      return CONCAT31((int3)(uVar3 >> 8),1);
    }
  }
  return uVar3 & 0xffffff00;
}


// ==== FUN_00647120 @ 0x00647120 ====

void FUN_00647120(int *param_1,int param_2)

{
  int *piVar1;
  byte bVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iStack_c;
  byte *pbStack_8;
  
  iVar4 = (**(code **)(*param_1 + 0x14))();
  iStack_c = 0;
  if (*(char *)(iVar4 + 0x1f) != '\0') {
    pbStack_8 = (byte *)(iVar4 + 0x10);
    do {
      bVar2 = *pbStack_8;
      piVar5 = (int *)(**(code **)(*DAT_00b5abb8 + 8))(*(undefined2 *)(pbStack_8 + -2));
      if (piVar5 != (int *)0x0) {
        iVar6 = (**(code **)(*piVar5 + 4))();
        iVar6 = *(int *)(iVar6 + 4);
        iVar7 = (**(code **)(*piVar5 + 4))();
        iVar7 = *(int *)(iVar7 + 0x88);
        iVar8 = (**(code **)(*piVar5 + 4))();
        piVar5 = (int *)(param_2 + iVar6 * 4);
        *piVar5 = *piVar5 + (int)((*(int *)(iVar8 + 0x8c) - iVar7) * (uint)bVar2) / 100 + iVar7;
      }
      iStack_c = iStack_c + 1;
      pbStack_8 = pbStack_8 + 4;
    } while (iStack_c < (int)(uint)*(byte *)(iVar4 + 0x1f));
  }
  piVar5 = (int *)(**(code **)(*param_1 + 0x48))();
  if ((piVar5 != (int *)0x0) && (cVar3 = (**(code **)(*piVar5 + 0xc))(), cVar3 != '\0')) {
    iVar4 = (**(code **)(*piVar5 + 4))();
    uVar9 = 0;
    if (*(int *)(iVar4 + 0xe4) != 0) {
      piVar5 = (int *)(iVar4 + 0xb8);
      do {
        piVar1 = (int *)(param_2 + (uint)*(ushort *)(piVar5 + -1) * 4);
        *piVar1 = *piVar1 + *piVar5;
        uVar9 = uVar9 + 1;
        piVar5 = piVar5 + 2;
      } while (uVar9 < *(uint *)(iVar4 + 0xe4));
    }
  }
  return;
}


// ==== FUN_00647240 @ 0x00647240 ====

undefined4 FUN_00647240(int *param_1)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar3 = (**(code **)(*param_1 + 0x14))();
  piVar4 = (int *)(**(code **)(*param_1 + 0x48))();
  if (((piVar4 == (int *)0x0) || (iVar5 = (**(code **)(*piVar4 + 4))(), 4 < *(byte *)(iVar3 + 0x1f))
      ) || (4 < *(byte *)(iVar3 + 0x1e))) {
    return 0;
  }
  if (*(char *)(iVar3 + 0x21) == '\x01') {
    if (*(ushort *)(iVar5 + 0x76) < 2) {
      return 0;
    }
    if (*(ushort *)(iVar5 + 0x76) < *(ushort *)(iVar3 + 0xc)) {
      return 0;
    }
    if (*(ushort *)(iVar3 + 0xc) == 0) {
      return 0;
    }
  }
  if (*(byte *)(iVar3 + 0x1e) != 0) {
    uVar7 = 0;
    do {
      sVar1 = *(short *)(iVar3 + 4 + uVar7 * 2);
      if (sVar1 != 0) {
        piVar4 = (int *)(**(code **)(*DAT_00b5abb4 + 4))(sVar1);
        if (piVar4 == (int *)0x0) {
          return 0;
        }
        cVar2 = (**(code **)(*piVar4 + 0xc))(*(undefined4 *)(iVar5 + 0xc));
        if (cVar2 == '\0') {
          return 0;
        }
      }
      bVar6 = (char)uVar7 + 1;
      uVar7 = (uint)bVar6;
    } while (bVar6 < *(byte *)(iVar3 + 0x1e));
  }
  return 1;
}


// ==== FUN_00647300 @ 0x00647300 ====

uint FUN_00647300(int *param_1)

{
  ushort uVar1;
  ulonglong uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *in_ECX;
  
  piVar3 = (int *)(**(code **)(*param_1 + 0x48))();
  uVar4 = (**(code **)(*piVar3 + 4))();
  if (*(char *)(uVar4 + 0x7e) == '\0') {
    return uVar4 & 0xffffff00;
  }
  uVar4 = (**(code **)(*param_1 + 0x14))();
  uVar1 = *(ushort *)(uVar4 + 2);
  if (uVar1 != 0) {
    uVar4 = (**(code **)(*in_ECX + 0x40))(param_1);
    if ((short)uVar4 != 0) {
      iVar5 = (**(code **)(*DAT_00b5a6b8 + 4))();
      uVar2 = (ulonglong)((uint)uVar1 * 100) / (ulonglong)(longlong)(int)(uVar4 & 0xffff);
      return CONCAT31((int3)(uVar2 >> 8),(byte)uVar2 <= *(byte *)(iVar5 + 0x71));
    }
  }
  return uVar4 & 0xffffff00;
}


// ==== FUN_00647380 @ 0x00647380 ====

void FUN_00647380(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a734 = 0;
  *in_ECX = &PTR_FUN_009d4614;
  return;
}


// ==== FUN_006473a0 @ 0x006473a0 ====

bool FUN_006473a0(int param_1,int *param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  byte *pbVar5;
  ushort *puVar6;
  
  if (param_2 == (int *)0x0) {
    return false;
  }
  iVar3 = FUN_00803725(param_1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (iVar3 == 0) {
    return false;
  }
  if (*(int **)(param_1 + 4) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0x18))();
  }
  pbVar5 = (byte *)(**(code **)(*piVar4 + 8))();
  bVar1 = *pbVar5;
  iVar3 = (**(code **)(*param_2 + 0x2c))();
  if ((*(uint *)(iVar3 + 0x18) & 0x80000000U >> (bVar1 & 0x1f)) != 0) {
    if (*(int **)(param_1 + 0x48) == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x48) + 0x28))();
    }
    puVar6 = (ushort *)(**(code **)(*piVar4 + 8))();
    iVar3 = (**(code **)(*param_2 + 0x2c))();
    if (*(ushort *)(iVar3 + 0x28) <= *puVar6) {
      piVar4 = (int *)(**(code **)(*param_2 + 0x48))();
      (**(code **)(*param_2 + 0x48))();
      if (piVar4 != (int *)0x0) {
        cVar2 = (**(code **)(*piVar4 + 0xc))();
        return cVar2 != '\x01';
      }
    }
  }
  return false;
}


// ==== FUN_00647460 @ 0x00647460 ====

bool FUN_00647460(int param_1,int *param_2)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  byte *pbVar5;
  int iVar6;
  ushort *puVar7;
  
  if (param_2 == (int *)0x0) {
    return false;
  }
  iVar3 = FUN_00803725(param_1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (iVar3 == 0) {
    return false;
  }
  if (*(int **)(param_1 + 4) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0x18))();
  }
  pbVar5 = (byte *)(**(code **)(*piVar4 + 8))();
  bVar1 = *pbVar5;
  iVar6 = (**(code **)(*param_2 + 0x2c))();
  if ((*(uint *)(iVar6 + 0x18) & 0x80000000U >> (bVar1 & 0x1f)) != 0) {
    if (*(int **)(iVar3 + 0x48) == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x48) + 0x28))();
    }
    puVar7 = (ushort *)(**(code **)(*piVar4 + 8))();
    iVar3 = (**(code **)(*param_2 + 0x2c))();
    if (*(ushort *)(iVar3 + 0x28) <= *puVar7) {
      piVar4 = (int *)(**(code **)(*param_2 + 0x48))();
      if (piVar4 != (int *)0x0) {
        cVar2 = (**(code **)(*piVar4 + 0xc))();
        if (cVar2 == '\0') {
          return true;
        }
        piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x50) + 0x14))(0);
        iVar3 = (**(code **)(*param_2 + 0x34))();
        puVar7 = (ushort *)(**(code **)(*piVar4 + 0x14))();
        if (*(ushort *)(iVar3 + 0x6c) <= *puVar7) {
          iVar6 = (**(code **)(*piVar4 + 0x14))();
          if (*(ushort *)(iVar3 + 0x6e) <= *(ushort *)(iVar6 + 2)) {
            iVar6 = (**(code **)(*piVar4 + 0x14))();
            return *(ushort *)(iVar3 + 0x70) <= *(ushort *)(iVar6 + 6);
          }
        }
      }
    }
  }
  return false;
}


// ==== FUN_00647570 @ 0x00647570 ====

undefined4 FUN_00647570(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_2 == (int *)0x0) {
    return 0xff;
  }
  iVar1 = FUN_00803725(param_1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (iVar1 == 0) {
    return 0xff;
  }
  if (*(int **)(param_1 + 4) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0x18))();
  }
  (**(code **)(*piVar2 + 8))();
  iVar1 = (**(code **)(*param_2 + 0x2c))();
  iVar1 = *(int *)(iVar1 + 8);
  if (((((iVar1 == 0x400) || (iVar1 == 0x402)) || (iVar1 == 0x403)) ||
      ((((iVar1 == 0x404 || (iVar1 == 0x405)) ||
        ((iVar1 == 0x407 || ((iVar1 == 0x409 || (iVar1 == 0x40a)))))) || (iVar1 == 0x40b)))) ||
     ((((iVar1 == 0x40c || (iVar1 == 0x411)) || (iVar1 == 0x412)) ||
      ((iVar1 == 0x413 || (uVar3 = 1, iVar1 == 0x414)))))) {
    uVar3 = 2;
  }
  return uVar3;
}


// ==== FUN_00647640 @ 0x00647640 ====

void FUN_00647640(int *param_1,int param_2)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  undefined2 *puVar5;
  undefined4 uVar6;
  byte bVar7;
  uint uVar8;
  byte local_101;
  undefined1 auStack_100 [256];
  
  uVar8 = 0;
  local_101 = 0;
  iVar3 = (**(code **)(*param_1 + 0x14))();
  if (*(char *)(iVar3 + 0x1e) != '\0') {
    do {
      bVar7 = (byte)uVar8;
      iVar3 = (**(code **)(*param_1 + 0x14))();
      sVar2 = *(short *)(iVar3 + 4 + uVar8 * 2);
      if (sVar2 != 0) {
        piVar4 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(sVar2);
        if (piVar4 == (int *)0x0) {
          puVar5 = (undefined2 *)(**(code **)(*param_1 + 0x14))();
          uVar6 = FUN_0044a580(auStack_100,s_AddSocketOption___Wrong_Socket_I_009d4580,sVar2,*puVar5
                              );
          FUN_00797b80(uVar6);
        }
        else {
          iVar3 = (**(code **)(*piVar4 + 4))();
          uVar8 = 0;
          if (*(int *)(iVar3 + 0xe4) != 0) {
            piVar4 = (int *)(iVar3 + 0xb8);
            do {
              piVar1 = (int *)(param_2 + (uint)*(ushort *)(piVar4 + -1) * 4);
              *piVar1 = *piVar1 + *piVar4;
              uVar8 = uVar8 + 1;
              piVar4 = piVar4 + 2;
            } while (uVar8 < *(uint *)(iVar3 + 0xe4));
            bVar7 = local_101;
          }
        }
      }
      local_101 = bVar7 + 1;
      uVar8 = (uint)local_101;
      iVar3 = (**(code **)(*param_1 + 0x14))();
    } while (local_101 < *(byte *)(iVar3 + 0x1e));
  }
  return;
}


// ==== FUN_00647730 @ 0x00647730 ====

void FUN_00647730(int *param_1)

{
  short sVar1;
  char cVar2;
  undefined2 *puVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  byte bVar7;
  uint uVar8;
  char acStack_100 [256];
  
  if (param_1 != (int *)0x0) {
    puVar3 = (undefined2 *)(**(code **)(*param_1 + 0x14))();
    piVar4 = (int *)(**(code **)(*param_1 + 0x48))();
    if (((((piVar4 != (int *)0x0) &&
          (iVar5 = (**(code **)(*piVar4 + 4))(), *(byte *)((int)puVar3 + 0x1f) < 5)) &&
         (*(byte *)(puVar3 + 0xf) < 5)) &&
        ((*(char *)((int)puVar3 + 0x21) != '\x01' ||
         (((1 < *(ushort *)(iVar5 + 0x76) && ((ushort)puVar3[6] <= *(ushort *)(iVar5 + 0x76))) &&
          (puVar3[6] != 0)))))) && (uVar8 = 0, *(byte *)(puVar3 + 0xf) != 0)) {
      do {
        sVar1 = puVar3[uVar8 + 2];
        if (((sVar1 != 0) &&
            (piVar4 = (int *)(**(code **)(*DAT_00b5abb4 + 4))(sVar1), piVar4 != (int *)0x0)) &&
           (cVar2 = (**(code **)(*piVar4 + 0xc))(*(undefined4 *)(iVar5 + 0xc)), cVar2 == '\0')) {
          acStack_100[0] = cVar2;
          uVar6 = FUN_0044a580(acStack_100,s__ITEM__Deleting_Invalid_SocketIt_009d45c8,*puVar3,sVar1
                              );
          FUN_00797b80(uVar6);
          (**(code **)(*param_1 + 0x3c))(uVar8);
        }
        bVar7 = (char)uVar8 + 1;
        uVar8 = (uint)bVar7;
      } while (bVar7 < *(byte *)(puVar3 + 0xf));
    }
  }
  return;
}


// ==== FUN_00647830 @ 0x00647830 ====

bool FUN_00647830(undefined4 param_1,int param_2)

{
  switch(param_1) {
  case 0x400:
  case 0x402:
  case 0x403:
  case 0x404:
  case 0x405:
  case 0x407:
  case 0x409:
  case 0x40c:
  case 0x40d:
  case 0x411:
  case 0x412:
  case 0x413:
  case 0x414:
    return false;
  case 0x401:
  case 0x406:
  case 0x408:
    break;
  case 0x40a:
    return param_2 == 0x40f;
  case 0x40b:
    return param_2 == 0x410;
  case 0x40e:
    if (param_2 == 0x401) {
      return true;
    }
    if (param_2 == 0x406) {
      return true;
    }
    if (param_2 == 0x408) {
      return true;
    }
    return false;
  case 0x40f:
    return param_2 == 0x40a;
  case 0x410:
    return param_2 == 0x40b;
  default:
    return true;
  }
  if (param_2 == 0x401) {
    return true;
  }
  if (param_2 == 0x406) {
    return true;
  }
  if (param_2 == 0x408) {
    return true;
  }
  if (param_2 == 0x40e) {
    return true;
  }
  return false;
}


// ==== FUN_00647910 @ 0x00647910 ====

void FUN_00647910(byte param_1)

{
  void *in_ECX;
  
  FUN_00647380();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00647930 @ 0x00647930 ====

void FUN_00647930(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00647935. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_00647940 @ 0x00647940 ====

void FUN_00647940(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00647945. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_00647950 @ 0x00647950 ====

void FUN_00647950(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00647955. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_00647960 @ 0x00647960 ====

int FUN_00647960(undefined4 param_1,int *param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))(param_1,param_2);
  if (iVar1 == 0) {
    (**(code **)(*param_2 + 0x10))();
  }
  return iVar1;
}


// ==== FUN_00647990 @ 0x00647990 ====

void FUN_00647990(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bd03;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4888;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a730 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a730 = in_ECX;
  }
  pvVar2 = operator_new(0x80);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_00647b30();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00647a30 @ 0x00647a30 ====

void FUN_00647a30(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bd15;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4888;
  DAT_00b5a730 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009d4838;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00647a90 @ 0x00647a90 ====

void FUN_00647a90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4850;
  return;
}


// ==== FUN_00647aa0 @ 0x00647aa0 ====

void FUN_00647aa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4850;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00647ad0 @ 0x00647ad0 ====

void FUN_00647ad0(void)

{
  FUN_00659b10();
  return;
}


// ==== FUN_00647ae0 @ 0x00647ae0 ====

void FUN_00647ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4838;
  return;
}


// ==== FUN_00647af0 @ 0x00647af0 ====

void FUN_00647af0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4838;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00647b10 @ 0x00647b10 ====

void FUN_00647b10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4868;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x68,1,(_func_void_void_ptr *)&LAB_00647ac0);
  return;
}


// ==== FUN_00647b30 @ 0x00647b30 ====

void FUN_00647b30(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bcd8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4870;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009d4868;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x68,1,FUN_00647ad0,(_func_void_void_ptr *)&LAB_00647ac0);
  in_ECX[0x1c] = 0;
  in_ECX[0x1c] = in_ECX[0x1c] + 1;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = in_ECX + 2;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00647bb0 @ 0x00647bb0 ====

void FUN_00647bb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00647b10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00647bd0 @ 0x00647bd0 ====

void * FUN_00647bd0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098bd39;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x7c);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x74) = *(int *)(in_ECX + 0x74) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x68);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00659b10();
      }
      *(undefined4 *)((int)param_2 + 0x60) = *(undefined4 *)(in_ECX + 0x78);
      *(void **)(in_ECX + 0x78) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)((int)param_2 + 0x5c);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 100) = param_1;
    *(undefined4 *)((int)param_2 + 0x5c) = 0;
    FUN_00659830();
  }
  else {
    if (*(int *)((int)param_2 + 100) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d48a0,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 100) = *(int *)((int)param_2 + 100) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00647ce0 @ 0x00647ce0 ====

undefined4 FUN_00647ce0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 100) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009d48a0,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 100);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 100);
    }
    FUN_00659840();
    *(undefined4 *)(param_2 + 0x5c) = *(undefined4 *)(in_ECX + 0x7c);
    *(int *)(in_ECX + 0x74) = *(int *)(in_ECX + 0x74) + -1;
    *(int *)(in_ECX + 0x7c) = param_2;
  }
  return 0;
}


// ==== FUN_00647d60 @ 0x00647d60 ====

void FUN_00647d60(byte param_1)

{
  void *in_ECX;
  
  FUN_00647d80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00647d80 @ 0x00647d80 ====

void FUN_00647d80(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098bd69;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4870;
  local_4 = 1;
  if (in_ECX[0x1d] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009d4720,
                         s_d__usa_24_0_1_2__develop_share_l_009d46b8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[0x1b] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009d47a0,
                         s_d__usa_24_0_1_2__develop_share_l_009d4738,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[0x1e];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009d4868;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x68,1,(_func_void_void_ptr *)&LAB_00647ac0);
    *in_ECX = &PTR_FUN_009d4850;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 100) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009d4820,
                         s_d__usa_24_0_1_2__develop_share_l_009d47b8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00659820();
  _free(_Memory);
  return;
}


// ==== FUN_00647eb0 @ 0x00647eb0 ====

void FUN_00647eb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00647a30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00647ed0 @ 0x00647ed0 ====

void FUN_00647ed0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d490c;
  return;
}


// ==== FUN_00647ee0 @ 0x00647ee0 ====

void FUN_00647ee0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d490c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00647f00 @ 0x00647f00 ====

int FUN_00647f00(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00647f10 @ 0x00647f10 ====

void FUN_00647f10(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bd88;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d491c;
  local_4 = 0;
  in_ECX[0xd] = &PTR_FUN_009a45a4;
  _eh_vector_destructor_iterator_(in_ECX + 0xe,0x30,0xc,FUN_006ef6d0);
  *in_ECX = &PTR_FUN_009d490c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00647f70 @ 0x00647f70 ====

void FUN_00647f70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bd9a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d491c;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  local_4 = 0;
  in_ECX[0xd] = &PTR_FUN_009a45a4;
  _eh_vector_constructor_iterator_(in_ECX + 0xe,0x30,0xc,FUN_005fd550,FUN_006ef6d0);
  in_ECX[0x9e] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00647fe0 @ 0x00647fe0 ====

void FUN_00647fe0(void)

{
  FUN_006480a0();
  return;
}


// ==== FUN_00647ff0 @ 0x00647ff0 ====

void FUN_00647ff0(int param_1)

{
  char cVar1;
  char *in_ECX;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0;
  pcVar3 = in_ECX;
  do {
    cVar1 = pcVar3[param_1 - (int)in_ECX];
    *pcVar3 = cVar1;
    if (cVar1 == '\0') goto LAB_00648018;
    uVar2 = uVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar2 < 0x28);
  *in_ECX = '\0';
LAB_00648018:
  *(undefined2 *)(in_ECX + 0x28) = *(undefined2 *)(param_1 + 0x28);
  *(undefined2 *)(in_ECX + 0x2a) = *(undefined2 *)(param_1 + 0x2a);
  *(undefined2 *)(in_ECX + 0x2c) = *(undefined2 *)(param_1 + 0x2c);
  *(undefined2 *)(in_ECX + 0x2e) = *(undefined2 *)(param_1 + 0x2e);
  return;
}


// ==== FUN_00648040 @ 0x00648040 ====

void FUN_00648040(byte param_1)

{
  void *in_ECX;
  
  FUN_00647f10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648060 @ 0x00648060 ====

void FUN_00648060(int param_1)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  
  iVar2 = in_ECX + 4;
  iVar1 = 0xc;
  do {
    FUN_00647ff0((param_1 - in_ECX) + iVar2);
    iVar2 = iVar2 + 0x30;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(in_ECX + 0x244) = *(undefined4 *)(param_1 + 0x244);
  return;
}


// ==== FUN_006480a0 @ 0x006480a0 ====

void FUN_006480a0(undefined2 *param_1)

{
  char cVar1;
  uint uVar2;
  undefined2 *in_ECX;
  
  *in_ECX = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 2);
    *(char *)(uVar2 + 2 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_006480c8;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x28);
  *(undefined1 *)(in_ECX + 1) = 0;
LAB_006480c8:
  in_ECX[0x15] = param_1[0x15];
  in_ECX[0x16] = param_1[0x16];
  FUN_00648060(param_1 + 0x18);
  return;
}


// ==== FUN_006480f0 @ 0x006480f0 ====

void FUN_006480f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d492c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648110 @ 0x00648110 ====

int FUN_00648110(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00648120 @ 0x00648120 ====

void FUN_00648120(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d492c;
  return;
}


// ==== FUN_00648130 @ 0x00648130 ====

void FUN_00648130(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d493c;
  *(undefined1 *)((int)in_ECX + 0xb) = 0;
  return;
}


// ==== FUN_00648140 @ 0x00648140 ====

void FUN_00648140(void)

{
  FUN_006481f0();
  return;
}


// ==== FUN_00648150 @ 0x00648150 ====

void FUN_00648150(byte param_1)

{
  void *in_ECX;
  
  FUN_00648120();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648170 @ 0x00648170 ====

void FUN_00648170(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d494c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648190 @ 0x00648190 ====

int FUN_00648190(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_006481a0 @ 0x006481a0 ====

void FUN_006481a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d494c;
  return;
}


// ==== FUN_006481b0 @ 0x006481b0 ====

void FUN_006481b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d495c;
  *(undefined1 *)((int)in_ECX + 0xb) = 0;
  return;
}


// ==== FUN_006481c0 @ 0x006481c0 ====

void FUN_006481c0(void)

{
  FUN_006481f0();
  return;
}


// ==== FUN_006481d0 @ 0x006481d0 ====

void FUN_006481d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006481a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006481f0 @ 0x006481f0 ====

void FUN_006481f0(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  *(undefined1 *)(in_ECX + 3) = *(undefined1 *)(param_1 + 3);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 7);
    *(char *)(uVar2 + 7 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)((int)in_ECX + 7) = 0;
  return;
}


// ==== FUN_00648240 @ 0x00648240 ====

void FUN_00648240(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d496c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648260 @ 0x00648260 ====

void FUN_00648260(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d496c;
  return;
}


// ==== FUN_00648270 @ 0x00648270 ====

int FUN_00648270(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00648280 @ 0x00648280 ====

void FUN_00648280(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  return;
}


// ==== FUN_00648290 @ 0x00648290 ====

void FUN_00648290(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d497c;
  return;
}


// ==== FUN_006482a0 @ 0x006482a0 ====

void FUN_006482a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00648260();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006482c0 @ 0x006482c0 ====

void FUN_006482c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d498c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006482e0 @ 0x006482e0 ====

void FUN_006482e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d498c;
  return;
}


// ==== FUN_006482f0 @ 0x006482f0 ====

int FUN_006482f0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00648300 @ 0x00648300 ====

void FUN_00648300(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  return;
}


// ==== FUN_00648320 @ 0x00648320 ====

void FUN_00648320(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d499c;
  return;
}


// ==== FUN_00648330 @ 0x00648330 ====

void FUN_00648330(byte param_1)

{
  void *in_ECX;
  
  FUN_006482e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648350 @ 0x00648350 ====

void FUN_00648350(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d49ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648370 @ 0x00648370 ====

void FUN_00648370(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d49ac;
  return;
}


// ==== FUN_00648380 @ 0x00648380 ====

int FUN_00648380(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00648390 @ 0x00648390 ====

void FUN_00648390(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  return;
}


// ==== FUN_006483b0 @ 0x006483b0 ====

void FUN_006483b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d49bc;
  return;
}


// ==== FUN_006483c0 @ 0x006483c0 ====

void FUN_006483c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00648370();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006483e0 @ 0x006483e0 ====

void FUN_006483e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d49cc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648400 @ 0x00648400 ====

void FUN_00648400(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d49cc;
  return;
}


// ==== FUN_00648410 @ 0x00648410 ====

int FUN_00648410(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00648420 @ 0x00648420 ====

void FUN_00648420(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  return;
}


// ==== FUN_00648440 @ 0x00648440 ====

void FUN_00648440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d49dc;
  return;
}


// ==== FUN_00648450 @ 0x00648450 ====

void FUN_00648450(byte param_1)

{
  void *in_ECX;
  
  FUN_00648400();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648470 @ 0x00648470 ====

void FUN_00648470(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d49ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648490 @ 0x00648490 ====

int FUN_00648490(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_006484a0 @ 0x006484a0 ====

void FUN_006484a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d49ec;
  return;
}


// ==== FUN_006484b0 @ 0x006484b0 ====

void FUN_006484b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d49fc;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  return;
}


// ==== FUN_006484c0 @ 0x006484c0 ====

void FUN_006484c0(void)

{
  FUN_006484f0();
  return;
}


// ==== FUN_006484d0 @ 0x006484d0 ====

void FUN_006484d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006484a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006484f0 @ 0x006484f0 ====

void FUN_006484f0(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 2);
    *(char *)(uVar2 + 2 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0064851b;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 1) = 0;
LAB_0064851b:
  in_ECX[0x81] = param_1[0x81];
  in_ECX[0x82] = param_1[0x82];
  in_ECX[0x83] = param_1[0x83];
  *(undefined1 *)(in_ECX + 0x84) = *(undefined1 *)(param_1 + 0x84);
  in_ECX[0x85] = param_1[0x85];
  in_ECX[0x86] = param_1[0x86];
  *(undefined1 *)(in_ECX + 0x87) = *(undefined1 *)(param_1 + 0x87);
  return;
}


// ==== FUN_00648580 @ 0x00648580 ====

void FUN_00648580(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a0c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006485a0 @ 0x006485a0 ====

void FUN_006485a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a0c;
  return;
}


// ==== FUN_006485b0 @ 0x006485b0 ====

int FUN_006485b0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_006485c0 @ 0x006485c0 ====

void FUN_006485c0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined2 *)(in_ECX + 8) = *(undefined2 *)(param_1 + 1);
  return;
}


// ==== FUN_006485e0 @ 0x006485e0 ====

void FUN_006485e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a1c;
  return;
}


// ==== FUN_006485f0 @ 0x006485f0 ====

void FUN_006485f0(byte param_1)

{
  void *in_ECX;
  
  FUN_006485a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648610 @ 0x00648610 ====

void FUN_00648610(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a2c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648630 @ 0x00648630 ====

int FUN_00648630(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00648640 @ 0x00648640 ====

void FUN_00648640(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a2c;
  return;
}


// ==== FUN_00648650 @ 0x00648650 ====

void FUN_00648650(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a3c;
  *(undefined1 *)(in_ECX + 2) = 0;
  return;
}


// ==== FUN_00648660 @ 0x00648660 ====

void FUN_00648660(undefined4 *param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 4);
    *(char *)(uVar2 + 8 + in_ECX) = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x400);
  *(undefined1 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00648690 @ 0x00648690 ====

void FUN_00648690(int param_1)

{
  char cVar1;
  char *in_ECX;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  pcVar2 = in_ECX;
  do {
    cVar1 = pcVar2[param_1 - (int)in_ECX];
    *pcVar2 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0x400);
  *in_ECX = '\0';
  return;
}


// ==== FUN_006486c0 @ 0x006486c0 ====

void FUN_006486c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00648640();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006486e0 @ 0x006486e0 ====

void FUN_006486e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648700 @ 0x00648700 ====

int FUN_00648700(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00648710 @ 0x00648710 ====

void FUN_00648710(void)

{
  undefined4 *in_ECX;
  
  in_ECX[3] = &PTR_FUN_009a48e8;
  *in_ECX = &PTR_FUN_009d4a4c;
  return;
}


// ==== FUN_00648720 @ 0x00648720 ====

void FUN_00648720(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a5c;
  in_ECX[3] = &PTR_FUN_009a48e8;
  in_ECX[0x28] = 0;
  return;
}


// ==== FUN_00648740 @ 0x00648740 ====

void FUN_00648740(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = *param_1;
  *(undefined2 *)(in_ECX + 6) = param_1[1];
  *(undefined1 *)(in_ECX + 8) = *(undefined1 *)(param_1 + 2);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 6);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 10);
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0xe);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0x12);
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(param_1 + 0x16);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(param_1 + 0x1a);
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x1e);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x22);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x26);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x28);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x2a);
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(param_1 + 0x2c);
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x2e);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x30);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x32);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(param_1 + 0x36);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(param_1 + 0x38);
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(param_1 + 0x3a);
  *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(param_1 + 0x3c);
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(param_1 + 0x3e);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(param_1 + 0x42);
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(in_ECX + 0x90) = *(undefined4 *)(param_1 + 0x46);
  *(undefined4 *)(in_ECX + 0x94) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(param_1 + 0x4a);
  *(undefined4 *)(in_ECX + 0x9c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0xa0) = *(undefined4 *)(param_1 + 0x4e);
  return;
}


// ==== FUN_00648890 @ 0x00648890 ====

void FUN_00648890(byte param_1)

{
  void *in_ECX;
  
  FUN_00648710();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006488b0 @ 0x006488b0 ====

void FUN_006488b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a6c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006488d0 @ 0x006488d0 ====

void FUN_006488d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a6c;
  return;
}


// ==== FUN_006488e0 @ 0x006488e0 ====

int FUN_006488e0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_006488f0 @ 0x006488f0 ====

void FUN_006488f0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  return;
}


// ==== FUN_00648910 @ 0x00648910 ====

void FUN_00648910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a7c;
  return;
}


// ==== FUN_00648920 @ 0x00648920 ====

void FUN_00648920(byte param_1)

{
  void *in_ECX;
  
  FUN_006488d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648940 @ 0x00648940 ====

void FUN_00648940(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648960 @ 0x00648960 ====

void FUN_00648960(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a8c;
  return;
}


// ==== FUN_00648970 @ 0x00648970 ====

int FUN_00648970(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00648980 @ 0x00648980 ====

void FUN_00648980(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  return;
}


// ==== FUN_006489a0 @ 0x006489a0 ====

void FUN_006489a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4a9c;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_006489c0 @ 0x006489c0 ====

void FUN_006489c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00648960();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006489e0 @ 0x006489e0 ====

void FUN_006489e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4aac;
  return;
}


// ==== FUN_006489f0 @ 0x006489f0 ====

void FUN_006489f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4aac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648a10 @ 0x00648a10 ====

void FUN_00648a10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4aac;
  return;
}


// ==== FUN_00648a20 @ 0x00648a20 ====

bool FUN_00648a20(char *param_1)

{
  return *param_1 == '\0';
}


// ==== FUN_00648a30 @ 0x00648a30 ====

int FUN_00648a30(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00648a40 @ 0x00648a40 ====

void FUN_00648a40(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  return;
}


// ==== FUN_00648a60 @ 0x00648a60 ====

undefined1 FUN_00648a60(void)

{
  return 0;
}


// ==== FUN_00648a70 @ 0x00648a70 ====

undefined4 FUN_00648a70(void)

{
  return 0;
}


// ==== FUN_00648a80 @ 0x00648a80 ====

undefined1 FUN_00648a80(void)

{
  return 0;
}


// ==== FUN_00648a90 @ 0x00648a90 ====

void FUN_00648a90(undefined4 *param_1)

{
  undefined4 local_8;
  undefined2 local_4;
  
  FUN_00797a50(&local_8,0,6);
  *param_1 = local_8;
  *(undefined2 *)(param_1 + 1) = local_4;
  return;
}


// ==== FUN_00648ad0 @ 0x00648ad0 ====

void FUN_00648ad0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bdb8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4ad0;
  FUN_00797a50(in_ECX + 1,0,8);
  *(undefined1 *)(in_ECX + 1) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00648b30 @ 0x00648b30 ====

undefined1 FUN_00648b30(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_00648b40 @ 0x00648b40 ====

void FUN_00648b40(byte param_1)

{
  void *in_ECX;
  
  FUN_00648a10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648b60 @ 0x00648b60 ====

void FUN_00648b60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4aac;
  return;
}


// ==== FUN_00648b70 @ 0x00648b70 ====

bool FUN_00648b70(char *param_1)

{
  return *param_1 == '\x02';
}


// ==== FUN_00648b80 @ 0x00648b80 ====

int FUN_00648b80(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00648b90 @ 0x00648b90 ====

void FUN_00648b90(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  return;
}


// ==== FUN_00648bb0 @ 0x00648bb0 ====

undefined1 FUN_00648bb0(void)

{
  return 0;
}


// ==== FUN_00648bc0 @ 0x00648bc0 ====

undefined4 FUN_00648bc0(void)

{
  return 0;
}


// ==== FUN_00648bd0 @ 0x00648bd0 ====

undefined1 FUN_00648bd0(void)

{
  return 1;
}


// ==== FUN_00648bf0 @ 0x00648bf0 ====

void FUN_00648bf0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bdd8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4af4;
  FUN_00797a50(in_ECX + 1,0,8);
  *(undefined1 *)(in_ECX + 1) = 2;
  *(undefined2 *)((int)in_ECX + 6) = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00648c50 @ 0x00648c50 ====

undefined1 FUN_00648c50(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_00648c60 @ 0x00648c60 ====

void FUN_00648c60(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 6);
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(in_ECX + 10);
  return;
}


// ==== FUN_00648c80 @ 0x00648c80 ====

void FUN_00648c80(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 6) = *param_1;
  *(undefined2 *)(in_ECX + 10) = *(undefined2 *)(param_1 + 1);
  return;
}


// ==== FUN_00648ca0 @ 0x00648ca0 ====

void FUN_00648ca0(byte param_1)

{
  void *in_ECX;
  
  FUN_00648b60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648cc0 @ 0x00648cc0 ====

void FUN_00648cc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4aac;
  return;
}


// ==== FUN_00648cd0 @ 0x00648cd0 ====

bool FUN_00648cd0(char *param_1)

{
  return *param_1 == '\x01';
}


// ==== FUN_00648ce0 @ 0x00648ce0 ====

int FUN_00648ce0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00648cf0 @ 0x00648cf0 ====

void FUN_00648cf0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  return;
}


// ==== FUN_00648d10 @ 0x00648d10 ====

undefined1 FUN_00648d10(void)

{
  return 1;
}


// ==== FUN_00648d20 @ 0x00648d20 ====

undefined1 FUN_00648d20(void)

{
  return 0;
}


// ==== FUN_00648d30 @ 0x00648d30 ====

void FUN_00648d30(undefined4 *param_1)

{
  undefined4 local_8;
  undefined2 local_4;
  
  FUN_00797a50(&local_8,0,6);
  *param_1 = local_8;
  *(undefined2 *)(param_1 + 1) = local_4;
  return;
}


// ==== FUN_00648d70 @ 0x00648d70 ====

void FUN_00648d70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bdf8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4b18;
  FUN_00797a50(in_ECX + 1,0,8);
  *(undefined1 *)(in_ECX + 1) = 1;
  in_ECX[2] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00648dd0 @ 0x00648dd0 ====

undefined1 FUN_00648dd0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_00648de0 @ 0x00648de0 ====

undefined4 FUN_00648de0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00648df0 @ 0x00648df0 ====

void FUN_00648df0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00648e00 @ 0x00648e00 ====

void FUN_00648e00(byte param_1)

{
  void *in_ECX;
  
  FUN_00648cc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648e20 @ 0x00648e20 ====

void FUN_00648e20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b44;
  return;
}


// ==== FUN_00648e30 @ 0x00648e30 ====

void FUN_00648e30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648e50 @ 0x00648e50 ====

void FUN_00648e50(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00648e60 @ 0x00648e60 ====

undefined4 FUN_00648e60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00648e70 @ 0x00648e70 ====

void FUN_00648e70(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00648e75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_00648e80 @ 0x00648e80 ====

void FUN_00648e80(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00648e85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_00648e90 @ 0x00648e90 ====

void FUN_00648e90(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00648e95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_00648ea0 @ 0x00648ea0 ====

void FUN_00648ea0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b44;
  return;
}


// ==== FUN_00648eb0 @ 0x00648eb0 ====

void FUN_00648eb0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_00648ec0 @ 0x00648ec0 ====

int FUN_00648ec0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))(param_1,param_2);
  if (piVar1 == (int *)0x0) {
    return in_ECX + 8;
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  return iVar2;
}


// ==== FUN_00648ef0 @ 0x00648ef0 ====

void FUN_00648ef0(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  undefined4 *in_ECX;
  uint uVar4;
  char local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098be1b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4b60;
  pcVar1 = (char *)(in_ECX + 2);
  local_4 = 0;
  *pcVar1 = '\0';
  FUN_0044a580(local_10c,&DAT_009d4b3c,&DAT_009d4b39);
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[(int)(local_10c + -(int)pcVar1)];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') {
      ExceptionList = local_c;
      return;
    }
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x100);
  *pcVar1 = '\0';
  ExceptionList = local_c;
  return;
}


// ==== FUN_00648f90 @ 0x00648f90 ====

void FUN_00648f90(byte param_1)

{
  void *in_ECX;
  
  FUN_00648ea0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648fb0 @ 0x00648fb0 ====

void FUN_00648fb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_00648fc0 @ 0x00648fc0 ====

void FUN_00648fc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00648fe0 @ 0x00648fe0 ====

undefined4 FUN_00648fe0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x504);
}


// ==== FUN_00648ff0 @ 0x00648ff0 ====

undefined4 FUN_00648ff0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x50c);
}


// ==== FUN_00649000 @ 0x00649000 ====

void FUN_00649000(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_00649090 @ 0x00649090 ====

void FUN_00649090(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  return;
}


// ==== FUN_00649130 @ 0x00649130 ====

undefined1 FUN_00649130(void)

{
  return 0;
}


// ==== FUN_00649140 @ 0x00649140 ====

undefined1 FUN_00649140(void)

{
  return 0;
}


// ==== FUN_006491d0 @ 0x006491d0 ====

void FUN_006491d0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098be38;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4bcc;
  in_ECX[0x141] = param_1;
  in_ECX[0x142] = 0;
  in_ECX[0x143] = 0;
  FUN_00797a50(in_ECX + 0x144,0,9);
  FUN_00797a50(in_ECX + 1,0,0x280);
  FUN_00797a50(in_ECX + 0xa1,0,0x280);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00649270 @ 0x00649270 ====

void FUN_00649270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_00649280 @ 0x00649280 ====

void FUN_00649280(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x510) = 1;
  return;
}


// ==== FUN_00649290 @ 0x00649290 ====

void FUN_00649290(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x511) = 1;
  return;
}


// ==== FUN_006492a0 @ 0x006492a0 ====

void FUN_006492a0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x512) = 1;
  return;
}


// ==== FUN_006492b0 @ 0x006492b0 ====

void FUN_006492b0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x513) = 1;
  return;
}


// ==== FUN_006492c0 @ 0x006492c0 ====

void FUN_006492c0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x514) = 1;
  return;
}


// ==== FUN_006492d0 @ 0x006492d0 ====

void FUN_006492d0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x515) = 1;
  return;
}


// ==== FUN_006492e0 @ 0x006492e0 ====

void FUN_006492e0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x516) = 1;
  return;
}


// ==== FUN_006492f0 @ 0x006492f0 ====

void FUN_006492f0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x517) = 1;
  return;
}


// ==== FUN_00649310 @ 0x00649310 ====

void FUN_00649310(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = 0;
  FUN_00797a50(in_ECX + 0x510,0,9);
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  return;
}


// ==== FUN_00649360 @ 0x00649360 ====

void FUN_00649360(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_006493b0 @ 0x006493b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006493b0(void)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  float fVar6;
  float fStack_10;
  
  (**(code **)(*DAT_00b5a6b8 + 4))();
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x504) + 0x20))();
  iVar4 = (**(code **)(*piVar3 + 4))();
  fVar1 = (float)(*(int *)(in_ECX + 0x2a4) + *(int *)(iVar4 + 0x28));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x74))();
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x78))();
  uVar5 = (uint)*(ushort *)(iVar4 + 0x2c);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x7c))((float)uVar5 * (float)*(int *)(in_ECX + 0x2ac));
  fVar2 = (float)*(int *)(in_ECX + 0x2b4);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x84))(fVar2);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x88))(0);
  piVar3 = (int *)(**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x44) + 0x14))();
  iVar4 = (**(code **)(*piVar3 + 0xc))();
  if (*(float *)(iVar4 + 4) <= 0.0) {
    *(uint *)(in_ECX + 0x50c) = uVar5;
    return;
  }
  fVar6 = 0.0;
  if (*(int *)(in_ECX + 0x50c) + 500U < uVar5) {
    iVar4 = uVar5 - *(int *)(in_ECX + 0x50c);
    fVar6 = (float)iVar4;
    if (iVar4 < 0) {
      fVar6 = fVar6 + _DAT_0099d104;
    }
    fVar6 = fVar6 * DAT_0099d0ec;
    *(uint *)(in_ECX + 0x50c) = uVar5;
  }
  iVar4 = (**(code **)(*piVar3 + 0xc))();
  fStack_10 = (0.0 - fVar1) * fVar6 + *(float *)(iVar4 + 4);
  if (fVar2 < fStack_10) {
    fStack_10 = fVar2;
  }
  if (fStack_10 <= DAT_0099d080) {
    fStack_10 = DAT_0099d080;
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x6c))(fStack_10);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x70))(0);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x8c))(0);
  (**(code **)(*piVar3 + 0x14))(fStack_10);
  (**(code **)(*piVar3 + 0x20))(0);
  (**(code **)(*piVar3 + 0x1c))(fVar1);
  (**(code **)(*piVar3 + 0x28))(0);
  (**(code **)(*piVar3 + 0x2c))(0);
  (**(code **)(*piVar3 + 0x34))(0);
  return;
}


// ==== FUN_00649690 @ 0x00649690 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00649690(void)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  byte bVar8;
  int in_ECX;
  byte bVar9;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  float fVar10;
  float fVar11;
  uint uStack_114;
  uint uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  int iStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  float fStack_e0;
  undefined4 uStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  uint uStack_c4;
  float fStack_c0;
  undefined4 uStack_bc;
  float fStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined1 uStack_a8;
  undefined3 uStack_a7;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  byte bStack_84;
  undefined3 uStack_83;
  int iStack_80;
  byte bStack_7c;
  undefined3 uStack_7b;
  undefined1 *puStack_78;
  byte bStack_74;
  undefined3 uStack_73;
  uint *puStack_70;
  int iStack_6c;
  int iStack_68;
  undefined1 *puStack_64;
  undefined1 *puStack_60;
  uint *puStack_5c;
  uint *puStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_38 [4];
  undefined1 auStack_34 [8];
  int iStack_2c;
  int iStack_28;
  uint uStack_24;
  uint uStack_20;
  int iStack_1c;
  int iStack_18;
  
  uStack_4c = 0x6496a4;
  iVar3 = (**(code **)(*DAT_00b5a6b8 + 4))();
  uStack_4c = 0x6496b1;
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 0x504) + 0x20))();
  uStack_4c = 0x6496b8;
  iVar5 = (**(code **)(*piVar4 + 4))();
  uStack_4c = CONCAT22(extraout_var,*(undefined2 *)(iVar5 + 0x24));
  uStack_50 = 0x6496ca;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x54))();
  uStack_50 = 0;
  uStack_54 = 0x6496d7;
  uVar6 = (**(code **)(**(int **)(in_ECX + 0x508) + 0x58))();
  uStack_54 = CONCAT31((int3)((uint)uVar6 >> 8),*(undefined1 *)(iVar5 + 0x104));
  puStack_58 = (uint *)0x6496ec;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xbc))();
  fVar11 = (float)(*(int *)(in_ECX + 0x30c) + 100);
  fVar10 = ((float)*(ushort *)(iVar5 + 0xfc) + (float)*(int *)(in_ECX + 0x304)) * fVar11 *
           DAT_009a09b8 * *(float *)(iVar3 + 0x10);
  fVar11 = ((float)*(ushort *)(iVar5 + 0xfe) + (float)*(int *)(in_ECX + 0x308)) * fVar11 *
           DAT_009a09b8 * *(float *)(iVar3 + 0x10);
  if (fVar10 < 0.0) {
    fVar10 = 0.0;
  }
  if (fVar11 < 0.0) {
    fVar11 = 0.0;
  }
  iStack_1c = (int)fVar10;
  iStack_18 = iStack_1c;
  if (iStack_1c <= (int)fVar11) {
    iStack_18 = (int)fVar11;
  }
  fVar11 = (float)(*(int *)(in_ECX + 0x30c) + 100);
  fVar10 = ((float)*(ushort *)(iVar5 + 0x198) + (float)*(int *)(in_ECX + 0x304)) * fVar11 *
           DAT_009a09b8 * *(float *)(iVar3 + 0x10);
  fVar11 = ((float)*(ushort *)(iVar5 + 0x19a) + (float)*(int *)(in_ECX + 0x308)) * fVar11 *
           DAT_009a09b8 * *(float *)(iVar3 + 0x10);
  if (fVar10 < 0.0) {
    fVar10 = 0.0;
  }
  if (fVar11 < 0.0) {
    fVar11 = 0.0;
  }
  iStack_2c = (int)fVar10;
  iStack_28 = iStack_2c;
  if (iStack_2c <= (int)fVar11) {
    iStack_28 = (int)fVar11;
  }
  uStack_24 = (uint)*(ushort *)(iVar5 + 0x100);
  uStack_20 = uStack_24;
  if (uStack_24 <= *(ushort *)(iVar5 + 0x102)) {
    uStack_20 = (uint)*(ushort *)(iVar5 + 0x102);
  }
  puStack_58 = &uStack_24;
  puStack_5c = (uint *)0x649812;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd8))();
  puStack_5c = &uStack_20;
  puStack_60 = (undefined1 *)0x649825;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x9c))();
  puStack_60 = auStack_34;
  puStack_64 = (undefined1 *)0x649838;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xa0))();
  puStack_64 = auStack_38;
  iStack_68 = 0x64984b;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xa4))();
  fVar10 = (float)(*(int *)(in_ECX + 0x3ac) + 100);
  iStack_68 = (int)(((float)*(ushort *)(iVar5 + 0x30) + (float)*(int *)(in_ECX + 0x3a8)) * fVar10 *
                    DAT_009a09b8 * *(float *)(iVar3 + 0x18));
  iStack_6c = (int)(((float)*(ushort *)(iVar5 + 0x2e) + (float)*(int *)(in_ECX + 0x3a4)) * fVar10 *
                    DAT_009a09b8 * *(float *)(iVar3 + 0x18));
  puStack_70 = (uint *)0x6498ba;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc0))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x36) + *(int *)(in_ECX + 0x2e4) + *(int *)(in_ECX + 0x300);
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_006498d4:
    bVar1 = (byte)iVar3;
    if (0x4b < bVar1) goto LAB_006498d8;
    puStack_5c = (uint *)CONCAT31(puStack_5c._1_3_,100);
    if (bVar1 < 0x65) goto LAB_006498e5;
  }
  else {
    if ((byte)iVar3 < 0x65) goto LAB_006498d4;
LAB_006498d8:
    bVar1 = 0x4b;
LAB_006498e5:
    puStack_5c = (uint *)CONCAT31(puStack_5c._1_3_,bVar1);
  }
  puStack_70 = puStack_5c;
  bStack_74 = 0;
  uStack_73 = 0;
  puStack_78 = (undefined1 *)0x6498fe;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x37) + *(int *)(in_ECX + 0x2e8) + *(int *)(in_ECX + 0x300);
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_00649918:
    bVar1 = (byte)iVar3;
    if (0x4b < bVar1) goto LAB_0064991c;
    puStack_64 = (undefined1 *)CONCAT31(puStack_64._1_3_,100);
    if (bVar1 < 0x65) goto LAB_00649929;
  }
  else {
    if ((byte)iVar3 < 0x65) goto LAB_00649918;
LAB_0064991c:
    bVar1 = 0x4b;
LAB_00649929:
    puStack_64 = (undefined1 *)CONCAT31(puStack_64._1_3_,bVar1);
  }
  puStack_78 = puStack_64;
  bStack_7c = 1;
  uStack_7b = 0;
  iStack_80 = 0x649942;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x38) + *(int *)(in_ECX + 0x2ec) + *(int *)(in_ECX + 0x300);
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_0064995c:
    bVar1 = (byte)iVar3;
    if (0x4b < bVar1) goto LAB_00649960;
    iStack_6c = CONCAT31(iStack_6c._1_3_,100);
    if (bVar1 < 0x65) goto LAB_0064996d;
  }
  else {
    if ((byte)iVar3 < 0x65) goto LAB_0064995c;
LAB_00649960:
    bVar1 = 0x4b;
LAB_0064996d:
    iStack_6c = CONCAT31(iStack_6c._1_3_,bVar1);
  }
  iStack_80 = iStack_6c;
  bStack_84 = 2;
  uStack_83 = 0;
  uStack_88 = 0x649986;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x39) + *(int *)(in_ECX + 0x2f0) + *(int *)(in_ECX + 0x300);
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_006499a0:
    bVar1 = (byte)iVar3;
    if (0x4b < bVar1) goto LAB_006499a4;
    bStack_74 = 100;
    if (bVar1 < 0x65) goto LAB_006499b1;
  }
  else {
    if ((byte)iVar3 < 0x65) goto LAB_006499a0;
LAB_006499a4:
    bVar1 = 0x4b;
LAB_006499b1:
    bStack_74 = bVar1;
  }
  uStack_88._0_1_ = bStack_74;
  uStack_88._1_3_ = uStack_73;
  uStack_8c = 3;
  uStack_90 = 0x6499ca;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x3a) + *(int *)(in_ECX + 0x2f4) + *(int *)(in_ECX + 0x300);
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_006499e4:
    bVar1 = (byte)iVar3;
    if (0x4b < bVar1) goto LAB_006499e8;
    bStack_7c = 100;
    if (bVar1 < 0x65) goto LAB_006499f5;
  }
  else {
    if ((byte)iVar3 < 0x65) goto LAB_006499e4;
LAB_006499e8:
    bVar1 = 0x4b;
LAB_006499f5:
    bStack_7c = bVar1;
  }
  uStack_90._0_1_ = bStack_7c;
  uStack_90._1_3_ = uStack_7b;
  uStack_94 = 4;
  uStack_98 = 0x649a0e;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x35) + *(int *)(in_ECX + 0x2f8);
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_00649a22:
    bVar1 = (byte)iVar3;
    if (0x4b < bVar1) goto LAB_00649a26;
    bStack_84 = 100;
    if (bVar1 < 0x65) goto LAB_00649a33;
  }
  else {
    if ((byte)iVar3 < 0x65) goto LAB_00649a22;
LAB_00649a26:
    bVar1 = 0x4b;
LAB_00649a33:
    bStack_84 = bVar1;
  }
  uStack_98._0_1_ = bStack_84;
  uStack_98._1_3_ = uStack_83;
  uStack_9c = 5;
  uStack_a0 = 0x649a4c;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  uStack_a0._0_1_ = 0;
  uStack_a0._1_3_ = 0;
  uStack_a4 = 0x649a5c;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x104))();
  iVar3 = *(int *)(in_ECX + 0x364);
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_00649a73:
    uStack_90._0_1_ = (byte)iVar3;
  }
  else {
    uStack_90._0_1_ = 0xfa;
    if ((byte)iVar3 < 0xfb) goto LAB_00649a73;
  }
  uStack_a4._0_1_ = (byte)uStack_90;
  uStack_a4._1_3_ = uStack_90._1_3_;
  uStack_a8 = 0;
  uStack_a7 = 0;
  uStack_ac = 0x649a8c;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar3 = *(int *)(in_ECX + 0x368);
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_00649aa3:
    uStack_98._0_1_ = (byte)iVar3;
  }
  else {
    uStack_98._0_1_ = 0xfa;
    if ((byte)iVar3 < 0xfb) goto LAB_00649aa3;
  }
  uStack_ac._0_1_ = (byte)uStack_98;
  uStack_ac._1_3_ = uStack_98._1_3_;
  uStack_b0._0_1_ = 1;
  uStack_b0._1_3_ = 0;
  uStack_b4 = 0x649abc;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar3 = *(int *)(in_ECX + 0x36c);
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_00649ad3:
    uStack_a0._0_1_ = (undefined1)iVar3;
  }
  else {
    uStack_a0._0_1_ = 0xfa;
    if ((byte)iVar3 < 0xfb) goto LAB_00649ad3;
  }
  uStack_b4._0_1_ = (undefined1)uStack_a0;
  uStack_b4._1_3_ = uStack_a0._1_3_;
  fStack_b8 = 2.8026e-45;
  uStack_bc = 0x649aec;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar3 = *(int *)(in_ECX + 0x370);
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_00649b03:
    uStack_a8 = (undefined1)iVar3;
  }
  else {
    uStack_a8 = 0xfa;
    if ((byte)iVar3 < 0xfb) goto LAB_00649b03;
  }
  uStack_bc._0_1_ = uStack_a8;
  uStack_bc._1_3_ = uStack_a7;
  fStack_c0 = 4.2039e-45;
  uStack_c4 = 0x649b1c;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar3 = *(int *)(in_ECX + 0x374);
  if (iVar3 < 0) {
    iVar3 = 0;
LAB_00649b33:
    uStack_b0._0_1_ = (undefined1)iVar3;
  }
  else {
    uStack_b0._0_1_ = 0xfa;
    if ((byte)iVar3 < 0xfb) goto LAB_00649b33;
  }
  uStack_c4._0_1_ = (undefined1)uStack_b0;
  uStack_c4._1_3_ = uStack_b0._1_3_;
  uStack_c8 = 4;
  uStack_cc = 0x649b4c;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  uStack_cc = 100;
  uStack_d0 = 100;
  uStack_d4 = 0x649b5e;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xcc))();
  uStack_d4 = 0x96;
  fStack_d8 = 9.239311e-39;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd4))();
  iVar3 = *(int *)(in_ECX + 0x324) + 100;
  if (iVar3 < 200) {
    if (-1 < iVar3) goto LAB_00649b86;
    bVar1 = 0;
LAB_00649b8c:
    bVar9 = bVar1;
  }
  else {
    iVar3 = 200;
LAB_00649b86:
    bVar1 = (byte)iVar3;
    bVar9 = 200;
    if (bVar1 < 0xc9) goto LAB_00649b8c;
  }
  iVar3 = *(int *)(in_ECX + 0x330) + 100;
  uStack_bc = CONCAT31(uStack_bc._1_3_,bVar9);
  if (iVar3 < 200) {
    if (-1 < iVar3) goto LAB_00649ba7;
    bVar1 = 0;
LAB_00649bad:
    bVar8 = bVar1;
  }
  else {
    iVar3 = 200;
LAB_00649ba7:
    bVar1 = (byte)iVar3;
    bVar8 = 200;
    if (bVar1 < 0xc9) goto LAB_00649bad;
  }
  uStack_b4 = CONCAT31(uStack_b4._1_3_,bVar8);
  if (bVar9 < 100) {
    fVar10 = DAT_0099d0f8 - (float)bVar9 * DAT_009a09b8;
  }
  else {
    fVar10 = DAT_0099d080 - ((float)bVar9 - DAT_0099de78) * _DAT_009b832c;
  }
  if (fVar10 <= DAT_0099d0f8) {
    fStack_c0 = DAT_009b8328;
    if (DAT_009b8328 <= fVar10) goto LAB_00649c38;
  }
  else {
    fVar10 = DAT_0099d0f8;
LAB_00649c38:
    fStack_c0 = fVar10;
  }
  uStack_b0 = *(undefined4 *)(iVar5 + 0x40);
  if (bVar8 < 100) {
    fVar10 = (float)bVar8 * _DAT_009b836c + DAT_009a09b8;
  }
  else {
    fVar10 = ((float)bVar8 - DAT_0099de78) * _DAT_009b836c + DAT_0099d080;
  }
  if (fVar10 <= DAT_009b8368) {
    fStack_b8 = DAT_009a09b8;
    if (fVar10 < DAT_009a09b8) goto LAB_00649c96;
  }
  else {
    fVar10 = DAT_009b8368;
  }
  fStack_b8 = fVar10;
LAB_00649c96:
  fStack_d8 = fStack_c0;
  uStack_dc = uStack_bc;
  fStack_e0 = 9.239756e-39;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xe0))();
  fStack_e0 = fStack_c0 * fStack_b8;
  uStack_e4 = uStack_bc;
  uStack_e8 = 0x649cd3;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xe8))();
  uStack_e8 = 0x3f800000;
  uStack_ec = 0x649ce6;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xe4))();
  uVar2 = *(ushort *)(in_ECX + 0x344);
  if ((int)(9999 - (uint)uVar2) < 1) {
    uVar2 = 9999;
  }
  else {
    uVar2 = (-1 < (int)-(uint)uVar2) - 1 & uVar2;
  }
  uStack_ec = 0x649d1e;
  (**(code **)(*DAT_00b5a6b8 + 4))();
  uStack_c4 = (uint)uVar2;
  uStack_ec = 0x649d31;
  uVar2 = FUN_00802534();
  uStack_c8 = CONCAT22(uStack_c8._2_2_,9999);
  if (uVar2 < 10000) {
    uStack_c8 = CONCAT22(uStack_c8._2_2_,uVar2);
  }
  uStack_ec = uStack_c8;
  iStack_f0 = 0x649d56;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xec))();
  bVar1 = 100;
  if (*(byte *)(iVar5 + 0x34) < 0x65) {
    bVar1 = *(byte *)(iVar5 + 0x34);
  }
  bVar9 = *(byte *)(in_ECX + 0x34c);
  if ((int)(uint)bVar1 < (int)(100 - (uint)bVar9)) {
    if ((int)-(uint)bVar9 < (int)(uint)bVar1) {
      fStack_d8 = (float)CONCAT31(fStack_d8._1_3_,bVar1 + bVar9);
    }
    else {
      fStack_d8 = (float)((uint)fStack_d8._1_3_ << 8);
    }
  }
  else {
    fStack_d8 = (float)CONCAT31(fStack_d8._1_3_,100);
  }
  iStack_f0 = (int)fStack_d8;
  uStack_f4 = 0x649da5;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xfc))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x32) + *(int *)(in_ECX + 0x350);
  uStack_f4._0_1_ = *(undefined1 *)(iVar5 + 0x33);
  uStack_f4._1_3_ = (undefined3)((uint)iVar3 >> 8);
  uStack_cc = CONCAT31(uStack_cc._1_3_,(iVar3 < 0) - 1U & (byte)iVar3);
  uStack_f8 = uStack_cc;
  uStack_fc = 0x649dd2;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x100))();
  bVar1 = *(byte *)(in_ECX + 0x348);
  uStack_d4 = CONCAT31(uStack_d4._1_3_,bVar1);
  if ((int)(100 - (uint)bVar1) < 1) {
    uStack_e4 = CONCAT31(uStack_e4._1_3_,100);
  }
  else {
    uStack_e4 = CONCAT31(uStack_e4._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  uVar6 = uStack_e4;
  uStack_fc = uStack_e4;
  uStack_100 = 0x649e14;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf0))();
  uStack_100 = uVar6;
  uStack_104 = 0x649e23;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf4))();
  uStack_104 = uVar6;
  uStack_108 = 0x649e32;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf8))();
  bVar1 = *(byte *)(in_ECX + 900);
  fStack_e0 = (float)CONCAT31(fStack_e0._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_f4 = CONCAT31(uStack_f4._1_3_,0xfa);
  }
  else {
    uStack_f4 = CONCAT31(uStack_f4._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  uStack_108 = uStack_f4;
  uStack_10c = 0;
  uStack_110 = 0x649e76;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))();
  bVar1 = *(byte *)(in_ECX + 0x388);
  uStack_e8 = CONCAT31(uStack_e8._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_fc = CONCAT31(uStack_fc._1_3_,0xfa);
  }
  else {
    uStack_fc = CONCAT31(uStack_fc._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  uStack_110 = uStack_fc;
  uStack_114 = 1;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))();
  bVar1 = *(byte *)(in_ECX + 0x38c);
  iStack_f0 = CONCAT31(iStack_f0._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_104 = CONCAT31(uStack_104._1_3_,0xfa);
  }
  else {
    uStack_104 = CONCAT31(uStack_104._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(2,uStack_104);
  bVar1 = *(byte *)(in_ECX + 0x390);
  uStack_f8 = CONCAT31(uStack_f8._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_10c = CONCAT31(uStack_10c._1_3_,0xfa);
  }
  else {
    uStack_10c = CONCAT31(uStack_10c._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(3,uStack_10c);
  bVar1 = *(byte *)(in_ECX + 0x394);
  uStack_100 = CONCAT31(uStack_100._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_114 = CONCAT31(uStack_114._1_3_,0xfa);
  }
  else {
    uStack_114 = CONCAT31(uStack_114._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(4,uStack_114);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(0,*(undefined4 *)(in_ECX + 0x3e4));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(1,*(undefined4 *)(in_ECX + 1000));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(2,*(undefined4 *)(in_ECX + 0x3ec));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(3,*(undefined4 *)(in_ECX + 0x3f0));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(4,*(undefined4 *)(in_ECX + 0x3f4));
  uStack_114 = (uint)*(ushort *)(iVar5 + 0x100);
  uStack_110 = uStack_114;
  if (uStack_114 <= *(ushort *)(iVar5 + 0x102)) {
    uStack_110 = (uint)*(ushort *)(iVar5 + 0x102);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd8))(&uStack_114);
  iVar7 = (uint)*(byte *)(iVar5 + 0xf4) + *(int *)(in_ECX + 0x3b0);
  iVar3 = (uint)*(byte *)(iVar5 + 0xf5) + *(int *)(in_ECX + 0x3b0);
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  else if (99 < iVar7) {
    iVar7 = 100;
  }
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  else if (99 < iVar3) {
    iVar3 = 100;
  }
  if (iVar3 <= iVar7) {
    iVar3 = iVar7 + 1;
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xdc))(iVar7,iVar3);
  piVar4 = (int *)(**(code **)(*DAT_00b5abc4 + 8))
                            (CONCAT22(extraout_var_00,*(undefined2 *)(iVar5 + 0x1c)));
  if (piVar4 == (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x508) + 0x128))(1);
    (**(code **)(**(int **)(in_ECX + 0x508) + 300))(0x3f800000);
    return;
  }
  iVar3 = **(int **)(in_ECX + 0x508);
  iVar5 = (**(code **)(*piVar4 + 4))();
  (**(code **)(iVar3 + 0x128))(*(undefined4 *)(iVar5 + 4));
  iVar3 = **(int **)(in_ECX + 0x508);
  iVar5 = (**(code **)(*piVar4 + 4))();
  (**(code **)(iVar3 + 300))(*(undefined4 *)(iVar5 + 8));
  return;
}


// ==== FUN_0064a110 @ 0x0064a110 ====

/* WARNING: Removing unreachable block (ram,0x0064a11e) */

void FUN_0064a110(undefined4 param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(char *)(in_ECX + 0x512) == '\x01') {
    (**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x10) + 0x30))((undefined4 *)(in_ECX + 4));
    puVar2 = (undefined4 *)(in_ECX + 4);
    puVar3 = (undefined4 *)(in_ECX + 0x284);
    for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_00649690(param_1);
  }
  FUN_006493b0(param_1);
  FUN_00797a50(in_ECX + 0x510,0,9);
  return;
}


// ==== FUN_0064a180 @ 0x0064a180 ====

void FUN_0064a180(void)

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
  FUN_00649690(unaff_retaddr);
  FUN_006493b0(unaff_retaddr);
  *(undefined4 *)(in_ECX + 0x50c) = unaff_retaddr;
  FUN_00797a50(in_ECX + 0x510,0,9);
  return;
}


// ==== FUN_0064a1e0 @ 0x0064a1e0 ====

void FUN_0064a1e0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  FUN_00797a50(in_ECX + 0x510,0,9);
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  uVar1 = FUN_006179e0();
  *(undefined4 *)(in_ECX + 0x508) = uVar1;
  FUN_0064a180(param_1);
  return;
}


// ==== FUN_0064a250 @ 0x0064a250 ====

void FUN_0064a250(byte param_1)

{
  void *in_ECX;
  
  FUN_00649270();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0064a270 @ 0x0064a270 ====

undefined4 FUN_0064a270(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x504);
}


// ==== FUN_0064a280 @ 0x0064a280 ====

undefined4 FUN_0064a280(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x50c);
}


// ==== FUN_0064a290 @ 0x0064a290 ====

void FUN_0064a290(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_0064a2a0 @ 0x0064a2a0 ====

undefined1 FUN_0064a2a0(void)

{
  return 0;
}


// ==== FUN_0064a2b0 @ 0x0064a2b0 ====

undefined1 FUN_0064a2b0(void)

{
  return 0;
}


// ==== FUN_0064a330 @ 0x0064a330 ====

void FUN_0064a330(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098be58;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4c1c;
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


// ==== FUN_0064a3c0 @ 0x0064a3c0 ====

void FUN_0064a3c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_0064a3d0 @ 0x0064a3d0 ====

void FUN_0064a3d0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x510) = 1;
  return;
}


// ==== FUN_0064a3e0 @ 0x0064a3e0 ====

void FUN_0064a3e0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x511) = 1;
  return;
}


// ==== FUN_0064a3f0 @ 0x0064a3f0 ====

void FUN_0064a3f0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x512) = 1;
  return;
}


// ==== FUN_0064a400 @ 0x0064a400 ====

void FUN_0064a400(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x513) = 1;
  return;
}


// ==== FUN_0064a410 @ 0x0064a410 ====

void FUN_0064a410(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x514) = 1;
  return;
}


// ==== FUN_0064a420 @ 0x0064a420 ====

void FUN_0064a420(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x515) = 1;
  return;
}


// ==== FUN_0064a430 @ 0x0064a430 ====

void FUN_0064a430(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x516) = 1;
  return;
}


// ==== FUN_0064a440 @ 0x0064a440 ====

void FUN_0064a440(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x517) = 1;
  return;
}


// ==== FUN_0064a460 @ 0x0064a460 ====

void FUN_0064a460(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = 0;
  FUN_00797a50(in_ECX + 0x510,0,9);
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  return;
}


// ==== FUN_0064a4b0 @ 0x0064a4b0 ====

void FUN_0064a4b0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_0064a5d0 @ 0x0064a5d0 ====

void FUN_0064a5d0(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined2 extraout_var;
  float fVar7;
  float fVar8;
  uint uStack_f8;
  uint uStack_f4;
  undefined4 uStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  int iStack_50;
  uint uStack_4c;
  int *piStack_48;
  int *piStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  int iStack_24;
  int iStack_20;
  uint uStack_1c;
  uint uStack_18;
  
  uStack_38 = 0x64a5e4;
  iVar3 = (**(code **)(*DAT_00b5a6b8 + 4))();
  uStack_38 = 0x64a5f1;
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 0x504) + 0x20))();
  uStack_38 = 0x64a5f8;
  iVar5 = (**(code **)(*piVar4 + 4))();
  uStack_38 = CONCAT22(extraout_var,*(undefined2 *)(iVar5 + 0x28));
  uStack_3c = 0x64a60a;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x54))();
  uStack_3c = 0;
  uStack_40 = 0x64a617;
  uVar6 = (**(code **)(**(int **)(in_ECX + 0x508) + 0x58))();
  uStack_40 = CONCAT31((int3)((uint)uVar6 >> 8),*(undefined1 *)(iVar5 + 0x118));
  piStack_44 = (int *)0x64a62c;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xbc))();
  fVar8 = (float)(*(int *)(in_ECX + 0x30c) + 100) * DAT_009a09b8;
  fVar7 = ((float)*(ushort *)(iVar5 + 0x112) + (float)*(int *)(in_ECX + 0x308) + fVar8) *
          *(float *)(iVar3 + 0x10);
  fVar8 = ((float)*(ushort *)(iVar5 + 0x110) + (float)*(int *)(in_ECX + 0x304) + fVar8) *
          *(float *)(iVar3 + 0x10);
  if (fVar8 < 0.0) {
    fVar8 = 0.0;
  }
  if (fVar7 < 0.0) {
    fVar7 = 0.0;
  }
  iStack_24 = (int)fVar8;
  iStack_20 = iStack_24;
  if (iStack_24 <= (int)fVar7) {
    iStack_20 = (int)fVar7;
  }
  uStack_1c = (uint)*(ushort *)(iVar5 + 0x114);
  uStack_18 = uStack_1c;
  if (uStack_1c <= *(ushort *)(iVar5 + 0x116)) {
    uStack_18 = (uint)*(ushort *)(iVar5 + 0x116);
  }
  piStack_44 = &iStack_24;
  piStack_48 = (int *)0x64a6dd;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x9c))();
  piStack_48 = &iStack_20;
  uStack_4c = 0x64a6f0;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd8))();
  fVar8 = (float)(*(int *)(in_ECX + 0x3ac) + 100) * DAT_009a09b8;
  uStack_4c = (uint)(((float)*(ushort *)(iVar5 + 0x40) + (float)*(int *)(in_ECX + 0x3a8) + fVar8) *
                    *(float *)(iVar3 + 0x18));
  iStack_50 = (int)(((float)*(ushort *)(iVar5 + 0x3e) + (float)*(int *)(in_ECX + 0x3a4) + fVar8) *
                   *(float *)(iVar3 + 0x18));
  uStack_54 = 0x64a757;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc0))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x44) + *(int *)(in_ECX + 0x2e4) + *(int *)(in_ECX + 0x300);
  if (iVar3 < 0) {
    iVar3 = 0;
    uStack_3c = uStack_3c & 0xffffff00;
  }
  else if (100 < (byte)iVar3) {
    iVar3 = 100;
  }
  uStack_3c = CONCAT31(uStack_3c._1_3_,(char)iVar3);
  uStack_54 = uStack_3c;
  uStack_58 = 0;
  uStack_5c = 0x64a791;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x45) + *(int *)(in_ECX + 0x2e8) + *(int *)(in_ECX + 0x300);
  if (iVar3 < 0) {
    iVar3 = 0;
    piStack_44 = (int *)((uint)piStack_44 & 0xffffff00);
  }
  else if (100 < (byte)iVar3) {
    iVar3 = 100;
  }
  piStack_44 = (int *)CONCAT31(piStack_44._1_3_,(char)iVar3);
  uStack_5c = (uint)piStack_44;
  uStack_60 = 1;
  uStack_64 = 0x64a7cb;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x46) + *(int *)(in_ECX + 0x2ec) + *(int *)(in_ECX + 0x300);
  if (iVar3 < 0) {
    iVar3 = 0;
    uStack_4c = uStack_4c & 0xffffff00;
  }
  else if (100 < (byte)iVar3) {
    iVar3 = 100;
  }
  uStack_4c = CONCAT31(uStack_4c._1_3_,(char)iVar3);
  uStack_64 = uStack_4c;
  uStack_68 = 2;
  uStack_6c = 0x64a805;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x47) + *(int *)(in_ECX + 0x2f0) + *(int *)(in_ECX + 0x300);
  if (iVar3 < 0) {
    iVar3 = 0;
    uStack_54 = uStack_54 & 0xffffff00;
  }
  else if (100 < (byte)iVar3) {
    iVar3 = 100;
  }
  uStack_54 = CONCAT31(uStack_54._1_3_,(char)iVar3);
  uStack_6c = uStack_54;
  uStack_70 = 3;
  uStack_74 = 0x64a83f;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x48) + *(int *)(in_ECX + 0x2f4) + *(int *)(in_ECX + 0x300);
  if (iVar3 < 0) {
    iVar3 = 0;
    uStack_5c = uStack_5c & 0xffffff00;
  }
  else if (100 < (byte)iVar3) {
    iVar3 = 100;
  }
  uStack_5c = CONCAT31(uStack_5c._1_3_,(char)iVar3);
  uStack_74 = uStack_5c;
  uStack_78 = 4;
  uStack_7c = 0x64a879;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar3 = (uint)*(byte *)(iVar5 + 0x43) + *(int *)(in_ECX + 0x2f8);
  if (iVar3 < 0) {
    iVar3 = 0;
    uStack_64 = uStack_64 & 0xffffff00;
  }
  else if (100 < (byte)iVar3) {
    iVar3 = 100;
  }
  uStack_64 = CONCAT31(uStack_64._1_3_,(char)iVar3);
  uStack_7c = uStack_64;
  uStack_80 = 5;
  uStack_84 = 0x64a8ad;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  uStack_84 = 0;
  uStack_88 = 0x64a8bd;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x104))();
  uStack_74 = CONCAT31(uStack_74._1_3_,0xfa);
  if (*(byte *)(in_ECX + 0x364) < 0xfb) {
    uStack_74 = CONCAT31(uStack_74._1_3_,*(byte *)(in_ECX + 0x364));
  }
  uStack_88 = uStack_74;
  uStack_8c = 0;
  uStack_90 = 0x64a8e9;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  uStack_7c = CONCAT31(uStack_7c._1_3_,0xfa);
  if (*(byte *)(in_ECX + 0x368) < 0xfb) {
    uStack_7c = CONCAT31(uStack_7c._1_3_,*(byte *)(in_ECX + 0x368));
  }
  uStack_90 = uStack_7c;
  uStack_94 = 1;
  uStack_98 = 0x64a910;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  uStack_84 = CONCAT31(uStack_84._1_3_,0xfa);
  if (*(byte *)(in_ECX + 0x36c) < 0xfb) {
    uStack_84 = CONCAT31(uStack_84._1_3_,*(byte *)(in_ECX + 0x36c));
  }
  uStack_98 = uStack_84;
  uStack_9c = 2;
  uStack_a0 = 0x64a937;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  uStack_8c = CONCAT31(uStack_8c._1_3_,0xfa);
  if (*(byte *)(in_ECX + 0x370) < 0xfb) {
    uStack_8c = CONCAT31(uStack_8c._1_3_,*(byte *)(in_ECX + 0x370));
  }
  uStack_a0 = uStack_8c;
  uStack_a4 = 3;
  uStack_a8 = 0x64a95e;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  uStack_94._0_1_ = 0xfa;
  if (*(byte *)(in_ECX + 0x374) < 0xfb) {
    uStack_94._0_1_ = *(byte *)(in_ECX + 0x374);
  }
  uStack_a8._0_1_ = (byte)uStack_94;
  uStack_a8._1_3_ = uStack_94._1_3_;
  uStack_ac = 4;
  uStack_b0 = 0x64a985;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  uStack_b0 = 100;
  uStack_b4 = 100;
  uStack_b8 = 0x64a997;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xcc))();
  uStack_b8 = 0x96;
  uStack_bc = 0x64a9aa;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd4))();
  uStack_bc = 0;
  uStack_c0 = 0x64a9ba;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xec))();
  bVar2 = *(byte *)(iVar5 + 0x42);
  if (100 < bVar2) {
    bVar2 = 100;
  }
  bVar1 = *(byte *)(in_ECX + 0x34c);
  if (*(int *)(in_ECX + 0x34c) < 1) {
    if (bVar2 < bVar1) {
      bVar2 = 0;
    }
    else {
      bVar2 = bVar2 - bVar1;
      uStack_a8._0_1_ = 100;
      if (100 < bVar2) goto LAB_0064aa78;
    }
  }
  else {
    if ((int)(100 - (uint)bVar1) <= (int)(uint)bVar2) {
      uStack_a8._0_1_ = 100;
      goto LAB_0064aa78;
    }
    if ((int)(uint)bVar2 <= (int)-(uint)bVar1) {
      uStack_a8._0_1_ = 0;
      goto LAB_0064aa78;
    }
    bVar2 = bVar2 + bVar1;
  }
  uStack_a8._0_1_ = bVar2;
LAB_0064aa78:
  uStack_c0._0_1_ = (byte)uStack_a8;
  uStack_c0._1_3_ = uStack_a8._1_3_;
  uStack_c4 = 0x64aa8b;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xfc))();
  uStack_c4 = 0;
  uStack_c8 = 0;
  uStack_cc = 0x64aa9d;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x100))();
  bVar2 = *(byte *)(in_ECX + 0x348);
  uStack_b0 = CONCAT31(uStack_b0._1_3_,bVar2);
  if ((int)(100 - (uint)bVar2) < 1) {
    uStack_b4._0_1_ = 100;
  }
  else {
    uStack_b4._0_1_ = (-1 < (int)-(uint)bVar2) - 1U & bVar2;
  }
  uStack_cc._0_1_ = (byte)uStack_b4;
  uStack_cc._1_3_ = uStack_b4._1_3_;
  uStack_d0 = 0x64aadf;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf0))();
  bVar2 = *(byte *)(in_ECX + 900);
  uStack_b4 = CONCAT31(uStack_b4._1_3_,bVar2);
  if ((int)(0xfa - (uint)bVar2) < 1) {
    uStack_bc._0_1_ = 0xfa;
  }
  else {
    uStack_bc._0_1_ = (-1 < (int)-(uint)bVar2) - 1U & bVar2;
  }
  uStack_d0._0_1_ = (byte)uStack_bc;
  uStack_d0._1_3_ = uStack_bc._1_3_;
  uStack_d4 = 0;
  uStack_d8 = 0x64ab1f;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))();
  bVar2 = *(byte *)(in_ECX + 0x388);
  uStack_bc = CONCAT31(uStack_bc._1_3_,bVar2);
  if ((int)(0xfa - (uint)bVar2) < 1) {
    uStack_c4._0_1_ = 0xfa;
  }
  else {
    uStack_c4._0_1_ = (-1 < (int)-(uint)bVar2) - 1U & bVar2;
  }
  uStack_d8._0_1_ = (byte)uStack_c4;
  uStack_d8._1_3_ = uStack_c4._1_3_;
  uStack_dc = 1;
  uStack_e0 = 0x64ab5f;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))();
  uStack_cc._0_1_ = *(byte *)(in_ECX + 0x38c);
  uStack_c4 = CONCAT31(uStack_c4._1_3_,(byte)uStack_cc);
  if ((int)(0xfa - (uint)(byte)uStack_cc) < 1) {
    uStack_cc._0_1_ = 0xfa;
  }
  else {
    uStack_cc._0_1_ = (-1 < (int)-(uint)(byte)uStack_cc) - 1U & (byte)uStack_cc;
  }
  uStack_e0._0_1_ = (byte)uStack_cc;
  uStack_e0._1_3_ = uStack_cc._1_3_;
  uStack_e4 = 2;
  uStack_e8 = 0x64ab9f;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))();
  bVar2 = *(byte *)(in_ECX + 0x390);
  uStack_cc = CONCAT31(uStack_cc._1_3_,bVar2);
  if ((int)(0xfa - (uint)bVar2) < 1) {
    uStack_d4._0_1_ = 0xfa;
  }
  else {
    uStack_d4._0_1_ = (-1 < (int)-(uint)bVar2) - 1U & bVar2;
  }
  uStack_e8._0_1_ = (byte)uStack_d4;
  uStack_e8._1_3_ = uStack_d4._1_3_;
  uStack_ec = 3;
  uStack_f0 = 0x64abdf;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))();
  bVar2 = *(byte *)(in_ECX + 0x394);
  uStack_d4 = CONCAT31(uStack_d4._1_3_,bVar2);
  if ((int)(0xfa - (uint)bVar2) < 1) {
    uStack_dc = CONCAT31(uStack_dc._1_3_,0xfa);
  }
  else {
    uStack_dc = CONCAT31(uStack_dc._1_3_,(-1 < (int)-(uint)bVar2) - 1U & bVar2);
  }
  uStack_f0 = uStack_dc;
  uStack_f4 = 4;
  uStack_f8 = 0x64ac1f;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))();
  uStack_e0 = CONCAT31(uStack_e0._1_3_,100);
  if (*(byte *)(iVar5 + 0x49) < 0x65) {
    uStack_e0 = CONCAT31(uStack_e0._1_3_,*(byte *)(iVar5 + 0x49));
  }
  uStack_f8 = 0;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x114))(uStack_e0);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(0,*(undefined4 *)(in_ECX + 0x3e4));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(1,*(undefined4 *)(in_ECX + 1000));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(2,*(undefined4 *)(in_ECX + 0x3ec));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(3,*(undefined4 *)(in_ECX + 0x3f0));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(4,*(undefined4 *)(in_ECX + 0x3f4));
  uStack_f8 = (uint)*(ushort *)(iVar5 + 0x114);
  uStack_f4 = uStack_f8;
  if (uStack_f8 <= *(ushort *)(iVar5 + 0x116)) {
    uStack_f4 = (uint)*(ushort *)(iVar5 + 0x116);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd8))(&uStack_f8);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xdc))(100,100);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x130))(100);
  return;
}


// ==== FUN_0064ad20 @ 0x0064ad20 ====

bool FUN_0064ad20(void)

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


// ==== FUN_0064ad90 @ 0x0064ad90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064ad90(void)

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
  fVar1 = (float)(*(int *)(in_ECX + 0x2a4) + *(int *)(iVar5 + 0x2c)) + *(float *)(iVar3 + 0x58);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x74))(fVar1);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x78))(0);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x7c))
            ((float)*(ushort *)(iVar5 + 0x34) + (float)*(int *)(in_ECX + 0x2ac) * DAT_009a09b8 +
             *(float *)(iVar3 + 0x5c));
  fVar6 = (float)*(int *)(in_ECX + 0x2b4) * DAT_009a09b8 + *(float *)(iVar3 + 0x60);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x84))();
  piVar4 = (int *)(**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x44) + 0x14))();
  cVar2 = FUN_0064ad20();
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


// ==== FUN_0064b010 @ 0x0064b010 ====

void FUN_0064b010(undefined4 param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (*(char *)(in_ECX + 0x512) == '\x01') {
    (**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x10) + 0x30))((undefined4 *)(in_ECX + 4));
    puVar2 = (undefined4 *)(in_ECX + 4);
    puVar3 = (undefined4 *)(in_ECX + 0x284);
    for (iVar1 = 0xa0; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    FUN_0064a5d0(param_1);
  }
  FUN_0064ad90(param_1);
  FUN_00797a50(in_ECX + 0x510,0,9);
  return;
}


// ==== FUN_0064b070 @ 0x0064b070 ====

void FUN_0064b070(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  *(undefined1 *)(in_ECX + 0x519) = 1;
  FUN_00797a50(in_ECX + 0x510,0,9);
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  uVar1 = FUN_00617cb0();
  *(undefined4 *)(in_ECX + 0x508) = uVar1;
  FUN_0064b110(param_1);
  *(undefined1 *)(in_ECX + 0x519) = 0;
  return;
}


// ==== FUN_0064b0f0 @ 0x0064b0f0 ====

void FUN_0064b0f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0064a3c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0064b110 @ 0x0064b110 ====

void FUN_0064b110(void)

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
  FUN_0064a5d0(unaff_retaddr);
  FUN_0064ad90(unaff_retaddr);
  *(undefined4 *)(in_ECX + 0x50c) = unaff_retaddr;
  FUN_00797a50(in_ECX + 0x510,0,9);
  return;
}


// ==== FUN_0064b170 @ 0x0064b170 ====

undefined4 FUN_0064b170(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa04);
}


// ==== FUN_0064b180 @ 0x0064b180 ====

undefined4 FUN_0064b180(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0c);
}


// ==== FUN_0064b190 @ 0x0064b190 ====

void FUN_0064b190(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_0064b240 @ 0x0064b240 ====

void FUN_0064b240(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  FUN_00797a50(in_ECX + 0x504,0,0x280);
  FUN_00797a50(in_ECX + 0x784,0,0x280);
  return;
}


// ==== FUN_0064b350 @ 0x0064b350 ====

undefined1 FUN_0064b350(void)

{
  return 0;
}


// ==== FUN_0064b360 @ 0x0064b360 ====

undefined1 FUN_0064b360(void)

{
  return 0;
}


// ==== FUN_0064b3a0 @ 0x0064b3a0 ====

void FUN_0064b3a0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098be78;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4c6c;
  in_ECX[0x281] = param_1;
  in_ECX[0x282] = 0;
  in_ECX[0x283] = 0;
  FUN_00797a50(in_ECX + 0x284,0,9);
  FUN_0064b240();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0064b410 @ 0x0064b410 ====

void FUN_0064b410(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_0064b420 @ 0x0064b420 ====

void FUN_0064b420(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa10) = 1;
  return;
}


// ==== FUN_0064b430 @ 0x0064b430 ====

void FUN_0064b430(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa11) = 1;
  return;
}


// ==== FUN_0064b440 @ 0x0064b440 ====

void FUN_0064b440(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa12) = 1;
  return;
}


// ==== FUN_0064b450 @ 0x0064b450 ====

void FUN_0064b450(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa13) = 1;
  return;
}


// ==== FUN_0064b460 @ 0x0064b460 ====

void FUN_0064b460(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa14) = 1;
  return;
}


// ==== FUN_0064b470 @ 0x0064b470 ====

void FUN_0064b470(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa15) = 1;
  return;
}


// ==== FUN_0064b480 @ 0x0064b480 ====

void FUN_0064b480(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa16) = 1;
  return;
}


// ==== FUN_0064b490 @ 0x0064b490 ====

void FUN_0064b490(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa17) = 1;
  return;
}


// ==== FUN_0064b4b0 @ 0x0064b4b0 ====

void FUN_0064b4b0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = 0;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_0064b240();
  return;
}


// ==== FUN_0064b4e0 @ 0x0064b4e0 ====

void FUN_0064b4e0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_0064b640 @ 0x0064b640 ====

void FUN_0064b640(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_0064b240();
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  return;
}


// ==== FUN_0064b690 @ 0x0064b690 ====

void FUN_0064b690(uint param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0xa0c);
  if (*(uint *)(in_ECX + 0xa0c) < param_1) {
    uVar1 = param_1;
  }
  *(uint *)(in_ECX + 0xa0c) = uVar1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  return;
}


// ==== FUN_0064b6c0 @ 0x0064b6c0 ====

void FUN_0064b6c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0064b410();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0064b6e0 @ 0x0064b6e0 ====

undefined4 FUN_0064b6e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa04);
}


// ==== FUN_0064b6f0 @ 0x0064b6f0 ====

void FUN_0064b6f0(void)

{
  return;
}


// ==== FUN_0064b700 @ 0x0064b700 ====

undefined4 FUN_0064b700(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0c);
}


// ==== FUN_0064b710 @ 0x0064b710 ====

void FUN_0064b710(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_0064b7c0 @ 0x0064b7c0 ====

void FUN_0064b7c0(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  FUN_00797a50(in_ECX + 0x504,0,0x280);
  FUN_00797a50(in_ECX + 0x784,0,0x280);
  return;
}


// ==== FUN_0064b8d0 @ 0x0064b8d0 ====

undefined1 FUN_0064b8d0(void)

{
  return 0;
}


// ==== FUN_0064b8e0 @ 0x0064b8e0 ====

undefined1 FUN_0064b8e0(void)

{
  return 0;
}


// ==== FUN_0064b920 @ 0x0064b920 ====

void FUN_0064b920(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098be98;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4cbc;
  in_ECX[0x281] = param_1;
  in_ECX[0x282] = 0;
  in_ECX[0x283] = 0;
  FUN_00797a50(in_ECX + 0x284,0,9);
  FUN_0064b7c0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0064b990 @ 0x0064b990 ====

void FUN_0064b990(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_0064b9a0 @ 0x0064b9a0 ====

void FUN_0064b9a0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa10) = 1;
  return;
}


// ==== FUN_0064b9b0 @ 0x0064b9b0 ====

void FUN_0064b9b0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa11) = 1;
  return;
}


// ==== FUN_0064b9c0 @ 0x0064b9c0 ====

void FUN_0064b9c0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa12) = 1;
  return;
}


// ==== FUN_0064b9d0 @ 0x0064b9d0 ====

void FUN_0064b9d0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa13) = 1;
  return;
}


// ==== FUN_0064b9e0 @ 0x0064b9e0 ====

void FUN_0064b9e0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa14) = 1;
  return;
}


// ==== FUN_0064b9f0 @ 0x0064b9f0 ====

void FUN_0064b9f0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa15) = 1;
  return;
}


// ==== FUN_0064ba00 @ 0x0064ba00 ====

void FUN_0064ba00(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa16) = 1;
  return;
}


// ==== FUN_0064ba10 @ 0x0064ba10 ====

void FUN_0064ba10(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa17) = 1;
  return;
}


// ==== FUN_0064ba30 @ 0x0064ba30 ====

void FUN_0064ba30(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = 0;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_0064b7c0();
  return;
}


// ==== FUN_0064ba60 @ 0x0064ba60 ====

void FUN_0064ba60(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_0064bbc0 @ 0x0064bbc0 ====

void FUN_0064bbc0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_0064b7c0();
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  return;
}


// ==== FUN_0064bc10 @ 0x0064bc10 ====

void FUN_0064bc10(byte param_1)

{
  void *in_ECX;
  
  FUN_0064b990();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0064bc30 @ 0x0064bc30 ====

undefined4 FUN_0064bc30(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa04);
}


// ==== FUN_0064bc40 @ 0x0064bc40 ====

undefined4 FUN_0064bc40(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0c);
}


// ==== FUN_0064bc50 @ 0x0064bc50 ====

void FUN_0064bc50(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_0064bd00 @ 0x0064bd00 ====

void FUN_0064bd00(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  FUN_00797a50(in_ECX + 0x504,0,0x280);
  FUN_00797a50(in_ECX + 0x784,0,0x280);
  return;
}


// ==== FUN_0064be20 @ 0x0064be20 ====

undefined1 FUN_0064be20(void)

{
  return 0;
}


// ==== FUN_0064be30 @ 0x0064be30 ====

undefined1 FUN_0064be30(void)

{
  return 0;
}


// ==== FUN_0064be70 @ 0x0064be70 ====

void FUN_0064be70(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098beb8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4d0c;
  in_ECX[0x281] = param_1;
  in_ECX[0x282] = 0;
  in_ECX[0x283] = 0;
  FUN_00797a50(in_ECX + 0x284,0,9);
  FUN_0064bd00();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0064bee0 @ 0x0064bee0 ====

void FUN_0064bee0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_0064bef0 @ 0x0064bef0 ====

void FUN_0064bef0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa10) = 1;
  return;
}


// ==== FUN_0064bf00 @ 0x0064bf00 ====

void FUN_0064bf00(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa11) = 1;
  return;
}


// ==== FUN_0064bf10 @ 0x0064bf10 ====

void FUN_0064bf10(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa12) = 1;
  return;
}


// ==== FUN_0064bf20 @ 0x0064bf20 ====

void FUN_0064bf20(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa13) = 1;
  return;
}


// ==== FUN_0064bf30 @ 0x0064bf30 ====

void FUN_0064bf30(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa14) = 1;
  return;
}


// ==== FUN_0064bf40 @ 0x0064bf40 ====

void FUN_0064bf40(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa15) = 1;
  return;
}


// ==== FUN_0064bf50 @ 0x0064bf50 ====

void FUN_0064bf50(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa16) = 1;
  return;
}


// ==== FUN_0064bf60 @ 0x0064bf60 ====

void FUN_0064bf60(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa17) = 1;
  return;
}


// ==== FUN_0064bf80 @ 0x0064bf80 ====

void FUN_0064bf80(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = 0;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_0064bd00();
  return;
}


// ==== FUN_0064bfb0 @ 0x0064bfb0 ====

void FUN_0064bfb0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_0064c110 @ 0x0064c110 ====

void FUN_0064c110(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_0064bd00();
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  return;
}


// ==== FUN_0064c160 @ 0x0064c160 ====

void FUN_0064c160(uint param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0xa0c);
  if (*(uint *)(in_ECX + 0xa0c) < param_1) {
    uVar1 = param_1;
  }
  *(uint *)(in_ECX + 0xa0c) = uVar1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  return;
}


// ==== FUN_0064c190 @ 0x0064c190 ====

void FUN_0064c190(byte param_1)

{
  void *in_ECX;
  
  FUN_0064bee0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0064c1b0 @ 0x0064c1b0 ====

undefined4 FUN_0064c1b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x504);
}


// ==== FUN_0064c1c0 @ 0x0064c1c0 ====

void FUN_0064c1c0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_0064c1d0 @ 0x0064c1d0 ====

void FUN_0064c1d0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = 0;
  return;
}


// ==== FUN_0064c1e0 @ 0x0064c1e0 ====

void FUN_0064c1e0(void)

{
  return;
}


// ==== FUN_0064c1f0 @ 0x0064c1f0 ====

void FUN_0064c1f0(void)

{
  return;
}


// ==== FUN_0064c200 @ 0x0064c200 ====

undefined4 FUN_0064c200(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x50c);
}


// ==== FUN_0064c210 @ 0x0064c210 ====

void FUN_0064c210(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_0064c220 @ 0x0064c220 ====

undefined1 FUN_0064c220(void)

{
  return 0;
}


// ==== FUN_0064c230 @ 0x0064c230 ====

undefined1 FUN_0064c230(void)

{
  return 0;
}


// ==== FUN_0064c240 @ 0x0064c240 ====

void FUN_0064c240(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[0x141] = param_1;
  *in_ECX = &PTR_FUN_009d4d5c;
  in_ECX[0x142] = 0;
  in_ECX[0x143] = 0;
  return;
}


// ==== FUN_0064c270 @ 0x0064c270 ====

void FUN_0064c270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_0064c280 @ 0x0064c280 ====

void FUN_0064c280(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x510) = 1;
  return;
}


// ==== FUN_0064c290 @ 0x0064c290 ====

void FUN_0064c290(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x511) = 1;
  return;
}


// ==== FUN_0064c2a0 @ 0x0064c2a0 ====

void FUN_0064c2a0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x512) = 1;
  return;
}


// ==== FUN_0064c2b0 @ 0x0064c2b0 ====

void FUN_0064c2b0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x513) = 1;
  return;
}


// ==== FUN_0064c2c0 @ 0x0064c2c0 ====

void FUN_0064c2c0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x514) = 1;
  return;
}


// ==== FUN_0064c2d0 @ 0x0064c2d0 ====

void FUN_0064c2d0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x515) = 1;
  return;
}


// ==== FUN_0064c2e0 @ 0x0064c2e0 ====

void FUN_0064c2e0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x516) = 1;
  return;
}


// ==== FUN_0064c2f0 @ 0x0064c2f0 ====

void FUN_0064c2f0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x517) = 1;
  return;
}


// ==== FUN_0064c320 @ 0x0064c320 ====

void FUN_0064c320(byte param_1)

{
  void *in_ECX;
  
  FUN_0064c270();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0064c340 @ 0x0064c340 ====

undefined4 FUN_0064c340(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x504);
}


// ==== FUN_0064c350 @ 0x0064c350 ====

void FUN_0064c350(void)

{
  return;
}


// ==== FUN_0064c360 @ 0x0064c360 ====

undefined4 FUN_0064c360(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x50c);
}


// ==== FUN_0064c370 @ 0x0064c370 ====

void FUN_0064c370(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_0064c400 @ 0x0064c400 ====

void FUN_0064c400(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  return;
}


// ==== FUN_0064c4c0 @ 0x0064c4c0 ====

undefined1 FUN_0064c4c0(void)

{
  return 0;
}


// ==== FUN_0064c4d0 @ 0x0064c4d0 ====

undefined1 FUN_0064c4d0(void)

{
  return 0;
}


// ==== FUN_0064c510 @ 0x0064c510 ====

void FUN_0064c510(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bed8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4dac;
  in_ECX[0x141] = param_1;
  in_ECX[0x142] = 0;
  in_ECX[0x143] = 0;
  FUN_00797a50(in_ECX + 0x144,0,9);
  FUN_00797a50(in_ECX + 1,0,0x280);
  FUN_00797a50(in_ECX + 0xa1,0,0x280);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0064c5b0 @ 0x0064c5b0 ====

void FUN_0064c5b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_0064c5c0 @ 0x0064c5c0 ====

void FUN_0064c5c0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x510) = 1;
  return;
}


// ==== FUN_0064c5d0 @ 0x0064c5d0 ====

void FUN_0064c5d0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x511) = 1;
  return;
}


// ==== FUN_0064c5e0 @ 0x0064c5e0 ====

void FUN_0064c5e0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x512) = 1;
  return;
}


// ==== FUN_0064c5f0 @ 0x0064c5f0 ====

void FUN_0064c5f0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x513) = 1;
  return;
}


// ==== FUN_0064c600 @ 0x0064c600 ====

void FUN_0064c600(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x514) = 1;
  return;
}


// ==== FUN_0064c610 @ 0x0064c610 ====

void FUN_0064c610(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x515) = 1;
  return;
}


// ==== FUN_0064c620 @ 0x0064c620 ====

void FUN_0064c620(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x516) = 1;
  return;
}


// ==== FUN_0064c630 @ 0x0064c630 ====

void FUN_0064c630(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x517) = 1;
  return;
}


// ==== FUN_0064c650 @ 0x0064c650 ====

void FUN_0064c650(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = 0;
  FUN_00797a50(in_ECX + 0x510,0,9);
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  return;
}


// ==== FUN_0064c6a0 @ 0x0064c6a0 ====

void FUN_0064c6a0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_0064c800 @ 0x0064c800 ====

void FUN_0064c800(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  FUN_00797a50(in_ECX + 0x510,0,9);
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  FUN_00797a50(in_ECX + 0x510,0,9);
  return;
}


// ==== FUN_0064c860 @ 0x0064c860 ====

void FUN_0064c860(byte param_1)

{
  void *in_ECX;
  
  FUN_0064c5b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0064c880 @ 0x0064c880 ====

undefined4 FUN_0064c880(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa04);
}


// ==== FUN_0064c890 @ 0x0064c890 ====

undefined4 FUN_0064c890(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0c);
}


// ==== FUN_0064c8a0 @ 0x0064c8a0 ====

void FUN_0064c8a0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_0064c950 @ 0x0064c950 ====

void FUN_0064c950(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  FUN_00797a50(in_ECX + 0x504,0,0x280);
  FUN_00797a50(in_ECX + 0x784,0,0x280);
  return;
}


// ==== FUN_0064c9b0 @ 0x0064c9b0 ====

bool FUN_0064c9b0(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xa1c) != 0;
}


// ==== FUN_0064ca40 @ 0x0064ca40 ====

void FUN_0064ca40(void)

{
  byte *in_ECX;
  byte *in_EDX;
  byte *unaff_ESI;
  
  if (*in_EDX <= *in_ECX) {
    in_ECX = in_EDX;
  }
  *unaff_ESI = *in_ECX;
  return;
}


// ==== FUN_0064ca90 @ 0x0064ca90 ====

void FUN_0064ca90(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bef8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4e1c;
  in_ECX[0x281] = param_1;
  in_ECX[0x283] = 0;
  FUN_00797a50(in_ECX + 0x284,0,9);
  FUN_0064c950();
  in_ECX[0x288] = 0;
  in_ECX[0x289] = 0;
  in_ECX[0x287] = 0;
  *(undefined2 *)(in_ECX + 0x28a) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0064cb20 @ 0x0064cb20 ====

void FUN_0064cb20(void)

{
  undefined4 *in_ECX;
  
  in_ECX[0x288] = 0;
  in_ECX[0x289] = 0;
  in_ECX[0x287] = 0;
  *(undefined2 *)(in_ECX + 0x28a) = 0;
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_0064cb50 @ 0x0064cb50 ====

void FUN_0064cb50(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa10) = 1;
  return;
}


// ==== FUN_0064cb60 @ 0x0064cb60 ====

void FUN_0064cb60(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa11) = 1;
  return;
}


// ==== FUN_0064cb70 @ 0x0064cb70 ====

void FUN_0064cb70(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa12) = 1;
  return;
}


// ==== FUN_0064cb80 @ 0x0064cb80 ====

void FUN_0064cb80(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa13) = 1;
  return;
}


// ==== FUN_0064cb90 @ 0x0064cb90 ====

void FUN_0064cb90(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa14) = 1;
  return;
}


// ==== FUN_0064cba0 @ 0x0064cba0 ====

void FUN_0064cba0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa15) = 1;
  return;
}


// ==== FUN_0064cbb0 @ 0x0064cbb0 ====

void FUN_0064cbb0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa16) = 1;
  return;
}


// ==== FUN_0064cbc0 @ 0x0064cbc0 ====

void FUN_0064cbc0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa17) = 1;
  return;
}


// ==== FUN_0064cbe0 @ 0x0064cbe0 ====

void FUN_0064cbe0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = 0;
  *(undefined4 *)(in_ECX + 0xa20) = 0;
  *(undefined4 *)(in_ECX + 0xa24) = 0;
  *(undefined4 *)(in_ECX + 0xa1c) = 0;
  *(undefined2 *)(in_ECX + 0xa28) = 0;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_0064c950();
  return;
}


// ==== FUN_0064cc20 @ 0x0064cc20 ====

void FUN_0064cc20(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_0064cc90 @ 0x0064cc90 ====

void FUN_0064cc90(void)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = in_ECX + 0x1e1;
  puVar2 = in_ECX;
  for (iVar1 = 0xa0; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar3 = puVar3 + 1;
  }
  FUN_00618280(in_ECX + 0xa1);
  FUN_00618280(in_ECX + 0x141);
  return;
}


// ==== FUN_0064ccd0 @ 0x0064ccd0 ====

void FUN_0064ccd0(void)

{
  int *piVar1;
  undefined2 uVar2;
  short sVar3;
  undefined4 uVar4;
  int *piVar5;
  short *psVar6;
  int iVar7;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0xa04) + 0x98);
  uVar4 = (**(code **)(*piVar1 + 0x40))();
  *(undefined4 *)(in_ECX + 0xa1c) = uVar4;
  uVar2 = (**(code **)(*piVar1 + 0x20))();
  *(undefined2 *)(in_ECX + 0xa28) = uVar2;
  piVar5 = *(int **)(*(int *)(in_ECX + 0xa04) + 0x24);
  (**(code **)(*piVar5 + 0x54))(in_ECX + 4);
  *(undefined4 *)(in_ECX + 0xa24) = *(undefined4 *)(in_ECX + 0xb0);
  iVar7 = *piVar5;
  uVar4 = (**(code **)(*piVar1 + 0x28))();
  piVar5 = (int *)(**(code **)(iVar7 + 0x2c))(uVar4);
  if (piVar5 == (int *)0x0) {
    *(undefined4 *)(in_ECX + 0xa20) = 0;
    *(undefined4 *)(in_ECX + 0xa24) = 0;
    *(undefined4 *)(in_ECX + 0xa1c) = 0;
    *(undefined2 *)(in_ECX + 0xa28) = 0;
    (**(code **)(*piVar1 + 0xc))();
    return;
  }
  psVar6 = (short *)(**(code **)(*piVar5 + 0x14))();
  sVar3 = (**(code **)(*piVar1 + 0x20))();
  if (*psVar6 == sVar3) {
    iVar7 = (**(code **)(*piVar5 + 0x34))();
    *(int *)(in_ECX + 0xa20) = (int)*(char *)(iVar7 + 1);
    return;
  }
  *(undefined4 *)(in_ECX + 0xa20) = 0;
  *(undefined4 *)(in_ECX + 0xa24) = 0;
  *(undefined4 *)(in_ECX + 0xa1c) = 0;
  *(undefined2 *)(in_ECX + 0xa28) = 0;
  (**(code **)(*piVar1 + 0xc))();
  return;
}


// ==== FUN_0064cf00 @ 0x0064cf00 ====

undefined4 FUN_0064cf00(undefined4 *param_1)

{
  int *piVar1;
  short *psVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(*(int *)(in_ECX + 0xa04) + 0x24) + 0x2c))(*param_1);
  if ((piVar1 != (int *)0x0) && (*(int *)(in_ECX + 0xa1c) != 0)) {
    psVar2 = (short *)(**(code **)(*piVar1 + 0x14))();
    if (*psVar2 == *(short *)(in_ECX + 0xa28)) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_0064cf50 @ 0x0064cf50 ====

int FUN_0064cf50(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(*(int *)(in_ECX + 0xa04) + 0x24) + 0x50))();
  if (*(int *)(in_ECX + 0xa1c) == 0) {
    return (int)*(char *)(iVar1 + 0x38);
  }
  return *(int *)(in_ECX + 0xa20);
}


// ==== FUN_0064cf90 @ 0x0064cf90 ====

void FUN_0064cf90(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0xa04) + 0x48);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x28))();
  }
  (**(code **)(*piVar1 + 8))();
                    /* WARNING: Could not recover jumptable at 0x0064cfc0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x54))();
  return;
}


// ==== FUN_0064cfd0 @ 0x0064cfd0 ====

void FUN_0064cfd0(void)

{
  int *piVar1;
  undefined2 *puVar2;
  int in_ECX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0xa04) + 0xc);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x28))();
  }
  puVar2 = (undefined2 *)(**(code **)(*piVar1 + 0xc))();
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x5c))(CONCAT22(extraout_var,*puVar2));
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x60))(CONCAT22(extraout_var_00,puVar2[1]));
  (**(code **)(**(int **)(in_ECX + 0xa08) + 100))(CONCAT22(extraout_var_01,puVar2[2]));
                    /* WARNING: Could not recover jumptable at 0x0064d034. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x68))(CONCAT22(extraout_var_02,puVar2[3]));
  return;
}


// ==== FUN_0064d040 @ 0x0064d040 ====

void FUN_0064d040(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = *(int **)(*(int *)(in_ECX + 0xa04) + 0x24);
  (**(code **)(*piVar2 + 0x50))();
  (**(code **)(*piVar2 + 0x54))(in_ECX + 4);
  piVar2 = *(int **)(*(int *)(in_ECX + 0xa04) + 0x74);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
  }
  iVar1 = **(int **)(in_ECX + 0xa08);
  iVar3 = (**(code **)(*piVar2 + 8))();
  (**(code **)(iVar1 + 0x58))(*(undefined1 *)(iVar3 + 4));
  return;
}


// ==== FUN_0064d0d0 @ 0x0064d0d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064d0d0(void)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  ushort *puVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  undefined1 *puVar11;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined4 uVar12;
  int *in_ECX;
  undefined4 extraout_ECX;
  int iVar13;
  byte bVar14;
  int *piVar15;
  ushort uVar16;
  int *piVar17;
  uint uVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  undefined8 uVar29;
  uint3 uVar30;
  undefined3 uVar31;
  int *piStack_25c;
  undefined4 uStack_258;
  int iStack_254;
  undefined4 uStack_250;
  uint uStack_24c;
  float fStack_248;
  int iStack_244;
  int **ppiStack_240;
  float fStack_23c;
  int iStack_238;
  int **ppiStack_234;
  undefined4 uStack_230;
  int *piStack_22c;
  int **ppiStack_228;
  float fStack_224;
  undefined4 uStack_220;
  int *piStack_21c;
  undefined4 uStack_218;
  int *piStack_214;
  int *piStack_210;
  int *piStack_20c;
  undefined4 uStack_208;
  int *piStack_204;
  int *piStack_200;
  int iStack_1fc;
  int iStack_1f8;
  int iStack_1f4;
  undefined4 uStack_1f0;
  int iStack_1ec;
  int iStack_1e8;
  int iStack_1e4;
  int iStack_1e0;
  int iStack_1dc;
  int iStack_1d8;
  float *pfStack_1d4;
  byte bStack_1d0;
  undefined3 uStack_1cf;
  undefined1 *puStack_1cc;
  int iStack_1c8;
  int iStack_1c4;
  float *pfStack_1c0;
  int *piStack_1bc;
  undefined1 *puStack_1b8;
  int *piStack_1b4;
  int iStack_1b0;
  float fStack_194;
  float fStack_184;
  float fStack_180;
  float fStack_17c;
  float fStack_178;
  int iStack_174;
  int iStack_170;
  int iStack_16c;
  int iStack_168;
  float fStack_164;
  float fStack_160;
  float fStack_158;
  float fStack_154;
  float fStack_150;
  float fStack_14c;
  int *piStack_144;
  float fStack_140;
  int iStack_13c;
  int iStack_138;
  int iStack_134;
  undefined1 auStack_130 [4];
  float fStack_12c;
  int iStack_128;
  int iStack_124;
  int iStack_120;
  int iStack_11c;
  int iStack_118;
  int iStack_114;
  int iStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  
  iStack_1b0 = 0x64d0e7;
  iStack_170 = (**(code **)(*DAT_00b5a6b8 + 4))();
  piVar7 = *(int **)(in_ECX[0x281] + 0x24);
  piVar15 = *(int **)(in_ECX[0x281] + 4);
  if (piVar15 == (int *)0x0) {
    piVar15 = (int *)0x0;
  }
  else {
    iStack_1b0 = 0x64d106;
    piVar15 = (int *)(**(code **)(*piVar15 + 0x18))();
  }
  piStack_144 = piVar15;
  if (*(int **)(in_ECX[0x281] + 0x48) != (int *)0x0) {
    iStack_1b0 = 0x64d11e;
    (**(code **)(**(int **)(in_ECX[0x281] + 0x48) + 0x28))();
  }
  iStack_1b0 = 0x64d129;
  (**(code **)(*(int *)in_ECX[0x282] + 0x14))();
  iStack_1b0 = 0x64d138;
  (**(code **)(*(int *)in_ECX[0x282] + 0x18))();
  iStack_1b0 = 0x64d13f;
  piVar15 = (int *)(**(code **)(*piVar15 + 0x10))();
  iStack_1b0 = 0x64d146;
  iStack_16c = (**(code **)(*piVar15 + 4))();
  iStack_1b0 = 0x64d155;
  (**(code **)(*(int *)in_ECX[0x282] + 8))();
  iStack_1b0 = 0x64d160;
  puVar4 = (ushort *)(**(code **)(*(int *)in_ECX[0x282] + 0x14))();
  fStack_12c = (float)*puVar4;
  iStack_1b0 = 0x64d17b;
  iVar5 = (**(code **)(*(int *)in_ECX[0x282] + 0x14))();
  fStack_158 = (float)*(ushort *)(iVar5 + 2);
  iStack_1b0 = 0x64d194;
  iVar5 = (**(code **)(*(int *)in_ECX[0x282] + 0x14))();
  fStack_140 = (float)*(ushort *)(iVar5 + 6);
  iStack_1b0 = 0x64d1a9;
  uVar29 = (**(code **)(*piVar7 + 0x50))();
  iVar13 = (int)uVar29;
  iStack_1b0 = CONCAT31((int3)((ulonglong)uVar29 >> 0x28),*(undefined1 *)(iVar13 + 0x36));
  piStack_1b4 = (int *)0x64d1bd;
  (**(code **)(*(int *)in_ECX[0x282] + 0xbc))();
  iVar5 = *(int *)(iVar13 + 0x14);
  fVar19 = (float)*(int *)(iVar13 + 0x1c);
  fVar22 = (float)*(int *)(iVar13 + 0x20);
  fStack_160 = (float)*(int *)(iVar13 + 0x18);
  fStack_164 = fVar22;
  if (*(int *)(iVar13 + 0x28) < 2) {
    fVar24 = (float)*(int *)(iVar13 + 0x2c) + fVar19;
    fVar22 = (float)*(int *)(iVar13 + 0x30) + fVar22;
  }
  else if (*(int *)(iVar13 + 0x30) < 2) {
    fVar24 = (float)*(int *)(iVar13 + 0x24) + fVar19;
    fVar22 = (float)*(int *)(iVar13 + 0x28) + fVar22;
  }
  else {
    piStack_1b4 = (int *)0x64d241;
    uVar8 = (**(code **)(*DAT_00b5b0a0 + 0xc))();
    if ((uVar8 & 1) == 0) {
      iVar6 = *(int *)(iVar13 + 0x24);
      iVar9 = *(int *)(iVar13 + 0x28);
    }
    else {
      iVar6 = *(int *)(iVar13 + 0x2c);
      iVar9 = *(int *)(iVar13 + 0x30);
    }
    fVar24 = (float)iVar6 + fVar19;
    fVar22 = (float)iVar9 + fVar22;
  }
  iStack_124 = *(int *)(iVar13 + 0x2c);
  iStack_13c = *(int *)(iVar13 + 0x28);
  iStack_118 = *(int *)(iVar13 + 0x30);
  iVar9 = *(int *)(iVar13 + 0x24);
  piStack_1b4 = (int *)0x64d2a8;
  puVar4 = (ushort *)(**(code **)(*(int *)in_ECX[0x282] + 0x14))();
  uVar16 = *puVar4;
  piStack_1b4 = (int *)0x64d2c0;
  iVar6 = (**(code **)(*(int *)in_ECX[0x282] + 0x14))();
  fStack_14c = (float)*(ushort *)(iVar6 + 2);
  piStack_1b4 = (int *)0x64d2d9;
  iVar6 = (**(code **)(*(int *)in_ECX[0x282] + 0x14))();
  fStack_154 = (float)*(ushort *)(iVar6 + 6);
  piStack_1b4 = (int *)0x64d2f2;
  puVar4 = (ushort *)(**(code **)(*(int *)in_ECX[0x282] + 8))();
  uVar3 = *puVar4;
  piStack_1b4 = (int *)0x64d30a;
  puVar4 = (ushort *)(**(code **)(*(int *)in_ECX[0x282] + 8))();
  fStack_158 = (float)*puVar4;
  piStack_1b4 = (int *)0x64d322;
  puVar4 = (ushort *)(**(code **)(*(int *)in_ECX[0x282] + 8))();
  fStack_180 = (float)in_ECX[0x201];
  fStack_14c = *(float *)(iStack_170 + 0x84) * fStack_14c;
  fStack_158 = *(float *)(iStack_170 + 0x88) * fStack_158;
  fVar25 = *(float *)(iStack_170 + 0x7c) * (float)uVar16;
  fStack_154 = *(float *)(iStack_170 + 0x8c) * fStack_154;
  fVar23 = (float)in_ECX[0x203] * DAT_009a09b8 + DAT_0099d080;
  fVar20 = *(float *)(iStack_170 + 0x80) * (float)uVar3;
  fStack_178 = ((float)*(int *)(iVar13 + 0x24) + fVar20 + fVar25) * fVar23 + fStack_180;
  fVar26 = (float)in_ECX[0x202] + fStack_180;
  fStack_150 = ((float)*(int *)(iVar13 + 0x28) + fVar20 + fVar25) * fVar23 + fVar26;
  fStack_194 = ((float)*(int *)(iVar13 + 0x2c) + fVar20 + fVar25) * fVar23 + fStack_180;
  fVar27 = *(float *)(iStack_170 + 0x90) * (float)*puVar4 + fStack_154;
  fVar28 = (float)in_ECX[0x206] * DAT_009a09b8 + DAT_0099d080;
  fVar21 = (fVar20 + fVar25 + fVar22) * fVar23 + fVar26;
  fVar22 = (fVar20 + fVar25 + fVar24) * fVar23 + fStack_180;
  fStack_184 = ((float)*(int *)(iVar13 + 0x30) + fVar20 + fVar25) * fVar23 + fVar26;
  fStack_180 = ((float)iVar9 + fVar19 + (float)iStack_124 + fStack_158 + fStack_14c) * fVar23 +
               fStack_180;
  fStack_164 = ((float)iStack_13c + fStack_164 + (float)iStack_118 + fStack_158 + fStack_14c) *
               fVar23 + fVar26;
  fStack_17c = (fVar27 + (float)iVar5) * fVar28 + (float)in_ECX[0x204];
  fStack_160 = (fVar27 + fStack_160) * fVar28 + (float)in_ECX[0x205] + (float)in_ECX[0x204];
  piStack_1b4 = (int *)0x64d524;
  cVar1 = (**(code **)(*piVar7 + 0x5c))();
  if (cVar1 == '\x01') {
    fVar19 = *(float *)(iStack_174 + 0x3c) + DAT_0099d080;
    fVar21 = fVar19 * fVar21;
    fVar19 = fVar19 * fVar22;
  }
  else {
    fVar19 = fVar22;
  }
  if (fVar21 < fVar19) {
    fVar19 = fVar21;
    fVar22 = fVar21;
  }
  if (fStack_164 < fStack_180) {
    fStack_180 = fStack_164;
  }
  if (fStack_160 < fStack_17c) {
    fStack_17c = fStack_160;
  }
  uStack_10c = 0;
  uStack_108 = 0;
  if (fStack_178 < 0.0) {
    fStack_178 = 0.0;
  }
  if (fStack_150 < 0.0) {
    fStack_150 = 0.0;
  }
  if (fStack_194 < 0.0) {
    fStack_194 = 0.0;
  }
  if (fStack_184 < 0.0) {
    fStack_184 = 0.0;
  }
  if (fVar19 < 0.0) {
    fVar22 = 0.0;
    fVar19 = 0.0;
  }
  if (fVar21 < 0.0) {
    fVar21 = 0.0;
  }
  if (fStack_180 < 0.0) {
    fStack_180 = 0.0;
  }
  if (fStack_164 < 0.0) {
    fStack_164 = 0.0;
  }
  if (fStack_17c < 0.0) {
    fStack_17c = 0.0;
  }
  if (fStack_160 < 0.0) {
    fStack_160 = 0.0;
  }
  iStack_114 = (int)fStack_178;
  iStack_110 = iStack_114;
  if (iStack_114 <= (int)fStack_150) {
    iStack_110 = (int)fStack_150;
  }
  iStack_138 = (int)fStack_194;
  iStack_134 = iStack_138;
  if (iStack_138 <= (int)fStack_184) {
    iStack_134 = (int)fStack_184;
  }
  fStack_12c = (float)(int)fVar19;
  iStack_128 = (int)fStack_12c;
  if ((int)fStack_12c <= (int)fVar21) {
    iStack_128 = (int)fVar21;
  }
  iStack_120 = (int)fStack_180;
  iStack_11c = iStack_120;
  if (iStack_120 <= (int)fStack_164) {
    iStack_11c = (int)fStack_164;
  }
  iStack_16c = (int)fStack_17c;
  iStack_168 = iStack_16c;
  if (iStack_16c <= (int)fStack_160) {
    iStack_168 = (int)fStack_160;
  }
  piStack_1b4 = &iStack_114;
  puStack_1b8 = (undefined1 *)0x64d6e3;
  FUN_0063c3a0();
  piStack_1b4 = &iStack_138;
  puStack_1b8 = (undefined1 *)0x64d6f3;
  FUN_0063c3f0();
  piStack_1b4 = &uStack_10c;
  puStack_1b8 = (undefined1 *)0x64d709;
  (**(code **)(*(int *)in_ECX[0x282] + 0xd8))();
  puStack_1b8 = auStack_130;
  piStack_1bc = (int *)0x64d71f;
  (**(code **)(*(int *)in_ECX[0x282] + 0x9c))();
  piStack_1bc = &iStack_128;
  pfStack_1c0 = (float *)0x64d735;
  (**(code **)(*(int *)in_ECX[0x282] + 0xa0))();
  pfStack_1c0 = &fStack_178;
  iStack_1c4 = 0x64d748;
  (**(code **)(*(int *)in_ECX[0x282] + 0xa4))();
  uVar16 = *(ushort *)((int)fVar22 + 4);
  iVar5 = *(int *)(iVar13 + 8);
  iVar9 = *(int *)(iVar13 + 4);
  iStack_1c4 = 0x64d76b;
  puVar4 = (ushort *)(**(code **)(*(int *)in_ECX[0x282] + 8))();
  fVar19 = *(float *)((int)fStack_180 + 0x94) * (float)uVar16;
  fVar22 = *(float *)((int)fStack_180 + 0x98) * (float)*puVar4;
  iStack_1c4 = (int)(((float)iVar5 + fVar22 + fVar19 + (float)in_ECX[0x22a] + (float)in_ECX[0x229])
                     * (float)(in_ECX[0x22b] + 100) * DAT_009a09b8 *
                    *(float *)((int)fStack_184 + 0x30));
  iStack_1c8 = (int)(((float)iVar9 + fVar22 + fVar19 + (float)in_ECX[0x229]) *
                     (float)(in_ECX[0x22b] + 100) * DAT_009a09b8 *
                    *(float *)((int)fStack_184 + 0x30));
  puStack_1cc = (undefined1 *)0x64d80f;
  (**(code **)(*(int *)in_ECX[0x282] + 0xc0))();
  iVar5 = in_ECX[0x1f9] + in_ECX[0x200];
  if (iVar5 < 0) {
    iVar5 = 0;
LAB_0064d823:
    bVar2 = (byte)iVar5;
    puStack_1b8 = (undefined1 *)CONCAT31(puStack_1b8._1_3_,100);
    if (bVar2 < 0x65) goto LAB_0064d82c;
  }
  else {
    if (iVar5 < 0x4c) goto LAB_0064d823;
    bVar2 = 0x4b;
LAB_0064d82c:
    puStack_1b8 = (undefined1 *)CONCAT31(puStack_1b8._1_3_,bVar2);
  }
  puStack_1cc = puStack_1b8;
  bStack_1d0 = 0;
  uStack_1cf = 0;
  pfStack_1d4 = (float *)0x64d845;
  (**(code **)(*(int *)in_ECX[0x282] + 0xc4))();
  iVar5 = in_ECX[0x1fa] + in_ECX[0x200];
  if (iVar5 < 0) {
    iVar5 = 0;
LAB_0064d859:
    bVar2 = (byte)iVar5;
    pfStack_1c0 = (float *)CONCAT31(pfStack_1c0._1_3_,100);
    if (bVar2 < 0x65) goto LAB_0064d862;
  }
  else {
    if (iVar5 < 0x4c) goto LAB_0064d859;
    bVar2 = 0x4b;
LAB_0064d862:
    pfStack_1c0 = (float *)CONCAT31(pfStack_1c0._1_3_,bVar2);
  }
  pfStack_1d4 = pfStack_1c0;
  iStack_1d8 = 1;
  iStack_1dc = 0x64d87b;
  (**(code **)(*(int *)in_ECX[0x282] + 0xc4))();
  iVar5 = in_ECX[0x1fb] + in_ECX[0x200];
  if (iVar5 < 0) {
    iVar5 = 0;
LAB_0064d88f:
    bVar2 = (byte)iVar5;
    iStack_1c8 = CONCAT31(iStack_1c8._1_3_,100);
    if (bVar2 < 0x65) goto LAB_0064d898;
  }
  else {
    if (iVar5 < 0x4c) goto LAB_0064d88f;
    bVar2 = 0x4b;
LAB_0064d898:
    iStack_1c8 = CONCAT31(iStack_1c8._1_3_,bVar2);
  }
  iStack_1dc = iStack_1c8;
  iStack_1e0._0_1_ = 2;
  iStack_1e0._1_3_ = 0;
  iStack_1e4 = 0x64d8b1;
  (**(code **)(*(int *)in_ECX[0x282] + 0xc4))();
  iVar5 = in_ECX[0x1fc] + in_ECX[0x200];
  if (iVar5 < 0) {
    iVar5 = 0;
LAB_0064d8c5:
    bVar2 = (byte)iVar5;
    bStack_1d0 = 100;
    if (bVar2 < 0x65) goto LAB_0064d8ce;
  }
  else {
    if (iVar5 < 0x4c) goto LAB_0064d8c5;
    bVar2 = 0x4b;
LAB_0064d8ce:
    bStack_1d0 = bVar2;
  }
  iStack_1e4._0_1_ = bStack_1d0;
  iStack_1e4._1_3_ = uStack_1cf;
  iStack_1e8 = 3;
  iStack_1ec = 0x64d8e7;
  (**(code **)(*(int *)in_ECX[0x282] + 0xc4))();
  iVar5 = in_ECX[0x1fd] + in_ECX[0x200];
  if (iVar5 < 0) {
    iVar5 = 0;
LAB_0064d8fb:
    bVar2 = (byte)iVar5;
    iStack_1d8 = CONCAT31(iStack_1d8._1_3_,100);
    if (bVar2 < 0x65) goto LAB_0064d904;
  }
  else {
    if (iVar5 < 0x4c) goto LAB_0064d8fb;
    bVar2 = 0x4b;
LAB_0064d904:
    iStack_1d8 = CONCAT31(iStack_1d8._1_3_,bVar2);
  }
  iStack_1ec = iStack_1d8;
  uStack_1f0 = 4;
  iStack_1f4 = 0x64d91d;
  (**(code **)(*(int *)in_ECX[0x282] + 0xc4))();
  iVar5 = in_ECX[0x1fe];
  if (iVar5 < 0) {
    iVar5 = 0;
LAB_0064d92d:
    bVar2 = (byte)iVar5;
    iStack_1e0._0_1_ = 100;
    if (bVar2 < 0x65) goto LAB_0064d936;
  }
  else {
    if (iVar5 < 0x4c) goto LAB_0064d92d;
    bVar2 = 0x4b;
LAB_0064d936:
    iStack_1e0._0_1_ = bVar2;
  }
  iStack_1f4._0_1_ = (byte)iStack_1e0;
  iStack_1f4._1_3_ = iStack_1e0._1_3_;
  iStack_1f8 = 5;
  iStack_1fc = 0x64d94f;
  (**(code **)(*(int *)in_ECX[0x282] + 0xc4))();
  uVar8 = in_ECX[0x219];
  if ((int)uVar8 < 0) {
    uVar8 = 0;
  }
  else if (0xfa < (byte)uVar8) {
    uVar8 = 0xfa;
  }
  iStack_1e4 = CONCAT31(iStack_1e4._1_3_,(char)uVar8);
  iVar5 = (int)((int)piStack_1b4 * (uVar8 & 0xff)) / 100;
  if (iVar5 < 0) {
    iVar9 = 0;
  }
  else {
    iVar9 = 0xffff;
    if (iVar5 < 0x10000) {
      iVar9 = iVar5;
    }
  }
  iVar5 = (int)(iStack_1b0 * (uVar8 & 0xff)) / 100;
  if (iVar5 < 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0xffff;
    if (iVar5 < 0x10000) {
      iVar6 = iVar5;
    }
  }
  iStack_1fc = iStack_1e4;
  piStack_200 = (int *)0x0;
  piStack_204 = (int *)0x64da37;
  (**(code **)(*(int *)in_ECX[0x282] + 200))();
  iStack_1dc = iVar9;
  if (iVar9 <= iVar6) {
    iStack_1dc = iVar6;
  }
  piStack_204 = &iStack_1e0;
  uStack_208 = 0x64da5a;
  iStack_1e0 = iVar9;
  (**(code **)(*(int *)in_ECX[0x282] + 0xa8))();
  uVar8 = in_ECX[0x21a];
  if ((int)uVar8 < 0) {
    uVar8 = 0;
  }
  else if (0xfa < (byte)uVar8) {
    uVar8 = 0xfa;
  }
  uStack_1f0 = CONCAT31(uStack_1f0._1_3_,(char)uVar8);
  iVar5 = (int)((int)pfStack_1c0 * (uVar8 & 0xff)) / 100;
  if (iVar5 < 0) {
    iVar9 = 0;
  }
  else {
    iVar9 = 0xffff;
    if (iVar5 < 0x10000) {
      iVar9 = iVar5;
    }
  }
  iVar5 = (int)((int)piStack_1bc * (uVar8 & 0xff)) / 100;
  if (iVar5 < 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0xffff;
    if (iVar5 < 0x10000) {
      iVar6 = iVar5;
    }
  }
  uStack_208 = uStack_1f0;
  piStack_20c = (int *)0x1;
  piStack_210 = (int *)0x64dae2;
  (**(code **)(*(int *)in_ECX[0x282] + 200))();
  iStack_1e8 = iVar9;
  if (iVar9 <= iVar6) {
    iStack_1e8 = iVar6;
  }
  piStack_210 = &iStack_1ec;
  piStack_214 = (int *)0x64db05;
  iStack_1ec = iVar9;
  (**(code **)(*(int *)in_ECX[0x282] + 0xac))();
  uVar8 = in_ECX[0x21b];
  if ((int)uVar8 < 0) {
    uVar8 = 0;
  }
  else if (0xfa < (byte)uVar8) {
    uVar8 = 0xfa;
  }
  iStack_1fc = CONCAT31(iStack_1fc._1_3_,(char)uVar8);
  iVar5 = (int)((int)puStack_1cc * (uVar8 & 0xff)) / 100;
  if (iVar5 < 0) {
    iVar9 = 0;
  }
  else {
    iVar9 = 0xffff;
    if (iVar5 < 0x10000) {
      iVar9 = iVar5;
    }
  }
  iVar5 = (int)(iStack_1c8 * (uVar8 & 0xff)) / 100;
  if (iVar5 < 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 0xffff;
    if (iVar5 < 0x10000) {
      iVar6 = iVar5;
    }
  }
  piStack_214 = (int *)iStack_1fc;
  uStack_218 = 2;
  piStack_21c = (int *)0x64db8d;
  (**(code **)(*(int *)in_ECX[0x282] + 200))();
  iStack_1f4 = iVar9;
  if (iVar9 <= iVar6) {
    iStack_1f4 = iVar6;
  }
  piStack_21c = &iStack_1f8;
  uStack_220 = 0x64dbb0;
  iStack_1f8 = iVar9;
  (**(code **)(*(int *)in_ECX[0x282] + 0xb0))();
  uVar8 = in_ECX[0x21c];
  if ((int)uVar8 < 0) {
    uVar8 = 0;
  }
  else if (0xfa < (byte)uVar8) {
    uVar8 = 0xfa;
  }
  uStack_208 = CONCAT31(uStack_208._1_3_,(char)uVar8);
  piVar7 = (int *)((int)(iStack_1d8 * (uVar8 & 0xff)) / 100);
  if ((int)piVar7 < 0) {
    piVar15 = (int *)0x0;
  }
  else {
    piVar15 = (int *)0xffff;
    if ((int)piVar7 < 0x10000) {
      piVar15 = piVar7;
    }
  }
  piVar7 = (int *)((int)((int)pfStack_1d4 * (uVar8 & 0xff)) / 100);
  if ((int)piVar7 < 0) {
    piVar17 = (int *)0x0;
  }
  else {
    piVar17 = (int *)0xffff;
    if ((int)piVar7 < 0x10000) {
      piVar17 = piVar7;
    }
  }
  uStack_220 = uStack_208;
  fStack_224 = 4.2039e-45;
  ppiStack_228 = (int **)0x64dc38;
  (**(code **)(*(int *)in_ECX[0x282] + 200))();
  piStack_200 = piVar15;
  if ((int)piVar15 <= (int)piVar17) {
    piStack_200 = piVar17;
  }
  ppiStack_228 = &piStack_204;
  piStack_22c = (int *)0x64dc5b;
  piStack_204 = piVar15;
  (**(code **)(*(int *)in_ECX[0x282] + 0xb4))();
  uVar8 = in_ECX[0x21d];
  if ((int)uVar8 < 0) {
    uVar8 = 0;
  }
  else if (0xfa < (byte)uVar8) {
    uVar8 = 0xfa;
  }
  piStack_214 = (int *)CONCAT31(piStack_214._1_3_,(char)uVar8);
  piVar7 = (int *)((int)(iStack_1e4 * (uVar8 & 0xff)) / 100);
  if ((int)piVar7 < 0) {
    piVar15 = (int *)0x0;
  }
  else {
    piVar15 = (int *)0xffff;
    if ((int)piVar7 < 0x10000) {
      piVar15 = piVar7;
    }
  }
  piVar7 = (int *)((int)(iStack_1e0 * (uVar8 & 0xff)) / 100);
  if ((int)piVar7 < 0) {
    piVar17 = (int *)0x0;
  }
  else {
    piVar17 = (int *)0xffff;
    if ((int)piVar7 < 0x10000) {
      piVar17 = piVar7;
    }
  }
  piStack_22c = piStack_214;
  uStack_230 = 4;
  ppiStack_234 = (int **)0x64dce3;
  (**(code **)(*(int *)in_ECX[0x282] + 200))();
  piStack_20c = piVar15;
  if ((int)piVar15 <= (int)piVar17) {
    piStack_20c = piVar17;
  }
  ppiStack_234 = &piStack_210;
  iStack_238 = 0x64dd06;
  piStack_210 = piVar15;
  (**(code **)(*(int *)in_ECX[0x282] + 0xb8))();
  iStack_238 = CONCAT31((int3)((uint)piVar15 >> 8),*(undefined1 *)(iStack_1f4 + 0xc5));
  fStack_23c = (float)CONCAT31((int3)((uint)iStack_1f4 >> 8),*(undefined1 *)(iStack_1f4 + 0xc4));
  ppiStack_240 = (int **)0x64dd26;
  (**(code **)(*(int *)in_ECX[0x282] + 0xcc))();
  iVar5 = in_ECX[0x21e] + 0x96;
  if (iVar5 < 0) {
    iVar5 = 0;
LAB_0064dd4e:
    ppiStack_228 = (int **)CONCAT31(ppiStack_228._1_3_,(char)iVar5);
  }
  else {
    if (0xfa < iVar5) {
      iVar5 = 0xfa;
      goto LAB_0064dd4e;
    }
    ppiStack_228 = (int **)CONCAT31(ppiStack_228._1_3_,0xfa);
    if ((byte)iVar5 < 0xfb) goto LAB_0064dd4e;
  }
  ppiStack_240 = ppiStack_228;
  iStack_244 = 0x64dd65;
  (**(code **)(*(int *)in_ECX[0x282] + 0xd4))();
  iStack_244 = in_ECX[0x239];
  fStack_248 = 0.0;
  uStack_24c = 0x64dd7c;
  (**(code **)(*(int *)in_ECX[0x282] + 0xd0))();
  uStack_24c = in_ECX[0x23a];
  uStack_250 = 1;
  iStack_254 = 0x64dd93;
  (**(code **)(*(int *)in_ECX[0x282] + 0xd0))();
  iStack_254 = in_ECX[0x23b];
  uStack_258 = 2;
  piStack_25c = (int *)0x64ddaa;
  (**(code **)(*(int *)in_ECX[0x282] + 0xd0))();
  piStack_25c = (int *)in_ECX[0x23c];
  (**(code **)(*(int *)in_ECX[0x282] + 0xd0))(3);
  (**(code **)(*(int *)in_ECX[0x282] + 0xd0))(4,in_ECX[0x23d]);
  cVar1 = *(char *)(iVar13 + 0x37);
  iVar5 = (**(code **)(**(int **)(in_ECX[0x281] + 0x24) + 0x50))();
  if (in_ECX[0x287] == 0) {
    iVar5 = (int)*(char *)(iVar5 + 0x38);
  }
  else {
    iVar5 = in_ECX[0x288];
  }
  iVar9 = in_ECX[0x209] + 100 + (int)cVar1;
  if (iVar9 < 200) {
    if (-1 < iVar9) goto LAB_0064de20;
    bVar2 = 0;
LAB_0064de29:
    uStack_24c = CONCAT31(uStack_24c._1_3_,bVar2);
  }
  else {
    iVar9 = 200;
LAB_0064de20:
    bVar2 = (byte)iVar9;
    uStack_24c = CONCAT31(uStack_24c._1_3_,200);
    if (bVar2 < 0xc9) goto LAB_0064de29;
  }
  iVar9 = in_ECX[0x20c];
  cVar1 = (**(code **)(*in_ECX + 0x44))();
  if (cVar1 == '\x01') {
    iVar9 = in_ECX[0x289];
  }
  iVar5 = iVar9 + 100 + iVar5;
  if (iVar5 < 200) {
    if (-1 < iVar5) goto LAB_0064de54;
    bVar2 = 0;
LAB_0064de5a:
    bVar14 = bVar2;
  }
  else {
    iVar5 = 200;
LAB_0064de54:
    bVar2 = (byte)iVar5;
    bVar14 = 200;
    if (bVar2 < 0xc9) goto LAB_0064de5a;
  }
  uStack_230 = CONCAT31(uStack_230._1_3_,bVar14);
  piVar7 = (int *)(**(code **)(*(int *)in_ECX[0x281] + 8))();
  piVar7 = (int *)(**(code **)(*piVar7 + 0x2c))();
  fVar19 = (float)(uStack_24c & 0xff);
  if ((uStack_24c & 0xff) < 100) {
    fVar19 = fVar19 * DAT_009a09b8;
    fVar22 = DAT_0099d0f8;
  }
  else {
    fVar19 = (fVar19 - DAT_0099de78) * _DAT_009b832c;
    fVar22 = DAT_0099d080;
  }
  fVar22 = fVar22 - fVar19;
  if (fVar22 <= DAT_0099d0f8) {
    fStack_23c = DAT_009b8328;
    if (fVar22 < DAT_009b8328) goto LAB_0064dedc;
  }
  else {
    fVar22 = DAT_0099d0f8;
  }
  fStack_23c = fVar22;
LAB_0064dedc:
  iVar5 = (**(code **)(*piVar7 + 0x10))();
  if (bVar14 < 100) {
    fStack_248 = (float)bVar14 * _DAT_009b836c + DAT_009a09b8;
  }
  else {
    fStack_248 = ((float)bVar14 - DAT_0099de78) * _DAT_009b836c + DAT_0099d080;
  }
  if (fStack_248 <= DAT_009b8368) {
    if (fStack_248 < DAT_009a09b8) {
      fStack_248 = DAT_009a09b8;
    }
  }
  else {
    fStack_248 = DAT_009b8368;
  }
  fStack_248 = fStack_248 * *(float *)(iVar5 + 0x968) * (float)ppiStack_228[0x1a];
  (**(code **)(*(int *)in_ECX[0x282] + 0xe0))(uStack_24c,fStack_23c);
  if (*(int **)(in_ECX[0x281] + 0x74) == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)(**(code **)(**(int **)(in_ECX[0x281] + 0x74) + 0x14))();
  }
  piVar7 = (int *)(**(code **)(*piVar7 + 8))();
  if (*piVar7 != 3) {
    (**(code **)(*(int *)in_ECX[0x282] + 0xe8))(iStack_238,uStack_250);
  }
  (**(code **)(*(int *)in_ECX[0x282] + 0xe4))(0x3f800000);
  uVar16 = *(ushort *)(iVar13 + 0x34);
  if (9999 < uVar16) {
    uVar16 = 9999;
  }
  uVar3 = *(ushort *)(in_ECX + 0x211);
  if ((int)(uint)uVar16 < (int)(9999 - (uint)uVar3)) {
    if ((int)-(uint)uVar3 < (int)(uint)uVar16) {
      uVar16 = uVar16 + uVar3;
    }
    else {
      uVar16 = 0;
    }
  }
  else {
    uVar16 = 9999;
  }
  uVar3 = FUN_00802534();
  if ((int)(uint)uVar16 < (int)(9999 - (uint)uVar3)) {
    if ((int)-(uint)uVar3 < (int)(uint)uVar16) {
      uStack_258 = CONCAT22(uStack_258._2_2_,uVar16 + uVar3);
    }
    else {
      uStack_258 = (uint)uStack_258._2_2_ << 0x10;
    }
  }
  else {
    uStack_258 = CONCAT22(uStack_258._2_2_,9999);
  }
  (**(code **)(*(int *)in_ECX[0x282] + 0xec))(uStack_258);
  iVar5 = iStack_238;
  uVar8 = (int)(*(float *)(iStack_238 + 0xa8) * fStack_224) + (uint)*(byte *)(iVar13 + 0xc) +
          in_ECX[0x213];
  if ((int)uVar8 < 0) {
    uVar8 = 0;
  }
  else if ((int)(uint)*(byte *)(iStack_238 + 0xa4) < (int)uVar8) {
    uVar8 = (uint)*(byte *)(iStack_238 + 0xa4);
  }
  (**(code **)(*(int *)in_ECX[0x282] + 0xfc))(uVar8);
  piVar7 = (int *)(**(code **)(*piStack_214 + 0x10))();
  iVar9 = (**(code **)(*piVar7 + 4))();
  uVar18 = (uint)*(byte *)(iVar9 + 0x5c) +
           (int)(*(float *)(iVar5 + 0xac) * (float)ppiStack_228) + in_ECX[0x214];
  uVar10 = (uint)*(byte *)(iVar5 + 0xa5);
  if ((int)uVar10 < (int)uVar18) {
    uVar18 = uVar10;
  }
  piVar7 = (int *)(**(code **)(*piStack_214 + 0x10))();
  piStack_25c = (int *)in_ECX[0x282];
  iVar5 = *piStack_25c;
  iVar9 = (**(code **)(*piVar7 + 4))();
  (**(code **)(iVar5 + 0x100))
            (CONCAT31((int3)((uint)extraout_ECX >> 8),((int)uVar18 < 0) + -1) & uVar18,
             *(undefined1 *)(iVar9 + 0x5d));
  FUN_00802534();
  puVar11 = (undefined1 *)FUN_0064ca40();
  (**(code **)(*(int *)in_ECX[0x282] + 0xf0))(*puVar11);
  FUN_00802534();
  puVar11 = (undefined1 *)FUN_0064ca40();
  uVar12 = CONCAT31((int3)((uint)puVar11 >> 8),*puVar11);
  (**(code **)(*(int *)in_ECX[0x282] + 0xf4))(uVar12);
  FUN_00802534();
  uVar31 = (undefined3)(uVar8 >> 8);
  puVar11 = (undefined1 *)FUN_0064ca40();
  (**(code **)(*(int *)in_ECX[0x282] + 0xf8))(CONCAT31(uVar31,*puVar11));
  bVar2 = 100;
  if (*(byte *)(in_ECX + 0x215) < 0x65) {
    bVar2 = *(byte *)(in_ECX + 0x215);
  }
  FUN_0063cab0(bVar2);
  bVar2 = *(byte *)(iVar13 + 0x3b);
  if (0xfa < bVar2) {
    bVar2 = 0xfa;
  }
  bVar14 = *(byte *)(in_ECX + 0x221);
  if ((int)(uint)bVar2 < (int)(0xfa - (uint)bVar14)) {
    if ((int)-(uint)bVar14 < (int)(uint)bVar2) {
      cVar1 = bVar2 + bVar14;
    }
    else {
      cVar1 = '\0';
    }
  }
  else {
    cVar1 = -6;
  }
  (**(code **)(*(int *)in_ECX[0x282] + 0x108))(0,cVar1);
  bVar2 = 0xfa;
  if (*(byte *)(iVar13 + 0x3c) < 0xfb) {
    bVar2 = *(byte *)(iVar13 + 0x3c);
  }
  bVar14 = *(byte *)(in_ECX + 0x222);
  if ((int)(uint)bVar2 < (int)(0xfa - (uint)bVar14)) {
    if ((int)-(uint)bVar14 < (int)(uint)bVar2) {
      cVar1 = bVar2 + bVar14;
    }
    else {
      cVar1 = '\0';
    }
  }
  else {
    cVar1 = -6;
  }
  (**(code **)(*(int *)in_ECX[0x282] + 0x108))(1,cVar1);
  bVar2 = 0xfa;
  if (*(byte *)(iVar13 + 0x3d) < 0xfb) {
    bVar2 = *(byte *)(iVar13 + 0x3d);
  }
  bVar14 = *(byte *)(in_ECX + 0x223);
  uVar30 = (uint3)((uint)uVar12 >> 8);
  if ((int)(uint)bVar2 < (int)(0xfa - (uint)bVar14)) {
    if ((int)-(uint)bVar14 < (int)(uint)bVar2) {
      iVar5 = CONCAT31(uVar30,bVar2 + bVar14);
    }
    else {
      iVar5 = (uint)uVar30 << 8;
    }
  }
  else {
    iVar5 = CONCAT31(uVar30,0xfa);
  }
  (**(code **)(*(int *)in_ECX[0x282] + 0x108))(2,iVar5);
  bVar2 = 0xfa;
  if (*(byte *)(iVar13 + 0x3e) < 0xfb) {
    bVar2 = *(byte *)(iVar13 + 0x3e);
  }
  bVar14 = *(byte *)(in_ECX + 0x224);
  if ((int)(uint)bVar2 < (int)(0xfa - (uint)bVar14)) {
    if ((int)-(uint)bVar14 < (int)(uint)bVar2) {
      cVar1 = bVar2 + bVar14;
    }
    else {
      cVar1 = '\0';
    }
  }
  else {
    cVar1 = -6;
  }
  (**(code **)(*(int *)in_ECX[0x282] + 0x108))(3,cVar1);
  bVar2 = 0xfa;
  if (*(byte *)(iVar13 + 0x3f) < 0xfb) {
    bVar2 = *(byte *)(iVar13 + 0x3f);
  }
  bVar14 = *(byte *)(in_ECX + 0x225);
  if ((int)(uint)bVar2 < (int)(0xfa - (uint)bVar14)) {
    if ((int)-(uint)bVar14 < (int)(uint)bVar2) {
      cVar1 = bVar2 + bVar14;
    }
    else {
      cVar1 = '\0';
    }
  }
  else {
    cVar1 = -6;
  }
  (**(code **)(*(int *)in_ECX[0x282] + 0x108))(4,cVar1);
  uVar12 = CONCAT22(extraout_var,(short)in_ECX[0x232]);
  (**(code **)(*(int *)in_ECX[0x282] + 0x114))
            (CONCAT31((int3)((uint)uVar12 >> 8),(char)in_ECX[0x231]),uVar12);
  uVar12 = CONCAT22(extraout_var_00,(short)in_ECX[0x234]);
  (**(code **)(*(int *)in_ECX[0x282] + 0x118))
            (CONCAT31((int3)((uint)uVar12 >> 8),(char)in_ECX[0x233]),uVar12);
  piStack_25c = (int *)0x0;
  uStack_258 = 0;
  (**(code **)(*(int *)in_ECX[0x282] + 0xd8))(&piStack_25c);
  iVar9 = *(int *)(iVar5 + 0x9c) + in_ECX[0x22c];
  iVar13 = *(int *)(iVar5 + 0xa0) + in_ECX[0x22c];
  if (iVar9 < 0) {
    iVar9 = 0;
  }
  else if (99 < iVar9) {
    iVar9 = 100;
  }
  if (iVar13 < 0) {
    iVar13 = 0;
  }
  else if (99 < iVar13) {
    iVar13 = 100;
  }
  if (iVar13 <= iVar9) {
    iVar13 = iVar9 + 1;
  }
  (**(code **)(*(int *)in_ECX[0x282] + 0xdc))(iVar9,iVar13);
  piVar7 = (int *)(**(code **)(*DAT_00b5abc4 + 8))(*(undefined1 *)(iVar5 + 1));
  if (piVar7 == (int *)0x0) {
    piStack_22c = (int *)((uint)piStack_22c & 0xffffff00);
    uVar12 = FUN_0044a580(&piStack_22c,s_Not_Exist_Rank_Type____d_009d4df8,
                          *(undefined1 *)(iVar5 + 1));
    FUN_00797b80(uVar12);
    (**(code **)(*(int *)in_ECX[0x282] + 0x128))(1);
    (**(code **)(*(int *)in_ECX[0x282] + 300))(0x3f800000);
    return;
  }
  iVar5 = *(int *)in_ECX[0x282];
  iVar13 = (**(code **)(*piVar7 + 4))();
  (**(code **)(iVar5 + 0x128))(*(undefined4 *)(iVar13 + 4));
  iVar5 = *(int *)in_ECX[0x282];
  iVar13 = (**(code **)(*piVar7 + 4))();
  (**(code **)(iVar5 + 300))(*(undefined4 *)(iVar13 + 8));
  bVar2 = 100;
  if (*(byte *)(in_ECX + 0x216) < 0x65) {
    bVar2 = *(byte *)(in_ECX + 0x216);
  }
  (**(code **)(*(int *)in_ECX[0x282] + 0x130))(bVar2);
  return;
}


// ==== FUN_0064e600 @ 0x0064e600 ====

void FUN_0064e600(uint param_1)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int in_ECX;
  undefined2 extraout_var;
  int *piVar7;
  
  piVar7 = *(int **)(*(int *)(in_ECX + 0xa04) + 0x7c);
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)(**(code **)(*piVar7 + 0x14))();
  }
  uVar3 = (**(code **)(*piVar7 + 0x34))();
  if (uVar3 < param_1) {
    sVar2 = (**(code **)(*piVar7 + 0x20))();
    if (sVar2 == 0) {
      (**(code **)(*piVar7 + 0x30))(param_1);
      return;
    }
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 0xa04) + 8))();
    piVar4 = (int *)(**(code **)(*piVar4 + 0x2c))();
    iVar5 = (**(code **)(*piVar4 + 0x10))();
    uVar1 = *(uint *)(iVar5 + 0x95c);
    iVar5 = (**(code **)(*piVar4 + 0x10))();
    if (uVar1 <= param_1 - uVar3) {
      uVar6 = (param_1 - uVar3) / uVar1;
      (**(code **)(*piVar7 + 0x2c))(uVar6 * CONCAT22(extraout_var,*(undefined2 *)(iVar5 + 0x95a)));
      (**(code **)(*piVar7 + 0x30))((uVar6 & 0xffff) * uVar1 + uVar3);
    }
  }
  return;
}


// ==== FUN_0064e6c0 @ 0x0064e6c0 ====

undefined4 FUN_0064e6c0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0xa04) + 0x4c);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if ((iVar2 != 8) && (iVar2 != 9)) {
    piVar1 = *(int **)(*(int *)(in_ECX + 0xa04) + 0x44);
    if (piVar1 == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
    }
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (*(float *)(iVar2 + 4) != DAT_0099cdc8) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_0064e770 @ 0x0064e770 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064e770(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  char cVar8;
  byte *pbVar9;
  float fVar10;
  int *piVar11;
  int iVar12;
  ushort *puVar13;
  int *piVar14;
  int iVar15;
  int iVar16;
  int in_ECX;
  int iVar17;
  int *piVar18;
  float fVar19;
  float unaff_ESI;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fStack_48;
  float fVar25;
  float fStack_20;
  float fStack_14;
  int iStack_8;
  
  (**(code **)(*DAT_00b5a6b8 + 4))();
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x14))();
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x18))();
  piVar18 = *(int **)(*(int *)(in_ECX + 0xa04) + 4);
  if (piVar18 == (int *)0x0) {
    piVar18 = (int *)0x0;
  }
  else {
    piVar18 = (int *)(**(code **)(*piVar18 + 0x18))();
  }
  pbVar9 = (byte *)(**(code **)(*piVar18 + 8))();
  fVar10 = (float)(uint)*pbVar9;
  piVar11 = (int *)(**(code **)(*DAT_00b5abac + 0x10))();
  iVar12 = (**(code **)(*piVar11 + 4))();
  piVar11 = *(int **)(*(int *)(in_ECX + 0xa04) + 0x44);
  if (piVar11 == (int *)0x0) {
    piVar11 = (int *)0x0;
  }
  else {
    piVar11 = (int *)(**(code **)(*piVar11 + 0x18))();
  }
  puVar13 = (ushort *)(**(code **)(**(int **)(in_ECX + 0xa08) + 8))();
  fVar20 = (float)*puVar13 * *(float *)(iVar12 + 0x6c);
  (**(code **)(**(int **)(in_ECX + 0xa08) + 8))();
  fVar21 = ((float)*(ushort *)(iStack_8 + 4) * *(float *)(iVar12 + 0x74) +
           (float)*(int *)(iVar12 + 0x44) + fVar20) *
           ((float)*(int *)(in_ECX + 0x7a8) * DAT_009a09b8 + DAT_0099d080) +
           (float)*(int *)(in_ECX + 0x7a4);
  if ((int)fVar21 == 0) {
    fVar21 = (float)*(int *)(iVar12 + 0x44);
  }
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x74))(fVar21);
  iVar17 = *(int *)(iVar12 + 0x48);
  fVar5 = (float)*(int *)(in_ECX + 0x7c8) * DAT_009a09b8 + DAT_0099d080;
  iVar1 = *(int *)(in_ECX + 0x7c4);
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x78))();
  piVar14 = (int *)(**(code **)(*piVar18 + 0x10))();
  iVar15 = (**(code **)(*piVar14 + 4))();
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x7c))
            ((float)*(int *)(in_ECX + 0x7ac) * DAT_009a09b8 + *(float *)(iVar15 + 0x4c));
  piVar14 = (int *)(**(code **)(*piVar18 + 0x10))();
  iVar15 = (**(code **)(*piVar14 + 4))();
  fVar22 = (float)*(int *)(in_ECX + 0x7cc) * DAT_009a09b8 + *(float *)(iVar15 + 0x50);
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x80))();
  fVar6 = (float)*(int *)(in_ECX + 0x7b4) * DAT_009a09b8;
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x84))();
  fVar7 = (float)*(int *)(in_ECX + 0x7d4) * DAT_009a09b8;
  fVar24 = fVar7;
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x88))(fVar7);
  puVar13 = (ushort *)(**(code **)(**(int **)(in_ECX + 0xa08) + 8))();
  uVar4 = *puVar13;
  iVar15 = (**(code **)(**(int **)(in_ECX + 0xa08) + 8))();
  iVar15 = *(int *)(iVar15 + 0xbc);
  fVar21 = *(float *)(iVar12 + 0xb8);
  fVar19 = *(float *)(iVar12 + 0xbc);
  fVar2 = *(float *)(iVar12 + 0xb4);
  fVar3 = *(float *)(iVar12 + 0xb0);
  iVar12 = *(int *)(in_ECX + 0x904);
  fVar23 = (float)*(int *)(in_ECX + 0x908) * DAT_009a09b8 + DAT_0099d080;
  piVar14 = (int *)(**(code **)(*piVar18 + 0x10))();
  iVar16 = (**(code **)(*piVar14 + 4))();
  fVar25 = *(float *)(iVar16 + 0x54);
  piVar18 = (int *)(**(code **)(*piVar18 + 0x10))();
  iVar16 = (**(code **)(*piVar18 + 4))();
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x94))
            ((float)*(int *)(in_ECX + 0x90c) * DAT_009a09b8 +
             *(float *)(iVar16 + 0x58) * (float)uVar4 + fVar25);
  fVar25 = (float)*(int *)(in_ECX + 0x914) * DAT_009a09b8;
  (**(code **)(**(int **)(in_ECX + 0xa08) + 0x98))();
  fStack_48 = 0.0;
  if (*(int *)(in_ECX + 0xa0c) + 500U < (uint)fVar7) {
    iVar16 = (int)fVar7 - *(int *)(in_ECX + 0xa0c);
    fStack_48 = (float)iVar16;
    if (iVar16 < 0) {
      fStack_48 = fStack_48 + _DAT_0099d104;
    }
    fStack_48 = fStack_48 * DAT_0099d0ec;
    *(float *)(in_ECX + 0xa0c) = fVar7;
  }
  cVar8 = FUN_0064e6c0();
  if (cVar8 == '\x01') {
    (**(code **)(**(int **)(in_ECX + 0xa08) + 0x6c))(0);
    (**(code **)(**(int **)(in_ECX + 0xa08) + 0x70))(0);
    (**(code **)(*piVar11 + 0x14))(0);
    fVar21 = 0.0;
    (**(code **)(*piVar11 + 0x18))(0);
    (**(code **)(*piVar11 + 0x20))(0);
    (**(code **)(*piVar11 + 0x24))(0);
    fVar20 = fVar7;
    (**(code **)(*piVar11 + 0x40))(0,fVar7);
    (**(code **)(**(int **)(in_ECX + 0xa08) + 0x8c))(0);
    (**(code **)(*piVar11 + 0x44))(0,fVar7);
  }
  else {
    iVar16 = (**(code **)(*piVar11 + 0xc))();
    fStack_20 = (unaff_ESI -
                (((float)iVar15 * fVar21 + fVar19 * (float)uVar4 +
                 fVar2 * (fVar5 * ((float)iVar17 + fStack_14 + fVar20) + (float)iVar1)) * fVar3 +
                (float)iVar12) * fVar23) * fStack_48 + *(float *)(iVar16 + 4);
    (**(code **)(*piVar11 + 0xc))();
    if (fVar22 < fStack_20) {
      fStack_20 = fVar22;
    }
    if (fStack_20 <= DAT_0099d080) {
      fStack_20 = DAT_0099d080;
    }
    fVar20 = fStack_20;
    (**(code **)(**(int **)(in_ECX + 0xa08) + 0x6c))();
    (**(code **)(**(int **)(in_ECX + 0xa08) + 0x70))(fStack_48);
    (**(code **)(*piVar11 + 0x14))(fStack_20);
    fVar21 = fVar10;
    (**(code **)(*piVar11 + 0x18))(fVar10);
    (**(code **)(*piVar11 + 0x20))(fVar6);
    (**(code **)(*piVar11 + 0x24))(fVar10);
    fVar20 = fVar20 - fVar10;
    iVar12 = (**(code **)(*piVar11 + 0xc))();
    fVar10 = fVar20 * fVar25 + *(float *)(iVar12 + 0x2c);
    if (fVar6 < fVar10) {
      fVar10 = fVar6;
    }
    if (fVar10 <= DAT_009a09bc) {
      fVar10 = DAT_009a09bc;
    }
    iVar12 = (**(code **)(*piVar11 + 0xc))();
    fVar19 = (float)(*(int *)(iVar12 + 0x34) + 60000);
    iVar12 = (**(code **)(*piVar11 + 0xc))();
    if (*(char *)(iVar12 + 0x38) == '\x01') {
      if ((uint)fVar7 < (uint)fVar19) {
        fVar10 = 0.0;
      }
      else {
        iVar12 = (**(code **)(*piVar11 + 0xc))();
        iVar17 = (int)fVar7 - (int)fVar19;
        fVar10 = (float)iVar17;
        if (iVar17 < 0) {
          fVar10 = fVar10 + _DAT_0099d104;
        }
        fVar10 = fVar10 * DAT_0099d0ec * fVar20 + *(float *)(iVar12 + 0x2c);
        (**(code **)(*piVar11 + 0x3c))(0);
      }
    }
    fVar20 = fVar10;
    (**(code **)(**(int **)(in_ECX + 0xa08) + 0x8c))(fVar10);
    (**(code **)(**(int **)(in_ECX + 0xa08) + 0x90))(fVar24);
    (**(code **)(*piVar11 + 0x2c))(fVar10);
    (**(code **)(*piVar11 + 0x30))(fStack_48);
    FUN_0064e600(fVar7);
  }
  (**(code **)(*piVar11 + 0x1c))(fVar20);
  (**(code **)(*piVar11 + 0x28))(fVar21);
  (**(code **)(*piVar11 + 0x34))(fVar21);
  return;
}


// ==== FUN_0064ed90 @ 0x0064ed90 ====

void FUN_0064ed90(uint param_1)

{
  bool bVar1;
  int *piVar2;
  undefined2 *puVar3;
  undefined4 *in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if ((uint)in_ECX[0x283] < param_1) {
  }
  else {
    param_1 = in_ECX[0x283];
  }
  bVar1 = false;
  if (*(char *)(in_ECX + 0x284) == '\x01') {
    bVar1 = true;
    if (*(int **)(in_ECX[0x281] + 0x48) == (int *)0x0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX[0x281] + 0x48) + 0x28))();
    }
    puVar3 = (undefined2 *)(**(code **)(*piVar2 + 8))();
    (**(code **)(*(int *)in_ECX[0x282] + 0x54))(*puVar3);
  }
  if (*(char *)((int)in_ECX + 0xa11) == '\x01') {
    FUN_0064cfd0(param_1);
LAB_0064ee1c:
    (**(code **)(**(int **)(in_ECX[0x281] + 0x40) + 0x18))(in_ECX + 0xa1);
LAB_0064ee3c:
    (**(code **)(**(int **)(in_ECX[0x281] + 0x10) + 0x30))(in_ECX + 0x141);
  }
  else {
    if (((bVar1) || (*(char *)((int)in_ECX + 0xa13) == '\x01')) ||
       (*(char *)(in_ECX + 0x285) == '\x01')) goto LAB_0064ee1c;
    if (*(char *)((int)in_ECX + 0xa12) == '\x01') goto LAB_0064ee3c;
    if (*(char *)((int)in_ECX + 0xa17) != '\x01') goto LAB_0064eeae;
  }
  FUN_0064ccd0(param_1);
  FUN_0064d040(param_1);
  puVar6 = in_ECX + 0x1e1;
  puVar5 = in_ECX;
  for (iVar4 = 0xa0; puVar5 = puVar5 + 1, iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar6 = puVar6 + 1;
  }
  FUN_00618280(in_ECX + 0xa1);
  FUN_00618280(in_ECX + 0x141);
  FUN_0064d0d0(param_1);
LAB_0064eeae:
  FUN_0064e770(param_1);
  FUN_00797a50(in_ECX + 0x284,0,9);
  return;
}


// ==== FUN_0064eed0 @ 0x0064eed0 ====

void FUN_0064eed0(void)

{
  int *piVar1;
  undefined2 *puVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 unaff_retaddr;
  
  if (*(int **)(in_ECX[0x281] + 0x48) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX[0x281] + 0x48) + 0x28))();
  }
  puVar2 = (undefined2 *)(**(code **)(*piVar1 + 8))();
  (**(code **)(*(int *)in_ECX[0x282] + 0x54))(*puVar2);
  FUN_0064cfd0(unaff_retaddr);
  (**(code **)(**(int **)(in_ECX[0x281] + 0x40) + 0x18))(in_ECX + 0xa1);
  (**(code **)(**(int **)(in_ECX[0x281] + 0x10) + 0x30))(in_ECX + 0x141);
  FUN_0064d040(unaff_retaddr);
  puVar5 = in_ECX + 0x1e1;
  puVar4 = in_ECX;
  for (iVar3 = 0xa0; puVar4 = puVar4 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar5 = puVar5 + 1;
  }
  FUN_00618280(in_ECX + 0xa1);
  FUN_00618280(in_ECX + 0x141);
  FUN_0064d0d0(unaff_retaddr);
  FUN_0064e770(unaff_retaddr);
  in_ECX[0x283] = unaff_retaddr;
  FUN_00797a50(in_ECX + 0x284,0,9);
  return;
}


// ==== FUN_0064efb0 @ 0x0064efb0 ====

void FUN_0064efb0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  uVar1 = FUN_00618fa0();
  *(undefined4 *)(in_ECX + 0xa08) = uVar1;
  *(undefined4 *)(in_ECX + 0xa20) = 0;
  *(undefined4 *)(in_ECX + 0xa24) = 0;
  *(undefined4 *)(in_ECX + 0xa1c) = 0;
  *(undefined2 *)(in_ECX + 0xa28) = 0;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_0064c950();
  FUN_0064eed0(param_1);
  return;
}


// ==== FUN_0064f020 @ 0x0064f020 ====

void FUN_0064f020(byte param_1)

{
  void *in_ECX;
  
  FUN_0064cb20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0064f040 @ 0x0064f040 ====

undefined4 FUN_0064f040(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa04);
}


// ==== FUN_0064f050 @ 0x0064f050 ====

void FUN_0064f050(void)

{
  return;
}


// ==== FUN_0064f060 @ 0x0064f060 ====

undefined4 FUN_0064f060(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0c);
}


// ==== FUN_0064f070 @ 0x0064f070 ====

void FUN_0064f070(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_0064f120 @ 0x0064f120 ====

void FUN_0064f120(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  FUN_00797a50(in_ECX + 0x504,0,0x280);
  FUN_00797a50(in_ECX + 0x784,0,0x280);
  return;
}


// ==== FUN_0064f230 @ 0x0064f230 ====

undefined1 FUN_0064f230(void)

{
  return 0;
}


// ==== FUN_0064f240 @ 0x0064f240 ====

undefined1 FUN_0064f240(void)

{
  return 0;
}


// ==== FUN_0064f280 @ 0x0064f280 ====

void FUN_0064f280(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bf18;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4e6c;
  in_ECX[0x281] = param_1;
  in_ECX[0x282] = 0;
  in_ECX[0x283] = 0;
  FUN_00797a50(in_ECX + 0x284,0,9);
  FUN_0064f120();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0064f2f0 @ 0x0064f2f0 ====

void FUN_0064f2f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_0064f300 @ 0x0064f300 ====

void FUN_0064f300(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa10) = 1;
  return;
}


// ==== FUN_0064f310 @ 0x0064f310 ====

void FUN_0064f310(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa11) = 1;
  return;
}


// ==== FUN_0064f320 @ 0x0064f320 ====

void FUN_0064f320(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa12) = 1;
  return;
}


// ==== FUN_0064f330 @ 0x0064f330 ====

void FUN_0064f330(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa13) = 1;
  return;
}


// ==== FUN_0064f340 @ 0x0064f340 ====

void FUN_0064f340(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa14) = 1;
  return;
}


// ==== FUN_0064f350 @ 0x0064f350 ====

void FUN_0064f350(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa15) = 1;
  return;
}


// ==== FUN_0064f360 @ 0x0064f360 ====

void FUN_0064f360(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa16) = 1;
  return;
}


// ==== FUN_0064f370 @ 0x0064f370 ====

void FUN_0064f370(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xa17) = 1;
  return;
}


// ==== FUN_0064f390 @ 0x0064f390 ====

void FUN_0064f390(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = 0;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_0064f120();
  return;
}


// ==== FUN_0064f3c0 @ 0x0064f3c0 ====

void FUN_0064f3c0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  return;
}


// ==== FUN_0064f520 @ 0x0064f520 ====

void FUN_0064f520(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  FUN_0064f120();
  *(undefined4 *)(in_ECX + 0xa0c) = param_1;
  FUN_00797a50(in_ECX + 0xa10,0,9);
  return;
}


// ==== FUN_0064f570 @ 0x0064f570 ====

void FUN_0064f570(byte param_1)

{
  void *in_ECX;
  
  FUN_0064f2f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0064f590 @ 0x0064f590 ====

undefined4 FUN_0064f590(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x504);
}


// ==== FUN_0064f5a0 @ 0x0064f5a0 ====

undefined4 FUN_0064f5a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x50c);
}


// ==== FUN_0064f5b0 @ 0x0064f5b0 ====

void FUN_0064f5b0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_0064f640 @ 0x0064f640 ====

void FUN_0064f640(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  return;
}


// ==== FUN_0064f6d0 @ 0x0064f6d0 ====

undefined1 FUN_0064f6d0(void)

{
  return 0;
}


// ==== FUN_0064f6e0 @ 0x0064f6e0 ====

undefined1 FUN_0064f6e0(void)

{
  return 0;
}


// ==== FUN_0064f770 @ 0x0064f770 ====

void FUN_0064f770(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098bf38;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d4ebc;
  in_ECX[0x141] = param_1;
  in_ECX[0x142] = 0;
  in_ECX[0x143] = 0;
  FUN_00797a50(in_ECX + 0x144,0,9);
  FUN_00797a50(in_ECX + 1,0,0x280);
  FUN_00797a50(in_ECX + 0xa1,0,0x280);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0064f810 @ 0x0064f810 ====

void FUN_0064f810(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d4b7c;
  return;
}


// ==== FUN_0064f820 @ 0x0064f820 ====

void FUN_0064f820(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x510) = 1;
  return;
}


// ==== FUN_0064f830 @ 0x0064f830 ====

void FUN_0064f830(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x511) = 1;
  return;
}


// ==== FUN_0064f840 @ 0x0064f840 ====

void FUN_0064f840(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x512) = 1;
  return;
}


// ==== FUN_0064f850 @ 0x0064f850 ====

void FUN_0064f850(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x513) = 1;
  return;
}


// ==== FUN_0064f860 @ 0x0064f860 ====

void FUN_0064f860(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x514) = 1;
  return;
}


// ==== FUN_0064f870 @ 0x0064f870 ====

void FUN_0064f870(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x515) = 1;
  return;
}


// ==== FUN_0064f880 @ 0x0064f880 ====

void FUN_0064f880(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x516) = 1;
  return;
}


// ==== FUN_0064f890 @ 0x0064f890 ====

void FUN_0064f890(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x517) = 1;
  return;
}


// ==== FUN_0064f8b0 @ 0x0064f8b0 ====

void FUN_0064f8b0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = 0;
  FUN_00797a50(in_ECX + 0x510,0,9);
  FUN_00797a50(in_ECX + 4,0,0x280);
  FUN_00797a50(in_ECX + 0x284,0,0x280);
  return;
}


// ==== FUN_0064f900 @ 0x0064f900 ====

void FUN_0064f900(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50c) = param_1;
  return;
}


// ==== FUN_0064f950 @ 0x0064f950 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064f950(void)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  float fVar6;
  float fStack_10;
  
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x504) + 0x20))();
  iVar4 = (**(code **)(*piVar3 + 4))();
  fVar1 = (float)(*(int *)(in_ECX + 0x2a4) + *(int *)(iVar4 + 0x28));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x74))();
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x78))();
  uVar5 = (uint)*(ushort *)(iVar4 + 0x2c);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x7c))((float)uVar5 * (float)*(int *)(in_ECX + 0x2ac));
  fVar2 = (float)*(int *)(in_ECX + 0x2b4);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x84))(fVar2);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x88))(0);
  piVar3 = (int *)(**(code **)(**(int **)(*(int *)(in_ECX + 0x504) + 0x44) + 0x14))();
  iVar4 = (**(code **)(*piVar3 + 0xc))();
  if (*(float *)(iVar4 + 4) <= 0.0) {
    *(uint *)(in_ECX + 0x50c) = uVar5;
    return;
  }
  fVar6 = 0.0;
  if (*(int *)(in_ECX + 0x50c) + 500U < uVar5) {
    iVar4 = uVar5 - *(int *)(in_ECX + 0x50c);
    fVar6 = (float)iVar4;
    if (iVar4 < 0) {
      fVar6 = fVar6 + _DAT_0099d104;
    }
    fVar6 = fVar6 * DAT_0099d0ec;
    *(uint *)(in_ECX + 0x50c) = uVar5;
  }
  iVar4 = (**(code **)(*piVar3 + 0xc))();
  fStack_10 = (0.0 - fVar1) * fVar6 + *(float *)(iVar4 + 4);
  if (fVar2 < fStack_10) {
    fStack_10 = fVar2;
  }
  if (fStack_10 <= DAT_0099d080) {
    fStack_10 = DAT_0099d080;
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x6c))(fStack_10);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x70))(0);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x8c))(0);
  (**(code **)(*piVar3 + 0x14))(fStack_10);
  (**(code **)(*piVar3 + 0x20))(0);
  (**(code **)(*piVar3 + 0x1c))(fVar1);
  (**(code **)(*piVar3 + 0x28))(0);
  (**(code **)(*piVar3 + 0x2c))(0);
  (**(code **)(*piVar3 + 0x34))(0);
  return;
}


// ==== FUN_0064fc30 @ 0x0064fc30 ====

void FUN_0064fc30(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x504) + 0x48);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x28))();
  }
  (**(code **)(*piVar1 + 8))();
                    /* WARNING: Could not recover jumptable at 0x0064fc60. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x54))();
  return;
}


// ==== FUN_0064fc70 @ 0x0064fc70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0064fc70(void)

{
  byte bVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  byte bVar8;
  int in_ECX;
  byte bVar9;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint uVar10;
  float fVar11;
  float fVar12;
  uint uStack_114;
  uint uStack_110;
  undefined4 uStack_10c;
  undefined4 uStack_108;
  undefined4 uStack_104;
  undefined4 uStack_100;
  undefined4 uStack_fc;
  undefined4 uStack_f8;
  undefined4 uStack_f4;
  int iStack_f0;
  undefined4 uStack_ec;
  undefined4 uStack_e8;
  undefined4 uStack_e4;
  float fStack_e0;
  undefined4 uStack_dc;
  float fStack_d8;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  uint uStack_c4;
  float fStack_c0;
  undefined4 uStack_bc;
  float fStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined1 uStack_a8;
  undefined3 uStack_a7;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  byte bStack_84;
  undefined3 uStack_83;
  int iStack_80;
  byte bStack_7c;
  undefined3 uStack_7b;
  undefined1 *puStack_78;
  byte bStack_74;
  undefined3 uStack_73;
  uint *puStack_70;
  int iStack_6c;
  int iStack_68;
  undefined1 *puStack_64;
  float *pfStack_60;
  uint *puStack_5c;
  uint *puStack_58;
  undefined4 uStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_38 [4];
  float afStack_34 [2];
  int iStack_2c;
  int iStack_28;
  uint uStack_24;
  uint uStack_20;
  int iStack_1c;
  int iStack_18;
  
  uStack_4c = 0x64fc84;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x504) + 0x20))();
  uStack_4c = 0x64fc8b;
  iVar4 = (**(code **)(*piVar3 + 4))();
  uStack_4c = CONCAT22(extraout_var,*(undefined2 *)(iVar4 + 0x24));
  fStack_50 = 9.27417e-39;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x54))();
  fStack_50 = 0.0;
  uStack_54 = 0x64fcaa;
  uVar5 = (**(code **)(**(int **)(in_ECX + 0x508) + 0x58))();
  uStack_54 = CONCAT31((int3)((uint)uVar5 >> 8),*(undefined1 *)(iVar4 + 0x104));
  puStack_58 = (uint *)0x64fcbf;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xbc))();
  uVar2 = *(ushort *)(iVar4 + 0xfc);
  fVar11 = ((float)*(ushort *)(iVar4 + 0xfe) + (float)*(int *)(in_ECX + 0x308)) *
           (float)(*(int *)(in_ECX + 0x30c) + 100) * DAT_009a09b8;
  puStack_58 = (uint *)0x64fd07;
  iVar6 = (**(code **)(*DAT_00b5a6b8 + 4))();
  fVar11 = *(float *)(iVar6 + 0x10) * fVar11;
  afStack_34[0] =
       ((float)uVar2 + (float)*(int *)(in_ECX + 0x304)) * (float)(*(int *)(in_ECX + 0x30c) + 100) *
       DAT_009a09b8;
  puStack_58 = (uint *)0x64fd55;
  iVar6 = (**(code **)(*DAT_00b5a6b8 + 4))();
  fVar12 = *(float *)(iVar6 + 0x10) * afStack_34[0];
  if (fVar12 < 0.0) {
    fVar12 = 0.0;
  }
  if (fVar11 < 0.0) {
    fVar11 = 0.0;
  }
  iStack_1c = (int)fVar12;
  iStack_18 = iStack_1c;
  if (iStack_1c <= (int)fVar11) {
    iStack_18 = (int)fVar11;
  }
  uVar2 = *(ushort *)(iVar4 + 0x198);
  fVar11 = ((float)*(ushort *)(iVar4 + 0x19a) + (float)*(int *)(in_ECX + 0x308)) *
           (float)(*(int *)(in_ECX + 0x30c) + 100) * DAT_009a09b8;
  puStack_58 = (uint *)0x64fdda;
  iVar6 = (**(code **)(*DAT_00b5a6b8 + 4))();
  fVar11 = *(float *)(iVar6 + 0x10) * fVar11;
  afStack_34[0] =
       ((float)uVar2 + (float)*(int *)(in_ECX + 0x304)) * (float)(*(int *)(in_ECX + 0x30c) + 100) *
       DAT_009a09b8;
  puStack_58 = (uint *)0x64fe28;
  iVar6 = (**(code **)(*DAT_00b5a6b8 + 4))();
  fVar12 = *(float *)(iVar6 + 0x10) * afStack_34[0];
  if (fVar12 < 0.0) {
    fVar12 = 0.0;
  }
  if (fVar11 < 0.0) {
    fVar11 = 0.0;
  }
  iStack_2c = (int)fVar12;
  iStack_28 = iStack_2c;
  if (iStack_2c <= (int)fVar11) {
    iStack_28 = (int)fVar11;
  }
  uStack_24 = (uint)*(ushort *)(iVar4 + 0x100);
  uStack_20 = uStack_24;
  if (uStack_24 <= *(ushort *)(iVar4 + 0x102)) {
    uStack_20 = (uint)*(ushort *)(iVar4 + 0x102);
  }
  puStack_58 = &uStack_24;
  puStack_5c = (uint *)0x64fe96;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd8))();
  puStack_5c = &uStack_20;
  pfStack_60 = (float *)0x64fea9;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x9c))();
  pfStack_60 = afStack_34;
  puStack_64 = (undefined1 *)0x64febc;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xa0))();
  puStack_64 = auStack_38;
  iStack_68 = 0x64fecf;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xa4))();
  uVar2 = *(ushort *)(iVar4 + 0x2e);
  fStack_50 = ((float)*(ushort *)(iVar4 + 0x30) + (float)*(int *)(in_ECX + 0x3a8)) *
              (float)(*(int *)(in_ECX + 0x3ac) + 100) * DAT_009a09b8;
  iStack_68 = 0x64ff11;
  iVar6 = (**(code **)(*DAT_00b5a6b8 + 4))();
  fStack_50 = *(float *)(iVar6 + 0x18) * fStack_50;
  fVar11 = ((float)*(int *)(in_ECX + 0x3a4) + (float)uVar2) *
           (float)(*(int *)(in_ECX + 0x3ac) + 100) * DAT_009a09b8;
  iStack_68 = 0x64ff5f;
  iVar6 = (**(code **)(*DAT_00b5a6b8 + 4))();
  iStack_68 = (int)fStack_50;
  iStack_6c = (int)(*(float *)(iVar6 + 0x18) * fVar11);
  puStack_70 = (uint *)0x64ff84;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc0))();
  iVar6 = (uint)*(byte *)(iVar4 + 0x36) + *(int *)(in_ECX + 0x2e4) + *(int *)(in_ECX + 0x300);
  if (iVar6 < 0) {
    iVar6 = 0;
LAB_0064ff9e:
    bVar1 = (byte)iVar6;
    if (0x4b < bVar1) goto LAB_0064ffa2;
    puStack_5c = (uint *)CONCAT31(puStack_5c._1_3_,100);
    if (bVar1 < 0x65) goto LAB_0064ffaf;
  }
  else {
    if ((byte)iVar6 < 0x65) goto LAB_0064ff9e;
LAB_0064ffa2:
    bVar1 = 0x4b;
LAB_0064ffaf:
    puStack_5c = (uint *)CONCAT31(puStack_5c._1_3_,bVar1);
  }
  puStack_70 = puStack_5c;
  bStack_74 = 0;
  uStack_73 = 0;
  puStack_78 = (undefined1 *)0x64ffc8;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar6 = (uint)*(byte *)(iVar4 + 0x37) + *(int *)(in_ECX + 0x2e8) + *(int *)(in_ECX + 0x300);
  if (iVar6 < 0) {
    iVar6 = 0;
LAB_0064ffe2:
    bVar1 = (byte)iVar6;
    if (0x4b < bVar1) goto LAB_0064ffe6;
    puStack_64 = (undefined1 *)CONCAT31(puStack_64._1_3_,100);
    if (bVar1 < 0x65) goto LAB_0064fff3;
  }
  else {
    if ((byte)iVar6 < 0x65) goto LAB_0064ffe2;
LAB_0064ffe6:
    bVar1 = 0x4b;
LAB_0064fff3:
    puStack_64 = (undefined1 *)CONCAT31(puStack_64._1_3_,bVar1);
  }
  puStack_78 = puStack_64;
  bStack_7c = 1;
  uStack_7b = 0;
  iStack_80 = 0x65000c;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar6 = (uint)*(byte *)(iVar4 + 0x38) + *(int *)(in_ECX + 0x2ec) + *(int *)(in_ECX + 0x300);
  if (iVar6 < 0) {
    iVar6 = 0;
LAB_00650026:
    bVar1 = (byte)iVar6;
    if (0x4b < bVar1) goto LAB_0065002a;
    iStack_6c = CONCAT31(iStack_6c._1_3_,100);
    if (bVar1 < 0x65) goto LAB_00650037;
  }
  else {
    if ((byte)iVar6 < 0x65) goto LAB_00650026;
LAB_0065002a:
    bVar1 = 0x4b;
LAB_00650037:
    iStack_6c = CONCAT31(iStack_6c._1_3_,bVar1);
  }
  iStack_80 = iStack_6c;
  bStack_84 = 2;
  uStack_83 = 0;
  uStack_88 = 0x650050;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar6 = (uint)*(byte *)(iVar4 + 0x39) + *(int *)(in_ECX + 0x2f0) + *(int *)(in_ECX + 0x300);
  if (iVar6 < 0) {
    iVar6 = 0;
LAB_0065006a:
    bVar1 = (byte)iVar6;
    if (0x4b < bVar1) goto LAB_0065006e;
    bStack_74 = 100;
    if (bVar1 < 0x65) goto LAB_0065007b;
  }
  else {
    if ((byte)iVar6 < 0x65) goto LAB_0065006a;
LAB_0065006e:
    bVar1 = 0x4b;
LAB_0065007b:
    bStack_74 = bVar1;
  }
  uStack_88._0_1_ = bStack_74;
  uStack_88._1_3_ = uStack_73;
  uStack_8c = 3;
  uStack_90 = 0x650094;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar6 = (uint)*(byte *)(iVar4 + 0x3a) + *(int *)(in_ECX + 0x2f4) + *(int *)(in_ECX + 0x300);
  if (iVar6 < 0) {
    iVar6 = 0;
LAB_006500ae:
    bVar1 = (byte)iVar6;
    if (0x4b < bVar1) goto LAB_006500b2;
    bStack_7c = 100;
    if (bVar1 < 0x65) goto LAB_006500bf;
  }
  else {
    if ((byte)iVar6 < 0x65) goto LAB_006500ae;
LAB_006500b2:
    bVar1 = 0x4b;
LAB_006500bf:
    bStack_7c = bVar1;
  }
  uStack_90._0_1_ = bStack_7c;
  uStack_90._1_3_ = uStack_7b;
  uStack_94 = 4;
  uStack_98 = 0x6500d8;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  iVar6 = (uint)*(byte *)(iVar4 + 0x35) + *(int *)(in_ECX + 0x2f8);
  if (iVar6 < 0) {
    iVar6 = 0;
LAB_006500ec:
    bVar1 = (byte)iVar6;
    if (0x4b < bVar1) goto LAB_006500f0;
    bStack_84 = 100;
    if (bVar1 < 0x65) goto LAB_006500fd;
  }
  else {
    if ((byte)iVar6 < 0x65) goto LAB_006500ec;
LAB_006500f0:
    bVar1 = 0x4b;
LAB_006500fd:
    bStack_84 = bVar1;
  }
  uStack_98._0_1_ = bStack_84;
  uStack_98._1_3_ = uStack_83;
  uStack_9c = 5;
  uStack_a0 = 0x650116;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xc4))();
  uStack_a0._0_1_ = 0;
  uStack_a0._1_3_ = 0;
  uStack_a4 = 0x650126;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x104))();
  iVar6 = *(int *)(in_ECX + 0x364);
  if (iVar6 < 0) {
    iVar6 = 0;
LAB_0065013d:
    uStack_90._0_1_ = (byte)iVar6;
  }
  else {
    uStack_90._0_1_ = 0xfa;
    if ((byte)iVar6 < 0xfb) goto LAB_0065013d;
  }
  uStack_a4._0_1_ = (byte)uStack_90;
  uStack_a4._1_3_ = uStack_90._1_3_;
  uStack_a8 = 0;
  uStack_a7 = 0;
  uStack_ac = 0x650156;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar6 = *(int *)(in_ECX + 0x368);
  if (iVar6 < 0) {
    iVar6 = 0;
LAB_0065016d:
    uStack_98._0_1_ = (byte)iVar6;
  }
  else {
    uStack_98._0_1_ = 0xfa;
    if ((byte)iVar6 < 0xfb) goto LAB_0065016d;
  }
  uStack_ac._0_1_ = (byte)uStack_98;
  uStack_ac._1_3_ = uStack_98._1_3_;
  uStack_b0._0_1_ = 1;
  uStack_b0._1_3_ = 0;
  uStack_b4 = 0x650186;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar6 = *(int *)(in_ECX + 0x36c);
  if (iVar6 < 0) {
    iVar6 = 0;
LAB_0065019d:
    uStack_a0._0_1_ = (undefined1)iVar6;
  }
  else {
    uStack_a0._0_1_ = 0xfa;
    if ((byte)iVar6 < 0xfb) goto LAB_0065019d;
  }
  uStack_b4._0_1_ = (undefined1)uStack_a0;
  uStack_b4._1_3_ = uStack_a0._1_3_;
  fStack_b8 = 2.8026e-45;
  uStack_bc = 0x6501b6;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar6 = *(int *)(in_ECX + 0x370);
  if (iVar6 < 0) {
    iVar6 = 0;
LAB_006501cd:
    uStack_a8 = (undefined1)iVar6;
  }
  else {
    uStack_a8 = 0xfa;
    if ((byte)iVar6 < 0xfb) goto LAB_006501cd;
  }
  uStack_bc._0_1_ = uStack_a8;
  uStack_bc._1_3_ = uStack_a7;
  fStack_c0 = 4.2039e-45;
  uStack_c4 = 0x6501e6;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  iVar6 = *(int *)(in_ECX + 0x374);
  if (iVar6 < 0) {
    iVar6 = 0;
LAB_006501fd:
    uStack_b0._0_1_ = (undefined1)iVar6;
  }
  else {
    uStack_b0._0_1_ = 0xfa;
    if ((byte)iVar6 < 0xfb) goto LAB_006501fd;
  }
  uStack_c4._0_1_ = (undefined1)uStack_b0;
  uStack_c4._1_3_ = uStack_b0._1_3_;
  uStack_c8 = 4;
  uStack_cc = 0x650216;
  (**(code **)(**(int **)(in_ECX + 0x508) + 200))();
  uStack_cc = 100;
  uStack_d0 = 100;
  uStack_d4 = 0x650228;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xcc))();
  uStack_d4 = 0x96;
  fStack_d8 = 9.276185e-39;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd4))();
  iVar6 = *(int *)(in_ECX + 0x324) + 100;
  if (iVar6 < 200) {
    if (-1 < iVar6) goto LAB_00650250;
    bVar1 = 0;
LAB_00650256:
    bVar9 = bVar1;
  }
  else {
    iVar6 = 200;
LAB_00650250:
    bVar1 = (byte)iVar6;
    bVar9 = 200;
    if (bVar1 < 0xc9) goto LAB_00650256;
  }
  iVar6 = *(int *)(in_ECX + 0x330) + 100;
  uStack_bc = CONCAT31(uStack_bc._1_3_,bVar9);
  if (iVar6 < 200) {
    if (-1 < iVar6) goto LAB_00650271;
    bVar1 = 0;
LAB_00650277:
    bVar8 = bVar1;
  }
  else {
    iVar6 = 200;
LAB_00650271:
    bVar1 = (byte)iVar6;
    bVar8 = 200;
    if (bVar1 < 0xc9) goto LAB_00650277;
  }
  uStack_b4 = CONCAT31(uStack_b4._1_3_,bVar8);
  if (bVar9 < 100) {
    fVar11 = DAT_0099d0f8 - (float)bVar9 * DAT_009a09b8;
  }
  else {
    fVar11 = DAT_0099d080 - ((float)bVar9 - DAT_0099de78) * _DAT_009b832c;
  }
  if (fVar11 <= DAT_0099d0f8) {
    fStack_c0 = DAT_009b8328;
    if (DAT_009b8328 <= fVar11) goto LAB_00650302;
  }
  else {
    fVar11 = DAT_0099d0f8;
LAB_00650302:
    fStack_c0 = fVar11;
  }
  uStack_b0 = *(undefined4 *)(iVar4 + 0x40);
  if (bVar8 < 100) {
    fVar11 = (float)bVar8 * _DAT_009b836c + DAT_009a09b8;
  }
  else {
    fVar11 = ((float)bVar8 - DAT_0099de78) * _DAT_009b836c + DAT_0099d080;
  }
  if (fVar11 <= DAT_009b8368) {
    fStack_b8 = DAT_009a09b8;
    if (fVar11 < DAT_009a09b8) goto LAB_00650360;
  }
  else {
    fVar11 = DAT_009b8368;
  }
  fStack_b8 = fVar11;
LAB_00650360:
  fStack_d8 = fStack_c0;
  uStack_dc = uStack_bc;
  fStack_e0 = 9.27663e-39;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xe0))();
  fStack_e0 = fStack_c0 * fStack_b8;
  uStack_e4 = uStack_bc;
  uStack_e8 = 0x65039d;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xe8))();
  uStack_e8 = 0x3f800000;
  uStack_ec = 0x6503b0;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xe4))();
  uVar10 = (uint)*(ushort *)(in_ECX + 0x344);
  if ((int)(9999 - uVar10) < 1) {
    uVar10 = 9999;
  }
  else {
    uVar10 = (-1 < (int)-uVar10) - 1 & uVar10;
  }
  uStack_ec = 0x6503e5;
  (**(code **)(*DAT_00b5a6b8 + 4))();
  uStack_ec = 0x6503f8;
  uStack_c4 = uVar10;
  uVar2 = FUN_00802534();
  uStack_c8 = CONCAT22(uStack_c8._2_2_,9999);
  if (uVar2 < 10000) {
    uStack_c8 = CONCAT22(uStack_c8._2_2_,uVar2);
  }
  uStack_ec = uStack_c8;
  iStack_f0 = 0x65041d;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xec))();
  bVar1 = 100;
  if (*(byte *)(iVar4 + 0x34) < 0x65) {
    bVar1 = *(byte *)(iVar4 + 0x34);
  }
  bVar9 = *(byte *)(in_ECX + 0x34c);
  if ((int)(uint)bVar1 < (int)(100 - (uint)bVar9)) {
    if ((int)-(uint)bVar9 < (int)(uint)bVar1) {
      fStack_d8 = (float)CONCAT31(fStack_d8._1_3_,bVar1 + bVar9);
    }
    else {
      fStack_d8 = (float)((uint)fStack_d8._1_3_ << 8);
    }
  }
  else {
    fStack_d8 = (float)CONCAT31(fStack_d8._1_3_,100);
  }
  iStack_f0 = (int)fStack_d8;
  uStack_f4 = 0x65046c;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xfc))();
  iVar6 = (uint)*(byte *)(iVar4 + 0x32) + *(int *)(in_ECX + 0x350);
  uStack_f4._0_1_ = *(undefined1 *)(iVar4 + 0x33);
  uStack_f4._1_3_ = (undefined3)((uint)iVar6 >> 8);
  uStack_cc = CONCAT31(uStack_cc._1_3_,(iVar6 < 0) - 1U & (byte)iVar6);
  uStack_f8 = uStack_cc;
  uStack_fc = 0x650499;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x100))();
  bVar1 = *(byte *)(in_ECX + 0x348);
  uStack_d4 = CONCAT31(uStack_d4._1_3_,bVar1);
  if ((int)(100 - (uint)bVar1) < 1) {
    uStack_e4 = CONCAT31(uStack_e4._1_3_,100);
  }
  else {
    uStack_e4 = CONCAT31(uStack_e4._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  uVar5 = uStack_e4;
  uStack_fc = uStack_e4;
  uStack_100 = 0x6504db;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf0))();
  uStack_100 = uVar5;
  uStack_104 = 0x6504ea;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf4))();
  uStack_104 = uVar5;
  uStack_108 = 0x6504f9;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xf8))();
  bVar1 = *(byte *)(in_ECX + 900);
  fStack_e0 = (float)CONCAT31(fStack_e0._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_f4 = CONCAT31(uStack_f4._1_3_,0xfa);
  }
  else {
    uStack_f4 = CONCAT31(uStack_f4._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  uStack_108 = uStack_f4;
  uStack_10c = 0;
  uStack_110 = 0x65053d;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))();
  bVar1 = *(byte *)(in_ECX + 0x388);
  uStack_e8 = CONCAT31(uStack_e8._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_fc = CONCAT31(uStack_fc._1_3_,0xfa);
  }
  else {
    uStack_fc = CONCAT31(uStack_fc._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  uStack_110 = uStack_fc;
  uStack_114 = 1;
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))();
  bVar1 = *(byte *)(in_ECX + 0x38c);
  iStack_f0 = CONCAT31(iStack_f0._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_104 = CONCAT31(uStack_104._1_3_,0xfa);
  }
  else {
    uStack_104 = CONCAT31(uStack_104._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(2,uStack_104);
  bVar1 = *(byte *)(in_ECX + 0x390);
  uStack_f8 = CONCAT31(uStack_f8._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_10c = CONCAT31(uStack_10c._1_3_,0xfa);
  }
  else {
    uStack_10c = CONCAT31(uStack_10c._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(3,uStack_10c);
  bVar1 = *(byte *)(in_ECX + 0x394);
  uStack_100 = CONCAT31(uStack_100._1_3_,bVar1);
  if ((int)(0xfa - (uint)bVar1) < 1) {
    uStack_114 = CONCAT31(uStack_114._1_3_,0xfa);
  }
  else {
    uStack_114 = CONCAT31(uStack_114._1_3_,(-1 < (int)-(uint)bVar1) - 1U & bVar1);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0x108))(4,uStack_114);
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(0,*(undefined4 *)(in_ECX + 0x3e4));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(1,*(undefined4 *)(in_ECX + 1000));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(2,*(undefined4 *)(in_ECX + 0x3ec));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(3,*(undefined4 *)(in_ECX + 0x3f0));
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd0))(4,*(undefined4 *)(in_ECX + 0x3f4));
  uStack_114 = (uint)*(ushort *)(iVar4 + 0x100);
  uStack_110 = uStack_114;
  if (uStack_114 <= *(ushort *)(iVar4 + 0x102)) {
    uStack_110 = (uint)*(ushort *)(iVar4 + 0x102);
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xd8))(&uStack_114);
  iVar7 = (uint)*(byte *)(iVar4 + 0xf4) + *(int *)(in_ECX + 0x3b0);
  iVar6 = (uint)*(byte *)(iVar4 + 0xf5) + *(int *)(in_ECX + 0x3b0);
  if (iVar7 < 0) {
    iVar7 = 0;
  }
  else if (99 < iVar7) {
    iVar7 = 100;
  }
  if (iVar6 < 0) {
    iVar6 = 0;
  }
  else if (99 < iVar6) {
    iVar6 = 100;
  }
  if (iVar6 <= iVar7) {
    iVar6 = iVar7 + 1;
  }
  (**(code **)(**(int **)(in_ECX + 0x508) + 0xdc))(iVar7,iVar6);
  piVar3 = (int *)(**(code **)(*DAT_00b5abc4 + 8))
                            (CONCAT22(extraout_var_00,*(undefined2 *)(iVar4 + 0x1c)));
  if (piVar3 == (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x508) + 0x128))(1);
    (**(code **)(**(int **)(in_ECX + 0x508) + 300))(0x3f800000);
    return;
  }
  iVar4 = **(int **)(in_ECX + 0x508);
  iVar6 = (**(code **)(*piVar3 + 4))();
  (**(code **)(iVar4 + 0x128))(*(undefined4 *)(iVar6 + 4));
  iVar4 = **(int **)(in_ECX + 0x508);
  iVar6 = (**(code **)(*piVar3 + 4))();
  (**(code **)(iVar4 + 300))(*(undefined4 *)(iVar6 + 8));
  return;
}


