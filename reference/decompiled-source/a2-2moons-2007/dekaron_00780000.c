// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x780000-0x78ffff

// ==== FUN_00781050 @ 0x00781050 ====

void FUN_00781050(byte param_1)

{
  void *in_ECX;
  
  FUN_0077f110();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00781070 @ 0x00781070 ====

void FUN_00781070(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f6fe4;
  return;
}


// ==== FUN_00781090 @ 0x00781090 ====

void FUN_00781090(int param_1)

{
  undefined1 auStack_20 [20];
  undefined4 uStack_c;
  undefined4 *puStack_8;
  
  puStack_8 = (undefined4 *)0x78109c;
  puStack_8 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puStack_8 == (undefined4 *)0x0) {
    puStack_8 = (undefined4 *)0x0;
  }
  else {
    *puStack_8 = &PTR_FUN_009f5d18;
  }
  *(undefined1 *)(puStack_8 + 1) = *(undefined1 *)(param_1 + 0x10);
  uStack_c = 0x7810ba;
  FUN_00797a20();
  FUN_00401740(s_Debug_LevelUp__u_OK_009f6d94,0x13);
  FUN_00404230(auStack_20);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  return;
}


// ==== FUN_00781110 @ 0x00781110 ====

void FUN_00781110(int param_1)

{
  undefined4 *puVar1;
  uint unaff_ESI;
  void *pvStack_60;
  void *local_44 [5];
  uint uStack_30;
  void *pvStack_2c;
  undefined1 local_28 [28];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997670;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_MapMove_Succeeded_009f6da8,0x11);
    FUN_00404230(local_44);
    local_4 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009b64f0;
      *(undefined2 *)(puVar1 + 1) = 0;
      *(undefined2 *)((int)puVar1 + 6) = 0;
      *(undefined2 *)(puVar1 + 2) = 0;
      *(undefined1 *)((int)puVar1 + 10) = 1;
    }
    puVar1[1] = *(undefined4 *)(param_1 + 0x12);
    *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_1 + 0x16);
    *(undefined1 *)((int)puVar1 + 10) = 1;
    FUN_00797a20(puVar1);
    if (unaff_ESI < 0x10) {
      ExceptionList = pvStack_2c;
      return;
    }
  }
  else {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_MapMove_Failed_009f6dbc,0xe);
    FUN_00404230(local_28);
    local_4 = 1;
    FUN_00401660(local_28,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (uStack_30 < 0x10) {
      ExceptionList = pvStack_2c;
      return;
    }
    pvStack_60 = local_44[0];
  }
  _free(pvStack_60);
  return;
}


// ==== FUN_00781260 @ 0x00781260 ====

void FUN_00781260(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (*(char *)(param_1 + 0x11) == '\0') {
      FUN_00401740(s_Open_GuildWar_Teleport_Command_i_009f6df8,0x38);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      return;
    }
    uVar2 = 0x29;
    pcVar1 = s_Open_GuildWar_Teleport_Command_i_009f6dcc;
  }
  else {
    uVar2 = 0x26;
    pcVar1 = s_Open_GuildWar_Teleport_Command_i_009f6e34;
  }
  FUN_00401740(pcVar1,uVar2);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_007812e0 @ 0x007812e0 ====

void FUN_007812e0(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (*(char *)(param_1 + 0x11) != '\0') {
      FUN_00401740(s_Close_GuildWar_Teleport_Command_i_009f6e74,0x3a);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      return;
    }
    uVar2 = 0x17;
    pcVar1 = s_Close_GuildWar_Teleport_009f6e5c;
  }
  else {
    uVar2 = 0x27;
    pcVar1 = s_Close_GuildWar_Teleport_Command_i_009f6eb0;
  }
  FUN_00401740(pcVar1,uVar2);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00781360 @ 0x00781360 ====

void FUN_00781360(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_00401740(s_ResetCoolTime_Command_is_Success_009f6ed8,0x20);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_Close_GuildWar_Teleport_Command_i_009f6efc,0x27);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_007813c0 @ 0x007813c0 ====

void FUN_007813c0(int param_1)

{
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_00401740(s_PartyWar_Start_Succeeded_009f6f24,0x18);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_PartyWar_Start_Failed_009f6f40,0x15);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00781420 @ 0x00781420 ====

void FUN_00781420(undefined1 *param_1)

{
  undefined1 auStack_20 [4];
  undefined1 uStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 *puStack_8;
  
  if (*(int *)((int)param_1 + 0x10) == 0) {
    puStack_8 = &param_1;
    param_1 = (undefined1 *)0x1;
    uStack_c = 0x781444;
    (**(code **)(*DAT_00b5ada4 + 8))();
    uStack_c = 0xf;
    uStack_10 = 0;
    auStack_20[0] = 0;
    FUN_00401740(s_PartyWar_End_Succeeded_009f6f58,0x16);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  param_1 = auStack_20;
  puStack_8 = (undefined4 *)0xf;
  uStack_c = 0;
  uStack_1c = 0;
  FUN_00401740(s_PartyWar_End_Failed_009f6f70);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  return;
}


// ==== FUN_00781477 @ 0x00781477 ====

void FUN_00781477(void)

{
  undefined1 *puStack00000008;
  undefined1 auStack_1c [20];
  
  puStack00000008 = auStack_1c;
  FUN_00401740(s_PartyWar_End_Failed_009f6f70,0x13);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_007814b0 @ 0x007814b0 ====

void FUN_007814b0(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_00401740(s_Create_Brick_Succeeded_009f6f84,0x16);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_Create_Brick_Failed_009f6f9c,0x13);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00781510 @ 0x00781510 ====

void FUN_00781510(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_00401740(s_Destroy_Brick_Succeeded_009f6fb0,0x17);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_Destroy_Brick_Failed_009f6fc8,0x14);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00781570 @ 0x00781570 ====

undefined4 FUN_00781570(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x7000049) {
    if (uVar1 == 0x7000048) {
      FUN_007813c0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    switch(uVar1) {
    case 0x7000025:
      FUN_00781110(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x7000041:
      FUN_00781260(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x7000043:
      FUN_007812e0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x7000045:
      FUN_00781360(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else if (uVar1 < 0x700004f) {
    if (uVar1 == 0x700004e) {
      FUN_00781510(*(undefined4 *)(param_1 + 0xc));
      return 0;
    }
    if (uVar1 == 0x700004a) {
      FUN_00781420(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x700004c) {
      FUN_007814b0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else if (uVar1 == 0x8000006) {
    FUN_00781090(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_007816b0 @ 0x007816b0 ====

undefined4 FUN_007816b0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00781570(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007816e0 @ 0x007816e0 ====

void FUN_007816e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f6fe4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00781700 @ 0x00781700 ====

void FUN_00781700(short param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (1000 < (ushort)(param_1 * 4)) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                         s_d__usa_24_0_1_2__develop_module__009f7368,0xcb);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  *(ushort *)(in_ECX + 6) = param_1 * 4 + 0x10;
  return;
}


// ==== FUN_00781760 @ 0x00781760 ====

void FUN_00781760(ushort param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_1 < (ushort)(*(short *)(in_ECX + 6) - 0x10U) >> 2) {
    *(undefined4 *)(in_ECX + 0x10 + (uint)param_1 * 4) = param_2;
    return;
  }
  local_100[0] = 0;
  uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                       s_d__usa_24_0_1_2__develop_module__009f7368,0xd3);
  FUN_00797b80(uVar1);
  FUN_00797a40();
  *(undefined4 *)(in_ECX + 0x10 + (uint)param_1 * 4) = param_2;
  return;
}


// ==== FUN_007817f0 @ 0x007817f0 ====

undefined4 FUN_007817f0(void)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009f63f8;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_00781830 @ 0x00781830 ====

undefined4 FUN_00781830(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x7000040;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return 1;
}


// ==== FUN_00781880 @ 0x00781880 ====

undefined4 FUN_00781880(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x7000042;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return 1;
}


// ==== FUN_007818d0 @ 0x007818d0 ====

undefined4 FUN_007818d0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x7000044;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return 1;
}


// ==== FUN_00781920 @ 0x00781920 ====

undefined4 FUN_00781920(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x7000049;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return 1;
}


// ==== FUN_00781970 @ 0x00781970 ====

void FUN_00781970(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099768f;
  local_c = ExceptionList;
  if (*(int *)(in_ECX + 4) != -1) {
    ExceptionList = &local_c;
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x50d0005;
    *(undefined2 *)((int)pvVar2 + 6) = 0x14;
    uVar1 = FUN_004244d0();
    FUN_00781700(1);
    FUN_00781760(0,*(undefined4 *)(in_ECX + 4));
    iVar3 = (**(code **)(*DAT_00b5a6a8 + 4))();
    uStack_4 = 0;
    if (iVar3 == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_00465540(uVar1);
    }
    uStack_4 = 0xffffffff;
    FUN_00797a20(uVar1);
    *(undefined4 *)(in_ECX + 4) = 0xffffffff;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00781a30 @ 0x00781a30 ====

void FUN_00781a30(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x1c);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    FUN_00401660(puVar3 + 10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (*(char *)((int)puVar3 + 0x45) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x45) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x45);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x45);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x45);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x45);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_00781ac0 @ 0x00781ac0 ====

undefined4 FUN_00781ac0(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  void *pvVar7;
  int in_ECX;
  undefined1 auStack_1e [6];
  void *pvStack_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009976a8;
  local_c = ExceptionList;
  iVar4 = *(int *)(param_1 + 4);
  if (iVar4 != 0) {
    iVar1 = (*(int *)(param_1 + 8) - iVar4) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 0) {
        ExceptionList = &local_c;
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      ExceptionList = &local_c;
      uVar3 = thunk_FUN_00796f80(iVar4);
      iVar4 = (**(code **)(*DAT_00b5a75c + 8))(uVar3);
      if (iVar4 != 0) {
        piVar5 = (int *)(**(code **)(*DAT_00b5add0 + 0x48))();
        if (piVar5 != (int *)0x0) {
          puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x28))();
          *(undefined4 *)(in_ECX + 8) = *puVar6;
          *(undefined4 *)(in_ECX + 0xc) = puVar6[1];
          puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x2c))();
          *(undefined4 *)(in_ECX + 0x10) = *puVar6;
          *(undefined4 *)(in_ECX + 0x14) = puVar6[1];
        }
        FUN_00781970();
        piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
        uVar3 = (**(code **)(*piVar5 + 4))(0,s___Chat_Command_Developer_cpp_009f72f4,0xec);
        *(undefined4 *)(in_ECX + 4) = uVar3;
        FUN_0040d5f0(in_ECX + 0x10);
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        pvVar7 = operator_new(0x400);
        *(undefined4 *)((int)pvVar7 + 8) = uVar3;
        *(undefined4 *)((int)pvVar7 + 0xc) = 0x5040000;
        *(undefined2 *)((int)pvVar7 + 6) = 0x4c;
        iVar4 = FUN_004244d0();
        *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(in_ECX + 4);
        uVar3 = FUN_00405d30(0);
        uVar2 = thunk_FUN_00796f80(uVar3);
        *(undefined2 *)(iVar4 + 0x14) = uVar2;
        *(undefined4 *)(iVar4 + 0x18) = 1;
        *(undefined4 *)(iVar4 + 0x1c) = 0;
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        FUN_00797a50((undefined4 *)(iVar4 + 0x20),0,0xc);
        *(undefined1 *)(iVar4 + 0x2b) = 1;
        *(undefined4 *)(iVar4 + 0x20) = uVar3;
        *(undefined1 *)(iVar4 + 0x2a) = 0;
        puVar6 = (undefined4 *)FUN_004ef0e0(auStack_1e + -0xc);
        *(undefined4 *)(iVar4 + 0x24) = *puVar6;
        *(undefined2 *)(iVar4 + 0x28) = *(undefined2 *)(puVar6 + 1);
        *(undefined4 *)(iVar4 + 0x40) = 0;
        *(undefined4 *)(iVar4 + 0x44) = 0;
        puStack_8 = (undefined1 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        if (puStack_8 == (undefined1 *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_00465540(iVar4);
        }
        FUN_00797a20(uVar3);
        ExceptionList = pvStack_18;
        return 1;
      }
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_00781cc0 @ 0x00781cc0 ====

undefined4 FUN_00781cc0(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  void *pvVar7;
  int in_ECX;
  undefined1 auStack_1e [6];
  void *pvStack_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009976c1;
  local_c = ExceptionList;
  iVar4 = *(int *)(param_1 + 4);
  if (iVar4 != 0) {
    iVar1 = (*(int *)(param_1 + 8) - iVar4) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 0) {
        ExceptionList = &local_c;
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      ExceptionList = &local_c;
      uVar3 = thunk_FUN_00796f80(iVar4);
      iVar4 = (**(code **)(*DAT_00b5a770 + 8))(uVar3);
      if (iVar4 != 0) {
        piVar5 = (int *)(**(code **)(*DAT_00b5add0 + 0x48))();
        if (piVar5 != (int *)0x0) {
          puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x28))();
          *(undefined4 *)(in_ECX + 8) = *puVar6;
          *(undefined4 *)(in_ECX + 0xc) = puVar6[1];
          puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x2c))();
          *(undefined4 *)(in_ECX + 0x10) = *puVar6;
          *(undefined4 *)(in_ECX + 0x14) = puVar6[1];
        }
        FUN_00781970();
        piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
        uVar3 = (**(code **)(*piVar5 + 4))(0,s___Chat_Command_Developer_cpp_009f7314,0x128);
        *(undefined4 *)(in_ECX + 4) = uVar3;
        FUN_0040d5f0(in_ECX + 0x10);
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        pvVar7 = operator_new(0x400);
        *(undefined4 *)((int)pvVar7 + 8) = uVar3;
        *(undefined4 *)((int)pvVar7 + 0xc) = 0x5050000;
        *(undefined2 *)((int)pvVar7 + 6) = 0x20;
        iVar4 = FUN_004244d0();
        *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(in_ECX + 4);
        uVar3 = FUN_00405d30(0);
        uVar2 = thunk_FUN_00796f80(uVar3);
        *(undefined2 *)(iVar4 + 0x14) = uVar2;
        puVar6 = (undefined4 *)FUN_004ef0e0(auStack_1e + -0xc);
        *(undefined4 *)(iVar4 + 0x16) = *puVar6;
        *(undefined2 *)(iVar4 + 0x1a) = *(undefined2 *)(puVar6 + 1);
        puStack_8 = (undefined1 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        if (puStack_8 == (undefined1 *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_00465540(iVar4);
        }
        FUN_00797a20(uVar3);
        ExceptionList = pvStack_18;
        return 1;
      }
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_00781e80 @ 0x00781e80 ====

undefined4 FUN_00781e80(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  void *pvVar7;
  int in_ECX;
  undefined1 auStack_1e [6];
  void *pvStack_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009976da;
  local_c = ExceptionList;
  iVar4 = *(int *)(param_1 + 4);
  if (iVar4 != 0) {
    iVar1 = (*(int *)(param_1 + 8) - iVar4) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 0) {
        ExceptionList = &local_c;
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      ExceptionList = &local_c;
      uVar3 = thunk_FUN_00796f80(iVar4);
      iVar4 = (**(code **)(*DAT_00b5abd4 + 8))(uVar3);
      if (iVar4 != 0) {
        piVar5 = (int *)(**(code **)(*DAT_00b5add0 + 0x48))();
        if (piVar5 != (int *)0x0) {
          puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x28))();
          *(undefined4 *)(in_ECX + 8) = *puVar6;
          *(undefined4 *)(in_ECX + 0xc) = puVar6[1];
          puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x2c))();
          *(undefined4 *)(in_ECX + 0x10) = *puVar6;
          *(undefined4 *)(in_ECX + 0x14) = puVar6[1];
        }
        FUN_00781970();
        piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
        uVar3 = (**(code **)(*piVar5 + 4))(0,s___Chat_Command_Developer_cpp_009f7334,0x15c);
        *(undefined4 *)(in_ECX + 4) = uVar3;
        FUN_0040d5f0(in_ECX + 0x10);
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        pvVar7 = operator_new(0x400);
        *(undefined4 *)((int)pvVar7 + 8) = uVar3;
        *(undefined4 *)((int)pvVar7 + 0xc) = 0x5190000;
        *(undefined2 *)((int)pvVar7 + 6) = 0x4c;
        iVar4 = FUN_004244d0();
        *(undefined4 *)(iVar4 + 0x10) = 0xffffffff;
        *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(in_ECX + 4);
        uVar3 = FUN_00405d30(0);
        uVar2 = thunk_FUN_00796f80(uVar3);
        *(undefined2 *)(iVar4 + 0x18) = uVar2;
        *(undefined4 *)(iVar4 + 0x1c) = 1;
        *(undefined4 *)(iVar4 + 0x20) = 0;
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        FUN_00797a50((undefined4 *)(iVar4 + 0x24),0,0xc);
        *(undefined1 *)(iVar4 + 0x2f) = 1;
        *(undefined4 *)(iVar4 + 0x24) = uVar3;
        *(undefined1 *)(iVar4 + 0x2e) = 0;
        puVar6 = (undefined4 *)FUN_004ef0e0(auStack_1e + -0xc);
        *(undefined4 *)(iVar4 + 0x28) = *puVar6;
        *(undefined2 *)(iVar4 + 0x2c) = *(undefined2 *)(puVar6 + 1);
        *(undefined4 *)(iVar4 + 0x42) = 0;
        *(undefined4 *)(iVar4 + 0x46) = 0;
        puStack_8 = (undefined1 *)(**(code **)(*DAT_00b5a6a8 + 4))();
        if (puStack_8 == (undefined1 *)0x0) {
          uVar3 = 0;
        }
        else {
          uVar3 = FUN_00465540(iVar4);
        }
        FUN_00797a20(uVar3);
        ExceptionList = pvStack_18;
        return 1;
      }
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_00782080 @ 0x00782080 ====

undefined4 FUN_00782080(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 4) != 0) {
    if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c == 3) {
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = uVar3;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x7000024;
      *(undefined2 *)((int)pvVar4 + 6) = 0x18;
      iVar5 = FUN_004244d0();
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 != 0) {
        if ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 0) {
          uVar2 = thunk_FUN_00796f80(iVar1);
          *(undefined2 *)(iVar5 + 0x10) = uVar2;
          iVar1 = *(int *)(param_1 + 4);
          if ((iVar1 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          uVar2 = thunk_FUN_00796f80(iVar1 + 0x1c);
          *(undefined2 *)(iVar5 + 0x12) = uVar2;
          iVar1 = *(int *)(param_1 + 4);
          if ((iVar1 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c) < 3)) {
                    /* WARNING: Subroutine does not return */
            FUN_00405ca0();
          }
          uVar2 = thunk_FUN_00796f80(iVar1 + 0x38);
          *(undefined2 *)(iVar5 + 0x14) = uVar2;
          FUN_004d8570(iVar5);
          return 1;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
  }
  return 0;
}


// ==== FUN_007821b0 @ 0x007821b0 ====

undefined4 FUN_007821b0(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 4) != 0) {
    if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c == 1) {
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = uVar3;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x700003c;
      *(undefined2 *)((int)pvVar4 + 6) = 0x14;
      iVar5 = FUN_004244d0();
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 != 0) {
        if ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 0) {
          uVar2 = thunk_FUN_00796f80(iVar1);
          *(undefined2 *)(iVar5 + 0x10) = uVar2;
          FUN_004d8570(iVar5);
          return 1;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
  }
  return 0;
}


// ==== FUN_00782270 @ 0x00782270 ====

undefined4 FUN_00782270(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  
  if (*(int *)(param_1 + 4) != 0) {
    if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c == 1) {
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = uVar3;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x700003e;
      *(undefined2 *)((int)pvVar4 + 6) = 0x14;
      iVar5 = FUN_004244d0();
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 != 0) {
        if ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 0) {
          uVar2 = thunk_FUN_00796f80(iVar1);
          *(undefined2 *)(iVar5 + 0x10) = uVar2;
          FUN_004d8570(iVar5);
          return 1;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
  }
  return 0;
}


// ==== FUN_00782330 @ 0x00782330 ====

undefined4 FUN_00782330(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  
  if (*(int *)(param_1 + 4) != 0) {
    if ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c == 1) {
      uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar3 = operator_new(0x400);
      *(undefined4 *)((int)pvVar3 + 8) = uVar2;
      *(undefined4 *)((int)pvVar3 + 0xc) = 0x7000047;
      *(undefined2 *)((int)pvVar3 + 6) = 0x14;
      iVar4 = FUN_004244d0();
      iVar1 = *(int *)(param_1 + 4);
      if (iVar1 != 0) {
        if ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 0) {
          uVar2 = thunk_FUN_00796fb0(iVar1);
          *(undefined4 *)(iVar4 + 0x10) = uVar2;
          FUN_004d8570(iVar4);
          return 1;
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_00405ca0();
    }
  }
  return 0;
}


// ==== FUN_007823e0 @ 0x007823e0 ====

/* WARNING: Removing unreachable block (ram,0x0078241b) */

undefined4 FUN_007823e0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae08;
  uVar3 = thunk_FUN_00796f80(iVar1);
  (**(code **)(iVar2 + 0x18))(uVar3);
  return 1;
}


// ==== FUN_00782440 @ 0x00782440 ====

/* WARNING: Removing unreachable block (ram,0x0078247b) */

undefined4 FUN_00782440(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae08;
  uVar3 = thunk_FUN_00796f80(iVar1);
  (**(code **)(iVar2 + 0x1c))(uVar3);
  return 1;
}


// ==== FUN_007824a0 @ 0x007824a0 ====

/* WARNING: Removing unreachable block (ram,0x00782543) */
/* WARNING: Removing unreachable block (ram,0x007824ed) */
/* WARNING: Removing unreachable block (ram,0x0078250c) */
/* WARNING: Removing unreachable block (ram,0x00782541) */
/* WARNING: Removing unreachable block (ram,0x00782584) */
/* WARNING: Removing unreachable block (ram,0x00782591) */
/* WARNING: Removing unreachable block (ram,0x00782597) */
/* WARNING: Removing unreachable block (ram,0x007825b7) */
/* WARNING: Removing unreachable block (ram,0x0078261a) */
/* WARNING: Removing unreachable block (ram,0x007825fd) */
/* WARNING: Removing unreachable block (ram,0x00782626) */
/* WARNING: Removing unreachable block (ram,0x00782685) */
/* WARNING: Removing unreachable block (ram,0x007826b4) */
/* WARNING: Removing unreachable block (ram,0x007826e3) */
/* WARNING: Removing unreachable block (ram,0x00782712) */
/* WARNING: Removing unreachable block (ram,0x00782741) */
/* WARNING: Removing unreachable block (ram,0x00782770) */
/* WARNING: Removing unreachable block (ram,0x0078279f) */
/* WARNING: Removing unreachable block (ram,0x007827ce) */
/* WARNING: Removing unreachable block (ram,0x007827fd) */
/* WARNING: Removing unreachable block (ram,0x0078282c) */
/* WARNING: Removing unreachable block (ram,0x00782857) */
/* WARNING: Removing unreachable block (ram,0x00782882) */
/* WARNING: Removing unreachable block (ram,0x007828aa) */
/* WARNING: Removing unreachable block (ram,0x007828c0) */
/* WARNING: Removing unreachable block (ram,0x00782898) */
/* WARNING: Removing unreachable block (ram,0x007828a8) */
/* WARNING: Removing unreachable block (ram,0x0078286d) */
/* WARNING: Removing unreachable block (ram,0x0078287d) */
/* WARNING: Removing unreachable block (ram,0x00782842) */
/* WARNING: Removing unreachable block (ram,0x00782852) */
/* WARNING: Removing unreachable block (ram,0x00782813) */
/* WARNING: Removing unreachable block (ram,0x00782827) */
/* WARNING: Removing unreachable block (ram,0x007827e4) */
/* WARNING: Removing unreachable block (ram,0x007827f8) */
/* WARNING: Removing unreachable block (ram,0x007827b5) */
/* WARNING: Removing unreachable block (ram,0x007827c9) */
/* WARNING: Removing unreachable block (ram,0x00782786) */
/* WARNING: Removing unreachable block (ram,0x0078279a) */
/* WARNING: Removing unreachable block (ram,0x00782757) */
/* WARNING: Removing unreachable block (ram,0x0078276b) */
/* WARNING: Removing unreachable block (ram,0x00782728) */
/* WARNING: Removing unreachable block (ram,0x0078273c) */
/* WARNING: Removing unreachable block (ram,0x007826f9) */
/* WARNING: Removing unreachable block (ram,0x0078270d) */
/* WARNING: Removing unreachable block (ram,0x007826ca) */
/* WARNING: Removing unreachable block (ram,0x007826de) */
/* WARNING: Removing unreachable block (ram,0x0078269b) */
/* WARNING: Removing unreachable block (ram,0x007826af) */
/* WARNING: Removing unreachable block (ram,0x0078266c) */
/* WARNING: Removing unreachable block (ram,0x00782680) */
/* WARNING: Removing unreachable block (ram,0x007828d0) */
/* WARNING: Removing unreachable block (ram,0x007828f4) */
/* WARNING: Removing unreachable block (ram,0x007828eb) */
/* WARNING: Removing unreachable block (ram,0x00782916) */

uint FUN_007824a0(void)

{
  uint uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009976fc;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  uVar1 = FUN_00405670();
  ExceptionList = local_c;
  return uVar1 & 0xffffff00;
}


// ==== FUN_00782940 @ 0x00782940 ====

void FUN_00782940(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  undefined1 auStack_12 [6];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00997719;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f73d4;
  local_4 = 1;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  (**(code **)(*piVar1 + 8))(s___Chat_Command_Developer_cpp_009f7210,0x36,0,in_ECX[1]);
  FUN_00410b90(*(undefined4 *)(in_ECX[7] + 4));
  *(undefined4 *)(in_ECX[7] + 4) = in_ECX[7];
  in_ECX[8] = 0;
  *(undefined4 *)in_ECX[7] = in_ECX[7];
  *(undefined4 *)(in_ECX[7] + 8) = in_ECX[7];
  FUN_00410f60(auStack_12 + -0xe,*(undefined4 *)in_ECX[7],(undefined4 *)in_ECX[7]);
  _free((void *)in_ECX[7]);
  return;
}


// ==== FUN_00782a00 @ 0x00782a00 ====

undefined4 * FUN_00782a00(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  undefined4 *extraout_EAX_01;
  undefined4 *extraout_EAX_02;
  undefined4 *extraout_EAX_03;
  undefined4 *extraout_EAX_04;
  undefined4 *extraout_EAX_05;
  undefined4 *extraout_EAX_06;
  undefined4 *extraout_EAX_07;
  undefined4 *extraout_EAX_08;
  undefined4 *extraout_EAX_09;
  undefined4 *extraout_EAX_10;
  undefined4 *extraout_EAX_11;
  undefined4 *extraout_EAX_12;
  undefined4 *extraout_EAX_13;
  undefined4 *extraout_EAX_14;
  undefined4 *extraout_EAX_15;
  undefined4 *extraout_EAX_16;
  undefined4 *extraout_EAX_17;
  undefined4 *extraout_EAX_18;
  undefined4 *extraout_EAX_19;
  undefined4 *extraout_EAX_20;
  undefined4 *extraout_EAX_21;
  undefined4 *extraout_EAX_22;
  undefined4 *extraout_EAX_23;
  undefined4 *extraout_EAX_24;
  undefined4 *extraout_EAX_25;
  undefined4 *extraout_EAX_26;
  undefined4 *extraout_EAX_27;
  undefined4 *extraout_EAX_28;
  undefined4 *extraout_EAX_29;
  undefined4 *extraout_EAX_30;
  undefined4 *extraout_EAX_31;
  undefined4 *extraout_EAX_32;
  undefined4 *extraout_EAX_33;
  undefined4 *extraout_EAX_34;
  undefined4 *extraout_EAX_35;
  undefined4 *extraout_EAX_36;
  undefined4 *extraout_EAX_37;
  undefined4 *extraout_EAX_38;
  undefined4 *extraout_EAX_39;
  undefined4 *extraout_EAX_40;
  undefined4 *extraout_EAX_41;
  undefined4 *extraout_EAX_42;
  undefined4 *extraout_EAX_43;
  undefined4 *extraout_EAX_44;
  undefined4 *in_ECX;
  undefined4 local_84;
  undefined4 local_80;
  undefined1 local_7c [4];
  void *local_78;
  undefined4 local_68;
  uint local_64;
  undefined1 local_60 [4];
  void *local_5c;
  undefined4 local_4c;
  uint local_48;
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099788c;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f73d4;
  iVar1 = FUN_004105c0();
  in_ECX[7] = iVar1;
  *(undefined1 *)(iVar1 + 0x45) = 1;
  *(undefined4 *)(in_ECX[7] + 4) = in_ECX[7];
  *(undefined4 *)in_ECX[7] = in_ECX[7];
  *(undefined4 *)(in_ECX[7] + 8) = in_ECX[7];
  in_ECX[8] = 0;
  local_80 = DAT_0099d0dc;
  local_84 = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[1] = 0xffffffff;
  in_ECX[4] = 0;
  in_ECX[5] = local_80;
  local_4._0_1_ = 1;
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401740(s__DEV_DUMMYMON__Monster_Index__009f6fec,0x1d);
  local_4._0_1_ = 2;
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  FUN_00401740(s_dummymon_009f700c,8);
  local_4._0_1_ = 3;
  uVar2 = FUN_00410890(local_7c,local_60);
  local_4._0_1_ = 4;
  FUN_00411200(&local_84,uVar2);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_00;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_01;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_02;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401740(s__DEV_DUMMYNPC__NPC_Index__009f7018,0x19);
  local_4._0_1_ = 5;
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  FUN_00401740(s_dummynpc_009f7034,8);
  local_4._0_1_ = 6;
  uVar2 = FUN_00410890(local_7c,local_60);
  local_4._0_1_ = 7;
  FUN_00411200(&local_84,uVar2);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_03;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_04;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_05;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_06;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401740(s__DEV_DUMMYSRV__Servant_Index__009f7040,0x1d);
  local_4._0_1_ = 8;
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  FUN_00401740(s_dummysrv_009f7060,8);
  local_4._0_1_ = 9;
  uVar2 = FUN_00410890(local_7c,local_60);
  local_4._0_1_ = 10;
  FUN_00411200(&local_84,uVar2);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_07;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_08;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_09;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_10;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401740(s__DEV_OPENCONSOLE_009f706c,0x10);
  local_4._0_1_ = 0xb;
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  FUN_00401740(s_openconsole_009f7080,0xb);
  local_4._0_1_ = 0xc;
  uVar2 = FUN_00410890(local_7c,local_60);
  local_4._0_1_ = 0xd;
  FUN_00411200(&local_84,uVar2);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_11;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_12;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_13;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_14;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401740(s__DEV_MOVEMAP__MAPINDEX___X___Y__009f708c,0x1f);
  local_4._0_1_ = 0xe;
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  FUN_00401740(s_movemap_009f70ac,7);
  local_4._0_1_ = 0xf;
  uVar2 = FUN_00410890(local_7c,local_60);
  local_4._0_1_ = 0x10;
  FUN_00411200(&local_84,uVar2);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_15;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_16;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_17;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_18;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401740(s__DEV_guildwarstart__time__009f70b4,0x19);
  local_4._0_1_ = 0x11;
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  FUN_00401740(s_guildwarstart_009f70d0,0xd);
  local_4._0_1_ = 0x12;
  uVar2 = FUN_00410890(local_7c,local_60);
  local_4._0_1_ = 0x13;
  FUN_00411200(&local_84,uVar2);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_19;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_20;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_21;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_22;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401740(s__DEV_guildwarend__time__009f70e0,0x17);
  local_4._0_1_ = 0x14;
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  FUN_00401740(s_guildwarend_009f70f8,0xb);
  local_4._0_1_ = 0x15;
  uVar2 = FUN_00410890(local_7c,local_60);
  local_4._0_1_ = 0x16;
  FUN_00411200(&local_84,uVar2);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_23;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_24;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_25;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_26;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401740(s__DEV_open_teleport_009f7104,0x12);
  local_4._0_1_ = 0x17;
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  FUN_00401740(s_open_teleport_009f7118,0xd);
  local_4._0_1_ = 0x18;
  uVar2 = FUN_00410890(local_7c,local_60);
  local_4._0_1_ = 0x19;
  FUN_00411200(&local_84,uVar2);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_27;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_28;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_29;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_30;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  FUN_00401740(s__DEV_close_teleport_009f7128,0x13);
  local_4._0_1_ = 0x1a;
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  FUN_00401740(s_close_teleport_009f713c,0xe);
  local_4._0_1_ = 0x1b;
  uVar2 = FUN_00410890(local_7c,local_60);
  local_4._0_1_ = 0x1c;
  FUN_00411200(&local_84,uVar2);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_31;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_32;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_33;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_34;
  }
  FUN_00401830(s__DEV_resetcooltime_009f714c);
  local_4._0_1_ = 0x1d;
  FUN_00401830(s_resetcooltime_009f7160);
  local_4._0_1_ = 0x1e;
  uVar2 = FUN_00410890(local_60,local_7c);
  local_4._0_1_ = 0x1f;
  FUN_00411200(&local_84,uVar2);
  FUN_0040a7d0();
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_35;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_36;
  }
  FUN_00401830(s__DEV_partywarstart__time__009f7170);
  local_4._0_1_ = 0x20;
  FUN_00401830(s_partywarstart_009f718c);
  local_4._0_1_ = 0x21;
  uVar2 = FUN_00410890(local_60,local_7c);
  local_4._0_1_ = 0x22;
  FUN_00411200(&local_84,uVar2);
  FUN_0040a7d0();
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_37;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_38;
  }
  FUN_00401830(s__DEV_partywarend_009f719c);
  local_4._0_1_ = 0x23;
  FUN_00401830(s_partywarend_009f71b0);
  local_4._0_1_ = 0x24;
  uVar2 = FUN_00410890(local_60,local_7c);
  local_4._0_1_ = 0x25;
  FUN_00411200(&local_84,uVar2);
  FUN_0040a7d0();
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_39;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_40;
  }
  FUN_00401830(s__DEV_createbrick__BrickID__009f71bc);
  local_4._0_1_ = 0x26;
  FUN_00401830(s_createbrick_009f71d8);
  local_4._0_1_ = 0x27;
  uVar2 = FUN_00410890(local_60,local_7c);
  local_4._0_1_ = 0x28;
  FUN_00411200(&local_84,uVar2);
  FUN_0040a7d0();
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_41;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  local_4._0_1_ = 1;
  if (0xf < local_64) {
    _free(local_78);
    return extraout_EAX_42;
  }
  FUN_00401830(s__DEV_destroybrick__BrickID__009f71e4);
  local_4._0_1_ = 0x29;
  FUN_00401830(s_destroybrick_009f7200);
  local_4._0_1_ = 0x2a;
  uVar2 = FUN_00410890(local_60,local_7c);
  local_4 = CONCAT31(local_4._1_3_,0x2b);
  FUN_00411200(&local_84,uVar2);
  FUN_0040a7d0();
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_43;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  if (local_64 < 0x10) {
    ExceptionList = local_c;
    return in_ECX;
  }
  _free(local_78);
  return extraout_EAX_44;
}


// ==== FUN_00783630 @ 0x00783630 ====

void FUN_00783630(byte param_1)

{
  void *in_ECX;
  
  FUN_00782940();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00783650 @ 0x00783650 ====

void FUN_00783650(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7a04;
  return;
}


// ==== FUN_00783670 @ 0x00783670 ====

void FUN_00783670(void)

{
  undefined1 auStack_74 [4];
  undefined1 uStack_70;
  undefined4 uStack_60;
  undefined1 auStack_54 [8];
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009978a8;
  pvStack_c = ExceptionList;
  uStack_34 = (void *)0x280013;
  uStack_38 = 0;
  uStack_3c = 0x78369d;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x7836ba;
  FUN_00401660();
  puStack_4 = auStack_74;
  uStack_60 = 0;
  pvStack_c = (void *)0x0;
  uStack_70 = 0;
  FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
  FUN_00404230(auStack_54);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  if (uStack_38 < 0x10) {
    ExceptionList = uStack_34;
    return;
  }
  uStack_60 = 0x78371a;
  _free(pvStack_4c);
  return;
}


// ==== FUN_00783730 @ 0x00783730 ====

/* WARNING: Removing unreachable block (ram,0x00783813) */

undefined4 FUN_00783730(int param_1)

{
  undefined3 uVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined1 auStack_50 [4];
  undefined1 uStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  puStack_8 = &LAB_009978ba;
  local_c = ExceptionList;
  uVar1 = (undefined3)((uint)param_1 >> 8);
  local_4 = (undefined1 *)0x0;
  if (*(char *)(param_1 + 0x10) == '\0') {
    uStack_34 = 0;
    uStack_38 = 0x78377b;
    ExceptionList = &local_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x783788;
    FUN_00401660();
    local_4 = auStack_50;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = 0;
    FUN_00401660(auStack_50 + 0x20,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uVar1 = extraout_var;
  }
  else if (*(char *)(param_1 + 0x10) == '\x01') {
    uStack_34 = 0;
    uStack_38 = 0x7837cf;
    ExceptionList = &local_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x7837dc;
    FUN_00401660();
    local_4 = auStack_50;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = 0;
    FUN_00401660(auStack_50 + 0x20,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uVar1 = extraout_var_00;
  }
  ExceptionList = local_c;
  return CONCAT31(uVar1,1);
}


// ==== FUN_00783840 @ 0x00783840 ====

/* WARNING: Removing unreachable block (ram,0x00783923) */

undefined4 FUN_00783840(int param_1)

{
  undefined3 uVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined1 auStack_50 [4];
  undefined1 uStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  puStack_8 = &LAB_009978cc;
  local_c = ExceptionList;
  uVar1 = (undefined3)((uint)param_1 >> 8);
  local_4 = (undefined1 *)0x0;
  if (*(char *)(param_1 + 0x10) == '\0') {
    uStack_34 = 0;
    uStack_38 = 0x78388b;
    ExceptionList = &local_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x783898;
    FUN_00401660();
    local_4 = auStack_50;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = 0;
    FUN_00401660(auStack_50 + 0x20,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uVar1 = extraout_var;
  }
  else if (*(char *)(param_1 + 0x10) == '\x01') {
    uStack_34 = 0;
    uStack_38 = 0x7838df;
    ExceptionList = &local_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x7838ec;
    FUN_00401660();
    local_4 = auStack_50;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = 0;
    FUN_00401660(auStack_50 + 0x20,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uVar1 = extraout_var_00;
  }
  ExceptionList = local_c;
  return CONCAT31(uVar1,1);
}


// ==== FUN_00783950 @ 0x00783950 ====

void FUN_00783950(int param_1)

{
  undefined1 auStack_50 [4];
  void *pvStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  void *pvStack_34;
  undefined4 uStack_30;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  puStack_8 = &LAB_009978de;
  pvStack_c = ExceptionList;
  local_4 = (undefined1 *)0x0;
  if (*(char *)(param_1 + 0x10) == '\0') {
    uStack_30 = 0x280012;
    pvStack_34 = (void *)0x0;
    uStack_38 = 0x7839e3;
    ExceptionList = &pvStack_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x7839f0;
    FUN_00401660();
    local_4 = auStack_50;
    uStack_38 = 0xf;
    uStack_3c = 0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    FUN_00401660(&uStack_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  else {
    uStack_30 = 0x280010;
    pvStack_34 = (void *)0x0;
    uStack_38 = 0x783999;
    ExceptionList = &pvStack_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x7839a6;
    FUN_00401660();
    local_4 = auStack_50;
    uStack_38 = 0xf;
    uStack_3c = 0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    FUN_00401660(&uStack_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  if (uStack_38 < 0x10) {
    ExceptionList = pvStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_00783a50 @ 0x00783a50 ====

void FUN_00783a50(void)

{
  undefined1 auStack_20 [28];
  
  FUN_00401740(s__d____d_009f7418,7);
  FUN_00404230(auStack_20);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  return;
}


// ==== FUN_00783ab0 @ 0x00783ab0 ====

void FUN_00783ab0(void)

{
  undefined1 auStack_20 [4];
  undefined1 local_1c;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 *local_4;
  
  local_4 = auStack_20;
  local_8 = 0xf;
  local_c = 0;
  local_1c = 0;
  FUN_00401740(s_Reset_MaxPC_OK_009f7420,0xe);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00783af0 @ 0x00783af0 ====

void FUN_00783af0(void)

{
  undefined1 auStack_20 [4];
  undefined1 local_1c;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 *local_4;
  
  local_4 = auStack_20;
  local_8 = 0xf;
  local_c = 0;
  local_1c = 0;
  FUN_00401740(s_Reset_Exp_Ratio_OK_009f7430,0x12);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00783b30 @ 0x00783b30 ====

/* WARNING: Removing unreachable block (ram,0x00783bc9) */

void FUN_00783b30(int param_1)

{
  void *local_44 [5];
  uint uStack_30;
  void *pvStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009978f8;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x18) == '\0') {
    ExceptionList = &pvStack_c;
    FUN_00401740();
    FUN_00404230();
    local_4 = 1;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (0xf < uStack_30) {
      _free(local_44[0]);
      return;
    }
  }
  else {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_OK_Old__f__New__f__009f7444,0x12);
    FUN_00404230(local_44);
    local_4 = 0;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
  }
  ExceptionList = pvStack_2c;
  return;
}


// ==== FUN_00783c60 @ 0x00783c60 ====

/* WARNING: Removing unreachable block (ram,0x00783cf9) */

void FUN_00783c60(int param_1)

{
  void *local_44 [5];
  uint uStack_30;
  void *pvStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997912;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x18) == '\0') {
    ExceptionList = &pvStack_c;
    FUN_00401740();
    FUN_00404230();
    local_4 = 1;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (0xf < uStack_30) {
      _free(local_44[0]);
      return;
    }
  }
  else {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_OK_Old__f__New__f__009f7460,0x12);
    FUN_00404230(local_44);
    local_4 = 0;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
  }
  ExceptionList = pvStack_2c;
  return;
}


// ==== FUN_00783d90 @ 0x00783d90 ====

void FUN_00783d90(int param_1)

{
  undefined4 *puVar1;
  uint unaff_ESI;
  void *pvStack_60;
  void *local_44 [5];
  uint uStack_30;
  void *pvStack_2c;
  undefined1 local_28 [28];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099792c;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_MapMove_Succeeded_009f747c,0x11);
    FUN_00404230(local_44);
    local_4 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009b64f0;
      *(undefined2 *)(puVar1 + 1) = 0;
      *(undefined2 *)((int)puVar1 + 6) = 0;
      *(undefined2 *)(puVar1 + 2) = 0;
      *(undefined1 *)((int)puVar1 + 10) = 1;
    }
    puVar1[1] = *(undefined4 *)(param_1 + 0x12);
    *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_1 + 0x16);
    *(undefined1 *)((int)puVar1 + 10) = 1;
    FUN_00797a20(puVar1);
    if (unaff_ESI < 0x10) {
      ExceptionList = pvStack_2c;
      return;
    }
  }
  else {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_MapMove_Failed_009f7490,0xe);
    FUN_00404230(local_28);
    local_4 = 1;
    FUN_00401660(local_28,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (uStack_30 < 0x10) {
      ExceptionList = pvStack_2c;
      return;
    }
    pvStack_60 = local_44[0];
  }
  _free(pvStack_60);
  return;
}


// ==== FUN_00783ee0 @ 0x00783ee0 ====

/* WARNING: Removing unreachable block (ram,0x00783f6b) */

void FUN_00783ee0(int param_1)

{
  void *local_44 [5];
  uint uStack_30;
  void *pvStack_2c;
  undefined1 local_28 [28];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997946;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_Reset_Monster_Succeeded_009f74a0,0x17);
    FUN_00404230(local_44);
    local_4 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  else {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_Reset_Monster_Failed_009f74b8,0x14);
    FUN_00404230(local_28);
    local_4 = 1;
    FUN_00401660(local_28,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_30) {
      _free(local_44[0]);
      return;
    }
  }
  ExceptionList = pvStack_2c;
  return;
}


// ==== FUN_00783ff0 @ 0x00783ff0 ====

/* WARNING: Removing unreachable block (ram,0x0078407b) */

void FUN_00783ff0(int param_1)

{
  void *local_44 [5];
  uint uStack_30;
  void *pvStack_2c;
  undefined1 local_28 [28];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997960;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_Call_User_Succeeded_009f74d0,0x13);
    FUN_00404230(local_44);
    local_4 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  else {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_Call_User_Fail_FindFail__009f74e4,0x18);
    FUN_00404230(local_28);
    local_4 = 1;
    FUN_00401660(local_28,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_30) {
      _free(local_44[0]);
      return;
    }
  }
  ExceptionList = pvStack_2c;
  return;
}


// ==== FUN_00784100 @ 0x00784100 ====

void FUN_00784100(int param_1)

{
  uint unaff_ESI;
  void *pvStack_60;
  void *local_44 [5];
  uint uStack_30;
  void *pvStack_2c;
  undefined1 local_28 [28];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997982;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_Revive_User_Succeeded_009f7500,0x15);
    FUN_00404230(local_44);
    local_4 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (unaff_ESI < 0x10) {
      ExceptionList = pvStack_2c;
      return;
    }
  }
  else if (*(char *)(param_1 + 0x10) == '\x02') {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_Revive_User_Fail_NotDead__009f7518,0x19);
    FUN_00404230(local_44);
    local_4 = 1;
    FUN_00401660(local_44,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (unaff_ESI < 0x10) {
      ExceptionList = pvStack_2c;
      return;
    }
  }
  else {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_Revive_User_Fail_FindFail__009f7534,0x1a);
    FUN_00404230(local_28);
    local_4 = 2;
    FUN_00401660(local_28,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (uStack_30 < 0x10) {
      ExceptionList = pvStack_2c;
      return;
    }
    pvStack_60 = local_44[0];
  }
  _free(pvStack_60);
  return;
}


// ==== FUN_00784270 @ 0x00784270 ====

void FUN_00784270(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\0') {
    FUN_00401740(s_Heal_User_Succeeded_009f7550,0x13);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  if (cVar1 == '\x01') {
    FUN_00401740(s_Can_not_find_user_for_Healing_009f7564,0x1d);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  if (cVar1 == '\x02') {
    pcVar2 = s_Can_not_find_guild_for_Healing_009f7584;
  }
  else {
    if (cVar1 == '\x03') {
      FUN_00401830(s_Invalid_map_index_for_Healing_009f75a4);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      return;
    }
    pcVar2 = s_Heal_User_Failed_009f75c4;
  }
  FUN_00401830(pcVar2);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00784320 @ 0x00784320 ====

/* WARNING: Removing unreachable block (ram,0x007843ae) */

void FUN_00784320(void)

{
  void *unaff_EBX;
  undefined1 local_28 [28];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997994;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_actors___d__other_stuffs___d_009f75d8,0x1c);
  FUN_00404230(local_28);
  local_4 = 0;
  FUN_00401660(local_28);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  ExceptionList = unaff_EBX;
  return;
}


// ==== FUN_007843d0 @ 0x007843d0 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_007843d0(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  uint unaff_EBX;
  undefined4 *puVar5;
  undefined1 auStack_1054 [4];
  uint uStack_1050;
  undefined4 uStack_104c;
  int iStack_1048;
  void *pvStack_1044;
  uint uStack_1040;
  uint uStack_103c;
  undefined1 *apuStack_1028 [7];
  undefined4 uStack_100c;
  void *pvStack_38;
  void *pvStack_34;
  undefined4 uStack_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009979a9;
  pvStack_14 = ExceptionList;
  uStack_1c = 0x7843f6;
  cVar1 = *(char *)(param_1 + 0x16);
  if (cVar1 == '\0') {
    uStack_103c = (uint)*(ushort *)(param_1 + 0x10);
    uStack_1040 = 0x784417;
    ExceptionList = &pvStack_14;
    piVar2 = (int *)(**(code **)(*DAT_00b5ab14 + 8))();
    uStack_1040 = 0x78441e;
    puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
    uStack_1040 = (uint)*(ushort *)(param_1 + 0x14);
    puVar5 = &uStack_100c;
    for (iVar4 = 0x3fb; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    pvStack_1044 = (void *)(uint)*(ushort *)(param_1 + 0x12);
    iStack_1048 = (int)&uStack_100c + 2;
    uStack_104c = 0xf;
    uStack_1050 = 0;
    FUN_00401740(s_Location___s__x___d_y___d_009f75f8,0x19);
    FUN_00404230(apuStack_1028);
    uStack_1040 = 0xf;
    pvStack_1044 = (void *)0x0;
    puStack_10 = (undefined1 *)0x0;
    auStack_1054[0] = 0;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (0xf < unaff_EBX) {
      _free(pvStack_1044);
      return;
    }
  }
  else {
    apuStack_1028[0] = auStack_1054;
    if (cVar1 == '\x01') {
      uStack_103c = 0xf;
      uStack_1040 = 0;
      uStack_1050 = uStack_1050 & 0xffffff00;
      ExceptionList = &pvStack_14;
      apuStack_1028[0] = auStack_1054;
      FUN_00401740();
    }
    else {
      if (cVar1 == '\x02') {
        ExceptionList = &pvStack_14;
        apuStack_1028[0] = auStack_1054;
        FUN_00401830();
        (**(code **)(*DAT_00b5ad0c + 0x28))();
        ExceptionList = pvStack_34;
        return;
      }
      ExceptionList = &pvStack_14;
      FUN_00401830();
    }
    (**(code **)(*DAT_00b5ad0c + 0x28))();
  }
  ExceptionList = pvStack_38;
  return;
}


// ==== FUN_007844cd @ 0x007844cd ====

void FUN_007844cd(void)

{
  char in_AL;
  undefined1 *puStack00000010;
  void *in_stack_00001004;
  undefined1 auStack_1c [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  puStack00000010 = auStack_1c;
  if (in_AL == '\x01') {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    puStack00000010 = auStack_1c;
    FUN_00401740(s_Can_not_find_user_for_chase_009f7614,0x1b);
  }
  else {
    if (in_AL == '\x02') {
      puStack00000010 = auStack_1c;
      FUN_00401830(s_Can_not_find_map_for_chase_009f7630);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      ExceptionList = in_stack_00001004;
      return;
    }
    FUN_00401830(s_Find_User_Failed_009f764c);
  }
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  ExceptionList = in_stack_00001004;
  return;
}


// ==== FUN_00784560 @ 0x00784560 ====

void FUN_00784560(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_00401740(s_Kick_Succeeded____009f7660,0x11);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_Kick_Failed___009f7674,0xd);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_007845c0 @ 0x007845c0 ====

void FUN_007845c0(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\0') {
    FUN_00401740(s_UserReturn_Succeeded_009f7684,0x14);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  if (cVar1 == '\x01') {
    FUN_00401740(s_Can_not_find_user_for_return_009f769c,0x1c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  if (cVar1 == '\x02') {
    pcVar2 = s_Can_not_find_guild_for_return_009f76bc;
  }
  else {
    if (cVar1 == '\x03') {
      FUN_00401830(s_Invalid_map_index_for_return_009f76dc);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      return;
    }
    pcVar2 = s_return_failed_009f76fc;
  }
  FUN_00401830(pcVar2);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00784670 @ 0x00784670 ====

void FUN_00784670(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_00401740(s_Reset_Siege_Succeeded_009f770c,0x15);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_Reset_Siege_Failed_009f7724,0x12);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_007846d0 @ 0x007846d0 ====

void FUN_007846d0(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_00401740(s_Stop_Siege_Succeeded_009f7738,0x14);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_Stop_Siege_Failed_009f7750,0x11);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00784730 @ 0x00784730 ====

void FUN_00784730(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    uVar2 = 0x15;
    pcVar1 = s_Siege_Start_Succeeded_009f7764;
  }
  else {
    if (*(char *)(param_1 + 0x10) == '\x01') {
      FUN_00401740(s_Siege_Already_Started_009f777c,0x15);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      return;
    }
    uVar2 = 0x12;
    pcVar1 = s_Siege_Start_Failed_009f7794;
  }
  FUN_00401740(pcVar1,uVar2);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_007847b0 @ 0x007847b0 ====

void FUN_007847b0(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    uVar2 = 0x13;
    pcVar1 = s_Siege_End_Succeeded_009f77a8;
  }
  else {
    if (*(char *)(param_1 + 0x10) == '\x01') {
      FUN_00401740(s_Siege_did_not_started_009f77bc,0x15);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      return;
    }
    uVar2 = 0x10;
    pcVar1 = s_Siege_End_Failed_009f77d4;
  }
  FUN_00401740(pcVar1,uVar2);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00784830 @ 0x00784830 ====

void FUN_00784830(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (*(char *)(param_1 + 0x11) == '\0') {
      FUN_00401740(s_Open_GuildWar_Teleport_Command_i_009f7814,0x38);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      return;
    }
    uVar2 = 0x29;
    pcVar1 = s_Open_GuildWar_Teleport_Command_i_009f77e8;
  }
  else {
    uVar2 = 0x26;
    pcVar1 = s_Open_GuildWar_Teleport_Command_i_009f7850;
  }
  FUN_00401740(pcVar1,uVar2);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_007848b0 @ 0x007848b0 ====

void FUN_007848b0(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (*(char *)(param_1 + 0x11) != '\0') {
      FUN_00401740(s_Close_GuildWar_Teleport_Command_i_009f7890,0x3a);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      return;
    }
    uVar2 = 0x17;
    pcVar1 = s_Close_GuildWar_Teleport_009f7878;
  }
  else {
    uVar2 = 0x27;
    pcVar1 = s_Close_GuildWar_Teleport_Command_i_009f78cc;
  }
  FUN_00401740(pcVar1,uVar2);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00784930 @ 0x00784930 ====

void FUN_00784930(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_00401740(s_ResetCoolTime_Command_is_Success_009f78f4,0x20);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_Close_GuildWar_Teleport_Command_i_009f7918,0x27);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00784990 @ 0x00784990 ====

void FUN_00784990(int param_1)

{
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_00401740(s_PartyWar_Start_Succeeded_009f7940,0x18);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_PartyWar_Start_Failed_009f795c,0x15);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_007849f0 @ 0x007849f0 ====

void FUN_007849f0(undefined1 *param_1)

{
  undefined1 auStack_20 [4];
  undefined1 uStack_1c;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 *puStack_8;
  
  if (*(int *)((int)param_1 + 0x10) == 0) {
    puStack_8 = &param_1;
    param_1 = (undefined1 *)0x1;
    uStack_c = 0x784a14;
    (**(code **)(*DAT_00b5ada4 + 8))();
    uStack_c = 0xf;
    uStack_10 = 0;
    auStack_20[0] = 0;
    FUN_00401740(s_PartyWar_End_Succeeded_009f7974,0x16);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  param_1 = auStack_20;
  puStack_8 = (undefined4 *)0xf;
  uStack_c = 0;
  uStack_1c = 0;
  FUN_00401740(s_PartyWar_End_Failed_009f798c);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  return;
}


// ==== FUN_00784a47 @ 0x00784a47 ====

void FUN_00784a47(void)

{
  undefined1 *puStack00000008;
  undefined1 auStack_1c [20];
  
  puStack00000008 = auStack_1c;
  FUN_00401740(s_PartyWar_End_Failed_009f798c,0x13);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00784a80 @ 0x00784a80 ====

void FUN_00784a80(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_00401740(s_Create_Brick_Succeeded_009f79a0,0x16);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_Create_Brick_Failed_009f79b8,0x13);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00784ae0 @ 0x00784ae0 ====

void FUN_00784ae0(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_00401740(s_Destroy_Brick_Succeeded_009f79cc,0x17);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_Destroy_Brick_Failed_009f79e4,0x14);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00784b40 @ 0x00784b40 ====

undefined4 FUN_00784b40(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  
  uVar2 = FUN_00424500();
  switch(uVar2) {
  case 0x7000004:
    cVar1 = FUN_00783730(*(undefined4 *)(param_1 + 0xc));
    if (cVar1 != '\0') {
      return 1;
    }
    break;
  case 0x7000006:
    cVar1 = FUN_00783840(*(undefined4 *)(param_1 + 0xc));
    if (cVar1 != '\0') {
      return 1;
    }
    break;
  case 0x7000010:
    FUN_00783950(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000012:
    FUN_00783a50(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000014:
    FUN_00783670(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000016:
    FUN_00783ab0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000018:
    FUN_00784560(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x700001c:
    FUN_00783af0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x700001f:
    FUN_00783b30(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000021:
    FUN_00783c60(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000023:
    FUN_00783ee0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000025:
    FUN_00783d90(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000027:
    FUN_00783ff0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000029:
    FUN_00784100(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x700002b:
    FUN_00784270(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x700002d:
    FUN_007843d0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x700002f:
    FUN_00784320(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000031:
    FUN_007845c0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000033:
    FUN_00784730(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000035:
    FUN_007847b0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000037:
    FUN_007846d0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000039:
    FUN_00784670(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000041:
    FUN_00784830(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000043:
    FUN_007848b0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000045:
    FUN_00784930(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x7000048:
    FUN_00784990(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x700004a:
    FUN_007849f0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x700004c:
    FUN_00784a80(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0x700004e:
    FUN_00784ae0(*(undefined4 *)(param_1 + 0xc));
  }
  return 0;
}


// ==== FUN_00784e50 @ 0x00784e50 ====

undefined4 FUN_00784e50(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00784b40(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00784e80 @ 0x00784e80 ====

void FUN_00784e80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7a04;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00784ea0 @ 0x00784ea0 ====

void FUN_00784ea0(void)

{
  return;
}


// ==== FUN_00784eb0 @ 0x00784eb0 ====

void FUN_00784eb0(void)

{
  return;
}


// ==== FUN_00784ec0 @ 0x00784ec0 ====

void FUN_00784ec0(void)

{
  return;
}


// ==== FUN_00784ed0 @ 0x00784ed0 ====

undefined * FUN_00784ed0(undefined4 param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)0x0;
  switch(param_1) {
  case 2:
    return (undefined *)0x820008;
  case 3:
  case 7:
    return (undefined *)0x820006;
  case 4:
    return (undefined *)0x820003;
  case 5:
    return (undefined *)0x820005;
  case 6:
    FUN_006f8c40();
    return (undefined *)0x820004;
  case 8:
    return (undefined *)0x820009;
  case 9:
    return &DAT_0082000a;
  case 10:
    return (undefined *)0x820010;
  case 0xb:
    puVar1 = &DAT_0082000c;
  }
  return puVar1;
}


// ==== FUN_00784f60 @ 0x00784f60 ====

void FUN_00784f60(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009f7a7c;
  *(undefined1 *)(in_ECX + 2) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b1a0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b1a0 = in_ECX;
  return;
}


// ==== FUN_00784f90 @ 0x00784f90 ====

void FUN_00784f90(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b1a0 = 0;
  *in_ECX = &PTR_FUN_009e782c;
  return;
}


// ==== FUN_00784fb0 @ 0x00784fb0 ====

void FUN_00784fb0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = FUN_00404900();
  if (cVar1 == '\x01') {
    (**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
    return;
  }
  FUN_00401660(param_1,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00784fdd @ 0x00784fdd ====

void FUN_00784fdd(void)

{
  undefined4 unaff_ESI;
  undefined1 *puStack0000000c;
  undefined1 auStack_1c [4];
  undefined1 local_18;
  undefined4 local_8;
  undefined4 local_4;
  
  puStack0000000c = auStack_1c;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401660(unaff_ESI,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00785010 @ 0x00785010 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00785010(float *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  float *pfVar5;
  ushort *puVar6;
  undefined4 *puVar7;
  int in_ECX;
  float fVar8;
  float fVar9;
  uint *puVar10;
  undefined4 uStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  undefined4 uStack_6c;
  uint uStack_68;
  uint uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined2 auStack_50 [2];
  undefined4 auStack_4c [2];
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009979e0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(float *)(in_ECX + 0x14) = *param_1;
  *(float *)(in_ECX + 0x18) = param_1[1];
  *(float *)(in_ECX + 0x1c) = param_1[2];
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  iVar3 = (**(code **)(*piVar2 + 0x40))();
  if (iVar3 != 1) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    iVar3 = (**(code **)(*piVar2 + 0x40))();
    if (iVar3 != 0x16) {
      piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      iVar3 = (**(code **)(*piVar2 + 0x40))();
      if (iVar3 != 0x15) {
        piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
        iVar3 = (**(code **)(*piVar2 + 0x40))();
        if (iVar3 != 0x17) {
          uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(5,0x820009);
          FUN_00765c50(uVar4);
          pvStack_c = (void *)0x3;
          FUN_00784fb0(&uStack_30);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
    }
  }
  if (*(char *)(in_ECX + 8) != '\x01') {
    piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    if (piVar2 != (int *)0x0) {
      pfVar5 = (float *)(**(code **)(*piVar2 + 0x28))();
      fStack_74 = *pfVar5;
      fStack_78 = param_1[2];
      fStack_70 = pfVar5[1];
      *(float *)(in_ECX + 0xc) = *param_1;
      *(float *)(in_ECX + 0x10) = fStack_78;
      fVar9 = *(float *)(in_ECX + 0xc) - fStack_74;
      fVar8 = *(float *)(in_ECX + 0x10) - fStack_70;
      uStack_7c = fVar9 * fVar9 + fVar8 * fVar8;
      if (SQRT(uStack_7c) <= _DAT_009f7a44) {
        fStack_70 = (float)(int)*(float *)(in_ECX + 0x10);
        fStack_74 = (float)(int)*(float *)(in_ECX + 0xc);
        pfVar5 = &fStack_74;
        (**(code **)(*DAT_00b5afb4 + 0x10))(pfVar5);
        cVar1 = FUN_005925b0(pfVar5);
        if (cVar1 == '\0') {
          uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(5,0x820004);
          FUN_00765c50(uVar4);
          pvStack_c = (void *)0x1;
          FUN_00784fb0(auStack_4c);
          FUN_006f8c40();
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        uStack_6c = 0;
        fStack_74 = *param_1;
        fStack_70 = param_1[2];
        puVar6 = (ushort *)FUN_0060ecb0(&uStack_7c);
        uStack_68 = (uint)*puVar6;
        iVar3 = FUN_0060ecb0(&uStack_7c);
        uStack_64 = (uint)*(ushort *)(iVar3 + 2);
        puVar10 = &uStack_68;
        (**(code **)(*DAT_00b5afb4 + 0x10))(puVar10);
        uVar4 = FUN_005925d0(puVar10);
        uStack_58 = 0;
        uStack_60 = *(undefined4 *)(in_ECX + 0xc);
        uStack_5c = *(undefined4 *)(in_ECX + 0x10);
        uVar4 = (**(code **)(*DAT_00b5ab10 + 8))(uVar4);
        auStack_4c[0] = (**(code **)(*DAT_00b5a6ac + 0x20))();
        puVar7 = (undefined4 *)FUN_004ef0e0(auStack_50 + -0x18);
        uStack_54 = *puVar7;
        auStack_50[0] = *(undefined2 *)(puVar7 + 1);
        uStack_58 = (**(code **)(*DAT_00b5a980 + 8))();
        uVar4 = (**(code **)(*DAT_00b5a980 + 8))(uVar4,&uStack_58);
        iVar3 = FUN_0082a4a0(uVar4);
        if (iVar3 != 1) {
          iVar3 = FUN_00784ed0(iVar3);
          if (iVar3 != 0) {
            uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(5,iVar3);
            FUN_00765c50(uVar4);
            uStack_10 = 2;
            FUN_00784fb0(auStack_50);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
        }
        uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        iVar3 = FUN_00785600(uVar4);
        puVar7 = (undefined4 *)FUN_004ef0e0(&uStack_7c);
        *(undefined4 *)(iVar3 + 0x10) = *puVar7;
        *(undefined2 *)(iVar3 + 0x14) = *(undefined2 *)(puVar7 + 1);
        FUN_004d8570(iVar3);
        *(undefined1 *)(in_ECX + 8) = 1;
      }
      else {
        uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(5,0x820005);
        uStack_2c = 0xf;
        uStack_30 = 0;
        pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
        FUN_00401660(uVar4,0,0xffffffff);
        uStack_4 = 0;
        FUN_00784fb0(auStack_44);
        if (0xf < uStack_2c) {
          _free(pvStack_40);
          return;
        }
      }
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00785450 @ 0x00785450 ====

void FUN_00785450(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined2 extraout_var;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009979f2;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)(in_ECX + 8) = 0;
  if (*(char *)(param_1 + 0x16) == '\x01') {
    FUN_006f86c0(DAT_00b5b13c);
    FUN_006f87a0(in_ECX + 0xc);
    FUN_00794c70(*(undefined4 *)(param_1 + 0x10),
                 CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x14)));
    FUN_004de2a0(0,1000);
    ExceptionList = pvStack_10;
    return;
  }
  iVar1 = FUN_00784ed0(*(char *)(param_1 + 0x16));
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(5,iVar1);
    pvStack_10 = (void *)0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401660(uVar2,0,0xffffffff);
    uStack_4 = 0;
    FUN_00784fb0(auStack_28);
    if (0xf < pvStack_10) {
      _free(pvStack_24);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00785550 @ 0x00785550 ====

void FUN_00785550(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = 0;
  FUN_00785010(in_ECX + 0x14);
  return;
}


// ==== FUN_00785590 @ 0x00785590 ====

undefined4 FUN_00785590(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x10001) {
    if ((param_1[2] == 1) && (param_1[3] == 2)) {
      FUN_00785010(param_1 + 9);
      return 1;
    }
  }
  else if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x5210001) {
      FUN_00785450(param_1[3]);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00785600 @ 0x00785600 ====

void FUN_00785600(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5210000;
  *(undefined2 *)((int)pvVar1 + 6) = 0x18;
  FUN_004244d0();
  return;
}


// ==== FUN_00785630 @ 0x00785630 ====

void FUN_00785630(byte param_1)

{
  void *in_ECX;
  
  FUN_00784f90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00785650 @ 0x00785650 ====

void FUN_00785650(undefined4 param_1)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997a37;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_00b5b1a0 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x20);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_00784f60(param_1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5b13c == 0) {
    pvVar1 = operator_new(0xc);
    local_4 = 1;
    if (pvVar1 != (void *)0x0) {
      FUN_00794c40(param_1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5b140 == 0) {
    pvVar1 = operator_new(0x24);
    local_4 = 2;
    if (pvVar1 != (void *)0x0) {
      FUN_006eed30(param_1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5b19c == 0) {
    pvVar1 = operator_new(0xc);
    local_4 = 3;
    if (pvVar1 != (void *)0x0) {
      FUN_00795150(param_1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5b198 == 0) {
    pvVar1 = operator_new(8);
    local_4 = 4;
    if (pvVar1 != (void *)0x0) {
      FUN_00794fa0(param_1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00785770 @ 0x00785770 ====

void FUN_00785770(void)

{
  if (DAT_00b5b1a0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b1a0)(1);
  }
  if (DAT_00b5b13c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b13c)(1);
  }
  if (DAT_00b5b140 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b140)(1);
  }
  if (DAT_00b5b19c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b19c)(1);
  }
  if (DAT_00b5b198 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b198)(1);
  }
  return;
}


// ==== FUN_007857d0 @ 0x007857d0 ====

void FUN_007857d0(void)

{
  return;
}


// ==== FUN_007857e0 @ 0x007857e0 ====

void FUN_007857e0(int param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (param_1 != 0) {
    uVar2 = FUN_004756e0(1,0);
    *(undefined4 *)(in_ECX + 0x1c) = uVar2;
    uVar2 = FUN_004756e0(1,1);
    *(undefined4 *)(in_ECX + 0x20) = uVar2;
    uVar1 = FUN_004756e0(1,2);
    *(undefined1 *)(in_ECX + 0x24) = uVar1;
    uVar2 = FUN_004756e0(1,3);
    *(undefined4 *)(in_ECX + 0x28) = uVar2;
    uVar1 = FUN_004756e0(1,4);
    *(undefined1 *)(in_ECX + 0x2c) = uVar1;
  }
  return;
}


// ==== FUN_00785840 @ 0x00785840 ====

int FUN_00785840(undefined1 param_1)

{
  int local_4;
  
  FUN_00786400(&local_4,&param_1);
  return local_4 + 0x10;
}


// ==== FUN_00785860 @ 0x00785860 ====

int FUN_00785860(undefined1 param_1)

{
  code *pcVar1;
  int extraout_EAX;
  int iVar2;
  int in_ECX;
  int local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997a58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00558e70(&local_2c,&param_1);
  if (local_2c != *(int *)(in_ECX + 0x14)) {
    ExceptionList = local_c;
    return local_2c + 0x10;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_itCashItem____m_mapCashItem_end__009f7b9c,0x21);
  local_4 = 0;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00785900 @ 0x00785900 ====

void FUN_00785900(int *param_1)

{
  uint *puVar1;
  char cVar2;
  ushort uVar3;
  undefined1 uVar4;
  ushort uVar5;
  uint uVar6;
  char *pcVar7;
  int in_ECX;
  char *pcVar8;
  uint *puVar9;
  uint *puVar10;
  uint auStack_68 [2];
  int iStack_60;
  undefined1 auStack_5c [4];
  uint *puStack_58;
  uint *puStack_54;
  undefined4 uStack_50;
  undefined1 auStack_4c [8];
  uint *puStack_44;
  uint *puStack_40;
  undefined4 uStack_3c;
  undefined4 auStack_38 [2];
  void *pvStack_30;
  undefined4 uStack_20;
  uint uStack_1c;
  long lStack_18;
  undefined4 uStack_14;
  undefined2 uStack_10;
  undefined1 uStack_e;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997a7a;
  local_c = ExceptionList;
  if (param_1 != (int *)0x0) {
    uVar3 = 1;
    ExceptionList = &local_c;
    uVar6 = (**(code **)(*param_1 + 8))();
    if (1 < uVar6) {
      iStack_60 = in_ECX + 4;
      do {
        puStack_58 = (uint *)0x0;
        puStack_54 = (uint *)0x0;
        uStack_50 = 0;
        uStack_4._0_1_ = 0;
        uStack_4._1_3_ = 0;
        uVar4 = FUN_004753b0(uVar3,0);
        uVar5 = FUN_00475a90(uVar3,1);
        puVar9 = (uint *)0x0;
        if (uVar5 != 0) {
          auStack_68[0] = (uint)uVar5;
          do {
            auStack_38[0] = 0;
            uStack_1c = 0xf;
            uStack_20 = 0;
            pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
            lStack_18 = 0;
            uStack_14 = 0;
            uStack_10 = 0;
            uStack_e = 0;
            uStack_4 = CONCAT31(uStack_4._1_3_,1);
            auStack_38[0] = FUN_004756e0(uVar3,2);
            pcVar7 = (char *)(**(code **)(*param_1 + 0x10))(uVar3,3);
            pcVar8 = pcVar7;
            do {
              cVar2 = *pcVar8;
              pcVar8 = pcVar8 + 1;
            } while (cVar2 != '\0');
            FUN_00401740(pcVar7,(int)pcVar8 - (int)(pcVar7 + 1));
            pcVar8 = (char *)(**(code **)(*param_1 + 0x10))(uVar3,5);
            FUN_00475260(pcVar8,uVar3,5);
            uVar6 = 0;
            do {
              if (pcVar8[uVar6] == '\0') {
                if (uVar6 != 0) {
                  _atol(pcVar8);
                }
                break;
              }
              uVar6 = uVar6 + 1;
            } while (uVar6 < 0x100);
            pcVar8 = (char *)(**(code **)(*param_1 + 0x10))(uVar3,4);
            FUN_00475260(pcVar8,uVar3,4);
            uVar6 = 0;
            do {
              if (pcVar8[uVar6] == '\0') {
                if (uVar6 == 0) {
                  lStack_18 = 0;
                }
                else {
                  lStack_18 = _atol(pcVar8);
                }
                goto LAB_00785a89;
              }
              uVar6 = uVar6 + 1;
            } while (uVar6 < 0x100);
            lStack_18 = 0;
LAB_00785a89:
            uStack_10 = FUN_00475a90(uVar3,6);
            uStack_e = FUN_004753b0(uVar3,7);
            FUN_00787110(auStack_38);
            uStack_4._0_1_ = 0;
            if (0xf < uStack_1c) {
              _free(pvStack_30);
              return;
            }
            uVar3 = uVar3 + 1;
            auStack_68[0] = auStack_68[0] - 1;
            uStack_1c = 0xf;
            uStack_20 = 0;
            pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
          } while (auStack_68[0] != 0);
          auStack_68[0] = 0;
          puVar9 = puStack_54;
        }
        auStack_4c[0] = uVar4;
        FUN_0066f030(auStack_5c);
        uStack_4 = CONCAT31(uStack_4._1_3_,2);
        FUN_00787750(auStack_68,auStack_4c);
        if (puStack_44 != (uint *)0x0) {
          if (puStack_44 != puStack_40) {
            puVar9 = puStack_44 + 7;
            do {
              if (0xf < *puVar9) {
                _free((void *)puVar9[-5]);
                return;
              }
              *puVar9 = 0xf;
              puVar9[-1] = 0;
              *(undefined1 *)(puVar9 + -5) = 0;
              puVar10 = puVar9 + 4;
              puVar9 = puVar9 + 0xb;
            } while (puVar10 != puStack_40);
          }
          _free(puStack_44);
          return;
        }
        puStack_44 = (uint *)0x0;
        puStack_40 = (uint *)0x0;
        uStack_3c = 0;
        uStack_4 = 0xffffffff;
        if (puStack_58 != (uint *)0x0) {
          if (puStack_58 != puVar9) {
            puVar10 = puStack_58 + 7;
            do {
              if (0xf < *puVar10) {
                _free((void *)puVar10[-5]);
                return;
              }
              *puVar10 = 0xf;
              puVar10[-1] = 0;
              *(undefined1 *)(puVar10 + -5) = 0;
              puVar1 = puVar10 + 4;
              puVar10 = puVar10 + 0xb;
            } while (puVar1 != puVar9);
          }
          _free(puStack_58);
          return;
        }
        puStack_58 = (uint *)0x0;
        puStack_54 = (uint *)0x0;
        uStack_50 = 0;
        uVar6 = (**(code **)(*param_1 + 8))();
      } while (uVar3 < uVar6);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00785c10 @ 0x00785c10 ====

void FUN_00785c10(int *param_1)

{
  uint *puVar1;
  char cVar2;
  int iVar3;
  ushort uVar4;
  ushort uVar5;
  uint uVar6;
  undefined4 uVar7;
  char *pcVar8;
  int in_ECX;
  char *pcVar9;
  uint *puVar10;
  uint *puVar11;
  uint uStack_6c;
  undefined4 auStack_68 [2];
  int iStack_60;
  undefined1 auStack_5c [4];
  uint *puStack_58;
  uint *puStack_54;
  undefined4 uStack_50;
  undefined4 auStack_4c [2];
  uint *puStack_44;
  uint *puStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined2 uStack_34;
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  undefined1 uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997a9c;
  local_c = ExceptionList;
  if (param_1 != (int *)0x0) {
    uVar4 = 1;
    ExceptionList = &local_c;
    uVar6 = (**(code **)(*param_1 + 8))();
    if (1 < uVar6) {
      iStack_60 = in_ECX + 0x10;
      do {
        puStack_58 = (uint *)0x0;
        puStack_54 = (uint *)0x0;
        uStack_50 = 0;
        uStack_4._0_1_ = 0;
        uStack_4._1_3_ = 0;
        auStack_68[0] = FUN_004756e0(uVar4,0);
        uVar5 = FUN_00475a90(uVar4,1);
        puVar10 = (uint *)0x0;
        if (uVar5 != 0) {
          uStack_6c = (uint)uVar5;
          do {
            uStack_14 = 0xf;
            uStack_18 = 0;
            pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
            iVar3 = *DAT_00b5ad20;
            uStack_4._0_1_ = 1;
            uVar7 = FUN_00475a90(uVar4,2);
            uStack_3c = (**(code **)(iVar3 + 0xc))(uVar7);
            uStack_38 = FUN_004756e0(uVar4,3);
            uStack_34 = FUN_00475a90(uVar4,4);
            pcVar8 = (char *)(**(code **)(*param_1 + 0x10))(uVar4,5);
            pcVar9 = pcVar8;
            do {
              cVar2 = *pcVar9;
              pcVar9 = pcVar9 + 1;
            } while (cVar2 != '\0');
            FUN_00401740(pcVar8,(int)pcVar9 - (int)(pcVar8 + 1));
            uStack_10 = FUN_004753b0(uVar4,6);
            FUN_007871a0(&uStack_38);
            uStack_4._0_1_ = 0;
            if (0xf < uStack_14) {
              _free(pvStack_28);
              return;
            }
            uVar4 = uVar4 + 1;
            uStack_6c = uStack_6c - 1;
            uStack_14 = 0xf;
            uStack_18 = 0;
            pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
          } while (uStack_6c != 0);
          puVar10 = puStack_54;
        }
        auStack_4c[0] = auStack_68[0];
        FUN_00696200(auStack_5c);
        uStack_4 = CONCAT31(uStack_4._1_3_,2);
        FUN_00787810(auStack_68,auStack_4c);
        if (puStack_44 != (uint *)0x0) {
          if (puStack_44 != puStack_40) {
            puVar10 = puStack_44 + 9;
            do {
              if (0xf < *puVar10) {
                _free((void *)puVar10[-5]);
                return;
              }
              *puVar10 = 0xf;
              puVar10[-1] = 0;
              *(undefined1 *)(puVar10 + -5) = 0;
              puVar11 = puVar10 + 2;
              puVar10 = puVar10 + 0xb;
            } while (puVar11 != puStack_40);
          }
          _free(puStack_44);
          return;
        }
        puStack_44 = (uint *)0x0;
        puStack_40 = (uint *)0x0;
        uStack_3c = 0;
        uStack_4 = 0xffffffff;
        if (puStack_58 != (uint *)0x0) {
          if (puStack_58 != puVar10) {
            puVar11 = puStack_58 + 9;
            do {
              if (0xf < *puVar11) {
                _free((void *)puVar11[-5]);
                return;
              }
              *puVar11 = 0xf;
              puVar11[-1] = 0;
              *(undefined1 *)(puVar11 + -5) = 0;
              puVar1 = puVar11 + 2;
              puVar11 = puVar11 + 0xb;
            } while (puVar1 != puVar10);
          }
          _free(puStack_58);
          return;
        }
        puStack_58 = (uint *)0x0;
        puStack_54 = (uint *)0x0;
        uStack_50 = 0;
        uVar6 = (**(code **)(*param_1 + 8))();
      } while (uVar4 < uVar6);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00785ea0 @ 0x00785ea0 ====

void FUN_00785ea0(undefined1 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  uint uVar3;
  void *unaff_EBX;
  void *unaff_retaddr;
  uint in_stack_00000014;
  int in_stack_0000001c;
  undefined1 local_234 [2];
  undefined1 auStack_232 [2];
  void *local_230;
  uint uStack_224;
  uint local_21c;
  void *local_218;
  char local_214 [256];
  undefined4 *local_114;
  undefined1 local_110;
  undefined1 local_10f;
  undefined1 local_10e;
  char local_10c [248];
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00997add;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  uVar1 = FUN_00402220(local_234,&param_1,s_Loading____009f7b6c);
  local_4._0_1_ = 1;
  FUN_00796d50(uVar1);
  local_4 = (uint)local_4._1_3_ << 8;
  if (0xf < local_21c) {
    _free(local_230);
    return;
  }
  local_218 = operator_new(0x10);
  local_4._0_1_ = 2;
  if (local_218 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_0081d3a0(&param_1);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  if (puVar2 == (undefined4 *)0x0) {
    uVar1 = FUN_00402220(local_234,&param_1,s_Loading_FAIL_009f7b78);
    local_4._0_1_ = 3;
    FUN_00796d50(uVar1);
    local_4 = (uint)local_4._1_3_ << 8;
    if (0xf < local_21c) {
      _free(local_230);
      return;
    }
  }
  local_214[0] = '\0';
  FUN_0044a580(local_10c,&DAT_009f7bc0,&DAT_009f7b88);
  uVar3 = 0;
  do {
    local_214[uVar3] = local_10c[uVar3];
    if (local_10c[uVar3] == '\0') goto LAB_00785fcd;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  local_214[0] = '\0';
LAB_00785fcd:
  local_110 = 10;
  local_10f = 0x2c;
  local_10e = 1;
  local_114 = puVar2;
  uVar1 = (**(code **)(*DAT_00b5aa34 + 8))(local_214);
  if (in_stack_0000001c == 0) {
    FUN_00785900(uVar1);
  }
  else if (in_stack_0000001c == 1) {
    FUN_00785c10(uVar1);
  }
  else if (in_stack_0000001c == 2) {
    FUN_007857e0(uVar1);
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar1);
  uVar1 = FUN_00402220(local_234 + -8,&local_4,s_Loading_OK_009f7b90);
  pvStack_c._0_1_ = 4;
  FUN_00796d50(uVar1);
  pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);
  if (0xf < uStack_224) {
    _free(unaff_EBX);
    return;
  }
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  if (in_stack_00000014 < 0x10) {
    ExceptionList = pvStack_14;
    return;
  }
  _free(unaff_retaddr);
  return;
}


// ==== FUN_007860d0 @ 0x007860d0 ====

void FUN_007860d0(void)

{
  uint *puVar1;
  char cVar2;
  int *piVar3;
  uint *puVar4;
  int *piVar5;
  undefined4 *in_ECX;
  int *piVar6;
  uint *puVar7;
  int *local_50;
  undefined4 *local_4c;
  uint *local_44;
  uint *local_40;
  undefined4 uStack_3c;
  uint local_38;
  uint local_34;
  undefined2 local_30;
  void *local_28;
  undefined4 local_18;
  uint local_14;
  undefined1 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_00997b15;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f7bcc;
  local_50 = (int *)in_ECX[5];
  piVar6 = (int *)*local_50;
  uStack_3 = 0;
  local_4c = in_ECX;
  if (piVar6 != local_50) {
    do {
      local_4 = 2;
      FUN_00696200(piVar6 + 4);
      puVar4 = local_40;
      if (local_44 != local_40) {
        puVar7 = local_44 + 2;
        do {
          local_4 = 3;
          local_38 = puVar7[-2];
          local_34 = puVar7[-1];
          local_30 = (undefined2)*puVar7;
          local_14 = 0xf;
          local_18 = 0;
          local_28 = (void *)((uint)local_28 & 0xffffff00);
          FUN_00401660(puVar7 + 1,0,0xffffffff);
          local_10 = (undefined1)puVar7[8];
          local_4 = 4;
          if (local_38 != 0) {
            (**(code **)(*DAT_00b5a730 + 0x10))(1,local_38);
          }
          local_4 = 3;
          if (0xf < local_14) {
            _free(local_28);
            return;
          }
          puVar1 = puVar7 + 9;
          local_14 = 0xf;
          local_18 = 0;
          local_28 = (void *)((uint)local_28 & 0xffffff00);
          puVar7 = puVar7 + 0xb;
        } while (puVar1 != puVar4);
      }
      local_4 = 2;
      if (local_44 != (uint *)0x0) {
        if (local_44 != puVar4) {
          puVar7 = local_44 + 9;
          do {
            if (0xf < *puVar7) {
              _free((void *)puVar7[-5]);
              return;
            }
            *puVar7 = 0xf;
            puVar7[-1] = 0;
            *(undefined1 *)(puVar7 + -5) = 0;
            puVar1 = puVar7 + 2;
            puVar7 = puVar7 + 0xb;
          } while (puVar1 != puVar4);
        }
        _free(local_44);
        return;
      }
      local_44 = (uint *)0x0;
      local_40 = (uint *)0x0;
      uStack_3c = 0;
      if (*(char *)((int)piVar6 + 0x21) == '\0') {
        piVar3 = (int *)piVar6[2];
        if (*(char *)((int)piVar3 + 0x21) == '\0') {
          cVar2 = *(char *)(*piVar3 + 0x21);
          piVar6 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar2 == '\0') {
            cVar2 = *(char *)(*piVar3 + 0x21);
            piVar6 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar2 = *(char *)(piVar6[1] + 0x21);
          piVar5 = (int *)piVar6[1];
          piVar3 = piVar6;
          while ((piVar6 = piVar5, cVar2 == '\0' && (piVar3 == (int *)piVar6[2]))) {
            cVar2 = *(char *)(piVar6[1] + 0x21);
            piVar5 = (int *)piVar6[1];
            piVar3 = piVar6;
          }
        }
      }
    } while (piVar6 != local_50);
    in_ECX = local_4c;
  }
  _local_4 = CONCAT31(uStack_3,1);
  FUN_00788050(&local_50,*(undefined4 *)in_ECX[5],(undefined4 *)in_ECX[5]);
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_007862f0 @ 0x007862f0 ====

void FUN_007862f0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00997b3d;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f7bcc;
  iVar1 = FUN_004be360();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  local_4._0_1_ = 1;
  iVar1 = FUN_004be360();
  in_ECX[5] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(undefined4 *)(in_ECX[5] + 4) = in_ECX[5];
  *(undefined4 *)in_ECX[5] = in_ECX[5];
  *(undefined4 *)(in_ECX[5] + 8) = in_ECX[5];
  in_ECX[6] = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00401740(s_Item_CashShop_TabList_csv_009f7b18,0x19);
  FUN_00785ea0();
  FUN_00401740(s_Item_CashShop_ItemList_csv_009f7b34,0x1a);
  FUN_00785ea0();
  FUN_00401740(s_Item_CashShop_MainTab_csv_009f7b50,0x19);
  FUN_00785ea0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00786400 @ 0x00786400 ====

void FUN_00786400(undefined4 *param_1,byte *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x21) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x21) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < *(byte *)(puVar3 + 3))) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_00786470 @ 0x00786470 ====

undefined4 * FUN_00786470(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 == param_2) {
    return param_3;
  }
  puVar2 = (undefined4 *)(param_2 + 0x20);
  puVar3 = param_3 + 8;
  do {
    puVar1 = (undefined4 *)(param_2 + -0x2c);
    param_2 = param_2 + -0x2c;
    param_3 = param_3 + -0xb;
    *param_3 = *puVar1;
    FUN_00401660(puVar2 + -0x12,0,0xffffffff);
    puVar3[-0xb] = puVar2[-0xb];
    puVar3[-10] = puVar2[-10];
    *(undefined2 *)(puVar3 + -9) = *(undefined2 *)(puVar2 + -9);
    *(undefined1 *)((int)puVar3 + -0x22) = *(undefined1 *)((int)puVar2 + -0x22);
    puVar2 = puVar2 + -0xb;
    puVar3 = puVar3 + -0xb;
  } while (param_2 != param_1);
  return param_3;
}


// ==== FUN_007864e0 @ 0x007864e0 ====

undefined4 * FUN_007864e0(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x2c;
    puVar2 = param_3 + -0xb;
    *puVar2 = *(undefined4 *)(param_2 + -0x2c);
    param_3[-10] = *(undefined4 *)(param_2 + -0x28);
    *(undefined2 *)(param_3 + -9) = *(undefined2 *)(param_2 + -0x24);
    FUN_00401660(param_2 + -0x20,0,0xffffffff);
    *(undefined1 *)(param_3 + -1) = *(undefined1 *)(param_2 + -4);
    param_2 = iVar1;
    param_3 = puVar2;
  } while (iVar1 != param_1);
  return puVar2;
}


// ==== FUN_00786540 @ 0x00786540 ====

undefined4 * FUN_00786540(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00997b61;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0xb) {
    local_8 = 1;
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[7] = 0xf;
      param_3[6] = 0;
      *(undefined1 *)(param_3 + 2) = 0;
      FUN_00401660(param_1 + 1,0,0xffffffff);
      param_3[8] = param_1[8];
      param_3[9] = param_1[9];
      *(undefined2 *)(param_3 + 10) = *(undefined2 *)(param_1 + 10);
      *(undefined1 *)((int)param_3 + 0x2a) = *(undefined1 *)((int)param_1 + 0x2a);
    }
    param_3 = param_3 + 0xb;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@007865cc @ 0x007865cc ====

void Catch_007865cc(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 0x10)) {
    puVar1 = (uint *)(iVar2 + 0x1c);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x2c;
      puVar1 = puVar1 + 0xb;
    } while (iVar2 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== __break @ 0x0078662e ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00786630 @ 0x00786630 ====

int FUN_00786630(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00997b70;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x2c) {
    FUN_00695f20(param_3,param_1);
    param_3 = param_3 + 0x2c;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0078667d @ 0x0078667d ====

void Catch_0078667d(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 0x10)) {
    puVar1 = (uint *)(iVar2 + 0x24);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x2c;
      puVar1 = puVar1 + 0xb;
    } while (iVar2 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_007866e0 @ 0x007866e0 ====

void FUN_007866e0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = param_1 + 8;
    do {
      *param_1 = *param_3;
      FUN_00401660(param_3 + 1,0,0xffffffff);
      *puVar1 = param_3[8];
      puVar1[1] = param_3[9];
      *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_3 + 10);
      *(undefined1 *)((int)puVar1 + 10) = *(undefined1 *)((int)param_3 + 0x2a);
      param_1 = param_1 + 0xb;
      puVar1 = puVar1 + 0xb;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_00786740 @ 0x00786740 ====

void FUN_00786740(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_3 + 2);
      FUN_00401660(param_3 + 3,0,0xffffffff);
      *(undefined1 *)(param_1 + 10) = *(undefined1 *)(param_3 + 10);
      param_1 = param_1 + 0xb;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_00786790 @ 0x00786790 ====

void FUN_00786790(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00997b91;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *param_3;
      param_1[7] = 0xf;
      param_1[6] = 0;
      *(undefined1 *)(param_1 + 2) = 0;
      FUN_00401660(param_3 + 1,0,0xffffffff);
      param_1[8] = param_3[8];
      param_1[9] = param_3[9];
      *(undefined2 *)(param_1 + 10) = *(undefined2 *)(param_3 + 10);
      *(undefined1 *)((int)param_1 + 0x2a) = *(undefined1 *)((int)param_3 + 0x2a);
    }
    param_1 = param_1 + 0xb;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0078681d @ 0x0078681d ====

void Catch_0078681d(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 8)) {
    puVar1 = (uint *)(iVar2 + 0x1c);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      iVar2 = iVar2 + 0x2c;
      puVar1 = puVar1 + 0xb;
    } while (iVar2 != *(int *)(unaff_EBP + 8));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00786870 @ 0x00786870 ====

void FUN_00786870(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00997ba0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00695f20(param_1,param_3);
    param_1 = param_1 + 0x2c;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@007868bd @ 0x007868bd ====

void Catch_007868bd(void)

{
  int iVar1;
  int unaff_EBP;
  uint *puVar2;
  int iVar3;
  
  iVar3 = *(int *)(unaff_EBP + -0x14);
  iVar1 = *(int *)(unaff_EBP + 8);
  if (iVar3 != iVar1) {
    puVar2 = (uint *)(iVar3 + 0x24);
    do {
      if (0xf < *puVar2) {
        _free((void *)puVar2[-5]);
        return;
      }
      *puVar2 = 0xf;
      puVar2[-1] = 0;
      *(undefined1 *)(puVar2 + -5) = 0;
      iVar3 = iVar3 + 0x2c;
      puVar2 = puVar2 + 0xb;
    } while (iVar3 != iVar1);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00786920 @ 0x00786920 ====

int FUN_00786920(int param_1,int param_2,undefined4 param_3)

{
  FUN_00786790(param_1,param_2,param_3);
  return param_1 + param_2 * 0x2c;
}


// ==== FUN_00786950 @ 0x00786950 ====

int FUN_00786950(int param_1,int param_2,undefined4 param_3)

{
  FUN_00786870(param_1,param_2,param_3);
  return param_1 + param_2 * 0x2c;
}


// ==== FUN_00786980 @ 0x00786980 ====

void FUN_00786980(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined4 local_44;
  void *local_3c;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  undefined1 local_1a;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00997bb8;
  local_10 = ExceptionList;
  local_44 = *param_3;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x50);
  local_28 = 0xf;
  local_2c = 0;
  local_3c = (void *)((uint)local_3c & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3 + 1,0,0xffffffff);
  local_24 = param_3[8];
  local_20 = param_3[9];
  local_1c = *(undefined2 *)(param_3 + 10);
  local_1a = *(undefined1 *)((int)param_3 + 0x2a);
  iVar2 = *(int *)(in_ECX + 4);
  local_8 = 0;
  if (iVar2 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x2c;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x2c;
    }
    if (0x5d1745dU - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x2c;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x5d1745d - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x2c;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_0066e800();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x2c);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = FUN_00786540(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_00786790(iVar2,param_2,&local_44);
      FUN_00786540(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x2c);
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x2c;
      }
      if (iVar2 != 0) {
        FUN_0066ec80(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x2c + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar1) * 0x2c);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      iVar1 = param_2 * 0x2c;
      if ((uint)((iVar2 - param_1) / 0x2c) < param_2) {
        FUN_00786540(param_1,iVar2,iVar1 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00786920(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x2c,
                     &local_44);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
        local_8 = 0;
        FUN_007866e0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x2c,&local_44);
      }
      else {
        iVar6 = iVar2 + param_2 * -0x2c;
        uVar4 = FUN_00786540(iVar6,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_00786470(param_1,iVar6,iVar2,param_1);
        FUN_007866e0(param_1,iVar1 + param_1,&local_44);
      }
    }
  }
  if (local_28 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_3c);
  return;
}


// ==== Catch@00786b81 @ 0x00786b81 ====

void Catch_00786b81(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_0066ec80(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@00786c3b @ 0x00786c3b ====

void Catch_00786c3b(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x2c;
  FUN_0066ec80(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00786cd0 @ 0x00786cd0 ====

void FUN_00786cd0(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  undefined4 local_44;
  undefined4 local_40;
  undefined2 local_3c;
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00997bd8;
  local_10 = ExceptionList;
  local_44 = *param_3;
  local_3c = *(undefined2 *)(param_3 + 2);
  local_14 = (undefined1 *)((int)register0x00000010 + -0x50);
  local_40 = param_3[1];
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3 + 3,0,0xffffffff);
  local_1c = *(undefined1 *)(param_3 + 10);
  iVar2 = *(int *)(in_ECX + 4);
  local_8 = 0;
  if (iVar2 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x2c;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x2c;
    }
    if (0x5d1745dU - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x2c;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x5d1745d - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x2c;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_0066e800();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x2c);
      local_8 = CONCAT31(local_8._1_3_,1);
      iVar2 = FUN_00786630(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_00786870(iVar2,param_2,&local_44);
      FUN_00786630(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x2c);
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x2c;
      }
      if (iVar2 != 0) {
        FUN_00696180(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x2c + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar1) * 0x2c);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      iVar1 = param_2 * 0x2c;
      if ((uint)((iVar2 - param_1) / 0x2c) < param_2) {
        FUN_00786630(param_1,iVar2,iVar1 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00786950(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x2c,
                     &local_44);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar1;
        local_8 = 0;
        FUN_00786740(param_1,*(int *)(in_ECX + 8) + param_2 * -0x2c,&local_44);
      }
      else {
        iVar6 = iVar2 + param_2 * -0x2c;
        uVar4 = FUN_00786630(iVar6,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_007864e0(param_1,iVar6,iVar2,param_1);
        FUN_00786740(param_1,iVar1 + param_1,&local_44);
      }
    }
  }
  if (local_20 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_34);
  return;
}


// ==== Catch@00786ecb @ 0x00786ecb ====

void Catch_00786ecb(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + 0x10);
  FUN_00696180(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@00786f85 @ 0x00786f85 ====

void Catch_00786f85(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x2c;
  FUN_00696180(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00787010 @ 0x00787010 ====

void FUN_00787010(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x2c != 0) {
      iVar1 = (param_2 - iVar1) / 0x2c;
      goto LAB_00787055;
    }
  }
  iVar1 = 0;
LAB_00787055:
  FUN_00786980(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x2c;
  return;
}


// ==== FUN_00787080 @ 0x00787080 ====

void FUN_00787080(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x2c != 0) {
      iVar1 = (param_2 - iVar1) / 0x2c;
      goto LAB_007870c5;
    }
  }
  iVar1 = 0;
LAB_007870c5:
  FUN_00786cd0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x2c;
  return;
}


// ==== FUN_007870f0 @ 0x007870f0 ====

void FUN_007870f0(void)

{
  FUN_0066f0e0();
  return;
}


// ==== FUN_00787100 @ 0x00787100 ====

void FUN_00787100(void)

{
  FUN_006961a0();
  return;
}


// ==== FUN_00787110 @ 0x00787110 ====

void FUN_00787110(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x2c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x2c))) {
    FUN_00787010(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00786790(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x2c;
  return;
}


// ==== FUN_007871a0 @ 0x007871a0 ====

void FUN_007871a0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x2c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x2c))) {
    FUN_00787080(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00786870(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x2c;
  return;
}


// ==== FUN_00787230 @ 0x00787230 ====

void FUN_00787230(void)

{
  FUN_0066f0e0();
  return;
}


// ==== FUN_00787240 @ 0x00787240 ====

void FUN_00787240(void)

{
  FUN_006961a0();
  return;
}


// ==== FUN_00787250 @ 0x00787250 ====

undefined4 *
FUN_00787250(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00997c01;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x24);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    *(undefined1 *)(puVar1 + 3) = *param_4;
    FUN_0066f030(param_4 + 4);
    *(undefined1 *)(puVar1 + 8) = param_5;
    *(undefined1 *)((int)puVar1 + 0x21) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@007872d6 @ 0x007872d6 ====

void Catch_007872d6(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_007872f0 @ 0x007872f0 ====

undefined4 *
FUN_007872f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00997c21;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x24);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[3] = *param_4;
    FUN_00696200(param_4 + 1);
    *(undefined1 *)(puVar1 + 8) = param_5;
    *(undefined1 *)((int)puVar1 + 0x21) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@00787376 @ 0x00787376 ====

void Catch_00787376(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00787390 @ 0x00787390 ====

void FUN_00787390(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997c38;
  local_c = ExceptionList;
  if (0xcccccca < *(uint *)(in_ECX + 8)) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &local_c;
    FUN_00401740(s_map_set<T>_too_long_0099cd54,0x13);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c48c);
  }
  ExceptionList = &local_c;
  piVar4 = (int *)FUN_00787250(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[8] == '\0') {
LAB_00787489:
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
      if ((char)piVar6[8] == '\0') goto LAB_00787489;
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


// ==== FUN_00787570 @ 0x00787570 ====

void FUN_00787570(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997c38;
  local_c = ExceptionList;
  if (0xcccccca < *(uint *)(in_ECX + 8)) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &local_c;
    FUN_00401740(s_map_set<T>_too_long_0099cd54,0x13);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c48c);
  }
  ExceptionList = &local_c;
  piVar4 = (int *)FUN_007872f0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[8] == '\0') {
LAB_00787669:
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
      if ((char)piVar6[8] == '\0') goto LAB_00787669;
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


// ==== FUN_00787750 @ 0x00787750 ====

void FUN_00787750(undefined4 *param_1,byte *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x21) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x21) == '\0');
  }
  param_2 = (byte *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00787390(&param_2,1,puVar4,pbVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004ddea0();
  }
  if (*(byte *)((int)param_2 + 0xc) < *pbVar2) {
    puVar4 = (undefined4 *)FUN_00787390(&param_2,bVar5,puVar4,pbVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00787810 @ 0x00787810 ====

void FUN_00787810(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00787570(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004ddea0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00787570(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_007878d0 @ 0x007878d0 ====

/* WARNING: Removing unreachable block (ram,0x007879e4) */
/* WARNING: Removing unreachable block (ram,0x007879f5) */
/* WARNING: Removing unreachable block (ram,0x007879fe) */
/* WARNING: Removing unreachable block (ram,0x00787a01) */
/* WARNING: Removing unreachable block (ram,0x007879f1) */
/* WARNING: Removing unreachable block (ram,0x00787a0f) */
/* WARNING: Removing unreachable block (ram,0x00787a1c) */
/* WARNING: Removing unreachable block (ram,0x00787a27) */
/* WARNING: Removing unreachable block (ram,0x00787a23) */
/* WARNING: Removing unreachable block (ram,0x00787a17) */
/* WARNING: Removing unreachable block (ram,0x00787a2a) */

void FUN_007878d0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  uint *puVar6;
  int *piVar7;
  int iVar8;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997c38;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x21) != '\0') {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &pvStack_c;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c7c8);
  }
  ExceptionList = &pvStack_c;
  FUN_004dde50();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x21) == '\0') {
    if (*(char *)(param_2[2] + 0x21) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x21) == '\0') {
    piVar7[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar7;
  }
  else if ((int *)*piVar5 == param_2) {
    *piVar5 = (int)piVar7;
  }
  else {
    piVar5[2] = (int)piVar7;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar7 + 0x21) == '\0') {
      piVar3 = (int *)FUN_004128f0(piVar7);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar8 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar8 + 8) == param_2) {
    if (*(char *)((int)piVar7 + 0x21) == '\0') {
      uVar4 = FUN_0057dff0(piVar7);
      *(undefined4 *)(iVar8 + 8) = uVar4;
    }
    else {
      *(int **)(iVar8 + 8) = piVar5;
    }
  }
  if ((char)param_2[8] == '\x01') {
    if (piVar7 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar7[8] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar7 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[8] == '\0') {
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(piVar3 + 8) = 0;
            FUN_004bdf70(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            if ((*(char *)(*piVar5 + 0x20) == '\x01') && (*(char *)(piVar5[2] + 0x20) == '\x01'))
            goto LAB_00787afb;
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
LAB_00787afb:
            *(undefined1 *)(piVar5 + 8) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar7 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar7 + 8) = 1;
  }
  iVar8 = param_2[5];
  if (iVar8 == 0) {
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    _free(param_2);
    return;
  }
  iVar2 = param_2[6];
  if (iVar8 != iVar2) {
    puVar6 = (uint *)(iVar8 + 0x1c);
    do {
      if (0xf < *puVar6) {
        FUN_00412910(puVar6[-5],*puVar6 + 1);
      }
      *puVar6 = 0xf;
      FUN_00401310(0);
      iVar8 = iVar8 + 0x2c;
      puVar6 = puVar6 + 0xb;
    } while (iVar8 != iVar2);
  }
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_00787bf0 @ 0x00787bf0 ====

/* WARNING: Removing unreachable block (ram,0x00787d04) */
/* WARNING: Removing unreachable block (ram,0x00787d15) */
/* WARNING: Removing unreachable block (ram,0x00787d1e) */
/* WARNING: Removing unreachable block (ram,0x00787d21) */
/* WARNING: Removing unreachable block (ram,0x00787d11) */
/* WARNING: Removing unreachable block (ram,0x00787d2f) */
/* WARNING: Removing unreachable block (ram,0x00787d3c) */
/* WARNING: Removing unreachable block (ram,0x00787d47) */
/* WARNING: Removing unreachable block (ram,0x00787d43) */
/* WARNING: Removing unreachable block (ram,0x00787d37) */
/* WARNING: Removing unreachable block (ram,0x00787d4a) */

void FUN_00787bf0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  uint *puVar6;
  int *piVar7;
  int iVar8;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997c38;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x21) != '\0') {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &pvStack_c;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c7c8);
  }
  ExceptionList = &pvStack_c;
  FUN_004dde50();
  piVar7 = (int *)*param_2;
  if (*(char *)((int)piVar7 + 0x21) == '\0') {
    if (*(char *)(param_2[2] + 0x21) == '\0') {
      piVar7 = (int *)param_2[2];
    }
  }
  else {
    piVar7 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar7 + 0x21) == '\0') {
    piVar7[1] = (int)piVar5;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar7;
  }
  else if ((int *)*piVar5 == param_2) {
    *piVar5 = (int)piVar7;
  }
  else {
    piVar5[2] = (int)piVar7;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar7 + 0x21) == '\0') {
      piVar3 = (int *)FUN_004128f0(piVar7);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar8 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar8 + 8) == param_2) {
    if (*(char *)((int)piVar7 + 0x21) == '\0') {
      uVar4 = FUN_0057dff0(piVar7);
      *(undefined4 *)(iVar8 + 8) = uVar4;
    }
    else {
      *(int **)(iVar8 + 8) = piVar5;
    }
  }
  if ((char)param_2[8] == '\x01') {
    if (piVar7 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar7[8] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar7 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[8] == '\0') {
            *(undefined1 *)(piVar5 + 8) = 1;
            *(undefined1 *)(piVar3 + 8) = 0;
            FUN_004bdf70(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x21) == '\0') {
            if ((*(char *)(*piVar5 + 0x20) == '\x01') && (*(char *)(piVar5[2] + 0x20) == '\x01'))
            goto LAB_00787e1b;
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
LAB_00787e1b:
            *(undefined1 *)(piVar5 + 8) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar7 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar7 + 8) = 1;
  }
  iVar8 = param_2[5];
  if (iVar8 == 0) {
    param_2[5] = 0;
    param_2[6] = 0;
    param_2[7] = 0;
    _free(param_2);
    return;
  }
  iVar2 = param_2[6];
  if (iVar8 != iVar2) {
    puVar6 = (uint *)(iVar8 + 0x24);
    do {
      if (0xf < *puVar6) {
        FUN_00412910(puVar6[-5],*puVar6 + 1);
      }
      *puVar6 = 0xf;
      FUN_00401310(0);
      iVar8 = iVar8 + 0x2c;
      puVar6 = puVar6 + 0xb;
    } while (iVar8 != iVar2);
  }
  _free((void *)param_2[5]);
  return;
}


// ==== FUN_00787f10 @ 0x00787f10 ====

void FUN_00787f10(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    FUN_00787f10(*(undefined4 *)((int)param_1 + 8));
    FUN_00787230();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00787f50 @ 0x00787f50 ====

void FUN_00787f50(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    FUN_00787f50(*(undefined4 *)((int)param_1 + 8));
    FUN_00787240();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00787f90 @ 0x00787f90 ====

void FUN_00787f90(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00787f10(piVar6[1]);
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
    FUN_007878d0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00788050 @ 0x00788050 ====

void FUN_00788050(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00787f50(piVar6[1]);
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
    FUN_00787bf0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00788110 @ 0x00788110 ====

void FUN_00788110(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00787f90(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00788140 @ 0x00788140 ====

void FUN_00788140(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00788050(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00788170 @ 0x00788170 ====

void FUN_00788170(byte param_1)

{
  void *in_ECX;
  
  FUN_007860d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00788190 @ 0x00788190 ====

void FUN_00788190(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7be8;
  return;
}


// ==== FUN_007881a0 @ 0x007881a0 ====

void FUN_007881a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7be8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007881c0 @ 0x007881c0 ====

undefined4 FUN_007881c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_007881d0 @ 0x007881d0 ====

undefined4 FUN_007881d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 4) + 0x10);
}


// ==== FUN_007881e0 @ 0x007881e0 ====

void FUN_007881e0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  iVar2 = *(int *)(in_ECX + 4);
  *(undefined4 *)(iVar2 + 8) = param_1[2];
  *(undefined4 *)(iVar2 + 0xc) = param_1[3];
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x14) = param_1[5];
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x10) = param_1[4];
  return;
}


// ==== FUN_00788220 @ 0x00788220 ====

void FUN_00788220(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00997c58;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f7c18;
  *(undefined1 *)(in_ECX + 2) = 0;
  puVar1 = operator_new(0x1c);
  if (puVar1 == (undefined4 *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[5] = 0;
  *(undefined1 *)(puVar1 + 6) = 0;
  puVar1[2] = 100;
  puVar1[3] = 100;
  puVar1[4] = 15000;
  in_ECX[1] = puVar1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_007882b0 @ 0x007882b0 ====

void FUN_007882b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7c18;
  _free((void *)in_ECX[1]);
  return;
}


// ==== FUN_007882e0 @ 0x007882e0 ====

void FUN_007882e0(void)

{
  int in_ECX;
  
  if (*(char *)(*(int *)(in_ECX + 4) + 0x18) == '\0') {
    *(undefined1 *)(in_ECX + 8) = 1;
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x10) = 15000;
    (**(code **)(*DAT_00b5a830 + 0xc))();
    (**(code **)(*DAT_00b5a830 + 8))
              (0xc0,0x90,0x280,0x1e0,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x14));
  }
  return;
}


// ==== FUN_00788340 @ 0x00788340 ====

void FUN_00788340(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  void *local_28;
  void *local_24;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997c6a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f7c04;
  }
  puVar1[1] = *(undefined4 *)(*(int *)(in_ECX + 4) + 0x14);
  FUN_00797a20(puVar1);
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_rc_ppl_on_009f7bd8,9);
  local_4 = 0;
  (**(code **)(*DAT_00b5a688 + 4))(&local_28);
  puStack_8 = (undefined1 *)0xffffffff;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  uVar4 = *puVar1;
  uVar2 = puVar1[1];
  uVar3 = puVar1[2];
  uVar5 = puVar1[3];
  puVar1[4] = 10000;
  if (*(char *)(in_ECX + 8) != '\0') {
    *(undefined4 *)(*(int *)(in_ECX + 4) + 0x10) = 15000;
    uVar3 = 0x280;
    uVar5 = 0x1e0;
    uVar4 = 0xc0;
    uVar2 = 0x90;
  }
  (**(code **)(*DAT_00b5a830 + 8))
            (uVar4,uVar2,uVar3,uVar5,*(undefined4 *)(*(int *)(in_ECX + 4) + 0x14));
  ExceptionList = local_24;
  return;
}


// ==== FUN_00788440 @ 0x00788440 ====

undefined4 FUN_00788440(void)

{
  return 0x70940002;
}


// ==== FUN_00788450 @ 0x00788450 ====

void FUN_00788450(byte param_1)

{
  void *in_ECX;
  
  FUN_007882b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00788470 @ 0x00788470 ====

void FUN_00788470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7c34;
  return;
}


// ==== FUN_00788480 @ 0x00788480 ====

void FUN_00788480(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7c34;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007884a0 @ 0x007884a0 ====

void FUN_007884a0(void)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x14))();
  if (cVar1 == '\x01') {
    (**(code **)(*in_ECX + 0xc))(2);
    return;
  }
  (**(code **)(*in_ECX + 0xc))(0);
  return;
}


// ==== FUN_007884c0 @ 0x007884c0 ====

short FUN_007884c0(ushort param_1)

{
  ushort uVar1;
  byte bVar2;
  int in_ECX;
  
  uVar1 = *(ushort *)(in_ECX + 8);
  bVar2 = (byte)(uVar1 >> 8);
  if (*(ushort *)(in_ECX + 10) == 0) {
    return CONCAT11(bVar2,uVar1 == param_1);
  }
  if (*(ushort *)(in_ECX + 10) < param_1) {
    return (ushort)bVar2 << 8;
  }
  return CONCAT11(bVar2,uVar1 <= param_1);
}


// ==== FUN_007884f0 @ 0x007884f0 ====

void FUN_007884f0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00788500 @ 0x00788500 ====

undefined4 FUN_00788500(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined2 *puVar5;
  int *in_ECX;
  
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x60) + 0x14))();
  piVar4 = (int *)(**(code **)(*piVar3 + 0x14))();
  while( true ) {
    while( true ) {
      if (piVar4 == (int *)0x0) {
        return 0;
      }
      piVar4 = (int *)(**(code **)(*piVar4 + 0xc))();
      puVar5 = (undefined2 *)(**(code **)(*piVar4 + 4))();
      piVar4 = (int *)(**(code **)(*DAT_00b5ab9c + 8))(*puVar5);
      if (piVar4 != (int *)0x0) break;
      piVar4 = (int *)(**(code **)(*piVar3 + 0x18))();
    }
    iVar2 = (**(code **)(*piVar4 + 8))();
    cVar1 = (**(code **)(*in_ECX + 0x18))(*(undefined2 *)(iVar2 + 2));
    if (cVar1 != '\0') break;
    piVar4 = (int *)(**(code **)(*piVar3 + 0x18))();
  }
  return 1;
}


// ==== FUN_00788580 @ 0x00788580 ====

undefined4 FUN_00788580(void)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x60) + 0x18))();
  sVar2 = (**(code **)(*piVar4 + 0x14))();
  while( true ) {
    if (sVar2 == 0) {
      return 0;
    }
    cVar1 = (**(code **)(*in_ECX + 0x18))(sVar2);
    if (cVar1 != '\0') break;
    sVar2 = (**(code **)(*piVar4 + 0x18))();
  }
  return 1;
}


// ==== FUN_007885d0 @ 0x007885d0 ====

uint FUN_007885d0(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  
  uVar3 = *(uint *)(in_ECX + 0x4c);
  if (uVar3 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (int)(*(int *)(in_ECX + 0x50) - uVar3) >> 2;
  }
  uVar4 = 0;
  if (uVar5 != 0) {
    iVar1 = *(int *)(in_ECX + 0x4c);
    do {
      if (iVar1 == 0) {
LAB_0078861a:
                    /* WARNING: Subroutine does not return */
        FUN_0042f370();
      }
      iVar2 = *(int *)(in_ECX + 0x50) - iVar1;
      uVar3 = iVar2 >> 2;
      if (uVar3 <= uVar4) goto LAB_0078861a;
      if (*(int *)(iVar1 + uVar4 * 4) == param_1) {
        return CONCAT31((int3)(iVar2 >> 10),1);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar5);
  }
  return uVar3 & 0xffffff00;
}


// ==== FUN_00788630 @ 0x00788630 ====

void FUN_00788630(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7c58;
  FUN_00716900();
  *in_ECX = &PTR_FUN_009f7c34;
  return;
}


// ==== FUN_00788650 @ 0x00788650 ====

void FUN_00788650(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00997cb8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f7c58;
  FUN_007886a0(param_1);
  ExceptionList = local_c;
  return;
}


// ==== FUN_007886a0 @ 0x007886a0 ====

void FUN_007886a0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997ca1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = *param_1;
  *(undefined2 *)(in_ECX + 1) = *(undefined2 *)(param_1 + 1);
  *(undefined2 *)((int)in_ECX + 6) = *(undefined2 *)((int)param_1 + 6);
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(param_1 + 2,0,0xffffffff);
  local_4 = 0;
  FUN_00406600(param_1 + 9);
  local_4._0_1_ = 1;
  FUN_00406600(param_1 + 0xd);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00430c20(param_1 + 0x11);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00788750 @ 0x00788750 ====

void FUN_00788750(byte param_1)

{
  void *in_ECX;
  
  FUN_00788630();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00788770 @ 0x00788770 ====

void FUN_00788770(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a4184;
  return;
}


// ==== FUN_00788780 @ 0x00788780 ====

void FUN_00788780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7d24;
  return;
}


// ==== FUN_00788790 @ 0x00788790 ====

/* WARNING: Removing unreachable block (ram,0x0078886e) */

void FUN_00788790(int *param_1)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  undefined1 auStack_a4 [8];
  undefined1 uStack_9c;
  undefined1 uStack_9b;
  undefined1 uStack_9a;
  undefined1 uStack_99;
  undefined1 uStack_98;
  uint uStack_90;
  undefined4 uStack_84;
  char *pcStack_80;
  int iStack_7c;
  char *pcStack_78;
  byte local_5a [30];
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  byte bStack_34;
  byte bStack_33;
  byte bStack_32;
  undefined1 uStack_31;
  undefined1 uStack_30;
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00997ce0;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_4 = 0;
  ExceptionList = &pvStack_c;
  uVar5 = (**(code **)(*param_1 + 8))();
  if (1 < uVar5) {
    uVar5 = 1;
    do {
      iVar2 = *DAT_00b5ad20;
      pcStack_78 = (char *)0x788804;
      FUN_00475a90();
      uVar6 = (**(code **)(iVar2 + 0xc))();
      iStack_7c = 0x78881a;
      pcStack_78 = (char *)uVar5;
      uVar4 = FUN_004756e0();
      iStack_7c = 0x788828;
      pcStack_78 = (char *)uVar5;
      bStack_34 = FUN_004753b0();
      if (3 < bStack_34) {
        pcStack_78 = s_stCashItem_m_Tab_<_MAXTABCOUNT_009f7cf8;
        iStack_7c = 0x788851;
        FUN_00401740();
        puStack_8._0_1_ = 1;
        pcStack_78 = (char *)0x788860;
        FUN_00406880();
        puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      bStack_33 = local_5a[bStack_34 - 6] / 10;
      bStack_32 = local_5a[bStack_34 - 6] % 10;
      iStack_7c = 0x7888ae;
      pcStack_78 = (char *)uVar5;
      uStack_31 = FUN_004753b0();
      iStack_7c = 0x7888bc;
      pcStack_78 = (char *)uVar5;
      uStack_30 = FUN_004753b0();
      iStack_7c = 0x7888ca;
      pcStack_78 = (char *)uVar5;
      pcStack_80 = (char *)(**(code **)(*param_1 + 0x10))();
      pcVar7 = pcStack_80;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      iStack_7c = (int)pcVar7 - (int)(pcStack_80 + 1);
      uStack_84 = 0x7888e6;
      FUN_00401740();
      local_5a[(uVar6 & 0xff) - 0xe] = local_5a[(uVar6 & 0xff) - 0xe] + 1;
      puStack_8 = auStack_a4;
      uStack_3c = (undefined1)uVar6;
      uStack_9c = uStack_3c;
      uStack_3b = (undefined1)(uVar6 >> 8);
      uStack_9b = uStack_3b;
      uStack_3a = (undefined1)(uVar6 >> 0x10);
      uStack_9a = uStack_3a;
      uStack_39 = (undefined1)(uVar6 >> 0x18);
      uStack_99 = uStack_39;
      iStack_7c = 0xf;
      pcStack_80 = (char *)0x0;
      uStack_90 = uStack_90 & 0xffffff00;
      uStack_98 = uVar4;
      FUN_00401660(&bStack_34,0,0xffffffff);
      (**(code **)(*DAT_00b5b0d8 + 4))();
      uStack_90 = uStack_90 + 1;
      uVar5 = uStack_90 & 0xffff;
      uVar6 = (**(code **)(*param_1 + 8))();
    } while (uVar5 < uVar6);
  }
  if (local_10 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_007889a0 @ 0x007889a0 ====

void FUN_007889a0(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *in_ECX;
  void *local_48;
  void *local_44;
  undefined1 local_40;
  uint local_30;
  undefined4 local_2c;
  void *local_28;
  void *local_24;
  uint uStack_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997d15;
  pvStack_c = ExceptionList;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Item_CashShop_csv_009f7cb4,0x11);
  local_4 = 0;
  uVar1 = FUN_00402220(&local_28,&local_44,s_Loading____009f7cc8);
  local_4._0_1_ = 1;
  FUN_00796d50(uVar1);
  local_4 = (uint)local_4._1_3_ << 8;
  if ((void *)0xf < local_10) {
    _free(local_24);
    return;
  }
  local_48 = operator_new(0x10);
  local_4._0_1_ = 2;
  if (local_48 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = (undefined4 *)FUN_0081d3a0(&local_44);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  if (puVar2 == (undefined4 *)0x0) {
    uVar1 = FUN_00402220(&local_28,&local_44,s_Loading_FAIL_009f7cd4);
    local_4._0_1_ = 3;
    FUN_00796d50(uVar1);
    local_4 = (uint)local_4._1_3_ << 8;
    if ((void *)0xf < local_10) {
      _free(local_24);
      return;
    }
  }
  (**(code **)(*in_ECX + 4))(puVar2);
  uVar1 = FUN_00402220(&local_2c,&local_48,s_Loading_OK_009f7ce4);
  puStack_8._0_1_ = 4;
  FUN_00796d50(uVar1);
  puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
  if (0xf < uStack_14) {
    _free(local_28);
    return;
  }
  if (puVar2 != (undefined4 *)0x0) {
    (**(code **)*puVar2)(1);
  }
  if (local_30 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_44);
  return;
}


// ==== FUN_00788b00 @ 0x00788b00 ====

void FUN_00788b00(undefined4 param_1)

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
  FUN_0044a580(local_100,&DAT_009f7d18,&DAT_009f7cf0);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_00788b4e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_00788b4e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  FUN_00788790(uVar2);
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_00788bb0 @ 0x00788bb0 ====

void FUN_00788bb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00788770();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00788be0 @ 0x00788be0 ====

undefined4 FUN_00788be0(void)

{
  undefined4 extraout_EAX;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [12];
  uint uStack_1c;
  void *pvStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997d28;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  auStack_2c[0] = (**(code **)(*DAT_00b5ac54 + 0x3c))();
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  puStack_8 = (undefined1 *)0x0;
  (**(code **)(*DAT_00b5ac48 + 0x24))(auStack_2c,auStack_28);
  if (uStack_1c < 0x10) {
    ExceptionList = pvStack_18;
    return 0;
  }
  _free(auStack_28);
  return extraout_EAX;
}


// ==== FUN_00788c60 @ 0x00788c60 ====

undefined4 FUN_00788c60(void)

{
  undefined4 extraout_EAX;
  undefined1 *puStack_2c;
  undefined1 local_28 [16];
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997d3a;
  pvStack_c = ExceptionList;
  puStack_2c = local_28;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  puStack_8 = (undefined1 *)0x0;
  (**(code **)(*DAT_00b5ac48 + 0x28))(&puStack_2c);
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_14;
    return 0;
  }
  _free(puStack_2c);
  return extraout_EAX;
}


// ==== FUN_00788cd0 @ 0x00788cd0 ====

undefined4 FUN_00788cd0(void)

{
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined1 *puStack_4c;
  undefined1 *apuStack_48 [2];
  undefined4 uStack_40;
  uint uStack_3c;
  void *pvStack_34;
  undefined1 auStack_30 [8];
  undefined1 local_28 [8];
  uint uStack_20;
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997d54;
  pvStack_c = ExceptionList;
  apuStack_48[0] = local_28;
  puStack_4c = (undefined1 *)0x788cf8;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  puStack_8 = (undefined1 *)0x0;
  puStack_4c = (undefined1 *)apuStack_48;
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  (**(code **)(*DAT_00b5ac48 + 0x2c))(&puStack_4c);
  if (0xf < uStack_3c) {
    _free(auStack_30);
    return extraout_EAX;
  }
  uStack_3c = 0xf;
  uStack_40 = 0;
  if (uStack_20 < 0x10) {
    ExceptionList = pvStack_1c;
    return 0;
  }
  _free(pvStack_34);
  return extraout_EAX_00;
}


// ==== FUN_00788d80 @ 0x00788d80 ====

undefined4 FUN_00788d80(void)

{
  undefined4 extraout_EAX;
  undefined1 auStack_2c [4];
  undefined1 auStack_28 [12];
  uint uStack_1c;
  void *pvStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997d66;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  auStack_2c[0] = (**(code **)(*DAT_00b5ac54 + 0x3c))();
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  puStack_8 = (undefined1 *)0x0;
  (**(code **)(*DAT_00b5ac48 + 0x30))(auStack_2c,auStack_28);
  if (uStack_1c < 0x10) {
    ExceptionList = pvStack_18;
    return 0;
  }
  _free(auStack_28);
  return extraout_EAX;
}


// ==== FUN_00788e00 @ 0x00788e00 ====

undefined4 FUN_00788e00(void)

{
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined1 *puStack_4c;
  undefined1 *apuStack_48 [2];
  undefined4 uStack_40;
  uint uStack_3c;
  void *pvStack_34;
  undefined1 auStack_30 [8];
  undefined1 local_28 [8];
  uint uStack_20;
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997d80;
  pvStack_c = ExceptionList;
  apuStack_48[0] = local_28;
  puStack_4c = (undefined1 *)0x788e28;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  puStack_8 = (undefined1 *)0x0;
  puStack_4c = (undefined1 *)apuStack_48;
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  (**(code **)(*DAT_00b5ac48 + 0x34))(&puStack_4c);
  if (0xf < uStack_3c) {
    _free(auStack_30);
    return extraout_EAX;
  }
  uStack_3c = 0xf;
  uStack_40 = 0;
  if (uStack_20 < 0x10) {
    ExceptionList = pvStack_1c;
    return 0;
  }
  _free(pvStack_34);
  return extraout_EAX_00;
}


// ==== FUN_00788eb0 @ 0x00788eb0 ====

undefined4 FUN_00788eb0(void)

{
  undefined4 extraout_EAX;
  undefined1 *puStack_2c;
  undefined1 local_28 [16];
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997d92;
  pvStack_c = ExceptionList;
  puStack_2c = local_28;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  puStack_8 = (undefined1 *)0x0;
  (**(code **)(*DAT_00b5ac48 + 0x40))(&puStack_2c);
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_14;
    return 0;
  }
  _free(puStack_2c);
  return extraout_EAX;
}


// ==== FUN_00788f20 @ 0x00788f20 ====

undefined4 FUN_00788f20(void)

{
  undefined4 extraout_EAX;
  undefined1 *puStack_2c;
  undefined1 local_28 [16];
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997da4;
  pvStack_c = ExceptionList;
  puStack_2c = local_28;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  puStack_8 = (undefined1 *)0x0;
  (**(code **)(*DAT_00b5ac48 + 0x38))(&puStack_2c);
  if (uStack_18 < 0x10) {
    ExceptionList = pvStack_14;
    return 0;
  }
  _free(puStack_2c);
  return extraout_EAX;
}


// ==== FUN_00788f90 @ 0x00788f90 ====

undefined4 FUN_00788f90(void)

{
  undefined1 uVar1;
  undefined4 extraout_EAX;
  undefined1 auStack_2c [4];
  undefined1 local_28 [12];
  uint uStack_1c;
  void *pvStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997db6;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  puStack_8 = (undefined1 *)0x0;
  uVar1 = (**(code **)(*DAT_00b5ac48 + 0x3c))(auStack_2c);
  (**(code **)(*DAT_00b5ac54 + 0x48))(uVar1);
  if (uStack_1c < 0x10) {
    ExceptionList = pvStack_18;
    return 1;
  }
  _free(local_28);
  return extraout_EAX;
}


// ==== FUN_00789010 @ 0x00789010 ====

undefined4 FUN_00789010(void)

{
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined1 auStack_90 [4];
  undefined1 uStack_8c;
  undefined4 uStack_84;
  undefined1 *puStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined1 auStack_74 [4];
  uint uStack_70;
  uint uStack_6c;
  void *pvStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 *puStack_58;
  undefined1 *puStack_54;
  void *pvStack_4c;
  undefined1 auStack_48 [24];
  undefined1 auStack_30 [8];
  undefined1 local_28 [28];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997dd8;
  pvStack_c = ExceptionList;
  puStack_54 = local_28;
  puStack_58 = (undefined1 *)0x789039;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  puStack_58 = auStack_48;
  puStack_8 = (undefined1 *)0x0;
  uStack_5c = 0x78904f;
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  puStack_54 = auStack_74;
  uStack_78 = 0xffffffff;
  uStack_7c = 0;
  puStack_80 = auStack_30;
  uStack_5c = 0xf;
  uStack_60 = 0;
  pvStack_c._0_1_ = 1;
  uStack_70 = uStack_70 & 0xffffff00;
  uStack_84 = 0x789077;
  FUN_00401660();
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_c._0_1_ = 2;
  uStack_8c = 0;
  FUN_00401660(&pvStack_4c,0,0xffffffff);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  (**(code **)(*DAT_00b5ac48 + 8))();
  if (0xf < uStack_6c) {
    _free(puStack_80);
    return extraout_EAX;
  }
  uStack_6c = 0xf;
  uStack_70 = 0;
  puStack_80 = (undefined1 *)((uint)puStack_80 & 0xffffff00);
  if (auStack_90 < (undefined1 *)0x10) {
    ExceptionList = pvStack_4c;
    return 0;
  }
  _free(pvStack_64);
  return extraout_EAX_00;
}


// ==== FUN_00789100 @ 0x00789100 ====

undefined4 FUN_00789100(void)

{
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  void *unaff_EBX;
  undefined1 auStack_74 [4];
  undefined1 uStack_70;
  void *pvStack_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined1 *puStack_58;
  undefined1 *puStack_54;
  undefined1 *puStack_50;
  undefined1 auStack_48 [16];
  uint uStack_38;
  void *pvStack_34;
  undefined1 auStack_2c [4];
  undefined1 local_28 [24];
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997df2;
  pvStack_c = ExceptionList;
  puStack_50 = local_28;
  puStack_54 = (undefined1 *)0x789129;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  puStack_54 = auStack_2c;
  puStack_58 = auStack_48;
  puStack_8 = (undefined1 *)0x0;
  uStack_5c = 0x789144;
  (**(code **)(*DAT_00b5ac48 + 0x44))();
  puStack_54 = auStack_74;
  uStack_5c = 0xf;
  uStack_60 = 0;
  uStack_10 = 1;
  uStack_70 = 0;
  FUN_00401660(&puStack_50,0,0xffffffff);
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  if ((undefined1 *)0xf < puStack_54) {
    _free(pvStack_68);
    return extraout_EAX;
  }
  puStack_54 = (undefined1 *)0xf;
  puStack_58 = (undefined1 *)0x0;
  pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
  if (uStack_38 < 0x10) {
    ExceptionList = pvStack_34;
    return 1;
  }
  _free(unaff_EBX);
  return extraout_EAX_00;
}


// ==== FUN_007891d0 @ 0x007891d0 ====

undefined4 FUN_007891d0(void)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_EAX;
  void *unaff_EBX;
  undefined1 auStack_58 [4];
  undefined1 uStack_54;
  undefined4 uStack_4c;
  void *pvStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined1 auStack_2a [30];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997e04;
  pvStack_c = ExceptionList;
  uStack_38 = 0x7891f5;
  ExceptionList = &pvStack_c;
  uVar1 = (**(code **)(*DAT_00b5ac54 + 0x38))();
  uStack_38 = 0x789202;
  iVar2 = (**(code **)(*DAT_00b5ac54 + 0x38))();
  uStack_38 = iVar2 << 0x10 | uVar1 & 0xffff;
  uStack_3c = 5;
  uStack_40 = 0x78921b;
  pvStack_48 = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_40 = 0xffffffff;
  uStack_44 = 0;
  uStack_4c = 0x78923b;
  FUN_00401660();
  uStack_40 = 0xf;
  uStack_44 = 0;
  pvStack_c = (void *)0x0;
  uStack_54 = 0;
  FUN_00401660(auStack_2a + -6,0,0xffffffff);
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  if (auStack_58 < (undefined1 *)0x10) {
    ExceptionList = unaff_EBX;
    return 1;
  }
  _free(pvStack_48);
  return extraout_EAX;
}


// ==== FUN_007892a0 @ 0x007892a0 ====

undefined4 FUN_007892a0(void)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined1 auStack_70 [4];
  undefined1 uStack_6c;
  undefined4 uStack_64;
  void **ppvStack_60;
  char *pcStack_5c;
  undefined1 auStack_48 [4];
  undefined1 uStack_44;
  undefined4 uStack_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997e1e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar2 = (**(code **)(*DAT_00b5ac54 + 0x38))();
  auStack_48[0] = uVar2;
  iVar3 = (**(code **)(*DAT_00b5ac80 + 8))();
  pcStack_5c = s_EMPTY_009f7d68;
  uStack_30 = 0xf;
  uStack_34 = 0;
  uStack_44 = 0;
  ppvStack_60 = (void **)0x7892fd;
  FUN_00401740();
  puStack_8 = (undefined1 *)0x0;
  if (iVar3 != 0) {
    pcStack_5c = (char *)(iVar3 + 1);
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    pcVar4 = pcStack_5c;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    ppvStack_60 = (void **)0x789336;
    FUN_00401740();
    pcStack_5c = (char *)0x0;
    ppvStack_60 = &pvStack_2c;
    puStack_8._0_1_ = 1;
    uStack_64 = 0x78934c;
    FUN_00401660();
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    if (0xf < uStack_14) {
      pcStack_5c = (char *)0x789361;
      _free(pvStack_28);
      return extraout_EAX;
    }
  }
  pcStack_5c = (char *)0x0;
  uStack_6c = 0;
  FUN_00401660(auStack_48,0,0xffffffff);
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  if (auStack_70 < (undefined1 *)0x10) {
    ExceptionList = pvStack_2c;
    return 1;
  }
  _free(ppvStack_60);
  return extraout_EAX_00;
}


// ==== FUN_007893c0 @ 0x007893c0 ====

undefined4 FUN_007893c0(void)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 *puVar3;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  void *unaff_EBX;
  undefined1 uStack_94;
  undefined1 auStack_93 [3];
  undefined1 auStack_88 [12];
  undefined4 uStack_7c;
  uint uStack_78;
  undefined1 auStack_74 [4];
  void *pvStack_70;
  undefined1 local_68 [12];
  uint uStack_5c;
  undefined4 uStack_58;
  undefined1 uStack_54;
  undefined1 uStack_53;
  undefined1 auStack_50 [4];
  undefined1 uStack_4c;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 auStack_34 [4];
  undefined1 uStack_30;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  void *pvStack_18;
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997e43;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5ac54 + 0x34))();
  puStack_8 = (undefined1 *)0x0;
  (**(code **)(*DAT_00b5ac54 + 0x34))(auStack_88);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  uVar1 = (**(code **)(*DAT_00b5ac54 + 0x38))();
  iVar2 = (**(code **)(*DAT_00b5ac80 + 8))(uVar1);
  if (iVar2 == 0) {
    if (0xf < uStack_78) {
      _free(unaff_EBX);
      return extraout_EAX;
    }
    if (uStack_5c < 0x10) {
      ExceptionList = pvStack_18;
      return 0;
    }
  }
  else {
    uStack_58 = 0;
    uStack_38 = 0xf;
    uStack_3c = 0;
    uStack_4c = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    uStack_94 = SUB41(local_68,0);
    uStack_54 = uStack_94;
    uStack_53 = *(undefined1 *)(iVar2 + 0x101);
    uStack_10 = 2;
    FUN_00401660(auStack_93 + 3,0,0xffffffff);
    FUN_00401660(auStack_74,0,0xffffffff);
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = &PTR_FUN_009d6470;
      puVar3[1] = 0;
      *(undefined1 *)(puVar3 + 2) = 0xff;
      *(undefined1 *)((int)puVar3 + 9) = 0xff;
      puVar3[9] = 0xf;
      puVar3[8] = 0;
      *(undefined1 *)(puVar3 + 4) = 0;
      puVar3[0x10] = 0xf;
      puVar3[0xf] = 0;
      *(undefined1 *)(puVar3 + 0xb) = 0;
    }
    puVar3[1] = uStack_58;
    *(undefined1 *)(puVar3 + 2) = uStack_54;
    *(undefined1 *)((int)puVar3 + 9) = uStack_53;
    FUN_00401660(auStack_50,0,0xffffffff);
    FUN_00401660(auStack_34,0,0xffffffff);
    FUN_00797a20(puVar3);
    FUN_00844200();
    if (0xf < uStack_78) {
      _free(unaff_EBX);
      return extraout_EAX_00;
    }
    if (uStack_5c < 0x10) {
      ExceptionList = pvStack_18;
      return 0;
    }
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  _free(pvStack_70);
  return extraout_EAX_01;
}


// ==== FUN_007895b0 @ 0x007895b0 ====

void FUN_007895b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7e10;
  return;
}


// ==== FUN_007895c0 @ 0x007895c0 ====

void FUN_007895c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7e10;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007895e0 @ 0x007895e0 ====

void FUN_007895e0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = param_1;
  return;
}


// ==== FUN_007895f0 @ 0x007895f0 ====

undefined4 FUN_007895f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x24);
}


// ==== FUN_00789600 @ 0x00789600 ====

int FUN_00789600(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 8,0,0xffffffff);
  return param_1;
}


// ==== FUN_00789630 @ 0x00789630 ====

void FUN_00789630(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00997e63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f7e34;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  local_4 = 1;
  in_ECX[1] = 0;
  FUN_00401740(&DAT_009f7dbe,0);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00789690 @ 0x00789690 ====

void FUN_00789690(undefined4 param_1,undefined1 param_2,void *param_3)

{
  int in_ECX;
  uint in_stack_00000020;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00997e75;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 4) = param_1;
  local_4 = 0;
  FUN_00401660(&param_2,0,0xffffffff);
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_3);
  return;
}


// ==== FUN_007896f0 @ 0x007896f0 ====

undefined4 FUN_007896f0(void)

{
  code *pcVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997e87;
  local_c = ExceptionList;
  if (*(int *)(in_ECX + 4) != 0) {
    return *(undefined4 *)(in_ECX + 4);
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_m_pBaseWindow____NULL_009f7dc0,0x15);
  local_4 = 0;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00789780 @ 0x00789780 ====

void FUN_00789780(void)

{
  int iVar1;
  int *in_ECX;
  undefined1 auStack_8c [4];
  undefined1 uStack_88;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined1 auStack_70 [4];
  uint uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 *puStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 uStack_50;
  undefined4 uStack_44;
  char *pcStack_40;
  undefined4 uStack_3c;
  undefined1 uStack_34;
  undefined1 *puStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = *DAT_00b5ac48;
  uStack_14 = 0x789793;
  uStack_14 = (**(code **)(*in_ECX + 0x10))();
  uStack_18 = 0x789799;
  (**(code **)(iVar1 + 0x10))();
  iStack_1c = in_ECX[9];
  uStack_18 = 0;
  uStack_20 = 0x7897ab;
  (**(code **)(*DAT_00b5ac54 + 8))();
  uStack_3c = 0xc;
  uStack_20 = 0xf;
  uStack_24 = 0;
  pcStack_40 = s_ProcessEvent_009f7dd8;
  uStack_34 = 0;
  uStack_44 = 0x7897ce;
  FUN_00401740();
  uStack_3c = 0x7897d9;
  (**(code **)(*DAT_00b5ac54 + 0x30))();
  puStack_2c = (undefined1 *)&uStack_54;
  uStack_58 = 0xffffffff;
  puStack_5c = (undefined1 *)0x0;
  uStack_3c = 0xf;
  pcStack_40 = (char *)0x0;
  uStack_60 = uStack_24;
  uStack_50 = 0;
  uStack_64 = 0x7897f8;
  FUN_00401660();
  uStack_58 = 0x789803;
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  pcStack_40 = auStack_70;
  uStack_74 = 0xffffffff;
  uStack_78 = 0;
  uStack_58 = 0xf;
  puStack_5c = (undefined1 *)0x0;
  uStack_7c = uStack_3c;
  uStack_6c = uStack_6c & 0xffffff00;
  uStack_80 = 0x789822;
  FUN_00401660();
  uStack_74 = 0x78982d;
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  puStack_5c = auStack_8c;
  uStack_74 = 0xf;
  uStack_78 = 0;
  uStack_88 = 0;
  FUN_00401660(uStack_54,0,0xffffffff);
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  (**(code **)(*DAT_00b5ac54 + 0x40))(uStack_6c);
  (**(code **)(*DAT_00b5ac54 + 8))(in_ECX[9],4);
  (**(code **)(*DAT_00b5ac54 + 0x3c))();
  return;
}


// ==== FUN_00789890 @ 0x00789890 ====

void FUN_00789890(void)

{
  int iVar1;
  int *in_ECX;
  undefined1 auStack_e0 [4];
  undefined1 uStack_dc;
  undefined4 uStack_d4;
  undefined4 uStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined1 auStack_c4 [4];
  undefined1 uStack_c0;
  undefined4 uStack_b8;
  uint uStack_b4;
  undefined1 *puStack_b0;
  undefined4 uStack_ac;
  undefined1 auStack_a8 [4];
  undefined1 uStack_a4;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined1 *puStack_94;
  undefined4 uStack_90;
  undefined1 auStack_8c [4];
  undefined1 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 *puStack_78;
  undefined4 uStack_74;
  undefined1 auStack_70 [4];
  uint uStack_6c;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined1 *puStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 uStack_50;
  undefined4 uStack_44;
  char *pcStack_40;
  undefined4 uStack_3c;
  undefined1 uStack_34;
  undefined1 *puStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  iVar1 = *DAT_00b5ac48;
  uStack_14 = 0x7898a3;
  uStack_14 = (**(code **)(*in_ECX + 0x10))();
  uStack_18 = 0x7898a9;
  (**(code **)(iVar1 + 0x10))();
  iStack_1c = in_ECX[9];
  uStack_18 = 0;
  uStack_20 = 0x7898bb;
  (**(code **)(*DAT_00b5ac54 + 8))();
  uStack_3c = 0xe;
  uStack_20 = 0xf;
  uStack_24 = 0;
  pcStack_40 = s_ProcessMessage_009f7de8;
  uStack_34 = 0;
  uStack_44 = 0x7898de;
  FUN_00401740();
  uStack_3c = 0x7898e9;
  (**(code **)(*DAT_00b5ac54 + 0x30))();
  puStack_2c = (undefined1 *)&uStack_54;
  uStack_58 = 0xffffffff;
  puStack_5c = (undefined1 *)0x0;
  uStack_3c = 0xf;
  pcStack_40 = (char *)0x0;
  uStack_60 = uStack_24;
  uStack_50 = 0;
  uStack_64 = 0x789908;
  FUN_00401660();
  uStack_58 = 0x789913;
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  pcStack_40 = auStack_70;
  uStack_74 = 0xffffffff;
  puStack_78 = (undefined1 *)0x0;
  uStack_58 = 0xf;
  puStack_5c = (undefined1 *)0x0;
  uStack_7c = uStack_3c;
  uStack_6c = uStack_6c & 0xffffff00;
  uStack_80 = 0x789932;
  FUN_00401660();
  uStack_74 = 0x78993d;
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  puStack_5c = auStack_8c;
  uStack_90 = 0xffffffff;
  puStack_94 = (undefined1 *)0x0;
  uStack_74 = 0xf;
  puStack_78 = (undefined1 *)0x0;
  uStack_98 = uStack_54;
  uStack_88 = 0;
  uStack_9c = 0x78995c;
  FUN_00401660();
  uStack_90 = 0x789967;
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  puStack_78 = auStack_a8;
  uStack_ac = 0xffffffff;
  uStack_90 = 0xf;
  puStack_94 = (undefined1 *)0x0;
  uStack_a4 = 0;
  puStack_b0 = (undefined1 *)0x0;
  uStack_b4 = uStack_6c;
  uStack_b8 = 0x789986;
  FUN_00401660();
  uStack_ac = 0x789991;
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  puStack_94 = auStack_c4;
  uStack_c8 = 0xffffffff;
  uStack_cc = 0;
  uStack_ac = 0xf;
  puStack_b0 = (undefined1 *)0x0;
  uStack_d0 = uStack_84;
  uStack_c0 = 0;
  uStack_d4 = 0x7899b0;
  FUN_00401660();
  uStack_c8 = 0x7899bb;
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  puStack_b0 = auStack_e0;
  uStack_c8 = 0xf;
  uStack_cc = 0;
  uStack_dc = 0;
  FUN_00401660(uStack_9c,0,0xffffffff);
  (**(code **)(*DAT_00b5ac54 + 0x44))();
  (**(code **)(*DAT_00b5ac54 + 8))(in_ECX[9],6);
  (**(code **)(*DAT_00b5ac54 + 0x3c))();
  return;
}


// ==== FUN_00789a10 @ 0x00789a10 ====

void FUN_00789a10(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00997ea4;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f7e34;
  iVar1 = *DAT_00b5a7a4;
  local_4 = 1;
  uVar2 = FUN_007896f0();
  (**(code **)(iVar1 + 8))(uVar2);
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    *in_ECX = &PTR_FUN_009f7e10;
    ExceptionList = in_ECX;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00789a90 @ 0x00789a90 ====

void FUN_00789a90(byte param_1)

{
  void *in_ECX;
  
  FUN_00789a10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00789ab0 @ 0x00789ab0 ====

void FUN_00789ab0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7e58;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00789ad0 @ 0x00789ad0 ====

void FUN_00789ad0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7e58;
  return;
}


// ==== FUN_00789ae0 @ 0x00789ae0 ====

void FUN_00789ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7e70;
  return;
}


// ==== FUN_00789af0 @ 0x00789af0 ====

undefined4 FUN_00789af0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uStack00000000;
  
  if ((param_1 == 0) || (DAT_00b5acd8 == (int *)0x0)) {
    return 0;
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 0x18));
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 == 2) {
      piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
      piVar1 = (int *)(**(code **)(*piVar1 + 0x24))();
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x1c))();
        (**(code **)(*piVar1 + 0x2c))(&uStack00000000);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00789b90 @ 0x00789b90 ====

undefined4 FUN_00789b90(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 uStack00000000;
  
  if ((param_1 == 0) || (DAT_00b5acd8 == (int *)0x0)) {
    return 0;
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 0x18));
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 == 2) {
      piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
      piVar1 = (int *)(**(code **)(*piVar1 + 0x24))();
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 0x1c))();
        (**(code **)(*piVar1 + 0x2c))(&uStack00000000);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00789c30 @ 0x00789c30 ====

uint FUN_00789c30(int param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  uint in_EAX;
  int *piVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 uStack_8;
  
  if ((param_1 == 0) || (DAT_00b5acd8 == (int *)0x0)) {
    return in_EAX & 0xffffff00;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 0x18));
  uVar4 = 0;
  if (piVar3 != (int *)0x0) {
    uVar4 = (**(code **)(*piVar3 + 0xc))();
    if (uVar4 == 2) {
      piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
      piVar3 = (int *)(**(code **)(*piVar3 + 0x24))();
      uVar4 = 0;
      if (piVar3 != (int *)0x0) {
        puVar5 = (undefined4 *)(**(code **)(*piVar3 + 0x1c))();
        uVar2 = *puVar5;
        uVar1 = *(undefined2 *)(puVar5 + 1);
        *(undefined4 *)(param_1 + 8) = 0;
        uStack_8 = CONCAT31(uStack_8._1_3_,(char)uVar1);
        *(undefined4 *)(param_1 + 0xc) = uStack_8;
        *(undefined4 *)(param_1 + 0x10) = 0;
        *(short *)(param_1 + 0x14) = (short)((uint)uVar2 >> 0x10);
        return CONCAT31((uint3)(byte)((uint)uVar2 >> 0x18),1);
      }
    }
  }
  return uVar4 & 0xffffff00;
}


// ==== FUN_00789ce0 @ 0x00789ce0 ====

void FUN_00789ce0(byte param_1)

{
  void *in_ECX;
  
  FUN_00789ad0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00789d00 @ 0x00789d00 ====

void FUN_00789d00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7e58;
  return;
}


// ==== FUN_00789d10 @ 0x00789d10 ====

void FUN_00789d10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7e88;
  return;
}


// ==== FUN_00789d20 @ 0x00789d20 ====

undefined4 FUN_00789d20(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 auStack_82 [2];
  undefined4 auStack_80 [31];
  
  if ((param_1 != 0) && (DAT_00b5acd8 != (int *)0x0)) {
    piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 0x18));
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0xc))();
      if (iVar2 == 0) {
        piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
        piVar1 = (int *)(**(code **)(*piVar1 + 0x24))();
        if (piVar1 != (int *)0x0) {
          iVar2 = *piVar1;
          uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
          puVar4 = (undefined4 *)(**(code **)(iVar2 + 0x1c))(uVar3);
          puVar5 = (undefined4 *)(auStack_82 + -6);
          for (iVar2 = 0x1e; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          (**(code **)(*piVar1 + 0x38))(auStack_82 + -10);
          return 1;
        }
      }
    }
  }
  return 0;
}


// ==== FUN_00789dd0 @ 0x00789dd0 ====

undefined4 FUN_00789dd0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 auStack_82 [2];
  undefined4 auStack_80 [31];
  
  if ((param_1 != 0) && (DAT_00b5acd8 != (int *)0x0)) {
    piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 0x18));
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0xc))();
      if (iVar2 == 0) {
        piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
        piVar1 = (int *)(**(code **)(*piVar1 + 0x24))();
        if (piVar1 != (int *)0x0) {
          iVar2 = *piVar1;
          uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
          puVar4 = (undefined4 *)(**(code **)(iVar2 + 0x1c))(uVar3);
          puVar5 = (undefined4 *)(auStack_82 + -6);
          for (iVar2 = 0x1e; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          (**(code **)(*piVar1 + 0x38))(auStack_82 + -10);
          return 1;
        }
      }
    }
  }
  return 0;
}


// ==== FUN_00789e70 @ 0x00789e70 ====

uint FUN_00789e70(float *param_1)

{
  uint in_EAX;
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  float fStack_8c;
  undefined4 auStack_88 [21];
  int iStack_34;
  undefined2 uStack_30;
  byte bStack_2e;
  
  if ((param_1 != (float *)0x0) && (DAT_00b5acd8 != (int *)0x0)) {
    piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1[6]);
    in_EAX = 0;
    if (piVar1 != (int *)0x0) {
      in_EAX = (**(code **)(*piVar1 + 0xc))();
      if (in_EAX == 0) {
        piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
        piVar1 = (int *)(**(code **)(*piVar1 + 0x24))();
        in_EAX = 0;
        if (piVar1 != (int *)0x0) {
          iVar4 = *piVar1;
          uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
          puVar3 = (undefined4 *)(**(code **)(iVar4 + 0x1c))(uVar2);
          puVar5 = auStack_88;
          for (iVar4 = 0x1e; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar5 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar5 = puVar5 + 1;
          }
          *param_1 = (float)iStack_34;
          param_1[1] = 0.0;
          fStack_8c = (float)(uint)bStack_2e;
          param_1[2] = 0.0;
          param_1[3] = fStack_8c;
          param_1[4] = 0.0;
          *(undefined2 *)(param_1 + 5) = uStack_30;
          return CONCAT31((uint3)(byte)((ushort)uStack_30 >> 8),1);
        }
      }
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00789f50 @ 0x00789f50 ====

void FUN_00789f50(byte param_1)

{
  void *in_ECX;
  
  FUN_00789d00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00789f70 @ 0x00789f70 ====

void FUN_00789f70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7e58;
  return;
}


// ==== FUN_00789f80 @ 0x00789f80 ====

void FUN_00789f80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7ea0;
  return;
}


// ==== FUN_00789f90 @ 0x00789f90 ====

undefined4 FUN_00789f90(int param_1)

{
  short sVar1;
  short sVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *unaff_retaddr;
  
  piVar5 = DAT_00b5a97c;
  if (param_1 == 0) {
    return 0;
  }
  if (DAT_00b5a97c == (int *)0x0) {
    return 0;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
  if ((piVar3 == (int *)0x0) || (piVar3[0x2b] != *(int *)(param_1 + 0x18))) {
    return 0;
  }
  (**(code **)(*piVar3 + 0x98))(*(undefined2 *)(param_1 + 0x10));
  if ((int *)piVar3[0x1f] == (int *)0x0) {
    return 0;
  }
  piVar3 = (int *)(**(code **)(*(int *)piVar3[0x1f] + 0x14))();
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  sVar2 = (**(code **)(*piVar3 + 0x20))();
  sVar1 = *(short *)(param_1 + 0x14);
  if (sVar1 == 0) {
    if (sVar2 == 0) goto LAB_0078a0a8;
    puVar4 = operator_new(0x10);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
      uRam00000004 = 5;
      uRam00000008 = 0;
      uRam0000000c = 0;
    }
    else {
      *puVar4 = &PTR_FUN_009b9b60;
      puVar4[1] = 5;
      puVar4[2] = 0;
      puVar4[3] = 0;
    }
  }
  else {
    if ((sVar2 != 0) || (sVar1 == 0)) goto LAB_0078a0a8;
    puVar4 = operator_new(0x10);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_009b9b60;
    }
    puVar4[1] = 6;
    puVar4[2] = 0;
    puVar4[3] = 0;
  }
  FUN_00797a20(puVar4);
  piVar5 = unaff_retaddr;
LAB_0078a0a8:
  (**(code **)(*piVar3 + 0x24))(sVar1);
  (**(code **)(*piVar5 + 0x34))();
  return 1;
}


// ==== FUN_0078a0d0 @ 0x0078a0d0 ====

undefined4 FUN_0078a0d0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  piVar1 = DAT_00b5a97c;
  if (param_1 == 0) {
    return 0;
  }
  if (DAT_00b5a97c != (int *)0x0) {
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    if (((iVar2 != 0) && (*(int *)(iVar2 + 0xac) == *(int *)(param_1 + 0x18))) &&
       (*(int **)(iVar2 + 0x7c) != (int *)0x0)) {
      piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x7c) + 0x14))();
      if (piVar3 == (int *)0x0) {
        return 0;
      }
      if (*(char *)(param_1 + 0xc) == '\x01') {
        iVar2 = *piVar3;
        uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        (**(code **)(iVar2 + 0x14))(uVar4);
        (**(code **)(*piVar1 + 0x30))();
        return 1;
      }
      (**(code **)(*piVar3 + 0x1c))();
      (**(code **)(*piVar1 + 0x30))();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0078a170 @ 0x0078a170 ====

uint FUN_0078a170(undefined4 *param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  uint in_EAX;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uStack_8;
  
  if ((param_1 == (undefined4 *)0x0) || (DAT_00b5a97c == 0)) {
    return in_EAX & 0xffffff00;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
  if ((piVar3 == (int *)0x0) || (piVar3[0x2b] != param_1[6])) {
    return (uint)piVar3 & 0xffffff00;
  }
  piVar4 = piVar3;
  if ((int *)piVar3[0x14] != (int *)0x0) {
    iVar7 = *(int *)piVar3[0x14];
    uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar6 = (int *)(**(code **)(iVar7 + 0x14))(uVar5);
    piVar4 = (int *)0x0;
    if (piVar6 != (int *)0x0) {
      iVar7 = (**(code **)(*piVar6 + 0x18))();
      piVar4 = *(int **)(iVar7 + 8);
      iVar7 = (**(code **)(*piVar6 + 0x18))();
      uVar5 = *(undefined4 *)(iVar7 + 0x14);
      *param_1 = piVar4;
      param_1[1] = uVar5;
      if ((int *)piVar3[0x1f] != (int *)0x0) {
        piVar6 = (int *)(**(code **)(*(int *)piVar3[0x1f] + 0x14))();
        piVar4 = (int *)0x0;
        if (piVar6 != (int *)0x0) {
          iVar7 = (**(code **)(*piVar6 + 8))();
          uStack_8 = CONCAT31((int3)((uint)uVar5 >> 8),*(undefined1 *)(iVar7 + 10));
          puVar8 = (undefined4 *)(**(code **)(*piVar6 + 8))();
          param_1[2] = *puVar8;
          param_1[3] = uStack_8;
          iVar7 = (**(code **)(*piVar3 + 0x74))();
          uVar1 = *(ushort *)(iVar7 + 0x40);
          iVar7 = (**(code **)(*piVar6 + 8))();
          uVar2 = *(undefined2 *)(iVar7 + 8);
          param_1[4] = (uint)uVar1;
          *(undefined2 *)(param_1 + 5) = uVar2;
          return CONCAT31((int3)(CONCAT22((short)((uint)iVar7 >> 0x10),uVar2) >> 8),1);
        }
      }
    }
  }
  return (uint)piVar4 & 0xffffff00;
}


// ==== FUN_0078a290 @ 0x0078a290 ====

void FUN_0078a290(byte param_1)

{
  void *in_ECX;
  
  FUN_00789f70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078a2b0 @ 0x0078a2b0 ====

void FUN_0078a2b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7f0c;
  return;
}


// ==== FUN_0078a2c0 @ 0x0078a2c0 ====

void FUN_0078a2c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7f0c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078a2e0 @ 0x0078a2e0 ====

void FUN_0078a2e0(void)

{
  return;
}


// ==== FUN_0078a2f0 @ 0x0078a2f0 ====

void FUN_0078a2f0(void)

{
  return;
}


// ==== FUN_0078a300 @ 0x0078a300 ====

void FUN_0078a300(void)

{
  return;
}


// ==== FUN_0078a310 @ 0x0078a310 ====

undefined4 FUN_0078a310(void)

{
  return 0;
}


// ==== FUN_0078a370 @ 0x0078a370 ====

void FUN_0078a370(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 0xc))();
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x34);
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x20))(param_1);
  if (piVar2 == (int *)0x0) {
    return;
  }
  (**(code **)(*piVar2 + 0x6c))();
  return;
}


// ==== FUN_0078a3b0 @ 0x0078a3b0 ====

void FUN_0078a3b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 0xc))();
  if ((iVar1 == 0) || (*(int **)(iVar1 + 0x34) == (int *)0x0)) {
    return;
  }
  (**(code **)(**(int **)(iVar1 + 0x34) + 0xc))();
  FUN_0073c600(DAT_00b5b1b8);
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009ef5e0;
  }
  FUN_00797a20(puVar2);
  (**(code **)(*DAT_00b5a78c + 0x60))(0);
  (**(code **)(*DAT_00b5a790 + 8))();
  (**(code **)(*DAT_00b5ad0c + 0x14))();
  (**(code **)(*DAT_00b5acd4 + 4))(0);
                    /* WARNING: Could not recover jumptable at 0x0078a43e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5af2c + 8))(0);
  return;
}


// ==== FUN_0078a450 @ 0x0078a450 ====

void FUN_0078a450(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x51a0002;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_0078a4b0 @ 0x0078a4b0 ====

void FUN_0078a4b0(undefined2 *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)0x0;
  if (iVar1 != 0) {
    piVar2 = *(int **)(iVar1 + 0x1c);
  }
  iVar1 = (**(code **)(*piVar2 + 0x1c))();
  if (iVar1 == 0) {
    puVar3 = operator_new(4);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = &PTR_FUN_009f7f4c;
    }
    FUN_00797a20(puVar3);
    *(undefined2 *)(in_ECX + 8) = *param_1;
    *(undefined1 *)(in_ECX + 10) = *(undefined1 *)(param_1 + 1);
  }
  return;
}


// ==== FUN_0078a510 @ 0x0078a510 ====

undefined4 FUN_0078a510(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 0xc))();
  if ((iVar1 == 0) || (*(int **)(iVar1 + 0x34) == (int *)0x0)) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0078a52d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(int **)(iVar1 + 0x34) + 0x34))();
  return uVar2;
}


// ==== FUN_0078a530 @ 0x0078a530 ====

undefined4 FUN_0078a530(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 0xc))();
  if ((iVar1 == 0) || (*(int **)(iVar1 + 0x34) == (int *)0x0)) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0078a54d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(int **)(iVar1 + 0x34) + 0x38))();
  return uVar2;
}


// ==== FUN_0078a550 @ 0x0078a550 ====

undefined4 FUN_0078a550(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 0xc))();
  if ((iVar1 == 0) || (*(int **)(iVar1 + 0x34) == (int *)0x0)) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0078a56f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(int **)(iVar1 + 0x34) + 0x18))();
  return uVar2;
}


// ==== FUN_0078a580 @ 0x0078a580 ====

void FUN_0078a580(char param_1)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x51a000c;
    *(undefined2 *)((int)pvVar3 + 6) = 0x18;
    iVar4 = FUN_004244d0();
    *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(in_ECX + 4);
    *(undefined2 *)(iVar4 + 0x14) = *(undefined2 *)(in_ECX + 8);
    *(undefined1 *)(iVar4 + 0x16) = *(undefined1 *)(in_ECX + 10);
    *(bool *)(iVar4 + 0x17) = param_1 == '\0';
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_0078a610 @ 0x0078a610 ====

void FUN_0078a610(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x1c) != (int *)0x0)) {
    iVar1 = (**(code **)(**(int **)(iVar1 + 0x1c) + 0x1c))();
    FUN_0078a580(in_ECX + 8,iVar1 == 0);
  }
  return;
}


// ==== FUN_0078a650 @ 0x0078a650 ====

void FUN_0078a650(undefined2 *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 8) = *param_1;
  *(undefined1 *)(in_ECX + 10) = *(undefined1 *)(param_1 + 1);
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)0x0;
  if (iVar1 != 0) {
    piVar2 = *(int **)(iVar1 + 0x1c);
  }
  iVar1 = (**(code **)(*piVar2 + 0x1c))();
  if (iVar1 == 0) {
    FUN_0078a580((undefined2 *)(in_ECX + 8),0);
  }
  return;
}


// ==== FUN_0078a6a0 @ 0x0078a6a0 ====

void FUN_0078a6a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f7f64;
  DAT_00b5b1ac = 0;
  if ((uint)in_ECX[10] < 0x10) {
    in_ECX[10] = 0xf;
    in_ECX[9] = 0;
    *(undefined1 *)(in_ECX + 5) = 0;
    *in_ECX = &PTR_FUN_009f7f0c;
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_0078a6e0 @ 0x0078a6e0 ====

void FUN_0078a6e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  int *piVar1;
  int *piVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00997ec3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f7f64;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[3] = param_1;
  local_4 = 1;
  piVar1 = in_ECX + 5;
  if ((uint)in_ECX[10] < 0x10) {
    piVar2 = piVar1;
  }
  else {
    piVar2 = (int *)*piVar1;
  }
  if (0xf < (uint)in_ECX[10]) {
    piVar1 = (int *)*piVar1;
  }
  FUN_004bdb30(&param_1,piVar1,in_ECX[9] + (int)piVar2);
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b1ac = (undefined4 *)0x0;
  }
  else {
    DAT_00b5b1ac = in_ECX;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0078a790 @ 0x0078a790 ====

int FUN_0078a790(int param_1)

{
  int in_ECX;
  
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(in_ECX + 0x10,0,0xffffffff);
  return param_1;
}


// ==== FUN_0078a7c0 @ 0x0078a7c0 ====

void FUN_0078a7c0(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int unaff_retaddr;
  undefined1 *puStack_9c;
  undefined1 auStack_98 [16];
  undefined4 uStack_88;
  undefined4 uStack_84;
  int iStack_80;
  int iStack_7c;
  int iStack_78;
  undefined4 uStack_74;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [28];
  void *pvStack_1c;
  void *pvStack_14;
  undefined4 uStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997ef5;
  puStack_c = ExceptionList;
  piVar6 = (int *)0x0;
  uStack_74 = 0;
  iStack_78 = 0x78a7ea;
  ExceptionList = &puStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x17)) {
  case 1:
    iStack_78 = 0x6e005b;
    iStack_7c = 0;
    iStack_80 = 0x78a905;
    iStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x78a90f;
    FUN_00765c50();
    puStack_8 = auStack_98;
    puStack_9c = auStack_50;
    uStack_10 = 3;
    FUN_00765c50();
    puStack_9c = (undefined1 *)0xc;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 2:
    iStack_78 = 0x78a966;
    iVar3 = (**(code **)(*DAT_00b5a980 + 0xc))();
    if (iVar3 == 0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = *(int **)(iVar3 + 0x34);
    }
    iStack_78 = unaff_retaddr + 0x14;
    iStack_7c = 0x78a97a;
    iStack_7c = (**(code **)(*piVar6 + 0x24))();
    if (iStack_7c != 0) {
      iStack_80 = 1;
      uStack_84 = 0x78a98c;
      (**(code **)(*DAT_00b5a730 + 0x10))();
    }
    iStack_7c = 0x78a997;
    (**(code **)(*DAT_00b5adc4 + 0x4c))();
    iStack_7c = 0x6e003b;
    iStack_80 = 0;
    uStack_84 = 0x78a9a8;
    uStack_84 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_88 = 0x78a9b2;
    FUN_00765c50();
    puStack_c = (undefined1 *)&puStack_9c;
    pvStack_14 = (void *)0x4;
    FUN_00765c50(auStack_38);
    (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 3:
    iStack_78 = 0x6e0036;
    iStack_7c = 0;
    iStack_80 = 0x78a816;
    iStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x78a820;
    FUN_00765c50();
    uStack_10 = 0;
    break;
  case 4:
    iStack_78 = 0x6e0037;
    iStack_7c = 0;
    iStack_80 = 0x78a83a;
    iStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x78a844;
    FUN_00765c50();
    puStack_8 = auStack_98;
    puStack_9c = auStack_50 + -0x1c;
    uStack_10 = 1;
    FUN_00765c50();
    puStack_9c = (undefined1 *)0xc;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 5:
    iStack_78 = 0x6e0038;
    iStack_7c = 0;
    iStack_80 = 0x78a8a1;
    iStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x78a8ab;
    FUN_00765c50();
    uStack_10 = 2;
    break;
  default:
    iStack_78 = 0x78aa09;
    iVar3 = (**(code **)(*DAT_00b5a980 + 0xc))();
    if (iVar3 != 0) {
      piVar6 = *(int **)(iVar3 + 0x34);
    }
    iVar3 = unaff_retaddr + 0x14;
    iStack_7c = 0x78aa1b;
    iStack_78 = iVar3;
    iVar4 = (**(code **)(*piVar6 + 0x24))();
    if (iVar4 != 0) {
      iStack_7c = 0x78aa30;
      iStack_80 = (**(code **)(*DAT_00b5a980 + 8))();
      if (iStack_80 != 0) {
        iStack_7c = *(undefined4 *)(unaff_retaddr + 0x10);
        uStack_84 = 0x78aa46;
        iStack_4 = iStack_80;
        FUN_00827bf0();
        if (*(char *)(unaff_retaddr + 0x18) == '\0') {
          iStack_7c = 0x78aa5b;
          iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
          if ((iVar5 == 0) || (piVar1 = *(int **)(iVar5 + 0x1c), piVar1 == (int *)0x0)) {
LAB_0078aa9a:
            uStack_84 = 0x78aaa3;
            iStack_80 = iVar3;
            iStack_7c = iVar4;
            (**(code **)(*piVar6 + 0x1c))();
            ExceptionList = pvStack_1c;
            return;
          }
          iStack_7c = 0x78aa6d;
          iVar5 = (**(code **)(*piVar1 + 0x1c))();
          if (iVar5 != 0) {
            uStack_84 = 0x78aa7a;
            iStack_80 = iVar3;
            iStack_7c = iVar4;
            (**(code **)(*piVar6 + 0x1c))();
            ExceptionList = pvStack_1c;
            return;
          }
          iStack_80 = 0x78aa96;
          iStack_7c = iVar4;
          cVar2 = (**(code **)(*piVar1 + 0x14))();
          if (cVar2 == '\0') goto LAB_0078aa9a;
        }
        else if (*(char *)(unaff_retaddr + 0x18) == '\x01') {
          iStack_80 = iStack_4;
          uStack_84 = 0x78aac8;
          iStack_7c = iVar4;
          cVar2 = FUN_00827e80();
          if (cVar2 == '\0') {
            uStack_84 = 0x78aad8;
            iStack_80 = iVar3;
            iStack_7c = iVar4;
            (**(code **)(*piVar6 + 0x1c))();
            ExceptionList = pvStack_1c;
            return;
          }
        }
        iStack_7c = 0x78aaf8;
        (**(code **)(*DAT_00b5a790 + 8))();
        iStack_7c = 0x78ab03;
        (**(code **)(*DAT_00b5a790 + 4))();
        iStack_7c = 0x78ab0e;
        (**(code **)(*DAT_00b5adc4 + 0x4c))();
      }
    }
    ExceptionList = pvStack_14;
    return;
  }
  puStack_8 = auStack_98;
  puStack_9c = auStack_50 + -0x1c;
  FUN_00765c50();
  puStack_9c = (undefined1 *)0xc;
  (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0078ab40 @ 0x0078ab40 ====

void FUN_0078ab40(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *pvStack_24;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00997f07;
  local_c = ExceptionList;
  if (((*(int *)(param_1 + 0x10) == *(int *)(in_ECX + 4)) &&
      (ExceptionList = &local_c, iVar1 = (**(code **)(*DAT_00b5a980 + 0xc))(), iVar1 != 0)) &&
     (*(int **)(iVar1 + 0x34) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x34) + 0xc))();
    uStack_38 = 0x78aba0;
    FUN_0073c600();
    uStack_38 = 0x78aba7;
    puVar2 = operator_new(4);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009ef5e0;
    }
    uStack_38 = 0x78abbe;
    FUN_00797a20();
    uStack_38 = 0;
    uStack_3c = 0x78abd2;
    uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_3c = 0xffffffff;
    uStack_40 = 0;
    uStack_48 = 0x78abf0;
    FUN_00401660();
    puStack_4 = auStack_54;
    uStack_3c = 0xf;
    uStack_40 = 0;
    local_c = (void *)0x0;
    uStack_50 = 0;
    FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
    (**(code **)(*DAT_00b5a78c + 0x60))(0);
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    (**(code **)(*DAT_00b5a790 + 8))();
    if (0xf < uStack_10) {
      uStack_38 = 0x78ac54;
      _free(pvStack_24);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0078ac70 @ 0x0078ac70 ====

void FUN_0078ac70(void)

{
  char cVar1;
  int *piVar2;
  undefined1 auStack_64 [4];
  undefined1 uStack_60;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 auStack_2e [6];
  void *pvStack_28;
  uint uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997f19;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a980 + 0xc))();
  if (piVar2 != (int *)0x0) {
    FUN_00424520();
    cVar1 = (**(code **)(*piVar2 + 0x20))();
    if (cVar1 == '\0') {
      uStack_48 = 0;
      uStack_4c = 0x78ace3;
      uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_4c = 0xffffffff;
      uStack_50 = 0;
      uStack_58 = 0x78ad01;
      FUN_00401660();
      puStack_8 = auStack_64;
      uStack_4c = 0xf;
      uStack_50 = 0;
      uStack_60 = 0;
      FUN_00401660(auStack_2e + -6,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      puStack_8 = (undefined1 *)0xffffffff;
      if (0xf < uStack_14) {
        uStack_48 = 0x78ad4a;
        _free(pvStack_28);
        return;
      }
    }
    (**(code **)(*DAT_00b5adc4 + 0x4c))();
    (**(code **)(*DAT_00b5a790 + 8))();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0078ad90 @ 0x0078ad90 ====

undefined4 FUN_0078ad90(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x51a0008) {
    if (uVar1 == 0x51a0007) {
      FUN_0078ab40(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x2040013) {
      FUN_0078ac70(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 == 0x51a0003) {
      FUN_0078a3b0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else if (uVar1 == 0x51a000d) {
    FUN_0078a7c0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_0078ae10 @ 0x0078ae10 ====

undefined4 FUN_0078ae10(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0078ad90(param_1);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  else {
    if (iVar2 != 0x70300006) {
      return 0;
    }
    FUN_0078a610(param_1);
  }
  return 1;
}


// ==== FUN_0078ae50 @ 0x0078ae50 ====

undefined4 FUN_0078ae50(void)

{
  return 0x70300005;
}


// ==== FUN_0078ae60 @ 0x0078ae60 ====

void FUN_0078ae60(byte param_1)

{
  void *in_ECX;
  
  FUN_0078a6a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078ae80 @ 0x0078ae80 ====

undefined4 FUN_0078ae80(undefined4 param_1)

{
  FUN_00401830(&DAT_0099cf70);
  return param_1;
}


// ==== FUN_0078aeb0 @ 0x0078aeb0 ====

void FUN_0078aeb0(void)

{
  return;
}


// ==== FUN_0078aec0 @ 0x0078aec0 ====

void FUN_0078aec0(void)

{
  return;
}


// ==== FUN_0078aed0 @ 0x0078aed0 ====

void FUN_0078aed0(void)

{
  return;
}


// ==== FUN_0078aee0 @ 0x0078aee0 ====

int FUN_0078aee0(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_0078af30 @ 0x0078af30 ====

void FUN_0078af30(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x51a0006;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_0078af90 @ 0x0078af90 ====

undefined4 FUN_0078af90(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 == 0) || (*(int **)(iVar1 + 0x34) == (int *)0x0)) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0078afad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(int **)(iVar1 + 0x34) + 0x34))();
  return uVar2;
}


// ==== FUN_0078afb0 @ 0x0078afb0 ====

undefined4 FUN_0078afb0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 == 0) || (*(int **)(iVar1 + 0x34) == (int *)0x0)) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0078afcd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(int **)(iVar1 + 0x34) + 0x38))();
  return uVar2;
}


// ==== FUN_0078afd0 @ 0x0078afd0 ====

undefined4 FUN_0078afd0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 == 0) || (*(int **)(iVar1 + 0x34) == (int *)0x0)) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0078afef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(int **)(iVar1 + 0x34) + 0x18))();
  return uVar2;
}


// ==== FUN_0078b000 @ 0x0078b000 ====

undefined4 FUN_0078b000(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x34) != (int *)0x0)) {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x34) + 0x3c))();
    if (piVar2 != (int *)0x0) {
      puVar3 = (undefined4 *)(**(code **)(*piVar2 + 4))();
      return *puVar3;
    }
  }
  return 0;
}


// ==== FUN_0078b030 @ 0x0078b030 ====

undefined4 FUN_0078b030(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x34) != (int *)0x0)) {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x34) + 0x20))(param_1);
    if (piVar2 != (int *)0x0) {
      uVar3 = (**(code **)(*piVar2 + 0x6c))();
      return uVar3;
    }
  }
  return 0;
}


// ==== FUN_0078b070 @ 0x0078b070 ====

void FUN_0078b070(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f802c;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[1] = param_1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b1b0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b1b0 = in_ECX;
  return;
}


// ==== FUN_0078b0b0 @ 0x0078b0b0 ====

void FUN_0078b0b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f802c;
  DAT_00b5b1b0 = 0;
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[9] = 0xf;
    in_ECX[8] = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    *in_ECX = &PTR_FUN_009f7f0c;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_0078b0f0 @ 0x0078b0f0 ====

void FUN_0078b0f0(void)

{
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997f38;
  pvStack_c = ExceptionList;
  uStack_34 = (undefined1 *)0x6e0068;
  uStack_38 = 0;
  uStack_3c = 0x78b11c;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x78b139;
  FUN_00401660();
  uStack_34 = auStack_54;
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_c = (void *)0x0;
  uStack_50 = 0;
  FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
  if (uStack_38 < 0x10) {
    ExceptionList = uStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_0078b1a0 @ 0x0078b1a0 ====

void FUN_0078b1a0(void)

{
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997f4a;
  pvStack_c = ExceptionList;
  uStack_34 = (undefined1 *)0x6e0068;
  uStack_38 = 0;
  uStack_3c = 0x78b1cc;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x78b1e9;
  FUN_00401660();
  uStack_34 = auStack_54;
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_c = (void *)0x0;
  uStack_50 = 0;
  FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
  if (uStack_38 < 0x10) {
    ExceptionList = uStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_0078b250 @ 0x0078b250 ====

void FUN_0078b250(undefined1 param_1,void *param_2)

{
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00997f5c;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00401660(&param_1,0,0xffffffff);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_0078b2b0 @ 0x0078b2b0 ====

void FUN_0078b2b0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_7e [6];
  void *pvStack_78;
  uint uStack_64;
  void *pvStack_5c;
  uint uStack_48;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997f86;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (*(int *)(param_1 + 0x10) == iVar2) {
    (**(code **)(*DAT_00b5a78c + 0x60))();
    FUN_0073c600();
    (**(code **)(*DAT_00b5af2c + 8))();
    cVar1 = *(char *)(param_1 + 0x14);
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5adc4 + 0x4c))();
      (**(code **)(*DAT_00b5acd4 + 4))();
      iVar2 = *DAT_00b5a97c;
      (**(code **)(*DAT_00b5a6e4 + 8))();
      (**(code **)(iVar2 + 0x38))();
      FUN_0073c6f0();
      (**(code **)(*DAT_00b5ad0c + 0x14))();
    }
    else if (cVar1 == '\x01') {
      FUN_00401830();
      uStack_4 = 0;
      FUN_00796d50();
      uStack_4 = 0xffffffff;
      if (0xf < uStack_48) {
        _free(pvStack_5c);
        return;
      }
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      pvStack_c = (void *)0x1;
      FUN_00401660(auStack_7e + -6,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
      if (0xf < uStack_64) {
        _free(pvStack_78);
        return;
      }
    }
    else if (cVar1 == '\x02') {
      FUN_00401830();
      uStack_4 = 2;
      FUN_00796d50();
      uStack_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0078b4e0 @ 0x0078b4e0 ====

void FUN_0078b4e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined1 auStack_78 [12];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  int iStack_58;
  undefined1 auStack_46 [58];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997fa0;
  local_c = ExceptionList;
  if (*(char *)(param_1 + 0x17) == '\0') {
    iStack_58 = 0x78b515;
    ExceptionList = &local_c;
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    if ((iVar1 != 0) && (piVar3 = *(int **)(iVar1 + 0x34), piVar3 != (int *)0x0)) {
      iStack_58 = param_1 + 0x14;
      uStack_5c = 0x78b533;
      piVar2 = (int *)(**(code **)(*piVar3 + 0x24))();
      if (piVar2 != (int *)0x0) {
        iStack_58 = 0x6e006a;
        uStack_5c = 0;
        iStack_60 = 0x78b54e;
        uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
        iStack_60 = 0xffffffff;
        uStack_64 = 0;
        uStack_6c = 0x78b56b;
        FUN_00401660();
        local_c = (void *)0x0;
        iStack_60 = 0x78b576;
        iStack_60 = (**(code **)(*piVar2 + 0x2c))();
        iStack_60 = iStack_60 + 0x32;
        uStack_64 = 0x78b583;
        FUN_00401830();
        local_c = (void *)CONCAT31(local_c._1_3_,1);
        FUN_00401660(auStack_46 + -6,0,0xffffffff);
        FUN_00404230(auStack_78);
        (**(code **)(*DAT_00b5ad0c + 0x28))();
        (**(code **)(*DAT_00b5a730 + 0x10))();
        piVar3 = (int *)(**(code **)(*piVar3 + 0x3c))();
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0xc))();
          (**(code **)(*DAT_00b5adc4 + 0x4c))();
          (**(code **)(*DAT_00b5a790 + 4))();
        }
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0078b650 @ 0x0078b650 ====

undefined4 FUN_0078b650(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x51a0007) {
    FUN_0078b2b0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x51a000d) {
    FUN_0078b4e0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_0078b6a0 @ 0x0078b6a0 ====

undefined4 FUN_0078b6a0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if ((iVar2 != 0x40001) && (iVar2 == 0x50011)) {
    cVar1 = FUN_0078b650(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0078b6e0 @ 0x0078b6e0 ====

void FUN_0078b6e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0078b0b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078b700 @ 0x0078b700 ====

void FUN_0078b700(void)

{
  return;
}


// ==== FUN_0078b710 @ 0x0078b710 ====

void FUN_0078b710(void)

{
  return;
}


// ==== FUN_0078b730 @ 0x0078b730 ====

void FUN_0078b730(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f81fc;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  in_ECX[3] = param_1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b1b4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b1b4 = in_ECX;
  return;
}


// ==== FUN_0078b770 @ 0x0078b770 ====

void FUN_0078b770(void)

{
  undefined4 *puVar1;
  
  FUN_0073c600(DAT_00b5b1b8);
  (**(code **)(*DAT_00b5a78c + 0x60))(0);
  (**(code **)(*DAT_00b5ad0c + 0x14))();
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009ef5e0;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0078b7c0 @ 0x0078b7c0 ====

void FUN_0078b7c0(undefined2 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f81e4;
  }
  FUN_00797a20(puVar1);
  *(undefined2 *)(in_ECX + 4) = *param_1;
  *(undefined1 *)(in_ECX + 6) = *(undefined1 *)(param_1 + 1);
  return;
}


// ==== FUN_0078b840 @ 0x0078b840 ====

void FUN_0078b840(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b1b4 = 0;
  *in_ECX = &PTR_FUN_009f7f0c;
  return;
}


// ==== FUN_0078b860 @ 0x0078b860 ====

undefined4 FUN_0078b860(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 == 0) || (*(int **)(iVar1 + 0x34) == (int *)0x0)) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0078b87d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(int **)(iVar1 + 0x34) + 0x34))();
  return uVar2;
}


// ==== FUN_0078b880 @ 0x0078b880 ====

undefined4 FUN_0078b880(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 == 0) || (*(int **)(iVar1 + 0x34) == (int *)0x0)) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0078b89d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(int **)(iVar1 + 0x34) + 0x38))();
  return uVar2;
}


// ==== FUN_0078b8a0 @ 0x0078b8a0 ====

undefined4 FUN_0078b8a0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 == 0) || (*(int **)(iVar1 + 0x34) == (int *)0x0)) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0078b8bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(**(int **)(iVar1 + 0x34) + 0x18))();
  return uVar2;
}


// ==== FUN_0078b8d0 @ 0x0078b8d0 ====

undefined4 FUN_0078b8d0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x34) != (int *)0x0)) {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x34) + 0x3c))();
    if (piVar2 != (int *)0x0) {
      puVar3 = (undefined4 *)(**(code **)(*piVar2 + 4))();
      return *puVar3;
    }
  }
  return 0;
}


// ==== FUN_0078b900 @ 0x0078b900 ====

void FUN_0078b900(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x34);
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x20))(param_1);
  if (piVar2 == (int *)0x0) {
    return;
  }
  (**(code **)(*piVar2 + 0x6c))();
  return;
}


// ==== FUN_0078b940 @ 0x0078b940 ====

void FUN_0078b940(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int in_ECX;
  undefined2 *unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x51a000a;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined2 *)(iVar4 + 0x10) = *unaff_retaddr;
    *(undefined1 *)(iVar4 + 0x12) = *(undefined1 *)(unaff_retaddr + 1);
    FUN_004d8570(iVar4);
    *(undefined2 *)(in_ECX + 4) = *unaff_retaddr;
    *(undefined1 *)(in_ECX + 6) = *(undefined1 *)(unaff_retaddr + 1);
                    /* WARNING: Could not recover jumptable at 0x0078b9ca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5af2c + 4))();
    return;
  }
  return;
}


// ==== FUN_0078b9e0 @ 0x0078b9e0 ====

void FUN_0078b9e0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined1 auStack_58 [20];
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00997fb8;
  pvStack_c = ExceptionList;
  uStack_38 = 0x78ba08;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar2 != 0) && (piVar1 = *(int **)(iVar2 + 0x34), piVar1 != (int *)0x0)) {
    uStack_38 = 0x78ba26;
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    if ((iVar2 != 0) && (uStack_38 = *(int *)(iVar2 + 0x1c), uStack_38 != 0)) {
      uStack_3c = param_1;
      uStack_40 = 0x78ba46;
      iVar2 = (**(code **)(*piVar1 + 0x14))();
      if (iVar2 == 1) {
        uStack_38 = param_1;
        uStack_3c = 0x78bab9;
        FUN_0078b7c0();
        ExceptionList = pvStack_c;
        return;
      }
      if (iVar2 != 2) {
        uStack_38 = 0x6e003d;
        uStack_3c = 0;
        uStack_40 = 0x78ba62;
        uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_44 = 0x78ba6c;
        FUN_00765c50();
        puStack_4 = auStack_58;
        pvStack_c = (void *)0x0;
        FUN_00765c50(auStack_58 + 0x28);
        (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      uStack_38 = param_1;
      uStack_3c = 0x78bad5;
      FUN_0078b940();
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0078baf0 @ 0x0078baf0 ====

void FUN_0078baf0(void)

{
  char cVar1;
  void *unaff_EDI;
  int unaff_retaddr;
  undefined1 auStack_78 [4];
  undefined1 uStack_74;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  void *pvStack_44;
  uint uStack_3c;
  void *pvStack_38;
  undefined4 uStack_34;
  uint uStack_30;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997fda;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  cVar1 = *(char *)(unaff_retaddr + 0x10);
  if (cVar1 == '\x04') {
    uStack_5c = 0;
    uStack_60 = 0x78bb3b;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = uStack_30 & 0xffffff00;
    uStack_6c = 0x78bb59;
    FUN_00401660();
    puStack_8 = auStack_78;
    uStack_60 = 0xf;
    uStack_64 = 0;
    uStack_10 = 0;
    uStack_74 = 0;
    FUN_00401660(&uStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
    if (0xf < uStack_3c) {
      _free(unaff_EDI);
      return;
    }
  }
  else if (cVar1 == '\x02') {
    uStack_5c = 5;
    uStack_60 = 0x78bbcf;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = uStack_30 & 0xffffff00;
    uStack_6c = 0x78bbed;
    FUN_00401660();
    puStack_8 = auStack_78;
    uStack_60 = 0xf;
    uStack_64 = 0;
    uStack_10 = 1;
    uStack_74 = 0;
    FUN_00401660(&uStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
    if (0xf < uStack_3c) {
      _free(unaff_EDI);
      return;
    }
  }
  else {
    if (cVar1 == '\x01') {
      uStack_5c = 0;
      uStack_60 = 0x78bc66;
      uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_60 = 0xffffffff;
      uStack_64 = 0;
      pvStack_38 = (void *)0xf;
      uStack_6c = 0x78bc84;
      FUN_00401660();
      puStack_8 = auStack_78;
      uStack_60 = 0xf;
      uStack_64 = 0;
      uStack_10 = 2;
      uStack_74 = 0;
      FUN_00401660(auStack_78 + 0x28,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
      puStack_8 = (undefined1 *)0xffffffff;
      if (0xf < uStack_30) {
        uStack_5c = 0x78bcd1;
        _free(pvStack_44);
        return;
      }
      uStack_30 = 0xf;
      uStack_34 = 0;
    }
    uStack_5c = 0x78bced;
    (**(code **)(*DAT_00b5a78c + 0x60))();
    uStack_5c = DAT_00b5b1b0;
    uStack_60 = 0x78bcfb;
    FUN_0073c600();
    uStack_5c = 0x78bd06;
    (**(code **)(*DAT_00b5adc4 + 0x4c))();
    uStack_5c = 5;
    uStack_60 = 0x78bd13;
    (**(code **)(*DAT_00b5acd4 + 4))();
    uStack_60 = 2;
    uStack_64 = 0x78bd20;
    (**(code **)(*DAT_00b5a97c + 0x38))();
    uStack_64 = 0x78bd2b;
    uStack_64 = FUN_0078aee0();
    uStack_68 = 0x78bd34;
    FUN_0073c6d0();
    uStack_64 = 0x78bd3f;
    (**(code **)(*DAT_00b5a790 + 8))();
  }
  ExceptionList = pvStack_38;
  return;
}


// ==== FUN_0078bd60 @ 0x0078bd60 ====

void FUN_0078bd60(void)

{
  undefined1 *puVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  int in_ECX;
  undefined1 auStack_68 [4];
  undefined1 uStack_64;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_3c;
  void *pvStack_28;
  uint uStack_14;
  undefined1 *puStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00997fec;
  pvStack_c = ExceptionList;
  uStack_3c = 0;
  ExceptionList = &pvStack_c;
  cVar2 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar2 == '\0') {
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_4c = 0;
    uStack_54 = 0x78bdc3;
    FUN_00401660();
    puStack_10 = (undefined1 *)0x0;
    uStack_4c = 0x78bdd1;
    uVar3 = thunk_FUN_00796fb0();
    puVar1 = puStack_8;
    if (uVar3 < *(uint *)(puStack_8 + 4)) {
      uStack_4c = 0;
      uStack_50 = 0x78bdee;
      uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_50 = 0xffffffff;
      uStack_54 = 0;
      uStack_5c = 0x78bdfb;
      FUN_00401660();
      puStack_10 = auStack_68;
      uStack_50 = 0xf;
      uStack_54 = 0;
      uStack_64 = 0;
      FUN_00401660(&uStack_3c,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
    }
    else {
      uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      uStack_4c = 0x78be40;
      pvVar5 = operator_new(0x400);
      *(undefined4 *)((int)pvVar5 + 8) = uVar4;
      *(undefined4 *)((int)pvVar5 + 0xc) = 0x51a0008;
      *(undefined2 *)((int)pvVar5 + 6) = 0x18;
      iVar6 = FUN_004244d0();
      *(undefined2 *)(iVar6 + 0x10) = *(undefined2 *)(in_ECX + 4);
      *(undefined1 *)(iVar6 + 0x12) = *(undefined1 *)(in_ECX + 6);
      *(undefined4 *)(iVar6 + 0x14) = *(undefined4 *)(puVar1 + 4);
      uStack_4c = 0x78be7e;
      FUN_004d8570();
      *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(puVar1 + 4);
      uStack_4c = 0x78be90;
      (**(code **)(*DAT_00b5af2c + 4))();
    }
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
  }
  ExceptionList = puStack_10;
  return;
}


// ==== FUN_0078bec0 @ 0x0078bec0 ====

void FUN_0078bec0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  undefined1 auStack_98 [12];
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  TypeDescriptor *pTStack_80;
  TypeDescriptor *pTStack_7c;
  int *piStack_78;
  undefined1 auStack_60 [28];
  undefined1 auStack_44 [20];
  undefined1 auStack_30 [24];
  void *pvStack_18;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0099806e;
  pvStack_c = ExceptionList;
  piStack_78 = (int *)0x78beeb;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(iVar2 + 0x34);
  }
  piStack_78 = (int *)0x78bf01;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = *(int **)(iVar2 + 0x1c);
  }
  if ((piVar5 != (int *)0x0) && (piVar6 != (int *)0x0)) {
    piStack_78 = (int *)0x0;
    pTStack_7c = (TypeDescriptor *)0x78bf29;
    (**(code **)(*DAT_00b5af2c + 8))();
    cVar1 = *(char *)(param_1 + 0x10);
    if (cVar1 == '\0') {
      piStack_78 = (int *)0x78c2be;
      uVar3 = (**(code **)(*piVar6 + 0x18))();
      piStack_78 = (int *)0x0;
      pTStack_7c = &Framework::Article::IItem::RTTI_Type_Descriptor;
      pTStack_80 = &Framework::IArticle::RTTI_Type_Descriptor;
      uStack_84 = 0;
      uStack_8c = 0x78c2d4;
      uStack_88 = uVar3;
      piVar4 = (int *)FUN_00803725();
      if (piVar4 == (int *)0x0) {
        pTStack_7c = (TypeDescriptor *)0x78c2e5;
        piStack_78 = (int *)uVar3;
        (**(code **)(*piVar6 + 0x14))();
        ExceptionList = pvStack_10;
        return;
      }
      pTStack_7c = (TypeDescriptor *)(in_ECX + 4);
      pTStack_80 = (TypeDescriptor *)0x78c30b;
      piStack_78 = piVar4;
      cVar1 = (**(code **)(*piVar5 + 0x1c))();
      if (cVar1 == '\0') {
        uStack_84 = 0x78c317;
        pTStack_80 = (TypeDescriptor *)piVar4;
        (**(code **)(*piVar6 + 0x14))();
        ExceptionList = pvStack_18;
        return;
      }
      pTStack_80 = *(TypeDescriptor **)(in_ECX + 8);
      uStack_84 = 0x78c337;
      (**(code **)(*piVar4 + 0x68))();
      uStack_84 = 0x78c342;
      (**(code **)(*DAT_00b5adc4 + 0x4c))();
      uStack_84 = 0x78c34d;
      (**(code **)(*DAT_00b5a790 + 8))();
    }
    else {
      if (cVar1 == '\x01') {
        piStack_78 = (int *)s_SA_EntryItem___NOT_ITEM_009f80a4;
        pTStack_7c = (TypeDescriptor *)0x78bf4e;
        FUN_00401830();
        piStack_78 = (int *)auStack_60;
        puStack_4 = (undefined1 *)0x0;
        pTStack_7c = (TypeDescriptor *)0x78bf60;
        FUN_00796d50();
        puStack_4 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
        piStack_78 = (int *)0x78bf74;
        FUN_00446f10();
      }
      if (cVar1 == '\x02') {
        piStack_78 = (int *)s_SA_EntryItem___QUEST_ITEM_009f80bc;
        pTStack_7c = (TypeDescriptor *)0x78bfee;
        FUN_00401830();
        piStack_78 = (int *)auStack_44;
        puStack_4 = (undefined1 *)0x2;
        pTStack_7c = (TypeDescriptor *)0x78c000;
        FUN_00796d50();
        puStack_4 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
        piStack_78 = (int *)0x78c014;
        FUN_00446f10();
      }
      if (cVar1 == '\x03') {
        piStack_78 = (int *)s_SA_EntryItem___CANNOT_PUTITEM_009f80f4;
        pTStack_7c = (TypeDescriptor *)0x78c04f;
        FUN_00401830();
        piStack_78 = (int *)auStack_44;
        puStack_4 = (undefined1 *)0x6;
        pTStack_7c = (TypeDescriptor *)0x78c061;
        FUN_00796d50();
        puStack_4 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
        piStack_78 = (int *)0x78c075;
        FUN_00446f10();
      }
      if (cVar1 == '\x04') {
        piStack_78 = (int *)s_SA_EntryItem___COUNT_OVER_009f8114;
        pTStack_7c = (TypeDescriptor *)0x78c0b0;
        FUN_00401830();
        piStack_78 = (int *)auStack_44;
        puStack_4 = (undefined1 *)0x8;
        pTStack_7c = (TypeDescriptor *)0x78c0c2;
        FUN_00796d50();
        puStack_4 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
        piStack_78 = (int *)0x78c0d6;
        FUN_00446f10();
      }
      if (cVar1 == '\x05') {
        piStack_78 = (int *)s_SA_EntryItem___COUNT_OVER_009f8130;
        pTStack_7c = (TypeDescriptor *)0x78c111;
        FUN_00401830();
        piStack_78 = (int *)auStack_44;
        puStack_4 = (undefined1 *)0xa;
        pTStack_7c = (TypeDescriptor *)0x78c123;
        FUN_00796d50();
        puStack_4 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
        piStack_78 = (int *)0x78c137;
        FUN_00446f10();
      }
      if (cVar1 == '\a') {
        piStack_78 = (int *)s_SA_EntryItem___FAIL_009f814c;
        pTStack_7c = (TypeDescriptor *)0x78c172;
        FUN_00401830();
        piStack_78 = (int *)auStack_44;
        puStack_4 = (undefined1 *)0xc;
        pTStack_7c = (TypeDescriptor *)0x78c184;
        FUN_00796d50();
        puStack_4 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
        piStack_78 = (int *)0x78c198;
        FUN_00446f10();
      }
      if (cVar1 == '\t') {
        piStack_78 = (int *)s_SA_EntryItem___FAIL_009f8160;
        pTStack_7c = (TypeDescriptor *)0x78c1d4;
        FUN_00401830();
        piStack_78 = (int *)auStack_44;
        puStack_4 = (undefined1 *)0xe;
        pTStack_7c = (TypeDescriptor *)0x78c1e6;
        FUN_00796d50();
        puStack_4 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
        piStack_78 = (int *)0x78c1fa;
        FUN_00446f10();
      }
      if (cVar1 == '\x06') {
        piStack_78 = (int *)0x6e010b;
        pTStack_7c = (TypeDescriptor *)0x0;
        pTStack_80 = (TypeDescriptor *)0x78c279;
        pTStack_80 = (TypeDescriptor *)(**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_84 = 0x78c283;
        FUN_00765c50();
        puStack_4 = auStack_98;
        pvStack_c = (void *)0x10;
        FUN_00765c50(auStack_30);
        (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0078c370 @ 0x0078c370 ====

void FUN_0078c370(int param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int *piVar4;
  undefined1 auStack_7c [28];
  undefined1 auStack_60 [28];
  undefined1 auStack_44 [56];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009980a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(iVar2 + 0x34);
  }
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(iVar2 + 0x1c);
  }
  if ((piVar4 != (int *)0x0) && (piVar3 != (int *)0x0)) {
    (**(code **)(*DAT_00b5af2c + 8))(0);
    cVar1 = *(char *)(param_1 + 0x10);
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*piVar3 + 0x1c))();
      if (iVar2 == 0) {
        iVar2 = (**(code **)(*piVar4 + 0x24))(in_ECX + 4);
        if (iVar2 != 0) {
          cVar1 = (**(code **)(*piVar3 + 0x14))(iVar2);
          if (cVar1 == '\0') {
            (**(code **)(*piVar4 + 0x1c))(in_ECX + 4,iVar2);
          }
          else {
            (**(code **)(*DAT_00b5adc4 + 0x4c))();
            (**(code **)(*DAT_00b5a790 + 8))();
          }
        }
      }
    }
    else {
      if (cVar1 == '\x01') {
        FUN_00401830(s_SA_RemoveItem___NOT_ITEM_009f8174);
        uStack_4 = 0;
        FUN_00796d50(auStack_7c);
        uStack_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      if (cVar1 == '\x02') {
        FUN_00401830(s_SA_RemoveItem___CANNOT_PUTITEM_009f8190);
        uStack_4 = 2;
        FUN_00796d50(auStack_60);
        uStack_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      if (cVar1 == '\x03') {
        FUN_00401830(s_SA_RemoveItem___FAIL_009f81b0);
        uStack_4 = 4;
        FUN_00796d50(auStack_44);
        uStack_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0078c620 @ 0x0078c620 ====

void FUN_0078c620(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  uint unaff_ESI;
  undefined1 auStack_e0 [4];
  undefined4 uStack_dc;
  undefined1 *puStack_d8;
  undefined1 *puStack_d4;
  int *piStack_d0;
  undefined1 *puStack_cc;
  undefined1 auStack_bc [4];
  undefined1 auStack_b8 [4];
  undefined1 *puStack_b4;
  undefined4 uStack_b0;
  void *pvStack_ac;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined1 auStack_8a [10];
  int aiStack_80 [9];
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [32];
  undefined4 uStack_38;
  void *pvStack_34;
  undefined4 uStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009980f6;
  pvStack_c = ExceptionList;
  uStack_a0 = 0x78c64a;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5aee4 + 0xc))();
  if (cVar1 == '\0') {
    uStack_a0 = 0x78c6de;
    iVar2 = (**(code **)(*DAT_00b5a78c + 100))();
    if (iVar2 == 0) {
      uStack_a0 = 0x78c776;
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      uStack_a0 = 0x78c783;
      piVar4 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
      if (((piVar4 != (int *)0x0) && ((int *)piVar4[0x13] != (int *)0x0)) &&
         (piVar5 = (int *)(**(code **)(*(int *)piVar4[0x13] + 0x18))(), piVar5 != (int *)0x0)) {
        if ((int *)piVar4[0x1d] == (int *)0x0) {
          piVar6 = (int *)0x0;
        }
        else {
          piVar6 = (int *)(**(code **)(*(int *)piVar4[0x1d] + 0x14))();
        }
        iVar2 = (**(code **)(*piVar6 + 8))();
        puStack_b4 = (undefined1 *)CONCAT31(puStack_b4._1_3_,*(undefined1 *)(iVar2 + 4));
        piStack_d0 = (int *)auStack_5c;
        puStack_d4 = (undefined1 *)0x78c7d7;
        puStack_cc = (undefined1 *)uVar3;
        FUN_004ef6c0();
        puStack_cc = (undefined1 *)0x78c7e6;
        cVar1 = (**(code **)(*piVar5 + 0x20))();
        if (cVar1 == '\0') {
          puStack_cc = (undefined1 *)0x6e0061;
          piStack_d0 = (int *)0x0;
          puStack_d4 = (undefined1 *)0x78c7fb;
          puStack_d4 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
          puStack_d8 = (undefined1 *)0x78c805;
          FUN_00765c50();
          uStack_38 = 2;
          FUN_00765c50(auStack_bc);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
        }
        else {
          puStack_cc = (undefined1 *)0x0;
          piStack_d0 = (int *)0x78c845;
          cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
          if (cVar1 != '\0') {
            ExceptionList = pvStack_34;
            return;
          }
          puStack_cc = (undefined1 *)0x78c85e;
          FUN_00765c50();
          uStack_2c = 3;
          if (aiStack_80[0] == 0) {
            puStack_cc = (undefined1 *)0x0;
            piStack_d0 = (int *)0x78c884;
            piStack_d0 = (int *)(**(code **)(*DAT_00b5a794 + 0xc))();
            puStack_d4 = (undefined1 *)0x78c88e;
            FUN_00765c50();
            pvStack_34._0_1_ = 4;
            piStack_d0 = (int *)0x78c89d;
            iVar2 = (**(code **)(*piVar4 + 0x74))();
            piStack_d0 = (int *)(iVar2 + 0x5c);
            puStack_d4 = (undefined1 *)0x78c8aa;
            FUN_00401830();
            piStack_d0 = aiStack_80;
            puStack_d4 = auStack_b8;
            puStack_d8 = auStack_58;
            pvStack_34._0_1_ = 5;
            uStack_dc = 0x78c8c6;
            puStack_d8 = (undefined1 *)FUN_00405bd0();
            piStack_d0 = (int *)0xffffffff;
            puStack_d4 = (undefined1 *)0x0;
            pvStack_34 = (void *)CONCAT31(pvStack_34._1_3_,6);
            uStack_dc = 0x78c8de;
            FUN_00401660();
                    /* WARNING: Subroutine does not return */
            piStack_d0 = (int *)0x78c8e7;
            FUN_00446f10();
          }
          (**(code **)(*DAT_00b5a6ac + 0x20))();
          puStack_cc = (undefined1 *)0x78c912;
          FUN_0078ca40();
          puStack_cc = (undefined1 *)0x78c930;
          FUN_0047aa60();
          puStack_cc = (undefined1 *)0x78c93d;
          FUN_0047aa00();
          puStack_cc = (undefined1 *)0x78c943;
          FUN_004ef210();
          puStack_b4 = auStack_e0;
          FUN_00765c50();
          FUN_0078b250();
          puStack_cc = (undefined1 *)0x78c96d;
          (**(code **)(*DAT_00b5af2c + 4))();
        }
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else {
      uStack_a0 = 0x6e0060;
      uStack_a4 = 0;
      uStack_a8 = 0x78c6f9;
      uStack_b0 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_a8 = 0xffffffff;
      pvStack_ac = (void *)0x0;
      aiStack_80[2] = 0xf;
      aiStack_80[1] = 0;
      puStack_b4 = (undefined1 *)0x78c717;
      FUN_00401660();
      puStack_cc = auStack_8a + -6;
      uStack_a8 = 0xf;
      pvStack_ac = (void *)0x0;
      pvStack_c = (void *)0x1;
      auStack_bc[0] = 0;
      piStack_d0 = (int *)0x78c741;
      FUN_00401660();
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      if (0xf < unaff_ESI) {
        puStack_cc = (undefined1 *)0x78c763;
        _free(pvStack_ac);
        return;
      }
    }
  }
  else {
    uStack_a0 = 0x6e005f;
    uStack_a4 = 0;
    uStack_a8 = 0x78c665;
    uStack_b0 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_a8 = 0xffffffff;
    pvStack_ac = (void *)0x0;
    aiStack_80[2] = 0xf;
    aiStack_80[1] = 0;
    puStack_b4 = (undefined1 *)0x78c683;
    FUN_00401660();
    puStack_cc = auStack_8a + -6;
    uStack_a8 = 0xf;
    pvStack_ac = (void *)0x0;
    pvStack_c = (void *)0x0;
    auStack_bc[0] = 0;
    piStack_d0 = (int *)0x78c6a9;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (0xf < unaff_ESI) {
      puStack_cc = (undefined1 *)0x78c6cb;
      _free(pvStack_ac);
      return;
    }
  }
  ExceptionList = pvStack_34;
  return;
}


// ==== FUN_0078c9a0 @ 0x0078c9a0 ====

undefined4 FUN_0078c9a0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x51a0005) {
    FUN_0078baf0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x51a0009) {
    FUN_0078bec0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x51a000b) {
    FUN_0078c370(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_0078ca00 @ 0x0078ca00 ====

undefined4 FUN_0078ca00(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0078c9a0(param_1);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  else {
    if (iVar2 != 0x70300004) {
      return 0;
    }
    FUN_0078bd60(param_1);
  }
  return 1;
}


// ==== FUN_0078ca40 @ 0x0078ca40 ====

void FUN_0078ca40(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x51a0004;
  *(undefined2 *)((int)pvVar1 + 6) = 0x2c;
  FUN_004244d0();
  return;
}


// ==== FUN_0078ca70 @ 0x0078ca70 ====

undefined4 FUN_0078ca70(void)

{
  return 0x70300003;
}


// ==== FUN_0078ca80 @ 0x0078ca80 ====

void FUN_0078ca80(byte param_1)

{
  void *in_ECX;
  
  FUN_0078b840();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078caa0 @ 0x0078caa0 ====

void FUN_0078caa0(void)

{
  return;
}


// ==== FUN_0078cab0 @ 0x0078cab0 ====

undefined1 FUN_0078cab0(void)

{
  return 0;
}


// ==== FUN_0078cac0 @ 0x0078cac0 ====

undefined4 FUN_0078cac0(void)

{
  return 0;
}


// ==== FUN_0078cae0 @ 0x0078cae0 ====

void FUN_0078cae0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f82a4;
  in_ECX[1] = param_1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b1b8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b1b8 = in_ECX;
  return;
}


// ==== FUN_0078cb10 @ 0x0078cb10 ====

void FUN_0078cb10(void)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*DAT_00b5aee4 + 0xc))();
    if (cVar1 == '\0') {
      iVar2 = (**(code **)(*DAT_00b5a78c + 100))();
      if (iVar2 == 0) {
        FUN_0073c600(DAT_00b5b1b4);
        puVar3 = operator_new(4);
        if (puVar3 == (undefined4 *)0x0) {
          puVar3 = (undefined4 *)0x0;
        }
        else {
          *puVar3 = &PTR_FUN_009f828c;
        }
        FUN_00797a20(puVar3);
        (**(code **)(*DAT_00b5a78c + 0x20))();
                    /* WARNING: Could not recover jumptable at 0x0078cb86. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*DAT_00b5ad0c + 0x14))();
        return;
      }
    }
  }
  return;
}


// ==== FUN_0078cb90 @ 0x0078cb90 ====

void FUN_0078cb90(void)

{
  (**(code **)(*DAT_00b5a78c + 0x60))(0);
  return;
}


// ==== FUN_0078cba0 @ 0x0078cba0 ====

undefined4 FUN_0078cba0(void)

{
  return 0;
}


// ==== FUN_0078cbb0 @ 0x0078cbb0 ====

undefined4 FUN_0078cbb0(void)

{
  return 0;
}


// ==== FUN_0078cbc0 @ 0x0078cbc0 ====

void FUN_0078cbc0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b1b8 = 0;
  *in_ECX = &PTR_FUN_009f7f0c;
  return;
}


// ==== FUN_0078cbe0 @ 0x0078cbe0 ====

void FUN_0078cbe0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x51a0000;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined4 *)(iVar4 + 0x10) = unaff_retaddr;
    FUN_004d8570(iVar4);
    *(undefined4 *)(DAT_00b5b1ac + 4) = unaff_retaddr;
    (**(code **)(*DAT_00b5af2c + 4))(0);
    cVar1 = (**(code **)(*DAT_00b5a78c + 0x5c))();
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5a78c + 0x24))();
    }
    (**(code **)(*DAT_00b5a78c + 0x60))(4);
    (**(code **)(*DAT_00b5a78c + 0x20))();
  }
  return;
}


// ==== FUN_0078cc90 @ 0x0078cc90 ====

/* WARNING: Removing unreachable block (ram,0x0078cdc4) */

void FUN_0078cc90(void)

{
  char cVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int unaff_retaddr;
  undefined1 auStack_78 [4];
  undefined1 uStack_74;
  undefined4 uStack_6c;
  undefined1 *puStack_68;
  undefined4 uStack_64;
  undefined4 uStack_34;
  void *pvStack_30;
  undefined4 uStack_20;
  uint uStack_1c;
  void *pvStack_18;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998120;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  cVar1 = *(char *)(unaff_retaddr + 0x10);
  if (cVar1 == '\x01') {
    puStack_68 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_64 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
    uStack_6c = 0x78ceae;
    FUN_00401660();
    uStack_10 = 0;
  }
  else {
    if (cVar1 != '\x02') {
      if (cVar1 != '\x03') {
        FUN_0073c600();
        puVar2 = operator_new(4);
        if (puVar2 != (undefined4 *)0x0) {
          *puVar2 = &PTR_FUN_009f828c;
        }
        FUN_00797a20();
        cVar1 = (**(code **)(*DAT_00b5a78c + 0x5c))();
        if (cVar1 != '\0') {
          (**(code **)(*DAT_00b5a78c + 0x24))();
        }
        (**(code **)(*DAT_00b5a78c + 0x60))();
        (**(code **)(*DAT_00b5a78c + 0x20))();
        (**(code **)(*DAT_00b5ad0c + 0x14))();
        if (*(ushort *)(unaff_retaddr + 6) < 0x15) {
          pcVar3 = (char *)0x0;
        }
        else {
          pcVar3 = (char *)(unaff_retaddr + 0x14);
        }
        uStack_34 = 0xf;
        pvStack_c = (void *)0x3;
        if (pcVar3 != (char *)0x0) {
          do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          uStack_64 = 0x78cd96;
          FUN_00401740();
        }
        (**(code **)(*DAT_00b5acd4 + 4))();
        uStack_64 = 0;
        puStack_68 = auStack_78 + 0x28;
        uStack_6c = 0x78cdb9;
        FUN_00401660();
        ExceptionList = pvStack_18;
        return;
      }
      puStack_68 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_64 = 0;
      uStack_1c = 0xf;
      uStack_20 = 0;
      pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
      uStack_6c = 0x78cdfd;
      FUN_00401660();
      puStack_8 = auStack_78;
      uStack_64 = 0;
      uStack_10 = 2;
      uStack_74 = 0;
      FUN_00401660(&uStack_34,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
      goto joined_r0x0078ce36;
    }
    puStack_68 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_64 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
    uStack_6c = 0x78ce75;
    FUN_00401660();
    uStack_10 = 1;
  }
  puStack_8 = auStack_78;
  uStack_64 = 0;
  uStack_74 = 0;
  FUN_00401660(&uStack_34,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(0xc);
joined_r0x0078ce36:
  if (uStack_1c < 0x10) {
    ExceptionList = pvStack_18;
    return;
  }
  uStack_64 = 0x78ceef;
  _free(pvStack_30);
  return;
}


// ==== FUN_0078cf40 @ 0x0078cf40 ====

undefined4 FUN_0078cf40(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x51a0001) {
      FUN_0078cc90(param_1[3]);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0078cf80 @ 0x0078cf80 ====

undefined4 FUN_0078cf80(void)

{
  return 0x70300000;
}


// ==== FUN_0078cf90 @ 0x0078cf90 ====

void FUN_0078cf90(byte param_1)

{
  void *in_ECX;
  
  FUN_0078cbc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078cfb0 @ 0x0078cfb0 ====

void FUN_0078cfb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f836c;
  return;
}


// ==== FUN_0078cfc0 @ 0x0078cfc0 ====

void FUN_0078cfc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f836c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078cfe0 @ 0x0078cfe0 ====

void FUN_0078cfe0(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  undefined4 uVar8;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = 0x27;
  local_10 = 0x3d;
  local_c = 0;
  local_8 = 0;
  puVar5 = (undefined4 *)(**(code **)(*DAT_00b5ac68 + 4))(&local_14);
  if (puVar5 != (undefined4 *)0x0) {
    piVar6 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    uVar7 = (**(code **)(*piVar6 + 4))(0,s___Target_State_Creature_cpp_009f831c,0x265);
    *(undefined4 *)(in_ECX + 0x54) = uVar7;
    uVar8 = *puVar5;
    uVar2 = puVar5[2];
    uVar3 = puVar5[1];
    uVar4 = *(undefined4 *)(in_ECX + 0x50);
    bVar1 = *(byte *)(puVar5 + 3);
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 != (undefined4 *)0x0) {
      *puVar5 = &PTR_FUN_009bf3e8;
      puVar5[1] = uVar8;
      puVar5[2] = uVar4;
      puVar5[3] = uVar7;
      puVar5[4] = uVar3;
      puVar5[5] = uVar2;
      puVar5[6] = (uint)bVar1;
      FUN_00797a20(puVar5);
      return;
    }
    FUN_00797a20(0);
  }
  return;
}


// ==== FUN_0078d0b0 @ 0x0078d0b0 ====

void FUN_0078d0b0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x54);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b1874;
      puVar2[1] = iVar1;
    }
    FUN_00797a20(puVar2);
    piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    (**(code **)(*piVar3 + 8))(s___Target_State_Creature_cpp_009f8338,0x27e,0,iVar1);
    *(undefined4 *)(in_ECX + 0x54) = 0;
  }
  return;
}


// ==== FUN_0078d110 @ 0x0078d110 ====

undefined4 FUN_0078d110(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char *pcVar4;
  int in_ECX;
  int iVar5;
  char *pcVar6;
  char acStack_84 [128];
  
  iVar5 = *param_1;
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  puVar3 = (undefined4 *)(**(code **)(iVar5 + 0x1c))(uVar2);
  pcVar4 = acStack_84;
  pcVar6 = acStack_84;
  for (iVar5 = 0x1e; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined4 *)pcVar6 = *puVar3;
    puVar3 = puVar3 + 1;
    pcVar6 = pcVar6 + 4;
  }
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(acStack_84,(int)pcVar4 - (int)(acStack_84 + 1));
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  return 1;
}


// ==== FUN_0078d180 @ 0x0078d180 ====

undefined4 FUN_0078d180(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  char *pcVar5;
  
  piVar3 = (int *)(**(code **)(*param_1 + 0x20))();
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  iVar4 = (**(code **)(*piVar3 + 4))();
  pcVar5 = (char *)(iVar4 + 2);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar4 + 2),(int)pcVar5 - (iVar4 + 3));
  uVar2 = DAT_0099de78;
  *(undefined4 *)(in_ECX + 0x18) = DAT_0099de78;
  *(undefined4 *)(in_ECX + 0x1c) = uVar2;
  return 1;
}


// ==== FUN_0078d1e0 @ 0x0078d1e0 ====

undefined4 FUN_0078d1e0(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int in_ECX;
  char *pcVar8;
  int unaff_retaddr;
  
  piVar3 = (int *)(**(code **)(*param_1 + 0x20))();
  if ((piVar3 == (int *)0x0) || ((int *)param_1[0x14] == (int *)0x0)) {
    return 0;
  }
  iVar6 = *(int *)param_1[0x14];
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar5 = (int *)(**(code **)(iVar6 + 0x14))(uVar4);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  iVar6 = (**(code **)(*piVar3 + 4))();
  pcVar8 = (char *)(iVar6 + 2);
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar6 + 2),(int)pcVar8 - (iVar6 + 3));
  iVar6 = (**(code **)(*piVar3 + 4))();
  *(undefined2 *)(in_ECX + 0x14) = *(undefined2 *)(iVar6 + 0x4c);
  puVar7 = (undefined4 *)(**(code **)(*piVar5 + 0x18))();
  *(undefined4 *)(in_ECX + 0x18) = *puVar7;
  iVar6 = (**(code **)(*piVar5 + 0x18))();
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(iVar6 + 0xc);
  piVar3 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(unaff_retaddr + 0xac));
  iVar6 = (**(code **)(*piVar3 + 0xc))();
  if (iVar6 == 1) {
    piVar5 = *(int **)(unaff_retaddr + 0x14);
    uVar2 = (**(code **)(*piVar5 + 0x18))();
    *(undefined1 *)(in_ECX + 0x48) = uVar2;
    iVar6 = 1;
    do {
      uVar2 = (**(code **)(*piVar5 + 0x1c))();
      *(undefined1 *)(in_ECX + 0x48 + iVar6) = uVar2;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 8);
    uVar4 = (**(code **)(*piVar3 + 0x10))
                      (0,&Framework::ModelCenter::Actors::State::IActorState::RTTI_Type_Descriptor,
                       &Framework::ModelCenter::Actors::State::Monster::RTTI_Type_Descriptor,0);
    iVar6 = FUN_00803725(uVar4);
    *(undefined1 *)(in_ECX + 0x40) = *(undefined1 *)(iVar6 + 0x40);
    *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(iVar6 + 0x44);
  }
  return 1;
}


// ==== FUN_0078d300 @ 0x0078d300 ====

uint FUN_0078d300(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_ECX;
  char *pcVar7;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x24))();
  if ((piVar2 == (int *)0x0) || ((int *)param_1[0x14] == (int *)0x0)) {
    return (uint)piVar2 & 0xffffff00;
  }
  iVar5 = *(int *)param_1[0x14];
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar4 = (int *)(**(code **)(iVar5 + 0x14))(uVar3);
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  iVar5 = (**(code **)(*piVar2 + 4))();
  pcVar7 = (char *)(iVar5 + 8);
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar5 + 8),(int)pcVar7 - (iVar5 + 9));
  iVar5 = (**(code **)(*piVar2 + 4))();
  *(undefined2 *)(in_ECX + 0x14) = *(undefined2 *)(iVar5 + 0x2c);
  puVar6 = (undefined4 *)(**(code **)(*piVar4 + 0x18))();
  *(undefined4 *)(in_ECX + 0x18) = *puVar6;
  iVar5 = (**(code **)(*piVar4 + 0x18))();
  uVar3 = *(undefined4 *)(iVar5 + 0xc);
  *(undefined4 *)(in_ECX + 0x1c) = uVar3;
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}


// ==== FUN_0078d3b0 @ 0x0078d3b0 ====

uint FUN_0078d3b0(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_ECX;
  char *pcVar7;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x20))();
  if ((piVar2 == (int *)0x0) || ((int *)param_1[0x14] == (int *)0x0)) {
    return (uint)piVar2 & 0xffffff00;
  }
  iVar5 = *(int *)param_1[0x14];
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar4 = (int *)(**(code **)(iVar5 + 0x14))(uVar3);
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  iVar5 = (**(code **)(*piVar2 + 4))();
  pcVar7 = (char *)(iVar5 + 2);
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar5 + 2),(int)pcVar7 - (iVar5 + 3));
  iVar5 = (**(code **)(*piVar2 + 4))();
  *(undefined2 *)(in_ECX + 0x14) = *(undefined2 *)(iVar5 + 0x24);
  puVar6 = (undefined4 *)(**(code **)(*piVar4 + 0x18))();
  *(undefined4 *)(in_ECX + 0x18) = *puVar6;
  iVar5 = (**(code **)(*piVar4 + 0x18))();
  uVar3 = *(undefined4 *)(iVar5 + 0xc);
  *(undefined4 *)(in_ECX + 0x1c) = uVar3;
  return CONCAT31((int3)((uint)uVar3 >> 8),1);
}


// ==== FUN_0078d460 @ 0x0078d460 ====

uint FUN_0078d460(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int in_ECX;
  char *pcVar8;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x20))();
  piVar5 = piVar2;
  if ((piVar2 != (int *)0x0) && ((int *)param_1[0x14] != (int *)0x0)) {
    iVar6 = *(int *)param_1[0x14];
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar4 = (int *)(**(code **)(iVar6 + 0x14))(uVar3);
    piVar5 = (int *)0x0;
    if (piVar4 != (int *)0x0) {
      iVar6 = (**(code **)(*piVar2 + 4))();
      pcVar8 = (char *)(iVar6 + 2);
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_00401740((char *)(iVar6 + 2),(int)pcVar8 - (iVar6 + 3));
      *(undefined2 *)(in_ECX + 0x14) = 0;
      puVar7 = (undefined4 *)(**(code **)(*piVar4 + 0x18))();
      *(undefined4 *)(in_ECX + 0x18) = *puVar7;
      iVar6 = (**(code **)(*piVar4 + 0x18))();
      uVar3 = *(undefined4 *)(iVar6 + 0xc);
      *(undefined4 *)(in_ECX + 0x1c) = uVar3;
      return CONCAT31((int3)((uint)uVar3 >> 8),1);
    }
  }
  return (uint)piVar5 & 0xffffff00;
}


// ==== FUN_0078d4f0 @ 0x0078d4f0 ====

undefined4 FUN_0078d4f0(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int in_ECX;
  char *pcVar7;
  int *unaff_retaddr;
  
  iVar3 = (**(code **)(*param_1 + 0x20))();
  if (iVar3 == 0) {
    return 0;
  }
  if ((int *)param_1[0x14] == (int *)0x0) {
    return 0;
  }
  iVar3 = *(int *)param_1[0x14];
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar5 = (int *)(**(code **)(iVar3 + 0x14))(uVar4);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  iVar3 = (**(code **)(*unaff_retaddr + 4))();
  pcVar7 = (char *)(iVar3 + 2);
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar3 + 2),(int)pcVar7 - (iVar3 + 3));
  *(undefined2 *)(in_ECX + 0x14) = 0;
  puVar6 = (undefined4 *)(**(code **)(*piVar5 + 0x18))();
  *(undefined4 *)(in_ECX + 0x18) = *puVar6;
  iVar3 = (**(code **)(*piVar5 + 0x18))();
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(iVar3 + 0xc);
  piVar5 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1[0x2b]);
  iVar3 = (**(code **)(*piVar5 + 0xc))();
  if (iVar3 == 6) {
    piVar5 = (int *)param_1[5];
    uVar2 = (**(code **)(*piVar5 + 0x18))();
    *(undefined1 *)(in_ECX + 0x48) = uVar2;
    iVar3 = 1;
    do {
      uVar2 = (**(code **)(*piVar5 + 0x1c))();
      *(undefined1 *)(in_ECX + 0x48 + iVar3) = uVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 8);
  }
  return 1;
}


// ==== FUN_0078d5e0 @ 0x0078d5e0 ====

undefined4 FUN_0078d5e0(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  
  if (DAT_00b5acd8 == (int *)0x0) {
    return 0;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 0x50));
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  piVar3 = (int *)(**(code **)(*piVar2 + 0x14))();
  iVar4 = (**(code **)(*piVar3 + 0x24))();
  if (iVar4 != 0) {
    uVar5 = (**(code **)(*piVar2 + 0xc))();
    *(undefined4 *)(in_ECX + 0x10) = uVar5;
    switch(uVar5) {
    case 0:
      cVar1 = FUN_0078d110(iVar4);
      break;
    case 1:
      cVar1 = FUN_0078d1e0(iVar4);
      break;
    case 2:
      cVar1 = FUN_0078d300(iVar4);
      break;
    case 3:
      cVar1 = FUN_0078d3b0(iVar4);
      break;
    case 4:
      cVar1 = FUN_0078d180(iVar4);
      break;
    case 5:
      cVar1 = FUN_0078d460(iVar4);
      break;
    case 6:
      cVar1 = FUN_0078d4f0(iVar4);
      if (cVar1 == '\0') {
        return 0;
      }
      goto LAB_0078d681;
    default:
      goto switchD_0078d62a_default;
    }
    if (cVar1 != '\0') {
LAB_0078d681:
      cVar1 = (**(code **)(*piVar2 + 0x38))();
      if (cVar1 == '\0') {
        *(undefined4 *)(in_ECX + 0x18) = 0;
      }
      return 1;
    }
  }
switchD_0078d62a_default:
  return 0;
}


// ==== FUN_0078d6c0 @ 0x0078d6c0 ====

void FUN_0078d6c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998138;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f8384;
  FUN_00718f10();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0078d710 @ 0x0078d710 ====

void FUN_0078d710(void)

{
  int in_ECX;
  
  FUN_0078d0b0();
  (**(code **)(*DAT_00b5adb8 + 0xc))();
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0xffffffff;
  *(undefined2 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  FUN_00401740(&DAT_0099cf70,0);
  *(undefined1 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  return;
}


// ==== FUN_0078d770 @ 0x0078d770 ====

undefined4 FUN_0078d770(void)

{
  char cVar1;
  
  cVar1 = FUN_0078d5e0();
  if (cVar1 == '\0') {
    FUN_0078d710();
    return 0;
  }
  (**(code **)(*DAT_00b5adb8 + 0x2c))();
  return 1;
}


// ==== FUN_0078d7a0 @ 0x0078d7a0 ====

void FUN_0078d7a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998155;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f8384;
  local_4 = 1;
  FUN_0078d710();
  if ((uint)in_ECX[0xf] < 0x10) {
    in_ECX[0xf] = 0xf;
    in_ECX[0xe] = 0;
    *(undefined1 *)(in_ECX + 10) = 0;
    *in_ECX = &PTR_FUN_009f836c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[10]);
  return;
}


// ==== FUN_0078d850 @ 0x0078d850 ====

void FUN_0078d850(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  int *in_ECX;
  
  iVar1 = in_ECX[0x14];
  iVar2 = param_1[2];
  iVar3 = *param_1;
  iVar5 = (**(code **)(*in_ECX + 0xc))();
  if ((iVar3 == iVar5) && (iVar2 != iVar1)) {
    FUN_0078d710();
    in_ECX[0x14] = param_1[2];
    cVar4 = FUN_0078d5e0();
    if (cVar4 != '\0') {
      FUN_0078cfe0();
      (**(code **)(*DAT_00b5adb8 + 8))();
    }
  }
  return;
}


// ==== FUN_0078d8b0 @ 0x0078d8b0 ====

void FUN_0078d8b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0078d7a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078d900 @ 0x0078d900 ====

void FUN_0078d900(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 uStack_58;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998168;
  pvStack_c = ExceptionList;
  local_68 = 0x27;
  local_64 = 0x3e;
  local_60 = 0;
  local_5c = 0;
  ExceptionList = &pvStack_c;
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5ac68 + 4))(&local_68);
  if (puVar1 != (undefined4 *)0x0) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    uVar3 = (**(code **)(*piVar2 + 4))(2,s___Target_State_Ground_cpp_009f83d4,0x5f);
    *(undefined4 *)(in_ECX + 0x50) = uVar3;
    FUN_0081d760();
    local_60 = *(undefined4 *)(in_ECX + 4);
    local_64 = *(undefined4 *)(in_ECX + 0x50);
    local_5c = *(undefined4 *)(in_ECX + 0xc);
    uStack_58 = *(undefined4 *)(in_ECX + 8);
    uStack_20 = 0xffffffff;
    uStack_44 = 0;
    uStack_40 = *puVar1;
    uStack_3c = puVar1[1];
    uStack_38 = puVar1[2];
    uStack_2c = 0;
    uStack_24 = 0;
    uStack_34 = 0;
    uStack_28 = 0;
    uStack_14 = 0;
    (**(code **)(*DAT_00b5afe0 + 4))(&local_64);
    puStack_8 = (undefined1 *)0xffffffff;
    FUN_0081d670();
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0078da30 @ 0x0078da30 ====

void FUN_0078da30(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x50);
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5afe0 + 8))(iVar1);
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    (**(code **)(*piVar2 + 8))(s___Target_State_Ground_cpp_009f83f0,0x80,2,iVar1);
    *(undefined4 *)(in_ECX + 0x50) = 0;
  }
  return;
}


// ==== FUN_0078da70 @ 0x0078da70 ====

void FUN_0078da70(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x50);
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5afe0 + 8))(iVar1);
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    (**(code **)(*piVar2 + 8))(s___Target_State_Ground_cpp_009f83f0,0x80,2,iVar1);
    *(undefined4 *)(in_ECX + 0x50) = 0;
  }
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_0078daf0 @ 0x0078daf0 ====

void FUN_0078daf0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998185;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f8418;
  local_4 = 1;
  FUN_0078da70();
  if ((uint)in_ECX[0xf] < 0x10) {
    in_ECX[0xf] = 0xf;
    in_ECX[0xe] = 0;
    *(undefined1 *)(in_ECX + 10) = 0;
    *in_ECX = &PTR_FUN_009f836c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[10]);
  return;
}


// ==== FUN_0078db60 @ 0x0078db60 ====

bool FUN_0078db60(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  FUN_0078da70();
  iVar1 = *param_1;
  iVar2 = (**(code **)(*in_ECX + 0xc))();
  return iVar1 == iVar2;
}


// ==== FUN_0078db80 @ 0x0078db80 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0078db80(int *param_1)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  float unaff_EBX;
  float10 fVar4;
  int iStack_14;
  int iStack_10;
  float fStack_c;
  int iStack_8;
  
  FUN_0078da70();
  iVar2 = *param_1;
  iVar3 = (**(code **)(*in_ECX + 0xc))();
  if (iVar2 == iVar3) {
    iStack_14 = param_1[3];
    iStack_10 = param_1[4];
    fVar4 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(&iStack_14);
    fStack_c = (float)fVar4;
    in_ECX[1] = (int)unaff_EBX;
    in_ECX[2] = (int)fStack_c;
    iStack_8 = iStack_14;
    in_ECX[3] = iStack_14;
    fVar1 = (float)in_ECX[1];
    if (_DAT_009f840c <
        fVar1 * fVar1 + (float)in_ECX[2] * (float)in_ECX[2] + (float)in_ECX[3] * (float)in_ECX[3]) {
      FUN_0078d900();
    }
  }
  return;
}


// ==== FUN_0078dc40 @ 0x0078dc40 ====

void FUN_0078dc40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998197;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f8418;
  FUN_00718f10();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0078dc90 @ 0x0078dc90 ====

int FUN_0078dc90(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0078dca0 @ 0x0078dca0 ====

void FUN_0078dca0(byte param_1)

{
  void *in_ECX;
  
  FUN_0078daf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078dcc0 @ 0x0078dcc0 ====

void FUN_0078dcc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8430;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078dce0 @ 0x0078dce0 ====

void FUN_0078dce0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8430;
  return;
}


// ==== FUN_0078dcf0 @ 0x0078dcf0 ====

void FUN_0078dcf0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5acb4 = 0;
  *in_ECX = &PTR_FUN_009f8430;
  return;
}


// ==== FUN_0078dd10 @ 0x0078dd10 ====

void FUN_0078dd10(void)

{
  if (DAT_00b5accc != (int *)0x0) {
    (**(code **)(*DAT_00b5accc + 4))();
  }
  return;
}


// ==== FUN_0078dd30 @ 0x0078dd30 ====

void FUN_0078dd30(void)

{
  if (DAT_00b5accc != (int *)0x0) {
    (**(code **)(*DAT_00b5accc + 8))();
  }
  return;
}


// ==== FUN_0078dd50 @ 0x0078dd50 ====

void FUN_0078dd50(void)

{
  if (DAT_00b5acc0 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0078dd61. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5af24 + 4))();
  return;
}


// ==== FUN_0078dd70 @ 0x0078dd70 ====

void FUN_0078dd70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009981b8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f843c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5acb4 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5acb4 = in_ECX;
  }
  if (DAT_00b5accc != (int *)0x0) {
    (**(code **)(*DAT_00b5accc + 4))();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0078dde0 @ 0x0078dde0 ====

void FUN_0078dde0(byte param_1)

{
  void *in_ECX;
  
  FUN_0078dcf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078de00 @ 0x0078de00 ====

void FUN_0078de00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8490;
  return;
}


// ==== FUN_0078de10 @ 0x0078de10 ====

void FUN_0078de10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8490;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078de30 @ 0x0078de30 ====

void FUN_0078de30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8490;
  return;
}


// ==== FUN_0078de40 @ 0x0078de40 ====

void FUN_0078de40(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f849c;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_0078de60 @ 0x0078de60 ====

void FUN_0078de60(void)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5ac28 + 0x3c))(*(undefined4 *)(in_ECX + 4));
  return;
}


// ==== FUN_0078de80 @ 0x0078de80 ====

void FUN_0078de80(byte param_1)

{
  void *in_ECX;
  
  FUN_0078de30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078dea0 @ 0x0078dea0 ====

void FUN_0078dea0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8490;
  return;
}


// ==== FUN_0078deb0 @ 0x0078deb0 ====

void FUN_0078deb0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f84e8;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_0078ded0 @ 0x0078ded0 ====

void FUN_0078ded0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    uRam00000004 = *(undefined4 *)(in_ECX + 4);
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009b62d4;
  puVar1[1] = *(undefined4 *)(in_ECX + 4);
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0078df10 @ 0x0078df10 ====

void FUN_0078df10(byte param_1)

{
  void *in_ECX;
  
  FUN_0078dea0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078df30 @ 0x0078df30 ====

void FUN_0078df30(void)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5ad0c + 0x34))(in_ECX + 4);
  return;
}


// ==== FUN_0078df50 @ 0x0078df50 ====

void FUN_0078df50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8534;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009f8490;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0078df90 @ 0x0078df90 ====

void FUN_0078df90(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009981d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f8534;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0078dff0 @ 0x0078dff0 ====

void FUN_0078dff0(byte param_1)

{
  void *in_ECX;
  
  FUN_0078df50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078e010 @ 0x0078e010 ====

void FUN_0078e010(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8580;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009f8490;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0078e050 @ 0x0078e050 ====

void FUN_0078e050(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998200;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f8580;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_4 = 1;
  FUN_00401660(&param_1,0,0xffffffff);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_0078e0d0 @ 0x0078e0d0 ====

void FUN_0078e0d0(void)

{
  int in_ECX;
  undefined1 auStack_20 [4];
  undefined1 local_1c;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 *local_4;
  
  local_4 = auStack_20;
  local_8 = 0xf;
  local_c = 0;
  local_1c = 0;
  FUN_00401660(in_ECX + 4,0,0xffffffff);
  (**(code **)(*DAT_00b5aca8 + 0xac))();
  return;
}


// ==== FUN_0078e110 @ 0x0078e110 ====

void FUN_0078e110(byte param_1)

{
  void *in_ECX;
  
  FUN_0078e010();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078e130 @ 0x0078e130 ====

void FUN_0078e130(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f85cc;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009f8490;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0078e170 @ 0x0078e170 ====

void FUN_0078e170(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998220;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f85cc;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_4 = 1;
  FUN_00401660(&param_1,0,0xffffffff);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_0078e1f0 @ 0x0078e1f0 ====

void FUN_0078e1f0(void)

{
  int in_ECX;
  undefined1 auStack_20 [4];
  undefined1 local_1c;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 *local_4;
  
  local_4 = auStack_20;
  local_8 = 0xf;
  local_c = 0;
  local_1c = 0;
  FUN_00401660(in_ECX + 4,0,0xffffffff);
  (**(code **)(*DAT_00b5ae3c + 0x98))();
  return;
}


// ==== FUN_0078e230 @ 0x0078e230 ====

void FUN_0078e230(byte param_1)

{
  void *in_ECX;
  
  FUN_0078e130();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078e250 @ 0x0078e250 ====

void FUN_0078e250(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8630;
  if (0xf < (uint)in_ECX[0x15]) {
    _free((void *)in_ECX[0x10]);
    return;
  }
  in_ECX[0x15] = 0xf;
  in_ECX[0x14] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  if (0xf < (uint)in_ECX[0xe]) {
    _free((void *)in_ECX[9]);
    return;
  }
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[6] = 0;
    in_ECX[7] = 0xf;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_009f8490;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0078e2d0 @ 0x0078e2d0 ====

void FUN_0078e2d0(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  undefined1 uStack00000020;
  void *in_stack_00000024;
  uint in_stack_00000038;
  undefined1 uStack0000003c;
  void *in_stack_00000040;
  uint in_stack_00000054;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998266;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f8630;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  local_4 = 3;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(&param_1,0,0xffffffff);
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  local_4._0_1_ = 4;
  *(undefined1 *)(in_ECX + 9) = 0;
  FUN_00401660(&uStack00000020,0,0xffffffff);
  in_ECX[0x15] = 0xf;
  in_ECX[0x14] = 0;
  local_4 = CONCAT31(local_4._1_3_,5);
  *(undefined1 *)(in_ECX + 0x10) = 0;
  FUN_00401660(&uStack0000003c,0,0xffffffff);
  if (0xf < in_stack_0000001c) {
    _free(param_2);
    return;
  }
  if (0xf < in_stack_00000038) {
    _free(in_stack_00000024);
    return;
  }
  if (in_stack_00000054 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000040);
  return;
}


// ==== FUN_0078e3b0 @ 0x0078e3b0 ====

void FUN_0078e3b0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined1 auStack_bc [12];
  undefined4 uStack_b0;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  void **ppvStack_a4;
  undefined *puStack_a0;
  undefined1 auStack_82 [14];
  void *pvStack_74;
  undefined1 auStack_69 [9];
  uint uStack_60;
  undefined1 auStack_58 [4];
  undefined1 uStack_54;
  undefined4 uStack_44;
  undefined4 uStack_40;
  void *apvStack_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998278;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  puStack_a0 = (undefined *)0x78e3e5;
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5100003;
  *(undefined2 *)((int)pvVar2 + 6) = 0x14;
  FUN_004244d0();
  ppvStack_a4 = apvStack_34;
  puStack_a0 = &DAT_009f8620;
  uStack_a8 = 0x78e423;
  FUN_00478000();
  ppvStack_a4 = (void **)auStack_82;
  puStack_a0 = &DAT_009f8624;
  uStack_a8 = 0x78e443;
  FUN_0047aa30();
  ppvStack_a4 = (void **)auStack_69;
  puStack_a0 = &DAT_009f8624;
  uStack_a8 = 0x78e463;
  FUN_0047aa30();
  puStack_a0 = auStack_82;
  ppvStack_a4 = (void **)auStack_69;
  uStack_a8 = 0x78e47c;
  FUN_00774920();
  puStack_a0 = (undefined *)0x78e488;
  FUN_004d8570();
  puStack_a0 = (undefined *)0x0;
  ppvStack_a4 = (void **)0x78e49b;
  uStack_ac = (**(code **)(*DAT_00b5a794 + 0xc))();
  ppvStack_a4 = (void **)0xffffffff;
  uStack_a8 = 0;
  uStack_40 = 0xf;
  uStack_44 = 0;
  uStack_54 = 0;
  uStack_b0 = 0x78e4b9;
  FUN_00401660();
  pvStack_c = (void *)0x0;
  FUN_00401660(auStack_58,0,0xffffffff);
  FUN_00404230(auStack_bc);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  if (uStack_60 < 0x10) {
    ExceptionList = apvStack_34[0];
    return;
  }
  _free(pvStack_74);
  return;
}


// ==== FUN_0078e550 @ 0x0078e550 ====

void FUN_0078e550(byte param_1)

{
  void *in_ECX;
  
  FUN_0078e250();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078e570 @ 0x0078e570 ====

void FUN_0078e570(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (*(int *)(in_ECX + 4) == iVar1) {
    (**(code **)(*DAT_00b5ac28 + 0x10))(*(undefined4 *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_0078e5a0 @ 0x0078e5a0 ====

void FUN_0078e5a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f867c;
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[9] = 0xf;
    in_ECX[8] = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    *in_ECX = &PTR_FUN_009f8490;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_0078e5e0 @ 0x0078e5e0 ====

void FUN_0078e5e0(undefined4 param_1,undefined4 param_2,undefined1 param_3,void *param_4)

{
  undefined4 *in_ECX;
  uint in_stack_00000024;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009982a0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[1] = param_1;
  in_ECX[2] = param_2;
  *in_ECX = &PTR_FUN_009f867c;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  local_4 = 1;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(&param_3,0,0xffffffff);
  if (in_stack_00000024 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_4);
  return;
}


// ==== FUN_0078e660 @ 0x0078e660 ====

void FUN_0078e660(byte param_1)

{
  void *in_ECX;
  
  FUN_0078e5a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078e680 @ 0x0078e680 ====

void FUN_0078e680(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f86c8;
  return;
}


// ==== FUN_0078e690 @ 0x0078e690 ====

void FUN_0078e690(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f86c8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078e6b0 @ 0x0078e6b0 ====

undefined1 FUN_0078e6b0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x14);
}


// ==== FUN_0078e6c0 @ 0x0078e6c0 ====

void FUN_0078e6c0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x14) = param_1;
  return;
}


// ==== FUN_0078e6d0 @ 0x0078e6d0 ====

int FUN_0078e6d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8)) / 0xc;
}


// ==== FUN_0078e6f0 @ 0x0078e6f0 ====

void FUN_0078e6f0(void)

{
  uint in_ECX;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    local_4 = in_ECX & 0xffffff00;
    FUN_00409660(**(undefined4 **)(in_ECX + 0x1c),*(undefined4 **)(in_ECX + 0x1c),local_4);
    FUN_0078e9f0(*(undefined4 *)(*(int *)(in_ECX + 0x1c) + 4));
    *(int *)(*(int *)(in_ECX + 0x1c) + 4) = *(int *)(in_ECX + 0x1c);
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
    *(int *)(*(int *)(in_ECX + 0x1c) + 8) = *(int *)(in_ECX + 0x1c);
  }
  return;
}


// ==== FUN_0078e740 @ 0x0078e740 ====

void FUN_0078e740(undefined4 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_004d8980(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0x1c)) {
    (**(code **)(**(int **)(local_4 + 0x10) + 4))();
  }
  return;
}


// ==== FUN_0078e780 @ 0x0078e780 ====

void FUN_0078e780(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  local_10 = param_1;
  local_c = param_2;
  FUN_0078efa0(local_8,&local_10);
  return;
}


// ==== FUN_0078e7b0 @ 0x0078e7b0 ====

int FUN_0078e7b0(uint param_1)

{
  int iVar1;
  int in_ECX;
  uint extraout_EDX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc)) goto LAB_0078e7dd;
  }
  FUN_0078ea30();
  param_1 = extraout_EDX;
LAB_0078e7dd:
  return iVar1 + param_1 * 0xc;
}


// ==== FUN_0078e7f0 @ 0x0078e7f0 ====

void FUN_0078e7f0(void)

{
  undefined4 *in_ECX;
  uint local_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998309;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f86f4;
  local_4 = 3;
  if ((void *)in_ECX[2] != (void *)0x0) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  if (in_ECX[8] != 0) {
    local_14[0] = local_14[0] & 0xffffff00;
    FUN_00409660(*(undefined4 *)in_ECX[7],(undefined4 *)in_ECX[7],local_14[0]);
    FUN_0078e9f0(*(undefined4 *)(in_ECX[7] + 4));
    *(undefined4 *)(in_ECX[7] + 4) = in_ECX[7];
    in_ECX[8] = 0;
    *(undefined4 *)in_ECX[7] = in_ECX[7];
    *(undefined4 *)(in_ECX[7] + 8) = in_ECX[7];
  }
  if ((uint)in_ECX[0x10] < 0x10) {
    in_ECX[0x10] = 0xf;
    in_ECX[0xf] = 0;
    *(undefined1 *)(in_ECX + 0xb) = 0;
    local_4 = CONCAT31(local_4._1_3_,1);
    FUN_0078f310(local_14,*(undefined4 *)in_ECX[7],(undefined4 *)in_ECX[7]);
    _free((void *)in_ECX[7]);
    return;
  }
  _free((void *)in_ECX[0xb]);
  return;
}


// ==== FUN_0078e900 @ 0x0078e900 ====

void FUN_0078e900(undefined1 param_1)

{
  FUN_0078f440(&param_1);
  return;
}


// ==== FUN_0078e910 @ 0x0078e910 ====

void FUN_0078e910(void)

{
  int iVar1;
  undefined4 *in_ECX;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099833c;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f86f4;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  local_4 = 1;
  *(undefined1 *)(in_ECX + 5) = 0;
  iVar1 = FUN_0058d7c0();
  in_ECX[7] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[7] + 4) = in_ECX[7];
  *(undefined4 *)in_ECX[7] = in_ECX[7];
  *(undefined4 *)(in_ECX[7] + 8) = in_ECX[7];
  in_ECX[8] = 0;
  in_ECX[0x10] = 0xf;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  in_ECX[9] = 0;
  local_18 = 0;
  local_14 = 0x12c0001;
  local_4 = CONCAT31(local_4._1_3_,3);
  local_10 = 0;
  FUN_0078f440(&local_18);
  local_10 = 1;
  local_18 = 0;
  local_14 = 0x12c0002;
  FUN_0078f440(&local_18);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0078e9f0 @ 0x0078e9f0 ====

void FUN_0078e9f0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0078e9f0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0078ea30 @ 0x0078ea30 ====

void FUN_0078ea30(void)

{
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009982b8;
  pvStack_c = ExceptionList;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_invalid_vector<T>_subscript_0099ca88,0x1b);
  local_4 = 0;
  FUN_00403770(local_50);
  local_34[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00a9c7c8);
}


// ==== FUN_0078eaa0 @ 0x0078eaa0 ====

void FUN_0078eaa0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009982b8;
  local_c = ExceptionList;
  if (0x1ffffffd < *(uint *)(in_ECX + 8)) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &local_c;
    FUN_00401740(s_map_set<T>_too_long_0099cd54,0x13);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c48c);
  }
  ExceptionList = &local_c;
  piVar4 = (int *)FUN_00448a90(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[5] == '\0') {
LAB_0078eb99:
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
      if ((char)piVar6[5] == '\0') goto LAB_0078eb99;
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


// ==== FUN_0078ec80 @ 0x0078ec80 ====

void FUN_0078ec80(void)

{
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009982b8;
  pvStack_c = ExceptionList;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_vector<T>_too_long_0099c99c,0x12);
  local_4 = 0;
  FUN_00403770(local_50);
  local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00a9c48c);
}


// ==== FUN_0078ecf0 @ 0x0078ecf0 ====

/* WARNING: Removing unreachable block (ram,0x0078ee03) */
/* WARNING: Removing unreachable block (ram,0x0078ee13) */
/* WARNING: Removing unreachable block (ram,0x0078ee1c) */
/* WARNING: Removing unreachable block (ram,0x0078ee1f) */
/* WARNING: Removing unreachable block (ram,0x0078ee0f) */
/* WARNING: Removing unreachable block (ram,0x0078ee2d) */
/* WARNING: Removing unreachable block (ram,0x0078ee3a) */
/* WARNING: Removing unreachable block (ram,0x0078ee45) */
/* WARNING: Removing unreachable block (ram,0x0078ee41) */
/* WARNING: Removing unreachable block (ram,0x0078ee35) */
/* WARNING: Removing unreachable block (ram,0x0078ee48) */

void FUN_0078ecf0(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  int *piVar6;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009982b8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x15) != '\0') {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &pvStack_c;
    FUN_00401740(s_invalid_map_set<T>_iterator_0099cd68,0x1b);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c7c8);
  }
  ExceptionList = &pvStack_c;
  FUN_00458720();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x15) == '\0') {
    if (*(char *)(param_2[2] + 0x15) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x15) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x15) == '\0') {
      piVar3 = (int *)FUN_004cf3b0(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x15) == '\0') {
      uVar4 = FUN_004489e0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[5] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[5] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[5] == '\0') {
            *(undefined1 *)(piVar5 + 5) = 1;
            *(undefined1 *)(piVar3 + 5) = 0;
            FUN_00448a00(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            if ((*(char *)(*piVar5 + 0x14) == '\x01') && (*(char *)(piVar5[2] + 0x14) == '\x01'))
            goto LAB_0078ef15;
            if (*(char *)(piVar5[2] + 0x14) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x14) = 1;
              *(undefined1 *)(piVar5 + 5) = 0;
              FUN_00519c40(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 5) = (char)piVar3[5];
            *(undefined1 *)(piVar3 + 5) = 1;
            *(undefined1 *)(piVar5[2] + 0x14) = 1;
            FUN_00448a00(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[5] == '\0') {
            *(undefined1 *)(piVar5 + 5) = 1;
            *(undefined1 *)(piVar3 + 5) = 0;
            FUN_00519c40(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x15) == '\0') {
            if ((*(char *)(piVar5[2] + 0x14) != '\x01') || (*(char *)(*piVar5 + 0x14) != '\x01')) {
              if (*(char *)(*piVar5 + 0x14) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x14) = 1;
                *(undefined1 *)(piVar5 + 5) = 0;
                FUN_00448a00(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 5) = (char)piVar3[5];
              *(undefined1 *)(piVar3 + 5) = 1;
              *(undefined1 *)(*piVar5 + 0x14) = 1;
              FUN_00519c40(piVar3);
              break;
            }
LAB_0078ef15:
            *(undefined1 *)(piVar5 + 5) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 5) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_0078efa0 @ 0x0078efa0 ====

void FUN_0078efa0(undefined4 *param_1,int *param_2)

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
      puVar5 = (undefined4 *)FUN_0078eaa0(&param_2,1,puVar5,piVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *piVar3) {
    puVar5 = (undefined4 *)FUN_0078eaa0(&param_2,bVar2,puVar5,piVar3);
    *param_1 = *puVar5;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0078f060 @ 0x0078f060 ====

void FUN_0078f060(int param_1,uint param_2,undefined4 *param_3)

{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  uint extraout_ECX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009982d0;
  local_10 = ExceptionList;
  local_20 = *param_3;
  local_1c = param_3[1];
  iVar3 = *(int *)(in_ECX + 4);
  local_18 = param_3[2];
  local_14 = (undefined1 *)((int)register0x00000010 + -0x2c);
  if (iVar3 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = (*(int *)(in_ECX + 0xc) - iVar3) / 0xc;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x2c);
    if (0x15555555U - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_0078ec80();
      uVar6 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
    }
    if (uVar6 < iVar2 + param_2) {
      if (0x15555555 - (uVar6 >> 1) < uVar6) {
        uVar6 = 0;
      }
      else {
        uVar6 = uVar6 + (uVar6 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0xc;
      }
      if (uVar6 < iVar3 + param_2) {
        iVar3 = FUN_004a3750();
        uVar6 = iVar3 + param_2;
      }
      pvVar4 = operator_new(uVar6 * 0xc);
      local_8 = 0;
      iVar3 = FUN_0042eab0(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_0042ea70(iVar3,param_2,&local_20);
      FUN_0042eab0(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 0xc);
      iVar3 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar3 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0xc;
      }
      if (*(void **)(in_ECX + 4) == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar6 * 0xc + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 0xc);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    iVar3 = *(int *)(in_ECX + 8);
    if ((uint)((iVar3 - param_1) / 0xc) < param_2) {
      FUN_0042eab0(param_1,iVar3,param_2 * 0xc + param_1);
      local_8 = 2;
      FUN_0042edf0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0xc,&local_20);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0xc;
      FUN_006d89e0(param_1,*(int *)(in_ECX + 8) + param_2 * -0xc,&local_20);
      ExceptionList = local_10;
      return;
    }
    iVar2 = iVar3 + param_2 * -0xc;
    uVar5 = FUN_0042eab0(iVar2,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_004ab780(param_1,iVar2,iVar3,iVar2);
    FUN_006d89e0(param_1,param_2 * 0xc + param_1,&local_20);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0078f212 @ 0x0078f212 ====

void Catch_0078f212(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_0078f310 @ 0x0078f310 ====

void FUN_0078f310(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0078e9f0(piVar6[1]);
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
    FUN_0078ecf0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0078f3d0 @ 0x0078f3d0 ====

void FUN_0078f3d0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0xc != 0) {
      iVar1 = (param_2 - iVar1) / 0xc;
      goto LAB_0078f413;
    }
  }
  iVar1 = 0;
LAB_0078f413:
  FUN_0078f060(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0xc;
  return;
}


// ==== FUN_0078f440 @ 0x0078f440 ====

void FUN_0078f440(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc) <= (uint)((*(int *)(in_ECX + 8) - iVar1) / 0xc)
     )) {
    FUN_0078f3d0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0042ea70(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0xc;
  return;
}


// ==== FUN_0078f4c0 @ 0x0078f4c0 ====

void FUN_0078f4c0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0078f310(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0078f4f0 @ 0x0078f4f0 ====

int FUN_0078f4f0(void)

{
  int in_ECX;
  
  return in_ECX + 0x24;
}


// ==== FUN_0078f500 @ 0x0078f500 ====

void FUN_0078f500(byte param_1)

{
  void *in_ECX;
  
  FUN_0078e7f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078f520 @ 0x0078f520 ====

void FUN_0078f520(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f87a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078f540 @ 0x0078f540 ====

void FUN_0078f540(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f87a4;
  return;
}


// ==== FUN_0078f550 @ 0x0078f550 ====

undefined4 FUN_0078f550(void)

{
  return 9;
}


// ==== FUN_0078f560 @ 0x0078f560 ====

void FUN_0078f560(undefined1 param_1)

{
  FUN_007956e0(&param_1);
  return;
}


// ==== FUN_0078f570 @ 0x0078f570 ====

void FUN_0078f570(undefined4 param_1)

{
  FUN_00795a80(param_1);
  return;
}


// ==== FUN_0078f580 @ 0x0078f580 ====

void FUN_0078f580(void)

{
  return;
}


// ==== FUN_0078f590 @ 0x0078f590 ====

void FUN_0078f590(void)

{
  return;
}


// ==== FUN_0078f5a0 @ 0x0078f5a0 ====

void FUN_0078f5a0(void)

{
  return;
}


// ==== FUN_0078f5b0 @ 0x0078f5b0 ====

void FUN_0078f5b0(void)

{
  return;
}


// ==== FUN_0078f5c0 @ 0x0078f5c0 ====

void FUN_0078f5c0(void)

{
  return;
}


// ==== FUN_0078f610 @ 0x0078f610 ====

undefined4 * FUN_0078f610(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f87dc;
  return puVar1;
}


// ==== FUN_0078f630 @ 0x0078f630 ====

undefined4 FUN_0078f630(int *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_100 [256];
  
  iVar2 = (**(code **)(*param_1 + 0x14))();
  bVar1 = *(byte *)(iVar2 + 0x1e);
  if (bVar1 == 0) {
    return 0;
  }
  if (4 < bVar1) {
    auStack_100[0] = 0;
    uVar3 = FUN_0044a580(auStack_100,s_File___s__Line___d_009f8778,
                         s___Inven_State_RemoveStone_cpp_009f8758,0xbe);
    FUN_00797b80(uVar3);
    FUN_00797a40();
  }
  uVar5 = 0;
  if (bVar1 != 0) {
    iVar2 = 4;
    do {
      iVar4 = (**(code **)(*param_1 + 0x14))();
      if (*(short *)(iVar4 + iVar2) != 0) {
        return 1;
      }
      uVar5 = uVar5 + 1;
      iVar2 = iVar2 + 2;
    } while (uVar5 < bVar1);
  }
  return 0;
}


// ==== FUN_0078f6e0 @ 0x0078f6e0 ====

void FUN_0078f6e0(void)

{
  short sVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *in_ECX;
  int iVar7;
  byte bVar8;
  short *psVar9;
  undefined4 *puVar10;
  undefined1 auStack_5e [2];
  undefined4 uStack_5c;
  short asStack_58 [18];
  undefined4 uStack_34;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_8 = &LAB_00998370;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar2 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar2 == '\0') {
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x20) + 0x28))();
    if (piVar4 != (int *)0x0) {
      piVar5 = (int *)(**(code **)(*piVar4 + 0x2c))();
      cVar2 = (**(code **)(*in_ECX + 0x34))();
      if (cVar2 == '\0') {
        iVar3 = piVar5[2];
        if (((iVar3 != 0x10b) && (iVar3 != 0x100)) && (iVar3 != 0x101)) {
          iVar3 = (**(code **)(*piVar4 + 0x14))();
          if (*(char *)(iVar3 + 0x1e) == '\0') {
            (**(code **)(*DAT_00b5a794 + 0xc))();
            FUN_00765c50();
            uStack_14 = 3;
            FUN_00765c50();
            (**(code **)(*DAT_00b5ad0c + 0x28))();
            uStack_34 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          uStack_14 = 2;
          FUN_00765c50();
          (**(code **)(*DAT_00b5ad0c + 0x28))();
          uStack_34 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        iVar3 = (**(code **)(*DAT_00b5b0d0 + 4))();
        if (iVar3 == 0) {
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          uStack_1c = 1;
          FUN_00765c50(auStack_5e + -6);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        iVar3 = piVar5[2];
        if (iVar3 == 0x10b) {
          (**(code **)(*DAT_00b5b0d0 + 0x24))();
        }
        else if (iVar3 == 0x100) {
          (**(code **)(*DAT_00b5b0d0 + 0x20))();
        }
        else if ((iVar3 == 0x101) && (*piVar5 == 0)) {
          (**(code **)(*DAT_00b5b0d0 + 0x30))();
        }
      }
      else {
        cVar2 = (**(code **)(*DAT_00b5b0d0 + 0x58))();
        if (cVar2 != '\x01') {
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          uStack_18 = 0;
          FUN_00765c50();
          (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        uStack_5c._0_2_ = (undefined2)uStack_8;
        uStack_5c._2_1_ = uStack_8._2_1_;
        (**(code **)(*DAT_00b5b0d0 + 0x1c))();
        puVar6 = (undefined4 *)(**(code **)(*piVar4 + 0x14))();
        iVar3 = *piVar4;
        puVar10 = &uStack_5c;
        for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
          *puVar10 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar10 = puVar10 + 1;
        }
        bVar8 = 0;
        (**(code **)(iVar3 + 0x14))();
        psVar9 = asStack_58;
        piVar5 = piVar4;
        do {
          sVar1 = *psVar9;
          (**(code **)(*DAT_00b5b0d0 + 0x2c))();
          if (((char)((uint)piVar5 >> 0x18) == '\x01') && (sVar1 != 0)) {
            (**(code **)(*DAT_00b5b0d0 + 0x28))();
            piVar5 = (int *)0x0;
          }
          bVar8 = bVar8 + 1;
          psVar9 = psVar9 + 1;
          (**(code **)(*piVar4 + 0x14))();
        } while (bVar8 < 4);
      }
      (**(code **)(*DAT_00b5b0cc + 8))();
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0078fa90 @ 0x0078fa90 ====

void FUN_0078fa90(void)

{
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998382;
  pvStack_c = ExceptionList;
  uStack_34 = (undefined1 *)0x3e90031;
  uStack_38 = 0;
  uStack_3c = 0x78fabc;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x78fad9;
  FUN_00401660();
  uStack_34 = auStack_54;
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_c = (void *)0x0;
  uStack_50 = 0;
  FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (uStack_38 < 0x10) {
    ExceptionList = uStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_0078fb40 @ 0x0078fb40 ====

void FUN_0078fb40(byte param_1)

{
  void *in_ECX;
  
  FUN_0078f540();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0078fb60 @ 0x0078fb60 ====

void FUN_0078fb60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f87a4;
  return;
}


// ==== FUN_0078fb70 @ 0x0078fb70 ====

undefined4 FUN_0078fb70(void)

{
  return 8;
}


// ==== FUN_0078fb80 @ 0x0078fb80 ====

void FUN_0078fb80(undefined1 param_1)

{
  FUN_007956e0(&param_1);
  return;
}


// ==== FUN_0078fb90 @ 0x0078fb90 ====

void FUN_0078fb90(undefined4 param_1)

{
  FUN_00795a80(param_1);
  return;
}


// ==== FUN_0078fba0 @ 0x0078fba0 ====

void FUN_0078fba0(void)

{
  return;
}


// ==== FUN_0078fbb0 @ 0x0078fbb0 ====

void FUN_0078fbb0(void)

{
  return;
}


// ==== FUN_0078fbc0 @ 0x0078fbc0 ====

void FUN_0078fbc0(void)

{
  return;
}


// ==== FUN_0078fbd0 @ 0x0078fbd0 ====

void FUN_0078fbd0(void)

{
  return;
}


// ==== FUN_0078fbe0 @ 0x0078fbe0 ====

void FUN_0078fbe0(void)

{
  return;
}


// ==== FUN_0078fc30 @ 0x0078fc30 ====

undefined4 FUN_0078fc30(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  
  iVar2 = (**(code **)(*param_1 + 0x14))();
  cVar1 = *(char *)(iVar2 + 0x1e);
  piVar3 = (int *)(**(code **)(*param_1 + 0x48))();
  if (piVar3 != (int *)0x0) {
    switch((byte)(cVar1 + 1) - 1) {
    case 0:
      iVar2 = (**(code **)(*piVar3 + 4))();
      bVar4 = *(char *)(iVar2 + 0xa5) == '\0';
      break;
    case 1:
      iVar2 = (**(code **)(*piVar3 + 4))();
      bVar4 = *(char *)(iVar2 + 0xa6) == '\0';
      break;
    case 2:
      iVar2 = (**(code **)(*piVar3 + 4))();
      bVar4 = *(char *)(iVar2 + 0xa7) == '\0';
      break;
    case 3:
      iVar2 = (**(code **)(*piVar3 + 4))();
      if (*(char *)(iVar2 + 0xa8) == '\0') {
        return 0;
      }
      return 1;
    default:
      goto switchD_0078fc5b_default;
    }
    if (!bVar4) {
      return 1;
    }
  }
switchD_0078fc5b_default:
  return 0;
}


// ==== FUN_0078fcc0 @ 0x0078fcc0 ====

undefined4 * FUN_0078fcc0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f8868;
  return puVar1;
}


// ==== FUN_0078fce0 @ 0x0078fce0 ====

void FUN_0078fce0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  undefined1 auStack_5c [4];
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009983a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x20) + 0x28))();
    if (piVar3 != (int *)0x0) {
      piVar3 = (int *)(**(code **)(*piVar3 + 0x2c))();
      cVar1 = (**(code **)(*in_ECX + 0x34))();
      if (cVar1 == '\0') {
        if ((piVar3[2] != 0x102) && (piVar3[2] != 0x100)) {
          if (*piVar3 == 4) {
            (**(code **)(*DAT_00b5a794 + 0xc))();
            FUN_00765c50();
            uStack_14 = 1;
            FUN_00765c50(auStack_5c + 8);
            (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          uStack_14 = 2;
          FUN_00765c50(auStack_38);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        iVar2 = (**(code **)(*DAT_00b5b0f4 + 4))();
        if (iVar2 == 0) {
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          uStack_14 = 0;
          FUN_00765c50(auStack_5c + 8);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        if (piVar3[2] == 0x102) {
          (**(code **)(*DAT_00b5b0f4 + 0x1c))();
        }
        else {
          (**(code **)(*DAT_00b5b0f4 + 0x18))();
        }
      }
      else {
        (**(code **)(*DAT_00b5b0f4 + 0x14))();
      }
      (**(code **)(*DAT_00b5b0f0 + 8))();
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0078ff30 @ 0x0078ff30 ====

void FUN_0078ff30(void)

{
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009983ba;
  pvStack_c = ExceptionList;
  uStack_34 = (undefined1 *)0x3e90002;
  uStack_38 = 0;
  uStack_3c = 0x78ff5c;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x78ff79;
  FUN_00401660();
  uStack_34 = auStack_54;
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_c = (void *)0x0;
  uStack_50 = 0;
  FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (uStack_38 < 0x10) {
    ExceptionList = uStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_0078ffe0 @ 0x0078ffe0 ====

void FUN_0078ffe0(byte param_1)

{
  void *in_ECX;
  
  FUN_0078fb60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


