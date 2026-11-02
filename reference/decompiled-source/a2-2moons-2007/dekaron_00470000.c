// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x470000-0x47ffff

// ==== FUN_004721d0 @ 0x004721d0 ====

void FUN_004721d0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d860;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a37c4;
  FUN_00472250();
  FUN_0046edb0();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aa08 = (undefined4 *)0x0;
    ExceptionList = pvStack_c;
    return;
  }
  DAT_00b5aa08 = in_ECX;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00472250 @ 0x00472250 ====

void FUN_00472250(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097d815;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x78) = 0;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  pvVar1 = operator_new(4);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00487780();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004849f0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00483060();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00482db0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x18) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00482b40();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x1c) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004827b0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x20) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00482620();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x24) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00481a70();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x28) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 8;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00481950();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x2c) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 9;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00481320();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x34) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047eef0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x30) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0xb;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047ec70();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x38) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0xc;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047e980();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x3c) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0xd;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047e6b0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x40) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0xe;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047e490();
  }
  *(undefined4 *)(in_ECX + 0x44) = uVar2;
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  pvVar1 = operator_new(0x4054);
  local_4 = 0xf;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047d180();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x4c) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047c530();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x50) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x11;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047c360();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x54) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x12;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047c190();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x58) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x13;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047bfd0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x5c) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x14;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047bd60();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x68) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x15;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047bb50();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x6c) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x16;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047b840();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x70) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x17;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047b530();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x60) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x18;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047b390();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 100) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x19;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047b0b0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x74) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x1a;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047af00();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x78) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x1b;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047abd0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x7c) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x1c;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047aa90();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x80) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x1d;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047a790();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x84) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 0x1e;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0047a5e0();
  }
  *(undefined4 *)(in_ECX + 0x88) = uVar2;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00472850 @ 0x00472850 ====

void FUN_00472850(void)

{
  int in_ECX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(in_ECX + 0xc);
  iVar2 = 0x20;
  do {
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
    }
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== FUN_00472880 @ 0x00472880 ====

void FUN_00472880(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a37bc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x110,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_004728a0 @ 0x004728a0 ====

void FUN_004728a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00472880();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004728c0 @ 0x004728c0 ====

void FUN_004728c0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d878;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a37d4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a37bc;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x110,0x100,FUN_00636380,FUN_006ef6d0);
  in_ECX[0x4402] = 0;
  in_ECX[0x4402] = in_ECX[0x4402] + 0x100;
  in_ECX[0x4405] = in_ECX + 2;
  in_ECX[0x4403] = 0;
  in_ECX[0x4404] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[0x43] = puVar1 + 0x46;
    puVar1[0x44] = 0;
    puVar1[0x45] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x44;
  } while (iVar2 != 0);
  in_ECX[0x43ff] = 0;
  in_ECX[0x4400] = 0;
  in_ECX[0x4401] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00472980 @ 0x00472980 ====

undefined4 FUN_00472980(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1100c);
}


// ==== FUN_00472990 @ 0x00472990 ====

undefined4 FUN_00472990(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009a37e8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10c);
    }
    *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(in_ECX + 0x11014);
    *(int *)(in_ECX + 0x1100c) = *(int *)(in_ECX + 0x1100c) + -1;
    *(int *)(in_ECX + 0x11014) = param_2;
  }
  return 0;
}


// ==== FUN_00472a20 @ 0x00472a20 ====

void FUN_00472a20(byte param_1)

{
  void *in_ECX;
  
  FUN_00472a40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00472a40 @ 0x00472a40 ====

void FUN_00472a40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d8a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a37d4;
  local_4 = 1;
  if ((void *)in_ECX[0x4404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009a37bc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x110,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009a378c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x4404]);
  return;
}


// ==== FUN_00472ad0 @ 0x00472ad0 ====

undefined1 * FUN_00472ad0(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined1 *)0x0) {
    if (*(int *)(param_2 + 0x10c) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009a37e8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x10c) = *(int *)(param_2 + 0x10c) + param_1;
    return param_2;
  }
  puVar2 = *(undefined1 **)(in_ECX + 0x11014);
  *(int *)(in_ECX + 0x1100c) = *(int *)(in_ECX + 0x1100c) + 1;
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = operator_new(0x110);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = (undefined1 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    *(undefined4 *)(puVar2 + 0x108) = *(undefined4 *)(in_ECX + 0x11010);
    *(undefined1 **)(in_ECX + 0x11010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x11014) = *(undefined4 *)(puVar2 + 0x104);
  }
  *(undefined4 *)(puVar2 + 0x104) = 0;
  *(int *)(puVar2 + 0x10c) = param_1;
  return puVar2;
}


// ==== FUN_00472ba0 @ 0x00472ba0 ====

void FUN_00472ba0(byte param_1)

{
  void *in_ECX;
  
  FUN_0046ecb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00472bc0 @ 0x00472bc0 ====

void FUN_00472bc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a3860;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00472be0 @ 0x00472be0 ====

void FUN_00472be0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d8c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a3868;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009a3860;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009a37a4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_00472c60 @ 0x00472c60 ====

undefined4 FUN_00472c60(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009a37e8,0xa9);
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


// ==== FUN_00472ce0 @ 0x00472ce0 ====

undefined4 * FUN_00472ce0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009a37e8,0x85);
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


// ==== FUN_00472da0 @ 0x00472da0 ====

void FUN_00472da0(byte param_1)

{
  void *in_ECX;
  
  FUN_00472bc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00472dc0 @ 0x00472dc0 ====

void FUN_00472dc0(byte param_1)

{
  void *in_ECX;
  
  FUN_00472be0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00472de0 @ 0x00472de0 ====

void FUN_00472de0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d8d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a3868;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009a3860;
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


// ==== FUN_00472e90 @ 0x00472e90 ====

void FUN_00472e90(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d8f8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a3884;
  FUN_00472de0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00472ef0 @ 0x00472ef0 ====

void FUN_00472ef0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00472f10(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00472f10 @ 0x00472f10 ====

void FUN_00472f10(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00472f10(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00472f10(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00472f50 @ 0x00472f50 ====

void FUN_00472f50(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00472f70(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00472f70 @ 0x00472f70 ====

void FUN_00472f70(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00472f70(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00472f70(param_1[3]);
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


// ==== FUN_00472fe0 @ 0x00472fe0 ====

uint FUN_00472fe0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = FUN_00473020(param_2);
  if (cVar1 == '\0') {
    cVar1 = FUN_00473020(param_1);
    return (uint)(cVar1 != '\0');
  }
  return 0xffffffff;
}


// ==== FUN_00473020 @ 0x00473020 ====

undefined4 FUN_00473020(int param_1)

{
  char cVar1;
  char *in_ECX;
  uint uVar2;
  
  uVar2 = 0;
  param_1 = param_1 - (int)in_ECX;
  do {
    cVar1 = *in_ECX;
    if (cVar1 < in_ECX[param_1]) {
      return 1;
    }
    if (in_ECX[param_1] < cVar1) {
      return 0;
    }
    if (cVar1 == '\0') {
      return 0;
    }
    uVar2 = uVar2 + 1;
    in_ECX = in_ECX + 1;
  } while (uVar2 < 0x100);
  return 0;
}


// ==== FUN_00473060 @ 0x00473060 ====

void FUN_00473060(byte param_1)

{
  void *in_ECX;
  
  FUN_00473080();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00473080 @ 0x00473080 ====

void FUN_00473080(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097d923;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a3884;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00472f70(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00472be0();
  *in_ECX = &PTR_FUN_009a3734;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004730f0 @ 0x004730f0 ====

void FUN_004730f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a38dc;
  return;
}


// ==== FUN_00473100 @ 0x00473100 ====

void FUN_00473100(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a38dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00473120 @ 0x00473120 ====

void FUN_00473120(int *param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4 + *param_1 * 4) + 4))(param_2);
  return;
}


// ==== FUN_00473140 @ 0x00473140 ====

void FUN_00473140(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d9b8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a38e8;
  FUN_00473200();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aa0c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa0c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_004731b0 @ 0x004731b0 ====

void FUN_004731b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097d9ca;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a38e8;
  local_4 = 0;
  DAT_00b5aa0c = 0;
  FUN_00473410();
  *in_ECX = &PTR_FUN_009a38dc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00473200 @ 0x00473200 ====

void FUN_00473200(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097d99e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  pvVar1 = operator_new(4);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048a200();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 4) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00489ea0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 8) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00489c10();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004893e0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00488c30();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004889f0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x18) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00488370();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x1c) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00488190();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x20) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 8;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004879e0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x24) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 9;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x28) = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_004877c0();
  *(undefined4 *)(in_ECX + 0x28) = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00473410 @ 0x00473410 ====

void FUN_00473410(void)

{
  int *in_ECX;
  int iVar1;
  
  iVar1 = 10;
  do {
    in_ECX = in_ECX + 1;
    if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*in_ECX)(1);
    }
    *in_ECX = 0;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// ==== FUN_00473440 @ 0x00473440 ====

void FUN_00473440(byte param_1)

{
  void *in_ECX;
  
  FUN_004731b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00473460 @ 0x00473460 ====

void FUN_00473460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a38f4;
  return;
}


// ==== FUN_00473470 @ 0x00473470 ====

void FUN_00473470(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a38f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00473490 @ 0x00473490 ====

void FUN_00473490(int *param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4 + *param_1 * 4) + 4))(param_2);
  return;
}


// ==== FUN_004734b0 @ 0x004734b0 ====

void FUN_004734b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097da28;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a3900;
  FUN_00473570();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a9fc = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a9fc = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00473520 @ 0x00473520 ====

void FUN_00473520(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097da3a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a3900;
  local_4 = 0;
  DAT_00b5a9fc = 0;
  FUN_00473680();
  *in_ECX = &PTR_FUN_009a38f4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00473570 @ 0x00473570 ====

void FUN_00473570(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097da0c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  pvVar1 = operator_new(0x2040c);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048b110();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 4) = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048b090();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 8) = uVar2;
  pvVar1 = operator_new(0x8000c);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048adc0();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  pvVar1 = operator_new(0x2040c);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x10) = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0048aa80();
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00473680 @ 0x00473680 ====

void FUN_00473680(void)

{
  int *in_ECX;
  int iVar1;
  
  iVar1 = 4;
  do {
    in_ECX = in_ECX + 1;
    if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*in_ECX)(1);
    }
    *in_ECX = 0;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return;
}


// ==== FUN_004736b0 @ 0x004736b0 ====

void FUN_004736b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00473520();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00473740 @ 0x00473740 ====

uint FUN_00473740(void)

{
  uint in_ECX;
  
  return in_ECX >> 0x18 |
         CONCAT31((int3)in_ECX,(char)(in_ECX >> 8)) << 0x10 | (in_ECX >> 0x10 & 0xff) << 8;
}


// ==== FUN_00473770 @ 0x00473770 ====

void FUN_00473770(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a3f9c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aa10 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aa10 = in_ECX;
  return;
}


// ==== FUN_004737a0 @ 0x004737a0 ====

void FUN_004737a0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aa10 = 0;
  *in_ECX = &PTR_FUN_009a3f7c;
  return;
}


// ==== FUN_004737c0 @ 0x004737c0 ====

undefined4 FUN_004737c0(int *param_1,undefined2 *param_2)

{
  undefined1 uVar1;
  ushort uVar2;
  byte bVar6;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined2 extraout_var;
  byte bVar7;
  uint uVar8;
  undefined2 unaff_SI;
  char *pcVar9;
  uint uStack_124;
  undefined4 uStack_120;
  undefined1 auStack_112 [2];
  undefined1 auStack_110 [4];
  undefined4 uStack_10c;
  undefined1 auStack_108 [4];
  undefined1 local_104 [260];
  
  uStack_120 = (undefined1 *)0x24;
  uStack_124 = 0;
  FUN_00797a50(param_2);
  uStack_120 = local_104;
  uStack_124 = 2;
  uStack_10c._0_2_ = uStack_10c._1_2_;
  iVar3 = (**(code **)(*param_1 + 8))();
  if (iVar3 != 2) {
    FUN_0044a580(auStack_108,&DAT_009a3f74,s_<CONVERTER>_Cannot_Read_____byHe_009a390c);
    (**(code **)(*DAT_00b5a698 + 4))(auStack_108);
    return 0;
  }
  bVar6 = (byte)((ushort)(undefined2)uStack_10c >> 8);
  bVar7 = (byte)(undefined2)uStack_10c;
  uStack_10c = CONCAT22(extraout_var,CONCAT11(bVar7,bVar6));
  *(byte *)((int)param_2 + 0x23) = bVar7 & 1;
  *(byte *)((int)param_2 + 0x21) = bVar6 & 1;
  *(byte *)((int)param_2 + 0x1f) = bVar6 >> 1 & 7;
  *(byte *)(param_2 + 0xf) = bVar6 >> 4 & 7;
  *(byte *)(param_2 + 0x11) = bVar6 >> 7;
  iVar3 = (**(code **)(*param_1 + 8))(2,auStack_110);
  if (iVar3 != 2) {
    FUN_0044a580(auStack_110,&DAT_009a3f74,s_<CONVERTER>_Cannot_Read_____wInd_009a3934);
    (**(code **)(*DAT_00b5a698 + 4))(auStack_110);
    return 0;
  }
  *param_2 = CONCAT11((char)unaff_SI,(char)((ushort)unaff_SI >> 8));
  uVar8 = 0;
  if (*(char *)(param_2 + 0xf) != '\0') {
    do {
      iVar3 = (**(code **)(*param_1 + 8))(2,&uStack_124);
      if (iVar3 != 2) {
        uVar1 = *(undefined1 *)(param_2 + 0xf);
        pcVar9 = s_<CONVERTER>_Cannot_Read_____wSoc_009a3958;
        goto LAB_004739e2;
      }
      bVar7 = (char)uVar8 + 1;
      param_2[uVar8 + 2] = CONCAT11((char)uStack_124,(char)(uStack_124 >> 8));
      uVar8 = (uint)bVar7;
    } while (bVar7 < *(byte *)(param_2 + 0xf));
  }
  uVar8 = 0;
  if (*(char *)((int)param_2 + 0x1f) != '\0') {
    do {
      iVar3 = (**(code **)(*param_1 + 8))(2,&uStack_120);
      if (iVar3 != 2) {
        uVar1 = *(undefined1 *)((int)param_2 + 0x1f);
        pcVar9 = s_<CONVERTER>_Cannot_Read_____Opti_009a3990;
        goto LAB_004739e2;
      }
      iVar3 = (**(code **)(*param_1 + 8))(1,&uStack_124);
      if (iVar3 != 1) {
        uVar1 = *(undefined1 *)((int)param_2 + 0x1f);
        pcVar9 = s_<CONVERTER>_Cannot_Read_____Opti_009a39d0;
LAB_004739e2:
        auStack_110[0] = 0;
        iVar3 = *DAT_00b5a698;
        uVar5 = FUN_0044a580(auStack_110,pcVar9,uVar8,uVar1);
        (**(code **)(iVar3 + 4))(uVar5);
        return 0;
      }
      iVar3 = uVar8 * 2;
      bVar7 = (char)uVar8 + 1;
      uVar8 = (uint)bVar7;
      param_2[iVar3 + 7] = CONCAT11((char)uStack_120,(char)((uint)uStack_120 >> 8));
      *(undefined1 *)(param_2 + iVar3 + 7 + 1) = (undefined1)uStack_124;
    } while (bVar7 < *(byte *)((int)param_2 + 0x1f));
  }
  if (*(char *)((int)param_2 + 0x21) != '\0') {
    iVar3 = (**(code **)(*param_1 + 8))(2,auStack_112 + -10);
    if (iVar3 != 2) {
      FUN_0044a580(auStack_112 + -6,&DAT_009a3f74,s_<CONVERTER>_Cannot_Read_____wSta_009a3a10);
      (**(code **)(*DAT_00b5a698 + 4))(auStack_112 + -6);
      return 0;
    }
    param_2[6] = CONCAT11((char)uStack_124,(char)(uStack_124 >> 8));
    piVar4 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(*param_2);
    if (piVar4 == (int *)0x0) {
      iVar3 = *DAT_00b5a698;
      uVar5 = FUN_0044a580(auStack_112 + -10,s_<CONVERTER>_Cannot_FindItem__ind_009a3a3c,*param_2);
      (**(code **)(iVar3 + 4))(uVar5);
      return 0;
    }
    iVar3 = (**(code **)(*piVar4 + 4))();
    uVar2 = *(ushort *)(iVar3 + 0x76);
    if (uVar2 < (ushort)param_2[6]) {
      iVar3 = *DAT_00b5a698;
      uVar5 = FUN_0044a580(auStack_112 + -10,s_<CONVERTER>_wStackCount_>_wMaxSt_009a3a68,*param_2,
                           param_2[6],uVar2);
      (**(code **)(iVar3 + 4))(uVar5);
      param_2[6] = uVar2;
    }
  }
  return 1;
}


// ==== FUN_00473ac0 @ 0x00473ac0 ====

uint FUN_00473ac0(undefined2 *param_1,int *param_2)

{
  byte bVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 in_ECX;
  undefined2 uVar6;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  undefined2 extraout_var_02;
  byte bVar7;
  char *pcVar8;
  char cVar9;
  undefined4 uStack_114;
  undefined4 auStack_110 [2];
  undefined1 auStack_108 [4];
  undefined4 local_104 [65];
  
  uVar6 = (undefined2)((uint)in_ECX >> 0x10);
  iVar3 = ((((uint)*(byte *)((int)param_1 + 0x23) * 2 |
            CONCAT22(uVar6,(ushort)*(byte *)(param_1 + 0x11))) * 8 | (uint)*(byte *)(param_1 + 0xf))
           * 8 | CONCAT22(uVar6,(ushort)*(byte *)((int)param_1 + 0x1f))) * 2;
  local_104[0] = CONCAT22(uVar6,CONCAT11((byte)iVar3 | *(char *)((int)param_1 + 0x21) != '\0',
                                         (char)((uint)iVar3 >> 8)));
  uVar5 = 0;
  iVar3 = (**(code **)(*param_2 + 8))(2,local_104);
  if (iVar3 == 2) {
    uStack_114 = CONCAT22(extraout_var,CONCAT11((char)*param_1,(char)((ushort)*param_1 >> 8)));
    iVar3 = (**(code **)(*param_2 + 8))(2,&uStack_114);
    if (iVar3 == 2) {
      bVar7 = 0;
      bVar1 = 4;
      uVar6 = extraout_var_00;
      if (*(char *)(param_1 + 0xf) != '\0') {
        do {
          iVar3 = (**(code **)(*param_2 + 8))(2,auStack_110 + -2);
          if (iVar3 != 2) {
            uVar2 = *(undefined1 *)(param_1 + 0xf);
            pcVar8 = s_<CONVERTER>_Cannot_Write_____wSo_009a3b00;
            goto LAB_00473c6e;
          }
          bVar1 = bVar1 + 2;
          bVar7 = bVar7 + 1;
          uVar6 = extraout_var_01;
        } while (bVar7 < *(byte *)(param_1 + 0xf));
      }
      cVar9 = (char)((uint)uVar5 >> 0x10);
      bVar7 = 0;
      if (*(char *)((int)param_1 + 0x1f) != '\0') {
        do {
          iVar3 = (**(code **)(*param_2 + 8))(2,auStack_110 + -2);
          if (iVar3 != 2) {
            uVar2 = *(undefined1 *)((int)param_1 + 0x1f);
            pcVar8 = s_<CONVERTER>_Cannot_Write_____wOp_009a3b38;
            goto LAB_00473c6e;
          }
          iVar3 = (**(code **)(*param_2 + 8))(1,(int)auStack_110 + -9);
          cVar9 = (char)((uint)uVar5 >> 0x10);
          if (iVar3 != 1) {
            uVar2 = *(undefined1 *)((int)param_1 + 0x1f);
            pcVar8 = s_<CONVERTER>_Cannot_Write_____byV_009a3b70;
LAB_00473c6e:
            auStack_108[0] = 0;
            iVar3 = *DAT_00b5a698;
            uVar5 = FUN_0044a580(auStack_108,pcVar8,bVar7,uVar2);
            uVar4 = (**(code **)(iVar3 + 4))(uVar5);
            return uVar4 & 0xffffff00;
          }
          bVar1 = bVar1 + 3;
          bVar7 = bVar7 + 1;
          uVar6 = extraout_var_02;
        } while (bVar7 < *(byte *)((int)param_1 + 0x1f));
      }
      if (*(char *)((int)param_1 + 0x21) == '\0') {
        return (uint)bVar1;
      }
      auStack_110[0] = CONCAT22(uVar6,CONCAT11((char)param_1[6],(char)((ushort)param_1[6] >> 8)));
      iVar3 = (**(code **)(*param_2 + 8))(2,auStack_110);
      if (iVar3 == 2) {
        return (uint)(byte)(cVar9 + 2);
      }
      FUN_0044a580(auStack_110,&DAT_009a3f74,s_<CONVERTER>_Cannot_Write_____wSt_009a3ba8);
      uVar4 = (**(code **)(*DAT_00b5a698 + 4))(auStack_110);
      return uVar4 & 0xffffff00;
    }
    pcVar8 = s_<CONVERTER>_Cannot_Write_____wIn_009a3ad8;
  }
  else {
    pcVar8 = s_<CONVERTER>_Cannot_Write_____wHe_009a3ab0;
  }
  FUN_0044a580(auStack_108,&DAT_009a3f74,pcVar8);
  uVar4 = (**(code **)(*DAT_00b5a698 + 4))(auStack_108);
  return uVar4 & 0xffffff00;
}


// ==== FUN_00473d10 @ 0x00473d10 ====

undefined4 FUN_00473d10(int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined2 unaff_SI;
  undefined2 unaff_DI;
  uint *unaff_retaddr;
  char *pcVar3;
  undefined1 auStack_122 [2];
  undefined4 uStack_120;
  undefined1 auStack_114 [4];
  uint auStack_110 [2];
  undefined1 local_108 [264];
  
  uStack_120 = local_108;
  iVar1 = (**(code **)(*param_1 + 8))();
  if (iVar1 != 4) {
    FUN_0044a580(local_108,&DAT_009a3f74);
    (**(code **)(*DAT_00b5a698 + 4))();
    return 0;
  }
  *unaff_retaddr =
       CONCAT31((int3)auStack_110[0],(char)(auStack_110[0] >> 8)) << 0x10 |
       (auStack_110[0] >> 0x10 & 0xff) << 8 | auStack_110[0] >> 0x18;
  iVar1 = (**(code **)(*param_1 + 8))(2,auStack_122 + 6);
  if (iVar1 == 2) {
    *(undefined2 *)(unaff_retaddr + 1) = 0x400;
    iVar1 = (**(code **)(*param_1 + 8))(2,auStack_122 + 6);
    if (iVar1 == 2) {
      *(ushort *)((int)unaff_retaddr + 6) = CONCAT11((char)unaff_SI,(char)((ushort)unaff_SI >> 8));
      iVar1 = (**(code **)(*param_1 + 8))(2,&uStack_120);
      if (iVar1 == 2) {
        *(ushort *)(unaff_retaddr + 2) = CONCAT11((char)uStack_120,(char)((uint)uStack_120 >> 8));
        iVar1 = (**(code **)(*param_1 + 8))(2,auStack_122 + -6);
        if (iVar1 == 2) {
          *(ushort *)((int)unaff_retaddr + 10) =
               CONCAT11((char)unaff_DI,(char)((ushort)unaff_DI >> 8));
          iVar1 = (**(code **)(*param_1 + 8))(4,auStack_114);
          if (iVar1 == 4) {
            uVar2 = FUN_00473740();
            unaff_retaddr[3] = uVar2;
            return 1;
          }
          FUN_0044a670(s_<CONVERTER_ITEM_SERIAL>_Cannot_R_009a3cd0);
        }
        else {
          FUN_0044a670(s_<CONVERTER_ITEM_SERIAL>_Cannot_R_009a3c9c);
        }
        goto LAB_00473db8;
      }
      pcVar3 = s_<CONVERTER_ITEM_SERIAL>_Cannot_R_009a3c68;
    }
    else {
      pcVar3 = s_<CONVERTER_ITEM_SERIAL>_Cannot_R_009a3c34;
    }
  }
  else {
    pcVar3 = s_<CONVERTER_ITEM_SERIAL>_Cannot_R_009a3c04;
  }
  FUN_0044a580(auStack_110,&DAT_009a3f74,pcVar3);
LAB_00473db8:
  (**(code **)(*DAT_00b5a698 + 4))(auStack_110);
  return 0;
}


// ==== FUN_00473eb0 @ 0x00473eb0 ====

uint FUN_00473eb0(uint *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  char *pcVar3;
  undefined4 uStack_118;
  uint local_114;
  undefined1 auStack_110 [4];
  undefined4 uStack_10c;
  undefined1 auStack_108 [264];
  
  uVar2 = *param_1;
  local_114 = CONCAT31((int3)uVar2,(char)(uVar2 >> 8)) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
              uVar2 >> 0x18;
  iVar1 = (**(code **)(*param_2 + 8))(4,&local_114);
  if (iVar1 == 4) {
    uStack_10c = CONCAT22(extraout_var,CONCAT11((char)param_1[1],(char)(param_1[1] >> 8)));
    iVar1 = (**(code **)(*param_2 + 8))(2,&uStack_10c);
    if (iVar1 == 2) {
      local_114 = CONCAT22(extraout_var_00,
                           CONCAT11((char)*(undefined2 *)((int)param_1 + 6),
                                    (char)((ushort)*(undefined2 *)((int)param_1 + 6) >> 8)));
      iVar1 = (**(code **)(*param_2 + 8))(2,&local_114);
      if (iVar1 == 2) {
        iVar1 = (**(code **)(*param_2 + 8))(2,auStack_110 + -0x10);
        if (iVar1 == 2) {
          uStack_118 = CONCAT22(extraout_var_01,
                                CONCAT11((char)*(undefined2 *)((int)param_1 + 10),
                                         (char)((ushort)*(undefined2 *)((int)param_1 + 10) >> 8)));
          iVar1 = (**(code **)(*param_2 + 8))(2,&uStack_118);
          if (iVar1 != 2) {
            FUN_0044a670(s_<CONVERTER_ITEM_SERIAL>_Cannot_W_009a3dd0);
            uVar2 = (**(code **)(*DAT_00b5a698 + 4))(auStack_110);
            return uVar2 & 0xffffff00;
          }
          uStack_118 = FUN_00473740();
          iVar1 = (**(code **)(*param_2 + 8))(4,&uStack_118);
          if (iVar1 == 4) {
            return 0x10;
          }
          FUN_0044a670(s_<CONVERTER_ITEM_SERIAL>_Cannot_W_009a3e04);
          goto LAB_0047400b;
        }
        pcVar3 = s_<CONVERTER_ITEM_SERIAL>_Cannot_W_009a3d9c;
      }
      else {
        pcVar3 = s_<CONVERTER_ITEM_SERIAL>_Cannot_W_009a3d68;
      }
    }
    else {
      pcVar3 = s_<CONVERTER_ITEM_SERIAL>_Cannot_W_009a3d38;
    }
  }
  else {
    pcVar3 = s_<CONVERTER_ITEM_SERIAL>_Cannot_W_009a3d04;
  }
  FUN_0044a580(auStack_108,&DAT_009a3f74,pcVar3);
LAB_0047400b:
  uVar2 = (**(code **)(*DAT_00b5a698 + 4))(auStack_108);
  return uVar2 & 0xffffff00;
}


// ==== FUN_00474040 @ 0x00474040 ====

uint FUN_00474040(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint unaff_EDI;
  uint *unaff_retaddr;
  char *pcVar3;
  uint uStack_118;
  undefined4 uStack_114;
  uint uStack_10c;
  undefined1 auStack_108 [4];
  undefined1 local_104 [260];
  
  uStack_114 = local_104;
  uStack_118 = 4;
  iVar1 = (**(code **)(*param_1 + 8))();
  if (iVar1 != 4) {
    FUN_0044a580(auStack_108,&DAT_009a3f74,s_<CONVERTER_ITEM_Limit>_Cannot_Re_009a3e38);
    uVar2 = (**(code **)(*DAT_00b5a698 + 4))(auStack_108);
    return uVar2 & 0xffffff00;
  }
  *unaff_retaddr =
       CONCAT31((int3)uStack_10c,(char)(uStack_10c >> 8)) << 0x10 | (uStack_10c >> 0x10 & 0xff) << 8
       | uStack_10c >> 0x18;
  iVar1 = (**(code **)(*param_1 + 8))(4,&uStack_114);
  if (iVar1 == 4) {
    unaff_retaddr[2] =
         CONCAT31((int3)unaff_EDI,(char)(unaff_EDI >> 8)) << 0x10 | (unaff_EDI >> 0x10 & 0xff) << 8
         | unaff_EDI >> 0x18;
    iVar1 = (**(code **)(*param_1 + 8))(4,&uStack_118);
    if (iVar1 == 4) {
      unaff_retaddr[1] =
           CONCAT31((int3)uStack_118,(char)(uStack_118 >> 8)) << 0x10 |
           (uStack_118 >> 0x10 & 0xff) << 8 | uStack_118 >> 0x18;
      return 1;
    }
    pcVar3 = s_<CONVERTER_ITEM_Limit>_Cannot_Re_009a3ea4;
  }
  else {
    pcVar3 = s_<CONVERTER_ITEM_Limit>_Cannot_Re_009a3e6c;
  }
  FUN_0044a580(auStack_108 + -8,&DAT_009a3f74,pcVar3);
  uVar2 = (**(code **)(*DAT_00b5a698 + 4))(auStack_108 + -8);
  return uVar2 & 0xffffff00;
}


// ==== FUN_00474180 @ 0x00474180 ====

uint FUN_00474180(uint *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 auStack_10a [2];
  undefined1 auStack_108 [4];
  uint local_104 [65];
  
  uVar2 = *param_1;
  local_104[0] = CONCAT31((int3)uVar2,(char)(uVar2 >> 8)) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8 |
                 uVar2 >> 0x18;
  iVar1 = (**(code **)(*param_2 + 8))(4,local_104);
  if (iVar1 == 4) {
    iVar1 = (**(code **)(*param_2 + 8))(4,auStack_10a + -10);
    if (iVar1 == 4) {
      iVar1 = (**(code **)(*param_2 + 8))(4,auStack_10a + -6);
      if (iVar1 == 4) {
        return 0xc;
      }
      pcVar3 = s_<CONVERTER_ITEM_Limit>_Cannot_Wr_009a3f44;
    }
    else {
      pcVar3 = s_<CONVERTER_ITEM_Limit>_Cannot_Wr_009a3f0c;
    }
  }
  else {
    pcVar3 = s_<CONVERTER_ITEM_Limit>_Cannot_Wr_009a3edc;
  }
  FUN_0044a580(auStack_108,&DAT_009a3f74,pcVar3);
  uVar2 = (**(code **)(*DAT_00b5a698 + 4))(auStack_108);
  return uVar2 & 0xffffff00;
}


// ==== FUN_00474290 @ 0x00474290 ====

void FUN_00474290(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a3f7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004742b0 @ 0x004742b0 ====

void FUN_004742b0(byte param_1)

{
  void *in_ECX;
  
  FUN_004737a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004742d0 @ 0x004742d0 ====

void FUN_004742d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a3fbc;
  return;
}


// ==== FUN_004742e0 @ 0x004742e0 ====

void FUN_004742e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a3fbc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00474300 @ 0x00474300 ====

void FUN_00474300(void)

{
  FUN_0048b500();
  return;
}


// ==== FUN_00474310 @ 0x00474310 ====

void FUN_00474310(void)

{
  FUN_0048c3b0();
  return;
}


// ==== FUN_00474320 @ 0x00474320 ====

void FUN_00474320(void)

{
  FUN_0048d0f0();
  return;
}


// ==== FUN_00474330 @ 0x00474330 ====

void FUN_00474330(void)

{
  FUN_0048d870();
  return;
}


// ==== FUN_00474340 @ 0x00474340 ====

void FUN_00474340(void)

{
  FUN_0048dca0();
  return;
}


// ==== FUN_00474350 @ 0x00474350 ====

void FUN_00474350(void)

{
  FUN_0048ddf0();
  return;
}


// ==== FUN_00474360 @ 0x00474360 ====

void FUN_00474360(void)

{
  FUN_0048e210();
  return;
}


// ==== FUN_00474370 @ 0x00474370 ====

void FUN_00474370(void)

{
  FUN_0048e770();
  return;
}


// ==== FUN_00474380 @ 0x00474380 ====

void FUN_00474380(void)

{
  FUN_0048ec80();
  return;
}


// ==== FUN_00474390 @ 0x00474390 ====

undefined2 FUN_00474390(void)

{
  return 0;
}


// ==== FUN_004743a0 @ 0x004743a0 ====

void FUN_004743a0(void)

{
  FUN_0048f320();
  return;
}


// ==== FUN_004743b0 @ 0x004743b0 ====

undefined2 FUN_004743b0(void)

{
  return 0;
}


// ==== FUN_004743c0 @ 0x004743c0 ====

void FUN_004743c0(void)

{
  FUN_0048f470();
  return;
}


// ==== FUN_004743d0 @ 0x004743d0 ====

undefined2 FUN_004743d0(void)

{
  return 0;
}


// ==== FUN_004743e0 @ 0x004743e0 ====

void FUN_004743e0(void)

{
  FUN_004905e0();
  return;
}


// ==== FUN_004743f0 @ 0x004743f0 ====

void FUN_004743f0(void)

{
  FUN_00490790();
  return;
}


// ==== FUN_00474400 @ 0x00474400 ====

void FUN_00474400(void)

{
  FUN_00490ae0();
  return;
}


// ==== FUN_00474410 @ 0x00474410 ====

void FUN_00474410(void)

{
  FUN_00490c30();
  return;
}


// ==== FUN_00474420 @ 0x00474420 ====

void FUN_00474420(void)

{
  FUN_00490fa0();
  return;
}


// ==== FUN_00474430 @ 0x00474430 ====

void FUN_00474430(void)

{
  FUN_00491690();
  return;
}


// ==== FUN_00474440 @ 0x00474440 ====

void FUN_00474440(void)

{
  FUN_004919f0();
  return;
}


// ==== FUN_00474450 @ 0x00474450 ====

undefined2 FUN_00474450(void)

{
  return 0;
}


// ==== FUN_00474460 @ 0x00474460 ====

void FUN_00474460(void)

{
  FUN_00492090();
  return;
}


// ==== FUN_00474470 @ 0x00474470 ====

undefined2 FUN_00474470(void)

{
  return 0;
}


// ==== FUN_00474480 @ 0x00474480 ====

void FUN_00474480(void)

{
  FUN_004921e0();
  return;
}


// ==== FUN_00474490 @ 0x00474490 ====

undefined2 FUN_00474490(void)

{
  return 0;
}


// ==== FUN_004744a0 @ 0x004744a0 ====

void FUN_004744a0(void)

{
  FUN_00492840();
  return;
}


// ==== FUN_004744b0 @ 0x004744b0 ====

void FUN_004744b0(void)

{
  FUN_00492b80();
  return;
}


// ==== FUN_004744c0 @ 0x004744c0 ====

void FUN_004744c0(void)

{
  FUN_00492ed0();
  return;
}


// ==== FUN_004744d0 @ 0x004744d0 ====

void FUN_004744d0(void)

{
  FUN_004932a0();
  return;
}


// ==== FUN_004744e0 @ 0x004744e0 ====

void FUN_004744e0(void)

{
  FUN_004935d0();
  return;
}


// ==== FUN_004744f0 @ 0x004744f0 ====

void FUN_004744f0(void)

{
  FUN_00493ac0();
  return;
}


// ==== FUN_00474500 @ 0x00474500 ====

void FUN_00474500(void)

{
  FUN_00493fc0();
  return;
}


// ==== FUN_00474510 @ 0x00474510 ====

void FUN_00474510(void)

{
  FUN_00494280();
  return;
}


// ==== FUN_00474520 @ 0x00474520 ====

void FUN_00474520(void)

{
  FUN_004945c0();
  return;
}


// ==== FUN_00474530 @ 0x00474530 ====

void FUN_00474530(void)

{
  FUN_00494a90();
  return;
}


// ==== FUN_00474540 @ 0x00474540 ====

void FUN_00474540(void)

{
  FUN_00494d90();
  return;
}


// ==== FUN_00474550 @ 0x00474550 ====

void FUN_00474550(void)

{
  FUN_00494f20();
  return;
}


// ==== FUN_00474560 @ 0x00474560 ====

void FUN_00474560(void)

{
  FUN_00495f10();
  return;
}


// ==== FUN_00474570 @ 0x00474570 ====

void FUN_00474570(void)

{
  FUN_004964a0();
  return;
}


// ==== FUN_00474580 @ 0x00474580 ====

void FUN_00474580(void)

{
  FUN_004969b0();
  return;
}


// ==== FUN_00474590 @ 0x00474590 ====

void FUN_00474590(void)

{
  FUN_00496fa0();
  return;
}


// ==== FUN_004745a0 @ 0x004745a0 ====

void FUN_004745a0(void)

{
  FUN_00496f30();
  return;
}


// ==== FUN_004745b0 @ 0x004745b0 ====

void FUN_004745b0(void)

{
  FUN_00497960();
  return;
}


// ==== FUN_004745c0 @ 0x004745c0 ====

void FUN_004745c0(void)

{
  FUN_00497c60();
  return;
}


// ==== FUN_004745d0 @ 0x004745d0 ====

void FUN_004745d0(void)

{
  FUN_004973c0();
  return;
}


// ==== FUN_004745e0 @ 0x004745e0 ====

void FUN_004745e0(void)

{
  FUN_004975b0();
  return;
}


// ==== FUN_004745f0 @ 0x004745f0 ====

void FUN_004745f0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097dc05;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a4084;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048b4b0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048d0a0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048ec30();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048fae0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004919a0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004927f0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00492e80();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[7] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 8;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00493580();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[8] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 9;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00493f70();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[9] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00494570();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[10] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0xb;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00494d60();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0xb] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0xc;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00494ed0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0xc] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0xd;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048dcb0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0xd] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0xe;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048e1c0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0xe] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0xf;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048f330();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0xf] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048f420();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x10] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x11;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004920a0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x11] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x12;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00492190();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x12] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x13;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00490af0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x13] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x14;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00490f50();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x14] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x15;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00495ec0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x15] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x16;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00496960();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x16] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x17;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00496f50();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x17] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x18;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048c360();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x18] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x19;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048d820();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x19] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x1a;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00497fc0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x1a] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x1b;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00490740();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x1b] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x1c;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00497f30();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x1c] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x1d;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00492b30();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x1d] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x1e;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00493250();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x1e] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x1f;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00493a70();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x1f] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x20;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00494230();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x20] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x21;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00494a40();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x21] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x22;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048dda0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x22] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x23;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0048e720();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x23] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x24;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00490be0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x24] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x25;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00491640();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x25] = uVar2;
  pvVar1 = operator_new(4);
  local_4._0_1_ = 0x26;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00496450();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x26] = uVar2;
  pvVar1 = operator_new(4);
  local_4 = CONCAT31(local_4._1_3_,0x27);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00497910();
  }
  in_ECX[0x27] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aa18 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa18 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00474cb0 @ 0x00474cb0 ====

void FUN_00474cb0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097dc17;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a4084;
  DAT_00b5aa18 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[0x27] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x27])(1);
  }
  in_ECX[0x27] = 0;
  if ((undefined4 *)in_ECX[0x26] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x26])(1);
  }
  in_ECX[0x26] = 0;
  if ((undefined4 *)in_ECX[0x25] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x25])(1);
  }
  in_ECX[0x25] = 0;
  if ((undefined4 *)in_ECX[0x24] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x24])(1);
  }
  in_ECX[0x24] = 0;
  if ((undefined4 *)in_ECX[0x23] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x23])(1);
  }
  in_ECX[0x23] = 0;
  if ((undefined4 *)in_ECX[0x22] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x22])(1);
  }
  in_ECX[0x22] = 0;
  if ((undefined4 *)in_ECX[0x21] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x21])(1);
  }
  in_ECX[0x21] = 0;
  if ((undefined4 *)in_ECX[0x20] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x20])(1);
  }
  in_ECX[0x20] = 0;
  if ((undefined4 *)in_ECX[0x1f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1f])(1);
  }
  in_ECX[0x1f] = 0;
  if ((undefined4 *)in_ECX[0x1e] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1e])(1);
  }
  in_ECX[0x1e] = 0;
  if ((undefined4 *)in_ECX[0x1d] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1d])(1);
  }
  in_ECX[0x1d] = 0;
  if ((undefined4 *)in_ECX[0x1c] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1c])(1);
  }
  in_ECX[0x1c] = 0;
  if ((undefined4 *)in_ECX[0x1b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1b])(1);
  }
  in_ECX[0x1b] = 0;
  if ((undefined4 *)in_ECX[0x1a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1a])(1);
  }
  in_ECX[0x1a] = 0;
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
  if ((undefined4 *)in_ECX[0x13] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x13])(1);
  }
  in_ECX[0x13] = 0;
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
  if ((undefined4 *)in_ECX[0xf] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xf])(1);
  }
  in_ECX[0xf] = 0;
  if ((undefined4 *)in_ECX[0xe] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xe])(1);
  }
  in_ECX[0xe] = 0;
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
  *in_ECX = &PTR_FUN_009a3fbc;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00474fa0 @ 0x00474fa0 ====

void FUN_00474fa0(byte param_1)

{
  void *in_ECX;
  
  FUN_00474cb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00474fc0 @ 0x00474fc0 ====

void FUN_00474fc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4148;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00474fe0 @ 0x00474fe0 ====

void FUN_00474fe0(void)

{
  return;
}


// ==== FUN_00474ff0 @ 0x00474ff0 ====

void FUN_00474ff0(void)

{
  return;
}


// ==== FUN_00475000 @ 0x00475000 ====

void FUN_00475000(void)

{
  return;
}


// ==== FUN_00475010 @ 0x00475010 ====

void FUN_00475010(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a415c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aa1c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aa1c = in_ECX;
  return;
}


// ==== FUN_00475040 @ 0x00475040 ====

void FUN_00475040(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aa1c = 0;
  *in_ECX = &PTR_FUN_009a4148;
  return;
}


// ==== FUN_00475060 @ 0x00475060 ====

void FUN_00475060(byte param_1)

{
  void *in_ECX;
  
  FUN_00475040();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00475080 @ 0x00475080 ====

void FUN_00475080(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00475090 @ 0x00475090 ====

void FUN_00475090(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004750b0 @ 0x004750b0 ====

void FUN_004750b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_004750d0 @ 0x004750d0 ====

void FUN_004750d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4190;
  return;
}


// ==== FUN_004750e0 @ 0x004750e0 ====

void FUN_004750e0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uStack_274;
  char acStack_241 [57];
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  uStack_274 = local_100;
  FUN_0044a580();
  uVar2 = 0;
  do {
    local_208[uVar2] = local_100[uVar2];
    if (local_100[uVar2] == '\0') goto LAB_0047512e;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_208[0] = '\0';
LAB_0047512e:
  local_108 = param_1;
  uStack_274 = local_208;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  FUN_00475220();
  iVar4 = (**(code **)(*piVar3 + 0xc))();
  if (iVar4 != 0) {
    uVar2 = 0;
    do {
      FUN_004753b0(0,uVar2);
      uVar5 = (**(code **)(*piVar3 + 0x10))(1,uVar2);
      FUN_00475230(acStack_241,&DAT_009a417c,uVar5);
      uVar6 = 0;
      do {
        cVar1 = acStack_241[uVar6];
        acStack_241[uVar6 - 0x32] = cVar1;
        if (cVar1 == '\0') goto LAB_004751c9;
        uVar6 = uVar6 + 1;
      } while (uVar6 < 0x2d);
      uStack_274._0_2_ = (ushort)(byte)uStack_274;
LAB_004751c9:
      (**(code **)(*DAT_00b5aae0 + 8))(&uStack_274);
      uVar2 = uVar2 + 1;
      uVar6 = (**(code **)(*piVar3 + 0xc))();
    } while (uVar2 < uVar6);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar3);
  return;
}


// ==== FUN_00475200 @ 0x00475200 ====

void FUN_00475200(byte param_1)

{
  void *in_ECX;
  
  FUN_004750b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00475220 @ 0x00475220 ====

void FUN_00475220(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 1) = 0;
  return;
}


// ==== FUN_00475230 @ 0x00475230 ====

char * FUN_00475230(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x2d,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x2d)) {
    param_1[0x2c] = '\0';
  }
  return param_1;
}


// ==== FUN_00475260 @ 0x00475260 ====

void FUN_00475260(char *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int *in_ECX;
  char cVar2;
  int iVar3;
  uint local_204;
  undefined1 local_200 [256];
  undefined1 auStack_100 [256];
  
  if (*param_1 == '\0') {
    local_200[0] = 0;
    uVar1 = (**(code **)(*in_ECX + 0x14))(param_2,param_3);
    FUN_0044a580(local_200,s__s___Cell__d___d__is_NULL_009a422c,uVar1);
    FUN_00797b80(local_200);
    auStack_100[0] = 0;
    uVar1 = FUN_0044a580(auStack_100,s_File___s__Line___d_0099f0a0,
                         s_d__usa_24_0_1_2__develop_share_l_009a41c8,0x102);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  cVar2 = *param_1;
  iVar3 = 0;
  local_204 = 0;
  do {
    if (cVar2 == '\0') {
      return;
    }
    if ((iVar3 == 0) && (cVar2 == '-')) {
      cVar2 = param_1[1];
      iVar3 = 1;
    }
    else if ((cVar2 < '0') || ('9' < cVar2)) {
      local_200[0] = 0;
      uVar1 = (**(code **)(*in_ECX + 0x14))(param_2,param_3,param_1);
      FUN_0044a580(local_200,s__s_Cell___d___d__Can_t_convert_t_009a4198,uVar1);
      FUN_00797b80(local_200);
      auStack_100[0] = 0;
      uVar1 = FUN_0044a580(auStack_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009a41c8,0x126);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    else {
      cVar2 = param_1[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
    local_204 = local_204 + 1;
  } while (local_204 < 0x100);
  return;
}


// ==== FUN_004753b0 @ 0x004753b0 ====

uint FUN_004753b0(undefined4 param_1,undefined4 param_2)

{
  char *_Str;
  undefined4 uVar1;
  uint uVar2;
  int *in_ECX;
  undefined1 auStack_102 [258];
  
  _Str = (char *)(**(code **)(*in_ECX + 0x10))(param_1,param_2);
  if ((*_Str == '-') && (_Str[1] != '\0')) {
    uVar1 = (**(code **)(*in_ECX + 0x14))(param_1,param_2,_Str);
    uVar1 = FUN_0044a580(auStack_102 + -6,s_GetByte_Overflow____s___d___d____009a4248,uVar1);
    FUN_00797b80(uVar1);
    uVar1 = FUN_0044a580(auStack_102 + -6,s_File___s__Line___d_0099f0a0,
                         s_d__usa_24_0_1_2__develop_share_l_009a41c8,0x82);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00475260(_Str,param_1,param_2);
  uVar2 = 0;
  do {
    if (_Str[uVar2] == '\0') {
      if (uVar2 == 0) {
        return 0;
      }
      uVar2 = _atol(_Str);
      if (0xff < uVar2) {
        uVar1 = (**(code **)(*in_ECX + 0x14))(param_1,param_2,_Str);
        uVar1 = FUN_0044a580(auStack_102 + -6,s_GetByte_Overflow____s___d___d____009a4248,uVar1);
        FUN_00797b80(uVar1);
        uVar1 = FUN_0044a580(auStack_102 + -6,s_File___s__Line___d_0099f0a0,
                             s_d__usa_24_0_1_2__develop_share_l_009a41c8,0x91);
        FUN_00797b80(uVar1);
        FUN_00797a40();
        uVar2 = uVar2 & 0xff;
      }
      return uVar2;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  return 0;
}


// ==== FUN_004754f0 @ 0x004754f0 ====

void FUN_004754f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00475510 @ 0x00475510 ====

void FUN_00475510(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4284;
  return;
}


// ==== FUN_00475520 @ 0x00475520 ====

void FUN_00475520(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 auStack_246 [62];
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a427c);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0047556e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0047556e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_004756e0(0,1);
  FUN_004756e0(1,1);
  FUN_004756e0(2,1);
  FUN_004756e0(3,1);
  FUN_004756e0(4,1);
  FUN_004756e0(5,1);
  FUN_004756e0(6,1);
  FUN_004756e0(7,1);
  FUN_004756e0(8,1);
  FUN_004756e0(9,1);
  FUN_004756e0(10,1);
  FUN_004756e0(0xb,1);
  FUN_004756e0(0xc,1);
  FUN_004756e0(0xd,1);
  FUN_004756e0(0xe,1);
  FUN_004756e0(0xf,1);
  (**(code **)(*DAT_00b5aae4 + 8))(auStack_246 + -6);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_004756c0 @ 0x004756c0 ====

void FUN_004756c0(byte param_1)

{
  void *in_ECX;
  
  FUN_004754f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004756e0 @ 0x004756e0 ====

long FUN_004756e0(undefined4 param_1,undefined4 param_2)

{
  char *_Str;
  undefined4 uVar1;
  uint uVar2;
  long lVar3;
  int *in_ECX;
  undefined1 auStack_fe [254];
  
  _Str = (char *)(**(code **)(*in_ECX + 0x10))(param_1,param_2);
  if ((*_Str == '-') && (_Str[1] != '\0')) {
    uVar1 = (**(code **)(*in_ECX + 0x14))(param_1,param_2,_Str);
    uVar1 = FUN_0044a580(auStack_fe + -10,s_GetDword_Overflow____s___d___d____009a428c,uVar1);
    FUN_00797b80(uVar1);
    uVar1 = FUN_0044a580(auStack_fe + -10,s_File___s__Line___d_0099f0a0,
                         s_d__usa_24_0_1_2__develop_share_l_009a41c8,0xc2);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00475260(_Str,param_1,param_2);
  uVar2 = 0;
  do {
    if (_Str[uVar2] == '\0') {
      if (uVar2 == 0) {
        return 0;
      }
      lVar3 = _atol(_Str);
      return lVar3;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  return 0;
}


// ==== FUN_004757c0 @ 0x004757c0 ====

void FUN_004757c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_004757d0 @ 0x004757d0 ====

void FUN_004757d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a42cc;
  return;
}


// ==== FUN_004757e0 @ 0x004757e0 ====

void FUN_004757e0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  void *pvVar4;
  void *pvVar5;
  int *piVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int *unaff_EBP;
  uint unaff_ESI;
  int *unaff_EDI;
  int iVar10;
  undefined2 auStack_328 [2];
  undefined4 uStack_324;
  undefined4 uStack_320;
  undefined4 uStack_31c;
  char local_314 [256];
  undefined4 local_214;
  undefined1 local_210;
  undefined1 local_20f;
  undefined1 local_20e;
  char local_20c [504];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097dc3e;
  pvStack_c = ExceptionList;
  local_314[0] = '\0';
  ExceptionList = &pvStack_c;
  FUN_0044a580(local_20c,&DAT_009a42c4,s_Result_009a42b8);
  uVar2 = 0;
  do {
    local_314[uVar2] = local_20c[uVar2];
    if (local_20c[uVar2] == '\0') goto LAB_00475840;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_314[0] = '\0';
LAB_00475840:
  local_214 = param_1;
  local_210 = 10;
  local_20f = 0x2c;
  local_20e = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_314);
  pvVar4 = (void *)(**(code **)(*piVar3 + 0xc))();
  iVar10 = 1;
  if ((int)pvVar4 < 2) {
LAB_00475a3d:
    (**(code **)(*DAT_00b5aa34 + 0xc))(piVar3);
    ExceptionList = pvStack_14;
    return;
  }
LAB_00475896:
  piVar6 = (int *)0x0;
  pvVar5 = operator_new(0x20);
  puStack_8 = (undefined1 *)0x0;
  if (pvVar5 != (void *)0x0) {
    piVar6 = (int *)FUN_005de990();
  }
  puStack_8 = (undefined1 *)0xffffffff;
  auStack_328[0] = FUN_00475a90(0,iVar10);
  uStack_324 = FUN_004756e0(1,iVar10);
  uStack_320 = FUN_004756e0(2,iVar10);
  uStack_31c = FUN_004756e0(3,iVar10);
  (**(code **)(*piVar6 + 0xc))(auStack_328);
  uVar2 = (**(code **)(*piVar3 + 8))();
  if (4 < uVar2) {
LAB_00475940:
    FUN_0044a580(&local_214,&DAT_009a42c4,&DAT_009a42bf);
    pcVar7 = (char *)(**(code **)(*piVar3 + 0x10))(4,iVar10);
    uVar2 = 0;
    iVar1 = 0xf8 - (int)pcVar7;
    do {
      if (*pcVar7 != pcVar7[(int)(local_314 + iVar1)]) {
        FUN_0044a580(local_20c + 0xf0,&DAT_009a42c4,&DAT_009a42c0);
        pcVar7 = (char *)(**(code **)(*piVar3 + 0x10))(5,iVar10);
        uVar2 = 0;
        iVar1 = 0xf0 - (int)pcVar7;
        goto LAB_004759c0;
      }
      if (*pcVar7 == '\0') break;
      uVar2 = uVar2 + 1;
      pcVar7 = pcVar7 + 1;
    } while (uVar2 < 0x100);
    goto LAB_004759fe;
  }
  goto LAB_00475a27;
  while( true ) {
    if (*pcVar7 == '\0') break;
    uVar2 = uVar2 + 1;
    pcVar7 = pcVar7 + 1;
    if (0xff < uVar2) break;
LAB_004759c0:
    if (*pcVar7 != pcVar7[(int)(local_20c + iVar1)]) {
      uVar8 = FUN_00475a90(unaff_ESI,iVar10);
      uVar9 = FUN_004756e0(5,iVar10);
      (**(code **)(*unaff_EDI + 4))(uVar8,uVar9);
      break;
    }
  }
LAB_004759fe:
  piVar6 = (int *)((int)unaff_EBP + 2);
  unaff_ESI = (uint)piVar6 & 0xffff;
  uVar2 = (**(code **)(*piVar3 + 8))();
  unaff_EBP = piVar6;
  if (uVar2 <= unaff_ESI) goto code_r0x00475a1f;
  goto LAB_00475940;
code_r0x00475a1f:
  pvVar4 = pvVar5;
LAB_00475a27:
  (**(code **)*DAT_00b5aae8)(piVar6);
  iVar10 = iVar10 + 1;
  if ((int)pvVar4 <= iVar10) goto LAB_00475a3d;
  goto LAB_00475896;
}


// ==== FUN_00475a70 @ 0x00475a70 ====

void FUN_00475a70(byte param_1)

{
  void *in_ECX;
  
  FUN_004757c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00475a90 @ 0x00475a90 ====

uint FUN_00475a90(undefined4 param_1,undefined4 param_2)

{
  char *_Str;
  undefined4 uVar1;
  uint uVar2;
  undefined2 extraout_var;
  int *in_ECX;
  undefined1 auStack_102 [258];
  
  _Str = (char *)(**(code **)(*in_ECX + 0x10))(param_1,param_2);
  if ((*_Str == '-') && (_Str[1] != '\0')) {
    uVar1 = (**(code **)(*in_ECX + 0x14))(param_1,param_2,_Str);
    uVar1 = FUN_0044a580(auStack_102 + -6,s_GetWord_Overflow____s___d___d____009a42d4,uVar1);
    FUN_00797b80(uVar1);
    uVar1 = FUN_0044a580(auStack_102 + -6,s_File___s__Line___d_0099f0a0,
                         s_d__usa_24_0_1_2__develop_share_l_009a41c8,0xa2);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00475260(_Str,param_1,param_2);
  uVar2 = 0;
  do {
    if (_Str[uVar2] == '\0') {
      if (uVar2 == 0) {
        return 0;
      }
      uVar2 = _atol(_Str);
      if (0xffff < uVar2) {
        uVar1 = (**(code **)(*in_ECX + 0x14))(param_1,param_2,_Str);
        uVar1 = FUN_0044a580(auStack_102 + -6,s_GetWord_Overflow____s___d___d____009a42d4,uVar1);
        FUN_00797b80(uVar1);
        uVar1 = FUN_0044a580(auStack_102 + -6,s_File___s__Line___d_0099f0a0,
                             s_d__usa_24_0_1_2__develop_share_l_009a41c8,0xb1);
        FUN_00797b80(uVar1);
        FUN_00797a40();
        uVar2 = CONCAT22(extraout_var,(short)uVar2);
      }
      return uVar2;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  return 0;
}


// ==== FUN_00475bd0 @ 0x00475bd0 ====

void FUN_00475bd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00475be0 @ 0x00475be0 ====

void FUN_00475be0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4310;
  return;
}


// ==== FUN_00475bf0 @ 0x00475bf0 ====

void FUN_00475bf0(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_20e [6];
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4308);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00475c3e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00475c3e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  iVar3 = (**(code **)(*piVar2 + 0xc))();
  iVar4 = 1;
  if (1 < iVar3) {
    do {
      FUN_00475a90(0,iVar4);
      FUN_00475a90(1,iVar4);
      FUN_00475a90(2,iVar4);
      (**(code **)*DAT_00b5aaf0)(auStack_20e + -6);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar2);
  return;
}


// ==== FUN_00475cf0 @ 0x00475cf0 ====

void FUN_00475cf0(byte param_1)

{
  void *in_ECX;
  
  FUN_00475bd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00475d10 @ 0x00475d10 ====

void FUN_00475d10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00475d20 @ 0x00475d20 ====

void FUN_00475d20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4330;
  return;
}


// ==== FUN_00475d30 @ 0x00475d30 ====

void FUN_00475d30(undefined4 param_1)

{
  int iVar1;
  byte bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  void *pvVar8;
  char *pcVar9;
  undefined4 uVar10;
  uint uVar11;
  ushort uVar12;
  ushort uVar13;
  int iVar14;
  int *piVar15;
  uint uStack_4c8;
  int *piStack_4c4;
  undefined2 uStack_4b8;
  undefined2 uStack_4b6;
  ushort uStack_4b4;
  ushort uStack_4b2;
  undefined2 auStack_4b0 [12];
  undefined2 auStack_498 [12];
  undefined2 uStack_480;
  undefined2 uStack_47e;
  undefined2 uStack_47c;
  undefined2 uStack_47a;
  undefined2 uStack_478;
  undefined2 uStack_476;
  undefined2 uStack_474;
  undefined2 uStack_472;
  undefined2 uStack_470;
  undefined4 uStack_46c;
  char local_464 [256];
  undefined4 local_364;
  char local_360 [4];
  char local_35c [332];
  char acStack_210 [248];
  char acStack_118 [8];
  undefined1 auStack_110 [252];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097dc5e;
  pvStack_c = ExceptionList;
  local_464[0] = '\0';
  ExceptionList = &pvStack_c;
  FUN_0044a580(local_35c,&DAT_009a4328,s_Field_009a431c);
  uVar5 = 0;
  do {
    local_464[uVar5] = local_35c[uVar5];
    if (local_35c[uVar5] == '\0') goto LAB_00475d8f;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  local_464[0] = '\0';
LAB_00475d8f:
  local_364 = param_1;
  local_360[0] = '\n';
  local_360[1] = 0x2c;
  local_360[2] = 1;
  piVar6 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_464);
  FUN_004761a0();
  iVar7 = (**(code **)(*piVar6 + 0xc))();
  iVar14 = 1;
  if (1 < iVar7) {
    do {
      pvVar8 = operator_new(0x58);
      puStack_8 = (undefined1 *)0x0;
      if (pvVar8 == (void *)0x0) {
        piStack_4c4 = (int *)0x0;
      }
      else {
        piStack_4c4 = (int *)FUN_005df370();
      }
      puStack_8 = (undefined1 *)0xffffffff;
      FUN_004761a0();
      uStack_4b8 = FUN_00475a90(0,iVar14);
      uStack_4b6 = FUN_00475a90(1,iVar14);
      bVar2 = FUN_004753b0(2,iVar14);
      uStack_4b4 = (ushort)bVar2;
      bVar2 = FUN_004753b0(3,iVar14);
      uStack_4b2 = (ushort)bVar2;
      uStack_46c = FUN_004756e0(4,iVar14);
      uStack_480 = FUN_00475a90(5,iVar14);
      uStack_47e = FUN_00475a90(6,iVar14);
      uStack_47c = FUN_00475a90(7,iVar14);
      uStack_47a = FUN_00475a90(8,iVar14);
      uStack_478 = FUN_00475a90(9,iVar14);
      uStack_476 = FUN_00475a90(10,iVar14);
      uStack_474 = FUN_00475a90(0xb,iVar14);
      uStack_472 = FUN_00475a90(0xc,iVar14);
      uStack_470 = FUN_00475a90(0xd,iVar14);
      uStack_4c8 = 0;
      uVar12 = 0xe;
      do {
        FUN_0044a580(local_360,&DAT_009a4328,&DAT_009a4322);
        pcVar9 = (char *)(**(code **)(*piVar6 + 0x10))(uVar12,iVar14);
        piVar15 = (int *)0x0;
        iVar1 = -(int)pcVar9;
        do {
          if (*pcVar9 != pcVar9[(int)(local_360 + iVar1)]) {
            uVar3 = FUN_00475a90(uVar12,iVar14);
            piVar15 = (int *)FUN_00475a90(uVar12 + 1,iVar14);
            uVar4 = FUN_00475a90(uVar12 + 2,iVar14);
            uVar5 = uStack_4c8 & 0xffff;
            auStack_4b0[uVar5 * 3] = uVar3;
            uStack_4c8 = uStack_4c8 + 1;
            auStack_4b0[uVar5 * 3 + 1] = (short)piVar15;
            auStack_4b0[uVar5 * 3 + 2] = uVar4;
            uVar13 = uVar12 + 2;
            break;
          }
          uVar13 = uVar12;
          if (*pcVar9 == '\0') break;
          piVar15 = (int *)((int)piVar15 + 1);
          pcVar9 = pcVar9 + 1;
        } while (piVar15 < (int *)0x100);
        uVar12 = uVar13 + 1;
      } while (uVar12 < 0x1a);
      uStack_4c8 = 0;
      for (; uVar12 < (ushort)(uVar13 + 0xd); uVar12 = uVar12 + 1) {
        FUN_0044a580(acStack_210,&DAT_009a4328,&DAT_009a4323);
        pcVar9 = (char *)(**(code **)(*piVar6 + 0x10))(uVar12,iVar14);
        piVar15 = (int *)0x0;
        iVar1 = -(int)pcVar9;
        do {
          if (*pcVar9 != pcVar9[(int)(acStack_210 + iVar1)]) {
            uVar3 = FUN_00475a90(uVar12,iVar14);
            piVar15 = (int *)FUN_00475a90(uVar12 + 1,iVar14);
            uVar12 = uVar12 + 2;
            uVar4 = FUN_00475a90(uVar12,iVar14);
            uVar5 = uStack_4c8 & 0xffff;
            auStack_498[uVar5 * 3] = uVar3;
            uStack_4c8 = uStack_4c8 + 1;
            auStack_498[uVar5 * 3 + 1] = (short)piVar15;
            auStack_498[uVar5 * 3 + 2] = uVar4;
            break;
          }
          if (*pcVar9 == '\0') break;
          piVar15 = (int *)((int)piVar15 + 1);
          pcVar9 = pcVar9 + 1;
        } while (piVar15 < (int *)0x100);
      }
      uVar11 = (uint)uVar12;
      uVar5 = (**(code **)(*piVar6 + 8))();
      if (uVar11 < uVar5) {
        do {
          FUN_0044a580(auStack_110,&DAT_009a4328,&DAT_009a4324);
          pcVar9 = (char *)(**(code **)(*piVar6 + 0x10))(uVar11,iVar14);
          uVar5 = 0;
          iVar1 = -(int)pcVar9;
          do {
            if (*pcVar9 != pcVar9[(int)(acStack_118 + iVar1)]) {
              uVar10 = FUN_00475a90(uVar12,iVar14);
              (**(code **)(*piVar15 + 0xc))(uVar10);
              break;
            }
            if (*pcVar9 == '\0') break;
            uVar5 = uVar5 + 1;
            pcVar9 = pcVar9 + 1;
          } while (uVar5 < 0x100);
          uVar12 = uVar12 + 1;
          uVar11 = (uint)uVar12;
          uVar5 = (**(code **)(*piVar6 + 8))();
        } while (uVar11 < uVar5);
      }
      (**(code **)(*piStack_4c4 + 4))(&uStack_4b8);
      (**(code **)*DAT_00b5aaf4)(piStack_4c4);
      iVar14 = iVar14 + 1;
    } while (iVar14 < iVar7);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar6);
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00476180 @ 0x00476180 ====

void FUN_00476180(byte param_1)

{
  void *in_ECX;
  
  FUN_00475d10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004761a0 @ 0x004761a0 ====

void FUN_004761a0(void)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 8) = 0;
  *(undefined2 *)(in_ECX + 10) = 0;
  *(undefined2 *)(in_ECX + 0xc) = 0;
  *(undefined2 *)(in_ECX + 0xe) = 0;
  *(undefined2 *)(in_ECX + 0x10) = 0;
  *(undefined2 *)(in_ECX + 0x12) = 0;
  *(undefined2 *)(in_ECX + 0x14) = 0;
  *(undefined2 *)(in_ECX + 0x16) = 0;
  *(undefined2 *)(in_ECX + 0x18) = 0;
  *(undefined2 *)(in_ECX + 0x1a) = 0;
  *(undefined2 *)(in_ECX + 0x1c) = 0;
  *(undefined2 *)(in_ECX + 0x1e) = 0;
  *(undefined2 *)(in_ECX + 0x20) = 0;
  *(undefined2 *)(in_ECX + 0x22) = 0;
  *(undefined2 *)(in_ECX + 0x24) = 0;
  *(undefined2 *)(in_ECX + 0x26) = 0;
  *(undefined2 *)(in_ECX + 0x28) = 0;
  *(undefined2 *)(in_ECX + 0x2a) = 0;
  *(undefined2 *)(in_ECX + 0x2c) = 0;
  *(undefined2 *)(in_ECX + 0x2e) = 0;
  *(undefined2 *)(in_ECX + 0x30) = 0;
  *(undefined2 *)(in_ECX + 0x32) = 0;
  *(undefined2 *)(in_ECX + 0x34) = 0;
  *(undefined2 *)(in_ECX + 0x36) = 0;
  *(undefined2 *)(in_ECX + 0x38) = 0;
  *(undefined2 *)(in_ECX + 0x3a) = 0;
  *(undefined2 *)(in_ECX + 0x3c) = 0;
  *(undefined2 *)(in_ECX + 0x3e) = 0;
  *(undefined2 *)(in_ECX + 0x40) = 0;
  *(undefined2 *)(in_ECX + 0x42) = 0;
  *(undefined2 *)(in_ECX + 0x44) = 0;
  *(undefined2 *)(in_ECX + 0x46) = 0;
  *(undefined2 *)(in_ECX + 0x48) = 0;
  return;
}


// ==== FUN_00476250 @ 0x00476250 ====

void FUN_00476250(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00476270 @ 0x00476270 ====

void FUN_00476270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4350;
  return;
}


// ==== FUN_00476280 @ 0x00476280 ====

void FUN_00476280(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4348,s_PartyWar_009a433c);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_004762cc;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_004762cc:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  uVar3 = FUN_00475a90(0,1);
  (**(code **)(*DAT_00b5aaec + 0x14))(uVar3);
  iVar4 = (**(code **)(*piVar2 + 8))();
  iVar5 = 1;
  if (1 < iVar4) {
    do {
      uVar3 = FUN_00475a90(iVar5,1);
      (**(code **)(*DAT_00b5aaec + 4))(uVar3);
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar4);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar2);
  return;
}


// ==== FUN_00476370 @ 0x00476370 ====

void FUN_00476370(byte param_1)

{
  void *in_ECX;
  
  FUN_00476250();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00476390 @ 0x00476390 ====

void FUN_00476390(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4370;
  return;
}


// ==== FUN_004763c0 @ 0x004763c0 ====

void FUN_004763c0(int *param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  undefined1 auStack_10a [2];
  char acStack_108 [8];
  undefined1 auStack_100 [256];
  
  uVar4 = 1;
  uVar2 = (**(code **)(*param_1 + 8))();
  if (1 < uVar2) {
    do {
      FUN_0044a580(auStack_100,&DAT_009a4368,s_Location_009a435c + 9);
      pcVar3 = (char *)(**(code **)(*param_1 + 0x10))(uVar4,0);
      uVar2 = 0;
      iVar1 = -(int)pcVar3;
      do {
        if (*pcVar3 != pcVar3[(int)(acStack_108 + iVar1)]) {
          FUN_00797a50(auStack_10a + -10,0,0xc);
          FUN_004756e0(uVar4,0);
          FUN_00475a90(uVar4,1);
          FUN_00475a90(uVar4,2);
          FUN_004753b0(uVar4,3);
          (**(code **)(*DAT_00b5ab04 + 4))(auStack_10a + -10);
          break;
        }
        if (*pcVar3 == '\0') break;
        uVar2 = uVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (uVar2 < 0x100);
      uVar4 = uVar4 + 1;
      uVar2 = (**(code **)(*param_1 + 8))();
    } while (uVar4 < uVar2);
  }
  FUN_00476590();
  return;
}


// ==== FUN_004764c0 @ 0x004764c0 ====

void FUN_004764c0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4368,s_Location_009a435c);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0047650e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0047650e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_004763c0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00476570 @ 0x00476570 ====

void FUN_00476570(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4370;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00476590 @ 0x00476590 ====

void FUN_00476590(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piStack_120;
  undefined4 uStack_110;
  undefined1 auStack_10c [4];
  undefined4 uStack_108;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ab04 + 8))();
  while (piVar1 != (int *)0x0) {
    piStack_120 = (int *)0x4765b7;
    puVar2 = (undefined4 *)(**(code **)(*piVar1 + 4))();
    uStack_108 = puVar2[1];
    uStack_110 = *puVar2;
    uVar4 = puVar2[2];
    piStack_120 = piVar1;
    uVar3 = (**(code **)(*DAT_00b5ab0c + 4))(&uStack_110);
    (**(code **)(*DAT_00b5ab08 + 4))(uVar3);
    switch(uVar4) {
    case 1:
    case 3:
    case 5:
      break;
    default:
      auStack_10c[0] = 0;
      uVar4 = FUN_0044a580(auStack_10c,s_File___s__Line___d_0099f0a0,
                           s___Loader_Siege_Location_cpp_009a4378,0x7d);
      FUN_00797b80(uVar4);
      FUN_00797a40();
      break;
    case 4:
      uVar4 = (**(code **)(*DAT_00b5aafc + 4))(&piStack_120,piVar1);
      (**(code **)(*DAT_00b5aaf8 + 4))(uVar4);
    }
    piVar1 = (int *)(**(code **)(*DAT_00b5ab04 + 0xc))();
  }
  return;
}


// ==== FUN_00476680 @ 0x00476680 ====

void FUN_00476680(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a43d8;
  return;
}


// ==== FUN_004766b0 @ 0x004766b0 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x004770e1) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004766b0(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  float10 fVar10;
  double dVar11;
  char acStack_12dc [4];
  uint uStack_12d8;
  undefined2 uVar12;
  uint uStack_1238;
  char acStack_11fa [6];
  undefined2 uStack_11f4;
  char acStack_1102 [1250];
  float fStack_c20;
  float fStack_c1c;
  float fStack_c18;
  float fStack_c14;
  float fStack_c10;
  float fStack_c0c;
  float fStack_c08;
  float fStack_c04;
  float fStack_c00;
  float fStack_bfc;
  undefined4 uStack_bf8;
  char acStack_b04 [256];
  float fStack_a04;
  float fStack_928;
  float fStack_924;
  float fStack_920;
  undefined4 uStack_91c;
  float fStack_918;
  undefined4 uStack_914;
  undefined4 uStack_910;
  float fStack_90c;
  undefined1 uStack_908;
  undefined1 uStack_906;
  char acStack_815 [753];
  undefined2 uStack_524;
  undefined2 uStack_522;
  ushort uStack_520;
  undefined1 uStack_51e;
  undefined1 uStack_51d;
  undefined1 uStack_51c;
  ushort uStack_51a;
  char acStack_4e6 [256];
  undefined2 uStack_3e6;
  undefined2 uStack_3e4;
  undefined4 uStack_3e0;
  undefined4 uStack_3dc;
  undefined4 uStack_3d8;
  undefined2 uStack_3d4;
  undefined2 uStack_3d2;
  undefined2 uStack_3d0;
  undefined1 uStack_3ce;
  undefined2 uStack_3cc;
  undefined2 uStack_3ca;
  undefined2 uStack_3c8;
  undefined1 uStack_3c6;
  undefined1 uStack_3c4;
  char acStack_3c2 [6];
  undefined2 uStack_3bc;
  char acStack_108 [260];
  undefined4 uStack_4;
  
  uStack_4 = 0x4766ba;
  FUN_00477450();
  uVar9 = 1;
  uVar5 = (**(code **)(*param_1 + 8))();
  if (uVar5 < 2) {
    return;
  }
LAB_004766e8:
  pcVar6 = (char *)(**(code **)(*param_1 + 0x10))();
  FUN_0044a580();
  uVar5 = 0;
  iVar7 = -(int)pcVar6;
  do {
    if (*pcVar6 != pcVar6[(int)(acStack_108 + iVar7)]) {
      uStack_11f4 = FUN_00475a90();
      iVar7 = (**(code **)(*param_1 + 0x10))();
      uVar5 = 0;
      goto LAB_00476785;
    }
    if (*pcVar6 == '\0') break;
    uVar5 = uVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar5 < 0x100);
  goto LAB_0047673b;
  while (uVar5 = uVar5 + 1, uVar5 < 0x100) {
LAB_00476785:
    cVar1 = (acStack_11fa + uVar5)[iVar7 - (int)acStack_11fa];
    acStack_11fa[uVar5] = cVar1;
    if (cVar1 == '\0') goto LAB_004767a1;
  }
  acStack_11fa[0] = '\0';
LAB_004767a1:
  iVar7 = (**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    cVar1 = (acStack_1102 + uVar5)[iVar7 - (int)acStack_1102];
    acStack_1102[uVar5] = cVar1;
    if (cVar1 == '\0') goto LAB_004767e2;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  acStack_1102[0] = '\0';
LAB_004767e2:
  iVar7 = (**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    cVar1 = (acStack_1102 + uVar5 + 0xf8)[iVar7 - (int)(acStack_1102 + 0xf8)];
    acStack_1102[uVar5 + 0xf8] = cVar1;
    if (cVar1 == '\0') goto LAB_00476822;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  acStack_1102[0xf8] = 0;
LAB_00476822:
  iVar7 = (**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    cVar1 = (acStack_1102 + uVar5 + 0x1f0)[iVar7 - (int)(acStack_1102 + 0x1f0)];
    acStack_1102[uVar5 + 0x1f0] = cVar1;
    if (cVar1 == '\0') goto LAB_00476862;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  acStack_1102[0x1f0] = 0;
LAB_00476862:
  iVar7 = (**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    cVar1 = (acStack_1102 + uVar5 + 0x2e8)[iVar7 - (int)(acStack_1102 + 0x2e8)];
    acStack_1102[uVar5 + 0x2e8] = cVar1;
    if (cVar1 == '\0') goto LAB_004768a2;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  acStack_1102[0x2e8] = 0;
LAB_004768a2:
  iVar7 = (**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    cVar1 = (acStack_1102 + uVar5 + 0x3e0)[iVar7 - (int)(acStack_1102 + 0x3e0)];
    acStack_1102[uVar5 + 0x3e0] = cVar1;
    if (cVar1 == '\0') goto LAB_004768e2;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  acStack_1102[0x3e0] = 0;
LAB_004768e2:
  fVar10 = (float10)FUN_00477510();
  fStack_c20 = (float)fVar10;
  fVar10 = (float10)FUN_00477510();
  fStack_c1c = (float)fVar10;
  fVar10 = (float10)FUN_00477510();
  fStack_c18 = (float)fVar10;
  fVar10 = (float10)FUN_00477510();
  fStack_c14 = (float)(fVar10 * (float10)_DAT_009a4474);
  fVar10 = (float10)FUN_00477510();
  fStack_c10 = (float)(fVar10 * (float10)_DAT_009a4474);
  fVar10 = (float10)FUN_00477510();
  fStack_c0c = (float)fVar10;
  fVar10 = (float10)FUN_00477510();
  fStack_c08 = (float)(fVar10 * (float10)_DAT_009a4474);
  fVar10 = (float10)FUN_00477510();
  fStack_c04 = (float)(fVar10 * (float10)_DAT_009a4474);
  fVar10 = (float10)FUN_00477510();
  fStack_c00 = (float)fVar10;
  fVar10 = (float10)FUN_00477510();
  fStack_bfc = (float)fVar10;
  uStack_bf8 = FUN_004756e0();
  iVar7 = (**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    cVar1 = ((char *)((int)&fStack_bfc + uVar5))[iVar7 - (int)&fStack_bfc];
    *(char *)((int)&fStack_bfc + uVar5) = cVar1;
    if (cVar1 == '\0') goto LAB_004769f3;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  fStack_bfc = (float)((uint)fStack_bfc & 0xffffff00);
LAB_004769f3:
  iVar7 = (**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    cVar1 = (acStack_b04 + uVar5)[iVar7 - (int)acStack_b04];
    acStack_b04[uVar5] = cVar1;
    if (cVar1 == '\0') goto LAB_00476a32;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  acStack_b04[0] = '\0';
LAB_00476a32:
  fVar10 = (float10)FUN_00477510();
  fStack_a04 = (float)fVar10;
  iVar7 = (**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    cVar1 = (acStack_b04 + uVar5 + 0xfc)[iVar7 - (int)(acStack_b04 + 0xfc)];
    acStack_b04[uVar5 + 0xfc] = cVar1;
    if (cVar1 == '\0') goto LAB_00476a82;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  acStack_b04[0xfc] = 0;
LAB_00476a82:
  pcVar6 = (char *)(**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    if (pcVar6[uVar5] == '\0') {
      if (uVar5 == 0) {
        uStack_910 = 0.0;
      }
      else {
        dVar11 = _atof(pcVar6);
        uStack_910 = (float)dVar11;
      }
      goto LAB_00476ac1;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  uStack_910 = 0.0;
LAB_00476ac1:
  uVar12 = 0x17;
  pcVar6 = (char *)(**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    if (pcVar6[uVar5] == '\0') {
      if (uVar5 == 0) {
        uStack_914 = 0.0;
      }
      else {
        dVar11 = _atof(pcVar6);
        uStack_914 = (float)dVar11;
      }
      goto LAB_00476b07;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  uStack_914 = 0.0;
LAB_00476b07:
  pcVar6 = (char *)(**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    if (pcVar6[uVar5] == '\0') {
      if (uVar5 == 0) {
        fStack_918 = 0.0;
      }
      else {
        dVar11 = _atof(pcVar6);
        fStack_918 = (float)dVar11;
      }
      goto LAB_00476b51;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  fStack_918 = 0.0;
LAB_00476b51:
  pcVar6 = (char *)(**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    if (pcVar6[uVar5] == '\0') {
      if (uVar5 == 0) {
        uStack_91c = 0.0;
      }
      else {
        dVar11 = _atof(pcVar6);
        uStack_91c = (float)dVar11;
      }
      goto LAB_00476b97;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  uStack_91c = 0.0;
LAB_00476b97:
  pcVar6 = (char *)(**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    if (pcVar6[uVar5] == '\0') {
      if (uVar5 == 0) {
        fStack_920 = 0.0;
      }
      else {
        dVar11 = _atof(pcVar6);
        fStack_920 = (float)dVar11;
      }
      goto LAB_00476be1;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  fStack_920 = 0.0;
LAB_00476be1:
  pcVar6 = (char *)(**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    if (pcVar6[uVar5] == '\0') {
      if (uVar5 == 0) {
        fStack_924 = 0.0;
      }
      else {
        dVar11 = _atof(pcVar6);
        fStack_924 = (float)dVar11;
      }
      goto LAB_00476c27;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  fStack_924 = 0.0;
LAB_00476c27:
  pcVar6 = (char *)(**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    if (pcVar6[uVar5] == '\0') {
      if (uVar5 == 0) {
        fStack_928 = 0.0;
      }
      else {
        uStack_12d8 = 0x476c64;
        dVar11 = _atof(pcVar6);
        fStack_928 = (float)dVar11;
      }
      goto LAB_00476c71;
    }
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  fStack_928 = 0.0;
LAB_00476c71:
  acStack_12dc[0] = -0x7c;
  acStack_12dc[1] = 'l';
  acStack_12dc[2] = 'G';
  acStack_12dc[3] = '\0';
  uStack_12d8 = uVar9;
  uVar2 = FUN_004774b0();
  fStack_924 = (float)CONCAT31(fStack_924._1_3_,uVar2);
  acStack_12dc[0] = -0x6b;
  acStack_12dc[1] = 'l';
  acStack_12dc[2] = 'G';
  acStack_12dc[3] = '\0';
  uStack_12d8 = uVar9;
  fVar10 = (float10)FUN_00477510();
  fStack_920 = (float)fVar10;
  acStack_12dc[0] = -0x5a;
  acStack_12dc[1] = 'l';
  acStack_12dc[2] = 'G';
  acStack_12dc[3] = '\0';
  uStack_12d8 = uVar9;
  uVar2 = FUN_004774b0();
  uStack_91c = (float)CONCAT31(uStack_91c._1_3_,uVar2);
  acStack_12dc[0] = -0x49;
  acStack_12dc[1] = 'l';
  acStack_12dc[2] = 'G';
  acStack_12dc[3] = '\0';
  uStack_12d8 = uVar9;
  uVar2 = FUN_004774b0();
  uStack_91c._0_2_ = CONCAT11(uVar2,(undefined1)uStack_91c);
  acStack_12dc[0] = -0x38;
  acStack_12dc[1] = 'l';
  acStack_12dc[2] = 'G';
  acStack_12dc[3] = '\0';
  uStack_12d8 = uVar9;
  uVar3 = FUN_00475a90();
  uStack_91c = (float)CONCAT22(uVar3,(undefined2)uStack_91c);
  acStack_12dc[0] = -0x26;
  acStack_12dc[1] = 'l';
  acStack_12dc[2] = 'G';
  acStack_12dc[3] = '\0';
  uStack_12d8 = uVar9;
  fStack_918 = (float)FUN_004756e0();
  acStack_12dc[0] = -0x15;
  acStack_12dc[1] = 'l';
  acStack_12dc[2] = 'G';
  acStack_12dc[3] = '\0';
  uStack_12d8 = uVar9;
  uVar2 = FUN_004753b0();
  uStack_914 = (float)CONCAT31(uStack_914._1_3_,uVar2);
  acStack_12dc[0] = -4;
  acStack_12dc[1] = 'l';
  acStack_12dc[2] = 'G';
  acStack_12dc[3] = '\0';
  uStack_12d8 = uVar9;
  uVar2 = FUN_004774b0();
  uStack_914._0_2_ = CONCAT11(uVar2,(undefined1)uStack_914);
  builtin_strncpy(acStack_12dc,"\rmG",4);
  uStack_12d8 = uVar9;
  uVar2 = FUN_004774b0();
  uStack_914._0_3_ = CONCAT12(uVar2,(undefined2)uStack_914);
  builtin_strncpy(acStack_12dc,"\x1emG",4);
  uStack_12d8 = uVar9;
  uVar2 = FUN_004774b0();
  uStack_914 = (float)CONCAT13(uVar2,(undefined3)uStack_914);
  builtin_strncpy(acStack_12dc,"/mG",4);
  uStack_12d8 = uVar9;
  uVar2 = FUN_004774b0();
  uStack_910 = (float)CONCAT31(uStack_910._1_3_,uVar2);
  builtin_strncpy(acStack_12dc,"@mG",4);
  uStack_12d8 = uVar9;
  uVar2 = FUN_004774b0();
  uStack_910._0_2_ = CONCAT11(uVar2,(undefined1)uStack_910);
  builtin_strncpy(acStack_12dc,"QmG",4);
  uStack_12d8 = uVar9;
  fVar10 = (float10)FUN_00477510();
  fStack_90c = (float)fVar10;
  builtin_strncpy(acStack_12dc,"bmG",4);
  uStack_12d8 = uVar9;
  uStack_908 = FUN_004774b0();
  builtin_strncpy(acStack_12dc,"smG",4);
  uStack_12d8 = uVar9;
  uStack_906 = FUN_004774b0();
  acStack_12dc[0] = -0x7c;
  acStack_12dc[1] = 'm';
  acStack_12dc[2] = 'G';
  acStack_12dc[3] = '\0';
  uStack_12d8 = uVar9;
  iVar7 = (**(code **)(*param_1 + 0x10))();
  uVar5 = 0;
  do {
    pcVar6 = (char *)((int)&uStack_910 + uVar5 + 3);
    cVar1 = pcVar6[iVar7 - ((int)&uStack_910 + 3)];
    *pcVar6 = cVar1;
    if (cVar1 == '\0') goto LAB_00476db3;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  uStack_910 = (float)((uint)uStack_910 & 0xffffff);
LAB_00476db3:
  acStack_12dc[0] = '-';
  acStack_12dc[1] = '\0';
  acStack_12dc[2] = '\0';
  acStack_12dc[3] = '\0';
  iVar7 = (**(code **)(*param_1 + 0x10))(uVar9);
  uVar5 = 0;
  do {
    cVar1 = (acStack_815 + uVar5)[iVar7 - (int)acStack_815];
    acStack_815[uVar5] = cVar1;
    if (cVar1 == '\0') goto LAB_00476df2;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  acStack_815[0] = '\0';
LAB_00476df2:
  iVar7 = (**(code **)(*param_1 + 0x10))(uVar9,0x2e);
  uVar5 = 0;
  do {
    cVar1 = (acStack_815 + uVar5 + 0xf8)[iVar7 - (int)(acStack_815 + 0xf8)];
    acStack_815[uVar5 + 0xf8] = cVar1;
    if (cVar1 == '\0') goto LAB_00476e32;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  acStack_815[0xf8] = 0;
LAB_00476e32:
  iVar7 = (**(code **)(*param_1 + 0x10))(uVar9);
  uVar5 = 0;
  do {
    cVar1 = (acStack_815 + uVar5 + 0x1f0)[iVar7 - (int)(acStack_815 + 0x1f0)];
    acStack_815[uVar5 + 0x1f0] = cVar1;
    if (cVar1 == '\0') goto LAB_00476e72;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  acStack_815[0x1f0] = 0;
LAB_00476e72:
  uStack_524 = FUN_00475a90(uVar9,0x33);
  uStack_522 = FUN_00475a90(uVar9,0x34);
  uStack_520 = FUN_00475a90(uVar9,0x35);
  uStack_51e = FUN_004753b0(uVar9,0x36);
  uStack_51d = FUN_004774b0(uVar9,0x37);
  uStack_51c = FUN_004774b0(uVar9,0x38);
  uVar4 = FUN_00475a90(uVar9,0x39);
  uStack_51a = 10;
  if (9 < uVar4) {
    uStack_51a = uVar4;
  }
  uVar8 = (**(code **)(*param_1 + 0x10))(uVar9,0x3a);
  FUN_004772b0(acStack_12dc,&DAT_009a43d0,uVar8);
  uVar5 = 0;
  do {
    cVar1 = acStack_12dc[uVar5];
    acStack_815[uVar5 + 0x2f5] = cVar1;
    if (cVar1 == '\0') goto LAB_00476f3e;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x40);
  uStack_520 = uStack_520 & 0xff00;
LAB_00476f3e:
  acStack_4e6[6] = FUN_004774b0(uVar9,0x3b);
  acStack_4e6[7] = FUN_004774b0(uVar9,0x3c);
  iVar7 = (**(code **)(*param_1 + 0x10))(uVar9,0x3d);
  uVar5 = 0;
  do {
    cVar1 = (acStack_4e6 + uVar5)[iVar7 - (int)acStack_4e6];
    acStack_4e6[uVar5] = cVar1;
    if (cVar1 == '\0') goto LAB_00476fa2;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  acStack_4e6[0] = '\0';
LAB_00476fa2:
  uStack_3e6 = FUN_00475a90(uVar9,0x3e);
  uStack_3e4 = FUN_00475a90(uVar9,0x3f);
  uStack_3e0 = FUN_004756e0(uVar9,0x40);
  uStack_3dc = FUN_004756e0(uVar9,0x41);
  uStack_3d8 = FUN_004756e0(uVar9,0x42);
  uStack_3d4 = uVar12;
  uStack_3d2 = FUN_00475a90(uVar9,0x30);
  uStack_3d0 = FUN_00475a90(uVar9,0x31);
  uStack_3ce = FUN_004753b0(uVar9,0x32);
  uStack_3cc = FUN_00475a90(uVar9,0x43);
  uStack_3ca = FUN_00475a90(uVar9,0x44);
  uStack_3c8 = FUN_00475a90(uVar9,0x45);
  uStack_3c6 = FUN_004753b0(uVar9,0x46);
  uStack_3c4 = FUN_004774b0(uVar9,0x47);
  acStack_3c2[2] = FUN_004774b0(uVar9,0x48);
  acStack_3c2[3] = FUN_004774b0(uVar9,0x49);
  acStack_3c2[4] = FUN_004774b0(uVar9,0x4a);
  acStack_3c2[5] = FUN_004774b0(uVar9,0x4b);
  uStack_3bc = FUN_00475a90(uVar9,0x4c);
  iVar7 = (**(code **)(*param_1 + 0x10))(uVar9,0x4d);
  uVar5 = 0;
  do {
    cVar1 = (acStack_3c2 + uVar5)[iVar7 - (int)acStack_3c2];
    acStack_3c2[uVar5] = cVar1;
    if (cVar1 == '\0') goto LAB_00477162;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x100);
  acStack_3c2[0] = '\0';
LAB_00477162:
  (**(code **)(*DAT_00b5ab14 + 4))(acStack_12dc + 0x30);
LAB_0047673b:
  uStack_1238 = uStack_1238 + 1;
  uVar9 = uStack_1238 & 0xffff;
  uVar5 = (**(code **)(*param_1 + 8))();
  if (uVar5 <= uVar9) {
    return;
  }
  goto LAB_004766e8;
}


// ==== FUN_00477180 @ 0x00477180 ====

void FUN_00477180(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a43cc,&DAT_009a4398);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_004771ce;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_004771ce:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_004766b0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00477230 @ 0x00477230 ====

void FUN_00477230(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a43d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00477250 @ 0x00477250 ====

void FUN_00477250(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)(in_ECX + 0x101) = 0;
  *(undefined1 *)(in_ECX + 0x201) = 0;
  *(undefined1 *)(in_ECX + 0x301) = 0;
  *(undefined1 *)(in_ECX + 0x40e) = 0;
  return;
}


// ==== FUN_00477270 @ 0x00477270 ====

void FUN_00477270(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined2 *)(in_ECX + 0x114) = 0;
  *(undefined2 *)(in_ECX + 0x116) = 0;
  *(undefined2 *)(in_ECX + 0x118) = 0;
  *(undefined1 *)(in_ECX + 0x11a) = 0;
  *(undefined2 *)(in_ECX + 0x11c) = 0;
  *(undefined2 *)(in_ECX + 0x11e) = 0;
  *(undefined2 *)(in_ECX + 0x120) = 0;
  *(undefined1 *)(in_ECX + 0x122) = 0;
  return;
}


// ==== FUN_004772b0 @ 0x004772b0 ====

char * FUN_004772b0(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x40,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x40)) {
    param_1[0x3f] = '\0';
  }
  return param_1;
}


// ==== FUN_004772e0 @ 0x004772e0 ====

void FUN_004772e0(char *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int *in_ECX;
  char cVar2;
  int iVar3;
  uint local_208;
  uint local_204;
  undefined1 local_200 [256];
  undefined1 auStack_100 [256];
  
  if (*param_1 == '\0') {
    local_200[0] = 0;
    uVar1 = (**(code **)(*in_ECX + 0x14))(param_2,param_3);
    FUN_0044a580(local_200,s__s___Cell__d___d__is_NULL_009a422c,uVar1);
    FUN_00797b80(local_200);
    auStack_100[0] = 0;
    uVar1 = FUN_0044a580(auStack_100,s_File___s__Line___d_0099f0a0,
                         s_d__usa_24_0_1_2__develop_share_l_009a43e0,0x136);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  cVar2 = *param_1;
  iVar3 = 0;
  local_204 = 0;
  local_208 = 0;
  do {
    if (cVar2 == '\0') {
      return;
    }
    if ((iVar3 == 0) && (cVar2 == '-')) {
      cVar2 = param_1[1];
      iVar3 = 1;
    }
    else if ((cVar2 < '0') || ('9' < cVar2)) {
      if (cVar2 == '.') {
        local_204 = local_204 + 1;
        iVar3 = iVar3 + 1;
        if (local_204 < 2) {
          cVar2 = param_1[iVar3];
          goto LAB_0047742b;
        }
      }
      local_200[0] = 0;
      uVar1 = (**(code **)(*in_ECX + 0x14))(param_2,param_3,param_1);
      FUN_0044a580(local_200,s__s_Cell___d___d__Can_t_convert_t_009a4440,uVar1);
      FUN_00797b80(local_200);
      auStack_100[0] = 0;
      uVar1 = FUN_0044a580(auStack_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009a43e0,0x165);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    else {
      cVar2 = param_1[iVar3 + 1];
      iVar3 = iVar3 + 1;
    }
LAB_0047742b:
    local_208 = local_208 + 1;
    if (0xff < local_208) {
      return;
    }
  } while( true );
}


// ==== FUN_00477450 @ 0x00477450 ====

void FUN_00477450(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)(in_ECX + 0x102) = 0;
  *(undefined1 *)(in_ECX + 0x202) = 0;
  *(undefined1 *)(in_ECX + 0x302) = 0;
  *(undefined1 *)(in_ECX + 0x402) = 0;
  *(undefined1 *)(in_ECX + 0x502) = 0;
  *(undefined1 *)(in_ECX + 0x630) = 0;
  *(undefined1 *)(in_ECX + 0x730) = 0;
  *(undefined1 *)(in_ECX + 0x834) = 0;
  FUN_00477250();
  FUN_00477270();
  *(undefined1 *)(in_ECX + 0xeea) = 0;
  return;
}


// ==== FUN_004774b0 @ 0x004774b0 ====

undefined4 FUN_004774b0(undefined4 param_1,undefined4 param_2)

{
  char *_Str;
  uint uVar1;
  long lVar2;
  int *in_ECX;
  
  _Str = (char *)(**(code **)(*in_ECX + 0x10))(param_1,param_2);
  FUN_00475260(_Str,param_1,param_2);
  uVar1 = 0;
  do {
    if (_Str[uVar1] == '\0') {
      if (uVar1 != 0) {
        lVar2 = _atol(_Str);
        if (lVar2 != 0) {
          return 1;
        }
      }
      return 0;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  return 0;
}


// ==== FUN_00477510 @ 0x00477510 ====

float10 FUN_00477510(undefined4 param_1,undefined4 param_2)

{
  char *_String;
  uint uVar1;
  int *in_ECX;
  double dVar2;
  
  _String = (char *)(**(code **)(*in_ECX + 0x10))(param_1,param_2);
  FUN_004772e0(_String,param_1,param_2);
  uVar1 = 0;
  do {
    if (_String[uVar1] == '\0') {
      if (uVar1 != 0) {
        dVar2 = _atof(_String);
        return (float10)dVar2;
      }
      break;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  return (float10)0.0;
}


// ==== FUN_00477570 @ 0x00477570 ====

void FUN_00477570(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4508;
  return;
}


// ==== FUN_00477590 @ 0x00477590 ====

void FUN_00477590(undefined4 param_1,int *param_2)

{
  uint *puVar1;
  uint *puVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  undefined1 auStack_208 [2];
  undefined1 auStack_206 [246];
  undefined1 auStack_110 [260];
  undefined4 uStack_c;
  int *piStack_8;
  
  puVar3 = operator_new(0x10000c);
  puVar1 = (uint *)(puVar3 + 2);
  puVar8 = puVar1;
  iVar4 = (**(code **)(*param_2 + 8))(4,puVar1);
  if (iVar4 != 4) {
    auStack_208[0] = 0;
    uVar5 = FUN_0044a580(auStack_208,s_File___s__Line___d_0099f0a0,
                         s_d__usa_24_0_1_2__develop_Framewo_009a450c,0x31);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  puVar2 = (uint *)(puVar3 + 4);
  iVar4 = (**(code **)(*param_2 + 8))(4,puVar2);
  if (iVar4 != 4) {
    uVar5 = FUN_0044a580(auStack_208 + -8,s_File___s__Line___d_0099f0a0,
                         s_d__usa_24_0_1_2__develop_Framewo_009a450c,0x31);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  if (0x200 < *puVar1) {
    uVar5 = FUN_0044a580(auStack_208 + -8,s_File___s__Line___d_009a4494,
                         s___Loader_Map_Field_cpp_009a447c,0x22);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  if (0x200 < *puVar2) {
    uVar5 = FUN_0044a580(auStack_208 + -8,s_File___s__Line___d_009a44c0,
                         s___Loader_Map_Field_cpp_009a44a8,0x23);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  uVar9 = 0;
  if (*puVar1 != 0) {
    do {
      uVar7 = 0;
      if (*puVar2 != 0) {
        do {
          iVar4 = (**(code **)(*param_2 + 8))(2,auStack_208 + -0xc);
          if (iVar4 != 2) {
            uVar9 = uVar9 & 0xffffff00;
            uVar5 = FUN_0044a580(auStack_208 + -0x10,s_File___s__Line___d_0099f0a0,
                                 s_d__usa_24_0_1_2__develop_Framewo_009a450c,0x31);
            FUN_00797b80(uVar5);
            FUN_00797a40();
          }
          iVar4 = (**(code **)(*DAT_00b5ab10 + 8))(puVar8);
          if (iVar4 == 0) {
            auStack_110[0] = 0;
            uVar5 = FUN_0044a580(auStack_110,s_File___s__Line___d_009a44ec,
                                 s___Loader_Map_Field_cpp_009a44d4,0x2d);
            FUN_00797b80(uVar5);
            FUN_00797a40();
          }
          *(int *)(puVar3 + (*puVar2 * uVar9 + uVar7) * 2 + 6) = iVar4;
          uVar7 = uVar7 + 1;
          param_2 = piStack_8;
        } while (uVar7 < *puVar2);
      }
      uVar9 = uVar9 + 1;
    } while (uVar9 < *(uint *)(puVar3 + 2));
  }
  *puVar3 = (short)uStack_c;
  piVar6 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(uStack_c);
  (**(code **)(*piVar6 + 8))(puVar3);
  return;
}


// ==== FUN_00477790 @ 0x00477790 ====

void FUN_00477790(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4508;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004777b0 @ 0x004777b0 ====

void FUN_004777b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4554;
  return;
}


// ==== FUN_004777d0 @ 0x004777d0 ====

void FUN_004777d0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  byte bVar5;
  undefined2 uVar6;
  uint uVar7;
  int *piVar8;
  void *pvVar9;
  char *pcVar10;
  undefined2 *puVar11;
  undefined4 uVar12;
  uint uVar13;
  undefined4 uVar14;
  int *piVar15;
  char local_314 [256];
  undefined4 local_214;
  undefined1 local_210;
  undefined1 local_20f;
  undefined1 local_20e;
  char local_20c [500];
  void *pvStack_18;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097dc7e;
  pvStack_c = ExceptionList;
  local_314[0] = '\0';
  ExceptionList = &pvStack_c;
  FUN_0044a580(local_20c,&DAT_009a454c,s_LevelCap_009a4540);
  uVar7 = 0;
  do {
    local_314[uVar7] = local_20c[uVar7];
    if (local_20c[uVar7] == '\0') goto LAB_0047782e;
    uVar7 = uVar7 + 1;
  } while (uVar7 < 0x100);
  local_314[0] = '\0';
LAB_0047782e:
  local_214 = param_2;
  local_210 = 10;
  local_20f = 0x2c;
  local_20e = 1;
  piVar8 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_314);
  FUN_0044a580(&local_210,&DAT_009a454c,&DAT_009a4549);
  piVar15 = (int *)&local_210;
  uVar14 = 1;
  (**(code **)(*piVar8 + 0x10))(1);
  cVar2 = FUN_0044a440(uVar14);
  if (cVar2 == '\0') {
    pvVar9 = operator_new(0xc);
    uStack_10 = 0;
    if (pvVar9 == (void *)0x0) {
      uVar14 = 0;
    }
    else {
      uVar14 = FUN_005df650();
    }
    uStack_10 = 0xffffffff;
    uVar13 = 1;
    uVar7 = (**(code **)(*piVar8 + 8))();
    if (1 < uVar7) {
      do {
        FUN_0044a580(local_20c + 0xf4,&DAT_009a454c,&DAT_009a454a);
        pcVar10 = (char *)(**(code **)(*piVar8 + 0x10))(uVar13,0);
        uVar7 = 0;
        iVar1 = 0xec - (int)pcVar10;
        do {
          if (*pcVar10 != pcVar10[(int)(local_20c + iVar1)]) {
            puVar11 = operator_new(0x18);
            uVar6 = FUN_00475a90(uVar13,0);
            *puVar11 = uVar6;
            uVar12 = FUN_00477a70(uVar13,1);
            *(undefined4 *)(puVar11 + 2) = uVar12;
            uVar12 = FUN_00477a70(uVar13,2);
            *(undefined4 *)(puVar11 + 4) = uVar12;
            uVar3 = FUN_004753b0(uVar13,3);
            *(undefined1 *)(puVar11 + 6) = uVar3;
            uVar6 = FUN_00475a90(uVar13,4);
            puVar11[7] = uVar6;
            uVar3 = FUN_004774b0(uVar13,5);
            *(undefined1 *)(puVar11 + 8) = uVar3;
            uVar3 = FUN_004774b0(uVar13,6);
            *(undefined1 *)((int)puVar11 + 0x11) = uVar3;
            bVar4 = FUN_004753b0(uVar13,7);
            bVar5 = FUN_004753b0(uVar13,8);
            uVar7 = FUN_004753b0(uVar13,9);
            *(uint *)(puVar11 + 10) = ((bVar4 | 0xffffff00) << 8 | (uint)bVar5) << 8 | uVar7 & 0xff;
            (**(code **)(*piVar15 + 8))(puVar11);
            break;
          }
          if (*pcVar10 == '\0') break;
          uVar7 = uVar7 + 1;
          pcVar10 = pcVar10 + 1;
        } while (uVar7 < 0x100);
        uVar13 = uVar13 + 1;
        uVar7 = (**(code **)(*piVar8 + 8))();
      } while (uVar13 < uVar7);
    }
    (**(code **)(*DAT_00b5ab1c + 4))(puStack_8,uVar14);
    (**(code **)(*DAT_00b5aa34 + 0xc))(piVar8);
  }
  ExceptionList = pvStack_18;
  return;
}


// ==== FUN_00477a50 @ 0x00477a50 ====

void FUN_00477a50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4554;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00477a70 @ 0x00477a70 ====

long FUN_00477a70(undefined4 param_1,undefined4 param_2)

{
  char *_Str;
  uint uVar1;
  long lVar2;
  int *in_ECX;
  
  _Str = (char *)(**(code **)(*in_ECX + 0x10))(param_1,param_2);
  FUN_00475260(_Str,param_1,param_2);
  uVar1 = 0;
  do {
    if (_Str[uVar1] == '\0') {
      if (uVar1 == 0) {
        return 0;
      }
      lVar2 = _atol(_Str);
      return lVar2;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  return 0;
}


// ==== FUN_00477ad0 @ 0x00477ad0 ====

void FUN_00477ad0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00477ae0 @ 0x00477ae0 ====

void FUN_00477ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4574;
  return;
}


// ==== FUN_00477af0 @ 0x00477af0 ====

void FUN_00477af0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a456c,s_ItemRemoveStone_009a455c);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00477b3e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00477b3e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00477bc0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00477ba0 @ 0x00477ba0 ====

void FUN_00477ba0(byte param_1)

{
  void *in_ECX;
  
  FUN_00477ad0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00477bc0 @ 0x00477bc0 ====

void FUN_00477bc0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  
  uVar1 = (**(code **)(*param_1 + 8))();
  if (1 < uVar1) {
    uVar1 = 1;
    do {
      uVar2 = FUN_00475a90(uVar1,0);
      uStack_4 = FUN_004753b0(uVar1,9);
      uStack_2 = FUN_004753b0(uVar1,10);
      uStack_3 = FUN_004753b0(uVar1,0xb);
      uStack_c = FUN_004756e0(uVar1,1);
      uStack_8 = FUN_004756e0(uVar1,2);
      uVar2 = uVar2 & 0xffff;
      uStack_34 = 0;
      uStack_30 = uVar2;
      (**(code **)(*DAT_00b5aa20 + 4))(&uStack_34,&uStack_c);
      uStack_14 = FUN_004756e0(uVar1,3);
      uStack_10 = FUN_004756e0(uVar1,4);
      uStack_34 = 1;
      uStack_30 = uVar2;
      (**(code **)(*DAT_00b5aa20 + 4))(&uStack_34,&uStack_14);
      uStack_1c = FUN_004756e0(uVar1,3);
      uStack_18 = FUN_004756e0(uVar1,4);
      uStack_34 = 2;
      uStack_30 = uVar2;
      (**(code **)(*DAT_00b5aa20 + 4))(&uStack_34,&uStack_1c);
      uStack_24 = FUN_004756e0(uVar1,5);
      uStack_20 = FUN_004756e0(uVar1,6);
      uStack_34 = 3;
      uStack_30 = uVar2;
      (**(code **)(*DAT_00b5aa20 + 4))(&uStack_34,&uStack_24);
      uStack_2c = FUN_004756e0(uVar1,7);
      uStack_28 = FUN_004756e0(uVar1,8);
      uStack_34 = 4;
      uStack_30 = uVar2;
      (**(code **)(*DAT_00b5aa20 + 4))(&uStack_34,&uStack_2c);
      uVar1 = uVar1 + 1;
      uVar2 = (**(code **)(*param_1 + 8))();
    } while (uVar1 < uVar2);
  }
  return;
}


// ==== FUN_00477d70 @ 0x00477d70 ====

void FUN_00477d70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00477d80 @ 0x00477d80 ====

void FUN_00477d80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4598;
  return;
}


// ==== FUN_00477d90 @ 0x00477d90 ====

void FUN_00477d90(int *param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  uint uVar5;
  undefined1 auStack_384 [2];
  undefined1 uStack_382;
  undefined **ppuStack_358;
  undefined **ppuStack_354;
  undefined1 auStack_350 [576];
  undefined4 uStack_110;
  char acStack_10c [256];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097dc9b;
  pvStack_c = ExceptionList;
  uVar4 = 1;
  ExceptionList = &pvStack_c;
  uVar2 = (**(code **)(*param_1 + 0xc))();
  if (1 < uVar2) {
    uVar2 = 1;
    do {
      uStack_382 = 0;
      ppuStack_354 = &PTR_FUN_009a45a4;
      _eh_vector_constructor_iterator_(auStack_350,0x30,0xc,FUN_005fd550,FUN_006ef6d0);
      uVar5 = 0;
      uStack_110 = 0;
      uStack_4 = 0;
      pcVar3 = (char *)(**(code **)(*param_1 + 0x10))(0,uVar2);
      FUN_0044a580(acStack_10c,&DAT_009a4590,&DAT_0099cf70);
      iVar1 = -(int)pcVar3;
      while (*pcVar3 == pcVar3[(int)(acStack_10c + iVar1)]) {
        if (*pcVar3 == '\0') goto LAB_00477e4e;
        uVar5 = uVar5 + 1;
        pcVar3 = pcVar3 + 1;
        if (0xff < uVar5) {
LAB_00477e4e:
          uStack_4 = 0xffffffff;
          ppuStack_354 = &PTR_FUN_009a45a4;
          _eh_vector_destructor_iterator_(auStack_350,0x30,0xc,FUN_006ef6d0);
          ExceptionList = pvStack_c;
          return;
        }
      }
      FUN_004780c0(param_1,uVar4,auStack_384);
      (**(code **)(*DAT_00b5aa24 + 4))(auStack_384);
      puStack_8 = (undefined1 *)0xffffffff;
      ppuStack_358 = &PTR_FUN_009a45a4;
      _eh_vector_destructor_iterator_(&ppuStack_354,0x30,0xc,FUN_006ef6d0);
      uVar4 = uVar4 + 1;
      uVar2 = uVar4 & 0xffff;
      uVar5 = (**(code **)(*param_1 + 0xc))();
    } while (uVar2 < uVar5);
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00477ef0 @ 0x00477ef0 ====

void FUN_00477ef0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4590,s_DungeonShop_009a4580);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00477f3e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00477f3e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00477d90(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00477fa0 @ 0x00477fa0 ====

void FUN_00477fa0(byte param_1)

{
  void *in_ECX;
  
  FUN_00477d70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00477fc0 @ 0x00477fc0 ====

void FUN_00477fc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a45a4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x30,0xc,FUN_006ef6d0);
  return;
}


// ==== FUN_00477fe0 @ 0x00477fe0 ====

void FUN_00477fe0(byte param_1)

{
  void *in_ECX;
  
  FUN_00477fc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00478000 @ 0x00478000 ====

char * FUN_00478000(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x28,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x28)) {
    param_1[0x27] = '\0';
  }
  return param_1;
}


// ==== FUN_00478030 @ 0x00478030 ====

void FUN_00478030(void)

{
  int in_ECX;
  
  *(undefined ***)(in_ECX + 0x30) = &PTR_FUN_009a45a4;
  _eh_vector_destructor_iterator_((void *)(in_ECX + 0x34),0x30,0xc,FUN_006ef6d0);
  return;
}


// ==== FUN_00478050 @ 0x00478050 ====

void FUN_00478050(void)

{
  FUN_00478000();
  return;
}


// ==== FUN_00478070 @ 0x00478070 ====

bool FUN_00478070(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int *in_ECX;
  undefined4 uStack_108;
  
  uStack_108 = param_2;
  (**(code **)(*in_ECX + 0x10))(param_1);
  FUN_0044a580(&uStack_108,&DAT_009a4590,&DAT_0099cf70);
  cVar1 = FUN_0044a440(&uStack_108);
  return cVar1 != '\0';
}


// ==== FUN_004780c0 @ 0x004780c0 ====

void FUN_004780c0(int *param_1,ushort param_2)

{
  char *pcVar1;
  char cVar2;
  undefined2 uVar3;
  char *pcVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int iVar9;
  undefined1 auStack_16c [12];
  undefined4 uStack_160;
  undefined1 *puStack_15c;
  undefined *puStack_158;
  uint uStack_154;
  undefined4 uStack_150;
  uint uStack_14c;
  undefined1 *puStack_140;
  undefined4 uStack_13c;
  int iStack_4;
  
  FUN_0044a580();
  uVar7 = (uint)param_2;
  (**(code **)(*param_1 + 0x10))();
  cVar2 = FUN_0044a440();
  if (cVar2 == '\0') {
    uStack_150 = 0;
    uStack_154 = 0x478118;
    uStack_14c = uVar7;
    uVar3 = FUN_00475a90();
    *(undefined2 *)param_1 = uVar3;
    uStack_150 = 1;
    uStack_154 = 0x47812d;
    uStack_14c = uVar7;
    uStack_154 = (**(code **)(*param_1 + 0x10))();
    puStack_15c = auStack_16c + 0x34;
    puStack_158 = &DAT_009a458c;
    uStack_160 = 0x47813d;
    FUN_00478000();
    pcVar1 = (char *)((int)param_1 + 2);
    puStack_140 = (undefined1 *)0x0;
    pcVar4 = pcVar1;
    do {
      cVar2 = pcVar4[(int)(auStack_16c + (0x34 - (int)pcVar1))];
      *pcVar4 = cVar2;
      if (cVar2 == '\0') goto LAB_00478172;
      puStack_140 = (undefined1 *)((int)puStack_140 + 1);
      pcVar4 = pcVar4 + 1;
    } while (puStack_140 < 0x28);
    *pcVar1 = '\0';
LAB_00478172:
    puStack_158 = (undefined *)0x2;
    puStack_15c = (undefined1 *)0x47817c;
    uStack_154 = uVar7;
    uVar3 = FUN_00475a90();
    puStack_158 = (undefined *)0x3;
    *(undefined2 *)((int)param_1 + 0x2a) = uVar3;
    puStack_15c = (undefined1 *)0x47818a;
    uStack_154 = uVar7;
    uVar3 = FUN_00475a90();
    *(undefined2 *)(param_1 + 0xb) = uVar3;
    param_1[0x9d] = param_1[0x9d] + 0xc;
    piVar8 = param_1 + 0xd;
    puStack_140 = auStack_16c + -iStack_4;
    iVar9 = 4;
    uStack_13c = 0xc;
    do {
      puStack_15c = (undefined1 *)0x4781c0;
      puStack_158 = (undefined *)iVar9;
      uStack_154 = uVar7;
      uStack_154 = (**(code **)(*param_1 + 0x10))();
      puStack_15c = auStack_16c + 0x34;
      puStack_158 = &DAT_009a458c;
      uStack_160 = 0x4781d3;
      FUN_00478000();
      uVar6 = 0;
      piVar5 = piVar8;
      do {
        cVar2 = puStack_140[(int)piVar5];
        *(char *)piVar5 = cVar2;
        if (cVar2 == '\0') goto LAB_004781fc;
        uVar6 = uVar6 + 1;
        piVar5 = (int *)((int)piVar5 + 1);
      } while (uVar6 < 0x28);
      *(char *)piVar8 = '\0';
LAB_004781fc:
      puStack_15c = (undefined1 *)0x478205;
      puStack_158 = (undefined *)(iVar9 + 1);
      uStack_154 = uVar7;
      uVar3 = FUN_00475a90();
      puStack_158 = (undefined *)(iVar9 + 2);
      *(undefined2 *)(piVar8 + 10) = uVar3;
      puStack_15c = (undefined1 *)0x478215;
      uStack_154 = uVar7;
      uVar3 = FUN_00475a90();
      puStack_158 = (undefined *)(iVar9 + 3);
      *(undefined2 *)((int)piVar8 + 0x2a) = uVar3;
      puStack_15c = (undefined1 *)0x478225;
      uStack_154 = uVar7;
      uVar3 = FUN_00475a90();
      puStack_158 = (undefined *)(iVar9 + 4);
      *(undefined2 *)(piVar8 + 0xb) = uVar3;
      puStack_15c = (undefined1 *)0x478235;
      uStack_154 = uVar7;
      uVar3 = FUN_00475a90();
      puStack_140 = puStack_140 + -0x30;
      *(undefined2 *)((int)piVar8 + 0x2e) = uVar3;
      iVar9 = iVar9 + 5;
      piVar8 = piVar8 + 0xc;
      uStack_13c = uStack_13c + -1;
    } while (uStack_13c != 0);
  }
  return;
}


// ==== FUN_00478260 @ 0x00478260 ====

void FUN_00478260(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00478270 @ 0x00478270 ====

void FUN_00478270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a45c4;
  return;
}


// ==== FUN_00478280 @ 0x00478280 ====

void FUN_00478280(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a45bc,s_PortalLocation_009a45ac);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_004782ce;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_004782ce:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00478350(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00478330 @ 0x00478330 ====

void FUN_00478330(byte param_1)

{
  void *in_ECX;
  
  FUN_00478260();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00478350 @ 0x00478350 ====

void FUN_00478350(int *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  undefined4 uStack_218;
  char acStack_108 [8];
  undefined1 auStack_100 [256];
  
  uVar5 = 1;
  uVar2 = (**(code **)(*param_1 + 8))();
  if (uVar2 < 2) {
    return;
  }
LAB_00478374:
  uStack_218 = &DAT_0099cf70;
  FUN_0044a580(auStack_100,&DAT_009a45bc);
  uStack_218 = (undefined1 *)0x0;
  pcVar3 = (char *)(**(code **)(*param_1 + 0x10))(uVar5);
  uVar2 = 0;
  iVar4 = -(int)pcVar3;
  do {
    if (*pcVar3 != pcVar3[(int)(acStack_108 + iVar4)]) {
      FUN_00478a60();
      FUN_00797a50((int)register0x00000010 + -0x210,0,0x108);
      FUN_00475a90(uVar5,0);
      FUN_00475a90(uVar5,1);
      FUN_00475a90(uVar5,2);
      FUN_004753b0(uVar5,3);
      iVar4 = (**(code **)(*param_1 + 0x10))(uVar5,4);
      uVar2 = 0;
      goto LAB_00478431;
    }
    if (*pcVar3 == '\0') break;
    uVar2 = uVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar2 < 0x100);
  goto LAB_0047845e;
  while (uVar2 = uVar2 + 1, uVar2 < 0x100) {
LAB_00478431:
    cVar1 = ((char *)((int)register0x00000010 + (uVar2 - 0x211)))
            [iVar4 - ((int)register0x00000010 + -0x211)];
    *(char *)((int)register0x00000010 + (uVar2 - 0x211)) = cVar1;
    if (cVar1 == '\0') break;
  }
  (**(code **)(*DAT_00b5ab20 + 4))(&uStack_218);
LAB_0047845e:
  uVar5 = uVar5 + 1;
  uVar2 = (**(code **)(*param_1 + 8))();
  if (uVar2 <= uVar5) {
    return;
  }
  goto LAB_00478374;
}


// ==== FUN_00478480 @ 0x00478480 ====

void FUN_00478480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00478490 @ 0x00478490 ====

void FUN_00478490(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a45e8;
  return;
}


// ==== FUN_004784a0 @ 0x004784a0 ====

void FUN_004784a0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a45e0,s_ItemSellPrice_009a45d0);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_004784ee;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_004784ee:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00478570(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00478550 @ 0x00478550 ====

void FUN_00478550(byte param_1)

{
  void *in_ECX;
  
  FUN_00478480();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00478570 @ 0x00478570 ====

void FUN_00478570(int *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *piStack_64;
  undefined4 *puStack_60;
  undefined4 *puStack_5c;
  undefined4 *puStack_58;
  int iStack_54;
  undefined4 *puStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  int iStack_34;
  
  uVar3 = 1;
  uStack_4c = (undefined4 *)0x47858b;
  uVar2 = (**(code **)(*param_1 + 8))();
  if (1 < uVar2) {
    do {
      uStack_4c = (undefined4 *)0x0;
      iStack_54 = 0x47859d;
      puStack_50 = (undefined4 *)uVar3;
      FUN_00475a90();
      uStack_4c = (undefined4 *)0x1;
      iStack_54 = 0x4785a7;
      puStack_50 = (undefined4 *)uVar3;
      uStack_3c = FUN_004756e0();
      uStack_4c = &uStack_3c;
      iVar1 = uVar3 - 1;
      puStack_50 = &uStack_38;
      uStack_38 = 0;
      iStack_54 = 0x4785cf;
      iStack_34 = iVar1;
      (**(code **)(*DAT_00b5ab24 + 4))();
      iStack_54 = 2;
      puStack_5c = (undefined4 *)0x4785d9;
      puStack_58 = (undefined4 *)uVar3;
      FUN_004756e0();
      iStack_54 = (int)register0x00000010 + -0x44;
      puStack_58 = &uStack_38;
      uStack_38 = 1;
      puStack_5c = (undefined4 *)0x4785fe;
      iStack_34 = iVar1;
      (**(code **)(*DAT_00b5ab24 + 4))();
      puStack_5c = (undefined4 *)0x3;
      piStack_64 = (int *)0x478608;
      puStack_60 = (undefined4 *)uVar3;
      uStack_4c = (undefined4 *)FUN_004756e0();
      puStack_5c = &uStack_4c;
      puStack_60 = &uStack_38;
      uStack_38 = 2;
      piStack_64 = (int *)0x47862d;
      iStack_34 = iVar1;
      (**(code **)(*DAT_00b5ab24 + 4))();
      piStack_64 = (int *)0x4;
      iStack_54 = FUN_004756e0(uVar3);
      piStack_64 = &iStack_54;
      uStack_38 = 3;
      iStack_34 = iVar1;
      (**(code **)(*DAT_00b5ab24 + 4))(&uStack_38);
      puStack_5c = (undefined4 *)FUN_004756e0(uVar3,5);
      uStack_38 = 4;
      iStack_34 = iVar1;
      (**(code **)(*DAT_00b5ab24 + 4))(&uStack_38,&puStack_5c);
      piStack_64 = (int *)FUN_004756e0(uVar3,6);
      uStack_38 = 5;
      iStack_34 = iVar1;
      (**(code **)(*DAT_00b5ab24 + 4))(&uStack_38,&piStack_64);
      uVar3 = uVar3 + 1;
      uVar2 = (**(code **)(*param_1 + 8))();
    } while (uVar3 < uVar2);
  }
  return;
}


// ==== FUN_004786e0 @ 0x004786e0 ====

void FUN_004786e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_004786f0 @ 0x004786f0 ====

void FUN_004786f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a460c;
  return;
}


// ==== FUN_00478700 @ 0x00478700 ====

void FUN_00478700(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4604,s_ItemAddSocket_009a45f4);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0047874e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0047874e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_004787d0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_004787b0 @ 0x004787b0 ====

void FUN_004787b0(byte param_1)

{
  void *in_ECX;
  
  FUN_004786e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004787d0 @ 0x004787d0 ====

void FUN_004787d0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  undefined1 uStack_3;
  
  uVar1 = (**(code **)(*param_1 + 8))();
  if (1 < uVar1) {
    uVar1 = 1;
    do {
      uVar2 = FUN_00475a90(uVar1,0);
      uStack_4 = FUN_004753b0(uVar1,9);
      uStack_3 = FUN_004753b0(uVar1,10);
      uStack_c = FUN_004756e0(uVar1,1);
      uStack_8 = FUN_004756e0(uVar1,2);
      uVar2 = uVar2 & 0xffff;
      uStack_34 = 0;
      uStack_30 = uVar2;
      (**(code **)(*DAT_00b5aa28 + 4))(&uStack_34,&uStack_c);
      uStack_14 = FUN_004756e0(uVar1,3);
      uStack_10 = FUN_004756e0(uVar1,4);
      uStack_34 = 1;
      uStack_30 = uVar2;
      (**(code **)(*DAT_00b5aa28 + 4))(&uStack_34,&uStack_14);
      uStack_1c = FUN_004756e0(uVar1,3);
      uStack_18 = FUN_004756e0(uVar1,4);
      uStack_34 = 2;
      uStack_30 = uVar2;
      (**(code **)(*DAT_00b5aa28 + 4))(&uStack_34,&uStack_1c);
      uStack_24 = FUN_004756e0(uVar1,5);
      uStack_20 = FUN_004756e0(uVar1,6);
      uStack_34 = 3;
      uStack_30 = uVar2;
      (**(code **)(*DAT_00b5aa28 + 4))(&uStack_34,&uStack_24);
      uStack_2c = FUN_004756e0(uVar1,7);
      uStack_28 = FUN_004756e0(uVar1,8);
      uStack_34 = 4;
      uStack_30 = uVar2;
      (**(code **)(*DAT_00b5aa28 + 4))(&uStack_34,&uStack_2c);
      uVar1 = uVar1 + 1;
      uVar2 = (**(code **)(*param_1 + 8))();
    } while (uVar1 < uVar2);
  }
  return;
}


// ==== FUN_00478970 @ 0x00478970 ====

void FUN_00478970(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00478980 @ 0x00478980 ====

void FUN_00478980(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4630;
  return;
}


// ==== FUN_00478990 @ 0x00478990 ====

void FUN_00478990(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4628,s_ChaoticLocation_009a4618);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_004789de;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_004789de:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00478a70(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00478a40 @ 0x00478a40 ====

void FUN_00478a40(byte param_1)

{
  void *in_ECX;
  
  FUN_00478970();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00478a60 @ 0x00478a60 ====

void FUN_00478a60(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 7) = 0;
  return;
}


// ==== FUN_00478a70 @ 0x00478a70 ====

void FUN_00478a70(int *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  undefined4 uStack_218;
  char acStack_108 [8];
  undefined1 auStack_100 [256];
  
  uVar5 = 1;
  uVar2 = (**(code **)(*param_1 + 8))();
  if (uVar2 < 2) {
    return;
  }
LAB_00478a94:
  uStack_218 = &DAT_0099cf70;
  FUN_0044a580(auStack_100,&DAT_009a4628);
  uStack_218 = (undefined1 *)0x0;
  pcVar3 = (char *)(**(code **)(*param_1 + 0x10))(uVar5);
  uVar2 = 0;
  iVar4 = -(int)pcVar3;
  do {
    if (*pcVar3 != pcVar3[(int)(acStack_108 + iVar4)]) {
      FUN_00478a60();
      FUN_00797a50((int)register0x00000010 + -0x210,0,0x108);
      FUN_00475a90(uVar5,0);
      FUN_00475a90(uVar5,1);
      FUN_00475a90(uVar5,2);
      FUN_004753b0(uVar5,3);
      iVar4 = (**(code **)(*param_1 + 0x10))(uVar5,4);
      uVar2 = 0;
      goto LAB_00478b51;
    }
    if (*pcVar3 == '\0') break;
    uVar2 = uVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar2 < 0x100);
  goto LAB_00478b7e;
  while (uVar2 = uVar2 + 1, uVar2 < 0x100) {
LAB_00478b51:
    cVar1 = ((char *)((int)register0x00000010 + (uVar2 - 0x211)))
            [iVar4 - ((int)register0x00000010 + -0x211)];
    *(char *)((int)register0x00000010 + (uVar2 - 0x211)) = cVar1;
    if (cVar1 == '\0') break;
  }
  (**(code **)(*DAT_00b5ab28 + 4))(&uStack_218);
LAB_00478b7e:
  uVar5 = uVar5 + 1;
  uVar2 = (**(code **)(*param_1 + 8))();
  if (uVar2 <= uVar5) {
    return;
  }
  goto LAB_00478a94;
}


// ==== FUN_00478ba0 @ 0x00478ba0 ====

void FUN_00478ba0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00478bb0 @ 0x00478bb0 ====

void FUN_00478bb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4718;
  return;
}


// ==== FUN_00478bc0 @ 0x00478bc0 ====

long FUN_00478bc0(char *param_1)

{
  char cVar1;
  uint uVar2;
  long lVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  char local_100 [256];
  
  uVar2 = 0;
  do {
    if (param_1[uVar2] == '\0') goto LAB_00478be2;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  uVar2 = 0;
LAB_00478be2:
  uVar6 = 0;
  if (uVar2 != 0) {
    do {
      if ((param_1[uVar6] < '0') || ('9' < param_1[uVar6])) {
        FUN_0044a580(local_100,&DAT_009a4710,s_NOT_FAIL_009a4648);
        uVar2 = 0;
        pcVar4 = param_1;
        do {
          if (*pcVar4 != pcVar4[(int)(local_100 + -(int)param_1)]) {
            FUN_0044a580(local_100,&DAT_009a4710,s_BACKWARD_ITEM_009a4654);
            uVar2 = 0;
            pcVar4 = param_1;
            do {
              if (*pcVar4 != pcVar4[(int)(local_100 + -(int)param_1)]) {
                FUN_0044a580(local_100,&DAT_009a4710,s_TARGETITEM_DESTRUCT_009a4664);
                uVar2 = 0;
                pcVar4 = param_1;
                do {
                  if (*pcVar4 != pcVar4[(int)(local_100 + -(int)param_1)]) {
                    FUN_0044a580(local_100,&DAT_009a4710,s_APPLYITEM_DESTRUCT_009a4678);
                    cVar1 = FUN_0044a440(local_100);
                    if (cVar1 != '\0') {
                      return 3;
                    }
                    FUN_0044a580(local_100,&DAT_009a4710,s_ALLITEM_DESTRUCT_009a468c);
                    cVar1 = FUN_0044a440(local_100);
                    if (cVar1 != '\0') {
                      return 4;
                    }
                    FUN_0044a580(local_100,&DAT_009a4710,s_BACK_TO_ZERO_009a46a0);
                    cVar1 = FUN_0044a440(local_100);
                    if (cVar1 == '\0') {
                      local_100[0] = '\0';
                      uVar5 = FUN_0044a580(local_100,s_CANNOT_FIND_ITEMUPGRADE_Penalty___009a46b0,
                                           param_1);
                      FUN_00797b80(uVar5);
                      local_100[0] = '\0';
                      uVar5 = FUN_0044a580(local_100,s_File___s__Line___d_009a46fc,
                                           s___Loader_Support_ItemUpgrade_cpp_009a46d8,0x85);
                      FUN_00797b80(uVar5);
                      FUN_00797a40();
                      return 0;
                    }
                    return 5;
                  }
                  if (*pcVar4 == '\0') {
                    return 2;
                  }
                  uVar2 = uVar2 + 1;
                  pcVar4 = pcVar4 + 1;
                } while (uVar2 < 0x100);
                return 2;
              }
              if (*pcVar4 == '\0') {
                return 1;
              }
              uVar2 = uVar2 + 1;
              pcVar4 = pcVar4 + 1;
            } while (uVar2 < 0x100);
            return 1;
          }
          if (*pcVar4 == '\0') {
            return 0;
          }
          uVar2 = uVar2 + 1;
          pcVar4 = pcVar4 + 1;
        } while (uVar2 < 0x100);
        return 0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < uVar2);
  }
  uVar2 = 0;
  do {
    if (param_1[uVar2] == '\0') {
      if (uVar2 == 0) {
        return 0;
      }
      lVar3 = _atol(param_1);
      return lVar3;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  return 0;
}


// ==== FUN_00478e10 @ 0x00478e10 ====

void FUN_00478e10(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4710,s_ItemUpgrade_009a463c);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00478e5e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00478e5e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00479360(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00478ec0 @ 0x00478ec0 ====

void FUN_00478ec0(byte param_1)

{
  void *in_ECX;
  
  FUN_00478ba0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00478ee0 @ 0x00478ee0 ====

undefined4 FUN_00478ee0(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_100 [256];
  
  FUN_0044a580(local_100,&DAT_009a4710,s_SHORT_SWORD_009a4864);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 0x400;
  }
  FUN_0044a580(local_100,&DAT_009a4710,s_SWORD_009a485c);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 0x401;
  }
  FUN_0044a580(local_100,&DAT_009a4710,s_LONG_SWORD_009a4850);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 0x402;
  }
  FUN_0044a580(local_100,&DAT_009a4710,s_GREAT_SWORD_009a4844);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 0x403;
  }
  FUN_0044a580(local_100,&DAT_009a4710,s_SPEAR_009a483c);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 0x404;
  }
  uVar2 = FUN_0044a670(s_POLEARM_009a4834);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x405;
  }
  uVar2 = FUN_0044a670(&DAT_009a482c);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x406;
  }
  uVar2 = FUN_0044a670(s_GREAT_MACE_009a4820);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x407;
  }
  uVar2 = FUN_0044a670(&DAT_009a481c);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x408;
  }
  uVar2 = FUN_0044a670(s_GREAT_AX_009a4810);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x409;
  }
  uVar2 = FUN_0044a670(&DAT_009a480c);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x40a;
  }
  uVar2 = FUN_0044a670(s_CROSS_BOW_009a4800);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x40b;
  }
  uVar2 = FUN_0044a670(s_STAFF_009a47f8);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x40c;
  }
  uVar2 = FUN_0044a670(&DAT_009a47f0);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x40d;
  }
  uVar2 = FUN_0044a670(s_SHIELD_009a47e8);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x40e;
  }
  uVar2 = FUN_0044a670(s_TWIN_SWORD_009a47dc);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x411;
  }
  uVar2 = FUN_0044a670(s_BLOODWHIP_009a47d0);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x412;
  }
  uVar2 = FUN_0044a670(s_FISHING_ROD_009a47c4);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x413;
  }
  uVar2 = FUN_0044a670(s_GAUNTLET_009a47b8);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x414;
  }
  uVar2 = FUN_0044a670(s_HELMET_009a47b0);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x500;
  }
  uVar2 = FUN_0044a670(&DAT_009a47a8);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x501;
  }
  uVar2 = FUN_0044a670(s_PANTS_009a47a0);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x502;
  }
  uVar2 = FUN_0044a670(s_BOOTS_009a4798);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x503;
  }
  uVar2 = FUN_0044a670(s_GLOVES_009a4790);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 == '\0') {
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,&DAT_009a4748,param_1);
    FUN_00797b80(uVar2);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                         s___Loader_Support_ItemUpgrade_cpp_009a4720,0xae);
    FUN_00797b80(uVar2);
    FUN_00797a40();
    return 0;
  }
  return 0x504;
}


// ==== FUN_00479360 @ 0x00479360 ====

void FUN_00479360(int *param_1)

{
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 auStack_112 [10];
  char acStack_108 [264];
  
  uVar5 = 1;
  uVar1 = (**(code **)(*param_1 + 8))();
  if (1 < uVar1) {
    do {
      pcVar2 = (char *)(**(code **)(*param_1 + 0x10))(uVar5,0);
      FUN_0044a580(acStack_108,&DAT_009a4710,&DAT_0099cf70);
      uVar1 = 0;
      pcVar3 = pcVar2;
      do {
        if (*pcVar3 != pcVar3[(int)(acStack_108 + -(int)pcVar2)]) {
          FUN_00797a50(auStack_112 + -10,0,0x10);
          FUN_00478ee0(pcVar2);
          FUN_00475a90(uVar5,1);
          FUN_00475a90(uVar5,2);
          FUN_004756e0(uVar5,3);
          FUN_004753b0(uVar5,4);
          uVar4 = (**(code **)(*param_1 + 0x10))(uVar5,5);
          FUN_00478bc0(uVar4);
          (**(code **)(*DAT_00b5ab2c + 4))(auStack_112 + -0x12);
          break;
        }
        if (*pcVar3 == '\0') break;
        uVar1 = uVar1 + 1;
        pcVar3 = pcVar3 + 1;
      } while (uVar1 < 0x100);
      uVar5 = uVar5 + 1;
      uVar1 = (**(code **)(*param_1 + 8))();
    } while (uVar5 < uVar1);
  }
  return;
}


// ==== FUN_00479490 @ 0x00479490 ====

void FUN_00479490(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_004794a0 @ 0x004794a0 ====

void FUN_004794a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4888;
  return;
}


// ==== FUN_004794b0 @ 0x004794b0 ====

void FUN_004794b0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4880,s_LevelCap_009a4874);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_004794fc;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_004794fc:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00479550 @ 0x00479550 ====

void FUN_00479550(byte param_1)

{
  void *in_ECX;
  
  FUN_00479490();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00479570 @ 0x00479570 ====

void FUN_00479570(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00479580 @ 0x00479580 ====

void FUN_00479580(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a48a8;
  return;
}


// ==== FUN_00479590 @ 0x00479590 ====

void FUN_00479590(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a48a0,s_StartPoint_009a4894);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_004795de;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_004795de:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00479660(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00479640 @ 0x00479640 ====

void FUN_00479640(byte param_1)

{
  void *in_ECX;
  
  FUN_00479570();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00479660 @ 0x00479660 ====

void FUN_00479660(int *param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  char acStack_108 [8];
  undefined1 auStack_100 [256];
  
  uVar4 = 1;
  uVar2 = (**(code **)(*param_1 + 8))();
  if (1 < uVar2) {
    do {
      FUN_0044a580(auStack_100,&DAT_009a48a0,&DAT_0099cf70);
      pcVar3 = (char *)(**(code **)(*param_1 + 0x10))(uVar4,0);
      uVar2 = 0;
      iVar1 = -(int)pcVar3;
      do {
        if (*pcVar3 != pcVar3[(int)(acStack_108 + iVar1)]) {
          FUN_00797a50(acStack_108 + -8,0,6);
          FUN_00475a90(uVar4,0);
          FUN_00475a90(uVar4,1);
          FUN_00475a90(uVar4,2);
          (**(code **)(*DAT_00b5ab30 + 4))(acStack_108 + -8);
          break;
        }
        if (*pcVar3 == '\0') break;
        uVar2 = uVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (uVar2 < 0x100);
      uVar4 = uVar4 + 1;
      uVar2 = (**(code **)(*param_1 + 8))();
    } while (uVar4 < uVar2);
  }
  return;
}


// ==== FUN_00479750 @ 0x00479750 ====

void FUN_00479750(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00479760 @ 0x00479760 ====

void FUN_00479760(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a48c8;
  return;
}


// ==== FUN_00479770 @ 0x00479770 ====

void FUN_00479770(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a48c0,s_Location_009a48b4);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_004797be;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_004797be:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00479850(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00479820 @ 0x00479820 ====

void FUN_00479820(byte param_1)

{
  void *in_ECX;
  
  FUN_00479750();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00479840 @ 0x00479840 ====

void FUN_00479840(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 2) = 0;
  return;
}


// ==== FUN_00479850 @ 0x00479850 ====

void FUN_00479850(int *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  undefined4 uStack_220;
  char acStack_108 [8];
  undefined1 auStack_100 [256];
  
  uVar5 = 1;
  uVar2 = (**(code **)(*param_1 + 8))();
  if (uVar2 < 2) {
    return;
  }
LAB_00479874:
  uStack_220 = &DAT_0099cf70;
  FUN_0044a580(auStack_100,&DAT_009a48c0);
  uStack_220 = (undefined1 *)0x0;
  pcVar3 = (char *)(**(code **)(*param_1 + 0x10))(uVar5);
  uVar2 = 0;
  iVar4 = -(int)pcVar3;
  do {
    if (*pcVar3 != pcVar3[(int)(acStack_108 + iVar4)]) {
      FUN_00479840();
      FUN_00797a50((int)register0x00000010 + -0x218,0,0x110);
      FUN_00475a90(uVar5,0);
      iVar4 = (**(code **)(*param_1 + 0x10))(uVar5,1);
      uVar2 = 0;
      goto LAB_00479905;
    }
    if (*pcVar3 == '\0') break;
    uVar2 = uVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar2 < 0x100);
  goto LAB_004799ae;
  while (uVar2 = uVar2 + 1, uVar2 < 0x100) {
LAB_00479905:
    pcVar3 = (char *)((int)&uStack_220 + uVar2 + 2);
    cVar1 = pcVar3[iVar4 - ((int)&uStack_220 + 2)];
    *pcVar3 = cVar1;
    if (cVar1 == '\0') goto LAB_00479922;
  }
  uStack_220._0_3_ = (uint3)(ushort)uStack_220;
LAB_00479922:
  FUN_00475a90(uVar5,2);
  FUN_00475a90(uVar5,3);
  FUN_00475a90(uVar5,4);
  FUN_004753b0(uVar5,5);
  FUN_00475a90(uVar5,6);
  FUN_00475a90(uVar5,7);
  FUN_004753b0(uVar5,8);
  (**(code **)(*DAT_00b5ab34 + 4))(&uStack_220);
LAB_004799ae:
  uVar5 = uVar5 + 1;
  uVar2 = (**(code **)(*param_1 + 8))();
  if (uVar2 <= uVar5) {
    return;
  }
  goto LAB_00479874;
}


// ==== FUN_004799d0 @ 0x004799d0 ====

void FUN_004799d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_004799e0 @ 0x004799e0 ====

void FUN_004799e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a48f0;
  return;
}


// ==== FUN_004799f0 @ 0x004799f0 ====

void FUN_004799f0(int *param_1)

{
  byte bVar1;
  byte bVar2;
  undefined2 uVar3;
  uint uVar4;
  char *pcVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined1 auStack_1ae [6];
  undefined4 auStack_1a8 [3];
  undefined2 auStack_19c [66];
  int iStack_118;
  char acStack_114 [8];
  undefined1 auStack_10c [256];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097dcbb;
  pvStack_c = ExceptionList;
  uVar7 = 1;
  ExceptionList = &pvStack_c;
  uVar4 = (**(code **)(*param_1 + 0xc))();
  if (uVar4 < 2) {
    ExceptionList = pvStack_c;
    return;
  }
  do {
    FUN_0044a580(auStack_10c,&DAT_009a48e0,s_Teleport_009a48d4 + 9);
    pcVar5 = (char *)(**(code **)(*param_1 + 0x10))(uVar7,0);
    uVar4 = 0;
    iVar8 = -(int)pcVar5;
    while (*pcVar5 == pcVar5[(int)(acStack_114 + iVar8)]) {
      if (*pcVar5 == '\0') goto LAB_00479b7f;
      uVar4 = uVar4 + 1;
      pcVar5 = pcVar5 + 1;
      if (0xff < uVar4) goto LAB_00479b7f;
    }
    iStack_118 = 0;
    pvStack_c = (void *)0x0;
    FUN_00797a50(auStack_1ae + -6,0,0xa0);
    FUN_00475a90(uVar7,0);
    FUN_00475a90(uVar7,1);
    bVar1 = FUN_004753b0(uVar7,2);
    iStack_118 = iStack_118 + (uint)bVar1;
    iVar8 = 3;
    bVar2 = 0;
    if (bVar1 != 0) {
      do {
        uVar4 = (uint)bVar2;
        uVar3 = FUN_00475a90(uVar7,iVar8);
        *(undefined2 *)(auStack_1a8 + uVar4 * 4) = uVar3;
        uVar3 = FUN_00475a90(uVar7,iVar8 + 1);
        *(undefined2 *)((int)auStack_1a8 + (uVar4 * 8 + 1) * 2) = uVar3;
        uVar3 = FUN_00475a90(uVar7,iVar8 + 2);
        *(undefined2 *)(auStack_1a8 + uVar4 * 4 + 1) = uVar3;
        uVar6 = FUN_004756e0(uVar7,iVar8 + 3);
        auStack_1a8[uVar4 * 4 + 2] = uVar6;
        uVar3 = FUN_00475a90(uVar7,iVar8 + 4);
        auStack_19c[uVar4 * 8] = uVar3;
        bVar2 = bVar2 + 1;
        iVar8 = iVar8 + 5;
      } while (bVar2 < bVar1);
    }
    (**(code **)(*DAT_00b5ab38 + 4))(auStack_1ae + -6);
    pvStack_c = (void *)0xffffffff;
LAB_00479b7f:
    uVar7 = uVar7 + 1;
    uVar4 = (**(code **)(*param_1 + 0xc))();
    if (uVar4 <= uVar7) {
      ExceptionList = pvStack_c;
      return;
    }
  } while( true );
}


// ==== FUN_00479bb0 @ 0x00479bb0 ====

void FUN_00479bb0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a48e0,s_Teleport_009a48d4);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00479bfe;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00479bfe:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_004799f0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00479c60 @ 0x00479c60 ====

void FUN_00479c60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a48e8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00479c80 @ 0x00479c80 ====

void FUN_00479c80(byte param_1)

{
  void *in_ECX;
  
  FUN_004799d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00479ca0 @ 0x00479ca0 ====

void FUN_00479ca0(void)

{
  int in_ECX;
  
  *(undefined ***)(in_ECX + 8) = &PTR_FUN_009a48e8;
  return;
}


// ==== FUN_00479cb0 @ 0x00479cb0 ====

void FUN_00479cb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00479cc0 @ 0x00479cc0 ====

void FUN_00479cc0(void)

{
  return;
}


// ==== FUN_00479cd0 @ 0x00479cd0 ====

void FUN_00479cd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4904;
  return;
}


// ==== FUN_00479ce0 @ 0x00479ce0 ====

void FUN_00479ce0(byte param_1)

{
  void *in_ECX;
  
  FUN_00479cb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00479d00 @ 0x00479d00 ====

void FUN_00479d00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00479d10 @ 0x00479d10 ====

void FUN_00479d10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4920;
  return;
}


// ==== FUN_00479d20 @ 0x00479d20 ====

void FUN_00479d20(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4918,s_Combo_009a4910);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00479d6e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00479d6e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00479df0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00479dd0 @ 0x00479dd0 ====

void FUN_00479dd0(byte param_1)

{
  void *in_ECX;
  
  FUN_00479d00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00479df0 @ 0x00479df0 ====

void FUN_00479df0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 uStack_4;
  undefined1 uStack_3;
  undefined1 uStack_2;
  undefined1 uStack_1;
  
  uVar2 = 1;
  uVar1 = (**(code **)(*param_1 + 0xc))();
  if (1 < uVar1) {
    do {
      uStack_8 = FUN_004753b0(0,uVar2);
      uStack_7 = FUN_004753b0(1,uVar2);
      uStack_6 = FUN_004753b0(2,uVar2);
      uStack_5 = FUN_004753b0(3,uVar2);
      uStack_4 = FUN_004753b0(4,uVar2);
      uStack_3 = FUN_004753b0(5,uVar2);
      uStack_2 = FUN_004753b0(6,uVar2);
      uStack_1 = FUN_004753b0(7,uVar2);
      (**(code **)(*DAT_00b5ab44 + 4))(&uStack_8);
      uVar2 = uVar2 + 1;
      uVar1 = (**(code **)(*param_1 + 0xc))();
    } while (uVar2 < uVar1);
  }
  return;
}


// ==== FUN_00479eb0 @ 0x00479eb0 ====

void FUN_00479eb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00479ec0 @ 0x00479ec0 ====

uint FUN_00479ec0(char *param_1,int *param_2)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  if ((int)pcVar2 - (int)(param_1 + 1) != 8) {
    return (int)pcVar2 - (int)(param_1 + 1) & 0xffffff00;
  }
  *param_2 = 0;
  uVar5 = 0x10000000;
  iVar4 = 0;
  uVar3 = 0;
  do {
    cVar1 = param_1[iVar4];
    if ((cVar1 < '0') || ('9' < cVar1)) {
      if ((cVar1 < 'A') || ('F' < cVar1)) {
        if ((cVar1 < 'a') || ('f' < cVar1)) {
          return uVar3 & 0xffffff00;
        }
        uVar3 = (int)cVar1 - 0x57;
      }
      else {
        uVar3 = (int)cVar1 - 0x37;
      }
    }
    else {
      uVar3 = (int)cVar1 - 0x30;
    }
    if (iVar4 != 7) {
      uVar3 = uVar3 * uVar5;
    }
    *param_2 = *param_2 + uVar3;
    iVar4 = iVar4 + 1;
    uVar5 = uVar5 >> 4;
  } while (iVar4 < 8);
  return CONCAT31((int3)(uVar3 >> 8),1);
}


// ==== FUN_00479f50 @ 0x00479f50 ====

void FUN_00479f50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a499c;
  return;
}


// ==== FUN_00479f60 @ 0x00479f60 ====

undefined4 FUN_00479f60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  char local_100 [256];
  
  FUN_0044a580(local_100,&DAT_009a4994,&DAT_009a493c);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 1;
  }
  FUN_0044a580(local_100,&DAT_009a4994,&DAT_009a4940);
  local_100[0] = FUN_0044a440(local_100);
  if (local_100[0] == '\0') {
    uVar2 = FUN_0044a580(local_100,s__s_field_is_not_Y_or_N__row__d_009a4944,param_2,param_3);
    FUN_00797b80(uVar2);
    local_100[0] = '\0';
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009a4980,
                         s___Loader_Arrange_Cell_cpp_009a4964,0x67);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  return 0;
}


// ==== FUN_0047a030 @ 0x0047a030 ====

void FUN_0047a030(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4994,s_Cell_Arrange_009a492c);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0047a07e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0047a07e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_0047a110(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_0047a0e0 @ 0x0047a0e0 ====

void FUN_0047a0e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00479eb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047a100 @ 0x0047a100 ====

void FUN_0047a100(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xb) = 0;
  return;
}


// ==== FUN_0047a110 @ 0x0047a110 ====

void FUN_0047a110(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  ushort uVar3;
  undefined2 uVar4;
  uint uVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  ushort uVar9;
  uint unaff_ESI;
  char *pcVar10;
  undefined4 uVar11;
  char *pcStack_798;
  char *pcStack_794;
  undefined4 uStack_790;
  undefined1 *puStack_78c;
  undefined4 uStack_788;
  undefined4 uStack_784;
  undefined2 auStack_680 [2];
  undefined4 auStack_67c [27];
  undefined1 auStack_610 [248];
  undefined1 auStack_518 [272];
  char acStack_408 [232];
  undefined1 auStack_320 [272];
  char acStack_210 [256];
  char acStack_110 [272];
  
  pcVar10 = (char *)0x1;
  uVar5 = (**(code **)(*param_1 + 8))();
  if (uVar5 < 2) {
    return;
  }
LAB_0047a140:
  uStack_784 = 0x47a149;
  FUN_0047a100();
  uStack_784 = 0;
  puStack_78c = (undefined1 *)0x47a153;
  uStack_788 = pcVar10;
  pcVar6 = (char *)(**(code **)(*param_1 + 0x10))();
  puStack_78c = &DAT_0099cf70;
  pcStack_794 = acStack_408;
  uStack_790 = &DAT_009a4994;
  pcStack_798 = (char *)0x47a16c;
  FUN_0044a580();
  uVar5 = 0;
  iVar8 = -(int)pcVar6;
  do {
    if (*pcVar6 != pcVar6[(int)(acStack_408 + iVar8)]) {
      puStack_78c = (undefined1 *)0x0;
      pcStack_794 = (char *)0x47a1ac;
      uStack_790 = pcVar10;
      FUN_00475a90();
      puStack_78c = (undefined1 *)0x1;
      pcStack_794 = (char *)0x47a1bb;
      uStack_790 = pcVar10;
      pcStack_798 = (char *)(**(code **)(*param_1 + 0x10))();
      pcStack_794 = (char *)((int)register0x00000010 + -0x780);
      cVar1 = FUN_00479ec0();
      if (cVar1 == '\0') {
        pcStack_794 = (char *)(unaff_ESI & 0xffff);
        pcStack_798 = s_COLOR_field_has_error__index__d_009a49e0;
        acStack_110[0] = cVar1;
        uVar7 = FUN_0044a580(acStack_110);
        FUN_00797b80(uVar7);
        auStack_610[0] = 0;
        uVar7 = FUN_0044a580(auStack_610,s_File___s__Line___d_0099f0a0,
                             s___Loader_Arrange_Cell_cpp_009a49c4,0x41);
        FUN_00797b80(uVar7);
        pcStack_794 = (char *)0x47a228;
        FUN_00797a40();
      }
      pcStack_794 = s_BLOCKED_009a49bc;
      pcStack_798 = &DAT_009a4994;
      FUN_0044a580(acStack_210);
      pcStack_798 = acStack_210;
      uVar11 = 2;
      pcVar6 = pcVar10;
      pcStack_794 = pcVar10;
      uVar7 = (**(code **)(*param_1 + 0x10))(pcVar10,2);
      uVar2 = FUN_00479f60(uVar7,pcVar6,uVar11);
      unaff_ESI = CONCAT31((int3)(unaff_ESI >> 8),uVar2);
      FUN_0044a580(auStack_518,&DAT_009a4994,s_REMOTEBLOCKED_009a49ac);
      uVar11 = 4;
      pcVar6 = pcVar10;
      uVar7 = (**(code **)(*param_1 + 0x10))(pcVar10,4,auStack_518,pcVar10);
      FUN_00479f60(uVar7,pcVar6,uVar11);
      FUN_0044a580(auStack_320,&DAT_009a4994,s_FISHING_009a49a4);
      uVar11 = 3;
      pcVar6 = pcVar10;
      uVar7 = (**(code **)(*param_1 + 0x10))(pcVar10,3,auStack_320,pcVar10);
      uVar2 = FUN_00479f60(uVar7,pcVar6,uVar11);
      uStack_788._0_3_ = CONCAT12(uVar2,(undefined2)uStack_788);
      iVar8 = (**(code **)(*param_1 + 0x10))(pcVar10,5);
      uVar5 = 0;
      goto LAB_0047a2f0;
    }
    if (*pcVar6 == '\0') break;
    uVar5 = uVar5 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar5 < 0x100);
  goto LAB_0047a39d;
  while (uVar5 = uVar5 + 1, uVar5 < 0x100) {
LAB_0047a2f0:
    pcVar6 = (char *)((int)&uStack_790 + uVar5 + 3);
    cVar1 = pcVar6[iVar8 - ((int)&uStack_790 + 3)];
    *pcVar6 = cVar1;
    if (cVar1 == '\0') goto LAB_0047a30e;
  }
  uStack_790 = (char *)((uint)uStack_790 & 0xffffff);
LAB_0047a30e:
  FUN_004753b0(pcVar10,6);
  FUN_004756e0(pcVar10,7);
  uVar3 = FUN_00475a90(pcVar10,8);
  uVar9 = 0;
  if (uVar3 != 0) {
    do {
      uVar5 = (uint)uVar9;
      uVar4 = FUN_00475a90(pcVar10,uVar5 * 2 + 9);
      auStack_680[uVar5 * 4] = uVar4;
      uVar7 = FUN_004756e0(pcVar10,uVar5 * 2 + 10);
      uVar9 = uVar9 + 1;
      auStack_67c[uVar5 * 2] = uVar7;
    } while (uVar9 < uVar3);
  }
  (**(code **)(*DAT_00b5ab10 + 4))(&pcStack_798);
LAB_0047a39d:
  pcVar10 = pcVar10 + 1;
  puStack_78c = (undefined1 *)0x47a3a7;
  pcVar6 = (char *)(**(code **)(*param_1 + 8))();
  if (pcVar6 <= pcVar10) {
    return;
  }
  goto LAB_0047a140;
}


// ==== FUN_0047a3c0 @ 0x0047a3c0 ====

void FUN_0047a3c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047a3d0 @ 0x0047a3d0 ====

void FUN_0047a3d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4a20;
  return;
}


// ==== FUN_0047a3e0 @ 0x0047a3e0 ====

void FUN_0047a3e0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4a18,s_Warp_Arrange_009a4a08);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0047a42e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0047a42e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_0047a4b0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_0047a490 @ 0x0047a490 ====

void FUN_0047a490(byte param_1)

{
  void *in_ECX;
  
  FUN_0047a3c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047a4b0 @ 0x0047a4b0 ====

void FUN_0047a4b0(int *param_1)

{
  int iVar1;
  uint uVar2;
  char *pcVar3;
  uint uVar4;
  undefined1 auStack_10a [2];
  char acStack_108 [264];
  
  uVar4 = 1;
  uVar2 = (**(code **)(*param_1 + 8))();
  if (1 < uVar2) {
    do {
      acStack_108[0] = '\0';
      acStack_108[1] = '\0';
      acStack_108[2] = '\0';
      acStack_108[3] = '\0';
      pcVar3 = (char *)(**(code **)(*param_1 + 0x10))(uVar4,0);
      FUN_0044a580(acStack_108,&DAT_009a4a18,&DAT_0099cf70);
      iVar1 = -(int)pcVar3;
      uVar2 = 0;
      do {
        if (*pcVar3 != pcVar3[(int)(acStack_108 + iVar1)]) {
          FUN_00475a90(uVar4,0);
          FUN_00475a90(uVar4,1);
          FUN_00475a90(uVar4,2);
          FUN_00475a90(uVar4,3);
          FUN_00475a90(uVar4,4);
          FUN_004774b0(uVar4,5);
          FUN_004774b0(uVar4,6);
          (**(code **)(*DAT_00b5ab48 + 4))(auStack_10a + -10);
          break;
        }
        if (*pcVar3 == '\0') break;
        uVar2 = uVar2 + 1;
        pcVar3 = pcVar3 + 1;
      } while (uVar2 < 0x100);
      uVar4 = uVar4 + 1;
      uVar2 = (**(code **)(*param_1 + 8))();
    } while (uVar4 < uVar2);
  }
  return;
}


// ==== FUN_0047a5d0 @ 0x0047a5d0 ====

void FUN_0047a5d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047a5e0 @ 0x0047a5e0 ====

void FUN_0047a5e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4a48;
  return;
}


// ==== FUN_0047a5f0 @ 0x0047a5f0 ====

void FUN_0047a5f0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  undefined1 auStack_216 [14];
  char local_208 [256];
  undefined4 local_108;
  char local_104 [4];
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4a40);
  uVar2 = 0;
  do {
    local_208[uVar2] = local_100[uVar2];
    if (local_100[uVar2] == '\0') goto LAB_0047a63e;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_208[0] = '\0';
LAB_0047a63e:
  local_108 = param_1;
  local_104[0] = '\n';
  local_104[1] = 0x2c;
  local_104[2] = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  iVar4 = (**(code **)(*piVar3 + 8))();
  iVar6 = 1;
  if (1 < iVar4) {
    do {
      FUN_0044a580(local_104,&DAT_009a4a40,s_GuildGuildObserver_009a4a2c + 0x13);
      pcVar5 = (char *)(**(code **)(*piVar3 + 0x10))(0,iVar6);
      uVar2 = 0;
      iVar1 = -(int)pcVar5;
      do {
        if (*pcVar5 != pcVar5[(int)(local_104 + iVar1)]) {
          FUN_00475a90(iVar6,0);
          FUN_00475a90(iVar6,1);
          FUN_00475a90(iVar6,2);
          FUN_004756e0(iVar6,3);
          FUN_00477510(iVar6,4);
          (**(code **)(*DAT_00b5ab4c + 4))(auStack_216 + -6);
          break;
        }
        if (*pcVar5 == '\0') break;
        uVar2 = uVar2 + 1;
        pcVar5 = pcVar5 + 1;
      } while (uVar2 < 0x100);
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar4);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar3);
  return;
}


// ==== FUN_0047a760 @ 0x0047a760 ====

void FUN_0047a760(byte param_1)

{
  void *in_ECX;
  
  FUN_0047a5d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047a780 @ 0x0047a780 ====

void FUN_0047a780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047a790 @ 0x0047a790 ====

void FUN_0047a790(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4ad0;
  return;
}


// ==== FUN_0047a7a0 @ 0x0047a7a0 ====

void FUN_0047a7a0(undefined4 param_1)

{
  undefined1 uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  char *pcVar12;
  undefined1 auStack_25c [2];
  char acStack_25a [2];
  undefined4 uStack_258;
  undefined2 uStack_254;
  undefined1 uStack_252;
  undefined2 uStack_240;
  undefined2 uStack_23e;
  char acStack_239 [37];
  char local_214 [256];
  undefined4 local_114;
  undefined1 local_110;
  undefined1 local_10f;
  undefined1 local_10e;
  char local_10c [248];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097dcde;
  pvStack_c = ExceptionList;
  local_214[0] = '\0';
  ExceptionList = &pvStack_c;
  FUN_0044a580(local_10c,&DAT_009a4ac4,s_Observer_009a4ab8);
  uVar2 = 0;
  do {
    local_214[uVar2] = local_10c[uVar2];
    if (local_10c[uVar2] == '\0') goto LAB_0047a7fe;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_214[0] = '\0';
LAB_0047a7fe:
  local_114 = param_1;
  pcVar12 = local_214;
  local_110 = 10;
  local_10f = 0x2c;
  local_10e = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(pcVar12);
  iVar4 = (**(code **)(*piVar3 + 8))();
  iVar10 = 1;
  if (1 < iVar4) {
    do {
      pvVar5 = operator_new(0x14);
      puStack_8 = (undefined1 *)0x0;
      if (pvVar5 == (void *)0x0) {
        piVar6 = (int *)0x0;
      }
      else {
        piVar6 = (int *)FUN_005dfe70();
      }
      puStack_8 = (undefined1 *)0xffffffff;
      uVar7 = FUN_00475a90(iVar10,0);
      uVar2 = FUN_00475a90(iVar10,1);
      uVar2 = (uVar2 & 0xffff) * 4;
      iVar11 = 2;
      uStack_252 = 0;
      if (2 < uVar2) {
        do {
          uStack_254 = FUN_00475a90(iVar10,iVar11);
          uVar8 = (**(code **)(*piVar3 + 0x10))(iVar10,iVar11 + 1);
          FUN_0047aa30(acStack_239,&DAT_009a4ac8,uVar8);
          uVar9 = 0;
          do {
            acStack_25a[uVar9] = acStack_239[uVar9];
            if (acStack_239[uVar9] == '\0') goto LAB_0047a909;
            uVar9 = uVar9 + 1;
          } while (uVar9 < 0x19);
          _auStack_25c = (uint3)(ushort)auStack_25c;
LAB_0047a909:
          uStack_240 = FUN_00475a90(iVar10,iVar11 + 2);
          uStack_23e = FUN_00475a90(iVar10,iVar11 + 3);
          (**(code **)(*piVar6 + 4))(auStack_25c);
          iVar11 = iVar11 + 4;
        } while (iVar11 < (int)uVar2);
      }
      uVar8 = FUN_004756e0(iVar10,iVar11);
      uStack_258 = FUN_004756e0(iVar10,iVar11 + 1);
      uVar1 = FUN_004753b0(iVar10,iVar11 + 2);
      _auStack_25c = CONCAT31(stack0xfffffda5,uVar1);
      (**(code **)(*piVar6 + 0x10))(uVar8);
      (**(code **)(*piVar6 + 0x18))(_auStack_25c);
      (**(code **)(*piVar6 + 0x20))(uVar7);
      (**(code **)(*DAT_00b5ab50 + 4))(pcVar12,piVar6);
      iVar10 = iVar10 + 1;
    } while (iVar10 < iVar4);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar3);
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_0047a9e0 @ 0x0047a9e0 ====

void FUN_0047a9e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0047a780();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047aa00 @ 0x0047aa00 ====

void FUN_0047aa00(int param_1)

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
  } while (uVar3 < 0x19);
  *in_ECX = '\0';
  return;
}


// ==== FUN_0047aa30 @ 0x0047aa30 ====

char * FUN_0047aa30(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x19,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x19)) {
    param_1[0x18] = '\0';
  }
  return param_1;
}


// ==== FUN_0047aa60 @ 0x0047aa60 ====

void FUN_0047aa60(void)

{
  FUN_0047aa30();
  return;
}


// ==== FUN_0047aa80 @ 0x0047aa80 ====

void FUN_0047aa80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047aa90 @ 0x0047aa90 ====

void FUN_0047aa90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4aec;
  return;
}


// ==== FUN_0047aaa0 @ 0x0047aaa0 ====

void FUN_0047aaa0(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_212 [10];
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4ae4);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0047aaee;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0047aaee:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  iVar3 = (**(code **)(*piVar2 + 8))();
  iVar4 = 1;
  if (1 < iVar3) {
    do {
      FUN_00475a90(iVar4,0);
      FUN_004756e0(iVar4,1);
      FUN_004756e0(iVar4,2);
      (**(code **)(*DAT_00b5ab54 + 4))(auStack_212 + -6);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar3);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar2);
  return;
}


// ==== FUN_0047aba0 @ 0x0047aba0 ====

void FUN_0047aba0(byte param_1)

{
  void *in_ECX;
  
  FUN_0047aa80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047abc0 @ 0x0047abc0 ====

void FUN_0047abc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047abd0 @ 0x0047abd0 ====

void FUN_0047abd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4b5c;
  return;
}


// ==== FUN_0047abe0 @ 0x0047abe0 ====

void FUN_0047abe0(short *param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_2 [2];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ab5c + 0xc))(1,0);
  (**(code **)(*piVar1 + 0x10))(param_1);
  iVar2 = 9;
  do {
    if (*param_1 != 0) {
      (**(code **)(*piVar1 + 0x14))(*param_1);
    }
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  (**(code **)(*DAT_00b5ab58 + 4))(auStack_2 + -0xe,piVar1);
  return;
}


// ==== FUN_0047ac60 @ 0x0047ac60 ====

void FUN_0047ac60(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 local_228 [5];
  char acStack_214 [12];
  char local_208 [256];
  char local_108 [256];
  undefined4 local_8;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  
  FUN_005fd550(0);
  FUN_0044a580(local_208,&DAT_009a4b54,s_DungeonText_009a4af8);
  uVar4 = 0;
  do {
    local_108[uVar4] = local_208[uVar4];
    if (local_208[uVar4] == '\0') goto LAB_0047acc1;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  local_108[0] = '\0';
LAB_0047acc1:
  local_8 = param_1;
  local_4 = 10;
  local_3 = 0x2c;
  local_2 = 1;
  piVar5 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_108);
  (**(code **)(*piVar5 + 0x10))(0,0);
  uVar6 = FUN_00475a90(0,1);
  uVar12 = uVar6;
  FUN_0044a580(acStack_214,&DAT_009a4b54,s_DungeonIndex_009a4b04);
  cVar2 = FUN_0047ae90(acStack_214);
  if ((cVar2 != '\0') || (15999 < (ushort)uVar6)) {
    FUN_0044a580(acStack_214,&DAT_009a4b54,s_<_In_Dungoen_Text_File_>_Dungeon_009a4b14);
    FUN_00797b80(acStack_214);
    return;
  }
  iVar9 = 3;
  iVar13 = 0xfd;
  do {
    pcVar7 = (char *)(**(code **)(*piVar5 + 0x10))(iVar9,0);
    FUN_0044a580(acStack_214,&DAT_009a4b54,&DAT_009a4b50);
    uVar4 = 0;
    iVar1 = -(int)pcVar7;
    while (*pcVar7 == pcVar7[(int)(acStack_214 + iVar1)]) {
      if (*pcVar7 == '\0') goto LAB_0047ae5a;
      uVar4 = uVar4 + 1;
      pcVar7 = pcVar7 + 1;
      if (0xff < uVar4) goto LAB_0047ae5a;
    }
    uVar6 = FUN_00475a90(iVar9,0);
    uVar8 = FUN_00475a90(iVar9,1);
    uVar10 = 2;
    uVar4 = (**(code **)(*piVar5 + 0xc))();
    if (uVar4 < 3) goto LAB_0047ae27;
    puVar11 = local_228;
    do {
      uVar3 = FUN_00475a90(iVar9,uVar10);
      *(undefined2 *)puVar11 = uVar3;
      uVar10 = uVar10 + 1;
      puVar11 = (undefined4 *)((int)puVar11 + 2);
      uVar4 = (**(code **)(*piVar5 + 0xc))();
    } while (uVar10 < uVar4);
    if (uVar10 < 9) {
LAB_0047ae27:
      puVar11 = (undefined4 *)((int)local_228 + (uVar10 - 2) * 2);
      for (uVar4 = 9 - uVar10 >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar11 = 0;
        puVar11 = puVar11 + 1;
      }
      for (uVar4 = (uint)((9 - uVar10 & 1) != 0); uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined2 *)puVar11 = 0;
        puVar11 = (undefined4 *)((int)puVar11 + 2);
      }
    }
    FUN_0047abe0(uVar12,uVar6,uVar8,local_228);
LAB_0047ae5a:
    iVar9 = iVar9 + 1;
    iVar13 = iVar13 + -1;
    if (iVar13 == 0) {
      (**(code **)(*DAT_00b5aa34 + 0xc))(piVar5);
      return;
    }
  } while( true );
}


// ==== FUN_0047ae90 @ 0x0047ae90 ====

undefined4 FUN_0047ae90(int param_1)

{
  char *in_ECX;
  uint uVar1;
  
  uVar1 = 0;
  param_1 = param_1 - (int)in_ECX;
  while( true ) {
    if (*in_ECX != in_ECX[param_1]) {
      return 1;
    }
    if (*in_ECX == '\0') break;
    uVar1 = uVar1 + 1;
    in_ECX = in_ECX + 1;
    if (0xff < uVar1) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0047aed0 @ 0x0047aed0 ====

void FUN_0047aed0(byte param_1)

{
  void *in_ECX;
  
  FUN_0047abc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047aef0 @ 0x0047aef0 ====

void FUN_0047aef0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047af00 @ 0x0047af00 ====

void FUN_0047af00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4b7c;
  return;
}


// ==== FUN_0047af10 @ 0x0047af10 ====

void FUN_0047af10(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  byte bVar7;
  uint uVar8;
  undefined4 uStack_238;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  uStack_238 = local_100;
  FUN_0044a580();
  uVar4 = 0;
  do {
    local_208[uVar4] = local_100[uVar4];
    if (local_100[uVar4] == '\0') goto LAB_0047af5e;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  local_208[0] = '\0';
LAB_0047af5e:
  local_108 = param_1;
  uStack_238 = local_208;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar5 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  uVar8 = 1;
  uVar4 = (**(code **)(*piVar5 + 0xc))();
  if (uVar4 < 2) {
LAB_0047b066:
    (**(code **)(*DAT_00b5aa34 + 0xc))(piVar5);
    return;
  }
  do {
    FUN_0044a580(&local_104,&DAT_009a4b74,s_Office_Set_009a4b68 + 0xb);
    pcVar6 = (char *)(**(code **)(*piVar5 + 0x10))(uVar8,0);
    uVar4 = 0;
    iVar1 = 0xfc - (int)pcVar6;
    while (*pcVar6 == pcVar6[(int)(local_208 + iVar1)]) {
      if (*pcVar6 == '\0') goto LAB_0047b052;
      uVar4 = uVar4 + 1;
      pcVar6 = pcVar6 + 1;
      if (0xff < uVar4) goto LAB_0047b052;
    }
    uVar3 = FUN_00475a90(0,uVar8);
    uStack_238 = (char *)CONCAT22(uStack_238._2_2_,uVar3);
    cVar2 = FUN_004753b0(1,uVar8);
    uVar4 = 0;
    uStack_238._0_3_ = CONCAT12(cVar2,(undefined2)uStack_238);
    if (cVar2 != '\0') {
      do {
        uVar3 = FUN_00475a90(uVar4 + 2,uVar8);
        bVar7 = (char)uVar4 + 1;
        *(undefined2 *)(local_208 + uVar4 * 2 + -0x2c) = uVar3;
        uVar4 = (uint)bVar7;
      } while (bVar7 < uStack_238._2_1_);
    }
    (**(code **)(*DAT_00b5ab60 + 4))(uStack_238,&uStack_238);
LAB_0047b052:
    uVar8 = uVar8 + 1;
    uVar4 = (**(code **)(*piVar5 + 0xc))();
    if (uVar4 <= uVar8) goto LAB_0047b066;
  } while( true );
}


// ==== FUN_0047b080 @ 0x0047b080 ====

void FUN_0047b080(byte param_1)

{
  void *in_ECX;
  
  FUN_0047aef0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047b0a0 @ 0x0047b0a0 ====

void FUN_0047b0a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047b0b0 @ 0x0047b0b0 ====

void FUN_0047b0b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4ba8;
  return;
}


// ==== FUN_0047b0c0 @ 0x0047b0c0 ====

void FUN_0047b0c0(undefined4 param_1)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined *puVar8;
  bool bVar9;
  undefined *puStack_3f0;
  char *pcStack_3ec;
  undefined4 uStack_3e0;
  char acStack_3c4 [4];
  undefined4 uStack_3c0;
  char acStack_33c [52];
  char local_308 [256];
  undefined4 local_208;
  undefined1 local_204;
  undefined1 local_203;
  undefined1 local_202;
  char local_200 [512];
  
  uStack_3e0 = (char *)0x47b0d4;
  FUN_005fd550();
  uStack_3e0 = s_RequestQuest_009a4b88;
  pcStack_3ec = (char *)0x47b0eb;
  FUN_0044a580();
  uVar3 = 0;
  do {
    local_308[uVar3] = local_200[uVar3];
    if (local_200[uVar3] == '\0') goto LAB_0047b123;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  local_308[0] = '\0';
LAB_0047b123:
  local_208 = param_1;
  uStack_3e0 = local_308;
  local_204 = 10;
  local_203 = 0x2c;
  local_202 = 1;
  piVar4 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  FUN_0047b310();
  iVar5 = (**(code **)(*piVar4 + 8))();
  if (iVar5 == 1) {
LAB_0047b2cc:
    (**(code **)(*DAT_00b5aa34 + 0xc))();
    return;
  }
  puVar8 = (undefined *)0x1;
LAB_0047b180:
  pcStack_3ec = s_RequestQuest_009a4b88 + 0xd;
  puStack_3f0 = &DAT_009a4b98;
  FUN_0044a580(local_200 + 0xfc);
  pcStack_3ec = (char *)0x0;
  puStack_3f0 = puVar8;
  pcVar6 = (char *)(**(code **)(*piVar4 + 0x10))();
  uVar3 = 0;
  iVar5 = 0xf4 - (int)pcVar6;
  do {
    if (*pcVar6 != pcVar6[(int)(local_200 + iVar5)]) {
      uVar2 = FUN_00475a90(puVar8,0);
      uStack_3e0 = (char *)CONCAT22(uStack_3e0._2_2_,uVar2);
      uVar2 = FUN_00475a90(puVar8,1);
      uStack_3e0 = (char *)CONCAT22(uVar2,(undefined2)uStack_3e0);
      FUN_00475a90(puVar8,2);
      uVar7 = (**(code **)(*piVar4 + 0x10))(puVar8,3);
      FUN_0047b320(acStack_33c,&DAT_009a4b9c,uVar7);
      uVar3 = 0;
      goto LAB_0047b220;
    }
    if (*pcVar6 == '\0') break;
    uVar3 = uVar3 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar3 < 0x100);
  goto LAB_0047b2b2;
  while (uVar3 = uVar3 + 1, uVar3 < 0x20) {
LAB_0047b220:
    cVar1 = acStack_33c[uVar3];
    acStack_3c4[uVar3 - 0x1c] = cVar1;
    if (cVar1 == '\0') goto LAB_0047b23b;
  }
  uStack_3e0 = (char *)((uint)uStack_3e0 & 0xffffff00);
LAB_0047b23b:
  FUN_00475a90(puVar8,4);
  uStack_3c0 = FUN_004756e0(puVar8,5);
  uVar7 = (**(code **)(*piVar4 + 0x10))(puVar8,6);
  FUN_0047b350(local_308 + 0xec,&DAT_009a4ba0,uVar7);
  uVar3 = 0;
  do {
    cVar1 = local_308[uVar3 + 0xec];
    acStack_3c4[uVar3] = cVar1;
    if (cVar1 == '\0') goto LAB_0047b29d;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x80);
  acStack_3c4[0] = '\0';
LAB_0047b29d:
  (**(code **)(*DAT_00b5ab64 + 4))(puStack_3f0,&puStack_3f0);
LAB_0047b2b2:
  iVar5 = (**(code **)(*piVar4 + 8))();
  bVar9 = (undefined *)(iVar5 - 1U) <= puVar8;
  puVar8 = puVar8 + 1;
  if (bVar9) goto LAB_0047b2cc;
  goto LAB_0047b180;
}


// ==== FUN_0047b2f0 @ 0x0047b2f0 ====

void FUN_0047b2f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0047b0a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047b310 @ 0x0047b310 ====

void FUN_0047b310(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  return;
}


// ==== FUN_0047b320 @ 0x0047b320 ====

char * FUN_0047b320(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x20,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x20)) {
    param_1[0x1f] = '\0';
  }
  return param_1;
}


// ==== FUN_0047b350 @ 0x0047b350 ====

char * FUN_0047b350(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x80,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x80)) {
    param_1[0x7f] = '\0';
  }
  return param_1;
}


// ==== FUN_0047b380 @ 0x0047b380 ====

void FUN_0047b380(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047b390 @ 0x0047b390 ====

void FUN_0047b390(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4bc8;
  return;
}


// ==== FUN_0047b3a0 @ 0x0047b3a0 ====

void FUN_0047b3a0(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  bool bVar9;
  undefined1 auStack_212 [2];
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580();
  uVar4 = 0;
  do {
    local_208[uVar4] = local_100[uVar4];
    if (local_100[uVar4] == '\0') goto LAB_0047b3ee;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  local_208[0] = '\0';
LAB_0047b3ee:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar5 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  iVar6 = (**(code **)(*piVar5 + 8))();
  if (iVar6 != 1) {
    uVar4 = 1;
    do {
      FUN_0044a580(&local_104,&DAT_009a4bc0,s_SlotItem_009a4bb4 + 9);
      pcVar7 = (char *)(**(code **)(*piVar5 + 0x10))(uVar4,0);
      uVar8 = 0;
      iVar6 = 0xfc - (int)pcVar7;
      do {
        if (*pcVar7 != pcVar7[(int)(local_208 + iVar6)]) {
          uVar3 = FUN_00475a90(uVar4,0);
          uVar1 = FUN_004753b0(uVar4,1);
          uVar2 = FUN_004753b0(uVar4,2);
          (**(code **)(*DAT_00b5ab68 + 4))(CONCAT13(uVar2,CONCAT12(uVar1,uVar3)),auStack_212 + -6);
          break;
        }
        if (*pcVar7 == '\0') break;
        uVar8 = uVar8 + 1;
        pcVar7 = pcVar7 + 1;
      } while (uVar8 < 0x100);
      iVar6 = (**(code **)(*piVar5 + 8))();
      bVar9 = uVar4 < iVar6 - 1U;
      uVar4 = uVar4 + 1;
    } while (bVar9);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))();
  return;
}


// ==== FUN_0047b500 @ 0x0047b500 ====

void FUN_0047b500(byte param_1)

{
  void *in_ECX;
  
  FUN_0047b380();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047b520 @ 0x0047b520 ====

void FUN_0047b520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047b530 @ 0x0047b530 ====

void FUN_0047b530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4bec;
  return;
}


// ==== FUN_0047b540 @ 0x0047b540 ====

void FUN_0047b540(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  float10 fVar8;
  char *pcStack_54c;
  undefined1 *puStack_548;
  char *pcStack_544;
  undefined4 uStack_540;
  float fStack_42c;
  float fStack_428;
  char local_308 [256];
  undefined4 local_208;
  undefined1 local_204;
  undefined1 local_203;
  undefined1 local_202;
  char local_200 [512];
  
  FUN_005fd550();
  uStack_540 = (char *)0x47b56b;
  FUN_0044a580();
  uVar2 = 0;
  do {
    local_308[uVar2] = local_200[uVar2];
    if (local_200[uVar2] == '\0') goto LAB_0047b5a3;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_308[0] = '\0';
LAB_0047b5a3:
  local_208 = param_1;
  local_204 = 10;
  local_203 = 0x2c;
  local_202 = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  FUN_0047b820();
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (iVar4 == 1) {
LAB_0047b7e2:
    (**(code **)(*DAT_00b5aa34 + 0xc))();
    return;
  }
  pcVar6 = (char *)0x1;
LAB_0047b600:
  uStack_540 = s_ItemStatus_009a4bd4 + 0xb;
  puStack_548 = &local_204;
  pcStack_544 = &DAT_009a4be4;
  pcStack_54c = (char *)0x47b617;
  FUN_0044a580();
  uStack_540 = (char *)0x0;
  puStack_548 = (undefined1 *)0x47b623;
  pcStack_544 = pcVar6;
  pcVar5 = (char *)(**(code **)(*piVar3 + 0x10))();
  uVar2 = 0;
  iVar4 = 0xfc - (int)pcVar5;
  do {
    if (*pcVar5 != pcVar5[(int)(local_308 + iVar4)]) {
      puStack_548 = (undefined1 *)0x0;
      pcStack_54c = pcVar6;
      FUN_00475a90();
      puStack_548 = (undefined1 *)0x1;
      pcStack_54c = pcVar6;
      FUN_00475a90();
      puStack_548 = &DAT_009a4be0;
      pcStack_54c = &DAT_009a4be4;
      FUN_0044a580(local_200 + 0xf4);
      puStack_548 = (undefined1 *)0x2;
      pcStack_54c = pcVar6;
      pcVar5 = (char *)(**(code **)(*piVar3 + 0x10))();
      uVar2 = 0;
      iVar4 = 0xec - (int)pcVar5;
      goto LAB_0047b6a0;
    }
    if (*pcVar5 == '\0') break;
    uVar2 = uVar2 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar2 < 0x100);
  goto LAB_0047b7c8;
  while( true ) {
    uVar2 = uVar2 + 1;
    pcVar5 = pcVar5 + 1;
    if (0xff < uVar2) break;
LAB_0047b6a0:
    if ((*pcVar5 != pcVar5[(int)(local_200 + iVar4)]) || (*pcVar5 == '\0')) break;
  }
  FUN_00475a90(pcVar6,3);
  FUN_00475a90(pcVar6,4);
  iVar4 = (**(code **)(*piVar3 + 0x10))(pcVar6,5);
  uVar2 = 0;
  do {
    cVar1 = ((char *)((int)register0x00000010 + (uVar2 - 0x53a)))
            [iVar4 - ((int)register0x00000010 + -0x53a)];
    *(char *)((int)register0x00000010 + (uVar2 - 0x53a)) = cVar1;
    if (cVar1 == '\0') break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  FUN_004756e0(pcVar6,6);
  FUN_00477510(pcVar6,7);
  FUN_00477510(pcVar6,8);
  fVar8 = (float10)FUN_00477510(pcVar6,9);
  fStack_42c = (float)fVar8;
  fVar8 = (float10)FUN_00477510(pcVar6,10);
  fStack_428 = (float)fVar8;
  iVar4 = (**(code **)(*piVar3 + 0x10))(pcVar6,0xb);
  uVar2 = 0;
  do {
    cVar1 = ((char *)((int)&fStack_42c + uVar2))[iVar4 - (int)&fStack_42c];
    *(char *)((int)&fStack_42c + uVar2) = cVar1;
    if (cVar1 == '\0') goto LAB_0047b7b3;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  fStack_42c = (float)((uint)fStack_42c & 0xffffff00);
LAB_0047b7b3:
  (**(code **)(*DAT_00b5ab6c + 4))(pcStack_54c,&pcStack_54c);
LAB_0047b7c8:
  puStack_548 = (undefined1 *)0x47b7d2;
  iVar4 = (**(code **)(*piVar3 + 8))();
  bVar7 = (char *)(iVar4 - 1U) <= pcVar6;
  pcVar6 = pcVar6 + 1;
  if (bVar7) goto LAB_0047b7e2;
  goto LAB_0047b600;
}


// ==== FUN_0047b800 @ 0x0047b800 ====

void FUN_0047b800(byte param_1)

{
  void *in_ECX;
  
  FUN_0047b520();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047b820 @ 0x0047b820 ====

void FUN_0047b820(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 10) = 0;
  *(undefined1 *)(in_ECX + 0x120) = 0;
  return;
}


// ==== FUN_0047b830 @ 0x0047b830 ====

void FUN_0047b830(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047b840 @ 0x0047b840 ====

void FUN_0047b840(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4ca8;
  return;
}


// ==== FUN_0047b850 @ 0x0047b850 ====

undefined4 FUN_0047b850(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_100 [256];
  
  FUN_0044a580(local_100,&DAT_009a4ca0,s_KNIGHT_009a4c08);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 == '\0') {
    FUN_0044a580(local_100,&DAT_009a4ca0,s_HUNTER_009a4c10);
    cVar1 = FUN_0044a440(local_100);
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_0044a580(local_100,&DAT_009a4ca0,s_MAGICIAN_009a4c18);
    cVar1 = FUN_0044a440(local_100);
    if (cVar1 != '\0') {
      return 2;
    }
    FUN_0044a580(local_100,&DAT_009a4ca0,s_SUMMONER_009a4c24);
    cVar1 = FUN_0044a440(local_100);
    if (cVar1 != '\0') {
      return 3;
    }
    FUN_0044a580(local_100,&DAT_009a4ca0,s_SEGNALLE_009a4c30);
    cVar1 = FUN_0044a440(local_100);
    if (cVar1 != '\0') {
      return 4;
    }
    uVar2 = FUN_0044a670(s_WARRIOR_009a4c3c);
    cVar1 = FUN_0044a440(uVar2);
    if (cVar1 != '\0') {
      return 5;
    }
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_CANNOT_Parse_Class_String______s_009a4c44,param_1);
    FUN_00797b80(uVar2);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009a4c8c,
                         s___Loader_Article_FishingSkill_cp_009a4c68,0x58);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  return 0;
}


// ==== FUN_0047b9d0 @ 0x0047b9d0 ====

void FUN_0047b9d0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 auStack_20e [6];
  char local_208 [256];
  undefined4 local_108;
  char local_104 [4];
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580();
  uVar2 = 0;
  do {
    local_208[uVar2] = local_100[uVar2];
    if (local_100[uVar2] == '\0') goto LAB_0047ba1e;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_208[0] = '\0';
LAB_0047ba1e:
  local_108 = param_1;
  local_104[0] = '\n';
  local_104[1] = 0x2c;
  local_104[2] = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  iVar4 = (**(code **)(*piVar3 + 8))();
  iVar7 = 1;
  if (1 < iVar4) {
    do {
      FUN_0044a580(local_104,&DAT_009a4ca0,s_FishingSkill_009a4bf8 + 0xd);
      pcVar5 = (char *)(**(code **)(*piVar3 + 0x10))(iVar7,0);
      uVar2 = 0;
      iVar1 = -(int)pcVar5;
      do {
        if (*pcVar5 != pcVar5[(int)(local_104 + iVar1)]) {
          uVar6 = (**(code **)(*piVar3 + 0x10))(iVar7,0);
          FUN_0047b850(uVar6);
          FUN_00475a90(iVar7,1);
          (**(code **)(*DAT_00b5ab70 + 4))(auStack_20e + -0xe);
          break;
        }
        if (*pcVar5 == '\0') break;
        uVar2 = uVar2 + 1;
        pcVar5 = pcVar5 + 1;
      } while (uVar2 < 0x100);
      iVar7 = iVar7 + 1;
    } while (iVar7 < iVar4);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar3);
  return;
}


// ==== FUN_0047bb20 @ 0x0047bb20 ====

void FUN_0047bb20(byte param_1)

{
  void *in_ECX;
  
  FUN_0047b830();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047bb40 @ 0x0047bb40 ====

void FUN_0047bb40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047bb50 @ 0x0047bb50 ====

void FUN_0047bb50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4cc8;
  return;
}


// ==== FUN_0047bb60 @ 0x0047bb60 ====

void FUN_0047bb60(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  char acStack_31e [278];
  char local_208 [256];
  undefined4 local_108;
  char local_104 [4];
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100);
  uVar2 = 0;
  do {
    local_208[uVar2] = local_100[uVar2];
    if (local_100[uVar2] == '\0') goto LAB_0047bbb4;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_208[0] = '\0';
LAB_0047bbb4:
  local_108 = param_1;
  local_104[0] = '\n';
  local_104[1] = 0x2c;
  local_104[2] = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00479840();
  iVar4 = (**(code **)(*piVar3 + 8))();
  iVar7 = 1;
  if (iVar4 < 2) {
LAB_0047bd18:
    (**(code **)(*DAT_00b5aa34 + 0xc))(piVar3);
    return;
  }
LAB_0047bc13:
  FUN_0044a580(local_104,&DAT_009a4cc0,s_FishingRod_009a4cb4 + 0xb);
  pcVar5 = (char *)(**(code **)(*piVar3 + 0x10))(iVar7,0);
  uVar2 = 0;
  iVar6 = -(int)pcVar5;
  do {
    if (*pcVar5 != pcVar5[(int)(local_104 + iVar6)]) {
      FUN_00475a90(iVar7,0);
      iVar6 = (**(code **)(*piVar3 + 0x10))(iVar7,1);
      uVar2 = 0;
      goto LAB_0047bc87;
    }
    if (*pcVar5 == '\0') break;
    uVar2 = uVar2 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar2 < 0x100);
  goto LAB_0047bd0a;
  while (uVar2 = uVar2 + 1, uVar2 < 0x100) {
LAB_0047bc87:
    cVar1 = (acStack_31e + (uVar2 - 8))[iVar6 - (int)(acStack_31e + -8)];
    acStack_31e[uVar2 - 8] = cVar1;
    if (cVar1 == '\0') break;
  }
  FUN_00477a70(iVar7,2);
  FUN_00477a70(iVar7,3);
  FUN_00477a70(iVar7,4);
  FUN_00475a90(iVar7,5);
  FUN_004753b0(iVar7,6);
  (**(code **)(*DAT_00b5ab74 + 4))(acStack_31e + -10);
LAB_0047bd0a:
  iVar7 = iVar7 + 1;
  if (iVar4 <= iVar7) goto LAB_0047bd18;
  goto LAB_0047bc13;
}


// ==== FUN_0047bd30 @ 0x0047bd30 ====

void FUN_0047bd30(byte param_1)

{
  void *in_ECX;
  
  FUN_0047bb40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047bd50 @ 0x0047bd50 ====

void FUN_0047bd50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047bd60 @ 0x0047bd60 ====

void FUN_0047bd60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4ce4;
  return;
}


// ==== FUN_0047bd70 @ 0x0047bd70 ====

void FUN_0047bd70(undefined4 param_1)

{
  int iVar1;
  undefined2 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  undefined4 uVar7;
  ushort uVar8;
  int iVar9;
  int iVar10;
  undefined2 auStack_2b8 [2];
  undefined4 uStack_2b4;
  undefined4 uStack_2b0;
  undefined4 uStack_2ac;
  undefined4 uStack_2a8;
  undefined4 uStack_2a4;
  undefined4 uStack_2a0;
  undefined4 uStack_29c;
  undefined4 uStack_298;
  undefined4 uStack_294;
  undefined4 uStack_290;
  undefined4 uStack_28c;
  ushort uStack_288;
  undefined2 auStack_284 [2];
  undefined4 auStack_280 [30];
  char local_208 [256];
  undefined4 local_108;
  char local_104 [4];
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4cdc,&DAT_009a4cd4);
  uVar3 = 0;
  do {
    local_208[uVar3] = local_100[uVar3];
    if (local_100[uVar3] == '\0') goto LAB_0047bdc4;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  local_208[0] = '\0';
LAB_0047bdc4:
  local_108 = param_1;
  local_104[0] = '\n';
  local_104[1] = 0x2c;
  local_104[2] = 1;
  piVar4 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  iVar5 = (**(code **)(*piVar4 + 0xc))();
  iVar9 = 1;
  iVar10 = iVar5;
  if (iVar5 < 2) {
LAB_0047bf81:
    (**(code **)(*DAT_00b5aa34 + 0xc))(piVar4);
    return;
  }
  do {
    FUN_0044a580(local_104,&DAT_009a4cdc,&DAT_009a4cd9);
    pcVar6 = (char *)(**(code **)(*piVar4 + 0x10))(0,iVar9);
    uVar3 = 0;
    iVar1 = -(int)pcVar6;
    while (*pcVar6 == pcVar6[(int)(local_104 + iVar1)]) {
      if (*pcVar6 == '\0') goto LAB_0047bf75;
      uVar3 = uVar3 + 1;
      pcVar6 = pcVar6 + 1;
      if (0xff < uVar3) goto LAB_0047bf75;
    }
    auStack_2b8[0] = FUN_00475a90(0,iVar9);
    uStack_2b4 = FUN_004756e0(4,iVar9);
    uStack_2b0 = FUN_00477a70(5,iVar9);
    uStack_2ac = FUN_00477a70(6,iVar9);
    uStack_2a8 = FUN_00477a70(7,iVar9);
    uStack_2a4 = FUN_00477a70(8,iVar9);
    uStack_2a0 = FUN_00477a70(9,iVar9);
    uStack_29c = FUN_004756e0(0xb,iVar9);
    uStack_298 = FUN_004756e0(0xc,iVar9);
    uStack_294 = FUN_004756e0(0xd,iVar9);
    uStack_290 = FUN_004756e0(0xf,iVar9);
    uStack_28c = FUN_004756e0(0x10,iVar9);
    uStack_288 = FUN_00475a90(0x12,iVar9);
    uVar8 = 0;
    iVar5 = iVar10;
    if (uStack_288 != 0) {
      do {
        uVar3 = (uint)uVar8;
        uVar2 = FUN_00475a90(uVar3 * 2 + 0x14,iVar9);
        auStack_284[uVar3 * 4] = uVar2;
        uVar7 = FUN_004756e0(uVar3 * 2 + 0x15,iVar9);
        uVar8 = uVar8 + 1;
        auStack_280[uVar3 * 2] = uVar7;
        iVar5 = iVar10;
      } while (uVar8 < uStack_288);
    }
    (**(code **)(*DAT_00b5ab78 + 4))(auStack_2b8);
    iVar10 = iVar5;
LAB_0047bf75:
    iVar9 = iVar9 + 1;
    if (iVar5 <= iVar9) goto LAB_0047bf81;
  } while( true );
}


// ==== FUN_0047bfa0 @ 0x0047bfa0 ====

void FUN_0047bfa0(byte param_1)

{
  void *in_ECX;
  
  FUN_0047bd50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047bfc0 @ 0x0047bfc0 ====

void FUN_0047bfc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047bfd0 @ 0x0047bfd0 ====

void FUN_0047bfd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4d04;
  return;
}


// ==== FUN_0047bfe0 @ 0x0047bfe0 ====

void FUN_0047bfe0(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 uStack_22c;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580();
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0047c02e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0047c02e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  uVar4 = 1;
  uVar1 = (**(code **)(*piVar2 + 8))();
  if (1 < uVar1) {
    do {
      uStack_22c = 0;
      FUN_00475a90(uVar4);
      uStack_22c = 1;
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))(uVar4);
      FUN_00475260(pcVar3,uVar4,1);
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atol(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))(uVar4,2);
      FUN_00475260(pcVar3,uVar4,2);
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atol(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      FUN_00475a90(uVar4,3);
      (**(code **)(*DAT_00b5ab7c + 4))(&uStack_22c);
      uVar4 = uVar4 + 1;
      uVar1 = (**(code **)(*piVar2 + 8))();
    } while (uVar4 < uVar1);
  }
  uStack_22c = 0x47c149;
  (**(code **)(*DAT_00b5aa34 + 0xc))();
  return;
}


// ==== FUN_0047c160 @ 0x0047c160 ====

void FUN_0047c160(byte param_1)

{
  void *in_ECX;
  
  FUN_0047bfc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047c180 @ 0x0047c180 ====

void FUN_0047c180(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047c190 @ 0x0047c190 ====

void FUN_0047c190(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4d20;
  return;
}


// ==== FUN_0047c1a0 @ 0x0047c1a0 ====

void FUN_0047c1a0(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 uStack_22c;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580();
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0047c1ee;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0047c1ee:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  uVar4 = 1;
  uVar1 = (**(code **)(*piVar2 + 8))();
  if (1 < uVar1) {
    do {
      uStack_22c = 0;
      FUN_00475a90(uVar4);
      uStack_22c = 1;
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))(uVar4);
      FUN_00475260(pcVar3,uVar4,1);
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atol(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))(uVar4,2);
      FUN_00475260(pcVar3,uVar4,2);
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atol(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      FUN_00475a90(uVar4,3);
      FUN_00475a90(uVar4,4);
      (**(code **)(*DAT_00b5ab80 + 4))(&uStack_22c);
      uVar4 = uVar4 + 1;
      uVar1 = (**(code **)(*piVar2 + 8))();
    } while (uVar4 < uVar1);
  }
  uStack_22c = 0x47c318;
  (**(code **)(*DAT_00b5aa34 + 0xc))();
  return;
}


// ==== FUN_0047c330 @ 0x0047c330 ====

void FUN_0047c330(byte param_1)

{
  void *in_ECX;
  
  FUN_0047c180();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047c350 @ 0x0047c350 ====

void FUN_0047c350(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047c360 @ 0x0047c360 ====

void FUN_0047c360(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4d3c;
  return;
}


// ==== FUN_0047c370 @ 0x0047c370 ====

void FUN_0047c370(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  char *pcVar3;
  uint uVar4;
  undefined4 uStack_22c;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580();
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0047c3be;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0047c3be:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  uVar4 = 1;
  uVar1 = (**(code **)(*piVar2 + 8))();
  if (1 < uVar1) {
    do {
      uStack_22c = 0;
      FUN_00475a90(uVar4);
      uStack_22c = 1;
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))(uVar4);
      FUN_00475260(pcVar3,uVar4,1);
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atol(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      pcVar3 = (char *)(**(code **)(*piVar2 + 0x10))(uVar4,2);
      FUN_00475260(pcVar3,uVar4,2);
      uVar1 = 0;
      do {
        if (pcVar3[uVar1] == '\0') {
          if (uVar1 != 0) {
            _atol(pcVar3);
          }
          break;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x100);
      FUN_004753b0(uVar4,3);
      FUN_00475a90(uVar4,4);
      (**(code **)(*DAT_00b5ab84 + 4))(&uStack_22c);
      uVar4 = uVar4 + 1;
      uVar1 = (**(code **)(*piVar2 + 8))();
    } while (uVar4 < uVar1);
  }
  uStack_22c = 0x47c4e7;
  (**(code **)(*DAT_00b5aa34 + 0xc))();
  return;
}


// ==== FUN_0047c500 @ 0x0047c500 ====

void FUN_0047c500(byte param_1)

{
  void *in_ECX;
  
  FUN_0047c350();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047c520 @ 0x0047c520 ====

void FUN_0047c520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047c530 @ 0x0047c530 ====

void FUN_0047c530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4d58;
  return;
}


// ==== FUN_0047c540 @ 0x0047c540 ====

void FUN_0047c540(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a4d50,s_ShopSet_009a4d48);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0047c58e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0047c58e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_0047c6c0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_0047c5f0 @ 0x0047c5f0 ====

void FUN_0047c5f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0047c520();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047c610 @ 0x0047c610 ====

void FUN_0047c610(char *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  char *pcVar4;
  uint uVar5;
  undefined1 auStack_1fe [246];
  undefined1 auStack_108 [264];
  
  iVar2 = (**(code **)(*in_ECX + 0x10))(param_1,param_2);
  uVar5 = 0;
  pcVar4 = param_1;
  do {
    cVar1 = pcVar4[iVar2 - (int)param_1];
    *pcVar4 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar5 = uVar5 + 1;
    pcVar4 = pcVar4 + 1;
  } while (uVar5 < 0x19);
  uVar3 = (**(code **)(*in_ECX + 0x14))(param_1,param_2);
  FUN_0044a580(auStack_1fe + -10,s_GetString_Error____s___Cell__d____009a4dcc,uVar3);
  FUN_00797b80(auStack_1fe + -10);
  auStack_108[0] = 0;
  uVar3 = FUN_0044a580(auStack_108,s_File___s__Line___d_0099f0a0,
                       s_d__usa_24_0_1_2__develop_share_l_009a4d60,0x6a);
  FUN_00797b80(uVar3);
  FUN_00797a40();
  return;
}


// ==== FUN_0047c6c0 @ 0x0047c6c0 ====

void FUN_0047c6c0(int *param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint uVar3;
  char *pcVar4;
  undefined2 *puVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_34e [18];
  undefined2 auStack_33c [2];
  undefined2 uStack_338;
  char acStack_208 [8];
  undefined1 auStack_200 [240];
  char acStack_110 [8];
  undefined1 auStack_108 [264];
  
  FUN_00479840();
  uVar6 = 1;
  uVar3 = (**(code **)(*param_1 + 0xc))();
  if (uVar3 < 2) {
    return;
  }
LAB_0047c6f0:
  FUN_0044a580(auStack_200,&DAT_009a4d50,&DAT_0099cf70);
  pcVar4 = (char *)(**(code **)(*param_1 + 0x10))(0,uVar6);
  uVar3 = 0;
  iVar8 = -(int)pcVar4;
  do {
    if (*pcVar4 != pcVar4[(int)(acStack_208 + iVar8)]) {
      FUN_00475a90(0,uVar6);
      FUN_0047c610(1,uVar6,auStack_34e + -4);
      uStack_338 = FUN_00475a90(2,uVar6);
      iVar7 = 3;
      FUN_0044a580(auStack_108,&DAT_009a4d50,s_ItemIndex_009a4df4);
      pcVar4 = (char *)(**(code **)(*param_1 + 0x10))(5,0);
      uVar3 = 0;
      iVar8 = -(int)pcVar4;
      goto LAB_0047c7a4;
    }
    if (*pcVar4 == '\0') break;
    uVar3 = uVar3 + 1;
    pcVar4 = pcVar4 + 1;
  } while (uVar3 < 0x100);
  goto LAB_0047c86b;
LAB_0047c7a4:
  if (*pcVar4 != pcVar4[(int)(acStack_110 + iVar8)]) {
    puVar5 = auStack_33c;
    iVar8 = 0x32;
    do {
      uVar2 = FUN_00475a90(iVar7,uVar6);
      puVar5[-1] = uVar2;
      uVar2 = FUN_00475a90(iVar7 + 1,uVar6);
      *puVar5 = uVar2;
      uVar1 = FUN_004753b0(iVar7 + 2,uVar6);
      *(undefined1 *)(puVar5 + 1) = uVar1;
      uVar1 = FUN_004753b0(iVar7 + 3,uVar6);
      *(undefined1 *)((int)puVar5 + 3) = uVar1;
      iVar7 = iVar7 + 4;
      puVar5 = puVar5 + 3;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
    goto LAB_0047c85b;
  }
  if (*pcVar4 != '\0') goto code_r0x0047c7af;
  goto LAB_0047c7bd;
code_r0x0047c7af:
  uVar3 = uVar3 + 1;
  pcVar4 = pcVar4 + 1;
  if (0xff < uVar3) goto LAB_0047c7bd;
  goto LAB_0047c7a4;
LAB_0047c7bd:
  puVar5 = auStack_33c;
  iVar8 = 0x32;
  do {
    uVar2 = FUN_00475a90(iVar7,uVar6);
    puVar5[-1] = uVar2;
    uVar2 = FUN_00475a90(iVar7 + 1,uVar6);
    *puVar5 = uVar2;
    *(undefined1 *)(puVar5 + 1) = 0;
    *(undefined1 *)((int)puVar5 + 3) = 0;
    iVar7 = iVar7 + 2;
    puVar5 = puVar5 + 3;
    iVar8 = iVar8 + -1;
  } while (iVar8 != 0);
LAB_0047c85b:
  (**(code **)(*DAT_00b5ab88 + 4))(auStack_34e + -0xe);
LAB_0047c86b:
  uVar6 = uVar6 + 1;
  uVar3 = (**(code **)(*param_1 + 0xc))();
  if (uVar3 <= uVar6) {
    return;
  }
  goto LAB_0047c6f0;
}


// ==== FUN_0047c890 @ 0x0047c890 ====

void FUN_0047c890(int param_1,undefined2 *param_2)

{
  char cVar1;
  char *in_ECX;
  char *pcVar2;
  uint uVar3;
  
  uVar3 = 0;
  *in_ECX = '\0';
  pcVar2 = in_ECX;
  do {
    cVar1 = pcVar2[param_1 - (int)in_ECX];
    *pcVar2 = cVar1;
    if (cVar1 == '\0') goto LAB_0047c8bb;
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0x100);
  *in_ECX = '\0';
LAB_0047c8bb:
  *(undefined2 *)(in_ECX + 0x100) = *param_2;
  return;
}


// ==== FUN_0047c8d0 @ 0x0047c8d0 ====

void FUN_0047c8d0(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  void *pvVar7;
  uint uVar8;
  char *pcVar9;
  uint in_ECX;
  undefined1 unaff_BL;
  int iVar10;
  uint uVar11;
  double dVar12;
  uint uStack_d64;
  uint uStack_d60;
  uint uStack_d58;
  uint uStack_d54;
  uint local_d50;
  undefined4 uStack_c74;
  undefined4 uStack_c70;
  float fStack_c6c;
  float fStack_c68;
  undefined4 uStack_c64;
  float fStack_c60;
  char acStack_c1e [8];
  undefined1 auStack_c16 [240];
  char acStack_b26 [266];
  undefined1 auStack_a1c [8];
  uint uStack_a14;
  undefined2 uStack_a10;
  undefined1 uStack_a0c;
  undefined1 auStack_914 [176];
  undefined1 auStack_864 [80];
  char acStack_814 [256];
  char acStack_714 [184];
  char acStack_65c [8];
  undefined1 auStack_654 [312];
  undefined1 auStack_51c [8];
  char acStack_514 [248];
  char acStack_41c [8];
  undefined1 auStack_414 [248];
  char acStack_31c [8];
  undefined1 auStack_314 [176];
  char acStack_264 [8];
  undefined1 auStack_25c [328];
  undefined1 auStack_114 [264];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097dcfe;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_d50 = in_ECX;
  uVar4 = (**(code **)(*param_1 + 8))();
  if (uVar4 < 4) {
    FUN_0044a580(auStack_c16,&DAT_009a5068,s_Invalid_Action_Table_009a4fac);
    FUN_00797b80(auStack_c16);
  }
  else {
    uVar5 = (**(code **)(*param_1 + 0x10))(0,1);
    FUN_00483b60(uVar5);
    piVar6 = (int *)(**(code **)(*(int *)(in_ECX + 4) + 0x30))(acStack_b26 + 8);
    if (piVar6 == (int *)0x0) {
      FUN_0044a580(auStack_c16,&DAT_009a5068,s_Action_Table_Error___Unknown_CRE_009a4fc4);
      FUN_00797b80(auStack_c16);
      auStack_c16[0] = 0;
      uVar5 = FUN_0044a580(auStack_c16,s__>_Row__u_Col__u_009a4ff8,0,1);
      FUN_00797b80(uVar5);
    }
    else {
      uStack_a10 = 0;
      uStack_a0c = 0;
      uStack_a14 = (uint)*(ushort *)(*piVar6 + 0x100);
      uStack_a10 = FUN_00475a90(1,1);
      uVar5 = (**(code **)(*param_1 + 0x10))(2,1);
      FUN_0044cff0(uVar5);
      uStack_d64 = uStack_d64 & 0xffffff00;
      uStack_d60 = 1;
      pvVar7 = operator_new(0x11c);
      pvStack_c = (void *)0x0;
      if (pvVar7 == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_005e0270();
      }
      pvStack_c = (void *)0xffffffff;
      FUN_005e0240(auStack_a1c);
      uVar11 = 5;
      uVar8 = (**(code **)(*param_1 + 8))();
      if (5 < uVar8) {
LAB_0047ca71:
        iVar10 = 0;
        do {
          FUN_0044a580(acStack_c1e,&DAT_009a5068,&DAT_009a5010);
          pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,iVar10);
          uVar8 = 0;
          iVar2 = -(int)pcVar9;
LAB_0047caa1:
          if (*pcVar9 != pcVar9[(int)(acStack_c1e + iVar2)]) goto LAB_0047cabe;
          if (*pcVar9 != '\0') goto code_r0x0047cab0;
          iVar10 = iVar10 + 1;
        } while (iVar10 < 0x10);
        goto LAB_0047d089;
      }
LAB_0047d09c:
      (**(code **)(*DAT_00b5a780 + 4))(uVar4);
    }
  }
  ExceptionList = pvStack_c;
  return;
code_r0x0047cab0:
  uVar8 = uVar8 + 1;
  pcVar9 = pcVar9 + 1;
  if (0xff < uVar8) {
LAB_0047cabe:
    FUN_0044a580(auStack_314,&DAT_009a5068,&DAT_009a5011);
    pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,0);
    uVar8 = 0;
    iVar10 = -(int)pcVar9;
    goto LAB_0047caf0;
  }
  goto LAB_0047caa1;
  while( true ) {
    if (*pcVar9 == '\0') goto LAB_0047cb16;
    uVar8 = uVar8 + 1;
    pcVar9 = pcVar9 + 1;
    if (0xff < uVar8) break;
LAB_0047caf0:
    if (*pcVar9 != pcVar9[(int)(acStack_31c + iVar10)]) break;
  }
  unaff_BL = FUN_004753b0(uVar11,0);
LAB_0047cb16:
  FUN_0044a580(auStack_51c,&DAT_009a5068,&DAT_009a5012);
  pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,1);
  uVar8 = 0;
  iVar10 = -(int)pcVar9;
  do {
    if (*pcVar9 != pcVar9[(int)(acStack_514 + iVar10)]) break;
    if (*pcVar9 == '\0') goto LAB_0047cc30;
    uVar8 = uVar8 + 1;
    pcVar9 = pcVar9 + 1;
  } while (uVar8 < 0x100);
  iVar10 = (**(code **)(*param_1 + 0x10))(uVar11,1);
  uVar8 = 0;
  acStack_b26[0] = '\0';
  do {
    cVar1 = (acStack_b26 + uVar8)[iVar10 - (int)acStack_b26];
    acStack_b26[uVar8] = cVar1;
    if (cVar1 == '\0') goto LAB_0047cba4;
    uVar8 = uVar8 + 1;
  } while (uVar8 < 0x100);
  acStack_b26[0] = '\0';
LAB_0047cba4:
  piVar6 = (int *)(**(code **)(*(int *)(uStack_d60 + 0x202c) + 0x30))(acStack_b26);
  if (piVar6 == (int *)0x0) {
    FUN_0044a580(auStack_914,&DAT_009a5068,s_Action_Table_Error___Unknown_ACT_009a5014);
    FUN_00797b80(auStack_914);
    auStack_114[0] = 0;
    uVar5 = FUN_0044a580(auStack_114,s__>_Row__u_Col__u_009a5048,uVar11,1);
    FUN_00797b80(uVar5);
  }
  else {
    uStack_d60 = (uint)*(ushort *)(*piVar6 + 0x100);
LAB_0047cc30:
    FUN_0044a580(auStack_414,&DAT_009a5068,&DAT_009a5060);
    pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,2);
    uVar8 = 0;
    iVar10 = -(int)pcVar9;
    do {
      if (*pcVar9 != pcVar9[(int)(acStack_41c + iVar10)]) break;
      if (*pcVar9 == '\0') goto LAB_0047cc87;
      uVar8 = uVar8 + 1;
      pcVar9 = pcVar9 + 1;
    } while (uVar8 < 0x100);
    uStack_d64 = FUN_004756e0(uVar11,2);
LAB_0047cc87:
    local_d50 = local_d50 & 0xffffff00;
    uStack_d54 = uStack_d64;
    uStack_d58 = uVar4;
    iVar10 = (**(code **)(*param_1 + 0x10))(uVar11,3);
    uVar8 = 0;
    do {
      cVar1 = ((char *)((int)&uStack_d58 + uVar8))[iVar10 - (int)&uStack_d58];
      *(char *)((int)&uStack_d58 + uVar8) = cVar1;
      if (cVar1 == '\0') goto LAB_0047ccdd;
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x100);
    uStack_d58 = uStack_d58 & 0xffffff00;
LAB_0047ccdd:
    pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,4);
    FUN_004772e0(pcVar9,uVar11,4);
    uVar8 = 0;
    do {
      if (pcVar9[uVar8] == '\0') {
        if (uVar8 == 0) {
          fStack_c60 = 0.0;
        }
        else {
          dVar12 = _atof(pcVar9);
          fStack_c60 = (float)dVar12;
        }
        goto LAB_0047cd27;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x100);
    fStack_c60 = 0.0;
LAB_0047cd27:
    pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,5);
    FUN_004772e0(pcVar9,uVar11,5);
    uVar8 = 0;
    do {
      if (pcVar9[uVar8] == '\0') {
        if (uVar8 == 0) {
          uStack_c64 = 0.0;
        }
        else {
          dVar12 = _atof(pcVar9);
          uStack_c64 = (float)dVar12;
        }
        goto LAB_0047cd81;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x100);
    uStack_c64 = 0.0;
LAB_0047cd81:
    pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,6);
    FUN_004772e0(pcVar9,uVar11,6);
    uVar8 = 0;
    do {
      if (pcVar9[uVar8] == '\0') {
        if (uVar8 == 0) {
          fStack_c68 = 0.0;
        }
        else {
          dVar12 = _atof(pcVar9);
          fStack_c68 = (float)dVar12;
        }
        goto LAB_0047cdd4;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x100);
    fStack_c68 = 0.0;
LAB_0047cdd4:
    uVar3 = FUN_004753b0(uVar11,7);
    uStack_c64 = (float)CONCAT31(uStack_c64._1_3_,uVar3);
    uVar3 = FUN_004753b0(uVar11,8);
    uStack_c64._0_2_ = CONCAT11(uVar3,(undefined1)uStack_c64);
    pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,9);
    FUN_004772e0(pcVar9,uVar11,9);
    uVar8 = 0;
    do {
      if (pcVar9[uVar8] == '\0') {
        if (uVar8 == 0) {
          fStack_c68 = 0.0;
        }
        else {
          dVar12 = _atof(pcVar9);
          fStack_c68 = (float)dVar12;
        }
        goto LAB_0047ce49;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x100);
    fStack_c68 = 0.0;
LAB_0047ce49:
    uVar3 = FUN_004774b0(uVar11,10);
    uStack_c64 = (float)CONCAT31(uStack_c64._1_3_,uVar3);
    pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,0xb);
    FUN_004772e0(pcVar9,uVar11,0xb);
    uVar8 = 0;
    do {
      if (pcVar9[uVar8] == '\0') {
        if (uVar8 == 0) {
          fStack_c68 = 0.0;
        }
        else {
          dVar12 = _atof(pcVar9);
          fStack_c68 = (float)dVar12;
        }
        goto LAB_0047ceb1;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x100);
    fStack_c68 = 0.0;
LAB_0047ceb1:
    pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,0xc);
    FUN_004772e0(pcVar9,uVar11,0xc);
    uVar8 = 0;
    do {
      if (pcVar9[uVar8] == '\0') {
        if (uVar8 == 0) {
          fStack_c6c = 0.0;
        }
        else {
          dVar12 = _atof(pcVar9);
          fStack_c6c = (float)dVar12;
        }
        goto LAB_0047cf04;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x100);
    fStack_c6c = 0.0;
LAB_0047cf04:
    FUN_0044a580(auStack_654,&DAT_009a5068,&DAT_009a5061);
    pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,0xd);
    uVar8 = 0;
    iVar10 = -(int)pcVar9;
    do {
      if (*pcVar9 != pcVar9[(int)(acStack_65c + iVar10)]) break;
      if (*pcVar9 == '\0') {
        uStack_c70 = 0;
        goto LAB_0047cf73;
      }
      uVar8 = uVar8 + 1;
      pcVar9 = pcVar9 + 1;
    } while (uVar8 < 0x100);
    uStack_c70 = FUN_004756e0(uVar11,0xd);
LAB_0047cf73:
    FUN_0044a580(auStack_25c,&DAT_009a5068,&DAT_009a5062);
    pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,0xe);
    uVar8 = 0;
    iVar10 = -(int)pcVar9;
    do {
      if (*pcVar9 != pcVar9[(int)(acStack_264 + iVar10)]) break;
      if (*pcVar9 == '\0') {
        uStack_c74 = 0;
        goto LAB_0047cfd5;
      }
      uVar8 = uVar8 + 1;
      pcVar9 = pcVar9 + 1;
    } while (uVar8 < 0x100);
    uStack_c74 = FUN_004756e0(uVar11,0xe);
LAB_0047cfd5:
    FUN_0044a580(auStack_864,&DAT_009a5068,&DAT_009a5063);
    pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,0xf);
    uVar8 = 0;
    iVar10 = -(int)pcVar9;
    do {
      if (*pcVar9 != pcVar9[(int)(acStack_814 + iVar10)]) break;
      if (*pcVar9 == '\0') goto LAB_0047d076;
      uVar8 = uVar8 + 1;
      pcVar9 = pcVar9 + 1;
    } while (uVar8 < 0x100);
    FUN_0044a580(acStack_714,&DAT_009a5068,&DAT_009a5064);
    pcVar9 = (char *)(**(code **)(*param_1 + 0x10))(uVar11,0xf);
    uVar8 = 0;
    iVar10 = -(int)pcVar9;
    do {
      if (*pcVar9 != pcVar9[(int)(acStack_714 + iVar10)]) {
        unaff_BL = 0;
        goto LAB_0047d076;
      }
      if (*pcVar9 == '\0') break;
      uVar8 = uVar8 + 1;
      pcVar9 = pcVar9 + 1;
    } while (uVar8 < 0x100);
    unaff_BL = 1;
LAB_0047d076:
    FUN_005e0100(&uStack_d54,unaff_BL);
  }
LAB_0047d089:
  uVar11 = uVar11 + 1;
  uVar8 = (**(code **)(*param_1 + 8))();
  if (uVar8 <= uVar11) goto LAB_0047d09c;
  goto LAB_0047ca71;
}


// ==== FUN_0047d0d0 @ 0x0047d0d0 ====

void FUN_0047d0d0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009a5068,s_Action_009a4fa4);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0047d11e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0047d11e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_0047c8d0(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_0047d180 @ 0x0047d180 ====

void * FUN_0047d180(void)

{
  int *piVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  int *piVar4;
  undefined1 auStackY_268 [128];
  void *pvStack_c4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097dfb6;
  pvStack_c = ExceptionList;
  piVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009a50e0;
  FUN_0047e400();
  piVar4 = in_ECX + 0x80b;
  local_4._0_1_ = 1;
  FUN_0047e400();
  local_4._0_1_ = 2;
  pvVar2 = operator_new(0x102);
  local_4._0_1_ = 3;
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  puStack_8._0_1_ = 4;
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  pvStack_c._0_1_ = 5;
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar1 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580();
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580(auStackY_268 + 0xc0);
    FUN_0047c890();
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 != (void *)0x0) {
    FUN_0044a580(auStackY_268 + 0xbc,&DAT_009a5068);
    FUN_0047c890(auStackY_268 + 0xbc);
  }
  (**(code **)(*piVar4 + 0x24))();
  pvVar2 = operator_new(0x102);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    FUN_0044a580(auStackY_268 + 0xb8,&DAT_009a5068,s_SM_DEAD_009a4f6c);
    uVar3 = FUN_0047c890(auStackY_268 + 0xb8,auStackY_268 + 0xac);
  }
  (**(code **)(*piVar4 + 0x24))(uVar3);
  pvVar2 = operator_new(0x102);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    FUN_0044a580(auStackY_268 + 0xb4,&DAT_009a5068,s_SM_MOVE_009a4f74);
    uVar3 = FUN_0047c890(auStackY_268 + 0xb4,auStackY_268 + 0xa8);
  }
  (**(code **)(*piVar4 + 0x24))(uVar3);
  pvVar2 = operator_new(0x102);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    FUN_0044a580(auStackY_268 + 0xb0,&DAT_009a5068,s_SM_REVIVE_009a4f7c);
    uVar3 = FUN_0047c890(auStackY_268 + 0xb0,auStackY_268 + 0xa4);
  }
  (**(code **)(*piVar4 + 0x24))(uVar3);
  pvVar2 = operator_new(0x102);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    FUN_0044a580(auStackY_268 + 0xac,&DAT_009a5068,s_ENDSIEGE_009a4f88);
    uVar3 = FUN_0047c890(auStackY_268 + 0xac,auStackY_268 + 0xa0);
  }
  (**(code **)(*piVar4 + 0x24))(uVar3);
  pvVar2 = operator_new(0x102);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    FUN_0044a580(auStackY_268 + 0xa8,&DAT_009a5068,s_EMOTIMOTION2_009a4f94);
    uVar3 = FUN_0047c890(auStackY_268 + 0xa8,auStackY_268 + 0x9c);
  }
  (**(code **)(*piVar4 + 0x24))(uVar3);
  ExceptionList = pvStack_c4;
  return pvVar2;
}


// ==== FUN_0047e3a0 @ 0x0047e3a0 ====

void FUN_0047e3a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0097dfd3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a50e0;
  local_4 = 1;
  FUN_00473080();
  local_4 = local_4 & 0xffffff00;
  FUN_00473080();
  *in_ECX = &PTR_FUN_009a4184;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0047e400 @ 0x0047e400 ====

void FUN_0047e400(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097dfe8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009a3884;
  FUN_00472de0();
  in_ECX[2] = 0;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0047e460 @ 0x0047e460 ====

void FUN_0047e460(byte param_1)

{
  void *in_ECX;
  
  FUN_0047e3a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047e480 @ 0x0047e480 ====

void FUN_0047e480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047e490 @ 0x0047e490 ====

void FUN_0047e490(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a5104;
  return;
}


// ==== FUN_0047e4a0 @ 0x0047e4a0 ====

void FUN_0047e4a0(undefined4 param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 uStack_22c;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  uStack_22c = local_100;
  FUN_0044a580();
  uVar3 = 0;
  do {
    local_208[uVar3] = local_100[uVar3];
    if (local_100[uVar3] == '\0') goto LAB_0047e4ee;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  local_208[0] = '\0';
LAB_0047e4ee:
  local_108 = param_1;
  uStack_22c = local_208;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar4 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  uVar3 = 1;
  iVar5 = (**(code **)(*piVar4 + 8))();
  if (1 < iVar5 + 1U) {
    do {
      FUN_0044a580(&local_104,&DAT_009a50fc,s_SatatusEffect_009a50ec + 0xe);
      pcVar6 = (char *)(**(code **)(*piVar4 + 0x10))(uVar3,1);
      uVar7 = 0;
      iVar5 = 0xfc - (int)pcVar6;
      do {
        if (*pcVar6 != pcVar6[(int)(local_208 + iVar5)]) {
          uVar1 = FUN_004753b0(uVar3,0);
          uStack_22c = (char *)CONCAT31(uStack_22c._1_3_,uVar1);
          uVar1 = FUN_004753b0(uVar3,1);
          uStack_22c._0_2_ = CONCAT11(uVar1,(undefined1)uStack_22c);
          uVar2 = FUN_00475a90(uVar3,2);
          uStack_22c = (char *)CONCAT22(uVar2,(undefined2)uStack_22c);
          FUN_00475a90(uVar3,3);
          FUN_004756e0(uVar3,4);
          FUN_00475a90(uVar3,5);
          FUN_00475a90(uVar3,6);
          FUN_00475a90(uVar3,7);
          FUN_00475a90(uVar3,8);
          FUN_004756e0(uVar3,9);
          (**(code **)(*DAT_00b5ab8c + 8))(&uStack_22c);
          break;
        }
        if (*pcVar6 == '\0') break;
        uVar7 = uVar7 + 1;
        pcVar6 = pcVar6 + 1;
      } while (uVar7 < 0x100);
      uVar3 = uVar3 + 1;
      iVar5 = (**(code **)(*piVar4 + 8))();
    } while (uVar3 < iVar5 + 1U);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar4);
  return;
}


// ==== FUN_0047e670 @ 0x0047e670 ====

void FUN_0047e670(byte param_1)

{
  void *in_ECX;
  
  FUN_0047e480();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047e690 @ 0x0047e690 ====

void FUN_0047e690(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047e6b0 @ 0x0047e6b0 ====

void FUN_0047e6b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a5124;
  return;
}


// ==== FUN_0047e6c0 @ 0x0047e6c0 ====

void FUN_0047e6c0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  undefined4 uVar6;
  long lVar7;
  uint uVar8;
  int iVar9;
  bool bVar10;
  int iVar11;
  long *plVar12;
  char acStack_33a [2];
  long alStack_234 [3];
  undefined1 uStack_228;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580();
  uVar2 = 0;
  do {
    local_208[uVar2] = local_100[uVar2];
    if (local_100[uVar2] == '\0') goto LAB_0047e714;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_208[0] = '\0';
LAB_0047e714:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  FUN_00479840();
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (iVar4 == 1) {
LAB_0047e92e:
    (**(code **)(*DAT_00b5aa34 + 0xc))();
    return;
  }
  uVar2 = 1;
LAB_0047e771:
  FUN_0044a580(&local_104,&DAT_009a511c,&DAT_009a5118);
  pcVar5 = (char *)(**(code **)(*piVar3 + 0x10))(uVar2,0);
  uVar8 = 0;
  iVar4 = 0xfc - (int)pcVar5;
  do {
    if (*pcVar5 != pcVar5[(int)(local_208 + iVar4)]) {
      FUN_00475a90(uVar2,0);
      iVar11 = 1;
      iVar4 = (**(code **)(*piVar3 + 0x10))(uVar2);
      uVar8 = 0;
      goto LAB_0047e7e5;
    }
    if (*pcVar5 == '\0') break;
    uVar8 = uVar8 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar8 < 0x100);
  goto LAB_0047e913;
  while (uVar8 = uVar8 + 1, uVar8 < 0x100) {
LAB_0047e7e5:
    cVar1 = (acStack_33a + (uVar8 - 4))[iVar4 - (int)(acStack_33a + -4)];
    acStack_33a[uVar8 - 4] = cVar1;
    if (cVar1 == '\0') break;
  }
  FUN_004753b0(uVar2,2);
  FUN_004756e0(uVar2,3);
  plVar12 = alStack_234;
  iVar9 = 5;
  iVar4 = 3;
  do {
    uVar6 = (**(code **)(*piVar3 + 0x10))(uVar2,iVar9 + -1);
    uVar8 = (**(code **)(*DAT_00b5aa08 + 4))(uVar6);
    *(uint *)(iVar11 + -4) = uVar8 & 0xffff;
    pcVar5 = (char *)(**(code **)(*piVar3 + 0x10))(uVar2,iVar9);
    FUN_00475260(pcVar5,uVar2,iVar9);
    uVar8 = 0;
    do {
      if (pcVar5[uVar8] == '\0') {
        lVar7 = 0;
        if (uVar8 != 0) {
          lVar7 = _atol(pcVar5);
        }
        goto LAB_0047e8a1;
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 0x100);
    lVar7 = 0;
LAB_0047e8a1:
    *plVar12 = lVar7;
    plVar12 = plVar12 + 2;
    iVar9 = iVar9 + 2;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  pcVar5 = (char *)(**(code **)(*piVar3 + 0x10))(uVar2,10);
  FUN_00475260(pcVar5,uVar2,10);
  uVar8 = 0;
  do {
    if (pcVar5[uVar8] == '\0') {
      if ((uVar8 == 0) || (lVar7 = _atol(pcVar5), lVar7 == 0)) {
        uStack_228 = 0;
      }
      else {
        uStack_228 = 1;
      }
      goto LAB_0047e8fc;
    }
    uVar8 = uVar8 + 1;
  } while (uVar8 < 0x100);
  uStack_228 = 0;
LAB_0047e8fc:
  (**(code **)(*DAT_00b5ab90 + 4))(acStack_33a + -0xe);
LAB_0047e913:
  iVar4 = (**(code **)(*piVar3 + 8))();
  bVar10 = iVar4 - 1U <= uVar2;
  uVar2 = uVar2 + 1;
  if (bVar10) goto LAB_0047e92e;
  goto LAB_0047e771;
}


// ==== FUN_0047e950 @ 0x0047e950 ====

void FUN_0047e950(byte param_1)

{
  void *in_ECX;
  
  FUN_0047e690();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047e970 @ 0x0047e970 ====

void FUN_0047e970(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047e980 @ 0x0047e980 ====

void FUN_0047e980(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a518c;
  return;
}


// ==== FUN_0047e990 @ 0x0047e990 ====

void FUN_0047e990(short *param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_2 [2];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ab98 + 0xc))(1,0);
  (**(code **)(*piVar1 + 0x10))(param_1);
  iVar2 = 9;
  do {
    if (*param_1 != 0) {
      (**(code **)(*piVar1 + 0x14))(*param_1);
    }
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  (**(code **)(*DAT_00b5ab94 + 4))(auStack_2 + -0xe,piVar1);
  return;
}


// ==== FUN_0047ea10 @ 0x0047ea10 ====

void FUN_0047ea10(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  undefined2 uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  int iVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined4 uVar12;
  int iVar13;
  undefined4 local_228 [5];
  char acStack_214 [12];
  char local_208 [256];
  char local_108 [256];
  undefined4 local_8;
  undefined1 local_4;
  undefined1 local_3;
  undefined1 local_2;
  
  FUN_005fd550(0);
  FUN_0044a580(local_208,&DAT_009a5184,s_QuestText_009a5130);
  uVar4 = 0;
  do {
    local_108[uVar4] = local_208[uVar4];
    if (local_208[uVar4] == '\0') goto LAB_0047ea71;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  local_108[0] = '\0';
LAB_0047ea71:
  local_8 = param_1;
  local_4 = 10;
  local_3 = 0x2c;
  local_2 = 1;
  piVar5 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_108);
  (**(code **)(*piVar5 + 0x10))(0,0);
  uVar6 = FUN_00475a90(0,1);
  uVar12 = uVar6;
  FUN_0044a580(acStack_214,&DAT_009a5184,s_QuestIndex_009a513c);
  cVar2 = FUN_0047ae90(acStack_214);
  if ((cVar2 != '\0') || (15999 < (ushort)uVar6)) {
    FUN_0044a580(acStack_214,&DAT_009a5184,s_<_In_Quest_Text_File_>_QuestInde_009a5148);
    FUN_00797b80(acStack_214);
    return;
  }
  iVar9 = 3;
  iVar13 = 0xfd;
  do {
    pcVar7 = (char *)(**(code **)(*piVar5 + 0x10))(iVar9,0);
    FUN_0044a580(acStack_214,&DAT_009a5184,&DAT_009a5180);
    uVar4 = 0;
    iVar1 = -(int)pcVar7;
    while (*pcVar7 == pcVar7[(int)(acStack_214 + iVar1)]) {
      if (*pcVar7 == '\0') goto LAB_0047ec0a;
      uVar4 = uVar4 + 1;
      pcVar7 = pcVar7 + 1;
      if (0xff < uVar4) goto LAB_0047ec0a;
    }
    uVar6 = FUN_00475a90(iVar9,0);
    uVar8 = FUN_00475a90(iVar9,1);
    uVar10 = 2;
    uVar4 = (**(code **)(*piVar5 + 0xc))();
    if (uVar4 < 3) goto LAB_0047ebd7;
    puVar11 = local_228;
    do {
      uVar3 = FUN_00475a90(iVar9,uVar10);
      *(undefined2 *)puVar11 = uVar3;
      uVar10 = uVar10 + 1;
      puVar11 = (undefined4 *)((int)puVar11 + 2);
      uVar4 = (**(code **)(*piVar5 + 0xc))();
    } while (uVar10 < uVar4);
    if (uVar10 < 9) {
LAB_0047ebd7:
      puVar11 = (undefined4 *)((int)local_228 + (uVar10 - 2) * 2);
      for (uVar4 = 9 - uVar10 >> 1; uVar4 != 0; uVar4 = uVar4 - 1) {
        *puVar11 = 0;
        puVar11 = puVar11 + 1;
      }
      for (uVar4 = (uint)((9 - uVar10 & 1) != 0); uVar4 != 0; uVar4 = uVar4 - 1) {
        *(undefined2 *)puVar11 = 0;
        puVar11 = (undefined4 *)((int)puVar11 + 2);
      }
    }
    FUN_0047e990(uVar12,uVar6,uVar8,local_228);
LAB_0047ec0a:
    iVar9 = iVar9 + 1;
    iVar13 = iVar13 + -1;
    if (iVar13 == 0) {
      (**(code **)(*DAT_00b5aa34 + 0xc))(piVar5);
      return;
    }
  } while( true );
}


// ==== FUN_0047ec40 @ 0x0047ec40 ====

void FUN_0047ec40(byte param_1)

{
  void *in_ECX;
  
  FUN_0047e970();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047ec60 @ 0x0047ec60 ====

void FUN_0047ec60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047ec70 @ 0x0047ec70 ====

void FUN_0047ec70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a51a8;
  return;
}


// ==== FUN_0047ec80 @ 0x0047ec80 ====

void FUN_0047ec80(void)

{
  int *piVar1;
  undefined4 uStack_14;
  
  uStack_14 = 0;
  piVar1 = (int *)(**(code **)(*DAT_00b5aba0 + 0xc))(1);
  (**(code **)(*piVar1 + 4))(&uStack_14);
  (**(code **)(*DAT_00b5ab9c + 4))(piVar1);
  return;
}


// ==== FUN_0047ecf0 @ 0x0047ecf0 ====

void FUN_0047ecf0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  char *pcVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_226 [2];
  undefined2 uStack_224;
  undefined2 uStack_220;
  char local_208 [256];
  undefined4 local_108;
  char local_104 [4];
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100);
  uVar2 = 0;
  do {
    local_208[uVar2] = local_100[uVar2];
    if (local_100[uVar2] == '\0') goto LAB_0047ed3e;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_208[0] = '\0';
LAB_0047ed3e:
  local_108 = param_1;
  local_104[0] = '\n';
  local_104[1] = 0x2c;
  local_104[2] = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  iVar6 = 1;
  iVar7 = 0x3ff;
  do {
    pcVar4 = (char *)(**(code **)(*piVar3 + 0x10))(iVar6,0);
    FUN_0044a580(local_104,&DAT_009a51a0,s_Quest_009a5198 + 6);
    uVar2 = 0;
    iVar1 = -(int)pcVar4;
    do {
      if (*pcVar4 != pcVar4[(int)(local_104 + iVar1)]) {
        FUN_00475a90(iVar6,0);
        FUN_00475a90(iVar6,1);
        FUN_00475a90(iVar6,2);
        FUN_00475a90(iVar6,3);
        FUN_00475a90(iVar6,4);
        piVar5 = (int *)(**(code **)(*DAT_00b5aba0 + 0xc))(1,0);
        iVar7 = CONCAT22(uStack_224,uStack_220);
        (**(code **)(*piVar5 + 4))(auStack_226 + -10);
        (**(code **)(*DAT_00b5ab9c + 4))(piVar5);
        break;
      }
      if (*pcVar4 == '\0') break;
      uVar2 = uVar2 + 1;
      pcVar4 = pcVar4 + 1;
    } while (uVar2 < 0x100);
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + -1;
    if (iVar7 == 0) {
      (**(code **)(*DAT_00b5aa34 + 0xc))(piVar3);
      return;
    }
  } while( true );
}


// ==== FUN_0047eeb0 @ 0x0047eeb0 ====

void FUN_0047eeb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0047ec60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047eed0 @ 0x0047eed0 ====

void FUN_0047eed0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_0047eef0 @ 0x0047eef0 ====

void FUN_0047eef0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a51dc;
  return;
}


// ==== FUN_0047ef00 @ 0x0047ef00 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_0047ef00(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  char local_2de0 [256];
  undefined4 local_2ce0;
  undefined1 local_2cdc;
  undefined1 local_2cdb;
  undefined1 local_2cda;
  char local_2cd8 [11456];
  void *pvStack_18;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097e02b;
  pvStack_c = ExceptionList;
  uStack_10 = 0x47ef1f;
  local_2de0[0] = '\0';
  ExceptionList = &pvStack_c;
  FUN_0044a580(local_2cd8,&DAT_009a51bc,s_Skill_009a51b4);
  uVar1 = 0;
  do {
    local_2de0[uVar1] = local_2cd8[uVar1];
    if (local_2cd8[uVar1] == '\0') goto LAB_0047ef6e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_2de0[0] = '\0';
LAB_0047ef6e:
  local_2ce0 = param_1;
  local_2cdc = 10;
  local_2cdb = 0x2c;
  local_2cda = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_2de0);
  FUN_00480270();
  puStack_8 = (undefined1 *)0x0;
  FUN_00480380(local_2cd8 + 0xfc,uVar2);
  FUN_00480a90(local_2cd8 + 0xfc,uVar2);
  FUN_004811d0(local_2cd8 + 0xfc,uVar2);
  FUN_0047f1e0(local_2cd8 + 0xfc,uVar2);
  (**(code **)(*DAT_00b5aa30 + 4))(local_2cd8 + 0xfc);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  uStack_10 = 0xffffffff;
  FUN_00480300();
  ExceptionList = pvStack_18;
  return;
}


// ==== FUN_0047f050 @ 0x0047f050 ====

void FUN_0047f050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a51d4;
  return;
}


// ==== FUN_0047f060 @ 0x0047f060 ====

void FUN_0047f060(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a51c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047f080 @ 0x0047f080 ====

void FUN_0047f080(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a51cc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047f0a0 @ 0x0047f0a0 ====

void FUN_0047f0a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a51d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047f0c0 @ 0x0047f0c0 ====

void FUN_0047f0c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a51c4;
  return;
}


// ==== FUN_0047f0d0 @ 0x0047f0d0 ====

void FUN_0047f0d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0047eed0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047f0f0 @ 0x0047f0f0 ====

void FUN_0047f0f0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[0xe] = &PTR_FUN_009a51c4;
  *in_ECX = &PTR_FUN_009a51cc;
  return;
}


// ==== FUN_0047f100 @ 0x0047f100 ====

void FUN_0047f100(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  char local_200 [256];
  undefined1 local_100 [256];
  
  local_200[0] = FUN_0044a440(param_2);
  if (local_200[0] == '\0') {
    FUN_0044a580(local_200,s_Wrong_Title____s___s_009a5200,param_1,param_2);
    FUN_00797b80(local_200);
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                         s___Loader_Article_Skill_cpp_009a51e4,0x1d6);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  return;
}


// ==== FUN_0047f180 @ 0x0047f180 ====

void FUN_0047f180(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a521c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x80,0x10,FUN_0047f0f0);
  return;
}


// ==== FUN_0047f1a0 @ 0x0047f1a0 ====

void FUN_0047f1a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0047f180();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0047f1e0 @ 0x0047f1e0 ====

void FUN_0047f1e0(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte bVar4;
  undefined1 uVar5;
  undefined2 uVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  char cVar14;
  uint uVar13;
  int iVar15;
  undefined2 *puVar16;
  undefined4 uVar17;
  uint *puVar18;
  uint uVar19;
  char ***pppcStack_698;
  undefined *puStack_694;
  char ***pppcStack_690;
  undefined *puStack_68c;
  char ***pppcStack_688;
  undefined *puStack_684;
  char ***pppcStack_680;
  undefined *puStack_67c;
  char ***pppcStack_678;
  undefined *puStack_674;
  char **ppcStack_670;
  undefined *puStack_66c;
  char **ppcStack_668;
  undefined *puStack_664;
  char **ppcStack_660;
  undefined *puStack_65c;
  char **ppcStack_658;
  undefined *puStack_654;
  char **ppcStack_650;
  undefined *puStack_64c;
  undefined1 **ppuStack_648;
  undefined *puStack_644;
  undefined1 **ppuStack_640;
  undefined *puStack_63c;
  char *pcStack_638;
  undefined *puStack_634;
  char *pcStack_630;
  undefined *puStack_62c;
  char *pcStack_628;
  char acStack_61a [2];
  char *apcStack_618 [2];
  char acStack_610 [8];
  char acStack_608 [8];
  char local_600 [104];
  undefined1 auStack_598 [256];
  undefined1 auStack_498 [256];
  undefined1 auStack_398 [256];
  undefined1 auStack_298 [256];
  undefined1 auStack_198 [260];
  int iStack_94;
  
  pcStack_628 = s_LevelIndex_009a5384;
  pcStack_630 = local_600;
  puStack_62c = &DAT_009a51bc;
  puStack_634 = (undefined *)0x47f1fe;
  FUN_0044a580();
  pcStack_628 = local_600;
  puStack_62c = (undefined *)0x0;
  pcStack_630 = (char *)0xb8;
  puStack_634 = (undefined *)0x47f21b;
  puStack_634 = (undefined *)(**(code **)(*param_2 + 0x10))();
  pcStack_638 = (char *)0x47f223;
  FUN_0047f100();
  pcStack_630 = s_SPCostLevelUp_009a5374;
  pcStack_638 = acStack_608;
  puStack_634 = &DAT_009a51bc;
  puStack_63c = (undefined *)0x47f237;
  FUN_0044a580();
  pcStack_630 = acStack_608;
  puStack_634 = (undefined *)0x1;
  pcStack_638 = (char *)0xb8;
  puStack_63c = (undefined *)0x47f24d;
  puStack_63c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppuStack_640 = (undefined1 **)0x47f255;
  FUN_0047f100();
  pcStack_638 = s_PCLevel_009a536c;
  ppuStack_640 = (undefined1 **)acStack_610;
  puStack_63c = &DAT_009a51bc;
  puStack_644 = (undefined *)0x47f269;
  FUN_0044a580();
  pcStack_638 = acStack_610;
  puStack_63c = (undefined *)0x2;
  ppuStack_640 = (undefined1 **)0xb8;
  puStack_644 = (undefined *)0x47f27f;
  puStack_644 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppuStack_648 = (undefined1 **)0x47f287;
  FUN_0047f100();
  ppuStack_640 = (undefined1 **)s_MaxOption_009a5360;
  ppuStack_648 = apcStack_618;
  puStack_644 = &DAT_009a51bc;
  puStack_64c = (undefined *)0x47f29b;
  FUN_0044a580();
  ppuStack_640 = apcStack_618;
  puStack_644 = (undefined *)0x3;
  ppuStack_648 = (undefined1 **)0xb8;
  puStack_64c = (undefined *)0x47f2b1;
  puStack_64c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppcStack_650 = (char **)0x47f2b9;
  FUN_0047f100();
  ppuStack_648 = (undefined1 **)s_OptionIndex_009a5354;
  ppcStack_650 = (char **)(acStack_61a + -6);
  puStack_64c = &DAT_009a51bc;
  puStack_654 = (undefined *)0x47f2cd;
  FUN_0044a580();
  ppuStack_648 = (undefined1 **)(acStack_61a + -6);
  puStack_64c = (undefined *)0x4;
  ppcStack_650 = (char **)0xb8;
  puStack_654 = (undefined *)0x47f2e3;
  puStack_654 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppcStack_658 = (char **)0x47f2eb;
  FUN_0047f100();
  ppcStack_650 = (char **)s_OptionCode_009a5348;
  ppcStack_658 = &pcStack_628;
  puStack_654 = &DAT_009a51bc;
  puStack_65c = (undefined *)0x47f2ff;
  FUN_0044a580();
  ppcStack_650 = &pcStack_628;
  puStack_654 = (undefined *)0x5;
  ppcStack_658 = (char **)0xb8;
  puStack_65c = (undefined *)0x47f315;
  puStack_65c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppcStack_660 = (char **)0x47f31d;
  FUN_0047f100();
  ppcStack_658 = (char **)s_OptionValue_009a533c;
  ppcStack_660 = &pcStack_630;
  puStack_65c = &DAT_009a51bc;
  puStack_664 = (undefined *)0x47f331;
  FUN_0044a580();
  ppcStack_658 = &pcStack_630;
  puStack_65c = (undefined *)0x6;
  ppcStack_660 = (char **)0xb8;
  puStack_664 = (undefined *)0x47f347;
  puStack_664 = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppcStack_668 = (char **)0x47f34f;
  FUN_0047f100();
  ppcStack_660 = (char **)s_MaxRequire_009a5330;
  ppcStack_668 = &pcStack_638;
  puStack_664 = &DAT_009a51bc;
  puStack_66c = (undefined *)0x47f363;
  FUN_0044a580();
  ppcStack_660 = &pcStack_638;
  puStack_664 = (undefined *)0x7;
  ppcStack_668 = (char **)0xb8;
  puStack_66c = (undefined *)0x47f379;
  puStack_66c = (undefined *)(**(code **)(*param_2 + 0x10))();
  ppcStack_670 = (char **)0x47f381;
  FUN_0047f100();
  ppcStack_668 = (char **)s_ReqIndex_009a5324;
  ppcStack_670 = (char **)&ppuStack_640;
  puStack_66c = &DAT_009a51bc;
  puStack_674 = (undefined *)0x47f395;
  FUN_0044a580();
  ppcStack_668 = (char **)&ppuStack_640;
  puStack_66c = (undefined *)0x8;
  ppcStack_670 = (char **)0xb8;
  puStack_674 = (undefined *)0x47f3ab;
  puStack_674 = (undefined *)(**(code **)(*param_2 + 0x10))();
  pppcStack_678 = (undefined1 ***)0x47f3b3;
  FUN_0047f100();
  ppcStack_670 = (char **)s_Index_009a531c;
  pppcStack_678 = &ppuStack_648;
  puStack_674 = &DAT_009a51bc;
  puStack_67c = (undefined *)0x47f3c7;
  FUN_0044a580();
  ppcStack_670 = (char **)&ppuStack_648;
  puStack_674 = (undefined *)0x9;
  pppcStack_678 = (undefined1 ***)0xb8;
  puStack_67c = (undefined *)0x47f3dd;
  puStack_67c = (undefined *)(**(code **)(*param_2 + 0x10))();
  pppcStack_680 = (undefined1 ***)0x47f3e5;
  FUN_0047f100();
  pppcStack_678 = (char ***)s_Level_009a5314;
  pppcStack_680 = &ppcStack_650;
  puStack_67c = &DAT_009a51bc;
  puStack_684 = (undefined *)0x47f3f9;
  FUN_0044a580();
  pppcStack_678 = &ppcStack_650;
  puStack_67c = (undefined *)0xa;
  pppcStack_680 = (undefined1 ***)0xb8;
  puStack_684 = (undefined *)0x47f40f;
  puStack_684 = (undefined *)(**(code **)(*param_2 + 0x10))();
  pppcStack_688 = (undefined1 ***)0x47f417;
  FUN_0047f100();
  pppcStack_680 = (char ***)s_CastTick_009a5308;
  pppcStack_688 = &ppcStack_658;
  puStack_684 = &DAT_009a51bc;
  puStack_68c = (undefined *)0x47f42b;
  FUN_0044a580();
  pppcStack_680 = &ppcStack_658;
  puStack_684 = (undefined *)0xb;
  pppcStack_688 = (undefined1 ***)0xb8;
  puStack_68c = (undefined *)0x47f441;
  puStack_68c = (undefined *)(**(code **)(*param_2 + 0x10))();
  pppcStack_690 = (undefined1 ***)0x47f449;
  FUN_0047f100();
  pppcStack_688 = (char ***)s_CoolTick_009a52fc;
  pppcStack_690 = &ppcStack_660;
  puStack_68c = &DAT_009a51bc;
  puStack_694 = (undefined *)0x47f45d;
  FUN_0044a580();
  pppcStack_688 = &ppcStack_660;
  puStack_68c = (undefined *)0xc;
  pppcStack_690 = (undefined1 ***)0xb8;
  puStack_694 = (undefined *)0x47f473;
  puStack_694 = (undefined *)(**(code **)(*param_2 + 0x10))();
  pppcStack_698 = (undefined1 ***)0x47f47b;
  FUN_0047f100();
  pppcStack_690 = (char ***)s_StartComboIndex_009a52ec;
  pppcStack_698 = &ppcStack_668;
  puStack_694 = &DAT_009a51bc;
  FUN_0044a580();
  pppcStack_690 = &ppcStack_668;
  puStack_694 = (undefined *)0xd;
  pppcStack_698 = (undefined1 ***)0xb8;
  uVar7 = (**(code **)(*param_2 + 0x10))();
  FUN_0047f100(uVar7);
  pppcStack_698 = (char ***)s_EndComboIndex_009a52dc;
  FUN_0044a580(&ppcStack_670,&DAT_009a51bc);
  pppcStack_698 = &ppcStack_670;
  uVar17 = 0xb8;
  uVar7 = (**(code **)(*param_2 + 0x10))(0xb8,0xe);
  FUN_0047f100(uVar7,uVar17);
  FUN_0044a580(&pppcStack_678,&DAT_009a51bc,s_ResourceHP_009a52d0);
  uVar17 = 0xb8;
  uVar7 = (**(code **)(*param_2 + 0x10))(0xb8,0xf,&pppcStack_678);
  FUN_0047f100(uVar7,uVar17);
  FUN_0044a580(&pppcStack_680,&DAT_009a51bc,s_ResourceMP_009a52c4);
  uVar17 = 0xb8;
  uVar7 = (**(code **)(*param_2 + 0x10))(0xb8,0x10,&pppcStack_680);
  FUN_0047f100(uVar7,uVar17);
  FUN_0044a580(&pppcStack_688,&DAT_009a51bc,s_ResourceItemCode_009a52b0);
  uVar17 = 0xb8;
  uVar7 = (**(code **)(*param_2 + 0x10))(0xb8,0x11,&pppcStack_688);
  FUN_0047f100(uVar7,uVar17);
  FUN_0044a580(&pppcStack_690,&DAT_009a51bc,s_ResourceItemCount_009a529c);
  uVar17 = 0xb8;
  uVar7 = (**(code **)(*param_2 + 0x10))(0xb8,0x12,&pppcStack_690);
  FUN_0047f100(uVar7,uVar17);
  uVar19 = *(uint *)(iStack_94 + 0x804);
  uVar13 = 0;
  if (uVar19 != 0) {
    uVar12 = 0;
    do {
      iVar2 = uVar12 * 6 + 0xb9;
      bVar4 = FUN_004753b0(iVar2,0);
      if (bVar4 != (byte)(uVar13 >> 0x10)) {
        auStack_498[0] = 0;
        FUN_0044a580(auStack_498,s_Wrong_Level_Index____d____d_009a527c,bVar4,uVar12);
        FUN_00797b80(auStack_498);
        auStack_398[0] = 0;
        uVar7 = FUN_0044a580(auStack_398,s_File___s__Line___d_0099f0a0,
                             s___Loader_Article_Skill_cpp_009a51e4,0x17c);
        FUN_00797b80(uVar7);
        FUN_00797a40();
      }
      iVar1 = (uint)bVar4 * 0x80 + 4 + iStack_94;
      uVar5 = FUN_004753b0(iVar2,1);
      *(undefined1 *)(iVar1 + 0x7c) = uVar5;
      uVar5 = FUN_004753b0(iVar2,2);
      *(undefined1 *)(iVar1 + 0x50) = uVar5;
      uVar12 = FUN_004753b0(iVar2,3);
      *(int *)(iVar1 + 0x34) = *(int *)(iVar1 + 0x34) + (uVar12 & 0xff);
      iVar9 = uVar12 << 0x18;
      uVar13 = uVar13 & 0xffffff;
      if ((char)uVar12 != '\0') {
        puVar18 = (uint *)(iVar1 + 4);
        iVar15 = 0;
        do {
          bVar4 = FUN_004753b0(iVar15 + iVar2,4);
          if (bVar4 != (byte)(uVar13 >> 0x18)) {
            auStack_598[0] = 0;
            FUN_0044a580(auStack_598,s_Wrong_LevelCharge_Option_Index___009a5250,bVar4,iVar15);
            FUN_00797b80(auStack_598);
            auStack_298[0] = 0;
            uVar7 = FUN_0044a580(auStack_298,s_File___s__Line___d_0099f0a0,
                                 s___Loader_Article_Skill_cpp_009a51e4,400);
            FUN_00797b80(uVar7);
            FUN_00797a40();
          }
          iVar3 = *DAT_00b5aa08;
          iVar10 = (uint)bVar4 + iVar2;
          uVar7 = (**(code **)(*param_2 + 0x10))(iVar10,5);
          uVar12 = (**(code **)(iVar3 + 4))(uVar7);
          *puVar18 = uVar12 & 0xffff;
          uVar12 = FUN_004756e0(iVar10,6);
          iVar15 = iVar15 + 1;
          puVar18[1] = uVar12;
          bVar4 = (char)(uVar13 >> 0x18) + 1;
          puVar18 = puVar18 + 2;
          uVar13 = CONCAT13(bVar4,(int3)uVar13);
        } while (bVar4 < (byte)((uint)iVar9 >> 0x18));
      }
      uVar12 = FUN_004753b0(iVar2,7);
      cVar14 = (char)(uVar13 >> 0x10);
      uVar12 = uVar12 & 0xff;
      *(int *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) + uVar12;
      uVar11 = 0;
      if (uVar12 != 0) {
        puVar16 = (undefined2 *)(iVar1 + 0x3c);
        do {
          uVar8 = FUN_004753b0(uVar11 + iVar2,8);
          uVar8 = uVar8 & 0xff;
          if (uVar8 != uVar11) {
            pppcStack_698 = (char ***)((uint)pppcStack_698 & 0xffffff00);
            FUN_0044a580(&pppcStack_698,s_Wrong_LevelCharge_RequireSkill_I_009a5220,uVar8,uVar11);
            FUN_00797b80(&pppcStack_698);
            auStack_198[0] = 0;
            uVar7 = FUN_0044a580(auStack_198,s_File___s__Line___d_0099f0a0,
                                 s___Loader_Article_Skill_cpp_009a51e4,0x1a8);
            FUN_00797b80(uVar7);
            FUN_00797a40();
          }
          iVar9 = uVar8 + iVar2;
          uVar6 = FUN_00475a90(iVar9,9);
          *puVar16 = uVar6;
          uVar5 = FUN_004753b0(iVar9,10);
          cVar14 = (char)(uVar13 >> 0x10);
          *(undefined1 *)(puVar16 + 1) = uVar5;
          uVar11 = uVar11 + 1;
          puVar16 = puVar16 + 2;
        } while (uVar11 < uVar12);
      }
      uVar7 = FUN_004756e0(iVar2,0xc);
      *(undefined4 *)(iVar1 + 100) = uVar7;
      *(undefined1 *)(iVar1 + 0x70) = *(undefined1 *)(iStack_94 + 0x2bac);
      *(undefined2 *)(iVar1 + 0x68) = 0;
      *(undefined2 *)(iVar1 + 0x6a) = 0;
      *(undefined4 *)(iVar1 + 0x6c) = 0;
      *(undefined1 *)(iVar1 + 0x71) = 0;
      *(undefined4 *)(iVar1 + 0x74) = 0;
      uVar7 = FUN_004756e0(iVar2,0xb);
      *(undefined4 *)(iVar1 + 0x78) = uVar7;
      uVar5 = FUN_004753b0(iVar2,0xd);
      *(undefined1 *)(iVar1 + 0x60) = uVar5;
      uVar5 = FUN_004753b0(iVar2,0xe);
      *(undefined1 *)(iVar1 + 0x61) = uVar5;
      uVar6 = FUN_00475a90(iVar2,0xf);
      *(undefined2 *)(iVar1 + 0x5a) = uVar6;
      uVar6 = FUN_00475a90(iVar2,0x10);
      *(undefined2 *)(iVar1 + 0x5c) = uVar6;
      uVar7 = FUN_004756e0(iVar2,0x11);
      *(undefined4 *)(iVar1 + 0x54) = uVar7;
      uVar5 = FUN_004753b0(iVar2,0x12);
      *(undefined1 *)(iVar1 + 0x58) = uVar5;
      uVar12 = (uint)(byte)(cVar14 + 1U);
      uVar13 = (uint)(byte)(cVar14 + 1U) << 0x10;
    } while (uVar12 < uVar19);
  }
  return;
}


// ==== FUN_0047f910 @ 0x0047f910 ====

undefined4 FUN_0047f910(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_100 [256];
  
  FUN_0044a580(local_100,&DAT_009a51bc,s_PREPARE_009a53a4);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 == '\0') {
    FUN_0044a580(local_100,&DAT_009a51bc,s_ACTION_009a539c);
    cVar1 = FUN_0044a440(local_100);
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_0044a580(local_100,&DAT_009a51bc,s_NO_CANCEL_009a5390);
    cVar1 = FUN_0044a440(local_100);
    if (cVar1 != '\0') {
      return 2;
    }
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                         s___Loader_Article_Skill_cpp_009a51e4,0x1ec);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  return 0;
}


// ==== FUN_0047f9f0 @ 0x0047f9f0 ====

uint FUN_0047f9f0(int param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined1 local_200 [232];
  undefined1 auStack_118 [280];
  
  piVar3 = DAT_00b5aa34;
  uVar2 = 0;
  do {
    if (*(char *)(uVar2 + param_1) == '\0') goto LAB_0047fa26;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  uVar2 = 0;
LAB_0047fa26:
  FUN_0044a580(local_200,&DAT_009a51bc,s_Skill_TargetFlag__009a53ac);
  piVar3 = (int *)(**(code **)(*piVar3 + 4))(local_200,param_1,uVar2,10,0x20,1);
  uVar7 = 0;
  iVar4 = (**(code **)(*piVar3 + 0xc))();
  if (iVar4 != 0) {
    do {
      cVar1 = FUN_00478070(0,uVar7);
      if (cVar1 == '\x01') break;
      uVar5 = FUN_004756e0(0,uVar7);
      if (0x20 < uVar5) {
        auStack_118[0] = 0;
        uVar6 = FUN_0044a580(auStack_118,s_File___s__Line___d_0099f0a0,
                             s___Loader_Article_Skill_cpp_009a51e4,0x203);
        FUN_00797b80(uVar6);
        FUN_00797a40();
      }
      uVar7 = uVar7 + 1;
      uVar5 = (**(code **)(*piVar3 + 0xc))();
    } while (uVar7 < uVar5);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar3);
  return uVar2;
}


// ==== FUN_0047faf0 @ 0x0047faf0 ====

undefined4 FUN_0047faf0(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  FUN_0044a580(local_200,&DAT_009a51bc,&DAT_009a53fc);
  cVar1 = FUN_0044a440(local_200);
  if (cVar1 == '\0') {
    FUN_0044a580(local_200,&DAT_009a51bc,s_PASSIVE_009a53f4);
    cVar1 = FUN_0044a440(local_200);
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_0044a580(local_200,&DAT_009a51bc,s_MASTERY_009a53ec);
    cVar1 = FUN_0044a440(local_200);
    if (cVar1 != '\0') {
      return 2;
    }
    FUN_0044a580(local_200,&DAT_009a51bc,s_ACTION_009a539c);
    cVar1 = FUN_0044a440(local_200);
    if (cVar1 != '\0') {
      return 0x10;
    }
    FUN_0044a580(local_200,&DAT_009a51bc,&DAT_009a53e4);
    cVar1 = FUN_0044a440(local_200);
    if (cVar1 != '\0') {
      return 0x20;
    }
    uVar2 = FUN_0044a670(s_ACTION_CAST_009a53d8);
    cVar1 = FUN_0044a440(uVar2);
    if (cVar1 != '\0') {
      return 0x30;
    }
    local_100[0] = 0;
    FUN_0044a580(local_100,s_Wrong_Type_Flag____s_009a53c0,param_1);
    FUN_00797b80(local_100);
    local_200[0] = 0;
    uVar2 = FUN_0044a580(local_200,s_File___s__Line___d_0099f0a0,
                         s___Loader_Article_Skill_cpp_009a51e4,0x22e);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  return 0;
}


// ==== FUN_0047fc90 @ 0x0047fc90 ====

undefined4 FUN_0047fc90(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_200 [256];
  undefined1 local_100 [256];
  
  FUN_0044a580(local_200,&DAT_009a51bc,&DAT_009a5430);
  cVar1 = FUN_0044a440(local_200);
  if (cVar1 == '\0') {
    FUN_0044a580(local_200,&DAT_009a51bc,&DAT_009a542c);
    cVar1 = FUN_0044a440(local_200);
    if (cVar1 != '\0') {
      return 1;
    }
    FUN_0044a580(local_200,&DAT_009a51bc,&DAT_009a5428);
    cVar1 = FUN_0044a440(local_200);
    if (cVar1 != '\0') {
      return 2;
    }
    FUN_0044a580(local_200,&DAT_009a51bc,&DAT_009a5424);
    cVar1 = FUN_0044a440(local_200);
    if (cVar1 != '\0') {
      return 3;
    }
    FUN_0044a580(local_200,&DAT_009a51bc,&DAT_009a5420);
    cVar1 = FUN_0044a440(local_200);
    if (cVar1 != '\0') {
      return 4;
    }
    uVar2 = FUN_0044a670(&DAT_009a541c);
    cVar1 = FUN_0044a440(uVar2);
    if (cVar1 != '\0') {
      return 5;
    }
    local_100[0] = 0;
    FUN_0044a580(local_100,s_Wrong_PC_Class____s_009a5404,param_1);
    FUN_00797b80(local_100);
    local_200[0] = 0;
    uVar2 = FUN_0044a580(local_200,s_File___s__Line___d_0099f0a0,
                         s___Loader_Article_Skill_cpp_009a51e4,0x255);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  return 0;
}


// ==== FUN_0047fe20 @ 0x0047fe20 ====

byte FUN_0047fe20(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined1 local_100 [256];
  
  FUN_0044a580(local_100,&DAT_009a51bc,&DAT_009a549c);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 0;
  }
  FUN_0044a580(local_100,&DAT_009a51bc,s_BAREHANDS_009a5490);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 1;
  }
  FUN_0044a580(local_100,&DAT_009a51bc,s_SHORTSWORD_009a5484);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 2;
  }
  FUN_0044a580(local_100,&DAT_009a51bc,s_SWORD_009a485c);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 3;
  }
  FUN_0044a580(local_100,&DAT_009a51bc,s_LONGSWORD_009a5478);
  cVar1 = FUN_0044a440(local_100);
  if (cVar1 != '\0') {
    return 4;
  }
  uVar2 = FUN_0044a670(s_SPEAR_009a483c);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 5;
  }
  uVar2 = FUN_0044a670(s_POLEARM_009a4834);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 6;
  }
  uVar2 = FUN_0044a670(&DAT_009a480c);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 7;
  }
  uVar2 = FUN_0044a670(s_CROSS_BOW_009a4800);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 8;
  }
  uVar2 = FUN_0044a670(s_STAFF_009a47f8);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 9;
  }
  uVar2 = FUN_0044a670(&DAT_009a5470);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 10;
  }
  uVar2 = FUN_0044a670(&DAT_009a47f0);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0xb;
  }
  uVar2 = FUN_0044a670(&DAT_009a482c);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0xc;
  }
  uVar2 = FUN_0044a670(&DAT_009a481c);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0xd;
  }
  uVar2 = FUN_0044a670(s_SHIELD_009a47e8);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0xe;
  }
  uVar2 = FUN_0044a670(s_SHIELD_SHORTSWORD_009a545c);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0xf;
  }
  uVar2 = FUN_0044a670(s_SHIELD_SWORD_009a544c);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x10;
  }
  uVar2 = FUN_0044a670(s_SHIELD_MACE_009a5440);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x11;
  }
  uVar2 = FUN_0044a670(s_SHIELD_AX_009a5434);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x12;
  }
  uVar2 = FUN_0044a670(s_GREAT_MACE_009a4820);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x13;
  }
  uVar2 = FUN_0044a670(s_GREAT_AX_009a4810);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x14;
  }
  uVar2 = FUN_0044a670(s_TWIN_SWORD_009a47dc);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x15;
  }
  uVar2 = FUN_0044a670(s_BLOODWHIP_009a47d0);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 != '\0') {
    return 0x16;
  }
  uVar2 = FUN_0044a670(s_FISHING_ROD_009a47c4);
  cVar1 = FUN_0044a440(uVar2);
  if (cVar1 == '\0') {
    uVar2 = FUN_0044a670(s_GAUNTLET_009a47b8);
    cVar1 = FUN_0044a440(uVar2);
    return -(cVar1 != '\0') & 0x18;
  }
  return 0x17;
}


