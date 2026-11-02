// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x750000-0x75ffff

// ==== FUN_00750110 @ 0x00750110 ====

void FUN_00750110(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *in_ECX;
  undefined1 auStack_98 [20];
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  char *pcStack_78;
  undefined1 auStack_60 [20];
  undefined1 auStack_4c [28];
  undefined4 auStack_30 [8];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00993c8f;
  pvStack_c = ExceptionList;
  pcStack_78 = (char *)0x750139;
  ExceptionList = &pvStack_c;
  uVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  pcStack_78 = (char *)0x750146;
  iVar4 = (**(code **)(*DAT_00b5a980 + 0xc))();
  uVar1 = *(undefined4 *)(iVar4 + 0x28);
  pcStack_78 = (char *)0x75015a;
  cVar2 = (**(code **)(*DAT_00b5a9e0 + 0x1c))();
  if (cVar2 != '\0') {
    pcStack_78 = (char *)0x750169;
    piVar5 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
    if (piVar5 != (int *)0x0) {
      pcStack_78 = (char *)0x750177;
      iVar6 = (**(code **)(*piVar5 + 8))();
      if (iVar6 != 0x13) {
        pcStack_78 = (char *)0x750184;
        iVar6 = (**(code **)(*piVar5 + 8))();
        if (iVar6 != 0x14) goto LAB_00750194;
      }
      pcStack_78 = (char *)0x750194;
      (**(code **)(*DAT_00b5a9dc + 0x10))();
    }
  }
LAB_00750194:
  pcStack_78 = (char *)uVar3;
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0:
    uStack_7c = 0x7501b1;
    FUN_00829810();
    uStack_84 = 0x7501bc;
    uStack_80 = uVar3;
    uStack_7c = uVar1;
    cVar2 = FUN_00829740();
    if (cVar2 == '\0') {
      pcStack_78 = s_result_009f18e4;
      uStack_7c = 0x7501d4;
      FUN_00401830();
      pcStack_78 = auStack_60;
      puStack_4 = (undefined1 *)0x0;
      uStack_7c = 0x7501e6;
      FUN_00406880();
      puStack_4 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
      pcStack_78 = (char *)0x7501f6;
      FUN_00446f10();
    }
    uStack_7c = 0x7501ff;
    pcStack_78 = (char *)uVar3;
    FUN_0074fc60();
    pcStack_78 = (char *)0x750207;
    (**(code **)(**(int **)(iVar4 + 0x28) + 0x30))();
    uStack_7c = 0x75020d;
    pcStack_78 = (char *)uVar3;
    FUN_00829310();
    pcStack_78 = (char *)0x75021b;
    (**(code **)(*DAT_00b5a9ec + 8))();
    pcStack_78 = (char *)0x750226;
    (**(code **)(*DAT_00b5a790 + 4))();
    pcStack_78 = (char *)0x750231;
    (**(code **)(*DAT_00b5a790 + 8))();
    pcStack_78 = (char *)0x75023c;
    (**(code **)(*DAT_00b5aef4 + 0x54))();
    pcStack_78 = (undefined *)0x6e0029;
    uStack_7c = 0;
    uStack_80 = 0x75024e;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x750258;
    FUN_00765c50();
    puStack_4 = auStack_98;
    pvStack_c = (void *)0x1;
    FUN_00765c50(auStack_4c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    break;
  case 1:
    pcStack_78 = (undefined *)0x6e002a;
    uStack_7c = 0;
    uStack_80 = 0x7502b2;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x7502bc;
    FUN_00765c50();
    pvStack_c = (void *)0x2;
    goto LAB_0075041d;
  case 2:
    uStack_7c = 0x7502cf;
    FUN_00828ea0();
    pcStack_78 = (char *)0x7502dd;
    (**(code **)(*DAT_00b5a9ec + 8))();
    uStack_7c = 0x7502e5;
    pcStack_78 = (char *)iVar4;
    FUN_0074fc60();
    pcStack_78 = (char *)0x7502f0;
    (**(code **)(*DAT_00b5a790 + 4))();
    pcStack_78 = (char *)0x7502fb;
    (**(code **)(*DAT_00b5a790 + 8))();
    pcStack_78 = (char *)0x750306;
    (**(code **)(*DAT_00b5aef4 + 0x54))();
    pcStack_78 = (undefined *)0x6e002b;
    uStack_7c = 0;
    uStack_80 = 0x750318;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x750322;
    FUN_00765c50();
    pvStack_c = (void *)0x3;
    goto LAB_0075041d;
  case 3:
    pcStack_78 = (char *)0x750336;
    (**(code **)(*in_ECX + 0xc))();
    pcStack_78 = (char *)0x750341;
    (**(code **)(*DAT_00b5aef8 + 4))();
    pcStack_78 = (undefined *)0x6e002c;
    uStack_7c = 0;
    uStack_80 = 0x750353;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x75035d;
    FUN_00765c50();
    puStack_4 = auStack_98;
    pvStack_c = (void *)0x4;
    FUN_00765c50(auStack_4c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    break;
  case 4:
    pcStack_78 = (char *)0x75039b;
    (**(code **)(*in_ECX + 0xc))();
    pcStack_78 = (char *)0x7503a6;
    (**(code **)(*DAT_00b5aef8 + 4))();
    pcStack_78 = (undefined *)0x6e002d;
    uStack_7c = 0;
    uStack_80 = 0x7503b8;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x7503c2;
    FUN_00765c50();
    puStack_4 = auStack_98;
    pvStack_c = (void *)0x5;
    FUN_00765c50(auStack_4c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    break;
  case 5:
    pcStack_78 = &DAT_006e0084;
    uStack_7c = 0;
    uStack_80 = 0x75040b;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x750415;
    FUN_00765c50();
    pvStack_c = (void *)0x6;
LAB_0075041d:
    puStack_4 = auStack_98;
    FUN_00765c50(auStack_4c);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    break;
  case 6:
    pcStack_78 = &DAT_006e0085;
    uStack_7c = 0;
    uStack_80 = 0x750465;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_84 = 0x75046f;
    FUN_00765c50();
    puStack_4 = auStack_98;
    pvStack_c = (void *)0x7;
    FUN_00765c50(auStack_30);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    break;
  default:
    pcStack_78 = (char *)0x7504c6;
    (**(code **)(*DAT_00b5ad1c + 8))();
    pcStack_78 = (char *)0x0;
    uStack_7c = 0x7504d3;
    (**(code **)(*DAT_00b5af2c + 8))();
    ExceptionList = pvStack_10;
    return;
  }
  auStack_30[0] = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00750510 @ 0x00750510 ====

int FUN_00750510(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_retaddr;
  undefined4 local_104 [64];
  int iStack_4;
  
  local_104[0] = 0;
  if (DAT_00b5acd8 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_009f18eb,0);
    return param_1;
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_2);
  if (piVar1 == (int *)0x0) {
    *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
    *(undefined4 *)(unaff_retaddr + 0x14) = 0;
    *(undefined1 *)(unaff_retaddr + 4) = 0;
    FUN_00401740(&DAT_009f18ec,0);
    return unaff_retaddr;
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if (iVar2 == 0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
    piVar1 = (int *)(**(code **)(*piVar1 + 0x24))();
    iVar2 = *piVar1;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uVar3 = (**(code **)(iVar2 + 0x1c))(uVar3);
    FUN_00401830(uVar3);
    return iStack_4;
  }
  FUN_0044a580(local_104,&DAT_009f1918,&DAT_009f18f0);
  FUN_00797b80(local_104);
  FUN_00401830(&DAT_009f1916);
  return unaff_retaddr;
}


// ==== FUN_00750630 @ 0x00750630 ====

void FUN_00750630(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  void *unaff_EBP;
  int unaff_retaddr;
  undefined1 auStack_42 [10];
  uint uStack_38;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  void *pvStack_18;
  uint uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  piVar4 = DAT_00b5a97c;
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993cb1;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5acd4 + 4))(1);
  iVar5 = *(int *)(unaff_retaddr + 0x10);
  puStack_8 = (undefined1 *)0x0;
  iVar2 = (**(code **)(*piVar4 + 0xc))();
  if (iVar2 == iVar5) {
    uVar3 = FUN_00750510(auStack_2c,*(undefined4 *)(unaff_retaddr + 0x14));
    puStack_8._0_1_ = 1;
    FUN_00401660(uVar3,0,0xffffffff);
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    if (0xf < uStack_14) goto LAB_007506f8;
  }
  else {
    uVar3 = FUN_00750510(auStack_2c,iVar5);
    puStack_8._0_1_ = 2;
    FUN_00401660(uVar3,0,0xffffffff);
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    if (0xf < uStack_14) {
LAB_007506f8:
      _free(pvStack_28);
      return;
    }
  }
  cVar1 = (**(code **)(*DAT_00b5a9e0 + 0x1c))();
  if (((cVar1 != '\0') &&
      (piVar4 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))(), piVar4 != (int *)0x0)) &&
     ((iVar5 = (**(code **)(*piVar4 + 8))(), iVar5 == 0x13 ||
      (iVar5 = (**(code **)(*piVar4 + 8))(), iVar5 == 0x14)))) {
    (**(code **)(*DAT_00b5a9dc + 0x10))();
  }
  iVar5 = *DAT_00b5aef4;
  uVar3 = (**(code **)(*DAT_00b5a78c + 0x40))();
  (**(code **)(iVar5 + 0x2c))(uVar3);
  (**(code **)(*DAT_00b5aef8 + 8))(auStack_42 + -10);
  (**(code **)(*DAT_00b5aef8 + 4))();
  (**(code **)(*DAT_00b5aef4 + 0x50))();
  (**(code **)(*DAT_00b5a78c + 0x24))();
  if (uStack_38 < 0x10) {
    ExceptionList = pvStack_18;
    return;
  }
  _free(unaff_EBP);
  return;
}


// ==== FUN_007507c0 @ 0x007507c0 ====

undefined4 FUN_007507c0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  switch(iVar1 + -0x50e0001) {
  case 0:
    FUN_0074fcd0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  default:
    return 0;
  case 2:
    FUN_00750110(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 3:
    FUN_00750630(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 6:
    FUN_0074fa60(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 8:
    FUN_0074fec0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 9:
    FUN_0074fb00(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 10:
    FUN_0074fb70(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0xc:
    FUN_0074fbf0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 0xd:
    FUN_0074fc30(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
}


// ==== FUN_007508d0 @ 0x007508d0 ====

undefined4 FUN_007508d0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_007507c0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00750900 @ 0x00750900 ====

undefined4 FUN_00750900(void)

{
  return 0x70110004;
}


// ==== FUN_00750910 @ 0x00750910 ====

void FUN_00750910(byte param_1)

{
  void *in_ECX;
  
  FUN_0074fcb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00750930 @ 0x00750930 ====

void FUN_00750930(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993be8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f1960;
  in_ECX[6] = 0;
  in_ECX[7] = 0xf;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00750990 @ 0x00750990 ====

undefined4 FUN_00750990(void)

{
  return 0x70110003;
}


// ==== FUN_007509a0 @ 0x007509a0 ====

void FUN_007509a0(byte param_1)

{
  void *in_ECX;
  
  FUN_007509c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007509c0 @ 0x007509c0 ====

void FUN_007509c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1960;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[7] = 0xf;
    in_ECX[6] = 0;
    *(undefined1 *)(in_ECX + 2) = 0;
    *in_ECX = &PTR_FUN_0099cf40;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00750a00 @ 0x00750a00 ====

void FUN_00750a00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1a44;
  return;
}


// ==== FUN_00750a10 @ 0x00750a10 ====

void FUN_00750a10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1a44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00750a30 @ 0x00750a30 ====

undefined1 FUN_00750a30(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_00750a40 @ 0x00750a40 ====

undefined4 FUN_00750a40(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00750a50 @ 0x00750a50 ====

void FUN_00750a50(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_00750a70 @ 0x00750a70 ====

void FUN_00750a70(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f1acc;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00750aa0 @ 0x00750aa0 ====

void FUN_00750aa0(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009f1aa4;
  }
  FUN_00797a20(puVar2);
  *(undefined1 *)(in_ECX + 8) = 1;
  cVar1 = (**(code **)(*DAT_00b5a78c + 0x5c))();
  if (cVar1 == '\x01') {
    (**(code **)(*DAT_00b5a78c + 0x24))();
  }
  (**(code **)(*DAT_00b5a78c + 0x60))(2);
  return;
}


// ==== FUN_00750b00 @ 0x00750b00 ====

void FUN_00750b00(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f1ab8;
  }
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 8) = 0;
  (**(code **)(*DAT_00b5a78c + 0x60))(0);
  return;
}


// ==== FUN_00750b40 @ 0x00750b40 ====

void FUN_00750b40(void)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
                    /* WARNING: Could not recover jumptable at 0x00750b59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*in_ECX + 0xc))();
    return;
  }
  return;
}


// ==== FUN_00750b60 @ 0x00750b60 ====

void FUN_00750b60(void)

{
                    /* WARNING: Could not recover jumptable at 0x00750b68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aef8 + 0x14))();
  return;
}


// ==== FUN_00750b70 @ 0x00750b70 ====

void FUN_00750b70(void)

{
                    /* WARNING: Could not recover jumptable at 0x00750b78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aef8 + 0x18))();
  return;
}


// ==== FUN_00750b80 @ 0x00750b80 ====

void FUN_00750b80(void)

{
                    /* WARNING: Could not recover jumptable at 0x00750b88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aef8 + 0x1c))();
  return;
}


// ==== FUN_00750b90 @ 0x00750b90 ====

void FUN_00750b90(void)

{
                    /* WARNING: Could not recover jumptable at 0x00750b98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aef8 + 0x20))();
  return;
}


// ==== FUN_00750ba0 @ 0x00750ba0 ====

void FUN_00750ba0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00750ba8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aef8 + 0x24))();
  return;
}


// ==== FUN_00750bb0 @ 0x00750bb0 ====

void FUN_00750bb0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00750bb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aef8 + 0x30))();
  return;
}


// ==== FUN_00750bc0 @ 0x00750bc0 ====

void FUN_00750bc0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00750bc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aef8 + 0x34))();
  return;
}


// ==== FUN_00750bd0 @ 0x00750bd0 ====

void FUN_00750bd0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00750bd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aef8 + 0x38))();
  return;
}


// ==== FUN_00750be0 @ 0x00750be0 ====

void FUN_00750be0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00750be8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aef8 + 0x3c))();
  return;
}


// ==== FUN_00750bf0 @ 0x00750bf0 ====

void FUN_00750bf0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00750bf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aef8 + 0x2c))();
  return;
}


// ==== FUN_00750c00 @ 0x00750c00 ====

void FUN_00750c00(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x50e000c;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined1 *)(iVar4 + 0x10) = 0;
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_00750c70 @ 0x00750c70 ====

void FUN_00750c70(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x50e0005;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_00750cd0 @ 0x00750cd0 ====

void FUN_00750cd0(void)

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
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x50e0008;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined4 *)(iVar4 + 0x10) = unaff_retaddr;
    FUN_004d8570(iVar4);
                    /* WARNING: Could not recover jumptable at 0x00750d37. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5af2c + 4))();
    return;
  }
  return;
}


// ==== FUN_00750d40 @ 0x00750d40 ====

void FUN_00750d40(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined2 *unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x50e0006;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined2 *)(iVar4 + 0x10) = *unaff_retaddr;
    *(undefined1 *)(iVar4 + 0x12) = *(undefined1 *)(unaff_retaddr + 1);
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5aef0 + 8))(unaff_retaddr);
                    /* WARNING: Could not recover jumptable at 0x00750dc3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5af2c + 4))(0);
    return;
  }
  return;
}


// ==== FUN_00750dd0 @ 0x00750dd0 ====

void FUN_00750dd0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EDI;
  undefined1 auStack_46 [2];
  uint local_44;
  undefined1 local_40;
  void *pvStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  void *local_30;
  undefined4 local_2c;
  void *local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993cf3;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *puVar1 = &PTR_FUN_009ef7a4;
  local_4 = 1;
  *in_ECX = &PTR_FUN_009f1aec;
  *puVar1 = &PTR_FUN_009f1ae0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(&DAT_009f19aa,0);
  local_4._0_1_ = 2;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = 0;
  FUN_00401740(s_refresh_tradewnd_009f19ac,0x10);
  local_4 = CONCAT31(local_4._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 8))(&local_44,0,&local_28);
  if (0xf < uStack_38) {
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10._0_1_ = 1;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  FUN_00401740(&DAT_009f19c0,0x16);
  local_10._0_1_ = 4;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_trade_ask_009f19d8,9);
  local_10 = CONCAT31(local_10._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,1,auStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c = CONCAT31(uStack_1c._1_3_,1);
  if ((void *)0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aef4 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5aef4 = in_ECX;
  }
  (**(code **)(*DAT_00b5aef8 + 0xc))(puVar1);
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[3] = 0;
  ExceptionList = local_28;
  return;
}


// ==== FUN_00750f80 @ 0x00750f80 ====

void FUN_00750f80(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  undefined4 *local_2c;
  void *local_28;
  undefined1 local_24;
  void *pvStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993d3c;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f1aec;
  *puVar1 = &PTR_FUN_009f1ae0;
  local_4 = 1;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_refresh_tradewnd_009f19e4,0x10);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8._0_1_ = 1;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  pvStack_18 = (void *)0x0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_trade_ask_009f19f8,9);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  if (pvStack_18 < (void *)0x10) {
    DAT_00b5aef4 = 0;
    (**(code **)(*DAT_00b5aef8 + 0x10))(puVar1);
    *puVar1 = &PTR_FUN_009ef7a4;
    *in_ECX = &PTR_FUN_009f1a44;
    ExceptionList = pvStack_18;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_00751090 @ 0x00751090 ====

undefined4 FUN_00751090(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined1 auStack_42 [26];
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00993d4e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_refresh_tradewnd_009f1a04,0x10);
  if (iVar1 != 0) {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_trade_ask_009f1a18,9);
    if (iVar1 != 0) {
      ExceptionList = local_c;
      return 0;
    }
    if (*(int *)(param_1 + 0x28) != 0) {
      if ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c == 1) {
        FUN_00459160(local_28,0);
        local_4 = 0;
        iVar1 = (**(code **)(*DAT_00b5acd8 + 0x10))(local_28);
        if (iVar1 != 0) {
          uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
          iVar4 = FUN_004f2e60(uVar3);
          uVar3 = (**(code **)(*DAT_00b5a97c + 0xc))();
          *(undefined4 *)(iVar4 + 0x10) = uVar3;
          piVar5 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
          iVar6 = (**(code **)(*piVar5 + 0x74))();
          FUN_0047aa30(auStack_42 + -3,&DAT_009f1a24,iVar6 + 0x5c);
          FUN_0047aa00(auStack_42 + -3);
          *(int *)(iVar4 + 0x14) = iVar1;
          FUN_004d8570(iVar4);
        }
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    ExceptionList = local_c;
    return 1;
  }
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    ExceptionList = local_c;
    return 1;
  }
  *puVar2 = &PTR_FUN_009f1acc;
  FUN_00797a20(puVar2);
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00751230 @ 0x00751230 ====

undefined4 FUN_00751230(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_00751090(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00751260 @ 0x00751260 ====

undefined4 FUN_00751260(void)

{
  return 0x70110000;
}


// ==== FUN_00751270 @ 0x00751270 ====

undefined4 FUN_00751270(void)

{
  return 0x70110001;
}


// ==== FUN_00751280 @ 0x00751280 ====

undefined4 FUN_00751280(void)

{
  return 0x70110002;
}


// ==== FUN_00751290 @ 0x00751290 ====

void FUN_00751290(void)

{
  FUN_007512b0();
  return;
}


// ==== FUN_007512a0 @ 0x007512a0 ====

void FUN_007512a0(void)

{
  FUN_00750a70();
  return;
}


// ==== FUN_007512b0 @ 0x007512b0 ====

void FUN_007512b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00750f80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007512d0 @ 0x007512d0 ====

void FUN_007512d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1b8c;
  return;
}


// ==== FUN_007512e0 @ 0x007512e0 ====

void FUN_007512e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1b8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00751320 @ 0x00751320 ====

int FUN_00751320(void)

{
  int in_ECX;
  
  return in_ECX + 0x44;
}


// ==== FUN_00751330 @ 0x00751330 ====

undefined4 FUN_00751330(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x70);
}


// ==== FUN_00751340 @ 0x00751340 ====

undefined1 FUN_00751340(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x74);
}


// ==== FUN_00751350 @ 0x00751350 ====

undefined4 FUN_00751350(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x3c);
}


// ==== FUN_00751360 @ 0x00751360 ====

undefined1 FUN_00751360(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x40);
}


// ==== FUN_00751370 @ 0x00751370 ====

int FUN_00751370(void)

{
  int in_ECX;
  
  return in_ECX + 0x78;
}


// ==== FUN_00751380 @ 0x00751380 ====

int FUN_00751380(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 100) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x68) - *(int *)(in_ECX + 100) >> 3;
}


// ==== FUN_007513a0 @ 0x007513a0 ====

int FUN_007513a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x30) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0x34) - *(int *)(in_ECX + 0x30) >> 3;
}


// ==== FUN_007513c0 @ 0x007513c0 ====

void FUN_007513c0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  undefined4 unaff_EBP;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
  piVar4 = (int *)piVar2[10];
  iVar3 = (**(code **)(*piVar2 + 0x74))();
  pcVar5 = (char *)(iVar3 + 0x5c);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar3 + 0x5c),(int)pcVar5 - (iVar3 + 0x5d));
  (**(code **)(*piVar4 + 0x38))(0);
  (**(code **)(*piVar4 + 0x30))();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x34))();
  (**(code **)(*piVar4 + 8))(0);
  FUN_00401660(unaff_EBP,0,0xffffffff);
  iVar3 = (**(code **)(*DAT_00b5a980 + 0xc))();
  piVar4 = *(int **)(iVar3 + 0x28);
  (**(code **)(*piVar4 + 0x38))(0);
  (**(code **)(*piVar4 + 0x30))();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x34))();
                    /* WARNING: Could not recover jumptable at 0x0075145c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar4 + 8))(0);
  return;
}


// ==== FUN_00751460 @ 0x00751460 ====

void FUN_00751460(uint param_1,undefined1 param_2)

{
  char cVar1;
  int *piVar2;
  ushort *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  char *pcVar6;
  int *piVar7;
  
  piVar7 = *(int **)(in_ECX + 100);
  if (piVar7 != *(int **)(in_ECX + 0x68)) {
    do {
      piVar2 = (int *)*piVar7;
      if ((piVar2 != (int *)0x0) &&
         (puVar3 = (ushort *)(**(code **)(*piVar2 + 0x14))(), *puVar3 == param_1)) {
        iVar4 = (**(code **)(*piVar2 + 0x2c))();
        pcVar6 = (char *)(iVar4 + 0x32);
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        FUN_00401740((char *)(iVar4 + 0x32),(int)pcVar6 - (iVar4 + 0x33));
      }
      piVar7 = piVar7 + 2;
    } while (piVar7 != *(int **)(in_ECX + 0x68));
  }
  puVar5 = operator_new(8);
  if (puVar5 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar5 = &PTR_FUN_009f1bd0;
  *(undefined1 *)(puVar5 + 1) = param_2;
  FUN_00797a20(puVar5);
  return;
}


// ==== FUN_00751500 @ 0x00751500 ====

void FUN_00751500(undefined1 param_1)

{
  undefined1 local_8 [8];
  
  FUN_00752030(local_8,&param_1);
  return;
}


// ==== FUN_00751520 @ 0x00751520 ====

int FUN_00751520(uint param_1)

{
  int in_ECX;
  int extraout_EDX;
  int iVar1;
  uint unaff_ESI;
  
  iVar1 = *(int *)(in_ECX + 100);
  if ((iVar1 == 0) || (unaff_ESI = param_1, (uint)(*(int *)(in_ECX + 0x68) - iVar1 >> 3) <= param_1)
     ) {
    FUN_00751ca0();
    iVar1 = extraout_EDX;
    param_1 = unaff_ESI;
  }
  return iVar1 + param_1 * 8;
}


// ==== FUN_00751550 @ 0x00751550 ====

int FUN_00751550(uint param_1)

{
  int in_ECX;
  int extraout_EDX;
  int iVar1;
  uint unaff_ESI;
  
  iVar1 = *(int *)(in_ECX + 0x30);
  if ((iVar1 == 0) || (unaff_ESI = param_1, (uint)(*(int *)(in_ECX + 0x34) - iVar1 >> 3) <= param_1)
     ) {
    FUN_00751ca0();
    iVar1 = extraout_EDX;
    param_1 = unaff_ESI;
  }
  return iVar1 + param_1 * 8;
}


// ==== FUN_00751580 @ 0x00751580 ====

void FUN_00751580(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993d98;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f1be4;
  DAT_00b5aef8 = 0;
  local_4 = 0;
  if (0xf < (uint)in_ECX[0x24]) {
    _free((void *)in_ECX[0x1f]);
    return;
  }
  in_ECX[0x24] = 0xf;
  in_ECX[0x23] = 0;
  *(undefined1 *)(in_ECX + 0x1f) = 0;
  if ((void *)in_ECX[0x19] != (void *)0x0) {
    _free((void *)in_ECX[0x19]);
    return;
  }
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  if (0xf < (uint)in_ECX[0x17]) {
    _free((void *)in_ECX[0x12]);
    return;
  }
  in_ECX[0x17] = 0xf;
  in_ECX[0x16] = 0;
  *(undefined1 *)(in_ECX + 0x12) = 0;
  if ((void *)in_ECX[0xc] != (void *)0x0) {
    _free((void *)in_ECX[0xc]);
    return;
  }
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  if ((uint)in_ECX[10] < 0x10) {
    in_ECX[10] = 0xf;
    in_ECX[9] = 0;
    *(undefined1 *)(in_ECX + 5) = 0;
    FUN_007520f0(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
    _free((void *)in_ECX[2]);
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_00751690 @ 0x00751690 ====

void FUN_00751690(undefined1 param_1)

{
  FUN_00752400(&param_1);
  return;
}


// ==== FUN_007516a0 @ 0x007516a0 ====

void FUN_007516a0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993dd6;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f1be4;
  iVar1 = FUN_00751a80();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x11) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  in_ECX[0x17] = 0xf;
  in_ECX[0x16] = 0;
  *(undefined1 *)(in_ECX + 0x12) = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  *(undefined1 *)(in_ECX + 0x1d) = 0;
  in_ECX[0x24] = 0xf;
  in_ECX[0x23] = 0;
  *(undefined1 *)(in_ECX + 0x1f) = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aef8 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aef8 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00751770 @ 0x00751770 ====

void FUN_00751770(int *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 unaff_ESI;
  undefined2 uStack_14;
  undefined1 auStack_12 [14];
  
  if (*(void **)(param_2 + 4) != (void *)0x0) {
    _free(*(void **)(param_2 + 4));
    return;
  }
  *(undefined4 *)(param_2 + 4) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + 0xc) = 0;
  iVar2 = (**(code **)(*param_1 + 0x28))();
  if (iVar2 != 0) {
    do {
      uStack_14 = 0;
      auStack_12[0] = 0;
      cVar1 = (**(code **)(*param_1 + 0x18))(iVar2,&uStack_14);
      if (cVar1 != '\0') {
        auStack_12[0] = (undefined1)((uint)unaff_ESI >> 0x10);
        uStack_14 = (undefined2)unaff_ESI;
        iVar2 = *(int *)(param_2 + 4);
        if ((iVar2 == 0) ||
           ((uint)(*(int *)(param_2 + 0xc) - iVar2 >> 3) <=
            (uint)(*(int *)(param_2 + 8) - iVar2 >> 3))) {
          FUN_007521b0(*(undefined4 *)(param_2 + 8),1,auStack_12 + -6);
        }
        else {
          iVar2 = *(int *)(param_2 + 8);
          FUN_00429bc0(iVar2,1,auStack_12 + -6,param_2,unaff_ESI);
          *(int *)(param_2 + 8) = iVar2 + 8;
        }
      }
      iVar2 = (**(code **)(*param_1 + 0x2c))();
    } while (iVar2 != 0);
  }
  return;
}


// ==== FUN_00751860 @ 0x00751860 ====

void FUN_00751860(void)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 uVar6;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  int in_ECX;
  
  iVar7 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = *(int **)(iVar7 + 0x28);
  piVar8 = (int *)(**(code **)(*piVar2 + 0x34))();
  puVar9 = (undefined4 *)(**(code **)(*piVar8 + 4))();
  *(undefined4 *)(in_ECX + 0x3c) = *puVar9;
  FUN_00751770(piVar2,in_ECX + 0x2c);
  uVar6 = (**(code **)(*piVar2 + 0x3c))();
  *(undefined1 *)(in_ECX + 0x40) = uVar6;
  iVar7 = (**(code **)(*DAT_00b5a980 + 0xc))();
  piVar2 = *(int **)(iVar7 + 0x28);
  piVar8 = (int *)(**(code **)(*piVar2 + 0x34))();
  puVar9 = (undefined4 *)(**(code **)(*piVar8 + 4))();
  *(undefined4 *)(in_ECX + 0x70) = *puVar9;
  FUN_00751770(piVar2,in_ECX + 0x60);
  uVar6 = (**(code **)(*piVar2 + 0x3c))();
  *(undefined1 *)(in_ECX + 0x74) = uVar6;
  puVar9 = *(undefined4 **)(in_ECX + 8);
  puVar3 = (undefined4 *)*puVar9;
  while (puVar3 != puVar9) {
    (**(code **)(*(int *)puVar3[3] + 4))();
    if (*(char *)((int)puVar3 + 0x11) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x11) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x11);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x11);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x11);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x11);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_00751930 @ 0x00751930 ====

void FUN_00751930(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x11) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x11) == '\0');
  }
  return;
}


// ==== FUN_00751950 @ 0x00751950 ====

void FUN_00751950(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x11) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x11) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x11);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x11);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x11) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x11) == '\0');
    if (*(char *)((int)piVar4 + 0x11) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_007519b0 @ 0x007519b0 ====

undefined4 FUN_007519b0(void)

{
  return 0x70110005;
}


// ==== FUN_007519c0 @ 0x007519c0 ====

void FUN_007519c0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x11) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x11) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x11);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x11);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x11);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x11);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_00751a10 @ 0x00751a10 ====

void FUN_00751a10(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 2) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *param_1;
      param_3[1] = param_1[1];
    }
    param_3 = param_3 + 2;
  }
  return;
}


// ==== FUN_00751a40 @ 0x00751a40 ====

void FUN_00751a40(void *param_1)

{
  if (*(char *)((int)param_1 + 0x11) == '\0') {
    FUN_00751a40(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00751a80 @ 0x00751a80 ====

void FUN_00751a80(void)

{
  undefined4 *puVar1;
  
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
  return;
}


// ==== FUN_00751ac0 @ 0x00751ac0 ====

void FUN_00751ac0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00993d68;
  local_c = ExceptionList;
  if (0x3ffffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_004671c0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[4] == '\0') {
LAB_00751bb9:
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
      if ((char)piVar6[4] == '\0') goto LAB_00751bb9;
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


// ==== FUN_00751ca0 @ 0x00751ca0 ====

void FUN_00751ca0(void)

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
  puStack_8 = &LAB_00993d68;
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


// ==== FUN_00751d10 @ 0x00751d10 ====

/* WARNING: Removing unreachable block (ram,0x00751e23) */
/* WARNING: Removing unreachable block (ram,0x00751e33) */
/* WARNING: Removing unreachable block (ram,0x00751e3c) */
/* WARNING: Removing unreachable block (ram,0x00751e3f) */
/* WARNING: Removing unreachable block (ram,0x00751e2f) */
/* WARNING: Removing unreachable block (ram,0x00751e4d) */
/* WARNING: Removing unreachable block (ram,0x00751e5a) */
/* WARNING: Removing unreachable block (ram,0x00751e65) */
/* WARNING: Removing unreachable block (ram,0x00751e61) */
/* WARNING: Removing unreachable block (ram,0x00751e55) */
/* WARNING: Removing unreachable block (ram,0x00751e68) */

void FUN_00751d10(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00993d68;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x11) != '\0') {
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
            goto LAB_00751f35;
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
LAB_00751f35:
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


// ==== FUN_00751fc0 @ 0x00751fc0 ====

void FUN_00751fc0(void)

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
  puStack_8 = &LAB_00993d68;
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


// ==== FUN_00752030 @ 0x00752030 ====

void FUN_00752030(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00751ac0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_00751950();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00751ac0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_007520f0 @ 0x007520f0 ====

void FUN_007520f0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00751a40(piVar6[1]);
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
    FUN_00751d10(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_007521b0 @ 0x007521b0 ====

void FUN_007521b0(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  int extraout_ECX;
  int iVar6;
  int iVar7;
  undefined4 local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00993d80;
  local_10 = ExceptionList;
  local_1c = param_3[1];
  local_20 = *param_3;
  iVar3 = *(int *)(in_ECX + 4);
  local_14 = (undefined1 *)((int)register0x00000010 + -0x2c);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0xc) - iVar3 >> 3;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
    }
    ExceptionList = &local_10;
    puVar1 = (undefined1 *)((int)register0x00000010 + -0x2c);
    if (0x1fffffffU - iVar6 < param_2) {
      ExceptionList = &local_10;
      uVar2 = FUN_00751fc0();
      iVar3 = extraout_ECX;
      puVar1 = local_14;
    }
    local_14 = puVar1;
    if (iVar3 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
    }
    if (uVar2 < iVar6 + param_2) {
      if (0x1fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar3 == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - iVar3 >> 3;
      }
      if (uVar2 < iVar6 + param_2) {
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - iVar3 >> 3;
        }
        uVar2 = iVar3 + param_2;
      }
      pvVar4 = operator_new(uVar2 * 8);
      local_8 = 0;
      local_18 = pvVar4;
      iVar3 = FUN_00751a10(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      FUN_00429bc0(iVar3,param_2,&local_20);
      FUN_00751a10(param_1,*(undefined4 *)(in_ECX + 8),iVar3 + param_2 * 8);
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 8 + (int)pvVar4);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar4 + (param_2 + iVar3) * 8);
        *(void **)(in_ECX + 4) = pvVar4;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar6 = *(int *)(in_ECX + 8);
    iVar3 = param_2 * 8;
    if ((uint)(iVar6 - param_1 >> 3) < param_2) {
      FUN_00751a10(param_1,iVar6,iVar3 + param_1);
      local_8 = 2;
      FUN_004b9150(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 3),&local_20);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar3;
      FUN_00686630(param_1,*(int *)(in_ECX + 8) + param_2 * -8,&local_20);
      ExceptionList = local_10;
      return;
    }
    iVar7 = iVar6 + param_2 * -8;
    uVar5 = FUN_00751a10(iVar7,iVar6,iVar6);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_00576790(param_1,iVar7,iVar6);
    FUN_00686630(param_1,iVar3 + param_1,&local_20);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00752321 @ 0x00752321 ====

void Catch_00752321(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00752400 @ 0x00752400 ====

undefined4 FUN_00752400(undefined4 param_1)

{
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_004672b0(&local_8,param_1);
  param_1 = 0;
  FUN_00467250(local_8,local_4,&param_1,0);
  FUN_007520f0(&local_8,local_8,local_4);
  return param_1;
}


// ==== FUN_00752460 @ 0x00752460 ====

void FUN_00752460(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_007520f0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00752490 @ 0x00752490 ====

void FUN_00752490(byte param_1)

{
  void *in_ECX;
  
  FUN_00751580();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007524b0 @ 0x007524b0 ====

void FUN_007524b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1c28;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007524d0 @ 0x007524d0 ====

undefined1 FUN_007524d0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 6);
}


// ==== FUN_007524e0 @ 0x007524e0 ====

void FUN_007524e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1c8c;
  *(undefined2 *)(in_ECX + 1) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5acb8 = (undefined4 *)0x0;
    *(undefined1 *)((int)in_ECX + 6) = 0;
    return;
  }
  DAT_00b5acb8 = in_ECX;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  return;
}


// ==== FUN_00752510 @ 0x00752510 ====

void FUN_00752510(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009bac70;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00752540 @ 0x00752540 ====

void FUN_00752540(undefined2 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = param_1;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f1c78;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00752580 @ 0x00752580 ====

void FUN_00752580(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = 0;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f1c78;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007525b0 @ 0x007525b0 ====

undefined4 FUN_007525b0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if (*(short *)(in_ECX + 4) != 0) {
    uVar1 = (**(code **)(*DAT_00b5acc0 + 0x18))(*(short *)(in_ECX + 4));
  }
  return uVar1;
}


// ==== FUN_007525d0 @ 0x007525d0 ====

void FUN_007525d0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5acb8 = 0;
  *in_ECX = &PTR_FUN_009f1c28;
  return;
}


// ==== FUN_00752610 @ 0x00752610 ====

void FUN_00752610(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f1c50;
  }
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 6) = 1;
  *(undefined2 *)(in_ECX + 4) = 0;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f1c78;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00752670 @ 0x00752670 ====

undefined4 FUN_00752670(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f1c64;
  }
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 6) = 0;
  *(undefined2 *)(in_ECX + 4) = 0;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009f1c78;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_007526d0 @ 0x007526d0 ====

undefined4 FUN_007526d0(int *param_1)

{
  int iVar1;
  undefined2 extraout_var;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x70140005) {
    FUN_00752540(CONCAT22(extraout_var,(short)param_1[1]));
    return 1;
  }
  return 0;
}


// ==== FUN_00752700 @ 0x00752700 ====

void FUN_00752700(undefined1 param_1,void *param_2)

{
  void **ppvVar1;
  int in_stack_00000018;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993de8;
  local_c = ExceptionList;
  local_4 = 0;
  ppvVar1 = &local_c;
  if (in_stack_00000018 != 0) {
    ExceptionList = &local_c;
    FUN_00401660(&param_1,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    ppvVar1 = ExceptionList;
  }
  ExceptionList = ppvVar1;
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00752790 @ 0x00752790 ====

undefined4 FUN_00752790(void)

{
  return 0x70140000;
}


// ==== FUN_007527a0 @ 0x007527a0 ====

undefined4 FUN_007527a0(void)

{
  return 0x70140001;
}


// ==== FUN_007527b0 @ 0x007527b0 ====

undefined4 FUN_007527b0(void)

{
  return 0x70140004;
}


// ==== FUN_007527c0 @ 0x007527c0 ====

void FUN_007527c0(byte param_1)

{
  void *in_ECX;
  
  FUN_007525d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007527e0 @ 0x007527e0 ====

void FUN_007527e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1e48;
  return;
}


// ==== FUN_007527f0 @ 0x007527f0 ====

void FUN_007527f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1e48;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00752820 @ 0x00752820 ====

undefined4 FUN_00752820(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(*DAT_00b5acc0 + 0x18))(*(ushort *)(param_1 + 0x10) >> 4);
  if (iVar2 != 0) {
    iVar1 = *DAT_00b5acc8;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    (**(code **)(iVar1 + 0x40))(iVar2,uVar3);
  }
  return 1;
}


// ==== FUN_00752870 @ 0x00752870 ====

undefined4 FUN_00752870(undefined4 *param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = *param_1;
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5150008;
  *(undefined2 *)((int)pvVar2 + 6) = 0x24;
  iVar3 = FUN_004244d0();
  if (iVar3 == 0) {
    return 0;
  }
  *(ushort *)(iVar3 + 0x10) =
       (ushort)(*(byte *)((int)param_1 + 6) & 0xf) | *(short *)(param_1 + 1) << 4;
  *(undefined4 *)(iVar3 + 0x12) = *(undefined4 *)((int)param_1 + 0xe);
  *(undefined4 *)(iVar3 + 0x16) = *(undefined4 *)((int)param_1 + 0x12);
  *(undefined4 *)(iVar3 + 0x1a) = param_1[2];
  *(undefined2 *)(iVar3 + 0x1e) = *(undefined2 *)(param_1 + 3);
  *(undefined1 *)(iVar3 + 0x20) = *(undefined1 *)((int)param_1 + 7);
  FUN_004d8570(iVar3);
  return 1;
}


// ==== FUN_00752900 @ 0x00752900 ====

undefined4 FUN_00752900(undefined2 *param_1)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5150002;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  iVar2 = FUN_004244d0();
  *(undefined2 *)(iVar2 + 0x10) = *param_1;
  FUN_004d8570(iVar2);
  return 1;
}


// ==== FUN_00752950 @ 0x00752950 ====

void FUN_00752950(void)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = 0;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x515000f;
  *(undefined2 *)((int)pvVar1 + 6) = 0x10;
  uVar2 = FUN_004244d0();
  FUN_004d8570(uVar2);
  return;
}


// ==== FUN_00752990 @ 0x00752990 ====

undefined4 FUN_00752990(int param_1)

{
  byte bVar1;
  ushort uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  ushort *puVar7;
  uint uVar8;
  undefined4 *puVar9;
  
  iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar4 == 0) {
    return 0;
  }
  if (*(int **)(iVar4 + 0x48) != (int *)0x0) {
    piVar5 = (int *)(**(code **)(**(int **)(iVar4 + 0x48) + 0x28))();
    if ((piVar5 != (int *)0x0) && (*(int **)(iVar4 + 0x40) != (int *)0x0)) {
      piVar6 = (int *)(**(code **)(**(int **)(iVar4 + 0x40) + 0x24))();
      if (piVar6 != (int *)0x0) {
        puVar7 = (ushort *)(**(code **)(*piVar5 + 8))();
        uVar2 = *puVar7;
        uVar8 = (**(code **)(*piVar6 + 8))();
        bVar1 = *(byte *)(param_1 + 0x18);
        uVar3 = *(undefined4 *)(param_1 + 0x14);
        puVar9 = operator_new(0x14);
        if (puVar9 == (undefined4 *)0x0) {
          puVar9 = (undefined4 *)0x0;
        }
        else {
          *puVar9 = &PTR_FUN_009f1e68;
        }
        puVar9[1] = uVar2 - 1;
        puVar9[2] = (uVar2 - 1) - (uVar8 & 0xffff);
        puVar9[3] = (uint)bVar1;
        puVar9[4] = uVar3;
        FUN_00797a20(puVar9);
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_00752a40 @ 0x00752a40 ====

undefined4 FUN_00752a40(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_10;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_resetskill_009f1d0c,0xf);
  if (iVar1 != 0) {
    return 0;
  }
  puVar2 = operator_new(0x14);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009f1e68;
  }
  puVar2[1] = local_10;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  FUN_00797a20(puVar2);
  return 1;
}


// ==== FUN_00752ab0 @ 0x00752ab0 ====

undefined4 FUN_00752ab0(void)

{
  undefined4 extraout_EAX;
  int iVar1;
  int *piVar2;
  int unaff_retaddr;
  undefined1 auStack_68 [4];
  undefined1 uStack_64;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 *puStack_50;
  void *pvStack_4c;
  uint *puStack_48;
  undefined4 uStack_44;
  uint uStack_38;
  void *pvStack_34;
  undefined1 uStack_30;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993e08;
  pvStack_c = ExceptionList;
  uStack_44 = 1;
  puStack_48 = (uint *)0x752ad7;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  if (*(char *)(unaff_retaddr + 0x10) == '\0') {
    puStack_48 = (uint *)0x752b79;
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    puStack_48 = (uint *)0x752b81;
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x40) + 0x1c))();
    puStack_48 = &uStack_38;
    pvStack_4c = (void *)0x752b93;
    (**(code **)(*DAT_00b5ad54 + 0x58))();
    puStack_50 = auStack_68 + 0x28;
    uStack_54 = 0x752bb4;
    (**(code **)(*piVar2 + 0xc))();
    uStack_54 = 0x752bbf;
    (**(code **)(*DAT_00b5ad58 + 8))();
  }
  else {
    puStack_48 = (uint *)0x3c001b;
    pvStack_4c = (void *)0x0;
    puStack_50 = (undefined1 *)0x752af9;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_50 = (undefined1 *)0xffffffff;
    uStack_54 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    uStack_5c = 0x752b17;
    FUN_00401660();
    puStack_8 = auStack_68;
    puStack_50 = (undefined1 *)0xf;
    uStack_54 = 0;
    uStack_10 = 0;
    uStack_64 = 0;
    FUN_00401660(&pvStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5acb8 + 0x18))();
    if (0xf < uStack_38) {
      _free(pvStack_4c);
      return extraout_EAX;
    }
  }
  ExceptionList = pvStack_34;
  return 1;
}


// ==== FUN_00752be0 @ 0x00752be0 ====

undefined4 FUN_00752be0(void)

{
  undefined4 extraout_EAX;
  int iVar1;
  int *piVar2;
  int unaff_retaddr;
  undefined1 auStack_68 [4];
  undefined1 uStack_64;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 *puStack_50;
  void *pvStack_4c;
  uint *puStack_48;
  undefined4 uStack_44;
  uint uStack_38;
  void *pvStack_34;
  undefined1 uStack_30;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993e1a;
  pvStack_c = ExceptionList;
  uStack_44 = 1;
  puStack_48 = (uint *)0x752c07;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  if (*(char *)(unaff_retaddr + 0x10) == '\x01') {
    puStack_48 = (uint *)0x3c001c;
    pvStack_4c = (void *)0x0;
    puStack_50 = (undefined1 *)0x752c28;
    uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_50 = (undefined1 *)0xffffffff;
    uStack_54 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    uStack_5c = 0x752c46;
    FUN_00401660();
    puStack_8 = auStack_68;
    puStack_50 = (undefined1 *)0xf;
    uStack_54 = 0;
    uStack_10 = 0;
    uStack_64 = 0;
    FUN_00401660(&pvStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5acb8 + 0x18))();
    if (0xf < uStack_38) {
      _free(pvStack_4c);
      return extraout_EAX;
    }
  }
  else {
    puStack_48 = (uint *)0x752ca8;
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    puStack_48 = (uint *)0x752cb0;
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x40) + 0x1c))();
    puStack_48 = &uStack_38;
    pvStack_4c = (void *)0x752cc2;
    (**(code **)(*DAT_00b5ad54 + 0x58))();
    pvStack_4c = (void *)0x0;
    puStack_50 = auStack_68 + 0x28;
    uStack_54 = 0x752ce0;
    (**(code **)(*piVar2 + 0xc))();
    uStack_54 = 0x752ceb;
    (**(code **)(*DAT_00b5ad58 + 8))();
  }
  ExceptionList = pvStack_34;
  return 1;
}


// ==== FUN_00752d00 @ 0x00752d00 ====

undefined4 FUN_00752d00(int param_1)

{
  char cVar1;
  undefined4 extraout_EAX;
  int iVar2;
  int *piVar3;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 auStack_74 [4];
  undefined1 uStack_70;
  void *pvStack_6c;
  void *pvStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  undefined1 auStack_30 [4];
  undefined4 uStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00993e4c;
  pvStack_c = ExceptionList;
  cVar1 = *(char *)(param_1 + 0x14);
  if (cVar1 == '\0') {
    uStack_54 = 0x3c001f;
    uStack_58 = 0;
    uStack_5c = 0x752d3d;
    ExceptionList = &pvStack_c;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    pvStack_68 = (void *)0x752d5b;
    FUN_00401660();
    puStack_4 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_c = (void *)0x0;
    uStack_70 = 0;
    FUN_00401660(auStack_30 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uStack_2c = 0xffffffff;
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return extraout_EAX;
    }
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    FUN_008298b0(iVar2);
    piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x20) + 0x54))();
    (**(code **)(*piVar3 + 8))(*(undefined4 *)(param_1 + 0x10));
    (**(code **)(*DAT_00b5ad58 + 8))();
    (**(code **)(*DAT_00b5acb8 + 0x14))();
    (**(code **)(*DAT_00b5a790 + 4))();
  }
  else if (cVar1 == '\x03') {
    uStack_54 = 0x6e001b;
    uStack_58 = 0;
    uStack_5c = 0x752e05;
    ExceptionList = &pvStack_c;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    pvStack_68 = (void *)0x752e23;
    FUN_00401660();
    puStack_4 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_c = (void *)0x1;
    uStack_70 = 0;
    FUN_00401660(auStack_30 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return extraout_EAX_00;
    }
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 == '\x02') {
        uStack_54 = 0x3c0021;
        uStack_58 = 0;
        uStack_5c = 0x752f01;
        ExceptionList = &pvStack_c;
        uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_60 = 0x752f0b;
        FUN_00765c50();
        puStack_4 = auStack_74;
        pvStack_c = (void *)0x3;
        FUN_00765c50(auStack_30 + -0x1c);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      }
      else {
        uStack_54 = 0x3c0022;
        uStack_58 = 0;
        uStack_5c = 0x752f44;
        ExceptionList = &pvStack_c;
        uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_60 = 0x752f4e;
        FUN_00765c50();
        puStack_4 = auStack_74;
        pvStack_c = (void *)0x4;
        FUN_00765c50(auStack_30);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uStack_54 = 0x3c0020;
    uStack_58 = 0;
    uStack_5c = 0x752e83;
    ExceptionList = &pvStack_c;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    uStack_60 = 0;
    pvStack_68 = (void *)0x752ea1;
    FUN_00401660();
    puStack_4 = auStack_74;
    uStack_5c = 0xf;
    uStack_60 = 0;
    pvStack_c = (void *)0x2;
    uStack_70 = 0;
    FUN_00401660(auStack_30 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return extraout_EAX_01;
    }
  }
  ExceptionList = (void *)0x0;
  return 1;
}


// ==== FUN_00752fa0 @ 0x00752fa0 ====

void FUN_00752fa0(void)

{
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  undefined1 local_24;
  uint uStack_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993e66;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f1e90;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5acbc = (undefined4 *)0x0;
  }
  else {
    DAT_00b5acbc = in_ECX;
  }
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  FUN_00401740(s_show_resetskill_009f1cec,0xf);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_28,0);
  if (uStack_18 < 0x10) {
    ExceptionList = local_14;
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00753040 @ 0x00753040 ====

void FUN_00753040(void)

{
  undefined4 *in_ECX;
  void *local_28;
  undefined1 local_24;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993e80;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f1e90;
  local_4 = 0;
  DAT_00b5acbc = 0;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(s_show_resetskill_009f1cfc,0xf);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  if (local_14 < 0x10) {
    *in_ECX = &PTR_FUN_009f1e48;
    ExceptionList = local_10;
    return;
  }
  _free(local_28);
  return;
}


// ==== FUN_007530d0 @ 0x007530d0 ====

/* WARNING: Removing unreachable block (ram,0x0075324f) */

undefined4 FUN_007530d0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined4 unaff_ESI;
  undefined4 uVar4;
  undefined1 auStack_8c [4];
  undefined1 uStack_88;
  undefined4 uStack_80;
  void **ppvStack_7c;
  undefined *puStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 *puStack_6c;
  uint uStack_68;
  uint uStack_64;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  void *apvStack_44 [3];
  undefined1 uStack_38;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 uStack_20;
  undefined1 *puStack_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993e9a;
  local_c = ExceptionList;
  if (DAT_00b5a97c == 0) {
    return 0;
  }
  iVar1 = *DAT_00b5acc8;
  uVar4 = CONCAT22((short)((uint)unaff_ESI >> 0x10),*(ushort *)(param_1 + 0x10) >> 4);
  uStack_5c = 0x75312d;
  ExceptionList = &local_c;
  uStack_58 = uVar4;
  uStack_5c = (**(code **)(*DAT_00b5a980 + 8))();
  uStack_60 = 0x753133;
  (**(code **)(iVar1 + 0x18))();
  uStack_64 = 0x75313f;
  uStack_60 = uVar4;
  piVar2 = (int *)(**(code **)(*DAT_00b5acc0 + 0x1c))();
  iVar1 = *DAT_00b5ace8;
  uStack_64 = 0;
  uStack_68 = 0x75314f;
  iVar3 = (**(code **)(*piVar2 + 4))();
  uStack_68 = (uint)*(ushort *)(iVar3 + 0x2bb8);
  puStack_6c = (undefined4 *)0x75315c;
  uStack_74 = (**(code **)(iVar1 + 8))();
  puStack_6c = (undefined4 *)0xffffffff;
  uStack_70 = 0;
  uStack_24 = 0xf;
  uStack_28 = 0;
  uStack_38 = 0;
  puStack_78 = (undefined *)0x75317a;
  FUN_00401660();
  puStack_18 = (undefined1 *)0x0;
  puStack_6c = (undefined4 *)0x753189;
  puStack_6c = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puStack_6c == (undefined4 *)0x0) {
    puStack_6c = (undefined4 *)0x0;
  }
  else {
    *puStack_6c = &PTR_FUN_009f1e7c;
  }
  uStack_70 = 0x75319d;
  FUN_00797a20();
  puStack_6c = (undefined4 *)0x7531ab;
  (**(code **)(*DAT_00b5acb8 + 0x14))();
  puStack_6c = (undefined4 *)0x3c0019;
  uStack_70 = 0;
  uStack_74 = 0x7531bc;
  ppvStack_7c = (void **)(**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_74 = 0xffffffff;
  puStack_78 = (undefined *)0x0;
  uStack_5c = uStack_5c & 0xffffff00;
  uStack_80 = 0x7531d5;
  FUN_00401660();
  uStack_74 = 0xffffffff;
  puStack_78 = (undefined *)0x0;
  ppvStack_7c = apvStack_44;
  uStack_20 = 1;
  uStack_80 = 0x7531eb;
  FUN_00401ff0();
  uStack_74 = 1;
  puStack_78 = &DAT_009f1d1c;
  ppvStack_7c = (void **)0x7531fb;
  FUN_004020e0();
  puStack_18 = auStack_8c;
  uStack_74 = 0xf;
  puStack_78 = (void *)0x0;
  uStack_88 = 0;
  FUN_00401660(&uStack_60,0,0xffffffff);
  (**(code **)(*DAT_00b5acb8 + 0x18))();
  if (uStack_64 < 0x10) {
    ExceptionList = apvStack_44[0];
    return 1;
  }
  _free(puStack_78);
  return extraout_EAX;
}


// ==== FUN_00753280 @ 0x00753280 ====

undefined4 FUN_00753280(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  uint unaff_ESI;
  undefined4 uVar3;
  undefined1 auStack_a8 [4];
  uint uStack_a4;
  void **ppvStack_a0;
  undefined4 uStack_9c;
  undefined *puStack_94;
  uint uStack_90;
  uint uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  void *pvStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  undefined4 uStack_74;
  void *_Memory;
  undefined1 auStack_60 [12];
  undefined1 uStack_54;
  uint uStack_50;
  void *pvStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint uStack_34;
  void *pvStack_30;
  undefined1 uStack_2c;
  undefined1 uStack_20;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  int iStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00993ebc;
  local_c = ExceptionList;
  if (DAT_00b5a97c == 0) {
    return 0;
  }
  if (*(char *)(param_1 + 0x10) == '\0') {
    uVar3 = CONCAT22((short)(unaff_ESI >> 0x10),*(undefined2 *)(param_1 + 0x12));
    iVar2 = *DAT_00b5acc8;
    uStack_78 = 0x753356;
    ExceptionList = &local_c;
    uStack_74 = uVar3;
    uStack_78 = (**(code **)(*DAT_00b5a980 + 8))();
    uStack_7c = 0x75335c;
    (**(code **)(iVar2 + 0x1c))();
    uStack_7c = 0x753367;
    (**(code **)(*DAT_00b5acb8 + 0x14))();
    uStack_7c = 0x753372;
    (**(code **)(*DAT_00b5ad58 + 8))();
    pvStack_80 = (void *)0x75337e;
    uStack_7c = uVar3;
    piVar1 = (int *)(**(code **)(*DAT_00b5acc0 + 0x1c))();
    pvStack_80 = (void *)0x3c001a;
    uStack_84 = 0;
    uStack_88 = 0x753391;
    uStack_90 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_88 = 0xffffffff;
    uStack_8c = 0;
    uStack_40 = 0xf;
    uStack_44 = 0;
    uStack_54 = 0;
    puStack_94 = (undefined *)0x7533af;
    FUN_00401660();
    iStack_10 = *DAT_00b5ace8;
    uStack_88 = 0;
    puStack_18 = (undefined1 *)0x1;
    uStack_8c = 0x7533cb;
    iVar2 = (**(code **)(*piVar1 + 4))();
    uStack_8c = (uint)*(ushort *)(iVar2 + 0x2bb8);
    uStack_90 = 0x7533dc;
    (**(code **)(iStack_10 + 8))();
    uStack_90 = 0xffffffff;
    puStack_94 = (undefined *)0x0;
    _Memory = (void *)0xf;
    uStack_78 = uStack_78 & 0xffffff00;
    uStack_9c = 0x7533f5;
    FUN_00401660();
    uStack_90 = 0xffffffff;
    puStack_94 = (undefined *)0x0;
    uStack_20 = 2;
    uStack_9c = 0x75340b;
    FUN_00401ff0();
    uStack_90 = 1;
    puStack_94 = &DAT_009f1d20;
    FUN_004020e0();
    puStack_18 = auStack_a8;
    uStack_90 = 0xf;
    puStack_94 = (undefined *)0x0;
    uStack_a4 = uStack_a4 & 0xffffff00;
    FUN_00401660(auStack_60,0,0xffffffff);
    (**(code **)(*DAT_00b5acb8 + 0x18))();
    if (0xf < unaff_ESI) {
      uStack_9c = 0x75345d;
      _free(pvStack_80);
      return extraout_EAX;
    }
    pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
    if (uStack_50 < 0x10) {
      ExceptionList = pvStack_30;
      return 1;
    }
  }
  else {
    uStack_74 = 0x3c001e;
    uStack_78 = 0;
    uStack_7c = 0x7532d7;
    ExceptionList = &local_c;
    uStack_84 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_7c = 0xffffffff;
    pvStack_80 = (void *)0x0;
    puStack_18 = (undefined1 *)0xf;
    uStack_1c = 0;
    uStack_2c = 0;
    uStack_88 = 0x7532f5;
    FUN_00401660();
    puStack_4 = (undefined1 *)&puStack_94;
    uStack_9c = 0;
    ppvStack_a0 = &pvStack_30;
    uStack_7c = 0xf;
    pvStack_80 = (void *)0x0;
    local_c = (void *)0x0;
    uStack_90 = uStack_90 & 0xffffff00;
    uStack_a4 = 0x75331e;
    FUN_00401660();
    (**(code **)(*DAT_00b5acb8 + 0x18))();
    if (uStack_34 < 0x10) {
      ExceptionList = pvStack_30;
      return 1;
    }
    _Memory = pvStack_48;
  }
  uStack_9c = 0x75347c;
  _free(_Memory);
  return extraout_EAX_00;
}


// ==== FUN_007534a0 @ 0x007534a0 ====

undefined4 FUN_007534a0(int param_1)

{
  undefined1 uVar1;
  int *piVar2;
  char cVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  float10 fVar8;
  undefined1 auStack_72 [6];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  float fStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00993ee6;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s__________Receive_SN_FORCESTOP_009f1d24,0x1d);
  local_4 = 0;
  FUN_00796d50(local_28);
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  cVar3 = (**(code **)(*DAT_00b5acc0 + 0x2c))();
  piVar2 = DAT_00b5a97c;
  if (cVar3 == '\0') {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24._1_3_ << 8);
    FUN_00401740(&DAT_009f1d44,0x32);
    local_4 = 1;
    FUN_00796d50(local_28);
    if (0xf < local_10) {
      _free(local_24);
      return extraout_EAX_00;
    }
  }
  else if (DAT_00b5a97c == (int *)0x0) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24._1_3_ << 8);
    FUN_00401740(&DAT_009f1d78,0x2a);
    local_4 = 2;
    FUN_00796d50(local_28);
    if (0xf < local_10) {
      _free(local_24);
      return extraout_EAX_01;
    }
  }
  else {
    cVar3 = (**(code **)(*DAT_00b5a97c + 0x14))();
    if (cVar3 == '\x01') {
      FUN_00401830(&DAT_009f1da4);
      local_4 = 3;
      FUN_00796d50(local_28);
      if (0xf < local_10) {
        _free(local_24);
        return extraout_EAX_02;
      }
    }
    else {
      uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      iVar5 = (**(code **)(*DAT_00b5acc4 + 0x1c))();
      uVar1 = *(undefined1 *)(iVar5 + 0x13);
      FUN_00797a50(&uStack_5c,0,0xc);
      uStack_54 = CONCAT13(1,CONCAT12(uVar1,(undefined2)uStack_54));
      uStack_5c = uVar4;
      piVar6 = (int *)(**(code **)(*piVar2 + 8))();
      puVar7 = (undefined4 *)(**(code **)(*piVar6 + 0x28))();
      uStack_6c = *puVar7;
      uStack_68 = puVar7[1];
      piVar6 = (int *)(**(code **)(*piVar2 + 8))();
      puVar7 = (undefined4 *)(**(code **)(*piVar6 + 0x2c))();
      uStack_64 = *puVar7;
      uStack_60 = puVar7[1];
      uStack_50 = uStack_6c;
      uStack_4c = uStack_68;
      fVar8 = (float10)FUN_0040d5f0(&uStack_64);
      fStack_48 = (float)fVar8;
      puVar7 = (undefined4 *)FUN_004ef0e0(auStack_72);
      uStack_58 = *puVar7;
      uStack_54 = CONCAT22(uStack_54._2_2_,*(undefined2 *)(puVar7 + 1));
      uStack_44 = uStack_5c;
      uStack_3c = uStack_54;
      uStack_6c = CONCAT31(uStack_6c._1_3_,*(undefined1 *)(param_1 + 0x10));
      uStack_40 = uStack_58;
      puVar7 = operator_new(0xc);
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        *puVar7 = &PTR_FUN_009b6f50;
      }
      puVar7[1] = uStack_6c;
      puVar7[2] = uVar4;
      FUN_00797a20(puVar7);
      puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        *puVar7 = &PTR_FUN_009b6f3c;
      }
      uVar4 = FUN_004f4d60();
      FUN_00403e60(puVar7 + 1,&uStack_44,uVar4);
      FUN_00797a20(puVar7);
      puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar7 == (undefined4 *)0x0) {
        puVar7 = (undefined4 *)0x0;
      }
      else {
        *puVar7 = &PTR_FUN_009b2d88;
      }
      uVar4 = (**(code **)(*piVar2 + 0xc))();
      puVar7[1] = uVar4;
      FUN_00403e60(puVar7 + 2,&uStack_5c,0x19);
      FUN_00797a20(puVar7);
    }
  }
  ExceptionList = pvStack_c;
  return 1;
}


// ==== FUN_007537b0 @ 0x007537b0 ====

undefined4 FUN_007537b0(undefined4 *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00993ef8;
  local_c = ExceptionList;
  uVar3 = param_1[1];
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = uVar3;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x6040000;
  *(undefined2 *)((int)pvVar1 + 6) = 0x24;
  iVar2 = FUN_004244d0();
  if (iVar2 == 0) {
    ExceptionList = local_c;
    return 0;
  }
  *(undefined4 *)(iVar2 + 0x10) = *param_1;
  *(ushort *)(iVar2 + 0x14) =
       (ushort)(*(byte *)((int)param_1 + 10) & 0xf) | *(short *)(param_1 + 2) << 4;
  *(undefined1 *)(iVar2 + 0x16) = *(undefined1 *)(param_1 + 4);
  *(undefined1 *)(iVar2 + 0x17) = *(undefined1 *)((int)param_1 + 0x11);
  *(undefined1 *)(iVar2 + 0x18) = *(undefined1 *)((int)param_1 + 0x12);
  *(undefined1 *)(iVar2 + 0x19) = *(undefined1 *)((int)param_1 + 0x13);
  *(undefined1 *)(iVar2 + 0x1a) = *(undefined1 *)(param_1 + 5);
  *(undefined1 *)(iVar2 + 0x1b) = *(undefined1 *)((int)param_1 + 0x15);
  *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)((int)param_1 + 0x16);
  *(undefined2 *)(iVar2 + 0x20) = *(undefined2 *)((int)param_1 + 0x1a);
  FUN_00401740(s__SKILLACTION__SENDRESULT__skill___009f1dd0,0x2c);
  uVar3 = FUN_00797530(local_28);
  local_4 = 0;
  FUN_00796d50(uVar3);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_004d8570();
    ExceptionList = local_c;
    return 1;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00753900 @ 0x00753900 ====

undefined4 FUN_00753900(int param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 local_28;
  void *local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00993f0a;
  local_c = ExceptionList;
  uVar3 = *(undefined4 *)(param_1 + 4);
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = uVar3;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x515000a;
  *(undefined2 *)((int)pvVar1 + 6) = 0x1c;
  iVar2 = FUN_004244d0();
  if (iVar2 == 0) {
    ExceptionList = local_c;
    return 0;
  }
  local_28 = *(undefined4 *)(param_1 + 8);
  uVar3 = *(undefined4 *)(param_1 + 0xc);
  local_20 = *(undefined4 *)(param_1 + 0x10);
  local_1c = *(int *)(param_1 + 0x14);
  local_18 = *(undefined4 *)(param_1 + 0x18);
  *(ushort *)(iVar2 + 0x10) =
       (ushort)((byte)((uint)local_1c >> 0x10) & 0xf) | (ushort)(local_1c << 4);
  *(char *)(iVar2 + 0x12) = (char)((uint)local_1c >> 0x18);
  *(char *)(iVar2 + 0x13) = (char)((uint)local_18 >> 0x18);
  *(undefined4 *)(iVar2 + 0x14) = uVar3;
  *(undefined2 *)(iVar2 + 0x18) = (undefined2)local_20;
  FUN_00401740(s__SKILLACTION__SENDMOTION__skill___009f1e00,0x2c);
  uVar3 = FUN_00797530(&local_28);
  local_4 = 0;
  FUN_00796d50(uVar3);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_004d8570();
    ExceptionList = local_c;
    return 1;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00753a50 @ 0x00753a50 ====

undefined4 FUN_00753a50(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_00424500();
  switch(uVar1) {
  case 0x5150001:
    uVar1 = FUN_007530d0(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  default:
    return 0;
  case 0x5150003:
    uVar1 = FUN_00753280(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  case 0x5150005:
    uVar1 = FUN_00752ab0(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  case 0x5150007:
    uVar1 = FUN_00752be0(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  case 0x5150009:
    uVar1 = FUN_00752820(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  case 0x515000d:
    uVar1 = FUN_007534a0(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  case 0x515000e:
    uVar1 = FUN_00752990(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  case 0x5150010:
    uVar1 = FUN_00752d00(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  }
}


// ==== FUN_00753b40 @ 0x00753b40 ====

undefined4 FUN_00753b40(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00753a50(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x70004) {
    cVar1 = FUN_00752a40(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00753b90 @ 0x00753b90 ====

undefined4 FUN_00753b90(void)

{
  return 0x70140007;
}


// ==== FUN_00753ba0 @ 0x00753ba0 ====

undefined4 FUN_00753ba0(void)

{
  return 0x50040009;
}


// ==== FUN_00753bb0 @ 0x00753bb0 ====

void FUN_00753bb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00753040();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00753bd0 @ 0x00753bd0 ====

void FUN_00753bd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1ebc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00753bf0 @ 0x00753bf0 ====

void FUN_00753bf0(int param_1)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x28))();
  if (cVar1 != '\0') {
    in_ECX[0xf] = param_1;
  }
  return;
}


// ==== FUN_00753c10 @ 0x00753c10 ====

undefined4 FUN_00753c10(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x3c) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x3c) + 0x20))();
    if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00753c26. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(*piVar1 + 4))();
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_00753c30 @ 0x00753c30 ====

undefined4 FUN_00753c30(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x3c) == 0) {
    return 1;
  }
  uVar1 = (**(code **)(*DAT_00b5acc8 + 0x20))(*(int *)(in_ECX + 0x3c));
  return uVar1;
}


// ==== FUN_00753c50 @ 0x00753c50 ====

void FUN_00753c50(int *param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  undefined1 local_1c [8];
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  float local_4;
  
  if (*param_1 == 0) {
    iVar1 = (**(code **)(*DAT_00b5a77c + 8))(param_1[1]);
    in_ECX[0x10] = iVar1;
    (**(code **)(*in_ECX + 0x20))(param_1);
    return;
  }
  if (*param_1 == 1) {
    local_c = param_1[3];
    local_8 = param_1[4];
    local_14 = DAT_0099d080;
    local_10 = 0;
    fVar2 = (float10)FUN_0040d5f0(&local_14);
    local_4 = (float)fVar2;
    FUN_004ef0e0(local_1c);
    iVar1 = (**(code **)(*DAT_00b5a77c + 4))(local_1c);
    in_ECX[0x10] = iVar1;
  }
  (**(code **)(*in_ECX + 0x20))(param_1);
  return;
}


// ==== FUN_00753d00 @ 0x00753d00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00753d00(undefined4 *param_1,float param_2,float param_3)

{
  undefined4 uVar1;
  int *piVar2;
  float *pfVar3;
  undefined4 *puVar4;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  pfVar3 = (float *)(**(code **)(*piVar2 + 0x28))();
  fStack_8 = *pfVar3;
  fStack_4 = pfVar3[1];
  puVar4 = (undefined4 *)(**(code **)(*piVar2 + 0x2c))();
  fStack_10 = param_2 - fStack_8;
  uVar1 = puVar4[1];
  fStack_c = param_3 - fStack_4;
  if (_DAT_009f1eb0 < SQRT(fStack_10 * fStack_10 + fStack_c * fStack_c)) {
    thunk_FUN_0079de77();
    *(float **)fStack_4 = &fStack_10;
    *(float **)((int)fStack_4 + 4) = &fStack_10;
    return;
  }
  *param_1 = *puVar4;
  param_1[1] = uVar1;
  return;
}


// ==== FUN_00753da0 @ 0x00753da0 ====

ushort FUN_00753da0(void)

{
  int *piVar1;
  ushort *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x3c) == 0) {
    return 0;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x3c) + 0x18))();
  puVar2 = (ushort *)(**(code **)(*piVar1 + 0xc))();
  return *puVar2 >> 4;
}


// ==== FUN_00753dd0 @ 0x00753dd0 ====

uint FUN_00753dd0(void)

{
  uint in_EAX;
  int *piVar1;
  undefined1 *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x3c) == 0) {
    return in_EAX & 0xffffff00;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x3c) + 0x18))();
  puVar2 = (undefined1 *)(**(code **)(*piVar1 + 0xc))();
  return CONCAT31((int3)((uint)puVar2 >> 8),*puVar2) & 0xffffff0f;
}


// ==== FUN_00753df0 @ 0x00753df0 ====

void FUN_00753df0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x40) + 0x1c))();
                    /* WARNING: Could not recover jumptable at 0x00753e07. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0x10))();
  return;
}


// ==== FUN_00753e10 @ 0x00753e10 ====

void FUN_00753e10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1f04;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  *(undefined1 *)((int)in_ECX + 0x33) = 0;
  in_ECX[0x10] = 0;
  in_ECX[0xf] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[2] = 0;
  in_ECX[1] = 2;
  *(undefined1 *)(in_ECX + 3) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5acc4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5acc4 = in_ECX;
  return;
}


// ==== FUN_00753e90 @ 0x00753e90 ====

void FUN_00753e90(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5acc4 = 0;
  *in_ECX = &PTR_FUN_009f1ebc;
  return;
}


// ==== FUN_00753eb0 @ 0x00753eb0 ====

undefined4 * FUN_00753eb0(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *unaff_retaddr;
  
  if (DAT_00b5acd8 == (int *)0x0) {
    *param_1 = 0;
    param_1[1] = 0;
    return param_1;
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_2);
  if (piVar1 == (int *)0x0) {
    *unaff_retaddr = *(undefined4 *)(in_ECX + 0x10);
    unaff_retaddr[1] = *(undefined4 *)(in_ECX + 0x14);
    return unaff_retaddr;
  }
  puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x28))();
  *unaff_retaddr = *puVar2;
  unaff_retaddr[1] = puVar2[1];
  return unaff_retaddr;
}


// ==== FUN_00753f30 @ 0x00753f30 ====

void FUN_00753f30(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  int iVar3;
  int *piVar4;
  undefined1 local_8 [8];
  
  iVar1 = *param_1;
  if (iVar1 != 2) {
    piVar4 = param_1;
    piVar2 = in_ECX;
    for (iVar3 = 7; piVar2 = piVar2 + 1, iVar3 != 0; iVar3 = iVar3 + -1) {
      *piVar2 = *piVar4;
      piVar4 = piVar4 + 1;
    }
    if (iVar1 == 0) {
      piVar2 = (int *)FUN_00753eb0(local_8,param_1[1]);
      in_ECX[4] = *piVar2;
      in_ECX[5] = piVar2[1];
    }
    piVar2 = (int *)FUN_00753d00(local_8,in_ECX[4],in_ECX[5]);
    in_ECX[6] = *piVar2;
    in_ECX[7] = piVar2[1];
  }
  return;
}


// ==== FUN_00753fa0 @ 0x00753fa0 ====

undefined4 FUN_00753fa0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00b5a97c != 0) {
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar1 != 0) {
                    /* WARNING: Could not recover jumptable at 0x00753fc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(**(int **)(iVar1 + 0x40) + 0x20))();
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_00753fd0 @ 0x00753fd0 ====

undefined2 FUN_00753fd0(void)

{
  undefined2 uVar1;
  int iVar2;
  int *piVar3;
  
  if (DAT_00b5a97c != 0) {
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar2 != 0) {
      piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x40) + 0x24))();
      uVar1 = (**(code **)(*piVar3 + 8))();
      return uVar1;
    }
  }
  return 0;
}


// ==== FUN_00754000 @ 0x00754000 ====

undefined4 FUN_00754000(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x40);
}


// ==== FUN_00754010 @ 0x00754010 ====

void FUN_00754010(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  for (iVar1 = 7; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *in_ECX;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_00754030 @ 0x00754030 ====

void FUN_00754030(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x20);
  for (iVar1 = 7; register0x00000010 = (BADSPACEBASE *)((int)register0x00000010 + 4), iVar1 != 0;
      iVar1 = iVar1 + -1) {
    *puVar2 = *(undefined4 *)register0x00000010;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== FUN_00754050 @ 0x00754050 ====

void FUN_00754050(byte param_1)

{
  void *in_ECX;
  
  FUN_00753e90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00754070 @ 0x00754070 ====

void FUN_00754070(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1f9c;
  return;
}


// ==== FUN_00754080 @ 0x00754080 ====

void FUN_00754080(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1f9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007540a0 @ 0x007540a0 ====

void FUN_007540a0(undefined4 param_1)

{
  undefined1 uVar1;
  int *in_ECX;
  
  if ((char)in_ECX[1] == '\0') {
    uVar1 = (**(code **)(*in_ECX + 0x38))(param_1);
    *(undefined1 *)(in_ECX + 1) = uVar1;
  }
  return;
}


// ==== FUN_007540c0 @ 0x007540c0 ====

bool FUN_007540c0(int param_1)

{
  return param_1 == 3;
}


// ==== FUN_007540d0 @ 0x007540d0 ====

void FUN_007540d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1fec;
  *(undefined1 *)(in_ECX + 1) = 1;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5acc0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5acc0 = in_ECX;
  return;
}


// ==== FUN_00754100 @ 0x00754100 ====

void FUN_00754100(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_2c [5];
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  if ((char)in_ECX[1] == '\0') {
    uStack_14 = param_1;
    uStack_18 = 0x754116;
    (**(code **)(*in_ECX + 0x38))();
  }
  *(undefined1 *)(in_ECX + 1) = 0;
  iVar1 = *DAT_00b5acc4;
  puVar3 = auStack_2c;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  (**(code **)(iVar1 + 0x18))();
  (**(code **)(*in_ECX + 0x38))(param_1);
  return;
}


// ==== FUN_00754150 @ 0x00754150 ====

void FUN_00754150(void)

{
                    /* WARNING: Could not recover jumptable at 0x00754158. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aa30 + 8))();
  return;
}


// ==== FUN_00754160 @ 0x00754160 ====

undefined4 FUN_00754160(uint param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5acc4 + 0x1c))();
  if (param_1 < *(uint *)(iVar1 + 4)) {
    return 0;
  }
  iVar1 = (**(code **)(*DAT_00b5acc4 + 0x2c))();
  if (iVar1 == 2) {
    (**(code **)(*in_ECX + 0x44))();
  }
  return 1;
}


// ==== FUN_007541a0 @ 0x007541a0 ====

void FUN_007541a0(void)

{
  undefined1 *puStack_20;
  undefined1 local_1c [28];
  
  puStack_20 = local_1c;
  (**(code **)(*DAT_00b5acc4 + 0x24))();
  (**(code **)(*DAT_00b5acc4 + 0x20))(&puStack_20);
  return;
}


// ==== FUN_007541d0 @ 0x007541d0 ====

void FUN_007541d0(undefined4 param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  float10 fVar6;
  undefined1 *puStack_58;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 *puStack_48;
  undefined4 uStack_44;
  float fStack_40;
  undefined1 auStack_3c [8];
  undefined4 local_34;
  undefined2 uStack_30;
  undefined1 uStack_2e;
  undefined4 uStack_26;
  undefined4 uStack_22;
  undefined1 auStack_1c [28];
  
  piVar5 = DAT_00b5acc4;
  local_34 = param_1;
  puStack_58 = (undefined1 *)0x7541e9;
  uStack_30 = (**(code **)(*DAT_00b5acc4 + 0x34))();
  puStack_58 = (undefined1 *)0x7541f5;
  uStack_2e = (**(code **)(*piVar5 + 0x38))();
  puStack_58 = (undefined1 *)0x754200;
  piVar2 = (int *)(**(code **)(*piVar5 + 0x14))();
  puStack_58 = (undefined1 *)0x754207;
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 8))();
  uStack_26 = *puVar3;
  uStack_22 = puVar3[1];
  puStack_58 = auStack_1c;
  iVar4 = (**(code **)(*piVar5 + 0x24))();
  local_34 = CONCAT13(*(undefined1 *)(iVar4 + 8),(undefined3)local_34);
  piVar5 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar3 = (undefined4 *)(**(code **)(*piVar5 + 0x28))();
  uVar1 = *puVar3;
  uStack_50 = puVar3[1];
  (**(code **)(*piVar5 + 0x2c))();
  iVar4 = (**(code **)(*DAT_00b5acc4 + 0x24))((int)&uStack_22 + 2);
  uStack_50 = *(undefined4 *)(iVar4 + 0x14);
  uStack_4c = *(undefined4 *)(iVar4 + 0x18);
  puStack_48 = puStack_58;
  uStack_44 = uVar1;
  fVar6 = (float10)FUN_0040d5f0(&uStack_50);
  fStack_40 = (float)fVar6;
  puVar3 = (undefined4 *)FUN_004ef0e0(&puStack_58);
  local_34 = *puVar3;
  uStack_30 = *(undefined2 *)(puVar3 + 1);
  (**(code **)(*DAT_00b5acbc + 0xc))(auStack_3c);
  return;
}


// ==== FUN_007542d0 @ 0x007542d0 ====

void FUN_007542d0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_1c [4];
  undefined1 local_9;
  
  if (*(char *)(in_ECX + 5) == '\x01') {
    local_1c[0] = 0;
    local_1c[1] = 0;
    local_9 = 0;
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5acc4 + 0x1c))();
    puVar3 = local_1c;
    for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
    (**(code **)(*DAT_00b5acbc + 0x14))(local_1c);
    *(undefined1 *)(in_ECX + 5) = 2;
  }
  return;
}


// ==== FUN_00754320 @ 0x00754320 ====

void FUN_00754320(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int in_ECX;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_14 = param_2;
  local_10 = param_3;
  local_18 = param_1;
  local_8 = param_5;
  local_4 = param_6;
  local_c = param_4;
  (**(code **)(*DAT_00b5acbc + 0x10))(local_1c);
  *(undefined1 *)(in_ECX + 5) = 1;
  return;
}


// ==== FUN_00754380 @ 0x00754380 ====

void FUN_00754380(undefined2 param_1)

{
  (**(code **)(*DAT_00b5acbc + 0x18))(&param_1);
  return;
}


// ==== FUN_007543a0 @ 0x007543a0 ====

undefined4 FUN_007543a0(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5acc4 + 0x2c))();
  if ((iVar1 == 2) || (iVar1 == 1)) {
    return 1;
  }
  return 0;
}


// ==== FUN_00754400 @ 0x00754400 ====

void FUN_00754400(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00993f2b;
  local_c = ExceptionList;
  if (DAT_00b5acb4 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(4);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_0078dd70(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00754460 @ 0x00754460 ====

void FUN_00754460(void)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acc4 + 0x3c))();
                    /* WARNING: Could not recover jumptable at 0x0075446f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x18))();
  return;
}


// ==== FUN_00754480 @ 0x00754480 ====

void FUN_00754480(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993f3d;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f1fec;
  local_4 = 0;
  if (DAT_00b5acb4 != (int *)0x0) {
    (**(code **)(*DAT_00b5acb4 + 0xc))();
  }
  DAT_00b5acc0 = 0;
  *in_ECX = &PTR_FUN_009f1f9c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_007544f0 @ 0x007544f0 ====

void FUN_007544f0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  undefined1 auStack_6c [20];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_30 [36];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00993f67;
  pvStack_c = ExceptionList;
  uStack_4c = 0x75450e;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*in_ECX + 0x2c))();
  if (cVar1 == '\0') {
switchD_0075453d_default:
    ExceptionList = pvStack_c;
    return;
  }
  uStack_4c = 0x754521;
  piVar2 = (int *)(**(code **)(*DAT_00b5acc4 + 0x3c))();
  uStack_4c = *(undefined4 *)(param_1 + 8);
  uStack_50 = 0x754530;
  (**(code **)(*piVar2 + 0x2c))();
  switch(*(undefined1 *)(param_1 + 4)) {
  case 0:
    uStack_4c = 0x3c000f;
    uStack_50 = 0;
    uStack_54 = 0x754556;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x754560;
    FUN_00765c50();
    pvStack_c = (void *)0x0;
    break;
  case 1:
    uStack_4c = 0x3c0010;
    uStack_50 = 0;
    uStack_54 = 0x75457c;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x754586;
    FUN_00765c50();
    puStack_4 = auStack_6c;
    pvStack_c = (void *)0x1;
    FUN_00765c50(&uStack_4c);
    (**(code **)(*DAT_00b5acb8 + 0x18))();
    goto LAB_00754643;
  case 2:
    uStack_4c = 0x3c0011;
    uStack_50 = 0;
    uStack_54 = 0x7545c7;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x7545d1;
    FUN_00765c50();
    pvStack_c = (void *)0x2;
    break;
  case 3:
    uStack_4c = 0x3c0012;
    uStack_50 = 0;
    uStack_54 = 0x75460f;
    uStack_54 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0x754619;
    FUN_00765c50();
    puStack_4 = auStack_6c;
    pvStack_c = (void *)0x3;
    FUN_00765c50(auStack_30);
    (**(code **)(*DAT_00b5acb8 + 0x18))();
    goto LAB_00754643;
  default:
    goto switchD_0075453d_default;
  }
  puStack_4 = auStack_6c;
  FUN_00765c50(&uStack_4c);
  (**(code **)(*DAT_00b5acb8 + 0x18))();
LAB_00754643:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00754670 @ 0x00754670 ====

undefined4 FUN_00754670(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined1 auStack_8c [20];
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined1 auStack_44 [36];
  void *pvStack_20;
  undefined1 *puStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993f99;
  pvStack_c = ExceptionList;
  uStack_58 = 0x754697;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5a97c + 0x14))();
  if ((cVar1 != '\x01') && (param_1 != 0)) {
    uStack_58 = 0x7546ae;
    cVar1 = (**(code **)(*DAT_00b5acc4 + 0x28))();
    if (cVar1 != '\0') {
      uStack_58 = 0x7546d7;
      uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      uStack_58 = 0x7546e4;
      iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
      if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        uStack_58 = 0x7546f4;
        piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
      }
      uStack_5c = 0x7546fc;
      uStack_58 = uVar2;
      (**(code **)(*piVar4 + 8))();
      uStack_5c = 0x754707;
      iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
      uStack_60 = 0x754710;
      uStack_5c = uVar2;
      (**(code **)(**(int **)(iVar3 + 0x50) + 0x20))();
      iVar3 = *DAT_00b5acc8;
      iStack_64 = param_1;
      uStack_68 = 0x754725;
      uStack_60 = uVar2;
      uStack_68 = (**(code **)(*DAT_00b5a980 + 8))();
      uStack_6c = 0x75472b;
      uVar2 = (**(code **)(iVar3 + 4))();
      switch(uVar2) {
      case 1:
        uStack_6c = 0x3c0014;
        uStack_70 = 0;
        uStack_74 = 0x754759;
        uStack_74 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_78 = 0x754763;
        FUN_00765c50();
        puStack_18 = auStack_8c;
        pvStack_20 = (void *)0x0;
        FUN_00765c50(&uStack_60);
        (**(code **)(*DAT_00b5acb8 + 0x18))();
        FUN_004dd240(0x16,3,0,0,0);
        break;
      case 2:
        uStack_6c = 0x3c0015;
        uStack_70 = 0;
        uStack_74 = 0x7547b6;
        uStack_74 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_78 = 0x7547c0;
        FUN_00765c50();
        puStack_18 = auStack_8c;
        pvStack_20 = (void *)0x1;
        FUN_00765c50(&uStack_60);
        (**(code **)(*DAT_00b5acb8 + 0x18))();
        break;
      case 3:
        uStack_6c = 0x3c0016;
        uStack_70 = 0;
        uStack_74 = 0x754801;
        uStack_74 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_78 = 0x75480b;
        FUN_00765c50();
        puStack_18 = auStack_8c;
        pvStack_20 = (void *)0x2;
        FUN_00765c50(&uStack_60);
        (**(code **)(*DAT_00b5acb8 + 0x18))();
        break;
      default:
        ExceptionList = pvStack_20;
        return uVar2;
      case 7:
        uStack_6c = 0x3c0017;
        uStack_70 = 0;
        uStack_74 = 0x75484c;
        uStack_74 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_78 = 0x754856;
        FUN_00765c50();
        puStack_18 = auStack_8c;
        pvStack_20 = (void *)0x3;
        FUN_00765c50(&uStack_60);
        (**(code **)(*DAT_00b5acb8 + 0x18))();
        FUN_004dd240(0x16,5,0,0,0);
        break;
      case 0xb:
        uStack_6c = 0x7d50017;
        uStack_70 = 0;
        uStack_74 = 0x7548a6;
        uStack_74 = (**(code **)(*DAT_00b5a794 + 0xc))();
        uStack_78 = 0x7548b0;
        FUN_00765c50();
        puStack_18 = auStack_8c;
        pvStack_20 = (void *)0x4;
        FUN_00765c50(auStack_44);
        (**(code **)(*DAT_00b5acb8 + 0x18))();
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  ExceptionList = pvStack_c;
  return 0xc;
}


// ==== FUN_00754920 @ 0x00754920 ====

undefined4 FUN_00754920(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  
  if (DAT_00b5a97c == 0) {
    return 0;
  }
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    (**(code **)(*in_ECX + 0x34))(param_1[3]);
    piVar2 = (int *)(**(code **)(*DAT_00b5acc4 + 0x3c))();
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x28))(param_1[3]);
    }
  }
  else if (iVar1 == 0x70140006) {
    FUN_007544f0(param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_00754990 @ 0x00754990 ====

void FUN_00754990(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *unaff_ESI;
  undefined1 auStack_9c [4];
  undefined1 uStack_98;
  undefined4 uStack_90;
  undefined4 *puStack_8c;
  undefined *puStack_88;
  undefined1 *puStack_84;
  uint uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  uint uStack_58;
  undefined4 uStack_54;
  void *pvStack_50;
  undefined4 uStack_40;
  uint uStack_3c;
  void *pvStack_38;
  undefined1 auStack_30 [4];
  undefined1 uStack_2c;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  int *piStack_4;
  
  piStack_4 = (int *)0xffffffff;
  puStack_8 = &LAB_00993fbb;
  puStack_c = ExceptionList;
  uStack_74 = 0x3c0018;
  uStack_78 = 0;
  uStack_7c = 0x7549bf;
  ExceptionList = &puStack_c;
  puStack_84 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_7c = 0xffffffff;
  uStack_80 = 0;
  uStack_18 = 0xf;
  uStack_1c = 0;
  uStack_2c = 0;
  puStack_88 = (undefined *)0x7549dd;
  FUN_00401660();
  uStack_7c = 0xffffffff;
  uStack_80 = 0;
  puStack_84 = auStack_30;
  puStack_c = (undefined1 *)0x0;
  pvStack_50 = (void *)0xf;
  uStack_54 = 0;
  puStack_88 = (undefined *)0x7549fe;
  FUN_00401660();
  puStack_c = (undefined1 *)CONCAT31(puStack_c._1_3_,1);
  uStack_7c = 0x754a0c;
  piVar2 = (int *)(**(code **)(*piStack_4 + 0x10))();
  iVar1 = *DAT_00b5ace8;
  uStack_7c = 0;
  uStack_80 = 0x754a1c;
  iVar3 = (**(code **)(*piVar2 + 4))();
  uStack_80 = (uint)*(ushort *)(iVar3 + 0x2bb8);
  puStack_84 = (undefined1 *)0x754a29;
  puStack_8c = (undefined4 *)(**(code **)(iVar1 + 8))();
  puStack_84 = (undefined1 *)0xffffffff;
  puStack_88 = (undefined *)0x0;
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  uStack_90 = 0x754a42;
  FUN_00401660();
  puStack_84 = (undefined1 *)0xffffffff;
  puStack_88 = (undefined *)0x0;
  puStack_8c = &uStack_54;
  uStack_14 = 2;
  uStack_90 = 0x754a58;
  FUN_00401ff0();
  puStack_84 = (undefined1 *)0x1;
  puStack_88 = &DAT_009f1f80;
  puStack_8c = (undefined4 *)0x754a68;
  FUN_004020e0();
  puStack_c = auStack_9c;
  puStack_84 = (undefined1 *)0xf;
  puStack_88 = (void *)0x0;
  uStack_98 = 0;
  FUN_00401660(auStack_9c + 0x2c,0,0xffffffff);
  (**(code **)(*DAT_00b5acb8 + 0x18))();
  if (0xf < uStack_58) {
    _free(unaff_ESI);
    return;
  }
  if (0xf < uStack_74) {
    _free(puStack_88);
    return;
  }
  uStack_74 = 0xf;
  uStack_78 = 0;
  puStack_88 = (undefined *)((uint)puStack_88 & 0xffffff00);
  if (uStack_3c < 0x10) {
    ExceptionList = pvStack_38;
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_00754b00 @ 0x00754b00 ====

void FUN_00754b00(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int *in_ECX;
  undefined4 unaff_retaddr;
  
  (**(code **)(*DAT_00b5acc4 + 8))(param_2);
  (**(code **)(*DAT_00b5acc4 + 0x10))(unaff_retaddr);
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(*in_ECX + 0x3c))(uVar2);
  if (param_2 != (int *)0x0) {
    iVar1 = *param_2;
    uVar3 = (**(code **)(*DAT_00b5acc4 + 0x14))();
    (**(code **)(iVar1 + 0x28))(uVar2,uVar3);
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5acc4 + 0x3c))();
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x28))(uVar2);
  }
  FUN_00754990(param_2);
  return;
}


// ==== FUN_00754b80 @ 0x00754b80 ====

void FUN_00754b80(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00754b90 @ 0x00754b90 ====

void FUN_00754b90(byte param_1)

{
  void *in_ECX;
  
  FUN_00754480();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00754bb0 @ 0x00754bb0 ====

void FUN_00754bb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f21f4;
  return;
}


// ==== FUN_00754bc0 @ 0x00754bc0 ====

void FUN_00754bc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f21f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00754be0 @ 0x00754be0 ====

void FUN_00754be0(undefined2 param_1,undefined1 param_2)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = param_1;
  *(undefined1 *)(in_ECX + 6) = param_2;
  return;
}


// ==== FUN_00754c00 @ 0x00754c00 ====

void FUN_00754c00(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00754c90 @ 0x00754c90 ====

undefined4 FUN_00754c90(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_storewnd_009f20b4,0xd);
  if (iVar1 == 0) {
    puVar2 = operator_new(4);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009f2208;
      FUN_00797a20(puVar2);
      return 1;
    }
  }
  else {
    iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_storewnd_009f20c4,0xd);
    if (iVar1 != 0) {
      return 0;
    }
    puVar2 = operator_new(4);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = &PTR_FUN_009f221c;
      FUN_00797a20(puVar2);
      return 1;
    }
  }
  FUN_00797a20(0);
  return 1;
}


// ==== FUN_00754d30 @ 0x00754d30 ====

void FUN_00754d30(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EDI;
  undefined1 auStack_46 [2];
  uint local_44;
  undefined1 local_40;
  void *pvStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  void *local_30;
  undefined4 local_2c;
  uint local_28;
  void *local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993ff8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f2230;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_009f2072,0);
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = 0;
  FUN_00401740(s_show_storewnd_009f2074,0xd);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 8))(&local_44,0,&local_28);
  if (0xf < uStack_38) {
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  FUN_00401740(&DAT_009f2082,0);
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_storewnd_009f2084,0xd);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,auStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b124 = (undefined4 *)0x0;
    ExceptionList = local_24;
    return;
  }
  DAT_00b5b124 = in_ECX;
  ExceptionList = local_24;
  return;
}


// ==== FUN_00754ec0 @ 0x00754ec0 ====

void FUN_00754ec0(void)

{
  undefined4 *in_ECX;
  undefined4 *local_2c;
  void *local_28;
  undefined1 local_24;
  uint uStack_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099401a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f2230;
  local_4 = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_storewnd_009f2094,0xd);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = (void *)0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_storewnd_009f20a4,0xd);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  if (uStack_18 < 0x10) {
    DAT_00b5b124 = 0;
    *in_ECX = &PTR_FUN_009f21f4;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_00754fa0 @ 0x00754fa0 ====

undefined4 FUN_00754fa0(int param_1)

{
  undefined4 extraout_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  void *unaff_EDI;
  undefined1 auStack_74 [4];
  undefined1 uStack_70;
  undefined4 uStack_68;
  undefined1 auStack_42 [2];
  void *local_40;
  uint uStack_3c;
  void *pvStack_34;
  undefined4 local_30;
  uint local_2c;
  uint uStack_20;
  void *pvStack_1c;
  undefined4 uStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00994044;
  pvStack_c = ExceptionList;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = (undefined1 *)0x0;
  FUN_00796d50();
  local_4 = (undefined1 *)0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX;
  }
  if (*(char *)(param_1 + 0x16) == '\0') {
    (**(code **)(*DAT_00b5b120 + 4))();
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009f2208;
    }
    FUN_00797a20();
    (**(code **)(*DAT_00b5a78c + 0x60))();
    (**(code **)(*DAT_00b5a78c + 0x20))();
    iVar2 = (**(code **)(*DAT_00b5adc4 + 8))();
    if (iVar2 != 0) {
      (**(code **)(*DAT_00b5adc4 + 0x1c))();
    }
    (**(code **)(*DAT_00b5acd4 + 4))();
  }
  else if (*(char *)(param_1 + 0x16) == '\x01') {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_68 = 0x7550c1;
    FUN_00401660();
    local_4 = auStack_74;
    pvStack_c = (void *)0x1;
    uStack_70 = 0;
    FUN_00401660(auStack_42 + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_3c) goto LAB_007551b0;
  }
  else {
    FUN_00401830();
    local_4 = (undefined1 *)0x3;
    FUN_00796d50();
    local_4 = (undefined1 *)0xffffffff;
    if (0xf < local_2c) {
      _free(local_40);
      return extraout_EAX_00;
    }
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_18 = 0xf;
    pvStack_1c = (void *)0x0;
    local_2c = local_2c & 0xffffff00;
    uStack_68 = 0x755171;
    FUN_00401660();
    local_4 = auStack_74;
    pvStack_c = (void *)0x4;
    uStack_70 = 0;
    FUN_00401660(&local_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_20) {
      unaff_EDI = pvStack_34;
LAB_007551b0:
      uStack_68 = 0x7551b5;
      _free(unaff_EDI);
      return extraout_EAX_01;
    }
  }
  ExceptionList = pvStack_1c;
  return 1;
}


// ==== FUN_007551d0 @ 0x007551d0 ====

/* WARNING: Removing unreachable block (ram,0x00755427) */
/* WARNING: Removing unreachable block (ram,0x00755233) */

undefined4 FUN_007551d0(void)

{
  code *pcVar1;
  char cVar2;
  undefined4 extraout_EAX;
  int *piVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX_00;
  void *unaff_ESI;
  int unaff_retaddr;
  undefined1 auStack_7c [4];
  undefined1 uStack_78;
  undefined4 uStack_70;
  char *pcStack_6c;
  uint uVar5;
  uint uStack_3c;
  void *pvStack_38;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994076;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  FUN_00796d50();
  local_4 = 0xffffffff;
  uVar5 = 0;
  (**(code **)(*DAT_00b5af2c + 8))();
  cVar2 = *(char *)(unaff_retaddr + 0x14);
  if (cVar2 != '\0') {
    puStack_8 = (undefined1 *)0x1;
    if (cVar2 == '\x03') {
      pcStack_6c = (char *)(**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_70 = 0x755293;
      FUN_00401660();
      puStack_8 = auStack_7c;
      uStack_78 = 0;
      FUN_00401660(auStack_7c + 0x2c,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      FUN_004dd240(0x16,1,0,0,0);
    }
    else if (cVar2 == '\x02') {
      pcStack_6c = (char *)(**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_70 = 0x7552f0;
      FUN_00401660();
      puStack_8 = auStack_7c;
      uStack_78 = 0;
      FUN_00401660(auStack_7c + 0x2c,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      FUN_004dd240(0x16,4,0,0,0);
    }
    else if (cVar2 == '\b') {
      pcStack_6c = (char *)(**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_70 = 0x75534a;
      FUN_00401660();
      puStack_8 = auStack_7c;
      FUN_00765c50(auStack_7c + 0x2c);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    }
    else {
      pcStack_6c = (char *)(**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_70 = 0x755384;
      FUN_00401660();
      puStack_8 = auStack_7c;
      FUN_00765c50(auStack_7c + 0x2c);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    }
    if (uVar5 < 0x10) {
      ExceptionList = pvStack_38;
      return 1;
    }
    _free(pcStack_6c);
    return extraout_EAX;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
  cVar2 = (**(code **)(*piVar3 + 8))();
  if (cVar2 == '\0') {
    pcStack_6c = s_Shop__NetHandler_SA_BUY_item_ope_009f2110;
    uStack_3c = 0xf;
    unaff_ESI = (void *)((uint)unaff_ESI & 0xffffff00);
    uStack_70 = 0x755403;
    FUN_00401740();
    pcStack_6c = (char *)0x755415;
    FUN_00796d50();
  }
  uVar4 = (**(code **)(*DAT_00b5a980 + 8))();
  if (pvStack_c == (void *)0x0) {
    uStack_70 = 0x755450;
    pcStack_6c = (char *)uVar4;
    cVar2 = FUN_00829a00();
    if (cVar2 == '\0') {
      pcStack_6c = (char *)0x755465;
      FUN_00401830();
      pcStack_6c = (char *)0x755477;
      FUN_00406880();
      if (uStack_3c < 0x10) {
        pcVar1 = (code *)swi(3);
        uVar4 = (*pcVar1)();
        return uVar4;
      }
      pcStack_6c = (char *)0x755493;
      _free(unaff_ESI);
      return extraout_EAX_00;
    }
  }
  else {
    if (pvStack_c != (void *)0x1) goto LAB_007554f2;
    uStack_70 = 0x7554a9;
    pcStack_6c = (char *)uVar4;
    cVar2 = FUN_00829990();
    if (cVar2 == '\0') {
      pcStack_6c = (char *)0x7554be;
      FUN_00401830();
      pcStack_6c = (char *)0x7554d0;
      FUN_00406880();
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  uStack_70 = 0x7554ef;
  pcStack_6c = (char *)uVar4;
  FUN_00829930();
LAB_007554f2:
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5a790 + 8))();
  (**(code **)(*DAT_00b5ad1c + 8))();
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  ExceptionList = pvStack_38;
  return 1;
}


// ==== FUN_00755540 @ 0x00755540 ====

/* WARNING: Removing unreachable block (ram,0x007557bf) */
/* WARNING: Removing unreachable block (ram,0x0075582b) */
/* WARNING: Removing unreachable block (ram,0x007555a3) */

undefined4 FUN_00755540(void)

{
  code *pcVar1;
  char cVar2;
  byte bVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  int *piVar5;
  uint unaff_EDI;
  int unaff_retaddr;
  undefined1 auStack_80 [4];
  undefined1 uStack_7c;
  undefined4 uStack_74;
  undefined4 uStack_70;
  void *pvStack_6c;
  int iStack_68;
  char *pcStack_64;
  undefined1 auStack_46 [14];
  void *pvStack_38;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009940a0;
  pvStack_c = ExceptionList;
  pcStack_64 = (char *)0x75557f;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  FUN_00796d50();
  local_4 = 0xffffffff;
  (**(code **)(*DAT_00b5af2c + 8))();
  cVar2 = *(char *)(unaff_retaddr + 0x14);
  if (cVar2 == '\0') {
    uVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    iStack_68 = 0x755749;
    pcStack_64 = (char *)uVar4;
    FUN_00829930();
    bVar3 = 0;
    if (*(char *)(unaff_retaddr + 0x3a) != '\0') {
      do {
        pcStack_64 = (char *)0x1;
        iStack_68 = 0x75576e;
        piVar5 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
        iStack_68 = unaff_retaddr + 0x16;
        pvStack_6c = (void *)0x75577b;
        cVar2 = (**(code **)(*piVar5 + 8))();
        if (cVar2 == '\0') {
          pcStack_64 = s_openResult_009f2160;
          iStack_68 = 0x75579b;
          FUN_00401740();
          puStack_8 = (undefined1 *)0x2;
          pcStack_64 = (char *)0x7557ad;
          FUN_00406880();
          puStack_8 = (undefined1 *)0xffffffff;
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
        iStack_68 = 0x7557e4;
        pcStack_64 = (char *)uVar4;
        cVar2 = FUN_00829990();
        if (cVar2 == '\0') {
          pcStack_64 = s_buyResult_009f216c;
          iStack_68 = 0x755807;
          FUN_00401740();
          puStack_8 = (undefined1 *)0x3;
          pcStack_64 = (char *)0x755819;
          FUN_00406880();
          puStack_8 = (undefined1 *)0xffffffff;
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
        bVar3 = bVar3 + 1;
      } while (bVar3 < *(byte *)(unaff_retaddr + 0x3a));
    }
    (**(code **)(*DAT_00b5a790 + 4))();
    (**(code **)(*DAT_00b5ad1c + 8))();
    (**(code **)(*DAT_00b5ad58 + 0xc))();
  }
  else {
    puStack_8 = (undefined1 *)0x1;
    if (cVar2 == '\x02') {
      pcStack_64 = (char *)0x0;
      iStack_68 = 0x7555f6;
      uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
      iStack_68 = 0xffffffff;
      pvStack_6c = (void *)0x0;
      uStack_74 = 0x755603;
      FUN_00401660();
      puStack_8 = auStack_80;
      iStack_68 = 0xf;
      pvStack_6c = (void *)0x0;
      uStack_7c = 0;
      FUN_00401660(auStack_46 + -10,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      FUN_004dd240(0x16,1,0,0,0);
    }
    else if (cVar2 == '\x01') {
      pcStack_64 = (char *)0x0;
      iStack_68 = 0x755653;
      uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
      iStack_68 = 0xffffffff;
      pvStack_6c = (void *)0x0;
      uStack_74 = 0x755660;
      FUN_00401660();
      puStack_8 = auStack_80;
      iStack_68 = 0xf;
      pvStack_6c = (void *)0x0;
      uStack_7c = 0;
      FUN_00401660(auStack_46 + -10,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      FUN_004dd240(0x16,4,0,0,0);
    }
    else if (cVar2 == '\a') {
      pcStack_64 = (char *)0x0;
      iStack_68 = 0x7556ad;
      uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
      iStack_68 = 0xffffffff;
      pvStack_6c = (void *)0x0;
      uStack_74 = 0x7556ba;
      FUN_00401660();
      puStack_8 = auStack_80;
      FUN_00765c50(auStack_46 + -10);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    }
    else {
      pcStack_64 = (char *)0x0;
      iStack_68 = 0x7556e7;
      uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
      iStack_68 = 0xffffffff;
      pvStack_6c = (void *)0x0;
      uStack_74 = 0x7556f4;
      FUN_00401660();
      puStack_8 = auStack_80;
      FUN_00765c50(auStack_46 + -10);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    }
    if (0xf < unaff_EDI) {
      _free(pvStack_6c);
      return extraout_EAX;
    }
  }
  ExceptionList = pvStack_38;
  return 1;
}


// ==== FUN_00755890 @ 0x00755890 ====

undefined4 FUN_00755890(void)

{
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined2 extraout_var;
  int unaff_EBX;
  int unaff_retaddr;
  undefined1 auStack_80 [4];
  undefined1 uStack_7c;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 auStack_46 [2];
  void *pvStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  void *local_28;
  void *local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009940d2;
  pvStack_c = ExceptionList;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  uStack_64 = 0x7558d2;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  FUN_00796d50();
  local_4 = 0xffffffff;
  if ((void *)0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  (**(code **)(*DAT_00b5af2c + 8))();
  switch(*(undefined1 *)(unaff_retaddr + 0x10)) {
  case 0:
    (**(code **)(*DAT_00b5a784 + 0x10))();
    uStack_64 = CONCAT22(extraout_var,*(undefined2 *)(unaff_EBX + 8));
    uStack_68 = 0x755940;
    FUN_00829ac0();
    uStack_64 = (**(code **)(*DAT_00b5a980 + 8))();
    uStack_68 = 0x755957;
    FUN_00829a60();
    (**(code **)(*DAT_00b5a784 + 8))();
    goto LAB_00755ac9;
  default:
    uStack_64 = 0;
    uStack_68 = 0x755a5b;
    uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_68 = 0xffffffff;
    uStack_6c = 0;
    uStack_74 = 0x755a73;
    FUN_00401660();
    puStack_8 = auStack_80;
    uStack_68 = 0xf;
    uStack_6c = 0;
    local_10 = (void *)0x4;
    uStack_7c = 0;
    FUN_00401660(auStack_46 + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    puStack_8 = (undefined1 *)0xffffffff;
    if (0xf < uStack_30) {
      uStack_64 = 0x755aba;
      _free(pvStack_44);
      return extraout_EAX_01;
    }
    uStack_30 = 0xf;
    uStack_34 = 0;
    goto LAB_00755ac9;
  case 2:
    uStack_64 = 0;
    uStack_68 = 0x7559af;
    uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_68 = 0xffffffff;
    uStack_6c = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = uStack_30 & 0xffffff00;
    uStack_74 = 0x7559c7;
    FUN_00401660();
    local_10 = (void *)0x2;
    break;
  case 3:
    uStack_64 = 5;
    uStack_68 = 0x75597c;
    uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_68 = 0xffffffff;
    uStack_6c = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = uStack_30 & 0xffffff00;
    uStack_74 = 0x755994;
    FUN_00401660();
    local_10 = (void *)0x1;
    break;
  case 4:
    uStack_64 = 0;
    uStack_68 = 0x7559e2;
    uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_68 = 0xffffffff;
    uStack_6c = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = uStack_30 & 0xffffff00;
    uStack_74 = 0x7559fa;
    FUN_00401660();
    local_10 = (void *)0x3;
  }
  puStack_8 = auStack_80;
  uStack_68 = 0xf;
  uStack_6c = 0;
  uStack_7c = 0;
  FUN_00401660(&uStack_34,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  puStack_8 = (undefined1 *)0xffffffff;
  if (0xf < local_14) {
    uStack_64 = 0x755a45;
    _free(local_28);
    return extraout_EAX_00;
  }
LAB_00755ac9:
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5a790 + 8))();
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  ExceptionList = local_10;
  return 1;
}


// ==== FUN_00755b20 @ 0x00755b20 ====

undefined4 FUN_00755b20(void)

{
  undefined4 extraout_EAX;
  undefined4 *puVar1;
  undefined1 local_28 [4];
  void *local_24;
  void *pvStack_18;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009940e4;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_>>>>>_Shop_Close_009f2188,0x10);
  local_4 = 0;
  FUN_00796d50(local_28);
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  (**(code **)(*DAT_00b5af2c + 8))(0);
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f221c;
  }
  FUN_00797a20(puVar1);
  (**(code **)(*DAT_00b5a78c + 0x60))(0);
  (**(code **)(*DAT_00b5b120 + 8))();
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  ExceptionList = pvStack_18;
  return 1;
}


// ==== FUN_00755c00 @ 0x00755c00 ====

undefined4 FUN_00755c00(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  void *unaff_EBX;
  int unaff_retaddr;
  undefined4 uStack_88;
  uint uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined1 auStack_50 [12];
  undefined1 uStack_44;
  uint uStack_40;
  undefined4 uStack_34;
  undefined4 uStack_30;
  void *pvStack_20;
  undefined1 uStack_18;
  undefined1 uStack_14;
  int iStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099410e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  uStack_30 = 0xf;
  uStack_34 = 0;
  uStack_44 = 0;
  puStack_8 = (undefined1 *)0x0;
  switch(*(undefined4 *)(unaff_retaddr + 0x44)) {
  case 0:
    piVar2 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
    cVar1 = (**(code **)(*piVar2 + 8))();
    if (cVar1 == '\0') {
      FUN_00401830();
      uStack_14 = 1;
      FUN_00796d50();
      uStack_14 = 0;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    (**(code **)(*piVar2 + 0x78))();
    uVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iStack_10 == 0) {
      uStack_80 = 0x755cf2;
      uStack_7c = uVar3;
      cVar1 = FUN_00829a00();
      if (cVar1 == '\0') {
        uStack_7c = 0x755d07;
        FUN_00401830();
        uStack_18 = 2;
        uStack_7c = 0x755d16;
        FUN_00406880();
        uStack_18 = 0;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
LAB_00755d72:
      uStack_80 = 0x755d78;
      uStack_7c = uVar3;
      FUN_00829930();
    }
    else if (iStack_10 == 1) {
      uStack_80 = 0x755d39;
      uStack_7c = uVar3;
      cVar1 = FUN_00829990();
      if (cVar1 == '\0') {
        uStack_7c = 0x755d4e;
        FUN_00401830();
        uStack_18 = 3;
        uStack_7c = 0x755d5d;
        FUN_00406880();
        uStack_18 = 0;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      goto LAB_00755d72;
    }
    (**(code **)(*DAT_00b5a790 + 4))();
    (**(code **)(*DAT_00b5a790 + 8))();
    (**(code **)(*DAT_00b5ad1c + 8))();
    (**(code **)(*DAT_00b5ad58 + 0xc))();
    (**(code **)(*DAT_00b5ad84 + 0x18))();
    break;
  default:
    goto LAB_00755e87;
  case 0xb:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_7c = 0x755dda;
    FUN_00401660();
    puStack_8 = (undefined1 *)&uStack_88;
    uStack_84 = uStack_84 & 0xffffff00;
    FUN_00401660(auStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uStack_7c = 0;
    uStack_80 = 0;
    uStack_84 = 4;
    uStack_88 = 0x16;
    FUN_004dd240();
    break;
  case 0xe:
LAB_00755e87:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_7c = 0x755ea0;
    FUN_00401660();
    puStack_8 = (undefined1 *)&uStack_88;
    uStack_84 = uStack_84 & 0xffffff00;
    FUN_00401660(auStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    break;
  case 0x10:
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_7c = 0x755e42;
    FUN_00401660();
    puStack_8 = (undefined1 *)&uStack_88;
    uStack_84 = uStack_84 & 0xffffff00;
    FUN_00401660(auStack_50,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uStack_7c = 0;
    uStack_80 = 0;
    uStack_84 = 1;
    uStack_88 = 0x16;
    FUN_004dd240();
  }
  if (uStack_40 < 0x10) {
    ExceptionList = pvStack_20;
    return 1;
  }
  uStack_7c = 0x755edf;
  _free(unaff_EBX);
  return extraout_EAX;
}


// ==== FUN_00755f30 @ 0x00755f30 ====

undefined4 FUN_00755f30(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x10000003) {
    if (uVar1 == 0x10000002) {
      FUN_00755c00(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    switch(uVar1 + 0xfaf60000) {
    case 0:
      FUN_00754fa0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 2:
      FUN_007551d0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 4:
      FUN_00755890(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 6:
      FUN_00755b20(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 8:
      FUN_00755540(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00756000 @ 0x00756000 ====

undefined4 FUN_00756000(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00755f30(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x70004) {
    cVar1 = FUN_00754c90(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00756050 @ 0x00756050 ====

undefined4 FUN_00756050(void)

{
  return 0x70100000;
}


// ==== FUN_00756060 @ 0x00756060 ====

undefined4 FUN_00756060(void)

{
  return 0x70100001;
}


// ==== FUN_00756070 @ 0x00756070 ====

void FUN_00756070(byte param_1)

{
  void *in_ECX;
  
  FUN_00754ec0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00756090 @ 0x00756090 ====

void FUN_00756090(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f22a4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007560b0 @ 0x007560b0 ====

undefined4 FUN_007560b0(void)

{
  return 0x70100002;
}


// ==== FUN_007560d0 @ 0x007560d0 ====

void FUN_007560d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f22e4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b11c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b11c = in_ECX;
  return;
}


// ==== FUN_00756100 @ 0x00756100 ====

void FUN_00756100(void)

{
                    /* WARNING: Could not recover jumptable at 0x00756108. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b120 + 0xc))();
  return;
}


// ==== FUN_00756110 @ 0x00756110 ====

void FUN_00756110(void)

{
                    /* WARNING: Could not recover jumptable at 0x00756118. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5b120 + 0x10))();
  return;
}


// ==== FUN_00756120 @ 0x00756120 ====

void FUN_00756120(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5b120 + 0x18))(param_1);
  FUN_00829ac0(uVar1);
  return;
}


// ==== FUN_00756140 @ 0x00756140 ====

uint FUN_00756140(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  
  uVar2 = (**(code **)(*DAT_00b5b120 + 0xc))();
  uVar4 = 0;
  piVar3 = (int *)0x0;
  if (uVar2 != 0) {
    do {
      piVar3 = (int *)(**(code **)(*DAT_00b5b120 + 0x10))(uVar4);
      if (*piVar3 == param_1) {
        iVar1 = piVar3[2];
        *param_2 = iVar1;
        return CONCAT31((int3)((uint)iVar1 >> 8),1);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  *param_2 = 0;
  return (uint)piVar3 & 0xffffff00;
}


// ==== FUN_007561a0 @ 0x007561a0 ====

void FUN_007561a0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f22d0;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007561d0 @ 0x007561d0 ====

void FUN_007561d0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b11c = 0;
  *in_ECX = &PTR_FUN_009f22a4;
  return;
}


// ==== FUN_007561f0 @ 0x007561f0 ====

void FUN_007561f0(undefined1 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5b120 + 0x18))();
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x10000001;
    *(undefined2 *)((int)pvVar4 + 6) = 0x1c;
    iVar5 = FUN_004244d0();
    uVar3 = (**(code **)(*DAT_00b5b120 + 0x14))();
    *(undefined4 *)(iVar5 + 0x10) = uVar3;
    *(short *)(iVar5 + 0x14) = (short)uVar2;
    *(undefined2 *)(iVar5 + 0x16) = *(undefined2 *)(unaff_retaddr + 4);
    *(undefined1 *)(iVar5 + 0x18) = *(undefined1 *)(unaff_retaddr + 6);
    *(undefined1 *)(iVar5 + 0x19) = param_1;
    FUN_004d8570(iVar5);
    (**(code **)(*DAT_00b5b124 + 8))(uVar2,*(undefined1 *)(unaff_retaddr + 4));
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_007562b0 @ 0x007562b0 ====

void FUN_007562b0(undefined1 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5b120 + 0x18))();
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x50a0001;
    *(undefined2 *)((int)pvVar4 + 6) = 0x1c;
    iVar5 = FUN_004244d0();
    uVar3 = (**(code **)(*DAT_00b5b120 + 0x14))();
    *(undefined4 *)(iVar5 + 0x10) = uVar3;
    *(short *)(iVar5 + 0x14) = (short)uVar2;
    *(undefined2 *)(iVar5 + 0x16) = *(undefined2 *)(unaff_retaddr + 4);
    *(undefined1 *)(iVar5 + 0x18) = *(undefined1 *)(unaff_retaddr + 6);
    *(undefined1 *)(iVar5 + 0x19) = param_1;
    FUN_004d8570(iVar5);
    (**(code **)(*DAT_00b5b124 + 8))(uVar2,*(undefined1 *)(unaff_retaddr + 4));
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_00756370 @ 0x00756370 ====

void FUN_00756370(char param_1)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if ((cVar1 == '\0') && (param_1 != '\0')) {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x50a0007;
    *(undefined2 *)((int)pvVar4 + 6) = 0x1c;
    iVar5 = FUN_004244d0();
    uVar3 = (**(code **)(*DAT_00b5b120 + 0x14))();
    *(undefined4 *)(iVar5 + 0x10) = uVar3;
    uVar2 = (**(code **)(*DAT_00b5b120 + 0x18))();
    *(undefined2 *)(iVar5 + 0x14) = uVar2;
    *(undefined2 *)(iVar5 + 0x16) = *(undefined2 *)(unaff_retaddr + 4);
    *(undefined1 *)(iVar5 + 0x18) = *(undefined1 *)(unaff_retaddr + 6);
    *(char *)(iVar5 + 0x19) = param_1;
    FUN_004d8570(iVar5);
    (**(code **)(*DAT_00b5b124 + 8))
              (*(undefined2 *)(iVar5 + 0x14),*(undefined1 *)(unaff_retaddr + 4));
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_00756440 @ 0x00756440 ====

void FUN_00756440(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  undefined2 extraout_var;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x50a0003;
    *(undefined2 *)((int)pvVar4 + 6) = 0x18;
    iVar5 = FUN_004244d0();
    uVar3 = (**(code **)(*DAT_00b5b120 + 0x14))();
    *(undefined4 *)(iVar5 + 0x10) = uVar3;
    uVar2 = (**(code **)(*DAT_00b5b120 + 0x18))();
    *(undefined2 *)(iVar5 + 0x14) = uVar2;
    FUN_004d8570(iVar5);
    (**(code **)(*DAT_00b5b124 + 0xc))(CONCAT22(extraout_var,*(undefined2 *)(iVar5 + 0x14)));
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  return;
}


// ==== FUN_007564d0 @ 0x007564d0 ====

undefined4 FUN_007564d0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x50a0005;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(0);
    return 1;
  }
  return 0;
}


// ==== FUN_00756540 @ 0x00756540 ====

void FUN_00756540(undefined4 *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*(int *)*param_1 + 0x48))();
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (*(int *)(iVar2 + 0x120) == 0) {
    FUN_007562b0(param_1,param_2);
    return;
  }
  FUN_007561f0(param_1,param_2);
  return;
}


// ==== FUN_00756590 @ 0x00756590 ====

void FUN_00756590(byte param_1)

{
  void *in_ECX;
  
  FUN_007561d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007565b0 @ 0x007565b0 ====

void FUN_007565b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f2310;
  return;
}


// ==== FUN_007565c0 @ 0x007565c0 ====

void FUN_007565c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f2310;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007565e0 @ 0x007565e0 ====

undefined4 FUN_007565e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_007565f0 @ 0x007565f0 ====

undefined2 FUN_007565f0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x18);
}


// ==== FUN_00756600 @ 0x00756600 ====

void FUN_00756600(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
                    /* WARNING: Could not recover jumptable at 0x00756610. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(iVar1 + 0x30) + 0xc))();
  return;
}


// ==== FUN_00756620 @ 0x00756620 ====

int FUN_00756620(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8)) / 0xc;
}


// ==== FUN_00756640 @ 0x00756640 ====

void FUN_00756640(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f2330;
  DAT_00b5b120 = 0;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009f2310;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00756680 @ 0x00756680 ====

int FUN_00756680(uint param_1)

{
  int iVar1;
  int in_ECX;
  uint extraout_EDX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 != 0) {
    if (param_1 < (uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc)) goto LAB_007566ad;
  }
  FUN_00756800();
  param_1 = extraout_EDX;
LAB_007566ad:
  return iVar1 + param_1 * 0xc;
}


// ==== FUN_007566c0 @ 0x007566c0 ====

void FUN_007566c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f2330;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b120 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b120 = in_ECX;
  return;
}


// ==== FUN_00756720 @ 0x00756720 ====

void FUN_00756720(undefined4 param_1,undefined2 param_2)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  undefined1 uStack00000000;
  undefined1 auStack_a [2];
  undefined4 uStack_8;
  
  *(undefined4 *)(in_ECX + 0x14) = param_1;
  *(undefined2 *)(in_ECX + 0x18) = param_2;
  if (*(void **)(in_ECX + 8) != (void *)0x0) {
    _free(*(void **)(in_ECX + 8));
    return;
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar1 = *(int **)(iVar3 + 0x30);
  (**(code **)(*piVar1 + 0x20))(&param_2);
  cVar2 = (**(code **)(*piVar1 + 0x24))();
  if ((cVar2 != '\0') && (iVar3 = (**(code **)(*piVar1 + 0x2c))(), iVar3 != 0)) {
    do {
      cVar2 = (**(code **)(*piVar1 + 0x34))(iVar3,&uStack00000000);
      if (cVar2 != '\0') {
        FUN_00829c20(*(undefined2 *)(in_ECX + 0x18),uStack_8,iVar3);
        FUN_00756c20(auStack_a + -0xe);
      }
      iVar3 = (**(code **)(*piVar1 + 0x30))();
    } while (iVar3 != 0);
  }
  return;
}


// ==== FUN_00756800 @ 0x00756800 ====

void FUN_00756800(void)

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
  puStack_8 = &LAB_00994128;
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


// ==== FUN_00756870 @ 0x00756870 ====

void FUN_00756870(void)

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
  puStack_8 = &LAB_00994128;
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


// ==== FUN_007568e0 @ 0x007568e0 ====

void FUN_007568e0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00994140;
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
      FUN_00756870();
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


// ==== Catch@00756a92 @ 0x00756a92 ====

void Catch_00756a92(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + 0x10));
  return;
}


// ==== FUN_00756b90 @ 0x00756b90 ====

void FUN_00756b90(byte param_1)

{
  void *in_ECX;
  
  FUN_00756640();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00756bb0 @ 0x00756bb0 ====

void FUN_00756bb0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0xc != 0) {
      iVar1 = (param_2 - iVar1) / 0xc;
      goto LAB_00756bf3;
    }
  }
  iVar1 = 0;
LAB_00756bf3:
  FUN_007568e0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0xc;
  return;
}


// ==== FUN_00756c20 @ 0x00756c20 ====

void FUN_00756c20(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0xc) <= (uint)((*(int *)(in_ECX + 8) - iVar1) / 0xc)
     )) {
    FUN_00756bb0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0042ea70(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0xc;
  return;
}


// ==== FUN_00756ca0 @ 0x00756ca0 ====

void FUN_00756ca0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f24ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00756cd0 @ 0x00756cd0 ====

void FUN_00756cd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f24b8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b110 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b110 = in_ECX;
  return;
}


// ==== FUN_00756d40 @ 0x00756d40 ====

void FUN_00756d40(void)

{
  (**(code **)(*DAT_00b5b114 + 0xc))();
  (**(code **)(*DAT_00b5a78c + 0x20))();
                    /* WARNING: Could not recover jumptable at 0x00756d66. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5acd4 + 4))();
  return;
}


// ==== FUN_00756d70 @ 0x00756d70 ====

void FUN_00756d70(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b110 = 0;
  *in_ECX = &PTR_FUN_009f24ac;
  return;
}


// ==== FUN_00756d90 @ 0x00756d90 ====

void FUN_00756d90(void)

{
  undefined4 auStack_104 [65];
  
  auStack_104[0] = 0x756da1;
  (**(code **)(*DAT_00b5b114 + 0x10))();
  auStack_104[0] = 0x756dac;
  (**(code **)(*DAT_00b5a78c + 0x24))();
  auStack_104[0] = 0;
  (**(code **)(*DAT_00b5af2c + 8))();
  FUN_0044a580(auStack_104,&DAT_009f2490,s_RECEIVE______STORAGEPACKETS__SA__009f2468);
  FUN_00797b80(auStack_104);
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  return;
}


// ==== FUN_00756df0 @ 0x00756df0 ====

/* WARNING: Removing unreachable block (ram,0x00756e84) */

void FUN_00756df0(int param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  undefined1 auStack_12a [2];
  void *pvStack_128;
  uint uStack_114;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099419c;
  pvStack_c = ExceptionList;
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\0') {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5b114 + 0x2c))();
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar3 == 0) {
      FUN_00401740();
      local_4 = 0;
      FUN_00406880();
      local_4 = 0xffffffff;
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_00829ce0();
  }
  else if (cVar1 == '\x02') {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0x1;
    FUN_00401660(auStack_12a + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    local_4 = 0xffffffff;
    if (0xf < uStack_114) {
      _free(pvStack_128);
      return;
    }
  }
  else {
    if (cVar1 != '\x01') {
      ExceptionList = &pvStack_c;
      FUN_00401830();
      local_4 = 3;
      FUN_00406880();
      local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0x2;
    FUN_00401660(auStack_12a + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    local_4 = 0xffffffff;
    if (0xf < uStack_114) {
      _free(pvStack_128);
      return;
    }
  }
  (**(code **)(*DAT_00b5af2c + 8))();
  FUN_0044a580();
  FUN_00797b80();
  (**(code **)(*DAT_00b5b114 + 8))();
  (**(code **)(*DAT_00b5a78c + 0x6c))();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00757070 @ 0x00757070 ====

/* WARNING: Removing unreachable block (ram,0x00757104) */

void FUN_00757070(int param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  undefined1 auStack_12a [2];
  void *pvStack_128;
  uint uStack_114;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009941dd;
  pvStack_c = ExceptionList;
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\0') {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5b114 + 0x2c))();
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar3 == 0) {
      FUN_00401740();
      local_4 = 0;
      FUN_00406880();
      local_4 = 0xffffffff;
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    FUN_00829d40();
  }
  else if (cVar1 == '\x03') {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0x1;
    FUN_00401660(auStack_12a + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    local_4 = 0xffffffff;
    if (0xf < uStack_114) {
      _free(pvStack_128);
      return;
    }
  }
  else {
    if (cVar1 != '\x01') {
      if (cVar1 == '\x02') {
        ExceptionList = &pvStack_c;
        (**(code **)(*DAT_00b5a794 + 0xc))();
        FUN_00765c50();
        pvStack_c = (void *)0x3;
        FUN_00765c50(auStack_12a + -10);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      ExceptionList = &pvStack_c;
      FUN_00401830();
      local_4 = 4;
      FUN_00406880();
      local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0x2;
    FUN_00401660(auStack_12a + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    local_4 = 0xffffffff;
    if (0xf < uStack_114) {
      _free(pvStack_128);
      return;
    }
  }
  (**(code **)(*DAT_00b5af2c + 8))();
  FUN_0044a580();
  FUN_00797b80();
  (**(code **)(*DAT_00b5b114 + 8))();
  (**(code **)(*DAT_00b5a78c + 0x6c))();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00757350 @ 0x00757350 ====

void FUN_00757350(int param_1)

{
  char cVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  void *unaff_EBP;
  int iStack_180;
  undefined1 *puStack_17c;
  undefined1 *puStack_178;
  char *pcStack_174;
  TypeDescriptor *pTStack_170;
  TypeDescriptor *pTStack_16c;
  uint uVar8;
  undefined1 auStack_14a [6];
  void *pvStack_144;
  uint auStack_140 [3];
  int *piStack_134;
  uint uStack_130;
  int *piStack_12c;
  undefined1 uStack_124;
  undefined4 uStack_114;
  undefined4 uStack_110;
  void *pvStack_40;
  undefined4 uStack_34;
  undefined4 uStack_2c;
  undefined1 uStack_18;
  undefined1 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994260;
  pvStack_c = ExceptionList;
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 != '\0') {
    if (cVar1 == '\x02') {
      uVar8 = 0x6e0020;
      ExceptionList = &pvStack_c;
      pTStack_170 = (TypeDescriptor *)(**(code **)(*DAT_00b5a794 + 0xc))();
      pTStack_16c = (TypeDescriptor *)0x0;
      auStack_140[2] = 0xf;
      auStack_140[1] = 0;
      pcStack_174 = (void *)0x757704;
      FUN_00401660();
      pTStack_16c = (TypeDescriptor *)0x0;
      pvStack_c = (void *)0x6;
      puStack_17c = (undefined1 *)((uint)puStack_17c & 0xffffff00);
      FUN_00401660(auStack_14a + -6,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      uStack_34 = 0xffffffff;
      if (0xf < uVar8) {
        _free(pcStack_174);
        return;
      }
    }
    else {
      if (cVar1 != '\x03') {
        if (cVar1 == '\x01') {
          ExceptionList = &pvStack_c;
          (**(code **)(*DAT_00b5a794 + 0xc))();
          pTStack_16c = (TypeDescriptor *)0x75781a;
          FUN_00765c50();
          pvStack_c = (void *)0x8;
          FUN_00765c50(auStack_14a + -6);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
        }
        else {
          if (cVar1 != '\x04') {
            ExceptionList = &pvStack_c;
            FUN_00401830();
            local_4 = 10;
            FUN_00406880();
            local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          ExceptionList = &pvStack_c;
          (**(code **)(*DAT_00b5a794 + 0xc))();
          pTStack_16c = (TypeDescriptor *)0x75787f;
          FUN_00765c50();
          pvStack_c = (void *)0x9;
          FUN_00765c50(auStack_14a + -6);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
        }
        uStack_2c = 0xffffffff;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      uVar8 = 0x6e0021;
      ExceptionList = &pvStack_c;
      pTStack_170 = (TypeDescriptor *)(**(code **)(*DAT_00b5a794 + 0xc))();
      pTStack_16c = (TypeDescriptor *)0x0;
      auStack_140[2] = 0xf;
      auStack_140[1] = 0;
      pcStack_174 = (void *)0x75779b;
      FUN_00401660();
      pTStack_16c = (TypeDescriptor *)0x0;
      pvStack_c = (void *)0x7;
      puStack_17c = (undefined1 *)((uint)puStack_17c & 0xffffff00);
      FUN_00401660(auStack_14a + -6,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      uStack_34 = 0xffffffff;
      if (0xf < uVar8) {
        _free(pcStack_174);
        return;
      }
    }
    goto LAB_007578e7;
  }
  ExceptionList = &pvStack_c;
  iVar4 = (**(code **)(*DAT_00b5b114 + 0x2c))();
  iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar5 == 0) {
    uStack_130 = 0xf;
    piStack_134 = (int *)0x0;
    pvStack_144 = (void *)((uint)pvStack_144 & 0xffffff00);
    FUN_00401740();
    local_4 = 0;
    FUN_00406880();
    local_4 = 0xffffffff;
    if (uStack_130 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_144);
    return;
  }
  piVar2 = *(int **)(iVar5 + 0x2c);
  if (piVar2 == (int *)0x0) {
    uStack_130 = 0xf;
    piStack_134 = (int *)0x0;
    pvStack_144 = (void *)((uint)pvStack_144._1_3_ << 8);
    FUN_00401740();
    local_4 = 1;
    FUN_00406880();
    local_4 = 0xffffffff;
    if (uStack_130 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_144);
    return;
  }
  piVar6 = *(int **)(iVar5 + 0x1c);
  piStack_12c = piVar6;
  if (piVar6 == (int *)0x0) {
    uStack_130 = 0xf;
    piStack_134 = (int *)0x0;
    pvStack_144 = (void *)((uint)pvStack_144._1_3_ << 8);
    FUN_00401740();
    local_4 = 2;
    FUN_00406880();
    if (uStack_130 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(pvStack_144);
    return;
  }
  uStack_110 = 0xf;
  uStack_114 = 0;
  uStack_124 = 0;
  local_4 = 3;
  iVar5 = (**(code **)(*piVar2 + 0x14))();
  if (iVar5 == 2) {
    pTStack_16c = (TypeDescriptor *)0x7574e4;
    piVar6 = (int *)(**(code **)(*piVar2 + 0x24))();
    pTStack_16c = (TypeDescriptor *)0x6e001e;
    pTStack_170 = (TypeDescriptor *)0x0;
    pcStack_174 = (char *)0x7574f7;
    puStack_17c = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
    pcStack_174 = (char *)0xffffffff;
    puStack_178 = (undefined1 *)0x0;
    iStack_180 = 0x757510;
    FUN_00401660();
    pcStack_174 = (char *)0xffffffff;
    puStack_178 = (undefined1 *)0x0;
    puStack_17c = auStack_14a + -0x12;
    uStack_18 = 4;
    iStack_180 = 0x757529;
    FUN_00401660();
    pcStack_174 = (void *)0x757530;
    iVar5 = (**(code **)(*piVar6 + 0x2c))();
    pTStack_16c = (TypeDescriptor *)(iVar5 + 0x32);
    pcVar7 = (char *)pTStack_16c;
    do {
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    pTStack_170 = (TypeDescriptor *)0x757556;
    FUN_004020e0();
    pTStack_16c = (TypeDescriptor *)&DAT_009f23b8;
    pTStack_170 = (TypeDescriptor *)0x757566;
    FUN_004020e0();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
    if (0xf < auStack_140[2]) {
      pTStack_16c = (TypeDescriptor *)0x757583;
      _free((void *)(iVar4 + 4));
      return;
    }
LAB_00757667:
    piVar6 = piStack_134;
  }
  else if ((iVar5 == 1) || (iVar5 == 3)) {
    puStack_178 = (undefined1 *)(**(code **)(*piVar6 + 0x1c))();
    pTStack_16c = &Framework::Article::IItem::RTTI_Type_Descriptor;
    pTStack_170 = &Framework::IArticle::RTTI_Type_Descriptor;
    pcStack_174 = (void *)0x0;
    puStack_17c = (undefined1 *)0x7575b2;
    piVar6 = (int *)FUN_00803725();
    if (piVar6 != (int *)0x0) {
      pTStack_16c = (TypeDescriptor *)0x0;
      pTStack_170 = (TypeDescriptor *)0x0;
      pcStack_174 = (char *)0x7575c9;
      iVar4 = (**(code **)(*piVar6 + 0x2c))();
      pcStack_174 = *(char **)(iVar4 + 0x14);
      puStack_178 = (undefined1 *)0xb;
      puStack_17c = (undefined1 *)0x7575d4;
      FUN_004dd240();
      pTStack_16c = (TypeDescriptor *)0x0;
      pTStack_170 = (TypeDescriptor *)0x7575e8;
      puStack_178 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
      pTStack_170 = (TypeDescriptor *)0xffffffff;
      pcStack_174 = (char *)0x0;
      auStack_140[0] = 0xf;
      puStack_17c = (undefined1 *)0x757601;
      FUN_00401660();
      pTStack_170 = (TypeDescriptor *)0xffffffff;
      pcStack_174 = (char *)0x0;
      puStack_178 = auStack_14a + -0xe;
      uStack_14 = 5;
      puStack_17c = (undefined1 *)0x75761a;
      FUN_00401660();
      pTStack_170 = (TypeDescriptor *)0x757621;
      iVar4 = (**(code **)(*piVar6 + 0x2c))();
      pcStack_174 = (char *)(iVar4 + 0x32);
      pcVar7 = pcStack_174;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      pTStack_170 = (TypeDescriptor *)((int)pcVar7 - (iVar4 + 0x33));
      puStack_178 = (undefined1 *)0x757646;
      FUN_004020e0();
      pTStack_170 = (TypeDescriptor *)0x1;
      pcStack_174 = &DAT_009f23bc;
      puStack_178 = (undefined1 *)0x757656;
      FUN_004020e0();
      uStack_14 = 3;
                    /* WARNING: Subroutine does not return */
      pTStack_170 = (TypeDescriptor *)0x757667;
      FUN_00446f10();
    }
    goto LAB_00757667;
  }
  piStack_134 = &iStack_180;
  pTStack_16c = (TypeDescriptor *)0x0;
  puStack_17c = (undefined1 *)((uint)puStack_17c & 0xffffff00);
  FUN_00401660(&uStack_130,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  (**(code **)(*piVar2 + 0x2c))(pcStack_174,piVar6);
  uStack_34 = 0xffffffff;
  if (0xf < auStack_140[0]) {
    _free(unaff_EBP);
    return;
  }
LAB_007578e7:
  uStack_34 = 0xffffffff;
  (**(code **)(*DAT_00b5af2c + 8))(0);
  FUN_0044a580(auStack_140,&DAT_009f2490,s_RECEIVE______STORAGEPACKETS__SA__009f23c8);
  FUN_00797b80(auStack_140);
  (**(code **)(*DAT_00b5b114 + 8))();
  (**(code **)(*DAT_00b5a78c + 0x6c))();
  ExceptionList = pvStack_40;
  return;
}


// ==== FUN_00757950 @ 0x00757950 ====

undefined4 FUN_00757950(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  switch(iVar1 + -0x50b0000) {
  case 0:
    FUN_00756d40(*(undefined4 *)(param_1 + 0xc));
    return 1;
  default:
    return 0;
  case 2:
    FUN_00757350(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 4:
    FUN_00757070(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 6:
    FUN_00756df0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 8:
    FUN_00756d90(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
}


// ==== FUN_00757a00 @ 0x00757a00 ====

undefined4 FUN_00757a00(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00757950(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00757a30 @ 0x00757a30 ====

void FUN_00757a30(byte param_1)

{
  void *in_ECX;
  
  FUN_00756d70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00757a50 @ 0x00757a50 ====

void FUN_00757a50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f2604;
  return;
}


// ==== FUN_00757a60 @ 0x00757a60 ====

void FUN_00757a60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f2604;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00757a80 @ 0x00757a80 ====

undefined1 FUN_00757a80(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_00757a90 @ 0x00757a90 ====

undefined1 FUN_00757a90(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x14);
}


// ==== FUN_00757aa0 @ 0x00757aa0 ====

void FUN_00757aa0(undefined1 param_1)

{
  int *in_ECX;
  
  *(undefined1 *)(in_ECX + 5) = param_1;
  (**(code **)(*in_ECX + 8))();
  return;
}


// ==== FUN_00757ab0 @ 0x00757ab0 ====

int FUN_00757ab0(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_00757ad0 @ 0x00757ad0 ====

void FUN_00757ad0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f265c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00757b00 @ 0x00757b00 ====

void FUN_00757b00(void)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5b118 + 8))();
  *(undefined1 *)(in_ECX + 8) = 1;
  (**(code **)(*DAT_00b5a78c + 0x60))(3);
                    /* WARNING: Could not recover jumptable at 0x00757b28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a78c + 0x20))();
  return;
}


// ==== FUN_00757b30 @ 0x00757b30 ====

void FUN_00757b30(void)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5b118 + 0xc))();
  *(undefined1 *)(in_ECX + 8) = 0;
  (**(code **)(*DAT_00b5a78c + 0x60))(0);
  return;
}


// ==== FUN_00757b60 @ 0x00757b60 ====

undefined4 FUN_00757b60(undefined4 param_1)

{
  (**(code **)(*DAT_00b5b118 + 0x18))(param_1);
  return param_1;
}


// ==== FUN_00757b80 @ 0x00757b80 ====

undefined4 FUN_00757b80(undefined4 param_1)

{
  (**(code **)(*DAT_00b5b118 + 0x1c))(param_1);
  return param_1;
}


// ==== FUN_00757ba0 @ 0x00757ba0 ====

undefined4 FUN_00757ba0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_storagewnd_009f251c,0xf);
  if (iVar1 != 0) {
    return 0;
  }
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar2 = &PTR_FUN_009f2648;
  FUN_00797a20(puVar2);
  return 1;
}


// ==== FUN_00757c00 @ 0x00757c00 ====

void FUN_00757c00(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int in_ECX;
  undefined2 unaff_retaddr;
  undefined1 unaff_retaddr_00;
  undefined4 uStack_108;
  
  uStack_108 = 0;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x50b0001;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined2 *)(iVar4 + 0x10) = unaff_retaddr;
    *(undefined1 *)(iVar4 + 0x12) = unaff_retaddr_00;
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5af2c + 4))(0);
    FUN_0044a580(&uStack_108,&DAT_009f25e8,s_SEND______Storage_CQ_Change_009f254c);
    FUN_00797b80(&uStack_108);
    *(undefined2 *)(in_ECX + 0x10) = unaff_retaddr;
    *(undefined1 *)(in_ECX + 0x12) = unaff_retaddr_00;
  }
  return;
}


// ==== FUN_00757cc0 @ 0x00757cc0 ====

void FUN_00757cc0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined4 uStack_108;
  
  uStack_108 = 0;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x50b0005;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined4 *)(iVar4 + 0x10) = unaff_retaddr;
    FUN_004d8570(iVar4);
    *(undefined4 *)(in_ECX + 0xc) = unaff_retaddr;
    (**(code **)(*DAT_00b5af2c + 4))(0);
    FUN_0044a580(&uStack_108,&DAT_009f25e8,s_SEND______Storage_CQ_LOADMONEY_009f25ac);
    FUN_00797b80(&uStack_108);
  }
  return;
}


// ==== FUN_00757d60 @ 0x00757d60 ====

void FUN_00757d60(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  undefined1 auStack_102 [258];
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x50b0007;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(0);
    FUN_0044a580(auStack_102 + -6,&DAT_009f25e8,s_SEND______Storage_CQ_Close_009f25cc);
    FUN_00797b80(auStack_102 + -6);
  }
  return;
}


// ==== FUN_00757df0 @ 0x00757df0 ====

undefined4 FUN_00757df0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_00757ba0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00757e20 @ 0x00757e20 ====

void FUN_00757e20(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  undefined1 local_24;
  void *pvStack_18;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099428b;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *puVar1 = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f267c;
  *puVar1 = &PTR_FUN_009f2670;
  local_4 = 1;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)((int)in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x12) = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5b114 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5b114 = in_ECX;
  }
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(s_show_storagewnd_009f24fc,0xf);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_28,0);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  if (pvStack_18 < (void *)0x10) {
    (**(code **)(*DAT_00b5b118 + 0x10))(puVar1);
    ExceptionList = pvStack_18;
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00757f00 @ 0x00757f00 ====

void FUN_00757f00(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_28;
  undefined1 local_24;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009942cc;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f267c;
  *puVar1 = &PTR_FUN_009f2670;
  local_4 = 1;
  DAT_00b5b114 = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  FUN_00401740(s_show_storagewnd_009f250c,0xf);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
  if (local_14 < (void *)0x10) {
    (**(code **)(*DAT_00b5b118 + 0x14))(puVar1);
    *puVar1 = &PTR_FUN_009ef7a4;
    *in_ECX = &PTR_FUN_009f2604;
    ExceptionList = local_14;
    return;
  }
  _free(local_28);
  return;
}


// ==== FUN_00757fc0 @ 0x00757fc0 ====

undefined4 FUN_00757fc0(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 extraout_EAX_00;
  int *piVar4;
  undefined4 *puVar5;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009942e6;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f252c,0xb);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_24);
    return extraout_EAX;
  }
  if (*(int **)(iVar2 + 0x2c) != (int *)0x0) {
    piVar4 = (int *)(**(code **)(**(int **)(iVar2 + 0x2c) + 0x3c))();
    puVar5 = (undefined4 *)(**(code **)(*piVar4 + 4))();
    ExceptionList = pvStack_c;
    return *puVar5;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pStorage____NULL_009f2538,0x10);
  uStack_4 = 1;
  FUN_00406880(auStack_44);
  uStack_4 = 0xffffffff;
  if (uStack_2c < 0x10) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_40);
  return extraout_EAX_00;
}


// ==== FUN_007580d0 @ 0x007580d0 ====

void FUN_007580d0(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined1 auStack_128 [4];
  void *pvStack_124;
  undefined4 uStack_114;
  uint auStack_110 [64];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994306;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    auStack_110[0] = 0xf;
    uStack_114 = 0;
    pvStack_124 = (void *)((uint)pvStack_124._1_3_ << 8);
    FUN_00401740(s_pPC____NULL_009f256c,0xb);
    uStack_4 = 0;
    FUN_00406880(auStack_128);
    uStack_4 = 0xffffffff;
    if (auStack_110[0] < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_124);
    return;
  }
  if (*(int *)(iVar3 + 0x2c) != 0) {
    cVar2 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
    if (cVar2 == '\0') {
      uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar5 = operator_new(0x400);
      *(undefined4 *)((int)pvVar5 + 8) = uVar4;
      *(undefined4 *)((int)pvVar5 + 0xc) = 0x50b0003;
      *(undefined2 *)((int)pvVar5 + 6) = 0x14;
      iVar3 = FUN_004244d0();
      *(undefined4 *)(iVar3 + 0x10) = unaff_retaddr;
      FUN_004d8570(iVar3);
      *(undefined4 *)(in_ECX + 0xc) = unaff_retaddr;
      (**(code **)(*DAT_00b5af2c + 4))(0);
      FUN_0044a580(auStack_110,&DAT_009f25e8,s_SEND______Storage_CQ_SaveMoney_009f258c);
      FUN_00797b80(auStack_110);
    }
    ExceptionList = pvStack_10;
    return;
  }
  auStack_110[0] = 0xf;
  uStack_114 = 0;
  pvStack_124 = (void *)((uint)pvStack_124._1_3_ << 8);
  FUN_00401740(s_pStorage____NULL_009f2578,0x10);
  uStack_4 = 1;
  FUN_00406880(auStack_128);
  uStack_4 = 0xffffffff;
  if (auStack_110[0] < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_124);
  return;
}


// ==== FUN_00758260 @ 0x00758260 ====

undefined4 FUN_00758260(void)

{
  return 0x70090000;
}


// ==== FUN_00758270 @ 0x00758270 ====

undefined4 FUN_00758270(void)

{
  return 0x70090002;
}


// ==== FUN_00758280 @ 0x00758280 ====

void FUN_00758280(void)

{
  FUN_007582a0();
  return;
}


// ==== FUN_00758290 @ 0x00758290 ====

void FUN_00758290(void)

{
  FUN_00757ad0();
  return;
}


// ==== FUN_007582a0 @ 0x007582a0 ====

void FUN_007582a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00757f00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007582c0 @ 0x007582c0 ====

void FUN_007582c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f2740;
  return;
}


// ==== FUN_007582d0 @ 0x007582d0 ====

void FUN_007582d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f2740;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007582f0 @ 0x007582f0 ====

undefined4 FUN_007582f0(void)

{
  return 0x70090001;
}


// ==== FUN_00758300 @ 0x00758300 ====

void FUN_00758300(void)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f2648;
  }
  FUN_00797a20(puVar1);
  iVar2 = (**(code **)(*DAT_00b5adc4 + 8))();
  if (iVar2 == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00758338. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5adc4 + 0x1c))();
  return;
}


// ==== FUN_00758340 @ 0x00758340 ====

void FUN_00758340(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f2764;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00758370 @ 0x00758370 ====

void FUN_00758370(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 8);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*(int *)puVar3[3] + 4))();
    if (*(char *)((int)puVar3 + 0x11) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x11) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x11);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x11);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x11);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x11);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_007583d0 @ 0x007583d0 ====

void FUN_007583d0(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined4 uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  void *pvStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 *puStack_4;
  
  puStack_4 = (undefined4 *)0xffffffff;
  puStack_8 = &LAB_00994320;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    uStack_10 = 0xf;
    pvStack_14 = (void *)0x0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f26f8,0xb);
    puStack_4 = (undefined4 *)0x0;
    FUN_00406880(auStack_28);
    puStack_4 = (undefined4 *)0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  piVar1 = *(int **)(iVar3 + 0x2c);
  if (piVar1 != (int *)0x0) {
    uStack_4c = 0;
    uStack_4b = 0;
    uStack_4a = 0;
    uStack_48 = (**(code **)(*piVar1 + 0x30))();
    (**(code **)(*piVar1 + 0x18))(uStack_48,&uStack_4c);
    puStack_4[1] = unaff_EBX;
    *puStack_4 = unaff_ESI;
    ExceptionList = pvStack_14;
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pStorage____NULL_009f2704,0x10);
  puStack_4 = (undefined4 *)0x1;
  FUN_00406880(auStack_44);
  puStack_4 = (undefined4 *)0xffffffff;
  if (uStack_2c < 0x10) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_00758500 @ 0x00758500 ====

void FUN_00758500(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined4 uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  void *pvStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 *puStack_4;
  
  puStack_4 = (undefined4 *)0xffffffff;
  puStack_8 = &LAB_0099433a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    uStack_10 = 0xf;
    pvStack_14 = (void *)0x0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f2718,0xb);
    puStack_4 = (undefined4 *)0x0;
    FUN_00406880(auStack_28);
    puStack_4 = (undefined4 *)0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  piVar1 = *(int **)(iVar3 + 0x2c);
  if (piVar1 != (int *)0x0) {
    uStack_4c = 0;
    uStack_4b = 0;
    uStack_4a = 0;
    uStack_48 = (**(code **)(*piVar1 + 0x34))();
    (**(code **)(*piVar1 + 0x18))(uStack_48,&uStack_4c);
    puStack_4[1] = unaff_EBX;
    *puStack_4 = unaff_ESI;
    ExceptionList = pvStack_14;
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pStorage____NULL_009f2724,0x10);
  puStack_4 = (undefined4 *)0x1;
  FUN_00406880(auStack_44);
  puStack_4 = (undefined4 *)0xffffffff;
  if (uStack_2c < 0x10) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_00758630 @ 0x00758630 ====

void FUN_00758630(undefined1 param_1)

{
  undefined1 local_8 [8];
  
  FUN_00752030(local_8,&param_1);
  return;
}


// ==== FUN_00758650 @ 0x00758650 ====

void FUN_00758650(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099434c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f2778;
  DAT_00b5b118 = 0;
  local_4 = 0;
  FUN_007520f0(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_007586d0 @ 0x007586d0 ====

void FUN_007586d0(undefined1 param_1)

{
  FUN_00752400(&param_1);
  return;
}


// ==== FUN_007586e0 @ 0x007586e0 ====

void FUN_007586e0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099435e;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f2778;
  iVar1 = FUN_00751a80();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x11) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b118 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5b118 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00758770 @ 0x00758770 ====

void FUN_00758770(byte param_1)

{
  void *in_ECX;
  
  FUN_00758650();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00758790 @ 0x00758790 ====

void FUN_00758790(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f27f8;
  return;
}


// ==== FUN_007587a0 @ 0x007587a0 ====

void FUN_007587a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f27f8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007587c0 @ 0x007587c0 ====

void FUN_007587c0(void)

{
  return;
}


// ==== FUN_007587e0 @ 0x007587e0 ====

void FUN_007587e0(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x007587e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x1c))();
  return;
}


// ==== FUN_007587f0 @ 0x007587f0 ====

void FUN_007587f0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00994383;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *puVar1 = &PTR_FUN_009ef7a4;
  local_4 = 1;
  *in_ECX = &PTR_FUN_009f286c;
  *puVar1 = &PTR_FUN_009f2860;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5af00 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5af00 = in_ECX;
  }
  *(undefined1 *)(in_ECX + 2) = 0;
  (**(code **)(*DAT_00b5af04 + 0x18))(puVar1);
  ExceptionList = in_ECX;
  return;
}


// ==== FUN_00758870 @ 0x00758870 ====

void FUN_00758870(undefined4 param_1)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5af04 + 8))();
  (**(code **)(*piVar1 + 0x18))(param_1);
  (**(code **)(*in_ECX + 0x1c))();
  return;
}


// ==== FUN_007588a0 @ 0x007588a0 ====

void FUN_007588a0(void)

{
                    /* WARNING: Could not recover jumptable at 0x007588a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5af04 + 8))();
  return;
}


// ==== FUN_007588b0 @ 0x007588b0 ====

uint FUN_007588b0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  return uVar1 & 0xffffff00;
}


// ==== FUN_007588c0 @ 0x007588c0 ====

void FUN_007588c0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f284c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007588f0 @ 0x007588f0 ====

void FUN_007588f0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009943bc;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f286c;
  *puVar1 = &PTR_FUN_009f2860;
  DAT_00b5af00 = 0;
  local_4 = 1;
  (**(code **)(*DAT_00b5af04 + 0x1c))(puVar1);
  *puVar1 = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f27f8;
  ExceptionList = in_ECX;
  return;
}


// ==== FUN_00758960 @ 0x00758960 ====

void FUN_00758960(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) == '\0') {
    *(undefined1 *)(in_ECX + 8) = 1;
    puVar1 = operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009f2824;
    }
    FUN_00797a20(puVar1);
    if (DAT_00b5adb8 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00758997. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*DAT_00b5adb8 + 0x28))();
      return;
    }
  }
  return;
}


// ==== FUN_007589a0 @ 0x007589a0 ====

void FUN_007589a0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    *(undefined1 *)(in_ECX + 8) = 0;
    puVar1 = operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009f2838;
    }
    FUN_00797a20(puVar1);
    if (DAT_00b5adb8 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x007589d7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*DAT_00b5adb8 + 0x28))();
      return;
    }
  }
  return;
}


// ==== FUN_007589e0 @ 0x007589e0 ====

void FUN_007589e0(int param_1)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  void *pvVar6;
  undefined4 *puVar7;
  int in_ECX;
  int *piStack_90;
  void *pvStack_40;
  undefined1 auStack_38 [4];
  undefined1 uStack_34;
  uint uStack_2c;
  undefined1 uStack_24;
  undefined1 uStack_1c;
  undefined1 uStack_14;
  void *local_c;
  undefined1 *puStack_8;
  int *piStack_4;
  
  piStack_4 = (int *)0xffffffff;
  puStack_8 = &LAB_00994460;
  local_c = ExceptionList;
  if ((*(char *)(in_ECX + 8) != '\x01') && (DAT_00b5acd8 != (int *)0x0)) {
    ExceptionList = &local_c;
    piVar3 = (int *)(**(code **)(*DAT_00b5af04 + 8))();
    if (piVar3 == (int *)0x0) {
      FUN_00401830();
      piStack_4 = piVar3;
      FUN_00406880();
      piStack_4 = (int *)0xffffffff;
      if (uStack_2c < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_40);
      return;
    }
    piVar4 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
    if (piVar4 == (int *)0x0) {
      FUN_00401830();
      piStack_4 = (int *)0x1;
      FUN_00406880();
      piStack_4 = (int *)0xffffffff;
      if (uStack_2c < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_40);
      return;
    }
    iVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
    if (iVar5 != param_1) {
      (**(code **)(*piVar4 + 0x74))();
      FUN_00401830();
      piStack_4 = (int *)0x2;
      (**(code **)(*DAT_00b5a7b4 + 0x44))();
      FUN_00401660();
      piStack_4 = (int *)CONCAT31(piStack_4._1_3_,3);
      piVar4 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))();
      if (piVar4 != (int *)0x0) {
        iVar5 = (**(code **)(*piVar4 + 0xc))();
        if (iVar5 == 0) {
          piVar4 = (int *)(**(code **)(*piVar4 + 0x14))();
          piVar4 = (int *)(**(code **)(*piVar4 + 0x24))();
          iVar5 = *piVar4;
          (**(code **)(*DAT_00b5a6ac + 0x20))();
          (**(code **)(iVar5 + 0x1c))();
          FUN_00401830();
          local_c._0_1_ = 4;
          (**(code **)(*piVar3 + 4))();
          pvVar6 = operator_new(0x28);
          local_c._0_1_ = 5;
          if (pvVar6 != (void *)0x0) {
            FUN_00765c50();
            FUN_0078e5e0();
          }
          local_c = (void *)CONCAT31(local_c._1_3_,4);
          (**(code **)(*piVar3 + 8))();
          pvVar6 = operator_new(0x58);
          uStack_14 = 6;
          if (pvVar6 != (void *)0x0) {
            FUN_00765c50();
            uStack_14 = 7;
            FUN_00765c50();
            uStack_14 = 8;
            FUN_00765c50(auStack_38);
            uStack_14 = 6;
            FUN_0078e2d0();
          }
          uStack_14 = 4;
          (**(code **)(*piVar3 + 8))();
          pvVar6 = operator_new(0x20);
          uStack_1c = 9;
          if (pvVar6 != (void *)0x0) {
            FUN_00765c50();
            FUN_0078e170();
          }
          uStack_1c = 4;
          (**(code **)(*piVar3 + 8))();
          pvVar6 = operator_new(0x20);
          uStack_24 = 10;
          if (pvVar6 != (void *)0x0) {
            FUN_00765c50();
            FUN_0078e050();
          }
          uStack_24 = 4;
          (**(code **)(*piVar3 + 8))();
          pvVar6 = operator_new(0x20);
          uStack_2c._0_1_ = 0xb;
          if (pvVar6 == (void *)0x0) {
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = (int *)FUN_0078df90();
          }
          uStack_2c = CONCAT31(uStack_2c._1_3_,4);
          (**(code **)(*piVar3 + 8))();
          pvVar6 = operator_new(8);
          uVar2 = uStack_2c;
          uStack_34 = 0xc;
          if (pvVar6 != (void *)0x0) {
            FUN_0078deb0();
          }
          uStack_34 = 4;
          (**(code **)(*piVar3 + 8))();
          pvVar6 = operator_new(8);
          if (pvVar6 != (void *)0x0) {
            FUN_0078de40();
          }
          (**(code **)(*piVar3 + 8))();
          puVar7 = (undefined4 *)(**(code **)(*piVar3 + 0x24))();
          *puVar7 = uVar2;
          (**(code **)(*piVar3 + 0x24))();
          FUN_00401660();
          (**(code **)(*piVar4 + 0x18))();
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        iVar5 = (**(code **)(*piVar4 + 0xc))();
        if (iVar5 == 6) {
          (**(code **)(*piStack_90 + 0x18))();
        }
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00758e50 @ 0x00758e50 ====

undefined4 FUN_00758e50(void)

{
  return 0x70070000;
}


// ==== FUN_00758e60 @ 0x00758e60 ====

undefined4 FUN_00758e60(void)

{
  return 0x70070001;
}


// ==== FUN_00758e70 @ 0x00758e70 ====

undefined4 FUN_00758e70(void)

{
  return 0x70070002;
}


// ==== FUN_00758e80 @ 0x00758e80 ====

void FUN_00758e80(void)

{
  FUN_00758e90();
  return;
}


// ==== FUN_00758e90 @ 0x00758e90 ====

void FUN_00758e90(byte param_1)

{
  void *in_ECX;
  
  FUN_007588f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00758eb0 @ 0x00758eb0 ====

void FUN_00758eb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f28d8;
  return;
}


// ==== FUN_00758ec0 @ 0x00758ec0 ====

void FUN_00758ec0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f28d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00758ee0 @ 0x00758ee0 ====

undefined4 FUN_00758ee0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00758ef0 @ 0x00758ef0 ====

undefined4 FUN_00758ef0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00758f00 @ 0x00758f00 ====

void FUN_00758f00(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00758f10 @ 0x00758f10 ====

undefined1 FUN_00758f10(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_00758f20 @ 0x00758f20 ====

void FUN_00758f20(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x10);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*(int *)puVar3[3] + 4))();
    if (*(char *)((int)puVar3 + 0x11) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x11) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x11);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x11);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x11);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x11);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_00758f80 @ 0x00758f80 ====

void FUN_00758f80(undefined1 param_1)

{
  undefined1 local_8 [8];
  
  FUN_00752030(local_8,&param_1);
  return;
}


// ==== FUN_00758fa0 @ 0x00758fa0 ====

void FUN_00758fa0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00994483;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f28fc;
  local_4 = 1;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  DAT_00b5af04 = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_007520f0(local_10,*(undefined4 *)in_ECX[4],(undefined4 *)in_ECX[4]);
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_00759030 @ 0x00759030 ====

void FUN_00759030(undefined1 param_1)

{
  FUN_00752400(&param_1);
  return;
}


// ==== FUN_00759040 @ 0x00759040 ====

void FUN_00759040(void)

{
  undefined4 *puVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009944ab;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f28fc;
  *(undefined1 *)(in_ECX + 2) = 0;
  iVar2 = FUN_00751a80();
  in_ECX[4] = iVar2;
  *(undefined1 *)(iVar2 + 0x11) = 1;
  *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
  *(undefined4 *)in_ECX[4] = in_ECX[4];
  *(undefined4 *)(in_ECX[4] + 8) = in_ECX[4];
  in_ECX[5] = 0;
  puVar1 = in_ECX + 1;
  local_4._0_1_ = 1;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5af04 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5af04 = in_ECX;
  }
  pvVar3 = operator_new(0x44);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar3 == (void *)0x0) {
    *puVar1 = 0;
    ExceptionList = local_c;
    return;
  }
  uVar4 = FUN_0078e910();
  *puVar1 = uVar4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00759100 @ 0x00759100 ====

void FUN_00759100(byte param_1)

{
  void *in_ECX;
  
  FUN_00758fa0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00759120 @ 0x00759120 ====

void FUN_00759120(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f29bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00759140 @ 0x00759140 ====

void FUN_00759140(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f29dc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a784 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a784 = in_ECX;
  return;
}


// ==== FUN_00759190 @ 0x00759190 ====

void FUN_00759190(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a784 = 0;
  *in_ECX = &PTR_FUN_009f29bc;
  return;
}


// ==== FUN_007591b0 @ 0x007591b0 ====

void FUN_007591b0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  piVar1 = *(int **)(iVar2 + 0x1c);
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  if (iVar2 != 0) {
    (**(code **)(*piVar1 + 0x18))();
  }
  (**(code **)(*piVar1 + 0x14))(param_1);
  (**(code **)(*DAT_00b5a790 + 8))();
  return;
}


// ==== FUN_007591f0 @ 0x007591f0 ====

void FUN_007591f0(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009944c8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar2 != 0) {
    FUN_00829990(iVar2,param_1);
    (**(code **)(*DAT_00b5a790 + 4))();
    ExceptionList = pvStack_c;
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pPC____NULL_009f2958,0xb);
  uStack_4 = 0;
  FUN_00406880(auStack_28);
  uStack_4 = 0xffffffff;
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_007592b0 @ 0x007592b0 ====

void FUN_007592b0(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009944e2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f2964,0xb);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  if (*(int **)(iVar2 + 0x1c) != (int *)0x0) {
    uVar3 = (**(code **)(**(int **)(iVar2 + 0x1c) + 0x1c))
                      (0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
    FUN_00803725(uVar3);
    ExceptionList = pvStack_c;
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pCursor____NULL_009f2970,0xf);
  uStack_4 = 1;
  FUN_00406880(auStack_44);
  uStack_4 = 0xffffffff;
  if (uStack_2c < 0x10) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_007593d0 @ 0x007593d0 ====

void FUN_007593d0(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009944fc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f2980,0xb);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  if (*(int **)(iVar2 + 0x1c) != (int *)0x0) {
    uVar3 = (**(code **)(**(int **)(iVar2 + 0x1c) + 0x18))
                      (0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
    iVar2 = FUN_00803725(uVar3);
    if (iVar2 != 0) {
      (**(code **)(*DAT_00b5a730 + 0x10))(1,iVar2);
    }
    (**(code **)(*DAT_00b5a790 + 8))();
    ExceptionList = pvStack_c;
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pCursor____NULL_009f298c,0xf);
  uStack_4 = 1;
  FUN_00406880(auStack_44);
  uStack_4 = 0xffffffff;
  if (uStack_2c < 0x10) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_00759500 @ 0x00759500 ====

void FUN_00759500(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099450e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 != 0) {
    FUN_00829a60(iVar2,param_1);
    (**(code **)(*DAT_00b5a790 + 4))();
    ExceptionList = pvStack_c;
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pPC____NULL_009f299c,0xb);
  uStack_4 = 0;
  FUN_00406880(auStack_28);
  uStack_4 = 0xffffffff;
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_007595c0 @ 0x007595c0 ====

void FUN_007595c0(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994520;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 != 0) {
    FUN_00827bf0(iVar2,param_1);
    (**(code **)(*DAT_00b5a790 + 4))();
    ExceptionList = pvStack_c;
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pPC____NULL_009f29a8,0xb);
  uStack_4 = 0;
  FUN_00406880(auStack_28);
  uStack_4 = 0xffffffff;
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_00759680 @ 0x00759680 ====

void FUN_00759680(byte param_1)

{
  void *in_ECX;
  
  FUN_00759190();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007596a0 @ 0x007596a0 ====

void FUN_007596a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f2e30;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007596d0 @ 0x007596d0 ====

void FUN_007596d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f2e3c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a788 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a788 = in_ECX;
  return;
}


// ==== FUN_00759740 @ 0x00759740 ====

void FUN_00759740(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x24) != (int *)0x0)) {
    iVar1 = (**(code **)(**(int **)(iVar1 + 0x24) + 0x20))(*(undefined4 *)(param_1 + 0x10));
    if (iVar1 != 0) {
      (**(code **)(*DAT_00b5ad20 + 0x10))(iVar1);
      (**(code **)(*DAT_00b5a790 + 4))();
      (**(code **)(*DAT_00b5ad58 + 0xc))();
      (**(code **)(*DAT_00b5ad58 + 8))();
      (**(code **)(*DAT_00b5ad1c + 8))();
    }
  }
  return;
}


// ==== FUN_007597b0 @ 0x007597b0 ====

void FUN_007597b0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a788 = 0;
  *in_ECX = &PTR_FUN_009f2e30;
  return;
}


// ==== FUN_007597d0 @ 0x007597d0 ====

void FUN_007597d0(int param_1)

{
  char cVar1;
  undefined3 *puVar2;
  int iVar3;
  undefined1 extraout_var;
  void *pvStack_150;
  uint uStack_13c;
  undefined4 uStack_138;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099455c;
  pvStack_c = ExceptionList;
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\0') {
    uStack_138 = (code *)0x759809;
    ExceptionList = &pvStack_c;
    puVar2 = (undefined3 *)(**(code **)(*DAT_00b5a78c + 0x4c))();
    uStack_138 = (code *)0x759816;
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar3 == 0) {
      ExceptionList = pvStack_c;
      return;
    }
    uStack_138 = (code *)CONCAT13(extraout_var,*puVar2);
    FUN_00829da0();
    uStack_138 = FUN_006e0000 + 2;
    uStack_13c = 0;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0x0;
    FUN_00401660((int)register0x00000010 + -0x134,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    (**(code **)(*DAT_00b5aef0 + 0xc))();
  }
  else {
    iVar3 = *DAT_00b5a794;
    if (cVar1 == '\x01') {
      uStack_138 = (code *)0x650009;
      uStack_13c = 5;
      ExceptionList = &pvStack_c;
      (**(code **)(iVar3 + 0xc))();
      FUN_00401660();
      pvStack_c = (void *)0x1;
    }
    else if (cVar1 == '\x02') {
      uStack_138 = (code *)&DAT_006e0088;
      uStack_13c = 0;
      ExceptionList = &pvStack_c;
      (**(code **)(iVar3 + 0xc))();
      FUN_00401660();
      pvStack_c = (void *)0x2;
    }
    else {
      uStack_138 = FUN_006e0000 + 3;
      uStack_13c = 0;
      ExceptionList = &pvStack_c;
      (**(code **)(iVar3 + 0xc))();
      FUN_00401660();
      pvStack_c = (void *)0x3;
    }
    FUN_00401660((int)register0x00000010 + -0x134,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  if (uStack_13c < 0x10) {
    (**(code **)(*DAT_00b5af2c + 8))(0);
    FUN_0044a580(&uStack_138,&DAT_009f2e14,s_RECEIVE______ITEMPACKETS__SA_Pic_009f2a34);
    FUN_00797b80(&uStack_138);
    (**(code **)(*DAT_00b5aef8 + 4))();
    ExceptionList = pvStack_c;
    return;
  }
  _free(pvStack_150);
  return;
}


// ==== FUN_007599f0 @ 0x007599f0 ====

void FUN_007599f0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined1 auStack_158 [32];
  void *pvStack_128;
  uint uStack_114;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994587;
  pvStack_c = ExceptionList;
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\0') {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a78c + 0x4c))();
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar2 == 0) {
      ExceptionList = pvStack_c;
      return;
    }
    FUN_00829e20();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0x0;
    FUN_00401660(auStack_158 + 0x24,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    (**(code **)(*DAT_00b5aef0 + 0xc))();
  }
  else {
    if (cVar1 == '\x03') {
      ExceptionList = &pvStack_c;
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      pvStack_c = (void *)0x1;
    }
    else {
      ExceptionList = &pvStack_c;
      if (cVar1 != '\x01') goto LAB_00759ba6;
      ExceptionList = &pvStack_c;
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      pvStack_c = (void *)0x2;
    }
    FUN_00401660(auStack_158 + 0x24,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  if (0xf < uStack_114) {
    uStack_4 = 0xffffffff;
    _free(pvStack_128);
    return;
  }
LAB_00759ba6:
  uStack_4 = 0xffffffff;
  (**(code **)(*DAT_00b5af2c + 8))();
  FUN_0044a580();
  FUN_00797b80();
  (**(code **)(*DAT_00b5aef8 + 4))();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00759c00 @ 0x00759c00 ====

void FUN_00759c00(int param_1)

{
  undefined1 auStack_6c [4];
  undefined1 uStack_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  void *pvStack_40;
  undefined1 auStack_30 [4];
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009945a1;
  local_c = ExceptionList;
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0x33:
    break;
  case 0x34:
    break;
  case 0x35:
    break;
  case 0x36:
    break;
  case 0x37:
    break;
  case 0x38:
    break;
  case 0x39:
    break;
  default:
    goto switchD_00759c34_caseD_3a;
  case 100:
    goto LAB_00759cf3;
  case 0x65:
    goto LAB_00759cf3;
  case 0x66:
    goto LAB_00759cf3;
  case 0x67:
    goto LAB_00759cf3;
  case 0x68:
LAB_00759cf3:
    uStack_50 = 0;
    uStack_54 = 0x759d02;
    ExceptionList = &local_c;
    uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_54 = 0xffffffff;
    uStack_58 = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    uStack_2c = uStack_2c & 0xffffff00;
    uStack_60 = 0x759d1f;
    FUN_00401660();
    puStack_4 = auStack_6c;
    uStack_54 = 0xf;
    uStack_58 = 0;
    local_c = (void *)0x1;
    uStack_68 = 0;
    FUN_00401660(auStack_30,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(0);
    if (uStack_10 < 0x10) {
      ExceptionList = local_c;
      return;
    }
    goto LAB_00759d61;
  }
  uStack_50 = 8;
  uStack_54 = 0x759c4e;
  ExceptionList = &local_c;
  uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_54 = 0xffffffff;
  uStack_58 = 0;
  uStack_60 = 0x759c6d;
  FUN_00401660();
  puStack_4 = auStack_6c;
  uStack_54 = 0xf;
  uStack_58 = 0;
  local_c = (void *)0x0;
  uStack_68 = 0;
  FUN_00401660(auStack_30 + -0x1c,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (uStack_2c < 0x10) {
switchD_00759c34_caseD_3a:
    ExceptionList = local_c;
    return;
  }
  pvStack_24 = pvStack_40;
LAB_00759d61:
  uStack_50 = 0x759d67;
  _free(pvStack_24);
  return;
}


// ==== FUN_00759e10 @ 0x00759e10 ====

void FUN_00759e10(void)

{
  undefined4 uVar1;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  int iStack_24;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009945b3;
  pvStack_c = ExceptionList;
  uStack_34 = (undefined1 *)0x6e0017;
  uStack_38 = 0;
  uStack_3c = 0x759e3c;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x759e59;
  FUN_00401660();
  uStack_34 = auStack_54;
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_c = (void *)0x0;
  uStack_50 = 0;
  FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  uVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  FUN_00829ed0(uVar1,*(undefined2 *)(iStack_24 + 0x10),*(undefined4 *)(iStack_24 + 0x14));
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  if (uStack_38 < 0x10) {
    ExceptionList = uStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_00759ef0 @ 0x00759ef0 ====

void FUN_00759ef0(void)

{
  undefined4 uVar1;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  int iStack_24;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009945c5;
  pvStack_c = ExceptionList;
  uStack_34 = (undefined1 *)0x6e0018;
  uStack_38 = 0;
  uStack_3c = 0x759f1c;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x759f39;
  FUN_00401660();
  uStack_34 = auStack_54;
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_c = (void *)0x0;
  uStack_50 = 0;
  FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  uVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  FUN_00829a60(uVar1,*(undefined4 *)(iStack_24 + 0x10));
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  if (uStack_38 < 0x10) {
    ExceptionList = uStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_00759fd0 @ 0x00759fd0 ====

void FUN_00759fd0(void)

{
  undefined4 uVar1;
  undefined1 auStack_54 [4];
  undefined1 uStack_50;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined4 uStack_34;
  int iStack_24;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009945d7;
  pvStack_c = ExceptionList;
  uStack_34 = (undefined1 *)0x6e0019;
  uStack_38 = 0;
  uStack_3c = 0x759ffc;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x75a019;
  FUN_00401660();
  uStack_34 = auStack_54;
  uStack_3c = 0xf;
  uStack_40 = 0;
  pvStack_c = (void *)0x0;
  uStack_50 = 0;
  FUN_00401660(auStack_54 + 0x24,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  uVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  FUN_00827bf0(uVar1,*(undefined4 *)(iStack_24 + 0x10));
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  if (uStack_38 < 0x10) {
    ExceptionList = uStack_34;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_0075a0b0 @ 0x0075a0b0 ====

void FUN_0075a0b0(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined1 auStack_1f8 [4];
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined1 *puStack_1ec;
  char *pcStack_1e8;
  undefined **ppuStack_1e4;
  int *piStack_1e0;
  int *piStack_1dc;
  undefined4 *puStack_1d8;
  int *piStack_1d4;
  undefined4 *puStack_1d0;
  undefined1 *puStack_1cc;
  undefined1 *puStack_1c8;
  undefined *puStack_1c4;
  char *pcStack_1c0;
  undefined1 auStack_1a6 [6];
  void *pvStack_1a0;
  undefined4 uStack_19c;
  undefined4 uStack_198;
  undefined4 auStack_194 [2];
  uint uStack_18c;
  undefined1 auStack_180 [48];
  undefined1 auStack_150 [64];
  undefined1 auStack_110 [228];
  undefined4 uStack_2c;
  undefined1 uStack_24;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994670;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a7b8 + 0x28))();
  iVar3 = (-(uint)(iVar3 != 0) & 2) + 2;
  switch(*(undefined1 *)(param_1 + 0x41)) {
  case 0:
    pcStack_1c0 = (char *)0x0;
    puStack_1c4 = (undefined *)0x75a114;
    puStack_1c4 = (undefined *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_1c8 = (undefined1 *)0x75a11e;
    FUN_00765c50();
    puStack_1c4 = (undefined *)0x0;
    puStack_1c8 = (undefined1 *)0x1;
    pvStack_c = (void *)0x0;
    puStack_1cc = (undefined1 *)0x75a133;
    piVar4 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
    puStack_1cc = (undefined1 *)(param_1 + 0x10);
    puStack_1d0 = (undefined4 *)0x75a140;
    (**(code **)(*piVar4 + 8))();
    auStack_194[0] = *(undefined4 *)(param_1 + 0x3c);
    uStack_19c = *(undefined4 *)(param_1 + 0x34);
    uStack_198 = *(undefined4 *)(param_1 + 0x38);
    puStack_1d0 = &uStack_19c;
    piStack_1d4 = (int *)0x75a161;
    (**(code **)(*piVar4 + 0x78))();
    piStack_1d4 = (int *)0x0;
    puStack_1d8 = (undefined4 *)0x0;
    piStack_1dc = (int *)0x0;
    piStack_1e0 = (int *)0x0;
    ppuStack_1e4 = (undefined **)0xa;
    pcStack_1e8 = (char *)0x75a16c;
    FUN_004dd240();
    puStack_1d8 = auStack_194;
    piStack_1dc = (int *)0x75a180;
    piStack_1d4 = piVar4;
    (**(code **)(*DAT_00b5ad20 + 0x40))();
    piStack_1dc = (int *)0xffffffff;
    piStack_1e0 = (int *)0x0;
    ppuStack_1e4 = &puStack_1c4;
    uStack_24 = 1;
    pcStack_1e8 = (char *)0x75a199;
    FUN_00401ff0();
    if (*(char *)(param_1 + 0x40) != '\0') {
      if (*(char *)(param_1 + 0x40) != '\x01') {
        piStack_1dc = (int *)s_FALSE_009f2acc;
        piStack_1e0 = (int *)0x75a2b2;
        FUN_00401830();
        piStack_1dc = (int *)auStack_180;
        uStack_24 = 4;
        piStack_1e0 = (int *)0x75a2c4;
        FUN_00406880();
        uStack_24 = 1;
                    /* WARNING: Subroutine does not return */
        piStack_1dc = (int *)0x75a2d8;
        FUN_00446f10();
      }
      piStack_1e0 = (int *)0x75a282;
      piStack_1dc = piVar4;
      piStack_1e0 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
      ppuStack_1e4 = (undefined **)0x75a288;
      FUN_00827e80();
      piStack_1dc = (int *)0x75a296;
      (**(code **)(*DAT_00b5ad1c + 8))();
      piStack_1dc = (int *)0x0;
      piStack_1e0 = (int *)0x75a2a2;
      (**(code **)(*DAT_00b5a9e4 + 0x2c))();
LAB_0075a2d9:
      puStack_1cc = auStack_1f8;
      FUN_00765c50(&pvStack_1a0);
      (**(code **)(*DAT_00b5ad0c + 0x28))(iVar3);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    piStack_1dc = (int *)0x75a1af;
    iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
    if ((iVar5 != 0) && (piVar1 = *(int **)(iVar5 + 0x1c), piVar1 != (int *)0x0)) {
      piStack_1dc = (int *)0x75a1c2;
      iVar5 = (**(code **)(*piVar1 + 0x1c))();
      if (iVar5 == 0) {
        piStack_1e0 = (int *)0x75a1e6;
        piStack_1dc = piVar4;
        cVar2 = (**(code **)(*piVar1 + 0x14))();
        if (cVar2 == '\0') {
          ppuStack_1e4 = (undefined **)0x75a1fa;
          piStack_1e0 = piVar4;
          (**(code **)(*DAT_00b5ad20 + 0x10))();
          ppuStack_1e4 = (undefined **)s_____Inven_NetHandler_cpp_461__009f2a7c;
          pcStack_1e8 = (char *)0x75a208;
          ppuStack_1e4 = (undefined **)FUN_00401830();
          puStack_1ec = auStack_150;
          pcStack_1e8 = s_Cannot_Pick_to_Cursor_009f2a9c;
          uStack_2c._0_1_ = 2;
          uStack_1f0 = 0x75a223;
          uStack_1f0 = FUN_004022a0();
          uStack_2c = CONCAT31(uStack_2c._1_3_,3);
          uStack_1f4 = 0x75a231;
          FUN_00796d50();
                    /* WARNING: Subroutine does not return */
          ppuStack_1e4 = (undefined **)0x75a240;
          FUN_00446f10();
        }
        goto LAB_0075a2d9;
      }
    }
                    /* WARNING: Subroutine does not return */
    piStack_1dc = (int *)0x75a1cf;
    FUN_00446f10();
  case 1:
    pcStack_1c0 = (char *)0x0;
    puStack_1c4 = (undefined *)0x75a32b;
    puStack_1c4 = (undefined *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_1c8 = (undefined1 *)0x75a335;
    FUN_00765c50();
    pvStack_c = (void *)0x5;
    break;
  case 2:
    pcStack_1c0 = (char *)0x0;
    puStack_1c4 = (undefined *)0x75a356;
    puStack_1c4 = (undefined *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_1c8 = (undefined1 *)0x75a360;
    FUN_00765c50();
    pvStack_c = (void *)0x6;
    goto LAB_0075a430;
  case 3:
    pcStack_1c0 = (char *)0x0;
    puStack_1c4 = (undefined *)0x75a381;
    puStack_1c4 = (undefined *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_1c8 = (undefined1 *)0x75a38b;
    FUN_00765c50();
    pvStack_c = (void *)0x7;
    break;
  case 4:
    pcStack_1c0 = (char *)0x0;
    puStack_1c4 = (undefined *)0x75a3a9;
    puStack_1c4 = (undefined *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_1c8 = (undefined1 *)0x75a3b3;
    FUN_00765c50();
    pvStack_c = (void *)0x8;
    goto LAB_0075a430;
  case 6:
  case 9:
    pcStack_1c0 = (char *)0x0;
    puStack_1c4 = (undefined *)0x75a465;
    puStack_1cc = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_1c4 = (undefined *)0xffffffff;
    puStack_1c8 = (undefined1 *)0x0;
    auStack_194[0] = 0xf;
    uStack_198 = 0;
    puStack_1d0 = (undefined4 *)0x75a483;
    FUN_00401660();
    piStack_1e0 = (int *)0xffffffff;
    ppuStack_1e4 = (undefined **)0x0;
    pcStack_1e8 = auStack_1a6 + -6;
    puStack_1c4 = (undefined *)0xf;
    puStack_1c8 = (undefined1 *)0x0;
    pvStack_c = (void *)0xb;
    puStack_1d8 = (undefined4 *)((uint)puStack_1d8 & 0xffffff00);
    puStack_1ec = (undefined1 *)0x75a4ad;
    FUN_00401660();
    ppuStack_1e4 = (undefined **)0x75a4b9;
    piStack_1e0 = (int *)iVar3;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_0075a301;
  case 7:
    pcStack_1c0 = (char *)0x0;
    puStack_1c4 = (undefined *)0x75a3d1;
    puStack_1c4 = (undefined *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_1c8 = (undefined1 *)0x75a3db;
    FUN_00765c50();
    pvStack_c = (void *)0x9;
    break;
  case 8:
    pcStack_1c0 = (char *)0x0;
    puStack_1c4 = (undefined *)0x75a41b;
    puStack_1c4 = (undefined *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_1c8 = (undefined1 *)0x75a425;
    FUN_00765c50();
    pvStack_c = (void *)0xa;
LAB_0075a430:
    piStack_1e0 = (int *)(auStack_1a6 + -6);
    ppuStack_1e4 = (undefined **)0x75a443;
    FUN_00765c50();
    ppuStack_1e4 = (undefined **)0x75a44f;
    piStack_1e0 = (int *)iVar3;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_0075a301;
  default:
    pcStack_1c0 = (char *)0x0;
    puStack_1c4 = (undefined *)0x75a4cf;
    puStack_1cc = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_1c4 = (undefined *)0xffffffff;
    puStack_1c8 = (undefined1 *)0x0;
    auStack_194[0] = 0xf;
    uStack_198 = 0;
    puStack_1d0 = (undefined4 *)0x75a4ed;
    FUN_00401660();
    piStack_1e0 = (int *)0xffffffff;
    ppuStack_1e4 = (undefined **)0x0;
    pcStack_1e8 = auStack_1a6 + -6;
    puStack_1c4 = (undefined *)0xf;
    puStack_1c8 = (undefined1 *)0x0;
    pvStack_c = (void *)0xc;
    puStack_1d8 = (undefined4 *)((uint)puStack_1d8 & 0xffffff00);
    puStack_1ec = (undefined1 *)0x75a517;
    FUN_00401660();
    ppuStack_1e4 = (undefined **)0x75a523;
    piStack_1e0 = (int *)iVar3;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_4 = 0xffffffff;
    if (0xf < uStack_18c) {
      pcStack_1c0 = (char *)0x75a53f;
      _free(pvStack_1a0);
      return;
    }
  case 5:
    (**(code **)(*DAT_00b5a790 + 4))();
    (**(code **)(*DAT_00b5ad58 + 0xc))();
    (**(code **)(*DAT_00b5a790 + 8))();
    pcStack_1c0 = (char *)0x75a56f;
    (**(code **)(*DAT_00b5af2c + 8))();
    pcStack_1c0 = s_RECEIVE______ITEMPACKETS__SA_Pic_009f2ad4;
    puStack_1c8 = auStack_110;
    puStack_1c4 = &DAT_009f2e14;
    puStack_1cc = (undefined1 *)0x75a586;
    FUN_0044a580();
    puStack_1cc = auStack_110;
    puStack_1d0 = (undefined4 *)0x75a593;
    FUN_00797b80();
    ExceptionList = pvStack_10;
    return;
  }
  piStack_1e0 = (int *)(auStack_1a6 + -6);
  ppuStack_1e4 = (undefined **)0x75a3f9;
  FUN_00765c50();
  ppuStack_1e4 = (undefined **)0x75a405;
  piStack_1e0 = (int *)iVar3;
  (**(code **)(*DAT_00b5ad0c + 0x28))();
LAB_0075a301:
  uStack_2c = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  ppuStack_1e4 = (undefined **)0x75a315;
  FUN_00446f10();
}


// ==== FUN_0075a5e0 @ 0x0075a5e0 ====

void FUN_0075a5e0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  undefined1 auStack_146 [6];
  void *pvStack_140;
  undefined4 uStack_130;
  uint uStack_12c;
  void *pvStack_124;
  undefined4 uStack_114;
  uint uStack_110;
  undefined4 uStack_2c;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009946d2;
  pvStack_c = ExceptionList;
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\0') {
    ExceptionList = &pvStack_c;
    piVar2 = (int *)(**(code **)(*DAT_00b5ad20 + 4))();
    if (piVar2 == (int *)0x0) {
      uStack_12c = 0xf;
      uStack_130 = 0;
      pvStack_140 = (void *)((uint)pvStack_140 & 0xffffff00);
      FUN_00401740();
      local_4 = 1;
      FUN_004022a0();
      local_4 = CONCAT31(local_4._1_3_,2);
      FUN_00796d50();
      if (0xf < uStack_110) {
        _free(pvStack_124);
        return;
      }
      uStack_110 = 0xf;
      uStack_114 = 0;
      pvStack_124 = (void *)((uint)pvStack_124 & 0xffffff00);
      local_4 = 0xffffffff;
      if (0xf < uStack_12c) {
        _free(pvStack_140);
        return;
      }
      goto LAB_0075a981;
    }
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0x0;
    iVar3 = (**(code **)(*piVar2 + 0x2c))();
    pcVar4 = (char *)(iVar3 + 0x32);
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_004020e0();
    FUN_004020e0();
    FUN_00401660(auStack_146 + -6,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    (**(code **)(*DAT_00b5ad20 + 0x10))(piVar2);
  }
  else {
    if (cVar1 != '\x05') {
      if (cVar1 != '\x01') {
        if (cVar1 == '\x04') {
          ExceptionList = &pvStack_c;
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          pvStack_c = (void *)0x5;
          FUN_00765c50(&uStack_130);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
        }
        else {
          if (cVar1 != '\x03') {
            ExceptionList = &pvStack_c;
            FUN_00401830();
            local_4 = 7;
            FUN_00406880();
            local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
            FUN_00446f10();
          }
          ExceptionList = &pvStack_c;
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          pvStack_c = (void *)0x6;
          FUN_00765c50(&uStack_130);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
        }
        uStack_2c = 0xffffffff;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      ExceptionList = &pvStack_c;
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      pvStack_c = (void *)0x4;
      FUN_00401660(auStack_146 + -6,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      local_4 = 0xffffffff;
      if (0xf < uStack_12c) {
        _free(pvStack_140);
        return;
      }
      goto LAB_0075a981;
    }
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    pvStack_c = (void *)0x3;
    FUN_00401660(auStack_146 + -6,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  local_4 = 0xffffffff;
  if (0xf < uStack_12c) {
    _free(pvStack_140);
    return;
  }
LAB_0075a981:
  local_4 = 0xffffffff;
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  (**(code **)(*DAT_00b5a790 + 8))();
  (**(code **)(*DAT_00b5af2c + 8))();
  FUN_0044a580();
  FUN_00797b80();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0075a9f0 @ 0x0075a9f0 ====

/* WARNING: Removing unreachable block (ram,0x0075ab19) */

void FUN_0075a9f0(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_42 [26];
  undefined1 auStack_28 [4];
  void *pvStack_24;
  void *pvStack_18;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009946f4;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24._1_3_ << 8);
    FUN_00401740(s_pPC____NULL_009f2b60,0xb);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  if (*(int **)(iVar2 + 0x78) == (int *)0x0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24._1_3_ << 8);
    FUN_00401740(s_pCoolTimeManager____NULL_009f2b6c,0x18);
    uStack_4 = 1;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x78) + 0x20))(*(undefined1 *)(param_1 + 0x14));
  if (piVar3 == (int *)0x0) {
    FUN_00401740(s_pCoolTime____NULL_009f2b88,0x11);
    puStack_8 = (undefined1 *)0x2;
    FUN_00406880(auStack_42 + -6);
    puStack_8 = (undefined1 *)0xffffffff;
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  iVar2 = *piVar3;
  iVar4 = FUN_004244f0();
  uVar5 = FUN_004244f0(iVar4 + *(int *)(param_1 + 0x10));
  (**(code **)(iVar2 + 8))(uVar5);
  ExceptionList = pvStack_18;
  return;
}


// ==== FUN_0075ab70 @ 0x0075ab70 ====

void FUN_0075ab70(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  uint unaff_EDI;
  void *pvStack_16c;
  undefined1 auStack_146 [14];
  undefined4 uStack_138;
  undefined4 uStack_134;
  void *pvStack_130;
  uint uStack_11c;
  void *pvStack_3c;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  int iStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099474b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a7b8 + 0x28))();
  cVar1 = *(char *)(param_1 + 0x14);
  if (cVar1 == '\0') {
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x20) + 0x54))();
    (**(code **)(*piVar4 + 0xc))();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_138 = 0xf;
    FUN_00401660();
    iStack_10 = 0;
    FUN_004041a0();
    iStack_10._0_1_ = 1;
    FUN_00401ff0();
    iStack_10 = (uint)iStack_10._1_3_ << 8;
    if (0xf < uStack_11c) {
      _free(pvStack_130);
      return;
    }
    FUN_004020e0();
    FUN_004dd240();
    pvStack_16c = (void *)0x0;
    FUN_00401660(auStack_146 + -10,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))((-(iVar2 != 0) & 2U) + 2);
LAB_0075ac9e:
    uStack_30 = 0xffffffff;
    if (unaff_EDI < 0x10) {
      (**(code **)(*DAT_00b5a790 + 4))();
      (**(code **)(*DAT_00b5ad58 + 0xc))();
      (**(code **)(*DAT_00b5a790 + 8))();
      FUN_0044a580(&uStack_138,&DAT_009f2e14,s_RECEIVE______MONEYPACKETS__SA_Pi_009f2ba4);
      FUN_00797b80(&uStack_138);
      (**(code **)(*DAT_00b5af2c + 8))(0);
      ExceptionList = pvStack_3c;
      return;
    }
    _free(pvStack_16c);
    return;
  }
  if (cVar1 == '\x01') {
    pvStack_16c = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_134 = 0xf;
    uStack_138 = 0;
    FUN_00401660();
    pvStack_c = (void *)0x2;
    FUN_00401660(auStack_146 + -6,0);
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_0075ac9e;
  }
  if (cVar1 == '\x02') {
    pvStack_16c = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_134 = 0xf;
    uStack_138 = 0;
    FUN_00401660();
    pvStack_c = (void *)0x3;
    FUN_00401660(auStack_146 + -6,0);
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    goto LAB_0075ac9e;
  }
  if (cVar1 == '\x03') {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x4;
  }
  else {
    if (cVar1 == '\x04') {
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00765c50();
      pvStack_c = (void *)0x5;
      FUN_00765c50();
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      goto LAB_0075ae4b;
    }
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00765c50();
    pvStack_c = (void *)0x6;
  }
  FUN_00765c50();
  (**(code **)(*DAT_00b5ad0c + 0x28))();
LAB_0075ae4b:
  uStack_2c = 0xffffffff;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_0075aed0 @ 0x0075aed0 ====

void FUN_0075aed0(int param_1)

{
  int *piVar1;
  undefined1 auStack_18c [4];
  undefined1 uStack_188;
  undefined4 uStack_180;
  undefined1 *puStack_17c;
  undefined4 uStack_178;
  int *piStack_174;
  undefined **ppuStack_170;
  int *piStack_16c;
  int iStack_168;
  undefined1 *puStack_164;
  undefined1 *puStack_160;
  undefined *puStack_15c;
  undefined1 auStack_148 [4];
  void *pvStack_144;
  undefined4 uStack_134;
  uint uStack_130;
  undefined1 *puStack_12c;
  void *pvStack_128;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  uint uStack_114;
  undefined1 auStack_10c [236];
  undefined1 uStack_20;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099476b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(char *)(param_1 + 0x34) == '\0') {
    puStack_15c = (undefined *)0x0;
    puStack_160 = (undefined1 *)0x75af11;
    ExceptionList = &pvStack_c;
    iStack_168 = (**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_160 = (undefined1 *)0xffffffff;
    puStack_164 = (undefined1 *)0x0;
    uStack_11c = 0xf;
    uStack_120 = 0;
    uStack_130 = uStack_130 & 0xffffff00;
    piStack_16c = (int *)0x75af2e;
    FUN_00401660();
    puStack_160 = (undefined1 *)0x0;
    puStack_164 = (undefined1 *)0x1;
    pvStack_c = (void *)0x0;
    iStack_168 = 0x75af43;
    piVar1 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
    iStack_168 = param_1 + 0x10;
    piStack_16c = (int *)0x75af50;
    (**(code **)(*piVar1 + 8))();
    piStack_16c = (int *)0x0;
    ppuStack_170 = (undefined **)0x0;
    piStack_174 = (int *)0x0;
    uStack_178 = 0;
    puStack_17c = (undefined1 *)0xa;
    uStack_180 = 0x75af5b;
    FUN_004dd240();
    ppuStack_170 = &puStack_15c;
    piStack_174 = (int *)0x75af6f;
    piStack_16c = piVar1;
    (**(code **)(*DAT_00b5ad20 + 0x40))();
    piStack_174 = (int *)0xffffffff;
    uStack_178 = 0;
    puStack_17c = auStack_148;
    uStack_20 = 1;
    uStack_180 = 0x75af88;
    FUN_00401ff0();
    uStack_178 = 0x75af94;
    piStack_174 = piVar1;
    uStack_178 = (**(code **)(*DAT_00b5a980 + 8))();
    puStack_17c = (undefined1 *)0x75af9a;
    FUN_00827e80();
    piStack_174 = (int *)0x75afa8;
    (**(code **)(*DAT_00b5ad1c + 8))();
    puStack_12c = auStack_18c;
    piStack_174 = (int *)0xf;
    uStack_178 = 0;
    uStack_188 = 0;
    FUN_00401660(&puStack_164,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_130) {
      puStack_15c = (undefined *)0x75afed;
      _free(pvStack_144);
      return;
    }
    uStack_130 = 0xf;
    uStack_134 = 0;
    pvStack_144 = (void *)((uint)pvStack_144 & 0xffffff00);
    uStack_4 = 0xffffffff;
    if (0xf < uStack_114) {
      puStack_15c = (undefined *)0x75b01b;
      _free(pvStack_128);
      return;
    }
  }
  uStack_4 = 0xffffffff;
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  (**(code **)(*DAT_00b5a790 + 8))();
  puStack_160 = auStack_10c;
  puStack_15c = &DAT_009f2e14;
  puStack_164 = (undefined1 *)0x75b053;
  FUN_0044a580();
  puStack_164 = auStack_10c;
  iStack_168 = 0x75b05d;
  FUN_00797b80();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0075b080 @ 0x0075b080 ====

void FUN_0075b080(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  void *_Memory;
  uint unaff_EDI;
  undefined1 auStack_146 [6];
  void *local_140;
  undefined4 uStack_138;
  undefined4 uStack_134;
  void *pvStack_130;
  uint local_12c;
  uint uStack_11c;
  void *pvStack_3c;
  undefined4 uStack_30;
  int iStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009947a1;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x14) == '\0') {
    ExceptionList = &pvStack_c;
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    piVar4 = *(int **)(iVar2 + 0x20);
    piVar3 = (int *)(**(code **)(*piVar4 + 0x54))();
    (**(code **)(*piVar3 + 4))();
    piVar4 = (int *)(**(code **)(*piVar4 + 0x54))();
    (**(code **)(*piVar4 + 8))();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_138 = 0xf;
    FUN_00401660();
    iStack_10 = 0;
    FUN_00401740(&DAT_009f2bf4,2);
    FUN_00404230(&uStack_134);
    iStack_10._0_1_ = 1;
    FUN_00401ff0();
    iStack_10 = (uint)iStack_10._1_3_ << 8;
    if (0xf < uStack_11c) {
      _free(pvStack_130);
      return;
    }
    FUN_004020e0();
    FUN_00401660(auStack_146 + -10,0);
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_30 = 0xffffffff;
    if (0xf < unaff_EDI) {
      _free((void *)0x0);
      return;
    }
  }
  else {
    if (*(char *)(param_1 + 0x14) != '\x01') {
      ExceptionList = &pvStack_c;
      FUN_00401830();
      local_4 = 3;
      FUN_00406880();
      local_4 = 0xffffffff;
      if (local_12c < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(local_140);
      return;
    }
    ExceptionList = &pvStack_c;
    _Memory = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_134 = 0xf;
    uStack_138 = 0;
    FUN_00401660();
    pvStack_c = (void *)0x2;
    FUN_00401660(auStack_146 + -6);
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    uStack_30 = 0xffffffff;
    if (0xf < unaff_EDI) {
      _free(_Memory);
      return;
    }
  }
  uStack_30 = 0xffffffff;
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  (**(code **)(*DAT_00b5a790 + 8))();
  FUN_0044a580(&uStack_138,&DAT_009f2e14,s_RECEIVE______MONEYPACKETS__SA_Dr_009f2c08);
  FUN_00797b80(&uStack_138);
  (**(code **)(*DAT_00b5af2c + 8))(0);
  ExceptionList = pvStack_3c;
  return;
}


// ==== FUN_0075b320 @ 0x0075b320 ====

void FUN_0075b320(int param_1)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined1 auStack_12c [4];
  void *pvStack_128;
  undefined4 uStack_118;
  uint uStack_114;
  undefined4 auStack_110 [64];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009947e2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &pvStack_c;
    auStack_110[0] = (**(code **)(*DAT_00b5a78c + 0x4c))();
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar4 == 0) {
      uStack_114 = 0xf;
      uStack_118 = 0;
      pvStack_128 = (void *)((uint)pvStack_128 & 0xffffff00);
      FUN_00401740(s_pPC____NULL_009f2c2c,0xb);
      uStack_4 = 0;
      FUN_00406880(auStack_12c);
      uStack_4 = 0xffffffff;
      if (uStack_114 < 0x10) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      _free(pvStack_128);
      return;
    }
    piVar1 = *(int **)(iVar4 + 0x20);
    if (piVar1 == (int *)0x0) {
      uStack_114 = 0xf;
      uStack_118 = 0;
      pvStack_128 = (void *)((uint)pvStack_128._1_3_ << 8);
      FUN_00401740(s_pBag____NULL_009f2c38,0xc);
      uStack_4 = 1;
      FUN_00406880(auStack_12c);
      uStack_4 = 0xffffffff;
      if (uStack_114 < 0x10) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      _free(pvStack_128);
      return;
    }
    piVar2 = *(int **)(iVar4 + 0x1c);
    if (piVar2 == (int *)0x0) {
      uStack_114 = 0xf;
      uStack_118 = 0;
      pvStack_128 = (void *)((uint)pvStack_128._1_3_ << 8);
      FUN_00401740(s_pCursor____NULL_009f2c48,0xf);
      uStack_4 = 2;
      FUN_00406880(auStack_12c);
      uStack_4 = 0xffffffff;
      if (uStack_114 < 0x10) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      _free(pvStack_128);
      return;
    }
    uVar5 = (**(code **)(*piVar2 + 0x1c))();
    piVar6 = (int *)FUN_00803725(uVar5,0,&Framework::IArticle::RTTI_Type_Descriptor,
                                 &Framework::Article::IItem::RTTI_Type_Descriptor,0);
    if (piVar6 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar6 + 0x2c))(0,0,0);
      FUN_004dd240(0xb,*(undefined4 *)(iVar4 + 0x14));
    }
    if (*(char *)(param_1 + 0x11) == '\x05') {
      iVar4 = *piVar1;
      uVar5 = (**(code **)(*DAT_00b5a78c + 0x58))();
      (**(code **)(iVar4 + 0x60))(auStack_110[0],piVar2,uVar5);
      uStack_114 = 0xf;
      uStack_118 = 0;
      pvStack_128 = (void *)((uint)pvStack_128 & 0xffffff00);
      FUN_00401740(s_RECEIVE______stackpick_009f2c58,0x19);
      uStack_4 = 3;
      FUN_00796d50(auStack_12c);
    }
    else {
      (**(code **)(*piVar1 + 0x24))(auStack_110[0],piVar2);
      uStack_114 = 0xf;
      uStack_118 = 0;
      pvStack_128 = (void *)((uint)pvStack_128 & 0xffffff00);
      FUN_00401740(s_RECEIVE______change_009f2c74,0x16);
      uStack_4 = 4;
      FUN_00796d50(auStack_12c);
    }
    if (0xf < uStack_114) {
      uStack_4 = 0xffffffff;
      _free(pvStack_128);
      return;
    }
  }
  uStack_4 = 0xffffffff;
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  (**(code **)(*DAT_00b5a790 + 8))();
  (**(code **)(*DAT_00b5af2c + 8))(0);
  FUN_0044a580(auStack_110,&DAT_009f2e14,s_RECEIVE______BAGPACKETS__SA_Chan_009f2c8c);
  FUN_00797b80(auStack_110);
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0075b5f0 @ 0x0075b5f0 ====

/* WARNING: Removing unreachable block (ram,0x0075b6ea) */
/* WARNING: Removing unreachable block (ram,0x0075b68b) */

void FUN_0075b5f0(int param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined3 *puVar3;
  int iVar4;
  int *piVar5;
  undefined1 auStack_164 [4];
  uint uStack_160;
  undefined4 uStack_15c;
  uint uStack_158;
  undefined1 *puStack_154;
  undefined1 *puStack_150;
  undefined4 uStack_14c;
  int *piStack_148;
  undefined1 auStack_12e [2];
  void *pvStack_12c;
  undefined1 auStack_110 [256];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099480d;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &pvStack_c;
    puVar3 = (undefined3 *)(**(code **)(*DAT_00b5a78c + 0x4c))();
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar4 == 0) {
      piStack_148 = (int *)s_pPC____NULL_009f2cb0;
      uStack_14c = (undefined3 *)0x75b665;
      FUN_00401740();
      uStack_4 = 0;
      piStack_148 = (int *)0x75b676;
      FUN_00406880();
      uStack_4 = 0xffffffff;
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    piVar1 = *(int **)(iVar4 + 0x20);
    if (piVar1 == (int *)0x0) {
      piStack_148 = (int *)s_pBag____NULL_009f2cbc;
      uStack_14c = (undefined3 *)0x75b6c0;
      FUN_00401740();
      uStack_4 = 1;
      piStack_148 = (int *)0x75b6d5;
      FUN_00406880();
      uStack_4 = 0xffffffff;
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    piStack_148 = (int *)0x75b700;
    piVar5 = (int *)(**(code **)(*piVar1 + 0x28))();
    uStack_14c = (undefined3 *)0x75b70e;
    piStack_148 = piVar5;
    (**(code **)(*DAT_00b5b130 + 0xc))();
    uStack_14c = (undefined3 *)0x0;
    puStack_150 = (undefined1 *)0x0;
    puStack_154 = (undefined1 *)0x0;
    uStack_158 = 0x75b718;
    uStack_158 = (**(code **)(*piVar5 + 0x1c))();
    uStack_158 = uStack_158 & 0xffff;
    uStack_15c = 0xd;
    uStack_160 = 0x75b723;
    FUN_004dd240();
    uStack_14c = (undefined3 *)0x75b72d;
    iVar4 = (**(code **)(*piVar5 + 0x2c))();
    if (*(short *)(iVar4 + 0x72) == 0) {
      puStack_150 = (undefined1 *)0x75b764;
      uStack_14c = puVar3;
      puStack_150 = (undefined1 *)(**(code **)(*piVar1 + 0x20))();
      puStack_154 = (undefined1 *)0x1;
      uStack_158 = 0x75b772;
      (**(code **)(*DAT_00b5a730 + 0x10))();
    }
    else {
      uStack_14c = (undefined3 *)CONCAT13((char)((uint)DAT_00b5a980 >> 0x18),*puVar3);
      puStack_150 = (undefined1 *)0x75b74e;
      piStack_148 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
      uStack_14c = (undefined3 *)0x75b754;
      FUN_00827380();
    }
  }
  else {
    ExceptionList = &pvStack_c;
    if (*(char *)(param_1 + 0x10) == '=') {
      piStack_148 = (int *)0x0;
      uStack_14c = (undefined3 *)0x75b790;
      ExceptionList = &pvStack_c;
      puStack_154 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_14c = (undefined3 *)0xffffffff;
      puStack_150 = (undefined1 *)0x0;
      uStack_158 = 0x75b7ae;
      FUN_00401660();
      uStack_14c = (undefined3 *)0xf;
      puStack_150 = (undefined1 *)0x0;
      pvStack_c = (void *)0x2;
      uStack_160 = uStack_160 & 0xffffff00;
      FUN_00401660(auStack_12e + -10,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      uStack_4 = 0xffffffff;
      if ((undefined1 *)0xf < auStack_164) {
        piStack_148 = (int *)0x75b801;
        _free(pvStack_12c);
        return;
      }
    }
  }
  piStack_148 = (int *)0x75b810;
  (**(code **)(*DAT_00b5af2c + 8))();
  piStack_148 = (int *)s_RECEIVE______BAGPACKETS__SA_Use_009f2ccc;
  puStack_150 = auStack_110;
  uStack_14c = (undefined3 *)&DAT_009f2e14;
  puStack_154 = (undefined1 *)0x75b824;
  FUN_0044a580();
  puStack_154 = auStack_110;
  uStack_158 = 0x75b82e;
  FUN_00797b80();
  piStack_148 = (int *)0x75b83c;
  (**(code **)(*DAT_00b5a790 + 4))();
  piStack_148 = (int *)0x75b847;
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  uStack_14c = (undefined3 *)0x75b858;
  FUN_00759c00();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0075b880 @ 0x0075b880 ====

void FUN_0075b880(int param_1)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int unaff_retaddr;
  undefined1 auStack_180 [4];
  undefined1 uStack_17c;
  undefined4 uStack_174;
  undefined4 uStack_170;
  undefined1 *puStack_16c;
  undefined1 *puStack_168;
  undefined *puStack_164;
  void *pvStack_144;
  undefined1 auStack_138 [4];
  uint uStack_134;
  uint uStack_130;
  void *pvStack_12c;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined1 *puStack_11c;
  uint uStack_118;
  undefined1 auStack_110 [256];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994838;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &pvStack_c;
    (**(code **)(*DAT_00b5a78c + 0x4c))();
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar3 == 0) {
      uStack_130 = 0xf;
      uStack_134 = 0;
      pvStack_144 = (void *)((uint)pvStack_144._1_3_ << 8);
      puStack_164 = (undefined *)0x75b8ec;
      FUN_00401740();
      uStack_4 = 0;
      FUN_00406880();
      uStack_4 = 0xffffffff;
      if (uStack_130 < 0x10) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(pvStack_144);
      return;
    }
    piVar1 = *(int **)(iVar3 + 0x20);
    if (piVar1 == (int *)0x0) {
      uStack_130 = 0xf;
      uStack_134 = 0;
      pvStack_144 = (void *)((uint)pvStack_144._1_3_ << 8);
      puStack_164 = (undefined *)0x75b947;
      FUN_00401740();
      uStack_4 = 1;
      FUN_00406880();
      uStack_4 = 0xffffffff;
      if (uStack_130 < 0x10) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(pvStack_144);
      return;
    }
    piVar4 = (int *)(**(code **)(*piVar1 + 0x28))();
    puStack_164 = (undefined *)0x0;
    puStack_168 = (undefined1 *)0x0;
    puStack_16c = (undefined1 *)0x75b993;
    uVar5 = (**(code **)(*piVar4 + 0x1c))();
    puStack_16c = (undefined1 *)(uVar5 & 0xffff);
    uStack_170 = 0xd;
    uStack_174 = 0x75b99e;
    FUN_004dd240();
    iVar3 = (**(code **)(*piVar4 + 0x2c))();
    if (*(short *)(iVar3 + 0x72) == 0) {
      puStack_164 = (undefined *)0x75b9dc;
      puStack_164 = (undefined *)(**(code **)(*piVar1 + 0x20))();
      puStack_168 = (undefined1 *)0x1;
      puStack_16c = (undefined1 *)0x75b9ea;
      (**(code **)(*DAT_00b5a730 + 0x10))();
    }
    else {
      puStack_164 = (undefined *)0x75b9c9;
      (**(code **)(*DAT_00b5a980 + 8))();
      puStack_164 = (undefined *)0x75b9cf;
      FUN_00827380();
    }
  }
  (**(code **)(*DAT_00b5af2c + 8))();
  puStack_168 = auStack_110;
  puStack_164 = &DAT_009f2e14;
  puStack_16c = (undefined1 *)0x75ba0a;
  FUN_0044a580();
  puStack_16c = auStack_110;
  uStack_170 = 0x75ba14;
  FUN_00797b80();
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  if ((*(char *)(unaff_retaddr + 0x10) == '\x01') || (*(char *)(unaff_retaddr + 0x10) == '\x06')) {
    puStack_164 = (undefined *)0x0;
    puStack_168 = (undefined1 *)0x75ba5f;
    uStack_170 = (**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_168 = (undefined1 *)0xffffffff;
    puStack_16c = (undefined1 *)0x0;
    uStack_120 = 0xf;
    uStack_124 = 0;
    uStack_134 = uStack_134 & 0xffffff00;
    uStack_174 = 0x75ba7d;
    FUN_00401660();
    puStack_11c = auStack_180;
    puStack_168 = (undefined1 *)0xf;
    puStack_16c = (undefined1 *)0x0;
    pvStack_10 = (void *)0x2;
    uStack_17c = 0;
    FUN_00401660(auStack_138,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_118) {
      puStack_164 = (undefined *)0x75bac5;
      _free(pvStack_12c);
      return;
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0075baf0 @ 0x0075baf0 ====

void FUN_0075baf0(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  void *unaff_EDI;
  undefined1 auStack_84 [4];
  undefined1 uStack_80;
  undefined4 uStack_78;
  undefined1 *puStack_74;
  int iStack_70;
  undefined4 uStack_58;
  uint uStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_34;
  uint uStack_24;
  void *pvStack_20;
  undefined1 uStack_18;
  undefined1 *puStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &LAB_00994852;
  pvStack_c = ExceptionList;
  uStack_58 = 0x6e0016;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_34 = 0xf;
  pvStack_38 = (void *)0x0;
  FUN_00401660();
  iVar1 = iStack_4;
  pvStack_c = (void *)0x0;
  piVar3 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
  cVar2 = (**(code **)(*piVar3 + 8))();
  if (cVar2 != '\0') {
    iStack_70 = (**(code **)(*piVar3 + 0x2c))();
    iStack_70 = iStack_70 + 0x32;
    puStack_74 = auStack_3c;
    uStack_78 = 0x75bb87;
    puStack_74 = (undefined1 *)FUN_004022a0();
    iStack_70 = 0;
    uStack_18 = 1;
    uStack_78 = 0x75bb9c;
    FUN_00401660();
    uStack_18 = 0;
    if (0xf < uStack_24) {
      iStack_70 = 0x75bbb5;
      _free(pvStack_38);
      return;
    }
    puStack_10 = auStack_84;
    iStack_70 = 0;
    uStack_80 = 0;
    FUN_00401660(&uStack_58,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    cVar2 = (**(code **)(**(int **)(iVar4 + 0x20) + 0x1c))(iVar1 + 0x10,piVar3);
    if (cVar2 != '\0') {
      (**(code **)(*DAT_00b5a790 + 4))();
      (**(code **)(*DAT_00b5ad58 + 0xc))();
    }
  }
  if (uStack_40 < 0x10) {
    ExceptionList = pvStack_20;
    return;
  }
  iStack_70 = 0x75bc2a;
  _free(unaff_EDI);
  return;
}


// ==== FUN_0075bc50 @ 0x0075bc50 ====

void FUN_0075bc50(int param_1)

{
  int *piVar1;
  int *piVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  undefined1 auStack_128 [4];
  void *pvStack_124;
  undefined4 uStack_114;
  uint auStack_110 [64];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099487d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &pvStack_c;
    iVar4 = (**(code **)(*DAT_00b5a78c + 0x4c))();
    iVar4 = *(int *)(iVar4 + 4);
    iVar5 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar5 == 0) {
      auStack_110[0] = 0xf;
      uStack_114 = 0;
      pvStack_124 = (void *)((uint)pvStack_124 & 0xffffff00);
      FUN_00401740(s_pPC____NULL_009f2d30,0xb);
      uStack_4 = 0;
      FUN_00406880(auStack_128);
      uStack_4 = 0xffffffff;
      if (auStack_110[0] < 0x10) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      _free(pvStack_124);
      return;
    }
    piVar1 = *(int **)(iVar5 + 0x24);
    if (piVar1 == (int *)0x0) {
      auStack_110[0] = 0xf;
      uStack_114 = 0;
      pvStack_124 = (void *)((uint)pvStack_124._1_3_ << 8);
      FUN_00401740(s_pSuit____NULL_009f2d3c,0xd);
      uStack_4 = 1;
      FUN_00406880(auStack_128);
      uStack_4 = 0xffffffff;
      if (auStack_110[0] < 0x10) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      _free(pvStack_124);
      return;
    }
    piVar2 = *(int **)(iVar5 + 0x1c);
    if (piVar2 == (int *)0x0) {
      auStack_110[0] = 0xf;
      uStack_114 = 0;
      pvStack_124 = (void *)((uint)pvStack_124._1_3_ << 8);
      FUN_00401740(s_pCursor____NULL_009f2d4c,0xf);
      uStack_4 = 2;
      FUN_00406880(auStack_128);
      uStack_4 = 0xffffffff;
      if (auStack_110[0] < 0x10) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      _free(pvStack_124);
      return;
    }
    uVar6 = (**(code **)(*piVar2 + 0x1c))();
    piVar7 = (int *)FUN_00803725(uVar6,0,&Framework::IArticle::RTTI_Type_Descriptor,
                                 &Framework::Article::IItem::RTTI_Type_Descriptor,0);
    if (piVar7 != (int *)0x0) {
      iVar5 = (**(code **)(*piVar7 + 0x2c))(0,0,0);
      FUN_004dd240(0xb,*(undefined4 *)(iVar5 + 0x14));
    }
    (**(code **)(*piVar1 + 0x28))(iVar4,piVar2);
    if (iVar4 == 6) {
      (**(code **)(*DAT_00b5a9e4 + 0x2c))(0);
    }
    else {
      if (iVar4 == 7) {
        uVar6 = 1;
      }
      else {
        if (iVar4 == 0x13) {
          (**(code **)(*DAT_00b5a9e4 + 0x2c))(2);
          goto LAB_0075be36;
        }
        if (iVar4 != 0x14) goto LAB_0075be36;
        uVar6 = 3;
      }
      (**(code **)(*DAT_00b5a9e4 + 0x2c))(uVar6);
    }
  }
LAB_0075be36:
  (**(code **)(*DAT_00b5af2c + 8))(0);
  FUN_0044a580(auStack_110,&DAT_009f2e14,s_RECEIVE______SUITPACKETS__SA_Cha_009f2d5c);
  FUN_00797b80(auStack_110);
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  (**(code **)(*DAT_00b5a790 + 8))();
  (**(code **)(*DAT_00b5ad58 + 8))();
  (**(code **)(*DAT_00b5ad1c + 8))();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0075bec0 @ 0x0075bec0 ====

void FUN_0075bec0(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_128 [4];
  void *pvStack_124;
  undefined4 uStack_114;
  uint auStack_110 [64];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099489d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(char *)(param_1 + 0x11) == '\0') {
    ExceptionList = &pvStack_c;
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar2 == 0) {
      auStack_110[0] = 0xf;
      uStack_114 = 0;
      pvStack_124 = (void *)((uint)pvStack_124._1_3_ << 8);
      FUN_00401740(s_pPC____NULL_009f2d84,0xb);
      uStack_4 = 0;
      FUN_00406880(auStack_128);
      uStack_4 = 0xffffffff;
      if (auStack_110[0] < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_124);
      return;
    }
    if (*(int **)(iVar2 + 0x24) == (int *)0x0) {
      auStack_110[0] = 0xf;
      uStack_114 = 0;
      pvStack_124 = (void *)((uint)pvStack_124._1_3_ << 8);
      FUN_00401740(s_pSuit____NULL_009f2d90,0xd);
      uStack_4 = 1;
      FUN_00406880(auStack_128);
      uStack_4 = 0xffffffff;
      if (auStack_110[0] < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_124);
      return;
    }
    (**(code **)(**(int **)(iVar2 + 0x24) + 0x40))();
  }
  (**(code **)(*DAT_00b5af2c + 8))(0);
  FUN_0044a580(auStack_110,&DAT_009f2e14,s_RECEIVE______SUITPACKETS__SA_Swa_009f2da0);
  FUN_00797b80(auStack_110);
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 0xc))();
  (**(code **)(*DAT_00b5a790 + 8))();
  (**(code **)(*DAT_00b5ad1c + 8))();
  (**(code **)(*DAT_00b5ad58 + 8))();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0075c040 @ 0x0075c040 ====

void FUN_0075c040(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009948af;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x10) != 1) {
    ExceptionList = &local_c;
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar2 == 0) {
      uStack_10 = 0xf;
      uStack_14 = 0;
      pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      FUN_00401740(s_pPC_L____NULL_009f2dcc,0xd);
      uStack_4 = 0;
      FUN_00406880(auStack_28);
      uStack_4 = 0xffffffff;
      if (uStack_10 < 0x10) {
        uStack_10 = 0xf;
        uStack_14 = 0;
        pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_24);
      return;
    }
    FUN_0082a030(iVar2);
    (**(code **)(*DAT_00b5a790 + 4))();
    (**(code **)(*DAT_00b5ad58 + 0xc))();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0075c110 @ 0x0075c110 ====

void FUN_0075c110(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined1 auStack_94 [4];
  uint uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  char *pcStack_80;
  undefined *puStack_7c;
  undefined4 uStack_78;
  uint uStack_48;
  void *pvStack_40;
  uint uStack_2c;
  void *pvStack_24;
  uint uStack_10;
  undefined1 *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009948d1;
  local_c = ExceptionList;
  if (*(char *)(param_1 + 0x34) == '\x01') {
    uStack_78 = 1;
    puStack_7c = (undefined *)0x75c14b;
    ExceptionList = &local_c;
    piVar2 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
    pcStack_80 = (char *)0x75c158;
    puStack_7c = (undefined *)(param_1 + 0x10);
    cVar1 = (**(code **)(*piVar2 + 8))();
    if (cVar1 == '\x01') {
      puStack_7c = (undefined *)0x75c171;
      uStack_78 = param_1 + 0x10;
      (**(code **)(*DAT_00b5aeec + 0x30))();
      puStack_7c = (undefined *)0x75c178;
      iVar3 = (**(code **)(*piVar2 + 0x2c))();
      pcStack_80 = (char *)(iVar3 + 0x32);
      uStack_48 = uStack_48 & 0xffffff00;
      pcVar4 = pcStack_80;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      puStack_7c = (undefined *)((int)pcVar4 - (iVar3 + 0x33));
      uStack_84 = 0x75c1a8;
      FUN_00401740();
      local_c = (undefined1 *)0x1;
      if (*(int *)(iVar3 + 8) == 0x101) {
        puStack_7c = (undefined *)0x0;
        pcStack_80 = (char *)0x0;
        uStack_84 = 0;
        uStack_88 = 200;
        uStack_8c = 0x16;
        uStack_90 = 0x75c1c8;
        FUN_004dd240();
      }
      puStack_7c = &DAT_0082000b;
      pcStack_80 = (char *)0x5;
      uStack_84 = 0x75c1dd;
      uStack_8c = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_84 = 0xffffffff;
      uStack_88 = 0;
      uStack_90 = 0x75c1fb;
      FUN_00401660();
      local_c = (undefined1 *)&uStack_9c;
      FUN_00401660(auStack_94 + 0x24,0,0xffffffff);
      FUN_00404230(local_c);
      (**(code **)(*DAT_00b5ad0c + 0x28))();
      (**(code **)(*DAT_00b5a980 + 8))();
      FUN_00827e80();
      (**(code **)(*DAT_00b5ad1c + 8))();
      (**(code **)(*DAT_00b5a790 + 4))();
      (**(code **)(*DAT_00b5ad58 + 0xc))();
      (**(code **)(*DAT_00b5ad58 + 8))();
      if (0xf < uStack_48) {
        uStack_78 = 0x75c2b7;
        _free((void *)0x0);
        return;
      }
      if (0xf < uStack_2c) goto LAB_0075c35d;
    }
  }
  else if (*(char *)(param_1 + 0x34) == '\x02') {
    uStack_78 = 0;
    puStack_7c = (undefined *)0x75c2f9;
    ExceptionList = &local_c;
    uStack_84 = (**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_7c = (undefined *)0xffffffff;
    pcStack_80 = (char *)0x0;
    uStack_88 = 0x75c317;
    FUN_00401660();
    puStack_4 = auStack_94;
    uStack_98 = 0xffffffff;
    uStack_9c = 0;
    puStack_7c = (undefined *)0xf;
    pcStack_80 = (char *)0x0;
    local_c = (undefined1 *)0x3;
    uStack_90 = uStack_90 & 0xffffff00;
    FUN_00401660();
    uStack_98 = 2;
    uStack_9c = 0x75c351;
    (**(code **)(*DAT_00b5ad0c + 0x28))();
    if (0xf < uStack_10) {
      pvStack_40 = pvStack_24;
LAB_0075c35d:
      uStack_78 = 0x75c362;
      _free(pvStack_40);
      return;
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0075c380 @ 0x0075c380 ====

void FUN_0075c380(void)

{
  int iVar1;
  undefined1 auStack_94 [4];
  undefined1 uStack_90;
  undefined4 uStack_88;
  undefined4 *puStack_84;
  undefined1 *puStack_80;
  undefined4 uStack_70;
  void *pvStack_5c;
  uint uStack_48;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  uint uStack_20;
  undefined1 uStack_14;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009948f3;
  puStack_c = ExceptionList;
  ExceptionList = &puStack_c;
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x24) != (int *)0x0)) {
    uStack_70 = 0x75c3c7;
    iVar1 = (**(code **)(**(int **)(iVar1 + 0x24) + 0x20))();
    if (iVar1 != 0) {
      uStack_70 = 0;
      (**(code **)(*DAT_00b5a794 + 0xc))();
      puStack_80 = (undefined1 *)0x75c3ff;
      FUN_00401660();
      puStack_c = (undefined1 *)0x0;
      FUN_00401830();
      puStack_c = (undefined1 *)CONCAT31(puStack_c._1_3_,1);
      (**(code **)(*DAT_00b5ad20 + 0x40))();
      puStack_80 = auStack_38;
      puStack_84 = &uStack_70;
      uStack_14 = 2;
      uStack_88 = 0x75c43c;
      FUN_00404440();
      if (0xf < uStack_3c) {
        puStack_80 = (undefined1 *)0x75c450;
        _free((void *)0xf);
        return;
      }
      uStack_14 = 0;
      if (0xf < uStack_20) {
        puStack_80 = (undefined1 *)0x75c478;
        _free(pvStack_34);
        return;
      }
      puStack_c = auStack_94;
      puStack_80 = (undefined1 *)0x0;
      uStack_90 = 0;
      FUN_00401660(&uStack_70,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      (**(code **)(*DAT_00b5a730 + 0x10))(1,iVar1);
      (**(code **)(*DAT_00b5a790 + 4))();
      (**(code **)(*DAT_00b5ad58 + 0xc))();
      if (0xf < uStack_48) {
        uStack_70 = 0x75c4e3;
        _free(pvStack_5c);
        return;
      }
    }
  }
  ExceptionList = puStack_c;
  return;
}


// ==== FUN_0075c500 @ 0x0075c500 ====

void FUN_0075c500(void)

{
  int iVar1;
  undefined1 auStack_94 [4];
  undefined1 uStack_90;
  undefined4 uStack_88;
  undefined4 *puStack_84;
  undefined1 *puStack_80;
  undefined4 uStack_70;
  void *pvStack_5c;
  uint uStack_48;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  uint uStack_20;
  undefined1 uStack_14;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994915;
  puStack_c = ExceptionList;
  ExceptionList = &puStack_c;
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x20) != (int *)0x0)) {
    uStack_70 = 0x75c547;
    iVar1 = (**(code **)(**(int **)(iVar1 + 0x20) + 0x20))();
    if (iVar1 != 0) {
      uStack_70 = 0;
      (**(code **)(*DAT_00b5a794 + 0xc))();
      puStack_80 = (undefined1 *)0x75c57f;
      FUN_00401660();
      puStack_c = (undefined1 *)0x0;
      FUN_00401830();
      puStack_c = (undefined1 *)CONCAT31(puStack_c._1_3_,1);
      (**(code **)(*DAT_00b5ad20 + 0x40))();
      puStack_80 = auStack_38;
      puStack_84 = &uStack_70;
      uStack_14 = 2;
      uStack_88 = 0x75c5bc;
      FUN_00404440();
      if (0xf < uStack_3c) {
        puStack_80 = (undefined1 *)0x75c5d0;
        _free((void *)0xf);
        return;
      }
      uStack_14 = 0;
      if (0xf < uStack_20) {
        puStack_80 = (undefined1 *)0x75c5f8;
        _free(pvStack_34);
        return;
      }
      puStack_c = auStack_94;
      puStack_80 = (undefined1 *)0x0;
      uStack_90 = 0;
      FUN_00401660(&uStack_70,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      (**(code **)(*DAT_00b5a730 + 0x10))(1,iVar1);
      (**(code **)(*DAT_00b5a790 + 4))();
      (**(code **)(*DAT_00b5ad58 + 0xc))();
      if (0xf < uStack_48) {
        uStack_70 = 0x75c663;
        _free(pvStack_5c);
        return;
      }
    }
  }
  ExceptionList = puStack_c;
  return;
}


// ==== FUN_0075c680 @ 0x0075c680 ====

void FUN_0075c680(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puStack_70;
  undefined1 auStack_54 [36];
  undefined1 auStack_30 [28];
  undefined1 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994937;
  pvStack_c = ExceptionList;
  puStack_70 = (undefined *)0x75c6a5;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x1c) != (int *)0x0)) {
    puStack_70 = (undefined *)0x75c6bf;
    iVar1 = (**(code **)(**(int **)(iVar1 + 0x1c) + 0x1c))();
    if (iVar1 != 0) {
      puStack_70 = (undefined *)0x0;
      iVar1 = FUN_00803725(iVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                           &Framework::Article::IItem::RTTI_Type_Descriptor);
      if (iVar1 != 0) {
        puStack_70 = &DAT_006e0071;
        uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
        FUN_00765c50(uVar2);
        pvStack_c = (void *)0x0;
        FUN_00401830(s_<NAME>_009f2dfc);
        pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
        uVar2 = (**(code **)(*DAT_00b5ad20 + 0x40))(auStack_30,iVar1);
        uStack_14 = 2;
        FUN_00404440(&puStack_70,auStack_54,uVar2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0075c7b0 @ 0x0075c7b0 ====

void FUN_0075c7b0(void)

{
  int iVar1;
  undefined1 auStack_94 [4];
  undefined1 uStack_90;
  undefined4 uStack_88;
  undefined4 *puStack_84;
  undefined1 *puStack_80;
  undefined4 uStack_70;
  void *pvStack_5c;
  uint uStack_48;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  uint uStack_20;
  undefined1 uStack_14;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994959;
  puStack_c = ExceptionList;
  ExceptionList = &puStack_c;
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x34) != (int *)0x0)) {
    uStack_70 = 0x75c7f7;
    iVar1 = (**(code **)(**(int **)(iVar1 + 0x34) + 0x24))();
    if (iVar1 != 0) {
      uStack_70 = 0;
      (**(code **)(*DAT_00b5a794 + 0xc))();
      puStack_80 = (undefined1 *)0x75c82f;
      FUN_00401660();
      puStack_c = (undefined1 *)0x0;
      FUN_00401830();
      puStack_c = (undefined1 *)CONCAT31(puStack_c._1_3_,1);
      (**(code **)(*DAT_00b5ad20 + 0x40))();
      puStack_80 = auStack_38;
      puStack_84 = &uStack_70;
      uStack_14 = 2;
      uStack_88 = 0x75c86c;
      FUN_00404440();
      if (0xf < uStack_3c) {
        puStack_80 = (undefined1 *)0x75c880;
        _free((void *)0xf);
        return;
      }
      uStack_14 = 0;
      if (0xf < uStack_20) {
        puStack_80 = (undefined1 *)0x75c8a8;
        _free(pvStack_34);
        return;
      }
      puStack_c = auStack_94;
      puStack_80 = (undefined1 *)0x0;
      uStack_90 = 0;
      FUN_00401660(&uStack_70,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      (**(code **)(*DAT_00b5a730 + 0x10))(1,iVar1);
      (**(code **)(*DAT_00b5a790 + 4))();
      if (0xf < uStack_48) {
        uStack_70 = 0x75c908;
        _free(pvStack_5c);
        return;
      }
    }
  }
  ExceptionList = puStack_c;
  return;
}


// ==== FUN_0075c920 @ 0x0075c920 ====

void FUN_0075c920(void)

{
  int iVar1;
  undefined1 auStack_94 [4];
  undefined1 uStack_90;
  undefined4 uStack_88;
  undefined4 *puStack_84;
  undefined1 *puStack_80;
  undefined4 uStack_70;
  void *pvStack_5c;
  uint uStack_48;
  uint uStack_3c;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  uint uStack_20;
  undefined1 uStack_14;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099497b;
  puStack_c = ExceptionList;
  ExceptionList = &puStack_c;
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x2c) != (int *)0x0)) {
    uStack_70 = 0x75c967;
    iVar1 = (**(code **)(**(int **)(iVar1 + 0x2c) + 0x28))();
    if (iVar1 != 0) {
      uStack_70 = 0;
      (**(code **)(*DAT_00b5a794 + 0xc))();
      puStack_80 = (undefined1 *)0x75c99f;
      FUN_00401660();
      puStack_c = (undefined1 *)0x0;
      FUN_00401830();
      puStack_c = (undefined1 *)CONCAT31(puStack_c._1_3_,1);
      (**(code **)(*DAT_00b5ad20 + 0x40))();
      puStack_80 = auStack_38;
      puStack_84 = &uStack_70;
      uStack_14 = 2;
      uStack_88 = 0x75c9dc;
      FUN_00404440();
      if (0xf < uStack_3c) {
        puStack_80 = (undefined1 *)0x75c9f0;
        _free((void *)0xf);
        return;
      }
      uStack_14 = 0;
      if (0xf < uStack_20) {
        puStack_80 = (undefined1 *)0x75ca18;
        _free(pvStack_34);
        return;
      }
      puStack_c = auStack_94;
      puStack_80 = (undefined1 *)0x0;
      uStack_90 = 0;
      FUN_00401660(&uStack_70,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      (**(code **)(*DAT_00b5a730 + 0x10))(1,iVar1);
      (**(code **)(*DAT_00b5b118 + 4))();
      if (0xf < uStack_48) {
        uStack_70 = 0x75ca78;
        _free(pvStack_5c);
        return;
      }
    }
  }
  ExceptionList = puStack_c;
  return;
}


// ==== FUN_0075ca90 @ 0x0075ca90 ====

undefined4 FUN_0075ca90(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x500000c) {
    if (uVar1 == 0x500000b) {
      FUN_0075b880(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    switch(uVar1 + 0xfaffffff) {
    case 0:
      FUN_0075b320(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 2:
      FUN_0075b5f0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 3:
      FUN_0075baf0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 4:
      FUN_00759e10(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 5:
      FUN_00759ef0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 6:
      FUN_00759fd0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else if (uVar1 < 0x50e0011) {
    if (uVar1 == 0x50e0010) {
      FUN_007599f0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar1 < 0x5030005) {
      if (uVar1 == 0x5030004) {
        FUN_0075ab70(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 < 0x5020007) {
        if (uVar1 == 0x5020006) {
          FUN_0075a9f0(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar1 == 0x5020002) {
          FUN_0075a5e0(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
        if (uVar1 == 0x5020004) {
          FUN_0075a0b0(*(undefined4 *)(param_1 + 0xc));
          return 1;
        }
      }
      else if (uVar1 == 0x5030001) {
        FUN_0075b080(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
    else if (uVar1 < 0x50c0004) {
      if (uVar1 == 0x50c0003) {
        FUN_0075bec0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x509000d) {
        FUN_00759740(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x50c0001) {
        FUN_0075bc50(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
    else if (uVar1 == 0x50c0004) {
      FUN_0075c040(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else if (uVar1 < 0x10000005) {
    if (uVar1 == 0x10000004) {
      FUN_0075c500(*(undefined4 *)(param_1 + 0xc));
      return 0;
    }
    if (uVar1 < 0x521000a) {
      if (uVar1 == 0x5210009) {
        FUN_0075c110(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x50e0012) {
        FUN_007597d0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
      if (uVar1 == 0x511000e) {
        FUN_0075aed0(*(undefined4 *)(param_1 + 0xc));
        return 1;
      }
    }
    else if (uVar1 == 0x10000003) {
      FUN_0075c380(*(undefined4 *)(param_1 + 0xc));
      return 0;
    }
  }
  else if (uVar1 == 0x10000005) {
    FUN_0075c680(*(undefined4 *)(param_1 + 0xc));
  }
  else {
    if (uVar1 == 0x10000006) {
      FUN_0075c7b0(*(undefined4 *)(param_1 + 0xc));
      return 0;
    }
    if (uVar1 == 0x10000007) {
      FUN_0075c920(*(undefined4 *)(param_1 + 0xc));
      return 0;
    }
  }
  return 0;
}


// ==== FUN_0075cd50 @ 0x0075cd50 ====

undefined4 FUN_0075cd50(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0075ca90(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0075cd80 @ 0x0075cd80 ====

void FUN_0075cd80(byte param_1)

{
  void *in_ECX;
  
  FUN_007597b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075cda0 @ 0x0075cda0 ====

void FUN_0075cda0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f2f8c;
  return;
}


// ==== FUN_0075cdb0 @ 0x0075cdb0 ====

void FUN_0075cdb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f2f8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075cdd0 @ 0x0075cdd0 ====

undefined1 FUN_0075cdd0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x12);
}


// ==== FUN_0075cde0 @ 0x0075cde0 ====

void FUN_0075cde0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x18) = param_1;
  return;
}


// ==== FUN_0075cdf0 @ 0x0075cdf0 ====

int FUN_0075cdf0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0075ce00 @ 0x0075ce00 ====

undefined1 FUN_0075ce00(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x13);
}


// ==== FUN_0075ce10 @ 0x0075ce10 ====

void FUN_0075ce10(undefined3 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x14) + 8))
            (CONCAT13((char)((uint)*(int **)(in_ECX + 0x14) >> 0x18),param_1));
  return;
}


// ==== FUN_0075ce40 @ 0x0075ce40 ====

void FUN_0075ce40(undefined3 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x14) + 0xc))
            (CONCAT13((char)((uint)*(int **)(in_ECX + 0x14) >> 0x18),param_1));
  return;
}


// ==== FUN_0075ce70 @ 0x0075ce70 ====

void FUN_0075ce70(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0075ce75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x14) + 0x10))();
  return;
}


// ==== FUN_0075ce80 @ 0x0075ce80 ====

void FUN_0075ce80(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*(int *)in_ECX[5] + 0x14))(param_1);
  (**(code **)(*in_ECX + 0x74))(param_1);
  return;
}


// ==== FUN_0075cea0 @ 0x0075cea0 ====

void FUN_0075cea0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0075cea5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x14) + 0x18))();
  return;
}


// ==== FUN_0075ceb0 @ 0x0075ceb0 ====

void FUN_0075ceb0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0075ceb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x14) + 0x1c))();
  return;
}


// ==== FUN_0075cec0 @ 0x0075cec0 ====

void FUN_0075cec0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0075cec5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x14) + 0x20))();
  return;
}


// ==== FUN_0075ced0 @ 0x0075ced0 ====

void FUN_0075ced0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0075ced5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x14) + 0x28))();
  return;
}


// ==== FUN_0075cee0 @ 0x0075cee0 ====

bool FUN_0075cee0(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(**(int **)(in_ECX + 0x14) + 0x30))();
  return cVar1 == '\x01';
}


// ==== FUN_0075cef0 @ 0x0075cef0 ====

void FUN_0075cef0(char param_1)

{
  int *in_ECX;
  
  if (param_1 != *(char *)((int)in_ECX + 0x12)) {
    *(char *)((int)in_ECX + 0x12) = param_1;
    (**(code **)(*in_ECX + 0x6c))();
  }
  return;
}


// ==== FUN_0075cf10 @ 0x0075cf10 ====

void FUN_0075cf10(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0075cf15. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x14) + 4))();
  return;
}


// ==== FUN_0075cf20 @ 0x0075cf20 ====

undefined2 FUN_0075cf20(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x10);
}


// ==== FUN_0075cf30 @ 0x0075cf30 ====

void FUN_0075cf30(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x13) = param_1;
  return;
}


// ==== FUN_0075cf40 @ 0x0075cf40 ====

void FUN_0075cf40(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f3008;
  }
  FUN_00797a20(puVar1);
                    /* WARNING: Could not recover jumptable at 0x0075cf69. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a790 + 8))();
  return;
}


// ==== FUN_0075cf70 @ 0x0075cf70 ====

undefined4 FUN_0075cf70(undefined4 param_1)

{
  (**(code **)(*DAT_00b5a790 + 0x18))(param_1);
  return param_1;
}


// ==== FUN_0075cf90 @ 0x0075cf90 ====

undefined4 FUN_0075cf90(undefined4 param_1)

{
  (**(code **)(*DAT_00b5a790 + 0x1c))(param_1);
  return param_1;
}


// ==== FUN_0075cfb0 @ 0x0075cfb0 ====

void FUN_0075cfb0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0075cfb8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a790 + 0x20))();
  return;
}


// ==== FUN_0075cfc0 @ 0x0075cfc0 ====

void FUN_0075cfc0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0075cfc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a790 + 0x24))();
  return;
}


// ==== FUN_0075cfd0 @ 0x0075cfd0 ====

void FUN_0075cfd0(void)

{
                    /* WARNING: Could not recover jumptable at 0x0075cfd8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a790 + 0x2c))();
  return;
}


// ==== FUN_0075cfe0 @ 0x0075cfe0 ====

void FUN_0075cfe0(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined2 extraout_var;
  undefined1 uVar4;
  undefined3 uVar5;
  
  *(undefined2 *)(in_ECX + 0x10) = param_2;
  uVar5 = (undefined3)param_1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a790 + 0x28))
                            (CONCAT13((char)((uint)DAT_00b5a790 >> 0x18),uVar5));
  if (piVar2 != (int *)0x0) {
    *(undefined2 *)(in_ECX + 8) = (undefined2)param_1;
    *(undefined1 *)(in_ECX + 10) = param_1._2_1_;
    iVar3 = (**(code **)(*piVar2 + 0x14))();
    iVar1 = **(int **)(in_ECX + 0x14);
    uVar4 = (undefined1)((uint)*(int **)(in_ECX + 0x14) >> 0x18);
    if (*(char *)(iVar3 + 0x21) == '\x01') {
      (**(code **)(iVar1 + 0x24))
                (CONCAT13(uVar4,uVar5),CONCAT22(extraout_var,*(undefined2 *)(in_ECX + 0x10)));
      return;
    }
    (**(code **)(iVar1 + 8))(CONCAT13(uVar4,uVar5));
  }
  return;
}


// ==== FUN_0075d060 @ 0x0075d060 ====

void FUN_0075d060(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aef4 + 0x58))();
  if (cVar1 != '\x01') {
    cVar1 = (**(code **)(*DAT_00b5b0fc + 0x14))();
    if (cVar1 != '\x01') {
                    /* WARNING: Could not recover jumptable at 0x0075d087. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(in_ECX + 0x14) + 0x2c))();
      return;
    }
  }
  return;
}


// ==== FUN_0075d090 @ 0x0075d090 ====

undefined4 FUN_0075d090(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_invenwnd_009f2ed4,0xd);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x20))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_invenwnd_009f2ee4,0xd);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x24))();
    return 1;
  }
  return 0;
}


// ==== FUN_0075d0f0 @ 0x0075d0f0 ====

undefined4 FUN_0075d0f0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_0075d090(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0075d120 @ 0x0075d120 ====

void FUN_0075d120(undefined4 param_1)

{
  code *pcVar1;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994998;
  local_c = ExceptionList;
  switch(param_1) {
  case 0:
    ExceptionList = &local_c;
    FUN_00791470();
    ExceptionList = local_c;
    return;
  case 1:
    ExceptionList = &local_c;
    FUN_00791310();
    ExceptionList = local_c;
    return;
  case 2:
    ExceptionList = &local_c;
    FUN_00790a90();
    ExceptionList = local_c;
    return;
  case 3:
    ExceptionList = &local_c;
    FUN_007911f0();
    ExceptionList = local_c;
    return;
  case 4:
    ExceptionList = &local_c;
    FUN_00790980();
    ExceptionList = local_c;
    return;
  case 5:
    ExceptionList = &local_c;
    FUN_00790860();
    ExceptionList = local_c;
    return;
  case 6:
    ExceptionList = &local_c;
    FUN_00790400();
    ExceptionList = local_c;
    return;
  case 7:
    ExceptionList = &local_c;
    FUN_007900d0();
    ExceptionList = local_c;
    return;
  case 8:
    ExceptionList = &local_c;
    FUN_0078fcc0();
    ExceptionList = local_c;
    return;
  case 9:
    ExceptionList = &local_c;
    FUN_0078f610();
    ExceptionList = local_c;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_FALSE_009f2e80,5);
  local_4 = 0;
  FUN_00406880(local_28);
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_0075d2a0 @ 0x0075d2a0 ====

void FUN_0075d2a0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EDI;
  undefined1 auStack_46 [2];
  uint local_44;
  undefined1 local_40;
  void *pvStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  void *local_30;
  undefined4 local_2c;
  void *local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009949d5;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *puVar1 = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f302c;
  *puVar1 = &PTR_FUN_009f301c;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  local_4 = 1;
  *(undefined1 *)((int)in_ECX + 0x13) = 0;
  in_ECX[5] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a78c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a78c = in_ECX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(&DAT_009f2e86,0);
  local_4._0_1_ = 2;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = 0;
  FUN_00401740(s_show_invenwnd_009f2e88,0xd);
  local_4 = CONCAT31(local_4._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 8))(&local_44,0,&local_28);
  if (0xf < uStack_38) {
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10._0_1_ = 1;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  FUN_00401740(&DAT_009f2e96,0);
  local_10._0_1_ = 4;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_invenwnd_009f2e98,0xd);
  local_10 = CONCAT31(local_10._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,auStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c = CONCAT31(uStack_1c._1_3_,1);
  if ((void *)0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  (**(code **)(*DAT_00b5a790 + 0xc))(puVar1);
  *(undefined1 *)((int)in_ECX + 0x12) = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  *(undefined2 *)(in_ECX + 4) = 0;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  uVar2 = FUN_00791470();
  in_ECX[5] = uVar2;
  ExceptionList = local_28;
  return;
}


// ==== FUN_0075d470 @ 0x0075d470 ====

void FUN_0075d470(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  undefined4 *local_2c;
  void *local_28;
  undefined1 local_24;
  void *pvStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00994a1e;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f302c;
  *puVar1 = &PTR_FUN_009f301c;
  local_4 = 1;
  DAT_00b5a78c = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_invenwnd_009f2ea8,0xd);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8._0_1_ = 1;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  pvStack_18 = (void *)0x0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_invenwnd_009f2eb8,0xd);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  if ((void *)0xf < pvStack_18) {
    _free(local_2c);
    return;
  }
  (**(code **)(*DAT_00b5a790 + 0x10))(puVar1);
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
  *puVar1 = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f2f8c;
  ExceptionList = pvStack_18;
  return;
}


// ==== FUN_0075d590 @ 0x0075d590 ====

uint FUN_0075d590(void)

{
  code *pcVar1;
  uint extraout_EAX;
  uint uVar2;
  int in_ECX;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  int iStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994a30;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iStack_14 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iStack_14 != 0) {
    ExceptionList = pvStack_c;
    return (uint)*(byte *)(in_ECX + 0x18);
  }
  uStack_10 = 0xf;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pPC____NULL_009f2ec8,0xb);
  uStack_4 = 0;
  FUN_00406880(auStack_28);
  if (uStack_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  _free(pvStack_24);
  return extraout_EAX;
}


// ==== FUN_0075d620 @ 0x0075d620 ====

void FUN_0075d620(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994a4a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x14) + 4))();
  if (iVar1 == param_1) {
    (**(code **)(**(int **)(in_ECX + 0x14) + 4))();
    FUN_00401740(&DAT_009f2ef4,0x24);
    uVar2 = FUN_00404230(auStack_28);
    uStack_4 = 0;
    FUN_00796d50(uVar2);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
  }
  else {
    if (param_1 != 0) {
      (**(code **)(**(int **)(in_ECX + 0x14) + 4))();
      FUN_00401740(&DAT_009f2f1c,0x24);
      uVar2 = FUN_00404230(auStack_44);
      uStack_4 = 1;
      FUN_00796d50(uVar2);
      uStack_4 = 0xffffffff;
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return;
      }
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    }
    if (*(undefined4 **)(in_ECX + 0x14) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x14))();
    }
    *(undefined4 *)(in_ECX + 0x14) = 0;
    uVar2 = FUN_0075d120();
    *(undefined4 *)(in_ECX + 0x14) = uVar2;
    (**(code **)(*DAT_00b5a790 + 4))();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0075d780 @ 0x0075d780 ====

uint FUN_0075d780(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  uint extraout_EAX;
  uint uVar3;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  void *pvStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994a6c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    uStack_10 = 0xf;
    pvStack_14 = (void *)0x0;
    pvStack_24 = (void *)((uint)pvStack_24._1_3_ << 8);
    FUN_00401740(s_pPC____NULL_009f2f44,0xb);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_24);
    return extraout_EAX;
  }
  if (*(int **)(iVar2 + 0x20) == (int *)0x0) {
    uStack_10 = 0xf;
    pvStack_14 = (void *)0x0;
    pvStack_24 = (void *)((uint)pvStack_24._1_3_ << 8);
    FUN_00401740(s_pBag____NULL_009f2f50,0xc);
    uStack_4 = 1;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_24);
    return extraout_EAX_00;
  }
  if (*(int *)(iVar2 + 0x1c) != 0) {
    iVar2 = (**(code **)(**(int **)(iVar2 + 0x20) + 0x14))(param_1,*(int *)(iVar2 + 0x1c));
    ExceptionList = pvStack_14;
    return (uint)(iVar2 == 4);
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pCursor____NULL_009f2f60,0xf);
  uStack_4 = 2;
  FUN_00406880(auStack_44);
  uStack_4 = 0xffffffff;
  if (uStack_2c < 0x10) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_40);
  return extraout_EAX_01;
}


// ==== FUN_0075d8e0 @ 0x0075d8e0 ====

undefined4 FUN_0075d8e0(void)

{
  return 0x70080002;
}


// ==== FUN_0075d8f0 @ 0x0075d8f0 ====

void FUN_0075d8f0(void)

{
  FUN_0075d910();
  return;
}


// ==== FUN_0075d900 @ 0x0075d900 ====

void FUN_0075d900(void)

{
  FUN_0075cf40();
  return;
}


// ==== FUN_0075d910 @ 0x0075d910 ====

void FUN_0075d910(byte param_1)

{
  void *in_ECX;
  
  FUN_0075d470();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075d930 @ 0x0075d930 ====

void FUN_0075d930(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f31dc;
  return;
}


// ==== FUN_0075d940 @ 0x0075d940 ====

void FUN_0075d940(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f31dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075d960 @ 0x0075d960 ====

undefined4 FUN_0075d960(void)

{
  return 0x70080005;
}


// ==== FUN_0075d970 @ 0x0075d970 ====

void FUN_0075d970(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f3210;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0075d9a0 @ 0x0075d9a0 ====

undefined4 FUN_0075d9a0(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00b5a97c != 0) {
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    if ((iVar1 != 0) && (*(int **)(iVar1 + 0x1c) != (int *)0x0)) {
      uVar2 = (**(code **)(**(int **)(iVar1 + 0x1c) + 0x1c))
                        (0,&Framework::IArticle::RTTI_Type_Descriptor,
                         &Framework::Article::IItem::RTTI_Type_Descriptor,0);
      uVar2 = FUN_00803725(uVar2);
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_0075d9e0 @ 0x0075d9e0 ====

void FUN_0075d9e0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 8);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*(int *)puVar3[3] + 4))();
    if (*(char *)((int)puVar3 + 0x11) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x11) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x11);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x11);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x11);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x11);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_0075da40 @ 0x0075da40 ====

void FUN_0075da40(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined4 uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  void *pvStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 *puStack_4;
  
  puStack_4 = (undefined4 *)0xffffffff;
  puStack_8 = &LAB_00994a90;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    uStack_10 = 0xf;
    pvStack_14 = (void *)0x0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f30e0,0xb);
    puStack_4 = (undefined4 *)0x0;
    FUN_00406880(auStack_28);
    puStack_4 = (undefined4 *)0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  piVar1 = *(int **)(iVar3 + 0x20);
  if (piVar1 != (int *)0x0) {
    uStack_4c = 0;
    uStack_4b = 0;
    uStack_4a = 0;
    uStack_48 = (**(code **)(*piVar1 + 0x30))();
    (**(code **)(*piVar1 + 0x18))(uStack_48,&uStack_4c);
    puStack_4[1] = unaff_EBX;
    *puStack_4 = unaff_ESI;
    ExceptionList = pvStack_14;
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pBag____NULL_009f30ec,0xc);
  puStack_4 = (undefined4 *)0x1;
  FUN_00406880(auStack_44);
  puStack_4 = (undefined4 *)0xffffffff;
  if (uStack_2c < 0x10) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_0075db70 @ 0x0075db70 ====

uint FUN_0075db70(undefined4 param_1)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
  uint extraout_EAX;
  uint uVar4;
  uint extraout_EAX_00;
  int *in_ECX;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994aaa;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    pvStack_10 = (void *)0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f30fc,0xb);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (pvStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    _free(pvStack_24);
    return extraout_EAX;
  }
  if (*(int **)(iVar3 + 0x20) != (int *)0x0) {
    bVar2 = (**(code **)(**(int **)(iVar3 + 0x20) + 0x40))(param_1);
    (**(code **)(*in_ECX + 4))();
    ExceptionList = pvStack_10;
    return (uint)bVar2;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pBag____NULL_009f3108,0xc);
  uStack_4 = 1;
  FUN_00406880(auStack_44);
  uStack_4 = 0xffffffff;
  if (uStack_2c < 0x10) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    uVar4 = (*pcVar1)();
    return uVar4;
  }
  _free(pvStack_40);
  return extraout_EAX_00;
}


// ==== FUN_0075dc90 @ 0x0075dc90 ====

void FUN_0075dc90(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined4 uStack_48;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  void *pvStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 *puStack_4;
  
  puStack_4 = (undefined4 *)0xffffffff;
  puStack_8 = &LAB_00994ac4;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    uStack_10 = 0xf;
    pvStack_14 = (void *)0x0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f3118,0xb);
    puStack_4 = (undefined4 *)0x0;
    FUN_00406880(auStack_28);
    puStack_4 = (undefined4 *)0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  piVar1 = *(int **)(iVar3 + 0x20);
  if (piVar1 != (int *)0x0) {
    uStack_4c = 0;
    uStack_4b = 0;
    uStack_4a = 0;
    uStack_48 = (**(code **)(*piVar1 + 0x34))();
    (**(code **)(*piVar1 + 0x18))(uStack_48,&uStack_4c);
    puStack_4[1] = unaff_EBX;
    *puStack_4 = unaff_ESI;
    ExceptionList = pvStack_14;
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pBag____NULL_009f3124,0xc);
  puStack_4 = (undefined4 *)0x1;
  FUN_00406880(auStack_44);
  puStack_4 = (undefined4 *)0xffffffff;
  if (uStack_2c < 0x10) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_0075ddc0 @ 0x0075ddc0 ====

undefined4 FUN_0075ddc0(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 extraout_EAX_00;
  int *piVar4;
  undefined4 extraout_EAX_01;
  undefined4 *puVar5;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994ae6;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24._1_3_ << 8);
    FUN_00401740(s_pPC____NULL_009f3134,0xb);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_24);
    return extraout_EAX;
  }
  if (*(int **)(iVar2 + 0x20) == (int *)0x0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24._1_3_ << 8);
    FUN_00401740(s_pBag____NULL_009f3140,0xc);
    uStack_4 = 1;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_24);
    return extraout_EAX_00;
  }
  piVar4 = (int *)(**(code **)(**(int **)(iVar2 + 0x20) + 0x54))();
  if (piVar4 != (int *)0x0) {
    puVar5 = (undefined4 *)(**(code **)(*piVar4 + 4))();
    ExceptionList = pvStack_c;
    return *puVar5;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pAccount____NULL_009f3150,0x10);
  uStack_4 = 2;
  FUN_00406880(auStack_44);
  uStack_4 = 0xffffffff;
  if (uStack_2c < 0x10) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_40);
  return extraout_EAX_01;
}


// ==== FUN_0075df20 @ 0x0075df20 ====

void FUN_0075df20(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00994b08;
  pvStack_c = ExceptionList;
  if ((param_1 < 0) || (0x14 < param_1)) {
    local_10 = (void *)0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    ExceptionList = &pvStack_c;
    FUN_00401740(s_ePlace_>__0____ePlace_<_IInven::_009f3164,0x34);
    local_4 = 0;
    FUN_00406880(local_28);
    local_4 = 0xffffffff;
    if (local_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_24);
    return;
  }
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    local_10 = (void *)0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f319c,0xb);
    local_4 = 1;
    FUN_00406880(local_28);
    local_4 = 0xffffffff;
    if (local_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_24);
    return;
  }
  if (*(int **)(iVar2 + 0x24) != (int *)0x0) {
    (**(code **)(**(int **)(iVar2 + 0x24) + 0x2c))(param_1);
    ExceptionList = local_10;
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pSuit____NULL_009f31a8,0xd);
  local_4 = 2;
  FUN_00406880(auStack_44);
  local_4 = 0xffffffff;
  if (uStack_2c < 0x10) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_0075e080 @ 0x0075e080 ====

void FUN_0075e080(undefined1 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994b22;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    pvStack_10 = (void *)0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f31b8,0xb);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (pvStack_10 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  if (*(int **)(iVar2 + 0x20) != (int *)0x0) {
    (**(code **)(**(int **)(iVar2 + 0x20) + 0x28))(&param_1);
    ExceptionList = pvStack_10;
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pBag____NULL_009f31c4,0xc);
  uStack_4 = 1;
  FUN_00406880(auStack_44);
  uStack_4 = 0xffffffff;
  if (uStack_2c < 0x10) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_0075e190 @ 0x0075e190 ====

void FUN_0075e190(undefined1 param_1)

{
  undefined1 local_8 [8];
  
  FUN_00752030(local_8,&param_1);
  return;
}


// ==== FUN_0075e1b0 @ 0x0075e1b0 ====

void FUN_0075e1b0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00994b34;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f3224;
  DAT_00b5a790 = 0;
  local_4 = 0;
  FUN_007520f0(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0075e230 @ 0x0075e230 ====

void FUN_0075e230(undefined1 param_1)

{
  FUN_00752400(&param_1);
  return;
}


// ==== FUN_0075e240 @ 0x0075e240 ====

void FUN_0075e240(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00994b46;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f3224;
  iVar1 = FUN_00751a80();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x11) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a790 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a790 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0075e2d0 @ 0x0075e2d0 ====

void FUN_0075e2d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0075e1b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075e2f0 @ 0x0075e2f0 ====

void FUN_0075e2f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f32a8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075e310 @ 0x0075e310 ====

void FUN_0075e310(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x50e0002;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  FUN_004244d0();
  return;
}


// ==== FUN_0075e340 @ 0x0075e340 ====

void FUN_0075e340(undefined1 *param_1)

{
  undefined1 *puVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = 0;
  if (*(char *)(in_ECX + 0x10) == '\0') {
    param_1[*(byte *)(in_ECX + 0x10)] = 0;
    return;
  }
  puVar1 = param_1;
  do {
    *puVar1 = puVar1[(in_ECX + 0x14) - (int)param_1];
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < *(byte *)(in_ECX + 0x10));
  param_1[*(byte *)(in_ECX + 0x10)] = 0;
  return;
}


// ==== FUN_0075e390 @ 0x0075e390 ====

void FUN_0075e390(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if (*(char *)(in_ECX + 0x11) == '\0') {
    *(undefined1 *)((uint)*(byte *)(in_ECX + 0x11) + param_1) = 0;
    return;
  }
  do {
    *(undefined1 *)(uVar1 + param_1) =
         *(undefined1 *)(*(byte *)(in_ECX + 0x10) + uVar1 + 0x14 + in_ECX);
    uVar1 = uVar1 + 1;
  } while (uVar1 < *(byte *)(in_ECX + 0x11));
  *(undefined1 *)((uint)*(byte *)(in_ECX + 0x11) + param_1) = 0;
  return;
}


// ==== FUN_0075e3e0 @ 0x0075e3e0 ====

void FUN_0075e3e0(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = 0;
  if (*(char *)(in_ECX + 0x12) == '\0') {
    *(undefined1 *)((uint)*(byte *)(in_ECX + 0x12) + param_1) = 0;
    return;
  }
  do {
    *(undefined1 *)(uVar1 + param_1) =
         *(undefined1 *)
          ((uint)*(byte *)(in_ECX + 0x10) + *(byte *)(in_ECX + 0x11) + uVar1 + 0x14 + in_ECX);
    uVar1 = uVar1 + 1;
  } while (uVar1 < *(byte *)(in_ECX + 0x12));
  *(undefined1 *)((uint)*(byte *)(in_ECX + 0x12) + param_1) = 0;
  return;
}


// ==== FUN_0075e430 @ 0x0075e430 ====

uint FUN_0075e430(undefined1 param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 *puVar5;
  int in_ECX;
  char cVar6;
  
  uVar3 = 0;
  do {
    if (*(char *)(uVar3 + param_2) == '\0') goto LAB_0075e454;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x19);
  uVar3 = 0;
LAB_0075e454:
  cVar6 = (char)uVar3;
  *(char *)(in_ECX + 0x11) = cVar6;
  uVar4 = 0;
  do {
    if (*(char *)(uVar4 + param_3) == '\0') goto LAB_0075e470;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x19);
  uVar4 = 0;
LAB_0075e470:
  *(char *)(in_ECX + 0x12) = (char)uVar4;
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  if ((cVar6 == '\0') || ((char)uVar4 == '\0')) {
    return uVar4 & 0xffffff00;
  }
  uVar4 = 0;
  puVar1 = (undefined1 *)(in_ECX + 0x14);
  if (cVar6 != '\0') {
    puVar5 = puVar1;
    do {
      *puVar5 = puVar5[param_2 - (int)puVar1];
      uVar3 = (uint)*(byte *)(in_ECX + 0x11);
      uVar4 = uVar4 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar4 < uVar3);
  }
  uVar4 = 0;
  if (*(char *)(in_ECX + 0x12) != '\0') {
    do {
      puVar1[*(byte *)(in_ECX + 0x11) + uVar4] = *(undefined1 *)(uVar4 + param_3);
      uVar3 = (uint)*(byte *)(in_ECX + 0x12);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar3);
  }
  iVar2 = CONCAT22((short)(uVar4 >> 0x10),(ushort)*(byte *)(in_ECX + 0x11)) + 0x14 +
          CONCAT22((short)(uVar3 >> 0x10),(ushort)*(byte *)(in_ECX + 0x12));
  *(short *)(in_ECX + 6) = (short)iVar2;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


// ==== FUN_0075e500 @ 0x0075e500 ====

void FUN_0075e500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f32b4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a9d8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a9d8 = in_ECX;
  return;
}


// ==== FUN_0075e530 @ 0x0075e530 ====

void FUN_0075e530(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a9d8 = 0;
  *in_ECX = &PTR_FUN_009f32a8;
  return;
}


// ==== FUN_0075e550 @ 0x0075e550 ====

undefined4 FUN_0075e550(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *piVar5;
  
  cVar2 = (**(code **)(*DAT_00b5a9e0 + 0x1c))();
  if (cVar2 == '\0') {
    piVar5 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
    (**(code **)*piVar5)(0x13,param_1 + 4);
    iVar1 = *piVar5;
    uVar3 = FUN_007914d0();
    (**(code **)(iVar1 + 4))(uVar3);
    (**(code **)(*DAT_00b5a9dc + 0xc))();
    return 1;
  }
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0x50e0005;
  *(undefined2 *)((int)pvVar4 + 6) = 0x10;
  uVar3 = FUN_004244d0();
  FUN_004d8570(uVar3);
  return 0;
}


// ==== FUN_0075e5e0 @ 0x0075e5e0 ====

void FUN_0075e5e0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  undefined1 auStack_f8 [2];
  undefined1 auStack_f6 [2];
  void *pvStack_f4;
  undefined4 uStack_e4;
  uint uStack_e0;
  void *pvStack_d8;
  undefined4 uStack_c8;
  uint uStack_c4;
  void *pvStack_bc;
  undefined4 uStack_ac;
  uint uStack_a8;
  undefined1 auStack_a4 [28];
  undefined1 auStack_88 [28];
  char acStack_6c [28];
  char acStack_50 [28];
  char acStack_34 [40];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994b71;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5a9e0 + 0x1c))();
  if (cVar1 == '\0') {
    iVar4 = (**(code **)(*DAT_00b5a6e4 + 8))();
    if (*(char *)(iVar4 + 9) != '\x01') {
      acStack_6c[0] = '\0';
      FUN_0075e340(acStack_6c);
      acStack_50[0] = '\0';
      FUN_0075e390(acStack_50);
      acStack_34[0] = '\0';
      FUN_0075e3e0(acStack_34);
      pcVar5 = acStack_6c;
      uStack_a8 = 0xf;
      uStack_ac = 0;
      pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(acStack_6c,(int)pcVar5 - (int)(acStack_6c + 1));
      pcVar5 = acStack_50;
      uStack_4 = 0;
      uStack_e0 = 0xf;
      uStack_e4 = 0;
      pvStack_f4 = (void *)((uint)pvStack_f4 & 0xffffff00);
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(acStack_50,(int)pcVar5 - (int)(acStack_50 + 1));
      pcVar5 = acStack_34;
      uStack_4._0_1_ = 1;
      uStack_c4 = 0xf;
      uStack_c8 = 0;
      pvStack_d8 = (void *)((uint)pvStack_d8 & 0xffffff00);
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      FUN_00401740(acStack_34,(int)pcVar5 - (int)(acStack_34 + 1));
      uStack_4 = CONCAT31(uStack_4._1_3_,2);
      piVar6 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
      (**(code **)*piVar6)(0,auStack_f8);
      iVar4 = *piVar6;
      uVar2 = FUN_00791870(auStack_f8 + -8,&uStack_c8);
      (**(code **)(iVar4 + 4))(uVar2);
      (**(code **)(*DAT_00b5a9dc + 0xc))();
      if (0xf < uStack_c4) {
        _free(pvStack_d8);
        return;
      }
      uStack_c4 = 0xf;
      uStack_c8 = 0;
      pvStack_d8 = (void *)((uint)pvStack_d8 & 0xffffff00);
      if (0xf < uStack_e0) {
        _free(pvStack_f4);
        return;
      }
      uStack_e0 = 0xf;
      uStack_e4 = 0;
      pvStack_f4 = (void *)((uint)pvStack_f4 & 0xffffff00);
      if (uStack_a8 < 0x10) {
        ExceptionList = pvStack_c;
        return;
      }
      _free(pvStack_bc);
      return;
    }
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5100005;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    uVar2 = FUN_004244d0();
    auStack_88[0] = 0;
    FUN_0075e340(auStack_88);
    auStack_a4[0] = 0;
    FUN_0075e390(auStack_a4);
    puVar9 = auStack_a4;
    puVar8 = auStack_88;
    uVar7 = 2;
  }
  else {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5100005;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    uVar2 = FUN_004244d0();
    auStack_a4[0] = 0;
    FUN_0075e340(auStack_a4);
    auStack_88[0] = 0;
    FUN_0075e390(auStack_88);
    puVar9 = auStack_88;
    puVar8 = auStack_a4;
    uVar7 = 0;
  }
  FUN_0075e430(uVar7,puVar8,puVar9);
  FUN_004d8570(uVar2);
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0075e8e0 @ 0x0075e8e0 ====

void FUN_0075e8e0(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  undefined1 *_Memory;
  undefined1 auStack_28 [4];
  undefined1 uStack_24;
  uint uStack_20;
  void *pvStack_1c;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994b83;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5a9e0 + 0x1c))();
  if (cVar1 != '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x50e0002;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined4 *)(iVar4 + 0x10) = 2;
    FUN_004d8570(iVar4);
    ExceptionList = pvStack_c;
    return;
  }
  iVar4 = (**(code **)(*DAT_00b5a6e4 + 8))();
  if (*(char *)(iVar4 + 8) == '\x01') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x50e0002;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined4 *)(iVar4 + 0x10) = 3;
    FUN_004d8570(iVar4);
    ExceptionList = pvStack_c;
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  uStack_24 = 0;
  pcVar5 = (char *)(param_1 + 0x18);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(param_1 + 0x18),(int)pcVar5 - (param_1 + 0x19));
  uStack_4 = 0;
  piVar6 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
  _Memory = auStack_28;
  (**(code **)*piVar6)(0x14);
  iVar4 = *piVar6;
  uVar2 = FUN_007914d0();
  (**(code **)(iVar4 + 4))(uVar2);
  (**(code **)(*DAT_00b5a9dc + 0xc))();
  (**(code **)(*DAT_00b5acd4 + 4))(1);
  if (uStack_20 < 0x10) {
    ExceptionList = pvStack_1c;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0075ea70 @ 0x0075ea70 ====

undefined4 FUN_0075ea70(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x50e0000) {
    FUN_0075e8e0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (iVar1 == 0x5100003) {
    FUN_0075e5e0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_0075eac0 @ 0x0075eac0 ====

undefined4 FUN_0075eac0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0075ea70(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x70110003) {
    cVar1 = FUN_0075e550(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0075eb10 @ 0x0075eb10 ====

void FUN_0075eb10(byte param_1)

{
  void *in_ECX;
  
  FUN_0075e530();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075eb30 @ 0x0075eb30 ====

void FUN_0075eb30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3300;
  return;
}


// ==== FUN_0075eb40 @ 0x0075eb40 ====

void FUN_0075eb40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3300;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075eb60 @ 0x0075eb60 ====

void FUN_0075eb60(void)

{
  return;
}


// ==== FUN_0075eb70 @ 0x0075eb70 ====

undefined1 FUN_0075eb70(void)

{
  return 0;
}


// ==== FUN_0075eb80 @ 0x0075eb80 ====

void FUN_0075eb80(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00994ba3;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *puVar1 = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f3350;
  *puVar1 = &PTR_FUN_009f3344;
  local_4 = 1;
  (**(code **)(*DAT_00b5a9e0 + 8))(puVar1);
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a9dc = (undefined4 *)0x0;
    ExceptionList = in_ECX;
    return;
  }
  DAT_00b5a9dc = in_ECX;
  ExceptionList = in_ECX;
  return;
}


// ==== FUN_0075ec10 @ 0x0075ec10 ====

void FUN_0075ec10(void)

{
                    /* WARNING: Could not recover jumptable at 0x0075ec18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a9e0 + 0x14))();
  return;
}


// ==== FUN_0075ec20 @ 0x0075ec20 ====

void FUN_0075ec20(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f331c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0075ec50 @ 0x0075ec50 ====

void FUN_0075ec50(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f3330;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0075ec80 @ 0x0075ec80 ====

void FUN_0075ec80(void)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x0075ec8f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x14))();
  return;
}


// ==== FUN_0075eca0 @ 0x0075eca0 ====

void FUN_0075eca0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00994bdc;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f3350;
  *puVar1 = &PTR_FUN_009f3344;
  DAT_00b5a9dc = 0;
  local_4 = 1;
  (**(code **)(*DAT_00b5a9e0 + 0xc))(puVar1);
  *puVar1 = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f3300;
  ExceptionList = in_ECX;
  return;
}


// ==== FUN_0075ed10 @ 0x0075ed10 ====

undefined4 FUN_0075ed10(void)

{
  return 0x70060000;
}


// ==== FUN_0075ed20 @ 0x0075ed20 ====

undefined4 FUN_0075ed20(void)

{
  return 0x70060001;
}


// ==== FUN_0075ed30 @ 0x0075ed30 ====

void FUN_0075ed30(void)

{
  FUN_0075ed40();
  return;
}


// ==== FUN_0075ed40 @ 0x0075ed40 ====

void FUN_0075ed40(byte param_1)

{
  void *in_ECX;
  
  FUN_0075eca0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075ed60 @ 0x0075ed60 ====

void FUN_0075ed60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f33ac;
  return;
}


// ==== FUN_0075ed70 @ 0x0075ed70 ====

void FUN_0075ed70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f33ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075ed90 @ 0x0075ed90 ====

void FUN_0075ed90(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0075ed95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)**(undefined4 **)(in_ECX + 0x10))();
  return;
}


// ==== FUN_0075eda0 @ 0x0075eda0 ====

undefined4 FUN_0075eda0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_0075edb0 @ 0x0075edb0 ====

undefined4 FUN_0075edb0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_0075edc0 @ 0x0075edc0 ====

void FUN_0075edc0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x14) = param_1;
  return;
}


// ==== FUN_0075edd0 @ 0x0075edd0 ====

undefined4 FUN_0075edd0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a7a0 + 0x28))();
  if ((*(char *)(in_ECX + 0x14) == '\0') && (iVar1 == 0)) {
    return 0;
  }
  return 1;
}


// ==== FUN_0075edf0 @ 0x0075edf0 ====

void FUN_0075edf0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 8);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*(int *)puVar3[3] + 4))();
    if (*(char *)((int)puVar3 + 0x11) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x11) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x11);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x11);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x11);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x11);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return;
}


// ==== FUN_0075ee50 @ 0x0075ee50 ====

void FUN_0075ee50(undefined1 param_1)

{
  undefined1 local_8 [8];
  
  FUN_00752030(local_8,&param_1);
  return;
}


// ==== FUN_0075ee70 @ 0x0075ee70 ====

void FUN_0075ee70(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00994bf8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f33d4;
  local_4 = 0;
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_0075ef00 @ 0x0075ef00 ====

void FUN_0075ef00(undefined1 param_1)

{
  FUN_00752400(&param_1);
  return;
}


// ==== FUN_0075ef10 @ 0x0075ef10 ====

void FUN_0075ef10(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00994c20;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f33d4;
  iVar1 = FUN_00751a80();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x11) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  local_4._0_1_ = 1;
  *(undefined1 *)(in_ECX + 5) = 0;
  pvVar2 = operator_new(0x38);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_007919d0();
  }
  in_ECX[4] = uVar3;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a9e0 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a9e0 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0075efd0 @ 0x0075efd0 ====

void FUN_0075efd0(byte param_1)

{
  void *in_ECX;
  
  FUN_0075ee70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075eff0 @ 0x0075eff0 ====

void FUN_0075eff0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f344c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075f020 @ 0x0075f020 ====

void FUN_0075f020(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f3458;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad50 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad50 = in_ECX;
  return;
}


// ==== FUN_0075f0b0 @ 0x0075f0b0 ====

void FUN_0075f0b0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad50 = 0;
  *in_ECX = &PTR_FUN_009f344c;
  return;
}


// ==== FUN_0075f0d0 @ 0x0075f0d0 ====

void FUN_0075f0d0(void)

{
  int iVar1;
  int *piVar2;
  undefined1 extraout_var;
  int unaff_retaddr;
  undefined1 auStack_80 [4];
  undefined1 uStack_7c;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  uint uStack_68;
  int iStack_64;
  undefined4 uStack_60;
  void *pvStack_44;
  undefined1 auStack_38 [4];
  uint uStack_34;
  uint uStack_30;
  void *pvStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint uStack_14;
  void *pvStack_10;
  undefined1 *puStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994c40;
  puStack_c = ExceptionList;
  ExceptionList = &puStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (*(int *)(unaff_retaddr + 0x10) == 1) {
    uStack_60 = 0x75f123;
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x20) + 0x28))();
    if (piVar2 != (int *)0x0) {
      uStack_60 = 0;
      iStack_64 = 0;
      uStack_68 = 0x75f137;
      uStack_68 = (**(code **)(*piVar2 + 0x1c))();
      uStack_68 = uStack_68 & 0xffff;
      uStack_6c = 0xd;
      uStack_70 = 0x75f142;
      FUN_004dd240();
      uStack_60 = 0x75f151;
      (**(code **)(*DAT_00b5b130 + 0xc))();
      uStack_60 = CONCAT13(extraout_var,*(undefined3 *)(unaff_retaddr + 0x18));
      uStack_68 = 0x75f167;
      iStack_64 = iVar1;
      FUN_00827380();
      uStack_60 = 0x280018;
      iStack_64 = 0;
      uStack_68 = 0x75f17b;
      uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_68 = 0xffffffff;
      uStack_6c = 0;
      uStack_20 = 0xf;
      uStack_24 = 0;
      uStack_34 = uStack_34 & 0xffffff00;
      uStack_74 = 0x75f199;
      FUN_00401660();
      puStack_c = auStack_80;
      uStack_68 = 0xf;
      uStack_6c = 0;
      uStack_14 = 0;
      uStack_7c = 0;
      FUN_00401660(auStack_38,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0);
      puStack_8 = (undefined1 *)0xffffffff;
      if (0xf < uStack_14) {
        uStack_60 = 0x75f1e5;
        _free(pvStack_28);
        return;
      }
    }
  }
  else if (*(int *)(unaff_retaddr + 0x10) == 0) {
    uStack_60 = 0x75f201;
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x24) + 0x2c))();
    if (piVar2 != (int *)0x0) {
      uStack_60 = 0;
      iStack_64 = 0;
      uStack_68 = 0x75f215;
      uStack_68 = (**(code **)(*piVar2 + 0x1c))();
      uStack_68 = uStack_68 & 0xffff;
      uStack_6c = 0xd;
      uStack_70 = 0x75f220;
      FUN_004dd240();
      uStack_60 = 0x75f22f;
      (**(code **)(*DAT_00b5b130 + 0xc))();
      uStack_60 = *(undefined4 *)(unaff_retaddr + 0x14);
      uStack_68 = 0x75f239;
      iStack_64 = iVar1;
      FUN_008273e0();
      uStack_60 = 0x280018;
      iStack_64 = 0;
      uStack_68 = 0x75f24d;
      uStack_70 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_68 = 0xffffffff;
      uStack_6c = 0;
      uStack_74 = 0x75f26b;
      FUN_00401660();
      puStack_c = auStack_80;
      uStack_68 = 0xf;
      uStack_6c = 0;
      uStack_14 = 1;
      uStack_7c = 0;
      FUN_00401660(auStack_38 + -0x1c,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0);
      puStack_8 = (undefined1 *)0xffffffff;
      if (0xf < uStack_30) {
        uStack_60 = 0x75f2b7;
        _free(pvStack_44);
        return;
      }
      uStack_30 = 0xf;
      uStack_34 = 0;
    }
  }
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 8))();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0075f300 @ 0x0075f300 ====

void FUN_0075f300(void)

{
  int iVar1;
  int *piVar2;
  int unaff_retaddr;
  undefined1 auStack_78 [4];
  uint uStack_74;
  int iStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  uint uStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  void *pvStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  void *pvStack_28;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00994c5a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (*(int *)(unaff_retaddr + 0x10) == 1) {
    iStack_5c = 0x75f352;
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x20) + 0x28))();
    if (piVar2 != (int *)0x0) {
      iStack_5c = 0;
      uStack_60 = 0;
      uStack_64 = 0x75f364;
      uStack_64 = (**(code **)(*piVar2 + 0x1c))();
      uStack_64 = uStack_64 & 0xffff;
      uStack_68 = 0xd;
      uStack_6c = 0x75f36f;
      FUN_004dd240();
      uStack_60 = 0x75f386;
      iStack_5c = iVar1;
      FUN_00827380();
      iStack_5c = 0;
      uStack_60 = 0x75f39a;
      uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_60 = 0xffffffff;
      uStack_64 = 0;
      uStack_1c = 0xf;
      uStack_20 = 0;
      uStack_30 = uStack_30 & 0xffffff00;
      uStack_6c = 0x75f3b8;
      FUN_00401660();
      puStack_8 = auStack_78;
      uStack_60 = 0xf;
      uStack_64 = 0;
      pvStack_10 = (void *)0x0;
      uStack_74 = uStack_74 & 0xffffff00;
      FUN_00401660(&uStack_34,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0);
      puStack_8 = (undefined1 *)0xffffffff;
      if (0xf < uStack_14) {
        iStack_5c = 0x75f404;
        _free(pvStack_28);
        return;
      }
    }
  }
  else if (*(int *)(unaff_retaddr + 0x10) == 0) {
    iStack_5c = 0x75f420;
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x24) + 0x2c))();
    if (piVar2 != (int *)0x0) {
      iStack_5c = 0;
      uStack_60 = 0;
      uStack_64 = 0x75f432;
      uStack_64 = (**(code **)(*piVar2 + 0x1c))();
      uStack_64 = uStack_64 & 0xffff;
      uStack_68 = 0xd;
      uStack_6c = 0x75f43d;
      FUN_004dd240();
      uStack_6c = *(undefined4 *)(unaff_retaddr + 0x14);
      uStack_74 = 0x75f447;
      iStack_70 = iVar1;
      FUN_008273e0();
      iStack_5c = 0;
      uStack_60 = 0x75f45b;
      uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_60 = 0xffffffff;
      uStack_64 = 0;
      uStack_6c = 0x75f479;
      FUN_00401660();
      puStack_8 = auStack_78;
      uStack_60 = 0xf;
      uStack_64 = 0;
      pvStack_10 = (void *)0x1;
      uStack_74 = uStack_74 & 0xffffff00;
      FUN_00401660(auStack_78 + 0x28,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(0);
      puStack_8 = (undefined1 *)0xffffffff;
      if (0xf < uStack_30) {
        iStack_5c = 0x75f4c5;
        _free(pvStack_44);
        return;
      }
      uStack_30 = 0xf;
      uStack_34 = 0;
    }
  }
  (**(code **)(*DAT_00b5a790 + 4))();
  (**(code **)(*DAT_00b5ad58 + 8))();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0075f500 @ 0x0075f500 ====

undefined4 FUN_0075f500(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x5010001) {
    FUN_0075f0d0(*(undefined4 *)(param_1 + 0xc));
  }
  else {
    if (iVar1 == 0x5010003) {
      FUN_0075f300(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (iVar1 != 0x7000046) {
      return 0;
    }
    iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    if (iVar1 != 0) {
      FUN_0082a230(iVar1);
      FUN_0082a1d0(iVar1);
      (**(code **)(*DAT_00b5ad58 + 8))();
      return 1;
    }
  }
  return 1;
}


// ==== FUN_0075f580 @ 0x0075f580 ====

undefined4 FUN_0075f580(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_0075f500(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0075f5b0 @ 0x0075f5b0 ====

void FUN_0075f5b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0075f0b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075f5d0 @ 0x0075f5d0 ====

void FUN_0075f5d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f35e4;
  return;
}


// ==== FUN_0075f5e0 @ 0x0075f5e0 ====

void FUN_0075f5e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f35e4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0075f650 @ 0x0075f650 ====

void FUN_0075f650(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 8);
  param_1[1] = *(undefined4 *)(in_ECX + 0xc);
  param_1[2] = *(undefined4 *)(in_ECX + 0x10);
  return;
}


// ==== FUN_0075f670 @ 0x0075f670 ====

undefined1 FUN_0075f670(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_0075f680 @ 0x0075f680 ====

void FUN_0075f680(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_0075f6a0 @ 0x0075f6a0 ====

void FUN_0075f6a0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f3658;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0075f6d0 @ 0x0075f6d0 ====

void FUN_0075f6d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f366c;
  }
  FUN_00797a20(puVar1);
                    /* WARNING: Could not recover jumptable at 0x0075f6f9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a6e4 + 0x14))();
  return;
}


// ==== FUN_0075f700 @ 0x0075f700 ====

int FUN_0075f700(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a6e4 + 8))();
  return iVar1 + 0x24;
}


// ==== FUN_0075f710 @ 0x0075f710 ====

int FUN_0075f710(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a6e4 + 8))();
  return iVar1 + 0x2c;
}


// ==== FUN_0075f720 @ 0x0075f720 ====

int FUN_0075f720(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a6e4 + 8))();
  return iVar1 + 0x34;
}


// ==== FUN_0075f730 @ 0x0075f730 ====

undefined1 FUN_0075f730(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a6e4 + 8))();
  return *(undefined1 *)(iVar1 + 0xe);
}


// ==== FUN_0075f740 @ 0x0075f740 ====

void FUN_0075f740(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_64 [9];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  uVar1 = param_1[1];
  puVar4 = auStack_64;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  uStack_40 = *param_1;
  uStack_3c = uVar1;
  (**(code **)(*DAT_00b5a6e4 + 0x10))(auStack_64);
  return;
}


// ==== FUN_0075f790 @ 0x0075f790 ====

void FUN_0075f790(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_64 [11];
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  uVar1 = param_1[1];
  puVar4 = auStack_64;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  uStack_38 = *param_1;
  uStack_34 = uVar1;
  (**(code **)(*DAT_00b5a6e4 + 0x10))(auStack_64);
  return;
}


// ==== FUN_0075f7e0 @ 0x0075f7e0 ====

void FUN_0075f7e0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_64 [13];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  uVar1 = param_1[1];
  puVar4 = auStack_64;
  for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  uStack_30 = *param_1;
  uStack_2c = uVar1;
  (**(code **)(*DAT_00b5a6e4 + 0x10))(auStack_64);
  return;
}


// ==== FUN_0075f830 @ 0x0075f830 ====

void FUN_0075f830(undefined1 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_64 [3];
  undefined1 uStack_56;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar3 = auStack_64;
  for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  uStack_56 = param_1;
  (**(code **)(*DAT_00b5a6e4 + 0x10))(auStack_64);
  return;
}


// ==== FUN_0075f870 @ 0x0075f870 ====

undefined4 FUN_0075f870(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x48))();
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (*(int *)(iVar2 + 8) == 9) {
    (**(code **)(*DAT_00b5b130 + 0x10))(param_2);
    piVar1 = (int *)(**(code **)(*param_1 + 0x48))();
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (*(int *)(iVar2 + 0xc) == 0x901) {
      puVar3 = operator_new(0xc);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        *puVar3 = &PTR_FUN_009eaeb4;
      }
      puVar3[1] = 5000;
      *(undefined1 *)(puVar3 + 2) = 3;
      FUN_00797a20(puVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0075f8f0 @ 0x0075f8f0 ====

uint FUN_0075f8f0(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  uint uVar9;
  int *in_ECX;
  
  piVar5 = (int *)(**(code **)(*in_ECX + 4))(param_1);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  uVar6 = (**(code **)(*DAT_00b5ad20 + 0x54))(piVar5);
  uVar6 = uVar6 & 0xffff;
  iVar7 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  piVar1 = *(int **)(iVar7 + 0x20);
  piVar8 = (int *)(**(code **)(*piVar1 + 0x30))();
  while (piVar8 != (int *)0x0) {
    sVar3 = (**(code **)(*piVar8 + 0x1c))();
    sVar4 = (**(code **)(*piVar5 + 0x1c))();
    if ((sVar3 == sVar4) && (cVar2 = (**(code **)(*DAT_00b5ad20 + 0x50))(piVar8), cVar2 == '\x01'))
    {
      uVar9 = (**(code **)(*DAT_00b5ad20 + 0x54))(piVar8);
      uVar6 = uVar6 + (uVar9 & 0xffff);
    }
    piVar8 = (int *)(**(code **)(*piVar1 + 0x34))();
  }
  return uVar6;
}


// ==== FUN_0075f9b0 @ 0x0075f9b0 ====

undefined4 FUN_0075f9b0(uint param_1)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  uVar1 = param_1;
  if (param_1 < 9) {
    param_1 = param_1 & 0xffff0000;
    iVar3 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x40) + 0x1c))();
    uVar2 = (**(code **)(*piVar4 + 0x1c))();
    param_1._0_2_ = CONCAT11((char)uVar1,uVar2);
    iVar3 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x40) + 0x1c))();
    uVar5 = (**(code **)(*piVar4 + 8))(&param_1);
    return uVar5;
  }
  return 0;
}


// ==== FUN_0075fa10 @ 0x0075fa10 ====

undefined2 FUN_0075fa10(uint param_1)

{
  uint uVar1;
  undefined1 uVar2;
  int iVar3;
  int *piVar4;
  
  uVar1 = param_1;
  if (param_1 < 9) {
    param_1 = param_1 & 0xffff0000;
    iVar3 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x40) + 0x1c))();
    uVar2 = (**(code **)(*piVar4 + 0x1c))();
    param_1._0_2_ = CONCAT11((char)uVar1,uVar2);
    iVar3 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x40) + 0x1c))();
    piVar4 = (int *)(**(code **)(*piVar4 + 8))(&param_1);
    if (piVar4 != (int *)0x0) {
      piVar4 = (int *)(**(code **)(*piVar4 + 0x10))();
      iVar3 = (**(code **)(*piVar4 + 4))();
      return *(undefined2 *)(iVar3 + 0x2bb8);
    }
  }
  return 0;
}


// ==== FUN_0075fa90 @ 0x0075fa90 ====

void FUN_0075fa90(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x40) + 0x1c))();
                    /* WARNING: Could not recover jumptable at 0x0075faa7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0x10))();
  return;
}


// ==== FUN_0075fab0 @ 0x0075fab0 ====

int FUN_0075fab0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x40) + 0x1c))();
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  iVar1 = (**(code **)(*piVar2 + 0x1c))();
  return iVar1 + 1;
}


// ==== FUN_0075fae0 @ 0x0075fae0 ====

void FUN_0075fae0(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x40) + 0x1c))();
  uVar3 = (**(code **)(*piVar2 + 0x1c))();
  uVar3 = (uVar3 & 0xff) + 1;
  if (1 < uVar3) {
    uVar3 = 0;
  }
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x40) + 0x1c))();
  (**(code **)(*piVar2 + 0x14))(uVar3);
                    /* WARNING: Could not recover jumptable at 0x0075fb2c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ad58 + 8))();
  return;
}


// ==== FUN_0075fb30 @ 0x0075fb30 ====

void FUN_0075fb30(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x40) + 0x1c))();
  uVar3 = (**(code **)(*piVar2 + 0x1c))();
  if ((uVar3 & 0xff) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = (uVar3 & 0xff) - 1;
  }
  iVar4 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar4 + 0x40) + 0x1c))();
  (**(code **)(*piVar2 + 0x14))(iVar1);
                    /* WARNING: Could not recover jumptable at 0x0075fb80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ad58 + 8))();
  return;
}


// ==== FUN_0075fb90 @ 0x0075fb90 ====

void FUN_0075fb90(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined2 *puVar9;
  int in_ECX;
  int *unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(1);
  if (cVar1 == '\0') {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined2 *)((int)pvVar4 + 6) = 0x14;
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    if (unaff_retaddr == (int *)0x0) {
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x5150006;
      iVar5 = FUN_004244d0();
      iVar6 = (**(code **)(*DAT_00b5ac1c + 0x14))();
      piVar7 = (int *)(**(code **)(**(int **)(iVar6 + 0x40) + 0x1c))();
      uVar2 = (**(code **)(*piVar7 + 0x1c))();
      *(undefined1 *)(iVar5 + 0x10) = uVar2;
      *(char *)(iVar5 + 0x11) = (char)param_1;
      FUN_004d8570(iVar5);
      (**(code **)(*DAT_00b5af2c + 4))(1);
      *(undefined4 *)(in_ECX + 8) = 0;
      *(undefined4 *)(in_ECX + 0xc) = param_1;
      iVar5 = (**(code **)(*DAT_00b5ac1c + 0x14))();
      piVar7 = (int *)(**(code **)(**(int **)(iVar5 + 0x40) + 0x1c))();
      uVar8 = (**(code **)(*piVar7 + 0x1c))();
      *(uint *)(in_ECX + 0x10) = uVar8 & 0xff;
      return;
    }
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5150004;
    iVar5 = FUN_004244d0();
    iVar6 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    piVar7 = (int *)(**(code **)(**(int **)(iVar6 + 0x40) + 0x1c))();
    uVar2 = (**(code **)(*piVar7 + 0x1c))();
    *(undefined1 *)(iVar5 + 0x12) = uVar2;
    *(char *)(iVar5 + 0x13) = (char)param_1;
    piVar7 = (int *)(**(code **)(*unaff_retaddr + 0x18))();
    puVar9 = (undefined2 *)(**(code **)(*piVar7 + 0xc))();
    *(undefined2 *)(iVar5 + 0x10) = *puVar9;
    FUN_004d8570(iVar5);
    (**(code **)(*DAT_00b5af2c + 4))(1);
    *(int **)(in_ECX + 8) = unaff_retaddr;
    *(undefined4 *)(in_ECX + 0xc) = param_1;
    iVar5 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    piVar7 = (int *)(**(code **)(**(int **)(iVar5 + 0x40) + 0x1c))();
    uVar8 = (**(code **)(*piVar7 + 0x1c))();
    *(uint *)(in_ECX + 0x10) = uVar8 & 0xff;
  }
  return;
}


// ==== FUN_0075fce0 @ 0x0075fce0 ====

undefined4 FUN_0075fce0(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_maintoolbar_009f3510,0x10);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x60))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_maintoolbar_009f3524,0x10);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 100))();
    return 1;
  }
  return 0;
}


// ==== FUN_0075fd40 @ 0x0075fd40 ====

undefined4 FUN_0075fd40(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_0075fce0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0075fd70 @ 0x0075fd70 ====

void FUN_0075fd70(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EDI;
  undefined1 auStack_46 [2];
  uint local_44;
  void *local_40;
  void *pvStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  void *local_30;
  uint local_2c;
  uint local_28;
  void *local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00994ca0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f3684;
  local_4 = 0;
  if (DAT_00b5ad58 == 0) {
    local_2c = 0xf;
    local_30 = (void *)0x0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740(s_IMainToolBar__IREFERENCE______NU_009f349c,0x22);
    local_4._0_1_ = 1;
    FUN_00406880(&local_44);
    local_4 = (uint)local_4._1_3_ << 8;
    if (local_2c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_40);
    return;
  }
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad54 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ad54 = in_ECX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_009f34bf,0);
  local_4._0_1_ = 2;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401740(s_show_maintoolbar_009f34c0,0x10);
  local_4 = CONCAT31(local_4._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 8))(&local_44,0,&local_28);
  if (0xf < uStack_38) {
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  FUN_00401740(&DAT_009f34d1,0);
  local_10._0_1_ = 4;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_maintoolbar_009f34d4,0x10);
  local_10 = CONCAT31(local_10._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,auStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  if (local_28 < 0x10) {
    *(undefined1 *)(in_ECX + 1) = 1;
    ExceptionList = local_24;
    return;
  }
  _free(pvStack_3c);
  return;
}


// ==== FUN_0075ff40 @ 0x0075ff40 ====

void FUN_0075ff40(void)

{
  undefined4 *in_ECX;
  undefined4 *local_2c;
  void *local_28;
  undefined1 local_24;
  uint uStack_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00994cc2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f3684;
  local_4 = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_maintoolbar_009f34e8,0x10);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = (void *)0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_maintoolbar_009f34fc,0x10);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  if (uStack_18 < 0x10) {
    DAT_00b5ad54 = 0;
    *in_ECX = &PTR_FUN_009f35e4;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


