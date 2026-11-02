// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x540000-0x54ffff

// ==== FUN_005400a0 @ 0x005400a0 ====

undefined4 FUN_005400a0(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  undefined1 auStack_26 [10];
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
  if (iVar2 != 0) {
    piVar4 = (int *)(**(code **)(*DAT_00b5a780 + 8))(iVar2 + 0x14);
    if (piVar4 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar4 + 0xc))(auStack_26 + -6);
      if (iVar2 != 0) {
        return *(undefined4 *)(iVar2 + 300);
      }
    }
    return 0;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pRemoteDoll____NULL_009ba59c,0x13);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_18);
  return extraout_EAX;
}


// ==== FUN_00540150 @ 0x00540150 ====

void FUN_00540150(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  void *unaff_ESI;
  undefined4 uStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_38 [16];
  void *apvStack_28 [3];
  void *apvStack_1c [2];
  uint uStack_14;
  undefined4 uStack_c;
  uint uStack_8;
  
  if ((*(int **)(in_ECX + 4) == (int *)0x0) || (param_1 == *(int *)(in_ECX + 0x18))) {
    return;
  }
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  uVar2 = (**(code **)(*piVar1 + 8))();
  if (param_1 == 1) {
    FUN_005400a0(0x18);
    FUN_00401830(s__BRICK__Open_009ba3e8);
    FUN_00403e50(apvStack_1c);
  }
  else if (param_1 == 2) {
    FUN_005400a0(0x19);
    FUN_00401830(s__BRICK__Close_009ba3f8);
    FUN_00403e50(auStack_38);
  }
  else {
    if (param_1 != 3) {
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
      (**(code **)(*piVar1 + 0x40))(apvStack_1c);
      FUN_00401740(s__BRICK__Effect__s__d__d__d_009ba418,0x1a);
      uVar3 = FUN_00404230(auStack_38 + -0x20);
      FUN_00403e50(uVar3);
      if (0xf < uStack_40) {
        _free(uStack_54);
        return;
      }
      uStack_40 = 0xf;
      uStack_44 = 0;
      uStack_54 = (void *)((uint)uStack_54 & 0xffffff00);
      if (0xf < uStack_8) {
        _free(apvStack_1c[0]);
        return;
      }
      (**(code **)(*DAT_00b5ac70 + 0x20))(uVar2,*(undefined4 *)(in_ECX + 8));
      uVar2 = FUN_004dd240(0x23,5,5,0,uVar2);
      *(undefined4 *)(in_ECX + 8) = uVar2;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
      (**(code **)(*piVar1 + 0x40))(apvStack_28);
      FUN_00401740(s__BRICK__New_Effect__s__d__d__d_009ba434,0x1e);
      uVar2 = FUN_00404230(auStack_38 + -0x2c);
      FUN_00403e50(uVar2);
      if (0xf < uStack_4c) {
        _free(unaff_ESI);
        return;
      }
      uStack_4c = 0xf;
      uStack_50 = 0;
      if (uStack_14 < 0x10) {
        *(undefined4 *)(in_ECX + 0x18) = uStack_c;
        return;
      }
      _free(apvStack_28[0]);
      return;
    }
    FUN_005400a0(8);
    FUN_00401830(s__BRICK__Dead_009ba408);
    FUN_00403e50(&uStack_54);
  }
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00540380 @ 0x00540380 ====

undefined4 FUN_00540380(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  int *piVar4;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  int in_ECX;
  undefined2 in_FPUControlWord;
  float10 fVar5;
  int *unaff_retaddr;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uStack_64;
  int iStack_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  void *pvStack_38;
  void *pvStack_34;
  undefined4 uStack_28;
  uint uStack_24;
  uint uStack_20;
  void *apvStack_1c [5];
  uint uStack_8;
  
  FUN_004f5730(&local_58);
  local_4c = local_58;
  local_3c = 0;
  local_44 = 0;
  local_40 = 0x19;
  local_48 = local_54;
  FUN_0040d600(&local_58,local_50);
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
  if (iVar2 == 0) {
    uStack_20 = 0xf;
    uStack_24 = 0;
    pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
    FUN_00401740(s_pRemoteDoll____NULL_009ba454,0x13);
    FUN_00406880(&pvStack_38);
    if (uStack_20 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_34);
    return extraout_EAX;
  }
  uVar3 = 0;
  puVar6 = &local_58;
  puVar8 = &local_4c;
  FUN_00511d20(puVar8,puVar6,0);
  FUN_005118f0(puVar8,puVar6,uVar3);
  fVar5 = (float10)FUN_0053fff0(0x19);
  iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uStack_64 = CONCAT22(in_FPUControlWord,(undefined2)uStack_64);
  iStack_5c = (int)ROUND((float)fVar5 * DAT_009b012c);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  (**(code **)(*piVar4 + 0x40))(apvStack_1c);
  FUN_00401740(s________Brick_Name____s_Close_ani_009ba468,0x29);
  puVar6 = &local_3c;
  uVar3 = FUN_00404230(puVar6);
  FUN_00403e50(uVar3);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return extraout_EAX_00;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return extraout_EAX_01;
  }
  if ((uint)(float)fVar5 < (uint)(iVar2 - *unaff_retaddr)) {
    uVar7 = (uint)puVar6 & 0xffffff00;
    FUN_00401740(&DAT_009ba498,0x4d);
    uVar3 = FUN_00404230(&uStack_20,uVar3,uVar7);
    FUN_00796d50(uVar3);
    if (0xf < uStack_8) {
      _free(apvStack_1c[0]);
      return extraout_EAX_02;
    }
    uVar10 = 0;
    uVar9 = 0;
    piVar4 = &iStack_5c;
    puVar6 = &local_48;
    uVar3 = uStack_64;
    FUN_00511d20(puVar6,piVar4,uStack_64,uStack_64,0,0);
    FUN_00511b10(puVar6,piVar4,uStack_64,uVar3,uVar9,uVar10);
  }
  else {
    uVar9 = 0;
    uVar3 = 0;
    piVar4 = &iStack_5c;
    puVar6 = &local_48;
    FUN_00511d20(puVar6,piVar4,uStack_64,0,0);
    FUN_00511c00(puVar6,piVar4,uStack_64,uVar3,uVar9);
  }
  if ((*(int **)(in_ECX + 4) != (int *)0x0) && (*(int *)(in_ECX + 0x18) != 2)) {
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    (**(code **)(*piVar4 + 8))();
    FUN_005400a0(0x19);
    FUN_00401830(s__BRICK__Close_009ba3f8);
    FUN_00403e50(&uStack_20);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return 1;
}


// ==== FUN_00540760 @ 0x00540760 ====

undefined4 FUN_00540760(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 extraout_EAX_00;
  uint uVar4;
  int *piVar5;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  int in_ECX;
  undefined2 in_FPUControlWord;
  float10 fVar6;
  uint *unaff_retaddr;
  undefined4 *puVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined4 uStack_6c;
  int iStack_64;
  undefined1 auStack_60 [8];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  void *pvStack_38;
  void *pvStack_34;
  undefined4 uStack_28;
  uint uStack_24;
  uint uStack_20;
  void *apvStack_1c [5];
  uint uStack_8;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
  if (iVar2 == 0) {
    uStack_20 = 0xf;
    uStack_24 = 0;
    pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
    FUN_00401740(s_pRemoteDoll____NULL_009ba4e8,0x13);
    FUN_00406880(&pvStack_38);
    if (uStack_20 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_34);
    return extraout_EAX;
  }
  FUN_00511ea0(0);
  FUN_0052fd10(0);
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))
                    (0,&Framework::ModelCenter::Actors::Info::IActorInfo::RTTI_Type_Descriptor,
                     &Framework::ModelCenter::Actors::Info::Brick::RTTI_Type_Descriptor,0);
  iVar2 = FUN_00803725(uVar3);
  if (iVar2 == 0) {
    uStack_20 = 0xf;
    uStack_24 = 0;
    pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
    FUN_00401740(s_pInfo____NULL_009ba4fc,0xd);
    FUN_00406880(&pvStack_38);
    if (uStack_20 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_34);
    return extraout_EAX_00;
  }
  FUN_004f5730(&uStack_44);
  uStack_58 = uStack_44;
  uStack_48 = 0;
  uStack_50 = 0;
  uStack_4c = 8;
  uStack_54 = uStack_40;
  FUN_0040d600(auStack_60,uStack_3c);
  uVar3 = 0;
  puVar9 = auStack_60;
  puVar7 = &uStack_58;
  FUN_00511d20(puVar7,puVar9,0);
  FUN_005118f0(puVar7,puVar9,uVar3);
  fVar6 = (float10)FUN_0053fff0(8);
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uStack_6c = CONCAT22(in_FPUControlWord,(undefined2)uStack_6c);
  iStack_64 = (int)ROUND((float)fVar6 * DAT_009b012c);
  piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  (**(code **)(*piVar5 + 0x40))(apvStack_1c);
  FUN_00401740(s________Brick_Name____s_Dead_anim_009ba50c,0x28);
  puVar7 = &uStack_3c;
  uVar3 = FUN_00404230(puVar7);
  FUN_00403e50(uVar3);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return extraout_EAX_01;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return extraout_EAX_02;
  }
  if ((*unaff_retaddr < uVar4) && ((uint)(float)fVar6 < uVar4 - *unaff_retaddr)) {
    uVar4 = (uint)puVar7 & 0xffffff00;
    FUN_00401740(&DAT_009ba538,0x4c);
    uVar3 = FUN_00404230(&uStack_20,uVar3,uVar4);
    FUN_00796d50(uVar3);
    if (0xf < uStack_8) {
      _free(apvStack_1c[0]);
      return extraout_EAX_03;
    }
    uVar10 = 0;
    uVar8 = 0;
    piVar5 = &iStack_64;
    puVar7 = &uStack_54;
    uVar3 = uStack_6c;
    FUN_00511d20(puVar7,piVar5,uStack_6c,uStack_6c,0,0);
    FUN_00511b10(puVar7,piVar5,uStack_6c,uVar3,uVar8,uVar10);
  }
  else {
    uVar8 = 0;
    uVar3 = 0;
    piVar5 = &iStack_64;
    puVar7 = &uStack_54;
    FUN_00511d20(puVar7,piVar5,uStack_6c,0,0);
    FUN_00511c00(puVar7,piVar5,uStack_6c,uVar3,uVar8);
  }
  if ((*(int **)(in_ECX + 4) != (int *)0x0) && (*(int *)(in_ECX + 0x18) != 3)) {
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    (**(code **)(*piVar5 + 8))();
    FUN_005400a0(8);
    FUN_00401830(s__BRICK__Dead_009ba408);
    FUN_00403e50(&uStack_20);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return 1;
}


// ==== FUN_00540bc0 @ 0x00540bc0 ====

undefined4 FUN_00540bc0(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  int *piVar4;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  void *pvStack_38;
  void *pvStack_34;
  undefined4 uStack_28;
  uint uStack_24;
  uint uStack_20;
  void *apvStack_1c [5];
  uint uStack_8;
  
  FUN_004f5730(&local_50);
  local_58 = local_50;
  local_3c = 0;
  local_44 = 0;
  local_40 = 0x18;
  local_54 = local_4c;
  FUN_0040d600(&local_50,local_48);
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
  if (iVar2 == 0) {
    uStack_20 = 0xf;
    uStack_24 = 0;
    pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
    FUN_00401740(s_pRemoteDoll____NULL_009ba3a8,0x13);
    FUN_00406880(&pvStack_38);
    if (uStack_20 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
    _free(pvStack_34);
    return extraout_EAX;
  }
  uVar3 = 0;
  puVar6 = &local_50;
  puVar5 = &local_58;
  FUN_00511d20(puVar5,puVar6,0);
  FUN_005118f0(puVar5,puVar6,uVar3);
  FUN_00511ea0(0);
  FUN_0052fd10(0);
  FUN_0053fff0(0x18);
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  (**(code **)(*piVar4 + 0x40))(apvStack_1c);
  FUN_00401740(s________Brick_Name____s_open_anim_009ba3bc,0x28);
  uVar3 = FUN_00404230(&local_3c);
  FUN_00403e50(uVar3);
  if (0xf < uStack_24) {
    _free(pvStack_38);
    return extraout_EAX_00;
  }
  uStack_24 = 0xf;
  uStack_28 = 0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  if (0xf < uStack_8) {
    _free(apvStack_1c[0]);
    return extraout_EAX_01;
  }
  uVar7 = 0;
  uVar3 = 0;
  puVar6 = &local_54;
  puVar5 = &local_48;
  FUN_00511d20(puVar5,puVar6,unaff_retaddr,0,0);
  FUN_00511c00(puVar5,puVar6,unaff_retaddr,uVar3,uVar7);
  if ((*(int **)(in_ECX + 4) != (int *)0x0) && (*(int *)(in_ECX + 0x18) != 1)) {
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    (**(code **)(*piVar4 + 8))();
    FUN_005400a0(0x18);
    FUN_00401830(s__BRICK__Open_009ba3e8);
    FUN_00403e50(&uStack_20);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return 1;
}


// ==== FUN_00540f00 @ 0x00540f00 ====

uint FUN_00540f00(uint *param_1)

{
  char cVar1;
  uint in_EAX;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int in_ECX;
  
  cVar1 = *(char *)((int)param_1 + 0xb);
  if (((cVar1 == '\x18') || (cVar1 == '\x19')) || (cVar1 == '\b')) {
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))
                      (0,&Framework::ModelCenter::Actors::Info::IActorInfo::RTTI_Type_Descriptor,
                       &Framework::ModelCenter::Actors::Info::Brick::RTTI_Type_Descriptor,0);
    piVar3 = (int *)FUN_00803725(uVar2);
    uVar2 = (**(code **)(*piVar3 + 0x24))
                      (0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IBrick::RTTI_Type_Descriptor,0);
    iVar4 = FUN_00803725(uVar2);
    if (*(int **)(iVar4 + 0x4c) == (int *)0x0) {
      piVar3 = (int *)0x0;
    }
    else {
      piVar3 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
    }
    (**(code **)(*piVar3 + 0x24))(param_1);
    if (cVar1 == '\b') {
      uVar5 = FUN_00540760(param_1);
      return uVar5;
    }
    if (cVar1 == '\x18') {
      uVar5 = FUN_00540bc0(param_1);
      return uVar5;
    }
    if (cVar1 == '\x19') {
      uVar5 = FUN_00540380(param_1);
      return uVar5;
    }
    in_EAX = *param_1;
    *(uint *)(in_ECX + 0xc) = in_EAX;
    *(uint *)(in_ECX + 0x10) = param_1[1];
    *(uint *)(in_ECX + 0x14) = param_1[2];
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00540fd0 @ 0x00540fd0 ====

void FUN_00540fd0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  uint unaff_EBX;
  
  *in_ECX = &PTR_FUN_009ba5d4;
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
  iVar1 = *DAT_00b5ac6c;
  uVar3 = (**(code **)(*piVar2 + 8))(in_ECX[2]);
  (**(code **)(iVar1 + 0x14))(uVar3);
  in_ECX[1] = 0;
  if ((unaff_EBX & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00541020 @ 0x00541020 ====

undefined4 FUN_00541020(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00541030 @ 0x00541030 ====

void FUN_00541030(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_00541050 @ 0x00541050 ====

undefined4 FUN_00541050(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00541060 @ 0x00541060 ====

undefined4 FUN_00541060(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00541080 @ 0x00541080 ====

void FUN_00541080(int param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))(*(undefined4 *)(param_1 + 0xac));
  in_ECX[4] = param_1;
  (**(code **)(*in_ECX + 0x28))(param_1);
  return;
}


// ==== FUN_005410b0 @ 0x005410b0 ====

void FUN_005410b0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  float unaff_retaddr;
  
  iVar3 = **(int **)(*(int *)(in_ECX + 0x10) + 0x50);
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar2 = (int *)(**(code **)(iVar3 + 0x14))(uVar1);
  iVar3 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x24))();
  piVar5 = *(int **)(*(int *)(in_ECX + 0x10) + 0x44);
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(*piVar5 + 0x18))();
  }
  iVar4 = (**(code **)(*piVar5 + 0xc))();
  if (*(float *)(iVar4 + 4) != DAT_0099cdc8) {
    iVar4 = (**(code **)(*piVar2 + 8))();
    iVar4 = (int)(unaff_retaddr * DAT_0099d0b4 + *(float *)(iVar4 + 0xc));
    if (*(int *)(iVar3 + 0x2c) < iVar4) {
      iVar4 = *(int *)(iVar3 + 0x2c);
    }
    (**(code **)(*piVar5 + 0x14))((float)iVar4);
  }
  return;
}


// ==== FUN_00541150 @ 0x00541150 ====

void FUN_00541150(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba82c;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  FUN_00538640();
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00541180 @ 0x00541180 ====

int FUN_00541180(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int extraout_EAX;
  int in_ECX;
  char *pcVar4;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x20))();
  if (piVar2 == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(s_Brick_009ba628,5);
    return param_1;
  }
  iVar3 = (**(code **)(*piVar2 + 4))();
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  pcVar4 = (char *)(iVar3 + 2);
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar3 + 2),(int)pcVar4 - (iVar3 + 3));
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(auStack_1c,0,0xffffffff);
  if (uStack_4 < 0x10) {
    return param_1;
  }
  _free(pvStack_18);
  return extraout_EAX;
}


// ==== FUN_00541240 @ 0x00541240 ====

undefined4 FUN_00541240(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x20))();
  if (piVar2 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar2 + 4))();
    return *(undefined4 *)(iVar4 + 0x20);
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pFlyweight____NULL_009ba630,0x12);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_18);
  return extraout_EAX;
}


// ==== FUN_005412b0 @ 0x005412b0 ====

void FUN_005412b0(void)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *in_ECX;
  undefined1 auStack_1e0 [4];
  void *pvStack_1dc;
  int *piStack_1cc;
  uint uStack_1c8;
  int iStack_1a8;
  char cStack_4;
  
  piStack_1cc = (int *)(**(code **)(*(int *)in_ECX[4] + 0x20))();
  if (piStack_1cc != (int *)0x0) {
    uVar2 = (**(code **)(*piStack_1cc + 4))();
    FUN_00541dc0(uVar2);
    if (cStack_4 == '\0') {
      puVar3 = operator_new(8);
      if (iStack_1a8 == 2) {
        if (puVar3 == (undefined4 *)0x0) {
          uRam00000004 = (**(code **)(*in_ECX + 8))();
          FUN_00797a20(0);
          return;
        }
        *puVar3 = &PTR_FUN_009ba7ec;
        uVar2 = (**(code **)(*in_ECX + 8))();
        puVar3[1] = uVar2;
        FUN_00797a20(puVar3);
        return;
      }
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        *puVar3 = &PTR_FUN_009b7950;
      }
      puVar3[1] = in_ECX[3];
      FUN_00797a20(puVar3);
    }
    return;
  }
  uStack_1c8 = 0xf;
  pvStack_1dc = (void *)((uint)pvStack_1dc & 0xffffff00);
  FUN_00401740(s_pFlyweight____NULL_009ba644,0x12);
  FUN_00406880(auStack_1e0);
  if (uStack_1c8 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_1dc);
  return;
}


// ==== FUN_005413b0 @ 0x005413b0 ====

void FUN_005413b0(char param_1)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *in_ECX;
  undefined4 uStack_1ec;
  int iStack_1e8;
  undefined1 auStack_1e0 [4];
  void *pvStack_1dc;
  undefined4 uStack_1cc;
  uint uStack_1c8;
  int iStack_1a8;
  char cStack_4;
  
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[4] + 0x20))();
  if (piVar2 == (int *)0x0) {
    uStack_1c8 = 0xf;
    uStack_1cc = 0;
    pvStack_1dc = (void *)((uint)pvStack_1dc & 0xffffff00);
    FUN_00401740(s_pFlyweight____NULL_009ba7ac,0x12);
    FUN_00406880(auStack_1e0);
    if (uStack_1c8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_1dc);
    return;
  }
  uVar3 = (**(code **)(*piVar2 + 4))();
  FUN_00541dc0(uVar3);
  if (cStack_4 == '\0') {
    if (param_1 == '\x01') {
      if (iStack_1a8 == 2) {
        if ((char)in_ECX[5] != '\x01') {
          puVar4 = operator_new(0xc);
          if (puVar4 == (undefined4 *)0x0) {
            puVar4 = (undefined4 *)0x0;
          }
          else {
            *puVar4 = &PTR_FUN_009ba800;
          }
          uVar3 = (**(code **)(*in_ECX + 8))();
          puVar4[1] = uVar3;
          *(undefined1 *)(puVar4 + 2) = 1;
          FUN_00797a20(puVar4);
          *(undefined1 *)(in_ECX + 5) = 1;
          return;
        }
      }
      else if ((char)in_ECX[5] != '\x01') {
        puVar4 = operator_new(0x10);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          *puVar4 = &PTR_FUN_009b7964;
          puVar4[3] = 0;
          *(undefined1 *)(puVar4 + 2) = 1;
        }
        uVar3 = (**(code **)(*in_ECX + 8))();
        puVar4[1] = uStack_1ec;
        iStack_1e8 = CONCAT31(iStack_1e8._1_3_,1);
        puVar4[2] = iStack_1e8;
        puVar4[3] = uVar3;
        FUN_00797a20(puVar4);
        *(undefined1 *)(in_ECX + 5) = 1;
        return;
      }
    }
    else {
      if (iStack_1a8 == 2) {
        if ((char)in_ECX[5] == '\0') {
          return;
        }
        puVar4 = operator_new(0xc);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
          uRam00000004 = (**(code **)(*in_ECX + 8))();
          uRam00000008 = 0;
        }
        else {
          *puVar4 = &PTR_FUN_009ba800;
          uVar3 = (**(code **)(*in_ECX + 8))();
          puVar4[1] = uVar3;
          *(undefined1 *)(puVar4 + 2) = 0;
        }
      }
      else {
        if ((char)in_ECX[5] == '\0') {
          return;
        }
        puVar4 = operator_new(0x10);
        if (puVar4 == (undefined4 *)0x0) {
          puVar4 = (undefined4 *)0x0;
        }
        else {
          *puVar4 = &PTR_FUN_009b7964;
          puVar4[3] = 0;
          *(undefined1 *)(puVar4 + 2) = 1;
        }
        uVar3 = (**(code **)(*in_ECX + 8))();
        puVar4[1] = uStack_1ec;
        iStack_1e8 = (uint)iStack_1e8._1_3_ << 8;
        puVar4[2] = iStack_1e8;
        puVar4[3] = uVar3;
      }
      FUN_00797a20(puVar4);
      *(undefined1 *)(in_ECX + 5) = 0;
    }
  }
  return;
}


// ==== FUN_00541590 @ 0x00541590 ====

undefined4 FUN_00541590(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined4 uStack_1c;
  uint uStack_8;
  
  piVar1 = *(int **)(*(int *)(in_ECX + 0x10) + 0x44);
  piVar3 = (int *)(**(code **)(*piVar1 + 0x18))();
  iVar2 = *piVar1;
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar2 + 0x1c))(uVar4);
  FUN_00401740(s_Update_Brick_HP____f_009ba7c0,0x15);
  uVar4 = FUN_00404230((int)register0x00000010 + -0x20);
  FUN_00403e50(uVar4);
  if (uStack_8 < 0x10) {
    (**(code **)(*piVar3 + 0x14))();
    return 1;
  }
  _free(uStack_1c);
  return extraout_EAX;
}


// ==== FUN_00541620 @ 0x00541620 ====

void FUN_00541620(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    FUN_005412b0();
    *(undefined1 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_00541640 @ 0x00541640 ====

void FUN_00541640(void)

{
  code *pcVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  void *pvVar5;
  int iVar6;
  int *in_ECX;
  void **ppvVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  void *pvStack_210;
  void *pvStack_20c;
  uint uStack_1fc;
  uint uStack_1f8;
  undefined4 uStack_1f4;
  undefined4 uStack_1f0;
  undefined4 uStack_1ec;
  undefined4 uStack_1e8;
  undefined1 auStack_1e4 [4];
  void *pvStack_1e0;
  uint uStack_1cc;
  int iStack_1a8;
  char cStack_4;
  
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[4] + 0x20))();
  if (piVar2 == (int *)0x0) {
    uStack_1f8 = 0xf;
    uStack_1fc = 0;
    pvStack_20c = (void *)((uint)pvStack_20c & 0xffffff00);
    FUN_00401740(s_pFlyweight____NULL_009ba658,0x12);
    FUN_00406880(&pvStack_210);
    if (uStack_1f8 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_20c);
    return;
  }
  uVar3 = (**(code **)(*piVar2 + 4))();
  FUN_00541dc0(uVar3);
  if (cStack_4 == '\0') {
    if (iStack_1a8 == 2) {
      puVar4 = operator_new(0x30);
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        *puVar4 = &PTR_FUN_009ba814;
        FUN_00541f60();
      }
      FUN_00541f60();
      uStack_1f0 = (**(code **)(*in_ECX + 8))();
      uStack_1ec = *(undefined4 *)((int)in_ECX + 0x1a);
      uStack_1e8 = CONCAT22(uStack_1e8._2_2_,*(undefined2 *)((int)in_ECX + 0x1e));
      FUN_00401660(in_ECX + 8,0,0xffffffff);
      uStack_1f4 = CONCAT31(CONCAT21(uStack_1f4._2_2_,(char)in_ECX[6]),1);
      FUN_00542010(&uStack_1f4);
      FUN_00797a20(puVar4);
      uStack_1f8 = 0xf;
      uStack_1fc = 0;
      pvStack_20c = (void *)((uint)pvStack_20c & 0xffffff00);
      FUN_00401740(s_________________ZEOLITE_OPEN_INF_009ba66c,0x38);
      FUN_00403e50(&pvStack_210);
      if (0xf < uStack_1f8) {
        _free(pvStack_20c);
        return;
      }
      (**(code **)(*in_ECX + 8))();
      FUN_00401740(s______________BRICKID____d________009ba6a8,0x2f);
      uVar3 = FUN_00404230(&pvStack_210);
      FUN_00403e50(uVar3);
      if (0xf < uStack_1f8) {
        _free(pvStack_20c);
        return;
      }
      uVar9 = 0;
      FUN_00401740(s______________OWNER_GUILD____s____009ba6d8,0x32);
      ppvVar7 = &pvStack_210;
      uVar3 = FUN_00404230(ppvVar7);
      FUN_00403e50(uVar3);
      if (0xf < uStack_1f8) {
        _free(pvStack_20c);
        return;
      }
      uVar8 = 0;
      FUN_00401740(s______________MARK____d___MARKBG___009ba70c,0x35);
      uVar3 = FUN_00404230(&pvStack_210,ppvVar7,uVar8,uVar9);
      FUN_00403e50(uVar3);
      if (0xf < uStack_1f8) {
        _free(pvStack_20c);
        return;
      }
      uVar9 = 0;
      FUN_00401740(s______________STATE____d__________009ba744,0x2b);
      uVar3 = FUN_00404230(&pvStack_210,uVar8,uVar9);
      FUN_00403e50(uVar3);
      if (0xf < uStack_1f8) {
        _free(pvStack_20c);
        return;
      }
      uStack_1f8 = 0xf;
      uStack_1fc = 0;
      pvStack_20c = (void *)((uint)pvStack_20c & 0xffffff00);
      FUN_00401740(s_________________ZEOLITE_OPEN_INF_009ba770,0x39);
      FUN_00403e50(&pvStack_210);
      if (0xf < uStack_1f8) {
        _free(pvStack_20c);
        return;
      }
      if (0xf < uStack_1cc) {
        _free(pvStack_1e0);
        return;
      }
    }
    else {
      FUN_00522130();
      uStack_1ec = (**(code **)(*in_ECX + 8))();
      uStack_1f4 = 0;
      uVar3 = (**(code **)(*in_ECX + 0x40))(&pvStack_210);
      FUN_00401660(uVar3,0,0xffffffff);
      if (0xf < uStack_1fc) {
        _free(pvStack_210);
        return;
      }
      uStack_1e8 = 0x3a;
      uStack_1ec = 0xffffff00;
      uStack_1f4 = CONCAT31(uStack_1f4._1_3_,1);
      pvVar5 = operator_new(0x34);
      if (pvVar5 == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = FUN_00522170();
      }
      *(uint *)(iVar6 + 4) = uStack_1f8;
      *(undefined1 *)(iVar6 + 8) = (undefined1)uStack_1f4;
      *(undefined4 *)(iVar6 + 0xc) = uStack_1f0;
      *(undefined4 *)(iVar6 + 0x10) = uStack_1ec;
      *(undefined4 *)(iVar6 + 0x14) = uStack_1e8;
      FUN_00401660(auStack_1e4,0,0xffffffff);
      FUN_00797a20(iVar6);
      if (0xf < uStack_1cc) {
        _free(pvStack_1e0);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00541a00 @ 0x00541a00 ====

void FUN_00541a00(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  *in_ECX = &PTR_FUN_009ba82c;
  if (*(char *)(in_ECX + 2) != '\0') {
    FUN_005412b0();
    *(undefined1 *)(in_ECX + 2) = 0;
  }
  if (in_ECX[4] != 0) {
    piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
    if (piVar1 == (int *)0x0) {
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
      FUN_00401740(&DAT_009ba5dc,0xd);
      FUN_00403e50(auStack_1c);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return;
      }
    }
    else {
      (**(code **)(*piVar1 + 0x10))(in_ECX[4]);
    }
    (**(code **)(*DAT_00b5ac8c + 0x10))(1,in_ECX[4]);
    in_ECX[4] = 0;
    in_ECX[3] = 0;
  }
  if ((uint)in_ECX[0xe] < 0x10) {
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0xf;
    *(undefined1 *)(in_ECX + 9) = 0;
    *in_ECX = &PTR_FUN_009b78dc;
    return;
  }
  _free((void *)in_ECX[9]);
  return;
}


// ==== FUN_00541ac0 @ 0x00541ac0 ====

void FUN_00541ac0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\x01') {
    FUN_00541640();
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_00541ae0 @ 0x00541ae0 ====

/* WARNING: Removing unreachable block (ram,0x00541cf6) */

void FUN_00541ae0(int *param_1)

{
  char cVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  void *in_ECX;
  char *pcVar6;
  undefined1 *puVar7;
  undefined1 auStack_8e [6];
  undefined1 auStack_88 [4];
  void *pvStack_84;
  undefined1 local_80 [4];
  void *local_7c;
  undefined4 uStack_74;
  uint uStack_70;
  int *local_6c;
  uint local_68;
  void *local_64;
  undefined1 auStack_60 [4];
  undefined1 uStack_5c;
  uint uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  void *pvStack_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  if (param_1 == (int *)0x0) {
    local_68 = 0xf;
    local_6c = (int *)0x0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    FUN_00401740(s_i_pRemoteDoll____NULL_009ba5ec,0x15);
    FUN_00406880(local_80);
    if (local_68 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_7c);
    return;
  }
  local_64 = in_ECX;
  piVar3 = (int *)(**(code **)(**(int **)((int)in_ECX + 0x10) + 0x20))();
  if (piVar3 == (int *)0x0) {
    local_68 = 0xf;
    local_6c = (int *)0x0;
    local_7c = (void *)((uint)local_7c & 0xffffff00);
    FUN_00401740(s_pFlyweight____NULL_009ba604,0x12);
    FUN_00406880(local_80);
    if (local_68 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_7c);
    return;
  }
  iVar4 = (**(code **)(*piVar3 + 4))();
  uStack_48 = 0xf;
  uStack_4c = 0;
  uStack_5c = 0;
  pcVar6 = (char *)(iVar4 + 0x4c);
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar4 + 0x4c),(int)pcVar6 - (iVar4 + 0x4d));
  iVar4 = (**(code **)(*DAT_00b5a6dc + 0x1c))(4,auStack_60);
  if (iVar4 == 0) {
    uStack_70 = 0xf;
    uStack_74 = 0;
    pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
    FUN_00401740(s_pShape____NULL_009ba618,0xe);
    FUN_00406880(auStack_88);
    if (uStack_70 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_84);
    return;
  }
  (**(code **)(*param_1 + 0xc))();
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  uStack_4c = 0;
  uStack_44 = DAT_0099d080;
  uStack_48 = 0xffffffff;
  FUN_00401660(iVar4,0,0xffffffff);
  FUN_00401660(iVar4 + 0x1c,0,0xffffffff);
  FUN_004ff800(&uStack_4c);
  if (*(short *)(iVar4 + 0x38) != 0) {
    uVar5 = (**(code **)(*local_6c + 8))();
    FUN_004dd240(0x23,5,1,*(undefined2 *)(iVar4 + 0x38),uVar5);
  }
  puVar7 = auStack_8e + -10;
  FUN_00511d10(puVar7);
  FUN_00512cd0();
  FUN_00512a20(puVar7);
  (**(code **)(*param_1 + 0x10))();
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  uStack_c = 0xf;
  uStack_10 = 0;
  pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
  if (0xf < uStack_28) {
    _free(pvStack_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  if (uStack_50 < 0x10) {
    return;
  }
  _free(local_64);
  return;
}


// ==== FUN_00541da0 @ 0x00541da0 ====

undefined4 FUN_00541da0(void)

{
  return 0x70910018;
}


// ==== FUN_00541db0 @ 0x00541db0 ====

undefined4 FUN_00541db0(void)

{
  return 0x70910019;
}


// ==== FUN_00541dc0 @ 0x00541dc0 ====

void FUN_00541dc0(undefined2 *param_1)

{
  undefined2 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *in_ECX = *param_1;
  puVar2 = (undefined4 *)(param_1 + 1);
  puVar3 = (undefined4 *)(in_ECX + 1);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
  *(undefined4 *)(in_ECX + 0xe) = *(undefined4 *)(param_1 + 0xe);
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(param_1 + 0x10);
  *(undefined4 *)(in_ECX + 0x12) = *(undefined4 *)(param_1 + 0x12);
  in_ECX[0x14] = param_1[0x14];
  *(undefined4 *)(in_ECX + 0x16) = *(undefined4 *)(param_1 + 0x16);
  *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(param_1 + 0x18);
  in_ECX[0x1a] = param_1[0x1a];
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined1 *)(in_ECX + 0x1e) = *(undefined1 *)(param_1 + 0x1e);
  *(undefined1 *)((int)in_ECX + 0x3d) = *(undefined1 *)((int)param_1 + 0x3d);
  *(undefined4 *)(in_ECX + 0x1f) = *(undefined4 *)(param_1 + 0x1f);
  *(undefined1 *)(in_ECX + 0x21) = *(undefined1 *)(param_1 + 0x21);
  *(undefined1 *)((int)in_ECX + 0x43) = *(undefined1 *)((int)param_1 + 0x43);
  *(undefined1 *)(in_ECX + 0x22) = *(undefined1 *)(param_1 + 0x22);
  *(undefined1 *)((int)in_ECX + 0x45) = *(undefined1 *)((int)param_1 + 0x45);
  *(undefined1 *)(in_ECX + 0x23) = *(undefined1 *)(param_1 + 0x23);
  *(undefined1 *)((int)in_ECX + 0x47) = *(undefined1 *)((int)param_1 + 0x47);
  *(undefined1 *)(in_ECX + 0x24) = *(undefined1 *)(param_1 + 0x24);
  *(undefined1 *)((int)in_ECX + 0x49) = *(undefined1 *)((int)param_1 + 0x49);
  *(undefined1 *)(in_ECX + 0x25) = *(undefined1 *)(param_1 + 0x25);
  *(undefined1 *)((int)in_ECX + 0x4b) = *(undefined1 *)((int)param_1 + 0x4b);
  puVar2 = (undefined4 *)(param_1 + 0x26);
  puVar3 = (undefined4 *)(in_ECX + 0x26);
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  puVar2 = (undefined4 *)(param_1 + 0x66);
  puVar3 = (undefined4 *)(in_ECX + 0x66);
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined1 *)puVar3 = *(undefined1 *)puVar2;
  *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(param_1 + 0x74);
  *(undefined4 *)(in_ECX + 0x76) = *(undefined4 *)(param_1 + 0x76);
  *(undefined4 *)(in_ECX + 0x78) = *(undefined4 *)(param_1 + 0x78);
  *(undefined4 *)(in_ECX + 0x7a) = *(undefined4 *)(param_1 + 0x7a);
  in_ECX[0x7c] = param_1[0x7c];
  *(undefined ***)(in_ECX + 0x7e) = &PTR_FUN_009a6c24;
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(param_1 + 0x80);
  *(undefined4 *)(in_ECX + 0x82) = *(undefined4 *)(param_1 + 0x82);
  in_ECX[0x84] = param_1[0x84];
  puVar2 = (undefined4 *)(param_1 + 0x86);
  puVar3 = (undefined4 *)(in_ECX + 0x86);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  in_ECX[0x9e] = param_1[0x9e];
  puVar2 = (undefined4 *)(param_1 + 0xa0);
  puVar3 = (undefined4 *)(in_ECX + 0xa0);
  for (iVar1 = 0x1e; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  in_ECX[0xdc] = param_1[0xdc];
  *(undefined4 *)(in_ECX + 0xde) = *(undefined4 *)(param_1 + 0xde);
  *(undefined1 *)(in_ECX + 0xe0) = *(undefined1 *)(param_1 + 0xe0);
  return;
}


// ==== FUN_00541f60 @ 0x00541f60 ====

void FUN_00541f60(void)

{
  undefined1 *in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_4 [4];
  
  *(undefined4 *)(in_ECX + 0x28) = 0xf;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  in_ECX[0x14] = 0;
  in_ECX[1] = 1;
  *(undefined4 *)(in_ECX + 4) = 0xffffffff;
  *in_ECX = 0;
  *(undefined2 *)(in_ECX + 8) = 0;
  *(undefined2 *)(in_ECX + 10) = 0;
  *(undefined2 *)(in_ECX + 0xc) = 0;
  puVar1 = (undefined4 *)(in_ECX + 0x14);
  if (*(uint *)(in_ECX + 0x28) < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0x28)) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_004bdb30(local_4,puVar1,*(int *)(in_ECX + 0x24) + (int)puVar2);
  return;
}


// ==== FUN_00541fd0 @ 0x00541fd0 ====

undefined4 FUN_00541fd0(void)

{
  return 0x70910017;
}


// ==== FUN_00541fe0 @ 0x00541fe0 ====

void FUN_00541fe0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba814;
  FUN_00792590();
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00542010 @ 0x00542010 ====

void FUN_00542010(undefined1 *param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = *param_1;
  *(undefined1 *)(in_ECX + 5) = param_1[1];
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(param_1 + 4);
  *(undefined2 *)(in_ECX + 0xc) = *(undefined2 *)(param_1 + 8);
  *(undefined2 *)(in_ECX + 0xe) = *(undefined2 *)(param_1 + 10);
  *(undefined2 *)(in_ECX + 0x10) = *(undefined2 *)(param_1 + 0xc);
  FUN_00401660(param_1 + 0x10,0,0xffffffff);
  return;
}


// ==== FUN_00542060 @ 0x00542060 ====

void FUN_00542060(byte param_1)

{
  void *in_ECX;
  
  FUN_00541a00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00542090 @ 0x00542090 ====

void FUN_00542090(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009ba8a0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  return;
}


// ==== FUN_005420b0 @ 0x005420b0 ====

undefined4 FUN_005420b0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 9) != '\0') {
    switch(param_1) {
    case 0x41:
      (**(code **)(*DAT_00b5ae90 + 0x24))(4);
      return 1;
    case 0x45:
      (**(code **)(*DAT_00b5ae90 + 0x24))(2);
      return 1;
    case 0x51:
      (**(code **)(*DAT_00b5ae90 + 0x24))(0);
      return 1;
    case 0x52:
      (**(code **)(*DAT_00b5ae90 + 0x24))(3);
      return 1;
    case 0x57:
      (**(code **)(*DAT_00b5ae90 + 0x24))(1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00542190 @ 0x00542190 ====

undefined4 FUN_00542190(int param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  
  cVar2 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar2 != '\0') {
    return 0;
  }
  cVar2 = FUN_005420b0(*(undefined4 *)(param_1 + 4));
  if (cVar2 == '\x01') {
    return 1;
  }
  uVar1 = *(uint *)(param_1 + 4);
  if (0x30 < uVar1) {
    if (uVar1 < 0x3a) {
      iVar3 = (**(code **)(*DAT_00b5acd4 + 8))();
      if ((iVar3 == 0) && (cVar2 = (**(code **)(*DAT_00b5a97c + 0x18))(), cVar2 != '\0')) {
        FUN_00532b80(*(undefined1 *)(in_ECX + 8),*(int *)(param_1 + 4) + -0x31);
      }
      return 1;
    }
    if (uVar1 == 0xc0) {
      iVar3 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar3 == 0) {
        FUN_00532e70(*(undefined1 *)(in_ECX + 8));
        return 1;
      }
      return 1;
    }
  }
  if (uVar1 == 0x10) {
    *(undefined1 *)(in_ECX + 9) = 1;
  }
  else if (uVar1 == 0x11) {
    *(undefined1 *)(in_ECX + 8) = 1;
    return 0;
  }
  return 0;
}


// ==== FUN_00542250 @ 0x00542250 ====

undefined4 FUN_00542250(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x20001) {
    cVar1 = FUN_00542190(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x20002) {
    if (param_1[1] == 0x10) {
      *(undefined1 *)(in_ECX + 9) = 0;
      return 0;
    }
    if (param_1[1] == 0x11) {
      *(undefined1 *)(in_ECX + 8) = 0;
    }
  }
  return 0;
}


// ==== FUN_005422b0 @ 0x005422b0 ====

undefined4 FUN_005422b0(void)

{
  return 0x70140005;
}


// ==== FUN_005422c0 @ 0x005422c0 ====

void FUN_005422c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba8c0;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_005422e0 @ 0x005422e0 ====

void FUN_005422e0(int param_1,int param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (((*(char *)(in_ECX + 4) != '\x01') && (param_2 != 0)) && (param_1 != 0)) {
    *(undefined1 *)(in_ECX + 4) = 1;
    *(int *)(in_ECX + 0xc) = param_2;
    *(int *)(in_ECX + 0x10) = param_1;
    pvVar1 = operator_new(0xc);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_005493c0(*(undefined4 *)(in_ECX + 0xc));
      *(undefined4 *)(in_ECX + 8) = uVar2;
      return;
    }
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_00542330 @ 0x00542330 ====

void FUN_00542330(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    *(undefined1 *)(in_ECX + 4) = 0;
    if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 8))(1);
    }
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
  }
  return;
}


// ==== FUN_00542360 @ 0x00542360 ====

undefined4 FUN_00542360(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5af10 + 8))();
  if (cVar1 != '\0') {
    cVar1 = FUN_005495d0();
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5af10 + 4))(0);
      return 0;
    }
    cVar1 = (**(code **)(**(int **)(*(int *)(in_ECX + 8) + 4) + 8))();
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5ae90 + 0x14))(*(undefined4 *)(*(int *)(in_ECX + 0xc) + 4));
      (**(code **)(*DAT_00b5af10 + 4))(0);
      return 1;
    }
    (**(code **)(*DAT_00b5af10 + 4))(0);
  }
  return 0;
}


// ==== FUN_005423e0 @ 0x005423e0 ====

undefined4 FUN_005423e0(void)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5ac28 + 8))(*(undefined4 *)(*(int *)(in_ECX + 0xc) + 4),0,0);
  return 1;
}


// ==== FUN_00542400 @ 0x00542400 ====

undefined4 FUN_00542400(void)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5ac28 + 4))(*(int *)(in_ECX + 0xc) + 0xc,0);
  return 1;
}


// ==== FUN_00542420 @ 0x00542420 ====

undefined4 FUN_00542420(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 0xc) + 8) != 3) {
    iVar1 = (**(code **)(*DAT_00b5acb8 + 0x1c))();
    if (iVar1 != 0) {
      puVar2 = operator_new(8);
      if (puVar2 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar2 = &PTR_FUN_009ba8ac;
      *(undefined2 *)(puVar2 + 1) = 0;
      FUN_00797a20(puVar2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00542470 @ 0x00542470 ====

undefined4 FUN_00542470(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 uVar6;
  undefined4 local_10;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0xc) + 8);
  if (iVar1 == 1) {
    uVar6 = 1;
  }
  else {
    if (iVar1 != 2) {
      return 0;
    }
    uVar6 = 0;
  }
  iVar1 = *(int *)(in_ECX + 0xc);
  uVar2 = *(undefined4 *)(iVar1 + 0x10);
  uVar3 = *(undefined4 *)(iVar1 + 4);
  uVar4 = *(undefined4 *)(iVar1 + 0xc);
  puVar5 = operator_new(0x18);
  if (puVar5 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  puVar5[1] = uVar6;
  puVar5[2] = local_10;
  puVar5[3] = uVar3;
  puVar5[4] = uVar4;
  *puVar5 = &PTR_FUN_009b62fc;
  puVar5[5] = uVar2;
  FUN_00797a20(puVar5);
  return 1;
}


// ==== FUN_00542500 @ 0x00542500 ====

void FUN_00542500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba8c0;
  if (*(char *)(in_ECX + 1) != '\0') {
    *(undefined1 *)(in_ECX + 1) = 0;
    if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[2])(1);
    }
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
  }
  return;
}


// ==== __break @ 0x0054252d ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00542530 @ 0x00542530 ====

undefined4 FUN_00542530(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5acac + 0x48))();
  if (iVar1 != 1) {
    (**(code **)(*DAT_00b5ac28 + 8))(*(undefined4 *)(*(int *)(in_ECX + 0xc) + 4),0,0);
    return 1;
  }
  if (**(char **)(in_ECX + 0xc) == '\0') {
    return 0;
  }
  (**(code **)(*DAT_00b5ac28 + 8))
            (*(undefined4 *)(*(undefined1 **)(in_ECX + 0xc) + 4),0,**(undefined1 **)(in_ECX + 0xc));
  return 1;
}


// ==== FUN_00542590 @ 0x00542590 ====

uint FUN_00542590(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5adc0 + 0x18))();
  if (iVar1 == *(int *)(*(int *)(in_ECX + 0xc) + 4)) {
    uVar2 = (**(code **)(*DAT_00b5ae58 + 8))();
    if ((char)uVar2 == '\0') {
      uVar2 = FUN_005495d0();
      if ((char)uVar2 != '\0') {
        uVar2 = FUN_005492f0();
        return uVar2;
      }
    }
  }
  else {
    uVar2 = FUN_00542470();
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_005425e0 @ 0x005425e0 ====

uint FUN_005425e0(void)

{
  uint uVar1;
  
  FUN_00542470();
  uVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if ((char)uVar1 == '\0') {
    uVar1 = FUN_00549680();
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00542610 @ 0x00542610 ====

undefined4 FUN_00542610(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(*(int *)(in_ECX + 0xc) + 4));
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x40))();
    if (iVar2 == 0x11) {
      FUN_00542470();
      iVar2 = *DAT_00b5acdc;
      uVar3 = FUN_004e5f00(*(undefined4 *)(*(int *)(in_ECX + 0xc) + 4));
      (**(code **)(iVar2 + 0x10))(uVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00542670 @ 0x00542670 ====

undefined4 FUN_00542670(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    cVar1 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x20))(*(int *)(in_ECX + 0xc) + 0xc);
    if (cVar1 != '\0') {
      puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar2 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        return 1;
      }
      *puVar2 = &PTR_FUN_009b6dbc;
      FUN_00797a20(puVar2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005426c0 @ 0x005426c0 ====

undefined4 FUN_005426c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) == 0) {
    return 0;
  }
  FUN_00542470();
  (**(code **)(*DAT_00b5ac28 + 0x20))(*(int *)(in_ECX + 0xc) + 0xc,1);
  return 1;
}


// ==== FUN_005426f0 @ 0x005426f0 ====

undefined4 FUN_005426f0(void)

{
  int in_ECX;
  
  if (DAT_00b5ac28 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*DAT_00b5ac28 + 0xc))(*(undefined4 *)(*(int *)(in_ECX + 0xc) + 4));
  return 1;
}


// ==== FUN_00542710 @ 0x00542710 ====

undefined4 FUN_00542710(void)

{
  char cVar1;
  int in_ECX;
  
  FUN_00542470();
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5ac28 + 0x14))(*(undefined4 *)(*(int *)(in_ECX + 0xc) + 4));
  }
  return 1;
}


// ==== FUN_00542760 @ 0x00542760 ====

uint FUN_00542760(uint param_1)

{
  char cVar1;
  uint in_EAX;
  uint uVar2;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 4) != '\0') &&
     ((DAT_00b5a9e0 == (int *)0x0 ||
      (in_EAX = (**(code **)(*DAT_00b5a9e0 + 0x1c))(), (char)in_EAX == '\0')))) {
    cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
    in_EAX = param_1;
    if (cVar1 != '\0') {
      switch(param_1) {
      default:
        goto switchD_005427a7_caseD_0;
      case 1:
      case 4:
      case 5:
      case 7:
      case 8:
      case 9:
      case 10:
      case 0xb:
      case 0xc:
        break;
      }
    }
    switch(param_1) {
    case 0:
      uVar2 = FUN_00542360();
      return uVar2;
    case 1:
      uVar2 = FUN_00542590();
      return uVar2;
    case 2:
      uVar2 = FUN_005423e0();
      return uVar2;
    case 3:
      uVar2 = FUN_00542400();
      return uVar2;
    case 5:
      uVar2 = FUN_005425e0();
      return uVar2;
    case 6:
      uVar2 = FUN_00542420();
      return uVar2;
    case 7:
      uVar2 = FUN_00542610();
      return uVar2;
    case 8:
      uVar2 = FUN_00542670();
      return uVar2;
    case 9:
      uVar2 = FUN_005426c0();
      return uVar2;
    case 10:
      uVar2 = FUN_005426f0();
      return uVar2;
    case 0xb:
      uVar2 = FUN_00542710();
      return uVar2;
    case 0xc:
      uVar2 = FUN_00542470();
      return uVar2;
    case 0xd:
      uVar2 = FUN_00542530();
      return uVar2;
    }
  }
switchD_005427a7_caseD_0:
  return in_EAX & 0xffffff00;
}


// ==== FUN_005428b0 @ 0x005428b0 ====

void FUN_005428b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba8c0;
  if (*(char *)(in_ECX + 1) != '\0') {
    *(undefined1 *)(in_ECX + 1) = 0;
    if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[2])(1);
    }
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
  }
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00542910 @ 0x00542910 ====

void FUN_00542910(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009ba8c8;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  return;
}


// ==== FUN_00542930 @ 0x00542930 ====

undefined4 FUN_00542930(undefined4 param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 9) != '\0') {
    switch(param_1) {
    case 0x41:
      (**(code **)(*DAT_00b5ae90 + 0x24))(4);
      return 1;
    case 0x45:
      (**(code **)(*DAT_00b5ae90 + 0x24))(2);
      return 1;
    case 0x51:
      (**(code **)(*DAT_00b5ae90 + 0x24))(0);
      return 1;
    case 0x52:
      (**(code **)(*DAT_00b5ae90 + 0x24))(3);
      return 1;
    case 0x57:
      (**(code **)(*DAT_00b5ae90 + 0x24))(1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00542a10 @ 0x00542a10 ====

undefined4 FUN_00542a10(int param_1)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  
  cVar2 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar2 != '\0') {
    return 0;
  }
  cVar2 = FUN_00542930(*(undefined4 *)(param_1 + 4));
  if (cVar2 == '\x01') {
    return 1;
  }
  uVar1 = *(uint *)(param_1 + 4);
  if (0x30 < uVar1) {
    if (uVar1 < 0x3a) {
      iVar3 = (**(code **)(*DAT_00b5acd4 + 8))();
      if ((iVar3 == 0) && (cVar2 = (**(code **)(*DAT_00b5a97c + 0x18))(), cVar2 != '\0')) {
        (**(code **)(*DAT_00b5ad54 + 0x40))(*(int *)(param_1 + 4) + -0x31);
      }
      return 1;
    }
    if (uVar1 == 0xc0) {
      iVar3 = (**(code **)(*DAT_00b5acd4 + 8))();
      if (iVar3 == 0) {
        FUN_00533670(*(undefined1 *)(in_ECX + 8));
        return 1;
      }
      return 1;
    }
  }
  if (uVar1 == 0x10) {
    *(undefined1 *)(in_ECX + 9) = 1;
  }
  else if (uVar1 == 0x11) {
    *(undefined1 *)(in_ECX + 8) = 1;
    return 0;
  }
  return 0;
}


// ==== FUN_00542ad0 @ 0x00542ad0 ====

undefined4 FUN_00542ad0(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x20001) {
    cVar1 = FUN_00542a10(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x20002) {
    if (param_1[1] == 0x10) {
      *(undefined1 *)(in_ECX + 9) = 0;
      return 0;
    }
    if (param_1[1] == 0x11) {
      *(undefined1 *)(in_ECX + 8) = 0;
    }
  }
  return 0;
}


// ==== FUN_00542b30 @ 0x00542b30 ====

void FUN_00542b30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba8f8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00542b50 @ 0x00542b50 ====

void FUN_00542b50(int *param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_1 != (int *)0x0) {
    iVar2 = (**(code **)(*param_1 + 0x18))();
    if (iVar2 == 9) {
      if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[1])(1);
      }
      in_ECX[1] = 0;
      iVar2 = FUN_004edc10();
      in_ECX[1] = iVar2;
    }
    else {
      iVar2 = (**(code **)(*param_1 + 0x18))();
      if (iVar2 != 0) {
        iVar2 = (**(code **)(*param_1 + 0x18))();
        if (iVar2 != 1) {
          if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
            (*(code *)**(undefined4 **)in_ECX[1])(1);
          }
          in_ECX[1] = 0;
        }
      }
    }
    cVar1 = (**(code **)(*param_1 + 8))();
    if (cVar1 != '\0') {
      (**(code **)(*in_ECX + 8))(param_1);
      return;
    }
    (**(code **)(*param_1 + 4))();
    (**(code **)*param_1)(1);
  }
  return;
}


// ==== FUN_00542be0 @ 0x00542be0 ====

undefined4 * FUN_00542be0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (*(char *)(puVar1 + 1) == '\x01') {
    (**(code **)*puVar1)(1);
    puVar1 = (undefined4 *)0x0;
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  return puVar1;
}


// ==== FUN_00542c10 @ 0x00542c10 ====

void FUN_00542c10(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = 0;
  if (*(char *)(in_ECX + 0x20) != '\0') {
    (**(code **)(*DAT_00b5a838 + 0x10))();
    *(undefined1 *)(in_ECX + 0x20) = 0;
  }
  return;
}


// ==== FUN_00542c60 @ 0x00542c60 ====

void FUN_00542c60(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    cVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0xc))(param_1);
    if (cVar1 == '\0') {
      if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
        (**(code **)**(undefined4 **)(in_ECX + 8))(1);
      }
      *(undefined4 *)(in_ECX + 8) = 0;
    }
  }
  return;
}


// ==== FUN_00542c90 @ 0x00542c90 ====

void FUN_00542c90(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x20) != '\x01') && (*(int *)(in_ECX + 0x18) != 0)) {
    iVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    if (60000 < (uint)(iVar1 - *(int *)(in_ECX + 0x18))) {
      (**(code **)(*DAT_00b5a838 + 0xc))(4);
      *(undefined1 *)(in_ECX + 0x20) = 1;
    }
  }
  return;
}


// ==== FUN_00542cd0 @ 0x00542cd0 ====

void FUN_00542cd0(int param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_64 [24];
  char cStack_1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar3 = auStack_64;
  for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  if (cStack_1 != '\0') {
    if (((((param_1 != 0xf) && (param_1 != 0x13)) && (param_1 != 0x14)) &&
        ((param_1 != 0x15 && (param_1 != 0xb)))) &&
       ((param_1 != 0xc && ((param_1 != 7 && (param_1 != 8)))))) {
      (**(code **)(*in_ECX + 0x18))();
      return;
    }
    if (in_ECX[6] == 0) {
      iVar2 = (**(code **)(*DAT_00b5a6ac + 0x18))();
      in_ECX[6] = iVar2;
    }
  }
  return;
}


// ==== FUN_00542d50 @ 0x00542d50 ====

void FUN_00542d50(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  void *_Memory;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 8) = 0;
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    if ((undefined4 *)puVar2[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)puVar2[2])(1);
    }
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x10);
  _Memory = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 0x10) + 4) = *(int *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x14) = 0;
  if (_Memory == *(void **)(in_ECX + 0x10)) {
    uVar3 = FUN_004e5e10();
    *(undefined4 *)(in_ECX + 8) = uVar3;
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_00542df0 @ 0x00542df0 ====

void FUN_00542df0(void)

{
  undefined4 *in_ECX;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009ba918;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if (in_ECX[5] != 0) {
    local_4 = (uint)in_ECX & 0xffffff00;
    FUN_00528030(*(undefined4 *)in_ECX[4],(undefined4 *)in_ECX[4],local_4);
    FUN_00510b80();
  }
  DAT_00b5acdc = 0;
  FUN_008984a0();
  *in_ECX = &PTR_FUN_009ba8f8;
  return;
}


// ==== FUN_00542e60 @ 0x00542e60 ====

void FUN_00542e60(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba918;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  uVar1 = FUN_005430e0();
  in_ECX[4] = uVar1;
  in_ECX[5] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5acdc = (undefined4 *)0x0;
    *(undefined1 *)(in_ECX + 8) = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 5000;
    return;
  }
  DAT_00b5acdc = in_ECX;
  *(undefined1 *)(in_ECX + 8) = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 5000;
  return;
}


// ==== FUN_00542ed0 @ 0x00542ed0 ====

void FUN_00542ed0(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  if (((*(char *)(in_ECX + 0x20) != '\x01') && (*(int *)(in_ECX + 0x18) != 0)) &&
     (iVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))(), 60000 < (uint)(iVar3 - *(int *)(in_ECX + 0x18))
     )) {
    (**(code **)(*DAT_00b5a838 + 0xc))(4);
    *(undefined1 *)(in_ECX + 0x20) = 1;
  }
  if ((*(int *)(in_ECX + 8) == 0) && (*(int *)(in_ECX + 0x14) == 0)) {
    return;
  }
  if (10 < *(uint *)(in_ECX + 0x14)) {
    FUN_00401740(s_m_commandQueue_size____u_10__009ba8d4,0x1c);
    uVar4 = FUN_00797530(auStack_1c);
    FUN_00796d90(uVar4);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
  }
  piVar6 = *(int **)(in_ECX + 0x10);
  piVar5 = (int *)*piVar6;
  do {
    if (piVar5 == piVar6) goto LAB_00543063;
    piVar1 = (int *)piVar5[2];
    cVar2 = (**(code **)(*piVar1 + 0x10))();
    if (cVar2 == '\x01') {
      (**(code **)*piVar1)(1);
      if (piVar5 != *(int **)(in_ECX + 0x10)) {
        *(int **)piVar5[1] = (int *)*piVar5;
        *(int *)(*piVar5 + 4) = piVar5[1];
        _free(piVar5);
        return;
      }
      piVar5 = (int *)*piVar5;
    }
    else {
      cVar2 = (**(code **)(*piVar1 + 8))();
      if (cVar2 != '\0') {
        if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(in_ECX + 8))(1);
        }
        *(int **)(in_ECX + 8) = piVar1;
        uVar4 = (**(code **)(*piVar1 + 0x18))();
        FUN_00542cd0(uVar4);
        piVar6 = (int *)*piVar5;
        if (piVar5 != *(int **)(in_ECX + 0x10)) {
          *(int **)piVar5[1] = piVar6;
          *(int *)(*piVar5 + 4) = piVar5[1];
          _free(piVar5);
          return;
        }
        cVar2 = (**(code **)(*piVar1 + 0x14))();
        if ((cVar2 == '\x01') && (piVar6 != *(int **)(in_ECX + 0x10))) {
          do {
            if ((undefined4 *)piVar6[2] != (undefined4 *)0x0) {
              (*(code *)**(undefined4 **)piVar6[2])(1);
            }
            piVar5 = (int *)*piVar6;
            if (piVar6 != *(int **)(in_ECX + 0x10)) {
              *(int **)piVar6[1] = piVar5;
              *(int *)(*piVar6 + 4) = piVar6[1];
              _free(piVar6);
              return;
            }
            piVar6 = piVar5;
          } while (piVar5 != (int *)*(int *)(in_ECX + 0x10));
        }
        (**(code **)(**(int **)(in_ECX + 8) + 4))();
LAB_00543063:
        if (*(int **)(in_ECX + 8) == (int *)0x0) {
          return;
        }
        cVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0xc))(param_1);
        if (cVar2 != '\0') {
          return;
        }
        if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(in_ECX + 8))(1);
        }
        *(undefined4 *)(in_ECX + 8) = 0;
        return;
      }
    }
    piVar5 = (int *)*piVar5;
  } while( true );
}


// ==== FUN_005430a0 @ 0x005430a0 ====

void FUN_005430a0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  if (param_1 != 0) {
    iVar1 = **(int **)(in_ECX + 0x10);
    iVar2 = FUN_00543170(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
    FUN_00517200(1);
    *(int *)(iVar1 + 4) = iVar2;
    **(int **)(iVar2 + 4) = iVar2;
  }
  return;
}


// ==== FUN_005430e0 @ 0x005430e0 ====

void FUN_005430e0(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981950;
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


// ==== Catch@0054314f @ 0x0054314f ====

void Catch_0054314f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00543170 @ 0x00543170 ====

void FUN_00543170(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981960;
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


// ==== Catch@005431d9 @ 0x005431d9 ====

void Catch_005431d9(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005431f0 @ 0x005431f0 ====

void FUN_005431f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00542df0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00543220 @ 0x00543220 ====

void FUN_00543220(undefined2 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined2 *)(in_ECX + 0x3c);
  return;
}


// ==== FUN_00543230 @ 0x00543230 ====

void FUN_00543230(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x3c) = *param_1;
  return;
}


// ==== FUN_00543240 @ 0x00543240 ====

void FUN_00543240(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar2 = DAT_009a000c;
  uVar1 = DAT_0099d080;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *in_ECX = &PTR_FUN_009ba94c;
  *(undefined1 *)(in_ECX + 5) = 1;
  in_ECX[8] = 0;
  in_ECX[9] = uVar1;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = uVar2;
  in_ECX[0xe] = 0;
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_005432b0 @ 0x005432b0 ====

void FUN_005432b0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  return;
}


// ==== FUN_005432c0 @ 0x005432c0 ====

void FUN_005432c0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_005432d0 @ 0x005432d0 ====

void FUN_005432d0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_005432e0 @ 0x005432e0 ====

void FUN_005432e0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_005432f0 @ 0x005432f0 ====

void FUN_005432f0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = param_1;
  return;
}


// ==== FUN_00543300 @ 0x00543300 ====

void FUN_00543300(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00543310 @ 0x00543310 ====

void FUN_00543310(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x18) = param_1;
  return;
}


// ==== FUN_00543320 @ 0x00543320 ====

void FUN_00543320(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1c) = param_1;
  return;
}


// ==== FUN_00543330 @ 0x00543330 ====

undefined4 FUN_00543330(void)

{
  undefined4 *in_ECX;
  
  return *in_ECX;
}


// ==== FUN_00543340 @ 0x00543340 ====

undefined4 FUN_00543340(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00543350 @ 0x00543350 ====

undefined4 FUN_00543350(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00543360 @ 0x00543360 ====

undefined4 FUN_00543360(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00543370 @ 0x00543370 ====

undefined4 FUN_00543370(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_00543380 @ 0x00543380 ====

undefined4 FUN_00543380(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00543390 @ 0x00543390 ====

undefined4 FUN_00543390(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18);
}


// ==== FUN_005433a0 @ 0x005433a0 ====

undefined4 FUN_005433a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1c);
}


// ==== FUN_005433b0 @ 0x005433b0 ====

void FUN_005433b0(undefined1 param_1,undefined4 param_2,undefined4 param_3)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x20) = param_1;
  *(undefined4 *)(in_ECX + 0x24) = param_2;
  *(undefined4 *)(in_ECX + 0x28) = param_3;
  return;
}


// ==== FUN_005433d0 @ 0x005433d0 ====

void FUN_005433d0(undefined1 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int in_ECX;
  
  *param_1 = *(undefined1 *)(in_ECX + 0x20);
  *param_2 = *(undefined4 *)(in_ECX + 0x24);
  *param_3 = *(undefined4 *)(in_ECX + 0x28);
  return;
}


// ==== FUN_005433f0 @ 0x005433f0 ====

void FUN_005433f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  return;
}


// ==== FUN_00543420 @ 0x00543420 ====

void FUN_00543420(void)

{
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar1 = *DAT_00b5ac6c;
  uVar3 = (**(code **)(*(int *)in_ECX[1] + 8))();
  (**(code **)(iVar1 + 0x18))(uVar3);
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*in_ECX)(1);
  }
  *in_ECX = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  pvVar2 = (void *)in_ECX[4];
  in_ECX[3] = 0;
  if (pvVar2 != (void *)0x0) {
    FUN_00547630();
    _free(pvVar2);
    return;
  }
  in_ECX[4] = 0;
  if ((int *)in_ECX[6] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[6] + 0x70))(1);
  }
  pvVar2 = (void *)in_ECX[7];
  in_ECX[6] = 0;
  if (pvVar2 == (void *)0x0) {
    in_ECX[7] = 0;
    in_ECX[5] = 0;
    return;
  }
  FUN_00543560();
  _free(pvVar2);
  return;
}


// ==== FUN_005434e0 @ 0x005434e0 ====

void FUN_005434e0(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = param_1;
  local_14 = 0x27;
  local_c = 0;
  local_8 = 0;
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5ac68 + 4))(&local_14);
  piVar1 = DAT_00b5ac70;
  if (puVar2 != (undefined4 *)0x0) {
    piVar3 = (int *)FUN_00543340();
    uVar4 = (**(code **)(*piVar3 + 8))();
    (**(code **)(*piVar1 + 0xc))(uVar4,*puVar2,puVar2[1],puVar2[2],0,*(undefined1 *)(puVar2 + 3));
  }
  return;
}


// ==== FUN_00543560 @ 0x00543560 ====

void FUN_00543560(void)

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


// ==== FUN_00543590 @ 0x00543590 ====

void FUN_00543590(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 *puVar6;
  
  puVar1 = *(undefined4 **)(in_ECX + 0xc);
  piVar3 = DAT_00b5ac6c;
  for (puVar6 = *(undefined4 **)(in_ECX + 8); DAT_00b5ac6c = piVar3, puVar6 != puVar1;
      puVar6 = puVar6 + 1) {
    uVar2 = *puVar6;
    piVar4 = (int *)FUN_00543340();
    uVar5 = (**(code **)(*piVar4 + 8))();
    (**(code **)(*piVar3 + 0x30))(uVar5,uVar2);
    piVar3 = DAT_00b5ac6c;
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


// ==== FUN_005435f0 @ 0x005435f0 ====

void FUN_005435f0(int param_1)

{
  if ((param_1 == 1) || (param_1 == 2)) {
    FUN_00543590();
  }
  return;
}


// ==== FUN_00543610 @ 0x00543610 ====

void FUN_00543610(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_00543630 @ 0x00543630 ====

void FUN_00543630(ushort param_1,short param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uStack_14;
  
  piVar1 = DAT_00b5ac70;
  if ((param_1 != 0) && (param_2 != 0)) {
    uStack_14 = 0x543664;
    piVar2 = (int *)FUN_00543340();
    uStack_14 = 0x54366b;
    uVar3 = (**(code **)(*piVar2 + 8))();
    uStack_14 = param_4;
    (**(code **)(*piVar1 + 0xc))(uVar3,param_1 | 0x640000,param_2,param_3,0);
    FUN_00430ce0(&uStack_14);
  }
  return;
}


// ==== FUN_005436a0 @ 0x005436a0 ====

void FUN_005436a0(void)

{
  FUN_00543340();
  return;
}


// ==== FUN_005436b0 @ 0x005436b0 ====

void FUN_005436b0(void)

{
  FUN_00543330();
  return;
}


// ==== FUN_005436c0 @ 0x005436c0 ====

void FUN_005436c0(void)

{
  FUN_00543370();
  return;
}


// ==== FUN_005436d0 @ 0x005436d0 ====

void FUN_005436d0(void)

{
  FUN_00543360();
  return;
}


// ==== FUN_00543720 @ 0x00543720 ====

void FUN_00543720(undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  undefined4 uVar1;
  
  uVar1 = 0;
  (**(code **)(*in_ECX + 0x80))(param_1,param_2,0);
  FUN_00511d20();
  FUN_005118f0(param_1,param_2,uVar1);
  return;
}


// ==== FUN_00543750 @ 0x00543750 ====

void FUN_00543750(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  undefined4 uVar3;
  
  uVar3 = 0;
  (**(code **)(*in_ECX + 0x80))(0);
  FUN_00511ea0(uVar3);
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar1 = *piVar2;
  uVar3 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar1 + 0x48))(param_1,param_4,param_5,param_6,param_7,uVar3);
  return;
}


// ==== FUN_005437e0 @ 0x005437e0 ====

undefined4 FUN_005437e0(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    piVar1 = (int *)FUN_00543340();
    if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005437f7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(*piVar1 + 0x24))();
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_00543800 @ 0x00543800 ====

bool FUN_00543800(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  
  piVar1 = DAT_00b5a97c;
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar3 = (**(code **)(*piVar1 + 0xc))();
  iVar4 = (**(code **)(*piVar2 + 8))();
  return iVar3 == iVar4;
}


// ==== FUN_00543830 @ 0x00543830 ====

void FUN_00543830(int param_1)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5acc0 + 0x1c))(*(undefined2 *)(param_1 + 0xc));
  if (piVar3 != (int *)0x0) {
    bVar1 = *(byte *)(param_1 + 0x13);
    iVar4 = (**(code **)(*piVar3 + 4))();
    uVar6 = (uint)*(ushort *)(iVar4 + 0x888 + (uint)bVar1 * 0x3c);
    bVar1 = *(byte *)(param_1 + 0x13);
    iVar4 = (**(code **)(*piVar3 + 4))();
    bVar2 = *(byte *)(param_1 + 0x13);
    uVar5 = (uint)*(ushort *)(iVar4 + 0x88a + (uint)bVar1 * 0x3c);
    iVar4 = (**(code **)(*piVar3 + 4))();
    uVar7 = *(undefined4 *)(iVar4 + 0x88c + (uint)bVar2 * 0x3c);
    uVar8 = 1;
    FUN_005433a0(uVar6,uVar5,uVar7,1);
    FUN_00543630(uVar6,uVar5,uVar7,uVar8);
  }
  return;
}


// ==== FUN_005438d0 @ 0x005438d0 ====

void FUN_005438d0(byte param_1,char param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *in_ECX;
  undefined4 uStack_c;
  undefined4 uStack_4;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x7c))();
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  piVar1 = DAT_00b5a97c;
  if (iVar2 == 0) {
    piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
    iVar2 = (**(code **)(*piVar3 + 8))();
    iVar4 = (**(code **)(*piVar1 + 0xc))();
    if ((iVar4 == iVar2) ||
       (iVar2 = (**(code **)(*DAT_00b5ac24 + 8))(), *(char *)(iVar2 + 2) != '\x01')) {
      puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar5 == (undefined4 *)0x0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        piVar1 = (int *)(**(code **)(*in_ECX + 0x74))();
        uVar6 = (**(code **)(*piVar1 + 8))();
        *puVar5 = &PTR_FUN_009b8420;
        *(undefined1 *)((int)puVar5 + 0xd) = 0;
        *(undefined1 *)((int)puVar5 + 0xe) = 0;
        *(undefined1 *)((int)puVar5 + 0xf) = 1;
        puVar5[4] = uVar6;
      }
      uStack_4 = (uint)param_1 << 0x18;
      uStack_4._0_2_ = CONCAT11(param_2,0xff);
      uVar6 = DAT_009bab34;
      if (param_2 == '\0') {
        uVar6 = DAT_0099d080;
      }
      puVar5[1] = uStack_c;
      puVar5[2] = uVar6;
      puVar5[3] = uStack_4;
      FUN_00797a20(puVar5);
    }
  }
  return;
}


// ==== FUN_00543a20 @ 0x00543a20 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00543a20(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  undefined1 unaff_retaddr;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x80))();
  piVar2 = DAT_00b5a780;
  iStack_14 = *(int *)(iVar1 + 0x1c);
  uStack_10 = *(undefined4 *)(iVar1 + 0x20);
  if (iStack_14 == 7) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a780 + 8))(&iStack_14);
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 0x80))();
    piVar2 = (int *)(**(code **)(*piVar2 + 8))(iVar1 + 0x14);
  }
  if (piVar2 != (int *)0x0) {
    uStack_10 = CONCAT31(uStack_10._1_3_,unaff_retaddr);
    uStack_8 = param_2;
    uStack_c = param_1;
    iVar1 = (**(code **)(*piVar2 + 0xc))(&uStack_10);
    if (iVar1 != 0) {
      return (float10)*(float *)(iVar1 + 0x114);
    }
  }
  return (float10)_DAT_009bab38;
}


// ==== FUN_00543ac0 @ 0x00543ac0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00543ac0(int param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar2 = (**(code **)(*piVar1 + 0x24))();
  if (*(int **)(iVar2 + 0x4c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar1 + 0x24))(param_1);
  iVar2 = (**(code **)(*in_ECX + 0x78))();
  uVar7 = *(undefined4 *)(iVar2 + 0x30);
  iVar2 = param_1 + 0x30;
  iVar3 = param_1 + 0x28;
  iVar5 = iVar2;
  (**(code **)(*in_ECX + 0x80))(iVar3,iVar2,uVar7);
  FUN_00511d20();
  FUN_005118f0(iVar3,iVar5,uVar7);
  iVar3 = *(int *)(param_1 + 0x3c) - *(int *)(param_1 + 0x38);
  uVar7 = *(undefined4 *)(param_1 + 0x44);
  uVar6 = *(undefined4 *)(param_1 + 0x40);
  fVar4 = (float)iVar3;
  if (iVar3 < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  fVar4 = fVar4 * DAT_0099d0ec;
  param_1 = param_1 + 0x1c;
  (**(code **)(*in_ECX + 0x80))(param_1,iVar2,fVar4,uVar6,uVar7);
  FUN_00511d20();
  FUN_00511c00(param_1,iVar2,fVar4,uVar6,uVar7);
  return;
}


// ==== FUN_00543b70 @ 0x00543b70 ====

void FUN_00543b70(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  undefined4 uVar3;
  
  uVar3 = 0;
  (**(code **)(*in_ECX + 0x80))(0);
  FUN_00511ea0(uVar3);
  uVar3 = 0;
  (**(code **)(*in_ECX + 0x80))(0);
  FUN_00511ef0(uVar3);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar2 = (**(code **)(*piVar1 + 0x24))();
  if (*(int **)(iVar2 + 0x4c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar1 + 0x24))(param_1);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar2 = *piVar1;
  uVar3 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar2 + 0x28))(uVar3);
  (**(code **)(*DAT_00b5a6ac + 0x20))();
  return;
}


// ==== FUN_00543bf0 @ 0x00543bf0 ====

void FUN_00543bf0(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  float10 fVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  float fVar9;
  undefined4 uVar10;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  undefined1 auStack_20 [8];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  float fStack_4;
  
  cVar1 = (**(code **)(*in_ECX + 4))();
  if (cVar1 == '\0') {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x7c))();
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    if (iVar3 == 0) {
      (**(code **)(*in_ECX + 0x80))();
      goto LAB_00543c2b;
    }
  }
  (**(code **)(*in_ECX + 0x80))();
LAB_00543c2b:
  FUN_00511ea0();
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar3 = (**(code **)(*piVar2 + 0x24))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar2 + 0x24))(param_1);
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar3 = *piVar2;
  uVar4 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar3 + 0x28))(uVar4);
  FUN_004f5730(auStack_20);
  uStack_14 = 0;
  uStack_c = (uint)(*(char *)(param_1 + 0xc) != '\0');
  uStack_10 = 0x1e;
  fVar5 = (float10)FUN_00543a20(*(undefined1 *)(param_1 + 10),0x1e,uStack_c);
  fStack_4 = (float)fVar5;
  FUN_0040d600(auStack_28,uStack_18);
  cVar1 = (**(code **)(*in_ECX + 4))();
  if (cVar1 == '\0') {
    uVar4 = 0;
    puVar7 = auStack_28;
    puVar8 = auStack_28 + -8;
    (**(code **)(*in_ECX + 0x80))(puVar8,puVar7,0);
    FUN_00511d20();
    FUN_005118f0(puVar8,puVar7,uVar4);
  }
  uVar10 = 0;
  uVar4 = 0;
  puVar7 = auStack_28;
  puVar6 = &uStack_14;
  fVar9 = fStack_4;
  (**(code **)(*in_ECX + 0x80))(puVar6,puVar7,fStack_4,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar6,puVar7,fVar9,uVar4,uVar10);
  return;
}


// ==== FUN_00543d50 @ 0x00543d50 ====

int FUN_00543d50(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  piVar2 = DAT_00b5a780;
  iVar1 = (**(code **)(*in_ECX + 0x80))();
  piVar2 = (int *)(**(code **)(*piVar2 + 8))(iVar1 + 0x14);
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 0xc))(auStack_a + -6);
    if (iVar1 != 0) {
      return (int)ROUND(*(float *)(iVar1 + 0x114) * DAT_009b012c);
    }
  }
  return 1000;
}


// ==== FUN_00543de0 @ 0x00543de0 ====

void FUN_00543de0(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  piVar2 = DAT_00b5a780;
  iVar1 = (**(code **)(*in_ECX + 0x80))();
  piVar2 = (int *)(**(code **)(*piVar2 + 8))(iVar1 + 0x14);
  if (piVar2 == (int *)0x0) {
    return;
  }
  (**(code **)(*piVar2 + 0xc))(auStack_a + -6);
  return;
}


// ==== FUN_00543e30 @ 0x00543e30 ====

void FUN_00543e30(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  void *_Memory;
  undefined4 *puVar6;
  int *piVar7;
  undefined4 uVar8;
  int *in_ECX;
  
  if (in_ECX[4] != 0) {
    puVar2 = (undefined4 *)in_ECX[3];
    puVar3 = (undefined4 *)*puVar2;
    while (puVar3 != puVar2) {
      piVar7 = (int *)(**(code **)(*in_ECX + 0x74))();
      iVar4 = *DAT_00b5ac70;
      uVar8 = (**(code **)(*piVar7 + 8))(puVar3[4]);
      (**(code **)(iVar4 + 0x20))(uVar8);
      if (*(char *)((int)puVar3 + 0x21) == '\0') {
        puVar5 = (undefined4 *)puVar3[2];
        if (*(char *)((int)puVar5 + 0x21) == '\0') {
          cVar1 = *(char *)((int)*puVar5 + 0x21);
          puVar3 = puVar5;
          puVar5 = (undefined4 *)*puVar5;
          while (cVar1 == '\0') {
            cVar1 = *(char *)((int)*puVar5 + 0x21);
            puVar3 = puVar5;
            puVar5 = (undefined4 *)*puVar5;
          }
        }
        else {
          cVar1 = *(char *)((int)puVar3[1] + 0x21);
          puVar6 = (undefined4 *)puVar3[1];
          puVar5 = puVar3;
          while ((puVar3 = puVar6, cVar1 == '\0' && (puVar5 == (undefined4 *)puVar3[2]))) {
            cVar1 = *(char *)((int)puVar3[1] + 0x21);
            puVar6 = (undefined4 *)puVar3[1];
            puVar5 = puVar3;
          }
        }
      }
    }
    _Memory = *(void **)(in_ECX[3] + 4);
    if (*(char *)((int)_Memory + 0x21) == '\0') {
      FUN_00546f90(*(undefined4 *)((int)_Memory + 8));
      _free(_Memory);
      return;
    }
    *(int *)(in_ECX[3] + 4) = in_ECX[3];
    in_ECX[4] = 0;
    *(int *)in_ECX[3] = in_ECX[3];
    *(int *)(in_ECX[3] + 8) = in_ECX[3];
  }
  return;
}


// ==== FUN_00543f10 @ 0x00543f10 ====

void FUN_00543f10(char param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  char cVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  char *pcVar9;
  int *piVar10;
  int *in_ECX;
  void *unaff_EBX;
  undefined1 *puVar11;
  undefined1 uVar12;
  undefined4 uStack_78;
  undefined4 uStack_6c;
  uint uStack_68;
  void *pvStack_60;
  undefined1 auStack_5c [4];
  undefined1 auStack_58 [4];
  void *pvStack_54;
  undefined4 uStack_50;
  uint uStack_4c;
  void *pvStack_44;
  uint uStack_40;
  undefined1 auStack_3c [12];
  uint uStack_30;
  void *pvStack_28;
  undefined1 auStack_24 [4];
  undefined1 auStack_20 [12];
  uint uStack_14;
  
  if (in_ECX[4] != 0) {
    piVar10 = *(int **)in_ECX[3];
    uStack_78 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    if (piVar10 != (int *)in_ECX[3]) {
      do {
        uVar5 = uStack_78 - piVar10[5];
        uVar1 = piVar10[6];
        if ((uVar5 < 0x4e21) &&
           (((uVar1 != 0 && (uVar1 < uVar5)) ||
            (((param_1 == '\0' || ((char)piVar10[7] == '\0')) && (uVar1 < uVar5)))))) {
          if (*(char *)((int)piVar10 + 0x21) == '\0') {
            piVar6 = (int *)piVar10[2];
            if (*(char *)((int)piVar6 + 0x21) == '\0') {
              cVar4 = *(char *)(*piVar6 + 0x21);
              piVar10 = piVar6;
              piVar6 = (int *)*piVar6;
              while (cVar4 == '\0') {
                cVar4 = *(char *)(*piVar6 + 0x21);
                piVar10 = piVar6;
                piVar6 = (int *)*piVar6;
              }
            }
            else {
              cVar4 = *(char *)(piVar10[1] + 0x21);
              piVar3 = (int *)piVar10[1];
              piVar6 = piVar10;
              while ((piVar10 = piVar3, cVar4 == '\0' && (piVar6 == (int *)piVar10[2]))) {
                cVar4 = *(char *)(piVar10[1] + 0x21);
                piVar3 = (int *)piVar10[1];
                piVar6 = piVar10;
              }
            }
          }
        }
        else {
          piVar6 = (int *)(**(code **)(*in_ECX + 0x74))();
          iVar2 = *DAT_00b5ac70;
          uVar7 = (**(code **)(*piVar6 + 8))(piVar10[4]);
          (**(code **)(iVar2 + 0x20))(uVar7);
          puVar8 = (undefined4 *)FUN_0057e890(auStack_5c + -0x20,piVar10);
          piVar10 = (int *)*puVar8;
        }
      } while (piVar10 != (int *)in_ECX[3]);
    }
    pcVar9 = (char *)(**(code **)(*DAT_00b5ac24 + 8))();
    if (*pcVar9 != '\0') {
      piVar10 = (int *)(**(code **)(*in_ECX + 0x74))();
      iVar2 = *DAT_00b5a97c;
      uVar7 = (**(code **)(*piVar10 + 8))();
      cVar4 = (**(code **)(iVar2 + 0x10))(uVar7);
      if (cVar4 != '\0') {
        piVar10 = (int *)(**(code **)(*in_ECX + 0x74))();
        iVar2 = *DAT_00b5ac6c;
        uVar7 = (**(code **)(*piVar10 + 8))();
        (**(code **)(iVar2 + 0x34))(uVar7);
      }
      if (in_ECX[4] == 0) {
        FUN_00401830(s_Empty_009baadc);
        piVar10 = (int *)(**(code **)(*in_ECX + 0x74))();
        (**(code **)(*piVar10 + 0x40))(auStack_58);
        FUN_00401830(s_EffInfo__s__009baae4);
        uVar7 = FUN_00404230(&uStack_78);
        (**(code **)(*DAT_00b5a688 + 8))(uVar7,auStack_24);
        if (0xf < uStack_68) {
          _free(unaff_EBX);
          return;
        }
        uStack_68 = 0xf;
        uStack_6c = 0;
        if (0xf < uStack_4c) {
          _free(pvStack_60);
          return;
        }
        uStack_4c = 0xf;
        uStack_50 = 0;
        pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
        if (0xf < uStack_14) {
          _free(pvStack_28);
          return;
        }
      }
      else {
        FUN_00401830(s_Total__d__009baaf0);
        puVar11 = auStack_3c;
        FUN_00404230(puVar11);
        piVar10 = (int *)in_ECX[3];
        piVar6 = (int *)*piVar10;
        while (piVar6 != piVar10) {
          uVar12 = 0;
          FUN_00401740(s___d__d__009baafc,7);
          uVar7 = FUN_00404230(auStack_58,puVar11,uVar12);
          FUN_00401ff0(uVar7,0,0xffffffff);
          if (0xf < uStack_40) {
            _free(pvStack_54);
            return;
          }
          uStack_40 = 0xf;
          pvStack_44 = (void *)0x0;
          pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
          FUN_004dde50();
        }
        piVar10 = (int *)(**(code **)(*in_ECX + 0x74))();
        (**(code **)(*piVar10 + 0x40))(auStack_20);
        uVar12 = 0;
        FUN_00401740(s_EffInfo__s__009bab04,0xb);
        uVar7 = FUN_00404230(auStack_5c,puVar11,uVar12);
        (**(code **)(*DAT_00b5a688 + 8))(uVar7,&uStack_40);
        if (0xf < uStack_4c) {
          _free(pvStack_60);
          return;
        }
        uStack_4c = 0xf;
        uStack_50 = 0;
        pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
        if (0xf < uStack_14) {
          _free(pvStack_28);
          return;
        }
        if (0xf < uStack_30) {
          _free(pvStack_44);
          return;
        }
      }
    }
  }
  return;
}


// ==== FUN_00544280 @ 0x00544280 ====

void FUN_00544280(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int *in_ECX;
  int local_30;
  int *local_2c [5];
  undefined4 uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar2 = param_3;
  iVar1 = param_1;
  if ((param_1 != 0) && (param_3 != 0)) {
    local_2c[0] = in_ECX + 2;
    FUN_00558e70(&local_30,&param_1);
    if (local_30 != in_ECX[3]) {
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      *(undefined4 *)(local_30 + 0x18) = param_2;
      *(undefined4 *)(local_30 + 0x14) = uVar3;
      *(undefined1 *)(local_30 + 0x1c) = 1;
      piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
      piVar5 = (int *)(**(code **)(*in_ECX + 0x74))();
      uVar3 = (**(code **)(*piVar4 + 8))();
      uVar3 = (**(code **)(*piVar5 + 4))(1,iVar1,iVar2,uVar3);
      FUN_004dd280(0x19,uVar3);
      return;
    }
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uStack_18 = CONCAT31(uStack_18._1_3_,1);
    piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
    piVar5 = (int *)(**(code **)(*in_ECX + 0x74))();
    uVar6 = (**(code **)(*piVar4 + 8))();
    uVar6 = (**(code **)(*piVar5 + 4))(1,iVar1,param_3,uVar6);
    uStack_10 = FUN_004dd280(0x19,uVar6);
    uStack_8 = param_2;
    iStack_14 = iVar1;
    uStack_4 = uStack_18;
    uStack_c = uVar3;
    FUN_005473a0(local_2c,&iStack_14);
  }
  return;
}


// ==== FUN_00544390 @ 0x00544390 ====

void FUN_00544390(int param_1,undefined4 param_2,undefined1 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_ECX;
  int local_30;
  int *local_2c [5];
  undefined4 uStack_18;
  int iStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = param_1;
  if (param_1 != 0) {
    local_2c[0] = in_ECX + 2;
    FUN_00558e70(&local_30,&param_1);
    if (local_30 != in_ECX[3]) {
      uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      *(undefined4 *)(local_30 + 0x18) = param_2;
      *(undefined4 *)(local_30 + 0x14) = uVar2;
      *(undefined1 *)(local_30 + 0x1c) = param_3;
      piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
      piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
      uVar2 = (**(code **)(*piVar3 + 8))();
      uVar2 = (**(code **)(*piVar4 + 4))(1,iVar1,uVar2);
      FUN_004dd240(0x19,uVar2);
      return;
    }
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uStack_18 = CONCAT31(uStack_18._1_3_,param_3);
    piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
    piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
    uVar5 = (**(code **)(*piVar3 + 8))();
    uVar5 = (**(code **)(*piVar4 + 4))(1,iVar1,uVar5);
    uStack_10 = FUN_004dd240(0x19,uVar5);
    uStack_8 = param_2;
    uStack_4 = uStack_18;
    iStack_14 = iVar1;
    uStack_c = uVar2;
    FUN_005473a0(local_2c,&iStack_14);
  }
  return;
}


// ==== FUN_005444e0 @ 0x005444e0 ====

void FUN_005444e0(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  float10 fVar5;
  uint *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  float fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined1 auStack_2a [2];
  undefined1 auStack_28 [8];
  uint auStack_20 [3];
  undefined1 auStack_14 [8];
  undefined4 uStack_c;
  float fStack_4;
  
  cVar2 = (**(code **)(*in_ECX + 4))();
  if (cVar2 == '\0') {
    piVar3 = (int *)(**(code **)(*in_ECX + 0x7c))();
    iVar4 = (**(code **)(*piVar3 + 0xc))();
    if (iVar4 == 0) {
      uVar11 = 1;
      (**(code **)(*in_ECX + 0x80))(1);
      FUN_00511ea0(uVar11);
    }
  }
  piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar4 = (**(code **)(*piVar3 + 0x24))();
  if (*(int **)(iVar4 + 0x4c) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar3 + 0x24))(param_1);
  piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar4 = *piVar3;
  uVar11 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar4 + 0x28))(uVar11);
  FUN_004f5730(auStack_14);
  auStack_20[0] = (uint)*(byte *)(param_1 + 10);
  auStack_20[1] = 0x20;
  auStack_20[2] = 0;
  piVar3 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar3 = (int *)(**(code **)(*piVar3 + 0x2c))();
  iVar4 = (**(code **)(*piVar3 + 0x10))();
  if (*(char *)(iVar4 + 0x960) == '\x01') {
    uVar1 = *(undefined1 *)(param_1 + 10);
    uVar11 = 0x1a;
    auStack_20[1] = 0x1a;
  }
  else {
    uVar1 = *(undefined1 *)(param_1 + 10);
    uVar11 = 1;
    auStack_20[1] = 1;
  }
  fVar5 = (float10)FUN_00543a20(uVar1,uVar11,0);
  fStack_4 = (float)fVar5;
  FUN_0040d600(auStack_28,uStack_c);
  cVar2 = (**(code **)(*in_ECX + 4))();
  if (cVar2 == '\0') {
    iVar4 = (**(code **)(*in_ECX + 0x78))();
    uVar11 = *(undefined4 *)(iVar4 + 0x30);
    puVar7 = auStack_28;
    puVar8 = auStack_2a + -6;
    (**(code **)(*in_ECX + 0x80))(puVar8,puVar7,uVar11);
    FUN_00511d20();
    FUN_005118f0(puVar8,puVar7,uVar11);
  }
  uVar10 = 0;
  uVar11 = 0;
  puVar7 = auStack_28;
  puVar6 = auStack_20;
  fVar9 = fStack_4;
  (**(code **)(*in_ECX + 0x80))(puVar6,puVar7,fStack_4,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar6,puVar7,fVar9,uVar11,uVar10);
  FUN_00543f10(0);
  piVar3 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar3 = (int *)(**(code **)(*piVar3 + 0x2c))();
  iVar4 = (**(code **)(*piVar3 + 0x10))();
  if (*(char *)(iVar4 + 0x960) == '\x01') {
    uVar11 = 0x1a;
  }
  else {
    uVar11 = 1;
  }
  iVar4 = FUN_00543de0(auStack_20[0],uVar11,auStack_20[2]);
  if (iVar4 != 0) {
    FUN_00544390(*(undefined4 *)(iVar4 + 300),*(undefined4 *)(iVar4 + 0x130),0);
  }
  FUN_005438d0(0,0);
  return;
}


// ==== FUN_005446e0 @ 0x005446e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005446e0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  uint *puVar4;
  float fVar5;
  undefined1 *puVar6;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  uint uStack_20;
  int iStack_1c;
  uint uStack_18;
  undefined1 auStack_14 [8];
  undefined4 uStack_c;
  float fStack_4;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar2 = (**(code **)(*piVar1 + 0x24))();
  if (*(int **)(iVar2 + 0x4c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar1 + 0x24))(param_1);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar2 = *piVar1;
  uVar3 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar2 + 0x28))(uVar3);
  FUN_004f5730(auStack_14);
  uStack_20 = (uint)*(byte *)(param_1 + 10);
  iStack_1c = 0x20;
  uStack_18 = 0;
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x2c))();
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  iStack_1c = (-(uint)(*(char *)(iVar2 + 0x960) != '\x01') & 0xffffffe6) + 0x1c;
  uStack_18 = (uint)(*(char *)(param_1 + 0xd) != '\0');
  FUN_0040d600(auStack_28,uStack_c);
  if ((DAT_00b5ade8 & 1) == 0) {
    DAT_00b5ade8 = DAT_00b5ade8 | 1;
    _DAT_00b5ade4 = DAT_009b0eb8;
  }
  if ((DAT_00b5ade8 & 2) == 0) {
    DAT_00b5ade8 = DAT_00b5ade8 | 2;
    _DAT_00b5ade0 = DAT_009b2d7c;
  }
  FUN_0040d600(auStack_28 + -8,(float)*(byte *)(param_1 + 0xc) * _DAT_00b5ade0 * _DAT_009ae954);
  uVar3 = 1;
  puVar6 = auStack_28 + -8;
  puVar4 = &uStack_20;
  fVar5 = (float)*(ushort *)(param_1 + 0xe) * DAT_009b3508;
  fStack_4 = fVar5;
  (**(code **)(*in_ECX + 0x80))(puVar4,fVar5,puVar6,1);
  FUN_00511d20();
  FUN_00511a60(puVar4,fVar5,puVar6,uVar3);
  FUN_00543f10(0);
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x2c))();
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  if (*(char *)(iVar2 + 0x960) == '\x01') {
    uVar3 = 0x1c;
  }
  else {
    uVar3 = 2;
  }
  iVar2 = FUN_00543de0(uStack_20,uVar3,uStack_18);
  if (iVar2 != 0) {
    FUN_00544390(*(undefined4 *)(iVar2 + 300),*(undefined4 *)(iVar2 + 0x130),0);
  }
  FUN_005438d0(0,0);
  return;
}


// ==== FUN_005448c0 @ 0x005448c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005448c0(float *param_1,float *param_2,undefined4 param_3,undefined1 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 unaff_retaddr;
  undefined1 *puVar4;
  undefined4 local_44;
  float local_40;
  undefined1 auStack_38 [16];
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  float fStack_10;
  float fStack_c;
  undefined1 uStack_8;
  undefined4 uStack_4;
  
  local_44 = *param_2 - *param_1;
  local_40 = param_2[1] - param_1[1];
  if (_DAT_009bab30 < SQRT(local_44 * local_44 + local_40 * local_40)) {
    thunk_FUN_0079de77(&local_44,&local_44);
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 0x78))();
    local_44 = *(float *)(iVar1 + 0x20);
    local_40 = *(float *)(iVar1 + 0x24);
  }
  fStack_28 = *param_1;
  fStack_24 = param_1[1];
  uStack_18 = param_6;
  uStack_14 = (undefined1)param_3;
  uStack_8 = param_4;
  uStack_4 = param_5;
  fStack_20 = local_44;
  fStack_1c = local_40;
  fStack_10 = local_44;
  fStack_c = local_40;
  FUN_00507870(&fStack_28,auStack_38);
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar1 = (**(code **)(*piVar2 + 0x24))();
  if (*(int **)(iVar1 + 0x4c) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar2 + 0x24))(auStack_38);
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar1 = *piVar2;
  uVar3 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar1 + 0x28))(uVar3);
  local_44 = 0.0;
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))();
  (**(code **)(*piVar2 + 0x10))();
  puVar4 = auStack_38 + -0x14;
  local_44 = (float)(uint)((char)param_2 != '\0');
  uVar3 = param_3;
  (**(code **)(*in_ECX + 0x80))(puVar4,param_3,unaff_retaddr,param_6);
  FUN_00511d20();
  FUN_005119b0(puVar4,uVar3,unaff_retaddr,param_6);
  FUN_00543f10(0);
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))();
  iVar1 = (**(code **)(*piVar2 + 0x10))();
  if (*(char *)(iVar1 + 0x960) == '\x01') {
    uVar3 = 0x1c;
  }
  else {
    uVar3 = 2;
  }
  iVar1 = FUN_00543de0(param_3,uVar3,local_44);
  if (iVar1 != 0) {
    FUN_00544390(*(undefined4 *)(iVar1 + 300),*(undefined4 *)(iVar1 + 0x130),0);
  }
  FUN_005438d0(0,0);
  return;
}


// ==== FUN_00544ac0 @ 0x00544ac0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00544ac0(uint *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_ECX;
  uint *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  float fVar9;
  float fVar10;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  uint auStack_20 [2];
  uint auStack_18 [3];
  undefined4 uStack_c;
  undefined1 uStack_8;
  float fStack_4;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar3 = (**(code **)(*piVar2 + 0x24))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar2 + 0x24))(param_1);
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar3 = *piVar2;
  uVar4 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar3 + 0x28))(uVar4);
  FUN_004f5730(auStack_18 + 1);
  auStack_18[0] = (uint)*(byte *)((int)param_1 + 0xe);
  auStack_20[0] = (uint)*(byte *)((int)param_1 + 10);
  auStack_20[1] = 6;
  FUN_0040d600(auStack_28,uStack_c);
  fStack_4 = (float)(ushort)param_1[3] * DAT_009b3508;
  iVar3 = 0;
  if (*param_1 < *(uint *)((int)param_1 + 0xf)) {
    iVar3 = *(uint *)((int)param_1 + 0xf) - *param_1;
  }
  uVar4 = 0;
  puVar7 = auStack_28;
  puVar8 = auStack_28 + -8;
  (**(code **)(*in_ECX + 0x80))(puVar8,puVar7,0);
  FUN_00511d20();
  FUN_005118f0(puVar8,puVar7,uVar4);
  fVar10 = fStack_4;
  fVar9 = (float)iVar3;
  uVar4 = 2;
  if (iVar3 < 0) {
    fVar9 = fVar9 + _DAT_0099d104;
  }
  fVar9 = fVar9 * DAT_0099d0ec;
  puVar7 = auStack_28;
  puVar6 = auStack_20;
  fStack_4 = (float)iVar3;
  (**(code **)(*in_ECX + 0x80))(puVar6,puVar7,fVar9,2,fVar10);
  FUN_00511d20();
  FUN_00511c00(puVar6,puVar7,fVar9,uVar4,fVar10);
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  (**(code **)(*piVar2 + 0x5c))();
  FUN_00543f10(0);
  uVar1 = auStack_18[0];
  piVar2 = DAT_00b5a780;
  fStack_4 = (float)auStack_20[0];
  iVar5 = (**(code **)(*in_ECX + 0x80))();
  piVar2 = (int *)(**(code **)(*piVar2 + 8))(iVar5 + 0x14);
  if (piVar2 != (int *)0x0) {
    auStack_18[0] = CONCAT31(auStack_18[0]._1_3_,uStack_8);
    auStack_18[1] = 6;
    auStack_18[2] = uVar1;
    iVar5 = (**(code **)(*piVar2 + 0xc))(auStack_18);
    if (iVar5 != 0) {
      FUN_00544280(*(undefined4 *)(iVar5 + 300),*(undefined4 *)(iVar5 + 0x130),iVar3);
    }
  }
  FUN_005438d0(1,0);
  return;
}


// ==== FUN_00544c80 @ 0x00544c80 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00544c80(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  uint *puVar5;
  undefined1 *puVar6;
  undefined1 *puVar7;
  float fVar8;
  undefined4 uVar9;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  uint uStack_20;
  int iStack_1c;
  uint uStack_18;
  undefined1 auStack_14 [8];
  undefined4 uStack_c;
  int iStack_4;
  
  cVar1 = (**(code **)(*in_ECX + 4))();
  if (cVar1 == '\0') {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x7c))();
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    if (iVar3 == 0) {
      (**(code **)(*in_ECX + 0x80))();
      FUN_00511ea0();
    }
  }
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar3 = (**(code **)(*piVar2 + 0x24))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar2 + 0x24))(param_1);
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar3 = *piVar2;
  uVar4 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar3 + 0x28))(uVar4);
  FUN_004f5730(auStack_14);
  uStack_20 = (uint)*(byte *)((int)param_1 + 10);
  iStack_1c = 0x20;
  uStack_18 = (uint)((char)param_1[3] == '\x02');
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))();
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  iStack_1c = (-(uint)(*(char *)(iVar3 + 0x960) != '\x01') & 0xffffffee) + 0x1d;
  FUN_0040d600(auStack_28,uStack_c);
  iVar3 = *(int *)((int)param_1 + 0xd) - *param_1;
  uVar4 = 0;
  puVar6 = auStack_28;
  puVar7 = auStack_28 + -8;
  (**(code **)(*in_ECX + 0x80))(puVar7,puVar6,0);
  FUN_00511d20();
  FUN_005118f0(puVar7,puVar6,uVar4);
  uVar9 = 0;
  fVar8 = (float)iVar3;
  uVar4 = 0;
  if (iVar3 < 0) {
    fVar8 = fVar8 + _DAT_0099d104;
  }
  fVar8 = fVar8 * DAT_0099d0ec;
  puVar6 = auStack_28;
  puVar5 = &uStack_20;
  iStack_4 = iVar3;
  (**(code **)(*in_ECX + 0x80))(puVar5,puVar6,fVar8,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar5,puVar6,fVar8,uVar4,uVar9);
  FUN_00543f10(0);
  piVar2 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x2c))();
  iVar3 = (**(code **)(*piVar2 + 0x10))();
  if (*(char *)(iVar3 + 0x960) == '\x01') {
    uVar4 = 0x1d;
  }
  else {
    uVar4 = 0xb;
  }
  iVar3 = FUN_00543de0(uStack_20,uVar4,uStack_18);
  if (iVar3 != 0) {
    FUN_00544390(*(undefined4 *)(iVar3 + 300),*(undefined4 *)(iVar3 + 0x130),0);
  }
  return;
}


// ==== FUN_00544e60 @ 0x00544e60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00544e60(int *param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *in_ECX;
  uint *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  float fVar10;
  float fVar11;
  undefined1 auStack_44 [2];
  undefined1 auStack_42 [6];
  uint auStack_3c [2];
  uint auStack_34 [3];
  undefined4 uStack_28;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  float fStack_4;
  
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = (**(code **)(*piVar4 + 0x24))();
  if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar4 + 0x24))(param_1);
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = *piVar4;
  uVar6 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar5 + 0x28))(uVar6);
  FUN_004f5730(auStack_34 + 1);
  auStack_34[0] = (uint)*(byte *)(param_1 + 3);
  auStack_3c[0] = (uint)*(byte *)((int)param_1 + 10);
  auStack_3c[1] = 7;
  FUN_0040d600(auStack_44,uStack_28);
  iVar5 = *(int *)((int)param_1 + 0x11) - *param_1;
  fStack_4 = (float)*(ushort *)((int)param_1 + 0xf) * DAT_009b3508;
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 == '\0') {
    uVar6 = 0;
    puVar8 = auStack_44;
    puVar9 = auStack_44 + -8;
    (**(code **)(*in_ECX + 0x80))(puVar9,puVar8,0);
    FUN_00511d20();
    FUN_005118f0(puVar9,puVar8,uVar6);
  }
  fVar11 = fStack_4;
  fVar10 = (float)iVar5;
  uVar6 = 1;
  if (iVar5 < 0) {
    fVar10 = fVar10 + _DAT_0099d104;
  }
  fVar10 = fVar10 * DAT_0099d0ec;
  puVar8 = auStack_44;
  puVar7 = auStack_3c;
  fStack_4 = (float)iVar5;
  (**(code **)(*in_ECX + 0x80))(puVar7,puVar8,fVar10,1,fVar11);
  FUN_00511d20();
  FUN_00511c00(puVar7,puVar8,fVar10,uVar6,fVar11);
  FUN_00543f10(1);
  uVar2 = auStack_34[0];
  uVar1 = auStack_3c[0];
  piVar4 = DAT_00b5a780;
  iVar5 = (**(code **)(*in_ECX + 0x80))();
  piVar4 = (int *)(**(code **)(*piVar4 + 8))(iVar5 + 0x14);
  if (piVar4 != (int *)0x0) {
    auStack_34[0] = CONCAT31(auStack_34[0]._1_3_,(char)uVar1);
    auStack_34[1] = 7;
    auStack_34[2] = uVar2;
    iVar5 = (**(code **)(*piVar4 + 0xc))(auStack_34);
    if (iVar5 != 0) {
      FUN_00544390(*(undefined4 *)(iVar5 + 300),*(undefined4 *)(iVar5 + 0x130),0);
    }
  }
  FUN_005438d0(0,0);
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 != '\0') {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_SKILL_DEFEAT_009ba9b4,0xc);
    FUN_00796d50(&uStack_28);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
  }
  return;
}


// ==== __break @ 0x00545059 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00545060 @ 0x00545060 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00545060(int *param_1)

{
  byte bVar1;
  float fVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *in_ECX;
  float10 fVar7;
  uint *puVar8;
  undefined1 *puVar9;
  undefined8 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined1 auStack_4e [10];
  undefined1 auStack_44 [8];
  uint auStack_3c [3];
  undefined1 auStack_30 [8];
  undefined4 uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  uint uStack_c;
  float fStack_4;
  
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 == '\0') {
    piVar4 = (int *)(**(code **)(*in_ECX + 0x7c))();
    iVar5 = (**(code **)(*piVar4 + 0xc))();
    if (iVar5 == 0) {
      uVar12 = 1;
      (**(code **)(*in_ECX + 0x80))(1);
      goto LAB_0054509e;
    }
  }
  uVar12 = 0;
  (**(code **)(*in_ECX + 0x80))(0);
LAB_0054509e:
  FUN_00511ea0(uVar12);
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = (**(code **)(*piVar4 + 0x24))();
  if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar4 + 0x24))(param_1);
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = *piVar4;
  uVar12 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar5 + 0x28))(uVar12);
  FUN_004f5730(auStack_30);
  auStack_3c[1] = 0x20;
  auStack_3c[2] = (uint)(*(char *)((int)param_1 + 0x13) == '\x01');
  auStack_3c[0] = (uint)*(byte *)((int)param_1 + 10);
  piVar4 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x2c))();
  iVar5 = (**(code **)(*piVar4 + 0x10))();
  if (*(char *)(iVar5 + 0x960) == '\x01') {
    if (*(char *)((int)param_1 + 0x13) == '\x02') {
      auStack_3c[2] = auStack_3c[2] + 10;
    }
    auStack_3c[1] = 0x1b;
    fVar7 = (float10)FUN_00543a20();
    if ((float10)_DAT_009bab38 == fVar7) {
      return;
    }
  }
  else {
    auStack_3c[1] = 8;
    fVar7 = (float10)FUN_00543a20();
  }
  fStack_4 = (float)fVar7;
  FUN_0040d600(auStack_4e + -6,uStack_28);
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 == '\0') {
    (**(code **)(*in_ECX + 0x80))();
    FUN_00511d20();
    FUN_005118f0();
  }
  iVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  fVar2 = (float)(iVar5 - *param_1);
  if (iVar5 - *param_1 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  if (fVar2 <= fStack_4 * DAT_009b012c) {
    uVar11 = 0;
    uVar12 = 0;
    uVar10 = CONCAT44(fStack_4,auStack_4e + -6);
    puVar8 = auStack_3c;
    (**(code **)(*in_ECX + 0x80))(puVar8,auStack_4e + -6,fStack_4,0,0);
    FUN_00511d20();
    FUN_00511c00(puVar8,uVar10,uVar12,uVar11);
  }
  else {
    FUN_00401740(&DAT_009ba9c8,0x44);
    uVar12 = FUN_00404230(auStack_24);
    FUN_00796d50(uVar12);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return;
    }
    uVar11 = 0;
    uVar12 = 0;
    uVar10 = CONCAT44(fStack_4,fStack_4);
    puVar9 = auStack_4e + -6;
    puVar8 = auStack_3c;
    (**(code **)(*in_ECX + 0x80))(puVar8,puVar9,fStack_4,fStack_4,0,0);
    FUN_00511d20();
    FUN_00511b10(puVar8,puVar9,uVar10,uVar12,uVar11);
  }
  FUN_00543e30();
  piVar4 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar4 = (int *)(**(code **)(*piVar4 + 0x2c))();
  (**(code **)(*piVar4 + 0x10))();
  iVar5 = FUN_00543de0();
  if (iVar5 != 0) {
    FUN_00544390();
  }
  FUN_005438d0(0,0);
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = (**(code **)(*piVar4 + 0x1c))();
  if (iVar5 != 3) {
    piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
    iVar5 = (**(code **)(*piVar4 + 0x1c))();
    if (iVar5 != 2) {
      piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
      iVar5 = (**(code **)(*piVar4 + 4))();
      if (iVar5 != 2) {
        piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
        iVar5 = (**(code **)(*piVar4 + 4))();
        if (((iVar5 != 0) && (cVar3 = (**(code **)(*DAT_00b5ac1c + 0x18))(), cVar3 != '\0')) &&
           (2 < *(byte *)((int)param_1 + 0x12))) {
          fVar7 = (float10)FUN_004f56d0((char)param_1[2]);
          fStack_4 = (float)fVar7;
          FUN_0040d600();
          (**(code **)(*in_ECX + 100))
                    (auStack_44,*(undefined1 *)((int)param_1 + 10),*param_1,param_1[3],
                     (char)param_1[4],*(undefined1 *)((int)param_1 + 0x11),
                     *(undefined1 *)((int)param_1 + 0x12));
          piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
          piVar6 = (int *)(**(code **)(*in_ECX + 0x74))();
          bVar1 = *(byte *)((int)param_1 + 0x12);
          uVar12 = (**(code **)(*piVar4 + 8))();
          uVar12 = (**(code **)(*piVar6 + 0x34))(bVar1 - 3,0,uVar12);
          FUN_004dd240(7,uVar12);
        }
      }
    }
  }
  return;
}


// ==== FUN_00545440 @ 0x00545440 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00545440(int *param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *in_ECX;
  uint *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  float fVar10;
  float fVar11;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  uint auStack_20 [2];
  uint auStack_18 [3];
  undefined4 uStack_c;
  float fStack_4;
  
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = (**(code **)(*piVar4 + 0x24))();
  if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar4 + 0x24))(param_1);
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = *piVar4;
  uVar6 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar5 + 0x28))(uVar6);
  FUN_004f5730(auStack_18 + 1);
  auStack_18[0] = (uint)*(byte *)(param_1 + 3);
  auStack_20[0] = (uint)*(byte *)((int)param_1 + 10);
  auStack_20[1] = 0xe;
  FUN_0040d600(auStack_28,uStack_c);
  iVar5 = *(int *)((int)param_1 + 0xf) - *param_1;
  fStack_4 = (float)*(ushort *)((int)param_1 + 0xd) * DAT_009b3508;
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 == '\0') {
    uVar6 = 0;
    puVar8 = auStack_28;
    puVar9 = auStack_28 + -8;
    (**(code **)(*in_ECX + 0x80))(puVar9,puVar8,0);
    FUN_00511d20();
    FUN_005118f0(puVar9,puVar8,uVar6);
  }
  fVar11 = fStack_4;
  fVar10 = (float)iVar5;
  uVar6 = 1;
  if (iVar5 < 0) {
    fVar10 = fVar10 + _DAT_0099d104;
  }
  fVar10 = fVar10 * DAT_0099d0ec;
  puVar8 = auStack_28;
  puVar7 = auStack_20;
  fStack_4 = (float)iVar5;
  (**(code **)(*in_ECX + 0x80))(puVar7,puVar8,fVar10,1,fVar11);
  FUN_00511d20();
  FUN_00511c00(puVar7,puVar8,fVar10,uVar6,fVar11);
  FUN_00543f10(1);
  uVar2 = auStack_18[0];
  uVar1 = auStack_20[0];
  piVar4 = DAT_00b5a780;
  iVar5 = (**(code **)(*in_ECX + 0x80))();
  piVar4 = (int *)(**(code **)(*piVar4 + 8))(iVar5 + 0x14);
  if (piVar4 != (int *)0x0) {
    auStack_18[0] = CONCAT31(auStack_18[0]._1_3_,(char)uVar1);
    auStack_18[1] = 0xe;
    auStack_18[2] = uVar2;
    iVar5 = (**(code **)(*piVar4 + 0xc))(auStack_18);
    if (iVar5 != 0) {
      FUN_00544390(*(undefined4 *)(iVar5 + 300),*(undefined4 *)(iVar5 + 0x130),0);
    }
  }
  FUN_005438d0(0,0);
  return;
}


// ==== FUN_005455f0 @ 0x005455f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005455f0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *in_ECX;
  uint *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  float fVar10;
  float fVar11;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  uint auStack_20 [2];
  uint auStack_18 [3];
  undefined4 uStack_c;
  float fStack_4;
  
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = (**(code **)(*piVar4 + 0x24))();
  if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar4 + 0x24))(param_1);
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = *piVar4;
  uVar6 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar5 + 0x28))(uVar6);
  FUN_004f5730(auStack_18 + 1);
  auStack_18[0] = (uint)*(byte *)(param_1 + 3);
  auStack_20[0] = (uint)*(byte *)((int)param_1 + 10);
  auStack_20[1] = 0xc;
  FUN_0040d600(auStack_28,uStack_c);
  iVar5 = *(int *)((int)param_1 + 0xf) - *param_1;
  fStack_4 = (float)*(ushort *)((int)param_1 + 0xd) * DAT_009b3508;
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 == '\0') {
    uVar6 = 0;
    puVar8 = auStack_28;
    puVar9 = auStack_28 + -8;
    (**(code **)(*in_ECX + 0x80))(puVar9,puVar8,0);
    FUN_00511d20();
    FUN_005118f0(puVar9,puVar8,uVar6);
  }
  fVar11 = fStack_4;
  fVar10 = (float)iVar5;
  uVar6 = 1;
  if (iVar5 < 0) {
    fVar10 = fVar10 + _DAT_0099d104;
  }
  fVar10 = fVar10 * DAT_0099d0ec;
  puVar8 = auStack_28;
  puVar7 = auStack_20;
  fStack_4 = (float)iVar5;
  (**(code **)(*in_ECX + 0x80))(puVar7,puVar8,fVar10,1,fVar11);
  FUN_00511d20();
  FUN_00511c00(puVar7,puVar8,fVar10,uVar6,fVar11);
  FUN_00543f10(1);
  uVar2 = auStack_18[0];
  uVar1 = auStack_20[0];
  piVar4 = DAT_00b5a780;
  iVar5 = (**(code **)(*in_ECX + 0x80))();
  piVar4 = (int *)(**(code **)(*piVar4 + 8))(iVar5 + 0x14);
  if (piVar4 != (int *)0x0) {
    auStack_18[0] = CONCAT31(auStack_18[0]._1_3_,(char)uVar1);
    auStack_18[1] = 0xc;
    auStack_18[2] = uVar2;
    iVar5 = (**(code **)(*piVar4 + 0xc))(auStack_18);
    if (iVar5 != 0) {
      FUN_00544390(*(undefined4 *)(iVar5 + 300),*(undefined4 *)(iVar5 + 0x130),0);
    }
  }
  FUN_005438d0(0,0);
  return;
}


// ==== FUN_005457a0 @ 0x005457a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005457a0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *in_ECX;
  uint *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  float fVar10;
  float fVar11;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  uint auStack_20 [2];
  uint auStack_18 [3];
  undefined4 uStack_c;
  float fStack_4;
  
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = (**(code **)(*piVar4 + 0x24))();
  if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar4 + 0x24))(param_1);
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = *piVar4;
  uVar6 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar5 + 0x28))(uVar6);
  FUN_004f5730(auStack_18 + 1);
  auStack_18[0] = (uint)*(byte *)(param_1 + 3);
  auStack_20[0] = (uint)*(byte *)((int)param_1 + 10);
  auStack_20[1] = 0xd;
  FUN_0040d600(auStack_28,uStack_c);
  iVar5 = *(int *)((int)param_1 + 0xf) - *param_1;
  fStack_4 = (float)*(ushort *)((int)param_1 + 0xd) * DAT_009b3508;
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 == '\0') {
    uVar6 = 0;
    puVar8 = auStack_28;
    puVar9 = auStack_28 + -8;
    (**(code **)(*in_ECX + 0x80))(puVar9,puVar8,0);
    FUN_00511d20();
    FUN_005118f0(puVar9,puVar8,uVar6);
  }
  fVar11 = fStack_4;
  fVar10 = (float)iVar5;
  uVar6 = 1;
  if (iVar5 < 0) {
    fVar10 = fVar10 + _DAT_0099d104;
  }
  fVar10 = fVar10 * DAT_0099d0ec;
  puVar8 = auStack_28;
  puVar7 = auStack_20;
  fStack_4 = (float)iVar5;
  (**(code **)(*in_ECX + 0x80))(puVar7,puVar8,fVar10,1,fVar11);
  FUN_00511d20();
  FUN_00511c00(puVar7,puVar8,fVar10,uVar6,fVar11);
  FUN_00543f10(1);
  uVar2 = auStack_18[0];
  uVar1 = auStack_20[0];
  piVar4 = DAT_00b5a780;
  iVar5 = (**(code **)(*in_ECX + 0x80))();
  piVar4 = (int *)(**(code **)(*piVar4 + 8))(iVar5 + 0x14);
  if (piVar4 != (int *)0x0) {
    auStack_18[0] = CONCAT31(auStack_18[0]._1_3_,(char)uVar1);
    auStack_18[1] = 0xd;
    auStack_18[2] = uVar2;
    iVar5 = (**(code **)(*piVar4 + 0xc))(auStack_18);
    if (iVar5 != 0) {
      FUN_00544390(*(undefined4 *)(iVar5 + 300),*(undefined4 *)(iVar5 + 0x130),0);
    }
  }
  FUN_005438d0(0,0);
  return;
}


// ==== FUN_00545950 @ 0x00545950 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00545950(int param_1)

{
  uint uVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *in_ECX;
  uint *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  float fVar10;
  undefined4 uVar11;
  undefined1 auStack_44 [2];
  undefined1 auStack_42 [6];
  uint auStack_3c [2];
  int aiStack_34 [3];
  undefined4 uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  uint uStack_c;
  int iStack_4;
  
  piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar4 = (**(code **)(*piVar3 + 0x24))();
  if (*(int **)(iVar4 + 0x4c) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar3 + 0x24))(param_1);
  piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar4 = *piVar3;
  uVar5 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar4 + 0x28))(uVar5);
  FUN_004f5730(aiStack_34 + 1);
  FUN_0040d600(auStack_44,uStack_28);
  iVar4 = FUN_00508200(param_1);
  FUN_00543830(param_1);
  bVar2 = FUN_005081a0(param_1);
  if (bVar2 == 0xff) {
    bVar2 = *(byte *)(param_1 + 10);
  }
  auStack_3c[0] = (uint)bVar2;
  auStack_3c[1] = 0x20;
  aiStack_34[0] = 0;
  aiStack_34[0] = FUN_005081d0(param_1);
  auStack_3c[1] = 10;
  if (*(int *)(param_1 + 0xf) == 1) {
    aiStack_34[0] = aiStack_34[0] + 10000;
  }
  uVar5 = 0;
  puVar8 = auStack_44;
  puVar9 = auStack_44 + -8;
  (**(code **)(*in_ECX + 0x80))(puVar9,puVar8,0);
  FUN_00511d20();
  FUN_005118f0(puVar9,puVar8,uVar5);
  uVar11 = 0;
  fVar10 = (float)iVar4;
  uVar5 = 0;
  if (iVar4 < 0) {
    fVar10 = fVar10 + _DAT_0099d104;
  }
  fVar10 = fVar10 * DAT_0099d0ec;
  puVar8 = auStack_44;
  puVar7 = auStack_3c;
  iStack_4 = iVar4;
  (**(code **)(*in_ECX + 0x80))(puVar7,puVar8,fVar10,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar7,puVar8,fVar10,uVar5,uVar11);
  FUN_00401740(s__SKILLACTION__style__u__serial___009baa10,0x2a);
  uVar5 = FUN_00797530(auStack_24);
  FUN_00796d50(uVar5);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  FUN_00543f10(0);
  iVar4 = aiStack_34[0];
  uVar1 = auStack_3c[0];
  piVar3 = DAT_00b5a780;
  iVar6 = (**(code **)(*in_ECX + 0x80))();
  piVar3 = (int *)(**(code **)(*piVar3 + 8))(iVar6 + 0x14);
  if (piVar3 != (int *)0x0) {
    aiStack_34[0] = CONCAT31(aiStack_34[0]._1_3_,(char)uVar1);
    aiStack_34[1] = 10;
    aiStack_34[2] = iVar4;
    iVar4 = (**(code **)(*piVar3 + 0xc))(aiStack_34);
    if (iVar4 != 0) {
      FUN_00544390(*(undefined4 *)(iVar4 + 300),*(undefined4 *)(iVar4 + 0x130),1);
    }
  }
  FUN_005438d0(1,1);
  return;
}


// ==== FUN_00545b60 @ 0x00545b60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00545b60(int param_1)

{
  short sVar1;
  byte bVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int *in_ECX;
  undefined2 extraout_var;
  uint *puVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  undefined1 *puVar12;
  float fVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined1 auStack_48 [2];
  undefined1 auStack_46 [6];
  uint auStack_40 [3];
  undefined1 auStack_34 [8];
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_8;
  
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = (**(code **)(*piVar4 + 0x24))();
  if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar4 + 0x24))(param_1);
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = *piVar4;
  uVar6 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar5 + 0x28))(uVar6);
  piVar4 = (int *)(**(code **)(*DAT_00b5acc0 + 0x1c))
                            (CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0xc)));
  if (piVar4 != (int *)0x0) {
    FUN_004f5730(auStack_34);
    FUN_0040d600(auStack_48,uStack_2c);
    iVar7 = (**(code **)(*piVar4 + 4))();
    iVar7 = *(int *)(iVar7 + 0x2ba0);
    iVar8 = (**(code **)(*piVar4 + 4))();
    sVar1 = *(short *)(iVar8 + 0x2b90);
    uVar15 = CONCAT22((short)((uint)iVar5 >> 0x10),sVar1);
    iVar5 = (**(code **)(*piVar4 + 4))();
    uStack_8 = CONCAT22(uStack_8._2_2_,*(undefined2 *)(iVar5 + 0x2b92));
    iVar5 = (**(code **)(*piVar4 + 4))();
    uVar6 = *(undefined4 *)(iVar5 + 0x2b94);
    if ((sVar1 != 0) && ((short)uStack_8 != 0)) {
      uVar14 = 1;
      uVar11 = uStack_8;
      FUN_005433a0(uVar15,uStack_8,uVar6,1);
      FUN_00543630(uVar15,uVar11,uVar6,uVar14);
    }
    iVar5 = (**(code **)(*piVar4 + 4))();
    bVar2 = *(byte *)(iVar5 + 0x2b99);
    if (bVar2 == 0xff) {
      bVar2 = *(byte *)(param_1 + 10);
    }
    auStack_40[0] = (uint)bVar2;
    auStack_40[1] = 0x20;
    auStack_40[2] = 0;
    iVar5 = (**(code **)(*piVar4 + 4))();
    auStack_40[2] = *(int *)(iVar5 + 0x2b9c);
    auStack_40[1] = 10;
    if (*(int *)(param_1 + 0xf) == 1) {
      auStack_40[2] = auStack_40[2] + 10000;
    }
    uVar6 = 0;
    puVar10 = auStack_48;
    puVar12 = auStack_48 + -8;
    (**(code **)(*in_ECX + 0x80))(puVar12,puVar10,0);
    FUN_00511d20();
    FUN_005118f0(puVar12,puVar10,uVar6);
    fVar13 = (float)iVar7;
    uVar15 = 0;
    uVar6 = 0;
    if (iVar7 < 0) {
      fVar13 = fVar13 + _DAT_0099d104;
    }
    fVar13 = fVar13 * DAT_0099d0ec;
    puVar10 = auStack_48;
    puVar9 = auStack_40;
    (**(code **)(*in_ECX + 0x80))(puVar9,puVar10,fVar13,0,0);
    FUN_00511d20();
    FUN_00511c00(puVar9,puVar10,fVar13,uVar6,uVar15);
    FUN_00401740(s__SKILLACTION__style__u__serial___009baa3c,0x2a);
    uVar6 = FUN_00797530(auStack_28);
    FUN_00796d50(uVar6);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    FUN_00543f10(0);
    iVar5 = FUN_00543de0(auStack_40[0],10,auStack_40[2]);
    if (iVar5 != 0) {
      FUN_00544390(*(undefined4 *)(iVar5 + 300),*(undefined4 *)(iVar5 + 0x130),1);
    }
    FUN_005438d0(1,1);
    cVar3 = (**(code **)(*in_ECX + 4))();
    if (cVar3 != '\0') {
      uStack_10 = 0xf;
      uStack_14 = 0;
      pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      FUN_00401740(s_SKILL_READY_009baa68,0xb);
      FUN_00796d50(auStack_28);
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00545e00 @ 0x00545e00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00545e00(int param_1)

{
  short sVar1;
  byte bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  uint extraout_EAX;
  uint uVar8;
  uint extraout_EAX_00;
  int *in_ECX;
  undefined2 extraout_var;
  uint *puVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  undefined1 *puVar12;
  float fVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined1 auStack_48 [2];
  undefined1 auStack_46 [6];
  uint auStack_40 [3];
  undefined1 auStack_34 [8];
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_8;
  
  piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar4 = (**(code **)(*piVar3 + 0x24))();
  if (*(int **)(iVar4 + 0x4c) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar3 + 0x24))(param_1);
  piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar4 = *piVar3;
  uVar5 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar4 + 0x28))(uVar5);
  piVar3 = (int *)(**(code **)(*DAT_00b5acc0 + 0x1c))
                            (CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0xc)));
  if (piVar3 == (int *)0x0) {
    return 1;
  }
  FUN_004f5730(auStack_34);
  FUN_0040d600(auStack_48,uStack_2c);
  iVar6 = (**(code **)(*piVar3 + 4))();
  iVar6 = *(int *)(iVar6 + 0x2bb4);
  iVar7 = (**(code **)(*piVar3 + 4))();
  sVar1 = *(short *)(iVar7 + 0x2ba4);
  uVar15 = CONCAT22((short)((uint)iVar4 >> 0x10),sVar1);
  iVar4 = (**(code **)(*piVar3 + 4))();
  uStack_8 = CONCAT22(uStack_8._2_2_,*(undefined2 *)(iVar4 + 0x2ba6));
  iVar4 = (**(code **)(*piVar3 + 4))();
  uVar5 = *(undefined4 *)(iVar4 + 0x2ba8);
  if ((sVar1 != 0) && ((short)uStack_8 != 0)) {
    uVar14 = 0;
    uVar11 = uStack_8;
    FUN_005433a0(uVar15,uStack_8,uVar5,0);
    FUN_00543630(uVar15,uVar11,uVar5,uVar14);
  }
  iVar4 = (**(code **)(*piVar3 + 4))();
  bVar2 = *(byte *)(iVar4 + 0x2bad);
  if (bVar2 == 0xff) {
    bVar2 = *(byte *)(param_1 + 10);
  }
  auStack_40[0] = (uint)bVar2;
  auStack_40[1] = 0x20;
  auStack_40[2] = 0;
  iVar4 = (**(code **)(*piVar3 + 4))();
  auStack_40[2] = *(int *)(iVar4 + 0x2bb0);
  auStack_40[1] = 10;
  if (*(int *)(param_1 + 0xf) == 1) {
    auStack_40[2] = auStack_40[2] + 10000;
  }
  uVar5 = 0;
  puVar10 = auStack_48;
  puVar12 = auStack_48 + -8;
  (**(code **)(*in_ECX + 0x80))(puVar12,puVar10,0);
  FUN_00511d20();
  FUN_005118f0(puVar12,puVar10,uVar5);
  fVar13 = (float)iVar6;
  uVar15 = 0;
  uVar5 = 0;
  if (iVar6 < 0) {
    fVar13 = fVar13 + _DAT_0099d104;
  }
  fVar13 = fVar13 * DAT_0099d0ec;
  puVar10 = auStack_48;
  puVar9 = auStack_40;
  (**(code **)(*in_ECX + 0x80))(puVar9,puVar10,fVar13,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar9,puVar10,fVar13,uVar5,uVar15);
  FUN_00401740(s__SKILLACTION__style__u__serial___009baa74,0x2a);
  uVar5 = FUN_00797530(auStack_28);
  FUN_00796d50(uVar5);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return extraout_EAX;
  }
  FUN_00543f10(0);
  iVar4 = FUN_00543de0(auStack_40[0],10,auStack_40[2]);
  if (iVar4 != 0) {
    FUN_00544390(*(undefined4 *)(iVar4 + 300),*(undefined4 *)(iVar4 + 0x130),1);
  }
  FUN_005438d0(1,1);
  uVar8 = (**(code **)(*in_ECX + 4))();
  if ((char)uVar8 != '\0') {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_SKILL_CHARGE_009baaa0,0xc);
    uVar8 = FUN_00796d50(auStack_28);
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return extraout_EAX_00;
    }
  }
  return uVar8 & 0xffffff00;
}


// ==== FUN_005460b0 @ 0x005460b0 ====

void FUN_005460b0(int param_1,undefined4 param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  float10 fVar5;
  char unaff_retaddr;
  uint *puVar6;
  undefined1 *puVar7;
  float fVar8;
  ulonglong uVar9;
  undefined8 uVar10;
  undefined1 auStack_44 [2];
  undefined1 auStack_42 [6];
  uint auStack_3c [2];
  int aiStack_34 [3];
  undefined4 uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  uint uStack_c;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar3 = (**(code **)(*piVar2 + 0x24))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar2 + 0x24))(param_1);
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar3 = *piVar2;
  uVar4 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar3 + 0x28))(uVar4);
  FUN_004f5730();
  auStack_3c[0] = (uint)*(byte *)(param_1 + 10);
  auStack_3c[1] = 10;
  aiStack_34[0] = param_1;
  if (unaff_retaddr != '\x01') {
    aiStack_34[0] = param_1 + 10000;
  }
  FUN_0040d600(auStack_44,uStack_28);
  fVar5 = (float10)FUN_00543a20(auStack_3c[0],0xf,aiStack_34[0]);
  fVar8 = (float)fVar5;
  uVar9 = ZEXT48(auStack_44);
  puVar7 = auStack_44 + -8;
  (**(code **)(*in_ECX + 0x80))(puVar7,auStack_44,0);
  FUN_00511d20();
  FUN_005118f0(puVar7,uVar9);
  uVar10 = 0;
  puVar7 = auStack_44;
  puVar6 = auStack_3c;
  (**(code **)(*in_ECX + 0x80))(puVar6,puVar7,fVar8,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar6,puVar7,fVar8,uVar10);
  FUN_00401740(s__SKILLACTION__style__u__serial___009baab0,0x2a);
  uVar4 = FUN_00797530(auStack_24);
  FUN_00796d50(uVar4);
  if (0xf < uStack_c) {
    _free(pvStack_20);
    return;
  }
  piVar2 = (int *)(**(code **)(*in_ECX + 0x80))();
  uVar4 = (**(code **)(*piVar2 + 4))();
  FUN_004dd240(0x14,param_2,0,0,uVar4);
  FUN_00543f10();
  iVar3 = aiStack_34[0];
  uVar1 = auStack_3c[0];
  piVar2 = DAT_00b5a780;
  (**(code **)(*in_ECX + 0x80))();
  piVar2 = (int *)(**(code **)(*piVar2 + 8))();
  if (piVar2 != (int *)0x0) {
    aiStack_34[0] = CONCAT31(aiStack_34[0]._1_3_,(char)uVar1);
    aiStack_34[1] = 10;
    aiStack_34[2] = iVar3;
    iVar3 = (**(code **)(*piVar2 + 0xc))(aiStack_34);
    if (iVar3 != 0) {
      FUN_00544390(*(undefined4 *)(iVar3 + 300),*(undefined4 *)(iVar3 + 0x130),1);
    }
  }
  FUN_005438d0(1,1);
  return;
}


// ==== FUN_005462d0 @ 0x005462d0 ====

void FUN_005462d0(int param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  float10 fVar6;
  byte unaff_retaddr;
  uint *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  float fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  uint auStack_20 [2];
  uint auStack_18 [3];
  undefined4 uStack_c;
  float fStack_4;
  
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 == '\0') {
    piVar4 = (int *)(**(code **)(*in_ECX + 0x7c))();
    iVar5 = (**(code **)(*piVar4 + 0xc))();
    if (iVar5 == 0) {
      uVar12 = 1;
      (**(code **)(*in_ECX + 0x80))(1);
      FUN_00511ea0(uVar12);
    }
  }
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = (**(code **)(*piVar4 + 0x24))();
  if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar4 + 0x24))(param_1);
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = *piVar4;
  uVar12 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar5 + 0x28))(uVar12);
  FUN_004f5730(auStack_18 + 1);
  auStack_18[0] = (uint)unaff_retaddr;
  auStack_20[0] = (uint)*(byte *)(param_1 + 10);
  auStack_20[1] = 0x11;
  FUN_0040d600(auStack_28,uStack_c);
  fVar6 = (float10)FUN_00543a20(0,0x11,0);
  fStack_4 = (float)fVar6;
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 == '\0') {
    iVar5 = (**(code **)(*in_ECX + 0x78))();
    uVar12 = *(undefined4 *)(iVar5 + 0x30);
    puVar8 = auStack_28;
    puVar9 = auStack_28 + -8;
    (**(code **)(*in_ECX + 0x80))(puVar9,puVar8,uVar12);
    FUN_00511d20();
    FUN_005118f0(puVar9,puVar8,uVar12);
  }
  uVar11 = 0;
  uVar12 = 0;
  puVar8 = auStack_28;
  puVar7 = auStack_20;
  fVar10 = fStack_4;
  (**(code **)(*in_ECX + 0x80))(puVar7,puVar8,fStack_4,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar7,puVar8,fVar10,uVar12,uVar11);
  FUN_00543f10(0);
  uVar2 = auStack_18[0];
  uVar1 = auStack_20[0];
  piVar4 = DAT_00b5a780;
  iVar5 = (**(code **)(*in_ECX + 0x80))();
  piVar4 = (int *)(**(code **)(*piVar4 + 8))(iVar5 + 0x14);
  if (piVar4 != (int *)0x0) {
    auStack_18[0] = CONCAT31(auStack_18[0]._1_3_,(char)uVar1);
    auStack_18[1] = 0x11;
    auStack_18[2] = uVar2;
    iVar5 = (**(code **)(*piVar4 + 0xc))(auStack_18);
    if (iVar5 != 0) {
      FUN_00544390(*(undefined4 *)(iVar5 + 300),*(undefined4 *)(iVar5 + 0x130),0);
    }
  }
  return;
}


// ==== FUN_00546490 @ 0x00546490 ====

void FUN_00546490(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  FUN_00543f10(0);
  piVar2 = DAT_00b5a780;
  iVar1 = (**(code **)(*in_ECX + 0x80))();
  piVar2 = (int *)(**(code **)(*piVar2 + 8))(iVar1 + 0x14);
  if (piVar2 != (int *)0x0) {
    iVar1 = (**(code **)(*piVar2 + 0xc))(auStack_a + -6);
    if (iVar1 != 0) {
      FUN_00544390(*(undefined4 *)(iVar1 + 300),*(undefined4 *)(iVar1 + 0x130),0);
    }
  }
  return;
}


// ==== FUN_00546510 @ 0x00546510 ====

void FUN_00546510(int param_1)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  float10 fVar5;
  uint *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  float fVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined1 auStack_2a [2];
  undefined1 auStack_28 [8];
  uint auStack_20 [2];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_4;
  
  cVar2 = (**(code **)(*in_ECX + 4))();
  if (cVar2 == '\0') {
    piVar3 = (int *)(**(code **)(*in_ECX + 0x7c))();
    iVar4 = (**(code **)(*piVar3 + 0xc))();
    if (iVar4 == 0) {
      uVar11 = 1;
      (**(code **)(*in_ECX + 0x80))(1);
      FUN_00511ea0(uVar11);
    }
  }
  piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar4 = (**(code **)(*piVar3 + 0x24))();
  if (*(int **)(iVar4 + 0x4c) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar3 + 0x24))(param_1);
  piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar4 = *piVar3;
  uVar11 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar4 + 0x28))(uVar11);
  FUN_004f5730(&uStack_14);
  auStack_20[0] = (uint)*(byte *)(param_1 + 10);
  uStack_18 = 0;
  auStack_20[1] = 0x12;
  FUN_0040d600(auStack_28,uStack_c);
  fVar5 = (float10)FUN_00543a20(0,0x12,0);
  fVar9 = (float)fVar5;
  cVar2 = (**(code **)(*in_ECX + 4))();
  if (cVar2 == '\0') {
    iVar4 = (**(code **)(*in_ECX + 0x78))();
    uVar11 = *(undefined4 *)(iVar4 + 0x30);
    puVar7 = auStack_28;
    puVar8 = auStack_2a + -6;
    uStack_4 = uVar11;
    (**(code **)(*in_ECX + 0x80))(puVar8,puVar7,uVar11);
    FUN_00511d20();
    FUN_005118f0(puVar8,puVar7,uVar11);
  }
  uVar10 = 0;
  uVar11 = 0;
  puVar7 = auStack_28;
  puVar6 = auStack_20;
  (**(code **)(*in_ECX + 0x80))(puVar6,puVar7,fVar9,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar6,puVar7,fVar9,uVar11,uVar10);
  FUN_00546490(auStack_20);
  FUN_00543f10(0);
  uVar11 = uStack_18;
  uVar1 = auStack_20[0];
  piVar3 = DAT_00b5a780;
  iVar4 = (**(code **)(*in_ECX + 0x80))();
  piVar3 = (int *)(**(code **)(*piVar3 + 8))(iVar4 + 0x14);
  if (piVar3 != (int *)0x0) {
    uStack_18 = CONCAT31(uStack_18._1_3_,(char)uVar1);
    uStack_14 = 0x12;
    uStack_10 = uVar11;
    iVar4 = (**(code **)(*piVar3 + 0xc))(&uStack_18);
    if (iVar4 != 0) {
      FUN_00544390(*(undefined4 *)(iVar4 + 300),*(undefined4 *)(iVar4 + 0x130),0);
    }
  }
  return;
}


// ==== FUN_005466e0 @ 0x005466e0 ====

void FUN_005466e0(int param_1)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  int *in_ECX;
  float10 fVar7;
  byte unaff_retaddr;
  uint *puVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  float fVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  uint auStack_20 [2];
  uint auStack_18 [3];
  undefined4 uStack_c;
  float fStack_4;
  
  cVar4 = (**(code **)(*in_ECX + 4))();
  if (cVar4 == '\0') {
    piVar5 = (int *)(**(code **)(*in_ECX + 0x7c))();
    iVar6 = (**(code **)(*piVar5 + 0xc))();
    if (iVar6 == 0) {
      uVar13 = 1;
      (**(code **)(*in_ECX + 0x80))(1);
      FUN_00511ea0(uVar13);
    }
  }
  piVar5 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar6 = (**(code **)(*piVar5 + 0x24))();
  if (*(int **)(iVar6 + 0x4c) == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(**(int **)(iVar6 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar5 + 0x24))(param_1);
  piVar5 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar6 = *piVar5;
  uVar13 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar6 + 0x28))(uVar13);
  FUN_004f5730(auStack_18 + 1);
  auStack_18[0] = (uint)unaff_retaddr;
  auStack_20[0] = (uint)*(byte *)(param_1 + 10);
  auStack_20[1] = 0x15;
  FUN_0040d600(auStack_28,uStack_c);
  fVar7 = (float10)FUN_00543a20(0x17,0x15,auStack_18[0]);
  fStack_4 = (float)fVar7;
  cVar4 = (**(code **)(*in_ECX + 4))();
  if (cVar4 == '\0') {
    iVar6 = (**(code **)(*in_ECX + 0x78))();
    uVar13 = *(undefined4 *)(iVar6 + 0x30);
    puVar9 = auStack_28;
    puVar10 = auStack_28 + -8;
    (**(code **)(*in_ECX + 0x80))(puVar10,puVar9,uVar13);
    FUN_00511d20();
    FUN_005118f0(puVar10,puVar9,uVar13);
  }
  uVar1 = *(undefined1 *)(param_1 + 0xc);
  uVar13 = (**(code **)(*DAT_00b5a97c + 0xc))();
  FUN_004dd240(0x16,200,1,uVar1,uVar13);
  uVar12 = 0;
  uVar13 = 0;
  puVar9 = auStack_28;
  puVar8 = auStack_20;
  fVar11 = fStack_4;
  (**(code **)(*in_ECX + 0x80))(puVar8,puVar9,fStack_4,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar8,puVar9,fVar11,uVar13,uVar12);
  FUN_00543f10(0);
  uVar3 = auStack_18[0];
  uVar2 = auStack_20[0];
  piVar5 = DAT_00b5a780;
  iVar6 = (**(code **)(*in_ECX + 0x80))();
  piVar5 = (int *)(**(code **)(*piVar5 + 8))(iVar6 + 0x14);
  if (piVar5 != (int *)0x0) {
    auStack_18[0] = CONCAT31(auStack_18[0]._1_3_,(char)uVar2);
    auStack_18[1] = 0x15;
    auStack_18[2] = uVar3;
    iVar6 = (**(code **)(*piVar5 + 0xc))(auStack_18);
    if (iVar6 != 0) {
      FUN_00544390(*(undefined4 *)(iVar6 + 300),*(undefined4 *)(iVar6 + 0x130),0);
    }
  }
  return;
}


// ==== FUN_005468c0 @ 0x005468c0 ====

void FUN_005468c0(int param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  float10 fVar6;
  byte unaff_retaddr;
  uint *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  float fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  uint auStack_20 [2];
  uint auStack_18 [3];
  undefined4 uStack_c;
  float fStack_4;
  
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 == '\0') {
    piVar4 = (int *)(**(code **)(*in_ECX + 0x7c))();
    iVar5 = (**(code **)(*piVar4 + 0xc))();
    if (iVar5 == 0) {
      uVar12 = 1;
      (**(code **)(*in_ECX + 0x80))(1);
      FUN_00511ea0(uVar12);
    }
  }
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = (**(code **)(*piVar4 + 0x24))();
  if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar4 + 0x24))(param_1);
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = *piVar4;
  uVar12 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar5 + 0x28))(uVar12);
  FUN_004f5730(auStack_18 + 1);
  auStack_18[0] = (uint)unaff_retaddr;
  auStack_20[0] = (uint)*(byte *)(param_1 + 10);
  auStack_20[1] = 0x16;
  FUN_0040d600(auStack_28,uStack_c);
  fVar6 = (float10)FUN_00543a20(0x17,0x16,auStack_18[0]);
  fStack_4 = (float)fVar6;
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 == '\0') {
    iVar5 = (**(code **)(*in_ECX + 0x78))();
    uVar12 = *(undefined4 *)(iVar5 + 0x30);
    puVar8 = auStack_28;
    puVar9 = auStack_28 + -8;
    (**(code **)(*in_ECX + 0x80))(puVar9,puVar8,uVar12);
    FUN_00511d20();
    FUN_005118f0(puVar9,puVar8,uVar12);
  }
  uVar11 = 0;
  uVar12 = 0;
  puVar8 = auStack_28;
  puVar7 = auStack_20;
  fVar10 = fStack_4;
  (**(code **)(*in_ECX + 0x80))(puVar7,puVar8,fStack_4,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar7,puVar8,fVar10,uVar12,uVar11);
  FUN_00543f10(0);
  uVar2 = auStack_18[0];
  uVar1 = auStack_20[0];
  piVar4 = DAT_00b5a780;
  iVar5 = (**(code **)(*in_ECX + 0x80))();
  piVar4 = (int *)(**(code **)(*piVar4 + 8))(iVar5 + 0x14);
  if (piVar4 != (int *)0x0) {
    auStack_18[0] = CONCAT31(auStack_18[0]._1_3_,(char)uVar1);
    auStack_18[1] = 0x16;
    auStack_18[2] = uVar2;
    iVar5 = (**(code **)(*piVar4 + 0xc))(auStack_18);
    if (iVar5 != 0) {
      FUN_00544390(*(undefined4 *)(iVar5 + 300),*(undefined4 *)(iVar5 + 0x130),0);
    }
  }
  return;
}


// ==== FUN_00546a80 @ 0x00546a80 ====

void FUN_00546a80(int param_1)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  float10 fVar6;
  byte unaff_retaddr;
  uint *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  float fVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  uint auStack_20 [2];
  uint auStack_18 [3];
  undefined4 uStack_c;
  float fStack_4;
  
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 == '\0') {
    piVar4 = (int *)(**(code **)(*in_ECX + 0x7c))();
    iVar5 = (**(code **)(*piVar4 + 0xc))();
    if (iVar5 == 0) {
      uVar12 = 1;
      (**(code **)(*in_ECX + 0x80))(1);
      FUN_00511ea0(uVar12);
    }
  }
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = (**(code **)(*piVar4 + 0x24))();
  if (*(int **)(iVar5 + 0x4c) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(iVar5 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar4 + 0x24))(param_1);
  piVar4 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar5 = *piVar4;
  uVar12 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar5 + 0x28))(uVar12);
  FUN_004f5730(auStack_18 + 1);
  auStack_18[0] = (uint)unaff_retaddr;
  auStack_20[0] = (uint)*(byte *)(param_1 + 10);
  auStack_20[1] = 0x17;
  FUN_0040d600(auStack_28,uStack_c);
  fVar6 = (float10)FUN_00543a20(0x17,0x17,auStack_18[0]);
  fStack_4 = (float)fVar6;
  cVar3 = (**(code **)(*in_ECX + 4))();
  if (cVar3 == '\0') {
    iVar5 = (**(code **)(*in_ECX + 0x78))();
    uVar12 = *(undefined4 *)(iVar5 + 0x30);
    puVar8 = auStack_28;
    puVar9 = auStack_28 + -8;
    (**(code **)(*in_ECX + 0x80))(puVar9,puVar8,uVar12);
    FUN_00511d20();
    FUN_005118f0(puVar9,puVar8,uVar12);
  }
  uVar11 = 0;
  uVar12 = 0;
  puVar8 = auStack_28;
  puVar7 = auStack_20;
  fVar10 = fStack_4;
  (**(code **)(*in_ECX + 0x80))(puVar7,puVar8,fStack_4,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar7,puVar8,fVar10,uVar12,uVar11);
  FUN_00543f10(0);
  uVar2 = auStack_18[0];
  uVar1 = auStack_20[0];
  piVar4 = DAT_00b5a780;
  iVar5 = (**(code **)(*in_ECX + 0x80))();
  piVar4 = (int *)(**(code **)(*piVar4 + 8))(iVar5 + 0x14);
  if (piVar4 != (int *)0x0) {
    auStack_18[0] = CONCAT31(auStack_18[0]._1_3_,(char)uVar1);
    auStack_18[1] = 0x17;
    auStack_18[2] = uVar2;
    iVar5 = (**(code **)(*piVar4 + 0xc))(auStack_18);
    if (iVar5 != 0) {
      FUN_00544390(*(undefined4 *)(iVar5 + 300),*(undefined4 *)(iVar5 + 0x130),0);
    }
  }
  return;
}


// ==== FUN_00546c40 @ 0x00546c40 ====

void FUN_00546c40(undefined4 param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bab44;
  in_ECX[1] = param_1;
  iVar1 = FUN_00547060();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x21) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  return;
}


// ==== FUN_00546c90 @ 0x00546c90 ====

void FUN_00546c90(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  float10 fVar4;
  uint *puVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  float fVar8;
  undefined4 uVar9;
  int local_34;
  undefined4 local_30;
  uint local_2c;
  undefined1 auStack_28 [8];
  uint auStack_20 [3];
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 uStack_c;
  float fStack_4;
  
  local_34 = 0;
  local_30 = 0;
  local_2c = local_2c & 0xffffff00;
  FUN_005433d0(&local_2c,&local_34,&local_30);
  if (local_34 != 0) {
    FUN_005460b0(param_1,local_2c,local_34,local_30);
    return;
  }
  piVar1 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar2 = (**(code **)(*piVar1 + 0x24))();
  if (*(int **)(iVar2 + 0x4c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar1 + 0x24))(param_1);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar2 = *piVar1;
  uVar3 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar2 + 0x28))(uVar3);
  FUN_004f5730(&uStack_14);
  auStack_20[2] = (uint)*(byte *)(param_1 + 0xc);
  auStack_20[0] = (uint)*(byte *)(param_1 + 10);
  local_30 = uStack_14;
  auStack_20[1] = 0xf;
  local_2c = uStack_10;
  FUN_0040d600(auStack_28,uStack_c);
  fVar4 = (float10)FUN_00543a20(auStack_20[0],0xf,auStack_20[2]);
  fStack_4 = (float)fVar4;
  uVar3 = 0;
  puVar6 = auStack_28;
  puVar7 = &local_30;
  (**(code **)(*in_ECX + 0x80))(puVar7,puVar6,0);
  FUN_00511d20();
  FUN_005118f0(puVar7,puVar6,uVar3);
  uVar9 = 0;
  uVar3 = 0;
  puVar6 = auStack_28;
  puVar5 = auStack_20;
  fVar8 = fStack_4;
  (**(code **)(*in_ECX + 0x80))(puVar5,puVar6,fStack_4,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar5,puVar6,fVar8,uVar3,uVar9);
  FUN_00543f10(0);
  iVar2 = FUN_00543de0(auStack_20[0],0xf,auStack_20[2]);
  if (iVar2 != 0) {
    FUN_00544390(*(undefined4 *)(iVar2 + 300),*(undefined4 *)(iVar2 + 0x130),0);
  }
  FUN_005438d0(0,0);
  return;
}


// ==== FUN_00546e30 @ 0x00546e30 ====

void FUN_00546e30(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  float10 fVar5;
  byte unaff_retaddr;
  uint *puVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  float fVar9;
  undefined4 uVar10;
  undefined1 auStack_28 [2];
  undefined1 auStack_26 [6];
  uint auStack_20 [3];
  undefined1 auStack_14 [8];
  undefined4 uStack_c;
  float fStack_4;
  
  cVar1 = (**(code **)(*in_ECX + 4))();
  if (cVar1 == '\0') {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x7c))();
    iVar3 = (**(code **)(*piVar2 + 0xc))();
    if (iVar3 == 0) {
      (**(code **)(*in_ECX + 0x80))();
      FUN_00511ea0();
    }
  }
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar3 = (**(code **)(*piVar2 + 0x24))();
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar2 + 0x24))(param_1);
  piVar2 = (int *)(**(code **)(*in_ECX + 0x74))();
  iVar3 = *piVar2;
  uVar4 = (**(code **)(*in_ECX + 0x80))();
  (**(code **)(iVar3 + 0x28))(uVar4);
  FUN_004f5730(auStack_14);
  auStack_20[0] = (uint)*(byte *)(param_1 + 10);
  auStack_20[1] = 0x1f;
  auStack_20[2] = (uint)unaff_retaddr;
  FUN_0040d600(auStack_28,uStack_c);
  fVar5 = (float10)FUN_00543a20(0,0x1f,(uint)unaff_retaddr);
  fStack_4 = (float)fVar5;
  cVar1 = (**(code **)(*in_ECX + 4))();
  if (cVar1 == '\0') {
    iVar3 = (**(code **)(*in_ECX + 0x78))();
    uVar4 = *(undefined4 *)(iVar3 + 0x30);
    puVar7 = auStack_28;
    puVar8 = auStack_28 + -8;
    (**(code **)(*in_ECX + 0x80))(puVar8,puVar7,uVar4);
    FUN_00511d20();
    FUN_005118f0(puVar8,puVar7,uVar4);
  }
  uVar10 = 0;
  uVar4 = 0;
  puVar7 = auStack_28;
  puVar6 = auStack_20;
  fVar9 = fStack_4;
  (**(code **)(*in_ECX + 0x80))(puVar6,puVar7,fStack_4,0,0);
  FUN_00511d20();
  FUN_00511c00(puVar6,puVar7,fVar9,uVar4,uVar10);
  FUN_00546490(auStack_20);
  return;
}


// ==== FUN_00546f90 @ 0x00546f90 ====

void FUN_00546f90(void *param_1)

{
  if (*(char *)((int)param_1 + 0x21) == '\0') {
    FUN_00546f90(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00546fd0 @ 0x00546fd0 ====

void * FUN_00546fd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981970;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x24);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_0065ddc0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@00547045 @ 0x00547045 ====

void Catch_00547045(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00547060 @ 0x00547060 ====

void FUN_00547060(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981980;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x24);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 8) = 1;
  *(undefined1 *)((int)puVar1 + 0x21) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@005470ea @ 0x005470ea ====

void Catch_005470ea(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00547100 @ 0x00547100 ====

void FUN_00547100(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0xcccccca < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00546fd0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[8] == '\0') {
LAB_00547205:
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
      if ((char)piVar6[8] == '\0') goto LAB_00547205;
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


// ==== FUN_005472e0 @ 0x005472e0 ====

void FUN_005472e0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00546f90(piVar6[1]);
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
    FUN_0057e890(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_005473a0 @ 0x005473a0 ====

void FUN_005473a0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_00547100(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_004ddea0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00547100(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_00547460 @ 0x00547460 ====

void FUN_00547460(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009bab44;
  in_ECX[1] = 0;
  FUN_005472e0(local_4,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_005474c0 @ 0x005474c0 ====

undefined4 FUN_005474c0(void)

{
  return 0x60060030;
}


// ==== FUN_005474d0 @ 0x005474d0 ====

undefined4 FUN_005474d0(void)

{
  return 0x60060032;
}


// ==== FUN_005474e0 @ 0x005474e0 ====

void FUN_005474e0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  *(undefined1 *)((int)in_ECX + 9) = 0;
  *(undefined1 *)((int)in_ECX + 10) = 0;
  return;
}


// ==== FUN_00547580 @ 0x00547580 ====

int FUN_00547580(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint3 uVar4;
  uint3 extraout_var;
  undefined4 uVar5;
  
  piVar1 = (int *)FUN_00543340();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  iVar3 = (**(code **)(*piVar1 + 8))();
  uVar4 = (uint3)((uint)iVar3 >> 8);
  if (iVar2 != iVar3) {
    return (uint)uVar4 << 8;
  }
  if ((char)param_1[2] == '\x01') {
    uVar5 = 0x15;
  }
  else {
    if ((char)param_1[2] != '\x02') goto LAB_005475cf;
    uVar5 = 0x1f;
  }
  FUN_005433a0(uVar5);
  FUN_005434e0(uVar5);
  uVar4 = extraout_var;
LAB_005475cf:
  return CONCAT31(uVar4,1);
}


// ==== FUN_005475e0 @ 0x005475e0 ====

undefined4 FUN_005475e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)FUN_00543340();
  iVar1 = *(int *)(param_1 + 4);
  iVar3 = (**(code **)(*piVar2 + 8))();
  if (iVar1 == iVar3) {
    FUN_004dd3b0(0x18,*(undefined4 *)(param_1 + 0xc),*(undefined4 *)(param_1 + 0x10),
                 *(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 4),param_1 + 0x18);
    return 1;
  }
  return 0;
}


// ==== FUN_00547630 @ 0x00547630 ====

void FUN_00547630(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  return;
}


// ==== FUN_00547640 @ 0x00547640 ====

void FUN_00547640(undefined4 param_1)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5120002;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  iVar2 = FUN_004244d0();
  piVar3 = (int *)FUN_00543340();
  uVar4 = (**(code **)(*piVar3 + 8))();
  *(undefined4 *)(iVar2 + 0x10) = uVar4;
  FUN_004d8570(iVar2);
  return;
}


// ==== FUN_00547690 @ 0x00547690 ====

void FUN_00547690(float param_1,char param_2)

{
  undefined1 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  float10 fVar5;
  float fVar6;
  int unaff_retaddr;
  undefined4 uVar7;
  undefined1 uVar8;
  undefined2 uStack_c;
  undefined1 uStack_a;
  undefined4 *puStack_8;
  
  piVar2 = (int *)FUN_00543340();
  uVar3 = (**(code **)(*piVar2 + 8))();
  piVar2 = (int *)FUN_00543370();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
  uVar1 = (**(code **)(*piVar2 + 0x3c))();
  puStack_8 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puStack_8 == (undefined4 *)0x0) {
    puStack_8 = (undefined4 *)0x0;
  }
  else {
    *puStack_8 = &PTR_FUN_009bac40;
    *(undefined1 *)((int)puStack_8 + 5) = 1;
    puStack_8[2] = uVar3;
  }
  piVar2 = (int *)FUN_00543370();
  iVar4 = (**(code **)(*piVar2 + 0xc))();
  if (iVar4 == 0) {
    uStack_a = 0;
    uVar7 = 0;
    uVar8 = uVar1;
  }
  else {
    piVar2 = (int *)FUN_00543340();
    iVar4 = (**(code **)(*piVar2 + 0x24))();
    iVar4 = **(int **)(iVar4 + 0x50);
    uVar7 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar2 = (int *)(**(code **)(iVar4 + 0x14))(uVar7);
    iVar4 = (**(code **)(*piVar2 + 0x18))();
    fVar6 = (param_1 / *(float *)(iVar4 + 0xc)) * DAT_0099de78;
    iVar4 = 5;
    if (unaff_retaddr < 0x321) {
      if (unaff_retaddr < 0x1f5) {
        if ((200 < unaff_retaddr) && (DAT_0099de80 < fVar6)) {
          iVar4 = 7;
        }
      }
      else {
        iVar4 = 8;
        if (fVar6 <= DAT_0099de80) {
          if (DAT_009bac80 < fVar6) {
            iVar4 = 0xb;
          }
        }
        else {
          iVar4 = 0xc;
        }
      }
    }
    else {
      iVar4 = 10;
      if (fVar6 <= DAT_0099de80) {
        if (fVar6 <= DAT_009bac84) {
          if (DAT_009bac80 < fVar6) {
            iVar4 = 0xe;
          }
        }
        else {
          iVar4 = 0xf;
        }
      }
      else {
        iVar4 = 0x10;
      }
    }
    uStack_a = 1;
    FUN_004dd280(0x15,0,uVar1,0,iVar4 * 0x46,uVar3);
    fVar5 = (float10)FUN_0040d0a0(0,0x3e99999a);
    FUN_004dd240(0x15,0,0,(int)ROUND(fVar5 * (float10)DAT_0099d100),uVar3);
    if (param_2 == '\x01') {
      uVar8 = 2;
    }
    else {
      uVar8 = 1;
    }
    uVar7 = 1;
  }
  uStack_c = CONCAT11(1,uVar1);
  FUN_004dd320(0x15,uVar7,uVar8,0,uVar3,0);
  *(undefined2 *)(puStack_8 + 1) = uStack_c;
  *(undefined1 *)((int)puStack_8 + 6) = uStack_a;
  FUN_00797a20(puStack_8);
  return;
}


// ==== FUN_00547890 @ 0x00547890 ====

undefined4 FUN_00547890(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  piVar1 = (int *)FUN_00543340();
  iVar2 = (**(code **)(*piVar1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (iVar3 != iVar2) {
    return 0;
  }
  piVar1 = (int *)FUN_00543340();
  uVar4 = (**(code **)(*piVar1 + 0x24))();
  piVar1 = (int *)FUN_00803725(uVar4,0,&Framework::ICreature::RTTI_Type_Descriptor,
                               &Framework::Creature::IMiniPC::RTTI_Type_Descriptor,0);
  iVar2 = *piVar1;
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar2 = (**(code **)(iVar2 + 0x1c))(uVar4);
  iVar2 = *(byte *)(iVar2 + 0x44) + 1;
  FUN_005433a0(iVar2);
  FUN_005434e0(iVar2);
  puVar5 = operator_new(4);
  if (puVar5 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar5 = &PTR_FUN_009bac70;
  FUN_00797a20(puVar5);
  return 1;
}


// ==== FUN_00547950 @ 0x00547950 ====

undefined4 FUN_00547950(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = (int *)FUN_00543340();
  iVar2 = (**(code **)(*piVar1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (iVar3 != iVar2) {
    return 0;
  }
  uVar4 = 1;
  FUN_00543360(1);
  FUN_00511ef0(uVar4);
  piVar1 = (int *)FUN_00543340();
  uVar4 = (**(code **)(*piVar1 + 0x24))();
  piVar1 = (int *)FUN_00803725(uVar4,0,&Framework::ICreature::RTTI_Type_Descriptor,
                               &Framework::Creature::IMiniPC::RTTI_Type_Descriptor,0);
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    iVar2 = (**(code **)(iVar2 + 0x1c))(uVar4);
    iVar2 = *(byte *)(iVar2 + 0x44) + 0xb;
    FUN_005433a0(iVar2);
    FUN_005434e0(iVar2);
  }
  return 1;
}


// ==== FUN_005479f0 @ 0x005479f0 ====

undefined4 FUN_005479f0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  piVar1 = DAT_00b5a97c;
  piVar2 = (int *)FUN_00543340();
  iVar3 = (**(code **)(*piVar2 + 8))();
  iVar4 = (**(code **)(*piVar1 + 0xc))();
  if (iVar4 == iVar3) {
    uVar5 = 0x29;
    FUN_005433a0(0x29);
    FUN_005434e0(uVar5);
    return 1;
  }
  return 0;
}


// ==== FUN_00547a40 @ 0x00547a40 ====

undefined4 FUN_00547a40(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)FUN_00543340();
  iVar1 = *(int *)(param_1 + 8);
  iVar3 = (**(code **)(*piVar2 + 8))();
  if (iVar1 == iVar3) {
    (**(code **)(*DAT_00b5ac70 + 0x24))(param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_00547a90 @ 0x00547a90 ====

void FUN_00547a90(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  undefined4 *puVar8;
  float10 fVar9;
  undefined1 auStack_26 [6];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined2 uStack_10;
  undefined1 uStack_e;
  undefined1 uStack_d;
  undefined4 uStack_c;
  undefined4 uStack_8;
  float fStack_4;
  
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar3 = operator_new(0x400);
  *(undefined4 *)((int)pvVar3 + 8) = uVar2;
  *(undefined4 *)((int)pvVar3 + 0xc) = 0x50d0000;
  *(undefined2 *)((int)pvVar3 + 6) = 0x30;
  iVar4 = FUN_004244d0();
  piVar5 = (int *)FUN_00543340();
  uVar6 = (**(code **)(*piVar5 + 8))();
  *(undefined4 *)(iVar4 + 0x10) = uVar6;
  piVar5 = (int *)FUN_00543340();
  uVar1 = (**(code **)(*piVar5 + 0x30))();
  FUN_00797a50(&uStack_18,0,0xc);
  uStack_d = 1;
  uStack_18 = uVar2;
  uStack_e = uVar1;
  iVar7 = FUN_00543330();
  uStack_20 = *(undefined4 *)(iVar7 + 0x20);
  uStack_1c = *(undefined4 *)(iVar7 + 0x24);
  piVar5 = (int *)FUN_00543370();
  puVar8 = (undefined4 *)(**(code **)(*piVar5 + 0x28))();
  uStack_c = *puVar8;
  piVar5 = (int *)FUN_00543370();
  iVar7 = (**(code **)(*piVar5 + 0x28))();
  uStack_8 = *(undefined4 *)(iVar7 + 4);
  fVar9 = (float10)FUN_0040d5f0(&uStack_20);
  fStack_4 = (float)fVar9;
  puVar8 = (undefined4 *)FUN_004ef0e0(auStack_26);
  uStack_14 = *puVar8;
  uStack_10 = *(undefined2 *)(puVar8 + 1);
  FUN_00403e60(iVar4 + 0x14,&uStack_18,0xc);
  FUN_004d8570(iVar4);
  return;
}


// ==== FUN_00547bb0 @ 0x00547bb0 ====

bool FUN_00547bb0(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x2c))();
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  return *(char *)(iVar2 + 0x960) == '\x01';
}


// ==== FUN_00547be0 @ 0x00547be0 ====

void FUN_00547be0(uint param_1)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  
  piVar1 = (int *)FUN_00543340();
  iVar2 = (**(code **)(*piVar1 + 0x24))();
  if (*(int **)(iVar2 + 0x4c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar1 + 8))(param_1);
  puVar3 = (uint *)(**(code **)(*piVar1 + 0x10))();
  if (*(char *)((int)puVar3 + 0xb) == '\b') {
    if (*puVar3 < param_1) {
      uVar4 = param_1 - *puVar3;
      if ((0x1194 < uVar4) && (*(char *)(in_ECX + 8) == '\0')) {
        *(undefined1 *)(in_ECX + 8) = 1;
      }
      if (6000 < uVar4) {
        piVar1 = (int *)FUN_00543340();
        iVar2 = *DAT_00b5ac6c;
        uVar5 = (**(code **)(*piVar1 + 8))();
        (**(code **)(iVar2 + 0x18))(uVar5);
        FUN_00547640(param_1);
        piVar1 = (int *)FUN_00543330();
                    /* WARNING: Could not recover jumptable at 0x00547ca2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (**(code **)(*piVar1 + 0x30))(1);
        return;
      }
    }
  }
  else if ((*(char *)((int)puVar3 + 0xb) == '\t') && (*(uint *)((int)puVar3 + 0xd) < param_1)) {
    piVar1 = (int *)FUN_00543330();
                    /* WARNING: Could not recover jumptable at 0x00547c41. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar1 + 0x30))();
    return;
  }
  return;
}


// ==== FUN_00547cb0 @ 0x00547cb0 ====

void FUN_00547cb0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined1 auStack_12 [18];
  
  piVar1 = (int *)FUN_00543340();
  iVar2 = (**(code **)(*piVar1 + 0x24))();
  if (*(int **)(iVar2 + 0x4c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar1 + 8))(param_1);
  (**(code **)(*piVar1 + 0x10))();
  pvVar3 = operator_new(0x400);
  *(undefined4 *)((int)pvVar3 + 8) = param_1;
  *(undefined4 *)((int)pvVar3 + 0xc) = 0x50d0000;
  *(undefined2 *)((int)pvVar3 + 6) = 0x30;
  iVar2 = FUN_004244d0();
  piVar1 = (int *)FUN_00543340();
  uVar4 = (**(code **)(*piVar1 + 8))();
  *(undefined4 *)(iVar2 + 0x10) = uVar4;
  FUN_00797a50(auStack_12 + -6,0,0x11);
  FUN_00403e60(iVar2 + 0x14,auStack_12 + -6,0x11);
  FUN_004d8570(iVar2);
  return;
}


// ==== FUN_00547d90 @ 0x00547d90 ====

void FUN_00547d90(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puStack_14;
  undefined4 uStack_4;
  
  puStack_14 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puStack_14 == (undefined4 *)0x0) {
    puStack_14 = (undefined4 *)0x0;
  }
  else {
    piVar1 = (int *)FUN_00543340();
    uVar2 = (**(code **)(*piVar1 + 8))();
    *puStack_14 = &PTR_FUN_009b8cc4;
    puStack_14[1] = uVar2;
  }
  uVar2 = 0;
  uStack_4 = 0;
  piVar1 = (int *)FUN_00543370();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
  iVar3 = (**(code **)(*piVar1 + 0x1c))();
  if (iVar3 == 3) {
    uVar2 = 2;
    piVar1 = (int *)FUN_00543370();
    iVar3 = (**(code **)(*piVar1 + 0x10))();
    uStack_4 = *(undefined4 *)(iVar3 + 0x38);
  }
  if (param_1 == 0) {
    iVar3 = 1;
  }
  else {
    piVar1 = (int *)FUN_00543370();
    iVar3 = (**(code **)(*piVar1 + 0xc))();
    if (iVar3 == 0) {
      uVar2 = 0;
    }
    else {
      piVar1 = (int *)FUN_00543370();
      piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
      iVar3 = (**(code **)(*piVar1 + 0x1c))();
      if (iVar3 != 3) {
        uVar2 = 1;
      }
    }
    if ((char)param_2 == '\x01') {
      iVar3 = 4;
    }
    else {
      iVar3 = (-(uint)((char)param_2 != '\0') & 3) + 3;
    }
    FUN_00547690(param_1,param_2);
  }
  puStack_14[2] = iVar3;
  puStack_14[3] = uVar2;
  puStack_14[4] = param_1;
  puStack_14[5] = uStack_4;
  FUN_00797a20(puStack_14);
  return;
}


// ==== FUN_00547eb0 @ 0x00547eb0 ====

undefined4 FUN_00547eb0(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int in_ECX;
  
  piVar2 = (int *)FUN_00543340();
  iVar3 = (**(code **)(*piVar2 + 8))();
  iVar4 = (**(code **)(*param_1 + 0x10))();
  if (iVar4 != iVar3) {
    return 0;
  }
  FUN_00547d90(0,0);
  piVar2 = (int *)FUN_00543340();
  (**(code **)(*piVar2 + 0x60))((char)param_1[2]);
  piVar2 = (int *)FUN_00543340();
  piVar5 = (int *)FUN_00543340();
  iVar3 = param_1[2];
  uVar6 = (**(code **)(*piVar2 + 8))(*(undefined4 *)(in_ECX + 0x14));
  uVar6 = (**(code **)(*piVar5 + 0x34))(0,uVar6);
  FUN_004dd320(5,(char)iVar3,uVar6);
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
  if (1 < *(uint *)(in_ECX + 0x14)) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
  }
  iVar3 = *DAT_00b5a97c;
  uVar6 = (**(code **)(*param_1 + 0x10))();
  cVar1 = (**(code **)(iVar3 + 0x10))(uVar6);
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5acdc + 0x18))();
  }
  return 1;
}


// ==== FUN_00547f80 @ 0x00547f80 ====

undefined4 FUN_00547f80(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int in_ECX;
  
  piVar2 = (int *)FUN_00543340();
  iVar3 = (**(code **)(*piVar2 + 8))();
  iVar4 = (**(code **)(*param_1 + 0x10))();
  if (iVar4 != iVar3) {
    return 0;
  }
  FUN_00547d90(param_1[3],*(undefined1 *)((int)param_1 + 9));
  piVar2 = (int *)FUN_00543340();
  (**(code **)(*piVar2 + 0x54))();
  piVar2 = (int *)FUN_00543340();
  piVar5 = (int *)FUN_00543340();
  iVar3 = param_1[2];
  uVar6 = (**(code **)(*piVar2 + 8))(*(undefined4 *)(in_ECX + 0x14));
  uVar6 = (**(code **)(*piVar5 + 0x34))(0,uVar6);
  FUN_004dd320(5,(char)iVar3,uVar6);
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
  if (1 < *(uint *)(in_ECX + 0x14)) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
  }
  iVar3 = *DAT_00b5a97c;
  uVar6 = (**(code **)(*param_1 + 0x10))();
  cVar1 = (**(code **)(iVar3 + 0x10))(uVar6);
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5acdc + 0x18))();
  }
  return 1;
}


// ==== FUN_00548050 @ 0x00548050 ====

undefined4 FUN_00548050(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uStack_8;
  
  piVar2 = (int *)FUN_00543340();
  iVar3 = (**(code **)(*piVar2 + 8))();
  iVar4 = (**(code **)(*param_1 + 0x10))();
  if (iVar4 != iVar3) {
    return 0;
  }
  piVar2 = (int *)FUN_00543340();
  (**(code **)(*piVar2 + 0x60))((char)param_1[2]);
  puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  uVar7 = 0;
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00543340();
    uVar6 = (**(code **)(*piVar2 + 8))();
    *puVar5 = &PTR_FUN_009b8cc4;
    puVar5[1] = uVar6;
  }
  iVar3 = param_1[3];
  uStack_8 = 0;
  piVar2 = (int *)FUN_00543370();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
  iVar4 = (**(code **)(*piVar2 + 0x1c))();
  if (iVar4 == 3) {
    uVar7 = 2;
    piVar2 = (int *)FUN_00543370();
    iVar4 = (**(code **)(*piVar2 + 0x10))();
    uStack_8 = *(undefined4 *)(iVar4 + 0x38);
  }
  puVar5[2] = 2;
  puVar5[3] = uVar7;
  puVar5[4] = iVar3;
  puVar5[5] = uStack_8;
  FUN_00797a20(puVar5);
  iVar3 = *DAT_00b5a97c;
  uVar7 = (**(code **)(*param_1 + 0x10))();
  cVar1 = (**(code **)(iVar3 + 0x10))(uVar7);
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5acdc + 0x18))();
  }
  return 1;
}


// ==== FUN_00548170 @ 0x00548170 ====

undefined4 FUN_00548170(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  
  piVar2 = (int *)FUN_00543340();
  iVar3 = (**(code **)(*piVar2 + 8))();
  iVar4 = (**(code **)(*param_1 + 0x10))();
  if (iVar4 != iVar3) {
    return 0;
  }
  uVar5 = 0;
  FUN_00543360(0);
  FUN_00511ef0(uVar5);
  FUN_00547d90(param_1[5],*(undefined1 *)((int)param_1 + 0x11));
  piVar2 = (int *)FUN_00543370();
  iVar3 = (**(code **)(*piVar2 + 0xc))();
  if (iVar3 == 1) {
    uVar5 = FUN_00543330();
    piVar2 = (int *)FUN_00803725(uVar5,0,&Framework::ModelCenter::Actors::State::IActorState::
                                          RTTI_Type_Descriptor,
                                 &Framework::ModelCenter::Actors::State::Monster::
                                  RTTI_Type_Descriptor,0);
    if (piVar2 != (int *)0x0) {
      FUN_0052a630(0);
      (**(code **)(*piVar2 + 0x30))(0);
    }
    piVar2 = (int *)FUN_00543340();
    iVar3 = *DAT_00b5ad5c;
    uVar5 = (**(code **)(*piVar2 + 8))();
    (**(code **)(iVar3 + 8))(uVar5);
    *(undefined1 *)(in_ECX + 10) = 1;
  }
  piVar2 = (int *)FUN_00543340();
  (**(code **)(*piVar2 + 0x58))();
  iVar3 = *DAT_00b5a97c;
  uVar5 = (**(code **)(*param_1 + 0x10))();
  cVar1 = (**(code **)(iVar3 + 0x10))(uVar5);
  if (cVar1 != '\0') {
    (**(code **)(*DAT_00b5acdc + 0x18))();
  }
  return 1;
}


// ==== FUN_00548260 @ 0x00548260 ====

undefined4 FUN_00548260(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uStack_4;
  
  piVar1 = (int *)FUN_00543340();
  iVar2 = (**(code **)(*piVar1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (iVar3 != iVar2) {
    return 0;
  }
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    piVar1 = (int *)FUN_00543340();
    uVar5 = (**(code **)(*piVar1 + 8))();
    *puVar4 = &PTR_FUN_009b8cc4;
    puVar4[1] = uVar5;
  }
  uVar5 = 0;
  uStack_4 = 0;
  piVar1 = (int *)FUN_00543370();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  if (iVar2 == 3) {
    uVar5 = 2;
    piVar1 = (int *)FUN_00543370();
    iVar2 = (**(code **)(*piVar1 + 0x10))();
    uStack_4 = *(undefined4 *)(iVar2 + 0x38);
  }
  puVar4[2] = 0;
  puVar4[3] = uVar5;
  puVar4[4] = 0;
  puVar4[5] = uStack_4;
  FUN_00797a20(puVar4);
  return 1;
}


// ==== FUN_00548330 @ 0x00548330 ====

undefined4 FUN_00548330(int *param_1)

{
  undefined1 uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int in_ECX;
  float fVar8;
  undefined4 uVar9;
  ushort auStack_14 [2];
  undefined1 uStack_10;
  float afStack_c [2];
  undefined4 uStack_4;
  
  piVar3 = (int *)FUN_00543340();
  iVar4 = (**(code **)(*piVar3 + 8))();
  iVar5 = (**(code **)(*param_1 + 0x10))();
  if (iVar5 != iVar4) {
    return 0;
  }
  uStack_10 = (undefined1)param_1[2];
  auStack_14[0] = (ushort)*(byte *)((int)param_1 + 9);
  auStack_14[1] = 0;
  FUN_004f5730(afStack_c);
  FUN_00543360();
  fVar8 = afStack_c[0] * DAT_009b0120;
  uVar9 = 0x3e4ccccd;
  uVar6 = FUN_0040d600(auStack_14,uStack_4,fVar8,0x3e4ccccd);
  FUN_00511d20(uVar6);
  FUN_00511950(uVar6,fVar8,uVar9);
  FUN_00547d90(param_1[3],(char)param_1[4]);
  piVar3 = (int *)FUN_00543340();
  piVar7 = (int *)FUN_00543340();
  uVar1 = *(undefined1 *)((int)param_1 + 0x11);
  uVar6 = (**(code **)(*piVar3 + 8))(*(undefined4 *)(in_ECX + 0x14));
  uVar6 = (**(code **)(*piVar7 + 0x34))(0,uVar6);
  FUN_004dd320(5,uVar1,uVar6);
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
  if (1 < *(uint *)(in_ECX + 0x14)) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
  }
  iVar4 = *DAT_00b5a97c;
  uVar6 = (**(code **)(*param_1 + 0x10))();
  cVar2 = (**(code **)(iVar4 + 0x10))(uVar6);
  if (cVar2 != '\0') {
    (**(code **)(*DAT_00b5acdc + 0x18))();
  }
  return 1;
}


// ==== FUN_00548460 @ 0x00548460 ====

undefined4 FUN_00548460(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 extraout_var;
  undefined4 uVar5;
  uint uVar6;
  
  piVar1 = (int *)FUN_00543340();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  iVar3 = (**(code **)(*piVar1 + 8))();
  if (iVar2 != iVar3) {
    return 0;
  }
  piVar1 = (int *)FUN_00543340();
  iVar2 = (**(code **)(*piVar1 + 0x24))();
  if ((iVar2 != 0) && (*(int **)(iVar2 + 0x4c) != (int *)0x0)) {
    piVar1 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
    if (piVar1 != (int *)0x0) {
      uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      (**(code **)(*piVar1 + 8))(uVar4);
      iVar2 = (**(code **)(*piVar1 + 0x10))();
      if (*(char *)(iVar2 + 0xb) == '\n') {
        uVar4 = *(undefined4 *)(iVar2 + 0xf);
        uVar5 = CONCAT22(extraout_var,*(undefined2 *)(iVar2 + 0xc));
        uVar6 = (uint)*(byte *)(iVar2 + 0x13);
        FUN_005433a0(uVar4,uVar5,uVar6);
        FUN_005435f0(uVar4,uVar5,uVar6);
      }
    }
  }
  return 1;
}


// ==== FUN_00548500 @ 0x00548500 ====

void FUN_00548500(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined1 uVar6;
  undefined4 unaff_ESI;
  undefined1 auStack_8 [2];
  undefined1 auStack_6 [6];
  
  piVar1 = (int *)FUN_00543340();
  iVar2 = (**(code **)(*piVar1 + 0x24))();
  uVar6 = 0;
  if (*(int **)(iVar2 + 0x4c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
  }
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(*piVar1 + 8))(uVar3);
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  piVar1 = DAT_00b5a6b4;
  auStack_8[0] = *(char *)(iVar2 + 0xd) == '\0';
  piVar4 = (int *)FUN_00543370();
  iVar2 = (**(code **)(*piVar4 + 0x28))();
  (**(code **)(*piVar1 + 0x18))(iVar2,auStack_8 + -4);
  piVar1 = (int *)FUN_00543340();
  (**(code **)(*piVar1 + 0x50))(unaff_ESI,auStack_8 + -0xc,auStack_8);
  if (iVar2 == 3) {
    if (*(char *)(in_ECX + 9) != '\0') {
      return;
    }
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
      uVar6 = 1;
    }
    else {
      piVar1 = (int *)FUN_00543340();
      uVar3 = (**(code **)(*piVar1 + 8))();
      *puVar5 = &PTR_FUN_009bac58;
      puVar5[1] = uVar3;
      uVar6 = 1;
    }
  }
  else {
    if (*(char *)(in_ECX + 9) != '\x01') {
      return;
    }
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      piVar1 = (int *)FUN_00543340();
      uVar3 = (**(code **)(*piVar1 + 8))();
      *puVar5 = &PTR_FUN_009bac58;
      puVar5[1] = uVar3;
    }
  }
  *(undefined1 *)(puVar5 + 2) = uVar6;
  FUN_00797a20(puVar5);
  *(undefined1 *)(in_ECX + 9) = uVar6;
  return;
}


// ==== FUN_005486b0 @ 0x005486b0 ====

undefined4 FUN_005486b0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 uStack_30;
  undefined1 auStack_c [12];
  
  piVar8 = param_1;
  uStack_30 = 0x5486c0;
  piVar2 = (int *)FUN_00543340();
  uStack_30 = 0x5486cd;
  iVar3 = (**(code **)(*param_1 + 0x10))();
  uStack_30 = 0x5486d6;
  iVar4 = (**(code **)(*piVar2 + 8))();
  if (iVar3 == iVar4) {
    uStack_30 = 0x5486ed;
    piVar2 = (int *)FUN_00543370();
    uStack_30 = 0x5486f4;
    iVar5 = (**(code **)(*piVar2 + 0xc))();
    piVar2 = DAT_00b5adac;
    iVar3 = param_1[6];
    iVar4 = param_1[7];
    iVar1 = param_1[9];
    param_1 = (int *)CONCAT31(param_1._1_3_,*(undefined1 *)((int)param_1 + 0x25));
    uStack_30 = 0x548722;
    iVar6 = FUN_00543330();
    uStack_30 = 0x54872d;
    uVar7 = FUN_00543390();
    uStack_30 = param_1;
    (**(code **)(*piVar2 + 0xc))
              (auStack_c,uVar7,iVar6 + 0x18,piVar8 + 4,iVar4,(char)iVar1,iVar3,iVar5 != 0);
    piVar8 = (int *)FUN_00543330();
    (**(code **)(*piVar8 + 0x20))();
    piVar8 = (int *)FUN_00543330();
    (**(code **)(*piVar8 + 0x24))(&uStack_30);
    piVar8 = (int *)FUN_00543330();
    (**(code **)(*piVar8 + 0xc))();
    FUN_008984a0();
    return 1;
  }
  return 0;
}


// ==== FUN_005487a0 @ 0x005487a0 ====

undefined4 FUN_005487a0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uStack_20;
  undefined1 auStack_c [12];
  
  piVar1 = (int *)FUN_00543340();
  iVar2 = (**(code **)(*piVar1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  piVar1 = DAT_00b5adac;
  if (iVar3 != iVar2) {
    return 0;
  }
  uStack_20 = 0x5487e0;
  piVar4 = (int *)FUN_00543370();
  uStack_20 = 0x5487e7;
  uVar5 = (**(code **)(*piVar4 + 0x28))();
  uStack_20 = 0x5487f0;
  uVar6 = FUN_00543390();
  uStack_20 = 0;
  (**(code **)(*piVar1 + 4))(auStack_c,uVar6,uVar5,param_1 + 2);
  piVar1 = (int *)FUN_00543330();
  (**(code **)(*piVar1 + 0x20))();
  piVar1 = (int *)FUN_00543330();
  (**(code **)(*piVar1 + 0x24))(&uStack_20);
  piVar1 = (int *)FUN_00543330();
  (**(code **)(*piVar1 + 0xc))();
  if (*(char *)((int)param_1 + 0x13) == '\x01') {
    piVar1 = (int *)FUN_00543340();
    (**(code **)(*piVar1 + 0x4c))();
  }
  FUN_008984a0();
  return 1;
}


// ==== FUN_00548860 @ 0x00548860 ====

undefined4 FUN_00548860(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 auStack_c [2];
  undefined1 auStack_a [10];
  
  piVar1 = (int *)FUN_00543340();
  iVar2 = (**(code **)(*piVar1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  piVar1 = DAT_00b5adac;
  if (iVar3 != iVar2) {
    return 0;
  }
  piVar4 = (int *)FUN_00543370();
  uVar5 = (**(code **)(*piVar4 + 0x28))();
  uVar6 = FUN_00543390();
  (**(code **)(*piVar1 + 8))(auStack_c,uVar6,uVar5,param_1 + 2);
  piVar1 = (int *)FUN_00543330();
  (**(code **)(*piVar1 + 0x20))();
  piVar1 = (int *)FUN_00543330();
  (**(code **)(*piVar1 + 0x24))(auStack_c + -0x10);
  piVar1 = (int *)FUN_00543330();
  (**(code **)(*piVar1 + 0xc))();
  if (*(char *)((int)param_1 + 0x13) == '\x01') {
    piVar1 = (int *)FUN_00543340();
    (**(code **)(*piVar1 + 0x4c))();
  }
  FUN_008984a0();
  return 1;
}


// ==== FUN_00548920 @ 0x00548920 ====

void FUN_00548920(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puStack_44;
  undefined4 *puStack_40;
  undefined1 auStack_30 [12];
  undefined4 auStack_24 [3];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  
  puStack_40 = (undefined4 *)0x54892f;
  piVar1 = (int *)FUN_00543370();
  puStack_40 = (undefined4 *)0x548936;
  puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x28))();
  uStack_18 = *puVar2;
  uStack_14 = puVar2[1];
  puStack_40 = (undefined4 *)0x54894a;
  iVar3 = FUN_00543330();
  uStack_10 = *(undefined4 *)(iVar3 + 0x20);
  uStack_c = *(undefined4 *)(iVar3 + 0x24);
  puStack_40 = (undefined4 *)0x548963;
  uStack_8 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  puStack_40 = (undefined4 *)0x54896e;
  piVar1 = (int *)FUN_00543340();
  puStack_40 = (undefined4 *)0x548975;
  uStack_4 = (**(code **)(*piVar1 + 0x30))();
  puStack_40 = auStack_24;
  puStack_44 = &uStack_18;
  FUN_005077f0();
  piVar1 = DAT_00b5adac;
  puStack_40 = (undefined4 *)0x548998;
  piVar4 = (int *)FUN_00543370();
  puStack_40 = (undefined4 *)0x54899f;
  uVar5 = (**(code **)(*piVar4 + 0x28))();
  puStack_40 = (undefined4 *)0x5489a8;
  uVar6 = FUN_00543390();
  puStack_40 = (undefined4 *)0x0;
  puStack_44 = auStack_24;
  (**(code **)(*piVar1 + 4))(auStack_30,uVar6,uVar5);
  piVar1 = (int *)FUN_00543330();
  (**(code **)(*piVar1 + 0x20))();
  piVar1 = (int *)FUN_00543330();
  (**(code **)(*piVar1 + 0x24))(&puStack_44);
  piVar1 = (int *)FUN_00543330();
  (**(code **)(*piVar1 + 0xc))();
  FUN_008984a0();
  return;
}


// ==== FUN_00548a00 @ 0x00548a00 ====

void FUN_00548a00(void)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 *puStack_58;
  undefined4 *puStack_54;
  undefined1 auStack_44 [12];
  undefined4 auStack_38 [4];
  undefined1 uStack_25;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined1 uStack_10;
  
  puStack_54 = (undefined4 *)0x548a0f;
  piVar1 = (int *)FUN_00543370();
  puStack_54 = (undefined4 *)0x548a16;
  puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x28))();
  uStack_24 = *puVar2;
  uStack_20 = puVar2[1];
  puStack_54 = (undefined4 *)0x548a2a;
  iVar3 = FUN_00543330();
  uStack_1c = *(undefined4 *)(iVar3 + 0x20);
  uStack_18 = *(undefined4 *)(iVar3 + 0x24);
  puStack_54 = (undefined4 *)0x548a43;
  uStack_14 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  puStack_54 = (undefined4 *)0x548a4e;
  piVar1 = (int *)FUN_00543340();
  puStack_54 = (undefined4 *)0x548a55;
  uStack_10 = (**(code **)(*piVar1 + 0x30))();
  puStack_54 = auStack_38;
  puStack_58 = &uStack_24;
  FUN_00507b00();
  piVar1 = DAT_00b5adac;
  uStack_25 = 2;
  puStack_54 = (undefined4 *)0x548a7d;
  piVar4 = (int *)FUN_00543370();
  puStack_54 = (undefined4 *)0x548a84;
  uVar5 = (**(code **)(*piVar4 + 0x28))();
  puStack_54 = (undefined4 *)0x548a8d;
  uVar6 = FUN_00543390();
  puStack_54 = (undefined4 *)0x0;
  puStack_58 = auStack_38;
  (**(code **)(*piVar1 + 4))(auStack_44,uVar6,uVar5);
  piVar1 = (int *)FUN_00543330();
  (**(code **)(*piVar1 + 0x20))();
  piVar1 = (int *)FUN_00543330();
  (**(code **)(*piVar1 + 0x24))(&puStack_58);
  piVar1 = (int *)FUN_00543330();
  (**(code **)(*piVar1 + 0xc))();
  FUN_008984a0();
  return;
}


// ==== FUN_00548af0 @ 0x00548af0 ====

undefined4 FUN_00548af0(int *param_1)

{
  bool bVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  piVar3 = (int *)FUN_00543340();
  iVar4 = (**(code **)(*piVar3 + 8))();
  iVar5 = (**(code **)(*param_1 + 0x10))();
  if (iVar5 != iVar4) {
    return 0;
  }
  FUN_00543360();
  iVar4 = FUN_00511d20();
  if (*(int *)(iVar4 + 8) == param_1[2]) {
    if (param_1[3] == 2) {
      iVar4 = FUN_00543350();
      if (iVar4 != 0) {
        piVar3 = (int *)FUN_00543350();
        cVar2 = (**(code **)(*piVar3 + 8))();
        if (cVar2 != '\0') {
          FUN_00547a90();
          return 1;
        }
      }
      FUN_00548920();
      return 1;
    }
    piVar3 = (int *)FUN_00543330();
    piVar3 = (int *)(**(code **)(*piVar3 + 0x18))();
    if (piVar3 != (int *)0x0) {
      bVar1 = false;
      cVar2 = (**(code **)(*piVar3 + 0x10))(param_1[3]);
      if (cVar2 == '\x01') {
        iVar4 = (**(code **)(*piVar3 + 4))();
        if (iVar4 == 5) {
          cVar2 = FUN_00547bb0();
          if (cVar2 == '\0') {
            return 1;
          }
          piVar6 = (int *)FUN_00543340();
          iVar4 = (**(code **)(*piVar6 + 4))();
          if (iVar4 != 0) {
            piVar6 = (int *)FUN_00543340();
            iVar4 = (**(code **)(*piVar6 + 4))();
            if (iVar4 != 1) {
              return 1;
            }
          }
          bVar1 = true;
        }
        piVar6 = (int *)FUN_00543330();
        (**(code **)(*piVar6 + 0x1c))();
        (**(code **)*piVar3)(1);
        piVar3 = (int *)FUN_00543330();
        iVar4 = (**(code **)(*piVar3 + 0x18))();
        if (iVar4 != 0) {
          piVar3 = (int *)FUN_00543330();
          (**(code **)(*piVar3 + 0xc))();
          return 1;
        }
        if (bVar1) {
          FUN_00548a00();
          return 1;
        }
        FUN_00548920();
      }
    }
  }
  return 1;
}


// ==== FUN_00548c50 @ 0x00548c50 ====

void FUN_00548c50(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  piVar2 = (int *)FUN_00543330();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x18))();
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 8))();
    if (cVar1 == '\x01') {
      return;
    }
    piVar3 = (int *)FUN_00543330();
    (**(code **)(*piVar3 + 0x1c))();
    (**(code **)*piVar2)(1);
    piVar2 = (int *)FUN_00543330();
    piVar2 = (int *)(**(code **)(*piVar2 + 0x18))();
    if (piVar2 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00548caa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar2 + 0xc))();
      return;
    }
  }
  FUN_00548920();
  return;
}


// ==== FUN_00548cb0 @ 0x00548cb0 ====

void FUN_00548cb0(int param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  
  iVar2 = FUN_00543350();
  if (iVar2 != 0) {
    piVar3 = (int *)FUN_00543350();
    (**(code **)(*piVar3 + 0x10))();
  }
  piVar3 = (int *)FUN_00543330();
  cVar1 = (**(code **)(*piVar3 + 0x2c))();
  if (cVar1 != '\0') {
    piVar3 = (int *)FUN_00543330();
    cVar1 = (**(code **)(*piVar3 + 0x34))();
    if (cVar1 == '\0') {
      FUN_00547be0(*(undefined4 *)(param_1 + 0xc));
    }
  }
  FUN_00548c50();
  uVar5 = *(undefined4 *)(param_1 + 0xc);
  piVar3 = (int *)FUN_00543340();
  iVar2 = (**(code **)(*piVar3 + 0x24))();
  if (*(int **)(iVar2 + 0x4c) == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
  }
  (**(code **)(*piVar3 + 8))(uVar5);
  iVar2 = (**(code **)(*piVar3 + 0x10))();
  if ((*(char *)(iVar2 + 0xb) == '\x02') || (*(char *)(iVar2 + 0xb) == '\x03')) {
    FUN_00548500(*(undefined4 *)(param_1 + 4));
  }
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + *(int *)(param_1 + 4);
  if (499 < *(uint *)(in_ECX + 0xc)) {
    piVar3 = (int *)FUN_00543340();
    iVar2 = FUN_00543330();
    (**(code **)(*piVar3 + 0x44))(*(undefined4 *)(iVar2 + 4));
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  if ((*(char *)(in_ECX + 10) != '\0') &&
     (*(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + *(int *)(param_1 + 4),
     2000 < *(uint *)(in_ECX + 0x10))) {
    puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      piVar3 = (int *)FUN_00543340();
      uVar5 = (**(code **)(*piVar3 + 8))();
      *puVar4 = &PTR_FUN_009bac28;
      puVar4[1] = uVar5;
      puVar4[2] = 2000;
    }
    FUN_00797a20(puVar4);
    piVar3 = (int *)FUN_00543340();
    iVar2 = (**(code **)(*piVar3 + 0x1c))();
    if (iVar2 != 3) {
      uVar5 = 0x33;
      FUN_005433a0(0x33);
      FUN_005434e0(uVar5);
    }
    *(undefined1 *)(in_ECX + 10) = 0;
  }
  return;
}


// ==== FUN_00548e10 @ 0x00548e10 ====

void FUN_00548e10(undefined4 *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  short unaff_DI;
  undefined1 uStack00000000;
  undefined1 *puVar6;
  undefined1 local_34 [2];
  undefined1 auStack_32 [10];
  undefined4 local_28;
  undefined4 local_24;
  void *local_20;
  uint uStack_c;
  short sStack_4;
  
  local_28 = *param_1;
  local_24 = param_1[1];
  local_20 = (void *)0x0;
  piVar2 = (int *)FUN_00543330();
  (**(code **)(*piVar2 + 4))(local_34);
  puVar6 = (undefined1 *)register0x00000010;
  FUN_004ef0e0(auStack_32);
  FUN_005e0c90(puVar6);
  piVar2 = (int *)FUN_00543330();
  (**(code **)(*piVar2 + 8))(&uStack00000000);
  piVar2 = (int *)FUN_00543330();
  cVar1 = (**(code **)(*piVar2 + 0x2c))();
  if (cVar1 != '\0') {
    if (unaff_DI != sStack_4) {
      FUN_00401740(s__u_sector__>__u_sector_009babcc,0x16);
      uVar3 = FUN_00404230(&local_24);
      FUN_00796d50(uVar3);
      if (0xf < uStack_c) {
        _free(local_20);
        return;
      }
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = _uStack00000000;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x50d0002;
      *(undefined2 *)((int)pvVar4 + 6) = 0x18;
      iVar5 = FUN_004244d0();
      piVar2 = (int *)FUN_00543340();
      uVar3 = (**(code **)(*piVar2 + 8))();
      *(undefined4 *)(iVar5 + 0x10) = uVar3;
      *(short *)(iVar5 + 0x14) = sStack_4;
      FUN_004d8570(iVar5);
    }
  }
  return;
}


// ==== FUN_00548f50 @ 0x00548f50 ====

undefined4 FUN_00548f50(int *param_1)

{
  undefined1 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  piVar2 = (int *)FUN_00543340();
  iVar3 = (**(code **)(*piVar2 + 8))();
  iVar4 = (**(code **)(*param_1 + 0x10))();
  if (iVar4 != iVar3) {
    return 0;
  }
  puVar1 = (undefined1 *)param_1[1];
  uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  FUN_00548e10(puVar1 + 0x14,uVar5);
  iVar3 = FUN_00543330();
  *(undefined4 *)(iVar3 + 0x18) = *(undefined4 *)(puVar1 + 0x14);
  *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(puVar1 + 0x18);
  iVar3 = FUN_00543330();
  *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(puVar1 + 0x1c);
  *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(puVar1 + 0x20);
  iVar3 = FUN_00543330();
  *(undefined4 *)(iVar3 + 0x30) = *(undefined4 *)(puVar1 + 4);
  iVar3 = FUN_00543330();
  *(undefined4 *)(iVar3 + 0x2c) = *(undefined4 *)(puVar1 + 8);
  if (DAT_0099cdc8 < *(float *)(puVar1 + 0xc)) {
    iVar3 = FUN_00543330();
    *(undefined4 *)(iVar3 + 0x34) = *(undefined4 *)(puVar1 + 0xc);
  }
  iVar3 = FUN_00543330();
  *(undefined1 *)(iVar3 + 0x14) = *puVar1;
  return 1;
}


// ==== FUN_00549010 @ 0x00549010 ====

undefined4 FUN_00549010(int *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x50040006) {
    if (uVar1 == 0x50040005) {
      uVar2 = FUN_00548260(param_1);
      return uVar2;
    }
    if (uVar1 < 0x30060023) {
      if (uVar1 == 0x30060022) {
        uVar2 = FUN_00547580(param_1);
        return uVar2;
      }
      if (uVar1 < 0x20010023) {
        if (uVar1 == 0x20010022) {
          uVar2 = FUN_00548af0(param_1);
          return uVar2;
        }
        if (uVar1 == 0x40001) {
          FUN_00548cb0(param_1);
        }
        else if (uVar1 == 0x20010021) {
          uVar2 = FUN_00548f50(param_1);
          return uVar2;
        }
      }
      else {
        if (uVar1 == 0x30060003) {
          uVar2 = FUN_005486b0(param_1);
          return uVar2;
        }
        if (uVar1 == 0x30060018) {
          uVar2 = FUN_00547890(param_1);
          return uVar2;
        }
      }
    }
    else {
      switch(uVar1 + 0xaffbffff) {
      case 0:
        uVar2 = FUN_00547eb0(param_1);
        return uVar2;
      case 1:
        uVar2 = FUN_00547f80(param_1);
        return uVar2;
      case 2:
        uVar2 = FUN_00548050(param_1);
        return uVar2;
      case 3:
        uVar2 = FUN_00548170(param_1);
        return uVar2;
      }
    }
  }
  else if (uVar1 < 0x50070003) {
    if (uVar1 == 0x50070002) {
      uVar2 = FUN_005487a0(param_1);
      return uVar2;
    }
    switch(uVar1 + 0xaffbfffa) {
    case 0:
      uVar2 = FUN_00548330(param_1);
      return uVar2;
    case 1:
      uVar2 = FUN_00547950(param_1);
      return uVar2;
    case 2:
      uVar2 = FUN_00548460(param_1);
      return uVar2;
    case 3:
      uVar2 = FUN_005479f0(param_1);
      return uVar2;
    }
  }
  else if (uVar1 < 0x60010012) {
    if (uVar1 == 0x60010011) {
      uVar2 = FUN_00547a40(param_1);
      return uVar2;
    }
    if (uVar1 == 0x50070003) {
      uVar2 = FUN_00548860(param_1);
      return uVar2;
    }
    if (uVar1 == 0x60010010) {
      (**(code **)(*DAT_00b5ac6c + 4))();
      return 1;
    }
  }
  else if (uVar1 == 0x60010012) {
    uVar2 = FUN_005475e0(param_1);
    return uVar2;
  }
  return 0;
}


// ==== FUN_005491e0 @ 0x005491e0 ====

undefined4 FUN_005491e0(void)

{
  return 0x60010031;
}


// ==== FUN_005491f0 @ 0x005491f0 ====

undefined4 FUN_005491f0(void)

{
  return 0x70140002;
}


// ==== FUN_00549200 @ 0x00549200 ====

undefined4 FUN_00549200(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ad98 + 8))();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 != 1) {
                    /* WARNING: Could not recover jumptable at 0x00549228. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(*DAT_00b5ad9c + 0x10))();
      return uVar3;
    }
  }
  return 0;
}


// ==== FUN_00549230 @ 0x00549230 ====

uint FUN_00549230(undefined4 param_1,char param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  if ((char)uVar1 != '\0') {
    uVar1 = (**(code **)(*DAT_00b5ad04 + 4))();
    if ((char)uVar1 != '\x01') {
      uVar1 = (**(code **)(*DAT_00b5ad04 + 0x10))(param_1);
      return uVar1;
    }
    if (param_2 == '\x01') {
      uVar1 = FUN_00549810();
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00549280 @ 0x00549280 ====

undefined4 FUN_00549280(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_00549a40(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if ((((iVar2 == 0) || (iVar2 == 2)) || (iVar2 == 1)) ||
       (((iVar2 == 3 || (iVar2 == 5)) || (iVar2 == 6)))) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005492f0 @ 0x005492f0 ====

undefined4 FUN_005492f0(void)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    cVar2 = (**(code **)(**(int **)(in_ECX + 4) + 4))();
    if (cVar2 != '\0') {
      iVar1 = *DAT_00b5ac28;
      uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x18))(1,**(undefined1 **)(in_ECX + 8));
      (**(code **)(iVar1 + 8))(uVar3);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00549330 @ 0x00549330 ====

undefined4 FUN_00549330(void)

{
  undefined1 *puVar1;
  int in_ECX;
  undefined1 local_14 [4];
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = FUN_00549950();
  if (local_10 == 0) {
    return 0;
  }
  puVar1 = *(undefined1 **)(in_ECX + 8);
  local_c = 0;
  local_8 = *(undefined4 *)(puVar1 + 0xc);
  local_4 = *(undefined4 *)(puVar1 + 0x10);
  local_14[0] = *puVar1;
  (**(code **)(*DAT_00b5ac28 + 0x38))(local_14);
  return 1;
}


// ==== FUN_00549390 @ 0x00549390 ====

void FUN_00549390(undefined4 param_1)

{
  int in_ECX;
  undefined4 unaff_retaddr;
  
  if (*(undefined4 **)(in_ECX + 4) == (undefined4 *)0x0) {
    *(undefined4 *)(in_ECX + 4) = param_1;
    return;
  }
  (**(code **)**(undefined4 **)(in_ECX + 4))(1);
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 4) = unaff_retaddr;
  return;
}


// ==== FUN_005493c0 @ 0x005493c0 ====

void FUN_005493c0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bac9c;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  if (DAT_00b5af54 == 0) {
    pvVar1 = operator_new(4);
    if (pvVar1 != (void *)0x0) {
      FUN_00549850();
    }
  }
  return;
}


// ==== FUN_00549400 @ 0x00549400 ====

void FUN_00549400(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bac9c;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
    in_ECX[1] = 0;
  }
  in_ECX[1] = 0;
  if (DAT_00b5af54 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af54)(1);
  }
  return;
}


// ==== FUN_00549440 @ 0x00549440 ====

undefined1 FUN_00549440(void)

{
  char cVar1;
  int in_ECX;
  undefined1 auStack_14 [4];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  cVar1 = FUN_00549920();
  if (cVar1 == '\0') {
    return 0;
  }
  uStack_c = (**(code **)(*DAT_00b5a97c + 0xc))();
  uStack_10 = 0x10;
  uStack_8 = *(undefined4 *)(*(int *)(in_ECX + 8) + 0xc);
  uStack_4 = *(undefined4 *)(*(int *)(in_ECX + 8) + 0x10);
  auStack_14[0] = 0;
  (**(code **)(*DAT_00b5ac28 + 0x38))(auStack_14);
  return 1;
}


// ==== FUN_005494a0 @ 0x005494a0 ====

uint FUN_005494a0(void)

{
  code *pcVar1;
  char cVar2;
  int *piVar3;
  uint extraout_EAX;
  uint uVar4;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  int *piStack_8;
  uint uStack_4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  piStack_8 = (int *)(**(code **)(*piVar3 + 0x2c))();
  if (piStack_8 != (int *)0x0) {
    cVar2 = (**(code **)(*piStack_8 + 0x1c))();
    return (uint)(cVar2 != '\0');
  }
  uStack_4 = 0xf;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pFlyweight_009bac8c,10);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar4 = (*pcVar1)();
    return uVar4;
  }
  _free(pvStack_18);
  return extraout_EAX;
}


// ==== FUN_00549520 @ 0x00549520 ====

undefined4 FUN_00549520(void)

{
  undefined1 uVar1;
  undefined1 *puVar2;
  char cVar3;
  undefined4 uVar4;
  int in_ECX;
  
  puVar2 = *(undefined1 **)(in_ECX + 8);
  uVar1 = *puVar2;
  uVar4 = *(undefined4 *)(puVar2 + 4);
  if (*(int *)(puVar2 + 8) != 1) {
    return 0;
  }
  cVar3 = FUN_005494a0();
  if (cVar3 == '\x01') {
    uVar4 = FUN_00549b50(uVar4,uVar1);
    return uVar4;
  }
  cVar3 = (**(code **)(*DAT_00b5ada8 + 0x20))();
  if (cVar3 != '\0') {
    uVar4 = FUN_00549b80();
    return uVar4;
  }
  cVar3 = FUN_00549200(uVar4);
  if (cVar3 == '\x01') {
    uVar4 = FUN_00549ae0(uVar4);
    return uVar4;
  }
  cVar3 = FUN_00549230(uVar4,uVar1);
  if (cVar3 == '\x01') {
    uVar4 = FUN_00549b00(uVar4,uVar1);
    return uVar4;
  }
  cVar3 = FUN_00549280(uVar4);
  if (cVar3 == '\x01') {
    uVar4 = FUN_00549b30(uVar4);
    return uVar4;
  }
  return 0;
}


// ==== FUN_005495d0 @ 0x005495d0 ====

undefined4 FUN_005495d0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00549520();
  if (iVar1 == 0) {
    return 0;
  }
  if (*(undefined4 **)(in_ECX + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 4))(1);
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  *(int *)(in_ECX + 4) = iVar1;
  return 1;
}


// ==== FUN_00549600 @ 0x00549600 ====

undefined4 FUN_00549600(void)

{
  undefined1 *puVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_14 [4];
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar2 = FUN_00549520();
  if (iVar2 != 0) {
    if (*(undefined4 **)(in_ECX + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 4))(1);
      *(undefined4 *)(in_ECX + 4) = 0;
    }
    *(int *)(in_ECX + 4) = iVar2;
    iStack_10 = FUN_00549980(iVar2);
    if (iStack_10 != 0) {
      puVar1 = *(undefined1 **)(in_ECX + 8);
      uStack_c = *(undefined4 *)(puVar1 + 4);
      auStack_14[0] = *puVar1;
      uStack_8 = *(undefined4 *)(puVar1 + 0xc);
      uStack_4 = *(undefined4 *)(puVar1 + 0x10);
      (**(code **)(*DAT_00b5ac28 + 0x38))(auStack_14);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00549680 @ 0x00549680 ====

uint FUN_00549680(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = FUN_005498f0();
  if ((char)uVar1 != '\0') {
    uVar1 = FUN_00549440();
    if ((char)uVar1 == '\x01') {
      return uVar1;
    }
    uVar1 = *(uint *)(*(int *)(in_ECX + 8) + 8);
    if (uVar1 == 1) {
      uVar1 = FUN_00549600();
      return uVar1;
    }
    if (uVar1 == 2) {
      uVar1 = FUN_00549330();
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_005496d0 @ 0x005496d0 ====

void FUN_005496d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bac9c;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
    in_ECX[1] = 0;
  }
  in_ECX[1] = 0;
  if (DAT_00b5af54 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af54)(1);
  }
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00549720 @ 0x00549720 ====

void FUN_00549720(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009baca4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00549750 @ 0x00549750 ====

bool FUN_00549750(void)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 4))();
  return cVar1 == '\0';
}


// ==== FUN_00549760 @ 0x00549760 ====

bool FUN_00549760(void)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 4))();
  return cVar1 == '\x01';
}


// ==== FUN_00549770 @ 0x00549770 ====

undefined1 FUN_00549770(void)

{
  return 1;
}


// ==== FUN_00549780 @ 0x00549780 ====

void FUN_00549780(undefined4 param_1,undefined1 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bacc8;
  in_ECX[1] = param_1;
  *(undefined1 *)(in_ECX + 2) = param_2;
  return;
}


// ==== FUN_005497a0 @ 0x005497a0 ====

undefined4 FUN_005497a0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5ad04 + 0x18))(*(undefined4 *)(in_ECX + 4));
  if ((iVar1 == 0) ||
     (((*(char *)(in_ECX + 8) == '\0' && (*(char *)(iVar1 + 0xc) == '\0')) &&
      (*(short *)(iVar1 + 0x14) == 0)))) {
    return 0;
  }
  return 1;
}


// ==== FUN_005497e0 @ 0x005497e0 ====

bool FUN_005497e0(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)FUN_00549a40(*(undefined4 *)(in_ECX + 4));
  if (piVar2 == (int *)0x0) {
    return false;
  }
  cVar1 = (**(code **)(*piVar2 + 0x38))();
  return cVar1 != '\x01';
}


// ==== FUN_00549810 @ 0x00549810 ====

void FUN_00549810(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x10);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b9b60;
  }
  puVar1[1] = 8;
  puVar1[2] = 0;
  puVar1[3] = 0;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00549850 @ 0x00549850 ====

void FUN_00549850(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bacec;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5af54 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5af54 = in_ECX;
  return;
}


// ==== FUN_005498f0 @ 0x005498f0 ====

undefined4 FUN_005498f0(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = (**(code **)(*DAT_00b5acc4 + 4))();
  iVar2 = (**(code **)(*DAT_00b5acc0 + 0xc))(uVar1);
  if ((iVar2 == 0) || (iVar2 == 5)) {
    return 1;
  }
  return 0;
}


// ==== FUN_00549920 @ 0x00549920 ====

uint FUN_00549920(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acc4 + 4))();
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x10))();
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 4))();
      return CONCAT31((int3)((uint)iVar2 >> 8),*(byte *)(iVar2 + 0x2bbc) >> 4) & 0xffffff01;
    }
  }
  return 0;
}


// ==== FUN_00549950 @ 0x00549950 ====

byte FUN_00549950(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acc4 + 4))();
  if (piVar1 != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*piVar1 + 0x10))();
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 4))();
      return *(byte *)(iVar2 + 0x2bbc) & 1;
    }
  }
  return 0;
}


// ==== FUN_00549980 @ 0x00549980 ====

undefined4 FUN_00549980(int *param_1)

{
  uint uVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5acc4 + 4))();
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  piVar3 = (int *)(**(code **)(*piVar3 + 0x10))();
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  iVar4 = (**(code **)(*piVar3 + 4))();
  uVar1 = *(uint *)(iVar4 + 0x2bbc);
  if (((uVar1 & 0x20) != 0) && (cVar2 = (**(code **)(*param_1 + 0x14))(), cVar2 == '\x01')) {
    return 2;
  }
  if (((uVar1 & 4) != 0) && (cVar2 = (**(code **)(*param_1 + 8))(), cVar2 == '\x01')) {
    return 4;
  }
  if (((uVar1 & 2) != 0) && (cVar2 = (**(code **)(*param_1 + 0xc))(), cVar2 == '\x01')) {
    return 2;
  }
  if (((uVar1 & 8) == 0) || (cVar2 = (**(code **)(*param_1 + 0x10))(), cVar2 != '\x01')) {
    return 0;
  }
  return 8;
}


// ==== FUN_00549a40 @ 0x00549a40 ====

undefined4 FUN_00549a40(void)

{
  undefined4 uVar1;
  
  if (DAT_00b5acd8 == (int *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00549a51. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*DAT_00b5acd8 + 0xc))();
  return uVar1;
}


// ==== FUN_00549ab0 @ 0x00549ab0 ====

void FUN_00549ab0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bacec;
  DAT_00b5af54 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00549ae0 @ 0x00549ae0 ====

undefined4 FUN_00549ae0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_00549be0(param_1);
  return uVar2;
}


// ==== FUN_00549b00 @ 0x00549b00 ====

undefined4 FUN_00549b00(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_00549780(param_1,param_2);
  return uVar2;
}


// ==== FUN_00549b30 @ 0x00549b30 ====

undefined4 FUN_00549b30(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_00549c80(param_1);
  return uVar2;
}


// ==== FUN_00549b50 @ 0x00549b50 ====

undefined4 FUN_00549b50(undefined4 param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_00549d70(param_1,param_2);
  return uVar2;
}


// ==== FUN_00549b80 @ 0x00549b80 ====

undefined4 FUN_00549b80(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_00549fb0(param_1);
  return uVar2;
}


// ==== FUN_00549bb0 @ 0x00549bb0 ====

undefined1 FUN_00549bb0(void)

{
  return 0;
}


// ==== FUN_00549bc0 @ 0x00549bc0 ====

bool FUN_00549bc0(void)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 4))();
  return cVar1 == '\x01';
}


// ==== FUN_00549bd0 @ 0x00549bd0 ====

undefined1 FUN_00549bd0(void)

{
  return 1;
}


// ==== FUN_00549be0 @ 0x00549be0 ====

void FUN_00549be0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bacf4;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_00549c00 @ 0x00549c00 ====

bool FUN_00549c00(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ad98 + 8))();
  if (piVar1 == (int *)0x0) {
    return false;
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  return iVar2 == 5;
}


// ==== FUN_00549c20 @ 0x00549c20 ====

bool FUN_00549c20(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)FUN_00549a40(*(undefined4 *)(in_ECX + 4));
  if (piVar2 == (int *)0x0) {
    return false;
  }
  cVar1 = (**(code **)(*piVar2 + 0x38))();
  return cVar1 != '\x01';
}


// ==== FUN_00549c60 @ 0x00549c60 ====

undefined1 FUN_00549c60(void)

{
  return 0;
}


// ==== FUN_00549c70 @ 0x00549c70 ====

undefined1 FUN_00549c70(void)

{
  return 1;
}


// ==== FUN_00549c80 @ 0x00549c80 ====

void FUN_00549c80(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bad18;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_00549ca0 @ 0x00549ca0 ====

undefined4 FUN_00549ca0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)FUN_00549a40(*(undefined4 *)(in_ECX + 4));
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if ((iVar2 == 0) || (iVar2 == 2)) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00549cd0 @ 0x00549cd0 ====

undefined4 FUN_00549cd0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)FUN_00549a40(*(undefined4 *)(in_ECX + 4));
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if ((((iVar2 == 1) || (iVar2 == 3)) || (iVar2 == 5)) || (iVar2 == 6)) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00549d10 @ 0x00549d10 ====

bool FUN_00549d10(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)FUN_00549a40(*(undefined4 *)(in_ECX + 4));
  if (piVar2 == (int *)0x0) {
    return false;
  }
  cVar1 = (**(code **)(*piVar2 + 0x38))();
  return cVar1 != '\x01';
}


// ==== FUN_00549d50 @ 0x00549d50 ====

bool FUN_00549d50(void)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 4))();
  return cVar1 == '\x01';
}


// ==== FUN_00549d60 @ 0x00549d60 ====

undefined1 FUN_00549d60(void)

{
  return 1;
}


// ==== FUN_00549d70 @ 0x00549d70 ====

void FUN_00549d70(undefined4 param_1,undefined1 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bad3c;
  in_ECX[1] = param_1;
  *(undefined1 *)(in_ECX + 2) = param_2;
  return;
}


// ==== FUN_00549d90 @ 0x00549d90 ====

bool FUN_00549d90(void)

{
  char cVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return false;
  }
  cVar1 = (**(code **)(*DAT_00b5acac + 0x38))(*(int *)(in_ECX + 4));
  return cVar1 == '\x01';
}


// ==== FUN_00549db0 @ 0x00549db0 ====

bool FUN_00549db0(void)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  
  piVar2 = (int *)FUN_00549a40(in_ECX[1]);
  if (piVar2 == (int *)0x0) {
    return false;
  }
  cVar1 = (**(code **)(*in_ECX + 0xc))();
  if (cVar1 == '\x01') {
    return true;
  }
  cVar1 = (**(code **)(*piVar2 + 0x38))();
  return cVar1 == '\x01';
}


// ==== FUN_00549df0 @ 0x00549df0 ====

undefined4 FUN_00549df0(void)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  uint uStack_1fc;
  int *piStack_1dc;
  undefined1 auStack_1d8 [4];
  undefined4 local_1d4;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  local_1d4 = 0;
  uStack_1fc = (uint)*(byte *)(in_ECX + 8);
  cVar1 = (**(code **)(*DAT_00b5ac98 + 0x10))(*(int *)(in_ECX + 4));
  if (cVar1 == '\x01') {
    return 1;
  }
  uVar2 = (**(code **)(*DAT_00b5acac + 0xc))(auStack_1d8);
  FUN_00401660(uVar2,piStack_1dc,0xffffffff);
  FUN_00537c20();
  cVar1 = (**(code **)(*DAT_00b5ac98 + 0x14))(&uStack_1fc);
  if (cVar1 != '\x01') {
    piVar3 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
    if (piVar3 == piStack_1dc) goto switchD_00549ebe_caseD_1;
    uVar2 = (**(code **)(*piVar3 + 0xc))();
    switch(uVar2) {
    case 0:
    case 2:
      cVar1 = (**(code **)(*DAT_00b5acac + 0x38))(*(undefined4 *)(in_ECX + 4));
      goto LAB_00549ed4;
    default:
      goto switchD_00549ebe_caseD_1;
    case 5:
      goto switchD_00549ebe_caseD_5;
    case 6:
      goto switchD_00549f0c_caseD_6;
    }
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 4));
  if (piVar3 == piStack_1dc) goto switchD_00549ebe_caseD_1;
  piVar4 = (int *)(**(code **)(*piVar3 + 0x14))();
  iVar5 = (**(code **)(*piVar4 + 0x24))();
  if (iVar5 == 0) goto switchD_00549ebe_caseD_1;
  uVar2 = (**(code **)(*piVar3 + 0xc))();
  switch(uVar2) {
  case 0:
  case 2:
    cVar1 = (**(code **)(*DAT_00b5acac + 0x38))(*(undefined4 *)(in_ECX + 4));
    break;
  default:
    goto switchD_00549ebe_caseD_1;
  case 5:
  case 6:
    goto switchD_00549ebe_caseD_5;
  }
LAB_00549ed4:
  if (cVar1 == '\x01') {
switchD_00549f0c_caseD_6:
    if (*(char *)(in_ECX + 8) == '\x01') {
switchD_00549ebe_caseD_5:
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
switchD_00549ebe_caseD_1:
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_00549f80 @ 0x00549f80 ====

bool FUN_00549f80(void)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 4))();
  return cVar1 == '\0';
}


// ==== FUN_00549f90 @ 0x00549f90 ====

bool FUN_00549f90(void)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 4))();
  return cVar1 == '\x01';
}


// ==== FUN_00549fa0 @ 0x00549fa0 ====

undefined1 FUN_00549fa0(void)

{
  return 1;
}


// ==== FUN_00549fb0 @ 0x00549fb0 ====

void FUN_00549fb0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bad60;
  in_ECX[1] = param_1;
  return;
}


// ==== FUN_00549fd0 @ 0x00549fd0 ====

undefined4 FUN_00549fd0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) == 0) ||
     (piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(int *)(in_ECX + 4)), piVar2 == (int *)0x0
     )) {
    return 0;
  }
  iVar3 = (**(code **)(*piVar2 + 0xc))();
  if (iVar3 == 0) {
    cVar1 = (**(code **)(*DAT_00b5a7b8 + 0x3c))(*(undefined4 *)(in_ECX + 4));
    if (cVar1 == '\x01') {
      return 0;
    }
  }
  else if ((iVar3 == 2) &&
          (cVar1 = (**(code **)(*DAT_00b5a7b8 + 0x40))(*(undefined4 *)(in_ECX + 4)), cVar1 == '\x01'
          )) {
    return 0;
  }
  return 1;
}


// ==== FUN_0054a030 @ 0x0054a030 ====

bool FUN_0054a030(void)

{
  char cVar1;
  int *piVar2;
  int *in_ECX;
  
  piVar2 = (int *)FUN_00549a40(in_ECX[1]);
  if (piVar2 == (int *)0x0) {
    return false;
  }
  cVar1 = (**(code **)(*in_ECX + 0xc))();
  if (cVar1 == '\x01') {
    return true;
  }
  cVar1 = (**(code **)(*piVar2 + 0x38))();
  return cVar1 == '\x01';
}


// ==== FUN_0054a070 @ 0x0054a070 ====

int * FUN_0054a070(void)

{
  void *pvVar1;
  int *piVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098199b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(8);
  piVar2 = (int *)0x0;
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    piVar2 = (int *)FUN_0054a140();
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 4))();
  ExceptionList = pvStack_c;
  return piVar2;
}


// ==== FUN_0054a0d0 @ 0x0054a0d0 ====

undefined4 FUN_0054a0d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0054a0e0 @ 0x0054a0e0 ====

void FUN_0054a0e0(undefined4 param_1)

{
  code *pcVar1;
  undefined **ppuVar2;
  
  if (PTR_FUN_00aef1b4 != (undefined *)0x0) {
    ppuVar2 = &PTR_FUN_00aef1b4;
    pcVar1 = (code *)PTR_FUN_00aef1b4;
    do {
      (*pcVar1)(param_1);
      FUN_007bbdf0(param_1,0);
      pcVar1 = (code *)ppuVar2[2];
      ppuVar2 = ppuVar2 + 2;
    } while (pcVar1 != (code *)0x0);
  }
  return;
}


// ==== FUN_0054a120 @ 0x0054a120 ====

void FUN_0054a120(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    uVar1 = FUN_007bd0c0();
    *(undefined4 *)(in_ECX + 4) = uVar1;
    FUN_0054a0e0(uVar1);
  }
  return;
}


// ==== FUN_0054a140 @ 0x0054a140 ====

void FUN_0054a140(void)

{
  undefined4 *in_ECX;
  
  FUN_0054a190();
  *in_ECX = &PTR_FUN_009badfc;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_0054a160 @ 0x0054a160 ====

void FUN_0054a160(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009badfc;
  if (in_ECX[1] != 0) {
    FUN_007bd150(in_ECX[1]);
    in_ECX[1] = 0;
  }
  *in_ECX = &PTR_FUN_009badec;
  FUN_0054a230();
  return;
}


// ==== FUN_0054a190 @ 0x0054a190 ====

void FUN_0054a190(void)

{
  code *pcVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009819b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bade4;
  if (DAT_00b5a6bc == (undefined4 *)0x0) {
    DAT_00b5a6bc = in_ECX;
    ExceptionList = pvVar2;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_009badb8,0x14);
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


// ==== FUN_0054a230 @ 0x0054a230 ====

void FUN_0054a230(void)

{
  code *pcVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009819b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bade4;
  if (DAT_00b5a6bc != 0) {
    DAT_00b5a6bc = 0;
    ExceptionList = pvVar2;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_009badd0,0xc);
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


// ==== FUN_0054a2c0 @ 0x0054a2c0 ====

void FUN_0054a2c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0054a230();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054a2e0 @ 0x0054a2e0 ====

void FUN_0054a2e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009badec;
  FUN_0054a230();
  return;
}


// ==== FUN_0054a2f0 @ 0x0054a2f0 ====

void FUN_0054a2f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0054a2e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054a310 @ 0x0054a310 ====

void FUN_0054a310(byte param_1)

{
  void *in_ECX;
  
  FUN_0054a160();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054a330 @ 0x0054a330 ====

undefined4 FUN_0054a330(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009819db;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x14);
  uVar2 = 0;
  local_4 = 0;
  if (pvVar1 != (void *)0x0) {
    uVar2 = FUN_0054a410();
  }
  local_4 = 0xffffffff;
  FUN_0054aea0();
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_0054a390 @ 0x0054a390 ====

void FUN_0054a390(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb150;
  return;
}


// ==== FUN_0054a3a0 @ 0x0054a3a0 ====

void FUN_0054a3a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb150;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054a3c0 @ 0x0054a3c0 ====

undefined4 FUN_0054a3c0(void)

{
  return 0x50050002;
}


// ==== FUN_0054a3d0 @ 0x0054a3d0 ====

undefined4 FUN_0054a3d0(void)

{
  return 0x70900000;
}


// ==== FUN_0054a3e0 @ 0x0054a3e0 ====

undefined4 FUN_0054a3e0(void)

{
  return 0x70900001;
}


// ==== FUN_0054a410 @ 0x0054a410 ====

void FUN_0054a410(void)

{
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981a00;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb19c;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_Create_ViewCenter_009bae84,0x11);
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00796dd0(local_28);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_0054a4a0 @ 0x0054a4a0 ====

/* WARNING: Removing unreachable block (ram,0x0054a716) */

void FUN_0054a4a0(void)

{
  void **ppvVar1;
  undefined1 auStack_5a [2];
  void *pvStack_40;
  void *pvStack_3c;
  void *pvStack_38;
  void *pvStack_34;
  void *pvStack_30;
  void *pvStack_2c;
  void *local_28;
  uint local_24;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981a4a;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = local_24 & 0xffffff00;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  puStack_8 = (undefined1 *)0xffffffff;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_release_res_009bafa8);
  puStack_8 = (undefined1 *)0x1;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  pvStack_c = (void *)0xffffffff;
  if (0xf < uStack_18) {
    _free(pvStack_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  FUN_00401740(s_test_window_009bafb4,0xb);
  pvStack_c = (void *)0x2;
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&pvStack_30);
  local_10 = 0xffffffff;
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
  FUN_00401740(s_test_nullexception_009bafc0,0x12);
  ppvVar1 = &pvStack_34;
  local_10 = 3;
  (**(code **)(*DAT_00b5a6c8 + 0x10))();
  local_14 = 0xffffffff;
  if (0xf < uStack_20) {
    _free(pvStack_34);
    return;
  }
  uStack_20 = 0xf;
  local_24 = 0;
  pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
  FUN_00401740(s_test_stackwalk_009bafd4,0xe);
  local_14 = 4;
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&pvStack_38);
  uStack_18 = 0xffffffff;
  if (0xf < local_24) {
    _free(pvStack_38);
    return;
  }
  local_24 = 0xf;
  local_28 = (void *)0x0;
  pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
  FUN_00401740(s_test_timerate_009bafe4,0xd);
  uStack_18 = 5;
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&pvStack_3c);
  uStack_1c = 0xffffffff;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  local_28 = (void *)0xf;
  pvStack_2c = (void *)0x0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(s_resolution_009baff4,10);
  uStack_1c = 6;
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&pvStack_40);
  uStack_20 = 0xffffffff;
  if ((void *)0xf < pvStack_2c) {
    _free(pvStack_40);
    return;
  }
  FUN_00401740(s_systeminformationvisible_009bb000,0x18);
  uStack_20 = 7;
  (**(code **)(*DAT_00b5a6c8 + 0x10))(auStack_5a + -6);
  local_24 = 0xffffffff;
  FUN_0084c4a0();
  if (ppvVar1[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)ppvVar1[1])(1);
  }
  ppvVar1[1] = (void *)0x0;
  if (ppvVar1[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)ppvVar1[2])(1);
  }
  ppvVar1[2] = (void *)0x0;
  FUN_0084c500();
  ExceptionList = pvStack_2c;
  return;
}


// ==== FUN_0054a770 @ 0x0054a770 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054a770(void)

{
  float fVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_b8 [4];
  undefined1 uStack_b4;
  undefined4 uStack_ac;
  undefined4 uStack_a8;
  int *piStack_a4;
  int local_84;
  undefined1 *puStack_80;
  void *pvStack_78;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  void *pvStack_64;
  void *pvStack_5c;
  undefined4 uStack_54;
  uint uStack_50;
  undefined4 uStack_4c;
  void *pvStack_48;
  void *pvStack_40;
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981a9e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if ((DAT_00b5af68 & 1) == 0) {
    DAT_00b5af68 = DAT_00b5af68 | 1;
    local_4 = 0;
    ExceptionList = &pvStack_c;
    DAT_00b5af64 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  }
  if ((DAT_00b5af68 & 2) == 0) {
    DAT_00b5af68 = DAT_00b5af68 | 2;
    local_4 = 1;
    DAT_00b5af60 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  }
  local_4 = 0xffffffff;
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  if ((DAT_00b5af68 & 4) == 0) {
    DAT_00b5af68 = DAT_00b5af68 | 4;
    DAT_00b5af5c = uVar2 - DAT_00b5af60;
  }
  if (DAT_00b5af5c < uVar2 - DAT_00b5af60) {
    DAT_00b5af5c = uVar2 - DAT_00b5af60;
  }
  _DAT_00b5af58 = _DAT_00b5af58 + 1;
  DAT_00b5af60 = uVar2;
  if (DAT_00b5af64 + 1000 < uVar2) {
    pvStack_48 = (void *)0xf;
    uStack_4c = 0;
    pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
    _piStack_a4 = (double)CONCAT44(0x54a87a,piStack_a4);
    FUN_00401740();
    local_4 = 2;
    puStack_80 = auStack_b8;
    _piStack_a4 = 3.18299368644791e-313;
    uStack_b4 = 0;
    FUN_00401740();
    FUN_00404230();
    local_4 = CONCAT31(local_4._1_3_,3);
    _piStack_a4 = (double)CONCAT44(0x54a8f5,piStack_a4);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_34) {
      _piStack_a4 = (double)CONCAT44(pvStack_48,0x54a90a);
      _free(pvStack_48);
      return;
    }
    uStack_34 = 0xf;
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    pvStack_c = (void *)0xffffffff;
    if (0xf < uStack_50) {
      _piStack_a4 = (double)CONCAT44(pvStack_64,0x54a934);
      _free(pvStack_64);
      return;
    }
    if (DAT_00b5af5c == 0) {
      _piStack_a4 = 1.69810073743673e-313;
      uStack_6c = 0xf;
      uStack_70 = 0;
      puStack_80 = (undefined1 *)((uint)puStack_80 & 0xffffff00);
      uStack_a8 = 0x54aa2d;
      FUN_00401740();
      _piStack_a4 = (double)_DAT_0099d098;
      uStack_a8 = 0xf;
      uStack_ac = 0;
      pvStack_c = (void *)0x6;
      FUN_00401740(&DAT_009bb034,2);
      uVar3 = FUN_00404230(&uStack_30);
      _piStack_a4 = (double)CONCAT44(uVar3,&local_84);
      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,7);
      uStack_a8 = 0x54aa89;
      (**(code **)(*DAT_00b5a688 + 8))();
      if (0xf < uStack_10) {
        _free(pvStack_24);
        return;
      }
      uStack_10 = 0xf;
      uStack_14 = 0;
      pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      local_4 = 0xffffffff;
      if ((void *)0xf < pvStack_64) {
        _free(pvStack_78);
        return;
      }
      pvStack_64 = (void *)0xf;
      uStack_68 = 0;
      pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
    }
    else {
      _piStack_a4 = 1.69810073664623e-313;
      uStack_50 = 0xf;
      uStack_54 = 0;
      pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
      uStack_a8 = 0x54a95f;
      FUN_00401740();
      fVar1 = (float)(int)DAT_00b5af5c;
      pvStack_c = (void *)0x4;
      if ((int)DAT_00b5af5c < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
      uStack_a8 = 0xf;
      uStack_ac = 0;
      _piStack_a4 = (double)(DAT_009b012c / fVar1);
      FUN_00401740(&DAT_009bb024,2);
      uVar3 = FUN_00404230(&uStack_4c);
      _piStack_a4 = (double)CONCAT44(uVar3,&uStack_68);
      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);
      uStack_a8 = 0x54a9cd;
      (**(code **)(*DAT_00b5a688 + 8))();
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return;
      }
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      local_4 = 0xffffffff;
      if (0xf < pvStack_48) {
        _free(pvStack_5c);
        return;
      }
    }
    local_4 = 0xffffffff;
    _DAT_00b5af58 = 0;
    DAT_00b5af5c = 0;
    DAT_00b5af64 = uVar2;
  }
  (**(code **)(**(int **)(local_84 + 4) + 8))();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0054ab20 @ 0x0054ab20 ====

void FUN_0054ab20(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981ab0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009bb19c;
  local_4 = 0;
  if (in_ECX[4] != 0) {
    (**(code **)(*DAT_00b5a7a4 + 8))(in_ECX[4]);
  }
  FUN_0054a4a0();
  *in_ECX = &PTR_FUN_009bb150;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0054ab80 @ 0x0054ab80 ====

void FUN_0054ab80(void)

{
  char cVar1;
  undefined *puVar2;
  undefined1 *xRight;
  undefined4 *puVar3;
  char *pcVar4;
  int *piVar5;
  undefined4 uVar6;
  HWND hWnd;
  int iVar7;
  int in_ECX;
  int iVar8;
  int unaff_EBP;
  uint uVar9;
  HWND hWndInsertAfter;
  undefined4 *puVar10;
  uint uVar11;
  int in_stack_00000010;
  tagRECT tStack_b8;
  undefined1 uStack_a8;
  undefined4 uStack_a0;
  uint uStack_9c;
  undefined4 uStack_98;
  void *pvStack_94;
  undefined1 auStack_90 [12];
  undefined4 uStack_84;
  uint uStack_80;
  undefined4 uStack_70;
  undefined1 uStack_6b;
  void *pvStack_18;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = -1;
  puStack_8 = &LAB_00981ade;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af70 + 0x34))();
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6e4 + 8))();
  puVar10 = &uStack_70;
  for (iVar8 = 0x19; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar10 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar10 = puVar10 + 1;
  }
  uStack_6b = in_stack_00000010 != 0;
  (**(code **)(*DAT_00b5a6e4 + 0x10))(&uStack_70);
  FUN_0084c4a0();
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  puVar2 = PTR_s_WindowHandle_00aef218;
  *(undefined4 *)(in_ECX + 8) = 0;
  pvStack_94 = (void *)0xf;
  uStack_98 = 0;
  uStack_a8 = 0;
  pcVar4 = puVar2;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(puVar2,(int)pcVar4 - (int)(puVar2 + 1));
  puStack_8 = (undefined1 *)0x0;
  piVar5 = (int *)(**(code **)(*DAT_00b5a688 + 0xc))();
  uVar6 = (**(code **)(*piVar5 + 8))(auStack_90,&tStack_b8.bottom);
  uStack_10 = CONCAT31(uStack_10._1_3_,1);
  hWnd = (HWND)thunk_FUN_00796e90(uVar6);
  if (0xf < uStack_80) {
    _free(pvStack_94);
    return;
  }
  uStack_80 = 0xf;
  uStack_84 = 0;
  pvStack_94 = (void *)((uint)pvStack_94 & 0xffffff00);
  uStack_10 = 0xffffffff;
  if (0xf < uStack_9c) {
    _free((void *)tStack_b8.right);
    return;
  }
  uStack_9c = 0xf;
  uStack_a0 = 0;
  iVar8 = GetSystemMetrics(0);
  xRight = puStack_8;
  uVar9 = iVar8 - (int)puStack_8;
  iVar7 = GetSystemMetrics(1);
  iVar8 = iStack_4;
  uVar11 = iVar7 - iStack_4;
  iVar7 = (**(code **)(*DAT_00b5a6b0 + 8))();
  if (iVar7 == 1) {
LAB_0054ae14:
    SetRect((LPRECT)(auStack_90 + -0x38),0,0,(int)xRight,iVar8);
LAB_0054ae1a:
    SetWindowLongA(hWnd,-0x10,-0x6ff80000);
    SetMenu(hWnd,(HMENU)0x0);
    if (unaff_EBP != 0) {
      hWndInsertAfter = (HWND)0xffffffff;
      goto LAB_0054ad6d;
    }
  }
  else if ((iVar7 == 2) || (iVar7 == 4)) {
    if (unaff_EBP != 0) goto LAB_0054ae14;
LAB_0054ad62:
    SetWindowLongA(hWnd,-0x10,0x10ca0000);
  }
  else {
    if (unaff_EBP != 0) goto LAB_0054ae1a;
    iVar7 = GetSystemMetrics(1);
    if (iVar7 != iVar8) goto LAB_0054ad62;
    SetWindowLongA(hWnd,-0x10,-0x6ff80000);
    SetMenu(hWnd,(HMENU)0x0);
  }
  hWndInsertAfter = (HWND)0xfffffffe;
LAB_0054ad6d:
  iVar7 = GetSystemMetrics(1);
  if (iVar7 != iVar8) {
    AdjustWindowRect((LPRECT)(auStack_90 + -0x38),0x10ca0000,0);
  }
  SetWindowPos(hWnd,hWndInsertAfter,uVar9 >> 1,uVar11 >> 1,(int)xRight,iVar8,0x40);
  FUN_0084c480();
  piVar5 = operator_new(4);
  uStack_10 = 2;
  if (piVar5 == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    FUN_0054b8b0();
    *piVar5 = (int)&PTR_FUN_009bb1e0;
  }
  uStack_10 = 0xffffffff;
  (**(code **)(*piVar5 + 4))();
  *(int **)(tStack_b8.left + 8) = piVar5;
  (**(code **)(*DAT_00b5af70 + 0x38))();
  (**(code **)(*DAT_00b5a74c + 0x10))();
  ExceptionList = pvStack_18;
  return;
}


// ==== FUN_0054aea0 @ 0x0054aea0 ====

/* WARNING: Removing unreachable block (ram,0x0054b1bd) */

void FUN_0054aea0(void)

{
  int *_Memory;
  undefined4 uVar1;
  int in_ECX;
  uint unaff_EBX;
  void *unaff_ESI;
  int *piVar2;
  undefined1 auStackY_100 [32];
  undefined1 auStack_ae [10];
  undefined1 *puStack_98;
  undefined1 auStack_7c [4];
  void *pvStack_78;
  void *pvStack_74;
  void *pvStack_70;
  uint uStack_6c;
  void *pvStack_68;
  uint uStack_64;
  void *pvStack_60;
  void *pvStack_5c;
  undefined4 uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981b4b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0084c480();
  FUN_0084c5c0();
  _Memory = operator_new(4);
  local_4 = 0;
  if (_Memory == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_0054b8b0();
    *_Memory = (int)&PTR_FUN_009bb1e0;
    piVar2 = _Memory;
  }
  local_4 = 0xffffffff;
  (**(code **)(*piVar2 + 4))();
  *(int **)(in_ECX + 8) = piVar2;
  uVar1 = FUN_0058f2c0();
  *(undefined4 *)(in_ECX + 4) = uVar1;
  uStack_64 = 0xf;
  pvStack_68 = (void *)0x0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  FUN_00401740();
  local_4 = 1;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  pvStack_c = (void *)0xffffffff;
  if (0xf < uStack_6c) {
    _free(_Memory);
    return;
  }
  uStack_6c = 0xf;
  pvStack_70 = (void *)0x0;
  FUN_00401740();
  pvStack_c = (void *)0x2;
  (**(code **)(*DAT_00b5a6c8 + 0xc))();
  uStack_14 = 0xffffffff;
  if ((void *)0xf < pvStack_74) {
    _free(unaff_ESI);
    return;
  }
  uStack_3c = 0xf;
  uStack_40 = 0;
  uStack_50 = uStack_50 & 0xffffff00;
  FUN_00401740();
  uStack_14 = 3;
  pvStack_74 = (void *)0xf;
  pvStack_78 = (void *)0x0;
  FUN_00401740();
  uStack_14 = CONCAT31(uStack_14._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 4))();
  if (0xf < unaff_EBX) {
    _free(auStack_7c);
    return;
  }
  puStack_98 = auStackY_100;
  uStack_24 = 0xffffffff;
  if (0xf < uStack_4c) {
    _free(pvStack_60);
    return;
  }
  uStack_4c = 0xf;
  uStack_50 = 0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  FUN_00401740(s_test_window_009baef8);
  uStack_24 = 5;
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&uStack_64);
  uStack_2c = 0xffffffff;
  if (0xf < uStack_54) {
    _free(pvStack_68);
    return;
  }
  uStack_54 = 0xf;
  uStack_58 = 0;
  pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
  FUN_00401740(s_release_res_009baf04,0xb);
  uStack_2c = 6;
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&uStack_6c);
  uStack_34 = 0xffffffff;
  if (0xf < pvStack_5c) {
    _free(pvStack_70);
    return;
  }
  pvStack_5c = (void *)0xf;
  pvStack_60 = (void *)0x0;
  pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
  FUN_00401740(s_sleep_009baf10,5);
  uStack_34 = 7;
  (**(code **)(*DAT_00b5a6c8 + 0xc))(&pvStack_74,1);
  uStack_3c = 0xffffffff;
  if (0xf < uStack_64) {
    _free(pvStack_78);
    return;
  }
  uStack_64 = 0xf;
  pvStack_68 = (void *)0x0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  FUN_00401740(s_resolution__w___h___bpp___true_f_009baf18,0x25);
  uStack_3c = 8;
  FUN_00401740(s_resolution_009baf40,10);
  uStack_3c = CONCAT31(uStack_3c._1_3_,9);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_ae + -6,4,auStack_7c);
  uStack_48 = 0xffffffff;
  if (0xf < pvStack_70) {
    _free((void *)0xf);
    return;
  }
  uStack_54 = 0xf;
  uStack_58 = 0;
  pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
  FUN_00401740(s_systeminformationvisible_arg0____009baf4c,0x36);
  uStack_48 = 10;
  FUN_00401740(s_systeminformationvisible_009baf84,0x18);
  uStack_48 = CONCAT31(uStack_48._1_3_,0xb);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_ae + 10,1,&uStack_6c);
  if ((undefined1 *)0xf < puStack_98) {
    _free((void *)0x0);
    return;
  }
  if (pvStack_60 < 0x10) {
    ExceptionList = pvStack_5c;
    return;
  }
  _free(pvStack_74);
  return;
}


// ==== FUN_0054b2a0 @ 0x0054b2a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0054b2a0(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX_01;
  void *pvVar6;
  int in_ECX;
  float10 fVar7;
  undefined1 local_98 [4];
  void *local_94;
  undefined4 local_84;
  uint local_80;
  undefined1 local_7c [32];
  float fStack_5c;
  float fStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981bcf;
  local_c = ExceptionList;
  iVar1 = param_1 + 8;
  ExceptionList = &local_c;
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_test_nullexception_009bb044,0x12);
  if (iVar3 == 0) {
    local_80 = 0xf;
    local_84 = 0;
    local_94 = (void *)((uint)local_94 & 0xffffff00);
    FUN_00401740(s_NULL_Exception_009bb058,0xe);
    local_4 = 0;
    FUN_00401870(local_98);
    local_4 = 0xffffffff;
    if (0xf < local_80) {
      _free(local_94);
      return extraout_EAX;
    }
    _DAT_00000000 = 0;
    FUN_00401630();
    uVar5 = 1;
  }
  else {
    iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_test_stackwalk_009bb068,0xe);
    if (iVar3 == 0) {
      local_80 = 0xf;
      local_84 = 0;
      local_94 = (void *)((uint)local_94 & 0xffffff00);
      FUN_00401740(&DAT_009bb078,4);
      local_4 = 1;
      FUN_00406880(local_98);
      if (0xf < local_80) {
        _free(local_94);
        return extraout_EAX_00;
      }
      uVar5 = 1;
    }
    else {
      iVar3 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_test_timerate_009bb080,0xd);
      if (iVar3 == 0) {
        uStack_54 = (**(code **)(*DAT_00b5a6ac + 0x18))();
        uStack_50 = (**(code **)(*DAT_00b5a6ac + 0x1c))();
        uStack_4c = (**(code **)(*DAT_00b5a6ac + 0x20))();
        puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6ac + 0xc))();
        uStack_48 = *puVar4;
        uStack_44 = puVar4[1];
        uStack_40 = puVar4[2];
        uStack_3c = puVar4[3];
        puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6ac + 0x10))();
        uStack_38 = *puVar4;
        uStack_34 = puVar4[1];
        uStack_30 = puVar4[2];
        uStack_2c = puVar4[3];
        uVar5 = FUN_00459160(local_98,0);
        local_4 = 2;
        fVar7 = (float10)thunk_FUN_00796ec0(uVar5);
        fStack_5c = (float)fVar7;
        local_4 = 0xffffffff;
        if (0xf < local_80) {
          _free(local_94);
          return extraout_EAX_01;
        }
        if ((*(int *)(param_1 + 0x28) != 0) &&
           (1 < (uint)((*(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x28)) / 0x1c))) {
          uVar5 = FUN_00459160(local_7c,1);
          local_4 = 3;
          fVar7 = (float10)thunk_FUN_00796ec0(uVar5);
          fStack_58 = (float)fVar7;
          local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        fStack_58 = (float)DAT_0099d080;
        if (DAT_00b5a6ac != (int *)0x0) {
          (**(code **)*DAT_00b5a6ac)(1);
        }
        pvVar6 = operator_new(0xb0);
        local_4 = 4;
        if (pvVar6 != (void *)0x0) {
          FUN_00797e00(&fStack_5c);
        }
        uVar5 = 1;
      }
      else {
        cVar2 = FUN_004036a0(iVar1,s_test_window_009bb090);
        if (cVar2 != '\0') {
          FUN_00401830(s_UI_Test_ui_test_txt_009bb09c);
          local_4 = 5;
          uVar5 = (**(code **)(*DAT_00b5af6c + 4))(local_98);
          *(undefined4 *)(in_ECX + 0x10) = uVar5;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar2 = FUN_004036a0(iVar1,s_release_res_009bb0b0);
        if (cVar2 != '\0') {
          uVar5 = FUN_00459160(local_7c,0);
          local_4 = 6;
          (**(code **)(*DAT_00b5a7cc + 0x24))(uVar5);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar2 = FUN_004036a0(iVar1,s_sleep_009bb0bc);
        if (cVar2 != '\0') {
          uVar5 = FUN_00459160(local_7c,0);
          local_4 = 7;
          uVar5 = thunk_FUN_00796fb0(uVar5);
          *(undefined4 *)(in_ECX + 0xc) = uVar5;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar2 = FUN_004036a0(iVar1,s_resolution_009bb0c4);
        if (cVar2 != '\0') {
          uVar5 = FUN_00459160(local_7c,0);
          local_4 = 8;
          thunk_FUN_00796fb0(uVar5);
          local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar2 = FUN_004036a0(iVar1,s_systeminformationvisible_009bb0d0);
        if (cVar2 != '\0') {
          uVar5 = FUN_00459160(local_28,0);
          local_4 = 0xc;
          FUN_004036e0(uVar5,&DAT_009bb0ec);
          local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        uVar5 = 0;
      }
    }
  }
  ExceptionList = local_c;
  return uVar5;
}


// ==== FUN_0054b7f0 @ 0x0054b7f0 ====

bool FUN_0054b7f0(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    if (*(DWORD *)(in_ECX + 0xc) != 0) {
      Sleep(*(DWORD *)(in_ECX + 0xc));
    }
  }
  else if (iVar2 == 0x70004) {
    cVar1 = FUN_0054b2a0(param_1);
    if (cVar1 != '\0') {
      return true;
    }
  }
  else if (iVar2 == -0x60000000) {
    FUN_0054ab80(param_1[1],param_1[2],param_1[3],(uint)param_1[3] >> 8 & 0xff);
    (**(code **)(*DAT_00b5a748 + 4))();
    puVar3 = operator_new(4);
    if (puVar3 == (undefined4 *)0x0) {
      FUN_00797a20(0);
      return true;
    }
    *puVar3 = &PTR_FUN_009bb160;
    FUN_00797a20(puVar3);
    return true;
  }
  cVar1 = (**(code **)(**(int **)(in_ECX + 4) + 4))(param_1);
  return cVar1 != '\0';
}


// ==== FUN_0054b8b0 @ 0x0054b8b0 ====

void FUN_0054b8b0(void)

{
  code *pcVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981be8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb1ac;
  if (DAT_00b5a9d0 == (undefined4 *)0x0) {
    DAT_00b5a9d0 = in_ECX;
    ExceptionList = pvVar2;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_ms_pInstance____NULL_009bb0f0,0x14);
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


// ==== FUN_0054b950 @ 0x0054b950 ====

void FUN_0054b950(void)

{
  code *pcVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar2 = ExceptionList;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981be8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb1ac;
  if (DAT_00b5a9d0 != 0) {
    DAT_00b5a9d0 = 0;
    ExceptionList = pvVar2;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(s_ms_pInstance_009bb108,0xc);
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


// ==== FUN_0054b9e0 @ 0x0054b9e0 ====

void FUN_0054b9e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0054b950();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054ba00 @ 0x0054ba00 ====

void FUN_0054ba00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb1b4;
  FUN_0054b950();
  return;
}


// ==== FUN_0054ba10 @ 0x0054ba10 ====

void FUN_0054ba10(byte param_1)

{
  void *in_ECX;
  
  FUN_0054ba00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054ba30 @ 0x0054ba30 ====

void FUN_0054ba30(byte param_1)

{
  void *in_ECX;
  
  FUN_0054ab20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054ba50 @ 0x0054ba50 ====

void FUN_0054ba50(byte param_1)

{
  void *in_ECX;
  
  FUN_0084c700();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054ba70 @ 0x0054ba70 ====

undefined4 FUN_0054ba70(void)

{
  return DAT_00b5ac04;
}


// ==== FUN_0054ba80 @ 0x0054ba80 ====

void FUN_0054ba80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb210;
  return;
}


// ==== FUN_0054ba90 @ 0x0054ba90 ====

void FUN_0054ba90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb210;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054bab0 @ 0x0054bab0 ====

void FUN_0054bab0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00981c1e;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb218;
  pvVar1 = operator_new(0x1c);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0054d0c0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    in_ECX[2] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0054bd40();
  in_ECX[2] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0054bb60 @ 0x0054bb60 ====

void FUN_0054bb60(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981c30;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009bb218;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009bb210;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0054bbd0 @ 0x0054bbd0 ====

void FUN_0054bbd0(byte param_1)

{
  void *in_ECX;
  
  FUN_0054bb60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054bbf0 @ 0x0054bbf0 ====

void FUN_0054bbf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb220;
  return;
}


// ==== FUN_0054bc00 @ 0x0054bc00 ====

void FUN_0054bc00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb220;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054bc20 @ 0x0054bc20 ====

void FUN_0054bc20(ushort *param_1)

{
  ushort uVar1;
  ushort uVar2;
  int *in_ECX;
  ushort uVar3;
  ushort local_14;
  ushort local_12;
  undefined1 local_10 [4];
  undefined1 local_c;
  undefined1 local_b;
  
  in_ECX[2] = *(int *)param_1;
  local_c = 1;
  local_b = 1;
  uVar2 = 0;
  if (*param_1 != 0) {
    uVar1 = param_1[1];
    do {
      uVar3 = 0;
      if (uVar1 != 0) {
        do {
          local_14 = uVar2;
          local_12 = uVar3;
          (**(code **)(*in_ECX + 0xc))(&local_14,local_10);
          uVar1 = param_1[1];
          uVar3 = uVar3 + 1;
        } while (uVar3 < uVar1);
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < *param_1);
  }
  return;
}


// ==== FUN_0054bcb0 @ 0x0054bcb0 ====

int FUN_0054bcb0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0054bcc0 @ 0x0054bcc0 ====

void FUN_0054bcc0(ushort *param_1,undefined4 *param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  if ((*param_1 < *(ushort *)(in_ECX + 8)) && (param_1[1] < *(ushort *)(in_ECX + 10))) {
    iVar1 = *(int *)(in_ECX + 4);
    iVar2 = (uint)param_1[1] * 0x200 + (uint)*param_1;
    *(undefined4 *)(iVar1 + 4 + iVar2 * 8) = *param_2;
    *(undefined4 *)(iVar1 + 8 + iVar2 * 8) = param_2[1];
  }
  return;
}


// ==== FUN_0054bd00 @ 0x0054bd00 ====

int FUN_0054bd00(ushort *param_1)

{
  int in_ECX;
  
  if ((*param_1 < *(ushort *)(in_ECX + 8)) && (param_1[1] < *(ushort *)(in_ECX + 10))) {
    return *(int *)(in_ECX + 4) + 4 + ((uint)param_1[1] * 0x200 + (uint)*param_1) * 8;
  }
  return *(int *)(in_ECX + 4) + 4;
}


// ==== FUN_0054bd40 @ 0x0054bd40 ====

void FUN_0054bd40(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981c48;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb240;
  puVar1 = operator_new(0x200008);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009bb238;
    puVar1[0x80001] = 0;
  }
  in_ECX[1] = puVar1;
  puVar1[0x80001] = puVar1[0x80001] + 0x40000;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a718 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a718 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0054bde0 @ 0x0054bde0 ====

void FUN_0054bde0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981c5a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb240;
  DAT_00b5a718 = 0;
  *(int *)(in_ECX[1] + 0x200004) = *(int *)(in_ECX[1] + 0x200004) + -0x40000;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009bb220;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0054be50 @ 0x0054be50 ====

void FUN_0054be50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb238;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054be70 @ 0x0054be70 ====

void FUN_0054be70(byte param_1)

{
  void *in_ECX;
  
  FUN_0054bde0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054be90 @ 0x0054be90 ====

void FUN_0054be90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb258;
  return;
}


// ==== FUN_0054bea0 @ 0x0054bea0 ====

void FUN_0054bea0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb258;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054bec0 @ 0x0054bec0 ====

void FUN_0054bec0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb270;
  return;
}


// ==== FUN_0054bed0 @ 0x0054bed0 ====

void FUN_0054bed0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb28c;
  return;
}


// ==== FUN_0054bee0 @ 0x0054bee0 ====

void FUN_0054bee0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb2e4;
  return;
}


// ==== FUN_0054bef0 @ 0x0054bef0 ====

void FUN_0054bef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb270;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054bf10 @ 0x0054bf10 ====

void FUN_0054bf10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb28c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054bf30 @ 0x0054bf30 ====

void FUN_0054bf30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb2e4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054bfa0 @ 0x0054bfa0 ====

undefined4 FUN_0054bfa0(float *param_1,float *param_2,float param_3,float param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  float fVar8;
  
  pfVar3 = param_5;
  iVar6 = (int)*param_2;
  iVar7 = (int)*param_1;
  if (iVar7 < iVar6) {
    while( true ) {
      fVar8 = (float)iVar7;
      fVar1 = *param_1;
      fVar2 = param_1[1];
      param_5 = (float *)CONCAT22(param_5._2_2_,(short)iVar7);
      uVar4 = FUN_00802534();
      param_5 = (float *)CONCAT22(uVar4,param_5._0_2_);
      iVar5 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_5);
      if (*(char *)(iVar5 + 4) == '\0') break;
      iVar7 = iVar7 + 1;
      *pfVar3 = fVar8;
      pfVar3[1] = (fVar8 - fVar1) * (param_4 / param_3) + fVar2;
      if (iVar6 < iVar7) {
        return 1;
      }
    }
  }
  else {
    while( true ) {
      fVar8 = (float)iVar7;
      fVar1 = *param_1;
      fVar2 = param_1[1];
      param_5 = (float *)CONCAT22(param_5._2_2_,(short)iVar7);
      uVar4 = FUN_00802534();
      param_5 = (float *)CONCAT22(uVar4,param_5._0_2_);
      iVar5 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_5);
      if (*(char *)(iVar5 + 4) == '\0') break;
      iVar7 = iVar7 + -1;
      *pfVar3 = fVar8;
      pfVar3[1] = (fVar8 - fVar1) * (param_4 / param_3) + fVar2;
      if (iVar7 < iVar6) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_0054c0e0 @ 0x0054c0e0 ====

undefined4
FUN_0054c0e0(float *param_1,undefined4 param_2,float param_3,float param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float *pfVar3;
  undefined2 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  float fVar8;
  
  uVar5 = FUN_00802534();
  uVar5 = uVar5 & 0xffff;
  uVar6 = FUN_00802534();
  pfVar3 = param_5;
  uVar6 = uVar6 & 0xffff;
  if (uVar5 < uVar6) {
    while( true ) {
      fVar8 = (float)(int)uVar5;
      fVar1 = param_1[1];
      fVar2 = *param_1;
      uVar4 = FUN_00802534();
      param_5 = (float *)CONCAT22((short)uVar5,uVar4);
      iVar7 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_5);
      if (*(char *)(iVar7 + 4) == '\0') break;
      uVar5 = uVar5 + 1;
      *pfVar3 = (fVar8 - fVar1) * (param_3 / param_4) + fVar2;
      pfVar3[1] = fVar8;
      if ((int)uVar6 < (int)uVar5) {
        return 1;
      }
    }
  }
  else {
    while( true ) {
      fVar8 = (float)(int)uVar5;
      fVar1 = param_1[1];
      fVar2 = *param_1;
      uVar4 = FUN_00802534();
      param_5 = (float *)CONCAT22((short)uVar5,uVar4);
      iVar7 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_5);
      if (*(char *)(iVar7 + 4) == '\0') break;
      uVar5 = uVar5 - 1;
      *pfVar3 = (fVar8 - fVar1) * (param_3 / param_4) + fVar2;
      pfVar3[1] = fVar8;
      if ((int)uVar5 < (int)uVar6) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_0054c210 @ 0x0054c210 ====

undefined1 FUN_0054c210(uint *param_1,undefined2 param_2)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  short sVar3;
  undefined2 uStack0000000a;
  
  if (*(char *)(in_ECX + 0x10) == '\x01') {
    if ((char)param_2 == '\0') {
      uVar2 = *param_1;
      sVar3 = (short)(uVar2 >> 0x10);
    }
    else {
      uVar2 = (uint)*(ushort *)((int)param_1 + 2);
      sVar3 = (short)*param_1;
    }
    if (((*(short *)(in_ECX + 0x12) == (short)uVar2) && (*(short *)(in_ECX + 0x14) == sVar3)) ||
       ((*(short *)(in_ECX + 0x16) == (short)uVar2 && (*(short *)(in_ECX + 0x18) == sVar3)))) {
      return 1;
    }
  }
  if ((char)param_2 == '\0') {
    iVar1 = (**(code **)(*DAT_00b5a718 + 0x10))(param_1);
    return *(undefined1 *)(iVar1 + 4);
  }
  param_2 = *(undefined2 *)((int)param_1 + 2);
  uStack0000000a = (undefined2)*param_1;
  iVar1 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_2);
  return *(undefined1 *)(iVar1 + 4);
}


// ==== FUN_0054c2b0 @ 0x0054c2b0 ====

undefined1 FUN_0054c2b0(uint *param_1,undefined2 param_2)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  short sVar3;
  undefined2 uStack0000000a;
  
  if (*(char *)(in_ECX + 0x10) == '\x01') {
    if ((char)param_2 == '\0') {
      uVar2 = *param_1;
      sVar3 = (short)(uVar2 >> 0x10);
    }
    else {
      uVar2 = (uint)*(ushort *)((int)param_1 + 2);
      sVar3 = (short)*param_1;
    }
    if (((*(short *)(in_ECX + 0x12) == (short)uVar2) && (*(short *)(in_ECX + 0x14) == sVar3)) ||
       ((*(short *)(in_ECX + 0x16) == (short)uVar2 && (*(short *)(in_ECX + 0x18) == sVar3)))) {
      return 1;
    }
  }
  if ((char)param_2 == '\0') {
    iVar1 = (**(code **)(*DAT_00b5a718 + 0x10))(param_1);
    return *(undefined1 *)(iVar1 + 5);
  }
  param_2 = *(undefined2 *)((int)param_1 + 2);
  uStack0000000a = (undefined2)*param_1;
  iVar1 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_2);
  return *(undefined1 *)(iVar1 + 5);
}


// ==== FUN_0054c350 @ 0x0054c350 ====

undefined4 FUN_0054c350(undefined4 param_1)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iStack00000008;
  undefined4 uVar4;
  undefined4 uVar5;
  short local_8;
  short sStack_6;
  undefined2 uStack_4;
  
  sVar1 = FUN_00802534();
  local_8 = sVar1;
  sStack_6 = FUN_00802534();
  if (((*(char *)(in_ECX + 0x10) == '\x01') &&
      (((*(short *)(in_ECX + 0x12) == sVar1 && (*(short *)(in_ECX + 0x14) == sStack_6)) ||
       ((*(short *)(in_ECX + 0x16) == sVar1 && (*(short *)(in_ECX + 0x18) == sStack_6)))))) ||
     (iVar2 = (**(code **)(*DAT_00b5a718 + 0x10))(&local_8), *(char *)(iVar2 + 4) != '\0')) {
    FUN_0054e3b0(CONCAT22(sStack_6,local_8),CONCAT22(uStack_4,sStack_6));
    return param_1;
  }
  iStack00000008 = -1;
  do {
    iVar2 = -1;
    do {
      if ((iStack00000008 != 0) || (iVar2 != 0)) {
        sVar1 = FUN_00802534();
        local_8 = sVar1;
        sStack_6 = FUN_00802534();
        if (((*(char *)(in_ECX + 0x10) == '\x01') &&
            (((*(short *)(in_ECX + 0x12) == sVar1 && (*(short *)(in_ECX + 0x14) == sStack_6)) ||
             ((*(short *)(in_ECX + 0x16) == sVar1 && (*(short *)(in_ECX + 0x18) == sStack_6)))))) ||
           (iVar3 = (**(code **)(*DAT_00b5a718 + 0x10))(&local_8), *(char *)(iVar3 + 4) != '\0')) {
          uVar5 = CONCAT22(uStack_4,sStack_6);
          uVar4 = CONCAT22(sStack_6,local_8);
          goto LAB_0054c498;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 2);
    iStack00000008 = iStack00000008 + 1;
    if (1 < iStack00000008) {
      local_8 = FUN_00802534();
      sStack_6 = FUN_00802534();
      uVar5 = CONCAT22(uStack_4,sStack_6);
      uVar4 = CONCAT22(sStack_6,local_8);
LAB_0054c498:
      FUN_0054e3b0(uVar4,uVar5);
      return param_1;
    }
  } while( true );
}


// ==== FUN_0054c4c0 @ 0x0054c4c0 ====

void FUN_0054c4c0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981c78;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009bb304;
  DAT_00b5a800 = 0;
  local_4 = 0;
  (**(code **)(*(int *)in_ECX[2] + 0x20))();
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_009bb258;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0054c540 @ 0x0054c540 ====

void FUN_0054c540(float *param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *param_2 - *param_1;
  fVar3 = param_2[1] - param_1[1];
  if (fVar1 <= 0.0) {
    fVar4 = 0.0 - fVar1;
  }
  else {
    fVar4 = fVar1;
  }
  if (fVar3 <= 0.0) {
    fVar2 = 0.0 - fVar3;
  }
  else {
    fVar2 = fVar3;
  }
  if (fVar2 <= fVar4) {
    FUN_0054bfa0(param_1,param_2,fVar1,fVar3,param_3);
    return;
  }
  FUN_0054c0e0(param_1,param_2,fVar1,fVar3,param_3);
  return;
}


// ==== FUN_0054c5c0 @ 0x0054c5c0 ====

undefined4 FUN_0054c5c0(undefined4 param_1,ushort *param_2,ushort *param_3,undefined4 *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  ushort uVar5;
  char cVar6;
  char cVar7;
  short sVar8;
  short sVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  uint local_24;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 local_8;
  undefined4 local_6;
  
  uVar4 = *param_2;
  uVar5 = *param_3;
  uVar10 = (uint)uVar5;
  if (uVar4 != uVar5) {
    fVar14 = *(float *)(param_3 + 2) - *(float *)(param_2 + 2);
    fVar1 = *(float *)(param_3 + 4);
    fVar2 = *(float *)(param_2 + 4);
    if (fVar14 <= 0.0) {
      fVar15 = 0.0 - fVar14;
    }
    else {
      fVar15 = fVar14;
    }
    if (DAT_0099d0ec <= fVar15) {
      uVar12 = (uint)uVar4;
      if (uVar4 < uVar5) {
        uVar12 = uVar12 + 1;
        iVar11 = 1;
      }
      else {
        uVar10 = uVar10 + 1;
        iVar11 = -1;
      }
      uVar4 = param_2[1];
      uVar5 = param_3[1];
      do {
        if (uVar12 == uVar10 + iVar11) {
          *param_4 = *(undefined4 *)param_3;
          param_4[1] = *(undefined4 *)(param_3 + 2);
          param_4[2] = *(undefined4 *)(param_3 + 4);
          return 0;
        }
        fVar15 = *(float *)(param_2 + 2);
        fVar3 = *(float *)(param_2 + 4);
        if (iVar11 == 1) {
          uVar13 = uVar12;
          local_24 = uVar12 - 1;
        }
        else {
          uVar13 = uVar12 - 1;
          local_24 = uVar12;
        }
        local_10 = (short)uVar13;
        sVar8 = FUN_00802534();
        local_e = CONCAT22(local_e._2_2_,sVar8);
        local_8 = (short)uVar13;
        sVar9 = FUN_00802534();
        local_6 = CONCAT22(local_6._2_2_,sVar9);
        if (sVar8 == sVar9) {
          cVar6 = FUN_0054c210(&local_10,param_1);
          if (cVar6 != '\x01') {
LAB_0054c7b0:
            param_4[1] = (float)(int)uVar12;
            *(undefined2 *)param_4 = (undefined2)local_24;
            *(undefined2 *)((int)param_4 + 2) = (undefined2)local_e;
            param_4[2] = ((float)(int)uVar12 - fVar15) * ((fVar1 - fVar2) / fVar14) + fVar3;
            return 1;
          }
        }
        else {
          cVar6 = FUN_0054c210(&local_10,param_1);
          cVar7 = FUN_0054c210(&local_8,param_1);
          if ((cVar6 != '\x01') || (cVar7 != '\x01')) {
            if ((-(uVar4 < uVar5) & 2U) != 2) {
              local_e._0_2_ = (undefined2)local_6;
            }
            goto LAB_0054c7b0;
          }
        }
        uVar12 = uVar12 + iVar11;
      } while( true );
    }
    cVar6 = FUN_0054c210(param_3,param_1);
    if (cVar6 == '\0') {
      *param_4 = *(undefined4 *)param_2;
      param_4[1] = *(undefined4 *)(param_2 + 2);
      param_4[2] = *(undefined4 *)(param_2 + 4);
      return 1;
    }
    *param_4 = *(undefined4 *)param_3;
    param_4[1] = *(undefined4 *)(param_3 + 2);
    param_4[2] = *(undefined4 *)(param_3 + 4);
  }
  return 0;
}


// ==== FUN_0054c7f0 @ 0x0054c7f0 ====

undefined4 FUN_0054c7f0(undefined2 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined2 local_24;
  undefined2 local_22;
  undefined4 local_20;
  undefined4 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  undefined2 local_a;
  undefined4 local_8;
  undefined4 local_4;
  
  local_18 = param_1[1];
  local_14 = *(undefined4 *)(param_1 + 4);
  local_16 = *param_1;
  local_10 = *(undefined4 *)(param_1 + 2);
  local_24 = *(undefined2 *)((int)param_2 + 2);
  local_22 = *(undefined2 *)param_2;
  local_20 = param_2[2];
  local_1c = param_2[1];
  cVar1 = FUN_0054c5c0(1,&local_18,&local_24,&local_c);
  if (cVar1 == '\0') {
    *param_3 = *param_2;
    param_3[1] = param_2[1];
    param_3[2] = param_2[2];
    return 0;
  }
  param_3[1] = local_4;
  *(undefined2 *)param_3 = local_a;
  *(undefined2 *)((int)param_3 + 2) = local_c;
  param_3[2] = local_8;
  return 1;
}


// ==== FUN_0054c8c0 @ 0x0054c8c0 ====

undefined4 FUN_0054c8c0(undefined4 param_1,ushort *param_2,ushort *param_3,undefined4 *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  ushort uVar5;
  char cVar6;
  char cVar7;
  short sVar8;
  short sVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  float fVar14;
  float fVar15;
  uint local_24;
  undefined2 local_10;
  undefined4 local_e;
  undefined2 local_8;
  undefined4 local_6;
  
  uVar4 = *param_2;
  uVar5 = *param_3;
  uVar10 = (uint)uVar5;
  if (uVar4 != uVar5) {
    fVar14 = *(float *)(param_3 + 2) - *(float *)(param_2 + 2);
    fVar1 = *(float *)(param_3 + 4);
    fVar2 = *(float *)(param_2 + 4);
    if (fVar14 <= 0.0) {
      fVar15 = 0.0 - fVar14;
    }
    else {
      fVar15 = fVar14;
    }
    if (DAT_0099d0ec <= fVar15) {
      uVar12 = (uint)uVar4;
      if (uVar4 < uVar5) {
        uVar12 = uVar12 + 1;
        iVar11 = 1;
      }
      else {
        uVar10 = uVar10 + 1;
        iVar11 = -1;
      }
      uVar4 = param_2[1];
      uVar5 = param_3[1];
      do {
        if (uVar12 == uVar10 + iVar11) {
          *param_4 = *(undefined4 *)param_3;
          param_4[1] = *(undefined4 *)(param_3 + 2);
          param_4[2] = *(undefined4 *)(param_3 + 4);
          return 0;
        }
        fVar15 = *(float *)(param_2 + 2);
        fVar3 = *(float *)(param_2 + 4);
        if (iVar11 == 1) {
          uVar13 = uVar12;
          local_24 = uVar12 - 1;
        }
        else {
          uVar13 = uVar12 - 1;
          local_24 = uVar12;
        }
        local_10 = (short)uVar13;
        sVar8 = FUN_00802534();
        local_e = CONCAT22(local_e._2_2_,sVar8);
        local_8 = (short)uVar13;
        sVar9 = FUN_00802534();
        local_6 = CONCAT22(local_6._2_2_,sVar9);
        if (sVar8 == sVar9) {
          cVar6 = FUN_0054c2b0(&local_10,param_1);
          if (cVar6 != '\x01') {
LAB_0054cab0:
            param_4[1] = (float)(int)uVar12;
            *(undefined2 *)param_4 = (undefined2)local_24;
            *(undefined2 *)((int)param_4 + 2) = (undefined2)local_e;
            param_4[2] = ((float)(int)uVar12 - fVar15) * ((fVar1 - fVar2) / fVar14) + fVar3;
            return 1;
          }
        }
        else {
          cVar6 = FUN_0054c2b0(&local_10,param_1);
          cVar7 = FUN_0054c2b0(&local_8,param_1);
          if ((cVar6 != '\x01') || (cVar7 != '\x01')) {
            if ((-(uVar4 < uVar5) & 2U) != 2) {
              local_e._0_2_ = (undefined2)local_6;
            }
            goto LAB_0054cab0;
          }
        }
        uVar12 = uVar12 + iVar11;
      } while( true );
    }
    cVar6 = FUN_0054c2b0(param_3,param_1);
    if (cVar6 == '\0') {
      *param_4 = *(undefined4 *)param_2;
      param_4[1] = *(undefined4 *)(param_2 + 2);
      param_4[2] = *(undefined4 *)(param_2 + 4);
      return 1;
    }
    *param_4 = *(undefined4 *)param_3;
    param_4[1] = *(undefined4 *)(param_3 + 2);
    param_4[2] = *(undefined4 *)(param_3 + 4);
  }
  return 0;
}


// ==== FUN_0054caf0 @ 0x0054caf0 ====

undefined4 FUN_0054caf0(undefined2 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  char cVar1;
  undefined2 local_24;
  undefined2 local_22;
  undefined4 local_20;
  undefined4 local_1c;
  undefined2 local_18;
  undefined2 local_16;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  undefined2 local_a;
  undefined4 local_8;
  undefined4 local_4;
  
  local_18 = param_1[1];
  local_14 = *(undefined4 *)(param_1 + 4);
  local_16 = *param_1;
  local_10 = *(undefined4 *)(param_1 + 2);
  local_24 = *(undefined2 *)((int)param_2 + 2);
  local_22 = *(undefined2 *)param_2;
  local_20 = param_2[2];
  local_1c = param_2[1];
  cVar1 = FUN_0054c8c0(1,&local_18,&local_24,&local_c);
  if (cVar1 == '\0') {
    *param_3 = *param_2;
    param_3[1] = param_2[1];
    param_3[2] = param_2[2];
    return 0;
  }
  param_3[1] = local_4;
  *(undefined2 *)param_3 = local_a;
  *(undefined2 *)((int)param_3 + 2) = local_c;
  param_3[2] = local_8;
  return 1;
}


// ==== FUN_0054cbc0 @ 0x0054cbc0 ====

undefined4 FUN_0054cbc0(uint *param_1,uint *param_2,uint *param_3,char param_4)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  short sStack00000012;
  uint local_18;
  float fStack_14;
  float fStack_10;
  uint uStack_c;
  float fStack_8;
  float fStack_4;
  
  *(char *)(in_ECX + 0x10) = param_4;
  uVar1 = *param_1;
  *(uint *)(in_ECX + 0x12) = uVar1;
  *(uint *)(in_ECX + 0x16) = *param_2;
  if (param_4 == '\x01') {
    sVar4 = (short)*param_1;
    sStack00000012 = (short)(*param_1 >> 0x10);
    if ((((short)uVar1 == sVar4) && (*(short *)(in_ECX + 0x14) == sStack00000012)) ||
       ((*(short *)(in_ECX + 0x16) == sVar4 && (*(short *)(in_ECX + 0x18) == sStack00000012))))
    goto LAB_0054cc3d;
  }
  iVar5 = (**(code **)(*DAT_00b5a718 + 0x10))(param_1);
  if (*(char *)(iVar5 + 4) == '\0') {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 1;
  }
LAB_0054cc3d:
  cVar2 = FUN_0054c5c0(0,param_1,param_2,&local_18);
  cVar3 = FUN_0054c7f0(param_1,param_2,&uStack_c);
  if (cVar2 == '\0') {
    if (cVar3 == '\0') {
      *param_3 = *param_2;
      param_3[1] = param_2[1];
      param_3[2] = param_2[2];
      *(undefined1 *)(in_ECX + 0x10) = 0;
      return 0;
    }
    *param_3 = uStack_c;
    param_3[1] = (uint)fStack_8;
    param_3[2] = (uint)fStack_4;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 1;
  }
  if (cVar3 == '\0') {
    *param_3 = local_18;
    param_3[1] = (uint)fStack_14;
    param_3[2] = (uint)fStack_10;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 1;
  }
  iVar5 = (uint)(ushort)*param_1 - (local_18 & 0xffff);
  iVar8 = (uint)*(ushort *)((int)param_1 + 2) - (local_18 >> 0x10);
  if (iVar5 < 1) {
    iVar5 = -iVar5;
  }
  if (iVar8 < 1) {
    iVar8 = -iVar8;
  }
  iVar6 = (uint)(ushort)*param_1 - (uStack_c & 0xffff);
  iVar7 = (uint)*(ushort *)((int)param_1 + 2) - (uStack_c >> 0x10);
  if (iVar6 < 1) {
    iVar6 = -iVar6;
  }
  if (iVar7 < 1) {
    iVar7 = -iVar7;
  }
  if ((uint)(iVar5 + iVar8) < (uint)(iVar6 + iVar7)) {
    *param_3 = local_18;
    param_3[1] = (uint)fStack_14;
    param_3[2] = (uint)fStack_10;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 1;
  }
  if ((uint)(iVar6 + iVar7) < (uint)(iVar5 + iVar8)) {
    *param_3 = uStack_c;
    param_3[1] = (uint)fStack_8;
    param_3[2] = (uint)fStack_4;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 1;
  }
  fVar9 = (float)param_1[1] - fStack_14;
  fVar12 = (float)param_1[2] - fStack_10;
  if (fVar9 <= 0.0) {
    fVar9 = 0.0 - fVar9;
  }
  if (fVar12 <= 0.0) {
    fVar12 = 0.0 - fVar12;
  }
  fVar11 = (float)param_1[2] - fStack_4;
  fVar10 = (float)param_1[1] - fStack_8;
  if (fVar10 <= 0.0) {
    fVar10 = 0.0 - fVar10;
  }
  if (fVar11 <= 0.0) {
    fVar11 = 0.0 - fVar11;
  }
  if (fVar11 + fVar10 <= fVar12 + fVar9) {
    *param_3 = uStack_c;
    param_3[1] = (uint)fStack_8;
    param_3[2] = (uint)fStack_4;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 1;
  }
  *param_3 = local_18;
  param_3[1] = (uint)fStack_14;
  param_3[2] = (uint)fStack_10;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  return 1;
}


// ==== FUN_0054ce40 @ 0x0054ce40 ====

undefined4 FUN_0054ce40(uint *param_1,uint *param_2,uint *param_3,char param_4)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  int iVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  short sStack00000012;
  uint local_18;
  float fStack_14;
  float fStack_10;
  uint uStack_c;
  float fStack_8;
  float fStack_4;
  
  *(char *)(in_ECX + 0x10) = param_4;
  uVar1 = *param_1;
  *(uint *)(in_ECX + 0x12) = uVar1;
  *(uint *)(in_ECX + 0x16) = *param_2;
  if (param_4 == '\x01') {
    sVar4 = (short)*param_1;
    sStack00000012 = (short)(*param_1 >> 0x10);
    if ((((short)uVar1 == sVar4) && (*(short *)(in_ECX + 0x14) == sStack00000012)) ||
       ((*(short *)(in_ECX + 0x16) == sVar4 && (*(short *)(in_ECX + 0x18) == sStack00000012))))
    goto LAB_0054cebd;
  }
  iVar5 = (**(code **)(*DAT_00b5a718 + 0x10))(param_1);
  if (*(char *)(iVar5 + 5) == '\0') {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 1;
  }
LAB_0054cebd:
  cVar2 = FUN_0054c8c0(0,param_1,param_2,&local_18);
  cVar3 = FUN_0054caf0(param_1,param_2,&uStack_c);
  if (cVar2 == '\0') {
    if (cVar3 == '\0') {
      *param_3 = *param_2;
      param_3[1] = param_2[1];
      param_3[2] = param_2[2];
      *(undefined1 *)(in_ECX + 0x10) = 0;
      return 0;
    }
    *param_3 = uStack_c;
    param_3[1] = (uint)fStack_8;
    param_3[2] = (uint)fStack_4;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 1;
  }
  if (cVar3 == '\0') {
    *param_3 = local_18;
    param_3[1] = (uint)fStack_14;
    param_3[2] = (uint)fStack_10;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 1;
  }
  iVar5 = (uint)(ushort)*param_1 - (local_18 & 0xffff);
  iVar8 = (uint)*(ushort *)((int)param_1 + 2) - (local_18 >> 0x10);
  if (iVar5 < 1) {
    iVar5 = -iVar5;
  }
  if (iVar8 < 1) {
    iVar8 = -iVar8;
  }
  iVar6 = (uint)(ushort)*param_1 - (uStack_c & 0xffff);
  iVar7 = (uint)*(ushort *)((int)param_1 + 2) - (uStack_c >> 0x10);
  if (iVar6 < 1) {
    iVar6 = -iVar6;
  }
  if (iVar7 < 1) {
    iVar7 = -iVar7;
  }
  if ((uint)(iVar5 + iVar8) < (uint)(iVar6 + iVar7)) {
    *param_3 = local_18;
    param_3[1] = (uint)fStack_14;
    param_3[2] = (uint)fStack_10;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 1;
  }
  if ((uint)(iVar6 + iVar7) < (uint)(iVar5 + iVar8)) {
    *param_3 = uStack_c;
    param_3[1] = (uint)fStack_8;
    param_3[2] = (uint)fStack_4;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 1;
  }
  fVar9 = (float)param_1[1] - fStack_14;
  fVar12 = (float)param_1[2] - fStack_10;
  if (fVar9 <= 0.0) {
    fVar9 = 0.0 - fVar9;
  }
  if (fVar12 <= 0.0) {
    fVar12 = 0.0 - fVar12;
  }
  fVar11 = (float)param_1[2] - fStack_4;
  fVar10 = (float)param_1[1] - fStack_8;
  if (fVar10 <= 0.0) {
    fVar10 = 0.0 - fVar10;
  }
  if (fVar11 <= 0.0) {
    fVar11 = 0.0 - fVar11;
  }
  if (fVar11 + fVar10 <= fVar12 + fVar9) {
    *param_3 = uStack_c;
    param_3[1] = (uint)fStack_8;
    param_3[2] = (uint)fStack_4;
    *(undefined1 *)(in_ECX + 0x10) = 0;
    return 1;
  }
  *param_3 = local_18;
  param_3[1] = (uint)fStack_14;
  param_3[2] = (uint)fStack_10;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  return 1;
}


// ==== FUN_0054d0c0 @ 0x0054d0c0 ====

void FUN_0054d0c0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00981cab;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb304;
  pvVar1 = operator_new(0x1818);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0054d840();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0x242c);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0054de80(in_ECX[3]);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x30);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0054ed20();
  }
  in_ECX[1] = uVar2;
  *(undefined1 *)(in_ECX + 4) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a800 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a800 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0054d1b0 @ 0x0054d1b0 ====

undefined4 FUN_0054d1b0(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int in_ECX;
  undefined4 *puVar7;
  undefined1 uStack00000000;
  undefined4 local_18;
  void *pvStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar2 = param_3;
  puVar7 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981cc5;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  if (*(int *)(param_3 + 0x804) != 0) {
    ExceptionList = &pvStack_c;
    *(undefined4 *)(param_3 + 0x804) = 0;
  }
  FUN_0054c350(&param_3,param_1);
  local_18 = param_3;
  local_4 = 0;
  puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a718 + 0x10))(&local_18);
  puVar1 = param_1;
  local_18 = *puVar4;
  if (*(char *)(puVar4 + 1) == '\0') {
    puStack_8 = (undefined1 *)0xffffffff;
    FUN_0054e3d0();
    ExceptionList = pvStack_10;
    return 0;
  }
  FUN_0054c350(&uStack00000000,param_1);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
  iVar5 = (**(code **)(*DAT_00b5a718 + 0x10))((int)register0x00000010 + -0x1c);
  if (*(char *)(iVar5 + 4) == '\0') {
LAB_0054d2ac:
    pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
    FUN_0054e3d0();
    pvStack_c = (void *)0xffffffff;
    FUN_0054e3d0();
    ExceptionList = pvStack_14;
    return 0;
  }
  cVar3 = FUN_0054d7b0(puVar7,puVar1);
  if (cVar3 == '\x01') {
    *(int *)(iVar2 + 0x804) = *(int *)(iVar2 + 0x804) + 2;
    *(undefined4 *)(iVar2 + 4) = *puVar7;
    *(undefined4 *)(iVar2 + 8) = puVar7[1];
    *(undefined4 *)(iVar2 + 0xc) = *puVar1;
    *(undefined4 *)(iVar2 + 0x10) = puVar1[1];
  }
  else {
    cVar3 = FUN_0054db30(&param_1,&local_4,2000);
    if (cVar3 == '\0') goto LAB_0054d2ac;
    FUN_0054e160();
    piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
    iVar5 = *piVar6;
    *(undefined4 *)(iVar5 + 4) = *puVar7;
    *(undefined4 *)(iVar5 + 8) = puVar7[1];
    piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x10))();
    iVar5 = *piVar6;
    *(undefined4 *)(iVar5 + 4) = *puVar1;
    *(undefined4 *)(iVar5 + 8) = puVar1[1];
    piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
    if (piVar6 != (int *)0x0) {
      puVar7 = (undefined4 *)(iVar2 + 4);
      do {
        *(int *)(iVar2 + 0x804) = *(int *)(iVar2 + 0x804) + 1;
        iVar5 = *piVar6;
        *puVar7 = *(undefined4 *)(iVar5 + 4);
        puVar7[1] = *(undefined4 *)(iVar5 + 8);
        puVar7 = puVar7 + 2;
        piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar6);
      } while (piVar6 != (int *)0x0);
    }
    (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  }
  pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
  FUN_0054e3d0();
  pvStack_c = (void *)0xffffffff;
  FUN_0054e3d0();
  ExceptionList = pvStack_14;
  return 1;
}


// ==== FUN_0054d3e0 @ 0x0054d3e0 ====

undefined4 FUN_0054d3e0(float *param_1,float *param_2,float param_3,float param_4)

{
  float fVar1;
  int iVar2;
  undefined2 uVar3;
  int iVar4;
  float *pfVar5;
  short sVar6;
  undefined1 uStack00000000;
  float local_4;
  
  local_4 = param_4 / param_3;
  if (param_3 < DAT_0099cdc8) {
    fVar1 = *param_2;
    pfVar5 = param_1;
  }
  else {
    fVar1 = *param_1;
    pfVar5 = param_2;
  }
  param_4 = (float)(int)*pfVar5;
  param_3 = (float)((int)fVar1 + 1);
  if ((int)param_4 < (int)param_3) {
    return 1;
  }
  while( true ) {
    iVar2 = (int)param_3;
    sVar6 = SUB42(param_3,0);
    param_2 = (float *)CONCAT22(param_2._2_2_,sVar6);
    param_3 = ((float)(int)param_3 - *param_1) * local_4 + param_1[1];
    uVar3 = FUN_00802534();
    param_2 = (float *)CONCAT22(uVar3,param_2._0_2_);
    iVar4 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_2);
    if (*(char *)(iVar4 + 4) == '\0') {
      return 0;
    }
    uVar3 = FUN_00802534();
    param_1 = (float *)CONCAT22(uVar3,sVar6);
    iVar4 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_1);
    if (*(char *)(iVar4 + 4) == '\0') {
      return 0;
    }
    iVar4 = (**(code **)(*DAT_00b5a718 + 0x10))(&uStack00000000);
    if (*(char *)(iVar4 + 4) == '\0') {
      return 0;
    }
    local_4 = (float)CONCAT22(uVar3,sVar6 + -1);
    iVar4 = (**(code **)(*DAT_00b5a718 + 0x10))(&local_4);
    if (*(char *)(iVar4 + 4) == '\0') break;
    param_3 = (float)(iVar2 + 1);
    if ((int)param_4 < (int)param_3) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0054d550 @ 0x0054d550 ====

undefined4 FUN_0054d550(float *param_1,undefined4 param_2,float param_3,float param_4)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  float *pfVar5;
  short sVar6;
  undefined1 uStack00000000;
  float local_4;
  
  pfVar5 = param_1;
  local_4 = param_3 / param_4;
  if (param_4 < DAT_0099cdc8) {
    uVar2 = FUN_00802534();
    pfVar5 = param_1;
    uVar3 = FUN_00802534();
  }
  else {
    uVar2 = FUN_00802534();
    uVar3 = FUN_00802534();
  }
  param_1 = (float *)(uVar3 & 0xffff);
  param_3 = (float)((uVar2 & 0xffff) + 1);
  if ((uint)param_3 <= param_1) {
    do {
      uVar2 = (uint)param_3;
      param_3 = ((float)(int)param_3 - pfVar5[1]) * local_4 + *pfVar5;
      param_2._0_2_ = FUN_00802534();
      sVar6 = (short)uVar2;
      param_2._2_2_ = sVar6;
      iVar4 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_2);
      if (*(char *)(iVar4 + 4) == '\0') {
        return 0;
      }
      uVar1 = FUN_00802534();
      param_3 = (float)CONCAT22(sVar6,uVar1);
      param_1 = (float *)param_3;
      iVar4 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_1);
      if (*(char *)(iVar4 + 4) == '\0') {
        return 0;
      }
      iVar4 = (**(code **)(*DAT_00b5a718 + 0x10))(&uStack00000000);
      if (*(char *)(iVar4 + 4) == '\0') {
        return 0;
      }
      local_4 = (float)CONCAT22(sVar6 + -1,uVar1);
      iVar4 = (**(code **)(*DAT_00b5a718 + 0x10))(&local_4);
      if (*(char *)(iVar4 + 4) == '\0') {
        return 0;
      }
      param_3 = (float)(uVar2 + 1);
    } while ((int)param_3 <= (int)param_1);
  }
  return 1;
}


// ==== FUN_0054d6d0 @ 0x0054d6d0 ====

void FUN_0054d6d0(void)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int in_ECX;
  uint unaff_ESI;
  uint uVar4;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981cd8;
  pvStack_c = ExceptionList;
  uVar4 = 0;
  ExceptionList = &pvStack_c;
  iVar1 = FUN_0054e850();
  if (iVar1 != 0) {
    do {
      puVar2 = (uint *)FUN_0054e870(uVar4);
      if (puVar2 != (uint *)0x0) {
        uVar3 = *puVar2;
        local_4 = 0;
        puVar2 = (uint *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))(1,0);
        *puVar2 = uVar4;
        puVar2[1] = unaff_ESI;
        puVar2[2] = uVar3;
        (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
        local_4 = 0xffffffff;
        FUN_0054e3d0();
      }
      uVar4 = uVar4 + 1;
      uVar3 = FUN_0054e850();
    } while (uVar4 < uVar3);
  }
  FUN_0054e880();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0054d7b0 @ 0x0054d7b0 ====

void FUN_0054d7b0(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *param_2 - *param_1;
  fVar3 = param_2[1] - param_1[1];
  if (fVar1 <= 0.0) {
    fVar4 = 0.0 - fVar1;
  }
  else {
    fVar4 = fVar1;
  }
  if (fVar3 <= 0.0) {
    fVar2 = 0.0 - fVar3;
  }
  else {
    fVar2 = fVar3;
  }
  if (fVar2 <= fVar4) {
    FUN_0054d3e0(param_1,param_2,fVar1,fVar3);
    return;
  }
  FUN_0054d550(param_1,param_2,fVar1,fVar3);
  return;
}


// ==== FUN_0054d820 @ 0x0054d820 ====

void FUN_0054d820(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb2fc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x18,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0054d840 @ 0x0054d840 ====

void FUN_0054d840(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981cf8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb31c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009bb2fc;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x18,0x100,FUN_00419fa0,FUN_006ef6d0);
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


// ==== FUN_0054d8f0 @ 0x0054d8f0 ====

void * FUN_0054d8f0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981d1b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x1814);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x180c) = *(int *)(in_ECX + 0x180c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x18);
      *(undefined4 *)((int)param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x1810);
      *(void **)(in_ECX + 0x1810) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x1814) = *(undefined4 *)((int)param_2 + 0xc);
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
                           s_d__usa_24_0_1_2__develop_share_n_009bb330,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x14) = *(int *)((int)param_2 + 0x14) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0054d9d0 @ 0x0054d9d0 ====

undefined4 FUN_0054d9d0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x14) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_n_009bb330,0xa9);
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


// ==== FUN_0054da50 @ 0x0054da50 ====

void FUN_0054da50(byte param_1)

{
  void *in_ECX;
  
  FUN_0054d820();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054da70 @ 0x0054da70 ====

void FUN_0054da70(byte param_1)

{
  void *in_ECX;
  
  FUN_0054da90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054da90 @ 0x0054da90 ====

void FUN_0054da90(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981d43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb31c;
  local_4 = 1;
  if ((void *)in_ECX[0x604] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009bb2fc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x18,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009bb270;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x604]);
  return;
}


// ==== FUN_0054db10 @ 0x0054db10 ====

void FUN_0054db10(byte param_1)

{
  void *in_ECX;
  
  FUN_0054c4c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054db30 @ 0x0054db30 ====

undefined4 FUN_0054db30(undefined4 param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  FUN_0054eb50(param_1,param_2);
  uVar2 = 0;
  do {
    iVar1 = FUN_0054ec60();
    uVar2 = uVar2 + 1;
    if (param_3 < uVar2) {
      FUN_0054ea90();
      return 0;
    }
  } while (iVar1 == 1);
  if (iVar1 == 2) {
    FUN_0054d6d0();
    return 1;
  }
  if (iVar1 == 3) {
    FUN_0054e880();
    return 0;
  }
  return 0;
}


// ==== FUN_0054dbb0 @ 0x0054dbb0 ====

void FUN_0054dbb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb394;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x24,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0054dbd0 @ 0x0054dbd0 ====

void FUN_0054dbd0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981d63;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb39c;
  local_4 = 1;
  if ((void *)in_ECX[0x904] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009bb394;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x24,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009bb2e4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x904]);
  return;
}


// ==== FUN_0054dc50 @ 0x0054dc50 ====

undefined4 FUN_0054dc50(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x20) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_n_009bb330,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x20);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x20);
    }
    *(undefined4 *)(param_2 + 0x18) = *(undefined4 *)(in_ECX + 0x2414);
    *(int *)(in_ECX + 0x240c) = *(int *)(in_ECX + 0x240c) + -1;
    *(int *)(in_ECX + 0x2414) = param_2;
  }
  return 0;
}


// ==== FUN_0054dcd0 @ 0x0054dcd0 ====

undefined4 * FUN_0054dcd0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[8] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_n_009bb330,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[8] = param_2[8] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x2414);
  *(int *)(in_ECX + 0x240c) = *(int *)(in_ECX + 0x240c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x24);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[7] = *(undefined4 *)(in_ECX + 0x2410);
    *(undefined4 **)(in_ECX + 0x2410) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x2414) = puVar2[6];
  }
  puVar2[6] = 0;
  puVar2[8] = param_1;
  return puVar2;
}


// ==== FUN_0054dd90 @ 0x0054dd90 ====

void FUN_0054dd90(byte param_1)

{
  void *in_ECX;
  
  FUN_0054dbb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054ddb0 @ 0x0054ddb0 ====

void FUN_0054ddb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0054dbd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054ddd0 @ 0x0054ddd0 ====

void FUN_0054ddd0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981d78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb39c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009bb394;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x24,0x100,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x902] = 0;
  in_ECX[0x902] = in_ECX[0x902] + 0x100;
  in_ECX[0x905] = in_ECX + 2;
  in_ECX[0x903] = 0;
  in_ECX[0x904] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[8] = puVar1 + 0xb;
    puVar1[9] = 0;
    puVar1[10] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 9;
  } while (iVar2 != 0);
  in_ECX[0x8ff] = 0;
  in_ECX[0x900] = 0;
  in_ECX[0x901] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0054de80 @ 0x0054de80 ====

void FUN_0054de80(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981da3;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009bb3b4;
  FUN_0054ddd0();
  in_ECX[3] = param_1;
  local_4 = CONCAT31(local_4._1_3_,1);
  puVar1 = (undefined4 *)(**(code **)(in_ECX[5] + 0xc))(1,0);
  in_ECX[1] = puVar1;
  *puVar1 = 0;
  *(undefined4 *)(in_ECX[1] + 8) = in_ECX[1];
  *(undefined4 *)(in_ECX[1] + 0xc) = in_ECX[1];
  *(undefined4 *)(in_ECX[1] + 0x10) = in_ECX[1];
  *(undefined1 *)(in_ECX[1] + 0x14) = 1;
  in_ECX[2] = in_ECX[1];
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_0054df10 @ 0x0054df10 ====

void FUN_0054df10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    FUN_0054df30(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_0054df30 @ 0x0054df30 ====

void FUN_0054df30(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != *(int *)(in_ECX + 4)) {
    FUN_0054df30(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != *(int *)(in_ECX + 4)) {
    FUN_0054df30(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0054df70 @ 0x0054df70 ====

void FUN_0054df70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    FUN_0054df90(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_0054df90 @ 0x0054df90 ====

void FUN_0054df90(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != *(int *)(in_ECX + 4)) {
    FUN_0054df90(param_1[2]);
  }
  if (param_1[3] != *(int *)(in_ECX + 4)) {
    FUN_0054df90(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0054e000 @ 0x0054e000 ====

void FUN_0054e000(uint *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  if (puVar1 != *(undefined4 **)(in_ECX + 4)) {
    do {
      if (*param_1 < *(uint *)*puVar1) {
        puVar1 = (undefined4 *)puVar1[2];
      }
      else {
        if (*param_1 <= *(uint *)*puVar1) {
          return;
        }
        puVar1 = (undefined4 *)puVar1[3];
      }
    } while (puVar1 != *(undefined4 **)(in_ECX + 4));
  }
  return;
}


// ==== FUN_0054e030 @ 0x0054e030 ====

int FUN_0054e030(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(iVar1 + 0xc);
  if (*(char *)(iVar2 + 0x14) == '\0') {
    *(undefined1 *)(iVar2 + 0x14) = 1;
    *(undefined1 *)(iVar1 + 0x14) = 0;
    FUN_00457010(iVar1);
    iVar2 = *(int *)(iVar1 + 0xc);
  }
  if (*(char *)(*(int *)(iVar2 + 0xc) + 0x14) == '\x01') {
    *(undefined1 *)(iVar2 + 0x14) = 0;
    if (*(char *)(*(int *)(iVar2 + 8) + 0x14) == '\x01') {
      return iVar1;
    }
    *(undefined1 *)(*(int *)(iVar2 + 8) + 0x14) = 1;
    FUN_00457070(iVar2);
    iVar2 = *(int *)(iVar1 + 0xc);
  }
  *(undefined1 *)(iVar2 + 0x14) = *(undefined1 *)(iVar1 + 0x14);
  *(undefined1 *)(iVar1 + 0x14) = 1;
  *(undefined1 *)(*(int *)(iVar2 + 0xc) + 0x14) = 1;
  FUN_00457010(iVar1);
  return *(int *)(in_ECX + 8);
}


// ==== FUN_0054e0b0 @ 0x0054e0b0 ====

void FUN_0054e0b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0054e0d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054e0d0 @ 0x0054e0d0 ====

void FUN_0054e0d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00981da3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb3b4;
  local_4 = 1;
  if (in_ECX[2] != in_ECX[1]) {
    FUN_0054df90(in_ECX[2]);
    in_ECX[2] = in_ECX[1];
  }
  FUN_0054e140();
  local_4 = local_4 & 0xffffff00;
  FUN_0054dbd0();
  *in_ECX = &PTR_FUN_009bb28c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0054e140 @ 0x0054e140 ====

void FUN_0054e140(void)

{
  int in_ECX;
  
  (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,*(undefined4 *)(in_ECX + 4));
  *(undefined4 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_0054e160 @ 0x0054e160 ====

void FUN_0054e160(void)

{
  char cVar1;
  void *pvVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int in_ECX;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00981dbb;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  pvVar2 = operator_new(0x242c);
  iVar8 = 0;
  local_c = 0;
  if (pvVar2 == (void *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)FUN_0054de80(*(undefined4 *)(in_ECX + 0xc));
  }
  local_c = 0xffffffff;
  uVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  if (1 < uVar4) {
    for (piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))(); piVar5 != (int *)0x0;
        piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar5)) {
      fStack_20 = *(float *)(*piVar5 + 4);
      fStack_1c = *(float *)(*piVar5 + 8);
      piVar6 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))(1,0);
      fVar10 = fStack_24 + DAT_0099d0b4;
      iVar8 = iVar8 + 1;
      piVar6[1] = (int)(fStack_28 + DAT_0099d0b4);
      *piVar6 = iVar8;
      piVar6[2] = (int)fVar10;
      (**(code **)(*piVar3 + 0x24))(piVar6);
    }
    (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
    piVar5 = (int *)(**(code **)(*piVar3 + 8))();
    if (piVar5 != (int *)0x0) {
      do {
        fStack_20 = *(float *)(*piVar5 + 4);
        fStack_1c = *(float *)(*piVar5 + 8);
        puVar7 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))(1,0);
        *puVar7 = *(undefined4 *)*piVar5;
        iVar8 = *piVar5;
        puVar7[1] = *(undefined4 *)(iVar8 + 4);
        puVar7[2] = *(undefined4 *)(iVar8 + 8);
        (**(code **)(**(int **)(in_ECX + 8) + 0x24))(puVar7);
        for (piVar6 = (int *)(**(code **)(*piVar3 + 0x10))(); piVar6 != piVar5;
            piVar6 = (int *)(**(code **)(*piVar3 + 0x50))(piVar6)) {
          fStack_28 = *(float *)(*piVar6 + 4);
          fStack_24 = *(float *)(*piVar6 + 8);
          fVar10 = fStack_28 - fStack_20;
          fVar11 = fStack_24 - fStack_1c;
          if (fVar10 <= 0.0) {
            fVar12 = 0.0 - fVar10;
          }
          else {
            fVar12 = fVar10;
          }
          if (fVar11 <= 0.0) {
            fVar9 = 0.0 - fVar11;
          }
          else {
            fVar9 = fVar11;
          }
          if (fVar12 < fVar9) {
            cVar1 = FUN_0054d550(&fStack_20,&fStack_28,fVar10,fVar11);
          }
          else {
            cVar1 = FUN_0054d3e0(&fStack_20,&fStack_28,fVar10,fVar11);
          }
          if (cVar1 == '\x01') goto LAB_0054e367;
        }
        piVar6 = (int *)(**(code **)(*piVar3 + 0x48))(piVar5);
LAB_0054e367:
        piVar5 = piVar6;
      } while (piVar6 != (int *)0x0);
    }
    (**(code **)(*piVar3 + 0x20))();
    (**(code **)*piVar3)(1);
  }
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_0054e3a0 @ 0x0054e3a0 ====

void FUN_0054e3a0(void)

{
  undefined2 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_0054e3b0 @ 0x0054e3b0 ====

void FUN_0054e3b0(undefined2 param_1,undefined2 param_2)

{
  undefined2 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  return;
}


// ==== FUN_0054e3d0 @ 0x0054e3d0 ====

void FUN_0054e3d0(void)

{
  return;
}


// ==== FUN_0054e3e0 @ 0x0054e3e0 ====

undefined4 FUN_0054e3e0(short *param_1)

{
  short *in_ECX;
  
  if ((*in_ECX == *param_1) && (in_ECX[1] == param_1[1])) {
    return 1;
  }
  return 0;
}


// ==== FUN_0054e450 @ 0x0054e450 ====

float10 FUN_0054e450(ushort *param_1)

{
  int iVar1;
  int iVar2;
  ushort *in_ECX;
  
  iVar1 = (uint)*in_ECX - (uint)*param_1;
  if (iVar1 < 1) {
    iVar1 = -iVar1;
  }
  iVar2 = (uint)in_ECX[1] - (uint)param_1[1];
  if (iVar2 < 1) {
    iVar2 = -iVar2;
  }
  return SQRT((float10)iVar1 * (float10)iVar1 + (float10)iVar2 * (float10)iVar2);
}


// ==== FUN_0054e4a0 @ 0x0054e4a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_0054e4a0(ushort param_1,ushort param_2)

{
  ushort *puVar1;
  int iVar2;
  ushort uStack_4;
  ushort uStack_2;
  
  puVar1 = (ushort *)(**(code **)(*DAT_00b5a718 + 8))();
  if ((param_1 < *puVar1) && (param_2 < puVar1[1])) {
    _uStack_4 = CONCAT22(param_2,param_1);
    iVar2 = (**(code **)(*DAT_00b5a718 + 0x10))(&uStack_4);
    if (*(char *)(iVar2 + 4) == '\x01') {
      return (float10)DAT_0099d080;
    }
  }
  return (float10)_DAT_009bb408;
}


// ==== FUN_0054e500 @ 0x0054e500 ====

void FUN_0054e500(int param_1)

{
  ushort uVar1;
  ushort *puVar2;
  int iVar3;
  ushort uVar4;
  ushort *in_ECX;
  int iVar5;
  ushort local_c;
  ushort local_a;
  ushort local_8;
  ushort uStack_6;
  
  local_c = 0;
  local_a = 0;
  local_8 = 0;
  uStack_6 = 0;
  if (param_1 == 0) {
    local_c = *in_ECX;
    local_a = in_ECX[1];
  }
  iVar5 = 0;
  do {
    uVar4 = 0;
    switch(iVar5) {
    case 0:
      if (*in_ECX < 2) {
        uStack_6 = in_ECX[1];
        local_8 = 0;
      }
      else {
        local_8 = *in_ECX - 1;
        uStack_6 = in_ECX[1];
      }
      break;
    case 1:
      if (*in_ECX < 0x1fe) {
        uStack_6 = in_ECX[1];
        local_8 = *in_ECX + 1;
      }
      else {
        uVar4 = in_ECX[1];
        local_8 = 0x1ff;
LAB_0054e5a8:
        uStack_6 = uVar4;
      }
      break;
    case 2:
      local_8 = *in_ECX;
      if (in_ECX[1] < 2) goto LAB_0054e5a8;
      uStack_6 = in_ECX[1] - 1;
      break;
    case 3:
      local_8 = *in_ECX;
      if (in_ECX[1] < 0x1fe) {
        uStack_6 = in_ECX[1] + 1;
      }
      else {
        uStack_6 = 0x1ff;
      }
    }
    uVar1 = uStack_6;
    uVar4 = local_8;
    puVar2 = (ushort *)(**(code **)(*DAT_00b5a718 + 8))();
    if ((uVar4 < *puVar2) && (uVar1 < puVar2[1])) {
      param_1 = CONCAT22(uVar1,uVar4);
      iVar3 = (**(code **)(*DAT_00b5a718 + 0x10))(&param_1);
      if ((*(char *)(iVar3 + 4) == '\x01') && ((local_8 != local_c || (uStack_6 != local_a)))) {
        FUN_0054e7a0(&local_8);
      }
    }
    iVar5 = iVar5 + 1;
    if (3 < iVar5) {
      return;
    }
  } while( true );
}


// ==== FUN_0054e680 @ 0x0054e680 ====

void FUN_0054e680(void)

{
  return;
}


// ==== FUN_0054e690 @ 0x0054e690 ====

void FUN_0054e690(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb414;
  return;
}


// ==== FUN_0054e6a0 @ 0x0054e6a0 ====

void FUN_0054e6a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb46c;
  return;
}


// ==== FUN_0054e6b0 @ 0x0054e6b0 ====

void FUN_0054e6b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb484;
  return;
}


// ==== FUN_0054e6c0 @ 0x0054e6c0 ====

void FUN_0054e6c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb49c;
  return;
}


// ==== FUN_0054e6d0 @ 0x0054e6d0 ====

void FUN_0054e6d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb4f4;
  return;
}


// ==== FUN_0054e6e0 @ 0x0054e6e0 ====

void FUN_0054e6e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb414;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054e700 @ 0x0054e700 ====

void FUN_0054e700(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb46c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054e720 @ 0x0054e720 ====

void FUN_0054e720(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb484;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054e740 @ 0x0054e740 ====

void FUN_0054e740(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb49c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054e760 @ 0x0054e760 ====

void FUN_0054e760(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb4f4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054e780 @ 0x0054e780 ====

void FUN_0054e780(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb50c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054e7a0 @ 0x0054e7a0 ====

undefined4 FUN_0054e7a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 extraout_EAX;
  int in_ECX;
  undefined4 *_Memory;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981ddb;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  puVar1 = operator_new(0x18);
  local_4 = 0;
  if (puVar1 == (undefined4 *)0x0) {
    _Memory = (undefined4 *)0x0;
  }
  else {
    FUN_0054e3a0();
    _Memory = puVar1;
  }
  *_Memory = *param_1;
  _Memory[2] = 0;
  _Memory[1] = 0;
  _Memory[3] = 0;
  _Memory[4] = 0;
  _Memory[5] = 0;
  local_4 = 0xffffffff;
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x28))(_Memory);
  if (iVar2 == 0) {
    ExceptionList = puVar1;
    return 1;
  }
  FUN_0054e3d0();
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_0054e850 @ 0x0054e850 ====

undefined4 FUN_0054e850(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x404);
}


// ==== FUN_0054e870 @ 0x0054e870 ====

undefined4 FUN_0054e870(int param_1)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x14) + 4 + param_1 * 4);
}


// ==== FUN_0054e880 @ 0x0054e880 ====

void FUN_0054e880(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  int *piVar3;
  int in_ECX;
  
  for (puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 8))();
      puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x40))(puVar2)) {
    pvVar1 = (void *)*puVar2;
    if (pvVar1 != (void *)0x0) {
      FUN_0054e680();
      _free(pvVar1);
      return;
    }
  }
  puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  if (puVar2 != (undefined4 *)0x0) {
    do {
      pvVar1 = (void *)*puVar2;
      if (pvVar1 != (void *)0x0) {
        FUN_0054e680();
        _free(pvVar1);
        return;
      }
      puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x3c))(puVar2);
    } while (puVar2 != (undefined4 *)0x0);
  }
  for (piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x10) + 8))(); piVar3 != (int *)0x0;
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x40))(piVar3)) {
    pvVar1 = *(void **)(*piVar3 + 4);
    if (pvVar1 != (void *)0x0) {
      FUN_0054e680();
      _free(pvVar1);
      return;
    }
  }
  piVar3 = (int *)(*(int *)(in_ECX + 0x14) + 0x404);
  *piVar3 = *piVar3 - *(int *)(*(int *)(in_ECX + 0x14) + 0x404);
  pvVar1 = *(void **)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    return;
  }
  FUN_0054e680();
  _free(pvVar1);
  return;
}


// ==== FUN_0054e970 @ 0x0054e970 ====

void FUN_0054e970(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb51c;
  DAT_00b5af78 = 0;
  for (puVar2 = (undefined4 *)(**(code **)(*(int *)in_ECX[1] + 8))(); puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)(**(code **)(*(int *)in_ECX[1] + 0x40))(puVar2)) {
    pvVar1 = (void *)*puVar2;
    if (pvVar1 != (void *)0x0) {
      FUN_0054e680();
      _free(pvVar1);
      return;
    }
  }
  for (puVar2 = (undefined4 *)(**(code **)(*(int *)in_ECX[2] + 8))(); puVar2 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)(**(code **)(*(int *)in_ECX[2] + 0x40))(puVar2)) {
    pvVar1 = (void *)*puVar2;
    if (pvVar1 != (void *)0x0) {
      FUN_0054e680();
      _free(pvVar1);
      return;
    }
  }
  piVar3 = (int *)(**(code **)(*(int *)in_ECX[4] + 8))();
  while( true ) {
    if (piVar3 == (int *)0x0) {
      (**(code **)(*(int *)in_ECX[4] + 0x20))();
      piVar3 = (int *)(in_ECX[5] + 0x404);
      *piVar3 = *piVar3 - *(int *)(in_ECX[5] + 0x404);
      if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[5])(1);
      }
      in_ECX[5] = 0;
      if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[4])(1);
      }
      in_ECX[4] = 0;
      if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[1])(1);
      }
      in_ECX[1] = 0;
      if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[2])(1);
      }
      in_ECX[2] = 0;
      if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)in_ECX[3])(1);
      }
      in_ECX[3] = 0;
      return;
    }
    pvVar1 = *(void **)(*piVar3 + 4);
    if (pvVar1 != (void *)0x0) break;
    piVar3 = (int *)(**(code **)(*(int *)in_ECX[4] + 0x48))(piVar3);
  }
  FUN_0054e680();
  _free(pvVar1);
  return;
}


// ==== FUN_0054ea90 @ 0x0054ea90 ====

void FUN_0054ea90(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x2c) = 1;
  FUN_0054e880();
  return;
}


// ==== FUN_0054eaa0 @ 0x0054eaa0 ====

void FUN_0054eaa0(void *param_1,void *param_2,void *param_3)

{
  int *piVar1;
  void *pvVar2;
  int in_ECX;
  void *pvVar3;
  void *pvVar4;
  
  *(undefined4 *)((int)param_2 + 4) = *(undefined4 *)((int)param_3 + 4);
  if (param_3 != param_1) {
    pvVar2 = *(void **)((int)param_3 + 4);
    pvVar4 = param_2;
    do {
      pvVar3 = pvVar2;
      *(void **)((int)pvVar3 + 8) = pvVar4;
      pvVar2 = *(void **)((int)pvVar3 + 4);
      pvVar4 = pvVar3;
    } while (pvVar3 != param_1);
  }
  while( true ) {
    if (param_1 == param_2) {
      piVar1 = (int *)(*(int *)(in_ECX + 0x14) + 0x404);
      *piVar1 = *piVar1 + 1;
      *(void **)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x28) * 4) = param_2;
      *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + 1;
      *(undefined4 *)(in_ECX + 0x24) = 2;
      FUN_0054e680();
      _free(param_3);
      return;
    }
    if (0xff < *(uint *)(in_ECX + 0x28)) break;
    piVar1 = (int *)(*(int *)(in_ECX + 0x14) + 0x404);
    *piVar1 = *piVar1 + 1;
    *(void **)(*(int *)(in_ECX + 0x14) + 4 + *(int *)(in_ECX + 0x28) * 4) = param_1;
    *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + 1;
    param_1 = *(void **)((int)param_1 + 8);
  }
  FUN_0054e880();
  *(undefined4 *)(in_ECX + 0x24) = 3;
  return;
}


// ==== FUN_0054eb50 @ 0x0054eb50 ====

void FUN_0054eb50(undefined2 *param_1,undefined2 *param_2)

{
  int iVar1;
  undefined2 *puVar2;
  int in_ECX;
  float10 fVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981dfb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  puVar2 = operator_new(0x18);
  local_4 = 0;
  if (puVar2 == (undefined2 *)0x0) {
    puVar2 = (undefined2 *)0x0;
  }
  else {
    FUN_0054e3a0();
  }
  *(undefined2 **)(in_ECX + 0x1c) = puVar2;
  *puVar2 = *param_1;
  local_4 = 0xffffffff;
  *(undefined2 *)(*(int *)(in_ECX + 0x1c) + 2) = param_1[1];
  puVar2 = operator_new(0x18);
  local_4 = 1;
  if (puVar2 == (undefined2 *)0x0) {
    puVar2 = (undefined2 *)0x0;
  }
  else {
    FUN_0054e3a0();
  }
  *(undefined2 **)(in_ECX + 0x18) = puVar2;
  *puVar2 = *param_2;
  *(undefined2 *)(*(int *)(in_ECX + 0x18) + 2) = param_2[1];
  *(undefined4 *)(in_ECX + 0x24) = 1;
  *(undefined4 *)(*(int *)(in_ECX + 0x1c) + 0xc) = 0;
  local_4 = 0xffffffff;
  fVar3 = (float10)FUN_0054e450(*(undefined4 *)(in_ECX + 0x18));
  *(float *)(*(int *)(in_ECX + 0x1c) + 0x10) = (float)fVar3;
  iVar1 = *(int *)(in_ECX + 0x1c);
  *(float *)(iVar1 + 0x14) = *(float *)(iVar1 + 0x10) + *(float *)(iVar1 + 0xc);
  *(undefined4 *)(*(int *)(in_ECX + 0x1c) + 4) = 0;
  *(undefined4 *)(*(int *)(in_ECX + 0x1c) + 8) = 0;
  FUN_0054eec0(*(undefined4 *)(in_ECX + 0x1c));
  ExceptionList = local_c;
  return;
}


// ==== FUN_0054ec60 @ 0x0054ec60 ====

int FUN_0054ec60(void)

{
  undefined4 uVar1;
  void *_Memory;
  char cVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int extraout_EAX;
  int in_ECX;
  
  iVar3 = *(int *)(in_ECX + 0x24);
  if ((iVar3 != 2) && (iVar3 != 3)) {
    iVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    if ((iVar3 == 0) || (*(char *)(in_ECX + 0x2c) != '\0')) {
      *(undefined4 *)(in_ECX + 0x24) = 3;
      return 3;
    }
    *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 1;
    puVar4 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
    uVar1 = *puVar4;
    (**(code **)(**(int **)(in_ECX + 8) + 0x3c))(puVar4);
    cVar2 = FUN_0054e3e0(*(undefined4 *)(in_ECX + 0x18));
    if (cVar2 == '\0') {
      puVar4 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 8))();
      while( true ) {
        if (puVar4 == (undefined4 *)0x0) {
          FUN_0054eec0(uVar1);
          return *(int *)(in_ECX + 0x24);
        }
        _Memory = (void *)*puVar4;
        if (_Memory != (void *)0x0) break;
        puVar4 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x3c))(puVar4);
      }
      FUN_0054e680();
      _free(_Memory);
      return extraout_EAX;
    }
    piVar5 = (int *)FUN_0054eaa0(*(undefined4 *)(in_ECX + 0x1c),*(undefined4 *)(in_ECX + 0x18),uVar1
                                );
    iVar3 = *piVar5;
  }
  return iVar3;
}


// ==== FUN_0054ed20 @ 0x0054ed20 ====

void FUN_0054ed20(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981e31;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb51c;
  pvVar1 = operator_new(0x242c);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0054fc20();
  }
  local_4 = 0xffffffff;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x242c);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0054fc20();
  }
  local_4 = 0xffffffff;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x1418);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0054f140();
  }
  local_4 = 0xffffffff;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0x242c);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0054f6e0(in_ECX[3]);
  }
  local_4 = 0xffffffff;
  in_ECX[4] = uVar2;
  puVar3 = operator_new(0x408);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *puVar3 = &PTR_FUN_009bb50c;
    puVar3[0x101] = 0;
  }
  in_ECX[5] = puVar3;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  in_ECX[8] = 0;
  in_ECX[10] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5af78 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5af78 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0054ee70 @ 0x0054ee70 ====

void FUN_0054ee70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb514;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_0054e680);
  return;
}


// ==== FUN_0054ee90 @ 0x0054ee90 ====

void FUN_0054ee90(byte param_1)

{
  void *in_ECX;
  
  FUN_0054ee70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054eeb0 @ 0x0054eeb0 ====

void FUN_0054eeb0(void)

{
  FUN_0054e3a0();
  return;
}


// ==== FUN_0054eec0 @ 0x0054eec0 ====

undefined4 FUN_0054eec0(undefined4 *param_1)

{
  short *_Memory;
  void *_Memory_00;
  float fVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int *piVar4;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  int iVar5;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  int in_ECX;
  undefined4 *unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 *_Memory_01;
  float10 fVar6;
  undefined4 *unaff_retaddr;
  void *apvStack_18 [3];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00981e53;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0054e500(param_1[1]);
  puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 8))();
  while( true ) {
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 0xc) + 0xc))(1,0);
      *puVar2 = *param_1;
      puVar2[1] = param_1;
      iVar5 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x28))(puVar2);
      if (iVar5 == 0) {
        ExceptionList = apvStack_18[0];
        return *(undefined4 *)(in_ECX + 0x24);
      }
      (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,puVar2);
      FUN_0054e3d0();
      _free(param_1);
      return extraout_EAX_04;
    }
    _Memory_01 = (undefined4 *)*puVar2;
    FUN_0054e4a0(*(undefined2 *)_Memory_01,*(undefined2 *)((int)_Memory_01 + 2));
    puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(_Memory_01);
    if (puVar3 != (undefined4 *)0x0) {
      do {
        _Memory = (short *)*puVar3;
        if ((*_Memory == *(short *)*unaff_EBP) && (_Memory[1] == ((short *)*unaff_EBP)[1])) {
          if ((float)puVar2 < *(float *)(_Memory + 6)) {
            FUN_0054e3d0();
            _free(_Memory);
            return extraout_EAX_00;
          }
          if (_Memory_01 != (undefined4 *)0x0) {
            FUN_0054e3d0();
            _free(_Memory_01);
            return extraout_EAX;
          }
          _Memory_01 = (undefined4 *)0x0;
          unaff_EBP = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x3c))(unaff_EBP);
        }
        else {
          puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(puVar3);
        }
      } while (puVar3 != (undefined4 *)0x0);
      param_1 = unaff_retaddr;
    }
    FUN_0054e3a0();
    apvStack_18[0] = (void *)*_Memory_01;
    puStack_8 = (undefined1 *)0x0;
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 0x10) + 0x30))(apvStack_18);
    pvStack_c = (void *)0xffffffff;
    FUN_0054e3d0();
    if (piVar4 != (int *)0x0) {
      _Memory_00 = *(void **)(*piVar4 + 4);
      if (*(float *)((int)_Memory_00 + 0xc) <= (float)unaff_EBP) {
        FUN_0054e3d0();
        _free(_Memory_01);
        return extraout_EAX_01;
      }
      FUN_0054e3d0();
      _free(_Memory_00);
      return extraout_EAX_02;
    }
    puVar2 = operator_new(0x18);
    pvStack_c = (void *)0x1;
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      FUN_0054e3a0();
    }
    puVar2[2] = 0;
    puVar2[1] = param_1;
    puVar2[3] = unaff_EBP;
    pvStack_c = (void *)0xffffffff;
    fVar6 = (float10)FUN_0054e450(*(undefined4 *)(in_ECX + 0x18));
    puVar2[4] = (float)fVar6;
    fVar1 = DAT_009b2d78;
    puVar2[5] = (float)fVar6 + (float)puVar2[3];
    *puVar2 = *_Memory_01;
    if ((fVar1 < (float)fVar6 + (float)puVar2[3]) ||
       (iVar5 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2), iVar5 != 0)) break;
    puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x40))(unaff_ESI);
  }
  FUN_0054e3d0();
  _free(puVar2);
  return extraout_EAX_03;
}


// ==== FUN_0054f140 @ 0x0054f140 ====

void FUN_0054f140(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981e68;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb524;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009bb514;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x100,FUN_0054eeb0,FUN_0054e680);
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


// ==== FUN_0054f1f0 @ 0x0054f1f0 ====

void FUN_0054f1f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0054f210();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054f210 @ 0x0054f210 ====

void FUN_0054f210(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981e93;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb524;
  _Memory = (void *)in_ECX[0x504];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009bb514;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_0054e680);
    *in_ECX = &PTR_FUN_009bb484;
    ExceptionList = local_c;
    return;
  }
  FUN_0054e3d0();
  _free(_Memory);
  return;
}


// ==== FUN_0054f2b0 @ 0x0054f2b0 ====

void * FUN_0054f2b0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00981eb9;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x1414);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x140c) = *(int *)(in_ECX + 0x140c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x14);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0054e3a0();
      }
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
                           s_d__usa_24_0_1_2__develop_share_n_009bb330,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0054f3c0 @ 0x0054f3c0 ====

undefined4 FUN_0054f3c0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_n_009bb330,0xa9);
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


// ==== FUN_0054f440 @ 0x0054f440 ====

void FUN_0054f440(byte param_1)

{
  void *in_ECX;
  
  FUN_0054e970();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054f460 @ 0x0054f460 ====

void FUN_0054f460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb544;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x24,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0054f480 @ 0x0054f480 ====

void FUN_0054f480(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981ed8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb54c;
  local_4 = 0;
  if ((void *)in_ECX[0x904] == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009bb544;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x24,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009bb46c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x904]);
  return;
}


// ==== FUN_0054f500 @ 0x0054f500 ====

void FUN_0054f500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009bb53c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x24,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0054f520 @ 0x0054f520 ====

void FUN_0054f520(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981ef8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb564;
  local_4 = 0;
  if ((void *)in_ECX[0x904] == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009bb53c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x24,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009bb4f4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x904]);
  return;
}


// ==== FUN_0054f5a0 @ 0x0054f5a0 ====

undefined4 FUN_0054f5a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x240c);
}


// ==== FUN_0054f5b0 @ 0x0054f5b0 ====

void FUN_0054f5b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0054f460();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054f5d0 @ 0x0054f5d0 ====

void FUN_0054f5d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0054f480();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054f5f0 @ 0x0054f5f0 ====

void FUN_0054f5f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0054f500();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054f610 @ 0x0054f610 ====

void FUN_0054f610(byte param_1)

{
  void *in_ECX;
  
  FUN_0054f520();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054f630 @ 0x0054f630 ====

void FUN_0054f630(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981ef8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb564;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009bb53c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x24,0x100,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x902] = 0;
  in_ECX[0x902] = in_ECX[0x902] + 0x100;
  in_ECX[0x905] = in_ECX + 2;
  in_ECX[0x903] = 0;
  in_ECX[0x904] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[8] = puVar1 + 0xb;
    puVar1[9] = 0;
    puVar1[10] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 9;
  } while (iVar2 != 0);
  in_ECX[0x8ff] = 0;
  in_ECX[0x900] = 0;
  in_ECX[0x901] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0054f6e0 @ 0x0054f6e0 ====

void FUN_0054f6e0(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981f23;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009bb57c;
  FUN_0054f630();
  in_ECX[3] = param_1;
  local_4 = CONCAT31(local_4._1_3_,1);
  puVar1 = (undefined4 *)(**(code **)(in_ECX[5] + 0xc))(1,0);
  in_ECX[1] = puVar1;
  *puVar1 = 0;
  *(undefined4 *)(in_ECX[1] + 8) = in_ECX[1];
  *(undefined4 *)(in_ECX[1] + 0xc) = in_ECX[1];
  *(undefined4 *)(in_ECX[1] + 0x10) = in_ECX[1];
  *(undefined1 *)(in_ECX[1] + 0x14) = 1;
  in_ECX[2] = in_ECX[1];
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_0054f770 @ 0x0054f770 ====

void FUN_0054f770(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    FUN_0054f790(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_0054f790 @ 0x0054f790 ====

void FUN_0054f790(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != *(int *)(in_ECX + 4)) {
    FUN_0054f790(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != *(int *)(in_ECX + 4)) {
    FUN_0054f790(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0054f7d0 @ 0x0054f7d0 ====

void FUN_0054f7d0(undefined4 *param_1)

{
  int *in_ECX;
  
  FUN_0054f7f0(*param_1);
  (**(code **)(*in_ECX + 0x3c))(param_1);
  return;
}


// ==== FUN_0054f7f0 @ 0x0054f7f0 ====

void FUN_0054f7f0(void *param_1)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,param_1);
    return;
  }
  if (param_1 == (void *)0x0) {
    return;
  }
  FUN_0054e680();
  _free(param_1);
  return;
}


// ==== FUN_0054f830 @ 0x0054f830 ====

void FUN_0054f830(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    FUN_0054f850(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_0054f850 @ 0x0054f850 ====

void FUN_0054f850(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != *(int *)(in_ECX + 4)) {
    FUN_0054f850(param_1[2]);
  }
  if (param_1[3] != *(int *)(in_ECX + 4)) {
    FUN_0054f850(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
    return;
  }
  FUN_0054e680();
  _free(_Memory);
  return;
}


// ==== FUN_0054f8c0 @ 0x0054f8c0 ====

undefined4 * FUN_0054f8c0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  int in_ECX;
  int *unaff_ESI;
  
  iVar1 = in_ECX + 0x14;
  piVar3 = (int *)(**(code **)(*(int *)(in_ECX + 0x14) + 0xc))(1,0);
  *piVar3 = iVar1;
  piVar3[2] = *(int *)(in_ECX + 4);
  piVar3[3] = *(int *)(in_ECX + 4);
  piVar3[4] = *(int *)(in_ECX + 4);
  *(undefined1 *)(piVar3 + 5) = 0;
  puVar2 = *(undefined4 **)(in_ECX + 8);
  if (puVar2 == *(undefined4 **)(in_ECX + 4)) {
    *(int **)(in_ECX + 8) = piVar3;
    FUN_0044b660(piVar3);
    return (undefined4 *)0x0;
  }
  iVar4 = FUN_005eebf0(iVar1,*puVar2);
  do {
    if (iVar4 == 0) {
      (**(code **)(*unaff_ESI + 0x10))(1,piVar3);
      return puVar2;
    }
    if (iVar4 < 1) {
      puVar5 = (undefined4 *)puVar2[2];
      if (puVar5 == *(undefined4 **)(in_ECX + 4)) {
        piVar3[4] = (int)puVar2;
        puVar2[2] = piVar3;
        FUN_0044b660(piVar3);
        return (undefined4 *)0x0;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == *(undefined4 **)(in_ECX + 4)) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
        FUN_0044b660(piVar3);
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_005eebf0(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_0054f9a0 @ 0x0054f9a0 ====

short FUN_0054f9a0(ushort *param_1)

{
  ushort uVar1;
  byte bVar2;
  ushort *in_ECX;
  
  uVar1 = *in_ECX;
  bVar2 = (byte)(uVar1 >> 8);
  if ((uVar1 < *param_1) || ((uVar1 <= *param_1 && (in_ECX[1] < param_1[1])))) {
    return CONCAT11(bVar2,1);
  }
  return (ushort)bVar2 << 8;
}


// ==== FUN_0054f9d0 @ 0x0054f9d0 ====

int FUN_0054f9d0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = *(int *)(*(int *)(iVar1 + 0x10) + 0xc);
  if (*(char *)(iVar2 + 0x14) == '\0') {
    *(undefined1 *)(iVar2 + 0x14) = 1;
    iVar1 = *(int *)(*(int *)(param_1 + 0x10) + 0x10);
    *(undefined1 *)(*(int *)(param_1 + 0x10) + 0x14) = 1;
    *(undefined1 *)(iVar1 + 0x14) = 0;
    return iVar1;
  }
  if (param_1 == *(int *)(iVar1 + 0xc)) {
    FUN_00457010(iVar1);
    param_1 = iVar1;
  }
  iVar1 = *(int *)(param_1 + 0x10);
  *(undefined1 *)(iVar1 + 0x14) = 1;
  iVar1 = *(int *)(iVar1 + 0x10);
  *(undefined1 *)(iVar1 + 0x14) = 0;
  FUN_00457070(iVar1);
  return param_1;
}


// ==== FUN_0054fa30 @ 0x0054fa30 ====

undefined4 * FUN_0054fa30(undefined4 param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  puVar3 = *(undefined4 **)(in_ECX + 8);
  if (puVar3 == puVar1) {
    return puVar3;
  }
  do {
    cVar2 = FUN_0054f9a0(*puVar3);
    if (cVar2 == '\0') {
      cVar2 = FUN_0054f9a0(param_1);
      if (cVar2 == '\0') {
        return puVar3;
      }
      puVar3 = (undefined4 *)puVar3[3];
    }
    else {
      puVar3 = (undefined4 *)puVar3[2];
    }
  } while (puVar3 != puVar1);
  return puVar3;
}


// ==== FUN_0054fa80 @ 0x0054fa80 ====

uint FUN_0054fa80(undefined4 param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = FUN_0054fa30(param_1);
  return -(uint)(uVar1 != *(uint *)(in_ECX + 4)) & uVar1;
}


// ==== FUN_0054faa0 @ 0x0054faa0 ====

uint FUN_0054faa0(undefined4 param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar1 = FUN_0044e520(param_1);
  uVar2 = FUN_0054ff30(param_1);
  (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,uVar2);
  return -(uint)(uVar1 != *(uint *)(in_ECX + 4)) & uVar1;
}


// ==== FUN_0054fae0 @ 0x0054fae0 ====

void FUN_0054fae0(byte param_1)

{
  void *in_ECX;
  
  FUN_0054fb00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0054fb00 @ 0x0054fb00 ====

void FUN_0054fb00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00981f23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb57c;
  local_4 = 1;
  if (in_ECX[2] != in_ECX[1]) {
    FUN_0054f850(in_ECX[2]);
    in_ECX[2] = in_ECX[1];
  }
  FUN_0054e140();
  local_4 = local_4 & 0xffffff00;
  FUN_0054f520();
  *in_ECX = &PTR_FUN_009bb49c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0054fb70 @ 0x0054fb70 ====

void FUN_0054fb70(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981ed8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009bb54c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009bb544;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x24,0x100,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x902] = 0;
  in_ECX[0x902] = in_ECX[0x902] + 0x100;
  in_ECX[0x905] = in_ECX + 2;
  in_ECX[0x903] = 0;
  in_ECX[0x904] = 0;
  iVar2 = 0xff;
  puVar1 = in_ECX;
  do {
    puVar1[8] = puVar1 + 0xb;
    puVar1[9] = 0;
    puVar1[10] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 9;
  } while (iVar2 != 0);
  in_ECX[0x8ff] = 0;
  in_ECX[0x900] = 0;
  in_ECX[0x901] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0054fc20 @ 0x0054fc20 ====

void FUN_0054fc20(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00981f43;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009bb5d4;
  FUN_0054fb70();
  in_ECX[3] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  puVar1 = (undefined4 *)(**(code **)(in_ECX[5] + 0xc))(1,0);
  in_ECX[1] = puVar1;
  *puVar1 = 0;
  *(undefined4 *)(in_ECX[1] + 8) = in_ECX[1];
  *(undefined4 *)(in_ECX[1] + 0xc) = in_ECX[1];
  *(undefined4 *)(in_ECX[1] + 0x10) = in_ECX[1];
  *(undefined1 *)(in_ECX[1] + 0x14) = 1;
  in_ECX[2] = in_ECX[1];
  ExceptionList = unaff_ESI;
  return;
}


// ==== FUN_0054fcb0 @ 0x0054fcb0 ====

void FUN_0054fcb0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    FUN_0054fcd0(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_0054fcd0 @ 0x0054fcd0 ====

void FUN_0054fcd0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != *(int *)(in_ECX + 4)) {
    FUN_0054fcd0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != *(int *)(in_ECX + 4)) {
    FUN_0054fcd0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0054fd10 @ 0x0054fd10 ====

undefined4 * FUN_0054fd10(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar2 = *(undefined4 **)(in_ECX + 8);
  if (puVar2 == *(undefined4 **)(in_ECX + 4)) {
    return puVar2;
  }
  do {
    cVar1 = FUN_0054fd60(*puVar2);
    if (cVar1 == '\0') {
      cVar1 = FUN_0054fd60(param_1);
      if (cVar1 == '\0') {
        return puVar2;
      }
      puVar2 = (undefined4 *)puVar2[3];
    }
    else {
      puVar2 = (undefined4 *)puVar2[2];
    }
  } while (puVar2 != *(undefined4 **)(in_ECX + 4));
  return puVar2;
}


// ==== FUN_0054fd60 @ 0x0054fd60 ====

undefined4 FUN_0054fd60(ushort *param_1)

{
  ushort *in_ECX;
  
  if (*(float *)(in_ECX + 10) <= *(float *)(param_1 + 10) &&
      *(float *)(param_1 + 10) != *(float *)(in_ECX + 10)) {
    return 1;
  }
  if (*(float *)(param_1 + 10) <= *(float *)(in_ECX + 10) &&
      *(float *)(in_ECX + 10) != *(float *)(param_1 + 10)) {
    return 0;
  }
  if ((*in_ECX < *param_1) || ((*in_ECX <= *param_1 && (in_ECX[1] < param_1[1])))) {
    return 1;
  }
  return 0;
}


// ==== FUN_0054fdb0 @ 0x0054fdb0 ====

uint FUN_0054fdb0(undefined4 param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = FUN_0054fd10(param_1);
  return -(uint)(uVar1 != *(uint *)(in_ECX + 4)) & uVar1;
}


// ==== FUN_0054fdd0 @ 0x0054fdd0 ====

void FUN_0054fdd0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(in_ECX + 4)) {
    FUN_0054fdf0(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  }
  return;
}


// ==== FUN_0054fdf0 @ 0x0054fdf0 ====

void FUN_0054fdf0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != *(int *)(in_ECX + 4)) {
    FUN_0054fdf0(param_1[2]);
  }
  if (param_1[3] != *(int *)(in_ECX + 4)) {
    FUN_0054fdf0(param_1[3]);
  }
  _Memory = (void *)*param_1;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))(1,_Memory);
    (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
    return;
  }
  if (_Memory == (void *)0x0) {
    (**(code **)(*(int *)(in_ECX + 0x14) + 0x10))(1,param_1);
    return;
  }
  FUN_0054e680();
  _free(_Memory);
  return;
}


// ==== FUN_0054fe60 @ 0x0054fe60 ====

undefined4 * FUN_0054fe60(void)

{
  undefined4 *puVar1;
  char cVar2;
  int *piVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 *puVar5;
  int *unaff_EBP;
  
  piVar3 = (int *)(**(code **)(*(int *)(in_ECX + 0x14) + 0xc))(1,0);
  *piVar3 = in_ECX + 0x14;
  piVar3[2] = *(int *)(in_ECX + 4);
  piVar3[3] = *(int *)(in_ECX + 4);
  piVar3[4] = *(int *)(in_ECX + 4);
  *(undefined1 *)(piVar3 + 5) = 0;
  puVar1 = *(undefined4 **)(in_ECX + 4);
  puVar5 = *(undefined4 **)(in_ECX + 8);
  if (*(undefined4 **)(in_ECX + 8) == puVar1) {
    *(int **)(in_ECX + 8) = piVar3;
    FUN_0044b660(piVar3);
    return (undefined4 *)0x0;
  }
  do {
    cVar2 = FUN_0054fd60(*puVar5);
    if (cVar2 == '\0') {
      cVar2 = FUN_0054fd60(in_ECX + 0x14);
      if (cVar2 == '\0') {
        (**(code **)(*unaff_EBP + 0x10))(1,piVar3);
        return puVar5;
      }
      puVar4 = (undefined4 *)puVar5[3];
      if (puVar4 == puVar1) {
        piVar3[4] = (int)puVar5;
        puVar5[3] = piVar3;
        FUN_0044b660(piVar3);
        return (undefined4 *)0x0;
      }
    }
    else {
      puVar4 = (undefined4 *)puVar5[2];
      if (puVar4 == puVar1) {
        piVar3[4] = (int)puVar5;
        puVar5[2] = piVar3;
        FUN_0044b660(piVar3);
        return (undefined4 *)0x0;
      }
    }
    puVar5 = puVar4;
  } while( true );
}


// ==== FUN_0054ff30 @ 0x0054ff30 ====

undefined4 * FUN_0054ff30(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  
  iVar1 = *(int *)(in_ECX + 4);
  puVar2 = param_1;
  if ((param_1[2] != iVar1) && (param_1[3] != iVar1)) {
    puVar2 = (undefined4 *)FUN_0044e520(param_1);
  }
  iVar3 = puVar2[2];
  if (iVar3 == iVar1) {
    iVar3 = puVar2[3];
  }
  iVar1 = puVar2[4];
  *(int *)(iVar3 + 0x10) = iVar1;
  if (iVar1 == *(int *)(in_ECX + 4)) {
    *(int *)(in_ECX + 8) = iVar3;
  }
  else if (puVar2 == *(undefined4 **)(iVar1 + 8)) {
    *(int *)(iVar1 + 8) = iVar3;
  }
  else {
    *(int *)(iVar1 + 0xc) = iVar3;
  }
  if (*(char *)(puVar2 + 5) == '\x01') {
    FUN_0054ffa0(iVar3);
  }
  *param_1 = *puVar2;
  return puVar2;
}


// ==== FUN_0054ffa0 @ 0x0054ffa0 ====

void FUN_0054ffa0(int param_1)

{
  int in_ECX;
  
  if (param_1 == *(int *)(in_ECX + 8)) {
    *(undefined1 *)(param_1 + 0x14) = 1;
    return;
  }
  do {
    if (*(char *)(param_1 + 0x14) != '\x01') break;
    if (*(int *)(*(int *)(param_1 + 0x10) + 8) == param_1) {
      param_1 = FUN_0054e030(param_1);
    }
    else {
      param_1 = FUN_00457140(param_1);
    }
  } while (param_1 != *(int *)(in_ECX + 8));
  *(undefined1 *)(param_1 + 0x14) = 1;
  return;
}


// ==== FUN_0054fff0 @ 0x0054fff0 ====

void FUN_0054fff0(byte param_1)

{
  void *in_ECX;
  
  FUN_00550010();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


