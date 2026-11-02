// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x530000-0x53ffff

// ==== FUN_00530070 @ 0x00530070 ====

void FUN_00530070(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  int iStack_8;
  uint uStack_4;
  
  uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IBrick::RTTI_Type_Descriptor,0);
  iStack_8 = FUN_00803725(uVar2);
  if (iStack_8 != 0) {
    FUN_006eb6d0(iStack_8);
    return;
  }
  uStack_4 = 0xf;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pBrick_L____NULL_009b8c7c,0x10);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_005300f0 @ 0x005300f0 ====

undefined4 FUN_005300f0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_EAX;
  int *in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 8))();
  iVar3 = (**(code **)(*param_1 + 0x10))();
  if (iVar3 != iVar2) {
    return 0;
  }
  if (param_1[3] == 0) {
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s_BrickAnim_Over_009b8c90,0xe);
    FUN_00403e50(auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX;
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_0053fe90();
  }
  return 1;
}


// ==== FUN_00530190 @ 0x00530190 ====

undefined4 FUN_00530190(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*(int *)in_ECX[1] + 8))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar1 == iVar2) {
    (**(code **)(*in_ECX + 4))(param_1 + 2);
    FUN_00530070();
    return 1;
  }
  return 0;
}


// ==== FUN_005301d0 @ 0x005301d0 ====

void FUN_005301d0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00541080(param_1,*(undefined4 *)(in_ECX + 0x10));
  FUN_0053fb60();
  FUN_0053ff80(in_ECX);
  FUN_0052ff70();
  FUN_00530070();
  return;
}


// ==== FUN_00530210 @ 0x00530210 ====

void FUN_00530210(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_0052fff0();
  if ((char)(*(int **)(in_ECX + 4))[2] != '\0') {
    iVar1 = *DAT_00b5ad5c;
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
    (**(code **)(iVar1 + 8))(uVar2);
    FUN_00541620();
    FUN_0053fb80();
  }
  if (*(undefined4 **)(in_ECX + 0x14) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x14))(1);
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  if (*(undefined4 **)(in_ECX + 0xc) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0xc))(1);
  }
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (*(undefined4 **)(in_ECX + 8) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 8))(1);
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  if (*(undefined4 **)(in_ECX + 4) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 4))(1);
  }
  *(undefined4 *)(in_ECX + 4) = 0;
  if (*(undefined4 **)(in_ECX + 0x10) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x10))(1);
  }
  *(undefined4 *)(in_ECX + 0x10) = 0;
  return;
}


// ==== FUN_005302a0 @ 0x005302a0 ====

uint FUN_005302a0(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 < 0x30060036) {
    if (uVar1 == 0x30060035) {
      uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
      uVar1 = (**(code **)(*param_1 + 0x10))();
      if (uVar2 == uVar1) {
        uVar1 = FUN_00541590((float)param_1[2]);
        return uVar1;
      }
    }
    else if (uVar1 == 0x40001) {
      uVar1 = 0;
      if (*(char *)(*(int *)(in_ECX + 4) + 8) == '\x01') {
        uVar1 = FUN_005413b0(*(undefined1 *)(*(int *)(in_ECX + 8) + 0x14));
      }
    }
    else {
      if (uVar1 == 0x20010021) {
        uVar1 = FUN_0052fd50(param_1);
        return uVar1;
      }
      uVar1 = uVar1 + 0xdffeffde;
      if (uVar1 == 0) {
        uVar1 = FUN_005300f0(param_1);
        return uVar1;
      }
    }
  }
  else {
    if (uVar1 == 0x50040001) {
      uVar1 = FUN_0052ff30(param_1);
      return uVar1;
    }
    if (uVar1 == 0x50040006) {
      uVar1 = FUN_0052fe80(param_1);
      return uVar1;
    }
    uVar1 = uVar1 + 0xaff8fffe;
    if (uVar1 == 0) {
      uVar1 = FUN_00530190(param_1);
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00530370 @ 0x00530370 ====

void FUN_00530370(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8cdc;
  FUN_00530210();
  *in_ECX = &PTR_FUN_009b7814;
  return;
}


// ==== FUN_00530390 @ 0x00530390 ====

undefined4 FUN_00530390(void)

{
  return 0x60010030;
}


// ==== FUN_005303a0 @ 0x005303a0 ====

void FUN_005303a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8cdc;
  FUN_00530210();
  *in_ECX = &PTR_FUN_009b7814;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005303d0 @ 0x005303d0 ====

void FUN_005303d0(void)

{
  return;
}


// ==== FUN_005303e0 @ 0x005303e0 ====

void FUN_005303e0(void)

{
  return;
}


// ==== FUN_005303f0 @ 0x005303f0 ====

void FUN_005303f0(void)

{
  return;
}


// ==== FUN_00530400 @ 0x00530400 ====

void FUN_00530400(void)

{
  return;
}


// ==== FUN_00530410 @ 0x00530410 ====

void FUN_00530410(void)

{
  return;
}


// ==== FUN_00530430 @ 0x00530430 ====

void FUN_00530430(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_a [2];
  undefined4 auStack_8 [2];
  
  if (*(char *)(in_ECX + 8) == '\0') {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    uVar2 = (**(code **)(*piVar1 + 8))();
    piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
    if ((piVar1 != (int *)0x0) &&
       (auStack_8[0] = uVar2, iVar3 = (**(code **)(*piVar1 + 0x30))(auStack_8), iVar3 == 0)) {
      (**(code **)(*piVar1 + 0x54))(auStack_a + -6,*(undefined4 *)(in_ECX + 0xc));
      *(undefined1 *)(in_ECX + 8) = 1;
    }
  }
  return;
}


// ==== FUN_005304a0 @ 0x005304a0 ====

void FUN_005304a0(void)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  undefined4 auStack_8 [2];
  
  if ((*(char *)(in_ECX + 8) != '\0') &&
     (piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 4))(), piVar1 != (int *)0x0)) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    auStack_8[0] = (**(code **)(*piVar2 + 8))();
    piVar2 = (int *)(**(code **)(*piVar1 + 0x30))(auStack_8);
    if (piVar2 != (int *)0x0) {
      (**(code **)(*DAT_00b5a6f8 + 0x10))(1,*(undefined4 *)(*piVar2 + 4));
      (**(code **)(*piVar1 + 0x40))(piVar2);
      *(undefined1 *)(in_ECX + 8) = 0;
    }
  }
  return;
}


// ==== FUN_00530510 @ 0x00530510 ====

void FUN_00530510(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
  if (iVar2 == 0) {
    return;
  }
  cVar1 = FUN_00511d60();
  if (cVar1 == '\0') {
    FUN_005304a0();
    return;
  }
  FUN_00530430();
  return;
}


// ==== FUN_00530540 @ 0x00530540 ====

void FUN_00530540(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8d40;
  FUN_005304a0();
  *in_ECX = &PTR_FUN_009b7ed4;
  return;
}


// ==== FUN_00530560 @ 0x00530560 ====

void FUN_00530560(int *param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *in_ECX;
  float10 fVar5;
  undefined4 uVar6;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  *in_ECX = &PTR_FUN_009b8d40;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[1] = param_1;
  piVar2 = (int *)(**(code **)(*param_1 + 0x14))();
  (**(code **)(*piVar2 + 8))();
  puVar3 = (undefined4 *)(**(code **)(*param_1 + 0x28))();
  uStack_10 = *puVar3;
  uStack_c = puVar3[1];
  uVar6 = 1;
  uStack_8 = uStack_10;
  uStack_4 = uStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a6f8 + 0xc))(1,0);
  in_ECX[3] = piVar2;
  piVar2 = (int *)(**(code **)(*piVar2 + 0xc))();
  (**(code **)(*piVar2 + 0x40))(&uStack_10);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
  (**(code **)(*piVar2 + 0x4c))(0);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
  (**(code **)(*piVar2 + 0x28))(4);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
  iVar4 = *piVar2;
  fVar5 = (float10)(**(code **)(*param_1 + 0x34))();
  (**(code **)(iVar4 + 0x94))((float)fVar5);
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[3] + 0xc))();
  iVar4 = *piVar2;
  fVar5 = (float10)(**(code **)(*param_1 + 0x30))();
  (**(code **)(iVar4 + 0x90))((float)fVar5);
  (**(code **)(*(int *)in_ECX[3] + 0x24))(0);
  FUN_00530430();
  piVar2 = (int *)(**(code **)(*param_1 + 0x14))();
  iVar4 = (**(code **)(*piVar2 + 0x24))();
  if ((iVar4 != 0) && (*(int **)(iVar4 + 0x4c) != (int *)0x0)) {
    piVar2 = (int *)(**(code **)(**(int **)(iVar4 + 0x4c) + 0x18))();
    if (piVar2 != (int *)0x0) {
      iVar4 = (**(code **)(*piVar2 + 0xc))();
      if (iVar4 == 8) {
        (**(code **)(*piVar2 + 8))(0);
        puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x10))();
        uVar1 = *puVar3;
        puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
        *puVar3 = 7;
        puVar3[1] = uVar1;
        puVar3[2] = uVar6;
        (**(code **)(*DAT_00b5a804 + 0xc))(uVar6,puVar3);
        (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar3);
      }
    }
  }
  return;
}


// ==== FUN_005306e0 @ 0x005306e0 ====

void FUN_005306e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8d40;
  FUN_005304a0();
  *in_ECX = &PTR_FUN_009b7ed4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00530710 @ 0x00530710 ====

undefined4 FUN_00530710(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00530720 @ 0x00530720 ====

void FUN_00530720(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00530730 @ 0x00530730 ====

void FUN_00530730(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x1c) = param_1;
  return;
}


// ==== FUN_00530740 @ 0x00530740 ====

undefined4 FUN_00530740(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_00530750 @ 0x00530750 ====

undefined4 FUN_00530750(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}


// ==== FUN_00530770 @ 0x00530770 ====

undefined1 FUN_00530770(void)

{
  return 0;
}


// ==== FUN_00530780 @ 0x00530780 ====

undefined4 FUN_00530780(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x20);
}


// ==== FUN_00530790 @ 0x00530790 ====

undefined4 FUN_00530790(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x20);
}


// ==== FUN_005307a0 @ 0x005307a0 ====

void FUN_005307a0(void)

{
  return;
}


// ==== FUN_005307b0 @ 0x005307b0 ====

void FUN_005307b0(void)

{
  return;
}


// ==== FUN_005307c0 @ 0x005307c0 ====

void FUN_005307c0(void)

{
  return;
}


// ==== FUN_005307d0 @ 0x005307d0 ====

void FUN_005307d0(void)

{
  return;
}


// ==== FUN_005307e0 @ 0x005307e0 ====

void FUN_005307e0(void)

{
  return;
}


// ==== FUN_005307f0 @ 0x005307f0 ====

void FUN_005307f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8df4;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  *(undefined1 *)((int)in_ECX + 0x1d) = 0;
  *(undefined1 *)((int)in_ECX + 0x1e) = 0;
  in_ECX[8] = 0;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00530820 @ 0x00530820 ====

void FUN_00530820(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8df4;
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b7950;
  }
  puVar1[1] = in_ECX[2];
  FUN_00797a20(puVar1);
  if (in_ECX[5] != 0) {
    (**(code **)(*DAT_00b5ac88 + 0x10))(1,in_ECX[5]);
  }
  in_ECX[6] = 0;
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_00530890 @ 0x00530890 ====

float10 FUN_00530890(char param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  if (iVar1 == 0) {
    return (float10)DAT_009a09bc;
  }
  if (param_1 == '\0') {
    return (float10)*(float *)(iVar1 + 0x40);
  }
  return (float10)*(float *)(iVar1 + 0x44);
}


// ==== FUN_005308c0 @ 0x005308c0 ====

undefined4 FUN_005308c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x1c);
}


// ==== FUN_005308d0 @ 0x005308d0 ====

uint FUN_005308d0(void)

{
  void *_Memory;
  uint extraout_EAX;
  int in_ECX;
  
  _Memory = *(void **)(in_ECX + 0x10);
  if ((_Memory == (void *)0x0) || (*(char *)((int)_Memory + 8) == '\x01')) {
    return (uint)_Memory & 0xffffff00;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00530910 @ 0x00530910 ====

void FUN_00530910(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uStack_c;
  int iStack_8;
  
  iVar1 = (**(code **)(*in_ECX + 0x68))();
  if (*(char *)(iVar1 + 0x14) == '\x01') {
    if (*(char *)((int)in_ECX + 0x1d) == '\0') {
      puVar2 = operator_new(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_009b7964;
        puVar2[3] = 0;
        *(undefined1 *)(puVar2 + 2) = 1;
      }
      uVar3 = (**(code **)(*in_ECX + 8))();
      puVar2[1] = uStack_c;
      iStack_8 = CONCAT31(iStack_8._1_3_,1);
      puVar2[2] = iStack_8;
      puVar2[3] = uVar3;
      FUN_00797a20(puVar2);
      *(undefined1 *)((int)in_ECX + 0x1d) = 1;
      return;
    }
  }
  else if (*(char *)((int)in_ECX + 0x1d) == '\x01') {
    puVar2 = operator_new(0x10);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009b7964;
      puVar2[3] = 0;
      *(undefined1 *)(puVar2 + 2) = 1;
    }
    uVar3 = (**(code **)(*in_ECX + 8))();
    puVar2[1] = uStack_c;
    iStack_8 = (uint)iStack_8._1_3_ << 8;
    puVar2[2] = iStack_8;
    puVar2[3] = uVar3;
    FUN_00797a20(puVar2);
    *(undefined1 *)((int)in_ECX + 0x1d) = 0;
  }
  return;
}


// ==== FUN_005309e0 @ 0x005309e0 ====

undefined1 FUN_005309e0(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x18))();
  if (cVar1 == '\0') {
    return 0;
  }
  return *(undefined1 *)(in_ECX + 0x1c);
}


// ==== FUN_00530a00 @ 0x00530a00 ====

void FUN_00530a00(byte param_1,byte param_2,int param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_retaddr;
  int iVar7;
  int iVar8;
  uint uVar9;
  undefined4 uStack_4;
  
  if (in_ECX[8] != 0) {
    (**(code **)(*DAT_00b5ac6c + 0x18))(in_ECX[2]);
    (**(code **)(*in_ECX + 0x30))();
    iVar3 = **(int **)(in_ECX[5] + 0x50);
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar2 = (int *)(**(code **)(iVar3 + 0x14))(uVar1);
    iVar3 = (**(code **)(*piVar2 + 0x18))();
    iVar3 = (int)ROUND(*(float *)(iVar3 + 0xc));
    if (param_3 == 3) {
      uVar6 = 0;
    }
    else if (param_3 == 4) {
      uVar6 = 1;
    }
    else {
      uVar6 = (param_3 != 5) - 1 & 2;
    }
    uVar5 = (uint)param_2;
    iVar7 = in_ECX[8];
    uVar4 = (uint)param_1;
    iVar8 = iVar7 + 0x1c;
    uVar9 = uVar6;
    FUN_00511d20(iVar7,iVar8,uStack_4,uVar4,uVar6,uVar5,unaff_retaddr,iVar3);
    FUN_00511c30(iVar7,iVar8,uStack_4,uVar4,uVar9,uVar5,unaff_retaddr,iVar3);
    uVar1 = (**(code **)(*in_ECX + 0x34))(uVar6,0,in_ECX[2]);
    FUN_004dd240(7,uVar1);
  }
  return;
}


// ==== FUN_00530af0 @ 0x00530af0 ====

void FUN_00530af0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  if ((in_ECX[4] != 0) && (*(char *)(in_ECX[4] + 8) == '\0')) {
    iVar2 = (**(code **)(*in_ECX + 0x24))();
    if ((*(int **)(iVar2 + 0x4c) != (int *)0x0) &&
       (piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))(), piVar3 != (int *)0x0)) {
      (**(code **)(*piVar3 + 8))(param_1);
      iVar2 = (**(code **)(*piVar3 + 0x10))();
      if ((iVar2 != 0) &&
         ((((cVar1 = *(char *)(iVar2 + 0xb), cVar1 == '\a' || (cVar1 == '\b')) || (cVar1 == '\t'))
          || ((cVar1 == '\f' || (cVar1 == '\x0e')))))) {
        _free((void *)in_ECX[4]);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00530b90 @ 0x00530b90 ====

void FUN_00530b90(float param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  float unaff_retaddr;
  
  if (param_1 != DAT_0099cdc8) {
    iVar1 = (**(code **)(*in_ECX + 0x24))();
    piVar2 = (int *)FUN_00803725(iVar1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                 &Framework::Creature::ISentry::RTTI_Type_Descriptor,0);
    iVar5 = *(int *)piVar2[0x14];
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    piVar4 = (int *)(**(code **)(iVar5 + 0x14))(uVar3);
    iVar5 = (**(code **)(*piVar2 + 0x24))();
    piVar2 = (int *)0x0;
    if (*(int **)(iVar1 + 0x44) != (int *)0x0) {
      piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x44) + 0x18))();
    }
    iVar1 = (**(code **)(*piVar4 + 8))();
    iVar1 = (int)(unaff_retaddr * DAT_0099d0b4 + *(float *)(iVar1 + 0xc));
    if (*(int *)(iVar5 + 0x28) < iVar1) {
      iVar1 = *(int *)(iVar5 + 0x28);
    }
    (**(code **)(*piVar2 + 0x14))((float)iVar1);
  }
  return;
}


// ==== FUN_00530c40 @ 0x00530c40 ====

void FUN_00530c40(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 0x10));
  return;
}


// ==== FUN_00530cb0 @ 0x00530cb0 ====

int FUN_00530cb0(int param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int in_ECX;
  char *pcVar4;
  
  iVar2 = *(int *)(in_ECX + 0x18);
  pcVar4 = (char *)(iVar2 + 2);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  pcVar3 = pcVar4;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar4,(int)pcVar3 - (iVar2 + 3));
  return param_1;
}


// ==== FUN_00530cf0 @ 0x00530cf0 ====

undefined4 FUN_00530cf0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  int *in_ECX;
  undefined4 unaff_EBP;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  uint uStack_8;
  
  iVar2 = (**(code **)(*param_1 + 0x10))();
  iVar3 = (**(code **)(*in_ECX + 8))();
  if (iVar2 != iVar3) {
    return 0;
  }
  piVar1 = *(int **)(in_ECX[5] + 0x44);
  piVar4 = (int *)(**(code **)(*piVar1 + 0x18))();
  iVar2 = *piVar1;
  uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar2 + 0x1c))(uVar5);
  FUN_00401740(s_Update_Servant_HPMP____f__f_009b8da0,0x1b);
  uVar5 = FUN_00404230(auStack_20);
  FUN_00796d50(uVar5);
  if (uStack_8 < 0x10) {
    (**(code **)(*piVar4 + 0x14))();
    (**(code **)(*piVar4 + 0x20))(unaff_EBP);
    return 1;
  }
  _free(pvStack_1c);
  return extraout_EAX;
}


// ==== FUN_00530de0 @ 0x00530de0 ====

uint FUN_00530de0(int *param_1,undefined4 *param_2)

{
  char cVar1;
  uint uVar2;
  
  uVar2 = (**(code **)(*param_1 + 4))();
  if (uVar2 == 0x40001) {
    cVar1 = (**(code **)(*(int *)*param_2 + 0x2c))();
    if (cVar1 != '\0') {
      FUN_00530af0(param_1[3]);
    }
    uVar2 = FUN_00530910();
  }
  else if (uVar2 == 0x30060031) {
    uVar2 = FUN_00530cf0(param_1);
    return uVar2;
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_00530e40 @ 0x00530e40 ====

void FUN_00530e40(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  char *pcVar5;
  int *in_ECX;
  char *pcVar6;
  void *unaff_ESI;
  undefined1 auStack_66 [10];
  uint uStack_5c;
  void *apvStack_4c [5];
  uint uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  undefined4 auStack_20 [2];
  undefined1 uStack_18;
  uint uStack_10;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  in_ECX[5] = (int)param_1;
  iVar2 = (**(code **)(*param_1 + 0x24))();
  in_ECX[6] = iVar2;
  uStack_4 = 0xf;
  uStack_8 = 0;
  uStack_18 = 0;
  uStack_30 = 0;
  uStack_28 = 0xffffffff;
  pvStack_24 = (void *)0xffffff;
  auStack_20[0] = 0x38;
  uStack_2c = uStack_2c & 0xffffff00;
  FUN_00401740(s_No_Name_009b79ec,7);
  uStack_28 = (**(code **)(*in_ECX + 8))();
  uStack_30 = 0;
  uVar3 = (**(code **)(*in_ECX + 0x40))(apvStack_4c);
  FUN_00401660(uVar3,0,0xffffffff);
  if (0xf < uStack_38) {
    _free(apvStack_4c[0]);
    return;
  }
  pvStack_24 = (void *)0x3b;
  pvVar4 = operator_new(0x34);
  if (pvVar4 == (void *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_00522170();
  }
  *(undefined4 *)(iVar2 + 4) = uStack_34;
  *(undefined1 *)(iVar2 + 8) = (undefined1)uStack_30;
  *(uint *)(iVar2 + 0xc) = uStack_2c;
  *(undefined4 *)(iVar2 + 0x10) = uStack_28;
  *(void **)(iVar2 + 0x14) = pvStack_24;
  FUN_00401660(auStack_20,0,0xffffffff);
  FUN_00797a20(iVar2);
  pcVar6 = (char *)(in_ECX[6] + 0x4c);
  pcVar5 = pcVar6;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar6,(int)pcVar5 - (in_ECX[6] + 0x4d));
  iVar2 = (**(code **)(*DAT_00b5a6dc + 0x1c))(5,auStack_66 + -6);
  in_ECX[8] = iVar2;
  if (0xf < uStack_5c) {
    _free(unaff_ESI);
    return;
  }
  if (uStack_10 < 0x10) {
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_00530fc0 @ 0x00530fc0 ====

void FUN_00530fc0(int *param_1)

{
  short sVar1;
  int in_ECX;
  undefined1 *puVar2;
  undefined1 auStack_54 [4];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 uStack_42;
  undefined1 uStack_41;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 uStack_34;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 uStack_18;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    (**(code **)(*param_1 + 0xc))();
    if (*(char *)(in_ECX + 0x1e) == '\0') {
      uStack_50 = 0;
      uStack_4c = 0;
      uStack_48 = 0;
      uStack_20 = 0xf;
      uStack_24 = 0;
      uStack_34 = 0;
      uStack_4 = 0xf;
      uStack_8 = 0;
      uStack_18 = 0;
      uStack_41 = 0;
      uStack_44 = 0;
      uStack_43 = 0;
      uStack_42 = 0;
      uStack_3c = DAT_0099d080;
      uStack_40 = 0xffffffff;
      FUN_00401660(*(undefined4 *)(in_ECX + 0x20),0,0xffffffff);
      FUN_00401660(*(int *)(in_ECX + 0x20) + 0x1c,0,0xffffffff);
      FUN_004ff800(&uStack_44);
      puVar2 = auStack_54;
      FUN_00511d10(puVar2);
      FUN_00512cd0();
      FUN_00512a20(puVar2);
      sVar1 = *(short *)(*(int *)(in_ECX + 0x20) + 0x38);
      if (sVar1 != 0) {
        FUN_004dd240(0x19,6,1,sVar1,*(undefined4 *)(in_ECX + 8));
      }
      *(undefined1 *)(in_ECX + 0x1e) = 1;
      FUN_004107d0();
      FUN_004ff750();
    }
    (**(code **)(*param_1 + 0x10))();
  }
  return;
}


// ==== FUN_005310d0 @ 0x005310d0 ====

void FUN_005310d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00530820();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005310f0 @ 0x005310f0 ====

void FUN_005310f0(undefined2 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined2 *)(in_ECX + 0x40);
  return;
}


// ==== FUN_00531100 @ 0x00531100 ====

void FUN_00531100(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x40) = *param_1;
  return;
}


// ==== FUN_00531110 @ 0x00531110 ====

undefined1 FUN_00531110(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3c);
}


// ==== FUN_00531120 @ 0x00531120 ====

void FUN_00531120(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_00531130 @ 0x00531130 ====

void FUN_00531130(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3d) = param_1;
  return;
}


// ==== FUN_00531140 @ 0x00531140 ====

undefined1 FUN_00531140(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3d);
}


// ==== FUN_00531170 @ 0x00531170 ====

void FUN_00531170(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3f) = param_1;
  return;
}


// ==== FUN_00531180 @ 0x00531180 ====

undefined1 FUN_00531180(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3f);
}


// ==== FUN_00531190 @ 0x00531190 ====

void FUN_00531190(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x005311a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(**(int **)(in_ECX + 0x48) + 8) + 0xc))();
  return;
}


// ==== FUN_005311b0 @ 0x005311b0 ====

undefined4 FUN_005311b0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return 1;
  }
                    /* WARNING: Could not recover jumptable at 0x005311c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(**(int **)(in_ECX + 0x48) + 8) + 8))();
  return uVar1;
}


// ==== FUN_005311d0 @ 0x005311d0 ====

undefined4 FUN_005311d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return 0;
  }
  return *(undefined4 *)(**(int **)(in_ECX + 0x48) + 8);
}


// ==== FUN_005311f0 @ 0x005311f0 ====

void FUN_005311f0(void)

{
  uint in_ECX;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return;
  }
  local_4 = in_ECX & 0xffffff00;
  FUN_00528030(**(undefined4 **)(in_ECX + 0x48),*(undefined4 **)(in_ECX + 0x48),local_4);
  FUN_00510b80();
  return;
}


// ==== FUN_00531230 @ 0x00531230 ====

void FUN_00531230(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8e7c;
  *(undefined1 *)(in_ECX + 0xf) = 1;
  *(undefined1 *)((int)in_ECX + 0x3d) = 1;
  *(undefined1 *)((int)in_ECX + 0x3e) = 1;
  *(undefined1 *)((int)in_ECX + 0x3f) = 0;
  uVar2 = FUN_005170b0();
  uVar1 = DAT_0099d080;
  in_ECX[0x12] = uVar2;
  in_ECX[0x13] = 0;
  in_ECX[3] = 100;
  in_ECX[4] = 100;
  in_ECX[6] = 0;
  uVar2 = DAT_0099d0f8;
  in_ECX[9] = uVar1;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = uVar2;
  in_ECX[0xe] = 0;
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_00531340 @ 0x00531340 ====

uint FUN_00531340(void)

{
  int *_Memory;
  uint in_EAX;
  uint extraout_EAX;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x4c) == 0) {
    return in_EAX & 0xffffff00;
  }
  _Memory = (int *)**(int **)(in_ECX + 0x48);
  if (_Memory == *(int **)(in_ECX + 0x48)) {
    return CONCAT31((int3)((uint)_Memory >> 8),1);
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_00531380 @ 0x00531380 ====

void FUN_00531380(int param_1)

{
  int in_ECX;
  
  FUN_005280c0(*(undefined4 *)(in_ECX + 0x48),**(undefined4 **)(param_1 + 4),
               *(undefined4 **)(param_1 + 4),param_1);
  return;
}


// ==== FUN_005313b0 @ 0x005313b0 ====

void FUN_005313b0(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x48);
  iVar2 = FUN_00517140(iVar1,*(undefined4 *)(iVar1 + 4),&param_1);
  FUN_00517200(1);
  *(int *)(iVar1 + 4) = iVar2;
  **(int **)(iVar2 + 4) = iVar2;
  return;
}


// ==== FUN_005313f0 @ 0x005313f0 ====

void FUN_005313f0(byte param_1)

{
  undefined4 *in_ECX;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009b8e7c;
  if (in_ECX[0x13] != 0) {
    local_4 = (uint)in_ECX & 0xffffff00;
    FUN_00528030(*(undefined4 *)in_ECX[0x12],(undefined4 *)in_ECX[0x12],local_4);
    FUN_00510b80();
  }
  FUN_008984a0();
  *in_ECX = &PTR_FUN_009b8184;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00531450 @ 0x00531450 ====

void FUN_00531450(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8ec4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00531480 @ 0x00531480 ====

undefined4 FUN_00531480(void)

{
  return 2;
}


// ==== FUN_00531490 @ 0x00531490 ====

undefined1 FUN_00531490(void)

{
  return 1;
}


// ==== FUN_005314a0 @ 0x005314a0 ====

undefined4 FUN_005314a0(int param_1)

{
  if ((param_1 < 0) || (2 < param_1)) {
    return 0;
  }
  return 1;
}


// ==== FUN_005314c0 @ 0x005314c0 ====

void FUN_005314c0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                 undefined1 param_5,undefined4 param_6,undefined1 param_7,undefined1 param_8)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b8edc;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = *param_3;
  in_ECX[5] = param_3[1];
  in_ECX[6] = param_4;
  *(undefined1 *)(in_ECX + 8) = param_5;
  in_ECX[7] = param_6;
  *(undefined1 *)((int)in_ECX + 0x21) = param_7;
  *(undefined1 *)((int)in_ECX + 0x22) = param_8;
  return;
}


// ==== FUN_00531520 @ 0x00531520 ====

void FUN_00531520(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = **(int **)(in_ECX + 4);
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))
                    (CONCAT31((int3)((uint)*(int **)(in_ECX + 4) >> 8),
                              *(undefined1 *)(in_ECX + 0x21)),*(undefined1 *)(in_ECX + 0x22));
  (**(code **)(iVar1 + 0x60))
            (in_ECX + 8,in_ECX + 0x10,*(undefined4 *)(in_ECX + 0x18),*(undefined1 *)(in_ECX + 0x20),
             *(undefined4 *)(in_ECX + 0x1c),uVar2);
  return;
}


// ==== FUN_00531570 @ 0x00531570 ====

undefined4 FUN_00531570(void)

{
  return 7;
}


// ==== FUN_00531580 @ 0x00531580 ====

undefined1 FUN_00531580(void)

{
  return 0;
}


// ==== FUN_00531590 @ 0x00531590 ====

void FUN_00531590(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x68))(in_ECX + 8,in_ECX + 0x10);
  return;
}


// ==== FUN_005315b0 @ 0x005315b0 ====

undefined1 FUN_005315b0(void)

{
  return 0;
}


// ==== FUN_005315c0 @ 0x005315c0 ====

void FUN_005315c0(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b8ef4;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = *param_3;
  in_ECX[5] = param_3[1];
  return;
}


// ==== FUN_00531600 @ 0x00531600 ====

undefined4 FUN_00531600(void)

{
  return 8;
}


// ==== FUN_00531610 @ 0x00531610 ====

bool FUN_00531610(int param_1)

{
  return param_1 == 0;
}


// ==== FUN_00531620 @ 0x00531620 ====

void FUN_00531620(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = param_1;
  *in_ECX = &PTR_FUN_009b8f0c;
  in_ECX[3] = *param_2;
  in_ECX[4] = param_2[1];
  in_ECX[5] = param_2[2];
  in_ECX[6] = param_2[3];
  *(undefined1 *)(in_ECX + 7) = *(undefined1 *)(param_2 + 4);
  return;
}


// ==== FUN_00531660 @ 0x00531660 ====

bool FUN_00531660(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  return uVar1 <= *(uint *)(in_ECX + 4);
}


// ==== FUN_00531680 @ 0x00531680 ====

void FUN_00531680(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x19);
  iVar2 = *(int *)(in_ECX + 0xc);
  iVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(int *)(in_ECX + 4) = iVar3 + (iVar1 - iVar2);
  (**(code **)(**(int **)(in_ECX + 8) + 0x24))(in_ECX + 0xc);
  return;
}


// ==== FUN_005316c0 @ 0x005316c0 ====

undefined4 FUN_005316c0(void)

{
  return 4;
}


// ==== FUN_005316d0 @ 0x005316d0 ====

bool FUN_005316d0(int param_1)

{
  return param_1 == 0;
}


// ==== FUN_005316e0 @ 0x005316e0 ====

void FUN_005316e0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b8f24;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  in_ECX[5] = param_2[3];
  in_ECX[6] = param_2[4];
  *(undefined1 *)(in_ECX + 7) = *(undefined1 *)(param_2 + 5);
  return;
}


// ==== FUN_00531720 @ 0x00531720 ====

bool FUN_00531720(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  return uVar1 <= *(uint *)(in_ECX + 0x20);
}


// ==== FUN_00531740 @ 0x00531740 ====

void FUN_00531740(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x19);
  iVar2 = *(int *)(in_ECX + 8);
  iVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(int *)(in_ECX + 0x20) = iVar3 + (iVar1 - iVar2);
  (**(code **)(**(int **)(in_ECX + 4) + 0x18))(in_ECX + 8);
  return;
}


// ==== FUN_00531780 @ 0x00531780 ====

undefined4 FUN_00531780(void)

{
  return 6;
}


// ==== FUN_00531790 @ 0x00531790 ====

void FUN_00531790(void)

{
  return;
}


// ==== FUN_005317a0 @ 0x005317a0 ====

undefined1 FUN_005317a0(void)

{
  return 0;
}


// ==== FUN_005317b0 @ 0x005317b0 ====

void FUN_005317b0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b8f3c;
  in_ECX[1] = param_1;
  in_ECX[2] = param_2;
  return;
}


// ==== FUN_005317d0 @ 0x005317d0 ====

bool FUN_005317d0(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  return uVar1 < *(uint *)(in_ECX + 8);
}


// ==== FUN_00531800 @ 0x00531800 ====

undefined4 FUN_00531800(void)

{
  return 5;
}


// ==== FUN_00531810 @ 0x00531810 ====

undefined1 FUN_00531810(void)

{
  return 1;
}


// ==== FUN_00531820 @ 0x00531820 ====

void FUN_00531820(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x1c))(in_ECX + 8);
  return;
}


// ==== FUN_00531830 @ 0x00531830 ====

uint FUN_00531830(int param_1)

{
  uint in_EAX;
  int in_ECX;
  
  if (param_1 == 0) {
    return (uint)((char)((uint)*(undefined4 *)(in_ECX + 0x18) >> 0x18) != '\x01');
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00531880 @ 0x00531880 ====

void FUN_00531880(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b8f54;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  in_ECX[5] = param_2[3];
  in_ECX[6] = param_2[4];
  return;
}


// ==== FUN_005318d0 @ 0x005318d0 ====

undefined4 FUN_005318d0(void)

{
  return 0xc;
}


// ==== FUN_005318e0 @ 0x005318e0 ====

bool FUN_005318e0(int param_1)

{
  return param_1 == 0;
}


// ==== FUN_005318f0 @ 0x005318f0 ====

void FUN_005318f0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = param_1;
  *in_ECX = &PTR_FUN_009b8f6c;
  in_ECX[3] = *param_2;
  in_ECX[4] = param_2[1];
  in_ECX[5] = param_2[2];
  in_ECX[6] = param_2[3];
  *(undefined2 *)(in_ECX + 7) = *(undefined2 *)(param_2 + 4);
  *(undefined1 *)((int)in_ECX + 0x1e) = *(undefined1 *)((int)param_2 + 0x12);
  return;
}


// ==== FUN_00531930 @ 0x00531930 ====

bool FUN_00531930(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  return uVar1 <= *(uint *)(in_ECX + 4);
}


// ==== FUN_00531950 @ 0x00531950 ====

void FUN_00531950(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x1b);
  iVar2 = *(int *)(in_ECX + 0xc);
  iVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(int *)(in_ECX + 4) = iVar3 + (iVar1 - iVar2);
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))(in_ECX + 0xc);
  return;
}


// ==== FUN_00531990 @ 0x00531990 ====

undefined4 FUN_00531990(void)

{
  return 9;
}


// ==== FUN_005319a0 @ 0x005319a0 ====

undefined1 FUN_005319a0(void)

{
  return 1;
}


// ==== FUN_005319b0 @ 0x005319b0 ====

void FUN_005319b0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x28))(in_ECX + 8);
  return;
}


// ==== FUN_005319c0 @ 0x005319c0 ====

bool FUN_005319c0(int param_1)

{
  return param_1 == 0;
}


// ==== FUN_005319d0 @ 0x005319d0 ====

void FUN_005319d0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b8f84;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  in_ECX[5] = param_2[3];
  *(undefined1 *)(in_ECX + 6) = *(undefined1 *)(param_2 + 4);
  return;
}


// ==== FUN_00531a20 @ 0x00531a20 ====

undefined4 FUN_00531a20(void)

{
  return 10;
}


// ==== FUN_00531a30 @ 0x00531a30 ====

bool FUN_00531a30(int param_1)

{
  return param_1 == 0;
}


// ==== FUN_00531a40 @ 0x00531a40 ====

void FUN_00531a40(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b8f9c;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  in_ECX[5] = param_2[3];
  *(undefined2 *)(in_ECX + 6) = *(undefined2 *)(param_2 + 4);
  *(undefined1 *)((int)in_ECX + 0x1a) = *(undefined1 *)((int)param_2 + 0x12);
  return;
}


// ==== FUN_00531a80 @ 0x00531a80 ====

bool FUN_00531a80(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  return uVar1 <= *(uint *)(in_ECX + 0x1c);
}


// ==== FUN_00531aa0 @ 0x00531aa0 ====

void FUN_00531aa0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x17);
  iVar2 = *(int *)(in_ECX + 8);
  iVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(int *)(in_ECX + 0x1c) = iVar3 + (iVar1 - iVar2);
  (**(code **)(**(int **)(in_ECX + 4) + 0x2c))(in_ECX + 8);
  return;
}


// ==== FUN_00531ae0 @ 0x00531ae0 ====

undefined4 FUN_00531ae0(void)

{
  return 0xb;
}


// ==== FUN_00531af0 @ 0x00531af0 ====

bool FUN_00531af0(int param_1)

{
  return param_1 == 0;
}


// ==== FUN_00531b00 @ 0x00531b00 ====

void FUN_00531b00(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b8fb4;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  in_ECX[5] = param_2[3];
  *(undefined2 *)(in_ECX + 6) = *(undefined2 *)(param_2 + 4);
  *(undefined1 *)((int)in_ECX + 0x1a) = *(undefined1 *)((int)param_2 + 0x12);
  return;
}


// ==== FUN_00531b40 @ 0x00531b40 ====

bool FUN_00531b40(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  return uVar1 <= *(uint *)(in_ECX + 0x1c);
}


// ==== FUN_00531b60 @ 0x00531b60 ====

void FUN_00531b60(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x17);
  iVar2 = *(int *)(in_ECX + 8);
  iVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(int *)(in_ECX + 0x1c) = iVar3 + (iVar1 - iVar2);
  (**(code **)(**(int **)(in_ECX + 4) + 0x30))(in_ECX + 8);
  return;
}


// ==== FUN_00531ba0 @ 0x00531ba0 ====

undefined4 FUN_00531ba0(void)

{
  return 0xd;
}


// ==== FUN_00531bb0 @ 0x00531bb0 ====

undefined1 FUN_00531bb0(void)

{
  return 1;
}


// ==== FUN_00531be0 @ 0x00531be0 ====

uint FUN_00531be0(int param_1)

{
  uint in_EAX;
  uint uVar1;
  int in_ECX;
  
  uVar1 = in_EAX & 0xffffff00;
  if ((param_1 == 0) && (uVar1 = 1, *(int *)(in_ECX + 0x17) == 1)) {
                    /* WARNING: Could not recover jumptable at 0x00531c01. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x3c))();
    return uVar1;
  }
  return uVar1;
}


// ==== FUN_00531c10 @ 0x00531c10 ====

void FUN_00531c10(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b8fcc;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  in_ECX[5] = param_2[3];
  in_ECX[6] = param_2[4];
  return;
}


// ==== FUN_00531c50 @ 0x00531c50 ====

void FUN_00531c50(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x17) == 1) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x38))(in_ECX + 8);
    return;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x34))(in_ECX + 8);
  return;
}


// ==== FUN_00531c80 @ 0x00531c80 ====

undefined4 FUN_00531c80(void)

{
  return 0xe;
}


// ==== FUN_00531c90 @ 0x00531c90 ====

undefined1 FUN_00531c90(void)

{
  return 1;
}


// ==== FUN_00531ca0 @ 0x00531ca0 ====

void FUN_00531ca0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x40))(in_ECX + 8);
  return;
}


// ==== FUN_00531cb0 @ 0x00531cb0 ====

bool FUN_00531cb0(int param_1)

{
  return param_1 == 0;
}


// ==== FUN_00531cc0 @ 0x00531cc0 ====

void FUN_00531cc0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b8fe4;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  *(undefined1 *)(in_ECX + 5) = *(undefined1 *)(param_2 + 3);
  return;
}


// ==== FUN_00531d10 @ 0x00531d10 ====

undefined4 FUN_00531d10(void)

{
  return 0xf;
}


// ==== FUN_00531d20 @ 0x00531d20 ====

undefined1 FUN_00531d20(void)

{
  return 1;
}


// ==== FUN_00531d30 @ 0x00531d30 ====

uint FUN_00531d30(int param_1)

{
  uint in_ECX;
  
  if (param_1 == 0) {
    in_ECX = (**(code **)(**(int **)(in_ECX + 4) + 0x44))
                       (in_ECX + 8,*(char *)(in_ECX + 0x14) + '\x01');
  }
  return in_ECX & 0xffffff00;
}


// ==== FUN_00531d60 @ 0x00531d60 ====

void FUN_00531d60(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b8ffc;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  *(undefined1 *)(in_ECX + 5) = *(undefined1 *)(param_2 + 3);
  return;
}


// ==== FUN_00531da0 @ 0x00531da0 ====

void FUN_00531da0(void)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  undefined4 unaff_EBP;
  
  cVar2 = *(char *)(in_ECX + 0x14);
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar1 = (int *)(in_ECX + 8);
  iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x6c))(piVar1,cVar2);
  if (uVar3 < (uint)(*piVar1 + iVar4)) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x44))(piVar1,unaff_EBP);
    return;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x44))(piVar1,cVar2 + '\x01');
  return;
}


// ==== FUN_00531e10 @ 0x00531e10 ====

undefined4 FUN_00531e10(void)

{
  return 0x10;
}


// ==== FUN_00531e20 @ 0x00531e20 ====

undefined1 FUN_00531e20(void)

{
  return 1;
}


// ==== FUN_00531e30 @ 0x00531e30 ====

uint FUN_00531e30(int param_1)

{
  uint in_EAX;
  int in_ECX;
  
  if (param_1 == 0) {
    in_EAX = (**(code **)(**(int **)(in_ECX + 4) + 0x48))(in_ECX + 8,1);
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00531e50 @ 0x00531e50 ====

void FUN_00531e50(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b9014;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  *(undefined1 *)(in_ECX + 5) = *(undefined1 *)(param_2 + 3);
  return;
}


// ==== FUN_00531e90 @ 0x00531e90 ====

void FUN_00531e90(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar2 = *(int *)(in_ECX + 8);
  iVar1 = in_ECX + 8;
  iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x6c))(iVar1,0);
  if (uVar3 < (uint)(iVar4 + iVar2)) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x48))(iVar1,0);
    return;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x48))(iVar1,1);
  return;
}


// ==== FUN_00531ef0 @ 0x00531ef0 ====

undefined4 FUN_00531ef0(void)

{
  return 0x11;
}


// ==== FUN_00531f00 @ 0x00531f00 ====

undefined1 FUN_00531f00(void)

{
  return 1;
}


// ==== FUN_00531f10 @ 0x00531f10 ====

void FUN_00531f10(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x4c))(in_ECX + 8);
  return;
}


// ==== FUN_00531f20 @ 0x00531f20 ====

bool FUN_00531f20(int param_1)

{
  return param_1 == 0;
}


// ==== FUN_00531f30 @ 0x00531f30 ====

void FUN_00531f30(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b902c;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  return;
}


// ==== FUN_00531f70 @ 0x00531f70 ====

undefined4 FUN_00531f70(void)

{
  return 0x13;
}


// ==== FUN_00531f80 @ 0x00531f80 ====

undefined1 FUN_00531f80(void)

{
  return 1;
}


// ==== FUN_00531f90 @ 0x00531f90 ====

uint FUN_00531f90(int param_1)

{
  uint in_ECX;
  
  if (param_1 == 0) {
    in_ECX = (**(code **)(**(int **)(in_ECX + 4) + 0x50))(in_ECX + 8,*(undefined1 *)(in_ECX + 0x14))
    ;
  }
  return in_ECX & 0xffffff00;
}


// ==== FUN_00531fb0 @ 0x00531fb0 ====

void FUN_00531fb0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b9058;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  return;
}


// ==== FUN_00531ff0 @ 0x00531ff0 ====

undefined4 FUN_00531ff0(void)

{
  return 0x13;
}


// ==== FUN_00532000 @ 0x00532000 ====

undefined1 FUN_00532000(void)

{
  return 1;
}


// ==== FUN_00532010 @ 0x00532010 ====

uint FUN_00532010(int param_1)

{
  uint in_EAX;
  int in_ECX;
  
  if (param_1 == 0) {
    in_EAX = (**(code **)(**(int **)(in_ECX + 4) + 0x54))(in_ECX + 8,1);
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00532030 @ 0x00532030 ====

void FUN_00532030(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = param_1;
  *in_ECX = &PTR_FUN_009b9070;
  in_ECX[3] = *param_2;
  in_ECX[4] = param_2[1];
  in_ECX[5] = param_2[2];
  in_ECX[6] = param_2[3];
  *(undefined1 *)(in_ECX + 7) = *(undefined1 *)(param_2 + 4);
  *(undefined1 *)(in_ECX + 1) = 1;
  return;
}


// ==== FUN_00532080 @ 0x00532080 ====

undefined4 FUN_00532080(void)

{
  return 0x14;
}


// ==== FUN_00532090 @ 0x00532090 ====

undefined1 FUN_00532090(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_005320a0 @ 0x005320a0 ====

undefined1 FUN_005320a0(int param_1)

{
  int in_ECX;
  
  if (param_1 == 0) {
    *(undefined1 *)(in_ECX + 4) = 0;
    return 1;
  }
  return 0;
}


// ==== FUN_005320c0 @ 0x005320c0 ====

void FUN_005320c0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b9088;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  *(undefined1 *)(in_ECX + 5) = *(undefined1 *)(param_2 + 3);
  return;
}


// ==== FUN_00532100 @ 0x00532100 ====

void FUN_00532100(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x50))(in_ECX + 8,*(undefined1 *)(in_ECX + 0x14));
  uVar1 = *(undefined1 *)(in_ECX + 0x14);
  uVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  FUN_004dd240(0x16,200,1,uVar1,uVar2);
  return;
}


// ==== FUN_00532140 @ 0x00532140 ====

void FUN_00532140(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar1 = *(undefined1 *)(in_ECX + 0x1c);
  uVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  FUN_004dd240(0x16,200,2,uVar1,uVar2);
  (**(code **)(**(int **)(in_ECX + 8) + 0x58))(in_ECX + 0xc,*(undefined1 *)(in_ECX + 0x1c));
  return;
}


// ==== FUN_00532180 @ 0x00532180 ====

void FUN_00532180(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar2 = *(int *)(in_ECX + 8);
  iVar1 = in_ECX + 8;
  iVar4 = (**(code **)(**(int **)(in_ECX + 4) + 0x6c))(iVar1,0);
  if (uVar3 < (uint)(iVar4 + iVar2)) {
    uVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
    FUN_004dd240(0x16,200,3,0,uVar5);
    (**(code **)(**(int **)(in_ECX + 4) + 0x54))(iVar1,0);
    return;
  }
  uVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
  FUN_004dd240(0x16,200,3,1,uVar5);
  (**(code **)(**(int **)(in_ECX + 4) + 0x54))(iVar1,1);
  return;
}


// ==== FUN_00532210 @ 0x00532210 ====

undefined4 FUN_00532210(void)

{
  return 0x1d;
}


// ==== FUN_00532220 @ 0x00532220 ====

undefined1 FUN_00532220(void)

{
  return 1;
}


// ==== FUN_00532230 @ 0x00532230 ====

void FUN_00532230(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x5c))(in_ECX + 8);
  return;
}


// ==== FUN_00532240 @ 0x00532240 ====

bool FUN_00532240(int param_1)

{
  return param_1 == 0;
}


// ==== FUN_00532250 @ 0x00532250 ====

void FUN_00532250(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b90a0;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  *(undefined1 *)(in_ECX + 5) = *(undefined1 *)(param_2 + 3);
  return;
}


// ==== FUN_005322a0 @ 0x005322a0 ====

undefined4 FUN_005322a0(void)

{
  return 3;
}


// ==== FUN_005322b0 @ 0x005322b0 ====

bool FUN_005322b0(int param_1)

{
  return param_1 == 0;
}


// ==== FUN_005322c0 @ 0x005322c0 ====

void FUN_005322c0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[2] = param_1;
  *in_ECX = &PTR_FUN_009b90b8;
  in_ECX[3] = *param_2;
  in_ECX[4] = param_2[1];
  in_ECX[5] = param_2[2];
  in_ECX[6] = param_2[3];
  *(undefined2 *)(in_ECX + 7) = *(undefined2 *)(param_2 + 4);
  *(undefined1 *)((int)in_ECX + 0x1e) = *(undefined1 *)((int)param_2 + 0x12);
  return;
}


// ==== FUN_00532300 @ 0x00532300 ====

bool FUN_00532300(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  return uVar1 <= *(uint *)(in_ECX + 4);
}


// ==== FUN_00532320 @ 0x00532320 ====

void FUN_00532320(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x1b);
  iVar2 = *(int *)(in_ECX + 0xc);
  iVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(int *)(in_ECX + 4) = iVar3 + (iVar1 - iVar2);
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))(in_ECX + 0xc);
  return;
}


// ==== FUN_00532360 @ 0x00532360 ====

void FUN_00532360(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(in_ECX + 8);
  return;
}


// ==== FUN_00532370 @ 0x00532370 ====

undefined4 FUN_00532370(void)

{
  return 1;
}


// ==== FUN_00532380 @ 0x00532380 ====

undefined1 FUN_00532380(void)

{
  return 1;
}


// ==== FUN_00532390 @ 0x00532390 ====

undefined4 FUN_00532390(int param_1)

{
  if ((param_1 < 0) || (2 < param_1)) {
    return 0;
  }
  return 1;
}


// ==== FUN_005323b0 @ 0x005323b0 ====

void FUN_005323b0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b90d0;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  in_ECX[5] = param_2[3];
  return;
}


// ==== FUN_00532400 @ 0x00532400 ====

undefined4 FUN_00532400(void)

{
  return 0;
}


// ==== FUN_00532410 @ 0x00532410 ====

undefined1 FUN_00532410(void)

{
  return 1;
}


// ==== FUN_00532420 @ 0x00532420 ====

void FUN_00532420(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(in_ECX + 8);
  return;
}


// ==== FUN_00532430 @ 0x00532430 ====

bool FUN_00532430(int param_1)

{
  return param_1 == 0;
}


// ==== FUN_00532440 @ 0x00532440 ====

void FUN_00532440(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009b90e8;
  in_ECX[2] = *param_2;
  in_ECX[3] = param_2[1];
  in_ECX[4] = param_2[2];
  return;
}


// ==== FUN_00532470 @ 0x00532470 ====

undefined1 FUN_00532470(void)

{
  return 1;
}


// ==== FUN_00532480 @ 0x00532480 ====

undefined4 FUN_00532480(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5060004;
  *(undefined2 *)((int)pvVar1 + 6) = 0x10;
  uVar2 = FUN_004244d0();
  FUN_004d8570(uVar2);
  return 1;
}


// ==== FUN_005324c0 @ 0x005324c0 ====

undefined4 FUN_005324c0(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5060004;
  *(undefined2 *)((int)pvVar1 + 6) = 0x10;
  uVar2 = FUN_004244d0();
  FUN_004d8570(uVar2);
  return 1;
}


// ==== FUN_00532500 @ 0x00532500 ====

undefined4 FUN_00532500(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x8000005;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  iVar2 = FUN_004244d0();
  *(undefined1 *)(iVar2 + 0x10) = param_3;
  FUN_004d8570(iVar2);
  return 1;
}


// ==== FUN_00532580 @ 0x00532580 ====

undefined4 FUN_00532580(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  void *pvVar1;
  int iVar2;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x6000000;
  *(undefined2 *)((int)pvVar1 + 6) = 0x20;
  iVar2 = FUN_004244d0();
  *(undefined4 *)(iVar2 + 0x10) = *param_3;
  *(undefined4 *)(iVar2 + 0x14) = param_3[1];
  *(undefined1 *)(iVar2 + 0x18) = *(undefined1 *)(param_3 + 2);
  *(undefined1 *)(iVar2 + 0x19) = *(undefined1 *)((int)param_3 + 9);
  *(undefined1 *)(iVar2 + 0x1a) = *(undefined1 *)((int)param_3 + 10);
  *(undefined1 *)(iVar2 + 0x1b) = *(undefined1 *)((int)param_3 + 0xb);
  *(undefined1 *)(iVar2 + 0x1c) = *(undefined1 *)(param_3 + 3);
  *(undefined1 *)(iVar2 + 0x1d) = *(undefined1 *)((int)param_3 + 0xd);
  *(undefined1 *)(iVar2 + 0x1e) = *(undefined1 *)((int)param_3 + 0xe);
  FUN_004d8570(iVar2);
  return 1;
}


// ==== FUN_00532600 @ 0x00532600 ====

undefined4
FUN_00532600(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined1 local_12 [6];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = param_1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x6020001;
  *(undefined2 *)((int)pvVar2 + 6) = 0x20;
  iVar3 = FUN_004244d0();
  iVar1 = *DAT_00b5a77c;
  local_c = *param_4;
  local_8 = param_4[1];
  local_4 = 0;
  uVar4 = FUN_004ef0e0(local_12);
  piVar5 = (int *)(**(code **)(iVar1 + 4))(uVar4);
  *(undefined4 *)(iVar3 + 0x10) = param_2;
  puVar6 = (undefined4 *)(**(code **)(*piVar5 + 8))();
  *(undefined4 *)(iVar3 + 0x14) = *puVar6;
  *(undefined4 *)(iVar3 + 0x18) = puVar6[1];
  *(undefined1 *)(iVar3 + 0x1c) = param_4._0_1_;
  FUN_004d8570(iVar3);
  (**(code **)(*DAT_00b5a77c + 0x18))(piVar5);
  return 1;
}


// ==== FUN_005326c0 @ 0x005326c0 ====

undefined4 FUN_005326c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x6020001;
  *(undefined2 *)((int)pvVar1 + 6) = 0x20;
  iVar2 = FUN_004244d0();
  piVar3 = (int *)(**(code **)(*DAT_00b5a77c + 8))(param_4);
  *(undefined4 *)(iVar2 + 0x10) = param_2;
  puVar4 = (undefined4 *)(**(code **)(*piVar3 + 8))();
  *(undefined4 *)(iVar2 + 0x14) = *puVar4;
  *(undefined4 *)(iVar2 + 0x18) = puVar4[1];
  *(undefined1 *)(iVar2 + 0x1c) = (undefined1)param_4;
  FUN_004d8570(iVar2);
  (**(code **)(*DAT_00b5a77c + 0x18))(piVar3);
  return 1;
}


// ==== FUN_00532780 @ 0x00532780 ====

undefined4 FUN_00532780(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x509000a;
  *(undefined2 *)((int)pvVar1 + 6) = 0x10;
  uVar2 = FUN_004244d0();
  FUN_004d8570(uVar2);
  return 1;
}


// ==== FUN_00532810 @ 0x00532810 ====

undefined4 FUN_00532810(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x509000b;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return 1;
}


// ==== FUN_00532900 @ 0x00532900 ====

void FUN_00532900(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9114;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00532920 @ 0x00532920 ====

void FUN_00532920(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9128;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[8] = param_1;
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005422c0();
  }
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    in_ECX[7] = 0;
    return;
  }
  uVar2 = FUN_00542090(in_ECX);
  in_ECX[7] = uVar2;
  return;
}


// ==== FUN_005329b0 @ 0x005329b0 ====

void FUN_005329b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_005422e0(*(undefined4 *)(in_ECX + 0x20),in_ECX + 4);
  }
  if (*(int *)(in_ECX + 0x1c) != 0) {
    (**(code **)(*DAT_00b5a79c + 8))(*(int *)(in_ECX + 0x1c));
  }
  return;
}


// ==== FUN_005329e0 @ 0x005329e0 ====

void FUN_005329e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_00542330();
  }
  if (*(int *)(in_ECX + 0x1c) != 0) {
    (**(code **)(*DAT_00b5a79c + 0xc))(*(int *)(in_ECX + 0x1c));
  }
  return;
}


// ==== FUN_00532a10 @ 0x00532a10 ====

bool FUN_00532a10(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5aeec + 0x38))();
  if (cVar1 == '\x01') {
    return false;
  }
  cVar1 = FUN_00542760(0);
  if (cVar1 == '\x01') {
    return true;
  }
  cVar1 = FUN_00542760(9);
  return cVar1 == '\x01';
}


// ==== FUN_00532a50 @ 0x00532a50 ====

undefined1 FUN_00532a50(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 8));
  if (piVar2 == (int *)0x0) {
switchD_00532a81_caseD_7:
    return 0;
  }
  uVar3 = (**(code **)(*piVar2 + 0xc))();
  switch(uVar3) {
  case 0:
    cVar1 = FUN_00542760(0);
    if (cVar1 == '\x01') {
      return 1;
    }
    cVar1 = FUN_00542760(7);
    if (cVar1 == '\x01') {
      return 1;
    }
    break;
  case 1:
  case 3:
  case 5:
    cVar1 = FUN_00542760(0);
    if (cVar1 == '\x01') {
      return 1;
    }
    iVar4 = (**(code **)(*DAT_00b5adc0 + 0x18))();
    if (iVar4 == *(int *)(in_ECX + 8)) {
      FUN_00542760(2);
      return 1;
    }
    goto LAB_00532b3a;
  case 2:
    cVar1 = FUN_00542760(0);
    if (cVar1 == '\x01') {
      return 1;
    }
    break;
  case 4:
    FUN_00542760(0xb);
    return 1;
  case 6:
    cVar1 = FUN_00542760(0);
    if (cVar1 == '\x01') {
      return 1;
    }
    iVar4 = (**(code **)(*DAT_00b5adc0 + 0x18))();
    if (iVar4 == *(int *)(in_ECX + 8)) {
      FUN_00542760(0xd);
      return 1;
    }
LAB_00532b3a:
    FUN_00542760(0xc);
    return 1;
  default:
    goto switchD_00532a81_caseD_7;
  case 9:
  case 10:
  case 0xe:
    FUN_00542760(10);
    return 1;
  }
  FUN_00542760(1);
  return 1;
}


// ==== FUN_00532b80 @ 0x00532b80 ====

void FUN_00532b80(undefined1 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 1;
  uVar1 = (**(code **)(*DAT_00b5adc0 + 0x18))();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined1 *)(in_ECX + 4) = param_1;
  (**(code **)(*DAT_00b5ad54 + 0x40))(param_2);
  FUN_00542760(5);
  return;
}


// ==== FUN_00532bf0 @ 0x00532bf0 ====

void FUN_00532bf0(int *param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int *piVar3;
  int aiStack_28 [6];
  undefined4 uStack_10;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 0x10001) {
    *(undefined1 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined1 *)(in_ECX + 5) = 0;
    return;
  }
  piVar2 = param_1 + 3;
  piVar3 = aiStack_28;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  }
  *(int *)(in_ECX + 8) = aiStack_28[1];
  *(undefined4 *)(in_ECX + 0x10) = uStack_10;
  *(undefined4 *)(in_ECX + 0x14) = uStack_8;
  *(byte *)(in_ECX + 4) = (byte)uStack_4 & 1;
  *(int *)(in_ECX + 0xc) = aiStack_28[0];
  *(byte *)(in_ECX + 5) = (byte)(uStack_4 >> 1) & 1;
  return;
}


// ==== FUN_00532ca0 @ 0x00532ca0 ====

void FUN_00532ca0(int *param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int *piVar3;
  int aiStack_44 [4];
  undefined4 uStack_34;
  int aiStack_28 [6];
  undefined4 uStack_10;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 0x10003) {
    *(undefined1 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined1 *)(in_ECX + 5) = 0;
    return;
  }
  piVar2 = param_1 + 3;
  piVar3 = aiStack_44;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  }
  piVar2 = param_1 + 10;
  piVar3 = aiStack_28;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  }
  *(undefined4 *)(in_ECX + 8) = uStack_34;
  *(undefined4 *)(in_ECX + 0x10) = uStack_10;
  *(undefined4 *)(in_ECX + 0x14) = uStack_8;
  *(byte *)(in_ECX + 4) = (byte)uStack_4 & 1;
  *(int *)(in_ECX + 0xc) = aiStack_44[2];
  *(byte *)(in_ECX + 5) = (byte)(uStack_4 >> 1) & 1;
  return;
}


// ==== FUN_00532d60 @ 0x00532d60 ====

bool FUN_00532d60(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    cVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x14))();
    if (cVar1 == '\0') {
      cVar1 = FUN_005179b0();
      if (cVar1 == '\0') {
        piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x20) + 8))();
        if (piVar2 != (int *)0x0) {
          piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
          if (piVar2 != (int *)0x0) {
            iVar3 = (**(code **)(*piVar2 + 8))();
            return iVar3 != param_1;
          }
        }
      }
    }
  }
  return false;
}


// ==== FUN_00532db0 @ 0x00532db0 ====

void FUN_00532db0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9128;
  if (in_ECX[6] != 0) {
    FUN_00542330();
  }
  if (in_ECX[7] != 0) {
    (**(code **)(*DAT_00b5a79c + 0xc))(in_ECX[7]);
  }
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
  if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[7])(1);
  }
  in_ECX[7] = 0;
  *in_ECX = &PTR_FUN_009b9114;
  return;
}


// ==== FUN_00532e10 @ 0x00532e10 ====

bool FUN_00532e10(void)

{
  char cVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 2) {
    cVar1 = (**(code **)(*DAT_00b5aeec + 0x38))();
    if (cVar1 != '\x01') {
      cVar1 = FUN_00542760(0);
      if (cVar1 == '\x01') {
        return true;
      }
      cVar1 = FUN_00542760(9);
      return cVar1 == '\x01';
    }
  }
  return false;
}


// ==== FUN_00532e70 @ 0x00532e70 ====

void FUN_00532e70(undefined1 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 1;
  uVar1 = (**(code **)(*DAT_00b5adc0 + 0x18))();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined1 *)(in_ECX + 4) = param_1;
  if (*(int *)(in_ECX + 0xc) == 1) {
    FUN_00532a50();
    return;
  }
  if (*(int *)(in_ECX + 0xc) == 2) {
    FUN_00532a10();
  }
  return;
}


// ==== FUN_00532ef0 @ 0x00532ef0 ====

uint FUN_00532ef0(int *param_1)

{
  uint in_EAX;
  undefined4 uVar1;
  uint uVar2;
  
  if (param_1[2] == 0) {
    uVar1 = (**(code **)(*param_1 + 0x10))();
    in_EAX = FUN_00532d60(uVar1);
    if ((char)in_EAX != '\0') {
      in_EAX = FUN_00532ca0(param_1);
      if (param_1[6] == 1) {
        uVar2 = FUN_00532e10();
        return uVar2;
      }
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00532f40 @ 0x00532f40 ====

uint FUN_00532f40(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  if (iVar1 == 1) {
    FUN_00542760(6);
    uVar2 = *(uint *)(in_ECX + 0xc);
    if (uVar2 == 1) {
      uVar2 = FUN_00532a50();
      return uVar2;
    }
    if (uVar2 == 2) {
      uVar2 = FUN_00532a10();
      return uVar2;
    }
  }
  else {
    if (iVar1 == 2) {
      FUN_00542760(6);
      uVar2 = FUN_00542760(8);
      return uVar2;
    }
    uVar2 = iVar1 - 3;
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_00532fc0 @ 0x00532fc0 ====

uint FUN_00532fc0(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 0x10))();
  uVar2 = FUN_00532d60(uVar1);
  if ((char)uVar2 != '\0') {
    FUN_00532bf0(param_1);
    if (param_1[2] == 1) {
      uVar2 = FUN_00532f40();
      return uVar2;
    }
    uVar2 = param_1[2] - 2;
    if (uVar2 == 0) {
      uVar2 = *(uint *)(in_ECX + 0xc);
      if (uVar2 == 1) {
        uVar2 = FUN_00532a50();
        return uVar2;
      }
      if (uVar2 == 2) {
        uVar2 = FUN_00532a10();
        return uVar2;
      }
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_00533030 @ 0x00533030 ====

undefined4 FUN_00533030(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    cVar1 = FUN_00532fc0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x10003) {
    cVar1 = FUN_00532ef0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00533080 @ 0x00533080 ====

void FUN_00533080(byte param_1)

{
  void *in_ECX;
  
  FUN_00532db0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005330b0 @ 0x005330b0 ====

uint FUN_005330b0(void)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xc);
  if (iVar1 == 1) {
    uVar2 = FUN_00542760(6);
    return uVar2 & 0xffffff00;
  }
  if (iVar1 == 2) {
    FUN_00542760(6);
    uVar2 = FUN_00542760(8);
    return uVar2;
  }
  return iVar1 - 3U & 0xffffff00;
}


// ==== FUN_00533100 @ 0x00533100 ====

uint FUN_00533100(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x18))();
  if ((char)uVar1 == '\0') {
    return uVar1 & 0xffffff00;
  }
  uVar1 = FUN_00542760(5);
  return uVar1;
}


// ==== FUN_00533120 @ 0x00533120 ====

void FUN_00533120(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b913c;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[8] = param_1;
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005422c0();
  }
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(0xc);
  if (pvVar1 == (void *)0x0) {
    in_ECX[7] = 0;
    return;
  }
  uVar2 = FUN_00542910(in_ECX);
  in_ECX[7] = uVar2;
  return;
}


// ==== FUN_005331b0 @ 0x005331b0 ====

void FUN_005331b0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_005422e0(*(undefined4 *)(in_ECX + 0x20),in_ECX + 4);
  }
  if (*(int *)(in_ECX + 0x1c) != 0) {
    (**(code **)(*DAT_00b5a79c + 8))(*(int *)(in_ECX + 0x1c));
  }
  return;
}


// ==== FUN_005331e0 @ 0x005331e0 ====

void FUN_005331e0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_00542330();
  }
  if (*(int *)(in_ECX + 0x1c) != 0) {
    (**(code **)(*DAT_00b5a79c + 0xc))(*(int *)(in_ECX + 0x1c));
  }
  return;
}


// ==== FUN_00533210 @ 0x00533210 ====

undefined1 FUN_00533210(void)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5aeec + 0x38))();
  if (cVar1 != '\x01') {
    if (*(char *)(in_ECX + 5) != '\x01') {
      cVar1 = FUN_00542760(0);
      if ((cVar1 == '\x01') || (cVar1 = FUN_00542760(9), cVar1 == '\x01')) {
        return 1;
      }
      return 0;
    }
    cVar1 = FUN_00542760(3);
    if (cVar1 == '\x01') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00533260 @ 0x00533260 ====

undefined1 FUN_00533260(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 8));
  if (piVar2 == (int *)0x0) {
switchD_00533291_caseD_7:
    return 0;
  }
  uVar3 = (**(code **)(*piVar2 + 0xc))();
  switch(uVar3) {
  case 0:
    cVar1 = FUN_00542760(0);
    if (cVar1 == '\x01') {
      return 1;
    }
    cVar1 = FUN_00542760(7);
    if (cVar1 == '\x01') {
      return 1;
    }
    break;
  case 1:
  case 3:
  case 5:
    cVar1 = FUN_00542760(0);
    if (cVar1 == '\x01') {
      return 1;
    }
    iVar4 = (**(code **)(*DAT_00b5adc0 + 0x18))();
    if (iVar4 == *(int *)(in_ECX + 8)) {
      FUN_00542760(2);
      return 1;
    }
    goto LAB_0053334a;
  case 2:
    cVar1 = FUN_00542760(0);
    if (cVar1 == '\x01') {
      return 1;
    }
    break;
  case 4:
    FUN_00542760(0xb);
    return 1;
  case 6:
    cVar1 = FUN_00542760(0);
    if (cVar1 == '\x01') {
      return 1;
    }
    iVar4 = (**(code **)(*DAT_00b5adc0 + 0x18))();
    if (iVar4 == *(int *)(in_ECX + 8)) {
      FUN_00542760(0xd);
      return 1;
    }
LAB_0053334a:
    FUN_00542760(0xc);
    return 1;
  default:
    goto switchD_00533291_caseD_7;
  case 9:
  case 10:
  case 0xe:
    FUN_00542760(10);
    return 1;
  }
  FUN_00542760(1);
  return 1;
}


// ==== FUN_00533390 @ 0x00533390 ====

uint FUN_00533390(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 8));
  uVar3 = 0;
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0xc))();
    uVar3 = 0;
    switch(uVar2) {
    case 0:
    case 1:
    case 5:
    case 6:
      uVar3 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x18))();
      if ((char)uVar3 != '\0') {
        uVar3 = FUN_00542760(5);
        return uVar3;
      }
    }
  }
  return uVar3 & 0xffffff00;
}


// ==== FUN_005333f0 @ 0x005333f0 ====

void FUN_005333f0(int *param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int *piVar3;
  int aiStack_28 [6];
  undefined4 uStack_10;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 0x10001) {
    *(undefined1 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined1 *)(in_ECX + 5) = 0;
    return;
  }
  piVar2 = param_1 + 3;
  piVar3 = aiStack_28;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  }
  *(int *)(in_ECX + 8) = aiStack_28[1];
  *(undefined4 *)(in_ECX + 0x10) = uStack_10;
  *(undefined4 *)(in_ECX + 0x14) = uStack_8;
  *(byte *)(in_ECX + 4) = (byte)uStack_4 & 1;
  *(int *)(in_ECX + 0xc) = aiStack_28[0];
  *(byte *)(in_ECX + 5) = (byte)(uStack_4 >> 1) & 1;
  return;
}


// ==== FUN_005334a0 @ 0x005334a0 ====

void FUN_005334a0(int *param_1)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int *piVar3;
  int aiStack_44 [4];
  undefined4 uStack_34;
  int aiStack_28 [6];
  undefined4 uStack_10;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 0x10003) {
    *(undefined1 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined1 *)(in_ECX + 5) = 0;
    return;
  }
  piVar2 = param_1 + 3;
  piVar3 = aiStack_44;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  }
  piVar2 = param_1 + 10;
  piVar3 = aiStack_28;
  for (iVar1 = 10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  }
  *(undefined4 *)(in_ECX + 8) = uStack_34;
  *(undefined4 *)(in_ECX + 0x10) = uStack_10;
  *(undefined4 *)(in_ECX + 0x14) = uStack_8;
  *(byte *)(in_ECX + 4) = (byte)uStack_4 & 1;
  *(int *)(in_ECX + 0xc) = aiStack_44[2];
  *(byte *)(in_ECX + 5) = (byte)(uStack_4 >> 1) & 1;
  return;
}


// ==== FUN_00533560 @ 0x00533560 ====

bool FUN_00533560(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    cVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x14))();
    if (cVar1 == '\0') {
      cVar1 = FUN_005179b0();
      if (cVar1 == '\0') {
        piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0x20) + 8))();
        if (piVar2 != (int *)0x0) {
          piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
          if (piVar2 != (int *)0x0) {
            iVar3 = (**(code **)(*piVar2 + 8))();
            return iVar3 != param_1;
          }
        }
      }
    }
  }
  return false;
}


// ==== FUN_005335b0 @ 0x005335b0 ====

void FUN_005335b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b913c;
  if (in_ECX[6] != 0) {
    FUN_00542330();
  }
  if (in_ECX[7] != 0) {
    (**(code **)(*DAT_00b5a79c + 0xc))(in_ECX[7]);
  }
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
  if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[7])(1);
  }
  in_ECX[7] = 0;
  *in_ECX = &PTR_FUN_009b9114;
  return;
}


// ==== FUN_00533630 @ 0x00533630 ====

uint FUN_00533630(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0xc);
  if (uVar1 == 1) {
    uVar1 = FUN_00533390();
    return uVar1;
  }
  if (uVar1 == 2) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x18))();
    if ((char)uVar1 != '\0') {
      uVar1 = FUN_00542760(5);
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00533670 @ 0x00533670 ====

void FUN_00533670(undefined1 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 1;
  uVar1 = (**(code **)(*DAT_00b5adc0 + 0x18))();
  *(undefined4 *)(in_ECX + 8) = uVar1;
  *(undefined1 *)(in_ECX + 4) = param_1;
  if (*(int *)(in_ECX + 0xc) == 1) {
    FUN_00533260();
    return;
  }
  if (*(int *)(in_ECX + 0xc) == 2) {
    FUN_00533210();
  }
  return;
}


// ==== FUN_00533710 @ 0x00533710 ====

uint FUN_00533710(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0xc);
  if (uVar1 == 1) {
    uVar1 = FUN_00533260();
    return uVar1;
  }
  if (uVar1 == 2) {
    uVar1 = FUN_00533210();
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00533730 @ 0x00533730 ====

uint FUN_00533730(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0xc);
  if (uVar1 == 1) {
    uVar1 = FUN_00533390();
    return uVar1;
  }
  if (uVar1 == 2) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x20) + 0x18))();
    if ((char)uVar1 != '\0') {
      uVar1 = FUN_00542760(5);
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00533770 @ 0x00533770 ====

uint FUN_00533770(int *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = (**(code **)(*param_1 + 0x10))();
  uVar2 = FUN_00533560(uVar1);
  if ((char)uVar2 != '\0') {
    FUN_005333f0(param_1);
    uVar2 = param_1[2] - 1;
    switch(uVar2) {
    case 0:
      uVar2 = FUN_005330b0();
      return uVar2;
    case 1:
      uVar2 = FUN_00533710();
      return uVar2;
    case 3:
      uVar2 = FUN_00533730();
      return uVar2;
    }
  }
  return uVar2 & 0xffffff00;
}


// ==== FUN_005337e0 @ 0x005337e0 ====

uint FUN_005337e0(int *param_1)

{
  uint in_EAX;
  undefined4 uVar1;
  uint uVar2;
  int in_ECX;
  
  if (param_1[2] == 0) {
    uVar1 = (**(code **)(*param_1 + 0x10))();
    in_EAX = FUN_00533560(uVar1);
    if ((char)in_EAX != '\0') {
      in_EAX = FUN_005334a0(param_1);
      if (param_1[6] == 1) {
        in_EAX = *(uint *)(in_ECX + 0xc);
        if (in_EAX == 1) {
          uVar2 = FUN_00533260();
          return uVar2;
        }
        if (in_EAX == 2) {
          uVar2 = FUN_00533210();
          return uVar2;
        }
      }
    }
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00533840 @ 0x00533840 ====

undefined4 FUN_00533840(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x10001) {
    cVar1 = FUN_00533770(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x10003) {
    cVar1 = FUN_005337e0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00533890 @ 0x00533890 ====

void FUN_00533890(byte param_1)

{
  void *in_ECX;
  
  FUN_005335b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005338b0 @ 0x005338b0 ====

void FUN_005338b0(void)

{
  return;
}


// ==== FUN_005338c0 @ 0x005338c0 ====

void FUN_005338c0(void)

{
  return;
}


// ==== FUN_005338d0 @ 0x005338d0 ====

undefined1 FUN_005338d0(void)

{
  return 0;
}


// ==== FUN_005338e0 @ 0x005338e0 ====

void FUN_005338e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9150;
  return;
}


// ==== FUN_00533900 @ 0x00533900 ====

void FUN_00533900(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9164;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00533930 @ 0x00533930 ====

void FUN_00533930(int param_1)

{
  int *piVar1;
  int in_ECX;
  
  if (1000 < (uint)(param_1 - *(int *)(in_ECX + 4))) {
    piVar1 = (int *)FUN_006ec490();
    (**(code **)(*piVar1 + 4))();
    *(int *)(in_ECX + 4) = param_1;
  }
  return;
}


// ==== FUN_00533960 @ 0x00533960 ====

void FUN_00533960(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9170;
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00533970 @ 0x00533970 ====

void FUN_00533970(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b917c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00533990 @ 0x00533990 ====

undefined4 FUN_00533990(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_005339a0 @ 0x005339a0 ====

void FUN_005339a0(int param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 4))();
  in_ECX[2] = param_1;
  return;
}


// ==== FUN_005339c0 @ 0x005339c0 ====

void FUN_005339c0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9194;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_005339e0 @ 0x005339e0 ====

void FUN_005339e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9194;
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00533a10 @ 0x00533a10 ====

void FUN_00533a10(void)

{
  int in_ECX;
  
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_00533a30 @ 0x00533a30 ====

undefined4 FUN_00533a30(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5a980 + 0x18))();
  if (cVar1 != '\a') {
    cVar1 = (**(code **)(*DAT_00b5a980 + 0x18))();
    if (cVar1 != '\b') {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_00533a60 @ 0x00533a60 ====

void FUN_00533a60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9194;
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00533aa0 @ 0x00533aa0 ====

void FUN_00533aa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b91b4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00533b10 @ 0x00533b10 ====

void FUN_00533b10(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined3 uVar2;
  undefined1 uVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int in_ECX;
  float10 fVar7;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  float fStack_18;
  undefined4 auStack_14 [2];
  undefined4 uStack_c;
  undefined1 uStack_5;
  undefined3 uStack_4;
  
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 0x18))();
  uVar6 = *(undefined4 *)(param_2 + 0x14);
  FUN_00797a50(auStack_14,0,0x14);
  uStack_c = CONCAT13(10,CONCAT12(uVar3,(undefined2)uStack_c));
  auStack_14[0] = uVar6;
  piVar4 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar5 = (undefined4 *)(**(code **)(*piVar4 + 0x28))();
  uStack_28 = *puVar5;
  uStack_24 = puVar5[1];
  uStack_20 = uStack_28;
  uStack_1c = uStack_24;
  piVar4 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  uVar6 = (**(code **)(*piVar4 + 0x2c))();
  fVar7 = (float10)FUN_0040d5f0(uVar6);
  fStack_18 = (float)fVar7;
  puVar5 = (undefined4 *)FUN_004ef0e0(&uStack_28);
  uVar6 = *puVar5;
  uStack_c = CONCAT22(uStack_c._2_2_,*(undefined2 *)(puVar5 + 1));
  uVar2 = *(undefined3 *)(param_2 + 4);
  uVar3 = *(undefined1 *)(param_2 + 0xc);
  uVar1 = *(undefined4 *)(param_2 + 8);
  *param_1 = auStack_14[0];
  param_1[1] = uVar6;
  param_1[2] = uStack_c;
  uStack_5 = (undefined1)uVar1;
  param_1[3] = CONCAT13(uStack_5,uVar2);
  uStack_4 = (undefined3)((uint)uVar1 >> 8);
  param_1[4] = CONCAT13(uVar3,uStack_4);
  return;
}


// ==== FUN_00533c50 @ 0x00533c50 ====

void FUN_00533c50(undefined4 param_1)

{
  undefined4 *puVar1;
  
  if (DAT_00b5af24 == (undefined4 *)0x0) {
    puVar1 = operator_new(8);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009b91c0;
      puVar1[1] = param_1;
      if (puVar1 + 1 != (undefined4 *)0x0) {
        DAT_00b5af24 = puVar1;
        return;
      }
      DAT_00b5af24 = (undefined4 *)0x0;
    }
  }
  return;
}


// ==== FUN_00533c90 @ 0x00533c90 ====

void FUN_00533c90(void)

{
  if (DAT_00b5af24 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5af24)(1);
  }
  return;
}


// ==== FUN_00533cd0 @ 0x00533cd0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00533cd0(undefined4 *param_1,float *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  float *pfVar3;
  undefined4 *puVar4;
  float fStack_8;
  float fStack_4;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  pfVar3 = (float *)(**(code **)(*piVar2 + 0x28))();
  fStack_4 = param_2[1] - pfVar3[1];
  fStack_8 = *param_2 - *pfVar3;
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  pfVar3 = (float *)(**(code **)(*piVar2 + 0x28))();
  if (_DAT_009b91ac <
      SQRT((param_2[1] - pfVar3[1]) * (param_2[1] - pfVar3[1]) +
           (*param_2 - *pfVar3) * (*param_2 - *pfVar3))) {
    thunk_FUN_0079de77();
    *(float **)fStack_4 = &fStack_8;
    *(float **)((int)fStack_4 + 4) = &fStack_8;
    return;
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar4 = (undefined4 *)(**(code **)(*piVar2 + 0x2c))();
  uVar1 = puVar4[1];
  *param_1 = *puVar4;
  param_1[1] = uVar1;
  return;
}


// ==== FUN_00533da0 @ 0x00533da0 ====

void FUN_00533da0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined1 auStack_a [10];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  piVar3 = DAT_00b5a780;
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  piVar3 = (int *)(**(code **)(*piVar3 + 8))(iVar2 + 0x14);
  if (piVar3 == (int *)0x0) {
    return;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x18))();
  FUN_005081d0(unaff_retaddr);
  (**(code **)(*piVar3 + 0xc))(auStack_a + -6);
  return;
}


// ==== FUN_00533e20 @ 0x00533e20 ====

float10 FUN_00533e20(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined1 auStack_a [10];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  piVar3 = DAT_00b5a780;
  iVar2 = (**(code **)(*piVar1 + 0x1c))();
  piVar3 = (int *)(**(code **)(*piVar3 + 8))(iVar2 + 0x14);
  if (piVar3 != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 4) + 0x18))();
    iVar2 = (**(code **)(*piVar3 + 0xc))(auStack_a + -6);
    if (iVar2 != 0) {
      return (float10)*(float *)(iVar2 + 0x11c);
    }
  }
  return (float10)DAT_0099d080;
}


// ==== FUN_00533eb0 @ 0x00533eb0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint FUN_00533eb0(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  float10 fVar4;
  float10 fVar5;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0xf) == 2) {
    iVar2 = FUN_00508200(param_1);
    uVar3 = FUN_00508230(param_1);
    fVar4 = (float10)FUN_00533e20(uVar3);
    fVar5 = (float10)iVar2;
    if (iVar2 < 0) {
      fVar5 = fVar5 + (float10)_DAT_0099d104;
    }
    uVar1 = (int)ROUND(fVar5 * fVar4);
    if (iVar2 - 1U < (uint)(int)ROUND(fVar5 * fVar4)) {
      uVar1 = iVar2 - 1U;
    }
    if (uVar1 == 0) {
      return 1;
    }
  }
  else if (*(int *)(param_1 + 0xf) == 1) {
    uVar1 = FUN_00508200(param_1);
  }
  return uVar1;
}


// ==== FUN_00533f40 @ 0x00533f40 ====

void FUN_00533f40(undefined4 param_1,int param_2,int param_3)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_ECX;
  int *piVar6;
  float10 fVar7;
  undefined1 auStack_54 [2];
  undefined1 auStack_52 [6];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  float fStack_44;
  int aiStack_40 [4];
  undefined2 uStack_30;
  undefined1 uStack_2e;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined2 uStack_2a;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  undefined1 auStack_20 [28];
  int *piStack_4;
  
  aiStack_40[2] = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  aiStack_40[3] = FUN_00533eb0(param_3);
  aiStack_40[3] = aiStack_40[3] + *(int *)(param_2 + 0x14);
  uStack_30 = *(ushort *)(param_3 + 0xc);
  uVar4 = *(undefined4 *)(param_3 + 0xf);
  uStack_2e = *(undefined1 *)(param_3 + 0xe);
  uStack_2c = (undefined1)uVar4;
  uStack_2b = (undefined1)((uint)uVar4 >> 8);
  uStack_2a = (undefined2)((uint)uVar4 >> 0x10);
  uStack_28 = *(undefined1 *)(param_3 + 0x13);
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x18))();
  uStack_26 = CONCAT11(uVar1,(undefined1)uStack_26);
  uStack_28 = (**(code **)(**(int **)(in_ECX + 4) + 0x20))(1);
  piVar6 = DAT_00b5acc4;
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  iVar3 = (**(code **)(*piVar6 + 0x24))(auStack_20);
  uVar4 = FUN_00533cd0(auStack_54,iVar3 + 0xc);
  puVar5 = (undefined4 *)(**(code **)(*piVar2 + 0x28))();
  fVar7 = (float10)FUN_0040d5f0(uVar4);
  fStack_44 = (float)fVar7;
  uStack_4c = *puVar5;
  uStack_48 = puVar5[1];
  puVar5 = (undefined4 *)FUN_004ef0e0(auStack_54 + -6);
  uVar4 = *puVar5;
  uStack_2a = (undefined2)uVar4;
  uStack_28 = (undefined1)((uint)uVar4 >> 0x10);
  uStack_27 = (undefined1)((uint)uVar4 >> 0x18);
  uStack_26 = *(undefined2 *)(puVar5 + 1);
  uStack_2b = (char)*(undefined2 *)(puVar5 + 1);
  uStack_30 = uStack_30 & 0xff;
  uStack_2e = 0;
  if (*(int *)(param_3 + 0xf) == 2) {
    iVar3 = FUN_00533da0(param_3);
    if (iVar3 == 0) {
      uStack_30 = uStack_30 & 0xff;
      uStack_2e = 0;
    }
    else {
      uStack_30 = CONCAT11(*(undefined1 *)(iVar3 + 0x118),(undefined1)uStack_30);
      uStack_2e = *(undefined1 *)(iVar3 + 0x119);
    }
  }
  piVar6 = aiStack_40;
  for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piStack_4 = *piVar6;
    piVar6 = piVar6 + 1;
    piStack_4 = piStack_4 + 1;
  }
  return;
}


// ==== FUN_00534080 @ 0x00534080 ====

void FUN_00534080(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  float10 fVar6;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  float fStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined3 auStack_20 [8];
  
  FUN_00533b10(&local_30,param_1);
  cVar1 = FUN_00508180(&local_30);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*DAT_00b5acc0 + 0x30))(CONCAT31(auStack_20[0],uStack_24._3_1_));
    if (cVar1 != '\0') {
      (**(code **)(*DAT_00b5acc0 + 0x40))
                (*(undefined4 *)(param_1 + 0x14),uStack_34,local_30,uStack_2c,uStack_28,uStack_24);
      return;
    }
  }
  else {
    (**(code **)(*DAT_00b5acc0 + 0x34))(*(undefined4 *)(param_1 + 0x14));
    (**(code **)(*DAT_00b5acc0 + 0x14))();
    piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x28))();
    iVar4 = (**(code **)(*DAT_00b5acc4 + 0x24))(auStack_20);
    uStack_4c = *(undefined4 *)(iVar4 + 0x14);
    uStack_48 = *(undefined4 *)(iVar4 + 0x18);
    uStack_44 = *puVar3;
    uStack_40 = puVar3[1];
    fVar6 = (float10)FUN_0040d5f0(&uStack_4c);
    fStack_3c = (float)fVar6;
    puVar3 = (undefined4 *)FUN_004ef0e0((int)auStack_20 + -0x32);
    uStack_34 = *puVar3;
    local_30 = CONCAT22(local_30._2_2_,*(undefined2 *)(puVar3 + 1));
    (**(code **)(**(int **)(in_ECX + 4) + 0x50))(&uStack_38);
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = &PTR_FUN_009b2d88;
    }
    uVar5 = (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
    puVar3[1] = uVar5;
    FUN_00403e60(puVar3 + 2,&fStack_3c,0x19);
    FUN_00797a20(puVar3);
    (**(code **)(*DAT_00b5acc0 + 0x40))
              (*(undefined4 *)(param_1 + 0x14),fStack_3c,uStack_38,uStack_34,local_30,uStack_2c);
    cVar1 = FUN_005080b0(*(undefined4 *)(param_1 + 8));
    if (cVar1 != '\0') {
      FUN_00533f40(&uStack_40,param_1,auStack_20 + -0xd);
      iVar4 = *DAT_00b5acc0;
      uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))(&uStack_40);
      (**(code **)(iVar4 + 0x20))(uVar5);
    }
  }
  return;
}


// ==== FUN_00534250 @ 0x00534250 ====

void FUN_00534250(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5af24 = 0;
  *in_ECX = &PTR_FUN_009b91b4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00534280 @ 0x00534280 ====

void FUN_00534280(void)

{
  void *pvVar1;
  
  if (DAT_00b5acdc == 0) {
    pvVar1 = operator_new(0x24);
    if (pvVar1 != (void *)0x0) {
      FUN_00542e60();
      return;
    }
  }
  return;
}


// ==== FUN_005342a0 @ 0x005342a0 ====

void FUN_005342a0(void)

{
  if (DAT_00b5acdc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5acdc)(1);
  }
  return;
}


// ==== FUN_005342c0 @ 0x005342c0 ====

void FUN_005342c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9284;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00534300 @ 0x00534300 ====

void FUN_00534300(undefined1 param_1,undefined4 param_2)

{
  int *in_ECX;
  
  *(undefined1 *)(in_ECX + 2) = param_1;
  (**(code **)(*in_ECX + 4))(param_2);
  return;
}


// ==== FUN_00534320 @ 0x00534320 ====

void FUN_00534320(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  if (*(int **)(in_ECX + 0x24) != (int *)0x0) {
    iVar1 = *DAT_00b5ac6c;
    uVar2 = (**(code **)(**(int **)(in_ECX + 0x24) + 4))();
    (**(code **)(iVar1 + 0x18))(uVar2);
  }
  if (*(undefined4 **)(in_ECX + 0x24) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x24))(1);
    *(undefined4 *)(in_ECX + 0x24) = 0;
  }
  uVar2 = DAT_0099d0dc;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  *(undefined4 *)(in_ECX + 0x10) = uVar2;
  return;
}


// ==== FUN_00534380 @ 0x00534380 ====

undefined4 FUN_00534380(undefined4 param_1)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(param_1);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  iVar3 = (**(code **)(*piVar2 + 4))();
  bVar1 = *(byte *)(iVar3 + 0x108);
  if (bVar1 == 0) {
    return 0;
  }
  if (*(char *)(in_ECX + 5) == '\0') {
    uVar6 = 3000;
    uVar5 = 1;
    uVar4 = 0x7000a;
    FUN_00511d10(0x7000a,1,3000);
    FUN_00512cd0();
    FUN_005127a0(uVar4,uVar5,uVar6);
    *(undefined1 *)(in_ECX + 5) = 1;
  }
  if ((bVar1 != 0) && (bVar1 < 4)) {
    return 1;
  }
  if ((bVar1 < 4) || (uVar4 = 2, 6 < bVar1)) {
    uVar4 = 3;
  }
  return uVar4;
}


// ==== FUN_00534440 @ 0x00534440 ====

char FUN_00534440(undefined4 param_1,char param_2)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(param_1);
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 4))();
    bVar1 = *(byte *)(iVar3 + 0x108);
    if (bVar1 != 0) {
      if ((bVar1 == 0) || (3 < bVar1)) {
        if ((bVar1 < 4) || (cVar4 = '\x02', 6 < bVar1)) {
          cVar4 = '\x03';
        }
      }
      else {
        cVar4 = '\x01';
      }
      if (param_2 != '\0') {
        cVar4 = cVar4 + '\n';
      }
      if (*(char *)(in_ECX + 6) == '\0') {
        uVar7 = 3000;
        uVar6 = 1;
        uVar5 = 0x7000a;
        FUN_00511d10(0x7000a,1,3000);
        FUN_00512cd0();
        FUN_005127a0(uVar5,uVar6,uVar7);
        *(undefined1 *)(in_ECX + 6) = 1;
      }
      return cVar4;
    }
  }
  return '\0';
}


// ==== FUN_005344d0 @ 0x005344d0 ====

void FUN_005344d0(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined2 *puVar4;
  
  puVar2 = *(undefined2 **)(in_ECX + 0x30);
  for (puVar4 = *(undefined2 **)(in_ECX + 0x2c); puVar4 != puVar2; puVar4 = puVar4 + 1) {
    uVar1 = *puVar4;
    uVar3 = (**(code **)(**(int **)(in_ECX + 0x24) + 4))();
    FUN_004dd240(0x1f,1,uVar1,0,uVar3);
  }
  return;
}


// ==== FUN_00534510 @ 0x00534510 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00534510(undefined4 param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  undefined1 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint local_24;
  int local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 auStack_14 [8];
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  local_24 = (uint)*(byte *)(in_ECX + 8);
  FUN_0079bba0(&local_20,&local_24);
  local_c = 0;
  local_8 = param_1;
  local_4 = param_2;
  if (param_2 == 3) {
    uVar3 = (*(undefined4 **)(local_20 + 0x10))[1];
  }
  else {
    uVar3 = **(undefined4 **)(local_20 + 0x10);
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar2 = (undefined4 *)(**(code **)(*piVar1 + 0x28))();
  uStack_1c = *puVar2;
  uStack_18 = puVar2[1];
  FUN_0040d600(auStack_14,*(float *)(in_ECX + 0x10) * _DAT_00aede90);
  uVar5 = 0;
  puVar4 = auStack_14;
  puVar2 = &uStack_1c;
  FUN_00511d20(puVar2,puVar4,0);
  FUN_005118f0(puVar2,puVar4,uVar5);
  uVar6 = 0;
  uVar5 = 0;
  puVar4 = auStack_14;
  puVar2 = &local_c;
  FUN_00511d20(puVar2,puVar4,uVar3,0,0);
  FUN_00511c00(puVar2,puVar4,uVar3,uVar5,uVar6);
  return;
}


// ==== FUN_005345f0 @ 0x005345f0 ====

void FUN_005345f0(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x1c) < 6) {
    FUN_00534510(1,2);
    return;
  }
  FUN_00534510(1,3);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  return;
}


// ==== FUN_00534620 @ 0x00534620 ====

void FUN_00534620(char param_1)

{
  int in_ECX;
  float fVar1;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    return;
  }
  if (param_1 == '\x01') {
    fVar1 = *(float *)(in_ECX + 0xc) + *(float *)(in_ECX + 0x10);
  }
  else {
    if (param_1 != '\x02') goto LAB_00534650;
    fVar1 = *(float *)(in_ECX + 0x10) - *(float *)(in_ECX + 0xc);
  }
  *(float *)(in_ECX + 0x10) = fVar1;
LAB_00534650:
  if (*(uint *)(in_ECX + 0x1c) < 6) {
    FUN_00534510(1,2);
    return;
  }
  FUN_00534510(1,3);
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  return;
}


// ==== FUN_00534680 @ 0x00534680 ====

undefined4 FUN_00534680(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  if (((*(char *)(in_ECX + 4) != '\0') && (*(int *)(in_ECX + 0x24) != 0)) && (param_1[3] == 0)) {
    iVar1 = (**(code **)(*param_1 + 0x10))();
    if (iVar1 == *(int *)(in_ECX + 0x14)) {
      *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
      FUN_005345f0();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005346c0 @ 0x005346c0 ====

/* WARNING: Removing unreachable block (ram,0x005347f4) */

void FUN_005346c0(int param_1,uint *param_2)

{
  char cVar1;
  short sVar2;
  undefined1 uVar3;
  char *pcVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint *puVar9;
  undefined4 *puVar10;
  void **ppvVar11;
  uint uVar12;
  uint uStack_84;
  undefined4 uStack_64;
  void *pvStack_60;
  undefined1 uStack_5c;
  undefined4 uStack_50;
  uint uStack_4c;
  undefined4 uStack_48;
  void *pvStack_44;
  undefined1 uStack_40;
  uint local_30 [8];
  undefined2 uStack_e;
  undefined2 uStack_c;
  undefined2 uStack_a;
  
  puVar8 = local_30;
  for (iVar6 = 0xb; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar8 = *param_2;
    param_2 = param_2 + 1;
    puVar8 = puVar8 + 1;
  }
  sVar2 = *(short *)((int)local_30 + param_1 * 2);
  uVar7 = CONCAT22((short)((uint)param_2 >> 0x10),sVar2);
  uStack_84 = uVar7;
  iVar6 = (**(code **)(*DAT_00b5ad20 + 0x14))();
  if (((iVar6 == 0x601) && (sVar2 != 0)) &&
     (uVar12 = uVar7, iVar6 = (**(code **)(*DAT_00b5a738 + 0x10))(uVar7), iVar6 != 0)) {
    (**(code **)(*DAT_00b5a6dc + 8))(CONCAT22(uStack_c,uStack_e),param_1,uVar7);
    local_30[1] = 0xf;
    local_30[0] = 0;
    uStack_40 = 0;
    FUN_00401740(s_weaponW_009b9244,7);
    uStack_48 = 0xf;
    uStack_84 = 9;
    uStack_4c = 0;
    uStack_5c = 0;
    pcVar4 = PTR_DAT_00aede8c;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_DAT_00aede8c,(int)pcVar4 - (int)(PTR_DAT_00aede8c + 1));
    uStack_64 = 0xf;
    FUN_00401740(s_WingArmor_009b924c,9);
    puVar8 = &uStack_84;
    ppvVar11 = &pvStack_44;
    uVar5 = (**(code **)(*DAT_00b5a7e4 + 4))(ppvVar11,puVar8,0);
    puVar10 = &uStack_64;
    puVar9 = local_30 + -0x14;
    FUN_00511d10(puVar9,puVar10,uVar5);
    FUN_00513030(puVar9,puVar10,uVar5,ppvVar11,puVar8);
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
    uStack_4c = 0xf;
    uStack_50 = 0;
    pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
    FUN_00401740(s_WingArmor_009b9258,9);
    puVar10 = &uStack_64;
    FUN_00511d10(puVar10);
    FUN_00512ca0(puVar10);
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
    uVar3 = FUN_00534440(uVar7,CONCAT22(uStack_a,uStack_c),1);
    FUN_00512a90(uVar12 + 0x78,uVar12 + 0x94,uVar3,0);
    if (0xf < local_30[0]) {
      _free(pvStack_44);
      return;
    }
  }
  return;
}


// ==== FUN_005348c0 @ 0x005348c0 ====

void FUN_005348c0(undefined4 param_1,uint param_2)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  int in_ECX;
  int iVar8;
  float10 fVar9;
  undefined1 auStack_20 [4];
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar3 = param_2;
  iVar6 = *(int *)(param_2 + 4);
  if (iVar6 != 0) {
    iVar8 = *(int *)(param_2 + 8) - iVar6;
    iVar2 = iVar8 >> 0x1f;
    iVar8 = iVar8 / 0x1c + iVar2;
    if (2 < (uint)(iVar8 - iVar2)) {
      if (iVar8 == iVar2) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      local_4 = 0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      FUN_00401660(iVar6,0,0xffffffff);
      iVar6 = *(int *)(iVar3 + 4);
      if ((iVar6 == 0) || ((uint)((*(int *)(iVar3 + 8) - iVar6) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      param_2 = thunk_FUN_00796f50(iVar6 + 0x1c);
      param_2 = param_2 & 0xff;
      piVar5 = (int *)FUN_0079bba0(auStack_20,&param_2);
      if (*piVar5 != *(int *)(in_ECX + 0x3c)) {
        pfVar1 = *(float **)(*piVar5 + 0x10);
        iVar6 = FUN_00403620(0,local_8,s_stand_009b9200,5);
        if (iVar6 == 0) {
          uVar7 = FUN_00405d30(2);
          fVar9 = (float10)thunk_FUN_00796ec0(uVar7);
          *pfVar1 = (float)fVar9;
        }
        else {
          cVar4 = FUN_004036a0(local_1c,s_stand_special_009b9208);
          if (cVar4 == '\0') {
            cVar4 = FUN_004036a0(local_1c,s_target_height_009b9218);
            if (cVar4 == '\0') {
              cVar4 = FUN_004036a0(local_1c,s_camera_far_009b9228);
              if (cVar4 == '\0') {
                cVar4 = FUN_004036a0(local_1c,s_camera_hight_009b9234);
                if (cVar4 != '\0') {
                  uVar7 = FUN_00405d30(2);
                  fVar9 = (float10)thunk_FUN_00796ec0(uVar7);
                  pfVar1[3] = (float)fVar9;
                }
              }
              else {
                uVar7 = FUN_00405d30(2);
                fVar9 = (float10)thunk_FUN_00796ec0(uVar7);
                pfVar1[4] = (float)fVar9;
              }
            }
            else {
              uVar7 = FUN_00405d30(2);
              fVar9 = (float10)thunk_FUN_00796ec0(uVar7);
              pfVar1[2] = (float)fVar9;
            }
          }
          else {
            uVar7 = FUN_00405d30(2);
            fVar9 = (float10)thunk_FUN_00796ec0(uVar7);
            pfVar1[1] = (float)fVar9;
          }
        }
      }
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
    }
  }
  return;
}


// ==== FUN_00534a80 @ 0x00534a80 ====

void FUN_00534a80(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_009b92a0;
  local_4 = in_ECX;
  if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[9])(1);
    in_ECX[9] = 0;
  }
  if (in_ECX[0x10] != 0) {
    local_4 = (undefined4 *)((uint)local_4 & 0xffffff00);
    FUN_005354c0(*(undefined4 *)in_ECX[0xf],(undefined4 *)in_ECX[0xf],local_4);
    FUN_00535480(*(undefined4 *)(in_ECX[0xf] + 4));
    *(undefined4 *)(in_ECX[0xf] + 4) = in_ECX[0xf];
    in_ECX[0x10] = 0;
    *(undefined4 *)in_ECX[0xf] = in_ECX[0xf];
    *(undefined4 *)(in_ECX[0xf] + 8) = in_ECX[0xf];
  }
  FUN_005357e0(&local_4,*(undefined4 *)in_ECX[0xf],(undefined4 *)in_ECX[0xf]);
  _free((void *)in_ECX[0xf]);
  return;
}


// ==== FUN_00534b30 @ 0x00534b30 ====

void FUN_00534b30(void)

{
  code *pcVar1;
  undefined4 uVar2;
  char cVar3;
  int *piVar4;
  byte *pbVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  uint uStack_64;
  undefined4 *puStack_60;
  undefined1 auStack_5c [4];
  void *pvStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_48;
  uint uStack_44;
  undefined1 auStack_40 [4];
  void *pvStack_3c;
  undefined4 uStack_2c;
  uint uStack_28;
  undefined1 auStack_24 [4];
  void *pvStack_20;
  undefined4 uStack_10;
  uint uStack_c;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5abac + 8))();
  while (piVar4 != (int *)0x0) {
    pbVar5 = (byte *)(**(code **)(*piVar4 + 4))();
    puStack_60 = operator_new(0x14);
    uVar2 = DAT_009b0120;
    uVar7 = DAT_0099d080;
    if (puStack_60 == (undefined4 *)0x0) {
      puStack_60 = (undefined4 *)0x0;
    }
    else {
      *puStack_60 = DAT_0099d080;
      puStack_60[2] = uVar7;
      puStack_60[3] = DAT_009a09bc;
      uVar7 = DAT_009b0ec8;
      puStack_60[1] = uVar2;
      puStack_60[4] = uVar7;
    }
    uStack_64 = (uint)*pbVar5;
    FUN_00535720(auStack_5c,&uStack_64);
    piVar4 = (int *)(**(code **)(*DAT_00b5abac + 0xc))();
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(s_Producer_char_previewinfo_txt_009b91cc,0x1d);
  iVar6 = FUN_00410500(auStack_40);
  if (0xf < uStack_28) {
    _free(pvStack_3c);
    return;
  }
  uStack_28 = 0xf;
  uStack_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  if (iVar6 == 0) {
    uStack_44 = 0xf;
    uStack_48 = 0;
    pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
    FUN_00401740(s_pScriptRes____NULL_009b91ec,0x12);
    FUN_00406880(auStack_5c);
    if (uStack_44 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_58);
    return;
  }
  *(undefined4 *)(*(int *)(iVar6 + 0x4c) + 4) = 0;
  cVar3 = FUN_0049d7c0();
  while( true ) {
    if (cVar3 != '\0') {
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar6);
      return;
    }
    puVar8 = auStack_5c;
    pvStack_58 = (void *)0x0;
    iStack_54 = 0;
    uStack_50 = 0;
    uVar7 = FUN_0049d800(auStack_24);
    FUN_00405670(uVar7,puVar8);
    if (0xf < uStack_c) break;
    uStack_c = 0xf;
    uStack_10 = 0;
    pvStack_20 = (void *)((uint)pvStack_20 & 0xffffff00);
    if ((pvStack_58 != (void *)0x0) &&
       (uStack_64 = (iStack_54 - (int)pvStack_58) / 0x1c, uStack_64 != 0)) {
      FUN_005348c0(iVar6,auStack_5c);
    }
    FUN_0049d780();
    if (pvStack_58 != (void *)0x0) {
      FUN_00405de0(pvStack_58,iStack_54,auStack_5c,uStack_64);
      _free(pvStack_58);
      return;
    }
    pvStack_58 = (void *)0x0;
    iStack_54 = 0;
    uStack_50 = 0;
    cVar3 = FUN_0049d7c0();
  }
  _free(pvStack_20);
  return;
}


// ==== FUN_00534d70 @ 0x00534d70 ====

void FUN_00534d70(undefined1 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b92a0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  iVar2 = FUN_005353e0();
  uVar1 = DAT_009b3420;
  in_ECX[0xf] = iVar2;
  *(undefined1 *)(iVar2 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0xf] + 4) = in_ECX[0xf];
  *(undefined4 *)in_ECX[0xf] = in_ECX[0xf];
  *(undefined4 *)(in_ECX[0xf] + 8) = in_ECX[0xf];
  in_ECX[0x10] = 0;
  in_ECX[3] = uVar1;
  uVar1 = DAT_0099d0dc;
  *(undefined1 *)(in_ECX + 2) = param_1;
  in_ECX[9] = 0;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  in_ECX[7] = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  *(undefined1 *)((int)in_ECX + 7) = 0;
  in_ECX[5] = 0x12;
  in_ECX[4] = uVar1;
  return;
}


// ==== FUN_00534df0 @ 0x00534df0 ====

void FUN_00534df0(int param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  bool bVar3;
  byte bVar4;
  byte bVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  undefined2 extraout_var;
  int in_ECX;
  undefined4 in_EDX;
  undefined4 uVar9;
  int unaff_EBX;
  undefined2 *puVar10;
  ulonglong uVar11;
  int iVar12;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined4 local_4c;
  undefined4 uStack_48;
  void *pvStack_40;
  undefined4 uStack_30;
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  int aiStack_8 [2];
  
  if (*(void **)(in_ECX + 0x2c) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x2c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  uVar9 = CONCAT22((short)((uint)in_EDX >> 0x10),*(undefined2 *)(in_ECX + 0x20));
  iVar6 = (**(code **)(*DAT_00b5a6dc + 8))
                    (CONCAT31((int3)((uint)uVar9 >> 8),*(undefined1 *)(param_1 + 0x2a)),0,uVar9);
  uStack_2c = 0xf;
  uStack_10 = 0xf;
  uVar7 = 2;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  uStack_4d = 0;
  uStack_50 = 0;
  uStack_4f = 0;
  uStack_4e = 0;
  uStack_48 = DAT_0099d080;
  local_4c = 0xffffffff;
  bVar5 = 2;
  bVar3 = false;
  iVar12 = 2;
  puVar10 = (undefined2 *)(param_1 + 4);
  do {
    bVar4 = (byte)uVar7;
    if ((bVar4 < 7) || (10 < bVar4)) {
      uVar11 = (ulonglong)uVar7;
      if ((*(ushort *)(iVar6 + 0x114) >> ((char)iVar12 - 2U & 0x1f) & 1) == 0) {
        iVar8 = (**(code **)(*DAT_00b5a6dc + 8))
                          (*(undefined1 *)(aiStack_8[0] + 0x2a),
                           CONCAT31((int3)(uVar7 >> 8),bVar4 - 2),*puVar10);
        FUN_00401660(iVar8 + 0x78,0,0xffffffff);
        FUN_00401660(iVar8 + 0x94,0,0xffffffff);
        uStack_4d = FUN_00534380(CONCAT22(extraout_var,*puVar10));
        FUN_004ff800(&uStack_50);
        puVar1 = (undefined2 *)(iVar8 + 0xb0);
        uVar11 = ZEXT48(puVar1);
        if (*(short *)(iVar8 + 0xb0) != 0) {
          iVar8 = *(int *)(in_ECX + 0x2c);
          if ((iVar8 == 0) ||
             ((uint)(*(int *)(in_ECX + 0x34) - iVar8 >> 1) <=
              (uint)(*(int *)(in_ECX + 0x30) - iVar8 >> 1))) {
            uVar11 = FUN_00427290(*(undefined4 *)(in_ECX + 0x30),1,puVar1);
          }
          else {
            puVar2 = *(undefined2 **)(in_ECX + 0x30);
            uVar11 = ZEXT48(puVar1);
            *puVar2 = *puVar1;
            *(undefined2 **)(in_ECX + 0x30) = puVar2 + 1;
          }
        }
      }
      else {
        bVar3 = true;
      }
    }
    else {
      uVar11 = (**(code **)(*DAT_00b5a6dc + 0x18))(0,*puVar10);
      iVar8 = (int)uVar11;
      if (iVar8 != 0) {
        FUN_005346c0(iVar12,aiStack_8[0],*(undefined4 *)(unaff_EBX + 0x24));
        uVar11 = (ulonglong)(iVar8 + 0xb0U);
        if (*(short *)(iVar8 + 0xb0) != 0) {
          uVar11 = FUN_004275a0(iVar8 + 0xb0U);
        }
      }
    }
    bVar5 = bVar5 + 1;
    uVar7 = CONCAT31((int3)(uVar11 >> 8),bVar5);
    iVar12 = iVar12 + 1;
    puVar10 = puVar10 + 1;
  } while (bVar5 < 0xb);
  if (bVar3) {
    iVar6 = (**(code **)(*DAT_00b5a6dc + 0x14))
                      (*(undefined1 *)(aiStack_8[0] + 0x2a),*(undefined2 *)(unaff_EBX + 0x20),
                       aiStack_8);
    FUN_00401660(iVar6,0,0xffffffff);
    FUN_00401660(iVar6 + 0x1c,0,0xffffffff);
    uStack_4d = 0;
    FUN_004ff800(&uStack_50);
  }
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  uStack_10 = 0xf;
  if (uStack_2c < 0x10) {
    return;
  }
  _free(pvStack_40);
  return;
}


// ==== FUN_00535080 @ 0x00535080 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00535080(uint param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 *puVar3;
  void *pvVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  int in_ECX;
  undefined4 *puVar8;
  ushort *puVar9;
  undefined1 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  undefined4 local_60;
  undefined4 local_5c;
  ushort local_58 [10];
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 auStack_38 [4];
  void *pvStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  undefined4 auStack_8 [2];
  
  *(uint *)(in_ECX + 0x20) = param_1;
  *(undefined1 *)(in_ECX + 4) = 1;
  if (*(char *)(in_ECX + 7) == '\0') {
    FUN_00534b30();
    *(undefined1 *)(in_ECX + 7) = 1;
  }
  param_1 = (uint)*(byte *)(in_ECX + 8);
  local_58[0] = (ushort)*(byte *)(in_ECX + 8);
  local_5c = 0;
  FUN_0079bba0(&local_60,&param_1);
  puVar8 = *(undefined4 **)(local_60 + 0x10);
  local_44 = puVar8[2];
  local_40 = puVar8[4];
  local_3c = puVar8[3];
  (**(code **)(*DAT_00b5af48 + 0xc))(local_44,local_40,local_3c);
  piVar2 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0x28))();
  local_60 = *puVar3;
  local_5c = puVar3[1];
  FUN_0040d600(local_58,*(float *)(in_ECX + 0x10) * _DAT_00aede90);
  if (*(undefined4 **)(in_ECX + 0x24) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x24))(1);
    *(undefined4 *)(in_ECX + 0x24) = 0;
  }
  pvVar4 = operator_new(0x40);
  if (pvVar4 == (void *)0x0) {
    uVar5 = 0;
  }
  else {
    uVar5 = FUN_005121e0();
  }
  *(undefined4 *)(in_ECX + 0x24) = uVar5;
  auStack_8[0] = 0;
  FUN_00512130(*(undefined4 *)(in_ECX + 0x14),&local_60,local_58,0,0x3f800000,local_58 + -8,
               auStack_8,1,1,1);
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  pcVar6 = PTR_DAT_00aede8c;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_DAT_00aede8c,(int)pcVar6 - (int)(PTR_DAT_00aede8c + 1));
  puVar9 = local_58 + -8;
  puVar10 = auStack_28;
  FUN_00511d10(puVar10,puVar9);
  FUN_00512e40(puVar10,puVar9);
  if (0xf < uStack_10) {
    _free(pvStack_24);
    return;
  }
  iVar7 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar7 + 0x18) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar7 + 0x18) + 0x18))();
  }
  uVar5 = (**(code **)(*piVar2 + 8))();
  pvStack_34 = (void *)0x0;
  uStack_30 = 0;
  uStack_2c = 0;
  FUN_00534df0(uVar5,auStack_38);
  FUN_00511ea0(0);
  puVar10 = auStack_38;
  FUN_00511d10(puVar10);
  FUN_00512cd0();
  FUN_00512a20(puVar10);
  uVar5 = 0;
  puVar9 = local_58;
  local_44 = 0;
  local_40 = 1;
  local_3c = 2;
  auStack_8[0] = *puVar8;
  puVar8 = &local_60;
  FUN_00511d20(puVar8,puVar9,0);
  FUN_005118f0(puVar8,puVar9,uVar5);
  uVar12 = 0;
  uVar11 = 0;
  puVar9 = local_58;
  puVar8 = &local_44;
  uVar5 = auStack_8[0];
  FUN_00511d20(puVar8,puVar9,auStack_8[0],0,0);
  FUN_00511c00(puVar8,puVar9,uVar5,uVar11,uVar12);
  FUN_005344d0();
  if (pvStack_34 == (void *)0x0) {
    return;
  }
  FUN_004ff020(pvStack_34,uStack_30,auStack_38,auStack_8[0]);
  _free(pvStack_34);
  return;
}


// ==== FUN_00535310 @ 0x00535310 ====

void FUN_00535310(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[1] = param_2;
  in_ECX[3] = *param_4;
  in_ECX[4] = param_4[1];
  *(undefined1 *)(in_ECX + 5) = param_5;
  *(undefined1 *)((int)in_ECX + 0x15) = 0;
  return;
}


// ==== __break @ 0x00535345 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00535350 @ 0x00535350 ====

void * FUN_00535350(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981910;
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


// ==== Catch@005353c5 @ 0x005353c5 ====

void Catch_005353c5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005353e0 @ 0x005353e0 ====

void FUN_005353e0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981920;
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


// ==== Catch@0053546a @ 0x0053546a ====

void Catch_0053546a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_00535480 @ 0x00535480 ====

void FUN_00535480(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_00535480(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_005354c0 @ 0x005354c0 ====

uint FUN_005354c0(int *param_1,int *param_2,byte param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  uint extraout_EAX;
  
  while( true ) {
    if (param_1 == param_2) {
      return (uint)param_3;
    }
    if ((void *)param_1[4] != (void *)0x0) break;
    if (*(char *)((int)param_1 + 0x15) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x15) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x15);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x15);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x15);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x15);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  _free((void *)param_1[4]);
  return extraout_EAX;
}


// ==== FUN_00535540 @ 0x00535540 ====

void FUN_00535540(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_00535350(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00535645:
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
      if ((char)piVar6[5] == '\0') goto LAB_00535645;
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


// ==== FUN_00535720 @ 0x00535720 ====

void FUN_00535720(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_00535540(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_00535540(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_005357e0 @ 0x005357e0 ====

void FUN_005357e0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00535480(piVar6[1]);
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


// ==== FUN_005358a0 @ 0x005358a0 ====

void FUN_005358a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00534a80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005358c0 @ 0x005358c0 ====

void FUN_005358c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b92d0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005358f0 @ 0x005358f0 ====

void FUN_005358f0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00535920 @ 0x00535920 ====

void FUN_00535920(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 8) = param_1 + 1000;
  FUN_00532780(param_1);
  return;
}


// ==== FUN_00535940 @ 0x00535940 ====

void FUN_00535940(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  return;
}


// ==== FUN_00535970 @ 0x00535970 ====

void FUN_00535970(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0x10) = param_1 + 1000;
  FUN_00532810();
  return;
}


// ==== FUN_00535990 @ 0x00535990 ====

void FUN_00535990(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b92f8;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_005359b0 @ 0x005359b0 ====

void FUN_005359b0(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  if (cVar1 != '\0') {
    iVar2 = (**(code **)(*DAT_00b5ad04 + 0x18))(param_1);
    if (iVar2 == 0) {
      (**(code **)(*in_ECX + 4))();
      return;
    }
    iVar3 = 0;
    if (*(char *)(iVar2 + 0xc) == '\x01') {
      iVar3 = *(int *)(iVar2 + 8) + 30000;
    }
    *(char *)(in_ECX + 1) = *(char *)(iVar2 + 0xc);
    in_ECX[2] = iVar3;
  }
  return;
}


// ==== FUN_00535a00 @ 0x00535a00 ====

bool FUN_00535a00(uint param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  if ((cVar1 == '\0') || (*(char *)(in_ECX + 4) == '\0')) {
    return false;
  }
  return *(uint *)(in_ECX + 8) <= param_1;
}


// ==== FUN_00535a30 @ 0x00535a30 ====

bool FUN_00535a30(undefined4 param_1,uint param_2)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  if (((cVar1 != '\0') && ((char)in_ECX[3] != '\0')) && ((uint)in_ECX[4] <= param_2)) {
    iVar2 = (**(code **)(*DAT_00b5ad04 + 0x18))(param_1);
    if (iVar2 != 0) {
      return *(short *)(iVar2 + 0x14) == 0;
    }
    (**(code **)(*in_ECX + 0xc))();
  }
  return false;
}


// ==== FUN_00535a80 @ 0x00535a80 ====

void FUN_00535a80(undefined4 param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  if (cVar1 != '\0') {
    iVar2 = (**(code **)(*DAT_00b5ad04 + 0x18))(param_1);
    if (iVar2 == 0) {
      (**(code **)(*in_ECX + 0xc))();
      return;
    }
    *(bool *)(in_ECX + 3) = *(short *)(iVar2 + 0x14) != 0;
    iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    in_ECX[4] = iVar2;
  }
  return;
}


// ==== FUN_00535ae0 @ 0x00535ae0 ====

bool FUN_00535ae0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (iVar2 == 0) {
      piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
      piVar1 = (int *)(**(code **)(*piVar1 + 0x24))();
      uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      iVar2 = (**(code **)(*piVar1 + 0x1c))(uVar3);
      return *(int *)(iVar2 + 0x48) == 3;
    }
  }
  return false;
}


// ==== FUN_00535b40 @ 0x00535b40 ====

void FUN_00535b40(undefined4 param_1)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 unaff_retaddr;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
  if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0xc))(), iVar3 == 0)) {
    piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
    piVar2 = (int *)(**(code **)(*piVar2 + 0x24))();
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    iVar3 = (**(code **)(*piVar2 + 0x1c))(uVar4);
    uVar4 = CONCAT22((short)((uint)iVar3 >> 0x10),*(short *)(iVar3 + 0x1a));
    if (*(short *)(iVar3 + 0x1a) != 0) {
      iVar5 = (**(code **)(*DAT_00b5a6dc + 8))
                        (CONCAT31((int3)((uint)uVar4 >> 8),*(undefined1 *)(iVar3 + 0x44)),0,uVar4);
      sVar1 = *(short *)(iVar5 + 0x11a);
      uVar4 = CONCAT22((short)((uint)iVar5 >> 0x10),sVar1);
      if (sVar1 != 0) {
        uVar4 = FUN_004dd240(0x26,1,sVar1,0,unaff_retaddr);
      }
    }
    uVar4 = CONCAT22((short)((uint)uVar4 >> 0x10),*(short *)(iVar3 + 0x1c));
    if (*(short *)(iVar3 + 0x1c) != 0) {
      iVar3 = (**(code **)(*DAT_00b5a6dc + 8))
                        (CONCAT31((int3)((uint)uVar4 >> 8),*(undefined1 *)(iVar3 + 0x44)),1,uVar4);
      if (*(short *)(iVar3 + 0x11a) != 0) {
        FUN_004dd240(0x26,1,*(short *)(iVar3 + 0x11a),0,unaff_retaddr);
      }
    }
  }
  return;
}


// ==== FUN_00535c10 @ 0x00535c10 ====

void FUN_00535c10(uint param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  char cVar7;
  uint uVar8;
  undefined4 uVar9;
  int *piVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined4 uVar13;
  uint *puVar14;
  uint uVar15;
  float10 fVar16;
  undefined2 uStack_50;
  ushort uStack_4e;
  undefined2 uStack_4c;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  float fStack_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_30 = *(uint *)(param_1 + 0x32);
  local_2c = *(uint *)(param_1 + 0x36);
  local_28 = *(undefined4 *)(param_1 + 0x3a);
  local_24 = *(undefined4 *)(param_1 + 0x3e);
  local_20 = *(undefined4 *)(param_1 + 0x42);
  uVar8 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uVar13 = *(undefined4 *)(param_1 + 0x20);
  uVar2 = *(undefined4 *)(param_1 + 0x24);
  iVar3 = *(int *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0x14);
  uStack_40 = *(undefined4 *)(param_1 + 0x10);
  iVar5 = *(int *)(param_1 + 0x1c);
  uVar6 = *(undefined4 *)(param_1 + 0x28);
  uVar1 = *(undefined1 *)(param_1 + 0x30);
  uStack_44 = CONCAT31(uStack_44._1_3_,*(undefined1 *)(param_1 + 0x31));
  uVar9 = (**(code **)(*DAT_00b5a97c + 0xc))();
  uStack_50 = (undefined2)uVar9;
  uStack_4e = (ushort)((uint)uVar9 >> 0x10);
  if (local_30 < uVar8) {
    piVar10 = (int *)(**(code **)(*DAT_00b5af4c + 4))(7);
    (**(code **)(*piVar10 + 0x1c))(&fStack_34,uVar8);
    uVar15 = uVar8;
  }
  else {
    uVar15 = uVar8 + 300;
    if (local_30 < uVar8 + 300) {
      uVar15 = local_30;
    }
  }
  FUN_0053a9e0(uVar15,iVar3);
  FUN_0053a990(&local_30,iVar3);
  cVar7 = FUN_00535ae0(iVar3);
  if (cVar7 == '\0') {
    puVar11 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar11 == (undefined4 *)0x0) {
      puVar11 = (undefined4 *)0x0;
    }
    else {
      *puVar11 = &PTR_FUN_009b9370;
    }
    puVar11[1] = iVar3;
    *(undefined1 *)(puVar11 + 2) = uVar1;
    *(undefined1 *)((int)puVar11 + 9) = 0;
    puVar11[3] = iVar5;
    FUN_0051b660(uVar15,puVar11);
  }
  uStack_1c = local_30;
  uStack_14 = local_28;
  uStack_18 = local_2c;
  uStack_10 = local_24;
  uStack_c = local_20;
  if (iVar3 == CONCAT22(uStack_4e,uStack_50)) {
    if (0 < iVar5) {
      FUN_0053aa30(uVar13,uVar2,uVar6,0xffffffff);
    }
    uStack_4e = local_2c._2_2_ >> 7;
    param_1 = CONCAT22(param_1._2_2_,(short)(local_2c >> 7)) & 0xffff01ff;
    cVar7 = FUN_0053b180(param_1,CONCAT22(uStack_4c,uStack_4e));
    if (cVar7 != '\0') {
      piVar10 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      puVar11 = (undefined4 *)(**(code **)(*piVar10 + 0x28))();
      uStack_3c = *puVar11;
      piVar10 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      iVar12 = (**(code **)(*piVar10 + 0x28))();
      uStack_38 = *(undefined4 *)(iVar12 + 4);
      piVar10 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      uVar13 = (**(code **)(*piVar10 + 0x2c))();
      fVar16 = (float10)FUN_0040d5f0(uVar13);
      fStack_34 = (float)fVar16;
      puVar14 = (uint *)FUN_004ef0e0(&uStack_50);
      uStack_18 = *puVar14;
      uStack_14 = CONCAT22(uStack_14._2_2_,(short)puVar14[1]);
    }
    cVar7 = (**(code **)(*DAT_00b5aee4 + 0x18))();
    if (cVar7 != '\0') {
      (**(code **)(*DAT_00b5aee4 + 0x20))(2);
    }
    iVar12 = *DAT_00b5ad1c;
    uVar13 = FUN_004244f0();
    (**(code **)(iVar12 + 0x8c))(uVar6,uVar13);
  }
  else if (0 < iVar5) {
    FUN_0053aad0(iVar3,uVar13,uVar2);
    iVar12 = (**(code **)(*DAT_00b5ac24 + 8))();
    if (((iVar4 == CONCAT22(uStack_4e,uStack_50)) && (*(char *)(iVar12 + 2) == '\x01')) ||
       (*(char *)(iVar12 + 2) == '\x02')) {
      FUN_0053a860(uVar15,iVar3,iVar4,iVar5);
    }
  }
  FUN_0053b410(iVar3,&uStack_1c);
  FUN_0053b0f0(iVar3,uStack_40,uStack_44);
  FUN_00535b40(iVar4,iVar3);
  FUN_0053b220(7,local_30,local_20,iVar4,iVar3,iVar5);
  return;
}


// ==== FUN_00535f20 @ 0x00535f20 ====

void FUN_00535f20(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  char cVar11;
  char cVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  undefined4 *puVar16;
  int iVar17;
  uint uStack_3c;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  iVar13 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uStack_3c = *(uint *)(param_1 + 0x21);
  if (iVar13 + 300U <= *(uint *)(param_1 + 0x21)) {
    uStack_3c = iVar13 + 300U;
  }
  iVar13 = *(int *)(param_1 + 0x14);
  iVar6 = *(int *)(param_1 + 0x10);
  uVar7 = *(undefined4 *)(param_1 + 0x1c);
  iVar8 = *(int *)(param_1 + 0x18);
  cVar12 = *(char *)(param_1 + 0x33);
  uVar1 = *(undefined1 *)(param_1 + 0x29);
  uVar2 = *(undefined1 *)(param_1 + 0x2b);
  uVar3 = *(undefined1 *)(param_1 + 0x20);
  iVar14 = (**(code **)(*DAT_00b5a97c + 0xc))();
  iVar15 = (**(code **)(*DAT_00b5af10 + 0xc))();
  cVar11 = (**(code **)(*DAT_00b5ac1c + 0x18))();
  if ((cVar11 == '\0') && (((cVar12 == '\x03' || (cVar12 == '\x04')) || (cVar12 == '\x05')))) {
    cVar12 = '\x02';
  }
  FUN_0053a9e0(uStack_3c,iVar8);
  FUN_0053a990((undefined4 *)(param_1 + 0x21),iVar8);
  cVar11 = FUN_00535ae0(iVar8);
  if (cVar11 == '\0') {
    puVar16 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar16 == (undefined4 *)0x0) {
      puVar16 = (undefined4 *)0x0;
    }
    else {
      *puVar16 = &PTR_FUN_009b93a0;
    }
    uVar4 = *(undefined1 *)(param_1 + 0x31);
    uVar5 = *(undefined1 *)(param_1 + 0x32);
    uVar9 = *(undefined4 *)(param_1 + 0x21);
    uVar10 = *(undefined4 *)(param_1 + 0x1c);
    *(undefined1 *)(puVar16 + 2) = uVar1;
    *(undefined1 *)(puVar16 + 4) = uVar2;
    *(undefined1 *)((int)puVar16 + 0x11) = uVar3;
    puVar16[5] = uVar10;
    puVar16[1] = iVar8;
    puVar16[3] = uVar9;
    *(undefined1 *)(puVar16 + 6) = uVar4;
    *(undefined1 *)((int)puVar16 + 0x19) = uVar5;
    *(char *)((int)puVar16 + 0x1a) = cVar12;
    FUN_0051b660(uStack_3c,puVar16);
  }
  uStack_1c = *(undefined4 *)(param_1 + 0x21);
  uStack_18 = *(undefined4 *)(param_1 + 0x25);
  uStack_14 = *(undefined4 *)(param_1 + 0x29);
  uStack_10 = *(undefined4 *)(param_1 + 0x2d);
  uStack_c = *(undefined4 *)(param_1 + 0x31);
  if (iVar8 == iVar14) {
    FUN_0053b090(uStack_1c);
    FUN_0053aa30(0,0,0,0xffffffff);
    FUN_0053ab70(3,iVar13,iVar8);
    FUN_0053abf0(*(undefined1 *)(param_1 + 0x34));
    cVar12 = (**(code **)(*DAT_00b5aee4 + 0x18))();
    if (cVar12 == '\0') {
      (**(code **)(*DAT_00b5aee4 + 8))();
    }
    else {
      (**(code **)(*DAT_00b5aee4 + 0x20))(2);
    }
    (**(code **)(*DAT_00b5ae84 + 0x20))();
    (**(code **)(*DAT_00b5a97c + 0x1c))();
    (**(code **)(*DAT_00b5ad88 + 0x18))();
  }
  FUN_0053b410(iVar8,&uStack_1c);
  if (iVar8 != iVar14) {
    FUN_0053aad0(iVar8,0,0);
    iVar17 = (**(code **)(*DAT_00b5ac24 + 8))();
    if (((iVar6 == iVar14) && (*(char *)(iVar17 + 2) == '\x01')) ||
       (*(char *)(iVar17 + 2) == '\x02')) {
      FUN_0053a860(uStack_3c,iVar8,iVar6,uVar7);
    }
    (**(code **)(*DAT_00b5ae84 + 0x24))(iVar8);
    if ((iVar13 == iVar14) || (iVar13 == iVar15)) {
      FUN_0053ab70(4,iVar13,iVar8);
    }
  }
  FUN_00535b40(iVar13,iVar8);
  FUN_0053b370(iVar8,*(undefined4 *)(param_1 + 0x21));
  return;
}


// ==== FUN_005361c0 @ 0x005361c0 ====

void FUN_005361c0(uint param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  
  iVar2 = param_1;
  iVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  param_1 = FUN_004244f0();
  if (iVar4 + 300U <= param_1) {
    param_1 = iVar4 + 300U;
  }
  uVar9 = *(undefined4 *)(iVar2 + 0x18);
  uVar8 = *(undefined4 *)(iVar2 + 0x14);
  cVar3 = FUN_00535ae0(uVar9);
  if (cVar3 == '\0') {
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_009b93b8;
    }
    puVar5[1] = uVar9;
    FUN_0051b660(param_1,puVar5);
  }
  FUN_00535b40(uVar8,uVar9);
  piVar1 = DAT_00b5a6ac;
  uVar10 = 0;
  uVar6 = (**(code **)(*DAT_00b5a6ac + 0x20))(uVar8,uVar9,0);
  uVar7 = (**(code **)(*piVar1 + 0x20))(uVar6);
  FUN_0053b220(3,uVar7,uVar6,uVar8,uVar9,uVar10);
  return;
}


// ==== FUN_00536270 @ 0x00536270 ====

void FUN_00536270(uint param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  
  iVar9 = param_1;
  iVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  param_1 = FUN_004244f0();
  if (iVar3 + 300U <= param_1) {
    param_1 = iVar3 + 300U;
  }
  uVar6 = *(undefined4 *)(iVar9 + 0x24);
  uVar7 = *(undefined4 *)(iVar9 + 0x28);
  uVar1 = *(undefined4 *)(iVar9 + 0x30);
  iVar3 = *(int *)(iVar9 + 0x18);
  uVar8 = *(undefined4 *)(iVar9 + 0x14);
  iVar9 = *(int *)(iVar9 + 0x1c);
  iVar4 = (**(code **)(*DAT_00b5a97c + 0xc))();
  cVar2 = FUN_00535ae0(iVar3);
  if (cVar2 == '\0') {
    puVar5 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar5 == (undefined4 *)0x0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      *puVar5 = &PTR_FUN_009b9370;
    }
    *(undefined1 *)(puVar5 + 2) = 3;
    *(undefined1 *)((int)puVar5 + 9) = 3;
    puVar5[1] = iVar3;
    puVar5[3] = iVar9;
    FUN_0051b660(param_1,puVar5);
  }
  if (iVar3 == iVar4) {
    FUN_0053aa30(uVar6,uVar7,uVar1,0xffffffff);
    cVar2 = (**(code **)(*DAT_00b5aee4 + 0x18))();
    if (cVar2 != '\0') {
      (**(code **)(*DAT_00b5aee4 + 0x20))(2);
    }
    iVar4 = *DAT_00b5ad1c;
    uVar6 = FUN_004244f0();
    (**(code **)(iVar4 + 0x8c))(uVar1,uVar6);
  }
  else if (0 < iVar9) {
    FUN_0053aad0(iVar3,uVar6,uVar7);
  }
  FUN_00535b40(uVar8,iVar3);
  uVar7 = 0;
  uVar6 = (**(code **)(*DAT_00b5a6ac + 0x20))(0,uVar8,iVar3,iVar9);
  FUN_0053b220(6,uVar6,uVar7,uVar8,iVar3,iVar9);
  return;
}


// ==== FUN_005363e0 @ 0x005363e0 ====

void FUN_005363e0(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = FUN_00535ae0(param_1);
  if ((cVar1 == '\0') && (cVar1 = FUN_00535ae0(param_2), cVar1 == '\0')) {
    iVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
    iVar3 = (**(code **)(*DAT_00b5af10 + 0xc))();
    if ((param_2 == iVar2) || (param_2 == iVar3)) {
      FUN_0053ab70(0,param_1,param_2);
    }
    else if ((param_1 == iVar2) || (param_1 == iVar3)) {
      FUN_0053ab70(1,param_1,param_2);
      return;
    }
  }
  return;
}


// ==== FUN_00536460 @ 0x00536460 ====

void FUN_00536460(uint param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  char cVar8;
  uint uVar9;
  undefined4 uVar10;
  int *piVar11;
  undefined4 *puVar12;
  int iVar13;
  undefined4 uVar14;
  uint *puVar15;
  int iVar16;
  uint uVar17;
  float10 fVar18;
  undefined2 uStack_50;
  ushort uStack_4e;
  undefined2 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  float fStack_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined1 local_20;
  uint uStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  
  local_34 = *(uint *)(param_1 + 0x2f);
  local_30 = *(uint *)(param_1 + 0x33);
  local_2c = *(undefined4 *)(param_1 + 0x37);
  local_28 = *(undefined4 *)(param_1 + 0x3b);
  local_24 = *(undefined4 *)(param_1 + 0x3f);
  local_20 = *(undefined1 *)(param_1 + 0x43);
  uVar9 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar3 = *(int *)(param_1 + 0x14);
  uStack_44 = *(undefined4 *)(param_1 + 0x10);
  iVar4 = *(int *)(param_1 + 0x18);
  uVar14 = *(undefined4 *)(param_1 + 0x24);
  uVar5 = *(undefined4 *)(param_1 + 0x28);
  uVar6 = *(undefined4 *)(param_1 + 0x20);
  uVar1 = *(undefined1 *)(param_1 + 0x2d);
  uVar2 = *(undefined1 *)(param_1 + 0x2c);
  iVar7 = *(int *)(param_1 + 0x1c);
  uStack_48 = CONCAT31(uStack_48._1_3_,*(undefined1 *)(param_1 + 0x2e));
  uVar10 = (**(code **)(*DAT_00b5a97c + 0xc))();
  uStack_50 = (undefined2)uVar10;
  uStack_4e = (ushort)((uint)uVar10 >> 0x10);
  if (local_34 < uVar9) {
    piVar11 = (int *)(**(code **)(*DAT_00b5af4c + 4))(7);
    (**(code **)(*piVar11 + 0x1c))(&fStack_38,uVar9);
    uVar17 = uVar9;
  }
  else {
    uVar17 = uVar9 + 300;
    if (local_34 < uVar9 + 300) {
      uVar17 = local_34;
    }
  }
  FUN_0053a9e0(uVar17,*(undefined4 *)(param_1 + 0x18));
  FUN_0053a990(&local_34,*(undefined4 *)(param_1 + 0x18));
  FUN_005363e0(iVar3,iVar4);
  cVar8 = FUN_00535ae0(iVar4);
  if (cVar8 == '\0') {
    puVar12 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar12 == (undefined4 *)0x0) {
      puVar12 = (undefined4 *)0x0;
    }
    else {
      *puVar12 = &PTR_FUN_009b9370;
    }
    *(undefined1 *)(puVar12 + 2) = uVar2;
    puVar12[1] = iVar4;
    *(undefined1 *)((int)puVar12 + 9) = uVar1;
    puVar12[3] = iVar7;
    FUN_0051b660(uVar17,puVar12);
  }
  iVar13 = CONCAT22(uStack_4e,uStack_50);
  uStack_1c = local_34;
  uStack_18 = local_30;
  uStack_14 = local_2c;
  uStack_10 = local_28;
  uStack_c = local_24;
  uStack_8 = local_20;
  if (iVar4 == iVar13) {
    if (0 < iVar7) {
      FUN_0053aa30(uVar6,uVar14,uVar5,0xffffffff);
    }
    uStack_4e = local_30._2_2_ >> 7;
    param_1 = local_30 >> 7 & 0x1ff;
    cVar8 = FUN_0053b180(param_1,CONCAT22(uStack_4c,uStack_4e));
    if (cVar8 != '\0') {
      piVar11 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      puVar12 = (undefined4 *)(**(code **)(*piVar11 + 0x28))();
      uStack_40 = *puVar12;
      piVar11 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      iVar13 = (**(code **)(*piVar11 + 0x28))();
      uStack_3c = *(undefined4 *)(iVar13 + 4);
      piVar11 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      uVar14 = (**(code **)(*piVar11 + 0x2c))();
      fVar18 = (float10)FUN_0040d5f0(uVar14);
      fStack_38 = (float)fVar18;
      puVar15 = (uint *)FUN_004ef0e0(&uStack_50);
      uStack_18 = *puVar15;
      uStack_14 = CONCAT22(uStack_14._2_2_,(short)puVar15[1]);
    }
    FUN_0053b090(uStack_1c);
    cVar8 = (**(code **)(*DAT_00b5aee4 + 0x18))();
    if (cVar8 != '\0') {
      (**(code **)(*DAT_00b5aee4 + 0x20))(2);
    }
    iVar13 = *DAT_00b5ad1c;
    uVar14 = FUN_004244f0();
    (**(code **)(iVar13 + 0x8c))(uVar5,uVar14);
  }
  else if (0 < iVar7) {
    FUN_0053aad0(iVar4,uVar6,uVar14);
    iVar16 = (**(code **)(*DAT_00b5ac24 + 8))();
    if (((iVar3 == iVar13) && (*(char *)(iVar16 + 2) == '\x01')) ||
       (*(char *)(iVar16 + 2) == '\x02')) {
      FUN_0053a860(uVar17,iVar4,iVar3,iVar7);
    }
  }
  FUN_0053b410(iVar4,&uStack_1c);
  FUN_0053b0f0(iVar4,uStack_44,uStack_48);
  FUN_0053b220(0,local_34,CONCAT13(local_20,local_24._1_3_),iVar3,iVar4,iVar7);
  return;
}


// ==== FUN_005367a0 @ 0x005367a0 ====

void FUN_005367a0(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  char cVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  undefined4 uVar14;
  uint uStack_40;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_c;
  undefined1 uStack_a;
  
  iVar11 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uStack_40 = *(uint *)(param_1 + 0x2e);
  if (iVar11 + 300U <= *(uint *)(param_1 + 0x2e)) {
    uStack_40 = iVar11 + 300U;
  }
  uVar3 = *(undefined4 *)(param_1 + 0x10);
  uVar4 = *(undefined4 *)(param_1 + 0x20);
  uVar5 = *(undefined4 *)(param_1 + 0x24);
  iVar11 = *(int *)(param_1 + 0x18);
  uVar6 = *(undefined4 *)(param_1 + 0x14);
  uVar7 = *(undefined4 *)(param_1 + 0x28);
  uVar1 = *(undefined1 *)(param_1 + 0x2d);
  iVar8 = *(int *)(param_1 + 0x1c);
  uVar2 = *(undefined1 *)(param_1 + 0x2c);
  iVar12 = (**(code **)(*DAT_00b5a97c + 0xc))();
  FUN_0053a9e0(uStack_40,iVar11);
  FUN_0053a990(param_1 + 0x2e,iVar11);
  FUN_005363e0(uVar6,iVar11);
  cVar10 = FUN_00535ae0(iVar11);
  if (cVar10 == '\0') {
    puVar13 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar13 == (undefined4 *)0x0) {
      puVar13 = (undefined4 *)0x0;
    }
    else {
      *puVar13 = &PTR_FUN_009b9388;
    }
    puVar13[1] = iVar11;
    *(undefined1 *)(puVar13 + 2) = uVar2;
    puVar13[3] = iVar8;
    FUN_0051b660(uStack_40,puVar13);
  }
  uStack_1c = *(undefined4 *)(param_1 + 0x2e);
  uStack_18 = *(undefined4 *)(param_1 + 0x32);
  uStack_14 = *(undefined4 *)(param_1 + 0x36);
  uStack_10 = *(undefined4 *)(param_1 + 0x3a);
  uStack_c = *(undefined2 *)(param_1 + 0x3e);
  uStack_a = *(undefined1 *)(param_1 + 0x40);
  if (iVar11 == iVar12) {
    FUN_0053b090(uStack_1c);
    FUN_0053aa30(uVar4,uVar5,uVar7,0xffffffff);
    cVar10 = (**(code **)(*DAT_00b5aee4 + 0x18))();
    if (cVar10 != '\0') {
      (**(code **)(*DAT_00b5aee4 + 0x20))(2);
    }
    iVar9 = *DAT_00b5ad1c;
    uVar14 = FUN_004244f0();
    (**(code **)(iVar9 + 0x8c))(uVar7,uVar14);
  }
  FUN_0053b410(iVar11,&uStack_1c);
  if ((iVar11 != iVar12) && (0 < iVar8)) {
    FUN_0053aad0(iVar11,uVar4,uVar5);
  }
  FUN_0053b0f0(iVar11,uVar3,uVar1);
  FUN_00535b40(uVar6,iVar11);
  FUN_0053b220(4,*(undefined4 *)(param_1 + 0x2e),*(undefined4 *)(param_1 + 0x3d),uVar6,iVar11,0);
  return;
}


// ==== FUN_005369a0 @ 0x005369a0 ====

void FUN_005369a0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uStack_28;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_c;
  undefined1 uStack_a;
  
  iVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uStack_28 = *(uint *)(param_1 + 0x1d);
  if (iVar4 + 300U <= *(uint *)(param_1 + 0x1d)) {
    uStack_28 = iVar4 + 300U;
  }
  uVar1 = *(undefined1 *)(param_1 + 0x1c);
  iVar4 = *(int *)(param_1 + 0x18);
  iVar2 = *(int *)(param_1 + 0x14);
  iVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
  FUN_0053a9e0(uStack_28,iVar4);
  FUN_0053a990(param_1 + 0x1d,iVar4);
  FUN_005363e0(iVar2,iVar4);
  cVar3 = FUN_00535ae0(iVar4);
  if (cVar3 == '\0') {
    puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      *puVar6 = &PTR_FUN_009b9358;
    }
    puVar6[1] = iVar4;
    *(undefined1 *)(puVar6 + 2) = uVar1;
    FUN_0051b660(uStack_28,puVar6);
  }
  uStack_1c = *(undefined4 *)(param_1 + 0x1d);
  uStack_18 = *(undefined4 *)(param_1 + 0x21);
  uStack_14 = *(undefined4 *)(param_1 + 0x25);
  uStack_10 = *(undefined4 *)(param_1 + 0x29);
  uStack_c = *(undefined2 *)(param_1 + 0x2d);
  uStack_a = *(undefined1 *)(param_1 + 0x2f);
  if ((iVar4 == iVar5) || (iVar2 == iVar5)) {
    cVar3 = (**(code **)(*DAT_00b5aee4 + 0x18))();
    if (cVar3 != '\0') {
      (**(code **)(*DAT_00b5aee4 + 0x20))(2);
    }
    FUN_0053b090(uStack_1c);
  }
  FUN_0053b410(iVar4,&uStack_1c);
  FUN_0053a990((undefined4 *)(param_1 + 0x30),iVar2);
  uStack_1c = *(undefined4 *)(param_1 + 0x30);
  uStack_14 = *(undefined4 *)(param_1 + 0x38);
  uStack_18 = *(undefined4 *)(param_1 + 0x34);
  uStack_10 = *(undefined4 *)(param_1 + 0x3c);
  uStack_a = *(undefined1 *)(param_1 + 0x42);
  uStack_c = *(undefined2 *)(param_1 + 0x40);
  FUN_0053b410(iVar2,&uStack_1c);
  iVar7 = (**(code **)(*DAT_00b5ac24 + 8))();
  if (((iVar2 == iVar5) && (*(char *)(iVar7 + 2) == '\x01')) || (*(char *)(iVar7 + 2) == '\x02')) {
    FUN_0053a860(uStack_28,iVar4,iVar2,0);
  }
  FUN_00535b40(iVar2,iVar4);
  FUN_0053b220(2,*(undefined4 *)(param_1 + 0x1d),*(undefined4 *)(param_1 + 0x2c),iVar2,iVar4,0);
  return;
}


// ==== FUN_00536b80 @ 0x00536b80 ====

void FUN_00536b80(int param_1)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uStack_28;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_c;
  undefined1 uStack_a;
  
  iVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  puVar1 = (undefined4 *)(param_1 + 0x1d);
  uStack_28 = *(uint *)(param_1 + 0x1d);
  if (iVar5 + 300U <= *(uint *)(param_1 + 0x1d)) {
    uStack_28 = iVar5 + 300U;
  }
  uVar2 = *(undefined1 *)(param_1 + 0x1c);
  iVar5 = *(int *)(param_1 + 0x18);
  uVar3 = *(undefined4 *)(param_1 + 0x14);
  iVar6 = (**(code **)(*DAT_00b5a97c + 0xc))();
  FUN_0053a9e0(uStack_28,iVar5);
  FUN_0053a990(puVar1,iVar5);
  FUN_005363e0(uVar3,iVar5);
  cVar4 = FUN_00535ae0(iVar5);
  if (cVar4 == '\0') {
    puVar7 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar7 == (undefined4 *)0x0) {
      puVar7 = (undefined4 *)0x0;
    }
    else {
      *puVar7 = &PTR_FUN_009b9358;
    }
    puVar7[1] = iVar5;
    *(undefined1 *)(puVar7 + 2) = uVar2;
    FUN_0051b660(uStack_28,puVar7);
  }
  uStack_1c = *puVar1;
  uStack_18 = *(undefined4 *)(param_1 + 0x21);
  uStack_14 = *(undefined4 *)(param_1 + 0x25);
  uStack_10 = *(undefined4 *)(param_1 + 0x29);
  uStack_c = *(undefined2 *)(param_1 + 0x2d);
  uStack_a = *(undefined1 *)(param_1 + 0x2f);
  if (iVar5 == iVar6) {
    cVar4 = (**(code **)(*DAT_00b5aee4 + 0x18))();
    if (cVar4 != '\0') {
      (**(code **)(*DAT_00b5aee4 + 0x20))(2);
    }
    FUN_0053b090(uStack_1c);
  }
  FUN_0053b410(iVar5,&uStack_1c);
  FUN_00535b40(uVar3,iVar5);
  FUN_0053b220(2,*puVar1,*(undefined4 *)(param_1 + 0x2c),uVar3,iVar5,0);
  return;
}


// ==== FUN_00536ce0 @ 0x00536ce0 ====

undefined4 FUN_00536ce0(int param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined2 uStack_c;
  undefined1 uStack_a;
  
  iVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uStack_24 = *(uint *)(param_1 + 0x1d);
  if (iVar4 + 300U <= *(uint *)(param_1 + 0x1d)) {
    uStack_24 = iVar4 + 300U;
  }
  uVar2 = *(undefined4 *)(param_1 + 0x18);
  iVar4 = *(int *)(param_1 + 0x14);
  uVar1 = *(undefined1 *)(param_1 + 0x1c);
  iVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
  FUN_005363e0(iVar4,uVar2);
  cVar3 = FUN_00535ae0(uVar2);
  if (cVar3 == '\0') {
    puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar6 == (undefined4 *)0x0) {
      puVar6 = (undefined4 *)0x0;
    }
    else {
      *puVar6 = &PTR_FUN_009b9358;
    }
    puVar6[1] = uVar2;
    *(undefined1 *)(puVar6 + 2) = uVar1;
    FUN_0051b660(uStack_24,puVar6);
  }
  FUN_0053a990((undefined4 *)(param_1 + 0x1d),iVar4);
  uStack_1c = *(undefined4 *)(param_1 + 0x1d);
  uStack_18 = *(undefined4 *)(param_1 + 0x21);
  uStack_14 = *(undefined4 *)(param_1 + 0x25);
  uStack_10 = *(undefined4 *)(param_1 + 0x29);
  uStack_c = *(undefined2 *)(param_1 + 0x2d);
  uStack_a = *(undefined1 *)(param_1 + 0x2f);
  if (iVar4 == iVar5) {
    cVar3 = (**(code **)(*DAT_00b5aee4 + 0x18))();
    if (cVar3 != '\0') {
      (**(code **)(*DAT_00b5aee4 + 0x20))(2);
    }
    FUN_0053b090(uStack_1c);
  }
  FUN_0053b410(iVar4,&uStack_1c);
  iVar7 = (**(code **)(*DAT_00b5ac24 + 8))();
  if (((iVar4 == iVar5) && (*(char *)(iVar7 + 2) == '\x01')) || (*(char *)(iVar7 + 2) == '\x02')) {
    FUN_0053a860(uStack_24,uVar2,iVar4,0);
  }
  FUN_00535b40(iVar4,uVar2);
  return 1;
}


// ==== FUN_00536e40 @ 0x00536e40 ====

void FUN_00536e40(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  char cVar9;
  int iVar10;
  int iVar11;
  undefined4 *puVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  int iVar15;
  undefined4 uVar16;
  int iVar17;
  int iVar18;
  uint uStack_34;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  iVar10 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uStack_34 = FUN_004244f0();
  if (iVar10 + 300U <= uStack_34) {
    uStack_34 = iVar10 + 300U;
  }
  uVar14 = *(undefined4 *)(param_1 + 0x20);
  uVar16 = *(undefined4 *)(param_1 + 0x10);
  uVar6 = *(undefined4 *)(param_1 + 0x24);
  iVar10 = *(int *)(param_1 + 0x18);
  iVar17 = *(int *)(param_1 + 0x14);
  iVar18 = *(int *)(param_1 + 0x1c);
  uVar1 = *(undefined1 *)(param_1 + 0x2d);
  uVar7 = *(undefined4 *)(param_1 + 0x28);
  uVar2 = *(undefined1 *)(param_1 + 0x2c);
  uVar3 = *(undefined1 *)(param_1 + 0x34);
  uVar4 = *(undefined1 *)(param_1 + 0x36);
  uVar5 = *(undefined1 *)(param_1 + 0x2e);
  iVar11 = (**(code **)(*DAT_00b5a97c + 0xc))();
  FUN_005363e0(iVar17,iVar10);
  cVar9 = FUN_00535ae0(iVar10);
  if (cVar9 == '\0') {
    puVar12 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar12 == (undefined4 *)0x0) {
      puVar12 = (undefined4 *)0x0;
    }
    else {
      *puVar12 = &PTR_FUN_009b93d0;
    }
    *(undefined1 *)(puVar12 + 2) = uVar3;
    *(undefined1 *)((int)puVar12 + 9) = uVar4;
    puVar12[1] = iVar10;
    puVar12[3] = iVar18;
    *(undefined1 *)(puVar12 + 4) = uVar1;
    *(undefined1 *)((int)puVar12 + 0x11) = uVar2;
    FUN_0051b660(uStack_34,puVar12);
  }
  if (iVar10 == iVar11) {
    FUN_00401740(s_SlidePacket____d__d_009b9320,0x13);
    uVar13 = FUN_00404230(auStack_1c);
    FUN_00796d20(uVar13);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return;
    }
    if (0 < iVar18) {
      FUN_0053aa30(uVar14,uVar6,uVar7,0xffffffff);
    }
    cVar9 = (**(code **)(*DAT_00b5aee4 + 0x18))();
    if (cVar9 != '\0') {
      (**(code **)(*DAT_00b5aee4 + 0x20))(2);
    }
    iVar11 = *DAT_00b5ad1c;
    uVar14 = FUN_004244f0();
    (**(code **)(iVar11 + 0x8c))(uVar7,uVar14);
  }
  else if (0 < iVar18) {
    FUN_0053aad0(iVar10,uVar14,uVar6);
    iVar15 = (**(code **)(*DAT_00b5ac24 + 8))();
    if (((iVar17 == iVar11) && (*(char *)(iVar15 + 2) == '\x01')) ||
       (*(char *)(iVar15 + 2) == '\x02')) {
      FUN_0053a860(uStack_34,iVar10,iVar17,iVar18);
    }
  }
  FUN_0053b0f0(iVar10,uVar16,uVar5);
  FUN_00535b40(iVar17,iVar10);
  piVar8 = DAT_00b5a6ac;
  uVar14 = (**(code **)(*DAT_00b5a6ac + 0x20))(iVar17,iVar10,iVar18);
  uVar16 = (**(code **)(*piVar8 + 0x20))(uVar14);
  FUN_0053b220(5,uVar16,uVar14,iVar17,iVar10,iVar18);
  return;
}


// ==== FUN_005370a0 @ 0x005370a0 ====

uint FUN_005370a0(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x6000101) {
    if (uVar1 == 0x6000100) {
      uVar1 = FUN_00535c10(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    }
    uVar1 = uVar1 + 0xf9ffffff;
    switch(uVar1) {
    case 0:
      uVar1 = FUN_005361c0(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    case 1:
      uVar1 = FUN_005369a0(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    case 2:
      uVar1 = FUN_00536e40(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    case 3:
      uVar1 = FUN_00536460(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    case 4:
      uVar1 = FUN_00535f20(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    case 5:
      uVar1 = FUN_005367a0(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    case 6:
      uVar1 = FUN_00536270(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    case 7:
      uVar1 = FUN_00536b80(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    case 8:
      uVar1 = FUN_00536ce0(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_005371b0 @ 0x005371b0 ====

undefined4 FUN_005371b0(void)

{
  return 0x50040001;
}


// ==== FUN_005371c0 @ 0x005371c0 ====

undefined4 FUN_005371c0(void)

{
  return 0x50040002;
}


// ==== FUN_005371d0 @ 0x005371d0 ====

undefined4 FUN_005371d0(void)

{
  return 0x50040003;
}


// ==== FUN_005371e0 @ 0x005371e0 ====

undefined4 FUN_005371e0(void)

{
  return 0x50040004;
}


// ==== FUN_005371f0 @ 0x005371f0 ====

undefined4 FUN_005371f0(void)

{
  return 0x50040005;
}


// ==== FUN_00537200 @ 0x00537200 ====

undefined4 FUN_00537200(void)

{
  return 0x50040006;
}


// ==== FUN_00537210 @ 0x00537210 ====

undefined4 FUN_00537210(int param_1)

{
  FUN_0053a8b0(*(undefined4 *)(param_1 + 0x10));
  return 1;
}


// ==== FUN_00537250 @ 0x00537250 ====

undefined4 FUN_00537250(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = *(int *)(param_1 + 0x10);
  FUN_0053a990((undefined4 *)(param_1 + 0x20),iVar1);
  iVar3 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (iVar1 == iVar3) {
    uVar2 = *(undefined4 *)(param_1 + 0x1c);
    FUN_0053ad30(*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),uVar2);
    iVar3 = *DAT_00b5ad1c;
    uVar4 = FUN_004244f0();
    (**(code **)(iVar3 + 0x8c))(uVar2,uVar4);
  }
  else {
    FUN_0053aad0(iVar1,1,1);
  }
  FUN_0053b3c0(iVar1,*(undefined4 *)(param_1 + 0x20));
  return 1;
}


// ==== FUN_00537310 @ 0x00537310 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00537310(int param_1)

{
  int iVar1;
  int *piVar2;
  
  if (*(char *)(param_1 + 0x10) == '\0') {
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    if (*(int **)(iVar1 + 0x90) == (int *)0x0) {
      (**(code **)(_DAT_00000000 + 0xc))(*(undefined4 *)(param_1 + 0x14));
      return 1;
    }
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x90) + 0x14))();
    (**(code **)(*piVar2 + 0xc))(*(undefined4 *)(param_1 + 0x14));
  }
  return 1;
}


// ==== FUN_00537360 @ 0x00537360 ====

undefined4 FUN_00537360(void)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  int unaff_retaddr;
  void *pvStack_44;
  uint uVar3;
  undefined4 uStack_28;
  
  uStack_28 = 0;
  (**(code **)(*DAT_00b5ac2c + 4))();
  if (*(int *)(unaff_retaddr + 0x10) == 1) {
    uVar3 = 0;
    uVar2 = (**(code **)(*DAT_00b5a794 + 0xc))(0,0x7d50005);
    FUN_00401660(uVar2,0,0xffffffff);
    piVar1 = DAT_00b5ad0c;
    FUN_00401660(&uStack_28,0,0xffffffff);
    (**(code **)(*piVar1 + 0x28))(2);
    if (0xf < uVar3) {
      _free(pvStack_44);
      return extraout_EAX;
    }
  }
  else if (*(int *)(unaff_retaddr + 0x10) != 2) {
    FUN_0053acd0(unaff_retaddr + 0x14,1);
    return 1;
  }
  return 1;
}


// ==== FUN_00537420 @ 0x00537420 ====

undefined4 FUN_00537420(int param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined1 auStack_1a [2];
  void *pvStack_18;
  uint uStack_4;
  
  cVar1 = *(char *)(param_1 + 0x14);
  if (cVar1 == '\x02') {
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(8,0x2bc003a);
    FUN_00401660(uVar3,0,0xffffffff);
    piVar2 = DAT_00b5ad0c;
    FUN_00401660(auStack_1a + -10,0,0xffffffff);
    (**(code **)(*piVar2 + 0x28))(2);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX;
    }
  }
  (**(code **)(*DAT_00b5ac98 + 0x60))(*(undefined4 *)(param_1 + 0x10),cVar1);
  return 1;
}


// ==== FUN_005374d0 @ 0x005374d0 ====

undefined4 FUN_005374d0(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 extraout_EAX;
  undefined4 uVar7;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  iVar2 = *(int *)(param_1 + 0x10);
  iVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
  uVar1 = *(undefined1 *)(param_1 + 0x22);
  uVar7 = *(undefined4 *)(param_1 + 0x18);
  uVar3 = *(undefined4 *)(param_1 + 0x14);
  uVar4 = *(undefined4 *)(param_1 + 0x1c);
  FUN_0053aa80(iVar2,uVar3,uVar7,uVar1);
  if (iVar2 != iVar5) {
    FUN_0053aad0(iVar2,uVar3,uVar7);
    return 1;
  }
  FUN_00401740(s_ChangePointPacket____d__d__d_009b93e8,0x1c);
  uVar6 = FUN_00404230(auStack_1c);
  FUN_00796d20(uVar6);
  if (uStack_4 < 0x10) {
    FUN_0053aa30(uVar3,uVar7,uVar4,uVar1);
    iVar2 = *DAT_00b5ad1c;
    uVar7 = FUN_004244f0();
    (**(code **)(iVar2 + 0x8c))(*(undefined4 *)(param_1 + 0x1c),uVar7);
    return 1;
  }
  _free(pvStack_18);
  return extraout_EAX;
}


// ==== FUN_005375d0 @ 0x005375d0 ====

undefined4 FUN_005375d0(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  void *unaff_EBX;
  undefined1 *puStack_264;
  undefined4 uStack_260;
  undefined1 auStack_248 [4];
  undefined4 uStack_244;
  uint uStack_240;
  void *pvStack_238;
  undefined4 uStack_230;
  undefined4 uStack_22c;
  void *pvStack_228;
  uint uStack_224;
  uint uStack_214;
  int iStack_204;
  undefined1 local_1fc [8];
  void *pvStack_1f4;
  uint uStack_1e0;
  undefined1 auStack_1d8 [4];
  undefined4 ****appppuStack_1d4 [4];
  undefined4 uStack_1c4;
  uint uStack_1c0;
  
  uVar1 = *(undefined4 *)(param_1 + 0x10);
  puStack_264 = local_1fc;
  uStack_260 = uVar1;
  (**(code **)(*DAT_00b5ac98 + 0x78))();
  if (iStack_204 != -1) {
    cVar2 = (**(code **)(*DAT_00b5ac98 + 0x44))();
    if (cVar2 != '\0') {
      (**(code **)(*DAT_00b5aca8 + 0x18))(auStack_1d8);
      if (uStack_1c0 < 0x10) {
        appppuStack_1d4[0] = appppuStack_1d4;
      }
      iVar3 = FUN_00403620(0,uStack_1e0,appppuStack_1d4[0],uStack_1c4);
      if (iVar3 == 0) {
        uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))(8,0x2bc007f);
        uStack_22c = 0xf;
        uStack_230 = 0;
        uStack_240 = uStack_240 & 0xffffff00;
        FUN_00401660(uVar4,0,0xffffffff);
        FUN_00401830(&DAT_009b9405);
        piVar5 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(uVar1);
        if (piVar5 != (int *)0x0) {
          piVar5 = (int *)(**(code **)(*piVar5 + 0x14))();
          uVar4 = (**(code **)(*piVar5 + 0x24))
                            (0,&Framework::ICreature::RTTI_Type_Descriptor,
                             &Framework::Creature::IBrick::RTTI_Type_Descriptor,0);
          piVar5 = (int *)FUN_00803725(uVar4);
          if (piVar5 != (int *)0x0) {
            piVar5 = (int *)(**(code **)(*piVar5 + 0x20))();
            if (piVar5 != (int *)0x0) {
              iVar3 = (**(code **)(*piVar5 + 4))();
              FUN_00403810(iVar3 + 2);
            }
          }
        }
        FUN_00401830(s_<STONENAME>_009b9408);
        FUN_00404440(auStack_248,&uStack_22c,&puStack_264);
        piVar5 = DAT_00b5ad0c;
        if (0xf < uStack_214) {
          _free(pvStack_228);
          return extraout_EAX;
        }
        FUN_00401660(auStack_248,0,0xffffffff);
        (**(code **)(*piVar5 + 0x28))(2);
        if (0xf < uStack_240) {
          _free(unaff_EBX);
          return extraout_EAX_00;
        }
        uStack_240 = 0xf;
        uStack_244 = 0;
        if (0xf < uStack_224) {
          _free(pvStack_238);
          return extraout_EAX_01;
        }
      }
      FUN_00537c20();
    }
  }
  (**(code **)(*DAT_00b5ac98 + 0x84))(uVar1);
  FUN_0053b1b0(uVar1);
  if (uStack_1e0 < 0x10) {
    return 1;
  }
  _free(pvStack_1f4);
  return extraout_EAX_02;
}


// ==== FUN_005377f0 @ 0x005377f0 ====

undefined4 FUN_005377f0(int param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  char cVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined2 extraout_var;
  undefined4 extraout_EAX;
  int iVar11;
  undefined1 auStack_86 [2];
  undefined4 auStack_84 [11];
  undefined1 uStack_58;
  void *pvStack_54;
  undefined2 uStack_50;
  undefined2 uStack_4e;
  undefined1 uStack_48;
  uint uStack_40;
  undefined4 uStack_38;
  undefined1 auStack_34 [4];
  undefined4 uStack_30;
  undefined1 uStack_8;
  undefined1 uStack_7;
  
  iVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
  iVar11 = *(int *)(param_1 + 0x10);
  if (iVar11 == iVar5) {
    (**(code **)(*DAT_00b5a97c + 0x44))(*(undefined1 *)(param_1 + 0x42));
    piVar6 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    piVar6 = (int *)(**(code **)(*piVar6 + 0x14))();
    uVar7 = (**(code **)(*piVar6 + 0x24))
                      (0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IMiniPC::RTTI_Type_Descriptor,0);
    piVar6 = (int *)FUN_00803725(uVar7);
    if (piVar6 != (int *)0x0) {
      puVar8 = (undefined4 *)(**(code **)(*piVar6 + 0x24))();
      uVar1 = *(undefined1 *)(param_1 + 0x4a);
      puVar10 = &uStack_30;
      for (iVar11 = 10; iVar11 != 0; iVar11 = iVar11 + -1) {
        *puVar10 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar10 = puVar10 + 1;
      }
      uVar2 = *(undefined1 *)(param_1 + 0x4b);
      *(undefined2 *)puVar10 = *(undefined2 *)puVar8;
      uStack_8 = uVar1;
      uStack_7 = uVar2;
      (**(code **)(*piVar6 + 0x20))(&uStack_30);
      (**(code **)(*piVar6 + 0x3c))(*(undefined1 *)(param_1 + 0x42));
      (**(code **)(*piVar6 + 0x40))(*(undefined1 *)(param_1 + 0x4c));
      (**(code **)(*piVar6 + 0x2c))(*(undefined1 *)(param_1 + 0x40));
      (**(code **)(*DAT_00b5ad84 + 0x18))();
      return 1;
    }
  }
  else {
    uVar1 = *(undefined1 *)(param_1 + 0x40);
    uVar3 = *(undefined2 *)(param_1 + 0x44);
    auStack_34 = (undefined1  [4])0xf;
    uStack_38 = 0;
    uStack_48 = 0;
    puVar8 = (undefined4 *)(param_1 + 0x14);
    puVar10 = auStack_84;
    for (iVar5 = 0xb; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    pvStack_54 = (void *)(uint)*(byte *)(param_1 + 0x41);
    uStack_4e = *(undefined2 *)(param_1 + 0x46);
    pcVar9 = (char *)(param_1 + 0x4d);
    do {
      cVar4 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar4 != '\0');
    uStack_58 = uVar1;
    uStack_50 = uVar3;
    FUN_00401740((char *)(param_1 + 0x4d),(int)pcVar9 - (param_1 + 0x4e));
    uStack_30._0_1_ = *(undefined1 *)(param_1 + 0x4a);
    uStack_30._3_1_ = *(undefined1 *)(param_1 + 0x4c);
    uStack_30._1_1_ = *(undefined1 *)(param_1 + 0x4b);
    cVar4 = (**(code **)(*DAT_00b5acac + 0x38))(*(undefined4 *)(param_1 + 0x10));
    if (cVar4 == '\0') {
      auStack_34[2] = 0;
    }
    else {
      auStack_34[2] = *(undefined1 *)(param_1 + 0x42);
    }
    puVar10 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    puVar8 = (undefined4 *)0x0;
    if (puVar10 != (undefined4 *)0x0) {
      *puVar10 = &PTR_FUN_009b9464;
      puVar10[0x15] = 0;
      puVar10[0x16] = 0xf;
      *(undefined1 *)(puVar10 + 0x11) = 0;
      puVar8 = puVar10;
    }
    FUN_00537d00(auStack_86 + -6);
    FUN_00797a20(puVar8);
    (**(code **)(*DAT_00b5aca8 + 0x7c))
              (iVar11,CONCAT22(extraout_var,*(undefined2 *)(param_1 + 0x48)));
    if (0xf < uStack_40) {
      _free(pvStack_54);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_005379e0 @ 0x005379e0 ====

undefined4 FUN_005379e0(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  void *unaff_ESI;
  undefined1 auStack_1a [10];
  uint uStack_10;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 0x10));
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0xc))(), iVar2 == 5)) {
    iVar2 = (**(code **)(*piVar1 + 0x14))();
    *(undefined1 *)(iVar2 + 0x18) = *(undefined1 *)(param_1 + 0x14);
    (**(code **)(*DAT_00b5ac98 + 0x68))
              (*(undefined4 *)(param_1 + 0x10),*(char *)(param_1 + 0x14) != '\x01');
    FUN_00537cb0(iVar2 + 0x18);
    FUN_00537d70();
    FUN_00401740(s_Brick_UpdateMode___Brick___d___S_009b9414,0x2a);
    uVar3 = FUN_00404230(auStack_1a + -0xe);
    FUN_00403e50(uVar3);
    if (0xf < uStack_10) {
      _free(unaff_ESI);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_00537ab0 @ 0x00537ab0 ====

undefined4 FUN_00537ab0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x5090005) {
    if (uVar1 == 0x5090004) {
      FUN_0053ac80(*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10));
      return 1;
    }
    if (uVar1 < 0x5080002) {
      if (uVar1 == 0x5080001) {
        uVar2 = FUN_005377f0(*(undefined4 *)(param_1 + 0xc));
        return uVar2;
      }
      if (uVar1 == 0x5050010) {
        uVar2 = FUN_00537420(*(undefined4 *)(param_1 + 0xc));
        return uVar2;
      }
      if (uVar1 == 0x5060006) {
        uVar2 = FUN_00537250(*(undefined4 *)(param_1 + 0xc));
        return uVar2;
      }
    }
    else {
      if (uVar1 == 0x5090001) {
        uVar2 = FUN_00537210(*(undefined4 *)(param_1 + 0xc));
        return uVar2;
      }
      if (uVar1 == 0x5090003) {
        uVar2 = FUN_005374d0(*(undefined4 *)(param_1 + 0xc));
        return uVar2;
      }
    }
  }
  else if (uVar1 < 0x5270004) {
    if (uVar1 == 0x5270003) {
      uVar2 = FUN_005379e0(*(undefined4 *)(param_1 + 0xc));
      return uVar2;
    }
    if (uVar1 == 0x5160001) {
      uVar2 = FUN_00537360(*(undefined4 *)(param_1 + 0xc));
      return uVar2;
    }
    if (uVar1 == 0x5270001) {
      uVar2 = FUN_005375d0(*(undefined4 *)(param_1 + 0xc));
      return uVar2;
    }
  }
  else {
    if (uVar1 == 0x5270004) {
      FUN_0053a990(*(int *)(param_1 + 0xc) + 0x14,*(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10));
      return 1;
    }
    if (uVar1 == 0x700003b) {
      uVar2 = FUN_00537310(*(undefined4 *)(param_1 + 0xc));
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_00537bf0 @ 0x00537bf0 ====

void FUN_00537bf0(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x54) < 0x10) {
    *(undefined4 *)(in_ECX + 0x54) = 0xf;
    *(undefined4 *)(in_ECX + 0x50) = 0;
    *(undefined1 *)(in_ECX + 0x40) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x40));
  return;
}


// ==== FUN_00537c20 @ 0x00537c20 ====

void FUN_00537c20(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x3c)) {
    _free(*(void **)(in_ECX + 0x28));
    return;
  }
  *(undefined4 *)(in_ECX + 0x3c) = 0xf;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined1 *)(in_ECX + 0x28) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00537c70 @ 0x00537c70 ====

undefined4 FUN_00537c70(void)

{
  return 0x50070001;
}


// ==== FUN_00537c80 @ 0x00537c80 ====

void FUN_00537c80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9464;
  FUN_00537bf0();
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) != 0) {
    (**(code **)(*DAT_00b5a6a8 + 8))();
  }
  return;
}


// ==== FUN_00537cb0 @ 0x00537cb0 ====

void FUN_00537cb0(undefined1 *param_1)

{
  undefined1 *in_ECX;
  
  *in_ECX = *param_1;
  *(undefined2 *)(in_ECX + 2) = *(undefined2 *)(param_1 + 2);
  *(undefined2 *)(in_ECX + 4) = *(undefined2 *)(param_1 + 4);
  *(undefined2 *)(in_ECX + 6) = *(undefined2 *)(param_1 + 6);
  *(undefined4 *)(in_ECX + 0x20) = 0xf;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  in_ECX[0xc] = 0;
  FUN_00401660(param_1 + 8,0,0xffffffff);
  return;
}


// ==== FUN_00537d00 @ 0x00537d00 ====

void FUN_00537d00(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *in_ECX = *param_1;
  iVar1 = 0xb;
  puVar2 = param_1;
  puVar3 = in_ECX;
  while( true ) {
    puVar3 = puVar3 + 1;
    puVar2 = puVar2 + 1;
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    *puVar3 = *puVar2;
  }
  *(undefined1 *)(in_ECX + 0xc) = *(undefined1 *)(param_1 + 0xc);
  in_ECX[0xd] = param_1[0xd];
  *(undefined2 *)(in_ECX + 0xe) = *(undefined2 *)(param_1 + 0xe);
  *(undefined2 *)((int)in_ECX + 0x3a) = *(undefined2 *)((int)param_1 + 0x3a);
  FUN_00401660(param_1 + 0xf,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x16) = *(undefined1 *)(param_1 + 0x16);
  *(undefined1 *)((int)in_ECX + 0x59) = *(undefined1 *)((int)param_1 + 0x59);
  *(undefined1 *)((int)in_ECX + 0x5a) = *(undefined1 *)((int)param_1 + 0x5a);
  *(undefined1 *)((int)in_ECX + 0x5b) = *(undefined1 *)((int)param_1 + 0x5b);
  return;
}


// ==== FUN_00537d70 @ 0x00537d70 ====

void FUN_00537d70(undefined4 param_1,undefined4 param_2,undefined1 param_3,void *param_4)

{
  int in_ECX;
  uint in_stack_00000024;
  
  *(undefined1 *)(in_ECX + 0x18) = (undefined1)param_1;
  *(short *)(in_ECX + 0x1a) = (short)((uint)param_1 >> 0x10);
  *(undefined2 *)(in_ECX + 0x1c) = (undefined2)param_2;
  *(short *)(in_ECX + 0x1e) = (short)((uint)param_2 >> 0x10);
  FUN_00401660(&param_3,0,0xffffffff);
  if (in_stack_00000024 < 0x10) {
    return;
  }
  _free(param_4);
  return;
}


// ==== FUN_00537dc0 @ 0x00537dc0 ====

void FUN_00537dc0(undefined2 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5,undefined4 *param_6,undefined4 param_7)

{
  undefined4 *in_ECX;
  
  *(undefined2 *)(in_ECX + 1) = param_1;
  *(undefined2 *)((int)in_ECX + 6) = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = param_4;
  *in_ECX = &PTR_FUN_009b9684;
  in_ECX[4] = *param_5;
  in_ECX[5] = param_5[1];
  in_ECX[6] = param_5[2];
  in_ECX[7] = *param_6;
  in_ECX[8] = param_6[1];
  in_ECX[9] = param_7;
  return;
}


// ==== FUN_00537e20 @ 0x00537e20 ====

undefined4 FUN_00537e20(void)

{
  return 0x30060110;
}


// ==== FUN_00537e30 @ 0x00537e30 ====

undefined4 FUN_00537e30(int param_1)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  float10 fVar6;
  undefined4 local_3c;
  undefined4 local_38;
  undefined1 auStack_34 [12];
  undefined4 local_28;
  undefined4 local_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  uint uStack_8;
  
  uVar5 = *(undefined4 *)(param_1 + 0x18);
  uVar3 = *(undefined4 *)(param_1 + 0x14);
  sVar1 = *(short *)(param_1 + 0x10);
  sVar2 = *(short *)(param_1 + 0x12);
  if ((sVar1 != 0) && (sVar2 != 0)) {
    FUN_004f5730(&local_28);
    local_3c = (float)local_28;
    local_38 = local_24;
    fVar6 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(&local_3c);
    local_3c = (float)fVar6;
    local_38 = local_28;
    FUN_0040d600(auStack_34,local_24);
    iVar4 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar4 == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_00537dc0(sVar1,sVar2,uVar3,uVar5,auStack_34 + -0xc,auStack_34,0);
    }
    FUN_00797a20(uVar5);
    FUN_00401740(s_______________NotifySkillEffect___009b9480,0x4c);
    uVar5 = FUN_00404230(auStack_20);
    FUN_00796d50(uVar5);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_00537f60 @ 0x00537f60 ====

undefined4 FUN_00537f60(int param_1)

{
  short sVar1;
  short sVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 extraout_EAX;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  uVar6 = *(undefined4 *)(param_1 + 0x1c);
  uVar3 = *(undefined4 *)(param_1 + 0x18);
  uVar4 = *(undefined4 *)(param_1 + 0x14);
  sVar1 = *(short *)(param_1 + 0x10);
  sVar2 = *(short *)(param_1 + 0x12);
  if ((sVar1 != 0) && (sVar2 != 0)) {
    iVar5 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar5 == 0) {
      uVar6 = 0;
    }
    else {
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0;
      uStack_20 = 0;
      uVar6 = FUN_00537dc0(sVar1,sVar2,uVar4,uVar3,&uStack_28,&uStack_30,uVar6);
    }
    FUN_00797a20(uVar6);
    FUN_00401740(s_______________NotifySkillEffect___009b94d0,0x4c);
    uVar6 = FUN_00404230(auStack_1c);
    FUN_00796d50(uVar6);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_00538050 @ 0x00538050 ====

undefined4 FUN_00538050(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int iVar4;
  int *piVar5;
  int iVar6;
  float10 fVar7;
  undefined4 unaff_retaddr;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  uint uStack_2c;
  short sStack_28;
  short sStack_26;
  undefined4 uStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 0x14));
  if (piVar2 == (int *)0x0) {
    FUN_00401740(s__________________________________009b9520,0x23);
    uVar3 = FUN_00404230(auStack_44);
    FUN_00796d50(uVar3);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return extraout_EAX;
    }
    FUN_00401740(s____Servant_No_Find____009b9544,0x16);
    uVar3 = FUN_00404230(auStack_44);
    FUN_00796d50(uVar3);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return extraout_EAX_00;
    }
    FUN_00401740(s__________________________________009b955c,0x23);
    uVar3 = FUN_00404230(auStack_44);
    FUN_00796d50(uVar3);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return extraout_EAX_01;
    }
  }
  else {
    iVar4 = (**(code **)(*piVar2 + 0xc))();
    if (iVar4 == 2) {
      piVar5 = (int *)(**(code **)(*piVar2 + 0x14))();
      piVar5 = (int *)(**(code **)(*piVar5 + 0x24))();
      iVar4 = (**(code **)(*piVar5 + 0x28))();
      if (*(char *)(param_1 + 0x18) == '\0') {
        FUN_004dd240(0x19,2,0,*(undefined2 *)(iVar4 + 0x2aa),unaff_retaddr);
        return 1;
      }
      iVar6 = (**(code **)(*piVar2 + 0x10))();
      uVar3 = *(undefined4 *)(iVar6 + 0x18);
      uVar1 = *(undefined4 *)(iVar6 + 0x1c);
      piVar5 = (int *)(**(code **)(*piVar2 + 0x10))();
      fVar7 = (float10)(**(code **)(*piVar5 + 0x38))();
      fStack_20 = (float)fVar7;
      sStack_28 = *(short *)(iVar4 + 0x2a0);
      sStack_26 = *(short *)(iVar4 + 0x2a2);
      uStack_24 = uVar3;
      uStack_1c = uVar1;
      iVar6 = (**(code **)(*piVar2 + 0x10))();
      uStack_18 = *(undefined4 *)(iVar6 + 0x20);
      uStack_14 = *(undefined4 *)(iVar6 + 0x24);
      iStack_10 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      iStack_c = *(int *)(iVar4 + 0x2a4) + iStack_10;
      uStack_8 = 0;
      if ((sStack_28 != 0) && (sStack_26 != 0)) {
        uVar3 = FUN_00513f50(&sStack_28);
        (**(code **)(*DAT_00b5af0c + 4))(uVar3);
      }
    }
  }
  return 1;
}


// ==== FUN_00538280 @ 0x00538280 ====

undefined4 FUN_00538280(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int iVar4;
  int *piVar5;
  int iVar6;
  float10 fVar7;
  undefined4 unaff_retaddr;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  uint uStack_2c;
  short sStack_28;
  short sStack_26;
  undefined4 uStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  int iStack_10;
  int iStack_c;
  undefined4 uStack_8;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 0x14));
  if (piVar2 == (int *)0x0) {
    FUN_00401740(s__________________________________009b9580,0x23);
    uVar3 = FUN_00404230(auStack_44);
    FUN_00796d50(uVar3);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return extraout_EAX;
    }
    FUN_00401740(s____GUARD_No_Find____009b95a4,0x14);
    uVar3 = FUN_00404230(auStack_44);
    FUN_00796d50(uVar3);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return extraout_EAX_00;
    }
    FUN_00401740(s__________________________________009b95bc,0x23);
    uVar3 = FUN_00404230(auStack_44);
    FUN_00796d50(uVar3);
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return extraout_EAX_01;
    }
  }
  else {
    iVar4 = (**(code **)(*piVar2 + 0xc))();
    if (iVar4 == 3) {
      piVar5 = (int *)(**(code **)(*piVar2 + 0x14))();
      piVar5 = (int *)(**(code **)(*piVar5 + 0x24))();
      iVar4 = (**(code **)(*piVar5 + 0x24))();
      if (*(char *)(param_1 + 0x18) == '\0') {
        FUN_004dd240(0x19,3,0,*(undefined2 *)(iVar4 + 0x2a2),unaff_retaddr);
        return 1;
      }
      iVar6 = (**(code **)(*piVar2 + 0x10))();
      uVar3 = *(undefined4 *)(iVar6 + 0x18);
      uVar1 = *(undefined4 *)(iVar6 + 0x1c);
      piVar5 = (int *)(**(code **)(*piVar2 + 0x10))();
      fVar7 = (float10)(**(code **)(*piVar5 + 0x38))();
      fStack_20 = (float)fVar7;
      sStack_28 = *(short *)(iVar4 + 0x298);
      sStack_26 = *(short *)(iVar4 + 0x29a);
      uStack_24 = uVar3;
      uStack_1c = uVar1;
      iVar6 = (**(code **)(*piVar2 + 0x10))();
      uStack_18 = *(undefined4 *)(iVar6 + 0x20);
      uStack_14 = *(undefined4 *)(iVar6 + 0x24);
      iStack_10 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      iStack_c = *(int *)(iVar4 + 0x29c) + iStack_10;
      uStack_8 = 0;
      if ((sStack_28 != 0) && (sStack_26 != 0)) {
        uVar3 = FUN_00513f50(&sStack_28);
        (**(code **)(*DAT_00b5af0c + 4))(uVar3);
      }
    }
  }
  return 1;
}


// ==== FUN_005385c0 @ 0x005385c0 ====

uint FUN_005385c0(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x6030007) {
    if (uVar1 == 0x6030006) {
      uVar1 = FUN_00537e30(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    }
    if (uVar1 == 0x5190003) {
      uVar1 = FUN_00538050(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    }
    if (uVar1 == 0x51d0003) {
      uVar1 = FUN_00538280(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    }
  }
  else if (uVar1 == 0x6030007) {
    uVar1 = FUN_00537f60(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00538640 @ 0x00538640 ====

void FUN_00538640(void)

{
  undefined1 *in_ECX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined1 local_4 [4];
  
  *(undefined4 *)(in_ECX + 0x20) = 0xf;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  in_ECX[0xc] = 0;
  *in_ECX = 1;
  *(undefined2 *)(in_ECX + 2) = 0;
  *(undefined2 *)(in_ECX + 4) = 0;
  *(undefined2 *)(in_ECX + 6) = 0;
  puVar1 = (undefined4 *)(in_ECX + 0xc);
  if (*(uint *)(in_ECX + 0x20) < 0x10) {
    puVar2 = puVar1;
  }
  else {
    puVar2 = (undefined4 *)*puVar1;
  }
  if (0xf < *(uint *)(in_ECX + 0x20)) {
    puVar1 = (undefined4 *)*puVar1;
  }
  FUN_004bdb30(local_4,puVar1,*(int *)(in_ECX + 0x1c) + (int)puVar2);
  return;
}


// ==== FUN_005386a0 @ 0x005386a0 ====

void FUN_005386a0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  *(undefined1 *)(in_ECX + 2) = *(undefined1 *)(param_1 + 2);
  *(undefined1 *)((int)in_ECX + 9) = *(undefined1 *)((int)param_1 + 9);
  *(undefined2 *)((int)in_ECX + 10) = *(undefined2 *)((int)param_1 + 10);
  *(undefined2 *)(in_ECX + 3) = *(undefined2 *)(param_1 + 3);
  *(undefined2 *)((int)in_ECX + 0xe) = *(undefined2 *)((int)param_1 + 0xe);
  in_ECX[10] = 0xf;
  in_ECX[9] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  FUN_00401660(param_1 + 4,0,0xffffffff);
  return;
}


// ==== FUN_00538700 @ 0x00538700 ====

undefined4 FUN_00538700(int param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  int *piVar5;
  undefined4 extraout_EAX_00;
  int *piVar6;
  int iVar7;
  undefined4 extraout_EAX_01;
  uint uVar8;
  float fVar9;
  int *piStack_24;
  void *pvStack_20;
  void *pvStack_1c;
  uint uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  iVar3 = (**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(param_1 + 0x10));
  if (iVar3 == 0) {
    FUN_00401740(s_Brick_Sync_Enter___No_Search_Bri_009b96b4,0x26);
    uVar4 = FUN_00404230(&pvStack_20);
    FUN_00403e50(uVar4);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return extraout_EAX;
    }
  }
  else {
    piVar5 = (int *)FUN_00803725(iVar3,0,&Framework::ModelCenter::Actors::IActor::
                                          RTTI_Type_Descriptor,
                                 &Framework::ModelCenter::Actors::Brick::RTTI_Type_Descriptor,0);
    if (piVar5 == (int *)0x0) {
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401740(s_pBrick____NULL_009b96dc,0xe);
      FUN_00406880(&pvStack_20);
      if (uStack_8 < 0x10) {
        pcVar2 = (code *)swi(3);
        uVar4 = (*pcVar2)();
        return uVar4;
      }
      _free(pvStack_1c);
      return extraout_EAX_00;
    }
    piVar6 = (int *)(**(code **)(*piVar5 + 0x14))();
    piStack_24 = piVar6;
    iVar3 = (**(code **)(*piVar5 + 0x10))();
    uVar4 = (**(code **)(*piVar6 + 0x24))
                      (0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IBrick::RTTI_Type_Descriptor,0);
    iVar7 = FUN_00803725(uVar4);
    fVar9 = (float)*(int *)(param_1 + 0x18);
    uVar4 = *(undefined4 *)(param_1 + 0x1c);
    if (*(int **)(iVar7 + 0x44) == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)(**(code **)(**(int **)(iVar7 + 0x44) + 0x18))();
    }
    (**(code **)(*piVar5 + 0x14))(fVar9);
    *(float *)(iVar3 + 4) = fVar9;
    uVar8 = 0;
    do {
      cVar1 = *(char *)(param_1 + 0x20 + uVar8);
      fVar9 = (float)CONCAT31((int3)((uint)fVar9 >> 8),cVar1);
      if (cVar1 != '\0') {
        FUN_00826b20(uVar4,fVar9);
        FUN_004dd240(0x13,cVar1,0,2,uStack_4);
      }
      uVar8 = uVar8 + 1;
    } while (uVar8 < 8);
    *(undefined1 *)(iVar7 + 0x18) = *(undefined1 *)(param_1 + 0x14);
    FUN_00401740(s_Brick_Sync_Enter___Brick__d__Sta_009b96ec,0x28);
    uVar4 = FUN_00404230(&piStack_24);
    FUN_00403e50(uVar4);
    if (0xf < uStack_c) {
      _free(pvStack_20);
      return extraout_EAX_01;
    }
    FUN_0052fc30();
  }
  return 1;
}


// ==== FUN_00538900 @ 0x00538900 ====

undefined4 FUN_00538900(int param_1)

{
  int *piVar1;
  char cVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  uint *_Memory;
  uint local_94;
  undefined1 local_90;
  void *pvStack_8c;
  undefined4 local_80;
  undefined4 local_7c;
  uint local_78;
  undefined1 local_74;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined2 local_50;
  undefined1 local_4e;
  undefined1 local_35;
  undefined1 auStack_34 [4];
  void *pvStack_30;
  uint uStack_1c;
  
  local_5c = *(undefined4 *)(param_1 + 0x14);
  local_58 = *(undefined4 *)(param_1 + 0x18);
  local_54 = *(undefined4 *)(param_1 + 0x1c);
  local_50 = *(undefined2 *)(param_1 + 0x20);
  local_4e = 0;
  local_35 = 0;
  local_60 = 0xf;
  local_64 = 0;
  local_74 = 0;
  pcVar3 = (char *)(param_1 + 0x22);
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  FUN_00401740((char *)(param_1 + 0x22),(int)pcVar3 - (param_1 + 0x23));
  local_7c = 0xf;
  local_80 = 0;
  local_90 = 0;
  pcVar3 = (char *)(param_1 + 0x3b);
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  FUN_00401740((char *)(param_1 + 0x3b),(int)pcVar3 - (param_1 + 0x3c));
  _Memory = &local_94;
  uVar4 = (**(code **)(*DAT_00b5adf8 + 0x28))(*(undefined4 *)(param_1 + 0x10),&local_5c,&local_78);
  cVar2 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(param_1 + 0x10),uVar4);
  piVar1 = DAT_00b5a6c0;
  if (cVar2 == '\0') {
    FUN_00401740(s_New_Enter___Flag___08X___009b9718,0x18);
    uVar4 = FUN_00404230(auStack_34);
    (**(code **)(*piVar1 + 4))(2,uVar4);
    if (0xf < uStack_1c) {
      _free(pvStack_30);
      return extraout_EAX;
    }
  }
  if (0xf < local_94) {
    _free(_Memory);
    return extraout_EAX_00;
  }
  local_94 = 0xf;
  if (local_78 < 0x10) {
    return 1;
  }
  _free(pvStack_8c);
  return extraout_EAX_01;
}


// ==== FUN_00538a70 @ 0x00538a70 ====

undefined4 FUN_00538a70(int param_1)

{
  uint uVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  int iVar6;
  void *pvVar7;
  undefined4 uStack_3c;
  void *pvStack_38;
  undefined1 local_22 [2];
  undefined2 uStack_20;
  undefined2 local_1e;
  undefined4 auStack_1c [7];
  
  uVar1 = *(uint *)(param_1 + 0x14);
  local_1e = *(undefined2 *)(param_1 + 0x1a);
  pvStack_38 = (void *)0x0;
  uStack_20 = (undefined2)((uint)*(undefined4 *)(param_1 + 0x16) >> 0x10);
  uStack_3c = 1;
  piVar4 = (int *)(**(code **)(*DAT_00b5a76c + 0xc))();
  iVar6 = *piVar4;
  uVar5 = (**(code **)(*DAT_00b5ac1c + 0x3c))(local_22 + -10);
  cVar3 = (**(code **)(iVar6 + 0x18))(uVar5);
  if (cVar3 == '\0') {
    (**(code **)(*DAT_00b5a76c + 0x10))(1);
    return 1;
  }
  piVar4[0x2b] = *(int *)(param_1 + 0x10);
  uVar5 = (**(code **)(*DAT_00b5adf8 + 0x10))(*(undefined4 *)(param_1 + 0x10),piVar4);
  cVar3 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(param_1 + 0x10),uVar5);
  piVar2 = DAT_00b5a6c0;
  if (cVar3 == '\0') {
    FUN_00401740(s_New_Enter___NPC___08X___009b9734,0x17);
    uVar5 = FUN_00404230(&uStack_3c);
    (**(code **)(*piVar2 + 4))(2,uVar5);
    if (0xf < uVar1) {
      _free(pvStack_38);
      return extraout_EAX;
    }
  }
  auStack_1c[0] = 0xc;
  cVar3 = (**(code **)(*piVar4 + 0x24))(auStack_1c);
  if (cVar3 == '\x01') {
    iVar6 = *DAT_00b5ad00;
    uVar5 = (**(code **)(*DAT_00b5a97c + 0xc))();
    iVar6 = (**(code **)(iVar6 + 4))(uVar5);
    if (*(short *)(iVar6 + 0x14) != 0) {
      pvVar7 = operator_new(0x400);
      *(undefined4 *)((int)pvVar7 + 8) = 0;
      *(undefined4 *)((int)pvVar7 + 0xc) = 0x51d0001;
      *(undefined2 *)((int)pvVar7 + 6) = 0x18;
      iVar6 = FUN_004244d0();
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(param_1 + 0x10);
      *(undefined2 *)(iVar6 + 0x14) = *(undefined2 *)(param_1 + 0x14);
      FUN_004d8570(iVar6);
    }
  }
  uStack_20 = 0x19;
  local_1e = 0;
  cVar3 = (**(code **)(*piVar4 + 0x24))(&uStack_20);
  if (cVar3 == '\x01') {
    (**(code **)(*DAT_00b5ac98 + 0x60))
              (*(undefined4 *)(param_1 + 0x10),*(undefined1 *)(param_1 + 0x1c));
  }
  return 1;
}


// ==== FUN_00538c20 @ 0x00538c20 ====

/* WARNING: Removing unreachable block (ram,0x00538e38) */

undefined4 FUN_00538c20(int param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  char *pcVar5;
  int iVar6;
  int iVar7;
  undefined4 extraout_EAX_00;
  undefined4 unaff_EBP;
  undefined1 auStack_76 [2];
  void *local_74;
  void *local_70;
  void *local_6c;
  undefined4 local_68;
  uint uStack_60;
  uint uStack_5c;
  char acStack_46 [18];
  undefined1 auStack_34 [8];
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined2 uStack_1c;
  char local_1a [26];
  
  FUN_004f5730(&local_70);
  local_74 = local_6c;
  FUN_0040d600(&local_70,local_68);
  local_1a[0] = '\0';
  uStack_2c = (**(code **)(*DAT_00b5ac1c + 0x38))();
  uStack_20 = *(undefined4 *)(param_1 + 0x14);
  uStack_1c = *(undefined2 *)(param_1 + 0x18);
  uStack_24 = *(undefined4 *)(param_1 + 0x10);
  uStack_2a = *(undefined2 *)(param_1 + 0x22);
  uVar2 = 0;
  do {
    cVar1 = *(char *)(param_1 + 0x24 + uVar2);
    local_1a[uVar2] = cVar1;
    if (cVar1 == '\0') goto LAB_00538cb9;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  local_1a[0] = '\0';
LAB_00538cb9:
  piVar3 = (int *)(**(code **)(*DAT_00b5adb0 + 0xc))(1,0);
  iVar6 = *piVar3;
  uVar4 = (**(code **)(*DAT_00b5ac1c + 0x3c))(auStack_34);
  cVar1 = (**(code **)(iVar6 + 0x18))(uVar4);
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5adb0 + 0x10))(1);
    return 1;
  }
  uVar4 = (**(code **)(*DAT_00b5adf8 + 0x1c))
                    (auStack_76 + -0x12,auStack_76 + -10,*(undefined4 *)(param_1 + 0x1c),
                     *(undefined2 *)(param_1 + 0x20),piVar3);
  cVar1 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(param_1 + 0x1c),uVar4);
  piVar3 = DAT_00b5a6c0;
  if (cVar1 == '\0') {
    FUN_00401740(s_New_Enter___Money___08X___009b974c,0x19);
    uVar4 = FUN_00404230(&local_74);
    (**(code **)(*piVar3 + 4))(2,uVar4);
    if (0xf < uStack_5c) {
      _free(local_70);
      return extraout_EAX;
    }
  }
  pcVar5 = acStack_46;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(acStack_46,(int)pcVar5 - (int)(acStack_46 + 1));
  iVar6 = (**(code **)(*DAT_00b5ad1c + 4))(&local_74);
  if (*(uint *)(iVar6 + 0x18) < 0x10) {
    iVar7 = iVar6 + 4;
  }
  else {
    iVar7 = *(int *)(iVar6 + 4);
  }
  iVar6 = FUN_00403620(0,unaff_EBP,iVar7,*(undefined4 *)(iVar6 + 0x14));
  if (0xf < uStack_60) {
    _free(local_74);
    return extraout_EAX_00;
  }
  if (iVar6 == 0) {
    (**(code **)(*DAT_00b5ad1c + 0x80))(*(undefined4 *)(param_1 + 0x1c));
    (**(code **)(*DAT_00b5ad1c + 0x84))(*(undefined4 *)(param_1 + 0x10));
  }
  return 1;
}


// ==== FUN_00538e60 @ 0x00538e60 ====

undefined4 FUN_00538e60(int param_1)

{
  char *pcVar1;
  undefined2 uVar2;
  code *pcVar3;
  char cVar4;
  int iVar5;
  undefined4 extraout_EAX;
  undefined4 uVar6;
  int *piVar7;
  undefined4 extraout_EAX_00;
  uint uVar8;
  char *pcVar9;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined1 auStack_92 [2];
  void *apvStack_80 [2];
  undefined1 auStack_78 [8];
  undefined4 uStack_70;
  uint uStack_6c;
  undefined1 auStack_68 [4];
  void *pvStack_64;
  undefined4 uStack_58;
  undefined4 uStack_54;
  uint uStack_50;
  void *pvStack_4c;
  void *pvStack_48;
  undefined4 uStack_3c;
  uint uStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined2 uStack_24;
  char acStack_22 [34];
  
  iVar5 = (**(code **)(*DAT_00b5ad20 + 0xc))();
  if (iVar5 == 0) {
    uStack_34 = 0xf;
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    FUN_00401740(s_pItemArticle____NULL_009b9768);
    FUN_00406880();
    if (uStack_34 < 0x10) {
      pcVar3 = (code *)swi(3);
      uVar6 = (*pcVar3)();
      return uVar6;
    }
    _free(pvStack_48);
    return extraout_EAX;
  }
  piVar7 = (int *)(**(code **)(*DAT_00b5abbc + 8))();
  if (piVar7 == (int *)0x0) {
    uStack_38 = 0xf;
    uStack_3c = 0;
    pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
    FUN_00401740(s_pFlyWeight____NULL_009b9780,0x12);
    FUN_00406880(&uStack_50);
    if (uStack_38 < 0x10) {
      pcVar3 = (code *)swi(3);
      uVar6 = (*pcVar3)();
      return uVar6;
    }
    _free(pvStack_4c);
    return extraout_EAX_00;
  }
  uStack_30 = *(undefined4 *)(param_1 + 0x10);
  uStack_2c = *(undefined4 *)(param_1 + 0x38);
  uStack_34 = CONCAT22(uStack_34._2_2_,*(undefined2 *)(param_1 + 0x34));
  uStack_28 = *(undefined4 *)(param_1 + 0x2e);
  uStack_24 = *(undefined2 *)(param_1 + 0x32);
  acStack_22[0] = '\0';
  uVar8 = 0;
  pcVar1 = (char *)(param_1 + 0x14);
  do {
    cVar4 = pcVar1[uVar8];
    acStack_22[uVar8] = cVar4;
    if (cVar4 == '\0') goto LAB_00538f6d;
    uVar8 = uVar8 + 1;
  } while (uVar8 < 0x19);
  acStack_22[0] = '\0';
LAB_00538f6d:
  uStack_54 = 0xf;
  uStack_58 = 0;
  auStack_68[0] = 0;
  pcVar9 = pcVar1;
  do {
    cVar4 = *pcVar9;
    pcVar9 = pcVar9 + 1;
  } while (cVar4 != '\0');
  FUN_00401740(pcVar1,(int)pcVar9 - (param_1 + 0x15));
  iVar5 = (**(code **)(*piVar7 + 4))();
  uVar2 = *(undefined2 *)(iVar5 + 0xe);
  FUN_004f5730(auStack_78);
  FUN_0040d600(apvStack_80,uStack_70);
  piVar7 = (int *)(**(code **)(*DAT_00b5adfc + 0xc))(1,0);
  iVar5 = *piVar7;
  uVar6 = (**(code **)(*DAT_00b5ac1c + 0x3c))(&uStack_3c);
  cVar4 = (**(code **)(iVar5 + 0x18))(uVar6);
  if (cVar4 == '\0') {
    (**(code **)(*DAT_00b5adfc + 0x10))(1);
    if (uStack_6c < 0x10) {
      return 1;
    }
  }
  else {
    uVar6 = (**(code **)(*DAT_00b5adf8 + 0x34))
                      (*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x38),
                       CONCAT22((short)((uint)(param_1 + 0x15) >> 0x10),uVar2),auStack_92 + -6,
                       auStack_92 + 2,piVar7);
    cVar4 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(param_1 + 0x10),uVar6);
    piVar7 = DAT_00b5a6c0;
    if (cVar4 == '\0') {
      FUN_00401740(s_New_Enter___Ornament_Item_009b9794,0x19);
      uVar6 = FUN_00404230(auStack_68);
      (**(code **)(*piVar7 + 4))(2,uVar6);
      if (0xf < uStack_50) {
        _free(pvStack_64);
        return extraout_EAX_01;
      }
    }
    if (uStack_6c < 0x10) {
      return 1;
    }
  }
  _free(apvStack_80[0]);
  return extraout_EAX_02;
}


// ==== FUN_005390e0 @ 0x005390e0 ====

undefined4 FUN_005390e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  void *unaff_EDI;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  iVar3 = param_1;
  param_1 = *(undefined4 *)(param_1 + 0x1c);
  FUN_004f5730(&local_28);
  local_30 = local_28;
  local_2c = local_24;
  FUN_0040d600(&local_28,local_20);
  iVar1 = *DAT_00b5adf8;
  uVar5 = FUN_004244f0(&local_30,&local_28,&param_1);
  uVar5 = (**(code **)(iVar1 + 0x24))(*(undefined4 *)(iVar3 + 0x10),uVar5);
  cVar4 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(iVar3 + 0x10),uVar5);
  piVar2 = DAT_00b5a6c0;
  if (cVar4 == '\0') {
    FUN_00401740(s_New_Enter___Money___08X___009b97b0,0x19);
    uVar5 = FUN_00404230((int)register0x00000010 + -0x38);
    (**(code **)(*piVar2 + 4))(2,uVar5);
    if (0xf < local_28) {
      _free(unaff_EDI);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_005391d0 @ 0x005391d0 ====

/* WARNING: Removing unreachable block (ram,0x005392c8) */

undefined4 FUN_005391d0(void)

{
  code *pcVar1;
  int *piVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 extraout_EAX;
  int iVar7;
  undefined4 uVar8;
  uint unaff_ESI;
  uint uVar9;
  float fStack_48;
  void *pvStack_44;
  undefined1 *puStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  undefined1 auStack_22 [30];
  int iStack_4;
  
  uStack_38 = 0;
  uStack_3c = 1;
  puStack_40 = (undefined1 *)0x5391e6;
  piVar4 = (int *)(**(code **)(*DAT_00b5af20 + 0xc))();
  if ((*(char *)(iStack_4 + 0x2f) == '\b') || (*(char *)(iStack_4 + 0x2f) == '\t')) {
    pvStack_44 = *(void **)(iStack_4 + 0x24);
    puStack_40 = (undefined1 *)0xea60;
    fStack_48 = 7.674737e-39;
    cVar3 = FUN_0053b060();
    if (cVar3 != '\0') {
      return 1;
    }
  }
  iVar7 = *piVar4;
  puStack_40 = auStack_22 + -10;
  pvStack_44 = (void *)0x53922e;
  pvStack_44 = (void *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  fStack_48 = 7.674794e-39;
  (**(code **)(iVar7 + 0x18))();
  piVar4[0x2b] = *(int *)(iStack_4 + 0x14);
  if ((int *)piVar4[0x11] == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    fStack_48 = 7.674829e-39;
    piVar5 = (int *)(**(code **)(*(int *)piVar4[0x11] + 0x18))();
  }
  fStack_48 = (float)*(int *)(iStack_4 + 0x1c);
  (**(code **)(*piVar5 + 0x14))();
  if ((int *)piVar4[0x13] == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(*(int *)piVar4[0x13] + 0x18))();
  }
  (**(code **)(*piVar5 + 0x24))(iStack_4 + 0x24);
  piVar5 = (int *)(**(code **)(*DAT_00b5adf8 + 0x18))
                            (*(undefined4 *)(iStack_4 + 0x14),*(undefined4 *)(iStack_4 + 0x10),
                             piVar4);
  if (piVar5 == (int *)0x0) {
    uStack_3c = uStack_3c & 0xffffff00;
    FUN_00401740(s_pActor____NULL_009b97cc,0xe);
    FUN_00406880(&puStack_40);
    pcVar1 = (code *)swi(3);
    uVar6 = (*pcVar1)();
    return uVar6;
  }
  cVar3 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(iStack_4 + 0x14),piVar5);
  piVar2 = DAT_00b5a6c0;
  if (cVar3 == '\0') {
    FUN_00401740(s_New_Enter___Guard___08X___009b97dc,0x19);
    uVar6 = FUN_00404230(&fStack_48);
    (**(code **)(*piVar2 + 4))(2,uVar6);
    if (0xf < unaff_ESI) {
      _free(pvStack_44);
      return extraout_EAX;
    }
  }
  iVar7 = (**(code **)(*piVar4 + 0x24))();
  FUN_004dd240(0x19,3,1,*(undefined2 *)(iVar7 + 0x2a0),*(undefined4 *)(iStack_4 + 0x14));
  uVar6 = *(undefined4 *)(iStack_4 + 0x20);
  iVar7 = (**(code **)(*piVar5 + 0x10))();
  *(undefined4 *)(iVar7 + 4) = uVar6;
  piVar4 = (int *)(**(code **)(*piVar5 + 0x14))();
  uVar8 = (**(code **)(*piVar4 + 0x24))();
  uVar9 = 0;
  do {
    cVar3 = *(char *)(iStack_4 + 0x3d + uVar9);
    uVar6 = CONCAT31((int3)((uint)uVar6 >> 8),cVar3);
    if (cVar3 != '\0') {
      FUN_00826b20(uVar8,uVar6);
      FUN_004dd240(0x13,cVar3,0,2,*(undefined4 *)(iStack_4 + 0x14));
    }
    uVar9 = uVar9 + 1;
  } while (uVar9 < 8);
  iVar7 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (iVar7 == *(int *)(iStack_4 + 0x10)) {
    (**(code **)(*piVar5 + 0x44))(1);
  }
  return 1;
}


// ==== FUN_00539400 @ 0x00539400 ====

undefined4 FUN_00539400(int param_1)

{
  int *piVar1;
  char cVar2;
  void *_Memory;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  uint unaff_EDI;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined2 *puStack_54;
  int iStack_50;
  undefined2 local_28 [16];
  undefined1 local_8;
  undefined1 local_7;
  undefined4 local_4;
  
  puStack_54 = *(undefined2 **)(param_1 + 0x20);
  iStack_50 = 30000;
  uStack_58 = 0x539420;
  cVar2 = FUN_0053b060();
  if (cVar2 != '\0') {
    iStack_50 = *(undefined4 *)(param_1 + 0x14);
    puStack_54 = (undefined2 *)0x539433;
    FUN_0053adb0();
    return 1;
  }
  local_7 = *(undefined1 *)(param_1 + 0x1b);
  local_28[0] = *(undefined2 *)(param_1 + 0x18);
  local_8 = *(undefined1 *)(param_1 + 0x1a);
  local_4 = *(undefined4 *)(param_1 + 0x1c);
  puStack_54 = local_28;
  uStack_58 = *(undefined4 *)(param_1 + 0x10);
  uStack_5c = *(undefined4 *)(param_1 + 0x14);
  iStack_50 = param_1 + 0x20;
  _Memory = (void *)(**(code **)(*DAT_00b5adf8 + 0x14))();
  cVar2 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(param_1 + 0x14));
  piVar1 = DAT_00b5a6c0;
  if (cVar2 == '\0') {
    FUN_00401740(s_New_Enter___Remote___08X___009b97f8,0x1a);
    uVar3 = FUN_00404230(&uStack_5c);
    (**(code **)(*piVar1 + 4))(2,uVar3);
    if (0xf < unaff_EDI) {
      _free(_Memory);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_005394f0 @ 0x005394f0 ====

undefined4 FUN_005394f0(void)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 extraout_EAX;
  int *piVar4;
  undefined4 extraout_EAX_00;
  int iVar5;
  undefined4 extraout_EAX_01;
  int *unaff_EBX;
  uint uVar6;
  void *unaff_ESI;
  undefined4 uStack_4c;
  void *pvStack_48;
  undefined1 *puStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_26 [6];
  uint uStack_20;
  int *piStack_10;
  int iStack_4;
  
  uStack_3c = 0;
  uStack_40 = 1;
  puStack_44 = (undefined1 *)0x539506;
  piVar2 = (int *)(**(code **)(*DAT_00b5a758 + 0xc))();
  iVar5 = *piVar2;
  puStack_44 = auStack_26 + -10;
  pvStack_48 = (void *)0x539527;
  pvStack_48 = (void *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  uStack_4c = 0x53952d;
  (**(code **)(iVar5 + 0x18))();
  piVar4 = (int *)piVar2[0x11];
  uStack_4c = 0x539538;
  (**(code **)(*piVar4 + 0x18))();
  iVar5 = *piVar4;
  uStack_4c = 0x53954a;
  uStack_4c = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar5 + 0x1c))();
  (**(code **)(*piStack_10 + 0x14))((float)*(int *)(iStack_4 + 0x18));
  iVar5 = *(int *)piVar2[0x14];
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar5 + 0x18))(uVar3);
  uVar6 = 0;
  FUN_00401740(s_______________First_MonsterHP__d_009b9814,0x38);
  uVar3 = FUN_00404230(auStack_26 + -0x12);
  FUN_00403e50(uVar3);
  if (0xf < uStack_20) {
    _free(unaff_ESI);
    return extraout_EAX;
  }
  piVar2[0x2b] = *(int *)(iStack_4 + 0x10);
  if ((int *)piVar2[0x13] == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(*(int *)piVar2[0x13] + 0x18))();
  }
  (**(code **)(*piVar4 + 0x24))(iStack_4 + 0x20);
  piVar2 = (int *)(**(code **)(*DAT_00b5adf8 + 8))(*(undefined4 *)(iStack_4 + 0x10),piVar2);
  cVar1 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(iStack_4 + 0x10),piVar2);
  piVar4 = DAT_00b5a6c0;
  if (cVar1 == '\0') {
    FUN_00401740(s_New_Enter___Monster___08X___009b9850,0x1b);
    uVar3 = FUN_00404230(&uStack_4c);
    (**(code **)(*piVar4 + 4))(2,uVar3);
    if ((void *)0xf < unaff_ESI) {
      _free(pvStack_48);
      return extraout_EAX_00;
    }
  }
  uVar3 = *(undefined4 *)(iStack_4 + 0x1c);
  iVar5 = (**(code **)(*piVar2 + 0x10))();
  *(undefined4 *)(iVar5 + 4) = uVar3;
  piVar4 = (int *)(**(code **)(*piVar2 + 0x14))();
  uVar3 = (**(code **)(*piVar4 + 0x24))();
  FUN_00826b40(uVar3);
  do {
    cVar1 = *(char *)(iStack_4 + 0x40 + uVar6);
    if (cVar1 != '\0') {
      FUN_00826b20(uVar3,cVar1);
      FUN_004dd240(0x13,cVar1,0,2,*(undefined4 *)(iStack_4 + 0x10));
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 8);
  (**(code **)(*unaff_EBX + 0xc))(*(undefined2 *)(iStack_4 + 0x14));
  FUN_00401740(s_______________Last_MonsterHP__d__009b986c,0x37);
  uVar3 = FUN_00404230(&uStack_4c);
  FUN_00403e50(uVar3);
  if (unaff_ESI < (void *)0x10) {
    uVar3 = (**(code **)(*piVar2 + 0x10))
                      (0,&Framework::ModelCenter::Actors::State::IActorState::RTTI_Type_Descriptor,
                       &Framework::ModelCenter::Actors::State::Monster::RTTI_Type_Descriptor,0);
    iVar5 = FUN_00803725(uVar3);
    *(undefined1 *)(iVar5 + 0x40) = *(undefined1 *)(iStack_4 + 0x48);
    *(undefined4 *)(iVar5 + 0x44) = *(undefined4 *)(iStack_4 + 0x3c);
    return 1;
  }
  _free(pvStack_48);
  return extraout_EAX_01;
}


// ==== FUN_00539790 @ 0x00539790 ====

undefined4 FUN_00539790(void)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int iVar5;
  undefined4 extraout_EAX_01;
  int *unaff_EBX;
  void *unaff_ESI;
  uint uVar6;
  float fStack_48;
  void *pvStack_44;
  undefined1 *puStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 auStack_22 [6];
  uint uStack_1c;
  int iStack_4;
  
  uStack_38 = 0;
  uStack_3c = 1;
  puStack_40 = (undefined1 *)0x5397a6;
  piVar2 = (int *)(**(code **)(*DAT_00b5ac88 + 0xc))();
  iVar5 = *piVar2;
  puStack_40 = auStack_22 + -10;
  pvStack_44 = (void *)0x5397c7;
  pvStack_44 = (void *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  fStack_48 = 7.676802e-39;
  (**(code **)(iVar5 + 0x18))();
  if ((int *)piVar2[0x11] == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    fStack_48 = 7.676824e-39;
    piVar3 = (int *)(**(code **)(*(int *)piVar2[0x11] + 0x18))();
  }
  fStack_48 = (float)*(int *)(iStack_4 + 0x18);
  (**(code **)(*piVar3 + 0x14))();
  iVar5 = *(int *)piVar2[0x14];
  uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  (**(code **)(iVar5 + 0x18))(uVar4);
  FUN_00401740(s_______________First_SentryHP__d__009b98a4,0x37);
  uVar4 = FUN_00404230(auStack_22 + -0x12);
  FUN_00403e50(uVar4);
  if (0xf < uStack_1c) {
    _free(unaff_ESI);
    return extraout_EAX;
  }
  piVar2[0x2b] = *(int *)(iStack_4 + 0x10);
  if ((int *)piVar2[0x13] == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = (int *)(**(code **)(*(int *)piVar2[0x13] + 0x18))();
  }
  (**(code **)(*piVar3 + 0x24))(iStack_4 + 0x20);
  piVar3 = (int *)(**(code **)(*DAT_00b5adf8 + 0x30))(*(undefined4 *)(iStack_4 + 0x10),piVar2);
  cVar1 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(iStack_4 + 0x10),piVar3);
  piVar2 = DAT_00b5a6c0;
  if (cVar1 == '\0') {
    FUN_00401740(s_New_Enter___Monster___08X___009b98dc,0x1b);
    uVar4 = FUN_00404230(&fStack_48);
    (**(code **)(*piVar2 + 4))(2,uVar4);
    if ((void *)0xf < unaff_ESI) {
      _free(pvStack_44);
      return extraout_EAX_00;
    }
  }
  uVar4 = *(undefined4 *)(iStack_4 + 0x1c);
  iVar5 = (**(code **)(*piVar3 + 0x10))();
  *(undefined4 *)(iVar5 + 4) = uVar4;
  piVar2 = (int *)(**(code **)(*piVar3 + 0x14))();
  uVar4 = (**(code **)(*piVar2 + 0x24))();
  uVar6 = 0;
  do {
    cVar1 = *(char *)(iStack_4 + 0x39 + uVar6);
    if (cVar1 != '\0') {
      FUN_00826b20(uVar4,cVar1);
      FUN_004dd240(0x13,cVar1,0,2,*(undefined4 *)(iStack_4 + 0x10));
    }
    uVar6 = uVar6 + 1;
  } while (uVar6 < 8);
  (**(code **)(*unaff_EBX + 0xc))(*(undefined2 *)(iStack_4 + 0x14));
  FUN_00401740(s_______________Last_SentryHP__d__I_009b98f8,0x36);
  uVar4 = FUN_00404230(&fStack_48);
  FUN_00403e50(uVar4);
  if (unaff_ESI < (void *)0x10) {
    return 1;
  }
  _free(pvStack_44);
  return extraout_EAX_01;
}


// ==== FUN_005399f0 @ 0x005399f0 ====

undefined4 FUN_005399f0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined4 extraout_EAX;
  int iVar7;
  undefined4 uVar8;
  uint unaff_EDI;
  uint uVar9;
  undefined4 uStack_50;
  undefined1 *puStack_4c;
  undefined4 uStack_48;
  int iStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_2a [38];
  int iStack_4;
  
  uStack_3c = 0;
  uStack_40 = 1;
  iStack_44 = 0x539a06;
  piVar2 = (int *)(**(code **)(*DAT_00b5addc + 0xc))();
  if ((*(char *)(iStack_4 + 0x2f) == '\b') || (*(char *)(iStack_4 + 0x2f) == '\t')) {
    uStack_48 = *(undefined4 *)(iStack_4 + 0x24);
    iStack_44 = 60000;
    puStack_4c = (undefined1 *)0x539a2b;
    cVar1 = FUN_0053b060();
    if (cVar1 != '\0') {
      return 1;
    }
  }
  iStack_44 = 0x539a47;
  (**(code **)(*DAT_00b5ac1c + 0x24))();
  iVar7 = *(int *)(iStack_4 + 0x10);
  iStack_44 = 0x539a6e;
  iVar3 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (iVar3 == iVar7) {
    iStack_44 = 0x539a7d;
    (**(code **)(*DAT_00b5ae90 + 0xc))();
    iStack_44 = *(int *)(iStack_4 + 0x14);
    uStack_48 = 0x539a8c;
    (**(code **)(*DAT_00b5af10 + 0x10))();
    piVar4 = DAT_00b5ac1c;
    iVar7 = *piVar2;
    uStack_48 = 0x539a9f;
    uStack_48 = (**(code **)(*DAT_00b5a980 + 8))();
  }
  else {
    uStack_48 = 0x539ac0;
    iStack_44 = iVar7;
    piVar4 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))();
    if (piVar4 == (int *)0x0) {
      iVar7 = *piVar2;
      uStack_48 = 0;
      puStack_4c = auStack_2a + -6;
      uStack_50 = 0x539af0;
      uStack_50 = (**(code **)(*DAT_00b5ac1c + 0x3c))();
      (**(code **)(iVar7 + 0x18))();
      goto LAB_00539af6;
    }
    uStack_48 = 0x539acb;
    piVar5 = (int *)(**(code **)(*piVar4 + 0x14))();
    piVar4 = DAT_00b5ac1c;
    iVar7 = *piVar2;
    uStack_48 = 0x539ada;
    uStack_48 = (**(code **)(*piVar5 + 0x24))();
  }
  puStack_4c = auStack_2a + -6;
  uStack_50 = 0x539aac;
  uStack_50 = (**(code **)(*piVar4 + 0x3c))();
  (**(code **)(iVar7 + 0x18))();
LAB_00539af6:
  piVar2[0x2b] = *(int *)(iStack_4 + 0x14);
  if ((int *)piVar2[0x11] == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(*(int *)piVar2[0x11] + 0x18))();
  }
  (**(code **)(*piVar4 + 0x14))((float)*(int *)(iStack_4 + 0x1c));
  if ((int *)piVar2[0x13] == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(*(int *)piVar2[0x13] + 0x18))();
  }
  (**(code **)(*piVar4 + 0x24))(iStack_4 + 0x24);
  piVar5 = (int *)(**(code **)(*DAT_00b5adf8 + 0xc))
                            (*(undefined4 *)(iStack_4 + 0x14),*(undefined4 *)(iStack_4 + 0x10),
                             piVar2);
  cVar1 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(iStack_4 + 0x14),piVar5);
  piVar4 = DAT_00b5a6c0;
  if (cVar1 == '\0') {
    FUN_00401740(s_New_Enter___Servant___08X___009b9930,0x1b);
    uVar6 = FUN_00404230(&uStack_50);
    (**(code **)(*piVar4 + 4))(2,uVar6);
    if (0xf < unaff_EDI) {
      _free(puStack_4c);
      return extraout_EAX;
    }
  }
  iVar7 = (**(code **)(*piVar2 + 0x28))();
  FUN_004dd240(0x19,2,1,*(undefined2 *)(iVar7 + 0x2a8),*(undefined4 *)(iStack_4 + 0x14));
  uVar6 = *(undefined4 *)(iStack_4 + 0x20);
  iVar7 = (**(code **)(*piVar5 + 0x10))();
  *(undefined4 *)(iVar7 + 4) = uVar6;
  piVar2 = (int *)(**(code **)(*piVar5 + 0x14))();
  uVar8 = (**(code **)(*piVar2 + 0x24))();
  uVar9 = 0;
  do {
    cVar1 = *(char *)(iStack_4 + 0x42 + uVar9);
    uVar6 = CONCAT31((int3)((uint)uVar6 >> 8),cVar1);
    if (cVar1 != '\0') {
      FUN_00826b20(uVar8,uVar6);
      FUN_004dd240(0x13,cVar1,0,2,*(undefined4 *)(iStack_4 + 0x14));
    }
    uVar9 = uVar9 + 1;
  } while (uVar9 < 8);
  iVar7 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (iVar7 == *(int *)(iStack_4 + 0x10)) {
    (**(code **)(*piVar5 + 0x44))(1);
  }
  return 1;
}


// ==== FUN_00539c70 @ 0x00539c70 ====

undefined4 FUN_00539c70(int param_1)

{
  int iVar1;
  int *piVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  void *unaff_EDI;
  uint local_54;
  uint local_50;
  uint local_4c;
  undefined4 local_48;
  undefined4 local_44;
  uint local_24 [9];
  
  local_24[1] = 0;
  local_24[2] = 0;
  local_24[3] = 0;
  local_24[4] = 0;
  local_24[5] = 0;
  local_24[6] = 0;
  local_24[7] = 0;
  local_24[0] = (uint)*(ushort *)(param_1 + 0x1a);
  local_24[8] = 0;
  FUN_004f5730(&local_4c);
  local_54 = local_4c;
  local_50 = local_48;
  FUN_0040d600(&local_4c,local_44);
  iVar1 = *DAT_00b5adf8;
  uVar4 = FUN_004244f0(local_24);
  uVar4 = (**(code **)(iVar1 + 0x20))(*(undefined4 *)(param_1 + 0x10),&local_54,&local_4c,uVar4);
  cVar3 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(param_1 + 0x10),uVar4);
  piVar2 = DAT_00b5a6c0;
  if (cVar3 == '\0') {
    FUN_00401740(s_New_Enter___Item___08X___009b994c,0x18);
    uVar4 = FUN_00404230(local_24 + -0xe);
    (**(code **)(*piVar2 + 4))(2,uVar4);
    if (0xf < local_4c) {
      _free(unaff_EDI);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_00539d80 @ 0x00539d80 ====

undefined4 FUN_00539d80(int param_1)

{
  char *pcVar1;
  char cVar2;
  short sVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 uVar7;
  undefined4 extraout_EAX;
  char *pcVar8;
  undefined4 extraout_EAX_00;
  int iVar9;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 unaff_EBX;
  void **in_stack_ffffff14;
  uint uVar10;
  undefined2 uVar11;
  undefined1 in_stack_ffffff1c;
  uint uVar12;
  void **ppvVar13;
  undefined4 uVar14;
  undefined4 uVar15;
  undefined1 uVar16;
  void *pvStack_a8;
  undefined4 uStack_a4;
  uint uVar17;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined1 uStack_88;
  undefined1 uStack_87;
  undefined2 uStack_86;
  undefined2 uStack_84;
  undefined2 uStack_82;
  void *pvStack_7c;
  undefined4 uStack_6c;
  uint uStack_68;
  void *pvStack_60;
  undefined1 uStack_5c;
  uint uStack_4c;
  undefined4 uStack_48;
  void *pvStack_44;
  void *pvStack_40;
  undefined4 uStack_34;
  uint uStack_30;
  uint uStack_2c;
  
  uStack_a4 = 0x539d95;
  sVar3 = (**(code **)(*DAT_00b5ac1c + 0x38))();
  if (*(short *)(param_1 + 0x5c) == sVar3) {
    uStack_a4 = 0;
    pvStack_a8 = (void *)0x1;
    piVar4 = (int *)(**(code **)(*DAT_00b5ac8c + 0xc))();
    uVar17 = CONCAT22((short)((uint)unaff_EBX >> 0x10),*(undefined2 *)(param_1 + 0x18));
    iVar9 = *piVar4;
    uVar5 = (**(code **)(*DAT_00b5ac1c + 0x3c))((int)register0x00000010 + -0x94);
    (**(code **)(iVar9 + 0x18))(uVar5);
    uVar16 = (undefined1)uVar5;
    iVar9 = *(int *)piVar4[0x14];
    uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    (**(code **)(iVar9 + 0x18))(uVar5);
    piVar4[0x2b] = *(int *)(param_1 + 0x14);
    if ((int *)piVar4[0x13] == (int *)0x0) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = (int *)(**(code **)(*(int *)piVar4[0x13] + 0x18))();
    }
    (**(code **)(*piVar6 + 0x24))(param_1 + 0x1a);
    uVar5 = (**(code **)(*DAT_00b5adf8 + 0x2c))(*(undefined4 *)(param_1 + 0x14),piVar4);
    cVar2 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(param_1 + 0x14),uVar5);
    piVar4 = DAT_00b5a6c0;
    if (cVar2 == '\0') {
      in_stack_ffffff1c = 0;
      FUN_00401740(s_New_Enter___Brick___08X___009b9698,0x19);
      in_stack_ffffff14 = &pvStack_44;
      uVar7 = FUN_00404230(in_stack_ffffff14);
      (**(code **)(*piVar4 + 4))(2,uVar7);
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return extraout_EAX;
      }
    }
    uVar12 = 0x539eae;
    piVar4 = (int *)FUN_00803725(uVar5,0,&Framework::ModelCenter::Actors::IActor::
                                          RTTI_Type_Descriptor,
                                 &Framework::ModelCenter::Actors::Brick::RTTI_Type_Descriptor,0);
    (**(code **)(*piVar4 + 0x14))();
    (**(code **)(*piVar4 + 0x10))();
    pcVar1 = (char *)(param_1 + 0x3a);
    uStack_48 = 0xf;
    uStack_4c = 0;
    uStack_5c = 0;
    pcVar8 = pcVar1;
    do {
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    FUN_00401740(pcVar1,(int)pcVar8 - (param_1 + 0x3b));
    FUN_00401660(&pvStack_60,0,0xffffffff);
    FUN_00538640();
    uVar11 = *(undefined2 *)(param_1 + 0x36);
    ppvVar13 = &pvStack_60;
    uVar7 = 0x539f41;
    FUN_00401660(ppvVar13,0,0xffffffff);
    uVar10 = CONCAT31((int3)((uint)in_stack_ffffff14 >> 8),uVar16) & 0xffff;
    uVar15 = 0xf;
    uVar14 = 0;
    uVar12 = uVar12 & 0xffffff00;
    FUN_00401660(&pvStack_a8,0,0xffffffff);
    FUN_00537d70(uVar10,uVar11,in_stack_ffffff1c,uVar12,uVar5,uVar7,ppvVar13,uVar14,uVar15);
    piVar4 = (int *)(**(code **)(*DAT_00b5aaf8 + 8))(*(undefined4 *)(param_1 + 0x10));
    if (piVar4 != (int *)0x0) {
      uStack_8c = *(undefined4 *)(param_1 + 0x10);
      uStack_90 = *(undefined4 *)(param_1 + 0x14);
      uStack_84 = *(undefined2 *)(param_1 + 0x36);
      uStack_68 = 0xf;
      uStack_86 = *(undefined2 *)(param_1 + 0x34);
      uStack_30 = 0xf;
      uStack_6c = 0;
      pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
      uStack_87 = 1;
      uStack_88 = 0;
      uStack_82 = 0;
      uStack_34 = 0;
      pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
      pcVar8 = pcVar1;
      do {
        cVar2 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar2 != '\0');
      FUN_00401740(pcVar1,(int)pcVar8 - (param_1 + 0x3b));
      FUN_00401660(&uStack_48,0,0xffffffff);
      if (0xf < uStack_30) {
        _free(pvStack_44);
        return extraout_EAX_00;
      }
      iVar9 = *DAT_00b5ac98;
      FUN_005386a0(&uStack_90);
      (**(code **)(iVar9 + 0x74))();
      iVar9 = (**(code **)(*DAT_00b5abec + 0xc))(pcVar1);
      if (iVar9 != 0) {
        (**(code **)(*piVar4 + 8))(iVar9);
        if (0xf < uStack_68) {
          _free(pvStack_7c);
          return extraout_EAX_01;
        }
        uStack_68 = 0xf;
        uStack_6c = 0;
        pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
        if (0xf < uVar17) {
          _free(pvStack_a8);
          return extraout_EAX_02;
        }
        if (uStack_4c < 0x10) {
          return 1;
        }
        goto LAB_0053a162;
      }
      iVar9 = (**(code **)(*DAT_00b5ac9c + 0xc))(pcVar1);
      if (iVar9 != 0) {
        (**(code **)(*piVar4 + 8))(iVar9);
        FUN_00792590();
        FUN_006c1c60();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_00792590();
    }
    if (0xf < uVar17) {
      _free(pvStack_a8);
      return extraout_EAX_03;
    }
    if (0xf < uStack_4c) {
LAB_0053a162:
      pvStack_a8 = (void *)((uint)pvStack_a8 & 0xffffff00);
      _free(pvStack_60);
      return extraout_EAX_04;
    }
  }
  return 1;
}


// ==== FUN_0053a180 @ 0x0053a180 ====

uint FUN_0053a180(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 < 0x5230004) {
    if (uVar1 == 0x5230003) {
      uVar1 = FUN_00538c20(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    }
    if (uVar1 < 0x5050001) {
      if (uVar1 == 0x5050000) {
        uVar1 = FUN_00538a70(*(undefined4 *)(param_1 + 0xc));
        return uVar1;
      }
      if (uVar1 == 0x5020000) {
        uVar1 = FUN_00539c70(*(undefined4 *)(param_1 + 0xc));
        return uVar1;
      }
      if (uVar1 == 0x5030002) {
        uVar1 = FUN_005390e0(*(undefined4 *)(param_1 + 0xc));
        return uVar1;
      }
      if (uVar1 == 0x5040000) {
        uVar1 = FUN_005394f0(*(undefined4 *)(param_1 + 0xc));
        return uVar1;
      }
    }
    else {
      if (uVar1 == 0x5190000) {
        uVar1 = FUN_005399f0(*(undefined4 *)(param_1 + 0xc));
        return uVar1;
      }
      if (uVar1 == 0x51d0000) {
        uVar1 = FUN_005391d0(*(undefined4 *)(param_1 + 0xc));
        return uVar1;
      }
    }
  }
  else if (uVar1 < 0x5290001) {
    if (uVar1 == 0x5290000) {
      uVar1 = FUN_00539790(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    }
    if (uVar1 == 0x5240000) {
      uVar1 = FUN_00538900(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    }
    if (uVar1 == 0x5270000) {
      uVar1 = FUN_00539d80(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    }
    uVar1 = uVar1 + 0xfad8fffe;
    if (uVar1 == 0) {
      uVar1 = FUN_00538700(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    }
  }
  else {
    if (uVar1 == 0x52f0002) {
      uVar1 = FUN_00538e60(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    }
    if (uVar1 == 0x6020000) {
      uVar1 = FUN_00539400(*(undefined4 *)(param_1 + 0xc));
      return uVar1;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0053a2f0 @ 0x0053a2f0 ====

undefined4 FUN_0053a2f0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  ushort uVar3;
  
  uVar3 = (ushort)(*(short *)(param_1 + 6) - 0x10U) >> 2;
  iVar2 = 0;
  if (uVar3 != 0) {
    do {
      uVar1 = FUN_0053a540(iVar2);
      FUN_0053b5d0(uVar1);
      iVar2 = iVar2 + 1;
    } while ((ushort)iVar2 < uVar3);
  }
  return 1;
}


// ==== FUN_0053a340 @ 0x0053a340 ====

undefined4 FUN_0053a340(int param_1)

{
  undefined1 uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  undefined4 extraout_EAX;
  int *piVar6;
  undefined4 extraout_EAX_00;
  char *pcVar7;
  int aiStack_24 [2];
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar2 = *(int *)(param_1 + 0x10);
  iVar4 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (*(ushort *)(param_1 + 6) < 0x31) {
    pcVar7 = (char *)0x0;
  }
  else {
    pcVar7 = (char *)(param_1 + 0x30);
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  if (pcVar7 != (char *)0x0) {
    pcVar5 = pcVar7;
    do {
      cVar3 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar3 != '\0');
    FUN_00401740(pcVar7,(int)pcVar5 - (int)(pcVar7 + 1));
  }
  uVar1 = 0;
  if (*(char *)(param_1 + 0x1f) == '\x11') {
    uVar1 = *(undefined1 *)(param_1 + 0x20);
  }
  FUN_0053ae50(iVar2,uVar1,auStack_1c);
  switch(*(undefined1 *)(param_1 + 0x1f)) {
  case 7:
  case 8:
    goto switchD_0053a3dc_caseD_7;
  case 0x11:
  case 0x12:
  case 0x16:
  case 0x17:
    if (iVar2 != iVar4) {
      FUN_0053a990(param_1 + 0x14,iVar2);
    }
    goto LAB_0053a3f7;
  }
  if (((iVar2 != iVar4) &&
      (piVar6 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(iVar2), piVar6 != (int *)0x0)) &&
     ((piVar6 = (int *)(**(code **)(*piVar6 + 0x18))(), piVar6 == (int *)0x0 ||
      (cVar3 = (**(code **)(*piVar6 + 8))(), cVar3 != '\x01')))) {
    FUN_0053a990(param_1 + 0x14,iVar2);
  }
switchD_0053a3dc_caseD_7:
  piVar6 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar6 == (int *)0x0) {
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX_00;
    }
  }
  else {
    aiStack_24[0] = iVar2;
    piVar6 = (int *)(**(code **)(*piVar6 + 0x30))(aiStack_24);
    if (piVar6 != (int *)0x0) {
      if (*(int *)(*piVar6 + 4) != 0) {
        (**(code **)(*DAT_00b5a804 + 8))(iVar2);
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
LAB_0053a3f7:
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX;
    }
  }
  return 1;
}


// ==== FUN_0053a4f0 @ 0x0053a4f0 ====

uint FUN_0053a4f0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x50d0000) {
    uVar2 = FUN_0053a340(*(undefined4 *)(param_1 + 0xc));
    return uVar2;
  }
  if (iVar1 + 0xfaf2fffbU == 0) {
    uVar2 = FUN_0053a2f0(*(undefined4 *)(param_1 + 0xc));
    return uVar2;
  }
  return iVar1 + 0xfaf2fffbU & 0xffffff00;
}


// ==== FUN_0053a540 @ 0x0053a540 ====

undefined4 FUN_0053a540(ushort param_1)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_1 < (ushort)(*(short *)(in_ECX + 6) - 0x10U) >> 2) {
    return *(undefined4 *)(in_ECX + 0x10 + (uint)param_1 * 4);
  }
  local_100[0] = 0;
  uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                       s_d__usa_24_0_1_2__develop_module__009b9998,0xe7);
  FUN_00797b80(uVar1);
  FUN_00797a40();
  return *(undefined4 *)(in_ECX + 0x10 + (uint)param_1 * 4);
}


// ==== FUN_0053a5c0 @ 0x0053a5c0 ====

undefined4 FUN_0053a5c0(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 extraout_EAX_02;
  undefined4 unaff_EBX;
  int *piVar6;
  undefined4 unaff_EBP;
  undefined1 uStack00000000;
  undefined4 local_20;
  void *pvStack_1c;
  uint uStack_8;
  
  uVar2 = *(undefined4 *)(param_1 + 0x14);
  piVar6 = (int *)0x0;
  local_20 = uVar2;
  (**(code **)(*DAT_00b5a97c + 0xc))();
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(uVar2);
  if (piVar1 == (int *)0x0) {
    FUN_00401740(s__________________________________009b9a30,0x23);
    uVar2 = FUN_00404230(&local_20);
    FUN_00796d50(uVar2);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return extraout_EAX;
    }
    FUN_00401740(s____Unhandled_Monster_Control_Pac_009b9a54,0x2c);
    uVar2 = FUN_00404230(&local_20);
    FUN_00796d50(uVar2);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return extraout_EAX_00;
    }
    FUN_00401740(s__________________________________009b9a84,0x23);
    uVar2 = FUN_00404230(&local_20);
    FUN_00796d50(uVar2);
    if (0xf < uStack_8) {
      _free(pvStack_1c);
      return extraout_EAX_01;
    }
  }
  else {
    iVar3 = (**(code **)(*piVar1 + 0xc))();
    if (iVar3 == 1) {
      piVar4 = (int *)(**(code **)(*piVar1 + 0x10))();
      (**(code **)(*piVar4 + 8))(&uStack00000000);
      piVar4[4] = (uint)*(byte *)(param_1 + 0x1b);
      piVar4[3] = (uint)*(byte *)(param_1 + 0x1a);
      (**(code **)(*piVar1 + 0x44))(unaff_EBP);
      piVar1 = (int *)(**(code **)(*piVar1 + 0x14))();
      iVar3 = (**(code **)(*piVar1 + 0x24))();
      if (*(int **)(iVar3 + 0x4c) != (int *)0x0) {
        piVar6 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
      }
      iVar3 = (**(code **)(*piVar6 + 0xc))();
      if (iVar3 == 8) {
        puVar5 = (undefined4 *)(**(code **)(*piVar6 + 0x10))();
        FUN_0053b370(unaff_EBP,*puVar5);
        return 1;
      }
    }
    else {
      iVar3 = (**(code **)(*piVar1 + 0xc))();
      if (iVar3 == 0xd) {
        (**(code **)(*piVar1 + 0x44))(unaff_EBX);
        return 1;
      }
      FUN_00401830(s__X_Controlled_by__X_009b9aa8);
      uVar2 = FUN_00404230(&local_20);
      FUN_00796d50(uVar2);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return extraout_EAX_02;
      }
    }
  }
  return 1;
}


// ==== FUN_0053a7f0 @ 0x0053a7f0 ====

uint FUN_0053a7f0(int param_1)

{
  uint uVar1;
  
  uVar1 = FUN_00424500();
  if (uVar1 == 0x50d0004) {
    uVar1 = FUN_0053a5c0(*(undefined4 *)(param_1 + 0xc));
    return uVar1;
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0053a830 @ 0x0053a830 ====

void FUN_0053a830(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9c1c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5af34 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5af34 = in_ECX;
  return;
}


// ==== FUN_0053a860 @ 0x0053a860 ====

undefined4 FUN_0053a860(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1[1] = param_2;
    *puVar1 = &PTR_FUN_009b9bcc;
    puVar1[2] = param_3;
    puVar1[3] = param_4;
  }
  FUN_0051b660(param_1,puVar1);
  return 1;
}


// ==== FUN_0053a8b0 @ 0x0053a8b0 ====

undefined4 FUN_0053a8b0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b9bec;
    puVar1[1] = param_1;
  }
  FUN_00797a20(puVar1);
  iVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (param_1 == iVar2) {
    (**(code **)(*DAT_00b5aca8 + 0xcc))();
    (**(code **)(*DAT_00b5ae3c + 0xa4))();
    (**(code **)(*DAT_00b5ae6c + 0x1c))();
  }
  return 1;
}


// ==== FUN_0053a920 @ 0x0053a920 ====

undefined4 FUN_0053a920(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if (((iVar2 == 0) || (iVar2 = (**(code **)(*piVar1 + 0xc))(), iVar2 == 4)) ||
     (iVar2 = (**(code **)(*piVar1 + 0xc))(), iVar2 == 2)) {
    return 1;
  }
  return 0;
}


// ==== FUN_0053a990 @ 0x0053a990 ====

undefined4 FUN_0053a990(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b2d88;
  }
  puVar1[1] = param_2;
  FUN_00403e60(puVar1 + 2,param_1,0x19);
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0053a9e0 @ 0x0053a9e0 ====

undefined4 FUN_0053a9e0(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    uRam00000004 = param_2;
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009b6f0c;
  puVar1[1] = param_2;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0053aa30 @ 0x0053aa30 ====

undefined4 FUN_0053aa30(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  puVar1[1] = param_1;
  puVar1[2] = param_2;
  *puVar1 = &PTR_FUN_009b9b8c;
  puVar1[3] = param_3;
  puVar1[4] = param_4;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0053aa80 @ 0x0053aa80 ====

undefined4 FUN_0053aa80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  puVar1[1] = param_1;
  *(undefined1 *)(puVar1 + 2) = param_4;
  *puVar1 = &PTR_FUN_009b9b74;
  puVar1[3] = param_2;
  puVar1[4] = param_3;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0053aad0 @ 0x0053aad0 ====

undefined4 FUN_0053aad0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if (iVar2 == 5) {
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = &PTR_FUN_009b9c04;
      puVar3[1] = param_1;
      puVar3[2] = param_1;
      FUN_00797a20(puVar3);
      return 1;
    }
  }
  else {
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = &PTR_FUN_009b9bb4;
      puVar3[1] = param_1;
      puVar3[2] = param_1;
      puVar3[3] = param_2;
      FUN_00797a20(puVar3);
      return 1;
    }
  }
  FUN_00797a20(0);
  return 1;
}


// ==== FUN_0053ab70 @ 0x0053ab70 ====

undefined1 FUN_0053ab70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  if (cVar1 == '\0') {
    return 0;
  }
  cVar1 = FUN_0053a920(param_2);
  if (cVar1 != '\0') {
    cVar1 = FUN_0053a920(param_3);
    if (cVar1 != '\0') {
      puVar2 = operator_new(0x10);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = &PTR_FUN_009b9b60;
      }
      puVar2[1] = param_1;
      puVar2[2] = param_2;
      puVar2[3] = param_3;
      FUN_00797a20(puVar2);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0053abf0 @ 0x0053abf0 ====

undefined4 FUN_0053abf0(char param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 == '\x01') {
    uVar2 = 2;
  }
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009b9b4c;
  puVar1[1] = uVar2;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0053ac40 @ 0x0053ac40 ====

undefined4 FUN_0053ac40(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009b9ba0;
  puVar1[1] = param_1;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0053ac80 @ 0x0053ac80 ====

undefined4 FUN_0053ac80(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    uRam00000004 = param_1;
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009b9b24;
  puVar1[1] = param_1;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0053acd0 @ 0x0053acd0 ====

undefined4 FUN_0053acd0(undefined4 *param_1,char param_2)

{
  undefined4 *puVar1;
  
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
  puVar1[1] = *param_1;
  *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(param_1 + 1);
  *(bool *)((int)puVar1 + 10) = param_2 == '\x01';
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0053ad30 @ 0x0053ad30 ====

undefined4 FUN_0053ad30(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  puVar1[2] = (float)param_1;
  puVar1[3] = (float)param_2;
  *puVar1 = &PTR_FUN_009b9b38;
  puVar1[1] = 0;
  puVar1[4] = (float)param_3;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_0053adb0 @ 0x0053adb0 ====

void FUN_0053adb0(undefined4 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5120003;
  *(undefined2 *)((int)pvVar2 + 6) = 0x14;
  iVar3 = FUN_004244d0();
  *(undefined4 *)(iVar3 + 0x10) = param_1;
  FUN_004d8570(iVar3);
  FUN_00401740(s_______________________Actor_Dele_009b9ad0,0x3c);
  uVar1 = FUN_00404230(auStack_1c);
  FUN_00796d50(uVar1);
  if (uStack_4 < 0x10) {
    return;
  }
  _free(pvStack_18);
  return;
}


// ==== FUN_0053ae50 @ 0x0053ae50 ====

undefined4 FUN_0053ae50(undefined4 param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 extraout_EAX;
  undefined1 local_20 [4];
  void *local_1c;
  undefined4 local_c;
  uint local_8;
  undefined1 local_4;
  
  local_8 = 0xf;
  local_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401660(param_3,0,0xffffffff);
  local_4 = param_2;
  puVar1 = operator_new(0x28);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009b9c24;
    puVar1[8] = 0xf;
    puVar1[7] = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
  }
  puVar1[1] = param_1;
  FUN_00401660(local_20,0,0xffffffff);
  *(undefined1 *)(puVar1 + 9) = local_4;
  FUN_00797a20(puVar1);
  if (local_8 < 0x10) {
    return 1;
  }
  _free(local_1c);
  return extraout_EAX;
}


// ==== FUN_0053af00 @ 0x0053af00 ====

undefined4 FUN_0053af00(void)

{
  return 0x50030000;
}


// ==== FUN_0053af10 @ 0x0053af10 ====

undefined4 FUN_0053af10(void)

{
  return 0x50030005;
}


// ==== FUN_0053af20 @ 0x0053af20 ====

undefined4 FUN_0053af20(void)

{
  return 0x50030006;
}


// ==== FUN_0053af30 @ 0x0053af30 ====

undefined4 FUN_0053af30(void)

{
  return 0x70350000;
}


// ==== FUN_0053af40 @ 0x0053af40 ====

undefined4 FUN_0053af40(void)

{
  return 0x30060022;
}


// ==== FUN_0053af50 @ 0x0053af50 ====

undefined4 FUN_0053af50(void)

{
  return 0x30060023;
}


// ==== FUN_0053af60 @ 0x0053af60 ====

undefined4 FUN_0053af60(void)

{
  return 0x30060100;
}


// ==== FUN_0053af70 @ 0x0053af70 ====

undefined4 FUN_0053af70(void)

{
  return 0x30060031;
}


// ==== FUN_0053af80 @ 0x0053af80 ====

undefined4 FUN_0053af80(void)

{
  return 0x30060032;
}


// ==== FUN_0053af90 @ 0x0053af90 ====

undefined4 FUN_0053af90(void)

{
  return 0x30060018;
}


// ==== FUN_0053afa0 @ 0x0053afa0 ====

undefined4 FUN_0053afa0(void)

{
  return 0x30060035;
}


// ==== FUN_0053afb0 @ 0x0053afb0 ====

void FUN_0053afb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9c1c;
  DAT_00b5af34 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053afe0 @ 0x0053afe0 ====

undefined4 FUN_0053afe0(void)

{
  return 0x7004000e;
}


// ==== FUN_0053aff0 @ 0x0053aff0 ====

void FUN_0053aff0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9c24;
  FUN_00446ee0();
  *in_ECX = &PTR_FUN_0099cf40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053b030 @ 0x0053b030 ====

void FUN_0053b030(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9c8c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5af30 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5af30 = in_ECX;
  return;
}


// ==== FUN_0053b060 @ 0x0053b060 ====

uint FUN_0053b060(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if ((param_1 < uVar1) && (uVar1 = uVar1 - param_1, param_2 < uVar1)) {
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0053b090 @ 0x0053b090 ====

undefined1 FUN_0053b090(undefined4 param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uStack_8;
  
  cVar1 = (**(code **)(*DAT_00b5acc0 + 0x2c))();
  if (cVar1 == '\0') {
    return 0;
  }
  uStack_8 = CONCAT31(uStack_8._1_3_,3);
  puVar2 = operator_new(0xc);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009b6f50;
  }
  puVar2[1] = uStack_8;
  puVar2[2] = param_1;
  FUN_00797a20(puVar2);
  return 1;
}


// ==== FUN_0053b0f0 @ 0x0053b0f0 ====

undefined4 FUN_0053b0f0(undefined4 param_1,undefined1 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if (iVar2 == 1) {
    uVar3 = (**(code **)(*piVar1 + 0x10))
                      (0,&Framework::ModelCenter::Actors::State::IActorState::RTTI_Type_Descriptor,
                       &Framework::ModelCenter::Actors::State::Monster::RTTI_Type_Descriptor,0);
    iVar2 = FUN_00803725(uVar3);
    *(undefined1 *)(iVar2 + 0x40) = param_2;
    *(undefined4 *)(iVar2 + 0x44) = param_1;
    return 1;
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if (iVar2 == 5) {
    uVar3 = (**(code **)(*piVar1 + 0x10))
                      (0,&Framework::ModelCenter::Actors::State::IActorState::RTTI_Type_Descriptor,
                       &Framework::ModelCenter::Actors::State::Brick::RTTI_Type_Descriptor,0);
    iVar2 = FUN_00803725(uVar3);
    *(undefined4 *)(iVar2 + 0x5c) = param_1;
  }
  return 1;
}


// ==== FUN_0053b180 @ 0x0053b180 ====

bool FUN_0053b180(ushort param_1,ushort param_2)

{
  char cVar1;
  uint local_8;
  uint local_4;
  
  local_8 = (uint)param_1;
  local_4 = (uint)param_2;
  cVar1 = (**(code **)(*DAT_00b5af50 + 0x14))(&local_8);
  return cVar1 == '\0';
}


// ==== FUN_0053b1b0 @ 0x0053b1b0 ====

undefined4 FUN_0053b1b0(int param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*DAT_00b5af10 + 0xc))();
  cVar1 = (**(code **)(*DAT_00b5acd8 + 8))(param_1);
  if (cVar1 == '\0') {
    FUN_0053ac40(param_1);
  }
  if (param_1 == iVar2) {
    (**(code **)(*DAT_00b5af10 + 0x14))();
    (**(code **)(*DAT_00b5ae90 + 0x10))();
  }
  return 1;
}


// ==== FUN_0053b220 @ 0x0053b220 ====

undefined4
FUN_0053b220(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int unaff_retaddr;
  undefined4 auStack_8 [2];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  auStack_8[0] = param_5;
  piVar1 = (int *)(**(code **)(*piVar1 + 0x30))(auStack_8);
  if (piVar1 != (int *)0x0) {
    if (*(int *)(*piVar1 + 4) == 0) {
      return 0;
    }
    if (unaff_retaddr == 2) {
      iVar2 = FUN_0053b6b0(param_1,param_3);
      *(int *)(iVar2 + 0xc) = param_2 - param_1;
LAB_0053b290:
      (**(code **)(*DAT_00b5a804 + 0xc))(param_5,iVar2);
      (**(code **)(*DAT_00b5a70c + 0x10))(1,iVar2);
      return 1;
    }
    if (unaff_retaddr == 5) {
      iVar2 = FUN_0053b6e0(param_1,param_3);
    }
    else if ((unaff_retaddr == 0) || (unaff_retaddr == 7)) {
      iVar2 = FUN_0053b710(param_1,param_3);
      *(int *)(iVar2 + 0xc) = param_2 - param_1;
      *(undefined4 *)(iVar2 + 0x10) = param_5;
    }
    else {
      if (unaff_retaddr == 3) {
        iVar2 = FUN_0053b740(param_1,param_3);
        *(undefined4 *)(iVar2 + 0xc) = 0;
        goto LAB_0053b290;
      }
      if (unaff_retaddr != 4) {
        return 1;
      }
      iVar2 = FUN_0053b740(param_1,param_3);
      *(int *)(iVar2 + 0xc) = param_2 - param_1;
    }
    (**(code **)(*DAT_00b5a804 + 0xc))(param_5,iVar2);
    (**(code **)(*DAT_00b5a70c + 0x10))(1,iVar2);
  }
  return 1;
}


// ==== FUN_0053b370 @ 0x0053b370 ====

undefined4 FUN_0053b370(void)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  *puVar1 = 7;
  puVar1[1] = unaff_retaddr;
  puVar1[2] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_ESI,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return 1;
}


// ==== FUN_0053b3c0 @ 0x0053b3c0 ====

undefined4 FUN_0053b3c0(void)

{
  undefined4 *puVar1;
  undefined4 unaff_ESI;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
  *puVar1 = 9;
  puVar1[1] = unaff_retaddr;
  puVar1[2] = unaff_ESI;
  (**(code **)(*DAT_00b5a804 + 0xc))(unaff_ESI,puVar1);
  (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar1);
  return 1;
}


// ==== FUN_0053b410 @ 0x0053b410 ====

undefined4 FUN_0053b410(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  undefined1 auStack_2a [2];
  int aiStack_28 [2];
  undefined1 auStack_20 [32];
  
  iVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (param_1 == iVar2) {
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = &PTR_FUN_009b6f3c;
    }
    uVar4 = FUN_004f4d60();
    FUN_00403e60(puVar3 + 1,param_2,uVar4);
    FUN_00797a20(puVar3);
    return 1;
  }
  piVar5 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  piVar6 = (int *)(**(code **)(*piVar5 + 0x18))();
  if (piVar6 == (int *)0x0) {
    return 0;
  }
  cVar1 = (**(code **)(*piVar6 + 8))();
  if (cVar1 == '\0') {
    return 0;
  }
  iVar2 = (**(code **)(*piVar5 + 0xc))();
  if (iVar2 == 1) {
    uVar4 = (**(code **)(*piVar5 + 0x14))
                      (0,&Framework::ModelCenter::Actors::Info::IActorInfo::RTTI_Type_Descriptor,
                       &Framework::ModelCenter::Actors::Info::Monster::RTTI_Type_Descriptor,0);
    iVar2 = FUN_00803725(uVar4);
    if (iVar2 == 0) {
      FUN_00401830(s_pInfo____NULL_009b9c38);
      FUN_00406880(auStack_20);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    cVar1 = FUN_00529900();
  }
  else {
    iVar2 = (**(code **)(*piVar5 + 0xc))();
    if (iVar2 != 2) goto LAB_0053b55a;
    uVar4 = (**(code **)(*piVar5 + 0x14))
                      (0,&Framework::ModelCenter::Actors::Info::IActorInfo::RTTI_Type_Descriptor,
                       &Framework::ModelCenter::Actors::Info::Servant::RTTI_Type_Descriptor,0);
    iVar2 = FUN_00803725(uVar4);
    if (iVar2 == 0) {
      FUN_00401830(s_pInfo____NULL_009b9c48);
      FUN_00406880(auStack_20);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    cVar1 = FUN_0052dbb0();
  }
  if (cVar1 == '\0') {
    return 0;
  }
LAB_0053b55a:
  piVar5 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar5 != (int *)0x0) {
    aiStack_28[0] = param_1;
    piVar5 = (int *)(**(code **)(*piVar5 + 0x30))(aiStack_28);
    if ((piVar5 != (int *)0x0) && (piVar5 = *(int **)(*piVar5 + 4), piVar5 != (int *)0x0)) {
      (**(code **)(*piVar5 + 0x30))();
      (**(code **)(*piVar5 + 0x2c))(auStack_2a + -10);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0053b5d0 @ 0x0053b5d0 ====

undefined4 FUN_0053b5d0(int param_1)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 extraout_EAX;
  undefined4 uVar5;
  undefined4 uStack_1c;
  uint uStack_8;
  
  iVar2 = (**(code **)(*DAT_00b5af10 + 0xc))();
  piVar3 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
  if (piVar3 == (int *)0x0) {
    FUN_0053ac40(param_1);
    return 1;
  }
  iVar4 = (**(code **)(*piVar3 + 0xc))();
  if (iVar4 != 5) {
    (**(code **)(*DAT_00b5acd8 + 8))(param_1);
    if (param_1 == iVar2) {
      (**(code **)(*DAT_00b5af10 + 0x14))();
      (**(code **)(*DAT_00b5ae90 + 0x10))();
    }
    return 1;
  }
  iVar2 = FUN_00803725(piVar3,0,&Framework::ModelCenter::Actors::IActor::RTTI_Type_Descriptor,
                       &Framework::ModelCenter::Actors::Brick::RTTI_Type_Descriptor,0);
  if (iVar2 != 0) {
    FUN_0052fc90();
    return 1;
  }
  FUN_00401830(s_pBrick____NULL_009b9c58);
  FUN_00406880((int)register0x00000010 + -0x20);
  if (uStack_8 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar5 = (*pcVar1)();
    return uVar5;
  }
  _free(uStack_1c);
  return extraout_EAX;
}


// ==== FUN_0053b6b0 @ 0x0053b6b0 ====

void FUN_0053b6b0(void)

{
  undefined4 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1);
  *puVar1 = 2;
  puVar1[1] = 0;
  puVar1[2] = unaff_retaddr;
  return;
}


// ==== FUN_0053b6e0 @ 0x0053b6e0 ====

void FUN_0053b6e0(void)

{
  undefined4 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1);
  *puVar1 = 4;
  puVar1[1] = 0;
  puVar1[2] = unaff_retaddr;
  return;
}


// ==== FUN_0053b710 @ 0x0053b710 ====

void FUN_0053b710(void)

{
  undefined4 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1);
  *puVar1 = 1;
  puVar1[1] = 0;
  puVar1[2] = unaff_retaddr;
  return;
}


// ==== FUN_0053b740 @ 0x0053b740 ====

void FUN_0053b740(void)

{
  undefined4 *puVar1;
  undefined4 unaff_retaddr;
  
  puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1);
  *puVar1 = 3;
  puVar1[1] = 0;
  puVar1[2] = unaff_retaddr;
  return;
}


// ==== FUN_0053b770 @ 0x0053b770 ====

void FUN_0053b770(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9c8c;
  DAT_00b5af30 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053b7c0 @ 0x0053b7c0 ====

void FUN_0053b7c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9cc0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_0053b7e0 @ 0x0053b7e0 ====

void FUN_0053b7e0(void)

{
  int *piVar1;
  char cVar2;
  char *pcVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  char *pcVar7;
  int iVar8;
  undefined4 uVar9;
  int in_ECX;
  int iVar10;
  uint uVar11;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined1 *puVar14;
  undefined2 uVar16;
  undefined4 uVar15;
  undefined4 uStack_128;
  char *pcStack_124;
  undefined1 *puStack_120;
  undefined1 local_e4 [4];
  undefined1 local_e0;
  char acStack_dc [28];
  void *pvStack_c0;
  undefined2 uStack_ba;
  undefined2 uStack_b8;
  undefined1 uStack_b4;
  undefined1 uStack_b3;
  char acStack_b0 [4];
  uint uStack_ac;
  undefined1 auStack_84 [12];
  char local_78 [26];
  undefined4 local_5e [11];
  undefined1 local_32;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_1c [5];
  undefined1 uStack_7;
  undefined1 local_2;
  
  iVar8 = *(int *)(in_ECX + 4);
  local_78[0] = '\0';
  puVar12 = (undefined4 *)(iVar8 + 0x14);
  puVar13 = local_5e;
  for (iVar10 = 0xb; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar13 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
  }
  local_32 = *(undefined1 *)(iVar8 + 0x40);
  iVar10 = *(int *)(in_ECX + 8);
  local_2 = *(undefined1 *)(iVar8 + 0x4c);
  local_30 = (uint)*(byte *)(iVar8 + 0x41);
  local_2c = *(undefined4 *)(iVar10 + 0x14);
  local_28 = *(undefined4 *)(iVar10 + 0x18);
  local_24 = *(uint *)(iVar10 + 0x1c);
  if (*(ushort *)(iVar8 + 6) < 0x71) {
    iVar10 = 0;
  }
  else {
    iVar10 = iVar8 + 0x70;
  }
  uVar11 = 0;
  do {
    cVar2 = (local_78 + uVar11)[iVar10 - (int)local_78];
    local_78[uVar11] = cVar2;
    if (cVar2 == '\0') goto LAB_0053b883;
    uVar11 = uVar11 + 1;
  } while (uVar11 < 0x19);
  local_78[0] = '\0';
LAB_0053b883:
  puVar12 = (undefined4 *)(*(int *)(in_ECX + 0xc) + 0x14);
  puVar13 = local_1c;
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    *puVar13 = *puVar12;
    puVar12 = puVar12 + 1;
    puVar13 = puVar13 + 1;
  }
  *(undefined1 *)puVar13 = *(undefined1 *)puVar12;
  pcStack_124 = (char *)(iVar8 + 0x4d);
  acStack_dc[0x10] = '\x0f';
  acStack_dc[0x11] = '\0';
  acStack_dc[0x12] = '\0';
  acStack_dc[0x13] = '\0';
  acStack_dc[0xc] = '\0';
  acStack_dc[0xd] = '\0';
  acStack_dc[0xe] = '\0';
  acStack_dc[0xf] = '\0';
  local_e0 = 0;
  pcVar3 = pcStack_124;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  puStack_120 = (undefined1 *)((int)pcVar3 - (iVar8 + 0x4e));
  uStack_128 = 0x53b8c9;
  FUN_00401740();
  puStack_120 = local_e4;
  pcStack_124 = (char *)0x53b8d9;
  cVar2 = (**(code **)(*DAT_00b5acac + 0x34))();
  if (cVar2 == '\0') {
    uStack_7 = 0;
  }
  else {
    uStack_7 = *(undefined1 *)(*(int *)(in_ECX + 4) + 0x42);
  }
  pcStack_124 = (char *)0x53b8ff;
  cVar2 = (**(code **)(*DAT_00b5ac1c + 0x24))();
  if (cVar2 == '\x01') {
    local_24 = *(uint *)(*(int *)(in_ECX + 8) + 0x20);
  }
  else {
    local_24 = local_24 & 0xff000000;
  }
  pcStack_124 = (char *)0x0;
  uStack_128 = 1;
  piVar4 = (int *)(**(code **)(*DAT_00b5a754 + 0xc))();
  iVar8 = *piVar4;
  puVar14 = auStack_84;
  piVar5 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))(puVar14);
  uVar16 = (undefined2)((uint)puVar14 >> 0x10);
  (**(code **)(iVar8 + 0x18))();
  piVar4[0x2b] = *(int *)(*(int *)(in_ECX + 4) + 0x10);
  iVar8 = *(int *)(in_ECX + 4);
  acStack_dc[0] = '\0';
  uStack_b8 = *(undefined2 *)(iVar8 + 0x46);
  uStack_ba = *(undefined2 *)(iVar8 + 0x44);
  pcVar3 = (char *)(iVar8 + 0x4d);
  pcVar7 = acStack_b0;
  for (iVar10 = 8; iVar10 != 0; iVar10 = iVar10 + -1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar3;
    pcVar3 = pcVar3 + 4;
    pcVar7 = pcVar7 + 4;
  }
  *pcVar7 = *pcVar3;
  uVar11 = 0;
  do {
    acStack_dc[uVar11] = acStack_b0[uVar11];
    if (acStack_b0[uVar11] == '\0') goto LAB_0053b9ac;
    uVar11 = uVar11 + 1;
  } while (uVar11 < 0x21);
  acStack_dc[0] = '\0';
LAB_0053b9ac:
  uStack_b3 = *(undefined1 *)(iVar8 + 0x4b);
  uStack_b4 = *(undefined1 *)(iVar8 + 0x4a);
  (**(code **)(*piVar4 + 0x20))(acStack_dc);
  uStack_128 = (**(code **)(*DAT_00b5adf8 + 4))(*(undefined4 *)(*(int *)(in_ECX + 4) + 0x10),piVar4)
  ;
  cVar2 = (**(code **)(*DAT_00b5acd8 + 4))(*(undefined4 *)(*(int *)(in_ECX + 4) + 0x10),uStack_128);
  piVar1 = DAT_00b5a6c0;
  if (cVar2 == '\0') {
    FUN_00401740(s_New_Enter___PC___08X___009b9c94,0x16);
    uVar6 = FUN_00404230(acStack_dc + 0x18);
    (**(code **)(*piVar1 + 4))(2,uVar6);
    if (0xf < uStack_ac) {
      _free(pvStack_c0);
      return;
    }
  }
  uVar6 = *(undefined4 *)(*(int *)(in_ECX + 4) + 0x10);
  uVar15 = CONCAT22(uVar16,*(undefined2 *)(*(int *)(in_ECX + 4) + 0x48));
  uVar11 = 0;
  pcStack_124 = (char *)((uint)pcStack_124 & 0xffffff00);
  FUN_00401740(s_New_Enter___PC___08X___009b9c94 + 0x17,0);
  iVar8 = *(int *)(in_ECX + 0xc);
  if ((0x30 < *(ushort *)(iVar8 + 6)) && (pcVar3 = (char *)(iVar8 + 0x30), pcVar3 != (char *)0x0)) {
    pcVar7 = pcVar3;
    do {
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    FUN_00401740(pcVar3,(int)pcVar7 - (iVar8 + 0x31));
  }
  piVar4 = (int *)(**(code **)(*(int *)piVar4[0x13] + 0x14))();
  iVar8 = (**(code **)(*piVar4 + 0x10))();
  if (*(char *)(iVar8 + 0xb) == '\x11') {
    uVar11 = (uint)*(byte *)(iVar8 + 0xc);
  }
  FUN_0053ae50(uVar6,uVar11,&uStack_128);
  piVar4 = (int *)(**(code **)(*piVar5 + 0x14))();
  uVar9 = (**(code **)(*piVar4 + 0x24))();
  uVar11 = 0;
  do {
    cVar2 = *(char *)(*(int *)(in_ECX + 8) + 0x24 + uVar11);
    if (cVar2 != '\0') {
      FUN_00826b20(uVar9,cVar2);
      FUN_004dd240(0x13,cVar2,0,2,uVar6);
    }
    uVar11 = uVar11 + 1;
  } while (uVar11 < 8);
  (**(code **)(*DAT_00b5aca8 + 0x7c))(uVar6,uVar15);
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    _free(*(void **)(in_ECX + 8));
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0053bbf0 @ 0x0053bbf0 ====

undefined4 FUN_0053bbf0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = FUN_00424500();
  if (iVar2 == 0x5070000) {
    uVar1 = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(in_ECX + 0xc) = uVar1;
    FUN_0053b7e0();
    return 1;
  }
  if (iVar2 == 0x5080000) {
    uVar1 = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(in_ECX + 4) = uVar1;
    return 1;
  }
  if (iVar2 == 0x5090000) {
    uVar1 = *(undefined4 *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(in_ECX + 8) = uVar1;
    return 1;
  }
  return 0;
}


// ==== FUN_0053bc60 @ 0x0053bc60 ====

void FUN_0053bc60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b6e88;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053bc80 @ 0x0053bc80 ====

void FUN_0053bc80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9ce0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053bcb0 @ 0x0053bcb0 ====

undefined2 FUN_0053bcb0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 4);
}


// ==== FUN_0053bcc0 @ 0x0053bcc0 ====

void FUN_0053bcc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9cf4;
  *(undefined2 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 0x19) = 0;
  return;
}


// ==== FUN_0053bce0 @ 0x0053bce0 ====

undefined4 FUN_0053bce0(undefined4 param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  float *pfVar9;
  int in_ECX;
  undefined2 uStack_4;
  
  piVar4 = (int *)(**(code **)(*DAT_00b5ab48 + 8))(param_1);
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  iVar5 = (**(code **)(*piVar4 + 4))();
  *(undefined1 *)(in_ECX + 0x18) = *(undefined1 *)(iVar5 + 10);
  iVar5 = *DAT_00b5ab34;
  iVar6 = (**(code **)(*piVar4 + 4))();
  piVar7 = (int *)(**(code **)(iVar5 + 8))(*(undefined2 *)(iVar6 + 2));
  if (piVar7 == (int *)0x0) {
    return 0;
  }
  *(undefined2 *)(in_ECX + 4) = uStack_4;
  iVar5 = (**(code **)(*piVar7 + 4))();
  uVar1 = *(ushort *)(iVar5 + 0x104);
  iVar5 = (**(code **)(*piVar7 + 4))();
  uVar2 = *(ushort *)(iVar5 + 0x106);
  iVar5 = (**(code **)(*piVar4 + 4))();
  uVar3 = *(ushort *)(iVar5 + 4);
  iVar5 = (**(code **)(*piVar4 + 4))();
  uVar8 = (uint)*(ushort *)(iVar5 + 6);
  *(uint *)(in_ECX + 8) = (uint)uVar1;
  *(uint *)(in_ECX + 0xc) = (uint)uVar2;
  *(uint *)(in_ECX + 0x10) = (uint)uVar1 + (uint)uVar3;
  *(uint *)(in_ECX + 0x14) = *(int *)(in_ECX + 0xc) + uVar8;
  if (DAT_00b5a97c != (int *)0x0) {
    piVar4 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    pfVar9 = (float *)(**(code **)(*piVar4 + 0x28))();
    uVar8 = (uint)pfVar9[1];
    if ((((*(int *)(in_ECX + 8) <= (int)*pfVar9) && (*(int *)(in_ECX + 0xc) <= (int)uVar8)) &&
        ((int)*pfVar9 < *(int *)(in_ECX + 0x10))) && ((int)uVar8 < *(int *)(in_ECX + 0x14))) {
      *(undefined1 *)(in_ECX + 0x19) = 1;
      return CONCAT31((int3)(uVar8 >> 8),1);
    }
  }
  *(undefined1 *)(in_ECX + 0x19) = 0;
  return CONCAT31((int3)(uVar8 >> 8),1);
}


// ==== FUN_0053bdf0 @ 0x0053bdf0 ====

void FUN_0053bdf0(void)

{
  char cVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  int *in_ECX;
  undefined1 auStack_1ea [26];
  undefined1 auStack_1d0 [464];
  
  cVar1 = (**(code **)(*DAT_00b5ae58 + 8))();
  if (cVar1 == '\0') {
    if ((char)in_ECX[6] == '\0') {
      pvVar4 = operator_new(0x400);
      *(undefined4 *)((int)pvVar4 + 8) = 0;
      *(undefined4 *)((int)pvVar4 + 0xc) = 0x5160000;
      *(undefined2 *)((int)pvVar4 + 6) = 0x14;
      iVar5 = FUN_004244d0();
      uVar2 = (**(code **)(*in_ECX + 8))();
      *(undefined2 *)(iVar5 + 0x10) = uVar2;
      FUN_004d8570(iVar5);
      (**(code **)(*DAT_00b5ac2c + 4))(1);
    }
    else if (DAT_00b5acac != (int *)0x0) {
      uVar3 = (**(code **)(*DAT_00b5acac + 0xc))(auStack_1d0);
      FUN_00401660(uVar3,0,0xffffffff);
      FUN_00537c20();
      if ((DAT_00b5ac98 == (int *)0x0) ||
         (cVar1 = (**(code **)(*DAT_00b5ac98 + 0x14))(auStack_1ea + -6), cVar1 != '\0')) {
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
  }
  return;
}


// ==== FUN_0053bee0 @ 0x0053bee0 ====

void FUN_0053bee0(void)

{
  int *piVar1;
  float *pfVar2;
  int in_ECX;
  char cVar3;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  pfVar2 = (float *)(**(code **)(*piVar1 + 0x28))();
  if (((((int)*pfVar2 < *(int *)(in_ECX + 8)) || ((int)pfVar2[1] < *(int *)(in_ECX + 0xc))) ||
      (*(int *)(in_ECX + 0x10) <= (int)*pfVar2)) || (*(int *)(in_ECX + 0x14) <= (int)pfVar2[1])) {
    cVar3 = '\0';
  }
  else {
    cVar3 = '\x01';
  }
  if (*(char *)(in_ECX + 0x19) != cVar3) {
    if (cVar3 == '\x01') {
      FUN_0053bdf0();
    }
    *(char *)(in_ECX + 0x19) = cVar3;
  }
  return;
}


// ==== FUN_0053bf40 @ 0x0053bf40 ====

uint FUN_0053bf40(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_0053bee0(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_0053bf70 @ 0x0053bf70 ====

uint FUN_0053bf70(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *param_1;
  if ((((iVar1 < *in_ECX) || (param_1 = (int *)param_1[1], (int)param_1 < in_ECX[1])) ||
      (in_ECX[2] <= iVar1)) || (in_ECX[3] <= (int)param_1)) {
    return (uint)param_1 & 0xffffff00;
  }
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}


// ==== FUN_0053bfa0 @ 0x0053bfa0 ====

void FUN_0053bfa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9d08;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053bfc0 @ 0x0053bfc0 ====

void FUN_0053bfc0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0053bfc0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0053c000 @ 0x0053c000 ====

void * FUN_0053c000(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981930;
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


// ==== Catch@0053c075 @ 0x0053c075 ====

void Catch_0053c075(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0053c090 @ 0x0053c090 ====

void FUN_0053c090(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00981940;
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


// ==== Catch@0053c11a @ 0x0053c11a ====

void Catch_0053c11a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_0053c130 @ 0x0053c130 ====

undefined4 FUN_0053c130(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char cVar5;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 8);
  puVar2 = (undefined4 *)*puVar1;
  while( true ) {
    if (puVar2 == puVar1) {
      return 0;
    }
    cVar5 = (**(code **)(*(int *)puVar2[4] + 0xc))(param_1);
    if (cVar5 != '\0') break;
    if (*(char *)((int)puVar2 + 0x15) == '\0') {
      puVar3 = (undefined4 *)puVar2[2];
      if (*(char *)((int)puVar3 + 0x15) == '\0') {
        cVar5 = *(char *)((int)*puVar3 + 0x15);
        puVar2 = puVar3;
        puVar3 = (undefined4 *)*puVar3;
        while (cVar5 == '\0') {
          cVar5 = *(char *)((int)*puVar3 + 0x15);
          puVar2 = puVar3;
          puVar3 = (undefined4 *)*puVar3;
        }
      }
      else {
        cVar5 = *(char *)((int)puVar2[1] + 0x15);
        puVar4 = (undefined4 *)puVar2[1];
        puVar3 = puVar2;
        while ((puVar2 = puVar4, cVar5 == '\0' && (puVar3 == (undefined4 *)puVar2[2]))) {
          cVar5 = *(char *)((int)puVar2[1] + 0x15);
          puVar4 = (undefined4 *)puVar2[1];
          puVar3 = puVar2;
        }
      }
    }
  }
  return 1;
}


// ==== FUN_0053c1b0 @ 0x0053c1b0 ====

undefined4 FUN_0053c1b0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_006e5150(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 8)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0x10);
}


// ==== FUN_0053c1e0 @ 0x0053c1e0 ====

undefined4 FUN_0053c1e0(int *param_1)

{
  int *piVar1;
  int *piVar2;
  uint in_ECX;
  uint uStack_4;
  
  piVar2 = param_1;
  uStack_4 = in_ECX;
  param_1 = (int *)(**(code **)(*param_1 + 8))();
  FUN_006e5150(&uStack_4,&param_1);
  if ((uStack_4 == *(uint *)(in_ECX + 8)) || (piVar1 = *(int **)(uStack_4 + 0x10), piVar1 != piVar2)
     ) {
    return 0;
  }
  FUN_0051a2a0(&param_1,uStack_4);
  if (piVar1 != (int *)0x0) {
    (**(code **)*piVar1)(1);
  }
  return 1;
}


// ==== FUN_0053c250 @ 0x0053c250 ====

undefined4 FUN_0053c250(int *param_1)

{
  int *piVar1;
  undefined2 uVar2;
  int in_ECX;
  uint uStack_10;
  int *piStack_c;
  undefined1 auStack_8 [8];
  
  piVar1 = param_1;
  param_1 = (int *)(**(code **)(*param_1 + 8))();
  FUN_006e5150(&uStack_10,&param_1);
  if (uStack_10 == *(uint *)(in_ECX + 8)) {
    uVar2 = (**(code **)(*piVar1 + 8))();
    uStack_10 = CONCAT22(uStack_10._2_2_,uVar2);
    piStack_c = piVar1;
    FUN_0053c640(auStack_8,&uStack_10);
    return 1;
  }
  return 0;
}


// ==== FUN_0053c2c0 @ 0x0053c2c0 ====

void FUN_0053c2c0(void)

{
  undefined4 *in_ECX;
  undefined4 *local_4;
  
  *in_ECX = &PTR_FUN_009b9d20;
  local_4 = in_ECX;
  if (in_ECX[3] != 0) {
    local_4 = (undefined4 *)((uint)in_ECX & 0xffffff00);
    FUN_00409660(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2],local_4);
    FUN_0053bfc0(*(undefined4 *)(in_ECX[2] + 4));
    *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
    in_ECX[3] = 0;
    *(undefined4 *)in_ECX[2] = in_ECX[2];
    *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  }
  DAT_00b5ae10 = 0;
  FUN_0053c580(&local_4,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0053c350 @ 0x0053c350 ====

void FUN_0053c350(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9d20;
  iVar1 = FUN_0053c090();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae10 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae10 = in_ECX;
  return;
}


// ==== FUN_0053c3a0 @ 0x0053c3a0 ====

void FUN_0053c3a0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_0053c000(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_0053c4a5:
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
      if ((char)piVar6[5] == '\0') goto LAB_0053c4a5;
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


// ==== FUN_0053c580 @ 0x0053c580 ====

void FUN_0053c580(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0053bfc0(piVar6[1]);
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


// ==== FUN_0053c640 @ 0x0053c640 ====

void FUN_0053c640(undefined4 *param_1,ushort *param_2)

{
  undefined4 uVar1;
  ushort *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  bool bVar5;
  
  puVar2 = param_2;
  puVar4 = *(undefined4 **)(in_ECX + 4);
  bVar5 = true;
  if (*(char *)((int)puVar4[1] + 0x15) == '\0') {
    puVar3 = (undefined4 *)puVar4[1];
    do {
      puVar4 = puVar3;
      bVar5 = *param_2 < *(ushort *)(puVar4 + 3);
      if (bVar5) {
        puVar3 = (undefined4 *)*puVar4;
      }
      else {
        puVar3 = (undefined4 *)puVar4[2];
      }
    } while (*(char *)((int)puVar3 + 0x15) == '\0');
  }
  param_2 = (ushort *)puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_0053c3a0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (*(ushort *)((int)param_2 + 0xc) < *puVar2) {
    puVar4 = (undefined4 *)FUN_0053c3a0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0053c700 @ 0x0053c700 ====

void FUN_0053c700(byte param_1)

{
  void *in_ECX;
  
  FUN_0053c2c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053c730 @ 0x0053c730 ====

undefined4 FUN_0053c730(undefined4 param_1)

{
  int in_ECX;
  undefined4 uVar1;
  undefined1 local_12 [6];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *(undefined4 *)(in_ECX + 0x18);
  local_8 = *(undefined4 *)(in_ECX + 0x1c);
  local_4 = 0;
  uVar1 = param_1;
  FUN_004ef0e0(local_12);
  FUN_005e0c90(uVar1);
  return param_1;
}


// ==== FUN_0053c780 @ 0x0053c780 ====

float10 FUN_0053c780(void)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(in_ECX + 0x18);
  return fVar1 + (float10)*(float *)(in_ECX + 0x30);
}


// ==== FUN_0053c7a0 @ 0x0053c7a0 ====

void FUN_0053c7a0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar2 = DAT_0099d0b4;
  uVar1 = DAT_0099d080;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *in_ECX = &PTR_FUN_009b9d4c;
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


// ==== FUN_0053c820 @ 0x0053c820 ====

void FUN_0053c820(undefined2 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined2 *)(in_ECX + 0x3c);
  return;
}


// ==== FUN_0053c830 @ 0x0053c830 ====

void FUN_0053c830(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x3c) = *param_1;
  return;
}


// ==== FUN_0053c840 @ 0x0053c840 ====

float10 FUN_0053c840(void)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(in_ECX + 0x18);
  return fVar1 + (float10)*(float *)(in_ECX + 0x30) + (float10)DAT_0099d0b4;
}


// ==== FUN_0053c860 @ 0x0053c860 ====

void FUN_0053c860(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar2 = DAT_009a000c;
  uVar1 = DAT_0099d080;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *in_ECX = &PTR_FUN_009b9da4;
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


// ==== FUN_0053c8d0 @ 0x0053c8d0 ====

void FUN_0053c8d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9e4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053c8f0 @ 0x0053c8f0 ====

void FUN_0053c8f0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_0053c910 @ 0x0053c910 ====

void FUN_0053c910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9e68;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_0053c950 @ 0x0053c950 ====

void FUN_0053c950(undefined4 param_1,undefined1 param_2)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 8) = param_1;
  *(undefined1 *)(in_ECX + 4) = param_2;
  return;
}


// ==== FUN_0053c990 @ 0x0053c990 ====

void FUN_0053c990(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10)

{
  int in_ECX;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_2c = *(undefined4 *)(in_ECX + 0x30);
  local_28 = param_1;
  local_20 = param_3;
  local_24 = param_2;
  local_1c = param_4;
  local_14 = param_6;
  local_18 = param_5;
  local_10 = param_7;
  local_8 = param_9;
  local_c = param_8;
  local_4 = param_10;
  (**(code **)(*DAT_00b5af38 + 4))(&local_2c);
  return;
}


// ==== FUN_0053cac0 @ 0x0053cac0 ====

void FUN_0053cac0(ushort param_1,undefined2 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar1 = iVar1 - param_4;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  (**(code **)(*DAT_00b5ac70 + 0xc))
            (*(undefined4 *)(in_ECX + 0x30),param_1 | 0x640000,param_2,param_3,iVar1,1);
  return;
}


// ==== FUN_0053cb10 @ 0x0053cb10 ====

void FUN_0053cb10(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  param_1 = iVar1 - param_1;
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (param_2 == 0) {
    param_2 = 1000;
  }
  if (param_2 < param_1) {
    param_1 = param_1 % param_2;
  }
  *(int *)(in_ECX + 0x28) = (param_2 - param_1) + iVar1;
  *(int *)(in_ECX + 0x2c) = param_2;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  return;
}


// ==== FUN_0053cb60 @ 0x0053cb60 ====

undefined4 FUN_0053cb60(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uVar3 = *(uint *)(in_ECX + 0x28);
  if (*(char *)(in_ECX + 0x24) == '\0') {
    if (uVar3 - 300 <= uVar2) {
      *(undefined1 *)(in_ECX + 0x24) = 1;
      return 1;
    }
  }
  else if (uVar3 <= uVar2) {
    uVar3 = uVar2 - uVar3;
    uVar1 = *(uint *)(in_ECX + 0x2c);
    if (uVar1 < uVar3) {
      uVar3 = uVar3 % uVar1;
      *(uint *)(in_ECX + 0x28) = uVar2;
    }
    *(int *)(in_ECX + 0x28) = *(int *)(in_ECX + 0x28) + (uVar1 - uVar3);
    *(undefined1 *)(in_ECX + 0x24) = 0;
  }
  return 0;
}


// ==== FUN_0053cbc0 @ 0x0053cbc0 ====

undefined4 FUN_0053cbc0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if (*(int *)(in_ECX + 0x10) - 100U < uVar1) {
    return 1;
  }
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    *(undefined4 *)(in_ECX + 0x34) = uRam00000018;
    *(undefined4 *)(in_ECX + 0x38) = uRam0000001c;
    return 0;
  }
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(iVar2 + 0x18);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(iVar2 + 0x1c);
  return 0;
}


// ==== FUN_0053cc10 @ 0x0053cc10 ====

void FUN_0053cc10(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 6) != '\x01') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5120003;
    *(undefined2 *)((int)pvVar2 + 6) = 0x14;
    iVar3 = FUN_004244d0();
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar1 = (**(code **)(*piVar4 + 8))();
    *(undefined4 *)(iVar3 + 0x10) = uVar1;
    FUN_004d8570(iVar3);
    *(undefined1 *)(in_ECX + 6) = 1;
  }
  return;
}


// ==== FUN_0053cc80 @ 0x0053cc80 ====

void FUN_0053cc80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9e68;
  (**(code **)(*DAT_00b5af38 + 8))(in_ECX[0xc]);
  *in_ECX = &PTR_FUN_009b9e4c;
  return;
}


// ==== FUN_0053cca0 @ 0x0053cca0 ====

void FUN_0053cca0(void)

{
  int iVar1;
  float fVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  float *pfVar8;
  int in_ECX;
  undefined2 extraout_var;
  int iStack_30;
  int iStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  int iStack_14;
  float fStack_10;
  undefined4 uStack_c;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  }
  uVar5 = (**(code **)(*piVar4 + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IRemote::RTTI_Type_Descriptor,0);
  piVar4 = (int *)FUN_00803725(uVar5);
  if (piVar4 != (int *)0x0) {
    iVar6 = (**(code **)(*piVar4 + 0x1c))();
    *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(iVar6 + 0x24);
    iVar6 = (**(code **)(*piVar4 + 0x24))();
    piVar7 = (int *)0x0;
    if ((int *)piVar4[0x13] != (int *)0x0) {
      piVar7 = (int *)(**(code **)(*(int *)piVar4[0x13] + 0x18))();
    }
    (**(code **)(*piVar7 + 8))(0);
    piVar4 = (int *)(**(code **)(*piVar7 + 0x10))();
    if (*(int **)(in_ECX + 8) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar5 = FUN_0053f080();
    *(undefined4 *)(in_ECX + 0x18) = uVar5;
    *(int *)(in_ECX + 0x1c) = piVar4[3];
    *(uint *)(in_ECX + 0x20) = (uint)*(byte *)(piVar4 + 4);
    FUN_004f5730(&fStack_10);
    fStack_28 = fStack_10;
    fStack_20 = (float)uStack_c;
    fStack_24 = 0.0;
    pfVar8 = (float *)FUN_005229b0(&fStack_10,&fStack_28);
    fStack_28 = *pfVar8;
    fStack_24 = pfVar8[1];
    fStack_20 = pfVar8[2];
    *(float *)(in_ECX + 0x34) = fStack_28;
    iStack_2c = (int)fStack_20;
    *(float *)(in_ECX + 0x38) = fStack_20;
    iStack_30 = (int)fStack_28;
    cVar3 = (**(code **)(*DAT_00b5af50 + 0x18))(&iStack_30);
    fVar2 = fStack_24;
    if (cVar3 == '\x01') {
      FUN_0053cc10();
      return;
    }
    fStack_10 = fStack_28;
    fStack_1c = fStack_28;
    iStack_14 = iStack_2c;
    fStack_20 = (float)iStack_2c;
    fStack_18 = fStack_24;
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar5 = (**(code **)(*piVar7 + 8))();
    *(undefined4 *)(in_ECX + 0x30) = uVar5;
    FUN_0053c990(iStack_14,fStack_10,fVar2,fStack_20,fStack_1c,fStack_18,0,0,0,0);
    iVar1 = *piVar4;
    *(int *)(in_ECX + 0x10) = *(int *)(iVar6 + 0xc) + iVar1;
    FUN_0053cb10(iVar1,*(undefined4 *)(iVar6 + 0x48));
    FUN_0053cac0(CONCAT22((short)((uint)*piVar4 >> 0x10),*(undefined2 *)(iVar6 + 4)),
                 CONCAT22(extraout_var,*(undefined2 *)(iVar6 + 8)),*(undefined4 *)(iVar6 + 0xc),
                 *piVar4);
  }
  return;
}


// ==== FUN_0053ced0 @ 0x0053ced0 ====

void FUN_0053ced0(void)

{
  undefined4 uVar1;
  int *piVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int in_ECX;
  char *pcVar7;
  undefined1 local_2e [6];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  void *pvStack_1c;
  uint uStack_8;
  
  local_28 = *(undefined4 *)(in_ECX + 0x34);
  local_24 = *(undefined4 *)(in_ECX + 0x38);
  iVar4 = *DAT_00b5a77c;
  local_20 = 0;
  uVar1 = FUN_004ef0e0(local_2e);
  piVar2 = (int *)(**(code **)(iVar4 + 4))(uVar1);
  if (piVar2 == (int *)0x0) {
    uVar1 = 0x28;
    pcVar7 = s_Send_Remote_Contect_Target_Type_E_009b9de4;
  }
  else {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar1;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x6020002;
    *(undefined2 *)((int)pvVar3 + 6) = 0x1c;
    iVar4 = FUN_004244d0();
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar1 = (**(code **)(*piVar5 + 8))();
    *(undefined4 *)(iVar4 + 0x10) = uVar1;
    puVar6 = (undefined4 *)(**(code **)(*piVar2 + 8))();
    *(undefined4 *)(iVar4 + 0x14) = *puVar6;
    *(undefined4 *)(iVar4 + 0x18) = puVar6[1];
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5a77c + 0x18))(piVar2);
    uVar1 = 0x16;
    pcVar7 = s_Send_Remote_Contect____009b9e10;
  }
  FUN_00401740(pcVar7,uVar1);
  uVar1 = FUN_00404230(&local_20);
  FUN_00796d50(uVar1);
  if (uStack_8 < 0x10) {
    return;
  }
  _free(pvStack_1c);
  return;
}


// ==== FUN_0053d000 @ 0x0053d000 ====

void FUN_0053d000(void)

{
  char cVar1;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 4) != '\0') && (*(char *)(in_ECX + 6) != '\x01')) {
    cVar1 = FUN_0053cbc0();
    if (cVar1 == '\x01') {
      FUN_0053cc10();
      return;
    }
    cVar1 = FUN_0053cb60();
    if (cVar1 == '\x01') {
      FUN_0053ced0();
    }
  }
  return;
}


// ==== FUN_0053d040 @ 0x0053d040 ====

void FUN_0053d040(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x6020002;
  *(undefined2 *)((int)pvVar1 + 6) = 0x1c;
  FUN_004244d0();
  return;
}


// ==== FUN_0053d070 @ 0x0053d070 ====

void FUN_0053d070(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009b9e68;
  (**(code **)(*DAT_00b5af38 + 8))(in_ECX[0xc]);
  *in_ECX = &PTR_FUN_009b9e4c;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053d0b0 @ 0x0053d0b0 ====

void FUN_0053d0b0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_0053d0c0 @ 0x0053d0c0 ====

void FUN_0053d0c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9efc;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  return;
}


// ==== FUN_0053d0f0 @ 0x0053d0f0 ====

void FUN_0053d0f0(undefined4 param_1,undefined1 param_2)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 8) = param_1;
  *(undefined1 *)(in_ECX + 4) = param_2;
  return;
}


// ==== FUN_0053d130 @ 0x0053d130 ====

void FUN_0053d130(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_2c = param_1;
  local_28 = param_2;
  local_20 = param_4;
  local_24 = param_3;
  local_1c = param_5;
  local_14 = param_7;
  local_18 = param_6;
  local_10 = param_8;
  local_8 = param_10;
  local_c = param_9;
  local_4 = param_11;
  (**(code **)(*DAT_00b5af38 + 4))(&local_2c);
  return;
}


// ==== FUN_0053d240 @ 0x0053d240 ====

void FUN_0053d240(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  *(undefined4 *)(in_ECX + 0x24) = uVar1;
  if (param_1 == 0) {
    *(undefined4 *)(in_ECX + 0x28) = 1000;
    return;
  }
  *(int *)(in_ECX + 0x28) = param_1;
  return;
}


// ==== FUN_0053d270 @ 0x0053d270 ====

undefined4 FUN_0053d270(void)

{
  uint uVar1;
  int in_ECX;
  int iVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if (uVar1 < *(int *)(in_ECX + 0x24) - 300U) {
    return 0;
  }
  iVar2 = *(int *)(in_ECX + 0x24) - uVar1;
  if (0 < iVar2) {
    uVar1 = uVar1 + iVar2;
  }
  *(uint *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x28) + uVar1;
  return 1;
}


// ==== FUN_0053d2b0 @ 0x0053d2b0 ====

bool FUN_0053d2b0(void)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  int in_ECX;
  
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar5 = DAT_00b5acd8;
  if (uVar3 <= *(int *)(in_ECX + 0x10) - 100U) {
    if (*(int **)(in_ECX + 8) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    iVar1 = *piVar5;
    uVar4 = FUN_0053f080();
    piVar5 = (int *)(**(code **)(iVar1 + 0xc))(uVar4);
    if (piVar5 != (int *)0x0) {
      cVar2 = (**(code **)(*piVar5 + 0x38))();
      return cVar2 == '\0';
    }
  }
  return true;
}


// ==== FUN_0053d310 @ 0x0053d310 ====

void FUN_0053d310(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 6) != '\x01') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5120003;
    *(undefined2 *)((int)pvVar2 + 6) = 0x14;
    iVar3 = FUN_004244d0();
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar1 = (**(code **)(*piVar4 + 8))();
    *(undefined4 *)(iVar3 + 0x10) = uVar1;
    FUN_004d8570(iVar3);
    *(undefined1 *)(in_ECX + 6) = 1;
  }
  return;
}


// ==== FUN_0053d3b0 @ 0x0053d3b0 ====

void FUN_0053d3b0(void)

{
  ushort uVar1;
  undefined2 uVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  float *pfVar8;
  undefined4 uVar9;
  int iVar10;
  int in_ECX;
  int *unaff_EBP;
  int iStack_24;
  int iStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined4 uStack_c;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  }
  uVar5 = (**(code **)(*piVar4 + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IRemote::RTTI_Type_Descriptor,0);
  piVar4 = (int *)FUN_00803725(uVar5);
  if (piVar4 != (int *)0x0) {
    iVar6 = (**(code **)(*piVar4 + 0x1c))();
    *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(iVar6 + 0x24);
    iVar6 = (**(code **)(*piVar4 + 0x24))();
    piVar7 = (int *)0x0;
    if ((int *)piVar4[0x13] != (int *)0x0) {
      piVar7 = (int *)(**(code **)(*(int *)piVar4[0x13] + 0x18))();
    }
    (**(code **)(*piVar7 + 8))(0);
    piVar4 = (int *)(**(code **)(*piVar7 + 0x10))();
    if (*(int **)(in_ECX + 8) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar5 = FUN_0053f080();
    *(undefined4 *)(in_ECX + 0x18) = uVar5;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    FUN_004f5730(&fStack_10);
    fStack_1c = fStack_10;
    fStack_14 = (float)uStack_c;
    fStack_18 = 0.0;
    pfVar8 = (float *)FUN_005229b0(&fStack_10,&fStack_1c);
    fStack_1c = *pfVar8;
    fStack_18 = pfVar8[1];
    iStack_24 = (int)fStack_1c;
    fStack_14 = pfVar8[2];
    iStack_20 = (int)fStack_14;
    cVar3 = (**(code **)(*DAT_00b5af50 + 0x18))(&iStack_24);
    if (cVar3 == '\x01') {
      FUN_0053d310();
      return;
    }
    *(int *)(in_ECX + 0x10) = *piVar4 + *(int *)(iVar6 + 0xc);
    iVar10 = *(int *)(iVar6 + 0x48);
    uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(undefined4 *)(in_ECX + 0x24) = uVar5;
    if (iVar10 == 0) {
      *(undefined4 *)(in_ECX + 0x28) = 1000;
    }
    else {
      *(int *)(in_ECX + 0x28) = iVar10;
    }
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar9 = (**(code **)(*piVar4 + 8))();
    fStack_14 = 0.0;
    fStack_10 = 0.0;
    uStack_c = 0;
    FUN_0053d130(uVar9,iStack_20,fStack_1c,fStack_18,iStack_20,fStack_1c,fStack_18,0,0,0,0);
    uVar1 = *(ushort *)(iVar6 + 4);
    uVar5 = *(undefined4 *)(iVar6 + 0xc);
    uVar2 = *(undefined2 *)(iVar6 + 8);
    iVar6 = *unaff_EBP;
    iVar10 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    iVar10 = iVar10 - iVar6;
    if (iVar10 < 0) {
      iVar10 = 0;
    }
    (**(code **)(*DAT_00b5ac70 + 0xc))(uVar9,uVar1 | 0x640000,uVar2,uVar5,iVar10,1);
  }
  return;
}


// ==== FUN_0053d5d0 @ 0x0053d5d0 ====

void FUN_0053d5d0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9efc;
  if ((int *)in_ECX[2] != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x14))();
    if (piVar2 != (int *)0x0) {
      iVar1 = *DAT_00b5af38;
      uVar3 = (**(code **)(*piVar2 + 8))();
      (**(code **)(iVar1 + 8))(uVar3);
    }
  }
  *in_ECX = &PTR_FUN_009b9e4c;
  return;
}


// ==== FUN_0053d610 @ 0x0053d610 ====

void FUN_0053d610(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int in_ECX;
  void *unaff_EBX;
  undefined4 uStack_1c;
  uint uStack_c;
  uint uStack_8;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a77c + 8))(param_1);
  if (piVar1 == (int *)0x0) {
    FUN_00401740(s_Send_Remote_Contect_Target_Type_E_009b9e84,0x28);
    uVar2 = FUN_00404230((int)register0x00000010 + -0x20);
    FUN_00796d50(uVar2);
    if (0xf < uStack_8) {
      _free(uStack_1c);
      return;
    }
  }
  else {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x6020002;
    *(undefined2 *)((int)pvVar3 + 6) = 0x1c;
    iVar4 = FUN_004244d0();
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar2 = (**(code **)(*piVar5 + 8))();
    *(undefined4 *)(iVar4 + 0x10) = uVar2;
    puVar6 = (undefined4 *)(**(code **)(*piVar1 + 8))();
    *(undefined4 *)(iVar4 + 0x14) = *puVar6;
    *(undefined4 *)(iVar4 + 0x18) = puVar6[1];
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5a77c + 0x18))(piVar1);
    FUN_00401740(s_Send_Remote_Contect____009b9eb0,0x16);
    uVar2 = FUN_00404230((int)register0x00000010 + -0x24);
    FUN_00796d50(uVar2);
    if (0xf < uStack_c) {
      _free(unaff_EBX);
      return;
    }
  }
  return;
}


// ==== FUN_0053d750 @ 0x0053d750 ====

void FUN_0053d750(void)

{
  byte bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  char cVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int in_ECX;
  int iVar10;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  }
  uVar6 = (**(code **)(*piVar5 + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IRemote::RTTI_Type_Descriptor,0);
  piVar5 = (int *)FUN_00803725(uVar6);
  if (piVar5 != (int *)0x0) {
    iVar7 = (**(code **)(*piVar5 + 0x24))();
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
    }
    uVar6 = *(undefined4 *)(iVar8 + 0x1c);
    uVar2 = *(undefined4 *)(in_ECX + 0xc);
    bVar1 = *(byte *)(iVar7 + 0x33);
    uVar3 = *(undefined4 *)(iVar8 + 0x18);
    iVar7 = *(int *)(in_ECX + 0x18);
    piVar5 = (int *)(**(code **)(*DAT_00b5ad5c + 0x18))();
    while (piVar5 != (int *)0x0) {
      iVar8 = (**(code **)(*piVar5 + 0x18))();
      if ((iVar7 != iVar8) &&
         (cVar4 = (**(code **)(*piVar5 + 8))(uVar3,uVar6,(float)bVar1,uVar2), cVar4 != '\0')) {
        uVar9 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        if (*(int *)(in_ECX + 0x24) - 300U <= uVar9) {
          iVar10 = *(int *)(in_ECX + 0x24) - uVar9;
          if (0 < iVar10) {
            uVar9 = uVar9 + iVar10;
          }
          *(uint *)(in_ECX + 0x24) = *(int *)(in_ECX + 0x28) + uVar9;
          FUN_0053d610(iVar8);
        }
      }
      piVar5 = (int *)(**(code **)(*DAT_00b5ad5c + 0x1c))();
    }
  }
  return;
}


// ==== FUN_0053d860 @ 0x0053d860 ====

void FUN_0053d860(void)

{
  char cVar1;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 4) != '\0') && (*(char *)(in_ECX + 6) != '\x01')) {
    cVar1 = FUN_0053d2b0();
    if (cVar1 == '\x01') {
      FUN_0053d310();
      return;
    }
    FUN_0053d750();
  }
  return;
}


// ==== FUN_0053d890 @ 0x0053d890 ====

void FUN_0053d890(byte param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9efc;
  if ((int *)in_ECX[2] != (int *)0x0) {
    piVar2 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x14))();
    if (piVar2 != (int *)0x0) {
      iVar1 = *DAT_00b5af38;
      uVar3 = (**(code **)(*piVar2 + 8))();
      (**(code **)(iVar1 + 8))(uVar3);
    }
  }
  *in_ECX = &PTR_FUN_009b9e4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053d8e0 @ 0x0053d8e0 ====

void FUN_0053d8e0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_0053d8f0 @ 0x0053d8f0 ====

void FUN_0053d8f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9f80;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 9) = 0;
  return;
}


// ==== FUN_0053d920 @ 0x0053d920 ====

void FUN_0053d920(undefined4 param_1,undefined1 param_2)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 8) = param_1;
  *(undefined1 *)(in_ECX + 4) = param_2;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  return;
}


// ==== FUN_0053d980 @ 0x0053d980 ====

void FUN_0053d980(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x24) != '\0') {
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar2 = (**(code **)(*piVar1 + 0x24))
                      (0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IRemote::RTTI_Type_Descriptor,0);
    piVar1 = (int *)FUN_00803725(uVar2);
    if (piVar1 != (int *)0x0) {
      uVar2 = *(undefined4 *)(in_ECX + 0x1c);
      iVar3 = (**(code **)(*piVar1 + 0x24))();
      (**(code **)(*DAT_00b5ac70 + 0x20))(uVar2,*(ushort *)(iVar3 + 4) | 0x640000);
      *(undefined1 *)(in_ECX + 0x24) = 0;
    }
  }
  return;
}


// ==== FUN_0053da00 @ 0x0053da00 ====

void FUN_0053da00(undefined4 param_1,ushort param_2,undefined2 param_3,undefined4 param_4,
                 int param_5,undefined1 param_6)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = *(int *)(in_ECX + 0x10) - param_5;
  if (200 < uVar2) {
    uVar2 = uVar2 + 100;
  }
  iVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  iVar1 = iVar1 - param_5;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  (**(code **)(*DAT_00b5ac70 + 0x18))
            (*(undefined4 *)(in_ECX + 0x14),param_1,param_2 | 0x640000,param_3,&param_6,param_1,
             uVar2,iVar1,param_4);
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
  *(undefined1 *)(in_ECX + 0x24) = 1;
  if (4 < *(uint *)(in_ECX + 0x14)) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
  }
  return;
}


// ==== FUN_0053da80 @ 0x0053da80 ====

void FUN_0053da80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9f80;
  FUN_0053d980();
  *in_ECX = &PTR_FUN_009b9e4c;
  return;
}


// ==== FUN_0053daa0 @ 0x0053daa0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053daa0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  float *pfVar8;
  undefined4 *puVar9;
  int iVar10;
  int in_ECX;
  float unaff_EBP;
  float unaff_ESI;
  float fVar11;
  float fVar12;
  undefined4 uStack_40;
  float fStack_3c;
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined1 auStack_18 [24];
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  }
  uVar5 = (**(code **)(*piVar4 + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IRemote::RTTI_Type_Descriptor,0);
  piVar4 = (int *)FUN_00803725(uVar5);
  if (piVar4 != (int *)0x0) {
    iVar6 = (**(code **)(*piVar4 + 0x24))();
    piVar7 = (int *)0x0;
    if ((int *)piVar4[0x13] != (int *)0x0) {
      piVar7 = (int *)(**(code **)(*(int *)piVar4[0x13] + 0x18))();
    }
    (**(code **)(*piVar7 + 8))(0);
    piVar4 = (int *)(**(code **)(*piVar7 + 0x10))();
    *(int *)(in_ECX + 0x18) = piVar4[3];
    *(int *)(in_ECX + 0x1c) = piVar4[4];
    fVar11 = (float)*(ushort *)(piVar4 + 5) * DAT_009b3508;
    piVar7 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 0x18));
    if (piVar7 == (int *)0x0) {
      FUN_004f5730(&fStack_20);
      fStack_2c = fStack_20;
      uStack_24 = uStack_1c;
      fStack_28 = DAT_009a000c;
    }
    else {
      pfVar8 = (float *)(**(code **)(*piVar7 + 0x28))();
      fStack_2c = *pfVar8;
      iVar10 = (**(code **)(*piVar7 + 0x28))();
      uStack_24 = *(undefined4 *)(iVar10 + 4);
      iVar10 = (**(code **)(*piVar7 + 0x10))();
      fStack_28 = *(float *)(iVar10 + 0x34) * DAT_009b9f98;
    }
    pfVar8 = (float *)FUN_005229b0(&fStack_20,&fStack_2c);
    fVar1 = *pfVar8;
    fVar2 = pfVar8[1];
    piVar7 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 0x1c));
    if (piVar7 == (int *)0x0) {
      FUN_004f5730(&uStack_24);
      FUN_0040d600(auStack_18 + -0x30,uStack_1c);
      fVar3 = (float)*(int *)(iVar6 + 0xc);
      if (*(int *)(iVar6 + 0xc) < 0) {
        fVar3 = fVar3 + _DAT_0099d104;
      }
      fVar12 = unaff_EBP * unaff_ESI * fVar3 * DAT_0099d0ec + fStack_3c;
      uStack_40 = fVar11 * unaff_ESI * fVar3 * DAT_0099d0ec + fVar2;
      fVar11 = fVar1;
    }
    else {
      puVar9 = (undefined4 *)(**(code **)(*piVar7 + 0x28))();
      uStack_24 = *puVar9;
      iVar10 = (**(code **)(*piVar7 + 0x28))();
      uStack_1c = *(undefined4 *)(iVar10 + 4);
      iVar10 = (**(code **)(*piVar7 + 0x10))();
      fStack_20 = *(float *)(iVar10 + 0x34) * DAT_009b9f98;
      pfVar8 = (float *)FUN_005229b0(auStack_18,&uStack_24);
      fVar12 = *pfVar8;
      fVar11 = pfVar8[1];
      uStack_40 = pfVar8[2];
    }
    iVar10 = (int)ROUND((SQRT((fVar12 - fStack_3c) * (fVar12 - fStack_3c) +
                              (fVar11 - fVar1) * (fVar11 - fVar1) +
                              (uStack_40 - fVar2) * (uStack_40 - fVar2)) / unaff_ESI) * DAT_009b012c
                       );
    if (iVar10 == 0) {
      iVar10 = 1;
    }
    *(int *)(in_ECX + 0x10) = *piVar4 + iVar10;
    FUN_0053da00(*(undefined4 *)(in_ECX + 0x1c),
                 CONCAT22((short)((uint)*piVar4 >> 0x10),*(undefined2 *)(iVar6 + 4)),
                 CONCAT22((short)((uint)fVar2 >> 0x10),*(undefined2 *)(iVar6 + 8)),
                 *(undefined4 *)(iVar6 + 0xc),*piVar4,fStack_3c,fVar1,fVar2);
  }
  return;
}


// ==== FUN_0053dd90 @ 0x0053dd90 ====

void FUN_0053dd90(void)

{
  int *piVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int in_ECX;
  void *unaff_EBX;
  undefined4 uStack_1c;
  uint uStack_c;
  uint uStack_8;
  
  if (*(char *)(in_ECX + 5) != '\x01') {
    piVar1 = (int *)(**(code **)(*DAT_00b5a77c + 8))(*(undefined4 *)(in_ECX + 0x1c));
    if (piVar1 == (int *)0x0) {
      FUN_00401740(s_Send_Remote_Contect_Target_Type_E_009b9f18,0x28);
      uVar2 = FUN_00404230((int)register0x00000010 + -0x20);
      FUN_00796d50(uVar2);
      if (0xf < uStack_8) {
        _free(uStack_1c);
        return;
      }
    }
    else {
      uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar3 = operator_new(0x400);
      *(undefined4 *)((int)pvVar3 + 8) = uVar2;
      *(undefined4 *)((int)pvVar3 + 0xc) = 0x6020002;
      *(undefined2 *)((int)pvVar3 + 6) = 0x1c;
      iVar4 = FUN_004244d0();
      if (*(int **)(in_ECX + 8) == (int *)0x0) {
        piVar5 = (int *)0x0;
      }
      else {
        piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
      }
      uVar2 = (**(code **)(*piVar5 + 8))();
      *(undefined4 *)(iVar4 + 0x10) = uVar2;
      puVar6 = (undefined4 *)(**(code **)(*piVar1 + 8))();
      *(undefined4 *)(iVar4 + 0x14) = *puVar6;
      *(undefined4 *)(iVar4 + 0x18) = puVar6[1];
      FUN_004d8570(iVar4);
      (**(code **)(*DAT_00b5a77c + 0x18))(piVar1);
      *(undefined1 *)(in_ECX + 5) = 1;
      FUN_00401740(s_Send_Remote_Contect____009b9f44,0x16);
      uVar2 = FUN_00404230((int)register0x00000010 + -0x24);
      FUN_00796d50(uVar2);
      if (0xf < uStack_c) {
        _free(unaff_EBX);
        return;
      }
    }
  }
  return;
}


// ==== FUN_0053dee0 @ 0x0053dee0 ====

void FUN_0053dee0(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if (*(uint *)(in_ECX + 0x10) < uVar1) {
    FUN_0053d980();
  }
  if (((*(char *)(in_ECX + 4) != '\0') && (*(char *)(in_ECX + 5) != '\x01')) &&
     (*(int *)(in_ECX + 0x10) - 100U < uVar1)) {
    FUN_0053dd90();
  }
  return;
}


// ==== FUN_0053df20 @ 0x0053df20 ====

void FUN_0053df20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009b9f80;
  FUN_0053d980();
  *in_ECX = &PTR_FUN_009b9e4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053df50 @ 0x0053df50 ====

void FUN_0053df50(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_0053df60 @ 0x0053df60 ====

void FUN_0053df60(undefined4 param_1,undefined1 param_2)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 8) = param_1;
  *(undefined1 *)(in_ECX + 4) = param_2;
  return;
}


// ==== FUN_0053dfa0 @ 0x0053dfa0 ====

void FUN_0053dfa0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11)

{
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_2c = param_1;
  local_28 = param_2;
  local_20 = param_4;
  local_24 = param_3;
  local_1c = param_5;
  local_14 = param_7;
  local_18 = param_6;
  local_10 = param_8;
  local_8 = param_10;
  local_c = param_9;
  local_4 = param_11;
  (**(code **)(*DAT_00b5af38 + 4))(&local_2c);
  return;
}


// ==== FUN_0053e090 @ 0x0053e090 ====

undefined4 FUN_0053e090(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  }
  uVar2 = (**(code **)(*piVar1 + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IRemote::RTTI_Type_Descriptor,0);
  piVar1 = (int *)FUN_00803725(uVar2);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0053e0c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(*piVar1 + 0x28))();
  return uVar2;
}


// ==== FUN_0053e140 @ 0x0053e140 ====

bool FUN_0053e140(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  int local_8;
  int local_4;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  }
  local_8 = (int)*(float *)(iVar2 + 0x18);
  local_4 = (int)*(float *)(iVar2 + 0x1c);
  cVar1 = (**(code **)(*DAT_00b5af50 + 0x1c))(&local_8);
  if (cVar1 == '\x01') {
    return true;
  }
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  return *(int *)(in_ECX + 0x10) - 100U < uVar3;
}


// ==== FUN_0053e1b0 @ 0x0053e1b0 ====

void FUN_0053e1b0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 6) != '\x01') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5120003;
    *(undefined2 *)((int)pvVar2 + 6) = 0x14;
    iVar3 = FUN_004244d0();
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar1 = (**(code **)(*piVar4 + 8))();
    *(undefined4 *)(iVar3 + 0x10) = uVar1;
    FUN_004d8570(iVar3);
    *(undefined1 *)(in_ECX + 6) = 1;
  }
  return;
}


// ==== FUN_0053e260 @ 0x0053e260 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0053e260(void)

{
  undefined2 uVar1;
  ushort uVar2;
  float fVar3;
  int *piVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  undefined4 *puVar8;
  float *pfVar9;
  undefined4 uVar10;
  int iVar11;
  int in_ECX;
  float unaff_EBX;
  float unaff_EBP;
  float fVar12;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float afStack_30 [3];
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  undefined1 auStack_18 [16];
  float fStack_8;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  }
  uVar5 = (**(code **)(*piVar4 + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IRemote::RTTI_Type_Descriptor,0);
  piVar4 = (int *)FUN_00803725(uVar5);
  if (piVar4 != (int *)0x0) {
    iVar6 = (**(code **)(*piVar4 + 0x1c))();
    *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(iVar6 + 0x24);
    iVar6 = (**(code **)(*piVar4 + 0x24))();
    piVar7 = (int *)0x0;
    if ((int *)piVar4[0x13] != (int *)0x0) {
      piVar7 = (int *)(**(code **)(*(int *)piVar4[0x13] + 0x18))();
    }
    (**(code **)(*piVar7 + 8))(0);
    piVar4 = (int *)(**(code **)(*piVar7 + 0x10))();
    if (*(int **)(in_ECX + 8) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar5 = FUN_0053f080();
    *(undefined4 *)(in_ECX + 0x18) = uVar5;
    *(int *)(in_ECX + 0x1c) = piVar4[6];
    *(int *)(in_ECX + 0x10) = *piVar4 + *(int *)(iVar6 + 0xc);
    puVar8 = (undefined4 *)FUN_004f5730(&fStack_20);
    fStack_3c = (float)*puVar8;
    fStack_38 = (float)puVar8[1];
    fStack_34 = (float)puVar8[2];
    afStack_30[0] = (float)*(ushort *)(piVar4 + 5) * DAT_009b3508;
    fStack_8 = afStack_30[0];
    piVar7 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(*(undefined4 *)(in_ECX + 0x18));
    if (piVar7 == (int *)0x0) {
      FUN_004f5730(&fStack_24);
      fStack_4c = fStack_24;
      fStack_44 = fStack_20;
      fStack_48 = DAT_009a000c;
      fStack_24 = fStack_40;
      fStack_20 = fStack_34;
    }
    else {
      pfVar9 = (float *)(**(code **)(*piVar7 + 0x28))();
      fStack_4c = *pfVar9;
      iVar11 = (**(code **)(*piVar7 + 0x28))();
      fStack_44 = *(float *)(iVar11 + 4);
      iVar11 = (**(code **)(*piVar7 + 0x10))();
      fStack_48 = *(float *)(iVar11 + 0x34) * DAT_009b9f98;
      iVar11 = (**(code **)(*piVar7 + 0x10))();
      fStack_20 = *(float *)(iVar11 + 0x34) * DAT_009b9f98;
      fStack_24 = fStack_40;
    }
    fStack_1c = fStack_3c;
    pfVar9 = (float *)FUN_005229b0(auStack_18,&fStack_24);
    fStack_40 = *pfVar9;
    fStack_3c = pfVar9[1];
    fStack_38 = pfVar9[2];
    pfVar9 = (float *)FUN_005229b0(auStack_18,&fStack_4c);
    fStack_4c = *pfVar9;
    fStack_48 = pfVar9[1];
    fStack_24 = fStack_40 - fStack_4c;
    fStack_44 = pfVar9[2];
    *(float *)(in_ECX + 0x24) = fStack_4c;
    fStack_20 = fStack_3c - fStack_48;
    *(float *)(in_ECX + 0x28) = fStack_48;
    *(float *)(in_ECX + 0x2c) = fStack_44;
    fStack_1c = fStack_38 - fStack_44;
    thunk_FUN_0079e1ba(afStack_30,&fStack_24);
    fVar3 = (float)*(int *)(iVar6 + 0xc);
    fVar12 = (float)*(ushort *)((int)piVar4 + 0x16) * DAT_009b3508;
    if (*(int *)(iVar6 + 0xc) < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    fVar3 = fVar3 * DAT_0099d0ec;
    fStack_48 = fStack_38 * fVar12 * fVar3 + unaff_EBP;
    fStack_44 = fStack_34 * fVar12 * fVar3 + unaff_EBX;
    fStack_40 = afStack_30[0] * fVar12 * fVar3 + fStack_4c;
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar10 = (**(code **)(*piVar7 + 8))();
    FUN_0053dfa0(uVar10,unaff_EBP,unaff_EBX,fStack_4c,fStack_48,fStack_44,fStack_40,fStack_38,
                 fStack_34,afStack_30[0],fVar12);
    uVar1 = *(undefined2 *)(iVar6 + 8);
    uVar2 = *(ushort *)(iVar6 + 4);
    uVar5 = *(undefined4 *)(iVar6 + 0xc);
    iVar6 = *piVar4;
    iVar11 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    iVar11 = iVar11 - iVar6;
    if (iVar11 < 0) {
      iVar11 = 0;
    }
    (**(code **)(*DAT_00b5ac70 + 0xc))(uVar10,uVar2 | 0x640000,uVar1,uVar5,iVar11,1);
  }
  return;
}


// ==== FUN_0053e640 @ 0x0053e640 ====

void FUN_0053e640(void)

{
  int iVar1;
  void *_Memory;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    if (piVar2 != (int *)0x0) {
      iVar1 = *DAT_00b5af38;
      uVar3 = (**(code **)(*piVar2 + 8))();
      (**(code **)(iVar1 + 8))(uVar3);
    }
  }
  _Memory = *(void **)(in_ECX + 0x34);
  if ((_Memory != (void *)0x0) && (*(int *)(in_ECX + 0x38) - (int)_Memory >> 2 != 0)) {
    if (_Memory != (void *)0x0) {
      _free(_Memory);
      return;
    }
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
  }
  return;
}


// ==== FUN_0053e6b0 @ 0x0053e6b0 ====

void FUN_0053e6b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba018;
  FUN_0053e640();
  if ((void *)in_ECX[0xd] == (void *)0x0) {
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    *in_ECX = &PTR_FUN_009b9e4c;
    return;
  }
  _free((void *)in_ECX[0xd]);
  return;
}


// ==== FUN_0053e6f0 @ 0x0053e6f0 ====

void FUN_0053e6f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba018;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  return;
}


// ==== FUN_0053e730 @ 0x0053e730 ====

void FUN_0053e730(undefined1 param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  }
  uVar3 = (**(code **)(*piVar2 + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IRemote::RTTI_Type_Descriptor,0);
  piVar2 = (int *)FUN_00803725(uVar3);
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 0x28))();
    if (cVar1 != '\0') {
      FUN_00430ce0(&param_1);
    }
  }
  return;
}


// ==== FUN_0053e790 @ 0x0053e790 ====

void FUN_0053e790(int param_1)

{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int in_ECX;
  void *unaff_EBX;
  undefined4 uStack_1c;
  uint uStack_c;
  uint uStack_8;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  }
  uVar3 = (**(code **)(*piVar2 + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IRemote::RTTI_Type_Descriptor,0);
  piVar2 = (int *)FUN_00803725(uVar3);
  if (piVar2 == (int *)0x0) {
    bVar1 = 0;
  }
  else {
    bVar1 = (**(code **)(*piVar2 + 0x28))();
  }
  if (bVar1 <= *(byte *)(in_ECX + 0x40)) {
    *(undefined1 *)(in_ECX + 5) = 1;
    return;
  }
  piVar2 = *(int **)(in_ECX + 0x34);
  if (piVar2 != *(int **)(in_ECX + 0x38)) {
    do {
      if (param_1 == *piVar2) {
        return;
      }
      piVar2 = piVar2 + 1;
    } while (piVar2 != *(int **)(in_ECX + 0x38));
  }
  FUN_0053e730(param_1);
  piVar2 = (int *)(**(code **)(*DAT_00b5a77c + 8))(param_1);
  if (piVar2 == (int *)0x0) {
    FUN_00401830(s_Send_Remote_Contect_Target_Type_E_009b9fa0);
    uVar3 = FUN_00404230((int)register0x00000010 + -0x20);
    FUN_00796d50(uVar3);
    if (0xf < uStack_8) {
      _free(uStack_1c);
      return;
    }
  }
  else {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    iVar4 = FUN_0053d040(uVar3);
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar3 = (**(code **)(*piVar5 + 8))();
    *(undefined4 *)(iVar4 + 0x10) = uVar3;
    puVar6 = (undefined4 *)(**(code **)(*piVar2 + 8))();
    *(undefined4 *)(iVar4 + 0x14) = *puVar6;
    *(undefined4 *)(iVar4 + 0x18) = puVar6[1];
    FUN_004d8570(iVar4);
    (**(code **)(*DAT_00b5a77c + 0x18))(piVar2);
    FUN_00401830(s_Send_Remote_Contact____009b9fcc);
    uVar3 = FUN_00404230((int)register0x00000010 + -0x24);
    FUN_00796d50(uVar3);
    if (0xf < uStack_c) {
      _free(unaff_EBX);
      return;
    }
    *(char *)(in_ECX + 0x40) = *(char *)(in_ECX + 0x40) + '\x01';
  }
  return;
}


// ==== FUN_0053e900 @ 0x0053e900 ====

void FUN_0053e900(void)

{
  byte bVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  int in_ECX;
  float fVar10;
  float fVar11;
  
  if (*(int **)(in_ECX + 8) == (int *)0x0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  }
  uVar6 = (**(code **)(*piVar5 + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IRemote::RTTI_Type_Descriptor,0);
  piVar5 = (int *)FUN_00803725(uVar6);
  if (piVar5 != (int *)0x0) {
    iVar7 = (**(code **)(*piVar5 + 0x24))();
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x14))();
    }
    uVar6 = (**(code **)(*piVar5 + 8))();
    if (*(int **)(in_ECX + 8) == (int *)0x0) {
      iVar8 = 0;
    }
    else {
      iVar8 = (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
    }
    fVar2 = *(float *)(iVar8 + 0x1c);
    fVar3 = *(float *)(iVar8 + 0x18);
    fVar11 = *(float *)(in_ECX + 0x2c) - fVar2;
    fVar10 = *(float *)(in_ECX + 0x24) - fVar3;
    if ((float)*(ushort *)(iVar7 + 0x30) < SQRT(fVar10 * fVar10 + fVar11 * fVar11)) {
      puVar9 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar9 == (undefined4 *)0x0) {
        puVar9 = (undefined4 *)0x0;
      }
      else {
        *puVar9 = &PTR_FUN_009b8cc4;
        puVar9[1] = uVar6;
      }
      puVar9[2] = 0;
      puVar9[3] = 0;
      puVar9[4] = 0;
      puVar9[5] = 0;
      FUN_00797a20(puVar9);
      return;
    }
    cVar4 = FUN_0053e090();
    if (cVar4 != '\0') {
      iVar8 = *(int *)(in_ECX + 0x18);
      uVar6 = *(undefined4 *)(in_ECX + 0xc);
      *(undefined1 *)(in_ECX + 0x40) = 0;
      bVar1 = *(byte *)(iVar7 + 0x33);
      piVar5 = (int *)(**(code **)(*DAT_00b5ad5c + 0x18))();
      while ((piVar5 != (int *)0x0 &&
             (iVar7 = (**(code **)(*piVar5 + 0x18))(), *(char *)(in_ECX + 5) != '\x01'))) {
        if ((iVar8 != iVar7) &&
           (cVar4 = (**(code **)(*piVar5 + 8))(fVar3,fVar2,(float)bVar1,uVar6), cVar4 != '\0')) {
          FUN_0053e790(iVar7);
        }
        piVar5 = (int *)(**(code **)(*DAT_00b5ad5c + 0x1c))();
      }
    }
  }
  return;
}


// ==== FUN_0053eab0 @ 0x0053eab0 ====

void FUN_0053eab0(void)

{
  char cVar1;
  int in_ECX;
  
  if (((*(char *)(in_ECX + 4) != '\0') && (*(char *)(in_ECX + 6) != '\x01')) &&
     (*(char *)(in_ECX + 5) != '\x01')) {
    cVar1 = FUN_0053e140();
    if (cVar1 == '\x01') {
      FUN_0053e1b0();
      return;
    }
    FUN_0053e900();
  }
  return;
}


// ==== FUN_0053eaf0 @ 0x0053eaf0 ====

void FUN_0053eaf0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba018;
  FUN_0053e640();
  if ((void *)in_ECX[0xd] != (void *)0x0) {
    _free((void *)in_ECX[0xd]);
    return;
  }
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  *in_ECX = &PTR_FUN_009b9e4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053eb40 @ 0x0053eb40 ====

undefined4 FUN_0053eb40(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0053eb50 @ 0x0053eb50 ====

undefined4 FUN_0053eb50(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_0053eb60 @ 0x0053eb60 ====

undefined4 FUN_0053eb60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_0053eb70 @ 0x0053eb70 ====

int FUN_0053eb70(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 8) + 0x18;
}


// ==== FUN_0053eb80 @ 0x0053eb80 ====

int FUN_0053eb80(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 8) + 0x20;
}


// ==== FUN_0053eb90 @ 0x0053eb90 ====

void FUN_0053eb90(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0053eb95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x38))();
  return;
}


// ==== FUN_0053eba0 @ 0x0053eba0 ====

float10 FUN_0053eba0(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 8) + 0x34);
}


// ==== FUN_0053ebb0 @ 0x0053ebb0 ====

void FUN_0053ebb0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0053ebb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x10) + 0x10))();
  return;
}


// ==== FUN_0053ebc0 @ 0x0053ebc0 ====

void FUN_0053ebc0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_0053ebe0 @ 0x0053ebe0 ====

undefined4 FUN_0053ebe0(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
  iVar2 = (**(code **)(*param_1 + 0x10))();
  if (iVar2 == iVar1) {
    (**(code **)(**(int **)(in_ECX + 0x10) + 0xc))();
    return 1;
  }
  return 0;
}


// ==== FUN_0053ec20 @ 0x0053ec20 ====

void FUN_0053ec20(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0053ec2b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x10) + 8))();
  return;
}


// ==== FUN_0053ec50 @ 0x0053ec50 ====

float10 FUN_0053ec50(float *param_1)

{
  float *pfVar1;
  int *in_ECX;
  
  pfVar1 = (float *)(**(code **)(*in_ECX + 0x28))();
  return SQRT(((float10)param_1[1] - (float10)pfVar1[1]) *
              ((float10)param_1[1] - (float10)pfVar1[1]) +
              ((float10)*param_1 - (float10)*pfVar1) * ((float10)*param_1 - (float10)*pfVar1));
}


// ==== FUN_0053ec80 @ 0x0053ec80 ====

void FUN_0053ec80(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009ba094;
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0053f090();
  }
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x40);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00543240();
  }
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s__REMOTE__Create_009ba034,0xf);
  FUN_00796d50(local_1c);
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0053ed20 @ 0x0053ed20 ====

void FUN_0053ed20(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  *in_ECX = &PTR_FUN_009ba094;
  (**(code **)(*(int *)in_ECX[1] + 8))();
  FUN_00401740(s__REMOTE__Destroy__u_009ba044,0x13);
  uVar1 = FUN_00797530(auStack_1c);
  FUN_00796d50(uVar1);
  if (0xf < uStack_4) {
    _free(pvStack_18);
    return;
  }
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
  *in_ECX = &PTR_FUN_009b7814;
  return;
}


// ==== FUN_0053edd0 @ 0x0053edd0 ====

void FUN_0053edd0(undefined4 *param_1)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  short unaff_SI;
  short *psVar6;
  short sStack_38;
  undefined1 auStack_36 [2];
  undefined1 auStack_34 [6];
  undefined1 auStack_2e [6];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  void *pvStack_1c;
  uint uStack_8;
  
  cVar1 = (**(code **)(*(int *)in_ECX[2] + 0x2c))();
  if (cVar1 != '\0') {
    uStack_28 = *param_1;
    uStack_24 = param_1[1];
    psVar6 = &sStack_38;
    uStack_20 = 0;
    FUN_004ef0e0(auStack_2e);
    FUN_005e0c90(psVar6);
    (**(code **)(*(int *)in_ECX[2] + 4))(auStack_34);
    if (unaff_SI != sStack_38) {
      FUN_00401740(s__u_sector__>__u_sector_009ba058,0x16);
      uVar2 = FUN_00404230(&uStack_20);
      FUN_00796d50(uVar2);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return;
      }
      pvVar3 = operator_new(0x400);
      *(undefined4 **)((int)pvVar3 + 8) = param_1;
      *(undefined4 *)((int)pvVar3 + 0xc) = 0x50d0002;
      *(undefined2 *)((int)pvVar3 + 6) = 0x18;
      iVar4 = FUN_004244d0();
      piVar5 = (int *)(**(code **)(*in_ECX + 0x14))();
      uVar2 = (**(code **)(*piVar5 + 8))();
      *(undefined4 *)(iVar4 + 0x10) = uVar2;
      *(short *)(iVar4 + 0x14) = unaff_SI;
      FUN_004d8570(iVar4);
      (**(code **)(*(int *)in_ECX[2] + 8))(auStack_36 + -6);
    }
  }
  return;
}


// ==== FUN_0053ef00 @ 0x0053ef00 ====

uint FUN_0053ef00(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  
  uVar3 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
  uVar4 = (**(code **)(*param_1 + 0x10))();
  if (uVar4 == uVar3) {
    iVar1 = param_1[1];
    uVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    FUN_0053edd0((undefined4 *)(iVar1 + 0x14),uVar5);
    iVar2 = *(int *)(in_ECX + 8);
    *(undefined4 *)(iVar2 + 0x18) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(iVar1 + 0x18);
    iVar2 = *(int *)(in_ECX + 8);
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar1 + 0x1c);
    *(undefined4 *)(iVar2 + 0x24) = *(undefined4 *)(iVar1 + 0x20);
    *(undefined4 *)(*(int *)(in_ECX + 8) + 0x30) = *(undefined4 *)(iVar1 + 4);
    iVar2 = *(int *)(in_ECX + 8);
    *(undefined4 *)(iVar2 + 0x2c) = *(undefined4 *)(iVar1 + 8);
    return CONCAT31((int3)((uint)iVar2 >> 8),1);
  }
  return uVar4 & 0xffffff00;
}


// ==== FUN_0053ef80 @ 0x0053ef80 ====

undefined1 FUN_0053ef80(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  iVar3 = (**(code **)(*param_1 + 4))();
  if (iVar3 == 0x40001) {
    if (*(int *)(in_ECX + 0x10) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x10) + 4))(param_1[1]);
    }
  }
  else if (iVar3 == 0x20010021) {
    cVar2 = FUN_0053ef00(param_1);
    if (cVar2 == '\x01') {
      return 1;
    }
  }
  else if (iVar3 == 0x20010022) {
    piVar1 = *(int **)(in_ECX + 4);
    iVar3 = (**(code **)(*param_1 + 0x10))();
    iVar4 = (**(code **)(*piVar1 + 8))();
    if (iVar3 == iVar4) {
      (**(code **)(**(int **)(in_ECX + 0x10) + 0xc))();
      return 1;
    }
  }
  return 0;
}


// ==== FUN_0053f000 @ 0x0053f000 ====

void FUN_0053f000(byte param_1)

{
  void *in_ECX;
  
  FUN_0053ed20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053f020 @ 0x0053f020 ====

undefined4 FUN_0053f020(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_0053f030 @ 0x0053f030 ====

void FUN_0053f030(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_0053f040 @ 0x0053f040 ====

undefined4 FUN_0053f040(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== __break @ 0x0053f047 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_0053f050 @ 0x0053f050 ====

undefined4 FUN_0053f050(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_0053f060 @ 0x0053f060 ====

void FUN_0053f060(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_0053f070 @ 0x0053f070 ====

void FUN_0053f070(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_0053f080 @ 0x0053f080 ====

undefined4 FUN_0053f080(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_0053f090 @ 0x0053f090 ====

void FUN_0053f090(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba0e4;
  in_ECX[4] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_0053f0b0 @ 0x0053f0b0 ====

void FUN_0053f0b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba0e4;
  if ((int *)in_ECX[4] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[4] + 4))();
    (**(code **)(*DAT_00b5a764 + 0x10))(1,in_ECX[4]);
  }
  *in_ECX = &PTR_FUN_009b78dc;
  return;
}


// ==== FUN_0053f0e0 @ 0x0053f0e0 ====

undefined1 FUN_0053f0e0(void)

{
  return 0;
}


// ==== FUN_0053f0f0 @ 0x0053f0f0 ====

void FUN_0053f0f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba0e4;
  if ((int *)in_ECX[4] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[4] + 4))();
    (**(code **)(*DAT_00b5a764 + 0x10))(1,in_ECX[4]);
  }
  *in_ECX = &PTR_FUN_009b78dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053f150 @ 0x0053f150 ====

undefined4 FUN_0053f150(undefined4 param_1)

{
  int in_ECX;
  undefined4 uVar1;
  undefined1 local_12 [6];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *(undefined4 *)(in_ECX + 0x18);
  local_8 = *(undefined4 *)(in_ECX + 0x1c);
  local_4 = 0;
  uVar1 = param_1;
  FUN_004ef0e0(local_12);
  FUN_005e0c90(uVar1);
  return param_1;
}


// ==== FUN_0053f1a0 @ 0x0053f1a0 ====

float10 FUN_0053f1a0(void)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(in_ECX + 0x18);
  return fVar1 + (float10)*(float *)(in_ECX + 0x30);
}


// ==== FUN_0053f1c0 @ 0x0053f1c0 ====

void FUN_0053f1c0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar2 = DAT_0099d0b4;
  uVar1 = DAT_0099d080;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *in_ECX = &PTR_FUN_009ba16c;
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


// ==== FUN_0053f240 @ 0x0053f240 ====

void FUN_0053f240(undefined2 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined2 *)(in_ECX + 0x3c);
  return;
}


// ==== FUN_0053f250 @ 0x0053f250 ====

void FUN_0053f250(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x3c) = *param_1;
  return;
}


// ==== FUN_0053f260 @ 0x0053f260 ====

void FUN_0053f260(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0x1c);
  uVar2 = *(undefined4 *)(in_ECX + 0x2c);
  *param_1 = *(undefined4 *)(in_ECX + 0x18);
  param_1[1] = uVar2;
  param_1[2] = uVar1;
  return;
}


// ==== FUN_0053f2b0 @ 0x0053f2b0 ====

void FUN_0053f2b0(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}


// ==== FUN_0053f2f0 @ 0x0053f2f0 ====

void FUN_0053f2f0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar2 = DAT_009a000c;
  uVar1 = DAT_0099d080;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *in_ECX = &PTR_FUN_009ba1c4;
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


// ==== FUN_0053f370 @ 0x0053f370 ====

undefined4 FUN_0053f370(undefined4 param_1)

{
  int in_ECX;
  undefined4 uVar1;
  undefined1 local_12 [6];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = *(undefined4 *)(in_ECX + 0x18);
  local_8 = *(undefined4 *)(in_ECX + 0x1c);
  local_4 = 0;
  uVar1 = param_1;
  FUN_004ef0e0(local_12);
  FUN_005e0c90(uVar1);
  return param_1;
}


// ==== FUN_0053f3c0 @ 0x0053f3c0 ====

float10 FUN_0053f3c0(void)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(in_ECX + 0x18);
  return fVar1 + (float10)*(float *)(in_ECX + 0x30);
}


// ==== FUN_0053f3e0 @ 0x0053f3e0 ====

void FUN_0053f3e0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar2 = DAT_0099d0b4;
  uVar1 = DAT_0099d080;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *in_ECX = &PTR_FUN_009ba21c;
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


// ==== FUN_0053f450 @ 0x0053f450 ====

void FUN_0053f450(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x0053f459. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 4))();
  return;
}


// ==== FUN_0053f460 @ 0x0053f460 ====

void FUN_0053f460(void)

{
  FUN_00543330();
  return;
}


// ==== FUN_0053f470 @ 0x0053f470 ====

void FUN_0053f470(void)

{
  FUN_00543340();
  return;
}


// ==== FUN_0053f480 @ 0x0053f480 ====

void FUN_0053f480(void)

{
  FUN_00543350();
  return;
}


// ==== FUN_0053f490 @ 0x0053f490 ====

void FUN_0053f490(void)

{
  FUN_00543360();
  return;
}


// ==== FUN_0053f4a0 @ 0x0053f4a0 ====

int FUN_0053f4a0(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x10))();
  return iVar1 + 0x18;
}


// ==== FUN_0053f4b0 @ 0x0053f4b0 ====

int FUN_0053f4b0(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x10))();
  return iVar1 + 0x20;
}


// ==== FUN_0053f4c0 @ 0x0053f4c0 ====

void FUN_0053f4c0(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x0053f4c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x38))();
  return;
}


// ==== FUN_0053f4d0 @ 0x0053f4d0 ====

float10 FUN_0053f4d0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  float fStack_4;
  
  iVar2 = (**(code **)(*in_ECX + 0x10))();
  fStack_4 = *(float *)(iVar2 + 0x34);
  piVar3 = (int *)(**(code **)(*in_ECX + 0x14))();
  cVar1 = (**(code **)(*piVar3 + 0x6c))();
  if (cVar1 == '\x01') {
    fStack_4 = fStack_4 + DAT_0099d0b4;
  }
  return (float10)fStack_4;
}


// ==== FUN_0053f510 @ 0x0053f510 ====

void FUN_0053f510(undefined4 param_1)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x10))();
  (**(code **)(*piVar1 + 0x28))(param_1);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x18))();
  (**(code **)(*piVar1 + 4))(param_1);
  return;
}


// ==== FUN_0053f540 @ 0x0053f540 ====

void FUN_0053f540(void)

{
  FUN_005432d0();
  return;
}


// ==== FUN_0053f550 @ 0x0053f550 ====

void FUN_0053f550(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x14))();
  iVar1 = *piVar2;
  uVar3 = (**(code **)(*in_ECX + 0x1c))();
  (**(code **)(iVar1 + 0x28))(uVar3);
  return;
}


// ==== FUN_0053f570 @ 0x0053f570 ====

float10 FUN_0053f570(float *param_1)

{
  float *pfVar1;
  int *in_ECX;
  
  pfVar1 = (float *)(**(code **)(*in_ECX + 0x28))();
  return SQRT(((float10)param_1[1] - (float10)pfVar1[1]) *
              ((float10)param_1[1] - (float10)pfVar1[1]) +
              ((float10)*param_1 - (float10)*pfVar1) * ((float10)*param_1 - (float10)*pfVar1));
}


// ==== FUN_0053f5a0 @ 0x0053f5a0 ====

void FUN_0053f5a0(void)

{
  int iVar1;
  void *_Memory;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba28c;
  piVar2 = (int *)FUN_00543340();
  iVar1 = *DAT_00b5ad5c;
  uVar3 = (**(code **)(*piVar2 + 8))();
  (**(code **)(iVar1 + 8))(uVar3);
  _Memory = (void *)in_ECX[1];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_009b7814;
    return;
  }
  FUN_00543420();
  _free(_Memory);
  return;
}


// ==== FUN_0053f5f0 @ 0x0053f5f0 ====

undefined4 FUN_0053f5f0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xc))();
  if (iVar1 == 1) {
    uVar2 = (**(code **)(*in_ECX + 0x10))
                      (0,&Framework::ModelCenter::Actors::State::IActorState::RTTI_Type_Descriptor,
                       &Framework::ModelCenter::Actors::State::Monster::RTTI_Type_Descriptor,0);
    iVar1 = FUN_00803725(uVar2);
    if (iVar1 != 0) {
      uVar2 = FUN_0052a640();
      return uVar2;
    }
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 0x40))();
    if (iVar1 != 8) {
      iVar1 = (**(code **)(*in_ECX + 0x40))();
      if (iVar1 != 0xb) {
        return 1;
      }
    }
  }
  return 0;
}


// ==== FUN_0053f650 @ 0x0053f650 ====

void FUN_0053f650(int *param_1,undefined4 param_2)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba28c;
  in_ECX[1] = 0;
  pvVar1 = operator_new(0x2c);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005433f0();
  }
  in_ECX[1] = uVar2;
  FUN_005432c0(param_1);
  FUN_005432b0(param_2);
  pvVar1 = operator_new(0x40);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005121e0();
  }
  FUN_005432e0(uVar2);
  pvVar1 = operator_new(0x18);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005474e0(in_ECX[1]);
  }
  FUN_00543300(uVar2);
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00546c40(in_ECX[1]);
  }
  FUN_00543310(uVar2);
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00543610(in_ECX[1]);
  }
  FUN_00543320(uVar2);
  FUN_005432f0(in_ECX);
  (**(code **)(*param_1 + 100))(param_2);
  return;
}


// ==== FUN_0053f750 @ 0x0053f750 ====

void FUN_0053f750(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  iVar2 = (**(code **)(*piVar1 + 0x24))();
  if (*(int **)(iVar2 + 0x4c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x18))();
  }
                    /* WARNING: Could not recover jumptable at 0x0053f770. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0xc))();
  return;
}


// ==== FUN_0053f780 @ 0x0053f780 ====

uint FUN_0053f780(int param_1)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint extraout_EAX_01;
  undefined1 local_1c [4];
  void *pvStack_18;
  uint uStack_4;
  
  uVar4 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_testskill_009ba25c,9);
  if (uVar4 == 0) {
    uVar5 = FUN_00459160(local_1c,0);
    uVar1 = thunk_FUN_00796f50(uVar5);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX;
    }
    uVar5 = FUN_00459160(local_1c,1);
    uVar2 = thunk_FUN_00796f80(uVar5);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX_00;
    }
    uVar5 = FUN_00459160(local_1c,2);
    uVar3 = thunk_FUN_00796f80(uVar5);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX_01;
    }
    uVar4 = FUN_005433b0(uVar1,uVar2,uVar3);
  }
  return uVar4 & 0xffffff00;
}


// ==== FUN_0053f850 @ 0x0053f850 ====

undefined4 FUN_0053f850(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = (**(code **)(*in_ECX + 0x10))();
  uStack_8 = (**(code **)(*in_ECX + 0x14))();
  uStack_4 = (**(code **)(*in_ECX + 0x1c))();
  piVar2 = (int *)(**(code **)(*in_ECX + 0x14))();
  cVar1 = (**(code **)(*piVar2 + 0x14))(param_1,&uStack_c);
  if (cVar1 == '\x01') {
    return 1;
  }
  piVar2 = (int *)FUN_00543350();
  if ((piVar2 != (int *)0x0) && (cVar1 = (**(code **)(*piVar2 + 0xc))(param_1), cVar1 != '\0')) {
    return 1;
  }
  iVar3 = (**(code **)(*param_1 + 4))();
  if ((iVar3 == 0x70004) && (cVar1 = FUN_0053f780(param_1), cVar1 != '\0')) {
    return 1;
  }
  FUN_00543380(param_1);
  uVar4 = FUN_00549010(param_1);
  return uVar4;
}


// ==== FUN_0053f8f0 @ 0x0053f8f0 ====

void FUN_0053f8f0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int *in_ECX;
  undefined4 uStack_4c;
  undefined1 auStack_36 [14];
  undefined1 auStack_28 [12];
  undefined1 auStack_1c [8];
  undefined4 auStack_14 [5];
  
  uStack_4c = 0x53f8fe;
  piVar1 = (int *)(**(code **)(*in_ECX + 0x14))();
  uStack_4c = 0x53f905;
  iVar2 = (**(code **)(*piVar1 + 0x24))();
  uStack_4c = 0x53f90d;
  piVar1 = (int *)(**(code **)(**(int **)(iVar2 + 0x4c) + 0x14))();
  uStack_4c = param_1;
  (**(code **)(*piVar1 + 0x24))();
  FUN_005170b0();
  FUN_00506ea0(param_1,auStack_1c);
  iVar2 = *DAT_00b5adac;
  uVar3 = FUN_00543390(auStack_36 + -6,param_1,1);
  puVar4 = (undefined1 *)(**(code **)(iVar2 + 4))(auStack_28,uVar3);
  if (auStack_36 + -0x12 != puVar4) {
    FUN_0053fa30(**(undefined4 **)(puVar4 + 4),*(undefined4 **)(puVar4 + 4),auStack_14[0]);
  }
  FUN_008984a0();
  piVar1 = (int *)(**(code **)(*in_ECX + 0x10))();
  iVar2 = *piVar1;
  uVar3 = FUN_005e0c90(auStack_14);
  (**(code **)(iVar2 + 8))(uVar3);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x10))();
  (**(code **)(*piVar1 + 0x20))();
  piVar1 = (int *)(**(code **)(*in_ECX + 0x10))();
  (**(code **)(*piVar1 + 0x24))(&uStack_4c);
  piVar1 = (int *)(**(code **)(*in_ECX + 0x10))();
  (**(code **)(*piVar1 + 0xc))();
  iVar2 = *DAT_00b5ad5c;
  uVar3 = FUN_00513b60();
  (**(code **)(iVar2 + 4))(uVar3);
  FUN_008984a0();
  return;
}


// ==== FUN_0053fa10 @ 0x0053fa10 ====

void FUN_0053fa10(byte param_1)

{
  void *in_ECX;
  
  FUN_0053f5a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053fa30 @ 0x0053fa30 ====

void FUN_0053fa30(undefined4 param_1,undefined4 param_2)

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
    FUN_005172d0(**(undefined4 **)(in_ECX + 4),param_1,param_2,param_2);
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_0053faa0 @ 0x0053faa0 ====

void FUN_0053faa0(undefined2 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined2 *)(in_ECX + 0x3e);
  return;
}


// ==== FUN_0053fab0 @ 0x0053fab0 ====

void FUN_0053fab0(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x3e) = *param_1;
  return;
}


// ==== FUN_0053fac0 @ 0x0053fac0 ====

undefined1 FUN_0053fac0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3c);
}


// ==== FUN_0053fad0 @ 0x0053fad0 ====

void FUN_0053fad0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_0053fae0 @ 0x0053fae0 ====

void FUN_0053fae0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *(undefined1 *)(in_ECX + 0xf) = 1;
  *(undefined1 *)(in_ECX + 5) = 1;
  uVar2 = DAT_009ba338;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *in_ECX = &PTR_FUN_009ba2f4;
  in_ECX[8] = 0;
  in_ECX[9] = uVar1;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = uVar2;
  in_ECX[0xe] = 0;
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  return;
}


// ==== FUN_0053fb60 @ 0x0053fb60 ====

void FUN_0053fb60(void)

{
  return;
}


// ==== FUN_0053fb70 @ 0x0053fb70 ====

void FUN_0053fb70(void)

{
  return;
}


// ==== FUN_0053fb80 @ 0x0053fb80 ====

void FUN_0053fb80(void)

{
  return;
}


// ==== FUN_0053fb90 @ 0x0053fb90 ====

void FUN_0053fb90(undefined2 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined2 *)(in_ECX + 0x60);
  return;
}


// ==== FUN_0053fba0 @ 0x0053fba0 ====

void FUN_0053fba0(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x60) = *param_1;
  return;
}


// ==== FUN_0053fbb0 @ 0x0053fbb0 ====

void FUN_0053fbb0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_0053fbc0 @ 0x0053fbc0 ====

undefined1 FUN_0053fbc0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x3c);
}


// ==== FUN_0053fbd0 @ 0x0053fbd0 ====

void FUN_0053fbd0(void)

{
  return;
}


// ==== FUN_0053fbe0 @ 0x0053fbe0 ====

void FUN_0053fbe0(void)

{
  return;
}


// ==== FUN_0053fbf0 @ 0x0053fbf0 ====

undefined1 FUN_0053fbf0(void)

{
  return 1;
}


// ==== FUN_0053fc00 @ 0x0053fc00 ====

undefined1 FUN_0053fc00(void)

{
  return 0;
}


// ==== FUN_0053fc10 @ 0x0053fc10 ====

void FUN_0053fc10(void)

{
  return;
}


// ==== FUN_0053fc20 @ 0x0053fc20 ====

void FUN_0053fc20(void)

{
  return;
}


// ==== FUN_0053fc30 @ 0x0053fc30 ====

undefined4 FUN_0053fc30(void)

{
  return 0;
}


// ==== FUN_0053fc40 @ 0x0053fc40 ====

void FUN_0053fc40(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_009ba354;
  *(undefined1 *)(in_ECX + 0xf) = 1;
  in_ECX[0x16] = 0xf;
  in_ECX[0x15] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  uVar2 = DAT_009a000c;
  in_ECX[8] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[9] = uVar1;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = uVar2;
  in_ECX[0xe] = 0;
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0x17] = 0;
  return;
}


// ==== FUN_0053fce0 @ 0x0053fce0 ====

void FUN_0053fce0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba354;
  if ((uint)in_ECX[0x16] < 0x10) {
    in_ECX[0x16] = 0xf;
    in_ECX[0x15] = 0;
    *(undefined1 *)(in_ECX + 0x11) = 0;
    *in_ECX = &PTR_FUN_009b8184;
    return;
  }
  _free((void *)in_ECX[0x11]);
  return;
}


// ==== FUN_0053fd20 @ 0x0053fd20 ====

void FUN_0053fd20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba354;
  if (0xf < (uint)in_ECX[0x16]) {
    _free((void *)in_ECX[0x11]);
    return;
  }
  in_ECX[0x16] = 0xf;
  in_ECX[0x15] = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  *in_ECX = &PTR_FUN_009b8184;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0053fd90 @ 0x0053fd90 ====

void FUN_0053fd90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba5d4;
  in_ECX[1] = 0;
  in_ECX[6] = 0;
  return;
}


// ==== FUN_0053fdb0 @ 0x0053fdb0 ====

void FUN_0053fdb0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
  iVar1 = *DAT_00b5ac6c;
  uVar3 = (**(code **)(*piVar2 + 8))(*(undefined4 *)(in_ECX + 8));
  (**(code **)(iVar1 + 0x14))(uVar3);
  *(undefined4 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_0053fdf0 @ 0x0053fdf0 ====

void FUN_0053fdf0(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ba5d4;
  piVar2 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x14))();
  iVar1 = *DAT_00b5ac6c;
  uVar3 = (**(code **)(*piVar2 + 8))(in_ECX[2]);
  (**(code **)(iVar1 + 0x14))(uVar3);
  in_ECX[1] = 0;
  return;
}


// ==== FUN_0053fe30 @ 0x0053fe30 ====

undefined4 FUN_0053fe30(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0x19;
  }
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x14))
                    (0,&Framework::ModelCenter::Actors::Info::IActorInfo::RTTI_Type_Descriptor,
                     &Framework::ModelCenter::Actors::Info::Brick::RTTI_Type_Descriptor,0);
  piVar2 = (int *)FUN_00803725(uVar1);
  uVar1 = (**(code **)(*piVar2 + 0x24))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IBrick::RTTI_Type_Descriptor,0);
  iVar3 = FUN_00803725(uVar1);
  if (*(int **)(iVar3 + 0x4c) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
  }
                    /* WARNING: Could not recover jumptable at 0x0053fe8d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*piVar2 + 0xc))();
  return uVar1;
}


// ==== FUN_0053fe90 @ 0x0053fe90 ====

void FUN_0053fe90(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int in_ECX;
  float10 fVar5;
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
  
  iVar1 = FUN_0053fe30();
  if (iVar1 == 0x19) {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    FUN_00797a50(&uStack_18,0,0xc);
    uStack_d = 0x19;
    uStack_e = 0;
    uStack_18 = uVar2;
    puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0x28))();
    uStack_20 = *puVar3;
    uStack_1c = puVar3[1];
    uStack_c = uStack_20;
    uStack_8 = uStack_1c;
    uVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
    fVar5 = (float10)FUN_0040d5f0(uVar2);
    fStack_4 = (float)fVar5;
    puVar3 = (undefined4 *)FUN_004ef0e0(&uStack_20);
    uStack_14 = *puVar3;
    uStack_10 = *(undefined2 *)(puVar3 + 1);
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      *puVar3 = &PTR_FUN_009b2d88;
    }
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x14))();
    uVar2 = (**(code **)(*piVar4 + 8))();
    puVar3[1] = uVar2;
    FUN_00403e60(puVar3 + 2,&uStack_18,0x19);
    FUN_00797a20(puVar3);
  }
  return;
}


// ==== FUN_0053ff80 @ 0x0053ff80 ====

void FUN_0053ff80(int param_1)

{
  code *pcVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (param_1 != 0) {
    *(int *)(in_ECX + 4) = param_1;
    *(undefined4 *)(in_ECX + 8) = 0;
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_i_pBrick____NULL_009ba394,0x10);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_0053fff0 @ 0x0053fff0 ====

float10 FUN_0053fff0(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  float10 extraout_ST0;
  float10 fVar4;
  undefined1 auStack_26 [10];
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0x1c))();
  if (iVar2 != 0) {
    piVar3 = (int *)(**(code **)(*DAT_00b5a780 + 8))(iVar2 + 0x14);
    if (piVar3 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar3 + 0xc))(auStack_26 + -6);
      if (iVar2 != 0) {
        return (float10)*(float *)(iVar2 + 0x114);
      }
    }
    return (float10)DAT_0099d080;
  }
  uStack_4 = 0xf;
  uStack_8 = 0;
  pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
  FUN_00401740(s_pRemoteDoll____NULL_009ba588,0x13);
  FUN_00406880(auStack_1c);
  if (uStack_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    fVar4 = (float10)(*pcVar1)();
    return fVar4;
  }
  _free(pvStack_18);
  return extraout_ST0;
}


