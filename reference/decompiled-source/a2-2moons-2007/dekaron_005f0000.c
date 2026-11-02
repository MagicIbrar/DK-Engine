// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x5f0000-0x5fffff

// ==== FUN_005f0030 @ 0x005f0030 ====

undefined4 FUN_005f0030(void)

{
  return 0x400;
}


// ==== FUN_005f0040 @ 0x005f0040 ====

undefined4 FUN_005f0040(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x700c);
}


// ==== __break @ 0x005f004f ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_005f0050 @ 0x005f0050 ====

void FUN_005f0050(byte param_1)

{
  void *in_ECX;
  
  FUN_005eff60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f0070 @ 0x005f0070 ====

void FUN_005f0070(byte param_1)

{
  void *in_ECX;
  
  FUN_005f0090();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f0090 @ 0x005f0090 ====

void FUN_005f0090(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984db3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c630c;
  _Memory = (void *)in_ECX[0x1c04];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c6304;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,0x400,(_func_void_void_ptr *)&LAB_005eff10);
    *in_ECX = &PTR_FUN_009c62ec;
    ExceptionList = local_c;
    return;
  }
  FUN_0060e440();
  _free(_Memory);
  return;
}


// ==== __break @ 0x005f012c ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_005f0130 @ 0x005f0130 ====

void * FUN_005f0130(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00984e09;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x7014);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x700c) = *(int *)(in_ECX + 0x700c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x1c);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0060e480();
      }
      *(undefined4 *)((int)param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x7010);
      *(void **)(in_ECX + 0x7010) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x7014) = *(undefined4 *)((int)param_2 + 0x10);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c61e0,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x18) = *(int *)((int)param_2 + 0x18) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f0240 @ 0x005f0240 ====

undefined4 FUN_005f0240(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c61e0,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x18);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x18);
    }
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x7014);
    *(int *)(in_ECX + 0x700c) = *(int *)(in_ECX + 0x700c) + -1;
    *(int *)(in_ECX + 0x7014) = param_2;
  }
  return 0;
}


// ==== FUN_005f02c0 @ 0x005f02c0 ====

void FUN_005f02c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005efe80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f02e0 @ 0x005f02e0 ====

void FUN_005f02e0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005f02e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_005f02f0 @ 0x005f02f0 ====

void FUN_005f02f0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005f02f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_005f0300 @ 0x005f0300 ====

void FUN_005f0300(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005f0305. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_005f0310 @ 0x005f0310 ====

void FUN_005f0310(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005f0315. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_005f0320 @ 0x005f0320 ====

void FUN_005f0320(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984e73;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c638c;
  pvVar1 = operator_new(0x1c18);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f04b0();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5abe0 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abe0 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f03b0 @ 0x005f03b0 ====

void FUN_005f03b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984e85;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c638c;
  DAT_00b5abe0 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c633c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f0410 @ 0x005f0410 ====

void FUN_005f0410(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6354;
  return;
}


// ==== FUN_005f0420 @ 0x005f0420 ====

void FUN_005f0420(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6354;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f0450 @ 0x005f0450 ====

void FUN_005f0450(void)

{
  FUN_0060e560();
  return;
}


// ==== FUN_005f0460 @ 0x005f0460 ====

void FUN_005f0460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c633c;
  return;
}


// ==== FUN_005f0470 @ 0x005f0470 ====

void FUN_005f0470(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c633c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f0490 @ 0x005f0490 ====

void FUN_005f0490(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c636c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,0x100,(_func_void_void_ptr *)&LAB_005f0440);
  return;
}


// ==== FUN_005f04b0 @ 0x005f04b0 ====

void FUN_005f04b0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984e28;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6374;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c636c;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x1c,0x100,FUN_005f0450,(_func_void_void_ptr *)&LAB_005f0440);
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


// ==== FUN_005f0560 @ 0x005f0560 ====

void FUN_005f0560(byte param_1)

{
  void *in_ECX;
  
  FUN_005f0490();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f0580 @ 0x005f0580 ====

void FUN_005f0580(byte param_1)

{
  void *in_ECX;
  
  FUN_005f05a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f05a0 @ 0x005f05a0 ====

void FUN_005f05a0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984e53;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6374;
  _Memory = (void *)in_ECX[0x704];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c636c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,0x100,(_func_void_void_ptr *)&LAB_005f0440);
    *in_ECX = &PTR_FUN_009c6354;
    ExceptionList = local_c;
    return;
  }
  FUN_0060e4e0();
  _free(_Memory);
  return;
}


// ==== FUN_005f0640 @ 0x005f0640 ====

void * FUN_005f0640(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00984ea9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x1c14);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x1c0c) = *(int *)(in_ECX + 0x1c0c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x1c);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0060e560();
      }
      *(undefined4 *)((int)param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x1c10);
      *(void **)(in_ECX + 0x1c10) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x1c14) = *(undefined4 *)((int)param_2 + 0x10);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c63a0,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x18) = *(int *)((int)param_2 + 0x18) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f0750 @ 0x005f0750 ====

undefined4 FUN_005f0750(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c63a0,0xa9);
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


// ==== FUN_005f07d0 @ 0x005f07d0 ====

void FUN_005f07d0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f03b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f07f0 @ 0x005f07f0 ====

void FUN_005f07f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c640c;
  return;
}


// ==== FUN_005f0800 @ 0x005f0800 ====

void FUN_005f0800(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c640c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f0820 @ 0x005f0820 ====

void FUN_005f0820(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6420;
  return;
}


// ==== FUN_005f0830 @ 0x005f0830 ====

void FUN_005f0830(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c643c;
  return;
}


// ==== FUN_005f0840 @ 0x005f0840 ====

void FUN_005f0840(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6494;
  return;
}


// ==== FUN_005f0850 @ 0x005f0850 ====

void FUN_005f0850(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6420;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f0870 @ 0x005f0870 ====

void FUN_005f0870(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c643c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f0890 @ 0x005f0890 ====

void FUN_005f0890(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6494;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f08b0 @ 0x005f08b0 ====

undefined4 FUN_005f08b0(undefined2 param_1)

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


// ==== FUN_005f08e0 @ 0x005f08e0 ====

int * FUN_005f08e0(ushort param_1,ushort param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return (int *)0x0;
    }
    piVar1 = *(int **)(*piVar2 + 4);
    iVar3 = (**(code **)(*piVar1 + 4))();
    if ((*(int *)(iVar3 + 4) <= (int)((uint)param_2 - (uint)param_1)) &&
       ((int)((uint)param_2 - (uint)param_1) <= *(int *)(iVar3 + 8))) break;
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar2);
  }
  return piVar1;
}


// ==== FUN_005f0940 @ 0x005f0940 ====

void FUN_005f0940(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984ec8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c64b4;
  DAT_00b5ab7c = 0;
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
  *in_ECX = &PTR_FUN_009c640c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005f09e0 @ 0x005f09e0 ====

void FUN_005f09e0(undefined2 *param_1)

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
  puStack_8 = &LAB_00984edd;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x14);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0060e650();
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


// ==== FUN_005f0a70 @ 0x005f0a70 ====

void FUN_005f0a70(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00984f05;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c64b4;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f0b80();
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
    uVar3 = FUN_005f1120(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab7c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab7c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f0b40 @ 0x005f0b40 ====

void FUN_005f0b40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c64ac;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005f0b60 @ 0x005f0b60 ====

void FUN_005f0b60(byte param_1)

{
  void *in_ECX;
  
  FUN_005f0b40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f0b80 @ 0x005f0b80 ====

void FUN_005f0b80(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984f18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c64c8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c64ac;
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


// ==== FUN_005f0c30 @ 0x005f0c30 ====

void FUN_005f0c30(byte param_1)

{
  void *in_ECX;
  
  FUN_005f0c50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f0c50 @ 0x005f0c50 ====

void FUN_005f0c50(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984f43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c64c8;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c64ac;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c6420;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_005f0cd0 @ 0x005f0cd0 ====

void * FUN_005f0cd0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00984f5b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c64e0,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f0db0 @ 0x005f0db0 ====

undefined4 FUN_005f0db0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c64e0,0xa9);
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


// ==== FUN_005f0e30 @ 0x005f0e30 ====

void FUN_005f0e30(byte param_1)

{
  void *in_ECX;
  
  FUN_005f0940();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f0e50 @ 0x005f0e50 ====

void FUN_005f0e50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c655c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005f0e70 @ 0x005f0e70 ====

void FUN_005f0e70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984f83;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6564;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c655c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c6494;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_005f0ef0 @ 0x005f0ef0 ====

undefined4 FUN_005f0ef0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c64e0,0xa9);
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


// ==== FUN_005f0f70 @ 0x005f0f70 ====

undefined4 * FUN_005f0f70(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c64e0,0x85);
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


// ==== FUN_005f1030 @ 0x005f1030 ====

void FUN_005f1030(byte param_1)

{
  void *in_ECX;
  
  FUN_005f0e50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1050 @ 0x005f1050 ====

void FUN_005f1050(byte param_1)

{
  void *in_ECX;
  
  FUN_005f0e70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1070 @ 0x005f1070 ====

void FUN_005f1070(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984f98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6564;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c655c;
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


// ==== FUN_005f1120 @ 0x005f1120 ====

void FUN_005f1120(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984fb8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c657c;
  FUN_005f1070();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f1180 @ 0x005f1180 ====

void FUN_005f1180(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f11a0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f11a0 @ 0x005f11a0 ====

void FUN_005f11a0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005f11a0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005f11a0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005f11e0 @ 0x005f11e0 ====

void FUN_005f11e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f1200(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f1200 @ 0x005f1200 ====

void FUN_005f1200(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005f1200(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005f1200(param_1[3]);
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


// ==== FUN_005f1270 @ 0x005f1270 ====

void FUN_005f1270(byte param_1)

{
  void *in_ECX;
  
  FUN_005f1290();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1290 @ 0x005f1290 ====

void FUN_005f1290(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00984fe3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c657c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005f1200(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005f0e70();
  *in_ECX = &PTR_FUN_009c643c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f1300 @ 0x005f1300 ====

void FUN_005f1300(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c65d4;
  return;
}


// ==== FUN_005f1310 @ 0x005f1310 ====

void FUN_005f1310(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c65d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1330 @ 0x005f1330 ====

void FUN_005f1330(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c65e8;
  return;
}


// ==== FUN_005f1340 @ 0x005f1340 ====

void FUN_005f1340(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6604;
  return;
}


// ==== FUN_005f1350 @ 0x005f1350 ====

void FUN_005f1350(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c665c;
  return;
}


// ==== FUN_005f1360 @ 0x005f1360 ====

void FUN_005f1360(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c65e8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1380 @ 0x005f1380 ====

void FUN_005f1380(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6604;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f13a0 @ 0x005f13a0 ====

void FUN_005f13a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c665c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f13c0 @ 0x005f13c0 ====

undefined4 FUN_005f13c0(undefined2 param_1)

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


// ==== FUN_005f13f0 @ 0x005f13f0 ====

int * FUN_005f13f0(ushort param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  if (piVar2 != (int *)0x0) {
    do {
      piVar1 = *(int **)(*piVar2 + 4);
      iVar3 = (**(code **)(*piVar1 + 4))();
      if ((*(int *)(iVar3 + 4) <= (int)(uint)param_1) && ((int)(uint)param_1 <= *(int *)(iVar3 + 8))
         ) {
        return piVar1;
      }
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar2);
    } while (piVar2 != (int *)0x0);
  }
  return (int *)0x0;
}


// ==== FUN_005f1450 @ 0x005f1450 ====

void FUN_005f1450(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00984ff8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c667c;
  DAT_00b5ab80 = 0;
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
  *in_ECX = &PTR_FUN_009c65d4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005f14f0 @ 0x005f14f0 ====

void FUN_005f14f0(undefined2 *param_1)

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
  puStack_8 = &LAB_0098500d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x14);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0060e6e0();
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


// ==== FUN_005f1580 @ 0x005f1580 ====

void FUN_005f1580(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00985035;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c667c;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f1690();
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
    uVar3 = FUN_005f1c30(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab80 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab80 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f1650 @ 0x005f1650 ====

void FUN_005f1650(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6674;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005f1670 @ 0x005f1670 ====

void FUN_005f1670(byte param_1)

{
  void *in_ECX;
  
  FUN_005f1650();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1690 @ 0x005f1690 ====

void FUN_005f1690(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985048;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6690;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c6674;
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


// ==== FUN_005f1740 @ 0x005f1740 ====

void FUN_005f1740(byte param_1)

{
  void *in_ECX;
  
  FUN_005f1760();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1760 @ 0x005f1760 ====

void FUN_005f1760(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985073;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6690;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c6674;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c65e8;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_005f17e0 @ 0x005f17e0 ====

void * FUN_005f17e0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098508b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c66a8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f18c0 @ 0x005f18c0 ====

undefined4 FUN_005f18c0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c66a8,0xa9);
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


// ==== FUN_005f1940 @ 0x005f1940 ====

void FUN_005f1940(byte param_1)

{
  void *in_ECX;
  
  FUN_005f1450();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1960 @ 0x005f1960 ====

void FUN_005f1960(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6724;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005f1980 @ 0x005f1980 ====

void FUN_005f1980(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009850b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c672c;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c6724;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c665c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_005f1a00 @ 0x005f1a00 ====

undefined4 FUN_005f1a00(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c66a8,0xa9);
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


// ==== FUN_005f1a80 @ 0x005f1a80 ====

undefined4 * FUN_005f1a80(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c66a8,0x85);
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


// ==== FUN_005f1b40 @ 0x005f1b40 ====

void FUN_005f1b40(byte param_1)

{
  void *in_ECX;
  
  FUN_005f1960();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1b60 @ 0x005f1b60 ====

void FUN_005f1b60(byte param_1)

{
  void *in_ECX;
  
  FUN_005f1980();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1b80 @ 0x005f1b80 ====

void FUN_005f1b80(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009850c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c672c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c6724;
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


// ==== FUN_005f1c30 @ 0x005f1c30 ====

void FUN_005f1c30(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009850e8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6744;
  FUN_005f1b80();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f1c90 @ 0x005f1c90 ====

void FUN_005f1c90(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f1cb0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f1cb0 @ 0x005f1cb0 ====

void FUN_005f1cb0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005f1cb0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005f1cb0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005f1cf0 @ 0x005f1cf0 ====

void FUN_005f1cf0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f1d10(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f1d10 @ 0x005f1d10 ====

void FUN_005f1d10(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005f1d10(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005f1d10(param_1[3]);
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


// ==== FUN_005f1d80 @ 0x005f1d80 ====

void FUN_005f1d80(byte param_1)

{
  void *in_ECX;
  
  FUN_005f1da0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1da0 @ 0x005f1da0 ====

void FUN_005f1da0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00985113;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6744;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005f1d10(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005f1980();
  *in_ECX = &PTR_FUN_009c6604;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f1e10 @ 0x005f1e10 ====

void FUN_005f1e10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c679c;
  return;
}


// ==== FUN_005f1e20 @ 0x005f1e20 ====

void FUN_005f1e20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c679c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1e40 @ 0x005f1e40 ====

void FUN_005f1e40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c67b0;
  return;
}


// ==== FUN_005f1e50 @ 0x005f1e50 ====

void FUN_005f1e50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c67cc;
  return;
}


// ==== FUN_005f1e60 @ 0x005f1e60 ====

void FUN_005f1e60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6824;
  return;
}


// ==== FUN_005f1e70 @ 0x005f1e70 ====

void FUN_005f1e70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c67b0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1e90 @ 0x005f1e90 ====

void FUN_005f1e90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c67cc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1eb0 @ 0x005f1eb0 ====

void FUN_005f1eb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6824;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f1ed0 @ 0x005f1ed0 ====

undefined4 FUN_005f1ed0(undefined2 param_1)

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


// ==== FUN_005f1f00 @ 0x005f1f00 ====

int * FUN_005f1f00(ushort param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  if (piVar2 != (int *)0x0) {
    do {
      piVar1 = *(int **)(*piVar2 + 4);
      iVar3 = (**(code **)(*piVar1 + 4))();
      if ((*(int *)(iVar3 + 4) <= (int)(uint)param_1) && ((int)(uint)param_1 <= *(int *)(iVar3 + 8))
         ) {
        return piVar1;
      }
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar2);
    } while (piVar2 != (int *)0x0);
  }
  return (int *)0x0;
}


// ==== FUN_005f1f60 @ 0x005f1f60 ====

void FUN_005f1f60(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985128;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c6844;
  DAT_00b5ab84 = 0;
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
  *in_ECX = &PTR_FUN_009c679c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005f2000 @ 0x005f2000 ====

void FUN_005f2000(undefined2 *param_1)

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
  puStack_8 = &LAB_0098513d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x14);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0060e770();
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


// ==== FUN_005f2090 @ 0x005f2090 ====

void FUN_005f2090(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00985165;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6844;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f21a0();
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
    uVar3 = FUN_005f2740(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab84 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab84 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f2160 @ 0x005f2160 ====

void FUN_005f2160(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c683c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005f2180 @ 0x005f2180 ====

void FUN_005f2180(byte param_1)

{
  void *in_ECX;
  
  FUN_005f2160();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f21a0 @ 0x005f21a0 ====

void FUN_005f21a0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985178;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6858;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c683c;
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


// ==== FUN_005f2250 @ 0x005f2250 ====

void FUN_005f2250(byte param_1)

{
  void *in_ECX;
  
  FUN_005f2270();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f2270 @ 0x005f2270 ====

void FUN_005f2270(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009851a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6858;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c683c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c67b0;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_005f22f0 @ 0x005f22f0 ====

void * FUN_005f22f0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009851bb;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c6870,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f23d0 @ 0x005f23d0 ====

undefined4 FUN_005f23d0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c6870,0xa9);
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


// ==== FUN_005f2450 @ 0x005f2450 ====

void FUN_005f2450(byte param_1)

{
  void *in_ECX;
  
  FUN_005f1f60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f2470 @ 0x005f2470 ====

void FUN_005f2470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c68e0;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005f2490 @ 0x005f2490 ====

void FUN_005f2490(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009851e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c68e8;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c68e0;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c6824;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_005f2510 @ 0x005f2510 ====

undefined4 FUN_005f2510(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c6870,0xa9);
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


// ==== FUN_005f2590 @ 0x005f2590 ====

undefined4 * FUN_005f2590(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c6870,0x85);
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


// ==== FUN_005f2650 @ 0x005f2650 ====

void FUN_005f2650(byte param_1)

{
  void *in_ECX;
  
  FUN_005f2470();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f2670 @ 0x005f2670 ====

void FUN_005f2670(byte param_1)

{
  void *in_ECX;
  
  FUN_005f2490();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f2690 @ 0x005f2690 ====

void FUN_005f2690(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009851f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c68e8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c68e0;
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


// ==== FUN_005f2740 @ 0x005f2740 ====

void FUN_005f2740(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985218;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6904;
  FUN_005f2690();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f27a0 @ 0x005f27a0 ====

void FUN_005f27a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f27c0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f27c0 @ 0x005f27c0 ====

void FUN_005f27c0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005f27c0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005f27c0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005f2800 @ 0x005f2800 ====

void FUN_005f2800(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f2820(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f2820 @ 0x005f2820 ====

void FUN_005f2820(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005f2820(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005f2820(param_1[3]);
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


// ==== FUN_005f2890 @ 0x005f2890 ====

void FUN_005f2890(byte param_1)

{
  void *in_ECX;
  
  FUN_005f28b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f28b0 @ 0x005f28b0 ====

void FUN_005f28b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00985243;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6904;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005f2820(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005f2490();
  *in_ECX = &PTR_FUN_009c67cc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f2920 @ 0x005f2920 ====

void FUN_005f2920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c695c;
  return;
}


// ==== FUN_005f2930 @ 0x005f2930 ====

void FUN_005f2930(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c695c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f2950 @ 0x005f2950 ====

void FUN_005f2950(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c696c;
  return;
}


// ==== FUN_005f2960 @ 0x005f2960 ====

void FUN_005f2960(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6984;
  return;
}


// ==== FUN_005f2970 @ 0x005f2970 ====

void FUN_005f2970(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c69dc;
  return;
}


// ==== FUN_005f2980 @ 0x005f2980 ====

void FUN_005f2980(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c696c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f29a0 @ 0x005f29a0 ====

void FUN_005f29a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6984;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f29c0 @ 0x005f29c0 ====

void FUN_005f29c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c69dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f29e0 @ 0x005f29e0 ====

undefined4 FUN_005f29e0(undefined2 param_1)

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


// ==== FUN_005f2a10 @ 0x005f2a10 ====

void FUN_005f2a10(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985258;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c69fc;
  DAT_00b5abb0 = 0;
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
  *in_ECX = &PTR_FUN_009c695c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005f2ab0 @ 0x005f2ab0 ====

void FUN_005f2ab0(byte *param_1)

{
  void *pvVar1;
  int *piVar2;
  ushort *puVar3;
  int in_ECX;
  void *unaff_EDI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098526d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x28);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0060e800();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 8))(param_1);
  puVar3 = (ushort *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = (ushort)*param_1;
  *(int **)(puVar3 + 2) = piVar2;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  ExceptionList = unaff_EDI;
  return;
}


// ==== FUN_005f2b40 @ 0x005f2b40 ====

void FUN_005f2b40(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00985295;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c69fc;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f2c50();
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
    uVar3 = FUN_005f31f0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abb0 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abb0 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f2c10 @ 0x005f2c10 ====

void FUN_005f2c10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c69f4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_005f2c30 @ 0x005f2c30 ====

void FUN_005f2c30(byte param_1)

{
  void *in_ECX;
  
  FUN_005f2c10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f2c50 @ 0x005f2c50 ====

void FUN_005f2c50(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009852a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6a0c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c69f4;
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


// ==== FUN_005f2d00 @ 0x005f2d00 ====

void FUN_005f2d00(byte param_1)

{
  void *in_ECX;
  
  FUN_005f2d20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f2d20 @ 0x005f2d20 ====

void FUN_005f2d20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009852d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6a0c;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c69f4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c696c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_005f2da0 @ 0x005f2da0 ====

void * FUN_005f2da0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009852eb;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c6a20,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f2e80 @ 0x005f2e80 ====

undefined4 FUN_005f2e80(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c6a20,0xa9);
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


// ==== FUN_005f2f00 @ 0x005f2f00 ====

void FUN_005f2f00(byte param_1)

{
  void *in_ECX;
  
  FUN_005f2a10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f2f20 @ 0x005f2f20 ====

void FUN_005f2f20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6a9c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_005f2f40 @ 0x005f2f40 ====

void FUN_005f2f40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985313;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6aa4;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c6a9c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c69dc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_005f2fc0 @ 0x005f2fc0 ====

undefined4 FUN_005f2fc0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c6a20,0xa9);
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


// ==== FUN_005f3040 @ 0x005f3040 ====

undefined4 * FUN_005f3040(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c6a20,0x85);
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


// ==== FUN_005f3100 @ 0x005f3100 ====

void FUN_005f3100(byte param_1)

{
  void *in_ECX;
  
  FUN_005f2f20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f3120 @ 0x005f3120 ====

void FUN_005f3120(byte param_1)

{
  void *in_ECX;
  
  FUN_005f2f40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f3140 @ 0x005f3140 ====

void FUN_005f3140(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985328;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6aa4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c6a9c;
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


// ==== FUN_005f31f0 @ 0x005f31f0 ====

void FUN_005f31f0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985348;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6abc;
  FUN_005f3140();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f3250 @ 0x005f3250 ====

void FUN_005f3250(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f3270(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f3270 @ 0x005f3270 ====

void FUN_005f3270(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005f3270(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005f3270(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005f32b0 @ 0x005f32b0 ====

void FUN_005f32b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f32d0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f32d0 @ 0x005f32d0 ====

void FUN_005f32d0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005f32d0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005f32d0(param_1[3]);
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


// ==== FUN_005f3350 @ 0x005f3350 ====

void FUN_005f3350(byte param_1)

{
  void *in_ECX;
  
  FUN_005f3370();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f3370 @ 0x005f3370 ====

void FUN_005f3370(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00985373;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6abc;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005f32d0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005f2f40();
  *in_ECX = &PTR_FUN_009c6984;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f33e0 @ 0x005f33e0 ====

void FUN_005f33e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6b14;
  return;
}


// ==== FUN_005f33f0 @ 0x005f33f0 ====

void FUN_005f33f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6b14;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f3410 @ 0x005f3410 ====

void FUN_005f3410(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6b24;
  return;
}


// ==== FUN_005f3420 @ 0x005f3420 ====

void FUN_005f3420(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6b3c;
  return;
}


// ==== FUN_005f3430 @ 0x005f3430 ====

void FUN_005f3430(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6b94;
  return;
}


// ==== FUN_005f3440 @ 0x005f3440 ====

void FUN_005f3440(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6b24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f3460 @ 0x005f3460 ====

void FUN_005f3460(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6b3c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f3480 @ 0x005f3480 ====

void FUN_005f3480(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6b94;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f34a0 @ 0x005f34a0 ====

undefined4 FUN_005f34a0(undefined4 param_1)

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


// ==== FUN_005f34d0 @ 0x005f34d0 ====

void FUN_005f34d0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985388;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c6bb4;
  DAT_00b5aba4 = 0;
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
  *in_ECX = &PTR_FUN_009c6b14;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005f3570 @ 0x005f3570 ====

void FUN_005f3570(undefined4 *param_1)

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
  puStack_8 = &LAB_0098539d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(8);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0060e880();
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


// ==== FUN_005f3600 @ 0x005f3600 ====

void FUN_005f3600(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009853c5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6bb4;
  pvVar2 = operator_new(0xa18);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f3710();
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
    uVar3 = FUN_005f3cb0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aba4 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aba4 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f36d0 @ 0x005f36d0 ====

void FUN_005f36d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6bac;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005f36f0 @ 0x005f36f0 ====

void FUN_005f36f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f36d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f3710 @ 0x005f3710 ====

void FUN_005f3710(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009853d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6bc4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c6bac;
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


// ==== FUN_005f37c0 @ 0x005f37c0 ====

void FUN_005f37c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f37e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f37e0 @ 0x005f37e0 ====

void FUN_005f37e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985403;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6bc4;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c6bac;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c6b24;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_005f3860 @ 0x005f3860 ====

void * FUN_005f3860(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098541b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c6bd8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f3940 @ 0x005f3940 ====

undefined4 FUN_005f3940(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c6bd8,0xa9);
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


// ==== FUN_005f39c0 @ 0x005f39c0 ====

void FUN_005f39c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f34d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f39e0 @ 0x005f39e0 ====

void FUN_005f39e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6c54;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005f3a00 @ 0x005f3a00 ====

void FUN_005f3a00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985443;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6c5c;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c6c54;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c6b94;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_005f3a80 @ 0x005f3a80 ====

undefined4 FUN_005f3a80(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c6bd8,0xa9);
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


// ==== FUN_005f3b00 @ 0x005f3b00 ====

undefined4 * FUN_005f3b00(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c6bd8,0x85);
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


// ==== FUN_005f3bc0 @ 0x005f3bc0 ====

void FUN_005f3bc0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f39e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f3be0 @ 0x005f3be0 ====

void FUN_005f3be0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f3a00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f3c00 @ 0x005f3c00 ====

void FUN_005f3c00(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985458;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6c5c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c6c54;
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


// ==== FUN_005f3cb0 @ 0x005f3cb0 ====

void FUN_005f3cb0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985478;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6c74;
  FUN_005f3c00();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f3d10 @ 0x005f3d10 ====

void FUN_005f3d10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f3d30(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f3d30 @ 0x005f3d30 ====

void FUN_005f3d30(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005f3d30(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005f3d30(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005f3d70 @ 0x005f3d70 ====

void FUN_005f3d70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f3d90(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f3d90 @ 0x005f3d90 ====

void FUN_005f3d90(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005f3d90(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005f3d90(param_1[3]);
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


// ==== FUN_005f3e00 @ 0x005f3e00 ====

void FUN_005f3e00(byte param_1)

{
  void *in_ECX;
  
  FUN_005f3e20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f3e20 @ 0x005f3e20 ====

void FUN_005f3e20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009854a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6c74;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005f3d90(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005f3a00();
  *in_ECX = &PTR_FUN_009c6b3c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f3e90 @ 0x005f3e90 ====

void FUN_005f3e90(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005f3e95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_005f3ea0 @ 0x005f3ea0 ====

void FUN_005f3ea0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005f3ea5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_005f3eb0 @ 0x005f3eb0 ====

void FUN_005f3eb0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005f3eb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_005f3ec0 @ 0x005f3ec0 ====

void FUN_005f3ec0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005f3ec5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_005f3ed0 @ 0x005f3ed0 ====

void FUN_005f3ed0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009854e3;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6ea0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a778 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a778 = in_ECX;
  }
  pvVar2 = operator_new(0x30);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_005f4070();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f3f70 @ 0x005f3f70 ====

void FUN_005f3f70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009854f5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6ea0;
  DAT_00b5a778 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c6e50;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f3fd0 @ 0x005f3fd0 ====

void FUN_005f3fd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6e68;
  return;
}


// ==== FUN_005f3fe0 @ 0x005f3fe0 ====

void FUN_005f3fe0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6e68;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f4010 @ 0x005f4010 ====

void FUN_005f4010(void)

{
  FUN_0060e900();
  return;
}


// ==== FUN_005f4020 @ 0x005f4020 ====

void FUN_005f4020(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6e50;
  return;
}


// ==== FUN_005f4030 @ 0x005f4030 ====

void FUN_005f4030(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6e50;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f4050 @ 0x005f4050 ====

void FUN_005f4050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6e80;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x18,1,(_func_void_void_ptr *)&LAB_005f4000);
  return;
}


// ==== FUN_005f4070 @ 0x005f4070 ====

void FUN_005f4070(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009854b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6e88;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c6e80;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x18,1,FUN_005f4010,(_func_void_void_ptr *)&LAB_005f4000);
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


// ==== FUN_005f40f0 @ 0x005f40f0 ====

void FUN_005f40f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f4050();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f4110 @ 0x005f4110 ====

void * FUN_005f4110(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00985519;
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
        FUN_0060e900();
      }
      *(undefined4 *)((int)param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x28);
      *(void **)(in_ECX + 0x28) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)((int)param_2 + 0xc);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0x14) = param_1;
    *(undefined4 *)((int)param_2 + 0xc) = 0;
    FUN_0060e8c0();
  }
  else {
    if (*(int *)((int)param_2 + 0x14) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c6eb8,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x14) = *(int *)((int)param_2 + 0x14) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f4220 @ 0x005f4220 ====

undefined4 FUN_005f4220(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x14) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c6eb8,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x14);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x14);
    }
    FUN_0060e8d0();
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x2c);
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + -1;
    *(int *)(in_ECX + 0x2c) = param_2;
  }
  return 0;
}


// ==== FUN_005f42a0 @ 0x005f42a0 ====

void FUN_005f42a0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f42c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f42c0 @ 0x005f42c0 ====

void FUN_005f42c0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00985549;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6e88;
  local_4 = 1;
  if (in_ECX[9] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009c6d38,
                         s_d__usa_24_0_1_2__develop_share_l_009c6cd0,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[7] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009c6db8,
                         s_d__usa_24_0_1_2__develop_share_l_009c6d50,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[10];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009c6e80;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x18,1,(_func_void_void_ptr *)&LAB_005f4000);
    *in_ECX = &PTR_FUN_009c6e68;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0x14) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009c6e38,
                         s_d__usa_24_0_1_2__develop_share_l_009c6dd0,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_0060e8b0();
  _free(_Memory);
  return;
}


// ==== FUN_005f43f0 @ 0x005f43f0 ====

void FUN_005f43f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f3f70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f4410 @ 0x005f4410 ====

void FUN_005f4410(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6f40;
  return;
}


// ==== FUN_005f4420 @ 0x005f4420 ====

void FUN_005f4420(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6f40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f4440 @ 0x005f4440 ====

void FUN_005f4440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6f5c;
  return;
}


// ==== __break @ 0x005f4449 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_005f4450 @ 0x005f4450 ====

void FUN_005f4450(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6fb4;
  return;
}


// ==== FUN_005f4460 @ 0x005f4460 ====

void FUN_005f4460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6fcc;
  return;
}


// ==== FUN_005f4470 @ 0x005f4470 ====

void FUN_005f4470(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6f5c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f4490 @ 0x005f4490 ====

void FUN_005f4490(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6fb4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f44b0 @ 0x005f44b0 ====

void FUN_005f44b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6fcc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f44d0 @ 0x005f44d0 ====

undefined4 FUN_005f44d0(undefined4 *param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = *param_1;
  local_8 = param_1[1];
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(&local_c);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 8);
}


// ==== FUN_005f4510 @ 0x005f4510 ====

undefined4 FUN_005f4510(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 8);
}


// ==== FUN_005f4530 @ 0x005f4530 ====

undefined4 FUN_005f4530(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(undefined4 *)(in_ECX + 0xc));
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 8);
}


// ==== FUN_005f4550 @ 0x005f4550 ====

void FUN_005f4550(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985568;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c6fec;
  DAT_00b5a780 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    if (*(undefined4 **)(*piVar1 + 8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(*piVar1 + 8))(1);
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
  *in_ECX = &PTR_FUN_009c6f40;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005f45f0 @ 0x005f45f0 ====

void FUN_005f45f0(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 uStack_10c;
  undefined4 auStack_108 [66];
  
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 4))();
  uStack_10c = *puVar1;
  auStack_108[0] = puVar1[1];
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(&uStack_10c);
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
    puVar3 = (undefined4 *)(**(code **)(*param_1 + 4))();
    *puVar1 = *puVar3;
    puVar1[1] = puVar3[1];
    puVar1[2] = param_1;
    (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar1);
    return;
  }
  (**(code **)*param_1)(1);
  FUN_0044a580(auStack_108,&DAT_009c6f38,s_Invalid_Action_CSV_009c6f24);
  FUN_00797b80(auStack_108);
  return;
}


// ==== FUN_005f46b0 @ 0x005f46b0 ====

void FUN_005f46b0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00985590;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c6fec;
  in_ECX[3] = 0;
  pvVar2 = operator_new(0x1818);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f47d0();
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
    uVar3 = FUN_005f4ce0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a780 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a780 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f4780 @ 0x005f4780 ====

void FUN_005f4780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c6fe4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x18,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_005f47a0 @ 0x005f47a0 ====

void FUN_005f47a0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f4780();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f47d0 @ 0x005f47d0 ====

void FUN_005f47d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009855a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7004;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c6fe4;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x18,0x100,(_func_void_void_ptr *)&LAB_005f47c0,FUN_006ef6d0);
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


// ==== FUN_005f4880 @ 0x005f4880 ====

void FUN_005f4880(byte param_1)

{
  void *in_ECX;
  
  FUN_005f48a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f48a0 @ 0x005f48a0 ====

void FUN_005f48a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009855d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7004;
  local_4 = 1;
  if ((void *)in_ECX[0x604] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c6fe4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x18,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c6fb4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x604]);
  return;
}


// ==== FUN_005f4920 @ 0x005f4920 ====

undefined4 * FUN_005f4920(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[5] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3b48,0x85);
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
      *puVar2 = 0x11;
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


// ==== FUN_005f49f0 @ 0x005f49f0 ====

undefined4 FUN_005f49f0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x14) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3b48,0xa9);
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


// ==== FUN_005f4a70 @ 0x005f4a70 ====

void FUN_005f4a70(byte param_1)

{
  void *in_ECX;
  
  FUN_005f4550();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f4a90 @ 0x005f4a90 ====

void FUN_005f4a90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c701c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_005f4ab0 @ 0x005f4ab0 ====

void FUN_005f4ab0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009855f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7024;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c701c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c6fcc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_005f4b30 @ 0x005f4b30 ====

undefined4 * FUN_005f4b30(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3b48,0x85);
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


// ==== FUN_005f4bf0 @ 0x005f4bf0 ====

void FUN_005f4bf0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f4a90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f4c10 @ 0x005f4c10 ====

void FUN_005f4c10(byte param_1)

{
  void *in_ECX;
  
  FUN_005f4ab0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f4c30 @ 0x005f4c30 ====

void FUN_005f4c30(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985608;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7024;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c701c;
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


// ==== FUN_005f4ce0 @ 0x005f4ce0 ====

void FUN_005f4ce0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985628;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c703c;
  FUN_005f4c30();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f4d40 @ 0x005f4d40 ====

void FUN_005f4d40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f4d60(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f4d60 @ 0x005f4d60 ====

void FUN_005f4d60(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005f4d60(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005f4d60(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005f4da0 @ 0x005f4da0 ====

undefined4 * FUN_005f4da0(void)

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
  iVar4 = FUN_005f4e50(iVar1,*puVar2);
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
        goto LAB_005f4e39;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
LAB_005f4e39:
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_005f4e50(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_005f4e50 @ 0x005f4e50 ====

uint FUN_005f4e50(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = FUN_005f4e90(param_2);
  if (cVar1 == '\0') {
    cVar1 = FUN_005f4e90(param_1);
    return (uint)(cVar1 != '\0');
  }
  return 0xffffffff;
}


// ==== FUN_005f4e90 @ 0x005f4e90 ====

int FUN_005f4e90(int *param_1)

{
  int iVar1;
  uint3 uVar2;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if ((iVar1 < *param_1) ||
     ((iVar1 <= *param_1 && (*(ushort *)(in_ECX + 1) < *(ushort *)(param_1 + 1))))) {
    return CONCAT31(uVar2,1);
  }
  return (uint)uVar2 << 8;
}


// ==== FUN_005f4ec0 @ 0x005f4ec0 ====

void FUN_005f4ec0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f4ee0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f4ee0 @ 0x005f4ee0 ====

void FUN_005f4ee0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005f4ee0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005f4ee0(param_1[3]);
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


// ==== FUN_005f4f60 @ 0x005f4f60 ====

int * FUN_005f4f60(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int *piVar4;
  
  piVar4 = *(int **)(in_ECX + 4);
  if (*(int **)(in_ECX + 4) == (int *)0x0) {
    return (int *)0x0;
  }
  do {
    piVar3 = piVar4;
    piVar4 = (int *)*piVar3;
    cVar1 = FUN_0059a550(piVar4);
    if (cVar1 == '\0') {
      if ((*param_1 <= *piVar4) &&
         ((*param_1 < *piVar4 || (*(ushort *)(param_1 + 1) <= *(ushort *)(piVar4 + 1))))) {
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return piVar3;
      }
      iVar2 = 1;
    }
    else {
      iVar2 = -1;
    }
    if (iVar2 < 0) {
      piVar4 = (int *)piVar3[2];
    }
    else {
      piVar4 = (int *)piVar3[3];
    }
  } while (piVar4 != (int *)0x0);
  FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
  return (int *)0x0;
}


// ==== FUN_005f4fe0 @ 0x005f4fe0 ====

void FUN_005f4fe0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f5000();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f5000 @ 0x005f5000 ====

void FUN_005f5000(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00985653;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c703c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005f4ee0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005f4ab0();
  *in_ECX = &PTR_FUN_009c6f5c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f5070 @ 0x005f5070 ====

void FUN_005f5070(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7094;
  return;
}


// ==== FUN_005f5080 @ 0x005f5080 ====

void FUN_005f5080(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7094;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f50a0 @ 0x005f50a0 ====

void FUN_005f50a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c70a0;
  return;
}


// ==== FUN_005f50b0 @ 0x005f50b0 ====

void FUN_005f50b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c70bc;
  return;
}


// ==== FUN_005f50c0 @ 0x005f50c0 ====

void FUN_005f50c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7114;
  return;
}


// ==== FUN_005f50d0 @ 0x005f50d0 ====

void FUN_005f50d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c70a0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f50f0 @ 0x005f50f0 ====

void FUN_005f50f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c70bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f5110 @ 0x005f5110 ====

void FUN_005f5110(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7114;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f5130 @ 0x005f5130 ====

undefined4 FUN_005f5130(undefined4 param_1)

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


// ==== FUN_005f5160 @ 0x005f5160 ====

void FUN_005f5160(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985668;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c7134;
  DAT_00b5af4c = 0;
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
  *in_ECX = &PTR_FUN_009c7094;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005f5200 @ 0x005f5200 ====

void FUN_005f5200(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009857da;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c7134;
  pvVar2 = operator_new(0x2c0);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f5b20();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x468);
  local_4._0_1_ = 2;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f60f0(*puVar1);
  }
  in_ECX[2] = uVar3;
  local_4 = (uint)local_4._1_3_ << 8;
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 6;
  pvVar2 = operator_new(4);
  pvStack_c._0_1_ = 3;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00611660();
  }
  puVar4[1] = uVar3;
  pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0xd;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00611500();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0xc;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00611370();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 8;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00611260();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 7;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00610f40();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00610d60();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 4;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00610c70();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0xe;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00610920();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 5;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_006107b0();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 9;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_006106d0();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 2;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00610380();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0xb;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00610180();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 10;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060ff20();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 1;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060fe60();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0xf;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060fd20();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x11;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060fad0();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x12;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060fb00();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x13;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060f960();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x14;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060f880();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x15;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060f5c0();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x16;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060f5f0();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x17;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060f620();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x18;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060f2e0();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x19;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060f310();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x1a;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060f1b0();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x1b;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060f0d0();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x1c;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060ed90();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x1d;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060ebc0();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x1e;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060eae0();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  puVar4 = (undefined4 *)(**(code **)(*(int *)*puVar1 + 0xc))(1,0);
  *puVar4 = 0x1f;
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0060ea00();
  }
  puVar4[1] = uVar3;
  (**(code **)(*(int *)in_ECX[2] + 0x28))(puVar4);
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5af4c = (undefined4 *)0x0;
    ExceptionList = pvVar2;
    return;
  }
  DAT_00b5af4c = in_ECX;
  ExceptionList = pvVar2;
  return;
}


// ==== FUN_005f5ae0 @ 0x005f5ae0 ====

void FUN_005f5ae0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c712c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x22,FUN_006ef6d0);
  return;
}


// ==== FUN_005f5b00 @ 0x005f5b00 ====

void FUN_005f5b00(byte param_1)

{
  void *in_ECX;
  
  FUN_005f5ae0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f5b20 @ 0x005f5b20 ====

void FUN_005f5b20(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009857f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7140;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c712c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x22,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0xac] = 0;
  in_ECX[0xac] = in_ECX[0xac] + 0x22;
  in_ECX[0xaf] = in_ECX + 2;
  in_ECX[0xad] = 0;
  in_ECX[0xae] = 0;
  iVar2 = 0x21;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0xa9] = 0;
  in_ECX[0xaa] = 0;
  in_ECX[0xab] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f5bd0 @ 0x005f5bd0 ====

undefined4 FUN_005f5bd0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2b4);
}


// ==== FUN_005f5be0 @ 0x005f5be0 ====

void FUN_005f5be0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f5c00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f5c00 @ 0x005f5c00 ====

void FUN_005f5c00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985823;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7140;
  local_4 = 1;
  if ((void *)in_ECX[0xae] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c712c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x22,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c70a0;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xae]);
  return;
}


// ==== FUN_005f5c80 @ 0x005f5c80 ====

void * FUN_005f5c80(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098583b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 700);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x2b4) = *(int *)(in_ECX + 0x2b4) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x2b8);
      *(void **)(in_ECX + 0x2b8) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 700) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c3b48,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f5d60 @ 0x005f5d60 ====

undefined4 FUN_005f5d60(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3b48,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 700);
    *(int *)(in_ECX + 0x2b4) = *(int *)(in_ECX + 0x2b4) + -1;
    *(int *)(in_ECX + 700) = param_2;
  }
  return 0;
}


// ==== FUN_005f5de0 @ 0x005f5de0 ====

void FUN_005f5de0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f5160();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f5e00 @ 0x005f5e00 ====

void FUN_005f5e00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7158;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x22,FUN_006ef6d0);
  return;
}


// ==== FUN_005f5e20 @ 0x005f5e20 ====

void FUN_005f5e20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985863;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7160;
  local_4 = 1;
  if ((void *)in_ECX[0x114] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c7158;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x22,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c7114;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x114]);
  return;
}


// ==== FUN_005f5ea0 @ 0x005f5ea0 ====

undefined4 FUN_005f5ea0(void)

{
  return 0x22;
}


// ==== FUN_005f5eb0 @ 0x005f5eb0 ====

undefined4 FUN_005f5eb0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x44c);
}


// ==== FUN_005f5ec0 @ 0x005f5ec0 ====

undefined4 FUN_005f5ec0(uint param_1,int param_2)

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
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x454);
    *(int *)(in_ECX + 0x44c) = *(int *)(in_ECX + 0x44c) + -1;
    *(int *)(in_ECX + 0x454) = param_2;
  }
  return 0;
}


// ==== FUN_005f5f40 @ 0x005f5f40 ====

undefined4 * FUN_005f5f40(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3b48,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x454);
  *(int *)(in_ECX + 0x44c) = *(int *)(in_ECX + 0x44c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x450);
    *(undefined4 **)(in_ECX + 0x450) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x454) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005f6000 @ 0x005f6000 ====

void FUN_005f6000(byte param_1)

{
  void *in_ECX;
  
  FUN_005f5e00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f6020 @ 0x005f6020 ====

void FUN_005f6020(byte param_1)

{
  void *in_ECX;
  
  FUN_005f5e20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f6040 @ 0x005f6040 ====

void FUN_005f6040(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985878;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7160;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c7158;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x22,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x112] = 0;
  in_ECX[0x112] = in_ECX[0x112] + 0x22;
  in_ECX[0x115] = in_ECX + 2;
  in_ECX[0x113] = 0;
  in_ECX[0x114] = 0;
  iVar2 = 0x21;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x10f] = 0;
  in_ECX[0x110] = 0;
  in_ECX[0x111] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f60f0 @ 0x005f60f0 ====

void FUN_005f60f0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985898;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c717c;
  FUN_005f6040();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f6150 @ 0x005f6150 ====

void FUN_005f6150(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f6170(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f6170 @ 0x005f6170 ====

void FUN_005f6170(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005f6170(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005f6170(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005f61b0 @ 0x005f61b0 ====

void FUN_005f61b0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0xc);
    *(int *)(param_1 + 8) = iVar2;
    if (iVar2 != 0) {
      *(int *)(iVar2 + 0x10) = param_1;
    }
    iVar2 = *(int *)(param_1 + 0x10);
    *(int *)(iVar1 + 0x10) = iVar2;
    if (iVar2 == 0) {
      *(int *)(in_ECX + 4) = iVar1;
      *(int *)(iVar1 + 0xc) = param_1;
      *(int *)(param_1 + 0x10) = iVar1;
      return;
    }
    if (param_1 == *(int *)(iVar2 + 8)) {
      *(int *)(iVar2 + 8) = iVar1;
      *(int *)(iVar1 + 0xc) = param_1;
      *(int *)(param_1 + 0x10) = iVar1;
      return;
    }
    *(int *)(iVar2 + 0xc) = iVar1;
    *(int *)(iVar1 + 0xc) = param_1;
    *(int *)(param_1 + 0x10) = iVar1;
  }
  return;
}


// ==== FUN_005f6200 @ 0x005f6200 ====

void FUN_005f6200(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f6220(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f6220 @ 0x005f6220 ====

void FUN_005f6220(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005f6220(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005f6220(param_1[3]);
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


// ==== FUN_005f6290 @ 0x005f6290 ====

undefined4 * FUN_005f6290(int *param_1)

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
    if (*param_1 < *(int *)*puVar3) {
      iVar2 = -1;
    }
    else {
      if (*param_1 <= *(int *)*puVar3) {
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


// ==== FUN_005f6300 @ 0x005f6300 ====

void FUN_005f6300(byte param_1)

{
  void *in_ECX;
  
  FUN_005f6320();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f6320 @ 0x005f6320 ====

void FUN_005f6320(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009858c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c717c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005f6220(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005f5e20();
  *in_ECX = &PTR_FUN_009c70bc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f6390 @ 0x005f6390 ====

void FUN_005f6390(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005f6395. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 4))();
  return;
}


// ==== FUN_005f63a0 @ 0x005f63a0 ====

void FUN_005f63a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005f63a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 8))();
  return;
}


// ==== FUN_005f63b0 @ 0x005f63b0 ====

void FUN_005f63b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005f63b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_005f63c0 @ 0x005f63c0 ====

void FUN_005f63c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005f63c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_005f63d0 @ 0x005f63d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f63d0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985903;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c73a8;
  if (puVar1 == (undefined4 *)0x0) {
    _DAT_00b5a774 = (undefined4 *)0x0;
  }
  else {
    _DAT_00b5a774 = in_ECX;
  }
  pvVar2 = operator_new(0x30);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar2 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar3 = FUN_005f6570();
  *puVar1 = uVar3;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f6470 @ 0x005f6470 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005f6470(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985915;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c73a8;
  _DAT_00b5a774 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c7358;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f64d0 @ 0x005f64d0 ====

void FUN_005f64d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7370;
  return;
}


// ==== FUN_005f64e0 @ 0x005f64e0 ====

void FUN_005f64e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7370;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f6510 @ 0x005f6510 ====

void FUN_005f6510(void)

{
  FUN_00611960();
  return;
}


// ==== FUN_005f6520 @ 0x005f6520 ====

void FUN_005f6520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7358;
  return;
}


// ==== FUN_005f6530 @ 0x005f6530 ====

void FUN_005f6530(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7358;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f6550 @ 0x005f6550 ====

void FUN_005f6550(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7388;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x18,1,(_func_void_void_ptr *)&LAB_005f6500);
  return;
}


// ==== FUN_005f6570 @ 0x005f6570 ====

void FUN_005f6570(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009858d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7390;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c7388;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x18,1,FUN_005f6510,(_func_void_void_ptr *)&LAB_005f6500);
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


// ==== FUN_005f65f0 @ 0x005f65f0 ====

undefined4 FUN_005f65f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x24);
}


// ==== FUN_005f6600 @ 0x005f6600 ====

void FUN_005f6600(byte param_1)

{
  void *in_ECX;
  
  FUN_005f6550();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f6620 @ 0x005f6620 ====

void * FUN_005f6620(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00985939;
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
        FUN_00611960();
      }
      *(undefined4 *)((int)param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x28);
      *(void **)(in_ECX + 0x28) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)((int)param_2 + 0xc);
    }
    local_4 = 0xffffffff;
    *(int *)((int)param_2 + 0x14) = param_1;
    *(undefined4 *)((int)param_2 + 0xc) = 0;
    FUN_00611910();
  }
  else {
    if (*(int *)((int)param_2 + 0x14) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c73c0,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x14) = *(int *)((int)param_2 + 0x14) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f6730 @ 0x005f6730 ====

undefined4 FUN_005f6730(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x14) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c73c0,0xa6);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x14);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x14);
    }
    FUN_00611920();
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x2c);
    *(int *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x24) + -1;
    *(int *)(in_ECX + 0x2c) = param_2;
  }
  return 0;
}


// ==== FUN_005f67b0 @ 0x005f67b0 ====

void FUN_005f67b0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f67d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f67d0 @ 0x005f67d0 ====

void FUN_005f67d0(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00985969;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7390;
  local_4 = 1;
  if (in_ECX[9] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009c7240,
                         s_d__usa_24_0_1_2__develop_share_l_009c71d8,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  if (in_ECX[7] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009c72c0,
                         s_d__usa_24_0_1_2__develop_share_l_009c7258,0x5b);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _Memory = (void *)in_ECX[10];
  if (_Memory == (void *)0x0) {
    local_4 = local_4 & 0xffffff00;
    in_ECX[1] = &PTR_FUN_009c7388;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x18,1,(_func_void_void_ptr *)&LAB_005f6500);
    *in_ECX = &PTR_FUN_009c7370;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0x14) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009c7340,
                         s_d__usa_24_0_1_2__develop_share_l_009c72d8,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  FUN_00611900();
  _free(_Memory);
  return;
}


// ==== FUN_005f6900 @ 0x005f6900 ====

void FUN_005f6900(byte param_1)

{
  void *in_ECX;
  
  FUN_005f6470();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f6920 @ 0x005f6920 ====

void FUN_005f6920(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c742c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f6940 @ 0x005f6940 ====

void FUN_005f6940(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7438;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a73c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a73c = in_ECX;
  return;
}


// ==== FUN_005f6970 @ 0x005f6970 ====

undefined4 FUN_005f6970(undefined1 param_1,char param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00985b7a;
  local_c = ExceptionList;
  switch(param_1) {
  case 0:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x18);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0061b140();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 1:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 1;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0061b050();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 2:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x24);
    local_4 = 7;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00619b30();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 3:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 0x1d;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00613720();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 4:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 0x1e;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006131e0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 5:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x3c);
    local_4 = 2;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0061acb0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 6:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 0x14;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00615b90();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 7:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x20);
    local_4 = 0x12;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006173a0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 8:
    if (param_2 == '\0') {
      ExceptionList = &local_c;
      pvVar1 = operator_new(100);
      local_4 = 0x13;
      if (pvVar1 != (void *)0x0) {
        uVar2 = FUN_00616640();
        ExceptionList = local_c;
        return uVar2;
      }
    }
    break;
  case 9:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 0x15;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00615990();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 10:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);
    local_4 = 0x16;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006156f0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xb:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x28);
    local_4 = 0x17;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00614ad0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xc:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x2c);
    local_4 = 0x18;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00614770();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xd:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0x19;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00614470();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xe:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x18);
    local_4 = 6;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00619c60();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0xf:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 0x10;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00617790();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x10:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x60);
    local_4 = 3;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0061ab40();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x11:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x20);
    local_4 = 4;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0061a770();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x12:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x44);
    local_4 = 0x11;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00617620();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x13:
    if (param_2 == '\0') {
      ExceptionList = &local_c;
      pvVar1 = operator_new(0x640);
      local_4 = 8;
      if (pvVar1 != (void *)0x0) {
        uVar2 = FUN_00619190();
        ExceptionList = local_c;
        return uVar2;
      }
    }
    else if (param_2 == '\x01') {
      ExceptionList = &local_c;
      pvVar1 = operator_new(0x640);
      local_4 = 9;
      if (pvVar1 != (void *)0x0) {
        uVar2 = FUN_00618be0();
        ExceptionList = local_c;
        return uVar2;
      }
    }
    else if (param_2 == '\r') {
      ExceptionList = &local_c;
      pvVar1 = operator_new(0x3c0);
      local_4 = 10;
      if (pvVar1 != (void *)0x0) {
        uVar2 = FUN_00618900();
        ExceptionList = local_c;
        return uVar2;
      }
    }
    else if (param_2 == '\x02') {
      ExceptionList = &local_c;
      pvVar1 = operator_new(0x640);
      local_4 = 0xb;
      if (pvVar1 != (void *)0x0) {
        uVar2 = FUN_006187a0();
        ExceptionList = local_c;
        return uVar2;
      }
    }
    else if (param_2 == '\x03') {
      ExceptionList = &local_c;
      pvVar1 = operator_new(0x640);
      local_4 = 0xc;
      if (pvVar1 != (void *)0x0) {
        uVar2 = FUN_00618200();
        ExceptionList = local_c;
        return uVar2;
      }
    }
    else if (param_2 == '\x05') {
      ExceptionList = &local_c;
      pvVar1 = operator_new(0x640);
      local_4 = 0xd;
      if (pvVar1 != (void *)0x0) {
        uVar2 = FUN_00617d70();
        ExceptionList = local_c;
        return uVar2;
      }
    }
    else if (param_2 == '\v') {
      ExceptionList = &local_c;
      pvVar1 = operator_new(0x3c0);
      local_4 = 0xe;
      if (pvVar1 != (void *)0x0) {
        uVar2 = FUN_00617c10();
        ExceptionList = local_c;
        return uVar2;
      }
    }
    else if (param_2 == '\x06') {
      ExceptionList = &local_c;
      pvVar1 = operator_new(0x640);
      local_4 = 0xf;
      if (pvVar1 != (void *)0x0) {
        uVar2 = FUN_00617ab0();
        ExceptionList = local_c;
        return uVar2;
      }
    }
    break;
  case 0x14:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 0x1a;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006142d0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x15:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0x1b;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00614230();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x17:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);
    local_4 = 0x1c;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00614140();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x1a:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0x21;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00612d60();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x1b:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0x22;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00612c40();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x1c:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x18);
    local_4 = 5;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0061a0f0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x1d:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x1c);
    local_4 = 0x1f;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00613030();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x1e:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x1c);
    local_4 = 0x20;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00612e70();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x1f:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x18);
    local_4 = 0x23;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00612b40();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x20:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x3c);
    local_4 = 0x24;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006129d0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x21:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x5c);
    local_4 = 0x25;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00612740();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x22:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x18);
    local_4 = 0x26;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00612660();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x23:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 0x27;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00612560();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x24:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 0x28;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00612470();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x25:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x30);
    local_4 = 0x29;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_006122d0();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x26:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x20);
    local_4 = 0x2a;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00611e60();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x27:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x24);
    local_4 = 0x2b;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00611c90();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x28:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 0x2c;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00611b40();
      ExceptionList = local_c;
      return uVar2;
    }
    break;
  case 0x29:
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x14);
    local_4 = 0x2d;
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_00611a40();
      ExceptionList = local_c;
      return uVar2;
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_005f7420 @ 0x005f7420 ====

void FUN_005f7420(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a73c = 0;
  *in_ECX = &PTR_FUN_009c742c;
  return;
}


// ==== FUN_005f7440 @ 0x005f7440 ====

void FUN_005f7440(byte param_1)

{
  void *in_ECX;
  
  FUN_005f7420();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f7460 @ 0x005f7460 ====

void FUN_005f7460(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00985ba6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(8);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0061b780();
  }
  local_4 = 0xffffffff;
  *in_ECX = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0061b370();
  in_ECX[1] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f7500 @ 0x005f7500 ====

void FUN_005f7500(void)

{
  int *in_ECX;
  
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


// ==== FUN_005f7530 @ 0x005f7530 ====

void FUN_005f7530(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985bc3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7444;
  pvVar1 = operator_new(8);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_005f7460();
  in_ECX[1] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f75b0 @ 0x005f75b0 ====

void FUN_005f75b0(void)

{
  int *_Memory;
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_00985bd5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7444;
  _Memory = (int *)in_ECX[1];
  local_4 = 0;
  if (_Memory == (int *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_009c3574;
    ExceptionList = pvVar1;
    return;
  }
  if ((undefined4 *)_Memory[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)_Memory[1])(1);
  }
  _Memory[1] = 0;
  if ((undefined4 *)*_Memory != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*_Memory)(1);
  }
  *_Memory = 0;
  _free(_Memory);
  return;
}


// ==== FUN_005f7630 @ 0x005f7630 ====

void FUN_005f7630(byte param_1)

{
  void *in_ECX;
  
  FUN_005f75b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f7650 @ 0x005f7650 ====

void FUN_005f7650(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00985cd2;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x104);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00627ec0();
  }
  local_4 = 0xffffffff;
  *in_ECX = uVar2;
  pvVar1 = operator_new(0x10e08);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006273f0();
  }
  local_4 = 0xffffffff;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x14);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006270e0();
  }
  local_4 = 0xffffffff;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00626be0();
  }
  local_4 = 0xffffffff;
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(0x20);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00626990();
  }
  local_4 = 0xffffffff;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0x28);
  local_4 = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006267a0();
  }
  local_4 = 0xffffffff;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00625d50();
  }
  local_4 = 0xffffffff;
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006251c0();
  }
  local_4 = 0xffffffff;
  in_ECX[7] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 8;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00624530();
  }
  local_4 = 0xffffffff;
  in_ECX[8] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 9;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00623aa0();
  }
  local_4 = 0xffffffff;
  in_ECX[9] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00622ef0();
  }
  local_4 = 0xffffffff;
  in_ECX[10] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0xb;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00622470();
  }
  local_4 = 0xffffffff;
  in_ECX[0xb] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0xc;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00622030();
  }
  local_4 = 0xffffffff;
  in_ECX[0xc] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0xd;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00621790();
  }
  local_4 = 0xffffffff;
  in_ECX[0xd] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0xe;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00620d90();
  }
  local_4 = 0xffffffff;
  in_ECX[0xe] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0xf;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00620100();
  }
  local_4 = 0xffffffff;
  in_ECX[0xf] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0x10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0061f510();
  }
  local_4 = 0xffffffff;
  in_ECX[0x10] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0x11;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0061e8f0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x11] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0x12;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0061db60();
  }
  local_4 = 0xffffffff;
  in_ECX[0x12] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0x13;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0061d080();
  }
  local_4 = 0xffffffff;
  in_ECX[0x13] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0x14;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0061c5b0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x14] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0x15;
  if (pvVar1 == (void *)0x0) {
    in_ECX[0x15] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0061baf0();
  in_ECX[0x15] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f7a60 @ 0x005f7a60 ====

void FUN_005f7a60(void)

{
  int *in_ECX;
  
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
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
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


// ==== FUN_005f7bd0 @ 0x005f7bd0 ====

void FUN_005f7bd0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985cef;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7454;
  pvVar1 = operator_new(0x58);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_005f7650();
  in_ECX[1] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f7c50 @ 0x005f7c50 ====

void FUN_005f7c50(void)

{
  void *_Memory;
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_00985d01;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7454;
  _Memory = (void *)in_ECX[1];
  local_4 = 0;
  if (_Memory == (void *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_009c3574;
    ExceptionList = pvVar1;
    return;
  }
  FUN_005f7a60();
  _free(_Memory);
  return;
}


// ==== FUN_005f7cc0 @ 0x005f7cc0 ====

void FUN_005f7cc0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f7c50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f7ce0 @ 0x005f7ce0 ====

void FUN_005f7ce0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c745c;
  return;
}


// ==== FUN_005f7cf0 @ 0x005f7cf0 ====

void FUN_005f7cf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c74b4;
  return;
}


// ==== FUN_005f7d00 @ 0x005f7d00 ====

void FUN_005f7d00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c74cc;
  return;
}


// ==== FUN_005f7d10 @ 0x005f7d10 ====

void FUN_005f7d10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c745c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f7d30 @ 0x005f7d30 ====

void FUN_005f7d30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c74b4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f7d50 @ 0x005f7d50 ====

void FUN_005f7d50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c74cc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f7d70 @ 0x005f7d70 ====

undefined4 FUN_005f7d70(undefined2 param_1)

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


// ==== FUN_005f7da0 @ 0x005f7da0 ====

undefined4 FUN_005f7da0(void)

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


// ==== FUN_005f7dc0 @ 0x005f7dc0 ====

undefined4 FUN_005f7dc0(void)

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


// ==== FUN_005f7df0 @ 0x005f7df0 ====

void FUN_005f7df0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c74ec;
  DAT_00b5aae8 = 0;
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
  return;
}


// ==== FUN_005f7e60 @ 0x005f7e60 ====

void FUN_005f7e60(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int in_ECX;
  int *unaff_EBX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  puVar2 = (undefined2 *)(**(code **)(*unaff_EBX + 0x10))();
  *puVar1 = *puVar2;
  *(int **)(puVar1 + 2) = unaff_EBX;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar1);
  return;
}


// ==== FUN_005f7ea0 @ 0x005f7ea0 ====

void FUN_005f7ea0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00985e06;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c74ec;
  pvVar2 = operator_new(0x68);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f7fb0();
  }
  puVar1 = in_ECX + 1;
  local_4 = 0xffffffff;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0xa8);
  local_4 = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f8530(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aae8 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aae8 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f7f70 @ 0x005f7f70 ====

void FUN_005f7f70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c74e4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,4,FUN_006ef6d0);
  return;
}


// ==== FUN_005f7f90 @ 0x005f7f90 ====

void FUN_005f7f90(byte param_1)

{
  void *in_ECX;
  
  FUN_005f7f70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f7fb0 @ 0x005f7fb0 ====

void FUN_005f7fb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985d18;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7504;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c74e4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,4,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x16] = 0;
  in_ECX[0x16] = in_ECX[0x16] + 4;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = in_ECX + 2;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[4] = in_ECX + 7;
  in_ECX[9] = in_ECX + 0xc;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xe] = in_ECX + 0x11;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f8050 @ 0x005f8050 ====

void FUN_005f8050(byte param_1)

{
  void *in_ECX;
  
  FUN_005f8070();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f8070 @ 0x005f8070 ====

void FUN_005f8070(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985d43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7504;
  local_4 = 1;
  if ((void *)in_ECX[0x18] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c74e4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,4,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c74b4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x18]);
  return;
}


// ==== FUN_005f80f0 @ 0x005f80f0 ====

void * FUN_005f80f0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00985d5b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 100);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x5c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x60);
      *(void **)(in_ECX + 0x60) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 100) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c36e8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f81c0 @ 0x005f81c0 ====

undefined4 FUN_005f81c0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c36e8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 100);
    *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x5c) + -1;
    *(int *)(in_ECX + 100) = param_2;
  }
  return 0;
}


// ==== FUN_005f8240 @ 0x005f8240 ====

void FUN_005f8240(byte param_1)

{
  void *in_ECX;
  
  FUN_005f7df0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f8260 @ 0x005f8260 ====

void FUN_005f8260(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c751c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,4,FUN_006ef6d0);
  return;
}


// ==== FUN_005f8280 @ 0x005f8280 ====

void FUN_005f8280(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985d83;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7524;
  local_4 = 1;
  if ((void *)in_ECX[0x24] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c751c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,4,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c74cc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x24]);
  return;
}


// ==== FUN_005f8300 @ 0x005f8300 ====

undefined4 FUN_005f8300(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c36e8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x94);
    *(int *)(in_ECX + 0x8c) = *(int *)(in_ECX + 0x8c) + -1;
    *(int *)(in_ECX + 0x94) = param_2;
  }
  return 0;
}


// ==== FUN_005f8380 @ 0x005f8380 ====

undefined4 * FUN_005f8380(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c36e8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x94);
  *(int *)(in_ECX + 0x8c) = *(int *)(in_ECX + 0x8c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x90);
    *(undefined4 **)(in_ECX + 0x90) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x94) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005f8440 @ 0x005f8440 ====

void FUN_005f8440(byte param_1)

{
  void *in_ECX;
  
  FUN_005f8260();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f8460 @ 0x005f8460 ====

void FUN_005f8460(byte param_1)

{
  void *in_ECX;
  
  FUN_005f8280();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f8480 @ 0x005f8480 ====

void FUN_005f8480(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985d98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7524;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c751c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,4,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x22] = 0;
  in_ECX[0x22] = in_ECX[0x22] + 4;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = in_ECX + 2;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[7] = in_ECX + 10;
  in_ECX[0xf] = in_ECX + 0x12;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x17] = in_ECX + 0x1a;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f8530 @ 0x005f8530 ====

void FUN_005f8530(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985db8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c753c;
  FUN_005f8480();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f8590 @ 0x005f8590 ====

void FUN_005f8590(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f85b0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f85b0 @ 0x005f85b0 ====

void FUN_005f85b0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005f85b0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005f85b0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005f85f0 @ 0x005f85f0 ====

void FUN_005f85f0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f8610(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f8610 @ 0x005f8610 ====

void FUN_005f8610(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005f8610(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005f8610(param_1[3]);
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


// ==== FUN_005f8680 @ 0x005f8680 ====

void FUN_005f8680(byte param_1)

{
  void *in_ECX;
  
  FUN_005f86a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f86a0 @ 0x005f86a0 ====

void FUN_005f86a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00985de3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c753c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005f8610(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005f8280();
  *in_ECX = &PTR_FUN_009c745c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f8710 @ 0x005f8710 ====

void FUN_005f8710(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7594;
  return;
}


// ==== FUN_005f8720 @ 0x005f8720 ====

void FUN_005f8720(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c75ec;
  return;
}


// ==== FUN_005f8730 @ 0x005f8730 ====

void FUN_005f8730(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7604;
  return;
}


// ==== FUN_005f8740 @ 0x005f8740 ====

void FUN_005f8740(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7594;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f8760 @ 0x005f8760 ====

void FUN_005f8760(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c75ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f8780 @ 0x005f8780 ====

void FUN_005f8780(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7604;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f87a0 @ 0x005f87a0 ====

undefined4 FUN_005f87a0(undefined2 param_1)

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


// ==== FUN_005f87d0 @ 0x005f87d0 ====

undefined4 FUN_005f87d0(void)

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


// ==== __break @ 0x005f87ee ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_005f87f0 @ 0x005f87f0 ====

undefined4 FUN_005f87f0(void)

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


// ==== FUN_005f8820 @ 0x005f8820 ====

void FUN_005f8820(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7624;
  DAT_00b5aaf0 = 0;
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
  return;
}


// ==== FUN_005f8890 @ 0x005f8890 ====

void FUN_005f8890(undefined2 *param_1)

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
  puStack_8 = &LAB_00985e1b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0xc);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_006290f0();
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


// ==== FUN_005f8920 @ 0x005f8920 ====

void FUN_005f8920(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00985e3b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7624;
  pvVar2 = operator_new(0xa18);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f8a30();
  }
  puVar1 = in_ECX + 1;
  local_4 = 0xffffffff;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x1028);
  local_4 = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f8fe0(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aaf0 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aaf0 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f89f0 @ 0x005f89f0 ====

void FUN_005f89f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c761c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005f8a10 @ 0x005f8a10 ====

void FUN_005f8a10(byte param_1)

{
  void *in_ECX;
  
  FUN_005f89f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f8a30 @ 0x005f8a30 ====

void FUN_005f8a30(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985e58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c763c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c761c;
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


// ==== FUN_005f8ae0 @ 0x005f8ae0 ====

void FUN_005f8ae0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f8b00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f8b00 @ 0x005f8b00 ====

void FUN_005f8b00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985e83;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c763c;
  local_4 = 1;
  if ((void *)in_ECX[0x284] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c761c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c75ec;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x284]);
  return;
}


// ==== FUN_005f8b80 @ 0x005f8b80 ====

void * FUN_005f8b80(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00985e9b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009c7650,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f8c60 @ 0x005f8c60 ====

undefined4 FUN_005f8c60(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7650,0xa9);
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


// ==== FUN_005f8ce0 @ 0x005f8ce0 ====

void FUN_005f8ce0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f8820();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f8d00 @ 0x005f8d00 ====

void FUN_005f8d00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c76d8;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x80,FUN_006ef6d0);
  return;
}


// ==== FUN_005f8d20 @ 0x005f8d20 ====

void FUN_005f8d20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985ec3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c76e0;
  local_4 = 1;
  if ((void *)in_ECX[0x404] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c76d8;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x80,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c7604;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x404]);
  return;
}


// ==== FUN_005f8da0 @ 0x005f8da0 ====

undefined4 FUN_005f8da0(void)

{
  return 0x80;
}


// ==== FUN_005f8db0 @ 0x005f8db0 ====

undefined4 FUN_005f8db0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7650,0xa9);
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


// ==== FUN_005f8e30 @ 0x005f8e30 ====

undefined4 * FUN_005f8e30(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7650,0x85);
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


// ==== FUN_005f8ef0 @ 0x005f8ef0 ====

void FUN_005f8ef0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f8d00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f8f10 @ 0x005f8f10 ====

void FUN_005f8f10(byte param_1)

{
  void *in_ECX;
  
  FUN_005f8d20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f8f30 @ 0x005f8f30 ====

void FUN_005f8f30(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985ed8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c76e0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c76d8;
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


// ==== FUN_005f8fe0 @ 0x005f8fe0 ====

void FUN_005f8fe0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985ef8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c76fc;
  FUN_005f8f30();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f9040 @ 0x005f9040 ====

void FUN_005f9040(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f9060(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f9060 @ 0x005f9060 ====

void FUN_005f9060(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005f9060(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005f9060(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005f90a0 @ 0x005f90a0 ====

void FUN_005f90a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f90c0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f90c0 @ 0x005f90c0 ====

void FUN_005f90c0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005f90c0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005f90c0(param_1[3]);
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


// ==== FUN_005f9130 @ 0x005f9130 ====

void FUN_005f9130(byte param_1)

{
  void *in_ECX;
  
  FUN_005f9150();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9150 @ 0x005f9150 ====

void FUN_005f9150(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00985f23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c76fc;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005f90c0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005f8d20();
  *in_ECX = &PTR_FUN_009c7594;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f91c0 @ 0x005f91c0 ====

void FUN_005f91c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7754;
  return;
}


// ==== FUN_005f91d0 @ 0x005f91d0 ====

void FUN_005f91d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c77ac;
  return;
}


// ==== FUN_005f91e0 @ 0x005f91e0 ====

void FUN_005f91e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c77c4;
  return;
}


// ==== FUN_005f91f0 @ 0x005f91f0 ====

void FUN_005f91f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7754;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9210 @ 0x005f9210 ====

void FUN_005f9210(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c77ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9230 @ 0x005f9230 ====

void FUN_005f9230(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c77c4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9250 @ 0x005f9250 ====

undefined4 FUN_005f9250(undefined2 param_1)

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


// ==== FUN_005f9280 @ 0x005f9280 ====

undefined4 FUN_005f9280(void)

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


// ==== FUN_005f92a0 @ 0x005f92a0 ====

undefined4 FUN_005f92a0(void)

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


// ==== FUN_005f92d0 @ 0x005f92d0 ====

void FUN_005f92d0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c77e4;
  DAT_00b5aaf4 = 0;
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
  return;
}


// ==== FUN_005f9340 @ 0x005f9340 ====

void FUN_005f9340(void)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  int in_ECX;
  int *unaff_EBX;
  
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  puVar2 = (undefined2 *)(**(code **)(*unaff_EBX + 8))();
  *puVar1 = *puVar2;
  *(int **)(puVar1 + 2) = unaff_EBX;
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar1);
  return;
}


// ==== FUN_005f9380 @ 0x005f9380 ====

void FUN_005f9380(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00986026;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c77e4;
  pvVar2 = operator_new(0x68);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f9490();
  }
  puVar1 = in_ECX + 1;
  local_4 = 0xffffffff;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0xa8);
  local_4 = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005f9a20(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aaf4 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aaf4 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f9450 @ 0x005f9450 ====

void FUN_005f9450(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c77dc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,4,FUN_006ef6d0);
  return;
}


// ==== FUN_005f9470 @ 0x005f9470 ====

void FUN_005f9470(byte param_1)

{
  void *in_ECX;
  
  FUN_005f9450();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9490 @ 0x005f9490 ====

void FUN_005f9490(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985f38;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c77fc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c77dc;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,4,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x16] = 0;
  in_ECX[0x16] = in_ECX[0x16] + 4;
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = in_ECX + 2;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[4] = in_ECX + 7;
  in_ECX[9] = in_ECX + 0xc;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xe] = in_ECX + 0x11;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f9530 @ 0x005f9530 ====

undefined4 FUN_005f9530(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x5c);
}


// ==== FUN_005f9540 @ 0x005f9540 ====

void FUN_005f9540(byte param_1)

{
  void *in_ECX;
  
  FUN_005f9560();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9560 @ 0x005f9560 ====

void FUN_005f9560(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985f63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c77fc;
  local_4 = 1;
  if ((void *)in_ECX[0x18] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c77dc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,4,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c77ac;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x18]);
  return;
}


// ==== FUN_005f95e0 @ 0x005f95e0 ====

void * FUN_005f95e0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00985f7b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 100);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x5c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      *(undefined4 *)((int)param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x60);
      *(void **)(in_ECX + 0x60) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 100) = *(undefined4 *)((int)param_2 + 8);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c7810,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005f96b0 @ 0x005f96b0 ====

undefined4 FUN_005f96b0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7810,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 100);
    *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x5c) + -1;
    *(int *)(in_ECX + 100) = param_2;
  }
  return 0;
}


// ==== FUN_005f9730 @ 0x005f9730 ====

void FUN_005f9730(byte param_1)

{
  void *in_ECX;
  
  FUN_005f92d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9750 @ 0x005f9750 ====

void FUN_005f9750(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c788c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,4,FUN_006ef6d0);
  return;
}


// ==== FUN_005f9770 @ 0x005f9770 ====

void FUN_005f9770(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985fa3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7894;
  local_4 = 1;
  if ((void *)in_ECX[0x24] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c788c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,4,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c77c4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x24]);
  return;
}


// ==== FUN_005f97f0 @ 0x005f97f0 ====

undefined4 FUN_005f97f0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7810,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x94);
    *(int *)(in_ECX + 0x8c) = *(int *)(in_ECX + 0x8c) + -1;
    *(int *)(in_ECX + 0x94) = param_2;
  }
  return 0;
}


// ==== FUN_005f9870 @ 0x005f9870 ====

undefined4 * FUN_005f9870(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7810,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x94);
  *(int *)(in_ECX + 0x8c) = *(int *)(in_ECX + 0x8c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x90);
    *(undefined4 **)(in_ECX + 0x90) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x94) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005f9930 @ 0x005f9930 ====

void FUN_005f9930(byte param_1)

{
  void *in_ECX;
  
  FUN_005f9750();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9950 @ 0x005f9950 ====

void FUN_005f9950(byte param_1)

{
  void *in_ECX;
  
  FUN_005f9770();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9970 @ 0x005f9970 ====

void FUN_005f9970(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985fb8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7894;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c788c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,4,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x22] = 0;
  in_ECX[0x22] = in_ECX[0x22] + 4;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = in_ECX + 2;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[7] = in_ECX + 10;
  in_ECX[0xf] = in_ECX + 0x12;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x17] = in_ECX + 0x1a;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f9a20 @ 0x005f9a20 ====

void FUN_005f9a20(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00985fd8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c78ac;
  FUN_005f9970();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f9a80 @ 0x005f9a80 ====

void FUN_005f9a80(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f9aa0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f9aa0 @ 0x005f9aa0 ====

void FUN_005f9aa0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005f9aa0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005f9aa0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005f9ae0 @ 0x005f9ae0 ====

void FUN_005f9ae0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005f9b00(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005f9b00 @ 0x005f9b00 ====

void FUN_005f9b00(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005f9b00(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005f9b00(param_1[3]);
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


// ==== FUN_005f9b70 @ 0x005f9b70 ====

void FUN_005f9b70(byte param_1)

{
  void *in_ECX;
  
  FUN_005f9b90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9b90 @ 0x005f9b90 ====

void FUN_005f9b90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00986003;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c78ac;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005f9b00(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005f9770();
  *in_ECX = &PTR_FUN_009c7754;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f9c00 @ 0x005f9c00 ====

void FUN_005f9c00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c790c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9c20 @ 0x005f9c20 ====

int FUN_005f9c20(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_005f9c30 @ 0x005f9c30 ====

void FUN_005f9c30(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  for (iVar1 = 0x10; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_ECX = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_005f9c50 @ 0x005f9c50 ====

void FUN_005f9c50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c791c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aae4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aae4 = in_ECX;
  return;
}


// ==== FUN_005f9c80 @ 0x005f9c80 ====

void FUN_005f9c80(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aae4 = 0;
  *in_ECX = &PTR_FUN_009c790c;
  return;
}


// ==== FUN_005f9ca0 @ 0x005f9ca0 ====

void FUN_005f9ca0(byte param_1)

{
  void *in_ECX;
  
  FUN_005f9c80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9cc0 @ 0x005f9cc0 ====

void FUN_005f9cc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c792c;
  return;
}


// ==== FUN_005f9cd0 @ 0x005f9cd0 ====

void FUN_005f9cd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c792c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9cf0 @ 0x005f9cf0 ====

int FUN_005f9cf0(byte param_1)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 4) + (uint)param_1 * 0x2e;
}


// ==== FUN_005f9d10 @ 0x005f9d10 ====

void FUN_005f9d10(void)

{
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986043;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c793c;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  local_4 = 0;
  in_ECX[0xe] = 0;
  pvVar1 = operator_new(0xb8);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    _eh_vector_constructor_iterator_(pvVar1,0x2e,4,FUN_00475220,FUN_006ef6d0);
  }
  in_ECX[1] = pvVar1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aae0 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aae0 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f9dc0 @ 0x005f9dc0 ====

void FUN_005f9dc0(void)

{
  void *_Memory;
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_00986055;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c793c;
  DAT_00b5aae0 = 0;
  _Memory = (void *)in_ECX[1];
  local_4 = 0;
  if (_Memory == (void *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_009c792c;
    ExceptionList = pvVar1;
    return;
  }
  _eh_vector_destructor_iterator_(_Memory,0x2e,4,FUN_006ef6d0);
  _free(_Memory);
  return;
}


// ==== FUN_005f9e30 @ 0x005f9e30 ====

void FUN_005f9e30(undefined1 *param_1)

{
  undefined1 *puVar1;
  char cVar2;
  uint uVar3;
  int in_ECX;
  
  puVar1 = (undefined1 *)(*(int *)(in_ECX + 4) + *(int *)(in_ECX + 0x38) * 0x2e);
  *puVar1 = *param_1;
  uVar3 = 0;
  do {
    cVar2 = param_1[uVar3 + 1];
    puVar1[uVar3 + 1] = cVar2;
    if (cVar2 == '\0') goto LAB_005f9e68;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x2d);
  puVar1[1] = 0;
LAB_005f9e68:
  *(int *)(in_ECX + 0x38) = *(int *)(in_ECX + 0x38) + 1;
  return;
}


// ==== FUN_005f9e80 @ 0x005f9e80 ====

void FUN_005f9e80(byte param_1)

{
  void *in_ECX;
  
  FUN_005f9dc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9ea0 @ 0x005f9ea0 ====

void FUN_005f9ea0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c794c;
  return;
}


// ==== FUN_005f9eb0 @ 0x005f9eb0 ====

void FUN_005f9eb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c794c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005f9ed0 @ 0x005f9ed0 ====

void FUN_005f9ed0(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_005f9ee0 @ 0x005f9ee0 ====

undefined2 FUN_005f9ee0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0xc);
}


// ==== FUN_005f9ef0 @ 0x005f9ef0 ====

void FUN_005f9ef0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986068;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7974;
  puVar1 = operator_new(0x14);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009c796c;
    puVar1[4] = 0;
  }
  in_ECX[1] = puVar1;
  *(undefined2 *)(in_ECX + 3) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aaec = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aaec = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005f9f80 @ 0x005f9f80 ====

void FUN_005f9f80(undefined2 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(*(int *)(in_ECX + 4) + 0x10);
  *piVar1 = *piVar1 + 1;
  *(undefined2 *)(*(int *)(in_ECX + 4) + 2 + *(int *)(*(int *)(in_ECX + 4) + 0x10) * 2) = param_1;
  return;
}


// ==== FUN_005f9fa0 @ 0x005f9fa0 ====

undefined4 FUN_005f9fa0(int param_1)

{
  int in_ECX;
  
  return CONCAT22((short)((uint)*(int *)(in_ECX + 4) >> 0x10),
                  *(undefined2 *)(*(int *)(in_ECX + 4) + 4 + param_1 * 2));
}


// ==== FUN_005f9fb0 @ 0x005f9fb0 ====

undefined4 FUN_005f9fb0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 4) + 0x10);
}


// ==== FUN_005f9fc0 @ 0x005f9fc0 ====

uint FUN_005f9fc0(short param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  short *psVar3;
  
  uVar1 = *(uint *)(*(int *)(in_ECX + 4) + 0x10);
  uVar2 = 0;
  if (uVar1 != 0) {
    psVar3 = (short *)(*(int *)(in_ECX + 4) + 4);
    do {
      if (param_1 == *psVar3) {
        return CONCAT31((int3)(uVar2 >> 8),1);
      }
      uVar2 = uVar2 + 1;
      psVar3 = psVar3 + 1;
    } while (uVar2 < uVar1);
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_005f9ff0 @ 0x005f9ff0 ====

void FUN_005f9ff0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098607a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7974;
  DAT_00b5aaec = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c794c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fa050 @ 0x005fa050 ====

void FUN_005fa050(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c796c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fa070 @ 0x005fa070 ====

void FUN_005fa070(byte param_1)

{
  void *in_ECX;
  
  FUN_005f9ff0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fa090 @ 0x005fa090 ====

void FUN_005fa090(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c79a8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fa0b0 @ 0x005fa0b0 ====

int FUN_005fa0b0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_005fa0c0 @ 0x005fa0c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fa0c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c79b8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b020 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b020 = in_ECX;
  return;
}


// ==== FUN_005fa0f0 @ 0x005fa0f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005fa0f0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b020 = 0;
  *in_ECX = &PTR_FUN_009c79a8;
  return;
}


// ==== FUN_005fa110 @ 0x005fa110 ====

void FUN_005fa110(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  float10 fVar3;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009c79a0,s_SiegeTax_009c7994);
  uVar1 = 0;
  do {
    local_208[uVar1] = local_100[uVar1];
    if (local_100[uVar1] == '\0') goto LAB_005fa15e;
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x100);
  local_208[0] = '\0';
LAB_005fa15e:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar2 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  fVar3 = (float10)FUN_00477510(0,1);
  *(float *)(in_ECX + 4) = (float)fVar3;
  fVar3 = (float10)FUN_00477510(1,1);
  *(float *)(in_ECX + 8) = (float)fVar3;
  fVar3 = (float10)FUN_00477510(2,1);
  *(float *)(in_ECX + 0xc) = (float)fVar3;
  fVar3 = (float10)FUN_00477510(3,1);
  *(float *)(in_ECX + 0x10) = (float)fVar3;
  fVar3 = (float10)FUN_00477510(4,1);
  *(float *)(in_ECX + 0x14) = (float)fVar3;
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar2);
  return;
}


// ==== FUN_005fa200 @ 0x005fa200 ====

void FUN_005fa200(byte param_1)

{
  void *in_ECX;
  
  FUN_005fa0f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fa220 @ 0x005fa220 ====

void FUN_005fa220(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c79dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fa240 @ 0x005fa240 ====

int FUN_005fa240(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_005fa260 @ 0x005fa260 ====

void FUN_005fa260(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c79ec;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5adb4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5adb4 = in_ECX;
  return;
}


// ==== FUN_005fa290 @ 0x005fa290 ====

void FUN_005fa290(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5adb4 = 0;
  *in_ECX = &PTR_FUN_009c79dc;
  return;
}


// ==== FUN_005fa2b0 @ 0x005fa2b0 ====

void FUN_005fa2b0(undefined4 param_1)

{
  undefined2 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  char local_208 [256];
  undefined4 local_108;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  char local_100 [256];
  
  FUN_005fd550();
  FUN_0044a580(local_100,&DAT_009c79d4,s_SiegeConfig_009c79c8);
  uVar2 = 0;
  do {
    local_208[uVar2] = local_100[uVar2];
    if (local_100[uVar2] == '\0') goto LAB_005fa2fe;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  local_208[0] = '\0';
LAB_005fa2fe:
  local_108 = param_1;
  local_104 = 10;
  local_103 = 0x2c;
  local_102 = 1;
  uVar3 = (**(code **)(*DAT_00b5aa34 + 8))(local_208);
  uVar4 = FUN_004756e0(0,1);
  *(undefined4 *)(in_ECX + 4) = uVar4;
  uVar1 = FUN_00475a90(1,1);
  *(undefined2 *)(in_ECX + 8) = uVar1;
  uVar4 = FUN_004756e0(2,1);
  *(undefined4 *)(in_ECX + 0xc) = uVar4;
  uVar1 = FUN_00475a90(3,1);
  *(undefined2 *)(in_ECX + 0x10) = uVar1;
  uVar1 = FUN_00475a90(4,1);
  *(undefined2 *)(in_ECX + 0x12) = uVar1;
  uVar1 = FUN_00475a90(5,1);
  *(undefined2 *)(in_ECX + 0x14) = uVar1;
  uVar1 = FUN_00475a90(6,1);
  *(undefined2 *)(in_ECX + 0x16) = uVar1;
  uVar2 = FUN_00475a90(7,1);
  *(uint *)(in_ECX + 0x18) = uVar2 & 0xffff;
  uVar1 = FUN_00475a90(8,1);
  *(undefined2 *)(in_ECX + 0x1c) = uVar1;
  uVar4 = FUN_004756e0(9,1);
  *(undefined4 *)(in_ECX + 0x20) = uVar4;
  uVar1 = FUN_00475a90(10,1);
  *(undefined2 *)(in_ECX + 0x24) = uVar1;
  uVar1 = FUN_00475a90(0xb,1);
  *(undefined2 *)(in_ECX + 0x26) = uVar1;
  uVar4 = FUN_004756e0(0xc,1);
  *(undefined4 *)(in_ECX + 0x28) = uVar4;
  uVar4 = FUN_004756e0(0xd,1);
  *(undefined4 *)(in_ECX + 0x2c) = uVar4;
  uVar4 = FUN_004756e0(0xe,1);
  *(undefined4 *)(in_ECX + 0x30) = uVar4;
  uVar4 = FUN_004756e0(0xf,1);
  *(undefined4 *)(in_ECX + 0x34) = uVar4;
  uVar1 = FUN_00475a90(0x10,1);
  *(undefined2 *)(in_ECX + 0x38) = uVar1;
  *(undefined4 *)(in_ECX + 0x3c) = 1;
  uVar4 = FUN_004756e0(0x11,1);
  *(undefined4 *)(in_ECX + 0x40) = uVar4;
  iVar5 = FUN_004756e0(0x12,1);
  *(int *)(in_ECX + 0x44) = iVar5 * iVar5 * 0x8000;
  uVar2 = FUN_004756e0(0x13,1);
  if (uVar2 < 5) {
    uVar2 = 5;
  }
  *(uint *)(in_ECX + 0x48) = uVar2;
  uVar1 = FUN_00475a90(0x14,1);
  *(undefined2 *)(in_ECX + 0x4c) = uVar1;
  uVar1 = FUN_00475a90(0x15,1);
  *(undefined2 *)(in_ECX + 0x4e) = uVar1;
  (**(code **)(*DAT_00b5aa34 + 0xc))(uVar3);
  return;
}


// ==== FUN_005fa4b0 @ 0x005fa4b0 ====

void FUN_005fa4b0(byte param_1)

{
  void *in_ECX;
  
  FUN_005fa290();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fa4d0 @ 0x005fa4d0 ====

void FUN_005fa4d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7a40;
  return;
}


// ==== FUN_005fa4e0 @ 0x005fa4e0 ====

void FUN_005fa4e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7a40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fa500 @ 0x005fa500 ====

void FUN_005fa500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7a54;
  return;
}


// ==== FUN_005fa510 @ 0x005fa510 ====

void FUN_005fa510(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7aac;
  return;
}


// ==== FUN_005fa520 @ 0x005fa520 ====

void FUN_005fa520(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7ac4;
  return;
}


// ==== FUN_005fa530 @ 0x005fa530 ====

void FUN_005fa530(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7a54;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fa550 @ 0x005fa550 ====

void FUN_005fa550(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7aac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fa570 @ 0x005fa570 ====

void FUN_005fa570(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7ac4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fa590 @ 0x005fa590 ====

undefined4 FUN_005fa590(void)

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


// ==== FUN_005fa5b0 @ 0x005fa5b0 ====

undefined4 FUN_005fa5b0(void)

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


// ==== FUN_005fa5e0 @ 0x005fa5e0 ====

void FUN_005fa5e0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986098;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c7ae4;
  DAT_00b5ab04 = 0;
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
  *in_ECX = &PTR_FUN_009c7a40;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005fa680 @ 0x005fa680 ====

void FUN_005fa680(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int *piVar6;
  undefined1 auStack_10e [242];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 *puStack_4;
  
  puStack_4 = (undefined4 *)0xffffffff;
  puStack_8 = &LAB_009860b0;
  pvStack_c = ExceptionList;
  piVar6 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar3 = operator_new(0x10);
  pvStack_c = (void *)0x0;
  if (pvVar3 != (void *)0x0) {
    piVar6 = (int *)FUN_006291c0();
  }
  puVar1 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar6 + 8))(puStack_4);
  *puVar2 = *puVar1;
  puVar2[1] = piVar6;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009c7a28,
                         s___Siege_Location_Flyweight_Conta_009c79fc,0x3c);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_005fa750 @ 0x005fa750 ====

void FUN_005fa750(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009860d8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7ae4;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005fa840();
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
    uVar3 = FUN_005fade0(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab04 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab04 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fa820 @ 0x005fa820 ====

void FUN_005fa820(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7adc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_005fa840 @ 0x005fa840 ====

void FUN_005fa840(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009860f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7af8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c7adc;
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


// ==== FUN_005fa8f0 @ 0x005fa8f0 ====

void * FUN_005fa8f0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7b10,0x85);
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


// ==== FUN_005fa9a0 @ 0x005fa9a0 ====

undefined4 FUN_005fa9a0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7b10,0xa9);
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


// ==== FUN_005faa20 @ 0x005faa20 ====

void FUN_005faa20(byte param_1)

{
  void *in_ECX;
  
  FUN_005fa820();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005faa40 @ 0x005faa40 ====

void FUN_005faa40(byte param_1)

{
  void *in_ECX;
  
  FUN_005faa60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005faa60 @ 0x005faa60 ====

void FUN_005faa60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986123;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7af8;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c7adc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c7aac;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_005faae0 @ 0x005faae0 ====

void FUN_005faae0(byte param_1)

{
  void *in_ECX;
  
  FUN_005fa5e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fab00 @ 0x005fab00 ====

void FUN_005fab00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7b8c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_005fab20 @ 0x005fab20 ====

void FUN_005fab20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986143;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7b94;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c7b8c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c7ac4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_005faba0 @ 0x005faba0 ====

undefined4 FUN_005faba0(void)

{
  return 0x100;
}


// ==== FUN_005fabb0 @ 0x005fabb0 ====

undefined4 FUN_005fabb0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7b10,0xa9);
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


// ==== FUN_005fac30 @ 0x005fac30 ====

undefined4 * FUN_005fac30(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7b10,0x85);
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


// ==== FUN_005facf0 @ 0x005facf0 ====

void FUN_005facf0(byte param_1)

{
  void *in_ECX;
  
  FUN_005fab00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fad10 @ 0x005fad10 ====

void FUN_005fad10(byte param_1)

{
  void *in_ECX;
  
  FUN_005fab20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fad30 @ 0x005fad30 ====

void FUN_005fad30(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986158;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7b94;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c7b8c;
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


// ==== FUN_005fade0 @ 0x005fade0 ====

void FUN_005fade0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986178;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7bac;
  FUN_005fad30();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fae40 @ 0x005fae40 ====

void FUN_005fae40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005fae60(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005fae60 @ 0x005fae60 ====

void FUN_005fae60(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005fae60(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005fae60(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005faea0 @ 0x005faea0 ====

void FUN_005faea0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005faec0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005faec0 @ 0x005faec0 ====

void FUN_005faec0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005faec0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005faec0(param_1[3]);
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


// ==== FUN_005faf30 @ 0x005faf30 ====

void FUN_005faf30(byte param_1)

{
  void *in_ECX;
  
  FUN_005faf50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005faf50 @ 0x005faf50 ====

void FUN_005faf50(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009861a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7bac;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005faec0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005fab20();
  *in_ECX = &PTR_FUN_009c7a54;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fafc0 @ 0x005fafc0 ====

void FUN_005fafc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7c3c;
  return;
}


// ==== FUN_005fafd0 @ 0x005fafd0 ====

void FUN_005fafd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7c3c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005faff0 @ 0x005faff0 ====

void FUN_005faff0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7c4c;
  return;
}


// ==== FUN_005fb000 @ 0x005fb000 ====

void FUN_005fb000(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7c64;
  return;
}


// ==== FUN_005fb010 @ 0x005fb010 ====

void FUN_005fb010(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7cbc;
  return;
}


// ==== FUN_005fb020 @ 0x005fb020 ====

void FUN_005fb020(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7c4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fb040 @ 0x005fb040 ====

void FUN_005fb040(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7c64;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fb060 @ 0x005fb060 ====

void FUN_005fb060(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7cbc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fb080 @ 0x005fb080 ====

undefined4 FUN_005fb080(undefined4 param_1)

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


// ==== FUN_005fb0b0 @ 0x005fb0b0 ====

void FUN_005fb0b0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009861b8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c7cdc;
  DAT_00b5ab08 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    (**(code **)(*DAT_00b5ab0c + 8))(*(undefined4 *)(*piVar1 + 4));
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c7c3c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005fb150 @ 0x005fb150 ====

undefined4 FUN_005fb150(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 auStack_fe [250];
  int *piStack_4;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  puVar2 = (undefined4 *)(**(code **)(*piStack_4 + 8))();
  *puVar1 = *puVar2;
  puVar1[1] = piStack_4;
  iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar1);
  if (iVar3 != 0) {
    uVar4 = FUN_0044a580(auStack_fe + -0xe,s_File___s__Line___d_009c7c24,
                         s___Siege_Location_Container_cpp_009c7c04,0x39);
    FUN_00797b80(uVar4);
    FUN_00797a40();
  }
  return 1;
}


// ==== FUN_005fb1d0 @ 0x005fb1d0 ====

void FUN_005fb1d0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009861e0;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7cdc;
  pvVar2 = operator_new(0x1a8);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005fb2e0();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x2a8);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005fb860(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab08 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab08 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fb2a0 @ 0x005fb2a0 ====

void FUN_005fb2a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7cd4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x14,FUN_006ef6d0);
  return;
}


// ==== FUN_005fb2c0 @ 0x005fb2c0 ====

void FUN_005fb2c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005fb2a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fb2e0 @ 0x005fb2e0 ====

void FUN_005fb2e0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009861f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7cec;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c7cd4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x14,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0x66] = 0;
  in_ECX[0x66] = in_ECX[0x66] + 0x14;
  in_ECX[0x69] = in_ECX + 2;
  in_ECX[0x67] = 0;
  in_ECX[0x68] = 0;
  iVar2 = 0x13;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[99] = 0;
  in_ECX[100] = 0;
  in_ECX[0x65] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fb390 @ 0x005fb390 ====

void FUN_005fb390(byte param_1)

{
  void *in_ECX;
  
  FUN_005fb3b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fb3b0 @ 0x005fb3b0 ====

void FUN_005fb3b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986223;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7cec;
  local_4 = 1;
  if ((void *)in_ECX[0x68] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c7cd4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x14,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c7c4c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x68]);
  return;
}


// ==== FUN_005fb430 @ 0x005fb430 ====

void * FUN_005fb430(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7d00,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x1a4);
  *(int *)(in_ECX + 0x19c) = *(int *)(in_ECX + 0x19c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0x1a0);
    *(void **)(in_ECX + 0x1a0) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1a4) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_005fb4e0 @ 0x005fb4e0 ====

undefined4 FUN_005fb4e0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7d00,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x1a4);
    *(int *)(in_ECX + 0x19c) = *(int *)(in_ECX + 0x19c) + -1;
    *(int *)(in_ECX + 0x1a4) = param_2;
  }
  return 0;
}


// ==== FUN_005fb560 @ 0x005fb560 ====

void FUN_005fb560(byte param_1)

{
  void *in_ECX;
  
  FUN_005fb0b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fb580 @ 0x005fb580 ====

void FUN_005fb580(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7d70;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x14,FUN_006ef6d0);
  return;
}


// ==== FUN_005fb5a0 @ 0x005fb5a0 ====

void FUN_005fb5a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986243;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7d78;
  local_4 = 1;
  if ((void *)in_ECX[0xa4] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c7d70;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x14,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c7cbc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xa4]);
  return;
}


// ==== FUN_005fb620 @ 0x005fb620 ====

undefined4 FUN_005fb620(void)

{
  return 0x14;
}


// ==== FUN_005fb630 @ 0x005fb630 ====

undefined4 FUN_005fb630(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7d00,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x294);
    *(int *)(in_ECX + 0x28c) = *(int *)(in_ECX + 0x28c) + -1;
    *(int *)(in_ECX + 0x294) = param_2;
  }
  return 0;
}


// ==== FUN_005fb6b0 @ 0x005fb6b0 ====

undefined4 * FUN_005fb6b0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7d00,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x294);
  *(int *)(in_ECX + 0x28c) = *(int *)(in_ECX + 0x28c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x290);
    *(undefined4 **)(in_ECX + 0x290) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x294) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005fb770 @ 0x005fb770 ====

void FUN_005fb770(byte param_1)

{
  void *in_ECX;
  
  FUN_005fb580();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fb790 @ 0x005fb790 ====

void FUN_005fb790(byte param_1)

{
  void *in_ECX;
  
  FUN_005fb5a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fb7b0 @ 0x005fb7b0 ====

void FUN_005fb7b0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986258;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7d78;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c7d70;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x14,FUN_00607500,FUN_006ef6d0);
  in_ECX[0xa2] = 0;
  in_ECX[0xa2] = in_ECX[0xa2] + 0x14;
  in_ECX[0xa5] = in_ECX + 2;
  in_ECX[0xa3] = 0;
  in_ECX[0xa4] = 0;
  iVar2 = 0x13;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x9f] = 0;
  in_ECX[0xa0] = 0;
  in_ECX[0xa1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fb860 @ 0x005fb860 ====

void FUN_005fb860(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986278;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7d94;
  FUN_005fb7b0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fb8c0 @ 0x005fb8c0 ====

void FUN_005fb8c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005fb8e0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005fb8e0 @ 0x005fb8e0 ====

void FUN_005fb8e0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005fb8e0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005fb8e0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005fb920 @ 0x005fb920 ====

void FUN_005fb920(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005fb940(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005fb940 @ 0x005fb940 ====

void FUN_005fb940(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005fb940(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005fb940(param_1[3]);
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


// ==== FUN_005fb9b0 @ 0x005fb9b0 ====

void FUN_005fb9b0(byte param_1)

{
  void *in_ECX;
  
  FUN_005fb9d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fb9d0 @ 0x005fb9d0 ====

void FUN_005fb9d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009862a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7d94;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005fb940(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005fb5a0();
  *in_ECX = &PTR_FUN_009c7c64;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fba40 @ 0x005fba40 ====

void FUN_005fba40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7dec;
  return;
}


// ==== FUN_005fba50 @ 0x005fba50 ====

void FUN_005fba50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7dec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fba70 @ 0x005fba70 ====

void FUN_005fba70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7dfc;
  return;
}


// ==== FUN_005fba80 @ 0x005fba80 ====

void FUN_005fba80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7dfc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fbab0 @ 0x005fbab0 ====

void FUN_005fbab0(void)

{
  FUN_00629270();
  return;
}


// ==== FUN_005fbac0 @ 0x005fbac0 ====

void FUN_005fbac0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00629280();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005fbae0 @ 0x005fbae0 ====

void FUN_005fbae0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986303;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7e34;
  pvVar1 = operator_new(0x108);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fbc20();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ab0c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab0c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fbb70 @ 0x005fbb70 ====

void FUN_005fbb70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986315;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7e34;
  DAT_00b5ab0c = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c7dec;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fbbd0 @ 0x005fbbd0 ====

undefined4 FUN_005fbbd0(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  FUN_00629220(unaff_ESI,unaff_retaddr);
  return uVar1;
}


// ==== FUN_005fbc00 @ 0x005fbc00 ====

void FUN_005fbc00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7e14;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x18,10,(_func_void_void_ptr *)&LAB_005fbaa0);
  return;
}


// ==== FUN_005fbc20 @ 0x005fbc20 ====

void FUN_005fbc20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009862b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7e1c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c7e14;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x18,10,FUN_005fbab0,(_func_void_void_ptr *)&LAB_005fbaa0);
  in_ECX[0x3e] = 0;
  in_ECX[0x3e] = in_ECX[0x3e] + 10;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = in_ECX + 2;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[5] = in_ECX + 8;
  in_ECX[0xb] = in_ECX + 0xe;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0x11] = in_ECX + 0x14;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x17] = in_ECX + 0x1a;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1d] = in_ECX + 0x20;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x23] = in_ECX + 0x26;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x29] = in_ECX + 0x2c;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2f] = in_ECX + 0x32;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x35] = in_ECX + 0x38;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x3b] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fbd30 @ 0x005fbd30 ====

void FUN_005fbd30(byte param_1)

{
  void *in_ECX;
  
  FUN_005fbc00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fbd50 @ 0x005fbd50 ====

void FUN_005fbd50(byte param_1)

{
  void *in_ECX;
  
  FUN_005fbd70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fbd70 @ 0x005fbd70 ====

void FUN_005fbd70(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009862e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7e1c;
  _Memory = (void *)in_ECX[0x40];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c7e14;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x18,10,(_func_void_void_ptr *)&LAB_005fbaa0);
    *in_ECX = &PTR_FUN_009c7dfc;
    ExceptionList = local_c;
    return;
  }
  FUN_00629210();
  _free(_Memory);
  return;
}


// ==== FUN_005fbe00 @ 0x005fbe00 ====

void * FUN_005fbe00(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00986339;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x104);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0xfc) = *(int *)(in_ECX + 0xfc) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x18);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00629270();
      }
      *(undefined4 *)((int)param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x100);
      *(void **)(in_ECX + 0x100) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x104) = *(undefined4 *)((int)param_2 + 0xc);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c7d00,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x14) = *(int *)((int)param_2 + 0x14) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005fbf10 @ 0x005fbf10 ====

undefined4 FUN_005fbf10(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x14) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7d00,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x14);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x14);
    }
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(in_ECX + 0x104);
    *(int *)(in_ECX + 0xfc) = *(int *)(in_ECX + 0xfc) + -1;
    *(int *)(in_ECX + 0x104) = param_2;
  }
  return 0;
}


// ==== FUN_005fbf90 @ 0x005fbf90 ====

void FUN_005fbf90(byte param_1)

{
  void *in_ECX;
  
  FUN_005fbb70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fbfb0 @ 0x005fbfb0 ====

void FUN_005fbfb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7e84;
  return;
}


// ==== FUN_005fbfc0 @ 0x005fbfc0 ====

void FUN_005fbfc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7e84;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fbfe0 @ 0x005fbfe0 ====

void FUN_005fbfe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7e9c;
  return;
}


// ==== FUN_005fbff0 @ 0x005fbff0 ====

void FUN_005fbff0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7ef4;
  return;
}


// ==== FUN_005fc000 @ 0x005fc000 ====

void FUN_005fc000(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7f0c;
  return;
}


// ==== FUN_005fc010 @ 0x005fc010 ====

void FUN_005fc010(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7e9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fc030 @ 0x005fc030 ====

void FUN_005fc030(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7ef4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fc050 @ 0x005fc050 ====

void FUN_005fc050(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7f0c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fc070 @ 0x005fc070 ====

undefined4 FUN_005fc070(undefined4 param_1)

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


// ==== FUN_005fc0a0 @ 0x005fc0a0 ====

undefined4 FUN_005fc0a0(void)

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


// ==== FUN_005fc0c0 @ 0x005fc0c0 ====

undefined4 FUN_005fc0c0(void)

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


// ==== FUN_005fc0f0 @ 0x005fc0f0 ====

void FUN_005fc0f0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986358;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c7f2c;
  DAT_00b5aaf8 = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    (**(code **)(*DAT_00b5aafc + 8))(*(undefined4 *)(*piVar1 + 4));
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c7e84;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005fc190 @ 0x005fc190 ====

undefined4 FUN_005fc190(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined1 auStack_fe [250];
  int *piStack_4;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  puVar2 = (undefined4 *)(**(code **)(*piStack_4 + 4))();
  *puVar1 = *puVar2;
  puVar1[1] = piStack_4;
  iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar1);
  if (iVar3 != 0) {
    uVar4 = FUN_0044a580(auStack_fe + -0xe,s_File___s__Line___d_009c7e6c,
                         s___Siege_Battle_Zeolite_Container_009c7e44,0x37);
    FUN_00797b80(uVar4);
    FUN_00797a40();
  }
  return 1;
}


// ==== FUN_005fc210 @ 0x005fc210 ====

void FUN_005fc210(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00986380;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7f2c;
  pvVar2 = operator_new(0xe0);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005fc320();
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
    uVar3 = FUN_005fc950(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aaf8 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aaf8 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fc2e0 @ 0x005fc2e0 ====

void FUN_005fc2e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7f24;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,10,FUN_006ef6d0);
  return;
}


// ==== FUN_005fc300 @ 0x005fc300 ====

void FUN_005fc300(byte param_1)

{
  void *in_ECX;
  
  FUN_005fc2e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fc320 @ 0x005fc320 ====

void FUN_005fc320(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986398;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7f44;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c7f24;
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


// ==== FUN_005fc420 @ 0x005fc420 ====

void FUN_005fc420(byte param_1)

{
  void *in_ECX;
  
  FUN_005fc440();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fc440 @ 0x005fc440 ====

void FUN_005fc440(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009863c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7f44;
  local_4 = 1;
  if ((void *)in_ECX[0x36] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c7f24;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,10,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c7ef4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x36]);
  return;
}


// ==== FUN_005fc4c0 @ 0x005fc4c0 ====

void * FUN_005fc4c0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7f58,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0xdc);
  *(int *)(in_ECX + 0xd4) = *(int *)(in_ECX + 0xd4) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0xd8);
    *(void **)(in_ECX + 0xd8) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0xdc) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_005fc570 @ 0x005fc570 ====

undefined4 FUN_005fc570(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7f58,0xa9);
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


// ==== FUN_005fc5f0 @ 0x005fc5f0 ====

void FUN_005fc5f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005fc0f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fc610 @ 0x005fc610 ====

void FUN_005fc610(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c7fd0;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,10,FUN_006ef6d0);
  return;
}


// ==== FUN_005fc630 @ 0x005fc630 ====

void FUN_005fc630(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009863e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7fd8;
  local_4 = 1;
  if ((void *)in_ECX[0x54] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c7fd0;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,10,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c7f0c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x54]);
  return;
}


// ==== FUN_005fc6b0 @ 0x005fc6b0 ====

undefined4 FUN_005fc6b0(void)

{
  return 10;
}


// ==== FUN_005fc6c0 @ 0x005fc6c0 ====

undefined4 FUN_005fc6c0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7f58,0xa9);
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


// ==== FUN_005fc740 @ 0x005fc740 ====

undefined4 * FUN_005fc740(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7f58,0x85);
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


// ==== FUN_005fc800 @ 0x005fc800 ====

void FUN_005fc800(byte param_1)

{
  void *in_ECX;
  
  FUN_005fc610();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fc820 @ 0x005fc820 ====

void FUN_005fc820(byte param_1)

{
  void *in_ECX;
  
  FUN_005fc630();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fc840 @ 0x005fc840 ====

void FUN_005fc840(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009863f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7fd8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c7fd0;
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


// ==== FUN_005fc950 @ 0x005fc950 ====

void FUN_005fc950(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986418;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7ff4;
  FUN_005fc840();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fc9b0 @ 0x005fc9b0 ====

void FUN_005fc9b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005fc9d0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005fc9d0 @ 0x005fc9d0 ====

void FUN_005fc9d0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005fc9d0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005fc9d0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005fca10 @ 0x005fca10 ====

void FUN_005fca10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005fca30(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005fca30 @ 0x005fca30 ====

void FUN_005fca30(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005fca30(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005fca30(param_1[3]);
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


// ==== FUN_005fcaa0 @ 0x005fcaa0 ====

void FUN_005fcaa0(byte param_1)

{
  void *in_ECX;
  
  FUN_005fcac0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fcac0 @ 0x005fcac0 ====

void FUN_005fcac0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00986443;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c7ff4;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005fca30(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005fc630();
  *in_ECX = &PTR_FUN_009c7e9c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fcb30 @ 0x005fcb30 ====

void FUN_005fcb30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c804c;
  return;
}


// ==== FUN_005fcb40 @ 0x005fcb40 ====

void FUN_005fcb40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c804c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fcb60 @ 0x005fcb60 ====

void FUN_005fcb60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c805c;
  return;
}


// ==== FUN_005fcb70 @ 0x005fcb70 ====

void FUN_005fcb70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c805c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fcba0 @ 0x005fcba0 ====

void FUN_005fcba0(void)

{
  FUN_00629440();
  return;
}


// ==== FUN_005fcbb0 @ 0x005fcbb0 ====

void FUN_005fcbb0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00629480();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005fcbd0 @ 0x005fcbd0 ====

void FUN_005fcbd0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009864a3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8094;
  pvVar1 = operator_new(0xa4);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fcd10();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aafc = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aafc = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fcc60 @ 0x005fcc60 ====

void FUN_005fcc60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009864b5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8094;
  DAT_00b5aafc = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c804c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fccc0 @ 0x005fccc0 ====

undefined4 FUN_005fccc0(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  FUN_00629460(unaff_ESI,unaff_retaddr);
  return uVar1;
}


// ==== FUN_005fccf0 @ 0x005fccf0 ====

void FUN_005fccf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8074;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,5,(_func_void_void_ptr *)&LAB_005fcb90);
  return;
}


// ==== FUN_005fcd10 @ 0x005fcd10 ====

void FUN_005fcd10(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986458;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c807c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c8074;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x1c,5,FUN_005fcba0,(_func_void_void_ptr *)&LAB_005fcb90);
  in_ECX[0x25] = 0;
  in_ECX[0x25] = in_ECX[0x25] + 5;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = in_ECX + 2;
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
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fcdd0 @ 0x005fcdd0 ====

undefined4 FUN_005fcdd0(void)

{
  return 5;
}


// ==== FUN_005fcde0 @ 0x005fcde0 ====

void FUN_005fcde0(byte param_1)

{
  void *in_ECX;
  
  FUN_005fccf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fce00 @ 0x005fce00 ====

void FUN_005fce00(byte param_1)

{
  void *in_ECX;
  
  FUN_005fce20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fce20 @ 0x005fce20 ====

void FUN_005fce20(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986483;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c807c;
  _Memory = (void *)in_ECX[0x27];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c8074;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,5,(_func_void_void_ptr *)&LAB_005fcb90);
    *in_ECX = &PTR_FUN_009c805c;
    ExceptionList = local_c;
    return;
  }
  FUN_006293f0();
  _free(_Memory);
  return;
}


// ==== FUN_005fceb0 @ 0x005fceb0 ====

void * FUN_005fceb0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009864d9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0xa0);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x98) = *(int *)(in_ECX + 0x98) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x1c);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00629440();
      }
      *(undefined4 *)((int)param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x9c);
      *(void **)(in_ECX + 0x9c) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0xa0) = *(undefined4 *)((int)param_2 + 0x10);
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
                           s_d__usa_24_0_1_2__develop_share_l_009c7f58,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x18) = *(int *)((int)param_2 + 0x18) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005fcfc0 @ 0x005fcfc0 ====

undefined4 FUN_005fcfc0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c7f58,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x18);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x18);
    }
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(in_ECX + 0xa0);
    *(int *)(in_ECX + 0x98) = *(int *)(in_ECX + 0x98) + -1;
    *(int *)(in_ECX + 0xa0) = param_2;
  }
  return 0;
}


// ==== FUN_005fd040 @ 0x005fd040 ====

void FUN_005fd040(byte param_1)

{
  void *in_ECX;
  
  FUN_005fcc60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fd060 @ 0x005fd060 ====

void FUN_005fd060(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c80a4;
  return;
}


// ==== FUN_005fd070 @ 0x005fd070 ====

void FUN_005fd070(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c80a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fd090 @ 0x005fd090 ====

undefined4 FUN_005fd090(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_005fd0a0 @ 0x005fd0a0 ====

void FUN_005fd0a0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986503;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c80b0;
  pvVar1 = operator_new(0x58);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00629590();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ab00 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab00 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fd130 @ 0x005fd130 ====

void FUN_005fd130(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986515;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c80b0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  DAT_00b5ab00 = 0;
  *in_ECX = &PTR_FUN_009c80a4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fd190 @ 0x005fd190 ====

void FUN_005fd190(byte param_1)

{
  void *in_ECX;
  
  FUN_005fd130();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fd1b0 @ 0x005fd1b0 ====

void FUN_005fd1b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c80f4;
  return;
}


// ==== FUN_005fd1c0 @ 0x005fd1c0 ====

void FUN_005fd1c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c80f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fd1e0 @ 0x005fd1e0 ====

void FUN_005fd1e0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005fd1e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_005fd1f0 @ 0x005fd1f0 ====

void FUN_005fd1f0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005fd1f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_005fd200 @ 0x005fd200 ====

undefined4 FUN_005fd200(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0x24);
}


// ==== FUN_005fd220 @ 0x005fd220 ====

undefined4 FUN_005fd220(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 0x24);
    }
  }
  return 0;
}


// ==== FUN_005fd250 @ 0x005fd250 ====

void FUN_005fd250(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986528;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c81ac;
  DAT_00b5ac9c = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    (**(code **)(*DAT_00b5aca0 + 8))(*(undefined4 *)(*piVar1 + 0x24));
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c80f4;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005fd2f0 @ 0x005fd2f0 ====

undefined4 FUN_005fd2f0(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  char *pcVar5;
  uint uVar6;
  undefined1 auStack_fe [250];
  int *piStack_4;
  
  pcVar2 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  iVar3 = (**(code **)(*piStack_4 + 4))();
  uVar6 = 0;
  pcVar5 = pcVar2;
  do {
    cVar1 = pcVar5[iVar3 - (int)pcVar2];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_005fd338;
    uVar6 = uVar6 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar6 < 0x21);
  *pcVar2 = '\0';
LAB_005fd338:
  *(int **)(pcVar2 + 0x24) = piStack_4;
  iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(pcVar2);
  if (iVar3 != 0) {
    uVar4 = FUN_0044a580(auStack_fe + -0xe,s_File___s__Line___d_009c80dc,
                         s___Siege_Defender_Container_cpp_009c80bc,0x35);
    FUN_00797b80(uVar4);
    FUN_00797a40();
  }
  return 1;
}


// ==== FUN_005fd380 @ 0x005fd380 ====

void FUN_005fd380(int *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 auStack_28 [40];
  
  uVar1 = (**(code **)(*param_1 + 4))();
  FUN_005fe720(uVar1);
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(auStack_28);
  (**(code **)(**(int **)(in_ECX + 8) + 0x40))(uVar1);
  return;
}


// ==== FUN_005fd3c0 @ 0x005fd3c0 ====

undefined4 FUN_005fd3c0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_28 [40];
  
  FUN_005fe720(param_1);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_28);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0x24);
}


// ==== FUN_005fd400 @ 0x005fd400 ====

void FUN_005fd400(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00986550;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c81ac;
  pvVar2 = operator_new(0x80);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005fd580();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0x68);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005fdaf0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ac9c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ac9c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fd4c0 @ 0x005fd4c0 ====

void FUN_005fd4c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c811c;
  return;
}


// ==== FUN_005fd4d0 @ 0x005fd4d0 ====

void FUN_005fd4d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8174;
  return;
}


// ==== FUN_005fd4e0 @ 0x005fd4e0 ====

void FUN_005fd4e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c818c;
  return;
}


// ==== FUN_005fd4f0 @ 0x005fd4f0 ====

void FUN_005fd4f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c811c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fd510 @ 0x005fd510 ====

void FUN_005fd510(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8174;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fd530 @ 0x005fd530 ====

void FUN_005fd530(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c818c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fd550 @ 0x005fd550 ====

void FUN_005fd550(void)

{
  undefined1 *in_ECX;
  
  *in_ECX = 0;
  return;
}


// ==== FUN_005fd560 @ 0x005fd560 ====

void FUN_005fd560(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c81a4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x34,2,FUN_006ef6d0);
  return;
}


// ==== FUN_005fd580 @ 0x005fd580 ====

void FUN_005fd580(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986568;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c81d0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c81a4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x34,2,FUN_00636380,FUN_006ef6d0);
  in_ECX[0x1c] = 0;
  in_ECX[0x1c] = in_ECX[0x1c] + 2;
  in_ECX[0x1d] = 0;
  in_ECX[0x1e] = 0;
  in_ECX[0x1f] = in_ECX + 2;
  in_ECX[0xc] = in_ECX + 0xf;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fd610 @ 0x005fd610 ====

undefined4 FUN_005fd610(void)

{
  return 2;
}


// ==== FUN_005fd620 @ 0x005fd620 ====

undefined4 FUN_005fd620(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x74);
}


// ==== FUN_005fd630 @ 0x005fd630 ====

undefined1 * FUN_005fd630(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined1 *)0x0) {
    if (*(int *)(param_2 + 0x30) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c81e8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x30) + param_1;
    return param_2;
  }
  puVar2 = *(undefined1 **)(in_ECX + 0x7c);
  *(int *)(in_ECX + 0x74) = *(int *)(in_ECX + 0x74) + 1;
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = operator_new(0x34);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = (undefined1 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    *(undefined4 *)(puVar2 + 0x2c) = *(undefined4 *)(in_ECX + 0x78);
    *(undefined1 **)(in_ECX + 0x78) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(puVar2 + 0x28);
  }
  *(undefined4 *)(puVar2 + 0x28) = 0;
  *(int *)(puVar2 + 0x30) = param_1;
  return puVar2;
}


// ==== FUN_005fd6e0 @ 0x005fd6e0 ====

undefined4 FUN_005fd6e0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x30) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c81e8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x30);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x30);
    }
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(in_ECX + 0x7c);
    *(int *)(in_ECX + 0x74) = *(int *)(in_ECX + 0x74) + -1;
    *(int *)(in_ECX + 0x7c) = param_2;
  }
  return 0;
}


// ==== FUN_005fd760 @ 0x005fd760 ====

void FUN_005fd760(byte param_1)

{
  void *in_ECX;
  
  FUN_005fd560();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fd780 @ 0x005fd780 ====

void FUN_005fd780(byte param_1)

{
  void *in_ECX;
  
  FUN_005fd7a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fd7a0 @ 0x005fd7a0 ====

void FUN_005fd7a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986593;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c81d0;
  local_4 = 1;
  if ((void *)in_ECX[0x1e] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c81a4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x34,2,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c8174;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1e]);
  return;
}


// ==== FUN_005fd820 @ 0x005fd820 ====

void FUN_005fd820(byte param_1)

{
  void *in_ECX;
  
  FUN_005fd250();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fd840 @ 0x005fd840 ====

void FUN_005fd840(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8258;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,2,FUN_006ef6d0);
  return;
}


// ==== FUN_005fd860 @ 0x005fd860 ====

void FUN_005fd860(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009865b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8260;
  local_4 = 1;
  if ((void *)in_ECX[0x14] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c8258;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,2,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c818c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x14]);
  return;
}


// ==== FUN_005fd8e0 @ 0x005fd8e0 ====

undefined4 FUN_005fd8e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x4c);
}


// ==== FUN_005fd8f0 @ 0x005fd8f0 ====

undefined4 FUN_005fd8f0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c81e8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x54);
    *(int *)(in_ECX + 0x4c) = *(int *)(in_ECX + 0x4c) + -1;
    *(int *)(in_ECX + 0x54) = param_2;
  }
  return 0;
}


// ==== FUN_005fd970 @ 0x005fd970 ====

undefined4 * FUN_005fd970(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c81e8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x54);
  *(int *)(in_ECX + 0x4c) = *(int *)(in_ECX + 0x4c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x50);
    *(undefined4 **)(in_ECX + 0x50) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x54) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005fda20 @ 0x005fda20 ====

void FUN_005fda20(byte param_1)

{
  void *in_ECX;
  
  FUN_005fd840();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fda40 @ 0x005fda40 ====

void FUN_005fda40(byte param_1)

{
  void *in_ECX;
  
  FUN_005fd860();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fda60 @ 0x005fda60 ====

void FUN_005fda60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009865c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8260;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c8258;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,2,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x12] = 0;
  in_ECX[0x12] = in_ECX[0x12] + 2;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = in_ECX + 2;
  in_ECX[7] = in_ECX + 10;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fdaf0 @ 0x005fdaf0 ====

void FUN_005fdaf0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009865e8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c827c;
  FUN_005fda60();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fdb50 @ 0x005fdb50 ====

void FUN_005fdb50(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005fdb70(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005fdb70 @ 0x005fdb70 ====

void FUN_005fdb70(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005fdb70(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005fdb70(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005fdbb0 @ 0x005fdbb0 ====

undefined4 * FUN_005fdbb0(void)

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
  iVar4 = FUN_005fdc60(iVar1,*puVar2);
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
        goto LAB_005fdc49;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
LAB_005fdc49:
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_005fdc60(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_005fdc60 @ 0x005fdc60 ====

uint FUN_005fdc60(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  
  cVar1 = FUN_005fdca0(param_2);
  if (cVar1 == '\0') {
    cVar1 = FUN_005fdca0(param_1);
    return (uint)(cVar1 != '\0');
  }
  return 0xffffffff;
}


// ==== FUN_005fdca0 @ 0x005fdca0 ====

undefined4 FUN_005fdca0(int param_1)

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
  } while (uVar2 < 0x21);
  return 0;
}


// ==== FUN_005fdce0 @ 0x005fdce0 ====

void FUN_005fdce0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005fdd00(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005fdd00 @ 0x005fdd00 ====

void FUN_005fdd00(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005fdd00(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005fdd00(param_1[3]);
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


// ==== FUN_005fdd70 @ 0x005fdd70 ====

undefined4 * FUN_005fdd70(undefined4 param_1)

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
    cVar1 = FUN_005fdca0(*puVar3);
    if (cVar1 == '\0') {
      cVar1 = FUN_005fdca0(param_1);
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


// ==== FUN_005fddf0 @ 0x005fddf0 ====

void FUN_005fddf0(byte param_1)

{
  void *in_ECX;
  
  FUN_005fde10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fde10 @ 0x005fde10 ====

void FUN_005fde10(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00986613;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c827c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005fdd00(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005fd860();
  *in_ECX = &PTR_FUN_009c811c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fde80 @ 0x005fde80 ====

void FUN_005fde80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c82d4;
  return;
}


// ==== FUN_005fde90 @ 0x005fde90 ====

void FUN_005fde90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c82d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fdeb0 @ 0x005fdeb0 ====

void FUN_005fdeb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c82e4;
  return;
}


// ==== FUN_005fdec0 @ 0x005fdec0 ====

void FUN_005fdec0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c82e4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fdef0 @ 0x005fdef0 ====

void FUN_005fdef0(void)

{
  FUN_00629840();
  return;
}


// ==== FUN_005fdf00 @ 0x005fdf00 ====

void FUN_005fdf00(undefined4 param_1)

{
  int in_ECX;
  
  FUN_006297f0();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005fdf20 @ 0x005fdf20 ====

void FUN_005fdf20(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986673;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c831c;
  pvVar1 = operator_new(0x6c);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005fe060();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aca0 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aca0 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fdfb0 @ 0x005fdfb0 ====

void FUN_005fdfb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986685;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c831c;
  DAT_00b5aca0 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c82d4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fe010 @ 0x005fe010 ====

undefined4 FUN_005fe010(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  FUN_006298a0(unaff_ESI);
  return uVar1;
}


// ==== FUN_005fe040 @ 0x005fe040 ====

void FUN_005fe040(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c82fc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x54,1,(_func_void_void_ptr *)&LAB_005fdee0);
  return;
}


// ==== FUN_005fe060 @ 0x005fe060 ====

void FUN_005fe060(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986628;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8304;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c82fc;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x54,1,FUN_005fdef0,(_func_void_void_ptr *)&LAB_005fdee0);
  in_ECX[0x17] = 0;
  in_ECX[0x17] = in_ECX[0x17] + 1;
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = in_ECX + 2;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fe0e0 @ 0x005fe0e0 ====

undefined4 FUN_005fe0e0(void)

{
  return 1;
}


// ==== FUN_005fe0f0 @ 0x005fe0f0 ====

undefined4 FUN_005fe0f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x60);
}


// ==== FUN_005fe100 @ 0x005fe100 ====

void FUN_005fe100(byte param_1)

{
  void *in_ECX;
  
  FUN_005fe040();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fe120 @ 0x005fe120 ====

void FUN_005fe120(byte param_1)

{
  void *in_ECX;
  
  FUN_005fe140();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fe140 @ 0x005fe140 ====

void FUN_005fe140(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986653;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8304;
  _Memory = (void *)in_ECX[0x19];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c82fc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x54,1,(_func_void_void_ptr *)&LAB_005fdee0);
    *in_ECX = &PTR_FUN_009c82e4;
    ExceptionList = local_c;
    return;
  }
  FUN_00629830();
  _free(_Memory);
  return;
}


// ==== FUN_005fe1d0 @ 0x005fe1d0 ====

void * FUN_005fe1d0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009866a9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x68);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x60) = *(int *)(in_ECX + 0x60) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x54);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00629840();
      }
      *(undefined4 *)((int)param_2 + 0x4c) = *(undefined4 *)(in_ECX + 100);
      *(void **)(in_ECX + 100) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)((int)param_2 + 0x48);
    }
    *(undefined4 *)((int)param_2 + 0x48) = 0;
    *(int *)((int)param_2 + 0x50) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x50) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c81e8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x50) = *(int *)((int)param_2 + 0x50) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005fe2d0 @ 0x005fe2d0 ====

undefined4 FUN_005fe2d0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x50) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c81e8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x50);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x50);
    }
    *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(in_ECX + 0x68);
    *(int *)(in_ECX + 0x60) = *(int *)(in_ECX + 0x60) + -1;
    *(int *)(in_ECX + 0x68) = param_2;
  }
  return 0;
}


// ==== FUN_005fe350 @ 0x005fe350 ====

void FUN_005fe350(byte param_1)

{
  void *in_ECX;
  
  FUN_005fdfb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fe370 @ 0x005fe370 ====

void FUN_005fe370(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8364;
  return;
}


// ==== FUN_005fe380 @ 0x005fe380 ====

void FUN_005fe380(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8364;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fe3a0 @ 0x005fe3a0 ====

void FUN_005fe3a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005fe3a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_005fe3b0 @ 0x005fe3b0 ====

void FUN_005fe3b0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005fe3b5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_005fe3c0 @ 0x005fe3c0 ====

undefined4 FUN_005fe3c0(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  *(int **)(in_ECX + 0xc) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0x24);
}


// ==== FUN_005fe3e0 @ 0x005fe3e0 ====

undefined4 FUN_005fe3e0(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(*(int *)(in_ECX + 0xc));
    *(int **)(in_ECX + 0xc) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 0x24);
    }
  }
  return 0;
}


// ==== FUN_005fe410 @ 0x005fe410 ====

void FUN_005fe410(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009866c8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c841c;
  DAT_00b5abec = 0;
  local_4 = 0;
  for (piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x40))(piVar1)) {
    (**(code **)(*DAT_00b5abf0 + 8))(*(undefined4 *)(*piVar1 + 0x24));
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c8364;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005fe4b0 @ 0x005fe4b0 ====

undefined4 FUN_005fe4b0(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  char *pcVar5;
  uint uVar6;
  undefined1 auStack_fe [250];
  int *piStack_4;
  
  pcVar2 = (char *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  iVar3 = (**(code **)(*piStack_4 + 4))();
  uVar6 = 0;
  pcVar5 = pcVar2;
  do {
    cVar1 = pcVar5[iVar3 - (int)pcVar2];
    *pcVar5 = cVar1;
    if (cVar1 == '\0') goto LAB_005fe4f8;
    uVar6 = uVar6 + 1;
    pcVar5 = pcVar5 + 1;
  } while (uVar6 < 0x21);
  *pcVar2 = '\0';
LAB_005fe4f8:
  *(int **)(pcVar2 + 0x24) = piStack_4;
  iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(pcVar2);
  if (iVar3 != 0) {
    uVar4 = FUN_0044a580(auStack_fe + -0xe,s_File___s__Line___d_009c834c,
                         s___Siege_Attacker_Container_cpp_009c832c,0x36);
    FUN_00797b80(uVar4);
    FUN_00797a40();
  }
  return 1;
}


// ==== FUN_005fe540 @ 0x005fe540 ====

void FUN_005fe540(int *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 auStack_28 [40];
  
  uVar1 = (**(code **)(*param_1 + 4))();
  FUN_005fe720(uVar1);
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(auStack_28);
  (**(code **)(**(int **)(in_ECX + 8) + 0x40))(uVar1);
  return;
}


// ==== FUN_005fe580 @ 0x005fe580 ====

undefined4 FUN_005fe580(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_28 [40];
  
  FUN_005fe720(param_1);
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_28);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 0x24);
}


// ==== FUN_005fe5c0 @ 0x005fe5c0 ====

void FUN_005fe5c0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009866f0;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c841c;
  pvVar2 = operator_new(0x150);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005fe770();
  }
  puVar1 = in_ECX + 1;
  local_4 = (uint)local_4._1_3_ << 8;
  *puVar1 = uVar3;
  pvVar2 = operator_new(0xe8);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005fed80(*puVar1);
  }
  in_ECX[2] = uVar3;
  in_ECX[3] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5abec = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abec = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fe690 @ 0x005fe690 ====

void FUN_005fe690(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c838c;
  return;
}


// ==== FUN_005fe6a0 @ 0x005fe6a0 ====

void FUN_005fe6a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c83e4;
  return;
}


// ==== FUN_005fe6b0 @ 0x005fe6b0 ====

void FUN_005fe6b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c83fc;
  return;
}


// ==== FUN_005fe6c0 @ 0x005fe6c0 ====

void FUN_005fe6c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c838c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fe6e0 @ 0x005fe6e0 ====

void FUN_005fe6e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c83e4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fe700 @ 0x005fe700 ====

void FUN_005fe700(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c83fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fe720 @ 0x005fe720 ====

void FUN_005fe720(int param_1)

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
    if (cVar1 == '\0') {
      return;
    }
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0x21);
  *in_ECX = '\0';
  return;
}


// ==== FUN_005fe750 @ 0x005fe750 ====

void FUN_005fe750(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8414;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x34,6,FUN_006ef6d0);
  return;
}


// ==== FUN_005fe770 @ 0x005fe770 ====

void FUN_005fe770(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986708;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8440;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c8414;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x34,6,FUN_00636380,FUN_006ef6d0);
  in_ECX[0x50] = 0;
  in_ECX[0x50] = in_ECX[0x50] + 6;
  in_ECX[0x51] = 0;
  in_ECX[0x52] = 0;
  in_ECX[0x53] = in_ECX + 2;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xc] = in_ECX + 0xf;
  in_ECX[0x19] = in_ECX + 0x1c;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x26] = in_ECX + 0x29;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x33] = in_ECX + 0x36;
  in_ECX[0x34] = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x40] = in_ECX + 0x43;
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x4d] = 0;
  in_ECX[0x4e] = 0;
  in_ECX[0x4f] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fe840 @ 0x005fe840 ====

undefined4 FUN_005fe840(void)

{
  return 6;
}


// ==== FUN_005fe850 @ 0x005fe850 ====

undefined4 FUN_005fe850(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x144);
}


// ==== FUN_005fe860 @ 0x005fe860 ====

undefined1 * FUN_005fe860(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined1 *)0x0) {
    if (*(int *)(param_2 + 0x30) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8458,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x30) = *(int *)(param_2 + 0x30) + param_1;
    return param_2;
  }
  puVar2 = *(undefined1 **)(in_ECX + 0x14c);
  *(int *)(in_ECX + 0x144) = *(int *)(in_ECX + 0x144) + 1;
  if (puVar2 == (undefined1 *)0x0) {
    puVar2 = operator_new(0x34);
    if (puVar2 == (undefined1 *)0x0) {
      puVar2 = (undefined1 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    *(undefined4 *)(puVar2 + 0x2c) = *(undefined4 *)(in_ECX + 0x148);
    *(undefined1 **)(in_ECX + 0x148) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x14c) = *(undefined4 *)(puVar2 + 0x28);
  }
  *(undefined4 *)(puVar2 + 0x28) = 0;
  *(int *)(puVar2 + 0x30) = param_1;
  return puVar2;
}


// ==== FUN_005fe920 @ 0x005fe920 ====

undefined4 FUN_005fe920(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x30) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8458,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x30);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x30);
    }
    *(undefined4 *)(param_2 + 0x28) = *(undefined4 *)(in_ECX + 0x14c);
    *(int *)(in_ECX + 0x144) = *(int *)(in_ECX + 0x144) + -1;
    *(int *)(in_ECX + 0x14c) = param_2;
  }
  return 0;
}


// ==== FUN_005fe9a0 @ 0x005fe9a0 ====

void FUN_005fe9a0(byte param_1)

{
  void *in_ECX;
  
  FUN_005fe750();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fe9c0 @ 0x005fe9c0 ====

void FUN_005fe9c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005fe9e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fe9e0 @ 0x005fe9e0 ====

void FUN_005fe9e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986733;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8440;
  local_4 = 1;
  if ((void *)in_ECX[0x52] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c8414;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x34,6,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c83e4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x52]);
  return;
}


// ==== FUN_005fea60 @ 0x005fea60 ====

void FUN_005fea60(byte param_1)

{
  void *in_ECX;
  
  FUN_005fe410();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fea80 @ 0x005fea80 ====

void FUN_005fea80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c84c8;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,6,FUN_006ef6d0);
  return;
}


// ==== FUN_005feaa0 @ 0x005feaa0 ====

void FUN_005feaa0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986753;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c84d0;
  local_4 = 1;
  if ((void *)in_ECX[0x34] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c84c8;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,6,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c83fc;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x34]);
  return;
}


// ==== FUN_005feb20 @ 0x005feb20 ====

undefined4 FUN_005feb20(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xcc);
}


// ==== FUN_005feb30 @ 0x005feb30 ====

undefined4 FUN_005feb30(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8458,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0xd4);
    *(int *)(in_ECX + 0xcc) = *(int *)(in_ECX + 0xcc) + -1;
    *(int *)(in_ECX + 0xd4) = param_2;
  }
  return 0;
}


// ==== FUN_005febb0 @ 0x005febb0 ====

undefined4 * FUN_005febb0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8458,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xd4);
  *(int *)(in_ECX + 0xcc) = *(int *)(in_ECX + 0xcc) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0xd0);
    *(undefined4 **)(in_ECX + 0xd0) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0xd4) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005fec70 @ 0x005fec70 ====

void FUN_005fec70(byte param_1)

{
  void *in_ECX;
  
  FUN_005fea80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fec90 @ 0x005fec90 ====

void FUN_005fec90(byte param_1)

{
  void *in_ECX;
  
  FUN_005feaa0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fecb0 @ 0x005fecb0 ====

void FUN_005fecb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986768;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c84d0;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c84c8;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,6,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x32] = 0;
  in_ECX[0x32] = in_ECX[0x32] + 6;
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x35] = in_ECX + 2;
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
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fed80 @ 0x005fed80 ====

void FUN_005fed80(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986788;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c84ec;
  FUN_005fecb0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005fede0 @ 0x005fede0 ====

void FUN_005fede0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005fee00(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005fee00 @ 0x005fee00 ====

void FUN_005fee00(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005fee00(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005fee00(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005fee40 @ 0x005fee40 ====

void FUN_005fee40(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  
  iVar1 = *(int *)(param_1 + 0xc);
  iVar2 = *(int *)(param_1 + 0x10);
  iVar3 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    iVar5 = 0;
    if (iVar3 != 0) {
      *(int *)(iVar3 + 0x10) = iVar2;
      iVar5 = iVar3;
    }
  }
  else {
    iVar4 = *(int *)(iVar1 + 8);
    iVar5 = iVar1;
    while (iVar4 != 0) {
      iVar5 = *(int *)(iVar5 + 8);
      iVar4 = *(int *)(iVar5 + 8);
    }
    FUN_0061f0e0(iVar5,iVar1);
    *(int *)(iVar5 + 8) = iVar3;
    if (iVar3 != 0) {
      *(int *)(iVar3 + 0x10) = iVar5;
    }
    *(int *)(iVar5 + 0x10) = iVar2;
  }
  if (iVar2 == 0) {
    *(int *)(in_ECX + 4) = iVar5;
    return;
  }
  if (*(int *)(iVar2 + 8) == param_1) {
    *(int *)(iVar2 + 8) = iVar5;
    return;
  }
  *(int *)(iVar2 + 0xc) = iVar5;
  return;
}


// ==== FUN_005feed0 @ 0x005feed0 ====

void FUN_005feed0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005feef0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005feef0 @ 0x005feef0 ====

void FUN_005feef0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005feef0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005feef0(param_1[3]);
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


// ==== FUN_005fef70 @ 0x005fef70 ====

void FUN_005fef70(byte param_1)

{
  void *in_ECX;
  
  FUN_005fef90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fef90 @ 0x005fef90 ====

void FUN_005fef90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009867b3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c84ec;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005feef0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005feaa0();
  *in_ECX = &PTR_FUN_009c838c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ff000 @ 0x005ff000 ====

void FUN_005ff000(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8544;
  return;
}


// ==== FUN_005ff010 @ 0x005ff010 ====

void FUN_005ff010(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8544;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ff030 @ 0x005ff030 ====

void FUN_005ff030(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8554;
  return;
}


// ==== FUN_005ff040 @ 0x005ff040 ====

void FUN_005ff040(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8554;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ff070 @ 0x005ff070 ====

void FUN_005ff070(void)

{
  FUN_00629980();
  return;
}


// ==== FUN_005ff080 @ 0x005ff080 ====

void FUN_005ff080(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00629950();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005ff0a0 @ 0x005ff0a0 ====

void FUN_005ff0a0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986813;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c858c;
  pvVar1 = operator_new(0x114);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005ff1e0();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5abf0 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5abf0 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ff130 @ 0x005ff130 ====

void FUN_005ff130(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986825;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c858c;
  DAT_00b5abf0 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c8544;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ff190 @ 0x005ff190 ====

undefined4 FUN_005ff190(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  FUN_006299a0(unaff_ESI);
  return uVar1;
}


// ==== FUN_005ff1c0 @ 0x005ff1c0 ====

void FUN_005ff1c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c856c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x54,3,(_func_void_void_ptr *)&LAB_005ff060);
  return;
}


// ==== FUN_005ff1e0 @ 0x005ff1e0 ====

void FUN_005ff1e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009867c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8574;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c856c;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x54,3,FUN_005ff070,(_func_void_void_ptr *)&LAB_005ff060);
  in_ECX[0x41] = 0;
  in_ECX[0x41] = in_ECX[0x41] + 3;
  in_ECX[0x42] = 0;
  in_ECX[0x43] = 0;
  in_ECX[0x44] = in_ECX + 2;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x14] = in_ECX + 0x17;
  in_ECX[0x29] = in_ECX + 0x2c;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ff290 @ 0x005ff290 ====

void FUN_005ff290(byte param_1)

{
  void *in_ECX;
  
  FUN_005ff1c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ff2b0 @ 0x005ff2b0 ====

void FUN_005ff2b0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ff2d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ff2d0 @ 0x005ff2d0 ====

void FUN_005ff2d0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009867f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8574;
  _Memory = (void *)in_ECX[0x43];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c856c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x54,3,(_func_void_void_ptr *)&LAB_005ff060);
    *in_ECX = &PTR_FUN_009c8554;
    ExceptionList = local_c;
    return;
  }
  FUN_00629970();
  _free(_Memory);
  return;
}


// ==== FUN_005ff360 @ 0x005ff360 ====

void * FUN_005ff360(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00986849;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x110);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x108) = *(int *)(in_ECX + 0x108) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x54);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_00629980();
      }
      *(undefined4 *)((int)param_2 + 0x4c) = *(undefined4 *)(in_ECX + 0x10c);
      *(void **)(in_ECX + 0x10c) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x110) = *(undefined4 *)((int)param_2 + 0x48);
    }
    *(undefined4 *)((int)param_2 + 0x48) = 0;
    *(int *)((int)param_2 + 0x50) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x50) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8458,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x50) = *(int *)((int)param_2 + 0x50) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_005ff470 @ 0x005ff470 ====

undefined4 FUN_005ff470(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x50) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c8458,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x50);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x50);
    }
    *(undefined4 *)(param_2 + 0x48) = *(undefined4 *)(in_ECX + 0x110);
    *(int *)(in_ECX + 0x108) = *(int *)(in_ECX + 0x108) + -1;
    *(int *)(in_ECX + 0x110) = param_2;
  }
  return 0;
}


// ==== FUN_005ff4f0 @ 0x005ff4f0 ====

void FUN_005ff4f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ff130();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ff510 @ 0x005ff510 ====

void FUN_005ff510(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c859c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ff530 @ 0x005ff530 ====

void FUN_005ff530(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c859c;
  return;
}


// ==== FUN_005ff540 @ 0x005ff540 ====

undefined2 FUN_005ff540(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 4);
}


// ==== FUN_005ff550 @ 0x005ff550 ====

undefined1 FUN_005ff550(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 6);
}


// ==== FUN_005ff560 @ 0x005ff560 ====

undefined2 FUN_005ff560(byte param_1)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 8 + (uint)param_1 * 2);
}


// ==== FUN_005ff570 @ 0x005ff570 ====

void FUN_005ff570(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_005ff580 @ 0x005ff580 ====

void FUN_005ff580(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 8 + (uint)*(byte *)(in_ECX + 6) * 2) = param_1;
  *(char *)(in_ECX + 6) = *(char *)(in_ECX + 6) + '\x01';
  return;
}


// ==== FUN_005ff5a0 @ 0x005ff5a0 ====

void FUN_005ff5a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c85b8;
  *(undefined2 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  return;
}


// ==== FUN_005ff5c0 @ 0x005ff5c0 ====

void FUN_005ff5c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ff530();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ff5e0 @ 0x005ff5e0 ====

void FUN_005ff5e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c85d4;
  return;
}


// ==== FUN_005ff5f0 @ 0x005ff5f0 ====

void FUN_005ff5f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c85d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ff610 @ 0x005ff610 ====

void FUN_005ff610(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c85d4;
  return;
}


// ==== FUN_005ff620 @ 0x005ff620 ====

void FUN_005ff620(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = param_1;
  *(undefined1 *)(in_ECX + 6) = 0;
  return;
}


// ==== FUN_005ff630 @ 0x005ff630 ====

void FUN_005ff630(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  return;
}


// ==== FUN_005ff640 @ 0x005ff640 ====

void FUN_005ff640(void)

{
  return;
}


// ==== FUN_005ff650 @ 0x005ff650 ====

int FUN_005ff650(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_005ff660 @ 0x005ff660 ====

void FUN_005ff660(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 6) = param_1;
  return;
}


// ==== FUN_005ff670 @ 0x005ff670 ====

void FUN_005ff670(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00986868;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c85e4;
  FUN_00797a50(in_ECX + 1,0,4);
  ExceptionList = local_c;
  return;
}


// ==== FUN_005ff6c0 @ 0x005ff6c0 ====

void FUN_005ff6c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ff610();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ff6e0 @ 0x005ff6e0 ====

void FUN_005ff6e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c862c;
  return;
}


// ==== FUN_005ff6f0 @ 0x005ff6f0 ====

void FUN_005ff6f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c862c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ff710 @ 0x005ff710 ====

undefined4 FUN_005ff710(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xff0);
}


// ==== FUN_005ff720 @ 0x005ff720 ====

void FUN_005ff720(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xff0) = param_1;
  return;
}


// ==== FUN_005ff730 @ 0x005ff730 ====

int FUN_005ff730(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_005ff740 @ 0x005ff740 ====

undefined1 FUN_005ff740(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x95d);
}


// ==== FUN_005ff750 @ 0x005ff750 ====

undefined1 FUN_005ff750(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x967);
}


// ==== FUN_005ff760 @ 0x005ff760 ====

undefined1 FUN_005ff760(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x970);
}


// ==== FUN_005ff770 @ 0x005ff770 ====

undefined4 FUN_005ff770(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xff4);
}


// ==== FUN_005ff790 @ 0x005ff790 ====

undefined4 FUN_005ff790(ushort *param_1)

{
  int in_ECX;
  
  if ((*param_1 < 0x200) && (param_1[1] < 0x200)) {
    return *(undefined4 *)
            (*(int *)(in_ECX + 0xff0) + 0xc +
            ((uint)param_1[1] * *(int *)(*(int *)(in_ECX + 0xff0) + 4) + (uint)*param_1) * 4);
  }
  return 0;
}


// ==== FUN_005ff7d0 @ 0x005ff7d0 ====

void FUN_005ff7d0(ushort param_1)

{
  int in_ECX;
  
  if (param_1 < 10) {
    param_1 = 10;
  }
  *(ushort *)(in_ECX + 0xd7e) = param_1;
  return;
}


// ==== FUN_005ff7f0 @ 0x005ff7f0 ====

void FUN_005ff7f0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_1 == 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009c8614,
                         s___Map_Flyweight_Provider_cpp_009c85f4,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  *(int *)(in_ECX + 0xff4) = param_1;
  return;
}


// ==== FUN_005ff840 @ 0x005ff840 ====

void FUN_005ff840(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8664;
  FUN_00477450();
  in_ECX[0x3fc] = 0;
  in_ECX[0x3fd] = 0;
  return;
}


// ==== FUN_005ff870 @ 0x005ff870 ====

void FUN_005ff870(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0xff0) == (void *)0x0) {
    return;
  }
  _free(*(void **)(in_ECX + 0xff0));
  return;
}


// ==== FUN_005ff8a0 @ 0x005ff8a0 ====

void FUN_005ff8a0(void)

{
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_00986888;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c8664;
  local_4 = 0;
  if ((void *)in_ECX[0x3fc] == (void *)0x0) {
    *in_ECX = &PTR_FUN_009c862c;
    ExceptionList = pvVar1;
    return;
  }
  _free((void *)in_ECX[0x3fc]);
  return;
}


// ==== FUN_005ff900 @ 0x005ff900 ====

void FUN_005ff900(void)

{
  FUN_005ffb20();
  return;
}


// ==== FUN_005ff910 @ 0x005ff910 ====

void FUN_005ff910(undefined1 *param_1)

{
  char cVar1;
  undefined1 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  uVar2 = 0;
  do {
    cVar1 = param_1[uVar2 + 1];
    in_ECX[uVar2 + 1] = cVar1;
    if (cVar1 == '\0') goto LAB_005ff93a;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  in_ECX[1] = 0;
LAB_005ff93a:
  uVar2 = 0;
  do {
    cVar1 = param_1[uVar2 + 0x101];
    in_ECX[uVar2 + 0x101] = cVar1;
    if (cVar1 == '\0') goto LAB_005ff963;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  in_ECX[0x101] = 0;
LAB_005ff963:
  uVar2 = 0;
  do {
    cVar1 = param_1[uVar2 + 0x201];
    in_ECX[uVar2 + 0x201] = cVar1;
    if (cVar1 == '\0') goto LAB_005ff993;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  in_ECX[0x201] = 0;
LAB_005ff993:
  uVar2 = 0;
  do {
    cVar1 = param_1[uVar2 + 0x301];
    in_ECX[uVar2 + 0x301] = cVar1;
    if (cVar1 == '\0') goto LAB_005ff9c3;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  in_ECX[0x301] = 0;
LAB_005ff9c3:
  *(undefined2 *)(in_ECX + 0x402) = *(undefined2 *)(param_1 + 0x402);
  *(undefined2 *)(in_ECX + 0x404) = *(undefined2 *)(param_1 + 0x404);
  *(undefined2 *)(in_ECX + 0x406) = *(undefined2 *)(param_1 + 0x406);
  in_ECX[0x408] = param_1[0x408];
  in_ECX[0x409] = param_1[0x409];
  in_ECX[0x40a] = param_1[0x40a];
  in_ECX[0x40b] = param_1[0x40b];
  *(undefined2 *)(in_ECX + 0x40c) = *(undefined2 *)(param_1 + 0x40c);
  uVar2 = 0;
  do {
    cVar1 = param_1[uVar2 + 0x40e];
    in_ECX[uVar2 + 0x40e] = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x40);
  in_ECX[0x40e] = 0;
  return;
}


// ==== FUN_005ffa70 @ 0x005ffa70 ====

void FUN_005ffa70(undefined1 *param_1)

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
    if (cVar1 == '\0') goto LAB_005ffa9e;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  in_ECX[2] = 0;
LAB_005ffa9e:
  *(undefined2 *)(in_ECX + 0x102) = *(undefined2 *)(param_1 + 0x102);
  *(undefined2 *)(in_ECX + 0x104) = *(undefined2 *)(param_1 + 0x104);
  *(undefined4 *)(in_ECX + 0x108) = *(undefined4 *)(param_1 + 0x108);
  *(undefined4 *)(in_ECX + 0x10c) = *(undefined4 *)(param_1 + 0x10c);
  *(undefined4 *)(in_ECX + 0x110) = *(undefined4 *)(param_1 + 0x110);
  *(undefined4 *)(in_ECX + 0x114) = *(undefined4 *)(param_1 + 0x114);
  *(undefined4 *)(in_ECX + 0x118) = *(undefined4 *)(param_1 + 0x118);
  *(undefined4 *)(in_ECX + 0x11c) = *(undefined4 *)(param_1 + 0x11c);
  *(undefined4 *)(in_ECX + 0x120) = *(undefined4 *)(param_1 + 0x120);
  in_ECX[0x124] = param_1[0x124];
  return;
}


// ==== FUN_005ffb20 @ 0x005ffb20 ====

void FUN_005ffb20(undefined2 *param_1)

{
  char cVar1;
  uint uVar2;
  undefined2 *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  *in_ECX = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 2);
    *(char *)(uVar2 + 2 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_005ffb4b;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 1) = 0;
LAB_005ffb4b:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x102);
    *(char *)(uVar2 + 0x102 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_005ffb73;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 0x81) = 0;
LAB_005ffb73:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x202);
    *(char *)(uVar2 + 0x202 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_005ffba3;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 0x101) = 0;
LAB_005ffba3:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x302);
    *(char *)(uVar2 + 0x302 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_005ffbd3;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 0x181) = 0;
LAB_005ffbd3:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x402);
    *(char *)(uVar2 + 0x402 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_005ffc03;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 0x201) = 0;
LAB_005ffc03:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x502);
    *(char *)(uVar2 + 0x502 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_005ffc33;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 0x281) = 0;
LAB_005ffc33:
  *(undefined4 *)(in_ECX + 0x302) = *(undefined4 *)(param_1 + 0x302);
  *(undefined4 *)(in_ECX + 0x304) = *(undefined4 *)(param_1 + 0x304);
  *(undefined4 *)(in_ECX + 0x306) = *(undefined4 *)(param_1 + 0x306);
  *(undefined4 *)(in_ECX + 0x308) = *(undefined4 *)(param_1 + 0x308);
  *(undefined4 *)(in_ECX + 0x30a) = *(undefined4 *)(param_1 + 0x30a);
  *(undefined4 *)(in_ECX + 0x30c) = *(undefined4 *)(param_1 + 0x30c);
  *(undefined4 *)(in_ECX + 0x30e) = *(undefined4 *)(param_1 + 0x30e);
  *(undefined4 *)(in_ECX + 0x310) = *(undefined4 *)(param_1 + 0x310);
  *(undefined4 *)(in_ECX + 0x312) = *(undefined4 *)(param_1 + 0x312);
  *(undefined4 *)(in_ECX + 0x314) = *(undefined4 *)(param_1 + 0x314);
  *(undefined4 *)(in_ECX + 0x316) = *(undefined4 *)(param_1 + 0x316);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x630);
    *(char *)(uVar2 + 0x630 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_005ffce3;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 0x318) = 0;
LAB_005ffce3:
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x730);
    *(char *)(uVar2 + 0x730 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_005ffd13;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 0x398) = 0;
LAB_005ffd13:
  *(undefined4 *)(in_ECX + 0x418) = *(undefined4 *)(param_1 + 0x418);
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0x834);
    *(char *)(uVar2 + 0x834 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_005ffd53;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 0x41a) = 0;
LAB_005ffd53:
  puVar4 = (undefined4 *)(param_1 + 0x49a);
  puVar5 = (undefined4 *)(in_ECX + 0x49a);
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  *(undefined4 *)(in_ECX + 0x4a8) = *(undefined4 *)(param_1 + 0x4a8);
  *(undefined4 *)(in_ECX + 0x4aa) = *(undefined4 *)(param_1 + 0x4aa);
  *(undefined1 *)(in_ECX + 0x4ac) = *(undefined1 *)(param_1 + 0x4ac);
  *(undefined1 *)((int)in_ECX + 0x959) = *(undefined1 *)((int)param_1 + 0x959);
  in_ECX[0x4ad] = param_1[0x4ad];
  *(undefined4 *)(in_ECX + 0x4ae) = *(undefined4 *)(param_1 + 0x4ae);
  *(undefined1 *)(in_ECX + 0x4b0) = *(undefined1 *)(param_1 + 0x4b0);
  *(undefined1 *)((int)in_ECX + 0x961) = *(undefined1 *)((int)param_1 + 0x961);
  *(undefined1 *)(in_ECX + 0x4b1) = *(undefined1 *)(param_1 + 0x4b1);
  *(undefined1 *)((int)in_ECX + 0x963) = *(undefined1 *)((int)param_1 + 0x963);
  *(undefined1 *)(in_ECX + 0x4b2) = *(undefined1 *)(param_1 + 0x4b2);
  *(undefined1 *)((int)in_ECX + 0x965) = *(undefined1 *)((int)param_1 + 0x965);
  *(undefined4 *)(in_ECX + 0x4b4) = *(undefined4 *)(param_1 + 0x4b4);
  *(undefined1 *)(in_ECX + 0x4b6) = *(undefined1 *)(param_1 + 0x4b6);
  FUN_005ff910(param_1 + 0x4b7);
  FUN_005ffa70(param_1 + 0x6de);
  *(undefined1 *)(in_ECX + 0x772) = *(undefined1 *)(param_1 + 0x772);
  *(undefined1 *)((int)in_ECX + 0xee5) = *(undefined1 *)((int)param_1 + 0xee5);
  *(undefined1 *)(in_ECX + 0x773) = *(undefined1 *)(param_1 + 0x773);
  *(undefined1 *)((int)in_ECX + 0xee7) = *(undefined1 *)((int)param_1 + 0xee7);
  in_ECX[0x774] = param_1[0x774];
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 0xeea);
    *(char *)(uVar2 + 0xeea + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') {
      return;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x100);
  *(undefined1 *)(in_ECX + 0x775) = 0;
  return;
}


// ==== FUN_005ffec0 @ 0x005ffec0 ====

void FUN_005ffec0(byte param_1)

{
  void *in_ECX;
  
  FUN_005ff8a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ffee0 @ 0x005ffee0 ====

void FUN_005ffee0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8824;
  return;
}


// ==== FUN_005ffef0 @ 0x005ffef0 ====

void FUN_005ffef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c8824;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005fff10 @ 0x005fff10 ====

int FUN_005fff10(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_005fff20 @ 0x005fff20 ====

undefined4 FUN_005fff20(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_005fff30 @ 0x005fff30 ====

undefined4 FUN_005fff30(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_005fff40 @ 0x005fff40 ====

undefined4 FUN_005fff40(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_005fff50 @ 0x005fff50 ====

undefined4 FUN_005fff50(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18);
}


// ==== FUN_005fff60 @ 0x005fff60 ====

undefined4 FUN_005fff60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x20);
}


// ==== FUN_005fff70 @ 0x005fff70 ====

void FUN_005fff70(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 1;
  return;
}


// ==== FUN_005fff80 @ 0x005fff80 ====

void FUN_005fff80(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + -1;
  return;
}


// ==== FUN_005fff90 @ 0x005fff90 ====

void FUN_005fff90(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = 0;
  return;
}


// ==== FUN_005fffa0 @ 0x005fffa0 ====

undefined4 FUN_005fffa0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1c);
}


// ==== FUN_005fffb0 @ 0x005fffb0 ====

void FUN_005fffb0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009868a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c88dc;
  local_4 = 0;
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
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c8824;
  ExceptionList = pvStack_c;
  return;
}


