// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x490000-0x49ffff

// ==== FUN_00490260 @ 0x00490260 ====

undefined4 FUN_00490260(int param_1)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  byte bVar11;
  undefined4 uStack_254;
  int *piStack_250;
  undefined4 uStack_24c;
  int *piStack_248;
  undefined1 *puStack_244;
  undefined4 uStack_240;
  undefined4 uStack_234;
  int *piStack_230;
  undefined4 uStack_228;
  undefined2 uStack_220;
  undefined1 auStack_218 [12];
  undefined1 auStack_20c [8];
  undefined1 auStack_204 [192];
  char acStack_144 [32];
  undefined1 auStack_124 [8];
  undefined1 auStack_11c [8];
  undefined1 auStack_114 [276];
  
  uStack_228 = param_1;
  piVar4 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  if (piVar4 == (int *)0x0) {
    uStack_234 = auStack_204;
    piStack_230 = (int *)&DAT_009a97f4;
    FUN_0044a580();
    FUN_00797b80();
    return 0;
  }
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 == (int *)0x0) {
    piStack_230 = (int *)s_LoadStore___pStore_is_NULL_009a96f0;
    uStack_234 = &DAT_009a97f4;
    FUN_0044a580();
    uStack_240 = (int *)0x4902d7;
    FUN_00797b80();
    uStack_234 = (undefined1 *)0x4902e6;
    piStack_230 = piVar4;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  piStack_230 = (int *)auStack_218;
  uStack_234 = (undefined1 *)0x2;
  iVar5 = (**(code **)(*piVar4 + 8))();
  if (iVar5 != 2) {
    uStack_240 = (int *)auStack_20c;
    puStack_244 = (undefined1 *)0x49031a;
    FUN_0044a580();
    puStack_244 = auStack_20c;
    piStack_248 = (int *)0x490324;
    FUN_00797b80();
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  uStack_228 = 2;
  uVar8 = (uint)CONCAT11((char)uStack_220,(char)((ushort)uStack_220 >> 8));
  if (uVar8 != 2) {
    do {
      uStack_240 = (int *)(auStack_218 + -0x12);
      puStack_244 = (undefined1 *)0x1;
      piStack_248 = (int *)0x490375;
      iVar5 = (**(code **)(*piVar4 + 8))();
      if (iVar5 != 1) {
        piStack_248 = (int *)s_LoadStore___pReader_>READ__size___009a973c;
        uStack_24c = 0x490532;
        FUN_0044a670();
        piStack_248 = (int *)auStack_114;
        uStack_24c = 0x49053f;
        FUN_00797b80();
        uStack_24c = 0x49054e;
        piStack_248 = piVar4;
        (**(code **)(*DAT_00b5a69c + 8))();
        return 0;
      }
      piStack_248 = (int *)((int)&uStack_234 + 3);
      uStack_24c = 1;
      piStack_250 = (int *)0x49038c;
      iVar5 = (**(code **)(*piVar4 + 8))();
      if (iVar5 != 1) {
        piStack_250 = (int *)s_LoadStore___pReader_>READ__posit_009a9764;
        uStack_254 = 0x49056e;
        FUN_0044a670();
        piStack_250 = (int *)auStack_11c;
        uStack_254 = 0x49057b;
        FUN_00797b80();
        uStack_254 = 0x49058a;
        piStack_250 = piVar4;
        (**(code **)(*DAT_00b5a69c + 8))();
        return 0;
      }
      piStack_250 = &uStack_228;
      uStack_254 = 4;
      iVar5 = (**(code **)(*piVar4 + 8))();
      if (iVar5 != 4) {
        FUN_0044a670(s_LoadStore___pReader_>READ__dwPri_009a9790);
        FUN_00797b80(auStack_124);
        (**(code **)(*DAT_00b5a69c + 8))(piVar4);
        return 0;
      }
      uVar2 = (uint)puStack_244 >> 0x10;
      bVar11 = 0;
      piStack_230 = (int *)(**(code **)(*piVar4 + 4))(1,0);
      uVar10 = 0;
      uVar9 = 0;
      piVar6 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
      cVar3 = (**(code **)(*piVar6 + 0xc))(auStack_218 + -0x24);
      if (cVar3 == '\0') {
        uVar7 = FUN_0044a580(auStack_218 + -0x20,s_LoadStore___Item_Open_Fail_009a97bc);
        FUN_00797b80(uVar7);
        (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar6);
        (**(code **)(*piVar4 + 4))(1,(uVar10 >> 0x10 & 0xff) - 6);
      }
      else {
        (**(code **)(*piVar6 + 0x68))
                  (CONCAT31((int3)puStack_244,(char)((uint)puStack_244 >> 8)) << 0x10 |
                   ((uint)puStack_244 >> 0x10 & 0xff) << 8 | (uint)puStack_244 >> 0x18);
        uStack_254 = CONCAT22(CONCAT11(uStack_254._3_1_,(bVar11 % 0x32) / 10),
                              CONCAT11((bVar11 % 0x32) % 10,bVar11 / 0x32));
        cVar3 = (**(code **)(*piVar1 + 0x1c))(&uStack_254,piVar6);
        if (cVar3 == '\0') {
          acStack_144[0] = cVar3;
          uVar7 = FUN_0044a580(acStack_144,s_LoadStore___PutItem_fail_009a97d8);
          FUN_00797b80(uVar7);
          (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar6);
        }
        (**(code **)(*piVar4 + 4))(1,(uVar9 >> 0x10 & 0xff) - 6);
      }
      uStack_228 = uStack_228 + ((uVar2 & 0xff) - 6 >> 0x10 & 0xff);
    } while (uVar8 != uStack_228);
  }
  puStack_244 = (undefined1 *)0x490512;
  uStack_240 = piVar4;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 1;
}


// ==== FUN_004905e0 @ 0x004905e0 ====

undefined4 FUN_004905e0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00803725(param_2,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    uVar2 = FUN_0048fb30(param_1,iVar1);
    return uVar2;
  }
  iVar1 = FUN_00803725(param_2,0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::ITradePC::RTTI_Type_Descriptor,0);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_00490260(param_1,iVar1);
  return uVar2;
}


// ==== FUN_00490650 @ 0x00490650 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490650(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a97fc;
  _DAT_00b5aad0 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00490740 @ 0x00490740 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490740(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a9970;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa74 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa74 = in_ECX;
  return;
}


// ==== FUN_00490790 @ 0x00490790 ====

uint FUN_00490790(undefined *param_1,int param_2)

{
  undefined1 *puVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  int iVar7;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  ushort uVar8;
  undefined4 unaff_EBX;
  int *unaff_EBP;
  int *piVar9;
  char *pcVar10;
  undefined1 auStack_142 [10];
  undefined1 *puStack_138;
  undefined1 *puStack_134;
  undefined *puStack_128;
  undefined4 auStack_11c [4];
  int *local_10c;
  undefined1 auStack_104 [232];
  undefined4 uStack_1c;
  
  piVar9 = *(int **)(param_2 + 0x34);
  local_10c = piVar9;
  if (piVar9 == (int *)0x0) {
    puStack_128 = &DAT_009a9968;
    FUN_0044a580();
    puStack_134 = (undefined1 *)0x4907c7;
    uVar3 = FUN_00797b80();
    return uVar3 & 0xffff0000;
  }
  puStack_128 = param_1;
  piVar4 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar4 == (int *)0x0) {
    puStack_134 = auStack_104;
    puStack_138 = (undefined1 *)0x490805;
    FUN_0044a580();
    puStack_138 = auStack_104;
    uVar3 = FUN_00797b80();
    return uVar3 & 0xffff0000;
  }
  puStack_134 = (undefined1 *)0x2;
  puStack_138 = (undefined1 *)0x0;
  (**(code **)(*piVar4 + 4))();
  uVar3 = 2;
  uVar8 = 2;
  auStack_11c[0] = 2;
  piVar5 = (int *)(**(code **)(*piVar9 + 0x34))();
  if (piVar5 != (int *)0x0) {
    do {
      cVar2 = (**(code **)(*piVar9 + 0x18))();
      if (cVar2 == '\x01') {
        puStack_128 = (undefined *)
                      CONCAT31(puStack_128._1_3_,
                               ((char)unaff_EBX * '\x05' + (char)((uint)unaff_EBX >> 0x10)) * '\n' +
                               (char)((uint)unaff_EBX >> 8));
        (**(code **)(*piVar4 + 4))(1);
        iVar7 = *DAT_00b5aa10;
        uVar6 = (**(code **)(*piVar5 + 0x14))(piVar4);
        cVar2 = (**(code **)(iVar7 + 4))(uVar6);
        puVar1 = puStack_134;
        if (cVar2 == '\0') {
          FUN_0044a580(auStack_11c + -2,&DAT_009a9968,s_OnSaveStore___Convert_return_siz_009a9844);
          FUN_00797b80(auStack_11c + -2);
          iVar7 = FUN_00803725(uStack_1c,0,&Framework::ICreature::RTTI_Type_Descriptor,
                               &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
          if (iVar7 != 0) {
            FUN_004985b0(0,iVar7,piVar5,puStack_138);
          }
          goto LAB_00490a76;
        }
        (**(code **)(*piVar4 + 4))(0,(uint)puStack_134 & 0xffff);
        iVar7 = (**(code **)(*piVar4 + 8))(1,auStack_142 + -3);
        if (iVar7 == 1) {
          iVar7 = (**(code **)(*piVar4 + 8))(1,&puStack_138);
          if (iVar7 == 1) {
            uVar3 = (**(code **)(*piVar5 + 0x6c))();
            puStack_128 = (undefined *)
                          (CONCAT31((int3)uVar3,(char)(uVar3 >> 8)) << 0x10 |
                           (uVar3 >> 0x10 & 0xff) << 8 | uVar3 >> 0x18);
            iVar7 = (**(code **)(*piVar4 + 8))(4,&puStack_128);
            if (iVar7 == 4) {
              uVar3 = (int)puVar1 + CONCAT22(extraout_var_01,(ushort)(byte)(cVar2 + 6));
              puStack_134 = (undefined1 *)uVar3;
              (**(code **)(*piVar4 + 4))(0,uVar3 & 0xffff);
              piVar9 = unaff_EBP;
              goto LAB_00490953;
            }
            pcVar10 = s_OnSaveStore___pWriter_>WRITE__dw_009a98dc;
          }
          else {
            pcVar10 = s_OnSaveStore___pWriter_>WRITE__by_009a98a8;
          }
        }
        else {
          pcVar10 = s_OnSaveStore___pWriter_>WRITE__by_009a9874;
        }
        FUN_0044a580(auStack_11c + -2,&DAT_009a9968,pcVar10);
        FUN_00797b80(auStack_11c + -2);
LAB_00490a76:
        uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return uVar3 & 0xffff0000;
      }
LAB_00490953:
      uVar8 = (ushort)uVar3;
      piVar5 = (int *)(**(code **)(*piVar9 + 0x38))();
    } while (piVar5 != (int *)0x0);
    if (1000 < uVar8) {
      local_10c = (int *)((uint)local_10c & 0xffffff00);
      iVar7 = *DAT_00b5aa1c;
      FUN_0044a580();
      (**(code **)(iVar7 + 4))();
    }
  }
  (**(code **)(*piVar4 + 4))();
  auStack_11c[0] = CONCAT22(extraout_var,CONCAT11((char)uVar8,(char)(uVar8 >> 8)));
  iVar7 = (**(code **)(*piVar4 + 8))(2);
  if (iVar7 == 2) {
    (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
    return CONCAT22(extraout_var_00,uVar8);
  }
  FUN_0044a670(s_OnSaveStore___pWriter_>WRITE__wC_009a9934);
  FUN_00797b80(auStack_11c);
  uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
  return uVar3 & 0xffff0000;
}


// ==== FUN_00490ab0 @ 0x00490ab0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490ab0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a9970;
  _DAT_00b5aa74 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00490ae0 @ 0x00490ae0 ====

undefined1 FUN_00490ae0(void)

{
  return 1;
}


// ==== FUN_00490af0 @ 0x00490af0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490af0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a9978;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa94 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa94 = in_ECX;
  return;
}


// ==== FUN_00490b40 @ 0x00490b40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490b40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a9978;
  _DAT_00b5aa94 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00490be0 @ 0x00490be0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490be0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a9af0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa50 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa50 = in_ECX;
  return;
}


// ==== FUN_00490c30 @ 0x00490c30 ====

/* WARNING: Removing unreachable block (ram,0x00490dad) */

uint FUN_00490c30(undefined4 param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined2 extraout_var;
  char *pcVar8;
  undefined1 auStack_122 [2];
  undefined1 auStack_116 [2];
  undefined1 auStack_114 [16];
  undefined1 auStack_104 [4];
  undefined1 local_100 [256];
  
  piVar1 = *(int **)(param_2 + 0x34);
  if (piVar1 == (int *)0x0) {
    FUN_0044a580();
    uVar3 = FUN_00797b80(local_100);
    return uVar3 & 0xffff0000;
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar4 == (int *)0x0) {
    FUN_0044a580(auStack_104,&DAT_009a9ae8);
    uVar3 = FUN_00797b80(auStack_104);
    return uVar3 & 0xffff0000;
  }
  (**(code **)(*piVar4 + 4))(0,2);
  piVar5 = (int *)(**(code **)(*piVar1 + 0x34))();
  do {
    if (piVar5 == (int *)0x0) {
      (**(code **)(*piVar4 + 4))(0,0);
      iVar6 = (**(code **)(*piVar4 + 8))(2,auStack_122 + 6);
      if (iVar6 == 2) {
        (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return CONCAT22(extraout_var,2);
      }
      FUN_0044a670(s_OnSave_StoreSerial___pWriter_>WR_009a9aac);
      FUN_00797b80(auStack_122 + 6);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
    cVar2 = (**(code **)(*piVar1 + 0x18))(piVar5,auStack_122 + 2);
    if (cVar2 == '\x01') {
      iVar6 = (**(code **)(*piVar4 + 8))(1,auStack_122 + -7);
      if (iVar6 != 1) {
        pcVar8 = s_OnSave_StoreSerial___pWriter_>WR_009a99d8;
LAB_00490dea:
        FUN_0044a580(auStack_114,&DAT_009a9ae8,pcVar8);
        FUN_00797b80(auStack_114);
        uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return uVar3 & 0xffff0000;
      }
      (**(code **)(*piVar5 + 0x14))();
      iVar6 = (**(code **)(*piVar4 + 8))(2,auStack_122 + 2);
      if (iVar6 != 2) {
        pcVar8 = s_OnSave_StoreSerial___pWriter_>WR_009a9a14;
        goto LAB_00490dea;
      }
      iVar6 = *DAT_00b5aa10;
      uVar7 = (**(code **)(*piVar5 + 0x74))(piVar4);
      cVar2 = (**(code **)(iVar6 + 0xc))(uVar7);
      if (cVar2 == '\0') {
        pcVar8 = s_OnSave_StoreSerial___Convert_ret_009a9a50;
        goto LAB_00490dea;
      }
    }
    piVar5 = (int *)(**(code **)(*piVar1 + 0x38))();
  } while( true );
}


// ==== FUN_00490eb0 @ 0x00490eb0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490eb0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a9af0;
  _DAT_00b5aa50 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00490f50 @ 0x00490f50 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00490f50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a9f18;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa90 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa90 = in_ECX;
  return;
}


// ==== FUN_00490fa0 @ 0x00490fa0 ====

undefined4 FUN_00490fa0(uint *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  short *psVar8;
  undefined2 *puVar9;
  byte bVar10;
  uint unaff_EBP;
  uint uVar11;
  undefined4 *puVar12;
  int *piVar13;
  undefined1 *puVar14;
  undefined4 uStack_160;
  undefined4 *puStack_15c;
  int *piStack_158;
  int *piStack_154;
  int *piStack_150;
  undefined1 *puStack_14c;
  undefined4 uStack_140;
  undefined4 uStack_134;
  uint uStack_130;
  undefined1 auStack_12c [4];
  undefined1 auStack_128 [4];
  undefined1 auStack_124 [4];
  undefined1 auStack_120 [4];
  uint uStack_11c;
  undefined1 auStack_118 [4];
  undefined1 auStack_114 [4];
  undefined1 auStack_110 [4];
  undefined1 auStack_10c [4];
  undefined1 auStack_108 [4];
  undefined1 auStack_104 [260];
  
  uStack_140 = param_1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  piVar13 = DAT_00b5aa1c;
  if (piVar2 == (int *)0x0) {
    (**(code **)(*param_1 + 0x70))();
    puStack_14c = auStack_104;
    auStack_104[0] = 0;
    iVar3 = *piVar13;
    piStack_150 = (int *)0x490fea;
    FUN_0044a580();
    (**(code **)(iVar3 + 4))();
    piStack_150 = (int *)auStack_108;
    puStack_14c = &DAT_009a9f10;
    piStack_154 = (int *)0x491007;
    FUN_0044a580();
    piStack_154 = (int *)auStack_108;
    piStack_158 = (int *)0x491011;
    FUN_00797b80();
    return 0;
  }
  uStack_11c = param_1[0xd];
  if (uStack_11c == 0) {
    puStack_14c = (undefined1 *)0x491043;
    puStack_14c = (undefined1 *)(**(code **)(*param_1 + 0x70))();
    piStack_154 = (int *)auStack_104;
    piStack_150 = (int *)s_UserName____s__Load_StoreLimit___009a9b54;
    auStack_104[0] = 0;
    iVar3 = *piVar13;
    piStack_158 = (int *)0x49105a;
    puStack_14c = (undefined1 *)FUN_0044a580();
    piStack_150 = (int *)0x491063;
    (**(code **)(iVar3 + 4))();
    piStack_150 = (int *)s_Load_StoreLimit___pSuit_is_NULL_009a9b84;
    piStack_158 = (int *)auStack_108;
    piStack_154 = (int *)&DAT_009a9f10;
    puStack_15c = (undefined4 *)0x491077;
    FUN_0044a580();
    puStack_15c = (undefined4 *)auStack_108;
    uStack_160 = (char *)0x491081;
    FUN_00797b80();
    piStack_154 = (int *)0x491090;
    piStack_150 = piVar2;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  puStack_14c = auStack_124;
  piStack_150 = (int *)0x2;
  piStack_154 = (int *)0x4910ad;
  iVar3 = (**(code **)(*piVar2 + 8))();
  piVar13 = DAT_00b5aa1c;
  if (iVar3 == 2) {
    uVar4 = (uint)CONCAT11(auStack_12c[0],auStack_12c[1]);
    if (uVar4 <= *param_1) {
      uStack_134 = 2;
      if (uVar4 != 2) {
        do {
          piStack_154 = (int *)((int)&uStack_140 + 1);
          piStack_158 = (int *)0x1;
          puStack_15c = (undefined4 *)0x49118e;
          iVar3 = (**(code **)(*piVar2 + 8))();
          piVar13 = DAT_00b5aa1c;
          if (iVar3 != 1) {
            puStack_15c = (undefined4 *)0x49134a;
            puStack_15c = (undefined4 *)(**(code **)(*param_1 + 0x70))();
            uStack_160 = s_UserName____s__Load_StoreLimit__p_009a9c98;
            auStack_114[0] = 0;
            iVar3 = *piVar13;
            puStack_15c = (undefined4 *)FUN_0044a580(auStack_114);
            uStack_160 = (char *)0x49136a;
            (**(code **)(iVar3 + 4))();
            uStack_160 = s_Load_StoreLimit___pReader_>READ__009a9cd8;
            FUN_0044a670();
            uStack_160 = auStack_118;
            FUN_00797b80();
            uStack_160 = (char *)piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          bVar10 = (byte)(unaff_EBP >> 8);
          if (0x32 < bVar10) {
            puStack_15c = (undefined4 *)0x4913ae;
            puStack_15c = (undefined4 *)(**(code **)(*param_1 + 0x70))();
            uStack_160 = s_UserName____s__Load_StoreLimit__I_009a9d0c;
            auStack_114[0] = 0;
            iVar3 = *piVar13;
            puStack_15c = (undefined4 *)FUN_0044a580(auStack_114);
            uStack_160 = (char *)0x4913ce;
            (**(code **)(iVar3 + 4))();
            uStack_160 = s_Load_StoreLimit___Invalid_Positi_009a9d44;
            FUN_0044a670();
            uStack_160 = auStack_118;
            FUN_00797b80();
            uStack_160 = (char *)piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          puStack_15c = &uStack_140;
          uStack_160 = (char *)0x2;
          iVar3 = (**(code **)(*piVar2 + 8))();
          piVar13 = DAT_00b5aa1c;
          if (iVar3 != 2) {
            uVar7 = (**(code **)(*param_1 + 0x70))();
            uStack_11c = uStack_11c & 0xffffff00;
            iVar3 = *piVar13;
            uVar7 = FUN_0044a580(&uStack_11c,s_UserName____s__Load_StoreLimit__p_009a9d70,uVar7);
            (**(code **)(iVar3 + 4))(uVar7);
            FUN_0044a670(s_Load_StoreLimit___pReader_>READ__009a9db4);
            FUN_00797b80(auStack_120);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          unaff_EBP = (uint)CONCAT11((char)unaff_EBP,bVar10);
          uStack_130 = 0xc;
          uStack_134 = (**(code **)(*piVar2 + 4))(1,0);
          puVar14 = auStack_12c + -0xc;
          uVar5 = (**(code **)(*DAT_00b5a69c + 4))();
          piVar13 = DAT_00b5aa1c;
          if (uVar5 == 0) {
            uVar7 = (**(code **)(*param_1 + 0x70))();
            auStack_128[0] = 0;
            iVar3 = *piVar13;
            uVar7 = FUN_0044a580(auStack_128,s_UserName____s__Load_BagLimit___p_009a9de8,uVar7);
            (**(code **)(iVar3 + 4))(uVar7);
            FUN_0044a670(s_Load_BagLimit___pLimitReader_is_N_009a9e20);
            FUN_00797b80(auStack_12c);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          FUN_00797a50(&uStack_134,0,0xc);
          puVar12 = &uStack_134;
          uVar11 = uVar5;
          cVar1 = (**(code **)(*DAT_00b5aa10 + 0x18))(uVar5,puVar12);
          piVar13 = DAT_00b5aa1c;
          bVar10 = (byte)((uint)puVar12 >> 8);
          if (cVar1 == '\0') {
            uVar7 = (**(code **)(*param_1 + 0x70))();
            uStack_130 = uStack_130 & 0xffffff00;
            iVar3 = *piVar13;
            uVar7 = FUN_0044a580(&uStack_130,s_UserName____s__Converter_FAIL_009a9e48,uVar7);
            (**(code **)(iVar3 + 4))(uVar7);
            (**(code **)(*DAT_00b5a69c + 8))(uVar5);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          (**(code **)(*DAT_00b5a69c + 8))(uVar5);
          puStack_15c = (undefined4 *)((int)puStack_15c + 0xf);
          (**(code **)(*piVar2 + 4))(1,0xc);
          uVar5 = bVar10 / 0x32;
          bVar10 = bVar10 + (char)uVar5 * -0x32;
          uStack_160 = (char *)CONCAT31(CONCAT12(uStack_160._3_1_,CONCAT11(bVar10 / 10,bVar10 % 10))
                                        ,(char)uVar5);
          piVar6 = (int *)(**(code **)(*piStack_154 + 0x20))(&uStack_160);
          piVar13 = DAT_00b5aa1c;
          if (piVar6 == (int *)0x0) {
            uVar7 = (**(code **)(*param_1 + 0x70))();
            uStack_140 = (uint *)((uint)uStack_140 & 0xffffff00);
            puStack_15c = (undefined4 *)*piVar13;
            uVar7 = FUN_0044a580(&uStack_140,s_UserName____s__Not_Exist____BagL_009a9e68,uVar7,uVar5
                                 ,uVar11 >> 0x18,uVar11 >> 0x10 & 0xff);
            (**(code **)((int)puStack_15c + 4))(uVar7);
          }
          else {
            psVar8 = (short *)(**(code **)(*piVar6 + 0x14))();
            if ((short)puVar14 != *psVar8) {
              piVar13 = DAT_00b5aa1c;
              uVar7 = (**(code **)(*param_1 + 0x70))();
              uStack_140 = (uint *)((uint)uStack_140 & 0xffffff00);
              puVar9 = (undefined2 *)(**(code **)(*piVar6 + 0x14))();
              iVar3 = *piVar13;
              uVar7 = FUN_0044a580(&uStack_140,s_UserName____s__Not_SameIndex_____009a9ec0,uVar7,
                                   (uint)puVar14 & 0xffff,*puVar9,uVar5,uVar11 >> 0x18,
                                   uVar11 >> 0x10 & 0xff);
              (**(code **)(iVar3 + 4))(uVar7);
              (**(code **)(*DAT_00b5a69c + 8))(piVar2);
              return 0;
            }
            (**(code **)(*piVar6 + 0x78))(&puStack_14c);
          }
        } while (uVar4 != uStack_134);
      }
      piStack_158 = (int *)0x49132d;
      piStack_154 = piVar2;
      (**(code **)(*DAT_00b5a69c + 8))();
      return 1;
    }
    piStack_154 = (int *)0x49110d;
    piStack_154 = (int *)(**(code **)(*param_1 + 0x70))();
    puStack_15c = (undefined4 *)auStack_10c;
    piStack_158 = (int *)s_UserName____s__Load_StoreLimit__w_009a9c20;
    auStack_10c[0] = 0;
    iVar3 = *piVar13;
    uStack_160 = (char *)0x491124;
    piStack_154 = (int *)FUN_0044a580();
    piStack_158 = (int *)0x49112d;
    (**(code **)(iVar3 + 4))();
    piStack_158 = (int *)s_Load_StoreLimit___wConvertSize_>_009a9c64;
  }
  else {
    piStack_154 = (int *)0x4910c0;
    piStack_154 = (int *)(**(code **)(*param_1 + 0x70))();
    puStack_15c = (undefined4 *)auStack_10c;
    piStack_158 = (int *)s_UserName____s__Load_StoreLimit___009a9ba8;
    auStack_10c[0] = 0;
    iVar3 = *piVar13;
    uStack_160 = (char *)0x4910d7;
    piStack_154 = (int *)FUN_0044a580();
    piStack_158 = (int *)0x4910e0;
    (**(code **)(iVar3 + 4))();
    piStack_158 = (int *)s_Load_StoreLimit___pReader_>READ__009a9bec;
  }
  uStack_160 = auStack_110;
  puStack_15c = (undefined4 *)&DAT_009a9f10;
  FUN_0044a580();
  FUN_00797b80(auStack_110);
  puStack_15c = (undefined4 *)0x49115a;
  piStack_158 = piVar2;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 0;
}


// ==== FUN_004915a0 @ 0x004915a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004915a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009a9f18;
  _DAT_00b5aa90 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00491640 @ 0x00491640 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00491640(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aa084;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa4c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa4c = in_ECX;
  return;
}


// ==== FUN_00491690 @ 0x00491690 ====

/* WARNING: Removing unreachable block (ram,0x0049180d) */

uint FUN_00491690(undefined4 param_1,int param_2)

{
  int *piVar1;
  char cVar2;
  uint uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined2 extraout_var;
  char *pcVar8;
  undefined1 auStack_122 [2];
  undefined1 auStack_116 [2];
  undefined1 auStack_114 [16];
  undefined1 auStack_104 [4];
  undefined1 local_100 [256];
  
  piVar1 = *(int **)(param_2 + 0x34);
  if (piVar1 == (int *)0x0) {
    FUN_0044a580();
    uVar3 = FUN_00797b80(local_100);
    return uVar3 & 0xffff0000;
  }
  piVar4 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar4 == (int *)0x0) {
    FUN_0044a580(auStack_104,&DAT_009aa07c);
    uVar3 = FUN_00797b80(auStack_104);
    return uVar3 & 0xffff0000;
  }
  (**(code **)(*piVar4 + 4))(0,2);
  piVar5 = (int *)(**(code **)(*piVar1 + 0x34))();
  do {
    if (piVar5 == (int *)0x0) {
      (**(code **)(*piVar4 + 4))(0,0);
      iVar6 = (**(code **)(*piVar4 + 8))(2,auStack_122 + 6);
      if (iVar6 == 2) {
        (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return CONCAT22(extraout_var,2);
      }
      FUN_0044a670(s_OnSave_StoreLImit___pWriter_>WRI_009aa044);
      FUN_00797b80(auStack_122 + 6);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
      return uVar3 & 0xffff0000;
    }
    cVar2 = (**(code **)(*piVar1 + 0x18))(piVar5,auStack_122 + 2);
    if (cVar2 == '\x01') {
      iVar6 = (**(code **)(*piVar4 + 8))(1,auStack_122 + -7);
      if (iVar6 != 1) {
        pcVar8 = s_OnSave_StoreLimit___pWriter_>WRI_009a9f70;
LAB_0049184a:
        FUN_0044a580(auStack_114,&DAT_009aa07c,pcVar8);
        FUN_00797b80(auStack_114);
        uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return uVar3 & 0xffff0000;
      }
      (**(code **)(*piVar5 + 0x14))();
      iVar6 = (**(code **)(*piVar4 + 8))(2,auStack_122 + 2);
      if (iVar6 != 2) {
        pcVar8 = s_OnSave_StoreLimit___pWriter_>WRI_009a9fac;
        goto LAB_0049184a;
      }
      iVar6 = *DAT_00b5aa10;
      uVar7 = (**(code **)(*piVar5 + 0x7c))(piVar4);
      cVar2 = (**(code **)(iVar6 + 0x14))(uVar7);
      if (cVar2 == '\0') {
        pcVar8 = s_OnSave_StoreLimit___Convert_retu_009a9fe8;
        goto LAB_0049184a;
      }
    }
    piVar5 = (int *)(**(code **)(*piVar1 + 0x38))();
  } while( true );
}


// ==== FUN_00491910 @ 0x00491910 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00491910(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aa084;
  _DAT_00b5aa4c = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004919a0 @ 0x004919a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004919a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aa514;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aacc = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aacc = in_ECX;
  return;
}


// ==== FUN_004919f0 @ 0x004919f0 ====

undefined4 FUN_004919f0(uint *param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  byte bVar8;
  int *unaff_EBP;
  uint unaff_EDI;
  uint uVar9;
  byte bVar10;
  uint uVar11;
  undefined4 uStack_650;
  int *piStack_64c;
  int *piStack_644;
  undefined4 uStack_640;
  undefined4 uStack_63c;
  uint uVar12;
  undefined1 auStack_62a [14];
  undefined1 auStack_61c [4];
  uint uStack_618;
  int *piStack_614;
  undefined1 auStack_610 [4];
  undefined1 auStack_60c [4];
  undefined1 auStack_608 [4];
  undefined1 uStack_604;
  undefined1 auStack_534 [20];
  undefined1 auStack_520 [4];
  undefined1 auStack_51c [4];
  undefined1 auStack_518 [4];
  undefined1 auStack_514 [224];
  undefined1 auStack_434 [248];
  undefined1 auStack_33c [256];
  undefined1 auStack_23c [264];
  undefined1 auStack_134 [308];
  
  uStack_63c = param_1;
  uStack_640 = (undefined1 *)0x491a0c;
  piVar3 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  piVar1 = DAT_00b5aa1c;
  piStack_614 = piVar3;
  if (piVar3 == (int *)0x0) {
    uStack_640 = (undefined1 *)0x491a28;
    uStack_640 = (undefined1 *)(**(code **)(*param_1 + 0x70))();
    uStack_604 = 0;
    iVar4 = *piVar1;
    piStack_64c = (int *)0x491a3f;
    uStack_640 = (undefined1 *)FUN_0044a580();
    (**(code **)(iVar4 + 4))();
    piStack_64c = (int *)auStack_608;
    uStack_650 = (undefined1 *)0x491a5c;
    FUN_0044a580();
    uStack_650 = auStack_608;
    FUN_00797b80();
    return 0;
  }
  uStack_618 = param_1[0xb];
  if (uStack_618 == 0) {
    uStack_640 = (undefined1 *)0x491a96;
    uStack_640 = (undefined1 *)(**(code **)(*param_1 + 0x70))();
    uStack_604 = 0;
    iVar4 = *piVar1;
    piStack_64c = (int *)0x491aad;
    uStack_640 = (undefined1 *)FUN_0044a580();
    (**(code **)(iVar4 + 4))();
    piStack_64c = (int *)auStack_608;
    uStack_650 = (undefined1 *)0x491aca;
    FUN_0044a580();
    uStack_650 = auStack_608;
    FUN_00797b80();
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  uStack_640 = auStack_61c;
  piStack_644 = (int *)0x2;
  iVar4 = (**(code **)(*piVar3 + 8))();
  piVar1 = DAT_00b5aa1c;
  if (iVar4 == 2) {
    uStack_618 = (uint)CONCAT11(auStack_62a[6],auStack_62a[7]);
    if (uStack_618 <= *param_1) {
      uVar12 = 2;
      if (uStack_618 != 2) {
        do {
          piStack_64c = (int *)(auStack_62a + -0xc);
          uStack_650 = (undefined1 *)0x1;
          iVar4 = (**(code **)(*piVar3 + 8))();
          piVar1 = DAT_00b5aa1c;
          if (iVar4 != 1) {
            uVar6 = (**(code **)(*param_1 + 0x70))();
            auStack_514[0] = 0;
            iVar4 = *piVar1;
            uVar6 = FUN_0044a580(auStack_514,s_UserName____s__LoadStorage___wCo_009aa20c,uVar6);
            (**(code **)(iVar4 + 4))(uVar6);
            FUN_0044a670(s_LoadStorage___pReader_>READ__siz_009aa24c);
            FUN_00797b80(auStack_518);
            (**(code **)(*DAT_00b5a69c + 8))(piVar3);
            return 0;
          }
          if (uStack_640._2_1_ < 3) {
            uVar6 = (**(code **)(*param_1 + 0x70))();
            auStack_514[0] = 0;
            iVar4 = *piVar1;
            uVar6 = FUN_0044a580(auStack_514,s_UserName____s__LoadStorage___siz_009aa278,uVar6);
            (**(code **)(iVar4 + 4))(uVar6);
            FUN_0044a670(s_LoadStorage___size_<__2_009aa2a0);
            FUN_00797b80(auStack_518);
            (**(code **)(*DAT_00b5a69c + 8))(piVar3);
            return 0;
          }
          iVar4 = (**(code **)(*piVar3 + 8))(1,(int)&uStack_640 + 3);
          piVar1 = DAT_00b5aa1c;
          if (iVar4 != 1) {
            uVar6 = (**(code **)(*param_1 + 0x70))();
            auStack_51c[0] = 0;
            iVar4 = *piVar1;
            uVar6 = FUN_0044a580(auStack_51c,s_UserName____s__LoadStorage___pRe_009aa2bc,uVar6);
            (**(code **)(iVar4 + 4))(uVar6);
            FUN_0044a670(s_LoadStorage___pReader_>READ__siz_009aa2f8);
            FUN_00797b80(auStack_520);
            (**(code **)(*DAT_00b5a69c + 8))(piVar3);
            return 0;
          }
          (**(code **)(*piVar3 + 4))(1,0);
          bVar10 = (byte)((uint)iVar4 >> 0x18);
          uVar9 = 0;
          piVar5 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
          cVar2 = (**(code **)(*piVar5 + 0xc))(auStack_62a + -10);
          piVar1 = DAT_00b5aa1c;
          if (cVar2 == '\0') {
            uVar6 = (**(code **)(*param_1 + 0x70))();
            uVar12 = uVar12 & 0xffffff00;
            iVar4 = *piVar1;
            uVar6 = FUN_0044a580(auStack_62a + -6,s_UserName____s__LoadStorage___Ite_009aa324,uVar6)
            ;
            (**(code **)(iVar4 + 4))(uVar6);
            auStack_434[0] = 0;
            uVar6 = FUN_0044a580(auStack_434,s_LoadStorage___Item_Open_Fail_009aa354);
            FUN_00797b80(uVar6);
LAB_00491ebd:
            (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar5);
          }
          else {
            cVar2 = (**(code **)(*DAT_00b5a734 + 0x38))(piVar5);
            if (cVar2 == '\0') {
              puVar7 = (undefined2 *)(**(code **)(*piVar5 + 0x14))();
              piVar1 = DAT_00b5aa1c;
              uVar6 = (**(code **)(*param_1 + 0x70))();
              auStack_134[0] = 0;
              iVar4 = *piVar1;
              uVar6 = FUN_0044a580(auStack_134,s__ITEM__InvalidItem___index__u__U_009aa378,*puVar7,
                                   uVar6,*(undefined1 *)((int)puVar7 + 0x21),puVar7[6],
                                   *(undefined1 *)((int)puVar7 + 0x1f),*(undefined1 *)(puVar7 + 0xf)
                                   ,puVar7[7],*(undefined1 *)(puVar7 + 8),puVar7[9],
                                   *(undefined1 *)(puVar7 + 10),puVar7[0xb],
                                   *(undefined1 *)(puVar7 + 0xc),puVar7[0xd],
                                   *(undefined1 *)(puVar7 + 0xe),puVar7[2],puVar7[3],puVar7[4],
                                   puVar7[5]);
              (**(code **)(iVar4 + 0xc))(uVar6);
              (**(code **)(*DAT_00b5a734 + 0x3c))(piVar5);
              piVar1 = DAT_00b5aa1c;
              uVar6 = (**(code **)(*param_1 + 0x70))();
              auStack_23c[0] = 0;
              iVar4 = *piVar1;
              uVar6 = FUN_0044a580(auStack_23c,s__ITEM__RevisedItem___index__u__U_009aa420,*puVar7,
                                   uVar6,*(undefined1 *)((int)puVar7 + 0x21),puVar7[6],
                                   *(undefined1 *)((int)puVar7 + 0x1f),*(undefined1 *)(puVar7 + 0xf)
                                   ,puVar7[7],*(undefined1 *)(puVar7 + 8),puVar7[9],
                                   *(undefined1 *)(puVar7 + 10),puVar7[0xb],
                                   *(undefined1 *)(puVar7 + 0xc),puVar7[0xd],
                                   *(undefined1 *)(puVar7 + 0xe),puVar7[2],puVar7[3],puVar7[4],
                                   puVar7[5]);
              (**(code **)(iVar4 + 0xc))(uVar6);
              piVar3 = piStack_644;
            }
            bVar8 = (bVar10 % 100) % 10;
            uVar11 = (uint)bVar8;
            uStack_650 = (undefined1 *)
                         CONCAT22(CONCAT11(uStack_650._3_1_,(bVar10 % 100) / 10),
                                  CONCAT11(bVar8,bVar10 / 100));
            cVar2 = (**(code **)(*unaff_EBP + 0x20))(&uStack_650,piVar5);
            piVar1 = DAT_00b5aa1c;
            if (cVar2 == '\0') {
              uVar6 = (**(code **)(*param_1 + 0x70))();
              auStack_33c[0] = 0;
              iVar4 = *piVar1;
              uVar6 = FUN_0044a580(auStack_33c,s_UserName____s__LoadStorage___Put_009aa4c4,uVar6);
              (**(code **)(iVar4 + 4))(uVar6);
              auStack_534[0] = 0;
              uVar6 = FUN_0044a580(auStack_534,s_LoadStorage___PutItem_fail_009aa4f0);
              FUN_00797b80(uVar6);
              FUN_00498050(2,param_1,piVar5,uVar11);
              goto LAB_00491ebd;
            }
          }
          (**(code **)(*piVar3 + 4))(1,(uVar9 >> 0x10 & 0xff) - 2);
          uVar12 = uVar12 + (unaff_EDI >> 0x10 & 0xff);
        } while (uStack_618 != uVar12);
      }
      uStack_650 = (undefined1 *)0x491f00;
      piStack_64c = piVar3;
      (**(code **)(*DAT_00b5a69c + 8))();
      return 1;
    }
    (**(code **)(*param_1 + 0x70))();
    uStack_650 = auStack_60c;
    piStack_64c = (int *)s_UserName____s__LoadStorage___wCo_009aa19c;
    auStack_60c[0] = 0;
    iVar4 = *piVar1;
    FUN_0044a580();
    piStack_64c = (int *)0x491b7d;
    (**(code **)(iVar4 + 4))();
    piStack_64c = (int *)s_LoadStorage___wConvertSize_>_rBu_009aa1dc;
  }
  else {
    (**(code **)(*param_1 + 0x70))();
    uStack_650 = auStack_60c;
    piStack_64c = (int *)s_UserName____s__LoadStorage___pRe_009aa12c;
    auStack_60c[0] = 0;
    iVar4 = *piVar1;
    FUN_0044a580();
    piStack_64c = (int *)0x491b31;
    (**(code **)(iVar4 + 4))();
    piStack_64c = (int *)s_LoadStorage___pReader_>READ___To_009aa16c;
  }
  uStack_650 = &DAT_009aa50c;
  FUN_0044a580(auStack_610);
  FUN_00797b80(auStack_610);
  uStack_650 = (undefined1 *)0x491baa;
  piStack_64c = piVar3;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 0;
}


// ==== FUN_00492060 @ 0x00492060 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00492060(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aa514;
  _DAT_00b5aacc = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00492090 @ 0x00492090 ====

undefined1 FUN_00492090(void)

{
  return 1;
}


// ==== FUN_004920a0 @ 0x004920a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004920a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aa51c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa9c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa9c = in_ECX;
  return;
}


// ==== FUN_004920f0 @ 0x004920f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004920f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aa51c;
  _DAT_00b5aa9c = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00492190 @ 0x00492190 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00492190(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aa908;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa98 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa98 = in_ECX;
  return;
}


// ==== FUN_004921e0 @ 0x004921e0 ====

undefined4 FUN_004921e0(uint *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  short *psVar8;
  undefined2 *puVar9;
  byte bVar10;
  uint uVar11;
  undefined4 *puVar12;
  int *piVar13;
  undefined1 *puVar14;
  undefined4 uStack_160;
  undefined4 *puStack_15c;
  int *piStack_158;
  int *piStack_154;
  int *piStack_150;
  undefined1 *puStack_14c;
  undefined4 uStack_140;
  undefined4 uStack_134;
  uint uStack_130;
  undefined1 auStack_12c [4];
  undefined1 auStack_128 [4];
  undefined1 auStack_124 [4];
  undefined1 auStack_120 [4];
  uint uStack_11c;
  undefined1 auStack_118 [4];
  undefined1 auStack_114 [4];
  undefined1 auStack_110 [4];
  undefined1 auStack_10c [4];
  undefined1 auStack_108 [4];
  undefined1 auStack_104 [260];
  
  uStack_140 = param_1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  piVar13 = DAT_00b5aa1c;
  if (piVar2 == (int *)0x0) {
    (**(code **)(*param_1 + 0x70))();
    puStack_14c = auStack_104;
    auStack_104[0] = 0;
    iVar3 = *piVar13;
    piStack_150 = (int *)0x49222a;
    FUN_0044a580();
    (**(code **)(iVar3 + 4))();
    piStack_150 = (int *)auStack_108;
    puStack_14c = &DAT_009aa900;
    piStack_154 = (int *)0x492247;
    FUN_0044a580();
    piStack_154 = (int *)auStack_108;
    piStack_158 = (int *)0x492251;
    FUN_00797b80();
    return 0;
  }
  uStack_11c = param_1[0xb];
  if (uStack_11c == 0) {
    puStack_14c = (undefined1 *)0x492283;
    puStack_14c = (undefined1 *)(**(code **)(*param_1 + 0x70))();
    piStack_154 = (int *)auStack_104;
    piStack_150 = (int *)s_UserName____s__Load_StorageLimit_009aa580;
    auStack_104[0] = 0;
    iVar3 = *piVar13;
    piStack_158 = (int *)0x49229a;
    puStack_14c = (undefined1 *)FUN_0044a580();
    piStack_150 = (int *)0x4922a3;
    (**(code **)(iVar3 + 4))();
    piStack_150 = (int *)s_Load_StorageLimit___pStorage_is_N_009aa5b8;
    piStack_158 = (int *)auStack_108;
    piStack_154 = (int *)&DAT_009aa900;
    puStack_15c = (undefined4 *)0x4922b7;
    FUN_0044a580();
    puStack_15c = (undefined4 *)auStack_108;
    uStack_160 = (char *)0x4922c1;
    FUN_00797b80();
    piStack_154 = (int *)0x4922d0;
    piStack_150 = piVar2;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  puStack_14c = auStack_124;
  piStack_150 = (int *)0x2;
  piStack_154 = (int *)0x4922ed;
  iVar3 = (**(code **)(*piVar2 + 8))();
  piVar13 = DAT_00b5aa1c;
  if (iVar3 == 2) {
    uVar4 = (uint)CONCAT11(auStack_12c[0],auStack_12c[1]);
    if (uVar4 <= *param_1) {
      uStack_134 = 2;
      if (uVar4 != 2) {
        do {
          piStack_154 = (int *)((int)&uStack_140 + 3);
          piStack_158 = (int *)0x1;
          puStack_15c = (undefined4 *)0x4923ce;
          iVar3 = (**(code **)(*piVar2 + 8))();
          piVar13 = DAT_00b5aa1c;
          if (iVar3 != 1) {
            puStack_15c = (undefined4 *)0x49257f;
            puStack_15c = (undefined4 *)(**(code **)(*param_1 + 0x70))();
            uStack_160 = s_UserName____s__Load_StorageLimit_009aa6e0;
            auStack_114[0] = 0;
            iVar3 = *piVar13;
            puStack_15c = (undefined4 *)FUN_0044a580(auStack_114);
            uStack_160 = (char *)0x49259f;
            (**(code **)(iVar3 + 4))();
            uStack_160 = s_LoadBag___pReader_>READ__byPosit_009aa728;
            FUN_0044a670();
            uStack_160 = auStack_118;
            FUN_00797b80();
            uStack_160 = (char *)piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          puStack_15c = &uStack_140;
          uStack_160 = (char *)0x2;
          iVar3 = (**(code **)(*piVar2 + 8))();
          piVar13 = DAT_00b5aa1c;
          if (iVar3 != 2) {
            uVar7 = (**(code **)(*param_1 + 0x70))();
            uStack_11c = uStack_11c & 0xffffff00;
            iVar3 = *piVar13;
            uVar7 = FUN_0044a580(&uStack_11c,s_UserName____s__Load_StorageLimit_009aa758,uVar7);
            (**(code **)(iVar3 + 4))(uVar7);
            FUN_0044a670(s_Load_StorageLimit__pReader_>READ_009aa79c);
            FUN_00797b80(auStack_120);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          uStack_130 = 0xc;
          uStack_134 = (**(code **)(*piVar2 + 4))(1,0);
          puVar14 = auStack_12c + -0xc;
          uVar5 = (**(code **)(*DAT_00b5a69c + 4))();
          piVar13 = DAT_00b5aa1c;
          if (uVar5 == 0) {
            uVar7 = (**(code **)(*param_1 + 0x70))();
            auStack_128[0] = 0;
            iVar3 = *piVar13;
            uVar7 = FUN_0044a580(auStack_128,s_UserName____s__Load_BagLimit___p_009aa7d4,uVar7);
            (**(code **)(iVar3 + 4))(uVar7);
            FUN_0044a670(s_Load_BagLimit___pLimitReader_is_N_009aa80c);
            FUN_00797b80(auStack_12c);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          FUN_00797a50(&uStack_134,0,0xc);
          puVar12 = &uStack_134;
          uVar11 = uVar5;
          cVar1 = (**(code **)(*DAT_00b5aa10 + 0x18))(uVar5,puVar12);
          piVar13 = DAT_00b5aa1c;
          bVar10 = (byte)((uint)puVar12 >> 0x18);
          if (cVar1 == '\0') {
            uVar7 = (**(code **)(*param_1 + 0x70))();
            uStack_130 = uStack_130 & 0xffffff00;
            iVar3 = *piVar13;
            uVar7 = FUN_0044a580(&uStack_130,s_UserName____s__Converter_FAIL_009aa834,uVar7);
            (**(code **)(iVar3 + 4))(uVar7);
            (**(code **)(*DAT_00b5a69c + 8))(uVar5);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          (**(code **)(*DAT_00b5a69c + 8))(uVar5);
          puStack_15c = (undefined4 *)((int)puStack_15c + 0xf);
          (**(code **)(*piVar2 + 4))(1,0xc);
          uVar5 = bVar10 / 100;
          bVar10 = bVar10 + (char)uVar5 * -100;
          uStack_160 = (char *)CONCAT31(CONCAT12(uStack_160._3_1_,CONCAT11(bVar10 / 10,bVar10 % 10))
                                        ,(char)uVar5);
          piVar6 = (int *)(**(code **)(*piStack_154 + 0x24))(&uStack_160);
          piVar13 = DAT_00b5aa1c;
          if (piVar6 == (int *)0x0) {
            uVar7 = (**(code **)(*param_1 + 0x70))();
            uStack_140 = (uint *)((uint)uStack_140 & 0xffffff00);
            puStack_15c = (undefined4 *)*piVar13;
            uVar7 = FUN_0044a580(&uStack_140,s_UserName____s__Not_Exist____BagL_009aa858,uVar7,uVar5
                                 ,uVar11 >> 0x10 & 0xff,uVar11 >> 8 & 0xff);
            (**(code **)((int)puStack_15c + 4))(uVar7);
          }
          else {
            psVar8 = (short *)(**(code **)(*piVar6 + 0x14))();
            if ((short)puVar14 != *psVar8) {
              piVar13 = DAT_00b5aa1c;
              uVar7 = (**(code **)(*param_1 + 0x70))();
              uStack_140 = (uint *)((uint)uStack_140 & 0xffffff00);
              puVar9 = (undefined2 *)(**(code **)(*piVar6 + 0x14))();
              iVar3 = *piVar13;
              uVar7 = FUN_0044a580(&uStack_140,s_UserName____s__Not_SameIndex_____009aa8b0,uVar7,
                                   (uint)puVar14 & 0xffff,*puVar9,uVar5,uVar11 >> 0x10 & 0xff,
                                   uVar11 >> 8 & 0xff);
              (**(code **)(iVar3 + 4))(uVar7);
              (**(code **)(*DAT_00b5a69c + 8))(piVar2);
              return 0;
            }
            (**(code **)(*piVar6 + 0x78))(&puStack_14c);
          }
        } while (uVar4 != uStack_134);
      }
      piStack_158 = (int *)0x492562;
      piStack_154 = piVar2;
      (**(code **)(*DAT_00b5a69c + 8))();
      return 1;
    }
    piStack_154 = (int *)0x49234d;
    piStack_154 = (int *)(**(code **)(*param_1 + 0x70))();
    puStack_15c = (undefined4 *)auStack_10c;
    piStack_158 = (int *)s_UserName____s__Load_StorageLimit_009aa660;
    auStack_10c[0] = 0;
    iVar3 = *piVar13;
    uStack_160 = (char *)0x492364;
    piStack_154 = (int *)FUN_0044a580();
    piStack_158 = (int *)0x49236d;
    (**(code **)(iVar3 + 4))();
    piStack_158 = (int *)s_Load_StorageLimit___wConvertSize_009aa6a4;
  }
  else {
    piStack_154 = (int *)0x492300;
    piStack_154 = (int *)(**(code **)(*param_1 + 0x70))();
    puStack_15c = (undefined4 *)auStack_10c;
    piStack_158 = (int *)s_UserName____s__Load_StorageLimit_009aa5e0;
    auStack_10c[0] = 0;
    iVar3 = *piVar13;
    uStack_160 = (char *)0x492317;
    piStack_154 = (int *)FUN_0044a580();
    piStack_158 = (int *)0x492320;
    (**(code **)(iVar3 + 4))();
    piStack_158 = (int *)s_Load_StorageLimit___pReader_>REA_009aa628;
  }
  uStack_160 = auStack_110;
  puStack_15c = (undefined4 *)&DAT_009aa900;
  FUN_0044a580();
  FUN_00797b80(auStack_110);
  puStack_15c = (undefined4 *)0x49239a;
  piStack_158 = piVar2;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 0;
}


// ==== FUN_00492770 @ 0x00492770 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00492770(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aa908;
  _DAT_00b5aa98 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004927f0 @ 0x004927f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004927f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aaa5c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aac8 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aac8 = in_ECX;
  return;
}


// ==== FUN_00492840 @ 0x00492840 ====

undefined4 FUN_00492840(uint param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  byte bVar6;
  undefined4 *puVar7;
  char *pcVar8;
  undefined4 uStack_120;
  undefined4 uStack_11c;
  undefined4 uStack_118;
  undefined1 auStack_10c [8];
  undefined1 auStack_104 [256];
  int iStack_4;
  
  uStack_118 = param_1;
  uStack_11c = (char *)0x492857;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  if (piVar2 == (int *)0x0) {
    uStack_11c = s_LoadSkill___pReader_is_NULL_009aa910;
    uStack_120 = &DAT_009aaa54;
    FUN_0044a580(auStack_104);
    FUN_00797b80(auStack_104);
    return 0;
  }
  uStack_11c = auStack_10c;
  uStack_120 = (undefined *)0x2;
  iVar3 = (**(code **)(*piVar2 + 8))();
  if (iVar3 == 2) {
    iVar3 = (**(code **)(*piVar2 + 8))(1,(int)&uStack_11c + 2);
    if (iVar3 == 1) {
      if (*(int **)(iStack_4 + 0x40) == (int *)0x0) {
        FUN_0044a580(auStack_10c,&DAT_009aaa54,s_LoadSkill___pManager_is_NULL_009aa98c);
        FUN_00797b80(auStack_10c);
        (**(code **)(*DAT_00b5a69c + 8))(piVar2);
        return 0;
      }
      piVar4 = (int *)(**(code **)(**(int **)(iStack_4 + 0x40) + 0x20))();
      if (piVar4 == (int *)0x0) {
        FUN_0044a670(s_LoadSkill___pTree_is_NULL_009aa9ac);
        FUN_00797b80(auStack_10c);
        (**(code **)(*DAT_00b5a69c + 8))(piVar2);
        return 0;
      }
      cVar1 = uStack_11c._2_1_;
      while( true ) {
        if (cVar1 == '\0') {
          (**(code **)(*DAT_00b5a69c + 8))(piVar2);
          return 1;
        }
        puVar7 = &uStack_118;
        bVar6 = 0;
        iVar3 = (**(code **)(*piVar2 + 8))(2,puVar7);
        if (iVar3 != 2) break;
        iVar3 = (**(code **)(*piVar2 + 8))(1,auStack_10c + -0x15);
        if (iVar3 != 1) {
          FUN_0044a670(s_LoadSkill___pReader_>READ___Leve_009aa9f4);
          FUN_00797b80(&uStack_11c);
          (**(code **)(*DAT_00b5a69c + 8))(piVar2);
          return 0;
        }
        uStack_120 = (undefined *)
                     CONCAT22(uStack_120._2_2_,(ushort)(bVar6 & 0xf) | (ushort)((int)puVar7 << 4));
        iVar3 = (**(code **)(*DAT_00b5abd8 + 4))(&uStack_120);
        if (iVar3 == 0) {
          auStack_10c[0] = 0;
          uVar5 = FUN_0044a580(auStack_10c,s_LoadSkillTree___pSkill_is_NULL__S_009aaa20,
                               uStack_118 & 0xffff);
          FUN_00797b80(uVar5);
        }
        else {
          (**(code **)(*piVar4 + 0x10))(iVar3);
        }
        cVar1 = uStack_11c._2_1_ + -1;
        uStack_11c._0_3_ = CONCAT12(cVar1,(undefined2)uStack_11c);
      }
      FUN_0044a670(s_LoadSkill___pReader_>READ___Inde_009aa9c8);
      FUN_00797b80(auStack_10c + -8);
      (**(code **)(*DAT_00b5a69c + 8))(piVar2);
      return 0;
    }
    pcVar8 = s_LoadSkill___pReader_>READ___coun_009aa960;
  }
  else {
    pcVar8 = s_LoadSkill___pReader_>READ___Tota_009aa930;
  }
  FUN_0044a580(auStack_10c,&DAT_009aaa54,pcVar8);
  FUN_00797b80(auStack_10c);
  (**(code **)(*DAT_00b5a69c + 8))(piVar2);
  return 0;
}


// ==== FUN_00492aa0 @ 0x00492aa0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00492aa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aaa5c;
  _DAT_00b5aac8 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00492b30 @ 0x00492b30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00492b30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aabbc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa6c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa6c = in_ECX;
  return;
}


// ==== FUN_00492b80 @ 0x00492b80 ====

uint FUN_00492b80(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined1 *puVar6;
  int iVar7;
  undefined4 uVar8;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  ushort uVar9;
  ushort uVar10;
  char *pcVar11;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_118;
  undefined1 auStack_10c [8];
  undefined1 auStack_104 [4];
  undefined1 local_100 [256];
  
  if (*(int **)(param_2 + 0x40) == (int *)0x0) {
    uStack_118 = local_100;
    FUN_0044a580();
    uStack_120 = (undefined1 *)0x492baf;
    uVar2 = FUN_00797b80();
    return uVar2 & 0xffff0000;
  }
  piVar3 = (int *)(**(code **)(**(int **)(param_2 + 0x40) + 0x20))();
  if (piVar3 == (int *)0x0) {
    uStack_118 = &DAT_009aabb4;
    uStack_120 = (undefined1 *)0x492bde;
    FUN_0044a580();
    uStack_120 = local_100;
    uStack_124 = (undefined1 *)0x492be8;
    uVar2 = FUN_00797b80();
    return uVar2 & 0xffff0000;
  }
  uStack_118 = (undefined1 *)param_1;
  piVar4 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar4 == (int *)0x0) {
    uStack_124 = auStack_104;
    uStack_120 = &DAT_009aabb4;
    FUN_0044a580();
    uVar2 = FUN_00797b80(auStack_104);
    return uVar2 & 0xffff0000;
  }
  uStack_120 = (undefined1 *)0x3;
  uStack_124 = (undefined1 *)0x0;
  (**(code **)(*piVar4 + 4))();
  uStack_118._0_3_ = (uint3)(ushort)uStack_118;
  uVar9 = 3;
  piVar5 = (int *)(**(code **)(*piVar3 + 0x20))();
  uVar10 = 3;
  if (piVar5 != (int *)0x0) {
    do {
      piVar5 = (int *)(**(code **)(*piVar5 + 0x18))();
      puVar6 = (undefined1 *)(**(code **)(*piVar5 + 0xc))();
      uStack_118 = (undefined1 *)(CONCAT13(*puVar6,(uint3)uStack_118) & 0xfffffff);
      iVar7 = (**(code **)(*piVar4 + 8))(2,auStack_10c + -8);
      if (iVar7 != 2) {
        pcVar11 = s_OnSendSkill___pWriter_>WRITE__in_009aaac4;
LAB_00492d5c:
        FUN_0044a580(auStack_10c + -8,&DAT_009aabb4,pcVar11);
        FUN_00797b80(auStack_10c + -8);
        uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
        return uVar2 & 0xffff0000;
      }
      iVar7 = (**(code **)(*piVar4 + 8))(1,(int)&uStack_120 + 3);
      if (iVar7 != 1) {
        pcVar11 = s_OnSendSkill___pWriter_>WRITE__le_009aaaf4;
        goto LAB_00492d5c;
      }
      cVar1 = uStack_120._2_1_ + '\x01';
      uStack_120._0_3_ = CONCAT12(cVar1,(undefined2)uStack_120);
      uVar9 = uVar10 + 3;
      piVar5 = (int *)(**(code **)(*piVar3 + 0x24))();
      uVar10 = uVar9;
    } while (piVar5 != (int *)0x0);
    if (0x12f < uVar9) {
      auStack_10c[0] = 0;
      iVar7 = *DAT_00b5aa1c;
      uVar8 = FUN_0044a580(auStack_10c,s_Skill__Save_wTotalSize__d__>_303_009aab24,uVar9);
      (**(code **)(iVar7 + 4))(uVar8);
    }
  }
  (**(code **)(*piVar4 + 4))(0,0);
  uStack_118 = (undefined1 *)CONCAT22(extraout_var,CONCAT11((char)uVar9,(char)(uVar9 >> 8)));
  iVar7 = (**(code **)(*piVar4 + 8))(2,&uStack_118);
  if (iVar7 != 2) {
    FUN_0044a670(s_OnSendSkill___pWriter_>WRITE__wC_009aab48);
    FUN_00797b80(auStack_10c + -0x10);
    uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
    return uVar2 & 0xffff0000;
  }
  iVar7 = (**(code **)(*piVar4 + 8))(1,auStack_10c + -0x1a);
  if (iVar7 == 1) {
    (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
    return CONCAT22(extraout_var_00,uVar9);
  }
  FUN_0044a670(s_OnSendSkill___pWriter_>WRITE__bT_009aab7c);
  FUN_00797b80(&uStack_124);
  uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar4);
  return uVar2 & 0xffff0000;
}


// ==== FUN_00492e00 @ 0x00492e00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00492e00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aabbc;
  _DAT_00b5aa6c = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00492e80 @ 0x00492e80 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00492e80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aad54;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aac4 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aac4 = in_ECX;
  return;
}


// ==== FUN_00492ed0 @ 0x00492ed0 ====

undefined4 FUN_00492ed0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  undefined2 unaff_BX;
  char *pcVar7;
  undefined4 uVar8;
  undefined4 uStack_124;
  undefined1 auStack_116 [2];
  undefined4 auStack_114 [2];
  undefined1 auStack_10c [4];
  undefined1 auStack_108 [4];
  undefined1 auStack_104 [256];
  int iStack_4;
  
  uStack_124 = param_1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(auStack_104,&DAT_009aad4c,s_LoadSkillSlot___pReader_is_NULL_009aabc4);
    FUN_00797b80(auStack_104);
    return 0;
  }
  uVar8 = 2;
  iVar3 = (**(code **)(*piVar2 + 8))(2,auStack_108);
  if (iVar3 == 2) {
    iVar3 = (**(code **)(*piVar2 + 8))(1,(int)&uStack_124 + 3);
    if (iVar3 == 1) {
      piVar5 = *(int **)(iStack_4 + 0x40);
      if (piVar5 == (int *)0x0) {
        FUN_0044a580(auStack_10c,&DAT_009aad4c,s_LoadSkillSlot___pManager_is_NULL_009aac4c);
        FUN_00797b80(auStack_10c);
        (**(code **)(*DAT_00b5a69c + 8))(piVar2);
        return 0;
      }
      piVar4 = (int *)(**(code **)(*piVar5 + 0x1c))();
      if (piVar4 == (int *)0x0) {
        FUN_0044a670(s_LoadSkillSlot___pQuickSlot_is_NU_009aac70);
        FUN_00797b80(auStack_10c);
        (**(code **)(*DAT_00b5a69c + 8))(piVar2);
        return 0;
      }
      piVar5 = (int *)(**(code **)(*piVar5 + 0x20))();
      if (piVar5 == (int *)0x0) {
        FUN_0044a670(s_LoadSkillSlot___pTree_is_NULL_009aac94);
        FUN_00797b80(auStack_10c);
        (**(code **)(*DAT_00b5a69c + 8))(piVar2);
        return 0;
      }
      cVar1 = uStack_124._3_1_;
      while( true ) {
        if (cVar1 == '\0') {
          (**(code **)(*DAT_00b5a69c + 8))(piVar2);
          return 1;
        }
        iVar3 = (**(code **)(*piVar2 + 8))(1,auStack_114);
        if (iVar3 != 1) break;
        iVar3 = (**(code **)(*piVar2 + 8))(2,&uStack_124);
        if (iVar3 != 2) {
          FUN_0044a670(s_LoadSkillSlot___pReader_>READ____009aace8);
          FUN_00797b80(auStack_116 + -6);
          (**(code **)(*DAT_00b5a69c + 8))(piVar2);
          return 0;
        }
        iVar3 = (**(code **)(*piVar5 + 0x18))(uVar8);
        if (iVar3 == 0) {
          auStack_10c[0] = 0;
          uVar6 = FUN_0044a580(auStack_10c,s_LoadSkillSlot___pSkill_is_NULL_S_009aad18,unaff_BX);
          FUN_00797b80(uVar6);
        }
        else {
          FUN_00493190(auStack_114[0]);
          (**(code **)(*piVar4 + 0xc))(auStack_116 + -10,iVar3);
        }
        cVar1 = uStack_124._3_1_ + -1;
        uStack_124 = CONCAT13(cVar1,(undefined3)uStack_124);
      }
      FUN_0044a670(s_LoadSkillSlot___pReader_>READ____009aacb4);
      FUN_00797b80(auStack_114);
      (**(code **)(*DAT_00b5a69c + 8))(piVar2);
      return 0;
    }
    pcVar7 = s_LoadSkillSlot___pReader_>READ____009aac1c;
  }
  else {
    pcVar7 = s_LoadSkillSlot___pReader_>READ____009aabe8;
  }
  FUN_0044a580(auStack_10c,&DAT_009aad4c,pcVar7);
  FUN_00797b80(auStack_10c);
  (**(code **)(*DAT_00b5a69c + 8))(piVar2);
  return 0;
}


// ==== FUN_00493190 @ 0x00493190 ====

uint FUN_00493190(byte param_1)

{
  uint in_EAX;
  byte *in_ECX;
  
  if (param_1 < 0x12) {
    *in_ECX = param_1 / 9;
    in_ECX[1] = param_1 % 9;
    return 1;
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_004931c0 @ 0x004931c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004931c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aad54;
  _DAT_00b5aac4 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00493250 @ 0x00493250 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493250(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aaed0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa68 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa68 = in_ECX;
  return;
}


// ==== FUN_004932a0 @ 0x004932a0 ====

uint FUN_004932a0(undefined4 param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  ushort *puVar5;
  int iVar6;
  undefined4 uVar7;
  undefined2 extraout_var;
  byte bVar8;
  char *pcVar9;
  ushort uVar10;
  ushort uVar11;
  undefined4 uStack_114;
  undefined1 auStack_10c [8];
  undefined1 auStack_104 [4];
  undefined1 local_100 [256];
  
  if (*(int **)(param_2 + 0x40) == (int *)0x0) {
    FUN_0044a580(local_100);
    uVar1 = FUN_00797b80(local_100);
    return uVar1 & 0xffff0000;
  }
  piVar2 = (int *)(**(code **)(**(int **)(param_2 + 0x40) + 0x1c))();
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009aaec8);
    uVar1 = FUN_00797b80(local_100);
    return uVar1 & 0xffff0000;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar3 == (int *)0x0) {
    FUN_0044a580(auStack_104,&DAT_009aaec8,s_OnSendSkillSlot___pWriter_is_NUL_009aada8);
    uVar1 = FUN_00797b80(auStack_104);
    return uVar1 & 0xffff0000;
  }
  (**(code **)(*piVar3 + 4))(0,3);
  uVar11 = 3;
  iVar6 = 0;
  do {
    bVar8 = 0;
    do {
      piVar4 = (int *)(**(code **)(*piVar2 + 8))(auStack_10c + -0x10);
      uVar10 = (ushort)((uint)iVar6 >> 0x10);
      if (piVar4 != (int *)0x0) {
        piVar4 = (int *)(**(code **)(*piVar4 + 0x18))();
        puVar5 = (ushort *)(**(code **)(*piVar4 + 0xc))();
        uVar10 = uVar10 & 0xff;
        uStack_114 = CONCAT22((short)((uint)puVar5 >> 0x10),*puVar5 >> 4);
        iVar6 = (**(code **)(*piVar3 + 8))(1,auStack_10c + -0x11);
        if (iVar6 != 1) {
          pcVar9 = s_OnSendSkillSlot___pWriter_>WRITE_009aadcc;
          goto LAB_00493485;
        }
        iVar6 = (**(code **)(*piVar3 + 8))(2,&uStack_114);
        if (iVar6 != 2) {
          pcVar9 = s_OnSendSkillSlot___pWriter_>WRITE_009aae00;
          goto LAB_00493485;
        }
        uVar11 = uVar11 + 3;
        iVar6 = (uint)uVar10 << 0x10;
      }
      bVar8 = bVar8 + 1;
    } while (bVar8 < 9);
    bVar8 = (char)((uint)iVar6 >> 0x10) + 1;
    iVar6 = (uint)bVar8 << 0x10;
  } while (bVar8 < 2);
  if (0x6f < uVar11) {
    auStack_10c[0] = 0;
    iVar6 = *DAT_00b5aa1c;
    uVar7 = FUN_0044a580(auStack_10c,s_SkillSlot__Save_wTotalSize__d__>_009aae34,uVar11);
    (**(code **)(iVar6 + 4))(uVar7);
  }
  (**(code **)(*piVar3 + 4))(0,0);
  iVar6 = (**(code **)(*piVar3 + 8))(2,auStack_10c + -0xc);
  if (iVar6 == 2) {
    iVar6 = (**(code **)(*piVar3 + 8))(1,auStack_10c + -0x13);
    if (iVar6 == 1) {
      (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
      return CONCAT22(extraout_var,uVar11);
    }
    pcVar9 = s_OnSendSkill___pWriter_>WRITE__bT_009aae90;
  }
  else {
    pcVar9 = s_OnSendSkill___pWriter_>WRITE__wC_009aae5c;
  }
LAB_00493485:
  FUN_0044a580(auStack_10c,&DAT_009aaec8,pcVar9);
  FUN_00797b80(auStack_10c);
  uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
  return uVar1 & 0xffff0000;
}


// ==== FUN_00493500 @ 0x00493500 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493500(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aaed0;
  _DAT_00b5aa68 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00493580 @ 0x00493580 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493580(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ab11c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aac0 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aac0 = in_ECX;
  return;
}


// ==== FUN_004935d0 @ 0x004935d0 ====

undefined4 FUN_004935d0(undefined4 param_1)

{
  char cVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  undefined2 extraout_var;
  undefined2 unaff_BP;
  uint unaff_ESI;
  int *piVar8;
  undefined4 uVar9;
  byte bVar10;
  uint uVar11;
  undefined1 *puVar12;
  undefined4 uVar13;
  undefined4 uStack_138;
  char *pcStack_134;
  undefined4 uStack_130;
  undefined1 auStack_124 [8];
  int aiStack_11c [2];
  undefined1 auStack_114 [8];
  char acStack_10c [264];
  int iStack_4;
  
  uStack_130 = param_1;
  pcStack_134 = (char *)0x4935e7;
  piVar3 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  if (piVar3 == (int *)0x0) {
    pcStack_134 = s_LoadQuestDoing___pReader_is_NULL_009aaedc;
    uStack_138 = &DAT_009ab114;
    FUN_0044a580();
    FUN_00797b80();
    return 0;
  }
  pcStack_134 = acStack_10c;
  uStack_138 = (undefined *)0x2;
  iVar4 = (**(code **)(*piVar3 + 8))();
  if ((iVar4 != 2) || (iVar4 = (**(code **)(*piVar3 + 8))(), iVar4 != 2)) {
    FUN_0044a580(acStack_10c);
    FUN_00797b80(acStack_10c);
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  sVar2 = CONCAT11((char)unaff_BP,(char)((ushort)unaff_BP >> 8));
  piVar7 = (int *)CONCAT22(extraout_var,sVar2);
  if (*(int **)(iStack_4 + 0x60) == (int *)0x0) {
    FUN_0044a580(acStack_10c,&DAT_009ab114);
    FUN_00797b80(acStack_10c);
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  aiStack_11c[0] = (**(code **)(**(int **)(iStack_4 + 0x60) + 0x14))();
  piVar6 = piVar7;
  if (aiStack_11c[0] == 0) {
    FUN_0044a670();
    FUN_00797b80();
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  while( true ) {
    if (sVar2 == 0) {
      (**(code **)(*DAT_00b5a69c + 8))(piVar3);
      return 1;
    }
    iVar4 = (**(code **)(*piVar3 + 8))(2,&pcStack_134);
    if (iVar4 != 2) {
      FUN_0044a670(s_LoadQuestDoing___pReader_>READ____009aafa8);
      FUN_00797b80(auStack_114);
      (**(code **)(*DAT_00b5a69c + 8))(piVar3);
      return 0;
    }
    iVar4 = (**(code **)(*piVar3 + 8))(1,&uStack_138);
    if (iVar4 != 1) {
      FUN_0044a670(s_LoadQuestDoing___pReader_>READ____009aafe0);
      FUN_00797b80(aiStack_11c);
      (**(code **)(*DAT_00b5a69c + 8))(piVar3);
      return 0;
    }
    iVar4 = (**(code **)(*piVar3 + 8))(1,&pcStack_134);
    if (iVar4 != 1) break;
    uVar13 = 1;
    iVar4 = (**(code **)(*piVar3 + 8))(1,&uStack_130);
    if (iVar4 != 1) {
      FUN_0044a670(s_LoadQuestDoing___pReader_>READ____009ab040);
      FUN_00797b80(auStack_124 + -8);
      (**(code **)(*DAT_00b5a69c + 8))(piVar3);
      return 0;
    }
    puVar12 = auStack_124 + -0x1c;
    uVar11 = 1;
    iVar4 = (**(code **)(*piVar3 + 8))(1,puVar12);
    if (iVar4 != 1) {
      FUN_0044a670(s_LoadQuestDoing___pReader_>READ____009ab070);
      FUN_00797b80(&pcStack_134);
      (**(code **)(*DAT_00b5a69c + 8))(piVar3);
      return 0;
    }
    uVar9 = 4;
    iVar4 = (**(code **)(*piVar3 + 8))(4,&uStack_138);
    if (iVar4 != 4) {
      FUN_0044a670(s_LoadQuestDoing___pReader_>READ____009ab0a0);
      FUN_00797b80(auStack_124 + -0x18);
      (**(code **)(*DAT_00b5a69c + 8))(piVar3);
      return 0;
    }
    piVar8 = (int *)0x0;
    piVar5 = (int *)(**(code **)(*DAT_00b5abe0 + 0xc))(1);
    (**(code **)(*piVar5 + 8))
              ((unaff_ESI & 0xff) << 8 |
               CONCAT22((short)((uint)piVar6 >> 0x10),(ushort)unaff_ESI >> 8));
    piVar6 = (int *)(**(code **)(*piVar5 + 0xc))();
    bVar10 = (byte)uVar11;
    if (0x80 < bVar10) {
      (**(code **)(*piVar6 + 0x10))(1);
      uVar11 = (uint)(byte)(bVar10 + 0x80);
    }
    (**(code **)(*piVar6 + 0xc))(0,uVar11);
    (**(code **)(*piVar6 + 0xc))(1,puVar12);
    (**(code **)(*piVar6 + 0xc))(2,uVar13);
    (**(code **)(*piVar6 + 0xc))(3,uVar9);
    cVar1 = (**(code **)(*piVar8 + 4))(piVar5);
    if (cVar1 == '\0') {
      acStack_10c[0] = cVar1;
      uVar13 = FUN_0044a580(acStack_10c,s_LoadQuestDoing___pBook_>Insert_i_009ab0d0,
                            (uint)pcStack_134 & 0xffff);
      FUN_00797b80(uVar13);
    }
    piVar7 = (int *)((int)piVar7 + 0xffff);
    sVar2 = (short)piVar7;
  }
  FUN_0044a670(s_LoadQuestDoing___pReader_>READ____009ab010);
  FUN_00797b80(auStack_124);
  (**(code **)(*DAT_00b5a69c + 8))(piVar3);
  return 0;
}


// ==== FUN_004939e0 @ 0x004939e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004939e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ab11c;
  _DAT_00b5aac0 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00493a70 @ 0x00493a70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493a70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ab37c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa64 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa64 = in_ECX;
  return;
}


// ==== FUN_00493ac0 @ 0x00493ac0 ====

/* WARNING: Removing unreachable block (ram,0x00493cb1) */

uint FUN_00493ac0(undefined4 param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined2 *puVar5;
  int iVar6;
  undefined2 extraout_var;
  undefined4 uStack_144;
  undefined4 uStack_140;
  uint *puStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined1 auStack_126 [2];
  undefined4 uStack_11c;
  undefined1 auStack_114 [4];
  uint auStack_110 [3];
  undefined1 auStack_104 [260];
  
  if (*(int **)(param_2 + 0x60) == (int *)0x0) {
    FUN_0044a580();
    uVar1 = FUN_00797b80();
    return uVar1 & 0xffff0000;
  }
  piVar2 = (int *)(**(code **)(**(int **)(param_2 + 0x60) + 0x14))();
  if (piVar2 == (int *)0x0) {
    FUN_0044a580();
    uStack_134 = (undefined1 *)0x493b28;
    uVar1 = FUN_00797b80();
    return uVar1 & 0xffff0000;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar3 == (int *)0x0) {
    uStack_134 = auStack_104;
    uStack_138 = (undefined1 *)0x493b66;
    FUN_0044a580();
    uStack_138 = auStack_104;
    puStack_13c = (uint *)0x493b70;
    uVar1 = FUN_00797b80();
    return uVar1 & 0xffff0000;
  }
  uStack_134 = (undefined1 *)0x4;
  uStack_138 = (undefined1 *)0x0;
  puStack_13c = (uint *)0x493b8e;
  (**(code **)(*piVar3 + 4))();
  puStack_13c = (uint *)0x493ba6;
  piVar4 = (int *)(**(code **)(*piVar2 + 0x14))();
  while( true ) {
    if (piVar4 == (int *)0x0) {
      puStack_13c = (uint *)0x0;
      uStack_140 = 0;
      uStack_144 = (char *)0x493caa;
      (**(code **)(*piVar3 + 4))();
      uStack_144 = auStack_126 + 6;
      iVar6 = (**(code **)(*piVar3 + 8))(2);
      if (iVar6 != 2) {
        FUN_0044a670(s_OnSendSkill___pWriter_>WRITE__wC_009ab308);
        FUN_00797b80(&uStack_11c);
        uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
        return uVar1 & 0xffff0000;
      }
      iVar6 = (**(code **)(*piVar3 + 8))(2,auStack_126 + 2);
      if (iVar6 == 2) {
        (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
        return CONCAT22(extraout_var,4);
      }
      FUN_0044a670(s_OnSendSkill___pWriter_>WRITE__bT_009ab33c);
      FUN_00797b80(auStack_126 + 2);
      uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
      return uVar1 & 0xffff0000;
    }
    puStack_13c = (uint *)0x493bba;
    piVar4 = (int *)(**(code **)(*piVar4 + 0xc))();
    puStack_13c = (uint *)0x493bc1;
    puVar5 = (undefined2 *)(**(code **)(*piVar4 + 4))();
    auStack_110[0] = (uint)CONCAT11((char)*puVar5,(char)((ushort)*puVar5 >> 8));
    puStack_13c = auStack_110;
    uStack_140 = 2;
    uStack_11c = 0;
    uStack_144 = (char *)0x493c06;
    iVar6 = (**(code **)(*piVar3 + 8))();
    if (iVar6 != 2) {
      uStack_144 = s_OnSendQuestDoing___pWriter_>WRIT_009ab194;
      FUN_0044a670();
      uStack_144 = auStack_114;
      FUN_00797b80();
      uStack_144 = (char *)piVar3;
      uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))();
      return uVar1 & 0xffff0000;
    }
    uStack_144 = auStack_126 + -10;
    iVar6 = (**(code **)(*piVar3 + 8))(1);
    if (iVar6 != 1) {
      FUN_0044a670(s_OnSendQuestDoing___pWriter_>WRIT_009ab1cc);
      FUN_00797b80(&uStack_11c);
      uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
      return uVar1 & 0xffff0000;
    }
    iVar6 = (**(code **)(*piVar3 + 8))(1,(int)&uStack_138 + 1);
    if (iVar6 != 1) {
      FUN_0044a670(s_OnSendQuestDoing___pWriter_>WRIT_009ab204);
      FUN_00797b80(auStack_126 + 2);
      uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
      return uVar1 & 0xffff0000;
    }
    iVar6 = (**(code **)(*piVar3 + 8))(1,(int)&uStack_140 + 2);
    if (iVar6 != 1) break;
    iVar6 = (**(code **)(*piVar3 + 8))(1,auStack_126 + -0x1f);
    if (iVar6 != 1) {
      FUN_0044a670(s_OnSendQuestDoing___pWriter_>WRIT_009ab274);
      FUN_00797b80(&uStack_134);
      uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
      return uVar1 & 0xffff0000;
    }
    iVar6 = (**(code **)(*piVar3 + 8))(4,&uStack_144);
    if (iVar6 != 4) {
      FUN_0044a670(s_OnSendQuestDone___pWriter_>WRITE_009ab2ac);
      FUN_00797b80(&puStack_13c);
      uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
      return uVar1 & 0xffff0000;
    }
    piVar4 = (int *)(**(code **)(*piVar2 + 0x18))();
  }
  FUN_0044a670(s_OnSendQuestDoing___pWriter_>WRIT_009ab23c);
  FUN_00797b80(auStack_126 + -6);
  uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
  return uVar1 & 0xffff0000;
}


// ==== FUN_00493ef0 @ 0x00493ef0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493ef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ab37c;
  _DAT_00b5aa64 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00493f70 @ 0x00493f70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00493f70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ab4b8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aabc = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aabc = in_ECX;
  return;
}


// ==== FUN_00493fc0 @ 0x00493fc0 ====

undefined4 FUN_00493fc0(int param_1)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  short sVar5;
  undefined2 extraout_var;
  uint uVar6;
  undefined1 *puStack_120;
  char *pcStack_11c;
  int iStack_114;
  undefined1 auStack_10c [4];
  char acStack_108 [4];
  undefined1 auStack_104 [260];
  
  iStack_114 = param_1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  if ((piVar2 == (int *)0x0) || (*(int **)(param_1 + 0x60) == (int *)0x0)) {
    puStack_120 = auStack_104;
    pcStack_11c = &DAT_009ab4b0;
    FUN_0044a580();
    FUN_00797b80(auStack_104);
    return 0;
  }
  pcStack_11c = (char *)0x494025;
  piVar3 = (int *)(**(code **)(**(int **)(param_1 + 0x60) + 0x18))();
  if (piVar3 == (int *)0x0) {
    pcStack_11c = s_LoadQuestDone___pDiary_is_NULL_009ab3cc;
    puStack_120 = &DAT_009ab4b0;
    FUN_0044a580(auStack_104);
    FUN_00797b80(auStack_104);
    return 0;
  }
  pcStack_11c = acStack_108;
  puStack_120 = (undefined1 *)0x2;
  iVar4 = (**(code **)(*piVar2 + 8))();
  if (iVar4 != 2) {
    FUN_0044a580(auStack_10c,&DAT_009ab4b0,s_LoadQuestDone___Reader_>READ___T_009ab3ec);
    FUN_00797b80(auStack_10c);
    return 0;
  }
  uVar6 = 2;
  iVar4 = (**(code **)(*piVar2 + 8))(2,&iStack_114);
  if (iVar4 != 2) {
    FUN_0044a670(s_LoadQuestDone___pReader_>READ____009ab420);
    FUN_00797b80(&iStack_114);
    return 0;
  }
  sVar5 = CONCAT11((char)pcStack_11c,(char)((uint)pcStack_11c >> 8));
  while( true ) {
    if (sVar5 == 0) {
      (**(code **)(*DAT_00b5a69c + 8))(piVar2);
      return 1;
    }
    iVar4 = (**(code **)(*piVar2 + 8))(2,&puStack_120);
    if (iVar4 != 2) break;
    cVar1 = (**(code **)(*piVar3 + 4))
                      ((uVar6 & 0xff) << 8 | CONCAT22(extraout_var,(ushort)uVar6 >> 8));
    if (cVar1 == '\0') {
      FUN_0044a670(s_LoadQuestDone___pDiary_>Insert___009ab484);
      FUN_00797b80(&iStack_114);
      return 0;
    }
    sVar5 = sVar5 + -1;
  }
  FUN_0044a670(s_LoadQuestDone___pReader_>READ____009ab450);
  FUN_00797b80(&pcStack_11c);
  return 0;
}


// ==== FUN_004941a0 @ 0x004941a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004941a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ab4b8;
  _DAT_00b5aabc = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00494230 @ 0x00494230 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494230(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ab5fc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa60 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa60 = in_ECX;
  return;
}


// ==== FUN_00494280 @ 0x00494280 ====

uint FUN_00494280(undefined1 *param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined2 extraout_var;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined2 extraout_var_00;
  ushort uVar7;
  ushort uVar8;
  undefined2 uVar9;
  undefined4 uStack_124;
  undefined1 *puStack_11c;
  undefined4 uStack_110;
  undefined1 auStack_10c [8];
  undefined1 auStack_104 [4];
  undefined1 local_100 [256];
  
  if (*(int **)(param_2 + 0x60) == (int *)0x0) {
    puStack_11c = local_100;
    FUN_0044a580();
    uStack_124 = (undefined1 *)0x4942af;
    uVar1 = FUN_00797b80();
    return uVar1 & 0xffff0000;
  }
  piVar2 = (int *)(**(code **)(**(int **)(param_2 + 0x60) + 0x18))();
  if (piVar2 == (int *)0x0) {
    puStack_11c = &DAT_009ab5f4;
    uStack_124 = (undefined1 *)0x4942de;
    FUN_0044a580();
    uStack_124 = local_100;
    uVar1 = FUN_00797b80();
    return uVar1 & 0xffff0000;
  }
  puStack_11c = param_1;
  piVar3 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar3 == (int *)0x0) {
    uStack_124 = &DAT_009ab5f4;
    FUN_0044a580(auStack_104);
    uVar1 = FUN_00797b80(auStack_104);
    return uVar1 & 0xffff0000;
  }
  uStack_124 = (undefined1 *)0x4;
  (**(code **)(*piVar3 + 4))(0);
  uVar7 = 4;
  puStack_11c = (undefined1 *)0x0;
  uVar4 = (**(code **)(*piVar2 + 0x14))();
  uVar6 = extraout_ECX;
  uVar8 = 4;
  if ((short)uVar4 != 0) {
    do {
      uStack_110 = CONCAT22((short)((uint)uVar6 >> 0x10),
                            CONCAT11((char)uVar4,(char)((uint)uVar4 >> 8)));
      iVar5 = (**(code **)(*piVar3 + 8))(2,&uStack_110);
      if (iVar5 != 2) {
        FUN_0044a580(auStack_10c + -8,&DAT_009ab5f4,s_OnSendQuestDone___pWriter_>WRITE_009ab52c);
        FUN_00797b80(auStack_10c + -8);
        uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
        return uVar1 & 0xffff0000;
      }
      uStack_124 = (undefined1 *)((int)uStack_124 + 1);
      uVar7 = uVar8 + 2;
      uVar4 = (**(code **)(*piVar2 + 0x18))();
      uVar6 = extraout_ECX_00;
      uVar8 = uVar7;
    } while ((short)uVar4 != 0);
    if (1000 < uVar7) {
      auStack_10c[0] = (undefined1)uVar4;
      iVar5 = *DAT_00b5aa1c;
      uVar6 = FUN_0044a580(auStack_10c,s_QuestDone__Save_wTotalSize__d__>_009ab560,uVar7);
      (**(code **)(iVar5 + 4))(uVar6);
    }
  }
  uVar9 = 0;
  (**(code **)(*piVar3 + 4))(0,0);
  iVar5 = (**(code **)(*piVar3 + 8))(2,auStack_10c + -0x14);
  if (iVar5 != 2) {
    FUN_0044a670(s_OnSendSkill___pWriter_>WRITE__wC_009ab588);
    FUN_00797b80(&puStack_11c);
    uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
    return uVar1 & 0xffff0000;
  }
  uStack_124 = (undefined1 *)
               CONCAT22(extraout_var_00,CONCAT11((char)uVar9,(char)((ushort)uVar9 >> 8)));
  iVar5 = (**(code **)(*piVar3 + 8))(2,&uStack_124);
  if (iVar5 == 2) {
    (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
    return CONCAT22(extraout_var,uVar7);
  }
  FUN_0044a670(s_OnSendSkill___pWriter_>WRITE__bT_009ab5bc);
  FUN_00797b80(&uStack_124);
  uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
  return uVar1 & 0xffff0000;
}


// ==== FUN_004944e0 @ 0x004944e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004944e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ab5fc;
  _DAT_00b5aa60 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00494570 @ 0x00494570 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494570(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ab9f4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aab8 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aab8 = in_ECX;
  return;
}


// ==== FUN_004945c0 @ 0x004945c0 ====

undefined4 FUN_004945c0(uint *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *piVar6;
  undefined2 unaff_SI;
  uint uVar7;
  int *piVar8;
  int *piStack_148;
  undefined4 uStack_144;
  char *pcStack_140;
  undefined1 auStack_13c [4];
  undefined4 uStack_138;
  undefined1 auStack_128 [4];
  undefined1 auStack_124 [4];
  undefined1 auStack_120 [4];
  undefined1 auStack_11c [4];
  undefined1 auStack_118 [4];
  undefined1 auStack_114 [4];
  undefined1 auStack_110 [4];
  undefined1 auStack_10c [4];
  int iStack_108;
  undefined1 auStack_104 [248];
  int *piStack_c;
  int *piStack_4;
  
  uStack_138 = param_1;
  auStack_13c = (undefined1  [4])0x4945dc;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  piVar8 = DAT_00b5aa1c;
  if (piVar2 == (int *)0x0) {
    auStack_13c = (undefined1  [4])0x4945f6;
    auStack_13c = (undefined1  [4])(**(code **)(*param_1 + 0x70))();
    uStack_144 = auStack_104;
    pcStack_140 = s_UserName____s__LoadBuddyList___p_009ab604;
    auStack_104[0] = 0;
    iVar3 = *piVar8;
    piStack_148 = (int *)0x49460c;
    auStack_13c = (undefined1  [4])FUN_0044a580();
    pcStack_140 = (char *)0x494615;
    (**(code **)(iVar3 + 4))();
    pcStack_140 = s_LoadBuddyList___pReader_is_NULL_009ab634;
    piStack_148 = &iStack_108;
    uStack_144 = &DAT_009ab9ec;
    FUN_0044a580();
    FUN_00797b80(&iStack_108);
    return 0;
  }
  auStack_13c = (undefined1  [4])auStack_128;
  pcStack_140 = (char *)0x2;
  uStack_144 = (undefined1 *)0x494652;
  iVar3 = (**(code **)(*piVar2 + 8))();
  piVar8 = DAT_00b5aa1c;
  if (iVar3 == 2) {
    if (*param_1 < (uint)CONCAT11((char)unaff_SI,(char)((ushort)unaff_SI >> 8))) {
      uStack_144 = (undefined1 *)0x4946b3;
      uStack_144 = (undefined1 *)(**(code **)(*piStack_4 + 0x70))();
      piStack_148 = (int *)s_UserName____s__LoadBuddyList___w_009ab6d0;
      auStack_10c[0] = 0;
      iVar3 = *piVar8;
      uStack_144 = (undefined1 *)FUN_0044a580(auStack_10c);
      piStack_148 = (int *)0x4946d2;
      (**(code **)(iVar3 + 4))();
      piStack_148 = (int *)s_LoadBuddyList___wConvertSize_>_r_009ab710;
    }
    else {
      uStack_144 = auStack_13c + 10;
      piStack_148 = (int *)0x1;
      iVar3 = (**(code **)(*piVar2 + 8))();
      piVar8 = DAT_00b5aa1c;
      if (iVar3 == 1) {
        if ((int *)piStack_c[0x1b] == (int *)0x0) {
          uVar4 = (**(code **)(*piStack_c + 0x70))();
          auStack_114[0] = 0;
          iVar3 = *piVar8;
          uVar4 = FUN_0044a580(auStack_114,s_UserName____s__LoadBuddyList___p_009ab7b4,uVar4);
          (**(code **)(iVar3 + 4))(uVar4);
          FUN_0044a670(s_LoadBuddyList___pManager_is_NULL_009ab7e8);
          FUN_00797b80(auStack_118);
          (**(code **)(*DAT_00b5a69c + 8))(piVar2);
          return 0;
        }
        iVar3 = (**(code **)(*(int *)piStack_c[0x1b] + 0x14))();
        piVar8 = DAT_00b5aa1c;
        if (iVar3 == 0) {
          uVar4 = (**(code **)(*piStack_c + 0x70))();
          auStack_114[0] = 0;
          iVar3 = *piVar8;
          uVar4 = FUN_0044a580(auStack_114,s_UserName____s__LoadBuddyList___p_009ab80c,uVar4);
          (**(code **)(iVar3 + 4))(uVar4);
          FUN_0044a670(s_LoadBuddyList___pMessenger_is_NU_009ab840);
          FUN_00797b80(auStack_118);
          (**(code **)(*DAT_00b5a69c + 8))(piVar2);
          return 0;
        }
        cVar1 = auStack_13c[2];
        while( true ) {
          if (cVar1 == '\0') {
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 1;
          }
          piVar8 = (int *)(auStack_13c + 3);
          iVar3 = (**(code **)(*piVar2 + 8))(1);
          piVar6 = DAT_00b5aa1c;
          if (iVar3 != 1) break;
          uVar7 = (uint)(byte)(uStack_144._3_1_ - 1);
          uStack_138 = (uint *)((uint)uStack_138 & 0xffffff00);
          uVar5 = (**(code **)(*piVar2 + 8))(uVar7,&uStack_138);
          piVar6 = DAT_00b5aa1c;
          if (uVar5 != uVar7) {
            uVar4 = (**(code **)(*piStack_c + 0x70))();
            auStack_124[0] = 0;
            iVar3 = *piVar6;
            uVar4 = FUN_0044a580(auStack_124,s_UserName____s__LoadBuddyList___p_009ab8f8,uVar4);
            (**(code **)(iVar3 + 4))(uVar4);
            FUN_0044a670(s_LoadBuddyList_pReader_>Read__byN_009ab958);
            FUN_00797b80(auStack_128);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          auStack_13c[uVar7 - 4] = 0;
          piVar6 = (int *)(**(code **)(*DAT_00b5abe4 + 0xc))(1,0);
          (**(code **)(*piVar6 + 8))(&piStack_148);
          cVar1 = (**(code **)(*piVar8 + 4))(piVar6);
          if (cVar1 == '\0') {
            auStack_114[0] = 0;
            uVar4 = FUN_0044a580(auStack_114,s_LoadBuddyList___pMessenger_>AddF_009ab9a0,
                                 auStack_128 + -8);
            FUN_00797b80(uVar4);
          }
          cVar1 = auStack_13c[2] + -1;
          auStack_13c[2] = cVar1;
        }
        uVar4 = (**(code **)(*piStack_c + 0x70))();
        auStack_11c[0] = 0;
        iVar3 = *piVar6;
        uVar4 = FUN_0044a580(auStack_11c,s_UserName____s__LoadBuddyList___p_009ab868,uVar4);
        (**(code **)(iVar3 + 4))(uVar4);
        FUN_0044a670(s_LoadBuddyList_pReader_>READ____b_009ab8b8);
        FUN_00797b80(auStack_120);
        (**(code **)(*DAT_00b5a69c + 8))(piVar2);
        return 0;
      }
      uVar4 = (**(code **)(*piStack_c + 0x70))();
      auStack_114[0] = 0;
      iVar3 = *piVar8;
      uVar4 = FUN_0044a580(auStack_114,s_UserName____s__LoadBuddyList___p_009ab744,uVar4);
      (**(code **)(iVar3 + 4))(uVar4);
      piStack_148 = (int *)s_LoadBuddyList___pReader_>READ____009ab784;
    }
  }
  else {
    uStack_144 = (undefined1 *)0x494669;
    uStack_144 = (undefined1 *)(**(code **)(*piStack_4 + 0x70))();
    piStack_148 = (int *)s_UserName____s__LoadBuddyList___R_009ab658;
    auStack_10c[0] = 0;
    iVar3 = *piVar8;
    uStack_144 = (undefined1 *)FUN_0044a580(auStack_10c);
    piStack_148 = (int *)0x494688;
    (**(code **)(iVar3 + 4))();
    piStack_148 = (int *)s_LoadBuddyList___Reader_>READ___T_009ab698;
  }
  FUN_0044a580(auStack_110,&DAT_009ab9ec);
  FUN_00797b80(auStack_110);
  piStack_148 = piVar2;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 0;
}


// ==== FUN_004949c0 @ 0x004949c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004949c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ab9f4;
  _DAT_00b5aab8 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00494a40 @ 0x00494a40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494a40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009abb60;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa5c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa5c = in_ECX;
  return;
}


// ==== FUN_00494a90 @ 0x00494a90 ====

uint FUN_00494a90(undefined4 param_1,int param_2)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined2 extraout_var;
  undefined2 uVar7;
  int iVar8;
  char *pcVar9;
  undefined4 uStack_124;
  undefined4 uStack_120;
  undefined4 uStack_114;
  undefined1 auStack_104 [4];
  undefined1 local_100 [256];
  
  if (*(int **)(param_2 + 0x6c) == (int *)0x0) {
    uStack_114 = local_100;
    FUN_0044a580();
    uVar1 = FUN_00797b80();
    return uVar1 & 0xffff0000;
  }
  piVar2 = (int *)(**(code **)(**(int **)(param_2 + 0x6c) + 0x14))();
  if (piVar2 == (int *)0x0) {
    uStack_114 = &DAT_009abb58;
    FUN_0044a580();
    uStack_120 = (undefined1 *)0x494af8;
    uVar1 = FUN_00797b80();
    return uVar1 & 0xffff0000;
  }
  uStack_114 = (undefined1 *)param_1;
  piVar3 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar3 == (int *)0x0) {
    uStack_120 = auStack_104;
    uStack_124 = (undefined1 *)0x494b36;
    FUN_0044a580();
    uStack_124 = auStack_104;
    uVar1 = FUN_00797b80();
    return uVar1 & 0xffff0000;
  }
  uStack_120 = (undefined1 *)0x3;
  uStack_124 = (undefined1 *)0x0;
  (**(code **)(*piVar3 + 4))();
  uStack_114._0_3_ = (uint3)(ushort)uStack_114;
  uVar7 = 3;
  piVar4 = (int *)(**(code **)(*piVar2 + 0x14))();
  if (piVar4 != (int *)0x0) {
    iVar8 = 3;
    do {
      iVar5 = (**(code **)(*piVar4 + 0xc))();
      uVar1 = 0;
      do {
        if (*(char *)(uVar1 + iVar5) == '\0') goto LAB_00494ba0;
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x19);
      uVar1 = 0;
LAB_00494ba0:
      uStack_114 = (undefined1 *)CONCAT13((char)uVar1 + '\x01',(uint3)uStack_114);
      iVar5 = (**(code **)(*piVar3 + 8))(1,(int)&uStack_114 + 3);
      if (iVar5 != 1) {
        pcVar9 = s_SaveBuddyList_pWriter_>WRITE__pP_009aba68;
LAB_00494c84:
        FUN_0044a580(&uStack_114,&DAT_009abb58,pcVar9);
        FUN_00797b80(&uStack_114);
        uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
        return uVar1 & 0xffff0000;
      }
      iVar5 = (**(code **)(*piVar4 + 0xc))();
      uVar1 = 0;
      do {
        if (*(char *)(uVar1 + iVar5) == '\0') goto LAB_00494be4;
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x19);
      uVar1 = 0;
LAB_00494be4:
      uVar6 = (**(code **)(*piVar3 + 8))(uVar1,iVar5);
      if (uVar6 != uVar1) {
        pcVar9 = s_pWriter_>Write__ulUserNameCount__009abaa8;
        goto LAB_00494c84;
      }
      iVar8 = iVar8 + 1 + uVar1;
      uVar7 = (undefined2)iVar8;
      piVar4 = (int *)(**(code **)(*piVar2 + 0x18))();
    } while (piVar4 != (int *)0x0);
  }
  (**(code **)(*piVar3 + 4))(0,0);
  iVar8 = (**(code **)(*piVar3 + 8))(2,auStack_104 + -0x14);
  if (iVar8 != 2) {
    FUN_0044a670(s_SaveBuddyList___pWriter_>WRITE__w_009abaec);
    FUN_00797b80(auStack_104 + -0x18);
    uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
    return uVar1 & 0xffff0000;
  }
  iVar8 = (**(code **)(*piVar3 + 8))(1,(int)&uStack_124 + 2);
  if (iVar8 == 1) {
    (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
    return CONCAT22(extraout_var,uVar7);
  }
  FUN_0044a670(s_SaveBuddyList___pWriter_>WRITE__b_009abb20);
  FUN_00797b80(&uStack_124);
  uVar1 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
  return uVar1 & 0xffff0000;
}


// ==== FUN_00494d30 @ 0x00494d30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494d30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009abb60;
  _DAT_00b5aa5c = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00494d60 @ 0x00494d60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494d60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009abb68;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aab4 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aab4 = in_ECX;
  return;
}


// ==== FUN_00494d90 @ 0x00494d90 ====

undefined4 FUN_00494d90(undefined4 param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(**(int **)(param_3 + 0x70) + 0x14))();
  (**(code **)(*piVar1 + 0x24))(param_1);
  (**(code **)(*piVar1 + 0x2c))(param_1);
  return 1;
}


// ==== FUN_00494de0 @ 0x00494de0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494de0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009abb68;
  _DAT_00b5aab4 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00494e80 @ 0x00494e80 ====

uint FUN_00494e80(void)

{
  uint in_ECX;
  
  return in_ECX >> 0x18 |
         CONCAT31((int3)in_ECX,(char)(in_ECX >> 8)) << 0x10 | (in_ECX >> 0x10 & 0xff) << 8;
}


// ==== FUN_00494ed0 @ 0x00494ed0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00494ed0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ac720;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aab0 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aab0 = in_ECX;
  return;
}


// ==== FUN_00494f20 @ 0x00494f20 ====

/* WARNING: Type propagation algorithm not settling */

undefined4 FUN_00494f20(uint *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  undefined4 uVar6;
  int *piVar7;
  ushort uVar8;
  uint uVar9;
  int *piVar10;
  undefined4 *in_stack_fffff844;
  int *in_stack_fffff848;
  int *in_stack_fffff850;
  uint in_stack_fffff854;
  undefined4 uStack_79c;
  undefined4 uStack_798;
  undefined4 uStack_794;
  undefined1 *puStack_790;
  undefined4 uStack_78c;
  undefined4 *puStack_788;
  undefined4 uStack_784;
  undefined4 uStack_780;
  undefined4 uStack_77c;
  undefined4 uStack_778;
  undefined4 uStack_774;
  undefined1 *puStack_770;
  int *piStack_76c;
  undefined1 *puStack_768;
  int *piStack_764;
  undefined4 uStack_760;
  undefined4 uStack_75c;
  undefined1 *puStack_758;
  int *piStack_754;
  undefined4 uStack_750;
  undefined4 uStack_748;
  undefined4 uStack_744;
  undefined4 uStack_740;
  undefined1 uStack_72e;
  undefined4 uStack_72d;
  undefined1 auStack_729 [4];
  undefined1 uStack_725;
  undefined1 auStack_724 [3];
  undefined1 auStack_721 [4];
  undefined4 uStack_71d;
  undefined1 uStack_719;
  undefined4 uStack_718;
  undefined1 auStack_711 [4];
  undefined1 auStack_70d [4];
  undefined1 auStack_709 [4];
  undefined1 auStack_705 [4];
  undefined1 auStack_701 [4];
  undefined1 auStack_6fd [4];
  undefined1 auStack_6f9 [4];
  undefined1 uStack_6f5;
  undefined1 auStack_588 [20];
  undefined1 auStack_574 [44];
  undefined1 auStack_548 [12];
  undefined1 auStack_53c [32];
  undefined1 auStack_51c [8];
  undefined1 auStack_514 [12];
  undefined1 auStack_508 [10];
  undefined1 uStack_4fe;
  undefined1 auStack_4f8 [24];
  uint uStack_4e0;
  undefined1 auStack_4c3 [571];
  int *piStack_288;
  undefined1 auStack_284 [72];
  undefined1 auStack_23c [568];
  int *piStack_4;
  
  uStack_740 = param_1;
  uStack_744 = (undefined1 *)0x494f3c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  piVar5 = DAT_00b5aa1c;
  if (piVar2 == (int *)0x0) {
    uStack_744 = (undefined1 *)0x494f56;
    uStack_744 = (undefined1 *)(**(code **)(*param_1 + 0x70))();
    uStack_748 = s_UserName____s__LoadMailList___pR_009abb74;
    uStack_6f5 = 0;
    iVar3 = *piVar5;
    uStack_750 = (char *)0x494f6c;
    uStack_744 = (undefined1 *)FUN_0044a580();
    uStack_748 = (char *)0x494f75;
    (**(code **)(iVar3 + 4))();
    uStack_748 = s_LoadMailList___pReader_is_NULL_009abba4;
    uStack_750 = auStack_6f9;
    piStack_754 = (int *)0x494f89;
    FUN_0044a580();
    piStack_754 = (int *)auStack_6f9;
    puStack_758 = (undefined1 *)0x494f93;
    FUN_00797b80();
    return 0;
  }
  uStack_744 = auStack_724;
  uStack_748 = (char *)0x2;
  iVar3 = (**(code **)(*piVar2 + 8))();
  piVar5 = DAT_00b5aa1c;
  if (iVar3 != 2) {
    (**(code **)(*piStack_4 + 0x70))();
    piStack_754 = (int *)auStack_6fd;
    uStack_750 = s_UserName____s__LoadMailList___pR_009abbc8;
    auStack_6fd[0] = 0;
    iVar3 = *piVar5;
    puStack_758 = (undefined1 *)0x494fdf;
    FUN_0044a580();
    uStack_750 = (char *)0x494fe8;
    (**(code **)(iVar3 + 4))();
    uStack_750 = s_LoadMailList___pReader_>READ___T_009abc08;
    puStack_758 = auStack_701;
    piStack_754 = (int *)&DAT_009ac718;
    uStack_75c = (char *)0x494ffc;
    FUN_0044a580();
    uStack_75c = auStack_701;
    uStack_760 = (undefined1 *)0x495006;
    FUN_00797b80();
    piStack_754 = (int *)0x495015;
    uStack_750 = (char *)piVar2;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  uVar8 = CONCAT11((char)uStack_72d._1_2_,(char)((ushort)uStack_72d._1_2_ >> 8));
  if (*param_1 < (uint)uVar8) {
    (**(code **)(*piStack_4 + 0x70))();
    piStack_754 = (int *)auStack_6fd;
    uStack_750 = s_UserName____s__LoadMailList___wC_009abc3c;
    auStack_6fd[0] = 0;
    iVar3 = *piVar5;
    puStack_758 = (undefined1 *)0x49505f;
    FUN_0044a580();
    uStack_750 = (char *)0x495068;
    (**(code **)(iVar3 + 4))();
    uStack_750 = s_LoadMailList___wConvertSize_>_rB_009abc7c;
    puStack_758 = auStack_701;
    piStack_754 = (int *)&DAT_009ac718;
    uStack_75c = (char *)0x49507c;
    FUN_0044a580();
    uStack_75c = auStack_701;
    uStack_760 = (undefined1 *)0x495086;
    FUN_00797b80();
    piStack_754 = (int *)0x495095;
    uStack_750 = (char *)piVar2;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  if (uVar8 < 3) {
    (**(code **)(*piStack_4 + 0x70))();
    piStack_754 = (int *)auStack_6fd;
    uStack_750 = s_UserName____s__wConvertSize_<__2_009abcac;
    auStack_6fd[0] = 0;
    iVar3 = *piVar5;
    puStack_758 = (undefined1 *)0x4950d1;
    FUN_0044a580();
    uStack_750 = (char *)0x4950da;
    (**(code **)(iVar3 + 4))();
    uStack_750 = s_LoadMailList___wConvertSize_<__2_009abcd0;
    puStack_758 = auStack_701;
    piStack_754 = (int *)&DAT_009ac718;
    uStack_75c = (char *)0x4950ee;
    FUN_0044a580();
    uStack_75c = auStack_701;
    uStack_760 = (undefined1 *)0x4950f8;
    FUN_00797b80();
    piStack_754 = (int *)0x495107;
    uStack_750 = (char *)piVar2;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 1;
  }
  if ((int *)piStack_4[0x1c] == (int *)0x0) {
    uStack_750 = (char *)0x495131;
    uStack_750 = (char *)(**(code **)(*piStack_4 + 0x70))();
    puStack_758 = auStack_6fd;
    piStack_754 = (int *)s_UserName____s__LoadMailList___pM_009abcf4;
    auStack_6fd[0] = 0;
    iVar3 = *piVar5;
    uStack_75c = (char *)0x495148;
    uStack_750 = (char *)FUN_0044a580();
    piStack_754 = (int *)0x495151;
    (**(code **)(iVar3 + 4))();
    piStack_754 = (int *)s_LoadMailList___pManager_is_NULL_009abd24;
  }
  else {
    uStack_750 = (char *)0x495160;
    uStack_718 = (**(code **)(*(int *)piStack_4[0x1c] + 0x14))();
    piVar5 = DAT_00b5aa1c;
    if (uStack_718 == 0) {
      uStack_750 = (char *)0x495175;
      uStack_750 = (char *)(**(code **)(*piStack_4 + 0x70))();
      puStack_758 = auStack_6fd;
      piStack_754 = (int *)s_UserName____s__LoadMailList___pM_009abd48;
      auStack_6fd[0] = 0;
      iVar3 = *piVar5;
      uStack_75c = (char *)0x49518c;
      uStack_750 = (char *)FUN_0044a580();
      piStack_754 = (int *)0x495195;
      (**(code **)(iVar3 + 4))();
      piStack_754 = (int *)s_LoadMailList___pMailBox_is_NULL_009abd78;
    }
    else {
      uStack_750 = auStack_508;
      auStack_508[0] = 0;
      piStack_754 = (int *)0x12;
      puStack_758 = (undefined1 *)0x4951b7;
      iVar3 = (**(code **)(*piVar2 + 8))();
      piVar5 = DAT_00b5aa1c;
      if (iVar3 != 0x12) {
        puStack_758 = (undefined1 *)0x4951c9;
        puStack_758 = (undefined1 *)(**(code **)(*piStack_4 + 0x70))();
        uStack_760 = auStack_705;
        uStack_75c = s_UserName____s__LoadMailList___pR_009abda0;
        auStack_705[0] = 0;
        iVar3 = *piVar5;
        piStack_764 = (int *)0x4951e0;
        puStack_758 = (undefined1 *)FUN_0044a580();
        uStack_75c = (char *)0x4951e9;
        (**(code **)(iVar3 + 4))();
        uStack_75c = s_LoadMailList___pReader_>Read__by_009abdf0;
        uStack_760 = (undefined1 *)0x4951f7;
        FUN_0044a670();
        uStack_75c = auStack_709;
        uStack_760 = (undefined1 *)0x495201;
        FUN_00797b80();
        uStack_760 = (undefined1 *)0x495210;
        uStack_75c = (char *)piVar2;
        (**(code **)(*DAT_00b5a69c + 8))();
        return 0;
      }
      puStack_758 = (undefined1 *)((int)&uStack_744 + 3);
      uStack_4fe = 0;
      uStack_75c = (char *)0x1;
      uStack_760 = (undefined1 *)0x495234;
      iVar3 = (**(code **)(*piVar2 + 8))();
      piVar5 = DAT_00b5aa1c;
      if (iVar3 != 1) {
        uStack_760 = (undefined1 *)0x495246;
        uStack_760 = (undefined1 *)(**(code **)(*piStack_4 + 0x70))();
        puStack_768 = auStack_70d;
        piStack_764 = (int *)s_UserName____s__LoadMailList___pR_009abe30;
        auStack_70d[0] = 0;
        iVar3 = *piVar5;
        piStack_76c = (int *)0x49525d;
        uStack_760 = (undefined1 *)FUN_0044a580();
        piStack_764 = (int *)0x495266;
        (**(code **)(iVar3 + 4))();
        piStack_764 = (int *)s_LoadMailList___pReader_>READ____b_009abe70;
        puStack_768 = (undefined1 *)0x495274;
        FUN_0044a670();
        piStack_764 = (int *)auStack_711;
        puStack_768 = (undefined1 *)0x49527e;
        FUN_00797b80();
        puStack_768 = (undefined1 *)0x49528d;
        piStack_764 = piVar2;
        (**(code **)(*DAT_00b5a69c + 8))();
        return 0;
      }
      uStack_760 = (undefined1 *)((int)&uStack_72d + 1);
      piStack_764 = (int *)0x1;
      puStack_768 = (undefined1 *)0x4952aa;
      iVar3 = (**(code **)(*piVar2 + 8))();
      piVar5 = DAT_00b5aa1c;
      if (iVar3 != 1) {
        puStack_768 = (undefined1 *)0x4952bc;
        puStack_768 = (undefined1 *)(**(code **)(*piStack_4 + 0x70))();
        puStack_770 = (undefined1 *)((int)&uStack_718 + 3);
        piStack_76c = (int *)s_UserName____s__LoadMailList___pR_009abea0;
        uStack_718 = uStack_718 & 0xffffff;
        iVar3 = *piVar5;
        uStack_774 = (char *)0x4952d3;
        puStack_768 = (undefined1 *)FUN_0044a580();
        piStack_76c = (int *)0x4952dc;
        (**(code **)(iVar3 + 4))();
        piStack_76c = (int *)s_LoadMailList___pReader_>READ____b_009abee0;
        puStack_770 = (undefined1 *)0x4952ea;
        FUN_0044a670();
        piStack_76c = (int *)&uStack_719;
        puStack_770 = (undefined1 *)0x4952f4;
        FUN_00797b80();
        puStack_770 = (undefined1 *)0x495303;
        piStack_76c = piVar2;
        (**(code **)(*DAT_00b5a69c + 8))();
        return 0;
      }
      puStack_768 = auStack_729 + -0x23;
      piStack_76c = (int *)0x2;
      puStack_770 = (undefined1 *)0x495320;
      iVar3 = (**(code **)(*piVar2 + 8))();
      piVar5 = DAT_00b5aa1c;
      if (iVar3 != 2) {
        puStack_770 = (undefined1 *)0x495332;
        puStack_770 = (undefined1 *)(**(code **)(*piStack_4 + 0x70))();
        uStack_778 = &uStack_71d;
        uStack_774 = s_UserName____s__LoadMailList___pR_009abf10;
        uStack_71d._0_1_ = 0;
        iVar3 = *piVar5;
        uStack_77c = (char *)0x495349;
        puStack_770 = (undefined1 *)FUN_0044a580();
        uStack_774 = (char *)0x495352;
        (**(code **)(iVar3 + 4))();
        uStack_774 = s_LoadMailList___pReader_>READ____w_009abf54;
        uStack_778 = (undefined4 *)0x495360;
        FUN_0044a670();
        uStack_774 = auStack_721;
        uStack_778 = (undefined4 *)0x49536a;
        FUN_00797b80();
        uStack_778 = (undefined4 *)0x495379;
        uStack_774 = (char *)piVar2;
        (**(code **)(*DAT_00b5a69c + 8))();
        return 0;
      }
      uVar8 = CONCAT11((char)piStack_754,(char)((uint)piStack_754 >> 8));
      if ((uVar8 < 0x19) && (uVar8 != 0)) {
        uVar9 = (uint)uVar8;
        puStack_770 = auStack_514;
        auStack_514[0] = 0;
        uStack_778 = (undefined4 *)0x4953c2;
        uStack_774 = (char *)uVar9;
        uVar4 = (**(code **)(*piVar2 + 8))();
        piVar5 = DAT_00b5aa1c;
        if (uVar4 != uVar9) {
          uStack_778 = (undefined4 *)0x4953d3;
          uStack_778 = (undefined4 *)(**(code **)(*piStack_4 + 0x70))();
          uStack_780 = (undefined4 *)&uStack_725;
          uStack_77c = s_UserName____s__LoadMailList___pR_009abfe0;
          uStack_725 = 0;
          iVar3 = *piVar5;
          uStack_784 = (char *)0x4953e9;
          uStack_778 = (undefined4 *)FUN_0044a580();
          uStack_77c = (char *)0x4953f2;
          (**(code **)(iVar3 + 4))();
          uStack_77c = s_LoadMailList___pReader_>Read__wS_009ac050;
          uStack_780 = (undefined4 *)0x495400;
          FUN_0044a670();
          uStack_77c = auStack_729;
          uStack_780 = (undefined4 *)0x49540a;
          FUN_00797b80();
          return 0;
        }
        uStack_778 = &uStack_750;
        auStack_51c[uVar9] = 0;
        uStack_77c = (char *)0x2;
        uStack_780 = (undefined4 *)0x495431;
        iVar3 = (**(code **)(*piVar2 + 8))();
        piVar5 = DAT_00b5aa1c;
        if (iVar3 != 2) {
          uStack_780 = (undefined4 *)0x495443;
          uStack_780 = (undefined4 *)(**(code **)(*piStack_4 + 0x70))();
          puStack_788 = &uStack_72d;
          uStack_784 = s_UserName____s__LoadMailList___pR_009ac0b0;
          uStack_72d._0_1_ = 0;
          iVar3 = *piVar5;
          uStack_78c = (char *)0x495459;
          uStack_780 = (undefined4 *)FUN_0044a580();
          uStack_784 = (char *)0x495462;
          (**(code **)(iVar3 + 4))();
          uStack_784 = s_LoadMailList___pReader_>Read__wT_009ac0f4;
          puStack_788 = (undefined4 *)0x495470;
          FUN_0044a670();
          uStack_784 = auStack_729 + -8;
          puStack_788 = (undefined4 *)0x49547a;
          FUN_00797b80();
          return 0;
        }
        uVar8 = CONCAT11((char)puStack_758,(char)((uint)puStack_758 >> 8));
        if (uVar8 < 0x33) {
          auStack_4f8[0] = 0;
          if (uVar8 == 0) {
            uStack_780 = (undefined4 *)&DAT_009ac18c;
            uStack_784 = (char *)0x4954f3;
            FUN_00495db0();
            uStack_780 = (undefined4 *)auStack_4c3;
            uStack_784 = (char *)0x495507;
            FUN_00495ce0();
          }
          else {
            uVar9 = (uint)uVar8;
            uStack_780 = (undefined4 *)auStack_4f8;
            puStack_788 = (undefined4 *)0x49551f;
            uStack_784 = (char *)uVar9;
            uVar4 = (**(code **)(*piVar2 + 8))();
            piVar5 = DAT_00b5aa1c;
            if (uVar4 != uVar9) {
              uStack_780 = (undefined4 *)0x495530;
              uStack_780 = (undefined4 *)(**(code **)(*piStack_4 + 0x70))();
              puStack_788 = &uStack_72d;
              uStack_784 = s_UserName____s__LoadMailList___pR_009ac190;
              uStack_72d._0_1_ = 0;
              iVar3 = *piVar5;
              uStack_78c = (char *)0x495547;
              uStack_780 = (undefined4 *)FUN_0044a580();
              uStack_784 = (char *)0x495550;
              (**(code **)(iVar3 + 4))();
              uStack_784 = s_LoadMailList___pReader_>Read__wR_009ac1f0;
              puStack_788 = (undefined4 *)0x49555e;
              FUN_0044a670();
              uStack_784 = auStack_729 + -8;
              puStack_788 = (undefined4 *)0x495568;
              FUN_00797b80();
              puStack_788 = (undefined4 *)0x495577;
              uStack_784 = (char *)piVar2;
              (**(code **)(*DAT_00b5a69c + 8))();
              return 0;
            }
            auStack_4f8[uVar9] = 0;
          }
          uStack_780 = &uStack_760;
          uStack_784 = (char *)0x2;
          puStack_788 = (undefined4 *)0x49559b;
          iVar3 = (**(code **)(*piVar2 + 8))();
          piVar5 = DAT_00b5aa1c;
          if (iVar3 != 2) {
            puStack_788 = (undefined4 *)0x4955ad;
            puStack_788 = (undefined4 *)(**(code **)(*piStack_4 + 0x70))();
            puStack_790 = auStack_729 + -0xc;
            uStack_78c = s_UserName____s__LoadMailList___pR_009ac248;
            iVar3 = *piVar5;
            uStack_794 = (char *)0x4955c4;
            puStack_788 = (undefined4 *)FUN_0044a580();
            uStack_78c = (char *)0x4955cd;
            (**(code **)(iVar3 + 4))();
            uStack_78c = s_LoadMailList___pReader_>READ____w_009ac290;
            puStack_790 = (undefined1 *)0x4955db;
            FUN_0044a670();
            uStack_78c = auStack_729 + -0x10;
            puStack_790 = (undefined1 *)0x4955e5;
            FUN_00797b80();
            puStack_790 = (undefined1 *)0x4955f4;
            uStack_78c = (char *)piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          uVar8 = CONCAT11((char)puStack_768,(char)((uint)puStack_768 >> 8));
          if (500 < uVar8) {
            puStack_788 = (undefined4 *)0x495623;
            puStack_788 = (undefined4 *)(**(code **)(*piStack_4 + 0x70))();
            puStack_790 = auStack_729 + -0xc;
            uStack_78c = s_UserName____s__LoadMailList___wC_009ac2c4;
            iVar3 = *piVar5;
            uStack_794 = (char *)0x49563a;
            puStack_788 = (undefined4 *)FUN_0044a580();
            uStack_78c = (char *)0x495643;
            (**(code **)(iVar3 + 4))();
            uStack_78c = s_LoadMailList___wConContentsSize_>_009ac2fc;
            puStack_790 = (undefined1 *)0x495651;
            FUN_0044a670();
            uStack_78c = auStack_729 + -0x10;
            puStack_790 = (undefined1 *)0x49565b;
            FUN_00797b80();
            puStack_790 = (undefined1 *)0x49566a;
            uStack_78c = (char *)piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          auStack_23c[0] = 0;
          if (uVar8 == 0) {
            puStack_788 = (undefined4 *)&DAT_009ac324;
            uStack_78c = (char *)0x495693;
            FUN_00495dd0();
            puStack_788 = (undefined4 *)(auStack_729 + -0xc);
            uStack_78c = (char *)0x4956a4;
            FUN_00495d10();
          }
          else {
            uVar9 = (uint)uVar8;
            puStack_788 = (undefined4 *)auStack_23c;
            puStack_790 = (undefined1 *)0x4956bc;
            uStack_78c = (char *)uVar9;
            uVar4 = (**(code **)(*piVar2 + 8))();
            piVar5 = DAT_00b5aa1c;
            if (uVar4 != uVar9) {
              puStack_788 = (undefined4 *)0x4956cd;
              puStack_788 = (undefined4 *)(**(code **)(*piStack_4 + 0x70))();
              puStack_790 = auStack_729 + -0xc;
              uStack_78c = s_UserName____s__LoadMailList___pR_009ac328;
              iVar3 = *piVar5;
              uStack_794 = (char *)0x4956e4;
              puStack_788 = (undefined4 *)FUN_0044a580();
              uStack_78c = (char *)0x4956ed;
              (**(code **)(iVar3 + 4))();
              uStack_78c = s_LoadMailList___pReader_>Read__wR_009ac390;
              puStack_790 = (undefined1 *)0x4956fb;
              FUN_0044a670();
              uStack_78c = auStack_729 + -0x10;
              puStack_790 = (undefined1 *)0x495705;
              FUN_00797b80();
              puStack_790 = (undefined1 *)0x495714;
              uStack_78c = (char *)piVar2;
              (**(code **)(*DAT_00b5a69c + 8))();
              return 0;
            }
            auStack_23c[uVar9] = 0;
          }
          puStack_788 = &uStack_748;
          uStack_78c = (char *)0x4;
          puStack_790 = (undefined1 *)0x495738;
          iVar3 = (**(code **)(*piVar2 + 8))();
          piVar5 = DAT_00b5aa1c;
          if (iVar3 != 4) {
            puStack_790 = (undefined1 *)0x49574a;
            puStack_790 = (undefined1 *)(**(code **)(*piStack_4 + 0x70))();
            uStack_798 = (int)&uStack_740 + 3;
            uStack_794 = s_UserName____s__LoadMailList___pR_009ac3f0;
            uStack_740 = (uint *)((uint)uStack_740 & 0xffffff);
            iVar3 = *piVar5;
            uStack_79c = (char *)0x495761;
            puStack_790 = (undefined1 *)FUN_0044a580();
            uStack_794 = (char *)0x49576a;
            (**(code **)(iVar3 + 4))();
            uStack_794 = s_LoadMailList___pReader_>READ____d_009ac434;
            uStack_798 = 0x495778;
            FUN_0044a670();
            uStack_794 = (char *)((int)&uStack_744 + 3);
            uStack_798 = 0x495782;
            FUN_00797b80();
            uStack_798 = 0x495791;
            uStack_794 = (char *)piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          puStack_790 = (undefined1 *)0x4957a9;
          uStack_778 = (undefined4 *)FUN_00494e80();
          puStack_790 = (undefined1 *)((int)&uStack_77c + 2);
          uStack_794 = (char *)0x1;
          uStack_798 = 0x4957bb;
          iVar3 = (**(code **)(*piVar2 + 8))();
          piVar5 = DAT_00b5aa1c;
          if (iVar3 != 1) {
            uStack_798 = 0x4957cd;
            uStack_798 = (**(code **)(*piStack_4 + 0x70))();
            uStack_79c = s_UserName____s__LoadMailList___pR_009ac468;
            uStack_748 = (char *)((uint)uStack_748 & 0xffffff);
            iVar3 = *piVar5;
            uStack_798 = FUN_0044a580((int)&uStack_748 + 3);
            uStack_79c = (char *)0x4957ed;
            (**(code **)(iVar3 + 4))();
            uStack_79c = s_LoadMailList___pReader_>READ____b_009ac4ac;
            FUN_0044a670();
            uStack_79c = auStack_729 + -0x20;
            FUN_00797b80();
            uStack_79c = (char *)piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          uStack_798 = 0;
          uStack_79c = (char *)0x1;
          piVar5 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
          if (uStack_78c._2_1_ < 2) {
            (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar5);
            piVar5 = (int *)0x0;
          }
          else {
            uStack_774 = (char *)(uint)uStack_78c._2_1_;
            uStack_778 = (undefined4 *)(**(code **)(*piVar2 + 4))(1,0);
            cVar1 = (**(code **)(*piVar5 + 0xc))(&uStack_77c);
            if (cVar1 == '\0') {
              uStack_794 = (char *)DAT_00b5aa1c;
              uVar6 = (**(code **)(*piStack_4 + 0x70))();
              uStack_75c = (char *)((uint)uStack_75c & 0xffffff);
              iVar3 = *(int *)uStack_794;
              uVar6 = FUN_0044a580((int)&uStack_75c + 3,s_UserName____s__pItem_>Open__Item_009ac4dc,
                                   uVar6);
              (**(code **)(iVar3 + 4))(uVar6);
              FUN_0044a670(s_LoadMailList___pItem_>Open__Item_009ac510);
              FUN_00797b80((int)&uStack_760 + 3);
              (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar5);
              (**(code **)(*DAT_00b5a69c + 8))(piVar2);
              return 0;
            }
            in_stack_fffff854 = uStack_798 >> 0x10 & 0xff;
            in_stack_fffff850 = (int *)0x1;
            (**(code **)(*piVar2 + 4))(1,in_stack_fffff854);
            FUN_00797a50(auStack_53c,0,0x10);
            in_stack_fffff848 = piVar2;
            cVar1 = (**(code **)(*DAT_00b5aa10 + 0x10))(piVar2,auStack_53c);
            if (cVar1 == '\0') {
              (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar5);
              piVar5 = DAT_00b5aa1c;
              uVar6 = (**(code **)(*piStack_4 + 0x70))();
              uStack_774 = (char *)((uint)uStack_774 & 0xffffff);
              iVar3 = *piVar5;
              uVar6 = FUN_0044a580((int)&uStack_774 + 3,s_UserName____s__LoadMailList___CO_009ac544,
                                   uVar6);
              (**(code **)(iVar3 + 4))(uVar6);
              FUN_0044a670(s_Mail_Item_Serial_Parsing_Fail_009ac578);
              FUN_00797b80((int)&uStack_778 + 3);
              (**(code **)(*DAT_00b5a69c + 8))(piVar2);
              return 0;
            }
            FUN_00797a50(&uStack_778,0,0xc);
            in_stack_fffff844 = &uStack_778;
            cVar1 = (**(code **)(*DAT_00b5aa10 + 0x18))(piVar2,in_stack_fffff844);
            if (cVar1 == '\0') {
              (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar5);
              piVar5 = DAT_00b5aa1c;
              uVar6 = (**(code **)(*piStack_4 + 0x70))();
              uStack_77c = (char *)((uint)uStack_77c & 0xffffff);
              iVar3 = *piVar5;
              uVar6 = FUN_0044a580((int)&uStack_77c + 3,s_UserName____s__LoadMailList___CO_009ac598,
                                   uVar6);
              (**(code **)(iVar3 + 4))(uVar6);
              piStack_754 = (int *)s_Mail_Item_Limit_Parsing_Fail_009ac5cc;
              goto LAB_00495c5d;
            }
            (**(code **)(*piVar5 + 0x78))(&uStack_780);
          }
          piVar10 = (int *)0x4;
          iVar3 = (**(code **)(*piVar2 + 8))(4,&uStack_78c);
          piVar7 = DAT_00b5aa1c;
          if (iVar3 != 4) {
            uVar6 = (**(code **)(*piStack_4 + 0x70))();
            uStack_780 = (undefined4 *)((uint)uStack_780 & 0xffffff);
            iVar3 = *piVar7;
            uVar6 = FUN_0044a580((int)&uStack_780 + 3,s_UserName____s__LoadMailList___pR_009ac5ec,
                                 uVar6);
            (**(code **)(iVar3 + 4))(uVar6);
            FUN_0044a670(s_LoadMailList___pReader_>READ____d_009ac62c);
            FUN_00797b80((int)&uStack_784 + 3);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          FUN_00494e80();
          FUN_00495c90();
          FUN_00495cb0(auStack_588);
          uStack_4e0 = (uint)in_stack_fffff844 >> 0x18;
          FUN_0047aa00(auStack_574);
          FUN_00495ce0(auStack_548);
          FUN_00495d10(auStack_284);
          piStack_288 = in_stack_fffff848;
          piVar7 = (int *)(**(code **)(*DAT_00b5abe8 + 0xc))(1,0);
          cVar1 = (**(code **)(*piVar7 + 8))(in_stack_fffff854,auStack_4f8 + 0x10,piVar5);
          piVar7 = DAT_00b5aa1c;
          if (cVar1 == '\0') {
            uVar6 = (**(code **)(*piStack_4 + 0x70))();
            uStack_794 = (char *)((uint)uStack_794 & 0xffffff);
            iVar3 = *piVar7;
            uVar6 = FUN_0044a580((int)&uStack_794 + 3,s_UserName____s__pMail_>Open__FAIL_009ac658,
                                 uVar6);
            (**(code **)(iVar3 + 4))(uVar6);
            FUN_0044a670(s_LoadMailList__pMail_>Open__009ac67c);
            FUN_00797b80((int)&uStack_798 + 3);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          (**(code **)(*piVar10 + 0x24))(in_stack_fffff850);
          cVar1 = (**(code **)(*in_stack_fffff850 + 4))(piVar10);
          piVar7 = DAT_00b5aa1c;
          if (cVar1 != '\0') {
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 1;
          }
          uVar6 = (**(code **)(*piStack_4 + 0x70))();
          uStack_79c = (char *)((uint)uStack_79c & 0xffffff);
          iVar3 = *piVar7;
          uVar6 = FUN_0044a580((int)&uStack_79c + 3,s_UserName____s__LoadMailList___pM_009ac698,
                               uVar6);
          (**(code **)(iVar3 + 4))(uVar6);
          FUN_0044a670(s_LoadMailList___pMailBox_>AddMail_009ac6dc);
          FUN_00797b80(auStack_729 + -0x74);
          (**(code **)(*DAT_00b5abe8 + 0x10))(1,piVar5);
          goto LAB_00495c73;
        }
        uStack_780 = (undefined4 *)0x4954ac;
        uStack_780 = (undefined4 *)(**(code **)(*piStack_4 + 0x70))();
        puStack_788 = &uStack_72d;
        uStack_784 = s_UserName____s__LoadMailList___wC_009ac134;
        uStack_72d._0_1_ = 0;
        iVar3 = *piVar5;
        uStack_78c = (char *)0x4954c3;
        uStack_780 = (undefined4 *)FUN_0044a580();
        uStack_784 = (char *)0x4954cc;
        (**(code **)(iVar3 + 4))();
        piStack_754 = (int *)s_LoadMailList___wConTitleSize_>_5_009ac168;
      }
      else {
        puStack_770 = (undefined1 *)0x495c38;
        puStack_770 = (undefined1 *)(**(code **)(*piStack_4 + 0x70))();
        uStack_778 = &uStack_71d;
        uStack_774 = s_UserName____s__LoadMailList___wC_009abf88;
        uStack_71d._0_1_ = 0;
        iVar3 = *piVar5;
        uStack_77c = (char *)0x495c4f;
        puStack_770 = (undefined1 *)FUN_0044a580();
        uStack_774 = (char *)0x495c58;
        (**(code **)(iVar3 + 4))();
        piStack_754 = (int *)s_LoadMailList___wConNameSize_>_24_009abfbc;
      }
    }
  }
LAB_00495c5d:
  puStack_758 = (undefined1 *)0x495c66;
  FUN_0044a670();
  piStack_754 = (int *)auStack_701;
  puStack_758 = (undefined1 *)0x495c70;
  FUN_00797b80();
LAB_00495c73:
  puStack_758 = (undefined1 *)0x495c7f;
  piStack_754 = piVar2;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 0;
}


// ==== FUN_00495c90 @ 0x00495c90 ====

void FUN_00495c90(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)(in_ECX + 0x17) = 0;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 99) = 0;
  return;
}


// ==== FUN_00495cb0 @ 0x00495cb0 ====

void FUN_00495cb0(int param_1)

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
    if (cVar1 == '\0') {
      return;
    }
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0x13);
  *in_ECX = '\0';
  return;
}


// ==== FUN_00495ce0 @ 0x00495ce0 ====

void FUN_00495ce0(int param_1)

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
    if (cVar1 == '\0') {
      return;
    }
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0x33);
  *in_ECX = '\0';
  return;
}


// ==== FUN_00495d10 @ 0x00495d10 ====

void FUN_00495d10(int param_1)

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
    if (cVar1 == '\0') {
      return;
    }
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0x1f5);
  *in_ECX = '\0';
  return;
}


// ==== FUN_00495d40 @ 0x00495d40 ====

char * FUN_00495d40(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x33,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x33)) {
    param_1[0x32] = '\0';
  }
  return param_1;
}


// ==== FUN_00495d70 @ 0x00495d70 ====

char * FUN_00495d70(char *param_1,char *param_2,char param_3)

{
  int iVar1;
  
  iVar1 = __vsnprintf(param_1,0x1f5,param_2,&param_3);
  if ((iVar1 < 0) || (iVar1 == 0x1f5)) {
    param_1[500] = '\0';
  }
  return param_1;
}


// ==== FUN_00495db0 @ 0x00495db0 ====

void FUN_00495db0(void)

{
  FUN_00495d40();
  return;
}


// ==== FUN_00495dd0 @ 0x00495dd0 ====

void FUN_00495dd0(void)

{
  FUN_00495d70();
  return;
}


// ==== FUN_00495df0 @ 0x00495df0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00495df0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ac720;
  _DAT_00b5aab0 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00495ec0 @ 0x00495ec0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00495ec0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ac904;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa8c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa8c = in_ECX;
  return;
}


// ==== FUN_00495f10 @ 0x00495f10 ====

undefined4 FUN_00495f10(int param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  uint unaff_EBP;
  undefined2 unaff_DI;
  undefined1 **ppuVar8;
  byte bVar9;
  uint uVar10;
  undefined4 uStack_278;
  undefined4 uStack_274;
  int *piStack_270;
  uint uStack_26c;
  uint *puStack_268;
  undefined4 uStack_264;
  int *piStack_260;
  uint uStack_25c;
  int *piStack_258;
  undefined1 *puStack_254;
  undefined4 uStack_250;
  undefined1 auStack_244 [4];
  int *piStack_240;
  undefined4 uStack_238;
  undefined1 auStack_230 [4];
  undefined1 auStack_22c [8];
  uint auStack_224 [2];
  undefined1 auStack_21c [8];
  int aiStack_214 [51];
  char acStack_148 [60];
  undefined1 auStack_10c [8];
  undefined1 auStack_104 [260];
  
  uStack_238 = param_1;
  piVar3 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  if (piVar3 == (int *)0x0) {
    auStack_244 = (undefined1  [4])auStack_104;
    piStack_240 = (int *)&DAT_009ac8fc;
    FUN_0044a580();
    FUN_00797b80();
    return 0;
  }
  piVar1 = *(int **)(param_1 + 0x34);
  if (piVar1 == (int *)0x0) {
    piStack_240 = (int *)s_LoadStoreItem___pStore_is_NULL_009ac758;
    auStack_244 = (undefined1  [4])&DAT_009ac8fc;
    FUN_0044a580();
    uStack_250 = (int *)0x495f93;
    FUN_00797b80();
    auStack_244 = (undefined1  [4])0x495fa2;
    piStack_240 = piVar3;
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  piStack_240 = (int *)auStack_22c;
  auStack_244 = (undefined1  [4])0x2;
  iVar4 = (**(code **)(*piVar3 + 8))();
  if (iVar4 != 2) {
    uStack_250 = (int *)auStack_10c;
    puStack_254 = (undefined1 *)0x495fd9;
    FUN_0044a580();
    puStack_254 = auStack_10c;
    piStack_258 = (int *)0x495fe6;
    FUN_00797b80();
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  uStack_238 = 2;
  uVar7 = (uint)CONCAT11((char)unaff_DI,(char)((ushort)unaff_DI >> 8));
  auStack_224[0] = uVar7;
  if (uVar7 != 2) {
    do {
      uStack_250 = (int *)(auStack_230 + -10);
      puStack_254 = (undefined1 *)0x1;
      piStack_258 = (int *)0x49603e;
      iVar4 = (**(code **)(*piVar3 + 8))();
      if (iVar4 != 1) {
        piStack_258 = (int *)s_LoadStoreItem___pReader_>READ__s_009ac7ac;
        uStack_25c = 0x49625d;
        FUN_0044a670();
        piStack_258 = aiStack_214;
        uStack_25c = 0x496267;
        FUN_00797b80();
        uStack_25c = 0x496276;
        piStack_258 = piVar3;
        (**(code **)(*DAT_00b5a69c + 8))();
        return 0;
      }
      piStack_258 = (int *)(auStack_244 + 3);
      uStack_25c = 1;
      piStack_260 = (int *)0x496055;
      iVar4 = (**(code **)(*piVar3 + 8))();
      if (iVar4 != 1) {
        piStack_260 = (int *)s_LoadStoreItem___pReader_>READ__p_009ac7d8;
        uStack_264 = 0x496293;
        FUN_0044a670();
        piStack_260 = (int *)auStack_21c;
        uStack_264 = 0x49629d;
        FUN_00797b80();
        uStack_264 = 0x4962ac;
        piStack_260 = piVar3;
        (**(code **)(*DAT_00b5a69c + 8))();
        return 0;
      }
      piStack_260 = &uStack_238;
      uStack_264 = 4;
      puStack_268 = (uint *)0x49606c;
      iVar4 = (**(code **)(*piVar3 + 8))();
      if (iVar4 != 4) {
        puStack_268 = (uint *)s_LoadStoreItem___pReader_>READ__d_009ac808;
        uStack_26c = 0x4962c9;
        FUN_0044a670();
        puStack_268 = auStack_224;
        uStack_26c = 0x4962d3;
        FUN_00797b80();
        uStack_26c = 0x4962e2;
        puStack_268 = (uint *)piVar3;
        (**(code **)(*DAT_00b5a69c + 8))();
        return 0;
      }
      puStack_268 = (uint *)auStack_230;
      uStack_26c = 0xc;
      piStack_270 = (int *)0x496083;
      iVar4 = (**(code **)(*piVar3 + 8))();
      if (iVar4 != 0xc) {
        piStack_270 = (int *)s_LoadStoreItem___pReader_>READ____009ac838;
        uStack_274 = 0x4962ff;
        FUN_0044a670();
        piStack_270 = (int *)auStack_22c;
        uStack_274 = 0x496309;
        FUN_00797b80();
        uStack_274 = 0x496318;
        piStack_270 = piVar3;
        (**(code **)(*DAT_00b5a69c + 8))();
        return 0;
      }
      piStack_270 = (int *)(auStack_230 + -0x1c);
      uStack_274 = 4;
      uStack_278 = (char *)0x49609a;
      iVar4 = (**(code **)(*piVar3 + 8))();
      if (iVar4 != 4) {
        uStack_278 = s_LoadStoreItem___pReader_>READ____009ac878;
        FUN_0044a670();
        uStack_278 = auStack_230 + -4;
        FUN_00797b80();
        uStack_278 = (char *)piVar3;
        (**(code **)(*DAT_00b5a69c + 8))();
        return 0;
      }
      uStack_278 = (char *)0x0;
      (**(code **)(*piVar3 + 4))(1);
      uVar10 = 0;
      bVar9 = 0;
      piVar5 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
      cVar2 = (**(code **)(*piVar5 + 0xc))(&piStack_258);
      if (cVar2 == '\0') {
        acStack_148[0] = cVar2;
        uVar6 = FUN_0044a580(acStack_148,s_LoadStoreItem___Item_Open_Fail_009ac8bc);
        FUN_00797b80(uVar6);
        (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar5);
        (**(code **)(*piVar3 + 4))(1,(uVar10 >> 0x10 & 0xff) - 0x16);
      }
      else {
        ppuVar8 = &puStack_254;
        (**(code **)(*piVar5 + 0x78))(ppuVar8);
        (**(code **)(*piVar5 + 0x84))
                  (CONCAT31((int3)uStack_26c,(char)(uStack_26c >> 8)) << 0x10 |
                   (uStack_26c >> 0x10 & 0xff) << 8 | uStack_26c >> 0x18);
        (**(code **)(*piVar5 + 0x68))
                  (CONCAT31((int3)uStack_26c,(char)(uStack_26c >> 8)) << 0x10 |
                   (uStack_26c >> 0x10 & 0xff) << 8 | uStack_26c >> 0x18);
        uStack_278 = (char *)CONCAT22(CONCAT11(uStack_278._3_1_,(bVar9 % 0x32) / 10),
                                      CONCAT11((bVar9 % 0x32) % 10,bVar9 / 0x32));
        cVar2 = (**(code **)(*piVar1 + 0x1c))(&uStack_278,piVar5);
        if (cVar2 == '\0') {
          uStack_25c = uStack_25c & 0xffffff00;
          uVar6 = FUN_0044a580(&uStack_25c,s_LoadStoreItem___PutItem_fail_009ac8dc);
          FUN_00797b80(uVar6);
          (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar5);
        }
        (**(code **)(*piVar3 + 4))(1,((uint)ppuVar8 >> 0x10 & 0xff) - 0x16);
        uVar7 = auStack_224[0];
      }
      uStack_238 = uStack_238 + (unaff_EBP >> 0x10 & 0xff);
    } while (uVar7 != uStack_238);
  }
  puStack_254 = (undefined1 *)0x496240;
  uStack_250 = piVar3;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 1;
}


// ==== FUN_00496360 @ 0x00496360 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496360(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ac904;
  _DAT_00b5aa8c = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00496450 @ 0x00496450 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496450(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009acb10;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa48 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa48 = in_ECX;
  return;
}


// ==== FUN_004964a0 @ 0x004964a0 ====

uint FUN_004964a0(undefined4 param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  ushort uVar7;
  undefined1 *puVar8;
  int *piVar9;
  byte bVar10;
  undefined4 uStack_154;
  int **ppiStack_150;
  undefined4 uStack_14c;
  int **ppiStack_148;
  undefined4 uStack_144;
  int **ppiStack_140;
  undefined1 *puStack_13c;
  int *piStack_138;
  int *piStack_120;
  int *apiStack_11c [4];
  int *local_10c [2];
  undefined1 auStack_104 [232];
  undefined4 uStack_1c;
  
  piVar9 = *(int **)(param_2 + 0x34);
  local_10c[0] = piVar9;
  if (piVar9 == (int *)0x0) {
    FUN_0044a580();
    piStack_138 = (int *)0x4964d7;
    uVar2 = FUN_00797b80();
    return uVar2 & 0xffff0000;
  }
  piVar3 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar3 == (int *)0x0) {
    piStack_138 = (int *)auStack_104;
    puStack_13c = (undefined1 *)0x496515;
    FUN_0044a580();
    puStack_13c = auStack_104;
    ppiStack_140 = (int **)0x49651f;
    uVar2 = FUN_00797b80();
    return uVar2 & 0xffff0000;
  }
  piStack_138 = (int *)0x2;
  puStack_13c = (undefined1 *)0x0;
  ppiStack_140 = (int **)0x49653d;
  (**(code **)(*piVar3 + 4))();
  puVar8 = (undefined1 *)0x2;
  uVar7 = 2;
  ppiStack_140 = (int **)0x49654e;
  piVar4 = (int *)(**(code **)(*piVar9 + 0x34))();
  if (piVar4 != (int *)0x0) {
    do {
      ppiStack_140 = apiStack_11c + -3;
      ppiStack_148 = (int **)0x496575;
      uStack_144 = (char *)piVar4;
      cVar1 = (**(code **)(*piVar9 + 0x18))();
      if (cVar1 == '\x01') {
        ppiStack_148 = (int **)0x16;
        uStack_14c = 1;
        ppiStack_150 = (int **)0x4965a0;
        (**(code **)(*piVar3 + 4))();
        iVar5 = *DAT_00b5aa10;
        uStack_154 = 0x4965b1;
        ppiStack_150 = (int **)piVar3;
        uStack_154 = (**(code **)(*piVar4 + 0x14))();
        cVar1 = (**(code **)(iVar5 + 4))();
        puVar8 = puStack_13c;
        uStack_144 = (char *)CONCAT13(cVar1,(undefined3)uStack_144);
        if (cVar1 == '\0') {
          FUN_0044a670(s_OnSaveStoreItem___Convert_return_009ac954);
          FUN_00797b80(apiStack_11c + -2);
          FUN_004985b0(0,uStack_1c,piVar4,piStack_138);
          uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
          return uVar2 & 0xffff0000;
        }
        uStack_144 = (char *)CONCAT13(cVar1 + '\x16',(undefined3)uStack_144);
        (**(code **)(*piVar3 + 4))(0,(uint)puStack_13c & 0xffff);
        iVar5 = (**(code **)(*piVar3 + 8))(1,(int)&uStack_14c + 3);
        if (iVar5 != 1) {
          FUN_0044a670(s_OnSaveStore___pWriter_>WRITE__by_009ac988);
          FUN_00797b80(apiStack_11c + -6);
          uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
          return uVar2 & 0xffff0000;
        }
        iVar5 = (**(code **)(*piVar3 + 8))(1,&ppiStack_148);
        if (iVar5 != 1) {
          FUN_0044a670(s_OnSaveStore___pWriter_>WRITE__by_009ac9bc);
          FUN_00797b80(&puStack_13c);
          uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
          return uVar2 & 0xffff0000;
        }
        uVar2 = (**(code **)(*piVar4 + 0x6c))();
        uStack_14c = CONCAT31((int3)uVar2,(char)(uVar2 >> 8)) << 0x10 | (uVar2 >> 0x10 & 0xff) << 8
                     | uVar2 >> 0x18;
        bVar10 = 0;
        iVar5 = (**(code **)(*piVar3 + 8))(4,&uStack_14c);
        if (iVar5 != 4) {
          FUN_0044a670(s_OnSaveStoreItem___pWriter_>WRITE_009ac9f0);
          FUN_00797b80(&uStack_144);
          uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
          return uVar2 & 0xffff0000;
        }
        uVar6 = (**(code **)(*piVar4 + 0x7c))();
        iVar5 = (**(code **)(*piVar3 + 8))(0xc,uVar6);
        if (iVar5 != 0xc) {
          FUN_0044a670(s_OnSaveStoreItem___pWriter_>WRITE_009aca28);
          FUN_00797b80(&uStack_14c);
          uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
          return uVar2 & 0xffff0000;
        }
        uVar2 = (**(code **)(*piVar4 + 0x88))();
        ppiStack_150 = (int **)(CONCAT31((int3)uVar2,(char)(uVar2 >> 8)) << 0x10 |
                                (uVar2 >> 0x10 & 0xff) << 8 | uVar2 >> 0x18);
        iVar5 = (**(code **)(*piVar3 + 8))(4,&ppiStack_150);
        if (iVar5 != 4) {
          FUN_0044a670(s_OnSaveStoreItem___pWriter_>WRITE_009aca68);
          FUN_00797b80(&uStack_154);
          uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar3);
          return uVar2 & 0xffff0000;
        }
        puVar8 = puVar8 + bVar10;
        (**(code **)(*piVar3 + 4))(0,(uint)puVar8 & 0xffff);
        piVar9 = piStack_120;
      }
      uVar7 = (ushort)puVar8;
      ppiStack_148 = (int **)0x4966c6;
      piVar4 = (int *)(**(code **)(*piVar9 + 0x38))();
    } while (piVar4 != (int *)0x0);
    if (1000 < uVar7) {
      local_10c[0] = (int *)((uint)local_10c[0] & 0xffffff00);
      iVar5 = *DAT_00b5aa1c;
      ppiStack_140 = (int **)((uint)puVar8 & 0xffff);
      ppiStack_148 = local_10c;
      uStack_144 = s_OnSaveStoreItem__Save_wTotalSize_009acaa0;
      uStack_14c = 0x4966f6;
      ppiStack_140 = (int **)FUN_0044a580();
      uStack_144 = (char *)0x4966ff;
      (**(code **)(iVar5 + 4))();
    }
  }
  ppiStack_140 = (int **)0x0;
  uStack_144 = (char *)0x0;
  ppiStack_148 = (int **)0x49670a;
  (**(code **)(*piVar3 + 4))();
  apiStack_11c[0] = (int *)CONCAT22(extraout_var,CONCAT11((char)uVar7,(char)(uVar7 >> 8)));
  ppiStack_148 = apiStack_11c;
  uStack_14c = 2;
  ppiStack_150 = (int **)0x496722;
  iVar5 = (**(code **)(*piVar3 + 8))();
  if (iVar5 == 2) {
    uStack_154 = 0x4968cd;
    ppiStack_150 = (int **)piVar3;
    (**(code **)(*DAT_00b5a69c + 0x10))();
    return CONCAT22(extraout_var_00,uVar7);
  }
  ppiStack_150 = (int **)s_OnSaveStoreItem___pWriter_>WRITE_009acad0;
  uStack_154 = 0x496739;
  FUN_0044a670();
  ppiStack_150 = apiStack_11c;
  uStack_154 = 0x496743;
  FUN_00797b80();
  uStack_154 = 0x496752;
  ppiStack_150 = (int **)piVar3;
  uVar2 = (**(code **)(*DAT_00b5a69c + 0x10))();
  return uVar2 & 0xffff0000;
}


// ==== FUN_004968e0 @ 0x004968e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004968e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009acb10;
  _DAT_00b5aa48 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00496960 @ 0x00496960 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496960(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009accac;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa88 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa88 = in_ECX;
  return;
}


// ==== FUN_004969b0 @ 0x004969b0 ====

undefined4 FUN_004969b0(uint *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined2 unaff_BX;
  char unaff_DI;
  uint uVar5;
  undefined1 uVar7;
  int **ppiVar6;
  undefined2 uVar8;
  undefined1 auStack_1ee [14];
  undefined4 uStack_1e0;
  int *piStack_1dc;
  uint uStack_1d8;
  int *piStack_1d4;
  undefined1 *puStack_1d0;
  undefined1 auStack_1cc [4];
  undefined1 *puStack_1c8;
  undefined4 uStack_1c4;
  undefined *puStack_1c0;
  undefined4 uStack_1bc;
  undefined4 uStack_1b8;
  undefined1 auStack_1a4 [4];
  undefined1 auStack_1a0 [2];
  undefined1 uStack_19e;
  char acStack_19b [25];
  undefined2 uStack_182;
  undefined2 uStack_180;
  undefined2 uStack_17e;
  undefined1 uStack_17c;
  char acStack_178 [36];
  undefined1 auStack_154 [8];
  undefined1 auStack_14c [4];
  undefined1 auStack_148 [4];
  undefined1 auStack_144 [4];
  undefined1 auStack_140 [4];
  undefined1 auStack_13c [24];
  int aiStack_124 [2];
  undefined1 auStack_11c [8];
  undefined1 auStack_114 [8];
  undefined1 auStack_10c [8];
  undefined1 auStack_104 [260];
  
  uStack_1b8 = param_1;
  uStack_1bc = (char *)0x4969cc;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  if (piVar2 == (int *)0x0) {
    uStack_1bc = s_EntryGuild___pReader_is_NULL_009acb18;
    uStack_1c4 = auStack_104;
    puStack_1c0 = &DAT_009acca4;
    puStack_1c8 = (undefined1 *)0x4969eb;
    FUN_0044a580();
    puStack_1c8 = auStack_104;
    auStack_1cc = (undefined1  [4])0x4969f8;
    FUN_00797b80();
    return 0;
  }
  uStack_1bc = auStack_1a4;
  puStack_1c0 = (undefined *)0x2;
  uStack_1c4 = (char *)0x496a17;
  iVar3 = (**(code **)(*piVar2 + 8))();
  if (iVar3 == 2) {
    if (*param_1 < (uint)CONCAT11((char)unaff_BX,(char)((ushort)unaff_BX >> 8))) {
      uStack_1c4 = s_EntryGuild___wConvertSize_009acb54;
    }
    else {
      uStack_1c4 = auStack_1a4 + -0x10;
      puStack_1c8 = (undefined1 *)0x1;
      auStack_1cc = (undefined1  [4])0x496a47;
      iVar3 = (**(code **)(*piVar2 + 8))();
      if (iVar3 == 1) {
        do {
          if (unaff_DI == '\0') {
            puStack_1c8 = (undefined1 *)0x496c57;
            uStack_1c4 = (char *)piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 1;
          }
          uStack_1c4 = auStack_1a0;
          puStack_1c8 = (undefined1 *)0xa;
          auStack_1a0[0] = 0;
          auStack_1cc = (undefined1  [4])0x496aa9;
          iVar3 = (**(code **)(*piVar2 + 8))();
          if (iVar3 != 10) {
            auStack_1cc = (undefined1  [4])s_EntryGuildParse___strGuildCode_009acb88;
            puStack_1d0 = (undefined1 *)0x496c76;
            FUN_0044a670();
            auStack_1cc = (undefined1  [4])auStack_114;
            puStack_1d0 = (undefined1 *)0x496c83;
            FUN_00797b80();
            puStack_1d0 = (undefined1 *)0x496c92;
            auStack_1cc = (undefined1  [4])piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          auStack_1cc = (undefined1  [4])((int)&uStack_1bc + 1);
          puStack_1d0 = (undefined1 *)0x1;
          uStack_19e = 0;
          piStack_1d4 = (int *)0x496ac4;
          iVar3 = (**(code **)(*piVar2 + 8))();
          if (iVar3 != 1) {
            piStack_1d4 = (int *)s_EntryGuild___byGuildNameSize_009acba8;
            uStack_1d8 = 0x496cb1;
            FUN_0044a670();
            piStack_1d4 = (int *)auStack_11c;
            uStack_1d8 = 0x496cbe;
            FUN_00797b80();
            uStack_1d8 = 0x496ccd;
            piStack_1d4 = piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          uVar5 = (uint)uStack_1c4._1_1_;
          piStack_1d4 = (int *)auStack_140;
          uStack_1d8 = (uint)uStack_1c4._1_1_;
          auStack_140[0] = 0;
          piStack_1dc = (int *)0x496aee;
          uVar4 = (**(code **)(*piVar2 + 8))();
          if (uVar4 != uVar5) {
            piStack_1dc = (int *)s_EntryGuild___strGuildName_009acbc8;
            uStack_1e0 = 0x496cec;
            FUN_0044a670();
            piStack_1dc = aiStack_124;
            uStack_1e0 = 0x496cf9;
            FUN_00797b80();
            uStack_1e0 = 0x496d08;
            piStack_1dc = piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          iVar3 = *piVar2;
          piStack_1dc = (int *)(auStack_1cc + 2);
          uStack_1e0 = 1;
          auStack_148[uVar5] = 0;
          iVar3 = (**(code **)(iVar3 + 8))();
          if (iVar3 != 1) {
            FUN_0044a670();
            FUN_00797b80();
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          uVar5 = (uint)piStack_1d4 >> 0x10 & 0xff;
          uVar4 = (**(code **)(*piVar2 + 8))();
          if (uVar4 != uVar5) {
            FUN_0044a670();
            FUN_00797b80();
            (**(code **)(*DAT_00b5a69c + 8))();
            return 0;
          }
          iVar3 = *piVar2;
          auStack_1a4[uVar5 - 0x14] = 0;
          iVar3 = (**(code **)(iVar3 + 8))();
          if (iVar3 != 2) {
            FUN_0044a670(s_EntryGuild___wMark_009acc20);
            FUN_00797b80(auStack_13c);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          uVar8 = 0;
          iVar3 = (**(code **)(*piVar2 + 8))(2,&uStack_1e0);
          if (iVar3 != 2) {
            FUN_0044a670(s_EntryGuild___wMarkBg_009acc34);
            FUN_00797b80(auStack_144);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          ppiVar6 = &piStack_1dc;
          iVar3 = (**(code **)(*piVar2 + 8))(2,ppiVar6);
          uVar7 = (undefined1)((uint)ppiVar6 >> 0x18);
          if (iVar3 != 2) {
            FUN_0044a670(s_EntryGuild___wEffect_009acc4c);
            FUN_00797b80(auStack_14c);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          iVar3 = (**(code **)(*piVar2 + 8))(1,auStack_1ee + -3);
          if (iVar3 != 1) {
            FUN_0044a670(s_EntryGuild___byChannelIndex_009acc64);
            FUN_00797b80(auStack_154);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          FUN_00496ec0();
          uStack_17c = uVar7;
          uVar4 = 0;
          do {
            cVar1 = acStack_178[uVar4];
            auStack_1a4[uVar4 - 0x18] = cVar1;
            if (cVar1 == '\0') goto LAB_00496bbd;
            uVar4 = uVar4 + 1;
          } while (uVar4 < 0x21);
          uStack_1bc = (char *)((uint)uStack_1bc & 0xffffff00);
LAB_00496bbd:
          uVar4 = 0;
          do {
            cVar1 = auStack_1a4[uVar4 - 0x34];
            acStack_19b[uVar4] = cVar1;
            if (cVar1 == '\0') goto LAB_00496bd8;
            uVar4 = uVar4 + 1;
          } while (uVar4 < 0x19);
          acStack_19b[0] = '\0';
LAB_00496bd8:
          uStack_182 = 0x200;
          uStack_180 = CONCAT11((char)uVar8,(char)((ushort)uVar8 >> 8));
          uStack_17e = CONCAT11((char)&puStack_1d0,(char)((uint)&puStack_1d0 >> 8));
          iVar3 = (**(code **)(*DAT_00b5abf0 + 4))(&uStack_1bc);
          if (iVar3 == 0) {
            FUN_0044a670(s_EntryGuild___pAttacker_is_NULL_009acc84);
            FUN_00797b80(acStack_178 + 0x20);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          (**(code **)(*DAT_00b5abec + 4))(iVar3);
          unaff_DI = unaff_DI + -1;
        } while( true );
      }
      uStack_1c4 = s_EntryGuild___byCount_009acb70;
    }
  }
  else {
    uStack_1c4 = s_EntryGuild___wTotalSize_009acb38;
  }
  auStack_1cc = (undefined1  [4])auStack_10c;
  puStack_1c8 = &DAT_009acca4;
  puStack_1d0 = (undefined1 *)0x496a63;
  FUN_0044a580();
  puStack_1d0 = auStack_10c;
  piStack_1d4 = (int *)0x496a70;
  FUN_00797b80();
  puStack_1c8 = (undefined1 *)0x496a7f;
  uStack_1c4 = (char *)piVar2;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 0;
}


// ==== FUN_00496ec0 @ 0x00496ec0 ====

void FUN_00496ec0(void)

{
  undefined1 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[0x21] = 0;
  return;
}


// ==== FUN_00496ed0 @ 0x00496ed0 ====

void FUN_00496ed0(int param_1)

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
    if (cVar1 == '\0') {
      return;
    }
    uVar3 = uVar3 + 1;
    pcVar2 = pcVar2 + 1;
  } while (uVar3 < 0x21);
  *in_ECX = '\0';
  return;
}


// ==== FUN_00496f00 @ 0x00496f00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496f00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009accac;
  _DAT_00b5aa88 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00496f30 @ 0x00496f30 ====

undefined1 FUN_00496f30(void)

{
  return 1;
}


// ==== FUN_00496f50 @ 0x00496f50 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00496f50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ad048;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa84 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa84 = in_ECX;
  return;
}


// ==== FUN_00496fa0 @ 0x00496fa0 ====

undefined4 FUN_00496fa0(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  uint unaff_EDI;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined1 *puVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  undefined4 *puVar9;
  int *piStack_148;
  int *piStack_144;
  int *piStack_140;
  undefined1 auStack_13c [4];
  undefined4 uStack_138;
  byte bVar10;
  char cVar11;
  undefined4 uStack_128;
  undefined1 auStack_124 [8];
  undefined1 auStack_11c [8];
  undefined1 auStack_114 [4];
  int iStack_110;
  undefined1 auStack_10c [8];
  int aiStack_104 [65];
  
  uStack_138 = (int *)0x496fb7;
  piVar1 = (int *)(**(code **)(*param_2 + 0x3c))();
  uStack_138 = param_1;
  auStack_13c = (undefined1  [4])0x496fcc;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  if (piVar2 == (int *)0x0) {
    auStack_13c = (undefined1  [4])s_DefenderSetting__Load_pReader_is_009accb4;
    piStack_144 = aiStack_104;
    piStack_140 = (int *)&DAT_009ad040;
    piStack_148 = (int *)0x496fe6;
    FUN_0044a580();
    piStack_148 = aiStack_104;
    FUN_00797b80();
    return 0;
  }
  auStack_13c = (undefined1  [4])auStack_10c;
  piStack_140 = (int *)0x2;
  piStack_144 = (int *)0x49700f;
  iVar3 = (**(code **)(*piVar2 + 8))();
  if (iVar3 == 2) {
    piStack_144 = (int *)(auStack_13c + 0xb);
    piStack_148 = (int *)0x1;
    iVar3 = (**(code **)(*piVar2 + 8))();
    if (iVar3 == 1) {
      piStack_144 = (int *)(auStack_13c + 10);
      piStack_148 = (int *)0x1;
      iVar3 = (**(code **)(*piVar2 + 8))();
      if (iVar3 == 1) {
        cVar11 = (char)(unaff_EDI >> 0x18);
        while (cVar11 != '\0') {
          piStack_144 = &uStack_128;
          piStack_148 = (int *)0x4;
          iVar3 = (**(code **)(*piVar2 + 8))();
          if (iVar3 != 4) {
            FUN_0044a670(s_DefenderSetting__Load_dwGateKey_009acd4c);
            FUN_00797b80(auStack_114);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          iVar3 = (**(code **)(*piVar2 + 8))(1,&uStack_138);
          if (iVar3 != 1) {
            FUN_0044a670(s_DefenderSetting__Load_byLevel_009acd70);
            FUN_00797b80(auStack_11c);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          iVar3 = (**(code **)(*piVar2 + 8))(4,auStack_13c);
          if (iVar3 != 4) {
            FUN_0044a670(s_DefenderSetting__Load_dwAddHP_009acd90);
            FUN_00797b80(auStack_124);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          uStack_138 = piStack_140;
          (**(code **)(*param_2 + 0x30))(&uStack_138);
          cVar11 = (char)(unaff_EDI >> 0x18) + -1;
          unaff_EDI = CONCAT13(cVar11,(int3)unaff_EDI) & 0xffffff00;
        }
        bVar10 = (byte)(unaff_EDI >> 0x10);
        while( true ) {
          if (bVar10 == 0) {
            piStack_148 = (int *)0x4971ea;
            piStack_144 = piVar2;
            (**(code **)(*DAT_00b5a69c + 8))();
            return 1;
          }
          piStack_144 = &iStack_110;
          piStack_148 = (int *)0x4;
          iVar3 = (**(code **)(*piVar2 + 8))();
          if (iVar3 != 4) {
            FUN_0044a670(s_DefenderSetting__Load_wLocateKey_009acdb0);
            FUN_00797b80(auStack_114);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          puVar9 = &uStack_138;
          uVar7 = 2;
          iVar3 = (**(code **)(*piVar2 + 8))(2,puVar9);
          uVar8 = SUB42(puVar9,0);
          if (iVar3 != 2) {
            FUN_0044a670(s_DefenderSetting__Load_wSentryInd_009acdd4);
            FUN_00797b80(auStack_11c);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          puVar6 = auStack_13c + 8;
          uVar4 = 2;
          iVar3 = (**(code **)(*piVar2 + 8))(2,puVar6);
          uVar5 = SUB42(puVar6,0);
          if (iVar3 != 2) break;
          iVar3 = (**(code **)(*piVar2 + 8))(2,&piStack_144);
          if (iVar3 != 2) {
            FUN_0044a670(s_DefenderSetting__Load_wX_009ace1c);
            FUN_00797b80(auStack_124 + -8);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          iVar3 = (**(code **)(*piVar2 + 8))(2,&piStack_148);
          if (iVar3 != 2) {
            FUN_0044a670(s_DefenderSetting__Load_wY_009ace38);
            FUN_00797b80(auStack_13c + 8);
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          piStack_148 = uStack_138;
          piStack_140 = (int *)CONCAT22(uVar7,uVar5);
          piStack_144 = (int *)CONCAT22(uVar8,uVar4);
          iVar3 = (**(code **)(*DAT_00b5abf8 + 4))(&piStack_148);
          if (iVar3 == 0) {
            (**(code **)(*DAT_00b5a69c + 8))(piVar2);
            return 0;
          }
          (**(code **)(*piVar1 + 4))(iVar3);
          bVar10 = (char)(unaff_EDI >> 0x10) - 1;
          unaff_EDI = (uint)bVar10 << 0x10;
        }
        FUN_0044a670(s_DefenderSetting__Load_wMapIndex_009acdf8);
        FUN_00797b80(auStack_124);
        (**(code **)(*DAT_00b5a69c + 8))(piVar2);
        return 0;
      }
      piStack_144 = (int *)s_DefenderSetting__Load_bySentryCo_009acd24;
    }
    else {
      piStack_144 = (int *)s_DefenderSetting__Load_byGateCoun_009acd00;
    }
  }
  else {
    piStack_144 = (int *)s_DefenderSetting__Load_wTotalSize_009accdc;
  }
  piStack_148 = (int *)&DAT_009ad040;
  FUN_0044a580(auStack_10c);
  FUN_00797b80(auStack_10c);
  piStack_148 = (int *)0x497075;
  piStack_144 = piVar2;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 0;
}


// ==== FUN_004973c0 @ 0x004973c0 ====

undefined4 FUN_004973c0(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  char cVar3;
  undefined1 auStack_12a [4];
  char cStack_126;
  undefined4 uStack_124;
  undefined1 auStack_11c [8];
  undefined1 auStack_114 [8];
  undefined1 auStack_10c [8];
  undefined1 auStack_104 [256];
  int *piStack_4;
  
  uStack_124 = param_1;
  piVar1 = (int *)(**(code **)(*DAT_00b5a69c + 4))();
  if (piVar1 == (int *)0x0) {
    FUN_0044a580();
    FUN_00797b80(auStack_104);
    return 0;
  }
  iVar2 = (**(code **)(*piVar1 + 8))();
  if ((iVar2 != 2) || (iVar2 = (**(code **)(*piVar1 + 8))(1), iVar2 != 1)) {
    FUN_0044a580(auStack_10c,&DAT_009ad040);
    FUN_00797b80(auStack_10c);
    (**(code **)(*DAT_00b5a69c + 8))();
    return 0;
  }
  cStack_126 = (char)((uint)auStack_114 >> 0x10);
  if (cStack_126 != '\0') {
    do {
      cVar3 = '\0';
      iVar2 = (**(code **)(*piVar1 + 8))(4,&uStack_124);
      if (iVar2 != 4) {
        FUN_0044a670(s_DefenderSetting__Load_dwGateKey_009acec4);
        FUN_00797b80(auStack_114);
        (**(code **)(*DAT_00b5a69c + 8))(piVar1);
        return 0;
      }
      iVar2 = (**(code **)(*piVar1 + 8))(1,auStack_12a + -3);
      if (iVar2 != 1) {
        FUN_0044a670(s_DefenderSetting__Load_byLevel_009acee8);
        FUN_00797b80(auStack_11c);
        (**(code **)(*DAT_00b5a69c + 8))(piVar1);
        return 0;
      }
      iVar2 = (**(code **)(*piVar1 + 8))(4,auStack_12a + -6);
      if (iVar2 != 4) {
        FUN_0044a670(s_DefenderSetting__Load_dwAddHP_009acf08);
        FUN_00797b80(&uStack_124);
        (**(code **)(*DAT_00b5a69c + 8))(piVar1);
        return 0;
      }
      (**(code **)(*piStack_4 + 0x30))(auStack_12a + -6);
    } while (cVar3 != '\x01');
  }
  (**(code **)(*DAT_00b5a69c + 8))(piVar1);
  return 1;
}


// ==== FUN_004975b0 @ 0x004975b0 ====

undefined4 FUN_004975b0(undefined4 param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  char **ppcVar3;
  int iVar4;
  undefined2 uVar5;
  char **ppcVar6;
  undefined2 uVar7;
  char **ppcStack_150;
  undefined1 *puStack_14c;
  char **ppcStack_148;
  char *pcStack_144;
  char **ppcStack_140;
  undefined *puStack_13c;
  char *pcStack_138;
  undefined4 uStack_134;
  undefined1 auStack_126 [2];
  undefined1 auStack_124 [8];
  char *pcStack_11c;
  char acStack_118 [4];
  undefined1 auStack_114 [4];
  undefined1 auStack_110 [4];
  undefined1 auStack_10c [8];
  char acStack_104 [260];
  
  uStack_134 = 0x4975c1;
  piVar2 = (int *)(**(code **)(*param_2 + 0x3c))();
  uStack_134 = param_1;
  pcStack_138 = (char *)0x4975d6;
  ppcVar3 = (char **)(**(code **)(*DAT_00b5a69c + 4))();
  if (ppcVar3 == (char **)0x0) {
    pcStack_138 = s_DefenderSetting__Load_pReader_is_009acf28;
    ppcStack_140 = (char **)acStack_104;
    puStack_13c = &DAT_009ad040;
    pcStack_144 = (char *)0x4975f0;
    FUN_0044a580();
    pcStack_144 = acStack_104;
    ppcStack_148 = (char **)0x4975fa;
    FUN_00797b80();
    return 0;
  }
  pcStack_138 = acStack_118;
  puStack_13c = (undefined *)0x2;
  ppcStack_140 = (char **)0x497618;
  iVar4 = (**(code **)(*ppcVar3 + 8))();
  if (iVar4 == 2) {
    ppcStack_140 = (char **)((int)&uStack_134 + 3);
    pcStack_144 = (char *)0x1;
    ppcStack_148 = (char **)0x497632;
    iVar4 = (**(code **)(*ppcVar3 + 8))();
    if (iVar4 == 1) {
      cVar1 = uStack_134._3_1_;
      while( true ) {
        if (cVar1 == '\0') {
          pcStack_144 = (char *)0x49775a;
          ppcStack_140 = ppcVar3;
          (**(code **)(*DAT_00b5a69c + 8))();
          return 1;
        }
        ppcStack_140 = (char **)auStack_110;
        pcStack_144 = (char *)0x4;
        ppcStack_148 = (char **)0x49768e;
        iVar4 = (**(code **)(*ppcVar3 + 8))();
        if (iVar4 != 4) {
          ppcStack_148 = (char **)s_DefenderSetting__Load_wLocateKey_009acf9c;
          puStack_14c = (undefined1 *)0x497775;
          FUN_0044a670();
          ppcStack_148 = (char **)auStack_114;
          puStack_14c = (undefined1 *)0x49777f;
          FUN_00797b80();
          puStack_14c = (undefined1 *)0x49778e;
          ppcStack_148 = ppcVar3;
          (**(code **)(*DAT_00b5a69c + 8))();
          return 0;
        }
        ppcStack_148 = (char **)(auStack_126 + -6);
        puStack_14c = (undefined1 *)0x2;
        ppcStack_150 = (char **)0x4976a5;
        iVar4 = (**(code **)(*ppcVar3 + 8))();
        if (iVar4 != 2) {
          ppcStack_150 = (char **)s_DefenderSetting__Load_wSentryInd_009acfc0;
          FUN_0044a670();
          ppcStack_150 = &pcStack_11c;
          FUN_00797b80();
          ppcStack_150 = ppcVar3;
          (**(code **)(*DAT_00b5a69c + 8))();
          return 0;
        }
        ppcStack_150 = &pcStack_138;
        uVar7 = 2;
        iVar4 = (**(code **)(*ppcVar3 + 8))(2);
        if (iVar4 != 2) break;
        ppcVar6 = &pcStack_144;
        iVar4 = (**(code **)(*ppcVar3 + 8))(2,ppcVar6);
        uVar5 = SUB42(ppcVar6,0);
        if (iVar4 != 2) {
          FUN_0044a670(s_DefenderSetting__Load_wX_009ad008);
          FUN_00797b80(auStack_126 + -6);
          (**(code **)(*DAT_00b5a69c + 8))(ppcVar3);
          return 0;
        }
        iVar4 = (**(code **)(*ppcVar3 + 8))(2,&ppcStack_150);
        if (iVar4 != 2) {
          FUN_0044a670(s_DefenderSetting__Load_wY_009ad024);
          FUN_00797b80(&uStack_134);
          (**(code **)(*DAT_00b5a69c + 8))(ppcVar3);
          return 0;
        }
        pcStack_144 = pcStack_138;
        puStack_13c = (undefined *)CONCAT22(uVar5,uVar7);
        ppcStack_140 = (char **)CONCAT22(ppcStack_150._0_2_,(short)puStack_14c);
        iVar4 = (**(code **)(*DAT_00b5abf8 + 4))(&pcStack_144);
        if (iVar4 == 0) {
          (**(code **)(*DAT_00b5a69c + 8))(ppcVar3);
          return 0;
        }
        (**(code **)(*piVar2 + 4))(iVar4);
        cVar1 = uStack_134._3_1_ + -1;
        uStack_134 = CONCAT13(cVar1,(undefined3)uStack_134);
      }
      FUN_0044a670(s_DefenderSetting__Load_wMapIndex_009acfe4);
      FUN_00797b80(auStack_124);
      (**(code **)(*DAT_00b5a69c + 8))(ppcVar3);
      return 0;
    }
    ppcStack_140 = (char **)s_DefenderSetting__Load_bySentryCo_009acf74;
  }
  else {
    ppcStack_140 = (char **)s_DefenderSetting__Load_wTotalSize_009acf50;
  }
  ppcStack_148 = (char **)auStack_10c;
  pcStack_144 = &DAT_009ad040;
  puStack_14c = (undefined1 *)0x49764b;
  FUN_0044a580();
  puStack_14c = auStack_10c;
  ppcStack_150 = (char **)0x497655;
  FUN_00797b80();
  pcStack_144 = (char *)0x497664;
  ppcStack_140 = ppcVar3;
  (**(code **)(*DAT_00b5a69c + 8))();
  return 0;
}


// ==== FUN_00497890 @ 0x00497890 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00497890(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ad048;
  _DAT_00b5aa84 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00497910 @ 0x00497910 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00497910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ad424;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa44 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa44 = in_ECX;
  return;
}


// ==== FUN_00497960 @ 0x00497960 ====

uint FUN_00497960(undefined2 param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 uVar8;
  undefined1 *puVar9;
  undefined2 extraout_var;
  int *unaff_EBX;
  char *pcVar10;
  int iVar11;
  undefined1 auStack_11a [2];
  int *apiStack_104 [65];
  
  piVar1 = (int *)(**(code **)(*param_2 + 0x3c))();
  apiStack_104[0] = piVar1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(apiStack_104,&DAT_009ad41c);
    uVar3 = FUN_00797b80(apiStack_104);
    return uVar3 & 0xffff0000;
  }
  iVar11 = 0;
  (**(code **)(*piVar2 + 4))(0,4);
  uVar3 = 0;
  iVar4 = (**(code **)(*param_2 + 0x38))();
  if (iVar4 != 0) {
    do {
      iVar4 = (**(code **)(*param_2 + 0x34))(uVar3);
      iVar5 = (**(code **)(*piVar2 + 8))(4,iVar4);
      if (iVar5 != 4) {
        pcVar10 = s_DefenderSetting__Save_rGate_dwGa_009ad078;
        goto LAB_00497b4c;
      }
      iVar5 = (**(code **)(*piVar2 + 8))(1,iVar4 + 4);
      if (iVar5 != 1) {
        pcVar10 = s_DefenderSetting__Save_rGate_byLe_009ad0a0;
        goto LAB_00497b4c;
      }
      iVar4 = (**(code **)(*piVar2 + 8))(4,iVar4 + 8);
      if (iVar4 != 4) {
        pcVar10 = s_DefenderSetting__Save_rGate_dwAd_009ad0c8;
        goto LAB_00497b4c;
      }
      uVar3 = uVar3 + 1;
      uVar6 = (**(code **)(*param_2 + 0x38))();
    } while (uVar3 < uVar6);
    piVar1 = unaff_EBX;
  }
  piVar7 = (int *)(**(code **)(*piVar1 + 0xc))();
  do {
    if (piVar7 == (int *)0x0) {
      (**(code **)(*piVar2 + 4))(0,0,iVar11);
      iVar11 = (**(code **)(*piVar2 + 8))(2,auStack_11a + 2);
      if (iVar11 == 2) {
        iVar11 = (**(code **)(*piVar2 + 8))(1,auStack_11a + -8);
        if (iVar11 == 1) {
          iVar11 = (**(code **)(*piVar2 + 8))(1,auStack_11a + -7);
          if (iVar11 == 1) {
            (**(code **)(*DAT_00b5a69c + 0x10))(piVar2);
            return CONCAT22(extraout_var,param_1);
          }
          pcVar10 = s_DefenderSetting__Save_byLocateCo_009ad214;
        }
        else {
          pcVar10 = s_DefenderSetting__Save_byGateCoun_009ad1f0;
        }
      }
      else {
        pcVar10 = s_DefenderSetting__Save_wTotalSize_009ad1cc;
      }
LAB_00497b4c:
      FUN_0044a580(auStack_11a + 2,&DAT_009ad41c,pcVar10);
      FUN_00797b80(auStack_11a + 2);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar2);
      return uVar3 & 0xffff0000;
    }
    uVar8 = (**(code **)(*piVar7 + 8))();
    iVar4 = (**(code **)(*piVar2 + 8))(4,uVar8);
    if (iVar4 != 4) {
      pcVar10 = s_DefenderSetting__Save_pLocate_>G_009ad0f0;
      goto LAB_00497b4c;
    }
    iVar4 = (**(code **)(*piVar7 + 8))();
    iVar4 = (**(code **)(*piVar2 + 8))(2,iVar4 + 4);
    if (iVar4 != 2) {
      puVar9 = (undefined1 *)FUN_0044a580(auStack_11a + -6,s_SIZE____d_009ad128,iVar4);
      goto LAB_00497bd8;
    }
    iVar4 = (**(code **)(*piVar7 + 8))();
    iVar4 = (**(code **)(*piVar2 + 8))(2,iVar4 + 6);
    if (iVar4 != 2) {
      pcVar10 = s_DefenderSetting__Save_pLocate_>G_009ad134;
LAB_00497bc4:
      FUN_0044a580(auStack_11a + -6,&DAT_009ad41c,pcVar10);
      puVar9 = auStack_11a + -6;
LAB_00497bd8:
      FUN_00797b80(puVar9);
      uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar2);
      return uVar3 & 0xffff0000;
    }
    iVar4 = (**(code **)(*piVar7 + 8))();
    iVar4 = (**(code **)(*piVar2 + 8))(2,iVar4 + 8);
    if (iVar4 != 2) {
      pcVar10 = s_DefenderSetting__Save_pLocate_>G_009ad16c;
      goto LAB_00497bc4;
    }
    iVar4 = (**(code **)(*piVar7 + 8))();
    iVar4 = (**(code **)(*piVar2 + 8))(2,iVar4 + 10);
    if (iVar4 != 2) {
      pcVar10 = s_DefenderSetting__Save_pLocate_>G_009ad19c;
      goto LAB_00497bc4;
    }
    iVar11 = iVar11 + 0xc;
    piVar7 = (int *)(**(code **)(*piVar1 + 0x10))();
  } while( true );
}


// ==== FUN_00497c60 @ 0x00497c60 ====

uint FUN_00497c60(undefined2 param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined2 extraout_var;
  int *unaff_EBX;
  char *pcVar8;
  undefined1 auStack_11a [2];
  int *apiStack_104 [65];
  
  piVar1 = (int *)(**(code **)(*param_2 + 0x3c))();
  apiStack_104[0] = piVar1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a69c + 0xc))();
  if (piVar2 == (int *)0x0) {
    FUN_0044a580(apiStack_104,&DAT_009ad41c);
    uVar3 = FUN_00797b80(apiStack_104);
    return uVar3 & 0xffff0000;
  }
  (**(code **)(*piVar2 + 4))(0,4);
  uVar3 = 0;
  iVar4 = (**(code **)(*param_2 + 0x38))();
  if (iVar4 != 0) {
    do {
      iVar4 = (**(code **)(*param_2 + 0x34))(uVar3);
      iVar5 = (**(code **)(*piVar2 + 8))(4,iVar4);
      if (iVar5 != 4) {
        pcVar8 = s_DefenderSetting__Save_rGate_dwGa_009ad264;
        goto LAB_00497e35;
      }
      iVar5 = (**(code **)(*piVar2 + 8))(1,iVar4 + 4);
      if (iVar5 != 1) {
        pcVar8 = s_DefenderSetting__Save_rGate_byLe_009ad28c;
        goto LAB_00497e35;
      }
      iVar4 = (**(code **)(*piVar2 + 8))(4,iVar4 + 8);
      if (iVar4 != 4) {
        pcVar8 = s_DefenderSetting__Save_rGate_dwAd_009ad2b4;
        goto LAB_00497e35;
      }
      uVar3 = uVar3 + 1;
      uVar6 = (**(code **)(*param_2 + 0x38))();
    } while (uVar3 < uVar6);
    piVar1 = unaff_EBX;
  }
  piVar7 = (int *)(**(code **)(*piVar1 + 0xc))();
  if (piVar7 != (int *)0x0) {
    do {
      iVar4 = (**(code **)(*piVar7 + 8))();
      iVar4 = (**(code **)(*piVar2 + 8))(2,iVar4 + 4);
      if (iVar4 != 2) {
        pcVar8 = s_DefenderSetting__Save_pLocate_>G_009ad2dc;
        goto LAB_00497e35;
      }
      iVar4 = (**(code **)(*piVar7 + 8))();
      iVar4 = (**(code **)(*piVar2 + 8))(2,iVar4 + 6);
      if (iVar4 != 2) {
        pcVar8 = s_DefenderSetting__Save_pLocate_>G_009ad314;
        goto LAB_00497e35;
      }
      iVar4 = (**(code **)(*piVar7 + 8))();
      iVar4 = (**(code **)(*piVar2 + 8))(2,iVar4 + 8);
      if (iVar4 != 2) {
        pcVar8 = s_DefenderSetting__Save_pLocate_>G_009ad34c;
        goto LAB_00497e35;
      }
      iVar4 = (**(code **)(*piVar7 + 8))();
      iVar4 = (**(code **)(*piVar2 + 8))(2,iVar4 + 10);
      if (iVar4 != 2) {
        pcVar8 = s_DefenderSetting__Save_pLocate_>G_009ad37c;
        goto LAB_00497e35;
      }
      piVar7 = (int *)(**(code **)(*piVar1 + 0x10))();
    } while (piVar7 != (int *)0x0);
  }
  (**(code **)(*piVar2 + 4))(0,0);
  iVar4 = (**(code **)(*piVar2 + 8))(2,auStack_11a + 2);
  if (iVar4 == 2) {
    iVar4 = (**(code **)(*piVar2 + 8))(1,auStack_11a + -8);
    if (iVar4 == 1) {
      iVar4 = (**(code **)(*piVar2 + 8))(1,auStack_11a + -7);
      if (iVar4 == 1) {
        (**(code **)(*DAT_00b5a69c + 0x10))(piVar2);
        return CONCAT22(extraout_var,param_1);
      }
      pcVar8 = s_DefenderSetting__Save_byLocateCo_009ad3f4;
    }
    else {
      pcVar8 = s_DefenderSetting__Save_byGateCoun_009ad3d0;
    }
  }
  else {
    pcVar8 = s_DefenderSetting__Save_wTotalSize_009ad3ac;
  }
LAB_00497e35:
  FUN_0044a580(auStack_11a + 2,&DAT_009ad41c,pcVar8);
  FUN_00797b80(auStack_11a + 2);
  uVar3 = (**(code **)(*DAT_00b5a69c + 0x10))(piVar2);
  return uVar3 & 0xffff0000;
}


// ==== FUN_00497ef0 @ 0x00497ef0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00497ef0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ad424;
  _DAT_00b5aa44 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00497f30 @ 0x00497f30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00497f30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ad42c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa70 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa70 = in_ECX;
  return;
}


// ==== FUN_00497f80 @ 0x00497f80 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00497f80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ad42c;
  _DAT_00b5aa70 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00497fc0 @ 0x00497fc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00497fc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ad434;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5aa78 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5aa78 = in_ECX;
  return;
}


// ==== FUN_00498010 @ 0x00498010 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00498010(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ad434;
  _DAT_00b5aa78 = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00498050 @ 0x00498050 ====

void FUN_00498050(short param_1,int *param_2,int *param_3,undefined1 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  undefined1 uVar8;
  undefined1 auStack_100 [256];
  
  piVar1 = DAT_00b5a698;
  if (param_1 == 0) {
    uVar2 = (**(code **)(*param_2 + 0x70))();
    auStack_100[0] = 0;
    puVar3 = (undefined2 *)(**(code **)(*param_3 + 0x14))();
    iVar6 = *piVar1;
    iVar4 = (**(code **)(*param_3 + 0x14))();
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xc));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1c));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x1a));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x18));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x16));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x14));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x12));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x10));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xe));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1f));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 10));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 8));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 6));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 4));
    iVar4 = (**(code **)(*param_3 + 0x14))(*puVar3,*(undefined1 *)(iVar4 + 0x1e));
    uVar8 = *(undefined1 *)(iVar4 + 0x21);
    pcVar7 = s__________________________________009ad440;
  }
  else {
    iVar6 = *param_2;
    if (param_1 == 1) {
      uVar2 = (**(code **)(iVar6 + 0x70))();
      auStack_100[0] = 0;
      puVar3 = (undefined2 *)(**(code **)(*param_3 + 0x14))();
      iVar6 = *piVar1;
      iVar4 = (**(code **)(*param_3 + 0x14))();
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xc));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1c));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x1a));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x18));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x16));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x14));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x12));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x10));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xe));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1f));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 10));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 8));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 6));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 4));
      iVar4 = (**(code **)(*param_3 + 0x14))(*puVar3,*(undefined1 *)(iVar4 + 0x1e));
      uVar8 = *(undefined1 *)(iVar4 + 0x21);
      pcVar7 = s__________________________________009ad598;
    }
    else if (param_1 == 2) {
      uVar2 = (**(code **)(iVar6 + 0x70))();
      auStack_100[0] = 0;
      puVar3 = (undefined2 *)(**(code **)(*param_3 + 0x14))();
      iVar6 = *piVar1;
      iVar4 = (**(code **)(*param_3 + 0x14))();
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xc));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1c));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x1a));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x18));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x16));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x14));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x12));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x10));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xe));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1f));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 10));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 8));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 6));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 4));
      iVar4 = (**(code **)(*param_3 + 0x14))(*puVar3,*(undefined1 *)(iVar4 + 0x1e));
      uVar8 = *(undefined1 *)(iVar4 + 0x21);
      pcVar7 = s__________________________________009ad6f0;
    }
    else {
      if (param_1 == 3) {
        uVar2 = (**(code **)(iVar6 + 0x70))();
        auStack_100[0] = 0;
        puVar3 = (undefined2 *)(**(code **)(*param_3 + 0x14))();
        iVar6 = *piVar1;
        uVar5 = (**(code **)(*param_3 + 0x6c))();
        iVar4 = (**(code **)(*param_3 + 0x14))(uVar5);
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xc));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1c));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x1a));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x18));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x16));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x14));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x12));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x10));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xe));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1f));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 10));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 8));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 6));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 4));
        iVar4 = (**(code **)(*param_3 + 0x14))(*puVar3,*(undefined1 *)(iVar4 + 0x1e));
        uVar2 = FUN_0044a580(auStack_100,s__________________________________009ad860,uVar2,param_4,
                             *(undefined1 *)(iVar4 + 0x21));
        (**(code **)(iVar6 + 4))(uVar2);
        return;
      }
      uVar2 = (**(code **)(iVar6 + 0x70))();
      auStack_100[0] = 0;
      puVar3 = (undefined2 *)(**(code **)(*param_3 + 0x14))();
      iVar6 = *piVar1;
      iVar4 = (**(code **)(*param_3 + 0x14))();
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xc));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1c));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x1a));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x18));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x16));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x14));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x12));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x10));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xe));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1f));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 10));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 8));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 6));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 4));
      iVar4 = (**(code **)(*param_3 + 0x14))(*puVar3,*(undefined1 *)(iVar4 + 0x1e));
      uVar8 = *(undefined1 *)(iVar4 + 0x21);
      pcVar7 = s__________________________________009ad9c8;
    }
  }
  uVar2 = FUN_0044a580(auStack_100,pcVar7,uVar2,param_4,uVar8);
  (**(code **)(iVar6 + 4))(uVar2);
  return;
}


// ==== FUN_004985b0 @ 0x004985b0 ====

void FUN_004985b0(short param_1,int *param_2,int *param_3,undefined1 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  undefined1 uVar8;
  undefined1 auStack_100 [256];
  
  piVar1 = DAT_00b5a698;
  if (param_1 == 0) {
    uVar2 = (**(code **)(*param_2 + 0x70))();
    auStack_100[0] = 0;
    puVar3 = (undefined2 *)(**(code **)(*param_3 + 0x14))();
    iVar6 = *piVar1;
    iVar4 = (**(code **)(*param_3 + 0x14))();
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xc));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1c));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x1a));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x18));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x16));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x14));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x12));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x10));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xe));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1f));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 10));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 8));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 6));
    iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 4));
    iVar4 = (**(code **)(*param_3 + 0x14))(*puVar3,*(undefined1 *)(iVar4 + 0x1e));
    uVar8 = *(undefined1 *)(iVar4 + 0x21);
    pcVar7 = s__________________________________009adb28;
  }
  else {
    iVar6 = *param_2;
    if (param_1 == 1) {
      uVar2 = (**(code **)(iVar6 + 0x70))();
      auStack_100[0] = 0;
      puVar3 = (undefined2 *)(**(code **)(*param_3 + 0x14))();
      iVar6 = *piVar1;
      iVar4 = (**(code **)(*param_3 + 0x14))();
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xc));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1c));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x1a));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x18));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x16));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x14));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x12));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x10));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xe));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1f));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 10));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 8));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 6));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 4));
      iVar4 = (**(code **)(*param_3 + 0x14))(*puVar3,*(undefined1 *)(iVar4 + 0x1e));
      uVar8 = *(undefined1 *)(iVar4 + 0x21);
      pcVar7 = s__________________________________009adc80;
    }
    else if (param_1 == 2) {
      uVar2 = (**(code **)(iVar6 + 0x70))();
      auStack_100[0] = 0;
      puVar3 = (undefined2 *)(**(code **)(*param_3 + 0x14))();
      iVar6 = *piVar1;
      iVar4 = (**(code **)(*param_3 + 0x14))();
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xc));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1c));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x1a));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x18));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x16));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x14));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x12));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x10));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xe));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1f));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 10));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 8));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 6));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 4));
      iVar4 = (**(code **)(*param_3 + 0x14))(*puVar3,*(undefined1 *)(iVar4 + 0x1e));
      uVar8 = *(undefined1 *)(iVar4 + 0x21);
      pcVar7 = s__________________________________009addd8;
    }
    else {
      if (param_1 == 3) {
        uVar2 = (**(code **)(iVar6 + 0x70))();
        auStack_100[0] = 0;
        puVar3 = (undefined2 *)(**(code **)(*param_3 + 0x14))();
        iVar6 = *piVar1;
        uVar5 = (**(code **)(*param_3 + 0x6c))();
        iVar4 = (**(code **)(*param_3 + 0x14))(uVar5);
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xc));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1c));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x1a));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x18));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x16));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x14));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x12));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x10));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xe));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1f));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 10));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 8));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 6));
        iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 4));
        iVar4 = (**(code **)(*param_3 + 0x14))(*puVar3,*(undefined1 *)(iVar4 + 0x1e));
        uVar2 = FUN_0044a580(auStack_100,s__________________________________009adf38,uVar2,param_4,
                             *(undefined1 *)(iVar4 + 0x21));
        (**(code **)(iVar6 + 4))(uVar2);
        return;
      }
      uVar2 = (**(code **)(iVar6 + 0x70))();
      auStack_100[0] = 0;
      puVar3 = (undefined2 *)(**(code **)(*param_3 + 0x14))();
      iVar6 = *piVar1;
      iVar4 = (**(code **)(*param_3 + 0x14))();
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xc));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1c));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x1a));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x18));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x16));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x14));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0x12));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x10));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 0xe));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined1 *)(iVar4 + 0x1f));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 10));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 8));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 6));
      iVar4 = (**(code **)(*param_3 + 0x14))(*(undefined2 *)(iVar4 + 4));
      iVar4 = (**(code **)(*param_3 + 0x14))(*puVar3,*(undefined1 *)(iVar4 + 0x1e));
      uVar8 = *(undefined1 *)(iVar4 + 0x21);
      pcVar7 = s__________________________________009ae0a0;
    }
  }
  uVar2 = FUN_0044a580(auStack_100,pcVar7,uVar2,param_4,uVar8);
  (**(code **)(iVar6 + 4))(uVar2);
  return;
}


// ==== FUN_00498b30 @ 0x00498b30 ====

void FUN_00498b30(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e3e6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00498f30();
  FUN_00498eb0();
  FUN_00498e30();
  FUN_00498db0();
  if (DAT_00b5a694 == 0) {
    pvVar1 = operator_new(4);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_00498d30(pvVar1);
    }
    local_4 = 0xffffffff;
  }
  if (DAT_00b5a690 == 0) {
    pvVar1 = operator_new(4);
    local_4 = 1;
    if (pvVar1 != (void *)0x0) {
      FUN_00498c50(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00498bd0 @ 0x00498bd0 ====

void FUN_00498bd0(void)

{
  if (DAT_00b5a690 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a690)(1);
  }
  if (DAT_00b5a694 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a694)(1);
  }
  FUN_00498e00();
  FUN_00498f80();
  FUN_00498f00();
  FUN_00498e80();
  return;
}


// ==== FUN_00498c10 @ 0x00498c10 ====

void FUN_00498c10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae200;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00498c30 @ 0x00498c30 ====

void FUN_00498c30(void)

{
  return;
}


// ==== FUN_00498c40 @ 0x00498c40 ====

void FUN_00498c40(void)

{
  return;
}


// ==== FUN_00498c50 @ 0x00498c50 ====

void FUN_00498c50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae214;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a690 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a690 = in_ECX;
  return;
}


// ==== FUN_00498c80 @ 0x00498c80 ====

void FUN_00498c80(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a690 = 0;
  *in_ECX = &PTR_FUN_009ae200;
  return;
}


// ==== FUN_00498ca0 @ 0x00498ca0 ====

undefined4 FUN_00498ca0(void)

{
  undefined4 uVar1;
  
  if (DAT_00b5a6ac == (int *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00498caf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  return uVar1;
}


// ==== FUN_00498cc0 @ 0x00498cc0 ====

void FUN_00498cc0(byte param_1)

{
  void *in_ECX;
  
  FUN_00498c80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00498ce0 @ 0x00498ce0 ====

void FUN_00498ce0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae228;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00498d00 @ 0x00498d00 ====

void FUN_00498d00(void)

{
  return;
}


// ==== FUN_00498d10 @ 0x00498d10 ====

void FUN_00498d10(void)

{
  return;
}


// ==== FUN_00498d20 @ 0x00498d20 ====

void FUN_00498d20(void)

{
  return;
}


// ==== FUN_00498d30 @ 0x00498d30 ====

void FUN_00498d30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae23c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a694 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a694 = in_ECX;
  return;
}


// ==== FUN_00498d60 @ 0x00498d60 ====

void FUN_00498d60(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a694 = 0;
  *in_ECX = &PTR_FUN_009ae228;
  return;
}


// ==== FUN_00498d80 @ 0x00498d80 ====

void FUN_00498d80(byte param_1)

{
  void *in_ECX;
  
  FUN_00498d60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00498db0 @ 0x00498db0 ====

void FUN_00498db0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e3fb;
  local_c = ExceptionList;
  if (DAT_00b5a698 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(4);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_00498fd0(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00498e00 @ 0x00498e00 ====

void FUN_00498e00(void)

{
  if (DAT_00b5a698 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a698)(1);
  }
  return;
}


// ==== FUN_00498e30 @ 0x00498e30 ====

void FUN_00498e30(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e41b;
  local_c = ExceptionList;
  if (DAT_00b5a6a4 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(4);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_00499180(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00498e80 @ 0x00498e80 ====

void FUN_00498e80(void)

{
  if (DAT_00b5a6a4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6a4)(1);
  }
  return;
}


// ==== FUN_00498eb0 @ 0x00498eb0 ====

void FUN_00498eb0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e43b;
  local_c = ExceptionList;
  if (DAT_00b5a6a0 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_00499380(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00498f00 @ 0x00498f00 ====

void FUN_00498f00(void)

{
  if (DAT_00b5a6a0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a6a0)(1);
  }
  return;
}


// ==== FUN_00498f30 @ 0x00498f30 ====

void FUN_00498f30(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e45b;
  local_c = ExceptionList;
  if (DAT_00b5a69c == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0xc);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_00499e60(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00498f80 @ 0x00498f80 ====

void FUN_00498f80(void)

{
  if (DAT_00b5a69c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a69c)(1);
  }
  return;
}


// ==== FUN_00498fa0 @ 0x00498fa0 ====

void FUN_00498fa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae250;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00498fc0 @ 0x00498fc0 ====

void FUN_00498fc0(void)

{
  return;
}


// ==== FUN_00498fd0 @ 0x00498fd0 ====

void FUN_00498fd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae25c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a698 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a698 = in_ECX;
  return;
}


// ==== FUN_00499000 @ 0x00499000 ====

void FUN_00499000(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a698 = 0;
  *in_ECX = &PTR_FUN_009ae250;
  return;
}


// ==== FUN_00499020 @ 0x00499020 ====

void FUN_00499020(byte param_1)

{
  void *in_ECX;
  
  FUN_00499000();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499040 @ 0x00499040 ====

void FUN_00499040(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae268;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499060 @ 0x00499060 ====

undefined4 FUN_00499060(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e47b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(8);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_0049a900(pvVar1);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_004990c0 @ 0x004990c0 ====

undefined4 FUN_004990c0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e490;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_0049aaf0(pvVar1);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_00499120 @ 0x00499120 ====

undefined4 FUN_00499120(void)

{
  void *pvVar1;
  undefined4 uVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e4a5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0xc);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    ExceptionList = local_c;
    return 0;
  }
  uVar2 = FUN_0049abb0(pvVar1);
  ExceptionList = local_c;
  return uVar2;
}


// ==== FUN_00499180 @ 0x00499180 ====

void FUN_00499180(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae288;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a6a4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a6a4 = in_ECX;
  return;
}


// ==== FUN_004991b0 @ 0x004991b0 ====

void FUN_004991b0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004991c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)();
  return;
}


// ==== FUN_004991d0 @ 0x004991d0 ====

void FUN_004991d0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x004991e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)();
  return;
}


// ==== FUN_004991f0 @ 0x004991f0 ====

void FUN_004991f0(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00499202. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*param_1)();
  return;
}


// ==== FUN_00499210 @ 0x00499210 ====

void FUN_00499210(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5a6a4 = 0;
  *in_ECX = &PTR_FUN_009ae268;
  return;
}


// ==== FUN_00499230 @ 0x00499230 ====

void FUN_00499230(byte param_1)

{
  void *in_ECX;
  
  FUN_00499210();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499250 @ 0x00499250 ====

void FUN_00499250(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae4f0;
  return;
}


// ==== FUN_00499260 @ 0x00499260 ====

void FUN_00499260(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae4f0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499280 @ 0x00499280 ====

void FUN_00499280(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae508;
  return;
}


// ==== FUN_00499290 @ 0x00499290 ====

void FUN_00499290(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae520;
  return;
}


// ==== FUN_004992a0 @ 0x004992a0 ====

void FUN_004992a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae508;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004992c0 @ 0x004992c0 ====

void FUN_004992c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae520;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_004992e0 @ 0x004992e0 ====

void FUN_004992e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae538;
  return;
}


// ==== FUN_004992f0 @ 0x004992f0 ====

void FUN_004992f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae540;
  return;
}


// ==== FUN_00499300 @ 0x00499300 ====

void FUN_00499300(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae538;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499320 @ 0x00499320 ====

void FUN_00499320(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae540;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499340 @ 0x00499340 ====

void FUN_00499340(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00499360 @ 0x00499360 ====

void FUN_00499360(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00499380 @ 0x00499380 ====

void FUN_00499380(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e4b8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae588;
  pvVar1 = operator_new(0x518);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00499660();
  }
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x518);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004996d0();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a6a0 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a6a0 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00499430 @ 0x00499430 ====

void FUN_00499430(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e4ca;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ae588;
  DAT_00b5a6a0 = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009ae4f0;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_004994a0 @ 0x004994a0 ====

undefined4 * FUN_004994a0(void)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e4dc;
  pvStack_c = ExceptionList;
  piVar1 = *(int **)(in_ECX + 4);
  local_4 = 0;
  ExceptionList = &pvStack_c;
  puVar3 = (undefined4 *)(**(code **)(*piVar1 + 0xc))(1,0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(1,0);
  }
  cVar2 = FUN_0049aed0(local_4);
  pvStack_c = (void *)0xffffffff;
  if (cVar2 == '\x01') {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(1,0);
    }
    ExceptionList = (void *)0x0;
    return puVar3;
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(1,puVar3);
    ExceptionList = puVar3;
    return (undefined4 *)0x0;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  ExceptionList = (void *)0x0;
  return (undefined4 *)0x0;
}


// ==== FUN_00499580 @ 0x00499580 ====

undefined4 * FUN_00499580(void)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e4ee;
  pvStack_c = ExceptionList;
  piVar1 = *(int **)(in_ECX + 8);
  local_4 = 0;
  ExceptionList = &pvStack_c;
  puVar3 = (undefined4 *)(**(code **)(*piVar1 + 0xc))(1,0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(1,0);
  }
  cVar2 = FUN_0049ad30(local_4);
  pvStack_c = (void *)0xffffffff;
  if (cVar2 == '\x01') {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(1,0);
    }
    ExceptionList = (void *)0x0;
    return puVar3;
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(1,puVar3);
    ExceptionList = puVar3;
    return (undefined4 *)0x0;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  ExceptionList = (void *)0x0;
  return (undefined4 *)0x0;
}


// ==== FUN_00499660 @ 0x00499660 ====

void FUN_00499660(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009ae548;
  in_ECX[1] = &PTR_FUN_009ae538;
  in_ECX[0x142] = 0;
  in_ECX[0x142] = in_ECX[0x142] + 0x40;
  in_ECX[0x145] = in_ECX + 2;
  in_ECX[0x143] = 0;
  in_ECX[0x144] = 0;
  iVar2 = 0x3f;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x13f] = 0;
  in_ECX[0x140] = 0;
  in_ECX[0x141] = 0;
  return;
}


// ==== FUN_004996d0 @ 0x004996d0 ====

void FUN_004996d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009ae560;
  in_ECX[1] = &PTR_FUN_009ae540;
  in_ECX[0x142] = 0;
  in_ECX[0x142] = in_ECX[0x142] + 0x40;
  in_ECX[0x145] = in_ECX + 2;
  in_ECX[0x143] = 0;
  in_ECX[0x144] = 0;
  iVar2 = 0x3f;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x13f] = 0;
  in_ECX[0x140] = 0;
  in_ECX[0x141] = 0;
  return;
}


// ==== FUN_00499740 @ 0x00499740 ====

undefined4 FUN_00499740(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x50c);
}


// ==== FUN_00499750 @ 0x00499750 ====

int FUN_00499750(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e50b;
  local_c = ExceptionList;
  if (param_2 == 0) {
    pvVar2 = *(void **)(in_ECX + 0x514);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x50c) = *(int *)(in_ECX + 0x50c) + 1;
    if (pvVar2 == (void *)0x0) {
      pvVar2 = operator_new(0x14);
      *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0x510);
      *(void **)(in_ECX + 0x510) = pvVar2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x514) = *(undefined4 *)((int)pvVar2 + 8);
    }
    *(undefined4 *)((int)pvVar2 + 8) = 0;
    *(int *)((int)pvVar2 + 0x10) = param_1;
    param_2 = FUN_0049add0();
  }
  else {
    if (*(int *)(param_2 + 0x10) == 0) {
      local_10c[0] = 0;
      local_4 = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_framewo_009ae5a0,0x81);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00499840 @ 0x00499840 ====

undefined4 FUN_00499840(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if ((uint)param_2[4] < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_framewo_009ae5a0,0xa5);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = param_2 + 4;
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return param_2[4];
    }
    (**(code **)*param_2)(0);
    param_2[2] = *(undefined4 *)(in_ECX + 0x514);
    *(int *)(in_ECX + 0x50c) = *(int *)(in_ECX + 0x50c) + -1;
    *(undefined4 **)(in_ECX + 0x514) = param_2;
  }
  return 0;
}


// ==== FUN_004998d0 @ 0x004998d0 ====

int FUN_004998d0(int param_1,int param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(int *)(param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_framewo_009ae5a0,0x81);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)(param_2 + 0x10) = *(int *)(param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x514);
  *(int *)(in_ECX + 0x50c) = *(int *)(in_ECX + 0x50c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0x510);
    *(void **)(in_ECX + 0x510) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x514) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  iVar3 = FUN_0049af70();
  return iVar3;
}


// ==== FUN_00499990 @ 0x00499990 ====

void FUN_00499990(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae578;
  if ((int *)in_ECX[2] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[2] + 0x10))(1,in_ECX[1]);
    in_ECX[1] = 0;
    return;
  }
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  return;
}


// ==== FUN_004999d0 @ 0x004999d0 ====

void FUN_004999d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae580;
  if ((int *)in_ECX[2] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[2] + 0x10))(1,in_ECX[1]);
    in_ECX[1] = 0;
    return;
  }
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  return;
}


// ==== FUN_00499a10 @ 0x00499a10 ====

void FUN_00499a10(byte param_1)

{
  void *in_ECX;
  
  FUN_00499a30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499a30 @ 0x00499a30 ====

void FUN_00499a30(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e539;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae548;
  local_4 = 1;
  if (in_ECX[0x143] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ae2f8,
                         s_d__usa_24_0_1_2__develop_framewo_009ae2b0,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 6;
  iVar3 = 0x40;
  do {
    if (*piVar2 != 0) {
      local_10c[0] = 0;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ae358,
                           s_d__usa_24_0_1_2__develop_framewo_009ae310,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 5;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x144];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009ae538;
    *in_ECX = &PTR_FUN_009ae508;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0x10) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ae3b8,
                         s_d__usa_24_0_1_2__develop_framewo_009ae370,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_00499b50 @ 0x00499b50 ====

void FUN_00499b50(byte param_1)

{
  void *in_ECX;
  
  FUN_00499b70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499b70 @ 0x00499b70 ====

void FUN_00499b70(void)

{
  void *_Memory;
  undefined4 uVar1;
  undefined4 *in_ECX;
  int *piVar2;
  int iVar3;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e569;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae560;
  local_4 = 1;
  if (in_ECX[0x143] != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ae418,
                         s_d__usa_24_0_1_2__develop_framewo_009ae3d0,0x57);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  piVar2 = in_ECX + 6;
  iVar3 = 0x40;
  do {
    if (*piVar2 != 0) {
      local_10c[0] = 0;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ae478,
                           s_d__usa_24_0_1_2__develop_framewo_009ae430,0x5b);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    piVar2 = piVar2 + 5;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  _Memory = (void *)in_ECX[0x144];
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009ae540;
    *in_ECX = &PTR_FUN_009ae520;
    ExceptionList = local_c;
    return;
  }
  if (*(int *)((int)_Memory + 0x10) != 0) {
    local_10c[0] = 0;
    uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_009ae4d8,
                         s_d__usa_24_0_1_2__develop_framewo_009ae490,0x65);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(_Memory);
  return;
}


// ==== FUN_00499c90 @ 0x00499c90 ====

void FUN_00499c90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae578;
  if ((int *)in_ECX[2] == (int *)0x0) {
    if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[1])(1);
    }
  }
  else {
    (**(code **)(*(int *)in_ECX[2] + 0x10))(1,in_ECX[1]);
  }
  in_ECX[1] = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499ce0 @ 0x00499ce0 ====

void FUN_00499ce0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae580;
  if ((int *)in_ECX[2] == (int *)0x0) {
    if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[1])(1);
    }
  }
  else {
    (**(code **)(*(int *)in_ECX[2] + 0x10))(1,in_ECX[1]);
  }
  in_ECX[1] = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499d30 @ 0x00499d30 ====

void FUN_00499d30(byte param_1)

{
  void *in_ECX;
  
  FUN_00499430();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499d50 @ 0x00499d50 ====

void FUN_00499d50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae5ec;
  return;
}


// ==== FUN_00499d60 @ 0x00499d60 ====

void FUN_00499d60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae5ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499d80 @ 0x00499d80 ====

void FUN_00499d80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae604;
  return;
}


// ==== FUN_00499d90 @ 0x00499d90 ====

void FUN_00499d90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae61c;
  return;
}


// ==== FUN_00499da0 @ 0x00499da0 ====

void FUN_00499da0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae604;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499dc0 @ 0x00499dc0 ====

void FUN_00499dc0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae61c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00499df0 @ 0x00499df0 ====

void FUN_00499df0(void)

{
  FUN_0049b110();
  return;
}


// ==== FUN_00499e10 @ 0x00499e10 ====

void FUN_00499e10(void)

{
  FUN_0049b200();
  return;
}


// ==== FUN_00499e20 @ 0x00499e20 ====

void FUN_00499e20(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00499e40 @ 0x00499e40 ====

void FUN_00499e40(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00499e60 @ 0x00499e60 ====

void FUN_00499e60(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0097e61e;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae684;
  pvVar1 = operator_new(0x718);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0049a170();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x718);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0049a240();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5a69c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5a69c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00499f20 @ 0x00499f20 ====

void FUN_00499f20(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e630;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ae684;
  DAT_00b5a69c = 0;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009ae5ec;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00499f90 @ 0x00499f90 ====

undefined4 * FUN_00499f90(void)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e642;
  pvStack_c = ExceptionList;
  piVar1 = *(int **)(in_ECX + 4);
  local_4 = 0;
  ExceptionList = &pvStack_c;
  puVar3 = (undefined4 *)(**(code **)(*piVar1 + 0xc))(1,0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(1,0);
  }
  cVar2 = FUN_0049b160(local_4);
  pvStack_c = (void *)0xffffffff;
  if (cVar2 == '\x01') {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(1,0);
    }
    ExceptionList = (void *)0x0;
    return puVar3;
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(1,puVar3);
    ExceptionList = puVar3;
    return (undefined4 *)0x0;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  ExceptionList = (void *)0x0;
  return (undefined4 *)0x0;
}


// ==== FUN_0049a070 @ 0x0049a070 ====

undefined4 * FUN_0049a070(void)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e654;
  pvStack_c = ExceptionList;
  piVar1 = *(int **)(in_ECX + 8);
  local_4 = 0;
  ExceptionList = &pvStack_c;
  puVar3 = (undefined4 *)(**(code **)(*piVar1 + 0xc))(1,0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(1,0);
  }
  cVar2 = FUN_0049b070(local_4);
  pvStack_c = (void *)0xffffffff;
  if (cVar2 == '\x01') {
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x10))(1,0);
    }
    ExceptionList = (void *)0x0;
    return puVar3;
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(1,puVar3);
    ExceptionList = puVar3;
    return (undefined4 *)0x0;
  }
  if (puVar3 != (undefined4 *)0x0) {
    (**(code **)*puVar3)(1);
  }
  ExceptionList = (void *)0x0;
  return (undefined4 *)0x0;
}


// ==== FUN_0049a150 @ 0x0049a150 ====

void FUN_0049a150(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae634;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,0x40,(_func_void_void_ptr *)&LAB_00499de0);
  return;
}


// ==== FUN_0049a170 @ 0x0049a170 ====

void FUN_0049a170(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e588;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae644;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ae634;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x1c,0x40,FUN_00499df0,(_func_void_void_ptr *)&LAB_00499de0);
  in_ECX[0x1c2] = 0;
  in_ECX[0x1c2] = in_ECX[0x1c2] + 0x40;
  in_ECX[0x1c5] = in_ECX + 2;
  in_ECX[0x1c3] = 0;
  in_ECX[0x1c4] = 0;
  iVar2 = 0x3f;
  puVar1 = in_ECX;
  do {
    puVar1[6] = puVar1 + 9;
    puVar1[7] = 0;
    puVar1[8] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 7;
  } while (iVar2 != 0);
  in_ECX[0x1bf] = 0;
  in_ECX[0x1c0] = 0;
  in_ECX[0x1c1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049a220 @ 0x0049a220 ====

void FUN_0049a220(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae63c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x1c,0x40,(_func_void_void_ptr *)&LAB_00499e00);
  return;
}


// ==== FUN_0049a240 @ 0x0049a240 ====

void FUN_0049a240(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e5a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae65c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009ae63c;
  _eh_vector_constructor_iterator_
            (in_ECX + 2,0x1c,0x40,FUN_00499e10,(_func_void_void_ptr *)&LAB_00499e00);
  in_ECX[0x1c2] = 0;
  in_ECX[0x1c2] = in_ECX[0x1c2] + 0x40;
  in_ECX[0x1c5] = in_ECX + 2;
  in_ECX[0x1c3] = 0;
  in_ECX[0x1c4] = 0;
  iVar2 = 0x3f;
  puVar1 = in_ECX;
  do {
    puVar1[6] = puVar1 + 9;
    puVar1[7] = 0;
    puVar1[8] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 7;
  } while (iVar2 != 0);
  in_ECX[0x1bf] = 0;
  in_ECX[0x1c0] = 0;
  in_ECX[0x1c1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== __break @ 0x0049a2ee ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== __break @ 0x0049a2ef ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_0049a2f0 @ 0x0049a2f0 ====

undefined4 FUN_0049a2f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x70c);
}


// ==== FUN_0049a300 @ 0x0049a300 ====

void FUN_0049a300(byte param_1)

{
  void *in_ECX;
  
  FUN_0049a150();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049a320 @ 0x0049a320 ====

void FUN_0049a320(byte param_1)

{
  void *in_ECX;
  
  FUN_0049a340();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049a340 @ 0x0049a340 ====

void FUN_0049a340(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e5d3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae644;
  _Memory = (void *)in_ECX[0x1c4];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ae634;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,0x40,(_func_void_void_ptr *)&LAB_00499de0);
    *in_ECX = &PTR_FUN_009ae604;
    ExceptionList = local_c;
    return;
  }
  FUN_0049b050();
  _free(_Memory);
  return;
}


// ==== FUN_0049a3d0 @ 0x0049a3d0 ====

void FUN_0049a3d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0049a220();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049a3f0 @ 0x0049a3f0 ====

void FUN_0049a3f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0049a410();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049a410 @ 0x0049a410 ====

void FUN_0049a410(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e5f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae65c;
  _Memory = (void *)in_ECX[0x1c4];
  local_4 = 1;
  if (_Memory == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009ae63c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x1c,0x40,(_func_void_void_ptr *)&LAB_00499e00);
    *in_ECX = &PTR_FUN_009ae61c;
    ExceptionList = local_c;
    return;
  }
  FUN_0049b140();
  _free(_Memory);
  return;
}


// ==== FUN_0049a4a0 @ 0x0049a4a0 ====

void * FUN_0049a4a0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e679;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x714);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x70c) = *(int *)(in_ECX + 0x70c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x1c);
      local_4 = 1;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0049b110();
      }
      *(undefined4 *)((int)param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x710);
      *(void **)(in_ECX + 0x710) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x714) = *(undefined4 *)((int)param_2 + 0x10);
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
                           s_d__usa_24_0_1_2__develop_framewo_009ae698,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x18) = *(int *)((int)param_2 + 0x18) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0049a5b0 @ 0x0049a5b0 ====

void * FUN_0049a5b0(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e69e;
  local_c = ExceptionList;
  if (param_2 == (void *)0x0) {
    param_2 = *(void **)(in_ECX + 0x714);
    ExceptionList = &local_c;
    *(int *)(in_ECX + 0x70c) = *(int *)(in_ECX + 0x70c) + 1;
    if (param_2 == (void *)0x0) {
      param_2 = operator_new(0x1c);
      local_4 = 0;
      if (param_2 == (void *)0x0) {
        param_2 = (void *)0x0;
      }
      else {
        FUN_0049b200();
      }
      *(undefined4 *)((int)param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x710);
      *(void **)(in_ECX + 0x710) = param_2;
    }
    else {
      *(undefined4 *)(in_ECX + 0x714) = *(undefined4 *)((int)param_2 + 0x10);
    }
    *(undefined4 *)((int)param_2 + 0x10) = 0;
    *(int *)((int)param_2 + 0x18) = param_1;
  }
  else {
    if (*(int *)((int)param_2 + 0x18) == 0) {
      local_10c[0] = 0;
      ExceptionList = &local_c;
      uVar1 = FUN_0044a580(local_10c,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_framewo_009ae698,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x18) = *(int *)((int)param_2 + 0x18) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_0049a6a0 @ 0x0049a6a0 ====

undefined4 FUN_0049a6a0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x18) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_framewo_009ae698,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x18);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x18);
    }
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x714);
    *(int *)(in_ECX + 0x70c) = *(int *)(in_ECX + 0x70c) + -1;
    *(int *)(in_ECX + 0x714) = param_2;
  }
  return 0;
}


// ==== FUN_0049a720 @ 0x0049a720 ====

void FUN_0049a720(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae674;
  if ((int *)in_ECX[2] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[2] + 0x10))(1,in_ECX[1]);
    in_ECX[1] = 0;
    return;
  }
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  return;
}


// ==== FUN_0049a760 @ 0x0049a760 ====

void FUN_0049a760(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae67c;
  if ((int *)in_ECX[2] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[2] + 0x10))(1,in_ECX[1]);
    in_ECX[1] = 0;
    return;
  }
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  return;
}


// ==== FUN_0049a7a0 @ 0x0049a7a0 ====

void FUN_0049a7a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae674;
  if ((int *)in_ECX[2] == (int *)0x0) {
    if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[1])(1);
    }
  }
  else {
    (**(code **)(*(int *)in_ECX[2] + 0x10))(1,in_ECX[1]);
  }
  in_ECX[1] = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049a7f0 @ 0x0049a7f0 ====

void FUN_0049a7f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae67c;
  if ((int *)in_ECX[2] == (int *)0x0) {
    if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[1])(1);
    }
  }
  else {
    (**(code **)(*(int *)in_ECX[2] + 0x10))(1,in_ECX[1]);
  }
  in_ECX[1] = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049a840 @ 0x0049a840 ====

void FUN_0049a840(byte param_1)

{
  void *in_ECX;
  
  FUN_00499f20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049a860 @ 0x0049a860 ====

void FUN_0049a860(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae760;
  return;
}


// ==== FUN_0049a870 @ 0x0049a870 ====

void FUN_0049a870(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae760;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049a890 @ 0x0049a890 ====

void FUN_0049a890(void)

{
  DWORD DVar1;
  int in_ECX;
  
  do {
    DVar1 = WaitForSingleObject(*(HANDLE *)(in_ECX + 4),1000);
  } while (DVar1 != 0);
  return;
}


// ==== FUN_0049a8c0 @ 0x0049a8c0 ====

bool FUN_0049a8c0(void)

{
  DWORD DVar1;
  int in_ECX;
  
  DVar1 = WaitForSingleObject(*(HANDLE *)(in_ECX + 4),0);
  return DVar1 == 0;
}


// ==== FUN_0049a8e0 @ 0x0049a8e0 ====

void FUN_0049a8e0(void)

{
  DWORD DVar1;
  int in_ECX;
  
  do {
    DVar1 = WaitForSingleObject(*(HANDLE *)(in_ECX + 4),0);
  } while (DVar1 != 0);
  return;
}


// ==== FUN_0049a900 @ 0x0049a900 ====

void FUN_0049a900(void)

{
  HANDLE pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e6bb;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae778;
  pvVar1 = CreateSemaphoreA((LPSECURITY_ATTRIBUTES)0x0,0,0xffff,(LPCSTR)0x0);
  in_ECX[1] = pvVar1;
  if (pvVar1 == (HANDLE)0x0) {
    local_10c[0] = 0;
    uVar2 = FUN_0044a580(local_10c,s_File___s__Line___d_009ae6f8,s___Monitor_Count_cpp_009ae6e4,0xf)
    ;
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049a990 @ 0x0049a990 ====

void FUN_0049a990(void)

{
  BOOL BVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e6d0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae778;
  local_4 = 0;
  BVar1 = CloseHandle((HANDLE)in_ECX[1]);
  if (BVar1 == 0) {
    local_10c[0] = 0;
    uVar2 = FUN_0044a580(local_10c,s_File___s__Line___d_009ae720,s___Monitor_Count_cpp_009ae70c,0x1a
                        );
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  *in_ECX = &PTR_FUN_009ae760;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049aa20 @ 0x0049aa20 ====

void FUN_0049aa20(void)

{
  BOOL BVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  BVar1 = ReleaseSemaphore(*(HANDLE *)(in_ECX + 4),1,(LPLONG)0x0);
  if (BVar1 == 0) {
    local_100[0] = 0;
    uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_009ae748,s___Monitor_Count_cpp_009ae734,0x44
                        );
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  return;
}


// ==== FUN_0049aa70 @ 0x0049aa70 ====

void FUN_0049aa70(byte param_1)

{
  void *in_ECX;
  
  FUN_0049a990();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049aa90 @ 0x0049aa90 ====

void FUN_0049aa90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae790;
  DeleteCriticalSection((LPCRITICAL_SECTION)(in_ECX + 1));
  *in_ECX = &PTR_FUN_009ae760;
  return;
}


// ==== FUN_0049aab0 @ 0x0049aab0 ====

void FUN_0049aab0(void)

{
  int in_ECX;
  
  EnterCriticalSection((LPCRITICAL_SECTION)(in_ECX + 4));
  return;
}


// ==== FUN_0049aac0 @ 0x0049aac0 ====

void FUN_0049aac0(void)

{
  int in_ECX;
  
  LeaveCriticalSection((LPCRITICAL_SECTION)(in_ECX + 4));
  return;
}


// ==== FUN_0049aad0 @ 0x0049aad0 ====

undefined1 FUN_0049aad0(void)

{
  return 0;
}


// ==== FUN_0049aae0 @ 0x0049aae0 ====

void FUN_0049aae0(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0049aae2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 4))();
  return;
}


// ==== FUN_0049aaf0 @ 0x0049aaf0 ====

void FUN_0049aaf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae790;
  InitializeCriticalSection((LPCRITICAL_SECTION)(in_ECX + 1));
  return;
}


// ==== FUN_0049ab10 @ 0x0049ab10 ====

void FUN_0049ab10(byte param_1)

{
  void *in_ECX;
  
  FUN_0049aa90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049ab30 @ 0x0049ab30 ====

void FUN_0049ab30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae7a8;
  return;
}


// ==== FUN_0049ab40 @ 0x0049ab40 ====

void FUN_0049ab40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae7a8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049ab60 @ 0x0049ab60 ====

void FUN_0049ab60(undefined4 *param_1)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = param_1[1];
  if (iVar2 != 0) {
    *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + iVar2;
    piVar1 = (int *)*param_1;
    (**(code **)(*piVar1 + 8))();
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      (**(code **)(**(int **)(in_ECX + 4) + 4))();
    }
    (**(code **)(*piVar1 + 4))();
  }
  return;
}


// ==== FUN_0049abb0 @ 0x0049abb0 ====

void FUN_0049abb0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e6f3;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae7b8;
  in_ECX[2] = 0;
  pvVar1 = operator_new(8);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0049a900();
  in_ECX[1] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049ac30 @ 0x0049ac30 ====

void FUN_0049ac30(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e705;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae7b8;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009ae7a8;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049ac90 @ 0x0049ac90 ====

void FUN_0049ac90(undefined4 *param_1)

{
  int *piVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = param_1[1];
  piVar1 = (int *)*param_1;
  if (uVar2 == 0) {
    (**(code **)(*piVar1 + 8))();
    return;
  }
  if (*(int *)(in_ECX + 8) == 0) {
    (**(code **)(*piVar1 + 8))();
    return;
  }
  if (*(uint *)(in_ECX + 8) <= uVar2) {
    uVar2 = *(uint *)(in_ECX + 8);
  }
  *(uint *)(in_ECX + 8) = *(int *)(in_ECX + 8) - uVar2;
  (**(code **)(*piVar1 + 8))();
  for (; uVar2 != 0; uVar2 = uVar2 - 1) {
    (**(code **)(**(int **)(in_ECX + 4) + 8))();
  }
  return;
}


// ==== FUN_0049acf0 @ 0x0049acf0 ====

void FUN_0049acf0(byte param_1)

{
  void *in_ECX;
  
  FUN_0049ac30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049ad10 @ 0x0049ad10 ====

void FUN_0049ad10(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae824;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049ad30 @ 0x0049ad30 ====

bool FUN_0049ad30(LPCSTR param_1)

{
  HANDLE pvVar1;
  int in_ECX;
  
  pvVar1 = CreateFileA(param_1,0x40000000,1,(LPSECURITY_ATTRIBUTES)0x0,4,0x80,(HANDLE)0x0);
  *(HANDLE *)(in_ECX + 4) = pvVar1;
  return pvVar1 != (HANDLE)0xffffffff;
}


// ==== FUN_0049ad60 @ 0x0049ad60 ====

DWORD FUN_0049ad60(int param_1,LONG param_2)

{
  int in_ECX;
  DWORD DVar1;
  
  DVar1 = 1;
  if (param_1 == 0) {
    DVar1 = 0;
  }
  else if (param_1 != 1) {
    if (param_1 != 2) {
      return 0xffffffff;
    }
    DVar1 = 2;
  }
  DVar1 = SetFilePointer(*(HANDLE *)(in_ECX + 4),param_2,(PLONG)0x0,DVar1);
  if ((DVar1 == 0xffffffff) || ((int)DVar1 < 0)) {
    return 0xffffffff;
  }
  return DVar1;
}


// ==== FUN_0049ada0 @ 0x0049ada0 ====

uint FUN_0049ada0(DWORD param_1,LPCVOID param_2)

{
  BOOL BVar1;
  int in_ECX;
  DWORD local_4;
  
  local_4 = 0;
  BVar1 = WriteFile(*(HANDLE *)(in_ECX + 4),param_2,param_1,&local_4,(LPOVERLAPPED)0x0);
  return -(uint)(BVar1 != 0) & local_4;
}


// ==== FUN_0049add0 @ 0x0049add0 ====

void FUN_0049add0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae830;
  in_ECX[1] = 0xffffffff;
  return;
}


// ==== FUN_0049ade0 @ 0x0049ade0 ====

void FUN_0049ade0(void)

{
  BOOL BVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e71b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae830;
  local_4 = 0;
  if ((HANDLE)in_ECX[1] != (HANDLE)0xffffffff) {
    BVar1 = SetEndOfFile((HANDLE)in_ECX[1]);
    if (BVar1 == 0) {
      local_10c[0] = 0;
      uVar2 = FUN_0044a580(local_10c,s_File___s__Line___d_009ae7e0,s___Storage_Writer_cpp_009ae7c8,
                           0x1d);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    BVar1 = CloseHandle((HANDLE)in_ECX[1]);
    if (BVar1 == 0) {
      local_10c[0] = 0;
      uVar2 = FUN_0044a580(local_10c,s_File___s__Line___d_009ae80c,s___Storage_Writer_cpp_009ae7f4,
                           0x20);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
  }
  *in_ECX = &PTR_FUN_009ae824;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049aea0 @ 0x0049aea0 ====

void FUN_0049aea0(byte param_1)

{
  void *in_ECX;
  
  FUN_0049ade0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049aec0 @ 0x0049aec0 ====

void FUN_0049aec0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae824;
  return;
}


// ==== FUN_0049aed0 @ 0x0049aed0 ====

bool FUN_0049aed0(LPCSTR param_1)

{
  HANDLE pvVar1;
  int in_ECX;
  
  pvVar1 = CreateFileA(param_1,0x80000000,1,(LPSECURITY_ATTRIBUTES)0x0,3,0x80,(HANDLE)0x0);
  *(HANDLE *)(in_ECX + 4) = pvVar1;
  return pvVar1 != (HANDLE)0xffffffff;
}


// ==== FUN_0049af00 @ 0x0049af00 ====

DWORD FUN_0049af00(int param_1,LONG param_2)

{
  int in_ECX;
  DWORD DVar1;
  
  DVar1 = 1;
  if (param_1 == 0) {
    DVar1 = 0;
  }
  else if (param_1 != 1) {
    if (param_1 != 2) {
      return 0xffffffff;
    }
    DVar1 = 2;
  }
  DVar1 = SetFilePointer(*(HANDLE *)(in_ECX + 4),param_2,(PLONG)0x0,DVar1);
  if ((DVar1 == 0xffffffff) || ((int)DVar1 < 0)) {
    return 0xffffffff;
  }
  return DVar1;
}


// ==== FUN_0049af40 @ 0x0049af40 ====

uint FUN_0049af40(DWORD param_1,LPVOID param_2)

{
  BOOL BVar1;
  int in_ECX;
  DWORD local_4;
  
  local_4 = 0;
  BVar1 = ReadFile(*(HANDLE *)(in_ECX + 4),param_2,param_1,&local_4,(LPOVERLAPPED)0x0);
  return -(uint)(BVar1 != 0) & local_4;
}


// ==== FUN_0049af70 @ 0x0049af70 ====

void FUN_0049af70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae870;
  in_ECX[1] = 0xffffffff;
  return;
}


// ==== FUN_0049af80 @ 0x0049af80 ====

void FUN_0049af80(void)

{
  BOOL BVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e73b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ae870;
  local_4 = 0;
  if ((HANDLE)in_ECX[1] != (HANDLE)0xffffffff) {
    BVar1 = CloseHandle((HANDLE)in_ECX[1]);
    if (BVar1 == 0) {
      local_10c[0] = 0;
      uVar2 = FUN_0044a580(local_10c,s_File___s__Line___d_009ae858,s___Storage_Reader_cpp_009ae840,
                           0x1d);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
  }
  *in_ECX = &PTR_FUN_009ae824;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049b010 @ 0x0049b010 ====

void FUN_0049b010(byte param_1)

{
  void *in_ECX;
  
  FUN_0049af80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049b030 @ 0x0049b030 ====

void FUN_0049b030(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae880;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049b050 @ 0x0049b050 ====

void FUN_0049b050(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae880;
  return;
}


// ==== FUN_0049b070 @ 0x0049b070 ====

undefined4 FUN_0049b070(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1[1];
  *(int *)(in_ECX + 0xc) = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  *(int *)(in_ECX + 8) = iVar1;
  iVar1 = *(int *)(in_ECX + 0xc) + *param_1;
  *(int *)(in_ECX + 4) = iVar1;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== FUN_0049b0a0 @ 0x0049b0a0 ====

uint FUN_0049b0a0(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = 0;
  if (param_1 == 0) {
    iVar2 = *(int *)(in_ECX + 0xc);
  }
  else if (param_1 == 1) {
    iVar2 = *(int *)(in_ECX + 8);
  }
  else {
    if (param_1 != 2) goto LAB_0049b0c5;
    iVar2 = *(int *)(in_ECX + 4);
  }
  uVar1 = iVar2 + param_2;
LAB_0049b0c5:
  if ((uVar1 < *(uint *)(in_ECX + 0xc)) || (*(uint *)(in_ECX + 4) <= uVar1)) {
    return 0;
  }
  *(uint *)(in_ECX + 8) = uVar1;
  return uVar1;
}


// ==== FUN_0049b0e0 @ 0x0049b0e0 ====

uint FUN_0049b0e0(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(int *)(in_ECX + 4) - *(int *)(in_ECX + 8);
  if (uVar1 < param_1) {
    param_1 = uVar1;
  }
  FUN_00797a80(*(int *)(in_ECX + 8),param_2,param_1);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return param_1;
}


// ==== FUN_0049b110 @ 0x0049b110 ====

void FUN_0049b110(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae88c;
  return;
}


// ==== FUN_0049b120 @ 0x0049b120 ====

void FUN_0049b120(byte param_1)

{
  void *in_ECX;
  
  FUN_0049b050();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049b140 @ 0x0049b140 ====

void FUN_0049b140(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae880;
  return;
}


// ==== FUN_0049b160 @ 0x0049b160 ====

undefined4 FUN_0049b160(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1[1];
  *(int *)(in_ECX + 0xc) = iVar1;
  if (iVar1 == 0) {
    return 0;
  }
  *(int *)(in_ECX + 8) = iVar1;
  iVar1 = *(int *)(in_ECX + 0xc) + *param_1;
  *(int *)(in_ECX + 4) = iVar1;
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}


// ==== FUN_0049b190 @ 0x0049b190 ====

uint FUN_0049b190(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = 0;
  if (param_1 == 0) {
    iVar2 = *(int *)(in_ECX + 0xc);
  }
  else if (param_1 == 1) {
    iVar2 = *(int *)(in_ECX + 8);
  }
  else {
    if (param_1 != 2) goto LAB_0049b1b5;
    iVar2 = *(int *)(in_ECX + 4);
  }
  uVar1 = iVar2 + param_2;
LAB_0049b1b5:
  if ((uVar1 < *(uint *)(in_ECX + 0xc)) || (*(uint *)(in_ECX + 4) <= uVar1)) {
    return 0;
  }
  *(uint *)(in_ECX + 8) = uVar1;
  return uVar1;
}


// ==== FUN_0049b1d0 @ 0x0049b1d0 ====

uint FUN_0049b1d0(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(int *)(in_ECX + 4) - *(int *)(in_ECX + 8);
  if (uVar1 < param_1) {
    param_1 = uVar1;
  }
  FUN_00797a80(param_2,*(int *)(in_ECX + 8),param_1);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_1;
  return param_1;
}


// ==== FUN_0049b200 @ 0x0049b200 ====

void FUN_0049b200(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae89c;
  return;
}


// ==== FUN_0049b210 @ 0x0049b210 ====

void FUN_0049b210(byte param_1)

{
  void *in_ECX;
  
  FUN_0049b140();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049b230 @ 0x0049b230 ====

void FUN_0049b230(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae8ac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049b270 @ 0x0049b270 ====

void FUN_0049b270(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *puVar1 = &PTR_FUN_009a10e0;
  *in_ECX = &PTR_FUN_009ae8c4;
  *puVar1 = &PTR_FUN_009ae8bc;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5a6c4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a6c4 = in_ECX;
  return;
}


// ==== FUN_0049b2a0 @ 0x0049b2a0 ====

void FUN_0049b2a0(char param_1,undefined4 param_2)

{
  void *pvVar1;
  int in_ECX;
  
  if (param_1 == '\x01') {
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      DAT_00b5abfc = (int *)FUN_0049b6d0();
      goto LAB_0049b2da;
    }
  }
  else {
    pvVar1 = operator_new(8);
    if (pvVar1 != (void *)0x0) {
      DAT_00b5abfc = (int *)FUN_0049b4f0();
      goto LAB_0049b2da;
    }
  }
  DAT_00b5abfc = (int *)0x0;
LAB_0049b2da:
  (**(code **)(*DAT_00b5abfc + 4))(param_2);
  if (in_ECX == 0) {
    (**(code **)(*DAT_00b5a688 + 0x1c))(0);
    return;
  }
  (**(code **)(*DAT_00b5a688 + 0x1c))(in_ECX + 4);
  return;
}


// ==== FUN_0049b320 @ 0x0049b320 ====

void FUN_0049b320(void)

{
  int in_ECX;
  
  if (DAT_00b5abfc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5abfc)(1);
    DAT_00b5abfc = (undefined4 *)0x0;
  }
  if (in_ECX == 0) {
    (**(code **)(*DAT_00b5a688 + 0x20))(0);
    return;
  }
  (**(code **)(*DAT_00b5a688 + 0x20))(in_ECX + 4);
  return;
}


// ==== FUN_0049b370 @ 0x0049b370 ====

void FUN_0049b370(void)

{
  if (DAT_00b5abfc == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0049b37c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5abfc + 0xc))();
  return;
}


// ==== FUN_0049b390 @ 0x0049b390 ====

uint FUN_0049b390(int param_1)

{
  uint in_EAX;
  
  if ((param_1 == 2) && (DAT_00b5abfc != (int *)0x0)) {
    in_EAX = (**(code **)(*DAT_00b5abfc + 8))();
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_0049b3b0 @ 0x0049b3b0 ====

void FUN_0049b3b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae8c4;
  in_ECX[1] = &PTR_FUN_009ae8bc;
  if (DAT_00b5abfc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5abfc)(1);
    DAT_00b5abfc = (undefined4 *)0x0;
  }
  (**(code **)(*DAT_00b5a688 + 0x20))(in_ECX + 1);
  DAT_00b5a6c4 = 0;
  *in_ECX = &PTR_FUN_009ae8ac;
  return;
}


// ==== FUN_0049b400 @ 0x0049b400 ====

void FUN_0049b400(void)

{
  undefined4 *in_ECX;
  byte unaff_retaddr;
  
  *in_ECX = &PTR_FUN_009ae8c4;
  in_ECX[1] = &PTR_FUN_009ae8bc;
  if (DAT_00b5abfc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5abfc)(1);
    DAT_00b5abfc = (undefined4 *)0x0;
  }
  (**(code **)(*DAT_00b5a688 + 0x20))(in_ECX + 1);
  DAT_00b5a6c4 = 0;
  *in_ECX = &PTR_FUN_009ae8ac;
  if ((unaff_retaddr & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049b460 @ 0x0049b460 ====

void FUN_0049b460(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae924;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049b480 @ 0x0049b480 ====

void FUN_0049b480(undefined4 param_1,undefined4 param_2,int param_3,code *param_4)

{
  if (-1 < param_3 + -1) {
    do {
      (*param_4)();
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return;
}


// ==== FUN_0049b4c0 @ 0x0049b4c0 ====

void FUN_0049b4c0(void)

{
  int *in_ECX;
  
  if ((char)in_ECX[1] == '\x01') {
    return;
  }
  *(undefined1 *)(in_ECX + 1) = 1;
                    /* WARNING: Could not recover jumptable at 0x0049b4cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xc))();
  return;
}


// ==== FUN_0049b4e0 @ 0x0049b4e0 ====

void FUN_0049b4e0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0049b4f0 @ 0x0049b4f0 ====

void FUN_0049b4f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae938;
  *(undefined1 *)(in_ECX + 1) = 0;
  return;
}


// ==== FUN_0049b520 @ 0x0049b520 ====

/* WARNING: Type propagation algorithm not settling */

void FUN_0049b520(void)

{
  short sVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  int iVar4;
  short local_600 [256];
  short local_400 [256];
  short local_200 [256];
  
  if ((*(char *)(in_ECX + 4) != '\0') && (iVar2 = FUN_0049b670(), iVar2 != 0)) {
    iVar2 = 0;
    do {
      FUN_00801f40();
      sVar1 = FUN_00802534();
      iVar4 = iVar2 + 1;
      sVar1 = sVar1 << 8;
      local_600[iVar2 + 0x200] = sVar1;
      local_600[iVar2 + 0x100] = sVar1;
      local_600[iVar2] = sVar1;
      iVar2 = iVar4;
    } while (iVar4 < 0x100);
    piVar3 = (int *)FUN_0049b670();
    (**(code **)(*piVar3 + 0x54))(piVar3,0,0,local_600);
  }
  return;
}


// ==== FUN_0049b640 @ 0x0049b640 ====

void FUN_0049b640(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae938;
  if (*(char *)(in_ECX + 1) != '\0') {
    *(undefined1 *)(in_ECX + 1) = 0;
  }
  *in_ECX = &PTR_FUN_009ae924;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049b670 @ 0x0049b670 ====

undefined4 FUN_0049b670(void)

{
  code *pcVar1;
  undefined4 extraout_EAX;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  if (*(int *)(in_ECX + 0x90) != 0) {
    return *(undefined4 *)(in_ECX + 0x90);
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_m_pDevice_009ae948,9);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
  _free(local_18);
  return extraout_EAX;
}


// ==== FUN_0049b6d0 @ 0x0049b6d0 ====

void FUN_0049b6d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae9ac;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  return;
}


// ==== FUN_0049b6f0 @ 0x0049b6f0 ====

void FUN_0049b6f0(undefined4 param_1)

{
  void *pvVar1;
  HDC pHVar2;
  int *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_30 [8];
  HWND local_10;
  
  if ((char)in_ECX[1] != '\x01') {
    *(undefined1 *)(in_ECX + 1) = 1;
    puVar4 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x94);
    puVar5 = local_30;
    for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    if (local_10 != (HWND)0x0) {
      if (in_ECX[3] == 0) {
        pvVar1 = operator_new(0x600);
        in_ECX[3] = (int)pvVar1;
      }
      if (in_ECX[2] == 0) {
        pHVar2 = GetDC(local_10);
        in_ECX[2] = (int)pHVar2;
      }
      GetDeviceGammaRamp((HDC)in_ECX[2],(LPVOID)in_ECX[3]);
      (**(code **)(*in_ECX + 0xc))(param_1);
    }
  }
  return;
}


// ==== FUN_0049b770 @ 0x0049b770 ====

void FUN_0049b770(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_30 [8];
  HWND local_10;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    puVar2 = (undefined4 *)(*(int *)(DAT_00b5ac04 + 0x28) + 0x94);
    puVar3 = local_30;
    for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    if (((local_10 != (HWND)0x0) && (*(HDC *)(in_ECX + 8) != (HDC)0x0)) &&
       (*(LPVOID *)(in_ECX + 0xc) != (LPVOID)0x0)) {
      SetDeviceGammaRamp(*(HDC *)(in_ECX + 8),*(LPVOID *)(in_ECX + 0xc));
      ReleaseDC(local_10,*(HDC *)(in_ECX + 8));
      *(undefined4 *)(in_ECX + 8) = 0;
      _free(*(void **)(in_ECX + 0xc));
      return;
    }
  }
  return;
}


// ==== FUN_0049b7f0 @ 0x0049b7f0 ====

/* WARNING: Type propagation algorithm not settling */

void FUN_0049b7f0(void)

{
  HDC hdc;
  short sVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  short local_600 [256];
  short local_400 [256];
  short local_200 [256];
  
  if ((*(char *)(in_ECX + 4) != '\0') && (hdc = *(HDC *)(in_ECX + 8), hdc != (HDC)0x0)) {
    iVar2 = 0;
    do {
      FUN_00801f40();
      sVar1 = FUN_00802534();
      iVar3 = iVar2 + 1;
      sVar1 = sVar1 << 8;
      local_600[iVar2 + 0x200] = sVar1;
      local_600[iVar2 + 0x100] = sVar1;
      local_600[iVar2] = sVar1;
      iVar2 = iVar3;
    } while (iVar3 < 0x100);
    SetDeviceGammaRamp(hdc,local_600);
  }
  return;
}


// ==== FUN_0049b900 @ 0x0049b900 ====

void FUN_0049b900(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae9ac;
  FUN_0049b770();
  *in_ECX = &PTR_FUN_009ae924;
  return;
}


// ==== FUN_0049b920 @ 0x0049b920 ====

void FUN_0049b920(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae9ac;
  FUN_0049b770();
  *in_ECX = &PTR_FUN_009ae924;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049b950 @ 0x0049b950 ====

void FUN_0049b950(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae9c0;
  pvVar1 = operator_new(8);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0049c340();
  }
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x14);
  if (pvVar1 == (void *)0x0) {
    in_ECX[2] = 0;
    return;
  }
  uVar2 = FUN_0049bab0();
  in_ECX[2] = uVar2;
  return;
}


// ==== FUN_0049b9a0 @ 0x0049b9a0 ====

void FUN_0049b9a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae9c0;
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


// ==== FUN_0049b9e0 @ 0x0049b9e0 ====

void FUN_0049b9e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae9c0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049ba30 @ 0x0049ba30 ====

void FUN_0049ba30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae9c8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049ba50 @ 0x0049ba50 ====

void FUN_0049ba50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae9e0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049ba70 @ 0x0049ba70 ====

void FUN_0049ba70(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ae9ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049ba90 @ 0x0049ba90 ====

void FUN_0049ba90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aea04;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049bab0 @ 0x0049bab0 ====

void FUN_0049bab0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aea1c;
  in_ECX[4] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5a6e8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5a6e8 = in_ECX;
  return;
}


// ==== FUN_0049bae0 @ 0x0049bae0 ====

void FUN_0049bae0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00803725(param_1,0,&Framework::ICell::RTTI_Type_Descriptor,
                       &Framework::Cell::Provider<16>::RTTI_Type_Descriptor,0);
  if (iVar1 == 0) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x10))(1,param_1);
    return;
  }
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  return;
}


// ==== FUN_0049bb20 @ 0x0049bb20 ====

void FUN_0049bb20(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + 0x10);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
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
  }
  return;
}


// ==== FUN_0049bb70 @ 0x0049bb70 ====

void FUN_0049bb70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aea1c;
  DAT_00b5a6e8 = 0;
  in_ECX[4] = 0;
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
  *in_ECX = &PTR_FUN_009ae9c8;
  return;
}


// ==== FUN_0049bbc0 @ 0x0049bbc0 ====

void FUN_0049bbc0(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int unaff_ESI;
  
  if (param_2 < 0x10) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))();
    uVar3 = 0;
    uVar1 = uVar3;
    if (param_2 != 0) {
      while (uVar3 = uVar1, uVar3 < 0x11) {
        *(undefined1 *)(uVar3 + 4 + iVar2) = *(undefined1 *)(uVar3 + unaff_ESI);
        uVar1 = uVar3 + 1;
        if (param_2 <= uVar3 + 1) {
          *(undefined1 *)(uVar3 + 5 + iVar2) = 0;
          return;
        }
      }
    }
  }
  else {
    iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0xc))(1,0);
    uVar3 = 0;
    if (param_2 != 0) {
      do {
        if (0x100 < uVar3) break;
        *(undefined1 *)(uVar3 + 4 + iVar2) = *(undefined1 *)(uVar3 + unaff_ESI);
        uVar3 = uVar3 + 1;
      } while (uVar3 < param_2);
    }
  }
  *(undefined1 *)(uVar3 + 4 + iVar2) = 0;
  return;
}


// ==== FUN_0049bc30 @ 0x0049bc30 ====

void FUN_0049bc30(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + 1;
  if (*(uint *)(in_ECX + 0x10) < 2) {
    pvVar1 = operator_new(0x8018);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0049c020();
    }
    *(undefined4 *)(in_ECX + 4) = uVar2;
    pvVar1 = operator_new(0x1118);
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_0049bda0();
    }
    *(undefined4 *)(in_ECX + 8) = uVar2;
    pvVar1 = operator_new(0x10);
    if (pvVar1 != (void *)0x0) {
      uVar2 = FUN_0049c850();
      *(undefined4 *)(in_ECX + 0xc) = uVar2;
      return;
    }
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  return;
}


// ==== FUN_0049bca0 @ 0x0049bca0 ====

void FUN_0049bca0(byte param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009aea4c;
  puVar1 = in_ECX + 0x441;
  iVar2 = 0x10;
  do {
    puVar1 = puVar1 + -0x44;
    iVar2 = iVar2 + -1;
    *puVar1 = &PTR_FUN_009ae9e0;
  } while (iVar2 != 0);
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049bcf0 @ 0x0049bcf0 ====

void FUN_0049bcf0(byte param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009aea54;
  puVar1 = in_ECX + 0x2001;
  iVar2 = 0x400;
  do {
    puVar1 = puVar1 + -8;
    iVar2 = iVar2 + -1;
    *puVar1 = &PTR_FUN_009ae9e0;
  } while (iVar2 != 0);
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049bd30 @ 0x0049bd30 ====

void FUN_0049bd30(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009aea4c;
  puVar1 = in_ECX + 1;
  iVar2 = 0x10;
  do {
    *puVar1 = &PTR_FUN_009aea34;
    *(undefined1 *)(puVar1 + 1) = 0;
    puVar1 = puVar1 + 0x44;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  in_ECX[0x441] = 0;
  return;
}


// ==== FUN_0049bd80 @ 0x0049bd80 ====

void FUN_0049bd80(byte param_1)

{
  void *in_ECX;
  
  FUN_0049bb70();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049bda0 @ 0x0049bda0 ====

void FUN_0049bda0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009aea5c;
  FUN_0049bd30();
  in_ECX[0x442] = in_ECX[0x442] + 0x10;
  in_ECX[0x445] = in_ECX + 2;
  in_ECX[0x443] = 0;
  in_ECX[0x444] = 0;
  iVar2 = 0xf;
  puVar1 = in_ECX;
  do {
    puVar1[0x43] = puVar1 + 0x46;
    puVar1[0x44] = 0;
    puVar1[0x45] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 0x44;
  } while (iVar2 != 0);
  in_ECX[0x43f] = 0;
  in_ECX[0x440] = 0;
  in_ECX[0x441] = 0;
  return;
}


// ==== FUN_0049be10 @ 0x0049be10 ====

undefined4 FUN_0049be10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x110c);
}


// ==== FUN_0049be20 @ 0x0049be20 ====

undefined4 FUN_0049be20(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_utility_009aea70,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10c);
    }
    *(undefined4 *)(param_2 + 0x104) = *(undefined4 *)(in_ECX + 0x1114);
    *(int *)(in_ECX + 0x110c) = *(int *)(in_ECX + 0x110c) + -1;
    *(int *)(in_ECX + 0x1114) = param_2;
  }
  return 0;
}


// ==== FUN_0049beb0 @ 0x0049beb0 ====

void FUN_0049beb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0049bed0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049bed0 @ 0x0049bed0 ====

void FUN_0049bed0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  puVar1 = (undefined4 *)in_ECX[0x444];
  *in_ECX = &PTR_FUN_009aea5c;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_009ae9e0;
    _free(puVar1);
    return;
  }
  in_ECX[1] = &PTR_FUN_009aea4c;
  puVar1 = in_ECX + 0x442;
  iVar2 = 0x10;
  do {
    puVar1 = puVar1 + -0x44;
    iVar2 = iVar2 + -1;
    *puVar1 = &PTR_FUN_009ae9e0;
  } while (iVar2 != 0);
  *in_ECX = &PTR_FUN_009ae9ec;
  return;
}


// ==== FUN_0049bf40 @ 0x0049bf40 ====

undefined4 * FUN_0049bf40(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[0x43] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_utility_009aea70,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[0x43] = param_2[0x43] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x1114);
  *(int *)(in_ECX + 0x110c) = *(int *)(in_ECX + 0x110c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x110);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009aea34;
      *(undefined1 *)(puVar2 + 1) = 0;
    }
    puVar2[0x42] = *(undefined4 *)(in_ECX + 0x1110);
    *(undefined4 **)(in_ECX + 0x1110) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1114) = puVar2[0x41];
  }
  puVar2[0x41] = 0;
  puVar2[0x43] = param_1;
  return puVar2;
}


// ==== FUN_0049c020 @ 0x0049c020 ====

void FUN_0049c020(void)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  *in_ECX = &PTR_FUN_009aeac4;
  in_ECX[1] = &PTR_FUN_009aea54;
  puVar1 = in_ECX + 2;
  iVar2 = 0x400;
  do {
    *puVar1 = &PTR_FUN_009aea40;
    *(undefined1 *)(puVar1 + 1) = 0;
    puVar1 = puVar1 + 8;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  in_ECX[0x2002] = 0;
  in_ECX[0x2002] = in_ECX[0x2002] + 0x400;
  in_ECX[0x2005] = in_ECX + 2;
  in_ECX[0x2003] = 0;
  in_ECX[0x2004] = 0;
  iVar2 = 0x3ff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0x1fff] = 0;
  in_ECX[0x2000] = 0;
  in_ECX[0x2001] = 0;
  return;
}


// ==== FUN_0049c0b0 @ 0x0049c0b0 ====

undefined4 FUN_0049c0b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x800c);
}


// ==== FUN_0049c0c0 @ 0x0049c0c0 ====

undefined4 FUN_0049c0c0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_utility_009aea70,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x8014);
    *(int *)(in_ECX + 0x800c) = *(int *)(in_ECX + 0x800c) + -1;
    *(int *)(in_ECX + 0x8014) = param_2;
  }
  return 0;
}


// ==== FUN_0049c140 @ 0x0049c140 ====

void FUN_0049c140(byte param_1)

{
  void *in_ECX;
  
  FUN_0049c160();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049c160 @ 0x0049c160 ====

void FUN_0049c160(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  
  puVar1 = (undefined4 *)in_ECX[0x2004];
  *in_ECX = &PTR_FUN_009aeac4;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR_FUN_009ae9e0;
    _free(puVar1);
    return;
  }
  in_ECX[1] = &PTR_FUN_009aea54;
  puVar1 = in_ECX + 0x2002;
  iVar2 = 0x400;
  do {
    puVar1 = puVar1 + -8;
    iVar2 = iVar2 + -1;
    *puVar1 = &PTR_FUN_009ae9e0;
  } while (iVar2 != 0);
  *in_ECX = &PTR_FUN_009aea04;
  return;
}


// ==== FUN_0049c1c0 @ 0x0049c1c0 ====

undefined4 * FUN_0049c1c0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_utility_009aea70,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x8014);
  *(int *)(in_ECX + 0x800c) = *(int *)(in_ECX + 0x800c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009aea40;
      *(undefined1 *)(puVar2 + 1) = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x8010);
    *(undefined4 **)(in_ECX + 0x8010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x8014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_0049c290 @ 0x0049c290 ====

void FUN_0049c290(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aeadc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049c2b0 @ 0x0049c2b0 ====

void FUN_0049c2b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aeaec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049c2d0 @ 0x0049c2d0 ====

void FUN_0049c2d0(undefined4 param_1)

{
  int in_ECX;
  
  FUN_0049cbf0();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0049c2f0 @ 0x0049c2f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049c2f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aeb0c;
  _DAT_00b5a6ec = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009aeadc;
  return;
}


// ==== FUN_0049c320 @ 0x0049c320 ====

undefined4 FUN_0049c320(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  FUN_0049ccc0();
  return uVar1;
}


// ==== FUN_0049c340 @ 0x0049c340 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049c340(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aeb0c;
  pvVar1 = operator_new(0x488);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0049c420();
  }
  in_ECX[1] = uVar2;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    _DAT_00b5a6ec = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5a6ec = in_ECX;
  return;
}


// ==== FUN_0049c390 @ 0x0049c390 ====

void FUN_0049c390(byte param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_009aeb04;
  iVar1 = 4;
  do {
    FUN_0049ccb0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049c3e0 @ 0x0049c3e0 ====

void FUN_0049c3e0(void)

{
  undefined4 *in_ECX;
  int iVar1;
  
  *in_ECX = &PTR_FUN_009aeb04;
  iVar1 = 4;
  do {
    FUN_0049cca0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  in_ECX[0x11d] = 0;
  return;
}


// ==== FUN_0049c420 @ 0x0049c420 ====

void FUN_0049c420(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aeb1c;
  FUN_0049c3e0();
  in_ECX[0x11e] = in_ECX[0x11e] + 4;
  in_ECX[0x11f] = 0;
  in_ECX[0x120] = 0;
  in_ECX[0x121] = in_ECX + 2;
  in_ECX[0x47] = 0;
  in_ECX[0x48] = 0;
  in_ECX[0x46] = in_ECX + 0x49;
  in_ECX[0x8d] = in_ECX + 0x90;
  in_ECX[0x8e] = 0;
  in_ECX[0x8f] = 0;
  in_ECX[0xd4] = in_ECX + 0xd7;
  in_ECX[0xd5] = 0;
  in_ECX[0xd6] = 0;
  in_ECX[0x11b] = 0;
  in_ECX[0x11c] = 0;
  in_ECX[0x11d] = 0;
  return;
}


// ==== FUN_0049c4c0 @ 0x0049c4c0 ====

undefined4 FUN_0049c4c0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x47c);
}


// ==== FUN_0049c4d0 @ 0x0049c4d0 ====

void FUN_0049c4d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0049c4f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049c4f0 @ 0x0049c4f0 ====

void FUN_0049c4f0(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  int iVar1;
  
  _Memory = (void *)in_ECX[0x120];
  *in_ECX = &PTR_FUN_009aeb1c;
  if (_Memory != (void *)0x0) {
    FUN_0049ccb0();
    _free(_Memory);
    return;
  }
  in_ECX[1] = &PTR_FUN_009aeb04;
  iVar1 = 4;
  do {
    FUN_0049ccb0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *in_ECX = &PTR_FUN_009aeaec;
  return;
}


// ==== FUN_0049c560 @ 0x0049c560 ====

void * FUN_0049c560(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x118) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_utility_009aeb30,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x118) = *(int *)((int)param_2 + 0x118) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x484);
  *(int *)(in_ECX + 0x47c) = *(int *)(in_ECX + 0x47c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x11c);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_0049cca0();
    }
    *(undefined4 *)((int)pvVar2 + 0x114) = *(undefined4 *)(in_ECX + 0x480);
    *(void **)(in_ECX + 0x480) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x484) = *(undefined4 *)((int)pvVar2 + 0x110);
  }
  *(undefined4 *)((int)pvVar2 + 0x110) = 0;
  *(int *)((int)pvVar2 + 0x118) = param_1;
  return pvVar2;
}


// ==== FUN_0049c640 @ 0x0049c640 ====

undefined4 FUN_0049c640(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x118) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_utility_009aeb30,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x118);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x118);
    }
    *(undefined4 *)(param_2 + 0x110) = *(undefined4 *)(in_ECX + 0x484);
    *(int *)(in_ECX + 0x47c) = *(int *)(in_ECX + 0x47c) + -1;
    *(int *)(in_ECX + 0x484) = param_2;
  }
  return 0;
}


// ==== FUN_0049c6d0 @ 0x0049c6d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0049c6d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aeb0c;
  _DAT_00b5a6ec = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009aeadc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049c720 @ 0x0049c720 ====

void FUN_0049c720(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aebb8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049c740 @ 0x0049c740 ====

int FUN_0049c740(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0049c750 @ 0x0049c750 ====

void FUN_0049c750(undefined4 param_1)

{
  int in_ECX;
  
  FUN_0049cdd0();
  (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0049c770 @ 0x0049c770 ====

void FUN_0049c770(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aebe8;
  DAT_00b5ac08 = 0;
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0049c7b0 @ 0x0049c7b0 ====

undefined4 FUN_0049c7b0(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  
  uVar1 = (**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  FUN_0049cf20(unaff_ESI);
  return uVar1;
}


// ==== FUN_0049c7e0 @ 0x0049c7e0 ====

void FUN_0049c7e0(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (*(int *)(in_ECX + 8) == 0) {
    local_100[0] = 0;
    uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_009aeba0,s___Cell_Table_Factory_cpp_009aeb84
                         ,0x37);
    FUN_00797b80(uVar1);
    FUN_00797a40();
  }
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_0049c850 @ 0x0049c850 ====

void FUN_0049c850(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aebe8;
  pvVar1 = operator_new(0x138);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0049c910();
  }
  in_ECX[1] = uVar2;
  in_ECX[3] = 0x300000;
  pvVar1 = operator_new(0x300000);
  in_ECX[2] = pvVar1;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ac08 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ac08 = in_ECX;
  return;
}


// ==== FUN_0049c8c0 @ 0x0049c8c0 ====

void FUN_0049c8c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aebc8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049c8e0 @ 0x0049c8e0 ====

void FUN_0049c8e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aebe0;
  FUN_0049cd90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049c910 @ 0x0049c910 ====

void FUN_0049c910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aebf8;
  in_ECX[1] = &PTR_FUN_009aebe0;
  FUN_0049d050();
  in_ECX[0x4a] = 0;
  in_ECX[0x4a] = in_ECX[0x4a] + 1;
  in_ECX[0x4d] = in_ECX + 2;
  in_ECX[0x4b] = 0;
  in_ECX[0x4c] = 0;
  in_ECX[0x47] = 0;
  in_ECX[0x48] = 0;
  in_ECX[0x49] = 0;
  return;
}


// ==== FUN_0049c970 @ 0x0049c970 ====

undefined4 FUN_0049c970(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 300);
}


// ==== FUN_0049c980 @ 0x0049c980 ====

void * FUN_0049c980(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x11c) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_utility_009aec10,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x11c) = *(int *)((int)param_2 + 0x11c) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x134);
  *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x120);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_0049d050();
    }
    *(undefined4 *)((int)pvVar2 + 0x118) = *(undefined4 *)(in_ECX + 0x130);
    *(void **)(in_ECX + 0x130) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x134) = *(undefined4 *)((int)pvVar2 + 0x114);
  }
  *(undefined4 *)((int)pvVar2 + 0x114) = 0;
  *(int *)((int)pvVar2 + 0x11c) = param_1;
  return pvVar2;
}


// ==== FUN_0049ca60 @ 0x0049ca60 ====

undefined4 FUN_0049ca60(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x11c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_utility_009aec10,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x11c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x11c);
    }
    *(undefined4 *)(param_2 + 0x114) = *(undefined4 *)(in_ECX + 0x134);
    *(int *)(in_ECX + 300) = *(int *)(in_ECX + 300) + -1;
    *(int *)(in_ECX + 0x134) = param_2;
  }
  return 0;
}


// ==== FUN_0049caf0 @ 0x0049caf0 ====

void FUN_0049caf0(byte param_1)

{
  void *in_ECX;
  
  FUN_0049cb10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049cb10 @ 0x0049cb10 ====

void FUN_0049cb10(void)

{
  void *_Memory;
  undefined4 *in_ECX;
  
  _Memory = (void *)in_ECX[0x4c];
  *in_ECX = &PTR_FUN_009aebf8;
  if (_Memory == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009aebe0;
    FUN_0049cd90();
    *in_ECX = &PTR_FUN_009aebc8;
    return;
  }
  FUN_0049cd90();
  _free(_Memory);
  return;
}


// ==== FUN_0049cb70 @ 0x0049cb70 ====

void FUN_0049cb70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aebe8;
  DAT_00b5ac08 = 0;
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0049cbd0 @ 0x0049cbd0 ====

void FUN_0049cbd0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aec8c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049cbf0 @ 0x0049cbf0 ====

void FUN_0049cbf0(void)

{
  return;
}


// ==== FUN_0049cc00 @ 0x0049cc00 ====

int FUN_0049cc00(int *param_1)

{
  ushort *puVar1;
  int in_ECX;
  
  puVar1 = (ushort *)(**(code **)(*param_1 + 8))();
  if (*(ushort *)(in_ECX + 4) <= *puVar1) {
    if (*(ushort *)(in_ECX + 4) < *puVar1) {
      return -1;
    }
    if (*(ushort *)(in_ECX + 6) <= puVar1[1]) {
      if (*(ushort *)(in_ECX + 6) < puVar1[1]) {
        return -1;
      }
      if (*(ushort *)(in_ECX + 8) <= puVar1[2]) {
        if (*(ushort *)(in_ECX + 8) < puVar1[2]) {
          return -1;
        }
        if (*(ushort *)(in_ECX + 10) <= puVar1[3]) {
          if (*(ushort *)(in_ECX + 10) < puVar1[3]) {
            return -1;
          }
          if (*(ushort *)(in_ECX + 0xc) <= puVar1[4]) {
            if (*(ushort *)(in_ECX + 0xc) < puVar1[4]) {
              return -1;
            }
            if (*(ushort *)(in_ECX + 0xe) <= puVar1[5]) {
              return -(uint)(*(ushort *)(in_ECX + 0xe) < puVar1[5]);
            }
          }
        }
      }
    }
  }
  return 1;
}


// ==== FUN_0049cc80 @ 0x0049cc80 ====

int FUN_0049cc80(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_0049cc90 @ 0x0049cc90 ====

int FUN_0049cc90(void)

{
  int in_ECX;
  
  return in_ECX + 0x10;
}


// ==== FUN_0049cca0 @ 0x0049cca0 ====

void FUN_0049cca0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aeca0;
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_0049ccb0 @ 0x0049ccb0 ====

void FUN_0049ccb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aec8c;
  return;
}


// ==== FUN_0049ccc0 @ 0x0049ccc0 ====

void FUN_0049ccc0(void)

{
  int in_ECX;
  _SYSTEMTIME local_10;
  
  GetLocalTime(&local_10);
  *(short *)(in_ECX + 0xe) = local_10.wSecond;
  *(WORD *)(in_ECX + 0xc) = local_10.wMinute;
  *(WORD *)(in_ECX + 10) = local_10.wHour;
  *(WORD *)(in_ECX + 8) = local_10.wDay;
  *(WORD *)(in_ECX + 6) = local_10.wMonth;
  *(WORD *)(in_ECX + 4) = local_10.wYear;
  FUN_0044a580(in_ECX + 0x10,s__d__02d__02dT_02d__02d__02d_009aec6c,local_10.wYear,local_10.wMonth,
               local_10.wDay,local_10.wHour,local_10.wMinute,(uint)local_10.wSecond);
  return;
}


// ==== FUN_0049cd40 @ 0x0049cd40 ====

void FUN_0049cd40(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aecb4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049cd60 @ 0x0049cd60 ====

int FUN_0049cd60(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_0049cd70 @ 0x0049cd70 ====

undefined4 FUN_0049cd70(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10c);
}


// ==== FUN_0049cd80 @ 0x0049cd80 ====

undefined4 FUN_0049cd80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x110);
}


// ==== FUN_0049cd90 @ 0x0049cd90 ====

void FUN_0049cd90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aed5c;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009aecb4;
  return;
}


// ==== FUN_0049cdd0 @ 0x0049cdd0 ====

void FUN_0049cdd0(void)

{
  int *piVar1;
  int in_ECX;
  
  for (piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))(); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x40))(piVar1)) {
    (**(code **)(*DAT_00b5a6e8 + 8))(*(undefined4 *)(*piVar1 + 4));
  }
  return;
}


// ==== FUN_0049ce10 @ 0x0049ce10 ====

undefined4 FUN_0049ce10(int param_1,int param_2)

{
  int *piVar1;
  int in_ECX;
  int local_8 [2];
  
  local_8[0] = param_1 * 0x10000 + param_2;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_0049ce50 @ 0x0049ce50 ====

undefined4 FUN_0049ce50(int param_1,int param_2)

{
  int *piVar1;
  undefined4 *puVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int local_8 [2];
  
  local_8[0] = param_1 * 0x10000 + param_2;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*DAT_00b5a6e8 + 8))(*(undefined4 *)(*piVar1 + 4));
  (**(code **)(**(int **)(in_ECX + 8) + 0x40))(piVar1);
  if ((param_1 + 1 == *(int *)(in_ECX + 0x10c)) || (param_2 + 1 == *(int *)(in_ECX + 0x110))) {
    *(undefined4 *)(in_ECX + 0x10c) = 0;
    *(undefined4 *)(in_ECX + 0x110) = 0;
    for (puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
        puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(puVar2)) {
      uVar3 = *(uint *)*puVar2;
      uVar4 = (uVar3 >> 0x10) + 1;
      if (*(uint *)(in_ECX + 0x10c) < uVar4) {
        *(uint *)(in_ECX + 0x10c) = uVar4;
      }
      uVar3 = (uVar3 & 0xffff) + 1;
      if (*(uint *)(in_ECX + 0x110) < uVar3) {
        *(uint *)(in_ECX + 0x110) = uVar3;
      }
    }
  }
  return 1;
}


// ==== FUN_0049cf20 @ 0x0049cf20 ====

void FUN_0049cf20(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int in_ECX;
  uint uVar4;
  
  pcVar1 = (char *)(in_ECX + 0xc);
  uVar4 = 0;
  *(undefined4 *)(in_ECX + 0x10c) = 0;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  pcVar3 = pcVar1;
  do {
    cVar2 = pcVar3[param_1 - (int)pcVar1];
    *pcVar3 = cVar2;
    if (cVar2 == '\0') {
      return;
    }
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x100);
  *pcVar1 = '\0';
  return;
}


// ==== FUN_0049cf70 @ 0x0049cf70 ====

undefined4 FUN_0049cf70(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined4 unaff_EBP;
  int local_4;
  
  piVar2 = param_1;
  piVar3 = param_1 + 4;
  local_4 = param_1[2];
  param_1 = (int *)param_1[3];
  if ((char)*piVar3 == '\x01') {
    FUN_0049d160(&local_4,&param_1);
  }
  if (param_1 == (int *)0x0) {
    return 1;
  }
  iVar4 = *piVar2;
  iVar1 = piVar2[1];
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *piVar3 = iVar4 * 0x10000 + iVar1;
  iVar4 = (**(code **)(*DAT_00b5a6e8 + 4))(unaff_EBP,local_4);
  piVar3[1] = iVar4;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(piVar3);
  if (iVar4 != 0) {
    (**(code **)(*DAT_00b5a6e8 + 8))(piVar3[1]);
    (**(code **)(**(int **)(in_ECX + 4) + 0x10))(1,piVar3);
    return 0;
  }
  if (*(uint *)(in_ECX + 0x10c) < *piVar2 + 1U) {
    *(uint *)(in_ECX + 0x10c) = *piVar2 + 1U;
  }
  if (*(uint *)(in_ECX + 0x110) < piVar2[1] + 1U) {
    *(uint *)(in_ECX + 0x110) = piVar2[1] + 1U;
  }
  return 1;
}


// ==== FUN_0049d050 @ 0x0049d050 ====

void FUN_0049d050(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aed5c;
  *(undefined1 *)(in_ECX + 3) = 0;
  puVar2 = operator_new(0x2c);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009aed84;
    puVar2[1] = &PTR_FUN_009aed7c;
    puVar2[7] = 0;
    puVar2[7] = puVar2[7] + 1;
    puVar2[8] = 0;
    puVar2[9] = 0;
    puVar2[10] = puVar2 + 2;
    puVar2[4] = 0;
    puVar2[5] = 0;
    puVar2[6] = 0;
  }
  in_ECX[1] = puVar2;
  puVar2 = operator_new(0x48);
  if (puVar2 == (undefined4 *)0x0) {
    in_ECX[2] = 0;
    return;
  }
  uVar1 = in_ECX[1];
  *puVar2 = &PTR_FUN_009aedbc;
  puVar2[4] = &PTR_FUN_009aeda4;
  puVar2[5] = &PTR_FUN_009aed9c;
  puVar2[6] = 0;
  puVar2[0xe] = 0;
  puVar2[0xe] = puVar2[0xe] + 1;
  puVar2[0xf] = 0;
  puVar2[0x10] = 0;
  puVar2[0x11] = puVar2 + 6;
  puVar2[0xb] = 0;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  puVar2[1] = 0;
  puVar2[2] = uVar1;
  in_ECX[2] = puVar2;
  return;
}


// ==== FUN_0049d100 @ 0x0049d100 ====

void FUN_0049d100(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aecd4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049d120 @ 0x0049d120 ====

void FUN_0049d120(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aecec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049d140 @ 0x0049d140 ====

void FUN_0049d140(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aed44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049d160 @ 0x0049d160 ====

void FUN_0049d160(int *param_1,uint *param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (*param_2 == 0) {
LAB_0049d193:
    *param_1 = 0;
    *param_2 = 0;
    return;
  }
LAB_0049d172:
  switch(*(undefined1 *)(*param_1 + uVar1)) {
  case 9:
  case 10:
  case 0xd:
  case 0x20:
    break;
  default:
    *param_1 = *param_1 + uVar1;
    *param_2 = *param_2 - uVar1;
    uVar1 = *param_2;
    do {
      switch(*(undefined1 *)(*param_1 + (uVar1 - 1))) {
      case 9:
      case 10:
      case 0xd:
      case 0x20:
        uVar1 = uVar1 - 1;
        break;
      default:
        *param_2 = uVar1;
        return;
      }
    } while( true );
  }
  uVar1 = uVar1 + 1;
  if (*param_2 <= uVar1) goto LAB_0049d193;
  goto LAB_0049d172;
}


// ==== FUN_0049d220 @ 0x0049d220 ====

void FUN_0049d220(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aed7c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049d240 @ 0x0049d240 ====

void FUN_0049d240(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aed5c;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009aecb4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049d290 @ 0x0049d290 ====

void FUN_0049d290(byte param_1)

{
  void *in_ECX;
  
  FUN_0049d2b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049d2b0 @ 0x0049d2b0 ====

void FUN_0049d2b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aed84;
  if ((void *)in_ECX[9] == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009aed7c;
    *in_ECX = &PTR_FUN_009aecd4;
    return;
  }
  _free((void *)in_ECX[9]);
  return;
}


// ==== FUN_0049d2f0 @ 0x0049d2f0 ====

void * FUN_0049d2f0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_utility_009aec10,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x28);
  *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0x24);
    *(void **)(in_ECX + 0x24) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x28) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_0049d390 @ 0x0049d390 ====

undefined4 FUN_0049d390(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_utility_009aec10,0xa9);
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


// ==== FUN_0049d410 @ 0x0049d410 ====

void FUN_0049d410(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aeda4;
  if ((void *)in_ECX[0xc] == (void *)0x0) {
    in_ECX[1] = &PTR_FUN_009aed9c;
    *in_ECX = &PTR_FUN_009aed44;
    return;
  }
  _free((void *)in_ECX[0xc]);
  return;
}


// ==== FUN_0049d450 @ 0x0049d450 ====

undefined4 FUN_0049d450(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_utility_009aec10,0xa9);
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


// ==== FUN_0049d4d0 @ 0x0049d4d0 ====

undefined4 * FUN_0049d4d0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_utility_009aec10,0x85);
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


// ==== FUN_0049d580 @ 0x0049d580 ====

void FUN_0049d580(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aed9c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049d5a0 @ 0x0049d5a0 ====

void FUN_0049d5a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aeda4;
  if ((void *)in_ECX[0xc] != (void *)0x0) {
    _free((void *)in_ECX[0xc]);
    return;
  }
  in_ECX[1] = &PTR_FUN_009aed9c;
  *in_ECX = &PTR_FUN_009aed44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049d5f0 @ 0x0049d5f0 ====

void FUN_0049d5f0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0049d610(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0049d610 @ 0x0049d610 ====

void FUN_0049d610(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0049d610(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0049d610(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0049d650 @ 0x0049d650 ====

void FUN_0049d650(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0049d670(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0049d670 @ 0x0049d670 ====

void FUN_0049d670(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_0049d670(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_0049d670(param_1[3]);
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


// ==== FUN_0049d6e0 @ 0x0049d6e0 ====

void FUN_0049d6e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aedbc;
  FUN_0049d650();
  FUN_0049d410();
  *in_ECX = &PTR_FUN_009aecec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049d720 @ 0x0049d720 ====

void FUN_0049d720(void)

{
  FUN_0049fca0();
  FUN_0049fbb0();
  FUN_0049fb00();
  return;
}


// ==== FUN_0049d730 @ 0x0049d730 ====

void FUN_0049d730(void)

{
  FUN_0049fb90();
  FUN_0049fc60();
  FUN_0049fcf0();
  return;
}


// ==== FUN_0049d760 @ 0x0049d760 ====

void FUN_0049d760(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_0049d780 @ 0x0049d780 ====

void FUN_0049d780(void)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  iVar1 = *(int *)(*in_ECX + 0x40);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = (*(int *)(*in_ECX + 0x44) - iVar1) / 0x1c;
  }
  if ((uint)in_ECX[1] < uVar2) {
    in_ECX[1] = in_ECX[1] + 1;
  }
  return;
}


// ==== FUN_0049d7c0 @ 0x0049d7c0 ====

uint FUN_0049d7c0(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *(int *)(*in_ECX + 0x40);
  if (iVar1 == 0) {
    return (uint)(in_ECX[1] == 0);
  }
  iVar1 = (*(int *)(*in_ECX + 0x44) - iVar1) / 0x1c;
  return CONCAT31((int3)((uint)iVar1 >> 8),in_ECX[1] == iVar1);
}


// ==== FUN_0049d800 @ 0x0049d800 ====

int FUN_0049d800(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  if (*(int *)(iVar1 + 0x40) == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = (*(int *)(iVar1 + 0x44) - *(int *)(iVar1 + 0x40)) / 0x1c;
  }
  uVar2 = in_ECX[1];
  if (uVar2 < uVar3) {
    iVar1 = *(int *)(iVar1 + 0x40);
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(iVar1 + uVar2 * 0x1c,0,0xffffffff);
    return param_1;
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(&DAT_009aee8a,0);
  return param_1;
}


// ==== FUN_0049d890 @ 0x0049d890 ====

void FUN_0049d890(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e783;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *in_ECX = &PTR_FUN_009aeecc;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  local_4 = 1;
  FUN_00401660(param_1,0,0xffffffff);
  puVar1 = operator_new(8);
  if (puVar1 == (undefined4 *)0x0) {
    in_ECX[0x13] = 0;
    ExceptionList = local_c;
    return;
  }
  *puVar1 = in_ECX;
  puVar1[1] = 0;
  in_ECX[0x13] = puVar1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049d950 @ 0x0049d950 ====

void FUN_0049d950(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009aeecc;
  _free((void *)in_ECX[0x13]);
  return;
}


// ==== FUN_0049d9b0 @ 0x0049d9b0 ====

undefined4 FUN_0049d9b0(int *param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 != 9) {
    return 0;
  }
  uVar4 = 0;
  iVar1 = FUN_00411430();
  if (iVar1 != 0) {
    do {
      iVar1 = FUN_00411510(uVar4);
      if (*(int *)(iVar1 + 0x14) != 0) {
        FUN_00406720(iVar1);
      }
      uVar4 = uVar4 + 1;
      uVar2 = FUN_00411430();
    } while (uVar4 < uVar2);
  }
  uVar3 = (**(code **)(*param_1 + 0x10))();
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 2;
  (**(code **)*param_1)(1);
  return 1;
}


// ==== FUN_0049da30 @ 0x0049da30 ====

void FUN_0049da30(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e75b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009aee94;
  local_4 = 0;
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
  }
  in_ECX[8] = 0;
  if ((uint)in_ECX[7] < 0x10) {
    in_ECX[6] = 0;
    in_ECX[7] = 0xf;
    *(undefined1 *)(in_ECX + 2) = 0;
    ExceptionList = pvStack_c;
    return;
  }
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_0049daa0 @ 0x0049daa0 ====

void FUN_0049daa0(byte param_1)

{
  void *in_ECX;
  
  FUN_0049da30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049dac0 @ 0x0049dac0 ====

void FUN_0049dac0(byte param_1)

{
  void *in_ECX;
  
  FUN_0049d950();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049dae0 @ 0x0049dae0 ====

void FUN_0049dae0(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x55) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x55) == '\0');
  }
  return;
}


// ==== FUN_0049db00 @ 0x0049db00 ====

void FUN_0049db00(int *param_1)

{
  char cVar1;
  
  param_1 = (int *)*param_1;
  cVar1 = *(char *)((int)param_1 + 0x55);
  while (cVar1 == '\0') {
    param_1 = (int *)*param_1;
    cVar1 = *(char *)((int)param_1 + 0x55);
  }
  return;
}


// ==== FUN_0049db20 @ 0x0049db20 ====

void FUN_0049db20(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  if (*(char *)(iVar2 + 0x55) == '\0') {
    piVar3 = *(int **)(iVar2 + 8);
    if (*(char *)((int)piVar3 + 0x55) == '\0') {
      cVar1 = *(char *)(*piVar3 + 0x55);
      piVar4 = (int *)*piVar3;
      while (cVar1 == '\0') {
        cVar1 = *(char *)(*piVar4 + 0x55);
        piVar3 = piVar4;
        piVar4 = (int *)*piVar4;
      }
      *in_ECX = (int)piVar3;
      return;
    }
    iVar2 = *(int *)(iVar2 + 4);
    cVar1 = *(char *)(iVar2 + 0x55);
    while ((cVar1 == '\0' && (*in_ECX == *(int *)(iVar2 + 8)))) {
      *in_ECX = iVar2;
      iVar2 = *(int *)(iVar2 + 4);
      cVar1 = *(char *)(iVar2 + 0x55);
    }
    *in_ECX = iVar2;
  }
  return;
}


// ==== FUN_0049db90 @ 0x0049db90 ====

/* WARNING: Removing unreachable block (ram,0x0049dbcd) */

int FUN_0049db90(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  
  iVar3 = *(int *)(in_ECX + 0x20);
  if (iVar3 != *(int *)(in_ECX + 0x24)) {
    uVar1 = *(uint *)(param_1 + 0x14);
    do {
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        pbVar7 = (byte *)(param_1 + 4);
      }
      else {
        pbVar7 = *(byte **)(param_1 + 4);
      }
      uVar2 = *(uint *)(iVar3 + 0x14);
      if (uVar2 == 0) {
LAB_0049dbfc:
        if ((uVar1 <= uVar2) && (uVar2 == uVar1)) {
          return iVar3;
        }
      }
      else {
        uVar4 = uVar2;
        if (uVar1 <= uVar2) {
          uVar4 = uVar1;
        }
        if (*(uint *)(iVar3 + 0x18) < 0x10) {
          pbVar6 = (byte *)(iVar3 + 4);
        }
        else {
          pbVar6 = *(byte **)(iVar3 + 4);
        }
        bVar8 = false;
        iVar5 = 0;
        bVar9 = true;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          bVar8 = *pbVar6 < *pbVar7;
          bVar9 = *pbVar6 == *pbVar7;
          pbVar6 = pbVar6 + 1;
          pbVar7 = pbVar7 + 1;
        } while (bVar9);
        if (!bVar9) {
          iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        }
        if (iVar5 == 0) goto LAB_0049dbfc;
      }
      iVar3 = iVar3 + 0x48;
    } while (iVar3 != *(int *)(in_ECX + 0x24));
  }
  return 0;
}


// ==== FUN_0049dc20 @ 0x0049dc20 ====

/* WARNING: Removing unreachable block (ram,0x0049dc5d) */

int FUN_0049dc20(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  
  iVar3 = *(int *)(in_ECX + 0x40);
  if (iVar3 != *(int *)(in_ECX + 0x44)) {
    uVar1 = *(uint *)(param_1 + 0x14);
    do {
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        pbVar7 = (byte *)(param_1 + 4);
      }
      else {
        pbVar7 = *(byte **)(param_1 + 4);
      }
      uVar2 = *(uint *)(iVar3 + 0x14);
      if (uVar2 == 0) {
LAB_0049dc8c:
        if ((uVar1 <= uVar2) && (uVar2 == uVar1)) {
          return iVar3;
        }
      }
      else {
        uVar4 = uVar2;
        if (uVar1 <= uVar2) {
          uVar4 = uVar1;
        }
        if (*(uint *)(iVar3 + 0x18) < 0x10) {
          pbVar6 = (byte *)(iVar3 + 4);
        }
        else {
          pbVar6 = *(byte **)(iVar3 + 4);
        }
        bVar8 = false;
        iVar5 = 0;
        bVar9 = true;
        do {
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          bVar8 = *pbVar6 < *pbVar7;
          bVar9 = *pbVar6 == *pbVar7;
          pbVar6 = pbVar6 + 1;
          pbVar7 = pbVar7 + 1;
        } while (bVar9);
        if (!bVar9) {
          iVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
        }
        if (iVar5 == 0) goto LAB_0049dc8c;
      }
      iVar3 = iVar3 + 0x48;
    } while (iVar3 != *(int *)(in_ECX + 0x44));
  }
  return 0;
}


// ==== FUN_0049dcb0 @ 0x0049dcb0 ====

int FUN_0049dcb0(int param_1)

{
  int in_ECX;
  
  FUN_0049e660(&param_1,param_1);
  if (param_1 == *(int *)(in_ECX + 0x50)) {
    return 0;
  }
  return param_1 + 0x28;
}


// ==== FUN_0049dd20 @ 0x0049dd20 ====

undefined4 FUN_0049dd20(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined1 local_1c [4];
  int local_18;
  int local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e798;
  local_c = ExceptionList;
  if (*(int *)(param_1 + 0x14) == 0) {
    return 0;
  }
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_4 = 0;
  ExceptionList = &local_c;
  FUN_00405670(param_1,local_1c);
  iVar2 = local_18;
  if (local_18 != 0) {
    iVar1 = (local_14 - local_18) / 0x1c;
    if (iVar1 != 0) {
      FUN_00401660(local_18,0,0xffffffff);
      FUN_0040c520(*(undefined4 *)(param_2 + 0x20),iVar2 + 0x1c,local_14,iVar1);
      FUN_00401660(param_1,0,0xffffffff);
      FUN_00406250();
      ExceptionList = local_c;
      return 1;
    }
  }
  FUN_00406250();
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_0049de20 @ 0x0049de20 ====

/* WARNING: Removing unreachable block (ram,0x0049ded0) */
/* WARNING: Type propagation algorithm not settling */

void FUN_0049de20(void)

{
  uint uVar1;
  char cVar2;
  int iVar3;
  byte *pbVar4;
  uint uVar5;
  byte *******pppppppbVar6;
  uint uVar7;
  bool bVar8;
  bool bVar9;
  undefined1 auStack_c0 [4];
  undefined1 local_bc;
  undefined4 local_ac;
  undefined1 *local_a8;
  undefined1 local_90 [4];
  byte *******local_8c [4];
  uint local_7c;
  uint local_78;
  undefined1 *local_74;
  undefined1 local_70 [4];
  void *local_6c;
  undefined4 local_5c;
  uint local_58;
  undefined1 local_50;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 local_24;
  undefined4 local_14;
  undefined4 local_10;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e7c5;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  cVar2 = FUN_0049fe50();
  do {
    if (cVar2 != '\0') {
      ExceptionList = local_c;
      return;
    }
    local_a8 = (undefined1 *)0x49de61;
    FUN_0049fea0();
    local_4 = 0;
    local_74 = auStack_c0;
    local_a8 = (undefined1 *)0xf;
    local_ac = 0;
    local_bc = 0;
    FUN_00401740(s____s__009aef3c,5);
    iVar3 = FUN_00404230(local_70);
    uVar1 = *(uint *)(iVar3 + 0x14);
    if (*(uint *)(iVar3 + 0x18) < 0x10) {
      pbVar4 = (byte *)(iVar3 + 4);
    }
    else {
      pbVar4 = *(byte **)(iVar3 + 4);
    }
    if (local_7c == 0) {
LAB_0049df03:
      if (local_7c < uVar1) {
        uVar5 = 0xffffffff;
      }
      else {
        uVar5 = (uint)(local_7c != uVar1);
      }
    }
    else {
      uVar7 = local_7c;
      if (uVar1 <= local_7c) {
        uVar7 = uVar1;
      }
      pppppppbVar6 = local_8c[0];
      if (local_78 < 0x10) {
        pppppppbVar6 = (byte *******)local_8c;
      }
      bVar8 = false;
      uVar5 = 0;
      bVar9 = true;
      do {
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        bVar8 = *(byte *)pppppppbVar6 < *pbVar4;
        bVar9 = *(byte *)pppppppbVar6 == *pbVar4;
        pppppppbVar6 = (byte *******)((int)pppppppbVar6 + 1);
        pbVar4 = pbVar4 + 1;
      } while (bVar9);
      if (!bVar9) {
        uVar5 = (1 - (uint)bVar8) - (uint)(bVar8 != 0);
      }
      if (uVar5 == 0) goto LAB_0049df03;
    }
    uVar1 = local_4 >> 8;
    local_4 = local_4 & 0xffffff00;
    if (0xf < local_58) {
      local_a8 = (undefined1 *)0x49df31;
      _free(local_6c);
      return;
    }
    local_58 = 0xf;
    local_5c = 0;
    local_6c = (void *)((uint)local_6c & 0xffffff00);
    if (uVar5 == 0) {
joined_r0x0049e034:
      if (local_78 < 0x10) {
        ExceptionList = local_c;
        return;
      }
      local_a8 = (undefined1 *)0x49e05a;
      _free(local_8c[0]);
      return;
    }
    pppppppbVar6 = local_8c[0];
    if (local_78 < 0x10) {
      pppppppbVar6 = (byte *******)local_8c;
    }
    if (*(byte *)pppppppbVar6 == 0x5b) {
      pppppppbVar6 = local_8c[0];
      if (local_78 < 0x10) {
        pppppppbVar6 = (byte *******)local_8c;
      }
      if (*(byte *)((int)pppppppbVar6 + (local_7c - 1)) == 0x5d) {
        FUN_0049fe80();
        goto joined_r0x0049e034;
      }
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50 = 0;
    local_34 = 0;
    local_30 = 0;
    local_2c = 0;
    local_10 = 0xf;
    local_14 = 0;
    local_24 = 0;
    local_a8 = local_90;
    local_4 = CONCAT31((int3)uVar1,3);
    local_ac = 0x49dfc7;
    cVar2 = FUN_0049dd20();
    if (cVar2 != '\0') {
      local_a8 = (undefined1 *)0x49dfe2;
      FUN_0049ef10();
    }
    FUN_0049e800();
    local_4 = 0xffffffff;
    if (0xf < local_78) {
      local_a8 = (undefined1 *)0x49e007;
      _free(local_8c[0]);
      return;
    }
    local_78 = 0xf;
    local_7c = 0;
    local_8c[0] = (byte *******)((uint)local_8c[0] & 0xffffff00);
    cVar2 = FUN_0049fe50();
  } while( true );
}


// ==== FUN_0049e080 @ 0x0049e080 ====

undefined4 FUN_0049e080(int *param_1)

{
  char cVar1;
  int iVar2;
  char ****ppppcVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  int in_ECX;
  undefined1 auStack_114 [12];
  undefined1 auStack_108 [4];
  char ****appppcStack_104 [4];
  int iStack_f4;
  uint uStack_f0;
  undefined1 auStack_ec [4];
  void *pvStack_e8;
  undefined4 uStack_d8;
  uint uStack_d4;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined1 auStack_c0 [4];
  void *pvStack_bc;
  undefined4 uStack_ac;
  uint uStack_a8;
  void *pvStack_a0;
  undefined4 uStack_90;
  uint uStack_8c;
  void *pvStack_84;
  undefined4 uStack_74;
  uint uStack_70;
  undefined1 auStack_5c [4];
  undefined1 uStack_58;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 uStack_2c;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 auStack_14 [8];
  void *pvStack_c;
  undefined1 *puStack_8;
  uint uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097e821;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 9) {
    FUN_0049fe10(param_1);
    uStack_4 = 0;
    cVar1 = FUN_0049fe50();
    while (cVar1 == '\0') {
      FUN_0049fea0(auStack_108);
      ppppcVar3 = appppcStack_104[0];
      if (uStack_f0 < 0x10) {
        ppppcVar3 = (char ****)appppcStack_104;
      }
      if (*(char *)ppppcVar3 == '[') {
        ppppcVar3 = appppcStack_104[0];
        if (uStack_f0 < 0x10) {
          ppppcVar3 = (char ****)appppcStack_104;
        }
        if (*(char *)((int)ppppcVar3 + iStack_f4 + -1) != ']') goto LAB_0049e27a;
        uStack_d4 = 0xf;
        uStack_d8 = 0;
        pvStack_e8 = (void *)((uint)pvStack_e8 & 0xffffff00);
        uStack_cc = 0;
        uStack_c8 = 0;
        uStack_c4 = 0;
        uStack_4._0_1_ = 3;
        uVar4 = FUN_00405b90(auStack_c0,1,iStack_f4 + -2);
        uStack_4._0_1_ = 4;
        FUN_00401660(uVar4,0,0xffffffff);
        uStack_4._0_1_ = 3;
        if (0xf < uStack_a8) {
          _free(pvStack_bc);
          return extraout_EAX;
        }
        uStack_a8 = 0xf;
        uStack_ac = 0;
        pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
        FUN_0049de20(auStack_114,auStack_ec);
        uVar4 = FUN_0049f1b0(auStack_ec,auStack_ec);
        uStack_4 = CONCAT31(uStack_4._1_3_,5);
        FUN_0049f4a0(auStack_14,uVar4);
        FUN_0049eeb0();
        if (0xf < uStack_70) {
          _free(pvStack_84);
          return extraout_EAX_00;
        }
        uStack_70 = 0xf;
        uStack_74 = 0;
        pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
        if (0xf < uStack_8c) {
          _free(pvStack_a0);
          return extraout_EAX_01;
        }
        uStack_8c = 0xf;
        uStack_90 = 0;
        pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
        FUN_0049eeb0();
        if (0xf < uStack_d4) {
          _free(pvStack_e8);
          return extraout_EAX_02;
        }
        uStack_d4 = 0xf;
        uStack_d8 = 0;
        pvStack_e8 = (void *)((uint)pvStack_e8 & 0xffffff00);
      }
      else {
LAB_0049e27a:
        uStack_44 = 0xf;
        uStack_48 = 0;
        uStack_58 = 0;
        uStack_3c = 0;
        uStack_38 = 0;
        uStack_34 = 0;
        uStack_18 = 0xf;
        uStack_1c = 0;
        uStack_2c = 0;
        uStack_4 = CONCAT31(uStack_4._1_3_,7);
        cVar1 = FUN_0049dd20(auStack_108,auStack_5c);
        if (cVar1 != '\0') {
          FUN_0049ef10(auStack_5c);
        }
        FUN_0049e800();
      }
      uStack_4 = uStack_4 & 0xffffff00;
      if (0xf < uStack_f0) {
        _free(appppcStack_104[0]);
        return extraout_EAX_03;
      }
      uStack_f0 = 0xf;
      iStack_f4 = 0;
      appppcStack_104[0] = (char ****)((uint)appppcStack_104[0] & 0xffffff00);
      cVar1 = FUN_0049fe50();
    }
    uVar4 = (**(code **)(*param_1 + 0x10))();
    *(undefined4 *)(in_ECX + 0x28) = uVar4;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 2;
    (**(code **)*param_1)(1);
    uStack_4 = 0xffffffff;
    FUN_0049fe30();
    uVar4 = 1;
  }
  else {
    uVar4 = 0;
  }
  ExceptionList = pvStack_c;
  return uVar4;
}


// ==== FUN_0049e390 @ 0x0049e390 ====

void FUN_0049e390(undefined4 param_1)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e849;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xffffffff;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *in_ECX = &PTR_FUN_009aef4c;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  local_4 = 1;
  iVar1 = FUN_0049e560();
  in_ECX[0x14] = iVar1;
  *(undefined1 *)(iVar1 + 0x55) = 1;
  *(undefined4 *)(in_ECX[0x14] + 4) = in_ECX[0x14];
  *(undefined4 *)in_ECX[0x14] = in_ECX[0x14];
  *(undefined4 *)(in_ECX[0x14] + 8) = in_ECX[0x14];
  in_ECX[0x15] = 0;
  local_4 = CONCAT31(local_4._1_3_,2);
  FUN_00401660(param_1,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049e450 @ 0x0049e450 ====

void FUN_0049e450(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  
  piVar1 = *(int **)(param_1 + 8);
  *(int *)(param_1 + 8) = *piVar1;
  if (*(char *)(*piVar1 + 0x55) == '\0') {
    *(int *)(*piVar1 + 4) = param_1;
  }
  piVar1[1] = *(int *)(param_1 + 4);
  if (param_1 == *(int *)(*(int *)(in_ECX + 4) + 4)) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2 = *(int **)(param_1 + 4);
  if (param_1 == *piVar2) {
    *piVar2 = (int)piVar1;
    *piVar1 = param_1;
    *(int **)(param_1 + 4) = piVar1;
    return;
  }
  piVar2[2] = (int)piVar1;
  *piVar1 = param_1;
  *(int **)(param_1 + 4) = piVar1;
  return;
}


// ==== FUN_0049e4a0 @ 0x0049e4a0 ====

void FUN_0049e4a0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x55) == '\0') {
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


// ==== FUN_0049e500 @ 0x0049e500 ====

void FUN_0049e500(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  piVar4 = (int *)*in_ECX;
  if (*(char *)((int)piVar4 + 0x55) != '\0') {
    *in_ECX = piVar4[2];
    return;
  }
  iVar2 = *piVar4;
  if (*(char *)(iVar2 + 0x55) == '\0') {
    cVar1 = *(char *)(*(int *)(iVar2 + 8) + 0x55);
    iVar3 = *(int *)(iVar2 + 8);
    while (cVar1 == '\0') {
      cVar1 = *(char *)(*(int *)(iVar3 + 8) + 0x55);
      iVar2 = iVar3;
      iVar3 = *(int *)(iVar3 + 8);
    }
    *in_ECX = iVar2;
    return;
  }
  piVar4 = (int *)piVar4[1];
  if (*(char *)((int)piVar4 + 0x55) == '\0') {
    do {
      if (*in_ECX != *piVar4) break;
      *in_ECX = (int)piVar4;
      piVar4 = (int *)piVar4[1];
    } while (*(char *)((int)piVar4 + 0x55) == '\0');
    if (*(char *)((int)piVar4 + 0x55) == '\0') {
      *in_ECX = (int)piVar4;
    }
  }
  return;
}


// ==== FUN_0049e560 @ 0x0049e560 ====

void FUN_0049e560(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(0x58);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0x15) = 1;
  *(undefined1 *)((int)puVar1 + 0x55) = 0;
  return;
}


// ==== FUN_0049e5a0 @ 0x0049e5a0 ====

/* WARNING: Removing unreachable block (ram,0x0049e5f8) */

undefined4 * FUN_0049e5a0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  undefined4 *local_8;
  
  local_8 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)local_8[1] + 0x55) == '\0') {
    uVar1 = *(uint *)(param_1 + 0x14);
    puVar5 = (undefined4 *)local_8[1];
    do {
      if (*(uint *)(param_1 + 0x18) < 0x10) {
        pbVar8 = (byte *)(param_1 + 4);
      }
      else {
        pbVar8 = *(byte **)(param_1 + 4);
      }
      uVar2 = puVar5[8];
      if (uVar2 == 0) {
LAB_0049e623:
        if (uVar1 <= uVar2) {
          bVar9 = false;
          goto LAB_0049e630;
        }
LAB_0049e632:
        puVar6 = (undefined4 *)puVar5[2];
      }
      else {
        uVar3 = uVar2;
        if (uVar1 <= uVar2) {
          uVar3 = uVar1;
        }
        if ((uint)puVar5[9] < 0x10) {
          pbVar7 = (byte *)(puVar5 + 4);
        }
        else {
          pbVar7 = (byte *)puVar5[4];
        }
        bVar9 = false;
        iVar4 = 0;
        bVar10 = true;
        do {
          if (uVar3 == 0) break;
          uVar3 = uVar3 - 1;
          bVar9 = *pbVar7 < *pbVar8;
          bVar10 = *pbVar7 == *pbVar8;
          pbVar7 = pbVar7 + 1;
          pbVar8 = pbVar8 + 1;
        } while (bVar10);
        if (!bVar10) {
          iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
        }
        bVar9 = iVar4 < 0;
        if (iVar4 == 0) goto LAB_0049e623;
LAB_0049e630:
        if (bVar9) goto LAB_0049e632;
        puVar6 = (undefined4 *)*puVar5;
        local_8 = puVar5;
      }
      puVar5 = puVar6;
    } while (*(char *)((int)puVar6 + 0x55) == '\0');
  }
  return local_8;
}


// ==== FUN_0049e660 @ 0x0049e660 ====

void FUN_0049e660(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = FUN_0049e5a0(param_2);
  if (iVar1 != *(int *)(in_ECX + 4)) {
    if (*(uint *)(iVar1 + 0x24) < 0x10) {
      iVar2 = iVar1 + 0x10;
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x10);
    }
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),iVar2,*(undefined4 *)(iVar1 + 0x20));
    if (-1 < iVar2) {
      *param_1 = iVar1;
      return;
    }
  }
  *param_1 = *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_0049e6d0 @ 0x0049e6d0 ====

void FUN_0049e6d0(void)

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
  puStack_8 = &LAB_0097e938;
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


// ==== FUN_0049e740 @ 0x0049e740 ====

void FUN_0049e740(void)

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
  puStack_8 = &LAB_0097e938;
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


// ==== FUN_0049e7b0 @ 0x0049e7b0 ====

undefined4 FUN_0049e7b0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x38e38e3 < param_1) {
    param_1 = FUN_0049e740();
  }
  pvVar1 = operator_new(param_1 * 0x48);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x48 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_0049e800 @ 0x0049e800 ====

void FUN_0049e800(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x44)) {
    _free(*(void **)(in_ECX + 0x30));
    return;
  }
  *(undefined4 *)(in_ECX + 0x44) = 0xf;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  if (*(int *)(in_ECX + 0x20) != 0) {
    FUN_00405de0(*(int *)(in_ECX + 0x20),*(undefined4 *)(in_ECX + 0x24),in_ECX + 0x1c);
    _free(*(void **)(in_ECX + 0x20));
    return;
  }
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0049e880 @ 0x0049e880 ====

void FUN_0049e880(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e873;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_00406600(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x44) = 0xf;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined1 *)(in_ECX + 0x30) = 0;
  FUN_00401660(param_1 + 0x2c,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049e910 @ 0x0049e910 ====

int FUN_0049e910(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x48;
    param_3 = param_3 + -0x48;
    FUN_00401660(iVar1,0,0xffffffff);
    FUN_0043b3d0(param_2 + -0x2c);
    FUN_00401660(param_2 + -0x1c,0,0xffffffff);
    param_2 = iVar1;
  } while (iVar1 != param_1);
  return param_3;
}


// ==== FUN_0049e970 @ 0x0049e970 ====

void FUN_0049e970(int param_1,int param_2,int param_3)

{
  if (param_1 != param_2) {
    do {
      FUN_00401660(param_3,0,0xffffffff);
      FUN_0043b3d0(param_3 + 0x1c);
      FUN_00401660(param_3 + 0x2c,0,0xffffffff);
      param_1 = param_1 + 0x48;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_0049e9c0 @ 0x0049e9c0 ====

int FUN_0049e9c0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097e891;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x48) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_0049e880(param_1);
    }
    param_3 = param_3 + 0x48;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@0049ea16 @ 0x0049ea16 ====

void Catch_0049ea16(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x48) {
    FUN_0049e800();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0049ea50 @ 0x0049ea50 ====

void FUN_0049ea50(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0097e8b1;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_0049e880(param_3);
    }
    param_1 = param_1 + 0x48;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0049eaa8 @ 0x0049eaa8 ====

void Catch_0049eaa8(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x48) {
    FUN_0049e800();
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0049eae0 @ 0x0049eae0 ====

int FUN_0049eae0(int param_1,int param_2,undefined4 param_3)

{
  FUN_0049ea50(param_1,param_2,param_3);
  return param_1 + param_2 * 0x48;
}


// ==== FUN_0049eb10 @ 0x0049eb10 ====

void FUN_0049eb10(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x48) {
    FUN_0049e800();
  }
  return;
}


// ==== FUN_0049eb40 @ 0x0049eb40 ====

void FUN_0049eb40(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  undefined1 local_64 [2];
  undefined1 auStack_62 [70];
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097e8c8;
  local_10 = ExceptionList;
  local_14 = local_64 + -0xc;
  ExceptionList = &local_10;
  FUN_0049e880(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x48;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x48;
    }
    if (0x38e38e3U - iVar1 < param_2) {
      FUN_0049e740();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x48;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x38e38e3 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x48;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_00868440();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x48);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      iVar2 = FUN_0049e9c0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_0049ea50(iVar2,param_2,local_64);
      FUN_0049e9c0(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x48);
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x48;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_0049eb10(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x48 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (param_2 + iVar2) * 0x48);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      if ((uint)((iVar2 - param_1) / 0x48) < param_2) {
        FUN_0049e9c0(param_1,iVar2,param_2 * 0x48 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_0049eae0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x48,local_64
                    );
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x48;
        local_8 = 0;
        FUN_0049e970(param_1,*(int *)(in_ECX + 8) + param_2 * -0x48,local_64);
      }
      else {
        iVar1 = iVar2 + param_2 * -0x48;
        uVar4 = FUN_0049e9c0(iVar1,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_0049e910(param_1,iVar1,iVar2,iVar1);
        FUN_0049e970(param_1,param_2 * 0x48 + param_1,local_64);
      }
    }
  }
  FUN_0049e800();
  ExceptionList = local_10;
  return;
}


// ==== Catch@0049ecfe @ 0x0049ecfe ====

void Catch_0049ecfe(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_0049eb10(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0049edb1 @ 0x0049edb1 ====

void Catch_0049edb1(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x48;
  FUN_0049eb10(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0049ee40 @ 0x0049ee40 ====

void FUN_0049ee40(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x48 != 0) {
      iVar1 = (param_2 - iVar1) / 0x48;
      goto LAB_0049ee85;
    }
  }
  iVar1 = 0;
LAB_0049ee85:
  FUN_0049eb40(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x48;
  return;
}


// ==== FUN_0049eeb0 @ 0x0049eeb0 ====

void FUN_0049eeb0(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x48) {
    FUN_0049e800();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0049ef00 @ 0x0049ef00 ====

void FUN_0049ef00(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x48) {
    FUN_0049e800();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0049ef10 @ 0x0049ef10 ====

void FUN_0049ef10(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x48) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x48))) {
    FUN_0049ee40(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_0049ea50(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x48;
  return;
}


// ==== FUN_0049efa0 @ 0x0049efa0 ====

void FUN_0049efa0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097e8e0;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x48;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_0049e7b0(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_0049e9c0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@0049f02a @ 0x0049f02a ====

void Catch_0049f02a(void)

{
  FUN_0049eeb0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_0049f040 @ 0x0049f040 ====

void FUN_0049f040(void)

{
  int in_ECX;
  
  FUN_0049eeb0();
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0049f070 @ 0x0049f070 ====

void FUN_0049f070(void)

{
  int in_ECX;
  
  FUN_0049eeb0();
  if (0xf < *(uint *)(in_ECX + 0x34)) {
    _free(*(void **)(in_ECX + 0x20));
    return;
  }
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  if (*(uint *)(in_ECX + 0x18) < 0x10) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    *(undefined4 *)(in_ECX + 0x18) = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0049f0c0 @ 0x0049f0c0 ====

void FUN_0049f0c0(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e8f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_0049efa0(param_1 + 0x1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049f130 @ 0x0049f130 ====

void FUN_0049f130(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e8f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_0049f0c0(param_1 + 0x1c);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049f1a0 @ 0x0049f1a0 ====

void FUN_0049f1a0(void)

{
  FUN_0049f070();
  return;
}


// ==== FUN_0049f1b0 @ 0x0049f1b0 ====

void FUN_0049f1b0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e8f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = 0;
  FUN_0049f0c0(param_2);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049f220 @ 0x0049f220 ====

undefined4 *
FUN_0049f220(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined1 param_5)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0097e921;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x58);
  local_8 = 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_1;
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    FUN_0049f130(param_4);
    *(undefined1 *)(puVar1 + 0x15) = param_5;
    *(undefined1 *)((int)puVar1 + 0x55) = 0;
  }
  ExceptionList = local_10;
  return puVar1;
}


// ==== Catch@0049f29e @ 0x0049f29e ====

void Catch_0049f29e(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_0049f2c0 @ 0x0049f2c0 ====

void FUN_0049f2c0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_0097e938;
  local_c = ExceptionList;
  if (0x38e38e1 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_0049f220(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x54);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x54) = 1;
      *param_1 = piVar4;
      ExceptionList = local_c;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0x15] == '\0') {
LAB_0049f3b9:
        *(undefined1 *)(*piVar5 + 0x54) = 1;
        *(undefined1 *)(piVar6 + 0x15) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x54) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0049e450(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x54) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x54) = 0;
        FUN_0049e4a0(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0x15] == '\0') goto LAB_0049f3b9;
      if (piVar7 == (int *)*piVar2) {
        FUN_0049e4a0(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x54) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x54) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x55) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x54);
  } while( true );
}


// ==== FUN_0049f4a0 @ 0x0049f4a0 ====

/* WARNING: Removing unreachable block (ram,0x0049f4ff) */

void FUN_0049f4a0(undefined4 *param_1,undefined4 *param_2)

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
  if (*(char *)((int)puVar6[1] + 0x55) == '\0') {
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
LAB_0049f530:
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
        if (uVar5 == 0) goto LAB_0049f530;
      }
      bVar11 = (int)uVar5 < 0;
      if (bVar11) {
        puVar9 = (undefined4 *)*puVar6;
      }
      else {
        puVar9 = (undefined4 *)puVar6[2];
      }
    } while (*(char *)((int)puVar9 + 0x55) == '\0');
  }
  param_2 = puVar6;
  if (bVar11) {
    if (puVar6 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar6 = (undefined4 *)FUN_0049f2c0(&param_2,1,puVar6,iVar3);
      *param_1 = *puVar6;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_0049e500();
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
    puVar6 = (undefined4 *)FUN_0049f2c0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_0049f610 @ 0x0049f610 ====

/* WARNING: Removing unreachable block (ram,0x0049f71d) */
/* WARNING: Removing unreachable block (ram,0x0049f72d) */
/* WARNING: Removing unreachable block (ram,0x0049f736) */
/* WARNING: Removing unreachable block (ram,0x0049f739) */
/* WARNING: Removing unreachable block (ram,0x0049f729) */
/* WARNING: Removing unreachable block (ram,0x0049f747) */
/* WARNING: Removing unreachable block (ram,0x0049f754) */
/* WARNING: Removing unreachable block (ram,0x0049f75f) */
/* WARNING: Removing unreachable block (ram,0x0049f75b) */
/* WARNING: Removing unreachable block (ram,0x0049f74f) */
/* WARNING: Removing unreachable block (ram,0x0049f762) */

void FUN_0049f610(undefined4 param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  int iVar7;
  bool bVar8;
  undefined1 local_50 [4];
  undefined1 local_4c;
  undefined4 local_3c;
  undefined4 local_38;
  undefined **local_34 [10];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e938;
  pvStack_c = ExceptionList;
  if (*(char *)((int)param_2 + 0x55) != '\0') {
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
  FUN_0049db20();
  piVar5 = (int *)*param_2;
  if (*(char *)((int)piVar5 + 0x55) == '\0') {
    if (*(char *)(param_2[2] + 0x55) == '\0') {
      piVar5 = (int *)param_2[2];
    }
  }
  else {
    piVar5 = (int *)param_2[2];
  }
  piVar6 = (int *)param_2[1];
  if (*(char *)((int)piVar5 + 0x55) == '\0') {
    piVar5[1] = (int)piVar6;
  }
  if (*(int **)(*(int *)(in_ECX + 4) + 4) == param_2) {
    *(int **)(*(int *)(in_ECX + 4) + 4) = piVar5;
  }
  else if ((int *)*piVar6 == param_2) {
    *piVar6 = (int)piVar5;
  }
  else {
    piVar6[2] = (int)piVar5;
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if ((int *)*puVar1 == param_2) {
    if (*(char *)((int)piVar5 + 0x55) == '\0') {
      piVar3 = (int *)FUN_0049db00(piVar5);
    }
    else {
      piVar3 = piVar6;
    }
    *puVar1 = piVar3;
  }
  iVar7 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar7 + 8) == param_2) {
    if (*(char *)((int)piVar5 + 0x55) == '\0') {
      uVar4 = FUN_0049dae0(piVar5);
      *(undefined4 *)(iVar7 + 8) = uVar4;
    }
    else {
      *(int **)(iVar7 + 8) = piVar6;
    }
  }
  if ((char)param_2[0x15] == '\x01') {
    if (piVar5 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        if ((char)piVar5[0x15] != '\x01') break;
        piVar3 = (int *)*piVar6;
        if (piVar5 == piVar3) {
          piVar3 = (int *)piVar6[2];
          if ((char)piVar3[0x15] == '\0') {
            *(undefined1 *)(piVar3 + 0x15) = 1;
            *(undefined1 *)(piVar6 + 0x15) = 0;
            FUN_0049e450(piVar6);
            piVar3 = (int *)piVar6[2];
          }
          if (*(char *)((int)piVar3 + 0x55) == '\0') {
            if ((*(char *)(*piVar3 + 0x54) == '\x01') && (*(char *)(piVar3[2] + 0x54) == '\x01'))
            goto LAB_0049f834;
            if (*(char *)(piVar3[2] + 0x54) == '\x01') {
              *(undefined1 *)(*piVar3 + 0x54) = 1;
              *(undefined1 *)(piVar3 + 0x15) = 0;
              FUN_0049e4a0(piVar3);
              piVar3 = (int *)piVar6[2];
            }
            *(char *)(piVar3 + 0x15) = (char)piVar6[0x15];
            *(undefined1 *)(piVar6 + 0x15) = 1;
            *(undefined1 *)(piVar3[2] + 0x54) = 1;
            FUN_0049e450(piVar6);
            break;
          }
        }
        else {
          if ((char)piVar3[0x15] == '\0') {
            *(undefined1 *)(piVar3 + 0x15) = 1;
            *(undefined1 *)(piVar6 + 0x15) = 0;
            FUN_0049e4a0(piVar6);
            piVar3 = (int *)*piVar6;
          }
          if (*(char *)((int)piVar3 + 0x55) == '\0') {
            if ((*(char *)(piVar3[2] + 0x54) != '\x01') || (*(char *)(*piVar3 + 0x54) != '\x01')) {
              if (*(char *)(*piVar3 + 0x54) == '\x01') {
                *(undefined1 *)(piVar3[2] + 0x54) = 1;
                *(undefined1 *)(piVar3 + 0x15) = 0;
                FUN_0049e450(piVar3);
                piVar3 = (int *)*piVar6;
              }
              *(char *)(piVar3 + 0x15) = (char)piVar6[0x15];
              *(undefined1 *)(piVar6 + 0x15) = 1;
              *(undefined1 *)(*piVar3 + 0x54) = 1;
              FUN_0049e4a0(piVar6);
              break;
            }
LAB_0049f834:
            *(undefined1 *)(piVar3 + 0x15) = 0;
          }
        }
        bVar8 = piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4);
        piVar5 = piVar6;
        piVar6 = (int *)piVar6[1];
      } while (bVar8);
    }
    *(undefined1 *)(piVar5 + 0x15) = 1;
  }
  iVar7 = param_2[0x12];
  if (iVar7 != 0) {
    iVar2 = param_2[0x13];
    for (; iVar7 != iVar2; iVar7 = iVar7 + 0x48) {
      FUN_0049e800();
    }
    _free((void *)param_2[0x12]);
    return;
  }
  param_2[0x12] = 0;
  param_2[0x13] = 0;
  param_2[0x14] = 0;
  if (0xf < (uint)param_2[0x10]) {
    _free((void *)param_2[0xb]);
    return;
  }
  param_2[0x10] = 0xf;
  param_2[0xf] = 0;
  *(undefined1 *)(param_2 + 0xb) = 0;
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


// ==== FUN_0049f930 @ 0x0049f930 ====

void FUN_0049f930(void *param_1)

{
  if (*(char *)((int)param_1 + 0x55) == '\0') {
    FUN_0049f930(*(undefined4 *)((int)param_1 + 8));
    FUN_0049f1a0();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_0049f970 @ 0x0049f970 ====

void FUN_0049f970(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_0049f930(piVar6[1]);
    *(int *)(*(int *)(in_ECX + 4) + 4) = *(int *)(in_ECX + 4);
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)*(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 4);
    *(int *)(*(int *)(in_ECX + 4) + 8) = *(int *)(in_ECX + 4);
    *param_1 = **(undefined4 **)(in_ECX + 4);
    return;
  }
  while (piVar3 != piVar4) {
    piVar6 = piVar3;
    if (*(char *)((int)piVar3 + 0x55) == '\0') {
      piVar6 = (int *)piVar3[2];
      if (*(char *)((int)piVar6 + 0x55) == '\0') {
        cVar1 = *(char *)(*piVar6 + 0x55);
        piVar2 = (int *)*piVar6;
        while (cVar1 == '\0') {
          cVar1 = *(char *)(*piVar2 + 0x55);
          piVar6 = piVar2;
          piVar2 = (int *)*piVar2;
        }
      }
      else {
        cVar1 = *(char *)(piVar3[1] + 0x55);
        piVar5 = (int *)piVar3[1];
        piVar2 = piVar3;
        while ((piVar6 = piVar5, cVar1 == '\0' && (piVar2 == (int *)piVar6[2]))) {
          cVar1 = *(char *)(piVar6[1] + 0x55);
          piVar5 = (int *)piVar6[1];
          piVar2 = piVar6;
        }
      }
    }
    FUN_0049f610(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_0049fa30 @ 0x0049fa30 ====

void FUN_0049fa30(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_0049f970(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_0049fa60 @ 0x0049fa60 ====

void FUN_0049fa60(byte param_1)

{
  void *in_ECX;
  
  FUN_0049fa80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049fa80 @ 0x0049fa80 ====

void FUN_0049fa80(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0097e963;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009aef4c;
  local_4 = 1;
  FUN_0049f970(local_10,*(undefined4 *)in_ECX[0x14],(undefined4 *)in_ECX[0x14]);
  _free((void *)in_ECX[0x14]);
  return;
}


// ==== FUN_0049fb00 @ 0x0049fb00 ====

void FUN_0049fb00(void)

{
  char cVar1;
  void *pvVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e986;
  local_c = ExceptionList;
  if (DAT_00b5ac0c == 0) {
    ExceptionList = &local_c;
    cVar1 = FUN_007979d0();
    if (cVar1 == '\0') {
      pvVar2 = operator_new(0x1c);
      local_4 = 1;
      if (pvVar2 != (void *)0x0) {
        FUN_004a0790(pvVar2);
      }
    }
    else {
      pvVar2 = operator_new(0x3c);
      local_4 = 0;
      if (pvVar2 != (void *)0x0) {
        FUN_004a19b0(pvVar2);
        ExceptionList = local_c;
        return;
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049fb90 @ 0x0049fb90 ====

void FUN_0049fb90(void)

{
  if (DAT_00b5ac0c != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5ac0c)(1);
  }
  return;
}


// ==== FUN_0049fbb0 @ 0x0049fbb0 ====

void FUN_0049fbb0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e9b1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  if (DAT_00b5a7c8 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(4);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_004a6460(pvVar1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5a7d0 == 0) {
    pvVar1 = operator_new(0x2c);
    local_4 = 1;
    if (pvVar1 != (void *)0x0) {
      FUN_004a49b0(pvVar1);
    }
  }
  local_4 = 0xffffffff;
  if (DAT_00b5a7cc == 0) {
    pvVar1 = operator_new(4);
    local_4 = 2;
    if (pvVar1 != (void *)0x0) {
      FUN_004a2840(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049fc60 @ 0x0049fc60 ====

void FUN_0049fc60(void)

{
  if (DAT_00b5a7d0 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a7d0)(1);
  }
  if (DAT_00b5a7cc != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a7cc)(1);
  }
  if (DAT_00b5a7c8 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a7c8)(1);
  }
  return;
}


// ==== FUN_0049fca0 @ 0x0049fca0 ====

void FUN_0049fca0(void)

{
  void *pvVar1;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0097e9cb;
  local_c = ExceptionList;
  if (DAT_00b5a7e4 == 0) {
    ExceptionList = &local_c;
    pvVar1 = operator_new(0x10);
    local_4 = 0;
    if (pvVar1 != (void *)0x0) {
      FUN_004a7230(pvVar1);
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_0049fcf0 @ 0x0049fcf0 ====

void FUN_0049fcf0(void)

{
  if (DAT_00b5a7e4 != (undefined4 *)0x0) {
    (**(code **)*DAT_00b5a7e4)(1);
  }
  return;
}


// ==== FUN_0049fd10 @ 0x0049fd10 ====

void FUN_0049fd10(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 4))();
  *(undefined4 *)(iVar1 + 0x20) = param_1;
  return;
}


// ==== FUN_0049fd20 @ 0x0049fd20 ====

int FUN_0049fd20(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 4))();
  *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + 1;
  return iVar1 + 0x28;
}


// ==== FUN_0049fd30 @ 0x0049fd30 ====

undefined4 FUN_0049fd30(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 4))();
  *(int *)(iVar1 + 0x28) = *(int *)(iVar1 + 0x28) + -1;
  return *(undefined4 *)(iVar1 + 0x28);
}


// ==== FUN_0049fd40 @ 0x0049fd40 ====

void FUN_0049fd40(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0049fd42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x10))();
  return;
}


// ==== FUN_0049fd50 @ 0x0049fd50 ====

bool FUN_0049fd50(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 4))();
  return *(int *)(iVar1 + 0x30) == 2;
}


// ==== FUN_0049fd60 @ 0x0049fd60 ====

void FUN_0049fd60(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0049fd62. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x2c))();
  return;
}


// ==== FUN_0049fd70 @ 0x0049fd70 ====

undefined4 FUN_0049fd70(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_EAX;
  int *in_ECX;
  undefined1 auStack_2c [4];
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0097e9e8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar1 = (**(code **)(*in_ECX + 0xc))();
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  FUN_00401660(param_1,0,0xffffffff);
  uStack_4 = 0;
  uStack_10 = uVar1;
  iVar2 = (**(code **)(*in_ECX + 4))();
  uVar1 = FUN_004a8360(auStack_2c,*(undefined4 *)(iVar2 + 0x1c));
  if (uStack_14 < 0x10) {
    ExceptionList = pvStack_c;
    return uVar1;
  }
  _free(pvStack_28);
  return extraout_EAX;
}


// ==== FUN_0049fe10 @ 0x0049fe10 ====

void FUN_0049fe10(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af048;
  in_ECX[1] = 0;
  in_ECX[2] = param_1;
  return;
}


// ==== FUN_0049fe30 @ 0x0049fe30 ====

void FUN_0049fe30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af048;
  return;
}


// ==== FUN_0049fe50 @ 0x0049fe50 ====

bool FUN_0049fe50(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00411430();
  return iVar1 == *(int *)(in_ECX + 4);
}


// ==== FUN_0049fe80 @ 0x0049fe80 ====

void FUN_0049fe80(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(int *)(in_ECX + 4) - 1;
  *(uint *)(in_ECX + 4) = uVar1 & ((int)uVar1 < 1) - 1;
  return;
}


// ==== FUN_0049fea0 @ 0x0049fea0 ====

int FUN_0049fea0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  iVar2 = FUN_00411430();
  if (iVar1 < iVar2) {
    *(int *)(in_ECX + 4) = iVar1 + 1;
    uVar3 = FUN_00411510(iVar1);
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(uVar3,0,0xffffffff);
    return param_1;
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401740(&DAT_009af042,0);
  return param_1;
}


// ==== FUN_0049ff20 @ 0x0049ff20 ====

void FUN_0049ff20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af048;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049ff40 @ 0x0049ff40 ====

void FUN_0049ff40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af090;
  return;
}


// ==== FUN_0049ff50 @ 0x0049ff50 ====

void FUN_0049ff50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009af090;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0049ff70 @ 0x0049ff70 ====

void FUN_0049ff70(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  if (*(char *)(iVar1 + 0x31) == '\0') {
    do {
      iVar1 = *(int *)(iVar1 + 8);
    } while (*(char *)(iVar1 + 0x31) == '\0');
  }
  return;
}


// ==== FUN_0049ff90 @ 0x0049ff90 ====

void FUN_0049ff90(int *param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  iVar1 = *param_1;
  *param_1 = *(int *)(iVar1 + 8);
  if (*(char *)(*(int *)(iVar1 + 8) + 0x31) == '\0') {
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


