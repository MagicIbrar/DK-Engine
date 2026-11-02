// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x770000-0x77ffff

// ==== FUN_00770060 @ 0x00770060 ====

void FUN_00770060(void)

{
  undefined4 uVar1;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099604a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Quest_Record_Received__Quest___d_009f4dc0,0x21);
  uVar1 = FUN_00404230(local_28);
  local_4 = 0;
  FUN_00796d50(uVar1);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = (void *)0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    (**(code **)(*DAT_00b5ac1c + 0x14))();
    FUN_0082a450();
    (**(code **)(*DAT_00b5ac3c + 0x18))();
    (**(code **)(*DAT_00b5ae6c + 0x20))();
    ExceptionList = local_10;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00770130 @ 0x00770130 ====

void FUN_00770130(void)

{
  undefined4 uVar1;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099605c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_Quest_Delete_Received__Quest___d_009f4de4,0x20);
  uVar1 = FUN_00404230(local_28);
  local_4 = 0;
  FUN_00796d50(uVar1);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    (**(code **)(*DAT_00b5ac1c + 0x14))();
    FUN_0082a480();
    (**(code **)(*DAT_00b5ac3c + 0x18))();
    ExceptionList = pvStack_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00770200 @ 0x00770200 ====

void FUN_00770200(int param_1)

{
  undefined1 auStack_6c [4];
  undefined1 uStack_68;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  void *pvStack_40;
  uint uStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00996076;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    uStack_50 = 0x77023f;
    ExceptionList = &pvStack_c;
    FUN_00401830();
    local_4 = (undefined1 *)0x0;
    uStack_50 = 0x770251;
    FUN_00796d50();
    local_4 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  case 1:
    break;
  case 2:
    break;
  default:
    goto switchD_0077022a_caseD_3;
  case 4:
  }
  uStack_50 = 0;
  uStack_54 = 0x77028c;
  ExceptionList = &pvStack_c;
  uStack_5c = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_54 = 0xffffffff;
  uStack_58 = 0;
  uStack_60 = 0x7702a9;
  FUN_00401660();
  local_4 = auStack_6c;
  uStack_54 = 0xf;
  uStack_58 = 0;
  pvStack_c = (void *)0x1;
  uStack_68 = 0;
  FUN_00401660(auStack_6c + 0x20,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  local_4 = (undefined1 *)0xffffffff;
  if (0xf < uStack_2c) {
    uStack_50 = 0x7702fa;
    _free(pvStack_40);
    return;
  }
switchD_0077022a_caseD_3:
  local_4 = (undefined1 *)0xffffffff;
  (**(code **)(*DAT_00b5ac38 + 0x4c))();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00770340 @ 0x00770340 ====

undefined4 FUN_00770340(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x5250001) {
    if (uVar1 == 0x5250000) {
      (**(code **)(*DAT_00b5ac38 + 0x44))(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10));
      return 1;
    }
    switch(uVar1 + 0xfaf0ffff) {
    case 0:
      FUN_0076faa0(*(undefined4 *)(param_1 + 0xc));
      break;
    case 1:
      FUN_0076fbe0(*(undefined4 *)(param_1 + 0xc));
      break;
    case 2:
      FUN_0076fd70(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 3:
      FUN_0076fe50(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 4:
      FUN_0076ff20(*(undefined4 *)(param_1 + 0xc));
      break;
    default:
      goto switchD_0077036f_caseD_5;
    case 8:
      FUN_00770060(*(undefined4 *)(param_1 + 0xc));
      break;
    case 9:
      FUN_00770130(*(undefined4 *)(param_1 + 0xc));
    }
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      FUN_00797a20(0);
      return 1;
    }
    *puVar2 = &PTR_FUN_009f4e50;
    FUN_00797a20(puVar2);
    return 1;
  }
  if (uVar1 == 0x5250002) {
    FUN_00770200(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  if (uVar1 == 0x5250004) {
    (**(code **)(*DAT_00b5ac38 + 0x4c))();
    return 1;
  }
switchD_0077036f_caseD_5:
  return 0;
}


// ==== FUN_00770490 @ 0x00770490 ====

undefined4 FUN_00770490(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00770340(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007704c0 @ 0x007704c0 ====

void FUN_007704c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0076fa80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007704e0 @ 0x007704e0 ====

void FUN_007704e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5014;
  return;
}


// ==== FUN_007704f0 @ 0x007704f0 ====

void FUN_007704f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5014;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00770510 @ 0x00770510 ====

void FUN_00770510(undefined1 param_1,undefined2 param_2)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 10) = param_1;
  *(undefined2 *)(in_ECX + 8) = param_2;
  return;
}


// ==== FUN_00770530 @ 0x00770530 ====

void FUN_00770530(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00770532. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x38))();
  return;
}


// ==== FUN_00770540 @ 0x00770540 ====

bool FUN_00770540(void)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x3c))();
  return cVar1 == '\x01';
}


// ==== FUN_00770550 @ 0x00770550 ====

undefined4 FUN_00770550(int *param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = (**(code **)(*in_ECX + 100))(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00770580 @ 0x00770580 ====

undefined1 FUN_00770580(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xb);
}


// ==== FUN_00770590 @ 0x00770590 ====

undefined1 FUN_00770590(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xc);
}


// ==== FUN_007705a0 @ 0x007705a0 ====

void FUN_007705a0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099608b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x18);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006ef930(param_1);
  }
  local_4 = 0xffffffff;
  (**(code **)(*DAT_00b5ac3c + 0x10))(uVar2);
  ExceptionList = pvVar1;
  return;
}


// ==== FUN_00770610 @ 0x00770610 ====

void FUN_00770610(void)

{
                    /* WARNING: Could not recover jumptable at 0x00770618. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ac3c + 0x14))();
  return;
}


// ==== FUN_00770620 @ 0x00770620 ====

void FUN_00770620(void)

{
                    /* WARNING: Could not recover jumptable at 0x00770628. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ac3c + 4))();
  return;
}


// ==== FUN_00770630 @ 0x00770630 ====

void FUN_00770630(void)

{
                    /* WARNING: Could not recover jumptable at 0x00770638. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ac3c + 8))();
  return;
}


// ==== FUN_00770640 @ 0x00770640 ====

void FUN_00770640(void)

{
                    /* WARNING: Could not recover jumptable at 0x00770648. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ac3c + 0xc))();
  return;
}


// ==== FUN_00770650 @ 0x00770650 ====

void FUN_00770650(undefined2 *param_1)

{
  char cVar1;
  int in_ECX;
  undefined1 *unaff_retaddr;
  
  cVar1 = (**(code **)(*DAT_00b5ac3c + 0x1c))(*(undefined2 *)(in_ECX + 8));
  if (cVar1 == '\0') {
    *(undefined2 *)(in_ECX + 8) = 0xffff;
  }
  *unaff_retaddr = *(undefined1 *)(in_ECX + 10);
  *param_1 = *(undefined2 *)(in_ECX + 8);
  return;
}


// ==== FUN_00770690 @ 0x00770690 ====

void FUN_00770690(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xb) = 1;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f507c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007706c0 @ 0x007706c0 ====

undefined4 FUN_007706c0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xb) = 0;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009f5090;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_00770700 @ 0x00770700 ====

void FUN_00770700(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f50a4;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00770730 @ 0x00770730 ====

void FUN_00770730(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0xc) == '\x01') {
    return;
  }
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f50b8;
  }
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 0xc) = 1;
  *(undefined4 *)(in_ECX + 0x10) = param_1;
                    /* WARNING: Could not recover jumptable at 0x00770776. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5acd4 + 4))();
  return;
}


// ==== FUN_00770780 @ 0x00770780 ====

void FUN_00770780(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0xc) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009f50cc;
    }
    FUN_00797a20(puVar1);
    *(undefined1 *)(in_ECX + 0xc) = 0;
    *(undefined2 *)(in_ECX + 0x16) = 0;
    (**(code **)(*DAT_00b5acd4 + 4))(0);
  }
  return;
}


// ==== FUN_007707d0 @ 0x007707d0 ====

void FUN_007707d0(undefined4 param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar3 = operator_new(0x400);
  *(undefined4 *)((int)pvVar3 + 8) = uVar2;
  *(undefined4 *)((int)pvVar3 + 0xc) = 0x50f0000;
  *(undefined2 *)((int)pvVar3 + 6) = 0x14;
  iVar4 = FUN_004244d0();
  uVar1 = (**(code **)(*DAT_00b5ac40 + 8))(param_1);
  *(undefined2 *)(iVar4 + 0x10) = uVar1;
  FUN_004d8570(iVar4);
  return;
}


// ==== FUN_00770830 @ 0x00770830 ====

void FUN_00770830(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5250003;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_00770870 @ 0x00770870 ====

void FUN_00770870(short param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  
  if (*(short *)(in_ECX + 0x16) != param_1) {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5250001;
    *(undefined2 *)((int)pvVar2 + 6) = 0x18;
    iVar3 = FUN_004244d0();
    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
    *(short *)(iVar3 + 0x14) = param_1;
    FUN_004d8570(iVar3);
    *(short *)(in_ECX + 0x16) = param_1;
  }
  return;
}


// ==== FUN_007708e0 @ 0x007708e0 ====

void FUN_007708e0(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *unaff_EDI;
  undefined1 *_Memory;
  undefined1 auStack_6e [6];
  uint *puVar2;
  uint *puVar3;
  undefined1 auStack_46 [2];
  uint local_44;
  void *local_40;
  void *pvStack_3c;
  uint uStack_38;
  uint uStack_34;
  void *local_30;
  uint local_2c;
  uint local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00996100;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  in_ECX[1] = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f50ec;
  in_ECX[1] = &PTR_FUN_009f50e0;
  *(undefined2 *)(in_ECX + 2) = 0xffff;
  *(undefined1 *)((int)in_ECX + 0xb) = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 1;
  *(undefined2 *)((int)in_ECX + 0x16) = 0;
  local_4 = 1;
  if (DAT_00b5ac3c == (int *)0x0) {
    local_2c = 0xf;
    local_30 = (void *)0x0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740();
    local_4._0_1_ = 2;
    FUN_00406880();
    local_4 = CONCAT31(local_4._1_3_,1);
    if (local_2c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_40);
    return;
  }
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac38 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ac38 = in_ECX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740();
  local_4._0_1_ = 3;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401740();
  puVar3 = &local_28;
  local_4 = CONCAT31(local_4._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))();
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
  FUN_00401740();
  local_10._0_1_ = 5;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740();
  puVar2 = &uStack_34;
  local_10 = CONCAT31(local_10._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c._0_1_ = 1;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(&DAT_009f4edf);
  uStack_1c._0_1_ = 7;
  local_44 = 0xf;
  FUN_00401740(s_quest_endlist_009f4ee0);
  _Memory = auStack_6e + 0x12;
  uStack_1c = CONCAT31(uStack_1c._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 8))(_Memory,0);
  if (0xf < unaff_EBP) {
    _free(&local_44);
    return;
  }
  local_28._0_1_ = 1;
  if (0xf < uStack_34) {
    _free((void *)0x0);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  FUN_00401740(&DAT_009f4eee,0);
  local_28._0_1_ = 9;
  FUN_00401740(s_quest_record_009f4ef0,0xc);
  local_28 = CONCAT31(local_28._1_3_,10);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_6e + 6,1,auStack_46 + -6);
  if ((uint *)0xf < puVar3) {
    _free(auStack_46 + -10);
    return;
  }
  uStack_34._0_1_ = 1;
  if (0xf < local_40) {
    _free((void *)0x0);
    return;
  }
  local_40 = (void *)0xf;
  local_44 = 0;
  FUN_00401740(&DAT_009f4efd,0);
  uStack_34._0_1_ = 0xb;
  FUN_00401740(s_quest_delete_009f4f00,0xc);
  uStack_34 = CONCAT31(uStack_34._1_3_,0xc);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_6e + -6,1,auStack_6e + 0x16);
  if ((uint *)0xf < puVar2) {
    _free(_Memory);
    return;
  }
  local_40 = (void *)CONCAT31(local_40._1_3_,1);
  if ((void *)((uint)unaff_EBX & 0xffffff00) < (void *)0x10) {
    (**(code **)(*DAT_00b5ac3c + 0x20))(in_ECX + 1);
    ExceptionList = (void *)((uint)unaff_EBX & 0xffffff00);
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_00770ca0 @ 0x00770ca0 ====

void FUN_00770ca0(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  undefined4 uStack_30;
  undefined4 *local_2c;
  void *local_28;
  void *local_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00996161;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f50ec;
  in_ECX[1] = &PTR_FUN_009f50e0;
  local_4 = 1;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_2c = in_ECX;
  FUN_00401740(s_show_quest_009f4f10,10);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8._0_1_ = 1;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_quest_009f4f1c,10);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  pvStack_c._0_1_ = 1;
  if (0xf < uStack_18) {
    _free(local_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffffff00);
  FUN_00401740(s_quest_endlist_009f4f28,0xd);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&uStack_30);
  local_10._0_1_ = 1;
  if (0xf < uStack_1c) {
    _free(uStack_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  uStack_30 = (void *)((uint)uStack_30 & 0xffffff00);
  FUN_00401740(s_quest_record_009f4f38,0xc);
  local_10 = CONCAT31(local_10._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x34);
  local_14._0_1_ = 1;
  if (0xf < uStack_20) {
    _free(unaff_EBX);
    return;
  }
  uStack_20 = 0xf;
  local_24 = (void *)0x0;
  FUN_00401740(s_quest_delete_009f4f48,0xc);
  local_14 = CONCAT31(local_14._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x38);
  uStack_18 = CONCAT31(uStack_18._1_3_,1);
  if (local_24 < (void *)0x10) {
    DAT_00b5ac38 = 0;
    (**(code **)(*DAT_00b5ac3c + 0x24))(in_ECX + 1);
    in_ECX[1] = &PTR_FUN_009ef7a4;
    *in_ECX = &PTR_FUN_009f5014;
    ExceptionList = local_24;
    return;
  }
  _free(unaff_EBP);
  return;
}


// ==== FUN_00770e90 @ 0x00770e90 ====

void FUN_00770e90(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
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
  puStack_8 = &LAB_0099617b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (*(int **)(iVar2 + 0x60) == (int *)0x0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pQuestManager____NULL_009f4fac,0x15);
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
  piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x60) + 0x18))();
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x14))();
    ExceptionList = pvStack_c;
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pDiary____NULL_009f4fc4,0xe);
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


// ==== FUN_00770fa0 @ 0x00770fa0 ====

void FUN_00770fa0(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
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
  puStack_8 = &LAB_00996195;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (*(int **)(iVar2 + 0x60) == (int *)0x0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pQuestManager____NULL_009f4fd4,0x15);
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
  piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x60) + 0x18))();
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 0x18))();
    ExceptionList = pvStack_c;
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pDiary____NULL_009f4fec,0xe);
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


// ==== FUN_007710b0 @ 0x007710b0 ====

undefined4 FUN_007710b0(void)

{
  char cVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  int *in_ECX;
  undefined1 local_44 [4];
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009961b7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar4 = FUN_00403620();
  if (iVar4 == 0) {
    (**(code **)(*in_ECX + 0x24))();
    ExceptionList = local_c;
    return 1;
  }
  iVar4 = FUN_00403620();
  if (iVar4 == 0) {
    (**(code **)(*in_ECX + 0x2c))();
    ExceptionList = local_c;
    return 1;
  }
  iVar4 = FUN_00403620();
  if (iVar4 == 0) {
    sVar2 = (**(code **)(*in_ECX + 0x30))();
    while( true ) {
      if (sVar2 == 0) {
        ExceptionList = local_c;
        return 1;
      }
      FUN_00401740(s_EndQuest__u_009f4f80,0xb);
      uVar5 = FUN_00404230(local_44);
      local_4 = 0;
      FUN_00796d20(uVar5);
      local_4 = 0xffffffff;
      if (0xf < uStack_2c) break;
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      sVar2 = (**(code **)(*in_ECX + 0x34))();
    }
    _free(pvStack_40);
    return extraout_EAX;
  }
  cVar1 = FUN_004036a0();
  if (cVar1 != '\0') {
    iVar4 = FUN_007712f0();
    FUN_00459160();
    local_4 = 1;
    uVar3 = thunk_FUN_00796f80();
    *(undefined2 *)(iVar4 + 0x10) = uVar3;
    local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar1 = FUN_004036a0();
  if (cVar1 != '\0') {
    iVar4 = FUN_00771320();
    FUN_00459160();
    local_4 = 2;
    uVar3 = thunk_FUN_00796f80();
    *(undefined2 *)(iVar4 + 0x10) = uVar3;
    local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_007712f0 @ 0x007712f0 ====

void FUN_007712f0(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x8000007;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  FUN_004244d0();
  return;
}


// ==== FUN_00771320 @ 0x00771320 ====

void FUN_00771320(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x8000008;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  FUN_004244d0();
  return;
}


// ==== FUN_00771350 @ 0x00771350 ====

undefined4 FUN_00771350(void)

{
  return 0x70000000;
}


// ==== FUN_00771360 @ 0x00771360 ====

undefined4 FUN_00771360(void)

{
  return 0x70000001;
}


// ==== FUN_00771370 @ 0x00771370 ====

undefined4 FUN_00771370(void)

{
  return 0x70000002;
}


// ==== FUN_00771380 @ 0x00771380 ====

undefined4 FUN_00771380(void)

{
  return 0x70000003;
}


// ==== FUN_00771390 @ 0x00771390 ====

undefined4 FUN_00771390(void)

{
  return 0x70000004;
}


// ==== FUN_007713a0 @ 0x007713a0 ====

void FUN_007713a0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x14) = param_1;
  return;
}


// ==== FUN_007713b0 @ 0x007713b0 ====

void FUN_007713b0(void)

{
  FUN_007713c0();
  return;
}


// ==== FUN_007713c0 @ 0x007713c0 ====

void FUN_007713c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00770ca0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007713e0 @ 0x007713e0 ====

void FUN_007713e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f519c;
  return;
}


// ==== FUN_007713f0 @ 0x007713f0 ====

void FUN_007713f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f519c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00771410 @ 0x00771410 ====

int FUN_00771410(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 2;
}


// ==== FUN_00771430 @ 0x00771430 ====

undefined4 FUN_00771430(undefined4 param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  char cVar3;
  short sVar4;
  int in_ECX;
  undefined4 *puVar5;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  puVar5 = *(undefined4 **)(in_ECX + 8);
  while( true ) {
    if (puVar5 == puVar1) {
      return 0;
    }
    piVar2 = (int *)*puVar5;
    sVar4 = (**(code **)(*piVar2 + 0x10))();
    if ((sVar4 == (short)param_1) ||
       (cVar3 = (**(code **)(*piVar2 + 0x20))(param_1), cVar3 == '\x01')) break;
    puVar5 = puVar5 + 1;
  }
  return 1;
}


// ==== FUN_00771480 @ 0x00771480 ====

int * FUN_00771480(short param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  short sVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  puVar4 = *(undefined4 **)(in_ECX + 8);
  while( true ) {
    if (puVar4 == puVar1) {
      return (int *)0x0;
    }
    piVar2 = (int *)*puVar4;
    sVar3 = (**(code **)(*piVar2 + 0x10))();
    if (sVar3 == param_1) break;
    puVar4 = puVar4 + 1;
  }
  return piVar2;
}


// ==== FUN_007714c0 @ 0x007714c0 ====

void FUN_007714c0(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar1 = *(int **)(in_ECX + 0xc);
  for (piVar2 = *(int **)(in_ECX + 8); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
  }
  if (*(void **)(in_ECX + 8) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_00771510 @ 0x00771510 ====

void FUN_00771510(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  int *in_ECX;
  int *unaff_EBX;
  undefined2 *puVar8;
  undefined2 uStack_66;
  char cStack_62;
  int *local_60;
  undefined4 uStack_54;
  undefined4 uStack_4c;
  undefined2 *puStack_3c;
  undefined2 *puStack_38;
  undefined2 *puStack_34;
  undefined4 uStack_30;
  undefined4 uStack_28;
  undefined4 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009961eb;
  pvStack_c = ExceptionList;
  uStack_66 = (undefined2)((uint)unaff_EBX >> 0x10);
  ExceptionList = &pvStack_c;
  FUN_007714c0();
  iVar3 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x60) + 0x14))();
  cStack_62 = (char)((uint)piVar4 >> 0x10);
  piVar5 = (int *)(**(code **)(*piVar4 + 0x14))();
  while( true ) {
    while( true ) {
      if (piVar5 == (int *)0x0) {
        ExceptionList = pvStack_c;
        return;
      }
      piVar5 = (int *)(**(code **)(*piVar5 + 0xc))();
      puVar6 = (undefined4 *)(**(code **)(*piVar5 + 4))();
      uVar1 = *puVar6;
      uVar2 = puVar6[1];
      uVar7 = (**(code **)(*DAT_00b5ac40 + 4))(uVar1);
      if ((short)uVar7 != 0) break;
      piVar5 = (int *)(**(code **)(*unaff_EBX + 0x18))();
    }
    local_60 = operator_new(0x18);
    puStack_8 = (undefined1 *)0x0;
    if (local_60 == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_006ef930(uVar7);
    }
    puStack_8 = (undefined1 *)0xffffffff;
    (**(code **)(*in_ECX + 0x10))(piVar5);
    (**(code **)(*DAT_00b5ac40 + 0xc))(&puStack_34,uVar1);
    uStack_14 = 1;
    puVar8 = puStack_38;
    if (puStack_38 != puStack_34) {
      do {
        local_60 = (int *)CONCAT22(local_60._2_2_,*puVar8);
        (**(code **)(*piVar5 + 4))(local_60,3,0);
        puVar8 = puVar8 + 1;
      } while (puVar8 != puStack_34);
    }
    uStack_14 = 0xffffffff;
    if (puStack_38 != (undefined2 *)0x0) break;
    uStack_4c = (int *)CONCAT13((char)((uint)piVar4 >> 8),CONCAT12((char)piVar4,uStack_66));
    uStack_54 = CONCAT22((short)((uint)uVar2 >> 0x10),(short)uVar1);
    puStack_38 = (undefined2 *)0x0;
    puStack_34 = (undefined2 *)0x0;
    uStack_30 = 0;
    (**(code **)(*piVar5 + 4))(uStack_54,-(cStack_62 != '\0') & 2);
    (**(code **)(*DAT_00b5ac40 + 0x10))(&puStack_38,uVar1);
    uStack_28 = 2;
    puVar8 = puStack_3c;
    if (puStack_3c != puStack_38) {
      do {
        (**(code **)(*piVar5 + 4))(*puVar8,1,0);
        puVar8 = puVar8 + 1;
      } while (puVar8 != puStack_38);
    }
    uStack_28 = 0xffffffff;
    if (puStack_3c != (undefined2 *)0x0) {
      _free(puStack_3c);
      return;
    }
    puStack_3c = (undefined2 *)0x0;
    puStack_38 = (undefined2 *)0x0;
    puStack_34 = (undefined2 *)0x0;
    piVar5 = (int *)(**(code **)(*uStack_4c + 0x18))();
    in_ECX = local_60;
  }
  _free(puStack_38);
  return;
}


// ==== FUN_00771750 @ 0x00771750 ====

void FUN_00771750(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  FUN_00771510();
  puVar2 = *(undefined4 **)(in_ECX + 0x18);
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


// ==== FUN_007717c0 @ 0x007717c0 ====

undefined4 FUN_007717c0(uint param_1)

{
  code *pcVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  int in_ECX;
  int extraout_ECX;
  int iVar3;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009961fd;
  local_c = ExceptionList;
  if ((*(int *)(in_ECX + 8) == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 2) <= param_1)) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(s_i_index_<_vecQuestList_size()_009f5158,0x1d);
    local_4 = 0;
    FUN_00406880(local_28);
    local_4 = 0xffffffff;
    if (local_10 < 0x10) {
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    _free(local_24);
    return extraout_EAX;
  }
  iVar3 = *(int *)(in_ECX + 8);
  if ((iVar3 == 0) || ((uint)(*(int *)(in_ECX + 0xc) - iVar3 >> 2) <= param_1)) {
    ExceptionList = &local_c;
    FUN_00771b20();
    iVar3 = extraout_ECX;
  }
  ExceptionList = local_c;
  return *(undefined4 *)(iVar3 + param_1 * 4);
}


// ==== FUN_00771890 @ 0x00771890 ====

undefined4 FUN_00771890(uint param_1)

{
  code *pcVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  int in_ECX;
  int extraout_ECX;
  int iVar3;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099620f;
  local_c = ExceptionList;
  if ((*(int *)(in_ECX + 8) == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 2) <= param_1)) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    ExceptionList = &local_c;
    FUN_00401740(s_i_index_<_vecQuestList_size()_009f5178,0x1d);
    local_4 = 0;
    FUN_00406880(local_28);
    local_4 = 0xffffffff;
    if (local_10 < 0x10) {
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    _free(local_24);
    return extraout_EAX;
  }
  iVar3 = *(int *)(in_ECX + 8);
  if ((iVar3 == 0) || ((uint)(*(int *)(in_ECX + 0xc) - iVar3 >> 2) <= param_1)) {
    ExceptionList = &local_c;
    FUN_00771b20();
    iVar3 = extraout_ECX;
  }
  ExceptionList = local_c;
  return *(undefined4 *)(iVar3 + param_1 * 4);
}


// ==== FUN_00771960 @ 0x00771960 ====

void FUN_00771960(undefined1 param_1)

{
  undefined1 local_8 [8];
  
  FUN_00752030(local_8,&param_1);
  return;
}


// ==== FUN_00771980 @ 0x00771980 ====

void FUN_00771980(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00996237;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f51c8;
  local_4 = 2;
  DAT_00b5ac3c = 0;
  FUN_007714c0();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_007520f0(local_10,*(undefined4 *)in_ECX[6],(undefined4 *)in_ECX[6]);
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00771a20 @ 0x00771a20 ====

void FUN_00771a20(undefined1 param_1)

{
  FUN_00752400(&param_1);
  return;
}


// ==== FUN_00771a30 @ 0x00771a30 ====

void FUN_00771a30(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00996254;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f51c8;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  local_4 = 1;
  iVar1 = FUN_00751a80();
  in_ECX[6] = iVar1;
  *(undefined1 *)(iVar1 + 0x11) = 1;
  *(undefined4 *)(in_ECX[6] + 4) = in_ECX[6];
  *(undefined4 *)in_ECX[6] = in_ECX[6];
  *(undefined4 *)(in_ECX[6] + 8) = in_ECX[6];
  in_ECX[7] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac3c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ac3c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00771ad0 @ 0x00771ad0 ====

void FUN_00771ad0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x10) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2)))
  {
    FUN_00771c00(*(undefined4 *)(in_ECX + 0xc),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0xc);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0xc) = puVar2 + 1;
  return;
}


// ==== FUN_00771b20 @ 0x00771b20 ====

void FUN_00771b20(void)

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
  puStack_8 = &LAB_00996268;
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


// ==== FUN_00771b90 @ 0x00771b90 ====

void FUN_00771b90(void)

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
  puStack_8 = &LAB_00996268;
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


// ==== FUN_00771c00 @ 0x00771c00 ====

void FUN_00771c00(void *param_1,uint param_2,undefined4 *param_3)

{
  size_t _Size;
  int iVar1;
  uint uVar2;
  void *_Dst;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  
  iVar5 = *(int *)(in_ECX + 4);
  param_3 = (undefined4 *)*param_3;
  if (iVar5 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar5 >> 2;
  }
  uVar7 = CONCAT44(iVar5,iVar1);
  if (param_2 != 0) {
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 2;
    }
    if (0x3fffffffU - iVar5 < param_2) {
      uVar7 = FUN_00771b90();
    }
    iVar5 = (int)((ulonglong)uVar7 >> 0x20);
    uVar2 = (uint)uVar7;
    if (iVar5 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 2;
    }
    if (uVar2 < iVar1 + param_2) {
      if (0x3fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar5 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 2;
      }
      if (uVar2 < iVar1 + param_2) {
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 2;
        }
        uVar2 = iVar5 + param_2;
      }
      _Dst = operator_new(uVar2 * 4);
      _Size = ((int)param_1 - (int)*(void **)(in_ECX + 4) >> 2) * 4;
      pvVar3 = _memmove(_Dst,*(void **)(in_ECX + 4),_Size);
      pvVar3 = (void *)FUN_00845740((void *)((int)pvVar3 + _Size),param_2,&param_3);
      _memmove(pvVar3,param_1,(*(int *)(in_ECX + 8) - (int)param_1 >> 2) * 4);
      pvVar3 = *(void **)(in_ECX + 4);
      if (pvVar3 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - (int)pvVar3 >> 2;
      }
      if (pvVar3 == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)_Dst);
        *(void **)(in_ECX + 8) = (void *)((int)_Dst + (param_2 + iVar5) * 4);
        *(void **)(in_ECX + 4) = _Dst;
        return;
      }
      _free(pvVar3);
      return;
    }
    iVar1 = *(int *)(in_ECX + 8);
    iVar5 = param_2 * 4;
    if ((uint)(iVar1 - (int)param_1 >> 2) < param_2) {
      FUN_005a6d90(param_1,iVar1,(void *)(iVar5 + (int)param_1));
      FUN_00845740(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - (int)param_1 >> 2),
                   &param_3);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar5;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + param_2 * -4,&param_3);
      return;
    }
    iVar6 = iVar1 + param_2 * -4;
    uVar4 = FUN_005a6d90(iVar6,iVar1,iVar1);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00822d20(param_1,iVar6,iVar1);
    FUN_008335f0(param_1,(void *)(iVar5 + (int)param_1),&param_3);
  }
  return;
}


// ==== FUN_00771de0 @ 0x00771de0 ====

void FUN_00771de0(byte param_1)

{
  void *in_ECX;
  
  FUN_00771980();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00771e00 @ 0x00771e00 ====

void FUN_00771e00(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099628b;
  local_c = ExceptionList;
  if (DAT_00b5b194 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(4);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_006ec4a0(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00771e50 @ 0x00771e50 ====

void FUN_00771e50(void)

{
  if (DAT_00b5b194 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b194)(1);
  }
  return;
}


// ==== FUN_00771e70 @ 0x00771e70 ====

void FUN_00771e70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5290;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00771e90 @ 0x00771e90 ====

void FUN_00771e90(undefined1 *param_1)

{
  undefined1 *puVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = 0;
  if (*(char *)(in_ECX + 0x11) == '\0') {
    param_1[*(byte *)(in_ECX + 0x11)] = 0;
    return;
  }
  puVar1 = param_1;
  do {
    *puVar1 = puVar1[(in_ECX + 0x14) - (int)param_1];
    uVar2 = uVar2 + 1;
    puVar1 = puVar1 + 1;
  } while (uVar2 < *(byte *)(in_ECX + 0x11));
  param_1[*(byte *)(in_ECX + 0x11)] = 0;
  return;
}


// ==== FUN_00771ee0 @ 0x00771ee0 ====

undefined4 FUN_00771ee0(void)

{
  return 0x70010006;
}


// ==== FUN_00771ef0 @ 0x00771ef0 ====

void FUN_00771ef0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f52b0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a7b0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a7b0 = in_ECX;
  return;
}


// ==== FUN_00771f20 @ 0x00771f20 ====

undefined4 FUN_00771f20(int param_1)

{
  (**(code **)(*DAT_00b5a7b8 + 0x18))(*(undefined1 *)(param_1 + 0x10));
  (**(code **)(*DAT_00b5a7b8 + 0x70))();
  return 1;
}


// ==== FUN_00771f50 @ 0x00771f50 ====

undefined4 FUN_00771f50(int param_1)

{
  (**(code **)(*DAT_00b5a7b8 + 0x50))
            (*(undefined4 *)(param_1 + 0x10),(float)*(byte *)(param_1 + 0x14) * DAT_009a09b8);
  (**(code **)(*DAT_00b5a7b8 + 0x70))();
  return 1;
}


// ==== FUN_00771f90 @ 0x00771f90 ====

undefined4 FUN_00771f90(int param_1)

{
  (**(code **)(*DAT_00b5a7b8 + 0x54))
            (*(undefined4 *)(param_1 + 0x10),*(undefined2 *)(param_1 + 0x14));
  (**(code **)(*DAT_00b5a7b8 + 0x70))();
  return 1;
}


// ==== FUN_00771fc0 @ 0x00771fc0 ====

undefined4 FUN_00771fc0(int param_1)

{
  (**(code **)(*DAT_00b5a7b8 + 0x58))
            (*(undefined4 *)(param_1 + 0x10),*(undefined2 *)(param_1 + 0x14));
  (**(code **)(*DAT_00b5a7b8 + 0x70))();
  return 1;
}


// ==== FUN_00771ff0 @ 0x00771ff0 ====

undefined4 FUN_00771ff0(int param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_004f5730(&local_c);
  (**(code **)(*DAT_00b5a7b8 + 0x5c))(*(undefined4 *)(param_1 + 0x10),local_c,local_8);
  (**(code **)(*DAT_00b5a7b8 + 0x70))();
  return 1;
}


// ==== FUN_00772050 @ 0x00772050 ====

undefined4 FUN_00772050(int param_1)

{
  (**(code **)(*DAT_00b5a7b8 + 0x60))(*(undefined4 *)(param_1 + 0x10),param_1 + 0x14);
  (**(code **)(*DAT_00b5a7b8 + 0x70))();
  return 1;
}


// ==== FUN_00772160 @ 0x00772160 ====

undefined1 FUN_00772160(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined1 uVar5;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a7b8 + 100))();
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  if (iVar3 == 0) {
    (**(code **)(*DAT_00b5a7b8 + 0x68))(piVar2);
    return 0;
  }
  uVar5 = 0;
  piVar4 = (int *)(**(code **)(*piVar2 + 4))();
  iVar3 = *piVar4;
  while (iVar3 != param_1) {
    cVar1 = (**(code **)(*piVar2 + 8))();
    if (cVar1 == '\0') goto LAB_007721bf;
    (**(code **)(*piVar2 + 0xc))();
    piVar4 = (int *)(**(code **)(*piVar2 + 4))();
    iVar3 = *piVar4;
  }
  uVar5 = 1;
LAB_007721bf:
  (**(code **)(*DAT_00b5a7b8 + 0x68))(piVar2);
  return uVar5;
}


// ==== FUN_007721e0 @ 0x007721e0 ====

void FUN_007721e0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a7b0 = 0;
  *in_ECX = &PTR_FUN_009f5290;
  return;
}


// ==== FUN_00772200 @ 0x00772200 ====

undefined4 FUN_00772200(int param_1)

{
  int iVar1;
  undefined4 extraout_EAX;
  undefined1 auStack_50 [4];
  undefined1 uStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  void *pvStack_24;
  void *pvStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009962a8;
  local_c = ExceptionList;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &local_c;
    iVar1 = (**(code **)(*DAT_00b5a7b8 + 0x28))();
    if (iVar1 != 0) {
      (**(code **)(*DAT_00b5a7b4 + 0x38))();
      uStack_34 = 0x772250;
      (**(code **)(*DAT_00b5ada8 + 0x60))();
      uStack_34 = 0x77225b;
      FUN_00774fc0();
      uStack_34 = 0x772266;
      (**(code **)(*DAT_00b5a7b8 + 0x70))();
      ExceptionList = pvStack_10;
      return 1;
    }
  }
  else if (*(char *)(param_1 + 0x10) == '\x04') {
    uStack_34 = 0;
    uStack_38 = 0x77228f;
    ExceptionList = &local_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x7722ac;
    FUN_00401660();
    puStack_4 = auStack_50;
    uStack_38 = 0xf;
    uStack_3c = 0;
    local_c = (void *)0x0;
    uStack_4c = 0;
    FUN_00401660(auStack_50 + 0x20,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(4);
    if ((void *)0xf < pvStack_10) {
      uStack_34 = 0x7722f1;
      _free(pvStack_24);
      return extraout_EAX;
    }
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00772310 @ 0x00772310 ====

undefined4 FUN_00772310(int param_1)

{
  undefined4 extraout_EAX;
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
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009962ba;
  pvStack_c = ExceptionList;
  uStack_30 = 0x460029;
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    uStack_30 = 0x46002d;
    break;
  case 1:
    uStack_30 = 0x46002c;
    break;
  case 2:
    uStack_30 = 0x46002b;
    break;
  case 3:
    uStack_30 = 0x460008;
    break;
  case 4:
    uStack_30 = 0x46002a;
    break;
  case 5:
    uStack_30 = 0x460029;
  }
  pvStack_34 = (void *)0x0;
  uStack_38 = 0x772379;
  ExceptionList = &pvStack_c;
  uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_38 = 0xffffffff;
  uStack_3c = 0;
  uStack_44 = 0x772396;
  FUN_00401660();
  puStack_4 = auStack_50;
  uStack_38 = 0xf;
  uStack_3c = 0;
  pvStack_c = (void *)0x0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  FUN_00401660(&uStack_30,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (uStack_38 < 0x10) {
    ExceptionList = pvStack_34;
    return 1;
  }
  _free(pvStack_4c);
  return extraout_EAX;
}


// ==== FUN_00772410 @ 0x00772410 ====

undefined4 FUN_00772410(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  char *pcVar4;
  int iVar5;
  undefined4 extraout_EAX;
  char *pcVar6;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009962cc;
  local_c = ExceptionList;
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (*(ushort *)(param_1 + 6) < 0x1d) {
      pcVar6 = (char *)0x0;
    }
    else {
      pcVar6 = (char *)(param_1 + 0x1c);
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    pcVar4 = pcVar6;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    ExceptionList = &local_c;
    FUN_00401740(pcVar6,(int)pcVar4 - (int)(pcVar6 + 1));
    uVar2 = *(undefined1 *)(param_1 + 0x18);
    uVar3 = *(undefined4 *)(param_1 + 0x14);
    local_4 = 0;
    iVar5 = (**(code **)(*DAT_00b5a7b8 + 0x28))();
    if (iVar5 == 0) {
      FUN_00774f70(uVar3,uVar3,5,uVar2,local_28);
      (**(code **)(*DAT_00b5a7b8 + 0x70))();
    }
    local_4 = 0xffffffff;
    if (0xf < local_10) {
      _free(local_24);
      return extraout_EAX;
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    (**(code **)(*DAT_00b5a7b4 + 0x34))();
    (**(code **)(*DAT_00b5ada8 + 0x60))(0);
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00772510 @ 0x00772510 ====

undefined4 FUN_00772510(int param_1)

{
  char cVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  undefined4 extraout_EAX;
  char *pcVar8;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009962de;
  pvStack_c = ExceptionList;
  if (*(ushort *)(param_1 + 6) < 0x21) {
    pcVar8 = (char *)0x0;
  }
  else {
    pcVar8 = (char *)(param_1 + 0x20);
  }
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  pcVar6 = pcVar8;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &pvStack_c;
  FUN_00401740(pcVar8,(int)pcVar6 - (int)(pcVar8 + 1));
  uVar2 = *(undefined1 *)(param_1 + 0x1c);
  uVar3 = *(undefined1 *)(param_1 + 0x10);
  uVar4 = *(undefined4 *)(param_1 + 0x14);
  uVar5 = *(undefined4 *)(param_1 + 0x18);
  local_4 = 0;
  iVar7 = (**(code **)(*DAT_00b5a7b8 + 0x28))();
  if (iVar7 == 0) {
    FUN_00774f70(uVar5,uVar4,uVar3,uVar2,local_28);
    (**(code **)(*DAT_00b5a7b8 + 0x70))();
  }
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = (void *)0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    (**(code **)(*DAT_00b5a7b4 + 0x2c))();
    (**(code **)(*DAT_00b5a7b4 + 0x34))();
    (**(code **)(*DAT_00b5ada8 + 0x60))(0);
    ExceptionList = local_10;
    return 1;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00772620 @ 0x00772620 ====

/* WARNING: Removing unreachable block (ram,0x007726ca) */

undefined4 FUN_00772620(void)

{
  char cVar1;
  undefined4 extraout_EAX;
  char *pcVar2;
  void *unaff_EDI;
  undefined1 auStack_78 [16];
  undefined4 uStack_68;
  undefined4 uStack_64;
  uint uStack_3c;
  undefined4 auStack_34 [2];
  undefined1 uStack_2c;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &LAB_009962f8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_18 = 0xf;
  uStack_1c = 0;
  uStack_2c = 0;
  uStack_68 = 0x77266b;
  FUN_00401660();
  pcVar2 = (char *)(iStack_4 + 0x10);
  pvStack_c = (void *)0x0;
  auStack_34[0] = 0xf;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uStack_64 = 0x7726a6;
  FUN_00401740();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  (**(code **)(*DAT_00b5a7b8 + 8))();
  uStack_10 = 0;
  (**(code **)(*DAT_00b5a7b8 + 0x70))();
  puStack_8 = auStack_78;
  FUN_00401660(auStack_34,0,0xffffffff);
  FUN_00404230(puStack_8);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  if (uStack_3c < 0x10) {
    ExceptionList = (void *)0x0;
    return 1;
  }
  _free(unaff_EDI);
  return extraout_EAX;
}


// ==== FUN_00772760 @ 0x00772760 ====

undefined4 FUN_00772760(int param_1)

{
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  uint unaff_ESI;
  undefined1 auStack_a4 [4];
  undefined1 uStack_a0;
  undefined4 uStack_98;
  undefined1 *puStack_94;
  undefined4 uStack_90;
  undefined4 *puStack_8c;
  undefined4 uStack_88;
  undefined1 *puStack_84;
  undefined4 uStack_80;
  undefined1 auStack_60 [8];
  undefined4 uStack_58;
  uint uStack_54;
  undefined1 auStack_50 [4];
  void *pvStack_4c;
  undefined4 uStack_3c;
  uint uStack_38;
  void *pvStack_30;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined1 *puStack_18;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099631a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5a7b8 + 0x14))();
  (**(code **)(*DAT_00b5a7b8 + 0x70))();
  puStack_84 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_80 = (char *)0x0;
  uStack_38 = 0xf;
  uStack_3c = 0;
  pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
  uStack_88 = 0x7727ca;
  FUN_00401660();
  uStack_80 = (char *)0x0;
  puStack_84 = auStack_50;
  uStack_10 = 0;
  uStack_54 = 0xf;
  uStack_58 = 0;
  uStack_88 = 0x7727eb;
  FUN_00401660();
  uStack_10._0_1_ = 1;
  switch(*(undefined1 *)(param_1 + 0x10)) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    uStack_80 = s___________CN_GETITEMWAY_Packet__R_009f5244;
    uStack_1c = 0xf;
    uStack_20 = 0;
    pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
    puStack_84 = (undefined1 *)0x7728f7;
    FUN_00401740();
    uStack_10._0_1_ = 2;
    uStack_80 = (char *)0x772906;
    FUN_00796d50();
    if (0xf < uStack_1c) {
      uStack_80 = (char *)0x77291e;
      _free(pvStack_30);
      return extraout_EAX_00;
    }
    uStack_1c = 0xf;
    uStack_20 = 0;
    pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
    if (0xf < uStack_54) {
      uStack_80 = (char *)0x77293d;
      _free((void *)(unaff_ESI & 0xffffff00));
      return extraout_EAX_01;
    }
    goto joined_r0x00772950;
  }
  uStack_80 = (char *)0x0;
  puStack_84 = (undefined1 *)0x77282a;
  puStack_8c = (undefined4 *)(**(code **)(*DAT_00b5a794 + 0xc))();
  puStack_84 = (undefined1 *)0xffffffff;
  uStack_88 = 0;
  uStack_90 = 0x772837;
  FUN_00401660();
  puStack_84 = (undefined1 *)0xffffffff;
  puStack_8c = &uStack_58;
  uStack_88 = 0;
  uStack_90 = 0x772848;
  FUN_00401ff0();
  puStack_84 = (undefined1 *)0x460014;
  uStack_88 = 0;
  puStack_8c = (undefined4 *)0x772859;
  puStack_94 = (undefined1 *)(**(code **)(*DAT_00b5a794 + 0xc))();
  puStack_8c = (undefined4 *)0xffffffff;
  uStack_90 = 0;
  uStack_98 = 0x772866;
  FUN_00401660();
  puStack_8c = (undefined4 *)0xffffffff;
  uStack_90 = 0;
  puStack_94 = auStack_60;
  uStack_98 = 0x772877;
  FUN_00401ff0();
  puStack_18 = auStack_a4;
  puStack_8c = (undefined4 *)0xf;
  uStack_90 = 0;
  uStack_a0 = 0;
  FUN_00401660(auStack_60 + -0x1c,0,0xffffffff);
  (**(code **)(*DAT_00b5ad0c + 0x28))(4);
  if (0xf < uStack_54) {
    uStack_80 = (char *)0x7728bb;
    _free((void *)(unaff_ESI & 0xffffff00));
    return extraout_EAX;
  }
joined_r0x00772950:
  if (uStack_38 < 0x10) {
    ExceptionList = puStack_18;
    return 1;
  }
  uStack_54 = 0xf;
  uStack_58 = 0;
  uStack_80 = (char *)0x77295c;
  _free(pvStack_4c);
  return extraout_EAX_02;
}


// ==== FUN_00772990 @ 0x00772990 ====

/* WARNING: Removing unreachable block (ram,0x00772a85) */

undefined4 FUN_00772990(int param_1)

{
  undefined1 auStack_4c [12];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  puStack_8 = &LAB_0099632c;
  local_c = ExceptionList;
  local_4 = (undefined1 *)0x0;
  switch(*(byte *)(param_1 + 0x10) - 1) {
  case 0:
    break;
  case 1:
    goto LAB_00772a43;
  case 2:
    break;
  case 3:
    goto LAB_00772a43;
  default:
    goto switchD_007729d9_caseD_4;
  case 6:
    break;
  case 7:
LAB_00772a43:
    uStack_30 = 0;
    uStack_34 = 0x772a50;
    ExceptionList = &local_c;
    uStack_3c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_34 = 0xffffffff;
    uStack_38 = 0;
    uStack_40 = 0x772a5e;
    FUN_00401660();
    local_4 = auStack_4c;
    FUN_00765c50(&uStack_30);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    goto switchD_007729d9_caseD_4;
  }
  uStack_30 = 0;
  uStack_34 = 0x772a0e;
  ExceptionList = &local_c;
  uStack_3c = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_34 = 0xffffffff;
  uStack_38 = 0;
  uStack_40 = 0x772a1c;
  FUN_00401660();
  local_4 = auStack_4c;
  FUN_00765c50(&uStack_30);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
switchD_007729d9_caseD_4:
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00772ad0 @ 0x00772ad0 ====

undefined4 FUN_00772ad0(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined1 auStack_90 [12];
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  char *pcStack_74;
  char local_60 [20];
  undefined1 auStack_4c [12];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *pvStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00996356;
  pvStack_c = ExceptionList;
  local_60[0] = '\0';
  pcStack_74 = (char *)0x772b01;
  ExceptionList = &pvStack_c;
  FUN_00771e90();
  pcVar2 = local_60;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  pcStack_74 = local_60;
  uStack_78 = 0x772b3a;
  FUN_00401740();
  cVar1 = *(char *)(param_1 + 0x10);
  local_4 = (undefined1 *)0x0;
  if (cVar1 == '\0') {
    pcStack_74 = (char *)0x0;
    uStack_78 = 0x772bcc;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_78 = 0xffffffff;
    uStack_7c = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    local_2c = local_2c & 0xffffff00;
    uStack_84 = 0x772be5;
    FUN_00401660();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  }
  else if (cVar1 == '\x01') {
    pcStack_74 = (char *)0x0;
    uStack_78 = 0x772b9b;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_78 = 0xffffffff;
    uStack_7c = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    local_2c = local_2c & 0xffffff00;
    uStack_84 = 0x772bb4;
    FUN_00401660();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
  }
  else {
    if (cVar1 != '\x02') goto LAB_00772c29;
    pcStack_74 = (char *)0x0;
    uStack_78 = 0x772b6a;
    uStack_80 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_78 = 0xffffffff;
    uStack_7c = 0;
    uStack_18 = 0xf;
    uStack_1c = 0;
    local_2c = local_2c & 0xffffff00;
    uStack_84 = 0x772b83;
    FUN_00401660();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  }
  local_4 = auStack_90;
  FUN_00405bd0(auStack_90,auStack_4c,&local_30);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (0xf < uStack_10) {
    pcStack_74 = (char *)0x772c26;
    _free(pvStack_24);
    return extraout_EAX;
  }
LAB_00772c29:
  if (local_2c < 0x10) {
    ExceptionList = pvStack_c;
    return 1;
  }
  pcStack_74 = (char *)0x772c39;
  _free(local_40);
  return extraout_EAX_00;
}


// ==== FUN_00772c60 @ 0x00772c60 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

void FUN_00772c60(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined1 auStack_10dc [12];
  undefined4 uStack_10d0;
  undefined4 uStack_10cc;
  undefined1 *puStack_10c8;
  char *pcStack_10c4;
  int iStack_10c0;
  undefined1 auStack_10aa [22];
  void *pvStack_1094;
  uint uStack_1080;
  void *pvStack_1078;
  undefined1 auStack_1048 [4];
  undefined1 uStack_1044;
  void *pvStack_1040;
  undefined4 uStack_1034;
  undefined4 uStack_1030;
  uint uStack_102c;
  void *pvStack_1024;
  undefined4 uStack_101c;
  undefined4 uStack_1018;
  undefined1 *puStack_1014;
  uint uStack_1010;
  undefined4 uStack_100c;
  undefined4 uStack_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00996381;
  pvStack_14 = ExceptionList;
  uStack_1c = 0x772c86;
  ExceptionList = &pvStack_14;
  iVar2 = (**(code **)(*DAT_00b5a7b8 + 0x28))();
  if (iVar2 != 0) {
    iStack_10c0 = 0x772cab;
    piVar3 = (int *)(**(code **)(*DAT_00b5ab14 + 8))();
    uStack_1030 = 0xf;
    uStack_1034 = 0;
    uStack_1044 = 0;
    puStack_10 = (undefined1 *)0x0;
    if (piVar3 == (int *)0x0) {
      iStack_10c0 = 0xb;
      pcStack_10c4 = s_Invalid_Map_009f527c;
      puStack_10c8 = (undefined1 *)0x772cdf;
      FUN_00401740();
    }
    else {
      iStack_10c0 = 0x772ce8;
      puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x10))();
      pcVar5 = (char *)((int)&uStack_100c + 2);
      puVar6 = &uStack_100c;
      for (iVar2 = 0x3fb; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar6 = puVar6 + 1;
      }
      do {
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar1 != '\0');
      iStack_10c0 = (int)pcVar5 - ((int)&uStack_100c + 3);
      pcStack_10c4 = (char *)((int)&uStack_100c + 2);
      puStack_10c8 = (undefined1 *)0x772d1f;
      FUN_00401740();
    }
    iStack_10c0 = 0xffffffff;
    pcStack_10c4 = (char *)0x0;
    puStack_10c8 = auStack_1048;
    puStack_10 = (undefined1 *)CONCAT31(puStack_10._1_3_,1);
    uStack_10cc = 0x772d7b;
    FUN_00401660();
    iStack_10c0 = 0xffffffff;
    pcStack_10c4 = (char *)0x0;
    puStack_10c8 = (undefined1 *)param_3;
    uStack_10cc = 0x772d8b;
    FUN_00401660();
    iStack_10c0 = param_3;
    pcStack_10c4 = (char *)0x772d97;
    (**(code **)(*DAT_00b5acd8 + 0x10))();
    pcStack_10c4 = auStack_10aa + -6;
    puStack_10c8 = (undefined1 *)0x772dd9;
    (**(code **)(*DAT_00b5a7b8 + 0x1c))();
    puStack_10c8 = (undefined1 *)0x772de4;
    (**(code **)(*DAT_00b5a7b8 + 0x70))();
    puStack_10c8 = (undefined1 *)0x772def;
    iVar2 = (**(code **)(*DAT_00b5a7b8 + 0x6c))();
    if (param_1 != iVar2) {
      iStack_10c0 = 0;
      pcStack_10c4 = (char *)0x772e09;
      uStack_10cc = (**(code **)(*DAT_00b5a794 + 0xc))();
      pcStack_10c4 = (undefined1 *)0xffffffff;
      puStack_10c8 = (undefined1 *)0x0;
      uStack_1018 = 0xf;
      uStack_101c = 0;
      uStack_102c = uStack_102c & 0xffffff00;
      uStack_10d0 = 0x772e2e;
      FUN_00401660();
      puStack_1014 = auStack_10dc;
      pvStack_14 = (void *)CONCAT31(pvStack_14._1_3_,2);
      FUN_00405bd0(auStack_10dc,param_3,&uStack_1030);
      (**(code **)(*DAT_00b5ad0c + 0x28))(4);
      if (0xf < uStack_1010) {
        iStack_10c0 = 0x772e7c;
        _free(pvStack_1024);
        return;
      }
    }
    if (0xf < param_5) {
      iStack_10c0 = 0x772e96;
      _free(pvStack_1078);
      return;
    }
    if (0xf < uStack_1080) {
      iStack_10c0 = 0x772eb5;
      _free(pvStack_1094);
      return;
    }
    if (0xf < uStack_102c) {
      iStack_10c0 = 0x772ed7;
      _free(pvStack_1040);
      return;
    }
  }
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00772f00 @ 0x00772f00 ====

int FUN_00772f00(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int extraout_EAX;
  uint uVar5;
  int unaff_retaddr;
  undefined4 local_2c;
  void *pvStack_28;
  undefined1 local_24;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00996393;
  pvStack_c = ExceptionList;
  local_2c = 0;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  piVar1 = (int *)(**(code **)(*DAT_00b5a7b4 + 0x58))();
  uVar5 = 0;
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  if (iVar2 != 0) {
    do {
      piVar3 = (int *)(**(code **)(*piVar1 + 4))();
      if (*piVar3 == param_2) {
        FUN_00401660(piVar3 + 4,0,0xffffffff);
        break;
      }
      (**(code **)(*piVar1 + 0xc))();
      uVar5 = uVar5 + 1;
      uVar4 = (**(code **)(*piVar1 + 0x10))();
    } while (uVar5 < uVar4);
  }
  (**(code **)(*DAT_00b5a7b4 + 0x5c))(piVar1);
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  FUN_00401660(&local_2c,0,0xffffffff);
  if (local_14 < 0x10) {
    ExceptionList = local_10;
    return unaff_retaddr;
  }
  _free(pvStack_28);
  return extraout_EAX;
}


// ==== FUN_00772fe0 @ 0x00772fe0 ====

/* WARNING: Removing unreachable block (ram,0x0077308e) */
/* WARNING: Removing unreachable block (ram,0x007730d9) */
/* WARNING: Removing unreachable block (ram,0x00773103) */

undefined4 FUN_00772fe0(void)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 auStack_74 [12];
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 *puStack_60;
  undefined1 auStack_30 [4];
  undefined1 uStack_2c;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009963ad;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
  puStack_60 = (undefined1 *)0x0;
  uStack_68 = 0x77302d;
  FUN_00401660();
  uVar1 = *(undefined4 *)((int)puStack_4 + 4);
  pvStack_c = (void *)0x0;
  puStack_60 = (undefined1 *)0x773040;
  cVar2 = FUN_00772160();
  if (cVar2 == '\0') {
    ExceptionList = pvStack_14;
    return 0;
  }
  puStack_60 = auStack_30;
  uStack_64 = 0x773055;
  uVar3 = FUN_00772f00();
  puStack_4 = auStack_74;
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
  FUN_00405bd0(auStack_74,uVar3,auStack_30 + -0x1c);
  (**(code **)(*DAT_00b5ad0c + 0x28))(4);
  uStack_2c = 0;
  (**(code **)(*DAT_00b5a7b8 + 0x20))(uVar1);
  (**(code **)(*DAT_00b5a7b8 + 0x70))();
  puVar4 = operator_new(4);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = &PTR_FUN_009f529c;
  }
  FUN_00797a20(puVar4);
  ExceptionList = (void *)0x0;
  return 1;
}


// ==== FUN_00773130 @ 0x00773130 ====

undefined4 FUN_00773130(int param_1)

{
  char cVar1;
  char *pcVar2;
  undefined4 extraout_EAX;
  undefined4 local_34;
  undefined4 local_30;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009963bf;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004f5730(&local_34);
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  pcVar2 = (char *)(param_1 + 0x1c);
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(param_1 + 0x1c),(int)pcVar2 - (param_1 + 0x1d));
  local_4 = 0;
  FUN_00772c60(*(undefined4 *)(param_1 + 0x10),*(undefined2 *)(param_1 + 0x14),local_28,
               CONCAT31((int3)((uint)(param_1 + 0x3a) >> 8),*(undefined1 *)(param_1 + 0x35)),
               (float)*(byte *)(param_1 + 0x36) * DAT_009a09b8,*(undefined2 *)(param_1 + 0x38),
               param_1 + 0x3a,local_34,local_30);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return 1;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00773220 @ 0x00773220 ====

/* WARNING: Removing unreachable block (ram,0x00773314) */

undefined4 FUN_00773220(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 extraout_EAX;
  undefined1 auStack_74 [12];
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 *puStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined1 auStack_42 [2];
  void *pvStack_40;
  undefined1 auStack_30 [4];
  uint uStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009963d9;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a7b8 + 0x6c))();
  if (iVar2 == *(int *)(param_1 + 0x10)) {
    iVar2 = (**(code **)(*DAT_00b5a7b8 + 0x28))();
    if (iVar2 != 0) {
      (**(code **)(*DAT_00b5a7b4 + 0x38))();
      uStack_58 = 0x77327c;
      (**(code **)(*DAT_00b5ada8 + 0x60))();
      uStack_58 = 0x773287;
      FUN_00774fc0();
      uStack_58 = 0x773292;
      (**(code **)(*DAT_00b5a7b8 + 0x70))();
    }
  }
  else {
    uStack_58 = 0;
    uStack_5c = 0x7732aa;
    uStack_64 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_5c = 0xffffffff;
    puStack_60 = (undefined1 *)0x0;
    uStack_68 = 0x7732c7;
    FUN_00401660();
    uVar1 = *(undefined4 *)(param_1 + 0x10);
    puStack_60 = auStack_30;
    pvStack_c = (void *)0x0;
    uStack_64 = 0x7732db;
    uStack_5c = uVar1;
    uVar3 = FUN_00772f00();
    puStack_4 = auStack_74;
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
    FUN_00405bd0(auStack_74,uVar3,auStack_42 + -10);
    (**(code **)(*DAT_00b5ad0c + 0x28))(4);
    uStack_2c = uStack_2c & 0xffffff00;
    (**(code **)(*DAT_00b5a7b8 + 0x20))(uVar1);
    (**(code **)(*DAT_00b5a7b8 + 0x70))();
    uStack_58 = 0x77333f;
    puVar4 = operator_new(4);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = &PTR_FUN_009f529c;
    }
    uStack_58 = 0x773356;
    FUN_00797a20();
    if (0xf < uStack_2c) {
      uStack_58 = 0x773369;
      _free(pvStack_40);
      return extraout_EAX;
    }
  }
  ExceptionList = pvStack_c;
  return 1;
}


// ==== FUN_00773390 @ 0x00773390 ====

undefined4 FUN_00773390(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  void *unaff_EDI;
  undefined1 auStack_78 [8];
  void *pvStack_70;
  undefined4 uStack_68;
  undefined4 *puStack_64;
  int iStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  void *pvStack_3c;
  undefined4 uStack_34;
  undefined1 uStack_30;
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &LAB_009963f3;
  pvStack_c = ExceptionList;
  uStack_54 = 0x460003;
  uStack_58 = 0;
  uStack_5c = 0x7733c0;
  ExceptionList = &pvStack_c;
  puStack_64 = (undefined4 *)(**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_5c = 0xffffffff;
  iStack_60 = 0;
  uStack_34 = 0xf;
  uStack_68 = 0x7733dd;
  FUN_00401660();
  iVar1 = *(int *)(iStack_4 + 0x10);
  pvStack_c = (void *)0x0;
  uStack_5c = 0x7733f3;
  iVar2 = (**(code **)(*DAT_00b5a7b8 + 0x6c))();
  if (iVar1 == iVar2) {
    uStack_5c = 1;
    iStack_60 = 0x773404;
    (**(code **)(*DAT_00b5a7b8 + 4))();
  }
  else {
    uStack_5c = 0;
    iStack_60 = 0x77340c;
    (**(code **)(*DAT_00b5a7b8 + 4))();
  }
  puStack_64 = &uStack_34;
  uStack_68 = 0x773419;
  iStack_60 = iVar1;
  uVar3 = FUN_00772f00();
  puStack_8 = auStack_78;
  uStack_10 = 1;
  FUN_00405bd0(auStack_78,uVar3,auStack_78 + 0x28);
  (**(code **)(*DAT_00b5ad0c + 0x28))(4);
  uStack_30 = 0;
  if ((void *)0xf < pvStack_3c) {
    _free(unaff_EDI);
    return extraout_EAX;
  }
  (**(code **)(*DAT_00b5a7b8 + 0xc))(iVar1);
  (**(code **)(*DAT_00b5a7b8 + 0x70))();
  if (uStack_5c < 0x10) {
    ExceptionList = pvStack_3c;
    return 1;
  }
  _free(pvStack_70);
  return extraout_EAX_00;
}


// ==== FUN_007734a0 @ 0x007734a0 ====

undefined4 FUN_007734a0(int param_1)

{
  short sVar1;
  undefined4 extraout_EAX;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX_00;
  undefined1 local_204 [4];
  void *local_200;
  int local_1f0;
  uint local_1ec;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009964c2;
  local_c = ExceptionList;
  sVar1 = *(short *)(param_1 + 0x18);
  ExceptionList = &local_c;
  FUN_00772f00(local_204,*(undefined4 *)(param_1 + 0x14));
  local_4 = 0;
  if (local_1f0 == 0) {
    if (0xf < local_1ec) {
      _free(local_200);
      return extraout_EAX;
    }
  }
  else {
    piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x14))();
    local_4._0_1_ = 1;
    switch(*(undefined1 *)(param_1 + 0x10)) {
    case 0:
      if (sVar1 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      iVar3 = (**(code **)(*piVar2 + 0x74))();
      uVar4 = FUN_00401830(iVar3 + 0x5c);
      local_4._0_1_ = 2;
      FUN_00423420(local_204,uVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 1:
      iVar3 = (**(code **)(*piVar2 + 0x74))();
      uVar4 = FUN_00401830(iVar3 + 0x5c);
      local_4._0_1_ = 5;
      FUN_004a1f80(local_204,uVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 2:
      iVar3 = (**(code **)(*piVar2 + 0x74))();
      uVar4 = FUN_00401830(iVar3 + 0x5c);
      local_4._0_1_ = 6;
      FUN_004a1f80(local_204,uVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 3:
      iVar3 = (**(code **)(*piVar2 + 0x74))();
      uVar4 = FUN_00401830(iVar3 + 0x5c);
      local_4._0_1_ = 7;
      FUN_004a1f80(local_204,uVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 4:
      iVar3 = (**(code **)(*piVar2 + 0x74))();
      uVar4 = FUN_00401830(iVar3 + 0x5c);
      local_4._0_1_ = 8;
      FUN_00423420(local_204,uVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 5:
      iVar3 = (**(code **)(*piVar2 + 0x74))();
      uVar4 = FUN_00401830(iVar3 + 0x5c);
      local_4._0_1_ = 0xb;
      FUN_004a1f80(local_204,uVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 6:
      iVar3 = (**(code **)(*piVar2 + 0x74))();
      uVar4 = FUN_00401830(iVar3 + 0x5c);
      local_4._0_1_ = 0xc;
      FUN_00423420(local_204,uVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 7:
      iVar3 = (**(code **)(*piVar2 + 0x74))();
      uVar4 = FUN_00401830(iVar3 + 0x5c);
      local_4._0_1_ = 0xf;
      FUN_004a1f80(local_204,uVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    case 8:
      iVar3 = (**(code **)(*piVar2 + 0x74))();
      uVar4 = FUN_00401830(iVar3 + 0x5c);
      local_4._0_1_ = 0x10;
      FUN_00423420(local_204,uVar4);
      local_4 = CONCAT31(local_4._1_3_,1);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    default:
      if (0xf < local_1ec) {
        _free(local_200);
        return extraout_EAX_00;
      }
    }
  }
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00773b80 @ 0x00773b80 ====

undefined4 FUN_00773b80(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x5110001) {
    if (uVar1 == 0x5110000) {
      FUN_00772620(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    switch(uVar1 + 0xfaeffffe) {
    case 0:
      FUN_00772410(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 2:
      FUN_00772990(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 3:
      FUN_00772ad0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 5:
      FUN_00772510(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 6:
      FUN_00772310(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 8:
      FUN_00772200(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 9:
      FUN_00773130(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 10:
      FUN_00772760(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else {
    switch(uVar1 + 0xfaeefffe) {
    case 0:
      FUN_00771f20(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 1:
      FUN_00773220(*(undefined4 *)(param_1 + 0xc));
      puVar2 = operator_new(4);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar2 = &PTR_FUN_009f529c;
      FUN_00797a20(puVar2);
      return 1;
    case 2:
      FUN_00773390(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 5:
      FUN_00771f50(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 6:
      FUN_00771f90(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 7:
      FUN_00772050(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 8:
      FUN_00771ff0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 9:
      FUN_00771fc0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0xb:
      FUN_007734a0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00773db0 @ 0x00773db0 ====

undefined4 FUN_00773db0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00773b80(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x30060100) {
    cVar1 = FUN_00772fe0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00773e00 @ 0x00773e00 ====

void FUN_00773e00(byte param_1)

{
  void *in_ECX;
  
  FUN_007721e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00773e20 @ 0x00773e20 ====

void FUN_00773e20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5384;
  return;
}


// ==== FUN_00773e30 @ 0x00773e30 ====

void FUN_00773e30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5384;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00773e50 @ 0x00773e50 ====

void FUN_00773e50(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00773e55. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 8))();
  return;
}


// ==== FUN_00773e60 @ 0x00773e60 ====

void FUN_00773e60(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00773e65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0xc))();
  return;
}


// ==== FUN_00773e70 @ 0x00773e70 ====

void FUN_00773e70(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00773e75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x18))();
  return;
}


// ==== FUN_00773e80 @ 0x00773e80 ====

void FUN_00773e80(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00773e85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  return;
}


// ==== FUN_00773e90 @ 0x00773e90 ====

void FUN_00773e90(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00773e95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
  return;
}


// ==== FUN_00773ea0 @ 0x00773ea0 ====

void FUN_00773ea0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00773ea5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_00773eb0 @ 0x00773eb0 ====

void FUN_00773eb0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00773eb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  return;
}


// ==== FUN_00773ec0 @ 0x00773ec0 ====

undefined1 FUN_00773ec0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xc);
}


// ==== FUN_00773ed0 @ 0x00773ed0 ====

void FUN_00773ed0(int param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 0x14) != 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 4))(param_1,param_2);
  }
  return;
}


// ==== FUN_00773ef0 @ 0x00773ef0 ====

void FUN_00773ef0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00773ef8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a7b8 + 0x28))();
  return;
}


// ==== FUN_00773f00 @ 0x00773f00 ====

void FUN_00773f00(void)

{
                    /* WARNING: Could not recover jumptable at 0x00773f08. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a7b8 + 0x30))();
  return;
}


// ==== FUN_00773f10 @ 0x00773f10 ====

void FUN_00773f10(void)

{
                    /* WARNING: Could not recover jumptable at 0x00773f18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a7b8 + 0x44))();
  return;
}


// ==== FUN_00773f20 @ 0x00773f20 ====

void FUN_00773f20(void)

{
                    /* WARNING: Could not recover jumptable at 0x00773f28. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a7b8 + 0x34))();
  return;
}


// ==== FUN_00773f30 @ 0x00773f30 ====

bool FUN_00773f30(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a7b8 + 0x38))(param_1);
  return iVar1 != 0;
}


// ==== FUN_00773f50 @ 0x00773f50 ====

void FUN_00773f50(void)

{
                    /* WARNING: Could not recover jumptable at 0x00773f58. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a7b8 + 0x48))();
  return;
}


// ==== FUN_00773f60 @ 0x00773f60 ====

void FUN_00773f60(void)

{
                    /* WARNING: Could not recover jumptable at 0x00773f68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a7b8 + 100))();
  return;
}


// ==== FUN_00773f70 @ 0x00773f70 ====

void FUN_00773f70(void)

{
                    /* WARNING: Could not recover jumptable at 0x00773f78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a7b8 + 0x68))();
  return;
}


// ==== FUN_00773f80 @ 0x00773f80 ====

void FUN_00773f80(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  if (param_1 == 0) {
    uVar1 = FUN_00794740();
    *(undefined4 *)(in_ECX + 8) = uVar1;
    return;
  }
  if (param_1 == 1) {
    uVar1 = FUN_00794350();
    *(undefined4 *)(in_ECX + 8) = uVar1;
    return;
  }
  uVar1 = FUN_00794290();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  return;
}


// ==== FUN_00773fd0 @ 0x00773fd0 ====

void FUN_00773fd0(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a7b8 + 0x28))();
  if (*(undefined4 **)(in_ECX + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 4))(1);
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  if (iVar1 == 0) {
    uVar2 = FUN_00794740();
  }
  else if (iVar1 == 1) {
    uVar2 = FUN_00794350();
  }
  else {
    uVar2 = FUN_00794290();
  }
  *(undefined4 *)(in_ECX + 4) = uVar2;
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar3 = &PTR_FUN_009f5414;
  FUN_00797a20(puVar3);
  return;
}


// ==== FUN_00774040 @ 0x00774040 ====

void FUN_00774040(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a7b8 + 0x28))();
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  if (iVar1 == 0) {
    uVar2 = FUN_00794740();
  }
  else if (iVar1 == 1) {
    uVar2 = FUN_00794350();
  }
  else {
    uVar2 = FUN_00794290();
  }
  *(undefined4 *)(in_ECX + 8) = uVar2;
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 0xc) = 1;
    return;
  }
  *puVar3 = &PTR_FUN_009ee728;
  FUN_00797a20(puVar3);
  *(undefined1 *)(in_ECX + 0xc) = 1;
  return;
}


// ==== FUN_007740c0 @ 0x007740c0 ====

undefined4 FUN_007740c0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 0xc) = 0;
    return 1;
  }
  *puVar1 = &PTR_FUN_009ee73c;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 0xc) = 0;
  return 1;
}


// ==== FUN_00774100 @ 0x00774100 ====

void FUN_00774100(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f53ec;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00774130 @ 0x00774130 ====

void FUN_00774130(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f5400;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00774160 @ 0x00774160 ====

void FUN_00774160(void)

{
                    /* WARNING: Could not recover jumptable at 0x00774168. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a7b8 + 0x6c))();
  return;
}


// ==== FUN_00774170 @ 0x00774170 ====

void FUN_00774170(int param_1)

{
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  int local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009964d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00404170(local_28,param_1);
  local_4 = 0;
  if ((*(int *)(param_1 + 0x14) == 0) || (local_14 == 0)) {
    if (local_10 < 0x10) {
      ExceptionList = local_c;
      return;
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(param_1);
    if (local_10 < 0x10) {
      ExceptionList = local_c;
      return;
    }
  }
  _free(local_24);
  return;
}


// ==== FUN_00774200 @ 0x00774200 ====

void FUN_00774200(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *unaff_EDI;
  uint *_Memory;
  undefined1 auStack_46 [2];
  uint local_44;
  void *local_40;
  void *pvStack_3c;
  uint uStack_38;
  void *pvStack_34;
  void *local_30;
  uint local_2c;
  uint local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099652d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  in_ECX[1] = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f5434;
  in_ECX[1] = &PTR_FUN_009f5428;
  local_4 = 1;
  if (DAT_00b5a7b8 == (int *)0x0) {
    local_2c = 0xf;
    local_30 = (void *)0x0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    FUN_00401740(s_IParty__IREFERENCE______NULL_009f52bc);
    local_4._0_1_ = 2;
    FUN_00406880();
    local_4 = CONCAT31(local_4._1_3_,1);
    if (local_2c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_40);
    return;
  }
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a7b4 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a7b4 = in_ECX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(&DAT_009f52d9);
  local_4._0_1_ = 3;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401740(s_show_party_009f52dc);
  _Memory = &local_44;
  local_4 = CONCAT31(local_4._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))(_Memory,0);
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
  FUN_00401740(&DAT_009f52e7,0);
  local_10._0_1_ = 5;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_party_009f52e8,10);
  local_10 = CONCAT31(local_10._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,&pvStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c._0_1_ = 1;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(s_party_invite__name__009f52f4,0x13);
  uStack_1c._0_1_ = 7;
  local_44 = 0xf;
  FUN_00401740(s_party_invite_009f5308,0xc);
  uStack_1c = CONCAT31(uStack_1c._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -0x16,1,&local_40);
  if (0xf < unaff_EBP) {
    _free(_Memory);
    return;
  }
  local_28 = CONCAT31(local_28._1_3_,1);
  if (pvStack_34 < (void *)0x10) {
    uVar2 = FUN_00794740();
    in_ECX[2] = uVar2;
    *(undefined1 *)(in_ECX + 3) = 0;
    (**(code **)(*DAT_00b5a7b8 + 0x74))(in_ECX + 1);
    ExceptionList = pvStack_34;
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_00774490 @ 0x00774490 ====

void FUN_00774490(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *pvStack_30;
  undefined4 *local_2c;
  void *local_28;
  undefined1 local_24;
  void *pvStack_1c;
  uint uStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099657e;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f5434;
  *puVar1 = &PTR_FUN_009f5428;
  local_4 = 1;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_party_009f5318,10);
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8._0_1_ = 1;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_party_009f5324,10);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  pvStack_c._0_1_ = 1;
  if (0xf < uStack_18) {
    _free(local_2c);
    return;
  }
  uStack_18 = 0xf;
  pvStack_1c = (void *)0x0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffffff00);
  FUN_00401740(s_party_invite_009f5330,0xc);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&pvStack_30);
  local_10 = CONCAT31(local_10._1_3_,1);
  if ((void *)0xf < pvStack_1c) {
    _free(pvStack_30);
    return;
  }
  DAT_00b5a7b4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  (**(code **)(*DAT_00b5a7b8 + 0x78))(puVar1);
  *puVar1 = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f5384;
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_00774600 @ 0x00774600 ====

undefined4 FUN_00774600(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  int *piVar7;
  undefined4 *******pppppppuVar8;
  undefined4 *******apppppppuStack_b8 [4];
  int iStack_a8;
  uint uStack_a4;
  undefined4 *******apppppppuStack_9c [5];
  uint uStack_88;
  undefined1 auStack_84 [4];
  undefined4 *******apppppppuStack_80 [5];
  uint uStack_6c;
  undefined1 auStack_66 [25];
  undefined1 auStack_4d [25];
  undefined1 auStack_34 [40];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009965a9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_party_009f5340,10);
  if (iVar2 == 0) {
    puVar3 = operator_new(4);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = &PTR_FUN_009ee728;
      FUN_00797a20(puVar3);
      ExceptionList = local_c;
      return 1;
    }
  }
  else {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_party_009f534c,10);
    if (iVar2 != 0) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_party_invite_009f5358,0xc);
      if (iVar2 != 0) {
        ExceptionList = local_c;
        return 0;
      }
      if (*(int *)(param_1 + 0x28) == 0) {
        ExceptionList = local_c;
        return 1;
      }
      if ((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c != 1) {
        ExceptionList = local_c;
        return 1;
      }
      iVar2 = (**(code **)(*DAT_00b5a7b8 + 0x28))();
      if (iVar2 != 1) {
        ExceptionList = local_c;
        return 1;
      }
      uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      uVar4 = FUN_007748c0(uVar4);
      FUN_00459160(auStack_84,0);
      uStack_4 = 0;
      uVar5 = (**(code **)(*DAT_00b5a7b8 + 0x30))();
      FUN_00765c50(uVar5);
      uStack_a4 = 0xf;
      iStack_a8 = 0;
      apppppppuStack_b8[0] = (undefined4 *******)((uint)apppppppuStack_b8[0] & 0xffffff00);
      uStack_4 = CONCAT31(uStack_4._1_3_,2);
      iVar2 = (**(code **)(*DAT_00b5a7b8 + 0x44))();
      piVar6 = (int *)(**(code **)(*DAT_00b5a7b8 + 100))();
      piVar7 = (int *)(**(code **)(*piVar6 + 4))();
      do {
        if (piVar7 == (int *)0x0) {
LAB_007747a9:
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        if (*piVar7 == iVar2) {
          FUN_00401660(piVar7 + 4,0,0xffffffff);
LAB_007747f1:
          (**(code **)(*DAT_00b5a7b8 + 0x68))(piVar6);
          if (iStack_a8 != 0) {
            if (uStack_88 < 0x10) {
              apppppppuStack_9c[0] = apppppppuStack_9c;
            }
            FUN_00478050(apppppppuStack_9c[0]);
            pppppppuVar8 = apppppppuStack_b8[0];
            if (uStack_a4 < 0x10) {
              pppppppuVar8 = apppppppuStack_b8;
            }
            FUN_0047aa60(pppppppuVar8);
            if (uStack_6c < 0x10) {
              apppppppuStack_80[0] = apppppppuStack_80;
            }
            FUN_0047aa60(apppppppuStack_80[0]);
            FUN_00774920(auStack_66,auStack_4d,auStack_34);
            FUN_004ef210(uVar4);
          }
          goto LAB_007747a9;
        }
        cVar1 = (**(code **)(*piVar6 + 8))();
        if (cVar1 == '\0') goto LAB_007747f1;
        (**(code **)(*piVar6 + 0xc))();
        piVar7 = (int *)(**(code **)(*piVar6 + 4))();
      } while( true );
    }
    puVar3 = operator_new(4);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = &PTR_FUN_009ee73c;
      FUN_00797a20(puVar3);
      ExceptionList = local_c;
      return 1;
    }
  }
  FUN_00797a20(0);
  ExceptionList = local_c;
  return 1;
}


// ==== FUN_00774890 @ 0x00774890 ====

undefined4 FUN_00774890(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_00774600(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007748c0 @ 0x007748c0 ====

void FUN_007748c0(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5100003;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  FUN_004244d0();
  return;
}


// ==== FUN_007748f0 @ 0x007748f0 ====

undefined4 FUN_007748f0(void)

{
  return 0x70010002;
}


// ==== FUN_00774900 @ 0x00774900 ====

undefined4 FUN_00774900(void)

{
  return 0x70010003;
}


// ==== FUN_00774910 @ 0x00774910 ====

undefined4 FUN_00774910(void)

{
  return 0x70010004;
}


// ==== FUN_00774920 @ 0x00774920 ====

uint FUN_00774920(int param_1,int param_2,int param_3)

{
  undefined1 *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  int in_ECX;
  uint uVar5;
  undefined2 uVar6;
  char cVar7;
  
  uVar3 = 0;
  do {
    if (*(char *)(uVar3 + param_1) == '\0') {
      cVar7 = (char)uVar3;
      goto LAB_00774944;
    }
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x19);
  cVar7 = '\0';
LAB_00774944:
  *(char *)(in_ECX + 0x10) = cVar7;
  uVar3 = 0;
  do {
    if (*(char *)(uVar3 + param_2) == '\0') goto LAB_00774960;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x19);
  uVar3 = 0;
LAB_00774960:
  *(char *)(in_ECX + 0x11) = (char)uVar3;
  uVar5 = 0;
  do {
    if (*(char *)(uVar5 + param_3) == '\0') goto LAB_00774980;
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x28);
  uVar5 = 0;
LAB_00774980:
  *(char *)(in_ECX + 0x12) = (char)uVar5;
  if (((cVar7 == '\0') || ((char)uVar3 == '\0')) || ((char)uVar5 == '\0')) {
    return uVar3 & 0xffffff00;
  }
  uVar3 = 0;
  puVar1 = (undefined1 *)(in_ECX + 0x14);
  if (cVar7 != '\0') {
    puVar4 = puVar1;
    do {
      *puVar4 = puVar4[param_1 - (int)puVar1];
      uVar5 = (uint)*(byte *)(in_ECX + 0x10);
      uVar3 = uVar3 + 1;
      puVar4 = puVar4 + 1;
    } while (uVar3 < uVar5);
  }
  uVar3 = 0;
  if (*(char *)(in_ECX + 0x11) != '\0') {
    do {
      puVar1[*(byte *)(in_ECX + 0x10) + uVar3] = *(undefined1 *)(uVar3 + param_2);
      uVar5 = (uint)*(byte *)(in_ECX + 0x11);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar5);
  }
  uVar3 = 0;
  if (*(char *)(in_ECX + 0x12) != '\0') {
    do {
      puVar1[(uint)*(byte *)(in_ECX + 0x11) + *(byte *)(in_ECX + 0x10) + uVar3] =
           *(undefined1 *)(uVar3 + param_3);
      uVar5 = (uint)*(byte *)(in_ECX + 0x12);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar5);
  }
  uVar6 = (undefined2)(uVar5 >> 0x10);
  iVar2 = CONCAT22((short)(uVar3 >> 0x10),(ushort)*(byte *)(in_ECX + 0x10)) +
          CONCAT22(uVar6,(ushort)*(byte *)(in_ECX + 0x12)) + 0x14 +
          CONCAT22(uVar6,(ushort)*(byte *)(in_ECX + 0x11));
  *(short *)(in_ECX + 6) = (short)iVar2;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


// ==== FUN_00774a40 @ 0x00774a40 ====

void FUN_00774a40(void)

{
  FUN_00774a50();
  return;
}


// ==== FUN_00774a50 @ 0x00774a50 ====

void FUN_00774a50(byte param_1)

{
  void *in_ECX;
  
  FUN_00774490();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00774a70 @ 0x00774a70 ====

void FUN_00774a70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f54bc;
  return;
}


// ==== FUN_00774a80 @ 0x00774a80 ====

void FUN_00774a80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f54bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00774aa0 @ 0x00774aa0 ====

void FUN_00774aa0(char param_1)

{
  int in_ECX;
  
  *(uint *)(in_ECX + 0x24) = 2 - (uint)(param_1 != '\0');
  return;
}


// ==== FUN_00774ac0 @ 0x00774ac0 ====

void FUN_00774ac0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x44) = param_1;
  return;
}


// ==== FUN_00774ad0 @ 0x00774ad0 ====

void FUN_00774ad0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x50) = param_1;
  return;
}


// ==== FUN_00774ae0 @ 0x00774ae0 ====

void FUN_00774ae0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = param_1;
  return;
}


// ==== FUN_00774af0 @ 0x00774af0 ====

undefined4 FUN_00774af0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x24);
}


// ==== FUN_00774b00 @ 0x00774b00 ====

int FUN_00774b00(void)

{
  int in_ECX;
  
  return in_ECX + 0x28;
}


// ==== FUN_00774b10 @ 0x00774b10 ====

undefined4 FUN_00774b10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x44);
}


// ==== FUN_00774b20 @ 0x00774b20 ====

undefined1 FUN_00774b20(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x50);
}


// ==== FUN_00774b30 @ 0x00774b30 ====

int FUN_00774b30(void)

{
  int in_ECX;
  
  return 6 - *(int *)(in_ECX + 0x20);
}


// ==== FUN_00774b40 @ 0x00774b40 ====

undefined4 FUN_00774b40(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009965cb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x10);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_007948b0(in_ECX + 0x10);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_00774ba0 @ 0x00774ba0 ====

undefined4 FUN_00774ba0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x4c);
}


// ==== FUN_00774bb0 @ 0x00774bb0 ====

void FUN_00774bb0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x4c) = param_1;
  return;
}


// ==== FUN_00774bc0 @ 0x00774bc0 ====

void FUN_00774bc0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00774bd2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)();
  return;
}


// ==== FUN_00774be0 @ 0x00774be0 ====

bool FUN_00774be0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    if (iVar3 == 2) {
      iVar3 = (**(code **)(*piVar2 + 0x14))();
      cVar1 = (**(code **)(*in_ECX + 0x3c))(*(undefined4 *)(iVar3 + 0xc));
      return cVar1 != '\0';
    }
  }
  return false;
}


// ==== FUN_00774c30 @ 0x00774c30 ====

void FUN_00774c30(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x38))(param_1);
  if (iVar1 == 0) {
    return;
  }
  FUN_007949a0();
  return;
}


// ==== FUN_00774c50 @ 0x00774c50 ====

undefined4 FUN_00774c50(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x18);
  puVar4 = *(undefined4 **)(in_ECX + 0x14);
  while( true ) {
    if (puVar4 == puVar1) {
      return 0;
    }
    uVar2 = *puVar4;
    piVar3 = (int *)FUN_007949a0();
    if (*piVar3 == param_1) break;
    puVar4 = puVar4 + 1;
  }
  return uVar2;
}


// ==== FUN_00774c90 @ 0x00774c90 ====

undefined4 FUN_00774c90(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  
  piVar3 = *(int **)(in_ECX + 0x14);
  piVar1 = *(int **)(in_ECX + 0x18);
  while( true ) {
    if (piVar3 == piVar1) {
      return 0;
    }
    if ((*piVar3 != 0) && (iVar2 = FUN_007949a0(), *(int *)(iVar2 + 4) == param_1)) break;
    piVar3 = piVar3 + 1;
  }
  return 1;
}


// ==== FUN_00774cd0 @ 0x00774cd0 ====

/* WARNING: Removing unreachable block (ram,0x00774d16) */

undefined4 FUN_00774cd0(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  int in_ECX;
  uint uVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  bool bVar10;
  bool bVar11;
  
  puVar8 = *(undefined4 **)(in_ECX + 0x14);
  puVar1 = *(undefined4 **)(in_ECX + 0x18);
  do {
    if (puVar8 == puVar1) {
      return 0;
    }
    uVar2 = *puVar8;
    iVar5 = FUN_007949a0();
    uVar3 = *(uint *)(param_1 + 0x14);
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      pbVar9 = (byte *)(param_1 + 4);
    }
    else {
      pbVar9 = *(byte **)(param_1 + 4);
    }
    uVar4 = *(uint *)(iVar5 + 0x24);
    if (uVar4 == 0) {
LAB_00774d48:
      if ((uVar3 <= uVar4) && (uVar4 == uVar3)) {
        return uVar2;
      }
    }
    else {
      uVar7 = uVar4;
      if (uVar3 <= uVar4) {
        uVar7 = uVar3;
      }
      if (*(uint *)(iVar5 + 0x28) < 0x10) {
        pbVar6 = (byte *)(iVar5 + 0x14);
      }
      else {
        pbVar6 = *(byte **)(iVar5 + 0x14);
      }
      bVar10 = false;
      iVar5 = 0;
      bVar11 = true;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar10 = *pbVar6 < *pbVar9;
        bVar11 = *pbVar6 == *pbVar9;
        pbVar6 = pbVar6 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar11);
      if (!bVar11) {
        iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
      }
      if (iVar5 == 0) goto LAB_00774d48;
    }
    puVar8 = puVar8 + 1;
  } while( true );
}


// ==== FUN_00774d80 @ 0x00774d80 ====

void FUN_00774d80(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int in_ECX;
  int *_Dst;
  
  piVar1 = *(int **)(in_ECX + 0x18);
  _Dst = *(int **)(in_ECX + 0x14);
  if (_Dst != piVar1) {
    while( true ) {
      puVar2 = (undefined4 *)*_Dst;
      piVar3 = (int *)FUN_007949a0();
      if (*piVar3 == param_1) break;
      _Dst = _Dst + 1;
      if (_Dst == piVar1) {
        return;
      }
    }
    _memmove(_Dst,_Dst + 1,(*(int *)(in_ECX + 0x18) - (int)(_Dst + 1) >> 2) * 4);
    *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + -4;
    if (puVar2 != (undefined4 *)0x0) {
      (**(code **)*puVar2)(1);
    }
  }
  return;
}


// ==== FUN_00774de0 @ 0x00774de0 ====

void FUN_00774de0(void)

{
  int *piVar1;
  int in_ECX;
  int *piVar2;
  
  piVar1 = *(int **)(in_ECX + 0x18);
  for (piVar2 = *(int **)(in_ECX + 0x14); piVar2 != piVar1; piVar2 = piVar2 + 1) {
    if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar2)(1);
    }
  }
  if (*(void **)(in_ECX + 0x14) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_00774e30 @ 0x00774e30 ====

void FUN_00774e30(void)

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


// ==== FUN_00774e90 @ 0x00774e90 ====

void FUN_00774e90(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00774c50(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_007949a0();
    *(undefined4 *)(iVar1 + 0x48) = param_2;
  }
  return;
}


// ==== FUN_00774ec0 @ 0x00774ec0 ====

void FUN_00774ec0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00774c50(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_007949a0();
    *(undefined4 *)(iVar1 + 8) = param_2;
  }
  return;
}


// ==== FUN_00774ee0 @ 0x00774ee0 ====

void FUN_00774ee0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_00774c50(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_007949a0();
    *(undefined4 *)(iVar1 + 0x50) = param_2;
    *(undefined4 *)(iVar1 + 0x54) = param_3;
  }
  return;
}


// ==== FUN_00774f10 @ 0x00774f10 ====

void FUN_00774f10(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_00774c50(param_1);
  if ((iVar1 != 0) && (param_2 != 0)) {
    iVar3 = 0;
    iVar1 = 8;
    do {
      iVar2 = FUN_007949a0();
      *(undefined1 *)(iVar2 + 0x58 + iVar3) = *(undefined1 *)(iVar3 + param_2);
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// ==== FUN_00774f50 @ 0x00774f50 ====

void FUN_00774f50(undefined4 param_1)

{
  FUN_00401660(param_1,0,0xffffffff);
  return;
}


// ==== FUN_00774f70 @ 0x00774f70 ====

void FUN_00774f70(int param_1,int param_2,int param_3,undefined1 param_4,undefined4 param_5)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x24))();
  in_ECX[8] = param_3;
  in_ECX[9] = (param_1 != param_2) + 1;
  FUN_00401660(param_5,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x14) = param_4;
  in_ECX[0x11] = param_2;
  (**(code **)(*in_ECX + 0x10))(param_1);
  return;
}


// ==== FUN_00774fc0 @ 0x00774fc0 ====

void FUN_00774fc0(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x24))();
  in_ECX[8] = 6;
  in_ECX[9] = 0;
  FUN_00401740(&DAT_009f54a3,0);
  in_ECX[0x11] = 0;
  in_ECX[0x13] = -1;
  return;
}


// ==== FUN_00775000 @ 0x00775000 ====

/* WARNING: Removing unreachable block (ram,0x007750b6) */

void FUN_00775000(void)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  int *in_ECX;
  uint uVar6;
  int iVar7;
  byte *****pppppbVar8;
  bool bVar9;
  bool bVar10;
  int local_30;
  byte *****local_24 [4];
  uint local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009965dd;
  iVar1 = in_ECX[6];
  iVar7 = in_ECX[5];
  local_10 = 0xf;
  local_14 = 0;
  local_24[0] = (byte *****)((uint)local_24[0] & 0xffffff00);
  local_4 = 0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  for (; iVar7 != iVar1; iVar7 = iVar7 + 4) {
    piVar3 = (int *)FUN_007949a0();
    iVar4 = (**(code **)(*in_ECX + 0x6c))();
    if (*piVar3 == iVar4) {
      iVar7 = FUN_007949a0();
      FUN_00401660(iVar7 + 0x2c,0,0xffffffff);
      break;
    }
  }
  local_30 = in_ECX[5];
  if (local_30 != iVar1) {
    do {
      iVar7 = FUN_007949a0();
      pppppbVar8 = local_24[0];
      if (local_10 < 0x10) {
        pppppbVar8 = (byte *****)local_24;
      }
      uVar2 = *(uint *)(iVar7 + 0x40);
      if (uVar2 == 0) {
LAB_007750e8:
        if ((uVar2 < local_14) || (uVar2 != local_14)) goto LAB_00775104;
        iVar7 = FUN_007949a0();
        *(undefined1 *)(iVar7 + 0x4c) = 1;
      }
      else {
        uVar6 = uVar2;
        if (local_14 <= uVar2) {
          uVar6 = local_14;
        }
        if (*(uint *)(iVar7 + 0x44) < 0x10) {
          pbVar5 = (byte *)(iVar7 + 0x30);
        }
        else {
          pbVar5 = *(byte **)(iVar7 + 0x30);
        }
        bVar9 = false;
        iVar7 = 0;
        bVar10 = true;
        do {
          if (uVar6 == 0) break;
          uVar6 = uVar6 - 1;
          bVar9 = *pbVar5 < *(byte *)pppppbVar8;
          bVar10 = *pbVar5 == *(byte *)pppppbVar8;
          pbVar5 = pbVar5 + 1;
          pppppbVar8 = (byte *****)((int)pppppbVar8 + 1);
        } while (bVar10);
        if (!bVar10) {
          iVar7 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        if (iVar7 == 0) goto LAB_007750e8;
LAB_00775104:
        iVar7 = FUN_007949a0();
        *(undefined1 *)(iVar7 + 0x4c) = 0;
      }
      local_30 = local_30 + 4;
    } while (local_30 != iVar1);
  }
  if (local_10 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(local_24[0]);
  return;
}


// ==== FUN_00775150 @ 0x00775150 ====

void FUN_00775150(undefined1 param_1)

{
  undefined1 local_8 [8];
  
  FUN_00752030(local_8,&param_1);
  return;
}


// ==== FUN_00775170 @ 0x00775170 ====

void FUN_00775170(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 local_ffc;
  
  iVar2 = FUN_00774c50(param_1);
  if (iVar2 != 0) {
    piVar3 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(param_2);
    if (piVar3 == (int *)0x0) {
      FUN_007949a0();
      FUN_00401740(s_Invalid_Name_009f54a4,0xc);
      FUN_00775000();
      return;
    }
    puVar4 = (undefined4 *)(**(code **)(*piVar3 + 0x10))();
    puVar6 = &local_ffc;
    for (iVar2 = 0x3fb; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar6 = puVar6 + 1;
    }
    FUN_007949a0();
    pcVar5 = (char *)((int)&local_ffc + 2);
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    FUN_00401740((int)&local_ffc + 2,(int)pcVar5 - ((int)&local_ffc + 3));
    FUN_00775000();
  }
  return;
}


// ==== __break @ 0x00775227 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00775230 @ 0x00775230 ====

void FUN_00775230(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00996610;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f553c;
  local_4 = 3;
  DAT_00b5a7b8 = 0;
  FUN_00774de0();
  if (0xf < (uint)in_ECX[0x10]) {
    _free((void *)in_ECX[0xb]);
    return;
  }
  in_ECX[0x10] = 0xf;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  if ((void *)in_ECX[5] == (void *)0x0) {
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    local_4 = local_4 & 0xffffff00;
    FUN_007520f0(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
    _free((void *)in_ECX[2]);
    return;
  }
  _free((void *)in_ECX[5]);
  return;
}


// ==== FUN_007752f0 @ 0x007752f0 ====

void FUN_007752f0(undefined1 param_1)

{
  FUN_00752400(&param_1);
  return;
}


// ==== FUN_00775300 @ 0x00775300 ====

void FUN_00775300(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00996643;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f553c;
  iVar1 = FUN_00751a80();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x11) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[0x10] = 0xf;
  in_ECX[0xf] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  local_4 = CONCAT31(local_4._1_3_,3);
  in_ECX[9] = 0;
  in_ECX[8] = 6;
  FUN_00401740(s_NoName_009f549c,6);
  in_ECX[0x11] = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a7b8 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a7b8 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_007753d0 @ 0x007753d0 ====

void FUN_007753d0(undefined4 param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996658;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar2 = operator_new(100);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00794a10();
  }
  local_4 = 0xffffffff;
  FUN_006c5210(param_1);
  FUN_00794a40();
  iVar4 = *(int *)(in_ECX + 0x14);
  if ((iVar4 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x1c) - iVar4 >> 2) <= (uint)(*(int *)(in_ECX + 0x18) - iVar4 >> 2)))
  {
    FUN_00775550();
  }
  else {
    puVar1 = *(undefined4 **)(in_ECX + 0x18);
    *puVar1 = uVar3;
    *(undefined4 **)(in_ECX + 0x18) = puVar1 + 1;
  }
  if (*(int *)(in_ECX + 0x14) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
  }
  if (6 < (uint)(*(int *)(in_ECX + 0x20) + iVar4)) {
    if (*(int *)(in_ECX + 0x14) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 0x18) - *(int *)(in_ECX + 0x14) >> 2;
    }
    *(int *)(in_ECX + 0x20) = 6 - iVar4;
  }
  FUN_00775000();
  ExceptionList = local_c;
  return;
}


// ==== FUN_007754e0 @ 0x007754e0 ====

void FUN_007754e0(void)

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
  puStack_8 = &LAB_00996678;
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


// ==== FUN_00775550 @ 0x00775550 ====

void FUN_00775550(void *param_1,uint param_2,undefined4 *param_3)

{
  size_t _Size;
  int iVar1;
  uint uVar2;
  void *_Dst;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  undefined8 uVar7;
  
  iVar5 = *(int *)(in_ECX + 4);
  param_3 = (undefined4 *)*param_3;
  if (iVar5 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar5 >> 2;
  }
  uVar7 = CONCAT44(iVar5,iVar1);
  if (param_2 != 0) {
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 2;
    }
    if (0x3fffffffU - iVar5 < param_2) {
      uVar7 = FUN_007754e0();
    }
    iVar5 = (int)((ulonglong)uVar7 >> 0x20);
    uVar2 = (uint)uVar7;
    if (iVar5 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 2;
    }
    if (uVar2 < iVar1 + param_2) {
      if (0x3fffffff - (uVar2 >> 1) < uVar2) {
        uVar2 = 0;
      }
      else {
        uVar2 = uVar2 + (uVar2 >> 1);
      }
      if (iVar5 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar5 >> 2;
      }
      if (uVar2 < iVar1 + param_2) {
        if (iVar5 == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - iVar5 >> 2;
        }
        uVar2 = iVar5 + param_2;
      }
      _Dst = operator_new(uVar2 * 4);
      _Size = ((int)param_1 - (int)*(void **)(in_ECX + 4) >> 2) * 4;
      pvVar3 = _memmove(_Dst,*(void **)(in_ECX + 4),_Size);
      pvVar3 = (void *)FUN_00845740((void *)((int)pvVar3 + _Size),param_2,&param_3);
      _memmove(pvVar3,param_1,(*(int *)(in_ECX + 8) - (int)param_1 >> 2) * 4);
      pvVar3 = *(void **)(in_ECX + 4);
      if (pvVar3 == (void *)0x0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - (int)pvVar3 >> 2;
      }
      if (pvVar3 == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar2 * 4 + (int)_Dst);
        *(void **)(in_ECX + 8) = (void *)((int)_Dst + (param_2 + iVar5) * 4);
        *(void **)(in_ECX + 4) = _Dst;
        return;
      }
      _free(pvVar3);
      return;
    }
    iVar1 = *(int *)(in_ECX + 8);
    iVar5 = param_2 * 4;
    if ((uint)(iVar1 - (int)param_1 >> 2) < param_2) {
      FUN_005a6d90(param_1,iVar1,(void *)(iVar5 + (int)param_1));
      FUN_00845740(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - (int)param_1 >> 2),
                   &param_3);
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar5;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + param_2 * -4,&param_3);
      return;
    }
    iVar6 = iVar1 + param_2 * -4;
    uVar4 = FUN_005a6d90(iVar6,iVar1,iVar1);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00822d20(param_1,iVar6,iVar1);
    FUN_008335f0(param_1,(void *)(iVar5 + (int)param_1),&param_3);
  }
  return;
}


// ==== FUN_00775730 @ 0x00775730 ====

void FUN_00775730(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = param_1;
  return;
}


// ==== FUN_00775740 @ 0x00775740 ====

void FUN_00775740(byte param_1)

{
  void *in_ECX;
  
  FUN_00775230();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00775760 @ 0x00775760 ====

void FUN_00775760(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5620;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00775790 @ 0x00775790 ====

void FUN_00775790(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5630;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad2c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ad2c = in_ECX;
  return;
}


// ==== FUN_007757c0 @ 0x007757c0 ====

void FUN_007757c0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad2c = 0;
  *in_ECX = &PTR_FUN_009f5620;
  return;
}


// ==== FUN_007757e0 @ 0x007757e0 ====

/* WARNING: Removing unreachable block (ram,0x0077584d) */
/* WARNING: Removing unreachable block (ram,0x007758c3) */

int FUN_007757e0(undefined2 *param_1)

{
  char cVar1;
  int iVar2;
  int extraout_EAX;
  undefined1 auStack_42 [22];
  undefined1 auStack_2c [4];
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009966a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5ab18 + 4))(*param_1);
  if (iVar2 == 0) {
    FUN_00401740(&DAT_009f55bc,0x13);
    puStack_8 = (undefined1 *)0x0;
    FUN_00796d50(auStack_42 + -6);
    ExceptionList = pvStack_10;
    return 0;
  }
  cVar1 = FUN_006eb9e0(iVar2);
  if (cVar1 == '\0') {
    FUN_00401740(&DAT_009f55d0,0x15);
    puStack_8 = (undefined1 *)0x1;
    FUN_00796d50(auStack_42 + -6);
    puStack_8 = (undefined1 *)0xffffffff;
  }
  cVar1 = FUN_006eb490(iVar2);
  if (cVar1 == '\0') {
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    FUN_00401740(&DAT_009f55e8,0x1e);
    puStack_8 = (undefined1 *)0x2;
    FUN_00796d50(auStack_2c);
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return extraout_EAX;
    }
  }
  ExceptionList = pvStack_10;
  return iVar2;
}


// ==== FUN_00775940 @ 0x00775940 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x007759ee) */

void FUN_00775940(int *param_1)

{
  code *pcVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined1 auStack_1022 [26];
  undefined4 auStack_1008 [1019];
  undefined4 uStack_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009966bd;
  local_14 = ExceptionList;
  uStack_1c = 0x775966;
  if (param_1 != (int *)0x0) {
    ExceptionList = &local_14;
    piVar2 = (int *)(**(code **)(*param_1 + 0x2c))();
    puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
    puVar5 = auStack_1008;
    for (iVar4 = 0x3fb; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar5 = puVar5 + 1;
    }
    piVar2 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(auStack_1008[0]);
    if (piVar2 == (int *)0x0) {
      FUN_00401740(s_pFlyweight____NULL_009f5608,0x12);
      puStack_10 = (undefined1 *)0x0;
      FUN_00406880(auStack_1022 + -6);
      puStack_10 = (undefined1 *)0xffffffff;
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    (**(code **)(*piVar2 + 0xc))();
    (**(code **)(*DAT_00b5ab18 + 8))(param_1);
  }
  ExceptionList = local_14;
  return;
}


// ==== FUN_00775a40 @ 0x00775a40 ====

void FUN_00775a40(byte param_1)

{
  void *in_ECX;
  
  FUN_007757c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00775a60 @ 0x00775a60 ====

void FUN_00775a60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5714;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00775a80 @ 0x00775a80 ====

undefined4 FUN_00775a80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00775a90 @ 0x00775a90 ====

void FUN_00775a90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5724;
  in_ECX[1] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5acd4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5acd4 = in_ECX;
  return;
}


// ==== FUN_00775ac0 @ 0x00775ac0 ====

void FUN_00775ac0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5acd4 = 0;
  *in_ECX = &PTR_FUN_009f5714;
  return;
}


// ==== FUN_00775ae0 @ 0x00775ae0 ====

int FUN_00775ae0(int param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0:
    FUN_00401830(s_Play_State_009f5654);
    return param_1;
  case 1:
    FUN_00401830(s_Trade_State_009f5660);
    return param_1;
  case 2:
    FUN_00401830(s_Shop_State_009f566c);
    return param_1;
  case 3:
    FUN_00401830(s_Talk_State_009f5678);
    return param_1;
  case 4:
    FUN_00401830(s_Storage_State_009f5684);
    return param_1;
  case 5:
    FUN_00401830(s_Store_State_009f5694);
    return param_1;
  case 6:
    FUN_00401830(s_Guild_State_009f56a0);
    return param_1;
  case 7:
    FUN_00401830(s_Upgrade_State_009f56ac);
    return param_1;
  case 8:
    FUN_00401830(s_Degrade_State_009f56bc);
    return param_1;
  case 9:
    FUN_00401830(s_ItemAddSocket_state_009f56cc);
    return param_1;
  case 10:
    FUN_00401830(s_Mail_State_009f56e0);
    return param_1;
  default:
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(s_Unhandled_State_009f5700,0xf);
    return param_1;
  case 0xc:
    FUN_00401830(s_Request_Quest_State_009f56ec);
    return param_1;
  }
}


// ==== FUN_00775c70 @ 0x00775c70 ====

void FUN_00775c70(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_98 [4];
  void *local_94;
  undefined4 local_84;
  uint local_80;
  undefined1 local_7c [4];
  void *local_78;
  undefined4 local_68;
  uint local_64;
  undefined1 local_60 [4];
  void *local_5c;
  undefined4 local_4c;
  uint local_48;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009966fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  uVar1 = FUN_00775ae0(local_28,param_1);
  local_4 = 0;
  uVar2 = FUN_00775ae0(local_60,*(undefined4 *)(in_ECX + 4));
  local_4._0_1_ = 1;
  uVar2 = FUN_004022a0(local_98,&DAT_009f5648,uVar2);
  local_4._0_1_ = 2;
  uVar2 = FUN_00402220(local_44,uVar2,&DAT_009f5640);
  local_4._0_1_ = 3;
  uVar1 = FUN_00405bd0(local_7c,uVar2,uVar1);
  local_4 = CONCAT31(local_4._1_3_,4);
  FUN_00796d50(uVar1);
  if (0xf < local_64) {
    _free(local_78);
    return;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (0xf < local_80) {
    _free(local_94);
    return;
  }
  local_80 = 0xf;
  local_84 = 0;
  local_94 = (void *)((uint)local_94 & 0xffffff00);
  if (0xf < local_48) {
    _free(local_5c);
    return;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    _free(local_24);
    return;
  }
  *(int *)(in_ECX + 4) = param_1;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_10 = 0xf;
  if (param_1 != 0) {
    (**(code **)(*DAT_00b5ac28 + 0x34))();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00775e10 @ 0x00775e10 ====

void FUN_00775e10(byte param_1)

{
  void *in_ECX;
  
  FUN_00775ac0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00775e30 @ 0x00775e30 ====

void FUN_00775e30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5894;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00775e60 @ 0x00775e60 ====

void FUN_00775e60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f58a0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5af28 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5af28 = in_ECX;
  return;
}


// ==== FUN_00775e90 @ 0x00775e90 ====

void FUN_00775e90(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5af28 = 0;
  *in_ECX = &PTR_FUN_009f5894;
  return;
}


// ==== FUN_00775eb0 @ 0x00775eb0 ====

undefined4 FUN_00775eb0(void)

{
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996738;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s__________________________________009f5738,0x45);
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
  FUN_00401740(s__________________________________009f5780,0x45);
  local_4 = 1;
  FUN_00796d50(local_28);
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_00;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_>>>_SN_FailNotify_Received___All_009f57c8,0x31);
  local_4 = 2;
  FUN_00796d50(local_28);
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_01;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s__________________________________009f5800,0x45);
  local_4 = 3;
  FUN_00796d50(local_28);
  local_4 = 0xffffffff;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX_02;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  FUN_00401740(s__________________________________009f5848,0x45);
  local_4 = 4;
  FUN_00796d50(local_44);
  local_4 = 0xffffffff;
  if (local_2c < 0x10) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    (**(code **)(*DAT_00b5af2c + 0x10))();
    ExceptionList = pvStack_c;
    return 1;
  }
  _free(local_40);
  return extraout_EAX_03;
}


// ==== FUN_007760a0 @ 0x007760a0 ====

undefined4 FUN_007760a0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    iVar2 = FUN_00424500();
    if (iVar2 == 0x5060009) {
      cVar1 = FUN_00775eb0(param_1[3]);
      if (cVar1 != '\0') {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_007760f0 @ 0x007760f0 ====

void FUN_007760f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00775e90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00776110 @ 0x00776110 ====

void FUN_00776110(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5950;
  return;
}


// ==== FUN_00776120 @ 0x00776120 ====

void FUN_00776120(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5950;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00776140 @ 0x00776140 ====

void FUN_00776140(uint *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint *in_ECX;
  
  uVar1 = *in_ECX;
  uVar2 = in_ECX[1];
  if ((param_2 < 0) && (uVar1 < (uint)-param_2)) {
    *param_1 = uVar1 + param_2 & 0x1f;
    param_1[1] = uVar2 + (-(uVar1 + param_2) - 1 >> 5) * -4 + -4;
    return;
  }
  *param_1 = uVar1 + param_2 & 0x1f;
  param_1[1] = uVar2 + (uVar1 + param_2 >> 5) * 4;
  return;
}


// ==== FUN_007761a0 @ 0x007761a0 ====

void FUN_007761a0(uint *param_1,uint param_2,uint *param_3,uint param_4,uint *param_5,uint param_6,
                 uint *param_7)

{
  while ((param_3 != param_5 || (param_2 != param_4))) {
    if ((*param_3 & 1 << ((byte)param_2 & 0x1f)) == 0) {
      *param_7 = *param_7 & ~(1 << ((byte)param_6 & 0x1f));
    }
    else {
      *param_7 = *param_7 | 1 << ((byte)param_6 & 0x1f);
    }
    if (param_6 < 0x1f) {
      param_6 = param_6 + 1;
    }
    else {
      param_6 = 0;
      param_7 = param_7 + 1;
    }
    if (param_2 < 0x1f) {
      param_2 = param_2 + 1;
    }
    else {
      param_2 = 0;
      param_3 = param_3 + 1;
    }
  }
  *param_1 = param_6;
  param_1[1] = (uint)param_7;
  return;
}


// ==== FUN_00776220 @ 0x00776220 ====

void FUN_00776220(uint *param_1)

{
  uint uVar1;
  uint *in_ECX;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *in_ECX;
  uVar2 = in_ECX[2];
  uVar3 = 0;
  if (uVar1 != 0) {
    if (((int)uVar1 < 0) && (uVar1 != 0)) {
      *param_1 = uVar1 & 0x1f;
      param_1[1] = uVar2 + (-uVar1 - 1 >> 5) * -4 + -4;
      return;
    }
    uVar3 = uVar1 & 0x1f;
    uVar2 = uVar2 + (uVar1 >> 5) * 4;
  }
  *param_1 = uVar3;
  param_1[1] = uVar2;
  return;
}


// ==== FUN_00776280 @ 0x00776280 ====

void FUN_00776280(uint param_1,uint *param_2,uint param_3,uint *param_4,char *param_5)

{
  uint uVar1;
  
  while ((param_2 != param_4 || (param_1 != param_3))) {
    uVar1 = 1 << ((byte)param_1 & 0x1f);
    if (*param_5 == '\0') {
      *param_2 = *param_2 & ~uVar1;
    }
    else {
      *param_2 = *param_2 | uVar1;
    }
    if (param_1 < 0x1f) {
      param_1 = param_1 + 1;
    }
    else {
      param_1 = 0;
      param_2 = param_2 + 1;
    }
  }
  return;
}


// ==== FUN_007762d0 @ 0x007762d0 ====

void FUN_007762d0(int *param_1,int param_2,uint *param_3,int param_4,uint *param_5,int param_6,
                 uint *param_7)

{
  while ((param_3 != param_5 || (param_2 != param_4))) {
    if (param_4 == 0) {
      param_5 = param_5 + -1;
      param_4 = 0x1f;
    }
    else {
      param_4 = param_4 + -1;
    }
    if (param_6 == 0) {
      param_6 = 0x1f;
      param_7 = param_7 + -1;
    }
    else {
      param_6 = param_6 + -1;
    }
    if ((*param_5 & 1 << ((byte)param_4 & 0x1f)) == 0) {
      *param_7 = *param_7 & ~(1 << ((byte)param_6 & 0x1f));
    }
    else {
      *param_7 = *param_7 | 1 << ((byte)param_6 & 0x1f);
    }
  }
  param_1[1] = (int)param_7;
  *param_1 = param_6;
  return;
}


// ==== FUN_00776350 @ 0x00776350 ====

undefined4
FUN_00776350(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  FUN_007762d0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_1);
  return param_1;
}


// ==== FUN_00776390 @ 0x00776390 ====

void FUN_00776390(void)

{
  byte bVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  
  uVar2 = 0;
  if (*(int *)(in_ECX + 4) != 0) {
    do {
      if (((int)uVar2 < 0) && (uVar2 != 0)) {
        iVar3 = (-uVar2 - 1 >> 5) * -4 + -4;
      }
      else {
        iVar3 = (uVar2 >> 5) * 4;
      }
      puVar4 = (uint *)(*(int *)(in_ECX + 0xc) + iVar3);
      bVar1 = (byte)uVar2;
      uVar2 = uVar2 + 1;
      *puVar4 = *puVar4 & ~(1 << (bVar1 & 0x1f));
    } while (uVar2 < *(uint *)(in_ECX + 4));
  }
  return;
}


// ==== FUN_00776400 @ 0x00776400 ====

void FUN_00776400(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5968;
  DAT_00b5af2c = 0;
  in_ECX[1] = 0;
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009f5950;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00776440 @ 0x00776440 ====

void FUN_00776440(int param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined1 local_30 [8];
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996760;
  local_c = ExceptionList;
  if (param_1 < 9) {
    ExceptionList = &local_c;
    puVar2 = (undefined4 *)FUN_00776140(local_30,param_1);
    if ((*(uint *)puVar2[1] & 1 << ((byte)*puVar2 & 0x1f)) == 0) {
      puVar2 = (undefined4 *)FUN_00776140(local_30,param_1);
      *(uint *)puVar2[1] = *(uint *)puVar2[1] | 1 << ((byte)*puVar2 & 0x1f);
    }
    else {
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      FUN_00401740(&DAT_009f58cc,0x1d);
      local_4 = 1;
      FUN_00796d50(local_28);
      if (0xf < local_10) {
        _free(local_24);
        return;
      }
    }
    ExceptionList = local_c;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_type_<_E_TYPE::TYPE::__MAX___009f58ac,0x1c);
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


// ==== FUN_00776580 @ 0x00776580 ====

void FUN_00776580(int param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined1 local_30 [8];
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099677a;
  local_c = ExceptionList;
  if (param_1 < 9) {
    ExceptionList = &local_c;
    puVar2 = (undefined4 *)FUN_00776140(local_30,param_1);
    if ((*(uint *)puVar2[1] & 1 << ((byte)*puVar2 & 0x1f)) == 0) {
      local_10 = 0xf;
      local_14 = 0;
      local_24 = (void *)((uint)local_24 & 0xffffff00);
      FUN_00401740(&DAT_009f590c,0x1f);
      local_4 = 1;
      FUN_00796d50(local_28);
      if (0xf < local_10) {
        _free(local_24);
        return;
      }
    }
    else {
      puVar2 = (undefined4 *)FUN_00776140(local_30,param_1);
      *(uint *)puVar2[1] = *(uint *)puVar2[1] & ~(1 << ((byte)*puVar2 & 0x1f));
    }
    ExceptionList = local_c;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_type_<_E_TYPE::TYPE::__MAX___009f58ec,0x1c);
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


// ==== FUN_007766c0 @ 0x007766c0 ====

uint FUN_007766c0(int param_1)

{
  code *pcVar1;
  uint extraout_EAX;
  uint uVar2;
  undefined4 *puVar3;
  undefined1 local_30 [8];
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099678c;
  local_c = ExceptionList;
  if (param_1 < 9) {
    ExceptionList = &local_c;
    puVar3 = (undefined4 *)FUN_00776140(local_30,param_1);
    ExceptionList = local_c;
    return (uint)((1 << ((byte)*puVar3 & 0x1f) & *(uint *)puVar3[1]) != 0);
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_type_<_E_TYPE::TYPE::__MAX___009f592c,0x1c);
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


// ==== FUN_00776770 @ 0x00776770 ====

void FUN_00776770(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [8];
  undefined1 local_14 [8];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009967a9;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f5968;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  local_4 = 1;
  puVar1 = (undefined4 *)FUN_00776220(local_1c);
  FUN_00776960(local_14,0,0,*puVar1,puVar1[1]);
  FUN_00776ae0(0,in_ECX[3],9,0);
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5af2c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5af2c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00776820 @ 0x00776820 ====

void FUN_00776820(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00776850 @ 0x00776850 ====

void FUN_00776850(byte param_1)

{
  void *in_ECX;
  
  FUN_00776400();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00776870 @ 0x00776870 ====

void FUN_00776870(void)

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
  puStack_8 = &LAB_009967c8;
  pvStack_c = ExceptionList;
  local_38 = 0xf;
  local_3c = 0;
  local_4c = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_vector<bool>_too_long_009f597c,0x15);
  local_4 = 0;
  FUN_00403770(local_50);
  local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_34,&DAT_00a9c48c);
}


// ==== FUN_007768e0 @ 0x007768e0 ====

/* WARNING: Removing unreachable block (ram,0x007768ed) */

void FUN_007768e0(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  void *pvVar3;
  uint *in_ECX;
  uint uVar4;
  
  uVar2 = in_ECX[2];
  uVar4 = param_1 + 0x1f >> 5;
  if ((uVar2 != 0) && (uVar4 < (uint)((int)(in_ECX[3] - uVar2) >> 2))) {
    pvVar3 = (void *)(uVar2 + uVar4 * 4);
    if (pvVar3 != (void *)in_ECX[3]) {
      pvVar3 = _memmove(pvVar3,(void *)in_ECX[3],0);
      in_ECX[3] = (uint)pvVar3;
    }
  }
  *in_ECX = param_1;
  if ((param_1 & 0x1f) != 0) {
    puVar1 = (uint *)((in_ECX[2] - 4) + uVar4 * 4);
    *puVar1 = *puVar1 & (1 << (sbyte)(param_1 & 0x1f)) - 1U;
  }
  return;
}


// ==== FUN_00776960 @ 0x00776960 ====

undefined4 FUN_00776960(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_8 [8];
  
  iVar1 = *(int *)(in_ECX + 8);
  puVar2 = (undefined4 *)FUN_00776220(local_8);
  FUN_007761a0(&param_4,param_4,param_5,*puVar2,puVar2[1],param_2,param_3,param_1);
  FUN_007768e0((param_5 - *(int *)(in_ECX + 8) >> 2) * 0x20 + param_4);
  param_5 = *(undefined4 *)(in_ECX + 8);
  param_4 = 0;
  FUN_00776140(param_1,(param_3 - iVar1 >> 2) * 0x20 + param_2);
  return param_1;
}


// ==== FUN_00776a00 @ 0x00776a00 ====

int FUN_00776a00(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint *in_ECX;
  int iVar5;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined1 auStack_10 [8];
  undefined1 auStack_8 [8];
  
  uVar1 = param_3;
  iVar5 = ((int)(param_2 - in_ECX[2]) >> 2) * 0x20 + param_1;
  if (param_3 != 0) {
    uVar2 = *in_ECX;
    if (-uVar2 - 1 < param_3) {
      uVar2 = FUN_00776870();
    }
    FUN_00446090(uVar2 + 0x1f + uVar1 >> 5,0);
    uVar2 = *in_ECX;
    if (uVar2 == 0) {
      *in_ECX = uVar1;
      return iVar5;
    }
    FUN_00776220(&uStack_18);
    param_2 = in_ECX[2];
    *in_ECX = uVar2 + uVar1;
    param_1 = 0;
    puVar3 = (undefined4 *)FUN_00776220(auStack_10);
    puVar4 = (undefined4 *)FUN_00776140(auStack_8,iVar5);
    FUN_00776350(&param_1,*puVar4,puVar4[1],uStack_18,uStack_14,*puVar3,puVar3[1]);
  }
  return iVar5;
}


// ==== FUN_00776ae0 @ 0x00776ae0 ====

void FUN_00776ae0(undefined4 param_1,undefined4 param_2,int param_3,undefined1 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  iVar1 = param_3;
  iVar2 = FUN_00776a00(param_1,param_2,param_3);
  param_2 = *(undefined4 *)(in_ECX + 8);
  param_1 = 0;
  puVar3 = (undefined4 *)FUN_00776140(local_8,iVar2 + iVar1);
  puVar4 = (undefined4 *)FUN_00776140(&param_1,iVar2);
  FUN_00776280(*puVar4,puVar4[1],*puVar3,puVar3[1],&param_4);
  return;
}


// ==== FUN_00776b60 @ 0x00776b60 ====

void FUN_00776b60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f59d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00776b90 @ 0x00776b90 ====

void FUN_00776b90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f59e4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ac44 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac44 = in_ECX;
  return;
}


// ==== FUN_00776bc0 @ 0x00776bc0 ====

void FUN_00776bc0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ac44 = 0;
  *in_ECX = &PTR_FUN_009f59d8;
  return;
}


// ==== FUN_00776be0 @ 0x00776be0 ====

bool FUN_00776be0(undefined4 param_1)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5af28 + 4))(param_1);
  if (((((((cVar1 == '\0') && (cVar1 = (**(code **)(*DAT_00b5a7b0 + 4))(param_1), cVar1 == '\0')) &&
         (cVar1 = (**(code **)(*DAT_00b5a7b4 + 0x60))(param_1), cVar1 == '\0')) &&
        ((((cVar1 = (**(code **)(*DAT_00b5ac34 + 4))(param_1), cVar1 == '\0' &&
           (cVar1 = (**(code **)(*DAT_00b5ac38 + 0x40))(param_1), cVar1 == '\0')) &&
          ((cVar1 = (**(code **)(*DAT_00b5aeac + 4))(param_1), cVar1 == '\0' &&
           ((cVar1 = (**(code **)(*DAT_00b5aed8 + 4))(param_1), cVar1 == '\0' &&
            (cVar1 = (**(code **)(*DAT_00b5aed4 + 4))(param_1), cVar1 == '\0')))))) &&
         (cVar1 = (**(code **)(*DAT_00b5aed0 + 4))(param_1), cVar1 == '\0')))) &&
       (((((((cVar1 = (**(code **)(*DAT_00b5aec8 + 4))(param_1), cVar1 == '\0' &&
             (cVar1 = (**(code **)(*DAT_00b5aecc + 4))(param_1), cVar1 == '\0')) &&
            (cVar1 = (**(code **)(*DAT_00b5aec0 + 4))(param_1), cVar1 == '\0')) &&
           ((cVar1 = (**(code **)(*DAT_00b5aec4 + 4))(param_1), cVar1 == '\0' &&
            (cVar1 = (**(code **)(*DAT_00b5aeb0 + 4))(param_1), cVar1 == '\0')))) &&
          ((cVar1 = (**(code **)(*DAT_00b5aedc + 4))(param_1), cVar1 == '\0' &&
           ((cVar1 = (**(code **)(*DAT_00b5aee0 + 4))(param_1), cVar1 == '\0' &&
            (cVar1 = (**(code **)(*DAT_00b5aeb4 + 4))(param_1), cVar1 == '\0')))))) &&
         (cVar1 = (**(code **)(*DAT_00b5aea8 + 4))(param_1), cVar1 == '\0')) &&
        ((((((cVar1 = (**(code **)(*DAT_00b5aeb8 + 4))(param_1), cVar1 == '\0' &&
             (cVar1 = (**(code **)(*DAT_00b5aebc + 4))(param_1), cVar1 == '\0')) &&
            (cVar1 = (**(code **)(*DAT_00b5aee4 + 0x14))(param_1), cVar1 == '\0')) &&
           ((cVar1 = (**(code **)(*DAT_00b5ad0c + 0x24))(param_1), cVar1 == '\0' &&
            (cVar1 = (**(code **)(*DAT_00b5ad08 + 4))(param_1), cVar1 == '\0')))) &&
          ((cVar1 = (**(code **)(*DAT_00b5ad54 + 0x5c))(param_1), cVar1 == '\0' &&
           ((cVar1 = (**(code **)(*DAT_00b5ad50 + 4))(param_1), cVar1 == '\0' &&
            (cVar1 = (**(code **)(*DAT_00b5a9d8 + 4))(param_1), cVar1 == '\0')))))) &&
         ((cVar1 = (**(code **)(*DAT_00b5a9dc + 4))(param_1), cVar1 == '\0' &&
          (((cVar1 = (**(code **)(*DAT_00b5af00 + 0x14))(param_1), cVar1 == '\0' &&
            (cVar1 = (**(code **)(*DAT_00b5a788 + 4))(param_1), cVar1 == '\0')) &&
           (cVar1 = (**(code **)(*DAT_00b5a78c + 0x70))(param_1), cVar1 == '\0')))))))))) &&
      ((((cVar1 = (**(code **)(*DAT_00b5b110 + 4))(param_1), cVar1 == '\0' &&
         (cVar1 = (**(code **)(*DAT_00b5b114 + 4))(param_1), cVar1 == '\0')) &&
        ((cVar1 = (**(code **)(*DAT_00b5aef0 + 4))(param_1), cVar1 == '\0' &&
         ((cVar1 = (**(code **)(*DAT_00b5aef4 + 0x48))(param_1), cVar1 == '\0' &&
          (cVar1 = (**(code **)(*DAT_00b5ae74 + 4))(param_1), cVar1 == '\0')))))) &&
       (cVar1 = (**(code **)(*DAT_00b5ae7c + 4))(param_1), cVar1 == '\0')))) &&
     (((cVar1 = (**(code **)(*DAT_00b5ae20 + 4))(param_1), cVar1 == '\0' &&
       (cVar1 = (**(code **)(*DAT_00b5ae1c + 4))(param_1), cVar1 == '\0')) &&
      (cVar1 = (**(code **)(*DAT_00b5b124 + 4))(param_1), cVar1 == '\0')))) {
    if ((DAT_00b5acbc != (int *)0x0) &&
       (cVar1 = (**(code **)(*DAT_00b5acbc + 4))(param_1), cVar1 != '\0')) {
      return true;
    }
    if ((DAT_00b5acb8 != (int *)0x0) &&
       (cVar1 = (**(code **)(*DAT_00b5acb8 + 4))(param_1), cVar1 != '\0')) {
      return true;
    }
    cVar1 = (**(code **)(*DAT_00b5acc0 + 4))(param_1);
    if (((((((cVar1 == '\0') && (cVar1 = (**(code **)(*DAT_00b5ae9c + 4))(param_1), cVar1 == '\0'))
           && (cVar1 = (**(code **)(*DAT_00b5ae98 + 0x24))(param_1), cVar1 == '\0')) &&
          ((cVar1 = (**(code **)(*DAT_00b5ae80 + 4))(param_1), cVar1 == '\0' &&
           (cVar1 = (**(code **)(*DAT_00b5ae84 + 8))(param_1), cVar1 == '\0')))) &&
         (((cVar1 = (**(code **)(*DAT_00b5b148 + 4))(param_1), cVar1 == '\0' &&
           ((cVar1 = (**(code **)(*DAT_00b5b14c + 4))(param_1), cVar1 == '\0' &&
            (cVar1 = (**(code **)(*DAT_00b5ae2c + 4))(param_1), cVar1 == '\0')))) &&
          (cVar1 = (**(code **)(*DAT_00b5ae30 + 4))(param_1), cVar1 == '\0')))) &&
        ((((cVar1 = (**(code **)(*DAT_00b5ae94 + 4))(param_1), cVar1 == '\0' &&
           (cVar1 = (**(code **)(*DAT_00b5adbc + 4))(param_1), cVar1 == '\0')) &&
          (cVar1 = (**(code **)(*DAT_00b5adb8 + 4))(param_1), cVar1 == '\0')) &&
         (((cVar1 = (**(code **)(*DAT_00b5add0 + 4))(param_1), cVar1 == '\0' &&
           (cVar1 = (**(code **)(*DAT_00b5add4 + 4))(param_1), cVar1 == '\0')) &&
          ((cVar1 = (**(code **)(*DAT_00b5ae8c + 4))(param_1), cVar1 == '\0' &&
           ((cVar1 = (**(code **)(*DAT_00b5ae90 + 4))(param_1), cVar1 == '\0' &&
            (cVar1 = (**(code **)(*DAT_00b5ae88 + 4))(param_1), cVar1 == '\0')))))))))) &&
       ((((cVar1 = (**(code **)(*DAT_00b5adc4 + 4))(param_1), cVar1 == '\0' &&
          (((cVar1 = (**(code **)(*DAT_00b5b104 + 4))(param_1), cVar1 == '\0' &&
            (cVar1 = (**(code **)(*DAT_00b5aca4 + 4))(param_1), cVar1 == '\0')) &&
           (cVar1 = (**(code **)(*DAT_00b5aca8 + 8))(param_1), cVar1 == '\0')))) &&
         (((cVar1 = (**(code **)(*DAT_00b5b0f8 + 4))(param_1), cVar1 == '\0' &&
           (cVar1 = (**(code **)(*DAT_00b5b0fc + 4))(param_1), cVar1 == '\0')) &&
          ((cVar1 = (**(code **)(*DAT_00b5b0e0 + 4))(param_1), cVar1 == '\0' &&
           ((cVar1 = (**(code **)(*DAT_00b5b0e4 + 4))(param_1), cVar1 == '\0' &&
            (cVar1 = (**(code **)(*DAT_00b5b0ec + 4))(param_1), cVar1 == '\0')))))))) &&
        ((cVar1 = (**(code **)(*DAT_00b5b0f0 + 4))(param_1), cVar1 == '\0' &&
         ((cVar1 = (**(code **)(*DAT_00b5acfc + 4))(param_1), cVar1 == '\0' &&
          (cVar1 = (**(code **)(*DAT_00b5ad04 + 0x1c))(param_1), cVar1 == '\0')))))))) {
      if ((DAT_00b5ae0c != (int *)0x0) &&
         (cVar1 = (**(code **)(*DAT_00b5ae0c + 4))(param_1), cVar1 != '\0')) {
        return true;
      }
      if ((DAT_00b5ae08 != (int *)0x0) &&
         (cVar1 = (**(code **)(*DAT_00b5ae08 + 4))(param_1), cVar1 != '\0')) {
        return true;
      }
      if ((DAT_00b5ae04 != (int *)0x0) &&
         (cVar1 = (**(code **)(*DAT_00b5ae04 + 4))(param_1), cVar1 != '\0')) {
        return true;
      }
      cVar1 = (**(code **)(*DAT_00b5ae38 + 4))(param_1);
      if ((((((((((cVar1 == '\0') &&
                 (cVar1 = (**(code **)(*DAT_00b5ae3c + 0x68))(param_1), cVar1 == '\0')) &&
                (cVar1 = (**(code **)(*DAT_00b5ae44 + 4))(param_1), cVar1 == '\0')) &&
               ((cVar1 = (**(code **)(*DAT_00b5ae48 + 4))(param_1), cVar1 == '\0' &&
                (cVar1 = (**(code **)(*DAT_00b5aeec + 4))(param_1), cVar1 == '\0')))) &&
              (cVar1 = (**(code **)(*DAT_00b5a9e8 + 4))(param_1), cVar1 == '\0')) &&
             (((cVar1 = (**(code **)(*DAT_00b5a9e4 + 0x10))(param_1), cVar1 == '\0' &&
               (cVar1 = (**(code **)(*DAT_00b5ad9c + 4))(param_1), cVar1 == '\0')) &&
              ((cVar1 = (**(code **)(*DAT_00b5ad90 + 4))(param_1), cVar1 == '\0' &&
               (((cVar1 = (**(code **)(*DAT_00b5ad94 + 4))(param_1), cVar1 == '\0' &&
                 (cVar1 = (**(code **)(*DAT_00b5b184 + 4))(param_1), cVar1 == '\0')) &&
                (cVar1 = (**(code **)(*DAT_00b5ae6c + 0x2c))(param_1), cVar1 == '\0')))))))) &&
            ((cVar1 = (**(code **)(*DAT_00b5b17c + 4))(param_1), cVar1 == '\0' &&
             (cVar1 = (**(code **)(*DAT_00b5ac90 + 4))(param_1), cVar1 == '\0')))) &&
           ((cVar1 = (**(code **)(*DAT_00b5ac94 + 0x68))(param_1), cVar1 == '\0' &&
            (((cVar1 = (**(code **)(*DAT_00b5ae68 + 4))(param_1), cVar1 == '\0' &&
              (cVar1 = (**(code **)(*DAT_00b5ae64 + 4))(param_1), cVar1 == '\0')) &&
             ((cVar1 = (**(code **)(*DAT_00b5ad8c + 4))(param_1), cVar1 == '\0' &&
              (((cVar1 = (**(code **)(*DAT_00b5ad84 + 4))(param_1), cVar1 == '\0' &&
                (cVar1 = (**(code **)(*DAT_00b5b138 + 4))(param_1), cVar1 == '\0')) &&
               (cVar1 = (**(code **)(*DAT_00b5b134 + 4))(param_1), cVar1 == '\0')))))))))) &&
          (((cVar1 = (**(code **)(*DAT_00b5b12c + 4))(param_1), cVar1 == '\0' &&
            (cVar1 = (**(code **)(*DAT_00b5b128 + 4))(param_1), cVar1 == '\0')) &&
           (cVar1 = (**(code **)(*DAT_00b5ae60 + 4))(param_1), cVar1 == '\0')))) &&
         (((cVar1 = (**(code **)(*DAT_00b5ae5c + 8))(param_1), cVar1 == '\0' &&
           (cVar1 = (**(code **)(*DAT_00b5b130 + 4))(param_1), cVar1 == '\0')) &&
          ((cVar1 = (**(code **)(*DAT_00b5ada0 + 4))(param_1), cVar1 == '\0' &&
           ((((cVar1 = (**(code **)(*DAT_00b5ada4 + 0x34))(param_1), cVar1 == '\0' &&
              (cVar1 = (**(code **)(*DAT_00b5a834 + 4))(param_1), cVar1 == '\0')) &&
             (cVar1 = (**(code **)(*DAT_00b5a830 + 4))(param_1), cVar1 == '\0')) &&
            (cVar1 = (**(code **)(*DAT_00b5b0c8 + 4))(param_1), cVar1 == '\0')))))))) {
        cVar1 = (**(code **)(*DAT_00b5b0cc + 4))(param_1);
        return cVar1 != '\0';
      }
    }
  }
  return true;
}


// ==== FUN_00777420 @ 0x00777420 ====

void FUN_00777420(byte param_1)

{
  void *in_ECX;
  
  FUN_00776bc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00777440 @ 0x00777440 ====

void FUN_00777440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5d10;
  return;
}


// ==== FUN_00777460 @ 0x00777460 ====

void FUN_00777460(void)

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
  puStack_8 = &LAB_009967e8;
  pvStack_c = ExceptionList;
  uStack_34 = (void *)0x280013;
  uStack_38 = 0;
  uStack_3c = 0x77748d;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x7774aa;
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
  uStack_60 = 0x77750a;
  _free(pvStack_4c);
  return;
}


// ==== FUN_00777520 @ 0x00777520 ====

/* WARNING: Removing unreachable block (ram,0x00777603) */

undefined4 FUN_00777520(int param_1)

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
  
  puStack_8 = &LAB_009967fa;
  local_c = ExceptionList;
  uVar1 = (undefined3)((uint)param_1 >> 8);
  local_4 = (undefined1 *)0x0;
  if (*(char *)(param_1 + 0x10) == '\0') {
    uStack_34 = 0;
    uStack_38 = 0x77756b;
    ExceptionList = &local_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x777578;
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
    uStack_38 = 0x7775bf;
    ExceptionList = &local_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x7775cc;
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


// ==== FUN_00777630 @ 0x00777630 ====

/* WARNING: Removing unreachable block (ram,0x00777713) */

undefined4 FUN_00777630(int param_1)

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
  
  puStack_8 = &LAB_0099680c;
  local_c = ExceptionList;
  uVar1 = (undefined3)((uint)param_1 >> 8);
  local_4 = (undefined1 *)0x0;
  if (*(char *)(param_1 + 0x10) == '\0') {
    uStack_34 = 0;
    uStack_38 = 0x77767b;
    ExceptionList = &local_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x777688;
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
    uStack_38 = 0x7776cf;
    ExceptionList = &local_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x7776dc;
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


// ==== FUN_00777740 @ 0x00777740 ====

void FUN_00777740(int param_1)

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
  
  puStack_8 = &LAB_0099681e;
  pvStack_c = ExceptionList;
  local_4 = (undefined1 *)0x0;
  if (*(char *)(param_1 + 0x10) == '\0') {
    uStack_30 = 0x280012;
    pvStack_34 = (void *)0x0;
    uStack_38 = 0x7777d3;
    ExceptionList = &pvStack_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x7777e0;
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
    uStack_38 = 0x777789;
    ExceptionList = &pvStack_c;
    uStack_40 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_38 = 0xffffffff;
    uStack_3c = 0;
    uStack_44 = 0x777796;
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


// ==== FUN_00777840 @ 0x00777840 ====

void FUN_00777840(void)

{
  undefined1 auStack_20 [28];
  
  FUN_00401740(s__d____d_009f5a28,7);
  FUN_00404230(auStack_20);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  return;
}


// ==== FUN_007778a0 @ 0x007778a0 ====

void FUN_007778a0(void)

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
  FUN_00401740(s_Reset_MaxPC_OK_009f5a30,0xe);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_007778e0 @ 0x007778e0 ====

void FUN_007778e0(void)

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
  FUN_00401740(s_Reset_Exp_Ratio_OK_009f5a40,0x12);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00777920 @ 0x00777920 ====

/* WARNING: Removing unreachable block (ram,0x007779b9) */

void FUN_00777920(int param_1)

{
  void *local_44 [5];
  uint uStack_30;
  void *pvStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996838;
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
    FUN_00401740(s_OK_Old__f__New__f__009f5a54,0x12);
    FUN_00404230(local_44);
    local_4 = 0;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
  }
  ExceptionList = pvStack_2c;
  return;
}


// ==== FUN_00777a50 @ 0x00777a50 ====

/* WARNING: Removing unreachable block (ram,0x00777ae9) */

void FUN_00777a50(int param_1)

{
  void *local_44 [5];
  uint uStack_30;
  void *pvStack_2c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996852;
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
    FUN_00401740(s_OK_Old__f__New__f__009f5a70,0x12);
    FUN_00404230(local_44);
    local_4 = 0;
    FUN_00401660();
    (**(code **)(*DAT_00b5ad0c + 0x28))();
  }
  ExceptionList = pvStack_2c;
  return;
}


// ==== FUN_00777b80 @ 0x00777b80 ====

void FUN_00777b80(int param_1)

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
  puStack_8 = &LAB_0099686c;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_MapMove_Succeeded_009f5a8c,0x11);
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
    FUN_00401740(s_MapMove_Failed_009f5aa0,0xe);
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


// ==== FUN_00777cd0 @ 0x00777cd0 ====

/* WARNING: Removing unreachable block (ram,0x00777d5b) */

void FUN_00777cd0(int param_1)

{
  void *local_44 [5];
  uint uStack_30;
  void *pvStack_2c;
  undefined1 local_28 [28];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996886;
  pvStack_c = ExceptionList;
  if (*(char *)(param_1 + 0x10) == '\0') {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_Reset_Monster_Succeeded_009f5ab0,0x17);
    FUN_00404230(local_44);
    local_4 = 0;
    FUN_00401660(local_44,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  else {
    ExceptionList = &pvStack_c;
    FUN_00401740(s_Reset_Monster_Failed_009f5ac8,0x14);
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


// ==== FUN_00777de0 @ 0x00777de0 ====

void FUN_00777de0(int param_1)

{
  undefined1 auStack_20 [20];
  undefined4 uStack_c;
  undefined4 *puStack_8;
  
  puStack_8 = (undefined4 *)0x777dec;
  puStack_8 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puStack_8 == (undefined4 *)0x0) {
    puStack_8 = (undefined4 *)0x0;
  }
  else {
    *puStack_8 = &PTR_FUN_009f5d18;
  }
  *(undefined1 *)(puStack_8 + 1) = *(undefined1 *)(param_1 + 0x10);
  uStack_c = 0x777e0a;
  FUN_00797a20();
  FUN_00401740(s_Debug_LevelUp__u_OK_009f5ae0,0x13);
  FUN_00404230(auStack_20);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  return;
}


// ==== FUN_00777e60 @ 0x00777e60 ====

void FUN_00777e60(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (*(char *)(param_1 + 0x11) == '\0') {
      FUN_00401740(s_Open_GuildWar_Teleport_Command_i_009f5b20,0x38);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      return;
    }
    uVar2 = 0x29;
    pcVar1 = s_Open_GuildWar_Teleport_Command_i_009f5af4;
  }
  else {
    uVar2 = 0x26;
    pcVar1 = s_Open_GuildWar_Teleport_Command_i_009f5b5c;
  }
  FUN_00401740(pcVar1,uVar2);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00777ee0 @ 0x00777ee0 ====

void FUN_00777ee0(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    if (*(char *)(param_1 + 0x11) != '\0') {
      FUN_00401740(s_Close_GuildWar_Teleport_Command_i_009f5b9c,0x3a);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      return;
    }
    uVar2 = 0x17;
    pcVar1 = s_Close_GuildWar_Teleport_009f5b84;
  }
  else {
    uVar2 = 0x27;
    pcVar1 = s_Close_GuildWar_Teleport_Command_i_009f5bd8;
  }
  FUN_00401740(pcVar1,uVar2);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00777f60 @ 0x00777f60 ====

void FUN_00777f60(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_00401740(s_ResetCoolTime_Command_is_Success_009f5c00,0x20);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_Close_GuildWar_Teleport_Command_i_009f5c24,0x27);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00777fc0 @ 0x00777fc0 ====

void FUN_00777fc0(int param_1)

{
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_00401740(s_PartyWar_Start_Succeeded_009f5c4c,0x18);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_PartyWar_Start_Failed_009f5c68,0x15);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00778020 @ 0x00778020 ====

void FUN_00778020(int param_1)

{
  if (*(int *)(param_1 + 0x10) == 0) {
    FUN_00401740(s_PartyWar_End_Succeeded_009f5c80,0x16);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_PartyWar_End_Failed_009f5c98,0x13);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00778080 @ 0x00778080 ====

void FUN_00778080(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_00401740(s_Create_Brick_Succeeded_009f5cac,0x16);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_Create_Brick_Failed_009f5cc4,0x13);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_007780e0 @ 0x007780e0 ====

void FUN_007780e0(int param_1)

{
  if (*(char *)(param_1 + 0x10) == '\0') {
    FUN_00401740(s_Destroy_Brick_Succeeded_009f5cd8,0x17);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    return;
  }
  FUN_00401740(s_Destroy_Brick_Failed_009f5cf0,0x14);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  return;
}


// ==== FUN_00778140 @ 0x00778140 ====

undefined4 FUN_00778140(int param_1)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = FUN_00424500();
  if (uVar2 < 0x7000024) {
    if (uVar2 == 0x7000023) {
      FUN_00777cd0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    switch(uVar2) {
    case 0x7000004:
      cVar1 = FUN_00777520(*(undefined4 *)(param_1 + 0xc));
      if (cVar1 != '\0') {
        return 1;
      }
      break;
    case 0x7000006:
      cVar1 = FUN_00777630(*(undefined4 *)(param_1 + 0xc));
      if (cVar1 != '\0') {
        return 1;
      }
      break;
    case 0x7000010:
      FUN_00777740(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x7000012:
      FUN_00777840(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x7000014:
      FUN_00777460(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x7000016:
      FUN_007778a0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x700001c:
      FUN_007778e0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x700001f:
      FUN_00777920(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x7000021:
      FUN_00777a50(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else if (uVar2 < 0x7000049) {
    if (uVar2 == 0x7000048) {
      FUN_00777fc0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    switch(uVar2) {
    case 0x7000025:
      FUN_00777b80(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x7000041:
      FUN_00777e60(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x7000043:
      FUN_00777ee0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    case 0x7000045:
      FUN_00777f60(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else if (uVar2 < 0x700004f) {
    if (uVar2 == 0x700004e) {
      FUN_007780e0(*(undefined4 *)(param_1 + 0xc));
      return 0;
    }
    if (uVar2 == 0x700004a) {
      FUN_00778020(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar2 == 0x700004c) {
      FUN_00778080(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else if (uVar2 == 0x8000006) {
    FUN_00777de0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
  return 0;
}


// ==== FUN_007783b0 @ 0x007783b0 ====

undefined4 FUN_007783b0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00778140(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007783e0 @ 0x007783e0 ====

undefined4 FUN_007783e0(void)

{
  return 0x50030001;
}


// ==== FUN_007783f0 @ 0x007783f0 ====

void FUN_007783f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f5d10;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00778410 @ 0x00778410 ====

void FUN_00778410(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f63ec;
  return;
}


// ==== FUN_00778420 @ 0x00778420 ====

void FUN_00778420(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f63ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00778440 @ 0x00778440 ====

undefined4 FUN_00778440(void)

{
  return 0x50060001;
}


// ==== FUN_00778490 @ 0x00778490 ====

undefined4 FUN_00778490(void)

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


// ==== FUN_007784d0 @ 0x007784d0 ====

undefined4 FUN_007784d0(void)

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


// ==== FUN_00778520 @ 0x00778520 ====

undefined4 FUN_00778520(void)

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


// ==== FUN_00778570 @ 0x00778570 ====

undefined4 FUN_00778570(void)

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


// ==== FUN_007785c0 @ 0x007785c0 ====

undefined4 FUN_007785c0(void)

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


// ==== FUN_00778610 @ 0x00778610 ====

void FUN_00778610(void)

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


// ==== FUN_007786a0 @ 0x007786a0 ====

undefined4 FUN_007786a0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009968a0;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae04;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 100))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(&DAT_009f6390,4);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae04 + 100))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007787f0 @ 0x007787f0 ====

undefined4 FUN_007787f0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009968ba;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae04;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x68))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(s_revive_009f6398,6);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae04 + 0x68))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00778940 @ 0x00778940 ====

undefined4 FUN_00778940(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009968d4;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae04;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x7c))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(&DAT_009f63a0,4);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae04 + 0x7c))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00778a90 @ 0x00778a90 ====

undefined4 FUN_00778a90(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009968ee;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae04;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x6c))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(&DAT_009f63a8,4);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae04 + 0x6c))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00778be0 @ 0x00778be0 ====

undefined4 FUN_00778be0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996908;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae04;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x70))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(&DAT_009f63b0,4);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae04 + 0x70))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00778d30 @ 0x00778d30 ====

undefined4 FUN_00778d30(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996922;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae04;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x74))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(s_chase_009f63b8,5);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae04 + 0x74))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00778e80 @ 0x00778e80 ====

undefined4 FUN_00778e80(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar3 = thunk_FUN_00796f50(iVar1);
      uStack_8 = 0;
      uVar4 = 0;
      if ((*(int *)(param_1 + 4) != 0) &&
         (1 < (uint)((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c))) {
        uStack_8 = 1;
        uVar5 = FUN_00405d30(1);
        uVar4 = thunk_FUN_00796f50(uVar5);
      }
      (**(code **)(*DAT_00b5ae04 + 8))(uVar3,uStack_8,uVar4);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00778f40 @ 0x00778f40 ====

undefined4 FUN_00778f40(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar3 = thunk_FUN_00796f80(iVar1);
      (**(code **)(*DAT_00b5ae04 + 0x10))(uVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00778fa0 @ 0x00778fa0 ====

undefined4 FUN_00778fa0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar3 = thunk_FUN_00796f80(iVar1);
      (**(code **)(*DAT_00b5ae04 + 0x14))(uVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00779000 @ 0x00779000 ====

undefined4 FUN_00779000(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar3 = thunk_FUN_00796f80(iVar1);
      (**(code **)(*DAT_00b5ae04 + 0x18))(uVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00779060 @ 0x00779060 ====

undefined4 FUN_00779060(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      (**(code **)(*DAT_00b5ae04 + 0x20))(iVar1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007790b0 @ 0x007790b0 ====

undefined4 FUN_007790b0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099693c;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae04;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x24))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(s_summon_009f63c0,6);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae04 + 0x24))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00779200 @ 0x00779200 ====

undefined4 FUN_00779200(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996956;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae04;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x28))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(s_return_009f63c8,6);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae04 + 0x28))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00779350 @ 0x00779350 ====

undefined4 FUN_00779350(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar2 = *DAT_00b5ae04;
      fVar3 = (float10)thunk_FUN_00796ec0(iVar1);
      (**(code **)(iVar2 + 0x2c))((float)fVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007793b0 @ 0x007793b0 ====

undefined4 FUN_007793b0(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar2 = *DAT_00b5ae04;
      fVar3 = (float10)thunk_FUN_00796ec0(iVar1);
      (**(code **)(iVar2 + 0x30))((float)fVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00779410 @ 0x00779410 ====

undefined4 FUN_00779410(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar2 = *DAT_00b5ae04;
      fVar3 = (float10)thunk_FUN_00796ec0(iVar1);
      (**(code **)(iVar2 + 0x34))((float)fVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00779470 @ 0x00779470 ====

/* WARNING: Removing unreachable block (ram,0x007794ba) */
/* WARNING: Removing unreachable block (ram,0x007794c6) */
/* WARNING: Removing unreachable block (ram,0x007794ad) */

undefined4 FUN_00779470(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 3)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae04;
  uVar3 = thunk_FUN_00796fb0(iVar1 + 0x38);
  uVar3 = thunk_FUN_00796fb0(iVar1 + 0x1c,uVar3);
  uVar3 = thunk_FUN_00796fb0(iVar1,uVar3);
  (**(code **)(iVar2 + 0x38))(uVar3);
  return 1;
}


// ==== FUN_00779500 @ 0x00779500 ====

/* WARNING: Removing unreachable block (ram,0x0077953b) */

undefined4 FUN_00779500(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae04;
  uVar3 = thunk_FUN_00796fb0(iVar1);
  (**(code **)(iVar2 + 0x40))(uVar3);
  return 1;
}


// ==== FUN_00779560 @ 0x00779560 ====

/* WARNING: Removing unreachable block (ram,0x00779595) */

undefined4 FUN_00779560(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),&DAT_009f63d0,2);
  (**(code **)(*DAT_00b5ae04 + 0x44))('\x02' - (iVar1 != 0));
  return 1;
}


// ==== FUN_007795d0 @ 0x007795d0 ====

/* WARNING: Removing unreachable block (ram,0x0077960b) */

undefined4 FUN_007795d0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae04;
  uVar3 = thunk_FUN_00796f80(iVar1,0);
  (**(code **)(iVar2 + 0x48))(uVar3);
  return 1;
}


// ==== FUN_00779630 @ 0x00779630 ====

undefined4 FUN_00779630(int param_1)

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


// ==== FUN_007796f0 @ 0x007796f0 ====

undefined4 FUN_007796f0(int param_1)

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


// ==== FUN_007797b0 @ 0x007797b0 ====

undefined4 FUN_007797b0(int param_1)

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


// ==== FUN_00779860 @ 0x00779860 ====

/* WARNING: Removing unreachable block (ram,0x0077989b) */

undefined4 FUN_00779860(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae04;
  uVar3 = thunk_FUN_00796f80(iVar1);
  (**(code **)(iVar2 + 0x4c))(uVar3);
  return 1;
}


// ==== FUN_007798c0 @ 0x007798c0 ====

/* WARNING: Removing unreachable block (ram,0x007798fb) */

undefined4 FUN_007798c0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae04;
  uVar3 = thunk_FUN_00796f80(iVar1);
  (**(code **)(iVar2 + 0x50))(uVar3);
  return 1;
}


// ==== FUN_00779920 @ 0x00779920 ====

/* WARNING: Removing unreachable block (ram,0x007799c5) */
/* WARNING: Removing unreachable block (ram,0x0077996d) */
/* WARNING: Removing unreachable block (ram,0x0077998a) */
/* WARNING: Removing unreachable block (ram,0x007799c3) */
/* WARNING: Removing unreachable block (ram,0x00779a06) */
/* WARNING: Removing unreachable block (ram,0x00779a13) */
/* WARNING: Removing unreachable block (ram,0x00779a19) */
/* WARNING: Removing unreachable block (ram,0x00779a39) */
/* WARNING: Removing unreachable block (ram,0x00779a9c) */
/* WARNING: Removing unreachable block (ram,0x00779a7f) */
/* WARNING: Removing unreachable block (ram,0x00779aa8) */
/* WARNING: Removing unreachable block (ram,0x00779b07) */
/* WARNING: Removing unreachable block (ram,0x00779b1d) */
/* WARNING: Removing unreachable block (ram,0x00779b2d) */
/* WARNING: Removing unreachable block (ram,0x00779b5c) */
/* WARNING: Removing unreachable block (ram,0x00779b8b) */
/* WARNING: Removing unreachable block (ram,0x00779bba) */
/* WARNING: Removing unreachable block (ram,0x00779bd0) */
/* WARNING: Removing unreachable block (ram,0x00779be0) */
/* WARNING: Removing unreachable block (ram,0x00779c0f) */
/* WARNING: Removing unreachable block (ram,0x00779c3f) */
/* WARNING: Removing unreachable block (ram,0x00779c6f) */
/* WARNING: Removing unreachable block (ram,0x00779c9e) */
/* WARNING: Removing unreachable block (ram,0x00779ccd) */
/* WARNING: Removing unreachable block (ram,0x00779cfc) */
/* WARNING: Removing unreachable block (ram,0x00779d2b) */
/* WARNING: Removing unreachable block (ram,0x00779d41) */
/* WARNING: Removing unreachable block (ram,0x00779d51) */
/* WARNING: Removing unreachable block (ram,0x00779d80) */
/* WARNING: Removing unreachable block (ram,0x00779daf) */
/* WARNING: Removing unreachable block (ram,0x00779dde) */
/* WARNING: Removing unreachable block (ram,0x00779e0d) */
/* WARNING: Removing unreachable block (ram,0x00779e3d) */
/* WARNING: Removing unreachable block (ram,0x00779e6d) */
/* WARNING: Removing unreachable block (ram,0x00779e9d) */
/* WARNING: Removing unreachable block (ram,0x00779ecd) */
/* WARNING: Removing unreachable block (ram,0x00779efd) */
/* WARNING: Removing unreachable block (ram,0x00779f2d) */
/* WARNING: Removing unreachable block (ram,0x00779f43) */
/* WARNING: Removing unreachable block (ram,0x00779f53) */
/* WARNING: Removing unreachable block (ram,0x00779f82) */
/* WARNING: Removing unreachable block (ram,0x00779fb1) */
/* WARNING: Removing unreachable block (ram,0x00779fe0) */
/* WARNING: Removing unreachable block (ram,0x0077a00f) */
/* WARNING: Removing unreachable block (ram,0x0077a03e) */
/* WARNING: Removing unreachable block (ram,0x0077a069) */
/* WARNING: Removing unreachable block (ram,0x0077a094) */
/* WARNING: Removing unreachable block (ram,0x0077a0bc) */
/* WARNING: Removing unreachable block (ram,0x0077a0d2) */
/* WARNING: Removing unreachable block (ram,0x0077a0aa) */
/* WARNING: Removing unreachable block (ram,0x0077a0ba) */
/* WARNING: Removing unreachable block (ram,0x0077a07f) */
/* WARNING: Removing unreachable block (ram,0x0077a08f) */
/* WARNING: Removing unreachable block (ram,0x0077a054) */
/* WARNING: Removing unreachable block (ram,0x0077a064) */
/* WARNING: Removing unreachable block (ram,0x0077a025) */
/* WARNING: Removing unreachable block (ram,0x0077a039) */
/* WARNING: Removing unreachable block (ram,0x00779ff6) */
/* WARNING: Removing unreachable block (ram,0x0077a00a) */
/* WARNING: Removing unreachable block (ram,0x00779fc7) */
/* WARNING: Removing unreachable block (ram,0x00779fdb) */
/* WARNING: Removing unreachable block (ram,0x00779f98) */
/* WARNING: Removing unreachable block (ram,0x00779fac) */
/* WARNING: Removing unreachable block (ram,0x00779f69) */
/* WARNING: Removing unreachable block (ram,0x00779f7d) */
/* WARNING: Removing unreachable block (ram,0x00779f13) */
/* WARNING: Removing unreachable block (ram,0x00779f28) */
/* WARNING: Removing unreachable block (ram,0x00779ee3) */
/* WARNING: Removing unreachable block (ram,0x00779ef8) */
/* WARNING: Removing unreachable block (ram,0x00779eb3) */
/* WARNING: Removing unreachable block (ram,0x00779ec8) */
/* WARNING: Removing unreachable block (ram,0x00779e83) */
/* WARNING: Removing unreachable block (ram,0x00779e98) */
/* WARNING: Removing unreachable block (ram,0x00779e53) */
/* WARNING: Removing unreachable block (ram,0x00779e68) */
/* WARNING: Removing unreachable block (ram,0x00779e23) */
/* WARNING: Removing unreachable block (ram,0x00779e38) */
/* WARNING: Removing unreachable block (ram,0x00779df4) */
/* WARNING: Removing unreachable block (ram,0x00779e08) */
/* WARNING: Removing unreachable block (ram,0x00779dc5) */
/* WARNING: Removing unreachable block (ram,0x00779dd9) */
/* WARNING: Removing unreachable block (ram,0x00779d96) */
/* WARNING: Removing unreachable block (ram,0x00779daa) */
/* WARNING: Removing unreachable block (ram,0x00779d67) */
/* WARNING: Removing unreachable block (ram,0x00779d7b) */
/* WARNING: Removing unreachable block (ram,0x00779d12) */
/* WARNING: Removing unreachable block (ram,0x00779d26) */
/* WARNING: Removing unreachable block (ram,0x00779ce3) */
/* WARNING: Removing unreachable block (ram,0x00779cf7) */
/* WARNING: Removing unreachable block (ram,0x00779cb4) */
/* WARNING: Removing unreachable block (ram,0x00779cc8) */
/* WARNING: Removing unreachable block (ram,0x00779c85) */
/* WARNING: Removing unreachable block (ram,0x00779c99) */
/* WARNING: Removing unreachable block (ram,0x00779c55) */
/* WARNING: Removing unreachable block (ram,0x00779c6a) */
/* WARNING: Removing unreachable block (ram,0x00779c25) */
/* WARNING: Removing unreachable block (ram,0x00779c3a) */
/* WARNING: Removing unreachable block (ram,0x00779bf6) */
/* WARNING: Removing unreachable block (ram,0x00779c0a) */
/* WARNING: Removing unreachable block (ram,0x00779ba1) */
/* WARNING: Removing unreachable block (ram,0x00779bb5) */
/* WARNING: Removing unreachable block (ram,0x00779b72) */
/* WARNING: Removing unreachable block (ram,0x00779b86) */
/* WARNING: Removing unreachable block (ram,0x00779b43) */
/* WARNING: Removing unreachable block (ram,0x00779b57) */
/* WARNING: Removing unreachable block (ram,0x00779aee) */
/* WARNING: Removing unreachable block (ram,0x00779b02) */
/* WARNING: Removing unreachable block (ram,0x0077a0e2) */
/* WARNING: Removing unreachable block (ram,0x0077a106) */
/* WARNING: Removing unreachable block (ram,0x0077a0fd) */
/* WARNING: Removing unreachable block (ram,0x0077a128) */

uint FUN_00779920(void)

{
  uint uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00996978;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  uVar1 = FUN_00405670();
  ExceptionList = local_c;
  return uVar1 & 0xffffff00;
}


// ==== FUN_0077a160 @ 0x0077a160 ====

void FUN_0077a160(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00996995;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f640c;
  local_4 = 1;
  FUN_00410b90(*(undefined4 *)(in_ECX[2] + 4));
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  in_ECX[3] = 0;
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  local_4 = local_4 & 0xffffff00;
  FUN_00410f60(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0077a200 @ 0x0077a200 ====

/* WARNING: Removing unreachable block (ram,0x0077aac8) */
/* WARNING: Removing unreachable block (ram,0x0077a8c8) */
/* WARNING: Removing unreachable block (ram,0x0077a9d7) */
/* WARNING: Removing unreachable block (ram,0x0077abb9) */
/* WARNING: Removing unreachable block (ram,0x0077a7d7) */

undefined4 FUN_0077a200(void)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  undefined4 extraout_EAX_07;
  undefined4 extraout_EAX_08;
  undefined4 extraout_EAX_09;
  undefined4 extraout_EAX_10;
  undefined4 uVar3;
  undefined4 extraout_EAX_11;
  undefined4 extraout_EAX_12;
  undefined4 extraout_EAX_13;
  undefined4 extraout_EAX_14;
  undefined4 extraout_EAX_15;
  undefined4 extraout_EAX_16;
  undefined4 extraout_EAX_17;
  undefined4 extraout_EAX_18;
  undefined4 extraout_EAX_19;
  undefined4 extraout_EAX_20;
  undefined4 extraout_EAX_21;
  undefined4 extraout_EAX_22;
  undefined4 extraout_EAX_23;
  undefined4 extraout_EAX_24;
  undefined4 extraout_EAX_25;
  undefined4 extraout_EAX_26;
  undefined4 extraout_EAX_27;
  undefined4 extraout_EAX_28;
  undefined4 extraout_EAX_29;
  undefined4 extraout_EAX_30;
  undefined4 extraout_EAX_31;
  undefined4 extraout_EAX_32;
  undefined4 extraout_EAX_33;
  undefined4 extraout_EAX_34;
  undefined4 extraout_EAX_35;
  undefined4 extraout_EAX_36;
  undefined4 extraout_EAX_37;
  undefined4 extraout_EAX_38;
  undefined4 extraout_EAX_39;
  undefined4 extraout_EAX_40;
  undefined4 extraout_EAX_41;
  undefined4 extraout_EAX_42;
  undefined4 extraout_EAX_43;
  undefined4 extraout_EAX_44;
  undefined4 extraout_EAX_45;
  undefined4 extraout_EAX_46;
  undefined4 extraout_EAX_47;
  undefined4 extraout_EAX_48;
  undefined4 extraout_EAX_49;
  undefined4 extraout_EAX_50;
  undefined4 extraout_EAX_51;
  undefined4 extraout_EAX_52;
  undefined4 extraout_EAX_53;
  undefined4 extraout_EAX_54;
  undefined4 extraout_EAX_55;
  undefined4 extraout_EAX_56;
  undefined4 extraout_EAX_57;
  undefined4 extraout_EAX_58;
  undefined4 extraout_EAX_59;
  undefined4 extraout_EAX_60;
  undefined4 extraout_EAX_61;
  undefined4 extraout_EAX_62;
  undefined4 extraout_EAX_63;
  undefined4 extraout_EAX_64;
  undefined4 extraout_EAX_65;
  undefined4 extraout_EAX_66;
  undefined4 extraout_EAX_67;
  undefined4 extraout_EAX_68;
  undefined4 extraout_EAX_69;
  undefined4 extraout_EAX_70;
  undefined4 extraout_EAX_71;
  undefined4 extraout_EAX_72;
  undefined4 extraout_EAX_73;
  undefined4 extraout_EAX_74;
  undefined4 extraout_EAX_75;
  undefined4 extraout_EAX_76;
  undefined4 extraout_EAX_77;
  undefined4 extraout_EAX_78;
  undefined4 extraout_EAX_79;
  undefined4 *in_ECX;
  uint unaff_EDI;
  undefined1 auStack_f6 [2];
  undefined4 uStack_e4;
  undefined1 *puStack_d8;
  void *pvStack_d0;
  void *pvStack_cc;
  uint uStack_c8;
  void *pvStack_c4;
  uint uStack_c0;
  void *pvStack_bc;
  uint uStack_b8;
  void *pvStack_b4;
  void *pvStack_b0;
  undefined4 uStack_ac;
  void *pvStack_a8;
  undefined4 uStack_a4;
  void *pvStack_a0;
  uint uStack_9c;
  void *pvStack_98;
  void *pvStack_94;
  void *pvStack_90;
  void *pvStack_8c;
  undefined4 uStack_88;
  void *pvStack_84;
  uint uStack_80;
  void *pvStack_7c;
  uint uStack_78;
  void *pvStack_74;
  uint auStack_70 [4];
  void *pvStack_60;
  undefined1 auStack_5c [8];
  undefined1 local_54 [8];
  uint local_4c [2];
  void *pvStack_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34;
  undefined1 local_30;
  undefined1 uStack_2c;
  undefined1 uStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  undefined1 auStack_8 [4];
  
  puStack_d8 = auStack_8 + 4;
  puStack_10 = &LAB_00996e03;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  *in_ECX = &PTR_FUN_009f640c;
  local_c = 0;
  uStack_e4 = 0x77a245;
  iVar2 = FUN_004105c0();
  in_ECX[2] = iVar2;
  *(undefined1 *)(iVar2 + 0x45) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  uStack_e4 = 9;
  local_c._0_1_ = 1;
  local_1c = 0xf;
  local_20 = 0;
  local_30 = 0;
  FUN_00401740();
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffffff00;
  uStack_e4 = 0x640001;
  local_c = CONCAT31(local_c._1_3_,3);
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  pvStack_a0 = (void *)0xf;
  uStack_a4 = 0;
  pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
  FUN_00401740();
  pvStack_14._0_1_ = 4;
  FUN_00405bd0();
  pvStack_14._0_1_ = 5;
  FUN_00410890();
  pvStack_14._0_1_ = 6;
  FUN_00411200();
  if (0xf < pvStack_60) {
    _free(pvStack_74);
    return extraout_EAX;
  }
  pvStack_60 = (void *)0xf;
  auStack_70[3] = 0;
  pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
  if (0xf < pvStack_7c) {
    _free(pvStack_90);
    return extraout_EAX_00;
  }
  pvStack_7c = (void *)0xf;
  uStack_80 = 0;
  pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
  if ((void *)0xf < pvStack_bc) {
    _free(pvStack_d0);
    return extraout_EAX_01;
  }
  pvStack_bc = (void *)0xf;
  uStack_c0 = 0;
  uVar1 = (uint)pvStack_d0 >> 8;
  pvStack_d0 = (void *)(uVar1 << 8);
  pvStack_14._0_1_ = 3;
  if (0xf < pvStack_a0) {
    _free(pvStack_b4);
    return extraout_EAX_02;
  }
  pvStack_bc = (void *)0xf;
  uStack_c0 = 0;
  pvStack_d0 = (void *)(uVar1 << 8);
  FUN_00401740();
  pvStack_14._0_1_ = 7;
  pvStack_a0 = (void *)0xf;
  uStack_a4 = 0;
  pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
  FUN_00401740();
  pvStack_14._0_1_ = 8;
  FUN_00410890();
  pvStack_14._0_1_ = 9;
  FUN_00411200();
  if (0xf < pvStack_60) {
    _free(pvStack_74);
    return extraout_EAX_03;
  }
  pvStack_60 = (void *)0xf;
  auStack_70[3] = 0;
  pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
  if (0xf < pvStack_7c) {
    _free(pvStack_90);
    return extraout_EAX_04;
  }
  pvStack_7c = (void *)0xf;
  uStack_80 = 0;
  pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
  if (0xf < pvStack_a0) {
    _free(pvStack_b4);
    return extraout_EAX_05;
  }
  pvStack_a0 = (void *)0xf;
  uStack_a4 = 0;
  pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
  pvStack_14 = (void *)CONCAT31(pvStack_14._1_3_,3);
  if ((void *)0xf < pvStack_bc) {
    _free(pvStack_d0);
    return extraout_EAX_06;
  }
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  pvStack_c4 = (void *)0xf;
  uStack_c8 = 0;
  puStack_d8 = (undefined1 *)((uint)puStack_d8 & 0xffffff00);
  FUN_00401740();
  local_1c._0_1_ = 10;
  FUN_00405bd0();
  local_1c._0_1_ = 0xb;
  FUN_00410890();
  local_1c._0_1_ = 0xc;
  FUN_00411200();
  if (0xf < auStack_70[2]) {
    _free(pvStack_7c);
    return extraout_EAX_07;
  }
  auStack_70[2] = 0xf;
  auStack_70[1] = 0;
  pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
  if (0xf < pvStack_84) {
    _free(pvStack_98);
    return extraout_EAX_08;
  }
  pvStack_84 = (void *)0xf;
  uStack_88 = 0;
  pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
  if (0xf < pvStack_a8) {
    _free(pvStack_bc);
    return extraout_EAX_09;
  }
  pvStack_a8 = (void *)0xf;
  uStack_ac = 0;
  pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
  local_1c = CONCAT31(local_1c._1_3_,3);
  if ((void *)0xf < pvStack_c4) {
    _free(puStack_d8);
    return extraout_EAX_10;
  }
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660(uVar3,0);
  pvStack_cc = (void *)0xf;
  pvStack_d0 = (void *)0x0;
  FUN_00401740(s_maxplayer_009f5da0);
  uStack_24 = 0xd;
  FUN_00405bd0(&uStack_c8,local_4c);
  uStack_24 = 0xe;
  FUN_00410890(&uStack_e4);
  uStack_24 = 0xf;
  FUN_00411200(&uStack_ac);
  if (0xf < auStack_70[0]) {
    _free(pvStack_84);
    return extraout_EAX_11;
  }
  auStack_70[0] = 0xf;
  pvStack_74 = (void *)0x0;
  pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
  if (0xf < pvStack_8c) {
    _free(pvStack_a0);
    return extraout_EAX_12;
  }
  pvStack_8c = (void *)0xf;
  pvStack_90 = (void *)0x0;
  pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
  if (0xf < pvStack_b0) {
    _free(pvStack_c4);
    return extraout_EAX_13;
  }
  pvStack_b0 = (void *)0xf;
  pvStack_b4 = (void *)0x0;
  pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
  uStack_24 = 3;
  if ((void *)0xf < pvStack_cc) {
    _free((void *)(unaff_EDI & 0xffffff00));
    return extraout_EAX_14;
  }
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
  FUN_00401660(uVar3,0,0xffffffff);
  puStack_d8 = (undefined1 *)0x0;
  FUN_00401740(s_regen_009f5dac,5);
  uStack_2c = 0x10;
  uVar3 = FUN_00405bd0(&pvStack_d0,local_54,auStack_70);
  uStack_2c = 0x11;
  uVar3 = FUN_00410890(auStack_f6 + 10,uVar3);
  uStack_2c = 0x12;
  FUN_00411200(&pvStack_b4,uVar3);
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return extraout_EAX_15;
  }
  uStack_78 = 0xf;
  pvStack_7c = (void *)0x0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  if (0xf < pvStack_94) {
    _free(pvStack_a8);
    return extraout_EAX_16;
  }
  pvStack_94 = (void *)0xf;
  pvStack_98 = (void *)0x0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < uStack_b8) {
    _free(pvStack_cc);
    return extraout_EAX_17;
  }
  uStack_b8 = 0xf;
  pvStack_bc = (void *)0x0;
  pvStack_cc = (void *)((uint)pvStack_cc & 0xffffff00);
  uStack_2c = 3;
  puStack_d8 = (undefined1 *)0x0;
  FUN_00401740(s__DEKARON_PLAYERCOUNT_009f5db4,0x14);
  uStack_2c = 0x13;
  uStack_b8 = 0xf;
  pvStack_bc = (void *)0x0;
  pvStack_cc = (void *)((uint)pvStack_cc & 0xffffff00);
  FUN_00401740(s_playercount_009f5dcc,0xb);
  uStack_2c = 0x14;
  uVar3 = FUN_00410890(&pvStack_d0,auStack_f6 + 10);
  uStack_2c = 0x15;
  FUN_00411200(&pvStack_b4,uVar3);
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return extraout_EAX_18;
  }
  uStack_78 = 0xf;
  pvStack_7c = (void *)0x0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  if (0xf < pvStack_94) {
    _free(pvStack_a8);
    return extraout_EAX_19;
  }
  pvStack_94 = (void *)0xf;
  pvStack_98 = (void *)0x0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < uStack_b8) {
    _free(pvStack_cc);
    return extraout_EAX_20;
  }
  uStack_b8 = 0xf;
  pvStack_bc = (void *)0x0;
  pvStack_cc = (void *)((uint)pvStack_cc & 0xffffff00);
  uStack_2c = 3;
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x640005);
  FUN_00401660(uVar3,0,0xffffffff);
  FUN_00401740(s_notice_009f5dd8,6);
  local_34 = 0x16;
  uVar3 = FUN_00405bd0(&puStack_d8,auStack_5c,&uStack_78);
  local_34 = 0x17;
  uVar3 = FUN_00410890(auStack_f6 + 2,uVar3);
  local_34 = 0x18;
  FUN_00411200(&pvStack_bc,uVar3);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return extraout_EAX_21;
  }
  uStack_80 = 0xf;
  pvStack_84 = (void *)0x0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  if (0xf < uStack_9c) {
    _free(pvStack_b0);
    return extraout_EAX_22;
  }
  uStack_9c = 0xf;
  pvStack_a0 = (void *)0x0;
  pvStack_b0 = (void *)((uint)pvStack_b0 & 0xffffff00);
  if (0xf < uStack_c0) {
    _free((void *)0xf);
    return extraout_EAX_23;
  }
  uStack_c0 = 0xf;
  pvStack_c4 = (void *)0x0;
  local_34 = 3;
  FUN_00401740(s__DEKARON_SUMMON__PC_ID__009f5de0,0x17);
  local_34 = 0x19;
  uStack_c0 = 0xf;
  pvStack_c4 = (void *)0x0;
  FUN_00401740(s_summon_009f5df8,6);
  local_34 = 0x1a;
  uVar3 = FUN_00410890(&puStack_d8,auStack_f6 + 2);
  local_34 = 0x1b;
  FUN_00411200(&pvStack_bc,uVar3);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return extraout_EAX_24;
  }
  uStack_80 = 0xf;
  pvStack_84 = (void *)0x0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  if (0xf < uStack_9c) {
    _free(pvStack_b0);
    return extraout_EAX_25;
  }
  uStack_9c = 0xf;
  pvStack_a0 = (void *)0x0;
  pvStack_b0 = (void *)((uint)pvStack_b0 & 0xffffff00);
  if (0xf < uStack_c0) {
    _free((void *)0x0);
    return extraout_EAX_26;
  }
  uStack_c0 = 0xf;
  pvStack_c4 = (void *)0x0;
  local_34 = 3;
  FUN_00401740(s__DEKARON_RETURN__PC_ID__009f5e00,0x17);
  local_34 = 0x1c;
  uStack_c0 = 0xf;
  pvStack_c4 = (void *)0x0;
  FUN_00401740(s_return_009f5e18,6);
  local_34 = 0x1d;
  uVar3 = FUN_00410890(&puStack_d8,auStack_f6 + 2);
  local_34 = 0x1e;
  FUN_00411200(&pvStack_bc,uVar3);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return extraout_EAX_27;
  }
  uStack_80 = 0xf;
  pvStack_84 = (void *)0x0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  if (0xf < uStack_9c) {
    _free(pvStack_b0);
    return extraout_EAX_28;
  }
  uStack_9c = 0xf;
  pvStack_a0 = (void *)0x0;
  pvStack_b0 = (void *)((uint)pvStack_b0 & 0xffffff00);
  if (0xf < uStack_c0) {
    _free((void *)0x0);
    return extraout_EAX_29;
  }
  uStack_c0 = 0xf;
  pvStack_c4 = (void *)0x0;
  local_34 = 3;
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x640006);
  FUN_00401660(uVar3,0,0xffffffff);
  FUN_00401830(s_expratio_009f5e20);
  local_3c._0_1_ = 0x1f;
  uVar3 = FUN_00405bd0(auStack_f6 + -6,auStack_70 + 3,&uStack_80);
  local_3c._0_1_ = 0x20;
  uVar3 = FUN_00410890(auStack_f6 + 0x16,uVar3);
  local_3c._0_1_ = 0x21;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_30;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_31;
  }
  FUN_00401830(s__DEKARON_ITEMDROPRATIO__ItemDrop_009f5e2c);
  local_3c._0_1_ = 0x22;
  FUN_00401830(s_itemdropratio_009f5e58);
  local_3c._0_1_ = 0x23;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x24;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_32;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_33;
  }
  FUN_00401830(s__DEKARON_MONEYDROPRATIO__MoneyDr_009f5e68);
  local_3c._0_1_ = 0x25;
  FUN_00401830(s_moneydropratio_009f5e98);
  local_3c._0_1_ = 0x26;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x27;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_34;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_35;
  }
  FUN_00401830(s__DEKARON_MOVEMAP__MAPINDEX___X____009f5ea8);
  local_3c._0_1_ = 0x28;
  FUN_00401830(s_movemap_009f5ecc);
  local_3c._0_1_ = 0x29;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x2a;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_36;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_37;
  }
  FUN_00401830(s__DEKARON_RESET_ALLMONSTER_009f5ed4);
  local_3c._0_1_ = 0x2b;
  FUN_00401830(s_reset_allmonster_009f5ef0);
  local_3c._0_1_ = 0x2c;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x2d;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_38;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_39;
  }
  FUN_00401830(s__DEKARON_RESETMONSTER__MONSTERIN_009f5f04);
  local_3c._0_1_ = 0x2e;
  FUN_00401830(s_resetmonster_009f5f28);
  local_3c._0_1_ = 0x2f;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x30;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_40;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_41;
  }
  FUN_00401830(s__DEKARON_ghostmode__on_off__009f5f38);
  local_3c._0_1_ = 0x31;
  FUN_00401830(s_ghostmode_009f5f54);
  local_3c._0_1_ = 0x32;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x33;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_42;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_43;
  }
  FUN_00401830(s__DEKARON_callmonster__MonsterInd_009f5f60);
  local_3c._0_1_ = 0x34;
  FUN_00401830(s_callmonster_009f5f84);
  local_3c._0_1_ = 0x35;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x36;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_44;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_45;
  }
  FUN_00401830(s__DEKARON_OPENCONSOLE_009f5f90);
  local_3c._0_1_ = 0x37;
  FUN_00401830(s_openconsole_009f5fa8);
  local_3c._0_1_ = 0x38;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x39;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_46;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_47;
  }
  FUN_00401830(s__DEKARON_call__PC_ID__009f5fb4);
  local_3c._0_1_ = 0x3a;
  FUN_00401830(&DAT_009f5fcc);
  local_3c._0_1_ = 0x3b;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x3c;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_48;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_49;
  }
  FUN_00401830(s__DEKARON_revive__PC_ID__009f5fd4);
  local_3c._0_1_ = 0x3d;
  FUN_00401830(s_revive_009f5fec);
  local_3c._0_1_ = 0x3e;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x3f;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_50;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_51;
  }
  FUN_00401830(s__DEKARON_heal__PC_ID__009f5ff4);
  local_3c._0_1_ = 0x40;
  FUN_00401830(&DAT_009f600c);
  local_3c._0_1_ = 0x41;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x42;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_52;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_53;
  }
  FUN_00401830(s__DEKARON_find__PC_ID__009f6014);
  local_3c._0_1_ = 0x43;
  FUN_00401830(&DAT_009f602c);
  local_3c._0_1_ = 0x44;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x45;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_54;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_55;
  }
  FUN_00401830(s__DEKARON_chase__PC_ID__009f6034);
  local_3c._0_1_ = 0x46;
  FUN_00401830(s_chase_009f604c);
  local_3c._0_1_ = 0x47;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x48;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_56;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_57;
  }
  FUN_00401830(s__DEKARON_dummycount_009f6054);
  local_3c._0_1_ = 0x49;
  FUN_00401830(s_dummycount_009f6068);
  local_3c._0_1_ = 0x4a;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x4b;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_58;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_59;
  }
  FUN_00401830(s__DEKARON_guildwarstart__time__009f6074);
  local_3c._0_1_ = 0x4c;
  FUN_00401830(s_guildwarstart_009f6094);
  local_3c._0_1_ = 0x4d;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x4e;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_60;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_61;
  }
  FUN_00401830(s__DEKARON_guildwarend__time__009f60a4);
  local_3c._0_1_ = 0x4f;
  FUN_00401830(s_guildwarend_009f60c0);
  local_3c._0_1_ = 0x50;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x51;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_62;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_63;
  }
  FUN_00401830(s__DEKARON_open_teleport_009f60cc);
  local_3c._0_1_ = 0x52;
  FUN_00401830(s_open_teleport_009f60e4);
  local_3c._0_1_ = 0x53;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x54;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_64;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_65;
  }
  FUN_00401830(s__DEKARON_close_teleport_009f60f4);
  local_3c._0_1_ = 0x55;
  FUN_00401830(s_close_teleport_009f610c);
  local_3c._0_1_ = 0x56;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x57;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_66;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_67;
  }
  FUN_00401830(s__DEKARON_resetcooltime_009f611c);
  local_3c._0_1_ = 0x58;
  FUN_00401830(s_resetcooltime_009f6134);
  local_3c._0_1_ = 0x59;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x5a;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_68;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_69;
  }
  FUN_00401830(s__DEKARON_partywarstart__time__009f6144);
  local_3c._0_1_ = 0x5b;
  FUN_00401830(s_partywarstart_009f6164);
  local_3c._0_1_ = 0x5c;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x5d;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_70;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_71;
  }
  FUN_00401830(s__DEKARON_partywarend_009f6174);
  local_3c._0_1_ = 0x5e;
  FUN_00401830(s_partywarend_009f618c);
  local_3c._0_1_ = 0x5f;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x60;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_72;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_73;
  }
  FUN_00401830(s__DEKARON_createbrick__BrickID__009f6198);
  local_3c._0_1_ = 0x61;
  FUN_00401830(s_createbrick_009f61b8);
  local_3c._0_1_ = 0x62;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 99;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_74;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_75;
  }
  FUN_00401830(s__DEKARON_destroybrick__BrickID__009f61c4);
  local_3c._0_1_ = 100;
  FUN_00401830(s_destroybrick_009f61e4);
  local_3c._0_1_ = 0x65;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c = CONCAT31(local_3c._1_3_,0x66);
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_76;
  }
  uStack_e4 = 0xf;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_77;
  }
  if (0xf < auStack_70[2]) {
    _free(pvStack_7c);
    return extraout_EAX_78;
  }
  auStack_70[2] = 0xf;
  auStack_70[1] = 0;
  pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
  if (local_4c[0] < 0x10) {
    ExceptionList = pvStack_44;
    return pvStack_84;
  }
  _free(pvStack_60);
  return extraout_EAX_79;
}


// ==== FUN_0077ba80 @ 0x0077ba80 ====

void FUN_0077ba80(byte param_1)

{
  FUN_0073e550();
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_0077bab0 @ 0x0077bab0 ====

void FUN_0077bab0(byte param_1)

{
  void *in_ECX;
  
  FUN_0077a160();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0077bb90 @ 0x0077bb90 ====

undefined4 FUN_0077bb90(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar3 = thunk_FUN_00796f50(iVar1);
      uStack_8 = 0;
      uVar4 = 0;
      if ((*(int *)(param_1 + 4) != 0) &&
         (1 < (uint)((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c))) {
        uStack_8 = 1;
        uVar5 = FUN_00405d30(1);
        uVar4 = thunk_FUN_00796f50(uVar5);
      }
      (**(code **)(*DAT_00b5ae0c + 8))(uVar3,uStack_8,uVar4);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077bd70 @ 0x0077bd70 ====

undefined4 FUN_0077bd70(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      (**(code **)(*DAT_00b5ae0c + 0x20))(iVar1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077be10 @ 0x0077be10 ====

undefined4 FUN_0077be10(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996e20;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae0c;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x28))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(s_return_009f64f4,6);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae0c + 0x28))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077c080 @ 0x0077c080 ====

/* WARNING: Removing unreachable block (ram,0x0077c0ca) */
/* WARNING: Removing unreachable block (ram,0x0077c0d6) */
/* WARNING: Removing unreachable block (ram,0x0077c0bd) */

undefined4 FUN_0077c080(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 3)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae0c;
  uVar3 = thunk_FUN_00796fb0(iVar1 + 0x38);
  uVar3 = thunk_FUN_00796fb0(iVar1 + 0x1c,uVar3);
  uVar3 = thunk_FUN_00796fb0(iVar1,uVar3);
  (**(code **)(iVar2 + 0x38))(uVar3);
  return 1;
}


// ==== FUN_0077c170 @ 0x0077c170 ====

/* WARNING: Removing unreachable block (ram,0x0077c1a5) */

undefined4 FUN_0077c170(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),&DAT_009f64fc,2);
  (**(code **)(*DAT_00b5ae0c + 0x44))('\x02' - (iVar1 != 0));
  return 1;
}


// ==== FUN_0077c1e0 @ 0x0077c1e0 ====

/* WARNING: Removing unreachable block (ram,0x0077c287) */
/* WARNING: Removing unreachable block (ram,0x0077c231) */
/* WARNING: Removing unreachable block (ram,0x0077c250) */
/* WARNING: Removing unreachable block (ram,0x0077c285) */
/* WARNING: Removing unreachable block (ram,0x0077c2c8) */
/* WARNING: Removing unreachable block (ram,0x0077c2d5) */
/* WARNING: Removing unreachable block (ram,0x0077c2db) */
/* WARNING: Removing unreachable block (ram,0x0077c2fb) */
/* WARNING: Removing unreachable block (ram,0x0077c489) */
/* WARNING: Removing unreachable block (ram,0x0077c345) */
/* WARNING: Removing unreachable block (ram,0x0077c366) */
/* WARNING: Removing unreachable block (ram,0x0077c3c5) */
/* WARNING: Removing unreachable block (ram,0x0077c3f0) */
/* WARNING: Removing unreachable block (ram,0x0077c41d) */
/* WARNING: Removing unreachable block (ram,0x0077c433) */
/* WARNING: Removing unreachable block (ram,0x0077c406) */
/* WARNING: Removing unreachable block (ram,0x0077c41b) */
/* WARNING: Removing unreachable block (ram,0x0077c3db) */
/* WARNING: Removing unreachable block (ram,0x0077c3eb) */
/* WARNING: Removing unreachable block (ram,0x0077c3ac) */
/* WARNING: Removing unreachable block (ram,0x0077c3c0) */
/* WARNING: Removing unreachable block (ram,0x0077c443) */
/* WARNING: Removing unreachable block (ram,0x0077c45e) */
/* WARNING: Removing unreachable block (ram,0x0077c480) */

uint FUN_0077c1e0(void)

{
  uint uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00996e42;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  uVar1 = FUN_00405670();
  ExceptionList = local_c;
  return uVar1 & 0xffffff00;
}


// ==== FUN_0077c4b0 @ 0x0077c4b0 ====

void FUN_0077c4b0(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00996e54;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f6508;
  local_4 = 0;
  FUN_00410f60(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0077c530 @ 0x0077c530 ====

/* WARNING: Removing unreachable block (ram,0x0077c88c) */
/* WARNING: Removing unreachable block (ram,0x0077c7a1) */
/* WARNING: Removing unreachable block (ram,0x0077c977) */
/* WARNING: Removing unreachable block (ram,0x0077c6dd) */

undefined4 FUN_0077c530(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  undefined4 extraout_EAX_07;
  undefined4 extraout_EAX_08;
  undefined4 extraout_EAX_09;
  undefined4 extraout_EAX_10;
  undefined4 extraout_EAX_11;
  undefined4 extraout_EAX_12;
  undefined4 *in_ECX;
  undefined1 auStack_be [18];
  undefined1 auStack_ac [4];
  void *pvStack_a8;
  undefined4 uStack_98;
  uint uStack_94;
  void *pvStack_8c;
  undefined4 uStack_7c;
  uint uStack_78;
  void *pvStack_70;
  undefined4 uStack_60;
  uint uStack_5c;
  undefined4 uStack_58;
  undefined1 auStack_54 [8];
  undefined1 auStack_4c [4];
  void *pvStack_48;
  undefined1 local_40;
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 local_30;
  void *local_2c;
  undefined1 local_24;
  uint uStack_18;
  void *local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00996f05;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f6508;
  local_4 = 0;
  iVar1 = FUN_004105c0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x45) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_4._0_1_ = 2;
  local_2c = (void *)0xf;
  local_30 = 0;
  local_40 = 0;
  FUN_00401740(s__OPR_009f6450,5);
  local_4 = CONCAT31(local_4._1_3_,3);
  uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x640005);
  FUN_00401660(uVar2,0,0xffffffff);
  FUN_00401740(s_notice_009f6458,6);
  pvStack_c._0_1_ = 4;
  uVar2 = FUN_00405bd0(auStack_ac,auStack_4c,&local_30);
  pvStack_c._0_1_ = 5;
  uVar2 = FUN_00410890(auStack_be + -10,uVar2);
  pvStack_c._0_1_ = 6;
  FUN_00411200(auStack_54,uVar2);
  if (0xf < uStack_5c) {
    _free(pvStack_70);
    return extraout_EAX;
  }
  uStack_5c = 0xf;
  uStack_60 = 0;
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return extraout_EAX_00;
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return extraout_EAX_01;
  }
  pvStack_c._0_1_ = 3;
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  FUN_00401740(s__OPR_RETURN__PC_ID__009f6460,0x13);
  pvStack_c._0_1_ = 7;
  FUN_00401740(s_return_009f6474,6);
  pvStack_c._0_1_ = 8;
  uVar2 = FUN_00410890(auStack_be + -10,auStack_ac);
  pvStack_c._0_1_ = 9;
  FUN_00411200(auStack_54,uVar2);
  if (0xf < uStack_5c) {
    _free(pvStack_70);
    return extraout_EAX_02;
  }
  uStack_5c = 0xf;
  uStack_60 = 0;
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return extraout_EAX_03;
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  pvStack_c._0_1_ = 3;
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return extraout_EAX_04;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  FUN_00401740(s__OPR_MOVEMAP__MAPINDEX___X___Y__009f647c,0x1f);
  pvStack_c._0_1_ = 10;
  FUN_00401740(s_movemap_009f649c,7);
  pvStack_c._0_1_ = 0xb;
  uVar2 = FUN_00410890(auStack_be + -10,auStack_ac);
  pvStack_c._0_1_ = 0xc;
  FUN_00411200(auStack_54,uVar2);
  if (0xf < uStack_5c) {
    _free(pvStack_70);
    return extraout_EAX_05;
  }
  uStack_5c = 0xf;
  uStack_60 = 0;
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return extraout_EAX_06;
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  pvStack_c._0_1_ = 3;
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return extraout_EAX_07;
  }
  uStack_94 = 0xf;
  uStack_98 = 0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  FUN_00401740(s__OPR_ghostmode__on_off__009f64a4,0x17);
  pvStack_c._0_1_ = 0xd;
  FUN_00401740(s_ghostmode_009f64bc,9);
  pvStack_c._0_1_ = 0xe;
  uVar2 = FUN_00410890(auStack_be + -10,auStack_ac);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,0xf);
  FUN_00411200(auStack_54,uVar2);
  if (0xf < uStack_5c) {
    _free(pvStack_70);
    return extraout_EAX_08;
  }
  uStack_5c = 0xf;
  uStack_60 = 0;
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return extraout_EAX_09;
  }
  uStack_78 = 0xf;
  uStack_7c = 0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  if (0xf < uStack_94) {
    _free(pvStack_a8);
    return extraout_EAX_10;
  }
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return extraout_EAX_11;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  if (uStack_18 < 0x10) {
    ExceptionList = local_14;
    return uStack_58;
  }
  _free(local_2c);
  return extraout_EAX_12;
}


// ==== FUN_0077ca10 @ 0x0077ca10 ====

void FUN_0077ca10(byte param_1)

{
  void *in_ECX;
  
  FUN_0077c4b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0077ca80 @ 0x0077ca80 ====

undefined4 FUN_0077ca80(void)

{
  (**(code **)(*DAT_00b5ae0c + 0x80))();
  return 1;
}


// ==== FUN_0077caa0 @ 0x0077caa0 ====

undefined4 FUN_0077caa0(void)

{
  (**(code **)(*DAT_00b5ae0c + 0x84))();
  return 1;
}


// ==== FUN_0077cb70 @ 0x0077cb70 ====

bool FUN_0077cb70(int param_1)

{
  int in_ECX;
  
  FUN_00410820(&param_1,param_1);
  return param_1 != *(int *)(in_ECX + 8);
}


// ==== FUN_0077cba0 @ 0x0077cba0 ====

void FUN_0077cba0(void)

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


// ==== FUN_0077cc30 @ 0x0077cc30 ====

int FUN_0077cc30(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  FUN_00410820(&param_2,param_2);
  iVar1 = *(int *)(in_ECX + 8);
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined1 *)(param_1 + 4) = 0;
  if (param_2 == iVar1) {
    FUN_00401740(&DAT_009f6cfd,0);
    return param_1;
  }
  FUN_00401660(param_2 + 0x28,0,0xffffffff);
  return param_1;
}


// ==== FUN_0077cc90 @ 0x0077cc90 ====

undefined4 FUN_0077cc90(int param_1)

{
  int iVar1;
  int iVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  undefined4 uStack_8;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar3 = thunk_FUN_00796f50(iVar1);
      uStack_8 = 0;
      uVar4 = 0;
      if ((*(int *)(param_1 + 4) != 0) &&
         (1 < (uint)((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c))) {
        uStack_8 = 1;
        uVar5 = FUN_00405d30(1);
        uVar4 = thunk_FUN_00796f50(uVar5);
      }
      (**(code **)(*DAT_00b5ae0c + 8))(uVar3,uStack_8,uVar4);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077cd50 @ 0x0077cd50 ====

undefined4 FUN_0077cd50(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar3 = thunk_FUN_00796f80(iVar1);
      (**(code **)(*DAT_00b5ae0c + 0x10))(uVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077cdb0 @ 0x0077cdb0 ====

undefined4 FUN_0077cdb0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar3 = thunk_FUN_00796f80(iVar1);
      (**(code **)(*DAT_00b5ae0c + 0x14))(uVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077ce10 @ 0x0077ce10 ====

undefined4 FUN_0077ce10(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      uVar3 = thunk_FUN_00796f80(iVar1);
      (**(code **)(*DAT_00b5ae0c + 0x18))(uVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077ce70 @ 0x0077ce70 ====

undefined4 FUN_0077ce70(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      (**(code **)(*DAT_00b5ae0c + 0x20))(iVar1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077cec0 @ 0x0077cec0 ====

undefined4 FUN_0077cec0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996f20;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae0c;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x24))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(s_summon_009f6d08,6);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae0c + 0x24))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077d010 @ 0x0077d010 ====

undefined4 FUN_0077d010(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996f3a;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae0c;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x28))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(s_return_009f6d10,6);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae0c + 0x28))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077d160 @ 0x0077d160 ====

undefined4 FUN_0077d160(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996f54;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae0c;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x54))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(&DAT_009f6d18,4);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae0c + 0x54))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077d2b0 @ 0x0077d2b0 ====

undefined4 FUN_0077d2b0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996f6e;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae0c;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x58))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(s_revive_009f6d20,6);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae0c + 0x58))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077d400 @ 0x0077d400 ====

undefined4 FUN_0077d400(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996f88;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae0c;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x50))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(&DAT_009f6d28,4);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae0c + 0x50))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077d550 @ 0x0077d550 ====

undefined4 FUN_0077d550(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996fa2;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae0c;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x5c))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(&DAT_009f6d30,4);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae0c + 0x5c))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077d6a0 @ 0x0077d6a0 ====

undefined4 FUN_0077d6a0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996fbc;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae0c;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x60))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(&DAT_009f6d38,4);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae0c + 0x60))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077d7f0 @ 0x0077d7f0 ====

undefined4 FUN_0077d7f0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996fd6;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae0c;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 100))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(s_chase_009f6d40,5);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae0c + 100))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077d940 @ 0x0077d940 ====

undefined4 FUN_0077d940(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar2 = *DAT_00b5ae0c;
      fVar3 = (float10)thunk_FUN_00796ec0(iVar1);
      (**(code **)(iVar2 + 0x2c))((float)fVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077d9a0 @ 0x0077d9a0 ====

undefined4 FUN_0077d9a0(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar2 = *DAT_00b5ae0c;
      fVar3 = (float10)thunk_FUN_00796ec0(iVar1);
      (**(code **)(iVar2 + 0x30))((float)fVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077da00 @ 0x0077da00 ====

undefined4 FUN_0077da00(int param_1)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar2 = (*(int *)(param_1 + 8) - iVar1) / 0x1c;
    if (iVar2 != 0) {
      if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      iVar2 = *DAT_00b5ae0c;
      fVar3 = (float10)thunk_FUN_00796ec0(iVar1);
      (**(code **)(iVar2 + 0x34))((float)fVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077da60 @ 0x0077da60 ====

/* WARNING: Removing unreachable block (ram,0x0077daaa) */
/* WARNING: Removing unreachable block (ram,0x0077dab6) */
/* WARNING: Removing unreachable block (ram,0x0077da9d) */

undefined4 FUN_0077da60(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 3)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae0c;
  uVar3 = thunk_FUN_00796fb0(iVar1 + 0x38);
  uVar3 = thunk_FUN_00796fb0(iVar1 + 0x1c,uVar3);
  uVar3 = thunk_FUN_00796fb0(iVar1,uVar3);
  (**(code **)(iVar2 + 0x38))(uVar3);
  return 1;
}


// ==== FUN_0077daf0 @ 0x0077daf0 ====

/* WARNING: Removing unreachable block (ram,0x0077db2b) */

undefined4 FUN_0077daf0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae0c;
  uVar3 = thunk_FUN_00796fb0(iVar1);
  (**(code **)(iVar2 + 0x40))(uVar3);
  return 1;
}


// ==== FUN_0077db50 @ 0x0077db50 ====

/* WARNING: Removing unreachable block (ram,0x0077db85) */

undefined4 FUN_0077db50(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),&DAT_009f6d48,2);
  (**(code **)(*DAT_00b5ae0c + 0x44))('\x02' - (iVar1 != 0));
  return 1;
}


// ==== FUN_0077dbc0 @ 0x0077dbc0 ====

/* WARNING: Removing unreachable block (ram,0x0077dbfa) */

undefined4 FUN_0077dbc0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  param_1 = 1;
  iVar1 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),&DAT_009f6d4c,2);
  if (iVar1 == 0) {
    param_1 = 3;
  }
  (**(code **)(*DAT_00b5ae0c + 0x44))(param_1);
  return 1;
}


// ==== FUN_0077dc40 @ 0x0077dc40 ====

/* WARNING: Removing unreachable block (ram,0x0077dc7b) */

undefined4 FUN_0077dc40(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae0c;
  uVar3 = thunk_FUN_00796f80(iVar1,0);
  (**(code **)(iVar2 + 0x48))(uVar3);
  return 1;
}


// ==== FUN_0077dca0 @ 0x0077dca0 ====

/* WARNING: Removing unreachable block (ram,0x0077dce8) */
/* WARNING: Removing unreachable block (ram,0x0077dcdc) */

undefined4 FUN_0077dca0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 2)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae0c;
  uVar3 = thunk_FUN_00796f80(iVar1 + 0x1c);
  uVar3 = thunk_FUN_00796f80(iVar1,uVar3);
  (**(code **)(iVar2 + 0x4c))(uVar3);
  return 1;
}


// ==== FUN_0077dd20 @ 0x0077dd20 ====

/* WARNING: Removing unreachable block (ram,0x0077dd5b) */

undefined4 FUN_0077dd20(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae0c;
  uVar3 = thunk_FUN_00796f80(iVar1);
  (**(code **)(iVar2 + 0x68))(uVar3);
  return 1;
}


// ==== FUN_0077dd80 @ 0x0077dd80 ====

/* WARNING: Removing unreachable block (ram,0x0077ddbb) */

undefined4 FUN_0077dd80(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae0c;
  uVar3 = thunk_FUN_00796f80(iVar1);
  (**(code **)(iVar2 + 0x6c))(uVar3);
  return 1;
}


// ==== FUN_0077dde0 @ 0x0077dde0 ====

/* WARNING: Removing unreachable block (ram,0x0077de3f) */

undefined4 FUN_0077dde0(int param_1)

{
  undefined4 extraout_EAX;
  void *unaff_EBX;
  uint unaff_ESI;
  undefined1 local_28 [12];
  undefined4 uStack_1c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00996fe8;
  local_c = ExceptionList;
  if ((*(int *)(param_1 + 4) == 0) || ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c != 1))
  {
    return 0;
  }
  ExceptionList = &local_c;
  FUN_00403620();
  if ((*(int *)(param_1 + 4) == 0) || ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c == 0))
  {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  FUN_00401740(s_Damage_Display__s_009f6d54,0x11);
  FUN_00404230(local_28);
  local_4 = 0;
  FUN_00401660(local_28,0);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  (**(code **)(*DAT_00b5ae0c + 0xb0))(uStack_1c);
  if (unaff_ESI < 0x10) {
    ExceptionList = unaff_EBX;
    return 1;
  }
  _free((void *)0x0);
  return extraout_EAX;
}


// ==== FUN_0077df40 @ 0x0077df40 ====

undefined4 FUN_0077df40(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00997002;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae0c;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x70))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(s_guildheal_009f6d68,9);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae0c + 0x70))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077e090 @ 0x0077e090 ====

/* WARNING: Removing unreachable block (ram,0x0077e0c5) */

undefined4 FUN_0077e090(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  uVar2 = thunk_FUN_00796f80(iVar1);
  (**(code **)(*DAT_00b5ae0c + 0x74))(uVar2);
  return 1;
}


// ==== FUN_0077e0f0 @ 0x0077e0f0 ====

undefined4 FUN_0077e0f0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099701c;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 4) != 0) {
    iVar1 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x1c;
    if (iVar1 != 0) {
      if (iVar1 == 1) {
        iVar1 = *DAT_00b5ae0c;
        ExceptionList = &local_c;
        uVar2 = FUN_00405d30(0);
        (**(code **)(iVar1 + 0x78))(uVar2);
      }
      else {
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        ExceptionList = &local_c;
        FUN_00401740(s_guildreturn_009f6d74,0xb);
        local_4 = 0;
        FUN_00794ad0(&local_28,param_2,local_44);
        local_4 = CONCAT31(local_4._1_3_,2);
        if (0xf < local_2c) {
          _free(local_40);
          return extraout_EAX;
        }
        local_2c = 0xf;
        local_30 = 0;
        local_40 = (void *)((uint)local_40 & 0xffffff00);
        if (local_14 == 0) {
          if (local_10 < (void *)0x10) {
            ExceptionList = local_c;
            return 0;
          }
          _free(local_24);
          return extraout_EAX_00;
        }
        (**(code **)(*DAT_00b5ae0c + 0x78))(&local_28);
        if (0xf < local_14) {
          _free(local_28);
          return extraout_EAX_01;
        }
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0077e240 @ 0x0077e240 ====

/* WARNING: Removing unreachable block (ram,0x0077e275) */

undefined4 FUN_0077e240(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  uVar2 = thunk_FUN_00796f80(iVar1);
  (**(code **)(*DAT_00b5ae0c + 0x7c))(uVar2);
  return 1;
}


// ==== FUN_0077e2a0 @ 0x0077e2a0 ====

/* WARNING: Removing unreachable block (ram,0x0077e2db) */

undefined4 FUN_0077e2a0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae0c;
  uVar3 = thunk_FUN_00796fb0(iVar1);
  (**(code **)(iVar2 + 0x88))(uVar3);
  return 1;
}


// ==== FUN_0077e300 @ 0x0077e300 ====

/* WARNING: Removing unreachable block (ram,0x0077e33b) */

undefined4 FUN_0077e300(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae0c;
  uVar3 = thunk_FUN_00796fb0(iVar1);
  (**(code **)(iVar2 + 0x8c))(uVar3);
  return 1;
}


// ==== FUN_0077e360 @ 0x0077e360 ====

/* WARNING: Removing unreachable block (ram,0x0077e39b) */

undefined4 FUN_0077e360(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae0c;
  uVar3 = thunk_FUN_00796fb0(iVar1);
  (**(code **)(iVar2 + 0x90))(uVar3);
  return 1;
}


// ==== FUN_0077e3c0 @ 0x0077e3c0 ====

/* WARNING: Removing unreachable block (ram,0x0077e3fb) */

undefined4 FUN_0077e3c0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae0c;
  uVar3 = thunk_FUN_00796fb0(iVar1);
  (**(code **)(iVar2 + 0x94))(uVar3);
  return 1;
}


// ==== FUN_0077e420 @ 0x0077e420 ====

/* WARNING: Removing unreachable block (ram,0x0077e45b) */

undefined4 FUN_0077e420(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 == 0) || ((*(int *)(param_1 + 8) - iVar1) / 0x1c != 1)) {
    return 0;
  }
  iVar2 = *DAT_00b5ae0c;
  uVar3 = thunk_FUN_00796fb0(iVar1);
  (**(code **)(iVar2 + 0xa4))(uVar3);
  return 1;
}


// ==== FUN_0077e480 @ 0x0077e480 ====

/* WARNING: Removing unreachable block (ram,0x0077e50d) */
/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_0077e480(int param_1,undefined1 param_2,void *param_3,int param_4)

{
  int iVar1;
  void *_Memory;
  char cVar2;
  undefined4 extraout_EAX;
  int iVar3;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar3 = param_4;
  _Memory = param_3;
  puStack_8 = &LAB_00997036;
  local_c = ExceptionList;
  local_4 = 0;
  if ((param_3 == (void *)0x0) ||
     (iVar1 = param_4 - (int)param_3 >> 0x1f, (param_4 - (int)param_3) / 0x1c + iVar1 == iVar1)) {
    ExceptionList = &local_c;
    FUN_0077cba0();
    if (_Memory == (void *)0x0) {
      ExceptionList = local_c;
      return 1;
    }
    FUN_00405de0(_Memory,iVar3,&param_2,param_1);
    _free(_Memory);
    return extraout_EAX;
  }
  ExceptionList = &local_c;
  FUN_004041d0(local_28,param_3);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_0040c0e0((int)_Memory + 0x1c,iVar3,_Memory,param_1);
  FUN_00405de0(iVar3 + -0x1c,iVar3,&param_2,param_1);
  param_4 = iVar3 + -0x1c;
  iVar3 = FUN_00403620(0,local_14,s_finish_009f6af4,6);
  if (iVar3 == 0) {
    cVar2 = FUN_0077cc90(&param_2);
    if (cVar2 == '\x01') {
      if (local_10 < 0x10) {
        local_10 = 0xf;
        local_14 = 0;
        local_24 = (void *)((uint)local_24 & 0xffffff00);
        FUN_00406250();
        ExceptionList = local_c;
        return 1;
      }
      _free(local_24);
      return extraout_EAX_00;
    }
  }
  else {
    iVar3 = FUN_00403620(0,local_14,s_distribute_009f6afc,10);
    if (iVar3 == 0) {
      (**(code **)(*DAT_00b5ae0c + 0xc))();
      goto LAB_0077ed4d;
    }
    cVar2 = FUN_004036a0(local_28,s_maxpc_009f6b08);
    if (cVar2 == '\0') {
      cVar2 = FUN_004036a0(local_28,s_maxplayer_009f6b10);
      if (cVar2 == '\0') {
        cVar2 = FUN_004036a0(local_28,s_regen_009f6b1c);
        if (cVar2 == '\0') {
          cVar2 = FUN_004036a0(local_28,s_playercount_009f6b24);
          if (cVar2 != '\0') {
            (**(code **)(*DAT_00b5ae0c + 0x1c))();
            goto LAB_0077ed4d;
          }
          cVar2 = FUN_004036a0(local_28,s_notice_009f6b30);
          if (cVar2 == '\0') {
            cVar2 = FUN_004036a0(local_28,s_summon_009f6b38);
            if (cVar2 == '\0') {
              cVar2 = FUN_004036a0(local_28,s_return_009f6b40);
              if (cVar2 == '\0') {
                cVar2 = FUN_004036a0(local_28,s_expratio_009f6b48);
                if (cVar2 == '\0') {
                  cVar2 = FUN_004036a0(local_28,s_itemdropratio_009f6b54);
                  if (cVar2 == '\0') {
                    cVar2 = FUN_004036a0(local_28,s_moneydropratio_009f6b64);
                    if (cVar2 == '\0') {
                      cVar2 = FUN_004036a0(local_28,s_movemap_009f6b74);
                      if (cVar2 == '\0') {
                        cVar2 = FUN_004036a0(local_28,s_reset_allmonster_009f6b7c);
                        if (cVar2 != '\0') {
                          (**(code **)(*DAT_00b5ae0c + 0x3c))();
                          goto LAB_0077ed4d;
                        }
                        cVar2 = FUN_004036a0(local_28,s_resetmonster_009f6b90);
                        if (cVar2 == '\0') {
                          cVar2 = FUN_004036a0(local_28,s_ghostmode_009f6ba0);
                          if (cVar2 == '\0') {
                            cVar2 = FUN_004036a0(local_28,s_observermode_009f6bac);
                            if (cVar2 == '\0') {
                              cVar2 = FUN_004036a0(local_28,s_callmonster_009f6bbc);
                              if (cVar2 == '\0') {
                                cVar2 = FUN_004036a0(local_28,s_callmonsters_009f6bc8);
                                if (cVar2 == '\0') {
                                  cVar2 = FUN_004036a0(local_28,&DAT_009f6bd8);
                                  if (cVar2 == '\0') {
                                    cVar2 = FUN_004036a0(local_28,s_revive_009f6be0);
                                    if (cVar2 == '\0') {
                                      cVar2 = FUN_004036a0(local_28,&DAT_009f6be8);
                                      if (cVar2 == '\0') {
                                        cVar2 = FUN_004036a0(local_28,&DAT_009f6bf0);
                                        if (cVar2 == '\0') {
                                          cVar2 = FUN_004036a0(local_28,&DAT_009f6bf8);
                                          if (cVar2 == '\0') {
                                            cVar2 = FUN_004036a0(local_28,s_chase_009f6c00);
                                            if (cVar2 == '\0') {
                                              cVar2 = FUN_004036a0(local_28,s_dummycount_009f6c08);
                                              if (cVar2 != '\0') {
                                                (**(code **)(*DAT_00b5ae0c + 0xac))();
                                                goto LAB_0077ed4d;
                                              }
                                              cVar2 = FUN_004036a0(local_28,s_damage_009f6c14);
                                              if (cVar2 == '\0') {
                                                cVar2 = FUN_004036a0(local_28,s_guildheal_009f6c1c);
                                                if (cVar2 == '\0') {
                                                  cVar2 = FUN_004036a0(local_28,s_fieldheal_009f6c28
                                                                      );
                                                  if (cVar2 == '\0') {
                                                    cVar2 = FUN_004036a0(local_28,
                                                  s_guildreturn_009f6c34);
                                                  if (cVar2 == '\0') {
                                                    cVar2 = FUN_004036a0(local_28,
                                                  s_fieldreturn_009f6c40);
                                                  if (cVar2 == '\0') {
                                                    cVar2 = FUN_004036a0(local_28,
                                                  s_siegereset_009f6c4c);
                                                  if (cVar2 == '\0') {
                                                    cVar2 = FUN_004036a0(local_28,
                                                  s_siegestop_009f6c58);
                                                  if (cVar2 == '\0') {
                                                    cVar2 = FUN_004036a0(local_28,
                                                  s_siegestart_009f6c64);
                                                  if (cVar2 == '\0') {
                                                    cVar2 = FUN_004036a0(local_28,
                                                  s_siegeend_009f6c70);
                                                  if (cVar2 == '\0') {
                                                    cVar2 = FUN_004036a0(local_28,
                                                  s_guildwarstart_009f6c7c);
                                                  if (cVar2 == '\0') {
                                                    cVar2 = FUN_004036a0(local_28,
                                                  s_guildwarend_009f6c8c);
                                                  if (cVar2 == '\0') {
                                                    cVar2 = FUN_004036a0(local_28,
                                                  s_open_teleport_009f6c98);
                                                  if (cVar2 != '\0') {
                                                    (**(code **)(*DAT_00b5ae0c + 0x98))();
                                                    goto LAB_0077ed4d;
                                                  }
                                                  cVar2 = FUN_004036a0(local_28,
                                                  s_close_teleport_009f6ca8);
                                                  if (cVar2 != '\0') {
                                                    (**(code **)(*DAT_00b5ae0c + 0x9c))();
                                                    goto LAB_0077ed4d;
                                                  }
                                                  cVar2 = FUN_004036a0(local_28,
                                                  s_resetcooltime_009f6cb8);
                                                  if (cVar2 != '\0') {
                                                    (**(code **)(*DAT_00b5ae0c + 0xa0))();
                                                    goto LAB_0077ed4d;
                                                  }
                                                  cVar2 = FUN_004036a0(local_28,
                                                  s_partywarstart_009f6cc8);
                                                  if (cVar2 == '\0') {
                                                    cVar2 = FUN_004036a0(local_28,
                                                  s_partywarend_009f6cd8);
                                                  if (cVar2 != '\0') {
                                                    (**(code **)(*DAT_00b5ae0c + 0xa8))();
                                                    goto LAB_0077ed4d;
                                                  }
                                                  cVar2 = FUN_004036a0(local_28,
                                                  s_createbrick_009f6ce4);
                                                  if (cVar2 == '\0') {
                                                    cVar2 = FUN_004036a0(local_28,
                                                  s_destroybrick_009f6cf0);
                                                  if (cVar2 == '\0') goto LAB_0077edc0;
                                                  cVar2 = FUN_0077dd80(&param_2);
                                                  }
                                                  else {
                                                    cVar2 = FUN_0077dd20(&param_2);
                                                  }
                                                  }
                                                  else {
                                                    cVar2 = FUN_0077e420(&param_2);
                                                  }
                                                  }
                                                  else {
                                                    cVar2 = FUN_0077e3c0(&param_2);
                                                  }
                                                  }
                                                  else {
                                                    cVar2 = FUN_0077e360(&param_2);
                                                  }
                                                  }
                                                  else {
                                                    cVar2 = FUN_0077e300(&param_2);
                                                  }
                                                  }
                                                  else {
                                                    cVar2 = FUN_0077e2a0(&param_2);
                                                  }
                                                  }
                                                  else {
                                                    cVar2 = FUN_0077caa0();
                                                  }
                                                  }
                                                  else {
                                                    cVar2 = FUN_0077ca80();
                                                  }
                                                  }
                                                  else {
                                                    cVar2 = FUN_0077e240(&param_2);
                                                  }
                                                  }
                                                  else {
                                                    cVar2 = FUN_0077e0f0(&param_2,param_1 + 8);
                                                  }
                                                  }
                                                  else {
                                                    cVar2 = FUN_0077e090(&param_2);
                                                  }
                                                }
                                                else {
                                                  cVar2 = FUN_0077df40(&param_2,param_1 + 8);
                                                }
                                              }
                                              else {
                                                cVar2 = FUN_0077dde0(&param_2);
                                              }
                                            }
                                            else {
                                              cVar2 = FUN_0077d7f0(&param_2,param_1 + 8);
                                            }
                                          }
                                          else {
                                            cVar2 = FUN_0077d6a0(&param_2,param_1 + 8);
                                          }
                                        }
                                        else {
                                          cVar2 = FUN_0077d550(&param_2,param_1 + 8);
                                        }
                                      }
                                      else {
                                        cVar2 = FUN_0077d400(&param_2,param_1 + 8);
                                      }
                                    }
                                    else {
                                      cVar2 = FUN_0077d2b0(&param_2,param_1 + 8);
                                    }
                                  }
                                  else {
                                    cVar2 = FUN_0077d160(&param_2,param_1 + 8);
                                  }
                                }
                                else {
                                  cVar2 = FUN_0077dca0(&param_2);
                                }
                                if (cVar2 == '\0') goto LAB_0077edc0;
                                goto LAB_0077ed4d;
                              }
                              cVar2 = FUN_0077dc40(&param_2);
                            }
                            else {
                              cVar2 = FUN_0077dbc0(&param_2);
                            }
                          }
                          else {
                            cVar2 = FUN_0077db50(&param_2);
                          }
                        }
                        else {
                          cVar2 = FUN_0077daf0(&param_2);
                        }
                      }
                      else {
                        cVar2 = FUN_0077da60(&param_2);
                      }
                    }
                    else {
                      cVar2 = FUN_0077da00(&param_2);
                    }
                  }
                  else {
                    cVar2 = FUN_0077d9a0(&param_2);
                  }
                }
                else {
                  cVar2 = FUN_0077d940(&param_2);
                }
              }
              else {
                cVar2 = FUN_0077d010(&param_2,param_1 + 8);
              }
            }
            else {
              cVar2 = FUN_0077cec0(&param_2,param_1 + 8);
            }
          }
          else {
            cVar2 = FUN_0077ce70(&param_2);
          }
        }
        else {
          cVar2 = FUN_0077ce10(&param_2);
        }
      }
      else {
        cVar2 = FUN_0077cdb0(&param_2);
      }
    }
    else {
      cVar2 = FUN_0077cd50(&param_2);
    }
    if (cVar2 == '\x01') {
LAB_0077ed4d:
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
LAB_0077edc0:
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00406250();
    ExceptionList = local_c;
    return 0;
  }
  _free(local_24);
  return extraout_EAX_01;
}


// ==== FUN_0077ee10 @ 0x0077ee10 ====

/* WARNING: Removing unreachable block (ram,0x0077eea5) */
/* WARNING: Removing unreachable block (ram,0x0077ee61) */
/* WARNING: Removing unreachable block (ram,0x0077ee80) */
/* WARNING: Removing unreachable block (ram,0x0077eea3) */
/* WARNING: Removing unreachable block (ram,0x0077eeea) */
/* WARNING: Removing unreachable block (ram,0x0077eef7) */
/* WARNING: Removing unreachable block (ram,0x0077ef01) */
/* WARNING: Removing unreachable block (ram,0x0077f03d) */
/* WARNING: Removing unreachable block (ram,0x0077f069) */
/* WARNING: Removing unreachable block (ram,0x0077f0c6) */
/* WARNING: Removing unreachable block (ram,0x0077f0cc) */
/* WARNING: Removing unreachable block (ram,0x0077f0d9) */
/* WARNING: Removing unreachable block (ram,0x0077f083) */
/* WARNING: Removing unreachable block (ram,0x0077f089) */
/* WARNING: Removing unreachable block (ram,0x0077f096) */
/* WARNING: Removing unreachable block (ram,0x0077f0a6) */
/* WARNING: Removing unreachable block (ram,0x0077ef4e) */
/* WARNING: Removing unreachable block (ram,0x0077ef6f) */
/* WARNING: Removing unreachable block (ram,0x0077ef9d) */
/* WARNING: Removing unreachable block (ram,0x0077f00d) */
/* WARNING: Removing unreachable block (ram,0x0077efc6) */
/* WARNING: Removing unreachable block (ram,0x0077f0aa) */

uint FUN_0077ee10(void)

{
  uint uVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00997068;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  uVar1 = FUN_00405670();
  ExceptionList = local_c;
  return uVar1 & 0xffffff00;
}


// ==== FUN_0077f110 @ 0x0077f110 ====

void FUN_0077f110(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099707a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f6d88;
  local_4 = 0;
  FUN_00410f60(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0077f190 @ 0x0077f190 ====

/* WARNING: Removing unreachable block (ram,0x0077fa57) */
/* WARNING: Removing unreachable block (ram,0x0077f857) */
/* WARNING: Removing unreachable block (ram,0x0077f966) */
/* WARNING: Removing unreachable block (ram,0x0077fb0a) */
/* WARNING: Removing unreachable block (ram,0x0077f767) */

undefined4 FUN_0077f190(void)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  undefined4 extraout_EAX_07;
  undefined4 extraout_EAX_08;
  undefined4 extraout_EAX_09;
  undefined4 extraout_EAX_10;
  undefined4 uVar3;
  undefined4 extraout_EAX_11;
  undefined4 extraout_EAX_12;
  undefined4 extraout_EAX_13;
  undefined4 extraout_EAX_14;
  undefined4 extraout_EAX_15;
  undefined4 extraout_EAX_16;
  undefined4 extraout_EAX_17;
  undefined4 extraout_EAX_18;
  undefined4 extraout_EAX_19;
  undefined4 extraout_EAX_20;
  undefined4 extraout_EAX_21;
  undefined4 extraout_EAX_22;
  undefined4 extraout_EAX_23;
  undefined4 extraout_EAX_24;
  undefined4 extraout_EAX_25;
  undefined4 extraout_EAX_26;
  undefined4 extraout_EAX_27;
  undefined4 extraout_EAX_28;
  undefined4 extraout_EAX_29;
  undefined4 extraout_EAX_30;
  undefined4 extraout_EAX_31;
  undefined4 extraout_EAX_32;
  undefined4 extraout_EAX_33;
  undefined4 extraout_EAX_34;
  undefined4 extraout_EAX_35;
  undefined4 extraout_EAX_36;
  undefined4 extraout_EAX_37;
  undefined4 extraout_EAX_38;
  undefined4 extraout_EAX_39;
  undefined4 extraout_EAX_40;
  undefined4 extraout_EAX_41;
  undefined4 extraout_EAX_42;
  undefined4 extraout_EAX_43;
  undefined4 extraout_EAX_44;
  undefined4 extraout_EAX_45;
  undefined4 extraout_EAX_46;
  undefined4 extraout_EAX_47;
  undefined4 extraout_EAX_48;
  undefined4 extraout_EAX_49;
  undefined4 extraout_EAX_50;
  undefined4 extraout_EAX_51;
  undefined4 extraout_EAX_52;
  undefined4 extraout_EAX_53;
  undefined4 extraout_EAX_54;
  undefined4 extraout_EAX_55;
  undefined4 extraout_EAX_56;
  undefined4 extraout_EAX_57;
  undefined4 extraout_EAX_58;
  undefined4 extraout_EAX_59;
  undefined4 extraout_EAX_60;
  undefined4 extraout_EAX_61;
  undefined4 extraout_EAX_62;
  undefined4 extraout_EAX_63;
  undefined4 extraout_EAX_64;
  undefined4 extraout_EAX_65;
  undefined4 extraout_EAX_66;
  undefined4 extraout_EAX_67;
  undefined4 extraout_EAX_68;
  undefined4 extraout_EAX_69;
  undefined4 extraout_EAX_70;
  undefined4 extraout_EAX_71;
  undefined4 extraout_EAX_72;
  undefined4 extraout_EAX_73;
  undefined4 extraout_EAX_74;
  undefined4 extraout_EAX_75;
  undefined4 extraout_EAX_76;
  undefined4 extraout_EAX_77;
  undefined4 extraout_EAX_78;
  undefined4 extraout_EAX_79;
  undefined4 extraout_EAX_80;
  undefined4 extraout_EAX_81;
  undefined4 extraout_EAX_82;
  undefined4 extraout_EAX_83;
  undefined4 extraout_EAX_84;
  undefined4 extraout_EAX_85;
  undefined4 extraout_EAX_86;
  undefined4 extraout_EAX_87;
  undefined4 extraout_EAX_88;
  undefined4 extraout_EAX_89;
  undefined4 extraout_EAX_90;
  undefined4 extraout_EAX_91;
  undefined4 extraout_EAX_92;
  undefined4 extraout_EAX_93;
  undefined4 extraout_EAX_94;
  undefined4 extraout_EAX_95;
  undefined4 extraout_EAX_96;
  undefined4 extraout_EAX_97;
  undefined4 extraout_EAX_98;
  undefined4 extraout_EAX_99;
  undefined4 *in_ECX;
  uint unaff_EDI;
  undefined1 auStack_f6 [2];
  undefined4 uStack_e4;
  undefined1 *puStack_d8;
  void *pvStack_d0;
  void *pvStack_cc;
  uint uStack_c8;
  void *pvStack_c4;
  uint uStack_c0;
  void *pvStack_bc;
  uint uStack_b8;
  void *pvStack_b4;
  void *pvStack_b0;
  undefined4 uStack_ac;
  void *pvStack_a8;
  undefined4 uStack_a4;
  void *pvStack_a0;
  uint uStack_9c;
  void *pvStack_98;
  void *pvStack_94;
  void *pvStack_90;
  void *pvStack_8c;
  undefined4 uStack_88;
  void *pvStack_84;
  uint uStack_80;
  void *pvStack_7c;
  uint uStack_78;
  void *pvStack_74;
  uint auStack_70 [4];
  void *pvStack_60;
  undefined1 auStack_5c [8];
  undefined1 local_54 [4];
  undefined4 uStack_50;
  uint local_4c [2];
  void *pvStack_44;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 local_34;
  undefined1 local_30;
  undefined1 uStack_2c;
  undefined1 uStack_24;
  undefined4 local_20;
  undefined4 local_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  undefined1 auStack_8 [4];
  
  puStack_d8 = auStack_8 + 4;
  puStack_10 = &LAB_00997653;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  *in_ECX = &PTR_FUN_009f6d88;
  local_c = 0;
  uStack_e4 = 0x77f1d5;
  iVar2 = FUN_004105c0();
  in_ECX[2] = iVar2;
  *(undefined1 *)(iVar2 + 0x45) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  local_38 = 0xf;
  local_3c = 0;
  local_4c[0] = local_4c[0] & 0xffffff00;
  uStack_e4 = 4;
  local_c._0_1_ = 2;
  local_1c = 0xf;
  local_20 = 0;
  local_30 = 0;
  FUN_00401740();
  uStack_e4 = 0x640001;
  local_c = CONCAT31(local_c._1_3_,3);
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  pvStack_a0 = (void *)0xf;
  uStack_a4 = 0;
  pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
  FUN_00401740();
  pvStack_14._0_1_ = 4;
  FUN_00405bd0();
  pvStack_14._0_1_ = 5;
  FUN_00410890();
  pvStack_14._0_1_ = 6;
  FUN_00411200();
  if (0xf < pvStack_60) {
    _free(pvStack_74);
    return extraout_EAX;
  }
  pvStack_60 = (void *)0xf;
  auStack_70[3] = 0;
  pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
  if (0xf < pvStack_7c) {
    _free(pvStack_90);
    return extraout_EAX_00;
  }
  pvStack_7c = (void *)0xf;
  uStack_80 = 0;
  pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
  if ((void *)0xf < pvStack_bc) {
    _free(pvStack_d0);
    return extraout_EAX_01;
  }
  pvStack_bc = (void *)0xf;
  uStack_c0 = 0;
  uVar1 = (uint)pvStack_d0 >> 8;
  pvStack_d0 = (void *)(uVar1 << 8);
  pvStack_14._0_1_ = 3;
  if (0xf < pvStack_a0) {
    _free(pvStack_b4);
    return extraout_EAX_02;
  }
  pvStack_bc = (void *)0xf;
  uStack_c0 = 0;
  pvStack_d0 = (void *)(uVar1 << 8);
  FUN_00401740();
  pvStack_14._0_1_ = 7;
  pvStack_a0 = (void *)0xf;
  uStack_a4 = 0;
  pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
  FUN_00401740();
  pvStack_14._0_1_ = 8;
  FUN_00410890();
  pvStack_14._0_1_ = 9;
  FUN_00411200();
  if (0xf < pvStack_60) {
    _free(pvStack_74);
    return extraout_EAX_03;
  }
  pvStack_60 = (void *)0xf;
  auStack_70[3] = 0;
  pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
  if (0xf < pvStack_7c) {
    _free(pvStack_90);
    return extraout_EAX_04;
  }
  pvStack_7c = (void *)0xf;
  uStack_80 = 0;
  pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
  if (0xf < pvStack_a0) {
    _free(pvStack_b4);
    return extraout_EAX_05;
  }
  pvStack_a0 = (void *)0xf;
  uStack_a4 = 0;
  pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
  pvStack_14 = (void *)CONCAT31(pvStack_14._1_3_,3);
  if ((void *)0xf < pvStack_bc) {
    _free(pvStack_d0);
    return extraout_EAX_06;
  }
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  pvStack_c4 = (void *)0xf;
  uStack_c8 = 0;
  puStack_d8 = (undefined1 *)((uint)puStack_d8 & 0xffffff00);
  FUN_00401740();
  local_1c._0_1_ = 10;
  FUN_00405bd0();
  local_1c._0_1_ = 0xb;
  FUN_00410890();
  local_1c._0_1_ = 0xc;
  FUN_00411200();
  if (0xf < auStack_70[2]) {
    _free(pvStack_7c);
    return extraout_EAX_07;
  }
  auStack_70[2] = 0xf;
  auStack_70[1] = 0;
  pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
  if (0xf < pvStack_84) {
    _free(pvStack_98);
    return extraout_EAX_08;
  }
  pvStack_84 = (void *)0xf;
  uStack_88 = 0;
  pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
  if (0xf < pvStack_a8) {
    _free(pvStack_bc);
    return extraout_EAX_09;
  }
  pvStack_a8 = (void *)0xf;
  uStack_ac = 0;
  pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
  local_1c = CONCAT31(local_1c._1_3_,3);
  if ((void *)0xf < pvStack_c4) {
    _free(puStack_d8);
    return extraout_EAX_10;
  }
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660(uVar3,0);
  pvStack_cc = (void *)0xf;
  pvStack_d0 = (void *)0x0;
  FUN_00401740(s_maxplayer_009f6580);
  uStack_24 = 0xd;
  FUN_00405bd0(&uStack_c8,local_4c);
  uStack_24 = 0xe;
  FUN_00410890(&uStack_e4);
  uStack_24 = 0xf;
  FUN_00411200(&uStack_ac);
  if (0xf < auStack_70[0]) {
    _free(pvStack_84);
    return extraout_EAX_11;
  }
  auStack_70[0] = 0xf;
  pvStack_74 = (void *)0x0;
  pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
  if (0xf < pvStack_8c) {
    _free(pvStack_a0);
    return extraout_EAX_12;
  }
  pvStack_8c = (void *)0xf;
  pvStack_90 = (void *)0x0;
  pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
  if (0xf < pvStack_b0) {
    _free(pvStack_c4);
    return extraout_EAX_13;
  }
  pvStack_b0 = (void *)0xf;
  pvStack_b4 = (void *)0x0;
  pvStack_c4 = (void *)((uint)pvStack_c4 & 0xffffff00);
  uStack_24 = 3;
  if ((void *)0xf < pvStack_cc) {
    _free((void *)(unaff_EDI & 0xffffff00));
    return extraout_EAX_14;
  }
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0);
  FUN_00401660(uVar3,0,0xffffffff);
  puStack_d8 = (undefined1 *)0x0;
  FUN_00401740(s_regen_009f658c,5);
  uStack_2c = 0x10;
  uVar3 = FUN_00405bd0(&pvStack_d0,local_54,auStack_70);
  uStack_2c = 0x11;
  uVar3 = FUN_00410890(auStack_f6 + 10,uVar3);
  uStack_2c = 0x12;
  FUN_00411200(&pvStack_b4,uVar3);
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return extraout_EAX_15;
  }
  uStack_78 = 0xf;
  pvStack_7c = (void *)0x0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  if (0xf < pvStack_94) {
    _free(pvStack_a8);
    return extraout_EAX_16;
  }
  pvStack_94 = (void *)0xf;
  pvStack_98 = (void *)0x0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < uStack_b8) {
    _free(pvStack_cc);
    return extraout_EAX_17;
  }
  uStack_b8 = 0xf;
  pvStack_bc = (void *)0x0;
  pvStack_cc = (void *)((uint)pvStack_cc & 0xffffff00);
  uStack_2c = 3;
  puStack_d8 = (undefined1 *)0x0;
  FUN_00401740(s__GM_PLAYERCOUNT_009f6594,0xf);
  uStack_2c = 0x13;
  uStack_b8 = 0xf;
  pvStack_bc = (void *)0x0;
  pvStack_cc = (void *)((uint)pvStack_cc & 0xffffff00);
  FUN_00401740(s_playercount_009f65a4,0xb);
  uStack_2c = 0x14;
  uVar3 = FUN_00410890(&pvStack_d0,auStack_f6 + 10);
  uStack_2c = 0x15;
  FUN_00411200(&pvStack_b4,uVar3);
  if (0xf < uStack_78) {
    _free(pvStack_8c);
    return extraout_EAX_18;
  }
  uStack_78 = 0xf;
  pvStack_7c = (void *)0x0;
  pvStack_8c = (void *)((uint)pvStack_8c & 0xffffff00);
  if (0xf < pvStack_94) {
    _free(pvStack_a8);
    return extraout_EAX_19;
  }
  pvStack_94 = (void *)0xf;
  pvStack_98 = (void *)0x0;
  pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
  if (0xf < uStack_b8) {
    _free(pvStack_cc);
    return extraout_EAX_20;
  }
  uStack_b8 = 0xf;
  pvStack_bc = (void *)0x0;
  pvStack_cc = (void *)((uint)pvStack_cc & 0xffffff00);
  uStack_2c = 3;
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x640005);
  FUN_00401660(uVar3,0,0xffffffff);
  FUN_00401740(s_notice_009f65b0,6);
  local_34 = 0x16;
  uVar3 = FUN_00405bd0(&puStack_d8,auStack_5c,&uStack_78);
  local_34 = 0x17;
  uVar3 = FUN_00410890(auStack_f6 + 2,uVar3);
  local_34 = 0x18;
  FUN_00411200(&pvStack_bc,uVar3);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return extraout_EAX_21;
  }
  uStack_80 = 0xf;
  pvStack_84 = (void *)0x0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  if (0xf < uStack_9c) {
    _free(pvStack_b0);
    return extraout_EAX_22;
  }
  uStack_9c = 0xf;
  pvStack_a0 = (void *)0x0;
  pvStack_b0 = (void *)((uint)pvStack_b0 & 0xffffff00);
  if (0xf < uStack_c0) {
    _free((void *)0xf);
    return extraout_EAX_23;
  }
  uStack_c0 = 0xf;
  pvStack_c4 = (void *)0x0;
  local_34 = 3;
  FUN_00401740(s__GM_SUMMON__PC_ID__009f65b8,0x12);
  local_34 = 0x19;
  uStack_c0 = 0xf;
  pvStack_c4 = (void *)0x0;
  FUN_00401740(s_summon_009f65cc,6);
  local_34 = 0x1a;
  uVar3 = FUN_00410890(&puStack_d8,auStack_f6 + 2);
  local_34 = 0x1b;
  FUN_00411200(&pvStack_bc,uVar3);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return extraout_EAX_24;
  }
  uStack_80 = 0xf;
  pvStack_84 = (void *)0x0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  if (0xf < uStack_9c) {
    _free(pvStack_b0);
    return extraout_EAX_25;
  }
  uStack_9c = 0xf;
  pvStack_a0 = (void *)0x0;
  pvStack_b0 = (void *)((uint)pvStack_b0 & 0xffffff00);
  if (0xf < uStack_c0) {
    _free((void *)0x0);
    return extraout_EAX_26;
  }
  uStack_c0 = 0xf;
  pvStack_c4 = (void *)0x0;
  local_34 = 3;
  FUN_00401740(s__GM_RETURN__PC_ID__009f65d4,0x12);
  local_34 = 0x1c;
  uStack_c0 = 0xf;
  pvStack_c4 = (void *)0x0;
  FUN_00401740(s_return_009f65e8,6);
  local_34 = 0x1d;
  uVar3 = FUN_00410890(&puStack_d8,auStack_f6 + 2);
  local_34 = 0x1e;
  FUN_00411200(&pvStack_bc,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_c0) {
    _free((void *)0x0);
    return extraout_EAX_27;
  }
  uStack_c0 = 0xf;
  pvStack_c4 = (void *)0x0;
  local_34 = 3;
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x640006);
  FUN_00401660(uVar3,0,0xffffffff);
  FUN_00401830(s_expratio_009f65f0);
  local_3c._0_1_ = 0x1f;
  uVar3 = FUN_00405bd0(auStack_f6 + -6,auStack_70 + 3,&uStack_80);
  local_3c._0_1_ = 0x20;
  uVar3 = FUN_00410890(auStack_f6 + 0x16,uVar3);
  local_3c._0_1_ = 0x21;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_28;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_29;
  }
  FUN_00401830(s__GM_ITEMDROPRATIO__ItemDropRatio_009f65fc);
  local_3c._0_1_ = 0x22;
  FUN_00401830(s_itemdropratio_009f6624);
  local_3c._0_1_ = 0x23;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x24;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_30;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_31;
  }
  FUN_00401830(s__GM_MONEYDROPRATIO__MoneyDropRat_009f6634);
  local_3c._0_1_ = 0x25;
  FUN_00401830(s_moneydropratio_009f6660);
  local_3c._0_1_ = 0x26;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x27;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_32;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_33;
  }
  FUN_00401830(s__GM_MOVEMAP__MAPINDEX___X___Y__009f6670);
  local_3c._0_1_ = 0x28;
  FUN_00401830(s_movemap_009f6690);
  local_3c._0_1_ = 0x29;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x2a;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_34;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_35;
  }
  FUN_00401830(s__GM_RESET_ALLMONSTER_009f6698);
  local_3c._0_1_ = 0x2b;
  FUN_00401830(s_reset_allmonster_009f66b0);
  local_3c._0_1_ = 0x2c;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x2d;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_36;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_37;
  }
  FUN_00401830(s__GM_RESETMONSTER__MONSTERINDEX_009f66c4);
  local_3c._0_1_ = 0x2e;
  FUN_00401830(s_resetmonster_009f66e4);
  local_3c._0_1_ = 0x2f;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x30;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_38;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_39;
  }
  FUN_00401830(s__GM_ghostmode__on_off__009f66f4);
  local_3c._0_1_ = 0x31;
  FUN_00401830(s_ghostmode_009f670c);
  local_3c._0_1_ = 0x32;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x33;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_40;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_41;
  }
  FUN_00401830(s__GM_observermode__on_off__009f6718);
  local_3c._0_1_ = 0x34;
  FUN_00401830(s_observermode_009f6734);
  local_3c._0_1_ = 0x35;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x36;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_42;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_43;
  }
  FUN_00401830(s__GM_callmonster__MonsterIndex__009f6744);
  local_3c._0_1_ = 0x37;
  FUN_00401830(s_callmonster_009f6764);
  local_3c._0_1_ = 0x38;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x39;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_44;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_45;
  }
  FUN_00401830(s__GM_callmonsters__index___count__009f6770);
  local_3c._0_1_ = 0x3a;
  FUN_00401830(s_callmonsters_009f6794);
  local_3c._0_1_ = 0x3b;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x3c;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_46;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_47;
  }
  FUN_00401830(s__GM_kick__PC_ID__009f67a4);
  local_3c._0_1_ = 0x3d;
  FUN_00401830(&DAT_009f67b8);
  local_3c._0_1_ = 0x3e;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x3f;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_48;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_49;
  }
  FUN_00401830(s__GM_call__PC_ID__009f67c0);
  local_3c._0_1_ = 0x40;
  FUN_00401830(&DAT_009f67d4);
  local_3c._0_1_ = 0x41;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x42;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_50;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_51;
  }
  FUN_00401830(s__GM_revive__PC_ID__009f67dc);
  local_3c._0_1_ = 0x43;
  FUN_00401830(s_revive_009f67f0);
  local_3c._0_1_ = 0x44;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x45;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_52;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_53;
  }
  FUN_00401830(s__GM_heal__PC_ID__009f67f8);
  local_3c._0_1_ = 0x46;
  FUN_00401830(&DAT_009f680c);
  local_3c._0_1_ = 0x47;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x48;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_54;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_55;
  }
  FUN_00401830(s__GM_find__PC_ID__009f6814);
  local_3c._0_1_ = 0x49;
  FUN_00401830(&DAT_009f6828);
  local_3c._0_1_ = 0x4a;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x4b;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_56;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_57;
  }
  FUN_00401830(s__GM_chase__PC_ID__009f6830);
  local_3c._0_1_ = 0x4c;
  FUN_00401830(s_chase_009f6844);
  local_3c._0_1_ = 0x4d;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x4e;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_58;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_59;
  }
  FUN_00401830(s__GM_dummycount_009f684c);
  local_3c._0_1_ = 0x4f;
  FUN_00401830(s_dummycount_009f685c);
  local_3c._0_1_ = 0x50;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x51;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_60;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_61;
  }
  FUN_00401830(s__GM_damage__on_off__009f6868);
  local_3c._0_1_ = 0x52;
  FUN_00401830(s_damage_009f687c);
  local_3c._0_1_ = 0x53;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x54;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_62;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_63;
  }
  FUN_00401830(s__GM_createbrick__BrickID__009f6884);
  local_3c._0_1_ = 0x55;
  FUN_00401830(s_createbrick_009f68a0);
  local_3c._0_1_ = 0x56;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x57;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_64;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_65;
  }
  FUN_00401830(s__GM_destroybrick__BrickID__009f68ac);
  local_3c._0_1_ = 0x58;
  FUN_00401830(s_destroybrick_009f68c8);
  local_3c._0_1_ = 0x59;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x5a;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_66;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_67;
  }
  FUN_00401830(s__GM_guildheal__pc_name__009f68d8);
  local_3c._0_1_ = 0x5b;
  FUN_00401830(s_guildheal_009f68f0);
  local_3c._0_1_ = 0x5c;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x5d;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_68;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_69;
  }
  FUN_00401830(s__GM_fieldheal__map_index__009f68fc);
  local_3c._0_1_ = 0x5e;
  FUN_00401830(s_fieldheal_009f6918);
  local_3c._0_1_ = 0x5f;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x60;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_70;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_71;
  }
  FUN_00401830(s__GM_guildreturn__pc_name__009f6924);
  local_3c._0_1_ = 0x61;
  FUN_00401830(s_guildreturn_009f6940);
  local_3c._0_1_ = 0x62;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 99;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_72;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_73;
  }
  FUN_00401830(s__GM_fieldreturn__map_index__009f694c);
  local_3c._0_1_ = 100;
  FUN_00401830(s_fieldreturn_009f6968);
  local_3c._0_1_ = 0x65;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x66;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_74;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_75;
  }
  FUN_00401830(s__GM_siegereset_009f6974);
  local_3c._0_1_ = 0x67;
  FUN_00401830(s_siegereset_009f6984);
  local_3c._0_1_ = 0x68;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x69;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_76;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_77;
  }
  FUN_00401830(s__GM_siegestop_009f6990);
  local_3c._0_1_ = 0x6a;
  FUN_00401830(s_siegestop_009f69a0);
  local_3c._0_1_ = 0x6b;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x6c;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_78;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_79;
  }
  FUN_00401830(s__GM_siegestart__time__009f69ac);
  local_3c._0_1_ = 0x6d;
  FUN_00401830(s_siegestart_009f69c4);
  local_3c._0_1_ = 0x6e;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x6f;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_80;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_81;
  }
  FUN_00401830(s__GM_siegeend__time__009f69d0);
  local_3c._0_1_ = 0x70;
  FUN_00401830(s_siegeend_009f69e4);
  local_3c._0_1_ = 0x71;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x72;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_82;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_83;
  }
  FUN_00401830(s__GM_guildwarstart__time__009f69f0);
  local_3c._0_1_ = 0x73;
  FUN_00401830(s_guildwarstart_009f6a0c);
  local_3c._0_1_ = 0x74;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x75;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_84;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_85;
  }
  FUN_00401830(s__GM_guildwarend__time__009f6a1c);
  local_3c._0_1_ = 0x76;
  FUN_00401830(s_guildwarend_009f6a34);
  local_3c._0_1_ = 0x77;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x78;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_86;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_87;
  }
  FUN_00401830(s__GM_open_teleport_009f6a40);
  local_3c._0_1_ = 0x79;
  FUN_00401830(s_open_teleport_009f6a54);
  local_3c._0_1_ = 0x7a;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x7b;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_88;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_89;
  }
  FUN_00401830(s__GM_close_teleport_009f6a64);
  local_3c._0_1_ = 0x7c;
  FUN_00401830(s_close_teleport_009f6a78);
  local_3c._0_1_ = 0x7d;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x7e;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_90;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_91;
  }
  FUN_00401830(s__GM_resetcooltime_009f6a88);
  local_3c._0_1_ = 0x7f;
  FUN_00401830(s_resetcooltime_009f6a9c);
  local_3c._0_1_ = 0x80;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x81;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_92;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_93;
  }
  FUN_00401830(s__GM_partywarstart__time__009f6aac);
  local_3c._0_1_ = 0x82;
  FUN_00401830(s_partywarstart_009f6ac8);
  local_3c._0_1_ = 0x83;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c._0_1_ = 0x84;
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_94;
  }
  uStack_e4 = 0xf;
  local_3c._0_1_ = 3;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_95;
  }
  FUN_00401830(s__GM_partywarend_009f6ad8);
  local_3c._0_1_ = 0x85;
  FUN_00401830(s_partywarend_009f6ae8);
  local_3c._0_1_ = 0x86;
  uVar3 = FUN_00410890(auStack_f6 + -6,auStack_f6 + 0x16);
  local_3c = CONCAT31(local_3c._1_3_,0x87);
  FUN_00411200(&pvStack_c4,uVar3);
  FUN_0040a7d0();
  if (0xf < uStack_e4) {
    _free((void *)0x0);
    return extraout_EAX_96;
  }
  uStack_e4 = 0xf;
  if (0xf < uStack_c8) {
    _free((void *)0xf);
    return extraout_EAX_97;
  }
  if (0xf < local_4c[0]) {
    _free(pvStack_60);
    return extraout_EAX_98;
  }
  local_4c[0] = 0xf;
  uStack_50 = 0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  if (auStack_70[2] < 0x10) {
    ExceptionList = pvStack_44;
    return pvStack_84;
  }
  _free(pvStack_7c);
  return extraout_EAX_99;
}


