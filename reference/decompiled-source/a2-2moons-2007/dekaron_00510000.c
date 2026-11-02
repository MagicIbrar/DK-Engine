// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x510000-0x51ffff

// ==== FUN_00510570 @ 0x00510570 ====

undefined4 FUN_00510570(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x20001) {
    cVar1 = FUN_0050fe30(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x20002) {
    cVar1 = FUN_0050fae0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x40001) {
    FUN_0050f960(param_1);
  }
  return 0;
}


// ==== FUN_005105d0 @ 0x005105d0 ====

undefined4 FUN_005105d0(void)

{
  return 0x50030002;
}


// ==== FUN_005105e0 @ 0x005105e0 ====

undefined4 FUN_005105e0(void)

{
  return 0x50030004;
}


// ==== FUN_005105f0 @ 0x005105f0 ====

undefined4 FUN_005105f0(void)

{
  return 0x70210007;
}


// ==== FUN_00510600 @ 0x00510600 ====

void FUN_00510600(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b62fc;
  in_ECX[1] = *param_1;
  in_ECX[2] = param_1[1];
  in_ECX[3] = param_1[2];
  in_ECX[4] = param_1[3];
  in_ECX[5] = param_1[4];
  return;
}


// ==== FUN_00510630 @ 0x00510630 ====

undefined4 FUN_00510630(void)

{
  return 0x70190010;
}


// ==== FUN_00510640 @ 0x00510640 ====

undefined4 FUN_00510640(void)

{
  return 0x70230000;
}


// ==== FUN_00510650 @ 0x00510650 ====

void FUN_00510650(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981690;
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


// ==== Catch@005106da @ 0x005106da ====

void Catch_005106da(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005106f0 @ 0x005106f0 ====

void * FUN_005106f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009816a0;
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


// ==== Catch@00510765 @ 0x00510765 ====

void Catch_00510765(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00510780 @ 0x00510780 ====

void FUN_00510780(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00510780(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_005107c0 @ 0x005107c0 ====

void FUN_005107c0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00510780(piVar6[1]);
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


// ==== FUN_00510880 @ 0x00510880 ====

void FUN_00510880(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_005106f0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00510985:
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
      if ((char)piVar6[5] == '\0') goto LAB_00510985;
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


// ==== FUN_00510a60 @ 0x00510a60 ====

void FUN_00510a60(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  bool bVar3;
  
  puVar2 = *(undefined4 **)(in_ECX + 4);
  bVar3 = true;
  if (*(char *)((int)puVar2[1] + 0x15) == '\0') {
    puVar1 = (undefined4 *)puVar2[1];
    do {
      puVar2 = puVar1;
      bVar3 = *param_2 < (uint)puVar2[3];
      if (bVar3) {
        puVar1 = (undefined4 *)*puVar2;
      }
      else {
        puVar1 = (undefined4 *)puVar2[2];
      }
    } while (*(char *)((int)puVar1 + 0x15) == '\0');
  }
  puVar2 = (undefined4 *)FUN_00510880(&param_2,bVar3,puVar2,param_2);
  *param_1 = *puVar2;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_00510ad0 @ 0x00510ad0 ====

void FUN_00510ad0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6334;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00510af0 @ 0x00510af0 ====

void FUN_00510af0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009816b0;
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


// ==== Catch@00510b5f @ 0x00510b5f ====

void Catch_00510b5f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00510b80 @ 0x00510b80 ====

void FUN_00510b80(void)

{
  undefined4 *puVar1;
  void *_Memory;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  if (_Memory == *(void **)(in_ECX + 4)) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00510bc0 @ 0x00510bc0 ====

void FUN_00510bc0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009816c0;
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


// ==== Catch@00510c29 @ 0x00510c29 ====

void Catch_00510c29(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00510c40 @ 0x00510c40 ====

undefined4 FUN_00510c40(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  char cVar3;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      return 0;
    }
    cVar3 = (**(code **)(*(int *)puVar2[2] + 4))(param_1);
    if (cVar3 != '\0') break;
    puVar2 = (undefined4 *)*puVar2;
  }
  return 1;
}


// ==== FUN_00510cd0 @ 0x00510cd0 ====

void FUN_00510cd0(void)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *in_ECX;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b6340;
  uVar2 = FUN_00510af0();
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  pvVar3 = operator_new(4);
  if (pvVar3 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_005139b0();
  }
  iVar1 = in_ECX[2];
  iVar4 = FUN_00510bc0(iVar1,*(undefined4 *)(iVar1 + 4),&local_4);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar4;
  **(int **)(iVar4 + 4) = iVar4;
  pvVar3 = operator_new(0xc);
  if (pvVar3 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_005137f0();
  }
  iVar1 = in_ECX[2];
  iVar4 = FUN_00510bc0(iVar1,*(undefined4 *)(iVar1 + 4),&local_4);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar4;
  **(int **)(iVar4 + 4) = iVar4;
  return;
}


// ==== FUN_00510d90 @ 0x00510d90 ====

void FUN_00510d90(byte param_1)

{
  undefined4 *in_ECX;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b6340;
  if (in_ECX[3] != 0) {
    local_4 = (uint)in_ECX & 0xffffff00;
    FUN_00528030(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2],local_4);
    FUN_00510b80();
  }
  FUN_008984a0();
  *in_ECX = &PTR_FUN_009b6334;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00510df0 @ 0x00510df0 ====

void FUN_00510df0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6448;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00510e10 @ 0x00510e10 ====

undefined4 FUN_00510e10(void)

{
  return 0x70130007;
}


// ==== FUN_00510e20 @ 0x00510e20 ====

undefined4 FUN_00510e20(void)

{
  return 0x70130008;
}


// ==== FUN_00510e40 @ 0x00510e40 ====

void FUN_00510e40(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b6480;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  FUN_005144e0();
  FUN_00513fb0();
  FUN_00513ba0();
  FUN_00513b20();
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_enemy_monster_009b634c,0xd);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_1c,1);
  if (uStack_c < 0x10) {
    return;
  }
  _free(unaff_EBX);
  return;
}


// ==== FUN_00510ec0 @ 0x00510ec0 ====

void FUN_00510ec0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *pvStack_1c;
  undefined1 uStack_18;
  uint uStack_8;
  undefined4 uStack_4;
  
  *in_ECX = &PTR_FUN_009b6480;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b646c;
  }
  FUN_00797a20(puVar1);
  FUN_00514970();
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  FUN_00514640();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  FUN_00514520();
  FUN_00513f80();
  FUN_00513b80();
  FUN_00513b40();
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  FUN_00401740(s_enemy_monster_009b635c,0xd);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&pvStack_1c);
  if (uStack_8 < 0x10) {
    *in_ECX = &PTR_FUN_009b6448;
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_00510f80 @ 0x00510f80 ====

/* WARNING: Removing unreachable block (ram,0x00510ff5) */
/* WARNING: Removing unreachable block (ram,0x00510fae) */

void FUN_00510f80(int param_1)

{
  FUN_00401740(s_Sequence__IDIRECTOR___>Update_009b636c,0x1d);
  (**(code **)(*DAT_00b5a804 + 4))(*(undefined4 *)(param_1 + 0xc));
  FUN_00401740(s_IHANDLER___>ProcessTime_009b638c,0x17);
  (**(code **)(*DAT_00b5af08 + 4))(*(undefined4 *)(param_1 + 0xc));
  return;
}


// ==== FUN_00511020 @ 0x00511020 ====

void FUN_00511020(int param_1)

{
  undefined4 uVar1;
  undefined1 local_40 [4];
  void *local_3c;
  uint local_28;
  short local_24;
  short local_22;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  local_24 = *(short *)(param_1 + 4);
  if ((local_24 != 0) && (local_22 = *(short *)(param_1 + 6), local_22 != 0)) {
    local_20 = *(undefined4 *)(param_1 + 0x10);
    local_1c = *(undefined4 *)(param_1 + 0x14);
    local_18 = *(undefined4 *)(param_1 + 0x18);
    local_14 = *(undefined4 *)(param_1 + 0x1c);
    local_10 = *(undefined4 *)(param_1 + 0x20);
    local_c = *(undefined4 *)(param_1 + 8);
    local_8 = *(undefined4 *)(param_1 + 0xc);
    local_4 = *(int *)(param_1 + 0x24);
    FUN_00401740(s_______________Receve_NotifySkill_009b63a4,0x26);
    uVar1 = FUN_00404230(local_40);
    FUN_00796d50(uVar1);
    if (0xf < local_28) {
      _free(local_3c);
      return;
    }
    uVar1 = FUN_00513f50(&local_24);
    if (local_4 == 0) {
      (**(code **)(*DAT_00b5af0c + 4))(uVar1);
    }
  }
  return;
}


// ==== FUN_00511100 @ 0x00511100 ====

bool FUN_00511100(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    FUN_00510f80(param_1);
  }
  else if (iVar2 == 0x30060110) {
    FUN_00511020(param_1);
    return true;
  }
  if ((DAT_00b5ae14 != (int *)0x0) &&
     (cVar1 = (**(code **)(*DAT_00b5ae14 + 8))(param_1), cVar1 == '\x01')) {
    return true;
  }
  if ((*(int *)(in_ECX + 4) == 0) ||
     (cVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))(param_1), cVar1 != '\x01')) {
    cVar1 = (**(code **)(*DAT_00b5af18 + 4))(param_1);
    return cVar1 == '\x01';
  }
  return true;
}


// ==== FUN_00511180 @ 0x00511180 ====

void FUN_00511180(void)

{
  int iVar1;
  char cVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  int in_ECX;
  
  FUN_00514930();
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_00511240();
    *puVar3 = &PTR_FUN_009b6498;
  }
  *(undefined4 **)(in_ECX + 8) = puVar3;
  FUN_00514600();
  pvVar4 = operator_new(0x4c);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_005196f0(DAT_00b5a980);
  }
  *(undefined4 *)(in_ECX + 4) = uVar5;
  (**(code **)(*DAT_00b5ae14 + 4))();
  (**(code **)(*DAT_00b5acc0 + 8))();
  iVar1 = *DAT_00b5a804;
  uVar5 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  (**(code **)(iVar1 + 0x10))(uVar5);
  cVar2 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar2 == '\0') {
    puVar3 = operator_new(4);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = &PTR_FUN_009b6458;
      FUN_00797a20(puVar3);
      return;
    }
    FUN_00797a20(0);
  }
  return;
}


// ==== FUN_00511240 @ 0x00511240 ====

void FUN_00511240(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b6490;
  if (DAT_00b5adac == (undefined4 *)0x0) {
    DAT_00b5adac = in_ECX;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_009b63cc,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005112b0 @ 0x005112b0 ====

void FUN_005112b0(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b6490;
  if (DAT_00b5adac != 0) {
    DAT_00b5adac = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_009b63e4,0xc);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00511320 @ 0x00511320 ====

void FUN_00511320(byte param_1)

{
  void *in_ECX;
  
  FUN_005112b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00511340 @ 0x00511340 ====

void FUN_00511340(byte param_1)

{
  void *in_ECX;
  
  FUN_00510ec0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00511360 @ 0x00511360 ====

void FUN_00511360(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b64d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00511380 @ 0x00511380 ====

undefined4 FUN_00511380(int param_1)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_respawn_009b64bc,7);
  if (iVar1 == 0) {
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5060007;
    *(undefined2 *)((int)pvVar2 + 6) = 0x10;
    uVar3 = FUN_004244d0();
    FUN_004d8570(uVar3);
    return 1;
  }
  return 0;
}


// ==== FUN_005113e0 @ 0x005113e0 ====

uint FUN_005113e0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x70004) {
    uVar1 = FUN_00511380(param_1);
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00511410 @ 0x00511410 ====

void FUN_00511410(void)

{
  undefined4 *in_ECX;
  void *unaff_ESI;
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b64e4;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_respawn_009b64ac,7);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_1c,0);
  if (uStack_c < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_00511470 @ 0x00511470 ====

void FUN_00511470(void)

{
  undefined4 *in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b64e4;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_respawn_009b64b4,7);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_1c);
  if (local_8 < 0x10) {
    *in_ECX = &PTR_FUN_009b64d8;
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_005114d0 @ 0x005114d0 ====

void FUN_005114d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00511470();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00511500 @ 0x00511500 ====

void FUN_00511500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6518;
  return;
}


// ==== FUN_00511510 @ 0x00511510 ====

undefined4 FUN_00511510(int param_1)

{
  char cVar1;
  int *piVar2;
  void *pvVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint unaff_EDI;
  undefined1 auStack_1a [26];
  
  cVar1 = *(char *)(param_1 + 0x10);
  if (cVar1 == '\0') {
    puVar4 = operator_new(4);
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_009b6504;
    }
    FUN_00797a20(puVar4);
    iVar5 = (**(code **)(*DAT_00b5ac1c + 0x14))();
    uVar6 = (**(code **)(*DAT_00b5a6ac + 0x20))((undefined4 *)(param_1 + 0x24));
    FUN_00826490(iVar5,uVar6);
    (**(code **)(**(int **)(iVar5 + 0x48) + 0x18))(param_1 + 0x14);
    puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = &PTR_FUN_009b64f0;
      *(undefined2 *)(puVar4 + 1) = 0;
      *(undefined2 *)((int)puVar4 + 6) = 0;
      *(undefined2 *)(puVar4 + 2) = 0;
      *(undefined1 *)((int)puVar4 + 10) = 1;
    }
    puVar4[1] = *(undefined4 *)(param_1 + 0x24);
    *(undefined2 *)(puVar4 + 2) = *(undefined2 *)(param_1 + 0x28);
    *(undefined1 *)((int)puVar4 + 10) = 0;
    FUN_00797a20(puVar4);
  }
  else if (cVar1 == '\x02') {
    pvVar3 = (void *)(**(code **)(*DAT_00b5a794 + 0xc))(8,0x2bc0036);
    FUN_00401660(pvVar3,0,0xffffffff);
    piVar2 = DAT_00b5ad0c;
    FUN_00401660(auStack_1a + -10,0,0xffffffff);
    (**(code **)(*piVar2 + 0x28))(2);
    if (0xf < unaff_EDI) {
      _free(pvVar3);
      return extraout_EAX_00;
    }
  }
  else if (cVar1 == '\x03') {
    pvVar3 = (void *)(**(code **)(*DAT_00b5a794 + 0xc))(9,0x12c0066);
    FUN_00401660(pvVar3,0,0xffffffff);
    piVar2 = DAT_00b5ad0c;
    FUN_00401660(auStack_1a + -10,0,0xffffffff);
    (**(code **)(*piVar2 + 0x28))(2);
    if (0xf < unaff_EDI) {
      _free(pvVar3);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_00511720 @ 0x00511720 ====

uint FUN_00511720(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x50011) {
    uVar1 = FUN_00424500();
    if (uVar1 == 0x5060008) {
      uVar1 = FUN_00511510(param_1[3]);
      if ((char)uVar1 == '\x01') {
        return uVar1;
      }
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00511760 @ 0x00511760 ====

void FUN_00511760(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b64f0;
  *(undefined2 *)(in_ECX + 1) = 0;
  *(undefined2 *)((int)in_ECX + 6) = 0;
  *(undefined2 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 1;
  return;
}


// ==== FUN_00511780 @ 0x00511780 ====

undefined4 FUN_00511780(void)

{
  return 0x50000006;
}


// ==== FUN_00511790 @ 0x00511790 ====

undefined4 FUN_00511790(void)

{
  return 0x70260001;
}


// ==== FUN_005117a0 @ 0x005117a0 ====

undefined1 FUN_005117a0(void)

{
  return 0;
}


// ==== FUN_005117b0 @ 0x005117b0 ====

void FUN_005117b0(void)

{
  undefined4 *in_ECX;
  void *unaff_ESI;
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b6548;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_respawn_009b6524,7);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_1c,0);
  if (uStack_c < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_00511810 @ 0x00511810 ====

void FUN_00511810(void)

{
  undefined4 *in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b6548;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_respawn_009b652c,7);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_1c);
  if (local_8 < 0x10) {
    *in_ECX = &PTR_FUN_009b64d8;
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_00511870 @ 0x00511870 ====

void FUN_00511870(byte param_1)

{
  void *in_ECX;
  
  FUN_00511810();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005118a0 @ 0x005118a0 ====

void FUN_005118a0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  *(undefined4 *)(in_ECX + 0xc) = param_2;
  return;
}


// ==== FUN_005118d0 @ 0x005118d0 ====

void FUN_005118d0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_009b6554;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = uVar1;
  return;
}


// ==== FUN_005118f0 @ 0x005118f0 ====

void FUN_005118f0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0058ed90();
  }
  *(undefined4 *)(iVar2 + 4) = *param_1;
  *(undefined4 *)(iVar2 + 8) = param_1[1];
  *(undefined4 *)(iVar2 + 0xc) = *param_2;
  *(undefined4 *)(iVar2 + 0x10) = param_2[1];
  *(undefined4 *)(iVar2 + 0x14) = param_3;
  *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(in_ECX + 0xc);
  (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar2);
  return;
}


// ==== FUN_00511950 @ 0x00511950 ====

void FUN_00511950(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  puVar2 = operator_new(0x14);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009b6568;
    puVar2[1] = *param_1;
    uVar1 = param_1[1];
    puVar2[3] = param_2;
    puVar2[2] = uVar1;
    puVar2[4] = param_3;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 8))(puVar2);
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_005119b0 @ 0x005119b0 ====

void FUN_005119b0(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 param_4)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  undefined4 *unaff_retaddr;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0058ee20();
  }
  *(undefined4 *)(iVar2 + 4) = *param_3;
  *(undefined4 *)(iVar2 + 8) = param_3[1];
  *(undefined1 *)(iVar2 + 0xc) = 1;
  *(undefined1 *)(iVar2 + 0xd) = param_4;
  (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar2);
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
    iVar2 = FUN_0058edc0(*(undefined4 *)(in_ECX + 8));
  }
  *(undefined4 *)(iVar2 + 8) = *unaff_retaddr;
  *(undefined4 *)(iVar2 + 0xc) = unaff_retaddr[1];
  *(undefined4 *)(iVar2 + 0x10) = unaff_retaddr[2];
  *(undefined4 *)(iVar2 + 0x14) = param_1;
  *(undefined1 *)(iVar2 + 0x18) = 1;
  (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar2);
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_00511a60 @ 0x00511a60 ====

void FUN_00511a60(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined1 param_4)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  undefined4 *unaff_retaddr;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pvVar1 = operator_new(0x18);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0058ee40();
  }
  *(undefined4 *)(iVar2 + 4) = *param_3;
  *(undefined4 *)(iVar2 + 8) = param_3[1];
  *(undefined1 *)(iVar2 + 0xc) = 0;
  *(undefined1 *)(iVar2 + 0xd) = param_4;
  (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar2);
  pvVar1 = operator_new(0x1c);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
    iVar2 = FUN_0058edc0(*(undefined4 *)(in_ECX + 8));
  }
  *(undefined4 *)(iVar2 + 8) = *unaff_retaddr;
  *(undefined4 *)(iVar2 + 0xc) = unaff_retaddr[1];
  *(undefined4 *)(iVar2 + 0x10) = unaff_retaddr[2];
  *(undefined4 *)(iVar2 + 0x14) = param_1;
  *(undefined1 *)(iVar2 + 0x18) = 1;
  (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar2);
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_00511b10 @ 0x00511b10 ====

void FUN_00511b10(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  int in_ECX;
  undefined4 *unaff_retaddr;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  pvVar5 = operator_new(0x18);
  if (pvVar5 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_0058ee40();
  }
  *(undefined4 *)(iVar6 + 4) = *param_2;
  *(undefined4 *)(iVar6 + 8) = param_2[1];
  *(undefined1 *)(iVar6 + 0xc) = 1;
  *(undefined1 *)(iVar6 + 0xd) = 0;
  *(undefined4 *)(iVar6 + 0x10) = param_5;
  *(undefined4 *)(iVar6 + 0x14) = param_6;
  (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar6);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
  uVar1 = *unaff_retaddr;
  uVar2 = unaff_retaddr[1];
  uVar3 = unaff_retaddr[2];
  uVar4 = *(undefined4 *)(in_ECX + 8);
  pvVar5 = operator_new(0x1c);
  if (pvVar5 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_0058eea0();
  }
  *(undefined4 *)(iVar6 + 4) = uVar4;
  *(undefined4 *)(iVar6 + 8) = uVar1;
  *(undefined4 *)(iVar6 + 0xc) = uVar2;
  *(undefined4 *)(iVar6 + 0x10) = uVar3;
  *(undefined4 **)(iVar6 + 0x14) = param_2;
  *(undefined4 *)(iVar6 + 0x18) = param_3;
  (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar6);
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_00511c00 @ 0x00511c00 ====

void FUN_00511c00(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_00511b10(param_1,param_2,param_3,0,param_4,param_5);
  return;
}


// ==== FUN_00511c30 @ 0x00511c30 ====

void FUN_00511c30(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  
  pvVar1 = operator_new(0x5c);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0058eec0();
  }
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00401660(param_2,0,0xffffffff);
  *(undefined4 *)(iVar2 + 0x3c) = *param_3;
  *(undefined4 *)(iVar2 + 0x40) = param_3[1];
  *(undefined4 *)(iVar2 + 0x44) = param_4;
  *(undefined4 *)(iVar2 + 0x48) = param_6;
  *(undefined4 *)(iVar2 + 0x4c) = param_5;
  *(undefined4 *)(iVar2 + 0x50) = param_7;
  *(undefined4 *)(iVar2 + 0x54) = param_8;
  *(undefined4 *)(iVar2 + 0x58) = 0x401;
  (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar2);
  return;
}


// ==== FUN_00511cc0 @ 0x00511cc0 ====

undefined4 FUN_00511cc0(void)

{
  return 0x13;
}


// ==== FUN_00511cd0 @ 0x00511cd0 ====

void FUN_00511cd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6554;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00511cf0 @ 0x00511cf0 ====

void FUN_00511cf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b65ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00511d10 @ 0x00511d10 ====

undefined4 FUN_00511d10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x24);
}


// ==== FUN_00511d20 @ 0x00511d20 ====

undefined4 FUN_00511d20(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}


// ==== FUN_00511d30 @ 0x00511d30 ====

undefined4 FUN_00511d30(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00511d50 @ 0x00511d50 ====

void FUN_00511d50(void)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
  return;
}


// ==== FUN_00511d60 @ 0x00511d60 ====

undefined1 FUN_00511d60(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0xc);
}


// ==== FUN_00511d70 @ 0x00511d70 ====

void FUN_00511d70(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x24) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x24))(1);
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  pvVar1 = operator_new(0x20);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00513180();
  }
  *(undefined4 *)(in_ECX + 0x24) = uVar2;
  FUN_00512c80(in_ECX,in_ECX + 0x14,*(undefined1 *)(in_ECX + 0xf));
  return;
}


// ==== FUN_00511dc0 @ 0x00511dc0 ====

void FUN_00511dc0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x28) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x28))(1);
  }
  *(undefined4 *)(in_ECX + 0x28) = 0;
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x28) = 0;
    FUN_005118a0(in_ECX,param_1);
    return;
  }
  uVar2 = FUN_005118d0();
  *(undefined4 *)(in_ECX + 0x28) = uVar2;
  FUN_005118a0(in_ECX,param_1);
  return;
}


// ==== FUN_00511e20 @ 0x00511e20 ====

void FUN_00511e20(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x24) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x24))(1);
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  if (*(undefined4 **)(in_ECX + 0x28) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x28))(1);
  }
  *(undefined4 *)(in_ECX + 0x28) = 0;
  if (*(int *)(in_ECX + 4) != -1) {
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(in_ECX + 4);
      *puVar2 = &PTR_FUN_009b4b8c;
      puVar2[1] = uVar1;
      FUN_00797a20(puVar2);
      *(undefined4 *)(in_ECX + 4) = 0xffffffff;
      return;
    }
    FUN_00797a20(0);
    *(undefined4 *)(in_ECX + 4) = 0xffffffff;
  }
  return;
}


// ==== FUN_00511ea0 @ 0x00511ea0 ====

void FUN_00511ea0(char param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (*(char *)((int)in_ECX + 0xd) != param_1) {
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      uVar2 = (**(code **)(*in_ECX + 4))();
      *puVar1 = &PTR_FUN_009b65f4;
      puVar1[1] = uVar2;
    }
    *(char *)(puVar1 + 2) = param_1;
    FUN_00797a20(puVar1);
    *(char *)((int)in_ECX + 0xd) = param_1;
  }
  return;
}


// ==== FUN_00511ef0 @ 0x00511ef0 ====

void FUN_00511ef0(char param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (*(char *)((int)in_ECX + 0xe) != param_1) {
    puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      uVar2 = (**(code **)(*in_ECX + 4))();
      *puVar1 = &PTR_FUN_009b660c;
      puVar1[1] = uVar2;
    }
    *(char *)(puVar1 + 2) = param_1;
    FUN_00797a20(puVar1);
    *(char *)((int)in_ECX + 0xe) = param_1;
  }
  return;
}


// ==== FUN_00511f40 @ 0x00511f40 ====

void FUN_00511f40(char param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *in_ECX;
  undefined4 uStack_4;
  
  if ((char)in_ECX[3] != param_1) {
    uVar1 = (**(code **)(*in_ECX + 4))();
    uStack_4 = CONCAT31(uStack_4._1_3_,param_1);
    puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b65dc;
    }
    puVar2[1] = uVar1;
    puVar2[2] = uStack_4;
    FUN_00797a20(puVar2);
    *(char *)(in_ECX + 3) = param_1;
  }
  return;
}


// ==== FUN_00511fa0 @ 0x00511fa0 ====

void FUN_00511fa0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6624;
  FUN_00511e20();
  if ((void *)in_ECX[0xd] == (void *)0x0) {
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    *in_ECX = &PTR_FUN_009b65ac;
    return;
  }
  _free((void *)in_ECX[0xd]);
  return;
}


// ==== FUN_00511fe0 @ 0x00511fe0 ====

void FUN_00511fe0(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  undefined4 *puVar6;
  int *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (in_ECX[1] == -1) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18._1_3_ << 8);
    FUN_00401740(s_m_dwOwnerID____IDNONE_009b6574,0x15);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar5 = (code *)swi(3);
      (*pcVar5)();
      return;
    }
    _free(local_18);
    return;
  }
  if (in_ECX[9] != 0) {
    puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      iVar3 = in_ECX[1];
      *puVar6 = &PTR_FUN_009b65c4;
      puVar6[1] = iVar3;
      puVar6[10] = 0x11;
      *(undefined2 *)(puVar6 + 0xb) = 0;
      puVar6[0xc] = 0;
    }
    uVar1 = *(undefined1 *)((int)in_ECX + 0xd);
    uVar2 = *(undefined1 *)((int)in_ECX + 0x11);
    iVar3 = in_ECX[4];
    puVar6[2] = 1;
    *(undefined1 *)(puVar6 + 3) = uVar1;
    puVar6[4] = *param_1;
    puVar6[5] = param_1[1];
    puVar6[6] = *param_2;
    uVar4 = param_2[1];
    puVar6[8] = param_3;
    puVar6[7] = uVar4;
    puVar6[9] = param_4;
    puVar6[10] = in_ECX[5];
    puVar6[0xb] = in_ECX[6];
    puVar6[0xc] = in_ECX[2];
    *(undefined1 *)((int)puVar6 + 0x35) = uVar2;
    *(char *)(puVar6 + 0xd) = (char)iVar3;
    FUN_00797a20(puVar6);
    (**(code **)(*in_ECX + 0x10))();
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18._1_3_ << 8);
  FUN_00401740(s_m_pRemoteBodyMgr____NULL_009b658c,0x18);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar5 = (code *)swi(3);
    (*pcVar5)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00512130 @ 0x00512130 ====

void FUN_00512130(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 *param_6,undefined4 *param_7,undefined1 param_8,
                 undefined1 param_9,undefined1 param_10)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  *(undefined4 *)(in_ECX + 0x14) = *param_6;
  *(undefined4 *)(in_ECX + 0x18) = param_6[1];
  *(undefined4 *)(in_ECX + 0x1c) = *param_6;
  *(undefined4 *)(in_ECX + 0x20) = param_6[1];
  *(undefined4 *)(in_ECX + 8) = *param_7;
  *(undefined1 *)(in_ECX + 0x11) = param_10;
  *(undefined1 *)(in_ECX + 0xd) = param_8;
  *(undefined1 *)(in_ECX + 0x10) = param_9;
  if (*(undefined4 **)(in_ECX + 0x24) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x24))(1);
  }
  *(undefined4 *)(in_ECX + 0x24) = 0;
  pvVar1 = operator_new(0x20);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00513180();
  }
  *(undefined4 *)(in_ECX + 0x24) = uVar2;
  FUN_00512c80(in_ECX,in_ECX + 0x14,*(undefined1 *)(in_ECX + 0xf));
  FUN_00511dc0(param_5);
  FUN_00511fe0(param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_005121e0 @ 0x005121e0 ====

void FUN_005121e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6624;
  in_ECX[1] = 0xffffffff;
  in_ECX[2] = 0;
  *(undefined1 *)((int)in_ECX + 0xd) = 0;
  *(undefined1 *)((int)in_ECX + 0xf) = 0;
  *(undefined1 *)(in_ECX + 3) = 1;
  *(undefined1 *)((int)in_ECX + 0xe) = 1;
  in_ECX[5] = 0x11;
  *(undefined2 *)(in_ECX + 6) = 0;
  in_ECX[7] = 0x11;
  *(undefined2 *)(in_ECX + 8) = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 1;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  return;
}


// ==== FUN_00512230 @ 0x00512230 ====

void FUN_00512230(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  if (0 < *(int *)(in_ECX + 0x2c)) {
    FUN_00512700(&param_1);
    return;
  }
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  puVar3 = (undefined4 *)0x0;
  if (puVar2 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(in_ECX + 4);
    *puVar2 = &PTR_FUN_009b663c;
    puVar2[1] = uVar1;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar3 = puVar2;
  }
  FUN_00512750(param_1);
  FUN_00797a20(puVar3);
  return;
}


// ==== FUN_00512290 @ 0x00512290 ====

void FUN_00512290(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  undefined4 *puStack_c;
  undefined4 uStack_8;
  undefined4 *local_4;
  
  *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + -1;
  if (((*(int *)(in_ECX + 0x2c) < 1) && (*(int *)(in_ECX + 0x34) != 0)) &&
     (local_4 = (undefined4 *)(*(int *)(in_ECX + 0x38) - *(int *)(in_ECX + 0x34) >> 2),
     local_4 != (undefined4 *)0x0)) {
    puStack_c = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puStack_c == (undefined4 *)0x0) {
      puStack_c = (undefined4 *)0x0;
    }
    else {
      uVar1 = *(undefined4 *)(in_ECX + 4);
      *puStack_c = &PTR_FUN_009b663c;
      puStack_c[1] = uVar1;
      puStack_c[3] = 0;
      puStack_c[4] = 0;
      puStack_c[5] = 0;
    }
    local_4 = *(undefined4 **)(in_ECX + 0x38);
    puVar4 = *(undefined4 **)(in_ECX + 0x34);
    if (puVar4 != local_4) {
      do {
        iVar2 = puStack_c[3];
        uStack_8 = *puVar4;
        if ((iVar2 == 0) || ((uint)(puStack_c[5] - iVar2 >> 2) <= (uint)(puStack_c[4] - iVar2 >> 2))
           ) {
          FUN_00512430(puStack_c[4],1,&uStack_8);
        }
        else {
          puVar3 = (undefined4 *)puStack_c[4];
          *puVar3 = uStack_8;
          puStack_c[4] = puVar3 + 1;
        }
        puVar4 = puVar4 + 1;
      } while (puVar4 != local_4);
    }
    if (*(void **)(in_ECX + 0x34) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x34));
      return;
    }
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    FUN_00797a20(puStack_c);
  }
  return;
}


// ==== FUN_005123a0 @ 0x005123a0 ====

undefined4 FUN_005123a0(void)

{
  return 0x60020001;
}


// ==== FUN_005123b0 @ 0x005123b0 ====

undefined4 FUN_005123b0(void)

{
  return 0x60060010;
}


// ==== FUN_005123c0 @ 0x005123c0 ====

undefined4 FUN_005123c0(void)

{
  return 0x60060011;
}


// ==== FUN_005123d0 @ 0x005123d0 ====

undefined4 FUN_005123d0(void)

{
  return 0x60060012;
}


// ==== FUN_005123e0 @ 0x005123e0 ====

void FUN_005123e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6624;
  FUN_00511e20();
  if ((void *)in_ECX[0xd] != (void *)0x0) {
    _free((void *)in_ECX[0xd]);
    return;
  }
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  *in_ECX = &PTR_FUN_009b65ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00512430 @ 0x00512430 ====

void FUN_00512430(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_009816d0;
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


// ==== Catch@00512591 @ 0x00512591 ====

void Catch_00512591(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_00512680 @ 0x00512680 ====

undefined4 FUN_00512680(void)

{
  return 0x60060013;
}


// ==== FUN_00512690 @ 0x00512690 ====

void FUN_00512690(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b663c;
  FUN_004eb890(in_ECX + 2);
  FUN_00412dc0();
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_005126d0 @ 0x005126d0 ====

undefined1 FUN_005126d0(int *param_1,int *param_2,undefined1 param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 1) {
    if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*param_1)(1);
    }
  }
  return param_3;
}


// ==== FUN_00512700 @ 0x00512700 ====

void FUN_00512700(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_00512430(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_00512750 @ 0x00512750 ====

void FUN_00512750(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x14) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0x10) - iVar1 >> 2)))
  {
    FUN_00512430(*(undefined4 *)(in_ECX + 0x10),1,&param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x10);
  *puVar2 = param_1;
  *(undefined4 **)(in_ECX + 0x10) = puVar2 + 1;
  return;
}


// ==== FUN_005127a0 @ 0x005127a0 ====

void FUN_005127a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0058ef90();
  }
  *(undefined4 *)(iVar2 + 4) = param_1;
  *(undefined4 *)(iVar2 + 8) = param_2;
  *(undefined4 *)(iVar2 + 0xc) = param_3;
  (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar2);
  return;
}


// ==== FUN_005127e0 @ 0x005127e0 ====

void FUN_005127e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b66e4;
  if (0xf < (uint)in_ECX[0xf]) {
    _free((void *)in_ECX[10]);
    return;
  }
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[7] = 0;
    in_ECX[8] = 0xf;
    *(undefined1 *)(in_ECX + 3) = 0;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00512830 @ 0x00512830 ====

void FUN_00512830(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b66e4;
  in_ECX[1] = 0;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401740(&DAT_009b6652,0);
  in_ECX[0xf] = 0xf;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  FUN_00401740(&DAT_009b6653,0);
  in_ECX[0x10] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *(undefined1 *)((int)in_ECX + 0x45) = 0;
  *(undefined2 *)(in_ECX + 0x13) = 0;
  in_ECX[0x12] = 0x11;
  return;
}


// ==== FUN_00512890 @ 0x00512890 ====

void FUN_00512890(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 4) == 0) {
    local_20 = 0xf;
    local_24 = 0;
    local_34 = (void *)((uint)local_34 & 0xffffff00);
    FUN_00401740(s_____Model2_RemoteDoll_RemoteBody_009b6654,0x34);
    uVar1 = FUN_004022a0(local_1c,s_DollCommandSender_Not_Set_____Mo_009b6690,local_38);
    FUN_00796d50(uVar1);
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    if (0xf < local_20) {
      _free(local_34);
      return;
    }
  }
  else {
    pvVar2 = operator_new(0x50);
    if (pvVar2 == (void *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = FUN_0058f030();
    }
    FUN_0058f0a0(in_ECX + 8,in_ECX + 0x24,*(undefined4 *)(in_ECX + 0x40),in_ECX + 0x48,
                 *(undefined1 *)(in_ECX + 0x44),(float)*(byte *)(in_ECX + 0x45));
    (**(code **)(**(int **)(in_ECX + 4) + 8))(uVar1);
  }
  return;
}


// ==== FUN_00512970 @ 0x00512970 ====

void FUN_00512970(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(0x20);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b66ec;
    puVar1[7] = 0xf;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
  }
  FUN_00401660(in_ECX + 8,0,0xffffffff);
  (**(code **)(**(int **)(in_ECX + 4) + 8))(puVar1);
  return;
}


// ==== FUN_005129c0 @ 0x005129c0 ====

void FUN_005129c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  
  pvVar1 = operator_new(0x2c);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0058f130();
  }
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(iVar2 + 4) = param_2;
  *(undefined4 *)(iVar2 + 8) = param_3;
  *(undefined4 *)(iVar2 + 0xc) = param_4;
  (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar2);
  return;
}


// ==== FUN_00512a20 @ 0x00512a20 ====

void FUN_00512a20(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  pvVar2 = operator_new(0x34);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0058f1f0(in_ECX + 8);
  }
  *(undefined4 *)(iVar3 + 0x20) = 2;
  iVar1 = *(int *)(param_1 + 8);
  for (iVar4 = *(int *)(param_1 + 4); iVar4 != iVar1; iVar4 = iVar4 + 0x44) {
    FUN_004ff800(iVar4);
  }
  (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar3);
  return;
}


// ==== FUN_00512a90 @ 0x00512a90 ====

void FUN_00512a90(undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_44;
  undefined1 local_43;
  undefined1 local_42;
  undefined1 local_41;
  undefined4 local_40;
  undefined4 local_3c;
  void *local_38;
  undefined1 local_34;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  undefined1 local_18;
  undefined4 uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_20 = 0xf;
  local_24 = 0;
  local_34 = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  local_41 = 0;
  local_44 = 0;
  local_43 = 0;
  local_42 = 0;
  local_3c = DAT_0099d080;
  local_40 = 0xffffffff;
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00401660(param_2,0,0xffffffff);
  local_41 = param_3;
  local_44 = param_4;
  pvVar1 = operator_new(0x34);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0058f1f0(in_ECX + 8);
  }
  *(undefined4 *)(iVar2 + 0x20) = 0;
  FUN_004ff800(&local_44);
  (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar2);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  local_8 = 0xf;
  if (local_24 < 0x10) {
    return;
  }
  _free(local_38);
  return;
}


// ==== FUN_00512b90 @ 0x00512b90 ====

void FUN_00512b90(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_34;
  uint local_20;
  void *local_18;
  uint local_4;
  
  pvVar1 = operator_new(0x34);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0058f1f0(in_ECX + 8);
  }
  *(undefined4 *)(iVar2 + 0x20) = 1;
  uVar3 = FUN_004fecb0(param_1,param_2);
  FUN_004ff800(uVar3);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  if (local_20 < 0x10) {
    (**(code **)(**(int **)(in_ECX + 4) + 8))(iVar2);
    return;
  }
  _free(local_34);
  return;
}


// ==== FUN_00512c30 @ 0x00512c30 ====

void FUN_00512c30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b66ec;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00512c60 @ 0x00512c60 ====

void FUN_00512c60(byte param_1)

{
  void *in_ECX;
  
  FUN_005127e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00512c80 @ 0x00512c80 ====

void FUN_00512c80(undefined4 param_1,undefined4 *param_2,undefined1 param_3)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  *(undefined4 *)(in_ECX + 4) = *param_2;
  *(undefined4 *)(in_ECX + 8) = param_2[1];
  *(undefined1 *)(in_ECX + 0xc) = param_3;
  return;
}


// ==== FUN_00512ca0 @ 0x00512ca0 ====

undefined4 FUN_00512ca0(int param_1)

{
  int in_ECX;
  
  FUN_0069a470(&param_1,param_1);
  if (param_1 == *(int *)(in_ECX + 0x18)) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x28);
}


// ==== FUN_00512cd0 @ 0x00512cd0 ====

undefined4 FUN_00512cd0(void)

{
  char cVar1;
  char *pcVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined4 uVar3;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  pcVar2 = PTR_DAT_00aebd7c;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_DAT_00aebd7c,(int)pcVar2 - (int)(PTR_DAT_00aebd7c + 1));
  FUN_0069a470(&local_20,local_1c);
  if (local_20 == *(int *)(in_ECX + 0x18)) {
    uVar3 = 0;
  }
  else {
    uVar3 = *(undefined4 *)(local_20 + 0x28);
  }
  if (local_4 < 0x10) {
    return uVar3;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_00512d50 @ 0x00512d50 ====

void FUN_00512d50(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  FUN_0069a470(&param_1,param_1);
  iVar2 = param_1;
  if (param_1 != *(int *)(in_ECX + 0x18)) {
    puVar1 = *(undefined4 **)(param_1 + 0x28);
    FUN_00512970();
    if (puVar1 != (undefined4 *)0x0) {
      (**(code **)*puVar1)(1);
    }
    FUN_005a4100(&param_1,iVar2);
  }
  return;
}


// ==== FUN_00512da0 @ 0x00512da0 ====

void FUN_00512da0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 0x18);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    puVar4 = (undefined4 *)puVar3[10];
    FUN_00512970();
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    if (*(char *)((int)puVar3 + 0x2d) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x2d);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x2d);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x2d);
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x2d);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  FUN_00513270(*(undefined4 *)(*(int *)(in_ECX + 0x18) + 4));
  *(int *)(*(int *)(in_ECX + 0x18) + 4) = *(int *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x18);
  *(int *)(*(int *)(in_ECX + 0x18) + 8) = *(int *)(in_ECX + 0x18);
  return;
}


// ==== FUN_00512e40 @ 0x00512e40 ====

void FUN_00512e40(undefined4 param_1,undefined4 *param_2)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  int local_4;
  
  pvVar1 = operator_new(0x50);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00512830();
  }
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = iVar2;
  FUN_00513600(local_28,local_20);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(in_ECX + 0x10);
  FUN_00401660(param_1,0,0xffffffff);
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(&DAT_009b66f6,0);
  FUN_00401660(local_20,0,0xffffffff);
  if (local_8 < 0x10) {
    *(undefined4 *)(iVar2 + 0x40) = 0;
    *(undefined4 *)(iVar2 + 0x48) = *param_2;
    *(undefined4 *)(iVar2 + 0x4c) = param_2[1];
    *(undefined1 *)(iVar2 + 0x44) = *(undefined1 *)(in_ECX + 0xc);
    *(undefined1 *)(iVar2 + 0x45) = 0;
    FUN_00512890();
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_00512f40 @ 0x00512f40 ====

void FUN_00512f40(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  int local_4;
  
  pvVar1 = operator_new(0x50);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00512830();
  }
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = iVar2;
  FUN_00513600(local_28,local_20);
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(in_ECX + 0x10);
  FUN_00401660(param_1,0,0xffffffff);
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(&DAT_009b66f7,0);
  FUN_00401660(local_20,0,0xffffffff);
  if (local_8 < 0x10) {
    *(undefined4 *)(iVar2 + 0x40) = 0;
    *(undefined4 *)(iVar2 + 0x48) = *(undefined4 *)(in_ECX + 4);
    *(undefined4 *)(iVar2 + 0x4c) = *(undefined4 *)(in_ECX + 8);
    *(undefined1 *)(iVar2 + 0x44) = *(undefined1 *)(in_ECX + 0xc);
    *(undefined1 *)(iVar2 + 0x45) = 0;
    FUN_00512890();
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_00513030 @ 0x00513030 ====

void FUN_00513030(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  void *pvVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_28 [8];
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  int local_4;
  
  pvVar1 = operator_new(0x50);
  if (pvVar1 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00512830();
  }
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = iVar2;
  FUN_00513600(local_28,local_20);
  if (local_8 < 0x10) {
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(in_ECX + 0x10);
    FUN_00401660(param_1,0,0xffffffff);
    FUN_00401660(param_2,0,0xffffffff);
    *(undefined4 *)(iVar2 + 0x40) = param_3;
    *(undefined4 *)(iVar2 + 0x48) = *param_4;
    *(undefined4 *)(iVar2 + 0x4c) = param_4[1];
    *(undefined1 *)(iVar2 + 0x44) = 1;
    *(undefined1 *)(iVar2 + 0x45) = param_5;
    FUN_00512890();
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_00513100 @ 0x00513100 ====

void FUN_00513100(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_009b6704;
  local_4 = in_ECX;
  if (in_ECX[7] != 0) {
    local_4 = (undefined4 *)((uint)in_ECX & 0xffffff00);
    FUN_0082c4f0(*(undefined4 *)in_ECX[6],(undefined4 *)in_ECX[6],local_4);
    FUN_00513270(*(undefined4 *)(in_ECX[6] + 4));
    *(undefined4 *)(in_ECX[6] + 4) = in_ECX[6];
    in_ECX[7] = 0;
    *(undefined4 *)in_ECX[6] = in_ECX[6];
    *(undefined4 *)(in_ECX[6] + 8) = in_ECX[6];
  }
  FUN_00513540(&local_4,*(undefined4 *)in_ECX[6],(undefined4 *)in_ECX[6]);
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00513180 @ 0x00513180 ====

void FUN_00513180(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6704;
  in_ECX[1] = 0x11;
  *(undefined2 *)(in_ECX + 2) = 0;
  iVar1 = FUN_005131d0();
  in_ECX[6] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[6] + 4) = in_ECX[6];
  *(undefined4 *)in_ECX[6] = in_ECX[6];
  *(undefined4 *)(in_ECX[6] + 8) = in_ECX[6];
  in_ECX[7] = 0;
  return;
}


// ==== FUN_005131d0 @ 0x005131d0 ====

void FUN_005131d0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009816e0;
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


// ==== Catch@0051325a @ 0x0051325a ====

void Catch_0051325a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00513270 @ 0x00513270 ====

void FUN_00513270(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) != '\0') {
    return;
  }
  FUN_00513270(*(undefined4 *)((int)param_1 + 8));
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


// ==== FUN_005132d0 @ 0x005132d0 ====

void * FUN_005132d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009816f0;
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


// ==== Catch@00513345 @ 0x00513345 ====

void Catch_00513345(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00513360 @ 0x00513360 ====

void FUN_00513360(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_005132d0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00513465:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_00513465;
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


// ==== FUN_00513540 @ 0x00513540 ====

void FUN_00513540(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00513270(piVar6[1]);
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


// ==== FUN_00513600 @ 0x00513600 ====

/* WARNING: Removing unreachable block (ram,0x0051365f) */

void FUN_00513600(undefined4 *param_1,undefined4 *param_2)

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
LAB_00513690:
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
        if (uVar5 == 0) goto LAB_00513690;
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
      puVar6 = (undefined4 *)FUN_00513360(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_00513360(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_00513770 @ 0x00513770 ====

void FUN_00513770(byte param_1)

{
  void *in_ECX;
  
  FUN_00513100();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00513790 @ 0x00513790 ====

void FUN_00513790(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b670c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005137f0 @ 0x005137f0 ====

void FUN_005137f0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6718;
  if (DAT_00b5af1c == 0) {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      FUN_0051b610();
    }
  }
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0051ad70();
  }
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(4);
  if (pvVar1 == (void *)0x0) {
    in_ECX[2] = 0;
    return;
  }
  uVar2 = FUN_0051b110();
  in_ECX[2] = uVar2;
  return;
}


// ==== FUN_00513860 @ 0x00513860 ====

void FUN_00513860(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6718;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if (DAT_00b5af1c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af1c)(1);
  }
  *in_ECX = &PTR_FUN_009b670c;
  return;
}


// ==== FUN_005138b0 @ 0x005138b0 ====

undefined4 FUN_005138b0(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  
  piVar1 = param_1;
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 == 0x40001) {
    param_1 = (int *)piVar1[3];
    FUN_0051b410(&param_1);
  }
  else if (iVar3 == 0x50011) {
    cVar2 = FUN_0051aae0(piVar1);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  else if (iVar3 == 0x70004) {
    cVar2 = FUN_0051b3a0(piVar1);
    if (cVar2 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00513920 @ 0x00513920 ====

void FUN_00513920(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6718;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if (DAT_00b5af1c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af1c)(1);
  }
  *in_ECX = &PTR_FUN_009b670c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005139b0 @ 0x005139b0 ====

void FUN_005139b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6724;
  return;
}


// ==== FUN_005139c0 @ 0x005139c0 ====

undefined4 FUN_005139c0(int param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (*(int *)(param_1 + 8) != 0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x18) != 3) {
    if (*(int *)(param_1 + 0x18) != 2) {
      return 0;
    }
    local_4 = *(undefined4 *)(param_1 + 0x34);
    local_8 = *(undefined4 *)(param_1 + 0x30);
    local_c = *(undefined4 *)(param_1 + 0x3c);
    local_10 = *(undefined4 *)(param_1 + 0x38);
    (**(code **)(*DAT_00b5aea4 + 0x14))(&local_8,&local_10);
  }
  return 1;
}


// ==== FUN_00513a90 @ 0x00513a90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00513a90(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    if (param_1[2] == 5) {
      (**(code **)(*DAT_00b5aea4 + 0x18))(0x40970a3d,0x3f0ccccd,0x41900000);
    }
  }
  else if (iVar2 == 0x10003) {
    cVar1 = FUN_005139c0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if ((iVar2 == 0x10010) && (param_1[2] != 3)) {
    (**(code **)(*DAT_00b5aea4 + 0x1c))((float)(int)(short)param_1[1] * _DAT_009b632c);
    return 1;
  }
  return 0;
}


// ==== FUN_00513b20 @ 0x00513b20 ====

void FUN_00513b20(void)

{
  void *pvVar1;
  
  if (DAT_00b5ae14 == 0) {
    pvVar1 = operator_new(0x24);
    if (pvVar1 != (void *)0x0) {
      FUN_0051d2a0();
      return;
    }
  }
  return;
}


// ==== FUN_00513b40 @ 0x00513b40 ====

void FUN_00513b40(void)

{
  if (DAT_00b5ae14 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ae14)(1);
  }
  return;
}


// ==== FUN_00513b60 @ 0x00513b60 ====

undefined4 FUN_00513b60(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_0051f230(param_1);
  return uVar2;
}


// ==== FUN_00513b80 @ 0x00513b80 ====

void FUN_00513b80(void)

{
  if (DAT_00b5ad5c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ad5c)(1);
  }
  return;
}


// ==== FUN_00513ba0 @ 0x00513ba0 ====

void FUN_00513ba0(void)

{
  void *pvVar1;
  
  if (DAT_00b5ad5c == 0) {
    pvVar1 = operator_new(0x30);
    if (pvVar1 != (void *)0x0) {
      FUN_00513ed0();
      return;
    }
  }
  return;
}


// ==== FUN_00513bc0 @ 0x00513bc0 ====

void FUN_00513bc0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981700;
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


// ==== Catch@00513c2f @ 0x00513c2f ====

void Catch_00513c2f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00513c50 @ 0x00513c50 ====

void FUN_00513c50(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981710;
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


// ==== Catch@00513cb6 @ 0x00513cb6 ====

void Catch_00513cb6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00513cc0 @ 0x00513cc0 ====

int FUN_00513cc0(int param_1,int param_2,undefined4 param_3)

{
  FUN_00513c50(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_00513cf0 @ 0x00513cf0 ====

void FUN_00513cf0(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b6770;
  if (DAT_00b5ad5c == (undefined4 *)0x0) {
    DAT_00b5ad5c = in_ECX;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_009b6744,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00513d60 @ 0x00513d60 ====

void FUN_00513d60(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b6770;
  if (DAT_00b5ad5c != 0) {
    DAT_00b5ad5c = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_009b675c,0xc);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00513dd0 @ 0x00513dd0 ====

void FUN_00513dd0(byte param_1)

{
  void *in_ECX;
  
  FUN_00513d60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00513df0 @ 0x00513df0 ====

void FUN_00513df0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6778;
  FUN_00513d60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00513e20 @ 0x00513e20 ====

void FUN_00513e20(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981720;
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
    uVar2 = FUN_00513cc0(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00513eb4 @ 0x00513eb4 ====

void Catch_00513eb4(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00513ed0 @ 0x00513ed0 ====

void FUN_00513ed0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  FUN_00513cf0();
  *in_ECX = &PTR_FUN_009b679c;
  in_ECX[1] = 0;
  *(undefined1 *)(in_ECX + 2) = local_5;
  uVar1 = FUN_00513bc0();
  in_ECX[4] = uVar1;
  in_ECX[5] = 0;
  local_4 = in_ECX[4];
  FUN_00513e20(9,&local_4);
  in_ECX[10] = 1;
  in_ECX[0xb] = 1;
  return;
}


// ==== FUN_00513f30 @ 0x00513f30 ====

void FUN_00513f30(byte param_1)

{
  void *in_ECX;
  
  FUN_0051f950();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00513f50 @ 0x00513f50 ====

undefined4 FUN_00513f50(short *param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  if ((*param_1 != 0) && (param_1[1] != 0)) {
    pvVar1 = operator_new(0x30);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_005201c0(param_1);
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_00513f80 @ 0x00513f80 ====

void FUN_00513f80(void)

{
  if (DAT_00b5af0c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af0c)(1);
  }
  if (DAT_00b5af08 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af08)(1);
  }
  return;
}


// ==== FUN_00513fb0 @ 0x00513fb0 ====

void FUN_00513fb0(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  
  if ((DAT_00b5af0c == 0) && (pvVar1 = operator_new(0x2c), pvVar1 != (void *)0x0)) {
    FUN_00514460();
  }
  if ((DAT_00b5af08 == 0) && (puVar2 = operator_new(4), puVar2 != (undefined4 *)0x0)) {
    FUN_00514210();
    *puVar2 = &PTR_FUN_009b6848;
  }
  return;
}


// ==== FUN_00514000 @ 0x00514000 ====

void FUN_00514000(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981730;
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


// ==== Catch@0051406f @ 0x0051406f ====

void Catch_0051406f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00514090 @ 0x00514090 ====

void FUN_00514090(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981740;
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


// ==== Catch@005140f6 @ 0x005140f6 ====

void Catch_005140f6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00514100 @ 0x00514100 ====

int FUN_00514100(int param_1,int param_2,undefined4 param_3)

{
  FUN_00514090(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_00514130 @ 0x00514130 ====

void FUN_00514130(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b6814;
  if (DAT_00b5af0c == (undefined4 *)0x0) {
    DAT_00b5af0c = in_ECX;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_009b67c0,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005141a0 @ 0x005141a0 ====

void FUN_005141a0(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b6814;
  if (DAT_00b5af0c != 0) {
    DAT_00b5af0c = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_009b67d8,0xc);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00514210 @ 0x00514210 ====

void FUN_00514210(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b681c;
  if (DAT_00b5af08 == (undefined4 *)0x0) {
    DAT_00b5af08 = in_ECX;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_009b67e8,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_00514280 @ 0x00514280 ====

void FUN_00514280(void)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b681c;
  if (DAT_00b5af08 != 0) {
    DAT_00b5af08 = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_009b6800,0xc);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005142f0 @ 0x005142f0 ====

void FUN_005142f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005141a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00514310 @ 0x00514310 ====

void FUN_00514310(byte param_1)

{
  void *in_ECX;
  
  FUN_00514280();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00514330 @ 0x00514330 ====

void FUN_00514330(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6824;
  FUN_005141a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00514360 @ 0x00514360 ====

void FUN_00514360(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b683c;
  FUN_00514280();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00514390 @ 0x00514390 ====

void FUN_00514390(byte param_1)

{
  void *in_ECX;
  
  FUN_005202d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005143b0 @ 0x005143b0 ====

void FUN_005143b0(uint param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981750;
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
    uVar2 = FUN_00514100(*(undefined4 *)(in_ECX + 4),param_1,param_2);
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00514444 @ 0x00514444 ====

void Catch_00514444(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00514460 @ 0x00514460 ====

void FUN_00514460(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_5;
  undefined4 local_4;
  
  FUN_00514130();
  *in_ECX = &PTR_FUN_009b6854;
  *(undefined1 *)(in_ECX + 1) = local_5;
  uVar1 = FUN_00514000();
  in_ECX[3] = uVar1;
  in_ECX[4] = 0;
  local_4 = in_ECX[3];
  FUN_005143b0(9,&local_4);
  in_ECX[9] = 1;
  in_ECX[10] = 1;
  return;
}


// ==== FUN_005144c0 @ 0x005144c0 ====

void FUN_005144c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00520480();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005144e0 @ 0x005144e0 ====

void FUN_005144e0(void)

{
  void *pvVar1;
  
  if (DAT_00b5acd8 == 0) {
    pvVar1 = operator_new(0x14);
    if (pvVar1 != (void *)0x0) {
      FUN_005214a0();
    }
  }
  if (DAT_00b5af18 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_00520b80();
      return;
    }
  }
  return;
}


// ==== FUN_00514520 @ 0x00514520 ====

void FUN_00514520(void)

{
  if (DAT_00b5acd8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5acd8)(1);
  }
  if (DAT_00b5af18 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af18)(1);
  }
  return;
}


// ==== FUN_00514550 @ 0x00514550 ====

void FUN_00514550(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6880;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00514570 @ 0x00514570 ====

void FUN_00514570(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00514580 @ 0x00514580 ====

undefined1 FUN_00514580(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_00514590 @ 0x00514590 ====

undefined4 FUN_00514590(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_005145a0 @ 0x005145a0 ====

void FUN_005145a0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_005145b0 @ 0x005145b0 ====

void FUN_005145b0(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x10))(0);
  (**(code **)(*in_ECX + 4))(0);
  return;
}


// ==== FUN_00514600 @ 0x00514600 ====

void FUN_00514600(void)

{
  undefined4 *puVar1;
  
  if (DAT_00b5af10 == (undefined4 *)0x0) {
    puVar1 = operator_new(0xc);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009b689c;
      *(undefined1 *)(puVar1 + 1) = 0;
      if (puVar1 + 1 != (undefined4 *)0x0) {
        DAT_00b5af10 = puVar1;
        return;
      }
      DAT_00b5af10 = (undefined4 *)0x0;
    }
  }
  return;
}


// ==== FUN_00514640 @ 0x00514640 ====

void FUN_00514640(void)

{
  if (DAT_00b5af10 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af10)(1);
  }
  return;
}


// ==== FUN_00514680 @ 0x00514680 ====

void FUN_00514680(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5af10 = 0;
  *in_ECX = &PTR_FUN_009b6880;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005146b0 @ 0x005146b0 ====

void FUN_005146b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b68f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005146d0 @ 0x005146d0 ====

int * FUN_005146d0(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  void *pvVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *unaff_retaddr;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00521a30();
  }
  piVar3 = (int *)(**(code **)(*piVar2 + 0x14))();
  (**(code **)(*piVar3 + 0xc))(param_3);
  FUN_00521de0(param_4);
  iVar4 = (**(code **)(*piVar2 + 0x10))();
  *(undefined4 *)(iVar4 + 0x28) = 0;
  *(undefined4 *)(iVar4 + 0x2c) = 0;
  *(undefined4 *)(iVar4 + 0x18) = *unaff_retaddr;
  *(undefined4 *)(iVar4 + 0x1c) = unaff_retaddr[1];
  *(undefined4 *)(iVar4 + 0x20) = *param_1;
  *(undefined4 *)(iVar4 + 0x24) = param_1[1];
  iVar4 = (**(code **)(*param_4 + 0x20))();
  FUN_00521af0(*(undefined4 *)(iVar4 + 8));
  return piVar2;
}


// ==== FUN_00514760 @ 0x00514760 ====

int * FUN_00514760(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                  int *param_5)

{
  void *pvVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00522290();
  }
  piVar3 = (int *)(**(code **)(*piVar2 + 0x14))();
  (**(code **)(*piVar3 + 0xc))(param_1);
  FUN_00522510(param_2);
  FUN_00522590(param_5);
  iVar4 = (**(code **)(*piVar2 + 0x10))();
  *(undefined4 *)(iVar4 + 0x28) = 0;
  *(undefined4 *)(iVar4 + 0x2c) = 0;
  *(undefined4 *)(iVar4 + 0x18) = *param_3;
  *(undefined4 *)(iVar4 + 0x1c) = param_3[1];
  *(undefined4 *)(iVar4 + 0x20) = *param_4;
  *(undefined4 *)(iVar4 + 0x24) = param_4[1];
  iVar4 = (**(code **)(*param_5 + 0x1c))();
  FUN_00522370(*(undefined4 *)(iVar4 + 8));
  return piVar2;
}


// ==== FUN_00514820 @ 0x00514820 ====

void FUN_00514820(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00522be0(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_00514930 @ 0x00514930 ====

void FUN_00514930(void)

{
  undefined4 *puVar1;
  
  if (DAT_00b5adf8 == (undefined4 *)0x0) {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009b6930;
      if (puVar1 != (undefined4 *)0xfffffffc) {
        DAT_00b5adf8 = puVar1;
        return;
      }
      DAT_00b5adf8 = (undefined4 *)0x0;
    }
  }
  return;
}


// ==== FUN_00514970 @ 0x00514970 ====

void FUN_00514970(void)

{
  if (DAT_00b5adf8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5adf8)(1);
  }
  return;
}


// ==== FUN_00514a20 @ 0x00514a20 ====

int * FUN_00514a20(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *unaff_EBX;
  undefined4 unaff_EBP;
  int *in_stack_00000014;
  undefined1 auStack_2 [2];
  
  pvVar2 = operator_new(0x14);
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_00522da0();
  }
  puVar1 = (undefined4 *)*in_stack_00000014;
  piVar4 = (int *)(**(code **)(*DAT_00b5af14 + 0xc))(1,0);
  iVar7 = *piVar4;
  uVar5 = (**(code **)(*DAT_00b5ac1c + 0x3c))(auStack_2 + -10);
  (**(code **)(iVar7 + 0x18))(uVar5);
  piVar6 = (int *)(**(code **)(*piVar3 + 0x14))();
  (**(code **)(*piVar6 + 0xc))(unaff_EBP);
  FUN_00523130(piVar4);
  iVar7 = (**(code **)(*piVar3 + 0x10))();
  *(undefined4 *)(iVar7 + 0x28) = 0;
  *(undefined4 *)(iVar7 + 0x2c) = 0;
  *(undefined4 *)(iVar7 + 0x18) = *unaff_EBX;
  *(undefined4 *)(iVar7 + 0x1c) = unaff_EBX[1];
  *(undefined4 *)(iVar7 + 0x20) = *puVar1;
  *(undefined4 *)(iVar7 + 0x24) = puVar1[1];
  FUN_00522e70(unaff_EBP);
  FUN_004dd240(9,0x2c,0,0,unaff_EBP);
  return piVar3;
}


// ==== FUN_00514af0 @ 0x00514af0 ====

int * FUN_00514af0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  void *pvVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *unaff_retaddr;
  undefined4 uStack_44;
  undefined4 uStack_30;
  int iStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int iStack_1c;
  int iStack_18;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_44 = 0;
  piVar4 = (int *)(**(code **)(*DAT_00b5ae00 + 0xc))(1);
  iVar1 = *piVar4;
  uVar5 = (**(code **)(*DAT_00b5ac1c + 0x3c))(unaff_retaddr);
  (**(code **)(iVar1 + 0x18))(uVar5);
  FUN_004f5730(&iStack_1c);
  FUN_0040d600(&uStack_30,uStack_14);
  iVar1 = *unaff_retaddr;
  iVar2 = unaff_retaddr[1];
  pvVar6 = operator_new(0x10);
  if (pvVar6 == (void *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)FUN_00523300();
  }
  piVar8 = (int *)(**(code **)(*piVar7 + 0x14))();
  (**(code **)(*piVar8 + 0xc))(uStack_c);
  FUN_00523580(&uStack_44);
  FUN_00523590((int)register0x00000010 + -0x40);
  FUN_00523690(uStack_8);
  FUN_00523670(uStack_4);
  FUN_00523740(piVar4);
  piVar4 = (int *)(**(code **)(*piVar7 + 0x10))();
  iVar3 = *piVar4;
  uVar5 = FUN_005e0c90(&uStack_c);
  (**(code **)(iVar3 + 8))(uVar5);
  piVar4[7] = iVar1;
  piVar4[6] = iVar2;
  piVar4[8] = iStack_1c;
  piVar4[9] = iStack_18;
  piVar4[10] = 0;
  uStack_30 = uStack_24;
  uStack_28 = uStack_20;
  iStack_2c = 0;
  puVar9 = (undefined4 *)FUN_005229b0(&uStack_24,&uStack_30);
  uStack_30 = *puVar9;
  iStack_2c = puVar9[1];
  uStack_28 = puVar9[2];
  piVar4[0xb] = iStack_2c;
  FUN_00523350();
  return piVar7;
}


// ==== FUN_00514c70 @ 0x00514c70 ====

int * FUN_00514c70(void)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *in_stack_00000014;
  undefined4 local_24;
  undefined4 *puStack_c;
  undefined4 *puStack_8;
  undefined4 uStack_4;
  
  pvVar2 = operator_new(0xc);
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_00523af0();
  }
  puVar8 = &local_24;
  for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar8 = *in_stack_00000014;
    in_stack_00000014 = in_stack_00000014 + 1;
    puVar8 = puVar8 + 1;
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5aa14 + 0xc))(1,0);
  iVar7 = *piVar4;
  uVar5 = (**(code **)(*DAT_00b5ac1c + 0x3c))((int)register0x00000010 + -0x2c);
  (**(code **)(iVar7 + 0x18))(uVar5);
  piVar6 = (int *)(**(code **)(*piVar3 + 0x14))();
  puVar8 = puStack_c;
  (**(code **)(*piVar6 + 0xc))(puStack_c);
  FUN_00523e70(piVar4);
  iVar7 = (**(code **)(*piVar3 + 0x10))();
  *(undefined4 *)(iVar7 + 0x28) = 0;
  *(undefined4 *)(iVar7 + 0x2c) = 0;
  *(undefined4 *)(iVar7 + 0x18) = *puStack_c;
  *(undefined4 *)(iVar7 + 0x1c) = puStack_c[1];
  *(undefined4 *)(iVar7 + 0x20) = *puStack_8;
  *(undefined4 *)(iVar7 + 0x24) = puStack_8[1];
  FUN_00523bb0(uStack_4);
  uVar5 = (**(code **)(*piVar4 + 0x1c))();
  piVar4 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
  if (piVar4 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar4 + 8))(uVar5);
    if (cVar1 != '\0') goto LAB_00514d5f;
    (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar4);
  }
  piVar4 = (int *)0x0;
LAB_00514d5f:
  iVar7 = (**(code **)(*piVar4 + 0x2c))(0,0,puVar8);
  FUN_004dd240(9,*(undefined4 *)(iVar7 + 0x14));
  (**(code **)(*piVar4 + 0x10))();
  (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar4);
  return piVar3;
}


// ==== FUN_00514da0 @ 0x00514da0 ====

int * FUN_00514da0(int *param_1)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  int *extraout_EAX;
  int unaff_EBX;
  int unaff_EBP;
  undefined1 *puVar9;
  undefined4 *puVar10;
  undefined1 auStack_52 [6];
  undefined4 uStack_4c;
  ushort uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  int iStack_8;
  uint uStack_4;
  
  pvVar2 = operator_new(0x4c);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00527e80();
  }
  pvVar2 = operator_new(0xc4);
  if (pvVar2 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_005262f0();
  }
  piVar5 = (int *)FUN_00527d40(piVar4,uVar3);
  (**(code **)(*piVar4 + 0xc))(param_1);
  FUN_005262d0(param_1);
  uStack_4c = (**(code **)(*piVar5 + 0x1c))();
  iVar7 = *param_1;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar6 = (**(code **)(iVar7 + 0x1c))(uVar3);
  piVar4 = (int *)(**(code **)(*(int *)param_1[0x13] + 0x18))();
  iVar7 = *piVar4;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uVar3 = (**(code **)(iVar7 + 0x18))(uVar3);
  FUN_004f5730(&uStack_34);
  uStack_44 = uStack_34;
  uStack_40 = uStack_30;
  FUN_0040d600(&uStack_3c,uStack_2c);
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  iVar7 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (iStack_8 == iVar7) {
    uStack_4 = uStack_4 & 0xffffff00;
  }
  else if ((DAT_00b5ac98 != (int *)0x0) &&
          (cVar1 = (**(code **)(*DAT_00b5ac98 + 0x44))(), cVar1 != '\0')) {
    (**(code **)(*DAT_00b5acac + 0x3c))(param_1);
  }
  uStack_4c = 0;
  uStack_48 = (ushort)*(byte *)(unaff_EBX + 0x44);
  *(undefined1 *)(iVar6 + 0xf) = 1;
  FUN_00512130(iStack_8,&uStack_44,&uStack_3c,0,0x3f800000,&uStack_4c,auStack_52 + -0xe,uStack_4,1,1
              );
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  pcVar8 = PTR_DAT_00aec138;
  do {
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_DAT_00aec138,(int)pcVar8 - (int)(PTR_DAT_00aec138 + 1));
  puVar10 = &uStack_4c;
  puVar9 = auStack_28;
  FUN_00511d10(puVar9,puVar10);
  FUN_00512e40(puVar9,puVar10);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return extraout_EAX;
  }
  (**(code **)(*piVar5 + 0x20))();
  *(undefined4 *)(unaff_EBP + 0x28) = 0;
  *(undefined4 *)(unaff_EBP + 0x2c) = 0;
  *(undefined4 *)(unaff_EBP + 0x18) = uStack_44;
  *(undefined4 *)(unaff_EBP + 0x1c) = uStack_40;
  *(undefined4 *)(unaff_EBP + 0x20) = uStack_3c;
  *(undefined4 *)(unaff_EBP + 0x24) = uStack_38;
  iVar7 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (iStack_8 == iVar7) {
    pvVar2 = operator_new(0x60);
    if (pvVar2 == (void *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)FUN_00524e60(piVar5);
    }
  }
  (**(code **)(*piVar5 + 4))(uVar3);
  pvVar2 = operator_new(0x10);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005241c0(piVar5);
  }
  (**(code **)(*piVar5 + 8))(uVar3);
  return piVar5;
}


// ==== FUN_00515030 @ 0x00515030 ====

int * FUN_00515030(int *param_1)

{
  char cVar1;
  undefined1 uVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined2 *puVar10;
  char *pcVar11;
  int *extraout_EAX;
  undefined4 unaff_EBP;
  float10 fVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  undefined *puStack_4;
  
  pvVar3 = operator_new(0x58);
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_0052a710();
  }
  pvVar3 = operator_new(0x34);
  if (pvVar3 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_00529850();
  }
  piVar6 = (int *)FUN_00527d40(piVar5,iVar4);
  (**(code **)(*piVar5 + 0xc))(param_1);
  FUN_0052a2b0(param_1);
  uVar2 = FUN_00522930(param_1);
  FUN_00529630(uVar2);
  iVar7 = (**(code **)(*param_1 + 0x24))();
  uStack_4c = CONCAT31(uStack_4c._1_3_,*(undefined1 *)(iVar7 + 100));
  uVar8 = (**(code **)(*piVar6 + 0x1c))();
  if ((int *)param_1[0x13] == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(*(int *)param_1[0x13] + 0x18))();
  }
  iVar7 = *piVar5;
  uVar9 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uVar9 = (**(code **)(iVar7 + 0x18))(uVar9);
  FUN_004f5730(&uStack_30);
  uStack_40 = uStack_30;
  uStack_3c = uStack_2c;
  FUN_0040d600(&uStack_38,uStack_28);
  uStack_4c = 1;
  uStack_48 = 1;
  uStack_44 = 0;
  puVar10 = (undefined2 *)(**(code **)(*param_1 + 0x1c))();
  uStack_44 = *puVar10;
  FUN_00512130(puStack_4,&uStack_40,&uStack_38,0,0x3f800000,&uStack_48,&uStack_4c,1,uVar8,unaff_EBP)
  ;
  puStack_4 = PTR_DAT_00aec138 + 1;
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  pcVar11 = PTR_DAT_00aec138;
  do {
    cVar1 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_DAT_00aec138,(int)pcVar11 - (int)puStack_4);
  puVar14 = &uStack_48;
  puVar13 = auStack_24;
  FUN_00511d10(puVar13,puVar14);
  FUN_00512e40(puVar13,puVar14);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return extraout_EAX;
  }
  (**(code **)(*piVar6 + 0x20))();
  fVar12 = (float10)FUN_005228b0(param_1);
  *(float *)(iVar4 + 0x38) = (float)fVar12;
  *(undefined4 *)(iVar4 + 0x28) = 0;
  *(undefined4 *)(iVar4 + 0x2c) = 0;
  *(undefined4 *)(iVar4 + 0x18) = uStack_40;
  *(undefined4 *)(iVar4 + 0x1c) = uStack_3c;
  *(undefined4 *)(iVar4 + 0x20) = uStack_38;
  *(undefined4 *)(iVar4 + 0x24) = uStack_34;
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_00528620(piVar6);
  }
  (**(code **)(*piVar6 + 4))(uVar9);
  (**(code **)(*piVar6 + 8))(uVar8);
  return piVar6;
}


// ==== FUN_00515260 @ 0x00515260 ====

int * FUN_00515260(undefined4 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined1 uVar3;
  void *pvVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  undefined4 uVar9;
  undefined2 *puVar10;
  char *pcVar11;
  int *extraout_EAX;
  undefined4 uVar12;
  undefined4 unaff_EBP;
  float10 fVar13;
  undefined4 unaff_retaddr;
  undefined1 *puVar14;
  int **ppiVar15;
  undefined4 uStack_4c;
  int *local_48;
  undefined2 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  undefined *puStack_4;
  
  pvVar4 = operator_new(0x50);
  if (pvVar4 == (void *)0x0) {
    iVar5 = 0;
  }
  else {
    iVar5 = FUN_0052c720();
  }
  pvVar4 = operator_new(0x24);
  if (pvVar4 == (void *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)FUN_0052bba0();
  }
  local_48 = piVar6;
  piVar7 = (int *)FUN_00527d40(piVar6,iVar5);
  (**(code **)(*piVar6 + 0xc))(param_1);
  FUN_0052c210(param_2);
  uVar3 = FUN_00522970(param_2);
  FUN_0052ba50(uVar3);
  iVar8 = (**(code **)(*piVar7 + 0x1c))();
  if ((int *)param_2[0x13] == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(**(code **)(*(int *)param_2[0x13] + 0x18))();
  }
  iVar2 = *piVar6;
  uVar9 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uVar9 = (**(code **)(iVar2 + 0x18))(uVar9);
  FUN_004f5730(&uStack_30);
  uStack_40 = uStack_30;
  uStack_3c = uStack_2c;
  FUN_0040d600(&uStack_38,uStack_28);
  uStack_4c = 1;
  uStack_44 = 0;
  local_48 = (int *)0x3;
  puVar10 = (undefined2 *)(**(code **)(*param_2 + 0x1c))();
  uStack_44 = *puVar10;
  FUN_00512130(puStack_4,&uStack_40,&uStack_38,0,0x3f800000,&local_48,&uStack_4c,1,1,unaff_EBP);
  puStack_4 = PTR_DAT_00aec138 + 1;
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  pcVar11 = PTR_DAT_00aec138;
  do {
    cVar1 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_DAT_00aec138,(int)pcVar11 - (int)puStack_4);
  ppiVar15 = &local_48;
  puVar14 = auStack_24;
  FUN_00511d10(puVar14,ppiVar15);
  FUN_00512e40(puVar14,ppiVar15);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return extraout_EAX;
  }
  (**(code **)(*piVar7 + 0x20))();
  fVar13 = (float10)FUN_005228d0(param_2);
  *(float *)(iVar5 + 0x38) = (float)fVar13;
  *(undefined4 *)(iVar5 + 0x28) = 0;
  *(undefined4 *)(iVar5 + 0x2c) = 0;
  *(undefined4 *)(iVar5 + 0x18) = uStack_40;
  *(undefined4 *)(iVar5 + 0x1c) = uStack_3c;
  *(undefined4 *)(iVar5 + 0x20) = uStack_38;
  *(undefined4 *)(iVar5 + 0x24) = uStack_34;
  *(undefined4 *)(iVar8 + 0xc) = unaff_retaddr;
  pvVar4 = operator_new(0x10);
  if (pvVar4 == (void *)0x0) {
    uVar12 = 0;
  }
  else {
    uVar12 = FUN_0052ad90(piVar7);
  }
  (**(code **)(*piVar7 + 4))(uVar9);
  (**(code **)(*piVar7 + 8))(uVar12);
  return piVar7;
}


// ==== FUN_00515490 @ 0x00515490 ====

int * FUN_00515490(undefined4 param_1,int *param_2)

{
  undefined1 uVar1;
  char cVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined2 *puVar10;
  char *pcVar11;
  int *extraout_EAX;
  undefined4 unaff_EBP;
  float10 fVar12;
  undefined4 unaff_retaddr;
  undefined1 *puVar13;
  undefined4 *puVar14;
  undefined4 uStack_54;
  int iStack_50;
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  undefined *puStack_4;
  
  pvVar3 = operator_new(0x50);
  if (pvVar3 == (void *)0x0) {
    iVar4 = 0;
  }
  else {
    iVar4 = FUN_0052e820();
  }
  pvVar3 = operator_new(0x24);
  if (pvVar3 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_0052dac0();
  }
  piVar6 = (int *)FUN_00527d40(piVar5,iVar4);
  (**(code **)(*piVar5 + 0xc))(param_1);
  FUN_0052e300(param_2);
  uVar1 = FUN_00522950(param_2);
  FUN_0052d970(uVar1);
  iVar7 = (**(code **)(*param_2 + 0x28))();
  uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)(iVar7 + 0x44));
  uVar8 = (**(code **)(*piVar6 + 0x1c))();
  if ((int *)param_2[0x13] == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(*(int *)param_2[0x13] + 0x18))();
  }
  iVar7 = *piVar5;
  uVar9 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uVar9 = (**(code **)(iVar7 + 0x18))(uVar9);
  FUN_004f5730(&uStack_30);
  uStack_40 = uStack_30;
  uStack_3c = uStack_2c;
  FUN_0040d600(&uStack_38,uStack_28);
  if ((DAT_00b5ac98 != (int *)0x0) && (cVar2 = (**(code **)(*DAT_00b5ac98 + 0x44))(), cVar2 != '\0')
     ) {
    (**(code **)(*DAT_00b5acac + 0x40))(unaff_retaddr);
  }
  uStack_44 = 0;
  uStack_48 = 2;
  puVar10 = (undefined2 *)(**(code **)(*param_2 + 0x1c))();
  uStack_44 = *puVar10;
  *(undefined1 *)(iStack_50 + 0xf) = 1;
  FUN_00512130(puStack_4,&uStack_40,&uStack_38,0,0x3f800000,&uStack_48,auStack_24 + -0x34,1,uVar8,
               unaff_EBP);
  puStack_4 = PTR_DAT_00aec138 + 1;
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  pcVar11 = PTR_DAT_00aec138;
  do {
    cVar2 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar2 != '\0');
  FUN_00401740(PTR_DAT_00aec138,(int)pcVar11 - (int)puStack_4);
  puVar14 = &uStack_48;
  puVar13 = auStack_24;
  FUN_00511d10(puVar13,puVar14);
  FUN_00512e40(puVar13,puVar14);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return extraout_EAX;
  }
  (**(code **)(*piVar6 + 0x20))();
  fVar12 = (float10)FUN_005228c0(param_2);
  *(float *)(iVar4 + 0x38) = (float)fVar12;
  *(undefined4 *)(iVar4 + 0x28) = 0;
  *(undefined4 *)(iVar4 + 0x2c) = 0;
  *(undefined4 *)(iVar4 + 0x18) = uStack_40;
  *(undefined4 *)(iVar4 + 0x1c) = uStack_3c;
  *(undefined4 *)(iVar4 + 0x20) = uStack_38;
  *(undefined4 *)(iVar4 + 0x24) = uStack_34;
  *(undefined4 *)(uStack_54 + 0xc) = unaff_retaddr;
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_0052cf00(piVar6);
  }
  (**(code **)(*piVar6 + 4))(uVar9);
  (**(code **)(*piVar6 + 8))(uVar8);
  return piVar6;
}


// ==== FUN_00515710 @ 0x00515710 ====

int * FUN_00515710(int *param_1)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  int *piVar4;
  undefined2 *puVar5;
  char *pcVar6;
  int *extraout_EAX;
  int iVar7;
  undefined4 unaff_retaddr;
  undefined1 *puVar8;
  undefined4 *puVar9;
  undefined4 uStack_44;
  undefined2 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  pvVar2 = operator_new(0x1c);
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0052ee00();
  }
  piVar4 = (int *)(**(code **)(*piVar3 + 0x14))();
  (**(code **)(*piVar4 + 0xc))(param_1);
  FUN_0052ec00(param_1);
  (**(code **)(*piVar3 + 0x1c))();
  puVar5 = (undefined2 *)(**(code **)(*param_1 + 0x1c))();
  FUN_004f5730(&uStack_2c);
  uStack_3c = uStack_2c;
  uStack_38 = uStack_28;
  FUN_0040d600(&uStack_34,uStack_24);
  uStack_44 = 4;
  uStack_40 = *puVar5;
  FUN_00512130(unaff_retaddr,&uStack_3c,&uStack_34,0,0x3f800000,&uStack_44,auStack_20 + -0x28,1,1,1)
  ;
  uStack_c = 0;
  uStack_8 = 0xf;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  pcVar6 = PTR_DAT_00aec138;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_DAT_00aec138,(int)pcVar6 - (int)(PTR_DAT_00aec138 + 1));
  puVar9 = &uStack_44;
  puVar8 = auStack_20;
  FUN_00511d10(puVar8,puVar9);
  FUN_00512e40(puVar8,puVar9);
  if (uStack_8 < 0x10) {
    iVar7 = (**(code **)(*piVar3 + 0x10))();
    *(undefined4 *)(iVar7 + 0x28) = 0;
    *(undefined4 *)(iVar7 + 0x2c) = 0;
    *(undefined4 *)(iVar7 + 0x18) = uStack_3c;
    *(undefined4 *)(iVar7 + 0x1c) = uStack_38;
    *(undefined4 *)(iVar7 + 0x20) = uStack_34;
    *(undefined4 *)(iVar7 + 0x24) = uStack_30;
    (**(code **)(*piVar3 + 0x20))();
    return piVar3;
  }
  _free(pvStack_1c);
  return extraout_EAX;
}


// ==== FUN_00515890 @ 0x00515890 ====

int * FUN_00515890(undefined4 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  char *pcVar7;
  int *extraout_EAX;
  int *piVar8;
  float10 fVar9;
  undefined4 unaff_retaddr;
  undefined1 *puVar10;
  undefined4 *puVar11;
  undefined4 uStack_58;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  undefined4 uStack_48;
  undefined2 uStack_44;
  int iStack_40;
  int iStack_3c;
  int iStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  undefined4 uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  pvVar3 = operator_new(0x18);
  if (pvVar3 == (void *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)FUN_0052fb90();
  }
  if ((int *)param_2[0x13] == (int *)0x0) {
    piVar8 = (int *)0x0;
  }
  else {
    piVar8 = (int *)(**(code **)(*(int *)param_2[0x13] + 0x18))();
  }
  iVar2 = *piVar8;
  uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uVar5 = (**(code **)(iVar2 + 0x18))(uVar5);
  FUN_004f5730(&iStack_2c);
  FUN_005e0c90(auStack_20 + -0x3c);
  iStack_50 = iStack_2c;
  iStack_4c = iStack_28;
  FUN_0040d600(&iStack_40,uStack_24);
  iStack_38 = iStack_50;
  iStack_30 = iStack_4c;
  iStack_34 = 0;
  piVar8 = (int *)FUN_005229b0(&iStack_2c,&iStack_38);
  iStack_38 = *piVar8;
  iStack_54 = piVar8[1];
  iStack_30 = piVar8[2];
  uStack_58 = 10;
  uStack_44 = 0;
  uStack_48 = 5;
  iStack_34 = iStack_54;
  puVar6 = (undefined2 *)(**(code **)(*param_2 + 0x1c))();
  uStack_44 = *puVar6;
  (**(code **)(*piVar4 + 0x1c))();
  FUN_00512130(unaff_retaddr,&iStack_50,&iStack_40,0,0x3f800000,&uStack_48,&uStack_58,1,1,1);
  uStack_8 = 0xf;
  uStack_c = 0;
  pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
  pcVar7 = PTR_DAT_00aec138;
  do {
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_DAT_00aec138,(int)pcVar7 - (int)(PTR_DAT_00aec138 + 1));
  puVar11 = &uStack_48;
  puVar10 = auStack_20;
  FUN_00511d10(puVar10,puVar11);
  FUN_00512e40(puVar10,puVar11);
  if (0xf < uStack_8) {
    _free(pvStack_1c);
    return extraout_EAX;
  }
  FUN_005301d0(param_2);
  piVar8 = (int *)(**(code **)(*piVar4 + 0x10))();
  fVar9 = (float10)FUN_005228e0(param_2);
  piVar8[0xe] = (int)(float)fVar9;
  fVar9 = (float10)FUN_00522900(param_2);
  piVar8[0xd] = (int)(float)fVar9;
  piVar8[10] = 0;
  piVar8[0xb] = iStack_54;
  piVar8[6] = iStack_50;
  piVar8[7] = iStack_4c;
  piVar8[8] = iStack_40;
  piVar8[9] = iStack_3c;
  (**(code **)(*piVar8 + 8))(auStack_20 + -0x3c);
  (**(code **)(*piVar4 + 4))(uVar5);
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    (**(code **)(*piVar4 + 8))(0);
    return piVar4;
  }
  uVar5 = FUN_0052f7d0(piVar4);
  (**(code **)(*piVar4 + 8))(uVar5);
  return piVar4;
}


// ==== FUN_00515ae0 @ 0x00515ae0 ====

int * FUN_00515ae0(int *param_1)

{
  char cVar1;
  int iVar2;
  code *pcVar3;
  undefined1 uVar4;
  void *pvVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *extraout_EAX;
  undefined4 uVar9;
  undefined2 *puVar10;
  char *pcVar11;
  int *extraout_EAX_00;
  undefined4 unaff_EBX;
  float10 fVar12;
  undefined1 *puVar13;
  undefined4 *puVar14;
  undefined1 auStack_4a [2];
  undefined4 uStack_48;
  undefined2 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 uStack_10;
  uint uStack_c;
  int *local_8;
  undefined *local_4;
  
  pvVar5 = operator_new(0x50);
  if (pvVar5 == (void *)0x0) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_00531230();
  }
  pvVar5 = operator_new(0x24);
  if (pvVar5 == (void *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)FUN_005307f0();
  }
  piVar8 = (int *)FUN_00527d40(piVar7,iVar6);
  if (piVar8 == (int *)0x0) {
    local_4 = (undefined *)0xf;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    local_8 = piVar8;
    FUN_00401740(s_pSentry____NULL_009b68b8,0xf);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar3 = (code *)swi(3);
      piVar7 = (int *)(*pcVar3)();
      return piVar7;
    }
    _free(local_18);
    return extraout_EAX;
  }
  (**(code **)(*piVar7 + 0xc))(param_1);
  FUN_00530e40(param_1);
  uVar4 = FUN_00522990(param_1);
  FUN_00530730(uVar4);
  uStack_48 = (**(code **)(*piVar8 + 0x1c))();
  if ((int *)param_1[0x13] == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)(**(code **)(*(int *)param_1[0x13] + 0x18))();
  }
  iVar2 = *piVar7;
  uVar9 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uVar9 = (**(code **)(iVar2 + 0x18))(uVar9);
  FUN_004f5730(&uStack_30);
  uStack_40 = uStack_30;
  uStack_3c = uStack_2c;
  FUN_0040d600(&uStack_38,uStack_28);
  uStack_44 = 0;
  uStack_48 = 6;
  puVar10 = (undefined2 *)(**(code **)(*param_1 + 0x1c))();
  uStack_44 = *puVar10;
  FUN_00512130(local_4,&uStack_40,&uStack_38,0,0x3f800000,&uStack_48,auStack_4a + -10,1,1,unaff_EBX)
  ;
  local_4 = PTR_DAT_00aec138 + 1;
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  pcVar11 = PTR_DAT_00aec138;
  do {
    cVar1 = *pcVar11;
    pcVar11 = pcVar11 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_DAT_00aec138,(int)pcVar11 - (int)local_4);
  puVar14 = &uStack_48;
  puVar13 = auStack_24;
  FUN_00511d10(puVar13,puVar14);
  FUN_00512e40(puVar13,puVar14);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return extraout_EAX_00;
  }
  (**(code **)(*piVar8 + 0x20))();
  fVar12 = (float10)FUN_00522920(param_1);
  *(float *)(iVar6 + 0x38) = (float)fVar12;
  *(undefined4 *)(iVar6 + 0x28) = 0;
  *(undefined4 *)(iVar6 + 0x2c) = 0;
  *(undefined4 *)(iVar6 + 0x18) = uStack_40;
  *(undefined4 *)(iVar6 + 0x1c) = uStack_3c;
  *(undefined4 *)(iVar6 + 0x20) = uStack_38;
  *(undefined4 *)(iVar6 + 0x24) = uStack_34;
  (**(code **)(*piVar8 + 4))(uVar9);
  pvVar5 = operator_new(0x10);
  if (pvVar5 == (void *)0x0) {
    (**(code **)(*piVar8 + 8))(0);
    return piVar8;
  }
  uVar9 = FUN_00530560(piVar8);
  (**(code **)(*piVar8 + 8))(uVar9);
  return piVar8;
}


// ==== FUN_00515d60 @ 0x00515d60 ====

void FUN_00515d60(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5adf8 = 0;
  *in_ECX = &PTR_FUN_009b68f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00515df0 @ 0x00515df0 ====

void FUN_00515df0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = operator_new(0x20);
  if (pvVar2 == (void *)0x0) {
    param_2 = 0;
  }
  else {
    param_2 = FUN_00531620(param_1,param_2);
  }
  iVar1 = *(int *)(param_3 + 4);
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_2);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


// ==== FUN_00515e60 @ 0x00515e60 ====

void FUN_00515e60(undefined4 param_1,undefined4 param_2,uint *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar2 = param_4;
  puVar3 = param_3;
  uVar1 = *param_3;
  if (uVar4 < uVar1) {
    uVar8 = uVar4 + 300;
    if (uVar1 <= uVar4 + 300) {
      uVar8 = uVar1;
    }
    pvVar5 = operator_new(0xc);
    if (pvVar5 == (void *)0x0) {
      param_3 = (uint *)0x0;
    }
    else {
      param_3 = (uint *)FUN_005317b0(param_1,uVar8);
    }
    iVar7 = *(int *)(iVar2 + 4);
    iVar6 = FUN_00517140(iVar7,*(undefined4 *)(iVar7 + 4),&param_3);
    FUN_00517200(1);
    *(int *)(iVar7 + 4) = iVar6;
    **(int **)(iVar6 + 4) = iVar6;
  }
  pvVar5 = operator_new(0x24);
  if (pvVar5 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_005316e0(param_1,puVar3);
  }
  iVar2 = *(int *)(iVar2 + 4);
  iVar7 = FUN_00517140(iVar2,*(undefined4 *)(iVar2 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar2 + 4) = iVar7;
  **(int **)(iVar7 + 4) = iVar7;
  return;
}


// ==== FUN_00515f40 @ 0x00515f40 ====

void FUN_00515f40(undefined4 param_1,undefined4 param_2,uint *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar2 = param_4;
  puVar3 = param_3;
  uVar1 = *param_3;
  if (uVar4 < uVar1) {
    uVar8 = uVar4 + 300;
    if (uVar1 <= uVar4 + 300) {
      uVar8 = uVar1;
    }
    pvVar5 = operator_new(0xc);
    if (pvVar5 == (void *)0x0) {
      param_3 = (uint *)0x0;
    }
    else {
      param_3 = (uint *)FUN_005317b0(param_1,uVar8);
    }
    iVar7 = *(int *)(iVar2 + 4);
    iVar6 = FUN_00517140(iVar7,*(undefined4 *)(iVar7 + 4),&param_3);
    FUN_00517200(1);
    *(int *)(iVar7 + 4) = iVar6;
    **(int **)(iVar6 + 4) = iVar6;
  }
  pvVar5 = operator_new(0x1c);
  if (pvVar5 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_00531880(param_1,puVar3);
  }
  iVar2 = *(int *)(iVar2 + 4);
  iVar7 = FUN_00517140(iVar2,*(undefined4 *)(iVar2 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar2 + 4) = iVar7;
  **(int **)(iVar7 + 4) = iVar7;
  return;
}


// ==== FUN_00516020 @ 0x00516020 ====

void FUN_00516020(undefined4 param_1,undefined4 param_2,uint *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar2 = param_4;
  puVar3 = param_3;
  uVar1 = *param_3;
  if (uVar4 < uVar1) {
    uVar8 = uVar4 + 300;
    if (uVar1 <= uVar4 + 300) {
      uVar8 = uVar1;
    }
    pvVar5 = operator_new(0xc);
    if (pvVar5 == (void *)0x0) {
      param_3 = (uint *)0x0;
    }
    else {
      param_3 = (uint *)FUN_005317b0(param_1,uVar8);
    }
    iVar7 = *(int *)(iVar2 + 4);
    iVar6 = FUN_00517140(iVar7,*(undefined4 *)(iVar7 + 4),&param_3);
    FUN_00517200(1);
    *(int *)(iVar7 + 4) = iVar6;
    **(int **)(iVar6 + 4) = iVar6;
  }
  pvVar5 = operator_new(0x20);
  if (pvVar5 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_005318f0(param_1,puVar3);
  }
  iVar2 = *(int *)(iVar2 + 4);
  iVar7 = FUN_00517140(iVar2,*(undefined4 *)(iVar2 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar2 + 4) = iVar7;
  **(int **)(iVar7 + 4) = iVar7;
  return;
}


// ==== FUN_00516100 @ 0x00516100 ====

void FUN_00516100(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = operator_new(0x1c);
  if (pvVar2 == (void *)0x0) {
    param_3 = 0;
  }
  else {
    param_3 = FUN_005319d0(param_1,param_3);
  }
  iVar1 = *(int *)(param_4 + 4);
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


// ==== FUN_00516170 @ 0x00516170 ====

void FUN_00516170(undefined4 param_1,undefined4 param_2,uint *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar2 = param_4;
  puVar3 = param_3;
  uVar1 = *param_3;
  if (uVar4 < uVar1) {
    uVar8 = uVar4 + 300;
    if (uVar1 <= uVar4 + 300) {
      uVar8 = uVar1;
    }
    pvVar5 = operator_new(0xc);
    if (pvVar5 == (void *)0x0) {
      param_3 = (uint *)0x0;
    }
    else {
      param_3 = (uint *)FUN_005317b0(param_1,uVar8);
    }
    iVar7 = *(int *)(iVar2 + 4);
    iVar6 = FUN_00517140(iVar7,*(undefined4 *)(iVar7 + 4),&param_3);
    FUN_00517200(1);
    *(int *)(iVar7 + 4) = iVar6;
    **(int **)(iVar6 + 4) = iVar6;
  }
  pvVar5 = operator_new(0x20);
  if (pvVar5 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_00531a40(param_1,puVar3);
  }
  iVar2 = *(int *)(iVar2 + 4);
  iVar7 = FUN_00517140(iVar2,*(undefined4 *)(iVar2 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar2 + 4) = iVar7;
  **(int **)(iVar7 + 4) = iVar7;
  return;
}


// ==== FUN_00516250 @ 0x00516250 ====

void FUN_00516250(undefined4 param_1,undefined4 param_2,uint *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  void *pvVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar2 = param_4;
  puVar3 = param_3;
  uVar1 = *param_3;
  if (uVar4 < uVar1) {
    uVar8 = uVar4 + 300;
    if (uVar1 <= uVar4 + 300) {
      uVar8 = uVar1;
    }
    pvVar5 = operator_new(0xc);
    if (pvVar5 == (void *)0x0) {
      param_3 = (uint *)0x0;
    }
    else {
      param_3 = (uint *)FUN_005317b0(param_1,uVar8);
    }
    iVar7 = *(int *)(iVar2 + 4);
    iVar6 = FUN_00517140(iVar7,*(undefined4 *)(iVar7 + 4),&param_3);
    FUN_00517200(1);
    *(int *)(iVar7 + 4) = iVar6;
    **(int **)(iVar6 + 4) = iVar6;
  }
  pvVar5 = operator_new(0x20);
  if (pvVar5 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_00531b00(param_1,puVar3);
  }
  iVar2 = *(int *)(iVar2 + 4);
  iVar7 = FUN_00517140(iVar2,*(undefined4 *)(iVar2 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar2 + 4) = iVar7;
  **(int **)(iVar7 + 4) = iVar7;
  return;
}


// ==== FUN_00516330 @ 0x00516330 ====

void FUN_00516330(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = operator_new(0x1c);
  if (pvVar2 == (void *)0x0) {
    param_3 = 0;
  }
  else {
    param_3 = FUN_00531c10(param_1,param_3);
  }
  iVar1 = *(int *)(param_4 + 4);
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


// ==== FUN_005163a0 @ 0x005163a0 ====

void FUN_005163a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = operator_new(0x18);
  if (pvVar2 == (void *)0x0) {
    param_3 = 0;
  }
  else {
    param_3 = FUN_00531cc0(param_1,param_3);
  }
  iVar1 = *(int *)(param_4 + 4);
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


// ==== FUN_00516410 @ 0x00516410 ====

void FUN_00516410(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = operator_new(0x18);
  if (pvVar2 == (void *)0x0) {
    param_3 = 0;
  }
  else {
    param_3 = FUN_00531d60(param_1,param_3);
  }
  iVar1 = *(int *)(param_4 + 4);
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


// ==== FUN_00516480 @ 0x00516480 ====

void FUN_00516480(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = operator_new(0x18);
  if (pvVar2 == (void *)0x0) {
    param_3 = 0;
  }
  else {
    param_3 = FUN_00531e50(param_1,param_3);
  }
  iVar1 = *(int *)(param_4 + 4);
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


// ==== FUN_005164f0 @ 0x005164f0 ====

void FUN_005164f0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = operator_new(0x14);
  if (pvVar2 == (void *)0x0) {
    param_3 = 0;
  }
  else {
    param_3 = FUN_00531f30(param_1,param_3);
  }
  iVar1 = *(int *)(param_4 + 4);
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


// ==== FUN_00516560 @ 0x00516560 ====

void FUN_00516560(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = operator_new(0x18);
  if (pvVar2 == (void *)0x0) {
    param_3 = 0;
  }
  else {
    param_3 = FUN_005320c0(param_1,param_3);
  }
  iVar1 = *(int *)(param_4 + 4);
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


// ==== FUN_005165d0 @ 0x005165d0 ====

void FUN_005165d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = operator_new(0x14);
  if (pvVar2 == (void *)0x0) {
    param_3 = 0;
  }
  else {
    param_3 = FUN_00531fb0(param_1,param_3);
  }
  iVar1 = *(int *)(param_4 + 4);
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


// ==== FUN_00516640 @ 0x00516640 ====

void FUN_00516640(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = operator_new(0x20);
  if (pvVar2 == (void *)0x0) {
    param_3 = 0;
  }
  else {
    param_3 = FUN_00532030(param_1,param_3);
  }
  iVar1 = *(int *)(param_4 + 4);
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


// ==== FUN_005166b0 @ 0x005166b0 ====

void FUN_005166b0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = operator_new(0x18);
  if (pvVar2 == (void *)0x0) {
    param_3 = 0;
  }
  else {
    param_3 = FUN_00532250(param_1,param_3);
  }
  iVar1 = *(int *)(param_4 + 4);
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


// ==== FUN_00516720 @ 0x00516720 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float FUN_00516720(undefined4 param_1,float param_2,float *param_3,undefined4 param_4,float *param_5
                  ,int param_6,undefined4 param_7,float param_8,int param_9)

{
  float fVar1;
  uint uVar2;
  float fVar3;
  float *pfVar4;
  float *pfVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  undefined2 in_FPUControlWord;
  
  pfVar5 = param_5;
  pfVar4 = param_3;
  fVar3 = param_2;
  param_5 = (float *)SQRT((*param_5 - *param_3) * (*param_5 - *param_3) +
                          (param_5[1] - param_3[1]) * (param_5[1] - param_3[1]));
  if ((float)param_5 < DAT_0099d080) {
    return param_2;
  }
  if ((uint)param_2 < (uint)param_8) {
    iVar7 = (int)param_8 - (int)param_2;
    param_2 = (float)iVar7;
    if (iVar7 < 0) {
      param_2 = param_2 + _DAT_0099d104;
    }
    param_3 = (float *)(param_2 * DAT_009a09b8);
    if (((float)param_5 < (float)param_3) && (DAT_009b697c <= (float)param_3)) {
      fVar1 = param_2 / (float)param_3;
      uVar2 = (uint)param_2 >> 0x10;
      param_2 = (float)CONCAT22((short)uVar2,in_FPUControlWord);
      iVar7 = (int)ROUND(fVar1 * (float)param_5);
      param_6 = iVar7;
      pvVar6 = operator_new(0x24);
      if (pvVar6 == (void *)0x0) {
        param_1 = 0;
      }
      else {
        param_1 = FUN_005314c0(param_1,pfVar4,pfVar5,param_7,1,0x41200000,1,0);
      }
      FUN_00517370(&param_1);
      return (float)(iVar7 + (int)fVar3);
    }
  }
  pvVar6 = operator_new(0x18);
  if (pvVar6 == (void *)0x0) {
    param_1 = 0;
  }
  else {
    param_1 = FUN_005315c0(param_1,pfVar5,param_6);
  }
  iVar7 = *(int *)(param_9 + 4);
  iVar8 = FUN_00517140(iVar7,*(undefined4 *)(iVar7 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar7 + 4) = iVar8;
  **(int **)(iVar8 + 4) = iVar8;
  return fVar3;
}


// ==== FUN_00516890 @ 0x00516890 ====

undefined4 FUN_00516890(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int *in_ECX;
  undefined4 uStack_38;
  int *piStack_34;
  undefined4 uStack_30;
  undefined1 local_24 [20];
  undefined4 uStack_10;
  undefined4 uStack_4;
  
  uStack_30 = 0;
  piStack_34 = param_4;
  uStack_38 = param_3;
  (**(code **)(*in_ECX + 4))(local_24,param_2);
  FUN_00506ea0(param_4,local_24 + -8);
  pvVar2 = operator_new(0x18);
  if (pvVar2 == (void *)0x0) {
    uStack_4 = 0;
  }
  else {
    uStack_4 = FUN_005315c0(param_2,local_24 + -8,local_24);
  }
  iVar1 = *piStack_34;
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&uStack_4);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  FUN_005173d0(&uStack_38);
  FUN_008984a0();
  return uStack_10;
}


// ==== FUN_00516940 @ 0x00516940 ====

void FUN_00516940(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  void *pvVar4;
  int iVar5;
  undefined1 auStack_28 [8];
  undefined1 auStack_20 [8];
  undefined4 uStack_18;
  undefined1 uStack_14;
  
  cVar3 = (**(code **)(*param_1 + 4))();
  if (cVar3 == '\0') {
    iVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uVar2 = param_3;
    FUN_00507020(param_3,auStack_28);
    iVar1 = param_4;
    FUN_00516720(param_1,iVar5,param_2,uStack_18,auStack_28,auStack_20,uStack_14,iVar5 + 300,param_4
                );
    pvVar4 = operator_new(0x20);
    if (pvVar4 == (void *)0x0) {
      param_3 = 0;
    }
    else {
      param_3 = FUN_005322c0(param_1,uVar2);
    }
    iVar1 = *(int *)(iVar1 + 4);
    iVar5 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
    FUN_00517200(1);
    *(int *)(iVar1 + 4) = iVar5;
    **(int **)(iVar5 + 4) = iVar5;
    return;
  }
  pvVar4 = operator_new(0x20);
  if (pvVar4 == (void *)0x0) {
    param_3 = 0;
  }
  else {
    param_3 = FUN_005322c0(param_1,param_3);
  }
  iVar1 = *(int *)(param_4 + 4);
  iVar5 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  return;
}


// ==== FUN_00516a60 @ 0x00516a60 ====

void FUN_00516a60(int *param_1,undefined4 param_2,undefined4 *param_3,int param_4,undefined4 param_5
                 )

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined1 local_3c [4];
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [16];
  int iStack_18;
  undefined1 uStack_14;
  undefined1 auStack_10 [16];
  
  cVar1 = (**(code **)(*param_1 + 4))();
  if (cVar1 != '\0') {
    pvVar2 = operator_new(0x18);
    if (pvVar2 == (void *)0x0) {
      param_5 = 0;
    }
    else {
      param_5 = FUN_005323b0(param_1,param_3);
    }
    iVar5 = *(int *)(param_4 + 4);
    iVar3 = FUN_00517140(iVar5,*(undefined4 *)(iVar5 + 4),&param_5);
    FUN_00517200(1);
    *(int *)(iVar5 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
    return;
  }
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar5 = (**(code **)*param_1)();
  if ((iVar5 != 0) && (*(int **)(iVar5 + 0x4c) != (int *)0x0)) {
    piVar6 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
    if (piVar6 != (int *)0x0) {
      uStack_38 = *param_3;
      uStack_34 = param_3[1];
      uStack_30 = param_3[2];
      uStack_2c = param_3[3];
      if ((char)param_5 == '\x01') {
        (**(code **)(*piVar6 + 0x24))(param_3);
        FUN_004eff90(local_3c,uVar4,*(undefined1 *)((int)param_3 + 10));
        puVar7 = (undefined4 *)(**(code **)(*piVar6 + 0x3c))(uVar4);
        uStack_34 = *puVar7;
        uStack_30 = CONCAT22(uStack_30._2_2_,*(undefined2 *)(puVar7 + 1));
      }
      FUN_00506f60(&uStack_38,auStack_28);
      uVar8 = iStack_18 + 1000U;
      if (iStack_18 + 1000U <= uVar4) {
        uVar8 = uVar4;
      }
      FUN_00516720(param_1,uVar4,param_2,iStack_18,auStack_28,auStack_10,uStack_14,uVar8,param_4);
      pvVar2 = operator_new(0x18);
      if (pvVar2 != (void *)0x0) {
        param_5 = FUN_005323b0(param_1,&uStack_38);
        FUN_00517370(&param_5);
        return;
      }
      param_5 = 0;
      FUN_00517370(&param_5);
    }
  }
  return;
}


// ==== FUN_00516c10 @ 0x00516c10 ====

undefined4
FUN_00516c10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined1 local_c [4];
  int local_8;
  undefined4 local_4;
  
  iVar1 = FUN_005170b0();
  local_4 = 0;
  local_8 = iVar1;
  pvVar2 = operator_new(0x24);
  if (pvVar2 == (void *)0x0) {
    param_9 = 0;
  }
  else {
    param_9 = FUN_005314c0(param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  }
  iVar3 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_9);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  FUN_005173d0(local_c);
  FUN_008984a0();
  return param_1;
}


// ==== FUN_00516cc0 @ 0x00516cc0 ====

void FUN_00516cc0(int *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  void *pvVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 auStack_18 [8];
  undefined1 auStack_10 [8];
  int iStack_8;
  undefined1 uStack_4;
  
  cVar3 = (**(code **)(*param_1 + 4))();
  if (cVar3 == '\0') {
    uVar6 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uVar2 = param_3;
    FUN_00506f00(param_3,auStack_18);
    iVar1 = param_4;
    FUN_00516720(param_1,uVar6,param_2,iStack_8,auStack_18,auStack_10,uStack_4,iStack_8 + 1000,
                 param_4);
    pvVar4 = operator_new(0x14);
    if (pvVar4 == (void *)0x0) {
      param_3 = 0;
    }
    else {
      param_3 = FUN_00532440(param_1,uVar2);
    }
    iVar1 = *(int *)(iVar1 + 4);
    iVar5 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
    FUN_00517200(1);
    *(int *)(iVar1 + 4) = iVar5;
    **(int **)(iVar5 + 4) = iVar5;
    return;
  }
  pvVar4 = operator_new(0x14);
  if (pvVar4 == (void *)0x0) {
    param_3 = 0;
  }
  else {
    param_3 = FUN_00532440(param_1,param_3);
  }
  iVar1 = *(int *)(param_4 + 4);
  iVar5 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_3);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar5;
  **(int **)(iVar5 + 4) = iVar5;
  return;
}


// ==== FUN_00516de0 @ 0x00516de0 ====

undefined4
FUN_00516de0(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5
            )

{
  undefined1 local_c [4];
  undefined4 local_8;
  undefined4 local_4;
  
  local_8 = FUN_005170b0();
  local_4 = 0;
  switch(*(undefined1 *)(param_4 + 0xb)) {
  case 1:
    FUN_00516cc0(param_2,param_3,param_4,local_c);
    break;
  case 2:
    FUN_00516a60(param_2,param_3,param_4,local_c,param_5);
    break;
  case 6:
    FUN_00516940(param_2,param_3,param_4,local_c);
    break;
  case 7:
    FUN_00515e60(param_2,param_3,param_4,local_c);
    break;
  case 8:
    FUN_00515f40(param_2,param_3,param_4,local_c);
    break;
  case 9:
    FUN_00516100(param_2,param_3,param_4,local_c);
    break;
  case 10:
    FUN_00516330(param_2,param_3,param_4,local_c);
    break;
  case 0xb:
    FUN_00515df0(param_2,param_4,local_c);
    break;
  case 0xc:
    FUN_00516170(param_2,param_3,param_4,local_c);
    break;
  case 0xd:
    FUN_00516250(param_2,param_3,param_4,local_c);
    break;
  case 0xe:
    FUN_00516020(param_2,param_3,param_4,local_c);
    break;
  case 0xf:
    FUN_005163a0(param_2,param_3,param_4,local_c);
    break;
  case 0x11:
    FUN_00516480(param_2,param_3,param_4,local_c);
    break;
  case 0x12:
    FUN_005164f0(param_2,param_3,param_4,local_c);
    break;
  case 0x15:
    FUN_00516560(param_2,param_3,param_4,local_c);
    break;
  case 0x16:
    FUN_005165d0(param_2,param_3,param_4,local_c);
    break;
  case 0x17:
    FUN_00516640(param_2,param_3,param_4,local_c);
    break;
  case 0x1e:
    FUN_005166b0(param_2,param_3,param_4,local_c);
    break;
  case 0x1f:
    FUN_00516410(param_2,param_3,param_4,local_c);
  }
  FUN_005173d0(local_c);
  FUN_008984a0();
  return param_1;
}


// ==== FUN_005170b0 @ 0x005170b0 ====

void FUN_005170b0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981760;
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


// ==== Catch@0051711f @ 0x0051711f ====

void Catch_0051711f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00517140 @ 0x00517140 ====

void FUN_00517140(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981770;
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


// ==== Catch@005171a9 @ 0x005171a9 ====

void Catch_005171a9(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005171c0 @ 0x005171c0 ====

void FUN_005171c0(int *param_1,int *param_2)

{
  int in_ECX;
  
  if (param_2 == *(int **)(in_ECX + 4)) {
    *param_1 = *param_2;
    return;
  }
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  _free(param_2);
  return;
}


// ==== FUN_00517200 @ 0x00517200 ====

void FUN_00517200(uint param_1)

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
  
  if (0x3fffffffU - *(int *)(in_ECX + 8) < param_1) {
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


// ==== FUN_00517290 @ 0x00517290 ====

void FUN_00517290(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_00517140(param_1,*(undefined4 *)(param_1 + 4),param_2);
  FUN_00517200(1);
  *(int *)(param_1 + 4) = iVar1;
  **(int **)(iVar1 + 4) = iVar1;
  return;
}


// ==== FUN_005172d0 @ 0x005172d0 ====

void FUN_005172d0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981780;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != param_3; param_2 = (undefined4 *)*param_2) {
    FUN_00517290(param_1,param_2 + 2);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00517338 @ 0x00517338 ====

void Catch_00517338(void)

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


// ==== FUN_00517370 @ 0x00517370 ====

void FUN_00517370(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  iVar2 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),param_1);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}


// ==== FUN_005173b0 @ 0x005173b0 ====

void FUN_005173b0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005172d0(param_1,param_2,param_3,param_3);
  return;
}


// ==== FUN_005173d0 @ 0x005173d0 ====

void FUN_005173d0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981790;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uVar1 = FUN_005170b0();
  *(undefined4 *)(in_ECX + 4) = uVar1;
  *(undefined4 *)(in_ECX + 8) = 0;
  local_8 = 0;
  FUN_005173b0(**(undefined4 **)(in_ECX + 4),**(undefined4 **)(param_1 + 4),
               *(undefined4 **)(param_1 + 4));
  ExceptionList = local_10;
  return;
}


// ==== Catch@00517459 @ 0x00517459 ====

void Catch_00517459(void)

{
  FUN_008984a0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00517470 @ 0x00517470 ====

void FUN_00517470(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6d64;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00517490 @ 0x00517490 ====

undefined4 FUN_00517490(void)

{
  return 0x10050100;
}


// ==== FUN_005174a0 @ 0x005174a0 ====

undefined4 FUN_005174a0(void)

{
  return 0x70050008;
}


// ==== FUN_005174b0 @ 0x005174b0 ====

undefined4 FUN_005174b0(void)

{
  return 0x70260000;
}


// ==== FUN_005174c0 @ 0x005174c0 ====

void FUN_005174c0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = **(int **)(in_ECX + 0x24);
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  (**(code **)(iVar1 + 8))(uVar2);
  return;
}


// ==== FUN_00517510 @ 0x00517510 ====

void FUN_00517510(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = **(int **)(in_ECX + 0x24);
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  (**(code **)(iVar1 + 0x10))(uVar2);
  return;
}


// ==== FUN_00517530 @ 0x00517530 ====

void FUN_00517530(undefined4 param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar1 = **(int **)(in_ECX + 0x24);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))(param_1);
  cVar2 = (**(code **)(iVar1 + 0x1c))(uVar3);
  if (cVar2 != '\0') {
    (**(code **)(**(int **)(in_ECX + 0x24) + 0x20))(param_1);
  }
  return;
}


// ==== FUN_00517580 @ 0x00517580 ====

void FUN_00517580(int param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x4c))(param_1 + 4);
  (**(code **)(**(int **)(in_ECX + 0x20) + 4))();
  return;
}


// ==== FUN_005175a0 @ 0x005175a0 ====

void FUN_005175a0(void)

{
  int *piVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *in_ECX;
  float10 fVar5;
  
  uVar3 = (**(code **)(*(int *)in_ECX[1] + 0x20))(0);
  cVar2 = (**(code **)(*(int *)in_ECX[1] + 0x30))();
  if (cVar2 == '\0') {
    FUN_004dd240(0x16,0,uVar3,0,0);
  }
  (**(code **)(*in_ECX + 0x24))();
  cVar2 = FUN_005083d0();
  piVar1 = (int *)in_ECX[1];
  if (cVar2 == '\0') {
    (**(code **)(*in_ECX + 0x24))();
    uVar4 = FUN_005082b0();
    (**(code **)(*in_ECX + 0x24))(uVar4);
    uVar4 = FUN_005082f0();
    uVar4 = (**(code **)(*piVar1 + 0x10))(uVar4);
    uVar4 = (**(code **)(*piVar1 + 0x10))(uVar4);
    (**(code **)(*in_ECX + 0x24))(uVar4);
    uVar4 = FUN_00508310();
    FUN_00532600(uVar4);
  }
  else {
    (**(code **)(*in_ECX + 0x24))();
    uVar4 = FUN_005082b0();
    (**(code **)(*in_ECX + 0x24))(uVar4);
    uVar4 = FUN_005082e0();
    uVar4 = (**(code **)(*piVar1 + 0x10))(uVar4);
    uVar4 = (**(code **)(*piVar1 + 0x10))(uVar4);
    (**(code **)(*in_ECX + 0x24))(uVar4);
    uVar4 = FUN_00508310();
    FUN_005326c0(uVar4);
  }
  (**(code **)(*in_ECX + 0x24))();
  FUN_005082d0();
  fVar5 = (float10)FUN_0040d0a0(0x3f800000,0x40400000,0);
  FUN_004dd240(6,uVar3,1,(int)ROUND(fVar5));
  return;
}


// ==== FUN_005176d0 @ 0x005176d0 ====

void FUN_005176d0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005176d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x20) + 8))();
  return;
}


// ==== FUN_005176e0 @ 0x005176e0 ====

void FUN_005176e0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005176e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x20) + 0xc))();
  return;
}


// ==== FUN_005176f0 @ 0x005176f0 ====

void FUN_005176f0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005176f5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x28))();
  return;
}


// ==== FUN_00517700 @ 0x00517700 ====

void FUN_00517700(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00517705. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_00517710 @ 0x00517710 ====

void FUN_00517710(undefined4 param_1,int param_2)

{
  int in_ECX;
  
  if (param_2 == 0) {
    (**(code **)(**(int **)(in_ECX + 0x28) + 8))();
    return;
  }
  (**(code **)(**(int **)(in_ECX + 0x28) + 4))(param_1);
  return;
}


// ==== FUN_00517730 @ 0x00517730 ====

void FUN_00517730(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00517735. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x28) + 0xc))();
  return;
}


// ==== FUN_00517770 @ 0x00517770 ====

void FUN_00517770(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *DAT_00b5acd8;
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  (**(code **)(iVar1 + 0xc))(uVar2);
  return;
}


// ==== FUN_00517790 @ 0x00517790 ====

undefined1 FUN_00517790(float *param_1)

{
  float fVar1;
  char cVar2;
  int *piVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int *in_ECX;
  float10 fVar6;
  float *pfStack_20;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  pfStack_20 = (float *)0x51779e;
  cVar2 = (**(code **)(*(int *)in_ECX[1] + 0x2c))();
  if (cVar2 == '\0') {
    return 0;
  }
  pfStack_20 = (float *)0x5177b0;
  piVar3 = (int *)(**(code **)(*in_ECX + 8))();
  pfStack_20 = (float *)0x5177b7;
  pfVar4 = (float *)(**(code **)(*piVar3 + 0x28))();
  fStack_10 = *pfVar4;
  fStack_c = pfVar4[1];
  fStack_8 = *param_1 - fStack_10;
  pfStack_20 = &fStack_8;
  fStack_4 = param_1[1] - fStack_c;
  thunk_FUN_0079de77(&fStack_18);
  fVar6 = (float10)FUN_0040d0a0(0xbe99999a,0x3e99999a);
  fStack_4 = (float)fVar6;
  fVar6 = (float10)FUN_0040d5f0(&pfStack_20);
  pfVar4 = (float *)FUN_0040d600(&fStack_10,(float)(fVar6 + (float10)fStack_4));
  pfStack_20 = (float *)*pfVar4;
  fVar1 = pfVar4[1];
  fVar6 = (float10)FUN_0040d0a0(0x3f800000,0x40000000);
  fStack_4 = (float)fVar6;
  fStack_c = fVar1 * fStack_4 + fStack_14;
  fStack_10 = (float)pfStack_20 * fStack_4 + fStack_18;
  (**(code **)(*DAT_00b5a78c + 0x14))(fStack_10,fStack_c);
  puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar5 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar5 = &PTR_FUN_009b6dbc;
  FUN_00797a20(puVar5);
  return 1;
}


// ==== FUN_005178d0 @ 0x005178d0 ====

void FUN_005178d0(undefined1 param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x44) = param_1;
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x74) + 0x14))();
    if (*(char *)(in_ECX + 0x44) == '\x01') {
      (**(code **)(*piVar2 + 0x10))(3);
      (**(code **)(*DAT_00b5ad1c + 8))();
      return;
    }
    (**(code **)(*piVar2 + 0x10))(1);
    (**(code **)(*DAT_00b5ad1c + 8))();
  }
  return;
}


// ==== FUN_00517930 @ 0x00517930 ====

void FUN_00517930(void)

{
                    /* WARNING: Could not recover jumptable at 0x00517943. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5ac28 + 0x28))();
  return;
}


// ==== FUN_005179b0 @ 0x005179b0 ====

bool FUN_005179b0(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5acd4 + 8))();
  return iVar1 != 0;
}


// ==== FUN_005179d0 @ 0x005179d0 ====

void FUN_005179d0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  float fVar3;
  float afStack_8 [2];
  
  iVar1 = (**(code **)(*DAT_00b5acd4 + 8))();
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5ac28 + 0x30))();
    return;
  }
  iVar1 = (**(code **)(*DAT_00b5a988 + 0x14))();
  afStack_8[0] = *(float *)(iVar1 + 8);
  switch(*(undefined4 *)(in_ECX + 0x2c)) {
  case 0:
    fVar3 = DAT_00aec34c * DAT_009a000c;
    break;
  case 1:
    fVar3 = DAT_00aec34c * DAT_0099d0f8;
    break;
  case 2:
    fVar3 = DAT_00aec34c * DAT_009b6df8;
    break;
  case 3:
    fVar3 = DAT_00aec34c;
    break;
  case 4:
    (**(code **)(*DAT_00b5ac28 + 0x2c))();
    *(undefined4 *)(in_ECX + 0x2c) = 9;
    return;
  case 5:
    fVar3 = DAT_00aec34c * DAT_009b0300;
    break;
  case 6:
    fVar3 = DAT_00aec34c * DAT_0099d0b4;
    break;
  case 7:
    goto LAB_00517ab5;
  case 8:
    fVar3 = DAT_00aec34c * DAT_009b6df4;
    break;
  default:
    goto switchD_00517a11_default;
  }
  afStack_8[0] = fVar3 + afStack_8[0];
LAB_00517ab5:
  iVar1 = *DAT_00b5ac28;
  uVar2 = FUN_0040d600(afStack_8,afStack_8[0]);
  (**(code **)(iVar1 + 0x24))(uVar2);
switchD_00517a11_default:
  return;
}


// ==== FUN_00517b00 @ 0x00517b00 ====

void FUN_00517b00(char param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_1 == '\x01') {
    uVar1 = (**(code **)(*in_ECX + 0xc))();
    iVar2 = FUN_004dd240(0x23,3,0,0,uVar1);
    in_ECX[0x10] = iVar2;
    return;
  }
  iVar2 = *DAT_00b5ac70;
  uVar1 = (**(code **)(*in_ECX + 0xc))(in_ECX[0x10]);
  (**(code **)(iVar2 + 0x20))(uVar1);
  return;
}


// ==== FUN_00517b50 @ 0x00517b50 ====

void FUN_00517b50(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  
  if (param_1 == 0) {
    uVar3 = (**(code **)(*DAT_00b5ae14 + 0x18))();
    cVar2 = (**(code **)(*DAT_00b5add0 + 0x3c))(uVar3);
    if ((cVar2 != '\0') && (cVar2 = (**(code **)(*DAT_00b5ac98 + 0x44))(), cVar2 != '\0')) {
      (**(code **)(*DAT_00b5ac94 + 0x14))();
      return;
    }
    cVar2 = (**(code **)(*DAT_00b5add0 + 0x44))(uVar3);
    if ((cVar2 != '\0') && (cVar2 = (**(code **)(*DAT_00b5ada8 + 0x20))(), cVar2 != '\0')) {
      return;
    }
    puVar4 = operator_new(4);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = &PTR_FUN_009b6de4;
      FUN_00797a20(puVar4);
      return;
    }
    FUN_00797a20(0);
  }
  else {
    if (param_1 == 1) {
      iVar1 = *DAT_00b5add0;
      uVar3 = (**(code **)(*DAT_00b5ae14 + 0x18))();
      cVar2 = (**(code **)(iVar1 + 0x3c))(uVar3);
      if (cVar2 != '\0') {
        (**(code **)(*DAT_00b5ac94 + 0x40))();
        return;
      }
      puVar4 = operator_new(4);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = &PTR_FUN_009b6504;
      }
      FUN_00797a20(puVar4);
                    /* WARNING: Could not recover jumptable at 0x00517bdb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*DAT_00b5af2c + 8))();
      return;
    }
    if (param_1 == 2) {
      (**(code **)(*DAT_00b5ad90 + 0x18))();
      return;
    }
  }
  return;
}


// ==== FUN_00517c70 @ 0x00517c70 ====

void FUN_00517c70(void)

{
                    /* WARNING: Could not recover jumptable at 0x00517c78. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5acdc + 4))();
  return;
}


// ==== FUN_00517c90 @ 0x00517c90 ====

bool FUN_00517c90(void)

{
  int iVar1;
  undefined1 auStack_280 [604];
  int iStack_24;
  
  iVar1 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if ((iVar1 == 0) || (*(int **)(iVar1 + 0x10) == (int *)0x0)) {
    return false;
  }
  (**(code **)(**(int **)(iVar1 + 0x10) + 0x30))(auStack_280);
  return iStack_24 == 0;
}


// ==== FUN_00517cd0 @ 0x00517cd0 ====

void FUN_00517cd0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  void *_Memory;
  int in_ECX;
  int *piVar3;
  
  piVar1 = *(int **)(in_ECX + 0x34);
  piVar3 = (int *)*piVar1;
  if (piVar3 != piVar1) {
    do {
      if ((undefined4 *)piVar3[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)piVar3[2])(1);
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != piVar1);
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x34);
  _Memory = (void *)*puVar2;
  *puVar2 = puVar2;
  *(int *)(*(int *)(in_ECX + 0x34) + 4) = *(int *)(in_ECX + 0x34);
  *(undefined4 *)(in_ECX + 0x38) = 0;
  if (_Memory == *(void **)(in_ECX + 0x34)) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00517d60 @ 0x00517d60 ====

void FUN_00517d60(uint param_1)

{
  int *piVar1;
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  local_4 = in_ECX;
  if ((int *)in_ECX[2] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[2] + 8))();
  }
  param_1 = param_1 & 0xff;
  FUN_004d8980(&local_4,&param_1);
  if (local_4 == (undefined4 *)in_ECX[4]) {
    local_4 = *(undefined4 **)in_ECX[4];
  }
  piVar1 = (int *)local_4[4];
  in_ECX[2] = piVar1;
  (**(code **)(*piVar1 + 4))();
  return;
}


// ==== FUN_00517db0 @ 0x00517db0 ====

void FUN_00517db0(void)

{
  int in_ECX;
  undefined1 *puVar1;
  undefined1 *local_10;
  undefined1 *puStack_c;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x34))(&local_10);
  puVar1 = local_10;
  if (local_10 != puStack_c) {
    do {
      FUN_004dd240(0x13,*puVar1,0,2,0);
      puVar1 = puVar1 + 1;
    } while (puVar1 != puStack_c);
  }
  if (local_10 == (undefined1 *)0x0) {
    return;
  }
  _free(local_10);
  return;
}


// ==== FUN_00517e10 @ 0x00517e10 ====

undefined4 FUN_00517e10(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 extraout_EAX;
  int in_ECX;
  void *_Memory;
  undefined1 auStack_38 [4];
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 0xc);
  iVar3 = *(int *)(param_1 + 8);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 8))();
  iVar5 = (**(code **)(*piVar4 + 0x74))();
  iVar5 = *(int *)(iVar5 + 0x18);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 8))();
  iVar6 = (**(code **)(*piVar4 + 0x74))();
  iVar6 = *(int *)(iVar6 + 0x1c);
  (**(code **)(**(int **)(in_ECX + 4) + 0x40))((float)iVar1,(float)iVar3);
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 1) {
    uVar7 = 0x280001;
    goto LAB_00517eca;
  }
  if (iVar1 != 2) {
    if (iVar1 != 3) {
      return 1;
    }
    if (iVar5 != *(int *)(param_1 + 4)) {
      if (iVar6 != *(int *)(param_1 + 8)) {
        uVar7 = 0x280022;
        goto LAB_00517eca;
      }
      if (iVar5 != *(int *)(param_1 + 4)) {
        uVar7 = 0x280001;
        goto LAB_00517eca;
      }
    }
    if (iVar6 == *(int *)(param_1 + 8)) {
      return 1;
    }
  }
  uVar7 = 0x280002;
LAB_00517eca:
  uVar7 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar7);
  FUN_00401660(uVar7,0,0xffffffff);
  piVar4 = DAT_00b5ad0c;
  _Memory = (void *)0xf;
  FUN_00401660(auStack_38 + 8,0,0xffffffff);
  (**(code **)(*piVar4 + 0x28))(2);
  if ((uint)(float)iVar2 < 0x10) {
    return 1;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00517f50 @ 0x00517f50 ====

void FUN_00517f50(int param_1)

{
  int *piVar1;
  short sVar2;
  undefined4 uVar3;
  int in_ECX;
  void *pvStack_44;
  uint uVar4;
  uint uStack_28;
  
  uStack_28 = (uint)*(byte *)(param_1 + 4);
  sVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x48))();
  if (sVar2 != 0) {
    uVar4 = 0;
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x280004);
    FUN_00401660(uVar3,0,0xffffffff);
    piVar1 = DAT_00b5ad0c;
    FUN_00401660(&uStack_28,0,0xffffffff);
    (**(code **)(*piVar1 + 0x28))(2);
    if (0xf < uVar4) {
      _free(pvStack_44);
      return;
    }
  }
  return;
}


// ==== FUN_00517ff0 @ 0x00517ff0 ====

/* WARNING: Removing unreachable block (ram,0x00518279) */

void FUN_00517ff0(void)

{
  void *unaff_ESI;
  uint unaff_EDI;
  int iStack_ac;
  char *pcStack_a8;
  char *pcStack_a0;
  char **ppcStack_90;
  char *pcStack_8c;
  int *piVar1;
  uint uStack_84;
  char *pcStack_80;
  char *pcStack_78;
  void *pvVar2;
  uint uVar3;
  undefined4 uStack_70;
  uint uVar4;
  void *pvVar5;
  uint *puVar6;
  uint uVar7;
  int iStack_5c;
  char *pcStack_58;
  undefined4 uStack_48;
  uint local_38;
  uint local_34;
  void *pvStack_30;
  uint uStack_2c;
  uint uStack_28;
  void *local_24;
  undefined4 local_20;
  uint local_1c;
  undefined1 local_18;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 local_8;
  undefined4 local_4;
  
  uStack_48 = (uint *)0x1b;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740();
  uStack_48 = (uint *)0x7;
  local_20 = 0xf;
  local_24 = (void *)0x0;
  local_34 = local_34 & 0xffffff00;
  FUN_00401740();
  uStack_48 = &local_1c;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uStack_2c) {
    pcStack_58 = (char *)0x518061;
    _free(unaff_ESI);
    return;
  }
  uStack_2c = 0xf;
  pvStack_30 = (void *)0x0;
  if (0xf < uStack_10) {
    pcStack_58 = (char *)0x518080;
    _free(local_24);
    return;
  }
  pcStack_58 = s_adv_levelup__point__009b69a8;
  uStack_10 = 0xf;
  uStack_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  iStack_5c = 0x51809f;
  FUN_00401740();
  pcStack_58 = s_adv_levelup_009b69bc;
  uStack_2c = 0xf;
  pvStack_30 = (void *)0x0;
  iStack_5c = 0x5180bb;
  FUN_00401740();
  pcStack_58 = (void *)0x1;
  iStack_5c = (int)register0x00000010 + -0x44;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < local_38) {
    _free((void *)0x1);
    return;
  }
  local_38 = 0xf;
  if (0xf < local_1c) {
    _free(pvStack_30);
    return;
  }
  local_1c = 0xf;
  local_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  FUN_00401740();
  local_38 = 0xf;
  FUN_00401740();
  puVar6 = &local_34;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < unaff_EDI) {
    uStack_70 = (char *)0x518163;
    _free(pcStack_58);
    return;
  }
  uStack_48 = (uint *)0x0;
  pcStack_58 = (char *)((uint)pcStack_58 & 0xffffff00);
  if (0xf < uStack_28) {
    uStack_70 = (char *)0x518182;
    _free((void *)0x0);
    return;
  }
  uStack_70 = s_userrevive_009b69ec;
  uStack_28 = 0xf;
  uStack_2c = 0;
  FUN_00401740();
  uVar4 = 0;
  uStack_70 = (char *)((int)register0x00000010 + -0x40);
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < pvStack_30) {
    pcStack_78 = (char *)0x5181c2;
    _free((void *)0xf);
    return;
  }
  pcStack_78 = s_userrespawn_009b69f8;
  pvStack_30 = (void *)0xf;
  local_34 = 0;
  FUN_00401740();
  pvVar2 = (void *)0x0;
  pcStack_78 = (char *)&uStack_48;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < local_38) {
    pcStack_80 = (char *)0x518202;
    _free((void *)0x0);
    return;
  }
  pcStack_80 = s_testskill__style___action___effe_009b6a04;
  local_38 = 0xf;
  uStack_84 = 0x518221;
  FUN_00401740();
  pcStack_80 = s_testskill_009b6a28;
  pcStack_58 = (char *)0x0;
  uStack_84 = 0x51823d;
  FUN_00401740();
  pcStack_80 = (void *)0x3;
  uStack_84 = (int)register0x00000010 - 0x6c;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((uint *)0xf < puVar6) {
    pcStack_8c = (char *)0x518264;
    _free(pvVar2);
    return;
  }
  uVar3 = (uint)pvVar2 & 0xffffff00;
  pcStack_8c = s_changelogicmode__mode__009b6a34;
  uStack_48 = (uint *)0x0;
  pcStack_58 = (char *)((uint)pcStack_58 & 0xffffff00);
  ppcStack_90 = (char **)0x5182a2;
  FUN_00401740();
  pcStack_8c = s_changelogicmode_009b6a4c;
  uVar7 = 0xf;
  pvVar2 = (void *)(uVar3 & 0xffffff00);
  ppcStack_90 = (char **)0x5182bd;
  FUN_00401740();
  piVar1 = &iStack_5c;
  pcStack_8c = (char *)0x1;
  ppcStack_90 = &pcStack_78;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < uVar4) {
    _free(pcStack_80);
    return;
  }
  pvVar5 = (void *)0xf;
  uStack_70 = (char *)0x0;
  pcStack_80 = (char *)((uint)pcStack_80 & 0xffffff00);
  if ((uint *)0xf < &local_38) {
    _free((void *)0x0);
    return;
  }
  FUN_00401740();
  uVar4 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < pcStack_58) {
    pcStack_a0 = (char *)0x518344;
    _free(pvVar5);
    return;
  }
  pcStack_a0 = s_previewclass_009b6a68;
  pcStack_58 = (char *)0xf;
  iStack_5c = 0;
  uVar3 = (uint)pvVar5 & 0xffffff00;
  FUN_00401740();
  pvVar5 = (void *)0x2;
  pcStack_a0 = (char *)&uStack_70;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  if (0xf < uVar7) {
    pcStack_a8 = (char *)0x518385;
    _free(pvVar2);
    return;
  }
  pcStack_a8 = s_siege_start__time__009b6a78;
  iStack_ac = 0x5183a4;
  FUN_00401740();
  pcStack_a8 = s_siege_start_009b6a8c;
  pcStack_80 = (void *)0x0;
  ppcStack_90 = (char **)((uint)ppcStack_90 & 0xffffff00);
  iStack_ac = 0x5183c0;
  FUN_00401740();
  pcStack_a8 = (void *)0x1;
  iStack_ac = (int)register0x00000010 + -0x94;
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if ((int *)0xf < piVar1) {
    _free(pvVar5);
    return;
  }
  pcStack_8c = (char *)0x0;
  if (0xf < uVar3) {
    _free(pcStack_80);
    return;
  }
  uStack_70 = (char *)0x0;
  pcStack_80 = (char *)((uint)pcStack_80 & 0xffffff00);
  FUN_00401740(s_siege_end__time__009b6a98,0x10);
  pcStack_8c = (void *)0x0;
  FUN_00401740(s_siege_end_009b6aac,9);
  pvVar2 = (void *)0x1;
  (**(code **)(*DAT_00b5a6c8 + 8))(&pcStack_a0,1,&uStack_84);
  if (0xf < uVar4) {
    _free(pcStack_a8);
    return;
  }
  pcStack_a8 = (char *)((uint)pcStack_a8 & 0xffffff00);
  if ((char *)0xf < pcStack_78) {
    _free(pcStack_8c);
    return;
  }
  pcStack_78 = (char *)0xf;
  pcStack_8c = (char *)((uint)pcStack_8c & 0xffffff00);
  FUN_00401740(s_observer_mode__true_false__009b6ab8,0x1a);
  pcStack_a8 = (char *)((uint)pcStack_a8 & 0xffffff00);
  FUN_00401740(s_observer_mode_009b6ad4,0xd);
  (**(code **)(*DAT_00b5a6c8 + 8))(&iStack_ac,1,&ppcStack_90);
  if ((char *)0xf < pcStack_a0) {
    _free(pvVar2);
    return;
  }
  pcStack_a0 = (char *)0xf;
  if (uStack_84 < 0x10) {
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_00518520 @ 0x00518520 ====

/* WARNING: Removing unreachable block (ram,0x0051871c) */
/* WARNING: Removing unreachable block (ram,0x0051875b) */
/* WARNING: Removing unreachable block (ram,0x005186dd) */
/* WARNING: Removing unreachable block (ram,0x0051879a) */

void FUN_00518520(void)

{
  void *unaff_EBX;
  void *unaff_ESI;
  void *unaff_EDI;
  undefined1 auStackY_dc [128];
  undefined1 *_Memory;
  undefined1 *puVar1;
  uint uVar2;
  undefined1 auStack_2a [2];
  undefined4 local_1c;
  uint local_18;
  uint uStack_14;
  uint uStack_10;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = local_18 & 0xffffff00;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740();
  puVar1 = auStack_2a + 10;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_c) {
    _free(unaff_EBX);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_10) {
    _free(unaff_ESI);
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < uStack_14) {
    _free(unaff_EDI);
    return;
  }
  uStack_14 = 0xf;
  local_18 = 0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < local_18) {
    _free(&local_1c);
    return;
  }
  local_18 = 0xf;
  local_1c = (void *)0x0;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  if (0xf < local_1c) {
    _free(puVar1);
    return;
  }
  local_1c = (void *)0xf;
  FUN_00401740();
  puVar1 = auStack_2a + -10;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740(s_showobject_009b6b38);
  _Memory = auStack_2a + -0xe;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740(s_previewclass_009b6b44,0xc);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -0x12);
  FUN_00401740(s_siege_start_009b6b54,0xb);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_2a + -0x16);
  uVar2 = 0;
  FUN_00401740(s_siege_end_009b6b60,9);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_dc + 0x98);
  if (0xf < uVar2) {
    _free(puVar1);
    return;
  }
  uVar2 = 0;
  FUN_00401740(s_observer_mode_009b6b6c,0xd);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStackY_dc + 0x94);
  if (uVar2 < 0x10) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00518830 @ 0x00518830 ====

void FUN_00518830(void)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  int in_ECX;
  void *unaff_EDI;
  undefined1 auStack_1a [6];
  uint uStack_14;
  
  uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
  iVar1 = *DAT_00b5acd8;
  uVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))(uVar4);
  cVar3 = (**(code **)(iVar1 + 4))(uVar4);
  piVar2 = DAT_00b5a6c0;
  if (cVar3 == '\0') {
    (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
    FUN_00401740(s_New_Enter___PC___08X___009b6b7c,0x16);
    uVar4 = FUN_00404230(auStack_1a + -10);
    (**(code **)(*piVar2 + 4))(2,uVar4);
    if (0xf < uStack_14) {
      _free(unaff_EDI);
      return;
    }
  }
  return;
}


// ==== FUN_005188c0 @ 0x005188c0 ====

/* WARNING: Removing unreachable block (ram,0x00518995) */
/* WARNING: Removing unreachable block (ram,0x00518947) */
/* WARNING: Removing unreachable block (ram,0x005189f3) */
/* WARNING: Removing unreachable block (ram,0x00518903) */

void FUN_005188c0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *piVar3;
  char cVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x2c))(*(undefined4 *)(param_1 + 0xc));
  FUN_00401740(s_CGameUser__IACTIONCONTROLLER___>_009b6b94,0x27);
  if (DAT_00b5acdc != (int *)0x0) {
    (**(code **)(*DAT_00b5acdc + 0xc))(*(undefined4 *)(param_1 + 0xc));
  }
  FUN_00401740(s_CGameUser__SendBattleEndPossible_009b6bbc,0x20);
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  cVar4 = (**(code **)(*(int *)in_ECX[9] + 0x14))(uVar1);
  if (cVar4 != '\0') {
    (**(code **)(*(int *)in_ECX[9] + 0x18))(uVar1);
  }
  FUN_00401740(s_CGameUser__SendChaoticEndPossibl_009b6be0,0x21);
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  iVar8 = *(int *)in_ECX[9];
  uVar5 = (**(code **)(*(int *)in_ECX[1] + 0x10))(uVar1);
  cVar4 = (**(code **)(iVar8 + 0x1c))(uVar5);
  if (cVar4 != '\0') {
    (**(code **)(*(int *)in_ECX[9] + 0x20))(uVar1);
  }
  FUN_00401740(s_CGameUser__ISTATUS__IUIHANDLER___009b6c04,0x30);
  (**(code **)(*DAT_00b5ae84 + 4))(param_1);
  FUN_005179d0();
  puVar7 = (undefined4 *)in_ECX[0xd];
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  for (puVar2 = (undefined4 *)*puVar7; puVar2 != puVar7; puVar2 = (undefined4 *)*puVar2) {
    (**(code **)(*(int *)puVar2[2] + 4))(uVar1);
  }
  if ((char)in_ECX[0xf] != '\0') {
    (**(code **)(*DAT_00b5acd8 + 0x14))();
  }
  piVar6 = (int *)(**(code **)(*in_ECX + 8))();
  piVar3 = DAT_00b5a988;
  puVar7 = (undefined4 *)(**(code **)(*piVar6 + 0x28))();
  (**(code **)(*piVar3 + 0x2c))(*puVar7,puVar7[1]);
  iVar8 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  if (120000 < (uint)(iVar8 - in_ECX[0x12])) {
    (**(code **)(*DAT_00b5acdc + 0x18))();
  }
  return;
}


// ==== FUN_00518a90 @ 0x00518a90 ====

void FUN_00518a90(undefined4 param_1)

{
  code *pcVar1;
  char cVar2;
  int *piVar3;
  int *in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  int iStack_8;
  uint uStack_4;
  
  piVar3 = (int *)(**(code **)(*in_ECX + 8))();
  iStack_8 = (**(code **)(*piVar3 + 0x1c))();
  if (iStack_8 != 0) {
    piVar3 = (int *)(**(code **)(*in_ECX + 8))();
    (**(code **)(*piVar3 + 0x1c))();
    cVar2 = FUN_00511d60();
    if (cVar2 != (char)param_1) {
      piVar3 = (int *)(**(code **)(*in_ECX + 8))();
      (**(code **)(*piVar3 + 0x1c))(param_1);
      FUN_00511f40(param_1);
    }
    return;
  }
  uStack_4 = 0xf;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_GetPC___>GetRemoteDoll______NULL_009b6cb8,0x20);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_00518b30 @ 0x00518b30 ====

/* WARNING: Removing unreachable block (ram,0x00518c3f) */

void FUN_00518b30(void)

{
  int *piVar1;
  short sVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_ESI;
  undefined1 *puVar4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined1 auStack_a6 [6];
  uint uStack_a0;
  undefined1 auStack_94 [4];
  undefined1 uStack_90;
  undefined4 uStack_80;
  void *pvStack_7c;
  undefined1 auStack_78 [4];
  void *pvStack_74;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  uint uStack_60;
  undefined1 auStack_5c [28];
  undefined1 auStack_40 [4];
  void *pvStack_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  int iStack_24;
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  uStack_bc = 0x280003;
  uStack_c0 = 0;
  uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))();
  pvStack_7c = (void *)0xf;
  uStack_80 = 0;
  uStack_90 = 0;
  FUN_00401660(uVar3,0,0xffffffff);
  uStack_60 = 0xf;
  uStack_64 = 0;
  pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
  FUN_00401740(s_Exp__009b6cdc,5);
  puVar4 = auStack_78;
  FUN_00401740(&DAT_009b6ce4,2);
  uVar3 = FUN_00404230(&iStack_24);
  FUN_00401660(auStack_94,0,0xffffffff);
  uVar3 = FUN_00405bd0(auStack_40,auStack_a6 + -10,uVar3,puVar4);
  FUN_00405bd0(auStack_5c,uVar3);
  piVar1 = DAT_00b5ad0c;
  if (0xf < uStack_28) {
    _free(pvStack_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  if (0xf < uStack_60) {
    _free(pvStack_74);
    return;
  }
  FUN_00401660(auStack_5c,0,0xffffffff);
  (**(code **)(*piVar1 + 0x28))(2);
  sVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x44))(*(undefined4 *)(iStack_24 + 4));
  if (sVar2 != 0) {
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x280004);
    FUN_00401660(uVar3,0,0xffffffff);
    piVar1 = DAT_00b5ad0c;
    FUN_00401660(&uStack_c0,0,0xffffffff);
    (**(code **)(*piVar1 + 0x28))(2);
  }
  if (0xf < uStack_68) {
    _free(pvStack_7c);
    return;
  }
  uStack_68 = 0xf;
  uStack_6c = 0;
  pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
  if (uStack_a0 < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_00518d70 @ 0x00518d70 ====

void FUN_00518d70(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  if (*(int *)(param_1 + 4) == 0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x38))
              (*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_1 + 0xc),
               *(undefined4 *)(param_1 + 0x10));
    iVar1 = *DAT_00b5add0;
    uVar3 = (**(code **)(*DAT_00b5ae14 + 0x18))();
    cVar2 = (**(code **)(iVar1 + 0x3c))(uVar3);
    if (cVar2 == '\0') {
      puVar4 = operator_new(4);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = &PTR_FUN_009b6504;
      }
      FUN_00797a20(puVar4);
      (**(code **)(*DAT_00b5af2c + 8))(5);
    }
    else {
      (**(code **)(*DAT_00b5ac94 + 0x40))();
    }
  }
  FUN_00401740(s_UserPC_Revive_Message_Recive____009b6ce8,0x1f);
  uVar3 = FUN_00404230(auStack_1c);
  FUN_00796d50(uVar3);
  if (uStack_4 < 0x10) {
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_00518e40 @ 0x00518e40 ====

undefined4 FUN_00518e40(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  int iVar5;
  int *in_ECX;
  undefined1 local_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  iVar5 = param_1 + 8;
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_userrevive_009b6c38,10);
  if (iVar3 == 0) {
    uVar4 = (**(code **)(*(int *)in_ECX[1] + 0x10))();
    FUN_00532480(0,uVar4);
    return 1;
  }
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_userrespawn_009b6c44,0xb);
  if (iVar3 == 0) {
    uVar4 = (**(code **)(*(int *)in_ECX[1] + 0x10))();
    FUN_005324c0(0,uVar4);
    return 1;
  }
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_levelup_009b6c50,7);
  if (iVar3 == 0) {
    uVar4 = FUN_00459160(local_1c,0);
    uVar4 = thunk_FUN_00796f80(uVar4);
    piVar1 = DAT_00b5a6ac;
    if (uStack_4 < 0x10) {
      uVar4 = (**(code **)(*(int *)in_ECX[1] + 0x10))(uVar4);
      uVar4 = (**(code **)(*piVar1 + 0x20))(uVar4);
      FUN_00532500(uVar4);
      return 1;
    }
    _free(pvStack_18);
    return extraout_EAX;
  }
  cVar2 = FUN_004036a0(iVar5,s_adv_levelup_009b6c58);
  if (cVar2 != '\0') {
    uVar4 = FUN_00459160(local_1c,0);
    thunk_FUN_00796fb0(uVar4);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar2 = FUN_004036a0(iVar5,s_showobject_009b6c64);
  if (cVar2 != '\0') {
    uVar4 = FUN_00459160(local_1c,0);
    iVar5 = thunk_FUN_00796e60(uVar4);
    *(bool *)(in_ECX + 0xf) = iVar5 == 1;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar2 = FUN_004036a0(iVar5,s_changelogicmode_009b6c70);
  if (cVar2 != '\0') {
    uVar4 = FUN_00459160(local_1c,0);
    thunk_FUN_00796f50(uVar4);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar2 = FUN_004036a0(iVar5,s_previewclass_009b6c80);
  if (cVar2 != '\0') {
    uVar4 = FUN_00459160(local_1c,0);
    thunk_FUN_00796f50(uVar4);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar2 = FUN_004036a0(iVar5,s_siege_start_009b6c90);
  if (cVar2 == '\0') {
    cVar2 = FUN_004036a0(iVar5,s_siege_end_009b6c9c);
    if (cVar2 == '\0') {
      cVar2 = FUN_004036a0(iVar5,s_observer_mode_009b6ca8);
      if (cVar2 == '\0') {
        return 0;
      }
      iVar5 = FUN_004f45a0();
      if (iVar5 == 1) {
        iVar5 = *in_ECX;
        uVar4 = FUN_00459160(local_1c,0);
        uVar4 = thunk_FUN_00796fe0(uVar4);
        (**(code **)(iVar5 + 0x48))(uVar4);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    else {
      iVar5 = FUN_004f45a0();
      if (iVar5 == 1) {
        uVar4 = FUN_00459160(local_1c,0);
        thunk_FUN_00796fb0(uVar4);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  else {
    iVar5 = FUN_004f45a0();
    if (iVar5 == 1) {
      uVar4 = FUN_00459160(local_1c,0);
      thunk_FUN_00796fb0(uVar4);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  return 1;
}


// ==== FUN_005191b0 @ 0x005191b0 ====

void FUN_005191b0(void)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined4 *puVar4;
  uint local_10 [2];
  undefined4 *local_8;
  undefined4 local_4;
  
  pvVar2 = operator_new(4);
  if (pvVar2 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_005338e0();
  }
  local_8 = (undefined4 *)0x2;
  FUN_0051a920(local_10,&local_8);
  pvVar2 = operator_new(0x28);
  if (pvVar2 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_00533120(in_ECX);
  }
  local_8 = (undefined4 *)0x0;
  FUN_0051a920(local_10,&local_8);
  pvVar2 = operator_new(0x24);
  if (pvVar2 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_00532920(in_ECX);
  }
  local_8 = (undefined4 *)0x1;
  FUN_0051a920(local_10,&local_8);
  iVar3 = (**(code **)(*DAT_00b5a6e4 + 8))();
  local_10[0] = (uint)*(byte *)(iVar3 + 0x5b);
  FUN_004d8980(&local_8,local_10);
  puVar4 = local_8;
  if (local_8 == *(undefined4 **)(in_ECX + 0x10)) {
    puVar4 = (undefined4 *)**(undefined4 **)(in_ECX + 0x10);
  }
  piVar1 = (int *)puVar4[4];
  *(int **)(in_ECX + 8) = piVar1;
  (**(code **)(*piVar1 + 4))();
  return;
}


// ==== FUN_005192a0 @ 0x005192a0 ====

void FUN_005192a0(void)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_4;
  
  pvVar2 = operator_new(8);
  if (pvVar2 == (void *)0x0) {
    local_4 = 0;
  }
  else {
    local_4 = FUN_00533960();
  }
  iVar1 = *(int *)(in_ECX + 0x34);
  iVar3 = FUN_00519e00(iVar1,*(undefined4 *)(iVar1 + 4),&local_4);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar3;
  **(int **)(iVar3 + 4) = iVar3;
  return;
}


// ==== FUN_00519300 @ 0x00519300 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00519300(void)

{
  char cVar1;
  void *pvVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *in_ECX;
  float10 fVar6;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float fStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  FUN_005191b0();
  pvVar2 = operator_new(0xc);
  if (pvVar2 == (void *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_005339c0(in_ECX);
  }
  in_ECX[8] = iVar3;
  fVar6 = (float10)(**(code **)(*(int *)in_ECX[1] + 0x24))();
  fVar6 = (float10)FUN_0040d0f0((float)(fVar6 + (float10)_DAT_009b6dfc));
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a988 + 0xc))();
  uStack_14 = *puVar4;
  uStack_10 = puVar4[1];
  uStack_8 = puVar4[3];
  uStack_4 = puVar4[4];
  fStack_c = (float)fVar6;
  (**(code **)(*DAT_00b5a988 + 0x10))(&uStack_14);
  iVar3 = *DAT_00b5ad14;
  uVar5 = (**(code **)(*(int *)in_ECX[1] + 0x10))();
  (**(code **)(iVar3 + 4))(uVar5);
  iVar3 = *DAT_00b5ac5c;
  uVar5 = (**(code **)(*(int *)in_ECX[1] + 0x10))();
  (**(code **)(iVar3 + 0xc))(uVar5);
  FUN_00518830();
  cVar1 = (**(code **)(*(int *)in_ECX[1] + 0x28))();
  if (cVar1 != '\0') {
    FUN_00517b50(0);
  }
  uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  FUN_00532470(uVar5);
  FUN_00517db0();
  (**(code **)(*in_ECX + 0x30))();
  (**(code **)(*in_ECX + 0x34))();
  iVar3 = *DAT_00b5ad98;
  uVar5 = FUN_006ea910();
  (**(code **)(iVar3 + 4))(uVar5);
  (**(code **)(*DAT_00b5a834 + 8))();
  return;
}


// ==== FUN_00519430 @ 0x00519430 ====

undefined4 FUN_00519430(int *param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  
  if ((*(int **)(in_ECX + 8) != (int *)0x0) &&
     (cVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0xc))(param_1), cVar1 == '\x01')) {
    return 1;
  }
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 < 0x50030002) {
    if (uVar2 == 0x50030001) {
      FUN_00517f50(param_1);
      return 1;
    }
    if (uVar2 < 0x20010023) {
      if (uVar2 == 0x20010022) {
        uVar4 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x10))(param_1);
        return uVar4;
      }
      if (uVar2 == 0x40001) {
        FUN_005188c0(param_1);
      }
      else if (uVar2 == 0x70004) goto LAB_00519514;
    }
    else {
      if (uVar2 == 0x30060023) {
        cVar1 = FUN_00517e10(param_1);
        if (cVar1 == '\x01') {
          return 1;
        }
LAB_00519514:
        uVar4 = FUN_00518e40(param_1);
        return uVar4;
      }
      if (uVar2 == 0x50030000) {
        FUN_00518b30(param_1);
        return 1;
      }
    }
  }
  else {
    switch(uVar2 + 0xaffcfffe) {
    case 0:
      *(int *)(in_ECX + 0x2c) = param_1[1];
      return 1;
    case 1:
      FUN_00517580(param_1);
      return 1;
    case 2:
      FUN_00517930(param_1);
      return 1;
    case 3:
      FUN_00518d70(param_1);
      return 1;
    case 4:
      FUN_00517b50(param_1[1]);
      return 1;
    }
  }
  iVar3 = (**(code **)(*param_1 + 4))();
  if ((iVar3 == 0x10001) && (param_1[2] != 0)) {
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    *(undefined4 *)(in_ECX + 0x48) = uVar4;
  }
  iVar3 = (**(code **)(*param_1 + 4))();
  if ((iVar3 == 0x10003) || (iVar3 = (**(code **)(*param_1 + 4))(), iVar3 == 0x20001)) {
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    *(undefined4 *)(in_ECX + 0x48) = uVar4;
  }
  return 0;
}


// ==== FUN_005195b0 @ 0x005195b0 ====

void FUN_005195b0(void)

{
  int in_ECX;
  
  FUN_00534280();
  FUN_00533c50(*(undefined4 *)(in_ECX + 4));
  FUN_005192a0();
  return;
}


// ==== FUN_005195d0 @ 0x005195d0 ====

void FUN_005195d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  undefined4 *puStack_4;
  
  *in_ECX = &PTR_FUN_009b6e04;
  puStack_4 = in_ECX;
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b1874;
    puVar1[1] = 0xe;
  }
  FUN_00797a20(puVar1);
  FUN_00517cd0();
  in_ECX[2] = 0;
  if (in_ECX[5] != 0) {
    puStack_4 = (undefined4 *)((uint)puStack_4 & 0xffffff00);
    FUN_00409660(*(undefined4 *)in_ECX[4],(undefined4 *)in_ECX[4],puStack_4);
    FUN_0051a050(*(undefined4 *)(in_ECX[4] + 4));
    *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
    in_ECX[5] = 0;
    *(undefined4 *)in_ECX[4] = in_ECX[4];
    *(undefined4 *)(in_ECX[4] + 8) = in_ECX[4];
  }
  (**(code **)(*DAT_00b5ad14 + 8))();
  (**(code **)(*DAT_00b5ac5c + 0x10))();
  FUN_00518520();
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
  }
  in_ECX[8] = 0;
  FUN_00533c90();
  FUN_005342a0();
  if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[9])(1);
  }
  in_ECX[9] = 0;
  if ((undefined4 *)in_ECX[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[10])(1);
  }
  in_ECX[10] = 0;
  DAT_00b5a97c = 0;
  FUN_008984a0();
  FUN_0051a7a0(&puStack_4,*(undefined4 *)in_ECX[4],(undefined4 *)in_ECX[4]);
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_005196f0 @ 0x005196f0 ====

void FUN_005196f0(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int *piVar5;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *in_ECX = &PTR_FUN_009b6e04;
  *puVar1 = param_1;
  in_ECX[2] = 0;
  iVar2 = FUN_00519e80();
  in_ECX[4] = iVar2;
  *(undefined1 *)(iVar2 + 0x15) = 1;
  *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
  *(undefined4 *)in_ECX[4] = in_ECX[4];
  *(undefined4 *)(in_ECX[4] + 8) = in_ECX[4];
  in_ECX[5] = 0;
  in_ECX[8] = 0;
  uVar3 = FUN_00519ca0();
  in_ECX[0xd] = uVar3;
  in_ECX[0xe] = 0;
  *(undefined1 *)(in_ECX + 0xf) = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x12] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a97c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a97c = in_ECX;
  }
  FUN_00517ff0();
  in_ECX[0xb] = 9;
  pvVar4 = operator_new(0x14);
  if (pvVar4 == (void *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_00535990();
  }
  in_ECX[9] = piVar5;
  (**(code **)(*piVar5 + 4))();
  (**(code **)(*(int *)in_ECX[9] + 0xc))();
  pvVar4 = operator_new(0x44);
  if (pvVar4 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (**(code **)(*(int *)*puVar1 + 0x1c))();
    uVar3 = FUN_00534d70(uVar3);
  }
  in_ECX[10] = uVar3;
  (**(code **)(*DAT_00b5af10 + 0x14))();
  FUN_00534280();
  FUN_00533c50(*puVar1);
  FUN_005192a0();
  FUN_00519300();
  (**(code **)(*DAT_00b5ac2c + 4))(0);
  return;
}


// ==== FUN_00519800 @ 0x00519800 ====

void FUN_00519800(void)

{
  code *pcVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  int *piVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  int *in_ECX;
  bool bVar10;
  float10 fVar11;
  float fStack_88;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  undefined4 uStack_64;
  undefined1 auStack_5c [8];
  undefined1 auStack_54 [12];
  int *piStack_48;
  int iStack_44;
  float fStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  char cStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_26;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  int *piStack_10;
  uint uStack_c;
  
  iVar4 = (**(code **)(*in_ECX + 0x24))();
  if (iVar4 == 0) {
    return;
  }
  (**(code **)(*in_ECX + 0x24))();
  FUN_005082d0();
  iVar4 = FUN_00508280();
  piStack_48 = (int *)FUN_00519f20();
  *(undefined1 *)((int)piStack_48 + 0x19) = 1;
  piStack_48[1] = (int)piStack_48;
  *piStack_48 = (int)piStack_48;
  piStack_48[2] = (int)piStack_48;
  iStack_44 = 0;
  piVar5 = (int *)(**(code **)(*in_ECX + 8))();
  pfVar6 = (float *)(**(code **)(*piVar5 + 0x28))();
  fStack_74 = *pfVar6;
  fStack_70 = pfVar6[1];
  piVar5 = (int *)(**(code **)(*DAT_00b5ad5c + 0x18))();
  do {
    if (piVar5 == (int *)0x0) {
LAB_00519ace:
      if (iStack_44 != 0) {
        iVar7 = *piStack_48;
        piVar5 = (int *)(**(code **)(*in_ECX + 8))();
        piVar5 = (int *)(**(code **)(*piVar5 + 0x14))();
        uStack_34 = (**(code **)(*piVar5 + 8))();
        uStack_30 = *(undefined4 *)(iVar7 + 0x14);
        uStack_26 = *(undefined1 *)(iVar4 + 0x19);
        cStack_2c = *(undefined1 *)(iVar4 + 0x1b);
        uStack_2b = *(undefined1 *)(iVar4 + 0x1c);
        uStack_2a = *(undefined1 *)(iVar4 + 0x1d);
        uStack_29 = *(undefined1 *)(iVar4 + 0x1e);
        cVar2 = (**(code **)(*(int *)in_ECX[1] + 0x20))(1);
        if (cVar2 == '\0') {
          cVar2 = (**(code **)(*(int *)in_ECX[1] + 0x20))(0);
        }
        uStack_2b = *(undefined1 *)(iVar7 + 0x10);
        cStack_2c = cVar2;
        uVar9 = (**(code **)(*(int *)in_ECX[1] + 0x10))(&uStack_38);
        FUN_00532580(*(undefined4 *)(iVar4 + 8),uVar9);
        (**(code **)(*in_ECX + 0x24))();
        FUN_005082d0();
      }
      FUN_0051a860(&fStack_78,*piStack_48,piStack_48);
      _free(piStack_48);
      return;
    }
    piStack_10 = (int *)(**(code **)(*piVar5 + 4))();
    if (piStack_10 == (int *)0x0) {
      uStack_c = 0xf;
      pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
      FUN_00401740(s_pTActor____NULL_009b6d08,0xf);
      FUN_00406880(auStack_24);
      if (uStack_c < 0x10) {
        uStack_c = 0xf;
        piStack_10 = (int *)0x0;
        pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_20);
      return;
    }
    iVar7 = (**(code **)(*piStack_10 + 0xc))();
    iVar8 = (**(code **)(*in_ECX + 0x24))();
    if (iVar8 != 0) {
      cVar2 = FUN_005082a0();
      if ((cVar2 == '\x01') || (cVar2 = FUN_005082b0(), cVar2 == '\x01')) {
        if (iVar7 != 0) {
          bVar10 = iVar7 == 2;
          goto LAB_00519955;
        }
      }
      else if ((iVar7 != 1) && (iVar7 != 3)) {
        bVar10 = iVar7 == 5;
LAB_00519955:
        if ((!bVar10) && (iVar7 != 6)) goto LAB_00519a86;
      }
      cVar2 = (**(code **)(*piVar5 + 0x34))();
      if ((cVar2 != '\0') && (cVar2 = (**(code **)(*piVar5 + 0x2c))(), cVar2 != '\0')) {
        FUN_004f56d0(*(undefined1 *)(iVar4 + 0x1f));
        pfVar6 = (float *)(**(code **)(*piVar5 + 0x10))(auStack_5c);
        fStack_6c = pfVar6[1] - fStack_74;
        fStack_70 = *pfVar6 - fStack_78;
        fVar11 = (float10)FUN_0040d5f0(&fStack_70);
        FUN_0040d0f0((float)((float10)DAT_00aec34c * (float10)DAT_0099d0b4 +
                            (fVar11 - (float10)fStack_88)));
        cVar2 = (**(code **)(*piVar5 + 0xc))
                          (fStack_78,fStack_74,fStack_88,*(undefined4 *)(iVar4 + 0x20));
        if (cVar2 != '\0') {
          uVar3 = FUN_004ef070(iVar8);
          uStack_64 = CONCAT31(uStack_64._1_3_,uVar3);
          uVar9 = (**(code **)(*piVar5 + 0x18))();
          iVar7 = (**(code **)(*piVar5 + 0x18))();
          if (iVar7 == *(int *)(iVar4 + 0xc)) {
            FUN_0051a090();
            fStack_40 = 0.0;
            uStack_3c = uStack_64;
            uStack_38 = uVar9;
            FUN_0051a730(auStack_54,&fStack_40);
            goto LAB_00519ace;
          }
          fStack_40 = fStack_78 - DAT_00aec34c * DAT_0099d0b4;
          if (fStack_40 <= 0.0) {
            fStack_40 = 0.0 - fStack_40;
          }
          uStack_3c = uStack_64;
          uStack_38 = uVar9;
          FUN_0051a730(auStack_54,&fStack_40);
        }
      }
    }
LAB_00519a86:
    piVar5 = (int *)(**(code **)(*DAT_00b5ad5c + 0x1c))();
  } while( true );
}


// ==== FUN_00519ba0 @ 0x00519ba0 ====

void FUN_00519ba0(void)

{
  char cVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x24))();
  cVar1 = FUN_00508290();
  if (cVar1 == '\0') {
    FUN_005175a0();
    return;
  }
  FUN_00519800();
  return;
}


// ==== FUN_00519bc0 @ 0x00519bc0 ====

void FUN_00519bc0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x24))();
  if (iVar2 != 0) {
    (**(code **)(*in_ECX + 0x24))();
    cVar1 = FUN_005082c0();
    if (cVar1 == '\0') {
      (**(code **)(*in_ECX + 0x24))(param_1);
      cVar1 = FUN_00508390(param_1);
      if (cVar1 != '\0') {
        (**(code **)(*in_ECX + 0x24))();
        cVar1 = FUN_00508290();
        if (cVar1 != '\0') {
          FUN_00519800();
          return;
        }
        FUN_005175a0();
      }
    }
  }
  return;
}


// ==== FUN_00519c20 @ 0x00519c20 ====

undefined4 FUN_00519c20(float *param_1,float *param_2)

{
  if (*param_1 <= *param_2 && *param_2 != *param_1) {
    return 1;
  }
  return 0;
}


// ==== FUN_00519c40 @ 0x00519c40 ====

void FUN_00519c40(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x15) == '\0') {
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


// ==== FUN_00519ca0 @ 0x00519ca0 ====

void FUN_00519ca0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009817a0;
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


// ==== Catch@00519d0f @ 0x00519d0f ====

void Catch_00519d0f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00519d30 @ 0x00519d30 ====

void FUN_00519d30(void *param_1)

{
  if (*(char *)((int)param_1 + 0x19) == '\0') {
    FUN_00519d30(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00519d70 @ 0x00519d70 ====

void * FUN_00519d70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009817b0;
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


// ==== Catch@00519de5 @ 0x00519de5 ====

void Catch_00519de5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00519e00 @ 0x00519e00 ====

void FUN_00519e00(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009817c0;
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


// ==== Catch@00519e69 @ 0x00519e69 ====

void Catch_00519e69(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00519e80 @ 0x00519e80 ====

void FUN_00519e80(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009817d0;
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


// ==== Catch@00519f0a @ 0x00519f0a ====

void Catch_00519f0a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00519f20 @ 0x00519f20 ====

void FUN_00519f20(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009817e0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x1c);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 6) = 1;
  *(undefined1 *)((int)puVar1 + 0x19) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@00519faa @ 0x00519faa ====

void Catch_00519faa(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00519fc0 @ 0x00519fc0 ====

void * FUN_00519fc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009817f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x1c);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_00894570(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0051a035 @ 0x0051a035 ====

void Catch_0051a035(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0051a050 @ 0x0051a050 ====

void FUN_0051a050(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0051a050(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0051a090 @ 0x0051a090 ====

void FUN_0051a090(void)

{
  int in_ECX;
  
  FUN_00519d30(*(undefined4 *)(*(int *)(in_ECX + 4) + 4));
  *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
  *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_0051a0c0 @ 0x0051a0c0 ====

void FUN_0051a0c0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x15555553 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00519fc0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x18);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x18) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[6] == '\0') {
LAB_0051a1c5:
        *(undefined1 *)(*piVar5 + 0x18) = 1;
        *(undefined1 *)(piVar6 + 6) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x18) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0058b7a0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x18) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x18) = 0;
        FUN_004b8340(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[6] == '\0') goto LAB_0051a1c5;
      if (piVar7 == (int *)*piVar2) {
        FUN_004b8340(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x18) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x18) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x19) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x18);
  } while( true );
}


// ==== FUN_0051a2a0 @ 0x0051a2a0 ====

/* WARNING: Removing unreachable block (ram,0x0051a3bc) */
/* WARNING: Removing unreachable block (ram,0x0051a3cc) */
/* WARNING: Removing unreachable block (ram,0x0051a3d5) */
/* WARNING: Removing unreachable block (ram,0x0051a3d8) */
/* WARNING: Removing unreachable block (ram,0x0051a3c8) */
/* WARNING: Removing unreachable block (ram,0x0051a3e6) */
/* WARNING: Removing unreachable block (ram,0x0051a3f3) */
/* WARNING: Removing unreachable block (ram,0x0051a3fe) */
/* WARNING: Removing unreachable block (ram,0x0051a3fa) */
/* WARNING: Removing unreachable block (ram,0x0051a3ee) */
/* WARNING: Removing unreachable block (ram,0x0051a401) */

void FUN_0051a2a0(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x15) != '\0') {
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
            goto LAB_0051a4d0;
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
LAB_0051a4d0:
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


// ==== FUN_0051a550 @ 0x0051a550 ====

void FUN_0051a550(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00519d70(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_0051a655:
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
      if ((char)piVar6[5] == '\0') goto LAB_0051a655;
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


// ==== FUN_0051a730 @ 0x0051a730 ====

void FUN_0051a730(undefined4 *param_1,float *param_2)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int in_ECX;
  
  puVar7 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  bVar4 = true;
  cVar2 = *(char *)((int)puVar7 + 0x19);
  puVar5 = *(undefined4 **)(in_ECX + 4);
  while (cVar2 == '\0') {
    fVar1 = (float)puVar7[3];
    if (fVar1 < *param_2 || fVar1 == *param_2) {
      puVar6 = (undefined4 *)puVar7[2];
    }
    else {
      puVar6 = (undefined4 *)*puVar7;
    }
    bVar4 = fVar1 >= *param_2 && fVar1 != *param_2;
    puVar5 = puVar7;
    puVar7 = puVar6;
    cVar2 = *(char *)((int)puVar6 + 0x19);
  }
  puVar7 = (undefined4 *)FUN_0051a0c0(&param_2,bVar4,puVar5,param_2);
  uVar3 = *puVar7;
  *(undefined1 *)(param_1 + 1) = 1;
  *param_1 = uVar3;
  return;
}


// ==== FUN_0051a7a0 @ 0x0051a7a0 ====

void FUN_0051a7a0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0051a050(piVar6[1]);
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


// ==== FUN_0051a860 @ 0x0051a860 ====

void FUN_0051a860(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00519d30(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x19) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x19) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x19);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x19);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x19);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x19);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00850bf0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0051a920 @ 0x0051a920 ====

void FUN_0051a920(undefined4 *param_1,int *param_2)

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
      puVar5 = (undefined4 *)FUN_0051a550(&param_2,1,puVar5,piVar3);
      uVar1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *piVar3) {
    puVar5 = (undefined4 *)FUN_0051a550(&param_2,bVar2,puVar5,piVar3);
    *param_1 = *puVar5;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0051a9e0 @ 0x0051a9e0 ====

undefined1 FUN_0051a9e0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x44);
}


// ==== FUN_0051a9f0 @ 0x0051a9f0 ====

bool FUN_0051a9f0(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return iVar1 == param_1;
}


// ==== FUN_0051aa10 @ 0x0051aa10 ====

void FUN_0051aa10(byte param_1)

{
  void *in_ECX;
  
  FUN_005195d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0051aa30 @ 0x0051aa30 ====

void FUN_0051aa30(void)

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
  if (*(void **)(in_ECX + 8) != (void *)0x0) {
    _free(*(void **)(in_ECX + 8));
    return;
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  if (DAT_00b5af34 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af34)(1);
  }
  if (DAT_00b5af30 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af30)(1);
  }
  return;
}


// ==== FUN_0051aaa0 @ 0x0051aaa0 ====

void FUN_0051aaa0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6edc;
  FUN_0051aa30();
  if ((void *)in_ECX[2] == (void *)0x0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0051aae0 @ 0x0051aae0 ====

undefined4 FUN_0051aae0(undefined4 param_1)

{
  int *piVar1;
  code *pcVar2;
  char cVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  int in_ECX;
  int *piVar5;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  piVar5 = *(int **)(in_ECX + 8);
  piVar1 = *(int **)(in_ECX + 0xc);
  while( true ) {
    if (piVar5 == piVar1) {
      return 0;
    }
    if ((int *)*piVar5 == (int *)0x0) break;
    cVar3 = (**(code **)(*(int *)*piVar5 + 4))(param_1);
    if (cVar3 != '\0') {
      return 1;
    }
    piVar5 = piVar5 + 1;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pReceiver____NULL_009b6e5c,0x11);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    pcVar2 = (code *)swi(3);
    uVar4 = (*pcVar2)();
    return uVar4;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0051ab90 @ 0x0051ab90 ====

void FUN_0051ab90(int param_1)

{
  int iVar1;
  int *piVar2;
  code *pcVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  int local_8;
  uint local_4;
  
  if (param_1 == 0) {
    local_4 = 0xf;
    local_8 = param_1;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_i_pReceiver____NULL_009b6e70,0x13);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    _free(local_18);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0x10) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2)))
  {
    FUN_0051ade0(*(undefined4 *)(in_ECX + 0xc),1,&param_1);
    return;
  }
  piVar2 = *(int **)(in_ECX + 0xc);
  *piVar2 = param_1;
  *(int **)(in_ECX + 0xc) = piVar2 + 1;
  return;
}


// ==== FUN_0051ac40 @ 0x0051ac40 ====

void FUN_0051ac40(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (DAT_00b5af34 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_0053a830();
    }
  }
  if (DAT_00b5af30 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_0053b030();
    }
  }
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0053b7c0();
  }
  FUN_0051ab90(uVar2);
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b6e94;
  }
  FUN_0051ab90(puVar3);
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b6eb8;
  }
  FUN_0051ab90(puVar3);
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b6eac;
  }
  FUN_0051ab90(puVar3);
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b6ea0;
  }
  FUN_0051ab90(puVar3);
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b6ec4;
  }
  FUN_0051ab90(puVar3);
  puVar3 = operator_new(4);
  if (puVar3 == (undefined4 *)0x0) {
    FUN_0051ab90(0);
    return;
  }
  *puVar3 = &PTR_FUN_009b6ed0;
  FUN_0051ab90(puVar3);
  return;
}


// ==== FUN_0051ad70 @ 0x0051ad70 ====

void FUN_0051ad70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6edc;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  FUN_0051ac40();
  return;
}


// ==== FUN_0051ad90 @ 0x0051ad90 ====

void FUN_0051ad90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6edc;
  FUN_0051aa30();
  if ((void *)in_ECX[2] != (void *)0x0) {
    _free((void *)in_ECX[2]);
    return;
  }
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0051ade0 @ 0x0051ade0 ====

void FUN_0051ade0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981800;
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


// ==== Catch@0051af41 @ 0x0051af41 ====

void Catch_0051af41(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0051b030 @ 0x0051b030 ====

undefined4 FUN_0051b030(void)

{
  return 0x50040008;
}


// ==== FUN_0051b040 @ 0x0051b040 ====

undefined4 FUN_0051b040(void)

{
  return 0x50070003;
}


// ==== FUN_0051b050 @ 0x0051b050 ====

undefined4 FUN_0051b050(void)

{
  return 0x50030003;
}


// ==== FUN_0051b060 @ 0x0051b060 ====

undefined4 FUN_0051b060(void)

{
  return 0x70140006;
}


// ==== FUN_0051b110 @ 0x0051b110 ====

void FUN_0051b110(void)

{
  undefined4 *in_ECX;
  void *unaff_ESI;
  undefined1 local_1c [4];
  undefined1 local_18;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b6f64;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_setposition_009b6ee4,0xb);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_1c,2);
  if (uStack_c < 0x10) {
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_0051b170 @ 0x0051b170 ====

void FUN_0051b170(void)

{
  undefined4 *in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  *in_ECX = &PTR_FUN_009b6f64;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(s_setposition_009b6ef0,0xb);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_1c);
  if (local_8 < 0x10) {
    return;
  }
  _free(local_1c);
  return;
}


// ==== FUN_0051b1d0 @ 0x0051b1d0 ====

uint FUN_0051b1d0(void)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint uVar5;
  float10 fVar6;
  float10 fVar7;
  float afStack_58 [2];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  uint3 uStack_48;
  undefined1 uStack_45;
  float fStack_44;
  float fStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  uVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b6f0c;
  }
  puVar3[1] = uVar2;
  FUN_00797a20(puVar3);
  uVar4 = FUN_00459160(auStack_1c,0);
  fVar6 = (float10)thunk_FUN_00796ec0(uVar4);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return extraout_EAX;
  }
  uVar4 = FUN_00459160(auStack_1c,1);
  fVar7 = (float10)thunk_FUN_00796ec0(uVar4);
  afStack_58[0] = (float)fVar7;
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return extraout_EAX_00;
  }
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  FUN_00797a50(&uStack_50,0,0xc);
  fStack_40 = afStack_58[0];
  uStack_48 = uStack_48 & 0xffff;
  _uStack_48 = CONCAT13(1,uStack_48);
  uStack_3c = 0;
  uStack_50 = uVar4;
  fStack_44 = (float)fVar6;
  puVar3 = (undefined4 *)FUN_004ef0e0(afStack_58);
  uStack_4c = *puVar3;
  _uStack_48 = CONCAT22(stack0xffffffba,*(undefined2 *)(puVar3 + 1));
  uStack_30 = _uStack_48;
  uStack_38 = uVar4;
  uStack_34 = uStack_4c;
  cVar1 = (**(code **)(*DAT_00b5acc0 + 0x2c))();
  if (cVar1 != '\0') {
    afStack_58[0] = (float)CONCAT31(afStack_58[0]._1_3_,3);
    puVar3 = operator_new(0xc);
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = &PTR_FUN_009b6f50;
    }
    puVar3[1] = afStack_58[0];
    puVar3[2] = uVar4;
    FUN_00797a20(puVar3);
  }
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b6f3c;
  }
  uVar4 = FUN_004f4d60();
  FUN_00403e60(puVar3 + 1,&uStack_38,uVar4);
  FUN_00797a20(puVar3);
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009b6f24;
  }
  puVar3[1] = uVar2;
  FUN_00403e60(puVar3 + 2,&uStack_50,0x19);
  uVar5 = FUN_00797a20(puVar3);
  return uVar5 & 0xffffff00;
}


// ==== FUN_0051b3a0 @ 0x0051b3a0 ====

uint FUN_0051b3a0(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_setposition_009b6efc,0xb);
  if (uVar1 == 0) {
    uVar1 = FUN_0051b1d0(param_1);
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0051b3e0 @ 0x0051b3e0 ====

void FUN_0051b3e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0051b170();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0051b410 @ 0x0051b410 ====

void FUN_0051b410(uint *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  undefined1 local_4 [4];
  
  iVar1 = *(int *)(in_ECX + 0xc);
  while ((iVar1 != 0 && (iVar1 = **(int **)(in_ECX + 8), *(uint *)(iVar1 + 0xc) <= *param_1))) {
    iVar5 = *(int *)(iVar1 + 0x20);
    while (iVar5 != 0) {
      uVar2 = *(uint *)(iVar1 + 0x1c);
      uVar4 = uVar2 >> 2;
      iVar5 = uVar4 * -4;
      if (*(uint *)(iVar1 + 0x18) <= uVar4) {
        uVar4 = uVar4 - *(uint *)(iVar1 + 0x18);
      }
      uVar3 = *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x14) + uVar4 * 4) + (uVar2 + iVar5) * 4);
      if (*(int *)(iVar1 + 0x20) != 0) {
        *(uint *)(iVar1 + 0x1c) = uVar2 + 1;
        if ((uint)(*(int *)(iVar1 + 0x18) * 4) <= uVar2 + 1) {
          *(undefined4 *)(iVar1 + 0x1c) = 0;
        }
        iVar5 = *(int *)(iVar1 + 0x20) + -1;
        *(int *)(iVar1 + 0x20) = iVar5;
        if (iVar5 == 0) {
          *(undefined4 *)(iVar1 + 0x1c) = 0;
        }
      }
      FUN_00797a20(uVar3);
      iVar5 = *(int *)(iVar1 + 0x20);
    }
    FUN_0051b9b0(local_4,iVar1);
    iVar1 = *(int *)(in_ECX + 0xc);
  }
  return;
}


// ==== FUN_0051b4c0 @ 0x0051b4c0 ====

void FUN_0051b4c0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  int in_ECX;
  
  puVar2 = *(undefined4 **)(in_ECX + 8);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    iVar8 = puVar3[8];
    while (iVar8 != 0) {
      uVar4 = puVar3[7];
      uVar7 = uVar4 >> 2;
      iVar8 = uVar7 * -4;
      if ((uint)puVar3[6] <= uVar7) {
        uVar7 = uVar7 - puVar3[6];
      }
      puVar5 = *(undefined4 **)(*(int *)(puVar3[5] + uVar7 * 4) + (uVar4 + iVar8) * 4);
      if (puVar3[8] != 0) {
        puVar3[7] = uVar4 + 1;
        if ((uint)(puVar3[6] * 4) <= uVar4 + 1) {
          puVar3[7] = 0;
        }
        iVar8 = puVar3[8] + -1;
        puVar3[8] = iVar8;
        if (iVar8 == 0) {
          puVar3[7] = 0;
        }
      }
      if (puVar5 != (undefined4 *)0x0) {
        (**(code **)*puVar5)(1);
      }
      iVar8 = puVar3[8];
    }
    if (*(char *)((int)puVar3 + 0x25) == '\0') {
      puVar5 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar5 + 0x25) == '\0') {
        cVar1 = *(char *)((int)*puVar5 + 0x25);
        puVar3 = puVar5;
        puVar5 = (undefined4 *)*puVar5;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x25);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x25);
        puVar6 = (undefined4 *)puVar3[1];
        puVar5 = puVar3;
        while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x25);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
        }
      }
    }
  }
  FUN_0051bc70(*(undefined4 *)(*(int *)(in_ECX + 8) + 4));
  *(int *)(*(int *)(in_ECX + 8) + 4) = *(int *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 8);
  *(int *)(*(int *)(in_ECX + 8) + 8) = *(int *)(in_ECX + 8);
  return;
}


// ==== FUN_0051b610 @ 0x0051b610 ====

void FUN_0051b610(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6f6c;
  iVar1 = FUN_0051b890();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x25) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5af1c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5af1c = in_ECX;
  return;
}


// ==== FUN_0051b660 @ 0x0051b660 ====

void FUN_0051b660(uint param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if (param_1 < uVar1) {
    FUN_00797a20(param_2);
    return;
  }
  FUN_0051c900(&param_1);
  FUN_00460680(&param_2);
  return;
}


// ==== FUN_0051b6b0 @ 0x0051b6b0 ====

void FUN_0051b6b0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x25) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x25) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x25);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x25);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x25);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x25);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_0051b700 @ 0x0051b700 ====

int FUN_0051b700(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  
  uVar3 = (uint)(in_ECX[1] + param_1) >> 2;
  iVar2 = uVar3 * -4;
  uVar1 = *(uint *)(*in_ECX + 8);
  if (uVar1 <= uVar3) {
    uVar3 = uVar3 - uVar1;
  }
  return *(int *)(*(int *)(*in_ECX + 4) + uVar3 * 4) + (in_ECX[1] + param_1 + iVar2) * 4;
}


// ==== FUN_0051b730 @ 0x0051b730 ====

undefined4 FUN_0051b730(int *param_1)

{
  int *in_ECX;
  
  if ((*in_ECX == *param_1) && (in_ECX[1] == param_1[1])) {
    return 0;
  }
  return 1;
}


// ==== FUN_0051b770 @ 0x0051b770 ====

void FUN_0051b770(int *param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,
                 uint param_7)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  for (; (param_2 != param_4 || (param_3 != param_5)); param_3 = param_3 + 1) {
    uVar3 = param_3 >> 2;
    iVar1 = uVar3 * -4;
    if (*(uint *)(param_2 + 8) <= uVar3) {
      uVar3 = uVar3 - *(uint *)(param_2 + 8);
    }
    uVar2 = param_7 >> 2;
    iVar4 = param_7 + uVar2 * -4;
    if (*(uint *)(param_6 + 8) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(param_6 + 8);
    }
    param_7 = param_7 + 1;
    *(undefined4 *)(*(int *)(*(int *)(param_6 + 4) + uVar2 * 4) + iVar4 * 4) =
         *(undefined4 *)(*(int *)(*(int *)(param_2 + 4) + uVar3 * 4) + (param_3 + iVar1) * 4);
  }
  param_1[1] = param_7;
  *param_1 = param_6;
  return;
}


// ==== FUN_0051b800 @ 0x0051b800 ====

void FUN_0051b800(int *param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6,
                 uint param_7)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  while ((param_2 != param_4 || (param_3 != param_5))) {
    param_5 = param_5 - 1;
    uVar3 = param_5 >> 2;
    iVar1 = uVar3 * -4;
    if (*(uint *)(param_4 + 8) <= uVar3) {
      uVar3 = uVar3 - *(uint *)(param_4 + 8);
    }
    param_7 = param_7 - 1;
    uVar4 = param_7 >> 2;
    iVar2 = uVar4 * -4;
    if (*(uint *)(param_6 + 8) <= uVar4) {
      uVar4 = uVar4 - *(uint *)(param_6 + 8);
    }
    *(undefined4 *)(*(int *)(*(int *)(param_6 + 4) + uVar4 * 4) + (param_7 + iVar2) * 4) =
         *(undefined4 *)(*(int *)(*(int *)(param_4 + 4) + uVar3 * 4) + (param_5 + iVar1) * 4);
  }
  *param_1 = param_6;
  param_1[1] = param_7;
  return;
}


// ==== FUN_0051b890 @ 0x0051b890 ====

void FUN_0051b890(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981810;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x28);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 9) = 1;
  *(undefined1 *)((int)puVar1 + 0x25) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@0051b91a @ 0x0051b91a ====

void Catch_0051b91a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0051b930 @ 0x0051b930 ====

undefined4
FUN_0051b930(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  FUN_0051b770(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_1);
  return param_1;
}


// ==== FUN_0051b970 @ 0x0051b970 ====

undefined4
FUN_0051b970(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  FUN_0051b800(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_1);
  return param_1;
}


// ==== FUN_0051b9b0 @ 0x0051b9b0 ====

/* WARNING: Removing unreachable block (ram,0x0051bacc) */
/* WARNING: Removing unreachable block (ram,0x0051badc) */
/* WARNING: Removing unreachable block (ram,0x0051bae5) */
/* WARNING: Removing unreachable block (ram,0x0051bae8) */
/* WARNING: Removing unreachable block (ram,0x0051bad8) */
/* WARNING: Removing unreachable block (ram,0x0051baf6) */
/* WARNING: Removing unreachable block (ram,0x0051bb03) */
/* WARNING: Removing unreachable block (ram,0x0051bb0e) */
/* WARNING: Removing unreachable block (ram,0x0051bb0a) */
/* WARNING: Removing unreachable block (ram,0x0051bafe) */
/* WARNING: Removing unreachable block (ram,0x0051bb11) */

void FUN_0051b9b0(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x25) != '\0') {
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
  FUN_0051b6b0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x25) == '\0') {
    if (*(char *)(param_2[2] + 0x25) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x25) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x25) == '\0') {
      piVar3 = (int *)FUN_00412870(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x25) == '\0') {
      uVar4 = FUN_004ae4e0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[9] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[9] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[9] == '\0') {
            *(undefined1 *)(piVar5 + 9) = 1;
            *(undefined1 *)(piVar3 + 9) = 0;
            FUN_0058b7f0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x25) == '\0') {
            if ((*(char *)(*piVar5 + 0x24) == '\x01') && (*(char *)(piVar5[2] + 0x24) == '\x01'))
            goto LAB_0051bbe0;
            if (*(char *)(piVar5[2] + 0x24) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x24) = 1;
              *(undefined1 *)(piVar5 + 9) = 0;
              FUN_00412890(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 9) = (char)piVar3[9];
            *(undefined1 *)(piVar3 + 9) = 1;
            *(undefined1 *)(piVar5[2] + 0x24) = 1;
            FUN_0058b7f0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[9] == '\0') {
            *(undefined1 *)(piVar5 + 9) = 1;
            *(undefined1 *)(piVar3 + 9) = 0;
            FUN_00412890(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x25) == '\0') {
            if ((*(char *)(piVar5[2] + 0x24) != '\x01') || (*(char *)(*piVar5 + 0x24) != '\x01')) {
              if (*(char *)(*piVar5 + 0x24) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x24) = 1;
                *(undefined1 *)(piVar5 + 9) = 0;
                FUN_0058b7f0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 9) = (char)piVar3[9];
              *(undefined1 *)(piVar3 + 9) = 1;
              *(undefined1 *)(*piVar5 + 0x24) = 1;
              FUN_00412890(piVar3);
              break;
            }
LAB_0051bbe0:
            *(undefined1 *)(piVar5 + 9) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 9) = 1;
  }
  FUN_0046cfc0();
  _free(param_2);
  return;
}


// ==== FUN_0051bc70 @ 0x0051bc70 ====

void FUN_0051bc70(void *param_1)

{
  if (*(char *)((int)param_1 + 0x25) == '\0') {
    FUN_0051bc70(*(undefined4 *)((int)param_1 + 8));
    FUN_0046cfc0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0051bcb0 @ 0x0051bcb0 ====

void FUN_0051bcb0(undefined4 *param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if (((*(byte *)(in_ECX + 0xc) & 3) == 0) &&
     (*(uint *)(in_ECX + 8) <= *(int *)(in_ECX + 0x10) + 4U >> 2)) {
    FUN_00460510(1);
  }
  iVar3 = *(int *)(in_ECX + 0xc);
  if (iVar3 == 0) {
    iVar3 = *(int *)(in_ECX + 8) * 4;
  }
  uVar4 = iVar3 - 1;
  uVar5 = uVar4 >> 2;
  if (*(int *)(*(int *)(in_ECX + 4) + uVar5 * 4) == 0) {
    pvVar2 = operator_new(0x10);
    *(void **)(*(int *)(in_ECX + 4) + uVar5 * 4) = pvVar2;
  }
  puVar1 = (undefined4 *)(*(int *)(*(int *)(in_ECX + 4) + uVar5 * 4) + (uVar4 & 3) * 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
  }
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
  *(uint *)(in_ECX + 0xc) = uVar4;
  return;
}


// ==== FUN_0051bd30 @ 0x0051bd30 ====

void FUN_0051bd30(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0051bc70(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x25) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x25) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x25);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x25);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x25);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x25);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0051b9b0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0051bdf0 @ 0x0051bdf0 ====

void FUN_0051bdf0(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5,
                 int param_6)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  undefined1 auStack_1d4 [4];
  undefined1 local_1c0 [8];
  undefined1 local_1b8 [8];
  undefined1 local_1b0 [8];
  undefined4 local_1a8;
  undefined1 local_1a0 [8];
  undefined4 local_198;
  undefined1 local_190 [8];
  undefined1 local_188 [8];
  undefined4 local_180;
  undefined4 local_178;
  int local_174;
  int local_16c;
  int local_168;
  int local_160;
  int local_15c;
  int local_158;
  int local_154;
  uint local_150;
  int local_148;
  int local_140;
  int local_138;
  int local_130;
  int local_128;
  int local_124;
  int local_11c;
  uint local_118;
  int local_110;
  int local_10c;
  int local_104;
  uint local_100;
  int local_f8;
  uint local_f4;
  int local_ec;
  int local_e8;
  int local_e0;
  int local_dc;
  int local_d4;
  int local_cc;
  int local_c4;
  int local_bc;
  undefined4 local_b4;
  int local_ac;
  int local_a4;
  int local_9c;
  int local_94;
  int local_8c;
  int local_84;
  int local_7c;
  int local_74;
  int local_6c;
  int local_64;
  int local_5c;
  undefined4 local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981820;
  local_10 = ExceptionList;
  local_14 = auStack_1d4 + 8;
  local_180 = param_1;
  local_1c = param_2 - *(int *)(in_ECX + 0xc);
  uVar3 = local_1c;
  local_50 = *(int *)(in_ECX + 0x10);
  local_20 = local_50 - local_1c;
  local_1a8 = param_5;
  local_198 = param_3;
  uVar4 = param_6 - param_4;
  if (local_1c < local_20) {
    local_8 = 0;
    if (local_1c < uVar4) {
      local_44 = param_3;
      local_15c = uVar4 - local_1c;
      local_48 = param_4 + local_15c;
      local_4c = param_3;
      ExceptionList = &local_10;
      local_40 = local_48;
      while (cVar1 = FUN_0051b730(&local_4c), cVar1 != '\0') {
        local_48 = local_48 + -1;
        uVar2 = FUN_006ea150();
        FUN_0051bcb0(uVar2);
      }
      for (; local_174 = *(int *)(in_ECX + 0xc), local_18 = uVar3, uVar3 != 0; uVar3 = uVar3 - 1) {
        local_10c = local_174;
        local_ac = local_174;
        uVar2 = FUN_0051b700(uVar4 - 1);
        FUN_0051bcb0(uVar2);
      }
      local_130 = local_174 + uVar4;
      local_118 = uVar4;
      local_cc = local_174;
      local_9c = local_130;
      FUN_0051b930(local_1b8,local_44,local_40,param_5,param_6);
    }
    else {
      ExceptionList = &local_10;
      local_14 = auStack_1d4 + 8;
      for (uVar3 = uVar4; local_160 = *(int *)(in_ECX + 0xc), local_18 = uVar3, uVar3 != 0;
          uVar3 = uVar3 - 1) {
        local_154 = local_160;
        local_74 = local_160;
        uVar2 = FUN_0051b700(uVar4 - 1);
        FUN_0051bcb0(uVar2);
      }
      local_140 = local_160 + uVar4;
      local_16c = local_140 + local_1c;
      local_d4 = local_140 + uVar4;
      local_150 = uVar4;
      local_f4 = uVar4;
      local_dc = local_160;
      local_bc = local_140;
      local_64 = local_d4;
      local_5c = local_16c;
      FUN_0051b930(local_188);
      local_124 = *(int *)(in_ECX + 0xc);
      local_ec = local_124 + local_1c;
      local_e0 = local_124;
      local_84 = local_ec;
      FUN_0051b930(local_190,param_3,param_4,param_5,param_6);
    }
  }
  else {
    local_8 = 2;
    if (local_20 < uVar4) {
      local_58 = param_3;
      local_54 = param_4 + local_20;
      local_3c = param_3;
      ExceptionList = &local_10;
      local_38 = local_54;
      local_14 = auStack_1d4 + 8;
      while (cVar1 = FUN_0051b730(&param_5), cVar1 != '\0') {
        uVar2 = FUN_006ea150();
        FUN_00460680(uVar2);
        local_38 = local_38 + 1;
      }
      for (uVar4 = 0; local_f8 = *(int *)(in_ECX + 0xc), local_18 = uVar4, uVar4 < local_20;
          uVar4 = uVar4 + 1) {
        local_158 = local_f8;
        local_94 = local_f8;
        uVar2 = FUN_0051b700(uVar4 + uVar3);
        FUN_00460680(uVar2);
      }
      local_104 = local_f8 + uVar3;
      local_e8 = local_f8;
      local_a4 = local_104;
      FUN_0051b930(local_1a0,param_3,param_4,local_58,local_54);
    }
    else {
      ExceptionList = &local_10;
      local_14 = auStack_1d4 + 8;
      for (local_18 = 0; local_18 < uVar4; local_18 = local_18 + 1) {
        local_178 = *(undefined4 *)(in_ECX + 0xc);
        local_b4 = local_178;
        uVar2 = FUN_0051b700((local_18 - uVar4) + local_20 + uVar3);
        FUN_00460680(uVar2);
      }
      local_168 = *(int *)(in_ECX + 0xc);
      local_11c = local_168 + local_1c;
      local_128 = local_11c + local_20;
      local_138 = local_11c + local_20;
      local_148 = local_138 - uVar4;
      local_110 = local_168;
      local_100 = uVar4;
      local_c4 = local_11c;
      local_8c = local_138;
      local_7c = local_148;
      local_6c = local_128;
      FUN_0051b970(local_1b0);
      FUN_0051b930(local_1c0,param_3,param_4,param_5,param_6);
    }
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0051c080 @ 0x0051c080 ====

void Catch_0051c080(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBP;
  
  iVar2 = *(int *)(unaff_EBP + -0x30);
  uVar3 = *(uint *)(unaff_EBP + -0x4c);
  uVar1 = *(uint *)(iVar2 + 0x10);
  while (uVar3 < uVar1) {
    FUN_006ea180();
    uVar1 = *(uint *)(iVar2 + 0x10);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== Catch@0051c2b6 @ 0x0051c2b6 ====

void Catch_0051c2b6(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int unaff_EBP;
  
  iVar2 = *(int *)(unaff_EBP + -0x30);
  uVar3 = *(uint *)(unaff_EBP + -0x4c);
  uVar1 = *(uint *)(iVar2 + 0x10);
  while (uVar3 < uVar1) {
    FUN_0045f580();
    uVar1 = *(uint *)(iVar2 + 0x10);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0051c2e0 @ 0x0051c2e0 ====

void FUN_0051c2e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_0051bdf0(param_1,param_2,param_3,param_4,param_5,param_6,param_5);
  return;
}


// ==== FUN_0051c310 @ 0x0051c310 ====

void FUN_0051c310(int param_1)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981830;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  local_8 = 0;
  FUN_0051c2e0(in_ECX,*(undefined4 *)(in_ECX + 0xc),param_1,*(int *)(param_1 + 0xc),param_1,
               *(int *)(param_1 + 0x10) + *(int *)(param_1 + 0xc));
  ExceptionList = local_10;
  return;
}


// ==== Catch@0051c39d @ 0x0051c39d ====

void Catch_0051c39d(void)

{
  FUN_0046cfc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0051c3b0 @ 0x0051c3b0 ====

void FUN_0051c3b0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009b6f6c;
  FUN_0051b4c0();
  DAT_00b5af1c = 0;
  FUN_0051bd30(local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0051c420 @ 0x0051c420 ====

void FUN_0051c420(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  FUN_0051c310(param_4 + 1);
  *(undefined1 *)(in_ECX + 9) = param_5;
  *(undefined1 *)((int)in_ECX + 0x25) = 0;
  return;
}


// ==== FUN_0051c460 @ 0x0051c460 ====

void * FUN_0051c460(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981840;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x28);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0051c420(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0051c4d5 @ 0x0051c4d5 ====

void Catch_0051c4d5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0051c4f0 @ 0x0051c4f0 ====

void FUN_0051c4f0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0xaaaaaa8 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0051c460(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x24);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x24) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[9] == '\0') {
LAB_0051c5f5:
        *(undefined1 *)(*piVar5 + 0x24) = 1;
        *(undefined1 *)(piVar6 + 9) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x24) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0058b7f0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x24) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x24) = 0;
        FUN_00412890(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[9] == '\0') goto LAB_0051c5f5;
      if (piVar7 == (int *)*piVar2) {
        FUN_00412890(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x24) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x24) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x25) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x24);
  } while( true );
}


// ==== FUN_0051c6d0 @ 0x0051c6d0 ====

void FUN_0051c6d0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x25) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x25) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_0051c4f0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058aca0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_0051c4f0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0051c790 @ 0x0051c790 ====

undefined4 * FUN_0051c790(undefined4 *param_1,int *param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_0051c4f0(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    if (*param_3 < (uint)param_2[3]) {
      FUN_0051c4f0(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    if (*(uint *)(piVar1[2] + 0xc) < *param_3) {
      FUN_0051c4f0(param_1,0,piVar1[2],param_3);
      return param_1;
    }
  }
  else {
    uVar2 = *param_3;
    uVar3 = param_2[3];
    if (uVar2 < uVar3) {
      FUN_0058aca0();
      if ((uint)param_2[3] < uVar2) {
        if (*(char *)(param_2[2] + 0x25) == '\0') {
          FUN_0051c4f0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_0051c4f0(param_1,0,param_2,param_3);
        return param_1;
      }
      uVar3 = param_2[3];
    }
    if (uVar3 < uVar2) {
      FUN_0051b6b0();
      if ((param_2 == *(int **)(in_ECX + 4)) || (uVar2 < (uint)param_2[3])) {
        if (*(char *)(param_2[2] + 0x25) == '\0') {
          FUN_0051c4f0(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_0051c4f0(param_1,0,param_2,param_3);
        return param_1;
      }
    }
  }
  puVar4 = (undefined4 *)FUN_0051c6d0(local_8,param_3);
  *param_1 = *puVar4;
  return param_1;
}


// ==== FUN_0051c900 @ 0x0051c900 ====

undefined4 * FUN_0051c900(uint *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 local_2c [4];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18 [6];
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x25) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((uint)puVar1[3] < *param_1) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x25) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_1 < (uint)puVar3[3])) {
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18[0] = *param_1;
    FUN_0051c310(local_2c);
    puVar3 = (undefined4 *)FUN_0051c790(&param_1,puVar3,local_18);
    puVar3 = (undefined4 *)*puVar3;
    FUN_0046cfc0();
    FUN_0046cfc0();
  }
  return puVar3 + 4;
}


// ==== FUN_0051c9a0 @ 0x0051c9a0 ====

void FUN_0051c9a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7418;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0051c9c0 @ 0x0051c9c0 ====

void FUN_0051c9c0(undefined4 *param_1,undefined4 *param_2)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 8);
  *param_2 = *(undefined4 *)(in_ECX + 0xc);
  return;
}


// ==== FUN_0051c9e0 @ 0x0051c9e0 ====

undefined2 FUN_0051c9e0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 4);
}


// ==== FUN_0051ca10 @ 0x0051ca10 ====

void FUN_0051ca10(short param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  void *pvVar6;
  undefined2 *puVar7;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5ab48 + 0xc))();
  while (piVar2 != (int *)0x0) {
    iVar5 = *DAT_00b5ab34;
    iVar3 = (**(code **)(*piVar2 + 4))();
    piVar4 = (int *)(**(code **)(iVar5 + 8))(*(undefined2 *)(iVar3 + 2));
    if ((piVar4 != (int *)0x0) &&
       (iVar5 = (**(code **)(*piVar4 + 4))(), *(short *)(iVar5 + 0x102) == param_1)) {
      pvVar6 = operator_new(0x1c);
      if (pvVar6 == (void *)0x0) {
        piVar4 = (int *)0x0;
      }
      else {
        piVar4 = (int *)FUN_0053bcc0();
      }
      puVar7 = (undefined2 *)(**(code **)(*piVar2 + 4))();
      cVar1 = (**(code **)(*piVar4 + 4))(*puVar7);
      if (cVar1 == '\0') {
        (**(code **)*piVar4)(1);
      }
      else {
        (**(code **)(*DAT_00b5ae10 + 4))(piVar4);
      }
    }
    piVar2 = (int *)(**(code **)(*DAT_00b5ab48 + 0x10))();
  }
  return;
}


// ==== FUN_0051cae0 @ 0x0051cae0 ====

undefined1 FUN_0051cae0(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 auStack_ff8 [601];
  undefined1 uStack_693;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x2c))();
    if (piVar1 != (int *)0x0) {
      puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x10))();
      puVar4 = auStack_ff8;
      for (iVar3 = 0x3fb; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar4 = puVar4 + 1;
      }
      return uStack_693;
    }
  }
  return 0;
}


// ==== FUN_0051cb40 @ 0x0051cb40 ====

/* WARNING: Removing unreachable block (ram,0x0051ce42) */
/* WARNING: Removing unreachable block (ram,0x0051cd86) */
/* WARNING: Removing unreachable block (ram,0x0051cd08) */
/* WARNING: Removing unreachable block (ram,0x0051cc8a) */
/* WARNING: Removing unreachable block (ram,0x0051ccc9) */
/* WARNING: Removing unreachable block (ram,0x0051cd47) */
/* WARNING: Removing unreachable block (ram,0x0051cdc5) */
/* WARNING: Removing unreachable block (ram,0x0051ce83) */
/* WARNING: Removing unreachable block (ram,0x0051cc4b) */

void FUN_0051cb40(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  uint *_Memory;
  undefined4 uStack_34;
  uint uStack_28;
  undefined1 auStack_1a [26];
  
  *in_ECX = &PTR_FUN_009b7450;
  uStack_28 = 0x51cb59;
  (**(code **)(*DAT_00b5ac94 + 0x38))();
  uStack_28 = 0x51cb64;
  (**(code **)(*DAT_00b5ac94 + 0x44))();
  uStack_28 = 0x51cb6f;
  (**(code **)(*DAT_00b5ac94 + 0x2c))();
  uStack_28 = 0x51cb7a;
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar1 != '\0') {
    uStack_28 = 0x51cb89;
    (**(code **)(*DAT_00b5ae5c + 0x3c))();
  }
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    uStack_28 = 1;
    (*(code *)**(undefined4 **)in_ECX[4])();
  }
  in_ECX[4] = 0;
  uStack_28 = 0;
  (**(code **)(*DAT_00b5ac58 + 0x3c))();
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = &PTR_FUN_009b5478;
  }
  FUN_00797a20();
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = &PTR_FUN_009b548c;
  }
  FUN_00797a20();
  uStack_34 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (uStack_34 == (undefined4 *)0x0) {
    uStack_34 = (undefined4 *)0x0;
  }
  else {
    *uStack_34 = &PTR_FUN_009b5464;
  }
  FUN_00797a20();
  uStack_34 = (undefined4 *)0xb;
  FUN_00401740();
  uStack_34 = (undefined4 *)(auStack_1a + -6);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740();
  _Memory = &uStack_28;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  uStack_28 = uStack_28 & 0xffffff00;
  FUN_00401740();
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740(s_dropitem_009b6fa8);
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  FUN_00401740(s_dropitemrange_009b6fb4,0xd);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&uStack_34);
  uStack_34 = (undefined4 *)((uint)uStack_34 & 0xffffff00);
  FUN_00401740(s_dropitemcount_009b6fc4,0xd);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_1a + -0x1e);
  uStack_28 = 0;
  FUN_00401740(s_dropitem_custom_009b6fd4,0xf);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_1a + -0x22);
  if (0xf < uStack_28) {
    _free(_Memory);
    return;
  }
  uStack_28 = 0xf;
  FUN_00401740(s_dropmoney_009b6fe4,9);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_1a + -0x26);
  FUN_00401740(s_setdaylight_009b6ff0,0xb);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_1a + -0x2a);
  DAT_00b5ae14 = 0;
  if ((void *)in_ECX[6] == (void *)0x0) {
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    *in_ECX = &PTR_FUN_009b7418;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_0051cec0 @ 0x0051cec0 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_0051cec0(int param_1)

{
  char cVar1;
  int *piVar2;
  int extraout_EAX;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 auStack_1014 [4];
  void *pvStack_1010;
  undefined4 uStack_1000;
  uint uStack_ffc;
  undefined4 uStack_ff8;
  undefined4 uStack_c;
  
  uStack_c = 0x51ced0;
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  if (piVar2 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(s_no_name_009b7284,7);
    return param_1;
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))();
  if (piVar2 == (int *)0x0) {
    uStack_ffc = 0xf;
    uStack_1000 = 0;
    pvStack_1010 = (void *)((uint)pvStack_1010 & 0xffffff00);
    FUN_00401740(&DAT_009b728c,0xd);
    FUN_00403e50(auStack_1014);
    if (uStack_ffc < 0x10) {
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401740(s_no_name_009b729c,7);
      return param_1;
    }
    _free(pvStack_1010);
    return extraout_EAX;
  }
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
  puVar6 = &uStack_ff8;
  for (iVar5 = 0x3fb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar6 = puVar6 + 1;
  }
  pcVar4 = (char *)((int)&uStack_ff8 + 2);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((int)&uStack_ff8 + 2,(int)pcVar4 - ((int)&uStack_ff8 + 3));
  return param_1;
}


// ==== FUN_0051cfe0 @ 0x0051cfe0 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_0051cfe0(int param_1)

{
  char cVar1;
  int *piVar2;
  int extraout_EAX;
  undefined4 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined1 auStack_1014 [4];
  void *pvStack_1010;
  undefined4 uStack_1000;
  uint uStack_ffc;
  undefined4 auStack_ff8 [320];
  char acStack_af6 [2794];
  undefined4 uStack_c;
  
  uStack_c = 0x51cff0;
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  if (piVar2 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_009b72a4,0);
    return param_1;
  }
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))();
  if (piVar2 == (int *)0x0) {
    uStack_ffc = 0xf;
    uStack_1000 = 0;
    pvStack_1010 = (void *)((uint)pvStack_1010 & 0xffffff00);
    FUN_00401740(&DAT_009b72a8,0xd);
    FUN_00403e50(auStack_1014);
    if (uStack_ffc < 0x10) {
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401740(&DAT_009b72b6,0);
      return param_1;
    }
    _free(pvStack_1010);
    return extraout_EAX;
  }
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
  puVar6 = auStack_ff8;
  for (iVar5 = 0x3fb; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar6 = puVar6 + 1;
  }
  pcVar4 = acStack_af6;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(acStack_af6,(int)pcVar4 - (int)(acStack_af6 + 1));
  return param_1;
}


// ==== FUN_0051d100 @ 0x0051d100 ====

void FUN_0051d100(undefined4 param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b54a0;
    *(undefined1 *)(puVar1 + 1) = 0;
    puVar1[8] = 0xf;
    puVar1[7] = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined2 *)((int)puVar1 + 6) = param_2;
  FUN_00797a20(puVar1);
  iVar2 = FUN_0051edd0(param_1);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(iVar2 + 0x40);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(iVar2 + 0x44);
  (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    uRam00000004 = 1;
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009b5450;
  *(undefined1 *)(puVar1 + 1) = 1;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0051d1b0 @ 0x0051d1b0 ====

void FUN_0051d1b0(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b54c8;
    puVar1[7] = 0xf;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0051d200 @ 0x0051d200 ====

void FUN_0051d200(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b54dc;
    puVar1[7] = 0xf;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0051d250 @ 0x0051d250 ====

void FUN_0051d250(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b54b4;
    puVar1[7] = 0xf;
    puVar1[6] = 0;
    *(undefined1 *)(puVar1 + 2) = 0;
  }
  FUN_00401660(param_1,0,0xffffffff);
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_0051d2a0 @ 0x0051d2a0 ====

void FUN_0051d2a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7450;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae14 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae14 = in_ECX;
  return;
}


// ==== FUN_0051d2d0 @ 0x0051d2d0 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Removing unreachable block (ram,0x0051d92c) */
/* WARNING: Removing unreachable block (ram,0x0051d723) */
/* WARNING: Removing unreachable block (ram,0x0051d869) */
/* WARNING: Removing unreachable block (ram,0x0051d9cc) */
/* WARNING: Removing unreachable block (ram,0x0051d6bf) */
/* WARNING: Removing unreachable block (ram,0x0051d6a0) */

void FUN_0051d2d0(void)

{
  ushort uVar1;
  char cVar2;
  void *pvVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined2 *puVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined3 *puVar9;
  int in_ECX;
  int iVar10;
  undefined2 extraout_var;
  undefined2 uVar11;
  undefined2 extraout_var_00;
  uint unaff_EDI;
  undefined4 *puVar12;
  undefined4 uStack_1108;
  uint *puVar13;
  void **ppvStack_1100;
  char *pcStack_10fc;
  uint ***_Memory;
  uint uStack_10f0;
  char *pcStack_10ec;
  char ***pppcStack_10e4;
  undefined4 uStack_10d4;
  undefined1 ***_Memory_00;
  uint uVar14;
  int *piVar15;
  char **ppcStack_10cc;
  void *pvStack_10c8;
  char *pcStack_10c4;
  undefined1 **ppuStack_10bc;
  undefined1 *puStack_10a4;
  char *pcStack_10a0;
  undefined1 *_Memory_01;
  uint uStack_1094;
  char *pcStack_1090;
  undefined4 uStack_108c;
  int **ppiStack_1078;
  undefined1 auStack_1066 [2];
  void *pvStack_105c;
  void *pvStack_1054;
  undefined1 uStack_1050;
  uint uStack_1048;
  undefined4 uStack_1044;
  void *pvStack_1040;
  undefined4 uStack_103c;
  undefined4 uStack_1030;
  uint uStack_102c;
  int local_1028;
  int *piStack_1024;
  undefined4 uStack_1020;
  undefined4 uStack_101c;
  undefined4 uStack_1018;
  undefined4 uStack_1014;
  undefined4 uStack_100c;
  undefined4 uStack_1008;
  undefined4 uStack_1004;
  int *piStack_1000;
  undefined4 uStack_ffc;
  undefined4 auStack_ff8 [22];
  char acStack_f9e [256];
  char acStack_e9e [256];
  char acStack_d9e [256];
  undefined1 auStack_c9e [682];
  undefined4 uStack_9f4;
  undefined4 uStack_9f0;
  undefined4 uStack_9ec;
  undefined4 uStack_9e8;
  int *piStack_9e4;
  uint uStack_9e0;
  undefined4 uStack_9dc;
  undefined4 auStack_9d8 [28];
  undefined1 auStack_968 [541];
  undefined1 auStack_74b [3];
  undefined4 uStack_748;
  undefined1 uStack_693;
  undefined4 uStack_c;
  undefined1 auStack_8 [4];
  
  uStack_c = 0x51d2e0;
  ppiStack_1078 = (int **)0x51d2f5;
  local_1028 = in_ECX;
  pvVar3 = operator_new(0x10);
  if (pvVar3 == (void *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0053c350();
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar4;
  piVar5 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  if (piVar5 == (int *)0x0) {
    ppiStack_1078 = (int **)&DAT_009b6ffc;
    uStack_102c = 0xf;
    uStack_1030 = 0;
    pvStack_1040 = (void *)((uint)pvStack_1040 & 0xffffff00);
    FUN_00401740();
    ppiStack_1078 = (int **)0x51d347;
    FUN_00403e50();
    if (0xf < uStack_102c) {
      ppiStack_1078 = (int **)0x51d35e;
      _free(pvStack_1040);
      return;
    }
  }
  else {
    puVar6 = (undefined2 *)(**(code **)(*piVar5 + 0x1c))();
    *(undefined2 *)(in_ECX + 4) = *puVar6;
    piStack_1024 = (int *)(**(code **)(*piVar5 + 0x2c))();
    if (piStack_1024 == (int *)0x0) {
      ppiStack_1078 = (int **)&DAT_009b700c;
      uStack_102c = 0xf;
      uStack_1030 = 0;
      pvStack_1040 = (void *)((uint)pvStack_1040 & 0xffffff00);
      FUN_00401740();
      ppiStack_1078 = (int **)0x51d3b0;
      FUN_00403e50();
      if (0xf < uStack_102c) {
        ppiStack_1078 = (int **)0x51d3c7;
        _free(pvStack_1040);
        return;
      }
    }
    else {
      puVar7 = (undefined4 *)(**(code **)(*piStack_1024 + 0x10))();
      puVar12 = auStack_ff8;
      for (iVar10 = 0x3fb; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar12 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar12 = puVar12 + 1;
      }
      puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar7 != (undefined4 *)0x0) {
        uVar1 = *(ushort *)(local_1028 + 4);
        *puVar7 = &PTR_FUN_009b743c;
        puVar7[1] = (uint)uVar1;
        *(undefined1 *)(puVar7 + 2) = uStack_693;
      }
      ppiStack_1078 = (int **)0x51d41a;
      FUN_00797a20();
      ppiStack_1078 = (int **)(uint)*(ushort *)(local_1028 + 4);
      pcStack_1090 = (char *)((uint)pcStack_1090 & 0xffffff00);
      pcStack_10a0 = (char *)0x51d44a;
      FUN_00401740();
      FUN_00404230();
      pcStack_10a0 = (char *)0x51d45a;
      FUN_00403e50();
      if (0xf < uStack_1048) {
        ppiStack_1078 = (int **)0x51d46d;
        _free(pvStack_105c);
        return;
      }
      uStack_100c = uStack_9f4;
      uStack_1008 = uStack_9f0;
      uStack_1004 = uStack_9e8;
      piStack_1000 = piStack_9e4;
      uStack_ffc = uStack_9ec;
      ppiStack_1078 = (int **)0x51d4cb;
      (**(code **)(*DAT_00b5ae24 + 4))();
      ppiStack_1078 = (int **)0x51d4d6;
      iVar10 = (**(code **)(*DAT_00b5a988 + 0xc))();
      uStack_101c = *(undefined4 *)(iVar10 + 8);
      uStack_1018 = *(undefined4 *)(iVar10 + 0xc);
      piStack_1024 = piStack_9e4;
      uStack_1020 = uStack_9dc;
      ppiStack_1078 = &piStack_1024;
      uStack_1014 = auStack_9d8[0];
      (**(code **)(*DAT_00b5a988 + 0x10))();
      (**(code **)(*DAT_00b5ac58 + 0x3c))();
      (**(code **)(*DAT_00b5ac58 + 0x28))();
      (**(code **)(*DAT_00b5ac58 + 0x44))();
      pcVar8 = (char *)auStack_9d8;
      uStack_103c = 0xf;
      pvStack_1040 = (void *)0x0;
      uStack_1050 = 0;
      do {
        cVar2 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar2 != '\0');
      uStack_108c = (int ***)0x51d592;
      FUN_00401740();
      (**(code **)(*DAT_00b5ac58 + 0xc))();
      if (0xf < pvStack_1040) {
        uStack_108c = (int ***)0x51d5b2;
        _free(pvStack_1054);
        return;
      }
      uStack_108c = (int ***)0x51d5c8;
      (**(code **)(*DAT_00b5ac58 + 0x1c))();
      uStack_108c = (int ***)0x34;
      pcStack_1090 = s_callmonster__mon_type____mon_zon_009b7048;
      uStack_1094 = 0x51d5e4;
      FUN_00401740();
      uStack_108c = (int ***)0xb;
      pcStack_1090 = s_callmonster_009b7080;
      uStack_1044 = 0xf;
      uStack_1048 = 0;
      uStack_1094 = 0x51d600;
      FUN_00401740();
      uStack_108c = &ppiStack_1078;
      pcStack_1090 = (char *)0x3;
      uStack_1094 = 1;
      (**(code **)(*DAT_00b5a6c8 + 4))();
      if ((void *)0xf < pvStack_1054) {
        pcStack_10a0 = (char *)0x51d629;
        _free(auStack_8 + 4);
        return;
      }
      pvStack_1054 = (void *)0xf;
      if (0xf < unaff_EDI) {
        pcStack_10a0 = (char *)0x51d648;
        _free(&pvStack_1054);
        return;
      }
      pcStack_10a0 = s_callmonsters__mon_type___mon_cou_009b708c;
      puStack_10a4 = (undefined1 *)0x51d667;
      FUN_00401740();
      pcStack_10a0 = s_callmonsters_009b70b0;
      pvStack_1054 = (void *)0xf;
      puStack_10a4 = (undefined1 *)0x51d683;
      FUN_00401740();
      _Memory_01 = auStack_1066 + -0x22;
      pcStack_10a0 = (void *)0x2;
      puStack_10a4 = auStack_1066 + -6;
      (**(code **)(*DAT_00b5a6c8 + 8))();
      pcStack_1090 = (char *)((uint)pcStack_1090 & 0xffffff00);
      FUN_00401740();
      FUN_00401740();
      puVar13 = &uStack_1094;
      (**(code **)(*DAT_00b5a6c8 + 4))();
      if ((int ***)0xf < uStack_108c) {
        ppuStack_10bc = (undefined1 **)0x51d74c;
        _free(pcStack_10a0);
        return;
      }
      ppuStack_10bc = (undefined1 **)s_clearprefix_009b70fc;
      uStack_108c = (int ***)0xf;
      pcStack_1090 = (char *)0x0;
      pcStack_10a0 = (char *)((uint)pcStack_10a0 & 0xffffff00);
      FUN_00401740();
      pvVar3 = (void *)0x0;
      ppuStack_10bc = &puStack_10a4;
      (**(code **)(*DAT_00b5a6c8 + 0xc))();
      if (0xf < uStack_1094) {
        pcStack_10c4 = (char *)0x51d78c;
        _free(puVar13);
        return;
      }
      pcStack_10c4 = s_dropitem__item_index____socket___009b7108;
      uStack_1094 = 0xf;
      pvStack_10c8 = (void *)0x51d7ab;
      FUN_00401740();
      pcStack_10c4 = s_dropitem_009b7150;
      ppiStack_1078 = (int **)0xf;
      uStack_108c = (int ***)((uint)uStack_108c & 0xffffff00);
      pvStack_10c8 = (void *)0x51d7c7;
      FUN_00401740();
      pcStack_10c4 = (char *)0x3;
      pvStack_10c8 = (void *)0x1;
      ppcStack_10cc = &pcStack_1090;
      (**(code **)(*DAT_00b5a6c8 + 4))();
      if (0xf < uStack_9e0) {
        uStack_10d4 = (char *)0x51d7f0;
        _free(_Memory_01);
        return;
      }
      uStack_108c = (int ***)0x0;
      if ((undefined1 *)0xf < puStack_10a4) {
        uStack_10d4 = (char *)0x51d80f;
        _free(pvVar3);
        return;
      }
      uStack_10d4 = s_dropitem__item_index___count_____009b7160;
      puStack_10a4 = (undefined1 *)0xf;
      FUN_00401740();
      uStack_10d4 = s_dropitemcount_009b71b0;
      uStack_108c = (int ***)0x0;
      FUN_00401740();
      _Memory_00 = &ppuStack_10bc;
      uStack_10d4 = (char *)0x4;
      (**(code **)(*DAT_00b5a6c8 + 4))();
      if ((int ***)0xf < &ppiStack_1078) {
        pppcStack_10e4 = (char ***)0x51d892;
        _free(pvStack_10c8);
        return;
      }
      pppcStack_10e4 = (char ***)s_dropitemrange_009b71c0;
      pvStack_10c8 = (void *)((uint)pvStack_10c8 & 0xffffff00);
      FUN_00401740();
      pvVar3 = (void *)0x2;
      pppcStack_10e4 = &ppcStack_10cc;
      (**(code **)(*DAT_00b5a6c8 + 0xc))();
      if ((undefined1 **)0xf < ppuStack_10bc) {
        pcStack_10ec = (char *)0x51d8d3;
        _free(_Memory_00);
        return;
      }
      pcStack_10ec = s_dropitem__item_index___socket____009b71d0;
      ppuStack_10bc = (undefined1 **)0xf;
      uStack_10f0 = 0x51d8f2;
      FUN_00401740();
      pcStack_10ec = s_dropitem_custom_009b720c;
      pcStack_10a0 = (char *)0xf;
      puStack_10a4 = (undefined1 *)0x0;
      uStack_10f0 = 0x51d90d;
      FUN_00401740();
      puVar7 = &uStack_10d4;
      pcStack_10ec = (char *)0x7;
      uStack_10f0 = 3;
      (**(code **)(*DAT_00b5a6c8 + 4))();
      pcStack_10c4 = (char *)((uint)pcStack_10c4 & 0xffffff00);
      if ((char **)0xf < ppcStack_10cc) {
        pcStack_10fc = (char *)0x51d955;
        _free(pvVar3);
        return;
      }
      pcStack_10fc = s_dropmoney__money__009b721c;
      ppcStack_10cc = (char **)0xf;
      pvVar3 = (void *)0x0;
      ppvStack_1100 = (void **)0x51d974;
      FUN_00401740();
      pcStack_10fc = s_dropmoney_009b7230;
      pcStack_10c4 = (char *)((uint)pcStack_10c4 & 0xffffff00);
      ppvStack_1100 = (void **)0x51d990;
      FUN_00401740();
      _Memory = (uint ***)&pppcStack_10e4;
      pcStack_10fc = (char *)0x1;
      ppvStack_1100 = &pvStack_10c8;
      (**(code **)(*DAT_00b5a6c8 + 8))();
      if ((undefined1 **)0xf < ppuStack_10bc) {
        uStack_1108 = (char *)0x51d9b7;
        _free(pvVar3);
        return;
      }
      ppuStack_10bc = (undefined1 **)0xf;
      uVar14 = (uint)pvVar3 & 0xffffff00;
      uStack_1108 = s__1_on_0_off__009b723c;
      pcStack_10ec = (char *)((uint)pcStack_10ec & 0xffffff00);
      FUN_00401740();
      uStack_1108 = s_setdaylight_009b724c;
      ppuStack_10bc = (undefined1 **)0xf;
      uVar14 = uVar14 & 0xffffff00;
      FUN_00401740();
      puVar13 = &uStack_10f0;
      uStack_1108 = (char *)0x1;
      (**(code **)(*DAT_00b5a6c8 + 8))(&uStack_10d4);
      if ((void *)0xf < pvStack_10c8) {
        _free((void *)0x0);
        return;
      }
      pvStack_10c8 = (void *)0xf;
      ppcStack_10cc = (char **)0x0;
      if ((char ***)0xf < pppcStack_10e4) {
        _free(_Memory);
        return;
      }
      FUN_00401740(s_ds_zfar__f_009b7258,10);
      FUN_00404230(&pcStack_10fc);
      (**(code **)(*DAT_00b5a688 + 4))();
      if ((undefined4 *)0xf < puVar7) {
        _free(pcStack_10fc);
        return;
      }
      pcStack_10ec = (char *)0x0;
      pcStack_10fc = (char *)((uint)pcStack_10fc & 0xffffff00);
      FUN_00401740();
      uVar4 = FUN_00402220(&pppcStack_10e4,&ppvStack_1100,auStack_968);
      (**(code **)(*DAT_00b5a688 + 4))(uVar4);
      if (0xf < uVar14) {
        _free(pppcStack_10e4);
        return;
      }
      piVar5 = (int *)0xf;
      uStack_10d4 = (char *)0x0;
      pppcStack_10e4 = (char ***)((uint)pppcStack_10e4 & 0xffffff00);
      if (0xf < pcStack_10ec) {
        _free(ppvStack_1100);
        return;
      }
      FUN_00401740(s_rc_geomipmap__d__f_009b7270,0x12);
      FUN_00404230((int)register0x00000010 + -0x1104);
      (**(code **)(*DAT_00b5a688 + 4))();
      if (0xf < uStack_10f0) {
        _free(puVar13);
        return;
      }
      pcVar8 = acStack_f9e;
      uStack_10f0 = 0xf;
      pvVar3 = (void *)((uint)puVar13 & 0xffffff00);
      do {
        cVar2 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar2 != '\0');
      FUN_00401740(acStack_f9e,(int)pcVar8 - (int)(acStack_f9e + 1));
      piVar15 = piVar5;
      FUN_0051d100(&uStack_1108,CONCAT22(extraout_var_00,(short)piVar5[1]));
      if (0xf < uStack_10f0) {
        _free(pvVar3);
        return;
      }
      pcVar8 = acStack_e9e;
      uStack_10f0 = 0xf;
      pvVar3 = (void *)((uint)pvVar3 & 0xffffff00);
      do {
        cVar2 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar2 != '\0');
      FUN_00401740(acStack_e9e,(int)pcVar8 - (int)(acStack_e9e + 1));
      FUN_0051d1b0(&uStack_1108);
      if (0xf < uStack_10f0) {
        _free(pvVar3);
        return;
      }
      pcVar8 = acStack_d9e;
      uStack_10f0 = 0xf;
      pvVar3 = (void *)((uint)pvVar3 & 0xffffff00);
      do {
        cVar2 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar2 != '\0');
      FUN_00401740(acStack_d9e,(int)pcVar8 - (int)(acStack_d9e + 1));
      FUN_0051d200(&uStack_1108);
      if (0xf < uStack_10f0) {
        _free(pvVar3);
        return;
      }
      FUN_00401830(auStack_c9e);
      FUN_0051d250(&uStack_1108);
      if (0xf < uStack_10f0) {
        _free(pvVar3);
        return;
      }
      (**(code **)(*DAT_00b5adc4 + 0x34))(uStack_748);
      uVar11 = 0;
      if (DAT_00b5ad00 != (int *)0x0) {
        (**(code **)(*DAT_00b5ad00 + 0x18))(auStack_74b);
        uVar11 = extraout_var;
      }
      FUN_0051ca10(CONCAT22(uVar11,(short)piVar5[1]));
      uStack_10d4 = (char *)CONCAT13(uStack_10d4._3_1_,0x640001);
      FUN_0051f0a0(&uStack_10d4);
      uStack_10d4._0_2_ = 3;
      FUN_0051f0a0(&uStack_10d4);
      cVar2 = (**(code **)(*DAT_00b5ae58 + 8))();
      if (cVar2 == '\0') {
        cVar2 = (**(code **)(*piVar15 + 0x1c))();
        if (cVar2 != '\0') {
          (**(code **)(*DAT_00b5ac94 + 4))();
          cVar2 = (**(code **)(*DAT_00b5ac98 + 0x44))();
          if (cVar2 != '\0') {
            (**(code **)(*DAT_00b5ac94 + 0x10))();
            (**(code **)(*DAT_00b5ac94 + 0x18))();
          }
        }
        iVar10 = (**(code **)(*DAT_00b5aca8 + 0x1c))();
        if (iVar10 != 0) {
          (**(code **)(*DAT_00b5ac94 + 4))();
        }
      }
      else {
        (**(code **)(*DAT_00b5ae54 + 0x14))();
        (**(code **)(*DAT_00b5ae5c + 0x38))();
        puVar9 = (undefined3 *)(**(code **)(*DAT_00b5ae54 + 0x24))();
        uStack_10d4 = (char *)CONCAT13(uStack_10d4._3_1_,*puVar9);
        iVar10 = (**(code **)(*DAT_00b5ae58 + 0x20))();
        if ((iVar10 != 2) && (uStack_10d4._1_1_ != '\0')) {
          (**(code **)(*DAT_00b5ac94 + 4))();
          (**(code **)(*DAT_00b5ac94 + 0x18))();
          return;
        }
      }
    }
  }
  return;
}


// ==== FUN_0051ddf0 @ 0x0051ddf0 ====

undefined4 FUN_0051ddf0(int param_1)

{
  char cVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  int iVar5;
  undefined4 uVar6;
  undefined4 extraout_EAX_00;
  int *piVar7;
  undefined4 *puVar8;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 extraout_EAX_05;
  undefined4 extraout_EAX_06;
  undefined4 extraout_EAX_07;
  undefined4 extraout_EAX_08;
  uint uVar9;
  int in_ECX;
  float10 fVar10;
  undefined2 uStack_98;
  undefined1 uStack_96;
  undefined4 uStack_94;
  undefined1 auStack_90 [4];
  void *local_8c;
  void *pvStack_88;
  uint uStack_78;
  uint uStack_74;
  uint local_68;
  int local_64;
  void *pvStack_60;
  void *pvStack_5c;
  undefined4 uStack_50;
  uint uStack_4c;
  uint uStack_48;
  void *local_44;
  void *pvStack_40;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  float fStack_24;
  undefined1 local_1c [28];
  
  iVar5 = param_1 + 8;
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_callmonster_009b72b8,0xb);
  if (iVar3 == 0) {
    uVar4 = FUN_00459160(&local_8c,0);
    uVar4 = thunk_FUN_00796f80(uVar4);
    if (0xf < uStack_74) {
      _free(pvStack_88);
      return extraout_EAX;
    }
    iVar5 = (**(code **)(*DAT_00b5a75c + 8))(uVar4);
    if (iVar5 != 0) {
      FUN_00401740(s_call__u_monster__009b72e0,0x11);
      uVar6 = FUN_00404230(auStack_90);
      FUN_00796d20(uVar6);
      if (0xf < uStack_78) {
        _free(local_8c);
        return extraout_EAX_00;
      }
      piVar7 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      puVar8 = (undefined4 *)(**(code **)(*piVar7 + 0x28))();
      uVar6 = (**(code **)(*piVar7 + 0x2c))();
      uStack_2c = *puVar8;
      uStack_28 = puVar8[1];
      fVar10 = (float10)FUN_0040d5f0(uVar6);
      fStack_24 = (float)fVar10;
      iVar5 = (**(code **)(*DAT_00b5ac1c + 0x20))();
      if (iVar5 == 2) {
        uVar6 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        iVar5 = FUN_0051ebd0(uVar6);
        *(short *)(iVar5 + 0x10) = (short)uVar4;
        puVar8 = (undefined4 *)FUN_004ef0e0(&uStack_98);
        *(undefined4 *)(iVar5 + 0x12) = *puVar8;
        *(undefined2 *)(iVar5 + 0x16) = *(undefined2 *)(puVar8 + 1);
      }
      else {
        iVar5 = (**(code **)(*DAT_00b5ac1c + 0x20))();
        if ((iVar5 != 3) && (iVar5 = (**(code **)(*DAT_00b5ac1c + 0x20))(), iVar5 != 4)) {
          return 1;
        }
        uVar6 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        iVar5 = FUN_0051ec00(uVar6);
        *(short *)(iVar5 + 0x10) = (short)uVar4;
        puVar8 = (undefined4 *)FUN_004ef0e0(&uStack_98);
        *(undefined4 *)(iVar5 + 0x12) = *puVar8;
        *(undefined2 *)(iVar5 + 0x16) = *(undefined2 *)(puVar8 + 1);
      }
      *(undefined2 *)(iVar5 + 0x18) = 0;
      FUN_004d8570(iVar5);
      return 1;
    }
    FUN_00401740(s___select_invalid_monster___009b72c4,0x1a);
    uVar4 = FUN_00404230(auStack_90);
    FUN_00796d20(uVar4);
  }
  else {
    iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_callmonsters_009b72f4,0xc);
    if (iVar3 != 0) {
      iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_setprefix_009b7358,9);
      if (iVar3 == 0) {
        local_64 = in_ECX + 0x14;
        FUN_00412dc0();
        if (*(int *)(param_1 + 0x28) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = (ushort)((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c);
        }
        if (uVar2 >> 1 != 0) {
          local_68 = (uint)(uVar2 >> 1);
          iVar5 = 0;
          do {
            uVar4 = FUN_00459160(&local_44,iVar5);
            uStack_98 = thunk_FUN_00796f80(uVar4);
            if (0xf < uStack_2c) {
              _free(pvStack_40);
              return extraout_EAX_07;
            }
            uStack_2c = 0xf;
            uStack_30 = 0;
            pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
            uVar4 = FUN_00459160(&pvStack_60,iVar5 + 1);
            uStack_96 = thunk_FUN_00796f50(uVar4);
            if (0xf < uStack_48) {
              _free(pvStack_5c);
              return extraout_EAX_08;
            }
            uStack_48 = 0xf;
            uStack_4c = 0;
            pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
            FUN_0051f0a0(&uStack_98);
            iVar5 = iVar5 + 2;
            local_68 = local_68 - 1;
          } while (local_68 != 0);
        }
        return 1;
      }
      cVar1 = FUN_004036a0(iVar5,s_clearprefix_009b7364);
      if (cVar1 != '\0') {
        FUN_00412dc0();
        return 1;
      }
      cVar1 = FUN_004036a0(iVar5,s_dropitemrange_009b7370);
      if (cVar1 != '\0') {
        uVar9 = FUN_004f45a0();
        if (1 < uVar9) {
          uVar4 = FUN_00459160(&local_8c,0);
          thunk_FUN_00796f80(uVar4);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        return 1;
      }
      cVar1 = FUN_004036a0(iVar5,s_dropitemcount_009b738c);
      if (cVar1 != '\0') {
        uVar9 = FUN_004f45a0();
        if (1 < uVar9) {
          uVar4 = FUN_00459160(&local_8c,0);
          thunk_FUN_00796f80(uVar4);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        return 1;
      }
      cVar1 = FUN_004036a0(iVar5,s_dropitem_custom_009b73ac);
      if (cVar1 != '\0') {
        uVar9 = FUN_004f45a0();
        if (uVar9 < 3) {
          return 1;
        }
        uVar9 = FUN_004f45a0();
        if (uVar9 < 7) {
          uVar4 = FUN_00459160(local_1c,0);
          uStack_94 = thunk_FUN_00796f80(uVar4);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        return 1;
      }
      cVar1 = FUN_004036a0(iVar5,s_dropitem_009b73bc);
      if (cVar1 != '\0') {
        iVar5 = FUN_004f45a0();
        if (iVar5 != 0) {
          uVar4 = FUN_00459160(local_1c,0);
          uStack_94 = thunk_FUN_00796f80(uVar4);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        return 1;
      }
      cVar1 = FUN_004036a0(iVar5,s_dropmoney_009b73e8);
      if (cVar1 == '\0') {
        return 0;
      }
      iVar5 = FUN_004f45a0();
      if (iVar5 == 1) {
        uVar4 = FUN_00459160(local_1c,0);
        thunk_FUN_00796fb0(uVar4);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      return 1;
    }
    FUN_00459160(&local_8c,0);
    uVar4 = FUN_00459160(&local_44,1);
    iVar5 = thunk_FUN_00796e60(uVar4);
    if (0xf < uStack_30) {
      _free(local_44);
      return extraout_EAX_01;
    }
    if (0x32 < iVar5) {
      iVar5 = 0x32;
      FUN_00401830(s_can_t_not_call_monsters_more_tha_009b7304);
      FUN_00796d20(&uStack_48);
      if (0xf < uStack_30) {
        _free(local_44);
        return extraout_EAX_02;
      }
      FUN_00401830(s__>_callmonsters_50_009b7334);
      FUN_00796d20(&uStack_48);
      if (0xf < uStack_30) {
        _free(local_44);
        return extraout_EAX_03;
      }
    }
    if (0 < iVar5) {
      do {
        uStack_4c = 0xf;
        uStack_50 = 0;
        pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
        FUN_00401740(s_callmonster_009b7348,0xc);
        uVar4 = FUN_00405bd0(&uStack_48,&local_64,auStack_90);
        (**(code **)(*DAT_00b5a688 + 4))(uVar4);
        if (0xf < uStack_30) {
          _free(local_44);
          return extraout_EAX_04;
        }
        uStack_30 = 0xf;
        uStack_34 = 0;
        local_44 = (void *)((uint)local_44 & 0xffffff00);
        if (0xf < uStack_4c) {
          _free(pvStack_60);
          return extraout_EAX_05;
        }
        iVar5 = iVar5 + -1;
        uStack_4c = 0xf;
        uStack_50 = 0;
        pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
      } while (iVar5 != 0);
    }
  }
  if (uStack_78 < 0x10) {
    return 1;
  }
  _free(local_8c);
  return extraout_EAX_06;
}


// ==== FUN_0051eb80 @ 0x0051eb80 ====

undefined4 FUN_0051eb80(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  cVar1 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x10))(param_1);
  if (cVar1 == '\x01') {
    return 1;
  }
  iVar2 = (**(code **)(*param_1 + 4))();
  if (((iVar2 == 0x40001) || (iVar2 != 0x70004)) || (cVar1 = FUN_0051ddf0(param_1), cVar1 == '\0'))
  {
    return 0;
  }
  return 1;
}


// ==== FUN_0051ebd0 @ 0x0051ebd0 ====

void FUN_0051ebd0(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x7000009;
  *(undefined2 *)((int)pvVar1 + 6) = 0x1c;
  FUN_004244d0();
  return;
}


// ==== FUN_0051ec00 @ 0x0051ec00 ====

void FUN_0051ec00(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x8000004;
  *(undefined2 *)((int)pvVar1 + 6) = 0x1c;
  FUN_004244d0();
  return;
}


// ==== FUN_0051ec90 @ 0x0051ec90 ====

undefined4 FUN_0051ec90(void)

{
  return 0x60090001;
}


// ==== FUN_0051eca0 @ 0x0051eca0 ====

int FUN_0051eca0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981850;
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


// ==== Catch@0051ed06 @ 0x0051ed06 ====

void Catch_0051ed06(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0051ed10 @ 0x0051ed10 ====

void FUN_0051ed10(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981860;
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


// ==== Catch@0051ed76 @ 0x0051ed76 ====

void Catch_0051ed76(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0051ed80 @ 0x0051ed80 ====

void FUN_0051ed80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0051eca0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0051eda0 @ 0x0051eda0 ====

int FUN_0051eda0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0051ed10(param_1,param_2,param_3);
  return param_1 + param_2 * 4;
}


// ==== FUN_0051edd0 @ 0x0051edd0 ====

undefined4 FUN_0051edd0(undefined4 param_1)

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
  local_4 = 1;
  uVar2 = (**(code **)(*piVar1 + 8))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_0051ee30 @ 0x0051ee30 ====

void FUN_0051ee30(byte param_1)

{
  void *in_ECX;
  
  FUN_0051cb40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0051ee50 @ 0x0051ee50 ====

void FUN_0051ee50(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00981870;
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
      uVar5 = FUN_0051ed80(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_0051eda0(uVar5,param_2,&local_18);
      FUN_0051ed80(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_0051eca0(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_0051eda0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_0051eca0(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0051efb1 @ 0x0051efb1 ====

void Catch_0051efb1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0051f0a0 @ 0x0051f0a0 ====

void FUN_0051f0a0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_0051ee50(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0051ed10(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 4;
  return;
}


// ==== FUN_0051f120 @ 0x0051f120 ====

undefined4 * FUN_0051f120(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x28))();
  *param_1 = *puVar1;
  param_1[1] = puVar1[1];
  return param_1;
}


// ==== FUN_0051f140 @ 0x0051f140 ====

void FUN_0051f140(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0051f145. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x30))();
  return;
}


// ==== FUN_0051f150 @ 0x0051f150 ====

void FUN_0051f150(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x0051f15c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 8))();
  return;
}


// ==== FUN_0051f160 @ 0x0051f160 ====

void FUN_0051f160(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0051f165. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x38))();
  return;
}


// ==== FUN_0051f170 @ 0x0051f170 ====

void FUN_0051f170(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0051f175. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x3c))();
  return;
}


// ==== FUN_0051f180 @ 0x0051f180 ====

undefined4 FUN_0051f180(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0051f190 @ 0x0051f190 ====

void FUN_0051f190(undefined4 param_1,undefined1 param_2)

{
  int *in_ECX;
  float unaff_ESI;
  float10 fVar1;
  float10 fVar2;
  undefined1 uStack00000000;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x24))();
  fVar2 = (float10)(**(code **)(*in_ECX + 0x28))();
  (**(code **)(*in_ECX + 0x10))(&fStack_18);
  fStack_c = (float)fVar2 - unaff_ESI;
  fStack_8 = fStack_18 - (float)fVar1;
  fStack_14 = (float)fVar2 + unaff_ESI;
  fStack_10 = fStack_18 + (float)fVar1;
  FUN_0040e9f0(&fStack_c,&fStack_14,&uStack00000000,&param_2);
  return;
}


// ==== FUN_0051f210 @ 0x0051f210 ====

void FUN_0051f210(undefined4 *param_1)

{
  undefined4 local_8;
  undefined4 local_4;
  
  *param_1 = local_8;
  param_1[1] = local_4;
  return;
}


// ==== FUN_0051f230 @ 0x0051f230 ====

void FUN_0051f230(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b7504;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_0051f250 @ 0x0051f250 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0051f250(float param_1,float param_2,undefined4 param_3)

{
  float *pfVar1;
  undefined4 uVar2;
  int *in_ECX;
  float10 fVar3;
  float10 extraout_ST0;
  float unaff_retaddr;
  float fStack_14;
  float fStack_10;
  undefined1 local_8 [8];
  
  pfVar1 = (float *)(**(code **)(*in_ECX + 0x10))(local_8);
  fStack_14 = *pfVar1 - unaff_retaddr;
  fStack_10 = pfVar1[1] - param_1;
  if (SQRT(fStack_10 * fStack_10 + fStack_14 * fStack_14) <= DAT_009a09bc) {
    return 1;
  }
  fVar3 = (float10)FUN_0040d5f0(&fStack_14);
  FUN_0040d0f0((float)((float10)_DAT_00aec9ec * (float10)DAT_0099d0b4 + (fVar3 - (float10)param_2)))
  ;
  if ((float10)_DAT_00aec9ec < extraout_ST0) {
    return 0;
  }
  uVar2 = (**(code **)(*in_ECX + 0x30))(unaff_retaddr,param_1,param_3);
  return uVar2;
}


// ==== FUN_0051f310 @ 0x0051f310 ====

undefined4 FUN_0051f310(float param_1,float param_2)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  int *in_ECX;
  float10 extraout_ST0;
  float unaff_retaddr;
  undefined1 local_8 [8];
  
  pfVar3 = (float *)(**(code **)(*in_ECX + 0x10))(local_8);
  fVar1 = *pfVar3;
  fVar2 = pfVar3[1];
  (**(code **)(*in_ECX + 0x20))();
  if ((float10)SQRT((fVar2 - param_1) * (fVar2 - param_1) +
                    (fVar1 - unaff_retaddr) * (fVar1 - unaff_retaddr)) <
      extraout_ST0 + (float10)param_2) {
    return 1;
  }
  return 0;
}


// ==== FUN_0051f370 @ 0x0051f370 ====

bool FUN_0051f370(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  bool bVar5;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  if (param_1 == 1) {
    if (iVar2 == 0) {
      return true;
    }
    if (iVar2 == 2) {
      return true;
    }
  }
  else {
    if (param_1 == 2) {
      if ((iVar2 != 5) && (iVar2 != 1)) {
        if ((iVar2 == 0) || (iVar2 == 2)) {
          piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
          uVar4 = (**(code **)(*piVar3 + 8))();
          cVar1 = (**(code **)(*DAT_00b5ad9c + 0x10))(uVar4);
          if (cVar1 == '\x01') {
            return true;
          }
          piVar3 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
          piVar3 = (int *)(**(code **)(*piVar3 + 0x2c))();
          cVar1 = (**(code **)(*piVar3 + 0x1c))();
          if ((cVar1 != '\0') && (cVar1 = (**(code **)(*DAT_00b5acac + 0x40))(uVar4), cVar1 == '\0')
             ) {
            return true;
          }
          cVar1 = (**(code **)(*DAT_00b5ada8 + 0x20))();
          if ((cVar1 != '\0') && (cVar1 = (**(code **)(*DAT_00b5a7b8 + 0x3c))(uVar4), cVar1 == '\0')
             ) {
            return true;
          }
          cVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
          if (cVar1 == '\0') {
            return false;
          }
          cVar1 = (**(code **)(*DAT_00b5ad04 + 0x14))(uVar4);
          bVar5 = cVar1 == '\x01';
        }
        else {
          if (iVar2 != 6) {
            return false;
          }
          iVar2 = (**(code **)(*DAT_00b5acac + 0x48))();
          bVar5 = iVar2 == 3;
        }
        if (!bVar5) {
          return false;
        }
      }
      return true;
    }
    if (param_1 == 3) {
      if (iVar2 == 5) {
        return true;
      }
      if (iVar2 == 1) {
        return true;
      }
      cVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
      if (cVar1 != '\0') {
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
        uVar4 = (**(code **)(*piVar3 + 8))();
        cVar1 = (**(code **)(*DAT_00b5ad04 + 0x10))(uVar4);
        return cVar1 == '\x01';
      }
    }
  }
  return false;
}


// ==== FUN_0051f4c0 @ 0x0051f4c0 ====

void FUN_0051f4c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = FUN_0051f370(param_4);
  if (cVar1 == '\0') {
    return;
  }
  (**(code **)(*in_ECX + 0x30))(param_1,param_2,param_3);
  return;
}


// ==== FUN_0051f4f0 @ 0x0051f4f0 ====

uint FUN_0051f4f0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x34))();
  if ((char)uVar1 != '\0') {
    uVar1 = (**(code **)(*in_ECX + 0x2c))();
    if ((char)uVar1 != '\0') {
      iVar2 = (**(code **)(*in_ECX + 0x38))();
      if (iVar2 == 0) {
        uVar1 = FUN_0051f310(param_1,param_2,param_3);
        return uVar1;
      }
      uVar1 = (**(code **)(*in_ECX + 0x38))();
      if (uVar1 == 1) {
        uVar1 = FUN_0051f190(param_1,param_2,param_3);
        return uVar1;
      }
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0051f560 @ 0x0051f560 ====

float10 FUN_0051f560(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  float10 extraout_ST0;
  float10 fVar3;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  if (iVar2 != 0) {
    return (float10)*(float *)(iVar2 + 0x38) + (float10)DAT_0099d080;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pState____NULL_009b7474,0xe);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    fVar3 = (float10)(*pcVar1)();
    return fVar3;
  }
  _free(pvStack_18);
  return extraout_ST0;
}


// ==== FUN_0051f5d0 @ 0x0051f5d0 ====

float10 FUN_0051f5d0(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  float10 extraout_ST0;
  float10 fVar3;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  if (iVar2 != 0) {
    return (float10)*(float *)(iVar2 + 0x38) + (float10)DAT_0099d080;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pState____NULL_009b7484,0xe);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    fVar3 = (float10)(*pcVar1)();
    return fVar3;
  }
  _free(pvStack_18);
  return extraout_ST0;
}


// ==== FUN_0051f640 @ 0x0051f640 ====

float10 FUN_0051f640(void)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  float10 extraout_ST0;
  float10 fVar3;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  if (iVar2 != 0) {
    return (float10)*(float *)(iVar2 + 0x34) + (float10)DAT_0099d080;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pState____NULL_009b7494,0xe);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    fVar3 = (float10)(*pcVar1)();
    return fVar3;
  }
  _free(pvStack_18);
  return extraout_ST0;
}


// ==== FUN_0051f6b0 @ 0x0051f6b0 ====

void FUN_0051f6b0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = *param_1;
  return;
}


// ==== FUN_0051f6c0 @ 0x0051f6c0 ====

void FUN_0051f6c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b74bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0051f6e0 @ 0x0051f6e0 ====

int FUN_0051f6e0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00981880;
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


// ==== Catch@0051f746 @ 0x0051f746 ====

void Catch_0051f746(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0051f750 @ 0x0051f750 ====

void * FUN_0051f750(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981890;
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


// ==== Catch@0051f7bd @ 0x0051f7bd ====

void Catch_0051f7bd(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0051f7e0 @ 0x0051f7e0 ====

undefined1 FUN_0051f7e0(undefined4 *param_1,undefined4 *param_2,undefined1 param_3)

{
  for (; param_1 != param_2; param_1 = (undefined4 *)*param_1) {
    if ((undefined4 *)param_1[3] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[3])(1);
    }
  }
  return param_3;
}


// ==== FUN_0051f810 @ 0x0051f810 ====

void FUN_0051f810(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_0051f6e0(param_1,param_2,param_3);
  return;
}


// ==== FUN_0051f830 @ 0x0051f830 ====

void FUN_0051f830(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = **(undefined4 **)(in_ECX + 0x10);
  return;
}


// ==== FUN_0051f840 @ 0x0051f840 ====

void FUN_0051f840(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x10);
  return;
}


// ==== FUN_0051f850 @ 0x0051f850 ====

undefined4 FUN_0051f850(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x14) == 0) {
    return 0;
  }
  iVar1 = **(int **)(in_ECX + 0x10);
  *(int *)(in_ECX + 4) = iVar1;
  return *(undefined4 *)(iVar1 + 0xc);
}


// ==== FUN_0051f870 @ 0x0051f870 ====

undefined4 FUN_0051f870(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 4) != *(int **)(in_ECX + 0x10)) {
    iVar1 = **(int **)(in_ECX + 4);
    *(int *)(in_ECX + 4) = iVar1;
    if (iVar1 != *(int *)(in_ECX + 0x10)) {
      return *(undefined4 *)(iVar1 + 0xc);
    }
  }
  return 0;
}


// ==== FUN_0051f890 @ 0x0051f890 ====

void FUN_0051f890(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 != *(int *)(in_ECX + 0x10)) {
    if (*(undefined4 **)(local_4 + 0xc) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(local_4 + 0xc))(1);
    }
    FUN_00598f60(&param_1,local_4);
    *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0x10);
  }
  return;
}


// ==== FUN_0051f8e0 @ 0x0051f8e0 ====

undefined4 FUN_0051f8e0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_00897340(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x10)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0xc);
}


// ==== FUN_0051f910 @ 0x0051f910 ====

void FUN_0051f910(int *param_1)

{
  int in_ECX;
  undefined4 uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [8];
  
  uStack_10 = (**(code **)(*param_1 + 0x18))();
  piStack_c = param_1;
  FUN_0051fcd0(auStack_8,&uStack_10);
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0x10);
  return;
}


// ==== FUN_0051f950 @ 0x0051f950 ====

void FUN_0051f950(void)

{
  undefined4 *in_ECX;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b679c;
  in_ECX[1] = in_ECX[4];
  if (in_ECX[5] != 0) {
    local_4 = (uint)in_ECX & 0xffffff00;
    FUN_0051f7e0(*(undefined4 *)in_ECX[4],(undefined4 *)in_ECX[4],local_4);
    FUN_0051ff00();
  }
  if ((void *)in_ECX[7] == (void *)0x0) {
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    FUN_008984a0();
    *in_ECX = &PTR_FUN_009b6778;
    FUN_00513d60();
    return;
  }
  _free((void *)in_ECX[7]);
  return;
}


// ==== FUN_0051f9c0 @ 0x0051f9c0 ====

void FUN_0051f9c0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_009818a0;
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
      uVar5 = FUN_0051f810(*(undefined4 *)(in_ECX + 4),param_1,pvVar4);
      uVar5 = FUN_00513cc0(uVar5,param_2,&local_18);
      FUN_0051f810(param_1,*(undefined4 *)(in_ECX + 8),uVar5);
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
      FUN_0051f6e0(param_1,iVar3,uVar7 * 4 + param_1);
      local_8 = 2;
      FUN_00513cc0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 2),&local_18);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar7 * 4;
      FUN_008335f0(param_1,*(int *)(in_ECX + 8) + uVar7 * -4,&local_18);
      ExceptionList = local_10;
      return;
    }
    iVar6 = iVar3 + uVar7 * -4;
    uVar5 = FUN_0051f6e0(iVar6,iVar3,iVar3);
    *(undefined4 *)(in_ECX + 8) = uVar5;
    FUN_0056bf90(param_1,iVar6,iVar3);
    FUN_008335f0(param_1,uVar7 * 4 + param_1,&local_18);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0051fb21 @ 0x0051fb21 ====

void Catch_0051fb21(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_0051fc10 @ 0x0051fc10 ====

void FUN_0051fc10(uint param_1,undefined1 param_2)

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
    FUN_0051f9c0(*(undefined4 *)(in_ECX + 8),param_1 - iVar2,&param_2);
    return;
  }
  if ((iVar2 != 0) && (param_1 < (uint)(*(int *)(in_ECX + 8) - iVar2 >> 2))) {
    FUN_004c7880(&param_1,iVar2 + param_1 * 4,*(int *)(in_ECX + 8));
  }
  return;
}


// ==== FUN_0051fc80 @ 0x0051fc80 ====

/* WARNING: Removing unreachable block (ram,0x0051fc9b) */
/* WARNING: Removing unreachable block (ram,0x0051fca0) */
/* WARNING: Removing unreachable block (ram,0x0051fcae) */

void FUN_0051fc80(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  param_2 = (undefined4 *)*param_2;
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 4);
  }
  FUN_0051f9c0(*(undefined4 *)(in_ECX + 4),param_1,&param_2);
  return;
}


// ==== FUN_0051fcd0 @ 0x0051fcd0 ====

/* WARNING: Removing unreachable block (ram,0x0051fdb8) */

void FUN_0051fcd0(int *param_1,uint *param_2)

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
      FUN_0051fc10(iVar3 * 2 + -1,*(undefined4 *)(in_ECX + 8));
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
  iVar5 = FUN_0051f750(puVar7,puVar7[1],param_2);
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


// ==== FUN_0051ff00 @ 0x0051ff00 ====

void FUN_0051ff00(void)

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
    FUN_0051fc80(9,&local_4);
    *(undefined4 *)(in_ECX + 0x20) = 1;
    *(undefined4 *)(in_ECX + 0x24) = 1;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0051ff60 @ 0x0051ff60 ====

void FUN_0051ff60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b75d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0051ff80 @ 0x0051ff80 ====

bool FUN_0051ff80(uint param_1)

{
  int in_ECX;
  
  return param_1 <= *(uint *)(in_ECX + 0x28);
}


// ==== FUN_0051ff90 @ 0x0051ff90 ====

undefined4 FUN_0051ff90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0051ffc0 @ 0x0051ffc0 ====

void FUN_0051ffc0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b75e4;
  if (in_ECX[0xb] == 0) {
    (**(code **)(*DAT_00b5af38 + 8))(in_ECX[1]);
    piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    (**(code **)(*piVar1 + 8))(s___Model2_Holder_Effect_cpp_009b7578,0x22,2,in_ECX[1]);
    (**(code **)(*DAT_00b5ac6c + 0x18))(in_ECX[1]);
    *in_ECX = &PTR_FUN_009b75d4;
    return;
  }
  (**(code **)(*DAT_00b5ac6c + 0x14))(in_ECX[1],in_ECX[2]);
  *in_ECX = &PTR_FUN_009b75d4;
  return;
}


