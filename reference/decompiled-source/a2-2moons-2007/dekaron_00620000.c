// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x620000-0x62ffff

// ==== __break @ 0x00620016 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00620020 @ 0x00620020 ====

void FUN_00620020(void)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  int *piVar7;
  undefined1 auStack_112 [246];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 *puStack_4;
  
  puStack_4 = (undefined4 *)0xffffffff;
  puStack_8 = &LAB_009892d0;
  pvStack_c = ExceptionList;
  piVar7 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar4 = operator_new(0x14);
  pvStack_c = (void *)0x0;
  if (pvVar4 != (void *)0x0) {
    piVar7 = (int *)FUN_00648440();
  }
  puVar2 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar7 + 8))(puStack_4);
  uVar1 = *(undefined2 *)(puVar2 + 1);
  *puVar3 = *puVar2;
  puVar3[1] = CONCAT22((short)((uint)pvVar4 >> 0x10),uVar1);
  puVar3[2] = piVar7;
  iVar5 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  if (iVar5 != 0) {
    uVar6 = FUN_0044a580(auStack_112 + -10,s_File___s__Line___d_009cdd14,
                         s___Support_ItemUpgrade_Flyweight__009cdce4,0x38);
    FUN_00797b80(uVar6);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_00620100 @ 0x00620100 ====

void FUN_00620100(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009892f8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cddcc;
  pvVar2 = operator_new(0x1818);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00620220();
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
    uVar3 = FUN_006207c0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab2c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab2c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006201d0 @ 0x006201d0 ====

void FUN_006201d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cddc4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x18,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_006201f0 @ 0x006201f0 ====

void FUN_006201f0(byte param_1)

{
  void *in_ECX;
  
  FUN_006201d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00620220 @ 0x00620220 ====

void FUN_00620220(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989318;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cdddc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cddc4;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x18,0x100,(_func_void_void_ptr *)&LAB_00620210,FUN_006ef6d0);
  in_ECX[0x602] = 0;
  in_ECX[0x602] = in_ECX[0x602] + 0x100;
  in_ECX[0x605] = in_ECX + 2;
  in_ECX[0x603] = 0;
  in_ECX[0x604] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[5] = puVar1 + 8;
    puVar1[6] = 0;
    puVar1[7] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 6;
  } while (iVar2 != 0);
  in_ECX[0x5ff] = 0;
  in_ECX[0x600] = 0;
  in_ECX[0x601] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006202d0 @ 0x006202d0 ====

undefined4 FUN_006202d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x180c);
}


// ==== FUN_006202e0 @ 0x006202e0 ====

void FUN_006202e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00620300();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00620300 @ 0x00620300 ====

void FUN_00620300(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989343;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cdddc;
  local_4 = 1;
  if ((void *)in_ECX[0x604] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cddc4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x18,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cdd3c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x604]);
  return;
}


// ==== FUN_00620380 @ 0x00620380 ====

undefined4 * FUN_00620380(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[5] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cddf0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[5] = param_2[5] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x1814);
  *(int *)(in_ECX + 0x180c) = *(int *)(in_ECX + 0x180c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x18);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
      *(undefined2 *)(puVar2 + 1) = 0;
    }
    puVar2[4] = *(undefined4 *)(in_ECX + 0x1810);
    *(undefined4 **)(in_ECX + 0x1810) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1814) = puVar2[3];
  }
  puVar2[3] = 0;
  puVar2[5] = param_1;
  return puVar2;
}


// ==== FUN_00620450 @ 0x00620450 ====

undefined4 FUN_00620450(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x14) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cddf0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x14);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x14);
    }
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x1814);
    *(int *)(in_ECX + 0x180c) = *(int *)(in_ECX + 0x180c) + -1;
    *(int *)(in_ECX + 0x1814) = param_2;
  }
  return 0;
}


// ==== FUN_006204d0 @ 0x006204d0 ====

void FUN_006204d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061ff80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006204f0 @ 0x006204f0 ====

void FUN_006204f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cde70;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00620510 @ 0x00620510 ====

void FUN_00620510(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989363;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cde78;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cde70;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cddac;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_00620590 @ 0x00620590 ====

undefined4 FUN_00620590(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cddf0,0xa9);
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


// ==== FUN_00620610 @ 0x00620610 ====

undefined4 * FUN_00620610(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cddf0,0x85);
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


// ==== FUN_006206d0 @ 0x006206d0 ====

void FUN_006206d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006204f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006206f0 @ 0x006206f0 ====

void FUN_006206f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00620510();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00620710 @ 0x00620710 ====

void FUN_00620710(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989378;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cde78;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cde70;
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


// ==== FUN_006207c0 @ 0x006207c0 ====

void FUN_006207c0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989398;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cde94;
  FUN_00620710();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00620820 @ 0x00620820 ====

void FUN_00620820(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00620840(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00620840 @ 0x00620840 ====

void FUN_00620840(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00620840(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00620840(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00620880 @ 0x00620880 ====

undefined4 * FUN_00620880(void)

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
  iVar4 = FUN_00620930(iVar1,*puVar2);
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
        goto LAB_00620919;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
LAB_00620919:
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_00620930(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_00620930 @ 0x00620930 ====

undefined4 FUN_00620930(uint *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *param_1;
  uVar2 = *param_2;
  if ((uVar1 < uVar2) || ((uVar1 <= uVar2 && ((ushort)param_1[1] < (ushort)param_2[1])))) {
    return 0xffffffff;
  }
  if ((uVar2 < uVar1) || ((uVar2 <= uVar1 && ((ushort)param_2[1] < (ushort)param_1[1])))) {
    return 1;
  }
  return 0;
}


// ==== FUN_00620980 @ 0x00620980 ====

void FUN_00620980(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006209a0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006209a0 @ 0x006209a0 ====

void FUN_006209a0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_006209a0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_006209a0(param_1[3]);
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


// ==== FUN_00620a20 @ 0x00620a20 ====

int * FUN_00620a20(uint *param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  int *piVar5;
  
  piVar5 = *(int **)(in_ECX + 4);
  if (*(int **)(in_ECX + 4) == (int *)0x0) {
    return (int *)0x0;
  }
  do {
    piVar4 = piVar5;
    uVar1 = *(uint *)*piVar4;
    if ((*param_1 < uVar1) ||
       ((*param_1 <= uVar1 && ((ushort)param_1[1] < (ushort)((uint *)*piVar4)[1])))) {
      iVar3 = -1;
    }
    else {
      cVar2 = FUN_00620aa0(param_1);
      if (cVar2 == '\0') {
        FUN_0061f0e0(piVar4,*(undefined4 *)(in_ECX + 4));
        return piVar4;
      }
      iVar3 = 1;
    }
    if (iVar3 < 0) {
      piVar5 = (int *)piVar4[2];
    }
    else {
      piVar5 = (int *)piVar4[3];
    }
  } while (piVar5 != (int *)0x0);
  FUN_0061f0e0(piVar4,*(undefined4 *)(in_ECX + 4));
  return (int *)0x0;
}


// ==== FUN_00620aa0 @ 0x00620aa0 ====

int FUN_00620aa0(uint *param_1)

{
  uint uVar1;
  uint3 uVar2;
  uint *in_ECX;
  
  uVar1 = *in_ECX;
  uVar2 = (uint3)(uVar1 >> 8);
  if (uVar1 < *param_1) {
    return CONCAT31(uVar2,1);
  }
  if (*param_1 < uVar1) {
    return (uint)uVar2 << 8;
  }
  return CONCAT31((int3)(CONCAT22((short)(uVar1 >> 0x10),(ushort)in_ECX[1]) >> 8),
                  (ushort)in_ECX[1] < (ushort)param_1[1]);
}


// ==== FUN_00620ad0 @ 0x00620ad0 ====

void FUN_00620ad0(byte param_1)

{
  void *in_ECX;
  
  FUN_00620af0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00620af0 @ 0x00620af0 ====

void FUN_00620af0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009893c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cde94;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_006209a0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00620510();
  *in_ECX = &PTR_FUN_009cdd54;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00620b60 @ 0x00620b60 ====

void FUN_00620b60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdf30;
  return;
}


// ==== FUN_00620b70 @ 0x00620b70 ====

void FUN_00620b70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdf30;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00620b90 @ 0x00620b90 ====

void FUN_00620b90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdf44;
  return;
}


// ==== FUN_00620ba0 @ 0x00620ba0 ====

void FUN_00620ba0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdf5c;
  return;
}


// ==== FUN_00620bb0 @ 0x00620bb0 ====

void FUN_00620bb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdfb4;
  return;
}


// ==== FUN_00620bc0 @ 0x00620bc0 ====

void FUN_00620bc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdf44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00620be0 @ 0x00620be0 ====

void FUN_00620be0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdf5c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00620c00 @ 0x00620c00 ====

void FUN_00620c00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdfb4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00620c20 @ 0x00620c20 ====

undefined4 FUN_00620c20(undefined2 param_1)

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


// ==== FUN_00620c50 @ 0x00620c50 ====

undefined4 FUN_00620c50(undefined2 param_1)

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


// ==== FUN_00620c80 @ 0x00620c80 ====

void FUN_00620c80(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009893d8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cdfd4;
  DAT_00b5ab1c = 0;
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
  *in_ECX = &PTR_FUN_009cdf30;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00620d20 @ 0x00620d20 ====

void FUN_00620d20(void)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined4 unaff_retaddr;
  uint auStack_10c [2];
  undefined2 uStack_4;
  
  auStack_10c[1] = 0;
  auStack_10c[0] = 1;
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  *puVar1 = uStack_4;
  *(undefined4 *)(puVar1 + 2) = unaff_retaddr;
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar1);
  if (iVar2 != 0) {
    auStack_10c[0] = auStack_10c[0] & 0xffffff00;
    uVar3 = FUN_0044a580(auStack_10c,s_File___s__Line___d_009cdf18,
                         s___Support_LevelCap_Flyweight_Con_009cdeec,0x35);
    FUN_00797b80(uVar3);
    FUN_00797a40();
  }
  return;
}


// ==== FUN_00620d90 @ 0x00620d90 ====

void FUN_00620d90(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00989400;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cdfd4;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00620ea0();
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
    uVar3 = FUN_006212e0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab1c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab1c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00620e60 @ 0x00620e60 ====

void FUN_00620e60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdfcc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00620e80 @ 0x00620e80 ====

void FUN_00620e80(byte param_1)

{
  void *in_ECX;
  
  FUN_00620e60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00620ea0 @ 0x00620ea0 ====

void FUN_00620ea0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989418;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cdfe8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cdfcc;
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


// ==== FUN_00620f50 @ 0x00620f50 ====

void FUN_00620f50(byte param_1)

{
  void *in_ECX;
  
  FUN_00620f70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00620f70 @ 0x00620f70 ====

void FUN_00620f70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989443;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cdfe8;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cdfcc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cdf44;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_00620ff0 @ 0x00620ff0 ====

void FUN_00620ff0(byte param_1)

{
  void *in_ECX;
  
  FUN_00620c80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00621010 @ 0x00621010 ====

void FUN_00621010(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce000;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00621030 @ 0x00621030 ====

void FUN_00621030(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989463;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce008;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ce000;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cdfb4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_006210b0 @ 0x006210b0 ====

undefined4 FUN_006210b0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3930,0xa9);
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


// ==== FUN_00621130 @ 0x00621130 ====

undefined4 * FUN_00621130(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3930,0x85);
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


// ==== FUN_006211f0 @ 0x006211f0 ====

void FUN_006211f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00621010();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00621210 @ 0x00621210 ====

void FUN_00621210(byte param_1)

{
  void *in_ECX;
  
  FUN_00621030();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00621230 @ 0x00621230 ====

void FUN_00621230(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989478;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce008;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ce000;
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


// ==== FUN_006212e0 @ 0x006212e0 ====

void FUN_006212e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989498;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce024;
  FUN_00621230();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00621340 @ 0x00621340 ====

void FUN_00621340(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00621360(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00621360 @ 0x00621360 ====

void FUN_00621360(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00621360(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00621360(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_006213a0 @ 0x006213a0 ====

void FUN_006213a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006213c0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006213c0 @ 0x006213c0 ====

void FUN_006213c0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_006213c0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_006213c0(param_1[3]);
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


// ==== FUN_00621430 @ 0x00621430 ====

undefined4 * FUN_00621430(ushort *param_1)

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
    if (*param_1 < *(ushort *)*puVar3) {
      iVar2 = -1;
    }
    else {
      if (*param_1 <= *(ushort *)*puVar3) {
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


// ==== FUN_006214a0 @ 0x006214a0 ====

void FUN_006214a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006214c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006214c0 @ 0x006214c0 ====

void FUN_006214c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009894c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce024;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_006213c0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00621030();
  *in_ECX = &PTR_FUN_009cdf5c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00621530 @ 0x00621530 ====

void FUN_00621530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce0c0;
  return;
}


// ==== FUN_00621540 @ 0x00621540 ====

void FUN_00621540(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce0c0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00621560 @ 0x00621560 ====

void FUN_00621560(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce0d0;
  return;
}


// ==== FUN_00621570 @ 0x00621570 ====

void FUN_00621570(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce0ec;
  return;
}


// ==== FUN_00621580 @ 0x00621580 ====

void FUN_00621580(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce144;
  return;
}


// ==== FUN_00621590 @ 0x00621590 ====

void FUN_00621590(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce0d0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006215b0 @ 0x006215b0 ====

void FUN_006215b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce0ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006215d0 @ 0x006215d0 ====

void FUN_006215d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce144;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006215f0 @ 0x006215f0 ====

undefined4 FUN_006215f0(undefined2 param_1)

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


// ==== FUN_00621620 @ 0x00621620 ====

void FUN_00621620(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009894d8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ce164;
  DAT_00b5ab34 = 0;
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
  *in_ECX = &PTR_FUN_009ce0c0;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006216c0 @ 0x006216c0 ====

void FUN_006216c0(void)

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
  puStack_8 = &LAB_009894f0;
  pvStack_c = ExceptionList;
  piVar6 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar3 = operator_new(0x114);
  pvStack_c = (void *)0x0;
  if (pvVar3 != (void *)0x0) {
    piVar6 = (int *)FUN_006484b0();
  }
  puVar1 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar6 + 8))(puStack_4);
  *puVar2 = *puVar1;
  *(int **)(puVar2 + 2) = piVar6;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009ce0a8,
                         s___Support_Location_Flyweight_Con_009ce07c,0x38);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_00621790 @ 0x00621790 ====

void FUN_00621790(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00989518;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce164;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_006218a0();
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
    uVar3 = FUN_00621e10(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab34 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab34 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00621860 @ 0x00621860 ====

void FUN_00621860(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce15c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00621880 @ 0x00621880 ====

void FUN_00621880(byte param_1)

{
  void *in_ECX;
  
  FUN_00621860();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006218a0 @ 0x006218a0 ====

void FUN_006218a0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989538;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce174;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ce15c;
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


// ==== FUN_00621950 @ 0x00621950 ====

undefined4 FUN_00621950(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce188,0xa9);
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


// ==== FUN_006219d0 @ 0x006219d0 ====

void FUN_006219d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006219f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006219f0 @ 0x006219f0 ====

void FUN_006219f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989563;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce174;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ce15c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009ce0d0;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_00621a70 @ 0x00621a70 ====

void * FUN_00621a70(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce188,0x85);
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


// ==== FUN_00621b20 @ 0x00621b20 ====

void FUN_00621b20(byte param_1)

{
  void *in_ECX;
  
  FUN_00621620();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00621b40 @ 0x00621b40 ====

void FUN_00621b40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce204;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00621b60 @ 0x00621b60 ====

void FUN_00621b60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989583;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce20c;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ce204;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009ce144;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_00621be0 @ 0x00621be0 ====

undefined4 FUN_00621be0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce188,0xa9);
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


// ==== FUN_00621c60 @ 0x00621c60 ====

undefined4 * FUN_00621c60(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce188,0x85);
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


// ==== FUN_00621d20 @ 0x00621d20 ====

void FUN_00621d20(byte param_1)

{
  void *in_ECX;
  
  FUN_00621b40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00621d40 @ 0x00621d40 ====

void FUN_00621d40(byte param_1)

{
  void *in_ECX;
  
  FUN_00621b60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00621d60 @ 0x00621d60 ====

void FUN_00621d60(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989598;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce20c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ce204;
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


// ==== FUN_00621e10 @ 0x00621e10 ====

void FUN_00621e10(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009895b8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce224;
  FUN_00621d60();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00621e70 @ 0x00621e70 ====

void FUN_00621e70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00621e90(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00621e90 @ 0x00621e90 ====

void FUN_00621e90(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00621e90(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00621e90(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00621ed0 @ 0x00621ed0 ====

void FUN_00621ed0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00621ef0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00621ef0 @ 0x00621ef0 ====

void FUN_00621ef0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00621ef0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00621ef0(param_1[3]);
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


// ==== FUN_00621f60 @ 0x00621f60 ====

void FUN_00621f60(byte param_1)

{
  void *in_ECX;
  
  FUN_00621f80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00621f80 @ 0x00621f80 ====

void FUN_00621f80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009895e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce224;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00621ef0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00621b60();
  *in_ECX = &PTR_FUN_009ce0ec;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00621ff0 @ 0x00621ff0 ====

void FUN_00621ff0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce2a8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622010 @ 0x00622010 ====

int FUN_00622010(ushort *param_1)

{
  undefined4 in_EAX;
  
  return CONCAT22((short)((uint)in_EAX >> 0x10),param_1[1] >> 0xb) * 0x20 +
         CONCAT22((short)((uint)param_1 >> 0x10),*param_1 >> 0xb);
}


// ==== FUN_00622030 @ 0x00622030 ====

void FUN_00622030(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce2bc;
  *(undefined2 *)(in_ECX + 1) = 0x333;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5af40 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5af40 = in_ECX;
  return;
}


// ==== FUN_00622060 @ 0x00622060 ====

void FUN_00622060(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5af40 = 0;
  *in_ECX = &PTR_FUN_009ce2a8;
  return;
}


// ==== FUN_00622080 @ 0x00622080 ====

/* WARNING: Removing unreachable block (ram,0x006220c1) */

void FUN_00622080(uint *param_1,uint param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  uint local_108;
  undefined4 local_104;
  undefined1 local_100 [256];
  
  if (0x3ff < (ushort)param_2) {
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_Sector_Overflow___Secter_Index___009ce27c,param_2 & 0xffff);
    FUN_00797b80(uVar2);
    param_2 = 0x3ff;
  }
  uVar1 = (ushort)(param_2 >> 5);
  local_108 = CONCAT22(uVar1,(ushort)param_2) & 0x7ff001f;
  local_104 = CONCAT22((uVar1 & 0x7ff) + 1,((ushort)param_2 & 0x1f) + 1);
  *param_1 = local_108;
  param_1[1] = local_104;
  return;
}


// ==== FUN_00622100 @ 0x00622100 ====

void FUN_00622100(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_00622080(&local_8,param_2);
  local_8 = CONCAT22(local_8._2_2_ << 0xb,(short)local_8 << 0xb);
  local_4 = CONCAT22(local_4._2_2_ << 0xb,(short)local_4 << 0xb);
  *param_1 = local_8;
  param_1[1] = local_4;
  return;
}


// ==== FUN_00622140 @ 0x00622140 ====

int FUN_00622140(undefined4 param_1)

{
  ushort uVar1;
  undefined2 extraout_var;
  uint3 uVar2;
  int *in_ECX;
  ushort uVar3;
  ushort uVar4;
  undefined4 unaff_EBX;
  ushort uVar5;
  undefined4 unaff_EBP;
  ushort uVar6;
  ushort *unaff_retaddr;
  short local_10 [4];
  undefined1 local_8 [8];
  
  FUN_00622080(local_8,param_1);
  (**(code **)(*in_ECX + 8))(local_10,param_1);
  uVar5 = (ushort)unaff_EBP;
  uVar1 = *unaff_retaddr >> 0xb;
  if (local_10[0] != 0) {
    uVar5 = uVar5 - (short)in_ECX[1];
  }
  uVar4 = (ushort)unaff_EBX;
  if (uVar4 < 0x1f) {
    uVar4 = uVar4 + (short)in_ECX[1];
  }
  uVar6 = (ushort)((uint)unaff_EBP >> 0x10);
  if (uVar6 != 0) {
    uVar6 = uVar6 - (short)in_ECX[1];
  }
  uVar3 = (ushort)((uint)unaff_EBX >> 0x10);
  if (uVar3 < 0x1f) {
    uVar3 = uVar3 + (short)in_ECX[1];
  }
  uVar2 = (uint3)(CONCAT22(extraout_var,uVar1) >> 8);
  if ((((uVar1 < uVar5) || (uVar4 < uVar1)) || (unaff_retaddr[1] >> 0xb < uVar6)) ||
     (uVar3 < unaff_retaddr[1] >> 0xb)) {
    return CONCAT31(uVar2,1);
  }
  return (uint)uVar2 << 8;
}


// ==== FUN_006221f0 @ 0x006221f0 ====

void FUN_006221f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00622060();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622210 @ 0x00622210 ====

void FUN_00622210(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce318;
  return;
}


// ==== FUN_00622220 @ 0x00622220 ====

void FUN_00622220(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce318;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622240 @ 0x00622240 ====

void FUN_00622240(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce328;
  return;
}


// ==== FUN_00622250 @ 0x00622250 ====

void FUN_00622250(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce344;
  return;
}


// ==== FUN_00622260 @ 0x00622260 ====

void FUN_00622260(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce39c;
  return;
}


// ==== FUN_00622270 @ 0x00622270 ====

void FUN_00622270(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce328;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622290 @ 0x00622290 ====

void FUN_00622290(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce344;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006222b0 @ 0x006222b0 ====

void FUN_006222b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce39c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006222d0 @ 0x006222d0 ====

undefined4 FUN_006222d0(undefined2 param_1)

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


// ==== FUN_00622300 @ 0x00622300 ====

void FUN_00622300(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009895f8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ce3bc;
  DAT_00b5ab30 = 0;
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
  *in_ECX = &PTR_FUN_009ce318;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006223a0 @ 0x006223a0 ====

void FUN_006223a0(void)

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
  puStack_8 = &LAB_00989610;
  pvStack_c = ExceptionList;
  piVar6 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar3 = operator_new(0xc);
  pvStack_c = (void *)0x0;
  if (pvVar3 != (void *)0x0) {
    piVar6 = (int *)FUN_006485e0();
  }
  puVar1 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar6 + 8))(puStack_4);
  *puVar2 = *puVar1;
  *(int **)(puVar2 + 2) = piVar6;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009ce300,
                         s___Support_startpoint_flyweight_C_009ce2d0,0x38);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_00622470 @ 0x00622470 ====

void FUN_00622470(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00989638;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce3bc;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00622580();
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
    uVar3 = FUN_00622af0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab30 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab30 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00622540 @ 0x00622540 ====

void FUN_00622540(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce3b4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00622560 @ 0x00622560 ====

void FUN_00622560(byte param_1)

{
  void *in_ECX;
  
  FUN_00622540();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622580 @ 0x00622580 ====

void FUN_00622580(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989658;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce3cc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ce3b4;
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


// ==== FUN_00622630 @ 0x00622630 ====

void FUN_00622630(byte param_1)

{
  void *in_ECX;
  
  FUN_00622650();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622650 @ 0x00622650 ====

void FUN_00622650(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989683;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce3cc;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ce3b4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009ce328;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_006226d0 @ 0x006226d0 ====

void * FUN_006226d0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce3e0,0x85);
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


// ==== FUN_00622780 @ 0x00622780 ====

undefined4 FUN_00622780(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce3e0,0xa9);
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


// ==== FUN_00622800 @ 0x00622800 ====

void FUN_00622800(byte param_1)

{
  void *in_ECX;
  
  FUN_00622300();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622820 @ 0x00622820 ====

void FUN_00622820(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce460;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00622840 @ 0x00622840 ====

void FUN_00622840(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009896a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce468;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ce460;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009ce39c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_006228c0 @ 0x006228c0 ====

undefined4 FUN_006228c0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce3e0,0xa9);
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


// ==== FUN_00622940 @ 0x00622940 ====

undefined4 * FUN_00622940(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce3e0,0x85);
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


// ==== FUN_00622a00 @ 0x00622a00 ====

void FUN_00622a00(byte param_1)

{
  void *in_ECX;
  
  FUN_00622820();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622a20 @ 0x00622a20 ====

void FUN_00622a20(byte param_1)

{
  void *in_ECX;
  
  FUN_00622840();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622a40 @ 0x00622a40 ====

void FUN_00622a40(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009896b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce468;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ce460;
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


// ==== FUN_00622af0 @ 0x00622af0 ====

void FUN_00622af0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009896d8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce484;
  FUN_00622a40();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00622b50 @ 0x00622b50 ====

void FUN_00622b50(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00622b70(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00622b70 @ 0x00622b70 ====

void FUN_00622b70(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00622b70(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00622b70(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00622bb0 @ 0x00622bb0 ====

void FUN_00622bb0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00622bd0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00622bd0 @ 0x00622bd0 ====

void FUN_00622bd0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00622bd0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00622bd0(param_1[3]);
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


// ==== FUN_00622c40 @ 0x00622c40 ====

void FUN_00622c40(byte param_1)

{
  void *in_ECX;
  
  FUN_00622c60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622c60 @ 0x00622c60 ====

void FUN_00622c60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00989703;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce484;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00622bd0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00622840();
  *in_ECX = &PTR_FUN_009ce344;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00622cd0 @ 0x00622cd0 ====

void FUN_00622cd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce4dc;
  return;
}


// ==== FUN_00622ce0 @ 0x00622ce0 ====

void FUN_00622ce0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce4dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622d00 @ 0x00622d00 ====

void FUN_00622d00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce4ec;
  return;
}


// ==== FUN_00622d10 @ 0x00622d10 ====

void FUN_00622d10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce504;
  return;
}


// ==== FUN_00622d20 @ 0x00622d20 ====

void FUN_00622d20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce55c;
  return;
}


// ==== FUN_00622d30 @ 0x00622d30 ====

void FUN_00622d30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce4ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622d50 @ 0x00622d50 ====

void FUN_00622d50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce504;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622d70 @ 0x00622d70 ====

void FUN_00622d70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce55c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00622d90 @ 0x00622d90 ====

undefined4 FUN_00622d90(undefined4 param_1)

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


// ==== FUN_00622dc0 @ 0x00622dc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00622dc0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989718;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ce57c;
  _DAT_00b5b09c = 0;
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
  *in_ECX = &PTR_FUN_009ce4dc;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00622e60 @ 0x00622e60 ====

void FUN_00622e60(undefined4 *param_1)

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
  puStack_8 = &LAB_0098972d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x408);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00648650();
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


// ==== FUN_00622ef0 @ 0x00622ef0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00622ef0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00989755;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce57c;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00623000();
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
    uVar3 = FUN_006235b0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    _DAT_00b5b09c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  _DAT_00b5b09c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00622fc0 @ 0x00622fc0 ====

void FUN_00622fc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce574;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00622fe0 @ 0x00622fe0 ====

void FUN_00622fe0(byte param_1)

{
  void *in_ECX;
  
  FUN_00622fc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00623000 @ 0x00623000 ====

void FUN_00623000(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989768;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce58c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ce574;
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


// ==== FUN_006230b0 @ 0x006230b0 ====

undefined4 FUN_006230b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0c);
}


// ==== FUN_006230c0 @ 0x006230c0 ====

void FUN_006230c0(byte param_1)

{
  void *in_ECX;
  
  FUN_006230e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006230e0 @ 0x006230e0 ====

void FUN_006230e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989793;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce58c;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ce574;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009ce4ec;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_00623160 @ 0x00623160 ====

void * FUN_00623160(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009897ab;
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
                           s_d__usa_24_0_1_2__develop_share_l_009ce5a0,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00623240 @ 0x00623240 ====

undefined4 FUN_00623240(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce5a0,0xa9);
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


// ==== FUN_006232c0 @ 0x006232c0 ====

void FUN_006232c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00622dc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006232e0 @ 0x006232e0 ====

void FUN_006232e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce61c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_00623300 @ 0x00623300 ====

void FUN_00623300(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009897d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce624;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ce61c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009ce55c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_00623380 @ 0x00623380 ====

undefined4 FUN_00623380(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce5a0,0xa9);
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


// ==== FUN_00623400 @ 0x00623400 ====

undefined4 * FUN_00623400(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce5a0,0x85);
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


// ==== FUN_006234c0 @ 0x006234c0 ====

void FUN_006234c0(byte param_1)

{
  void *in_ECX;
  
  FUN_006232e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006234e0 @ 0x006234e0 ====

void FUN_006234e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00623300();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00623500 @ 0x00623500 ====

void FUN_00623500(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009897e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce624;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ce61c;
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


// ==== FUN_006235b0 @ 0x006235b0 ====

void FUN_006235b0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989808;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce63c;
  FUN_00623500();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00623610 @ 0x00623610 ====

void FUN_00623610(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00623630(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00623630 @ 0x00623630 ====

void FUN_00623630(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00623630(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00623630(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00623670 @ 0x00623670 ====

undefined4 * FUN_00623670(void)

{
  undefined4 *puVar1;
  int in_ECX;
  uint *unaff_EBX;
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
    while (*unaff_EBX < *(uint *)*puVar2) {
      if ((undefined4 *)puVar2[2] == (undefined4 *)0x0) {
        puVar1[4] = puVar2;
        puVar2[2] = puVar1;
        FUN_0061f0e0(puVar1,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
      puVar2 = (undefined4 *)puVar2[2];
    }
    if (*unaff_EBX <= *(uint *)*puVar2) break;
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


// ==== FUN_00623720 @ 0x00623720 ====

void FUN_00623720(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00623740(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00623740 @ 0x00623740 ====

void FUN_00623740(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00623740(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00623740(param_1[3]);
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


// ==== FUN_006237b0 @ 0x006237b0 ====

void FUN_006237b0(byte param_1)

{
  void *in_ECX;
  
  FUN_006237d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006237d0 @ 0x006237d0 ====

void FUN_006237d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00989833;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce63c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00623740(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00623300();
  *in_ECX = &PTR_FUN_009ce504;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00623840 @ 0x00623840 ====

void FUN_00623840(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce6d8;
  return;
}


// ==== FUN_00623850 @ 0x00623850 ====

void FUN_00623850(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce6d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00623870 @ 0x00623870 ====

void FUN_00623870(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce6e8;
  return;
}


// ==== FUN_00623880 @ 0x00623880 ====

void FUN_00623880(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce704;
  return;
}


// ==== FUN_00623890 @ 0x00623890 ====

void FUN_00623890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce75c;
  return;
}


// ==== FUN_006238a0 @ 0x006238a0 ====

void FUN_006238a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce6e8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006238c0 @ 0x006238c0 ====

void FUN_006238c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce704;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006238e0 @ 0x006238e0 ====

void FUN_006238e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce75c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00623900 @ 0x00623900 ====

undefined4 FUN_00623900(undefined2 param_1)

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


// ==== FUN_00623930 @ 0x00623930 ====

void FUN_00623930(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989848;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ce77c;
  DAT_00b5ab38 = 0;
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
  *in_ECX = &PTR_FUN_009ce6d8;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006239d0 @ 0x006239d0 ====

void FUN_006239d0(void)

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
  puStack_8 = &LAB_00989860;
  pvStack_c = ExceptionList;
  piVar6 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar3 = operator_new(0xa4);
  pvStack_c = (void *)0x0;
  if (pvVar3 != (void *)0x0) {
    piVar6 = (int *)FUN_00648720();
  }
  puVar1 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar6 + 8))(puStack_4);
  *puVar2 = *puVar1;
  *(int **)(puVar2 + 2) = piVar6;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009ce6c0,
                         s___Support_Teleport_Flyweight_Con_009ce694,0x38);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_00623aa0 @ 0x00623aa0 ====

void FUN_00623aa0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00989888;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce77c;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00623bb0();
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
    uVar3 = FUN_00624120(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab38 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab38 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00623b70 @ 0x00623b70 ====

void FUN_00623b70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce774;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00623b90 @ 0x00623b90 ====

void FUN_00623b90(byte param_1)

{
  void *in_ECX;
  
  FUN_00623b70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00623bb0 @ 0x00623bb0 ====

void FUN_00623bb0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009898a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce78c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ce774;
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


// ==== FUN_00623c60 @ 0x00623c60 ====

void FUN_00623c60(byte param_1)

{
  void *in_ECX;
  
  FUN_00623c80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00623c80 @ 0x00623c80 ====

void FUN_00623c80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009898d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce78c;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ce774;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009ce6e8;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_00623d00 @ 0x00623d00 ====

void * FUN_00623d00(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce7a0,0x85);
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


// ==== FUN_00623db0 @ 0x00623db0 ====

undefined4 FUN_00623db0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce7a0,0xa9);
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


// ==== FUN_00623e30 @ 0x00623e30 ====

void FUN_00623e30(byte param_1)

{
  void *in_ECX;
  
  FUN_00623930();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00623e50 @ 0x00623e50 ====

void FUN_00623e50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce81c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00623e70 @ 0x00623e70 ====

void FUN_00623e70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009898f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce824;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ce81c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009ce75c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_00623ef0 @ 0x00623ef0 ====

undefined4 FUN_00623ef0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce7a0,0xa9);
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


// ==== FUN_00623f70 @ 0x00623f70 ====

undefined4 * FUN_00623f70(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce7a0,0x85);
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


// ==== FUN_00624030 @ 0x00624030 ====

void FUN_00624030(byte param_1)

{
  void *in_ECX;
  
  FUN_00623e50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00624050 @ 0x00624050 ====

void FUN_00624050(byte param_1)

{
  void *in_ECX;
  
  FUN_00623e70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00624070 @ 0x00624070 ====

void FUN_00624070(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989908;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce824;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ce81c;
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


// ==== FUN_00624120 @ 0x00624120 ====

void FUN_00624120(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989928;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce83c;
  FUN_00624070();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00624180 @ 0x00624180 ====

void FUN_00624180(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006241a0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006241a0 @ 0x006241a0 ====

void FUN_006241a0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_006241a0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_006241a0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_006241e0 @ 0x006241e0 ====

void FUN_006241e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00624200(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00624200 @ 0x00624200 ====

void FUN_00624200(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00624200(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00624200(param_1[3]);
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


// ==== FUN_00624270 @ 0x00624270 ====

void FUN_00624270(byte param_1)

{
  void *in_ECX;
  
  FUN_00624290();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00624290 @ 0x00624290 ====

void FUN_00624290(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00989953;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce83c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00624200(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00623e70();
  *in_ECX = &PTR_FUN_009ce704;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00624300 @ 0x00624300 ====

void FUN_00624300(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce894;
  return;
}


// ==== FUN_00624310 @ 0x00624310 ====

void FUN_00624310(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce894;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00624330 @ 0x00624330 ====

void FUN_00624330(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce8a4;
  return;
}


// ==== FUN_00624340 @ 0x00624340 ====

void FUN_00624340(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce8bc;
  return;
}


// ==== FUN_00624350 @ 0x00624350 ====

void FUN_00624350(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce914;
  return;
}


// ==== FUN_00624360 @ 0x00624360 ====

void FUN_00624360(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce8a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00624380 @ 0x00624380 ====

void FUN_00624380(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce8bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006243a0 @ 0x006243a0 ====

void FUN_006243a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce914;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006243c0 @ 0x006243c0 ====

undefined4 FUN_006243c0(undefined2 *param_1)

{
  int *piVar1;
  int in_ECX;
  undefined2 local_8;
  undefined1 local_6;
  
  local_8 = *param_1;
  local_6 = *(undefined1 *)(param_1 + 1);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(&local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_00624400 @ 0x00624400 ====

void FUN_00624400(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989968;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ce934;
  DAT_00b5ab44 = 0;
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
  *in_ECX = &PTR_FUN_009ce894;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006244a0 @ 0x006244a0 ====

void FUN_006244a0(undefined2 *param_1)

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
  puStack_8 = &LAB_0098997d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0xc);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00648910();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 8))(param_1);
  puVar3 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = *param_1;
  *(undefined1 *)(puVar3 + 1) = *(undefined1 *)(param_1 + 1);
  *(int **)(puVar3 + 2) = piVar2;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  ExceptionList = unaff_EDI;
  return;
}


// ==== FUN_00624530 @ 0x00624530 ====

void FUN_00624530(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009899a5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce934;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00624640();
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
    uVar3 = FUN_00624be0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab44 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab44 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00624600 @ 0x00624600 ====

void FUN_00624600(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce92c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00624620 @ 0x00624620 ====

void FUN_00624620(byte param_1)

{
  void *in_ECX;
  
  FUN_00624600();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00624640 @ 0x00624640 ====

void FUN_00624640(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009899b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce944;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ce92c;
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


// ==== FUN_006246f0 @ 0x006246f0 ====

void FUN_006246f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00624710();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00624710 @ 0x00624710 ====

void FUN_00624710(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009899e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce944;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ce92c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009ce8a4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_00624790 @ 0x00624790 ====

void * FUN_00624790(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009899fb;
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
                           s_d__usa_24_0_1_2__develop_share_l_009ce958,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00624870 @ 0x00624870 ====

undefined4 FUN_00624870(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce958,0xa9);
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


// ==== FUN_006248f0 @ 0x006248f0 ====

void FUN_006248f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00624400();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00624910 @ 0x00624910 ====

void FUN_00624910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ce9d4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_00624930 @ 0x00624930 ====

void FUN_00624930(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989a23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce9dc;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ce9d4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009ce914;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_006249b0 @ 0x006249b0 ====

undefined4 FUN_006249b0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce958,0xa9);
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


// ==== FUN_00624a30 @ 0x00624a30 ====

undefined4 * FUN_00624a30(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ce958,0x85);
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


// ==== FUN_00624af0 @ 0x00624af0 ====

void FUN_00624af0(byte param_1)

{
  void *in_ECX;
  
  FUN_00624910();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00624b10 @ 0x00624b10 ====

void FUN_00624b10(byte param_1)

{
  void *in_ECX;
  
  FUN_00624930();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00624b30 @ 0x00624b30 ====

void FUN_00624b30(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989a38;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce9dc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ce9d4;
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


// ==== FUN_00624be0 @ 0x00624be0 ====

void FUN_00624be0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989a58;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce9f4;
  FUN_00624b30();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00624c40 @ 0x00624c40 ====

void FUN_00624c40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00624c60(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00624c60 @ 0x00624c60 ====

void FUN_00624c60(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00624c60(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00624c60(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00624ca0 @ 0x00624ca0 ====

undefined4 * FUN_00624ca0(void)

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
  iVar4 = FUN_00624d50(iVar1,*puVar2);
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
        goto LAB_00624d39;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
LAB_00624d39:
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_00624d50(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_00624d50 @ 0x00624d50 ====

uint FUN_00624d50(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = FUN_00624d90(param_2);
  if (cVar1 == '\0') {
    cVar1 = FUN_00624d90(param_1);
    return (uint)(cVar1 != '\0');
  }
  return 0xffffffff;
}


// ==== FUN_00624d90 @ 0x00624d90 ====

undefined4 FUN_00624d90(byte *param_1)

{
  byte *in_ECX;
  
  if (((*in_ECX < *param_1) || (in_ECX[1] < param_1[1])) || (in_ECX[2] < param_1[2])) {
    return 1;
  }
  return 0;
}


// ==== FUN_00624dc0 @ 0x00624dc0 ====

void FUN_00624dc0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00624de0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00624de0 @ 0x00624de0 ====

void FUN_00624de0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00624de0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00624de0(param_1[3]);
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


// ==== FUN_00624e50 @ 0x00624e50 ====

undefined4 * FUN_00624e50(byte *param_1)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = *(undefined4 **)(in_ECX + 4);
  if (*(undefined4 **)(in_ECX + 4) == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  do {
    puVar4 = puVar5;
    pbVar1 = (byte *)*puVar4;
    if (((*param_1 < *pbVar1) || (param_1[1] < pbVar1[1])) || (param_1[2] < pbVar1[2])) {
      iVar3 = -1;
    }
    else {
      cVar2 = FUN_00624ed0(param_1);
      if (cVar2 == '\0') {
        FUN_0061f0e0(puVar4,*(undefined4 *)(in_ECX + 4));
        return puVar4;
      }
      iVar3 = 1;
    }
    if (iVar3 < 0) {
      puVar5 = (undefined4 *)puVar4[2];
    }
    else {
      puVar5 = (undefined4 *)puVar4[3];
    }
  } while (puVar5 != (undefined4 *)0x0);
  FUN_0061f0e0(puVar4,*(undefined4 *)(in_ECX + 4));
  return (undefined4 *)0x0;
}


// ==== FUN_00624ed0 @ 0x00624ed0 ====

bool FUN_00624ed0(byte *param_1)

{
  byte *in_ECX;
  
  if ((*in_ECX < *param_1) || (in_ECX[1] < param_1[1])) {
    return true;
  }
  return in_ECX[2] < param_1[2];
}


// ==== FUN_00624f10 @ 0x00624f10 ====

void FUN_00624f10(byte param_1)

{
  void *in_ECX;
  
  FUN_00624f30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00624f30 @ 0x00624f30 ====

void FUN_00624f30(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00989a83;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ce9f4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00624de0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00624930();
  *in_ECX = &PTR_FUN_009ce8bc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00624fa0 @ 0x00624fa0 ====

void FUN_00624fa0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cea4c;
  return;
}


// ==== FUN_00624fb0 @ 0x00624fb0 ====

void FUN_00624fb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cea4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00624fd0 @ 0x00624fd0 ====

void FUN_00624fd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cea5c;
  return;
}


// ==== FUN_00624fe0 @ 0x00624fe0 ====

void FUN_00624fe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cea74;
  return;
}


// ==== FUN_00624ff0 @ 0x00624ff0 ====

void FUN_00624ff0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ceacc;
  return;
}


// ==== FUN_00625000 @ 0x00625000 ====

void FUN_00625000(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cea5c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00625020 @ 0x00625020 ====

void FUN_00625020(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cea74;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00625040 @ 0x00625040 ====

void FUN_00625040(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ceacc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00625060 @ 0x00625060 ====

undefined4 FUN_00625060(undefined4 param_1)

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


// ==== FUN_00625090 @ 0x00625090 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00625090(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989a98;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ceaec;
  _DAT_00b5ab3c = 0;
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
  *in_ECX = &PTR_FUN_009cea4c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00625130 @ 0x00625130 ====

void FUN_00625130(byte *param_1)

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
  puStack_8 = &LAB_00989aad;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x14);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_006489a0();
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


// ==== FUN_006251c0 @ 0x006251c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006251c0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00989ad5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ceaec;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_006252d0();
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
    uVar3 = FUN_00625890(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    _DAT_00b5ab3c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  _DAT_00b5ab3c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00625290 @ 0x00625290 ====

void FUN_00625290(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ceae4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_006252b0 @ 0x006252b0 ====

void FUN_006252b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00625290();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006252d0 @ 0x006252d0 ====

void FUN_006252d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989ae8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ceafc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ceae4;
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


// ==== FUN_00625380 @ 0x00625380 ====

undefined4 FUN_00625380(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x140c);
}


// ==== FUN_00625390 @ 0x00625390 ====

void FUN_00625390(byte param_1)

{
  void *in_ECX;
  
  FUN_006253b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006253b0 @ 0x006253b0 ====

void FUN_006253b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989b13;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ceafc;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ceae4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cea5c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_00625430 @ 0x00625430 ====

void * FUN_00625430(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00989b2b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009ceb10,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00625510 @ 0x00625510 ====

undefined4 FUN_00625510(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ceb10,0xa9);
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


// ==== FUN_00625590 @ 0x00625590 ====

void FUN_00625590(byte param_1)

{
  void *in_ECX;
  
  FUN_00625090();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006255b0 @ 0x006255b0 ====

void FUN_006255b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ceb90;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_006255d0 @ 0x006255d0 ====

void FUN_006255d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989b53;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ceb98;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ceb90;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009ceacc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_00625650 @ 0x00625650 ====

undefined4 FUN_00625650(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x200c);
}


// ==== FUN_00625660 @ 0x00625660 ====

undefined4 FUN_00625660(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ceb10,0xa9);
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


// ==== FUN_006256e0 @ 0x006256e0 ====

undefined4 * FUN_006256e0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ceb10,0x85);
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


// ==== FUN_006257a0 @ 0x006257a0 ====

void FUN_006257a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006255b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006257c0 @ 0x006257c0 ====

void FUN_006257c0(byte param_1)

{
  void *in_ECX;
  
  FUN_006255d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006257e0 @ 0x006257e0 ====

void FUN_006257e0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989b68;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ceb98;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ceb90;
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


// ==== FUN_00625890 @ 0x00625890 ====

void FUN_00625890(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989b88;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cebb4;
  FUN_006257e0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006258f0 @ 0x006258f0 ====

void FUN_006258f0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00625910(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00625910 @ 0x00625910 ====

void FUN_00625910(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00625910(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00625910(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00625950 @ 0x00625950 ====

void FUN_00625950(void *param_1)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,param_1);
    return;
  }
  if (param_1 == (void *)0x0) {
    return;
  }
  _free(param_1);
  return;
}


// ==== FUN_00625980 @ 0x00625980 ====

void FUN_00625980(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_006259a0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_006259a0 @ 0x006259a0 ====

void FUN_006259a0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_006259a0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_006259a0(param_1[3]);
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


// ==== FUN_00625a10 @ 0x00625a10 ====

undefined4 * FUN_00625a10(uint *param_1)

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
    if (*param_1 < *(uint *)*puVar3) {
      iVar2 = -1;
    }
    else {
      if (*param_1 <= *(uint *)*puVar3) {
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


// ==== FUN_00625a80 @ 0x00625a80 ====

void FUN_00625a80(byte param_1)

{
  void *in_ECX;
  
  FUN_00625aa0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00625aa0 @ 0x00625aa0 ====

void FUN_00625aa0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00989bb3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cebb4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_006259a0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_006255d0();
  *in_ECX = &PTR_FUN_009cea74;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00625b10 @ 0x00625b10 ====

void FUN_00625b10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cec0c;
  return;
}


// ==== FUN_00625b20 @ 0x00625b20 ====

void FUN_00625b20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cec0c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00625b40 @ 0x00625b40 ====

void FUN_00625b40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cec2c;
  return;
}


// ==== FUN_00625b50 @ 0x00625b50 ====

void FUN_00625b50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cec44;
  return;
}


// ==== FUN_00625b60 @ 0x00625b60 ====

void FUN_00625b60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cec5c;
  return;
}


// ==== FUN_00625b70 @ 0x00625b70 ====

void FUN_00625b70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cec2c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00625b90 @ 0x00625b90 ====

void FUN_00625b90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cec44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00625bb0 @ 0x00625bb0 ====

void FUN_00625bb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cec5c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00625be0 @ 0x00625be0 ====

void FUN_00625be0(void)

{
  FUN_00648ad0();
  return;
}


// ==== FUN_00625c00 @ 0x00625c00 ====

void FUN_00625c00(void)

{
  FUN_00648bf0();
  return;
}


// ==== FUN_00625c20 @ 0x00625c20 ====

void FUN_00625c20(void)

{
  FUN_00648d70();
  return;
}


// ==== FUN_00625c30 @ 0x00625c30 ====

void FUN_00625c30(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00803725(param_1,0,&Framework::Support::ITarget::RTTI_Type_Descriptor,
                       &Framework::Support::Target::None::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,iVar1);
    return;
  }
  iVar1 = FUN_00803725(param_1,0,&Framework::Support::ITarget::RTTI_Type_Descriptor,
                       &Framework::Support::Target::Position::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0xc))(1,iVar1);
    return;
  }
  iVar1 = FUN_00803725(param_1,0,&Framework::Support::ITarget::RTTI_Type_Descriptor,
                       &Framework::Support::Target::Creature::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))(1,iVar1);
  }
  return;
}


// ==== FUN_00625cc0 @ 0x00625cc0 ====

void FUN_00625cc0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00803725(param_1,0,&Framework::Support::ITarget::RTTI_Type_Descriptor,
                       &Framework::Support::Target::None::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,iVar1);
    return;
  }
  iVar1 = FUN_00803725(param_1,0,&Framework::Support::ITarget::RTTI_Type_Descriptor,
                       &Framework::Support::Target::Position::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,iVar1);
    return;
  }
  iVar1 = FUN_00803725(param_1,0,&Framework::Support::ITarget::RTTI_Type_Descriptor,
                       &Framework::Support::Target::Creature::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,iVar1);
  }
  return;
}


// ==== FUN_00625d50 @ 0x00625d50 ====

void FUN_00625d50(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00989ca9;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cecd4;
  pvVar1 = operator_new(0x30);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00625fd0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x30);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00626070();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x30);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00626110();
  }
  in_ECX[3] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a77c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a77c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00625e30 @ 0x00625e30 ====

void FUN_00625e30(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989cbb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cecd4;
  DAT_00b5a77c = 0;
  local_4 = 0;
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
  *in_ECX = &PTR_FUN_009cec0c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00625eb0 @ 0x00625eb0 ====

void FUN_00625eb0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  return;
}


// ==== FUN_00625ec0 @ 0x00625ec0 ====

undefined4 FUN_00625ec0(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))(1,0);
  FUN_00648df0(unaff_ESI);
  return uVar1;
}


// ==== FUN_00625ef0 @ 0x00625ef0 ====

undefined4 FUN_00625ef0(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0xc))(1,0);
  FUN_00648c80(unaff_ESI);
  return uVar1;
}


// ==== FUN_00625f50 @ 0x00625f50 ====

int * FUN_00625f50(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  cVar1 = FUN_00648a20(param_1);
  if (cVar1 == '\x01') {
    piVar2 = *(int **)(in_ECX + 4);
  }
  else {
    cVar1 = FUN_00648cd0(param_1);
    if (cVar1 == '\x01') {
      piVar2 = *(int **)(in_ECX + 0xc);
    }
    else {
      cVar1 = FUN_00648b70(param_1);
      if (cVar1 != '\x01') {
        return (int *)0x0;
      }
      piVar2 = *(int **)(in_ECX + 8);
    }
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0xc))(1,0);
  (**(code **)(*piVar2 + 0xc))(param_1);
  return piVar2;
}


// ==== FUN_00625fb0 @ 0x00625fb0 ====

void FUN_00625fb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cec74;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x18,1,(_func_void_void_ptr *)&LAB_00625bd0);
  return;
}


// ==== FUN_00625fd0 @ 0x00625fd0 ====

void FUN_00625fd0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989bc8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cec8c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cec74;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x18,1,FUN_00625be0,(_func_void_void_ptr *)&LAB_00625bd0);
  in_ECX[8] = 0;
  in_ECX[8] = in_ECX[8] + 1;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = in_ECX + 2;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00626050 @ 0x00626050 ====

void FUN_00626050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cec7c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x18,1,(_func_void_void_ptr *)&LAB_00625bf0);
  return;
}


// ==== FUN_00626070 @ 0x00626070 ====

void FUN_00626070(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989be8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ceca4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cec7c;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x18,1,FUN_00625c00,(_func_void_void_ptr *)&LAB_00625bf0);
  in_ECX[8] = 0;
  in_ECX[8] = in_ECX[8] + 1;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = in_ECX + 2;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006260f0 @ 0x006260f0 ====

void FUN_006260f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cec84;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x18,1,(_func_void_void_ptr *)&LAB_00625c10);
  return;
}


// ==== FUN_00626110 @ 0x00626110 ====

void FUN_00626110(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989c08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cecbc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cec84;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x18,1,FUN_00625c20,(_func_void_void_ptr *)&LAB_00625c10);
  in_ECX[8] = 0;
  in_ECX[8] = in_ECX[8] + 1;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = in_ECX + 2;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00626190 @ 0x00626190 ====

void FUN_00626190(byte param_1)

{
  void *in_ECX;
  
  FUN_00625fb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006261b0 @ 0x006261b0 ====

void FUN_006261b0(byte param_1)

{
  void *in_ECX;
  
  FUN_006261d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006261d0 @ 0x006261d0 ====

void FUN_006261d0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989c33;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cec8c;
  _Memory = (void *)in_ECX[10];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cec74;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x18,1,(_func_void_void_ptr *)&LAB_00625bd0);
    *in_ECX = &PTR_FUN_009cec2c;
    ExceptionList = local_c;
    return;
  }
  FUN_00648a10();
  _free(_Memory);
  return;
}


// ==== FUN_00626260 @ 0x00626260 ====

void FUN_00626260(byte param_1)

{
  void *in_ECX;
  
  FUN_00626050();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00626280 @ 0x00626280 ====

void FUN_00626280(byte param_1)

{
  void *in_ECX;
  
  FUN_006262a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006262a0 @ 0x006262a0 ====

void FUN_006262a0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989c53;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ceca4;
  _Memory = (void *)in_ECX[10];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cec7c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x18,1,(_func_void_void_ptr *)&LAB_00625bf0);
    *in_ECX = &PTR_FUN_009cec44;
    ExceptionList = local_c;
    return;
  }
  FUN_00648b60();
  _free(_Memory);
  return;
}


// ==== FUN_00626330 @ 0x00626330 ====

void FUN_00626330(byte param_1)

{
  void *in_ECX;
  
  FUN_006260f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00626350 @ 0x00626350 ====

void FUN_00626350(byte param_1)

{
  void *in_ECX;
  
  FUN_00626370();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00626370 @ 0x00626370 ====

void FUN_00626370(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989c73;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cecbc;
  _Memory = (void *)in_ECX[10];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cec84;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x18,1,(_func_void_void_ptr *)&LAB_00625c10);
    *in_ECX = &PTR_FUN_009cec5c;
    ExceptionList = local_c;
    return;
  }
  FUN_00648cc0();
  _free(_Memory);
  return;
}


// ==== FUN_00626400 @ 0x00626400 ====

void * FUN_00626400(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00989ce9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x2c);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x18);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00648ad0();
      }
      *(undefined4 *)((int)param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x28);
      *(void **)(in_ECX + 0x28) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)((int)param_2 + 0xc);
    }
    *(undefined4 *)((int)param_2 + 0xc) = 0;
    *(int *)((int)param_2 + 0x14) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x14) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cecf0,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x14) = *(int *)((int)param_2 + 0x14) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00626500 @ 0x00626500 ====

void * FUN_00626500(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00989d0e;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x2c);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x18);
      local_4 = 0;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00648bf0();
      }
      *(undefined4 *)((int)param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x28);
      *(void **)(in_ECX + 0x28) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)((int)param_2 + 0xc);
    }
    *(undefined4 *)((int)param_2 + 0xc) = 0;
    *(int *)((int)param_2 + 0x14) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x14) == 0) {
      local_10c[0] = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cecf0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x14) = *(int *)((int)param_2 + 0x14) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_006265e0 @ 0x006265e0 ====

undefined4 FUN_006265e0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x14) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cecf0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x14);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x14);
    }
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x2c);
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + -1;
    *(int *)(in_ECX + 0x2c) = param_2;
  }
  return 0;
}


// ==== FUN_00626660 @ 0x00626660 ====

void * FUN_00626660(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00989d0e;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x2c);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x18);
      local_4 = 0;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00648d70();
      }
      *(undefined4 *)((int)param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x28);
      *(void **)(in_ECX + 0x28) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)((int)param_2 + 0xc);
    }
    *(undefined4 *)((int)param_2 + 0xc) = 0;
    *(int *)((int)param_2 + 0x14) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x14) == 0) {
      local_10c[0] = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cecf0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x14) = *(int *)((int)param_2 + 0x14) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00626740 @ 0x00626740 ====

void FUN_00626740(byte param_1)

{
  void *in_ECX;
  
  FUN_00625e30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00626760 @ 0x00626760 ====

void FUN_00626760(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cedc8;
  return;
}


// ==== FUN_00626770 @ 0x00626770 ====

void FUN_00626770(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cedc8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00626790 @ 0x00626790 ====

int FUN_00626790(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_006267a0 @ 0x006267a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006267a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989d28;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cedd8;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    _DAT_00b5acb0 = (undefined4 *)0x0;
  }
  else {
    _DAT_00b5acb0 = in_ECX;
  }
  FUN_00797a50(in_ECX + 1,0,0x24);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00626800 @ 0x00626800 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00626800(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5acb0 = 0;
  *in_ECX = &PTR_FUN_009cedc8;
  return;
}


// ==== FUN_00626820 @ 0x00626820 ====

void FUN_00626820(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009cedc0,s_GuildData_009ced60);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_0062686e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_0062686e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  (**(code **)(*piVar2 + 8))();
  uVar3 = FUN_004756e0(0,1);
  *(undefined4 *)(in_ECX + 4) = uVar3;
  uVar3 = FUN_004756e0(1,1);
  *(undefined4 *)(in_ECX + 8) = uVar3;
  uVar3 = FUN_004756e0(2,1);
  *(undefined4 *)(in_ECX + 0xc) = uVar3;
  uVar3 = FUN_004756e0(3,1);
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  uVar3 = FUN_004756e0(4,1);
  *(undefined4 *)(in_ECX + 0x14) = uVar3;
  uVar3 = FUN_004756e0(5,1);
  *(undefined4 *)(in_ECX + 0x18) = uVar3;
  uVar3 = FUN_004756e0(6,1);
  *(undefined4 *)(in_ECX + 0x1c) = uVar3;
  uVar3 = FUN_004756e0(7,1);
  *(undefined4 *)(in_ECX + 0x20) = uVar3;
  uVar3 = FUN_004756e0(8,1);
  *(undefined4 *)(in_ECX + 0x24) = uVar3;
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar2);
  return;
}


// ==== FUN_00626950 @ 0x00626950 ====

void FUN_00626950(byte param_1)

{
  void *in_ECX;
  
  FUN_00626800();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00626970 @ 0x00626970 ====

void FUN_00626970(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cee4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00626990 @ 0x00626990 ====

void FUN_00626990(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cee60;
  *(undefined1 *)(in_ECX + 1) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ac14 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac14 = in_ECX;
  return;
}


// ==== FUN_006269c0 @ 0x006269c0 ====

void FUN_006269c0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  for (iVar1 = 6; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *in_ECX;
    param_1 = param_1 + 1;
  }
  *(undefined1 *)param_1 = *(undefined1 *)in_ECX;
  return;
}


// ==== FUN_006269e0 @ 0x006269e0 ====

void FUN_006269e0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ac14 = 0;
  *in_ECX = &PTR_FUN_009cee4c;
  return;
}


// ==== FUN_00626a00 @ 0x00626a00 ====

void FUN_00626a00(undefined1 param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int in_ECX;
  uint uVar4;
  
  pcVar1 = (char *)(in_ECX + 4);
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[(int)(&param_1 + -(int)pcVar1)];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') {
      return;
    }
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x19);
  *pcVar1 = '\0';
  return;
}


// ==== FUN_00626a30 @ 0x00626a30 ====

void FUN_00626a30(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int *unaff_ESI;
  undefined4 *puVar6;
  int *piVar7;
  int aiStack_368 [4];
  undefined4 *puStack_358;
  undefined *puStack_354;
  undefined4 *puStack_350;
  char *pcStack_34c;
  undefined *puStack_348;
  char *pcStack_344;
  undefined1 uStack_332;
  undefined4 auStack_331 [8];
  char local_310 [256];
  undefined4 local_210;
  undefined1 local_20c;
  undefined1 local_20b;
  undefined1 local_20a;
  char local_208 [244];
  undefined4 auStack_114 [68];
  
  pcStack_344 = (char *)0x626a4c;
  FUN_005fd550();
  pcStack_344 = s_Version_009cede8;
  pcStack_34c = local_208;
  puStack_348 = &DAT_009cee44;
  puStack_350 = (undefined4 *)0x626a63;
  FUN_0044a580();
  uVar1 = 0;
  do {
    local_310[uVar1] = local_208[uVar1];
    if (local_208[uVar1] == '\0') goto LAB_00626a8e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_310[0] = '\0';
LAB_00626a8e:
  local_210 = param_1;
  pcStack_344 = local_310;
  local_20c = 10;
  local_20b = 0x2c;
  local_20a = 1;
  puStack_348 = (undefined *)0x626ac0;
  piVar2 = (int *)(**(code **)(*DAT_00b5aa34 + 8))();
  puStack_348 = (undefined *)0x626ac9;
  (**(code **)(*piVar2 + 8))();
  puStack_348 = (undefined *)0x1;
  pcStack_34c = (char *)0x0;
  puStack_350 = (undefined4 *)0x626ad4;
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
  puVar6 = auStack_114;
  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar6 = puVar6 + 1;
  }
  puStack_350 = auStack_114;
  puStack_358 = auStack_331 + -1;
  puStack_354 = &DAT_009cee40;
  aiStack_368[3] = 0x626afb;
  FUN_0047aa30();
  iVar4 = *unaff_ESI;
  puVar3 = auStack_331 + -1;
  piVar7 = aiStack_368;
  for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar7 = *puVar3;
    puVar3 = puVar3 + 1;
    piVar7 = piVar7 + 1;
  }
  *(undefined1 *)piVar7 = *(undefined1 *)puVar3;
  (**(code **)(iVar4 + 8))();
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar2);
  return;
}


// ==== FUN_00626b30 @ 0x00626b30 ====

void FUN_00626b30(byte param_1)

{
  void *in_ECX;
  
  FUN_006269e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00626b50 @ 0x00626b50 ====

void FUN_00626b50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cee7c;
  return;
}


// ==== FUN_00626b60 @ 0x00626b60 ====

void FUN_00626b60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cee7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00626b80 @ 0x00626b80 ====

void FUN_00626b80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cee90;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00626ba0 @ 0x00626ba0 ====

void FUN_00626ba0(int *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  (**(code **)(*DAT_00b5ac08 + 8))(uVar1);
  (**(code **)(*DAT_00b5a6e8 + 0x10))();
  FUN_00648eb0();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00626be0 @ 0x00626be0 ====

void FUN_00626be0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989d68;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cef2c;
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009ceea8;
    puVar1[1] = 0;
    puVar1[2] = 0;
  }
  in_ECX[1] = puVar1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aa34 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa34 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00626c70 @ 0x00626c70 ====

void FUN_00626c70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989d7a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cef2c;
  DAT_00b5aa34 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009cee7c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00626cd0 @ 0x00626cd0 ====

undefined4 FUN_00626cd0(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int in_ECX;
  char acStack_106 [258];
  int iStack_4;
  
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  (**(code **)(*DAT_00b5a6e8 + 0xc))();
  uVar3 = (**(code **)(*DAT_00b5ac08 + 4))(iStack_4);
  FUN_005fd550();
  uVar4 = 0;
  do {
    cVar1 = (acStack_106 + (uVar4 - 0xe))[iStack_4 - (int)(acStack_106 + -0xe)];
    acStack_106[uVar4 - 0xe] = cVar1;
    if (cVar1 == '\0') break;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  FUN_0089caf0(uVar3,acStack_106 + -0xe);
  FUN_00648e50(uVar3);
  return uVar2;
}


// ==== FUN_00626da0 @ 0x00626da0 ====

undefined4 FUN_00626da0(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int in_ECX;
  char acStack_10a [262];
  int iStack_4;
  
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  (**(code **)(*DAT_00b5a6e8 + 0xc))();
  uVar3 = (**(code **)(*DAT_00b5ac08 + 4))(iStack_4);
  FUN_005fd550();
  uVar4 = 0;
  do {
    cVar1 = (acStack_10a + (uVar4 - 0xe))[iStack_4 - (int)(acStack_10a + -0xe)];
    acStack_10a[uVar4 - 0xe] = cVar1;
    if (cVar1 == '\0') break;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  FUN_0089cce0(uVar3,acStack_10a + -0xe);
  FUN_00648e50(uVar3);
  return uVar2;
}


// ==== FUN_00626e80 @ 0x00626e80 ====

void FUN_00626e80(byte param_1)

{
  void *in_ECX;
  
  FUN_00626ea0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00626ea0 @ 0x00626ea0 ====

void FUN_00626ea0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cee90;
  return;
}


// ==== FUN_00626eb0 @ 0x00626eb0 ====

void * FUN_00626eb0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00989d4e;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    ExceptionList = &local_c;
    *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
    param_2 = operator_new(0x114);
    local_4 = 0;
    if (param_2 == (void *)0x0) {
      param_2 = (void *)0x0;
    }
    else {
      FUN_00648ef0();
    }
    *(undefined4 *)((int)param_2 + 0x108) = 0;
    *(undefined4 *)((int)param_2 + 0x10c) = *(undefined4 *)(in_ECX + 8);
    *(int *)((int)param_2 + 0x110) = param_1;
    if (*(int *)(in_ECX + 8) != 0) {
      *(void **)(*(int *)(in_ECX + 8) + 0x108) = param_2;
    }
    *(void **)(in_ECX + 8) = param_2;
  }
  else {
    if (*(int *)((int)param_2 + 0x110) == 0) {
      local_10c[0] = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ceec0,0x58);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x110) = *(int *)((int)param_2 + 0x110) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00626fa0 @ 0x00626fa0 ====

undefined4 FUN_00626fa0(uint param_1,void *param_2)

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
    if (*(uint *)((int)param_2 + 0x110) < param_1) {
      local_100[0] = 0;
      uVar3 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009ceec0,0x79);
      FUN_00797b80(uVar3);
      FUN_00797a40();
    }
    piVar1 = (int *)((int)param_2 + 0x110);
    *piVar1 = *piVar1 - param_1;
    uVar3 = *(undefined4 *)((int)param_2 + 0x110);
    if (*piVar1 == 0) {
      iVar2 = *(int *)((int)param_2 + 0x10c);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 0x108) = *(undefined4 *)((int)param_2 + 0x108);
      }
      if (param_2 == *(void **)(in_ECX + 8)) {
        *(int *)(in_ECX + 8) = iVar2;
      }
      else {
        *(int *)(*(int *)((int)param_2 + 0x108) + 0x10c) = iVar2;
      }
      thunk_FUN_00648ea0();
      _free(param_2);
      return extraout_EAX;
    }
  }
  return uVar3;
}


// ==== FUN_00627060 @ 0x00627060 ====

void FUN_00627060(byte param_1)

{
  void *in_ECX;
  
  FUN_00626c70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00627080 @ 0x00627080 ====

void FUN_00627080(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cef40;
  return;
}


// ==== FUN_00627090 @ 0x00627090 ====

void FUN_00627090(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cef40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006270b0 @ 0x006270b0 ====

uint FUN_006270b0(uint param_1)

{
  uint uVar1;
  uint in_EAX;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 4);
  if (uVar1 == 0) {
    return in_EAX & 0xffffff00;
  }
  *(uint *)(in_ECX + 0xc) = param_1 % uVar1;
  *(uint *)(in_ECX + 8) = param_1 % uVar1;
  return CONCAT31((int3)(param_1 / uVar1 >> 8),1);
}


// ==== FUN_006270e0 @ 0x006270e0 ====

void FUN_006270e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cef58;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b0a0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b0a0 = in_ECX;
  return;
}


// ==== FUN_00627110 @ 0x00627110 ====

undefined4 FUN_00627110(uint param_1)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  uint uVar5;
  
  pvVar1 = operator_new(param_1 * 4);
  uVar5 = 0;
  *(void **)(in_ECX + 0x10) = pvVar1;
  if (param_1 != 0) {
    do {
      iVar2 = FUN_00797ac0(0x1000);
      uVar3 = FUN_00797ac0(0x1000);
      uVar4 = FUN_00797ac0(0x100);
      *(uint *)(*(int *)(in_ECX + 0x10) + uVar5 * 4) =
           iVar2 << 0x14 | (uVar3 & 0xfff) << 8 | uVar4 & 0xff;
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_1);
  }
  *(uint *)(in_ECX + 4) = param_1;
  return 1;
}


// ==== FUN_00627190 @ 0x00627190 ====

uint FUN_00627190(uint param_1,uint param_2)

{
  uint uVar1;
  int in_ECX;
  
  if (param_2 <= param_1) {
    return param_1;
  }
  if (*(uint *)(in_ECX + 4) == 0) {
    uVar1 = FUN_006272b0();
    return uVar1 % (param_2 - param_1) + param_1;
  }
  uVar1 = *(uint *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 8) * 4);
  *(uint *)(in_ECX + 8) = (*(int *)(in_ECX + 8) + 1U) % *(uint *)(in_ECX + 4);
  return uVar1 % (param_2 - param_1) + param_1;
}


// ==== FUN_006271f0 @ 0x006271f0 ====

uint FUN_006271f0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  
  if (*(uint *)(in_ECX + 4) == 0) {
    iVar1 = FUN_00797ac0(0x1000);
    uVar2 = FUN_00797ac0(0x1000);
    uVar3 = FUN_00797ac0(0x100);
    return uVar3 & 0xff | iVar1 << 0x14 | (uVar2 & 0xfff) << 8;
  }
  uVar2 = *(uint *)(*(int *)(in_ECX + 0x10) + *(int *)(in_ECX + 8) * 4);
  *(uint *)(in_ECX + 8) = (*(int *)(in_ECX + 8) + 1U) % *(uint *)(in_ECX + 4);
  return uVar2;
}


// ==== FUN_00627250 @ 0x00627250 ====

void FUN_00627250(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989d98;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cef58;
  DAT_00b5b0a0 = 0;
  local_4 = 0;
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_006272b0 @ 0x006272b0 ====

uint FUN_006272b0(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = FUN_00797ac0(0x1000);
  uVar2 = FUN_00797ac0(0x1000);
  uVar3 = FUN_00797ac0(0x100);
  return uVar3 & 0xff | iVar1 << 0x14 | (uVar2 & 0xfff) << 8;
}


// ==== FUN_006272f0 @ 0x006272f0 ====

void FUN_006272f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00627250();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00627310 @ 0x00627310 ====

void FUN_00627310(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cef70;
  return;
}


// ==== FUN_00627320 @ 0x00627320 ====

void FUN_00627320(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cef70;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00627340 @ 0x00627340 ====

int FUN_00627340(byte param_1)

{
  int in_ECX;
  
  return in_ECX + 4 + (uint)param_1 * 0xc;
}


// ==== FUN_00627350 @ 0x00627350 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00627350(byte param_1)

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


// ==== FUN_006273b0 @ 0x006273b0 ====

void FUN_006273b0(undefined4 param_1)

{
  FUN_004ef070(param_1);
  return;
}


// ==== FUN_006273f0 @ 0x006273f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_006273f0(void)

{
  undefined4 uVar1;
  float fVar2;
  undefined1 uVar3;
  uint uVar4;
  undefined4 *in_ECX;
  int iVar5;
  float *pfVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  float10 fVar11;
  float10 fVar12;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989db8;
  local_c = ExceptionList;
  uVar8 = 0;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cef8c;
  puVar9 = in_ECX + 1;
  iVar5 = 0x100;
  do {
    *puVar9 = 0;
    puVar9[1] = 0;
    puVar9[2] = 0;
    fVar2 = DAT_009b2d7c;
    uVar1 = DAT_009b0eb8;
    puVar9 = puVar9 + 3;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  uVar4 = 0;
  pfVar6 = (float *)(in_ECX + 2);
  do {
    if ((DAT_00b5ade8 & 1) == 0) {
      DAT_00b5ade8 = DAT_00b5ade8 | 1;
      _DAT_00b5ade4 = uVar1;
    }
    if ((DAT_00b5ade8 & 2) == 0) {
      DAT_00b5ade8 = DAT_00b5ade8 | 2;
      _DAT_00b5ade0 = fVar2;
    }
    uVar7 = uVar4 & 0xff;
    uVar4 = uVar4 + 1;
    fVar11 = (float10)uVar7 * (float10)_DAT_00b5ade0 * (float10)_DAT_009ae954;
    fVar12 = (float10)fsin(fVar11);
    pfVar6[-1] = (float)-fVar12;
    fVar11 = (float10)fcos(fVar11);
    *pfVar6 = (float)-fVar11;
    pfVar6 = pfVar6 + 3;
  } while ((int)uVar4 < 0x100);
  if ((_DAT_00b5b0a8 & 1) == 0) {
    _DAT_00b5b0a8 = _DAT_00b5b0a8 | 1;
    _DAT_00b5b0a4 = DAT_009b2d78;
  }
  puVar9 = in_ECX + 0x301;
  FUN_00797a50(puVar9,0,0x10201);
  do {
    uVar4 = 0;
    puVar10 = puVar9;
    do {
      fpatan((float10)(0.0 - (float)(int)(uVar8 - 0x80)),-(float10)(int)(uVar4 - 0x80));
      uVar3 = FUN_00802534();
      *(undefined1 *)puVar10 = uVar3;
      uVar4 = uVar4 + 1;
      puVar10 = (undefined4 *)((int)puVar10 + 0x101);
    } while (uVar4 < 0x101);
    uVar8 = uVar8 + 1;
    puVar9 = (undefined4 *)((int)puVar9 + 1);
  } while (uVar8 < 0x101);
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ab40 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return (undefined4 *)0xfffffffc;
  }
  DAT_00b5ab40 = in_ECX;
  ExceptionList = local_c;
  return in_ECX;
}


// ==== FUN_006275b0 @ 0x006275b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_006275b0(float *param_1,float *param_2)

{
  int iVar1;
  int in_ECX;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  if ((_DAT_00b5b0b0 & 1) == 0) {
    _DAT_00b5b0b0 = _DAT_00b5b0b0 | 1;
    DAT_00b5b0ac = DAT_009b2d78;
  }
  fVar4 = param_2[1] - param_1[1];
  fVar3 = *param_2 - *param_1;
  if (fVar4 <= 0.0) {
    fVar5 = 0.0 - fVar4;
  }
  else {
    fVar5 = fVar4;
  }
  if (fVar3 <= 0.0) {
    fVar2 = 0.0 - fVar3;
  }
  else {
    fVar2 = fVar3;
  }
  if (fVar5 < fVar2) {
    fVar5 = fVar2;
  }
  if (fVar5 == 0.0) {
    return (uint)CONCAT21((short)((uint)param_2 >> 0x10),
                          (fVar5 == 0.0) << 6 | NAN(fVar5) << 2 | 2U | fVar5 < 0.0) << 8;
  }
  iVar1 = (int)(((DAT_0099d080 / fVar5) * fVar4 + DAT_0099d080) * DAT_00b5b0ac);
  return CONCAT31((int3)((uint)iVar1 >> 8),
                  *(undefined1 *)
                   ((int)(((DAT_0099d080 / fVar5) * fVar3 + DAT_0099d080) * DAT_00b5b0ac) + 0xc04 +
                   iVar1 * 0x101 + in_ECX));
}


// ==== FUN_00627680 @ 0x00627680 ====

void FUN_00627680(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ab40 = 0;
  *in_ECX = &PTR_FUN_009cef70;
  return;
}


// ==== FUN_006276a0 @ 0x006276a0 ====

void FUN_006276a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00627680();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006276c0 @ 0x006276c0 ====

void FUN_006276c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cf868;
  return;
}


// ==== FUN_006276d0 @ 0x006276d0 ====

void FUN_006276d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cf868;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006276f0 @ 0x006276f0 ====

int FUN_006276f0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00627700 @ 0x00627700 ====

undefined1 FUN_00627700(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 8);
  for (iVar1 = 0x3d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return 1;
}


// ==== FUN_00627720 @ 0x00627720 ====

void FUN_00627720(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989dd8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cf90c;
  DAT_00b5a6b8 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[0x40] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x40])(1);
  }
  in_ECX[0x40] = 0;
  if ((undefined4 *)in_ECX[0x3f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x3f])(1);
  }
  in_ECX[0x3f] = 0;
  *in_ECX = &PTR_FUN_009cf868;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006277a0 @ 0x006277a0 ====

void FUN_006277a0(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int in_ECX;
  float10 fVar5;
  
  uVar3 = FUN_00628520(s_wMaxLevel_009cf004);
  *(undefined2 *)(in_ECX + 8) = uVar3;
  uVar3 = FUN_00628520(s_wMinLevelToLoseExp_009cf010);
  *(undefined2 *)(in_ECX + 10) = uVar3;
  uVar1 = FUN_00628630(s_byStatPointPerLevel_009cf024);
  *(undefined1 *)(in_ECX + 0xc) = uVar1;
  uVar3 = FUN_00628520(s_wDropMaxDistance_009cf038);
  *(undefined2 *)(in_ECX + 0xe) = uVar3;
  fVar5 = (float10)FUN_00628740(s_fItemRatio_009cf04c);
  *(float *)(in_ECX + 0x10) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fPCDamageRatio_009cf058);
  *(float *)(in_ECX + 0x34) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fPCDefenseRatio_009cf068);
  *(float *)(in_ECX + 0x38) = (float)fVar5;
  uVar1 = FUN_00628630(s_byServantPCPhyDamageRate_009cf078);
  *(undefined1 *)(in_ECX + 0x14) = uVar1;
  uVar1 = FUN_00628630(s_byServantPCMagDamageRate_009cf094);
  *(undefined1 *)(in_ECX + 0x15) = uVar1;
  fVar5 = (float10)FUN_00628740(s_fMonAttDamageRatio_009cf0b0);
  *(float *)(in_ECX + 0x18) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fMonAttRatingRatio_009cf0c4);
  *(float *)(in_ECX + 0x1c) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fMonDefRatio_009cf0d8);
  *(float *)(in_ECX + 0x20) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fMonEXPRatio_009cf0e8);
  *(float *)(in_ECX + 0x24) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fMonMoneyRatio_009cf0f8);
  *(float *)(in_ECX + 0x28) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fMonItemDropRatio_009cf108);
  *(float *)(in_ECX + 0x2c) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fMonMoneyDropRatio_009cf11c);
  *(float *)(in_ECX + 0x30) = (float)fVar5;
  uVar1 = FUN_00628630(s_byMaxItemLevel_009cf130);
  *(undefined1 *)(in_ECX + 0x3c) = uVar1;
  uVar1 = FUN_00628630(s_byHPRecoveryFactor_009cf140);
  *(undefined1 *)(in_ECX + 0x3d) = uVar1;
  uVar1 = FUN_00628630(s_byMPRecoveryFactor_009cf154);
  *(undefined1 *)(in_ECX + 0x3e) = uVar1;
  uVar3 = FUN_00628520(s_wHPFullRecoveryTime_009cf168);
  *(undefined2 *)(in_ECX + 0x40) = uVar3;
  uVar3 = FUN_00628520(s_wMPFullRecoveryTime_009cf17c);
  *(undefined2 *)(in_ECX + 0x42) = uVar3;
  fVar5 = (float10)FUN_00628740(s_fSameWeaponBonus_009cf190);
  *(float *)(in_ECX + 0x44) = (float)fVar5;
  uVar1 = FUN_00628630(s_byReviveHPRatio_009cf1a4);
  *(undefined1 *)(in_ECX + 0x48) = uVar1;
  uVar1 = FUN_00628630(s_byReviveMPRatio_009cf1b4);
  *(undefined1 *)(in_ECX + 0x49) = uVar1;
  uVar1 = FUN_00628630(s_byReviveExpCostRatio_009cf1c4);
  *(undefined1 *)(in_ECX + 0x4a) = uVar1;
  uVar4 = FUN_00628840(s_dwReviveTick_009cf1dc);
  *(undefined4 *)(in_ECX + 0x54) = uVar4;
  uVar1 = FUN_00628630(s_byRespawnHPRatio_009cf1ec);
  *(undefined1 *)(in_ECX + 0x4b) = uVar1;
  uVar1 = FUN_00628630(s_byRespawnMPRatio_009cf200);
  *(undefined1 *)(in_ECX + 0x4c) = uVar1;
  uVar1 = FUN_00628630(s_byRespawnExpCostRatio_009cf214);
  *(undefined1 *)(in_ECX + 0x4d) = uVar1;
  uVar4 = FUN_00628840(s_stStorageCostPerUnit_009cf22c);
  *(undefined4 *)(in_ECX + 0x50) = uVar4;
  fVar5 = (float10)FUN_00628740(s_fItemSetDropRate_009cf244);
  *(float *)(in_ECX + 0x58) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fDILDropRate_009cf258);
  *(float *)(in_ECX + 0x5c) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fMonsterHP_009cf268);
  *(float *)(in_ECX + 0x60) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fMonsterHPRecovery_009cf274);
  *(float *)(in_ECX + 100) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fMonsterHPDecrease_009cf288);
  *(float *)(in_ECX + 0x68) = (float)fVar5;
  uVar4 = FUN_00628840(s_dwOwnershipLifeTime_009cf29c);
  *(undefined4 *)(in_ECX + 0x6c) = uVar4;
  fVar5 = (float10)FUN_00628740(s_fBuyPriceRate_009cf2b0);
  *(float *)(in_ECX + 0x70) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fSellPriceRate_009cf2c0);
  *(float *)(in_ECX + 0x74) = (float)fVar5;
  uVar1 = FUN_00628630(s_byNormalRepairPriceRate_009cf2d0);
  *(undefined1 *)(in_ECX + 0x78) = uVar1;
  uVar1 = FUN_00628630(s_byDamagedRepairPriceRate_009cf2e8);
  *(undefined1 *)(in_ECX + 0x79) = uVar1;
  uVar1 = FUN_00628630(s_byDamagedDurabilityRate_009cf304);
  *(undefined1 *)(in_ECX + 0x7a) = uVar1;
  fVar5 = (float10)FUN_00628740(s_fSkillCoolTimeRate_009cf31c);
  *(float *)(in_ECX + 0x7c) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fDEXAttackRatingFactor_009cf330);
  *(float *)(in_ECX + 0x80) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fMaxAttackProbFactor_009cf348);
  *(float *)(in_ECX + 0x84) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fDefaultAttackProb_009cf360);
  *(float *)(in_ECX + 0x88) = (float)fVar5;
  uVar1 = FUN_00628630(s_byMinAttackProbability_009cf374);
  *(undefined1 *)(in_ECX + 0x8c) = uVar1;
  uVar1 = FUN_00628630(s_byMaxAttackProbability_009cf38c);
  *(undefined1 *)(in_ECX + 0x8d) = uVar1;
  uVar1 = FUN_00628630(s_byGuardProbability_009cf3a4);
  *(undefined1 *)(in_ECX + 0x8e) = uVar1;
  uVar1 = FUN_00628630(s_byGuardEfficiency_009cf3b8);
  *(undefined1 *)(in_ECX + 0x8f) = uVar1;
  uVar1 = FUN_00628630(s_byMinDefeatRate_009cf3cc);
  *(undefined1 *)(in_ECX + 0xa0) = uVar1;
  uVar1 = FUN_00628630(s_byMaxDefeatRate_009cf3dc);
  *(undefined1 *)(in_ECX + 0xa1) = uVar1;
  uVar1 = FUN_00628630(s_byDeath1_Max_009cf3ec);
  *(undefined1 *)(in_ECX + 0xa2) = uVar1;
  uVar1 = FUN_00628630(s_byDeath2_Max_009cf3fc);
  *(undefined1 *)(in_ECX + 0xa3) = uVar1;
  uVar1 = FUN_00628630(s_byDeath3_Max_009cf40c);
  *(undefined1 *)(in_ECX + 0xa4) = uVar1;
  uVar1 = FUN_00628630(s_bySplit1_Max_009cf41c);
  *(undefined1 *)(in_ECX + 0xa5) = uVar1;
  uVar1 = FUN_00628630(s_bySplit2_Max_009cf42c);
  *(undefined1 *)(in_ECX + 0xa6) = uVar1;
  fVar5 = (float10)FUN_00628740(s_fSTRFactorForCritical_009cf43c);
  *(float *)(in_ECX + 0x90) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fDEXFactorForCritical_009cf454);
  *(float *)(in_ECX + 0x94) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fSPRFactorForCritical_009cf46c);
  *(float *)(in_ECX + 0x98) = (float)fVar5;
  fVar5 = (float10)FUN_00628740(s_fDEXEfficiencyFactor_009cf484);
  *(float *)(in_ECX + 0x9c) = (float)fVar5;
  uVar3 = FUN_00628520(s_wOnePartyExpRate_009cf49c);
  *(undefined2 *)(in_ECX + 0xa8) = uVar3;
  uVar3 = FUN_00628520(s_wTwoPartyExpRate_009cf4b0);
  *(undefined2 *)(in_ECX + 0xaa) = uVar3;
  uVar3 = FUN_00628520(s_wThreePartyExpRate_009cf4c4);
  *(undefined2 *)(in_ECX + 0xac) = uVar3;
  uVar3 = FUN_00628520(s_wFourPartyExpRate_009cf4d8);
  *(undefined2 *)(in_ECX + 0xae) = uVar3;
  uVar3 = FUN_00628520(s_wFivePartyExpRate_009cf4ec);
  *(undefined2 *)(in_ECX + 0xb0) = uVar3;
  uVar3 = FUN_00628520(s_wSixPartyExpRate_009cf500);
  *(undefined2 *)(in_ECX + 0xb2) = uVar3;
  uVar4 = FUN_00628960(s_nPKDamageRate_009cf514);
  *(undefined4 *)(in_ECX + 0xb4) = uVar4;
  uVar4 = FUN_00628960(s_nPKDefeatRate_009cf524);
  *(undefined4 *)(in_ECX + 0xb8) = uVar4;
  uVar1 = FUN_00628630(s_byPKBlockRate_009cf534);
  *(undefined1 *)(in_ECX + 0xbc) = uVar1;
  uVar1 = FUN_00628630(s_byPKGuardRate_009cf544);
  *(undefined1 *)(in_ECX + 0xbd) = uVar1;
  cVar2 = FUN_00628630(s_bPKVersion_009cf554);
  *(bool *)(in_ECX + 0xbe) = cVar2 == '\x01';
  uVar4 = FUN_00628960(s_nGuardARFactor_009cf560);
  *(undefined4 *)(in_ECX + 0xc0) = uVar4;
  uVar4 = FUN_00628840(s_dwNonPKTime_009cf570);
  *(undefined4 *)(in_ECX + 0xc4) = uVar4;
  uVar3 = FUN_00628520(s_wPCRoomExpRatio_009cf57c);
  *(undefined2 *)(in_ECX + 200) = uVar3;
  uVar4 = FUN_00628840(s_dwLosingRightTime_009cf58c);
  *(undefined4 *)(in_ECX + 0xcc) = uVar4;
  uVar4 = FUN_00628960(s_nGetRightDamageRatio_009cf5a0);
  *(undefined4 *)(in_ECX + 0xd0) = uVar4;
  uVar4 = FUN_00628960(s_dwFishingCastingmMinTime_009cf5b8);
  *(undefined4 *)(in_ECX + 0xd4) = uVar4;
  uVar4 = FUN_00628960(s_dwFishingCastingmMaxTime_009cf5d4);
  *(undefined4 *)(in_ECX + 0xd8) = uVar4;
  uVar4 = FUN_00628840(s_dwWinPVPPointRatio_009cf5f0);
  *(undefined4 *)(in_ECX + 0xdc) = uVar4;
  uVar4 = FUN_00628840(s_dwLosePVPPointRatio_009cf604);
  *(undefined4 *)(in_ECX + 0xe0) = uVar4;
  uVar4 = FUN_00628840(s_dwLossPVPPointRatio_009cf618);
  *(undefined4 *)(in_ECX + 0xe4) = uVar4;
  fVar5 = (float10)FUN_00628740(s_fLimitWinPVPRatio_009cf62c);
  *(float *)(in_ECX + 0xe8) = (float)fVar5;
  uVar4 = FUN_00628840(s_dwPVPReviveTick_009cf640);
  *(undefined4 *)(in_ECX + 0xec) = uVar4;
  cVar2 = FUN_00628630(s_bSiege_009cf650);
  *(bool *)(in_ECX + 0xf0) = cVar2 == '\x01';
  uVar4 = FUN_00628840(s_dwEntrySiegeCost_009cf658);
  *(undefined4 *)(in_ECX + 0xf4) = uVar4;
  uVar3 = FUN_00628520(s_wAdvertiseExpRatio_009cf66c);
  *(undefined2 *)(in_ECX + 0xf8) = uVar3;
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00627d50 @ 0x00627d50 ====

undefined4 FUN_00627d50(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  int unaff_EBP;
  int iVar8;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009cf680,s_Logic_Config_009cefa4);
  uVar2 = 0;
  do {
    local_208[uVar2] = local_100[uVar2];
    if (local_100[uVar2] == '\0') goto LAB_00627d9e;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_208[0] = '\0';
LAB_00627d9e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  piVar3 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_208);
  (**(code **)(*piVar3 + 8))();
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (iVar4 != 0) {
    do {
      iVar8 = 1;
      pcVar5 = (char *)(**(code **)(**(int **)(unaff_EBP + 0xfc) + 0xc))(1,0);
      iVar4 = (**(code **)(*piVar3 + 0x10))(0,0);
      uVar2 = 0;
      pcVar6 = pcVar5;
      do {
        cVar1 = pcVar6[iVar4 - (int)pcVar5];
        *pcVar6 = cVar1;
        if (cVar1 == '\0') goto LAB_00627e3f;
        uVar2 = uVar2 + 1;
        pcVar6 = pcVar6 + 1;
      } while (uVar2 < 0x100);
      *pcVar5 = '\0';
LAB_00627e3f:
      iVar4 = (**(code **)(*piVar3 + 0x10))(0,1);
      pcVar6 = pcVar5 + 0x100;
      uVar2 = 0;
      pcVar7 = pcVar6;
      do {
        cVar1 = pcVar7[iVar4 - (int)pcVar6];
        *pcVar7 = cVar1;
        if (cVar1 == '\0') goto LAB_00627e71;
        uVar2 = uVar2 + 1;
        pcVar7 = pcVar7 + 1;
      } while (uVar2 < 0x100);
      *pcVar6 = '\0';
LAB_00627e71:
      (**(code **)(**(int **)(iVar8 + 0x100) + 0x28))(pcVar5);
      uVar2 = (**(code **)(*piVar3 + 8))();
    } while (iVar8 + 1U < uVar2);
  }
  FUN_006277a0();
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar3);
  return 1;
}


// ==== FUN_00627ec0 @ 0x00627ec0 ====

void FUN_00627ec0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00989e00;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cf90c;
  *(undefined1 *)(in_ECX + 1) = 1;
  FUN_00797a50(in_ECX + 2,0,0xf4);
  uVar3 = DAT_0099d0b4;
  in_ECX[0x11] = DAT_009a09bc;
  uVar1 = DAT_009b0300;
  in_ECX[0x19] = DAT_009b0300;
  in_ECX[0x1a] = uVar1;
  in_ECX[0x20] = DAT_009b0ec8;
  uVar1 = DAT_0099de78;
  *(undefined1 *)((int)in_ECX + 0x3d) = 0x23;
  *(undefined1 *)((int)in_ECX + 0x3e) = 0x23;
  in_ECX[0x21] = uVar1;
  uVar1 = DAT_009bac84;
  *(undefined2 *)(in_ECX + 0x10) = 0x168;
  *(undefined2 *)((int)in_ECX + 0x42) = 0x168;
  in_ECX[4] = uVar3;
  uVar3 = DAT_0099d080;
  in_ECX[0x22] = uVar1;
  uVar1 = DAT_009a09b8;
  *(undefined2 *)(in_ECX + 2) = 0x96;
  *(undefined2 *)((int)in_ECX + 10) = 0;
  *(undefined1 *)(in_ECX + 3) = 5;
  *(undefined2 *)((int)in_ECX + 0xe) = 0x96;
  in_ECX[0xd] = uVar3;
  in_ECX[0xe] = uVar3;
  *(undefined1 *)(in_ECX + 5) = 0x1e;
  *(undefined1 *)((int)in_ECX + 0x15) = 0x1e;
  in_ECX[6] = uVar3;
  in_ECX[7] = uVar3;
  in_ECX[8] = uVar3;
  in_ECX[9] = uVar3;
  in_ECX[10] = uVar3;
  in_ECX[0xb] = uVar3;
  in_ECX[0xc] = uVar3;
  *(undefined1 *)(in_ECX + 0xf) = 10;
  *(undefined1 *)(in_ECX + 0x12) = 100;
  *(undefined1 *)((int)in_ECX + 0x49) = 100;
  *(undefined1 *)((int)in_ECX + 0x4a) = 5;
  in_ECX[0x15] = 4000;
  *(undefined1 *)((int)in_ECX + 0x4b) = 100;
  *(undefined1 *)(in_ECX + 0x13) = 100;
  *(undefined1 *)((int)in_ECX + 0x4d) = 3;
  in_ECX[0x14] = 10;
  in_ECX[0x16] = uVar3;
  in_ECX[0x17] = uVar3;
  in_ECX[0x18] = uVar3;
  in_ECX[0x1b] = 3000;
  in_ECX[0x1c] = uVar3;
  in_ECX[0x1d] = uVar3;
  *(undefined1 *)(in_ECX + 0x1e) = 0x32;
  *(undefined1 *)((int)in_ECX + 0x79) = 0x50;
  *(undefined1 *)((int)in_ECX + 0x7a) = 10;
  in_ECX[0x1f] = uVar3;
  *(undefined1 *)(in_ECX + 0x23) = 0x1e;
  *(undefined1 *)((int)in_ECX + 0x8d) = 0x5f;
  *(undefined1 *)(in_ECX + 0x28) = 0xf;
  *(undefined1 *)((int)in_ECX + 0xa1) = 0x1e;
  in_ECX[0x24] = uVar1;
  in_ECX[0x25] = uVar1;
  *(undefined2 *)(in_ECX + 0x2a) = 100;
  *(undefined2 *)((int)in_ECX + 0xaa) = 100;
  *(undefined2 *)(in_ECX + 0x2b) = 100;
  *(undefined2 *)((int)in_ECX + 0xae) = 100;
  *(undefined2 *)(in_ECX + 0x2c) = 100;
  *(undefined2 *)((int)in_ECX + 0xb2) = 100;
  in_ECX[0x33] = 10000;
  in_ECX[0x35] = 10000;
  in_ECX[0x37] = 2;
  in_ECX[0x38] = 2;
  in_ECX[0x27] = uVar3;
  uVar3 = DAT_009b2dc0;
  in_ECX[0x26] = uVar1;
  *(undefined1 *)((int)in_ECX + 0xa2) = 2;
  *(undefined1 *)((int)in_ECX + 0xa3) = 5;
  *(undefined1 *)(in_ECX + 0x29) = 10;
  *(undefined1 *)((int)in_ECX + 0xa5) = 0xf;
  *(undefined1 *)((int)in_ECX + 0xa6) = 0x14;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  *(undefined1 *)(in_ECX + 0x2f) = 0;
  *(undefined1 *)((int)in_ECX + 0xbd) = 0;
  *(undefined1 *)((int)in_ECX + 0xbe) = 0;
  in_ECX[0x30] = 1000;
  in_ECX[0x31] = 30000;
  *(undefined2 *)(in_ECX + 0x32) = 0;
  in_ECX[0x34] = 0x3c;
  in_ECX[0x36] = 15000;
  in_ECX[0x39] = 1;
  in_ECX[0x3a] = uVar3;
  in_ECX[0x3b] = 1;
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  in_ECX[0x3d] = 50000000;
  *(undefined2 *)(in_ECX + 0x3e) = 0;
  pvVar2 = operator_new(0x224);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00628300();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x3f] = uVar3;
  pvVar2 = operator_new(0x48);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00628df0(in_ECX[0x3f]);
  }
  in_ECX[0x40] = uVar3;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a6b8 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a6b8 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006281f0 @ 0x006281f0 ====

void FUN_006281f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cf87c;
  return;
}


// ==== FUN_00628200 @ 0x00628200 ====

void FUN_00628200(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cf894;
  return;
}


// ==== FUN_00628210 @ 0x00628210 ====

void FUN_00628210(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cf8ec;
  return;
}


// ==== FUN_00628220 @ 0x00628220 ====

void FUN_00628220(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cf87c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00628240 @ 0x00628240 ====

void FUN_00628240(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cf894;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00628260 @ 0x00628260 ====

void FUN_00628260(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cf8ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00628280 @ 0x00628280 ====

void FUN_00628280(int param_1)

{
  char cVar1;
  char *in_ECX;
  uint uVar2;
  char *pcVar3;
  
  *in_ECX = '\0';
  uVar2 = 0;
  in_ECX[0x100] = '\0';
  pcVar3 = in_ECX;
  do {
    cVar1 = pcVar3[param_1 - (int)in_ECX];
    *pcVar3 = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar2 < 0x100);
  *in_ECX = '\0';
  return;
}


// ==== FUN_006282c0 @ 0x006282c0 ====

void FUN_006282c0(void)

{
  undefined1 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[0x100] = 0;
  return;
}


// ==== FUN_006282d0 @ 0x006282d0 ====

void FUN_006282d0(void)

{
  FUN_006282c0();
  return;
}


// ==== FUN_006282e0 @ 0x006282e0 ====

void FUN_006282e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cf904;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20c,1,FUN_006ef6d0);
  return;
}


// ==== FUN_00628300 @ 0x00628300 ====

void FUN_00628300(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989e18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cf920;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cf904;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20c,1,FUN_006282d0,FUN_006ef6d0);
  in_ECX[0x85] = 0;
  in_ECX[0x85] = in_ECX[0x85] + 1;
  in_ECX[0x86] = 0;
  in_ECX[0x87] = 0;
  in_ECX[0x88] = in_ECX + 2;
  in_ECX[0x82] = 0;
  in_ECX[0x83] = 0;
  in_ECX[0x84] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006283a0 @ 0x006283a0 ====

undefined4 FUN_006283a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x218);
}


// ==== FUN_006283b0 @ 0x006283b0 ====

undefined4 FUN_006283b0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x208) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cf938,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x208);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x208);
    }
    *(undefined4 *)(param_2 + 0x200) = *(undefined4 *)(in_ECX + 0x220);
    *(int *)(in_ECX + 0x218) = *(int *)(in_ECX + 0x218) + -1;
    *(int *)(in_ECX + 0x220) = param_2;
  }
  return 0;
}


// ==== FUN_00628440 @ 0x00628440 ====

undefined1 * FUN_00628440(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined1 *)0x0) {
    if (*(int *)(param_2 + 0x208) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cf938,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x208) = *(int *)(param_2 + 0x208) + param_1;
    return param_2;
  }
  puVar2 = *(undefined1 **)(in_ECX + 0x220);
  *(int *)(in_ECX + 0x218) = *(int *)(in_ECX + 0x218) + 1;
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = operator_new(0x20c);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = (undefined1 *)0x0;
    }
    else {
      *puVar2 = 0;
      puVar2[0x100] = 0;
    }
    *(undefined4 *)(puVar2 + 0x204) = *(undefined4 *)(in_ECX + 0x21c);
    *(undefined1 **)(in_ECX + 0x21c) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x220) = *(undefined4 *)(puVar2 + 0x200);
  }
  *(undefined4 *)(puVar2 + 0x200) = 0;
  *(int *)(puVar2 + 0x208) = param_1;
  return puVar2;
}


// ==== FUN_00628520 @ 0x00628520 ====

void FUN_00628520(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  char acStack_40c [256];
  undefined1 auStack_30c [260];
  undefined1 local_208 [516];
  
  FUN_0044a580(acStack_40c + 4,&DAT_009cf680,param_1);
  FUN_00628280(acStack_40c + 4);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x100) + 0x30))(local_208);
  if (piVar1 == (int *)0x0) {
    auStack_30c[0] = 0;
    uVar2 = FUN_0044a580(auStack_30c,s___ASSERT___Cannot_Find__s_in_for_009cf684,param_1);
    FUN_00797b80(uVar2);
    auStack_30c[0] = 0;
    uVar2 = FUN_0044a580(auStack_30c,s_File___s__Line___d_009cf6d0,
                         s___Support_Config_Provider_cpp_009cf6b0,0x183);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  puVar5 = (undefined4 *)(*piVar1 + 0x100);
  pcVar6 = acStack_40c;
  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pcVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    pcVar6 = pcVar6 + 4;
  }
  uVar3 = 0;
  do {
    if (acStack_40c[uVar3] == '\0') {
      if (uVar3 != 0) {
        _atof(acStack_40c);
        FUN_00802534();
        return;
      }
      break;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  FUN_00802534();
  return;
}


// ==== FUN_00628630 @ 0x00628630 ====

void FUN_00628630(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  char acStack_40c [256];
  undefined1 auStack_30c [260];
  undefined1 local_208 [516];
  
  FUN_0044a580(acStack_40c + 4,&DAT_009cf680,param_1);
  FUN_00628280(acStack_40c + 4);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x100) + 0x30))(local_208);
  if (piVar1 == (int *)0x0) {
    auStack_30c[0] = 0;
    uVar2 = FUN_0044a580(auStack_30c,s___ASSERT___Cannot_Find__s_in_for_009cf6e4,param_1);
    FUN_00797b80(uVar2);
    auStack_30c[0] = 0;
    uVar2 = FUN_0044a580(auStack_30c,s_File___s__Line___d_009cf730,
                         s___Support_Config_Provider_cpp_009cf710,0x183);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  puVar5 = (undefined4 *)(*piVar1 + 0x100);
  pcVar6 = acStack_40c;
  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pcVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    pcVar6 = pcVar6 + 4;
  }
  uVar3 = 0;
  do {
    if (acStack_40c[uVar3] == '\0') {
      if (uVar3 != 0) {
        _atof(acStack_40c);
        FUN_00802534();
        return;
      }
      break;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  FUN_00802534();
  return;
}


// ==== FUN_00628740 @ 0x00628740 ====

float10 FUN_00628740(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  double dVar7;
  char acStack_40c [256];
  undefined1 auStack_30c [260];
  undefined1 local_208 [516];
  
  FUN_0044a580(acStack_40c + 4,&DAT_009cf680,param_1);
  FUN_00628280(acStack_40c + 4);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x100) + 0x30))(local_208);
  if (piVar1 == (int *)0x0) {
    auStack_30c[0] = 0;
    uVar2 = FUN_0044a580(auStack_30c,s___ASSERT___Cannot_Find__s_in_for_009cf744,param_1);
    FUN_00797b80(uVar2);
    auStack_30c[0] = 0;
    uVar2 = FUN_0044a580(auStack_30c,s_File___s__Line___d_009cf790,
                         s___Support_Config_Provider_cpp_009cf770,0x183);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  puVar5 = (undefined4 *)(*piVar1 + 0x100);
  pcVar6 = acStack_40c;
  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pcVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    pcVar6 = pcVar6 + 4;
  }
  uVar3 = 0;
  do {
    if (acStack_40c[uVar3] == '\0') {
      if (uVar3 != 0) {
        dVar7 = _atof(acStack_40c);
        return (float10)dVar7;
      }
      break;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  return (float10)0.0;
}


// ==== FUN_00628840 @ 0x00628840 ====

int FUN_00628840(undefined4 param_1)

{
  float fVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  char *pcVar7;
  double dVar8;
  char acStack_40c [256];
  undefined1 auStack_30c [260];
  undefined1 local_208 [516];
  
  FUN_0044a580(acStack_40c + 4,&DAT_009cf680,param_1);
  FUN_00628280(acStack_40c + 4);
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x100) + 0x30))(local_208);
  if (piVar2 == (int *)0x0) {
    auStack_30c[0] = 0;
    uVar3 = FUN_0044a580(auStack_30c,s___ASSERT___Cannot_Find__s_in_for_009cf7a4,param_1);
    FUN_00797b80(uVar3);
    auStack_30c[0] = 0;
    uVar3 = FUN_0044a580(auStack_30c,s_File___s__Line___d_009cf7f0,
                         s___Support_Config_Provider_cpp_009cf7d0,0x183);
    FUN_00797b80(uVar3);
    FUN_00797a40();
  }
  puVar6 = (undefined4 *)(*piVar2 + 0x100);
  pcVar7 = acStack_40c;
  for (iVar5 = 0x40; iVar5 != 0; iVar5 = iVar5 + -1) {
    *(undefined4 *)pcVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    pcVar7 = pcVar7 + 4;
  }
  uVar4 = 0;
  do {
    if (acStack_40c[uVar4] == '\0') {
      if (uVar4 != 0) {
        dVar8 = _atof(acStack_40c);
        fVar1 = (float)dVar8;
        goto LAB_0062892a;
      }
      break;
    }
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  fVar1 = 0.0;
LAB_0062892a:
  return (int)ROUND(fVar1);
}


// ==== FUN_00628960 @ 0x00628960 ====

int FUN_00628960(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  char *pcVar6;
  double dVar7;
  char acStack_40c [256];
  undefined1 auStack_30c [260];
  undefined1 local_208 [516];
  
  FUN_0044a580(acStack_40c + 4,&DAT_009cf680,param_1);
  FUN_00628280(acStack_40c + 4);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x100) + 0x30))(local_208);
  if (piVar1 == (int *)0x0) {
    auStack_30c[0] = 0;
    uVar2 = FUN_0044a580(auStack_30c,s___ASSERT___Cannot_Find__s_in_for_009cf804,param_1);
    FUN_00797b80(uVar2);
    auStack_30c[0] = 0;
    uVar2 = FUN_0044a580(auStack_30c,s_File___s__Line___d_009cf850,
                         s___Support_Config_Provider_cpp_009cf830,0x183);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  puVar5 = (undefined4 *)(*piVar1 + 0x100);
  pcVar6 = acStack_40c;
  for (iVar4 = 0x40; iVar4 != 0; iVar4 = iVar4 + -1) {
    *(undefined4 *)pcVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    pcVar6 = pcVar6 + 4;
  }
  uVar3 = 0;
  do {
    if (acStack_40c[uVar3] == '\0') {
      if (uVar3 == 0) {
        return 0;
      }
      dVar7 = _atof(acStack_40c);
      return (int)dVar7;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  return 0;
}


// ==== FUN_00628a70 @ 0x00628a70 ====

void FUN_00628a70(byte param_1)

{
  void *in_ECX;
  
  FUN_006282e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00628a90 @ 0x00628a90 ====

void FUN_00628a90(byte param_1)

{
  void *in_ECX;
  
  FUN_00628ab0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00628ab0 @ 0x00628ab0 ====

void FUN_00628ab0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989e43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cf920;
  local_4 = 1;
  if ((void *)in_ECX[0x87] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cf904;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20c,1,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cf87c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x87]);
  return;
}


// ==== FUN_00628b40 @ 0x00628b40 ====

void FUN_00628b40(byte param_1)

{
  void *in_ECX;
  
  FUN_00627720();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00628b60 @ 0x00628b60 ====

void FUN_00628b60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cf9a8;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,1,FUN_006ef6d0);
  return;
}


// ==== FUN_00628b80 @ 0x00628b80 ====

void FUN_00628b80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989e63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cf9b0;
  local_4 = 1;
  if ((void *)in_ECX[0xc] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cf9a8;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,1,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cf8ec;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xc]);
  return;
}


// ==== FUN_00628c00 @ 0x00628c00 ====

undefined4 FUN_00628c00(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cf938,0xa9);
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


// ==== FUN_00628c80 @ 0x00628c80 ====

undefined4 * FUN_00628c80(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cf938,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x34);
  *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x30);
    *(undefined4 **)(in_ECX + 0x30) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x34) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_00628d30 @ 0x00628d30 ====

void FUN_00628d30(byte param_1)

{
  void *in_ECX;
  
  FUN_00628b60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00628d50 @ 0x00628d50 ====

void FUN_00628d50(byte param_1)

{
  void *in_ECX;
  
  FUN_00628b80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00628d70 @ 0x00628d70 ====

void FUN_00628d70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989e78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cf9b0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cf9a8;
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


// ==== FUN_00628df0 @ 0x00628df0 ====

void FUN_00628df0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989e98;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cf9cc;
  FUN_00628d70();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00628e50 @ 0x00628e50 ====

void FUN_00628e50(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00628e70(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00628e70 @ 0x00628e70 ====

void FUN_00628e70(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00628e70(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00628e70(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00628eb0 @ 0x00628eb0 ====

void FUN_00628eb0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00628ed0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00628ed0 @ 0x00628ed0 ====

void FUN_00628ed0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00628ed0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00628ed0(param_1[3]);
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


// ==== FUN_00628f40 @ 0x00628f40 ====

undefined4 * FUN_00628f40(void)

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
  iVar4 = FUN_00472fe0(iVar1,*puVar2);
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
        goto LAB_00628fd9;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
LAB_00628fd9:
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_00472fe0(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_00628ff0 @ 0x00628ff0 ====

void FUN_00628ff0(byte param_1)

{
  void *in_ECX;
  
  FUN_00629010();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629010 @ 0x00629010 ====

void FUN_00629010(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00989ec3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cf9cc;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00628ed0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00628b80();
  *in_ECX = &PTR_FUN_009cf894;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00629080 @ 0x00629080 ====

void FUN_00629080(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfa24;
  return;
}


// ==== FUN_00629090 @ 0x00629090 ====

void FUN_00629090(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfa24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006290b0 @ 0x006290b0 ====

void FUN_006290b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfa24;
  return;
}


// ==== FUN_006290c0 @ 0x006290c0 ====

void FUN_006290c0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  return;
}


// ==== FUN_006290e0 @ 0x006290e0 ====

int FUN_006290e0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_006290f0 @ 0x006290f0 ====

void FUN_006290f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989ed8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfa34;
  FUN_00797a50(in_ECX + 1,0,8);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00629140 @ 0x00629140 ====

void FUN_00629140(byte param_1)

{
  void *in_ECX;
  
  FUN_006290b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629160 @ 0x00629160 ====

void FUN_00629160(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfa44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629180 @ 0x00629180 ====

void FUN_00629180(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfa44;
  return;
}


// ==== FUN_00629190 @ 0x00629190 ====

int FUN_00629190(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_006291a0 @ 0x006291a0 ====

void FUN_006291a0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  return;
}


// ==== FUN_006291c0 @ 0x006291c0 ====

void FUN_006291c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfa54;
  return;
}


// ==== FUN_006291d0 @ 0x006291d0 ====

void FUN_006291d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00629180();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006291f0 @ 0x006291f0 ====

void FUN_006291f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfa9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629210 @ 0x00629210 ====

void FUN_00629210(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfa9c;
  return;
}


// ==== FUN_00629220 @ 0x00629220 ====

void FUN_00629220(undefined4 *param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_00797a50((undefined4 *)(in_ECX + 4),0,4);
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_2;
  return;
}


// ==== FUN_00629250 @ 0x00629250 ====

undefined4 FUN_00629250(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00629260 @ 0x00629260 ====

int FUN_00629260(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00629270 @ 0x00629270 ====

void FUN_00629270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfab0;
  return;
}


// ==== FUN_00629280 @ 0x00629280 ====

void FUN_00629280(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00629290 @ 0x00629290 ====

bool FUN_00629290(int *param_1)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined1 auStack_100 [256];
  
  piVar3 = (int *)(**(code **)(*param_1 + 0xc4))();
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 4))();
  cVar2 = *(char *)(iVar4 + 8);
  piVar5 = (int *)(**(code **)(*piVar3 + 0x14))();
  cVar1 = (**(code **)(*piVar5 + 0x10))();
  if ((cVar2 == '\x01') || (cVar2 == '\x03')) {
    return cVar2 == cVar1;
  }
  if (cVar2 == '\x04') {
    iVar4 = (**(code **)(*piVar3 + 0xc))();
    iVar4 = iVar4 + 0x200;
    piVar3 = (int *)(**(code **)(*DAT_00b5aaf8 + 8))(*(undefined4 *)(in_ECX + 4));
    piVar3 = (int *)(**(code **)(*piVar3 + 0xc))();
    (**(code **)(*piVar3 + 4))(iVar4);
    cVar2 = FUN_00629390(iVar4);
    return cVar2 != '\0';
  }
  auStack_100[0] = 0;
  uVar6 = FUN_0044a580(auStack_100,s_File___s__Line___d_009cfa84,
                       s___Siege_Location_Provider_cpp_009cfa64,0x5e);
  FUN_00797b80(uVar6);
  FUN_00797a40();
  return false;
}


// ==== FUN_00629370 @ 0x00629370 ====

void FUN_00629370(byte param_1)

{
  void *in_ECX;
  
  FUN_00629210();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629390 @ 0x00629390 ====

undefined4 FUN_00629390(int param_1)

{
  char *in_ECX;
  uint uVar1;
  
  uVar1 = 0;
  param_1 = param_1 - (int)in_ECX;
  while( true ) {
    if (*in_ECX != in_ECX[param_1]) {
      return 0;
    }
    if (*in_ECX == '\0') break;
    uVar1 = uVar1 + 1;
    in_ECX = in_ECX + 1;
    if (0x20 < uVar1) {
      return 1;
    }
  }
  return 1;
}


// ==== FUN_006293d0 @ 0x006293d0 ====

void FUN_006293d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfac4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006293f0 @ 0x006293f0 ====

void FUN_006293f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfac4;
  return;
}


// ==== FUN_00629400 @ 0x00629400 ====

int FUN_00629400(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00629410 @ 0x00629410 ====

void FUN_00629410(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00629420 @ 0x00629420 ====

undefined4 FUN_00629420(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00629430 @ 0x00629430 ====

undefined4 FUN_00629430(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00629440 @ 0x00629440 ====

void FUN_00629440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfadc;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_00629460 @ 0x00629460 ====

void FUN_00629460(undefined4 *param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = param_2;
  return;
}


// ==== FUN_00629480 @ 0x00629480 ====

void FUN_00629480(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_00629490 @ 0x00629490 ====

void FUN_00629490(byte param_1)

{
  void *in_ECX;
  
  FUN_006293f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006294b0 @ 0x006294b0 ====

void FUN_006294b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfb00;
  return;
}


// ==== FUN_006294c0 @ 0x006294c0 ====

void FUN_006294c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfb00;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006294e0 @ 0x006294e0 ====

int FUN_006294e0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_006294f0 @ 0x006294f0 ====

int FUN_006294f0(void)

{
  int in_ECX;
  
  return in_ECX + 0x54;
}


// ==== FUN_00629500 @ 0x00629500 ====

void FUN_00629500(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x54) = 0;
  return;
}


// ==== FUN_00629510 @ 0x00629510 ====

void FUN_00629510(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x54) = 3;
  return;
}


// ==== FUN_00629520 @ 0x00629520 ====

void FUN_00629520(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x54) = 2;
  return;
}


// ==== FUN_00629540 @ 0x00629540 ====

void FUN_00629540(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfb00;
  return;
}


// ==== FUN_00629550 @ 0x00629550 ====

undefined4 FUN_00629550(uint param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(*DAT_00b5adb4 + 4))();
  uVar1 = *(int *)(in_ECX + 0x50) + *(int *)(iVar2 + 0x3c) * 1000;
  *param_2 = uVar1 - param_1;
  return CONCAT31((int3)(uVar1 >> 8),uVar1 <= param_1);
}


// ==== FUN_00629590 @ 0x00629590 ====

void FUN_00629590(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989ef8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfb2c;
  *(undefined1 *)(in_ECX + 4) = 0;
  local_4 = 0;
  *(undefined1 *)((int)in_ECX + 0x31) = 0;
  FUN_00797a50(in_ECX + 1,0,0x50);
  in_ECX[0x15] = 3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006295f0 @ 0x006295f0 ====

void FUN_006295f0(int param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int in_ECX;
  uint uVar4;
  
  pcVar1 = (char *)(in_ECX + 0x10);
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[param_1 - (int)pcVar1];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') goto LAB_00629617;
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x21);
  *pcVar1 = '\0';
LAB_00629617:
  pcVar1 = (char *)(in_ECX + 0x31);
  *(undefined4 *)(in_ECX + 0xc) = param_2;
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[param_3 - (int)pcVar1];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') goto LAB_00629647;
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x19);
  *pcVar1 = '\0';
LAB_00629647:
  *(undefined4 *)(in_ECX + 0x4c) = param_4;
  *(undefined4 *)(in_ECX + 0x50) = param_5;
  *(undefined4 *)(in_ECX + 0x54) = 1;
  return;
}


// ==== FUN_00629670 @ 0x00629670 ====

void FUN_00629670(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00629750(param_1);
  *(undefined4 *)(in_ECX + 0x54) = 3;
  return;
}


// ==== FUN_00629690 @ 0x00629690 ====

void FUN_00629690(void)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int in_ECX;
  uint uVar4;
  char local_21 [33];
  
  FUN_0050cd30(local_21,&DAT_009cfaf4,&DAT_009cfaf1);
  pcVar1 = (char *)(in_ECX + 0x10);
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[(int)(local_21 + -(int)pcVar1)];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') goto LAB_006296d6;
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x21);
  *pcVar1 = '\0';
LAB_006296d6:
  *(undefined4 *)(in_ECX + 0xc) = 0;
  FUN_0047aa30(local_21,&DAT_009cfaf8,&DAT_009cfaf2);
  pcVar1 = (char *)(in_ECX + 0x31);
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[(int)(local_21 + -(int)pcVar1)];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') goto LAB_00629716;
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x19);
  *pcVar1 = '\0';
LAB_00629716:
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  return;
}


// ==== FUN_00629730 @ 0x00629730 ====

void FUN_00629730(byte param_1)

{
  void *in_ECX;
  
  FUN_00629540();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629750 @ 0x00629750 ====

void FUN_00629750(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0xc);
    *(char *)(uVar2 + 0xc + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0062978d;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x21);
  *(undefined1 *)(in_ECX + 6) = 0;
LAB_0062978d:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x2d);
    *(char *)(uVar2 + 0x2d + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_006297a8;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)((int)in_ECX + 0x2d) = 0;
LAB_006297a8:
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x26) = *(undefined4 *)(param_1 + 0x26);
  return;
}


// ==== FUN_006297c0 @ 0x006297c0 ====

void FUN_006297c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfb58;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006297e0 @ 0x006297e0 ====

void FUN_006297e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfb58;
  return;
}


// ==== FUN_006297f0 @ 0x006297f0 ====

void FUN_006297f0(void)

{
  return;
}


// ==== FUN_00629800 @ 0x00629800 ====

int FUN_00629800(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00629810 @ 0x00629810 ====

void FUN_00629810(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x46) = param_1;
  return;
}


// ==== FUN_00629820 @ 0x00629820 ====

undefined1 FUN_00629820(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x46);
}


// ==== FUN_00629830 @ 0x00629830 ====

void FUN_00629830(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfb58;
  return;
}


// ==== FUN_00629840 @ 0x00629840 ====

void FUN_00629840(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989f18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfb64;
  *(undefined1 *)(in_ECX + 1) = 0;
  local_4 = 0;
  *(undefined1 *)((int)in_ECX + 0x25) = 0;
  FUN_00797a50(in_ECX + 1,0,0x42);
  *(undefined1 *)((int)in_ECX + 0x46) = 9;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006298a0 @ 0x006298a0 ====

void FUN_006298a0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_006298e0(param_1);
  *(undefined1 *)(in_ECX + 0x46) = 9;
  return;
}


// ==== FUN_006298c0 @ 0x006298c0 ====

void FUN_006298c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00629830();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006298e0 @ 0x006298e0 ====

void FUN_006298e0(int param_1)

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
    if (cVar1 == '\0') goto LAB_00629909;
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0x21);
  *in_ECX = '\0';
LAB_00629909:
  uVar3 = 0;
  do {
    cVar1 = *(char *)(uVar3 + 0x21 + param_1);
    in_ECX[uVar3 + 0x21] = cVar1;
    if (cVar1 == '\0') goto LAB_00629928;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x19);
  in_ECX[0x21] = '\0';
LAB_00629928:
  *(undefined2 *)(in_ECX + 0x3a) = *(undefined2 *)(param_1 + 0x3a);
  *(undefined2 *)(in_ECX + 0x3c) = *(undefined2 *)(param_1 + 0x3c);
  *(undefined2 *)(in_ECX + 0x3e) = *(undefined2 *)(param_1 + 0x3e);
  in_ECX[0x40] = *(char *)(param_1 + 0x40);
  return;
}


// ==== FUN_00629950 @ 0x00629950 ====

void FUN_00629950(void)

{
  return;
}


// ==== FUN_00629960 @ 0x00629960 ====

int FUN_00629960(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_00629970 @ 0x00629970 ====

void FUN_00629970(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfb58;
  return;
}


// ==== FUN_00629980 @ 0x00629980 ====

void FUN_00629980(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfb78;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 0x25) = 0;
  return;
}


// ==== FUN_006299a0 @ 0x006299a0 ====

void FUN_006299a0(void)

{
  FUN_006298e0();
  return;
}


// ==== FUN_006299b0 @ 0x006299b0 ====

void FUN_006299b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00629970();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006299d0 @ 0x006299d0 ====

void FUN_006299d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfb84;
  return;
}


// ==== FUN_006299e0 @ 0x006299e0 ====

void FUN_006299e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfb84;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629a00 @ 0x00629a00 ====

void FUN_00629a00(void)

{
  return;
}


// ==== FUN_00629a10 @ 0x00629a10 ====

void FUN_00629a10(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989f38;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cfc34;
  local_4 = 0;
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))();
  if (piVar1 != (int *)0x0) {
    do {
      (**(code **)(*DAT_00b5b018 + 0xc))(*(undefined4 *)(*piVar1 + 4));
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x48))(piVar1);
    } while (piVar1 != (int *)0x0);
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009cfb84;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00629ab0 @ 0x00629ab0 ====

void FUN_00629ab0(void)

{
  int *piVar1;
  int in_ECX;
  
  for (piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar1)) {
    (**(code **)(*DAT_00b5b018 + 0xc))(*(undefined4 *)(*piVar1 + 4));
  }
                    /* WARNING: Could not recover jumptable at 0x00629ae9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_00629af0 @ 0x00629af0 ====

undefined4 FUN_00629af0(undefined2 param_1)

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


// ==== FUN_00629b20 @ 0x00629b20 ====

void FUN_00629b20(undefined2 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined2 local_8 [4];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*DAT_00b5b018 + 0xc))(*(undefined4 *)(*piVar1 + 4));
    (**(code **)(**(int **)(in_ECX + 8) + 0x40))(piVar1);
  }
  return;
}


// ==== FUN_00629b70 @ 0x00629b70 ====

undefined4 FUN_00629b70(void)

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


// ==== FUN_00629b90 @ 0x00629b90 ====

undefined4 FUN_00629b90(void)

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


// ==== FUN_00629bc0 @ 0x00629bc0 ====

uint FUN_00629bc0(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int *unaff_EBX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  puVar2 = (undefined2 *)(**(code **)(*unaff_EBX + 4))();
  *puVar1 = *puVar2;
  *(int **)(puVar1 + 2) = unaff_EBX;
  iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar1);
  if (iVar3 == 0) {
    return 1;
  }
  uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,puVar1);
  return uVar4 & 0xffffff00;
}


// ==== FUN_00629c20 @ 0x00629c20 ====

void FUN_00629c20(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00989f60;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfc34;
  pvVar1 = operator_new(0xb8);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00629db0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x10c);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0062a3c0(in_ECX[1]);
  }
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00629cc0 @ 0x00629cc0 ====

void FUN_00629cc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfbac;
  return;
}


// ==== FUN_00629cd0 @ 0x00629cd0 ====

void FUN_00629cd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfc04;
  return;
}


// ==== FUN_00629ce0 @ 0x00629ce0 ====

void FUN_00629ce0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfc1c;
  return;
}


// ==== FUN_00629cf0 @ 0x00629cf0 ====

void FUN_00629cf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfbac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629d10 @ 0x00629d10 ====

void FUN_00629d10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfc04;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629d30 @ 0x00629d30 ====

void FUN_00629d30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfc1c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629d50 @ 0x00629d50 ====

void FUN_00629d50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfc58;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,8,FUN_006ef6d0);
  return;
}


// ==== FUN_00629d70 @ 0x00629d70 ====

void FUN_00629d70(byte param_1)

{
  void *in_ECX;
  
  FUN_00629d50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629d90 @ 0x00629d90 ====

void FUN_00629d90(byte param_1)

{
  void *in_ECX;
  
  FUN_00629a10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629db0 @ 0x00629db0 ====

void FUN_00629db0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989f78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfc60;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cfc58;
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


// ==== FUN_00629e90 @ 0x00629e90 ====

undefined4 FUN_00629e90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xac);
}


// ==== FUN_00629ea0 @ 0x00629ea0 ====

void FUN_00629ea0(byte param_1)

{
  void *in_ECX;
  
  FUN_00629ec0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00629ec0 @ 0x00629ec0 ====

void FUN_00629ec0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989fa3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfc60;
  local_4 = 1;
  if ((void *)in_ECX[0x2c] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cfc58;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,8,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cfc04;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x2c]);
  return;
}


// ==== FUN_00629f40 @ 0x00629f40 ====

void * FUN_00629f40(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00989fbb;
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
                           s_d__usa_24_0_1_2__develop_share_l_009cfc78,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0062a020 @ 0x0062a020 ====

undefined4 FUN_0062a020(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cfc78,0xa9);
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


// ==== FUN_0062a0a0 @ 0x0062a0a0 ====

void FUN_0062a0a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfce8;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,8,FUN_006ef6d0);
  return;
}


// ==== FUN_0062a0c0 @ 0x0062a0c0 ====

void FUN_0062a0c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989fe3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfcf0;
  local_4 = 1;
  if ((void *)in_ECX[0x3c] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cfce8;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,8,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cfc1c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x3c]);
  return;
}


// ==== FUN_0062a140 @ 0x0062a140 ====

undefined4 FUN_0062a140(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xec);
}


// ==== FUN_0062a150 @ 0x0062a150 ====

undefined4 FUN_0062a150(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cfc78,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x18);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x18);
    }
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(in_ECX + 0xf4);
    *(int *)(in_ECX + 0xec) = *(int *)(in_ECX + 0xec) + -1;
    *(int *)(in_ECX + 0xf4) = param_2;
  }
  return 0;
}


// ==== FUN_0062a1d0 @ 0x0062a1d0 ====

undefined4 * FUN_0062a1d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[6] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cfc78,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[6] = param_2[6] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xf4);
  *(int *)(in_ECX + 0xec) = *(int *)(in_ECX + 0xec) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x1c);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[5] = *(undefined4 *)(in_ECX + 0xf0);
    *(undefined4 **)(in_ECX + 0xf0) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0xf4) = puVar2[4];
  }
  puVar2[4] = 0;
  puVar2[6] = param_1;
  return puVar2;
}


// ==== FUN_0062a290 @ 0x0062a290 ====

void FUN_0062a290(byte param_1)

{
  void *in_ECX;
  
  FUN_0062a0a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062a2b0 @ 0x0062a2b0 ====

void FUN_0062a2b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062a0c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062a2d0 @ 0x0062a2d0 ====

void FUN_0062a2d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989ff8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfcf0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cfce8;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x1c,8,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x3a] = 0;
  in_ECX[0x3a] = in_ECX[0x3a] + 8;
  in_ECX[0x3b] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = in_ECX + 2;
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
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062a3c0 @ 0x0062a3c0 ====

void FUN_0062a3c0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a018;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfd0c;
  FUN_0062a2d0();
  in_ECX[3] = param_1;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062a420 @ 0x0062a420 ====

undefined4 FUN_0062a420(int param_1)

{
  return *(undefined4 *)(param_1 + 8);
}


// ==== FUN_0062a430 @ 0x0062a430 ====

undefined4 FUN_0062a430(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}


// ==== FUN_0062a440 @ 0x0062a440 ====

undefined4 FUN_0062a440(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(param_1 + 8);
  FUN_0063f470(param_1);
  (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
  return uVar1;
}


// ==== FUN_0062a470 @ 0x0062a470 ====

void FUN_0062a470(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  if (*(undefined4 **)(in_ECX + 4) != (undefined4 *)0x0) {
    puVar2 = *(undefined4 **)(in_ECX + 4);
    do {
      puVar1 = (undefined4 *)puVar2[2];
      FUN_0044e4f0(*puVar2);
      (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,puVar2);
      puVar2 = puVar1;
    } while (puVar1 != (undefined4 *)0x0);
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_0062a4b0 @ 0x0062a4b0 ====

undefined4 FUN_0062a4b0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)(in_ECX + 0x14) + 0xc))(1,0);
  *puVar1 = unaff_ESI;
  puVar1[2] = 0;
  puVar1[3] = *(undefined4 *)(in_ECX + 8);
  if (*(int *)(in_ECX + 8) == 0) {
    *(undefined4 **)(in_ECX + 4) = puVar1;
    *(undefined4 **)(in_ECX + 8) = puVar1;
    return 0;
  }
  *(undefined4 **)(*(int *)(in_ECX + 8) + 8) = puVar1;
  *(undefined4 **)(in_ECX + 8) = puVar1;
  return 0;
}


// ==== FUN_0062a500 @ 0x0062a500 ====

void FUN_0062a500(undefined4 *param_1)

{
  void *_Memory;
  int *in_ECX;
  
  _Memory = (void *)*param_1;
  if ((int *)in_ECX[3] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[3] + 0x10))(1,_Memory);
    (**(code **)(*in_ECX + 0x3c))(param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*in_ECX + 0x3c))(param_1);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0062a550 @ 0x0062a550 ====

undefined4 * FUN_0062a550(ushort *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if (puVar1 != (undefined4 *)0x0) {
    do {
      if ((*(ushort *)*puVar1 <= *param_1) && (*param_1 <= *(ushort *)*puVar1)) {
        return puVar1;
      }
      puVar1 = (undefined4 *)puVar1[2];
    } while (puVar1 != (undefined4 *)0x0);
  }
  return (undefined4 *)0x0;
}


// ==== FUN_0062a590 @ 0x0062a590 ====

undefined4 * FUN_0062a590(ushort *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  if (puVar1 != (undefined4 *)0x0) {
    do {
      if ((*(ushort *)*puVar1 <= *param_1) && (*param_1 <= *(ushort *)*puVar1)) {
        return puVar1;
      }
      puVar1 = (undefined4 *)puVar1[3];
    } while (puVar1 != (undefined4 *)0x0);
  }
  return (undefined4 *)0x0;
}


// ==== FUN_0062a5c0 @ 0x0062a5c0 ====

void FUN_0062a5c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062a5e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062a5e0 @ 0x0062a5e0 ====

void FUN_0062a5e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098a043;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfd0c;
  local_4 = 1;
  FUN_0062a470();
  local_4 = local_4 & 0xffffff00;
  FUN_0062a0c0();
  *in_ECX = &PTR_FUN_009cfbac;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062a640 @ 0x0062a640 ====

void FUN_0062a640(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfd64;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062a660 @ 0x0062a660 ====

void FUN_0062a660(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x20);
  return;
}


// ==== FUN_0062a680 @ 0x0062a680 ====

void FUN_0062a680(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  for (iVar1 = 8; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_ECX = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_0062a6a0 @ 0x0062a6a0 ====

void FUN_0062a6a0(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0x20);
  return;
}


// ==== FUN_0062a6c0 @ 0x0062a6c0 ====

int FUN_0062a6c0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062a6d0 @ 0x0062a6d0 ====

void FUN_0062a6d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfd64;
  return;
}


// ==== FUN_0062a6e0 @ 0x0062a6e0 ====

void FUN_0062a6e0(byte param_1,undefined2 param_2)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4 + (uint)param_1 * 2) = param_2;
  return;
}


// ==== FUN_0062a700 @ 0x0062a700 ====

void FUN_0062a700(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfd80;
  return;
}


// ==== FUN_0062a710 @ 0x0062a710 ====

void FUN_0062a710(byte param_1)

{
  void *in_ECX;
  
  FUN_0062a6d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062a730 @ 0x0062a730 ====

void FUN_0062a730(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfd9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062a750 @ 0x0062a750 ====

void FUN_0062a750(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0xa0);
  return;
}


// ==== FUN_0062a770 @ 0x0062a770 ====

void FUN_0062a770(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  for (iVar1 = 0x28; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_ECX = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_0062a790 @ 0x0062a790 ====

void FUN_0062a790(void)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4,0,0xa0);
  return;
}


// ==== FUN_0062a7b0 @ 0x0062a7b0 ====

int FUN_0062a7b0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062a7c0 @ 0x0062a7c0 ====

void FUN_0062a7c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfd9c;
  return;
}


// ==== FUN_0062a7d0 @ 0x0062a7d0 ====

void FUN_0062a7d0(byte param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(in_ECX + 4 + (uint)param_1 * 0x14);
  *puVar1 = *param_2;
  puVar1[1] = param_2[1];
  puVar1[2] = param_2[2];
  puVar1[3] = param_2[3];
  puVar1[4] = param_2[4];
  return;
}


// ==== FUN_0062a800 @ 0x0062a800 ====

void FUN_0062a800(byte param_1)

{
  int in_ECX;
  
  FUN_00797a50(in_ECX + 4 + (uint)param_1 * 0x14,0,0x14);
  return;
}


// ==== FUN_0062a820 @ 0x0062a820 ====

void FUN_0062a820(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfdbc;
  return;
}


// ==== FUN_0062a830 @ 0x0062a830 ====

void FUN_0062a830(byte param_1)

{
  void *in_ECX;
  
  FUN_0062a7c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062a850 @ 0x0062a850 ====

void FUN_0062a850(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfddc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062a870 @ 0x0062a870 ====

void FUN_0062a870(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfddc;
  return;
}


// ==== FUN_0062a880 @ 0x0062a880 ====

int FUN_0062a880(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062a890 @ 0x0062a890 ====

void FUN_0062a890(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  *(undefined4 *)(in_ECX + 0x14) = param_1[4];
  return;
}


// ==== FUN_0062a8c0 @ 0x0062a8c0 ====

void FUN_0062a8c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfdec;
  return;
}


// ==== FUN_0062a8d0 @ 0x0062a8d0 ====

void FUN_0062a8d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062a870();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062a8f0 @ 0x0062a8f0 ====

void FUN_0062a8f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfdfc;
  return;
}


// ==== FUN_0062a900 @ 0x0062a900 ====

void FUN_0062a900(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfdfc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062a920 @ 0x0062a920 ====

void FUN_0062a920(void)

{
  return;
}


// ==== FUN_0062a930 @ 0x0062a930 ====

void FUN_0062a930(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0062a935. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_0062a940 @ 0x0062a940 ====

void FUN_0062a940(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0062a945. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_0062a950 @ 0x0062a950 ====

void FUN_0062a950(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0062a955. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x18))();
  return;
}


// ==== FUN_0062a960 @ 0x0062a960 ====

void FUN_0062a960(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a058;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cfeac;
  local_4 = 0;
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))();
  if (piVar1 != (int *)0x0) {
    do {
      (**(code **)(*DAT_00b5abf8 + 8))(*(undefined4 *)(*piVar1 + 4));
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1);
    } while (piVar1 != (int *)0x0);
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009cfdfc;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0062aa00 @ 0x0062aa00 ====

void FUN_0062aa00(void)

{
  int *piVar1;
  int in_ECX;
  
  for (piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar1)) {
    (**(code **)(*DAT_00b5abf8 + 8))(*(undefined4 *)(*piVar1 + 4));
  }
  return;
}


// ==== FUN_0062aa40 @ 0x0062aa40 ====

undefined4 FUN_0062aa40(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (iVar1 == 0) {
    return 0;
  }
  (**(code **)(**(int **)(in_ECX + 8) + 0x40))(iVar1);
  return 1;
}


// ==== __break @ 0x0062aa7d ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_0062aa80 @ 0x0062aa80 ====

undefined4 FUN_0062aa80(void)

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


// ==== FUN_0062aaa0 @ 0x0062aaa0 ====

undefined4 FUN_0062aaa0(void)

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


// ==== FUN_0062aad0 @ 0x0062aad0 ====

undefined4 FUN_0062aad0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_8 [2];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_0062ab10 @ 0x0062ab10 ====

uint FUN_0062ab10(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int *unaff_EBX;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  puVar2 = (undefined4 *)(**(code **)(*unaff_EBX + 8))();
  *puVar1 = *puVar2;
  puVar1[1] = unaff_EBX;
  iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar1);
  if (iVar3 == 0) {
    return 1;
  }
  uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,puVar1);
  return uVar4 & 0xffffff00;
}


// ==== FUN_0062ab60 @ 0x0062ab60 ====

void FUN_0062ab60(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a080;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfeac;
  pvVar1 = operator_new(0x2c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0062acf0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x48);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0062b1f0(in_ECX[1]);
  }
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062ac00 @ 0x0062ac00 ====

void FUN_0062ac00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfe24;
  return;
}


// ==== FUN_0062ac10 @ 0x0062ac10 ====

void FUN_0062ac10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfe7c;
  return;
}


// ==== FUN_0062ac20 @ 0x0062ac20 ====

void FUN_0062ac20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfe94;
  return;
}


// ==== FUN_0062ac30 @ 0x0062ac30 ====

void FUN_0062ac30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfe24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062ac50 @ 0x0062ac50 ====

void FUN_0062ac50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfe7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062ac70 @ 0x0062ac70 ====

void FUN_0062ac70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfe94;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062ac90 @ 0x0062ac90 ====

void FUN_0062ac90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfed4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,1,FUN_006ef6d0);
  return;
}


// ==== FUN_0062acb0 @ 0x0062acb0 ====

void FUN_0062acb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062ac90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062acd0 @ 0x0062acd0 ====

void FUN_0062acd0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062a960();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062acf0 @ 0x0062acf0 ====

void FUN_0062acf0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a098;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfedc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cfed4;
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


// ==== FUN_0062ad70 @ 0x0062ad70 ====

void FUN_0062ad70(byte param_1)

{
  void *in_ECX;
  
  FUN_0062ad90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062ad90 @ 0x0062ad90 ====

void FUN_0062ad90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a0c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfedc;
  local_4 = 1;
  if ((void *)in_ECX[9] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cfed4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,1,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cfe7c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[9]);
  return;
}


// ==== FUN_0062ae10 @ 0x0062ae10 ====

void * FUN_0062ae10(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098a0db;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c8bf8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0062aee0 @ 0x0062aee0 ====

undefined4 FUN_0062aee0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8bf8,0xa9);
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


// ==== FUN_0062af60 @ 0x0062af60 ====

void FUN_0062af60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfef4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,1,FUN_006ef6d0);
  return;
}


// ==== FUN_0062af80 @ 0x0062af80 ====

void FUN_0062af80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a103;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfefc;
  local_4 = 1;
  if ((void *)in_ECX[0xc] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cfef4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,1,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cfe94;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xc]);
  return;
}


// ==== FUN_0062b000 @ 0x0062b000 ====

undefined4 FUN_0062b000(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8bf8,0xa9);
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


// ==== FUN_0062b080 @ 0x0062b080 ====

undefined4 * FUN_0062b080(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8bf8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x34);
  *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x30);
    *(undefined4 **)(in_ECX + 0x30) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x34) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_0062b130 @ 0x0062b130 ====

void FUN_0062b130(byte param_1)

{
  void *in_ECX;
  
  FUN_0062af60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062b150 @ 0x0062b150 ====

void FUN_0062b150(byte param_1)

{
  void *in_ECX;
  
  FUN_0062af80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062b170 @ 0x0062b170 ====

void FUN_0062b170(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a118;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cfefc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cfef4;
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


// ==== FUN_0062b1f0 @ 0x0062b1f0 ====

void FUN_0062b1f0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a138;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cff14;
  FUN_0062b170();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062b250 @ 0x0062b250 ====

void FUN_0062b250(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0062b270(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0062b270 @ 0x0062b270 ====

void FUN_0062b270(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0062b270(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0062b270(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0062b2b0 @ 0x0062b2b0 ====

void FUN_0062b2b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0062b2d0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0062b2d0 @ 0x0062b2d0 ====

void FUN_0062b2d0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_0062b2d0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_0062b2d0(param_1[3]);
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


// ==== FUN_0062b340 @ 0x0062b340 ====

void FUN_0062b340(byte param_1)

{
  void *in_ECX;
  
  FUN_0062b360();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062b360 @ 0x0062b360 ====

void FUN_0062b360(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_0098a163;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cff14;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_0062b2d0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0062af80();
  *in_ECX = &PTR_FUN_009cfe24;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062b3d0 @ 0x0062b3d0 ====

void FUN_0062b3d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cff6c;
  return;
}


// ==== FUN_0062b3e0 @ 0x0062b3e0 ====

void FUN_0062b3e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cff6c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062b400 @ 0x0062b400 ====

void FUN_0062b400(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cff6c;
  return;
}


// ==== FUN_0062b410 @ 0x0062b410 ====

undefined4 FUN_0062b410(undefined4 *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  uVar1 = param_1[2];
  *(undefined4 *)(in_ECX + 0xc) = uVar1;
  return CONCAT31((int3)((uint)uVar1 >> 8),1);
}


// ==== FUN_0062b430 @ 0x0062b430 ====

int FUN_0062b430(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062b440 @ 0x0062b440 ====

void FUN_0062b440(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a178;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cff7c;
  FUN_00797a50(in_ECX + 1,0,0xc);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062b490 @ 0x0062b490 ====

void FUN_0062b490(byte param_1)

{
  void *in_ECX;
  
  FUN_0062b400();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062b4b0 @ 0x0062b4b0 ====

void FUN_0062b4b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cff8c;
  return;
}


// ==== FUN_0062b4c0 @ 0x0062b4c0 ====

void FUN_0062b4c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cff8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062b4e0 @ 0x0062b4e0 ====

int FUN_0062b4e0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062b4f0 @ 0x0062b4f0 ====

void FUN_0062b4f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a198;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cff9c;
  local_4 = 0;
  FUN_00488120();
  *in_ECX = &PTR_FUN_009cff8c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062b540 @ 0x0062b540 ====

void FUN_0062b540(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a1aa;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cff9c;
  FUN_004880a0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062b590 @ 0x0062b590 ====

undefined2 * FUN_0062b590(undefined2 *param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)(in_ECX + 4);
  *puVar3 = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 2);
    *(char *)(uVar2 + 2 + (int)puVar3) = cVar1;
    if (cVar1 == '\0') goto LAB_0062b5c9;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)(in_ECX + 6) = 0;
LAB_0062b5c9:
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0xe);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x10);
  *(undefined2 *)(in_ECX + 0x28) = param_1[0x12];
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined2 *)(in_ECX + 0x30) = param_1[0x16];
  *(undefined2 *)(in_ECX + 0x32) = param_1[0x17];
  *(undefined2 *)(in_ECX + 0x34) = param_1[0x18];
  *(undefined1 *)(in_ECX + 0x36) = *(undefined1 *)(param_1 + 0x19);
  *(undefined1 *)(in_ECX + 0x37) = *(undefined1 *)((int)param_1 + 0x33);
  *(undefined1 *)(in_ECX + 0x38) = *(undefined1 *)(param_1 + 0x1a);
  *(undefined1 *)(in_ECX + 0x39) = *(undefined1 *)((int)param_1 + 0x35);
  *(undefined1 *)(in_ECX + 0x3a) = *(undefined1 *)(param_1 + 0x1b);
  *(undefined1 *)(in_ECX + 0x3b) = *(undefined1 *)((int)param_1 + 0x37);
  *(undefined1 *)(in_ECX + 0x3c) = *(undefined1 *)(param_1 + 0x1c);
  *(undefined1 *)(in_ECX + 0x3d) = *(undefined1 *)((int)param_1 + 0x39);
  *(undefined1 *)(in_ECX + 0x3e) = *(undefined1 *)(param_1 + 0x1d);
  *(undefined1 *)(in_ECX + 0x3f) = *(undefined1 *)((int)param_1 + 0x3b);
  *(undefined1 *)(in_ECX + 0x40) = *(undefined1 *)(param_1 + 0x1e);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x22);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x24);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x4c);
    *(char *)(uVar2 + 0x4c + (int)puVar3) = cVar1;
    if (cVar1 == '\0') goto LAB_0062b679;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x80);
  *(undefined1 *)(in_ECX + 0x50) = 0;
LAB_0062b679:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0xcc);
    *(char *)(uVar2 + 0xcc + (int)puVar3) = cVar1;
    if (cVar1 == '\0') goto LAB_0062b6a0;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)(in_ECX + 0xd0) = 0;
LAB_0062b6a0:
  *(undefined2 *)(in_ECX + 0xf0) = param_1[0x76];
  *(undefined2 *)(in_ECX + 0xf2) = param_1[0x77];
  *(undefined2 *)(in_ECX + 0xf4) = param_1[0x78];
  *(undefined2 *)(in_ECX + 0xf6) = param_1[0x79];
  *(undefined1 *)(in_ECX + 0xf8) = *(undefined1 *)(param_1 + 0x7a);
  *(undefined1 *)(in_ECX + 0xf9) = *(undefined1 *)((int)param_1 + 0xf5);
  FUN_0062c010(param_1 + 0x7c);
  *(undefined2 *)(in_ECX + 0x29c) = param_1[0x14c];
  *(undefined2 *)(in_ECX + 0x29e) = param_1[0x14d];
  *(undefined4 *)(in_ECX + 0x2a0) = *(undefined4 *)(param_1 + 0x14e);
  *(undefined2 *)(in_ECX + 0x2a4) = param_1[0x150];
  *(undefined2 *)(in_ECX + 0x2a6) = param_1[0x151];
  *(undefined2 *)(in_ECX + 0x2a8) = param_1[0x152];
  *(undefined2 *)(in_ECX + 0x2aa) = param_1[0x153];
  return puVar3;
}


// ==== FUN_0062b770 @ 0x0062b770 ====

void FUN_0062b770(byte param_1)

{
  void *in_ECX;
  
  FUN_0062b4f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062b790 @ 0x0062b790 ====

void FUN_0062b790(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cffac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062b7b0 @ 0x0062b7b0 ====

void FUN_0062b7b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cffac;
  return;
}


// ==== FUN_0062b7c0 @ 0x0062b7c0 ====

int FUN_0062b7c0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062b7d0 @ 0x0062b7d0 ====

void FUN_0062b7d0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  return;
}


// ==== FUN_0062b7f0 @ 0x0062b7f0 ====

void FUN_0062b7f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cffbc;
  return;
}


// ==== FUN_0062b800 @ 0x0062b800 ====

void FUN_0062b800(byte param_1)

{
  void *in_ECX;
  
  FUN_0062b7b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062b820 @ 0x0062b820 ====

void FUN_0062b820(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cffcc;
  return;
}


// ==== FUN_0062b830 @ 0x0062b830 ====

void FUN_0062b830(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cffcc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062b850 @ 0x0062b850 ====

int FUN_0062b850(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062b860 @ 0x0062b860 ====

void FUN_0062b860(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a1c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cffdc;
  local_4 = 0;
  FUN_00488510();
  *in_ECX = &PTR_FUN_009cffcc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062b8b0 @ 0x0062b8b0 ====

void FUN_0062b8b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a1da;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cffdc;
  FUN_00488480();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062b900 @ 0x0062b900 ====

void FUN_0062b900(undefined2 *param_1)

{
  char cVar1;
  int in_ECX;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar2 = (undefined2 *)(in_ECX + 4);
  *puVar2 = *param_1;
  uVar4 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar4 + 2);
    *(char *)(uVar4 + 2 + (int)puVar2) = cVar1;
    if (cVar1 == '\0') goto LAB_0062b938;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x19);
  *(undefined1 *)(in_ECX + 6) = 0;
LAB_0062b938:
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0xe);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0x12);
  *(undefined2 *)(in_ECX + 0x2c) = param_1[0x14];
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(param_1 + 0x16);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(param_1 + 0x18);
  *(undefined2 *)(in_ECX + 0x38) = param_1[0x1a];
  *(undefined4 *)(in_ECX + 0x3c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined1 *)(in_ECX + 0x40) = *(undefined1 *)(param_1 + 0x1e);
  *(undefined1 *)(in_ECX + 0x41) = *(undefined1 *)((int)param_1 + 0x3d);
  *(undefined2 *)(in_ECX + 0x42) = param_1[0x1f];
  *(undefined2 *)(in_ECX + 0x44) = param_1[0x20];
  *(undefined1 *)(in_ECX + 0x46) = *(undefined1 *)(param_1 + 0x21);
  *(undefined1 *)(in_ECX + 0x47) = *(undefined1 *)((int)param_1 + 0x43);
  *(undefined1 *)(in_ECX + 0x48) = *(undefined1 *)(param_1 + 0x22);
  *(undefined1 *)(in_ECX + 0x49) = *(undefined1 *)((int)param_1 + 0x45);
  *(undefined1 *)(in_ECX + 0x4a) = *(undefined1 *)(param_1 + 0x23);
  *(undefined1 *)(in_ECX + 0x4b) = *(undefined1 *)((int)param_1 + 0x47);
  *(undefined1 *)(in_ECX + 0x4c) = *(undefined1 *)(param_1 + 0x24);
  *(undefined1 *)(in_ECX + 0x4d) = *(undefined1 *)((int)param_1 + 0x49);
  *(undefined1 *)(in_ECX + 0x4e) = *(undefined1 *)(param_1 + 0x25);
  *(undefined1 *)(in_ECX + 0x4f) = *(undefined1 *)((int)param_1 + 0x4b);
  uVar4 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar4 + 0x4c);
    *(char *)(uVar4 + 0x4c + (int)puVar2) = cVar1;
    if (cVar1 == '\0') goto LAB_0062b9ed;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x80);
  *(undefined1 *)(in_ECX + 0x50) = 0;
LAB_0062b9ed:
  uVar4 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar4 + 0xcc);
    *(char *)(uVar4 + 0xcc + (int)puVar2) = cVar1;
    if (cVar1 == '\0') goto LAB_0062ba11;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x19);
  *(undefined1 *)(in_ECX + 0xd0) = 0;
LAB_0062ba11:
  *(undefined4 *)(in_ECX + 0xec) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(in_ECX + 0xf0) = *(undefined4 *)(param_1 + 0x76);
  *(undefined4 *)(in_ECX + 0xf4) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(in_ECX + 0xf8) = *(undefined4 *)(param_1 + 0x7a);
  *(undefined2 *)(in_ECX + 0xfc) = param_1[0x7c];
  *(undefined2 *)(in_ECX + 0x104) = param_1[0x80];
  *(undefined2 *)(in_ECX + 0x106) = param_1[0x81];
  *(undefined2 *)(in_ECX + 0x108) = param_1[0x82];
  *(undefined2 *)(in_ECX + 0x10a) = param_1[0x83];
  *(undefined1 *)(in_ECX + 0x10c) = *(undefined1 *)(param_1 + 0x84);
  *(undefined1 *)(in_ECX + 0x10d) = *(undefined1 *)((int)param_1 + 0x109);
  *(undefined4 *)(in_ECX + 0x110) = *(undefined4 *)(param_1 + 0x86);
  *(undefined2 *)(in_ECX + 0x114) = param_1[0x88];
  *(undefined2 *)(in_ECX + 0x116) = param_1[0x89];
  *(undefined2 *)(in_ECX + 0x118) = param_1[0x8a];
  *(undefined2 *)(in_ECX + 0x11a) = param_1[0x8b];
  *(undefined1 *)(in_ECX + 0x11c) = *(undefined1 *)(param_1 + 0x8c);
  puVar5 = (undefined4 *)(param_1 + 0x8e);
  puVar6 = (undefined4 *)(in_ECX + 0x120);
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)(in_ECX + 0x140) = param_1[0x9e];
  puVar5 = (undefined4 *)(param_1 + 0xa0);
  puVar6 = (undefined4 *)(in_ECX + 0x144);
  for (iVar3 = 0x1e; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  *(undefined2 *)(in_ECX + 0x1bc) = param_1[0xdc];
  *(undefined4 *)(in_ECX + 0x1c0) = *(undefined4 *)(param_1 + 0xde);
  *(undefined1 *)(in_ECX + 0x1c4) = *(undefined1 *)(param_1 + 0xe0);
  return;
}


// ==== FUN_0062bb60 @ 0x0062bb60 ====

void FUN_0062bb60(byte param_1)

{
  void *in_ECX;
  
  FUN_0062b860();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062bb80 @ 0x0062bb80 ====

void FUN_0062bb80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cffec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062bba0 @ 0x0062bba0 ====

int FUN_0062bba0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062bbb0 @ 0x0062bbb0 ====

void FUN_0062bbb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cffec;
  return;
}


// ==== FUN_0062bbc0 @ 0x0062bbc0 ====

void FUN_0062bbc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cfffc;
  *(undefined1 *)(in_ECX + 2) = 0;
  return;
}


// ==== FUN_0062bbd0 @ 0x0062bbd0 ====

void FUN_0062bbd0(void)

{
  FUN_0062bc00();
  return;
}


// ==== FUN_0062bbe0 @ 0x0062bbe0 ====

void FUN_0062bbe0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062bbb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062bc00 @ 0x0062bc00 ====

void FUN_0062bc00(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 4);
    *(char *)(uVar2 + 4 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x80);
  *(undefined1 *)(in_ECX + 2) = 0;
  return;
}


// ==== FUN_0062bc40 @ 0x0062bc40 ====

void FUN_0062bc40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d000c;
  return;
}


// ==== FUN_0062bc50 @ 0x0062bc50 ====

void FUN_0062bc50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d000c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062bc70 @ 0x0062bc70 ====

int FUN_0062bc70(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062bc80 @ 0x0062bc80 ====

void FUN_0062bc80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a1f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d001c;
  local_4 = 0;
  FUN_00489350();
  *in_ECX = &PTR_FUN_009d000c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062bcd0 @ 0x0062bcd0 ====

void FUN_0062bcd0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a20a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d001c;
  FUN_004892d0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062bd20 @ 0x0062bd20 ====

undefined2 * FUN_0062bd20(undefined2 *param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)(in_ECX + 4);
  *puVar3 = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 2);
    *(char *)(uVar2 + 2 + (int)puVar3) = cVar1;
    if (cVar1 == '\0') goto LAB_0062bd59;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)(in_ECX + 6) = 0;
LAB_0062bd59:
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(param_1 + 0xe);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x10);
  *(undefined2 *)(in_ECX + 0x28) = param_1[0x12];
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(param_1 + 0x14);
  *(undefined2 *)(in_ECX + 0x30) = param_1[0x16];
  *(undefined2 *)(in_ECX + 0x32) = param_1[0x17];
  *(undefined2 *)(in_ECX + 0x34) = param_1[0x18];
  *(undefined1 *)(in_ECX + 0x36) = *(undefined1 *)(param_1 + 0x19);
  *(undefined1 *)(in_ECX + 0x37) = *(undefined1 *)((int)param_1 + 0x33);
  *(undefined1 *)(in_ECX + 0x38) = *(undefined1 *)(param_1 + 0x1a);
  *(undefined1 *)(in_ECX + 0x39) = *(undefined1 *)((int)param_1 + 0x35);
  *(undefined1 *)(in_ECX + 0x3a) = *(undefined1 *)(param_1 + 0x1b);
  *(undefined1 *)(in_ECX + 0x3b) = *(undefined1 *)((int)param_1 + 0x37);
  *(undefined1 *)(in_ECX + 0x3c) = *(undefined1 *)(param_1 + 0x1c);
  *(undefined1 *)(in_ECX + 0x3d) = *(undefined1 *)((int)param_1 + 0x39);
  *(undefined1 *)(in_ECX + 0x3e) = *(undefined1 *)(param_1 + 0x1d);
  *(undefined1 *)(in_ECX + 0x3f) = *(undefined1 *)((int)param_1 + 0x3b);
  *(undefined1 *)(in_ECX + 0x40) = *(undefined1 *)(param_1 + 0x1e);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x22);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x24);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x4c);
    *(char *)(uVar2 + 0x4c + (int)puVar3) = cVar1;
    if (cVar1 == '\0') goto LAB_0062be09;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x80);
  *(undefined1 *)(in_ECX + 0x50) = 0;
LAB_0062be09:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0xcc);
    *(char *)(uVar2 + 0xcc + (int)puVar3) = cVar1;
    if (cVar1 == '\0') goto LAB_0062be30;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)(in_ECX + 0xd0) = 0;
LAB_0062be30:
  *(undefined2 *)(in_ECX + 0xea) = param_1[0x73];
  *(undefined2 *)(in_ECX + 0xf0) = param_1[0x76];
  *(undefined2 *)(in_ECX + 0xf2) = param_1[0x77];
  *(undefined2 *)(in_ECX + 0xf4) = param_1[0x78];
  *(undefined2 *)(in_ECX + 0xf6) = param_1[0x79];
  *(undefined1 *)(in_ECX + 0xf8) = *(undefined1 *)(param_1 + 0x7a);
  *(undefined1 *)(in_ECX + 0xf9) = *(undefined1 *)((int)param_1 + 0xf5);
  FUN_0062c010(param_1 + 0x7c);
  *(undefined2 *)(in_ECX + 0x29c) = param_1[0x14c];
  *(undefined2 *)(in_ECX + 0x29e) = param_1[0x14d];
  *(undefined4 *)(in_ECX + 0x2a0) = *(undefined4 *)(param_1 + 0x14e);
  *(undefined2 *)(in_ECX + 0x2a4) = param_1[0x150];
  *(undefined2 *)(in_ECX + 0x2a6) = param_1[0x151];
  *(undefined2 *)(in_ECX + 0x2a8) = param_1[0x152];
  return puVar3;
}


// ==== FUN_0062bf00 @ 0x0062bf00 ====

void FUN_0062bf00(byte param_1)

{
  void *in_ECX;
  
  FUN_0062bc80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062bf20 @ 0x0062bf20 ====

void FUN_0062bf20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d002c;
  return;
}


// ==== FUN_0062bf30 @ 0x0062bf30 ====

void FUN_0062bf30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d002c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062bf50 @ 0x0062bf50 ====

int FUN_0062bf50(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062bf60 @ 0x0062bf60 ====

void FUN_0062bf60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a228;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d003c;
  local_4 = 0;
  FUN_00489570();
  *in_ECX = &PTR_FUN_009d002c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062bfb0 @ 0x0062bfb0 ====

void FUN_0062bfb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a23a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d003c;
  FUN_004894f0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062c000 @ 0x0062c000 ====

void FUN_0062c000(void)

{
  FUN_0062c090();
  return;
}


// ==== FUN_0062c010 @ 0x0062c010 ====

int FUN_0062c010(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined2 *puVar3;
  undefined2 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar4 = (undefined2 *)(param_1 + 4);
  puVar3 = (undefined2 *)(in_ECX + 6);
  iVar1 = 8;
  do {
    *(undefined4 *)(puVar3 + -3) = *(undefined4 *)(puVar4 + -2);
    puVar3[-1] = *puVar4;
    *puVar3 = *(undefined2 *)((int)puVar3 + (param_1 - in_ECX));
    puVar3[1] = puVar4[2];
    puVar3[2] = puVar4[3];
    *(undefined1 *)(puVar3 + 3) = *(undefined1 *)(puVar4 + 4);
    *(undefined4 *)(puVar3 + 5) = *(undefined4 *)(puVar4 + 6);
    puVar5 = (undefined4 *)(puVar4 + 8);
    puVar6 = (undefined4 *)(puVar3 + 7);
    puVar4 = puVar4 + 0x1a;
    puVar3 = puVar3 + 0x1a;
    iVar1 = iVar1 + -1;
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
  } while (iVar1 != 0);
  return in_ECX;
}


// ==== FUN_0062c090 @ 0x0062c090 ====

void FUN_0062c090(undefined2 *param_1)

{
  char cVar1;
  uint uVar2;
  undefined2 *in_ECX;
  
  *in_ECX = *param_1;
  *(undefined4 *)(in_ECX + 2) = *(undefined4 *)(param_1 + 2);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 8);
    *(char *)(uVar2 + 8 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0062c0c7;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)(in_ECX + 4) = 0;
LAB_0062c0c7:
  *(undefined4 *)(in_ECX + 0x12) = *(undefined4 *)(param_1 + 0x12);
  *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(param_1 + 0x14);
  in_ECX[0x16] = param_1[0x16];
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x18);
  in_ECX[0x1a] = param_1[0x1a];
  in_ECX[0x1b] = param_1[0x1b];
  in_ECX[0x1c] = param_1[0x1c];
  *(undefined1 *)(in_ECX + 0x1d) = *(undefined1 *)(param_1 + 0x1d);
  *(undefined1 *)((int)in_ECX + 0x3b) = *(undefined1 *)((int)param_1 + 0x3b);
  *(undefined1 *)(in_ECX + 0x1e) = *(undefined1 *)(param_1 + 0x1e);
  *(undefined1 *)((int)in_ECX + 0x3d) = *(undefined1 *)((int)param_1 + 0x3d);
  *(undefined1 *)(in_ECX + 0x1f) = *(undefined1 *)(param_1 + 0x1f);
  *(undefined1 *)((int)in_ECX + 0x3f) = *(undefined1 *)((int)param_1 + 0x3f);
  *(undefined1 *)(in_ECX + 0x20) = *(undefined1 *)(param_1 + 0x20);
  *(undefined1 *)((int)in_ECX + 0x41) = *(undefined1 *)((int)param_1 + 0x41);
  *(undefined1 *)(in_ECX + 0x21) = *(undefined1 *)(param_1 + 0x21);
  *(undefined1 *)((int)in_ECX + 0x43) = *(undefined1 *)((int)param_1 + 0x43);
  *(undefined1 *)(in_ECX + 0x22) = *(undefined1 *)(param_1 + 0x22);
  *(undefined4 *)(in_ECX + 0x24) = *(undefined4 *)(param_1 + 0x24);
  *(undefined4 *)(in_ECX + 0x26) = *(undefined4 *)(param_1 + 0x26);
  *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)(param_1 + 0x28);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x54);
    *(char *)(uVar2 + 0x54 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0062c179;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x80);
  *(undefined1 *)(in_ECX + 0x2a) = 0;
LAB_0062c179:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0xd4);
    *(char *)(uVar2 + 0xd4 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0062c1a0;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)(in_ECX + 0x6a) = 0;
LAB_0062c1a0:
  in_ECX[0x77] = param_1[0x77];
  in_ECX[0x7a] = param_1[0x7a];
  in_ECX[0x7b] = param_1[0x7b];
  in_ECX[0x7c] = param_1[0x7c];
  in_ECX[0x7d] = param_1[0x7d];
  *(undefined1 *)(in_ECX + 0x7e) = *(undefined1 *)(param_1 + 0x7e);
  *(undefined1 *)((int)in_ECX + 0xfd) = *(undefined1 *)((int)param_1 + 0xfd);
  FUN_0062c010(param_1 + 0x80);
  in_ECX[0x150] = param_1[0x150];
  in_ECX[0x151] = param_1[0x151];
  *(undefined4 *)(in_ECX + 0x152) = *(undefined4 *)(param_1 + 0x152);
  in_ECX[0x154] = param_1[0x154];
  in_ECX[0x155] = param_1[0x155];
  in_ECX[0x156] = param_1[0x156];
  return;
}


// ==== FUN_0062c270 @ 0x0062c270 ====

void FUN_0062c270(byte param_1)

{
  void *in_ECX;
  
  FUN_0062bf60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062c290 @ 0x0062c290 ====

void FUN_0062c290(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d004c;
  return;
}


// ==== FUN_0062c2a0 @ 0x0062c2a0 ====

void FUN_0062c2a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d004c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062c2c0 @ 0x0062c2c0 ====

int FUN_0062c2c0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062c2d0 @ 0x0062c2d0 ====

void FUN_0062c2d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a258;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d005c;
  local_4 = 0;
  FUN_0048a3a0();
  *in_ECX = &PTR_FUN_009d004c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062c320 @ 0x0062c320 ====

void FUN_0062c320(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a26a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d005c;
  FUN_0048a310();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062c370 @ 0x0062c370 ====

undefined2 * FUN_0062c370(undefined2 *param_1)

{
  char cVar1;
  uint uVar2;
  int in_ECX;
  undefined2 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar3 = (undefined2 *)(in_ECX + 4);
  *puVar3 = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 2);
    *(char *)(uVar2 + 2 + (int)puVar3) = cVar1;
    if (cVar1 == '\0') goto LAB_0062c3aa;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x40);
  *(undefined1 *)(in_ECX + 6) = 0;
LAB_0062c3aa:
  *(undefined4 *)(in_ECX + 0x48) = *(undefined4 *)(param_1 + 0x22);
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x24);
  *(undefined2 *)(in_ECX + 0x50) = param_1[0x26];
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x28);
  *(undefined2 *)(in_ECX + 0x58) = param_1[0x2a];
  *(undefined2 *)(in_ECX + 0x5a) = param_1[0x2b];
  *(undefined2 *)(in_ECX + 0x5c) = param_1[0x2c];
  *(undefined1 *)(in_ECX + 0x5e) = *(undefined1 *)(param_1 + 0x2d);
  *(undefined1 *)(in_ECX + 0x5f) = *(undefined1 *)((int)param_1 + 0x5b);
  *(undefined1 *)(in_ECX + 0x60) = *(undefined1 *)(param_1 + 0x2e);
  *(undefined1 *)(in_ECX + 0x61) = *(undefined1 *)((int)param_1 + 0x5d);
  *(undefined1 *)(in_ECX + 0x62) = *(undefined1 *)(param_1 + 0x2f);
  *(undefined1 *)(in_ECX + 99) = *(undefined1 *)((int)param_1 + 0x5f);
  *(undefined1 *)(in_ECX + 100) = *(undefined1 *)(param_1 + 0x30);
  *(undefined1 *)(in_ECX + 0x65) = *(undefined1 *)((int)param_1 + 0x61);
  *(undefined1 *)(in_ECX + 0x66) = *(undefined1 *)(param_1 + 0x31);
  *(undefined1 *)(in_ECX + 0x67) = *(undefined1 *)((int)param_1 + 99);
  *(undefined1 *)(in_ECX + 0x68) = *(undefined1 *)(param_1 + 0x32);
  *(undefined4 *)(in_ECX + 0x6c) = *(undefined4 *)(param_1 + 0x34);
  *(undefined4 *)(in_ECX + 0x70) = *(undefined4 *)(param_1 + 0x36);
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(param_1 + 0x38);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x74);
    *(char *)(uVar2 + 0x74 + (int)puVar3) = cVar1;
    if (cVar1 == '\0') goto LAB_0062c459;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x80);
  *(undefined1 *)(in_ECX + 0x78) = 0;
LAB_0062c459:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0xf4);
    *(char *)(uVar2 + 0xf4 + (int)puVar3) = cVar1;
    if (cVar1 == '\0') goto LAB_0062c480;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x40);
  *(undefined1 *)(in_ECX + 0xf8) = 0;
LAB_0062c480:
  *(undefined4 *)(in_ECX + 0x138) = *(undefined4 *)(param_1 + 0x9a);
  *(undefined4 *)(in_ECX + 0x13c) = *(undefined4 *)(param_1 + 0x9c);
  *(undefined4 *)(in_ECX + 0x140) = *(undefined4 *)(param_1 + 0x9e);
  *(undefined4 *)(in_ECX + 0x144) = *(undefined4 *)(param_1 + 0xa0);
  *(undefined2 *)(in_ECX + 0x148) = param_1[0xa2];
  *(undefined2 *)(in_ECX + 0x14a) = param_1[0xa3];
  *(undefined2 *)(in_ECX + 0x150) = param_1[0xa6];
  *(undefined2 *)(in_ECX + 0x152) = param_1[0xa7];
  *(undefined2 *)(in_ECX + 0x154) = param_1[0xa8];
  *(undefined2 *)(in_ECX + 0x156) = param_1[0xa9];
  *(undefined1 *)(in_ECX + 0x158) = *(undefined1 *)(param_1 + 0xaa);
  *(undefined1 *)(in_ECX + 0x159) = *(undefined1 *)((int)param_1 + 0x155);
  FUN_0062c010(param_1 + 0xac);
  *(undefined2 *)(in_ECX + 0x2fc) = param_1[0x17c];
  puVar5 = (undefined4 *)(param_1 + 0x17e);
  puVar6 = (undefined4 *)(in_ECX + 0x300);
  for (iVar4 = 0x1e; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  return puVar3;
}


// ==== FUN_0062c560 @ 0x0062c560 ====

void FUN_0062c560(byte param_1)

{
  void *in_ECX;
  
  FUN_0062c2d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062c580 @ 0x0062c580 ====

void FUN_0062c580(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d006c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062c5a0 @ 0x0062c5a0 ====

int FUN_0062c5a0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062c5b0 @ 0x0062c5b0 ====

void FUN_0062c5b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d006c;
  return;
}


// ==== FUN_0062c5c0 @ 0x0062c5c0 ====

void FUN_0062c5c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d007c;
  *(undefined1 *)(in_ECX + 5) = 0;
  return;
}


// ==== FUN_0062c5d0 @ 0x0062c5d0 ====

void FUN_0062c5d0(void)

{
  FUN_0062c600();
  return;
}


// ==== FUN_0062c5e0 @ 0x0062c5e0 ====

void FUN_0062c5e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062c5b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062c600 @ 0x0062c600 ====

void FUN_0062c600(undefined4 *param_1)

{
  char cVar1;
  undefined4 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x10);
    *(char *)(uVar2 + 0x10 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0062c638;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)(in_ECX + 4) = 0;
LAB_0062c638:
  in_ECX[0xb] = param_1[0xb];
  *(undefined2 *)(in_ECX + 0xc) = *(undefined2 *)(param_1 + 0xc);
  *(undefined1 *)((int)in_ECX + 0x32) = *(undefined1 *)((int)param_1 + 0x32);
  *(undefined1 *)((int)in_ECX + 0x33) = *(undefined1 *)((int)param_1 + 0x33);
  *(undefined1 *)(in_ECX + 0xd) = *(undefined1 *)(param_1 + 0xd);
  *(undefined1 *)((int)in_ECX + 0x35) = *(undefined1 *)((int)param_1 + 0x35);
  *(undefined2 *)((int)in_ECX + 0x36) = *(undefined2 *)((int)param_1 + 0x36);
  *(undefined2 *)(in_ECX + 0xe) = *(undefined2 *)(param_1 + 0xe);
  in_ECX[0xf] = param_1[0xf];
  *(undefined2 *)(in_ECX + 0x10) = *(undefined2 *)(param_1 + 0x10);
  *(undefined2 *)((int)in_ECX + 0x42) = *(undefined2 *)((int)param_1 + 0x42);
  in_ECX[0x11] = param_1[0x11];
  in_ECX[0x12] = param_1[0x12];
  return;
}


// ==== FUN_0062c6a0 @ 0x0062c6a0 ====

void FUN_0062c6a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d008c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062c6c0 @ 0x0062c6c0 ====

int FUN_0062c6c0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0062c6d0 @ 0x0062c6d0 ====

void FUN_0062c6d0(void)

{
  undefined4 *in_ECX;
  
  in_ECX[0x4a] = &PTR_FUN_009a6d44;
  *in_ECX = &PTR_FUN_009d008c;
  return;
}


// ==== FUN_0062c6f0 @ 0x0062c6f0 ====

uint FUN_0062c6f0(char param_1,short param_2)

{
  short *in_EAX;
  int in_ECX;
  uint uVar1;
  
  uVar1 = 0;
  if (*(byte *)(in_ECX + 0x124) != 0) {
    in_EAX = (short *)(in_ECX + 0x12e);
    do {
      if (((char)in_EAX[-1] == param_1) && (*in_EAX == param_2)) {
        return CONCAT31((int3)((uint)in_EAX >> 8),1);
      }
      uVar1 = uVar1 + 1;
      in_EAX = in_EAX + 2;
    } while (uVar1 < *(byte *)(in_ECX + 0x124));
  }
  return (uint)in_EAX & 0xffffff00;
}


// ==== FUN_0062c740 @ 0x0062c740 ====

void FUN_0062c740(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d00a0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  *(undefined1 *)((int)in_ECX + 0x1f) = 0;
  *(undefined1 *)((int)in_ECX + 0x9f) = 0;
  in_ECX[0x4a] = &PTR_FUN_009a6d44;
  in_ECX[0x5f] = 0;
  return;
}


// ==== FUN_0062c770 @ 0x0062c770 ====

void FUN_0062c770(void)

{
  FUN_0062c7a0();
  return;
}


// ==== FUN_0062c780 @ 0x0062c780 ====

void FUN_0062c780(byte param_1)

{
  void *in_ECX;
  
  FUN_0062c6d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062c7a0 @ 0x0062c7a0 ====

void FUN_0062c7a0(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  *in_ECX = *param_1;
  uVar3 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar3 + 2);
    *(char *)(uVar3 + 2 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0062c7cb;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x19);
  *(undefined1 *)(in_ECX + 1) = 0;
LAB_0062c7cb:
  uVar3 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar3 + 0x1b);
    *(char *)(uVar3 + 0x1b + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0062c7ea;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x80);
  *(undefined1 *)((int)in_ECX + 0x1b) = 0;
LAB_0062c7ea:
  uVar3 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar3 + 0x9b);
    *(char *)(uVar3 + 0x9b + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0062c813;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x80);
  *(undefined1 *)((int)in_ECX + 0x9b) = 0;
LAB_0062c813:
  *(undefined1 *)((int)in_ECX + 0x11b) = *(undefined1 *)((int)param_1 + 0x11b);
  *(undefined4 *)(in_ECX + 0x8e) = *(undefined4 *)(param_1 + 0x8e);
  *(undefined1 *)(in_ECX + 0x90) = *(undefined1 *)(param_1 + 0x90);
  puVar2 = (undefined4 *)(in_ECX + 0x94);
  iVar4 = 0x14;
  do {
    *puVar2 = *(undefined4 *)((int)param_1 + (0x124 - (int)(in_ECX + 0x92)) + (int)puVar2);
    puVar2 = puVar2 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  *(undefined4 *)(in_ECX + 0xbc) = *(undefined4 *)(param_1 + 0xbc);
  return;
}


// ==== FUN_0062c870 @ 0x0062c870 ====

void FUN_0062c870(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009d02e4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062c8b0 @ 0x0062c8b0 ====

int FUN_0062c8b0(void)

{
  int in_ECX;
  
  return in_ECX + 0xb2;
}


// ==== FUN_0062c8c0 @ 0x0062c8c0 ====

undefined4 FUN_0062c8c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb4);
}


// ==== FUN_0062c8d0 @ 0x0062c8d0 ====

undefined4 FUN_0062c8d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb8);
}


// ==== FUN_0062c8e0 @ 0x0062c8e0 ====

void FUN_0062c8e0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xb8) = param_1;
  return;
}


// ==== FUN_0062c8f0 @ 0x0062c8f0 ====

undefined4 FUN_0062c8f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xbc);
}


// ==== FUN_0062c900 @ 0x0062c900 ====

void FUN_0062c900(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0062c908. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xbc) + 0x30))();
  return;
}


// ==== FUN_0062c930 @ 0x0062c930 ====

void FUN_0062c930(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a288;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d0300;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x2f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2f])(1);
  }
  in_ECX[0x2f] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0062c9c0 @ 0x0062c9c0 ====

void FUN_0062c9c0(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  
  FUN_00797a50((int)in_ECX + 0xb2,0,2);
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if (*piVar2 != 0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
                    /* WARNING: Could not recover jumptable at 0x0062ca06. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)in_ECX[0x2f] + 0x2c))();
  return;
}


// ==== FUN_0062ca10 @ 0x0062ca10 ====

void FUN_0062ca10(void)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5abc0 + 8))(*(undefined2 *)(in_ECX + 0xb2));
                    /* WARNING: Could not recover jumptable at 0x0062ca2f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xb4) + 4))();
  return;
}


// ==== FUN_0062ca40 @ 0x0062ca40 ====

undefined4 FUN_0062ca40(undefined2 *param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_46 [70];
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x44) + 0x14))();
  piVar2 = (int *)(**(code **)(*DAT_00b5abc0 + 8))(*param_1);
  (**(code **)(*piVar2 + 4))();
  (**(code **)(*piVar1 + 8))(auStack_46 + -6);
  return 1;
}


// ==== FUN_0062cab0 @ 0x0062cab0 ====

undefined4 FUN_0062cab0(undefined2 *param_1)

{
  int in_ECX;
  undefined4 local_8;
  undefined2 local_4;
  
  local_4 = *param_1;
  local_8 = 6;
  (**(code **)(**(int **)(in_ECX + 0x4c) + 0x1c))(&local_8);
  return 1;
}


// ==== FUN_0062cae0 @ 0x0062cae0 ====

void FUN_0062cae0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a2a5;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d0300;
  pvVar1 = operator_new(0x51c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006491d0(in_ECX);
  }
  in_ECX[0x2f] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50(in_ECX + 1,0,0xa8);
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x10,6);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x13,6);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x12,6);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(1);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(3,6);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(4,6);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  FUN_00797a50((int)in_ECX + 0xb2,0,2);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  in_ECX[0x2e] = 0;
  ExceptionList = (void *)0x6;
  return;
}


// ==== FUN_0062cc80 @ 0x0062cc80 ====

undefined4 FUN_0062cc80(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  undefined2 *unaff_retaddr;
  undefined1 local_100 [2];
  undefined1 auStack_fe [254];
  
  piVar2 = *(int **)(in_ECX + 0x50);
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d02dc,s_____EXCEPTION_____NULL_state_man_009d00b4);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009d00fc,
                         s___Creature_Sentry_Provider_cpp_009d00dc,0xda);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))(10);
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d02dc,s_____EXCEPTION_____NULL_state_art_009d0110);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d0158,
                         s___Creature_Sentry_Provider_cpp_009d0138,0xe1);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar3 = *(int **)(in_ECX + 0x44);
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d02dc,s_____EXCEPTION_____NULL_point_man_009d016c);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d01b4,
                         s___Creature_Sentry_Provider_cpp_009d0194,0xe8);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d02dc,s_____EXCEPTION_____NULL_point_art_009d01c8);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d0210,
                         s___Creature_Sentry_Provider_cpp_009d01f0,0xef);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5abc0 + 8))(*unaff_retaddr);
  iVar5 = (**(code **)(*piVar4 + 4))();
  (**(code **)(*piVar2 + 0x6c))((float)*(int *)(iVar5 + 0x28));
  (**(code **)(*piVar2 + 0x8c))(0);
  puVar6 = (undefined4 *)(**(code **)(*piVar2 + 0x18))();
  (**(code **)(*piVar3 + 0x14))(*puVar6);
  iVar5 = *piVar3;
  iVar7 = (**(code **)(*piVar2 + 0x18))();
  (**(code **)(iVar5 + 0x1c))(*(undefined4 *)(iVar7 + 0xc));
  (**(code **)(*piVar3 + 0x34))(0);
  return 1;
}


// ==== FUN_0062ce50 @ 0x0062ce50 ====

undefined4 FUN_0062ce50(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  undefined1 local_100 [256];
  
  piVar3 = (int *)in_ECX[2];
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d02dc,s_____EXCEPTION_____NULL_state_man_009d0224);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d026c,
                         s___Creature_Sentry_Provider_cpp_009d024c,0x10b);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d02dc,s_____EXCEPTION_____NULL_state_art_009d0280);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d02c8,
                         s___Creature_Sentry_Provider_cpp_009d02a8,0x112);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  piVar4 = (int *)(**(code **)(*in_ECX + 0x20))();
  iVar1 = *piVar3;
  iVar5 = (**(code **)(*piVar4 + 4))();
  (**(code **)(iVar1 + 0x14))(*(undefined1 *)(iVar5 + 0x1c));
  return 1;
}


// ==== FUN_0062cf30 @ 0x0062cf30 ====

undefined4 FUN_0062cf30(undefined2 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))(param_1);
  *(undefined2 *)((int)in_ECX + 0xb2) = *param_1;
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  iVar2 = (**(code **)(*DAT_00b5abc0 + 8))(*param_1);
  in_ECX[0x2d] = iVar2;
  if (iVar2 != 0) {
    cVar1 = FUN_0062ca40(param_1);
    if (cVar1 != '\0') {
      cVar1 = FUN_0062cc80(param_1);
      if (cVar1 != '\0') {
        cVar1 = FUN_0062ce50(param_1);
        if (cVar1 != '\0') {
          cVar1 = FUN_0062cab0(param_1);
          if (cVar1 != '\0') {
            iVar2 = *(int *)in_ECX[0x2f];
            uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
            (**(code **)(iVar2 + 0x28))(uVar3);
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_0062cfd0 @ 0x0062cfd0 ====

void FUN_0062cfd0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062c930();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062cff0 @ 0x0062cff0 ====

void FUN_0062cff0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xac) = 0;
  return;
}


// ==== FUN_0062d000 @ 0x0062d000 ====

void FUN_0062d000(void)

{
  return;
}


// ==== FUN_0062d010 @ 0x0062d010 ====

int FUN_0062d010(void)

{
  int in_ECX;
  
  return in_ECX + 0xb2;
}


// ==== FUN_0062d020 @ 0x0062d020 ====

undefined4 FUN_0062d020(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb4);
}


// ==== FUN_0062d030 @ 0x0062d030 ====

undefined4 FUN_0062d030(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xb8);
}


// ==== FUN_0062d040 @ 0x0062d040 ====

void FUN_0062d040(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xb8) = param_1;
  return;
}


// ==== FUN_0062d050 @ 0x0062d050 ====

undefined4 FUN_0062d050(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xbc);
}


// ==== FUN_0062d060 @ 0x0062d060 ====

void FUN_0062d060(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0062d068. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xbc) + 0x30))();
  return;
}


// ==== FUN_0062d0a0 @ 0x0062d0a0 ====

void FUN_0062d0a0(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a2b8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d0584;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x2f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x2f])(1);
  }
  in_ECX[0x2f] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0062d130 @ 0x0062d130 ====

void FUN_0062d130(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  
  FUN_00797a50((int)in_ECX + 0xb2,0,2);
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if (*piVar2 != 0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  (**(code **)(*(int *)in_ECX[0x2e] + 0x10))();
  (**(code **)(*(int *)in_ECX[0x2f] + 0x2c))();
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  return;
}


// ==== FUN_0062d190 @ 0x0062d190 ====

undefined4 FUN_0062d190(undefined2 *param_1)

{
  int in_ECX;
  undefined4 local_8;
  undefined2 local_4;
  
  local_4 = *param_1;
  local_8 = 5;
  (**(code **)(**(int **)(in_ECX + 0x4c) + 0x1c))(&local_8);
  return 1;
}


// ==== FUN_0062d1c0 @ 0x0062d1c0 ====

void FUN_0062d1c0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5abc8 + 8))(*(undefined2 *)(in_ECX + 0xb2));
                    /* WARNING: Could not recover jumptable at 0x0062d1d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 4))();
  return;
}


// ==== FUN_0062d1e0 @ 0x0062d1e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0062d1e0(int param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x44) + 0x14))();
  iVar3 = (**(code **)(*piVar2 + 0xc))();
  fVar1 = (float)param_1;
  if (param_1 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  (**(code **)(*piVar2 + 0x14))(fVar1 + *(float *)(iVar3 + 4));
  return;
}


// ==== FUN_0062d220 @ 0x0062d220 ====

void FUN_0062d220(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a2d5;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d0584;
  pvVar1 = operator_new(0x51c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0064a330(in_ECX);
  }
  in_ECX[0x2f] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50(in_ECX + 1,0,0xa8);
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x10,5);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x13,5);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x12,5);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(1);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(3,5);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(4,5);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  FUN_00797a50((int)in_ECX + 0xb2,0,2);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  in_ECX[0x2e] = 0;
  ExceptionList = (void *)0x5;
  return;
}


// ==== FUN_0062d3c0 @ 0x0062d3c0 ====

undefined4 FUN_0062d3c0(void)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  ushort *puVar4;
  int iVar5;
  int *in_ECX;
  int iVar6;
  int iVar7;
  int *piVar8;
  ushort *unaff_retaddr;
  
  if ((int *)in_ECX[0x13] == (int *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)(**(code **)(*(int *)in_ECX[0x13] + 0x18))();
  }
  puVar4 = (ushort *)(**(code **)(*piVar8 + 0x3c))(0);
  uVar2 = *puVar4;
  uVar3 = puVar4[1];
  iVar5 = (**(code **)(*in_ECX + 0x24))();
  bVar1 = *(byte *)(iVar5 + 0x3c);
  iVar5 = (**(code **)(*in_ECX + 0x24))();
  iVar6 = (uint)(uVar2 >> 7) - (uint)bVar1;
  iVar7 = (uint)(uVar3 >> 7) - (uint)*(byte *)(iVar5 + 0x3d);
  if (((((ushort)((iVar6 < 0) - 1 & (ushort)iVar6) <= *unaff_retaddr) &&
       (*unaff_retaddr <= (ushort)((ushort)bVar1 + (uVar2 >> 7)))) &&
      ((ushort)((iVar7 < 0) - 1 & (ushort)iVar7) <= unaff_retaddr[1])) &&
     (unaff_retaddr[1] <= (ushort)((ushort)*(byte *)(iVar5 + 0x3d) + (uVar3 >> 7)))) {
    iVar5 = (**(code **)(*piVar8 + 0xc))();
    if (iVar5 == 0x19) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_0062d4a0 @ 0x0062d4a0 ====

undefined4 FUN_0062d4a0(undefined2 *param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  undefined1 auStack_146 [70];
  undefined1 local_100 [256];
  
  piVar1 = *(int **)(in_ECX + 0x44);
  if (piVar1 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d057c,s_____EXCEPTION_____NULL_Point_Man_009d032c);
    FUN_00797b80(local_100);
  }
  piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
  piVar2 = (int *)(**(code **)(*DAT_00b5abc8 + 8))(*param_1);
  (**(code **)(*piVar2 + 4))();
  (**(code **)(*piVar1 + 8))(auStack_146 + -6);
  return 1;
}


// ==== FUN_0062d540 @ 0x0062d540 ====

undefined4 FUN_0062d540(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  undefined2 *unaff_retaddr;
  undefined1 local_100 [2];
  undefined1 auStack_fe [254];
  
  piVar2 = *(int **)(in_ECX + 0x50);
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d057c,s_____EXCEPTION_____NULL_state_man_009d0354);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009d039c,
                         s___Creature_Brick_Provider_cpp_009d037c,0xb8);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))(10);
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d057c,s_____EXCEPTION_____NULL_state_art_009d03b0);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d03f8,
                         s___Creature_Brick_Provider_cpp_009d03d8,0xbe);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar3 = *(int **)(in_ECX + 0x44);
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d057c,s_____EXCEPTION_____NULL_point_man_009d040c);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d0454,
                         s___Creature_Brick_Provider_cpp_009d0434,0xc4);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100 + -4,&DAT_009d057c,s_____EXCEPTION_____NULL_point_art_009d0468);
    FUN_00797b80(local_100 + -4);
    uVar1 = FUN_0044a580(local_100 + -4,s_File___s__Line___d_009d04b0,
                         s___Creature_Brick_Provider_cpp_009d0490,0xca);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5abc8 + 8))(*unaff_retaddr);
  iVar5 = (**(code **)(*piVar4 + 4))();
  (**(code **)(*piVar2 + 0x6c))((float)*(int *)(iVar5 + 0x30));
  puVar6 = (undefined4 *)(**(code **)(*piVar2 + 0x18))();
  (**(code **)(*piVar3 + 0x14))(*puVar6);
  (**(code **)(*piVar3 + 0x18))(0);
  iVar5 = *piVar3;
  iVar7 = (**(code **)(*piVar2 + 0x18))();
  (**(code **)(iVar5 + 0x1c))(*(undefined4 *)(iVar7 + 0xc));
  (**(code **)(*piVar2 + 0x8c))(0);
  (**(code **)(*piVar3 + 0x2c))(0);
  (**(code **)(*piVar3 + 0x30))(0);
  (**(code **)(*piVar3 + 0x34))(0);
  return 1;
}


// ==== FUN_0062d730 @ 0x0062d730 ====

undefined4 FUN_0062d730(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  undefined1 local_100 [256];
  
  piVar3 = (int *)in_ECX[2];
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d057c,s_____EXCEPTION_____NULL_Size_mana_009d04c4);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d050c,
                         s___Creature_Brick_Provider_cpp_009d04ec,0xeb);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d057c,s_____EXCEPTION_____NULL_Size_arti_009d0520);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d0568,
                         s___Creature_Brick_Provider_cpp_009d0548,0xf1);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  piVar4 = (int *)(**(code **)(*in_ECX + 0x20))();
  iVar1 = *piVar3;
  iVar5 = (**(code **)(*piVar4 + 4))();
  (**(code **)(iVar1 + 0x14))(*(undefined1 *)(iVar5 + 0x20));
  return 1;
}


// ==== FUN_0062d810 @ 0x0062d810 ====

undefined4 FUN_0062d810(undefined2 *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))(param_1);
  *(undefined2 *)((int)in_ECX + 0xb2) = *param_1;
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  iVar2 = (**(code **)(*DAT_00b5abc8 + 8))(*param_1);
  in_ECX[0x2d] = iVar2;
  if (iVar2 != 0) {
    cVar1 = FUN_0062d4a0(param_1);
    if (cVar1 != '\0') {
      cVar1 = FUN_0062d540(param_1);
      if (cVar1 != '\0') {
        cVar1 = FUN_0062d730(param_1);
        if (cVar1 != '\0') {
          cVar1 = FUN_0062d190(param_1);
          if (cVar1 != '\0') {
            iVar2 = *(int *)in_ECX[0x2f];
            uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
            (**(code **)(iVar2 + 0x28))(uVar3);
            (**(code **)(*(int *)in_ECX[0x2e] + 0xc))();
            return 1;
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_0062d8c0 @ 0x0062d8c0 ====

void FUN_0062d8c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062d0a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062d8e0 @ 0x0062d8e0 ====

void FUN_0062d8e0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xac) = 0;
  return;
}


// ==== FUN_0062d8f0 @ 0x0062d8f0 ====

void FUN_0062d8f0(void)

{
  return;
}


// ==== FUN_0062d900 @ 0x0062d900 ====

int FUN_0062d900(void)

{
  int in_ECX;
  
  return in_ECX + 0xb4;
}


// ==== FUN_0062d910 @ 0x0062d910 ====

undefined4 FUN_0062d910(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xf4);
}


// ==== FUN_0062d920 @ 0x0062d920 ====

void FUN_0062d920(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xf4) = param_1;
  return;
}


// ==== FUN_0062d930 @ 0x0062d930 ====

undefined4 FUN_0062d930(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xf8);
}


// ==== FUN_0062d940 @ 0x0062d940 ====

void FUN_0062d940(void)

{
  return;
}


// ==== FUN_0062d970 @ 0x0062d970 ====

void FUN_0062d970(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a2e8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d0670;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x3e] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x3e])(1);
  }
  in_ECX[0x3e] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0062da00 @ 0x0062da00 ====

void FUN_0062da00(void)

{
  char cVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0x2a;
  piVar3 = in_ECX;
  do {
    piVar3 = piVar3 + 1;
    if (*piVar3 != 0) {
      (**(code **)(*(int *)*piVar3 + 0xc))();
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00797a50(in_ECX + 0x2d,0,0x40);
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    (**(code **)(*(int *)in_ECX[0x3e] + 0x2c))();
  }
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  return;
}


// ==== FUN_0062da60 @ 0x0062da60 ====

void FUN_0062da60(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a305;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d0670;
  *(undefined1 *)((int)in_ECX + 0xc2) = 0;
  local_4 = 0;
  *(undefined1 *)((int)in_ECX + 0xdb) = 0;
  pvVar1 = operator_new(0xa1c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0064b3a0(in_ECX);
  }
  in_ECX[0x3e] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50(in_ECX + 1,0,0xa8);
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x12,0xf);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  FUN_00797a50(in_ECX + 0x2d,0,0x40);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  in_ECX[0x3d] = 0;
  ExceptionList = in_ECX;
  return;
}


// ==== FUN_0062db40 @ 0x0062db40 ====

undefined4 FUN_0062db40(void)

{
  int *piVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  undefined4 uStack_118;
  undefined1 uStack_10e;
  undefined1 uStack_10d;
  undefined4 uStack_108;
  undefined2 uStack_104;
  undefined1 local_100 [256];
  
  piVar1 = *(int **)(in_ECX + 0x4c);
  if (piVar1 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0668,s_>>>_ERROR_<<<_NULL_action_manage_009d05b8);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d05fc,
                         s___Creature_Flag_Provider_cpp_009d05dc,0x74);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  piVar3 = (int *)(**(code **)(*piVar1 + 0x14))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009d0668,s_>>>_ERROR_<<<_NULL_action_articl_009d0610);
    FUN_00797b80(local_100);
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009d0654,
                         s___Creature_Flag_Provider_cpp_009d0634,0x7b);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  uStack_104 = 0;
  uStack_108 = 0xf;
  (**(code **)(*piVar1 + 0x1c))(&uStack_108);
  FUN_005e0c90(local_100 + -0x1c);
  FUN_00797a50(&uStack_118,0,0xc);
  uStack_10d = 1;
  uStack_118 = 0;
  uStack_10e = 0;
  (**(code **)(*piVar3 + 0x24))(&uStack_118);
  return 1;
}


// ==== FUN_0062dc50 @ 0x0062dc50 ====

undefined1 FUN_0062dc50(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))(param_1);
  FUN_0062dce0(param_1);
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  cVar2 = FUN_0062db40(param_1);
  if (cVar2 == '\0') {
    *(undefined1 *)(in_ECX + 0x2c) = 0;
    return 0;
  }
  cVar2 = FUN_005c8e90();
  if (cVar2 == '\x01') {
    iVar1 = *(int *)in_ECX[0x3e];
    uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
    (**(code **)(iVar1 + 0x28))(uVar3);
  }
  return 1;
}


// ==== FUN_0062dcc0 @ 0x0062dcc0 ====

void FUN_0062dcc0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062d970();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062dce0 @ 0x0062dce0 ====

void FUN_0062dce0(undefined4 *param_1)

{
  char cVar1;
  undefined4 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  *(undefined2 *)(in_ECX + 3) = *(undefined2 *)(param_1 + 3);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0xe);
    *(char *)(uVar2 + 0xe + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_0062dd1e;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)((int)in_ECX + 0xe) = 0;
LAB_0062dd1e:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x27);
    *(char *)(uVar2 + 0x27 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)((int)in_ECX + 0x27) = 0;
  return;
}


// ==== FUN_0062dd40 @ 0x0062dd40 ====

void FUN_0062dd40(void)

{
  return;
}


// ==== FUN_0062dd50 @ 0x0062dd50 ====

void FUN_0062dd50(void)

{
  return;
}


// ==== FUN_0062dd60 @ 0x0062dd60 ====

int FUN_0062dd60(void)

{
  int in_ECX;
  
  return in_ECX + 0xb4;
}


// ==== FUN_0062dd70 @ 0x0062dd70 ====

void FUN_0062dd70(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xb8) = param_1;
  return;
}


// ==== FUN_0062dd80 @ 0x0062dd80 ====

void FUN_0062dd80(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xe0) = param_1;
  return;
}


// ==== FUN_0062dd90 @ 0x0062dd90 ====

void FUN_0062dd90(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xe4) = param_1;
  return;
}


// ==== FUN_0062dda0 @ 0x0062dda0 ====

undefined1 FUN_0062dda0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xe4);
}


// ==== FUN_0062ddb0 @ 0x0062ddb0 ====

undefined4 FUN_0062ddb0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe8);
}


// ==== FUN_0062ddc0 @ 0x0062ddc0 ====

void FUN_0062ddc0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xe8) = param_1;
  return;
}


// ==== FUN_0062ddd0 @ 0x0062ddd0 ====

undefined4 FUN_0062ddd0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xec);
}


// ==== FUN_0062dde0 @ 0x0062dde0 ====

void FUN_0062dde0(void)

{
  return;
}


// ==== FUN_0062de00 @ 0x0062de00 ====

void FUN_0062de00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a318;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d0694;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  if ((undefined4 *)in_ECX[0x3b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x3b])(1);
  }
  in_ECX[0x3b] = 0;
  *in_ECX = &PTR_FUN_009d02e4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062de60 @ 0x0062de60 ====

undefined4 FUN_0062de60(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0xb0) == '\0') {
    return 0;
  }
  return *(undefined4 *)(in_ECX + 0xe0);
}


// ==== FUN_0062de80 @ 0x0062de80 ====

void FUN_0062de80(void)

{
  char cVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  
  FUN_00797a50(in_ECX + 0x2d,0,0x2c);
  iVar2 = 0x2a;
  piVar3 = in_ECX;
  do {
    piVar3 = piVar3 + 1;
    if (*piVar3 != 0) {
      (**(code **)(*(int *)*piVar3 + 0xc))();
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  *(undefined1 *)(in_ECX + 0x39) = 0;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
                    /* WARNING: Could not recover jumptable at 0x0062ded6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)in_ECX[0x3b] + 0x2c))();
    return;
  }
  return;
}


// ==== FUN_0062dee0 @ 0x0062dee0 ====

void FUN_0062dee0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a335;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d0694;
  local_4 = 0;
  *(undefined1 *)((int)in_ECX + 0xc6) = 0;
  pvVar1 = operator_new(0xa1c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0064b920(in_ECX);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x3b] = uVar2;
  FUN_00797a50(in_ECX + 0x2d,0,0x2c);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  *(undefined1 *)(in_ECX + 0x39) = 0;
  in_ECX[0x3a] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062df80 @ 0x0062df80 ====

void FUN_0062df80(void)

{
  FUN_0062e030();
  return;
}


// ==== FUN_0062df90 @ 0x0062df90 ====

undefined4 FUN_0062df90(int param_1)

{
  char cVar1;
  undefined2 extraout_var;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))(param_1);
  FUN_0062e030(param_1);
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  *(undefined1 *)(in_ECX + 0x39) = 0;
  iVar2 = (**(code **)(*DAT_00b5abcc + 8))(CONCAT22(extraout_var,*(undefined2 *)(param_1 + 2)));
  in_ECX[0x38] = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    iVar2 = *(int *)in_ECX[0x3b];
    uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
    (**(code **)(iVar2 + 0x28))(uVar3);
  }
  return 1;
}


// ==== FUN_0062e010 @ 0x0062e010 ====

void FUN_0062e010(byte param_1)

{
  void *in_ECX;
  
  FUN_0062de00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062e030 @ 0x0062e030 ====

void FUN_0062e030(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  *(undefined4 *)(in_ECX + 2) = *(undefined4 *)(param_1 + 2);
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 6) = *(undefined4 *)(param_1 + 6);
  in_ECX[8] = param_1[8];
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x12);
    *(char *)(uVar2 + 0x12 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)(in_ECX + 9) = 0;
  return;
}


// ==== FUN_0062e090 @ 0x0062e090 ====

void FUN_0062e090(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xac) = 0;
  return;
}


// ==== FUN_0062e0a0 @ 0x0062e0a0 ====

void FUN_0062e0a0(void)

{
  return;
}


// ==== FUN_0062e0b0 @ 0x0062e0b0 ====

int FUN_0062e0b0(void)

{
  int in_ECX;
  
  return in_ECX + 0xb0;
}


// ==== FUN_0062e0c0 @ 0x0062e0c0 ====

undefined4 FUN_0062e0c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xcc);
}


// ==== FUN_0062e0d0 @ 0x0062e0d0 ====

void FUN_0062e0d0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xcc) = param_1;
  return;
}


// ==== FUN_0062e0e0 @ 0x0062e0e0 ====

undefined4 FUN_0062e0e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xd0);
}


// ==== FUN_0062e0f0 @ 0x0062e0f0 ====

void FUN_0062e0f0(void)

{
  return;
}


// ==== FUN_0062e130 @ 0x0062e130 ====

void FUN_0062e130(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a348;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d073c;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x34] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x34])(1);
  }
  in_ECX[0x34] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0062e1c0 @ 0x0062e1c0 ====

bool FUN_0062e1c0(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x9c))(param_1);
  return cVar1 != '\0';
}


// ==== FUN_0062e1e0 @ 0x0062e1e0 ====

void FUN_0062e1e0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a365;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d073c;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  pvVar1 = operator_new(0xa20);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0064be70(in_ECX);
  }
  in_ECX[0x34] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50(in_ECX + 1,0,0xa8);
  pvVar1 = (void *)0xc;
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(9);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0xc,0xc);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(6,0xc);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  FUN_00797a50(in_ECX + 0x2c,0,0x19);
  in_ECX[0x33] = 0;
  ExceptionList = pvVar1;
  return;
}


// ==== FUN_0062e310 @ 0x0062e310 ====

void FUN_0062e310(void)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 uStack_104;
  undefined1 uStack_103;
  undefined1 auStack_102 [258];
  
  piVar1 = *(int **)(in_ECX + 0x28);
  iVar3 = (**(code **)(*piVar1 + 0x28))();
  while (iVar3 != 0) {
    uStack_104 = 0;
    uStack_103 = 0;
    auStack_102[0] = 0;
    cVar2 = (**(code **)(*piVar1 + 0x18))(iVar3,&uStack_104);
    if (cVar2 == '\0') {
      uVar4 = FUN_0044a580(auStack_102 + -6,s_File___s__Line___d_009d06f0,
                           s___Creature_TradePC_Provider_cpp_009d06d0,0x74);
      FUN_00797b80(uVar4);
      FUN_00797a40();
    }
    uVar4 = (**(code **)(*piVar1 + 0x20))(auStack_102 + -10);
    (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar4);
    iVar3 = (**(code **)(*piVar1 + 0x28))();
  }
  piVar1 = *(int **)(in_ECX + 0x34);
  iVar3 = (**(code **)(*piVar1 + 0x34))();
  while (iVar3 != 0) {
    uStack_104 = 0;
    uStack_103 = 0;
    auStack_102[0] = 0;
    cVar2 = (**(code **)(*piVar1 + 0x18))(iVar3,&uStack_104);
    if (cVar2 == '\0') {
      uVar4 = FUN_0044a580(auStack_102 + -6,s_File___s__Line___d_009d0724,
                           s___Creature_TradePC_Provider_cpp_009d0704,0x8d);
      FUN_00797b80(uVar4);
      FUN_00797a40();
    }
    uVar4 = (**(code **)(*piVar1 + 0x24))(auStack_102 + -10);
    (**(code **)(*DAT_00b5a730 + 0x10))(1,uVar4);
    iVar3 = (**(code **)(*piVar1 + 0x34))();
  }
  cVar2 = FUN_005c8e90();
  if (cVar2 == '\x01') {
    (**(code **)(**(int **)(in_ECX + 0xd0) + 0x2c))();
  }
  return;
}


// ==== FUN_0062e440 @ 0x0062e440 ====

undefined4 FUN_0062e440(int param_1)

{
  char *pcVar1;
  int iVar2;
  char cVar3;
  char *pcVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  
  pcVar1 = (char *)(in_ECX + 0xb0);
  uVar6 = 0;
  pcVar4 = pcVar1;
  do {
    cVar3 = pcVar4[param_1 - (int)pcVar1];
    *pcVar4 = cVar3;
    if (cVar3 == '\0') goto LAB_0062e46c;
    uVar6 = uVar6 + 1;
    pcVar4 = pcVar4 + 1;
  } while (uVar6 < 0x19);
  *pcVar1 = '\0';
LAB_0062e46c:
  cVar3 = FUN_005c8e90();
  if (cVar3 == '\x01') {
    iVar2 = **(int **)(in_ECX + 0xd0);
    uVar5 = (**(code **)(*DAT_00b5a690 + 4))();
    (**(code **)(iVar2 + 0x28))(uVar5);
  }
  return 1;
}


// ==== FUN_0062e4a0 @ 0x0062e4a0 ====

void FUN_0062e4a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062e130();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062e4c0 @ 0x0062e4c0 ====

void FUN_0062e4c0(void)

{
  return;
}


// ==== FUN_0062e4d0 @ 0x0062e4d0 ====

void FUN_0062e4d0(void)

{
  return;
}


// ==== FUN_0062e4e0 @ 0x0062e4e0 ====

int FUN_0062e4e0(void)

{
  int in_ECX;
  
  return in_ECX + 0xb4;
}


// ==== FUN_0062e4f0 @ 0x0062e4f0 ====

undefined4 FUN_0062e4f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe0);
}


// ==== FUN_0062e500 @ 0x0062e500 ====

void FUN_0062e500(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0062e508. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xe0) + 4))();
  return;
}


// ==== FUN_0062e510 @ 0x0062e510 ====

void FUN_0062e510(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xb8) = param_1;
  return;
}


// ==== FUN_0062e520 @ 0x0062e520 ====

undefined4 FUN_0062e520(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe4);
}


// ==== FUN_0062e530 @ 0x0062e530 ====

void FUN_0062e530(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xe4) = param_1;
  return;
}


// ==== FUN_0062e540 @ 0x0062e540 ====

undefined4 FUN_0062e540(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe8);
}


// ==== FUN_0062e550 @ 0x0062e550 ====

void FUN_0062e550(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0062e558. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xe8) + 0x30))();
  return;
}


// ==== FUN_0062e570 @ 0x0062e570 ====

void FUN_0062e570(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a378;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d0764;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  if ((undefined4 *)in_ECX[0x3a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x3a])(1);
  }
  in_ECX[0x3a] = 0;
  *in_ECX = &PTR_FUN_009d02e4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062e5d0 @ 0x0062e5d0 ====

void FUN_0062e5d0(void)

{
  char cVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  
  FUN_00797a50(in_ECX + 0x2d,0,0x2c);
  iVar2 = 0x2a;
  piVar3 = in_ECX;
  do {
    piVar3 = piVar3 + 1;
    if (*piVar3 != 0) {
      (**(code **)(*(int *)*piVar3 + 0xc))();
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
                    /* WARNING: Could not recover jumptable at 0x0062e61f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)in_ECX[0x3a] + 0x2c))();
    return;
  }
  return;
}


// ==== FUN_0062e630 @ 0x0062e630 ====

void FUN_0062e630(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a395;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009d0764;
  local_4 = 0;
  *(undefined1 *)((int)in_ECX + 0xc6) = 0;
  pvVar1 = operator_new(0x51c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0064c240(in_ECX);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[0x3a] = uVar2;
  FUN_00797a50(in_ECX + 0x2d,0,0x2c);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  in_ECX[0x39] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0062e6d0 @ 0x0062e6d0 ====

undefined4 FUN_0062e6d0(undefined2 *param_1)

{
  char cVar1;
  undefined2 extraout_var;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))(param_1);
  FUN_0062e770(param_1);
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  iVar2 = (**(code **)(*DAT_00b5abbc + 8))(CONCAT22(extraout_var,*param_1));
  in_ECX[0x38] = iVar2;
  if (iVar2 == 0) {
    return 0;
  }
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    iVar2 = *(int *)in_ECX[0x3a];
    uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
    (**(code **)(iVar2 + 0x28))(uVar3);
  }
  return 1;
}


// ==== FUN_0062e750 @ 0x0062e750 ====

void FUN_0062e750(byte param_1)

{
  void *in_ECX;
  
  FUN_0062e570();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062e770 @ 0x0062e770 ====

void FUN_0062e770(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  *(undefined4 *)(in_ECX + 2) = *(undefined4 *)(param_1 + 2);
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 6) = *(undefined4 *)(param_1 + 6);
  in_ECX[8] = param_1[8];
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x12);
    *(char *)(uVar2 + 0x12 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)(in_ECX + 9) = 0;
  return;
}


// ==== FUN_0062e7c0 @ 0x0062e7c0 ====

void FUN_0062e7c0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xac) = 0;
  return;
}


// ==== FUN_0062e7d0 @ 0x0062e7d0 ====

void FUN_0062e7d0(void)

{
  return;
}


// ==== FUN_0062e7e0 @ 0x0062e7e0 ====

int FUN_0062e7e0(void)

{
  int in_ECX;
  
  return in_ECX + 0xb4;
}


// ==== FUN_0062e7f0 @ 0x0062e7f0 ====

undefined4 FUN_0062e7f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe0);
}


// ==== FUN_0062e800 @ 0x0062e800 ====

void FUN_0062e800(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0062e808. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xe0) + 4))();
  return;
}


// ==== FUN_0062e810 @ 0x0062e810 ====

undefined1 FUN_0062e810(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xd4);
}


// ==== FUN_0062e820 @ 0x0062e820 ====

undefined4 FUN_0062e820(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe4);
}


// ==== FUN_0062e830 @ 0x0062e830 ====

void FUN_0062e830(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xe4) = param_1;
  return;
}


// ==== FUN_0062e840 @ 0x0062e840 ====

undefined4 FUN_0062e840(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe8);
}


// ==== FUN_0062e850 @ 0x0062e850 ====

void FUN_0062e850(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0062e858. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xe8) + 0x30))();
  return;
}


// ==== FUN_0062e860 @ 0x0062e860 ====

undefined4 FUN_0062e860(byte param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x24))();
  if (*(byte *)(iVar1 + 0x34) < param_1) {
    return 0;
  }
  *(byte *)(in_ECX + 0x35) = param_1;
  return 1;
}


// ==== FUN_0062e890 @ 0x0062e890 ====

undefined1 FUN_0062e890(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xdc);
}


// ==== FUN_0062e8a0 @ 0x0062e8a0 ====

void FUN_0062e8a0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xdc) = param_1;
  return;
}


// ==== FUN_0062e8d0 @ 0x0062e8d0 ====

void FUN_0062e8d0(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a3a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d0794;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x3a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x3a])(1);
  }
  in_ECX[0x3a] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0062e960 @ 0x0062e960 ====

void FUN_0062e960(void)

{
  char cVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  
  iVar2 = 0x2a;
  piVar3 = in_ECX;
  do {
    piVar3 = piVar3 + 1;
    if (*piVar3 != 0) {
      (**(code **)(*(int *)*piVar3 + 0xc))();
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00797a50(in_ECX + 0x2d,0,0x28);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  in_ECX[0x38] = 0;
  *(undefined1 *)(in_ECX + 0x37) = 0;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
                    /* WARNING: Could not recover jumptable at 0x0062e9c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)in_ECX[0x3a] + 0x2c))();
    return;
  }
  return;
}


// ==== FUN_0062e9d0 @ 0x0062e9d0 ====

undefined4 FUN_0062e9d0(undefined2 *param_1)

{
  int in_ECX;
  undefined4 local_8;
  undefined2 local_4;
  
  local_4 = *param_1;
  local_8 = 0xd;
  (**(code **)(**(int **)(in_ECX + 0x4c) + 0x1c))(&local_8);
  return 1;
}


// ==== FUN_0062ea00 @ 0x0062ea00 ====

void FUN_0062ea00(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a3c5;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d0794;
  pvVar1 = operator_new(0x51c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0064c510(in_ECX);
  }
  in_ECX[0x3a] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50(in_ECX + 1,0,0xa8);
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x13,0xd);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x12,0xd);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  FUN_00797a50(in_ECX + 0x2d,0,0x28);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  *(undefined1 *)(in_ECX + 0x37) = 0;
  in_ECX[0x39] = 0;
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_0062eb00 @ 0x0062eb00 ====

undefined4 FUN_0062eb00(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  int *piVar4;
  undefined1 auStack_6 [6];
  
  (**(code **)(*in_ECX + 0xc))(param_1);
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  iVar2 = (**(code **)(*DAT_00b5a768 + 8))((short)*param_1);
  in_ECX[0x38] = iVar2;
  if (iVar2 == 0) {
    *(undefined1 *)(in_ECX + 0x2c) = 0;
    return 0;
  }
  (**(code **)(*(int *)in_ECX[0x13] + 0x1c))(auStack_6 + -10);
  piVar4 = in_ECX + 0x2d;
  for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar4 = *param_1;
    param_1 = param_1 + 1;
    piVar4 = piVar4 + 1;
  }
  iVar2 = (**(code **)(*(int *)in_ECX[0x38] + 4))();
  *(undefined1 *)(in_ECX + 0x35) = *(undefined1 *)(iVar2 + 0x34);
  iVar2 = (**(code **)(*(int *)in_ECX[0x38] + 4))();
  *(undefined1 *)((int)in_ECX + 0xd5) = *(undefined1 *)(iVar2 + 0x35);
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    iVar2 = *(int *)in_ECX[0x3a];
    uVar3 = (**(code **)(*DAT_00b5a690 + 4))();
    (**(code **)(iVar2 + 0x28))(uVar3);
  }
  return 1;
}


// ==== FUN_0062ebd0 @ 0x0062ebd0 ====

void FUN_0062ebd0(byte param_1)

{
  void *in_ECX;
  
  FUN_0062e8d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0062ec10 @ 0x0062ec10 ====

int FUN_0062ec10(void)

{
  int in_ECX;
  
  return in_ECX + 0x110;
}


// ==== FUN_0062ec20 @ 0x0062ec20 ====

void FUN_0062ec20(void)

{
  int in_ECX;
  
  *(short *)(in_ECX + 0xf4) = *(short *)(in_ECX + 0xf4) + 1;
  return;
}


// ==== FUN_0062ec30 @ 0x0062ec30 ====

undefined2 FUN_0062ec30(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0xf4);
}


// ==== FUN_0062ec40 @ 0x0062ec40 ====

void FUN_0062ec40(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0xf4) = param_1;
  return;
}


// ==== FUN_0062ec50 @ 0x0062ec50 ====

void FUN_0062ec50(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0xf6) = param_1;
  return;
}


// ==== FUN_0062ec60 @ 0x0062ec60 ====

undefined2 FUN_0062ec60(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0xf6);
}


// ==== FUN_0062ec70 @ 0x0062ec70 ====

void FUN_0062ec70(void)

{
  return;
}


// ==== FUN_0062ec80 @ 0x0062ec80 ====

void FUN_0062ec80(void)

{
  return;
}


// ==== FUN_0062ec90 @ 0x0062ec90 ====

void FUN_0062ec90(void)

{
  return;
}


// ==== FUN_0062eca0 @ 0x0062eca0 ====

void FUN_0062eca0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x158) = param_1;
  return;
}


// ==== FUN_0062ecb0 @ 0x0062ecb0 ====

undefined4 FUN_0062ecb0(uint param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0x158);
  if (uVar1 == 0) {
    return 1;
  }
  return CONCAT31((int3)(uVar1 >> 8),uVar1 <= param_1);
}


// ==== FUN_0062ecd0 @ 0x0062ecd0 ====

void FUN_0062ecd0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x15c) = param_1;
  return;
}


// ==== FUN_0062ece0 @ 0x0062ece0 ====

undefined4 FUN_0062ece0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x15c);
}


// ==== FUN_0062ed00 @ 0x0062ed00 ====

undefined4 FUN_0062ed00(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x150);
}


// ==== FUN_0062ed10 @ 0x0062ed10 ====

void FUN_0062ed10(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x150) = param_1;
  (**(code **)(**(int **)(in_ECX + 0x154) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x154) + 0xc))();
  (**(code **)(**(int **)(in_ECX + 0x154) + 0x10))();
  (**(code **)(**(int **)(in_ECX + 0x154) + 0x14))();
  return;
}


// ==== FUN_0062ed50 @ 0x0062ed50 ====

undefined4 FUN_0062ed50(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x154);
}


// ==== FUN_0062ed60 @ 0x0062ed60 ====

void FUN_0062ed60(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0062ed68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x154) + 0x30))();
  return;
}


// ==== FUN_0062ed70 @ 0x0062ed70 ====

int FUN_0062ed70(void)

{
  int in_ECX;
  
  return in_ECX + 0xb4;
}


// ==== FUN_0062ed80 @ 0x0062ed80 ====

void FUN_0062ed80(void)

{
  return;
}


// ==== FUN_0062ed90 @ 0x0062ed90 ====

void FUN_0062ed90(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0xfc) = *(int *)(in_ECX + 0xfc) + 1;
  return;
}


// ==== FUN_0062edb0 @ 0x0062edb0 ====

bool FUN_0062edb0(uint param_1)

{
  int in_ECX;
  
  return (*(uint *)(in_ECX + 300) & param_1) == param_1;
}


// ==== FUN_0062edd0 @ 0x0062edd0 ====

void FUN_0062edd0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x148) = param_1;
  return;
}


// ==== FUN_0062ede0 @ 0x0062ede0 ====

void FUN_0062ede0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14c) = param_1;
  return;
}


// ==== FUN_0062edf0 @ 0x0062edf0 ====

bool FUN_0062edf0(uint param_1)

{
  bool bVar1;
  int in_ECX;
  
  bVar1 = true;
  if (*(char *)(in_ECX + 0x148) != '\x01') {
    bVar1 = *(int *)(in_ECX + 0x14c) + 1800000U < param_1;
  }
  return bVar1;
}


// ==== FUN_0062ee10 @ 0x0062ee10 ====

void FUN_0062ee10(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x160) = param_1;
  *(undefined1 *)(in_ECX + 0x164) = param_2;
  *(undefined4 *)(in_ECX + 0x168) = param_3;
  return;
}


// ==== FUN_0062ee40 @ 0x0062ee40 ====

undefined4 FUN_0062ee40(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x160);
}


// ==== FUN_0062ee50 @ 0x0062ee50 ====

undefined1 FUN_0062ee50(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x164);
}


// ==== FUN_0062ee60 @ 0x0062ee60 ====

undefined4 FUN_0062ee60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x168);
}


// ==== FUN_0062ee70 @ 0x0062ee70 ====

void FUN_0062ee70(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x16c) = *param_1;
  *(undefined2 *)(in_ECX + 0x170) = *(undefined2 *)(param_1 + 1);
  return;
}


// ==== FUN_0062ee90 @ 0x0062ee90 ====

int FUN_0062ee90(void)

{
  int in_ECX;
  
  return in_ECX + 0x16c;
}


// ==== FUN_0062eea0 @ 0x0062eea0 ====

void FUN_0062eea0(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0xb8) = *(int *)(in_ECX + 0xb8) + param_1;
  return;
}


// ==== FUN_0062eed0 @ 0x0062eed0 ====

void FUN_0062eed0(void)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098a3d8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = (int)&PTR_FUN_009d0b74;
  local_4 = 0;
  iVar1 = 0x2a;
  piVar2 = in_ECX;
  do {
    piVar2 = piVar2 + 1;
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))();
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
    }
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((undefined4 *)in_ECX[0x55] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x55])(1);
  }
  in_ECX[0x55] = 0;
  *in_ECX = (int)&PTR_FUN_009d02e4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0062ef60 @ 0x0062ef60 ====

void FUN_0062ef60(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0xc))(param_1);
  if (cVar1 == '\0') {
    return;
  }
  *(uint *)(in_ECX + 300) = *(uint *)(in_ECX + 300) | 1;
  return;
}


// ==== FUN_0062ef90 @ 0x0062ef90 ====

undefined1 FUN_0062ef90(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x14))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  *(uint *)(in_ECX + 300) = *(uint *)(in_ECX + 300) | 2;
  return 1;
}


// ==== FUN_0062efc0 @ 0x0062efc0 ====

undefined1 FUN_0062efc0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x1c))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  *(uint *)(in_ECX + 300) = *(uint *)(in_ECX + 300) | 4;
  return 1;
}


// ==== FUN_0062eff0 @ 0x0062eff0 ====

void FUN_0062eff0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x24))(param_1);
  if (cVar1 == '\0') {
    return;
  }
  *(int *)(in_ECX + 0x130) = *(int *)(in_ECX + 0x130) + 1;
  if (*(int *)(in_ECX + 0x130) == 4) {
    *(uint *)(in_ECX + 300) = *(uint *)(in_ECX + 300) | 0x10;
  }
  return;
}


// ==== FUN_0062f030 @ 0x0062f030 ====

void FUN_0062f030(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x2c))(param_1);
  if (cVar1 == '\0') {
    return;
  }
  *(int *)(in_ECX + 0x138) = *(int *)(in_ECX + 0x138) + 1;
  if (*(int *)(in_ECX + 0x138) == 4) {
    *(uint *)(in_ECX + 300) = *(uint *)(in_ECX + 300) | 0x20;
  }
  return;
}


// ==== FUN_0062f070 @ 0x0062f070 ====

void FUN_0062f070(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x34))(param_1);
  if (cVar1 == '\0') {
    return;
  }
  *(int *)(in_ECX + 0x13c) = *(int *)(in_ECX + 0x13c) + 1;
  if (*(int *)(in_ECX + 0x13c) == 4) {
    *(uint *)(in_ECX + 300) = *(uint *)(in_ECX + 300) | 0x40;
  }
  return;
}


// ==== FUN_0062f0b0 @ 0x0062f0b0 ====

void FUN_0062f0b0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x54))(param_1);
  if (cVar1 == '\0') {
    return;
  }
  *(int *)(in_ECX + 0x134) = *(int *)(in_ECX + 0x134) + 1;
  if (*(int *)(in_ECX + 0x134) == 4) {
    *(byte *)(in_ECX + 0x12d) = *(byte *)(in_ECX + 0x12d) | 1;
  }
  return;
}


// ==== FUN_0062f0f0 @ 0x0062f0f0 ====

void FUN_0062f0f0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x5c))(param_1);
  if (cVar1 == '\0') {
    return;
  }
  *(int *)(in_ECX + 0x140) = *(int *)(in_ECX + 0x140) + 1;
  if (*(int *)(in_ECX + 0x140) == 4) {
    *(byte *)(in_ECX + 0x12d) = *(byte *)(in_ECX + 0x12d) | 2;
  }
  return;
}


// ==== FUN_0062f130 @ 0x0062f130 ====

void FUN_0062f130(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 100))(param_1);
  if (cVar1 == '\0') {
    return;
  }
  *(int *)(in_ECX + 0x144) = *(int *)(in_ECX + 0x144) + 1;
  if (*(int *)(in_ECX + 0x144) == 4) {
    *(byte *)(in_ECX + 0x12d) = *(byte *)(in_ECX + 0x12d) | 4;
  }
  return;
}


// ==== FUN_0062f170 @ 0x0062f170 ====

undefined1 FUN_0062f170(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x3c))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  *(byte *)(in_ECX + 0x12e) = *(byte *)(in_ECX + 0x12e) | 1;
  return 1;
}


// ==== FUN_0062f1a0 @ 0x0062f1a0 ====

undefined1 FUN_0062f1a0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x44))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  *(byte *)(in_ECX + 0x12e) = *(byte *)(in_ECX + 0x12e) | 2;
  return 1;
}


// ==== FUN_0062f1d0 @ 0x0062f1d0 ====

undefined1 FUN_0062f1d0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x4c))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  *(byte *)(in_ECX + 0x12e) = *(byte *)(in_ECX + 0x12e) | 4;
  return 1;
}


// ==== FUN_0062f200 @ 0x0062f200 ====

undefined1 FUN_0062f200(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x6c))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  *(byte *)(in_ECX + 0x12d) = *(byte *)(in_ECX + 0x12d) | 0x10;
  return 1;
}


// ==== FUN_0062f230 @ 0x0062f230 ====

undefined1 FUN_0062f230(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x74))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  *(byte *)(in_ECX + 0x12d) = *(byte *)(in_ECX + 0x12d) | 0x20;
  return 1;
}


// ==== FUN_0062f260 @ 0x0062f260 ====

undefined1 FUN_0062f260(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x7c))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  *(byte *)(in_ECX + 0x12d) = *(byte *)(in_ECX + 0x12d) | 0x40;
  return 1;
}


// ==== FUN_0062f290 @ 0x0062f290 ====

undefined1 FUN_0062f290(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x84))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  *(byte *)(in_ECX + 0x12d) = *(byte *)(in_ECX + 0x12d) | 0x80;
  return 1;
}


// ==== FUN_0062f2c0 @ 0x0062f2c0 ====

undefined1 FUN_0062f2c0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x8c))(param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  *(byte *)(in_ECX + 0x12e) = *(byte *)(in_ECX + 0x12e) | 0x10;
  return 1;
}


// ==== FUN_0062f2f0 @ 0x0062f2f0 ====

undefined1 FUN_0062f2f0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aa18 + 0x94))(param_1,param_2);
  if (cVar1 == '\0') {
    return 0;
  }
  *(byte *)(in_ECX + 0x12e) = *(byte *)(in_ECX + 0x12e) | 0x20;
  return 1;
}


// ==== FUN_0062f330 @ 0x0062f330 ====

void FUN_0062f330(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x15c) = 0;
  return;
}


// ==== FUN_0062f350 @ 0x0062f350 ====

void FUN_0062f350(void)

{
  int *in_ECX;
  int *piVar1;
  int iVar2;
  
  iVar2 = 0x2a;
  piVar1 = in_ECX;
  do {
    piVar1 = piVar1 + 1;
    if (*piVar1 != 0) {
      (**(code **)(*(int *)*piVar1 + 0xc))();
    }
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  in_ECX[0x57] = 0;
  return;
}


// ==== FUN_0062f390 @ 0x0062f390 ====

void FUN_0062f390(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x160) = 0;
  *(undefined1 *)(in_ECX + 0x164) = 3;
  *(undefined4 *)(in_ECX + 0x168) = 0;
  return;
}


// ==== FUN_0062f3b0 @ 0x0062f3b0 ====

void FUN_0062f3b0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0098a3f5;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009d0b74;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x44) = 0;
  pvVar1 = operator_new(0xa2c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0064ca90(in_ECX);
  }
  in_ECX[0x55] = uVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_00797a50(in_ECX + 1,0,0xa8);
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(1,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(2,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(5,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(6,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(7,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(8,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(9,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(10,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0xb,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0xc,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0xd,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0xe,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0xf,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x10,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x11,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x12,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x13,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x17,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x1c,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(3,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(4,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x1d,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x1e,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x1a,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x1b,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x1f,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x20,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x21,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x22,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x23,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x24,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x25,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  pvVar1 = (void *)0x26;
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x26,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x27,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x28,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a73c + 4))(0x29,0);
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (in_ECX[iVar4 + 1] == 0) {
    in_ECX[iVar4 + 1] = piVar3;
    (**(code **)(*piVar3 + 0x10))();
  }
  FUN_00797a50(in_ECX + 0x2d,0,0x78);
  FUN_00797a50(in_ECX + 0x5b,0,6);
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  *(undefined1 *)(in_ECX + 0x52) = 0;
  in_ECX[0x54] = 0;
  in_ECX[0x57] = 0;
  in_ECX[0x56] = 0;
  in_ECX[0x58] = 0;
  in_ECX[0x5a] = 0;
  *(undefined1 *)(in_ECX + 0x59) = 3;
  ExceptionList = pvVar1;
  return;
}


// ==== FUN_0062fa80 @ 0x0062fa80 ====

void FUN_0062fa80(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int in_ECX;
  uint uVar4;
  
  pcVar1 = (char *)(in_ECX + 0x110);
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[param_1 - (int)pcVar1];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') {
      return;
    }
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x19);
  *pcVar1 = '\0';
  return;
}


// ==== FUN_0062fab0 @ 0x0062fab0 ====

void FUN_0062fab0(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x7c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x7c) + 0x14))();
  }
                    /* WARNING: Could not recover jumptable at 0x0062fac4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x10))();
  return;
}


// ==== FUN_0062fad0 @ 0x0062fad0 ====

void FUN_0062fad0(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x7c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x7c) + 0x14))();
  }
                    /* WARNING: Could not recover jumptable at 0x0062fae4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x1c))();
  return;
}


// ==== FUN_0062fbc0 @ 0x0062fbc0 ====

undefined4 FUN_0062fbc0(int param_1)

{
  int in_ECX;
  int *piVar1;
  
  if (*(int **)(in_ECX + 0x44) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x44) + 0x18))();
  }
  (**(code **)(*piVar1 + 0x14))((float)*(int *)(param_1 + 0x18));
  (**(code **)(*piVar1 + 0x20))((float)*(int *)(param_1 + 0x1c));
  (**(code **)(*piVar1 + 0x2c))((float)*(int *)(param_1 + 0x44));
  (**(code **)(*piVar1 + 0x40))((float)*(int *)(param_1 + 0x18),0);
  (**(code **)(*piVar1 + 0x44))((float)*(int *)(param_1 + 0x44),0);
  return 1;
}


// ==== FUN_0062fc40 @ 0x0062fc40 ====

undefined4 FUN_0062fc40(int param_1)

{
  undefined1 uVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined2 uVar7;
  int in_ECX;
  int unaff_EBX;
  int *piVar8;
  int *piVar9;
  undefined4 local_1c;
  int local_18;
  undefined4 uStack_14;
  undefined1 uStack_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  
  if (*(int **)(in_ECX + 0x74) == (int *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)(**(code **)(**(int **)(in_ECX + 0x74) + 0x14))();
  }
  piVar3 = *(int **)(in_ECX + 0x4c);
  if (piVar3 == (int *)0x0) {
    piVar9 = (int *)0x0;
  }
  else {
    piVar9 = (int *)(**(code **)(*piVar3 + 0x18))();
  }
  local_18 = CONCAT22(local_18._2_2_,(ushort)*(byte *)(param_1 + 0x3a));
  local_1c = 0;
  (**(code **)(*piVar3 + 0x1c))(&local_1c);
  sVar2 = *(short *)(param_1 + 0x2a);
  iVar5 = *(int *)(param_1 + 0x28);
  iVar4 = *(int *)(param_1 + 0x28);
  iVar6 = (**(code **)(*piVar8 + 8))();
  uVar1 = *(undefined1 *)(iVar6 + 4);
  if (*(int *)(unaff_EBX + 0xcc) == 0) {
    FUN_00797a50(&local_18,0,0x14);
    uVar7 = (undefined2)(iVar4 << 7);
    uStack_d = 8;
  }
  else {
    FUN_00797a50(&local_18,0,0xc);
    uVar7 = (undefined2)(iVar5 << 7);
    uStack_d = 1;
  }
  uStack_14 = CONCAT22(sVar2 << 7,uVar7);
  local_18 = param_1;
  _uStack_10 = CONCAT11((char)((uint)in_ECX >> 8),*(undefined1 *)(param_1 + 0x3b));
  uStack_e = uVar1;
  (**(code **)(*piVar9 + 0x24))(&local_18);
  return 1;
}


// ==== FUN_0062fd70 @ 0x0062fd70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0062fd70(void)

{
  int *piVar1;
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x18) + 0x1c))();
  if (*(int **)(in_ECX + 0x74) == (int *)0x0) {
    (**(code **)(_DAT_00000000 + 0x10))(1);
    return 1;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x74) + 0x14))();
  (**(code **)(*piVar1 + 0x10))(1);
  return 1;
}


// ==== FUN_0062fdb0 @ 0x0062fdb0 ====

undefined4 FUN_0062fdb0(int param_1)

{
  int *piVar1;
  int in_ECX;
  undefined2 local_8;
  undefined2 local_6;
  undefined2 local_4;
  
  if (*(int **)(in_ECX + 0x8c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x8c) + 0x18))();
  }
  local_8 = *(undefined2 *)(param_1 + 0x32);
  local_6 = *(undefined2 *)(param_1 + 0x2c);
  local_4 = *(undefined2 *)(param_1 + 0x2e);
  (**(code **)(*piVar1 + 0x14))(&local_8);
  return 1;
}


// ==== FUN_0062fe00 @ 0x0062fe00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0062fe00(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x94) == (int *)0x0) {
    (**(code **)(_DAT_00000000 + 0xc))(0);
    return 1;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x94) + 0x18))();
  (**(code **)(*piVar1 + 0xc))(0);
  return 1;
}


// ==== FUN_0062fe30 @ 0x0062fe30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0062fe30(int param_1)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xa4) == (int *)0x0) {
    (**(code **)(_DAT_00000000 + 8))(*(undefined4 *)(param_1 + 0x58));
    return 1;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xa4) + 0x18))();
  (**(code **)(*piVar1 + 8))(*(undefined4 *)(param_1 + 0x58));
  return 1;
}


// ==== FUN_0062fe70 @ 0x0062fe70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0062fe70(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xa8) == (int *)0x0) {
    (**(code **)(_DAT_00000000 + 8))();
    return 1;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xa8) + 0x14))();
  (**(code **)(*piVar1 + 8))();
  return 1;
}


// ==== FUN_0062fea0 @ 0x0062fea0 ====

void FUN_0062fea0(undefined4 param_1)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  ushort uVar4;
  int iVar5;
  int *piVar6;
  undefined2 *puVar7;
  char *pcVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  int iVar11;
  ushort *puVar12;
  int *in_ECX;
  int *piVar13;
  undefined1 auStack_fe [254];
  
  (**(code **)(*(int *)in_ECX[0x14] + 0x20))(param_1);
  if ((int *)in_ECX[0x11] == (int *)0x0) {
    piVar13 = (int *)0x0;
  }
  else {
    piVar13 = (int *)(**(code **)(*(int *)in_ECX[0x11] + 0x18))();
  }
  iVar5 = (**(code **)(*piVar13 + 0xc))();
  in_ECX[0x33] = (int)*(float *)(iVar5 + 4);
  iVar5 = (**(code **)(*piVar13 + 0xc))();
  in_ECX[0x34] = (int)*(float *)(iVar5 + 0x18);
  iVar5 = (**(code **)(*piVar13 + 0xc))();
  in_ECX[0x3e] = (int)*(float *)(iVar5 + 0x2c);
  piVar13 = (int *)in_ECX[3];
  piVar6 = (int *)(**(code **)(*piVar13 + 0x24))();
  puVar7 = (undefined2 *)(**(code **)(*piVar6 + 0xc))();
  *(undefined2 *)(in_ECX + 0x35) = *puVar7;
  iVar5 = (**(code **)(*piVar6 + 0xc))();
  *(undefined2 *)((int)in_ECX + 0xd6) = *(undefined2 *)(iVar5 + 2);
  iVar5 = (**(code **)(*piVar6 + 0xc))();
  *(undefined2 *)(in_ECX + 0x36) = *(undefined2 *)(iVar5 + 4);
  iVar5 = (**(code **)(*piVar6 + 0xc))();
  *(undefined2 *)((int)in_ECX + 0xda) = *(undefined2 *)(iVar5 + 6);
  puVar7 = (undefined2 *)(**(code **)(*piVar13 + 0x14))();
  *(undefined2 *)(in_ECX + 0x3a) = *puVar7;
  uVar2 = (**(code **)(*piVar6 + 0x2c))();
  *(undefined1 *)((int)in_ECX + 0xf2) = uVar2;
  piVar13 = (int *)in_ECX[0x12];
  piVar6 = (int *)(**(code **)(*piVar13 + 0x24))();
  puVar7 = (undefined2 *)(**(code **)(*piVar6 + 8))();
  *(undefined2 *)(in_ECX + 0x3b) = *puVar7;
  piVar13 = (int *)(**(code **)(*piVar13 + 0x14))();
  in_ECX[0x2f] = *piVar13;
  piVar13 = (int *)(**(code **)(*(int *)in_ECX[0x10] + 0x24))();
  uVar3 = (**(code **)(*piVar13 + 8))();
  *(undefined2 *)((int)in_ECX + 0xea) = uVar3;
  uVar2 = (**(code **)(*piVar13 + 0x18))();
  *(undefined1 *)((int)in_ECX + 0xf1) = uVar2;
  piVar13 = (int *)(**(code **)(*(int *)in_ECX[8] + 0x54))();
  piVar13 = (int *)(**(code **)(*piVar13 + 4))();
  in_ECX[0x30] = *piVar13;
  piVar13 = (int *)(**(code **)(*(int *)in_ECX[0xd] + 0x3c))();
  piVar13 = (int *)(**(code **)(*piVar13 + 4))();
  in_ECX[0x31] = *piVar13;
  piVar13 = (int *)(**(code **)(*(int *)in_ECX[0xb] + 0x3c))();
  piVar13 = (int *)(**(code **)(*piVar13 + 4))();
  in_ECX[0x32] = *piVar13;
  if ((int *)in_ECX[1] == (int *)0x0) {
    piVar13 = (int *)0x0;
  }
  else {
    piVar13 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x18))();
  }
  pcVar8 = (char *)(**(code **)(*piVar13 + 8))();
  if (*(char *)((int)in_ECX + 0xee) != *pcVar8) {
    puVar9 = (undefined1 *)(**(code **)(*piVar13 + 8))();
    uVar10 = FUN_0044a580(auStack_fe + -6,s_____WARNING_____CLASS_HAS_CHANGE_009d0b28,
                          *(undefined1 *)((int)in_ECX + 0xee),*puVar9);
    FUN_00797b80(uVar10);
    puVar9 = (undefined1 *)(**(code **)(*piVar13 + 8))();
    *(undefined1 *)((int)in_ECX + 0xee) = *puVar9;
  }
  piVar13 = (int *)(**(code **)(*(int *)in_ECX[0x1f] + 0x14))();
  iVar5 = (**(code **)(*piVar13 + 8))();
  *(undefined2 *)((int)in_ECX + 0xf6) = *(undefined2 *)(iVar5 + 8);
  piVar13 = (int *)(**(code **)(*(int *)in_ECX[0x22] + 0x14))();
  iVar5 = (**(code **)(*piVar13 + 0xc))();
  in_ECX[0x40] = *(int *)(iVar5 + 0x38);
  iVar5 = (**(code **)(*piVar13 + 0xc))();
  *(undefined2 *)(in_ECX + 0x41) = *(undefined2 *)(iVar5 + 0x3c);
  iVar5 = (**(code **)(*piVar13 + 0xc))();
  *(undefined2 *)((int)in_ECX + 0x106) = *(undefined2 *)(iVar5 + 0x40);
  iVar5 = (**(code **)(*piVar13 + 0xc))();
  *(undefined2 *)(in_ECX + 0x42) = *(undefined2 *)(iVar5 + 0x3e);
  piVar13 = (int *)(**(code **)(*in_ECX + 8))();
  piVar13 = (int *)(**(code **)(*piVar13 + 0x2c))();
  iVar5 = (**(code **)(*piVar13 + 0x10))();
  iVar11 = (**(code **)(*piVar13 + 0x10))();
  if (*(char *)(iVar11 + 0x96c) == '\x01') {
    uVar3 = *(undefined2 *)(iVar5 + 0xeda);
    uVar1 = *(undefined2 *)(iVar5 + 0xedc);
    *(undefined2 *)(in_ECX + 0x39) = *(undefined2 *)(iVar5 + 0xed8);
    *(undefined2 *)(in_ECX + 0x37) = uVar3;
    *(undefined2 *)((int)in_ECX + 0xde) = uVar1;
  }
  else {
    iVar5 = (**(code **)(*piVar13 + 0x10))();
    if (*(char *)(iVar5 + 0xd77) == '\x01') {
      if ((int *)in_ECX[0x23] == (int *)0x0) {
        piVar13 = (int *)0x0;
      }
      else {
        piVar13 = (int *)(**(code **)(*(int *)in_ECX[0x23] + 0x18))();
      }
      puVar7 = (undefined2 *)(**(code **)(*piVar13 + 0x10))();
      *(undefined2 *)(in_ECX + 0x39) = *puVar7;
      iVar5 = (**(code **)(*piVar13 + 0x10))();
      *(undefined2 *)(in_ECX + 0x37) = *(undefined2 *)(iVar5 + 2);
      iVar5 = (**(code **)(*piVar13 + 0x10))();
      uVar4 = *(ushort *)(iVar5 + 4);
    }
    else {
      if ((int *)in_ECX[0x13] == (int *)0x0) {
        piVar13 = (int *)0x0;
      }
      else {
        piVar13 = (int *)(**(code **)(*(int *)in_ECX[0x13] + 0x18))();
      }
      piVar6 = (int *)(**(code **)(*in_ECX + 8))();
      puVar7 = (undefined2 *)(**(code **)(*piVar6 + 0x1c))();
      *(undefined2 *)(in_ECX + 0x39) = *puVar7;
      puVar12 = (ushort *)(**(code **)(*piVar13 + 0x3c))(param_1);
      *(ushort *)(in_ECX + 0x37) = *puVar12 >> 7;
      iVar5 = (**(code **)(*piVar13 + 0x3c))(param_1);
      uVar4 = *(ushort *)(iVar5 + 2) >> 7;
    }
    *(ushort *)((int)in_ECX + 0xde) = uVar4;
  }
  if ((int *)in_ECX[0x23] == (int *)0x0) {
    piVar13 = (int *)0x0;
  }
  else {
    piVar13 = (int *)(**(code **)(*(int *)in_ECX[0x23] + 0x18))();
  }
  puVar7 = (undefined2 *)(**(code **)(*piVar13 + 0x10))();
  *(undefined2 *)((int)in_ECX + 0xe6) = *puVar7;
  iVar5 = (**(code **)(*piVar13 + 0x10))();
  *(undefined2 *)(in_ECX + 0x38) = *(undefined2 *)(iVar5 + 2);
  iVar5 = (**(code **)(*piVar13 + 0x10))();
  *(undefined2 *)((int)in_ECX + 0xe2) = *(undefined2 *)(iVar5 + 4);
  piVar13 = (int *)(**(code **)(*(int *)in_ECX[0x24] + 0x14))();
  piVar13 = (int *)(**(code **)(*piVar13 + 8))();
  in_ECX[0x2d] = *piVar13;
  if ((int *)in_ECX[0x29] == (int *)0x0) {
    piVar13 = (int *)0x0;
  }
  else {
    piVar13 = (int *)(**(code **)(*(int *)in_ECX[0x29] + 0x18))();
  }
  piVar13 = (int *)(**(code **)(*piVar13 + 0xc))();
  in_ECX[0x43] = *piVar13;
  return;
}


