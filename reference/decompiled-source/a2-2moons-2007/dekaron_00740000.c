// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x740000-0x74ffff

// ==== FUN_00740140 @ 0x00740140 ====

void FUN_00740140(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992966;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009efca0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  local_4 = 2;
  FUN_00401740(s_filltering_txt_009efc64,0xe);
  FUN_0073fe40();
  FUN_00401740(s_wordfillter_txt_009efc74,0xf);
  FUN_0073ffc0();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae18 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ae18 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00740220 @ 0x00740220 ====

void FUN_00740220(byte param_1)

{
  void *in_ECX;
  
  FUN_0073fdc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00740240 @ 0x00740240 ====

void FUN_00740240(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efcf0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00740260 @ 0x00740260 ====

undefined4 FUN_00740260(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 4);
}


// ==== FUN_00740280 @ 0x00740280 ====

void FUN_00740280(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efd10;
  in_ECX[1] = 100;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5adc8 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5adc8 = in_ECX;
  return;
}


// ==== FUN_007402b0 @ 0x007402b0 ====

void FUN_007402b0(void)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x3c))();
  if (piVar1 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x007402cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0xc))();
  return;
}


// ==== FUN_007402d0 @ 0x007402d0 ====

void FUN_007402d0(void)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x3c))();
  if (piVar1 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x007402eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x10))();
  return;
}


// ==== FUN_007402f0 @ 0x007402f0 ====

void FUN_007402f0(void)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x3c))();
  if (piVar1 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0074030d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x14))();
  return;
}


// ==== FUN_00740310 @ 0x00740310 ====

void FUN_00740310(void)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
                    /* WARNING: Could not recover jumptable at 0x0074031f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x3c))();
  return;
}


// ==== FUN_00740330 @ 0x00740330 ====

void FUN_00740330(void)

{
  int *piVar1;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ac98 + 4))();
  piVar1 = (int *)(**(code **)(*piVar1 + 0x3c))();
  if (piVar1 == (int *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x0074034b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar1 + 0x1c))();
  return;
}


// ==== FUN_00740350 @ 0x00740350 ====

void FUN_00740350(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5adc8 = 0;
  *in_ECX = &PTR_FUN_009efcf0;
  return;
}


// ==== FUN_007403a0 @ 0x007403a0 ====

void FUN_007403a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00740350();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007403c0 @ 0x007403c0 ====

void FUN_007403c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efdac;
  return;
}


// ==== FUN_007403d0 @ 0x007403d0 ====

void FUN_007403d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efdac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007403f0 @ 0x007403f0 ====

int FUN_007403f0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x50;
}


// ==== FUN_00740410 @ 0x00740410 ====

byte FUN_00740410(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  char cStack_60;
  char cStack_58;
  ushort uStack_56;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a770 + 8))(param_1);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 4))();
    FUN_00689a70(uVar2);
    if (cStack_60 != '\0') {
      if (cStack_58 == '\0') {
        if ((((uStack_56 != 0) && (uStack_56 < 8)) || ((0xb < uStack_56 && (uStack_56 < 0x16)))) ||
           (((uStack_56 == 0x17 || (uStack_56 == 0x1a)) || (uStack_56 == 0x1b)))) {
          return 1;
        }
        if (((7 < uStack_56) && (uStack_56 < 0xc)) || ((uStack_56 == 0x16 || (uStack_56 == 0x19))))
        {
          return 2;
        }
      }
      else if (cStack_58 != '\x01') {
        if (cStack_58 == '\x02') {
          return 3;
        }
        if (cStack_58 == '\x03') {
          return 4;
        }
        if (cStack_58 == '\x04') {
          return 5;
        }
        if (cStack_58 == '\b') {
          return 10;
        }
        return (cStack_58 != '\f') - 1U & 0xb;
      }
    }
  }
  return 0;
}


// ==== FUN_00740530 @ 0x00740530 ====

undefined4 FUN_00740530(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    if ((*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x50 != 0) {
      *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0xc);
      return *(undefined4 *)(in_ECX + 0xc);
    }
  }
  return 0;
}


// ==== FUN_00740560 @ 0x00740560 ====

uint FUN_00740560(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == *(int *)(in_ECX + 0x10)) {
    return 0;
  }
  *(int *)(in_ECX + 4) = *(int *)(in_ECX + 4) + 0x50;
  return -(uint)(*(uint *)(in_ECX + 4) != *(uint *)(in_ECX + 0x10)) & *(uint *)(in_ECX + 4);
}


// ==== FUN_00740580 @ 0x00740580 ====

short * FUN_00740580(short param_1)

{
  short *psVar1;
  int in_ECX;
  
  psVar1 = *(short **)(in_ECX + 0xc);
  while( true ) {
    if (psVar1 == *(short **)(in_ECX + 0x10)) {
      return (short *)0x0;
    }
    if (*psVar1 == param_1) break;
    psVar1 = psVar1 + 0x28;
  }
  return psVar1;
}


// ==== FUN_007405b0 @ 0x007405b0 ====

/* WARNING: Removing unreachable block (ram,0x00740668) */

undefined1 * FUN_007405b0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  undefined1 *puVar5;
  undefined1 auStack_68 [4];
  undefined1 uStack_64;
  undefined4 uStack_54;
  undefined4 uStack_50;
  char *pcStack_4c;
  undefined1 auStack_2a [18];
  void *pvStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009929b8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a770 + 8))();
  if (piVar2 == (int *)0x0) {
    uStack_50 = (**(code **)(*DAT_00b5a794 + 0xc))();
    pcStack_4c = (char *)0x0;
    uStack_54 = 0x740617;
    FUN_00401660();
    pcStack_4c = auStack_2a + -6;
    puStack_4 = auStack_68;
    uStack_50 = 0xf;
    uStack_54 = 0;
    uStack_64 = 0;
    FUN_00401740(s__s____d_009efd78,7);
    puVar5 = puStack_8;
    FUN_00404230(puStack_8);
  }
  else {
    iVar3 = (**(code **)(*piVar2 + 4))();
    puVar5 = puStack_8;
    pcStack_4c = (char *)(iVar3 + 2);
    *(undefined4 *)(puStack_8 + 0x18) = 0xf;
    *(undefined4 *)(puStack_8 + 0x14) = 0;
    puStack_8[4] = 0;
    pcVar4 = pcStack_4c;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uStack_50 = 0x7406ab;
    FUN_00401740();
  }
  ExceptionList = pvStack_18;
  return puVar5;
}


// ==== FUN_007406d0 @ 0x007406d0 ====

/* WARNING: Removing unreachable block (ram,0x0074078f) */

undefined1 * FUN_007406d0(void)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined1 *extraout_EAX;
  char *pcVar4;
  undefined1 *puVar5;
  undefined1 auStack_84 [4];
  undefined1 uStack_80;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined1 *puStack_68;
  undefined1 auStack_46 [22];
  void *pvStack_30;
  uint uStack_1c;
  void *pvStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009929d2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a770 + 8))();
  if (piVar2 == (int *)0x0) {
    uStack_6c = (**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_68 = (undefined1 *)0x0;
    uStack_70 = 0x740737;
    FUN_00401660();
    puStack_68 = auStack_46 + -6;
    puStack_4 = auStack_84;
    uStack_6c = 0xf;
    uStack_70 = 0;
    uStack_80 = 0;
    FUN_00401740(s__s____d_009efd80,7);
    puVar5 = puStack_8;
    FUN_00404230(puStack_8);
  }
  else {
    iVar3 = (**(code **)(*piVar2 + 4))();
    pcVar4 = (char *)(iVar3 + 0x9b);
    pvStack_18 = (void *)0x0;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00401740();
    puStack_8 = (undefined1 *)0x1;
    thunk_FUN_00796f80();
    uStack_6c = (**(code **)(*DAT_00b5a794 + 0xc))();
    puVar5 = puStack_8;
    puStack_68 = (undefined1 *)0x0;
    *(undefined4 *)(puStack_8 + 0x18) = 0xf;
    *(undefined4 *)(puStack_8 + 0x14) = 0;
    puStack_8[4] = 0;
    uStack_70 = 0x74081c;
    FUN_00401660();
    if (0xf < uStack_1c) {
      puStack_68 = (undefined1 *)0x74082d;
      _free(pvStack_30);
      return extraout_EAX;
    }
  }
  ExceptionList = pvStack_18;
  return puVar5;
}


// ==== FUN_00740850 @ 0x00740850 ====

uint FUN_00740850(void)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  uint extraout_EAX;
  undefined1 auStack_1a8 [4];
  void *pvStack_1a4;
  uint uStack_190;
  char cStack_6c;
  uint uStack_62;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009929e7;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar1 = (int *)(**(code **)(*DAT_00b5a770 + 8))();
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))();
    FUN_00689a70();
    ExceptionList = pvStack_10;
    return -(uint)(cStack_6c != '\0') & uStack_62;
  }
  FUN_00401740(s__s____d_009efd98,7);
  uVar2 = FUN_00404230(auStack_1a8);
  puStack_8 = (undefined1 *)0x0;
  uVar3 = FUN_00796d50(uVar2);
  if (uStack_190 < 0x10) {
    ExceptionList = pvStack_10;
    return uVar3 & 0xffff0000;
  }
  _free(pvStack_1a4);
  return extraout_EAX;
}


// ==== FUN_00740940 @ 0x00740940 ====

void FUN_00740940(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efdc4;
  in_ECX[1] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5adcc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5adcc = in_ECX;
  return;
}


// ==== FUN_007409a0 @ 0x007409a0 ====

void FUN_007409a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efdc4;
  DAT_00b5adcc = 0;
  FUN_00741140();
  *in_ECX = &PTR_FUN_009efdac;
  return;
}


// ==== FUN_007409d0 @ 0x007409d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007409d0(undefined4 param_1)

{
  float10 fVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  float in_ECX;
  uint uVar9;
  int unaff_EDI;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float fStack_2a8;
  float local_2a4;
  float fStack_2a0;
  float fStack_29c;
  void *pvStack_294;
  undefined4 uStack_284;
  uint uStack_280;
  undefined4 uStack_27c;
  undefined2 uStack_278;
  void *pvStack_270;
  undefined4 uStack_260;
  uint uStack_25c;
  undefined1 auStack_258 [4];
  void *pvStack_254;
  undefined4 uStack_244;
  uint uStack_240;
  undefined1 auStack_23c [4];
  void *pvStack_238;
  undefined4 uStack_228;
  uint uStack_224;
  char local_214 [256];
  undefined4 local_114;
  undefined1 local_110;
  undefined1 local_10f;
  undefined1 local_10e;
  char local_10c [248];
  void *pvStack_14;
  int iStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992a24;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_2a4 = in_ECX;
  FUN_00741140();
  local_214[0] = '\0';
  FUN_0044a580(local_10c,&DAT_009efda0,s_NPCLocation_009efd68);
  uVar4 = 0;
  do {
    local_214[uVar4] = local_10c[uVar4];
    if (local_10c[uVar4] == '\0') goto LAB_00740a53;
    uVar4 = uVar4 + 1;
  } while (uVar4 < 0x100);
  local_214[0] = '\0';
LAB_00740a53:
  local_114 = param_1;
  local_110 = 10;
  local_10f = 0x2c;
  local_10e = 1;
  piVar5 = (int *)(**(code **)(*DAT_00b5aa34 + 8))(local_214);
  uVar4 = (**(code **)(*piVar5 + 0xc))();
  if (1 < uVar4) {
    uVar4 = 1;
    do {
      pcVar6 = (char *)(**(code **)(*piVar5 + 0x10))(0,uVar4);
      FUN_0044a580(local_214 + 0xfc,&DAT_009efda0,&DAT_009efd74);
      uVar9 = 0;
      iVar2 = 0xfc - (int)pcVar6;
      do {
        if (*pcVar6 != pcVar6[(int)(local_214 + iVar2)]) {
          uVar7 = FUN_00475a90(0,uVar4);
          fVar10 = (float10)FUN_00477510(1,uVar4);
          fVar1 = (float10)_DAT_00b3c5b0;
          fVar11 = (float10)FUN_00477510(2,uVar4);
          fVar12 = (float10)FUN_00477510(3,uVar4);
          uStack_280 = 0xf;
          uStack_284 = 0;
          pvStack_294 = (void *)((uint)pvStack_294 & 0xffffff00);
          uStack_25c = 0xf;
          uStack_260 = 0;
          pvStack_270 = (void *)((uint)pvStack_270 & 0xffffff00);
          fStack_29c = (float)fVar12;
          iStack_10 = 0;
          fStack_2a8 = (float)CONCAT22(fStack_2a8._2_2_,(short)uVar7);
          local_2a4 = (float)(fVar10 * fVar1);
          fStack_2a0 = (float)fVar11;
          uVar8 = FUN_007405b0(auStack_258,uVar7);
          iStack_10._0_1_ = 1;
          FUN_00401660(uVar8,0,0xffffffff);
          iStack_10 = (uint)iStack_10._1_3_ << 8;
          if (0xf < uStack_240) {
            _free(pvStack_254);
            return;
          }
          uStack_240 = 0xf;
          uStack_244 = 0;
          pvStack_254 = (void *)((uint)pvStack_254 & 0xffffff00);
          uStack_27c = FUN_00740410(uVar7);
          uStack_278 = FUN_00740850(uVar7);
          uVar7 = FUN_007406d0(auStack_23c,uVar7);
          iStack_10._0_1_ = 2;
          FUN_00401660(uVar7,0,0xffffffff);
          iStack_10 = (uint)iStack_10._1_3_ << 8;
          if (0xf < uStack_224) {
            _free(pvStack_238);
            return;
          }
          uStack_224 = 0xf;
          uStack_228 = 0;
          pvStack_238 = (void *)((uint)pvStack_238 & 0xffffff00);
          FUN_00741550(&fStack_2a8);
          iStack_10 = 0xffffffff;
          if (0xf < uStack_25c) {
            _free(pvStack_270);
            return;
          }
          uStack_25c = 0xf;
          uStack_260 = 0;
          pvStack_270 = (void *)((uint)pvStack_270 & 0xffffff00);
          if (0xf < uStack_280) {
            _free(pvStack_294);
            return;
          }
          uStack_280 = 0xf;
          uStack_284 = 0;
          pvStack_294 = (void *)((uint)pvStack_294 & 0xffffff00);
          break;
        }
        if (*pcVar6 == '\0') break;
        uVar9 = uVar9 + 1;
        pcVar6 = pcVar6 + 1;
      } while (uVar9 < 0x100);
      bVar3 = (char)((uint)unaff_EDI >> 0x18) + 1;
      unaff_EDI = (uint)bVar3 << 0x18;
      uVar4 = (uint)bVar3;
      uVar9 = (**(code **)(*piVar5 + 0xc))();
    } while (uVar4 < uVar9);
    in_ECX = fStack_2a8;
  }
  (**(code **)(*DAT_00b5aa34 + 0xc))(piVar5);
  *(undefined4 *)((int)in_ECX + 4) = *(undefined4 *)((int)in_ECX + 0x10);
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00740d00 @ 0x00740d00 ====

void FUN_00740d00(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x4c)) {
    _free(*(void **)(in_ECX + 0x38));
    return;
  }
  *(undefined4 *)(in_ECX + 0x4c) = 0xf;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined1 *)(in_ECX + 0x38) = 0;
  if (*(uint *)(in_ECX + 0x28) < 0x10) {
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0xf;
    *(undefined1 *)(in_ECX + 0x14) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x14));
  return;
}


// ==== FUN_00740d50 @ 0x00740d50 ====

void FUN_00740d50(void)

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
  puStack_8 = &LAB_00992978;
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


// ==== FUN_00740dc0 @ 0x00740dc0 ====

void FUN_00740dc0(undefined2 *param_1)

{
  undefined2 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099299b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = *param_1;
  *(undefined4 *)(in_ECX + 2) = *(undefined4 *)(param_1 + 2);
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 6) = *(undefined4 *)(param_1 + 6);
  *(undefined4 *)(in_ECX + 0x14) = 0xf;
  *(undefined4 *)(in_ECX + 0x12) = 0;
  *(undefined1 *)(in_ECX + 10) = 0;
  FUN_00401660(param_1 + 8,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x16) = *(undefined4 *)(param_1 + 0x16);
  in_ECX[0x18] = param_1[0x18];
  *(undefined4 *)(in_ECX + 0x26) = 0xf;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  FUN_00401660(param_1 + 0x1a,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00740e60 @ 0x00740e60 ====

int FUN_00740e60(int param_1,int param_2,int param_3)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  if (param_1 == param_2) {
    return param_3;
  }
  puVar2 = (undefined4 *)(param_2 + 8);
  puVar3 = (undefined4 *)(param_3 + 8);
  do {
    puVar1 = (undefined2 *)(param_2 + -0x50);
    param_2 = param_2 + -0x50;
    *(undefined2 *)(param_3 + -0x50) = *puVar1;
    param_3 = param_3 + -0x50;
    puVar3[-0x15] = puVar2[-0x15];
    puVar3[-0x14] = puVar2[-0x14];
    puVar3[-0x13] = puVar2[-0x13];
    FUN_00401660(puVar2 + -0x12,0,0xffffffff);
    puVar3[-0xb] = puVar2[-0xb];
    *(undefined2 *)(puVar3 + -10) = *(undefined2 *)(puVar2 + -10);
    FUN_00401660(puVar2 + -9,0,0xffffffff);
    puVar2 = puVar2 + -0x14;
    puVar3 = puVar3 + -0x14;
  } while (param_2 != param_1);
  return param_3;
}


// ==== FUN_00740ef0 @ 0x00740ef0 ====

int FUN_00740ef0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00992a41;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x50) {
    local_8 = 1;
    if (param_3 != 0) {
      FUN_00740dc0(param_1);
    }
    param_3 = param_3 + 0x50;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@00740f46 @ 0x00740f46 ====

void Catch_00740f46(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 0x10)) {
    puVar1 = (uint *)(iVar2 + 0x4c);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      if (0xf < puVar1[-9]) {
        _free((void *)puVar1[-0xe]);
        return;
      }
      puVar1[-9] = 0xf;
      puVar1[-10] = 0;
      *(undefined1 *)(puVar1 + -0xe) = 0;
      iVar2 = iVar2 + 0x50;
      puVar1 = puVar1 + 0x14;
    } while (iVar2 != *(int *)(unaff_EBP + 0x10));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00740fc0 @ 0x00740fc0 ====

void FUN_00740fc0(undefined2 *param_1,undefined2 *param_2,undefined2 *param_3)

{
  undefined4 *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (undefined4 *)(param_1 + 4);
    do {
      *param_1 = *param_3;
      puVar1[-1] = *(undefined4 *)(param_3 + 2);
      *puVar1 = *(undefined4 *)(param_3 + 4);
      puVar1[1] = *(undefined4 *)(param_3 + 6);
      FUN_00401660(param_3 + 8,0,0xffffffff);
      puVar1[9] = *(undefined4 *)(param_3 + 0x16);
      *(undefined2 *)(puVar1 + 10) = param_3[0x18];
      FUN_00401660(param_3 + 0x1a,0,0xffffffff);
      param_1 = param_1 + 0x28;
      puVar1 = puVar1 + 0x14;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_00741040 @ 0x00741040 ====

void FUN_00741040(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00992a61;
  local_10 = ExceptionList;
  uStack_7 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    local_8 = 1;
    if (param_1 != 0) {
      FUN_00740dc0(param_3);
    }
    param_1 = param_1 + 0x50;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@00741098 @ 0x00741098 ====

void Catch_00741098(void)

{
  int unaff_EBP;
  uint *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(unaff_EBP + -0x14);
  if (iVar2 != *(int *)(unaff_EBP + 8)) {
    puVar1 = (uint *)(iVar2 + 0x4c);
    do {
      if (0xf < *puVar1) {
        _free((void *)puVar1[-5]);
        return;
      }
      *puVar1 = 0xf;
      puVar1[-1] = 0;
      *(undefined1 *)(puVar1 + -5) = 0;
      if (0xf < puVar1[-9]) {
        _free((void *)puVar1[-0xe]);
        return;
      }
      puVar1[-9] = 0xf;
      puVar1[-10] = 0;
      *(undefined1 *)(puVar1 + -0xe) = 0;
      iVar2 = iVar2 + 0x50;
      puVar1 = puVar1 + 0x14;
    } while (iVar2 != *(int *)(unaff_EBP + 8));
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_00741110 @ 0x00741110 ====

void FUN_00741110(int param_1,int param_2)

{
  for (; param_1 != param_2; param_1 = param_1 + 0x50) {
    FUN_00740d00();
  }
  return;
}


// ==== FUN_00741140 @ 0x00741140 ====

void FUN_00741140(void)

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
  for (; iVar2 != iVar1; iVar2 = iVar2 + 0x50) {
    FUN_00740d00();
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_00741190 @ 0x00741190 ====

int FUN_00741190(int param_1,int param_2,undefined4 param_3)

{
  FUN_00741040(param_1,param_2,param_3);
  return param_2 * 0x50 + param_1;
}


// ==== FUN_007411c0 @ 0x007411c0 ====

void FUN_007411c0(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  undefined1 local_6c [2];
  undefined1 auStack_6a [18];
  void *local_58;
  uint local_44;
  void *local_34;
  undefined4 local_24;
  uint local_20;
  void *local_1c;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00992a78;
  local_10 = ExceptionList;
  local_14 = local_6c + -0xc;
  ExceptionList = &local_10;
  FUN_00740dc0(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  uVar5 = 0;
  local_8 = 0;
  if (iVar2 != 0) {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x50;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x50;
    }
    if (0x3333333U - iVar1 < param_2) {
      FUN_00740d50();
      uVar5 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x50;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x3333333 - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x50;
      }
      if (uVar5 < iVar2 + param_2) {
        iVar2 = FUN_007403f0();
        uVar5 = iVar2 + param_2;
      }
      pvVar3 = operator_new(uVar5 * 0x50);
      local_8 = CONCAT31(local_8._1_3_,1);
      local_1c = pvVar3;
      iVar2 = FUN_00740ef0(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      FUN_00741040(iVar2,param_2,local_6c);
      FUN_00740ef0(param_1,*(undefined4 *)(in_ECX + 8),iVar2 + param_2 * 0x50);
      iVar2 = 0;
      if (*(int *)(in_ECX + 4) != 0) {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x50;
      }
      if (*(int *)(in_ECX + 4) != 0) {
        FUN_00741110(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x50 + (int)pvVar3);
      *(void **)(in_ECX + 8) = (void *)((param_2 + iVar2) * 0x50 + (int)pvVar3);
      *(void **)(in_ECX + 4) = pvVar3;
    }
    else {
      iVar2 = *(int *)(in_ECX + 8);
      if ((uint)((iVar2 - param_1) / 0x50) < param_2) {
        FUN_00740ef0(param_1,iVar2,param_2 * 0x50 + param_1);
        local_8 = CONCAT31(local_8._1_3_,3);
        FUN_00741190(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x50,local_6c
                    );
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + param_2 * 0x50;
        local_8 = 0;
        FUN_00740fc0(param_1,*(int *)(in_ECX + 8) + param_2 * -0x50,local_6c);
      }
      else {
        iVar1 = iVar2 + param_2 * -0x50;
        uVar4 = FUN_00740ef0(iVar1,iVar2,iVar2);
        *(undefined4 *)(in_ECX + 8) = uVar4;
        FUN_00740e60(param_1,iVar1,iVar2,iVar1);
        FUN_00740fc0(param_1,param_2 * 0x50 + param_1,local_6c);
      }
    }
  }
  if (0xf < local_20) {
    _free(local_34);
    return;
  }
  local_20 = 0xf;
  local_24 = 0;
  local_34 = (void *)((uint)local_34 & 0xffffff00);
  if (local_44 < 0x10) {
    ExceptionList = local_10;
    return;
  }
  _free(local_58);
  return;
}


// ==== Catch@0074137f @ 0x0074137f ====

void Catch_0074137f(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_00741110(_Memory,*(undefined4 *)(unaff_EBP + 0xc));
  _free(_Memory);
  return;
}


// ==== Catch@0074142f @ 0x0074142f ====

void Catch_0074142f(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x50;
  FUN_00741110(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x14) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_007414e0 @ 0x007414e0 ====

void FUN_007414e0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x50 != 0) {
      iVar1 = (param_2 - iVar1) / 0x50;
      goto LAB_00741525;
    }
  }
  iVar1 = 0;
LAB_00741525:
  FUN_007411c0(param_2,1,param_3);
  *param_1 = iVar1 * 0x50 + *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_00741550 @ 0x00741550 ====

void FUN_00741550(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x50) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x50))) {
    FUN_007414e0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_00741040(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x50;
  return;
}


// ==== FUN_007415e0 @ 0x007415e0 ====

void FUN_007415e0(byte param_1)

{
  void *in_ECX;
  
  FUN_007409a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00741600 @ 0x00741600 ====

void FUN_00741600(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efddc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00741620 @ 0x00741620 ====

void FUN_00741620(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efde8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5add4 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5add4 = in_ECX;
  return;
}


// ==== FUN_00741690 @ 0x00741690 ====

void FUN_00741690(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5add4 = 0;
  *in_ECX = &PTR_FUN_009efddc;
  return;
}


// ==== FUN_007416b0 @ 0x007416b0 ====

undefined4 FUN_007416b0(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  if (iVar1 == 0x700000c) {
    iVar1 = *(int *)(param_1 + 0xc);
    (**(code **)(*DAT_00b5add0 + 0x18))
              (0,CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x12)),
               *(undefined2 *)(iVar1 + 0x14));
    return 1;
  }
  if (iVar1 == 0x700000d) {
    iVar1 = *(int *)(param_1 + 0xc);
    (**(code **)(*DAT_00b5add0 + 0x18))
              (1,CONCAT22((short)((uint)iVar1 >> 0x10),*(undefined2 *)(iVar1 + 0x12)),
               *(undefined2 *)(iVar1 + 0x14));
    return 1;
  }
  return 0;
}


// ==== FUN_00741710 @ 0x00741710 ====

undefined4 FUN_00741710(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_007416b0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00741740 @ 0x00741740 ====

void FUN_00741740(byte param_1)

{
  void *in_ECX;
  
  FUN_00741690();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00741760 @ 0x00741760 ====

void FUN_00741760(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efecc;
  return;
}


// ==== FUN_00741770 @ 0x00741770 ====

void FUN_00741770(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009efecc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00741790 @ 0x00741790 ====

void FUN_00741790(void)

{
  return;
}


// ==== FUN_007417a0 @ 0x007417a0 ====

undefined2 FUN_007417a0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x58);
}


// ==== FUN_007417b0 @ 0x007417b0 ====

undefined2 FUN_007417b0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x5a);
}


// ==== FUN_007417c0 @ 0x007417c0 ====

undefined1 FUN_007417c0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x56);
}


// ==== FUN_007417d0 @ 0x007417d0 ====

undefined1 FUN_007417d0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x54);
}


// ==== FUN_007417e0 @ 0x007417e0 ====

undefined1 FUN_007417e0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x55);
}


// ==== FUN_007417f0 @ 0x007417f0 ====

undefined4 FUN_007417f0(undefined4 param_1)

{
  switch(param_1) {
  default:
    return 0x6e;
  case 5:
  case 6:
  case 0xb:
  case 0xc:
  case 0x11:
  case 0x12:
    return 0x6f;
  }
}


// ==== FUN_00741850 @ 0x00741850 ====

void FUN_00741850(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x54) != '\x01') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009eff2c;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 0x54) = 1;
      *(undefined1 *)(in_ECX + 0x56) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 0x54) = 1;
    *(undefined1 *)(in_ECX + 0x56) = 1;
  }
  return;
}


// ==== FUN_007418a0 @ 0x007418a0 ====

void FUN_007418a0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 0x54) = 0;
    return;
  }
  *puVar1 = &PTR_FUN_009eff40;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 0x54) = 0;
  return;
}


// ==== FUN_007418e0 @ 0x007418e0 ====

void FUN_007418e0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 0x55) = 1;
    return;
  }
  *puVar1 = &PTR_FUN_009eff54;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 0x55) = 1;
  return;
}


// ==== FUN_00741920 @ 0x00741920 ====

void FUN_00741920(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 0x55) = 0;
    return;
  }
  *puVar1 = &PTR_FUN_009eff68;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 0x55) = 0;
  return;
}


// ==== FUN_00741960 @ 0x00741960 ====

void FUN_00741960(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 0x56) = 1;
    return;
  }
  *puVar1 = &PTR_FUN_009eff7c;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 0x56) = 1;
  return;
}


// ==== FUN_007419a0 @ 0x007419a0 ====

void FUN_007419a0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 0x56) = 0;
    return;
  }
  *puVar1 = &PTR_FUN_009eff90;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 0x56) = 0;
  return;
}


// ==== FUN_007419e0 @ 0x007419e0 ====

void FUN_007419e0(byte param_1,undefined2 param_2,undefined2 param_3)

{
  undefined4 *puVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = (uint)param_1;
  puVar1 = operator_new(0xc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009effa4;
    puVar1[1] = uVar2;
    *(undefined2 *)(puVar1 + 2) = param_2;
    *(undefined2 *)((int)puVar1 + 10) = param_3;
  }
  FUN_00797a20(puVar1);
  if (uVar2 == 0) {
    *(short *)(in_ECX + 0x5a) = *(short *)(in_ECX + 0x5a) + 1;
  }
  else if (uVar2 == 1) {
    *(short *)(in_ECX + 0x58) = *(short *)(in_ECX + 0x58) + 1;
    return;
  }
  return;
}


// ==== FUN_00741a40 @ 0x00741a40 ====

void FUN_00741a40(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009effb8;
  }
  FUN_00797a20(puVar1);
  *(undefined2 *)(in_ECX + 0x58) = 0;
  *(undefined2 *)(in_ECX + 0x5a) = 0;
  return;
}


// ==== FUN_00741a80 @ 0x00741a80 ====

undefined4 FUN_00741a80(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5ab14 + 8))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  uVar2 = (**(code **)(*piVar1 + 0x1c))();
  return uVar2;
}


// ==== FUN_00741ab0 @ 0x00741ab0 ====

void FUN_00741ab0(void)

{
                    /* WARNING: Could not recover jumptable at 0x00741ab8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5aaec + 0x10))();
  return;
}


// ==== FUN_00741ac0 @ 0x00741ac0 ====

bool FUN_00741ac0(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5ac98 + 8))();
  return iVar1 == 1;
}


// ==== FUN_00741ae0 @ 0x00741ae0 ====

void FUN_00741ae0(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009effcc;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00741b10 @ 0x00741b10 ====

void FUN_00741b10(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x55) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009effe0;
      FUN_00797a20(puVar1);
      return;
    }
    FUN_00797a20(0);
  }
  return;
}


// ==== FUN_00741b40 @ 0x00741b40 ====

void FUN_00741b40(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009efff4;
  }
  FUN_00797a20(puVar1);
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f0008;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00741b90 @ 0x00741b90 ====

undefined4 FUN_00741b90(void)

{
  undefined4 uVar1;
  
  if (DAT_00b5a97c == (int *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00741b9c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*DAT_00b5a97c + 8))();
  return uVar1;
}


// ==== FUN_00741bb0 @ 0x00741bb0 ====

undefined4 FUN_00741bb0(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_minimapwnd_009efe94,0xf);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 8))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_minimapwnd_009efea4,0xf);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0xc))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_refresh_sentry_009efeb4,0xe);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x50))();
    (**(code **)(*in_ECX + 0x54))();
    return 1;
  }
  return 0;
}


// ==== FUN_00741c40 @ 0x00741c40 ====

undefined4 FUN_00741c40(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_00741bb0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00741c70 @ 0x00741c70 ====

void FUN_00741c70(void)

{
  int in_ECX;
  int *piVar1;
  int iVar2;
  
  FUN_00401740(&DAT_009efe93,0);
  piVar1 = (int *)(in_ECX + 0x28);
  iVar2 = 3;
  do {
    if (*piVar1 != 0) {
      FUN_00405de0(*piVar1,piVar1[1],piVar1 + -1,in_ECX);
      _free((void *)*piVar1);
      return;
    }
    *piVar1 = 0;
    piVar1[1] = 0;
    piVar1[2] = 0;
    piVar1 = piVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== FUN_00741cd0 @ 0x00741cd0 ====

void FUN_00741cd0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *unaff_EDI;
  uint *_Memory;
  undefined1 auStack_46 [2];
  uint local_44;
  undefined1 local_40 [4];
  void *pvStack_3c;
  uint uStack_38;
  uint uStack_34;
  void *local_30;
  undefined4 local_2c;
  uint local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992af4;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *puVar1 = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f002c;
  *puVar1 = &PTR_FUN_009f001c;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  local_4 = 2;
  _eh_vector_constructor_iterator_(in_ECX + 9,0x10,3,FUN_0045a320,FUN_00406250);
  local_4._0_1_ = 3;
  *(undefined1 *)(in_ECX + 0x15) = 0;
  *(undefined1 *)((int)in_ECX + 0x55) = 0;
  *(undefined1 *)((int)in_ECX + 0x56) = 1;
  *(undefined2 *)(in_ECX + 0x16) = 0;
  *(undefined2 *)((int)in_ECX + 0x5a) = 0;
  FUN_00741c70();
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(&DAT_009efe2a);
  local_4._0_1_ = 4;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40[0] = 0;
  FUN_00401740(s_show_minimapwnd_009efe2c);
  _Memory = &local_44;
  local_4 = CONCAT31(local_4._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 8))(_Memory,0);
  if (0xf < uStack_38) {
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10._0_1_ = 3;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  FUN_00401740(&DAT_009efe3c,0);
  local_10._0_1_ = 6;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_minimapwnd_009efe40,0xf);
  local_10 = CONCAT31(local_10._1_3_,7);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,&uStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c._0_1_ = 3;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(&DAT_009efe50,0);
  uStack_1c._0_1_ = 8;
  local_44 = 0xf;
  FUN_00401740(s_refresh_sentry_009efe54,0xe);
  uStack_1c = CONCAT31(uStack_1c._1_3_,9);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -0x16,0,local_40);
  if (0xf < unaff_EBP) {
    _free(_Memory);
    return;
  }
  if (0xf < uStack_34) {
    _free((void *)0x0);
    return;
  }
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5add0 = (undefined4 *)0x0;
    ExceptionList = local_30;
    return;
  }
  DAT_00b5add0 = in_ECX;
  ExceptionList = local_30;
  return;
}


// ==== FUN_00741f40 @ 0x00741f40 ====

void FUN_00741f40(void)

{
  undefined4 *in_ECX;
  void *pvStack_30;
  undefined4 *local_2c;
  void *local_28;
  undefined1 local_24;
  uint uStack_1c;
  void *pvStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992b66;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f002c;
  in_ECX[1] = &PTR_FUN_009f001c;
  local_4 = 3;
  DAT_00b5add0 = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_minimapwnd_009efe64,0xf);
  local_4 = CONCAT31(local_4._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8._0_1_ = 3;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  pvStack_18 = (void *)0x0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_minimapwnd_009efe74,0xf);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  pvStack_c._0_1_ = 3;
  if (0xf < pvStack_18) {
    _free(local_2c);
    return;
  }
  pvStack_18 = (void *)0xf;
  uStack_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffffff00);
  FUN_00401740(s_refresh_sentry_009efe84,0xe);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&pvStack_30);
  local_10._0_1_ = 3;
  if (0xf < uStack_1c) {
    _free(pvStack_30);
    return;
  }
  FUN_00741c70();
  local_10 = CONCAT31(local_10._1_3_,2);
  _eh_vector_destructor_iterator_(in_ECX + 9,0x10,3,FUN_00406250);
  if ((uint)in_ECX[8] < 0x10) {
    in_ECX[8] = 0xf;
    in_ECX[7] = 0;
    *(undefined1 *)(in_ECX + 3) = 0;
    in_ECX[1] = &PTR_FUN_009ef7a4;
    *in_ECX = &PTR_FUN_009efecc;
    ExceptionList = pvStack_18;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_007420c0 @ 0x007420c0 ====

undefined4 FUN_007420c0(void)

{
  return 0x70210000;
}


// ==== FUN_007420d0 @ 0x007420d0 ====

undefined4 FUN_007420d0(void)

{
  return 0x70210001;
}


// ==== FUN_007420e0 @ 0x007420e0 ====

undefined4 FUN_007420e0(void)

{
  return 0x70210003;
}


// ==== FUN_007420f0 @ 0x007420f0 ====

undefined4 FUN_007420f0(void)

{
  return 0x70210004;
}


// ==== FUN_00742100 @ 0x00742100 ====

undefined4 FUN_00742100(void)

{
  return 0x70210005;
}


// ==== FUN_00742110 @ 0x00742110 ====

undefined4 FUN_00742110(void)

{
  return 0x70210006;
}


// ==== FUN_00742120 @ 0x00742120 ====

undefined4 FUN_00742120(void)

{
  return 0x70210008;
}


// ==== FUN_00742130 @ 0x00742130 ====

undefined4 FUN_00742130(void)

{
  return 0x70210009;
}


// ==== FUN_00742140 @ 0x00742140 ====

undefined4 FUN_00742140(void)

{
  return 0x70210010;
}


// ==== FUN_00742150 @ 0x00742150 ====

undefined4 FUN_00742150(void)

{
  return 0x70210011;
}


// ==== FUN_00742160 @ 0x00742160 ====

undefined4 FUN_00742160(void)

{
  return 0x70210014;
}


// ==== FUN_00742170 @ 0x00742170 ====

undefined4 FUN_00742170(void)

{
  return 0x70210015;
}


// ==== FUN_00742180 @ 0x00742180 ====

void FUN_00742180(void)

{
  FUN_00742190();
  return;
}


// ==== FUN_00742190 @ 0x00742190 ====

void FUN_00742190(byte param_1)

{
  void *in_ECX;
  
  FUN_00741f40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007421b0 @ 0x007421b0 ====

void FUN_007421b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f012c;
  return;
}


// ==== FUN_007421c0 @ 0x007421c0 ====

void FUN_007421c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f012c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007421e0 @ 0x007421e0 ====

undefined1 FUN_007421e0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_007421f0 @ 0x007421f0 ====

void FUN_007421f0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009f0160;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 4) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 1;
  }
  return;
}


// ==== FUN_00742230 @ 0x00742230 ====

void FUN_00742230(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f0188;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00742260 @ 0x00742260 ====

void FUN_00742260(void)

{
  undefined4 *puVar1;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f019c;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00742290 @ 0x00742290 ====

undefined4 FUN_00742290(void)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*DAT_00b5adc0 + 0x1c))();
  if (iVar2 == 0) {
    return 1;
  }
  cVar1 = (**(code **)(*DAT_00b5add0 + 0x40))();
  if ((cVar1 == '\0') || (iVar2 = (**(code **)(*DAT_00b5adc0 + 0x1c))(), iVar2 != 6)) {
    return 0;
  }
  return 1;
}


// ==== FUN_007422d0 @ 0x007422d0 ====

void FUN_007422d0(void)

{
                    /* WARNING: Could not recover jumptable at 0x007422d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5adc0 + 0xc))();
  return;
}


// ==== FUN_007422e0 @ 0x007422e0 ====

void FUN_007422e0(void)

{
                    /* WARNING: Could not recover jumptable at 0x007422e8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5adc0 + 0x18))();
  return;
}


// ==== FUN_007422f0 @ 0x007422f0 ====

void FUN_007422f0(void)

{
                    /* WARNING: Could not recover jumptable at 0x007422f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5adc0 + 0x14))();
  return;
}


// ==== FUN_00742310 @ 0x00742310 ====

void FUN_00742310(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      *puVar1 = &PTR_FUN_009f0174;
    }
    FUN_00797a20(puVar1);
    *(undefined1 *)(in_ECX + 4) = 0;
    if (DAT_00b5af00 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0074234b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*DAT_00b5af00 + 0x1c))();
      return;
    }
  }
  return;
}


// ==== FUN_00742350 @ 0x00742350 ====

undefined4 FUN_00742350(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_targetwnd_009f0104,0xe);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 8))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_targetwnd_009f0114,0xe);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0xc))();
    return 1;
  }
  return 0;
}


// ==== FUN_007423b0 @ 0x007423b0 ====

undefined4 FUN_007423b0(undefined4 param_1)

{
  (**(code **)(*DAT_00b5adc0 + 0x10))(param_1);
  return param_1;
}


// ==== FUN_007423e0 @ 0x007423e0 ====

undefined4 FUN_007423e0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_00742350(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00742410 @ 0x00742410 ====

void FUN_00742410(void)

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
  
  puStack_8 = &LAB_00992b98;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f01b0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  FUN_00401740(&DAT_009f00c2,0);
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = 0;
  FUN_00401740(s_show_targetwnd_009f00c4,0xe);
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
  FUN_00401740(&DAT_009f00d3,0);
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_targetwnd_009f00d4,0xe);
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
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5adb8 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5adb8 = in_ECX;
  }
  *(undefined1 *)(in_ECX + 1) = 0;
  ExceptionList = local_24;
  return;
}


// ==== FUN_00742590 @ 0x00742590 ====

void FUN_00742590(void)

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
  
  puStack_8 = &LAB_00992bba;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f01b0;
  local_4 = 0;
  DAT_00b5adb8 = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_targetwnd_009f00e4,0xe);
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
  FUN_00401740(s_hide_targetwnd_009f00f4,0xe);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  if (uStack_18 < 0x10) {
    *in_ECX = &PTR_FUN_009f012c;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_00742670 @ 0x00742670 ====

undefined4 FUN_00742670(void)

{
  return 0x70190000;
}


// ==== FUN_00742680 @ 0x00742680 ====

undefined4 FUN_00742680(void)

{
  return 0x70190001;
}


// ==== FUN_00742690 @ 0x00742690 ====

undefined4 FUN_00742690(void)

{
  return 0x70190002;
}


// ==== FUN_007426a0 @ 0x007426a0 ====

undefined4 FUN_007426a0(void)

{
  return 0x70190003;
}


// ==== FUN_007426b0 @ 0x007426b0 ====

void FUN_007426b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00742590();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007426d0 @ 0x007426d0 ====

void FUN_007426d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f01e4;
  return;
}


// ==== FUN_007426e0 @ 0x007426e0 ====

void FUN_007426e0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f01e4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00742700 @ 0x00742700 ====

void FUN_00742700(void)

{
  void *pvVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992be6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 4) = 2;
  pvVar1 = operator_new(0x58);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0078dc40();
  }
  local_4 = 0xffffffff;
  *(undefined4 *)(in_ECX + 8) = uVar2;
  pvVar1 = operator_new(0x58);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0xc) = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0078d6c0();
  *(undefined4 *)(in_ECX + 0xc) = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_007427a0 @ 0x007427a0 ====

void FUN_007427a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992bf8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f0218;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5adc0 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5adc0 = in_ECX;
  }
  FUN_00742700();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00742820 @ 0x00742820 ====

void FUN_00742820(undefined4 *param_1)

{
  int *in_ECX;
  uint uVar1;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = in_ECX + 2;
  do {
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 4))(param_1);
    }
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (uVar1 < 2);
  (**(code **)(*in_ECX + 0x2c))(*param_1);
  return;
}


// ==== FUN_00742860 @ 0x00742860 ====

void FUN_00742860(undefined4 param_1)

{
  int in_ECX;
  uint uVar1;
  int *piVar2;
  
  if (*(int *)(in_ECX + 4) != 2) {
    uVar1 = 0;
    piVar2 = (int *)(in_ECX + 8);
    do {
      if ((int *)*piVar2 != (int *)0x0) {
        (**(code **)(*(int *)*piVar2 + 8))(param_1);
      }
      uVar1 = uVar1 + 1;
      piVar2 = piVar2 + 1;
    } while (uVar1 < 2);
  }
  return;
}


// ==== FUN_007428a0 @ 0x007428a0 ====

float10 FUN_007428a0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  float local_8;
  float local_4;
  
  piVar1 = *(int **)(in_ECX + 0xc);
  local_8 = 0.0;
  local_4 = 0.0;
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x10))();
    local_8 = *(float *)(iVar2 + 0x14);
    iVar2 = (**(code **)(*piVar1 + 0x10))();
    local_4 = *(float *)(iVar2 + 0x18);
  }
  return (float10)local_8 / (float10)local_4;
}


// ==== FUN_007428f0 @ 0x007428f0 ====

undefined4 FUN_007428f0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = 0;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
    uVar1 = *(undefined4 *)(iVar2 + 0x4c);
  }
  return uVar1;
}


// ==== FUN_00742910 @ 0x00742910 ====

undefined2 FUN_00742910(void)

{
  undefined2 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = 0;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
    uVar1 = *(undefined2 *)(iVar2 + 0x10);
  }
  return uVar1;
}


// ==== FUN_00742930 @ 0x00742930 ====

undefined4 FUN_00742930(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = 0;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
    uVar1 = *(undefined4 *)(iVar2 + 0xc);
  }
  return uVar1;
}


// ==== FUN_00742950 @ 0x00742950 ====

undefined1 FUN_00742950(void)

{
  undefined1 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = 0;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
    uVar1 = *(undefined1 *)(iVar2 + 0x3c);
  }
  return uVar1;
}


// ==== FUN_00742970 @ 0x00742970 ====

undefined4 FUN_00742970(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = 0;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
    uVar1 = *(undefined4 *)(iVar2 + 0x40);
  }
  return uVar1;
}


// ==== FUN_00742990 @ 0x00742990 ====

undefined1 FUN_00742990(byte param_1)

{
  undefined1 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = 0;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
    uVar1 = *(undefined1 *)(iVar2 + 0x44 + (uint)param_1);
  }
  return uVar1;
}


// ==== FUN_007429b0 @ 0x007429b0 ====

void FUN_007429b0(void)

{
  int in_ECX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(in_ECX + 8);
  iVar2 = 2;
  do {
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined4 *)(in_ECX + 4) = 2;
  return;
}


// ==== FUN_007429f0 @ 0x007429f0 ====

void FUN_007429f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992c0a;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f0218;
  local_4 = 0;
  FUN_007429b0();
  DAT_00b5adc0 = 0;
  *in_ECX = &PTR_FUN_009f01e4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00742a40 @ 0x00742a40 ====

int FUN_00742a40(int param_1)

{
  int iVar1;
  int extraout_EAX;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992c1c;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_4 = 0;
  ExceptionList = &pvStack_c;
  if (*(int **)(in_ECX + 0xc) != (int *)0x0) {
    ExceptionList = &pvStack_c;
    iVar1 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
    FUN_00401660(iVar1 + 0x20,0,0xffffffff);
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_28,0,0xffffffff);
  if (local_10 < 0x10) {
    ExceptionList = pvStack_c;
    return param_1;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00742ae0 @ 0x00742ae0 ====

void FUN_00742ae0(byte param_1)

{
  void *in_ECX;
  
  FUN_007429f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00742b00 @ 0x00742b00 ====

void FUN_00742b00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f024c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00742b30 @ 0x00742b30 ====

void FUN_00742b30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0258;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5adbc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5adbc = in_ECX;
  return;
}


// ==== FUN_00742b80 @ 0x00742b80 ====

undefined4 FUN_00742b80(int param_1)

{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_14 = *(undefined4 *)(param_1 + 4);
  local_10 = *(undefined4 *)(param_1 + 8);
  local_c = *(undefined4 *)(param_1 + 0xc);
  local_8 = *(undefined4 *)(param_1 + 0x10);
  local_4 = *(undefined4 *)(param_1 + 0x14);
  (**(code **)(*DAT_00b5adc0 + 8))(&local_14);
  return 1;
}


// ==== FUN_00742bd0 @ 0x00742bd0 ====

void FUN_00742bd0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5adbc = 0;
  *in_ECX = &PTR_FUN_009f024c;
  return;
}


// ==== FUN_00742bf0 @ 0x00742bf0 ====

undefined4 FUN_00742bf0(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x40001) {
    (**(code **)(*DAT_00b5adc0 + 4))(param_1[1]);
  }
  else if ((iVar1 != 0x50011) && (iVar1 == 0x70190010)) {
    FUN_00742b80(param_1);
    return 1;
  }
  return 0;
}


// ==== FUN_00742c40 @ 0x00742c40 ====

void FUN_00742c40(byte param_1)

{
  void *in_ECX;
  
  FUN_00742bd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00742c60 @ 0x00742c60 ====

void FUN_00742c60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f027c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00742c80 @ 0x00742c80 ====

undefined1 FUN_00742c80(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_00742c90 @ 0x00742c90 ====

undefined1 FUN_00742c90(void)

{
  return 0;
}


// ==== FUN_00742ca0 @ 0x00742ca0 ====

void FUN_00742ca0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f02c0;
  *(undefined1 *)(in_ECX + 1) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aefc = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aefc = in_ECX;
  return;
}


// ==== FUN_00742cd0 @ 0x00742cd0 ====

void FUN_00742cd0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 1;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f0298;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_00742d00 @ 0x00742d00 ====

undefined4 FUN_00742d00(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar1 = &PTR_FUN_009f02ac;
  FUN_00797a20(puVar1);
  return 1;
}


// ==== FUN_00742d40 @ 0x00742d40 ====

void FUN_00742d40(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aefc = 0;
  *in_ECX = &PTR_FUN_009f027c;
  return;
}


// ==== FUN_00742d60 @ 0x00742d60 ====

void FUN_00742d60(int param_1)

{
  undefined4 uVar1;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992c38;
  local_c = ExceptionList;
  if ((((param_1 != 0xc) && (param_1 != 0xd)) && (param_1 != 0xe)) && (DAT_00b5a97c != 0)) {
    ExceptionList = &local_c;
    FUN_00401830(s_Emotimotion_Play__d_009f0264);
    uVar1 = FUN_00404230(local_28);
    local_4 = 0;
    FUN_00796d50(uVar1);
    local_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  return;
}


// ==== FUN_00742e00 @ 0x00742e00 ====

undefined4 FUN_00742e00(void)

{
  return 0x70180000;
}


// ==== FUN_00742e10 @ 0x00742e10 ====

undefined4 FUN_00742e10(void)

{
  return 0x70180001;
}


// ==== FUN_00742e20 @ 0x00742e20 ====

void FUN_00742e20(byte param_1)

{
  void *in_ECX;
  
  FUN_00742d40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00742e40 @ 0x00742e40 ====

void FUN_00742e40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f03ec;
  return;
}


// ==== FUN_00742e50 @ 0x00742e50 ====

void FUN_00742e50(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f03ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00742e70 @ 0x00742e70 ====

void FUN_00742e70(void)

{
  return;
}


// ==== FUN_00742e80 @ 0x00742e80 ====

undefined1 FUN_00742e80(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_00742e90 @ 0x00742e90 ====

undefined4 FUN_00742e90(int *param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = (**(code **)(*in_ECX + 0x20))(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00742ec0 @ 0x00742ec0 ====

void FUN_00742ec0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\x01') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009f0410;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 8) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_00742f00 @ 0x00742f00 ====

undefined4 FUN_00742f00(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 0;
    return 1;
  }
  *puVar1 = &PTR_FUN_009f0424;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 8) = 0;
  return 1;
}


// ==== FUN_00742f40 @ 0x00742f40 ====

void FUN_00742f40(undefined4 param_1)

{
  (**(code **)(*DAT_00b5a794 + 4))(4,param_1);
  return;
}


// ==== FUN_00742f60 @ 0x00742f60 ====

undefined4 FUN_00742f60(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_helpwnd_009f03b4,0xc);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 8))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_helpwnd_009f03c4,0xc);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0xc))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_refresh_string_009f03d4,0xe);
  if (iVar1 == 0) {
    (**(code **)(*DAT_00b5a794 + 0x10))();
    return 1;
  }
  return 0;
}


// ==== FUN_00742ff0 @ 0x00742ff0 ====

uint FUN_00742ff0(undefined1 param_1,void *param_2)

{
  uint extraout_EAX;
  uint extraout_EAX_00;
  uint in_ECX;
  uint in_stack_0000001c;
  undefined2 *in_stack_00000020;
  undefined2 *in_stack_00000024;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992c58;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  local_10 = in_ECX;
  FUN_0069a470(&local_10,&param_1);
  if (local_10 != *(uint *)(in_ECX + 0x10)) {
    local_10 = *(uint *)(local_10 + 0x28);
    *in_stack_00000020 = (short)local_10;
    *in_stack_00000024 = (short)(local_10 >> 0x10);
    if (in_stack_0000001c < 0x10) {
      ExceptionList = local_c;
      return CONCAT31((uint3)(byte)(local_10 >> 0x18),1);
    }
    _free(param_2);
    return extraout_EAX_00;
  }
  *in_stack_00000020 = 0xffff;
  if (in_stack_0000001c < 0x10) {
    ExceptionList = local_c;
    return local_10 & 0xffffff00;
  }
  _free(param_2);
  return extraout_EAX;
}


// ==== FUN_007430a0 @ 0x007430a0 ====

undefined4 FUN_007430a0(undefined4 param_1,undefined2 param_2,undefined2 param_3)

{
  undefined4 uVar1;
  
  uVar1 = (**(code **)(*DAT_00b5a794 + 0xc))(4,CONCAT22(param_2,param_3));
  uRam00000018 = 0xf;
  uRam00000014 = 0;
  uRam00000004 = 0;
  FUN_00401660(uVar1,0,0xffffffff);
  return 0;
}


// ==== FUN_007430f0 @ 0x007430f0 ====

void FUN_007430f0(void)

{
  undefined4 *in_ECX;
  undefined1 auStack_32 [2];
  undefined4 *local_30;
  void *pvStack_2c;
  void *local_28;
  undefined1 local_24;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992cb4;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f0444;
  in_ECX[1] = &PTR_FUN_009f0438;
  DAT_00b5ae94 = 0;
  local_4 = 2;
  local_30 = in_ECX;
  FUN_00743bd0(*(undefined4 *)(in_ECX[4] + 4));
  *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
  in_ECX[5] = 0;
  *(undefined4 *)in_ECX[4] = in_ECX[4];
  *(undefined4 *)(in_ECX[4] + 8) = in_ECX[4];
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(s_show_helpwnd_009f0344,0xc);
  local_4 = CONCAT31(local_4._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8._0_1_ = 2;
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_helpwnd_009f0354,0xc);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&pvStack_2c);
  pvStack_c._0_1_ = 2;
  if (0xf < uStack_18) {
    _free(pvStack_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  pvStack_2c = (void *)((uint)pvStack_2c & 0xffffff00);
  FUN_00401740(s_refresh_string_009f0364,0xe);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_30);
  if (uStack_1c < 0x10) {
    local_10 = CONCAT31(local_10._1_3_,1);
    FUN_00743e80(auStack_32 + -6,*(undefined4 *)in_ECX[4],(undefined4 *)in_ECX[4]);
    _free((void *)in_ECX[4]);
    return;
  }
  _free(local_30);
  return;
}


// ==== FUN_00743290 @ 0x00743290 ====

/* WARNING: Removing unreachable block (ram,0x00743514) */
/* WARNING: Removing unreachable block (ram,0x00743588) */
/* WARNING: Removing unreachable block (ram,0x00743598) */
/* WARNING: Removing unreachable block (ram,0x007435b6) */
/* WARNING: Removing unreachable block (ram,0x007435c3) */
/* WARNING: Removing unreachable block (ram,0x007434d5) */
/* WARNING: Removing unreachable block (ram,0x0074347a) */
/* WARNING: Removing unreachable block (ram,0x007433b3) */
/* WARNING: Removing unreachable block (ram,0x00743472) */
/* WARNING: Removing unreachable block (ram,0x00743651) */
/* WARNING: Removing unreachable block (ram,0x007434b3) */
/* WARNING: Removing unreachable block (ram,0x0074365a) */
/* WARNING: Removing unreachable block (ram,0x007434f2) */
/* WARNING: Removing unreachable block (ram,0x00743663) */
/* WARNING: Removing unreachable block (ram,0x007435e8) */

void FUN_00743290(void)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_e0 [4];
  undefined1 local_dc;
  undefined1 local_94 [4];
  void *local_90;
  undefined4 local_80;
  uint local_7c;
  undefined1 *local_78;
  int local_70;
  int local_68;
  void *local_60;
  undefined4 local_50;
  uint local_4c;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992cff;
  pvStack_c = ExceptionList;
  local_7c = 0xf;
  local_80 = 0;
  local_90 = (void *)((uint)local_90 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740();
  local_4 = 0;
  local_70 = FUN_00410500();
  local_4 = 0xffffffff;
  if (0xf < local_7c) {
    _free(local_90);
    return;
  }
  local_7c = 0xf;
  local_80 = 0;
  local_90 = (void *)((uint)local_90 & 0xffffff00);
  if (local_70 == 0) {
    local_4c = 0xf;
    local_50 = 0;
    local_60 = (void *)((uint)local_60 & 0xffffff00);
    FUN_00401740();
    local_4 = 1;
    FUN_00406880();
    local_4 = 0xffffffff;
    if (local_4c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_60);
    return;
  }
  local_68 = *(int *)(local_70 + 0x44);
  iVar2 = *(int *)(local_70 + 0x40);
  if (iVar2 != local_68) {
    do {
      local_7c = 0xf;
      local_80 = 0;
      local_4 = 2;
      FUN_00404fb0();
      local_78 = auStack_e0;
      local_dc = 0;
      FUN_00401740(s_Invalid_Line_____d__009f039c,0x14);
      FUN_00404230(local_94);
      local_4._0_1_ = 3;
      FUN_00405bd0();
      local_4 = CONCAT31(local_4._1_3_,4);
      FUN_00796d50();
      if (0xf < local_4c) {
        _free(local_60);
        return;
      }
      local_4c = 0xf;
      local_50 = 0;
      local_60 = (void *)((uint)local_60 & 0xffffff00);
      if (0xf < local_7c) {
        _free(local_90);
        return;
      }
      local_90 = (void *)((uint)local_90 & 0xffffff00);
      local_4c = 0xf;
      local_50 = 0;
      iVar2 = iVar2 + 0x1c;
    } while (iVar2 != local_68);
  }
  local_7c = 0xf;
  local_80 = 0;
  local_4 = 0xffffffff;
  (**(code **)(*DAT_00b5a7cc + 0x14))();
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00743670 @ 0x00743670 ====

void FUN_00743670(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *unaff_EDI;
  uint *_Memory;
  uint *puStack_5c;
  undefined1 auStack_46 [2];
  uint local_44;
  undefined1 local_40 [4];
  void *pvStack_3c;
  uint uStack_38;
  uint uStack_34;
  void *local_30;
  undefined4 local_2c;
  uint local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992d57;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *puVar1 = &PTR_FUN_009ef7a4;
  local_4 = 1;
  *in_ECX = &PTR_FUN_009f0444;
  *puVar1 = &PTR_FUN_009f0438;
  puStack_5c = (uint *)0x7436be;
  iVar2 = FUN_004a37b0();
  in_ECX[4] = iVar2;
  *(undefined1 *)(iVar2 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[4] + 4) = in_ECX[4];
  *(undefined4 *)in_ECX[4] = in_ECX[4];
  *(undefined4 *)(in_ECX[4] + 8) = in_ECX[4];
  in_ECX[5] = 0;
  puStack_5c = (uint *)0x0;
  local_4._0_1_ = 2;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(&DAT_009f0312);
  puStack_5c = (uint *)0xc;
  local_4._0_1_ = 3;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40[0] = 0;
  FUN_00401740(s_show_helpwnd_009f0314);
  puStack_5c = &local_28;
  _Memory = &local_44;
  local_4 = CONCAT31(local_4._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))(_Memory,0);
  if (0xf < uStack_38) {
    _free(unaff_EBX);
    return;
  }
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  local_10._0_1_ = 2;
  if (0xf < uStack_1c) {
    _free(local_30);
    return;
  }
  uStack_1c = 0xf;
  uStack_20 = 0;
  local_30 = (void *)((uint)local_30 & 0xffffff00);
  FUN_00401740(&DAT_009f0321,0);
  local_10._0_1_ = 5;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_helpwnd_009f0324,0xc);
  local_10 = CONCAT31(local_10._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,&uStack_34);
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c._0_1_ = 2;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(&DAT_009f0331,0);
  uStack_1c._0_1_ = 7;
  local_44 = 0xf;
  FUN_00401740(s_refresh_string_009f0334,0xe);
  uStack_1c = CONCAT31(uStack_1c._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 8))(&puStack_5c,0,local_40);
  if (0xf < unaff_EBP) {
    _free(_Memory);
    return;
  }
  local_28 = CONCAT31(local_28._1_3_,2);
  if (0xf < uStack_34) {
    _free((void *)0x0);
    return;
  }
  FUN_00743290();
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ae94 = (undefined4 *)0x0;
    ExceptionList = local_30;
    return;
  }
  DAT_00b5ae94 = in_ECX;
  ExceptionList = local_30;
  return;
}


// ==== FUN_007438e0 @ 0x007438e0 ====

undefined4 FUN_007438e0(void)

{
  return 0x70170000;
}


// ==== FUN_007438f0 @ 0x007438f0 ====

undefined4 FUN_007438f0(void)

{
  return 0x70170001;
}


// ==== FUN_00743900 @ 0x00743900 ====

/* WARNING: Removing unreachable block (ram,0x00743a10) */
/* WARNING: Removing unreachable block (ram,0x00743a21) */
/* WARNING: Removing unreachable block (ram,0x00743a2a) */
/* WARNING: Removing unreachable block (ram,0x00743a2d) */
/* WARNING: Removing unreachable block (ram,0x00743a1d) */
/* WARNING: Removing unreachable block (ram,0x00743a3b) */
/* WARNING: Removing unreachable block (ram,0x00743a48) */
/* WARNING: Removing unreachable block (ram,0x00743a53) */
/* WARNING: Removing unreachable block (ram,0x00743a4f) */
/* WARNING: Removing unreachable block (ram,0x00743a43) */
/* WARNING: Removing unreachable block (ram,0x00743a56) */

void FUN_00743900(undefined4 param_1,int *param_2)

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
  puStack_8 = &LAB_00992d98;
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
            goto LAB_00743b27;
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
LAB_00743b27:
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


// ==== FUN_00743bd0 @ 0x00743bd0 ====

void FUN_00743bd0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_00743bd0(*(undefined4 *)((int)param_1 + 8));
    FUN_00446f40();
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_00743c10 @ 0x00743c10 ====

void * FUN_00743c10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00992d81;
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


// ==== Catch@00743c82 @ 0x00743c82 ====

void Catch_00743c82(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_00743ca0 @ 0x00743ca0 ====

void FUN_00743ca0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  puStack_8 = &LAB_00992d98;
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
  piVar4 = (int *)FUN_00743c10(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_00743d99:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_00743d99;
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


// ==== FUN_00743e80 @ 0x00743e80 ====

void FUN_00743e80(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_00743bd0(piVar6[1]);
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
    FUN_00743900(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_00743f40 @ 0x00743f40 ====

/* WARNING: Removing unreachable block (ram,0x00743f9f) */

void FUN_00743f40(undefined4 *param_1,undefined4 *param_2)

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
LAB_00743fd0:
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
        if (uVar5 == 0) goto LAB_00743fd0;
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
      puVar6 = (undefined4 *)FUN_00743ca0(&param_2,1,puVar6,iVar3);
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
    puVar6 = (undefined4 *)FUN_00743ca0(&param_2,bVar11,puVar6,iVar3);
    *param_1 = *puVar6;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *param_1 = puVar9;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ==== FUN_007440b0 @ 0x007440b0 ====

void FUN_007440b0(void)

{
  int in_ECX;
  undefined1 local_4 [4];
  
  FUN_00743e80(local_4,**(undefined4 **)(in_ECX + 4),*(undefined4 **)(in_ECX + 4));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_007440e0 @ 0x007440e0 ====

void FUN_007440e0(void)

{
  FUN_007440f0();
  return;
}


// ==== FUN_007440f0 @ 0x007440f0 ====

void FUN_007440f0(byte param_1)

{
  void *in_ECX;
  
  FUN_007430f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00744110 @ 0x00744110 ====

void FUN_00744110(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f046c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00744130 @ 0x00744130 ====

void FUN_00744130(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0474;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae28 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae28 = in_ECX;
  return;
}


// ==== FUN_00744160 @ 0x00744160 ====

void FUN_00744160(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ae28 = 0;
  *in_ECX = &PTR_FUN_009f046c;
  return;
}


// ==== FUN_00744180 @ 0x00744180 ====

void FUN_00744180(byte param_1)

{
  void *in_ECX;
  
  FUN_00744160();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007441a0 @ 0x007441a0 ====

void FUN_007441a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f047c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007441c0 @ 0x007441c0 ====

undefined1 FUN_007441c0(void)

{
  return 0;
}


// ==== FUN_007441d0 @ 0x007441d0 ====

void FUN_007441d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0488;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae2c = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae2c = in_ECX;
  return;
}


// ==== FUN_00744200 @ 0x00744200 ====

void FUN_00744200(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ae2c = 0;
  *in_ECX = &PTR_FUN_009f047c;
  return;
}


// ==== FUN_00744220 @ 0x00744220 ====

void FUN_00744220(byte param_1)

{
  void *in_ECX;
  
  FUN_00744200();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00744240 @ 0x00744240 ====

void FUN_00744240(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0494;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00744260 @ 0x00744260 ====

void FUN_00744260(void)

{
  return;
}


// ==== FUN_00744270 @ 0x00744270 ====

undefined1 FUN_00744270(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_00744280 @ 0x00744280 ====

undefined1 FUN_00744280(void)

{
  return 0;
}


// ==== FUN_00744290 @ 0x00744290 ====

void FUN_00744290(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  
  puVar1 = in_ECX + 1;
  *puVar1 = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f04e0;
  *puVar1 = &PTR_FUN_009f04d4;
  *(undefined1 *)(in_ECX + 2) = 0;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ae30 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae30 = in_ECX;
  return;
}


// ==== FUN_007442d0 @ 0x007442d0 ====

void FUN_007442d0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\x01') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009f04ac;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 8) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_00744310 @ 0x00744310 ====

void FUN_00744310(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 0;
    return;
  }
  *puVar1 = &PTR_FUN_009f04c0;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00744350 @ 0x00744350 ====

void FUN_00744350(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = &PTR_FUN_009f04d4;
  DAT_00b5ae30 = 0;
  in_ECX[1] = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f0494;
  return;
}


// ==== FUN_00744370 @ 0x00744370 ====

undefined4 FUN_00744370(void)

{
  return 0x70160000;
}


// ==== FUN_00744380 @ 0x00744380 ====

undefined4 FUN_00744380(void)

{
  return 0x70160001;
}


// ==== FUN_00744390 @ 0x00744390 ====

void FUN_00744390(void)

{
  FUN_007443a0();
  return;
}


// ==== FUN_007443a0 @ 0x007443a0 ====

void FUN_007443a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00744350();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007443c0 @ 0x007443c0 ====

void FUN_007443c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f04f8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007443e0 @ 0x007443e0 ====

undefined1 FUN_007443e0(void)

{
  return 0;
}


// ==== FUN_007443f0 @ 0x007443f0 ====

void FUN_007443f0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0504;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5b148 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b148 = in_ECX;
  return;
}


// ==== FUN_00744420 @ 0x00744420 ====

void FUN_00744420(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5b148 = 0;
  *in_ECX = &PTR_FUN_009f04f8;
  return;
}


// ==== FUN_00744440 @ 0x00744440 ====

void FUN_00744440(byte param_1)

{
  void *in_ECX;
  
  FUN_00744420();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00744460 @ 0x00744460 ====

void FUN_00744460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0534;
  return;
}


// ==== FUN_00744470 @ 0x00744470 ====

void FUN_00744470(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0534;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00744490 @ 0x00744490 ====

void FUN_00744490(void)

{
  return;
}


// ==== FUN_007444a0 @ 0x007444a0 ====

undefined1 FUN_007444a0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_007444b0 @ 0x007444b0 ====

undefined1 FUN_007444b0(void)

{
  return 0;
}


// ==== FUN_007444c0 @ 0x007444c0 ====

void FUN_007444c0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 0;
    return;
  }
  *puVar1 = &PTR_FUN_009f0550;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00744500 @ 0x00744500 ====

void FUN_00744500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0584;
  in_ECX[1] = &PTR_FUN_009f0578;
  DAT_00b5b14c = 0;
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[9] = 0xf;
    in_ECX[8] = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
    in_ECX[1] = &PTR_FUN_009ef7a4;
    *in_ECX = &PTR_FUN_009f0534;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_00744550 @ 0x00744550 ====

void FUN_00744550(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992dce;
  local_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &local_c;
  *puVar1 = &PTR_FUN_009ef7a4;
  *in_ECX = &PTR_FUN_009f0584;
  *puVar1 = &PTR_FUN_009f0578;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  local_4 = 2;
  *(undefined1 *)(in_ECX + 2) = 0;
  FUN_00401740(&DAT_009f050e,0);
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5b14c = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5b14c = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_007445f0 @ 0x007445f0 ====

void FUN_007445f0(undefined1 param_1,void *param_2)

{
  void **ppvVar1;
  undefined4 *puVar2;
  int in_ECX;
  uint in_stack_0000001c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992de0;
  local_c = ExceptionList;
  local_4 = 0;
  ppvVar1 = &local_c;
  if (*(char *)(in_ECX + 8) != '\x01') {
    ExceptionList = &local_c;
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009f0564;
      puVar2[7] = 0xf;
      puVar2[6] = 0;
      *(undefined1 *)(puVar2 + 2) = 0;
    }
    FUN_00797a20(puVar2);
    *(undefined1 *)(in_ECX + 8) = 1;
    FUN_00401660(&param_1,0,0xffffffff);
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


// ==== FUN_007446a0 @ 0x007446a0 ====

int FUN_007446a0(int param_1)

{
  code *pcVar1;
  int extraout_EAX;
  int iVar2;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992df2;
  local_c = ExceptionList;
  if (*(int *)(in_ECX + 0x20) != 0) {
    ExceptionList = &local_c;
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(in_ECX + 0xc,0,0xffffffff);
    ExceptionList = local_c;
    return param_1;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(s_m_strCharName_empty______FALSE_009f0510,0x1e);
  local_4 = 0;
  FUN_00406880(local_28);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    iVar2 = (*pcVar1)();
    return iVar2;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_00744750 @ 0x00744750 ====

undefined4 FUN_00744750(void)

{
  return 0x70150001;
}


// ==== FUN_00744760 @ 0x00744760 ====

undefined4 FUN_00744760(void)

{
  return 0x70150000;
}


// ==== FUN_00744770 @ 0x00744770 ====

void FUN_00744770(byte param_1)

{
  void *in_ECX;
  
  FUN_00744790();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00744790 @ 0x00744790 ====

void FUN_00744790(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0564;
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


// ==== FUN_007447d0 @ 0x007447d0 ====

void FUN_007447d0(void)

{
  FUN_007447e0();
  return;
}


// ==== FUN_007447e0 @ 0x007447e0 ====

void FUN_007447e0(byte param_1)

{
  void *in_ECX;
  
  FUN_00744500();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00744800 @ 0x00744800 ====

void FUN_00744800(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0800;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00744820 @ 0x00744820 ====

undefined4 FUN_00744820(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0xc))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0xc))();
    if (iVar1 != 1) {
      iVar1 = (**(code **)(*param_1 + 0xc))();
      if (iVar1 != 2) {
        iVar1 = (**(code **)(*param_1 + 0xc))();
        if (iVar1 != 6) {
          return 0;
        }
      }
    }
  }
  return 1;
}


// ==== FUN_00744870 @ 0x00744870 ====

void FUN_00744870(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f080c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae80 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5ae80 = in_ECX;
  return;
}


// ==== FUN_007448a0 @ 0x007448a0 ====

void FUN_007448a0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ae80 = 0;
  *in_ECX = &PTR_FUN_009f0800;
  return;
}


// ==== FUN_007448c0 @ 0x007448c0 ====

void FUN_007448c0(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 auStack_8 [2];
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a6fc + 4))();
  if (piVar1 != (int *)0x0) {
    auStack_8[0] = param_1;
    piVar1 = (int *)(**(code **)(*piVar1 + 0x30))(auStack_8);
    if ((piVar1 != (int *)0x0) && (*(int *)(*piVar1 + 4) != 0)) {
      puVar2 = (undefined4 *)(**(code **)(*DAT_00b5a70c + 0xc))(1,0);
      *puVar2 = 0x1c;
      puVar2[1] = 0;
      puVar2[2] = 0;
      (**(code **)(*DAT_00b5a804 + 0xc))(param_1,puVar2);
      (**(code **)(*DAT_00b5a70c + 0x10))(1,puVar2);
    }
  }
  return;
}


// ==== FUN_00744940 @ 0x00744940 ====

/* WARNING: Removing unreachable block (ram,0x007449bd) */

void FUN_00744940(void)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  undefined1 auStack_15c [4];
  void *pvStack_158;
  uint uStack_144;
  undefined4 auStack_140 [75];
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00992e16;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    FUN_00401740();
    uStack_c = 0;
    FUN_00406880();
    uStack_c = 0xffffffff;
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  cVar2 = FUN_008289a0();
  if ((cVar2 != '\0') && (piVar4 = (int *)(**(code **)(*DAT_00b5ab90 + 8))(), piVar4 != (int *)0x0))
  {
    puVar5 = (undefined4 *)(**(code **)(*piVar4 + 4))();
    puVar7 = auStack_140;
    for (iVar3 = 0x49; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    FUN_004dd750();
    (**(code **)(*DAT_00b5ae84 + 0xc))();
    (**(code **)(*DAT_00b5ad58 + 8))();
    FUN_00401740(s_Insert_status___d_009f05e4,0x11);
    uVar6 = FUN_00404230(auStack_15c);
    uStack_c = 1;
    FUN_00796d50(uVar6);
    if (0xf < uStack_144) {
      _free(pvStack_158);
      return;
    }
  }
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_00744ab0 @ 0x00744ab0 ====

/* WARNING: Removing unreachable block (ram,0x00744b2d) */

void FUN_00744ab0(void)

{
  code *pcVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined1 auStack_160 [4];
  void *pvStack_15c;
  undefined4 uStack_14c;
  uint uStack_148;
  undefined4 auStack_144 [75];
  void *pvStack_18;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00992e36;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    FUN_00401740();
    uStack_c = 0;
    FUN_00406880();
    uStack_c = 0xffffffff;
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  FUN_00828b00();
  piVar3 = (int *)(**(code **)(*DAT_00b5ab90 + 8))();
  puVar4 = (undefined4 *)(**(code **)(*piVar3 + 4))();
  puVar6 = auStack_144;
  for (iVar2 = 0x49; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  FUN_004dd750();
  FUN_00401740(s_Delete_status___d_009f0604,0x11);
  uVar5 = FUN_00404230(auStack_160);
  puStack_10 = (undefined1 *)0x1;
  FUN_00796d50(uVar5);
  puStack_10 = (undefined1 *)0xffffffff;
  if (uStack_148 < 0x10) {
    uStack_148 = 0xf;
    uStack_14c = 0;
    pvStack_15c = (void *)((uint)pvStack_15c & 0xffffff00);
    (**(code **)(*DAT_00b5ae84 + 0xc))();
    (**(code **)(*DAT_00b5ad58 + 8))();
    ExceptionList = pvStack_18;
    return;
  }
  _free(pvStack_15c);
  return;
}


// ==== FUN_00744c30 @ 0x00744c30 ====

void FUN_00744c30(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  undefined4 uVar7;
  undefined1 auStack_12c [288];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992e4b;
  pvStack_c = ExceptionList;
  iVar6 = *(int *)(param_1 + 0x10);
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 0x10))();
  if ((iVar6 != iVar3) && (DAT_00b5acd8 != (int *)0x0)) {
    piVar4 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))();
    if (piVar4 == (int *)0x0) {
      FUN_0044a580();
      FUN_00797b80();
    }
    else {
      cVar2 = FUN_00744820();
      if (cVar2 != '\0') {
        piVar5 = (int *)(**(code **)(*piVar4 + 0x14))();
        iVar6 = (**(code **)(*piVar5 + 0x24))();
        if (*(int **)(iVar6 + 0x44) == (int *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = (int *)(**(code **)(**(int **)(iVar6 + 0x44) + 0x18))();
        }
        (**(code **)(*piVar5 + 0x14))();
        uVar7 = *(undefined4 *)(param_1 + 0x18);
        iVar6 = (**(code **)(*piVar4 + 0x10))();
        *(undefined4 *)(iVar6 + 4) = uVar7;
        bVar1 = *(byte *)(param_1 + 0x1c);
        iVar6 = (**(code **)(*piVar4 + 0x10))();
        *(uint *)(iVar6 + 0xc) = (uint)bVar1;
        bVar1 = *(byte *)(param_1 + 0x1d);
        iVar6 = (**(code **)(*piVar4 + 0x10))();
        *(uint *)(iVar6 + 0x10) = (uint)bVar1;
        FUN_00826b20();
        FUN_004dd750();
        (**(code **)(*DAT_00b5ae84 + 0xc))();
        FUN_007448c0();
        (**(code **)(*DAT_00b5a6ac + 0x20))();
        FUN_00401830(s_Mon_status_Insert___num____d_HP__009f0684);
        uVar7 = FUN_00404230(auStack_12c);
        puStack_8 = (undefined1 *)0x0;
        FUN_00796d50(uVar7);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_0044a580();
      FUN_00797b80();
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00744e10 @ 0x00744e10 ====

void FUN_00744e10(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  void *pvStack_40;
  uint uStack_2c;
  undefined1 auStack_28 [28];
  void *pvStack_c;
  undefined1 *puStack_8;
  int *piStack_4;
  
  piStack_4 = (int *)0xffffffff;
  puStack_8 = &LAB_00992e6d;
  pvStack_c = ExceptionList;
  iVar5 = *(int *)(param_1 + 0x10);
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 0x10))();
  if ((iVar5 != iVar3) && (DAT_00b5acd8 != (int *)0x0)) {
    piVar4 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))();
    if (piVar4 != (int *)0x0) {
      cVar2 = FUN_00744820();
      if (cVar2 == '\0') {
        FUN_00401830();
        piStack_4 = (int *)0x1;
        FUN_00796d50();
      }
      else {
        uVar6 = *(undefined4 *)(param_1 + 0x18);
        iVar5 = (**(code **)(*piVar4 + 0x10))();
        *(undefined4 *)(iVar5 + 4) = uVar6;
        bVar1 = *(byte *)(param_1 + 0x1c);
        iVar5 = (**(code **)(*piVar4 + 0x10))();
        *(uint *)(iVar5 + 0xc) = (uint)bVar1;
        bVar1 = *(byte *)(param_1 + 0x1d);
        iVar5 = (**(code **)(*piVar4 + 0x10))();
        *(uint *)(iVar5 + 0x10) = (uint)bVar1;
        piVar4 = (int *)(**(code **)(*piVar4 + 0x14))();
        iVar5 = (**(code **)(*piVar4 + 0x24))();
        if (*(int **)(iVar5 + 0x44) == (int *)0x0) {
          piVar4 = (int *)0x0;
        }
        else {
          piVar4 = (int *)(**(code **)(**(int **)(iVar5 + 0x44) + 0x18))();
        }
        (**(code **)(*piVar4 + 0x14))();
        FUN_00828b60();
        FUN_004dd750();
        (**(code **)(*DAT_00b5ae84 + 0xc))();
        (**(code **)(*DAT_00b5a6ac + 0x20))();
        FUN_00401830(s_Mon_status_del___num____d_HP___1_009f0720);
        uVar6 = FUN_00404230(auStack_28);
        piStack_4 = (int *)0x2;
        FUN_00796d50(uVar6);
      }
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    FUN_00401830();
    piStack_4 = piVar4;
    FUN_00796d50();
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00745000 @ 0x00745000 ====

void FUN_00745000(undefined4 param_1,int param_2)

{
  int *piVar1;
  code *pcVar2;
  char cVar3;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992e7f;
  pvStack_c = ExceptionList;
  piVar1 = *(int **)(param_2 + 0x14);
  if (piVar1 != (int *)0x0) {
    ExceptionList = &pvStack_c;
    cVar3 = (**(code **)(*piVar1 + 0x18))();
    while (cVar3 != '\0') {
      FUN_004dd750(0x13,cVar3,0,3,3,param_1);
      cVar3 = (**(code **)(*piVar1 + 0x1c))();
    }
    ExceptionList = pvStack_c;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_pList____NULL_009f07b4,0xd);
  local_4 = 0;
  FUN_00406880(local_28);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_007450d0 @ 0x007450d0 ====

void FUN_007450d0(int param_1)

{
  code *pcVar1;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00992e91;
  pvStack_c = ExceptionList;
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    ExceptionList = &pvStack_c;
    (**(code **)(**(int **)(param_1 + 0x14) + 0x2c))();
    ExceptionList = pvStack_c;
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_pList____NULL_009f07c4,0xd);
  local_4 = 0;
  FUN_00406880(local_28);
  local_4 = 0xffffffff;
  if (local_10 < 0x10) {
    local_10 = 0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00745170 @ 0x00745170 ====

void FUN_00745170(int param_1)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  undefined1 auStack_144 [4];
  void *pvStack_140;
  undefined4 uStack_130;
  uint auStack_12c [8];
  undefined1 auStack_10c [256];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992eb1;
  pvStack_c = ExceptionList;
  iVar7 = *(int *)(param_1 + 0x10);
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 0x10))();
  if (iVar7 == iVar3) {
    uVar4 = (**(code **)(*DAT_00b5a980 + 8))();
    FUN_00745000(0,uVar4);
    FUN_00828b80(uVar4);
    auStack_12c[0] = 0xf;
    uStack_130 = 0;
    pvStack_140 = (void *)((uint)pvStack_140 & 0xffffff00);
    FUN_00401740(s_SN_Clear__Self___009f075c,0x10);
    uStack_4 = 0;
    FUN_00796d50(auStack_144);
    uStack_4 = 0xffffffff;
    if (0xf < auStack_12c[0]) {
      _free(pvStack_140);
      return;
    }
    (**(code **)(*DAT_00b5ae84 + 0xc))();
    (**(code **)(*DAT_00b5ad58 + 8))();
  }
  else if (DAT_00b5acd8 != (int *)0x0) {
    piVar5 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(iVar7);
    if (piVar5 != (int *)0x0) {
      cVar2 = FUN_00744820(piVar5);
      if (cVar2 != '\0') {
        piVar6 = (int *)(**(code **)(*piVar5 + 0x14))();
        iVar7 = (**(code **)(*piVar6 + 0x24))();
        if (*(int **)(iVar7 + 0x44) == (int *)0x0) {
          piVar6 = (int *)0x0;
        }
        else {
          piVar6 = (int *)(**(code **)(**(int **)(iVar7 + 0x44) + 0x18))();
        }
        (**(code **)(*piVar6 + 0x14))((float)*(int *)(param_1 + 0x14));
        FUN_00745000(*(undefined4 *)(param_1 + 0x10),iVar7);
        uVar4 = *(undefined4 *)(param_1 + 0x18);
        iVar3 = (**(code **)(*piVar5 + 0x10))();
        *(undefined4 *)(iVar3 + 4) = uVar4;
        bVar1 = *(byte *)(param_1 + 0x1c);
        iVar3 = (**(code **)(*piVar5 + 0x10))();
        *(uint *)(iVar3 + 0xc) = (uint)bVar1;
        bVar1 = *(byte *)(param_1 + 0x1d);
        iVar3 = (**(code **)(*piVar5 + 0x10))();
        *(uint *)(iVar3 + 0x10) = (uint)bVar1;
        FUN_007450d0(iVar7);
        FUN_00401830(s_SN_Clear__Other___009f07a0);
        puStack_8 = (undefined1 *)0x1;
        FUN_00796d50(auStack_12c);
        puStack_8 = (undefined1 *)0xffffffff;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_0044a580(auStack_10c,&DAT_009f07d4,&DAT_009f0770);
      FUN_00797b80(auStack_10c);
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00745370 @ 0x00745370 ====

undefined4 FUN_00745370(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_00424500();
  switch(iVar1 + -0x5180000) {
  case 0:
    FUN_00744940(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 1:
    FUN_00744ab0(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 2:
    FUN_00744c30(*(undefined4 *)(param_1 + 0xc));
    return 1;
  case 3:
    FUN_00744e10(*(undefined4 *)(param_1 + 0xc));
    return 1;
  default:
    return 0;
  case 6:
    FUN_00745170(*(undefined4 *)(param_1 + 0xc));
    return 1;
  }
}


// ==== FUN_00745410 @ 0x00745410 ====

undefined4 FUN_00745410(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00745370(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00745440 @ 0x00745440 ====

void FUN_00745440(byte param_1)

{
  void *in_ECX;
  
  FUN_007448a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00745460 @ 0x00745460 ====

void FUN_00745460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f09bc;
  return;
}


// ==== FUN_00745470 @ 0x00745470 ====

void FUN_00745470(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f09bc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00745490 @ 0x00745490 ====

undefined4 FUN_00745490(void)

{
  return 0x70200000;
}


// ==== FUN_007454a0 @ 0x007454a0 ====

undefined4 FUN_007454a0(void)

{
  return 0x70200001;
}


// ==== FUN_007454b0 @ 0x007454b0 ====

undefined4 FUN_007454b0(void)

{
  return 0x70200002;
}


// ==== FUN_007454c0 @ 0x007454c0 ====

void FUN_007454c0(void)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x10))();
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  *puVar1 = &PTR_FUN_009f0a10;
  FUN_00797a20(puVar1);
  return;
}


// ==== FUN_007454f0 @ 0x007454f0 ====

void FUN_007454f0(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\x01') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009f09e8;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 8) = 1;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 1;
  }
  return;
}


// ==== FUN_00745530 @ 0x00745530 ====

void FUN_00745530(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 8) != '\0') {
    puVar1 = operator_new(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = &PTR_FUN_009f09fc;
      FUN_00797a20(puVar1);
      *(undefined1 *)(in_ECX + 8) = 0;
      return;
    }
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_00745570 @ 0x00745570 ====

void FUN_00745570(void)

{
  undefined4 uVar1;
  void *pvVar2;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5180004;
  *(undefined2 *)((int)pvVar2 + 6) = 0x10;
  uVar1 = FUN_004244d0();
  FUN_004d8570(uVar1);
  return;
}


// ==== FUN_007455b0 @ 0x007455b0 ====

void FUN_007455b0(undefined4 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  int iVar3;
  
  uVar1 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  pvVar2 = operator_new(0x400);
  *(undefined4 *)((int)pvVar2 + 8) = uVar1;
  *(undefined4 *)((int)pvVar2 + 0xc) = 0x5180005;
  *(undefined2 *)((int)pvVar2 + 6) = 0x14;
  iVar3 = FUN_004244d0();
  *(undefined4 *)(iVar3 + 0x10) = param_1;
  FUN_004d8570();
  return;
}


// ==== FUN_00745600 @ 0x00745600 ====

undefined4 FUN_00745600(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_statuswnd_009f08b0,0xe);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0xc))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_statuswnd_009f08c0,0xe);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x14))();
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_update_status_009f08d0,0xd);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x28))();
    return 1;
  }
  return 0;
}


// ==== FUN_00745690 @ 0x00745690 ====

undefined4 FUN_00745690(int *param_1)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    (**(code **)(*in_ECX + 4))(param_1);
  }
  else if (iVar2 == 0x70004) {
    cVar1 = FUN_00745600(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007456d0 @ 0x007456d0 ====

void FUN_007456d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_ESI;
  uint unaff_EDI;
  uint *_Memory;
  uint *puStack_5c;
  undefined1 auStack_46 [2];
  uint local_44;
  undefined1 local_40 [4];
  void *pvStack_3c;
  uint uStack_38;
  uint uStack_34;
  void *local_30;
  undefined4 local_2c;
  uint local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992f03;
  pvStack_c = ExceptionList;
  puVar1 = in_ECX + 1;
  ExceptionList = &pvStack_c;
  *puVar1 = &PTR_FUN_009ef7a4;
  local_4 = 1;
  *in_ECX = &PTR_FUN_009f0a30;
  *puVar1 = &PTR_FUN_009f0a24;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ae84 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ae84 = in_ECX;
  }
  puStack_5c = (uint *)0x0;
  *(undefined1 *)(in_ECX + 2) = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(&DAT_009f084e);
  puStack_5c = (uint *)0xe;
  local_4._0_1_ = 2;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40[0] = 0;
  FUN_00401740(s_show_statuswnd_009f0850);
  puStack_5c = &local_28;
  _Memory = &local_44;
  local_4 = CONCAT31(local_4._1_3_,3);
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
  FUN_00401740(&DAT_009f085f,0);
  local_10._0_1_ = 4;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740(s_hide_statuswnd_009f0860,0xe);
  local_10 = CONCAT31(local_10._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_46 + -10,0,&uStack_34);
  if (0xf < local_44) {
    _free(unaff_ESI);
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
  FUN_00401740(&DAT_009f086f,0);
  uStack_1c._0_1_ = 6;
  local_44 = 0xf;
  FUN_00401740(s_update_status_009f0870,0xd);
  uStack_1c = CONCAT31(uStack_1c._1_3_,7);
  (**(code **)(*DAT_00b5a6c8 + 8))(&puStack_5c,0,local_40);
  if (0xf < unaff_EDI) {
    _free(_Memory);
    return;
  }
  if (uStack_34 < 0x10) {
    in_ECX[3] = 0;
    ExceptionList = local_30;
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_007458f0 @ 0x007458f0 ====

void FUN_007458f0(void)

{
  undefined4 *in_ECX;
  void *pvStack_30;
  undefined4 *local_2c;
  void *local_28;
  undefined1 local_24;
  uint uStack_1c;
  void *pvStack_18;
  uint local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00992f54;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f0a30;
  in_ECX[1] = &PTR_FUN_009f0a24;
  local_4 = 1;
  DAT_00b5ae84 = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_statuswnd_009f0880,0xe);
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
  FUN_00401740(s_hide_statuswnd_009f0890,0xe);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  pvStack_c._0_1_ = 1;
  if (0xf < pvStack_18) {
    _free(local_2c);
    return;
  }
  pvStack_18 = (void *)0xf;
  uStack_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffffff00);
  FUN_00401740(s_update_status_009f08a0,0xd);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&pvStack_30);
  if (uStack_1c < 0x10) {
    in_ECX[1] = &PTR_FUN_009ef7a4;
    *in_ECX = &PTR_FUN_009f09bc;
    ExceptionList = pvStack_18;
    return;
  }
  _free(pvStack_30);
  return;
}


// ==== FUN_00745a30 @ 0x00745a30 ====

void FUN_00745a30(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int iVar8;
  int in_ECX;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992f66;
  local_c = ExceptionList;
  if ((999 < (uint)(param_1 - *(int *)(in_ECX + 0xc))) && (DAT_00b5acd8 != (int *)0x0)) {
    ExceptionList = &local_c;
    piVar4 = (int *)(**(code **)(*DAT_00b5a6fc + 8))();
    piVar5 = (int *)(**(code **)(*piVar4 + 8))();
    while (piVar5 != (int *)0x0) {
      piVar6 = (int *)(**(code **)(**(int **)(*piVar5 + 4) + 0xc))();
      puVar7 = (undefined4 *)(**(code **)(*piVar6 + 4))();
      uVar1 = *puVar7;
      piVar6 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(uVar1);
      if (piVar6 == (int *)0x0) {
        piVar5 = (int *)(**(code **)(*piVar4 + 0x48))(piVar5);
      }
      else {
        piVar6 = (int *)(**(code **)(*piVar6 + 0x14))();
        iVar8 = (**(code **)(*piVar6 + 0x24))();
        if (iVar8 == 0) {
          ExceptionList = local_c;
          return;
        }
        if (*(int **)(iVar8 + 0x14) == (int *)0x0) {
          uStack_10 = 0xf;
          uStack_14 = 0;
          pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
          FUN_00401740(s_pList____NULL_009f0900,0xd);
          uStack_4 = 0;
          FUN_00406880(auStack_28);
          uStack_4 = 0xffffffff;
          if (uStack_10 < 0x10) {
            uStack_10 = 0xf;
            uStack_14 = 0;
            pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
            pcVar2 = (code *)swi(3);
            (*pcVar2)();
            return;
          }
          _free(pvStack_24);
          return;
        }
        cVar3 = (**(code **)(**(int **)(iVar8 + 0x14) + 0x14))();
        if (cVar3 != '\0') {
          FUN_007455b0(uVar1);
        }
        piVar5 = (int *)(**(code **)(*piVar4 + 0x48))(piVar5);
      }
    }
    *(int *)(in_ECX + 0xc) = param_1;
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00745b90 @ 0x00745b90 ====

void FUN_00745b90(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
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
  puStack_8 = &LAB_00992f80;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f0910,0xb);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  piVar1 = *(int **)(iVar3 + 0x10);
  if (piVar1 == (int *)0x0) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(s_pBufferList____NULL_009f091c,0x13);
    uStack_4 = 1;
    FUN_00406880(auStack_44);
    uStack_4 = 0xffffffff;
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
  piVar4 = (int *)(**(code **)(*piVar1 + 0x18))();
  while (piVar4 != (int *)0x0) {
    piVar4 = (int *)(**(code **)(*piVar4 + 0xc))();
    iVar5 = (**(code **)(*piVar4 + 4))();
    FUN_004dd320(0x13,*(undefined1 *)(iVar5 + 0x102),0,3,0,0);
    piVar4 = (int *)(**(code **)(*piVar1 + 0x1c))();
  }
  FUN_00828b80(iVar3);
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00745cd0 @ 0x00745cd0 ====

void FUN_00745cd0(undefined4 param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  int *piStack_30;
  uint uStack_2c;
  undefined1 auStack_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992f9a;
  local_c = ExceptionList;
  if (DAT_00b5acd8 != (int *)0x0) {
    ExceptionList = &local_c;
    piStack_30 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_1);
    if (piStack_30 == (int *)0x0) {
      uStack_2c = 0xf;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      FUN_00401740(s_InitMonsterStatus__Can_t_find_ac_009f0930,0x23);
      uStack_4 = 0;
      FUN_00796d50(auStack_44);
      if (0xf < uStack_2c) {
        _free(pvStack_40);
        return;
      }
    }
    else {
      piVar2 = (int *)(**(code **)(*piStack_30 + 0x14))();
      iVar3 = (**(code **)(*piVar2 + 0x24))();
      if (iVar3 != 0) {
        piVar2 = *(int **)(iVar3 + 0x14);
        if (piVar2 == (int *)0x0) {
          FUN_00401830(s_pList____NULL_009f0954);
          uStack_4 = 1;
          FUN_00406880(auStack_28);
          uStack_4 = 0xffffffff;
                    /* WARNING: Subroutine does not return */
          FUN_00446f10();
        }
        cVar1 = (**(code **)(*piVar2 + 0x14))();
        if (cVar1 != '\0') {
          cVar1 = (**(code **)(*piVar2 + 0x18))();
          while (cVar1 != '\0') {
            FUN_004dd320(0x13,cVar1,0,3,param_1,0);
            cVar1 = (**(code **)(*piVar2 + 0x1c))();
          }
          (**(code **)(*piVar2 + 0x2c))();
        }
      }
    }
  }
  ExceptionList = local_c;
  return;
}


// ==== FUN_00745e10 @ 0x00745e10 ====

uint FUN_00745e10(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  uint extraout_EAX;
  uint uVar4;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *local_c;
  undefined1 *puStack_8;
  int *piStack_4;
  
  piStack_4 = (int *)0xffffffff;
  puStack_8 = &LAB_00992fac;
  local_c = ExceptionList;
  if (DAT_00b5a97c != 0) {
    ExceptionList = &local_c;
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar3 != 0) {
      piVar1 = *(int **)(iVar3 + 0x10);
      if (piVar1 != (int *)0x0) {
        iVar3 = (**(code **)(*piVar1 + 0x18))();
        ExceptionList = local_c;
        return (uint)(iVar3 != 0);
      }
      FUN_00401830(s_pList____NULL_009f0964);
      piStack_4 = piVar1;
      FUN_00406880(auStack_28);
      piStack_4 = (int *)0xffffffff;
      if (uStack_10 < 0x10) {
        uStack_10 = 0xf;
        uStack_14 = 0;
        pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
        pcVar2 = (code *)swi(3);
        uVar4 = (*pcVar2)();
        return uVar4;
      }
      _free(pvStack_24);
      return extraout_EAX;
    }
  }
  ExceptionList = local_c;
  return 0;
}


// ==== FUN_00745ed0 @ 0x00745ed0 ====

uint FUN_00745ed0(void)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  uint extraout_EAX;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992fbe;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    ExceptionList = pvStack_c;
    return 0;
  }
  if (*(int **)(iVar3 + 0x10) == (int *)0x0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pList____NULL_009f0974,0xd);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      uStack_10 = 0xf;
      uStack_14 = 0;
      pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
    _free(pvStack_24);
    return extraout_EAX;
  }
  piVar5 = (int *)(**(code **)(**(int **)(iVar3 + 0x10) + 0x18))();
  if (piVar5 == (int *)0x0) {
    ExceptionList = pvStack_c;
    return 0;
  }
  piVar5 = (int *)(**(code **)(*piVar5 + 0xc))();
  iVar3 = (**(code **)(*piVar5 + 4))();
  pcVar6 = (char *)(iVar3 + 2);
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar3 + 2),(int)pcVar6 - (iVar3 + 3));
  iVar3 = (**(code **)(*piVar5 + 4))();
  ExceptionList = pvStack_c;
  return (uint)*(byte *)(iVar3 + 0x102);
}


// ==== FUN_00745ff0 @ 0x00745ff0 ====

uint FUN_00745ff0(void)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  uint extraout_EAX;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00992fd0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    ExceptionList = pvStack_c;
    return 0;
  }
  if (*(int **)(iVar3 + 0x10) == (int *)0x0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pList____NULL_009f0984,0xd);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      uStack_10 = 0xf;
      uStack_14 = 0;
      pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      pcVar2 = (code *)swi(3);
      uVar4 = (*pcVar2)();
      return uVar4;
    }
    _free(pvStack_24);
    return extraout_EAX;
  }
  piVar5 = (int *)(**(code **)(**(int **)(iVar3 + 0x10) + 0x1c))();
  if (piVar5 == (int *)0x0) {
    ExceptionList = pvStack_c;
    return 0;
  }
  piVar5 = (int *)(**(code **)(*piVar5 + 0xc))();
  iVar3 = (**(code **)(*piVar5 + 4))();
  pcVar6 = (char *)(iVar3 + 2);
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar3 + 2),(int)pcVar6 - (iVar3 + 3));
  iVar3 = (**(code **)(*piVar5 + 4))();
  ExceptionList = pvStack_c;
  return (uint)*(byte *)(iVar3 + 0x102);
}


// ==== FUN_00746110 @ 0x00746110 ====

void FUN_00746110(int param_1)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
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
  puStack_8 = &LAB_00992fea;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00745a30(*(undefined4 *)(param_1 + 0xc));
  cVar2 = (**(code **)(*in_ECX + 0x2c))();
  if (cVar2 != '\0') {
    iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
    if (iVar3 == 0) {
      uStack_10 = 0xf;
      uStack_14 = 0;
      pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
      FUN_00401740(s_pPC____NULL_009f08e0,0xb);
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
    if (*(int **)(iVar3 + 0x10) == (int *)0x0) {
      uStack_2c = 0xf;
      uStack_30 = 0;
      pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
      FUN_00401740(s_pBufferList____NULL_009f08ec,0x13);
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
    iVar3 = **(int **)(iVar3 + 0x10);
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    iVar3 = (**(code **)(iVar3 + 0x2c))(uVar4);
    if (iVar3 != 0) {
      (**(code **)(*in_ECX + 0x28))();
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00746250 @ 0x00746250 ====

void FUN_00746250(void)

{
  FUN_00746270();
  return;
}


// ==== FUN_00746260 @ 0x00746260 ====

void FUN_00746260(void)

{
  FUN_007454c0();
  return;
}


// ==== FUN_00746270 @ 0x00746270 ====

void FUN_00746270(byte param_1)

{
  void *in_ECX;
  
  FUN_007458f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00746290 @ 0x00746290 ====

void FUN_00746290(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0b1c;
  return;
}


// ==== FUN_007462a0 @ 0x007462a0 ====

void FUN_007462a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0b1c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007462d0 @ 0x007462d0 ====

void FUN_007462d0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  puVar2 = operator_new(0xc);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = &PTR_FUN_009f0b2c;
  }
  uVar1 = *(undefined4 *)(param_1 + 0x14);
  puVar2[1] = (uint)*(byte *)(param_1 + 0x18);
  puVar2[2] = uVar1;
  FUN_00797a20(puVar2);
  return;
}


// ==== __break @ 0x00746365 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== __break @ 0x00746369 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00746390 @ 0x00746390 ====

void FUN_00746390(void)

{
  int unaff_retaddr;
  
  (**(code **)(*DAT_00b5af2c + 8))(2);
  if (*(int *)(unaff_retaddr + 0x10) == 0) {
    (**(code **)(*DAT_00b5aea0 + 8))();
    (**(code **)(*DAT_00b5a78c + 0x6c))();
    (**(code **)(*DAT_00b5b11c + 0x24))();
  }
  return;
}


// ==== FUN_007463d0 @ 0x007463d0 ====

undefined4 FUN_007463d0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_resetstat_009f0adc,0xe);
  if (iVar1 == 0) {
    puVar2 = operator_new(0xc);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = &PTR_FUN_009f0b2c;
    }
    puVar2[1] = 9;
    puVar2[2] = 999;
    FUN_00797a20(puVar2);
    return 1;
  }
  iVar1 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_resetstat_009f0aec,0xe);
  if (iVar1 != 0) {
    return 0;
  }
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return 1;
  }
  *puVar2 = &PTR_FUN_009d8b98;
  FUN_00797a20(puVar2);
  return 1;
}


// ==== FUN_00746480 @ 0x00746480 ====

void FUN_00746480(void)

{
  undefined4 *in_ECX;
  void *unaff_ESI;
  undefined1 auStack_2a [2];
  undefined1 local_28 [4];
  undefined1 local_24;
  uint uStack_20;
  void *pvStack_1c;
  uint uStack_18;
  undefined4 local_14;
  undefined4 local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993018;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f0b40;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ae9c = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ae9c = in_ECX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740(s_show_resetstat_009f0a9c,0xe);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(local_28,0);
  pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
  if (0xf < uStack_18) {
    _free(in_ECX);
    return;
  }
  uStack_18 = 0xf;
  pvStack_1c = (void *)0x0;
  FUN_00401740(s_hide_resetstat_009f0aac,0xe);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0xc))(auStack_2a + -6,0);
  if (uStack_20 < 0x10) {
    ExceptionList = pvStack_1c;
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== __break @ 0x0074656e ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00746570 @ 0x00746570 ====

void FUN_00746570(void)

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
  
  puStack_8 = &LAB_0099303a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f0b40;
  local_4 = 0;
  DAT_00b5ae9c = 0;
  local_10 = 0xf;
  local_14 = (void *)0x0;
  local_24 = 0;
  local_2c = in_ECX;
  FUN_00401740(s_show_resetstat_009f0abc,0xe);
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
  FUN_00401740(s_hide_resetstat_009f0acc,0xe);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  if (uStack_18 < 0x10) {
    *in_ECX = &PTR_FUN_009f0b1c;
    ExceptionList = local_14;
    return;
  }
  _free(local_2c);
  return;
}


// ==== FUN_00746650 @ 0x00746650 ====

/* WARNING: Removing unreachable block (ram,0x0074675e) */

void FUN_00746650(int param_1)

{
  undefined1 auStack_4c [12];
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 *puVar1;
  uint uStack_18;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  puStack_8 = &LAB_0099304c;
  local_c = ExceptionList;
  local_4 = (undefined1 *)0x0;
  switch(*(undefined1 *)(param_1 + 0x14)) {
  case 0:
    puVar1 = (undefined1 *)0x3c0025;
    uStack_30 = 0;
    uStack_34 = 0x7466af;
    ExceptionList = &local_c;
    uStack_3c = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_34 = 0xffffffff;
    uStack_38 = 0;
    uStack_40 = 0x7466bd;
    FUN_00401660();
    if (uStack_18 < 0x10) {
      puVar1 = auStack_4c + 0x20;
    }
    local_4 = auStack_4c;
    FUN_00401830(puVar1);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    (**(code **)(*DAT_00b5a980 + 8))();
    uStack_30 = 0x7466f9;
    FUN_00828c40();
    ExceptionList = local_c;
    return;
  case 1:
    puVar1 = (undefined1 *)0x3c0020;
    break;
  case 2:
  case 4:
  case 5:
    puVar1 = (undefined1 *)0x3c0022;
    break;
  case 3:
    puVar1 = (undefined1 *)0x3c0024;
    break;
  default:
    goto switchD_00746696_default;
  }
  uStack_30 = 0;
  uStack_34 = 0x74671e;
  ExceptionList = &local_c;
  uStack_3c = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_34 = 0xffffffff;
  uStack_38 = 0;
  uStack_40 = 0x74672c;
  FUN_00401660();
  if (uStack_18 < 0x10) {
    puVar1 = auStack_4c + 0x20;
  }
  local_4 = auStack_4c;
  FUN_00401830(puVar1);
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
switchD_00746696_default:
  ExceptionList = local_c;
  return;
}


// ==== FUN_007467a0 @ 0x007467a0 ====

void FUN_007467a0(void)

{
  undefined1 auStack_54 [4];
  void *pvStack_50;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  uint uStack_3c;
  void *pvStack_38;
  undefined4 uStack_34;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_0099305e;
  pvStack_c = ExceptionList;
  uStack_34 = 0x280027;
  pvStack_38 = (void *)0x0;
  uStack_3c = 0x7467cd;
  ExceptionList = &pvStack_c;
  uStack_44 = (**(code **)(*DAT_00b5a794 + 0xc))();
  uStack_3c = 0xffffffff;
  uStack_40 = 0;
  uStack_48 = 0x7467ea;
  FUN_00401660();
  pvStack_c = (void *)0x0;
  puStack_4 = auStack_54;
  FUN_00401740(&DAT_009f0afc,4);
  FUN_00404230(puStack_4);
  (**(code **)(*DAT_00b5ad0c + 0x28))();
  (**(code **)(*DAT_00b5ad1c + 0x90))();
  if (uStack_3c < 0x10) {
    ExceptionList = pvStack_38;
    return;
  }
  _free(pvStack_50);
  return;
}


// ==== FUN_00746890 @ 0x00746890 ====

void FUN_00746890(void)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  char *****pppppcVar4;
  int *piVar5;
  void *pvVar6;
  char *****apppppcStack_2c [2];
  void *local_24;
  uint uStack_18;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993070;
  pvStack_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_4 = 0;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  cVar1 = (**(code **)(**(int **)(iVar3 + 0x24) + 0x6c))();
  if (cVar1 == '\0') {
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    if (uStack_18 < 0x10) {
      apppppcStack_2c[0] = (char *****)apppppcStack_2c;
    }
    pppppcVar4 = apppppcStack_2c[0];
    do {
      cVar1 = *(char *)pppppcVar4;
      pppppcVar4 = (char *****)((int)pppppcVar4 + 1);
    } while (cVar1 != '\0');
    FUN_00401740(apppppcStack_2c[0],(int)pppppcVar4 - (int)((int)apppppcStack_2c[0] + 1));
  }
  else {
    if (*(int **)(iVar3 + 0xc) == (int *)0x0) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = (int *)(**(code **)(**(int **)(iVar3 + 0xc) + 0x28))();
    }
    bVar2 = (**(code **)(*piVar5 + 0x2c))();
    if (bVar2 < 2) {
      pvVar6 = operator_new(0x400);
      *(undefined4 *)((int)pvVar6 + 8) = 0;
      *(undefined4 *)((int)pvVar6 + 0xc) = 0x506000d;
      *(undefined2 *)((int)pvVar6 + 6) = 0x10;
      FUN_004244d0();
      FUN_004d8570();
      goto joined_r0x007469e4;
    }
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    if (uStack_18 < 0x10) {
      apppppcStack_2c[0] = (char *****)apppppcStack_2c;
    }
    FUN_00401830(apppppcStack_2c[0]);
  }
  (**(code **)(*DAT_00b5ad0c + 0x28))(2);
joined_r0x007469e4:
  if (local_10 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_00746a10 @ 0x00746a10 ====

undefined4 FUN_00746a10(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = FUN_00424500();
  if (uVar2 < 0x5060013) {
    if (uVar2 == 0x5060012) {
      iVar1 = *(int *)(param_1 + 0xc);
      (**(code **)(*DAT_00b5af2c + 8))(2);
      if (*(char *)(iVar1 + 0x10) == '\0') {
        (**(code **)(*DAT_00b5aea0 + 0xc))();
        return 1;
      }
      return 1;
    }
    if (uVar2 == 0x5060003) {
      FUN_00746390(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar2 == 0x506000c) {
      FUN_007462d0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
    if (uVar2 == 0x506000e) {
      FUN_00746650(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  else {
    if (uVar2 == 0x5060016) {
      iVar1 = *(int *)(param_1 + 0xc);
      iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
      if (iVar3 == 0) {
        return 1;
      }
      FUN_00828c10(iVar3,*(undefined4 *)(iVar1 + 0x10));
      return 1;
    }
    if (uVar2 == 0x509000e) {
      FUN_007467a0(*(undefined4 *)(param_1 + 0xc));
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00746af0 @ 0x00746af0 ====

undefined4 FUN_00746af0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x50011) {
    cVar1 = FUN_00746a10(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  else if (iVar2 == 0x70004) {
    cVar1 = FUN_007463d0(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00746b40 @ 0x00746b40 ====

undefined4 FUN_00746b40(void)

{
  return 0x70130003;
}


// ==== FUN_00746b50 @ 0x00746b50 ====

void FUN_00746b50(byte param_1)

{
  void *in_ECX;
  
  FUN_00746570();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00746b70 @ 0x00746b70 ====

void FUN_00746b70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0c24;
  return;
}


// ==== FUN_00746b80 @ 0x00746b80 ====

void FUN_00746b80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0c24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00746ba0 @ 0x00746ba0 ====

undefined1 FUN_00746ba0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 4);
}


// ==== FUN_00746bc0 @ 0x00746bc0 ====

undefined4 FUN_00746bc0(void)

{
  char cVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  cVar1 = (**(code **)(*DAT_00b5af2c + 0xc))(2);
  if (cVar1 != '\0') {
    return 0;
  }
  puVar2 = operator_new(4);
  if (puVar2 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 0;
    return 1;
  }
  *puVar2 = &PTR_FUN_009f0c64;
  FUN_00797a20(puVar2);
  *(undefined1 *)(in_ECX + 4) = 0;
  return 1;
}


// ==== FUN_00746c10 @ 0x00746c10 ====

void FUN_00746c10(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = operator_new(4);
  if (puVar1 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    *(undefined1 *)(in_ECX + 4) = 1;
    return;
  }
  *puVar1 = &PTR_FUN_009f0c50;
  FUN_00797a20(puVar1);
  *(undefined1 *)(in_ECX + 4) = 1;
  return;
}


// ==== FUN_00746c70 @ 0x00746c70 ====

void FUN_00746c70(void)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  psVar2 = (short *)(**(code **)(**(int **)(iVar1 + 0xc) + 0x14))();
  if (*psVar2 != 0) {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5060002;
    *(undefined2 *)((int)pvVar4 + 6) = 0x14;
    iVar1 = FUN_004244d0();
    *(undefined4 *)(iVar1 + 0x10) = 0;
    FUN_004d8570(iVar1);
    (**(code **)(*DAT_00b5af2c + 8))(2);
    (**(code **)(*DAT_00b5aea0 + 4))(0);
  }
  return;
}


// ==== FUN_00746cf0 @ 0x00746cf0 ====

void FUN_00746cf0(void)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  psVar2 = (short *)(**(code **)(**(int **)(iVar1 + 0xc) + 0x14))();
  if (*psVar2 != 0) {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5060002;
    *(undefined2 *)((int)pvVar4 + 6) = 0x14;
    iVar1 = FUN_004244d0();
    *(undefined4 *)(iVar1 + 0x10) = 1;
    FUN_004d8570(iVar1);
    (**(code **)(*DAT_00b5af2c + 8))(2);
    (**(code **)(*DAT_00b5aea0 + 4))(1);
  }
  return;
}


// ==== FUN_00746d70 @ 0x00746d70 ====

void FUN_00746d70(void)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  psVar2 = (short *)(**(code **)(**(int **)(iVar1 + 0xc) + 0x14))();
  if (*psVar2 != 0) {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5060002;
    *(undefined2 *)((int)pvVar4 + 6) = 0x14;
    iVar1 = FUN_004244d0();
    *(undefined4 *)(iVar1 + 0x10) = 2;
    FUN_004d8570(iVar1);
    (**(code **)(*DAT_00b5af2c + 8))(2);
    (**(code **)(*DAT_00b5aea0 + 4))(2);
  }
  return;
}


// ==== FUN_00746df0 @ 0x00746df0 ====

void FUN_00746df0(void)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  psVar2 = (short *)(**(code **)(**(int **)(iVar1 + 0xc) + 0x14))();
  if (*psVar2 != 0) {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5060002;
    *(undefined2 *)((int)pvVar4 + 6) = 0x14;
    iVar1 = FUN_004244d0();
    *(undefined4 *)(iVar1 + 0x10) = 3;
    FUN_004d8570(iVar1);
    (**(code **)(*DAT_00b5af2c + 8))(2);
    (**(code **)(*DAT_00b5aea0 + 4))(3);
  }
  return;
}


// ==== FUN_00746e70 @ 0x00746e70 ====

void FUN_00746e70(undefined2 param_1,undefined2 param_2,undefined2 param_3,undefined2 param_4)

{
  int iVar1;
  short *psVar2;
  undefined4 uVar3;
  void *pvVar4;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  psVar2 = (short *)(**(code **)(**(int **)(iVar1 + 0xc) + 0x14))();
  if (*psVar2 != 0) {
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    pvVar4 = operator_new(0x400);
    *(undefined4 *)((int)pvVar4 + 8) = uVar3;
    *(undefined4 *)((int)pvVar4 + 0xc) = 0x5060011;
    *(undefined2 *)((int)pvVar4 + 6) = 0x18;
    iVar1 = FUN_004244d0();
    *(undefined2 *)(iVar1 + 0x10) = param_1;
    *(undefined2 *)(iVar1 + 0x16) = param_2;
    *(undefined2 *)(iVar1 + 0x12) = param_3;
    *(undefined2 *)(iVar1 + 0x14) = param_4;
    FUN_004d8570(iVar1);
    (**(code **)(*DAT_00b5af2c + 8))(2);
  }
  return;
}


// ==== FUN_00746f00 @ 0x00746f00 ====

undefined4 FUN_00746f00(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_pcinfo_009f0bd4,0xb);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 8))();
    return 1;
  }
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_show_option_009f0be0,0xb);
  if (iVar2 == 0) {
    puVar3 = operator_new(4);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = &PTR_FUN_009e04a0;
      FUN_00797a20(puVar3);
      return 1;
    }
  }
  else {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_1 + 0x1c),s_hide_pcinfo_009f0bec,0xb);
    if (iVar2 == 0) {
      (**(code **)(*in_ECX + 4))();
      return 1;
    }
    cVar1 = FUN_004036a0(param_1 + 8,s_show_mp3_009f0bf8);
    if (cVar1 == '\0') {
      cVar1 = FUN_004036a0(param_1 + 8,s_hide_mp3_009f0c04);
      if (cVar1 == '\0') {
        return 0;
      }
      puVar3 = operator_new(4);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = &PTR_FUN_009b45dc;
        FUN_00797a20(puVar3);
        return 1;
      }
    }
    else {
      puVar3 = operator_new(4);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = &PTR_FUN_009b6224;
        FUN_00797a20(puVar3);
        return 1;
      }
    }
  }
  FUN_00797a20(0);
  return 1;
}


// ==== FUN_00747020 @ 0x00747020 ====

undefined4 FUN_00747020(int *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x70004) {
    cVar1 = FUN_00746f00(param_1);
    if (cVar1 != '\0') {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00747050 @ 0x00747050 ====

void FUN_00747050(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  uint unaff_EBP;
  void *unaff_EDI;
  undefined4 *_Memory;
  undefined1 auStack_6e [6];
  uint *puVar1;
  undefined4 uStack_5c;
  undefined1 auStack_46 [2];
  uint local_44;
  uint local_40;
  void *pvStack_3c;
  uint uStack_38;
  uint uStack_34;
  void *local_30;
  undefined4 local_2c;
  uint local_28;
  undefined1 local_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009930d8;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f0c78;
  *(undefined1 *)(in_ECX + 1) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ae98 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ae98 = in_ECX;
  }
  uStack_5c = (uint *)0x0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = 0;
  FUN_00401740();
  uStack_5c = (uint *)0xb;
  local_4._0_1_ = 1;
  local_2c = 0xf;
  local_30 = (void *)0x0;
  local_40 = local_40 & 0xffffff00;
  FUN_00401740();
  uStack_5c = &local_28;
  local_4 = CONCAT31(local_4._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 8))();
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
  FUN_00401740();
  local_10._0_1_ = 3;
  uStack_38 = 0xf;
  pvStack_3c = (void *)0x0;
  FUN_00401740();
  puVar1 = &uStack_34;
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 8))();
  if (0xf < local_44) {
    _free(unaff_EDI);
    return;
  }
  local_44 = 0xf;
  uStack_1c = uStack_1c & 0xffffff00;
  if (0xf < local_28) {
    _free(pvStack_3c);
    return;
  }
  local_28 = 0xf;
  local_2c = 0;
  pvStack_3c = (void *)((uint)pvStack_3c & 0xffffff00);
  FUN_00401740(&DAT_009f0b6c);
  uStack_1c._0_1_ = 5;
  local_44 = 0xf;
  FUN_00401740(s_show_option_009f0b70);
  _Memory = &uStack_5c;
  uStack_1c = CONCAT31(uStack_1c._1_3_,6);
  (**(code **)(*DAT_00b5a6c8 + 8))(_Memory,0);
  if (0xf < unaff_EBP) {
    _free(&local_44);
    return;
  }
  local_28 = local_28 & 0xffffff00;
  if (0xf < uStack_34) {
    _free((void *)0x0);
    return;
  }
  uStack_34 = 0xf;
  uStack_38 = 0;
  FUN_00401740(&DAT_009f0b7c,0);
  local_28._0_1_ = 7;
  FUN_00401740(s_show_mp3_009f0b80,8);
  local_28 = CONCAT31(local_28._1_3_,8);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_6e + 6,0,auStack_46 + -6);
  if ((uint *)0xf < uStack_5c) {
    _free(auStack_46 + -10);
    return;
  }
  uStack_5c = (uint *)0xf;
  uStack_34 = uStack_34 & 0xffffff00;
  if (0xf < local_40) {
    _free((void *)0x0);
    return;
  }
  local_40 = 0xf;
  local_44 = 0;
  FUN_00401740(&DAT_009f0b89,0);
  uStack_34._0_1_ = 9;
  uStack_5c = (uint *)0xf;
  FUN_00401740(s_hide_mp3_009f0b8c,8);
  uStack_34 = CONCAT31(uStack_34._1_3_,10);
  (**(code **)(*DAT_00b5a6c8 + 8))(auStack_6e + -6,0,auStack_6e + 0x16);
  if ((uint *)0xf < puVar1) {
    _free(_Memory);
    return;
  }
  if (((uint)unaff_EBX & 0xffffff00) < 0x10) {
    ExceptionList = (void *)0x0;
    return;
  }
  _free((void *)0x0);
  return;
}


// ==== FUN_00747380 @ 0x00747380 ====

void FUN_00747380(void)

{
  undefined4 *in_ECX;
  void *unaff_EBX;
  void *unaff_EBP;
  void *unaff_ESI;
  undefined4 local_2c;
  void *local_28;
  uint local_24;
  void *pvStack_20;
  uint uStack_1c;
  uint uStack_18;
  uint local_14;
  uint local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993112;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f0c78;
  local_4 = 0;
  DAT_00b5ae98 = 0;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = local_24 & 0xffffff00;
  local_2c = in_ECX;
  FUN_00401740(s_show_pcinfo_009f0b98,0xb);
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_28);
  puStack_8 = (undefined1 *)((uint)puStack_8 & 0xffffff00);
  if (0xf < local_14) {
    _free(local_28);
    return;
  }
  local_14 = 0xf;
  uStack_18 = 0;
  local_28 = (void *)((uint)local_28 & 0xffffff00);
  FUN_00401740(s_hide_pcinfo_009f0ba4,0xb);
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,2);
  (**(code **)(*DAT_00b5a6c8 + 0x10))(&local_2c);
  pvStack_c = (void *)((uint)pvStack_c & 0xffffff00);
  if (0xf < uStack_18) {
    _free(local_2c);
    return;
  }
  uStack_18 = 0xf;
  uStack_1c = 0;
  local_2c = (undefined4 *)((uint)local_2c & 0xffffff00);
  FUN_00401740(s_show_option_009f0bb0,0xb);
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,3);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x30);
  local_10 = local_10 & 0xffffff00;
  if (0xf < uStack_1c) {
    _free(unaff_EBX);
    return;
  }
  uStack_1c = 0xf;
  pvStack_20 = (void *)0x0;
  FUN_00401740(s_show_mp3_009f0bbc,8);
  local_10 = CONCAT31(local_10._1_3_,4);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x34);
  local_14 = local_14 & 0xffffff00;
  if (0xf < pvStack_20) {
    _free(unaff_EBP);
    return;
  }
  pvStack_20 = (void *)0xf;
  local_24 = 0;
  FUN_00401740(s_hide_mp3_009f0bc8,8);
  local_14 = CONCAT31(local_14._1_3_,5);
  (**(code **)(*DAT_00b5a6c8 + 0x10))((int)register0x00000010 + -0x38);
  if (local_24 < 0x10) {
    *in_ECX = &PTR_FUN_009f0c24;
    ExceptionList = pvStack_20;
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_00747540 @ 0x00747540 ====

undefined4 FUN_00747540(void)

{
  return 0x70130000;
}


// ==== __break @ 0x0074754f ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00747550 @ 0x00747550 ====

undefined4 FUN_00747550(void)

{
  return 0x70130001;
}


// ==== FUN_00747560 @ 0x00747560 ====

void FUN_00747560(byte param_1)

{
  void *in_ECX;
  
  FUN_0073e550();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00747580 @ 0x00747580 ====

void FUN_00747580(byte param_1)

{
  void *in_ECX;
  
  FUN_00747380();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007475a0 @ 0x007475a0 ====

void FUN_007475a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0d18;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007475c0 @ 0x007475c0 ====

void FUN_007475c0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_007475d0 @ 0x007475d0 ====

void FUN_007475d0(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x3c);
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== FUN_007475f0 @ 0x007475f0 ====

void FUN_007475f0(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 8);
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== FUN_00747610 @ 0x00747610 ====

int FUN_00747610(void)

{
  undefined4 in_EAX;
  int in_ECX;
  
  return CONCAT22((short)((uint)in_EAX >> 0x10),*(undefined2 *)(in_ECX + 0x3e)) -
         CONCAT22((short)((uint)in_ECX >> 0x10),*(undefined2 *)(in_ECX + 10));
}


// ==== FUN_00747620 @ 0x00747620 ====

int FUN_00747620(void)

{
  undefined4 in_EAX;
  int in_ECX;
  
  return CONCAT22((short)((uint)in_EAX >> 0x10),*(undefined2 *)(in_ECX + 0x44)) -
         CONCAT22((short)((uint)in_ECX >> 0x10),*(undefined2 *)(in_ECX + 0x10));
}


// ==== FUN_00747630 @ 0x00747630 ====

int FUN_00747630(void)

{
  undefined4 in_EAX;
  int in_ECX;
  
  return CONCAT22((short)((uint)in_EAX >> 0x10),*(undefined2 *)(in_ECX + 0x40)) -
         CONCAT22((short)((uint)in_ECX >> 0x10),*(undefined2 *)(in_ECX + 0xc));
}


// ==== FUN_00747640 @ 0x00747640 ====

int FUN_00747640(void)

{
  undefined4 in_EAX;
  int in_ECX;
  
  return CONCAT22((short)((uint)in_EAX >> 0x10),*(undefined2 *)(in_ECX + 0x42)) -
         CONCAT22((short)((uint)in_ECX >> 0x10),*(undefined2 *)(in_ECX + 0xe));
}


// ==== FUN_00747650 @ 0x00747650 ====

void FUN_00747650(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0d64;
  *(undefined2 *)(in_ECX + 2) = 0;
  *(undefined2 *)((int)in_ECX + 10) = 0;
  *(undefined2 *)(in_ECX + 3) = 0;
  *(undefined2 *)((int)in_ECX + 0xe) = 0;
  *(undefined2 *)(in_ECX + 4) = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  *(undefined2 *)(in_ECX + 0xb) = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  *(undefined2 *)(in_ECX + 0xf) = 0;
  *(undefined2 *)((int)in_ECX + 0x3e) = 0;
  *(undefined2 *)(in_ECX + 0x10) = 0;
  *(undefined2 *)((int)in_ECX + 0x42) = 0;
  *(undefined2 *)(in_ECX + 0x11) = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  *(undefined2 *)(in_ECX + 0x18) = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5aea0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aea0 = in_ECX;
  return;
}


// ==== FUN_007476e0 @ 0x007476e0 ====

void FUN_007476e0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aea0 = 0;
  *in_ECX = &PTR_FUN_009f0d18;
  return;
}


// ==== FUN_00747700 @ 0x00747700 ====

void FUN_00747700(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  short *psVar4;
  int in_ECX;
  undefined1 auStack_164 [36];
  void *pvStack_128;
  uint uStack_114;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099312b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar1 = *(int **)(iVar2 + 0xc);
  piVar3 = (int *)(**(code **)(*piVar1 + 0x24))();
  psVar4 = (short *)(**(code **)(*piVar1 + 0x14))();
  if (*psVar4 == 0) {
    FUN_0044a580();
    FUN_00797b80();
  }
  else {
    switch(*(undefined4 *)(in_ECX + 4)) {
    case 0:
      iVar2 = *piVar3;
      (**(code **)(iVar2 + 0xc))();
      (**(code **)(iVar2 + 0x14))();
      break;
    case 1:
      iVar2 = *piVar3;
      (**(code **)(iVar2 + 0xc))();
      (**(code **)(iVar2 + 0x18))();
      break;
    case 2:
      iVar2 = *piVar3;
      (**(code **)(iVar2 + 0xc))();
      (**(code **)(iVar2 + 0x1c))();
      break;
    case 3:
      iVar2 = *piVar3;
      (**(code **)(iVar2 + 0xc))();
      (**(code **)(iVar2 + 0x20))();
    }
    iVar2 = *piVar1;
    (**(code **)(iVar2 + 0x14))();
    (**(code **)(iVar2 + 0x18))();
    (**(code **)(*DAT_00b5a794 + 0xc))();
    FUN_00401660();
    FUN_00401660(auStack_164 + 0x2c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_114) {
      _free(pvStack_128);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00747890 @ 0x00747890 ====

void FUN_00747890(void)

{
  short sVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  short *psVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 *puVar10;
  int *in_ECX;
  int unaff_EBP;
  int unaff_ESI;
  int unaff_EDI;
  undefined1 auStack_78 [4];
  undefined1 uStack_74;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined1 *puStack_4c;
  undefined4 uStack_48;
  uint uStack_44;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099313d;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar4 = (**(code **)(*DAT_00b5ac1c + 0x14))();
  if (iVar4 != 0) {
    piVar2 = *(int **)(iVar4 + 0xc);
    piVar5 = (int *)(**(code **)(*piVar2 + 0x24))();
    iVar4 = **(int **)(iVar4 + 0x50);
    (**(code **)(*DAT_00b5a6ac + 0x20))();
    uStack_44 = 0x7478ec;
    piVar6 = (int *)(**(code **)(iVar4 + 0x14))();
    uStack_44 = 0x7478f3;
    psVar7 = (short *)(**(code **)(*piVar6 + 0x14))();
    iVar4 = *piVar5;
    uStack_44 = 0x747900;
    uVar8 = (**(code **)(*in_ECX + 0x20))();
    uStack_44 = CONCAT22((short)((uint)uVar8 >> 0x10),(short)uVar8 + *psVar7);
    uStack_48 = 0x74790d;
    (**(code **)(iVar4 + 0x14))();
    iVar4 = *piVar5;
    uStack_48 = 0x747916;
    uVar8 = (**(code **)(*in_ECX + 0x28))();
    uStack_48 = CONCAT22((short)((uint)uVar8 >> 0x10),(short)uVar8 + *(short *)(unaff_EBP + 2));
    puStack_4c = (undefined1 *)0x747924;
    (**(code **)(iVar4 + 0x18))();
    iVar4 = *piVar5;
    puStack_4c = (undefined1 *)0x74792d;
    uVar8 = (**(code **)(*in_ECX + 0x2c))();
    puStack_4c = (undefined1 *)
                 CONCAT22((short)((uint)uVar8 >> 0x10),(short)uVar8 + *(short *)(unaff_ESI + 4));
    uStack_50 = 0x74793b;
    (**(code **)(iVar4 + 0x1c))();
    iVar4 = *piVar5;
    uStack_50 = 0x747944;
    uVar8 = (**(code **)(*in_ECX + 0x24))();
    uStack_50 = CONCAT22((short)((uint)uVar8 >> 0x10),(short)uVar8 + *(short *)(unaff_EDI + 6));
    iStack_54 = 0x747952;
    (**(code **)(iVar4 + 0x20))();
    iStack_54 = 0x74795a;
    psVar7 = (short *)(**(code **)(*piVar2 + 0x14))();
    iStack_54 = 0x747963;
    sVar3 = (**(code **)(*in_ECX + 0x20))();
    sVar1 = *psVar7;
    iStack_54 = 0x747970;
    iVar4 = (**(code **)(*in_ECX + 0x2c))();
    iStack_54 = 0x747979;
    iVar9 = (**(code **)(*in_ECX + 0x28))();
    iStack_54 = 0x747982;
    iStack_54 = (**(code **)(*in_ECX + 0x24))();
    iStack_54 = ((CONCAT22((short)((uint)psVar7 >> 0x10),sVar1 - sVar3) - iVar4) - iVar9) -
                iStack_54;
    uStack_58 = 0x74798d;
    (**(code **)(*piVar2 + 0x18))();
    uStack_58 = 0x6e0035;
    uStack_5c = 0;
    uStack_60 = 0x7479a0;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    uStack_44 = uStack_44 & 0xffffff00;
    uStack_6c = 0x7479be;
    FUN_00401660();
    puStack_4c = auStack_78;
    uStack_60 = 0xf;
    uStack_64 = 0;
    uStack_74 = 0;
    FUN_00401660(&uStack_48,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    uStack_44 = 0x7479f5;
    puVar10 = operator_new(4);
    if (puVar10 != (undefined4 *)0x0) {
      *puVar10 = &PTR_FUN_009f0d50;
    }
    uStack_44 = 0x747a0c;
    FUN_00797a20();
    if (0xf < uStack_10) {
      uStack_44 = 0x747a20;
      _free((void *)0x0);
      return;
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00747a40 @ 0x00747a40 ====

undefined4 FUN_00747a40(void)

{
  return 0x70130005;
}


// ==== FUN_00747a50 @ 0x00747a50 ====

void FUN_00747a50(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x3c);
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_00747a70 @ 0x00747a70 ====

void FUN_00747a70(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 8);
  for (iVar1 = 0xd; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_00747a90 @ 0x00747a90 ====

undefined2 FUN_00747a90(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x3c);
}


// ==== FUN_00747aa0 @ 0x00747aa0 ====

void FUN_00747aa0(byte param_1)

{
  void *in_ECX;
  
  FUN_007476e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00747ac0 @ 0x00747ac0 ====

void FUN_00747ac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0e28;
  return;
}


// ==== FUN_00747ad0 @ 0x00747ad0 ====

void FUN_00747ad0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0e28;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00747af0 @ 0x00747af0 ====

void FUN_00747af0(int param_1)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00993158;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  FUN_00401660(param_1 + 0x1c,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00747b70 @ 0x00747b70 ====

void FUN_00747b70(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00993158;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)(in_ECX + 0x18) = 0xf;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_1,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x34) = 0xf;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  FUN_00401660(param_2,0,0xffffffff);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00747be0 @ 0x00747be0 ====

int FUN_00747be0(undefined4 param_1,undefined1 param_2)

{
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int *in_ECX;
  uint unaff_EBX;
  uint unaff_retaddr;
  undefined1 auStack_98 [4];
  undefined1 uStack_94;
  undefined4 uStack_88;
  undefined1 **ppuStack_84;
  undefined1 *puStack_80;
  undefined1 auStack_74 [4];
  undefined1 local_70;
  undefined1 *puStack_68;
  void *local_60;
  undefined4 local_5c;
  undefined1 *local_48;
  void *local_44;
  undefined4 uStack_34;
  uint uStack_30;
  void *pvStack_2c;
  undefined1 uStack_24;
  int iStack_1c;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993188;
  pvStack_c = ExceptionList;
  local_48 = auStack_74;
  puStack_80 = &param_2;
  local_5c = 0xf;
  local_60 = (void *)0x0;
  local_4 = 0;
  local_70 = 0;
  ppuStack_84 = (undefined1 **)0x747c2f;
  ExceptionList = &pvStack_c;
  FUN_00401660();
  (**(code **)(*in_ECX + 4))();
  uStack_24 = 1;
  puStack_68 = auStack_98;
  puStack_80 = (undefined1 *)0xf;
  ppuStack_84 = (undefined1 **)0x0;
  uStack_94 = 0;
  FUN_00401740(s_<color__s>_009f0e14,10);
  FUN_00404230(&local_48);
  puStack_80 = (undefined1 *)0x0;
  ppuStack_84 = &local_48;
  *(undefined4 *)(iStack_1c + 0x18) = 0xf;
  *(undefined4 *)(iStack_1c + 0x14) = 0;
  uStack_24 = 2;
  *(undefined1 *)(iStack_1c + 4) = 0;
  uStack_88 = 0x747ca0;
  FUN_00401660();
  if (0xf < uStack_30) {
    puStack_80 = (undefined1 *)0x747cb0;
    _free(local_44);
    return extraout_EAX;
  }
  uStack_30 = 0xf;
  uStack_34 = 0;
  local_44 = (void *)((uint)local_44 & 0xffffff00);
  if (0xf < unaff_EBX) {
    puStack_80 = (undefined1 *)0x747ccf;
    _free(local_60);
    return extraout_EAX_00;
  }
  local_60 = (void *)((uint)local_60 & 0xffffff00);
  if (unaff_retaddr < 0x10) {
    ExceptionList = pvStack_2c;
    return iStack_1c;
  }
  puStack_80 = (undefined1 *)0x747cee;
  _free(pvStack_14);
  return extraout_EAX_01;
}


// ==== FUN_00747d10 @ 0x00747d10 ====

void FUN_00747d10(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 auStack_108 [4];
  undefined1 local_104;
  undefined4 uStack_fc;
  undefined1 *puStack_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined1 auStack_ec [4];
  undefined1 local_e8;
  undefined4 uStack_e0;
  int iStack_dc;
  undefined1 **local_d8;
  undefined1 *local_c0;
  undefined1 local_bc [4];
  void *local_b8;
  undefined4 local_a8;
  uint local_a4;
  undefined1 *local_a0 [2];
  undefined1 local_98 [4];
  void *local_94;
  undefined4 local_84;
  uint local_80;
  undefined1 local_44 [56];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009931c3;
  local_c = ExceptionList;
  iStack_dc = *(int *)(param_1 + 4);
  if ((iStack_dc == 0) ||
     (local_a0[0] = (undefined1 *)((*(int *)(param_1 + 8) - iStack_dc) / 0x1c),
     local_a0[0] == (undefined1 *)0x0)) {
    ExceptionList = &local_c;
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  local_d8 = (undefined1 **)0x0;
  local_80 = 0xf;
  local_84 = 0;
  local_94 = (void *)((uint)local_94 & 0xffffff00);
  uStack_e0 = 0x747d86;
  ExceptionList = &local_c;
  FUN_00401660();
  iVar1 = *(int *)(param_1 + 4);
  local_4 = 0;
  if ((iVar1 == 0) || ((uint)((*(int *)(param_1 + 8) - iVar1) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
    FUN_00405ca0();
  }
  iStack_dc = iVar1 + 0x1c;
  local_d8 = (undefined1 **)0x0;
  local_a4 = 0xf;
  local_a8 = 0;
  local_b8 = (void *)((uint)local_b8 & 0xffffff00);
  uStack_e0 = 0x747dd4;
  FUN_00401660();
  puVar2 = local_c0;
  local_d8 = &local_c0;
  local_4._0_1_ = 1;
  iStack_dc = 0x747df4;
  FUN_00410820();
  if (local_c0 == *(undefined1 **)(puVar2 + 8)) {
    local_a0[0] = auStack_ec;
    local_f0 = 0xffffffff;
    local_f4 = 0;
    puStack_f8 = local_bc;
    local_d8 = (undefined1 **)0x0;
    local_e8 = 0;
    uStack_fc = 0x747e54;
    FUN_00401660();
    local_c0 = auStack_108;
    local_f0 = 0xf;
    local_f4 = 0;
    local_4._0_1_ = 2;
    local_104 = 0;
    FUN_00401660(local_98,0,0xffffffff);
    local_4._0_1_ = 1;
    FUN_007482b0(local_44);
    local_4._0_1_ = 3;
    local_d8 = (undefined1 **)0x747ea5;
    FUN_00747af0();
    local_d8 = local_a0;
    local_4._0_1_ = 4;
    iStack_dc = 0x747ebe;
    FUN_00411200();
    FUN_0040a7d0();
    FUN_0040a7d0();
    if (0xf < local_a4) {
      local_d8 = (undefined1 **)0x747ee8;
      _free(local_b8);
      return;
    }
  }
  else if (0xf < local_a4) {
    local_d8 = (undefined1 **)0x747e12;
    _free(local_b8);
    return;
  }
  if (local_80 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  local_a4 = 0xf;
  local_a8 = 0;
  local_b8 = (void *)((uint)local_b8 & 0xffffff00);
  local_d8 = (undefined1 **)0x747f07;
  _free(local_94);
  return;
}


// ==== FUN_00747f30 @ 0x00747f30 ====

void FUN_00747f30(void)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  undefined1 local_54 [4];
  void *local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_44 [4];
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  void *local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_009931e5;
  pvStack_c = ExceptionList;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  ExceptionList = &pvStack_c;
  FUN_00401740(s_string_stringtable_color_txt_009f0dd4,0x1c);
  local_4 = 0;
  iVar3 = FUN_00410500(local_44);
  local_4 = 0xffffffff;
  if (0xf < local_2c) {
    _free(local_40);
    return;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (iVar3 == 0) {
    local_10 = (void *)0xf;
    local_14 = 0;
    local_24 = (void *)((uint)local_24 & 0xffffff00);
    FUN_00401740(s_cpScriptRes____NULL_009f0df4,0x13);
    local_4 = 1;
    FUN_00406880(local_28);
    local_4 = 0xffffffff;
    if (local_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(local_24);
    return;
  }
  iVar4 = *(int *)(iVar3 + 0x40);
  iVar1 = *(int *)(iVar3 + 0x44);
  while( true ) {
    if (iVar4 == iVar1) {
      local_4 = 0xffffffff;
      (**(code **)(*DAT_00b5a7cc + 0x14))(iVar3);
      ExceptionList = local_10;
      return;
    }
    local_50 = (void *)0x0;
    local_4c = 0;
    local_48 = 0;
    local_4 = 2;
    FUN_00404fb0(iVar4,0x2c,local_54);
    FUN_00747d10(local_54);
    local_4 = 0xffffffff;
    if (local_50 != (void *)0x0) break;
    iVar4 = iVar4 + 0x1c;
    local_50 = (void *)0x0;
    local_4c = 0;
    local_48 = 0;
  }
  FUN_00405de0(local_50,local_4c,local_54,iVar3);
  _free(local_50);
  return;
}


// ==== FUN_007480c0 @ 0x007480c0 ====

int FUN_007480c0(int param_1,undefined1 param_2,void *param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int extraout_EAX;
  int in_ECX;
  uint in_stack_00000020;
  undefined1 local_10 [4];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009931f7;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  piVar1 = (int *)FUN_00410820(local_10,&param_2);
  if (*piVar1 == *(int *)(in_ECX + 8)) {
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401740(s_0xffffff_009f0e08,8);
  }
  else {
    uVar2 = FUN_007484e0(&param_2);
    *(undefined4 *)(param_1 + 0x18) = 0xf;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined1 *)(param_1 + 4) = 0;
    FUN_00401660(uVar2,0,0xffffffff);
  }
  if (in_stack_00000020 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(param_3);
  return extraout_EAX;
}


// ==== FUN_00748190 @ 0x00748190 ====

void FUN_00748190(void)

{
  undefined4 *in_ECX;
  undefined1 local_10 [4];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993209;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009f0e38;
  DAT_00b5ad18 = 0;
  local_4 = 0;
  FUN_00410f60(local_10,*(undefined4 *)in_ECX[2],(undefined4 *)in_ECX[2]);
  _free((void *)in_ECX[2]);
  return;
}


// ==== FUN_00748210 @ 0x00748210 ====

void FUN_00748210(void)

{
  int iVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993226;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f0e38;
  iVar1 = FUN_004105c0();
  in_ECX[2] = iVar1;
  *(undefined1 *)(iVar1 + 0x45) = 1;
  *(undefined4 *)(in_ECX[2] + 4) = in_ECX[2];
  *(undefined4 *)in_ECX[2] = in_ECX[2];
  *(undefined4 *)(in_ECX[2] + 8) = in_ECX[2];
  in_ECX[3] = 0;
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00747f30();
  if (in_ECX == (undefined4 *)0xfffffffc) {
    DAT_00b5ad18 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ad18 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_007482b0 @ 0x007482b0 ====

undefined4 FUN_007482b0(undefined4 param_1,undefined1 param_2,void *param_3)

{
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  uint in_stack_00000020;
  undefined1 uStack00000024;
  void *in_stack_00000028;
  uint in_stack_0000003c;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993240;
  local_c = ExceptionList;
  local_4 = 1;
  ExceptionList = &local_c;
  FUN_00747b70(&param_2,&uStack00000024);
  if (0xf < in_stack_00000020) {
    _free(param_3);
    return extraout_EAX;
  }
  if (in_stack_0000003c < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(in_stack_00000028);
  return extraout_EAX_00;
}


// ==== FUN_00748330 @ 0x00748330 ====

undefined4 * FUN_00748330(undefined4 *param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  char cVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 local_8 [8];
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00411020(param_1,1,*(undefined4 *)(in_ECX + 4),param_3);
    return param_1;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (param_2 == (int *)*piVar1) {
    cVar2 = FUN_0040a6d0(param_3,param_2 + 3);
    if (cVar2 != '\0') {
      FUN_00411020(param_1,1,param_2,param_3);
      return param_1;
    }
  }
  else if (param_2 == piVar1) {
    cVar2 = FUN_0040a6d0(piVar1[2] + 0xc,param_3);
    if (cVar2 != '\0') {
      FUN_00411020(param_1,0,*(undefined4 *)(*(int *)(in_ECX + 4) + 8),param_3);
      return param_1;
    }
  }
  else {
    cVar2 = FUN_0040a6d0(param_3,param_2 + 3);
    if (cVar2 != '\0') {
      FUN_00503830();
      cVar2 = FUN_0040a6d0(param_2 + 3,param_3);
      if (cVar2 != '\0') {
        if (*(char *)(param_2[2] + 0x45) == '\0') {
          FUN_00411020(param_1,1,param_2,param_3);
          return param_1;
        }
        FUN_00411020(param_1,0,param_2,param_3);
        return param_1;
      }
    }
    cVar2 = FUN_0040a6d0(param_2 + 3,param_3);
    if (cVar2 != '\0') {
      FUN_00503890();
      if (param_2 != *(int **)(in_ECX + 4)) {
        cVar2 = FUN_0040a6d0(param_3,param_2 + 3);
        if (cVar2 == '\0') goto LAB_007484b3;
      }
      if (*(char *)(param_2[2] + 0x45) == '\0') {
        FUN_00411020(param_1,1,param_2,param_3);
        return param_1;
      }
      FUN_00411020(param_1,0,param_2,param_3);
      return param_1;
    }
  }
LAB_007484b3:
  puVar3 = (undefined4 *)FUN_00411200(local_8,param_3);
  *param_1 = *puVar3;
  return param_1;
}


// ==== FUN_007484e0 @ 0x007484e0 ====

int FUN_007484e0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int in_ECX;
  undefined1 local_60 [4];
  void *local_5c;
  undefined4 local_4c;
  uint local_48;
  void *local_40;
  undefined4 local_30;
  uint local_2c;
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  iVar1 = param_1;
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00993260;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar2 = FUN_00410660(param_1);
  if (iVar2 != *(int *)(in_ECX + 4)) {
    if (*(uint *)(iVar2 + 0x24) < 0x10) {
      iVar3 = iVar2 + 0x10;
    }
    else {
      iVar3 = *(int *)(iVar2 + 0x10);
    }
    iVar3 = FUN_00403620(0,*(undefined4 *)(iVar1 + 0x14),iVar3,*(undefined4 *)(iVar2 + 0x20));
    if (-1 < iVar3) goto LAB_007485cd;
  }
  local_48 = 0xf;
  local_4c = 0;
  local_5c = (void *)((uint)local_5c & 0xffffff00);
  local_4 = 0;
  uVar4 = FUN_00410890(iVar1,local_60);
  local_4 = CONCAT31(local_4._1_3_,1);
  piVar5 = (int *)FUN_00748330(&param_1,iVar2,uVar4);
  iVar2 = *piVar5;
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  if (0xf < local_2c) {
    _free(local_40);
    return extraout_EAX_00;
  }
  local_2c = 0xf;
  local_30 = 0;
  local_40 = (void *)((uint)local_40 & 0xffffff00);
  if (0xf < local_48) {
    _free(local_5c);
    return extraout_EAX_01;
  }
LAB_007485cd:
  ExceptionList = local_c;
  return iVar2 + 0x28;
}


// ==== FUN_007485f0 @ 0x007485f0 ====

void FUN_007485f0(byte param_1)

{
  void *in_ECX;
  
  FUN_00748190();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00748610 @ 0x00748610 ====

void FUN_00748610(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0f44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00748630 @ 0x00748630 ====

float10 FUN_00748630(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0xc))();
  return fVar1 + fVar1;
}


// ==== FUN_00748640 @ 0x00748640 ====

void FUN_00748640(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_00748650 @ 0x00748650 ====

void FUN_00748650(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00748660 @ 0x00748660 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00748660(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f0fe4;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ad1c = (undefined4 *)0x0;
    _DAT_00000000 = 0;
    in_ECX[2] = 0;
    return;
  }
  DAT_00b5ad1c = in_ECX;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_007486c0 @ 0x007486c0 ====

undefined2 FUN_007486c0(void)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  puVar2 = (undefined2 *)(**(code **)(**(int **)(iVar1 + 0xc) + 0x14))();
  return *puVar2;
}


// ==== FUN_007486e0 @ 0x007486e0 ====

undefined2 FUN_007486e0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0xc) + 0x24))();
  iVar1 = (**(code **)(*piVar2 + 0xc))();
  return *(undefined2 *)(iVar1 + 4);
}


// ==== FUN_00748710 @ 0x00748710 ====

undefined4 FUN_00748710(void)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0xc) + 0x24))();
  puVar3 = (undefined4 *)(**(code **)(*piVar2 + 0xc))();
  return CONCAT22((short)((uint)puVar3[1] >> 0x10),(short)*puVar3);
}


// ==== FUN_00748740 @ 0x00748740 ====

uint FUN_00748740(void)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0xc) + 0x24))();
  puVar3 = (uint *)(**(code **)(*piVar2 + 0xc))();
  return *puVar3 >> 0x10;
}


// ==== FUN_00748780 @ 0x00748780 ====

uint FUN_00748780(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0xc) + 0x24))();
  iVar1 = (**(code **)(*piVar2 + 0xc))();
  return *(uint *)(iVar1 + 4) >> 0x10;
}


// ==== FUN_007487c0 @ 0x007487c0 ====

undefined2 FUN_007487c0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 4) + 0x14))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x10))();
  iVar1 = (**(code **)(*piVar2 + 4))();
  return *(undefined2 *)(iVar1 + 0x62);
}


// ==== FUN_007487f0 @ 0x007487f0 ====

undefined2 FUN_007487f0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 4) + 0x14))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x10))();
  iVar1 = (**(code **)(*piVar2 + 4))();
  return *(undefined2 *)(iVar1 + 0x5e);
}


// ==== FUN_00748820 @ 0x00748820 ====

undefined2 FUN_00748820(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 4) + 0x14))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x10))();
  iVar1 = (**(code **)(*piVar2 + 4))();
  return *(undefined2 *)(iVar1 + 0x60);
}


// ==== FUN_00748850 @ 0x00748850 ====

undefined2 FUN_00748850(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 4) + 0x14))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x10))();
  iVar1 = (**(code **)(*piVar2 + 4))();
  return *(undefined2 *)(iVar1 + 100);
}


// ==== FUN_00748880 @ 0x00748880 ====

void FUN_00748880(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x40) + 0x24))();
                    /* WARNING: Could not recover jumptable at 0x00748897. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0x18))();
  return;
}


// ==== FUN_007488a0 @ 0x007488a0 ====

void FUN_007488a0(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x40) + 0x24))();
                    /* WARNING: Could not recover jumptable at 0x007488b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0x14))();
  return;
}


// ==== FUN_007488c0 @ 0x007488c0 ====

void FUN_007488c0(void)

{
                    /* WARNING: Could not recover jumptable at 0x007488c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*DAT_00b5a838 + 0x14))();
  return;
}


// ==== FUN_007488d0 @ 0x007488d0 ====

uint FUN_007488d0(void)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar1 = *(int **)(uVar2 + 0x24);
  if (piVar1 == (int *)0x0) {
    return uVar2 & 0xffffff00;
  }
  uVar2 = 6;
  do {
    iVar3 = (**(code **)(*piVar1 + 0x2c))(uVar2);
    uVar4 = 0;
    if (iVar3 != 0) {
      uVar4 = (**(code **)(*DAT_00b5ad20 + 0x18))(iVar3);
      if (uVar4 == 0x602) {
        return 0x601;
      }
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x15);
  return uVar4 & 0xffffff00;
}


// ==== FUN_00748930 @ 0x00748930 ====

void FUN_00748930(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x90) + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x0074894a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0xc))();
  return;
}


// ==== FUN_00748950 @ 0x00748950 ====

void FUN_00748950(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x90) + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x0074896a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0x10))();
  return;
}


// ==== FUN_00748970 @ 0x00748970 ====

void FUN_00748970(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x90) + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x0074898a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*piVar2 + 0x18))();
  return;
}


// ==== FUN_00748990 @ 0x00748990 ====

void FUN_00748990(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5ad1c = 0;
  *in_ECX = &PTR_FUN_009f0f44;
  return;
}


// ==== FUN_007489b0 @ 0x007489b0 ====

float10 FUN_007489b0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  if (DAT_00b5a97c == 0) {
    return (float10)DAT_0099d0f8;
  }
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  iVar1 = **(int **)(iVar1 + 0x50);
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar3 = (int *)(**(code **)(iVar1 + 0x14))(uVar2);
  iVar1 = (**(code **)(*piVar3 + 0x30))();
  return (float10)*(float *)(iVar1 + 8);
}


// ==== FUN_007489f0 @ 0x007489f0 ====

float10 FUN_007489f0(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  float *pfVar4;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  iVar1 = **(int **)(iVar1 + 0x50);
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar3 = (int *)(**(code **)(iVar1 + 0x14))(uVar2);
  pfVar4 = (float *)(**(code **)(*piVar3 + 0x30))();
  return (float10)*pfVar4 * (float10)DAT_009b012c;
}


// ==== FUN_00748a30 @ 0x00748a30 ====

float10 FUN_00748a30(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  float *pfVar4;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  iVar1 = **(int **)(iVar1 + 0x50);
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar3 = (int *)(**(code **)(iVar1 + 0x14))(uVar2);
  pfVar4 = (float *)(**(code **)(*piVar3 + 0x30))();
  return (float10)*pfVar4 * (float10)DAT_009b012c;
}


// ==== FUN_00748a70 @ 0x00748a70 ====

float10 FUN_00748a70(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  float *pfVar4;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  iVar1 = **(int **)(iVar1 + 0x50);
  uVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar3 = (int *)(**(code **)(iVar1 + 0x14))(uVar2);
  pfVar4 = (float *)(**(code **)(*piVar3 + 0x30))();
  return (float10)*pfVar4 * (float10)DAT_009b012c;
}


// ==== FUN_00748ab0 @ 0x00748ab0 ====

void FUN_00748ab0(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  undefined4 *puVar7;
  int *piVar8;
  
  if (DAT_00b5acd8 != (int *)0x0) {
    uVar1 = (**(code **)(*DAT_00b5a97c + 0xc))();
    piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(uVar1);
    if (piVar2 != (int *)0x0) {
      piVar3 = (int *)(**(code **)(*piVar2 + 0x14))();
      uVar1 = (**(code **)(*piVar3 + 0x24))();
      piVar3 = (int *)FUN_00803725(uVar1,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                   &Framework::Creature::IMiniPC::RTTI_Type_Descriptor,0);
      iVar4 = (**(code **)(*DAT_00b5a980 + 8))();
      if (*(int **)(iVar4 + 0x18) == (int *)0x0) {
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)(**(code **)(**(int **)(iVar4 + 0x18) + 0x18))();
      }
      piVar5 = (int *)0x0;
      if (*(int **)(iVar4 + 0x74) != (int *)0x0) {
        piVar5 = (int *)(**(code **)(**(int **)(iVar4 + 0x74) + 0x14))();
      }
      iVar4 = *piVar3;
      uVar1 = (**(code **)(*piVar8 + 8))();
      (**(code **)(iVar4 + 0x28))(uVar1);
      iVar4 = *piVar3;
      iVar6 = (**(code **)(*piVar5 + 8))();
      (**(code **)(iVar4 + 0x2c))(*(undefined1 *)(iVar6 + 4));
      puVar7 = (undefined4 *)(**(code **)(*piVar5 + 8))();
      (**(code **)(*piVar3 + 0x30))(*puVar7);
                    /* WARNING: Could not recover jumptable at 0x00748b7f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(*piVar2 + 0x20))();
      return;
    }
  }
  return;
}


// ==== FUN_00748b90 @ 0x00748b90 ====

void FUN_00748b90(uint *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  
  *param_1 = 0x1e;
  *param_2 = 0;
  if ((*(int *)(in_ECX + 4) != 0) && (iVar1 = *(int *)(in_ECX + 8), iVar1 != 0)) {
    iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    uVar3 = 0x708 - (uint)(iVar2 - iVar1) / 1000;
    *param_2 = uVar3;
    *param_1 = uVar3 / 0x3c;
    *param_2 = *param_2 % 0x3c;
  }
  return;
}


// ==== FUN_00748c00 @ 0x00748c00 ====

void FUN_00748c00(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar1 + 0x44) == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x44) + 0x18))();
  }
  if (param_1 == 0) {
    (**(code **)(*piVar2 + 0x2c))();
    (**(code **)(*piVar2 + 0x38))(0);
    (**(code **)(*piVar2 + 0x3c))(1);
    return;
  }
  (**(code **)(*piVar2 + 0x3c))(0);
  return;
}


// ==== FUN_00748c50 @ 0x00748c50 ====

undefined4 FUN_00748c50(void *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  undefined4 extraout_EAX_00;
  void *unaff_ESI;
  uint in_stack_00000018;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993278;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*DAT_00b5acd8 + 0x10))(&param_1);
  iVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (iVar1 == iVar2) {
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  }
  else {
    piVar3 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(iVar1);
    if (piVar3 == (int *)0x0) goto joined_r0x00748d1d;
    piVar3 = (int *)(**(code **)(*piVar3 + 0x14))();
    uVar4 = (**(code **)(*piVar3 + 0x24))();
    iVar1 = FUN_00803725(uVar4,0,&Framework::ICreature::RTTI_Type_Descriptor,
                         &Framework::Creature::IMiniPC::RTTI_Type_Descriptor,0);
    if (iVar1 == 0) goto joined_r0x00748d1d;
  }
  if (*(int **)(iVar1 + 0x4c) != (int *)0x0) {
    piVar3 = (int *)(**(code **)(**(int **)(iVar1 + 0x4c) + 0x14))();
    iVar1 = (**(code **)(*piVar3 + 0x10))();
    if (*(char *)(iVar1 + 0xb) == '\x11') {
      if (in_stack_00000018 < 0x10) {
        ExceptionList = unaff_ESI;
        return 1;
      }
      _free(param_1);
      return extraout_EAX;
    }
  }
joined_r0x00748d1d:
  if (in_stack_00000018 < 0x10) {
    ExceptionList = unaff_ESI;
    return 0;
  }
  _free(param_1);
  return extraout_EAX_00;
}


// ==== FUN_00748d50 @ 0x00748d50 ====

uint FUN_00748d50(undefined4 param_1,void *param_2)

{
  uint in_EAX;
  uint extraout_EAX;
  uint in_stack_0000001c;
  
  if (in_stack_0000001c < 0x10) {
    return in_EAX & 0xffffff00;
  }
  _free(param_2);
  return extraout_EAX;
}


// ==== FUN_00748d70 @ 0x00748d70 ====

int FUN_00748d70(int param_1)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int extraout_EAX;
  char *pcVar4;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099328a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a980 + 8))();
  pcVar3 = (char *)(**(code **)(*piVar2 + 0x70))();
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  pcVar4 = pcVar3;
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(pcVar3,(int)pcVar4 - (int)(pcVar3 + 1));
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  uStack_4 = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(auStack_28,0,0xffffffff);
  if (uStack_10 < 0x10) {
    ExceptionList = pvStack_c;
    return param_1;
  }
  _free(pvStack_24);
  return extraout_EAX;
}


// ==== FUN_00748e30 @ 0x00748e30 ====

void FUN_00748e30(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 in_stack_00000028;
  undefined1 auStack_584 [440];
  undefined4 uStack_3cc;
  undefined4 uStack_3c8;
  undefined4 uStack_3c4;
  TypeDescriptor *pTStack_3c0;
  TypeDescriptor *pTStack_3bc;
  undefined4 *puStack_3b8;
  undefined1 *puStack_3b4;
  undefined1 auStack_3b0 [68];
  undefined2 uStack_36c;
  void *pvStack_1e0;
  undefined1 auStack_1dc [4];
  undefined4 uStack_1d8;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009932aa;
  pvStack_c = ExceptionList;
  puStack_3b4 = (undefined1 *)0x748e56;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (param_1 == iVar1) {
    puStack_3b4 = (undefined1 *)0x748e6e;
    FUN_00733920();
    puStack_3b4 = auStack_1dc;
    uStack_4 = 0;
    puStack_3b8 = (undefined4 *)0x748e8c;
    puStack_3b8 = (undefined4 *)(**(code **)(*DAT_00b5aca8 + 0x18))();
    puStack_8._0_1_ = 1;
    pTStack_3bc = (TypeDescriptor *)0x748e9e;
    FUN_00733a40();
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    puStack_3b8 = (undefined4 *)0x748eb2;
    FUN_00537c20();
    puStack_3b4 = auStack_584;
    uStack_36c = in_stack_00000028._2_2_;
    FUN_00733990(auStack_3b0);
    (**(code **)(*DAT_00b5acac + 8))();
    uStack_1d8 = 0xffffffff;
    FUN_00537c20();
    ExceptionList = pvStack_1e0;
    return;
  }
  puStack_3b4 = (undefined1 *)param_1;
  puStack_3b8 = (undefined4 *)0x748f20;
  piVar2 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))();
  if (piVar2 != (int *)0x0) {
    puStack_3b8 = (undefined4 *)0x748f2b;
    piVar2 = (int *)(**(code **)(*piVar2 + 0x14))();
    puStack_3b8 = (undefined4 *)0x748f32;
    uStack_3c8 = (**(code **)(*piVar2 + 0x24))();
    puStack_3b8 = (undefined4 *)0x0;
    pTStack_3bc = &Framework::Creature::IMiniPC::RTTI_Type_Descriptor;
    pTStack_3c0 = &Framework::ICreature::RTTI_Type_Descriptor;
    uStack_3c4 = 0;
    uStack_3cc = 0x748f46;
    piVar2 = (int *)FUN_00803725();
    if (piVar2 != (int *)0x0) {
      puStack_3b8 = &param_1;
      pTStack_3bc = (TypeDescriptor *)0x748f5c;
      (**(code **)(*piVar2 + 0x20))();
    }
  }
  ExceptionList = pvStack_10;
  return;
}


// ==== FUN_00748f80 @ 0x00748f80 ====

void FUN_00748f80(undefined1 *param_1)

{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined1 *unaff_retaddr;
  undefined1 uStack_4c;
  undefined4 uStack_48;
  void *pvStack_44;
  uint uStack_30;
  void *pvStack_28;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009932bc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar2 = (**(code **)(*DAT_00b5ac1c + 8))();
  FUN_006a2450(uVar2);
  uStack_4 = 0;
  (**(code **)(*DAT_00b5ac80 + 8))(uStack_48);
  uVar1 = (**(code **)(*DAT_00b5ac1c + 0xc))();
  *unaff_retaddr = uStack_4c;
  *param_1 = uVar1;
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return;
  }
  if (uStack_30 < 0x10) {
    ExceptionList = pvStack_10;
    return;
  }
  _free(pvStack_44);
  return;
}


// ==== FUN_00749030 @ 0x00749030 ====

int FUN_00749030(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  int unaff_retaddr;
  undefined4 local_6c;
  void *pvStack_68;
  undefined4 uStack_58;
  uint uStack_54;
  undefined4 uStack_48;
  void *pvStack_44;
  uint uStack_30;
  void *pvStack_28;
  undefined4 uStack_18;
  uint uStack_14;
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009932d6;
  pvStack_c = ExceptionList;
  local_6c = 0;
  ExceptionList = &pvStack_c;
  uVar2 = (**(code **)(*DAT_00b5ac1c + 8))();
  FUN_006a2450(uVar2);
  uStack_4 = 0;
  iVar3 = (**(code **)(*DAT_00b5ac80 + 8))(uStack_48);
  uStack_54 = 0xf;
  uStack_58 = 0;
  pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
  pcVar4 = (char *)(iVar3 + 1);
  do {
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar3 + 1),(int)pcVar4 - (iVar3 + 2));
  *(undefined4 *)(unaff_retaddr + 0x18) = 0xf;
  *(undefined4 *)(unaff_retaddr + 0x14) = 0;
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
  *(undefined1 *)(unaff_retaddr + 4) = 0;
  FUN_00401660(&local_6c,0,0xffffffff);
  if (0xf < uStack_54) {
    _free(pvStack_68);
    return extraout_EAX;
  }
  uStack_54 = 0xf;
  uStack_58 = 0;
  pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
  if (0xf < uStack_14) {
    _free(pvStack_28);
    return extraout_EAX_00;
  }
  uStack_14 = 0xf;
  uStack_18 = 0;
  pvStack_28 = (void *)((uint)pvStack_28 & 0xffffff00);
  if (uStack_30 < 0x10) {
    ExceptionList = pvStack_10;
    return unaff_retaddr;
  }
  _free(pvStack_44);
  return extraout_EAX_01;
}


// ==== FUN_00749140 @ 0x00749140 ====

/* WARNING: Removing unreachable block (ram,0x00749227) */

int FUN_00749140(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  undefined1 auStack_6a [34];
  undefined4 uStack_48;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  int iStack_4;
  
  iStack_4 = 0xffffffff;
  puStack_8 = &LAB_009932f0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  uVar2 = (**(code **)(*DAT_00b5ac1c + 8))();
  FUN_006a2450(uVar2);
  iStack_4 = 0;
  (**(code **)(*DAT_00b5ac80 + 8))(uStack_48);
  iVar3 = (**(code **)(*DAT_00b5ac78 + 8))(auStack_6a + -6);
  iVar5 = iStack_4;
  if (iVar3 == 0) {
    *(undefined4 *)(iStack_4 + 0x18) = 0xf;
    *(undefined4 *)(iStack_4 + 0x14) = 0;
    *(undefined1 *)(iStack_4 + 4) = 0;
    FUN_00401740(&DAT_009f0e84,0);
  }
  else {
    pcVar4 = (char *)(iVar3 + 10);
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    FUN_00401740((char *)(iVar3 + 10),(int)pcVar4 - (iVar3 + 0xb));
    iVar5 = iStack_4;
    *(undefined4 *)(iStack_4 + 0x18) = 0xf;
    *(undefined4 *)(iStack_4 + 0x14) = 0;
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,1);
    *(undefined1 *)(iStack_4 + 4) = 0;
    FUN_00401660(auStack_6a + -6,0,0xffffffff);
  }
  FUN_00844200();
  ExceptionList = pvStack_14;
  return iVar5;
}


// ==== FUN_00749270 @ 0x00749270 ====

float10 FUN_00749270(void)

{
  code *pcVar1;
  int iVar2;
  float10 extraout_ST0;
  float10 fVar3;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993302;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar2 + 0x24) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(iVar2 + 0x24) + 0x50))();
    ExceptionList = pvStack_c;
    return (float10)*(float *)(iVar2 + 0x44);
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pSuitManager____NULL_009f0e88,0x14);
  uStack_4 = 0;
  FUN_00406880(auStack_28);
  uStack_4 = 0xffffffff;
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    fVar3 = (float10)(*pcVar1)();
    return fVar3;
  }
  _free(pvStack_24);
  return extraout_ST0;
}


// ==== FUN_00749320 @ 0x00749320 ====

float10 FUN_00749320(void)

{
  code *pcVar1;
  int iVar2;
  float10 extraout_ST0;
  float10 fVar3;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993314;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar2 + 0x24) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(iVar2 + 0x24) + 0x50))();
    ExceptionList = pvStack_c;
    return (float10)*(float *)(iVar2 + 0x48);
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pSuitManager____NULL_009f0ea0,0x14);
  uStack_4 = 0;
  FUN_00406880(auStack_28);
  uStack_4 = 0xffffffff;
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    fVar3 = (float10)(*pcVar1)();
    return fVar3;
  }
  _free(pvStack_24);
  return extraout_ST0;
}


// ==== FUN_007493d0 @ 0x007493d0 ====

uint FUN_007493d0(void)

{
  code *pcVar1;
  int iVar2;
  uint extraout_EAX;
  uint uVar3;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993326;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar2 + 0x24) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(iVar2 + 0x24) + 0x50))();
    ExceptionList = pvStack_c;
    return (uint)*(byte *)(iVar2 + 0x4c);
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pSuitManager____NULL_009f0eb8,0x14);
  uStack_4 = 0;
  FUN_00406880(auStack_28);
  uStack_4 = 0xffffffff;
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_24);
  return extraout_EAX;
}


// ==== FUN_00749480 @ 0x00749480 ====

void FUN_00749480(void)

{
  code *pcVar1;
  byte bVar2;
  int iVar3;
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
  puStack_8 = &LAB_00993340;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (*(int **)(iVar3 + 0x20) == (int *)0x0) {
    uStack_2c = 0xf;
    uStack_30 = 0;
    pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
    FUN_00401740(s_pBag____NULL_009f0ed0,0xc);
    uStack_4 = 0;
    FUN_00406880(auStack_44);
    uStack_4 = 0xffffffff;
    if (uStack_2c < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_40);
    return;
  }
  bVar2 = (**(code **)(**(int **)(iVar3 + 0x20) + 0x70))();
  if ((1 < bVar2) && (bVar2 < 5)) {
    ExceptionList = pvStack_c;
    return;
  }
  uStack_10 = 0xf;
  uStack_14 = 0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_IITEM__IBag__byMinPageCount_<__b_009f0ee0,0x56);
  uStack_4 = 1;
  FUN_00406880(auStack_28);
  if (uStack_10 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_00749570 @ 0x00749570 ====

undefined4 * FUN_00749570(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined4 *unaff_retaddr;
  char acStack_41a [2];
  undefined4 auStack_418 [9];
  char acStack_3f2 [33];
  undefined1 auStack_3d1 [37];
  undefined4 ****appppuStack_3ac [5];
  uint uStack_398;
  undefined1 auStack_1dc [460];
  void *pvStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993360;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a97c + 0xc))();
  if (param_2 == iVar2) {
    FUN_00733920();
    uStack_4 = 0;
    uVar3 = (**(code **)(*DAT_00b5aca8 + 0x18))(auStack_1dc);
    puStack_8._0_1_ = 1;
    FUN_00733a40(uVar3);
    puStack_8 = (undefined1 *)((uint)puStack_8._1_3_ << 8);
    FUN_00537c20();
    if (uStack_398 < 0x10) {
      appppuStack_3ac[0] = appppuStack_3ac;
    }
    FUN_0050cd30(acStack_3f2,&DAT_009f0f38,appppuStack_3ac[0]);
    uVar4 = 0;
    do {
      cVar1 = acStack_3f2[uVar4];
      acStack_41a[uVar4 - 6] = cVar1;
      if (cVar1 == '\0') break;
      uVar4 = uVar4 + 1;
    } while (uVar4 < 0x21);
    piVar5 = (int *)(**(code **)(*DAT_00b5acac + 0x30))();
    piVar5 = (int *)(**(code **)(*piVar5 + 0x14))();
    (**(code **)(*piVar5 + 0x10))();
    pcVar6 = acStack_41a + -6;
    puVar7 = unaff_retaddr;
    for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      puVar7 = puVar7 + 1;
    }
    *(undefined2 *)puVar7 = *(undefined2 *)pcVar6;
    puStack_8 = (undefined1 *)0xffffffff;
    FUN_00537c20();
  }
  else {
    piVar5 = (int *)(**(code **)(*DAT_00b5acd8 + 0xc))(param_2);
    if (piVar5 == (int *)0x0) {
      FUN_0050cd30(acStack_3f2,&DAT_009f0f38,&DAT_009f0e82);
      FUN_00496ed0(acStack_3f2);
      pcVar6 = acStack_41a + -6;
    }
    else {
      piVar5 = (int *)(**(code **)(*piVar5 + 0x14))();
      uVar3 = (**(code **)(*piVar5 + 0x24))();
      piVar5 = (int *)FUN_00803725(uVar3,0,&Framework::ICreature::RTTI_Type_Descriptor,
                                   &Framework::Creature::IMiniPC::RTTI_Type_Descriptor,0);
      if (piVar5 == (int *)0x0) {
        FUN_0050cd30(auStack_3d1,&DAT_009f0f38,&DAT_009f0e83);
        FUN_00496ed0(auStack_3d1);
        pcVar6 = acStack_41a + -6;
      }
      else {
        pcVar6 = (char *)(**(code **)(*piVar5 + 0x24))();
      }
    }
    puVar7 = unaff_retaddr;
    for (iVar2 = 10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *(undefined4 *)pcVar6;
      pcVar6 = pcVar6 + 4;
      puVar7 = puVar7 + 1;
    }
    *(undefined2 *)puVar7 = *(undefined2 *)pcVar6;
  }
  ExceptionList = pvStack_10;
  return unaff_retaddr;
}


// ==== FUN_007497a0 @ 0x007497a0 ====

void FUN_007497a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00748990();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007497c0 @ 0x007497c0 ====

void FUN_007497c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f17cc;
  return;
}


// ==== FUN_007497d0 @ 0x007497d0 ====

void FUN_007497d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f17cc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_007497f0 @ 0x007497f0 ====

bool FUN_007497f0(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x20))(param_1);
  return iVar1 == 4;
}


// ==== FUN_00749810 @ 0x00749810 ====

bool FUN_00749810(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x18))(param_1);
  return iVar1 == 4;
}


// ==== FUN_00749830 @ 0x00749830 ====

undefined1 FUN_00749830(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_24 [8];
  undefined1 uStack_3;
  
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0x14))();
  puVar3 = auStack_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return uStack_3;
}


// ==== FUN_00749860 @ 0x00749860 ====

undefined2 FUN_00749860(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_24 [3];
  undefined2 uStack_18;
  
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0x14))();
  puVar3 = auStack_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return uStack_18;
}


// ==== FUN_00749890 @ 0x00749890 ====

undefined1 FUN_00749890(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 auStack_24 [7];
  undefined1 uStack_6;
  
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0x14))();
  puVar3 = auStack_24;
  for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  return uStack_6;
}


// ==== FUN_007498d0 @ 0x007498d0 ====

char FUN_007498d0(int *param_1)

{
  char cVar1;
  int iVar2;
  
  cVar1 = '\0';
  if (param_1 != (int *)0x0) {
    iVar2 = (**(code **)(*param_1 + 4))();
    if (*(char *)(iVar2 + 0xa5) == '\0') {
      return '\0';
    }
    iVar2 = (**(code **)(*param_1 + 4))();
    if (*(char *)(iVar2 + 0xa6) == '\0') {
      return '\x01';
    }
    iVar2 = (**(code **)(*param_1 + 4))();
    if (*(char *)(iVar2 + 0xa7) == '\0') {
      return '\x02';
    }
    iVar2 = (**(code **)(*param_1 + 4))();
    cVar1 = (*(char *)(iVar2 + 0xa8) != '\0') + '\x03';
  }
  return cVar1;
}


// ==== FUN_00749940 @ 0x00749940 ====

undefined4 FUN_00749940(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  if ((short)param_1 != 0) {
    piVar1 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(param_1);
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 4))();
      return *(undefined4 *)(iVar2 + 0xc);
    }
  }
  return 0xffffffff;
}


// ==== FUN_00749970 @ 0x00749970 ====

void FUN_00749970(int *param_1)

{
  (**(code **)(*param_1 + 0x10))();
  (**(code **)(*DAT_00b5a730 + 0x10))(1,param_1);
  return;
}


// ==== FUN_00749990 @ 0x00749990 ====

void FUN_00749990(int *param_1)

{
  int *piVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  int aiStack_a8 [41];
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x2c))();
  piVar3 = aiStack_a8;
  for (iVar2 = 0x27; iVar2 != 0; iVar2 = iVar2 + -1) {
    *piVar3 = *piVar1;
    piVar1 = piVar1 + 1;
    piVar3 = piVar3 + 1;
  }
  if (((aiStack_a8[1] == 4) || (aiStack_a8[1] == 5)) || (aiStack_a8[1] == 2)) {
    (**(code **)(*in_ECX + 0x38))(param_1);
    return;
  }
  (**(code **)(*in_ECX + 0x3c))(param_1,1);
  return;
}


// ==== FUN_00749a00 @ 0x00749a00 ====

void FUN_00749a00(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
                    /* WARNING: Could not recover jumptable at 0x00749a19. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(iVar1 + 0x24) + 0x14))();
  return;
}


// ==== FUN_00749a20 @ 0x00749a20 ====

undefined4 FUN_00749a20(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(param_1);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 4))();
    iVar2 = *(int *)(iVar2 + 8);
    if ((iVar2 == 4) || (iVar2 == 5)) {
      return 1;
    }
    if ((iVar2 == 1) && (iVar2 = (**(code **)(*piVar1 + 4))(), *(int *)(iVar2 + 0xc) == 0x101)) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00749a70 @ 0x00749a70 ====

int * FUN_00749a70(uint param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uStack_130;
  undefined1 auStack_122 [30];
  undefined1 auStack_104 [260];
  
  uStack_130 = param_1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))();
  if (piVar2 == (int *)0x0) {
    auStack_104[0] = 0;
    uVar3 = FUN_0044a580(auStack_104,s_____ERROR_____Invalid_Item_Index_009f1284,param_1 & 0xffff);
    FUN_00797b80(uVar3);
    return (int *)0x0;
  }
  FUN_00797a50(auStack_122 + -6,0,0x24);
  iVar4 = (**(code **)(*piVar2 + 4))();
  if (*(char *)(iVar4 + 0x7e) == '\x01') {
    (**(code **)(*piVar2 + 4))();
  }
  piVar2 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 8))(&uStack_130);
    if (cVar1 != '\0') {
      return piVar2;
    }
    (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar2);
  }
  return (int *)0x0;
}


// ==== FUN_00749b50 @ 0x00749b50 ====

undefined4 FUN_00749b50(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int aiStack_a8 [26];
  byte bStack_40;
  
  iVar1 = (**(code **)(*param_1 + 0x48))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*param_1 + 0x2c))();
    piVar4 = aiStack_a8;
    for (iVar1 = 0x27; iVar1 != 0; iVar1 = iVar1 + -1) {
      *piVar4 = *piVar2;
      piVar2 = piVar2 + 1;
      piVar4 = piVar4 + 1;
    }
    if ((aiStack_a8[1] == 4) || (aiStack_a8[1] == 5)) {
      uVar3 = (**(code **)(*param_1 + 0x34))();
      FUN_0074f860(uVar3);
      if (bStack_40 != 0) {
        if ((6 < bStack_40) && (bStack_40 < 10)) {
          return 0x17;
        }
        if ((bStack_40 < 4) || (uVar3 = 0x16, 6 < bStack_40)) {
          uVar3 = 0x15;
        }
        return uVar3;
      }
    }
  }
  return 0;
}


// ==== FUN_00749bf0 @ 0x00749bf0 ====

void FUN_00749bf0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993378;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f183c;
  local_4 = 0;
  DAT_00b5ad20 = 0;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x3c,0x1c,FUN_0074f950);
  *in_ECX = &PTR_FUN_009f17cc;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00749c50 @ 0x00749c50 ====

void FUN_00749c50(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar5 = (undefined4 *)(in_ECX + 0x28);
  iVar4 = 0x1c;
  do {
    *(undefined1 *)(puVar5 + -9) = 0;
    if ((uint)puVar5[5] < 0x10) {
      puVar3 = puVar5;
    }
    else {
      puVar3 = (undefined4 *)*puVar5;
    }
    iVar1 = puVar5[4] + (int)puVar3;
    if ((uint)puVar5[5] < 0x10) {
      puVar6 = puVar5;
      puVar3 = puVar5;
    }
    else {
      puVar6 = (undefined4 *)*puVar5;
      puVar3 = (undefined4 *)*puVar5;
    }
    if (puVar3 == (undefined4 *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (int)puVar3 - (int)puVar6;
    }
    if (iVar1 != 0) {
      iVar1 = iVar1 - (int)puVar3;
    }
    FUN_00401390(iVar2,iVar1);
    puVar5 = puVar5 + 0xf;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  return;
}


// ==== FUN_00749cc0 @ 0x00749cc0 ====

undefined4 FUN_00749cc0(int *param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined1 auStack_e4 [24];
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  undefined4 uStack_c4;
  undefined4 uStack_c0;
  undefined1 *puStack_bc;
  int aiStack_a8 [41];
  
  puStack_bc = (undefined1 *)0x749cd9;
  piVar2 = (int *)(**(code **)(*param_1 + 0x2c))();
  piVar1 = DAT_00b5a980;
  piVar6 = aiStack_a8;
  for (iVar5 = 0x27; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar6 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar6 = piVar6 + 1;
  }
  if ((aiStack_a8[1] == 3) && (aiStack_a8[2] == 0x302)) {
    iVar5 = *DAT_00b5acc8;
    puStack_bc = (undefined1 *)0x749d10;
    iVar3 = (**(code **)(*param_1 + 0x2c))();
    puStack_bc = (undefined1 *)CONCAT22((short)((uint)iVar3 >> 0x10),*(undefined2 *)(iVar3 + 0x20));
    uStack_c0 = 0x749d1c;
    uStack_c0 = (**(code **)(*piVar1 + 8))();
    uStack_c4 = 0x749d26;
    iVar5 = (**(code **)(iVar5 + 8))();
    if (iVar5 != 0) {
      if ((param_2 == '\0') && (iVar5 == 1)) {
        uStack_c4 = 0x14;
        uStack_c8 = 0;
        uStack_cc = 0x749d44;
        uVar4 = (**(code **)(*DAT_00b5a794 + 0xc))();
        puStack_bc = auStack_e4;
        FUN_00765c50(uVar4);
        (**(code **)(*DAT_00b5ad0c + 0x28))(2);
      }
      return 0;
    }
  }
  return 1;
}


// ==== FUN_00749d80 @ 0x00749d80 ====

void FUN_00749d80(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009933a0;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009f183c;
  _eh_vector_constructor_iterator_
            (in_ECX + 1,0x3c,0x1c,(_func_void_void_ptr *)&LAB_0074f930,FUN_0074f950);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5ad20 = (undefined4 *)0x0;
  }
  else {
    DAT_00b5ad20 = in_ECX;
  }
  FUN_00749c50();
  FUN_00401740(s_<NAME>_009f10bc,6);
  FUN_00401740(s_<TIMELIMIT>_009f10c4,0xb);
  FUN_00401740(s_<ENDUARANCE>_009f10d0,0xc);
  FUN_00401740(s_<DOUBLEHAND>_009f10e0,0xc);
  FUN_00401740(s_<MINMAXDEFENCE>_009f10f0,0xf);
  FUN_00401740(s_<MINMAXDAM>_009f1100,0xb);
  FUN_00401740(s_<MINMAXMAGICDAM>_009f110c,0x10);
  FUN_00401740(s_<ATTACKSPEED>_009f1120,0xd);
  FUN_00401740(s_<BLOCKINGRATE>_009f1130,0xe);
  FUN_00401740(s_<PCCLASS>_009f1140,9);
  FUN_00401740(s_<REQLV>_009f114c,7);
  FUN_00401740(s_<REQSTR>_009f1154,8);
  FUN_00401740(s_<REQDEX>_009f1160,8);
  FUN_00401740(s_<REQSPR>_009f116c,8);
  FUN_00401740(s_<OPTION>_009f1178,8);
  FUN_00401740(s_<BUYVALUE>_009f1184,10);
  FUN_00401740(s_<SELLVALUE>_009f1190,0xb);
  FUN_00401740(s_<STACKCOUNT>_009f119c,0xc);
  FUN_00401740(s_<USEHP>_009f11ac,7);
  FUN_00401740(s_<USEMP>_009f11b4,7);
  FUN_00401740(s_<COOLTIME>_009f11bc,10);
  FUN_00401740(s_<DESCRIPTION>_009f11c8,0xd);
  FUN_00401740(s_<CASHDESCRIPTION>_009f11d8,0x11);
  FUN_00401740(s_<NORMALLIMITDESC>_009f11ec,0x11);
  FUN_00401740(s_<REQSKILL>_009f1200,10);
  FUN_00401740(s_<SOCKETDESC>_009f120c,0xc);
  FUN_00401740(s_<VALUE>_009f121c,7);
  FUN_00401740(s_<STATUSDESC>_009f1224,0xc);
  *(undefined1 *)(in_ECX + 0x1a9) = 0x20;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0074a000 @ 0x0074a000 ====

undefined4 FUN_0074a000(int *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 auStack_d4 [4];
  void *pvStack_d0;
  undefined4 uStack_c0;
  uint uStack_bc;
  undefined4 auStack_b8 [41];
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009933b5;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  iVar2 = (**(code **)(*param_1 + 0x48))();
  if (iVar2 != 0) {
    puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x2c))();
    puVar5 = auStack_b8;
    for (iVar2 = 0x27; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    ExceptionList = pvStack_14;
    return auStack_b8[2];
  }
  uStack_bc = 0xf;
  uStack_c0 = 0;
  pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
  FUN_00401740(s_pFlyWeight____NULL_009f1234,0x12);
  uStack_c = 0;
  FUN_00406880(auStack_d4);
  uStack_c = 0xffffffff;
  if (uStack_bc < 0x10) {
    uStack_bc = 0xf;
    uStack_c0 = 0;
    pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_d0);
  return extraout_EAX;
}


// ==== FUN_0074a0d0 @ 0x0074a0d0 ====

uint FUN_0074a0d0(int *param_1)

{
  code *pcVar1;
  int iVar2;
  uint extraout_EAX;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 auStack_d4 [4];
  void *pvStack_d0;
  undefined4 uStack_c0;
  uint uStack_bc;
  undefined4 auStack_b8 [4];
  ushort uStack_a8;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009933ca;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  iVar2 = (**(code **)(*param_1 + 0x48))();
  if (iVar2 != 0) {
    puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x2c))();
    puVar5 = auStack_b8;
    for (iVar2 = 0x27; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    ExceptionList = pvStack_14;
    return (uint)uStack_a8;
  }
  uStack_bc = 0xf;
  uStack_c0 = 0;
  pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
  FUN_00401740(s_pFlyWeight____NULL_009f1248,0x12);
  uStack_c = 0;
  FUN_00406880(auStack_d4);
  uStack_c = 0xffffffff;
  if (uStack_bc < 0x10) {
    uStack_bc = 0xf;
    uStack_c0 = 0;
    pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_d0);
  return extraout_EAX;
}


// ==== FUN_0074a1a0 @ 0x0074a1a0 ====

undefined4 FUN_0074a1a0(int *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 auStack_d4 [4];
  void *pvStack_d0;
  undefined4 uStack_c0;
  uint uStack_bc;
  undefined4 auStack_b8 [41];
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009933df;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  iVar2 = (**(code **)(*param_1 + 0x48))();
  if (iVar2 != 0) {
    puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x2c))();
    puVar5 = auStack_b8;
    for (iVar2 = 0x27; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    ExceptionList = pvStack_14;
    return auStack_b8[0];
  }
  uStack_bc = 0xf;
  uStack_c0 = 0;
  pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
  FUN_00401740(s_pFlyWeight____NULL_009f125c,0x12);
  uStack_c = 0;
  FUN_00406880(auStack_d4);
  uStack_c = 0xffffffff;
  if (uStack_bc < 0x10) {
    uStack_bc = 0xf;
    uStack_c0 = 0;
    pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_d0);
  return extraout_EAX;
}


// ==== FUN_0074a270 @ 0x0074a270 ====

undefined4 FUN_0074a270(int *param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined1 auStack_d4 [4];
  void *pvStack_d0;
  undefined4 uStack_c0;
  uint uStack_bc;
  undefined4 auStack_b8 [41];
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009933f4;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  iVar2 = (**(code **)(*param_1 + 0x48))();
  if (iVar2 != 0) {
    puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x2c))();
    puVar5 = auStack_b8;
    for (iVar2 = 0x27; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    ExceptionList = pvStack_14;
    return auStack_b8[1];
  }
  uStack_bc = 0xf;
  uStack_c0 = 0;
  pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
  FUN_00401740(s_pFlyWeight____NULL_009f1270,0x12);
  uStack_c = 0;
  FUN_00406880(auStack_d4);
  uStack_c = 0xffffffff;
  if (uStack_bc < 0x10) {
    uStack_bc = 0xf;
    uStack_c0 = 0;
    pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  _free(pvStack_d0);
  return extraout_EAX;
}


// ==== FUN_0074a340 @ 0x0074a340 ====

void FUN_0074a340(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
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
  puStack_8 = &LAB_0099340e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar3 == 0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f12ac,0xb);
    uStack_4 = 0;
    FUN_00406880(auStack_28);
    uStack_4 = 0xffffffff;
    if (uStack_10 < 0x10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    _free(pvStack_24);
    return;
  }
  piVar1 = *(int **)(iVar3 + 0x1c);
  if (piVar1 != (int *)0x0) {
    uVar4 = (**(code **)(*piVar1 + 0x1c))();
    iVar3 = FUN_00803725(uVar4,0,&Framework::IArticle::RTTI_Type_Descriptor,
                         &Framework::Article::IItem::RTTI_Type_Descriptor,0);
    if (iVar3 != 0) {
      uVar4 = (**(code **)(*piVar1 + 0x18))();
      FUN_00803725(uVar4,0,&Framework::IArticle::RTTI_Type_Descriptor,
                   &Framework::Article::IItem::RTTI_Type_Descriptor,0);
    }
    ExceptionList = pvStack_c;
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pCursor____NULL_009f12b8,0xf);
  uStack_4 = 1;
  FUN_00406880(auStack_44);
  uStack_4 = 0xffffffff;
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


// ==== FUN_0074a480 @ 0x0074a480 ====

void FUN_0074a480(void)

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
  puStack_8 = &LAB_00993428;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 == 0) {
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_00401740(s_pPC____NULL_009f12c8,0xb);
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
    uVar3 = (**(code **)(**(int **)(iVar2 + 0x1c) + 0x1c))();
    FUN_00803725(uVar3,0,&Framework::IArticle::RTTI_Type_Descriptor,
                 &Framework::Article::IItem::RTTI_Type_Descriptor,0);
    ExceptionList = pvStack_c;
    return;
  }
  uStack_2c = 0xf;
  uStack_30 = 0;
  pvStack_40 = (void *)((uint)pvStack_40 & 0xffffff00);
  FUN_00401740(s_pCursor____NULL_009f12d4,0xf);
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


// ==== FUN_0074a5a0 @ 0x0074a5a0 ====

void FUN_0074a5a0(undefined4 param_1)

{
  code *pcVar1;
  int iVar2;
  undefined1 auStack_28 [4];
  void *pvStack_24;
  void *pvStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099343a;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*DAT_00b5a980 + 8))();
  if (iVar2 != 0) {
    (**(code **)(*DAT_00b5a734 + 0x14))(iVar2,param_1);
    ExceptionList = pvStack_14;
    return;
  }
  uStack_10 = 0xf;
  pvStack_14 = (void *)0x0;
  pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
  FUN_00401740(s_pPC____NULL_009f12e4,0xb);
  uStack_4 = 0;
  FUN_00406880(auStack_28);
  uStack_4 = 0xffffffff;
  if (uStack_10 < 0x10) {
    uStack_10 = 0xf;
    pvStack_14 = (void *)0x0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(pvStack_24);
  return;
}


// ==== FUN_0074a650 @ 0x0074a650 ====

int FUN_0074a650(int param_1,int *param_2)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  int extraout_EAX;
  undefined4 *puVar4;
  char *pcVar5;
  int extraout_EAX_00;
  undefined4 *puVar6;
  undefined1 auStack_f4 [4];
  void *pvStack_f0;
  undefined4 uStack_e0;
  uint uStack_dc;
  undefined1 auStack_d8 [4];
  void *pvStack_d4;
  undefined4 uStack_c4;
  uint uStack_c0;
  undefined4 local_bc;
  undefined4 auStack_b8 [12];
  char acStack_86 [114];
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0099345a;
  pvStack_14 = ExceptionList;
  local_bc = 0;
  ExceptionList = &pvStack_14;
  iVar3 = (**(code **)(*param_2 + 0x48))();
  if (iVar3 == 0) {
    uStack_c0 = 0xf;
    uStack_c4 = 0;
    pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
    FUN_00401740(s_pFlyWeight____NULL_009f12f0,0x12);
    uStack_c = 0;
    FUN_00406880(auStack_d8);
    uStack_c = 0xffffffff;
    if (uStack_c0 < 0x10) {
      pcVar2 = (code *)swi(3);
      iVar3 = (*pcVar2)();
      return iVar3;
    }
    _free(pvStack_d4);
    return extraout_EAX;
  }
  puVar4 = (undefined4 *)(**(code **)(*param_2 + 0x2c))();
  puVar6 = auStack_b8;
  for (iVar3 = 0x27; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  uStack_dc = 0xf;
  uStack_e0 = 0;
  pvStack_f0 = (void *)((uint)pvStack_f0 & 0xffffff00);
  pcVar5 = acStack_86;
  uStack_c = 1;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_004020e0(acStack_86,(int)pcVar5 - (int)(acStack_86 + 1));
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(auStack_f4,0,0xffffffff);
  if (uStack_dc < 0x10) {
    ExceptionList = pvStack_14;
    return param_1;
  }
  _free(pvStack_f0);
  return extraout_EAX_00;
}


// ==== FUN_0074a780 @ 0x0074a780 ====

int FUN_0074a780(int param_1,int *param_2)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  int extraout_EAX;
  int *piVar4;
  int extraout_EAX_00;
  undefined4 uVar5;
  char *pcVar6;
  int extraout_EAX_01;
  int *piVar7;
  void *pvStack_114;
  undefined1 auStack_108 [4];
  undefined4 uStack_104;
  uint uStack_100;
  void *pvStack_f8;
  undefined1 auStack_ec [4];
  undefined4 uStack_e8;
  uint uStack_e4;
  undefined1 auStack_cc [36];
  int aiStack_a8 [12];
  char acStack_76 [74];
  undefined1 uStack_2c;
  undefined1 uStack_24;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993514;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*param_2 + 0x48))();
  if (iVar3 == 0) {
    uStack_100 = 0xf;
    uStack_104 = 0;
    pvStack_114 = (void *)((uint)pvStack_114 & 0xffffff00);
    FUN_00401740();
    uStack_4 = 0;
    FUN_00406880();
    uStack_4 = 0xffffffff;
    if (uStack_100 < 0x10) {
      pcVar2 = (code *)swi(3);
      iVar3 = (*pcVar2)();
      return iVar3;
    }
    _free(pvStack_114);
    return extraout_EAX;
  }
  piVar4 = (int *)(**(code **)(*param_2 + 0x2c))();
  piVar7 = aiStack_a8;
  for (iVar3 = 0x27; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar7 = *piVar4;
    piVar4 = piVar4 + 1;
    piVar7 = piVar7 + 1;
  }
  uStack_e4 = 0xf;
  uStack_e8 = 0;
  pvStack_f8 = (void *)((uint)pvStack_f8 & 0xffffff00);
  uStack_4 = 1;
  FUN_004020e0();
  if (aiStack_a8[0] == 3) {
    FUN_004020e0();
    FUN_00401740();
    (**(code **)(*DAT_00b5ad18 + 8))();
    uStack_4._0_1_ = 2;
  }
  else if (aiStack_a8[0] == 4) {
    FUN_004020e0();
    FUN_00401740();
    (**(code **)(*DAT_00b5ad18 + 8))();
    uStack_4._0_1_ = 3;
  }
  else {
    if (aiStack_a8[0] != 1) {
      if (aiStack_a8[0] == 2) {
        FUN_004021f0();
        FUN_00401830();
        uVar5 = (**(code **)(*DAT_00b5ad18 + 8))();
        uStack_24 = 5;
        FUN_00401ff0(uVar5);
LAB_0074ac0c:
        uStack_24 = 1;
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      if (aiStack_a8[1] != 1) {
        FUN_004021f0();
        iVar3 = (**(code **)(*param_2 + 0x14))();
        if (*(char *)(iVar3 + 0x1f) != '\x01') {
          iVar3 = (**(code **)(*param_2 + 0x14))();
          if (*(char *)(iVar3 + 0x1f) != '\x02') {
            iVar3 = (**(code **)(*param_2 + 0x14))();
            if (*(char *)(iVar3 + 0x1f) == '\x03') {
              (**(code **)(*DAT_00b5a794 + 0xc))();
              FUN_00765c50();
              pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,9);
              FUN_00401830(s_purpul1_009f13a4);
              uVar5 = (**(code **)(*DAT_00b5ad18 + 8))(&uStack_e8);
              uStack_2c = 10;
              uVar5 = FUN_00405bd0(auStack_ec,uVar5);
              uStack_2c = 0xb;
              FUN_00401ff0(uVar5,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
              FUN_00446f10();
            }
            iVar3 = (**(code **)(*param_2 + 0x14))();
            if (*(char *)(iVar3 + 0x1f) != '\x04') {
              iVar3 = (**(code **)(*param_2 + 0x14))();
              if (*(byte *)(iVar3 + 0x1f) < 5) {
                FUN_00401830();
                uVar5 = (**(code **)(*DAT_00b5ad18 + 8))();
                uStack_24 = 0xf;
                FUN_00401ff0(uVar5);
                goto LAB_0074ac0c;
              }
              FUN_004021f0();
              goto LAB_0074ac19;
            }
            (**(code **)(*DAT_00b5a794 + 0xc))();
            FUN_00765c50();
            pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,0xc);
            FUN_00401830(s_yellow1_009f13ac);
            uVar5 = (**(code **)(*DAT_00b5ad18 + 8))(auStack_cc);
            uStack_2c = 0xd;
            uVar5 = FUN_00405bd0(auStack_108,uVar5);
            uStack_2c = 0xe;
            goto LAB_0074abe9;
          }
        }
        (**(code **)(*DAT_00b5a794 + 0xc))();
        FUN_00765c50();
        pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,6);
        FUN_00401830(s_blue1_009f139c);
        uVar5 = (**(code **)(*DAT_00b5ad18 + 8))(auStack_cc);
        uStack_2c = 7;
        uVar5 = FUN_00405bd0(auStack_108,uVar5);
        uStack_2c = 8;
LAB_0074abe9:
        FUN_00401ff0(uVar5,0,0xffffffff);
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
      FUN_004021f0();
      FUN_004021f0();
      goto LAB_0074ac19;
    }
    FUN_004020e0();
    FUN_00401830();
    (**(code **)(*DAT_00b5ad18 + 8))();
    uStack_4._0_1_ = 4;
  }
  FUN_00401ff0();
  uStack_4 = CONCAT31(uStack_4._1_3_,1);
  if (0xf < uStack_100) {
    _free(pvStack_114);
    return extraout_EAX_00;
  }
LAB_0074ac19:
  pcVar6 = acStack_76;
  do {
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_004020e0();
  FUN_004020e0();
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660();
  if (uStack_e4 < 0x10) {
    ExceptionList = pvStack_c;
    return param_1;
  }
  _free(pvStack_f8);
  return extraout_EAX_01;
}


// ==== FUN_0074aca0 @ 0x0074aca0 ====

void FUN_0074aca0(char param_1)

{
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00993526;
  local_c = ExceptionList;
  if (param_1 == '\x01') {
    *(undefined1 *)(in_ECX + 0x694) = 0;
    *(byte *)(in_ECX + 0x695) = *(byte *)(in_ECX + 0x6a4) >> 1;
    return;
  }
  if (param_1 == '\x02') {
    *(undefined1 *)(in_ECX + 0x694) = 0;
    *(undefined1 *)(in_ECX + 0x695) = 0;
    *(undefined1 *)(in_ECX + 0x698) = 0;
    *(undefined1 *)(in_ECX + 0x699) = *(undefined1 *)(in_ECX + 0x6a4);
    return;
  }
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  ExceptionList = &local_c;
  FUN_00401740(&DAT_009f1450,0x13);
  local_4 = 0;
  FUN_00403e50(local_28);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_0074ad80 @ 0x0074ad80 ====

void FUN_0074ad80(char param_1)

{
  byte bVar1;
  int in_ECX;
  undefined1 local_28 [4];
  void *local_24;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00993538;
  local_c = ExceptionList;
  if (param_1 == '\x01') {
    *(undefined1 *)(in_ECX + 0x694) = 0;
    *(undefined1 *)(in_ECX + 0x695) = *(undefined1 *)(in_ECX + 0x6a4);
    return;
  }
  if (param_1 == '\x02') {
    bVar1 = *(byte *)(in_ECX + 0x6a4) >> 1;
    *(byte *)(in_ECX + 0x695) = bVar1;
    *(undefined1 *)(in_ECX + 0x694) = 0;
    *(undefined1 *)(in_ECX + 0x698) = 0;
    *(byte *)(in_ECX + 0x699) = bVar1 + *(byte *)(in_ECX + 0x6a4);
    return;
  }
  if (param_1 == '\x03') {
    *(char *)(in_ECX + 0x699) = *(char *)(in_ECX + 0x6a4);
    *(undefined1 *)(in_ECX + 0x694) = 0;
    *(undefined1 *)(in_ECX + 0x695) = 0;
    *(undefined1 *)(in_ECX + 0x698) = 0;
    *(undefined1 *)(in_ECX + 0x69c) = 0;
    *(char *)(in_ECX + 0x69d) = *(char *)(in_ECX + 0x6a4) * '\x02';
    return;
  }
  ExceptionList = &local_c;
  FUN_00401830(&DAT_009f1464);
  local_4 = 0;
  FUN_00403e50(local_28);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return;
  }
  _free(local_24);
  return;
}


// ==== FUN_0074ae90 @ 0x0074ae90 ====

void FUN_0074ae90(char param_1)

{
  char cVar1;
  int in_ECX;
  byte bVar2;
  byte bVar3;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099354a;
  local_c = ExceptionList;
  if (param_1 == '\x01') {
    *(undefined1 *)(in_ECX + 0x694) = 0;
    *(byte *)(in_ECX + 0x695) = (*(byte *)(in_ECX + 0x6a4) >> 1) + *(byte *)(in_ECX + 0x6a4);
    return;
  }
  if (param_1 == '\x02') {
    bVar2 = *(byte *)(in_ECX + 0x6a4) >> 1;
    *(undefined1 *)(in_ECX + 0x694) = 0;
    *(undefined1 *)(in_ECX + 0x698) = 0;
    *(byte *)(in_ECX + 0x695) = bVar2;
    *(byte *)(in_ECX + 0x699) = *(byte *)(in_ECX + 0x6a4) * '\x02' + bVar2;
    return;
  }
  if (param_1 == '\x03') {
    bVar2 = *(byte *)(in_ECX + 0x6a4);
    bVar3 = bVar2 >> 1;
    *(undefined1 *)(in_ECX + 0x694) = 0;
    *(undefined1 *)(in_ECX + 0x698) = 0;
    *(byte *)(in_ECX + 0x699) = bVar3 + bVar2;
    *(byte *)(in_ECX + 0x695) = bVar3;
    *(undefined1 *)(in_ECX + 0x69c) = 0;
    *(byte *)(in_ECX + 0x69d) = bVar2 * '\x02' + bVar3;
    return;
  }
  if (param_1 != '\x04') {
    ExceptionList = &local_c;
    FUN_00401830(&DAT_009f1478);
    local_4 = 0;
    FUN_00403e50(local_28);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  cVar1 = *(char *)(in_ECX + 0x6a4);
  *(undefined1 *)(in_ECX + 0x694) = 0;
  *(undefined1 *)(in_ECX + 0x695) = 0;
  *(undefined1 *)(in_ECX + 0x698) = 0;
  *(undefined1 *)(in_ECX + 0x69c) = 0;
  *(undefined1 *)(in_ECX + 0x6a0) = 0;
  *(char *)(in_ECX + 0x699) = cVar1;
  *(char *)(in_ECX + 0x69d) = cVar1 * '\x02';
  *(char *)(in_ECX + 0x6a1) = cVar1 * '\x03';
  return;
}


// ==== FUN_0074b000 @ 0x0074b000 ====

void FUN_0074b000(char param_1)

{
  undefined1 uVar1;
  byte bVar2;
  int in_ECX;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099355c;
  local_c = ExceptionList;
  if (param_1 == '\x01') {
    bVar2 = *(byte *)(in_ECX + 0x6a4) >> 1;
    *(byte *)(in_ECX + 0x694) = bVar2;
    *(byte *)(in_ECX + 0x695) = bVar2;
    return;
  }
  if (param_1 == '\x02') {
    bVar2 = *(byte *)(in_ECX + 0x6a4) >> 1;
    *(byte *)(in_ECX + 0x694) = bVar2;
    *(undefined1 *)(in_ECX + 0x695) = 0;
    *(byte *)(in_ECX + 0x698) = bVar2;
    *(byte *)(in_ECX + 0x699) = *(byte *)(in_ECX + 0x6a4);
    return;
  }
  if (param_1 == '\x03') {
    bVar2 = *(byte *)(in_ECX + 0x6a4);
    *(undefined1 *)(in_ECX + 0x694) = 0;
    *(undefined1 *)(in_ECX + 0x695) = 0;
    *(undefined1 *)(in_ECX + 0x699) = 0;
    *(byte *)(in_ECX + 0x698) = bVar2;
    *(byte *)(in_ECX + 0x69c) = bVar2 >> 1;
    *(byte *)(in_ECX + 0x69d) = bVar2;
    return;
  }
  if (param_1 != '\x04') {
    ExceptionList = &local_c;
    FUN_00401830(&DAT_009f148c);
    local_4 = 0;
    FUN_00403e50(local_28);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  uVar1 = *(undefined1 *)(in_ECX + 0x6a4);
  *(undefined1 *)(in_ECX + 0x694) = 0;
  *(undefined1 *)(in_ECX + 0x695) = 0;
  *(undefined1 *)(in_ECX + 0x698) = uVar1;
  *(undefined1 *)(in_ECX + 0x699) = 0;
  *(undefined1 *)(in_ECX + 0x69c) = 0;
  *(undefined1 *)(in_ECX + 0x69d) = uVar1;
  *(undefined1 *)(in_ECX + 0x6a0) = uVar1;
  *(undefined1 *)(in_ECX + 0x6a1) = uVar1;
  return;
}


// ==== FUN_0074b150 @ 0x0074b150 ====

void FUN_0074b150(char param_1)

{
  byte bVar1;
  int in_ECX;
  byte bVar2;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0099356e;
  local_c = ExceptionList;
  if (param_1 == '\x01') {
    *(byte *)(in_ECX + 0x694) = *(byte *)(in_ECX + 0x6a4) >> 1;
    *(byte *)(in_ECX + 0x695) = *(byte *)(in_ECX + 0x6a4);
    return;
  }
  if (param_1 == '\x02') {
    bVar1 = *(byte *)(in_ECX + 0x6a4) >> 1;
    *(byte *)(in_ECX + 0x694) = bVar1;
    *(byte *)(in_ECX + 0x695) = bVar1;
    *(byte *)(in_ECX + 0x698) = bVar1;
    *(byte *)(in_ECX + 0x699) = bVar1 + *(byte *)(in_ECX + 0x6a4);
    return;
  }
  if (param_1 == '\x03') {
    bVar1 = *(byte *)(in_ECX + 0x6a4);
    bVar2 = bVar1 >> 1;
    *(byte *)(in_ECX + 0x699) = bVar1;
    *(byte *)(in_ECX + 0x694) = bVar2;
    *(undefined1 *)(in_ECX + 0x695) = 0;
    *(byte *)(in_ECX + 0x698) = bVar2;
    *(byte *)(in_ECX + 0x69c) = bVar2;
    *(byte *)(in_ECX + 0x69d) = bVar1 * '\x02';
    return;
  }
  if (param_1 != '\x04') {
    ExceptionList = &local_c;
    FUN_00401830(&DAT_009f14a0);
    local_4 = 0;
    FUN_00403e50(local_28);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  bVar1 = *(byte *)(in_ECX + 0x6a4);
  bVar2 = bVar1 >> 1;
  *(byte *)(in_ECX + 0x695) = bVar2;
  *(byte *)(in_ECX + 0x699) = bVar2;
  *(undefined1 *)(in_ECX + 0x694) = 0;
  *(byte *)(in_ECX + 0x698) = bVar1;
  *(undefined1 *)(in_ECX + 0x69c) = 0;
  *(byte *)(in_ECX + 0x69d) = bVar2 + bVar1;
  *(byte *)(in_ECX + 0x6a0) = bVar1;
  *(byte *)(in_ECX + 0x6a1) = bVar2 + bVar1;
  return;
}


// ==== FUN_0074b2b0 @ 0x0074b2b0 ====

void FUN_0074b2b0(char param_1)

{
  byte bVar1;
  byte bVar2;
  int in_ECX;
  undefined1 local_28 [28];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00993580;
  local_c = ExceptionList;
  if (param_1 == '\x01') {
    bVar1 = *(byte *)(in_ECX + 0x6a4) >> 1;
    *(byte *)(in_ECX + 0x694) = bVar1;
    *(byte *)(in_ECX + 0x695) = bVar1 + *(byte *)(in_ECX + 0x6a4);
    return;
  }
  if (param_1 == '\x02') {
    bVar1 = *(byte *)(in_ECX + 0x6a4) >> 1;
    *(byte *)(in_ECX + 0x694) = bVar1;
    *(byte *)(in_ECX + 0x695) = bVar1;
    *(byte *)(in_ECX + 0x698) = bVar1;
    *(byte *)(in_ECX + 0x699) = *(byte *)(in_ECX + 0x6a4) * '\x02' + bVar1;
    return;
  }
  if (param_1 == '\x03') {
    bVar1 = *(byte *)(in_ECX + 0x6a4);
    bVar2 = bVar1 >> 1;
    *(byte *)(in_ECX + 0x699) = bVar2 + bVar1;
    *(byte *)(in_ECX + 0x694) = bVar2;
    *(byte *)(in_ECX + 0x695) = bVar2;
    *(byte *)(in_ECX + 0x698) = bVar2;
    *(byte *)(in_ECX + 0x69c) = bVar2;
    *(byte *)(in_ECX + 0x69d) = bVar1 * '\x02' + bVar2;
    return;
  }
  if (param_1 != '\x04') {
    ExceptionList = &local_c;
    FUN_00401830(&DAT_009f14b4);
    local_4 = 0;
    FUN_00403e50(local_28);
                    /* WARNING: Subroutine does not return */
    FUN_00446f10();
  }
  bVar1 = *(byte *)(in_ECX + 0x6a4);
  bVar2 = bVar1 >> 1;
  *(byte *)(in_ECX + 0x694) = bVar2;
  *(byte *)(in_ECX + 0x698) = bVar2;
  *(byte *)(in_ECX + 0x69c) = bVar2;
  *(byte *)(in_ECX + 0x6a0) = bVar2;
  *(byte *)(in_ECX + 0x699) = bVar1;
  *(byte *)(in_ECX + 0x69d) = bVar1 * '\x02';
  *(undefined1 *)(in_ECX + 0x695) = 0;
  *(byte *)(in_ECX + 0x6a1) = bVar1 * '\x03';
  return;
}


// ==== FUN_0074b4c0 @ 0x0074b4c0 ====

void FUN_0074b4c0(int *param_1)

{
  ulonglong uVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  int unaff_EBP;
  uint uVar8;
  undefined1 auStack_ac [4];
  undefined1 uStack_a8;
  undefined4 uStack_9c;
  uint *puStack_98;
  undefined1 *puStack_94;
  uint uStack_68;
  void *pvStack_64;
  undefined4 uStack_54;
  uint uStack_50;
  undefined1 auStack_4c [4];
  void *pvStack_48;
  undefined1 uStack_40;
  uint uStack_34;
  undefined4 uStack_30;
  void *pvStack_2c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *puStack_4;
  
  puStack_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_009935ba;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  puVar2 = (uint *)(**(code **)(*param_1 + 0x7c))();
  uVar7 = *puVar2;
  uStack_68 = puVar2[1];
  pvStack_64 = (void *)puVar2[2];
  if (uVar7 == 0) {
    *(undefined1 *)(in_ECX + 0x40) = 0;
    ExceptionList = pvStack_c;
    return;
  }
  uVar8 = 0;
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  uVar4 = (**(code **)(*param_1 + 0x88))();
  if (uVar4 < uVar3) {
    iVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    iVar6 = (**(code **)(*param_1 + 0x88))();
    uVar8 = (uint)(iVar5 - iVar6) / 1000;
    if (uVar7 < uVar8) {
      uVar7 = 0;
      goto LAB_0074b576;
    }
  }
  uVar7 = uVar7 - uVar8;
LAB_0074b576:
  uVar1 = (ulonglong)(uVar7 / 0x3c) / 0x3c;
  pvStack_2c = (void *)0xf;
  uStack_30 = 0;
  uStack_40 = 0;
  puStack_4 = (undefined1 *)0x0;
  puStack_98 = (uint *)(**(code **)(*DAT_00b5a794 + 0xc))();
  puStack_94 = (undefined1 *)0x0;
  uStack_50 = 0xf;
  uStack_54 = 0;
  pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
  uStack_9c = 0x74b5e2;
  FUN_00401660();
  puStack_94 = (undefined1 *)0x0;
  puStack_98 = &uStack_68;
  pvStack_c._0_1_ = 1;
  uStack_9c = 0x74b5fb;
  FUN_00401660();
  if ((int)(uVar1 / 0x18) != 0) {
    puStack_94 = (undefined1 *)0xf;
    puStack_98 = (uint *)0x0;
    uStack_a8 = 0;
    FUN_00401740(&DAT_009f14c8,3);
    puStack_98 = (uint *)FUN_00404230(&uStack_30);
    puStack_94 = (undefined1 *)0x0;
    pvStack_c._0_1_ = 2;
    uStack_9c = 0x74b644;
    FUN_00401ff0();
    pvStack_c._0_1_ = 1;
    if (0xf < uStack_18) {
      puStack_94 = (undefined1 *)0x74b661;
      _free(pvStack_2c);
      return;
    }
    puStack_94 = (undefined1 *)0x5;
    puStack_98 = (uint *)0x74b676;
    puStack_98 = (uint *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_94 = (undefined1 *)0x0;
    uStack_9c = 0x74b683;
    FUN_00401660();
    puStack_94 = (undefined1 *)0x0;
    puStack_98 = &uStack_68;
    uStack_9c = 0x74b694;
    FUN_00401ff0();
  }
  if ((int)(uVar1 % 0x18) != 0) {
    puStack_94 = (undefined1 *)0xf;
    puStack_98 = (uint *)0x0;
    uStack_a8 = 0;
    FUN_00401740(&DAT_009f14cc,3);
    puStack_98 = (uint *)FUN_00404230(&uStack_30);
    puStack_94 = (undefined1 *)0x0;
    pvStack_c._0_1_ = 3;
    uStack_9c = 0x74b6ef;
    FUN_00401ff0();
    pvStack_c._0_1_ = 1;
    if (0xf < uStack_18) {
      puStack_94 = (undefined1 *)0x74b707;
      _free(pvStack_2c);
      return;
    }
    puStack_94 = (undefined1 *)0x5;
    puStack_98 = (uint *)0x74b71c;
    puStack_98 = (uint *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_94 = (undefined1 *)0x0;
    uStack_9c = 0x74b729;
    FUN_00401660();
    puStack_94 = (undefined1 *)0x0;
    puStack_98 = &uStack_68;
    uStack_9c = 0x74b73a;
    FUN_00401ff0();
  }
  if (puStack_4 != (undefined1 *)0x0) {
    puStack_4 = auStack_ac;
    puStack_94 = (undefined1 *)0xf;
    puStack_98 = (uint *)0x0;
    uStack_a8 = 0;
    FUN_00401740(&DAT_009f14d0,3);
    puStack_98 = (uint *)FUN_00404230(&uStack_30);
    puStack_94 = (undefined1 *)0x0;
    pvStack_c._0_1_ = 4;
    uStack_9c = 0x74b78d;
    FUN_00401ff0();
    pvStack_c._0_1_ = 1;
    if (0xf < uStack_18) {
      puStack_94 = (undefined1 *)0x74b7a5;
      _free(pvStack_2c);
      return;
    }
    puStack_94 = (undefined1 *)0x5;
    puStack_98 = (uint *)0x74b7ba;
    puStack_98 = (uint *)(**(code **)(*DAT_00b5a794 + 0xc))();
    puStack_94 = (undefined1 *)0x0;
    uStack_9c = 0x74b7c7;
    FUN_00401660();
    puStack_94 = (undefined1 *)0x0;
    puStack_98 = &uStack_68;
    uStack_9c = 0x74b7d8;
    FUN_00401ff0();
  }
  pvStack_c = (void *)((uint)pvStack_c._1_3_ << 8);
  if (0xf < uStack_50) {
    puStack_94 = (undefined1 *)0x74b7ef;
    _free(pvStack_64);
    return;
  }
  puStack_94 = auStack_4c;
  puStack_98 = &uStack_30;
  uStack_9c = 0x74b806;
  puStack_98 = (uint *)FUN_00402220();
  puStack_94 = (undefined1 *)0x0;
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,5);
  uStack_9c = 0x74b821;
  FUN_00401660();
  if (0xf < uStack_18) {
    puStack_94 = (undefined1 *)0x74b831;
    _free(pvStack_2c);
    return;
  }
  *(undefined1 *)(unaff_EBP + 0x40) = 1;
  if (uStack_34 < 0x10) {
    ExceptionList = pvStack_14;
    return;
  }
  puStack_94 = (undefined1 *)0x74b848;
  _free(pvStack_48);
  return;
}


// ==== FUN_0074b860 @ 0x0074b860 ====

/* WARNING: Removing unreachable block (ram,0x0074b952) */

void FUN_0074b860(void)

{
  int in_ECX;
  undefined1 auStack_62 [26];
  void *pvStack_48;
  uint uStack_34;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009935dc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  pvStack_c = (void *)0x0;
  FUN_00401660(auStack_62 + -6,0,0xffffffff);
  FUN_00404230(auStack_30);
  pvStack_c._0_1_ = 1;
  FUN_00402220();
  pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
  FUN_00401660();
  if (0xf < uStack_34) {
    _free(pvStack_48);
    return;
  }
  if (uStack_18 < 0x10) {
    *(undefined1 *)(in_ECX + 0x7c) = 1;
    ExceptionList = pvStack_14;
    return;
  }
  _free(pvStack_2c);
  return;
}


// ==== FUN_0074b980 @ 0x0074b980 ====

void FUN_0074b980(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  void *unaff_ESI;
  int *piVar5;
  undefined1 auStack_104 [4];
  uint uStack_e8;
  undefined1 auStack_e4 [4];
  void *pvStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  uint uStack_cc;
  int aiStack_b8 [37];
  void *pvStack_24;
  undefined1 uStack_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009935fc;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  piVar2 = (int *)(**(code **)(*param_1 + 0x2c))();
  piVar5 = aiStack_b8;
  for (iVar4 = 0x27; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar5 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar5 = piVar5 + 1;
  }
  if (aiStack_b8[1] != 4) {
    *(undefined1 *)(in_ECX + 0xb8) = 0;
    ExceptionList = pvStack_14;
    return;
  }
  uVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  uStack_d8 = 0xf;
  uStack_dc = 0;
  uStack_c = 0;
  cVar1 = (**(code **)(*DAT_00b5a734 + 0x18))(uVar3);
  if (cVar1 == '\x02') {
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(2,0x79);
  }
  else {
    uVar3 = (**(code **)(*DAT_00b5a794 + 0xc))(2,0x78);
  }
  FUN_00401660(uVar3,0,0xffffffff);
  uVar3 = FUN_00402220(auStack_e4,auStack_104 + 4,&DAT_009f14dc);
  uStack_1c = 1;
  FUN_00401660(uVar3,0,0xffffffff);
  if (0xf < uStack_cc) {
    _free(pvStack_e0);
    return;
  }
  *(undefined1 *)(param_1 + 0x2e) = 1;
  if (uStack_e8 < 0x10) {
    ExceptionList = pvStack_24;
    return;
  }
  _free(unaff_ESI);
  return;
}


// ==== FUN_0074bac0 @ 0x0074bac0 ====

int FUN_0074bac0(int param_1,uint param_2)

{
  int extraout_EAX;
  char *pcVar1;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0099360e;
  local_c = ExceptionList;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_4 = 0;
  if (param_2 < 100000) {
    ExceptionList = &local_c;
    FUN_00401740(s_FFFFFF_009f1628,6);
  }
  else if (param_2 < 1000000) {
    ExceptionList = &local_c;
    FUN_00401740(s_FF9900_009f1630,6);
  }
  else if (param_2 < 10000000) {
    ExceptionList = &local_c;
    FUN_00401740(s_00FF00_009f1638,6);
  }
  else {
    if (param_2 < 100000000) {
      pcVar1 = s_00CCFF_009f1640;
    }
    else {
      pcVar1 = s_FF00FF_009f1648;
    }
    ExceptionList = &local_c;
    FUN_00403810(pcVar1);
  }
  *(undefined4 *)(param_1 + 0x18) = 0xf;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined1 *)(param_1 + 4) = 0;
  FUN_00401660(local_28,0,0xffffffff);
  if (local_10 < 0x10) {
    ExceptionList = local_c;
    return param_1;
  }
  _free(local_24);
  return extraout_EAX;
}


// ==== FUN_0074bba0 @ 0x0074bba0 ====

void FUN_0074bba0(int param_1,int *param_2)

{
  int *piVar1;
  byte *pbVar2;
  void *in_ECX;
  uint unaff_EBX;
  int unaff_EBP;
  undefined1 *puVar3;
  undefined1 auStack_dc [24];
  undefined1 *puStack_88;
  void *local_84;
  undefined1 *puStack_80;
  undefined4 uStack_74;
  uint uStack_70;
  uint uStack_6c;
  void *pvStack_68;
  void *pvStack_64;
  undefined4 uStack_58;
  uint uStack_54;
  uint uStack_50;
  void *pvStack_48;
  undefined4 uStack_38;
  uint uStack_34;
  void *pvStack_2c;
  uint uStack_18;
  void *pvStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993668;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  local_84 = in_ECX;
  puStack_88 = (undefined1 *)(**(code **)(*param_2 + 0x2c))();
  if (*(int *)(puStack_88 + 0x18) == -1) {
    *(undefined1 *)((int)in_ECX + 0x220) = 0;
  }
  if (*(int **)(param_1 + 4) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0x18))();
  }
  pbVar2 = (byte *)(**(code **)(*piVar1 + 8))();
  puVar3 = (undefined1 *)(0x80000000 >> (*pbVar2 & 0x1f));
  puStack_80 = puVar3;
  (**(code **)(*DAT_00b5a794 + 0xc))();
  FUN_00401660();
  piVar1 = (int *)(**(code **)(*DAT_00b5abac + 8))();
  while (piVar1 != (int *)0x0) {
    pbVar2 = (byte *)(**(code **)(*piVar1 + 4))();
    if ((*(uint *)(unaff_EBP + 0x18) & 0x80000000U >> (*pbVar2 & 0x1f)) != 0) {
      FUN_004020e0();
      FUN_00402220();
      pvStack_c = (void *)0x0;
      (**(code **)(*piVar1 + 4))();
      FUN_00402220();
      pvStack_c._0_1_ = 1;
      FUN_00402220();
      pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,2);
      FUN_00401660();
      if (0xf < uStack_6c) {
        _free(puStack_80);
        return;
      }
      uStack_6c = 0xf;
      uStack_70 = 0;
      puStack_80 = (undefined1 *)((uint)puStack_80 & 0xffffff00);
      if (0xf < uStack_50) {
        _free(pvStack_64);
        return;
      }
      uStack_50 = 0xf;
      uStack_54 = 0;
      pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
      pvStack_c = (void *)0xffffffff;
      if (0xf < uStack_34) {
        _free(pvStack_48);
        return;
      }
      uStack_34 = 0xf;
      uStack_38 = 0;
      pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
      puVar3 = puStack_88;
    }
    piVar1 = (int *)(**(code **)(*DAT_00b5abac + 0xc))();
  }
  if ((*(uint *)(unaff_EBP + 0x18) & (uint)puVar3) == 0) {
    puStack_88 = auStack_dc + 0x18;
    FUN_00401740();
    (**(code **)(*DAT_00b5ad18 + 8))();
    pvStack_2c = (void *)0x3;
    FUN_00405bd0();
    pvStack_2c._0_1_ = 4;
    FUN_00402220();
    pvStack_2c = (void *)CONCAT31(pvStack_2c._1_3_,5);
    FUN_00401660();
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
    uStack_54 = 0xf;
    uStack_58 = 0;
    pvStack_68 = (void *)((uint)pvStack_68 & 0xffffff00);
    if (0xf < uStack_70) {
      _free(local_84);
      return;
    }
    uStack_70 = 0xf;
    uStack_74 = 0;
    local_84 = (void *)((uint)local_84 & 0xffffff00);
    pvStack_2c = (void *)0xffffffff;
    if (0xf < unaff_EBX) {
      _free((void *)0x2);
      return;
    }
    unaff_EBX = 0xf;
    FUN_00401740();
    pvStack_2c = (void *)0x6;
    FUN_00401740(&DAT_009f1698,4);
    (**(code **)(*DAT_00b5ad18 + 8))(&puStack_88);
    pvStack_c._0_1_ = 7;
    FUN_004022a0();
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,8);
    FUN_00404440();
    if (0xf < uStack_34) {
      _free(pvStack_48);
      return;
    }
    uStack_34 = 0xf;
    uStack_38 = 0;
    pvStack_48 = (void *)((uint)pvStack_48 & 0xffffff00);
    if (0xf < uStack_50) {
      _free(pvStack_64);
      return;
    }
    uStack_50 = 0xf;
    uStack_54 = 0;
    pvStack_64 = (void *)((uint)pvStack_64 & 0xffffff00);
    pvStack_c = (void *)0xffffffff;
    if (0xf < uStack_6c) {
      _free(puStack_80);
      return;
    }
  }
  FUN_00402220();
  pvStack_c = (void *)0x9;
  FUN_00401660();
  if (uStack_18 < 0x10) {
    *(undefined1 *)(unaff_EBX + 0x220) = 1;
    ExceptionList = pvStack_14;
    return;
  }
  _free(pvStack_2c);
  return;
}


// ==== FUN_0074c000 @ 0x0074c000 ====

void FUN_0074c000(int *param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  char *pcVar5;
  
  piVar2 = (int *)(**(code **)(*param_1 + 0x48))();
  iVar4 = *DAT_00b5ab6c;
  iVar3 = (**(code **)(*piVar2 + 4))();
  piVar2 = (int *)(**(code **)(iVar4 + 8))(*(undefined2 *)(iVar3 + 0x24));
  if (piVar2 == (int *)0x0) {
    *(undefined1 *)(in_ECX + 0x658) = 0;
    return;
  }
  *(undefined1 *)(in_ECX + 0x658) = 1;
  iVar4 = (**(code **)(*piVar2 + 4))();
  pcVar5 = (char *)(iVar4 + 0x120);
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_00401740((char *)(iVar4 + 0x120),(int)pcVar5 - (iVar4 + 0x121));
  return;
}


// ==== FUN_0074c070 @ 0x0074c070 ====

void FUN_0074c070(int *param_1)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined2 *puVar8;
  undefined4 *puVar9;
  undefined1 auStack_108 [4];
  void *pvStack_104;
  undefined4 uStack_f4;
  uint uStack_f0;
  uint uStack_ec;
  undefined1 auStack_e8 [4];
  void *pvStack_e4;
  undefined4 uStack_d4;
  uint uStack_d0;
  undefined4 uStack_cc;
  short asStack_c8 [13];
  uint uStack_ae;
  undefined4 auStack_a8 [12];
  char cStack_78;
  char cStack_77;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993693;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x14))();
  iVar3 = *param_1;
  puVar9 = &uStack_cc;
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar9 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar9 = puVar9 + 1;
  }
  iVar3 = (**(code **)(iVar3 + 0x48))();
  if (iVar3 == 0) {
    uStack_f0 = 0xf;
    uStack_f4 = 0;
    pvStack_104 = (void *)((uint)pvStack_104 & 0xffffff00);
    FUN_00401740(s_pFlyWeight____NULL_009f1410,0x12);
    uStack_4 = 0;
    FUN_00406880(auStack_108);
    uStack_4 = 0xffffffff;
    if (uStack_f0 < 0x10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(pvStack_104);
    return;
  }
  puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x2c))();
  uVar7 = uStack_ae & 0xff;
  puVar9 = auStack_a8;
  for (iVar3 = 0x27; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar9 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar9 = puVar9 + 1;
  }
  iVar3 = 0;
  uVar6 = uStack_ae;
  uStack_ec = uVar7;
  if (uVar7 != 0) {
    puVar8 = (undefined2 *)(in_ECX + 0x696);
    do {
      if (asStack_c8[iVar3] == 0) {
        *puVar8 = 0;
      }
      else {
        piVar4 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(asStack_c8[iVar3]);
        if (piVar4 == (int *)0x0) {
          *puVar8 = 0;
          uStack_f0 = 0xf;
          uStack_f4 = 0;
          pvStack_104 = (void *)((uint)pvStack_104 & 0xffffff00);
          FUN_00401740(s_Invalid_Socket_Index_009f1424,0x14);
          uStack_4 = 1;
          FUN_00403e50(auStack_108);
          uStack_4 = 0xffffffff;
          if (0xf < uStack_f0) {
            _free(pvStack_104);
            return;
          }
          uStack_f0 = 0xf;
          uStack_f4 = 0;
          pvStack_104 = (void *)((uint)pvStack_104 & 0xffffff00);
          uVar7 = uStack_ec;
        }
        else {
          iVar5 = (**(code **)(*piVar4 + 4))();
          *puVar8 = *(undefined2 *)(iVar5 + 0x24);
        }
        uVar6 = uStack_ae;
      }
      iVar3 = iVar3 + 1;
      puVar8 = puVar8 + 2;
    } while (iVar3 < (int)uVar7);
  }
  if (cStack_78 == '\x01') {
    if (cStack_77 == '\x02') {
      FUN_0074aca0(uVar6);
      ExceptionList = pvStack_c;
      return;
    }
    if (cStack_77 == '\x03') {
      FUN_0074ad80(uVar6);
      ExceptionList = pvStack_c;
      return;
    }
    if (cStack_77 == '\x04') {
      FUN_0074ae90(uVar6);
      ExceptionList = pvStack_c;
      return;
    }
  }
  else if (cStack_78 == '\x02') {
    if (cStack_77 == '\x02') {
      FUN_0074b000(uVar6);
      ExceptionList = pvStack_c;
      return;
    }
    if (cStack_77 == '\x03') {
      FUN_0074b150(uVar6);
      ExceptionList = pvStack_c;
      return;
    }
    if (cStack_77 == '\x04') {
      FUN_0074b2b0(uVar6);
      ExceptionList = pvStack_c;
      return;
    }
  }
  uStack_d0 = 0xf;
  uStack_d4 = 0;
  pvStack_e4 = (void *)((uint)pvStack_e4 & 0xffffff00);
  FUN_00401740(&DAT_009f143c,0x13);
  uStack_4 = 2;
  FUN_00403e50(auStack_e8);
  if (uStack_d0 < 0x10) {
    ExceptionList = pvStack_c;
    return;
  }
  _free(pvStack_e4);
  return;
}


// ==== FUN_0074c2d0 @ 0x0074c2d0 ====

char FUN_0074c2d0(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  char cVar5;
  
  pcVar1 = *(char **)(param_1 + 4);
  cVar3 = '\a';
  if (pcVar1 != (char *)0x0) {
    pcVar2 = *(char **)(param_1 + 8);
    if (pcVar2 != pcVar1) {
      cVar3 = '\a';
      if (pcVar2 == pcVar1) {
        cVar3 = FUN_004d4b70();
      }
      cVar5 = *pcVar1;
      for (uVar4 = 0; uVar4 < (uint)((int)pcVar2 - (int)pcVar1);
          uVar4 = (uint)(byte)((char)uVar4 + 1)) {
        cVar3 = pcVar1[uVar4];
        if (cVar3 != cVar5) goto LAB_0074c31c;
        cVar5 = cVar3;
      }
      if (cVar3 == '\0') {
LAB_0074c31c:
        cVar3 = '\x06';
      }
    }
  }
  return cVar3;
}


// ==== FUN_0074c330 @ 0x0074c330 ====

void FUN_0074c330(undefined4 *param_1,undefined4 param_2,byte param_3)

{
  int in_ECX;
  
  FUN_0074c070(param_2);
  *param_1 = *(undefined4 *)(in_ECX + 0x694 + (uint)param_3 * 4);
  return;
}


// ==== FUN_0074c360 @ 0x0074c360 ====

undefined4 FUN_0074c360(int *param_1)

{
  void *pvVar1;
  byte bVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int iVar6;
  uint uVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined1 auStack_f5 [5];
  int iStack_f0;
  undefined1 auStack_ec [4];
  void *pvStack_e8;
  undefined4 uStack_e4;
  undefined4 uStack_e0;
  undefined4 uStack_dc;
  undefined2 auStack_d8 [13];
  byte bStack_be;
  int aiStack_b8 [41];
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_009936a8;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  iStack_f0 = (**(code **)(*param_1 + 0x48))();
  if (iStack_f0 != 0) {
    piVar3 = (int *)(**(code **)(*param_1 + 0x2c))();
    piVar8 = aiStack_b8;
    for (iVar6 = 0x27; iVar6 != 0; iVar6 = iVar6 + -1) {
      *piVar8 = *piVar3;
      piVar3 = piVar3 + 1;
      piVar8 = piVar8 + 1;
    }
    if (aiStack_b8[1] == 4) {
      puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x14))();
      puVar9 = &uStack_dc;
      for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar9 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar9 = puVar9 + 1;
      }
      bVar2 = FUN_007498d0(iStack_f0);
      if ((bStack_be != 0) && (bVar2 <= bStack_be)) {
        pvStack_e8 = (void *)0x0;
        uStack_e4 = 0;
        uStack_e0 = 0;
        uVar7 = 0;
        uStack_c = 0;
        if (bStack_be != 0) {
          do {
            pvVar1 = pvStack_e8;
            piVar3 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(auStack_d8[uVar7]);
            if (piVar3 == (int *)0x0) {
              if (pvVar1 == (void *)0x0) {
                ExceptionList = pvStack_14;
                return 7;
              }
              _free(pvVar1);
              return extraout_EAX_00;
            }
            iVar6 = (**(code **)(*piVar3 + 4))();
            auStack_f5[0] = *(undefined1 *)(iVar6 + 0x10);
            FUN_004e1f00(auStack_f5);
            bVar2 = (char)uVar7 + 1;
            uVar7 = (uint)bVar2;
          } while (bVar2 < bStack_be);
        }
        pvVar1 = pvStack_e8;
        uVar5 = FUN_0074c2d0(auStack_ec);
        if (pvVar1 == (void *)0x0) {
          ExceptionList = pvStack_14;
          return uVar5;
        }
        _free(pvVar1);
        return extraout_EAX;
      }
    }
  }
  ExceptionList = pvStack_14;
  return 7;
}


// ==== FUN_0074c4b0 @ 0x0074c4b0 ====

/* WARNING: Removing unreachable block (ram,0x0074c703) */
/* WARNING: Removing unreachable block (ram,0x0074c6e4) */

void FUN_0074c4b0(int *param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009936e5;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*param_1 + 0x34))();
  if ((*(short *)(iVar1 + 100) == 0) && (*(short *)(iVar1 + 0x66) == 0)) {
    *(undefined1 *)(in_ECX + 0xf4) = 0;
  }
  else {
    uStack_4 = 1;
    FUN_00401740();
    FUN_00401740(&DAT_009f14e8,2);
    FUN_00404230(auStack_44);
    uStack_4._0_1_ = 2;
    FUN_00401660();
    uStack_4._0_1_ = 1;
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    FUN_004e6c20();
    FUN_00401740();
    FUN_00401740(&DAT_009f14f4,2);
    FUN_00404230(auStack_44);
    uStack_4._0_1_ = 3;
    FUN_00401660();
    uStack_4._0_1_ = 1;
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    FUN_004e6c20();
    (**(code **)(*DAT_00b5a794 + 8))();
    uStack_4._0_1_ = 4;
    FUN_00402220();
    uStack_4 = CONCAT31(uStack_4._1_3_,5);
    FUN_00401660();
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    *(undefined1 *)(in_ECX + 0xf4) = 1;
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_004e67a0();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0074c740 @ 0x0074c740 ====

/* WARNING: Removing unreachable block (ram,0x0074c993) */
/* WARNING: Removing unreachable block (ram,0x0074c974) */

void FUN_0074c740(int *param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993722;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*param_1 + 0x34))();
  if ((*(short *)(iVar1 + 0x5c) == 0) && (*(short *)(iVar1 + 0x5e) == 0)) {
    *(undefined1 *)(in_ECX + 0x130) = 0;
  }
  else {
    uStack_4 = 1;
    FUN_00401740();
    FUN_00401740(&DAT_009f1504,2);
    FUN_00404230(auStack_44);
    uStack_4._0_1_ = 2;
    FUN_00401660();
    uStack_4._0_1_ = 1;
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    FUN_004e6c20();
    FUN_00401740();
    FUN_00401740(&DAT_009f1510,2);
    FUN_00404230(auStack_44);
    uStack_4._0_1_ = 3;
    FUN_00401660();
    uStack_4._0_1_ = 1;
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    FUN_004e6c20();
    (**(code **)(*DAT_00b5a794 + 8))();
    uStack_4._0_1_ = 4;
    FUN_00402220();
    uStack_4 = CONCAT31(uStack_4._1_3_,5);
    FUN_00401660();
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    *(undefined1 *)(in_ECX + 0x130) = 1;
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_004e67a0();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0074c9d0 @ 0x0074c9d0 ====

/* WARNING: Removing unreachable block (ram,0x0074cc23) */
/* WARNING: Removing unreachable block (ram,0x0074cc04) */

void FUN_0074c9d0(int *param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 auStack_44 [4];
  void *pvStack_40;
  uint uStack_2c;
  void *pvStack_24;
  undefined4 uStack_14;
  uint uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0099375f;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*param_1 + 0x34))();
  if ((*(short *)(iVar1 + 0x60) == 0) && (*(short *)(iVar1 + 0x62) == 0)) {
    *(undefined1 *)(in_ECX + 0x16c) = 0;
  }
  else {
    uStack_4 = 1;
    FUN_00401740();
    FUN_00401740(&DAT_009f1520,2);
    FUN_00404230(auStack_44);
    uStack_4._0_1_ = 2;
    FUN_00401660();
    uStack_4._0_1_ = 1;
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    FUN_004e6c20();
    FUN_00401740();
    FUN_00401740(&DAT_009f152c,2);
    FUN_00404230(auStack_44);
    uStack_4._0_1_ = 3;
    FUN_00401660();
    uStack_4._0_1_ = 1;
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    FUN_004e6c20();
    (**(code **)(*DAT_00b5a794 + 8))();
    uStack_4._0_1_ = 4;
    FUN_00402220();
    uStack_4 = CONCAT31(uStack_4._1_3_,5);
    FUN_00401660();
    if (0xf < uStack_2c) {
      _free(pvStack_40);
      return;
    }
    *(undefined1 *)(in_ECX + 0x16c) = 1;
    if (0xf < uStack_10) {
      _free(pvStack_24);
      return;
    }
    uStack_10 = 0xf;
    uStack_14 = 0;
    pvStack_24 = (void *)((uint)pvStack_24 & 0xffffff00);
    FUN_004e67a0();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0074cc60 @ 0x0074cc60 ====

void FUN_0074cc60(int *param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 auStack_c0 [4];
  undefined1 uStack_bc;
  undefined4 uStack_b4;
  undefined1 *puStack_b0;
  undefined1 *puStack_ac;
  char *pcStack_a8;
  undefined1 auStack_80 [4];
  void *pvStack_7c;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined1 *puStack_64;
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  uint uStack_48;
  undefined1 uStack_40;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_24;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993794;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*param_1 + 0x34))();
  if (*(char *)(iVar1 + 1) == '\0') {
    *(undefined1 *)(in_ECX + 0x1a8) = 0;
  }
  else {
    uStack_2c = 0xf;
    uStack_30 = 0;
    uStack_40 = 0;
    uStack_10 = 0xf;
    uStack_14 = 0;
    uStack_24 = 0;
    pcStack_a8 = s_<VALUE>_009f1534;
    uStack_4 = 1;
    puStack_ac = (undefined1 *)0x74ccf2;
    FUN_00401740();
    puStack_64 = auStack_c0;
    pcStack_a8 = (char *)0xf;
    puStack_ac = (undefined1 *)0x0;
    uStack_bc = 0;
    FUN_00401740(&DAT_009f153c,2);
    puStack_ac = (undefined1 *)FUN_00404230(auStack_60);
    pcStack_a8 = (char *)0x0;
    uStack_4._0_1_ = 2;
    puStack_b0 = (undefined1 *)0x74cd3b;
    FUN_00401660();
    uStack_4._0_1_ = 1;
    if (0xf < uStack_48) {
      pcStack_a8 = (char *)0x74cd54;
      _free(pvStack_5c);
      return;
    }
    pcStack_a8 = (char *)0x74cd65;
    FUN_004e6c20();
    pcStack_a8 = (char *)0x68;
    puStack_ac = (undefined1 *)0x2;
    puStack_b0 = auStack_80;
    uStack_b4 = 0x74cd7e;
    (**(code **)(*DAT_00b5a794 + 8))();
    pcStack_a8 = auStack_80;
    puStack_ac = auStack_60;
    uStack_4._0_1_ = 3;
    puStack_b0 = (undefined1 *)0x74cd9a;
    puStack_ac = (undefined1 *)FUN_00402220();
    pcStack_a8 = (char *)0x0;
    uStack_4 = CONCAT31(uStack_4._1_3_,4);
    puStack_b0 = (undefined1 *)0x74cdb4;
    FUN_00401660();
    if (0xf < uStack_48) {
      pcStack_a8 = (char *)0x74cdc5;
      _free(pvStack_5c);
      return;
    }
    *(undefined1 *)(in_ECX + 0x1a8) = 1;
    if (0xf < uStack_68) {
      pcStack_a8 = (char *)0x74cde0;
      _free(pvStack_7c);
      return;
    }
    uStack_68 = 0xf;
    uStack_6c = 0;
    pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
    FUN_0040a7d0();
    FUN_004e67a0();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0074ce20 @ 0x0074ce20 ====

void FUN_0074ce20(int *param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 auStack_c0 [4];
  undefined1 uStack_bc;
  undefined4 uStack_b4;
  undefined1 *puStack_b0;
  undefined1 *puStack_ac;
  char *pcStack_a8;
  undefined1 auStack_80 [4];
  void *pvStack_7c;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined1 *puStack_64;
  undefined1 auStack_60 [4];
  void *pvStack_5c;
  uint uStack_48;
  undefined1 uStack_40;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_24;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009937c9;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar1 = (**(code **)(*param_1 + 0x34))();
  if (*(char *)(iVar1 + 0x69) == '\0') {
    *(undefined1 *)(in_ECX + 0x1e4) = 0;
  }
  else {
    uStack_2c = 0xf;
    uStack_30 = 0;
    uStack_40 = 0;
    uStack_10 = 0xf;
    uStack_14 = 0;
    uStack_24 = 0;
    pcStack_a8 = s_<VALUE>_009f1544;
    uStack_4 = 1;
    puStack_ac = (undefined1 *)0x74ceb2;
    FUN_00401740();
    puStack_64 = auStack_c0;
    pcStack_a8 = (char *)0xf;
    puStack_ac = (undefined1 *)0x0;
    uStack_bc = 0;
    FUN_00401740(&DAT_009f154c,2);
    puStack_ac = (undefined1 *)FUN_00404230(auStack_60);
    pcStack_a8 = (char *)0x0;
    uStack_4._0_1_ = 2;
    puStack_b0 = (undefined1 *)0x74cefb;
    FUN_00401660();
    uStack_4._0_1_ = 1;
    if (0xf < uStack_48) {
      pcStack_a8 = (char *)0x74cf14;
      _free(pvStack_5c);
      return;
    }
    pcStack_a8 = (char *)0x74cf25;
    FUN_004e6c20();
    pcStack_a8 = (char *)0x69;
    puStack_ac = (undefined1 *)0x2;
    puStack_b0 = auStack_80;
    uStack_b4 = 0x74cf3e;
    (**(code **)(*DAT_00b5a794 + 8))();
    pcStack_a8 = auStack_80;
    puStack_ac = auStack_60;
    uStack_4._0_1_ = 3;
    puStack_b0 = (undefined1 *)0x74cf5a;
    puStack_ac = (undefined1 *)FUN_00402220();
    pcStack_a8 = (char *)0x0;
    uStack_4 = CONCAT31(uStack_4._1_3_,4);
    puStack_b0 = (undefined1 *)0x74cf74;
    FUN_00401660();
    if (0xf < uStack_48) {
      pcStack_a8 = (char *)0x74cf85;
      _free(pvStack_5c);
      return;
    }
    *(undefined1 *)(in_ECX + 0x1e4) = 1;
    if (0xf < uStack_68) {
      pcStack_a8 = (char *)0x74cfa0;
      _free(pvStack_7c);
      return;
    }
    uStack_68 = 0xf;
    uStack_6c = 0;
    pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
    FUN_0040a7d0();
    FUN_004e67a0();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0074cfe0 @ 0x0074cfe0 ====

void FUN_0074cfe0(int param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  int *piVar3;
  ushort *puVar4;
  ushort unaff_SI;
  uint unaff_EDI;
  undefined1 *puStack_170;
  uint uStack_16c;
  undefined *puStack_168;
  undefined4 uStack_164;
  undefined2 *puStack_15c;
  undefined *puStack_158;
  undefined4 uStack_154;
  void **ppvStack_14c;
  undefined4 *puStack_148;
  undefined4 uStack_144;
  undefined1 *puStack_13c;
  undefined1 auStack_138 [8];
  undefined1 *puStack_12c;
  void ***_Memory;
  undefined4 uStack_118;
  undefined2 auStack_110 [2];
  void *pvStack_10c;
  uint uStack_108;
  undefined1 auStack_100 [4];
  void *pvStack_fc;
  uint uStack_f8;
  int iStack_f4;
  undefined4 uStack_f0;
  void *pvStack_ec;
  uint uStack_e8;
  undefined2 auStack_e4 [2];
  void *local_e0;
  void *pvStack_dc;
  uint uStack_d8;
  void *pvStack_d4;
  void *pvStack_d0;
  uint uStack_cc;
  uint uStack_c8;
  undefined4 uStack_c4;
  void *pvStack_c0;
  uint uStack_bc;
  void *pvStack_b8;
  undefined4 uStack_b0;
  uint auStack_ac [4];
  undefined1 auStack_9c [8];
  undefined4 uStack_94;
  void *pvStack_90;
  undefined1 uStack_88;
  undefined1 auStack_84 [4];
  undefined4 uStack_80;
  uint uStack_7c;
  undefined4 uStack_78;
  void *pvStack_74;
  undefined2 uStack_70;
  ushort uStack_6c;
  undefined2 auStack_68 [2];
  undefined4 uStack_64;
  uint uStack_60;
  void *pvStack_58;
  undefined4 uStack_48;
  uint uStack_44;
  void *pvStack_40;
  undefined1 auStack_3c [4];
  undefined1 uStack_38;
  undefined1 uStack_28;
  undefined1 uStack_18;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009938a6;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar2 = (**(code **)(*param_2 + 0x34))();
  auStack_110[0] = *(undefined2 *)(iVar2 + 0x6e);
  uVar1 = *(ushort *)(iVar2 + 0x6c);
  iVar2 = **(int **)(param_1 + 0x50);
  (**(code **)(*DAT_00b5a6ac + 0x20))();
  piVar3 = (int *)(**(code **)(iVar2 + 0x14))();
  puVar4 = (ushort *)(**(code **)(*piVar3 + 0x14))();
  uStack_6c = *puVar4;
  iVar2 = (**(code **)(*piVar3 + 0x14))();
  auStack_68[0] = *(undefined2 *)(iVar2 + 2);
  iVar2 = (**(code **)(*piVar3 + 0x14))();
  uStack_70 = *(undefined2 *)(iVar2 + 6);
  uStack_f0 = 0;
  pvStack_ec = (void *)0x0;
  uStack_e8 = 0;
  pvStack_90 = (void *)0xf;
  uStack_94 = 0;
  auStack_ac[2] = auStack_ac[2] & 0xffffff00;
  pvStack_74 = (void *)0xf;
  uStack_78 = 0;
  uStack_88 = 0;
  puStack_8 = (undefined1 *)0x1;
  FUN_00401740();
  _Memory = &ppvStack_14c;
  uStack_154 = &DAT_009f155c;
  puStack_148 = (undefined4 *)((uint)puStack_148 & 0xffffff00);
  puStack_158 = (undefined *)0x74d0fd;
  FUN_00401740();
  uStack_154 = (char *)0x74d107;
  FUN_00404230();
  puStack_8._0_1_ = 2;
  FUN_00401660();
  puStack_8._0_1_ = 1;
  if (0xf < uStack_c8) {
    _free(pvStack_dc);
    return;
  }
  if (uStack_6c < uVar1) {
    _Memory = (void ***)(auStack_138 + -0x18);
    uStack_154 = (char *)0x4;
    puStack_158 = &DAT_009f156c;
    ppvStack_14c = (void **)((uint)ppvStack_14c & 0xffffff00);
    puStack_15c = (undefined2 *)0x74d17b;
    FUN_00401740();
    uStack_154 = (char *)auStack_110;
    puStack_158 = (undefined *)0x74d18b;
    (**(code **)(*DAT_00b5ad18 + 8))();
    puStack_8._0_1_ = 3;
    FUN_00405bd0();
    puStack_8._0_1_ = 4;
    FUN_00402220();
    puStack_8._0_1_ = 5;
    FUN_00401660();
    if (0xf < auStack_ac[0]) {
      _free(pvStack_c0);
      return;
    }
    auStack_ac[0] = 0xf;
    uStack_b0 = 0;
    pvStack_c0 = (void *)((uint)pvStack_c0 & 0xffffff00);
    if (0xf < uStack_c8) {
      _free(pvStack_dc);
      return;
    }
    uStack_c8 = 0xf;
    uStack_cc = 0;
    pvStack_dc = (void *)((uint)pvStack_dc & 0xffffff00);
    puStack_8._0_1_ = 1;
    if (0xf < uStack_f8) {
      _free(pvStack_10c);
      return;
    }
  }
  puStack_8._0_1_ = 1;
  FUN_004e6c20();
  (**(code **)(*DAT_00b5a794 + 8))();
  uStack_18 = 6;
  FUN_004e67a0();
  uStack_144 = auStack_3c;
  puStack_148 = (undefined4 *)(auStack_110 + -8);
  ppvStack_14c = (void **)0x74d283;
  puStack_148 = (undefined4 *)FUN_00402220();
  uStack_144 = (char *)0x0;
  uStack_18 = 7;
  ppvStack_14c = (void **)0x74d2a1;
  FUN_00401660();
  uStack_18 = 6;
  if (0xf < uStack_108) {
    uStack_144 = (char *)0x74d2b9;
    _free(_Memory);
    return;
  }
  *(bool *)(iStack_f4 + 0x298) = uVar1 != 0;
  uStack_144 = s_<VALUE>_009f1578;
  puStack_148 = (undefined4 *)0x74d2df;
  FUN_00401740();
  puStack_12c = (undefined1 *)&puStack_15c;
  uStack_144 = (char *)0xf;
  puStack_148 = (undefined4 *)0x0;
  uStack_164 = (undefined4 *)&DAT_009f1580;
  puStack_158 = (undefined *)((uint)puStack_158 & 0xffffff00);
  puStack_168 = (undefined *)0x74d303;
  FUN_00401740();
  uStack_164 = (undefined4 *)0x74d30d;
  puStack_148 = (undefined4 *)FUN_00404230();
  uStack_144 = (char *)0x0;
  uStack_18 = 8;
  ppvStack_14c = (void **)0x74d328;
  FUN_00401660();
  uStack_18 = 6;
  if (0xf < uStack_108) {
    uStack_144 = (char *)0x74d340;
    _free(_Memory);
    return;
  }
  if ((ushort)uStack_78 < unaff_SI) {
    uStack_144 = auStack_9c;
    puStack_12c = auStack_138 + -0x28;
    uStack_164 = (undefined4 *)0x4;
    puStack_148 = (undefined4 *)0xf;
    ppvStack_14c = (void **)0x0;
    puStack_168 = &DAT_009f1590;
    puStack_15c = (undefined2 *)((uint)puStack_15c & 0xffffff00);
    uStack_16c = 0x74d381;
    FUN_00401740();
    uStack_164 = (undefined4 *)(auStack_110 + -8);
    puStack_168 = (undefined *)0x74d391;
    puStack_148 = (undefined4 *)(**(code **)(*DAT_00b5ad18 + 8))();
    ppvStack_14c = &pvStack_d4;
    uStack_18 = 9;
    uStack_144 = (char *)FUN_00405bd0();
    puStack_148 = &uStack_f0;
    uStack_18 = 10;
    ppvStack_14c = (void **)0x74d3ba;
    puStack_148 = (undefined4 *)FUN_00402220();
    uStack_144 = (char *)0x0;
    uStack_18 = 0xb;
    ppvStack_14c = (void **)0x74d3d5;
    FUN_00401660();
    if (0xf < uStack_d8) {
      uStack_144 = (char *)0x74d3e5;
      _free(pvStack_ec);
      return;
    }
    uStack_d8 = 0xf;
    pvStack_dc = (void *)0x0;
    pvStack_ec = (void *)((uint)pvStack_ec & 0xffffff00);
    if (0xf < uStack_bc) {
      uStack_144 = (char *)0x74d407;
      _free(pvStack_d0);
      return;
    }
    uStack_bc = 0xf;
    pvStack_c0 = (void *)0x0;
    pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
    uStack_18 = 6;
    if (0xf < uStack_108) {
      uStack_144 = (char *)0x74d431;
      _free(_Memory);
      return;
    }
  }
  uStack_18 = 6;
  uStack_144 = (char *)0x74d445;
  FUN_004e6c20();
  uStack_144 = (char *)0x6b;
  puStack_148 = (undefined4 *)0x2;
  ppvStack_14c = &pvStack_74;
  (**(code **)(*DAT_00b5a794 + 8))();
  uStack_28 = 0xc;
  FUN_004e67a0();
  uStack_154 = auStack_84;
  puStack_158 = auStack_138 + 8;
  puStack_15c = (undefined2 *)0x74d489;
  puStack_158 = (undefined *)FUN_00402220();
  uStack_154 = (char *)0x0;
  uStack_28 = 0xd;
  puStack_15c = (undefined2 *)0x74d4a3;
  FUN_00401660();
  uStack_28 = 0xc;
  if (0xf < uStack_118) {
    uStack_154 = (char *)0x74d4bb;
    _free(puStack_12c);
    return;
  }
  *(undefined1 *)(iStack_f4 + 0x2d4) = 1;
  uStack_154 = s_<VALUE>_009f159c;
  puStack_158 = (undefined *)0x74d4df;
  FUN_00401740();
  puStack_13c = (undefined1 *)&uStack_16c;
  puStack_170 = (undefined1 *)0x2;
  uStack_154 = (char *)0xf;
  puStack_158 = (undefined *)0x0;
  puStack_168 = (undefined *)((uint)puStack_168 & 0xffffff00);
  FUN_00401740(&DAT_009f15a4);
  puStack_170 = auStack_138 + 8;
  puStack_158 = (undefined *)FUN_00404230();
  uStack_154 = (char *)0x0;
  uStack_28 = 0xe;
  puStack_15c = (undefined2 *)0x74d528;
  FUN_00401660();
  uStack_28 = 0xc;
  if (0xf < uStack_118) {
    uStack_154 = (char *)0x74d540;
    _free(puStack_12c);
    return;
  }
  if ((ushort)pvStack_90 < 2) {
    uStack_154 = (char *)auStack_ac;
    puStack_13c = (undefined1 *)&puStack_170;
    puStack_158 = (undefined *)0xf;
    puStack_15c = (undefined2 *)0x0;
    uStack_16c = uStack_16c & 0xffffff00;
    FUN_00401740(&DAT_009f15b4,4);
    puStack_158 = (undefined *)(**(code **)(*DAT_00b5ad18 + 8))(auStack_138 + 8);
    puStack_15c = auStack_e4;
    uStack_28 = 0xf;
    uStack_154 = (char *)FUN_00405bd0();
    puStack_158 = auStack_100;
    uStack_28 = 0x10;
    puStack_15c = (undefined2 *)0x74d5ba;
    puStack_158 = (undefined *)FUN_00402220();
    uStack_154 = (char *)0x0;
    uStack_28 = 0x11;
    puStack_15c = (undefined2 *)0x74d5d5;
    FUN_00401660();
    if (0xf < uStack_e8) {
      uStack_154 = (char *)0x74d5e5;
      _free(pvStack_fc);
      return;
    }
    uStack_e8 = 0xf;
    pvStack_ec = (void *)0x0;
    pvStack_fc = (void *)((uint)pvStack_fc & 0xffffff00);
    if (0xf < uStack_cc) {
      uStack_154 = (char *)0x74d607;
      _free(local_e0);
      return;
    }
    uStack_cc = 0xf;
    pvStack_d0 = (void *)0x0;
    local_e0 = (void *)((uint)local_e0 & 0xffffff00);
    uStack_28 = 0xc;
    if (0xf < uStack_118) {
      uStack_154 = (char *)0x74d631;
      _free(puStack_12c);
      return;
    }
  }
  uStack_28 = 0xc;
  uStack_154 = (char *)0x74d645;
  FUN_004e6c20();
  uStack_154 = (char *)0x6c;
  puStack_158 = (undefined *)0x2;
  puStack_15c = auStack_68;
  (**(code **)(*DAT_00b5a794 + 8))();
  uStack_38 = 0x12;
  FUN_004e67a0();
  uStack_164 = &uStack_78;
  puStack_168 = auStack_138 + -8;
  uStack_16c = 0x74d689;
  puStack_168 = (undefined *)FUN_00402220();
  uStack_164 = (undefined4 *)0x0;
  uStack_38 = 0x13;
  uStack_16c = 0x74d6a3;
  FUN_00401660();
  if (0xf < unaff_EDI) {
    uStack_164 = (undefined4 *)0x74d6b3;
    _free(puStack_13c);
    return;
  }
  *(bool *)(iStack_f4 + 0x310) = (short)puStack_148 != 0;
  if (0xf < uStack_60) {
    uStack_164 = (undefined4 *)0x74d6da;
    _free(pvStack_74);
    return;
  }
  uStack_60 = 0xf;
  uStack_64 = 0;
  pvStack_74 = (void *)((uint)pvStack_74 & 0xffffff00);
  if (0xf < uStack_7c) {
    uStack_164 = (undefined4 *)0x74d708;
    _free(pvStack_90);
    return;
  }
  uStack_7c = 0xf;
  uStack_80 = 0;
  pvStack_90 = (void *)((uint)pvStack_90 & 0xffffff00);
  if (0xf < uStack_44) {
    uStack_164 = (undefined4 *)0x74d736;
    _free(pvStack_58);
    return;
  }
  uStack_44 = 0xf;
  uStack_48 = 0;
  pvStack_58 = (void *)((uint)pvStack_58 & 0xffffff00);
  if (0xf < auStack_ac[2]) {
    uStack_164 = (undefined4 *)0x74d764;
    _free(pvStack_b8);
    return;
  }
  auStack_ac[2] = 0xf;
  auStack_ac[1] = 0;
  pvStack_b8 = (void *)((uint)pvStack_b8 & 0xffffff00);
  if (pvStack_c0 < (void *)0x10) {
    pvStack_c0 = (void *)0xf;
    uStack_c4 = 0;
    pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
    FUN_004e67a0();
    ExceptionList = pvStack_40;
    return;
  }
  uStack_164 = (undefined4 *)0x74d792;
  _free(pvStack_d4);
  return;
}


// ==== FUN_0074d7d0 @ 0x0074d7d0 ====

void FUN_0074d7d0(int param_1,int *param_2)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  int *piVar4;
  ushort *puVar5;
  int in_ECX;
  void *pvStack_b0;
  uint uStack_9c;
  void *pvStack_94;
  uint uStack_80;
  undefined1 auStack_7c [4];
  void *pvStack_78;
  uint uStack_64;
  void *pvStack_5c;
  undefined4 uStack_4c;
  uint uStack_48;
  undefined1 uStack_40;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 uStack_24;
  undefined4 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009938fc;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*param_2 + 0x2c))();
  uVar1 = *(ushort *)(iVar3 + 0x28);
  if (uVar1 < 2) {
    *(undefined1 *)(in_ECX + 0x25c) = 0;
  }
  else {
    if (*(int **)(param_1 + 0x48) == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)(**(code **)(**(int **)(param_1 + 0x48) + 0x28))();
    }
    puVar5 = (ushort *)(**(code **)(*piVar4 + 8))();
    uVar2 = *puVar5;
    uStack_2c = 0xf;
    uStack_30 = 0;
    uStack_40 = 0;
    uStack_10 = 0xf;
    uStack_14 = 0;
    uStack_24 = 0;
    uStack_4 = 1;
    FUN_00401740();
    FUN_00401740(s_Lv__u_009f15c8);
    FUN_00404230();
    uStack_4._0_1_ = 2;
    FUN_00401660();
    uStack_4._0_1_ = 1;
    if (0xf < uStack_9c) {
      _free(pvStack_b0);
      return;
    }
    if (uVar2 < uVar1) {
      FUN_00401740(&DAT_009f15dc,4);
      (**(code **)(*DAT_00b5ad18 + 8))(auStack_7c);
      uStack_4._0_1_ = 3;
      FUN_00405bd0();
      uStack_4._0_1_ = 4;
      FUN_00402220();
      uStack_4._0_1_ = 5;
      FUN_00401660();
      if (0xf < uStack_48) {
        _free(pvStack_5c);
        return;
      }
      uStack_48 = 0xf;
      uStack_4c = 0;
      pvStack_5c = (void *)((uint)pvStack_5c & 0xffffff00);
      if (0xf < uStack_9c) {
        _free(pvStack_b0);
        return;
      }
      uStack_4._0_1_ = 1;
      if (0xf < uStack_64) {
        _free(pvStack_78);
        return;
      }
    }
    uStack_4._0_1_ = 1;
    FUN_004e6c20();
    (**(code **)(*DAT_00b5a794 + 8))();
    uStack_4._0_1_ = 6;
    FUN_00402220();
    uStack_4 = CONCAT31(uStack_4._1_3_,7);
    FUN_00401660();
    if (0xf < uStack_64) {
      _free(pvStack_78);
      return;
    }
    *(undefined1 *)(in_ECX + 0x25c) = 1;
    if (0xf < uStack_80) {
      _free(pvStack_94);
      return;
    }
    FUN_0040a7d0();
    FUN_004e67a0();
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0074dad0 @ 0x0074dad0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0074dad0(void)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  uint unaff_EBP;
  uint uVar5;
  float fVar6;
  undefined4 *puStack_144;
  undefined4 uStack_140;
  undefined4 uStack_124;
  void *pvStack_120;
  undefined4 uStack_118;
  undefined4 uStack_114;
  uint uStack_110;
  uint uStack_10c;
  void *pvStack_108;
  void *pvStack_104;
  void *pvStack_f8;
  uint uStack_f4;
  void *pvStack_f0;
  void *pvStack_ec;
  void *pvStack_e8;
  uint uStack_e4;
  uint uStack_dc;
  uint uStack_d8;
  uint uStack_d4;
  void *pvStack_d0;
  void *pvStack_cc;
  undefined4 uStack_c0;
  uint uStack_bc;
  uint uStack_b8;
  void *pvStack_b4;
  undefined4 uStack_a4;
  uint uStack_a0;
  undefined1 auStack_9c [4];
  void *pvStack_98;
  undefined4 uStack_88;
  uint uStack_84;
  undefined1 auStack_80 [4];
  void *apvStack_7c [3];
  undefined1 auStack_70 [4];
  undefined4 uStack_6c;
  uint uStack_68;
  undefined1 auStack_64 [4];
  void *pvStack_60;
  undefined4 uStack_50;
  uint uStack_4c;
  void *pvStack_48;
  undefined1 auStack_44 [4];
  undefined1 uStack_40;
  undefined1 auStack_34 [4];
  undefined1 uStack_30;
  undefined1 uStack_28;
  undefined1 uStack_20;
  int *piStack_18;
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_009939ad;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5b11c + 0x1c))();
  uStack_118 = 0;
  uStack_114 = 0;
  uStack_110 = 0;
  uStack_84 = 0xf;
  uStack_88 = 0;
  pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
  uStack_68 = 0xf;
  uStack_6c = 0;
  apvStack_7c[0] = (void *)((uint)apvStack_7c[0] & 0xffffff00);
  uStack_140 = s_<VALUE>_009f15e8;
  puStack_8 = (undefined1 *)0x1;
  puStack_144 = (undefined4 *)0x74db65;
  FUN_00401740();
  uStack_140 = (char *)&uStack_10c;
  puStack_144 = (undefined4 *)0x74db70;
  puStack_144 = (undefined4 *)FUN_004041a0();
  uStack_140 = (char *)0x0;
  puStack_8._0_1_ = 2;
  FUN_00401660();
  puStack_8 = (undefined1 *)CONCAT31(puStack_8._1_3_,1);
  if (0xf < uStack_f4) {
    uStack_140 = (char *)0x74dba8;
    _free(pvStack_108);
    return;
  }
  uStack_140 = (char *)0x74dbbc;
  FUN_004e6c20();
  uStack_140 = auStack_64;
  puStack_144 = (undefined4 *)0x74dbcc;
  (**(code **)(*in_ECX + 0x48))();
  puStack_144 = &uStack_124;
  uStack_10 = 3;
  (**(code **)(*DAT_00b5a794 + 8))(auStack_34,2,0x6e);
  uStack_20 = 4;
  uVar3 = FUN_004022a0(&pvStack_ec,s_<color__009f1600,apvStack_7c);
  uStack_20 = 5;
  uVar3 = FUN_00402220(&uStack_124,uVar3,&DAT_009f15fc);
  uStack_20 = 6;
  uVar3 = FUN_00405bd0(&pvStack_d0,uVar3,auStack_44);
  uStack_20 = 7;
  uVar3 = FUN_00402220(&pvStack_108,uVar3,s_<_color>__009f15f0);
  uStack_20 = 8;
  FUN_00401660(uVar3,0,0xffffffff);
  if ((void *)0xf < pvStack_f0) {
    _free(pvStack_104);
    return;
  }
  pvStack_f0 = (void *)0xf;
  uStack_f4 = 0;
  pvStack_104 = (void *)((uint)pvStack_104 & 0xffffff00);
  if (0xf < uStack_b8) {
    _free(pvStack_cc);
    return;
  }
  uStack_b8 = 0xf;
  uStack_bc = 0;
  pvStack_cc = (void *)((uint)pvStack_cc & 0xffffff00);
  if (0xf < uStack_10c) {
    _free(pvStack_120);
    return;
  }
  uStack_10c = 0xf;
  uStack_110 = 0;
  pvStack_120 = (void *)((uint)pvStack_120 & 0xffffff00);
  uStack_20 = 4;
  if (0xf < uStack_d4) {
    _free(pvStack_e8);
    return;
  }
  *(undefined1 *)(in_ECX + 0xf1) = 1;
  cVar2 = (**(code **)(*DAT_00b5b11c + 0x20))(piStack_18,(int)register0x00000010 + -0x13c);
  if (cVar2 == '\0') {
    iVar4 = (**(code **)(*piStack_18 + 0x2c))();
    if (*(ushort *)(iVar4 + 0x72) < 2) {
      iVar4 = (**(code **)(*piStack_18 + 0x2c))();
      puStack_144 = *(undefined4 **)(iVar4 + 0x2c);
    }
    else {
      iVar4 = (**(code **)(*piStack_18 + 0x2c))();
      uVar5 = (uint)*(ushort *)(iVar4 + 0x72);
      iVar4 = (**(code **)(*piStack_18 + 0x14))();
      uStack_140 = (char *)(uint)*(ushort *)(iVar4 + 0xc);
      fVar6 = (float)(int)uStack_140 / (float)(uVar5 & 0xffff);
      iVar4 = (**(code **)(*piStack_18 + 0x2c))();
      uStack_140 = *(char **)(iVar4 + 0x2c);
      fVar1 = (float)(int)uStack_140;
      if ((int)uStack_140 < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
      puStack_144 = (undefined4 *)(int)ROUND(fVar1 * fVar6);
    }
  }
  FUN_004e67a0();
  FUN_00401740(s_<VALUE>_009f1608,7);
  uVar3 = FUN_004041a0(&uStack_f4,puStack_144);
  uStack_28 = 9;
  FUN_00401660(uVar3,0,0xffffffff);
  uStack_28 = 4;
  if (0xf < uStack_dc) {
    _free(pvStack_f0);
    return;
  }
  FUN_004e6c20(&uStack_bc);
  uVar3 = (**(code **)(*in_ECX + 0x48))(&uStack_f4,puStack_144);
  uStack_30 = 10;
  FUN_00401660(uVar3,0,0xffffffff);
  uStack_30 = 4;
  if (0xf < uStack_e4) {
    _free(pvStack_f8);
    return;
  }
  (**(code **)(*DAT_00b5a794 + 8))(auStack_70,2,0x6f,&puStack_144);
  uStack_40 = 0xb;
  uVar3 = FUN_004022a0(&uStack_10c,s_<color__009f1620,auStack_9c);
  uStack_40 = 0xc;
  uVar3 = FUN_00402220((int)register0x00000010 + -0x128,uVar3,&DAT_009f161c);
  uStack_40 = 0xd;
  uVar3 = FUN_00405bd0(&pvStack_f0,uVar3,auStack_80);
  uStack_40 = 0xe;
  uVar3 = FUN_00402220(&puStack_144,uVar3,s_<_color>__009f1610);
  uStack_40 = 0xf;
  FUN_00401660(uVar3,0,0xffffffff);
  if (0xf < unaff_EBP) {
    _free(uStack_140);
    return;
  }
  uStack_140 = (char *)((uint)uStack_140 & 0xffffff00);
  if (0xf < uStack_d8) {
    _free(pvStack_ec);
    return;
  }
  uStack_d8 = 0xf;
  uStack_dc = 0;
  pvStack_ec = (void *)((uint)pvStack_ec & 0xffffff00);
  if (0xf < uStack_110) {
    _free(uStack_124);
    return;
  }
  uStack_110 = 0xf;
  uStack_114 = 0;
  uStack_124 = (void *)((uint)uStack_124 & 0xffffff00);
  if (0xf < uStack_f4) {
    _free(pvStack_108);
    return;
  }
  *(undefined1 *)(in_ECX + 0xe2) = 1;
  if (0xf < uStack_68) {
    _free(apvStack_7c[0]);
    return;
  }
  uStack_68 = 0xf;
  uStack_6c = 0;
  apvStack_7c[0] = (void *)((uint)apvStack_7c[0] & 0xffffff00);
  if (0xf < uStack_4c) {
    _free(pvStack_60);
    return;
  }
  uStack_4c = 0xf;
  uStack_50 = 0;
  pvStack_60 = (void *)((uint)pvStack_60 & 0xffffff00);
  if (0xf < uStack_84) {
    _free(pvStack_98);
    return;
  }
  uStack_84 = 0xf;
  uStack_88 = 0;
  pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
  if (0xf < uStack_a0) {
    _free(pvStack_b4);
    return;
  }
  uStack_a0 = 0xf;
  uStack_a4 = 0;
  pvStack_b4 = (void *)((uint)pvStack_b4 & 0xffffff00);
  if (uStack_bc < 0x10) {
    uStack_bc = 0xf;
    uStack_c0 = 0;
    pvStack_d0 = (void *)((uint)pvStack_d0 & 0xffffff00);
    FUN_004e67a0();
    ExceptionList = pvStack_48;
    return;
  }
  _free(pvStack_d0);
  return;
}


// ==== FUN_0074e0b0 @ 0x0074e0b0 ====

void FUN_0074e0b0(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uStack_110;
  undefined4 uStack_10c;
  undefined1 local_100;
  undefined1 local_ff;
  undefined1 local_fe;
  undefined4 local_f8;
  void *local_f4;
  void *local_f0;
  undefined1 auStack_e4 [4];
  uint uStack_e0;
  uint uStack_dc;
  undefined1 auStack_d8 [4];
  void *pvStack_d4;
  undefined4 uStack_c4;
  uint uStack_c0;
  undefined1 auStack_bc [4];
  void *pvStack_b8;
  undefined4 uStack_a8;
  uint uStack_a4;
  undefined1 auStack_a0 [4];
  void *pvStack_9c;
  undefined4 uStack_8c;
  uint uStack_88;
  undefined1 auStack_84 [4];
  void *pvStack_80;
  undefined4 uStack_70;
  uint auStack_6c [4];
  undefined1 local_5c;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 local_40;
  undefined4 local_30;
  void *local_2c;
  uint uStack_18;
  void *pvStack_14;
  undefined1 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993a11;
  pvStack_c = ExceptionList;
  local_f8 = 0;
  local_f4 = (void *)0x0;
  local_f0 = (void *)0x0;
  local_48 = 0xf;
  local_4c = 0;
  local_5c = 0;
  local_2c = (void *)0xf;
  local_30 = 0;
  local_40 = 0;
  uStack_10c = &local_100;
  local_100 = 0;
  local_ff = 0;
  local_fe = 0;
  uStack_110 = param_1;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  cVar1 = (**(code **)(*DAT_00b5adc4 + 0x30))();
  if (cVar1 == '\0') {
    FUN_0040a7d0();
    FUN_004e67a0();
  }
  else {
    uVar2 = (**(code **)(*DAT_00b5adc4 + 0x3c))(auStack_e4 + -0x24);
    FUN_00401740(s_<VALUE>_009f1650,7);
    uVar3 = FUN_004041a0(&local_f8,uVar2);
    uStack_10 = 2;
    FUN_00401660(uVar3,0,0xffffffff);
    uStack_10 = 1;
    if (0xf < uStack_e0) {
      _free(local_f4);
      return;
    }
    FUN_004e6c20(auStack_6c);
    (**(code **)(*in_ECX + 0x48))(&uStack_c0,uVar2);
    uStack_18 = CONCAT31(uStack_18._1_3_,3);
    (**(code **)(*DAT_00b5a794 + 8))(auStack_e4,2,0x6f,&uStack_110);
    pvStack_c._0_1_ = 4;
    uVar2 = FUN_004022a0(&local_30,s_<color__009f1668,auStack_bc);
    pvStack_c._0_1_ = 5;
    uVar2 = FUN_00402220(&local_f4,uVar2,&DAT_009f1664);
    pvStack_c._0_1_ = 6;
    uVar2 = FUN_00405bd0(auStack_84,uVar2,auStack_d8);
    pvStack_c._0_1_ = 7;
    uVar2 = FUN_00402220(auStack_a0,uVar2,s_<_color>__009f1658);
    pvStack_c = (void *)CONCAT31(pvStack_c._1_3_,8);
    FUN_00401660(uVar2,0,0xffffffff);
    if (0xf < uStack_88) {
      _free(pvStack_9c);
      return;
    }
    uStack_88 = 0xf;
    uStack_8c = 0;
    pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
    if (0xf < auStack_6c[0]) {
      _free(pvStack_80);
      return;
    }
    auStack_6c[0] = 0xf;
    uStack_70 = 0;
    pvStack_80 = (void *)((uint)pvStack_80 & 0xffffff00);
    if (0xf < uStack_dc) {
      _free(local_f0);
      return;
    }
    uStack_dc = 0xf;
    uStack_e0 = 0;
    local_f0 = (void *)((uint)local_f0 & 0xffffff00);
    if (0xf < uStack_18) {
      _free(local_2c);
      return;
    }
    *(undefined1 *)(in_ECX + 0xe2) = 1;
    if (0xf < uStack_c0) {
      _free(pvStack_d4);
      return;
    }
    uStack_c0 = 0xf;
    uStack_c4 = 0;
    pvStack_d4 = (void *)((uint)pvStack_d4 & 0xffffff00);
    if (0xf < uStack_a4) {
      _free(pvStack_b8);
      return;
    }
    uStack_a4 = 0xf;
    uStack_a8 = 0;
    pvStack_b8 = (void *)((uint)pvStack_b8 & 0xffffff00);
    FUN_0040a7d0();
    FUN_004e67a0();
  }
  ExceptionList = pvStack_14;
  return;
}


// ==== FUN_0074e3a0 @ 0x0074e3a0 ====

void FUN_0074e3a0(void)

{
  void *unaff_EBP;
  uint uStack_c0;
  int iStack_bc;
  undefined1 auStack_b8 [4];
  void *pvStack_b4;
  uint uStack_a0;
  void *pvStack_98;
  void *local_88;
  uint uStack_84;
  uint local_74;
  void *local_6c;
  undefined4 local_68;
  undefined4 local_64;
  uint local_5c;
  uint uStack_58;
  void *pvStack_50;
  undefined4 local_4c;
  undefined4 local_48;
  uint local_40;
  uint uStack_3c;
  void *pvStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 uStack_24;
  uint uStack_20;
  void *pvStack_1c;
  undefined1 uStack_14;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00993aa1;
  pvStack_c = ExceptionList;
  local_6c = (void *)0x0;
  local_68 = 0;
  local_64 = 0;
  local_48 = 0xf;
  local_4c = 0;
  local_5c = local_5c & 0xffffff00;
  local_2c = 0xf;
  local_30 = 0;
  local_40 = local_40 & 0xffffff00;
  local_4 = 1;
  ExceptionList = &pvStack_c;
  FUN_00401740();
  FUN_00401740();
  FUN_00404230();
  local_4._0_1_ = 2;
  FUN_00401660();
  local_4 = CONCAT31(local_4._1_3_,1);
  if (0xf < local_74) {
    _free(local_88);
    return;
  }
  FUN_004e6c20();
  (**(code **)(*DAT_00b5a794 + 8))();
  uStack_14 = 3;
  if (puStack_8 == (undefined1 *)0x0) {
    FUN_00401740(&DAT_009f16cc,4);
    (**(code **)(*DAT_00b5ad18 + 8))(auStack_b8);
    uStack_14 = 4;
    FUN_00405bd0();
    uStack_14 = 5;
    FUN_00402220();
    uStack_14 = 6;
    FUN_00401660();
    if (0xf < uStack_20) {
      _free(pvStack_34);
      return;
    }
    uStack_20 = 0xf;
    uStack_24 = 0;
    pvStack_34 = (void *)((uint)pvStack_34 & 0xffffff00);
    if (0xf < uStack_84) {
      _free(pvStack_98);
      return;
    }
    uStack_84 = 0xf;
    local_88 = (void *)0x0;
    pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
    uStack_14 = 3;
    if (0xf < uStack_a0) {
      _free(pvStack_b4);
      return;
    }
  }
  else if (puStack_8 == (undefined1 *)0x1) {
    FUN_00401740(s_<color__x>_s<_color>_009f16d4,0x14);
    FUN_00404230(auStack_b8);
    uStack_14 = 7;
    FUN_00401660();
    uStack_14 = 3;
    if (0xf < uStack_a0) {
      _free(pvStack_b4);
      return;
    }
  }
  else {
    if (puStack_8 != (undefined1 *)0x2) {
      if (puStack_8 == (undefined1 *)0x3) {
        FUN_00401830(s_<color__x>_s<_color>_009f1704);
        FUN_00404230(auStack_b8);
        uStack_14 = 9;
      }
      else {
        if (puStack_8 != (undefined1 *)0x4) goto LAB_0074e753;
        FUN_00401830(s_<color__x>_s<_color>_009f171c);
        FUN_00404230(auStack_b8);
        uStack_14 = 10;
      }
      FUN_00401660();
      uStack_14 = 3;
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    FUN_00401830(s_<color__x>_s<_color>_009f16ec);
    FUN_00404230(auStack_b8);
    uStack_14 = 8;
    FUN_00401660();
    uStack_14 = 3;
    if (0xf < uStack_a0) {
      _free(pvStack_b4);
      return;
    }
  }
LAB_0074e753:
  uStack_14 = 3;
  FUN_004020e0();
  FUN_00405bd0();
  uStack_14 = 0xb;
  FUN_00402220();
  uStack_14 = 0xc;
  FUN_00401660();
  if (0xf < uStack_84) {
    _free(pvStack_98);
    return;
  }
  uStack_84 = 0xf;
  local_88 = (void *)0x0;
  pvStack_98 = (void *)((uint)pvStack_98 & 0xffffff00);
  if (0xf < uStack_a0) {
    _free(pvStack_b4);
    return;
  }
  if (*(char *)(iStack_bc + 0x34c) == '\0') {
    *(undefined1 *)(iStack_bc + 0x34c) = 1;
  }
  if (0xf < uStack_c0) {
    _free(unaff_EBP);
    return;
  }
  if (0xf < uStack_3c) {
    _free(pvStack_50);
    return;
  }
  uStack_3c = 0xf;
  local_40 = 0;
  pvStack_50 = (void *)((uint)pvStack_50 & 0xffffff00);
  if (uStack_58 < 0x10) {
    uStack_58 = 0xf;
    local_5c = 0;
    local_6c = (void *)((uint)local_6c & 0xffffff00);
    FUN_004e67a0();
    ExceptionList = pvStack_1c;
    return;
  }
  _free(local_6c);
  return;
}


// ==== FUN_0074e890 @ 0x0074e890 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0074e890(int *param_1)

{
  void *pvVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  uint uVar6;
  int *piVar7;
  byte *pbVar8;
  int in_ECX;
  undefined4 *puVar9;
  bool bVar10;
  undefined1 *puStack_594c;
  undefined1 *puStack_5948;
  uint uStack_5944;
  char *pcStack_5940;
  uint uStack_5910;
  byte bStack_590a;
  undefined1 auStack_5908 [4];
  void *pvStack_5904;
  uint uStack_5900;
  undefined4 uStack_58f4;
  uint uStack_58f0;
  undefined4 uStack_58e8;
  undefined4 uStack_58e4;
  undefined4 uStack_58e0;
  undefined **ppuStack_58dc;
  void *apvStack_58d8 [4];
  int iStack_58c8;
  uint uStack_58c4;
  undefined1 *puStack_58c0;
  void *pvStack_58b8;
  undefined4 uStack_58a8;
  uint uStack_58a4;
  void *pvStack_589c;
  undefined4 uStack_588c;
  uint uStack_5888;
  void *pvStack_5880;
  undefined4 uStack_5870;
  uint uStack_586c;
  undefined4 uStack_5868;
  undefined4 uStack_5864;
  undefined1 auStack_585c [4];
  void *pvStack_5858;
  undefined4 uStack_5848;
  uint uStack_5844;
  undefined4 auStack_5840 [21];
  undefined4 uStack_57ec;
  undefined4 uStack_57e8;
  short sStack_57e4;
  int iStack_57dc;
  void *pvStack_56e4;
  undefined4 uStack_56e0;
  undefined4 uStack_56dc;
  undefined4 uStack_56d8;
  int iStack_56d4;
  undefined1 uStack_56d0;
  ushort uStack_2bfc;
  undefined1 uStack_14;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  int *piStack_4;
  
  piStack_4 = (int *)0xffffffff;
  puStack_8 = &LAB_00993b5b;
  pvStack_c = ExceptionList;
  uStack_10 = 0x74e8af;
  ExceptionList = &pvStack_c;
  iVar3 = (**(code **)(*param_1 + 0x48))();
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)(**(code **)(*param_1 + 0x2c))();
    puVar9 = auStack_5840;
    for (iVar3 = 0x27; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar9 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar9 = puVar9 + 1;
    }
    piVar5 = (int *)(**(code **)(*DAT_00b5aa30 + 8))();
    if (piVar5 != (int *)0x0) {
      (**(code **)(*piVar5 + 4))();
      FUN_006afd30();
      piStack_4 = (int *)0x0;
      FUN_006afbf0();
      uStack_5868 = uStack_57ec;
      uStack_5864 = uStack_57e8;
      uStack_58e8 = 0;
      uStack_58e4 = 0;
      uStack_58e0 = 0;
      uStack_58a4 = 0xf;
      uStack_58a8 = 0;
      pvStack_58b8 = (void *)((uint)pvStack_58b8 & 0xffffff00);
      uStack_5888 = 0xf;
      uStack_588c = 0;
      pvStack_589c = (void *)((uint)pvStack_589c & 0xffffff00);
      piStack_4._0_1_ = 3;
      if ((short)((uint)uStack_57e8 >> 0x10) != 0) {
        *(undefined1 *)(in_ECX + 0x400) = 1;
        FUN_00401740();
        puStack_594c = &DAT_009f1748;
        FUN_00401830();
        puStack_594c = auStack_5908;
        FUN_00404230();
        piStack_4._0_1_ = 4;
        FUN_00401660();
        piStack_4._0_1_ = 3;
        if (0xf < uStack_58f0) {
          _free(pvStack_5904);
          return;
        }
        FUN_004e6c20();
        (**(code **)(*DAT_00b5a794 + 8))();
        piStack_4._0_1_ = 5;
        FUN_00401660();
        piStack_4._0_1_ = 3;
        if (0xf < uStack_58f0) {
          _free(pvStack_5904);
          return;
        }
        FUN_004e67a0();
      }
      if (sStack_57e4 != 0) {
        *(undefined1 *)(in_ECX + 0x43c) = 1;
        FUN_00401740();
        puStack_594c = &DAT_009f1754;
        FUN_00401830();
        puStack_594c = auStack_5908;
        FUN_00404230();
        piStack_4._0_1_ = 6;
        FUN_00401660();
        piStack_4._0_1_ = 3;
        if (0xf < uStack_58f0) {
          _free(pvStack_5904);
          return;
        }
        FUN_004e6c20();
        (**(code **)(*DAT_00b5a794 + 8))();
        piStack_4._0_1_ = 7;
        FUN_00401660();
        piStack_4._0_1_ = 3;
        if (0xf < uStack_58f0) {
          _free(pvStack_5904);
          return;
        }
        FUN_004e67a0();
      }
      if (iStack_57dc != 0) {
        *(undefined1 *)(in_ECX + 0x478) = 1;
        FUN_00401740();
        FUN_00401830(s__4_1f__009f1760);
        FUN_00404230(auStack_5908);
        piStack_4._0_1_ = 8;
        FUN_00401660();
        piStack_4._0_1_ = 3;
        if (0xf < uStack_58f0) {
          _free(pvStack_5904);
          return;
        }
        FUN_004e6c20();
        uStack_5944 = (**(code **)(*DAT_00b5a794 + 8))();
        pcStack_5940 = (char *)0x0;
        uStack_14 = 9;
        puStack_5948 = (undefined1 *)0x74ec2a;
        FUN_00401660();
        uStack_14 = 3;
        if (0xf < uStack_5900) {
          pcStack_5940 = (char *)0x74ec42;
          _free(&puStack_594c);
          return;
        }
        FUN_004e67a0();
        pcStack_5940 = s_<color_FDDE5C>_009f1768;
        *(undefined1 *)(in_ECX + 0x4b4) = 1;
        uStack_5944 = 0x74ec69;
        FUN_00401740();
        pcStack_5940 = (char *)(uint)uStack_2bfc;
        uStack_5944 = 0x74ec7f;
        (**(code **)(*DAT_00b5ace8 + 8))();
        uStack_58c4 = 0xf;
        iStack_58c8 = 0;
        apvStack_58d8[0] = (void *)((uint)apvStack_58d8[0] & 0xffffff00);
        FUN_00401660();
        piStack_4._0_1_ = 10;
        FUN_00401ff0();
        FUN_004020e0();
        if (0xf < uStack_58c4) {
          _free(apvStack_58d8[0]);
          return;
        }
      }
      apvStack_58d8[0] = pvStack_56e4;
      apvStack_58d8[1] = (void *)uStack_56e0;
      apvStack_58d8[3] = (void *)uStack_56d8;
      ppuStack_58dc = &PTR_FUN_009a51c4;
      apvStack_58d8[2] = (void *)uStack_56dc;
      iStack_58c8 = iStack_56d4;
      uStack_58c4 = CONCAT31(uStack_58c4._1_3_,uStack_56d0);
      piStack_4 = (int *)CONCAT31(piStack_4._1_3_,0xb);
      uStack_5910 = 0;
      if (iStack_56d4 != 0) {
        *(undefined1 *)(in_ECX + 0x4f0) = 1;
        (**(code **)(*DAT_00b5a794 + 0xc))();
        pcStack_5940 = (char *)0x74ed5d;
        FUN_00401660();
        uVar6 = (**(code **)(*DAT_00b5a980 + 8))();
        iVar3 = *DAT_00b5acc8;
        (**(code **)(*piStack_4 + 0x1c))();
        iVar3 = (**(code **)(iVar3 + 0xc))();
        if (uVar6 != 0) {
          bVar10 = iVar3 != 0;
          do {
            pvVar1 = apvStack_58d8[uStack_5910];
            piVar5 = (int *)(**(code **)(*DAT_00b5aa30 + 8))();
            if (piVar5 != (int *)0x0) {
              if (uStack_5910 != 0) {
                FUN_004020e0();
              }
              if ((iVar3 == 0) ||
                 (piVar7 = (int *)(**(code **)(*DAT_00b5acc0 + 0x18))(), piVar7 == (int *)0x0)) {
LAB_0074f01d:
                bVar2 = bVar10;
                if (bVar10) {
                  puStack_58c0 = (undefined1 *)&uStack_5944;
                  puStack_5948 = &DAT_009f1794;
                  puStack_594c = (undefined1 *)0x74f03d;
                  FUN_00401830();
                  puStack_5948 = auStack_585c;
                  puStack_594c = (undefined1 *)0x74f050;
                  (**(code **)(*DAT_00b5ad18 + 8))();
                  piStack_4._0_1_ = 0xc;
                  FUN_00401ff0();
                  piStack_4 = (int *)CONCAT31(piStack_4._1_3_,0xb);
                  if (0xf < uStack_5844) {
                    _free(pvStack_5858);
                    return;
                  }
                  uStack_5844 = 0xf;
                  uStack_5848 = 0;
                  pvStack_5858 = (void *)((uint)pvStack_5858 & 0xffffff00);
                }
              }
              else {
                piVar7 = (int *)(**(code **)(*piVar7 + 0x18))();
                pbVar8 = (byte *)(**(code **)(*piVar7 + 0xc))();
                bStack_590a = (byte)((uint)pvVar1 >> 0x10);
                if ((*pbVar8 & 0xf) < bStack_590a) goto LAB_0074f01d;
                bVar2 = false;
              }
              (**(code **)(*piVar5 + 4))();
              FUN_006afd30();
              piStack_4._0_1_ = 0xd;
              (**(code **)(*DAT_00b5ace8 + 8))();
              uStack_586c = 0xf;
              uStack_5870 = 0;
              pvStack_5880 = (void *)((uint)pvStack_5880 & 0xffffff00);
              FUN_00401660();
              piStack_4._0_1_ = 0xe;
              FUN_00401ff0();
              puStack_58c0 = (undefined1 *)&puStack_5948;
              puStack_594c = (undefined1 *)0x6;
              uStack_5944 = uStack_5944 & 0xffffff00;
              FUN_00401740(s_Lv_d__009f179c);
              puStack_594c = auStack_5908;
              FUN_00404230();
              piStack_4._0_1_ = 0xf;
              FUN_00401ff0();
              piStack_4._0_1_ = 0xe;
              if (0xf < uStack_58f0) {
                _free(pvStack_5904);
                return;
              }
              uStack_58f0 = 0xf;
              uStack_58f4 = 0;
              pvStack_5904 = (void *)((uint)pvStack_5904 & 0xffffff00);
              if (bVar2) {
                FUN_004020e0();
              }
              if (0xf < uStack_586c) {
                _free(pvStack_5880);
                return;
              }
              uStack_586c = 0xf;
              uStack_5870 = 0;
              pvStack_5880 = (void *)((uint)pvStack_5880 & 0xffffff00);
              piStack_4 = (int *)CONCAT31(piStack_4._1_3_,0xb);
              FUN_00480300();
            }
            uStack_5910 = uStack_5910 + 1;
          } while (uStack_5910 < uVar6);
        }
      }
      if (0xf < uStack_5888) {
        _free(pvStack_589c);
        return;
      }
      uStack_5888 = 0xf;
      uStack_588c = 0;
      pvStack_589c = (void *)((uint)pvStack_589c & 0xffffff00);
      if (0xf < uStack_58a4) {
        _free(pvStack_58b8);
        return;
      }
      uStack_58a4 = 0xf;
      uStack_58a8 = 0;
      pvStack_58b8 = (void *)((uint)pvStack_58b8 & 0xffffff00);
      FUN_004e67a0();
      piStack_4 = (int *)0xffffffff;
      FUN_00480300();
    }
  }
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0074f0b0 @ 0x0074f0b0 ====

void FUN_0074f0b0(int *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  int unaff_EDI;
  undefined4 *puVar3;
  undefined4 uStack_170;
  undefined1 *puStack_16c;
  undefined1 *puStack_168;
  undefined1 auStack_13c [4];
  void *pvStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_128;
  uint uStack_124;
  undefined1 auStack_11c [4];
  void *pvStack_118;
  undefined1 *puStack_110;
  undefined1 auStack_10c [4];
  void *pvStack_108;
  uint uStack_104;
  uint uStack_f4;
  undefined1 uStack_ec;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined1 uStack_d0;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  undefined4 auStack_b8 [37];
  void *pvStack_24;
  undefined1 uStack_1c;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00993b9c;
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;
  iVar1 = (**(code **)(*param_1 + 0x48))();
  if (iVar1 == 0) {
    *(undefined1 *)(in_ECX + 0x568) = 0;
    ExceptionList = pvStack_14;
    return;
  }
  puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x2c))();
  puVar3 = auStack_b8;
  for (iVar1 = 0x27; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  pvStack_138 = (void *)0x0;
  uStack_134 = 0;
  uStack_130 = 0;
  uStack_d8 = 0xf;
  uStack_dc = 0;
  uStack_ec = 0;
  uStack_bc = 0xf;
  uStack_c0 = 0;
  uStack_d0 = 0;
  uStack_c = 1;
  FUN_00401740();
  puStack_110 = (undefined1 *)&uStack_170;
  puStack_16c = (undefined1 *)((uint)puStack_16c & 0xffffff00);
  FUN_00401740(&DAT_009f17b8,2);
  FUN_00404230(auStack_10c);
  uStack_c._0_1_ = 2;
  FUN_00401660();
  uStack_c = CONCAT31(uStack_c._1_3_,1);
  if (0xf < uStack_f4) {
    _free(pvStack_108);
    return;
  }
  FUN_004e6c20();
  (**(code **)(*DAT_00b5a794 + 8))();
  puStack_168 = auStack_13c;
  puStack_16c = auStack_11c;
  uStack_1c = 3;
  uStack_170 = 0x74f21e;
  puStack_16c = (undefined1 *)FUN_00402220();
  puStack_168 = (undefined1 *)0x0;
  uStack_1c = 4;
  uStack_170 = 0x74f23c;
  FUN_00401660();
  if (0xf < uStack_104) {
    puStack_168 = (undefined1 *)0x74f24c;
    _free(pvStack_118);
    return;
  }
  *(undefined1 *)(unaff_EDI + 0x568) = 1;
  if (uStack_124 < 0x10) {
    uStack_124 = 0xf;
    uStack_128 = 0;
    pvStack_138 = (void *)((uint)pvStack_138 & 0xffffff00);
    FUN_0040a7d0();
    FUN_004e67a0();
    ExceptionList = pvStack_24;
    return;
  }
  puStack_168 = (undefined1 *)0x74f26a;
  _free(pvStack_138);
  return;
}


// ==== FUN_0074f2b0 @ 0x0074f2b0 ====

void FUN_0074f2b0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  uVar3 = 0;
  if (*(int *)(iVar1 + 0xe4) != 0) {
    iVar2 = iVar1 + 0xb4;
    do {
      FUN_0074e3a0(iVar2,param_2);
      uVar3 = uVar3 + 1;
      iVar2 = iVar2 + 8;
    } while (uVar3 < *(uint *)(iVar1 + 0xe4));
  }
  return;
}


// ==== FUN_0074f2f0 @ 0x0074f2f0 ====

void FUN_0074f2f0(int *param_1)

{
  byte bVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  undefined2 auStack_10 [2];
  int iStack_c;
  
  iVar2 = (**(code **)(*param_1 + 0x14))();
  iVar7 = 0;
  if (*(char *)(iVar2 + 0x1f) != '\0') {
    do {
      bVar1 = *(byte *)(iVar2 + 0x10 + iVar7 * 4);
      piVar3 = (int *)(**(code **)(*DAT_00b5abb8 + 8))(*(undefined2 *)(iVar2 + 0xe + iVar7 * 4));
      if (piVar3 != (int *)0x0) {
        iVar4 = (**(code **)(*piVar3 + 4))();
        iVar4 = *(int *)(iVar4 + 0x88);
        iVar5 = (**(code **)(*piVar3 + 4))();
        iVar5 = *(int *)(iVar5 + 0x8c);
        iVar6 = (**(code **)(*piVar3 + 4))();
        auStack_10[0] = *(undefined2 *)(iVar6 + 4);
        iStack_c = (int)((iVar5 - iVar4) * (uint)bVar1) / 100 + iVar4;
        if (iVar7 < 2) {
          uVar8 = 2;
        }
        else if (iVar7 == 2) {
          uVar8 = 3;
        }
        else {
          if (iVar7 != 3) goto LAB_0074f3c4;
          uVar8 = 4;
        }
        FUN_0074e3a0(auStack_10,uVar8);
      }
LAB_0074f3c4:
      iVar7 = iVar7 + 1;
    } while (iVar7 < (int)(uint)*(byte *)(iVar2 + 0x1f));
  }
  return;
}


// ==== FUN_0074f3e0 @ 0x0074f3e0 ====

undefined4 FUN_0074f3e0(int *param_1)

{
  code *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined4 extraout_EAX;
  undefined4 uVar5;
  undefined4 extraout_EAX_00;
  uint uVar6;
  int iVar7;
  undefined4 *puVar8;
  undefined4 extraout_EAX_01;
  undefined2 *puVar9;
  int *in_ECX;
  char *pcVar10;
  undefined4 unaff_EDI;
  int *piVar11;
  short *psVar12;
  undefined4 uStack_2f0;
  int *piVar13;
  short asStack_2d6 [5];
  undefined1 auStack_2cc [4];
  undefined4 uStack_2c8;
  undefined1 auStack_2c0 [4];
  void *pvStack_2bc;
  int *piStack_2b8;
  uint uStack_2b4;
  int iStack_2ac;
  uint uStack_2a8;
  undefined1 auStack_2a4 [8];
  undefined1 auStack_29c [632];
  void *pvStack_24;
  undefined4 uStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  int *piStack_4;
  
  piStack_4 = (int *)0xffffffff;
  puStack_8 = &LAB_00993bc7;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  FUN_00749c50();
  uVar3 = (**(code **)(*DAT_00b5a980 + 8))();
  piVar4 = (int *)(**(code **)(*param_1 + 0x48))();
  if (piVar4 != (int *)0x0) {
    (**(code **)(*param_1 + 0x2c))();
    uStack_2f0 = auStack_2cc;
    *(undefined1 *)(in_ECX + 1) = 1;
    piVar13 = param_1;
    uVar5 = (**(code **)(*in_ECX + 0x44))();
    pvStack_c = (void *)0x1;
    FUN_00401660(uVar5,0,0xffffffff);
    pvStack_c = (void *)0xffffffff;
    if (0xf < pvStack_2bc) {
      _free(in_ECX + 1);
      return extraout_EAX_00;
    }
    FUN_0074b4c0(param_1);
    cVar2 = (**(code **)(*in_ECX + 0x28))(param_1);
    if (cVar2 == '\x01') {
      uVar6 = (**(code **)(*param_1 + 0x1c))();
      *(undefined1 *)(in_ECX + 0x178) = 1;
      uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar6 & 0xffff | 0x3840000);
      FUN_00401660(uVar5,0,0xffffffff);
    }
    iVar7 = (**(code **)(*in_ECX + 0x18))(param_1);
    if (iVar7 == 0x604) {
      uVar6 = (**(code **)(*param_1 + 0x1c))();
      *(undefined1 *)(in_ECX + 0x187) = 1;
      uVar5 = (**(code **)(*DAT_00b5a794 + 0xc))(0,uVar6 & 0xffff | 0x7d50000);
      FUN_00401660(uVar5,0,0xffffffff);
    }
    FUN_00797a50(auStack_29c,0,0x280);
    (**(code **)(*DAT_00b5a734 + 0x30))(param_1,auStack_29c);
    cVar2 = (**(code **)(*piVar4 + 0xc))();
    if (cVar2 != '\0') {
      FUN_0074b860(param_1);
      FUN_0074b980(param_1);
      FUN_0074c4b0(param_1,auStack_2a4);
      FUN_0074c740(param_1,auStack_2a4);
      FUN_0074c9d0(param_1,auStack_2a4);
      FUN_0074cc60(param_1,auStack_2a4);
      FUN_0074ce20(param_1,auStack_2a4);
      FUN_0074cfe0(uVar3,param_1,auStack_2a4);
    }
    iVar7 = (**(code **)(*DAT_00b5a78c + 100))();
    if (iVar7 == 1) {
      FUN_0074dad0(param_1,auStack_2a4);
    }
    else {
      iVar7 = (**(code **)(*DAT_00b5adc4 + 8))();
      if (iVar7 != 0) {
        FUN_0074e0b0(param_1);
      }
    }
    FUN_0074d7d0(uVar3,param_1,auStack_2a4);
    FUN_0074bba0(uVar3,param_1,auStack_2a4);
    piVar4 = in_ECX + 0xdc;
    if ((uint)in_ECX[0xe1] < 0x10) {
      piVar11 = piVar4;
    }
    else {
      piVar11 = (int *)*piVar4;
    }
    if (0xf < (uint)in_ECX[0xe1]) {
      piVar4 = (int *)*piVar4;
    }
    FUN_004bdb30(&uStack_2f0,piVar4,in_ECX[0xe0] + (int)piVar11);
    *(undefined1 *)(in_ECX + 0xd3) = 0;
    puVar8 = (undefined4 *)(**(code **)(*param_1 + 0x14))();
    psVar12 = asStack_2d6 + -7;
    for (iVar7 = 9; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined4 *)psVar12 = *puVar8;
      puVar8 = puVar8 + 1;
      psVar12 = psVar12 + 2;
    }
    if (uStack_2c8._2_1_ != 0) {
      uStack_2f0 = (char *)(uint)uStack_2c8._2_1_;
      psVar12 = asStack_2d6 + -5;
      do {
        if (*psVar12 != 0) {
          iVar7 = (**(code **)(*DAT_00b5a738 + 0x10))(*psVar12);
          if (iVar7 == 0) {
            uStack_2a8 = 0xf;
            pvStack_2bc = (void *)((uint)pvStack_2bc & 0xffffff00);
            iStack_2ac = iVar7;
            FUN_00401740(s_Invalid_Socket_Index_009f13f8,0x14);
            uStack_1c = 2;
            FUN_00403e50(auStack_2c0);
            uStack_1c = 0xffffffff;
            if (0xf < uStack_2a8) {
              _free(pvStack_2bc);
              return extraout_EAX_01;
            }
            uStack_2a8 = 0xf;
            iStack_2ac = 0;
            pvStack_2bc = (void *)((uint)pvStack_2bc & 0xffffff00);
          }
          else {
            FUN_0074f2b0(iVar7,1);
          }
        }
        psVar12 = psVar12 + 1;
        uStack_2f0 = uStack_2f0 + -1;
      } while (uStack_2f0 != (undefined1 *)0x0);
    }
    iVar7 = (**(code **)(*piVar13 + 4))();
    if (*(int *)(iVar7 + 0xe4) != 0) {
      uStack_2f0 = (char *)(iVar7 + 0xb4);
      uVar6 = 0;
      do {
        FUN_0074e3a0(uStack_2f0,0);
        uStack_2f0 = uStack_2f0 + 8;
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(iVar7 + 0xe4));
    }
    FUN_0074f2f0(param_1);
    iVar7 = (**(code **)(*piVar13 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0x302) {
      FUN_0074e890(param_1);
    }
    iVar7 = (**(code **)(*piVar13 + 4))();
    piVar4 = DAT_00b5abb4;
    if (*(int *)(iVar7 + 0xc) == 0x100) {
      puVar9 = (undefined2 *)(**(code **)(*param_1 + 0x14))();
      piVar4 = (int *)(**(code **)(*piVar4 + 4))(*puVar9);
      if (piVar4 == (int *)0x0) {
        *(undefined1 *)(in_ECX + 0x14b) = 0;
      }
      else {
        *(undefined1 *)(in_ECX + 0x14b) = 1;
        iVar7 = (**(code **)(*piVar4 + 8))();
        pcVar10 = (char *)(iVar7 + 2);
        do {
          cVar2 = *pcVar10;
          pcVar10 = pcVar10 + 1;
        } while (cVar2 != '\0');
        FUN_00401740((char *)(iVar7 + 2),(int)pcVar10 - (iVar7 + 3));
      }
    }
    iVar7 = (**(code **)(*piVar13 + 4))();
    if (*(int *)(iVar7 + 0xc) == 0xc) {
      FUN_0074c000(param_1);
    }
    (**(code **)(*piVar13 + 4))();
    FUN_0074f0b0(param_1);
    ExceptionList = pvStack_24;
    return unaff_EDI;
  }
  uStack_2f0 = s_pFlyWeight____NULL_009f13e4;
  uStack_2b4 = 0xf;
  uStack_2c8 = (void *)((uint)uStack_2c8 & 0xffffff00);
  piStack_2b8 = piVar4;
  FUN_00401740();
  uStack_2f0 = (char *)0x74f45c;
  piStack_4 = piVar4;
  FUN_00406880();
  piStack_4 = (int *)0xffffffff;
  if (uStack_2b4 < 0x10) {
    pcVar1 = (code *)swi(3);
    uVar3 = (*pcVar1)();
    return uVar3;
  }
  uStack_2f0 = (char *)0x74f47b;
  _free(uStack_2c8);
  return extraout_EAX;
}


// ==== FUN_0074f860 @ 0x0074f860 ====

void FUN_0074f860(undefined1 *param_1)

{
  undefined1 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  in_ECX[8] = param_1[8];
  in_ECX[9] = param_1[9];
  in_ECX[10] = param_1[10];
  in_ECX[0xb] = param_1[0xb];
  in_ECX[0xc] = param_1[0xc];
  in_ECX[0xd] = param_1[0xd];
  *(undefined ***)(in_ECX + 0x10) = &PTR_FUN_009a5978;
  puVar2 = (undefined4 *)(param_1 + 0x14);
  puVar3 = (undefined4 *)(in_ECX + 0x14);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(param_1 + 0x44);
  *(undefined ***)(in_ECX + 0x48) = &PTR_FUN_009a5980;
  *(undefined4 *)(in_ECX + 0x4c) = *(undefined4 *)(param_1 + 0x4c);
  *(undefined4 *)(in_ECX + 0x50) = *(undefined4 *)(param_1 + 0x50);
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 0x54);
  *(undefined4 *)(in_ECX + 0x58) = *(undefined4 *)(param_1 + 0x58);
  puVar2 = (undefined4 *)(param_1 + 0x5c);
  puVar3 = (undefined4 *)(in_ECX + 0x5c);
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined2 *)(in_ECX + 0x78) = *(undefined2 *)(param_1 + 0x78);
  *(undefined2 *)(in_ECX + 0x7a) = *(undefined2 *)(param_1 + 0x7a);
  return;
}


// ==== FUN_0074f950 @ 0x0074f950 ====

void FUN_0074f950(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x38)) {
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  if (*(uint *)(in_ECX + 0x1c) < 0x10) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0xf;
    *(undefined1 *)(in_ECX + 8) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_0074f9a0 @ 0x0074f9a0 ====

void FUN_0074f9a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00749bf0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0074f9c0 @ 0x0074f9c0 ====

void FUN_0074f9c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f1924;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0074f9e0 @ 0x0074f9e0 ====

void FUN_0074f9e0(undefined2 *param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 4) = *param_1;
  *(undefined1 *)(in_ECX + 6) = *(undefined1 *)(param_1 + 1);
  return;
}


// ==== FUN_0074fa20 @ 0x0074fa20 ====

void FUN_0074fa20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009f194c;
  *(undefined1 *)(in_ECX + 1) = 0;
  *(undefined1 *)((int)in_ECX + 5) = 0;
  *(undefined1 *)((int)in_ECX + 6) = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5aef0 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5aef0 = in_ECX;
  return;
}


// ==== FUN_0074fa60 @ 0x0074fa60 ====

void FUN_0074fa60(void)

{
  undefined4 uVar1;
  int *in_ECX;
  int unaff_retaddr;
  
  (**(code **)(*DAT_00b5af2c + 8))(0);
  if (*(int *)(unaff_retaddr + 0x10) != 1) {
    uVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    FUN_00828d10(uVar1,CONCAT13((char)((uint)(in_ECX + 1) >> 0x18),(int3)in_ECX[1]));
    (**(code **)(*in_ECX + 0xc))();
    (**(code **)(*DAT_00b5aef8 + 4))();
    (**(code **)(*DAT_00b5a790 + 8))();
  }
  return;
}


// ==== FUN_0074fad0 @ 0x0074fad0 ====

void FUN_0074fad0(void)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  (**(code **)(**(int **)(iVar1 + 0x28) + 0x38))(0);
  iVar1 = (**(code **)(*DAT_00b5a980 + 0xc))();
  (**(code **)(**(int **)(iVar1 + 0x28) + 0x38))(0);
  return;
}


// ==== FUN_0074fb00 @ 0x0074fb00 ====

void FUN_0074fb00(int param_1)

{
  undefined4 uVar1;
  int *in_ECX;
  undefined4 extraout_EDX;
  undefined3 uStack_20;
  undefined1 uStack_1d;
  ushort *puStack_1c;
  uint uStack_18;
  undefined4 uStack_14;
  
  uStack_14 = 0x74fb11;
  uVar1 = (**(code **)(*DAT_00b5a980 + 0xc))();
  uStack_14 = *(undefined4 *)(param_1 + 0x44);
  uStack_18 = param_1 + 0x38;
  _uStack_20 = CONCAT13((char)((uint)(param_1 + 0x10) >> 0x18),*(undefined3 *)(param_1 + 0x10));
  puStack_1c = (ushort *)(param_1 + 0x14);
  FUN_00828d40(uVar1,CONCAT31((int3)((uint)&uStack_20 >> 8),*(undefined1 *)(param_1 + 0x48)));
  uStack_14 = 0x74fb47;
  (**(code **)(*in_ECX + 0xc))();
  uStack_14 = 0x74fb52;
  (**(code **)(*DAT_00b5aef8 + 4))();
  uStack_14 = CONCAT31((int3)((uint)extraout_EDX >> 8),*(undefined1 *)(param_1 + 0x48));
  uStack_18 = (uint)*(ushort *)(param_1 + 0x14);
  puStack_1c = (ushort *)0x74fb65;
  (**(code **)(*DAT_00b5aef8 + 0x28))();
  return;
}


// ==== FUN_0074fb70 @ 0x0074fb70 ====

void FUN_0074fb70(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int *piVar5;
  int *in_ECX;
  
  iVar2 = (**(code **)(*DAT_00b5a980 + 0xc))();
  piVar5 = *(int **)(iVar2 + 0x28);
  piVar3 = (int *)(**(code **)(*piVar5 + 0x34))();
  puVar4 = (undefined4 *)(**(code **)(*piVar3 + 4))();
  uVar1 = *puVar4;
  piVar5 = (int *)(**(code **)(*piVar5 + 0x34))();
  (**(code **)(*piVar5 + 8))(*(undefined4 *)(param_1 + 0x10));
  (**(code **)(*in_ECX + 0xc))();
  (**(code **)(*DAT_00b5aef8 + 4))();
  puVar4 = operator_new(0xc);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    *puVar4 = &PTR_FUN_009f1938;
  }
  puVar4[2] = *(undefined4 *)(param_1 + 0x10);
  puVar4[1] = uVar1;
  FUN_00797a20(puVar4);
  return;
}


// ==== FUN_0074fbf0 @ 0x0074fbf0 ====

void FUN_0074fbf0(void)

{
  int iVar1;
  int unaff_retaddr;
  
  (**(code **)(*DAT_00b5af2c + 8))(0);
  iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
  (**(code **)(**(int **)(iVar1 + 0x28) + 0x38))(*(char *)(unaff_retaddr + 0x10) == '\0');
  (**(code **)(*DAT_00b5aef8 + 4))();
  return;
}


// ==== FUN_0074fc30 @ 0x0074fc30 ====

void FUN_0074fc30(int param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*DAT_00b5a980 + 0xc))();
  (**(code **)(**(int **)(iVar1 + 0x28) + 0x38))(*(char *)(param_1 + 0x10) == '\0');
  (**(code **)(*DAT_00b5aef8 + 4))();
  return;
}


// ==== FUN_0074fc60 @ 0x0074fc60 ====

void FUN_0074fc60(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x28);
  iVar2 = (**(code **)(*piVar1 + 0x28))();
  while (iVar2 != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,iVar2);
    iVar2 = (**(code **)(*piVar1 + 0x2c))();
  }
  (**(code **)(*piVar1 + 0x30))();
  return;
}


// ==== FUN_0074fcb0 @ 0x0074fcb0 ====

void FUN_0074fcb0(void)

{
  undefined4 *in_ECX;
  
  DAT_00b5aef0 = 0;
  *in_ECX = &PTR_FUN_009f1924;
  return;
}


// ==== FUN_0074fcd0 @ 0x0074fcd0 ====

void FUN_0074fcd0(int param_1)

{
  void *pvVar1;
  undefined1 auStack_70 [4];
  undefined1 uStack_6c;
  void *pvStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined1 auStack_30 [36];
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined1 *local_4;
  
  local_4 = (undefined1 *)0xffffffff;
  puStack_8 = &LAB_00993c23;
  pvStack_c = ExceptionList;
  if (*(int *)(param_1 + 0x10) == 0) {
    uStack_54 = 0x74fd02;
    ExceptionList = &pvStack_c;
    pvVar1 = operator_new(0x20);
    local_4 = (undefined1 *)0x0;
    if (pvVar1 != (void *)0x0) {
      (**(code **)(*DAT_00b5aef8 + 0x14))();
      uStack_54 = 0x74fd26;
      FUN_00750930();
    }
    local_4 = (undefined1 *)0xffffffff;
    uStack_54 = 0x74fd38;
    FUN_00797a20();
    uStack_54 = 0;
    uStack_58 = 0x74fd4c;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_64 = 0x74fd6a;
    FUN_00401660();
    local_4 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_c = (void *)0x1;
    uStack_6c = 0;
    FUN_00401660(auStack_30 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
  }
  else {
    if (*(int *)(param_1 + 0x10) != 1) {
      uStack_54 = 0;
      uStack_58 = 0x74fe65;
      ExceptionList = &pvStack_c;
      uStack_58 = (**(code **)(*DAT_00b5a794 + 0xc))();
      uStack_5c = 0x74fe6f;
      FUN_00765c50();
      local_4 = auStack_70;
      pvStack_c = (void *)0x5;
      FUN_00765c50(auStack_30);
      (**(code **)(*DAT_00b5ad0c + 0x28))(2);
                    /* WARNING: Subroutine does not return */
      FUN_00446f10();
    }
    uStack_54 = 0;
    uStack_58 = 0x74fde3;
    ExceptionList = &pvStack_c;
    uStack_60 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_58 = 0xffffffff;
    uStack_5c = 0;
    uStack_64 = 0x74fe01;
    FUN_00401660();
    local_4 = auStack_70;
    uStack_58 = 0xf;
    uStack_5c = 0;
    pvStack_c = (void *)0x2;
    uStack_6c = 0;
    FUN_00401660(auStack_30 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_54) {
      _free(pvStack_68);
      return;
    }
  }
  ExceptionList = (void *)0xf;
  return;
}


// ==== FUN_0074fec0 @ 0x0074fec0 ====

void FUN_0074fec0(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  void *unaff_EDI;
  int unaff_retaddr;
  undefined1 auStack_78 [4];
  undefined1 uStack_74;
  void *pvStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_54;
  uint uStack_3c;
  void *pvStack_38;
  undefined1 auStack_34 [4];
  undefined1 uStack_30;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_00993c45;
  pvStack_c = ExceptionList;
  uStack_54 = 0;
  uStack_58 = 0x74feeb;
  ExceptionList = &pvStack_c;
  (**(code **)(*DAT_00b5af2c + 8))();
  iVar1 = *(int *)(unaff_retaddr + 0x10);
  if (iVar1 == 1) {
    uStack_58 = 0x6e002e;
    uStack_5c = 0;
    uStack_60 = 0x74ff0c;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    pvStack_38 = (void *)0xf;
    pvStack_6c = (void *)0x74ff2a;
    FUN_00401660();
    puStack_8 = auStack_78;
    uStack_60 = 0xf;
    uStack_64 = 0;
    uStack_10 = 0;
    uStack_74 = 0;
    FUN_00401660(auStack_34 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
  }
  else if (iVar1 == 2) {
    uStack_58 = 0x6e002f;
    uStack_5c = 0;
    uStack_60 = 0x74ffa0;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    pvStack_38 = (void *)0xf;
    pvStack_6c = (void *)0x74ffbe;
    FUN_00401660();
    puStack_8 = auStack_78;
    uStack_60 = 0xf;
    uStack_64 = 0;
    uStack_10 = 1;
    uStack_74 = 0;
    FUN_00401660(auStack_34 + -0x1c,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_58) {
      _free(pvStack_6c);
      return;
    }
  }
  else if (iVar1 == 3) {
    uStack_58 = 0x6e002f;
    uStack_5c = 0;
    uStack_60 = 0x750038;
    uStack_68 = (**(code **)(*DAT_00b5a794 + 0xc))();
    uStack_60 = 0xffffffff;
    uStack_64 = 0;
    uStack_1c = 0xf;
    uStack_20 = 0;
    uStack_30 = 0;
    pvStack_6c = (void *)0x750056;
    FUN_00401660();
    puStack_8 = auStack_78;
    uStack_60 = 0xf;
    uStack_64 = 0;
    uStack_10 = 2;
    uStack_74 = 0;
    FUN_00401660(auStack_34,0,0xffffffff);
    (**(code **)(*DAT_00b5ad0c + 0x28))(2);
    if (0xf < uStack_3c) {
      _free(unaff_EDI);
      return;
    }
  }
  else {
    uStack_58 = 0x7500bd;
    iVar1 = (**(code **)(*DAT_00b5a980 + 8))();
    uStack_58 = 0x7500c5;
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x28) + 0x34))();
    uStack_58 = *(undefined4 *)(unaff_retaddr + 0x14);
    uStack_5c = 0x7500d0;
    (**(code **)(*piVar2 + 8))();
    uStack_5c = *(undefined4 *)(unaff_retaddr + 0x18);
    uStack_60 = 0x7500df;
    (**(code **)(*DAT_00b5aef4 + 0x2c))();
    uStack_60 = 0x7500e6;
    (**(code **)(*in_ECX + 0xc))();
    uStack_60 = 0x7500f1;
    (**(code **)(*DAT_00b5aef8 + 4))();
    uStack_60 = 0x7500fc;
    (**(code **)(*DAT_00b5a790 + 4))();
  }
  ExceptionList = pvStack_38;
  return;
}


