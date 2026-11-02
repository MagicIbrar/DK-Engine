// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x790000-0x79ffff

// ==== FUN_00790000 @ 0x00790000 ====

void FUN_00790000(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f87a4;
  return;
}


// ==== FUN_00790010 @ 0x00790010 ====

undefined4 FUN_00790010(void)

{
  return 7;
}


// ==== FUN_00790020 @ 0x00790020 ====

void FUN_00790020(undefined1 param_1)

{
  FUN_007956e0(&param_1);
  return;
}


// ==== FUN_00790030 @ 0x00790030 ====

void FUN_00790030(undefined4 param_1)

{
  FUN_00795a80(param_1);
  return;
}


// ==== FUN_00790040 @ 0x00790040 ====

void FUN_00790040(void)

{
  return;
}


// ==== FUN_00790050 @ 0x00790050 ====

void FUN_00790050(void)

{
  return;
}


// ==== FUN_00790060 @ 0x00790060 ====

void FUN_00790060(void)

{
  return;
}


// ==== __break @ 0x00790063 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00790070 @ 0x00790070 ====

void FUN_00790070(void)

{
  return;
}


// ==== __break @ 0x00790078 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== __break @ 0x0079007d ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00790080 @ 0x00790080 ====

void FUN_00790080(void)

{
  return;
}


// ==== FUN_007900d0 @ 0x007900d0 ====

undefined4 * FUN_007900d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f88f4;
  return puVar1;
}


// ==== FUN_007900f0 @ 0x007900f0 ====

void FUN_007900f0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined1 auStack_2e [6];
  void *pvStack_28;
  void *pvStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009983d8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
    piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x20) + 0x28))();
    if (piVar3 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar3 + 0x14))();
      uVar5 = 0;
      if (*(char *)(iVar2 + 0x1e) != '\0') {
        do {
          iVar4 = (**(code **)(*DAT_00b5ad20 + 0xc))();
          if (iVar4 != 0) {
            (**(code **)(*DAT_00b5b0e8 + 8))();
            (**(code **)(*DAT_00b5b0e4 + 8))();
            ExceptionList = pvStack_14;
            return;
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(byte *)(iVar2 + 0x1e));
      }
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      pvStack_10 = (void *)0x0;
      FUN_00401660(auStack_2e + -6,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if ((void *)0xf < pvStack_14) {
        _free(pvStack_28);
        return;
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00790260 @ 0x00790260 ====

void FUN_00790260(void)

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
  puStack_8 = &LAB_009983ea;
  pvStack_c = ExceptionList;
  uStack_34 = (undefined1 *)0x3e90002;
  uStack_38 = 0;
  uStack_3c = 0x79028c;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x7902a9;
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


// ==== FUN_00790310 @ 0x00790310 ====

void FUN_00790310(byte param_1)

{
  void *in_ECX;
  
  FUN_00790000();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00790330 @ 0x00790330 ====

void FUN_00790330(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f87a4;
  return;
}


// ==== FUN_00790340 @ 0x00790340 ====

undefined4 FUN_00790340(void)

{
  return 6;
}


// ==== FUN_00790350 @ 0x00790350 ====

void FUN_00790350(undefined1 param_1)

{
  FUN_007956e0(&param_1);
  return;
}


// ==== FUN_00790360 @ 0x00790360 ====

void FUN_00790360(undefined4 param_1)

{
  FUN_00795a80(param_1);
  return;
}


// ==== FUN_00790370 @ 0x00790370 ====

void FUN_00790370(void)

{
  return;
}


// ==== FUN_00790380 @ 0x00790380 ====

void FUN_00790380(void)

{
  return;
}


// ==== FUN_00790390 @ 0x00790390 ====

void FUN_00790390(void)

{
  return;
}


// ==== FUN_007903a0 @ 0x007903a0 ====

void FUN_007903a0(void)

{
  return;
}


// ==== FUN_007903b0 @ 0x007903b0 ====

void FUN_007903b0(void)

{
  return;
}


// ==== FUN_00790400 @ 0x00790400 ====

undefined4 * FUN_00790400(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f897c;
  return puVar1;
}


// ==== FUN_00790420 @ 0x00790420 ====

void FUN_00790420(void)

{
  int *piVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined1 auStack_4a [22];
  undefined1 auStack_34 [36];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998418;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar2 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar2 == '\0') {
    iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    piVar5 = (int *)(**(code **)(**(int **)(iVar4 + 0x20) + 0x28))();
    if (piVar5 != (int *)0x0) {
      piVar6 = (int *)(**(code **)(*piVar5 + 0x2c))();
      if ((piVar6[1] == 4) || (piVar6[1] == 5)) {
        (**(code **)(*DAT_00b5b100 + 0x10))();
      }
      else {
        if (piVar6[2] != 0x101) {
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          pvStack_10 = (void *)0x2;
          FUN_00765c50(auStack_34);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        iVar4 = (**(code **)(*DAT_00b5b100 + 4))();
        if (iVar4 == 0) {
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          pvStack_10 = (void *)0x0;
LAB_00790569:
          FUN_00765c50(auStack_4a + -6);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        puVar7 = (undefined4 *)(**(code **)(*DAT_00b5b100 + 4))();
        piVar1 = (int *)*puVar7;
        sVar3 = (**(code **)(*piVar5 + 0x1c))();
        piVar5 = (int *)(**(code **)(*piVar1 + 0x48))();
        (**(code **)(*piVar5 + 4))();
        (**(code **)(*piVar1 + 0x2c))();
        piVar5 = (int *)(**(code **)(*DAT_00b5ab2c + 8))();
        if (piVar5 == (int *)0x0) {
          ExceptionList = pvStack_10;
          return;
        }
        iVar4 = (**(code **)(*piVar5 + 4))();
        if (*piVar6 == 4) {
          (**(code **)(*DAT_00b5b100 + 0x18))();
        }
        else {
          if (*(short *)(iVar4 + 6) != sVar3) {
            (**(code **)(*DAT_00b5a794 + 0xc))();
            FUN_00765c50();
            pvStack_10 = (void *)0x1;
            goto LAB_00790569;
          }
          (**(code **)(*DAT_00b5b100 + 0x14))();
        }
      }
      (**(code **)(*DAT_00b5b0fc + 8))();
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_007906b0 @ 0x007906b0 ====

void FUN_007906b0(void)

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
  puStack_8 = &LAB_0099842a;
  pvStack_c = ExceptionList;
  uStack_34 = (undefined1 *)0x3e90002;
  uStack_38 = 0;
  uStack_3c = 0x7906dc;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x7906f9;
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


// ==== FUN_00790760 @ 0x00790760 ====

void FUN_00790760(byte param_1)

{
  void *in_ECX;
  
  FUN_00790330();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00790780 @ 0x00790780 ====

void FUN_00790780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f87a4;
  return;
}


// ==== FUN_00790790 @ 0x00790790 ====

undefined4 FUN_00790790(void)

{
  return 5;
}


// ==== FUN_007907a0 @ 0x007907a0 ====

void FUN_007907a0(void)

{
  return;
}


// ==== FUN_007907b0 @ 0x007907b0 ====

void FUN_007907b0(void)

{
  return;
}


// ==== FUN_007907c0 @ 0x007907c0 ====

void FUN_007907c0(void)

{
  return;
}


// ==== FUN_007907d0 @ 0x007907d0 ====

void FUN_007907d0(void)

{
  return;
}


// ==== FUN_007907e0 @ 0x007907e0 ====

void FUN_007907e0(void)

{
  return;
}


// ==== FUN_007907f0 @ 0x007907f0 ====

void FUN_007907f0(void)

{
  return;
}


// ==== FUN_00790800 @ 0x00790800 ====

void FUN_00790800(void)

{
  return;
}


// ==== FUN_00790810 @ 0x00790810 ====

void FUN_00790810(void)

{
  return;
}


// ==== FUN_00790820 @ 0x00790820 ====

void FUN_00790820(void)

{
  return;
}


// ==== FUN_00790830 @ 0x00790830 ====

void FUN_00790830(void)

{
  return;
}


// ==== FUN_00790840 @ 0x00790840 ====

undefined1 FUN_00790840(void)

{
  return 1;
}


// ==== FUN_00790860 @ 0x00790860 ====

undefined4 * FUN_00790860(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f8a04;
  return puVar1;
}


// ==== FUN_00790880 @ 0x00790880 ====

void FUN_00790880(byte param_1)

{
  void *in_ECX;
  
  FUN_00790780();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007908a0 @ 0x007908a0 ====

void FUN_007908a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f87a4;
  return;
}


// ==== FUN_007908b0 @ 0x007908b0 ====

undefined4 FUN_007908b0(void)

{
  return 4;
}


// ==== FUN_007908c0 @ 0x007908c0 ====

void FUN_007908c0(undefined1 param_1)

{
  FUN_00795dc0(&param_1);
  return;
}


// ==== FUN_007908d0 @ 0x007908d0 ====

void FUN_007908d0(undefined1 param_1)

{
  FUN_007956e0(&param_1);
  return;
}


// ==== FUN_007908e0 @ 0x007908e0 ====

void FUN_007908e0(undefined4 param_1)

{
  FUN_00796090(param_1);
  return;
}


// ==== FUN_007908f0 @ 0x007908f0 ====

void FUN_007908f0(undefined4 param_1)

{
  FUN_00795a80(param_1);
  return;
}


// ==== FUN_00790900 @ 0x00790900 ====

void FUN_00790900(void)

{
  return;
}


// ==== FUN_00790910 @ 0x00790910 ====

void FUN_00790910(void)

{
  return;
}


// ==== FUN_00790920 @ 0x00790920 ====

void FUN_00790920(void)

{
  return;
}


// ==== FUN_00790930 @ 0x00790930 ====

void FUN_00790930(void)

{
  return;
}


// ==== FUN_00790940 @ 0x00790940 ====

void FUN_00790940(void)

{
  return;
}


// ==== FUN_00790980 @ 0x00790980 ====

undefined4 * FUN_00790980(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f8a7c;
  return puVar1;
}


// ==== FUN_007909a0 @ 0x007909a0 ====

void FUN_007909a0(byte param_1)

{
  void *in_ECX;
  
  FUN_007908a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007909c0 @ 0x007909c0 ====

void FUN_007909c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f87a4;
  return;
}


// ==== FUN_007909d0 @ 0x007909d0 ====

undefined4 FUN_007909d0(void)

{
  return 2;
}


// ==== FUN_007909e0 @ 0x007909e0 ====

void FUN_007909e0(undefined1 param_1)

{
  FUN_007956e0(&param_1);
  return;
}


// ==== FUN_007909f0 @ 0x007909f0 ====

void FUN_007909f0(undefined4 param_1)

{
  FUN_00795a80(param_1);
  return;
}


// ==== FUN_00790a00 @ 0x00790a00 ====

void FUN_00790a00(void)

{
  return;
}


// ==== FUN_00790a10 @ 0x00790a10 ====

void FUN_00790a10(void)

{
  return;
}


// ==== FUN_00790a20 @ 0x00790a20 ====

void FUN_00790a20(void)

{
  return;
}


// ==== FUN_00790a30 @ 0x00790a30 ====

void FUN_00790a30(void)

{
  return;
}


// ==== FUN_00790a40 @ 0x00790a40 ====

void FUN_00790a40(void)

{
  return;
}


// ==== FUN_00790a90 @ 0x00790a90 ====

undefined4 * FUN_00790a90(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f8bc0;
  return puVar1;
}


// ==== FUN_00790ab0 @ 0x00790ab0 ====

/* WARNING: Removing unreachable block (ram,0x00790c38) */
/* WARNING: Removing unreachable block (ram,0x00790b89) */
/* WARNING: Removing unreachable block (ram,0x00790bdd) */
/* WARNING: Removing unreachable block (ram,0x00790b34) */

void FUN_00790ab0(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined1 auStack_5c [4];
  uint uStack_30;
  void *pvStack_10;
  void *pvStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  uStack_8 = &LAB_00998478;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar2 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar2 == '\0') {
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar3 == 0) {
      FUN_00401740();
      uStack_8 = (undefined1 *)0x0;
      FUN_00406880();
      uStack_8 = (undefined1 *)0xffffffff;
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    piVar4 = *(int **)(iVar3 + 0x20);
    if (piVar4 == (int *)0x0) {
      FUN_00401740();
      uStack_8 = (undefined1 *)0x1;
      FUN_00406880();
      uStack_8 = (undefined1 *)0xffffffff;
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(int *)(iVar3 + 0x1c) == 0) {
      FUN_00401740();
      uStack_8 = (undefined1 *)0x2;
      FUN_00406880();
      uStack_8 = (undefined1 *)0xffffffff;
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    iVar3 = (**(code **)(*piVar4 + 0x14))();
    if (iVar3 == 0) {
      FUN_00401740();
      uStack_8 = (undefined1 *)0x3;
      FUN_00796d50();
    }
    else {
      piVar4 = (int *)(**(code **)(*piVar4 + 0x28))();
      cVar2 = (**(code **)(*DAT_00b5ad20 + 0x2c))();
      if (cVar2 != '\x01') {
        piVar4 = (int *)(**(code **)(*piVar4 + 0x48))();
        cVar2 = (**(code **)(*piVar4 + 0x10))();
        if (cVar2 == '\0') {
          (**(code **)(*DAT_00b5a794 + 0xc))();
          FUN_00765c50();
          FUN_00765c50(auStack_5c + 4);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        (**(code **)(*DAT_00b5a6ac + 0x20))();
        iVar3 = FUN_00791090();
        *(undefined2 *)(iVar3 + 0x10) = (undefined2)uStack_8;
        *(undefined1 *)(iVar3 + 0x12) = uStack_8._2_1_;
        FUN_004d8570();
        FUN_00401830();
        FUN_00796d50();
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      (**(code **)(*DAT_00b5a794 + 0xc))();
      FUN_00401660();
      FUN_00401660(auStack_5c + 4,0,0xffffffff);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      if (0xf < uStack_30) {
        _free((void *)0x0);
        return;
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00790e20 @ 0x00790e20 ====

void FUN_00790e20(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  char *unaff_retaddr;
  undefined4 uStack_80;
  char *pcStack_7c;
  undefined1 auStack_78 [12];
  undefined4 uStack_6c;
  undefined4 uStack_68;
  int iStack_64;
  char *pcStack_60;
  int *piStack_5c;
  char *pcStack_58;
  undefined4 uStack_54;
  char acStack_42 [14];
  undefined1 auStack_34 [28];
  undefined4 uStack_18;
  undefined1 *puStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009984aa;
  pvStack_c = ExceptionList;
  uStack_54 = 0;
  pcStack_58 = (char *)0x790e48;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    pcStack_58 = (char *)0x790e5b;
    pcVar2 = (char *)(**(code **)(*DAT_00b5a6ac + 0x20))();
    pcStack_58 = (char *)0x790e68;
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if ((iVar3 != 0) && (*(int **)(iVar3 + 0x4c) != (int *)0x0)) {
      pcStack_58 = (char *)0x790e82;
      piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
      if (piVar4 != (int *)0x0) {
        piStack_5c = (int *)0x790e94;
        pcStack_58 = pcVar2;
        (**(code **)(*piVar4 + 8))();
        piStack_5c = (int *)0x790e9b;
        iVar5 = (**(code **)(*piVar4 + 0x10))();
        if (iVar5 != 0) {
          cVar1 = *(char *)(iVar5 + 0xb);
          if (((cVar1 == '\x01') || (cVar1 == '\x02')) || (cVar1 == '\x03')) {
            if (*(int **)(iVar3 + 0x24) == (int *)0x0) {
              pcStack_58 = s_pSuit____NULL_009f8b80;
              piStack_5c = (int *)0x790ef3;
              FUN_00401830();
              pcStack_58 = acStack_42 + -6;
              puStack_8 = (undefined1 *)0x1;
              piStack_5c = (int *)0x790f05;
              FUN_00406880();
              puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
              pcStack_58 = (char *)0x790f15;
              FUN_00446f10();
            }
            piStack_5c = (int *)0x790f22;
            pcStack_58 = unaff_retaddr;
            piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x24) + 0x2c))();
            pcStack_60 = (char *)0x790f30;
            piStack_5c = piVar4;
            cVar1 = (**(code **)(*DAT_00b5ad20 + 0x2c))();
            if (cVar1 == '\x01') {
              pcStack_60 = &DAT_006e0087;
              iStack_64 = 0;
              uStack_68 = 0x790f46;
              uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
              uStack_6c = 0x790f50;
              FUN_00765c50();
              puStack_10 = (undefined1 *)&uStack_80;
              uStack_18 = 2;
              FUN_00765c50(&pcStack_58);
              (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            pcStack_60 = (char *)0x790f9c;
            piVar4 = (int *)(**(code **)(*piVar4 + 0x48))();
            pcStack_60 = (char *)0x790fa3;
            cVar1 = (**(code **)(*piVar4 + 0x10))();
            if (cVar1 != '\0') {
              pcStack_60 = (char *)0x791013;
              pcStack_60 = (char *)(**(code **)(*DAT_00b5a6ac + 0x20))();
              iStack_64 = 0x791019;
              iStack_64 = FUN_007910c0();
              *(char **)(iStack_64 + 0x10) = unaff_retaddr;
              uStack_68 = 0x791022;
              FUN_004ef210();
              pcStack_60 = s_SEND______CQPick_Suit_009f8b90;
              iStack_64 = 0x791033;
              FUN_00401830();
              pcStack_60 = auStack_34;
              puStack_10 = (undefined1 *)0x4;
              iStack_64 = 0x791045;
              FUN_00796d50();
              puStack_10 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
              pcStack_60 = (char *)0x791055;
              FUN_00446f10();
            }
            pcStack_60 = (char *)0x650002;
            iStack_64 = 5;
            uStack_68 = 0x790fb9;
            pcStack_60 = (char *)(**(code **)(*DAT_00b5a794 + 0xc))();
            iStack_64 = 0x790fc3;
            FUN_00765c50();
            puStack_10 = (undefined1 *)0x3;
          }
          else {
            pcStack_58 = (char *)0x650001;
            piStack_5c = (int *)0x5;
            pcStack_60 = (char *)0x790ec4;
            pcStack_60 = (char *)(**(code **)(*DAT_00b5a794 + 0xc))();
            iStack_64 = 0x790ece;
            FUN_00765c50();
            puStack_10 = (undefined1 *)0x0;
          }
          puStack_8 = auStack_78;
          pcStack_7c = acStack_42 + -0xe;
          uStack_80 = 0x790fde;
          FUN_00765c50();
          pcStack_7c = (char *)0x2;
          uStack_80 = 0x790feb;
          (**(code **)(*DAT_00b5ad0c + 0x28))();
                    /* WARNING: Subroutine does not return */
          uStack_80 = 0x790ff4;
          FUN_00446f10();
        }
      }
    }
  }
  ExceptionList = puStack_10;
  return;
}


// ==== FUN_00791090 @ 0x00791090 ====

void FUN_00791090(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x50e0011;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  FUN_004244d0();
  return;
}


// ==== FUN_007910c0 @ 0x007910c0 ====

void FUN_007910c0(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x50e000f;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  FUN_004244d0();
  return;
}


// ==== FUN_007910f0 @ 0x007910f0 ====

void FUN_007910f0(byte param_1)

{
  void *in_ECX;
  
  FUN_007909c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00791110 @ 0x00791110 ====

void FUN_00791110(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f87a4;
  return;
}


// ==== FUN_00791120 @ 0x00791120 ====

undefined4 FUN_00791120(void)

{
  return 3;
}


// ==== FUN_00791130 @ 0x00791130 ====

void FUN_00791130(undefined1 param_1)

{
  FUN_00795dc0(&param_1);
  return;
}


// ==== FUN_00791140 @ 0x00791140 ====

void FUN_00791140(undefined1 param_1)

{
  FUN_007956e0(&param_1);
  return;
}


// ==== FUN_00791150 @ 0x00791150 ====

void FUN_00791150(undefined4 param_1)

{
  FUN_00796090(param_1);
  return;
}


// ==== FUN_00791160 @ 0x00791160 ====

void FUN_00791160(undefined4 param_1)

{
  FUN_00795a80(param_1);
  return;
}


// ==== FUN_00791170 @ 0x00791170 ====

void FUN_00791170(void)

{
  return;
}


// ==== FUN_00791180 @ 0x00791180 ====

void FUN_00791180(void)

{
  return;
}


// ==== FUN_00791190 @ 0x00791190 ====

void FUN_00791190(void)

{
  return;
}


// ==== FUN_007911a0 @ 0x007911a0 ====

void FUN_007911a0(void)

{
  return;
}


// ==== FUN_007911b0 @ 0x007911b0 ====

void FUN_007911b0(void)

{
  return;
}


// ==== FUN_007911f0 @ 0x007911f0 ====

undefined4 * FUN_007911f0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f8c38;
  return puVar1;
}


// ==== FUN_00791210 @ 0x00791210 ====

void FUN_00791210(byte param_1)

{
  void *in_ECX;
  
  FUN_00791110();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00791230 @ 0x00791230 ====

void FUN_00791230(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f87a4;
  return;
}


// ==== FUN_00791240 @ 0x00791240 ====

undefined4 FUN_00791240(void)

{
  return 1;
}


// ==== FUN_00791250 @ 0x00791250 ====

void FUN_00791250(undefined1 param_1)

{
  FUN_00795dc0(&param_1);
  return;
}


// ==== FUN_00791260 @ 0x00791260 ====

void FUN_00791260(undefined1 param_1)

{
  FUN_007956e0(&param_1);
  return;
}


// ==== FUN_00791270 @ 0x00791270 ====

void FUN_00791270(undefined4 param_1)

{
  FUN_00796090(param_1);
  return;
}


// ==== FUN_00791280 @ 0x00791280 ====

void FUN_00791280(undefined4 param_1)

{
  FUN_00795a80(param_1);
  return;
}


// ==== FUN_00791290 @ 0x00791290 ====

void FUN_00791290(void)

{
  return;
}


// ==== FUN_007912a0 @ 0x007912a0 ====

void FUN_007912a0(void)

{
  return;
}


// ==== FUN_007912b0 @ 0x007912b0 ====

void FUN_007912b0(void)

{
  return;
}


// ==== FUN_007912c0 @ 0x007912c0 ====

void FUN_007912c0(void)

{
  return;
}


// ==== FUN_007912d0 @ 0x007912d0 ====

void FUN_007912d0(void)

{
  return;
}


// ==== FUN_00791310 @ 0x00791310 ====

undefined4 * FUN_00791310(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f8cb0;
  return puVar1;
}


// ==== FUN_00791330 @ 0x00791330 ====

void FUN_00791330(byte param_1)

{
  void *in_ECX;
  
  FUN_00791230();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00791350 @ 0x00791350 ====

void FUN_00791350(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f87a4;
  return;
}


// ==== FUN_00791360 @ 0x00791360 ====

undefined4 FUN_00791360(void)

{
  return 0;
}


// ==== FUN_00791370 @ 0x00791370 ====

void FUN_00791370(undefined1 param_1)

{
  FUN_00795dc0(&param_1);
  return;
}


// ==== FUN_00791380 @ 0x00791380 ====

void FUN_00791380(undefined1 param_1)

{
  FUN_007956e0(&param_1);
  return;
}


// ==== FUN_00791390 @ 0x00791390 ====

void FUN_00791390(undefined4 param_1)

{
  FUN_00796090(param_1);
  return;
}


// ==== FUN_007913a0 @ 0x007913a0 ====

void FUN_007913a0(undefined4 param_1)

{
  FUN_00795a80(param_1);
  return;
}


// ==== FUN_007913b0 @ 0x007913b0 ====

void FUN_007913b0(undefined4 param_1,undefined4 param_2)

{
  FUN_00796250(param_1,param_2);
  return;
}


// ==== FUN_007913d0 @ 0x007913d0 ====

void FUN_007913d0(undefined4 param_1)

{
  FUN_007963b0(param_1);
  return;
}


// ==== FUN_007913e0 @ 0x007913e0 ====

void FUN_007913e0(undefined4 param_1,undefined4 param_2)

{
  FUN_00796570(param_1,param_2);
  return;
}


// ==== FUN_00791400 @ 0x00791400 ====

void FUN_00791400(undefined4 param_1)

{
  FUN_00796680(param_1);
  return;
}


// ==== FUN_00791410 @ 0x00791410 ====

void FUN_00791410(undefined3 param_1,undefined4 param_2)

{
  FUN_00796780(param_1,param_2);
  return;
}


// ==== FUN_00791450 @ 0x00791450 ====

bool FUN_00791450(void)

{
  char cVar1;
  
  cVar1 = FUN_00795cd0();
  return cVar1 == '\x01';
}


// ==== FUN_00791470 @ 0x00791470 ====

undefined4 * FUN_00791470(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f8d28;
  return puVar1;
}


// ==== FUN_00791490 @ 0x00791490 ====

void FUN_00791490(byte param_1)

{
  void *in_ECX;
  
  FUN_00791350();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007914b0 @ 0x007914b0 ====

void FUN_007914b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009e6d54;
  return;
}


// ==== FUN_007914d0 @ 0x007914d0 ====

undefined4 * FUN_007914d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f8db0;
  *(undefined1 *)(puVar1 + 1) = 0;
  return puVar1;
}


// ==== FUN_007914f0 @ 0x007914f0 ====

void FUN_007914f0(char param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    return;
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a9e0 + 0x14))();
  if (piVar1 == (int *)0x0) {
    return;
  }
  iVar2 = (**(code **)(*piVar1 + 8))();
  if (iVar2 == 0x14) {
    if (param_1 != '\0') {
      if (param_1 == '\x01') {
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        iVar2 = FUN_0075e310(uVar3);
        *(undefined4 *)(iVar2 + 0x10) = 0;
        FUN_004ef210(iVar2);
        *(undefined1 *)(in_ECX + 4) = 1;
        return;
      }
      goto LAB_007915a1;
    }
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 8))();
    if ((iVar2 != 0x13) || ((param_1 != '\0' && (param_1 != '\x01')))) goto LAB_007915a1;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  }
  iVar2 = FUN_0075e310(uVar3);
  *(undefined4 *)(iVar2 + 0x10) = 1;
  FUN_004d8570(iVar2);
LAB_007915a1:
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_007915b0 @ 0x007915b0 ====

void FUN_007915b0(byte param_1)

{
  void *in_ECX;
  
  FUN_007914b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007915d0 @ 0x007915d0 ====

void FUN_007915d0(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5100006;
  *(undefined2 *)((int)pvVar1 + 6) = 0x10;
  FUN_004244d0();
  return;
}


// ==== FUN_00791600 @ 0x00791600 ====

void FUN_00791600(int param_1)

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
    if (cVar2 == '\0') goto LAB_00791627;
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x19);
  *pcVar1 = '\0';
LAB_00791627:
  uVar4 = 0;
  do {
    if (pcVar1[uVar4] == '\0') goto LAB_00791640;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x19);
  uVar4 = 0;
LAB_00791640:
  *(short *)(in_ECX + 6) = (short)uVar4 + 0x11;
  return;
}


// ==== FUN_00791650 @ 0x00791650 ====

void FUN_00791650(char param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_32 [25];
  undefined1 auStack_19 [25];
  
  if (*(char *)(in_ECX + 0x3c) != '\0') {
    return;
  }
  if (param_1 == '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5100005;
    *(undefined2 *)((int)pvVar2 + 6) = 0x14;
    uVar1 = FUN_004244d0();
    if (*(uint *)(in_ECX + 0x1c) < 0x10) {
      iVar3 = in_ECX + 8;
    }
    else {
      iVar3 = *(int *)(in_ECX + 8);
    }
    FUN_0047aa30(auStack_32,&DAT_009f8e04,iVar3);
    if (*(uint *)(in_ECX + 0x38) < 0x10) {
      iVar3 = in_ECX + 0x24;
    }
    else {
      iVar3 = *(int *)(in_ECX + 0x24);
    }
    FUN_0047aa30(auStack_19,&DAT_009f8e04,iVar3);
    FUN_0075e430(1,auStack_19,auStack_32);
  }
  else {
    if (param_1 != '\x01') goto LAB_0079174a;
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uVar1 = FUN_007915d0(uVar1);
    if (*(uint *)(in_ECX + 0x1c) < 0x10) {
      iVar3 = in_ECX + 8;
    }
    else {
      iVar3 = *(int *)(in_ECX + 8);
    }
    FUN_0047aa30(auStack_19,&DAT_009f8e04,iVar3);
    FUN_00791600(auStack_19);
  }
  FUN_004d8570(uVar1);
LAB_0079174a:
  *(undefined1 *)(in_ECX + 0x3c) = 1;
  return;
}


// ==== FUN_00791760 @ 0x00791760 ====

void FUN_00791760(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8e10;
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
    *in_ECX = &PTR_FUN_009e6d54;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_007917c0 @ 0x007917c0 ====

void FUN_007917c0(undefined1 param_1,void *param_2)

{
  undefined4 *in_ECX;
  uint in_stack_0000001c;
  undefined1 uStack00000020;
  void *in_stack_00000024;
  uint in_stack_00000038;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009984e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f8e10;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  local_4 = 2;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401660(&param_1,0,0xffffffff);
  in_ECX[0xe] = 0xf;
  in_ECX[0xd] = 0;
  local_4 = CONCAT31(local_4._1_3_,3);
  *(undefined1 *)(in_ECX + 9) = 0;
  FUN_00401660(&uStack00000020,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0xf) = 0;
  if (0xf < in_stack_0000001c) {
    _free(param_2);
    return;
  }
  if (in_stack_00000038 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000024);
  return;
}


// ==== FUN_00791870 @ 0x00791870 ====

undefined4 FUN_00791870(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00998500;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x40);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  FUN_00401660();
  local_4._0_1_ = 1;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = (uint)local_4._1_3_ << 8;
  uVar2 = FUN_007917c0();
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_00791920 @ 0x00791920 ====

void FUN_00791920(byte param_1)

{
  void *in_ECX;
  
  FUN_00791760();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00791940 @ 0x00791940 ====

undefined4 FUN_00791940(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00791950 @ 0x00791950 ====

int FUN_00791950(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00791960 @ 0x00791960 ====

void FUN_00791960(undefined4 param_1)

{
  int in_ECX;
  undefined4 unaff_retaddr;
  
  if (*(undefined4 **)(in_ECX + 0x34) == (undefined4 *)0x0) {
    *(undefined4 *)(in_ECX + 0x34) = param_1;
    return;
  }
  (**(code **)**(undefined4 **)(in_ECX + 0x34))(1);
  *(undefined4 *)(in_ECX + 0x34) = unaff_retaddr;
  return;
}


// ==== FUN_00791990 @ 0x00791990 ====

void FUN_00791990(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x34) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0079199b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x34) + 4))();
  return;
}


// ==== FUN_007919b0 @ 0x007919b0 ====

void FUN_007919b0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  FUN_00401660(param_2,0,0xffffffff);
  return;
}


// ==== FUN_007919d0 @ 0x007919d0 ====

void FUN_007919d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998526;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f8e5c;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  local_4 = 1;
  in_ECX[1] = 0x1b;
  FUN_00401740(&DAT_009f8e52,0);
  in_ECX[0xd] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00791a40 @ 0x00791a40 ====

void FUN_00791a40(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998546;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f8e5c;
  local_4 = 1;
  if ((undefined4 *)in_ECX[0xd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xd])(1);
  }
  in_ECX[0xd] = 0;
  if (in_ECX[10] != 0) {
    FUN_00405de0(in_ECX[10],in_ECX[0xb],in_ECX + 9,in_ECX);
    _free((void *)in_ECX[10]);
    return;
  }
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[7] = 0;
    in_ECX[8] = 0xf;
    *(undefined1 *)(in_ECX + 3) = 0;
    ExceptionList = pvStack_c;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_00791ae0 @ 0x00791ae0 ====

undefined4 FUN_00791ae0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_00406600(in_ECX + 0x24);
  return param_1;
}


// ==== FUN_00791b00 @ 0x00791b00 ====

void FUN_00791b00(undefined4 param_1,void *param_2,undefined4 param_3)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998558;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_0043b3d0(&param_1);
  if (param_2 == (void *)0x0) {
    ExceptionList = local_c;
    return;
  }
  FUN_00405de0(param_2,param_3,&param_1,param_1);
  _free(param_2);
  return;
}


// ==== FUN_00791b70 @ 0x00791b70 ====

void FUN_00791b70(byte param_1)

{
  void *in_ECX;
  
  FUN_00791a40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00791b90 @ 0x00791b90 ====

void FUN_00791b90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8e80;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00791bb0 @ 0x00791bb0 ====

void FUN_00791bb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8e80;
  return;
}


// ==== FUN_00791bc0 @ 0x00791bc0 ====

void FUN_00791bc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8e88;
  return;
}


// ==== FUN_00791bd0 @ 0x00791bd0 ====

void FUN_00791bd0(byte param_1)

{
  void *in_ECX;
  
  FUN_00791bb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00791bf0 @ 0x00791bf0 ====

void FUN_00791bf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f18;
  return;
}


// ==== FUN_00791c00 @ 0x00791c00 ====

void FUN_00791c00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00791c20 @ 0x00791c20 ====

undefined4 FUN_00791c20(int param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099857b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x10);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_007968d0(in_ECX + 4 + param_1 * 0xc);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_00791ca0 @ 0x00791ca0 ====

void FUN_00791ca0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00791cb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)();
  return;
}


// ==== FUN_00791cc0 @ 0x00791cc0 ====

undefined4 FUN_00791cc0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  FILE *_File;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099858d;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_004020e0(&DAT_009f8ec8,4);
  puVar1 = param_2;
  if (in_stack_0000001c < 0x10) {
    puVar1 = &param_2;
  }
  _File = (FILE *)FUN_00803b27(puVar1,&DAT_009f8ed0);
  if (_File == (FILE *)0x0) {
    if (in_stack_0000001c < 0x10) {
      ExceptionList = local_c;
      return 0;
    }
    _free(param_2);
    return extraout_EAX_00;
  }
  _fclose(_File);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return 1;
  }
  _free(param_2);
  return extraout_EAX;
}


// ==== FUN_00791d70 @ 0x00791d70 ====

/* WARNING: Removing unreachable block (ram,0x0079200e) */

int FUN_00791d70(int param_1)

{
  char cVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int extraout_EAX_02;
  int extraout_EAX_03;
  int extraout_EAX_04;
  int iVar2;
  void *local_b8;
  uint local_a4;
  void *local_98;
  uint local_84;
  _SYSTEMTIME local_80;
  undefined1 local_70 [4];
  void *local_6c;
  undefined4 local_5c;
  uint local_58;
  void *local_50;
  undefined4 local_40;
  uint local_3c;
  void *local_34;
  uint local_20;
  _SYSTEMTIME local_1c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009985d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00404890();
  local_4 = 0;
  FUN_004045b0();
  local_4._0_1_ = 2;
  if (0xf < local_a4) {
    _free(local_b8);
    return extraout_EAX;
  }
  FUN_004046f0();
  local_4._0_1_ = 3;
  FUN_00402220();
  local_4._0_1_ = 5;
  if (0xf < local_3c) {
    _free(local_50);
    return extraout_EAX_00;
  }
  local_3c = 0xf;
  local_40 = 0;
  local_50 = (void *)((uint)local_50 & 0xffffff00);
  GetSystemTime(&local_1c);
  GetLocalTime(&local_80);
  FUN_00401740(s__02d_02d_02d__02d_02d_009f8ee4,0x15);
  FUN_00404230(local_70);
  local_4._0_1_ = 6;
  FUN_00401ff0();
  local_4._0_1_ = 5;
  if (0xf < local_58) {
    _free(local_6c);
    return extraout_EAX_01;
  }
  FUN_00401660();
  cVar1 = FUN_00791cc0();
  if (cVar1 == '\x01') {
    local_4._0_1_ = 7;
    iVar2 = 1;
    do {
      FUN_00401660();
      FUN_00401740();
      FUN_00404230();
      local_4._0_1_ = 8;
      FUN_00401ff0();
      local_4._0_1_ = 7;
      if (0xf < local_58) {
        _free(local_6c);
        return extraout_EAX_02;
      }
      local_58 = 0xf;
      local_5c = 0;
      local_6c = (void *)((uint)local_6c & 0xffffff00);
      FUN_00401660();
      cVar1 = FUN_00791cc0();
      if (cVar1 == '\0') {
        FUN_00401660();
        break;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 100);
    local_4._0_1_ = 5;
  }
  FUN_004020e0();
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660();
  if (0xf < local_84) {
    _free(local_98);
    return extraout_EAX_03;
  }
  if (local_20 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_34);
  return extraout_EAX_04;
}


// ==== FUN_007920a0 @ 0x007920a0 ====

void FUN_007920a0(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *_Memory;
  int iVar3;
  int in_ECX;
  
  iVar1 = in_ECX + param_1 * 0xc;
  if ((*(uint *)(in_ECX + 0xc + param_1 * 0xc) < 0x65) ||
     (piVar2 = *(int **)(iVar1 + 8), _Memory = (int *)*piVar2, _Memory == piVar2)) {
    iVar1 = *(int *)(iVar1 + 8);
    iVar3 = FUN_00792660(iVar1,*(undefined4 *)(iVar1 + 4),param_2);
    FUN_007925c0(1);
    *(int *)(iVar1 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
    return;
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  FUN_00792590();
  _free(_Memory);
  return;
}


// ==== FUN_00792110 @ 0x00792110 ====

void FUN_00792110(undefined4 *param_1)

{
  undefined4 uVar1;
  
  FUN_007920a0(0,param_1);
  switch(*param_1) {
  case 2:
    uVar1 = 1;
    break;
  case 3:
  case 6:
  case 9:
    FUN_007920a0(1,param_1);
    FUN_007920a0(2,param_1);
    FUN_007920a0(3,param_1);
    return;
  case 4:
  case 5:
    FUN_007920a0(2,param_1);
    FUN_007920a0(1,param_1);
    return;
  case 7:
    FUN_007920a0(3,param_1);
    FUN_007920a0(1,param_1);
    return;
  case 8:
    FUN_007920a0(3,param_1);
    FUN_007920a0(4,param_1);
  case 0:
  case 1:
    FUN_007920a0(1,param_1);
    return;
  case 10:
    FUN_007920a0(4,param_1);
    return;
  case 0xb:
    FUN_007920a0(1,param_1);
    FUN_007920a0(2,param_1);
    FUN_007920a0(3,param_1);
    uVar1 = 4;
    break;
  case 0xc:
    goto switchD_0079212b_caseD_c;
  default:
    return;
  }
  FUN_007920a0(uVar1,param_1);
switchD_0079212b_caseD_c:
  FUN_007920a0(5,param_1);
  return;
}


// ==== FUN_00792230 @ 0x00792230 ====

void FUN_00792230(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009985ea;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f8f30;
  _eh_vector_constructor_iterator_(in_ECX + 1,0xc,6,FUN_00792570,FUN_00792740);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00792290 @ 0x00792290 ====

void FUN_00792290(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009985fc;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f8f30;
  local_4 = 0;
  _eh_vector_destructor_iterator_(in_ECX + 1,0xc,6,FUN_00792740);
  *in_ECX = &PTR_FUN_009f8f18;
  ExceptionList = local_c;
  return;
}


// ==== FUN_007922f0 @ 0x007922f0 ====

void FUN_007922f0(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_68 [4];
  void *local_64;
  undefined4 local_54;
  void *local_50;
  uint uStack_3c;
  undefined4 local_30;
  undefined4 local_2c;
  void *local_24;
  void *local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00998634;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00791d70();
  puVar1 = *(undefined4 **)(in_ECX + 8 + param_1 * 0xc);
  puVar2 = (undefined4 *)*puVar1;
  local_4._1_3_ = 0;
  while( true ) {
    if (puVar2 == puVar1) {
      local_4._0_1_ = 2;
      (**(code **)(*DAT_00b5a740 + 0xc))();
      FUN_004137c0();
      if (uStack_3c < 0x10) {
        ExceptionList = local_14;
        return;
      }
      _free(local_50);
      return;
    }
    local_4._0_1_ = 2;
    local_30 = puVar2[2];
    local_2c = puVar2[3];
    local_10 = 0xf;
    local_14 = (void *)0x0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401660();
    local_4._0_1_ = 3;
    FUN_00401740(&DAT_009f8f0c,2);
    FUN_00404230(local_68);
    local_4._0_1_ = 4;
    FUN_00411630();
    if ((void *)0xf < local_50) {
      _free(local_64);
      return;
    }
    puVar2 = (undefined4 *)*puVar2;
    local_50 = (void *)0xf;
    local_54 = 0;
    local_64 = (void *)((uint)local_64 & 0xffffff00);
    local_4._0_1_ = 2;
    if (0xf < local_10) break;
    local_10 = 0xf;
    local_14 = (void *)0x0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
  }
  _free(local_24);
  return;
}


// ==== FUN_007924a0 @ 0x007924a0 ====

void FUN_007924a0(void)

{
  char cVar1;
  char ****ppppcVar2;
  char ****ppppcVar3;
  uint unaff_EDI;
  undefined1 auStack_5c [4];
  undefined1 uStack_58;
  undefined4 uStack_50;
  void *pvStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  char ****appppcStack_2c [4];
  undefined4 uStack_1c;
  uint uStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998646;
  pvStack_c = ExceptionList;
  uStack_3c = 0;
  uStack_40 = 0x7924c3;
  ExceptionList = &pvStack_c;
  FUN_007922f0();
  uStack_3c = 0x3200002;
  uStack_40 = 0;
  uStack_44 = 0x7924d4;
  pvStack_4c = (void *)(**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_44 = 0xffffffff;
  uStack_48 = 0;
  uStack_18 = 0xf;
  uStack_1c = 0;
  appppcStack_2c[0] = (char ****)((uint)appppcStack_2c[0] & 0xffffff00);
  uStack_50 = 0x7924f2;
  FUN_00401660();
  pvStack_c = (void *)0x0;
  ppppcVar3 = appppcStack_2c[0];
  if (uStack_18 < 0x10) {
    ppppcVar3 = (char ****)appppcStack_2c;
  }
  uStack_44 = 0xf;
  uStack_48 = 0;
  uStack_58 = 0;
  ppppcVar2 = ppppcVar3;
  do {
    cVar1 = *(char *)ppppcVar2;
    ppppcVar2 = (char ****)((int)ppppcVar2 + 1);
  } while (cVar1 != '\0');
  FUN_00401740(ppppcVar3,(int)ppppcVar2 - (int)((int)ppppcVar3 + 1));
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  if (unaff_EDI < 0x10) {
    ExceptionList = auStack_5c;
    return;
  }
  _free(pvStack_4c);
  return;
}


// ==== FUN_00792570 @ 0x00792570 ====

void FUN_00792570(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_004a0840();
  *(undefined4 *)(in_ECX + 4) = uVar1;
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00792590 @ 0x00792590 ====

void FUN_00792590(void)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x28) < 0x10) {
    *(undefined4 *)(in_ECX + 0x28) = 0xf;
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined1 *)(in_ECX + 0x14) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_007925c0 @ 0x007925c0 ====

void FUN_007925c0(uint param_1)

{
  int in_ECX;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00998658;
  local_c = ExceptionList;
  if (0x71c71c7U - *(int *)(in_ECX + 8) < param_1) {
    local_38 = 0xf;
    local_3c = 0;
    local_4c = 0;
    ExceptionList = &local_c;
    FUN_00401740(s_list<T>_too_long_0099d1d0,0x10);
    local_4 = 0;
    FUN_00403770(local_50);
    local_34[0] = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
    __CxxThrowException_8(local_34,&DAT_00a9c48c);
  }
  *(uint *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return;
}


// ==== FUN_00792660 @ 0x00792660 ====

undefined4 * FUN_00792660(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00998681;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x2c);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = *param_3;
    puVar1[3] = param_3[1];
    puVar1[10] = 0xf;
    puVar1[9] = 0;
    *(undefined1 *)(puVar1 + 5) = 0;
    FUN_00401660(param_3 + 2,0,0xffffffff);
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@007926ea @ 0x007926ea ====

void Catch_007926ea(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00792700 @ 0x00792700 ====

void FUN_00792700(void)

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
  FUN_00792590();
  _free(_Memory);
  return;
}


// ==== FUN_00792740 @ 0x00792740 ====

void FUN_00792740(void)

{
  int in_ECX;
  
  FUN_00792700();
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00792760 @ 0x00792760 ====

void FUN_00792760(byte param_1)

{
  void *in_ECX;
  
  FUN_00792290();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00792780 @ 0x00792780 ====

void FUN_00792780(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007927a0 @ 0x007927a0 ====

void FUN_007927a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_007927e0 @ 0x007927e0 ====

undefined4 * FUN_007927e0(undefined2 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f8fa8;
  *(undefined2 *)(puVar1 + 1) = param_1;
  *(undefined1 *)((int)puVar1 + 6) = 0;
  return puVar1;
}


// ==== FUN_00792810 @ 0x00792810 ====

void FUN_00792810(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 6) == '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5300005;
    *(undefined2 *)((int)pvVar2 + 6) = 0x14;
    iVar3 = FUN_004244d0();
    *(undefined2 *)(iVar3 + 0x10) = *(undefined2 *)(in_ECX + 4);
    FUN_004d8570(iVar3);
    *(undefined1 *)(in_ECX + 6) = 1;
                    /* WARNING: Could not recover jumptable at 0x00792875. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5af2c + 4))();
    return;
  }
  return;
}


// ==== FUN_00792880 @ 0x00792880 ====

void FUN_00792880(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5300015;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_007928e0 @ 0x007928e0 ====

void FUN_007928e0(byte param_1)

{
  void *in_ECX;
  
  FUN_007927a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00792900 @ 0x00792900 ====

void FUN_00792900(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_00792940 @ 0x00792940 ====

undefined4 * FUN_00792940(undefined2 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f9008;
  *(undefined2 *)(puVar1 + 1) = param_1;
  *(undefined1 *)((int)puVar1 + 6) = 0;
  return puVar1;
}


// ==== FUN_00792970 @ 0x00792970 ====

void FUN_00792970(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 6) == '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5300002;
    *(undefined2 *)((int)pvVar2 + 6) = 0x14;
    iVar3 = FUN_004244d0();
    *(undefined2 *)(iVar3 + 0x10) = *(undefined2 *)(in_ECX + 4);
    FUN_004d8570(iVar3);
    *(undefined1 *)(in_ECX + 6) = 1;
                    /* WARNING: Could not recover jumptable at 0x007929d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5af2c + 4))();
    return;
  }
  return;
}


// ==== FUN_007929e0 @ 0x007929e0 ====

void FUN_007929e0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5300015;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_00792a40 @ 0x00792a40 ====

void FUN_00792a40(byte param_1)

{
  void *in_ECX;
  
  FUN_00792900();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00792a60 @ 0x00792a60 ====

void FUN_00792a60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_00792aa0 @ 0x00792aa0 ====

undefined4 * FUN_00792aa0(undefined4 param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f9068;
  puVar1[1] = param_1;
  *(undefined2 *)(puVar1 + 2) = param_2;
  *(undefined1 *)((int)puVar1 + 10) = 0;
  return puVar1;
}


// ==== FUN_00792ad0 @ 0x00792ad0 ====

void FUN_00792ad0(undefined2 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 10) == '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5260003;
    *(undefined2 *)((int)pvVar2 + 6) = 0x18;
    iVar3 = FUN_004244d0();
    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(in_ECX + 4);
    *(undefined2 *)(iVar3 + 0x14) = *(undefined2 *)(in_ECX + 8);
    *(undefined2 *)(iVar3 + 0x16) = param_1;
    FUN_004d8570(iVar3);
    *(undefined1 *)(in_ECX + 10) = 1;
  }
  return;
}


// ==== FUN_00792b40 @ 0x00792b40 ====

void FUN_00792b40(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5050007;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_00792ba0 @ 0x00792ba0 ====

void FUN_00792ba0(byte param_1)

{
  void *in_ECX;
  
  FUN_00792a60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00792bc0 @ 0x00792bc0 ====

void FUN_00792bc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_00792c00 @ 0x00792c00 ====

undefined4 * FUN_00792c00(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f90c8;
  puVar1[1] = param_1;
  *(undefined1 *)(puVar1 + 2) = 0;
  return puVar1;
}


// ==== FUN_00792c30 @ 0x00792c30 ====

void FUN_00792c30(undefined1 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) == '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5050003;
    *(undefined2 *)((int)pvVar2 + 6) = 0x18;
    iVar3 = FUN_004244d0();
    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(in_ECX + 4);
    *(undefined1 *)(iVar3 + 0x14) = param_1;
    FUN_004d8570(iVar3);
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_00792c90 @ 0x00792c90 ====

void FUN_00792c90(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5050007;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_00792cf0 @ 0x00792cf0 ====

void FUN_00792cf0(byte param_1)

{
  void *in_ECX;
  
  FUN_00792bc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00792d10 @ 0x00792d10 ====

void FUN_00792d10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_00792d50 @ 0x00792d50 ====

undefined4 * FUN_00792d50(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f9128;
  puVar1[1] = param_1;
  *(undefined1 *)(puVar1 + 2) = 0;
  return puVar1;
}


// ==== FUN_00792d80 @ 0x00792d80 ====

void FUN_00792d80(void)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) == '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x51f0000;
    *(undefined2 *)((int)pvVar2 + 6) = 0x14;
    uVar1 = FUN_004244d0();
    FUN_004d8570(uVar1);
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_00792dd0 @ 0x00792dd0 ====

void FUN_00792dd0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x51f0001;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_00792e30 @ 0x00792e30 ====

void FUN_00792e30(byte param_1)

{
  void *in_ECX;
  
  FUN_00792d10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00792e50 @ 0x00792e50 ====

void FUN_00792e50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_00792e90 @ 0x00792e90 ====

void FUN_00792e90(int param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 6) != '\0') {
    return;
  }
  if (param_1 == 0) {
    (**(code **)(*DAT_00b5ac94 + 0x74))();
  }
  else {
    (**(code **)(*DAT_00b5ac94 + 0x80))();
  }
  *(undefined1 *)(in_ECX + 6) = 1;
                    /* WARNING: Could not recover jumptable at 0x00792eca. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5af2c + 4))();
  return;
}


// ==== FUN_00792ee0 @ 0x00792ee0 ====

void FUN_00792ee0(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5ac94 + 0x80))();
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_00792f10 @ 0x00792f10 ====

undefined4 * FUN_00792f10(undefined2 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f9188;
  *(undefined2 *)(puVar1 + 1) = param_1;
  *(undefined1 *)((int)puVar1 + 6) = 0;
  return puVar1;
}


// ==== FUN_00792f40 @ 0x00792f40 ====

void FUN_00792f40(byte param_1)

{
  void *in_ECX;
  
  FUN_00792e50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00792f60 @ 0x00792f60 ====

void FUN_00792f60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_00792fa0 @ 0x00792fa0 ====

void FUN_00792fa0(int param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 6) != '\0') {
    return;
  }
  if (param_1 == 0) {
    (**(code **)(*DAT_00b5ac94 + 0x70))();
  }
  else {
    (**(code **)(*DAT_00b5ac94 + 0x7c))();
  }
  *(undefined1 *)(in_ECX + 6) = 1;
                    /* WARNING: Could not recover jumptable at 0x00792fd7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5af2c + 4))();
  return;
}


// ==== FUN_00792fe0 @ 0x00792fe0 ====

void FUN_00792fe0(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5ac94 + 0x7c))();
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_00793010 @ 0x00793010 ====

undefined4 * FUN_00793010(undefined2 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f91e8;
  *(undefined2 *)(puVar1 + 1) = param_1;
  *(undefined1 *)((int)puVar1 + 6) = 0;
  return puVar1;
}


// ==== FUN_00793040 @ 0x00793040 ====

void FUN_00793040(byte param_1)

{
  void *in_ECX;
  
  FUN_00792f60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00793060 @ 0x00793060 ====

void FUN_00793060(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_00793090 @ 0x00793090 ====

void FUN_00793090(int param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    return;
  }
  if (param_1 == 0) {
    (**(code **)(*DAT_00b5ac94 + 0x8c))();
  }
  else {
    (**(code **)(*DAT_00b5ac94 + 0x80))();
  }
  *(undefined1 *)(in_ECX + 4) = 1;
                    /* WARNING: Could not recover jumptable at 0x007930cd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5af2c + 4))();
  return;
}


// ==== FUN_007930e0 @ 0x007930e0 ====

void FUN_007930e0(void)

{
  char cVar1;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5ac94 + 0x90))();
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_00793110 @ 0x00793110 ====

undefined4 * FUN_00793110(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f9248;
  *(undefined1 *)(puVar1 + 1) = 0;
  return puVar1;
}


// ==== FUN_00793130 @ 0x00793130 ====

void FUN_00793130(byte param_1)

{
  void *in_ECX;
  
  FUN_00793060();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00793150 @ 0x00793150 ====

void FUN_00793150(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_00793190 @ 0x00793190 ====

void FUN_00793190(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 6) == '\0') {
    (**(code **)(*DAT_00b5ac94 + 0x88))();
    (**(code **)(*DAT_00b5af2c + 4))(4);
    *(undefined1 *)(in_ECX + 6) = 1;
  }
  return;
}


// ==== FUN_007931c0 @ 0x007931c0 ====

undefined4 * FUN_007931c0(undefined2 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f92a8;
  *(undefined2 *)(puVar1 + 1) = param_1;
  *(undefined1 *)((int)puVar1 + 6) = 0;
  return puVar1;
}


// ==== FUN_007931f0 @ 0x007931f0 ====

void FUN_007931f0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5280008;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_00793250 @ 0x00793250 ====

void FUN_00793250(byte param_1)

{
  void *in_ECX;
  
  FUN_00793150();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00793270 @ 0x00793270 ====

void FUN_00793270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_007932a0 @ 0x007932a0 ====

void FUN_007932a0(void)

{
  (**(code **)(*DAT_00b5af2c + 8))(4);
  (**(code **)(*DAT_00b5aee8 + 0x14))();
  (**(code **)(*DAT_00b5acd4 + 4))(0);
  return;
}


// ==== FUN_007932d0 @ 0x007932d0 ====

undefined4 * FUN_007932d0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f9308;
  *(undefined1 *)(puVar1 + 1) = 0;
  return puVar1;
}


// ==== FUN_007932f0 @ 0x007932f0 ====

void FUN_007932f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00793270();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00793310 @ 0x00793310 ====

void FUN_00793310(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_00793350 @ 0x00793350 ====

void FUN_00793350(int param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 6) == '\0') {
    if (param_1 == 0) {
      (**(code **)(*DAT_00b5ac94 + 0xc))();
      (**(code **)(*DAT_00b5af2c + 4))(4);
      *(undefined1 *)(in_ECX + 6) = 1;
      return;
    }
    (**(code **)(*DAT_00b5ac94 + 0x84))();
    *(undefined1 *)(in_ECX + 6) = 1;
  }
  return;
}


// ==== FUN_00793390 @ 0x00793390 ====

undefined4 * FUN_00793390(undefined2 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f9368;
  *(undefined2 *)(puVar1 + 1) = param_1;
  *(undefined1 *)((int)puVar1 + 6) = 0;
  return puVar1;
}


// ==== FUN_007933c0 @ 0x007933c0 ====

void FUN_007933c0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5050007;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_00793420 @ 0x00793420 ====

void FUN_00793420(byte param_1)

{
  void *in_ECX;
  
  FUN_00793310();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00793440 @ 0x00793440 ====

void FUN_00793440(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_00793480 @ 0x00793480 ====

undefined4 * FUN_00793480(undefined2 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f93c8;
  *(undefined2 *)(puVar1 + 1) = param_1;
  *(undefined1 *)((int)puVar1 + 6) = 0;
  return puVar1;
}


// ==== FUN_007934b0 @ 0x007934b0 ====

void FUN_007934b0(undefined4 param_1)

{
  undefined2 uVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 6) == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5280001;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    uVar1 = (**(code **)(*DAT_00b5ac98 + 0xc))(param_1);
    *(undefined2 *)(iVar4 + 0x10) = uVar1;
    FUN_004d8570(iVar4);
    *(undefined1 *)(in_ECX + 6) = 1;
                    /* WARNING: Could not recover jumptable at 0x00793523. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5af2c + 4))();
    return;
  }
  return;
}


// ==== FUN_00793530 @ 0x00793530 ====

void FUN_00793530(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5050007;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_00793590 @ 0x00793590 ====

void FUN_00793590(byte param_1)

{
  void *in_ECX;
  
  FUN_00793440();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007935b0 @ 0x007935b0 ====

void FUN_007935b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_00793600 @ 0x00793600 ====

undefined4 * FUN_00793600(undefined2 param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f9428;
  *(undefined2 *)(puVar1 + 1) = param_1;
  *(undefined2 *)((int)puVar1 + 6) = param_2;
  *(undefined1 *)(puVar1 + 2) = 0;
  return puVar1;
}


// ==== FUN_00793630 @ 0x00793630 ====

void FUN_00793630(undefined2 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) == '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x5170001;
    *(undefined2 *)((int)pvVar2 + 6) = 0x18;
    iVar3 = FUN_004244d0();
    *(undefined2 *)(iVar3 + 0x10) = *(undefined2 *)(in_ECX + 4);
    *(undefined2 *)(iVar3 + 0x12) = *(undefined2 *)(in_ECX + 6);
    *(undefined2 *)(iVar3 + 0x14) = param_1;
    FUN_004d8570(iVar3);
    *(undefined1 *)(in_ECX + 8) = 1;
                    /* WARNING: Could not recover jumptable at 0x007936a6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*DAT_00b5af2c + 4))();
    return;
  }
  return;
}


// ==== FUN_007936b0 @ 0x007936b0 ====

void FUN_007936b0(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5050007;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_00793710 @ 0x00793710 ====

void FUN_00793710(byte param_1)

{
  void *in_ECX;
  
  FUN_007935b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00793730 @ 0x00793730 ====

void FUN_00793730(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f8f98;
  return;
}


// ==== FUN_00793770 @ 0x00793770 ====

undefined4 * FUN_00793770(undefined4 param_1,undefined2 param_2)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f9488;
  puVar1[1] = param_1;
  *(undefined2 *)(puVar1 + 2) = param_2;
  *(undefined1 *)((int)puVar1 + 10) = 0;
  return puVar1;
}


// ==== FUN_007937a0 @ 0x007937a0 ====

void FUN_007937a0(undefined2 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  
  if (*(char *)(in_ECX + 10) == '\0') {
    uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar2 = operator_new(0x400);
    *(undefined4 *)((int)pvVar2 + 8) = uVar1;
    *(undefined4 *)((int)pvVar2 + 0xc) = 0x50f0008;
    *(undefined2 *)((int)pvVar2 + 6) = 0x18;
    iVar3 = FUN_004244d0();
    *(undefined4 *)(iVar3 + 0x10) = *(undefined4 *)(in_ECX + 4);
    *(undefined2 *)(iVar3 + 0x14) = *(undefined2 *)(in_ECX + 8);
    *(undefined2 *)(iVar3 + 0x16) = param_1;
    FUN_004d8570(iVar3);
    *(undefined1 *)(in_ECX + 10) = 1;
  }
  return;
}


// ==== FUN_00793810 @ 0x00793810 ====

void FUN_00793810(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(4);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5050007;
    *(undefined2 *)((int)pvVar3 + 6) = 0x10;
    uVar2 = FUN_004244d0();
    FUN_004d8570(uVar2);
    (**(code **)(*DAT_00b5af2c + 4))(4);
  }
  return;
}


// ==== FUN_00793870 @ 0x00793870 ====

void FUN_00793870(byte param_1)

{
  void *in_ECX;
  
  FUN_00793730();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00793890 @ 0x00793890 ====

void FUN_00793890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f94d8;
  return;
}


// ==== FUN_007938a0 @ 0x007938a0 ====

void FUN_007938a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f94d8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007938c0 @ 0x007938c0 ====

int FUN_007938c0(void)

{
  int in_ECX;
  
  return in_ECX + 0x14;
}


// ==== FUN_007938d0 @ 0x007938d0 ====

void FUN_007938d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x34) == 0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x007938db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x34) + 4))();
  return;
}


// ==== FUN_007938f0 @ 0x007938f0 ====

undefined1 FUN_007938f0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x30);
}


// ==== FUN_00793900 @ 0x00793900 ====

void FUN_00793900(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x30) = param_1;
  return;
}


// ==== FUN_00793910 @ 0x00793910 ====

int FUN_00793910(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8) >> 5;
}


// ==== FUN_00793930 @ 0x00793930 ====

void FUN_00793930(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x34) == 0) {
    (**(code **)(*DAT_00b5aee8 + 0x14))();
    (**(code **)(*DAT_00b5acd4 + 4))(0);
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0079393b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x34) + 8))();
  return;
}


// ==== FUN_00793960 @ 0x00793960 ====

int FUN_00793960(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 5) <= param_1)) {
    param_1 = FUN_00793b40();
  }
  return param_1 * 0x20 + iVar1;
}


// ==== FUN_00793990 @ 0x00793990 ====

void FUN_00793990(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9504;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0xf;
  *(undefined1 *)(in_ECX + 6) = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  in_ECX[0xd] = 0;
  return;
}


// ==== FUN_007939e0 @ 0x007939e0 ====

void FUN_007939e0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998740;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f9504;
  local_4 = 2;
  FUN_00793e00();
  if ((undefined4 *)in_ECX[0xd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xd])(1);
  }
  in_ECX[0xd] = 0;
  if ((uint)in_ECX[0xb] < 0x10) {
    in_ECX[0xb] = 0xf;
    in_ECX[10] = 0;
    *(undefined1 *)(in_ECX + 6) = 0;
    FUN_00793e00();
    *in_ECX = &PTR_FUN_009f94d8;
    ExceptionList = pvStack_c;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00793a70 @ 0x00793a70 ====

void FUN_00793a70(undefined1 param_1,void *param_2)

{
  int in_ECX;
  uint in_stack_0000001c;
  undefined4 in_stack_00000020;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998752;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(&param_1,0,0xffffffff);
  FUN_00793e00();
  if (*(undefined4 **)(in_ECX + 0x34) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x34))(1);
  }
  *(undefined4 *)(in_ECX + 0x34) = in_stack_00000020;
  if (in_stack_0000001c < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00793af0 @ 0x00793af0 ====

void FUN_00793af0(undefined1 param_1,void *param_2)

{
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998764;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00794160(&param_1);
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(param_2);
  return;
}


// ==== FUN_00793b40 @ 0x00793b40 ====

void FUN_00793b40(void)

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
  puStack_8 = &LAB_00998698;
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


// ==== FUN_00793bb0 @ 0x00793bb0 ====

void FUN_00793bb0(void)

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
  puStack_8 = &LAB_00998698;
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


// ==== FUN_00793c20 @ 0x00793c20 ====

void FUN_00793c20(int param_1,int param_2,int param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    FUN_00401660(param_3,0,0xffffffff);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
  }
  return;
}


// ==== FUN_00793c50 @ 0x00793c50 ====

int FUN_00793c50(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009986c1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    local_8 = 1;
    if (param_3 != 0) {
      *(undefined4 *)(param_3 + 0x18) = 0xf;
      *(undefined4 *)(param_3 + 0x14) = 0;
      *(undefined1 *)(param_3 + 4) = 0;
      FUN_00401660(param_1,0,0xffffffff);
      *(undefined4 *)(param_3 + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
    }
    param_3 = param_3 + 0x20;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00793cbc @ 0x00793cbc ====

void Catch_00793cbc(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  iVar1 = *(int *)(unaff_EBP + 0x10);
  while( true ) {
    if (iVar2 == iVar1) {
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(0,0);
    }
    if (0xf < *(uint *)(iVar2 + 0x18)) break;
    *(undefined4 *)(iVar2 + 0x18) = 0xf;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined1 *)(iVar2 + 4) = 0;
    iVar2 = iVar2 + 0x20;
  }
  _free(*(void **)(iVar2 + 4));
  return;
}


// ==== FUN_00793d10 @ 0x00793d10 ====

void FUN_00793d10(int param_1,int param_2)

{
  if (param_1 != param_2) {
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return;
}


// ==== FUN_00793d40 @ 0x00793d40 ====

void FUN_00793d40(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009986e1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401660(param_3,0,0xffffffff);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_3 + 0x1c);
    }
    param_1 = param_1 + 0x20;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00793db1 @ 0x00793db1 ====

void Catch_00793db1(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  iVar1 = *(int *)(unaff_EBP + 8);
  while( true ) {
    if (iVar2 == iVar1) {
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(0,0);
    }
    if (0xf < *(uint *)(iVar2 + 0x18)) break;
    *(undefined4 *)(iVar2 + 0x18) = 0xf;
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined1 *)(iVar2 + 4) = 0;
    iVar2 = iVar2 + 0x20;
  }
  _free(*(void **)(iVar2 + 4));
  return;
}


// ==== FUN_00793e00 @ 0x00793e00 ====

void FUN_00793e00(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00793e50 @ 0x00793e50 ====

void FUN_00793e50(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  if (*(int *)(in_ECX + 4) != *(int *)(in_ECX + 8)) {
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00793e60 @ 0x00793e60 ====

int FUN_00793e60(int param_1,int param_2,undefined4 param_3)

{
  FUN_00793d40(param_1,param_2,param_3);
  return param_2 * 0x20 + param_1;
}


// ==== FUN_00793e90 @ 0x00793e90 ====

void FUN_00793e90(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  int extraout_ECX;
  int iVar5;
  undefined1 local_3c [2];
  undefined1 auStack_3a [2];
  void *local_38;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009986f8;
  local_10 = ExceptionList;
  local_14 = local_3c + -0xc;
  local_24 = 0xf;
  local_28 = 0;
  local_38 = (void *)((uint)local_38 & 0xffffff00);
  ExceptionList = &local_10;
  FUN_00401660(param_3,0,0xffffffff);
  local_20 = *(undefined4 *)(param_3 + 0x1c);
  iVar2 = *(int *)(in_ECX + 4);
  local_8 = 0;
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(in_ECX + 0xc) - iVar2 >> 5;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
    }
    if (0x7ffffffU - iVar5 < param_2) {
      uVar1 = FUN_00793bb0();
      iVar2 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
    }
    if (uVar1 < iVar5 + param_2) {
      if (0x7ffffff - (uVar1 >> 1) < uVar1) {
        uVar1 = 0;
      }
      else {
        uVar1 = uVar1 + (uVar1 >> 1);
      }
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
      }
      if (uVar1 < iVar5 + param_2) {
        if (iVar2 == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - iVar2 >> 5;
        }
        uVar1 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar1 * 0x20);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      iVar2 = FUN_00793c50(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_00793d40(iVar2,param_2,local_3c);
      FUN_00793c50(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x20);
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(in_ECX + 8) - iVar2 >> 5;
      }
      if (iVar2 != 0) {
        FUN_00793d10(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x20 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((param_2 + iVar5) * 0x20 + (int)pvVar3);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      local_1c = *(void **)(in_ECX + 8);
      if ((uint)((int)local_1c - param_1 >> 5) < param_2) {
        FUN_00793c50(param_1,local_1c,param_2 * 0x20 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00793e60(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 5),local_3c);
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x20;
        local_8 = 0;
        FUN_00793c20(param_1,*(int *)(in_ECX + 8) + param_2 * -0x20,local_3c);
      }
      else {
        pvVar3 = (void *)((int)local_1c + param_2 * -0x20);
        uVar4 = FUN_00793c50(pvVar3,local_1c,local_1c);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_0068e670(param_1,pvVar3,local_1c,param_1);
        FUN_00793c20(param_1,param_2 * 0x20 + param_1,local_3c);
      }
    }
  }
  if (local_24 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_38);
  return;
}


// ==== Catch@00794024 @ 0x00794024 ====

void Catch_00794024(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_00793d10(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@007940b3 @ 0x007940b3 ====

void Catch_007940b3(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x20;
  FUN_00793d10(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00794140 @ 0x00794140 ====

void FUN_00794140(byte param_1)

{
  void *in_ECX;
  
  FUN_007939e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00794160 @ 0x00794160 ====

void FUN_00794160(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 5) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 5))) {
    FUN_00793e90(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00793d40(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x20;
  return;
}


// ==== FUN_007941d0 @ 0x007941d0 ====

void FUN_007941d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9544;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007941f0 @ 0x007941f0 ====

void FUN_007941f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9544;
  return;
}


// ==== FUN_00794200 @ 0x00794200 ====

void FUN_00794200(void)

{
  return;
}


// ==== FUN_00794210 @ 0x00794210 ====

void FUN_00794210(void)

{
  return;
}


// ==== FUN_00794220 @ 0x00794220 ====

void FUN_00794220(void)

{
  return;
}


// ==== FUN_00794230 @ 0x00794230 ====

void FUN_00794230(void)

{
  return;
}


// ==== FUN_00794240 @ 0x00794240 ====

void FUN_00794240(void)

{
  return;
}


// ==== FUN_00794250 @ 0x00794250 ====

void FUN_00794250(void)

{
  return;
}


// ==== FUN_00794260 @ 0x00794260 ====

void FUN_00794260(void)

{
  return;
}


// ==== FUN_00794270 @ 0x00794270 ====

void FUN_00794270(void)

{
  return;
}


// ==== FUN_00794290 @ 0x00794290 ====

undefined4 * FUN_00794290(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f9570;
  return puVar1;
}


// ==== FUN_007942b0 @ 0x007942b0 ====

void FUN_007942b0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5100009;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_007942f0 @ 0x007942f0 ====

void FUN_007942f0(byte param_1)

{
  void *in_ECX;
  
  FUN_007941f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00794310 @ 0x00794310 ====

void FUN_00794310(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9544;
  return;
}


// ==== FUN_00794320 @ 0x00794320 ====

void FUN_00794320(void)

{
  return;
}


// ==== FUN_00794330 @ 0x00794330 ====

void FUN_00794330(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00794332. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 8))();
  return;
}


// ==== FUN_00794350 @ 0x00794350 ====

undefined4 * FUN_00794350(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f95b4;
  return puVar1;
}


// ==== FUN_00794370 @ 0x00794370 ====

void FUN_00794370(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5100009;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_007943b0 @ 0x007943b0 ====

void FUN_007943b0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  iVar1 = (**(code **)(*DAT_00b5a7b8 + 0x6c))();
  if (param_1 == iVar1) {
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar3 = operator_new(0x400);
  *(undefined4 *)((int)pvVar3 + 8) = uVar2;
  *(undefined4 *)((int)pvVar3 + 0xc) = 0x5110003;
  *(undefined2 *)((int)pvVar3 + 6) = 0x14;
  iVar1 = FUN_004244d0();
  *(int *)(iVar1 + 0x10) = param_1;
  FUN_004d8570();
  return;
}


// ==== FUN_00794410 @ 0x00794410 ====

void FUN_00794410(undefined1 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x510000c;
  *(undefined2 *)((int)pvVar2 + 6) = 0x14;
  iVar3 = FUN_004244d0();
  *(undefined1 *)(iVar3 + 0x10) = param_1;
  FUN_004d8570();
  return;
}


// ==== FUN_00794460 @ 0x00794460 ====

void FUN_00794460(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *pvVar3;
  
  iVar1 = (**(code **)(*DAT_00b5a7b8 + 0x6c))();
  if (iVar1 == param_1) {
    return;
  }
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar3 = operator_new(0x400);
  *(undefined4 *)((int)pvVar3 + 8) = uVar2;
  *(undefined4 *)((int)pvVar3 + 0xc) = 0x5110004;
  *(undefined2 *)((int)pvVar3 + 6) = 0x14;
  iVar1 = FUN_004244d0();
  *(int *)(iVar1 + 0x10) = param_1;
  FUN_004d8570();
  return;
}


// ==== FUN_007944c0 @ 0x007944c0 ====

void FUN_007944c0(void)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvVar7;
  
  piVar3 = (int *)(**(code **)(*DAT_00b5a7b8 + 100))();
  piVar1 = DAT_00b5a7b8;
  iVar4 = (**(code **)(*piVar3 + 0x10))();
  iVar5 = (**(code **)(*piVar1 + 0x48))();
  if ((uint)(iVar4 + iVar5) < 6) {
    uVar6 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar7 = operator_new(0x400);
    *(undefined4 *)((int)pvVar7 + 8) = uVar6;
    *(undefined4 *)((int)pvVar7 + 0xc) = 0x5110002;
    *(undefined2 *)((int)pvVar7 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    cVar2 = (**(code **)(*DAT_00b5a7b8 + 0x48))();
    *(char *)(iVar4 + 0x10) = cVar2 + '\x01';
    FUN_004d8570(iVar4);
  }
  (**(code **)(*DAT_00b5a7b8 + 0x68))(piVar3);
  return;
}


// ==== FUN_00794550 @ 0x00794550 ====

void FUN_00794550(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  
  piVar2 = (int *)(**(code **)(*DAT_00b5a7b8 + 100))();
  iVar3 = (**(code **)(*DAT_00b5a7b8 + 0x48))();
  if (iVar3 != 0) {
    iVar3 = (**(code **)(*piVar2 + 0x10))();
    if (iVar3 != 6) {
      uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar5 = operator_new(0x400);
      *(undefined4 *)((int)pvVar5 + 8) = uVar4;
      *(undefined4 *)((int)pvVar5 + 0xc) = 0x5110002;
      *(undefined2 *)((int)pvVar5 + 6) = 0x14;
      iVar3 = FUN_004244d0();
      cVar1 = (**(code **)(*DAT_00b5a7b8 + 0x48))();
      *(char *)(iVar3 + 0x10) = cVar1 + -1;
      FUN_004d8570(iVar3);
    }
  }
  (**(code **)(*DAT_00b5a7b8 + 0x68))(piVar2);
  return;
}


// ==== FUN_007945e0 @ 0x007945e0 ====

void FUN_007945e0(int param_1)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  void *pvVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  char acStack_28 [40];
  
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar4 = operator_new(0x400);
  *(undefined4 *)((int)pvVar4 + 8) = uVar3;
  *(undefined4 *)((int)pvVar4 + 0xc) = 0x5110000;
  *(undefined2 *)((int)pvVar4 + 6) = 0x38;
  iVar5 = FUN_004244d0();
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    param_1 = param_1 + 4;
  }
  else {
    param_1 = *(int *)(param_1 + 4);
  }
  FUN_00478000(acStack_28,&DAT_009f95ac,param_1);
  pcVar1 = (char *)(iVar5 + 0x10);
  uVar7 = 0;
  pcVar6 = pcVar1;
  do {
    cVar2 = pcVar6[(int)(acStack_28 + -(int)pcVar1)];
    *pcVar6 = cVar2;
    if (cVar2 == '\0') goto LAB_00794667;
    uVar7 = uVar7 + 1;
    pcVar6 = pcVar6 + 1;
  } while (uVar7 < 0x28);
  *pcVar1 = '\0';
LAB_00794667:
  FUN_004d8570(iVar5);
  return;
}


// ==== FUN_00794680 @ 0x00794680 ====

void FUN_00794680(byte param_1)

{
  void *in_ECX;
  
  FUN_00794310();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007946a0 @ 0x007946a0 ====

void FUN_007946a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9544;
  return;
}


// ==== FUN_007946b0 @ 0x007946b0 ====

void FUN_007946b0(void)

{
  return;
}


// ==== FUN_007946c0 @ 0x007946c0 ====

void FUN_007946c0(void)

{
  return;
}


// ==== FUN_007946d0 @ 0x007946d0 ====

void FUN_007946d0(void)

{
  return;
}


// ==== FUN_007946e0 @ 0x007946e0 ====

void FUN_007946e0(void)

{
  return;
}


// ==== FUN_007946f0 @ 0x007946f0 ====

void FUN_007946f0(void)

{
  return;
}


// ==== FUN_00794700 @ 0x00794700 ====

void FUN_00794700(void)

{
  return;
}


// ==== FUN_00794710 @ 0x00794710 ====

void FUN_00794710(void)

{
  return;
}


// ==== FUN_00794720 @ 0x00794720 ====

void FUN_00794720(void)

{
  return;
}


// ==== FUN_00794740 @ 0x00794740 ====

undefined4 * FUN_00794740(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = &PTR_FUN_009f95f8;
  return puVar1;
}


// ==== FUN_00794760 @ 0x00794760 ====

void FUN_00794760(int param_1,undefined1 *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  undefined1 auStack_28 [40];
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5100001;
  *(undefined2 *)((int)pvVar2 + 6) = 0x14;
  iVar3 = FUN_004244d0();
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    param_1 = param_1 + 4;
  }
  else {
    param_1 = *(int *)(param_1 + 4);
  }
  FUN_00478000(auStack_28,&DAT_009f95f0,param_1);
  FUN_007947f0(auStack_28);
  *(undefined1 *)(iVar3 + 0x10) = *param_2;
  FUN_004d8570(iVar3);
  return;
}


// ==== FUN_007947f0 @ 0x007947f0 ====

void FUN_007947f0(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int in_ECX;
  uint uVar4;
  
  pcVar1 = (char *)(in_ECX + 0x14);
  uVar4 = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[param_1 - (int)pcVar1];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') goto LAB_00794817;
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x28);
  *pcVar1 = '\0';
LAB_00794817:
  uVar4 = 0;
  do {
    if (pcVar1[uVar4] == '\0') goto LAB_00794830;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x28);
  uVar4 = 0;
LAB_00794830:
  *(short *)(in_ECX + 6) = (short)uVar4 + 0x15;
  return;
}


// ==== FUN_00794840 @ 0x00794840 ====

void FUN_00794840(byte param_1)

{
  void *in_ECX;
  
  FUN_007946a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00794860 @ 0x00794860 ====

void FUN_00794860(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9624;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00794880 @ 0x00794880 ====

void FUN_00794880(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9624;
  return;
}


// ==== FUN_00794890 @ 0x00794890 ====

int FUN_00794890(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) || (*(int *)(iVar1 + 4) == 0)) {
    return 0;
  }
  return *(int *)(iVar1 + 8) - *(int *)(iVar1 + 4) >> 2;
}


// ==== FUN_007948b0 @ 0x007948b0 ====

void FUN_007948b0(int param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f963c;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[2] = *(undefined4 *)(param_1 + 8);
  in_ECX[3] = *(undefined4 *)(param_1 + 4);
  return;
}


// ==== FUN_007948e0 @ 0x007948e0 ====

undefined4 FUN_007948e0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 4) != 0)) {
    if ((*(int *)(iVar1 + 8) - *(int *)(iVar1 + 4) >> 2 != 0) &&
       (*(int *)(in_ECX + 0xc) != *(int *)(iVar1 + 8))) {
      uVar2 = FUN_007949a0();
      return uVar2;
    }
  }
  return 0;
}


// ==== FUN_00794920 @ 0x00794920 ====

uint FUN_00794920(void)

{
  uint in_EAX;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) == 0) ||
     (in_EAX = *(uint *)(in_ECX + 0xc), in_EAX == *(uint *)(*(int *)(in_ECX + 4) + 8))) {
    return in_EAX & 0xffffff00;
  }
  return CONCAT31((int3)(in_EAX + 4 >> 8),in_EAX + 4 != *(int *)(in_ECX + 8));
}


// ==== FUN_00794940 @ 0x00794940 ====

void FUN_00794940(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) != 0) && (*(int *)(in_ECX + 0xc) != *(int *)(*(int *)(in_ECX + 4) + 8)))
  {
    *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + 4;
  }
  return;
}


// ==== FUN_00794960 @ 0x00794960 ====

void FUN_00794960(byte param_1)

{
  void *in_ECX;
  
  FUN_00794880();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00794980 @ 0x00794980 ====

void FUN_00794980(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9654;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007949a0 @ 0x007949a0 ====

int FUN_007949a0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_007949b0 @ 0x007949b0 ====

void FUN_007949b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f965c;
  if (0xf < (uint)in_ECX[0x12]) {
    _free((void *)in_ECX[0xd]);
    return;
  }
  in_ECX[0x12] = 0xf;
  in_ECX[0x11] = 0;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  if ((uint)in_ECX[0xb] < 0x10) {
    in_ECX[10] = 0;
    in_ECX[0xb] = 0xf;
    *(undefined1 *)(in_ECX + 6) = 0;
    *in_ECX = &PTR_FUN_009f9654;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_00794a10 @ 0x00794a10 ====

void FUN_00794a10(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f965c;
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  in_ECX[0x12] = 0xf;
  in_ECX[0x11] = 0;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  return;
}


// ==== FUN_00794a40 @ 0x00794a40 ====

void FUN_00794a40(undefined1 param_1)

{
  void *in_stack_00000018;
  uint in_stack_0000002c;
  void *in_stack_00000034;
  uint in_stack_00000048;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998778;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00585650(&param_1);
  if (0xf < in_stack_00000048) {
    _free(in_stack_00000034);
    return;
  }
  if (in_stack_0000002c < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(in_stack_00000018);
  return;
}


// ==== FUN_00794ab0 @ 0x00794ab0 ====

void FUN_00794ab0(byte param_1)

{
  void *in_ECX;
  
  FUN_007949b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00794ad0 @ 0x00794ad0 ====

int FUN_00794ad0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
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
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009987a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004041d0(local_28,param_2);
  local_4 = 0;
  if (*(uint *)(param_3 + 0x18) < 0x10) {
    iVar1 = param_3 + 4;
  }
  else {
    iVar1 = *(int *)(param_3 + 4);
  }
  iVar1 = FUN_00405850(iVar1,0,*(undefined4 *)(param_3 + 0x14));
  if (iVar1 == -1) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(&DAT_009f9662,0);
  }
  else {
    uVar2 = FUN_00405b90(local_44,*(int *)(param_3 + 0x14) + iVar1,0xffffffff);
    local_4._0_1_ = 1;
    FUN_00404170(local_60,uVar2);
    local_4 = CONCAT31(local_4._1_3_,3);
    if (0xf < local_2c) {
      _free(local_40);
      return extraout_EAX;
    }
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(local_60,0,0xffffffff);
    if (0xf < local_48) {
      _free(local_5c);
      return extraout_EAX_00;
    }
    local_48 = 0xf;
    local_4c = 0;
    local_5c = (void *)((uint)local_5c & 0xffffff00);
  }
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_24);
  return extraout_EAX_01;
}


// ==== FUN_00794c10 @ 0x00794c10 ====

void FUN_00794c10(void)

{
  return;
}


// ==== FUN_00794c20 @ 0x00794c20 ====

void FUN_00794c20(void)

{
  return;
}


// ==== FUN_00794c30 @ 0x00794c30 ====

void FUN_00794c30(void)

{
  return;
}


// ==== FUN_00794c40 @ 0x00794c40 ====

void FUN_00794c40(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009f96c4;
  in_ECX[2] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b13c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b13c = in_ECX;
  return;
}


// ==== FUN_00794c70 @ 0x00794c70 ====

void FUN_00794c70(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x84) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x84) + 0x20))(param_2,param_1);
    (**(code **)(**(int **)(in_ECX + 4) + 0x20))();
    (**(code **)(**(int **)(in_ECX + 4) + 0x28))();
  }
  return;
}


// ==== FUN_00794cc0 @ 0x00794cc0 ====

void FUN_00794cc0(void)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  FUN_006f86c0(DAT_00b5b1a0);
  cVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0x44))();
  if (cVar1 != '\x01') {
    FUN_006f8c40();
    return;
  }
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    return;
  }
  (**(code **)(**(int **)(iVar2 + 0x84) + 0x28))();
  (**(code **)(**(int **)(in_ECX + 4) + 0x24))();
  FUN_006f8a00();
                    /* WARNING: Could not recover jumptable at 0x00794d0d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0x3c))();
  return;
}


// ==== FUN_00794d20 @ 0x00794d20 ====

void FUN_00794d20(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b13c = 0;
  *in_ECX = &PTR_FUN_009e782c;
  return;
}


// ==== FUN_00794d40 @ 0x00794d40 ====

void FUN_00794d40(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  void *pvVar4;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  iVar2 = (**(code **)(*piVar1 + 0x40))();
  if (iVar2 == 8) {
    FUN_006f86c0(DAT_00b5b1a0);
    FUN_006f8c40();
    (**(code **)(**(int **)(in_ECX + 4) + 0x24))();
    return;
  }
  if (1000 < (uint)(*(int *)(param_1 + 0xc) - *(int *)(in_ECX + 8))) {
    *(int *)(in_ECX + 8) = *(int *)(param_1 + 0xc);
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5210003;
    *(undefined2 *)((int)pvVar4 + 6) = 0x10;
    uVar3 = FUN_004244d0();
    FUN_004d8570(uVar3);
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x28))();
  return;
}


// ==== FUN_00794de0 @ 0x00794de0 ====

void FUN_00794de0(void)

{
  char cVar1;
  int in_ECX;
  undefined1 *unaff_ESI;
  undefined1 auStack_58 [4];
  undefined1 uStack_54;
  undefined4 uStack_4c;
  undefined1 auStack_2a [10];
  uint uStack_20;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009987c8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00794cc0();
  (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_4c = 0x794e32;
  FUN_00401660();
  pvStack_c = (void *)0x0;
  cVar1 = FUN_00404900();
  if (cVar1 == '\x01') {
    (**(code **)(**(int **)(in_ECX + 4) + 0x2c))();
  }
  else {
    unaff_ESI = auStack_58;
    uStack_54 = 0;
    FUN_00401660(auStack_2a + -6,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
  }
  if (uStack_20 < 0x10) {
    ExceptionList = (void *)0x0;
    return;
  }
  uStack_4c = 0x794ea1;
  _free(unaff_ESI);
  return;
}


// ==== FUN_00794ef0 @ 0x00794ef0 ====

undefined4 FUN_00794ef0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    FUN_00794d40(param_1);
  }
  else if (iVar1 == 0x50011) {
    iVar1 = FUN_00424500();
    if (iVar1 == 0x5210004) {
      FUN_00794de0(param_1[3]);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00794f40 @ 0x00794f40 ====

void FUN_00794f40(byte param_1)

{
  void *in_ECX;
  
  FUN_00794d20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00794f60 @ 0x00794f60 ====

void FUN_00794f60(void)

{
  return;
}


// ==== FUN_00794f70 @ 0x00794f70 ====

void FUN_00794f70(void)

{
  return;
}


// ==== FUN_00794f80 @ 0x00794f80 ====

void FUN_00794f80(void)

{
  return;
}


// ==== FUN_00794f90 @ 0x00794f90 ====

void FUN_00794f90(void)

{
  FUN_006f87b0(0);
  return;
}


// ==== FUN_00794fa0 @ 0x00794fa0 ====

void FUN_00794fa0(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9738;
  in_ECX[1] = param_1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b198 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b198 = in_ECX;
  return;
}


// ==== FUN_00794fd0 @ 0x00794fd0 ====

void FUN_00794fd0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  iVar2 = (**(code **)(*piVar1 + 0x40))();
  if (iVar2 == 8) {
    FUN_006f86c0(DAT_00b5b1a0);
    FUN_006f8c40();
    (**(code **)(**(int **)(in_ECX + 4) + 0x24))();
    return;
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  iVar2 = (**(code **)(*piVar1 + 0x40))();
  if (iVar2 != 0x17) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    iVar2 = (**(code **)(*piVar1 + 0x40))();
    if (iVar2 != 0x15) {
      piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      iVar2 = (**(code **)(*piVar1 + 0x40))();
      if (iVar2 != 0x16) {
        FUN_006f86c0(DAT_00b5b1a0);
        (**(code **)(**(int **)(in_ECX + 4) + 0x24))();
        (**(code **)(**(int **)(in_ECX + 4) + 0x3c))();
      }
    }
  }
  return;
}


// ==== FUN_00795080 @ 0x00795080 ====

void FUN_00795080(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b198 = 0;
  *in_ECX = &PTR_FUN_009e782c;
  return;
}


// ==== FUN_007950a0 @ 0x007950a0 ====

uint FUN_007950a0(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00794fd0(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_007950d0 @ 0x007950d0 ====

void FUN_007950d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00795080();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007950f0 @ 0x007950f0 ====

void FUN_007950f0(void)

{
  return;
}


// ==== FUN_00795100 @ 0x00795100 ====

void FUN_00795100(void)

{
  return;
}


// ==== FUN_00795110 @ 0x00795110 ====

void FUN_00795110(void)

{
  return;
}


// ==== FUN_00795120 @ 0x00795120 ====

void FUN_00795120(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  
  iVar1 = *(int *)(in_ECX + 8);
  uVar2 = 1;
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      FUN_006f87b0(1);
      return;
    }
    if (iVar1 == 2) {
      uVar2 = 2;
    }
    FUN_006f87b0(uVar2);
  }
  return;
}


// ==== FUN_00795150 @ 0x00795150 ====

void FUN_00795150(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009f97ac;
  in_ECX[2] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b19c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b19c = in_ECX;
  return;
}


// ==== FUN_00795180 @ 0x00795180 ====

void FUN_00795180(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  iVar2 = (**(code **)(*piVar1 + 0x40))();
  if (iVar2 == 8) {
    FUN_006f86c0(DAT_00b5b1a0);
    FUN_006f8c40();
    (**(code **)(**(int **)(in_ECX + 4) + 0x24))();
    return;
  }
  piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
  iVar2 = (**(code **)(*piVar1 + 0x40))();
  if (iVar2 != 0x17) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    iVar2 = (**(code **)(*piVar1 + 0x40))();
    if (iVar2 != 0x15) {
      piVar1 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
      iVar2 = (**(code **)(*piVar1 + 0x40))();
      if (iVar2 != 0x16) {
        FUN_006f86c0(DAT_00b5b1a0);
        (**(code **)(**(int **)(in_ECX + 4) + 0x24))();
        (**(code **)(**(int **)(in_ECX + 4) + 0x3c))();
      }
    }
  }
  return;
}


// ==== FUN_00795230 @ 0x00795230 ====

void FUN_00795230(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b19c = 0;
  *in_ECX = &PTR_FUN_009e782c;
  return;
}


// ==== FUN_00795250 @ 0x00795250 ====

uint FUN_00795250(int *param_1)

{
  uint uVar1;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    uVar1 = FUN_00795180(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00795280 @ 0x00795280 ====

void FUN_00795280(byte param_1)

{
  void *in_ECX;
  
  FUN_00795230();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007952a0 @ 0x007952a0 ====

bool FUN_007952a0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  return *(int *)(iVar1 + 8) == 0x300;
}


// ==== FUN_007952f0 @ 0x007952f0 ====

bool FUN_007952f0(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac1c + 0x3c))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x2c))();
  iVar2 = (**(code **)(*piVar1 + 0x10))();
  return *(char *)(iVar2 + 0x964) != '\0';
}


// ==== FUN_00795320 @ 0x00795320 ====

bool FUN_00795320(int *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x2c))();
  if (*(int *)(iVar2 + 4) == 7) {
    iVar2 = *DAT_00b5add0;
    uVar3 = (**(code **)(*DAT_00b5ae14 + 0x18))();
    cVar1 = (**(code **)(iVar2 + 0x3c))(uVar3);
    return cVar1 != '\0';
  }
  return true;
}


// ==== FUN_00795360 @ 0x00795360 ====

undefined4 FUN_00795360(int *param_1)

{
  int *piVar1;
  byte bVar2;
  int iVar3;
  undefined1 auStack_26 [14];
  void *pvStack_18;
  void *pvStack_14;
  void *pvStack_10;
  void *pvStack_c;
  int *piStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  piStack_8 = (int *)&LAB_009987e8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5ad20 + 0x20))(param_1);
  if (iVar3 == 4) {
    iVar3 = (**(code **)(*param_1 + 0x2c))();
    if (*(int *)(iVar3 + 8) == 0xb) {
      (**(code **)(*DAT_00b5b0e4 + 0xc))((uint)param_1 & 0xffffff);
      ExceptionList = pvStack_14;
      return 1;
    }
    iVar3 = (**(code **)(*param_1 + 0x2c))();
    if (*(int *)(iVar3 + 8) == 10) {
      (**(code **)(*DAT_00b5a9e4 + 0x24))(0,(uint)param_1 & 0xffffff);
      ExceptionList = pvStack_18;
      return 1;
    }
    iVar3 = (**(code **)(*param_1 + 0x2c))();
    if (*(int *)(iVar3 + 8) == 7) {
      (**(code **)(*DAT_00b5a9e4 + 0x24))(3,(uint)param_1 & 0xffffff);
      ExceptionList = pvStack_18;
      return 1;
    }
    iVar3 = (**(code **)(*param_1 + 0x2c))();
    if (*(int *)(iVar3 + 8) == 8) {
      (**(code **)(*DAT_00b5a9e4 + 0x24))(2,(uint)param_1 & 0xffffff);
      ExceptionList = pvStack_18;
      return 1;
    }
    iVar3 = (**(code **)(*param_1 + 0x2c))();
    if (*(int *)(iVar3 + 8) == 6) {
      (**(code **)(*DAT_00b5a9e4 + 0x24))(1,(uint)param_1 & 0xffffff);
      ExceptionList = pvStack_18;
      return 1;
    }
    iVar3 = (**(code **)(*param_1 + 0x2c))();
    if (*(int *)(iVar3 + 8) == 9) {
      (**(code **)(*DAT_00b5a9e4 + 0x24))(4,(uint)param_1 & 0xffffff);
      ExceptionList = pvStack_18;
      return 1;
    }
    iVar3 = (**(code **)(*param_1 + 0x2c))();
    if (*(int *)(iVar3 + 8) == 0xd) {
      (**(code **)(*DAT_00b5a9e4 + 0x24))(5,(uint)param_1 & 0xffffff);
      (**(code **)(*DAT_00b5a9e4 + 0x3c))();
      ExceptionList = pvStack_18;
      return 1;
    }
    iVar3 = (**(code **)(*param_1 + 0x2c))();
    if (*(int *)(iVar3 + 8) == 0xe) {
      (**(code **)(*DAT_00b5a9e4 + 0x24))(6,(uint)param_1 & 0xffffff);
      (**(code **)(*DAT_00b5a9e4 + 0x40))();
      ExceptionList = pvStack_18;
      return 1;
    }
    iVar3 = (**(code **)(*param_1 + 0x2c))();
    if (*(int *)(iVar3 + 8) == 0xf) {
      iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
      piVar1 = *(int **)(iVar3 + 0x20);
      if (piVar1 == (int *)0x0) {
        FUN_00401830(s_pBag____NULL_009f9860);
        piStack_8 = piVar1;
        FUN_00406880(auStack_26 + -6);
        piStack_8 = (int *)0xffffffff;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      bVar2 = (**(code **)(*piVar1 + 0x70))();
      if (bVar2 < 4) {
        (**(code **)(*DAT_00b5a9e4 + 0x24))(7,(uint)param_1 & 0xffffff);
        ExceptionList = pvStack_18;
        return 1;
      }
      (**(code **)(*DAT_00b5a9e4 + 0x28))(1);
      ExceptionList = pvStack_14;
      return 1;
    }
    iVar3 = (**(code **)(*param_1 + 0x2c))();
    if (*(int *)(iVar3 + 8) == 0x10) {
      (**(code **)(*DAT_00b5a9e4 + 0x24))(8,(uint)param_1 & 0xffffff);
      ExceptionList = pvStack_18;
      return 1;
    }
    iVar3 = (**(code **)(*param_1 + 0x2c))();
    if (*(int *)(iVar3 + 8) == 0x304) {
      (**(code **)(*DAT_00b5a9e4 + 0x24))(9,(uint)param_1 & 0xffffff);
      ExceptionList = pvStack_18;
      return 1;
    }
  }
  ExceptionList = pvStack_10;
  return 0;
}


// ==== FUN_007956e0 @ 0x007956e0 ====

/* WARNING: Removing unreachable block (ram,0x007957b7) */
/* WARNING: Removing unreachable block (ram,0x00795762) */

void FUN_007956e0(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined2 *unaff_retaddr;
  undefined1 auStack_46 [54];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099881a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar2 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar2 == '\0') {
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar3 == 0) {
      FUN_00401740();
      puStack_8 = (undefined1 *)0x0;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(int **)(iVar3 + 0x20) == (int *)0x0) {
      FUN_00401740();
      puStack_8 = (undefined1 *)0x1;
      FUN_00406880();
      puStack_8 = (undefined1 *)0xffffffff;
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x20) + 0x28))();
    if (((piVar4 != (int *)0x0) && (cVar2 = FUN_00795360(), cVar2 != '\x01')) &&
       (cVar2 = (**(code **)(*DAT_00b5ad20 + 0x3c))(), cVar2 != '\0')) {
      iVar3 = (**(code **)(*piVar4 + 0x2c))();
      if (*(int *)(iVar3 + 8) == 0x800) {
        (**(code **)(*DAT_00b5a6ac + 0x20))();
        iVar3 = FUN_007959e0();
        uVar5 = (**(code **)(*DAT_00b5adc0 + 0x24))();
        *(undefined4 *)(iVar3 + 0x10) = uVar5;
        uVar5 = (**(code **)(*DAT_00b5adc0 + 0x18))();
        *(undefined4 *)(iVar3 + 0x14) = uVar5;
        *(undefined2 *)(iVar3 + 0x18) = *unaff_retaddr;
        *(undefined1 *)(iVar3 + 0x1a) = *(undefined1 *)(unaff_retaddr + 1);
        FUN_004ef210();
        FUN_00401830();
        puStack_8 = (undefined1 *)0x2;
        FUN_00796d50();
        puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      cVar2 = FUN_00795320();
      if (cVar2 != '\0') {
        cVar2 = FUN_007952a0();
        if ((cVar2 == '\0') || (cVar2 = FUN_007952f0(), cVar2 != '\0')) {
          (**(code **)(*DAT_00b5a6ac + 0x20))();
          iVar3 = FUN_00795a10();
          *(undefined2 *)(iVar3 + 0x10) = *unaff_retaddr;
          *(undefined1 *)(iVar3 + 0x12) = *(undefined1 *)(unaff_retaddr + 1);
          FUN_004ef210();
          FUN_00401830();
          puStack_8 = (undefined1 *)0x4;
          FUN_00796d50();
          puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        (**(code **)(*DAT_00b5a794 + 0xc))();
        FUN_00765c50();
        FUN_00765c50(auStack_46 + -10);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_007959e0 @ 0x007959e0 ====

void FUN_007959e0(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x500000a;
  *(undefined2 *)((int)pvVar1 + 6) = 0x1c;
  FUN_004244d0();
  return;
}


// ==== FUN_00795a10 @ 0x00795a10 ====

void FUN_00795a10(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5000002;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  FUN_004244d0();
  return;
}


// ==== FUN_00795a40 @ 0x00795a40 ====

void FUN_00795a40(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x50c0002;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  FUN_004244d0();
  return;
}


// ==== FUN_00795a80 @ 0x00795a80 ====

void FUN_00795a80(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined1 auStack_78 [20];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  char *pcStack_58;
  undefined4 uStack_54;
  undefined1 auStack_2c [28];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998840;
  pvStack_c = ExceptionList;
  uStack_54 = (undefined1 *)0x0;
  pcStack_58 = (char *)0x795aa7;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    pcStack_58 = (char *)0x795aba;
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pcStack_58 = (char *)0x795ac7;
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if ((iVar3 != 0) && (*(int **)(iVar3 + 0x4c) != (int *)0x0)) {
      pcStack_58 = (char *)0x795ae1;
      piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
      if (piVar4 != (int *)0x0) {
        uStack_5c = 0x795af3;
        pcStack_58 = (char *)uVar2;
        (**(code **)(*piVar4 + 8))();
        uStack_5c = 0x795afa;
        iVar3 = (**(code **)(*piVar4 + 0x10))();
        if (iVar3 != 0) {
          cVar1 = *(char *)(iVar3 + 0xb);
          if (((cVar1 == '\x01') || (cVar1 == '\x02')) || (cVar1 == '\x03')) {
            uStack_5c = 0x795b75;
            pcStack_58 = (char *)uVar2;
            pcStack_58 = (char *)FUN_00795a40();
            uStack_5c = 0x795b84;
            FUN_004d8570();
            pcStack_58 = s_SEND______CQSwap_Weapon_009f98c0;
            uStack_5c = 0x795b92;
            FUN_00401830();
            pcStack_58 = auStack_2c;
            puStack_8 = (undefined1 *)0x1;
            uStack_5c = 0x795ba4;
            FUN_00796d50();
            puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
            pcStack_58 = (char *)0x795bb8;
            FUN_00446f10();
          }
          pcStack_58 = (char *)0x650001;
          uStack_5c = 5;
          uStack_60 = 0x795b23;
          uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
          uStack_64 = 0x795b2d;
          FUN_00765c50();
          uStack_54 = auStack_78;
          pvStack_10 = (void *)0x0;
          FUN_00765c50(auStack_78 + 0x28);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00795bf0 @ 0x00795bf0 ====

void FUN_00795bf0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uStack_2c;
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998858;
  pvStack_c = ExceptionList;
  uStack_2c = 0;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    puVar2 = operator_new(4);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009f994c;
    }
    FUN_00797a20(puVar2);
    (**(code **)(*DAT_00b5a78c + 0x68))(1);
    uStack_14 = 0xf;
    uStack_18 = 0;
    pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
    FUN_00401740(s_Show_Inventory_Window_009f992c,0x15);
    puStack_8 = (undefined1 *)0x0;
    FUN_00796d50(&uStack_2c);
    if (0xf < uStack_14) {
      _free(pvStack_28);
      return;
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00795cb0 @ 0x00795cb0 ====

undefined4 FUN_00795cb0(void)

{
  return 0x70080000;
}


// ==== FUN_00795cd0 @ 0x00795cd0 ====

/* WARNING: Removing unreachable block (ram,0x00795d78) */

undefined4 FUN_00795cd0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined1 auStack_2a [22];
  void *pvStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998878;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 != '\0') {
    ExceptionList = pvStack_10;
    return 0;
  }
  puVar2 = operator_new(4);
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = &PTR_FUN_009f99b8;
  }
  FUN_00797a20();
  (**(code **)(*DAT_00b5a78c + 0x68))();
  FUN_00401740(s_Close_Inventory_Window_009f9998,0x16);
  pvStack_c = (void *)0x0;
  FUN_00796d50(auStack_2a + -6);
  ExceptionList = pvStack_14;
  return 1;
}


// ==== FUN_00795da0 @ 0x00795da0 ====

undefined4 FUN_00795da0(void)

{
  return 0x70080001;
}


// ==== FUN_00795dc0 @ 0x00795dc0 ====

/* WARNING: Removing unreachable block (ram,0x00795ffa) */

void FUN_00795dc0(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  void *pvVar5;
  undefined2 *puVar6;
  undefined2 *unaff_retaddr;
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
  puStack_8 = &LAB_009988b8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar2 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar2 == '\0') {
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar3 == 0) {
      uStack_14 = 0xf;
      uStack_18 = 0;
      pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
      FUN_00401740(s_pPC____NULL_009f9a04,0xb);
      puStack_8 = (undefined1 *)0x0;
      FUN_00406880(auStack_2c);
      puStack_8 = (undefined1 *)0xffffffff;
      if (uStack_14 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_28);
      return;
    }
    if (*(int **)(iVar3 + 0x20) == (int *)0x0) {
      uStack_14 = 0xf;
      uStack_18 = 0;
      pvStack_28 = (void *)((uint)pvStack_28._1_3_ << 8);
      FUN_00401740(s_pBag____NULL_009f9a10,0xc);
      puStack_8 = (undefined1 *)0x1;
      FUN_00406880(auStack_2c);
      puStack_8 = (undefined1 *)0xffffffff;
      if (uStack_14 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_28);
      return;
    }
    if (*(int *)(iVar3 + 0x1c) == 0) {
      uStack_14 = 0xf;
      uStack_18 = 0;
      pvStack_28 = (void *)((uint)pvStack_28._1_3_ << 8);
      FUN_00401740(s_pCursor____NULL_009f9a20,0xf);
      puStack_8 = (undefined1 *)0x2;
      FUN_00406880(auStack_2c);
      puStack_8 = (undefined1 *)0xffffffff;
      if (uStack_14 < 0x10) {
        pcVar1 = (code *)swi(3);
        (*pcVar1)();
        return;
      }
      _free(pvStack_28);
      return;
    }
    iVar3 = (**(code **)(**(int **)(iVar3 + 0x20) + 0x14))(unaff_retaddr,*(int *)(iVar3 + 0x1c));
    if (iVar3 == 0) {
      uStack_14 = 0xf;
      uStack_18 = 0;
      pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
      FUN_00401740(s_Waring______CQPick_Inven_pBag_>C_009f9a30,0x48);
      puStack_8 = (undefined1 *)0x3;
      FUN_00796d50(auStack_2c);
      if (0xf < uStack_14) {
        _free(pvStack_28);
        return;
      }
    }
    else {
      uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
      pvVar5 = operator_new(0x400);
      *(undefined4 *)((int)pvVar5 + 8) = uVar4;
      *(undefined4 *)((int)pvVar5 + 0xc) = 0x5000000;
      *(undefined2 *)((int)pvVar5 + 6) = 0x18;
      iVar3 = FUN_004244d0();
      *(undefined2 *)(iVar3 + 0x10) = *unaff_retaddr;
      *(undefined1 *)(iVar3 + 0x12) = *(undefined1 *)(unaff_retaddr + 1);
      *(undefined1 *)(iVar3 + 0x16) = 1;
      FUN_004d8570(iVar3);
      FUN_00401740(s_SEND______CQPick_Inven_009f9a7c,0x18);
      puStack_8 = (undefined1 *)0x4;
      FUN_00796d50(auStack_42 + -6);
      puStack_8 = (undefined1 *)0xffffffff;
      (**(code **)(*DAT_00b5af2c + 4))(0);
      puVar6 = (undefined2 *)(**(code **)(*DAT_00b5a78c + 0x4c))();
      *puVar6 = *unaff_retaddr;
      *(undefined1 *)(puVar6 + 1) = *(undefined1 *)(unaff_retaddr + 1);
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00796050 @ 0x00796050 ====

void FUN_00796050(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x50c0000;
  *(undefined2 *)((int)pvVar1 + 6) = 0x14;
  FUN_004244d0();
  return;
}


// ==== FUN_00796090 @ 0x00796090 ====

void FUN_00796090(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 unaff_retaddr;
  undefined1 auStack_78 [20];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  char *pcStack_58;
  undefined4 uStack_54;
  undefined1 auStack_2c [28];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009988e0;
  pvStack_c = ExceptionList;
  uStack_54 = (undefined1 *)0x0;
  pcStack_58 = (char *)0x7960b7;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    pcStack_58 = (char *)0x7960ca;
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pcStack_58 = (char *)0x7960d7;
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if ((iVar3 != 0) && (*(int **)(iVar3 + 0x4c) != (int *)0x0)) {
      pcStack_58 = (char *)0x7960f1;
      piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x4c) + 0x18))();
      if (piVar4 != (int *)0x0) {
        uStack_5c = 0x796103;
        pcStack_58 = (char *)uVar2;
        (**(code **)(*piVar4 + 8))();
        uStack_5c = 0x79610a;
        iVar3 = (**(code **)(*piVar4 + 0x10))();
        if (iVar3 != 0) {
          cVar1 = *(char *)(iVar3 + 0xb);
          if (((cVar1 == '\x01') || (cVar1 == '\x02')) || (cVar1 == '\x03')) {
            pcStack_58 = (char *)0x79618a;
            pcStack_58 = (char *)(**(code **)(*DAT_00b5a6ac + 0x20))();
            uStack_5c = 0x796190;
            pcStack_58 = (char *)FUN_00796050();
            *(undefined4 *)((int)pcStack_58 + 0x10) = unaff_retaddr;
            uStack_5c = 0x7961a6;
            FUN_004d8570();
            pcStack_58 = s_SEND______CQPick_Suit_009f9ae8;
            uStack_5c = 0x7961b4;
            FUN_00401830();
            pcStack_58 = auStack_2c;
            puStack_8 = (undefined1 *)0x1;
            uStack_5c = 0x7961c6;
            FUN_00796d50();
            puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
            pcStack_58 = (char *)0x7961da;
            FUN_00446f10();
          }
          pcStack_58 = (char *)0x650001;
          uStack_5c = 5;
          uStack_60 = 0x796133;
          uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
          uStack_64 = 0x79613d;
          FUN_00765c50();
          uStack_54 = auStack_78;
          pvStack_10 = (void *)0x0;
          FUN_00765c50(auStack_78 + 0x28);
          (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
      }
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00796210 @ 0x00796210 ====

void FUN_00796210(undefined4 param_1)

{
  void *pvVar1;
  
  pvVar1 = operator_new(0x400);
  *(undefined4 *)((int)pvVar1 + 8) = param_1;
  *(undefined4 *)((int)pvVar1 + 0xc) = 0x5020001;
  *(undefined2 *)((int)pvVar1 + 6) = 0x18;
  FUN_004244d0();
  return;
}


// ==== FUN_00796250 @ 0x00796250 ====

void FUN_00796250(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined1 auStack_3e [14];
  undefined4 uStack_30;
  void *pvStack_2c;
  undefined4 uStack_1c;
  void *pvStack_18;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009988f8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))();
  if (cVar1 == '\0') {
    uStack_30 = 0;
    iVar2 = (**(code **)(*DAT_00b5ad20 + 8))();
    if (iVar2 != 0) {
      iVar2 = (**(code **)(*DAT_00b5ad20 + 0x20))(iVar2);
      if (iVar2 != 4) {
        uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
        iVar2 = FUN_00796210(uVar3);
        puVar4 = (undefined4 *)FUN_004ef0e0(auStack_3e + -4);
        *(undefined4 *)(iVar2 + 0x10) = *puVar4;
        *(undefined2 *)(iVar2 + 0x14) = *(undefined2 *)(puVar4 + 1);
        FUN_004d8570(iVar2);
        FUN_00401830(s_SEND______CQDrop_Item_009f9b50);
        pvStack_c = (void *)0x0;
        FUN_00796d50(&uStack_30);
        pvStack_c = (void *)0xffffffff;
        if (pvStack_18 < 0x10) {
          pvStack_18 = (void *)0xf;
          uStack_1c = 0;
          pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
          (**(code **)(*DAT_00b5af2c + 4))(0);
          ExceptionList = pvStack_18;
          return;
        }
        _free(pvStack_2c);
        return;
      }
      (**(code **)(*DAT_00b5b0d4 + 0x14))();
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_007963b0 @ 0x007963b0 ====

void FUN_007963b0(void)

{
  undefined2 uVar1;
  code *pcVar2;
  char cVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  void *pvVar8;
  int iVar9;
  undefined4 unaff_retaddr;
  undefined1 auStack_56 [14];
  undefined1 auStack_48 [4];
  void *pvStack_44;
  undefined4 uStack_34;
  uint uStack_30;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998920;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar3 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar3 == '\0') {
    if (DAT_00b5a97c == (int *)0x0) {
      uStack_14 = 0xf;
      uStack_18 = 0;
      pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
      FUN_00401740(s_pGameUser____NULL_009f9bb8,0x11);
      puStack_8 = (undefined1 *)0x0;
      FUN_00406880(auStack_2c);
      puStack_8 = (undefined1 *)0xffffffff;
      if (uStack_14 < 0x10) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      _free(pvStack_28);
      return;
    }
    piVar4 = (int *)(**(code **)(*DAT_00b5a97c + 8))();
    (**(code **)(*piVar4 + 0x28))();
    (**(code **)(*piVar4 + 0x28))();
    uVar5 = (**(code **)(*piVar4 + 0x2c))();
    FUN_0040d5f0(uVar5);
    puVar6 = (undefined4 *)FUN_004ef0e0(auStack_56 + -4);
    uVar5 = *puVar6;
    uVar1 = *(undefined2 *)(puVar6 + 1);
    uVar7 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar8 = operator_new(0x400);
    *(undefined4 *)((int)pvVar8 + 8) = uVar7;
    *(undefined4 *)((int)pvVar8 + 0xc) = 0x5030000;
    *(undefined2 *)((int)pvVar8 + 6) = 0x1c;
    iVar9 = FUN_004244d0();
    *(undefined4 *)(iVar9 + 0x10) = uVar5;
    *(undefined4 *)(iVar9 + 0x18) = unaff_retaddr;
    *(undefined2 *)(iVar9 + 0x14) = uVar1;
    FUN_004d8570(iVar9);
    uStack_30 = 0xf;
    uStack_34 = 0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    FUN_00401740(s_SEND______CQDrop_Money_009f9bcc,0x18);
    puStack_8 = (undefined1 *)0x1;
    FUN_00796d50(auStack_48);
    puStack_8 = (undefined1 *)0xffffffff;
    if (0xf < uStack_30) {
      _free(pvStack_44);
      return;
    }
    uStack_30 = 0xf;
    uStack_34 = 0;
    pvStack_44 = (void *)((uint)pvStack_44 & 0xffffff00);
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== __break @ 0x0079656b ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== __break @ 0x0079656e ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00796570 @ 0x00796570 ====

/* WARNING: Removing unreachable block (ram,0x0079662c) */

void FUN_00796570(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined1 unaff_retaddr;
  undefined1 auStack_26 [22];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998938;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5020003;
    *(undefined2 *)((int)pvVar3 + 6) = 0x18;
    iVar4 = FUN_004244d0();
    *(undefined1 *)(iVar4 + 0x14) = unaff_retaddr;
    *(undefined4 *)(iVar4 + 0x10) = param_1;
    FUN_004d8570(iVar4);
    FUN_00401740(s_SEND______CQPick_Item_009f9c38,0x17);
    puStack_8 = (undefined1 *)0x0;
    FUN_00796d50(auStack_26 + -6);
    puStack_8 = (undefined1 *)0xffffffff;
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00796680 @ 0x00796680 ====

/* WARNING: Removing unreachable block (ram,0x00796735) */

void FUN_00796680(void)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 unaff_retaddr;
  undefined1 auStack_26 [22];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998958;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5030003;
    *(undefined2 *)((int)pvVar3 + 6) = 0x14;
    iVar4 = FUN_004244d0();
    *(undefined4 *)(iVar4 + 0x10) = unaff_retaddr;
    FUN_004d8570(iVar4);
    FUN_00401740(s_SEND______CQPick_Money_009f9ca0,0x18);
    puStack_8 = (undefined1 *)0x0;
    FUN_00796d50(auStack_26 + -6);
    puStack_8 = (undefined1 *)0xffffffff;
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00796780 @ 0x00796780 ====

/* WARNING: Removing unreachable block (ram,0x0079684c) */

void FUN_00796780(undefined2 param_1)

{
  char cVar1;
  undefined4 uVar2;
  void *pvVar3;
  int iVar4;
  undefined2 unaff_retaddr;
  undefined1 unaff_retaddr_00;
  undefined1 auStack_26 [22];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998978;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(0);
  if (cVar1 == '\0') {
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar3 = operator_new(0x400);
    *(undefined4 *)((int)pvVar3 + 8) = uVar2;
    *(undefined4 *)((int)pvVar3 + 0xc) = 0x5000000;
    *(undefined2 *)((int)pvVar3 + 6) = 0x18;
    iVar4 = FUN_004244d0();
    *(undefined2 *)(iVar4 + 0x10) = unaff_retaddr;
    *(undefined1 *)(iVar4 + 0x12) = unaff_retaddr_00;
    *(undefined2 *)(iVar4 + 0x14) = param_1;
    *(undefined1 *)(iVar4 + 0x16) = 0;
    FUN_004d8570(iVar4);
    FUN_00401740(s_SEND______CQPick_Stack_009f9d0c,0x18);
    puStack_8 = (undefined1 *)0x0;
    FUN_00796d50(auStack_26 + -6);
    puStack_8 = (undefined1 *)0xffffffff;
    (**(code **)(*DAT_00b5af2c + 4))(0);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00796890 @ 0x00796890 ====

void FUN_00796890(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9d40;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007968b0 @ 0x007968b0 ====

void FUN_007968b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9d40;
  return;
}


// ==== FUN_007968c0 @ 0x007968c0 ====

undefined4 FUN_007968c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 4) + 8);
}


// ==== FUN_007968d0 @ 0x007968d0 ====

void FUN_007968d0(int param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9d58;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[2] = **(undefined4 **)(param_1 + 4);
  in_ECX[3] = *(undefined4 *)(param_1 + 4);
  return;
}


// ==== FUN_00796900 @ 0x00796900 ====

int FUN_00796900(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 8) + 8;
}


// ==== FUN_00796910 @ 0x00796910 ====

undefined4 FUN_00796910(void)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int **)(in_ECX + 8) >> 8),
                  **(int **)(in_ECX + 8) != *(int *)(in_ECX + 0xc));
}


// ==== FUN_00796920 @ 0x00796920 ====

void FUN_00796920(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = **(undefined4 **)(in_ECX + 8);
  return;
}


// ==== FUN_00796930 @ 0x00796930 ====

void FUN_00796930(byte param_1)

{
  void *in_ECX;
  
  FUN_007968b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00796950 @ 0x00796950 ====

void FUN_00796950(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9d78;
  return;
}


// ==== FUN_00796960 @ 0x00796960 ====

void FUN_00796960(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9d78;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00796980 @ 0x00796980 ====

void FUN_00796980(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    piVar1 = (int *)(*(int *)(in_ECX + 0xc) + 0x100004);
    *piVar1 = *piVar1 + -1;
    return;
  }
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + -1;
  return;
}


// ==== FUN_007969c0 @ 0x007969c0 ====

void FUN_007969c0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009989ae;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f9d9c;
  in_ECX[1] = 0;
  puVar1 = operator_new(0x100008);
  local_4._0_1_ = 1;
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f9d94;
    _eh_vector_constructor_iterator_(puVar1 + 1,0x400,0x400,FUN_005fd550,FUN_006ef6d0);
    puVar1[0x40001] = 0;
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = puVar1;
  puVar1 = operator_new(0x100008);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009f9d94;
    _eh_vector_constructor_iterator_(puVar1 + 1,0x400,0x400,FUN_005fd550,FUN_006ef6d0);
    puVar1[0x40001] = 0;
  }
  in_ECX[3] = puVar1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a684 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a684 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00796ad0 @ 0x00796ad0 ====

void FUN_00796ad0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009989c0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f9d9c;
  DAT_00b5a684 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_009f9d78;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00796b40 @ 0x00796b40 ====

undefined4 FUN_00796b40(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if (param_1 == 0) {
    iVar1 = *(int *)(in_ECX + 8);
  }
  else {
    if (param_1 != 1) {
      return 0;
    }
    iVar1 = *(int *)(in_ECX + 0xc);
  }
  if (iVar1 == 0) {
    return 0;
  }
  return *(undefined4 *)(iVar1 + 0x100004);
}


// ==== FUN_00796b70 @ 0x00796b70 ====

int FUN_00796b70(uint param_1)

{
  uint uVar1;
  int *in_ECX;
  int iVar2;
  
  if (param_1 == 0) {
    iVar2 = in_ECX[2];
  }
  else {
    if (param_1 != 1) {
      return 0;
    }
    iVar2 = in_ECX[3];
  }
  if ((iVar2 == 0) || (uVar1 = (**(code **)(*in_ECX + 0x10))(param_1), uVar1 <= param_1)) {
    return 0;
  }
  return param_1 * 0x400 + 4 + iVar2;
}


// ==== FUN_00796bb0 @ 0x00796bb0 ====

void FUN_00796bb0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_400 [1024];
  
  if (*(uint *)(*(int *)(in_ECX + 8) + 0x100004) < 0x400) {
    piVar1 = (int *)(*(int *)(in_ECX + 8) + 0x100004);
    *piVar1 = *piVar1 + 1;
    FUN_00796cc0(local_400,&DAT_009f9d70,param_1);
    FUN_00648690(local_400);
  }
  return;
}


// ==== FUN_00796c10 @ 0x00796c10 ====

void FUN_00796c10(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined1 local_400 [1024];
  
  if (*(uint *)(*(int *)(in_ECX + 0xc) + 0x100004) < 0x400) {
    piVar1 = (int *)(*(int *)(in_ECX + 0xc) + 0x100004);
    *piVar1 = *piVar1 + 1;
    FUN_00796cc0(local_400,&DAT_009f9d70,param_1);
    FUN_00648690(local_400);
    return;
  }
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 1;
  return;
}


// ==== FUN_00796c80 @ 0x00796c80 ====

void FUN_00796c80(byte param_1)

{
  void *in_ECX;
  
  FUN_00796ca0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00796ca0 @ 0x00796ca0 ====

void FUN_00796ca0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9d94;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x400,0x400,FUN_006ef6d0);
  return;
}


// ==== FUN_00796cc0 @ 0x00796cc0 ====

char * FUN_00796cc0(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x400,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x400)) {
    param_1[0x3ff] = '\0';
  }
  return param_1;
}


// ==== FUN_00796d00 @ 0x00796d00 ====

void FUN_00796d00(byte param_1)

{
  void *in_ECX;
  
  FUN_00796ad0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00796d20 @ 0x00796d20 ====

void FUN_00796d20(undefined4 param_1)

{
  if (DAT_00b5b1bc != (int *)0x0) {
    (**(code **)(*DAT_00b5b1bc + 4))(1,param_1);
  }
  return;
}


// ==== FUN_00796d40 @ 0x00796d40 ====

void FUN_00796d40(void)

{
                    /* WARNING: Could not recover jumptable at 0x00796d48. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a684 + 0xc))();
  return;
}


// ==== FUN_00796d50 @ 0x00796d50 ====

void FUN_00796d50(int param_1)

{
  if (DAT_00b5b1bc != (int *)0x0) {
    (**(code **)(*DAT_00b5b1bc + 4))(0,param_1);
    return;
  }
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    OutputDebugStringA((LPCSTR)(param_1 + 4));
    return;
  }
  OutputDebugStringA(*(LPCSTR *)(param_1 + 4));
  return;
}


// ==== FUN_00796d90 @ 0x00796d90 ====

void FUN_00796d90(int param_1)

{
  if (DAT_00b5b1bc != (int *)0x0) {
    (**(code **)(*DAT_00b5b1bc + 4))(2,param_1);
    return;
  }
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    OutputDebugStringA((LPCSTR)(param_1 + 4));
    return;
  }
  OutputDebugStringA(*(LPCSTR *)(param_1 + 4));
  return;
}


// ==== FUN_00796dd0 @ 0x00796dd0 ====

void FUN_00796dd0(int param_1)

{
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    (**(code **)(*DAT_00b5a684 + 4))(param_1 + 4);
    return;
  }
  (**(code **)(*DAT_00b5a684 + 4))(*(undefined4 *)(param_1 + 4));
  return;
}


// ==== FUN_00796e00 @ 0x00796e00 ====

void FUN_00796e00(int param_1)

{
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    (**(code **)(*DAT_00b5a684 + 8))(param_1 + 4);
    return;
  }
  (**(code **)(*DAT_00b5a684 + 8))(*(undefined4 *)(param_1 + 4));
  return;
}


// ==== FUN_00796e60 @ 0x00796e60 ====

void FUN_00796e60(int param_1)

{
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    _atol((char *)(param_1 + 4));
    return;
  }
  _atol(*(char **)(param_1 + 4));
  return;
}


// ==== FUN_00796e90 @ 0x00796e90 ====

int FUN_00796e90(int param_1)

{
  char *_Src;
  
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    _Src = (char *)(param_1 + 4);
  }
  else {
    _Src = *(char **)(param_1 + 4);
  }
  __snscanf(_Src,*(size_t *)(param_1 + 0x14),&DAT_009f9dbc,&param_1);
  return param_1;
}


// ==== FUN_00796ec0 @ 0x00796ec0 ====

float10 FUN_00796ec0(int param_1)

{
  double dVar1;
  
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    dVar1 = _atof((char *)(param_1 + 4));
    return (float10)dVar1;
  }
  dVar1 = _atof(*(char **)(param_1 + 4));
  return (float10)dVar1;
}


// ==== FUN_00796f50 @ 0x00796f50 ====

void FUN_00796f50(int param_1)

{
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    _atol((char *)(param_1 + 4));
    return;
  }
  _atol(*(char **)(param_1 + 4));
  return;
}


// ==== __break @ 0x00796f72 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00796f80 @ 0x00796f80 ====

void FUN_00796f80(int param_1)

{
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    _atol((char *)(param_1 + 4));
    return;
  }
  _atol(*(char **)(param_1 + 4));
  return;
}


// ==== FUN_00796fb0 @ 0x00796fb0 ====

void FUN_00796fb0(int param_1)

{
  if (*(uint *)(param_1 + 0x18) < 0x10) {
    _atol((char *)(param_1 + 4));
    return;
  }
  _atol(*(char **)(param_1 + 4));
  return;
}


// ==== FUN_00796fe0 @ 0x00796fe0 ====

uint FUN_00796fe0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),&DAT_009f9dc0,4);
  if (iVar1 != 0) {
    uVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x14),&DAT_009f9dc8,4);
    if (uVar2 != 0) {
      return uVar2 & 0xffffff00;
    }
  }
  return 1;
}


// ==== FUN_00797020 @ 0x00797020 ====

int FUN_00797020(int param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 ****ppppuVar3;
  int extraout_EAX;
  uint uVar4;
  undefined1 local_28 [4];
  undefined4 ****local_24 [4];
  uint local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009989d8;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24[0] = (undefined4 ****)((uint)local_24[0] & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401660(param_2,0,0xffffffff);
  uVar2 = local_14;
  uVar4 = 0;
  local_4 = 0;
  if (local_14 != 0) {
    do {
      if (local_14 <= uVar4) {
        FUN_0079dba3();
      }
      ppppuVar3 = local_24[0];
      if (local_10 < 0x10) {
        ppppuVar3 = local_24;
      }
      cVar1 = *(char *)((int)ppppuVar3 + uVar4);
      if (('@' < cVar1) && (cVar1 < '[')) {
        ppppuVar3 = local_24[0];
        if (local_10 < 0x10) {
          ppppuVar3 = local_24;
        }
        *(char *)((int)ppppuVar3 + uVar4) = cVar1 + ' ';
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_28,0,0xffffffff);
  if (local_10 < 0x10) {
    ExceptionList = pvStack_c;
    return param_1;
  }
  _free(local_24[0]);
  return extraout_EAX;
}


// ==== FUN_00797110 @ 0x00797110 ====

int FUN_00797110(int param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 ****ppppuVar3;
  int extraout_EAX;
  uint uVar4;
  undefined1 local_28 [4];
  undefined4 ****local_24 [4];
  uint local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009989ea;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24[0] = (undefined4 ****)((uint)local_24[0] & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401660(param_2,0,0xffffffff);
  uVar2 = local_14;
  uVar4 = 0;
  local_4 = 0;
  if (local_14 != 0) {
    do {
      if (local_14 <= uVar4) {
        FUN_0079dba3();
      }
      ppppuVar3 = local_24[0];
      if (local_10 < 0x10) {
        ppppuVar3 = local_24;
      }
      cVar1 = *(char *)((int)ppppuVar3 + uVar4);
      if (('`' < cVar1) && (cVar1 < '{')) {
        ppppuVar3 = local_24[0];
        if (local_10 < 0x10) {
          ppppuVar3 = local_24;
        }
        *(char *)((int)ppppuVar3 + uVar4) = cVar1 + -0x20;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_28,0,0xffffffff);
  if (local_10 < 0x10) {
    ExceptionList = pvStack_c;
    return param_1;
  }
  _free(local_24[0]);
  return extraout_EAX;
}


// ==== FUN_00797200 @ 0x00797200 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */

int FUN_00797200(int param_1,undefined4 param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  int extraout_EAX;
  uint in_stack_00000020;
  va_list in_stack_00000024;
  char local_280c [10236];
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009989fc;
  local_c = ExceptionList;
  uStack_10 = 0x79721f;
  local_4 = 0;
  pcVar2 = param_3;
  if (in_stack_00000020 < 0x10) {
    pcVar2 = (char *)&param_3;
  }
  ExceptionList = &local_c;
  __vsnprintf(local_280c,0x27ff,pcVar2,in_stack_00000024);
  pcVar2 = local_280c;
  uStack_10 = uStack_10 & 0xffffff;
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(local_280c,(int)pcVar2 - (int)(local_280c + 1));
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(param_3);
  return extraout_EAX;
}


// ==== FUN_007972d0 @ 0x007972d0 ====

int FUN_007972d0(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(param_2 + 0x14);
  uVar3 = 0;
  if (uVar4 != 0) {
    do {
      if (*(uint *)(param_2 + 0x14) <= uVar3) {
        FUN_0079dba3();
      }
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        iVar1 = param_2 + 4;
      }
      else {
        iVar1 = *(int *)(param_2 + 4);
      }
      iVar1 = _isspace((int)*(char *)(iVar1 + uVar3));
      uVar2 = uVar4;
      if (iVar1 == 0) goto joined_r0x00797326;
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
LAB_00797366:
    if (uVar3 != 0) goto LAB_00797398;
  }
  if (uVar4 == *(uint *)(param_2 + 0x14)) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(param_2,0,0xffffffff);
    return param_1;
  }
LAB_00797398:
  FUN_00405b90(param_1,uVar3,uVar4);
  return param_1;
joined_r0x00797326:
  if (uVar4 <= uVar3) goto LAB_00797366;
  uVar2 = uVar2 - 1;
  if (*(uint *)(param_2 + 0x14) <= uVar2) {
    FUN_0079dba3();
  }
  if (*(uint *)(param_2 + 0x18) < 0x10) {
    iVar1 = param_2 + 4;
  }
  else {
    iVar1 = *(int *)(param_2 + 4);
  }
  iVar1 = _isspace((int)*(char *)(uVar2 + iVar1));
  if (iVar1 == 0) goto LAB_00797366;
  uVar4 = uVar4 - 1;
  goto joined_r0x00797326;
}


// ==== FUN_00797530 @ 0x00797530 ====

int FUN_00797530(int param_1,undefined1 param_2,void *param_3)

{
  int extraout_EAX;
  int extraout_EAX_00;
  uint in_stack_00000020;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998a38;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00401660(&param_2,0,0xffffffff);
  FUN_00797200(local_28);
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660();
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(param_3);
  return extraout_EAX_00;
}


// ==== FUN_00797600 @ 0x00797600 ====

/* WARNING: Removing unreachable block (ram,0x007976c5) */
/* WARNING: Removing unreachable block (ram,0x00797755) */

int FUN_00797600(int param_1)

{
  undefined4 *******pppppppuVar1;
  int extraout_EAX;
  char cVar2;
  undefined4 *******pppppppuVar3;
  undefined1 local_28 [4];
  undefined4 *******local_24 [4];
  int local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00998a52;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00401740(&DAT_009f9db8,2);
  FUN_00797530(local_28);
  pppppppuVar3 = local_24[0];
  if (local_10 < 0x10) {
    pppppppuVar3 = local_24;
  }
  pppppppuVar3 = (undefined4 *******)((int)pppppppuVar3 + local_14);
  local_4 = 1;
  cVar2 = '\0';
  while( true ) {
    pppppppuVar1 = local_24[0];
    if (local_10 < 0x10) {
      pppppppuVar1 = local_24;
    }
    if (pppppppuVar3 == pppppppuVar1) break;
    if (cVar2 == '\x03') {
      FUN_00557c50();
      cVar2 = '\0';
    }
    FUN_00557c50();
    pppppppuVar3 = (undefined4 *******)((int)pppppppuVar3 + -1);
    cVar2 = cVar2 + '\x01';
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660();
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_24[0]);
  return extraout_EAX;
}


// ==== FUN_007977a0 @ 0x007977a0 ====

void FUN_007977a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9dd4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007977c0 @ 0x007977c0 ====

void FUN_007977c0(byte param_1)

{
  void *in_ECX;
  
  FUN_007977e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007977e0 @ 0x007977e0 ====

void FUN_007977e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9dd4;
  return;
}


// ==== FUN_007977f0 @ 0x007977f0 ====

void FUN_007977f0(void)

{
  void *pvVar1;
  undefined4 *puVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00998aa2;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_00b5a6a8 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_0079a710();
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5a6ac == 0) {
    pvVar1 = operator_new(0xa8);
    local_4 = 1;
    if (pvVar1 != (void *)0x0) {
      FUN_0079a590();
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5a72c == 0) {
    pvVar1 = operator_new(0xc);
    local_4 = 2;
    if (pvVar1 != (void *)0x0) {
      FUN_00799f00();
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5b1bc == 0) {
    pvVar1 = operator_new(8);
    local_4 = 3;
    if (pvVar1 != (void *)0x0) {
      FUN_00799d90();
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5a990 == 0) {
    pvVar1 = operator_new(0x74);
    local_4 = 4;
    if (pvVar1 != (void *)0x0) {
      FUN_007994e0();
    }
  }
  local_4 = 0xffffffff;
  if ((DAT_00b5a98c == 0) && (puVar2 = operator_new(4), puVar2 != (undefined4 *)0x0)) {
    *puVar2 = &PTR_FUN_009f9df4;
  }
  if (DAT_00b5a82c == 0) {
    pvVar1 = operator_new(4);
    local_4 = 5;
    if (pvVar1 != (void *)0x0) {
      FUN_007980e0(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00797950 @ 0x00797950 ====

void FUN_00797950(void)

{
  if (DAT_00b5a82c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a82c)(1);
  }
  if (DAT_00b5a6a8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6a8)(1);
  }
  if (DAT_00b5a6ac != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6ac)(1);
  }
  if (DAT_00b5b1bc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5b1bc)(1);
  }
  if (DAT_00b5a72c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a72c)(1);
  }
  if (DAT_00b5a990 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a990)(1);
  }
  if (DAT_00b5a98c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a98c)(1);
  }
  return;
}


// ==== FUN_007979d0 @ 0x007979d0 ====

bool FUN_007979d0(void)

{
  BOOL BVar1;
  _OSVERSIONINFOA local_94;
  
  FUN_00797a50(&local_94,0,0x94);
  local_94.dwOSVersionInfoSize = 0x94;
  BVar1 = GetVersionExA(&local_94);
  if (BVar1 == 1) {
    return local_94.dwPlatformId == 2;
  }
  return false;
}


// ==== FUN_00797a20 @ 0x00797a20 ====

void FUN_00797a20(undefined4 param_1)

{
  (**(code **)(*DAT_00b5a840 + 0x18))(param_1);
  return;
}


// ==== FUN_00797a40 @ 0x00797a40 ====

void FUN_00797a40(void)

{
  return;
}


// ==== FUN_00797a50 @ 0x00797a50 ====

void FUN_00797a50(undefined4 *param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2));
    param_1 = param_1 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)param_1 = param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}


// ==== FUN_00797a80 @ 0x00797a80 ====

void FUN_00797a80(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  for (param_3 = param_3 & 3; param_3 != 0; param_3 = param_3 - 1) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    param_1 = (undefined4 *)((int)param_1 + 1);
  }
  return;
}


// ==== FUN_00797ac0 @ 0x00797ac0 ====

int FUN_00797ac0(int param_1)

{
  int iVar1;
  
  iVar1 = _rand();
  return iVar1 % param_1;
}


// ==== FUN_00797b80 @ 0x00797b80 ====

void FUN_00797b80(char *param_1)

{
  char cVar1;
  char *pcVar2;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00998ab8;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  ExceptionList = &local_c;
  FUN_00401740(param_1,(int)pcVar2 - (int)(param_1 + 1));
  local_4 = 0;
  FUN_00796d50(local_28);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00797c60 @ 0x00797c60 ====

void FUN_00797c60(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x14))();
  iVar1 = (**(code **)(*in_ECX + 0x18))();
  in_ECX[0x1e] = iVar1;
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  in_ECX[0x1f] = iVar1;
  in_ECX[0x20] = *param_1;
  in_ECX[0x21] = param_1[1];
  in_ECX[0x22] = param_1[2];
  in_ECX[0x23] = param_1[3];
  in_ECX[0x24] = *param_1;
  in_ECX[0x25] = param_1[1];
  in_ECX[0x26] = param_1[2];
  in_ECX[0x27] = param_1[3];
  return;
}


// ==== FUN_00797cc0 @ 0x00797cc0 ====

int FUN_00797cc0(void)

{
  int in_ECX;
  
  return in_ECX + 0x80;
}


// ==== FUN_00797cd0 @ 0x00797cd0 ====

int FUN_00797cd0(void)

{
  int in_ECX;
  
  return in_ECX + 0x90;
}


// ==== FUN_00797ce0 @ 0x00797ce0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00797ce0(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar2 = FUN_0079ac20();
  iVar3 = iVar2 - *(int *)(in_ECX + 0x7c);
  *(int *)(in_ECX + 0xa4) = iVar2;
  fVar1 = (float)iVar3;
  if (iVar3 < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  *(int *)(in_ECX + 0xa0) = (int)ROUND(fVar1 * *(float *)(in_ECX + 0x70)) + *(int *)(in_ECX + 0x78);
  *(int *)(in_ECX + 0xa8) =
       ((int)ROUND(fVar1 * *(float *)(in_ECX + 0x74)) - *(int *)(in_ECX + 0x88)) +
       *(int *)(in_ECX + 0x84) + *(int *)(in_ECX + 0x78);
  if (1000 < (uint)(iVar2 - *(int *)(in_ECX + 0xac))) {
    FUN_0079ac90();
    *(undefined4 *)(in_ECX + 0xac) = *(undefined4 *)(in_ECX + 0xa4);
  }
  return;
}


// ==== FUN_00797da0 @ 0x00797da0 ====

undefined4 FUN_00797da0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0);
}


// ==== FUN_00797db0 @ 0x00797db0 ====

undefined4 FUN_00797db0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa4);
}


// ==== FUN_00797dc0 @ 0x00797dc0 ====

undefined4 FUN_00797dc0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa8);
}


// ==== FUN_00797dd0 @ 0x00797dd0 ====

void FUN_00797dd0(void)

{
  FUN_0079ac20();
  return;
}


// ==== FUN_00797e00 @ 0x00797e00 ====

void FUN_00797e00(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998ad8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f9e48;
  FUN_0079ab10();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a6ac = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a6ac = in_ECX;
  }
  in_ECX[0x1e] = *(undefined4 *)(param_1 + 8);
  in_ECX[0x1f] = *(undefined4 *)(param_1 + 0xc);
  in_ECX[0x20] = *(undefined4 *)(param_1 + 0x14);
  in_ECX[0x21] = *(undefined4 *)(param_1 + 0x18);
  in_ECX[0x22] = *(undefined4 *)(param_1 + 0x1c);
  in_ECX[0x23] = *(undefined4 *)(param_1 + 0x20);
  in_ECX[0x24] = *(undefined4 *)(param_1 + 0x24);
  in_ECX[0x25] = *(undefined4 *)(param_1 + 0x28);
  in_ECX[0x26] = *(undefined4 *)(param_1 + 0x2c);
  in_ECX[0x27] = *(undefined4 *)(param_1 + 0x30);
  in_ECX[0x28] = *(undefined4 *)(param_1 + 8);
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  in_ECX[0x29] = uVar1;
  uVar2 = *(undefined4 *)(param_1 + 0x10);
  in_ECX[0x2b] = uVar1;
  in_ECX[0x2a] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00797ed0 @ 0x00797ed0 ====

void FUN_00797ed0(undefined4 *param_1)

{
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x98) != param_1[2]) || (*(int *)(in_ECX + 0x9c) != param_1[3])) ||
     (*(int *)(in_ECX + 0x94) != param_1[1])) {
    *(undefined4 *)(in_ECX + 0x90) = *param_1;
    *(undefined4 *)(in_ECX + 0x94) = param_1[1];
    *(undefined4 *)(in_ECX + 0x98) = param_1[2];
    *(undefined4 *)(in_ECX + 0x9c) = param_1[3];
  }
  return;
}


// ==== FUN_00797f20 @ 0x00797f20 ====

void FUN_00797f20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998aea;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f9e48;
  local_4 = 0;
  DAT_00b5a6ac = 0;
  FUN_0079abb0();
  *in_ECX = &PTR_FUN_009f9e1c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00797f70 @ 0x00797f70 ====

void FUN_00797f70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9e1c;
  return;
}


// ==== FUN_00797f80 @ 0x00797f80 ====

void FUN_00797f80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f9e1c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00797fa0 @ 0x00797fa0 ====

void FUN_00797fa0(byte param_1)

{
  void *in_ECX;
  
  FUN_00797f20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00797fc0 @ 0x00797fc0 ====

void FUN_00797fc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa050;
  return;
}


// ==== FUN_00797fd0 @ 0x00797fd0 ====

void FUN_00797fd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa050;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00798000 @ 0x00798000 ====

void FUN_00798000(void)

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
  
  puStack_8 = &LAB_00998b38;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009fa05c;
  local_4 = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_support_movecache_009f9fa8,0x11);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a7d8 + 8))(&local_28);
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = (void *)0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_support_output_visible_009f9fbc,0x16);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a7d8 + 8))(&local_2c);
  if (uStack_18 < 0x10) {
    DAT_00b5a82c = 0;
    *in_ECX = &PTR_FUN_009fa050;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_007980e0 @ 0x007980e0 ====

undefined4 FUN_007980e0(void)

{
  undefined4 extraout_EAX;
  int iVar1;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  undefined4 *in_ECX;
  undefined4 unaff_EBP;
  undefined1 local_bc [4];
  void *local_b8;
  undefined4 local_a8;
  void *local_a4;
  undefined1 local_a0 [16];
  uint uStack_90;
  undefined1 uStack_88;
  undefined1 uStack_87;
  void *pvStack_84;
  undefined4 uStack_74;
  uint uStack_70;
  undefined1 auStack_68 [4];
  void *pvStack_64;
  undefined4 uStack_54;
  uint uStack_50;
  void *pvStack_48;
  undefined4 uStack_38;
  uint uStack_34;
  void *pvStack_28;
  undefined4 uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998b73;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009fa05c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a82c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a82c = in_ECX;
  }
  local_a4 = (void *)0xf;
  local_a8 = 0;
  local_b8 = (void *)((uint)local_b8 & 0xffffff00);
  FUN_00401740(s_support_movecache_009f9f24,0x11);
  local_4._0_1_ = 1;
  FUN_0040bf70(local_bc,1);
  local_4 = CONCAT31(local_4._1_3_,3);
  if ((void *)0xf < local_a4) {
    _free(local_b8);
    return extraout_EAX;
  }
  local_a4 = (void *)0xf;
  local_a8 = 0;
  local_b8 = (void *)((uint)local_b8 & 0xffffff00);
  FUN_00401740(s_support_movecache__filename__009f9f38,0x1c);
  (**(code **)(*DAT_00b5a7d8 + 4))(local_a0);
  uStack_50 = 0xf;
  uStack_54 = 0;
  pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
  FUN_00401740(s_support_output_visible_009f9f58,0x16);
  puStack_8._0_1_ = 4;
  iVar1 = FUN_0040bf70(auStack_68,3);
  puStack_8._0_1_ = 5;
  FUN_00401660(iVar1,0,0xffffffff);
  uStack_88 = *(undefined1 *)(iVar1 + 0x1c);
  uStack_87 = *(undefined1 *)(iVar1 + 0x1d);
  FUN_00401660(iVar1 + 0x20,0,0xffffffff);
  if (0xf < pvStack_14) {
    _free(pvStack_28);
    return extraout_EAX_00;
  }
  pvStack_14 = (void *)0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return extraout_EAX_01;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
  if (0xf < uStack_50) {
    _free(pvStack_64);
    return extraout_EAX_02;
  }
  FUN_00401740(s_support_output_filter__debug_0_1_009f9f70,0x34);
  (**(code **)(*DAT_00b5a7d8 + 4))(&local_a4);
  if (0xf < uStack_70) {
    _free(pvStack_84);
    return extraout_EAX_03;
  }
  uStack_70 = 0xf;
  uStack_74 = 0;
  pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
  if (uStack_90 < 0x10) {
    ExceptionList = pvStack_14;
    return unaff_EBP;
  }
  _free(local_a4);
  return extraout_EAX_04;
}


// ==== FUN_00798310 @ 0x00798310 ====

void FUN_00798310(undefined4 param_1)

{
  uint *puVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  undefined1 **ppuVar9;
  uint *puVar10;
  undefined4 *puVar11;
  undefined1 auStack_138 [4];
  undefined1 uStack_134;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 ****ppppuStack_11c;
  double dStack_118;
  undefined8 uStack_110;
  undefined8 uStack_108;
  float *pfStack_100;
  undefined1 *puVar12;
  undefined1 auStack_e8 [4];
  undefined4 ****appppuStack_e4 [4];
  int iStack_d4;
  uint uStack_d0;
  undefined4 *local_c8;
  int local_c4;
  float fStack_c0;
  float fStack_bc;
  undefined1 *puStack_b8;
  float fStack_b4;
  float fStack_b0;
  undefined4 *puStack_ac;
  undefined **appuStack_a8 [4];
  uint *puStack_98;
  uint *puStack_94;
  undefined4 uStack_90;
  undefined1 *puStack_8c;
  undefined1 auStack_88 [4];
  void *pvStack_84;
  undefined4 uStack_74;
  uint uStack_70;
  undefined1 auStack_6c [4];
  void *pvStack_68;
  undefined4 uStack_58;
  uint uStack_54;
  undefined1 auStack_50 [4];
  void *pvStack_4c;
  undefined4 uStack_3c;
  uint uStack_38;
  undefined1 auStack_34 [4];
  void *pvStack_30;
  undefined4 uStack_20;
  uint uStack_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  int local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00998bea;
  pvStack_14 = ExceptionList;
  _pfStack_100 = (double)CONCAT44(0x79833d,pfStack_100);
  ExceptionList = &pvStack_14;
  local_c8 = (undefined4 *)FUN_00415ec0();
  *(undefined1 *)((int)local_c8 + 0x29) = 1;
  local_c8[1] = local_c8;
  *local_c8 = local_c8;
  local_c8[2] = local_c8;
  local_c4 = 0;
  local_c = 0;
  _pfStack_100 = (double)CONCAT44(0x798371,pfStack_100);
  piVar5 = (int *)(**(code **)(*DAT_00b5a780 + 0xc))();
  while (piVar5 != (int *)0x0) {
    _pfStack_100 = (double)CONCAT44(0x798387,pfStack_100);
    iVar6 = (**(code **)(*piVar5 + 0x10))();
    while (iVar6 != 0) {
      uStack_d0 = 0xf;
      iStack_d4 = 0;
      appppuStack_e4[0] = (undefined4 ****)((uint)appppuStack_e4[0] & 0xffffff00);
      pcVar7 = (char *)(iVar6 + 0xc);
      do {
        cVar2 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      _pfStack_100 = (double)CONCAT44((int)pcVar7 - (iVar6 + 0xd),(char *)(iVar6 + 0xc));
      uStack_108 = (double)CONCAT44(0x7983be,(undefined4)uStack_108);
      FUN_00401740();
      local_c._0_1_ = 1;
      if (iStack_d4 != 0) {
        _pfStack_100 = (double)CONCAT44(auStack_e8,&fStack_c0);
        uStack_108 = (double)CONCAT44(0x7983df,(undefined4)uStack_108);
        FUN_00799200();
      }
      local_c = (uint)local_c._1_3_ << 8;
      if (0xf < uStack_d0) {
        _pfStack_100 = (double)CONCAT44(appppuStack_e4[0],0x7983f7);
        _free(appppuStack_e4[0]);
        return;
      }
      uStack_d0 = 0xf;
      iStack_d4 = 0;
      appppuStack_e4[0] = (undefined4 ****)((uint)appppuStack_e4[0] & 0xffffff00);
      _pfStack_100 = (double)CONCAT44(0x798411,pfStack_100);
      iVar6 = (**(code **)(*piVar5 + 0x14))();
    }
    _pfStack_100 = (double)CONCAT44(0x798424,pfStack_100);
    piVar5 = (int *)(**(code **)(*DAT_00b5a780 + 0x10))();
  }
  if (local_c4 == 0) {
    _pfStack_100 = (double)CONCAT44(local_c8,*local_c8);
    ppuVar9 = &puStack_b8;
  }
  else {
    puVar12 = auStack_e8;
    pfStack_100 = (float *)0x79844f;
    uVar8 = FUN_00404890();
    _pfStack_100 = (double)CONCAT44(puVar12,uVar8);
    local_c._0_1_ = 2;
    uStack_108 = (double)CONCAT44(auStack_88,0x798462);
    FUN_004045b0();
    local_c._0_1_ = 4;
    if (0xf < uStack_d0) {
      _pfStack_100 = (double)CONCAT44(appppuStack_e4[0],0x79847e);
      _free(appppuStack_e4[0]);
      return;
    }
    _pfStack_100 = (double)CONCAT44(param_1,auStack_88);
    uStack_d0 = 0xf;
    iStack_d4 = 0;
    appppuStack_e4[0] = (undefined4 ****)((uint)appppuStack_e4[0] & 0xffffff00);
    uStack_108 = (double)CONCAT44(auStack_6c,0x7984a8);
    FUN_00405bd0();
    appuStack_a8[0] = &PTR_FUN_0099d55c;
    puStack_98 = (uint *)0x0;
    puStack_94 = (uint *)0x0;
    uStack_90 = 0;
    puVar11 = (undefined4 *)*local_c8;
    _pfStack_100 = 7.63970169923078e-313;
    local_c._0_1_ = 7;
    puStack_ac = local_c8;
    uStack_d0 = 0xf;
    iStack_d4 = 0;
    appppuStack_e4[0] = (undefined4 ****)((uint)appppuStack_e4[0] & 0xffffff00);
    uStack_108 = (double)CONCAT44(0x7984ed,(undefined4)uStack_108);
    FUN_00401740();
    local_c._0_1_ = 8;
    _pfStack_100 = (double)CONCAT44(auStack_e8,0x798503);
    FUN_00411630();
    local_c._0_1_ = 7;
    if (0xf < uStack_d0) {
      _pfStack_100 = (double)CONCAT44(appppuStack_e4[0],0x79851c);
      _free(appppuStack_e4[0]);
      return;
    }
    if (puVar11 != puStack_ac) {
      do {
        local_c._0_1_ = 7;
        _pfStack_100 = -NAN;
        uStack_d0 = 0xf;
        iStack_d4 = 0;
        appppuStack_e4[0] = (undefined4 ****)((uint)appppuStack_e4[0] & 0xffffff00);
        uStack_108 = (double)CONCAT44(puVar11 + 3,0x79854c);
        FUN_00401660();
        local_c._0_1_ = 9;
        _pfStack_100 = (double)CONCAT44(auStack_e8,0x79855e);
        iVar6 = FUN_00798bb0();
        if (iVar6 == 0) {
          local_c._0_1_ = 7;
          if (0xf < uStack_d0) {
            _pfStack_100 = (double)CONCAT44(appppuStack_e4[0],0x798584);
            _free(appppuStack_e4[0]);
            return;
          }
        }
        else {
          uStack_108._4_4_ = auStack_50;
          _pfStack_100 = (double)CONCAT44(auStack_e8,s_Cache_009fa034);
          uStack_108._0_4_ = 0x7985ab;
          uVar8 = FUN_004022a0();
          uStack_108 = (double)CONCAT44(uStack_108._4_4_,uVar8);
          local_c._0_1_ = 10;
          uStack_110 = (double)CONCAT44(0x7985b9,(undefined4)uStack_110);
          FUN_00796d50();
          local_c._0_1_ = 9;
          if (0xf < uStack_38) {
            _pfStack_100 = (double)CONCAT44(pvStack_4c,0x7985db);
            _free(pvStack_4c);
            return;
          }
          fStack_c0 = *(float *)(iVar6 + 0x58);
          fStack_bc = *(float *)(iVar6 + 0x5c);
          fStack_b4 = *(float *)(iVar6 + 0x60);
          fStack_b0 = *(float *)(iVar6 + 100);
          uStack_38 = 0xf;
          uStack_3c = 0;
          pvStack_4c = (void *)((uint)pvStack_4c & 0xffffff00);
          _pfStack_100 = (double)CONCAT44(iVar6,0x79861f);
          (**(code **)(*DAT_00b5a7cc + 0x1c))();
          puStack_b8 = (undefined1 *)
                       ((fStack_b4 - fStack_c0) * (fStack_b4 - fStack_c0) +
                       (fStack_b0 - fStack_bc) * (fStack_b0 - fStack_bc));
          if (SQRT((float)puStack_b8) < DAT_009a09bc) {
            local_c._0_1_ = 7;
            if (0xf < uStack_d0) {
              _pfStack_100 = (double)CONCAT44(appppuStack_e4[0],0x79867a);
              _free(appppuStack_e4[0]);
              return;
            }
          }
          else {
            _pfStack_100 = (double)fStack_b0;
            uStack_108 = (double)fStack_b4;
            uStack_110 = (double)fStack_bc;
            dStack_118 = (double)fStack_c0;
            ppppuStack_11c = appppuStack_e4[0];
            if (uStack_d0 < 0x10) {
              ppppuStack_11c = appppuStack_e4;
            }
            puStack_8c = auStack_138;
            uStack_120 = 0xf;
            uStack_124 = 0;
            uStack_134 = 0;
            FUN_00401740(s__s__f__f__f__f_009fa03c,0xe);
            uVar8 = FUN_00797530(auStack_34);
            local_c._0_1_ = 0xb;
            _pfStack_100 = (double)CONCAT44(uVar8,0x798704);
            FUN_00411630();
            if (0xf < uStack_1c) {
              _pfStack_100 = (double)CONCAT44(pvStack_30,0x79871b);
              _free(pvStack_30);
              return;
            }
            uStack_1c = 0xf;
            uStack_20 = 0;
            pvStack_30 = (void *)((uint)pvStack_30 & 0xffffff00);
            local_c._0_1_ = 7;
            if (0xf < uStack_d0) {
              _pfStack_100 = (double)CONCAT44(appppuStack_e4[0],0x79874c);
              _free(appppuStack_e4[0]);
              return;
            }
          }
        }
        uStack_d0 = 0xf;
        iStack_d4 = 0;
        appppuStack_e4[0] = (undefined4 ****)((uint)appppuStack_e4[0] & 0xffffff00);
        if (*(char *)((int)puVar11 + 0x29) == '\0') {
          puVar3 = (undefined4 *)puVar11[2];
          if (*(char *)((int)puVar3 + 0x29) == '\0') {
            cVar2 = *(char *)((int)*puVar3 + 0x29);
            puVar11 = puVar3;
            puVar3 = (undefined4 *)*puVar3;
            while (cVar2 == '\0') {
              cVar2 = *(char *)((int)*puVar3 + 0x29);
              puVar11 = puVar3;
              puVar3 = (undefined4 *)*puVar3;
            }
          }
          else {
            cVar2 = *(char *)((int)puVar11[1] + 0x29);
            puVar4 = (undefined4 *)puVar11[1];
            puVar3 = puVar11;
            while ((puVar11 = puVar4, cVar2 == '\0' && (puVar3 == (undefined4 *)puVar11[2]))) {
              cVar2 = *(char *)((int)puVar11[1] + 0x29);
              puVar4 = (undefined4 *)puVar11[1];
              puVar3 = puVar11;
            }
          }
        }
      } while (puVar11 != puStack_ac);
    }
    local_c._0_1_ = 7;
    _pfStack_100 = (double)CONCAT44(appuStack_a8,auStack_6c);
    uStack_108 = (double)CONCAT44(0x7987bd,(undefined4)uStack_108);
    (**(code **)(*DAT_00b5a740 + 0xc))();
    appuStack_a8[0] = &PTR_FUN_0099d55c;
    if (puStack_98 != (uint *)0x0) {
      if (puStack_98 != puStack_94) {
        puVar10 = puStack_98 + 6;
        do {
          if (0xf < *puVar10) {
            _pfStack_100 = (double)CONCAT44((void *)puVar10[-5],0x7987e6);
            _free((void *)puVar10[-5]);
            return;
          }
          *puVar10 = 0xf;
          puVar10[-1] = 0;
          *(undefined1 *)(puVar10 + -5) = 0;
          puVar1 = puVar10 + 1;
          puVar10 = puVar10 + 7;
        } while (puVar1 != puStack_94);
      }
      _pfStack_100 = (double)CONCAT44(puStack_98,0x79880e);
      _free(puStack_98);
      return;
    }
    puStack_98 = (uint *)0x0;
    puStack_94 = (uint *)0x0;
    uStack_90 = 0;
    appuStack_a8[0] = &PTR_FUN_0099d408;
    if (0xf < uStack_54) {
      _pfStack_100 = (double)CONCAT44(pvStack_68,0x798840);
      _free(pvStack_68);
      return;
    }
    uStack_54 = 0xf;
    uStack_58 = 0;
    pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
    if (0xf < uStack_70) {
      _pfStack_100 = (double)CONCAT44(pvStack_84,0x79886b);
      _free(pvStack_84);
      return;
    }
    uStack_70 = 0xf;
    uStack_74 = 0;
    pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
    _pfStack_100 = (double)CONCAT44(local_c8,*local_c8);
    ppuVar9 = &puStack_8c;
  }
  local_c = 0xffffffff;
  uStack_108 = (double)CONCAT44(ppuVar9,0x7988a1);
  FUN_00799370();
  _pfStack_100 = (double)CONCAT44(local_c8,0x7988ab);
  _free(local_c8);
  return;
}


// ==== FUN_007988d0 @ 0x007988d0 ====

undefined4 FUN_007988d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int iVar3;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_28;
  void *local_24;
  uint uStack_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00998c14;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_support_movecache_009f9fd4,0x11);
  if (iVar1 == 0) {
    uVar2 = FUN_00459160(&local_28,0);
    local_4 = 0;
    FUN_00798310(uVar2);
    if (uStack_14 < 0x10) {
      ExceptionList = local_10;
      return 1;
    }
    _free(local_28);
    return extraout_EAX;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_support_output_visible_009f9fe8,0x16);
  if (iVar1 != 0) {
    ExceptionList = local_c;
    return 0;
  }
  iVar1 = FUN_00459160(&local_28,0);
  local_4 = 1;
  iVar1 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),&DAT_009fa000,1);
  local_4 = 0xffffffff;
  if ((void *)0xf < local_10) {
    _free(local_24);
    return extraout_EAX_00;
  }
  iVar3 = FUN_00459160(&local_28,1);
  local_4 = 2;
  FUN_00403620(0,*(undefined4 *)(iVar3 + 0x14),&DAT_009fa004,1);
  local_4 = 0xffffffff;
  if ((void *)0xf < local_10) {
    _free(local_24);
    return extraout_EAX_01;
  }
  iVar3 = FUN_00459160(local_44,2);
  local_4 = 3;
  FUN_00403620(0,*(undefined4 *)(iVar3 + 0x14),&DAT_009fa008,1);
  local_4 = 0xffffffff;
  if (local_2c < 0x10) {
    local_2c = 0xf;
    local_30 = 0;
    local_40 = (void *)((uint)local_40 & 0xffffff00);
    (**(code **)(*DAT_00b5b1bc + 8))(0,iVar1 != 0);
    (**(code **)(*DAT_00b5b1bc + 8))(1,unaff_ESI);
    (**(code **)(*DAT_00b5b1bc + 8))(2,unaff_EDI);
    ExceptionList = local_24;
    return 1;
  }
  _free(local_40);
  return extraout_EAX_02;
}


// ==== FUN_00798ad0 @ 0x00798ad0 ====

undefined4 FUN_00798ad0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_007988d0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00798b00 @ 0x00798b00 ====

void FUN_00798b00(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x29) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x29) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x29);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x29);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x29);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x29);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_00798b50 @ 0x00798b50 ====

void FUN_00798b50(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x29) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x29) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x29);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x29);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x29) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x29) == '\0');
    if (*(char *)((int)piVar4 + 0x29) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_00798bb0 @ 0x00798bb0 ====

undefined4 FUN_00798bb0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 extraout_EAX;
  void *local_2c;
  undefined1 local_28;
  uint local_18;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00998b08;
  pvStack_c = ExceptionList;
  local_14 = 0xf;
  local_18 = 0;
  local_28 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401660(param_1,0,0xffffffff);
  local_10 = (void *)0x9;
  local_4 = 0;
  uVar1 = (**(code **)(*DAT_00b5a7cc + 8))(&local_2c);
  if (local_18 < 0x10) {
    ExceptionList = local_10;
    return uVar1;
  }
  _free(local_2c);
  return extraout_EAX;
}


// ==== FUN_00798c40 @ 0x00798c40 ====

undefined4 *
FUN_00798c40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00998c31;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x2c);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    puVar1[9] = 0xf;
    puVar1[8] = 0;
    *(undefined1 *)(puVar1 + 4) = 0;
    FUN_00401660(param_4,0,0xffffffff);
    *(undefined1 *)(puVar1 + 10) = param_5;
    *(undefined1 *)((int)puVar1 + 0x29) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@00798ccb @ 0x00798ccb ====

void Catch_00798ccb(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00798cf0 @ 0x00798cf0 ====

void FUN_00798cf0(byte param_1)

{
  void *in_ECX;
  
  FUN_00798000();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00798d10 @ 0x00798d10 ====

void FUN_00798d10(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00998c48;
  local_c = ExceptionList;
  if (0x9249247 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_00798c40(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x28);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x28) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[10] == '\0') {
LAB_00798e09:
        *(undefined1 *)(*piVar5 + 0x28) = 1;
        *(undefined1 *)(piVar6 + 10) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x28) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_004c9300(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x28) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x28) = 0;
        FUN_0043e2e0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[10] == '\0') goto LAB_00798e09;
      if (piVar7 == (int *)*piVar2) {
        FUN_0043e2e0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x28) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x28) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x29) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x28);
  } while( true );
}


// ==== FUN_00798ef0 @ 0x00798ef0 ====

/* WARNING: Removing unreachable block (ram,0x00799000) */
/* WARNING: Removing unreachable block (ram,0x00799011) */
/* WARNING: Removing unreachable block (ram,0x0079901a) */
/* WARNING: Removing unreachable block (ram,0x0079901d) */
/* WARNING: Removing unreachable block (ram,0x0079900d) */
/* WARNING: Removing unreachable block (ram,0x0079902b) */
/* WARNING: Removing unreachable block (ram,0x00799038) */
/* WARNING: Removing unreachable block (ram,0x00799043) */
/* WARNING: Removing unreachable block (ram,0x0079903f) */
/* WARNING: Removing unreachable block (ram,0x00799033) */
/* WARNING: Removing unreachable block (ram,0x00799046) */

void FUN_00798ef0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00998c48;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x29) != '\0') {
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
  FUN_00798b00();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x29) == '\0') {
    if (*(char *)(param_2[2] + 0x29) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x29) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x29) == '\0') {
      piVar3 = (int *)FUN_00441380(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x29) == '\0') {
      uVar4 = FUN_0043e2c0(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[10] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[10] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[10] == '\0') {
            *(undefined1 *)(piVar5 + 10) = 1;
            *(undefined1 *)(piVar3 + 10) = 0;
            FUN_004c9300(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x29) == '\0') {
            if ((*(char *)(*piVar5 + 0x28) == '\x01') && (*(char *)(piVar5[2] + 0x28) == '\x01'))
            goto LAB_00799117;
            if (*(char *)(piVar5[2] + 0x28) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x28) = 1;
              *(undefined1 *)(piVar5 + 10) = 0;
              FUN_0043e2e0(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 10) = (char)piVar3[10];
            *(undefined1 *)(piVar3 + 10) = 1;
            *(undefined1 *)(piVar5[2] + 0x28) = 1;
            FUN_004c9300(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[10] == '\0') {
            *(undefined1 *)(piVar5 + 10) = 1;
            *(undefined1 *)(piVar3 + 10) = 0;
            FUN_0043e2e0(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x29) == '\0') {
            if ((*(char *)(piVar5[2] + 0x28) != '\x01') || (*(char *)(*piVar5 + 0x28) != '\x01')) {
              if (*(char *)(*piVar5 + 0x28) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x28) = 1;
                *(undefined1 *)(piVar5 + 10) = 0;
                FUN_004c9300(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 10) = (char)piVar3[10];
              *(undefined1 *)(piVar3 + 10) = 1;
              *(undefined1 *)(*piVar5 + 0x28) = 1;
              FUN_0043e2e0(piVar3);
              break;
            }
LAB_00799117:
            *(undefined1 *)(piVar5 + 10) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 10) = 1;
  }
  if ((uint)param_2[9] < 0x10) {
    param_2[9] = 0xf;
    param_2[8] = 0;
    *(undefined1 *)(param_2 + 4) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[4]);
  return;
}


// ==== FUN_007991c0 @ 0x007991c0 ====

void FUN_007991c0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x29) == '\0') {
    FUN_007991c0(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00799200 @ 0x00799200 ====

/* WARNING: Removing unreachable block (ram,0x0079925f) */

void FUN_00799200(undefined4 *param_1,undefined4 *param_2)

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
  if (*(char *)((int)puVar6[1] + 0x29) == '\0') {
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
LAB_00799290:
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
        if (uVar5 == 0) goto LAB_00799290;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x29) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_00798d10(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_00798b50();
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
    puVar6 = (undefined4 *)FUN_00798d10(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_00799370 @ 0x00799370 ====

void FUN_00799370(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_007991c0(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x29) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x29) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x29);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x29);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x29);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x29);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_00798ef0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00799430 @ 0x00799430 ====

void FUN_00799430(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00799370(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00799460 @ 0x00799460 ====

void FUN_00799460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa20c;
  return;
}


// ==== FUN_00799470 @ 0x00799470 ====

void FUN_00799470(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa20c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00799490 @ 0x00799490 ====

void FUN_00799490(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_007994a0 @ 0x007994a0 ====

void FUN_007994a0(undefined4 param_1)

{
  FUN_0079ada0(param_1);
  FUN_0079ada0(param_1);
  return;
}


// ==== FUN_007994c0 @ 0x007994c0 ====

void FUN_007994c0(undefined4 param_1)

{
  FUN_0079ae60(param_1);
  FUN_0079ae60(param_1);
  return;
}


// ==== FUN_007994e0 @ 0x007994e0 ====

void FUN_007994e0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998c7e;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009fa228;
  in_ECX[1] = 1000;
  FUN_0079afd0();
  local_4._0_1_ = 1;
  FUN_0079afd0();
  local_4 = CONCAT31(local_4._1_3_,2);
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  in_ECX[2] = uVar1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a990 = (undefined4 *)0x0;
    ExceptionList = pvStack_c;
    return;
  }
  DAT_00b5a990 = in_ECX;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00799580 @ 0x00799580 ====

void FUN_00799580(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00998c9b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009fa228;
  local_4 = 1;
  DAT_00b5a990 = 0;
  FUN_0079af20();
  local_4 = local_4 & 0xffffff00;
  FUN_0079af20();
  *in_ECX = &PTR_FUN_009fa20c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_007995e0 @ 0x007995e0 ====

void FUN_007995e0(void)

{
  void *local_28;
  undefined1 local_24;
  uint local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00998cad;
  pvStack_c = ExceptionList;
  local_10 = (void *)0xf;
  local_14 = 0;
  local_24 = 0;
  ExceptionList = &pvStack_c;
  FUN_00401740(s_I_packet_txt_009fa0de + 2,10);
  local_4 = 0;
  FUN_0079b070(&local_28);
  if (local_14 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_28);
  return;
}


// ==== FUN_00799660 @ 0x00799660 ====

void FUN_00799660(void)

{
  uint uVar1;
  void *_Memory;
  undefined4 uVar2;
  int in_ECX;
  void *unaff_EBX;
  void *unaff_ESI;
  undefined *puStack_e8;
  void **ppvStack_e4;
  undefined *puStack_e0;
  void **ppvStack_dc;
  undefined *puStack_d8;
  void **ppvStack_b0;
  void *pvStack_7c;
  void *pvStack_78;
  void *pvStack_74;
  void *pvStack_70;
  void *pvStack_6c;
  void *pvStack_68;
  void *pvStack_64;
  void *pvStack_60;
  uint uStack_5c;
  void *pvStack_58;
  uint uStack_54;
  void *pvStack_50;
  uint uStack_4c;
  void *pvStack_48;
  uint uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_1c;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00998d47;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  uStack_5c = uStack_5c & 0xffffff00;
  uStack_4c = 0;
  pvStack_48 = (void *)0xf;
  if (uVar1 < (uint)(*(int *)(in_ECX + 4) + *(int *)(in_ECX + 8))) {
    FUN_00401740();
    uStack_4 = 0;
    ppvStack_b0 = (void **)((uint)ppvStack_b0 & 0xffffff00);
    FUN_00401740();
    FUN_00404230();
    uStack_4 = CONCAT31(uStack_4._1_3_,1);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_34) {
      _free(pvStack_48);
      return;
    }
    uStack_34 = 0xf;
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    if (0xf < pvStack_50) {
      _free(pvStack_64);
      return;
    }
  }
  else {
    FUN_00401740();
    uStack_4 = 2;
    FUN_00401740();
    _Memory = (void *)FUN_00404230();
    uStack_4 = CONCAT31(uStack_4._1_3_,3);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_34) {
      _free(pvStack_48);
      return;
    }
    uStack_34 = 0xf;
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    pvStack_c = (void *)0xffffffff;
    if (0xf < pvStack_50) {
      _free(pvStack_64);
      return;
    }
    pvStack_50 = (void *)0xf;
    uStack_54 = 0;
    pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
    FUN_00401740();
    pvStack_c = (void *)0x4;
    FUN_00401740();
    FUN_00404230();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_3c) {
      _free(pvStack_50);
      return;
    }
    uStack_3c = 0xf;
    uStack_40 = 0;
    pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
    pvStack_14 = (void *)0xffffffff;
    if (0xf < pvStack_58) {
      _free(pvStack_6c);
      return;
    }
    pvStack_58 = (void *)0xf;
    uStack_5c = 0;
    pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
    FUN_00401740();
    pvStack_14 = (void *)0x6;
    FUN_00401740();
    uVar1 = FUN_00404230();
    pvStack_14 = (void *)CONCAT31(pvStack_14._1_3_,7);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_44) {
      ppvStack_b0 = (void **)0x79991b;
      _free(pvStack_58);
      return;
    }
    uStack_44 = 0xf;
    pvStack_48 = (void *)0x0;
    pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
    uStack_1c = 0xffffffff;
    if ((void *)0xf < pvStack_60) {
      ppvStack_b0 = (void **)0x799945;
      _free(pvStack_74);
      return;
    }
    ppvStack_b0 = (void **)s__PACKET__Receive_Size_009fa158;
    pvStack_60 = (void *)0xf;
    pvStack_64 = (void *)0x0;
    pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
    FUN_00401740();
    ppvStack_b0 = (void **)0xf;
    uStack_1c = 8;
    FUN_00401740();
    FUN_00404230();
    ppvStack_b0 = &pvStack_78;
    uStack_1c = CONCAT31(uStack_1c._1_3_,9);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_4c) {
      _free(pvStack_60);
      return;
    }
    uStack_4c = 0xf;
    pvStack_50 = (void *)0x0;
    pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
    uStack_24 = 0xffffffff;
    if (0xf < pvStack_68) {
      _free(pvStack_7c);
      return;
    }
    FUN_0079ad00();
    pvStack_68 = (void *)0xf;
    pvStack_6c = (void *)0x0;
    FUN_00401740();
    puStack_d8 = &DAT_009fa170;
    uStack_24 = 10;
    ppvStack_dc = (void **)0x799a45;
    FUN_00401740();
    puStack_d8 = (undefined *)0x799a4f;
    FUN_00404230();
    uStack_24 = CONCAT31(uStack_24._1_3_,0xb);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
    uStack_54 = 0xf;
    pvStack_58 = (void *)0x0;
    pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
    uStack_2c = 0xffffffff;
    if (0xf < pvStack_70) {
      _free(unaff_EBX);
      return;
    }
    pvStack_70 = (void *)0xf;
    pvStack_74 = (void *)0x0;
    FUN_00401740();
    ppvStack_dc = (void **)0x2;
    puStack_e0 = &DAT_009fa190;
    uStack_2c = 0xc;
    ppvStack_e4 = (void **)0x799af1;
    FUN_00401740();
    ppvStack_dc = &pvStack_6c;
    puStack_e0 = (undefined *)0x799afb;
    FUN_00404230();
    uStack_2c = CONCAT31(uStack_2c._1_3_,0xd);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < uStack_5c) {
      _free(pvStack_70);
      return;
    }
    uStack_5c = 0xf;
    pvStack_60 = (void *)0x0;
    pvStack_70 = (void *)((uint)pvStack_70 & 0xffffff00);
    uStack_34 = 0xffffffff;
    if ((void *)0xf < pvStack_78) {
      _free(unaff_ESI);
      return;
    }
    pvStack_78 = (void *)0xf;
    FUN_00401740();
    ppvStack_b0 = &puStack_e0;
    ppvStack_e4 = (void **)0x2;
    puStack_e8 = &DAT_009fa1b0;
    uStack_34 = 0xe;
    ppvStack_dc = (void **)((uint)ppvStack_dc & 0xffffff00);
    FUN_00401740();
    ppvStack_e4 = &pvStack_74;
    puStack_e8 = (undefined *)0x799ba7;
    FUN_00404230();
    uStack_34 = CONCAT31(uStack_34._1_3_,0xf);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < pvStack_64) {
      _free(pvStack_78);
      return;
    }
    pvStack_64 = (void *)0xf;
    pvStack_68 = (void *)0x0;
    pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
    uStack_3c = 0xffffffff;
    if ((undefined1 *)0xf < &ppvStack_b0) {
      _free(_Memory);
      return;
    }
    ppvStack_b0 = (void **)((uint)ppvStack_b0 & 0xffffff00);
    FUN_00401740();
    uStack_3c = 0x10;
    ppvStack_e4 = (void **)((uint)ppvStack_e4 & 0xffffff00);
    FUN_00401740(&DAT_009fa1d4,2);
    FUN_00404230(&pvStack_60);
    uStack_3c = CONCAT31(uStack_3c._1_3_,0x11);
    (**(code **)(*DAT_00b5a688 + 8))();
    if (0xf < pvStack_50) {
      puStack_d8 = (undefined *)0x799c81;
      _free(pvStack_64);
      return;
    }
    pvStack_50 = (void *)0xf;
    uStack_54 = 0;
    pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
    uStack_44 = 0xffffffff;
    if (0xf < uVar1) {
      puStack_d8 = (undefined *)0x799cae;
      _free(&puStack_e8);
      return;
    }
    uVar2 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    *(undefined4 *)(in_ECX + 8) = uVar2;
  }
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00799cf0 @ 0x00799cf0 ====

void FUN_00799cf0(byte param_1)

{
  void *in_ECX;
  
  FUN_00799580();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00799d10 @ 0x00799d10 ====

void FUN_00799d10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa24c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00799d30 @ 0x00799d30 ====

void FUN_00799d30(byte param_1,char param_2)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = 1 << (param_1 & 0x1f);
  if (param_2 == '\0') {
    *(uint *)(in_ECX + 4) = *(uint *)(in_ECX + 4) & ~uVar1;
    return;
  }
  *(uint *)(in_ECX + 4) = *(uint *)(in_ECX + 4) | uVar1;
  return;
}


// ==== FUN_00799d90 @ 0x00799d90 ====

void FUN_00799d90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa25c;
  in_ECX[1] = 0xffffffff;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b1bc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b1bc = in_ECX;
  return;
}


// ==== FUN_00799de0 @ 0x00799de0 ====

void FUN_00799de0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b1bc = 0;
  *in_ECX = &PTR_FUN_009fa24c;
  return;
}


// ==== FUN_00799e30 @ 0x00799e30 ====

void FUN_00799e30(int param_1,int param_2)

{
  LPCSTR lpOutputString;
  int in_ECX;
  
  if (param_1 != 0) {
    if (param_1 == 1) {
      if ((DAT_00b5a72c != (int *)0x0) && ((*(byte *)(in_ECX + 4) & 2) != 0)) {
        (**(code **)(*DAT_00b5a72c + 8))(param_2);
      }
    }
    else if ((param_1 == 2) && ((*(byte *)(in_ECX + 4) & 4) != 0)) {
      if (*(uint *)(param_2 + 0x18) < 0x10) {
        lpOutputString = (LPCSTR)(param_2 + 4);
      }
      else {
        lpOutputString = *(LPCSTR *)(param_2 + 4);
      }
      OutputDebugStringA(lpOutputString);
      OutputDebugStringA(&DAT_009fa244);
      return;
    }
  }
  return;
}


// ==== FUN_00799e90 @ 0x00799e90 ====

void FUN_00799e90(byte param_1)

{
  void *in_ECX;
  
  FUN_00799de0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00799eb0 @ 0x00799eb0 ====

void FUN_00799eb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa328;
  return;
}


// ==== FUN_00799ec0 @ 0x00799ec0 ====

void FUN_00799ec0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa328;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00799ee0 @ 0x00799ee0 ====

void FUN_00799ee0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00799ee5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  return;
}


// ==== FUN_00799ef0 @ 0x00799ef0 ====

undefined4 FUN_00799ef0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00799f00 @ 0x00799f00 ====

void FUN_00799f00(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00998d7e;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009fa33c;
  pvVar1 = operator_new(0x14);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0079d740();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0079cab0();
  }
  in_ECX[2] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a72c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a72c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00799fc0 @ 0x00799fc0 ====

void FUN_00799fc0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998d90;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009fa33c;
  DAT_00b5a72c = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009fa328;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0079a030 @ 0x0079a030 ====

/* WARNING: Removing unreachable block (ram,0x0079a0ca) */
/* WARNING: Removing unreachable block (ram,0x0079a100) */
/* WARNING: Removing unreachable block (ram,0x0079a10d) */
/* WARNING: Removing unreachable block (ram,0x0079a115) */
/* WARNING: Removing unreachable block (ram,0x0079a13d) */
/* WARNING: Removing unreachable block (ram,0x0079a20d) */
/* WARNING: Removing unreachable block (ram,0x0079a219) */
/* WARNING: Removing unreachable block (ram,0x0079a19b) */
/* WARNING: Removing unreachable block (ram,0x0079a1db) */
/* WARNING: Removing unreachable block (ram,0x0079a1e8) */
/* WARNING: Removing unreachable block (ram,0x0079a1f7) */
/* WARNING: Removing unreachable block (ram,0x0079a204) */
/* WARNING: Removing unreachable block (ram,0x0079a134) */
/* WARNING: Removing unreachable block (ram,0x0079a086) */
/* WARNING: Removing unreachable block (ram,0x0079a0a7) */
/* WARNING: Removing unreachable block (ram,0x0079a21d) */
/* WARNING: Removing unreachable block (ram,0x0079a234) */
/* WARNING: Removing unreachable block (ram,0x0079a240) */
/* WARNING: Removing unreachable block (ram,0x0079a244) */
/* WARNING: Removing unreachable block (ram,0x0079a2c5) */
/* WARNING: Removing unreachable block (ram,0x0079a322) */
/* WARNING: Removing unreachable block (ram,0x0079a32f) */
/* WARNING: Removing unreachable block (ram,0x0079a349) */
/* WARNING: Removing unreachable block (ram,0x0079a356) */
/* WARNING: Removing unreachable block (ram,0x0079a365) */
/* WARNING: Removing unreachable block (ram,0x0079a372) */
/* WARNING: Removing unreachable block (ram,0x0079a376) */
/* WARNING: Removing unreachable block (ram,0x0079a248) */
/* WARNING: Removing unreachable block (ram,0x0079a25d) */
/* WARNING: Removing unreachable block (ram,0x0079a265) */
/* WARNING: Removing unreachable block (ram,0x0079a29b) */
/* WARNING: Removing unreachable block (ram,0x0079a280) */
/* WARNING: Removing unreachable block (ram,0x0079a29d) */

void FUN_0079a030(void)

{
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998de4;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00405670();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0079a3b0 @ 0x0079a3b0 ====

void FUN_0079a3b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00799fc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079a3d0 @ 0x0079a3d0 ====

void FUN_0079a3d0(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x14))();
  iVar1 = (**(code **)(*in_ECX + 0x18))();
  in_ECX[0x1c] = iVar1;
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  in_ECX[0x1d] = iVar1;
  in_ECX[0x1e] = *param_1;
  in_ECX[0x1f] = param_1[1];
  in_ECX[0x20] = param_1[2];
  in_ECX[0x21] = param_1[3];
  in_ECX[0x22] = *param_1;
  in_ECX[0x23] = param_1[1];
  in_ECX[0x24] = param_1[2];
  in_ECX[0x25] = param_1[3];
  return;
}


// ==== FUN_0079a430 @ 0x0079a430 ====

void FUN_0079a430(undefined4 *param_1)

{
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x90) != param_1[2]) || (*(int *)(in_ECX + 0x94) != param_1[3])) ||
     (*(int *)(in_ECX + 0x8c) != param_1[1])) {
    *(undefined4 *)(in_ECX + 0x88) = *param_1;
    *(undefined4 *)(in_ECX + 0x8c) = param_1[1];
    *(undefined4 *)(in_ECX + 0x90) = param_1[2];
    *(undefined4 *)(in_ECX + 0x94) = param_1[3];
  }
  return;
}


// ==== FUN_0079a480 @ 0x0079a480 ====

int FUN_0079a480(void)

{
  int in_ECX;
  
  return in_ECX + 0x78;
}


// ==== FUN_0079a490 @ 0x0079a490 ====

int FUN_0079a490(void)

{
  int in_ECX;
  
  return in_ECX + 0x88;
}


// ==== FUN_0079a4a0 @ 0x0079a4a0 ====

void FUN_0079a4a0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar1 = FUN_0079ac20();
  iVar2 = (*(int *)(in_ECX + 0x70) - *(int *)(in_ECX + 0x74)) + iVar1;
  *(int *)(in_ECX + 0x9c) = iVar1;
  *(int *)(in_ECX + 0x98) = iVar2;
  *(int *)(in_ECX + 0xa0) = (*(int *)(in_ECX + 0x7c) - *(int *)(in_ECX + 0x80)) + iVar2;
  if (1000 < (uint)(iVar1 - *(int *)(in_ECX + 0xa4))) {
    FUN_0079ac90();
    *(undefined4 *)(in_ECX + 0xa4) = *(undefined4 *)(in_ECX + 0x9c);
  }
  return;
}


// ==== FUN_0079a500 @ 0x0079a500 ====

undefined4 FUN_0079a500(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x98);
}


// ==== FUN_0079a510 @ 0x0079a510 ====

undefined4 FUN_0079a510(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x9c);
}


// ==== FUN_0079a520 @ 0x0079a520 ====

undefined4 FUN_0079a520(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0);
}


// ==== FUN_0079a530 @ 0x0079a530 ====

void FUN_0079a530(void)

{
  FUN_0079ac20();
  return;
}


// ==== FUN_0079a540 @ 0x0079a540 ====

void FUN_0079a540(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998df8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009fa364;
  local_4 = 0;
  DAT_00b5a6ac = 0;
  FUN_0079abb0();
  *in_ECX = &PTR_FUN_009f9e1c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0079a590 @ 0x0079a590 ====

void FUN_0079a590(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998e1d;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009fa364;
  FUN_0079ab10();
  local_4._0_1_ = 1;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a6ac = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a6ac = in_ECX;
  }
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x22] = in_ECX[0x1e];
  in_ECX[0x23] = in_ECX[0x1f];
  in_ECX[0x24] = in_ECX[0x20];
  in_ECX[0x25] = in_ECX[0x21];
  in_ECX[0x1c] = 0;
  uVar1 = FUN_0079ac20();
  in_ECX[0x1d] = uVar1;
  uVar1 = FUN_0079ac20();
  in_ECX[0x29] = uVar1;
  FUN_0079a4a0();
  FUN_00401740(s_Start_Tick__u_009fa350,0xd);
  uVar1 = FUN_00797530(local_28);
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00796dd0(uVar1);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_0079a6a0 @ 0x0079a6a0 ====

void FUN_0079a6a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0079a540();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079a6c0 @ 0x0079a6c0 ====

void FUN_0079a6c0(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0079a6e0 @ 0x0079a6e0 ====

void FUN_0079a6e0(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
  if (*(uint *)(in_ECX + 8) <= uVar1) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 8))();
    *(int *)(in_ECX + 8) = iVar2 + 1;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  return;
}


// ==== FUN_0079a710 @ 0x0079a710 ====

void FUN_0079a710(void)

{
  void *pvVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998e38;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009fa3d8;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a6a8 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5a6a8 = in_ECX;
  }
  pvVar1 = operator_new(0x509118);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0079a870();
  }
  in_ECX[1] = piVar2;
  uVar3 = (**(code **)(*piVar2 + 8))();
  in_ECX[2] = uVar3;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0079a7a0 @ 0x0079a7a0 ====

void FUN_0079a7a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00998e4a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009fa3d8;
  DAT_00b5a6a8 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009fa390;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0079a800 @ 0x0079a800 ====

void FUN_0079a800(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa3a0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079a820 @ 0x0079a820 ====

void FUN_0079a820(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa3b8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079a840 @ 0x0079a840 ====

void FUN_0079a840(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa390;
  return;
}


// ==== FUN_0079a850 @ 0x0079a850 ====

void FUN_0079a850(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa390;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079a870 @ 0x0079a870 ====

void FUN_0079a870(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009fa3c0;
  in_ECX[1] = &PTR_FUN_009fa3b8;
  in_ECX[0x142442] = 0;
  in_ECX[0x142442] = in_ECX[0x142442] + 10000;
  in_ECX[0x142445] = in_ECX + 2;
  in_ECX[0x142443] = 0;
  in_ECX[0x142444] = 0;
  iVar2 = 9999;
  puVar1 = in_ECX;
  do {
    puVar1[0x83] = puVar1 + 0x86;
    puVar1[0x84] = 0;
    puVar1[0x85] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x84;
  } while (iVar2 != 0);
  in_ECX[0x14243f] = 0;
  in_ECX[0x142440] = 0;
  in_ECX[0x142441] = 0;
  return;
}


// ==== FUN_0079a8e0 @ 0x0079a8e0 ====

undefined4 FUN_0079a8e0(void)

{
  return 10000;
}


// ==== FUN_0079a8f0 @ 0x0079a8f0 ====

undefined4 FUN_0079a8f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x50910c);
}


// ==== FUN_0079a900 @ 0x0079a900 ====

void FUN_0079a900(byte param_1)

{
  void *in_ECX;
  
  FUN_0079a920();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079a920 @ 0x0079a920 ====

void FUN_0079a920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa3c0;
  if ((void *)in_ECX[0x142444] == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009fa3b8;
    *in_ECX = &PTR_FUN_009fa3a0;
    return;
  }
  _free((void *)in_ECX[0x142444]);
  return;
}


// ==== FUN_0079a960 @ 0x0079a960 ====

void * FUN_0079a960(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00998e6b;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x509114);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x50910c) = *(int *)(in_ECX + 0x50910c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x210);
      *(undefined4 *)((int)param_2 + 0x208) = *(undefined4 *)(in_ECX + 0x509110);
      *(void **)(in_ECX + 0x509110) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x509114) = *(undefined4 *)((int)param_2 + 0x204);
    }
    *(undefined4 *)((int)param_2 + 0x204) = 0;
    *(int *)((int)param_2 + 0x20c) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x20c) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009fa3e8,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x20c) = *(int *)((int)param_2 + 0x20c) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0079aa60 @ 0x0079aa60 ====

undefined4 FUN_0079aa60(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x20c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_module__009fa3e8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x20c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x20c);
    }
    *(undefined4 *)(param_2 + 0x204) = *(undefined4 *)(in_ECX + 0x509114);
    *(int *)(in_ECX + 0x50910c) = *(int *)(in_ECX + 0x50910c) + -1;
    *(int *)(in_ECX + 0x509114) = param_2;
  }
  return 0;
}


// ==== FUN_0079aaf0 @ 0x0079aaf0 ====

void FUN_0079aaf0(byte param_1)

{
  void *in_ECX;
  
  FUN_0079a7a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079ab10 @ 0x0079ab10 ====

void FUN_0079ab10(void)

{
  undefined4 uVar1;
  DWORD DVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00998eac;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009fa448;
  FUN_0079db20();
  local_4 = 0;
  FUN_0079da40();
  local_4._0_1_ = 1;
  FUN_0079d9a0();
  local_4._0_1_ = 2;
  FUN_0079d870();
  local_4 = CONCAT31(local_4._1_3_,3);
  uVar1 = FUN_0079da90();
  in_ECX[0x13] = uVar1;
  DVar2 = timeGetTime();
  in_ECX[0x14] = DVar2;
  uVar1 = FUN_0079d930();
  in_ECX[0x15] = uVar1;
  in_ECX[0x12] = 2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0079abb0 @ 0x0079abb0 ====

void FUN_0079abb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00998ed7;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009fa448;
  local_4 = 2;
  FUN_0079d8b0();
  local_4._0_1_ = 1;
  FUN_0079d920();
  local_4 = (uint)local_4._1_3_ << 8;
  FUN_0079da00();
  local_4 = 0xffffffff;
  FUN_0079da80();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0079ac20 @ 0x0079ac20 ====

int FUN_0079ac20(void)

{
  int iVar1;
  DWORD DVar2;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) == 0) {
    iVar1 = FUN_0079da90();
    return iVar1 - *(int *)(in_ECX + 0x4c + *(int *)(in_ECX + 0x48) * 4);
  }
  if (*(int *)(in_ECX + 0x48) == 1) {
    DVar2 = timeGetTime();
    return DVar2 - *(int *)(in_ECX + 0x4c + *(int *)(in_ECX + 0x48) * 4);
  }
  iVar1 = FUN_0079d930();
  return iVar1 - *(int *)(in_ECX + 0x4c + *(int *)(in_ECX + 0x48) * 4);
}


// ==== FUN_0079ac90 @ 0x0079ac90 ====

void FUN_0079ac90(void)

{
  FUN_0079d8c0();
  FUN_0079db00();
  FUN_0079da20();
  FUN_0079d980();
  return;
}


// ==== FUN_0079acd0 @ 0x0079acd0 ====

void FUN_0079acd0(byte param_1)

{
  void *in_ECX;
  
  FUN_0079abb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079ad00 @ 0x0079ad00 ====

void FUN_0079ad00(void)

{
  uint in_ECX;
  uint local_4;
  
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  local_4 = in_ECX;
  if (*(int *)(in_ECX + 0x24) != 0) {
    local_4 = in_ECX & 0xffffff00;
    FUN_004c3cc0(**(undefined4 **)(in_ECX + 0x20),*(undefined4 **)(in_ECX + 0x20),local_4);
    FUN_0079bb20(*(undefined4 *)(*(int *)(in_ECX + 0x20) + 4));
    *(int *)(*(int *)(in_ECX + 0x20) + 4) = *(int *)(in_ECX + 0x20);
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(in_ECX + 0x20);
    *(int *)(*(int *)(in_ECX + 0x20) + 8) = *(int *)(in_ECX + 0x20);
  }
  if (*(int *)(in_ECX + 0x30) != 0) {
    local_4 = local_4 & 0xffffff00;
    FUN_004c3cc0(**(undefined4 **)(in_ECX + 0x2c),*(undefined4 **)(in_ECX + 0x2c),local_4);
    FUN_0079bb20(*(undefined4 *)(*(int *)(in_ECX + 0x2c) + 4));
    *(int *)(*(int *)(in_ECX + 0x2c) + 4) = *(int *)(in_ECX + 0x2c);
    *(undefined4 *)(in_ECX + 0x30) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
    *(int *)(*(int *)(in_ECX + 0x2c) + 8) = *(int *)(in_ECX + 0x2c);
  }
  return;
}


// ==== FUN_0079ada0 @ 0x0079ada0 ====

void FUN_0079ada0(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int local_10;
  int *local_c;
  undefined1 local_8 [8];
  
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + 1;
  uVar1 = FUN_00424520();
  *(int *)(in_ECX + 0xc) = *(int *)(in_ECX + 0xc) + (uVar1 & 0xffff);
  param_1 = FUN_00424500();
  FUN_0079bba0(&local_10,&param_1);
  if (local_10 != *(int *)(in_ECX + 0x20)) {
    iVar3 = *(int *)(local_10 + 0x10);
    piVar2 = (int *)(iVar3 + 4);
    *piVar2 = *piVar2 + 1;
    uVar1 = FUN_00424520();
    piVar2 = (int *)(iVar3 + 8);
    *piVar2 = *piVar2 + (uVar1 & 0xffff);
    return;
  }
  piVar2 = operator_new(0xc);
  local_c = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    *piVar2 = 0;
    piVar2[1] = 0;
    piVar2[2] = 0;
    local_c = piVar2;
  }
  iVar3 = FUN_00424500();
  *local_c = iVar3;
  local_c[1] = 1;
  uVar1 = FUN_00424520();
  local_10 = *local_c;
  local_c[2] = uVar1 & 0xffff;
  FUN_0079c0a0(local_8,&local_10);
  return;
}


// ==== FUN_0079ae60 @ 0x0079ae60 ====

void FUN_0079ae60(undefined4 param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  int local_10;
  int *local_c;
  undefined1 local_8 [8];
  
  *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + 1;
  uVar1 = FUN_00424520();
  *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + (uVar1 & 0xffff);
  param_1 = FUN_00424500();
  FUN_0079bba0(&local_10,&param_1);
  if (local_10 != *(int *)(in_ECX + 0x2c)) {
    iVar3 = *(int *)(local_10 + 0x10);
    piVar2 = (int *)(iVar3 + 4);
    *piVar2 = *piVar2 + 1;
    uVar1 = FUN_00424520();
    piVar2 = (int *)(iVar3 + 8);
    *piVar2 = *piVar2 + (uVar1 & 0xffff);
    return;
  }
  piVar2 = operator_new(0xc);
  local_c = (int *)0x0;
  if (piVar2 != (int *)0x0) {
    *piVar2 = 0;
    piVar2[1] = 0;
    piVar2[2] = 0;
    local_c = piVar2;
  }
  iVar3 = FUN_00424500();
  *local_c = iVar3;
  local_c[1] = 1;
  uVar1 = FUN_00424520();
  local_10 = *local_c;
  local_c[2] = uVar1 & 0xffff;
  FUN_0079c0a0(local_8,&local_10);
  return;
}


// ==== FUN_0079af20 @ 0x0079af20 ====

void FUN_0079af20(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00998f26;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009fa65c;
  local_4 = 1;
  FUN_0079ad00();
  local_4 = local_4 & 0xffffff00;
  FUN_0079c1d0(local_10,*(undefined4 *)in_ECX[0xb],(undefined4 *)in_ECX[0xb]);
  _free((void *)in_ECX[0xb]);
  return;
}


// ==== FUN_0079afd0 @ 0x0079afd0 ====

void FUN_0079afd0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00998f3b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009fa65c;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  iVar1 = FUN_0058d7c0();
  in_ECX[8] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[8] + 4) = in_ECX[8];
  *(undefined4 *)in_ECX[8] = in_ECX[8];
  *(undefined4 *)(in_ECX[8] + 8) = in_ECX[8];
  in_ECX[9] = 0;
  local_4 = 0;
  iVar1 = FUN_0058d7c0();
  in_ECX[0xb] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0xb] + 4) = in_ECX[0xb];
  *(undefined4 *)in_ECX[0xb] = in_ECX[0xb];
  *(undefined4 *)(in_ECX[0xb] + 8) = in_ECX[0xb];
  in_ECX[0xc] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0079b070 @ 0x0079b070 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079b070(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *piVar8;
  int *piVar9;
  int *piVar10;
  int in_ECX;
  int *piVar11;
  char *pcStack_10c;
  char *local_108;
  undefined1 *puStack_104;
  undefined1 local_100 [4];
  uint local_fc;
  int **local_f8;
  undefined4 local_f4;
  int *local_d4 [2];
  undefined1 *local_cc;
  int local_c8;
  int local_c4;
  undefined1 local_c0 [4];
  void *local_bc;
  undefined4 local_ac;
  undefined4 *local_a8;
  int *local_a0;
  undefined4 local_9c;
  undefined **local_98;
  undefined4 local_88;
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
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099900c;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_c4 = in_ECX;
  FUN_00404890();
  local_4 = 0;
  local_f4 = 0x79b0b6;
  FUN_004045b0();
  local_4._0_1_ = 2;
  if (0xf < local_64) {
    _free(local_78);
    return;
  }
  local_64 = 0xf;
  local_68 = 0;
  local_78 = (void *)((uint)local_78 & 0xffffff00);
  local_f4 = 0x79b110;
  FUN_00405bd0();
  local_98 = &PTR_FUN_0099d55c;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_d4[0] = (int *)&puStack_104;
  local_108 = (char *)0x12;
  pcStack_10c = s_I_Send_Count____u_009fa4c6 + 2;
  local_4._0_1_ = 5;
  local_100[0] = 0;
  FUN_00401740();
  local_108 = local_c0;
  pcStack_10c = (char *)0x79b15b;
  FUN_00797530();
  local_4._0_1_ = 6;
  FUN_00411630();
  local_4._0_1_ = 5;
  if ((undefined4 *)0xf < local_a8) {
    _free(local_bc);
    return;
  }
  local_d4[0] = (int *)&puStack_104;
  local_108 = (char *)0x12;
  pcStack_10c = s_Send_Size____u_009fa4dc;
  local_100[0] = 0;
  FUN_00401740();
  local_108 = local_c0;
  pcStack_10c = (char *)0x79b1b7;
  FUN_00797530();
  local_4._0_1_ = 7;
  FUN_00411630();
  local_4._0_1_ = 5;
  if ((undefined4 *)0xf < local_a8) {
    _free(local_bc);
    return;
  }
  local_d4[0] = (int *)&puStack_104;
  local_108 = (char *)0x12;
  pcStack_10c = s_Receive_Count____u_009fa4f0;
  local_100[0] = 0;
  FUN_00401740();
  local_108 = local_c0;
  pcStack_10c = (char *)0x79b213;
  FUN_00797530();
  local_4._0_1_ = 8;
  FUN_00411630();
  local_4._0_1_ = 5;
  if ((undefined4 *)0xf < local_a8) {
    _free(local_bc);
    return;
  }
  local_d4[0] = (int *)&puStack_104;
  local_108 = (char *)0x12;
  pcStack_10c = s_Receive_Size____u_009fa504;
  local_100[0] = 0;
  FUN_00401740();
  local_108 = local_c0;
  pcStack_10c = (char *)0x79b26f;
  FUN_00797530();
  local_4._0_1_ = 9;
  FUN_00411630();
  local_4._0_1_ = 5;
  if ((undefined4 *)0xf < local_a8) {
    _free(local_bc);
    return;
  }
  local_d4[0] = (int *)local_100;
  puStack_104 = (undefined1 *)0x26;
  local_108 = s__________________________________009fa518;
  local_fc = local_fc & 0xffffff00;
  pcStack_10c = (char *)0x79b2bd;
  FUN_00401740();
  puStack_104 = local_c0;
  local_108 = (char *)0x79b2c7;
  FUN_00797530();
  local_4._0_1_ = 10;
  FUN_00411630();
  local_4._0_1_ = 5;
  if ((undefined4 *)0xf < local_a8) {
    _free(local_bc);
    return;
  }
  local_a0 = (int *)FUN_0058d7c0();
  *(undefined1 *)((int)local_a0 + 0x15) = 1;
  local_a0[1] = (int)local_a0;
  *local_a0 = (int)local_a0;
  local_a0[2] = (int)local_a0;
  local_9c = 0;
  local_d4[0] = (int *)local_100;
  puStack_104 = (undefined1 *)0x26;
  local_108 = s_________________Send_____________009fa540;
  local_4._0_1_ = 0xb;
  local_fc = local_fc & 0xffffff00;
  pcStack_10c = (char *)0x79b346;
  FUN_00401740();
  puStack_104 = local_c0;
  local_108 = (char *)0x79b350;
  FUN_00797530();
  local_4._0_1_ = 0xc;
  FUN_00411630();
  local_4._0_1_ = 0xb;
  if ((undefined4 *)0xf < local_a8) {
    _free(local_bc);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x20);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    local_c8 = puVar3[4];
    local_cc = *(undefined1 **)(local_c8 + 4);
    FUN_0079c160();
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar7 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar7, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar7 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  piVar11 = (int *)*local_a0;
  piVar10 = local_a0;
  while (piVar10 != piVar11) {
    if (*(char *)((int)piVar10 + 0x15) == '\0') {
      if (*(char *)(*piVar10 + 0x15) == '\0') {
        iVar5 = *(int *)(*piVar10 + 8);
        cVar1 = *(char *)(iVar5 + 0x15);
        while (cVar1 == '\0') {
          iVar5 = *(int *)(iVar5 + 8);
          cVar1 = *(char *)(iVar5 + 0x15);
        }
      }
      else {
        cVar1 = *(char *)(piVar10[1] + 0x15);
        piVar8 = (int *)piVar10[1];
        piVar9 = piVar10;
        while ((piVar6 = piVar8, cVar1 == '\0' && (piVar9 == (int *)*piVar6))) {
          cVar1 = *(char *)(piVar6[1] + 0x15);
          piVar8 = (int *)piVar6[1];
          piVar9 = piVar6;
        }
      }
    }
    local_d4[0] = (int *)&puStack_104;
    local_108 = (char *)0x10;
    pcStack_10c = s_Packet_Code____u_009fa568;
    local_100[0] = 0;
    FUN_00401740();
    local_108 = local_7c;
    pcStack_10c = (char *)0x79b47e;
    FUN_00797530();
    local_4._0_1_ = 0xd;
    FUN_00411630();
    local_4._0_1_ = 0xb;
    if (0xf < local_64) {
      _free(local_78);
      return;
    }
    local_64 = 0xf;
    local_68 = 0;
    local_78 = (void *)((uint)local_78 & 0xffffff00);
    local_d4[0] = (int *)&pcStack_10c;
    local_f4 = 0xf;
    local_f8 = (int **)0x0;
    local_108 = (char *)((uint)local_108 & 0xffffff00);
    FUN_00401740(s_Send_Count____u__f____009fa57c,0x16);
    FUN_00797530(local_60);
    local_4._0_1_ = 0xe;
    FUN_00411630();
    local_4._0_1_ = 0xb;
    if (0xf < local_48) {
      _free(local_5c);
      return;
    }
    local_48 = 0xf;
    local_4c = 0;
    local_5c = (void *)((uint)local_5c & 0xffffff00);
    local_d4[0] = (int *)&pcStack_10c;
    local_f4 = 0xf;
    local_f8 = (int **)0x0;
    local_108 = (char *)((uint)local_108 & 0xffffff00);
    FUN_00401740(s_Send_Size____u__f____009fa594,0x16);
    FUN_00797530(local_c0);
    local_4._0_1_ = 0xf;
    FUN_00411630();
    local_4._0_1_ = 0xb;
    if ((undefined4 *)0xf < local_a8) {
      _free(local_bc);
      return;
    }
    local_a8 = (undefined4 *)0xf;
    local_ac = 0;
    local_bc = (void *)((uint)local_bc & 0xffffff00);
    if (*(char *)((int)piVar10 + 0x15) == '\0') {
      piVar9 = (int *)*piVar10;
      if (*(char *)((int)piVar9 + 0x15) == '\0') {
        cVar1 = *(char *)(piVar9[2] + 0x15);
        piVar10 = piVar9;
        piVar9 = (int *)piVar9[2];
        while (cVar1 == '\0') {
          cVar1 = *(char *)(piVar9[2] + 0x15);
          piVar10 = piVar9;
          piVar9 = (int *)piVar9[2];
        }
      }
      else {
        piVar9 = (int *)piVar10[1];
        if (*(char *)(piVar10[1] + 0x15) == '\0') {
          do {
            piVar8 = piVar9;
            piVar9 = piVar8;
            if (piVar10 != (int *)*piVar8) break;
            piVar9 = (int *)piVar8[1];
            piVar10 = piVar8;
          } while (*(char *)((int)piVar9 + 0x15) == '\0');
          if (*(char *)((int)piVar9 + 0x15) == '\0') {
            piVar10 = piVar9;
          }
        }
      }
    }
    else {
      piVar10 = (int *)piVar10[2];
    }
  }
  local_d4[0] = (int *)local_100;
  puStack_104 = (undefined1 *)0x26;
  local_108 = s__________________________________009fa5ac;
  local_fc = local_fc & 0xffffff00;
  pcStack_10c = (char *)0x79b690;
  FUN_00401740();
  puStack_104 = local_c0;
  local_108 = (char *)0x79b69a;
  FUN_00797530();
  local_4._0_1_ = 0x10;
  FUN_00411630();
  local_4._0_1_ = 0xb;
  if ((undefined4 *)0xf < local_a8) {
    _free(local_bc);
    return;
  }
  local_d4[0] = (int *)local_100;
  puStack_104 = (undefined1 *)0x26;
  local_108 = s_________________Receive__________009fa5d4;
  local_fc = local_fc & 0xffffff00;
  pcStack_10c = (char *)0x79b6ed;
  FUN_00401740();
  puStack_104 = local_c0;
  local_108 = (char *)0x79b6f7;
  FUN_00797530();
  local_4._0_1_ = 0x11;
  FUN_00411630();
  local_4._0_1_ = 0xb;
  if ((undefined4 *)0xf < local_a8) {
    _free(local_bc);
    return;
  }
  puVar2 = *(undefined4 **)(local_c4 + 0x2c);
  puVar3 = (undefined4 *)*puVar2;
  piVar11 = local_a0;
  while (local_a0 = piVar11, puVar3 != puVar2) {
    local_c8 = puVar3[4];
    local_cc = *(undefined1 **)(local_c8 + 4);
    FUN_0079c160();
    piVar11 = local_a0;
    if (*(char *)((int)puVar3 + 0x15) == '\0') {
      puVar4 = (undefined4 *)puVar3[2];
      if (*(char *)((int)puVar4 + 0x15) == '\0') {
        cVar1 = *(char *)((int)*puVar4 + 0x15);
        puVar3 = puVar4;
        puVar4 = (undefined4 *)*puVar4;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar4 + 0x15);
          puVar3 = puVar4;
          puVar4 = (undefined4 *)*puVar4;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar3[1] + 0x15);
        puVar7 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar7, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar7 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  local_d4[0] = (int *)*piVar11;
  if (piVar11 != local_d4[0]) {
    do {
      if (*(char *)((int)piVar11 + 0x15) == '\0') {
        if (*(char *)(*piVar11 + 0x15) == '\0') {
          iVar5 = *(int *)(*piVar11 + 8);
          cVar1 = *(char *)(iVar5 + 0x15);
          while (cVar1 == '\0') {
            iVar5 = *(int *)(iVar5 + 8);
            cVar1 = *(char *)(iVar5 + 0x15);
          }
        }
        else {
          cVar1 = *(char *)(piVar11[1] + 0x15);
          piVar9 = (int *)piVar11[1];
          piVar10 = piVar11;
          while ((piVar8 = piVar9, cVar1 == '\0' && (piVar10 == (int *)*piVar8))) {
            cVar1 = *(char *)(piVar8[1] + 0x15);
            piVar9 = (int *)piVar8[1];
            piVar10 = piVar8;
          }
        }
      }
      local_cc = (undefined1 *)&puStack_104;
      local_108 = (char *)0x10;
      pcStack_10c = s_Packet_Code____u_009fa5fc;
      local_100[0] = 0;
      FUN_00401740();
      local_108 = local_c0;
      pcStack_10c = (char *)0x79b827;
      FUN_00797530();
      local_4._0_1_ = 0x12;
      FUN_00411630();
      local_4._0_1_ = 0xb;
      if ((undefined4 *)0xf < local_a8) {
        _free(local_bc);
        return;
      }
      local_a8 = (undefined4 *)0xf;
      local_ac = 0;
      local_bc = (void *)((uint)local_bc & 0xffffff00);
      local_cc = (undefined1 *)&pcStack_10c;
      local_f4 = 0xf;
      local_f8 = (int **)0x0;
      local_108 = (char *)((uint)local_108 & 0xffffff00);
      FUN_00401740(s_Receive_Count____u__f____009fa610,0x19);
      FUN_00797530(local_60);
      local_4._0_1_ = 0x13;
      FUN_00411630();
      local_4._0_1_ = 0xb;
      if (0xf < local_48) {
        _free(local_5c);
        return;
      }
      local_48 = 0xf;
      local_4c = 0;
      local_5c = (void *)((uint)local_5c & 0xffffff00);
      local_cc = (undefined1 *)&pcStack_10c;
      local_f4 = 0xf;
      local_f8 = (int **)0x0;
      local_108 = (char *)((uint)local_108 & 0xffffff00);
      FUN_00401740(s_Receive_Size____u__f____009fa62c,0x19);
      FUN_00797530(local_7c);
      local_4._0_1_ = 0x14;
      FUN_00411630();
      local_4._0_1_ = 0xb;
      if (0xf < local_64) {
        _free(local_78);
        return;
      }
      local_64 = 0xf;
      local_68 = 0;
      local_78 = (void *)((uint)local_78 & 0xffffff00);
      if (*(char *)((int)piVar11 + 0x15) == '\0') {
        piVar10 = (int *)*piVar11;
        if (*(char *)((int)piVar10 + 0x15) == '\0') {
          cVar1 = *(char *)(piVar10[2] + 0x15);
          piVar11 = (int *)piVar10[2];
          while (cVar1 == '\0') {
            cVar1 = *(char *)(piVar11[2] + 0x15);
            piVar10 = piVar11;
            piVar11 = (int *)piVar11[2];
          }
          piVar11 = piVar10;
        }
        else {
          piVar10 = (int *)piVar11[1];
          if (*(char *)(piVar11[1] + 0x15) == '\0') {
            do {
              piVar9 = piVar10;
              piVar10 = piVar9;
              if (piVar11 != (int *)*piVar9) break;
              piVar10 = (int *)piVar9[1];
              piVar11 = piVar9;
            } while (*(char *)((int)piVar10 + 0x15) == '\0');
            if (*(char *)((int)piVar10 + 0x15) == '\0') {
              piVar11 = piVar10;
            }
          }
        }
      }
      else {
        piVar11 = (int *)piVar11[2];
      }
    } while (piVar11 != local_d4[0]);
  }
  (**(code **)(*DAT_00b5a740 + 0xc))();
  local_f4 = *local_a8;
  local_f8 = local_d4;
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);
  local_fc = 0x79ba3b;
  FUN_0079c290();
  local_f4 = 0x79ba45;
  _free(local_a8);
  return;
}


// ==== FUN_0079bb20 @ 0x0079bb20 ====

void FUN_0079bb20(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0079bb20(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0079bb60 @ 0x0079bb60 ====

void FUN_0079bb60(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_0079bb60(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0079bba0 @ 0x0079bba0 ====

void FUN_0079bba0(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x15) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if ((uint)puVar1[3] < *param_2) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x15) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_0079bc10 @ 0x0079bc10 ====

void FUN_0079bc10(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00998ef8;
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
LAB_0079bd09:
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
      if ((char)piVar6[5] == '\0') goto LAB_0079bd09;
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


// ==== FUN_0079bdf0 @ 0x0079bdf0 ====

/* WARNING: Removing unreachable block (ram,0x0079bf03) */
/* WARNING: Removing unreachable block (ram,0x0079bf13) */
/* WARNING: Removing unreachable block (ram,0x0079bf1c) */
/* WARNING: Removing unreachable block (ram,0x0079bf1f) */
/* WARNING: Removing unreachable block (ram,0x0079bf0f) */
/* WARNING: Removing unreachable block (ram,0x0079bf2d) */
/* WARNING: Removing unreachable block (ram,0x0079bf3a) */
/* WARNING: Removing unreachable block (ram,0x0079bf45) */
/* WARNING: Removing unreachable block (ram,0x0079bf41) */
/* WARNING: Removing unreachable block (ram,0x0079bf35) */
/* WARNING: Removing unreachable block (ram,0x0079bf48) */

void FUN_0079bdf0(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00998ef8;
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
            goto LAB_0079c015;
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
LAB_0079c015:
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


// ==== FUN_0079c0a0 @ 0x0079c0a0 ====

void FUN_0079c0a0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_0079bc10(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_0079bc10(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_0079c160 @ 0x0079c160 ====

void FUN_0079c160(undefined4 *param_1,uint *param_2)

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
  puVar2 = (undefined4 *)FUN_0079bc10(&param_2,bVar3,puVar2,param_2);
  *param_1 = *puVar2;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_0079c1d0 @ 0x0079c1d0 ====

void FUN_0079c1d0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0079bb20(piVar6[1]);
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
    FUN_0079bdf0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0079c290 @ 0x0079c290 ====

void FUN_0079c290(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0079bb60(piVar6[1]);
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
    FUN_0079bdf0(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0079c350 @ 0x0079c350 ====

void FUN_0079c350(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0079c1d0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0079c380 @ 0x0079c380 ====

void FUN_0079c380(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0079c290(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0079c3b0 @ 0x0079c3b0 ====

void FUN_0079c3b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0079af20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079c3d0 @ 0x0079c3d0 ====

void FUN_0079c3d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa6ac;
  return;
}


// ==== FUN_0079c3e0 @ 0x0079c3e0 ====

void FUN_0079c3e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa6ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079c400 @ 0x0079c400 ====

void FUN_0079c400(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x2d);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x2d);
  }
  return;
}


// ==== FUN_0079c420 @ 0x0079c420 ====

void FUN_0079c420(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x2d) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x2d) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x2d);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x2d);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x2d) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x2d) == '\0');
    if (*(char *)((int)piVar4 + 0x2d) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_0079c4a0 @ 0x0079c4a0 ====

undefined4 FUN_0079c4a0(int param_1)

{
  int in_ECX;
  
  FUN_0069a470(&param_1,param_1);
  if (param_1 == *(int *)(in_ECX + 8)) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x28);
}


// ==== FUN_0079c4d0 @ 0x0079c4d0 ====

void FUN_0079c4d0(int param_1)

{
  void *_Memory;
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_28 [5];
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00999068;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_0069a470(&param_1,param_1);
  if (param_1 == *(int *)(in_ECX + 8)) {
    uVar2 = FUN_004022a0(local_28,s_Not_Registered_Command___009fa68c,iVar1);
    local_4 = 0;
    (**(code **)(*DAT_00b5a72c + 8))(uVar2);
    if (0xf < uStack_14) {
      _free(local_28[0]);
      return;
    }
  }
  else {
    _Memory = *(void **)(param_1 + 0x28);
    if (_Memory != (void *)0x0) {
      if (0xf < *(uint *)((int)_Memory + 0x38)) {
        _free(*(void **)((int)_Memory + 0x24));
        return;
      }
      *(undefined4 *)((int)_Memory + 0x38) = 0xf;
      *(undefined4 *)((int)_Memory + 0x34) = 0;
      *(undefined1 *)((int)_Memory + 0x24) = 0;
      if (*(uint *)((int)_Memory + 0x18) < 0x10) {
        *(undefined4 *)((int)_Memory + 0x18) = 0xf;
        *(undefined4 *)((int)_Memory + 0x14) = 0;
        *(undefined1 *)((int)_Memory + 4) = 0;
        _free(_Memory);
        return;
      }
      _free(*(void **)((int)_Memory + 4));
      return;
    }
    FUN_0079ce60(&param_1,param_1);
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_0079c5e0 @ 0x0079c5e0 ====

void FUN_0079c5e0(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  int iVar11;
  int in_ECX;
  
  iVar8 = param_2;
  puVar2 = *(undefined4 **)(in_ECX + 8);
  uVar3 = *(uint *)(param_1 + 0x14);
  puVar4 = (undefined4 *)*puVar2;
  while (puVar4 != puVar2) {
    iVar5 = puVar4[10];
    if (uVar3 <= *(uint *)(iVar5 + 0x14)) {
      iVar11 = -1;
      if (*(int *)(param_1 + 0x14) != -1) {
        iVar11 = *(int *)(param_1 + 0x14);
      }
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        iVar10 = param_1 + 4;
      }
      else {
        iVar10 = *(int *)(param_1 + 4);
      }
      param_2 = iVar5;
      iVar11 = FUN_00403620(0,uVar3,iVar10,iVar11);
      if (iVar11 == 0) {
        iVar11 = *(int *)(iVar8 + 4);
        if ((iVar11 == 0) ||
           ((uint)(*(int *)(iVar8 + 0xc) - iVar11 >> 2) <= (uint)(*(int *)(iVar8 + 8) - iVar11 >> 2)
           )) {
          FUN_0079cc40(*(undefined4 *)(iVar8 + 8),1,&param_2);
        }
        else {
          piVar6 = *(int **)(iVar8 + 8);
          *piVar6 = iVar5;
          *(int **)(iVar8 + 8) = piVar6 + 1;
        }
      }
    }
    if (*(char *)((int)puVar4 + 0x2d) == '\0') {
      puVar7 = (undefined4 *)puVar4[2];
      if (*(char *)((int)puVar7 + 0x2d) == '\0') {
        cVar1 = *(char *)((int)*puVar7 + 0x2d);
        puVar4 = puVar7;
        puVar7 = (undefined4 *)*puVar7;
        while (cVar1 == '\0') {
          cVar1 = *(char *)((int)*puVar7 + 0x2d);
          puVar4 = puVar7;
          puVar7 = (undefined4 *)*puVar7;
        }
      }
      else {
        cVar1 = *(char *)((int)puVar4[1] + 0x2d);
        puVar9 = (undefined4 *)puVar4[1];
        puVar7 = puVar4;
        while ((puVar4 = puVar9, cVar1 == '\0' && (puVar7 == (undefined4 *)puVar4[2]))) {
          cVar1 = *(char *)((int)puVar4[1] + 0x2d);
          puVar9 = (undefined4 *)puVar4[1];
          puVar7 = puVar4;
        }
      }
    }
  }
  return;
}


// ==== FUN_0079c6e0 @ 0x0079c6e0 ====

void FUN_0079c6e0(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  void *_Memory;
  int in_ECX;
  byte bVar5;
  undefined1 auStack_bc [4];
  undefined1 local_b8;
  undefined4 uStack_ac;
  undefined1 *local_a8;
  undefined1 **local_a4;
  undefined1 *local_88 [2];
  undefined1 local_80 [4];
  void *local_7c;
  undefined4 local_6c;
  uint local_68;
  undefined1 local_64 [4];
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  undefined1 local_48 [4];
  void *local_44;
  undefined4 local_34;
  uint local_30;
  void *local_28;
  undefined4 local_18;
  uint local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009990b0;
  local_c = ExceptionList;
  iVar3 = *(int *)(in_ECX + 8);
  local_a4 = local_88;
  local_a8 = (undefined1 *)0x79c71b;
  ExceptionList = &local_c;
  piVar2 = (int *)FUN_0069a470();
  if (*piVar2 == iVar3) {
    local_a4 = (undefined1 **)0x79c764;
    local_88[0] = operator_new(0x3c);
    local_4 = 1;
    if (local_88[0] == (undefined1 *)0x0) {
      iVar3 = 0;
    }
    else {
      local_a4 = (undefined1 **)0x79c782;
      iVar3 = FUN_0079cb40();
    }
    local_4 = 0xffffffff;
    bVar5 = *(byte *)(param_1 + 0x1c);
    if (*(byte *)(param_1 + 0x1d) < *(byte *)(param_1 + 0x1c)) {
      bVar5 = *(byte *)(param_1 + 0x1d);
    }
    *(byte *)(iVar3 + 0x1c) = bVar5;
    bVar5 = *(byte *)(param_1 + 0x1c);
    if (*(byte *)(param_1 + 0x1c) <= *(byte *)(param_1 + 0x1d)) {
      bVar5 = *(byte *)(param_1 + 0x1d);
    }
    *(byte *)(iVar3 + 0x1d) = bVar5;
    if (*(int *)(iVar3 + 0x34) == 0) {
      local_a4 = (undefined1 **)0x0;
      iVar1 = iVar3 + 0x20;
      uStack_ac = 0x79c7cf;
      local_a8 = (undefined1 *)iVar3;
      FUN_00401660();
      bVar5 = 0;
      if (*(char *)(iVar3 + 0x1d) != '\0') {
        bVar5 = 0;
        do {
          if (bVar5 == *(byte *)(iVar3 + 0x1c)) {
            local_a8 = local_80;
            uStack_ac = 0x79c7f5;
            local_a4 = (undefined1 **)iVar1;
            local_a8 = (undefined1 *)FUN_00402220();
            local_a4 = (undefined1 **)0x0;
            local_4 = 2;
            uStack_ac = 0x79c80f;
            FUN_00401660();
            local_4 = 0xffffffff;
            if (0xf < local_68) {
              local_a4 = (undefined1 **)0x79c82a;
              _free(local_7c);
              return;
            }
            local_68 = 0xf;
            local_6c = 0;
            local_7c = (void *)((uint)local_7c & 0xffffff00);
          }
          local_88[0] = auStack_bc;
          local_a4 = (undefined1 **)0xf;
          local_a8 = (undefined1 *)0x0;
          local_b8 = 0;
          FUN_00401740(s__ARG_u__009fa67c,8);
          uVar4 = FUN_00797530(local_48);
          local_4 = 3;
          local_a8 = (undefined1 *)FUN_00405bd0(local_64,iVar1,uVar4);
          local_a4 = (undefined1 **)0x0;
          local_4 = CONCAT31(local_4._1_3_,4);
          uStack_ac = 0x79c8a5;
          FUN_00401660();
          if (0xf < local_4c) {
            local_a4 = (undefined1 **)0x79c8b5;
            _free(local_60);
            return;
          }
          local_4c = 0xf;
          local_50 = 0;
          local_60 = (void *)((uint)local_60 & 0xffffff00);
          local_4 = 0xffffffff;
          if (0xf < local_30) {
            local_a4 = (undefined1 **)0x79c8e8;
            _free(local_44);
            return;
          }
          bVar5 = bVar5 + 1;
          local_30 = 0xf;
          local_34 = 0;
          local_44 = (void *)((uint)local_44 & 0xffffff00);
        } while (bVar5 < *(byte *)(iVar3 + 0x1d));
      }
      if ((*(byte *)(iVar3 + 0x1c) != *(byte *)(iVar3 + 0x1d)) && (bVar5 == *(byte *)(iVar3 + 0x1c))
         ) {
        local_a8 = local_48;
        uStack_ac = 0x79c928;
        local_a4 = (undefined1 **)iVar1;
        local_a8 = (undefined1 *)FUN_00402220();
        local_a4 = (undefined1 **)0x0;
        local_4 = 5;
        uStack_ac = 0x79c942;
        FUN_00401660();
        local_4 = 0xffffffff;
        if (0xf < local_30) {
          local_a4 = (undefined1 **)0x79c95d;
          _free(local_44);
          return;
        }
      }
    }
    local_a4 = (undefined1 **)0x0;
    local_14 = 0xf;
    local_18 = 0;
    local_28 = (void *)((uint)local_28 & 0xffffff00);
    uStack_ac = 0x79c98c;
    local_a8 = (undefined1 *)iVar3;
    FUN_00401660();
    local_a4 = local_88;
    local_4 = 6;
    local_a8 = (undefined1 *)0x79c9b1;
    local_10 = iVar3;
    FUN_0079d460();
    if (local_14 < 0x10) {
      ExceptionList = local_c;
      return;
    }
    _Memory = local_28;
  }
  else {
    local_a8 = local_48;
    local_a4 = (undefined1 **)param_1;
    uStack_ac = 0x79c72f;
    FUN_00402220();
    local_4 = 0;
    local_a4 = (undefined1 **)0x79c749;
    (**(code **)(*DAT_00b5a72c + 8))();
    if (local_30 < 0x10) {
      ExceptionList = local_c;
      return;
    }
    _Memory = local_44;
  }
  local_a4 = (undefined1 **)0x79c9c4;
  _free(_Memory);
  return;
}


// ==== FUN_0079c9f0 @ 0x0079c9f0 ====

void FUN_0079c9f0(void)

{
  undefined4 *in_ECX;
  uint local_14 [2];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009990cd;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009fa6c4;
  local_4 = 1;
  if (in_ECX[3] != 0) {
    local_14[0] = local_14[0] & 0xffffff00;
    FUN_0079cbc0(*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2],local_14[0]);
    FUN_0079ce20(*(undefined4 *)(in_ECX[2] + 4));
    *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
    in_ECX[3] = 0;
    *(undefined4 *)in_ECX[2] = in_ECX[2];
    *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  }
  DAT_00b5a7d8 = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_0079d3a0(local_14,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0079cab0 @ 0x0079cab0 ====

void FUN_0079cab0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009990df;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009fa6c4;
  iVar1 = FUN_004a37b0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a7d8 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a7d8 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0079cb40 @ 0x0079cb40 ====

void FUN_0079cb40(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00999028;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined1 *)(in_ECX + 0x1c) = *(undefined1 *)(param_1 + 0x1c);
  *(undefined1 *)(in_ECX + 0x1d) = *(undefined1 *)(param_1 + 0x1d);
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  FUN_00401660(param_1 + 0x20,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0079cbc0 @ 0x0079cbc0 ====

uint FUN_0079cbc0(int *param_1,int *param_2,byte param_3)

{
  char cVar1;
  void *_Memory;
  int *piVar2;
  int *piVar3;
  uint extraout_EAX;
  
  while( true ) {
    if (param_1 == param_2) {
      return (uint)param_3;
    }
    _Memory = (void *)param_1[10];
    if (_Memory != (void *)0x0) break;
    if (*(char *)((int)param_1 + 0x2d) == '\0') {
      piVar2 = (int *)param_1[2];
      if (*(char *)((int)piVar2 + 0x2d) == '\0') {
        cVar1 = *(char *)(*piVar2 + 0x2d);
        param_1 = piVar2;
        piVar2 = (int *)*piVar2;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x2d);
          param_1 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(param_1[1] + 0x2d);
        piVar3 = (int *)param_1[1];
        piVar2 = param_1;
        while ((param_1 = piVar3, cVar1 == '\0' && (piVar2 == (int *)param_1[2]))) {
          cVar1 = *(char *)(param_1[1] + 0x2d);
          piVar3 = (int *)param_1[1];
          piVar2 = param_1;
        }
      }
    }
  }
  FUN_0040bf20();
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_0079cc40 @ 0x0079cc40 ====

void FUN_0079cc40(void *param_1,uint param_2,undefined4 *param_3)

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
      uVar7 = FUN_0040c070();
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


// ==== FUN_0079ce20 @ 0x0079ce20 ====

void FUN_0079ce20(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_0079ce20(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0079ce60 @ 0x0079ce60 ====

/* WARNING: Removing unreachable block (ram,0x0079cf70) */
/* WARNING: Removing unreachable block (ram,0x0079cf81) */
/* WARNING: Removing unreachable block (ram,0x0079cf8a) */
/* WARNING: Removing unreachable block (ram,0x0079cf8d) */
/* WARNING: Removing unreachable block (ram,0x0079cf7d) */
/* WARNING: Removing unreachable block (ram,0x0079cf9b) */
/* WARNING: Removing unreachable block (ram,0x0079cfa8) */
/* WARNING: Removing unreachable block (ram,0x0079cfb3) */
/* WARNING: Removing unreachable block (ram,0x0079cfaf) */
/* WARNING: Removing unreachable block (ram,0x0079cfa3) */
/* WARNING: Removing unreachable block (ram,0x0079cfb6) */

void FUN_0079ce60(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_009990f8;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x2d) != '\0') {
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
  FUN_00699bf0();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x2d) == '\0') {
    if (*(char *)(param_2[2] + 0x2d) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x2d) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      piVar3 = (int *)FUN_0079c400(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x2d) == '\0') {
      uVar4 = FUN_00578a40(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xb] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xb] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xb] == '\0') {
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(piVar3 + 0xb) = 0;
            FUN_004eb7a0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x2d) == '\0') {
            if ((*(char *)(*piVar5 + 0x2c) == '\x01') && (*(char *)(piVar5[2] + 0x2c) == '\x01'))
            goto LAB_0079d087;
            if (*(char *)(piVar5[2] + 0x2c) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x2c) = 1;
              *(undefined1 *)(piVar5 + 0xb) = 0;
              FUN_005a3430(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xb) = (char)piVar3[0xb];
            *(undefined1 *)(piVar3 + 0xb) = 1;
            *(undefined1 *)(piVar5[2] + 0x2c) = 1;
            FUN_004eb7a0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xb] == '\0') {
            *(undefined1 *)(piVar5 + 0xb) = 1;
            *(undefined1 *)(piVar3 + 0xb) = 0;
            FUN_005a3430(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x2d) == '\0') {
            if ((*(char *)(piVar5[2] + 0x2c) != '\x01') || (*(char *)(*piVar5 + 0x2c) != '\x01')) {
              if (*(char *)(*piVar5 + 0x2c) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x2c) = 1;
                *(undefined1 *)(piVar5 + 0xb) = 0;
                FUN_004eb7a0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xb) = (char)piVar3[0xb];
              *(undefined1 *)(piVar3 + 0xb) = 1;
              *(undefined1 *)(*piVar5 + 0x2c) = 1;
              FUN_005a3430(piVar3);
              break;
            }
LAB_0079d087:
            *(undefined1 *)(piVar5 + 0xb) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xb) = 1;
  }
  if ((uint)param_2[9] < 0x10) {
    param_2[9] = 0xf;
    param_2[8] = 0;
    *(undefined1 *)(param_2 + 4) = 0;
    _free(param_2);
    return;
  }
  _free((void *)param_2[4]);
  return;
}


// ==== FUN_0079d130 @ 0x0079d130 ====

void * FUN_0079d130(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00999051;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x30);
  local_8 = 1;
  if (pvVar1 != (void *)0x0) {
    FUN_004bbcf0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@0079d1a2 @ 0x0079d1a2 ====

void Catch_0079d1a2(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0079d1c0 @ 0x0079d1c0 ====

void FUN_0079d1c0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_009990f8;
  local_c = ExceptionList;
  if (0x7fffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0079d130(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xb] == '\0') {
LAB_0079d2b9:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_0079d2b9;
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


// ==== FUN_0079d3a0 @ 0x0079d3a0 ====

void FUN_0079d3a0(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0079ce20(piVar6[1]);
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
    FUN_0079ce60(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0079d460 @ 0x0079d460 ====

/* WARNING: Removing unreachable block (ram,0x0079d4bf) */

void FUN_0079d460(undefined4 *param_1,undefined4 *param_2)

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
LAB_0079d4f0:
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
        if (uVar5 == 0) goto LAB_0079d4f0;
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
      puVar6 = (undefined4 *)FUN_0079d1c0(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_0079d1c0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_0079d5d0 @ 0x0079d5d0 ====

void FUN_0079d5d0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0079d3a0(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0079d600 @ 0x0079d600 ====

void FUN_0079d600(byte param_1)

{
  void *in_ECX;
  
  FUN_0079c9f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079d620 @ 0x0079d620 ====

void FUN_0079d620(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa6e0;
  return;
}


// ==== FUN_0079d630 @ 0x0079d630 ====

void FUN_0079d630(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa6e0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079d650 @ 0x0079d650 ====

int FUN_0079d650(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8)) / 0x1c;
}


// ==== FUN_0079d680 @ 0x0079d680 ====

int FUN_0079d680(int param_1,uint param_2)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    if (param_2 < (uint)((*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8)) / 0x1c)) {
      iVar1 = *(int *)(in_ECX + 8);
      if ((iVar1 == 0) || ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x1c) <= param_2)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      *(undefined4 *)(param_1 + 0x18) = 0xf;
      *(undefined4 *)(param_1 + 0x14) = 0;
      *(undefined1 *)(param_1 + 4) = 0;
      FUN_00401660(iVar1 + param_2 * 0x1c,0,0xffffffff);
      return param_1;
    }
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(&DAT_009fa6d9,0);
  return param_1;
}


// ==== FUN_0079d740 @ 0x0079d740 ====

void FUN_0079d740(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa6f4;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_0079d780 @ 0x0079d780 ====

void FUN_0079d780(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa6f4;
  if (in_ECX[2] == 0) {
    in_ECX[2] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    *in_ECX = &PTR_FUN_009fa6e0;
    return;
  }
  FUN_00405de0(in_ECX[2],in_ECX[3],in_ECX + 1);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0079d7d0 @ 0x0079d7d0 ====

void FUN_0079d7d0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) != 0) &&
     (0x3ff < (uint)((*(int *)(in_ECX + 0xc) - *(int *)(in_ECX + 8)) / 0x1c))) {
    iVar1 = *(int *)(in_ECX + 8);
    if (iVar1 != iVar1 + 0xe00) {
      uVar2 = FUN_0040c0e0(iVar1 + 0xe00,*(undefined4 *)(in_ECX + 0xc),iVar1,param_1);
      FUN_00405de0(uVar2,*(undefined4 *)(in_ECX + 0xc),in_ECX + 4,param_1);
      *(undefined4 *)(in_ECX + 0xc) = uVar2;
    }
  }
  FUN_00406720(param_1);
  return;
}


// ==== FUN_0079d850 @ 0x0079d850 ====

void FUN_0079d850(byte param_1)

{
  void *in_ECX;
  
  FUN_0079d780();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079d870 @ 0x0079d870 ====

void FUN_0079d870(void)

{
  undefined8 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa708;
  uVar1 = rdtsc();
  in_ECX[2] = (int)uVar1;
  in_ECX[3] = (int)((ulonglong)uVar1 >> 0x20);
  return;
}


// ==== FUN_0079d8b0 @ 0x0079d8b0 ====

void FUN_0079d8b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa708;
  return;
}


// ==== FUN_0079d8c0 @ 0x0079d8c0 ====

void FUN_0079d8c0(void)

{
  uint uVar1;
  undefined8 uVar2;
  int in_ECX;
  
  uVar2 = rdtsc();
  uVar1 = *(uint *)(in_ECX + 8);
  *(uint *)(in_ECX + 8) = (uint)uVar2 - *(uint *)(in_ECX + 8);
  *(uint *)(in_ECX + 0xc) =
       ((int)((ulonglong)uVar2 >> 0x20) - *(int *)(in_ECX + 0xc)) - (uint)((uint)uVar2 < uVar1);
  return;
}


// ==== FUN_0079d900 @ 0x0079d900 ====

void FUN_0079d900(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa708;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079d920 @ 0x0079d920 ====

void FUN_0079d920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa710;
  return;
}


// ==== FUN_0079d930 @ 0x0079d930 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0079d930(void)

{
  BOOL BVar1;
  int in_ECX;
  LARGE_INTEGER local_8;
  
  BVar1 = QueryPerformanceCounter(&local_8);
  if (BVar1 == 0) {
    return 0;
  }
  local_8.s.LowPart =
       (DWORD)(longlong)
              ROUND((double)(longlong)local_8.s /
                    ((double)*(longlong *)(in_ECX + 8) * _DAT_009fa718));
  return local_8.s.LowPart;
}


// ==== FUN_0079d980 @ 0x0079d980 ====

int FUN_0079d980(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = FUN_0079d930();
  iVar1 = *(int *)(in_ECX + 0x10);
  *(int *)(in_ECX + 0x10) = iVar2;
  return iVar2 - iVar1;
}


// ==== FUN_0079d9a0 @ 0x0079d9a0 ====

void FUN_0079d9a0(void)

{
  BOOL BVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  LARGE_INTEGER local_8;
  
  *in_ECX = &PTR_FUN_009fa710;
  BVar1 = QueryPerformanceFrequency(&local_8);
  if (BVar1 != 0) {
    in_ECX[2] = local_8.s.LowPart;
    in_ECX[3] = local_8.s.HighPart;
    uVar2 = FUN_0079d930();
    in_ECX[4] = uVar2;
  }
  return;
}


// ==== FUN_0079d9e0 @ 0x0079d9e0 ====

void FUN_0079d9e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa710;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079da00 @ 0x0079da00 ====

void FUN_0079da00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa724;
  return;
}


// ==== FUN_0079da20 @ 0x0079da20 ====

int FUN_0079da20(void)

{
  int iVar1;
  DWORD DVar2;
  int in_ECX;
  
  DVar2 = timeGetTime();
  iVar1 = *(int *)(in_ECX + 4);
  *(DWORD *)(in_ECX + 4) = DVar2;
  return DVar2 - iVar1;
}


// ==== FUN_0079da40 @ 0x0079da40 ====

void FUN_0079da40(void)

{
  DWORD DVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa724;
  DVar1 = timeGetTime();
  in_ECX[1] = DVar1;
  return;
}


// ==== FUN_0079da60 @ 0x0079da60 ====

void FUN_0079da60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa724;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079da80 @ 0x0079da80 ====

void FUN_0079da80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa72c;
  return;
}


// ==== FUN_0079da90 @ 0x0079da90 ====

int FUN_0079da90(void)

{
  int in_ECX;
  _SYSTEMTIME local_10;
  
  GetSystemTime(&local_10);
  if (*(WORD *)(in_ECX + 4) != local_10.wDay) {
    *(short *)(in_ECX + 6) = *(short *)(in_ECX + 6) + 1;
    *(WORD *)(in_ECX + 4) = local_10.wDay;
  }
  return (uint)local_10.wMilliseconds +
         ((uint)local_10.wSecond +
         ((uint)local_10.wMinute +
         ((uint)local_10.wHour + (uint)*(ushort *)(in_ECX + 6) * 0x18) * 0x3c) * 0x3c) * 1000;
}


// ==== FUN_0079db00 @ 0x0079db00 ====

int FUN_0079db00(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = FUN_0079da90();
  iVar1 = *(int *)(in_ECX + 8);
  *(int *)(in_ECX + 8) = iVar2;
  return iVar2 - iVar1;
}


// ==== FUN_0079db20 @ 0x0079db20 ====

void FUN_0079db20(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  _SYSTEMTIME local_10;
  
  *in_ECX = &PTR_FUN_009fa72c;
  GetSystemTime(&local_10);
  *(WORD *)(in_ECX + 1) = local_10.wDay;
  *(undefined2 *)((int)in_ECX + 6) = 0;
  uVar1 = FUN_0079da90();
  in_ECX[2] = uVar1;
  return;
}


// ==== FUN_0079db60 @ 0x0079db60 ====

void FUN_0079db60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa72c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== operator_new @ 0x0079db7f ====

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __cdecl operator_new(uint param_1)

{
  int iVar1;
  void *pvVar2;
  
  while( true ) {
    pvVar2 = _malloc(param_1);
    if (pvVar2 != (void *)0x0) break;
    iVar1 = __callnewh(param_1);
    if (iVar1 == 0) {
      FUN_0079dc67();
    }
  }
  return pvVar2;
}


// ==== FUN_0079dba3 @ 0x0079dba3 ====

void FUN_0079dba3(void)

{
  int unaff_EBP;
  
  FUN_00804050();
  FUN_00401830(s_invalid_string_position_009fa730);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00403770(unaff_EBP + -0x28);
  *(undefined ***)(unaff_EBP + -0x50) = &PTR_FUN_0099ca80;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(unaff_EBP + -0x50,&DAT_00a9c7c8);
}


// ==== FUN_0079dbe3 @ 0x0079dbe3 ====

void FUN_0079dbe3(void)

{
  int unaff_EBP;
  
  FUN_00804050();
  FUN_00401830(s_string_too_long_009fa748);
  *(undefined4 *)(unaff_EBP + -4) = 0;
  FUN_00403770(unaff_EBP + -0x28);
  *(undefined ***)(unaff_EBP + -0x50) = &PTR_FUN_0099c98c;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(unaff_EBP + -0x50,&DAT_00a9c48c);
}


// ==== FUN_0079dc28 @ 0x0079dc28 ====

void FUN_0079dc28(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009fa75c;
  FUN_00801801();
  return;
}


// ==== FUN_0079dc33 @ 0x0079dc33 ====

void FUN_0079dc33(byte param_1)

{
  void *in_ECX;
  
  FUN_0079dc28();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0079dc4f @ 0x0079dc4f ====

void FUN_0079dc4f(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  FUN_008017af(param_1);
  *in_ECX = &PTR_FUN_009fa75c;
  return;
}


// ==== FUN_0079dc67 @ 0x0079dc67 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079dc67(void)

{
  undefined **local_14 [3];
  char *local_8;
  
  if ((_DAT_00b5b1cc & 1) == 0) {
    _DAT_00b5b1cc = _DAT_00b5b1cc | 1;
    local_8 = s_bad_allocation_009fa764;
    FUN_00801767(&local_8);
    _DAT_00b5b1c0 = &PTR_FUN_009fa75c;
    _atexit((_func_4879 *)&LAB_0099b40e);
  }
  FUN_008017af(&DAT_00b5b1c0);
  local_14[0] = &PTR_FUN_009fa75c;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_14,&DAT_00ad0f90);
}


// ==== FUN_0079dcc8 @ 0x0079dcc8 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0079dcc8(float param_1,float param_2)

{
  undefined4 uVar1;
  
  param_1 = param_1 - param_2;
  if (((NAN(_DAT_009fc79c) || NAN(param_1)) || _DAT_009fc79c < param_1 == (_DAT_009fc79c == param_1)
      ) || ((NAN(param_1) || NAN(_DAT_009fc798)) ||
            param_1 < _DAT_009fc798 == (param_1 == _DAT_009fc798))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ==== FUN_0079dcfc @ 0x0079dcfc ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079dcfc(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079dd09. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a78)();
  return;
}


// ==== FUN_0079dd15 @ 0x0079dd15 ====

void FUN_0079dd15(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  if (param_3 != 0) {
    do {
      uVar1 = *(uint *)(param_2 + uVar4 * 4);
      uVar2 = uVar1 & 0x7fffffff;
      uVar3 = (ushort)(uVar1 >> 0x10) & 0x8000;
      if (uVar2 < 0x47fff000) {
        if (uVar2 < 0x38800000) {
          iVar5 = 0x71 - (uVar2 >> 0x17);
          if (iVar5 < 0x20) {
            uVar2 = (uVar1 & 0x7fffff | 0x800000) >> ((byte)iVar5 & 0x1f);
          }
          else {
            uVar2 = 0;
          }
          uVar2 = (uVar2 >> 0xd & 1) + 0xfff + uVar2;
        }
        else {
          uVar2 = (uVar2 >> 0xd & 1) + 0xc8000fff + uVar2;
        }
        uVar3 = (ushort)(uVar2 >> 0xd) | uVar3;
      }
      else {
        uVar3 = uVar3 | 0x7fff;
      }
      *(ushort *)(param_1 + uVar4 * 2) = uVar3;
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_3);
  }
  return;
}


// ==== FUN_0079ddb7 @ 0x0079ddb7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079ddb7(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079ddc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a7c)();
  return;
}


// ==== FUN_0079ddd0 @ 0x0079ddd0 ====

int FUN_0079ddd0(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar4 = 0;
  if (param_3 != 0) {
    do {
      uVar1 = *(ushort *)(param_2 + uVar4 * 2);
      uVar2 = (uint)uVar1;
      if ((uVar1 & 0x7c00) == 0) {
        if ((uVar1 & 0x3ff) == 0) {
          uVar2 = (uVar2 & 0xffff8000) << 0x10;
        }
        else {
          iVar5 = -0xe;
          for (uVar3 = uVar2 & 0x3ff; (uVar3 & 0x400) == 0; uVar3 = uVar3 << 1) {
            iVar5 = iVar5 + -1;
          }
          uVar2 = (((uVar2 & 0xffff8080) << 3 | uVar3) & 0xfffffbff) << 0xd |
                  (iVar5 + 0x7f) * 0x800000;
        }
      }
      else {
        uVar2 = ((uVar2 & 0xffff8000) << 3 | uVar2 & 0x3ff) << 0xd |
                ((uVar1 >> 10 & 0x1f) + 0x70) * 0x800000;
      }
      *(uint *)(param_1 + uVar4 * 4) = uVar2;
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_3);
  }
  return param_1;
}


// ==== FUN_0079de77 @ 0x0079de77 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079de77(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079de84. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a4c)();
  return;
}


// ==== FUN_0079de90 @ 0x0079de90 ====

void FUN_0079de90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b449d8)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== FUN_0079debc @ 0x0079debc ====

void FUN_0079debc(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar4 = ((fVar2 + fVar2) - fVar1 * DAT_009b0300) + DAT_0099d080;
  param_6 = (fVar2 - (fVar1 + fVar1)) + param_6;
  fVar3 = fVar1 * DAT_009b0300 - (fVar2 + fVar2);
  *param_1 = (fVar2 - fVar1) * *param_5 + fVar3 * *param_4 + param_6 * *param_3 + fVar4 * *param_2;
  param_1[1] = fVar4 * param_2[1] +
               param_6 * param_3[1] + fVar3 * param_4[1] + (fVar2 - fVar1) * param_5[1];
  return;
}


// ==== FUN_0079df4c @ 0x0079df4c ====

void FUN_0079df4c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a50)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== FUN_0079df78 @ 0x0079df78 ====

void FUN_0079df78(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = DAT_0099d0b4;
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar4 = (fVar1 * DAT_0099d0f8 - fVar2) - param_6;
  fVar3 = (fVar2 * DAT_009b0300 - fVar1 * DAT_009b0120) + DAT_0099d0f8;
  param_6 = (fVar1 * DAT_009b0ec8 - fVar2 * DAT_009b0300) + param_6;
  *param_1 = ((fVar2 - fVar1) * *param_5 + param_6 * *param_4 + fVar3 * *param_3 + fVar4 * *param_2)
             * DAT_0099d0b4;
  param_1[1] = (fVar4 * param_2[1] +
               fVar3 * param_3[1] + param_6 * param_4[1] + (fVar2 - fVar1) * param_5[1]) * fVar5;
  return;
}


// ==== FUN_0079e029 @ 0x0079e029 ====

void FUN_0079e029(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a54)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== FUN_0079e05a @ 0x0079e05a ====

void FUN_0079e05a(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
                 float param_6)

{
  *param_1 = (*param_4 - *param_2) * param_6 + (*param_3 - *param_2) * param_5 + *param_2;
  param_1[1] = (param_4[1] - param_2[1]) * param_6 + (param_3[1] - param_2[1]) * param_5 +
               param_2[1];
  return;
}


// ==== FUN_0079e09f @ 0x0079e09f ====

void FUN_0079e09f(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e0ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_00b44990)();
  return;
}


// ==== FUN_0079e0cb @ 0x0079e0cb ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079e0cb(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e0d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449b4)();
  return;
}


// ==== FUN_0079e0f7 @ 0x0079e0f7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079e0f7(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e104. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449a4)();
  return;
}


// ==== FUN_0079e14e @ 0x0079e14e ====

void FUN_0079e14e(void)

{
  return;
}


// ==== FUN_0079e151 @ 0x0079e151 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079e151(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e15e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a88)();
  return;
}


// ==== FUN_0079e1ba @ 0x0079e1ba ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079e1ba(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e1c7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449ac)();
  return;
}


// ==== FUN_0079e1ff @ 0x0079e1ff ====

void FUN_0079e1ff(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar4 = ((fVar2 + fVar2) - fVar1 * DAT_009b0300) + DAT_0099d080;
  param_6 = (fVar2 - (fVar1 + fVar1)) + param_6;
  fVar3 = fVar1 * DAT_009b0300 - (fVar2 + fVar2);
  fVar2 = fVar2 - fVar1;
  *param_1 = fVar2 * *param_5 + fVar3 * *param_4 + param_6 * *param_3 + fVar4 * *param_2;
  param_1[1] = fVar4 * param_2[1] + param_6 * param_3[1] + fVar3 * param_4[1] + fVar2 * param_5[1];
  param_1[2] = fVar4 * param_2[2] + param_6 * param_3[2] + fVar3 * param_4[2] + fVar2 * param_5[2];
  return;
}


// ==== FUN_0079e2af @ 0x0079e2af ====

void FUN_0079e2af(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a5c)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== FUN_0079e2db @ 0x0079e2db ====

void FUN_0079e2db(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = DAT_0099d0b4;
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar4 = (fVar1 * DAT_0099d0f8 - fVar2) - param_6;
  fVar3 = (fVar2 * DAT_009b0300 - fVar1 * DAT_009b0120) + DAT_0099d0f8;
  param_6 = (fVar1 * DAT_009b0ec8 - fVar2 * DAT_009b0300) + param_6;
  fVar2 = fVar2 - fVar1;
  *param_1 = (fVar2 * *param_5 + param_6 * *param_4 + fVar3 * *param_3 + fVar4 * *param_2) *
             DAT_0099d0b4;
  param_1[1] = (fVar4 * param_2[1] + fVar3 * param_3[1] + param_6 * param_4[1] + fVar2 * param_5[1])
               * fVar5;
  param_1[2] = (fVar4 * param_2[2] + fVar3 * param_3[2] + param_6 * param_4[2] + fVar2 * param_5[2])
               * fVar5;
  return;
}


// ==== FUN_0079e3ae @ 0x0079e3ae ====

void FUN_0079e3ae(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a60)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== FUN_0079e3df @ 0x0079e3df ====

void FUN_0079e3df(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
                 float param_6)

{
  *param_1 = (*param_4 - *param_2) * param_6 + (*param_3 - *param_2) * param_5 + *param_2;
  param_1[1] = (param_4[1] - param_2[1]) * param_6 + (param_3[1] - param_2[1]) * param_5 +
               param_2[1];
  param_1[2] = (param_4[2] - param_2[2]) * param_6 + (param_3[2] - param_2[2]) * param_5 +
               param_2[2];
  return;
}


// ==== FUN_0079e43e @ 0x0079e43e ====

void FUN_0079e43e(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e44b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_00b44994)();
  return;
}


// ==== FUN_0079e4e4 @ 0x0079e4e4 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079e4e4(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e4f1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a8c)();
  return;
}


// ==== FUN_0079e5a0 @ 0x0079e5a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079e5a0(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e5ad. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449b8)();
  return;
}


// ==== FUN_0079e5b9 @ 0x0079e5b9 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079e5b9(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e5c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a90)();
  return;
}


// ==== FUN_0079e6b3 @ 0x0079e6b3 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079e6b3(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e6c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449a8)();
  return;
}


// ==== FUN_0079e734 @ 0x0079e734 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079e734(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e741. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a94)();
  return;
}


// ==== FUN_0079e7c7 @ 0x0079e7c7 ====

void FUN_0079e7c7(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e7d4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_00b449cc)();
  return;
}


// ==== FUN_0079e918 @ 0x0079e918 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079e918(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079e925. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449b0)();
  return;
}


// ==== FUN_0079e957 @ 0x0079e957 ====

void FUN_0079e957(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar3 = ((fVar2 + fVar2) - DAT_009b0300 * fVar1) + DAT_0099d080;
  param_6 = (fVar2 - (fVar1 + fVar1)) + param_6;
  fVar4 = DAT_009b0300 * fVar1 - (fVar2 + fVar2);
  fVar2 = fVar2 - fVar1;
  *param_1 = fVar2 * *param_5 + fVar4 * *param_4 + param_6 * *param_3 + fVar3 * *param_2;
  param_1[1] = fVar3 * param_2[1] + param_6 * param_3[1] + fVar4 * param_4[1] + fVar2 * param_5[1];
  param_1[2] = fVar3 * param_2[2] + param_6 * param_3[2] + fVar4 * param_4[2] + fVar2 * param_5[2];
  param_1[3] = fVar3 * param_2[3] + param_6 * param_3[3] + fVar4 * param_4[3] + fVar2 * param_5[3];
  return;
}


// ==== FUN_0079ea2a @ 0x0079ea2a ====

void FUN_0079ea2a(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a68)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== FUN_0079ea56 @ 0x0079ea56 ====

void FUN_0079ea56(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar5 = DAT_0099d0b4;
  fVar1 = param_6 * param_6;
  fVar2 = param_6 * fVar1;
  fVar4 = (fVar1 * DAT_0099d0f8 - fVar2) - param_6;
  fVar3 = (fVar2 * DAT_009b0300 - fVar1 * DAT_009b0120) + DAT_0099d0f8;
  param_6 = (fVar1 * DAT_009b0ec8 - fVar2 * DAT_009b0300) + param_6;
  fVar2 = fVar2 - fVar1;
  *param_1 = (fVar2 * *param_5 + param_6 * *param_4 + fVar3 * *param_3 + fVar4 * *param_2) *
             DAT_0099d0b4;
  param_1[1] = (fVar4 * param_2[1] + fVar3 * param_3[1] + param_6 * param_4[1] + fVar2 * param_5[1])
               * fVar5;
  param_1[2] = (fVar4 * param_2[2] + fVar3 * param_3[2] + param_6 * param_4[2] + fVar2 * param_5[2])
               * fVar5;
  param_1[3] = (fVar4 * param_2[3] + fVar3 * param_3[3] + param_6 * param_4[3] + fVar2 * param_5[3])
               * fVar5;
  return;
}


// ==== FUN_0079eb4b @ 0x0079eb4b ====

void FUN_0079eb4b(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a6c)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== FUN_0079eb7c @ 0x0079eb7c ====

void FUN_0079eb7c(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
                 float param_6)

{
  *param_1 = (*param_4 - *param_2) * param_6 + (*param_3 - *param_2) * param_5 + *param_2;
  param_1[1] = (param_4[1] - param_2[1]) * param_6 + (param_3[1] - param_2[1]) * param_5 +
               param_2[1];
  param_1[2] = (param_4[2] - param_2[2]) * param_6 + (param_3[2] - param_2[2]) * param_5 +
               param_2[2];
  param_1[3] = (param_4[3] - param_2[3]) * param_6 + (param_3[3] - param_2[3]) * param_5 +
               param_2[3];
  return;
}


// ==== FUN_0079ebf5 @ 0x0079ebf5 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079ebf5(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079ec02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44998)();
  return;
}


// ==== FUN_0079ecaf @ 0x0079ecaf ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079ecaf(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079ecbc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a98)();
  return;
}


// ==== FUN_0079ed83 @ 0x0079ed83 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079ed83(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079ed90. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449bc)();
  return;
}


// ==== FUN_0079ee68 @ 0x0079ee68 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079ee68(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079ee75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449c0)();
  return;
}


// ==== FUN_0079ee7b @ 0x0079ee7b ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079ee7b(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079ee88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b4499c)();
  return;
}


// ==== FUN_0079f0cc @ 0x0079f0cc ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079f0cc(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079f0d9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a28)();
  return;
}


// ==== FUN_0079f156 @ 0x0079f156 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079f156(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079f163. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449a0)();
  return;
}


// ==== FUN_0079f3a1 @ 0x0079f3a1 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079f3a1(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079f3ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449dc)();
  return;
}


// ==== FUN_0079f761 @ 0x0079f761 ====

void FUN_0079f761(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a18)(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_0079f7f5 @ 0x0079f7f5 ====

void FUN_0079f7f5(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b449fc)(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_0079f889 @ 0x0079f889 ====

void FUN_0079f889(undefined4 param_1,undefined4 param_2)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a0c)(param_1,param_2);
  return;
}


// ==== FUN_0079f8a9 @ 0x0079f8a9 ====

void FUN_0079f8a9(undefined4 *param_1,float param_2)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)fcos((float10)param_2);
  fVar2 = (float10)fsin((float10)param_2);
  *param_1 = 0x3f800000;
  param_1[1] = 0;
  param_1[6] = (float)fVar2;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = (float)fVar1;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = -(float)fVar2;
  param_1[10] = (float)fVar1;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0x3f800000;
  return;
}


// ==== FUN_0079f925 @ 0x0079f925 ====

void FUN_0079f925(undefined4 param_1,undefined4 param_2)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a10)(param_1,param_2);
  return;
}


// ==== FUN_0079f9c8 @ 0x0079f9c8 ====

void FUN_0079f9c8(undefined4 param_1,undefined4 param_2)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a14)(param_1,param_2);
  return;
}


// ==== FUN_0079fa6c @ 0x0079fa6c ====

void FUN_0079fa6c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a3c)(param_1,param_2,param_3);
  return;
}


// ==== FUN_0079fb96 @ 0x0079fb96 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079fb96(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079fba3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a2c)();
  return;
}


// ==== FUN_0079fc93 @ 0x0079fc93 ====

void FUN_0079fc93(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a34)(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_0079fcc3 @ 0x0079fcc3 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0079fcc3(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x0079fcd0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a30)();
  return;
}


// ==== FUN_0079ffe2 @ 0x0079ffe2 ====

void FUN_0079ffe2(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44ab0)(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return;
}


