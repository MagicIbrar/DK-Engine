// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x600000-0x60ffff

// ==== FUN_00600040 @ 0x00600040 ====

void FUN_00600040(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0;
  (**(code **)(**(int **)(in_ECX + 0x14) + 8))();
  (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))();
  (**(code **)(**(int **)(in_ECX + 0x10) + 0xc))();
  *(undefined4 *)(in_ECX + 0x20) = 0;
  FUN_00797a50(in_ECX + 8,0,2);
  return;
}


// ==== FUN_00600080 @ 0x00600080 ====

uint FUN_00600080(undefined4 param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 8))();
  while( true ) {
    if (puVar1 == (undefined4 *)0x0) {
      return 1;
    }
    uVar2 = (**(code **)(*(int *)*puVar1 + 0x28))(param_1);
    if ((char)uVar2 == '\0') break;
    puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x48))(puVar1);
  }
  return uVar2 & 0xffffff00;
}


// ==== __break @ 0x006000cc ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_006000d0 @ 0x006000d0 ====

undefined4 FUN_006000d0(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_fe [254];
  
  *(short *)(in_ECX + 8) = (short)param_1;
  (**(code **)(**(int **)(in_ECX + 0xc) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x10) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x14) + 4))();
  iVar1 = (**(code **)(*DAT_00b5ab14 + 8))(param_1);
  *(int *)(in_ECX + 0x18) = iVar1;
  if (iVar1 == 0) {
    uVar2 = FUN_0044a580(auStack_fe + -6,s_Invaild_Map_Index_____d__009c869c,param_1 & 0xffff);
    FUN_00797b80(uVar2);
    return 0;
  }
  iVar1 = (**(code **)(*DAT_00b5ab1c + 8))(param_1);
  *(int *)(in_ECX + 0x1c) = iVar1;
  if (iVar1 == 0) {
    uVar2 = FUN_0044a580(auStack_fe + -10,s_Invaild_LevelCap_Flyweight_Index_009c86b8,
                         param_1 & 0xffff);
    FUN_00797b80(uVar2);
    return 0;
  }
  *(undefined4 *)(in_ECX + 0x20) = 0;
  return 1;
}


// ==== FUN_006001a0 @ 0x006001a0 ====

bool FUN_006001a0(ushort *param_1)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  undefined1 local_100 [256];
  
  if (*(int *)(in_ECX + 0x18) == 0) {
    local_100[0] = 0;
    uVar3 = FUN_0044a580(local_100,s_File___s__Line___d_009c8740,s___Map_Provider_cpp_009c872c,0x8a)
    ;
    FUN_00797b80(uVar3);
    FUN_00797a40();
  }
  iVar4 = (**(code **)(**(int **)(in_ECX + 0x18) + 4))();
  uVar5 = (uint)*param_1;
  if ((uVar5 < *(uint *)(iVar4 + 4)) && (uVar6 = (uint)param_1[1], uVar6 < *(uint *)(iVar4 + 8))) {
    piVar1 = *(int **)(iVar4 + 0xc + (uVar6 * *(uint *)(iVar4 + 4) + uVar5) * 4);
    if (piVar1 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar1 + 4))();
      if (*(char *)(iVar4 + 8) == '\x01') {
        return false;
      }
      cVar2 = FUN_00600080(param_1);
      return cVar2 != '\0';
    }
    pcVar7 = s_NULL_Cell_Flyweight___poscell_____009c878c;
  }
  else {
    uVar6 = (uint)param_1[1];
    pcVar7 = s_Map__IsMovalbeCell___poscell___d_009c8754;
  }
  local_100[0] = 0;
  uVar3 = FUN_0044a580(local_100,pcVar7,uVar5,uVar6);
  FUN_00797b80(uVar3);
  return false;
}


// ==== FUN_00600280 @ 0x00600280 ====

bool FUN_00600280(ushort *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  undefined1 auStack_100 [256];
  
  iVar3 = (**(code **)(**(int **)(in_ECX + 0x18) + 4))();
  uVar5 = (uint)*param_1;
  if ((uVar5 < *(uint *)(iVar3 + 4)) && (uVar6 = (uint)param_1[1], uVar6 < *(uint *)(iVar3 + 8))) {
    piVar1 = *(int **)(iVar3 + 0xc + (uVar6 * *(uint *)(iVar3 + 4) + uVar5) * 4);
    if (piVar1 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar1 + 4))();
      if (*(char *)(iVar3 + 9) == '\x01') {
        return false;
      }
      cVar2 = FUN_00600080(param_1);
      return cVar2 != '\0';
    }
    pcVar7 = s_NULL_Cell_Flyweight___poscell_____009c87f0;
  }
  else {
    uVar6 = (uint)param_1[1];
    pcVar7 = s_Map__IsMovalbeCell___poscell___d_009c87b8;
  }
  auStack_100[0] = 0;
  uVar4 = FUN_0044a580(auStack_100,pcVar7,uVar5,uVar6);
  FUN_00797b80(uVar4);
  return false;
}


// ==== __break @ 0x0060032e ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00600330 @ 0x00600330 ====

uint FUN_00600330(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  undefined4 auStack_104 [65];
  
  auStack_104[0] = param_1;
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x28))();
  if (iVar1 == 0) {
    return 1;
  }
  FUN_0044a580(auStack_104,&DAT_009c881c,s___assert___Duplicate_Creature_009c86e4);
  uVar2 = FUN_00797b80(auStack_104);
  return uVar2 & 0xffffff00;
}


// ==== FUN_00600380 @ 0x00600380 ====

undefined4 FUN_00600380(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 auStack_fe [254];
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x38))(param_1);
  if (iVar1 == 0) {
    FUN_0044a580(auStack_fe + -6,&DAT_009c881c,s___assert___Unlink_Invalid_Creatu_009c8704);
    FUN_00797b80(auStack_fe + -6);
    return 0;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x3c))(iVar1);
  return 1;
}


// ==== FUN_006003e0 @ 0x006003e0 ====

void FUN_006003e0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009868e6;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c88dc;
  pvVar1 = operator_new(0x144);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006008a0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  in_ECX[6] = 0;
  pvVar1 = operator_new(0xa4);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0062a820();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0x24);
  local_4._0_1_ = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0062a700();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4._0_1_ = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00629c20();
  }
  in_ECX[5] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[8] = 0;
  FUN_00797a50(in_ECX + 2,0,2);
  ExceptionList = local_c;
  return;
}


// ==== FUN_006004e0 @ 0x006004e0 ====

void FUN_006004e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c886c;
  return;
}


// ==== FUN_006004f0 @ 0x006004f0 ====

void FUN_006004f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c88c4;
  return;
}


// ==== FUN_00600500 @ 0x00600500 ====

void FUN_00600500(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c886c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600520 @ 0x00600520 ====

void FUN_00600520(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c88c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600540 @ 0x00600540 ====

void FUN_00600540(byte param_1)

{
  void *in_ECX;
  
  FUN_005fffb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600560 @ 0x00600560 ====

void FUN_00600560(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8924;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,10,FUN_006ef6d0);
  return;
}


// ==== FUN_00600580 @ 0x00600580 ====

void FUN_00600580(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986903;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c892c;
  local_4 = 1;
  if ((void *)in_ECX[0x4a] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c8924;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,10,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c88c4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x4a]);
  return;
}


// ==== FUN_00600600 @ 0x00600600 ====

undefined4 FUN_00600600(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x124);
}


// ==== FUN_00600610 @ 0x00600610 ====

undefined4 FUN_00600610(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c41c0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x18);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x18);
    }
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(in_ECX + 300);
    *(int *)(in_ECX + 0x124) = *(int *)(in_ECX + 0x124) + -1;
    *(int *)(in_ECX + 300) = param_2;
  }
  return 0;
}


// ==== FUN_00600690 @ 0x00600690 ====

void FUN_00600690(byte param_1)

{
  void *in_ECX;
  
  FUN_00600560();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006006b0 @ 0x006006b0 ====

void FUN_006006b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00600580();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006006d0 @ 0x006006d0 ====

undefined4 * FUN_006006d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[6] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c41c0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[6] = param_2[6] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 300);
  *(int *)(in_ECX + 0x124) = *(int *)(in_ECX + 0x124) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x1c);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[5] = *(undefined4 *)(in_ECX + 0x128);
    *(undefined4 **)(in_ECX + 0x128) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 300) = puVar2[4];
  }
  puVar2[4] = 0;
  puVar2[6] = param_1;
  return puVar2;
}


// ==== FUN_00600790 @ 0x00600790 ====

void FUN_00600790(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986918;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c892c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c8924;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x1c,10,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x48] = 0;
  in_ECX[0x48] = in_ECX[0x48] + 10;
  in_ECX[0x49] = 0;
  in_ECX[0x4a] = 0;
  in_ECX[0x4b] = in_ECX + 2;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[6] = in_ECX + 9;
  in_ECX[0xd] = in_ECX + 0x10;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x14] = in_ECX + 0x17;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x1b] = in_ECX + 0x1e;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x22] = in_ECX + 0x25;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x29] = in_ECX + 0x2c;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x30] = in_ECX + 0x33;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x37] = in_ECX + 0x3a;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  in_ECX[0x3e] = in_ECX + 0x41;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x45] = 0;
  in_ECX[0x46] = 0;
  in_ECX[0x47] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006008a0 @ 0x006008a0 ====

void FUN_006008a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986938;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8944;
  FUN_00600790();
  in_ECX[3] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006008f0 @ 0x006008f0 ====

undefined4 FUN_006008f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00600900 @ 0x00600900 ====

void FUN_00600900(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00600905. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(in_ECX + 0x14) + 8))();
  return;
}


// ==== FUN_00600910 @ 0x00600910 ====

void FUN_00600910(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    iVar2 = *(int *)(in_ECX + 4);
    do {
      iVar1 = *(int *)(iVar2 + 8);
      (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,iVar2);
      iVar2 = iVar1;
    } while (iVar1 != 0);
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00600940 @ 0x00600940 ====

uint * FUN_00600940(uint param_1)

{
  uint *puVar1;
  int in_ECX;
  
  puVar1 = *(uint **)(in_ECX + 8);
  while( true ) {
    if (puVar1 == (uint *)0x0) {
      return (uint *)0x0;
    }
    if ((*puVar1 <= param_1) && (param_1 <= *puVar1)) break;
    puVar1 = (uint *)puVar1[3];
  }
  return puVar1;
}


// ==== FUN_00600970 @ 0x00600970 ====

void FUN_00600970(byte param_1)

{
  void *in_ECX;
  
  FUN_00600990();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600990 @ 0x00600990 ====

void FUN_00600990(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00986963;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8944;
  local_4 = 1;
  FUN_0063f4a0();
  local_4 = local_4 & 0xffffff00;
  FUN_00600580();
  *in_ECX = &PTR_FUN_009c886c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006009f0 @ 0x006009f0 ====

void FUN_006009f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c899c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600a10 @ 0x00600a10 ====

int FUN_00600a10(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00600a20 @ 0x00600a20 ====

void FUN_00600a20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c899c;
  return;
}


// ==== FUN_00600a30 @ 0x00600a30 ====

void FUN_00600a30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c89a8;
  *(undefined1 *)((int)in_ECX + 0xf) = 0;
  return;
}


// ==== FUN_00600a40 @ 0x00600a40 ====

void FUN_00600a40(undefined2 *param_1)

{
  char cVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *(undefined2 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 2);
  *(undefined1 *)(in_ECX + 0xc) = *(undefined1 *)(param_1 + 4);
  *(undefined1 *)(in_ECX + 0xd) = *(undefined1 *)((int)param_1 + 9);
  *(undefined1 *)(in_ECX + 0xe) = *(undefined1 *)(param_1 + 5);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0xb);
    *(char *)(uVar2 + 0xb + in_ECX + 4) = cVar1;
    if (cVar1 == '\0') goto LAB_00600a9b;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 0xf) = 0;
LAB_00600a9b:
  puVar4 = (undefined4 *)(param_1 + 0x86);
  puVar5 = (undefined4 *)(in_ECX + 0x110);
  for (iVar3 = 0x17; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  return;
}


// ==== FUN_00600ac0 @ 0x00600ac0 ====

void FUN_00600ac0(byte param_1)

{
  void *in_ECX;
  
  FUN_00600a20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600ae0 @ 0x00600ae0 ====

void FUN_00600ae0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c89b4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600b00 @ 0x00600b00 ====

void FUN_00600b00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c89b4;
  return;
}


// ==== FUN_00600b10 @ 0x00600b10 ====

int FUN_00600b10(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00600b20 @ 0x00600b20 ====

void FUN_00600b20(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  return;
}


// ==== FUN_00600b40 @ 0x00600b40 ====

void FUN_00600b40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c89c4;
  *(undefined2 *)(in_ECX + 2) = 0;
  *(undefined2 *)((int)in_ECX + 10) = 0;
  return;
}


// ==== FUN_00600b60 @ 0x00600b60 ====

void FUN_00600b60(byte param_1)

{
  void *in_ECX;
  
  FUN_00600b00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600b80 @ 0x00600b80 ====

void FUN_00600b80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c89d4;
  return;
}


// ==== FUN_00600b90 @ 0x00600b90 ====

void FUN_00600b90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c89d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600bb0 @ 0x00600bb0 ====

void FUN_00600bb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c89ec;
  return;
}


// ==== FUN_00600bc0 @ 0x00600bc0 ====

void FUN_00600bc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8a44;
  return;
}


// ==== FUN_00600bd0 @ 0x00600bd0 ====

void FUN_00600bd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8a5c;
  return;
}


// ==== FUN_00600be0 @ 0x00600be0 ====

void FUN_00600be0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c89ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600c00 @ 0x00600c00 ====

void FUN_00600c00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8a44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600c20 @ 0x00600c20 ====

void FUN_00600c20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8a5c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600c40 @ 0x00600c40 ====

undefined4 FUN_00600c40(ushort param_1)

{
  int *piVar1;
  int in_ECX;
  uint local_8 [2];
  
  local_8[0] = (uint)param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_00600c70 @ 0x00600c70 ====

undefined4 FUN_00600c70(void)

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


// ==== FUN_00600c90 @ 0x00600c90 ====

undefined4 FUN_00600c90(void)

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


// ==== FUN_00600cb0 @ 0x00600cb0 ====

void FUN_00600cb0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986978;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c8a7c;
  DAT_00b5abbc = 0;
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
  *in_ECX = &PTR_FUN_009c89d4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00600d50 @ 0x00600d50 ====

void FUN_00600d50(ushort *param_1)

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
  puStack_8 = &LAB_0098698d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x18);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0062a8c0();
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


// ==== FUN_00600de0 @ 0x00600de0 ====

void FUN_00600de0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009869b5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8a7c;
  in_ECX[3] = 0;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00600ef0();
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
    uVar3 = FUN_00601490(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abbc = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abbc = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00600eb0 @ 0x00600eb0 ====

void FUN_00600eb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8a74;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00600ed0 @ 0x00600ed0 ====

void FUN_00600ed0(byte param_1)

{
  void *in_ECX;
  
  FUN_00600eb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600ef0 @ 0x00600ef0 ====

void FUN_00600ef0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009869c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8a94;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c8a74;
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


// ==== FUN_00600fa0 @ 0x00600fa0 ====

void FUN_00600fa0(byte param_1)

{
  void *in_ECX;
  
  FUN_00600fc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00600fc0 @ 0x00600fc0 ====

void FUN_00600fc0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009869f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8a94;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c8a74;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c8a44;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_00601040 @ 0x00601040 ====

void * FUN_00601040(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00986a0b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c8aa8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00601120 @ 0x00601120 ====

undefined4 FUN_00601120(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8aa8,0xa9);
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


// ==== FUN_006011a0 @ 0x006011a0 ====

void FUN_006011a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00600cb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006011c0 @ 0x006011c0 ====

void FUN_006011c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8b28;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_006011e0 @ 0x006011e0 ====

void FUN_006011e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986a33;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8b30;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c8b28;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c8a5c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_00601260 @ 0x00601260 ====

undefined4 FUN_00601260(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8aa8,0xa9);
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


// ==== FUN_006012e0 @ 0x006012e0 ====

undefined4 * FUN_006012e0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8aa8,0x85);
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


// ==== FUN_006013a0 @ 0x006013a0 ====

void FUN_006013a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006011c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006013c0 @ 0x006013c0 ====

void FUN_006013c0(byte param_1)

{
  void *in_ECX;
  
  FUN_006011e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006013e0 @ 0x006013e0 ====

void FUN_006013e0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986a48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8b30;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c8b28;
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


// ==== FUN_00601490 @ 0x00601490 ====

void FUN_00601490(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986a68;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8b4c;
  FUN_006013e0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006014f0 @ 0x006014f0 ====

void FUN_006014f0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00601510(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00601510 @ 0x00601510 ====

void FUN_00601510(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00601510(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00601510(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00601550 @ 0x00601550 ====

void FUN_00601550(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00601570(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00601570 @ 0x00601570 ====

void FUN_00601570(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00601570(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00601570(param_1[3]);
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


// ==== FUN_006015e0 @ 0x006015e0 ====

void FUN_006015e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00601600();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00601600 @ 0x00601600 ====

void FUN_00601600(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00986a93;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8b4c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00601570(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_006011e0();
  *in_ECX = &PTR_FUN_009c89ec;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00601670 @ 0x00601670 ====

void FUN_00601670(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8ba4;
  return;
}


// ==== FUN_00601680 @ 0x00601680 ====

void FUN_00601680(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8ba4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006016a0 @ 0x006016a0 ====

void FUN_006016a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8bb4;
  return;
}


// ==== FUN_006016b0 @ 0x006016b0 ====

void FUN_006016b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8bb4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006016e0 @ 0x006016e0 ====

void FUN_006016e0(void)

{
  FUN_0062ab60();
  return;
}


// ==== FUN_006016f0 @ 0x006016f0 ====

void FUN_006016f0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_0062aa00();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00601710 @ 0x00601710 ====

void FUN_00601710(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986af3;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8bec;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abf4 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5abf4 = in_ECX;
  }
  pvVar2 = operator_new(0x34);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_00601850();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006017b0 @ 0x006017b0 ====

void FUN_006017b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986b05;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8bec;
  DAT_00b5abf4 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c8ba4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00601810 @ 0x00601810 ====

undefined4 FUN_00601810(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  FUN_0062a920();
  return uVar1;
}


// ==== FUN_00601830 @ 0x00601830 ====

void FUN_00601830(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8bcc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,1,(_func_void_void_ptr *)&LAB_006016d0);
  return;
}


// ==== FUN_00601850 @ 0x00601850 ====

void FUN_00601850(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986aa8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8bd4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c8bcc;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x1c,1,FUN_006016e0,(_func_void_void_ptr *)&LAB_006016d0);
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


// ==== FUN_006018d0 @ 0x006018d0 ====

undefined4 FUN_006018d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}


// ==== FUN_006018e0 @ 0x006018e0 ====

void FUN_006018e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00601830();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00601900 @ 0x00601900 ====

void FUN_00601900(byte param_1)

{
  void *in_ECX;
  
  FUN_00601920();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00601920 @ 0x00601920 ====

void FUN_00601920(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986ad3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8bd4;
  _Memory = (void *)in_ECX[0xb];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c8bcc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,1,(_func_void_void_ptr *)&LAB_006016d0);
    *in_ECX = &PTR_FUN_009c8bb4;
    ExceptionList = local_c;
    return;
  }
  FUN_0062a960();
  _free(_Memory);
  return;
}


// ==== FUN_006019b0 @ 0x006019b0 ====

void * FUN_006019b0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00986b29;
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
        FUN_0062ab60();
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
                           s_d__usa_24_0_1_2__develop_share_l_009c8bf8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x18) = *(int *)((int)param_2 + 0x18) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00601ab0 @ 0x00601ab0 ====

undefined4 FUN_00601ab0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8bf8,0xa9);
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


// ==== FUN_00601b30 @ 0x00601b30 ====

void FUN_00601b30(byte param_1)

{
  void *in_ECX;
  
  FUN_006017b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00601b50 @ 0x00601b50 ====

void FUN_00601b50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8c78;
  return;
}


// ==== FUN_00601b60 @ 0x00601b60 ====

void FUN_00601b60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8c78;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00601b80 @ 0x00601b80 ====

void FUN_00601b80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8c88;
  return;
}


// ==== FUN_00601b90 @ 0x00601b90 ====

void FUN_00601b90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8c88;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00601bc0 @ 0x00601bc0 ====

void FUN_00601bc0(void)

{
  FUN_0062b440();
  return;
}


// ==== FUN_00601bd0 @ 0x00601bd0 ====

void FUN_00601bd0(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00601bf0 @ 0x00601bf0 ====

void FUN_00601bf0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986b93;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8cc0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abf8 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5abf8 = in_ECX;
  }
  pvVar2 = operator_new(0x34);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_00601d40();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00601c90 @ 0x00601c90 ====

void FUN_00601c90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986ba5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8cc0;
  DAT_00b5abf8 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c8c78;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00601cf0 @ 0x00601cf0 ====

uint FUN_00601cf0(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  undefined4 unaff_ESI;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  cVar1 = (**(code **)(*piVar2 + 4))(unaff_ESI);
  return -(uint)(cVar1 != '\0') & (uint)piVar2;
}


// ==== FUN_00601d20 @ 0x00601d20 ====

void FUN_00601d20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8ca0;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,1,(_func_void_void_ptr *)&LAB_00601bb0);
  return;
}


// ==== FUN_00601d40 @ 0x00601d40 ====

void FUN_00601d40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986b48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8ca8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c8ca0;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x1c,1,FUN_00601bc0,(_func_void_void_ptr *)&LAB_00601bb0);
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


// ==== FUN_00601dc0 @ 0x00601dc0 ====

void FUN_00601dc0(byte param_1)

{
  void *in_ECX;
  
  FUN_00601d20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00601de0 @ 0x00601de0 ====

void FUN_00601de0(byte param_1)

{
  void *in_ECX;
  
  FUN_00601e00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00601e00 @ 0x00601e00 ====

void FUN_00601e00(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986b73;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8ca8;
  _Memory = (void *)in_ECX[0xb];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c8ca0;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,1,(_func_void_void_ptr *)&LAB_00601bb0);
    *in_ECX = &PTR_FUN_009c8c88;
    ExceptionList = local_c;
    return;
  }
  FUN_0062b400();
  _free(_Memory);
  return;
}


// ==== FUN_00601e90 @ 0x00601e90 ====

void * FUN_00601e90(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00986bc9;
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
        FUN_0062b440();
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
                           s_d__usa_24_0_1_2__develop_share_l_009c8cd0,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x18) = *(int *)((int)param_2 + 0x18) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00601f90 @ 0x00601f90 ====

undefined4 FUN_00601f90(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8cd0,0xa9);
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


// ==== FUN_00602010 @ 0x00602010 ====

void FUN_00602010(byte param_1)

{
  void *in_ECX;
  
  FUN_00601c90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602030 @ 0x00602030 ====

void FUN_00602030(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8d48;
  return;
}


// ==== FUN_00602040 @ 0x00602040 ====

void FUN_00602040(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8d48;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602060 @ 0x00602060 ====

void FUN_00602060(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8d5c;
  return;
}


// ==== FUN_00602070 @ 0x00602070 ====

void FUN_00602070(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8db4;
  return;
}


// ==== FUN_00602080 @ 0x00602080 ====

void FUN_00602080(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8dcc;
  return;
}


// ==== FUN_00602090 @ 0x00602090 ====

void FUN_00602090(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8d5c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006020b0 @ 0x006020b0 ====

void FUN_006020b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8db4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006020d0 @ 0x006020d0 ====

void FUN_006020d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8dcc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006020f0 @ 0x006020f0 ====

undefined4 FUN_006020f0(undefined2 param_1)

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


// ==== FUN_00602120 @ 0x00602120 ====

void FUN_00602120(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986be8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c8dec;
  DAT_00b5abc0 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
    *(undefined4 *)(*piVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c8d48;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006021c0 @ 0x006021c0 ====

void FUN_006021c0(undefined2 *param_1)

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
  puStack_8 = &LAB_00986bfd;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x2ac);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0062b540();
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


// ==== FUN_00602250 @ 0x00602250 ====

void FUN_00602250(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00986c25;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8dec;
  pvVar2 = operator_new(0xb8);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00602360();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x128);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00602970(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abc0 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abc0 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00602320 @ 0x00602320 ====

void FUN_00602320(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8de4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,8,FUN_006ef6d0);
  return;
}


// ==== FUN_00602340 @ 0x00602340 ====

void FUN_00602340(byte param_1)

{
  void *in_ECX;
  
  FUN_00602320();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602360 @ 0x00602360 ====

void FUN_00602360(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986c38;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8dfc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c8de4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,8,FUN_00419fa0,FUN_006ef6d0);
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


// ==== FUN_00602440 @ 0x00602440 ====

void FUN_00602440(byte param_1)

{
  void *in_ECX;
  
  FUN_00602460();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602460 @ 0x00602460 ====

void FUN_00602460(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986c63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8dfc;
  local_4 = 1;
  if ((void *)in_ECX[0x2c] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c8de4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,8,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c8db4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x2c]);
  return;
}


// ==== FUN_006024e0 @ 0x006024e0 ====

void * FUN_006024e0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00986c7b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0xb4);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xac) = *(int *)(in_ECX + 0xac) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c8e10,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_006025c0 @ 0x006025c0 ====

undefined4 FUN_006025c0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8e10,0xa9);
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


// ==== FUN_00602640 @ 0x00602640 ====

void FUN_00602640(byte param_1)

{
  void *in_ECX;
  
  FUN_00602120();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602660 @ 0x00602660 ====

void FUN_00602660(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8e8c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,8,FUN_006ef6d0);
  return;
}


// ==== FUN_00602680 @ 0x00602680 ====

void FUN_00602680(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986ca3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8e94;
  local_4 = 1;
  if ((void *)in_ECX[0x44] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c8e8c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,8,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c8dcc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x44]);
  return;
}


// ==== FUN_00602700 @ 0x00602700 ====

undefined4 FUN_00602700(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8e10,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x114);
    *(int *)(in_ECX + 0x10c) = *(int *)(in_ECX + 0x10c) + -1;
    *(int *)(in_ECX + 0x114) = param_2;
  }
  return 0;
}


// ==== FUN_00602780 @ 0x00602780 ====

undefined4 * FUN_00602780(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8e10,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x114);
  *(int *)(in_ECX + 0x10c) = *(int *)(in_ECX + 0x10c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x110);
    *(undefined4 **)(in_ECX + 0x110) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x114) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_00602840 @ 0x00602840 ====

void FUN_00602840(byte param_1)

{
  void *in_ECX;
  
  FUN_00602660();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602860 @ 0x00602860 ====

void FUN_00602860(byte param_1)

{
  void *in_ECX;
  
  FUN_00602680();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602880 @ 0x00602880 ====

void FUN_00602880(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986cb8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8e94;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c8e8c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,8,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x42] = 0;
  in_ECX[0x42] = in_ECX[0x42] + 8;
  in_ECX[0x43] = 0;
  in_ECX[0x44] = 0;
  in_ECX[0x45] = in_ECX + 2;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[7] = in_ECX + 10;
  in_ECX[0xf] = in_ECX + 0x12;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x17] = in_ECX + 0x1a;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1f] = in_ECX + 0x22;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x27] = in_ECX + 0x2a;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2f] = in_ECX + 0x32;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x37] = in_ECX + 0x3a;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00602970 @ 0x00602970 ====

void FUN_00602970(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986cd8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8eac;
  FUN_00602880();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006029d0 @ 0x006029d0 ====

void FUN_006029d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006029f0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006029f0 @ 0x006029f0 ====

void FUN_006029f0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_006029f0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_006029f0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00602a30 @ 0x00602a30 ====

void FUN_00602a30(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00602a50(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00602a50 @ 0x00602a50 ====

void FUN_00602a50(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00602a50(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00602a50(param_1[3]);
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


// ==== FUN_00602ac0 @ 0x00602ac0 ====

void FUN_00602ac0(byte param_1)

{
  void *in_ECX;
  
  FUN_00602ae0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602ae0 @ 0x00602ae0 ====

void FUN_00602ae0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00986d03;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8eac;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00602a50(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00602680();
  *in_ECX = &PTR_FUN_009c8d5c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00602b50 @ 0x00602b50 ====

void FUN_00602b50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8f04;
  return;
}


// ==== FUN_00602b60 @ 0x00602b60 ====

void FUN_00602b60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8f04;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602b80 @ 0x00602b80 ====

void FUN_00602b80(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00602b85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_00602b90 @ 0x00602b90 ====

undefined4 FUN_00602b90(undefined2 param_1)

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


// ==== FUN_00602bc0 @ 0x00602bc0 ====

undefined4 FUN_00602bc0(void)

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


// ==== FUN_00602be0 @ 0x00602be0 ====

undefined4 FUN_00602be0(void)

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


// ==== FUN_00602c10 @ 0x00602c10 ====

void FUN_00602c10(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986d18;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c8fb4;
  DAT_00b5abc4 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
    *(undefined4 *)(*piVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c8f04;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00602cb0 @ 0x00602cb0 ====

void FUN_00602cb0(undefined2 *param_1)

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
  puStack_8 = &LAB_00986d2d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x10);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0062b7f0();
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


// ==== FUN_00602d40 @ 0x00602d40 ====

void FUN_00602d40(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00986d55;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8fb4;
  pvVar2 = operator_new(0x7c);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00602ed0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(200);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00603480(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abc4 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abc4 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00602e00 @ 0x00602e00 ====

void FUN_00602e00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8f24;
  return;
}


// ==== FUN_00602e10 @ 0x00602e10 ====

void FUN_00602e10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8f7c;
  return;
}


// ==== FUN_00602e20 @ 0x00602e20 ====

void FUN_00602e20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8f94;
  return;
}


// ==== FUN_00602e30 @ 0x00602e30 ====

void FUN_00602e30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8f24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602e50 @ 0x00602e50 ====

void FUN_00602e50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8f7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602e70 @ 0x00602e70 ====

void FUN_00602e70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8f94;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602e90 @ 0x00602e90 ====

void FUN_00602e90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8fac;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,5,FUN_006ef6d0);
  return;
}


// ==== FUN_00602eb0 @ 0x00602eb0 ====

void FUN_00602eb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00602e90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602ed0 @ 0x00602ed0 ====

void FUN_00602ed0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986d68;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8fd0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c8fac;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,5,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x1b] = 0;
  in_ECX[0x1b] = in_ECX[0x1b] + 5;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = in_ECX + 2;
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
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00602f80 @ 0x00602f80 ====

undefined4 FUN_00602f80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x70);
}


// ==== FUN_00602f90 @ 0x00602f90 ====

void FUN_00602f90(byte param_1)

{
  void *in_ECX;
  
  FUN_00602fb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00602fb0 @ 0x00602fb0 ====

void FUN_00602fb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986d93;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8fd0;
  local_4 = 1;
  if ((void *)in_ECX[0x1d] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c8fac;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,5,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c8f7c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1d]);
  return;
}


// ==== FUN_00603030 @ 0x00603030 ====

void * FUN_00603030(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00986dab;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x78);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x70) = *(int *)(in_ECX + 0x70) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x74);
      *(void **)(in_ECX + 0x74) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c8fe8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00603100 @ 0x00603100 ====

undefined4 FUN_00603100(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8fe8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x78);
    *(int *)(in_ECX + 0x70) = *(int *)(in_ECX + 0x70) + -1;
    *(int *)(in_ECX + 0x78) = param_2;
  }
  return 0;
}


// ==== FUN_00603180 @ 0x00603180 ====

void FUN_00603180(byte param_1)

{
  void *in_ECX;
  
  FUN_00602c10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006031a0 @ 0x006031a0 ====

void FUN_006031a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c906c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,5,FUN_006ef6d0);
  return;
}


// ==== FUN_006031c0 @ 0x006031c0 ====

void FUN_006031c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986dd3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9074;
  local_4 = 1;
  if ((void *)in_ECX[0x2c] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c906c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,5,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c8f94;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x2c]);
  return;
}


// ==== FUN_00603240 @ 0x00603240 ====

undefined4 FUN_00603240(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8fe8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0xb4);
    *(int *)(in_ECX + 0xac) = *(int *)(in_ECX + 0xac) + -1;
    *(int *)(in_ECX + 0xb4) = param_2;
  }
  return 0;
}


// ==== FUN_006032c0 @ 0x006032c0 ====

undefined4 * FUN_006032c0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8fe8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xb4);
  *(int *)(in_ECX + 0xac) = *(int *)(in_ECX + 0xac) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0xb0);
    *(undefined4 **)(in_ECX + 0xb0) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0xb4) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_00603380 @ 0x00603380 ====

void FUN_00603380(byte param_1)

{
  void *in_ECX;
  
  FUN_006031a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006033a0 @ 0x006033a0 ====

void FUN_006033a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006031c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006033c0 @ 0x006033c0 ====

void FUN_006033c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986de8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9074;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c906c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,5,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x2a] = 0;
  in_ECX[0x2a] = in_ECX[0x2a] + 5;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x2d] = in_ECX + 2;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[7] = in_ECX + 10;
  in_ECX[0xf] = in_ECX + 0x12;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x17] = in_ECX + 0x1a;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1f] = in_ECX + 0x22;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00603480 @ 0x00603480 ====

void FUN_00603480(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986e08;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c908c;
  FUN_006033c0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006034e0 @ 0x006034e0 ====

void FUN_006034e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00603500(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00603500 @ 0x00603500 ====

void FUN_00603500(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00603500(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00603500(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00603540 @ 0x00603540 ====

void FUN_00603540(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00603560(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00603560 @ 0x00603560 ====

void FUN_00603560(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00603560(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00603560(param_1[3]);
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


// ==== FUN_006035d0 @ 0x006035d0 ====

void FUN_006035d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006035f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006035f0 @ 0x006035f0 ====

void FUN_006035f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00986e33;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c908c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00603560(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_006031c0();
  *in_ECX = &PTR_FUN_009c8f24;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00603660 @ 0x00603660 ====

void FUN_00603660(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c90e4;
  return;
}


// ==== FUN_00603670 @ 0x00603670 ====

void FUN_00603670(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c90e4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00603690 @ 0x00603690 ====

void FUN_00603690(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00603695. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_006036a0 @ 0x006036a0 ====

undefined4 FUN_006036a0(undefined2 param_1)

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


// ==== FUN_006036d0 @ 0x006036d0 ====

undefined4 FUN_006036d0(void)

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


// ==== FUN_006036f0 @ 0x006036f0 ====

undefined4 FUN_006036f0(void)

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


// ==== FUN_00603720 @ 0x00603720 ====

void FUN_00603720(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986e48;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c9194;
  DAT_00b5abc8 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
    *(undefined4 *)(*piVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c90e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006037c0 @ 0x006037c0 ====

void FUN_006037c0(undefined2 *param_1)

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
  puStack_8 = &LAB_00986e5d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x1c8);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0062b8b0();
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


// ==== FUN_00603850 @ 0x00603850 ====

void FUN_00603850(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00986e85;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9194;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_006039f0();
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
    uVar3 = FUN_00603f90(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abc8 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abc8 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00603920 @ 0x00603920 ====

void FUN_00603920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9104;
  return;
}


// ==== FUN_00603930 @ 0x00603930 ====

void FUN_00603930(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c915c;
  return;
}


// ==== FUN_00603940 @ 0x00603940 ====

void FUN_00603940(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9174;
  return;
}


// ==== FUN_00603950 @ 0x00603950 ====

void FUN_00603950(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9104;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00603970 @ 0x00603970 ====

void FUN_00603970(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c915c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00603990 @ 0x00603990 ====

void FUN_00603990(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9174;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006039b0 @ 0x006039b0 ====

void FUN_006039b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c918c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_006039d0 @ 0x006039d0 ====

void FUN_006039d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006039b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006039f0 @ 0x006039f0 ====

void FUN_006039f0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986e98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c91b0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c918c;
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


// ==== FUN_00603aa0 @ 0x00603aa0 ====

void FUN_00603aa0(byte param_1)

{
  void *in_ECX;
  
  FUN_00603ac0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00603ac0 @ 0x00603ac0 ====

void FUN_00603ac0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986ec3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c91b0;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c918c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c915c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_00603b40 @ 0x00603b40 ====

void * FUN_00603b40(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00986edb;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c91c8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00603c20 @ 0x00603c20 ====

undefined4 FUN_00603c20(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c91c8,0xa9);
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


// ==== FUN_00603ca0 @ 0x00603ca0 ====

void FUN_00603ca0(byte param_1)

{
  void *in_ECX;
  
  FUN_00603720();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00603cc0 @ 0x00603cc0 ====

void FUN_00603cc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9244;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00603ce0 @ 0x00603ce0 ====

void FUN_00603ce0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986f03;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c924c;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c9244;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c9174;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_00603d60 @ 0x00603d60 ====

undefined4 FUN_00603d60(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c91c8,0xa9);
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


// ==== FUN_00603de0 @ 0x00603de0 ====

undefined4 * FUN_00603de0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c91c8,0x85);
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


// ==== FUN_00603ea0 @ 0x00603ea0 ====

void FUN_00603ea0(byte param_1)

{
  void *in_ECX;
  
  FUN_00603cc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00603ec0 @ 0x00603ec0 ====

void FUN_00603ec0(byte param_1)

{
  void *in_ECX;
  
  FUN_00603ce0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00603ee0 @ 0x00603ee0 ====

void FUN_00603ee0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986f18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c924c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c9244;
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


// ==== FUN_00603f90 @ 0x00603f90 ====

void FUN_00603f90(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986f38;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9264;
  FUN_00603ee0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00603ff0 @ 0x00603ff0 ====

void FUN_00603ff0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00604010(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00604010 @ 0x00604010 ====

void FUN_00604010(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00604010(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00604010(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00604050 @ 0x00604050 ====

void FUN_00604050(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar2 = *(int *)(param_1 + 0x10);
    while ((iVar1 = iVar2, iVar1 != 0 && (*(int *)(iVar1 + 0xc) == param_1))) {
      param_1 = iVar1;
      iVar2 = *(int *)(iVar1 + 0x10);
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 0xc) + 8);
    if (iVar2 != 0) {
      do {
        iVar2 = *(int *)(iVar2 + 8);
      } while (iVar2 != 0);
      return;
    }
  }
  return;
}


// ==== FUN_00604090 @ 0x00604090 ====

void FUN_00604090(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 8) == 0) {
    iVar2 = *(int *)(param_1 + 0x10);
    while ((iVar1 = iVar2, iVar1 != 0 && (*(int *)(iVar1 + 8) == param_1))) {
      param_1 = iVar1;
      iVar2 = *(int *)(iVar1 + 0x10);
    }
  }
  else {
    iVar2 = *(int *)(*(int *)(param_1 + 8) + 0xc);
    if (iVar2 != 0) {
      do {
        iVar2 = *(int *)(iVar2 + 0xc);
      } while (iVar2 != 0);
      return;
    }
  }
  return;
}


// ==== FUN_006040d0 @ 0x006040d0 ====

void FUN_006040d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006040f0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006040f0 @ 0x006040f0 ====

void FUN_006040f0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_006040f0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_006040f0(param_1[3]);
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


// ==== FUN_00604160 @ 0x00604160 ====

void FUN_00604160(byte param_1)

{
  void *in_ECX;
  
  FUN_00604180();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00604180 @ 0x00604180 ====

void FUN_00604180(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00986f63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9264;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_006040f0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00603ce0();
  *in_ECX = &PTR_FUN_009c9104;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006041f0 @ 0x006041f0 ====

void FUN_006041f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c92bc;
  return;
}


// ==== FUN_00604200 @ 0x00604200 ====

void FUN_00604200(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c92bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00604220 @ 0x00604220 ====

void FUN_00604220(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c92d4;
  return;
}


// ==== FUN_00604230 @ 0x00604230 ====

void FUN_00604230(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c932c;
  return;
}


// ==== FUN_00604240 @ 0x00604240 ====

void FUN_00604240(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9344;
  return;
}


// ==== FUN_00604250 @ 0x00604250 ====

void FUN_00604250(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c92d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00604270 @ 0x00604270 ====

void FUN_00604270(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c932c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00604290 @ 0x00604290 ====

void FUN_00604290(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9344;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006042b0 @ 0x006042b0 ====

undefined4 FUN_006042b0(undefined2 param_1)

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


// ==== FUN_006042e0 @ 0x006042e0 ====

undefined4 FUN_006042e0(void)

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


// ==== FUN_00604300 @ 0x00604300 ====

undefined4 FUN_00604300(void)

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


// ==== FUN_00604330 @ 0x00604330 ====

void FUN_00604330(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986f78;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c9364;
  DAT_00b5abcc = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
    *(undefined4 *)(*piVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c92bc;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006043d0 @ 0x006043d0 ====

void FUN_006043d0(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  void *pvVar3;
  int in_ECX;
  void *unaff_ESI;
  int *piVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined2 *puStack_4;
  
  puStack_4 = (undefined2 *)0xffffffff;
  puStack_8 = &LAB_00986f8d;
  pvStack_c = ExceptionList;
  piVar4 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar3 = operator_new(0x88);
  pvStack_c = (void *)0x0;
  if (pvVar3 != (void *)0x0) {
    piVar4 = (int *)FUN_0062bbc0();
  }
  puVar1 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar4 + 8))(puStack_4);
  *puVar2 = *puVar1;
  *(int **)(puVar2 + 2) = piVar4;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_00604460 @ 0x00604460 ====

void FUN_00604460(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00986fb5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9364;
  pvVar2 = operator_new(0xe0);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00604570();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x168);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00604bd0(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abcc = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abcc = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00604530 @ 0x00604530 ====

void FUN_00604530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c935c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,10,FUN_006ef6d0);
  return;
}


// ==== FUN_00604550 @ 0x00604550 ====

void FUN_00604550(byte param_1)

{
  void *in_ECX;
  
  FUN_00604530();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00604570 @ 0x00604570 ====

void FUN_00604570(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986fc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c937c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c935c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,10,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x34] = 0;
  in_ECX[0x34] = in_ECX[0x34] + 10;
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = in_ECX + 2;
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
  in_ECX[0x27] = in_ECX + 0x2a;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2c] = in_ECX + 0x2f;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00604670 @ 0x00604670 ====

undefined4 FUN_00604670(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xd4);
}


// ==== FUN_00604680 @ 0x00604680 ====

void FUN_00604680(byte param_1)

{
  void *in_ECX;
  
  FUN_006046a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006046a0 @ 0x006046a0 ====

void FUN_006046a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986ff3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c937c;
  local_4 = 1;
  if ((void *)in_ECX[0x36] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c935c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,10,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c932c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x36]);
  return;
}


// ==== FUN_00604720 @ 0x00604720 ====

void * FUN_00604720(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098700b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0xdc);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xd4) = *(int *)(in_ECX + 0xd4) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0xd8);
      *(void **)(in_ECX + 0xd8) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0xdc) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c9390,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00604800 @ 0x00604800 ====

undefined4 FUN_00604800(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9390,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0xdc);
    *(int *)(in_ECX + 0xd4) = *(int *)(in_ECX + 0xd4) + -1;
    *(int *)(in_ECX + 0xdc) = param_2;
  }
  return 0;
}


// ==== FUN_00604880 @ 0x00604880 ====

void FUN_00604880(byte param_1)

{
  void *in_ECX;
  
  FUN_00604330();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006048a0 @ 0x006048a0 ====

void FUN_006048a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c940c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,10,FUN_006ef6d0);
  return;
}


// ==== FUN_006048c0 @ 0x006048c0 ====

void FUN_006048c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987033;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9414;
  local_4 = 1;
  if ((void *)in_ECX[0x54] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c940c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,10,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c9344;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x54]);
  return;
}


// ==== FUN_00604940 @ 0x00604940 ====

undefined4 FUN_00604940(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9390,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x154);
    *(int *)(in_ECX + 0x14c) = *(int *)(in_ECX + 0x14c) + -1;
    *(int *)(in_ECX + 0x154) = param_2;
  }
  return 0;
}


// ==== FUN_006049c0 @ 0x006049c0 ====

undefined4 * FUN_006049c0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9390,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x154);
  *(int *)(in_ECX + 0x14c) = *(int *)(in_ECX + 0x14c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x150);
    *(undefined4 **)(in_ECX + 0x150) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x154) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_00604a80 @ 0x00604a80 ====

void FUN_00604a80(byte param_1)

{
  void *in_ECX;
  
  FUN_006048a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00604aa0 @ 0x00604aa0 ====

void FUN_00604aa0(byte param_1)

{
  void *in_ECX;
  
  FUN_006048c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00604ac0 @ 0x00604ac0 ====

void FUN_00604ac0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987048;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9414;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c940c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,10,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x52] = 0;
  in_ECX[0x52] = in_ECX[0x52] + 10;
  in_ECX[0x53] = 0;
  in_ECX[0x54] = 0;
  in_ECX[0x55] = in_ECX + 2;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[7] = in_ECX + 10;
  in_ECX[0xf] = in_ECX + 0x12;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x17] = in_ECX + 0x1a;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1f] = in_ECX + 0x22;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x27] = in_ECX + 0x2a;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2f] = in_ECX + 0x32;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x37] = in_ECX + 0x3a;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  in_ECX[0x3f] = in_ECX + 0x42;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  in_ECX[0x47] = in_ECX + 0x4a;
  in_ECX[0x48] = 0;
  in_ECX[0x49] = 0;
  in_ECX[0x4f] = 0;
  in_ECX[0x50] = 0;
  in_ECX[0x51] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00604bd0 @ 0x00604bd0 ====

void FUN_00604bd0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987068;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c942c;
  FUN_00604ac0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00604c30 @ 0x00604c30 ====

void FUN_00604c30(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00604c50(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00604c50 @ 0x00604c50 ====

void FUN_00604c50(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00604c50(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00604c50(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00604c90 @ 0x00604c90 ====

void FUN_00604c90(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00604cb0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00604cb0 @ 0x00604cb0 ====

void FUN_00604cb0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00604cb0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00604cb0(param_1[3]);
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


// ==== FUN_00604d20 @ 0x00604d20 ====

void FUN_00604d20(byte param_1)

{
  void *in_ECX;
  
  FUN_00604d40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00604d40 @ 0x00604d40 ====

void FUN_00604d40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987093;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c942c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00604cb0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_006048c0();
  *in_ECX = &PTR_FUN_009c92d4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00604db0 @ 0x00604db0 ====

void FUN_00604db0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9484;
  return;
}


// ==== FUN_00604dc0 @ 0x00604dc0 ====

void FUN_00604dc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9484;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00604de0 @ 0x00604de0 ====

void FUN_00604de0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00604de5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_00604df0 @ 0x00604df0 ====

undefined4 FUN_00604df0(undefined2 param_1)

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


// ==== FUN_00604e20 @ 0x00604e20 ====

undefined4 FUN_00604e20(void)

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


// ==== FUN_00604e40 @ 0x00604e40 ====

undefined4 FUN_00604e40(void)

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


// ==== FUN_00604e70 @ 0x00604e70 ====

void FUN_00604e70(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009870a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c9534;
  DAT_00b5abd0 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
    *(undefined4 *)(*piVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c9484;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00604f10 @ 0x00604f10 ====

void FUN_00604f10(undefined2 *param_1)

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
  puStack_8 = &LAB_009870bd;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x2ac);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0062bcd0();
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


// ==== FUN_00604fa0 @ 0x00604fa0 ====

void FUN_00604fa0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009870e5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9534;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00605140();
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
    uVar3 = FUN_006056e0(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abd0 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abd0 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00605070 @ 0x00605070 ====

void FUN_00605070(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c94a4;
  return;
}


// ==== FUN_00605080 @ 0x00605080 ====

void FUN_00605080(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c94fc;
  return;
}


// ==== FUN_00605090 @ 0x00605090 ====

void FUN_00605090(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9514;
  return;
}


// ==== FUN_006050a0 @ 0x006050a0 ====

void FUN_006050a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c94a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006050c0 @ 0x006050c0 ====

void FUN_006050c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c94fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006050e0 @ 0x006050e0 ====

void FUN_006050e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9514;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605100 @ 0x00605100 ====

void FUN_00605100(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c952c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00605120 @ 0x00605120 ====

void FUN_00605120(byte param_1)

{
  void *in_ECX;
  
  FUN_00605100();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605140 @ 0x00605140 ====

void FUN_00605140(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009870f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9550;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c952c;
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


// ==== FUN_006051f0 @ 0x006051f0 ====

void FUN_006051f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00605210();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605210 @ 0x00605210 ====

void FUN_00605210(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987123;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9550;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c952c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c94fc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_00605290 @ 0x00605290 ====

void * FUN_00605290(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098713b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c9568,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00605370 @ 0x00605370 ====

undefined4 FUN_00605370(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9568,0xa9);
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


// ==== FUN_006053f0 @ 0x006053f0 ====

void FUN_006053f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00604e70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605410 @ 0x00605410 ====

void FUN_00605410(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c95e4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00605430 @ 0x00605430 ====

void FUN_00605430(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987163;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c95ec;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c95e4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c9514;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_006054b0 @ 0x006054b0 ====

undefined4 FUN_006054b0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9568,0xa9);
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


// ==== FUN_00605530 @ 0x00605530 ====

undefined4 * FUN_00605530(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9568,0x85);
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


// ==== FUN_006055f0 @ 0x006055f0 ====

void FUN_006055f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00605410();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605610 @ 0x00605610 ====

void FUN_00605610(byte param_1)

{
  void *in_ECX;
  
  FUN_00605430();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605630 @ 0x00605630 ====

void FUN_00605630(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987178;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c95ec;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c95e4;
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


// ==== FUN_006056e0 @ 0x006056e0 ====

void FUN_006056e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987198;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9604;
  FUN_00605630();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00605740 @ 0x00605740 ====

void FUN_00605740(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00605760(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00605760 @ 0x00605760 ====

void FUN_00605760(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00605760(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00605760(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_006057a0 @ 0x006057a0 ====

void FUN_006057a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006057c0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006057c0 @ 0x006057c0 ====

void FUN_006057c0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_006057c0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_006057c0(param_1[3]);
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


// ==== FUN_00605830 @ 0x00605830 ====

void FUN_00605830(byte param_1)

{
  void *in_ECX;
  
  FUN_00605850();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605850 @ 0x00605850 ====

void FUN_00605850(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009871c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9604;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_006057c0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00605430();
  *in_ECX = &PTR_FUN_009c94a4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006058c0 @ 0x006058c0 ====

void FUN_006058c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c965c;
  return;
}


// ==== FUN_006058d0 @ 0x006058d0 ====

void FUN_006058d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c965c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006058f0 @ 0x006058f0 ====

void FUN_006058f0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006058f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_00605900 @ 0x00605900 ====

undefined4 FUN_00605900(undefined2 param_1)

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


// ==== FUN_00605930 @ 0x00605930 ====

undefined4 FUN_00605930(void)

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


// ==== FUN_00605950 @ 0x00605950 ====

undefined4 FUN_00605950(void)

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


// ==== FUN_00605980 @ 0x00605980 ====

void FUN_00605980(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009871d8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c970c;
  DAT_00b5abd4 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
    *(undefined4 *)(*piVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c965c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00605a20 @ 0x00605a20 ====

void FUN_00605a20(undefined2 *param_1)

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
  puStack_8 = &LAB_009871ed;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x2b4);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0062bfb0();
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


// ==== FUN_00605ab0 @ 0x00605ab0 ====

void FUN_00605ab0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00987215;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c970c;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00605c50();
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
    uVar3 = FUN_006061f0(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abd4 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abd4 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00605b80 @ 0x00605b80 ====

void FUN_00605b80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c967c;
  return;
}


// ==== FUN_00605b90 @ 0x00605b90 ====

void FUN_00605b90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c96d4;
  return;
}


// ==== FUN_00605ba0 @ 0x00605ba0 ====

void FUN_00605ba0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c96ec;
  return;
}


// ==== FUN_00605bb0 @ 0x00605bb0 ====

void FUN_00605bb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c967c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605bd0 @ 0x00605bd0 ====

void FUN_00605bd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c96d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605bf0 @ 0x00605bf0 ====

void FUN_00605bf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c96ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605c10 @ 0x00605c10 ====

void FUN_00605c10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9704;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00605c30 @ 0x00605c30 ====

void FUN_00605c30(byte param_1)

{
  void *in_ECX;
  
  FUN_00605c10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605c50 @ 0x00605c50 ====

void FUN_00605c50(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987228;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9728;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c9704;
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


// ==== FUN_00605d00 @ 0x00605d00 ====

void FUN_00605d00(byte param_1)

{
  void *in_ECX;
  
  FUN_00605d20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605d20 @ 0x00605d20 ====

void FUN_00605d20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987253;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9728;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c9704;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c96d4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_00605da0 @ 0x00605da0 ====

void * FUN_00605da0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098726b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c9740,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00605e80 @ 0x00605e80 ====

undefined4 FUN_00605e80(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9740,0xa9);
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


// ==== FUN_00605f00 @ 0x00605f00 ====

void FUN_00605f00(byte param_1)

{
  void *in_ECX;
  
  FUN_00605980();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00605f20 @ 0x00605f20 ====

void FUN_00605f20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c97bc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00605f40 @ 0x00605f40 ====

void FUN_00605f40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987293;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c97c4;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c97bc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c96ec;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_00605fc0 @ 0x00605fc0 ====

undefined4 FUN_00605fc0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9740,0xa9);
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


// ==== FUN_00606040 @ 0x00606040 ====

undefined4 * FUN_00606040(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9740,0x85);
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


// ==== FUN_00606100 @ 0x00606100 ====

void FUN_00606100(byte param_1)

{
  void *in_ECX;
  
  FUN_00605f20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606120 @ 0x00606120 ====

void FUN_00606120(byte param_1)

{
  void *in_ECX;
  
  FUN_00605f40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606140 @ 0x00606140 ====

void FUN_00606140(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009872a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c97c4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c97bc;
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


// ==== FUN_006061f0 @ 0x006061f0 ====

void FUN_006061f0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009872c8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c97dc;
  FUN_00606140();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00606250 @ 0x00606250 ====

void FUN_00606250(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00606270(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00606270 @ 0x00606270 ====

void FUN_00606270(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00606270(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00606270(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_006062b0 @ 0x006062b0 ====

void FUN_006062b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006062d0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006062d0 @ 0x006062d0 ====

void FUN_006062d0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_006062d0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_006062d0(param_1[3]);
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


// ==== FUN_00606340 @ 0x00606340 ====

void FUN_00606340(byte param_1)

{
  void *in_ECX;
  
  FUN_00606360();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606360 @ 0x00606360 ====

void FUN_00606360(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009872f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c97dc;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_006062d0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00605f40();
  *in_ECX = &PTR_FUN_009c967c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006063d0 @ 0x006063d0 ====

void FUN_006063d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9834;
  return;
}


// ==== FUN_006063e0 @ 0x006063e0 ====

void FUN_006063e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9834;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606400 @ 0x00606400 ====

void FUN_00606400(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00606405. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_00606410 @ 0x00606410 ====

undefined4 FUN_00606410(undefined2 param_1)

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


// ==== FUN_00606440 @ 0x00606440 ====

undefined4 FUN_00606440(void)

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


// ==== FUN_00606460 @ 0x00606460 ====

undefined4 FUN_00606460(void)

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


// ==== FUN_00606490 @ 0x00606490 ====

void FUN_00606490(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987308;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c98e4;
  DAT_00b5a75c = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
    *(undefined4 *)(*piVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c9834;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00606530 @ 0x00606530 ====

void FUN_00606530(undefined2 *param_1)

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
  puStack_8 = &LAB_0098731d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x378);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0062c320();
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


// ==== FUN_006065c0 @ 0x006065c0 ====

void FUN_006065c0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00987345;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c98e4;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00606760();
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
    uVar3 = FUN_00606d00(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a75c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a75c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00606690 @ 0x00606690 ====

void FUN_00606690(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9854;
  return;
}


// ==== FUN_006066a0 @ 0x006066a0 ====

void FUN_006066a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c98ac;
  return;
}


// ==== FUN_006066b0 @ 0x006066b0 ====

void FUN_006066b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c98c4;
  return;
}


// ==== FUN_006066c0 @ 0x006066c0 ====

void FUN_006066c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9854;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006066e0 @ 0x006066e0 ====

void FUN_006066e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c98ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606700 @ 0x00606700 ====

void FUN_00606700(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c98c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606720 @ 0x00606720 ====

void FUN_00606720(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c98dc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00606740 @ 0x00606740 ====

void FUN_00606740(byte param_1)

{
  void *in_ECX;
  
  FUN_00606720();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606760 @ 0x00606760 ====

void FUN_00606760(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987358;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9900;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c98dc;
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


// ==== FUN_00606810 @ 0x00606810 ====

void FUN_00606810(byte param_1)

{
  void *in_ECX;
  
  FUN_00606830();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606830 @ 0x00606830 ====

void FUN_00606830(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987383;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9900;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c98dc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c98ac;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_006068b0 @ 0x006068b0 ====

void * FUN_006068b0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098739b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c9918,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00606990 @ 0x00606990 ====

undefined4 FUN_00606990(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9918,0xa9);
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


// ==== FUN_00606a10 @ 0x00606a10 ====

void FUN_00606a10(byte param_1)

{
  void *in_ECX;
  
  FUN_00606490();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606a30 @ 0x00606a30 ====

void FUN_00606a30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9994;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00606a50 @ 0x00606a50 ====

void FUN_00606a50(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009873c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c999c;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c9994;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c98c4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_00606ad0 @ 0x00606ad0 ====

undefined4 FUN_00606ad0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9918,0xa9);
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


// ==== FUN_00606b50 @ 0x00606b50 ====

undefined4 * FUN_00606b50(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9918,0x85);
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


// ==== FUN_00606c10 @ 0x00606c10 ====

void FUN_00606c10(byte param_1)

{
  void *in_ECX;
  
  FUN_00606a30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606c30 @ 0x00606c30 ====

void FUN_00606c30(byte param_1)

{
  void *in_ECX;
  
  FUN_00606a50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606c50 @ 0x00606c50 ====

void FUN_00606c50(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009873d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c999c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c9994;
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


// ==== FUN_00606d00 @ 0x00606d00 ====

void FUN_00606d00(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009873f8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c99b4;
  FUN_00606c50();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00606d60 @ 0x00606d60 ====

void FUN_00606d60(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00606d80(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00606d80 @ 0x00606d80 ====

void FUN_00606d80(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00606d80(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00606d80(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00606dc0 @ 0x00606dc0 ====

void FUN_00606dc0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00606de0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00606de0 @ 0x00606de0 ====

void FUN_00606de0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00606de0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00606de0(param_1[3]);
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


// ==== FUN_00606e50 @ 0x00606e50 ====

void FUN_00606e50(byte param_1)

{
  void *in_ECX;
  
  FUN_00606e70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606e70 @ 0x00606e70 ====

void FUN_00606e70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987423;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c99b4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00606de0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00606a50();
  *in_ECX = &PTR_FUN_009c9854;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00606ee0 @ 0x00606ee0 ====

void FUN_00606ee0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9a0c;
  return;
}


// ==== FUN_00606ef0 @ 0x00606ef0 ====

void FUN_00606ef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9a0c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606f10 @ 0x00606f10 ====

void FUN_00606f10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9a24;
  return;
}


// ==== FUN_00606f20 @ 0x00606f20 ====

void FUN_00606f20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9a7c;
  return;
}


// ==== FUN_00606f30 @ 0x00606f30 ====

void FUN_00606f30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9a94;
  return;
}


// ==== FUN_00606f40 @ 0x00606f40 ====

void FUN_00606f40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9a24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606f60 @ 0x00606f60 ====

void FUN_00606f60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9a7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606f80 @ 0x00606f80 ====

void FUN_00606f80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9a94;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00606fa0 @ 0x00606fa0 ====

undefined4 FUN_00606fa0(undefined4 param_1)

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


// ==== FUN_00606fd0 @ 0x00606fd0 ====

undefined4 FUN_00606fd0(void)

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


// ==== FUN_00606ff0 @ 0x00606ff0 ====

undefined4 FUN_00606ff0(void)

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


// ==== FUN_00607010 @ 0x00607010 ====

void FUN_00607010(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987438;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c9ab4;
  DAT_00b5a768 = 0;
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
  *in_ECX = &PTR_FUN_009c9a0c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006070b0 @ 0x006070b0 ====

void FUN_006070b0(undefined4 *param_1)

{
  void *pvVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  void *unaff_EDI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098744d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x50);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0062c5c0();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 8))(param_1);
  puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = *param_1;
  puVar3[1] = piVar2;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  ExceptionList = unaff_EDI;
  return;
}


// ==== FUN_00607140 @ 0x00607140 ====

void FUN_00607140(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00987475;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9ab4;
  in_ECX[3] = 0;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00607250();
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
    uVar3 = FUN_00607800(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a768 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a768 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00607210 @ 0x00607210 ====

void FUN_00607210(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9aac;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00607230 @ 0x00607230 ====

void FUN_00607230(byte param_1)

{
  void *in_ECX;
  
  FUN_00607210();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00607250 @ 0x00607250 ====

void FUN_00607250(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987488;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9acc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c9aac;
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


// ==== FUN_00607300 @ 0x00607300 ====

void FUN_00607300(byte param_1)

{
  void *in_ECX;
  
  FUN_00607320();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00607320 @ 0x00607320 ====

void FUN_00607320(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009874b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9acc;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c9aac;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c9a7c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_006073a0 @ 0x006073a0 ====

void * FUN_006073a0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009874cb;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c9ae0,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00607480 @ 0x00607480 ====

undefined4 FUN_00607480(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9ae0,0xa9);
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


// ==== FUN_00607500 @ 0x00607500 ====

void FUN_00607500(void)

{
  FUN_0061c6c0();
  return;
}


// ==== FUN_00607510 @ 0x00607510 ====

void FUN_00607510(byte param_1)

{
  void *in_ECX;
  
  FUN_00607010();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00607530 @ 0x00607530 ====

void FUN_00607530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9b5c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00607550 @ 0x00607550 ====

void FUN_00607550(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009874f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9b64;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c9b5c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c9a94;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_006075d0 @ 0x006075d0 ====

undefined4 FUN_006075d0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9ae0,0xa9);
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


// ==== FUN_00607650 @ 0x00607650 ====

undefined4 * FUN_00607650(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9ae0,0x85);
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


// ==== FUN_00607710 @ 0x00607710 ====

void FUN_00607710(byte param_1)

{
  void *in_ECX;
  
  FUN_00607530();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00607730 @ 0x00607730 ====

void FUN_00607730(byte param_1)

{
  void *in_ECX;
  
  FUN_00607550();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00607750 @ 0x00607750 ====

void FUN_00607750(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987508;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9b64;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c9b5c;
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


// ==== FUN_00607800 @ 0x00607800 ====

void FUN_00607800(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987528;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9b7c;
  FUN_00607750();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00607860 @ 0x00607860 ====

void FUN_00607860(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00607880(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00607880 @ 0x00607880 ====

void FUN_00607880(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00607880(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00607880(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_006078c0 @ 0x006078c0 ====

void FUN_006078c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006078e0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006078e0 @ 0x006078e0 ====

void FUN_006078e0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_006078e0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_006078e0(param_1[3]);
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


// ==== FUN_00607960 @ 0x00607960 ====

void FUN_00607960(byte param_1)

{
  void *in_ECX;
  
  FUN_00607980();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00607980 @ 0x00607980 ====

void FUN_00607980(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987553;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9b7c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_006078e0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00607550();
  *in_ECX = &PTR_FUN_009c9a24;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006079f0 @ 0x006079f0 ====

void FUN_006079f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9bd4;
  return;
}


// ==== FUN_00607a00 @ 0x00607a00 ====

void FUN_00607a00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9bd4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00607a20 @ 0x00607a20 ====

void FUN_00607a20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9bec;
  return;
}


// ==== FUN_00607a30 @ 0x00607a30 ====

void FUN_00607a30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9c44;
  return;
}


// ==== FUN_00607a40 @ 0x00607a40 ====

void FUN_00607a40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9c5c;
  return;
}


// ==== FUN_00607a50 @ 0x00607a50 ====

void FUN_00607a50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9bec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00607a70 @ 0x00607a70 ====

void FUN_00607a70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9c44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00607a90 @ 0x00607a90 ====

void FUN_00607a90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9c5c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00607ab0 @ 0x00607ab0 ====

undefined4 FUN_00607ab0(undefined2 param_1)

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


// ==== FUN_00607ae0 @ 0x00607ae0 ====

undefined4 FUN_00607ae0(void)

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


// ==== FUN_00607b00 @ 0x00607b00 ====

undefined4 FUN_00607b00(void)

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


// ==== FUN_00607b30 @ 0x00607b30 ====

void FUN_00607b30(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987568;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c9c7c;
  DAT_00b5a770 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 4))(1);
    }
    *(undefined4 *)(*piVar1 + 4) = 0;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c9bd4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00607bd0 @ 0x00607bd0 ====

void FUN_00607bd0(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  void *pvVar3;
  int in_ECX;
  void *unaff_ESI;
  int *piVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined2 *puStack_4;
  
  puStack_4 = (undefined2 *)0xffffffff;
  puStack_8 = &LAB_0098757d;
  pvStack_c = ExceptionList;
  piVar4 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar3 = operator_new(0x180);
  pvStack_c = (void *)0x0;
  if (pvVar3 != (void *)0x0) {
    piVar4 = (int *)FUN_0062c740();
  }
  puVar1 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar4 + 8))(puStack_4);
  *puVar2 = *puVar1;
  *(int **)(puVar2 + 2) = piVar4;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_00607c60 @ 0x00607c60 ====

void FUN_00607c60(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009875a5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9c7c;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00607d70();
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
    uVar3 = FUN_00608310(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a770 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a770 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00607d30 @ 0x00607d30 ====

void FUN_00607d30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9c74;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00607d50 @ 0x00607d50 ====

void FUN_00607d50(byte param_1)

{
  void *in_ECX;
  
  FUN_00607d30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00607d70 @ 0x00607d70 ====

void FUN_00607d70(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009875b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9c94;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c9c74;
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


// ==== FUN_00607e20 @ 0x00607e20 ====

void FUN_00607e20(byte param_1)

{
  void *in_ECX;
  
  FUN_00607e40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00607e40 @ 0x00607e40 ====

void FUN_00607e40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009875e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9c94;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c9c74;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c9c44;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_00607ec0 @ 0x00607ec0 ====

void * FUN_00607ec0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009875fb;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c9ca8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00607fa0 @ 0x00607fa0 ====

undefined4 FUN_00607fa0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9ca8,0xa9);
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


// ==== FUN_00608020 @ 0x00608020 ====

void FUN_00608020(byte param_1)

{
  void *in_ECX;
  
  FUN_00607b30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608040 @ 0x00608040 ====

void FUN_00608040(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9d20;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00608060 @ 0x00608060 ====

void FUN_00608060(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987623;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9d28;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c9d20;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c9c5c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_006080e0 @ 0x006080e0 ====

undefined4 FUN_006080e0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9ca8,0xa9);
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


// ==== FUN_00608160 @ 0x00608160 ====

undefined4 * FUN_00608160(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9ca8,0x85);
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


// ==== FUN_00608220 @ 0x00608220 ====

void FUN_00608220(byte param_1)

{
  void *in_ECX;
  
  FUN_00608040();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608240 @ 0x00608240 ====

void FUN_00608240(byte param_1)

{
  void *in_ECX;
  
  FUN_00608060();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608260 @ 0x00608260 ====

void FUN_00608260(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987638;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9d28;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c9d20;
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


// ==== FUN_00608310 @ 0x00608310 ====

void FUN_00608310(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987658;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9d44;
  FUN_00608260();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00608370 @ 0x00608370 ====

void FUN_00608370(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00608390(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00608390 @ 0x00608390 ====

void FUN_00608390(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00608390(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00608390(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_006083d0 @ 0x006083d0 ====

void FUN_006083d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006083f0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006083f0 @ 0x006083f0 ====

void FUN_006083f0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_006083f0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_006083f0(param_1[3]);
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


// ==== FUN_00608460 @ 0x00608460 ====

void FUN_00608460(byte param_1)

{
  void *in_ECX;
  
  FUN_00608480();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608480 @ 0x00608480 ====

void FUN_00608480(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987683;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9d44;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_006083f0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00608060();
  *in_ECX = &PTR_FUN_009c9bec;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006084f0 @ 0x006084f0 ====

void FUN_006084f0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006084f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_00608500 @ 0x00608500 ====

void FUN_00608500(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00608505. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_00608510 @ 0x00608510 ====

void FUN_00608510(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00608515. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_00608520 @ 0x00608520 ====

void FUN_00608520(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00608525. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_00608530 @ 0x00608530 ====

void FUN_00608530(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987698;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9de4;
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009c9dcc;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  in_ECX[1] = puVar1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ac88 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ac88 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006085c0 @ 0x006085c0 ====

void FUN_006085c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009876aa;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c9de4;
  DAT_00b5ac88 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c9d9c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00608620 @ 0x00608620 ====

void FUN_00608620(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9db4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608640 @ 0x00608640 ====

void FUN_00608640(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9d9c;
  return;
}


// ==== FUN_00608650 @ 0x00608650 ====

void FUN_00608650(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9d9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608670 @ 0x00608670 ====

undefined4 FUN_00608670(void)

{
  return 0xffffffff;
}


// ==== FUN_00608680 @ 0x00608680 ====

void FUN_00608680(byte param_1)

{
  void *in_ECX;
  
  FUN_006086a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006086a0 @ 0x006086a0 ====

void FUN_006086a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9db4;
  return;
}


// ==== FUN_006086b0 @ 0x006086b0 ====

void * FUN_006086b0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009876d9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    ExceptionList = &local_c;
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
    param_2 = operator_new(0xcc);
    local_4 = 1;
    if (param_2 == (void *)0x0) {
      param_2 = (void *)0x0;
    }
    else {
      FUN_0062cae0();
    }
    *(undefined4 *)((int)param_2 + 0xc0) = 0;
    *(undefined4 *)((int)param_2 + 0xc4) = *(undefined4 *)(in_ECX + 8);
    *(int *)((int)param_2 + 200) = param_1;
    if (*(int *)(in_ECX + 8) != 0) {
      *(void **)(*(int *)(in_ECX + 8) + 0xc0) = param_2;
    }
    *(void **)(in_ECX + 8) = param_2;
  }
  else {
    if (*(int *)((int)param_2 + 200) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9df8,0x58);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 200) = *(int *)((int)param_2 + 200) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_006087b0 @ 0x006087b0 ====

undefined4 FUN_006087b0(uint param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    if (*(uint *)((int)param_2 + 200) < param_1) {
      local_100[0] = 0;
      uVar3 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c9df8,0x79);
      FUN_00797b80(uVar3);
      FUN_00797a40();
    }
    piVar1 = (int *)((int)param_2 + 200);
    *piVar1 = *piVar1 - param_1;
    uVar3 = *(undefined4 *)((int)param_2 + 200);
    if (*piVar1 == 0) {
      iVar2 = *(int *)((int)param_2 + 0xc4);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0xc0) = *(undefined4 *)((int)param_2 + 0xc0);
      }
      if (param_2 == *(void **)(in_ECX + 8)) {
        *(int *)(in_ECX + 8) = iVar2;
      }
      else {
        *(int *)(*(int *)((int)param_2 + 0xc0) + 0xc4) = iVar2;
      }
      thunk_FUN_0062c930();
      _free(param_2);
      return extraout_EAX;
    }
  }
  return uVar3;
}


// ==== FUN_00608870 @ 0x00608870 ====

void FUN_00608870(byte param_1)

{
  void *in_ECX;
  
  FUN_006085c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608890 @ 0x00608890 ====

void FUN_00608890(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00608895. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_006088a0 @ 0x006088a0 ====

void FUN_006088a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006088a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_006088b0 @ 0x006088b0 ====

void FUN_006088b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006088b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_006088c0 @ 0x006088c0 ====

void FUN_006088c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006088c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_006088d0 @ 0x006088d0 ====

void FUN_006088d0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987723;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca044;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ac8c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ac8c = in_ECX;
  }
  pvVar2 = operator_new(0xe4);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_00608a70();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00608970 @ 0x00608970 ====

void FUN_00608970(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987735;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca044;
  DAT_00b5ac8c = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c9ff4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006089d0 @ 0x006089d0 ====

void FUN_006089d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca00c;
  return;
}


// ==== FUN_006089e0 @ 0x006089e0 ====

void FUN_006089e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca00c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608a10 @ 0x00608a10 ====

void FUN_00608a10(void)

{
  FUN_0062d220();
  return;
}


// ==== FUN_00608a20 @ 0x00608a20 ====

void FUN_00608a20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9ff4;
  return;
}


// ==== FUN_00608a30 @ 0x00608a30 ====

void FUN_00608a30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c9ff4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608a50 @ 0x00608a50 ====

void FUN_00608a50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca024;
  _eh_vector_destructor_iterator_(in_ECX + 1,0xcc,1,(_func_void_void_ptr *)&LAB_00608a00);
  return;
}


// ==== FUN_00608a70 @ 0x00608a70 ====

void FUN_00608a70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009876f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca02c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ca024;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0xcc,1,FUN_00608a10,(_func_void_void_ptr *)&LAB_00608a00);
  in_ECX[0x35] = 0;
  in_ECX[0x35] = in_ECX[0x35] + 1;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = in_ECX + 2;
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00608b10 @ 0x00608b10 ====

void FUN_00608b10(byte param_1)

{
  void *in_ECX;
  
  FUN_00608a50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608b30 @ 0x00608b30 ====

void * FUN_00608b30(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987759;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0xe0);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xd8) = *(int *)(in_ECX + 0xd8) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0xcc);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0062d220();
      }
      *(undefined4 *)((int)param_2 + 0xc4) = *(undefined4 *)(in_ECX + 0xdc);
      *(void **)(in_ECX + 0xdc) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0xe0) = *(undefined4 *)((int)param_2 + 0xc0);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 200) = param_1;
    *(undefined4 *)((int)param_2 + 0xc0) = 0;
    FUN_0062cff0();
  }
  else {
    if (*(int *)((int)param_2 + 200) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ca058,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 200) = *(int *)((int)param_2 + 200) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00608c60 @ 0x00608c60 ====

undefined4 FUN_00608c60(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 200) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ca058,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 200);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 200);
    }
    FUN_0062d000();
    *(undefined4 *)(param_2 + 0xc0) = *(undefined4 *)(in_ECX + 0xe0);
    *(int *)(in_ECX + 0xd8) = *(int *)(in_ECX + 0xd8) + -1;
    *(int *)(in_ECX + 0xe0) = param_2;
  }
  return 0;
}


// ==== FUN_00608cf0 @ 0x00608cf0 ====

void FUN_00608cf0(byte param_1)

{
  void *in_ECX;
  
  FUN_00608d10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608d10 @ 0x00608d10 ====

void FUN_00608d10(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987789;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca02c;
  local_4 = 1;
  if (in_ECX[0x36] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009c9edc,
                         s_d__usa_24_0_1_2__develop_share_l_009c9e70,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[0x34] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009c9f5c,
                         s_d__usa_24_0_1_2__develop_share_l_009c9ef0,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[0x37];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009ca024;
    _eh_vector_destructor_iterator_(in_ECX + 2,0xcc,1,(_func_void_void_ptr *)&LAB_00608a00);
    *in_ECX = &PTR_FUN_009ca00c;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 200) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009c9fdc,
                         s_d__usa_24_0_1_2__develop_share_l_009c9f70,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_0062d0a0();
  _free(_Memory);
  return;
}


// ==== FUN_00608e50 @ 0x00608e50 ====

void FUN_00608e50(byte param_1)

{
  void *in_ECX;
  
  FUN_00608970();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608e70 @ 0x00608e70 ====

void FUN_00608e70(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00608e75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_00608e80 @ 0x00608e80 ====

void FUN_00608e80(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00608e85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_00608e90 @ 0x00608e90 ====

void FUN_00608e90(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00608e95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_00608ea0 @ 0x00608ea0 ====

void FUN_00608ea0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00608ea5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_00608eb0 @ 0x00608eb0 ====

void FUN_00608eb0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009877d3;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca2a0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ae00 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ae00 = in_ECX;
  }
  pvVar2 = operator_new(0x10818);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_00609050();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00608f50 @ 0x00608f50 ====

void FUN_00608f50(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009877e5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca2a0;
  DAT_00b5ae00 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009ca250;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00608fb0 @ 0x00608fb0 ====

void FUN_00608fb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca268;
  return;
}


// ==== FUN_00608fc0 @ 0x00608fc0 ====

void FUN_00608fc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca268;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00608ff0 @ 0x00608ff0 ====

void FUN_00608ff0(void)

{
  FUN_0062da60();
  return;
}


// ==== FUN_00609000 @ 0x00609000 ====

void FUN_00609000(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca250;
  return;
}


// ==== FUN_00609010 @ 0x00609010 ====

void FUN_00609010(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca250;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00609030 @ 0x00609030 ====

void FUN_00609030(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca280;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x108,0x100,(_func_void_void_ptr *)&LAB_00608fe0);
  return;
}


// ==== FUN_00609050 @ 0x00609050 ====

void FUN_00609050(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009877a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca288;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ca280;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x108,0x100,FUN_00608ff0,(_func_void_void_ptr *)&LAB_00608fe0);
  in_ECX[0x4202] = 0;
  in_ECX[0x4202] = in_ECX[0x4202] + 0x100;
  in_ECX[0x4205] = in_ECX + 2;
  in_ECX[0x4203] = 0;
  in_ECX[0x4204] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[0x41] = puVar1 + 0x44;
    puVar1[0x42] = 0;
    puVar1[0x43] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x42;
  } while (iVar2 != 0);
  in_ECX[0x41ff] = 0;
  in_ECX[0x4200] = 0;
  in_ECX[0x4201] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00609110 @ 0x00609110 ====

undefined4 FUN_00609110(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1080c);
}


// ==== FUN_00609120 @ 0x00609120 ====

void FUN_00609120(byte param_1)

{
  void *in_ECX;
  
  FUN_00609030();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00609140 @ 0x00609140 ====

void * FUN_00609140(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987809;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x10814);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x1080c) = *(int *)(in_ECX + 0x1080c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x108);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0062da60();
      }
      *(undefined4 *)((int)param_2 + 0x100) = *(undefined4 *)(in_ECX + 0x10810);
      *(void **)(in_ECX + 0x10810) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x10814) = *(undefined4 *)((int)param_2 + 0xfc);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0x104) = param_1;
    *(undefined4 *)((int)param_2 + 0xfc) = 0;
    FUN_0062d8e0();
  }
  else {
    if (*(int *)((int)param_2 + 0x104) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ca2b8,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x104) = *(int *)((int)param_2 + 0x104) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00609270 @ 0x00609270 ====

undefined4 FUN_00609270(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x104) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ca2b8,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x104);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x104);
    }
    FUN_0062d8f0();
    *(undefined4 *)(param_2 + 0xfc) = *(undefined4 *)(in_ECX + 0x10814);
    *(int *)(in_ECX + 0x1080c) = *(int *)(in_ECX + 0x1080c) + -1;
    *(int *)(in_ECX + 0x10814) = param_2;
  }
  return 0;
}


// ==== FUN_00609300 @ 0x00609300 ====

void FUN_00609300(byte param_1)

{
  void *in_ECX;
  
  FUN_00609320();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00609320 @ 0x00609320 ====

void FUN_00609320(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987839;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca288;
  local_4 = 1;
  if (in_ECX[0x4203] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ca138,
                         s_d__usa_24_0_1_2__develop_share_l_009ca0d0,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 0x43;
  iVar3 = 0x100;
  do {
    if (*piVar2 != 0) {
      local_10c[0] = 0;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ca1b8,
                           s_d__usa_24_0_1_2__develop_share_l_009ca150,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 0x42;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x4204];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009ca280;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x108,0x100,(_func_void_void_ptr *)&LAB_00608fe0);
    *in_ECX = &PTR_FUN_009ca268;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0x104) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ca238,
                         s_d__usa_24_0_1_2__develop_share_l_009ca1d0,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_0062d970();
  _free(_Memory);
  return;
}


// ==== FUN_00609480 @ 0x00609480 ====

void FUN_00609480(byte param_1)

{
  void *in_ECX;
  
  FUN_00608f50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006094a0 @ 0x006094a0 ====

void FUN_006094a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006094a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_006094b0 @ 0x006094b0 ====

void FUN_006094b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006094b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_006094c0 @ 0x006094c0 ====

void FUN_006094c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006094c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_006094d0 @ 0x006094d0 ====

void FUN_006094d0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006094d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_006094e0 @ 0x006094e0 ====

void FUN_006094e0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987883;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca4fc;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5adb0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5adb0 = in_ECX;
  }
  pvVar2 = operator_new(0x114);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_00609680();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00609580 @ 0x00609580 ====

void FUN_00609580(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987895;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca4fc;
  DAT_00b5adb0 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009ca4ac;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006095e0 @ 0x006095e0 ====

void FUN_006095e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca4c4;
  return;
}


// ==== FUN_006095f0 @ 0x006095f0 ====

void FUN_006095f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca4c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00609620 @ 0x00609620 ====

void FUN_00609620(void)

{
  FUN_0062dee0();
  return;
}


// ==== FUN_00609630 @ 0x00609630 ====

void FUN_00609630(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca4ac;
  return;
}


// ==== FUN_00609640 @ 0x00609640 ====

void FUN_00609640(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca4ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00609660 @ 0x00609660 ====

void FUN_00609660(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca4dc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0xfc,1,(_func_void_void_ptr *)&LAB_00609610);
  return;
}


// ==== FUN_00609680 @ 0x00609680 ====

void FUN_00609680(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987858;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca4e4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ca4dc;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0xfc,1,FUN_00609620,(_func_void_void_ptr *)&LAB_00609610);
  in_ECX[0x41] = 0;
  in_ECX[0x41] = in_ECX[0x41] + 1;
  in_ECX[0x42] = 0;
  in_ECX[0x43] = 0;
  in_ECX[0x44] = in_ECX + 2;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00609720 @ 0x00609720 ====

undefined4 FUN_00609720(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x108);
}


// ==== FUN_00609730 @ 0x00609730 ====

void FUN_00609730(byte param_1)

{
  void *in_ECX;
  
  FUN_00609660();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00609750 @ 0x00609750 ====

void * FUN_00609750(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009878b9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x110);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x108) = *(int *)(in_ECX + 0x108) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0xfc);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0062dee0();
      }
      *(undefined4 *)((int)param_2 + 0xf4) = *(undefined4 *)(in_ECX + 0x10c);
      *(void **)(in_ECX + 0x10c) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x110) = *(undefined4 *)((int)param_2 + 0xf0);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0xf8) = param_1;
    *(undefined4 *)((int)param_2 + 0xf0) = 0;
    FUN_0062dd40();
  }
  else {
    if (*(int *)((int)param_2 + 0xf8) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ca510,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0xf8) = *(int *)((int)param_2 + 0xf8) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00609880 @ 0x00609880 ====

undefined4 FUN_00609880(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0xf8) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ca510,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0xf8);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0xf8);
    }
    FUN_0062dd50();
    *(undefined4 *)(param_2 + 0xf0) = *(undefined4 *)(in_ECX + 0x110);
    *(int *)(in_ECX + 0x108) = *(int *)(in_ECX + 0x108) + -1;
    *(int *)(in_ECX + 0x110) = param_2;
  }
  return 0;
}


// ==== FUN_00609910 @ 0x00609910 ====

void FUN_00609910(byte param_1)

{
  void *in_ECX;
  
  FUN_00609930();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00609930 @ 0x00609930 ====

void FUN_00609930(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009878e9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca4e4;
  local_4 = 1;
  if (in_ECX[0x42] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ca394,
                         s_d__usa_24_0_1_2__develop_share_l_009ca328,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[0x40] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ca414,
                         s_d__usa_24_0_1_2__develop_share_l_009ca3a8,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[0x43];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009ca4dc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0xfc,1,(_func_void_void_ptr *)&LAB_00609610);
    *in_ECX = &PTR_FUN_009ca4c4;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0xf8) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ca494,
                         s_d__usa_24_0_1_2__develop_share_l_009ca428,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_0062de00();
  _free(_Memory);
  return;
}


// ==== FUN_00609a70 @ 0x00609a70 ====

void FUN_00609a70(byte param_1)

{
  void *in_ECX;
  
  FUN_00609580();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00609a90 @ 0x00609a90 ====

void FUN_00609a90(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00609a95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_00609aa0 @ 0x00609aa0 ====

void FUN_00609aa0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00609aa5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_00609ab0 @ 0x00609ab0 ====

void FUN_00609ab0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00609ab5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_00609ac0 @ 0x00609ac0 ====

void FUN_00609ac0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00609ac5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_00609ad0 @ 0x00609ad0 ====

void FUN_00609ad0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987933;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca75c;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a984 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a984 = in_ECX;
  }
  pvVar2 = operator_new(0xf8);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_00609c70();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00609b70 @ 0x00609b70 ====

void FUN_00609b70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987945;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca75c;
  DAT_00b5a984 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009ca70c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00609bd0 @ 0x00609bd0 ====

void FUN_00609bd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca724;
  return;
}


// ==== FUN_00609be0 @ 0x00609be0 ====

void FUN_00609be0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca724;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00609c10 @ 0x00609c10 ====

void FUN_00609c10(void)

{
  FUN_0062e1e0();
  return;
}


// ==== FUN_00609c20 @ 0x00609c20 ====

void FUN_00609c20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca70c;
  return;
}


// ==== FUN_00609c30 @ 0x00609c30 ====

void FUN_00609c30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca70c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00609c50 @ 0x00609c50 ====

void FUN_00609c50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca73c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0xe0,1,(_func_void_void_ptr *)&LAB_00609c00);
  return;
}


// ==== FUN_00609c70 @ 0x00609c70 ====

void FUN_00609c70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987908;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca744;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ca73c;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0xe0,1,FUN_00609c10,(_func_void_void_ptr *)&LAB_00609c00);
  in_ECX[0x3a] = 0;
  in_ECX[0x3a] = in_ECX[0x3a] + 1;
  in_ECX[0x3b] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = in_ECX + 2;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00609d10 @ 0x00609d10 ====

void FUN_00609d10(byte param_1)

{
  void *in_ECX;
  
  FUN_00609c50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00609d30 @ 0x00609d30 ====

void * FUN_00609d30(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987969;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0xf4);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xec) = *(int *)(in_ECX + 0xec) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0xe0);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0062e1e0();
      }
      *(undefined4 *)((int)param_2 + 0xd8) = *(undefined4 *)(in_ECX + 0xf0);
      *(void **)(in_ECX + 0xf0) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0xf4) = *(undefined4 *)((int)param_2 + 0xd4);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0xdc) = param_1;
    *(undefined4 *)((int)param_2 + 0xd4) = 0;
    FUN_0062e090();
  }
  else {
    if (*(int *)((int)param_2 + 0xdc) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ca770,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0xdc) = *(int *)((int)param_2 + 0xdc) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00609e60 @ 0x00609e60 ====

undefined4 FUN_00609e60(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0xdc) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ca770,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0xdc);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0xdc);
    }
    FUN_0062e0a0();
    *(undefined4 *)(param_2 + 0xd4) = *(undefined4 *)(in_ECX + 0xf4);
    *(int *)(in_ECX + 0xec) = *(int *)(in_ECX + 0xec) + -1;
    *(int *)(in_ECX + 0xf4) = param_2;
  }
  return 0;
}


// ==== FUN_00609ef0 @ 0x00609ef0 ====

void FUN_00609ef0(byte param_1)

{
  void *in_ECX;
  
  FUN_00609f10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00609f10 @ 0x00609f10 ====

void FUN_00609f10(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987999;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca744;
  local_4 = 1;
  if (in_ECX[0x3b] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ca5f4,
                         s_d__usa_24_0_1_2__develop_share_l_009ca588,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[0x39] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ca674,
                         s_d__usa_24_0_1_2__develop_share_l_009ca608,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[0x3c];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009ca73c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0xe0,1,(_func_void_void_ptr *)&LAB_00609c00);
    *in_ECX = &PTR_FUN_009ca724;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0xdc) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ca6f4,
                         s_d__usa_24_0_1_2__develop_share_l_009ca688,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_0062e130();
  _free(_Memory);
  return;
}


// ==== FUN_0060a050 @ 0x0060a050 ====

void FUN_0060a050(byte param_1)

{
  void *in_ECX;
  
  FUN_00609b70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060a070 @ 0x0060a070 ====

void FUN_0060a070(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060a075. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0060a080 @ 0x0060a080 ====

void FUN_0060a080(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060a085. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0060a090 @ 0x0060a090 ====

void FUN_0060a090(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060a095. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0060a0a0 @ 0x0060a0a0 ====

void FUN_0060a0a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060a0a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_0060a0b0 @ 0x0060a0b0 ====

void FUN_0060a0b0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009879e3;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca9bc;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5adfc = (undefined4 *)0x0;
  }
  else {
    DAT_00b5adfc = in_ECX;
  }
  pvVar2 = operator_new(0x110);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_0060a250();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060a150 @ 0x0060a150 ====

void FUN_0060a150(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009879f5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca9bc;
  DAT_00b5adfc = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009ca96c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060a1b0 @ 0x0060a1b0 ====

void FUN_0060a1b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca984;
  return;
}


// ==== FUN_0060a1c0 @ 0x0060a1c0 ====

void FUN_0060a1c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca984;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060a1f0 @ 0x0060a1f0 ====

void FUN_0060a1f0(void)

{
  FUN_0062e630();
  return;
}


// ==== FUN_0060a200 @ 0x0060a200 ====

void FUN_0060a200(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca96c;
  return;
}


// ==== FUN_0060a210 @ 0x0060a210 ====

void FUN_0060a210(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca96c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060a230 @ 0x0060a230 ====

void FUN_0060a230(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ca99c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0xf8,1,(_func_void_void_ptr *)&LAB_0060a1e0);
  return;
}


// ==== FUN_0060a250 @ 0x0060a250 ====

void FUN_0060a250(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009879b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca9a4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ca99c;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0xf8,1,FUN_0060a1f0,(_func_void_void_ptr *)&LAB_0060a1e0);
  in_ECX[0x40] = 0;
  in_ECX[0x40] = in_ECX[0x40] + 1;
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x43] = in_ECX + 2;
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060a2f0 @ 0x0060a2f0 ====

void FUN_0060a2f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060a230();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060a310 @ 0x0060a310 ====

void * FUN_0060a310(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987a19;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x10c);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x104) = *(int *)(in_ECX + 0x104) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0xf8);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0062e630();
      }
      *(undefined4 *)((int)param_2 + 0xf0) = *(undefined4 *)(in_ECX + 0x108);
      *(void **)(in_ECX + 0x108) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x10c) = *(undefined4 *)((int)param_2 + 0xec);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0xf4) = param_1;
    *(undefined4 *)((int)param_2 + 0xec) = 0;
    FUN_0062e4c0();
  }
  else {
    if (*(int *)((int)param_2 + 0xf4) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ca9d0,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0xf4) = *(int *)((int)param_2 + 0xf4) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0060a440 @ 0x0060a440 ====

undefined4 FUN_0060a440(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0xf4) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ca9d0,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0xf4);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0xf4);
    }
    FUN_0062e4d0();
    *(undefined4 *)(param_2 + 0xec) = *(undefined4 *)(in_ECX + 0x10c);
    *(int *)(in_ECX + 0x104) = *(int *)(in_ECX + 0x104) + -1;
    *(int *)(in_ECX + 0x10c) = param_2;
  }
  return 0;
}


// ==== FUN_0060a4d0 @ 0x0060a4d0 ====

void FUN_0060a4d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060a4f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060a4f0 @ 0x0060a4f0 ====

void FUN_0060a4f0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987a49;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ca9a4;
  local_4 = 1;
  if (in_ECX[0x41] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ca854,
                         s_d__usa_24_0_1_2__develop_share_l_009ca7e8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[0x3f] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ca8d4,
                         s_d__usa_24_0_1_2__develop_share_l_009ca868,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[0x42];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009ca99c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0xf8,1,(_func_void_void_ptr *)&LAB_0060a1e0);
    *in_ECX = &PTR_FUN_009ca984;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0xf4) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ca954,
                         s_d__usa_24_0_1_2__develop_share_l_009ca8e8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_0062e570();
  _free(_Memory);
  return;
}


// ==== FUN_0060a630 @ 0x0060a630 ====

void FUN_0060a630(byte param_1)

{
  void *in_ECX;
  
  FUN_0060a150();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060a650 @ 0x0060a650 ====

void FUN_0060a650(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060a655. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0060a660 @ 0x0060a660 ====

void FUN_0060a660(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060a665. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0060a670 @ 0x0060a670 ====

void FUN_0060a670(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060a675. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0060a680 @ 0x0060a680 ====

void FUN_0060a680(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060a685. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_0060a690 @ 0x0060a690 ====

void FUN_0060a690(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987a93;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cac1c;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a764 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a764 = in_ECX;
  }
  pvVar2 = operator_new(0x110);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_0060a830();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060a730 @ 0x0060a730 ====

void FUN_0060a730(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987aa5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cac1c;
  DAT_00b5a764 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009cabcc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060a790 @ 0x0060a790 ====

void FUN_0060a790(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cabe4;
  return;
}


// ==== FUN_0060a7a0 @ 0x0060a7a0 ====

void FUN_0060a7a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cabe4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060a7d0 @ 0x0060a7d0 ====

void FUN_0060a7d0(void)

{
  FUN_0062ea00();
  return;
}


// ==== FUN_0060a7e0 @ 0x0060a7e0 ====

void FUN_0060a7e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cabcc;
  return;
}


// ==== FUN_0060a7f0 @ 0x0060a7f0 ====

void FUN_0060a7f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cabcc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060a810 @ 0x0060a810 ====

void FUN_0060a810(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cabfc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0xf8,1,(_func_void_void_ptr *)&LAB_0060a7c0);
  return;
}


// ==== FUN_0060a830 @ 0x0060a830 ====

void FUN_0060a830(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987a68;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cac04;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cabfc;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0xf8,1,FUN_0060a7d0,(_func_void_void_ptr *)&LAB_0060a7c0);
  in_ECX[0x40] = 0;
  in_ECX[0x40] = in_ECX[0x40] + 1;
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x43] = in_ECX + 2;
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060a8d0 @ 0x0060a8d0 ====

undefined4 FUN_0060a8d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x104);
}


// ==== FUN_0060a8e0 @ 0x0060a8e0 ====

void FUN_0060a8e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060a810();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060a900 @ 0x0060a900 ====

void * FUN_0060a900(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987ac9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x10c);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x104) = *(int *)(in_ECX + 0x104) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0xf8);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0062ea00();
      }
      *(undefined4 *)((int)param_2 + 0xf0) = *(undefined4 *)(in_ECX + 0x108);
      *(void **)(in_ECX + 0x108) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x10c) = *(undefined4 *)((int)param_2 + 0xec);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0xf4) = param_1;
    *(undefined4 *)((int)param_2 + 0xec) = 0;
    FUN_0062e7c0();
  }
  else {
    if (*(int *)((int)param_2 + 0xf4) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cac30,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0xf4) = *(int *)((int)param_2 + 0xf4) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0060aa30 @ 0x0060aa30 ====

undefined4 FUN_0060aa30(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0xf4) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cac30,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0xf4);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0xf4);
    }
    FUN_0062e7d0();
    *(undefined4 *)(param_2 + 0xec) = *(undefined4 *)(in_ECX + 0x10c);
    *(int *)(in_ECX + 0x104) = *(int *)(in_ECX + 0x104) + -1;
    *(int *)(in_ECX + 0x10c) = param_2;
  }
  return 0;
}


// ==== FUN_0060aac0 @ 0x0060aac0 ====

void FUN_0060aac0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060aae0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060aae0 @ 0x0060aae0 ====

void FUN_0060aae0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987af9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cac04;
  local_4 = 1;
  if (in_ECX[0x41] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009caab4,
                         s_d__usa_24_0_1_2__develop_share_l_009caa48,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[0x3f] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cab34,
                         s_d__usa_24_0_1_2__develop_share_l_009caac8,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[0x42];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009cabfc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0xf8,1,(_func_void_void_ptr *)&LAB_0060a7c0);
    *in_ECX = &PTR_FUN_009cabe4;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0xf4) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cabb4,
                         s_d__usa_24_0_1_2__develop_share_l_009cab48,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_0062e8d0();
  _free(_Memory);
  return;
}


// ==== FUN_0060ac20 @ 0x0060ac20 ====

void FUN_0060ac20(byte param_1)

{
  void *in_ECX;
  
  FUN_0060a730();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060ac40 @ 0x0060ac40 ====

void FUN_0060ac40(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060ac45. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0060ac50 @ 0x0060ac50 ====

void FUN_0060ac50(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060ac55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0060ac60 @ 0x0060ac60 ====

void FUN_0060ac60(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060ac65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0060ac70 @ 0x0060ac70 ====

void FUN_0060ac70(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060ac75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_0060ac80 @ 0x0060ac80 ====

void FUN_0060ac80(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987b18;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cace8;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a6e0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a6e0 = in_ECX;
  }
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009cacd0;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  in_ECX[1] = puVar1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060ad00 @ 0x0060ad00 ====

void FUN_0060ad00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987b2a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cace8;
  DAT_00b5a6e0 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009caca0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060ad60 @ 0x0060ad60 ====

void FUN_0060ad60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cacb8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060ad80 @ 0x0060ad80 ====

void FUN_0060ad80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009caca0;
  return;
}


// ==== FUN_0060ad90 @ 0x0060ad90 ====

void FUN_0060ad90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009caca0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060adb0 @ 0x0060adb0 ====

void FUN_0060adb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060add0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060add0 @ 0x0060add0 ====

void FUN_0060add0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cacb8;
  return;
}


// ==== FUN_0060ade0 @ 0x0060ade0 ====

void * FUN_0060ade0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987b59;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    ExceptionList = &local_c;
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
    param_2 = operator_new(0x180);
    local_4 = 1;
    if (param_2 == (void *)0x0) {
      param_2 = (void *)0x0;
    }
    else {
      FUN_0062f3b0();
    }
    *(undefined4 *)((int)param_2 + 0x174) = 0;
    *(undefined4 *)((int)param_2 + 0x178) = *(undefined4 *)(in_ECX + 8);
    *(int *)((int)param_2 + 0x17c) = param_1;
    if (*(int *)(in_ECX + 8) != 0) {
      *(void **)(*(int *)(in_ECX + 8) + 0x174) = param_2;
    }
    *(void **)(in_ECX + 8) = param_2;
  }
  else {
    if (*(int *)((int)param_2 + 0x17c) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cad00,0x58);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x17c) = *(int *)((int)param_2 + 0x17c) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0060aee0 @ 0x0060aee0 ====

undefined4 FUN_0060aee0(uint param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    if (*(uint *)((int)param_2 + 0x17c) < param_1) {
      local_100[0] = 0;
      uVar3 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cad00,0x79);
      FUN_00797b80(uVar3);
      FUN_00797a40();
    }
    piVar1 = (int *)((int)param_2 + 0x17c);
    *piVar1 = *piVar1 - param_1;
    uVar3 = *(undefined4 *)((int)param_2 + 0x17c);
    if (*piVar1 == 0) {
      iVar2 = *(int *)((int)param_2 + 0x178);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x174) = *(undefined4 *)((int)param_2 + 0x174);
      }
      if (param_2 == *(void **)(in_ECX + 8)) {
        *(int *)(in_ECX + 8) = iVar2;
      }
      else {
        *(int *)(*(int *)((int)param_2 + 0x174) + 0x178) = iVar2;
      }
      thunk_FUN_0062eed0();
      _free(param_2);
      return extraout_EAX;
    }
  }
  return uVar3;
}


// ==== FUN_0060afa0 @ 0x0060afa0 ====

void FUN_0060afa0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060ad00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060afc0 @ 0x0060afc0 ====

void FUN_0060afc0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060afc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0060afd0 @ 0x0060afd0 ====

void FUN_0060afd0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060afd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0060afe0 @ 0x0060afe0 ====

void FUN_0060afe0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060afe5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0060aff0 @ 0x0060aff0 ====

void FUN_0060aff0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060aff5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_0060b000 @ 0x0060b000 ====

void FUN_0060b000(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987ba3;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009caf40;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a76c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a76c = in_ECX;
  }
  pvVar2 = operator_new(0xec);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_0060b1a0();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060b0a0 @ 0x0060b0a0 ====

void FUN_0060b0a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987bb5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009caf40;
  DAT_00b5a76c = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009caef0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060b100 @ 0x0060b100 ====

void FUN_0060b100(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009caf08;
  return;
}


// ==== FUN_0060b110 @ 0x0060b110 ====

void FUN_0060b110(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009caf08;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060b140 @ 0x0060b140 ====

void FUN_0060b140(void)

{
  FUN_00630f30();
  return;
}


// ==== FUN_0060b150 @ 0x0060b150 ====

void FUN_0060b150(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009caef0;
  return;
}


// ==== FUN_0060b160 @ 0x0060b160 ====

void FUN_0060b160(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009caef0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060b180 @ 0x0060b180 ====

void FUN_0060b180(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009caf20;
  _eh_vector_destructor_iterator_(in_ECX + 1,0xd4,1,(_func_void_void_ptr *)&LAB_0060b130);
  return;
}


// ==== FUN_0060b1a0 @ 0x0060b1a0 ====

void FUN_0060b1a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987b78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009caf28;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009caf20;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0xd4,1,FUN_0060b140,(_func_void_void_ptr *)&LAB_0060b130);
  in_ECX[0x37] = 0;
  in_ECX[0x37] = in_ECX[0x37] + 1;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  in_ECX[0x3a] = in_ECX + 2;
  in_ECX[0x34] = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060b240 @ 0x0060b240 ====

undefined4 FUN_0060b240(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe0);
}


// ==== FUN_0060b250 @ 0x0060b250 ====

void FUN_0060b250(byte param_1)

{
  void *in_ECX;
  
  FUN_0060b180();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060b270 @ 0x0060b270 ====

void * FUN_0060b270(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987bd9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0xe8);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xe0) = *(int *)(in_ECX + 0xe0) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0xd4);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00630f30();
      }
      *(undefined4 *)((int)param_2 + 0xcc) = *(undefined4 *)(in_ECX + 0xe4);
      *(void **)(in_ECX + 0xe4) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0xe8) = *(undefined4 *)((int)param_2 + 200);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0xd0) = param_1;
    *(undefined4 *)((int)param_2 + 200) = 0;
    FUN_00630d30();
  }
  else {
    if (*(int *)((int)param_2 + 0xd0) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009caf58,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0xd0) = *(int *)((int)param_2 + 0xd0) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0060b3a0 @ 0x0060b3a0 ====

undefined4 FUN_0060b3a0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0xd0) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009caf58,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0xd0);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0xd0);
    }
    FUN_00630d40();
    *(undefined4 *)(param_2 + 200) = *(undefined4 *)(in_ECX + 0xe8);
    *(int *)(in_ECX + 0xe0) = *(int *)(in_ECX + 0xe0) + -1;
    *(int *)(in_ECX + 0xe8) = param_2;
  }
  return 0;
}


// ==== FUN_0060b430 @ 0x0060b430 ====

void FUN_0060b430(byte param_1)

{
  void *in_ECX;
  
  FUN_0060b450();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060b450 @ 0x0060b450 ====

void FUN_0060b450(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987c09;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009caf28;
  local_4 = 1;
  if (in_ECX[0x38] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cadd8,
                         s_d__usa_24_0_1_2__develop_share_l_009cad70,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[0x36] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cae58,
                         s_d__usa_24_0_1_2__develop_share_l_009cadf0,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[0x39];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009caf20;
    _eh_vector_destructor_iterator_(in_ECX + 2,0xd4,1,(_func_void_void_ptr *)&LAB_0060b130);
    *in_ECX = &PTR_FUN_009caf08;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0xd0) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009caed8,
                         s_d__usa_24_0_1_2__develop_share_l_009cae70,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00630dd0();
  _free(_Memory);
  return;
}


// ==== FUN_0060b590 @ 0x0060b590 ====

void FUN_0060b590(byte param_1)

{
  void *in_ECX;
  
  FUN_0060b0a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060b5b0 @ 0x0060b5b0 ====

void FUN_0060b5b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060b5b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0060b5c0 @ 0x0060b5c0 ====

void FUN_0060b5c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060b5c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0060b5d0 @ 0x0060b5d0 ====

void FUN_0060b5d0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060b5d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0060b5e0 @ 0x0060b5e0 ====

void FUN_0060b5e0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060b5e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_0060b5f0 @ 0x0060b5f0 ====

void FUN_0060b5f0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987c28;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb00c;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5af20 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5af20 = in_ECX;
  }
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009caff4;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  in_ECX[1] = puVar1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060b670 @ 0x0060b670 ====

void FUN_0060b670(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987c3a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb00c;
  DAT_00b5af20 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009cafc4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060b6d0 @ 0x0060b6d0 ====

void FUN_0060b6d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cafdc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060b6f0 @ 0x0060b6f0 ====

void FUN_0060b6f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cafc4;
  return;
}


// ==== FUN_0060b700 @ 0x0060b700 ====

void FUN_0060b700(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cafc4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060b720 @ 0x0060b720 ====

void FUN_0060b720(byte param_1)

{
  void *in_ECX;
  
  FUN_0060b740();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060b740 @ 0x0060b740 ====

void FUN_0060b740(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cafdc;
  return;
}


// ==== FUN_0060b750 @ 0x0060b750 ====

void * FUN_0060b750(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987c69;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    ExceptionList = &local_c;
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
    param_2 = operator_new(0xcc);
    local_4 = 1;
    if (param_2 == (void *)0x0) {
      param_2 = (void *)0x0;
    }
    else {
      FUN_006315a0();
    }
    *(undefined4 *)((int)param_2 + 0xc0) = 0;
    *(undefined4 *)((int)param_2 + 0xc4) = *(undefined4 *)(in_ECX + 8);
    *(int *)((int)param_2 + 200) = param_1;
    if (*(int *)(in_ECX + 8) != 0) {
      *(void **)(*(int *)(in_ECX + 8) + 0xc0) = param_2;
    }
    *(void **)(in_ECX + 8) = param_2;
  }
  else {
    if (*(int *)((int)param_2 + 200) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cb020,0x58);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 200) = *(int *)((int)param_2 + 200) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0060b850 @ 0x0060b850 ====

undefined4 FUN_0060b850(uint param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    if (*(uint *)((int)param_2 + 200) < param_1) {
      local_100[0] = 0;
      uVar3 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cb020,0x79);
      FUN_00797b80(uVar3);
      FUN_00797a40();
    }
    piVar1 = (int *)((int)param_2 + 200);
    *piVar1 = *piVar1 - param_1;
    uVar3 = *(undefined4 *)((int)param_2 + 200);
    if (*piVar1 == 0) {
      iVar2 = *(int *)((int)param_2 + 0xc4);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0xc0) = *(undefined4 *)((int)param_2 + 0xc0);
      }
      if (param_2 == *(void **)(in_ECX + 8)) {
        *(int *)(in_ECX + 8) = iVar2;
      }
      else {
        *(int *)(*(int *)((int)param_2 + 0xc0) + 0xc4) = iVar2;
      }
      thunk_FUN_006313f0();
      _free(param_2);
      return extraout_EAX;
    }
  }
  return uVar3;
}


// ==== FUN_0060b910 @ 0x0060b910 ====

void FUN_0060b910(byte param_1)

{
  void *in_ECX;
  
  FUN_0060b670();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060b930 @ 0x0060b930 ====

void FUN_0060b930(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060b935. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0060b940 @ 0x0060b940 ====

void FUN_0060b940(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060b945. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0060b950 @ 0x0060b950 ====

void FUN_0060b950(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060b955. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0060b960 @ 0x0060b960 ====

void FUN_0060b960(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060b965. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_0060b970 @ 0x0060b970 ====

void FUN_0060b970(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987c88;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb0d8;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5addc = (undefined4 *)0x0;
  }
  else {
    DAT_00b5addc = in_ECX;
  }
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009cb0c0;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  in_ECX[1] = puVar1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060b9f0 @ 0x0060b9f0 ====

void FUN_0060b9f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987c9a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb0d8;
  DAT_00b5addc = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009cb090;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060ba50 @ 0x0060ba50 ====

void FUN_0060ba50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb0a8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060ba70 @ 0x0060ba70 ====

void FUN_0060ba70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb090;
  return;
}


// ==== FUN_0060ba80 @ 0x0060ba80 ====

void FUN_0060ba80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb090;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060baa0 @ 0x0060baa0 ====

void FUN_0060baa0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060bac0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060bac0 @ 0x0060bac0 ====

void FUN_0060bac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb0a8;
  return;
}


// ==== FUN_0060bad0 @ 0x0060bad0 ====

void * FUN_0060bad0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987cc9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    ExceptionList = &local_c;
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
    param_2 = operator_new(0xd4);
    local_4 = 1;
    if (param_2 == (void *)0x0) {
      param_2 = (void *)0x0;
    }
    else {
      FUN_00631db0();
    }
    *(undefined4 *)((int)param_2 + 200) = 0;
    *(undefined4 *)((int)param_2 + 0xcc) = *(undefined4 *)(in_ECX + 8);
    *(int *)((int)param_2 + 0xd0) = param_1;
    if (*(int *)(in_ECX + 8) != 0) {
      *(void **)(*(int *)(in_ECX + 8) + 200) = param_2;
    }
    *(void **)(in_ECX + 8) = param_2;
  }
  else {
    if (*(int *)((int)param_2 + 0xd0) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cb0f0,0x58);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0xd0) = *(int *)((int)param_2 + 0xd0) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0060bbd0 @ 0x0060bbd0 ====

undefined4 FUN_0060bbd0(uint param_1,void *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    if (*(uint *)((int)param_2 + 0xd0) < param_1) {
      local_100[0] = 0;
      uVar3 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cb0f0,0x79);
      FUN_00797b80(uVar3);
      FUN_00797a40();
    }
    piVar1 = (int *)((int)param_2 + 0xd0);
    *piVar1 = *piVar1 - param_1;
    uVar3 = *(undefined4 *)((int)param_2 + 0xd0);
    if (*piVar1 == 0) {
      iVar2 = *(int *)((int)param_2 + 0xcc);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 200) = *(undefined4 *)((int)param_2 + 200);
      }
      if (param_2 == *(void **)(in_ECX + 8)) {
        *(int *)(in_ECX + 8) = iVar2;
      }
      else {
        *(int *)(*(int *)((int)param_2 + 200) + 0xcc) = iVar2;
      }
      thunk_FUN_00631c00();
      _free(param_2);
      return extraout_EAX;
    }
  }
  return uVar3;
}


// ==== FUN_0060bc90 @ 0x0060bc90 ====

void FUN_0060bc90(byte param_1)

{
  void *in_ECX;
  
  FUN_0060b9f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060bcb0 @ 0x0060bcb0 ====

void FUN_0060bcb0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060bcb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0060bcc0 @ 0x0060bcc0 ====

void FUN_0060bcc0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060bcc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0060bcd0 @ 0x0060bcd0 ====

void FUN_0060bcd0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060bcd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0060bce0 @ 0x0060bce0 ====

void FUN_0060bce0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060bce5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_0060bcf0 @ 0x0060bcf0 ====

void FUN_0060bcf0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987d13;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb33c;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a758 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a758 = in_ECX;
  }
  pvVar2 = operator_new(0xe4);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_0060be90();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060bd90 @ 0x0060bd90 ====

void FUN_0060bd90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987d25;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb33c;
  DAT_00b5a758 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009cb2ec;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060bdf0 @ 0x0060bdf0 ====

void FUN_0060bdf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb304;
  return;
}


// ==== FUN_0060be00 @ 0x0060be00 ====

void FUN_0060be00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb304;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060be30 @ 0x0060be30 ====

void FUN_0060be30(void)

{
  FUN_00632550();
  return;
}


// ==== FUN_0060be40 @ 0x0060be40 ====

void FUN_0060be40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb2ec;
  return;
}


// ==== FUN_0060be50 @ 0x0060be50 ====

void FUN_0060be50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb2ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060be70 @ 0x0060be70 ====

void FUN_0060be70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb31c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0xcc,1,(_func_void_void_ptr *)&LAB_0060be20);
  return;
}


// ==== FUN_0060be90 @ 0x0060be90 ====

void FUN_0060be90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987ce8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb324;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cb31c;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0xcc,1,FUN_0060be30,(_func_void_void_ptr *)&LAB_0060be20);
  in_ECX[0x35] = 0;
  in_ECX[0x35] = in_ECX[0x35] + 1;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = in_ECX + 2;
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060bf30 @ 0x0060bf30 ====

void FUN_0060bf30(byte param_1)

{
  void *in_ECX;
  
  FUN_0060be70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060bf50 @ 0x0060bf50 ====

void * FUN_0060bf50(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987d49;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0xe0);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xd8) = *(int *)(in_ECX + 0xd8) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0xcc);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00632550();
      }
      *(undefined4 *)((int)param_2 + 0xc4) = *(undefined4 *)(in_ECX + 0xdc);
      *(void **)(in_ECX + 0xdc) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0xe0) = *(undefined4 *)((int)param_2 + 0xc0);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 200) = param_1;
    *(undefined4 *)((int)param_2 + 0xc0) = 0;
    FUN_00632300();
  }
  else {
    if (*(int *)((int)param_2 + 200) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cb350,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 200) = *(int *)((int)param_2 + 200) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0060c080 @ 0x0060c080 ====

undefined4 FUN_0060c080(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 200) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cb350,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 200);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 200);
    }
    FUN_00632310();
    *(undefined4 *)(param_2 + 0xc0) = *(undefined4 *)(in_ECX + 0xe0);
    *(int *)(in_ECX + 0xd8) = *(int *)(in_ECX + 0xd8) + -1;
    *(int *)(in_ECX + 0xe0) = param_2;
  }
  return 0;
}


// ==== FUN_0060c110 @ 0x0060c110 ====

void FUN_0060c110(byte param_1)

{
  void *in_ECX;
  
  FUN_0060c130();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060c130 @ 0x0060c130 ====

void FUN_0060c130(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987d79;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb324;
  local_4 = 1;
  if (in_ECX[0x36] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cb1d4,
                         s_d__usa_24_0_1_2__develop_share_l_009cb168,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[0x34] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cb254,
                         s_d__usa_24_0_1_2__develop_share_l_009cb1e8,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[0x37];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009cb31c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0xcc,1,(_func_void_void_ptr *)&LAB_0060be20);
    *in_ECX = &PTR_FUN_009cb304;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 200) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cb2d4,
                         s_d__usa_24_0_1_2__develop_share_l_009cb268,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_006323a0();
  _free(_Memory);
  return;
}


// ==== FUN_0060c270 @ 0x0060c270 ====

void FUN_0060c270(byte param_1)

{
  void *in_ECX;
  
  FUN_0060bd90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060c290 @ 0x0060c290 ====

void FUN_0060c290(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060c295. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0060c2a0 @ 0x0060c2a0 ====

void FUN_0060c2a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060c2a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0060c2b0 @ 0x0060c2b0 ====

void FUN_0060c2b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060c2b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0060c2c0 @ 0x0060c2c0 ====

void FUN_0060c2c0(undefined4 param_1,int *param_2)

{
  int in_ECX;
  
  (**(code **)(*param_2 + 4))();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(param_1,param_2);
  return;
}


// ==== FUN_0060c2f0 @ 0x0060c2f0 ====

void FUN_0060c2f0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987dc3;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb59c;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5af14 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5af14 = in_ECX;
  }
  pvVar2 = operator_new(0xe4);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_0060c490();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060c390 @ 0x0060c390 ====

void FUN_0060c390(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987dd5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb59c;
  DAT_00b5af14 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009cb54c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060c3f0 @ 0x0060c3f0 ====

void FUN_0060c3f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb564;
  return;
}


// ==== FUN_0060c400 @ 0x0060c400 ====

void FUN_0060c400(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb564;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060c430 @ 0x0060c430 ====

void FUN_0060c430(void)

{
  FUN_00632c30();
  return;
}


// ==== FUN_0060c440 @ 0x0060c440 ====

void FUN_0060c440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb54c;
  return;
}


// ==== FUN_0060c450 @ 0x0060c450 ====

void FUN_0060c450(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb54c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060c470 @ 0x0060c470 ====

void FUN_0060c470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb57c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0xcc,1,(_func_void_void_ptr *)&LAB_0060c420);
  return;
}


// ==== FUN_0060c490 @ 0x0060c490 ====

void FUN_0060c490(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987d98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb584;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cb57c;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0xcc,1,FUN_0060c430,(_func_void_void_ptr *)&LAB_0060c420);
  in_ECX[0x35] = 0;
  in_ECX[0x35] = in_ECX[0x35] + 1;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = in_ECX + 2;
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060c530 @ 0x0060c530 ====

undefined4 FUN_0060c530(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xd8);
}


// ==== FUN_0060c540 @ 0x0060c540 ====

void FUN_0060c540(byte param_1)

{
  void *in_ECX;
  
  FUN_0060c470();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060c560 @ 0x0060c560 ====

void * FUN_0060c560(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987df9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0xe0);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xd8) = *(int *)(in_ECX + 0xd8) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0xcc);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00632c30();
      }
      *(undefined4 *)((int)param_2 + 0xc4) = *(undefined4 *)(in_ECX + 0xdc);
      *(void **)(in_ECX + 0xdc) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0xe0) = *(undefined4 *)((int)param_2 + 0xc0);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 200) = param_1;
    *(undefined4 *)((int)param_2 + 0xc0) = 0;
    FUN_00632a90();
  }
  else {
    if (*(int *)((int)param_2 + 200) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cb5b0,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 200) = *(int *)((int)param_2 + 200) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0060c690 @ 0x0060c690 ====

undefined4 FUN_0060c690(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 200) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cb5b0,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 200);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 200);
    }
    FUN_00632aa0();
    *(undefined4 *)(param_2 + 0xc0) = *(undefined4 *)(in_ECX + 0xe0);
    *(int *)(in_ECX + 0xd8) = *(int *)(in_ECX + 0xd8) + -1;
    *(int *)(in_ECX + 0xe0) = param_2;
  }
  return 0;
}


// ==== FUN_0060c720 @ 0x0060c720 ====

void FUN_0060c720(byte param_1)

{
  void *in_ECX;
  
  FUN_0060c740();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060c740 @ 0x0060c740 ====

void FUN_0060c740(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987e29;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb584;
  local_4 = 1;
  if (in_ECX[0x36] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cb434,
                         s_d__usa_24_0_1_2__develop_share_l_009cb3c8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[0x34] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cb4b4,
                         s_d__usa_24_0_1_2__develop_share_l_009cb448,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[0x37];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009cb57c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0xcc,1,(_func_void_void_ptr *)&LAB_0060c420);
    *in_ECX = &PTR_FUN_009cb564;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 200) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cb534,
                         s_d__usa_24_0_1_2__develop_share_l_009cb4c8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00632b20();
  _free(_Memory);
  return;
}


// ==== FUN_0060c880 @ 0x0060c880 ====

void FUN_0060c880(byte param_1)

{
  void *in_ECX;
  
  FUN_0060c390();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060c8a0 @ 0x0060c8a0 ====

void FUN_0060c8a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060c8a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0060c8b0 @ 0x0060c8b0 ====

void FUN_0060c8b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060c8b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0060c8c0 @ 0x0060c8c0 ====

void FUN_0060c8c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060c8c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0060c8d0 @ 0x0060c8d0 ====

void FUN_0060c8d0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060c8d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_0060c8e0 @ 0x0060c8e0 ====

void FUN_0060c8e0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987e73;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb7fc;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a754 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a754 = in_ECX;
  }
  pvVar2 = operator_new(0x184);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_0060ca80();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060c980 @ 0x0060c980 ====

void FUN_0060c980(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987e85;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb7fc;
  DAT_00b5a754 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009cb7ac;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060c9e0 @ 0x0060c9e0 ====

void FUN_0060c9e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb7c4;
  return;
}


// ==== FUN_0060c9f0 @ 0x0060c9f0 ====

void FUN_0060c9f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb7c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060ca20 @ 0x0060ca20 ====

void FUN_0060ca20(void)

{
  FUN_00633070();
  return;
}


// ==== FUN_0060ca30 @ 0x0060ca30 ====

void FUN_0060ca30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb7ac;
  return;
}


// ==== FUN_0060ca40 @ 0x0060ca40 ====

void FUN_0060ca40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb7ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060ca60 @ 0x0060ca60 ====

void FUN_0060ca60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cb7dc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x16c,1,(_func_void_void_ptr *)&LAB_0060ca10);
  return;
}


// ==== FUN_0060ca80 @ 0x0060ca80 ====

void FUN_0060ca80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987e48;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb7e4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cb7dc;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x16c,1,FUN_0060ca20,(_func_void_void_ptr *)&LAB_0060ca10);
  in_ECX[0x5d] = 0;
  in_ECX[0x5d] = in_ECX[0x5d] + 1;
  in_ECX[0x5e] = 0;
  in_ECX[0x5f] = 0;
  in_ECX[0x60] = in_ECX + 2;
  in_ECX[0x5a] = 0;
  in_ECX[0x5b] = 0;
  in_ECX[0x5c] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060cb20 @ 0x0060cb20 ====

undefined4 FUN_0060cb20(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x178);
}


// ==== FUN_0060cb30 @ 0x0060cb30 ====

void FUN_0060cb30(byte param_1)

{
  void *in_ECX;
  
  FUN_0060ca60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060cb50 @ 0x0060cb50 ====

void * FUN_0060cb50(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987ea9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x180);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x178) = *(int *)(in_ECX + 0x178) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x16c);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00633070();
      }
      *(undefined4 *)((int)param_2 + 0x164) = *(undefined4 *)(in_ECX + 0x17c);
      *(void **)(in_ECX + 0x17c) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x180) = *(undefined4 *)((int)param_2 + 0x160);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0x168) = param_1;
    *(undefined4 *)((int)param_2 + 0x160) = 0;
    FUN_00632e00();
  }
  else {
    if (*(int *)((int)param_2 + 0x168) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cb810,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x168) = *(int *)((int)param_2 + 0x168) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0060cc80 @ 0x0060cc80 ====

undefined4 FUN_0060cc80(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x168) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cb810,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x168);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x168);
    }
    FUN_00632e10();
    *(undefined4 *)(param_2 + 0x160) = *(undefined4 *)(in_ECX + 0x180);
    *(int *)(in_ECX + 0x178) = *(int *)(in_ECX + 0x178) + -1;
    *(int *)(in_ECX + 0x180) = param_2;
  }
  return 0;
}


// ==== FUN_0060cd10 @ 0x0060cd10 ====

void FUN_0060cd10(byte param_1)

{
  void *in_ECX;
  
  FUN_0060cd30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060cd30 @ 0x0060cd30 ====

void FUN_0060cd30(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987ed9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cb7e4;
  local_4 = 1;
  if (in_ECX[0x5e] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cb694,
                         s_d__usa_24_0_1_2__develop_share_l_009cb628,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[0x5c] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cb714,
                         s_d__usa_24_0_1_2__develop_share_l_009cb6a8,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[0x5f];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009cb7dc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x16c,1,(_func_void_void_ptr *)&LAB_0060ca10);
    *in_ECX = &PTR_FUN_009cb7c4;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0x168) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cb794,
                         s_d__usa_24_0_1_2__develop_share_l_009cb728,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00632f40();
  _free(_Memory);
  return;
}


// ==== FUN_0060ce70 @ 0x0060ce70 ====

void FUN_0060ce70(byte param_1)

{
  void *in_ECX;
  
  FUN_0060c980();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060ce90 @ 0x0060ce90 ====

void FUN_0060ce90(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060ce95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_0060cea0 @ 0x0060cea0 ====

void FUN_0060cea0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060cea5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_0060ceb0 @ 0x0060ceb0 ====

void FUN_0060ceb0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0060ceb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_0060cec0 @ 0x0060cec0 ====

void FUN_0060cec0(undefined4 param_1,int *param_2)

{
  int in_ECX;
  
  (**(code **)(*param_2 + 4))();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(param_1,param_2);
  return;
}


// ==== FUN_0060cef0 @ 0x0060cef0 ====

void FUN_0060cef0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987f23;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cba58;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aa14 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5aa14 = in_ECX;
  }
  pvVar2 = operator_new(0x108);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_0060d090();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060cf90 @ 0x0060cf90 ====

void FUN_0060cf90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987f35;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cba58;
  DAT_00b5aa14 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009cba08;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060cff0 @ 0x0060cff0 ====

void FUN_0060cff0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cba20;
  return;
}


// ==== FUN_0060d000 @ 0x0060d000 ====

void FUN_0060d000(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cba20;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d030 @ 0x0060d030 ====

void FUN_0060d030(void)

{
  FUN_00633620();
  return;
}


// ==== FUN_0060d040 @ 0x0060d040 ====

void FUN_0060d040(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cba08;
  return;
}


// ==== FUN_0060d050 @ 0x0060d050 ====

void FUN_0060d050(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cba08;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d070 @ 0x0060d070 ====

void FUN_0060d070(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cba38;
  _eh_vector_destructor_iterator_(in_ECX + 1,0xf0,1,(_func_void_void_ptr *)&LAB_0060d020);
  return;
}


// ==== FUN_0060d090 @ 0x0060d090 ====

void FUN_0060d090(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987ef8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cba40;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cba38;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0xf0,1,FUN_0060d030,(_func_void_void_ptr *)&LAB_0060d020);
  in_ECX[0x3e] = 0;
  in_ECX[0x3e] = in_ECX[0x3e] + 1;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = in_ECX + 2;
  in_ECX[0x3b] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060d130 @ 0x0060d130 ====

void FUN_0060d130(byte param_1)

{
  void *in_ECX;
  
  FUN_0060d070();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d150 @ 0x0060d150 ====

void * FUN_0060d150(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00987f59;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x104);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xfc) = *(int *)(in_ECX + 0xfc) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0xf0);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00633620();
      }
      *(undefined4 *)((int)param_2 + 0xe8) = *(undefined4 *)(in_ECX + 0x100);
      *(void **)(in_ECX + 0x100) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x104) = *(undefined4 *)((int)param_2 + 0xe4);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0xec) = param_1;
    *(undefined4 *)((int)param_2 + 0xe4) = 0;
    FUN_00633470();
  }
  else {
    if (*(int *)((int)param_2 + 0xec) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cba70,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0xec) = *(int *)((int)param_2 + 0xec) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0060d280 @ 0x0060d280 ====

undefined4 FUN_0060d280(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0xec) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cba70,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0xec);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0xec);
    }
    FUN_00633480();
    *(undefined4 *)(param_2 + 0xe4) = *(undefined4 *)(in_ECX + 0x104);
    *(int *)(in_ECX + 0xfc) = *(int *)(in_ECX + 0xfc) + -1;
    *(int *)(in_ECX + 0x104) = param_2;
  }
  return 0;
}


// ==== FUN_0060d310 @ 0x0060d310 ====

void FUN_0060d310(byte param_1)

{
  void *in_ECX;
  
  FUN_0060d330();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d330 @ 0x0060d330 ====

void FUN_0060d330(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00987f89;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cba40;
  local_4 = 1;
  if (in_ECX[0x3f] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cb8f0,
                         s_d__usa_24_0_1_2__develop_share_l_009cb888,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[0x3d] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cb970,
                         s_d__usa_24_0_1_2__develop_share_l_009cb908,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[0x40];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009cba38;
    _eh_vector_destructor_iterator_(in_ECX + 2,0xf0,1,(_func_void_void_ptr *)&LAB_0060d020);
    *in_ECX = &PTR_FUN_009cba20;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0xec) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009cb9f0,
                         s_d__usa_24_0_1_2__develop_share_l_009cb988,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00633510();
  _free(_Memory);
  return;
}


// ==== FUN_0060d470 @ 0x0060d470 ====

void FUN_0060d470(byte param_1)

{
  void *in_ECX;
  
  FUN_0060cf90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d490 @ 0x0060d490 ====

void FUN_0060d490(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbadc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d4b0 @ 0x0060d4b0 ====

void FUN_0060d4b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbadc;
  return;
}


// ==== FUN_0060d4c0 @ 0x0060d4c0 ====

void FUN_0060d4c0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  return;
}


// ==== FUN_0060d4e0 @ 0x0060d4e0 ====

int FUN_0060d4e0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060d4f0 @ 0x0060d4f0 ====

void FUN_0060d4f0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_0060d500 @ 0x0060d500 ====

void FUN_0060d500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbaf0;
  return;
}


// ==== FUN_0060d510 @ 0x0060d510 ====

void FUN_0060d510(byte param_1)

{
  void *in_ECX;
  
  FUN_0060d4b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d530 @ 0x0060d530 ====

void FUN_0060d530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb04;
  return;
}


// ==== FUN_0060d540 @ 0x0060d540 ====

void FUN_0060d540(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb04;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d560 @ 0x0060d560 ====

void FUN_0060d560(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb04;
  return;
}


// ==== FUN_0060d570 @ 0x0060d570 ====

int FUN_0060d570(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060d580 @ 0x0060d580 ====

void FUN_0060d580(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  return;
}


// ==== FUN_0060d5a0 @ 0x0060d5a0 ====

void FUN_0060d5a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987fa8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cbb14;
  FUN_00797a50(in_ECX + 1,0,0xc);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060d5f0 @ 0x0060d5f0 ====

void FUN_0060d5f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060d560();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d610 @ 0x0060d610 ====

void FUN_0060d610(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d630 @ 0x0060d630 ====

void FUN_0060d630(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb24;
  return;
}


// ==== FUN_0060d640 @ 0x0060d640 ====

int FUN_0060d640(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060d650 @ 0x0060d650 ====

void FUN_0060d650(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  for (iVar1 = 8; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_ECX = *param_1;
    param_1 = param_1 + 1;
  }
  *(undefined2 *)in_ECX = *(undefined2 *)param_1;
  return;
}


// ==== FUN_0060d670 @ 0x0060d670 ====

void FUN_0060d670(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb34;
  *(undefined2 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  *(undefined2 *)(in_ECX + 9) = 0;
  return;
}


// ==== FUN_0060d6a0 @ 0x0060d6a0 ====

void FUN_0060d6a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060d630();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d6c0 @ 0x0060d6c0 ====

void FUN_0060d6c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb50;
  return;
}


// ==== FUN_0060d6d0 @ 0x0060d6d0 ====

void FUN_0060d6d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb50;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d6f0 @ 0x0060d6f0 ====

int FUN_0060d6f0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060d700 @ 0x0060d700 ====

void FUN_0060d700(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb50;
  return;
}


// ==== FUN_0060d710 @ 0x0060d710 ====

void FUN_0060d710(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  undefined4 *in_ECX;
  uint uVar4;
  char local_ac [32];
  char local_8c [128];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987fcb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cbb60;
  *(undefined1 *)(in_ECX + 3) = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  local_4 = 0;
  *(undefined2 *)(in_ECX + 1) = 0;
  *(undefined2 *)((int)in_ECX + 6) = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
  in_ECX[0xb] = 0;
  FUN_0047b320(local_ac,&DAT_009cbb44,&DAT_009cbb41);
  pcVar1 = (char *)(in_ECX + 3);
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[(int)(local_ac + -(int)pcVar1)];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') goto LAB_0060d797;
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x20);
  *pcVar1 = '\0';
LAB_0060d797:
  FUN_0047b350(local_8c,&DAT_009cbb48,&DAT_009cbb42);
  pcVar1 = (char *)(in_ECX + 0xc);
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[(int)(local_8c + -(int)pcVar1)];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') {
      ExceptionList = local_c;
      return;
    }
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x80);
  *pcVar1 = '\0';
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060d800 @ 0x0060d800 ====

void FUN_0060d800(undefined2 *param_1)

{
  char cVar1;
  int in_ECX;
  undefined2 *puVar2;
  uint uVar3;
  
  puVar2 = (undefined2 *)(in_ECX + 4);
  *puVar2 = *param_1;
  *(undefined2 *)(in_ECX + 6) = param_1[1];
  *(undefined2 *)(in_ECX + 8) = param_1[2];
  *(undefined2 *)(in_ECX + 10) = param_1[3];
  uVar3 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar3 + 8);
    *(char *)(uVar3 + 8 + (int)puVar2) = cVar1;
    if (cVar1 == '\0') goto LAB_0060d858;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x20);
  *(undefined1 *)(in_ECX + 0xc) = 0;
LAB_0060d858:
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0x14);
  uVar3 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar3 + 0x2c);
    *(char *)(uVar3 + 0x2c + (int)puVar2) = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x80);
  *(undefined1 *)(in_ECX + 0x30) = 0;
  return;
}


// ==== FUN_0060d880 @ 0x0060d880 ====

void FUN_0060d880(byte param_1)

{
  void *in_ECX;
  
  FUN_0060d700();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d8a0 @ 0x0060d8a0 ====

void FUN_0060d8a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb70;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d8c0 @ 0x0060d8c0 ====

void FUN_0060d8c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb70;
  return;
}


// ==== FUN_0060d8d0 @ 0x0060d8d0 ====

int FUN_0060d8d0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060d8e0 @ 0x0060d8e0 ====

void FUN_0060d8e0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  return;
}


// ==== FUN_0060d8f0 @ 0x0060d8f0 ====

void FUN_0060d8f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb7c;
  return;
}


// ==== FUN_0060d900 @ 0x0060d900 ====

void FUN_0060d900(byte param_1)

{
  void *in_ECX;
  
  FUN_0060d8c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d920 @ 0x0060d920 ====

void FUN_0060d920(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb88;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d940 @ 0x0060d940 ====

int FUN_0060d940(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060d950 @ 0x0060d950 ====

void FUN_0060d950(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb88;
  return;
}


// ==== FUN_0060d960 @ 0x0060d960 ====

void FUN_0060d960(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbb94;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  return;
}


// ==== FUN_0060d970 @ 0x0060d970 ====

void FUN_0060d970(void)

{
  FUN_0060d9a0();
  return;
}


// ==== FUN_0060d980 @ 0x0060d980 ====

void FUN_0060d980(byte param_1)

{
  void *in_ECX;
  
  FUN_0060d950();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060d9a0 @ 0x0060d9a0 ====

void FUN_0060d9a0(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 2);
    *(char *)(uVar2 + 2 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0060d9cb;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 1) = 0;
LAB_0060d9cb:
  *(undefined4 *)(in_ECX + 0x82) = *(undefined4 *)(param_1 + 0x82);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(in_ECX + 0x86) = *(undefined4 *)(param_1 + 0x86);
  in_ECX[0x88] = param_1[0x88];
  *(undefined1 *)(in_ECX + 0x89) = *(undefined1 *)(param_1 + 0x89);
  return;
}


// ==== FUN_0060da10 @ 0x0060da10 ====

void FUN_0060da10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbba0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060da30 @ 0x0060da30 ====

int FUN_0060da30(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060da40 @ 0x0060da40 ====

void FUN_0060da40(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  for (iVar1 = 0x2b; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_ECX = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_0060da60 @ 0x0060da60 ====

void FUN_0060da60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbba0;
  return;
}


// ==== FUN_0060da70 @ 0x0060da70 ====

int FUN_0060da70(void)

{
  int in_ECX;
  
  return in_ECX + 0x38;
}


// ==== FUN_0060da80 @ 0x0060da80 ====

void FUN_0060da80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbb0;
  return;
}


// ==== FUN_0060da90 @ 0x0060da90 ====

void FUN_0060da90(byte param_1)

{
  void *in_ECX;
  
  FUN_0060da60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060dab0 @ 0x0060dab0 ====

void FUN_0060dab0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060dad0 @ 0x0060dad0 ====

undefined4 FUN_0060dad0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0060dae0 @ 0x0060dae0 ====

undefined4 FUN_0060dae0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_0060daf0 @ 0x0060daf0 ====

void FUN_0060daf0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_0060db00 @ 0x0060db00 ====

void FUN_0060db00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00987fe8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cbbcc;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009cbbc0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060db60 @ 0x0060db60 ====

void FUN_0060db60(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988005;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cbbcc;
  pvVar1 = operator_new(0x10);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00633890();
  }
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060dbd0 @ 0x0060dbd0 ====

void FUN_0060dbd0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060db00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060dbf0 @ 0x0060dbf0 ====

void FUN_0060dbf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbe4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060dc10 @ 0x0060dc10 ====

int FUN_0060dc10(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060dc20 @ 0x0060dc20 ====

void FUN_0060dc20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbe4;
  return;
}


// ==== FUN_0060dc30 @ 0x0060dc30 ====

void FUN_0060dc30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbf4;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  return;
}


// ==== FUN_0060dc40 @ 0x0060dc40 ====

void FUN_0060dc40(void)

{
  FUN_0060dc70();
  return;
}


// ==== FUN_0060dc50 @ 0x0060dc50 ====

void FUN_0060dc50(byte param_1)

{
  void *in_ECX;
  
  FUN_0060dc20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060dc70 @ 0x0060dc70 ====

void FUN_0060dc70(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 2);
    *(char *)(uVar2 + 2 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0060dc9c;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 1) = 0;
LAB_0060dc9c:
  *(undefined1 *)(in_ECX + 0x81) = *(undefined1 *)(param_1 + 0x81);
  *(undefined4 *)(in_ECX + 0x82) = *(undefined4 *)(param_1 + 0x82);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(in_ECX + 0x86) = *(undefined4 *)(param_1 + 0x86);
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(in_ECX + 0x8a) = *(undefined4 *)(param_1 + 0x8a);
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(in_ECX + 0x8e) = *(undefined4 *)(param_1 + 0x8e);
  *(undefined1 *)(in_ECX + 0x90) = *(undefined1 *)(param_1 + 0x90);
  return;
}


// ==== FUN_0060dd00 @ 0x0060dd00 ====

void FUN_0060dd00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbc04;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060dd20 @ 0x0060dd20 ====

void FUN_0060dd20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbc04;
  return;
}


// ==== FUN_0060dd30 @ 0x0060dd30 ====

int FUN_0060dd30(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060dd40 @ 0x0060dd40 ====

void FUN_0060dd40(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  *(undefined4 *)(in_ECX + 0x14) = param_1[4];
  *(undefined4 *)(in_ECX + 0x18) = param_1[5];
  return;
}


// ==== FUN_0060dd70 @ 0x0060dd70 ====

void FUN_0060dd70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbc14;
  *(undefined1 *)(in_ECX + 1) = 0;
  return;
}


// ==== FUN_0060dd80 @ 0x0060dd80 ====

void FUN_0060dd80(byte param_1)

{
  void *in_ECX;
  
  FUN_0060dd20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060dda0 @ 0x0060dda0 ====

void FUN_0060dda0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbc24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060ddc0 @ 0x0060ddc0 ====

int FUN_0060ddc0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060ddd0 @ 0x0060ddd0 ====

void FUN_0060ddd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbc24;
  return;
}


// ==== FUN_0060dde0 @ 0x0060dde0 ====

void FUN_0060dde0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbc34;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  return;
}


// ==== FUN_0060de00 @ 0x0060de00 ====

void FUN_0060de00(void)

{
  FUN_0060de30();
  return;
}


// ==== FUN_0060de10 @ 0x0060de10 ====

void FUN_0060de10(byte param_1)

{
  void *in_ECX;
  
  FUN_0060ddd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060de30 @ 0x0060de30 ====

void FUN_0060de30(undefined1 *param_1)

{
  char cVar1;
  undefined1 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  uVar2 = 0;
  do {
    cVar1 = param_1[uVar2 + 2];
    in_ECX[uVar2 + 2] = cVar1;
    if (cVar1 == '\0') goto LAB_0060de5d;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x1e);
  in_ECX[2] = 0;
LAB_0060de5d:
  uVar2 = 0;
  do {
    cVar1 = param_1[uVar2 + 0x20];
    in_ECX[uVar2 + 0x20] = cVar1;
    if (cVar1 == '\0') goto LAB_0060de78;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x1e);
  in_ECX[0x20] = 0;
LAB_0060de78:
  *(undefined4 *)(in_ECX + 0x40) = *(undefined4 *)(param_1 + 0x40);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x48);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x58);
  in_ECX[0x5c] = param_1[0x5c];
  in_ECX[0x5d] = param_1[0x5d];
  *(undefined2 *)(in_ECX + 0x5e) = *(undefined2 *)(param_1 + 0x5e);
  *(undefined2 *)(in_ECX + 0x60) = *(undefined2 *)(param_1 + 0x60);
  *(undefined2 *)(in_ECX + 0x62) = *(undefined2 *)(param_1 + 0x62);
  *(undefined2 *)(in_ECX + 100) = *(undefined2 *)(param_1 + 100);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x68);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x6c);
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(param_1 + 0x70);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(param_1 + 0x7c);
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(in_ECX + 0x84) = *(undefined4 *)(param_1 + 0x84);
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(param_1 + 0x88);
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(param_1 + 0x8c);
  *(undefined4 *)(in_ECX + 0x90) = *(undefined4 *)(param_1 + 0x90);
  *(undefined4 *)(in_ECX + 0x94) = *(undefined4 *)(param_1 + 0x94);
  *(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(param_1 + 0x98);
  *(undefined4 *)(in_ECX + 0x9c) = *(undefined4 *)(param_1 + 0x9c);
  *(undefined4 *)(in_ECX + 0xa0) = *(undefined4 *)(param_1 + 0xa0);
  in_ECX[0xa4] = param_1[0xa4];
  in_ECX[0xa5] = param_1[0xa5];
  *(undefined4 *)(in_ECX + 0xa8) = *(undefined4 *)(param_1 + 0xa8);
  *(undefined4 *)(in_ECX + 0xac) = *(undefined4 *)(param_1 + 0xac);
  *(undefined4 *)(in_ECX + 0xb0) = *(undefined4 *)(param_1 + 0xb0);
  *(undefined4 *)(in_ECX + 0xb4) = *(undefined4 *)(param_1 + 0xb4);
  *(undefined4 *)(in_ECX + 0xb8) = *(undefined4 *)(param_1 + 0xb8);
  *(undefined4 *)(in_ECX + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  *(undefined4 *)(in_ECX + 0xc0) = *(undefined4 *)(param_1 + 0xc0);
  in_ECX[0xc4] = param_1[0xc4];
  in_ECX[0xc5] = param_1[0xc5];
  return;
}


// ==== FUN_0060dff0 @ 0x0060dff0 ====

int FUN_0060dff0(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_0060e000 @ 0x0060e000 ====

undefined4 FUN_0060e000(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x268);
}


// ==== FUN_0060e010 @ 0x0060e010 ====

undefined4 FUN_0060e010(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x26c);
}


// ==== FUN_0060e020 @ 0x0060e020 ====

void FUN_0060e020(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x26c) = 0;
  return;
}


// ==== FUN_0060e030 @ 0x0060e030 ====

void FUN_0060e030(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0060e040 @ 0x0060e040 ====

bool FUN_0060e040(void)

{
  int in_ECX;
  
  return *(char *)(in_ECX + 8) != '\0';
}


// ==== FUN_0060e050 @ 0x0060e050 ====

void FUN_0060e050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_0060e060 @ 0x0060e060 ====

void FUN_0060e060(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 0xc,0,0x25c);
  *(undefined4 *)(in_ECX + 0x268) = 0;
  *(undefined4 *)(in_ECX + 0x26c) = 0;
  return;
}


// ==== FUN_0060e090 @ 0x0060e090 ====

void FUN_0060e090(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x268) = 0;
  return;
}


// ==== FUN_0060e0a0 @ 0x0060e0a0 ====

void FUN_0060e0a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988018;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cbc44;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)((int)in_ECX + 0x23) = 0;
  *(undefined1 *)(in_ECX + 0xf) = 0;
  local_4 = 0;
  *(undefined1 *)((int)in_ECX + 0x6f) = 0;
  FUN_00797a50(in_ECX + 3,0,0x25c);
  in_ECX[0x9a] = 0;
  in_ECX[0x9b] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060e110 @ 0x0060e110 ====

undefined4 FUN_0060e110(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 0xc,0,0x25c);
  FUN_0060e170(param_2);
  *(undefined4 *)(in_ECX + 0x268) = param_3;
  *(undefined4 *)(in_ECX + 0x26c) = param_1;
  return 1;
}


// ==== FUN_0060e150 @ 0x0060e150 ====

void FUN_0060e150(byte param_1)

{
  void *in_ECX;
  
  FUN_0060e050();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e170 @ 0x0060e170 ====

void FUN_0060e170(undefined4 *param_1)

{
  char cVar1;
  undefined4 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 4);
    *(char *)(uVar2 + 4 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0060e197;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x13);
  *(undefined1 *)(in_ECX + 1) = 0;
LAB_0060e197:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x17);
    *(char *)(uVar2 + 0x17 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0060e1b7;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)((int)in_ECX + 0x17) = 0;
LAB_0060e1b7:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x30);
    *(char *)(uVar2 + 0x30 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0060e1d7;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x33);
  *(undefined1 *)(in_ECX + 0xc) = 0;
LAB_0060e1d7:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 99);
    *(char *)(uVar2 + 99 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0060e1fa;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x1f5);
  *(undefined1 *)((int)in_ECX + 99) = 0;
LAB_0060e1fa:
  in_ECX[0x96] = param_1[0x96];
  return;
}


// ==== FUN_0060e210 @ 0x0060e210 ====

int FUN_0060e210(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0060e220 @ 0x0060e220 ====

void FUN_0060e220(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x22) = *param_1;
  *(undefined2 *)(in_ECX + 0x26) = *(undefined2 *)(param_1 + 1);
  return;
}


// ==== FUN_0060e240 @ 0x0060e240 ====

int FUN_0060e240(void)

{
  int in_ECX;
  
  return in_ECX + 0x22;
}


// ==== FUN_0060e250 @ 0x0060e250 ====

void FUN_0060e250(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 0x22,0,6);
  *(undefined1 *)(in_ECX + 0x26) = 100;
  return;
}


// ==== FUN_0060e270 @ 0x0060e270 ====

void FUN_0060e270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_0060e280 @ 0x0060e280 ====

void FUN_0060e280(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988038;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cbc74;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00797a50((int)in_ECX + 0x22,0,6);
  *(undefined1 *)((int)in_ECX + 0x26) = 100;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060e2e0 @ 0x0060e2e0 ====

undefined4 FUN_0060e2e0(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int in_ECX;
  uint uVar4;
  
  FUN_00797a50(in_ECX + 0x22,0,6);
  pcVar1 = (char *)(in_ECX + 8);
  *(undefined1 *)(in_ECX + 0x26) = 100;
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[param_1 - (int)pcVar1];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') goto LAB_0060e31c;
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x19);
  *pcVar1 = '\0';
LAB_0060e31c:
  return CONCAT31((int3)((uint)pcVar3 >> 8),1);
}


// ==== FUN_0060e330 @ 0x0060e330 ====

void FUN_0060e330(byte param_1)

{
  void *in_ECX;
  
  FUN_0060e270();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e350 @ 0x0060e350 ====

void FUN_0060e350(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbc94;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e370 @ 0x0060e370 ====

void FUN_0060e370(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbc94;
  return;
}


// ==== FUN_0060e380 @ 0x0060e380 ====

undefined2 FUN_0060e380(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 4);
}


// ==== FUN_0060e390 @ 0x0060e390 ====

undefined1 FUN_0060e390(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 6);
}


// ==== FUN_0060e3a0 @ 0x0060e3a0 ====

undefined2 FUN_0060e3a0(byte param_1)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 8 + (uint)param_1 * 2);
}


// ==== FUN_0060e3b0 @ 0x0060e3b0 ====

void FUN_0060e3b0(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_0060e3c0 @ 0x0060e3c0 ====

void FUN_0060e3c0(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 8 + (uint)*(byte *)(in_ECX + 6) * 2) = param_1;
  *(char *)(in_ECX + 6) = *(char *)(in_ECX + 6) + '\x01';
  return;
}


// ==== FUN_0060e3e0 @ 0x0060e3e0 ====

void FUN_0060e3e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbcb0;
  *(undefined2 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  return;
}


// ==== FUN_0060e400 @ 0x0060e400 ====

void FUN_0060e400(byte param_1)

{
  void *in_ECX;
  
  FUN_0060e370();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e420 @ 0x0060e420 ====

void FUN_0060e420(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbccc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e440 @ 0x0060e440 ====

void FUN_0060e440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbccc;
  return;
}


// ==== FUN_0060e450 @ 0x0060e450 ====

void FUN_0060e450(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined2 *)(in_ECX + 0xc) = *(undefined2 *)(param_1 + 2);
  return;
}


// ==== FUN_0060e470 @ 0x0060e470 ====

int FUN_0060e470(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060e480 @ 0x0060e480 ====

void FUN_0060e480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbcdc;
  return;
}


// ==== FUN_0060e490 @ 0x0060e490 ====

void FUN_0060e490(byte param_1)

{
  void *in_ECX;
  
  FUN_0060e440();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e4b0 @ 0x0060e4b0 ====

undefined4 FUN_0060e4b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0060e4c0 @ 0x0060e4c0 ====

void FUN_0060e4c0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_0060e4d0 @ 0x0060e4d0 ====

undefined4 FUN_0060e4d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_0060e4e0 @ 0x0060e4e0 ====

void FUN_0060e4e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988058;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cbcec;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009cbbc0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060e540 @ 0x0060e540 ====

void FUN_0060e540(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = 0;
                    /* WARNING: Could not recover jumptable at 0x0060e54c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 8))();
  return;
}


// ==== FUN_0060e550 @ 0x0060e550 ====

undefined4 FUN_0060e550(void)

{
  return 0;
}


// ==== FUN_0060e560 @ 0x0060e560 ====

void FUN_0060e560(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988075;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cbcec;
  pvVar1 = operator_new(0xc);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00633940();
  }
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060e5d0 @ 0x0060e5d0 ====

void FUN_0060e5d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060e4e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e5f0 @ 0x0060e5f0 ====

void FUN_0060e5f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd0c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e610 @ 0x0060e610 ====

void FUN_0060e610(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd0c;
  return;
}


// ==== FUN_0060e620 @ 0x0060e620 ====

int FUN_0060e620(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060e630 @ 0x0060e630 ====

void FUN_0060e630(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  return;
}


// ==== FUN_0060e650 @ 0x0060e650 ====

void FUN_0060e650(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd1c;
  return;
}


// ==== FUN_0060e660 @ 0x0060e660 ====

void FUN_0060e660(byte param_1)

{
  void *in_ECX;
  
  FUN_0060e610();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e680 @ 0x0060e680 ====

void FUN_0060e680(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd2c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e6a0 @ 0x0060e6a0 ====

void FUN_0060e6a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd2c;
  return;
}


// ==== FUN_0060e6b0 @ 0x0060e6b0 ====

int FUN_0060e6b0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060e6c0 @ 0x0060e6c0 ====

void FUN_0060e6c0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  return;
}


// ==== FUN_0060e6e0 @ 0x0060e6e0 ====

void FUN_0060e6e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd3c;
  return;
}


// ==== FUN_0060e6f0 @ 0x0060e6f0 ====

void FUN_0060e6f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060e6a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e710 @ 0x0060e710 ====

void FUN_0060e710(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e730 @ 0x0060e730 ====

void FUN_0060e730(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd4c;
  return;
}


// ==== FUN_0060e740 @ 0x0060e740 ====

int FUN_0060e740(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060e750 @ 0x0060e750 ====

void FUN_0060e750(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  return;
}


// ==== FUN_0060e770 @ 0x0060e770 ====

void FUN_0060e770(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd5c;
  return;
}


// ==== FUN_0060e780 @ 0x0060e780 ====

void FUN_0060e780(byte param_1)

{
  void *in_ECX;
  
  FUN_0060e730();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e7a0 @ 0x0060e7a0 ====

void FUN_0060e7a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd6c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e7c0 @ 0x0060e7c0 ====

int FUN_0060e7c0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060e7d0 @ 0x0060e7d0 ====

void FUN_0060e7d0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  for (iVar1 = 9; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_ECX = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_0060e7f0 @ 0x0060e7f0 ====

void FUN_0060e7f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd6c;
  return;
}


// ==== FUN_0060e800 @ 0x0060e800 ====

void FUN_0060e800(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd7c;
  return;
}


// ==== FUN_0060e810 @ 0x0060e810 ====

void FUN_0060e810(byte param_1)

{
  void *in_ECX;
  
  FUN_0060e7f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e830 @ 0x0060e830 ====

void FUN_0060e830(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e850 @ 0x0060e850 ====

void FUN_0060e850(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd8c;
  return;
}


// ==== FUN_0060e860 @ 0x0060e860 ====

int FUN_0060e860(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0060e870 @ 0x0060e870 ====

void FUN_0060e870(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  return;
}


// ==== FUN_0060e880 @ 0x0060e880 ====

void FUN_0060e880(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbd9c;
  return;
}


// ==== FUN_0060e890 @ 0x0060e890 ====

void FUN_0060e890(byte param_1)

{
  void *in_ECX;
  
  FUN_0060e850();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e8b0 @ 0x0060e8b0 ====

void FUN_0060e8b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_0060e8c0 @ 0x0060e8c0 ====

void FUN_0060e8c0(void)

{
  return;
}


// ==== FUN_0060e8d0 @ 0x0060e8d0 ====

void FUN_0060e8d0(void)

{
  return;
}


// ==== FUN_0060e8e0 @ 0x0060e8e0 ====

int FUN_0060e8e0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0060e8f0 @ 0x0060e8f0 ====

void FUN_0060e8f0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0060e900 @ 0x0060e900 ====

void FUN_0060e900(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988088;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cbdac;
  FUN_00797a50(in_ECX + 2,0,4);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0060e950 @ 0x0060e950 ====

void FUN_0060e950(byte param_1)

{
  void *in_ECX;
  
  FUN_0060e8b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e970 @ 0x0060e970 ====

void FUN_0060e970(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbdc0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060e990 @ 0x0060e990 ====

void FUN_0060e990(void)

{
  return;
}


// ==== FUN_0060e9a0 @ 0x0060e9a0 ====

undefined1 FUN_0060e9a0(void)

{
  return 1;
}


// ==== FUN_0060e9b0 @ 0x0060e9b0 ====

int FUN_0060e9b0(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060e9c0 @ 0x0060e9c0 ====

undefined1 FUN_0060e9c0(void)

{
  return 1;
}


// ==== FUN_0060e9d0 @ 0x0060e9d0 ====

undefined1 FUN_0060e9d0(void)

{
  return 0;
}


// ==== FUN_0060e9e0 @ 0x0060e9e0 ====

int FUN_0060e9e0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060ea00 @ 0x0060ea00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060ea00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbde4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b024 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b024 = in_ECX;
  return;
}


// ==== FUN_0060ea30 @ 0x0060ea30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060ea30(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b024 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060ea50 @ 0x0060ea50 ====

void FUN_0060ea50(byte param_1)

{
  void *in_ECX;
  
  FUN_0060ea30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060ea70 @ 0x0060ea70 ====

void FUN_0060ea70(void)

{
  return;
}


// ==== FUN_0060ea80 @ 0x0060ea80 ====

undefined1 FUN_0060ea80(void)

{
  return 1;
}


// ==== FUN_0060ea90 @ 0x0060ea90 ====

int FUN_0060ea90(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060eaa0 @ 0x0060eaa0 ====

undefined1 FUN_0060eaa0(void)

{
  return 1;
}


// ==== FUN_0060eab0 @ 0x0060eab0 ====

undefined1 FUN_0060eab0(void)

{
  return 0;
}


// ==== FUN_0060eac0 @ 0x0060eac0 ====

int FUN_0060eac0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060eae0 @ 0x0060eae0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060eae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbe08;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b038 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b038 = in_ECX;
  return;
}


// ==== FUN_0060eb10 @ 0x0060eb10 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060eb10(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b038 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060eb30 @ 0x0060eb30 ====

void FUN_0060eb30(byte param_1)

{
  void *in_ECX;
  
  FUN_0060eb10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060eb50 @ 0x0060eb50 ====

bool FUN_0060eb50(uint *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return *(uint *)(iVar1 + 0xd) < *param_1;
}


// ==== FUN_0060eb70 @ 0x0060eb70 ====

int FUN_0060eb70(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060eb80 @ 0x0060eb80 ====

undefined1 FUN_0060eb80(void)

{
  return 1;
}


// ==== FUN_0060eb90 @ 0x0060eb90 ====

undefined1 FUN_0060eb90(void)

{
  return 0;
}


// ==== FUN_0060eba0 @ 0x0060eba0 ====

int FUN_0060eba0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  *(int *)((int)param_1 + 0xd) = *(int *)((int)param_1 + 0xd) + (param_2 - iVar1);
  return param_2 - iVar1;
}


// ==== FUN_0060ebc0 @ 0x0060ebc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060ebc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbe2c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b02c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b02c = in_ECX;
  return;
}


// ==== FUN_0060ebf0 @ 0x0060ebf0 ====

void FUN_0060ebf0(uint param_1,int *param_2)

{
  int iVar1;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  if (*(uint *)(iVar1 + 0xd) < param_1) {
    (**(code **)(*in_ECX + 0x10))(param_1,param_2);
    FUN_00797a50(auStack_a + -10,0,0xc);
    (**(code **)(*param_2 + 0x24))(auStack_a + -10);
  }
  return;
}


// ==== FUN_0060ec70 @ 0x0060ec70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060ec70(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b02c = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060ec90 @ 0x0060ec90 ====

void FUN_0060ec90(byte param_1)

{
  void *in_ECX;
  
  FUN_0060ec70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060ecb0 @ 0x0060ecb0 ====

void FUN_0060ecb0(undefined4 *param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined4 local_4;
  
  uVar1 = FUN_00802534();
  uVar2 = FUN_00802534();
  local_4 = CONCAT22(uVar2,uVar1);
  *param_1 = local_4;
  return;
}


// ==== FUN_0060ece0 @ 0x0060ece0 ====

void FUN_0060ece0(void)

{
  return;
}


// ==== FUN_0060ecf0 @ 0x0060ecf0 ====

undefined1 FUN_0060ecf0(void)

{
  return 1;
}


// ==== FUN_0060ed00 @ 0x0060ed00 ====

undefined1 FUN_0060ed00(void)

{
  return 1;
}


// ==== FUN_0060ed10 @ 0x0060ed10 ====

undefined1 FUN_0060ed10(void)

{
  return 0;
}


// ==== FUN_0060ed20 @ 0x0060ed20 ====

int FUN_0060ed20(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060ed90 @ 0x0060ed90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060ed90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbe50;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b030 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b030 = in_ECX;
  return;
}


// ==== FUN_0060edc0 @ 0x0060edc0 ====

undefined4 FUN_0060edc0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  float fVar3;
  int unaff_retaddr;
  
  iVar1 = (**(code **)(*param_3 + 0x4c))();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x50) != 0)) {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x50) + 0x14))(param_2);
    if (*(char *)(unaff_retaddr + 0xd) == '\x01') {
      iVar1 = (**(code **)(*piVar2 + 0x30))();
      fVar3 = *(float *)(iVar1 + 8) * DAT_0099d0f8;
    }
    else {
      iVar1 = (**(code **)(*piVar2 + 0x30))();
      fVar3 = *(float *)(iVar1 + 8);
    }
    fVar3 = fVar3 - (float)*(ushort *)(unaff_retaddr + 0xe) * DAT_009b3508;
    if (fVar3 <= 0.0) {
      fVar3 = 0.0 - fVar3;
    }
    if (DAT_009a09bc <= fVar3) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_0060ee50 @ 0x0060ee50 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_0060ee50(float param_1,int *param_2)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  float fVar8;
  float unaff_retaddr;
  undefined4 uStack_34;
  undefined1 auStack_30 [8];
  float fStack_28;
  float fStack_24;
  undefined4 uStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  puVar4 = (uint *)(**(code **)(*param_2 + 0x10))();
  if ((uint)param_1 <= *puVar4) {
    iVar5 = (**(code **)(*param_2 + 0x10))();
    return (int *)(iVar5 + 4);
  }
  piVar6 = (int *)(**(code **)(*param_2 + 0x10))();
  pfVar7 = (float *)(**(code **)(*DAT_00b5ab40 + 4))((char)piVar6[3]);
  fStack_10 = *pfVar7;
  fStack_c = pfVar7[1];
  fStack_8 = pfVar7[2];
  fVar8 = (float)((int)param_1 - *piVar6);
  if ((int)param_1 - *piVar6 < 0) {
    fVar8 = fVar8 + _DAT_0099d104;
  }
  fVar8 = fVar8 * DAT_0099d0ec;
  if (DAT_009bac80 < fVar8) {
    return piVar6 + 1;
  }
  FUN_004f5730(&fStack_1c);
  fVar8 = fVar8 * unaff_retaddr;
  fStack_28 = fStack_1c;
  fStack_24 = fStack_18;
  uStack_20 = uStack_14;
  if (0.0 < fVar8) {
    uStack_14 = 0;
    do {
      param_1 = DAT_0099d080;
      if (fVar8 <= DAT_0099d080) {
        param_1 = fVar8;
      }
      fStack_1c = fStack_10 * param_1 + fStack_28;
      fStack_18 = fStack_c * param_1 + fStack_24;
      uVar2 = FUN_00802534();
      uVar3 = FUN_00802534();
      uStack_34 = CONCAT22(uVar3,uVar2);
      cVar1 = (**(code **)(*param_2 + 0x14))(&uStack_34);
      if (cVar1 == '\0') break;
      fVar8 = fVar8 - DAT_0099d080;
      fStack_28 = fStack_1c;
      fStack_24 = fStack_18;
      uStack_20 = 0;
    } while (DAT_0099cdc8 < fVar8);
  }
  FUN_004ef0e0(auStack_30);
  (**(code **)(*param_2 + 0x40))(auStack_30);
  piVar6 = (int *)FUN_00633b30();
  return piVar6;
}


// ==== FUN_0060f020 @ 0x0060f020 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f020(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b030 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060f040 @ 0x0060f040 ====

void FUN_0060f040(byte param_1)

{
  void *in_ECX;
  
  FUN_0060f020();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060f060 @ 0x0060f060 ====

void FUN_0060f060(void)

{
  return;
}


// ==== FUN_0060f070 @ 0x0060f070 ====

bool FUN_0060f070(int param_1)

{
  return *(char *)(param_1 + 0xb) == '\t';
}


// ==== FUN_0060f080 @ 0x0060f080 ====

int FUN_0060f080(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060f090 @ 0x0060f090 ====

undefined1 FUN_0060f090(void)

{
  return 0;
}


// ==== FUN_0060f0a0 @ 0x0060f0a0 ====

undefined1 FUN_0060f0a0(void)

{
  return 0;
}


// ==== FUN_0060f0b0 @ 0x0060f0b0 ====

int FUN_0060f0b0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060f0d0 @ 0x0060f0d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f0d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbe74;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b034 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b034 = in_ECX;
  return;
}


// ==== FUN_0060f100 @ 0x0060f100 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f100(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b034 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060f120 @ 0x0060f120 ====

void FUN_0060f120(byte param_1)

{
  void *in_ECX;
  
  FUN_0060f100();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060f140 @ 0x0060f140 ====

void FUN_0060f140(void)

{
  return;
}


// ==== FUN_0060f150 @ 0x0060f150 ====

undefined1 FUN_0060f150(void)

{
  return 1;
}


// ==== FUN_0060f160 @ 0x0060f160 ====

int FUN_0060f160(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060f170 @ 0x0060f170 ====

undefined1 FUN_0060f170(void)

{
  return 1;
}


// ==== FUN_0060f180 @ 0x0060f180 ====

undefined1 FUN_0060f180(void)

{
  return 0;
}


// ==== FUN_0060f190 @ 0x0060f190 ====

int FUN_0060f190(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060f1b0 @ 0x0060f1b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f1b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbe98;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b028 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b028 = in_ECX;
  return;
}


// ==== FUN_0060f1e0 @ 0x0060f1e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f1e0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b028 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060f200 @ 0x0060f200 ====

void FUN_0060f200(byte param_1)

{
  void *in_ECX;
  
  FUN_0060f1e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060f220 @ 0x0060f220 ====

void FUN_0060f220(void)

{
  return;
}


// ==== FUN_0060f230 @ 0x0060f230 ====

undefined1 FUN_0060f230(void)

{
  return 0;
}


// ==== FUN_0060f240 @ 0x0060f240 ====

int FUN_0060f240(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060f250 @ 0x0060f250 ====

undefined1 FUN_0060f250(void)

{
  return 1;
}


// ==== FUN_0060f260 @ 0x0060f260 ====

undefined1 FUN_0060f260(void)

{
  return 0;
}


// ==== FUN_0060f270 @ 0x0060f270 ====

undefined4 FUN_0060f270(void)

{
  return 0;
}


// ==== FUN_0060f280 @ 0x0060f280 ====

void FUN_0060f280(void)

{
  return;
}


// ==== FUN_0060f290 @ 0x0060f290 ====

undefined1 FUN_0060f290(void)

{
  return 0;
}


// ==== FUN_0060f2a0 @ 0x0060f2a0 ====

int FUN_0060f2a0(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060f2b0 @ 0x0060f2b0 ====

undefined1 FUN_0060f2b0(void)

{
  return 1;
}


// ==== FUN_0060f2c0 @ 0x0060f2c0 ====

undefined1 FUN_0060f2c0(void)

{
  return 0;
}


// ==== FUN_0060f2d0 @ 0x0060f2d0 ====

undefined4 FUN_0060f2d0(void)

{
  return 0;
}


// ==== FUN_0060f2e0 @ 0x0060f2e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f2e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbebc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b040 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b040 = in_ECX;
  return;
}


// ==== FUN_0060f310 @ 0x0060f310 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f310(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbee0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b03c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b03c = in_ECX;
  return;
}


// ==== FUN_0060f340 @ 0x0060f340 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f340(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b040 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060f360 @ 0x0060f360 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f360(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b03c = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060f380 @ 0x0060f380 ====

void FUN_0060f380(byte param_1)

{
  void *in_ECX;
  
  FUN_0060f340();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060f3a0 @ 0x0060f3a0 ====

void FUN_0060f3a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060f360();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060f3c0 @ 0x0060f3c0 ====

void FUN_0060f3c0(void)

{
  return;
}


// ==== FUN_0060f3d0 @ 0x0060f3d0 ====

int FUN_0060f3d0(int param_1)

{
  uint3 uVar1;
  
  uVar1 = (uint3)(*(byte *)(param_1 + 0xb) - 1 >> 8);
  switch(*(byte *)(param_1 + 0xb)) {
  case 1:
  case 8:
  case 0x15:
  case 0x16:
  case 0x17:
    return CONCAT31(uVar1,1);
  default:
    return (uint)uVar1 << 8;
  }
}


// ==== FUN_0060f420 @ 0x0060f420 ====

int FUN_0060f420(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060f430 @ 0x0060f430 ====

undefined1 FUN_0060f430(void)

{
  return 1;
}


// ==== FUN_0060f440 @ 0x0060f440 ====

undefined1 FUN_0060f440(void)

{
  return 0;
}


// ==== FUN_0060f450 @ 0x0060f450 ====

int FUN_0060f450(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060f470 @ 0x0060f470 ====

void FUN_0060f470(void)

{
  return;
}


// ==== FUN_0060f480 @ 0x0060f480 ====

int FUN_0060f480(int param_1)

{
  uint3 uVar1;
  
  uVar1 = (uint3)(*(byte *)(param_1 + 0xb) - 1 >> 8);
  switch(*(byte *)(param_1 + 0xb)) {
  case 1:
  case 8:
  case 0x15:
  case 0x16:
  case 0x17:
    return CONCAT31(uVar1,1);
  default:
    return (uint)uVar1 << 8;
  }
}


// ==== FUN_0060f4d0 @ 0x0060f4d0 ====

int FUN_0060f4d0(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060f4e0 @ 0x0060f4e0 ====

undefined1 FUN_0060f4e0(void)

{
  return 1;
}


// ==== FUN_0060f4f0 @ 0x0060f4f0 ====

undefined1 FUN_0060f4f0(void)

{
  return 0;
}


// ==== FUN_0060f500 @ 0x0060f500 ====

int FUN_0060f500(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060f520 @ 0x0060f520 ====

undefined4 FUN_0060f520(uint *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = (**(code **)(*param_2 + 0x10))();
  if (((*(uint *)(iVar2 + 0xc) < *param_1) || (cVar1 = *(char *)((int)param_1 + 0xb), cVar1 == '\b')
      ) || (cVar1 == '\x01')) {
    return 1;
  }
  if ((((cVar1 == '\a') || (cVar1 == '\f')) || ((cVar1 == '\r' || (cVar1 == '\x0e')))) &&
     (puVar3 = (uint *)(**(code **)(*param_2 + 0x10))(), *puVar3 < *param_1)) {
    return 1;
  }
  return 0;
}


// ==== FUN_0060f570 @ 0x0060f570 ====

int FUN_0060f570(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060f580 @ 0x0060f580 ====

undefined1 FUN_0060f580(void)

{
  return 1;
}


// ==== FUN_0060f590 @ 0x0060f590 ====

undefined1 FUN_0060f590(void)

{
  return 0;
}


// ==== FUN_0060f5a0 @ 0x0060f5a0 ====

int FUN_0060f5a0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060f5c0 @ 0x0060f5c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f5c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbf04;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b04c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b04c = in_ECX;
  return;
}


// ==== FUN_0060f5f0 @ 0x0060f5f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f5f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbf28;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b048 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b048 = in_ECX;
  return;
}


// ==== FUN_0060f620 @ 0x0060f620 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f620(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbf4c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b044 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b044 = in_ECX;
  return;
}


// ==== FUN_0060f650 @ 0x0060f650 ====

void FUN_0060f650(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  uint unaff_retaddr;
  undefined1 auStack_1e [18];
  undefined1 auStack_c [4];
  uint uStack_8;
  uint uStack_4;
  
  piVar1 = (int *)(**(code **)(*param_2 + 0x48))();
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*param_2 + 0x10))();
    auStack_c[0] = *(undefined1 *)((int)piVar2 + 10);
    uStack_8 = (uint)*(byte *)((int)piVar2 + 0xb);
    uStack_4 = (uint)*(byte *)(piVar2 + 4);
    iVar3 = (**(code **)(*piVar1 + 0xc))(auStack_c);
    if ((iVar3 != 0) &&
       ((uint)(*piVar2 - (int)ROUND(*(float *)(iVar3 + 0x114) * DAT_0099d0f4)) < unaff_retaddr)) {
      (**(code **)(*in_ECX + 0x10))(unaff_retaddr,param_2);
      uStack_4 = CONCAT31(uStack_4._1_3_,*(undefined1 *)((int)piVar2 + 10));
      FUN_00797a50(auStack_1e + -6,0,0xc);
      (**(code **)(*param_2 + 0x24))(auStack_1e + -6);
    }
  }
  return;
}


// ==== FUN_0060f750 @ 0x0060f750 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f750(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b04c = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060f770 @ 0x0060f770 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f770(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b048 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060f790 @ 0x0060f790 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f790(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b044 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060f7b0 @ 0x0060f7b0 ====

void FUN_0060f7b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060f750();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060f7d0 @ 0x0060f7d0 ====

void FUN_0060f7d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060f770();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060f7f0 @ 0x0060f7f0 ====

void FUN_0060f7f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060f790();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060f810 @ 0x0060f810 ====

void FUN_0060f810(void)

{
  return;
}


// ==== FUN_0060f820 @ 0x0060f820 ====

undefined1 FUN_0060f820(void)

{
  return 0;
}


// ==== FUN_0060f830 @ 0x0060f830 ====

int FUN_0060f830(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060f840 @ 0x0060f840 ====

undefined1 FUN_0060f840(void)

{
  return 1;
}


// ==== FUN_0060f850 @ 0x0060f850 ====

undefined1 FUN_0060f850(void)

{
  return 0;
}


// ==== FUN_0060f860 @ 0x0060f860 ====

int FUN_0060f860(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060f880 @ 0x0060f880 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f880(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbf70;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b050 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b050 = in_ECX;
  return;
}


// ==== FUN_0060f8b0 @ 0x0060f8b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f8b0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b050 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060f8d0 @ 0x0060f8d0 ====

void FUN_0060f8d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060f8b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060f8f0 @ 0x0060f8f0 ====

void FUN_0060f8f0(void)

{
  return;
}


// ==== FUN_0060f900 @ 0x0060f900 ====

undefined1 FUN_0060f900(void)

{
  return 0;
}


// ==== FUN_0060f910 @ 0x0060f910 ====

int FUN_0060f910(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060f920 @ 0x0060f920 ====

undefined1 FUN_0060f920(void)

{
  return 1;
}


// ==== FUN_0060f930 @ 0x0060f930 ====

undefined1 FUN_0060f930(void)

{
  return 0;
}


// ==== FUN_0060f940 @ 0x0060f940 ====

int FUN_0060f940(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060f960 @ 0x0060f960 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f960(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbf94;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b054 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b054 = in_ECX;
  return;
}


// ==== FUN_0060f990 @ 0x0060f990 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060f990(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b054 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060f9b0 @ 0x0060f9b0 ====

void FUN_0060f9b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060f990();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060f9d0 @ 0x0060f9d0 ====

void FUN_0060f9d0(void)

{
  return;
}


// ==== FUN_0060f9e0 @ 0x0060f9e0 ====

int FUN_0060f9e0(int param_1)

{
  uint3 uVar1;
  
  uVar1 = (uint3)(*(byte *)(param_1 + 0xb) - 7 >> 8);
  switch(*(byte *)(param_1 + 0xb)) {
  case 7:
  case 8:
  case 9:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0x12:
    return CONCAT31(uVar1,1);
  default:
    return (uint)uVar1 << 8;
  }
}


// ==== FUN_0060fa20 @ 0x0060fa20 ====

int FUN_0060fa20(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060fa30 @ 0x0060fa30 ====

undefined1 FUN_0060fa30(void)

{
  return 1;
}


// ==== FUN_0060fa40 @ 0x0060fa40 ====

undefined1 FUN_0060fa40(void)

{
  return 0;
}


// ==== FUN_0060fa50 @ 0x0060fa50 ====

int FUN_0060fa50(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060fa70 @ 0x0060fa70 ====

undefined1 FUN_0060fa70(void)

{
  return 1;
}


// ==== FUN_0060fa80 @ 0x0060fa80 ====

int FUN_0060fa80(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060fa90 @ 0x0060fa90 ====

undefined1 FUN_0060fa90(void)

{
  return 1;
}


// ==== FUN_0060faa0 @ 0x0060faa0 ====

undefined1 FUN_0060faa0(void)

{
  return 0;
}


// ==== FUN_0060fab0 @ 0x0060fab0 ====

int FUN_0060fab0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060fad0 @ 0x0060fad0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060fad0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbfb8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b05c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b05c = in_ECX;
  return;
}


// ==== FUN_0060fb00 @ 0x0060fb00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060fb00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbfdc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b058 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b058 = in_ECX;
  return;
}


// ==== FUN_0060fb30 @ 0x0060fb30 ====

void FUN_0060fb30(undefined4 param_1,int *param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *in_ECX;
  uint unaff_retaddr;
  undefined1 auStack_1c [4];
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  
  iVar3 = (**(code **)(*param_2 + 0x4c))();
  if ((iVar3 != 0) && (piVar4 = (int *)(**(code **)(*param_2 + 0x48))(), piVar4 != (int *)0x0)) {
    piVar5 = (int *)(**(code **)(*param_2 + 0x10))();
    uStack_18 = CONCAT31((int3)((uint)uStack_18 >> 8),*(undefined1 *)((int)piVar5 + 10));
    uStack_14 = (uint)*(byte *)((int)piVar5 + 0xb);
    uStack_10 = 0;
    iVar3 = (**(code **)(*piVar4 + 0xc))(&uStack_18);
    if ((iVar3 != 0) &&
       ((uint)(*piVar5 - (int)ROUND(*(float *)(iVar3 + 0x114) * DAT_0099d0f4)) < unaff_retaddr)) {
      puVar6 = (undefined4 *)(**(code **)(*in_ECX + 0x10))(unaff_retaddr,param_2);
      uVar2 = *puVar6;
      uVar1 = *(undefined2 *)(puVar6 + 1);
      iVar3 = (**(code **)(*param_2 + 0x4c))();
      piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x50) + 0x14))(unaff_retaddr);
      iVar3 = (**(code **)(*piVar4 + 0x10))();
      FUN_004ef6c0(auStack_1c,unaff_retaddr,*(undefined1 *)(iVar3 + 2));
      uStack_14 = CONCAT22(uStack_14._2_2_,uVar1);
      uStack_18 = uVar2;
      (**(code **)(*param_2 + 0x24))(auStack_1c);
    }
  }
  return;
}


// ==== FUN_0060fc30 @ 0x0060fc30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060fc30(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b05c = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060fc50 @ 0x0060fc50 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060fc50(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b058 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060fc70 @ 0x0060fc70 ====

void FUN_0060fc70(byte param_1)

{
  void *in_ECX;
  
  FUN_0060fc30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060fc90 @ 0x0060fc90 ====

void FUN_0060fc90(byte param_1)

{
  void *in_ECX;
  
  FUN_0060fc50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060fcb0 @ 0x0060fcb0 ====

void FUN_0060fcb0(void)

{
  return;
}


// ==== FUN_0060fcc0 @ 0x0060fcc0 ====

undefined1 FUN_0060fcc0(void)

{
  return 1;
}


// ==== FUN_0060fcd0 @ 0x0060fcd0 ====

int FUN_0060fcd0(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060fce0 @ 0x0060fce0 ====

undefined1 FUN_0060fce0(void)

{
  return 1;
}


// ==== FUN_0060fcf0 @ 0x0060fcf0 ====

undefined1 FUN_0060fcf0(void)

{
  return 0;
}


// ==== FUN_0060fd00 @ 0x0060fd00 ====

int FUN_0060fd00(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060fd20 @ 0x0060fd20 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060fd20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc000;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b060 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b060 = in_ECX;
  return;
}


// ==== FUN_0060fd50 @ 0x0060fd50 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060fd50(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b060 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060fd70 @ 0x0060fd70 ====

void FUN_0060fd70(byte param_1)

{
  void *in_ECX;
  
  FUN_0060fd50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060fd90 @ 0x0060fd90 ====

void FUN_0060fd90(void)

{
  return;
}


// ==== FUN_0060fda0 @ 0x0060fda0 ====

undefined4 FUN_0060fda0(int param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)(**(code **)(*param_2 + 0x4c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x10))();
  cVar1 = (**(code **)(*piVar2 + 0x44))();
  if (cVar1 == '\x01') {
    switch(*(undefined1 *)(param_1 + 0xb)) {
    case 6:
    case 10:
    case 0xf:
    case 0x11:
    case 0x12:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x1e:
    case 0x1f:
      return 0;
    }
  }
  return 1;
}


// ==== FUN_0060fe10 @ 0x0060fe10 ====

int FUN_0060fe10(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060fe20 @ 0x0060fe20 ====

undefined1 FUN_0060fe20(void)

{
  return 1;
}


// ==== FUN_0060fe30 @ 0x0060fe30 ====

undefined1 FUN_0060fe30(void)

{
  return 0;
}


// ==== FUN_0060fe40 @ 0x0060fe40 ====

int FUN_0060fe40(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060fe60 @ 0x0060fe60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060fe60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc024;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b064 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b064 = in_ECX;
  return;
}


// ==== FUN_0060fe90 @ 0x0060fe90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060fe90(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b064 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_0060feb0 @ 0x0060feb0 ====

void FUN_0060feb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060fe90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0060fed0 @ 0x0060fed0 ====

int FUN_0060fed0(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_0060fee0 @ 0x0060fee0 ====

undefined1 FUN_0060fee0(void)

{
  return 1;
}


// ==== FUN_0060fef0 @ 0x0060fef0 ====

undefined1 FUN_0060fef0(void)

{
  return 0;
}


// ==== FUN_0060ff00 @ 0x0060ff00 ====

int FUN_0060ff00(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_0060ff20 @ 0x0060ff20 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060ff20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc048;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b068 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b068 = in_ECX;
  return;
}


// ==== FUN_0060ff50 @ 0x0060ff50 ====

bool FUN_0060ff50(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(*param_2 + 0x10))();
  iVar2 = (**(code **)(*param_2 + 0x4c))();
  if (*(int *)(iVar2 + 0x40) == 0) {
    iVar2 = *piVar1;
    iVar4 = (**(code **)(*DAT_00b5acc8 + 0x28))(piVar1);
    if ((*(int *)((int)piVar1 + 0xf) != 3) && (*(int *)((int)piVar1 + 0xf) != 0)) {
      return (uint)(iVar2 + *(int *)(iVar4 + 8)) <= unaff_retaddr;
    }
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x40) + 0x20))();
    piVar1 = (int *)(**(code **)(*piVar3 + 0x18))((short)piVar1[3]);
    if (piVar1 != (int *)0x0) {
      piVar1 = (int *)(**(code **)(*piVar1 + 0x18))();
      piVar1 = (int *)(**(code **)(*piVar1 + 0x10))();
      if (*piVar1 != 0) {
        return *piVar1 == 3;
      }
    }
  }
  return true;
}


// ==== FUN_0060ffe0 @ 0x0060ffe0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0060ffe0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b068 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


