// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x610000-0x61ffff

// ==== FUN_00610000 @ 0x00610000 ====

void FUN_00610000(undefined4 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  iVar2 = (**(code **)(*param_2 + 0x4c))();
  if ((iVar2 != 0) && (cVar1 = FUN_0060ff50(param_1,param_2), cVar1 == '\x01')) {
    (**(code **)(*in_ECX + 0x10))(param_1,param_2);
    (**(code **)(*param_2 + 0x10))();
    iVar2 = (**(code **)(*param_2 + 0x4c))();
    piVar3 = (int *)(**(code **)(**(int **)(iVar2 + 0x50) + 0x14))(param_1);
    (**(code **)(*piVar3 + 0x10))();
    FUN_00797a50(auStack_a + -0xe,0,0xc);
    (**(code **)(*param_2 + 0x24))(auStack_a + -0xe);
  }
  return;
}


// ==== FUN_006100b0 @ 0x006100b0 ====

int FUN_006100b0(undefined4 *param_1,undefined4 param_2)

{
  char cVar1;
  char extraout_AL;
  uint3 extraout_var;
  
  FUN_0060ff50(*param_1,param_2);
  if ((((extraout_AL == '\x01') || (cVar1 = *(char *)((int)param_1 + 0xb), cVar1 == '\a')) ||
      (cVar1 == '\f')) ||
     (((cVar1 == '\r' || (cVar1 == '\x0e')) || ((cVar1 == '\n' || (cVar1 == '\b')))))) {
    return CONCAT31(extraout_var,1);
  }
  return (uint)extraout_var << 8;
}


// ==== FUN_006100f0 @ 0x006100f0 ====

void FUN_006100f0(byte param_1)

{
  void *in_ECX;
  
  FUN_0060ffe0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00610110 @ 0x00610110 ====

bool FUN_00610110(uint *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return *(uint *)(iVar1 + 0xd) < *param_1;
}


// ==== FUN_00610130 @ 0x00610130 ====

int FUN_00610130(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_00610140 @ 0x00610140 ====

undefined1 FUN_00610140(void)

{
  return 1;
}


// ==== FUN_00610150 @ 0x00610150 ====

undefined1 FUN_00610150(void)

{
  return 0;
}


// ==== FUN_00610160 @ 0x00610160 ====

int FUN_00610160(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  *(int *)((int)param_1 + 0xd) = *(int *)((int)param_1 + 0xd) + (param_2 - iVar1);
  return param_2 - iVar1;
}


// ==== FUN_00610180 @ 0x00610180 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00610180(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc06c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b06c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b06c = in_ECX;
  return;
}


// ==== FUN_006101b0 @ 0x006101b0 ====

void FUN_006101b0(uint param_1,int *param_2)

{
  int iVar1;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  if (*(uint *)(iVar1 + 0xd) < param_1) {
    (**(code **)(*in_ECX + 0x10))(param_1,param_2);
    FUN_00797a50(auStack_a + -10,0,0xc);
    (**(code **)(*param_2 + 0x24))(auStack_a + -10);
  }
  return;
}


// ==== FUN_00610230 @ 0x00610230 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00610230(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b06c = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_00610250 @ 0x00610250 ====

void FUN_00610250(byte param_1)

{
  void *in_ECX;
  
  FUN_00610230();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00610270 @ 0x00610270 ====

void FUN_00610270(void)

{
  return;
}


// ==== FUN_00610280 @ 0x00610280 ====

undefined4 FUN_00610280(int param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)(**(code **)(*param_2 + 0x4c))();
  piVar2 = (int *)(**(code **)(*piVar2 + 0x10))();
  cVar1 = (**(code **)(*piVar2 + 0x44))();
  if (cVar1 == '\x01') {
    switch(*(undefined1 *)(param_1 + 0xb)) {
    case 6:
    case 10:
    case 0xf:
    case 0x11:
    case 0x12:
    case 0x15:
    case 0x16:
    case 0x17:
    case 0x1e:
    case 0x1f:
      return 0;
    }
  }
  return 1;
}


// ==== FUN_006102f0 @ 0x006102f0 ====

undefined1 FUN_006102f0(void)

{
  return 1;
}


// ==== FUN_00610300 @ 0x00610300 ====

undefined1 FUN_00610300(void)

{
  return 0;
}


// ==== FUN_00610310 @ 0x00610310 ====

int FUN_00610310(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_00610380 @ 0x00610380 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00610380(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc090;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b070 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b070 = in_ECX;
  return;
}


// ==== FUN_006103b0 @ 0x006103b0 ====

undefined4 FUN_006103b0(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  float fVar3;
  int unaff_retaddr;
  
  iVar1 = (**(code **)(*param_3 + 0x4c))();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x50) != 0)) {
    piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x50) + 0x14))(param_2);
    if (*(char *)(unaff_retaddr + 0xd) == '\x01') {
      iVar1 = (**(code **)(*piVar2 + 0x30))();
      fVar3 = *(float *)(iVar1 + 8) * DAT_0099d0f8;
    }
    else {
      iVar1 = (**(code **)(*piVar2 + 0x30))();
      fVar3 = *(float *)(iVar1 + 8);
    }
    fVar3 = fVar3 - (float)*(ushort *)(unaff_retaddr + 0xe) * DAT_009b3508;
    if (fVar3 <= 0.0) {
      fVar3 = 0.0 - fVar3;
    }
    if (DAT_009a09bc <= fVar3) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_00610440 @ 0x00610440 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_00610440(float param_1,int *param_2)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  uint *puVar4;
  int iVar5;
  int *piVar6;
  float *pfVar7;
  float fVar8;
  float unaff_retaddr;
  undefined4 uStack_34;
  undefined1 auStack_30 [8];
  float fStack_28;
  float fStack_24;
  undefined4 uStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  
  puVar4 = (uint *)(**(code **)(*param_2 + 0x10))();
  if ((uint)param_1 <= *puVar4) {
    iVar5 = (**(code **)(*param_2 + 0x10))();
    return (int *)(iVar5 + 4);
  }
  piVar6 = (int *)(**(code **)(*param_2 + 0x10))();
  pfVar7 = (float *)(**(code **)(*DAT_00b5ab40 + 4))((char)piVar6[3]);
  fStack_10 = *pfVar7;
  fStack_c = pfVar7[1];
  fStack_8 = pfVar7[2];
  fVar8 = (float)((int)param_1 - *piVar6);
  if ((int)param_1 - *piVar6 < 0) {
    fVar8 = fVar8 + _DAT_0099d104;
  }
  fVar8 = fVar8 * DAT_0099d0ec;
  if (DAT_009bac80 < fVar8) {
    return piVar6 + 1;
  }
  FUN_004f5730(&fStack_1c);
  fVar8 = fVar8 * unaff_retaddr;
  fStack_28 = fStack_1c;
  fStack_24 = fStack_18;
  uStack_20 = uStack_14;
  if (0.0 < fVar8) {
    uStack_14 = 0;
    do {
      param_1 = DAT_0099d080;
      if (fVar8 <= DAT_0099d080) {
        param_1 = fVar8;
      }
      fStack_1c = fStack_10 * param_1 + fStack_28;
      fStack_18 = fStack_c * param_1 + fStack_24;
      uVar2 = FUN_00802534();
      uVar3 = FUN_00802534();
      uStack_34 = CONCAT22(uVar3,uVar2);
      cVar1 = (**(code **)(*param_2 + 0x14))(&uStack_34);
      if (cVar1 == '\0') break;
      fVar8 = fVar8 - DAT_0099d080;
      fStack_28 = fStack_1c;
      fStack_24 = fStack_18;
      uStack_20 = 0;
    } while (DAT_0099cdc8 < fVar8);
  }
  FUN_004ef0e0(auStack_30);
  (**(code **)(*param_2 + 0x40))(auStack_30);
  piVar6 = (int *)FUN_00633b30();
  return piVar6;
}


// ==== FUN_00610610 @ 0x00610610 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00610610(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b070 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_00610630 @ 0x00610630 ====

void FUN_00610630(byte param_1)

{
  void *in_ECX;
  
  FUN_00610610();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00610650 @ 0x00610650 ====

void FUN_00610650(void)

{
  return;
}


// ==== FUN_00610660 @ 0x00610660 ====

bool FUN_00610660(uint *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return *(uint *)(iVar1 + 0xd) < *param_1;
}


// ==== FUN_00610680 @ 0x00610680 ====

int FUN_00610680(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_00610690 @ 0x00610690 ====

undefined1 FUN_00610690(void)

{
  return 0;
}


// ==== FUN_006106a0 @ 0x006106a0 ====

undefined1 FUN_006106a0(void)

{
  return 0;
}


// ==== FUN_006106b0 @ 0x006106b0 ====

int FUN_006106b0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  *(int *)((int)param_1 + 0xd) = *(int *)((int)param_1 + 0xd) + (param_2 - iVar1);
  return param_2 - iVar1;
}


// ==== FUN_006106d0 @ 0x006106d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006106d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc0b4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b074 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b074 = in_ECX;
  return;
}


// ==== FUN_00610700 @ 0x00610700 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00610700(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b074 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_00610720 @ 0x00610720 ====

void FUN_00610720(byte param_1)

{
  void *in_ECX;
  
  FUN_00610700();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00610740 @ 0x00610740 ====

void FUN_00610740(void)

{
  return;
}


// ==== FUN_00610750 @ 0x00610750 ====

undefined1 FUN_00610750(void)

{
  return 0;
}


// ==== FUN_00610760 @ 0x00610760 ====

int FUN_00610760(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_00610770 @ 0x00610770 ====

undefined1 FUN_00610770(void)

{
  return 1;
}


// ==== FUN_00610780 @ 0x00610780 ====

undefined1 FUN_00610780(void)

{
  return 0;
}


// ==== FUN_00610790 @ 0x00610790 ====

int FUN_00610790(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_006107b0 @ 0x006107b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006107b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc0d8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b078 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b078 = in_ECX;
  return;
}


// ==== FUN_006107e0 @ 0x006107e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006107e0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b078 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_00610800 @ 0x00610800 ====

void FUN_00610800(byte param_1)

{
  void *in_ECX;
  
  FUN_006107e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00610820 @ 0x00610820 ====

undefined4 FUN_00610820(uint *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = (**(code **)(*param_2 + 0x10))();
  if ((*(uint *)(iVar2 + 0xf) < *param_1) || (cVar1 = *(char *)((int)param_1 + 0xb), cVar1 == '\b'))
  {
    return 1;
  }
  if (((cVar1 == '\a') || (((cVar1 == '\f' || (cVar1 == '\r')) || (cVar1 == '\x0e')))) &&
     (puVar3 = (uint *)(**(code **)(*param_2 + 0x10))(), *puVar3 < *param_1)) {
    return 1;
  }
  return 0;
}


// ==== FUN_00610870 @ 0x00610870 ====

undefined1 FUN_00610870(void)

{
  return 1;
}


// ==== FUN_00610880 @ 0x00610880 ====

undefined1 FUN_00610880(void)

{
  return 0;
}


// ==== FUN_00610890 @ 0x00610890 ====

int FUN_00610890(byte param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return param_2 + 0x5c;
  }
  iVar1 = param_1 - 1;
  iVar2 = CONCAT31((int3)((uint)iVar1 >> 8),param_2);
  if (iVar1 == 0) {
    return iVar2 + 0xa3;
  }
  return iVar2 + 0x80;
}


// ==== FUN_006108c0 @ 0x006108c0 ====

int FUN_006108c0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  *(int *)((int)param_1 + 0xf) = *(int *)((int)param_1 + 0xf) + (param_2 - iVar1);
  return param_2 - iVar1;
}


// ==== FUN_00610920 @ 0x00610920 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00610920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc0fc;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b07c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b07c = in_ECX;
  return;
}


// ==== FUN_00610950 @ 0x00610950 ====

void FUN_00610950(uint param_1,int *param_2)

{
  int iVar1;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  if (*(uint *)(iVar1 + 0xf) < param_1) {
    (**(code **)(*in_ECX + 0x10))(param_1,param_2);
    FUN_00797a50(auStack_a + -10,0,0xc);
    (**(code **)(*param_2 + 0x24))(auStack_a + -10);
  }
  return;
}


// ==== FUN_006109d0 @ 0x006109d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * FUN_006109d0(uint param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  undefined1 uVar3;
  char cVar4;
  uint *puVar5;
  int iVar6;
  undefined4 uVar7;
  float *pfVar8;
  float fVar9;
  undefined4 unaff_retaddr;
  float fVar10;
  undefined1 auStack_22 [14];
  float fStack_14;
  float fStack_10;
  
  puVar5 = (uint *)(**(code **)(*param_2 + 0x10))();
  iVar6 = (**(code **)(*param_2 + 0x4c))();
  if (*(int *)(iVar6 + 0x50) == 0) {
    return puVar5 + 1;
  }
  (**(code **)(**(int **)(iVar6 + 0x50) + 0x14))(param_1);
  if ((param_1 <= *puVar5) || (iVar6 = *(int *)((int)puVar5 + 0xf) - *puVar5, iVar6 == 0)) {
    return puVar5 + 1;
  }
  uVar3 = FUN_00610890((char)puVar5[3],CONCAT31((int3)((uint)iVar6 >> 8),(char)puVar5[2]));
  uVar7 = (**(code **)(*param_2 + 0x4c))
                    (0,&Framework::ICreature::RTTI_Type_Descriptor,
                     &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  iVar6 = FUN_00803725(uVar7);
  if (iVar6 != 0) {
    uVar3 = (undefined1)puVar5[2];
  }
  fVar10 = (float)CONCAT31((int3)((uint)unaff_retaddr >> 8),uVar3);
  pfVar8 = (float *)(**(code **)(*DAT_00b5ab40 + 4))(fVar10);
  fVar1 = *pfVar8;
  fVar2 = pfVar8[1];
  fVar9 = (float)*(ushort *)((int)puVar5 + 0xd) * DAT_009b3508;
  FUN_004f5730(&fStack_14);
  fStack_14 = fStack_14 + fVar1 * fVar9 * fVar10;
  fStack_10 = fStack_10 + fVar2 * fVar9 * fVar10;
  FUN_004ef0e0(auStack_22 + -6);
  cVar4 = (**(code **)(*param_2 + 0x14))(auStack_22 + -10);
  if (cVar4 == '\0') {
    return puVar5 + 1;
  }
  (**(code **)(*param_2 + 0x40))(auStack_22 + -10);
  puVar5 = (uint *)FUN_00633b30();
  return puVar5;
}


// ==== FUN_00610bc0 @ 0x00610bc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00610bc0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b07c = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_00610be0 @ 0x00610be0 ====

void FUN_00610be0(byte param_1)

{
  void *in_ECX;
  
  FUN_00610bc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00610c00 @ 0x00610c00 ====

void FUN_00610c00(void)

{
  return;
}


// ==== FUN_00610c10 @ 0x00610c10 ====

undefined1 FUN_00610c10(void)

{
  return 0;
}


// ==== FUN_00610c20 @ 0x00610c20 ====

int FUN_00610c20(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_00610c30 @ 0x00610c30 ====

undefined1 FUN_00610c30(void)

{
  return 1;
}


// ==== FUN_00610c40 @ 0x00610c40 ====

undefined1 FUN_00610c40(void)

{
  return 0;
}


// ==== FUN_00610c50 @ 0x00610c50 ====

int FUN_00610c50(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_00610c70 @ 0x00610c70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00610c70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc120;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b080 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b080 = in_ECX;
  return;
}


// ==== FUN_00610ca0 @ 0x00610ca0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00610ca0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b080 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_00610cc0 @ 0x00610cc0 ====

void FUN_00610cc0(byte param_1)

{
  void *in_ECX;
  
  FUN_00610ca0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00610ce0 @ 0x00610ce0 ====

bool FUN_00610ce0(uint *param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return *(uint *)(iVar1 + 0xd) < *param_1;
}


// ==== FUN_00610d00 @ 0x00610d00 ====

int FUN_00610d00(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_00610d10 @ 0x00610d10 ====

undefined1 FUN_00610d10(void)

{
  return 0;
}


// ==== FUN_00610d20 @ 0x00610d20 ====

undefined4 FUN_00610d20(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0xd);
  return 1;
}


// ==== FUN_00610d40 @ 0x00610d40 ====

int FUN_00610d40(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  *(int *)((int)param_1 + 0xd) = *(int *)((int)param_1 + 0xd) + (param_2 - iVar1);
  return param_2 - iVar1;
}


// ==== FUN_00610d60 @ 0x00610d60 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00610d60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc144;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b084 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b084 = in_ECX;
  return;
}


// ==== FUN_00610d90 @ 0x00610d90 ====

void FUN_00610d90(uint param_1,int *param_2)

{
  int iVar1;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  if (*(uint *)(iVar1 + 0xd) < param_1) {
    (**(code **)(*in_ECX + 0x10))(param_1,param_2);
    FUN_00797a50(auStack_a + -10,0,0xc);
    (**(code **)(*param_2 + 0x24))(auStack_a + -10);
  }
  return;
}


// ==== FUN_00610e10 @ 0x00610e10 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00610e10(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b084 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_00610e30 @ 0x00610e30 ====

void FUN_00610e30(byte param_1)

{
  void *in_ECX;
  
  FUN_00610e10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00610e50 @ 0x00610e50 ====

undefined4 FUN_00610e50(uint *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  
  iVar2 = (**(code **)(*param_2 + 0x10))();
  if (*param_1 <= *(uint *)(iVar2 + 0x11)) {
    cVar1 = *(char *)((int)param_1 + 0xb);
    if ((((cVar1 != '\a') && (cVar1 != '\f')) && (cVar1 != '\r')) &&
       ((cVar1 != '\x0e' && (cVar1 != '\b')))) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_00610e90 @ 0x00610e90 ====

undefined1 FUN_00610e90(void)

{
  return 1;
}


// ==== FUN_00610ea0 @ 0x00610ea0 ====

undefined1 FUN_00610ea0(void)

{
  return 0;
}


// ==== FUN_00610eb0 @ 0x00610eb0 ====

int FUN_00610eb0(byte param_1,byte param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return param_2 + 0x5c;
  }
  iVar1 = param_1 - 1;
  iVar2 = CONCAT31((int3)((uint)iVar1 >> 8),param_2);
  if (iVar1 == 0) {
    return iVar2 + 0xa3;
  }
  return iVar2 + 0x80;
}


// ==== FUN_00610ee0 @ 0x00610ee0 ====

int FUN_00610ee0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  *(int *)((int)param_1 + 0x11) = *(int *)((int)param_1 + 0x11) + (param_2 - iVar1);
  return param_2 - iVar1;
}


// ==== FUN_00610f40 @ 0x00610f40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00610f40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc168;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b088 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b088 = in_ECX;
  return;
}


// ==== FUN_00610f70 @ 0x00610f70 ====

void FUN_00610f70(uint param_1,int *param_2)

{
  int iVar1;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  if (*(uint *)(iVar1 + 0x11) < param_1) {
    (**(code **)(*in_ECX + 0x10))(param_1,param_2);
    FUN_00797a50(auStack_a + -10,0,0xc);
    (**(code **)(*param_2 + 0x24))(auStack_a + -10);
  }
  return;
}


// ==== FUN_00610ff0 @ 0x00610ff0 ====

uint * FUN_00610ff0(uint param_1,int *param_2)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  float *pfVar5;
  float fVar6;
  undefined4 unaff_retaddr;
  undefined1 auStack_34 [2];
  undefined1 auStack_32 [6];
  float fStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  float fStack_20;
  float afStack_1c [3];
  float fStack_10;
  float fStack_c;
  float fStack_4;
  
  puVar2 = (uint *)(**(code **)(*param_2 + 0x10))();
  iVar3 = (**(code **)(*param_2 + 0x4c))();
  if (*(int *)(iVar3 + 0x50) != 0) {
    (**(code **)(**(int **)(iVar3 + 0x50) + 0x14))(param_1);
    if ((*puVar2 < param_1) && (*puVar2 < *(uint *)((int)puVar2 + 0x11))) {
      cVar1 = FUN_00610eb0((char)puVar2[3],(char)puVar2[2]);
      uVar4 = (**(code **)(*param_2 + 0x4c))
                        (0,&Framework::ICreature::RTTI_Type_Descriptor,
                         &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
      iVar3 = FUN_00803725(uVar4);
      if (iVar3 != 0) {
        cVar1 = (char)puVar2[2] + -0x80;
      }
      fVar6 = (float)CONCAT31((int3)((uint)unaff_retaddr >> 8),cVar1);
      FUN_004f5730(afStack_1c);
      pfVar5 = (float *)(**(code **)(*DAT_00b5ab40 + 4))(fVar6);
      afStack_1c[2] = *pfVar5;
      fStack_10 = pfVar5[1];
      fStack_c = pfVar5[2];
      if (0.0 < fVar6) {
        uStack_24 = 0;
        do {
          fStack_4 = DAT_0099d080;
          if (fVar6 <= DAT_0099d080) {
            fStack_4 = fVar6;
          }
          fStack_2c = afStack_1c[2] * fStack_4 + fStack_20;
          fStack_28 = fStack_10 * fStack_4 + afStack_1c[0];
          FUN_00802534();
          FUN_00802534();
          cVar1 = (**(code **)(*param_2 + 0x14))(auStack_34 + -4);
          if (cVar1 == '\0') break;
          fVar6 = fVar6 - DAT_0099d080;
          fStack_20 = fStack_2c;
          afStack_1c[0] = fStack_28;
          afStack_1c[1] = 0.0;
        } while (DAT_0099cdc8 < fVar6);
      }
      FUN_004ef0e0(auStack_34);
      (**(code **)(*param_2 + 0x40))(auStack_34);
      puVar2 = (uint *)FUN_00633b30();
      return puVar2;
    }
  }
  return puVar2 + 1;
}


// ==== FUN_006111b0 @ 0x006111b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006111b0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b088 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_006111d0 @ 0x006111d0 ====

void FUN_006111d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006111b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006111f0 @ 0x006111f0 ====

void FUN_006111f0(void)

{
  return;
}


// ==== FUN_00611200 @ 0x00611200 ====

bool FUN_00611200(int param_1)

{
  return *(char *)(param_1 + 0xb) == '\t';
}


// ==== FUN_00611210 @ 0x00611210 ====

int FUN_00611210(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_00611220 @ 0x00611220 ====

undefined1 FUN_00611220(void)

{
  return 0;
}


// ==== FUN_00611230 @ 0x00611230 ====

undefined1 FUN_00611230(void)

{
  return 0;
}


// ==== FUN_00611240 @ 0x00611240 ====

int FUN_00611240(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  return param_2 - iVar1;
}


// ==== FUN_00611260 @ 0x00611260 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00611260(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc18c;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b08c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b08c = in_ECX;
  return;
}


// ==== FUN_00611290 @ 0x00611290 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00611290(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b08c = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_006112b0 @ 0x006112b0 ====

void FUN_006112b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00611290();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006112d0 @ 0x006112d0 ====

undefined4 FUN_006112d0(uint *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = (**(code **)(*param_2 + 0x10))();
  if ((*(uint *)(iVar2 + 0xf) < *param_1) || (cVar1 = *(char *)((int)param_1 + 0xb), cVar1 == '\b'))
  {
    return 1;
  }
  if (((cVar1 == '\a') || (((cVar1 == '\f' || (cVar1 == '\r')) || (cVar1 == '\x0e')))) &&
     (puVar3 = (uint *)(**(code **)(*param_2 + 0x10))(), *puVar3 < *param_1)) {
    return 1;
  }
  return 0;
}


// ==== FUN_00611320 @ 0x00611320 ====

int FUN_00611320(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_00611330 @ 0x00611330 ====

undefined1 FUN_00611330(void)

{
  return 1;
}


// ==== FUN_00611340 @ 0x00611340 ====

undefined1 FUN_00611340(void)

{
  return 0;
}


// ==== FUN_00611350 @ 0x00611350 ====

int FUN_00611350(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  *(int *)((int)param_1 + 0xf) = *(int *)((int)param_1 + 0xf) + (param_2 - iVar1);
  return param_2 - iVar1;
}


// ==== FUN_00611370 @ 0x00611370 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00611370(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc1b0;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b090 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b090 = in_ECX;
  return;
}


// ==== FUN_006113a0 @ 0x006113a0 ====

void FUN_006113a0(uint param_1,int *param_2)

{
  int iVar1;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  if (*(uint *)(iVar1 + 0xf) < param_1) {
    (**(code **)(*in_ECX + 0x10))(param_1,param_2);
    FUN_00797a50(auStack_a + -10,0,0xc);
    (**(code **)(*param_2 + 0x24))(auStack_a + -10);
  }
  return;
}


// ==== FUN_00611420 @ 0x00611420 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00611420(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b090 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_00611440 @ 0x00611440 ====

void FUN_00611440(byte param_1)

{
  void *in_ECX;
  
  FUN_00611420();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00611460 @ 0x00611460 ====

undefined4 FUN_00611460(uint *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = (**(code **)(*param_2 + 0x10))();
  if ((*(uint *)(iVar2 + 0xf) < *param_1) || (cVar1 = *(char *)((int)param_1 + 0xb), cVar1 == '\b'))
  {
    return 1;
  }
  if (((cVar1 == '\a') || (((cVar1 == '\f' || (cVar1 == '\r')) || (cVar1 == '\x0e')))) &&
     (puVar3 = (uint *)(**(code **)(*param_2 + 0x10))(), *puVar3 < *param_1)) {
    return 1;
  }
  return 0;
}


// ==== FUN_006114b0 @ 0x006114b0 ====

int FUN_006114b0(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_006114c0 @ 0x006114c0 ====

undefined1 FUN_006114c0(void)

{
  return 1;
}


// ==== FUN_006114d0 @ 0x006114d0 ====

undefined1 FUN_006114d0(void)

{
  return 0;
}


// ==== FUN_006114e0 @ 0x006114e0 ====

int FUN_006114e0(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  *(int *)((int)param_1 + 0xf) = *(int *)((int)param_1 + 0xf) + (param_2 - iVar1);
  return param_2 - iVar1;
}


// ==== FUN_00611500 @ 0x00611500 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00611500(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc1d4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b094 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b094 = in_ECX;
  return;
}


// ==== FUN_00611530 @ 0x00611530 ====

void FUN_00611530(uint param_1,int *param_2)

{
  int iVar1;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  if (*(uint *)(iVar1 + 0xf) < param_1) {
    (**(code **)(*in_ECX + 0x10))(param_1,param_2);
    FUN_00797a50(auStack_a + -10,0,0xc);
    (**(code **)(*param_2 + 0x24))(auStack_a + -10);
  }
  return;
}


// ==== FUN_006115b0 @ 0x006115b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006115b0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b094 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_006115d0 @ 0x006115d0 ====

void FUN_006115d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006115b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006115f0 @ 0x006115f0 ====

int FUN_006115f0(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  return iVar1 + 4;
}


// ==== FUN_00611600 @ 0x00611600 ====

undefined1 FUN_00611600(void)

{
  return 1;
}


// ==== FUN_00611610 @ 0x00611610 ====

undefined4 FUN_00611610(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0xf);
  return 1;
}


// ==== FUN_00611630 @ 0x00611630 ====

int FUN_00611630(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = param_2;
  *(int *)((int)param_1 + 0xf) = *(int *)((int)param_1 + 0xf) + (param_2 - iVar1);
  return param_2 - iVar1;
}


// ==== FUN_00611660 @ 0x00611660 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00611660(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc1f8;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b098 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b098 = in_ECX;
  return;
}


// ==== FUN_00611690 @ 0x00611690 ====

void FUN_00611690(uint param_1,int *param_2)

{
  int iVar1;
  int *in_ECX;
  undefined1 auStack_a [10];
  
  iVar1 = (**(code **)(*param_2 + 0x10))();
  if (*(uint *)(iVar1 + 0xf) < param_1) {
    (**(code **)(*in_ECX + 0x10))(param_1,param_2);
    FUN_00797a50(auStack_a + -10,0,0xc);
    (**(code **)(*param_2 + 0x24))(auStack_a + -10);
  }
  return;
}


// ==== FUN_00611710 @ 0x00611710 ====

uint FUN_00611710(undefined4 param_1,undefined4 param_2,int *param_3)

{
  uint uVar1;
  int *piVar2;
  float *pfVar3;
  int iVar4;
  int *unaff_retaddr;
  undefined1 auStack_a [10];
  
  uVar1 = (**(code **)(*param_3 + 0x4c))();
  if ((uVar1 == 0) || (*(int *)(uVar1 + 0x50) == 0)) {
    return uVar1 & 0xffffff00;
  }
  piVar2 = (int *)(**(code **)(**(int **)(uVar1 + 0x50) + 0x14))(param_2);
  pfVar3 = (float *)(**(code **)(*piVar2 + 0x30))();
  piVar2 = (int *)(**(code **)(*param_3 + 0x48))();
  if (piVar2 != (int *)0x0) {
    iVar4 = (**(code **)(*piVar2 + 0xc))(auStack_a + -6);
    if (iVar4 != 0) {
      iVar4 = (*(int *)((int)unaff_retaddr + 0xf) -
              (int)(*(float *)(iVar4 + 0x114) * *pfVar3 * DAT_009b012c)) - *unaff_retaddr;
      if (iVar4 < 1) {
        iVar4 = -iVar4;
      }
      return CONCAT31((int3)((uint)iVar4 >> 8),iVar4 < 100);
    }
  }
  return 0;
}


// ==== FUN_006117c0 @ 0x006117c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_006117c0(uint *param_1,int *param_2)

{
  char cVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  uint *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  undefined1 auStack_c [4];
  undefined4 uStack_8;
  uint uStack_4;
  
  puVar5 = (uint *)(**(code **)(*param_2 + 0x10))();
  if (((((*(uint *)((int)puVar5 + 0xf) < *param_1) ||
        (cVar1 = *(char *)((int)param_1 + 0xb), cVar1 == '\a')) || (cVar1 == '\f')) ||
      ((cVar1 == '\r' || (cVar1 == '\x0e')))) || (cVar1 == '\b')) {
    return 1;
  }
  if (((cVar1 == '\x06') || (cVar1 == '\n')) &&
     (piVar6 = (int *)(**(code **)(*param_2 + 0x48))(), piVar6 != (int *)0x0)) {
    auStack_c[0] = *(undefined1 *)((int)puVar5 + 10);
    uStack_8 = 6;
    uStack_4 = (uint)*(byte *)((int)puVar5 + 0xe);
    iVar7 = (**(code **)(*piVar6 + 0xc))(auStack_c);
    if (iVar7 != 0) {
      uVar2 = *puVar5;
      if (uVar2 <= *param_1) {
        if (*(uint *)((int)puVar5 + 0xf) <= uVar2) {
          return 1;
        }
        iVar8 = *param_1 - uVar2;
        fVar3 = (float)iVar8;
        if (iVar8 < 0) {
          fVar3 = fVar3 + _DAT_0099d104;
        }
        iVar8 = *(uint *)((int)puVar5 + 0xf) - uVar2;
        fVar4 = (float)iVar8;
        if (iVar8 < 0) {
          fVar4 = fVar4 + _DAT_0099d104;
        }
        if (*(float *)(iVar7 + 0x124) < fVar3 / fVar4) {
          return 1;
        }
        return 0;
      }
    }
  }
  return 0;
}


// ==== FUN_006118c0 @ 0x006118c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006118c0(void)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b098 = 0;
  *in_ECX = &PTR_FUN_009cbdc0;
  return;
}


// ==== FUN_006118e0 @ 0x006118e0 ====

void FUN_006118e0(byte param_1)

{
  void *in_ECX;
  
  FUN_006118c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00611900 @ 0x00611900 ====

void FUN_00611900(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cbbc0;
  return;
}


// ==== FUN_00611910 @ 0x00611910 ====

void FUN_00611910(void)

{
  return;
}


// ==== FUN_00611920 @ 0x00611920 ====

void FUN_00611920(void)

{
  return;
}


// ==== FUN_00611930 @ 0x00611930 ====

undefined4 FUN_00611930(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = *param_1;
  return 1;
}


// ==== FUN_00611940 @ 0x00611940 ====

int FUN_00611940(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00611950 @ 0x00611950 ====

void FUN_00611950(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00611960 @ 0x00611960 ====

void FUN_00611960(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc21c;
  return;
}


// ==== FUN_00611970 @ 0x00611970 ====

undefined4 FUN_00611970(void)

{
  return 0xd;
}


// ==== FUN_00611980 @ 0x00611980 ====

void FUN_00611980(byte param_1)

{
  void *in_ECX;
  
  FUN_00611900();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006119a0 @ 0x006119a0 ====

void FUN_006119a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc234;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006119c0 @ 0x006119c0 ====

void FUN_006119c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc234;
  return;
}


// ==== FUN_006119d0 @ 0x006119d0 ====

void FUN_006119d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009880a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc24c;
  local_4 = 0;
  FUN_00633d30();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00611a20 @ 0x00611a20 ====

void FUN_00611a20(void)

{
  return;
}


// ==== FUN_00611a30 @ 0x00611a30 ====

int FUN_00611a30(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00611a40 @ 0x00611a40 ====

void FUN_00611a40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009880ba;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc24c;
  FUN_00633d80();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00611a90 @ 0x00611a90 ====

undefined4 FUN_00611a90(void)

{
  return 0x29;
}


// ==== FUN_00611aa0 @ 0x00611aa0 ====

void FUN_00611aa0(byte param_1)

{
  void *in_ECX;
  
  FUN_006119d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00611ac0 @ 0x00611ac0 ====

void FUN_00611ac0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009880d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc268;
  local_4 = 0;
  FUN_00633df0();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00611b10 @ 0x00611b10 ====

void FUN_00611b10(void)

{
  return;
}


// ==== FUN_00611b20 @ 0x00611b20 ====

int FUN_00611b20(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00611b30 @ 0x00611b30 ====

int FUN_00611b30(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00611b40 @ 0x00611b40 ====

void FUN_00611b40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009880ea;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc268;
  FUN_00633e30();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00611b90 @ 0x00611b90 ====

undefined4 FUN_00611b90(void)

{
  return 0x20;
}


// ==== FUN_00611ba0 @ 0x00611ba0 ====

undefined4 FUN_00611ba0(void)

{
  return 0x28;
}


// ==== FUN_00611bb0 @ 0x00611bb0 ====

void FUN_00611bb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00611ac0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00611bd0 @ 0x00611bd0 ====

void FUN_00611bd0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*(int *)(in_ECX + 0x10) + 8))(param_1);
  if (cVar1 == '\0') {
    return;
  }
  *(short *)(in_ECX + 8) = (short)param_1;
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 4);
  *(undefined1 *)(in_ECX + 0x1c) = 1;
  return;
}


// ==== FUN_00611c00 @ 0x00611c00 ====

int FUN_00611c00(void)

{
  int in_ECX;
  
  return in_ECX + 0x10;
}


// ==== FUN_00611c10 @ 0x00611c10 ====

undefined2 FUN_00611c10(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 8);
}


// ==== FUN_00611c20 @ 0x00611c20 ====

undefined1 FUN_00611c20(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x1c);
}


// ==== FUN_00611c30 @ 0x00611c30 ====

void FUN_00611c30(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = param_1;
  return;
}


// ==== FUN_00611c40 @ 0x00611c40 ====

undefined4 FUN_00611c40(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x20);
}


// ==== FUN_00611c50 @ 0x00611c50 ====

void FUN_00611c50(void)

{
  int in_ECX;
  
  (**(code **)(*(int *)(in_ECX + 0x10) + 0xc))();
  *(undefined2 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  return;
}


// ==== FUN_00611c70 @ 0x00611c70 ====

void FUN_00611c70(void)

{
  int in_ECX;
  
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))();
  *(undefined2 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  return;
}


// ==== FUN_00611c90 @ 0x00611c90 ====

void FUN_00611c90(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988113;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cc288;
  FUN_00633ec0();
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(in_ECX[4] + 0x10))();
  *(undefined2 *)(in_ECX + 2) = 0;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  in_ECX[8] = 0;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00611d00 @ 0x00611d00 ====

void FUN_00611d00(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00988130;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cc288;
  local_4 = 1;
  (**(code **)(in_ECX[4] + 0xc))();
  *(undefined2 *)(in_ECX + 2) = 0;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 7) = 0;
  in_ECX[8] = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_00633e60();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00611d70 @ 0x00611d70 ====

undefined4 FUN_00611d70(void)

{
  return 0x27;
}


// ==== FUN_00611d80 @ 0x00611d80 ====

void FUN_00611d80(byte param_1)

{
  void *in_ECX;
  
  FUN_00611d00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00611da0 @ 0x00611da0 ====

void FUN_00611da0(undefined4 param_1)

{
  char cVar1;
  int in_ECX;
  
  cVar1 = (**(code **)(*(int *)(in_ECX + 0xc) + 8))(param_1);
  if (cVar1 == '\0') {
    return;
  }
  *(short *)(in_ECX + 0x18) = (short)param_1;
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
  *(undefined1 *)(in_ECX + 0x1a) = 1;
  return;
}


// ==== FUN_00611dd0 @ 0x00611dd0 ====

int FUN_00611dd0(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_00611de0 @ 0x00611de0 ====

undefined2 FUN_00611de0(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x18);
}


// ==== FUN_00611df0 @ 0x00611df0 ====

undefined1 FUN_00611df0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x1a);
}


// ==== FUN_00611e00 @ 0x00611e00 ====

void FUN_00611e00(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1c) = param_1;
  return;
}


// ==== FUN_00611e10 @ 0x00611e10 ====

undefined4 FUN_00611e10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1c);
}


// ==== FUN_00611e20 @ 0x00611e20 ====

void FUN_00611e20(void)

{
  int in_ECX;
  
  (**(code **)(*(int *)(in_ECX + 0xc) + 0x10))();
  *(undefined2 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined1 *)(in_ECX + 0x1a) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  return;
}


// ==== FUN_00611e40 @ 0x00611e40 ====

void FUN_00611e40(void)

{
  int in_ECX;
  
  (**(code **)(*(int *)(in_ECX + 0xc) + 0xc))();
  *(undefined2 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined1 *)(in_ECX + 0x1a) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  return;
}


// ==== FUN_00611e60 @ 0x00611e60 ====

void FUN_00611e60(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988153;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cc2bc;
  FUN_00633f50();
  local_4 = CONCAT31(local_4._1_3_,1);
  (**(code **)(in_ECX[3] + 0x10))();
  *(undefined2 *)(in_ECX + 6) = 0;
  in_ECX[2] = 0;
  *(undefined1 *)((int)in_ECX + 0x1a) = 0;
  in_ECX[7] = 0;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00611ed0 @ 0x00611ed0 ====

void FUN_00611ed0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00988170;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cc2bc;
  local_4 = 1;
  (**(code **)(in_ECX[3] + 0xc))();
  *(undefined2 *)(in_ECX + 6) = 0;
  in_ECX[2] = 0;
  *(undefined1 *)((int)in_ECX + 0x1a) = 0;
  in_ECX[7] = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_00633ef0();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00611f40 @ 0x00611f40 ====

undefined4 FUN_00611f40(void)

{
  return 0x26;
}


// ==== FUN_00611f50 @ 0x00611f50 ====

void FUN_00611f50(byte param_1)

{
  void *in_ECX;
  
  FUN_00611ed0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00611f70 @ 0x00611f70 ====

int FUN_00611f70(void)

{
  int in_ECX;
  
  return in_ECX + 0x10;
}


// ==== FUN_00611f80 @ 0x00611f80 ====

undefined2 FUN_00611f80(void)

{
  int in_ECX;
  
  return *(undefined2 *)(in_ECX + 0x20);
}


// ==== FUN_00611f90 @ 0x00611f90 ====

undefined4 FUN_00611f90(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 2) {
    return *(undefined4 *)(in_ECX + 0x24);
  }
  return 0;
}


// ==== FUN_00611fa0 @ 0x00611fa0 ====

undefined4 FUN_00611fa0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}


// ==== FUN_00611fb0 @ 0x00611fb0 ====

undefined4 FUN_00611fb0(int *param_1)

{
  short *psVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    psVar1 = (short *)(**(code **)(*param_1 + 0x14))();
    if (*psVar1 == *(short *)(in_ECX + 0x20)) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_00611fe0 @ 0x00611fe0 ====

uint FUN_00611fe0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = (int *)(**(code **)(*param_1 + 0x48))();
  iVar2 = (**(code **)(*piVar1 + 4))();
  iVar2 = *(int *)(iVar2 + 8);
  iVar3 = (**(code **)(*piVar1 + 4))();
  if ((iVar2 == 6) && (*(uint *)(iVar3 + 0xc) == 0x604)) {
    return 0x601;
  }
  return *(uint *)(iVar3 + 0xc) & 0xffffff00;
}


// ==== FUN_00612020 @ 0x00612020 ====

undefined4 FUN_00612020(int param_1)

{
  int in_ECX;
  
  switch(*(undefined4 *)(in_ECX + 0xc)) {
  case 0:
    if ((param_1 == 1) || (param_1 == 0)) {
      return 1;
    }
    break;
  case 1:
    if ((param_1 == 2) || (param_1 == 1)) {
      return 1;
    }
    break;
  case 2:
    if ((param_1 == 3) || (param_1 == 2)) {
      return 1;
    }
    break;
  case 3:
    if ((param_1 == 0) || (param_1 == 3)) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00612090 @ 0x00612090 ====

void FUN_00612090(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x2c) != '\0') {
    *(undefined4 *)(in_ECX + 0xc) = param_1;
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x10))();
    (**(code **)(*piVar1 + 0x24))();
  }
  return;
}


// ==== FUN_006120b0 @ 0x006120b0 ====

undefined4 FUN_006120b0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_006120c0 @ 0x006120c0 ====

void FUN_006120c0(void)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0x15;
                    /* WARNING: Could not recover jumptable at 0x006120df. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))();
  return;
}


// ==== FUN_006120f0 @ 0x006120f0 ====

void FUN_006120f0(void)

{
  int *piVar1;
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0x15;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined1 *)(in_ECX + 0x2c) = 0;
  (**(code **)(*(int *)(in_ECX + 0x10) + 0xc))();
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x10))();
    (**(code **)(*piVar1 + 0x24))();
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00612130 @ 0x00612130 ====

undefined4 FUN_00612130(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  short *psVar6;
  int *in_ECX;
  short unaff_BX;
  int *unaff_ESI;
  undefined4 unaff_retaddr;
  
  cVar1 = (**(code **)(*in_ECX + 0x38))(0);
  if (cVar1 != '\0') {
    (**(code **)(*in_ECX + 0x14))();
    cVar1 = (**(code **)(in_ECX[4] + 8))(unaff_retaddr);
    if (cVar1 != '\0') {
      iVar2 = FUN_00803725(in_ECX[1],0,&Framework::ICreature::RTTI_Type_Descriptor,
                           &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
      in_ECX[2] = iVar2;
      piVar5 = *(int **)(iVar2 + 0x24);
      piVar3 = (int *)(**(code **)(*piVar5 + 0x2c))(6);
      piVar4 = (int *)(**(code **)(*piVar5 + 0x2c))(7);
      (**(code **)(*piVar5 + 0x2c))(0x13);
      piVar5 = (int *)(**(code **)(*piVar5 + 0x2c))(0x14);
      if ((((piVar3 == (int *)0x0) && (piVar4 == (int *)0x0)) && (unaff_ESI == (int *)0x0)) &&
         (piVar5 == (int *)0x0)) {
        return 0;
      }
      in_ECX[9] = 0;
      if ((piVar3 != (int *)0x0) &&
         (psVar6 = (short *)(**(code **)(*piVar3 + 0x14))(), unaff_BX == *psVar6)) {
        in_ECX[9] = 7;
        in_ECX[10] = 6;
      }
      if ((piVar4 != (int *)0x0) &&
         (psVar6 = (short *)(**(code **)(*piVar4 + 0x14))(), unaff_BX == *psVar6)) {
        in_ECX[9] = 8;
        in_ECX[10] = 7;
      }
      if ((unaff_ESI != (int *)0x0) &&
         (psVar6 = (short *)(**(code **)(*unaff_ESI + 0x14))(), unaff_BX == *psVar6)) {
        in_ECX[9] = 9;
        in_ECX[10] = 0x13;
      }
      if ((piVar5 != (int *)0x0) &&
         (psVar6 = (short *)(**(code **)(*piVar5 + 0x14))(), unaff_BX == *psVar6)) {
        in_ECX[9] = 10;
        in_ECX[10] = 0x14;
      }
      *(short *)(in_ECX + 8) = unaff_BX;
      in_ECX[3] = 0;
      *(undefined1 *)(in_ECX + 0xb) = 1;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00612270 @ 0x00612270 ====

undefined4 FUN_00612270(undefined4 *param_1)

{
  int iVar1;
  int *piVar2;
  short *psVar3;
  int in_ECX;
  
  iVar1 = FUN_00803725(*(undefined4 *)(in_ECX + 4),0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  piVar2 = (int *)(**(code **)(**(int **)(iVar1 + 0x24) + 0x2c))(*param_1);
  if ((piVar2 != (int *)0x0) && (*(int *)(in_ECX + 0xc) != 0)) {
    psVar3 = (short *)(**(code **)(*piVar2 + 0x14))();
    if (*psVar3 == *(short *)(in_ECX + 0x20)) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_006122d0 @ 0x006122d0 ====

void FUN_006122d0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988193;
  pvStack_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cc2f4;
  FUN_00634010();
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined2 *)(in_ECX + 8) = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0x15;
  in_ECX[3] = 0;
  in_ECX[2] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  (**(code **)(in_ECX[4] + 0x10))();
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00612340 @ 0x00612340 ====

void FUN_00612340(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009881b0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cc2f4;
  local_4 = 1;
  *(undefined2 *)(in_ECX + 8) = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0x15;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 0xb) = 0;
  (**(code **)(in_ECX[4] + 0xc))();
  if ((int *)in_ECX[2] != (int *)0x0) {
    piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 0x10))();
    (**(code **)(*piVar1 + 0x24))();
  }
  in_ECX[2] = 0;
  local_4 = local_4 & 0xffffff00;
  FUN_00633f80();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006123d0 @ 0x006123d0 ====

void FUN_006123d0(byte param_1)

{
  void *in_ECX;
  
  FUN_00612340();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006123f0 @ 0x006123f0 ====

void FUN_006123f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009881c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc33c;
  local_4 = 0;
  FUN_00634040();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612440 @ 0x00612440 ====

void FUN_00612440(void)

{
  return;
}


// ==== FUN_00612450 @ 0x00612450 ====

int FUN_00612450(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00612460 @ 0x00612460 ====

int FUN_00612460(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00612470 @ 0x00612470 ====

void FUN_00612470(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009881da;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc33c;
  FUN_00634070();
  ExceptionList = local_c;
  return;
}


// ==== FUN_006124c0 @ 0x006124c0 ====

undefined4 FUN_006124c0(void)

{
  return 0x24;
}


// ==== FUN_006124d0 @ 0x006124d0 ====

void FUN_006124d0(byte param_1)

{
  void *in_ECX;
  
  FUN_006123f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006124f0 @ 0x006124f0 ====

void FUN_006124f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009881f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc35c;
  local_4 = 0;
  FUN_006340e0();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612540 @ 0x00612540 ====

void FUN_00612540(void)

{
  return;
}


// ==== FUN_00612550 @ 0x00612550 ====

int FUN_00612550(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00612560 @ 0x00612560 ====

void FUN_00612560(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098820a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc35c;
  FUN_006341d0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_006125b0 @ 0x006125b0 ====

undefined4 FUN_006125b0(void)

{
  return 0x23;
}


// ==== FUN_006125c0 @ 0x006125c0 ====

void FUN_006125c0(byte param_1)

{
  void *in_ECX;
  
  FUN_006124f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006125e0 @ 0x006125e0 ====

void FUN_006125e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988228;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc378;
  local_4 = 0;
  FUN_00634240();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612630 @ 0x00612630 ====

int FUN_00612630(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00612640 @ 0x00612640 ====

int FUN_00612640(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00612650 @ 0x00612650 ====

void FUN_00612650(void)

{
  return;
}


// ==== FUN_00612660 @ 0x00612660 ====

void FUN_00612660(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098823a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc378;
  FUN_006342a0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_006126b0 @ 0x006126b0 ====

void FUN_006126b0(byte param_1)

{
  void *in_ECX;
  
  FUN_006125e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006126d0 @ 0x006126d0 ====

void FUN_006126d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988258;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc398;
  local_4 = 0;
  FUN_00634500();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612720 @ 0x00612720 ====

void FUN_00612720(void)

{
  return;
}


// ==== FUN_00612730 @ 0x00612730 ====

int FUN_00612730(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00612740 @ 0x00612740 ====

void FUN_00612740(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098826a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc398;
  FUN_00634570();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612790 @ 0x00612790 ====

void FUN_00612790(byte param_1)

{
  void *in_ECX;
  
  FUN_006126d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006127b0 @ 0x006127b0 ====

void FUN_006127b0(void)

{
  int in_ECX;
  
  (**(code **)(*(int *)(in_ECX + 8) + 0x10))();
  (**(code **)(**(int **)(in_ECX + 0x2c) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x30) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x34) + 0x10))();
  (**(code **)(**(int **)(in_ECX + 0x34) + 0x1c))(*(undefined4 *)(in_ECX + 4));
  *(undefined1 *)(in_ECX + 0x38) = 0;
  *(undefined1 *)(in_ECX + 0x39) = 0;
  return;
}


// ==== FUN_006127f0 @ 0x006127f0 ====

int FUN_006127f0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00612800 @ 0x00612800 ====

int FUN_00612800(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00612810 @ 0x00612810 ====

void FUN_00612810(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x2c) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x30) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x34) + 0x10))();
  *(undefined1 *)(in_ECX + 0x38) = 0;
  *(undefined1 *)(in_ECX + 0x39) = 0;
  return;
}


// ==== FUN_00612840 @ 0x00612840 ====

undefined1 FUN_00612840(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x38);
}


// ==== FUN_00612850 @ 0x00612850 ====

undefined4 FUN_00612850(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2c);
}


// ==== FUN_00612860 @ 0x00612860 ====

undefined1 FUN_00612860(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x39);
}


// ==== FUN_00612870 @ 0x00612870 ====

undefined4 FUN_00612870(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}


// ==== FUN_00612880 @ 0x00612880 ====

undefined4 FUN_00612880(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x34);
}


// ==== FUN_00612890 @ 0x00612890 ====

void FUN_00612890(void)

{
  return;
}


// ==== FUN_006128a0 @ 0x006128a0 ====

void FUN_006128a0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00988293;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cc3b4;
  local_4 = 1;
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
  local_4 = local_4 & 0xffffff00;
  FUN_00634630();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00612930 @ 0x00612930 ====

int FUN_00612930(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x2c))();
  if (cVar1 != '\x01') {
    cVar1 = (**(code **)(*in_ECX + 0x34))();
    if (cVar1 != '\x01') {
      *(undefined1 *)(in_ECX + 0xe) = 1;
      *(undefined1 *)((int)in_ECX + 0x39) = 0;
      (**(code **)(*(int *)in_ECX[0xb] + 4))(param_1,param_2);
      return in_ECX[0xb];
    }
  }
  return 0;
}


// ==== FUN_00612970 @ 0x00612970 ====

int * FUN_00612970(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x2c))();
  if (cVar1 != '\0') {
    iVar2 = FUN_00826bf0(in_ECX[1]);
    if (iVar2 != 0) {
      cVar1 = (**(code **)(in_ECX[2] + 0xc))(param_1,iVar2,param_2);
      if (cVar1 == '\0') {
        return (int *)0x0;
      }
      *(undefined1 *)(in_ECX + 0xe) = 0;
      *(undefined1 *)((int)in_ECX + 0x39) = 1;
      (**(code **)(*(int *)in_ECX[0xd] + 0xc))(param_2);
      return in_ECX + 2;
    }
  }
  return (int *)0x0;
}


// ==== FUN_006129d0 @ 0x006129d0 ====

void FUN_006129d0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009882d1;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc3b4;
  FUN_00634780();
  local_4._0_1_ = 1;
  pvVar1 = operator_new(0x1c);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00634e70();
  }
  local_4._0_1_ = 1;
  in_ECX[0xb] = uVar2;
  pvVar1 = operator_new(0x30);
  local_4._0_1_ = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00634cd0();
  }
  local_4._0_1_ = 1;
  in_ECX[0xc] = uVar2;
  pvVar1 = operator_new(100);
  local_4 = CONCAT31(local_4._1_3_,4);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00634890();
  }
  in_ECX[0xd] = uVar2;
  *(undefined1 *)(in_ECX + 0xe) = 0;
  *(undefined1 *)((int)in_ECX + 0x39) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612aa0 @ 0x00612aa0 ====

void FUN_00612aa0(byte param_1)

{
  void *in_ECX;
  
  FUN_006128a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00612ac0 @ 0x00612ac0 ====

void FUN_00612ac0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009882e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc3f8;
  local_4 = 0;
  FUN_00635000();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612b10 @ 0x00612b10 ====

int FUN_00612b10(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00612b20 @ 0x00612b20 ====

int FUN_00612b20(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00612b30 @ 0x00612b30 ====

void FUN_00612b30(void)

{
  return;
}


// ==== FUN_00612b40 @ 0x00612b40 ====

void FUN_00612b40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009882fa;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc3f8;
  FUN_00634fe0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612b90 @ 0x00612b90 ====

undefined4 FUN_00612b90(void)

{
  return 0x17;
}


// ==== FUN_00612ba0 @ 0x00612ba0 ====

void FUN_00612ba0(byte param_1)

{
  void *in_ECX;
  
  FUN_00612ac0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00612bc0 @ 0x00612bc0 ====

undefined4 FUN_00612bc0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00612bd0 @ 0x00612bd0 ====

void FUN_00612bd0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00612bd5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
  return;
}


// ==== FUN_00612be0 @ 0x00612be0 ====

void FUN_00612be0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988318;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc418;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612c40 @ 0x00612c40 ====

void FUN_00612c40(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988335;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc418;
  pvVar1 = operator_new(0x1c);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[2] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_006353a0();
  in_ECX[2] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612cc0 @ 0x00612cc0 ====

void FUN_00612cc0(byte param_1)

{
  void *in_ECX;
  
  FUN_00612be0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00612ce0 @ 0x00612ce0 ====

undefined4 FUN_00612ce0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00612cf0 @ 0x00612cf0 ====

void FUN_00612cf0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00612cf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  return;
}


// ==== FUN_00612d00 @ 0x00612d00 ====

void FUN_00612d00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988348;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc434;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612d60 @ 0x00612d60 ====

void FUN_00612d60(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988365;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc434;
  pvVar1 = operator_new(0x10);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[2] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00636220();
  in_ECX[2] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612de0 @ 0x00612de0 ====

void FUN_00612de0(byte param_1)

{
  void *in_ECX;
  
  FUN_00612d00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00612e00 @ 0x00612e00 ====

void FUN_00612e00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988378;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc450;
  local_4 = 0;
  FUN_00636d50();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612e50 @ 0x00612e50 ====

void FUN_00612e50(void)

{
  return;
}


// ==== FUN_00612e60 @ 0x00612e60 ====

int FUN_00612e60(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00612e70 @ 0x00612e70 ====

void FUN_00612e70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098838a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc450;
  FUN_00636ec0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00612ec0 @ 0x00612ec0 ====

void FUN_00612ec0(byte param_1)

{
  void *in_ECX;
  
  FUN_00612e00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00612ee0 @ 0x00612ee0 ====

void FUN_00612ee0(void)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = 4;
  do {
    FUN_00636fd0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  *(undefined4 *)(in_ECX + 0x18) = 0;
  return;
}


// ==== FUN_00612f10 @ 0x00612f10 ====

undefined4 FUN_00612f10(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18);
}


// ==== FUN_00612f20 @ 0x00612f20 ====

void FUN_00612f20(uint param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  
  if (*(uint *)(in_ECX + 0x18) < param_1) {
    *(uint *)(in_ECX + 0x18) = param_1;
    puVar3 = (undefined4 *)(in_ECX + 8);
    iVar2 = 4;
    do {
      iVar1 = (**(code **)(*(int *)*puVar3 + 0x18))();
      if (param_1 < *(uint *)(iVar1 + 4)) {
        FUN_00636fc0(*(uint *)(iVar1 + 4) - param_1);
      }
      else {
        FUN_00636fd0();
      }
      puVar3 = puVar3 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


// ==== __break @ 0x00612f6e ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_00612f70 @ 0x00612f70 ====

undefined4 FUN_00612f70(int param_1)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8 + param_1 * 4);
}


// ==== FUN_00612f80 @ 0x00612f80 ====

void FUN_00612f80(void)

{
  undefined4 *in_ECX;
  int *piVar1;
  int iVar2;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009883a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cc46c;
  local_4 = 0;
  piVar1 = in_ECX + 2;
  iVar2 = 4;
  do {
    if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)*piVar1)(1);
    }
    *piVar1 = 0;
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00612ff0 @ 0x00612ff0 ====

undefined4 FUN_00612ff0(int param_1)

{
  undefined4 uVar1;
  int *in_ECX;
  
  if ((param_1 == 1) || (param_1 == 2)) {
                    /* WARNING: Could not recover jumptable at 0x0061301f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*in_ECX + 0x20))();
    return uVar1;
  }
  if (param_1 == 0xc) {
                    /* WARNING: Could not recover jumptable at 0x0061300d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(*in_ECX + 0x20))();
    return uVar1;
  }
  return 0;
}


// ==== FUN_00613030 @ 0x00613030 ====

void FUN_00613030(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined4 *puVar3;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_009883c5;
  local_c = ExceptionList;
  uStack_3 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc46c;
  puVar3 = in_ECX + 2;
  iVar4 = 4;
  do {
    local_4 = 0;
    pvVar1 = operator_new(0x14);
    local_4 = 1;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00636fe0();
    }
    *puVar3 = uVar2;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  in_ECX[6] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006130b0 @ 0x006130b0 ====

void FUN_006130b0(byte param_1)

{
  void *in_ECX;
  
  FUN_00612f80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006130d0 @ 0x006130d0 ====

void FUN_006130d0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  return;
}


// ==== FUN_006130e0 @ 0x006130e0 ====

undefined1 FUN_006130e0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_006130f0 @ 0x006130f0 ====

void FUN_006130f0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = 0;
  *(undefined1 *)(in_ECX + 0x11) = 0;
  return;
}


// ==== FUN_00613100 @ 0x00613100 ====

void FUN_00613100(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc234;
  return;
}


// ==== FUN_00613110 @ 0x00613110 ====

undefined1 FUN_00613110(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x11) = 0;
  if (*(char *)(in_ECX + 0x10) == '\0') {
    return 0;
  }
  return *(undefined1 *)(in_ECX + 8);
}


// ==== FUN_00613130 @ 0x00613130 ====

uint FUN_00613130(void)

{
  byte bVar1;
  uint in_EAX;
  int in_ECX;
  
  if (*(byte *)(in_ECX + 0x11) + 1 < (uint)*(byte *)(in_ECX + 0x10)) {
    bVar1 = *(byte *)(in_ECX + 0x11) + 1;
    *(byte *)(in_ECX + 0x11) = bVar1;
    return (uint)*(byte *)(bVar1 + 8 + in_ECX);
  }
  return in_EAX & 0xffffff00;
}


// ==== FUN_00613160 @ 0x00613160 ====

undefined1 FUN_00613160(char param_1)

{
  byte bVar1;
  int in_ECX;
  
  bVar1 = 0;
  if ((param_1 != '\0') && (*(byte *)(in_ECX + 0x10) != 0)) {
    do {
      if (*(char *)(bVar1 + 8 + in_ECX) == param_1) {
        return 1;
      }
      bVar1 = bVar1 + 1;
    } while (bVar1 < *(byte *)(in_ECX + 0x10));
  }
  return 0;
}


// ==== FUN_006131a0 @ 0x006131a0 ====

void FUN_006131a0(byte param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (uint)param_1;
  if ((int)uVar1 < (int)(*(byte *)(in_ECX + 0x10) - 1)) {
    do {
      *(undefined1 *)(uVar1 + 8 + in_ECX) = *(undefined1 *)(uVar1 + 9 + in_ECX);
      param_1 = param_1 + 1;
      uVar1 = (uint)param_1;
    } while ((int)uVar1 < (int)(*(byte *)(in_ECX + 0x10) - 1));
  }
  *(char *)(in_ECX + 0x10) = *(char *)(in_ECX + 0x10) + -1;
  return;
}


// ==== FUN_006131e0 @ 0x006131e0 ====

void FUN_006131e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc4e8;
  *(undefined1 *)(in_ECX + 4) = 0;
  return;
}


// ==== FUN_006131f0 @ 0x006131f0 ====

void FUN_006131f0(char param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_1 == '\0') {
    FUN_0044a580(local_100,&DAT_009cc4e0,s_Status_IconIndex_is_0______009cc494);
    FUN_00797b80(local_100);
    return;
  }
  bVar1 = *(byte *)(in_ECX + 0x10);
  if (7 < bVar1) {
    FUN_0044a580(local_100,&DAT_009cc4e0,s_Status_Overflow__009cc4b0);
    FUN_00797b80(local_100);
    return;
  }
  uVar3 = 0;
  if (bVar1 != 0) {
    do {
      if (*(char *)(uVar3 + 8 + in_ECX) == param_1) {
        return;
      }
      bVar2 = (char)uVar3 + 1;
      uVar3 = (uint)bVar2;
    } while (bVar2 < *(byte *)(in_ECX + 0x10));
  }
  *(byte *)(in_ECX + 0x10) = bVar1 + 1;
  *(char *)(bVar1 + 8 + in_ECX) = param_1;
  return;
}


// ==== FUN_00613290 @ 0x00613290 ====

void FUN_00613290(char param_1)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_1 == '\0') {
    FUN_0044a580(local_100,&DAT_009cc4e0,s_Status_IconIndex_is_0______009cc4c4);
    FUN_00797b80(local_100);
    return;
  }
  bVar1 = *(byte *)(in_ECX + 0x10);
  if ((bVar1 != 0) && (uVar3 = 0, bVar1 != 0)) {
    while (*(char *)(uVar3 + 8 + in_ECX) != param_1) {
      bVar2 = (char)uVar3 + 1;
      uVar3 = (uint)bVar2;
      if (bVar1 <= bVar2) {
        return;
      }
    }
    FUN_006131a0(uVar3);
  }
  return;
}


// ==== FUN_00613320 @ 0x00613320 ====

void FUN_00613320(byte param_1)

{
  void *in_ECX;
  
  FUN_00613100();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00613340 @ 0x00613340 ====

void FUN_00613340(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00613342. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x28))();
  return;
}


// ==== FUN_00613360 @ 0x00613360 ====

void FUN_00613360(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009883d8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cc5a4;
  local_4 = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006133d0 @ 0x006133d0 ====

undefined4 FUN_006133d0(undefined2 param_1)

{
  int *piVar1;
  int in_ECX;
  undefined2 local_8 [4];
  
  local_8[0] = param_1;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x30))(local_8);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_00613400 @ 0x00613400 ====

undefined4 FUN_00613400(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 8))();
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  *(int **)(in_ECX + 0x10) = piVar1;
  return *(undefined4 *)(*piVar1 + 4);
}


// ==== FUN_00613420 @ 0x00613420 ====

undefined4 FUN_00613420(void)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x48))(*(int *)(in_ECX + 0x10));
    *(int **)(in_ECX + 0x10) = piVar1;
    if (piVar1 != (int *)0x0) {
      return *(undefined4 *)(*piVar1 + 4);
    }
  }
  return 0;
}


// ==== FUN_00613450 @ 0x00613450 ====

void FUN_00613450(undefined2 param_1)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  undefined2 local_8 [4];
  
  local_8[0] = param_1;
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x30))(local_8);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*DAT_00b5b01c + 0x10))(1,*(undefined4 *)(*piVar2 + 4));
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x40))(piVar2);
    cVar1 = FUN_005c8e90();
    if (cVar1 == '\x01') {
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))();
      (**(code **)(*piVar2 + 0x10))();
    }
  }
  return;
}


// ==== FUN_006134b0 @ 0x006134b0 ====

void FUN_006134b0(int param_1)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  uint *puVar5;
  uint uVar6;
  
  FUN_00797a50(param_1,0,0x280);
  for (piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 8))(); piVar2 != (int *)0x0;
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x48))(piVar2)) {
    piVar3 = (int *)(**(code **)(**(int **)(*piVar2 + 4) + 0xc))();
    iVar4 = (**(code **)(*piVar3 + 4))();
    uVar6 = 0;
    if (*(int *)(iVar4 + 0x104) != 0) {
      puVar5 = (uint *)(iVar4 + 0x108);
      do {
        uVar1 = *puVar5;
        if ((uVar1 != 0) && (uVar1 < 0xa0)) {
          piVar3 = (int *)(param_1 + uVar1 * 4);
          *piVar3 = *piVar3 + puVar5[1];
        }
        uVar6 = uVar6 + 1;
        puVar5 = puVar5 + 2;
      } while (uVar6 < *(uint *)(iVar4 + 0x104));
    }
  }
  return;
}


// ==== FUN_00613540 @ 0x00613540 ====

int * FUN_00613540(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int in_ECX;
  int unaff_EBX;
  uint uVar6;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 8))();
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar5 = *(int **)(*piVar1 + 4);
  piVar2 = (int *)(**(code **)(*piVar5 + 8))();
  iVar3 = (**(code **)(*piVar2 + 4))();
  uVar6 = *(uint *)(iVar3 + 8);
  for (piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x48))(piVar1); piVar1 != (int *)0x0;
      piVar1 = (int *)(**(code **)(**(int **)(unaff_EBX + 0xc) + 0x48))(piVar1)) {
    piVar2 = *(int **)(*piVar1 + 4);
    piVar4 = (int *)(**(code **)(*piVar2 + 8))();
    iVar3 = (**(code **)(*piVar4 + 4))();
    if (*(uint *)(iVar3 + 8) < uVar6) {
      piVar5 = (int *)(**(code **)(*piVar2 + 8))();
      iVar3 = (**(code **)(*piVar5 + 4))();
      uVar6 = *(uint *)(iVar3 + 8);
      piVar5 = piVar2;
    }
  }
  return piVar5;
}


// ==== FUN_006135d0 @ 0x006135d0 ====

void FUN_006135d0(void)

{
  char cVar1;
  int *piVar2;
  int in_ECX;
  
  for (piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 8))(); piVar2 != (int *)0x0;
      piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x48))(piVar2)) {
    (**(code **)(*DAT_00b5b01c + 0x10))(1,*(undefined4 *)(*piVar2 + 4));
  }
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x20))();
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x00613623. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*piVar2 + 0x10))();
    return;
  }
  return;
}


// ==== FUN_00613630 @ 0x00613630 ====

int * FUN_00613630(uint param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 8))();
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return (int *)0x0;
    }
    piVar1 = *(int **)(*piVar2 + 4);
    piVar3 = (int *)(**(code **)(*piVar1 + 8))();
    iVar4 = (**(code **)(*piVar3 + 4))();
    if (*(uint *)(iVar4 + 8) <= param_1) break;
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 0xc) + 0x48))(piVar2);
  }
  return piVar1;
}


// ==== FUN_00613690 @ 0x00613690 ====

undefined4 FUN_00613690(int *param_1)

{
  char cVar1;
  int *piVar2;
  undefined2 *puVar3;
  int iVar4;
  undefined2 *puVar5;
  int in_ECX;
  undefined2 auStack_8 [4];
  
  piVar2 = (int *)(**(code **)(*param_1 + 8))();
  puVar3 = (undefined2 *)(**(code **)(*piVar2 + 4))();
  auStack_8[0] = *puVar3;
  iVar4 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x30))(auStack_8);
  if (iVar4 != 0) {
    return 0;
  }
  puVar3 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 8) + 0xc))(1,0);
  piVar2 = (int *)(**(code **)(*param_1 + 8))();
  puVar5 = (undefined2 *)(**(code **)(*piVar2 + 4))();
  *puVar3 = *puVar5;
  *(int **)(puVar3 + 2) = param_1;
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x28))(puVar3);
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))();
    (**(code **)(*piVar2 + 0x10))();
  }
  return 1;
}


// ==== FUN_00613720 @ 0x00613720 ====

void FUN_00613720(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00988400;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc5a4;
  pvVar1 = operator_new(0xb8);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006138b0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x128);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00613eb0(in_ECX[2]);
  }
  in_ECX[3] = uVar2;
  in_ECX[4] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006137c0 @ 0x006137c0 ====

void FUN_006137c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc51c;
  return;
}


// ==== FUN_006137d0 @ 0x006137d0 ====

void FUN_006137d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc574;
  return;
}


// ==== FUN_006137e0 @ 0x006137e0 ====

void FUN_006137e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc58c;
  return;
}


// ==== FUN_006137f0 @ 0x006137f0 ====

void FUN_006137f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc51c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00613810 @ 0x00613810 ====

void FUN_00613810(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc574;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00613830 @ 0x00613830 ====

void FUN_00613830(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc58c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00613850 @ 0x00613850 ====

void FUN_00613850(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc5e0;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,8,FUN_006ef6d0);
  return;
}


// ==== FUN_00613870 @ 0x00613870 ====

void FUN_00613870(byte param_1)

{
  void *in_ECX;
  
  FUN_00613850();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00613890 @ 0x00613890 ====

void FUN_00613890(byte param_1)

{
  void *in_ECX;
  
  FUN_00613360();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006138b0 @ 0x006138b0 ====

void FUN_006138b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988418;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc5e8;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cc5e0;
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


// ==== FUN_00613990 @ 0x00613990 ====

void FUN_00613990(byte param_1)

{
  void *in_ECX;
  
  FUN_006139b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006139b0 @ 0x006139b0 ====

void FUN_006139b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988443;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc5e8;
  local_4 = 1;
  if ((void *)in_ECX[0x2c] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cc5e0;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,8,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cc574;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x2c]);
  return;
}


// ==== FUN_00613a30 @ 0x00613a30 ====

void * FUN_00613a30(int param_1,void *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0098845b;
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
                           s_d__usa_24_0_1_2__develop_share_l_009cc600,0x85);
      FUN_00797b80(uVar1);
      local_4 = 0xffffffff;
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
  }
  ExceptionList = local_c;
  return param_2;
}


// ==== FUN_00613b10 @ 0x00613b10 ====

undefined4 FUN_00613b10(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cc600,0xa9);
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


// ==== FUN_00613b90 @ 0x00613b90 ====

void FUN_00613b90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc670;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,8,FUN_006ef6d0);
  return;
}


// ==== FUN_00613bb0 @ 0x00613bb0 ====

void FUN_00613bb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988483;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc678;
  local_4 = 1;
  if ((void *)in_ECX[0x44] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cc670;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,8,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cc58c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x44]);
  return;
}


// ==== FUN_00613c30 @ 0x00613c30 ====

undefined4 FUN_00613c30(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10c);
}


// ==== FUN_00613c40 @ 0x00613c40 ====

undefined4 FUN_00613c40(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cc600,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x114);
    *(int *)(in_ECX + 0x10c) = *(int *)(in_ECX + 0x10c) + -1;
    *(int *)(in_ECX + 0x114) = param_2;
  }
  return 0;
}


// ==== FUN_00613cc0 @ 0x00613cc0 ====

undefined4 * FUN_00613cc0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cc600,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x114);
  *(int *)(in_ECX + 0x10c) = *(int *)(in_ECX + 0x10c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x110);
    *(undefined4 **)(in_ECX + 0x110) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x114) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_00613d80 @ 0x00613d80 ====

void FUN_00613d80(byte param_1)

{
  void *in_ECX;
  
  FUN_00613b90();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00613da0 @ 0x00613da0 ====

void FUN_00613da0(byte param_1)

{
  void *in_ECX;
  
  FUN_00613bb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00613dc0 @ 0x00613dc0 ====

void FUN_00613dc0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988498;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc678;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cc670;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,8,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x42] = 0;
  in_ECX[0x42] = in_ECX[0x42] + 8;
  in_ECX[0x43] = 0;
  in_ECX[0x44] = 0;
  in_ECX[0x45] = in_ECX + 2;
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
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00613eb0 @ 0x00613eb0 ====

void FUN_00613eb0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009884b8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc694;
  FUN_00613dc0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00613f10 @ 0x00613f10 ====

void FUN_00613f10(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00613f30(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00613f30 @ 0x00613f30 ====

void FUN_00613f30(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_00613f30(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_00613f30(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_00613f70 @ 0x00613f70 ====

void FUN_00613f70(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_00613f90(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_00613f90 @ 0x00613f90 ====

void FUN_00613f90(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_00613f90(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_00613f90(param_1[3]);
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


// ==== FUN_00614000 @ 0x00614000 ====

void FUN_00614000(byte param_1)

{
  void *in_ECX;
  
  FUN_00614020();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00614020 @ 0x00614020 ====

void FUN_00614020(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009884e3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc694;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_00613f90(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_00613bb0();
  *in_ECX = &PTR_FUN_009cc51c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00614090 @ 0x00614090 ====

undefined4 FUN_00614090(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_006140a0 @ 0x006140a0 ====

undefined4 FUN_006140a0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_006140b0 @ 0x006140b0 ====

void FUN_006140b0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
                    /* WARNING: Could not recover jumptable at 0x006140c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
  return;
}


// ==== FUN_006140d0 @ 0x006140d0 ====

void FUN_006140d0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009884f8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cc6ec;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00614140 @ 0x00614140 ====

void FUN_00614140(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00988520;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc6ec;
  pvVar1 = operator_new(0x10);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00637cf0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    in_ECX[3] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00637240();
  in_ECX[3] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006141f0 @ 0x006141f0 ====

void FUN_006141f0(byte param_1)

{
  void *in_ECX;
  
  FUN_006140d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00614210 @ 0x00614210 ====

void FUN_00614210(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc234;
  return;
}


// ==== FUN_00614220 @ 0x00614220 ====

void FUN_00614220(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 8) = 0;
  return;
}


// ==== FUN_00614230 @ 0x00614230 ====

void FUN_00614230(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc70c;
  *(undefined1 *)(in_ECX + 2) = 0;
  return;
}


// ==== FUN_00614240 @ 0x00614240 ====

void FUN_00614240(byte param_1)

{
  void *in_ECX;
  
  FUN_00614210();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00614260 @ 0x00614260 ====

void FUN_00614260(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988538;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc724;
  local_4 = 0;
  FUN_0060e8b0();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006142b0 @ 0x006142b0 ====

void FUN_006142b0(void)

{
  return;
}


// ==== FUN_006142c0 @ 0x006142c0 ====

int FUN_006142c0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_006142d0 @ 0x006142d0 ====

void FUN_006142d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098854a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc724;
  FUN_0060e900();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00614320 @ 0x00614320 ====

void FUN_00614320(byte param_1)

{
  void *in_ECX;
  
  FUN_00614260();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00614340 @ 0x00614340 ====

void FUN_00614340(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614345. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_00614350 @ 0x00614350 ====

void FUN_00614350(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614355. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x34))();
  return;
}


// ==== FUN_00614360 @ 0x00614360 ====

void FUN_00614360(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614365. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x3c))();
  return;
}


// ==== FUN_00614370 @ 0x00614370 ====

void FUN_00614370(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614375. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x18))();
  return;
}


// ==== FUN_00614380 @ 0x00614380 ====

void FUN_00614380(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614385. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  return;
}


// ==== FUN_00614390 @ 0x00614390 ====

void FUN_00614390(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614395. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  return;
}


// ==== FUN_006143a0 @ 0x006143a0 ====

void FUN_006143a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006143a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  return;
}


// ==== FUN_006143b0 @ 0x006143b0 ====

void FUN_006143b0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988568;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cc740;
  local_4 = 0;
  (**(code **)(*(int *)in_ECX[2] + 0x10))();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00614410 @ 0x00614410 ====

bool FUN_00614410(int param_1,undefined4 param_2)

{
  char cVar1;
  int in_ECX;
  
  if (param_1 == 0) {
    return false;
  }
  cVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x48))(param_1,param_2);
  return cVar1 == '\x01';
}


// ==== FUN_00614440 @ 0x00614440 ====

void FUN_00614440(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  while (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x60))(0);
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  }
                    /* WARNING: Could not recover jumptable at 0x0061446b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  return;
}


// ==== FUN_00614470 @ 0x00614470 ====

void FUN_00614470(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988585;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc740;
  pvVar1 = operator_new(0x14);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[2] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00638680(1,10,0xe);
  in_ECX[2] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006144f0 @ 0x006144f0 ====

void FUN_006144f0(byte param_1)

{
  void *in_ECX;
  
  FUN_006143b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00614510 @ 0x00614510 ====

void FUN_00614510(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614515. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_00614520 @ 0x00614520 ====

void FUN_00614520(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614525. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x34))();
  return;
}


// ==== FUN_00614530 @ 0x00614530 ====

void FUN_00614530(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614535. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x18))();
  return;
}


// ==== FUN_00614540 @ 0x00614540 ====

void FUN_00614540(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614545. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x3c))();
  return;
}


// ==== FUN_00614550 @ 0x00614550 ====

void FUN_00614550(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614555. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  return;
}


// ==== FUN_00614560 @ 0x00614560 ====

void FUN_00614560(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614565. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  return;
}


// ==== FUN_00614570 @ 0x00614570 ====

void FUN_00614570(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614575. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0xc))();
  return;
}


// ==== FUN_00614580 @ 0x00614580 ====

undefined4 FUN_00614580(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00614590 @ 0x00614590 ====

void FUN_00614590(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00614595. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
  return;
}


// ==== FUN_006145a0 @ 0x006145a0 ====

int FUN_006145a0(void)

{
  int in_ECX;
  
  return in_ECX + 0x10;
}


// ==== FUN_006145b0 @ 0x006145b0 ====

void FUN_006145b0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988598;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cc77c;
  local_4 = 0;
  if ((int *)in_ECX[2] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[2] + 0xc))();
  }
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00614620 @ 0x00614620 ====

uint FUN_00614620(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*param_2 + 0x1c))();
  if (piVar1 == (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x18))(param_1);
    return -(uint)(iVar2 != 0) & 2;
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (iVar2 == 5) {
    FUN_00803725(piVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                 &Framework::Article::IItem::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x00614681. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
    return uVar3;
  }
  return 0;
}


// ==== FUN_00614690 @ 0x00614690 ====

undefined4 FUN_00614690(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x48))(param_1,param_2);
  return uVar1;
}


// ==== FUN_006146b0 @ 0x006146b0 ====

undefined4 FUN_006146b0(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar1 = param_1;
  if (param_1 == 0) {
    return 0;
  }
  param_1 = param_1 & 0xff000000;
  uVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x48))(uVar1,&param_1);
  return uVar2;
}


// ==== FUN_006146e0 @ 0x006146e0 ====

undefined4 FUN_006146e0(uint param_1)

{
  uint uVar1;
  char cVar2;
  int in_ECX;
  undefined1 auStackY_98 [128];
  
  uVar1 = param_1;
  if (param_1 != 0) {
    param_1 = param_1 & 0xff000000;
    cVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x48))(uVar1,&param_1);
    if (cVar2 != '\0') {
      (**(code **)(**(int **)(in_ECX + 8) + 0x34))(auStackY_98 + 0x94,uVar1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00614730 @ 0x00614730 ====

undefined4 FUN_00614730(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (iVar1 == param_1) break;
    iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  }
  return 1;
}


// ==== FUN_00614770 @ 0x00614770 ====

void FUN_00614770(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009885c0;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cc77c;
  local_4 = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  pvVar1 = operator_new(0x14);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00638680(1,10,5);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    in_ECX[3] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00639bc0();
  in_ECX[3] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00614820 @ 0x00614820 ====

void FUN_00614820(int param_1)

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
    if (cVar2 == '\0') {
      return;
    }
    uVar4 = uVar4 + 1;
    pcVar3 = pcVar3 + 1;
  } while (uVar4 < 0x19);
  *pcVar1 = '\0';
  return;
}


// ==== FUN_00614850 @ 0x00614850 ====

void FUN_00614850(byte param_1)

{
  void *in_ECX;
  
  FUN_006145b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00614870 @ 0x00614870 ====

int FUN_00614870(void)

{
  int in_ECX;
  
  return in_ECX + 0x1e;
}


// ==== FUN_00614880 @ 0x00614880 ====

void FUN_00614880(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  int iVar2;
  int *piVar3;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009885d8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cca48;
  local_4 = 0;
  piVar3 = in_ECX + 2;
  iVar2 = 5;
  do {
    piVar1 = (int *)*piVar3;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0xc))();
      (**(code **)*piVar1)(1);
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_006148f0 @ 0x006148f0 ====

undefined4 FUN_006148f0(uint param_1)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int in_ECX;
  byte bVar4;
  uint uVar5;
  
  uVar2 = param_1;
  if (param_1 == 0) {
    return 0;
  }
  uVar5 = 0;
  do {
    piVar1 = *(int **)(in_ECX + 8 + uVar5 * 4);
    if (piVar1 != (int *)0x0) {
      param_1 = param_1 & 0xff000000;
      cVar3 = (**(code **)(*piVar1 + 0x48))(uVar2,&param_1);
      if (cVar3 == '\x01') {
        return 1;
      }
    }
    bVar4 = (char)uVar5 + 1;
    uVar5 = (uint)bVar4;
  } while (bVar4 < 5);
  return 0;
}


// ==== FUN_00614950 @ 0x00614950 ====

undefined4 FUN_00614950(uint param_1)

{
  uint uVar1;
  char cVar2;
  int in_ECX;
  byte bVar3;
  uint uVar4;
  
  uVar1 = param_1;
  if (param_1 == 0) {
    return 0;
  }
  uVar4 = 0;
  do {
    if (*(int *)(in_ECX + 8 + uVar4 * 4) != 0) {
      param_1 = param_1 & 0xff000000;
      cVar2 = (**(code **)(**(int **)(in_ECX + 8 + uVar4 * 4) + 0x48))(uVar1,&param_1);
      if (cVar2 == '\x01') {
        (**(code **)(**(int **)(in_ECX + 8 + uVar4 * 4) + 0x34))(&param_1,uVar1);
        return 1;
      }
    }
    bVar3 = (char)uVar4 + 1;
    uVar4 = (uint)bVar3;
  } while (bVar3 < 5);
  return 0;
}


// ==== FUN_006149d0 @ 0x006149d0 ====

void FUN_006149d0(void)

{
  int in_ECX;
  int *piVar1;
  int iVar2;
  
  *(undefined1 *)(in_ECX + 0x1c) = 0;
  piVar1 = (int *)(in_ECX + 8);
  iVar2 = 5;
  do {
    if (*piVar1 != 0) {
      (**(code **)(*(int *)*piVar1 + 0xc))();
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== FUN_00614a00 @ 0x00614a00 ====

undefined4 FUN_00614a00(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x20) = 0;
  if (*(int *)(in_ECX + 8) == 0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x00614a12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  return uVar1;
}


// ==== FUN_00614a20 @ 0x00614a20 ====

int FUN_00614a20(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  bVar1 = *(byte *)(in_ECX + 0x20);
  if ((bVar1 < 5) && (*(int *)(in_ECX + 8 + (uint)bVar1 * 4) != 0)) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 8 + (uint)bVar1 * 4) + 0x28))();
    if (iVar2 == 0) {
      while (*(byte *)(in_ECX + 0x20) < 5) {
        bVar1 = *(byte *)(in_ECX + 0x20) + 1;
        *(byte *)(in_ECX + 0x20) = bVar1;
        if ((4 < bVar1) || (*(int *)(in_ECX + 8 + (uint)bVar1 * 4) == 0)) goto LAB_00614a71;
        iVar3 = (**(code **)(**(int **)(in_ECX + 8 + (uint)bVar1 * 4) + 0x24))();
        iVar2 = 0;
        if (iVar3 != 0) {
          return iVar3;
        }
      }
    }
  }
  else {
LAB_00614a71:
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_00614a80 @ 0x00614a80 ====

undefined4 FUN_00614a80(undefined4 param_1,char *param_2)

{
  char cVar1;
  int in_ECX;
  byte bVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    if (*(int *)(in_ECX + 8 + uVar3 * 4) != 0) {
      cVar1 = (**(code **)(**(int **)(in_ECX + 8 + uVar3 * 4) + 0x20))(param_1,param_2);
      if (cVar1 == '\x01') {
        *param_2 = (char)uVar3;
        return 1;
      }
    }
    bVar2 = (char)uVar3 + 1;
    uVar3 = (uint)bVar2;
  } while (bVar2 < 5);
  return 0;
}


// ==== FUN_00614ad0 @ 0x00614ad0 ====

void FUN_00614ad0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  undefined4 *puVar3;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined1 local_4;
  undefined3 uStack_3;
  
  puStack_8 = &LAB_009885f5;
  local_c = ExceptionList;
  uStack_3 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cca48;
  puVar3 = in_ECX + 2;
  iVar4 = 5;
  do {
    local_4 = 0;
    pvVar1 = operator_new(0x14);
    local_4 = 1;
    if (pvVar1 == (void *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = FUN_00638680(1,10,10);
    }
    *puVar3 = uVar2;
    puVar3 = puVar3 + 1;
    iVar4 = iVar4 + -1;
    local_4 = 0;
  } while (iVar4 != 0);
  *(undefined1 *)(in_ECX + 7) = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  in_ECX[9] = 0;
  FUN_00797a50((int)in_ECX + 0x1e,0,2);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00614b70 @ 0x00614b70 ====

undefined4 FUN_00614b70(uint param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  ushort uVar5;
  char *pcStack_140;
  uint uStack_13c;
  undefined4 uStack_138;
  ushort uStack_128;
  undefined2 uStack_126;
  ushort uStack_11c;
  undefined1 uStack_108;
  undefined1 uStack_107;
  undefined1 auStack_104 [256];
  int *piStack_4;
  
  uStack_138 = param_1;
  uStack_13c = 0x614b8c;
  piVar2 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))();
  if (piVar2 == (int *)0x0) {
    uStack_13c = param_1 & 0xffff;
    pcStack_140 = s_____ERROR_____Invalid_Item_Index_009cc920;
    auStack_104[0] = 0;
    uVar3 = FUN_0044a580(auStack_104);
    FUN_00797b80(uVar3);
    return 0;
  }
  uStack_13c = 0x24;
  pcStack_140 = (char *)0x0;
  FUN_00797a50(&uStack_128);
  uVar5 = (ushort)param_1;
  uStack_13c = 0x614bde;
  uStack_128 = uVar5;
  iVar4 = (**(code **)(*piVar2 + 4))();
  if (*(char *)(iVar4 + 0x7e) == '\x01') {
    uStack_108 = 2;
    uStack_13c = 0x614bf0;
    iVar4 = (**(code **)(*piVar2 + 4))();
    uStack_126 = *(undefined2 *)(iVar4 + 0x82);
  }
  uStack_13c = 0x614c03;
  iVar4 = (**(code **)(*piVar2 + 4))();
  if (*(short *)(iVar4 + 0x76) == 0) {
LAB_00614c41:
    if (uVar5 == 0) goto LAB_00614c95;
  }
  else if (uVar5 == 0) {
    uStack_13c = 0x16c;
    pcStack_140 = s___Article_Item_Shop_Shop_cpp_009cc948;
    auStack_104[0] = 0;
    uVar3 = FUN_0044a580(auStack_104,s_File___s__Line___d_009cc968);
    FUN_00797b80(uVar3);
    uStack_13c = 0x614c41;
    FUN_00797a40();
    goto LAB_00614c41;
  }
  uStack_13c = 0x614c4d;
  iVar4 = (**(code **)(*piVar2 + 4))();
  if (*(short *)(iVar4 + 0x76) == 0) {
LAB_00614c60:
    uStack_13c = 0x172;
    pcStack_140 = s___Article_Item_Shop_Shop_cpp_009cc97c;
    auStack_104[0] = 0;
    uVar3 = FUN_0044a580(auStack_104,s_File___s__Line___d_009cc99c);
    FUN_00797b80(uVar3);
    uStack_13c = 0x614c8b;
    FUN_00797a40();
  }
  else {
    uStack_13c = 0x614c5a;
    iVar4 = (**(code **)(*piVar2 + 4))();
    if (*(ushort *)(iVar4 + 0x76) < uVar5) goto LAB_00614c60;
  }
  uStack_107 = 1;
  uStack_11c = uVar5;
LAB_00614c95:
  uStack_13c = 0;
  pcStack_140 = (char *)0x1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))();
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 8))(auStack_104 + -0x2c);
    if (cVar1 == '\0') {
      (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar2);
      return 0;
    }
    uStack_138 = uStack_138 & 0xff000000;
    cVar1 = (**(code **)(*piStack_4 + 0x48))(piVar2,&uStack_138);
    if (cVar1 != '\0') {
      (**(code **)(*piStack_4 + 0x34))(&pcStack_140,piVar2);
      return 1;
    }
    (**(code **)(*DAT_00b5a730 + 0x10))(1);
  }
  return 0;
}


// ==== FUN_00614d30 @ 0x00614d30 ====

undefined4 FUN_00614d30(uint param_1)

{
  char cVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  ushort uVar5;
  int *unaff_retaddr;
  uint uStack_130;
  undefined1 auStack_122 [30];
  undefined1 auStack_104 [256];
  undefined4 uStack_4;
  
  uStack_130 = param_1;
  piVar2 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))();
  if (piVar2 == (int *)0x0) {
    auStack_104[0] = 0;
    uVar3 = FUN_0044a580(auStack_104,s_____ERROR_____Invalid_Item_Index_009cc9b0,param_1 & 0xffff);
    FUN_00797b80(uVar3);
    return 0;
  }
  FUN_00797a50(auStack_122 + -6,0,0x24);
  uVar5 = (ushort)param_1;
  iVar4 = (**(code **)(*piVar2 + 4))();
  if (*(char *)(iVar4 + 0x7e) == '\x01') {
    (**(code **)(*piVar2 + 4))();
  }
  iVar4 = (**(code **)(*piVar2 + 4))();
  if (*(short *)(iVar4 + 0x76) == 0) {
LAB_00614e00:
    if (uVar5 == 0) goto LAB_00614e56;
  }
  else if (uVar5 == 0) {
    auStack_104[0] = 0;
    uVar3 = FUN_0044a580(auStack_104,s_File___s__Line___d_009cc9f8,
                         s___Article_Item_Shop_Shop_cpp_009cc9d8,0x1ad);
    FUN_00797b80(uVar3);
    FUN_00797a40();
    goto LAB_00614e00;
  }
  iVar4 = (**(code **)(*piVar2 + 4))();
  if ((*(short *)(iVar4 + 0x76) == 0) ||
     (iVar4 = (**(code **)(*piVar2 + 4))(), *(ushort *)(iVar4 + 0x76) < uVar5)) {
    auStack_104[0] = 0;
    uVar3 = FUN_0044a580(auStack_104,s_File___s__Line___d_009cca2c,
                         s___Article_Item_Shop_Shop_cpp_009cca0c,0x1b3);
    FUN_00797b80(uVar3);
    FUN_00797a40();
  }
LAB_00614e56:
  piVar2 = (int *)(**(code **)(*DAT_00b5a730 + 0xc))(1,0);
  if (piVar2 != (int *)0x0) {
    cVar1 = (**(code **)(*piVar2 + 8))(&uStack_130);
    if (cVar1 != '\0') {
      iVar4 = (**(code **)(*unaff_retaddr + 0x30))(uStack_4,piVar2);
      if (iVar4 == 1) {
        (**(code **)(*unaff_retaddr + 0x34))(uStack_4,piVar2);
        return 1;
      }
      (**(code **)(*DAT_00b5a730 + 0x10))(1);
      return 0;
    }
    (**(code **)(*DAT_00b5a730 + 0x10))(1,piVar2);
  }
  return 0;
}


// ==== FUN_00614ef0 @ 0x00614ef0 ====

undefined4 FUN_00614ef0(byte *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_103;
  byte local_102;
  byte local_101;
  undefined1 local_100 [256];
  
  if (4 < *param_1) {
    FUN_0044a580(local_100,&DAT_009cca40,s_SHOPPLACE_is_Invalid_009cc7d0);
    FUN_00797b80(local_100);
    return 0;
  }
  piVar1 = *(int **)(in_ECX + 8 + (uint)*param_1 * 4);
  if (piVar1 == (int *)0x0) {
    FUN_0044a580(local_100,&DAT_009cca40,s_SHOP_Package_is_NULL_009cc7e8);
    FUN_00797b80(local_100);
    return 0;
  }
  local_102 = param_1[1];
  local_101 = param_1[2];
  local_103 = 0;
  uVar2 = (**(code **)(*piVar1 + 0x18))(&local_103);
  return uVar2;
}


// ==== FUN_00614f90 @ 0x00614f90 ====

undefined4 FUN_00614f90(undefined2 *param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 auStack_fe [254];
  
  *(undefined2 *)(in_ECX + 0x1e) = *param_1;
  *(undefined1 *)(in_ECX + 0x1c) = 1;
  iVar1 = (**(code **)(*DAT_00b5aa2c + 8))(*(undefined2 *)(in_ECX + 0x1e));
  if (iVar1 == 0) {
    FUN_0044a580(auStack_fe + -6,&DAT_009cca40,s_Shop_Open_Fail______Cannot_Find_S_009cc800);
    FUN_00797b80(auStack_fe + -6);
    return 0;
  }
  *(int *)(in_ECX + 0x24) = iVar1;
  return 1;
}


// ==== FUN_00615000 @ 0x00615000 ====

undefined4 FUN_00615000(undefined2 *param_1)

{
  short *psVar1;
  undefined1 uVar2;
  short sVar3;
  char cVar4;
  int *piVar5;
  short *psVar6;
  undefined4 uVar7;
  undefined2 extraout_var;
  undefined2 uVar8;
  undefined2 extraout_var_00;
  byte bVar9;
  uint uVar10;
  char acStack_204 [2];
  char acStack_202 [254];
  undefined1 auStack_104 [260];
  
  piVar5 = (int *)(**(code **)(*DAT_00b5ab88 + 8))(*param_1);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  psVar6 = (short *)(**(code **)(*piVar5 + 4))();
  if (*psVar6 == 0) {
    return 0;
  }
  if (*(int *)(param_1 + 2) == 0) {
    uVar10 = 0;
    if (*(char *)((int)psVar6 + 0x1b) == '\x01') {
      if (psVar6[0xe] != 0) {
        do {
          sVar3 = psVar6[uVar10 * 3 + 0x11];
          psVar1 = psVar6 + uVar10 * 3;
          uVar2 = *(undefined1 *)((int)psVar1 + 0x23);
          cVar4 = FUN_00614d30(psVar6[uVar10 * 3 + 0xf],
                               CONCAT22((short)((uint)psVar1 >> 0x10),psVar1[0x10]),acStack_204 + -4
                               ,param_1);
          if (cVar4 == '\0') {
            acStack_204[0] = cVar4;
            uVar7 = FUN_0044a580(acStack_204,s_ShopSet_Item_Invalie_Position__X_009cc8c0,(char)sVar3
                                 ,uVar2);
            FUN_00797b80(uVar7);
            auStack_104[0] = 0;
            uVar7 = FUN_0044a580(auStack_104,s_File___s__Line___d_009cc90c,
                                 s___Article_Item_Shop_Shop_cpp_009cc8ec,0x12f);
            FUN_00797b80(uVar7);
            FUN_00797a40();
          }
          bVar9 = (char)uVar10 + 1;
          uVar10 = (uint)bVar9;
        } while ((ushort)bVar9 < (ushort)psVar6[0xe]);
        return 1;
      }
    }
    else {
      uVar8 = extraout_var;
      if (psVar6[0xe] != 0) {
        do {
          FUN_00614b70(psVar6[uVar10 * 3 + 0xf],CONCAT22(uVar8,psVar6[uVar10 * 3 + 0x10]),param_1);
          bVar9 = (char)uVar10 + 1;
          uVar10 = (uint)bVar9;
          uVar8 = extraout_var_00;
        } while ((ushort)bVar9 < (ushort)psVar6[0xe]);
      }
    }
  }
  return 1;
}


// ==== FUN_00615180 @ 0x00615180 ====

uint FUN_00615180(void)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  byte bVar5;
  undefined1 uStack00000024;
  uint in_stack_00000060;
  undefined4 in_stack_00000064;
  undefined1 local_10c [256];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  uVar4 = in_stack_00000064;
  uVar3 = in_stack_00000060;
  puStack_8 = &LAB_00988607;
  local_c = ExceptionList;
  uVar2 = 0;
  local_4 = 0;
  if (in_stack_00000060 < 5) {
    bVar5 = 0;
    ExceptionList = &local_c;
    if (in_stack_00000060 != 0) {
      do {
        cVar1 = FUN_00615000(&uStack00000024 + uVar2 * 0xc,uVar4);
        if (cVar1 == '\0') {
          local_10c[0] = 0;
          uVar4 = FUN_0044a580(local_10c,s_____ERROR_____Cannot_Generate_It_009cc880,
                               *(undefined2 *)(&uStack00000024 + (uint)bVar5 * 0xc));
          uVar3 = FUN_00797b80(uVar4);
          ExceptionList = local_c;
          return uVar3 & 0xffffff00;
        }
        bVar5 = bVar5 + 1;
        uVar2 = (uint)bVar5;
      } while (uVar2 < uVar3);
    }
    uVar3 = 1;
  }
  else {
    ExceptionList = &local_c;
    FUN_0044a580(local_10c,&DAT_009cca40,s_Too_Many_SetToken_in_Tab_009cc864);
    uVar3 = FUN_00797b80(local_10c);
    uVar3 = uVar3 & 0xffffff00;
  }
  ExceptionList = local_c;
  return uVar3;
}


// ==== FUN_00615260 @ 0x00615260 ====

undefined4 FUN_00615260(void)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 auStack_17c [6];
  undefined2 uStack_162;
  undefined **ppuStack_160;
  undefined4 auStack_15c [12];
  undefined4 uStack_12c;
  undefined4 uStack_128;
  undefined1 *puStack_124;
  char *pcStack_120;
  uint uStack_11c;
  byte bStack_105;
  undefined1 auStack_100 [256];
  
  uStack_11c = 0x615274;
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x24) + 4))();
  *(undefined1 *)(in_ECX + 0x20) = 0;
  bStack_105 = 0;
  if (*(int *)(iVar2 + 0x1ec) != 0) {
    uStack_11c = 0;
    do {
      iVar4 = *(int *)(in_ECX + 8 + uStack_11c * 4);
      if (iVar4 == 0) {
        auStack_100[0] = 0;
        puStack_124 = auStack_100;
        pcStack_120 = s_____ERROR_____Missing_Package_in_009cc830;
        uStack_128 = 0x6152ac;
        uStack_128 = FUN_0044a580();
        uStack_12c = 0x6152b2;
        FUN_00797b80();
      }
      else {
        puVar1 = (undefined4 *)(uStack_11c * 0x60 + 0xc + iVar2);
        puVar5 = puVar1;
        puVar6 = auStack_17c;
        uStack_11c = iVar4;
        for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
        uStack_162 = *(undefined2 *)((int)puVar1 + 0x1a);
        ppuStack_160 = &PTR_FUN_009a5770;
        puVar5 = puVar1 + 8;
        puVar6 = auStack_15c;
        for (iVar4 = 0xf; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        pcStack_120 = (char *)puVar1[0x17];
        FUN_00615180();
      }
      bStack_105 = bStack_105 + 1;
      uStack_11c = (uint)bStack_105;
    } while (uStack_11c < *(uint *)(iVar2 + 0x1ec));
  }
  return 1;
}


// ==== FUN_00615330 @ 0x00615330 ====

void FUN_00615330(byte param_1)

{
  void *in_ECX;
  
  FUN_00614880();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00615350 @ 0x00615350 ====

void FUN_00615350(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00615355. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_00615360 @ 0x00615360 ====

void FUN_00615360(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00615365. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x34))();
  return;
}


// ==== FUN_00615370 @ 0x00615370 ====

void FUN_00615370(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00615375. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x3c))();
  return;
}


// ==== FUN_00615380 @ 0x00615380 ====

void FUN_00615380(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00615385. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x18))();
  return;
}


// ==== FUN_00615390 @ 0x00615390 ====

void FUN_00615390(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00615395. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  return;
}


// ==== FUN_006153a0 @ 0x006153a0 ====

void FUN_006153a0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006153a5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  return;
}


// ==== FUN_006153b0 @ 0x006153b0 ====

void FUN_006153b0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0xc))();
  (**(code **)(**(int **)(in_ECX + 0xc) + 8))(0);
  return;
}


// ==== FUN_006153d0 @ 0x006153d0 ====

undefined4 FUN_006153d0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_006153f0 @ 0x006153f0 ====

void FUN_006153f0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988628;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cca84;
  local_4 = 0;
  if ((int *)in_ECX[2] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[2] + 0xc))();
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00615460 @ 0x00615460 ====

uint FUN_00615460(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*param_2 + 0x1c))();
  if (piVar1 == (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x18))(param_1);
    return -(uint)(iVar2 != 0) & 2;
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (iVar2 == 5) {
    FUN_00803725(piVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                 &Framework::Article::IItem::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x006154c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
    return uVar3;
  }
  return 0;
}


// ==== FUN_006154d0 @ 0x006154d0 ====

int FUN_006154d0(undefined1 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  byte bVar7;
  int *in_ECX;
  byte bVar8;
  undefined4 uStack_4;
  
  piVar4 = param_2;
  uStack_4 = in_ECX;
  iVar2 = (**(code **)(*in_ECX + 0x14))(&param_1,param_2);
  if ((iVar2 == 0) || (iVar2 == 1)) {
    return 0;
  }
  uVar3 = (**(code **)(*piVar4 + 0x1c))
                    (0,&Framework::IArticle::RTTI_Type_Descriptor,
                     &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  piVar4 = (int *)FUN_00803725(uVar3);
  if (piVar4 == (int *)0x0) {
    iVar2 = (**(code **)(*(int *)in_ECX[2] + 0x18))(&uStack_4);
    return iVar2;
  }
  iVar2 = (**(code **)(*piVar4 + 0x2c))();
  uVar5 = (uint)uStack_4._1_2_;
  bVar7 = (byte)((uint)uStack_4 >> 8);
  if ((ushort)(uStack_4._1_2_ & 0xff) <
      (ushort)((ushort)*(byte *)(iVar2 + 0x30) + (uStack_4._1_2_ & 0xff))) {
    do {
      bVar8 = (byte)(uVar5 >> 8);
      if (uVar5 >> 8 < (uint)*(byte *)(iVar2 + 0x31) + (uVar5 >> 8)) {
        do {
          cVar1 = (**(code **)(*(int *)in_ECX[2] + 0x4c))((int)register0x00000010 + -0xc);
          if ((cVar1 != '\0') &&
             (iVar6 = (**(code **)(*(int *)in_ECX[2] + 0x18))((int)register0x00000010 + -0xc),
             iVar6 != 0)) {
            return iVar6;
          }
          uVar5 = (uint)uStack_4._1_2_;
          bVar8 = bVar8 + 1;
        } while ((ushort)bVar8 < (ushort)((ushort)*(byte *)(iVar2 + 0x31) + (uStack_4._1_2_ >> 8)));
      }
      bVar7 = bVar7 + 1;
    } while ((uint)bVar7 < (uint)*(byte *)(iVar2 + 0x30) + (uVar5 & 0xff));
  }
  return 0;
}


// ==== FUN_006155e0 @ 0x006155e0 ====

undefined4 FUN_006155e0(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*param_2 + 0x1c))();
  if (piVar1 == (int *)0x0) {
    iVar2 = (**(code **)(*in_ECX + 0x14))(param_1,param_2);
    if (iVar2 == 2) {
      uVar3 = (**(code **)(*in_ECX + 0x28))(param_1);
      (**(code **)(*param_2 + 0x14))(uVar3);
      return 1;
    }
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 == 5) {
      uVar3 = FUN_00803725(piVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                           &Framework::Article::IItem::RTTI_Type_Descriptor,0);
      iVar2 = (**(code **)(*(int *)in_ECX[2] + 0x30))(param_1,uVar3);
      if (iVar2 == 1) {
        (**(code **)(*in_ECX + 0x20))(param_1,uVar3);
        (**(code **)(*param_2 + 0x18))();
        return 1;
      }
      if (iVar2 == 3) {
        uVar3 = (**(code **)(*(int *)in_ECX[2] + 0x38))(param_1,uVar3);
        (**(code **)(*param_2 + 0x18))();
        (**(code **)(*param_2 + 0x14))(uVar3);
        return 1;
      }
      return 0;
    }
  }
  return 0;
}


// ==== FUN_006156b0 @ 0x006156b0 ====

int FUN_006156b0(int *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar3 = (**(code **)(*param_1 + 0x2c))();
  bVar1 = *(byte *)(iVar3 + 0x30);
  iVar3 = (**(code **)(*param_1 + 0x2c))();
  bVar2 = *(byte *)(iVar3 + 0x31);
  iVar3 = (**(code **)(*DAT_00b5a6b8 + 4))();
  return *(int *)(iVar3 + 0x48) * (uint)bVar2 * (uint)bVar1;
}


// ==== FUN_006156f0 @ 0x006156f0 ====

void FUN_006156f0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00988650;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cca84;
  pvVar1 = operator_new(0x14);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00638680(2,10,10);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    in_ECX[3] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00639bc0();
  in_ECX[3] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006157a0 @ 0x006157a0 ====

void FUN_006157a0(byte param_1)

{
  void *in_ECX;
  
  FUN_006153f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006157c0 @ 0x006157c0 ====

void FUN_006157c0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006157c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_006157d0 @ 0x006157d0 ====

void FUN_006157d0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006157d5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x34))();
  return;
}


// ==== FUN_006157e0 @ 0x006157e0 ====

void FUN_006157e0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006157e5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x3c))();
  return;
}


// ==== FUN_006157f0 @ 0x006157f0 ====

undefined1 FUN_006157f0(void)

{
  return 0;
}


// ==== FUN_00615800 @ 0x00615800 ====

void FUN_00615800(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00615805. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  return;
}


// ==== FUN_00615810 @ 0x00615810 ====

void FUN_00615810(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00615815. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  return;
}


// ==== FUN_00615820 @ 0x00615820 ====

void FUN_00615820(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  (**(code **)(**(int **)(in_ECX + 0xc) + 8))(0);
  *(undefined1 *)(in_ECX + 0x10) = 0;
  return;
}


// ==== FUN_00615840 @ 0x00615840 ====

void FUN_00615840(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  (**(code **)(**(int **)(in_ECX + 0xc) + 8))(0);
  *(undefined1 *)(in_ECX + 0x10) = 0;
  return;
}


// ==== FUN_00615860 @ 0x00615860 ====

undefined4 FUN_00615860(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00615870 @ 0x00615870 ====

void FUN_00615870(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_00615880 @ 0x00615880 ====

undefined1 FUN_00615880(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_00615890 @ 0x00615890 ====

void FUN_00615890(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988668;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ccacc;
  local_4 = 0;
  if ((int *)in_ECX[2] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[2] + 0x10))();
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00615900 @ 0x00615900 ====

uint FUN_00615900(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*param_2 + 0x1c))();
  if (piVar1 == (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x18))(param_1);
    return -(uint)(iVar2 != 0) & 2;
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (iVar2 == 5) {
    FUN_00803725(piVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                 &Framework::Article::IItem::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x00615961. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
    return uVar3;
  }
  return 0;
}


// ==== FUN_00615970 @ 0x00615970 ====

undefined4 FUN_00615970(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x48))(param_1,param_2);
  return uVar1;
}


// ==== FUN_00615990 @ 0x00615990 ====

void FUN_00615990(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00988690;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccacc;
  pvVar1 = operator_new(0x14);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00638680(1,10,5);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00639bc0();
  }
  in_ECX[3] = uVar2;
  *(undefined1 *)(in_ECX + 4) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00615a30 @ 0x00615a30 ====

void FUN_00615a30(byte param_1)

{
  void *in_ECX;
  
  FUN_00615890();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00615a50 @ 0x00615a50 ====

void FUN_00615a50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cc234;
  return;
}


// ==== FUN_00615a60 @ 0x00615a60 ====

undefined4 FUN_00615a60(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_00615a70 @ 0x00615a70 ====

void FUN_00615a70(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(in_ECX + 8);
  *(undefined1 *)(in_ECX + 0xc) = 1;
  return;
}


// ==== FUN_00615a80 @ 0x00615a80 ====

undefined1 FUN_00615a80(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    FUN_00803725(param_1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                 &Framework::Article::IItem::RTTI_Type_Descriptor,0);
    *(undefined4 *)(in_ECX + 8) = param_1;
    return 1;
  }
  return 0;
}


// ==== FUN_00615ac0 @ 0x00615ac0 ====

int FUN_00615ac0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 8);
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(in_ECX + 8) = 0;
  FUN_00803725(iVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
               &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  return iVar1;
}


// ==== FUN_00615af0 @ 0x00615af0 ====

void FUN_00615af0(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00803725(*(undefined4 *)(in_ECX + 8),0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a730 + 0x10))(1,iVar1);
    *(undefined4 *)(in_ECX + 8) = 0;
    return;
  }
  iVar1 = FUN_00803725(*(undefined4 *)(in_ECX + 8),0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IMoney::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    (**(code **)(*DAT_00b5a778 + 0x10))(1,iVar1);
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  return;
}


// ==== FUN_00615b60 @ 0x00615b60 ====

undefined4 FUN_00615b60(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0xc) == '\x01') {
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 0x10);
    *(undefined4 *)(in_ECX + 0x10) = 0;
    *(undefined1 *)(in_ECX + 0xc) = 0;
  }
  return 1;
}


// ==== FUN_00615b80 @ 0x00615b80 ====

void FUN_00615b80(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  return;
}


// ==== FUN_00615b90 @ 0x00615b90 ====

void FUN_00615b90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ccb14;
  in_ECX[2] = 0;
  in_ECX[4] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  return;
}


// ==== FUN_00615bb0 @ 0x00615bb0 ====

void FUN_00615bb0(byte param_1)

{
  void *in_ECX;
  
  FUN_00615a50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00615bd0 @ 0x00615bd0 ====

void FUN_00615bd0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
  (**(code **)(**(int **)(in_ECX + 8) + 8))();
  *(undefined1 *)(in_ECX + 0x11) = 1;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  return;
}


// ==== FUN_00615bf0 @ 0x00615bf0 ====

void FUN_00615bf0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00615bf5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
  return;
}


// ==== FUN_00615c00 @ 0x00615c00 ====

void FUN_00615c00(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0xc))(*(undefined4 *)(in_ECX + 0xc));
  *(undefined1 *)(in_ECX + 0x10) = 1;
  return;
}


// ==== FUN_00615c20 @ 0x00615c20 ====

void FUN_00615c20(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x10) == '\x01') {
    (**(code **)(**(int **)(in_ECX + 0xc) + 0xc))(*(undefined4 *)(in_ECX + 8));
    (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
    *(undefined1 *)(in_ECX + 0x10) = 0;
  }
  return;
}


// ==== FUN_00615c50 @ 0x00615c50 ====

void FUN_00615c50(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x10))();
  *(undefined1 *)(in_ECX + 0x10) = 0;
  return;
}


// ==== FUN_00615c70 @ 0x00615c70 ====

void FUN_00615c70(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x30))(param_1,&param_1);
  return;
}


// ==== FUN_00615c90 @ 0x00615c90 ====

undefined1 FUN_00615c90(void)

{
  return 0;
}


// ==== FUN_00615ca0 @ 0x00615ca0 ====

undefined1 FUN_00615ca0(void)

{
  return 0;
}


// ==== FUN_00615cb0 @ 0x00615cb0 ====

undefined1 FUN_00615cb0(void)

{
  return 0;
}


// ==== FUN_00615cc0 @ 0x00615cc0 ====

undefined1 FUN_00615cc0(void)

{
  return 0;
}


// ==== FUN_00615cd0 @ 0x00615cd0 ====

undefined1 FUN_00615cd0(void)

{
  return 0;
}


// ==== FUN_00615ce0 @ 0x00615ce0 ====

int FUN_00615ce0(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint3 uVar3;
  
  iVar2 = (**(code **)(*param_1 + 0x2c))();
  uVar1 = *(uint *)(iVar2 + 8);
  uVar3 = (uint3)(uVar1 >> 8);
  if ((((uVar1 >> 8 == 4) && (uVar1 != 0x40e)) && (uVar1 != 0x40f)) && (uVar1 != 0x410)) {
    return CONCAT31(uVar3,1);
  }
  return (uint)uVar3 << 8;
}


// ==== FUN_00615d60 @ 0x00615d60 ====

void FUN_00615d60(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009886a8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ccb4c;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00615dd0 @ 0x00615dd0 ====

undefined4 FUN_00615dd0(undefined1 param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 unaff_retaddr;
  
  iVar2 = (**(code **)(*param_2 + 0x1c))();
  iVar3 = FUN_00803725(iVar2,0,&Framework::IArticle::RTTI_Type_Descriptor,
                       &Framework::Article::IItem::RTTI_Type_Descriptor,0);
  if (iVar2 == 0) {
    if (iVar3 == 0) goto LAB_00615e21;
  }
  else if (iVar3 == 0) {
    return 0;
  }
  cVar1 = (**(code **)(*DAT_00b5a734 + 0x14))(*(undefined4 *)(in_ECX + 4),iVar3);
  if (cVar1 == '\0') {
    return 0;
  }
LAB_00615e21:
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  cVar1 = (**(code **)(*piVar4 + 0x40))(&param_1);
  if (cVar1 == '\0') {
    return 0;
  }
  uVar5 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(unaff_retaddr,iVar3);
  return uVar5;
}


// ==== FUN_00615e50 @ 0x00615e50 ====

bool FUN_00615e50(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  undefined4 unaff_ESI;
  int iStack_c;
  
  if (param_2 != 0) {
    iStack_c = param_2;
    cVar1 = (**(code **)(*DAT_00b5a734 + 0x14))(*(undefined4 *)(in_ECX + 4));
    if (cVar1 != '\0') {
      iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))(unaff_ESI,param_2);
      if ((iVar2 == 1) || (iVar2 == 3)) {
        return true;
      }
      if (iVar2 != 0) {
        piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))();
        cVar1 = (**(code **)(*piVar3 + 0x40))(&iStack_c);
        return cVar1 == '\x01';
      }
    }
  }
  return false;
}


// ==== FUN_00615ec0 @ 0x00615ec0 ====

undefined4 FUN_00615ec0(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  uVar2 = (**(code **)(*piVar1 + 0x28))();
  return uVar2;
}


// ==== FUN_00615ee0 @ 0x00615ee0 ====

undefined4 FUN_00615ee0(undefined4 param_1)

{
  char cVar1;
  undefined1 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined4 *unaff_EBX;
  char unaff_BP;
  
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  while( true ) {
    while( true ) {
      if (piVar3 == (int *)0x0) {
        return 0;
      }
      cVar1 = (**(code **)(*piVar3 + 0x28))();
      if (cVar1 != '\0') break;
      piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
    }
    iVar4 = (**(code **)(*piVar3 + 0x18))();
    uVar2 = (**(code **)(*DAT_00b5a734 + 0x14))(*(undefined4 *)(in_ECX + 4),param_1);
    unaff_EBX = (undefined4 *)CONCAT31((int3)((uint)unaff_EBX >> 8),uVar2);
    iVar5 = (**(code **)(*piVar3 + 0xc))(param_1);
    if (((iVar4 == 0) && (unaff_BP == '\x01')) && (iVar5 == 1)) break;
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
  }
  uVar6 = (**(code **)(*piVar3 + 4))();
  *unaff_EBX = uVar6;
  return 1;
}


// ==== FUN_00615fb0 @ 0x00615fb0 ====

void FUN_00615fb0(void)

{
  byte bVar1;
  char cVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int in_ECX;
  int *piVar11;
  char cVar12;
  int *piVar13;
  int *unaff_ESI;
  undefined1 auStack_1e [2];
  float local_1c;
  float local_18;
  int local_14;
  
  FUN_00616db0();
  piVar13 = (int *)0x0;
  cVar12 = '\0';
  uVar3 = FUN_00803725(*(undefined4 *)(in_ECX + 4),0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  *(undefined4 *)(in_ECX + 0x24) = 1;
  local_1c = 0.0;
  local_18 = 0.0;
  local_14 = 0;
  piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  if (piVar4 != (int *)0x0) {
    do {
      piVar5 = (int *)(**(code **)(*piVar4 + 0x18))();
      piVar11 = unaff_ESI;
      if (piVar5 == (int *)0x0) {
        piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
      }
      else {
        cVar12 = (**(code **)(*piVar4 + 0x20))();
        if (cVar12 == '\0') {
          piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
        }
        else {
          cVar12 = (**(code **)(*piVar4 + 0x28))();
          if (cVar12 == '\0') {
            piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
          }
          else {
            piVar4 = (int *)(**(code **)(*piVar5 + 0x48))();
            cVar12 = (**(code **)(*piVar4 + 0xc))();
            if (cVar12 == '\0') {
              piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
            }
            else {
              cVar12 = (**(code **)(*DAT_00b5a734 + 0x14))(uVar3,piVar5);
              if (cVar12 == '\0') {
                piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
              }
              else {
                iVar6 = (**(code **)(*piVar4 + 4))();
                piVar13 = (int *)(iVar6 + 4);
                pbVar7 = (byte *)(**(code **)(*piVar5 + 0x34))();
                iVar9 = *(int *)(in_ECX + 0x18);
                iVar8 = -(uint)*(ushort *)(pbVar7 + 100);
                if (iVar9 < iVar8 + 0xffff) {
                  if (iVar8 < iVar9) {
                    *(uint *)(in_ECX + 0x18) = iVar9 + (uint)*(ushort *)(pbVar7 + 100);
                  }
                  else {
                    *(undefined4 *)(in_ECX + 0x18) = 0;
                  }
                }
                else {
                  *(undefined4 *)(in_ECX + 0x18) = 0xffff;
                }
                iVar9 = *(int *)(in_ECX + 0x1c);
                iVar8 = -(uint)*(ushort *)(pbVar7 + 0x66);
                if (iVar9 < iVar8 + 0xffff) {
                  if (iVar8 < iVar9) {
                    *(uint *)(in_ECX + 0x1c) = iVar9 + (uint)*(ushort *)(pbVar7 + 0x66);
                  }
                  else {
                    *(undefined4 *)(in_ECX + 0x1c) = 0;
                  }
                }
                else {
                  *(undefined4 *)(in_ECX + 0x1c) = 0xffff;
                }
                FUN_00616cb0(pbVar7 + 0x69);
                iVar9 = (**(code **)(*unaff_ESI + 4))();
                if (iVar9 == 4) {
                  FUN_00616c70(auStack_1e + -10);
                  piVar11 = (int *)(uint)*(ushort *)(pbVar7 + 0x5e);
                  FUN_00616c70(auStack_1e + -10);
                  cVar12 = FUN_00615ce0(piVar5);
                  *(bool *)(in_ECX + 0x54) = cVar12 == '\x01';
                }
                else if (iVar9 == 5) {
                  FUN_00616c70(auStack_1e + -10);
                  piVar11 = (int *)(uint)*(ushort *)(pbVar7 + 0x5e);
                  FUN_00616c70(auStack_1e + -10);
                  cVar12 = FUN_00615ce0(piVar5);
                  *(bool *)(in_ECX + 0x55) = cVar12 == '\x01';
                }
                else {
                  FUN_00616c70(auStack_1e + -10);
                  piVar11 = (int *)(uint)*(ushort *)(pbVar7 + 0x5e);
                  FUN_00616c70(auStack_1e + -10);
                }
                iVar9 = *(int *)(in_ECX + 0x28);
                iVar8 = -(uint)*(ushort *)(pbVar7 + 0x60);
                if (iVar9 < iVar8 + 0xffff) {
                  if (iVar8 < iVar9) {
                    *(uint *)(in_ECX + 0x28) = iVar9 + (uint)*(ushort *)(pbVar7 + 0x60);
                  }
                  else {
                    *(undefined4 *)(in_ECX + 0x28) = 0;
                  }
                }
                else {
                  *(undefined4 *)(in_ECX + 0x28) = 0xffff;
                }
                iVar9 = *(int *)(in_ECX + 0x2c);
                iVar8 = -(uint)*(ushort *)(pbVar7 + 0x62);
                if (iVar9 < iVar8 + 0xffff) {
                  if (iVar8 < iVar9) {
                    *(uint *)(in_ECX + 0x2c) = iVar9 + (uint)*(ushort *)(pbVar7 + 0x62);
                  }
                  else {
                    *(undefined4 *)(in_ECX + 0x2c) = 0;
                  }
                }
                else {
                  *(undefined4 *)(in_ECX + 0x2c) = 0xffff;
                }
                uVar10 = (**(code **)(*unaff_ESI + 4))();
                switch(uVar10) {
                case 4:
                case 5:
                  break;
                case 6:
                case 7:
                case 0x13:
                case 0x14:
                  if ((*piVar13 == 4) && (*(int *)(iVar6 + 0xc) == 0x600)) {
                    if (local_1c < *(float *)(iVar6 + 0x94) || local_1c == *(float *)(iVar6 + 0x94))
                    {
                      local_1c = *(float *)(iVar6 + 0x94);
                    }
                    if (local_18 < *(float *)(iVar6 + 0x98) || local_18 == *(float *)(iVar6 + 0x98))
                    {
                      local_18 = *(float *)(iVar6 + 0x98);
                    }
LAB_006162da:
                    *(undefined1 *)(in_ECX + 0x60) = 1;
                  }
                  else if (*(int *)(iVar6 + 0xc) == 0x603) goto LAB_006162da;
                  if (*(int *)(iVar6 + 0xc) == 0x601) goto LAB_006162eb;
                  break;
                case 0xb:
                  local_14 = (int)(char)pbVar7[1];
                  break;
                case 0xc:
LAB_006162eb:
                  FUN_00616d50(pbVar7 + 1);
                }
                FUN_00616cb0(pbVar7 + 2);
                FUN_00616c30(pbVar7 + 0x6a);
                bVar1 = *(byte *)(in_ECX + 0x4a);
                if (*(byte *)(in_ECX + 0x4a) <= *pbVar7) {
                  bVar1 = *pbVar7;
                }
                if (bVar1 < 0xfb) {
                  *(byte *)(in_ECX + 0x4a) = bVar1;
                }
                else {
                  *(undefined1 *)(in_ECX + 0x4a) = 0xfa;
                }
                FUN_00616d00(pbVar7 + 9);
                FUN_00616d00(pbVar7 + 10);
                FUN_00616d00(pbVar7 + 0xb);
                FUN_00616d00(pbVar7 + 0xc);
                FUN_00616d00(pbVar7 + 0xd);
                piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
              }
            }
          }
        }
      }
      cVar12 = (char)piVar13;
      unaff_ESI = piVar11;
    } while (piVar4 != (int *)0x0);
    if (0 < (int)local_1c) {
      cVar2 = (char)((int)local_18 / (int)local_1c);
      goto LAB_0061638d;
    }
  }
  cVar2 = '\0';
LAB_0061638d:
  cVar12 = cVar12 + cVar2;
  if (cVar12 < -100) {
    *(undefined1 *)(in_ECX + 0x4b) = 0x9c;
  }
  else if (cVar12 < 'e') {
    *(char *)(in_ECX + 0x4b) = cVar12;
  }
  else {
    *(undefined1 *)(in_ECX + 0x4b) = 100;
  }
  *(int *)(in_ECX + 0x58) = local_14;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  return;
}


// ==== FUN_00616420 @ 0x00616420 ====

void FUN_00616420(void)

{
  int in_ECX;
  
  (**(code **)(*DAT_00b5a734 + 0x20))(*(undefined4 *)(in_ECX + 4));
  return;
}


// ==== FUN_00616440 @ 0x00616440 ====

undefined4 FUN_00616440(int param_1)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  while( true ) {
    while( true ) {
      if (piVar1 == (int *)0x0) {
        return 0;
      }
      iVar2 = (**(code **)(*piVar1 + 0x18))();
      if (iVar2 != 0) break;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
    }
    if (iVar2 == param_1) break;
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
  }
  return 1;
}


// ==== FUN_00616490 @ 0x00616490 ====

uint FUN_00616490(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  while( true ) {
    while( true ) {
      if (piVar1 == (int *)0x0) {
        return 1;
      }
      iVar2 = (**(code **)(*piVar1 + 4))();
      if (((iVar2 != 0xf) && (iVar2 = (**(code **)(*piVar1 + 4))(), iVar2 != 0x10)) &&
         (iVar2 = (**(code **)(*piVar1 + 4))(), iVar2 != 0x11)) break;
      piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
    }
    uVar3 = (**(code **)(*piVar1 + 0x18))();
    if (uVar3 != 0) break;
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
  }
  return uVar3 & 0xffffff00;
}


// ==== FUN_00616500 @ 0x00616500 ====

undefined4 FUN_00616500(void)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  undefined4 *puVar6;
  undefined4 auStack_64 [20];
  void *pvStack_14;
  int local_10;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009886ba;
  pvStack_c = ExceptionList;
  local_10 = 0;
  local_4 = 0;
  ExceptionList = &pvStack_c;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  if (piVar1 != (int *)0x0) {
    puVar6 = auStack_64;
    do {
      piVar2 = (int *)(**(code **)(*piVar1 + 0x18))();
      if (piVar2 == (int *)0x0) {
        piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
      }
      else {
        iVar5 = (**(code **)(*piVar1 + 4))();
        if (iVar5 != 0xf) {
          iVar5 = (**(code **)(*piVar1 + 4))();
          if (iVar5 != 0x10) {
            iVar5 = (**(code **)(*piVar1 + 4))();
            if (iVar5 != 0x11) {
              piVar3 = (int *)(**(code **)(*piVar2 + 0x48))();
              iVar5 = (**(code **)(*piVar3 + 4))();
              if (*(int *)(iVar5 + 0xc) == 4) {
                piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
              }
              else {
                piVar2 = (int *)(**(code **)(*piVar2 + 0x48))();
                iVar5 = (**(code **)(*piVar2 + 4))();
                if (*(int *)(iVar5 + 4) == 4) {
                  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
                }
                else {
                  local_10 = local_10 + 1;
                  uVar4 = (**(code **)(*piVar1 + 4))();
                  piVar1 = *(int **)(in_ECX + 8);
                  *puVar6 = uVar4;
                  puVar6 = puVar6 + 1;
                  piVar1 = (int *)(**(code **)(*piVar1 + 0x2c))();
                }
              }
              goto LAB_006165e4;
            }
          }
        }
        piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
      }
LAB_006165e4:
    } while (piVar1 != (int *)0x0);
    if (local_10 != 0) {
      iVar5 = (**(code **)(*DAT_00b5b0a0 + 0x10))(0,local_10);
      ExceptionList = pvStack_14;
      return auStack_64[iVar5 + -2];
    }
  }
  ExceptionList = pvStack_c;
  return 0x15;
}


// ==== FUN_00616640 @ 0x00616640 ====

void FUN_00616640(void)

{
  void *pvVar1;
  int *piVar2;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009886e2;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ccb4c;
  *(undefined1 *)(in_ECX + 5) = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  *(undefined2 *)(in_ECX + 0x12) = 0;
  *(undefined1 *)((int)in_ECX + 0x4a) = 0;
  *(undefined1 *)((int)in_ECX + 0x4b) = 0x9c;
  *(undefined1 *)(in_ECX + 0x13) = 0x9c;
  *(undefined1 *)((int)in_ECX + 0x4d) = 0;
  *(undefined1 *)((int)in_ECX + 0x4e) = 0;
  *(undefined1 *)((int)in_ECX + 0x4f) = 0x9c;
  *(undefined1 *)(in_ECX + 0x14) = 0x9c;
  *(undefined1 *)((int)in_ECX + 0x51) = 0x9c;
  *(undefined1 *)((int)in_ECX + 0x52) = 0x9c;
  local_4 = 0;
  *(undefined1 *)((int)in_ECX + 0x53) = 0x9c;
  pvVar1 = operator_new(0x10);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0063a100();
  }
  in_ECX[2] = piVar2;
  local_4 = (uint)local_4._1_3_ << 8;
  (**(code **)(*piVar2 + 4))(0);
  (**(code **)(*(int *)in_ECX[2] + 4))(1);
  (**(code **)(*(int *)in_ECX[2] + 4))(2);
  (**(code **)(*(int *)in_ECX[2] + 4))(3);
  (**(code **)(*(int *)in_ECX[2] + 4))(8);
  (**(code **)(*(int *)in_ECX[2] + 4))(9);
  (**(code **)(*(int *)in_ECX[2] + 4))(10);
  (**(code **)(*(int *)in_ECX[2] + 4))(0xb);
  (**(code **)(*(int *)in_ECX[2] + 4))(0xc);
  (**(code **)(*(int *)in_ECX[2] + 4))(6);
  (**(code **)(*(int *)in_ECX[2] + 4))(7);
  (**(code **)(*(int *)in_ECX[2] + 4))(4);
  (**(code **)(*(int *)in_ECX[2] + 4))(5);
  (**(code **)(*(int *)in_ECX[2] + 4))(0xf);
  (**(code **)(*(int *)in_ECX[2] + 4))(0x10);
  (**(code **)(*(int *)in_ECX[2] + 4))(0x11);
  (**(code **)(*(int *)in_ECX[2] + 4))(0xd);
  (**(code **)(*(int *)in_ECX[2] + 4))(0xe);
  (**(code **)(*(int *)in_ECX[2] + 4))(0x12);
  (**(code **)(*(int *)in_ECX[2] + 4))(0x13);
  (**(code **)(*(int *)in_ECX[2] + 4))(0x14);
  pvVar1 = operator_new(0x10);
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_0063a100();
  }
  in_ECX[3] = piVar2;
  (**(code **)(*piVar2 + 4))(0);
  (**(code **)(*(int *)in_ECX[3] + 4))(1);
  (**(code **)(*(int *)in_ECX[3] + 4))(2);
  (**(code **)(*(int *)in_ECX[3] + 4))(3);
  (**(code **)(*(int *)in_ECX[3] + 4))(8);
  (**(code **)(*(int *)in_ECX[3] + 4))(9);
  (**(code **)(*(int *)in_ECX[3] + 4))(10);
  (**(code **)(*(int *)in_ECX[3] + 4))(0xb);
  (**(code **)(*(int *)in_ECX[3] + 4))(0xc);
  (**(code **)(*(int *)in_ECX[3] + 4))(6);
  (**(code **)(*(int *)in_ECX[3] + 4))(7);
  (**(code **)(*(int *)in_ECX[3] + 4))(4);
  (**(code **)(*(int *)in_ECX[3] + 4))(5);
  (**(code **)(*(int *)in_ECX[3] + 4))(0xf);
  (**(code **)(*(int *)in_ECX[3] + 4))(0x10);
  (**(code **)(*(int *)in_ECX[3] + 4))();
  (**(code **)(*(int *)in_ECX[3] + 4))(0xd);
  (**(code **)(*(int *)in_ECX[3] + 4))(0xe);
  (**(code **)(*(int *)in_ECX[3] + 4))(0x12);
  (**(code **)(*(int *)in_ECX[3] + 4))(0x13);
  (**(code **)(*(int *)in_ECX[3] + 4))(0x14);
  *(undefined1 *)((int)in_ECX + 0x11) = 1;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00616db0();
  ExceptionList = (void *)0x11;
  return;
}


// ==== FUN_006168d0 @ 0x006168d0 ====

undefined4 FUN_006168d0(undefined4 param_1)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  uVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x14))(param_1);
  iVar3 = FUN_00803725(*(undefined4 *)(in_ECX + 4),0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  (**(code **)(**(int **)(iVar3 + 0x18) + 0x1c))();
  *(undefined1 *)(in_ECX + 0x11) = 1;
  cVar1 = FUN_005c8e90();
  if (cVar1 == '\x01') {
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))();
    (**(code **)(*piVar4 + 0x18))();
  }
  return uVar2;
}


// ==== FUN_00616930 @ 0x00616930 ====

char FUN_00616930(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  
  cVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x18))(param_1,param_2);
  if (cVar1 == '\0') {
    return '\0';
  }
  iVar3 = FUN_00803725(*(undefined4 *)(in_ECX + 4),0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  (**(code **)(**(int **)(iVar3 + 0x18) + 0x1c))();
  *(undefined1 *)(in_ECX + 0x11) = 1;
  cVar2 = FUN_005c8e90();
  if (cVar2 == '\x01') {
    piVar4 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))();
    (**(code **)(*piVar4 + 0x18))();
  }
  return cVar1;
}


// ==== FUN_006169a0 @ 0x006169a0 ====

char FUN_006169a0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  
  iVar3 = (**(code **)(*in_ECX + 0x18))(param_1,param_2);
  if (iVar3 != 0) {
    cVar1 = (**(code **)(*(int *)in_ECX[2] + 0x20))(param_1,param_2);
    if (cVar1 != '\0') {
      iVar3 = FUN_00803725(in_ECX[1],0,&Framework::ICreature::RTTI_Type_Descriptor,
                           &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
      (**(code **)(**(int **)(iVar3 + 0x18) + 0x1c))();
      *(undefined1 *)((int)in_ECX + 0x11) = 1;
      cVar2 = FUN_005c8e90();
      if (cVar2 == '\x01') {
        piVar4 = (int *)(**(code **)(*(int *)in_ECX[1] + 0x10))();
        (**(code **)(*piVar4 + 0x18))();
      }
      return cVar1;
    }
  }
  return '\0';
}


// ==== FUN_00616a20 @ 0x00616a20 ====

undefined1 FUN_00616a20(undefined4 param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int *in_ECX;
  undefined4 unaff_ESI;
  
  uVar1 = param_1;
  cVar2 = (**(code **)(*in_ECX + 0x30))(param_1,&param_1);
  if (cVar2 == '\0') {
    return 0;
  }
  (**(code **)(*in_ECX + 0x24))(unaff_ESI,uVar1);
  iVar3 = FUN_00803725(in_ECX[1],0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  (**(code **)(**(int **)(iVar3 + 0x18) + 0x1c))();
  return 1;
}


// ==== FUN_00616a80 @ 0x00616a80 ====

int FUN_00616a80(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x11) == '\x01') {
    FUN_00615fb0();
    *(undefined1 *)(in_ECX + 0x11) = 0;
  }
  return in_ECX + 0x14;
}


// ==== FUN_00616aa0 @ 0x00616aa0 ====

void FUN_00616aa0(undefined4 param_1)

{
  int *piVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  bool bVar7;
  
  FUN_00797a50(param_1,0,0x280);
  piVar1 = *(int **)(in_ECX + 4);
  iVar6 = 0;
  do {
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(iVar6);
    cVar2 = (**(code **)(*piVar3 + 0x28))();
    if ((((cVar2 != '\0') && (cVar2 = (**(code **)(*piVar3 + 0x20))(), cVar2 != '\0')) &&
        (piVar3 = (int *)(**(code **)(*piVar3 + 0x18))(), piVar3 != (int *)0x0)) &&
       (cVar2 = (**(code **)(*DAT_00b5a734 + 0x14))(piVar1,piVar3), cVar2 != '\0')) {
      piVar4 = (int *)(**(code **)(*piVar1 + 0x10))();
      cVar2 = (**(code **)(*piVar4 + 0x44))();
      if (cVar2 == '\x01') {
        piVar4 = (int *)(**(code **)(*piVar3 + 0x48))();
        iVar5 = (**(code **)(*piVar4 + 4))();
        bVar7 = *(int *)(iVar5 + 0xc) == 0x601;
      }
      else {
        piVar4 = (int *)(**(code **)(*piVar3 + 0x48))();
        iVar5 = (**(code **)(*piVar4 + 4))();
        bVar7 = *(int *)(iVar5 + 0xc) == 0x604;
      }
      if (!bVar7) {
        (**(code **)(*DAT_00b5a734 + 0x30))(piVar3,param_1);
        (**(code **)(*DAT_00b5a734 + 0x34))(piVar3,param_1);
      }
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x15);
  return;
}


// ==== FUN_00616b80 @ 0x00616b80 ====

undefined1 FUN_00616b80(void)

{
  char cVar1;
  char cVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  undefined1 local_5;
  undefined4 uStack_4;
  
  local_5 = 0;
  piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  do {
    iVar4 = (**(code **)(*piVar3 + 0x18))();
    if (iVar4 != 0) {
      cVar1 = (**(code **)(*DAT_00b5a734 + 0x14))(*(undefined4 *)(in_ECX + 4),iVar4);
      cVar2 = (**(code **)(*piVar3 + 0x20))();
      if (cVar2 != cVar1) {
        (**(code **)(*piVar3 + 0x24))(uStack_4);
        iVar4 = FUN_00803725(*(undefined4 *)(in_ECX + 4),0,
                             &Framework::ICreature::RTTI_Type_Descriptor,
                             &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
        (**(code **)(**(int **)(iVar4 + 0x18) + 0x1c))();
        local_5 = 1;
      }
    }
    piVar3 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
  } while (piVar3 != (int *)0x0);
  return local_5;
}


// ==== FUN_00616c30 @ 0x00616c30 ====

void FUN_00616c30(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte *in_ECX;
  
  bVar1 = *param_1;
  bVar2 = *in_ECX;
  if ((int)(0xfa - (uint)bVar1) <= (int)(uint)bVar2) {
    *in_ECX = 0xfa;
    return;
  }
  if ((int)-(uint)bVar1 < (int)(uint)bVar2) {
    *in_ECX = bVar2 + bVar1;
    return;
  }
  *in_ECX = 0;
  return;
}


// ==== FUN_00616c70 @ 0x00616c70 ====

void FUN_00616c70(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = *param_1;
  iVar2 = *in_ECX;
  if (0xffff - iVar1 <= iVar2) {
    *in_ECX = 0xffff;
    return;
  }
  if (-iVar1 < iVar2) {
    *in_ECX = iVar2 + iVar1;
    return;
  }
  *in_ECX = 0;
  return;
}


// ==== FUN_00616cb0 @ 0x00616cb0 ====

void FUN_00616cb0(byte *param_1)

{
  byte bVar1;
  byte bVar2;
  byte *in_ECX;
  
  bVar1 = *param_1;
  bVar2 = *in_ECX;
  if ((int)(100 - (uint)bVar1) <= (int)(uint)bVar2) {
    *in_ECX = 100;
    return;
  }
  if ((int)-(uint)bVar1 < (int)(uint)bVar2) {
    *in_ECX = bVar2 + bVar1;
    return;
  }
  *in_ECX = 0;
  return;
}


// ==== FUN_00616d00 @ 0x00616d00 ====

void FUN_00616d00(char *param_1)

{
  char cVar1;
  char cVar2;
  char *in_ECX;
  
  cVar1 = *param_1;
  cVar2 = *in_ECX;
  if (100 - cVar1 <= (int)cVar2) {
    *in_ECX = 'd';
    return;
  }
  if (-100 - cVar1 < (int)cVar2) {
    *in_ECX = cVar2 + cVar1;
    return;
  }
  *in_ECX = -100;
  return;
}


// ==== FUN_00616d50 @ 0x00616d50 ====

void FUN_00616d50(char *param_1)

{
  char cVar1;
  char *in_ECX;
  
  cVar1 = *param_1;
  if (cVar1 < -100) {
    *in_ECX = -100;
    return;
  }
  if (cVar1 < 'e') {
    *in_ECX = cVar1;
    return;
  }
  *in_ECX = 'd';
  return;
}


// ==== FUN_00616d80 @ 0x00616d80 ====

void FUN_00616d80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ccb44;
  return;
}


// ==== FUN_00616d90 @ 0x00616d90 ====

void FUN_00616d90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009ccb44;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00616db0 @ 0x00616db0 ====

void FUN_00616db0(void)

{
  undefined1 *in_ECX;
  
  *in_ECX = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  in_ECX[0xc] = 0;
  *(undefined4 *)(in_ECX + 0x10) = 1;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0x28) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined2 *)(in_ECX + 0x34) = 0;
  in_ECX[0x36] = 1;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  in_ECX[0x3a] = 0;
  in_ECX[0x3b] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  in_ECX[0x4c] = 0;
  return;
}


// ==== FUN_00616e20 @ 0x00616e20 ====

void FUN_00616e20(byte param_1)

{
  void *in_ECX;
  
  FUN_00615d60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00616e40 @ 0x00616e40 ====

void FUN_00616e40(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0xc))();
  if (*(int **)(in_ECX + 0x14) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x14) + 0x10))();
    *(undefined1 *)(in_ECX + 0x10) = 0;
  }
  return;
}


// ==== FUN_00616e60 @ 0x00616e60 ====

void FUN_00616e60(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00616e65. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return;
}


// ==== FUN_00616e70 @ 0x00616e70 ====

void FUN_00616e70(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00616e75. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x18))();
  return;
}


// ==== FUN_00616e80 @ 0x00616e80 ====

void FUN_00616e80(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00616e85. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x1c))();
  return;
}


// ==== FUN_00616e90 @ 0x00616e90 ====

void FUN_00616e90(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00616e95. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x34))();
  return;
}


// ==== FUN_00616ea0 @ 0x00616ea0 ====

void FUN_00616ea0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00616ea5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x3c))();
  return;
}


// ==== FUN_00616eb0 @ 0x00616eb0 ====

void FUN_00616eb0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00616eb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  return;
}


// ==== FUN_00616ec0 @ 0x00616ec0 ====

void FUN_00616ec0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00616ec5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  return;
}


// ==== FUN_00616ed0 @ 0x00616ed0 ====

undefined4 FUN_00616ed0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00803725(param_1,0,&Framework::Article::IItem::IBag::RTTI_Type_Descriptor,
                       &Framework::Article::Item::Bag::Bag::RTTI_Type_Descriptor,0);
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))(*(undefined4 *)(iVar1 + 8));
  return 1;
}


// ==== FUN_00616f00 @ 0x00616f00 ====

undefined4 FUN_00616f00(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00616f10 @ 0x00616f10 ====

void FUN_00616f10(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))(*(undefined4 *)(in_ECX + 0x14));
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 0xc) + 4))();
  (**(code **)(**(int **)(in_ECX + 0x18) + 8))(*puVar1);
  *(undefined1 *)(in_ECX + 0x10) = 1;
  return;
}


// ==== FUN_00616f40 @ 0x00616f40 ====

undefined4 FUN_00616f40(void)

{
  undefined4 *puVar1;
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x14) + 0x14))(*(undefined4 *)(in_ECX + 8));
  (**(code **)(**(int **)(in_ECX + 0x14) + 0x10))();
  puVar1 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 0x18) + 4))();
  (**(code **)(**(int **)(in_ECX + 0xc) + 8))(*puVar1);
  (**(code **)(**(int **)(in_ECX + 0x18) + 8))(0);
  *(undefined1 *)(in_ECX + 0x10) = 0;
  return 1;
}


// ==== FUN_00616f80 @ 0x00616f80 ====

void FUN_00616f80(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x14) + 0x10))();
  (**(code **)(**(int **)(in_ECX + 0x18) + 8))(0);
  *(undefined1 *)(in_ECX + 0x10) = 0;
  return;
}


// ==== FUN_00616fa0 @ 0x00616fa0 ====

void FUN_00616fa0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x1c) = param_1;
                    /* WARNING: Could not recover jumptable at 0x00616fb0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x58))();
  return;
}


// ==== FUN_00616fc0 @ 0x00616fc0 ====

undefined1 FUN_00616fc0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x1c);
}


// ==== FUN_00616fd0 @ 0x00616fd0 ====

undefined4 FUN_00616fd0(void)

{
  int in_ECX;
  
  if (*(byte *)(in_ECX + 0x1c) < 4) {
    *(byte *)(in_ECX + 0x1c) = *(byte *)(in_ECX + 0x1c) + 1;
    (**(code **)(**(int **)(in_ECX + 8) + 0x5c))();
    return 1;
  }
  return 0;
}


// ==== FUN_00616ff0 @ 0x00616ff0 ====

void FUN_00616ff0(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009886f8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ccc04;
  local_4 = 0;
  (**(code **)(*(int *)in_ECX[2] + 0xc))();
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((int *)in_ECX[5] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[5] + 0x10))();
    if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)in_ECX[5])(1);
    }
    in_ECX[5] = 0;
  }
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00617090 @ 0x00617090 ====

uint FUN_00617090(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(*param_2 + 0x1c))();
  if (piVar1 == (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x18))(param_1);
    return -(uint)(iVar2 != 0) & 2;
  }
  iVar2 = (**(code **)(*piVar1 + 4))();
  if (iVar2 == 5) {
    FUN_00803725(piVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                 &Framework::Article::IItem::RTTI_Type_Descriptor,0);
                    /* WARNING: Could not recover jumptable at 0x006170f1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar3 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))();
    return uVar3;
  }
  return 0;
}


// ==== FUN_00617100 @ 0x00617100 ====

undefined4 FUN_00617100(undefined4 param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*param_2 + 0x1c))();
  if (piVar1 == (int *)0x0) {
    iVar2 = (**(code **)(*in_ECX + 0x14))(param_1,param_2);
    if (iVar2 == 2) {
      uVar3 = (**(code **)(*in_ECX + 0x20))(param_1);
      (**(code **)(*param_2 + 0x14))(uVar3);
      return 2;
    }
  }
  else {
    iVar2 = (**(code **)(*piVar1 + 4))();
    if (iVar2 == 5) {
      uVar3 = FUN_00803725(piVar1,0,&Framework::IArticle::RTTI_Type_Descriptor,
                           &Framework::Article::IItem::RTTI_Type_Descriptor,0);
      iVar2 = (**(code **)(*(int *)in_ECX[2] + 0x30))(param_1,uVar3);
      if (iVar2 == 1) {
        (**(code **)(*in_ECX + 0x1c))(param_1,uVar3);
        (**(code **)(*param_2 + 0x18))();
        return 1;
      }
      if (iVar2 == 3) {
        uVar3 = (**(code **)(*(int *)in_ECX[2] + 0x38))(param_1,uVar3);
        (**(code **)(*param_2 + 0x18))();
        (**(code **)(*param_2 + 0x14))(uVar3);
        return 3;
      }
      if (iVar2 == 4) {
        (**(code **)(*(int *)in_ECX[2] + 0x40))(param_1,uVar3);
        (**(code **)(*param_2 + 0x18))();
        return 4;
      }
      if (iVar2 == 5) {
        piVar1 = (int *)(**(code **)(*in_ECX + 0x28))(param_1);
        if (piVar1 != (int *)0x0) {
          piVar1 = (int *)(**(code **)(*piVar1 + 0x48))();
          iVar2 = (**(code **)(*piVar1 + 4))();
          if (*(int *)(iVar2 + 4) != 4) {
            (**(code **)(*param_2 + 0x18))();
            iVar2 = (**(code **)(*(int *)in_ECX[2] + 0x44))(param_1,uVar3);
            if (iVar2 != 0) {
              (**(code **)(*param_2 + 0x14))(iVar2);
            }
            return 5;
          }
        }
      }
      return 0;
    }
  }
  return 0;
}


// ==== FUN_00617250 @ 0x00617250 ====

undefined4 FUN_00617250(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (param_1 == 0) {
    return 0;
  }
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x48))(param_1,param_2);
  return uVar1;
}


// ==== FUN_00617270 @ 0x00617270 ====

undefined4 FUN_00617270(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar1 = param_1;
  if (param_1 == 0) {
    return 0;
  }
  param_1 = param_1 & 0xff000000;
  uVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x48))(uVar1,&param_1);
  return uVar2;
}


// ==== FUN_006172a0 @ 0x006172a0 ====

undefined4 FUN_006172a0(uint param_1)

{
  uint uVar1;
  char cVar2;
  int in_ECX;
  undefined1 auStackY_98 [128];
  
  uVar1 = param_1;
  if (param_1 != 0) {
    param_1 = param_1 & 0xff000000;
    cVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x48))(uVar1,&param_1);
    if (cVar2 != '\0') {
      (**(code **)(**(int **)(in_ECX + 8) + 0x34))(auStackY_98 + 0x94,uVar1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_006172f0 @ 0x006172f0 ====

undefined4 FUN_006172f0(uint param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar1 = param_1;
  if (param_1 == 0) {
    return 0;
  }
  param_1 = param_1 & 0xff000000;
  uVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x50))(uVar1,&param_1);
  return uVar2;
}


// ==== FUN_00617320 @ 0x00617320 ====

bool FUN_00617320(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  int *unaff_retaddr;
  
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x54))(param_1,param_3);
  if (iVar2 == 0) {
    return false;
  }
  cVar1 = (**(code **)(*unaff_retaddr + 0x14))(iVar2);
  return cVar1 != '\0';
}


// ==== FUN_00617350 @ 0x00617350 ====

undefined4 FUN_00617350(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x24))();
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    if (iVar1 == param_1) break;
    iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))();
  }
  return 1;
}


// ==== FUN_00617390 @ 0x00617390 ====

undefined4 FUN_00617390(void)

{
  return 0;
}


// ==== FUN_006173a0 @ 0x006173a0 ====

void FUN_006173a0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00988736;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccc04;
  pvVar1 = operator_new(0x14);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00638680(4,10,5);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(8);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00639bc0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[3] = uVar2;
  *(undefined1 *)(in_ECX + 4) = 0;
  pvVar1 = operator_new(0x14);
  local_4._0_1_ = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00638680(4,10,5);
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = CONCAT31(local_4._1_3_,4);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00639bc0();
  }
  in_ECX[6] = uVar2;
  *(undefined1 *)(in_ECX + 7) = 2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006174a0 @ 0x006174a0 ====

uint FUN_006174a0(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_110;
  undefined1 local_104;
  undefined1 local_103;
  undefined1 local_102;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uStack_110 = &local_104;
    local_104 = 0;
    local_103 = 0;
    local_102 = 0;
    uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x50))(param_1);
    if ((char)uVar1 != '\0') {
      iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x44))((int)register0x00000010 + -0x10c,param_1)
      ;
      if (iVar2 == 0) {
        return 1;
      }
      FUN_0044a580(&uStack_110,&DAT_009ccbfc,&DAT_009ccbc4);
      uVar1 = FUN_00797b80(&uStack_110);
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00617530 @ 0x00617530 ====

void FUN_00617530(byte param_1)

{
  void *in_ECX;
  
  FUN_00616ff0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00617550 @ 0x00617550 ====

void FUN_00617550(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988748;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccc80;
  local_4 = 0;
  FUN_006339c0();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_006175a0 @ 0x006175a0 ====

int FUN_006175a0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_006175b0 @ 0x006175b0 ====

int FUN_006175b0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_006175c0 @ 0x006175c0 ====

void FUN_006175c0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*DAT_00b5a780 + 8))(param_1);
  (**(code **)(*(int *)(in_ECX + 8) + 0x50))(*(undefined4 *)(in_ECX + 4));
  FUN_00633ac0(uVar1);
  (**(code **)(*(int *)(in_ECX + 8) + 0x38))(0);
  return;
}


// ==== FUN_00617600 @ 0x00617600 ====

void FUN_00617600(void)

{
  int in_ECX;
  
  FUN_00633ac0(0);
  (**(code **)(*(int *)(in_ECX + 8) + 0x50))(0);
  return;
}


// ==== FUN_00617620 @ 0x00617620 ====

void FUN_00617620(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098875a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccc80;
  FUN_00633cf0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_00617670 @ 0x00617670 ====

void FUN_00617670(byte param_1)

{
  void *in_ECX;
  
  FUN_00617550();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00617690 @ 0x00617690 ====

undefined1 FUN_00617690(void)

{
  return 1;
}


// ==== FUN_006176a0 @ 0x006176a0 ====

void FUN_006176a0(void)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0xc) + 4))();
  (**(code **)(**(int **)(in_ECX + 8) + 4))();
  (**(code **)(**(int **)(in_ECX + 0x10) + 4))(0);
  return;
}


// ==== FUN_006176c0 @ 0x006176c0 ====

void FUN_006176c0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
                    /* WARNING: Could not recover jumptable at 0x006176d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc) + 8))();
  return;
}


// ==== FUN_006176e0 @ 0x006176e0 ====

undefined4 FUN_006176e0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_006176f0 @ 0x006176f0 ====

undefined4 FUN_006176f0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_00617700 @ 0x00617700 ====

undefined4 FUN_00617700(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x10);
}


// ==== FUN_00617710 @ 0x00617710 ====

void FUN_00617710(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988778;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009ccca4;
  local_4 = 0;
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[3])(1);
  }
  in_ECX[3] = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_00617790 @ 0x00617790 ====

void FUN_00617790(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009887ab;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccca4;
  pvVar1 = operator_new(0x10);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0063b340();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4._0_1_ = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0063aef0();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = CONCAT31(local_4._1_3_,3);
  if (pvVar1 == (void *)0x0) {
    in_ECX[4] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0063ade0();
  in_ECX[4] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00617860 @ 0x00617860 ====

void FUN_00617860(int param_1)

{
  ushort uVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  ushort *puVar6;
  int *piVar7;
  int *piVar8;
  byte *pbVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  int *in_ECX;
  int iVar13;
  byte bVar14;
  
  FUN_00797a50(param_1,0,0x280);
  iVar4 = FUN_00803725(in_ECX[1],0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (iVar4 == 0) {
    return;
  }
  piVar5 = (int *)0x0;
  if (*(int **)(iVar4 + 0x48) != (int *)0x0) {
    piVar5 = (int *)(**(code **)(**(int **)(iVar4 + 0x48) + 0x28))();
  }
  puVar6 = (ushort *)(**(code **)(*piVar5 + 8))();
  uVar1 = *puVar6;
  piVar7 = (int *)(**(code **)(*in_ECX + 0x20))();
  piVar5 = (int *)(**(code **)(*piVar7 + 0x20))();
  do {
    while( true ) {
      if (piVar5 == (int *)0x0) {
        return;
      }
      piVar8 = (int *)(**(code **)(*piVar5 + 0x10))();
      piVar5 = (int *)(**(code **)(*piVar5 + 0x18))();
      pbVar9 = (byte *)(**(code **)(*piVar5 + 0xc))();
      bVar14 = *pbVar9;
      iVar10 = (**(code **)(*piVar8 + 4))();
      iVar4 = *(int *)(iVar10 + 0x2bc4);
      if ((iVar4 != 0x10) && (iVar4 != 0x20)) break;
LAB_00617980:
      piVar5 = (int *)(**(code **)(*piVar7 + 0x24))();
    }
    if (iVar4 == 2) {
      uVar11 = (**(code **)(**(int **)(in_ECX[1] + 0x74) + 0x14))();
      cVar3 = (**(code **)(*piVar8 + 0x10))(uVar11);
      if (cVar3 == '\0') goto LAB_00617980;
    }
    iVar13 = (uint)(bVar14 & 0xf) * 0x80;
    iVar4 = iVar13 + 4 + iVar10;
    if (uVar1 < *(byte *)(iVar13 + 0x54 + iVar10)) goto LAB_00617980;
    bVar14 = 0;
    if (*(int *)(iVar4 + 0x34) != 0) {
      uVar12 = 0;
      do {
        uVar2 = *(uint *)(iVar4 + 4 + uVar12 * 8);
        if ((uVar2 != 0) && (uVar2 < 0xa0)) {
          *(undefined4 *)(param_1 + uVar2 * 4) = *(undefined4 *)(iVar4 + 8 + uVar12 * 8);
        }
        bVar14 = bVar14 + 1;
        uVar12 = (uint)bVar14;
      } while (uVar12 < *(uint *)(iVar4 + 0x34));
    }
    piVar5 = (int *)(**(code **)(*piVar7 + 0x24))();
  } while( true );
}


// ==== FUN_006179a0 @ 0x006179a0 ====

void FUN_006179a0(byte param_1)

{
  void *in_ECX;
  
  FUN_00617710();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006179c0 @ 0x006179c0 ====

int * FUN_006179c0(int param_1)

{
  int *in_ECX;
  
  if ((param_1 != 0) && (param_1 != 10)) {
    (**(code **)(*in_ECX + 0x20))(param_1);
  }
  return in_ECX + 2;
}


// ==== FUN_006179e0 @ 0x006179e0 ====

int FUN_006179e0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_006179f0 @ 0x006179f0 ====

void FUN_006179f0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x13c) = param_1;
  return;
}


// ==== FUN_00617a00 @ 0x00617a00 ====

int FUN_00617a00(void)

{
  int in_ECX;
  
  return in_ECX + 0x13c;
}


// ==== FUN_00617a10 @ 0x00617a10 ====

undefined4 FUN_00617a10(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  (**(code **)(*piVar1 + 0x1c))();
  (**(code **)(*piVar1 + 0x30))(param_1);
  return 1;
}


// ==== FUN_00617a40 @ 0x00617a40 ====

void FUN_00617a40(void)

{
  return;
}


// ==== FUN_00617a50 @ 0x00617a50 ====

int FUN_00617a50(void)

{
  int in_ECX;
  
  return in_ECX + 0x3c0;
}


// ==== FUN_00617a60 @ 0x00617a60 ====

void FUN_00617a60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009887c8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cccd0;
  local_4 = 0;
  FUN_0063cc50();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00617ab0 @ 0x00617ab0 ====

void FUN_00617ab0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009887e5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cccd0;
  FUN_0063cca0();
  local_4 = CONCAT31(local_4._1_3_,1);
  in_ECX[0x4f] = 0;
  FUN_00797a50(in_ECX + 0x50,0,0x280);
  FUN_00797a50(in_ECX + 0xf0,0,0x280);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00617b30 @ 0x00617b30 ====

void FUN_00617b30(byte param_1)

{
  void *in_ECX;
  
  FUN_00617a60();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00617b50 @ 0x00617b50 ====

void FUN_00617b50(void)

{
  return;
}


// ==== FUN_00617b60 @ 0x00617b60 ====

int FUN_00617b60(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00617b80 @ 0x00617b80 ====

void FUN_00617b80(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x13c) = param_1;
  return;
}


// ==== FUN_00617b90 @ 0x00617b90 ====

int FUN_00617b90(void)

{
  int in_ECX;
  
  return in_ECX + 0x13c;
}


// ==== FUN_00617ba0 @ 0x00617ba0 ====

undefined1 FUN_00617ba0(void)

{
  return 1;
}


// ==== FUN_00617bb0 @ 0x00617bb0 ====

int FUN_00617bb0(void)

{
  int in_ECX;
  
  return in_ECX + 0x140;
}


// ==== FUN_00617bc0 @ 0x00617bc0 ====

void FUN_00617bc0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009887f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cccfc;
  local_4 = 0;
  FUN_0063cc50();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00617c10 @ 0x00617c10 ====

void FUN_00617c10(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_0098880a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cccfc;
  FUN_0063cca0();
  in_ECX[0x4f] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00617c60 @ 0x00617c60 ====

void FUN_00617c60(byte param_1)

{
  void *in_ECX;
  
  FUN_00617bc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00617c80 @ 0x00617c80 ====

void FUN_00617c80(void)

{
  return;
}


// ==== FUN_00617c90 @ 0x00617c90 ====

int * FUN_00617c90(int param_1)

{
  int *in_ECX;
  
  if ((param_1 != 0) && (param_1 != 10)) {
    (**(code **)(*in_ECX + 0x20))(param_1);
  }
  return in_ECX + 2;
}


// ==== FUN_00617cb0 @ 0x00617cb0 ====

int FUN_00617cb0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00617cc0 @ 0x00617cc0 ====

void FUN_00617cc0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x13c) = param_1;
  return;
}


// ==== FUN_00617cd0 @ 0x00617cd0 ====

int FUN_00617cd0(void)

{
  int in_ECX;
  
  return in_ECX + 0x13c;
}


// ==== FUN_00617ce0 @ 0x00617ce0 ====

undefined4 FUN_00617ce0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  (**(code **)(*piVar1 + 0x1c))();
  (**(code **)(*piVar1 + 0x30))(param_1);
  return 1;
}


// ==== FUN_00617d10 @ 0x00617d10 ====

int FUN_00617d10(void)

{
  int in_ECX;
  
  return in_ECX + 0x3c0;
}


// ==== FUN_00617d20 @ 0x00617d20 ====

void FUN_00617d20(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988828;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccd28;
  local_4 = 0;
  FUN_0063cc50();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00617d70 @ 0x00617d70 ====

void FUN_00617d70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988845;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccd28;
  FUN_0063cca0();
  local_4 = CONCAT31(local_4._1_3_,1);
  in_ECX[0x4f] = 0;
  FUN_00797a50(in_ECX + 0x50,0,0x280);
  FUN_00797a50(in_ECX + 0xf0,0,0x280);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00617df0 @ 0x00617df0 ====

void FUN_00617df0(byte param_1)

{
  void *in_ECX;
  
  FUN_00617d20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00617e10 @ 0x00617e10 ====

void FUN_00617e10(void)

{
  return;
}


// ==== FUN_00617e20 @ 0x00617e20 ====

int * FUN_00617e20(int param_1)

{
  int *in_ECX;
  
  if ((param_1 != 0) && (param_1 != 10)) {
    (**(code **)(*in_ECX + 0x20))(param_1);
  }
  return in_ECX + 2;
}


// ==== FUN_00617e40 @ 0x00617e40 ====

int FUN_00617e40(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00617e50 @ 0x00617e50 ====

void FUN_00617e50(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x13c) = param_1;
  return;
}


// ==== FUN_00617e60 @ 0x00617e60 ====

int FUN_00617e60(void)

{
  int in_ECX;
  
  return in_ECX + 0x13c;
}


// ==== FUN_00617e70 @ 0x00617e70 ====

undefined4 FUN_00617e70(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  (**(code **)(*piVar1 + 0x1c))();
  (**(code **)(*piVar1 + 0x30))(param_1);
  return 1;
}


// ==== FUN_00617ea0 @ 0x00617ea0 ====

int FUN_00617ea0(void)

{
  int in_ECX;
  
  return in_ECX + 0x3c0;
}


// ==== FUN_00617ee0 @ 0x00617ee0 ====

void FUN_00617ee0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988858;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccd54;
  local_4 = 0;
  FUN_0063cc50();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00617f70 @ 0x00617f70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00617f70(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int in_ECX;
  int *piVar7;
  float fVar8;
  float fVar9;
  
  piVar6 = *(int **)(in_ECX + 4);
  piVar4 = (int *)(**(code **)(*piVar6 + 0x20))();
  iVar5 = (**(code **)(*piVar4 + 4))();
  iVar1 = *(int *)(iVar5 + 0x28);
  iVar2 = *(int *)(param_2 + 0x20);
  piVar7 = (int *)(in_ECX + 8);
  (**(code **)(*(int *)(in_ECX + 8) + 0x74))();
  (**(code **)(*piVar7 + 0x78))();
  fVar9 = (float)*(ushort *)(iVar5 + 0x2c) * (float)*(int *)(param_2 + 0x28);
  (**(code **)(*piVar7 + 0x7c))(fVar9);
  fVar3 = (float)*(int *)(param_2 + 0x30);
  (**(code **)(*piVar7 + 0x84))(fVar3);
  (**(code **)(*piVar7 + 0x88))(0);
  piVar6 = (int *)piVar6[0x11];
  piVar4 = (int *)(**(code **)(*piVar6 + 0x14))();
  (**(code **)(*piVar6 + 0x1c))(fVar3);
  iVar5 = (**(code **)(*piVar4 + 0xc))();
  if (0.0 < *(float *)(iVar5 + 4)) {
    piVar6 = (int *)(**(code **)(*piVar6 + 0x24))();
    fVar8 = (float)((int)fVar3 - *piVar6);
    if ((int)fVar3 - *piVar6 < 0) {
      fVar8 = fVar8 + _DAT_0099d104;
    }
    fVar8 = fVar8 * DAT_0099d0ec;
    iVar5 = (**(code **)(*piVar4 + 0xc))();
    fVar8 = (0.0 - (float)(iVar1 + iVar2)) * fVar8 + *(float *)(iVar5 + 4);
    if (fVar3 < fVar8) {
      fVar8 = fVar3;
    }
    if (fVar8 <= DAT_0099d080) {
      fVar8 = DAT_0099d080;
    }
    (**(code **)(*piVar7 + 0x6c))(fVar8);
    (**(code **)(*piVar7 + 0x70))(0);
    (**(code **)(*piVar7 + 0x8c))(0);
    (**(code **)(*piVar4 + 0x14))(fVar8);
    (**(code **)(*piVar4 + 0x20))(0);
    (**(code **)(*piVar4 + 0x1c))(fVar9);
    (**(code **)(*piVar4 + 0x28))(0);
    (**(code **)(*piVar4 + 0x2c))(0);
    (**(code **)(*piVar4 + 0x34))(0);
  }
  return;
}


// ==== FUN_00618200 @ 0x00618200 ====

void FUN_00618200(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988875;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccd54;
  FUN_0063cca0();
  local_4 = CONCAT31(local_4._1_3_,1);
  in_ECX[0x4f] = 0;
  FUN_00797a50(in_ECX + 0x50,0,0x280);
  FUN_00797a50(in_ECX + 0xf0,0,0x280);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00618280 @ 0x00618280 ====

void FUN_00618280(int param_1)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0xc);
  piVar1 = (int *)(in_ECX + 4);
  iVar2 = 0x20;
  do {
    piVar1[-1] = piVar1[-1] + piVar3[-3];
    *piVar1 = *piVar1 + *(int *)((param_1 - in_ECX) + (int)piVar1);
    piVar1[1] = piVar1[1] + piVar3[-1];
    piVar1[2] = piVar1[2] + *piVar3;
    piVar1[3] = piVar1[3] + piVar3[1];
    piVar1 = piVar1 + 5;
    piVar3 = piVar3 + 5;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}


// ==== FUN_006182c0 @ 0x006182c0 ====

void FUN_006182c0(byte param_1)

{
  void *in_ECX;
  
  FUN_00617ee0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_006182e0 @ 0x006182e0 ====

void FUN_006182e0(void)

{
  return;
}


// ==== FUN_006182f0 @ 0x006182f0 ====

int * FUN_006182f0(uint param_1)

{
  int *in_ECX;
  
  if (((param_1 != 0) && (param_1 != 10)) && ((uint)in_ECX[0x4f] < param_1)) {
    (**(code **)(*in_ECX + 0x20))(param_1);
  }
  return in_ECX + 2;
}


// ==== FUN_00618320 @ 0x00618320 ====

int FUN_00618320(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00618330 @ 0x00618330 ====

void FUN_00618330(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x13c) = param_1;
  return;
}


// ==== FUN_00618340 @ 0x00618340 ====

int FUN_00618340(void)

{
  int in_ECX;
  
  return in_ECX + 0x13c;
}


// ==== FUN_00618350 @ 0x00618350 ====

undefined4 FUN_00618350(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x14))(param_1);
  return 1;
}


// ==== FUN_00618370 @ 0x00618370 ====

int FUN_00618370(void)

{
  int in_ECX;
  
  return in_ECX + 0x3c0;
}


// ==== FUN_006183c0 @ 0x006183c0 ====

void FUN_006183c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988888;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccd80;
  local_4 = 0;
  FUN_0063cc50();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00618450 @ 0x00618450 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00618450(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int in_ECX;
  float unaff_EBX;
  float unaff_EDI;
  float fVar8;
  float fVar9;
  float fStack_24;
  
  piVar1 = *(int **)(in_ECX + 4);
  iVar3 = (**(code **)(*piVar1 + 0x20))();
  if (iVar3 == 0) {
    return;
  }
  piVar5 = *(int **)(iVar3 + 0x50);
  puVar4 = (uint *)(**(code **)(*piVar5 + 0x1c))();
  if (*puVar4 < param_1) {
    (**(code **)(*piVar5 + 0x20))(param_1);
  }
  (**(code **)(*piVar5 + 0x24))();
  piVar5 = (int *)(**(code **)(*piVar1 + 0x24))();
  (**(code **)(*DAT_00b5a6b8 + 4))();
  iVar6 = (**(code **)(*piVar5 + 4))();
  iVar3 = *(int *)(iVar6 + 0x30);
  iVar2 = *(int *)(param_2 + 0x20);
  piVar5 = (int *)(in_ECX + 8);
  (**(code **)(*(int *)(in_ECX + 8) + 0x74))();
  fStack_24 = 0.0;
  (**(code **)(*piVar5 + 0x78))();
  fVar8 = (float)*(ushort *)(iVar6 + 0x34) + (float)*(int *)(param_2 + 0x28) * DAT_009a09b8;
  if (*(int *)(iVar6 + 4) == 0) {
    iVar6 = *(int *)((int)unaff_EBX + 0x1a8);
  }
  else {
    if (*(int *)(iVar6 + 4) != 1) goto LAB_00618539;
    iVar6 = *(int *)((int)unaff_EBX + 0x208);
  }
  fVar8 = (float)iVar6 * DAT_009a09b8 + fVar8;
LAB_00618539:
  (**(code **)(*piVar5 + 0x7c))(fVar8);
  (**(code **)(*piVar5 + 0x84))((float)*(int *)(param_2 + 0x30) * DAT_009a09b8);
  (**(code **)(*piVar5 + 0x88))(0);
  piVar1 = (int *)piVar1[0x11];
  piVar7 = (int *)(**(code **)(*piVar1 + 0x14))();
  (**(code **)(*piVar1 + 0x24))();
  (**(code **)(*piVar1 + 0x1c))(unaff_EBX);
  iVar6 = (**(code **)(*piVar7 + 0xc))();
  if (0.0 < *(float *)(iVar6 + 4)) {
    iVar6 = (**(code **)(*piVar7 + 0xc))();
    fVar9 = (float)(int)unaff_EBX;
    if ((int)unaff_EBX < 0) {
      fVar9 = fVar9 + _DAT_0099d104;
    }
    fVar9 = (fVar9 - unaff_EDI) * DAT_0099d0ec * (unaff_EBX - (float)(iVar3 + iVar2)) +
            *(float *)(iVar6 + 4);
    if (fVar9 <= 0.0) {
      fStack_24 = fVar9;
    }
    if (fStack_24 <= DAT_0099d080) {
      fStack_24 = DAT_0099d080;
    }
    fVar9 = fStack_24;
    (**(code **)(*piVar5 + 0x6c))(fStack_24);
    (**(code **)(*piVar5 + 0x70))(0);
    (**(code **)(*piVar5 + 0x8c))(0);
    (**(code **)(*piVar7 + 0x14))(fStack_24);
    (**(code **)(*piVar7 + 0x20))(0);
    (**(code **)(*piVar7 + 0x1c))(fVar9);
    (**(code **)(*piVar7 + 0x18))(fVar8);
    (**(code **)(*piVar7 + 0x28))(0);
    (**(code **)(*piVar7 + 0x2c))(0);
    (**(code **)(*piVar7 + 0x34))(0);
  }
  return;
}


// ==== FUN_006187a0 @ 0x006187a0 ====

void FUN_006187a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009888a5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccd80;
  FUN_0063cca0();
  local_4 = CONCAT31(local_4._1_3_,1);
  in_ECX[0x4f] = 0;
  FUN_00797a50(in_ECX + 0x50,0,0x280);
  FUN_00797a50(in_ECX + 0xf0,0,0x280);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00618820 @ 0x00618820 ====

void FUN_00618820(byte param_1)

{
  void *in_ECX;
  
  FUN_006183c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00618840 @ 0x00618840 ====

void FUN_00618840(void)

{
  return;
}


// ==== FUN_00618850 @ 0x00618850 ====

int FUN_00618850(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00618870 @ 0x00618870 ====

void FUN_00618870(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x13c) = param_1;
  return;
}


// ==== FUN_00618880 @ 0x00618880 ====

int FUN_00618880(void)

{
  int in_ECX;
  
  return in_ECX + 0x13c;
}


// ==== FUN_00618890 @ 0x00618890 ====

undefined1 FUN_00618890(void)

{
  return 1;
}


// ==== FUN_006188a0 @ 0x006188a0 ====

int FUN_006188a0(void)

{
  int in_ECX;
  
  return in_ECX + 0x140;
}


// ==== FUN_006188b0 @ 0x006188b0 ====

void FUN_006188b0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009888b8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccdac;
  local_4 = 0;
  FUN_0063cc50();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00618900 @ 0x00618900 ====

void FUN_00618900(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009888ca;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccdac;
  FUN_0063cca0();
  in_ECX[0x4f] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00618950 @ 0x00618950 ====

void FUN_00618950(byte param_1)

{
  void *in_ECX;
  
  FUN_006188b0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00618970 @ 0x00618970 ====

void FUN_00618970(void)

{
  return;
}


// ==== FUN_00618980 @ 0x00618980 ====

int * FUN_00618980(int param_1)

{
  int *in_ECX;
  
  if ((param_1 != 0) && (param_1 != 10)) {
    (**(code **)(*in_ECX + 0x20))(param_1);
  }
  return in_ECX + 2;
}


// ==== FUN_006189a0 @ 0x006189a0 ====

int FUN_006189a0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_006189b0 @ 0x006189b0 ====

void FUN_006189b0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x13c) = param_1;
  return;
}


// ==== FUN_006189c0 @ 0x006189c0 ====

int FUN_006189c0(void)

{
  int in_ECX;
  
  return in_ECX + 0x13c;
}


// ==== FUN_006189d0 @ 0x006189d0 ====

undefined4 FUN_006189d0(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))();
  (**(code **)(*piVar1 + 0x1c))();
  (**(code **)(*piVar1 + 0x30))(param_1);
  return 1;
}


// ==== FUN_00618a00 @ 0x00618a00 ====

int FUN_00618a00(void)

{
  int in_ECX;
  
  return in_ECX + 0x3c0;
}


// ==== FUN_00618a50 @ 0x00618a50 ====

void FUN_00618a50(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009888e8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccdd8;
  local_4 = 0;
  FUN_0063cc50();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00618be0 @ 0x00618be0 ====

void FUN_00618be0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988905;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccdd8;
  FUN_0063cca0();
  local_4 = CONCAT31(local_4._1_3_,1);
  in_ECX[0x4f] = 0;
  FUN_00797a50(in_ECX + 0x50,0,0x280);
  FUN_00797a50(in_ECX + 0xf0,0,0x280);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00618c60 @ 0x00618c60 ====

undefined4 FUN_00618c60(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int **)(param_1 + 0x4c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x4c) + 0x18))();
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if ((iVar2 == 8) || (iVar2 == 9)) {
    return 1;
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    if (*(int **)(param_1 + 0x44) == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x44) + 0x18))();
    }
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (*(float *)(iVar2 + 4) == DAT_0099cdc8) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00618cd0 @ 0x00618cd0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00618cd0(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  float fVar5;
  int *piVar6;
  int *piVar7;
  int in_ECX;
  float unaff_ESI;
  int *piVar8;
  float unaff_EDI;
  int unaff_retaddr;
  float fVar9;
  undefined4 uVar10;
  float fStack_8;
  
  iVar2 = (**(code **)(*DAT_00b5a6b8 + 4))();
  piVar7 = *(int **)(in_ECX + 4);
  piVar3 = (int *)(**(code **)(*piVar7 + 0x20))();
  iVar4 = (**(code **)(*piVar3 + 4))();
  fVar5 = (float)(*(int *)(iVar4 + 0x50) + *(int *)(param_2 + 0x20));
  piVar8 = (int *)(in_ECX + 8);
  fVar9 = (float)(int)fVar5 * *(float *)(iVar2 + 0x58);
  (**(code **)(*(int *)(in_ECX + 8) + 0x74))(fVar9);
  uVar10 = 0;
  (**(code **)(*piVar8 + 0x78))(0);
  (**(code **)(*piVar8 + 0x7c))
            (((float)*(int *)(unaff_retaddr + 0x28) * DAT_009a09b8 +
             (float)*(ushort *)(iVar4 + 0x54)) * *(float *)(iVar2 + 0x5c));
  (**(code **)(*piVar8 + 0x84))
            ((float)*(int *)(unaff_retaddr + 0x30) * DAT_009a09b8 * *(float *)(iVar2 + 0x60));
  piVar3 = (int *)piVar7[0x11];
  piVar6 = (int *)(**(code **)(*piVar3 + 0x14))();
  cVar1 = FUN_00618c60(piVar7);
  if (cVar1 == '\x01') {
    uVar10 = 0;
    (**(code **)(*piVar8 + 0x6c))(0);
    (**(code **)(*piVar8 + 0x70))(0);
    (**(code **)(*piVar8 + 0x8c))(0);
    (**(code **)(*piVar6 + 0x14))(0);
    (**(code **)(*piVar6 + 0x18))(0);
    (**(code **)(*piVar6 + 0x20))(0);
    (**(code **)(*piVar6 + 0x24))(0);
    (**(code **)(*piVar6 + 0x2c))(0);
    (**(code **)(*piVar6 + 0x30))(0);
    (**(code **)(*piVar6 + 0x40))(0,uVar10);
    (**(code **)(*piVar6 + 0x44))(0,uVar10);
    return;
  }
  piVar7 = (int *)(**(code **)(*piVar3 + 0x24))();
  iVar2 = 0;
  if (*piVar7 + 500U < (uint)fVar9) {
    iVar2 = (int)fVar9 - *piVar7;
    (**(code **)(*piVar3 + 0x1c))(fVar9);
  }
  iVar4 = (**(code **)(*piVar6 + 0xc))();
  fVar9 = (float)iVar2;
  if (iVar2 < 0) {
    fVar9 = fVar9 + _DAT_0099d104;
  }
  fVar9 = fVar9 * DAT_0099d0ec * (fVar5 - unaff_ESI) + *(float *)(iVar4 + 4);
  fStack_8 = unaff_EDI;
  if (fVar9 <= unaff_EDI) {
    fStack_8 = fVar9;
  }
  if (fStack_8 <= DAT_0099d080) {
    fStack_8 = DAT_0099d080;
  }
  fVar9 = fStack_8;
  (**(code **)(*piVar8 + 0x6c))(fStack_8);
  (**(code **)(*piVar8 + 0x70))(0);
  (**(code **)(*piVar8 + 0x8c))(0);
  (**(code **)(*piVar6 + 0x14))(fStack_8);
  (**(code **)(*piVar6 + 0x20))(0);
  (**(code **)(*piVar6 + 0x1c))(fVar9);
  (**(code **)(*piVar6 + 0x18))(uVar10);
  (**(code **)(*piVar6 + 0x28))(0);
  (**(code **)(*piVar6 + 0x24))(0);
  (**(code **)(*piVar6 + 0x2c))(0);
  (**(code **)(*piVar6 + 0x30))(0);
  return;
}


// ==== FUN_00618f20 @ 0x00618f20 ====

void FUN_00618f20(byte param_1)

{
  void *in_ECX;
  
  FUN_00618a50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00618f40 @ 0x00618f40 ====

void FUN_00618f40(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x13c) = 0;
  FUN_00797a50(in_ECX + 0x140,0,0x280);
  FUN_00797a50(in_ECX + 0x3c0,0,0x280);
  return;
}


// ==== FUN_00618f80 @ 0x00618f80 ====

int * FUN_00618f80(int param_1)

{
  int *in_ECX;
  
  if ((param_1 != 0) && (param_1 != 10)) {
    (**(code **)(*in_ECX + 0x20))(param_1);
  }
  return in_ECX + 2;
}


// ==== FUN_00618fa0 @ 0x00618fa0 ====

int FUN_00618fa0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00618fb0 @ 0x00618fb0 ====

void FUN_00618fb0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x13c) = param_1;
  return;
}


// ==== FUN_00618fc0 @ 0x00618fc0 ====

int FUN_00618fc0(void)

{
  int in_ECX;
  
  return in_ECX + 0x13c;
}


// ==== FUN_00618fd0 @ 0x00618fd0 ====

undefined4 FUN_00618fd0(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 4) + 0x14))(param_1);
  return 1;
}


// ==== FUN_00618ff0 @ 0x00618ff0 ====

int FUN_00618ff0(void)

{
  int in_ECX;
  
  return in_ECX + 0x3c0;
}


// ==== FUN_00619040 @ 0x00619040 ====

void FUN_00619040(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988918;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cce04;
  local_4 = 0;
  FUN_0063cc50();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00619190 @ 0x00619190 ====

void FUN_00619190(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988935;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cce04;
  FUN_0063cca0();
  local_4 = CONCAT31(local_4._1_3_,1);
  in_ECX[0x4f] = 0;
  FUN_00797a50(in_ECX + 0x50,0,0x280);
  FUN_00797a50(in_ECX + 0xf0,0,0x280);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00619210 @ 0x00619210 ====

void FUN_00619210(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  short *psVar4;
  int iVar5;
  int in_ECX;
  
  FUN_00797a50(param_2,0,0x280);
  iVar5 = *(int *)(in_ECX + 4);
  (**(code **)(*DAT_00b5a6b8 + 4))();
  iVar2 = in_ECX + 0x140;
  (**(code **)(**(int **)(iVar5 + 0x40) + 0x18))(iVar2);
  FUN_00618280(iVar2);
  (**(code **)(**(int **)(iVar5 + 0x10) + 0x30))(iVar2);
  FUN_00618280(iVar2);
  (**(code **)(**(int **)(iVar5 + 0x24) + 0x54))(iVar2);
  FUN_00618280(iVar2);
  piVar3 = (int *)0x0;
  if (*(int **)(iVar5 + 0xc) != (int *)0x0) {
    piVar3 = (int *)(**(code **)(**(int **)(iVar5 + 0xc) + 0x28))();
  }
  piVar1 = (int *)(in_ECX + 8);
  psVar4 = (short *)(**(code **)(*piVar3 + 0xc))();
  (**(code **)(*piVar1 + 0x5c))(*(short *)(param_2 + 4) + *psVar4);
  iVar2 = *piVar1;
  iVar5 = (**(code **)(*piVar3 + 0xc))();
  (**(code **)(iVar2 + 0x60))(*(short *)(iVar5 + 2) + *(short *)(param_2 + 8));
  iVar2 = *piVar1;
  iVar5 = (**(code **)(*piVar3 + 0xc))();
  (**(code **)(iVar2 + 100))(*(short *)(iVar5 + 4) + *(short *)(param_2 + 0xc));
  iVar2 = *piVar1;
  iVar5 = (**(code **)(*piVar3 + 0xc))();
  (**(code **)(iVar2 + 0x68))(*(short *)(iVar5 + 6) + *(short *)(param_2 + 0x10));
  return;
}


// ==== FUN_006192f0 @ 0x006192f0 ====

void FUN_006192f0(uint param_1)

{
  uint uVar1;
  short sVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int in_ECX;
  undefined2 extraout_var;
  int *piVar7;
  
  piVar4 = *(int **)(in_ECX + 4);
  piVar7 = (int *)piVar4[0x1f];
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)(**(code **)(*piVar7 + 0x14))();
  }
  uVar3 = (**(code **)(*piVar7 + 0x34))();
  if (uVar3 < param_1) {
    sVar2 = (**(code **)(*piVar7 + 0x20))();
    if (sVar2 == 0) {
      (**(code **)(*piVar7 + 0x30))(param_1);
      return;
    }
    piVar4 = (int *)(**(code **)(*piVar4 + 8))();
    piVar4 = (int *)(**(code **)(*piVar4 + 0x2c))();
    iVar5 = (**(code **)(*piVar4 + 0x10))();
    uVar1 = *(uint *)(iVar5 + 0x95c);
    iVar5 = (**(code **)(*piVar4 + 0x10))();
    if (uVar1 <= param_1 - uVar3) {
      uVar6 = (param_1 - uVar3) / uVar1;
      (**(code **)(*piVar7 + 0x2c))(uVar6 * CONCAT22(extraout_var,*(undefined2 *)(iVar5 + 0x95a)));
      (**(code **)(*piVar7 + 0x30))((uVar6 & 0xffff) * uVar1 + uVar3);
    }
  }
  return;
}


// ==== FUN_006193a0 @ 0x006193a0 ====

undefined4 FUN_006193a0(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int **)(param_1 + 0x4c) == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x4c) + 0x18))();
  }
  iVar2 = (**(code **)(*piVar1 + 0xc))();
  if ((iVar2 == 8) || (iVar2 == 9)) {
    return 1;
  }
  if (*(int *)(param_1 + 0x44) != 0) {
    if (*(int **)(param_1 + 0x44) == (int *)0x0) {
      piVar1 = (int *)0x0;
    }
    else {
      piVar1 = (int *)(**(code **)(**(int **)(param_1 + 0x44) + 0x18))();
    }
    iVar2 = (**(code **)(*piVar1 + 0xc))();
    if (*(float *)(iVar2 + 4) == DAT_0099cdc8) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_00619450 @ 0x00619450 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00619450(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  char cVar7;
  undefined1 *puVar8;
  int *piVar9;
  int iVar10;
  ushort *puVar11;
  int iVar12;
  int in_ECX;
  int *piVar13;
  undefined4 unaff_EBP;
  int *piVar14;
  float unaff_ESI;
  int *piVar15;
  float unaff_EDI;
  int *piVar16;
  int *piVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fStack_38;
  int *piStack_34;
  int iStack_2c;
  int iStack_20;
  int *local_1c;
  
  fVar18 = *(float *)(in_ECX + 4);
  (**(code **)(*DAT_00b5a6b8 + 4))();
  if (*(int **)((int)fVar18 + 0x48) == (int *)0x0) {
    piVar15 = (int *)0x0;
  }
  else {
    piVar15 = (int *)(**(code **)(**(int **)((int)fVar18 + 0x48) + 0x28))();
  }
  if (*(int **)((int)fVar18 + 0xc) == (int *)0x0) {
    piVar13 = (int *)0x0;
  }
  else {
    piVar13 = (int *)(**(code **)(**(int **)((int)fVar18 + 0xc) + 0x28))();
  }
  if (*(int **)((int)fVar18 + 4) == (int *)0x0) {
    piVar14 = (int *)0x0;
  }
  else {
    piVar14 = (int *)(**(code **)(**(int **)((int)fVar18 + 4) + 0x18))();
  }
  puVar8 = (undefined1 *)(**(code **)(*piVar14 + 8))();
  piVar9 = (int *)(**(code **)(*DAT_00b5abac + 0x10))(*puVar8);
  iVar10 = (**(code **)(*piVar9 + 4))();
  if (*(int **)(iStack_20 + 0x44) == (int *)0x0) {
    piStack_34 = (int *)0x0;
  }
  else {
    piStack_34 = (int *)(**(code **)(**(int **)(iStack_20 + 0x44) + 0x18))();
  }
  puVar11 = (ushort *)(**(code **)(*piVar15 + 8))();
  uVar4 = *puVar11;
  fVar1 = *(float *)(iVar10 + 0x6c);
  (**(code **)(*piVar15 + 8))();
  iVar12 = (**(code **)(*piVar13 + 0xc))();
  uVar5 = *(ushort *)(iVar12 + 4);
  fVar2 = *(float *)(iVar10 + 0x74);
  iVar12 = (**(code **)(*piVar13 + 0xc))();
  uVar6 = *(ushort *)(iVar12 + 6);
  fVar3 = *(float *)(iVar10 + 0x78);
  piVar16 = (int *)(((float)*(int *)(iVar10 + 0x44) + (float)uVar4 * fVar1 + (float)uVar5 * fVar2) *
                    ((float)*(int *)(param_1 + 0x24) * DAT_009a09b8 + (float)DAT_0099d080) +
                   (float)*(int *)(param_1 + 0x20));
  piVar9 = (int *)(iStack_2c + 8);
  (**(code **)(*(int *)(iStack_2c + 8) + 0x74))();
  (**(code **)(*piVar9 + 0x78))
            (((float)*(int *)(iVar10 + 0x48) + (float)uVar6 * fVar3 + fVar18) *
             ((float)*(int *)(param_1 + 0x44) * DAT_009a09b8 + (float)DAT_0099d080) +
             (float)*(int *)(param_1 + 0x40));
  piVar15 = (int *)(**(code **)(*piVar14 + 0x10))();
  iVar12 = (**(code **)(*piVar15 + 4))();
  (**(code **)(*piVar9 + 0x7c))
            ((float)*(int *)(param_1 + 0x28) * DAT_009a09b8 + *(float *)(iVar12 + 0x4c));
  piVar15 = (int *)(**(code **)(*piVar14 + 0x10))();
  iVar12 = (**(code **)(*piVar15 + 4))();
  piVar17 = (int *)((float)*(int *)(param_1 + 0x48) * DAT_009a09b8 + *(float *)(iVar12 + 0x50));
  (**(code **)(*piVar9 + 0x80))();
  fVar20 = (float)*(int *)(param_1 + 0x30) * DAT_009a09b8;
  (**(code **)(*piVar9 + 0x84))(fVar20);
  fVar19 = (float)*(int *)(param_1 + 0x50) * DAT_009a09b8;
  (**(code **)(*piVar9 + 0x88))(fVar19);
  puVar11 = (ushort *)(**(code **)(*piVar16 + 8))();
  uVar4 = *puVar11;
  iVar12 = (**(code **)(*piVar9 + 8))();
  iVar12 = *(int *)(iVar12 + 0xbc);
  fVar18 = *(float *)(iVar10 + 0xb8);
  fVar1 = *(float *)(iVar10 + 0xbc);
  fVar2 = *(float *)(iVar10 + 0xb4);
  fVar3 = *(float *)(iVar10 + 0xb0);
  piVar15 = (int *)(**(code **)(*piVar14 + 0x10))();
  iVar10 = (**(code **)(*piVar15 + 4))();
  fVar21 = *(float *)(iVar10 + 0x54);
  piVar15 = (int *)(**(code **)(*piVar14 + 0x10))();
  iVar10 = (**(code **)(*piVar15 + 4))();
  piVar14 = (int *)((float)*(int *)(param_1 + 0x188) * DAT_009a09b8 +
                   *(float *)(iVar10 + 0x58) * (float)uVar4 + fVar21);
  (**(code **)(*piVar9 + 0x94))(piVar14);
  piVar15 = (int *)((float)*(int *)(param_1 + 400) * DAT_009a09b8);
  (**(code **)(*piVar9 + 0x98))(piVar15);
  fVar21 = 0.0;
  piVar13 = (int *)(**(code **)(*piVar15 + 0x24))();
  if ((int *)(*piVar13 + 500) < piVar17) {
    piVar13 = (int *)(**(code **)(*piVar15 + 0x24))();
    fVar21 = (float)((int)piVar17 - *piVar13);
    if ((int)piVar17 - *piVar13 < 0) {
      fVar21 = fVar21 + _DAT_0099d104;
    }
    fVar21 = fVar21 * DAT_0099d0ec;
    (**(code **)(*piVar15 + 0x1c))(piVar17);
  }
  cVar7 = FUN_006193a0(unaff_EBP);
  if (cVar7 == '\x01') {
    (**(code **)(*piVar9 + 0x6c))(0);
    (**(code **)(*piVar9 + 0x70))(0);
    local_1c = (int *)0x0;
    (**(code **)(*piVar17 + 0x14))(0);
    fVar18 = 0.0;
    (**(code **)(*piVar17 + 0x18))(0);
    (**(code **)(*piVar17 + 0x20))(0);
    (**(code **)(*piVar17 + 0x24))(0);
    (**(code **)(*piVar17 + 0x40))(0,piVar17);
    (**(code **)(*piVar9 + 0x8c))(0);
    (**(code **)(*piVar17 + 0x44))(0,piVar17);
  }
  else {
    piVar15 = (int *)((float)piStack_34 - (float)piVar16);
    iVar10 = (**(code **)(*piVar14 + 0xc))();
    local_1c = (int *)((((float)iVar12 * fVar18 + fVar1 * (float)uVar4 + fVar2 * unaff_EDI) * fVar3
                       - fStack_38) * fVar21 + *(float *)(iVar10 + 4));
    (**(code **)(*piVar14 + 0xc))();
    if ((float)piVar16 < (float)local_1c) {
      local_1c = piVar16;
    }
    if ((float)local_1c <= (float)DAT_0099d080) {
      local_1c = DAT_0099d080;
    }
    piVar13 = local_1c;
    (**(code **)(*piVar9 + 0x6c))();
    (**(code **)(*piVar9 + 0x70))();
    (**(code **)(*piVar14 + 0x14))(local_1c);
    fVar18 = unaff_ESI;
    (**(code **)(*piVar14 + 0x18))(unaff_ESI);
    (**(code **)(*piVar14 + 0x20))();
    (**(code **)(*piVar14 + 0x24))(unaff_ESI);
    iVar10 = (**(code **)(*piVar14 + 0xc))();
    piStack_34 = (int *)((fVar19 - unaff_ESI) * (float)piVar13 + *(float *)(iVar10 + 0x2c));
    if ((float)piVar17 < (float)piStack_34) {
      piStack_34 = piVar17;
    }
    if ((float)piStack_34 <= (float)DAT_009a09bc) {
      piStack_34 = DAT_009a09bc;
    }
    iVar10 = (**(code **)(*piVar14 + 0xc))();
    iVar10 = *(int *)(iVar10 + 0x34);
    iVar12 = (**(code **)(*piVar14 + 0xc))();
    if (*(char *)(iVar12 + 0x38) == '\x01') {
      if (piVar17 < (int *)(iVar10 + 60000)) {
        piStack_34 = (int *)0x0;
      }
      else {
        (**(code **)(*piVar14 + 0x3c))(0);
      }
    }
    (**(code **)(*piVar9 + 0x8c))(piStack_34);
    (**(code **)(*piVar9 + 0x90))(fVar20);
    (**(code **)(*piVar14 + 0x2c))(piStack_34);
    (**(code **)(*piVar14 + 0x30))(unaff_ESI);
    FUN_006192f0(piVar17);
    piVar17 = piVar15;
  }
  (**(code **)(*piVar17 + 0x1c))(fVar18);
  (**(code **)(*piVar17 + 0x28))(local_1c);
  (**(code **)(*piVar17 + 0x34))(local_1c);
  return;
}


// ==== FUN_00619a20 @ 0x00619a20 ====

void FUN_00619a20(byte param_1)

{
  void *in_ECX;
  
  FUN_00619040();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00619a40 @ 0x00619a40 ====

void FUN_00619a40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988948;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cce30;
  local_4 = 0;
  FUN_0063cf80();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00619a90 @ 0x00619a90 ====

int FUN_00619a90(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00619aa0 @ 0x00619aa0 ====

void FUN_00619aa0(void)

{
  return;
}


// ==== FUN_00619ab0 @ 0x00619ab0 ====

void FUN_00619ab0(undefined2 param_1)

{
  int in_ECX;
  
  *(undefined2 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_00619ac0 @ 0x00619ac0 ====

void FUN_00619ac0(short param_1)

{
  int in_ECX;
  
  *(short *)(in_ECX + 8) = *(short *)(in_ECX + 8) + param_1;
  return;
}


// ==== FUN_00619ad0 @ 0x00619ad0 ====

uint FUN_00619ad0(int param_1)

{
  undefined4 in_EAX;
  uint uVar1;
  int in_ECX;
  
  uVar1 = CONCAT22((short)((uint)in_EAX >> 0x10),*(ushort *)(in_ECX + 8));
  if (*(ushort *)(in_ECX + 8) < (ushort)param_1) {
    return uVar1 & 0xffffff00;
  }
  param_1 = uVar1 - param_1;
  *(short *)(in_ECX + 8) = (short)param_1;
  return CONCAT31((int3)((uint)param_1 >> 8),1);
}


// ==== FUN_00619af0 @ 0x00619af0 ====

int FUN_00619af0(void)

{
  int in_ECX;
  
  FUN_0063d090(*(undefined4 *)(in_ECX + 4));
  return in_ECX + 0xc;
}


// ==== FUN_00619b10 @ 0x00619b10 ====

int FUN_00619b10(void)

{
  int in_ECX;
  
  FUN_0063d090(*(undefined4 *)(in_ECX + 4));
  return in_ECX + 0xc;
}


// ==== FUN_00619b30 @ 0x00619b30 ====

void FUN_00619b30(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988965;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cce30;
  FUN_0063d0d0();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00797a50(in_ECX + 2,0,2);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00619b90 @ 0x00619b90 ====

void FUN_00619b90(byte param_1)

{
  void *in_ECX;
  
  FUN_00619a40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00619bb0 @ 0x00619bb0 ====

void FUN_00619bb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988978;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cceb4;
  local_4 = 0;
  FUN_0063d150();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00619c00 @ 0x00619c00 ====

int FUN_00619c00(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00619c10 @ 0x00619c10 ====

void FUN_00619c10(void)

{
  return;
}


// ==== FUN_00619c20 @ 0x00619c20 ====

void FUN_00619c20(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = *param_1;
  return;
}


// ==== FUN_00619c30 @ 0x00619c30 ====

int FUN_00619c30(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_00619c40 @ 0x00619c40 ====

int FUN_00619c40(void)

{
  int in_ECX;
  
  return in_ECX + 0xc;
}


// ==== FUN_00619c60 @ 0x00619c60 ====

void FUN_00619c60(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988995;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cceb4;
  FUN_0063d180();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00797a50(in_ECX + 2,0,4);
  ExceptionList = local_c;
  return;
}


// ==== FUN_00619cc0 @ 0x00619cc0 ====

bool FUN_00619cc0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined2 *puVar4;
  undefined1 *puVar5;
  int *in_ECX;
  undefined4 unaff_EBX;
  int *piVar6;
  int *piVar7;
  byte bVar8;
  
  bVar8 = (byte)((uint)unaff_EBX >> 0x18);
  iVar2 = FUN_00803725(in_ECX[1],0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (iVar2 == 0) {
    return false;
  }
  if (*(int **)(iVar2 + 4) == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = (int *)(**(code **)(**(int **)(iVar2 + 4) + 0x18))();
  }
  if (*(int **)(iVar2 + 0x48) == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    piVar7 = (int *)(**(code **)(**(int **)(iVar2 + 0x48) + 0x28))();
  }
  (**(code **)(in_ECX[3] + 8))();
  piVar1 = DAT_00b5aba8;
  puVar3 = (undefined4 *)(**(code **)(*in_ECX + 0x14))();
  puVar4 = (undefined2 *)(**(code **)(*piVar7 + 8))();
  puVar5 = (undefined1 *)(**(code **)(*piVar6 + 8))();
  iVar2 = (**(code **)(*piVar1 + 0x1c))
                    (*puVar5,CONCAT22((short)((uint)*puVar3 >> 0x10),*puVar4),*puVar3);
  return bVar8 < *(byte *)(iVar2 + 1);
}


// ==== FUN_00619d70 @ 0x00619d70 ====

int FUN_00619d70(void)

{
  byte bVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  undefined1 *puVar7;
  int *in_ECX;
  int *piVar8;
  int *local_4;
  
  piVar8 = (int *)0x0;
  iVar3 = FUN_00803725(in_ECX[1],0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (*(int **)(iVar3 + 4) == (int *)0x0) {
    local_4 = (int *)0x0;
  }
  else {
    local_4 = (int *)(**(code **)(**(int **)(iVar3 + 4) + 0x18))();
  }
  if (*(int **)(iVar3 + 0x48) != (int *)0x0) {
    piVar8 = (int *)(**(code **)(**(int **)(iVar3 + 0x48) + 0x28))();
  }
  pbVar4 = (byte *)(**(code **)(in_ECX[3] + 8))();
  piVar2 = DAT_00b5aba8;
  bVar1 = *pbVar4;
  puVar5 = (undefined4 *)(**(code **)(*in_ECX + 0x14))();
  puVar6 = (undefined2 *)(**(code **)(*piVar8 + 8))();
  puVar7 = (undefined1 *)(**(code **)(*local_4 + 8))();
  iVar3 = (**(code **)(*piVar2 + 0x1c))
                    (*puVar7,CONCAT22((short)((uint)*puVar5 >> 0x10),*puVar6),*puVar5);
  if (bVar1 < *(byte *)(iVar3 + 1)) {
    return (uint)*(byte *)(iVar3 + 1) - (uint)bVar1;
  }
  return 0;
}


// ==== FUN_00619e20 @ 0x00619e20 ====

uint FUN_00619e20(int *param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  iVar1 = *param_1;
  if (*(uint *)(in_ECX + 8) < -iVar1 - 1U) {
    *(uint *)(in_ECX + 8) = *(uint *)(in_ECX + 8) + iVar1;
    return CONCAT31((int3)((uint)iVar1 >> 8),1);
  }
  *(undefined4 *)(in_ECX + 8) = 0xffffffff;
  FUN_0044a580(local_100,&DAT_009cceac,s_____WARNING_____AdvPoint_Overflo_009cce60);
  uVar2 = FUN_00797b80(local_100);
  return uVar2 & 0xffffff00;
}


// ==== FUN_00619e80 @ 0x00619e80 ====

uint FUN_00619e80(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (*(uint *)(in_ECX + 8) < *param_1) {
    *(undefined4 *)(in_ECX + 8) = 0;
    FUN_0044a580(local_100,&DAT_009cceac,s_____WARNING_____AdvPoint_Underfl_009cce84);
    uVar1 = FUN_00797b80(local_100);
    return uVar1 & 0xffffff00;
  }
  iVar2 = *(uint *)(in_ECX + 8) - *param_1;
  *(int *)(in_ECX + 8) = iVar2;
  return CONCAT31((int3)((uint)iVar2 >> 8),1);
}


// ==== FUN_00619ee0 @ 0x00619ee0 ====

void FUN_00619ee0(byte param_1)

{
  void *in_ECX;
  
  FUN_00619bb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_00619f00 @ 0x00619f00 ====

void FUN_00619f00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009889a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccfa4;
  local_4 = 0;
  FUN_0063d2c0();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_00619f50 @ 0x00619f50 ====

void FUN_00619f50(void)

{
  return;
}


// ==== FUN_00619f60 @ 0x00619f60 ====

int FUN_00619f60(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_00619f70 @ 0x00619f70 ====

uint FUN_00619f70(int param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(uint *)(param_1 + 8);
    if (((((int3)(uVar1 >> 8) == 4) && (uVar1 != 0x40e)) && (uVar1 != 0x40f)) && (uVar1 != 0x410)) {
      return 0x401;
    }
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_00619fe0 @ 0x00619fe0 ====

undefined4 FUN_00619fe0(int param_1)

{
  uint uVar1;
  
  if ((((param_1 != 0) && (uVar1 = *(uint *)(param_1 + 8), uVar1 >> 8 == 4)) && (uVar1 != 0x40e)) &&
     (uVar1 != 0x40f)) {
    switch(uVar1) {
    case 0x400:
      return 2;
    case 0x401:
    case 0x406:
    case 0x408:
      return 3;
    case 0x402:
    case 0x403:
    case 0x407:
    case 0x409:
    case 0x411:
      return 4;
    case 0x404:
      return 5;
    case 0x405:
      return 6;
    case 0x40a:
      return 7;
    case 0x40b:
      return 8;
    case 0x40c:
      return 9;
    case 0x40d:
      return 0xb;
    case 0x412:
      return 0x16;
    case 0x413:
      return 0x17;
    case 0x414:
      return 0x18;
    }
  }
  return 1;
}


// ==== FUN_0061a0f0 @ 0x0061a0f0 ====

void FUN_0061a0f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009889ba;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccfa4;
  FUN_0063d330();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061a140 @ 0x0061a140 ====

undefined4 FUN_0061a140(int *param_1,int *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    return 1;
  }
  iVar5 = *DAT_00b5a738;
  uVar2 = (**(code **)(*param_1 + 0x1c))();
  piVar3 = (int *)(**(code **)(iVar5 + 0x10))(uVar2);
  iVar5 = *DAT_00b5a738;
  uVar2 = (**(code **)(*param_2 + 0x1c))();
  piVar4 = (int *)(**(code **)(iVar5 + 0x10))(uVar2);
  if ((piVar3 != (int *)0x0) && (piVar4 != (int *)0x0)) {
    iVar5 = (**(code **)(*piVar3 + 4))();
    iVar6 = (**(code **)(*piVar4 + 4))();
    cVar1 = FUN_00619f70(iVar5 + 4);
    if ((cVar1 != '\0') && (cVar1 = FUN_00619f70(iVar6 + 4), cVar1 != '\0')) {
      iVar5 = FUN_00619fe0(iVar5 + 4);
      if ((iVar5 == 3) && (iVar5 = FUN_00619fe0(iVar6 + 4), iVar5 == 3)) {
        return 1;
      }
      return 0;
    }
  }
  return 1;
}


// ==== FUN_0061a200 @ 0x0061a200 ====

undefined4 FUN_0061a200(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_100 [256];
  
  uVar3 = 4;
  if ((((param_1 == 0) || (*(int *)(param_1 + 8) == 0x40f)) || (*(int *)(param_1 + 8) == 0x410)) ||
     (*(int *)(param_1 + 4) != 4)) {
    if (param_2 == 0) {
      return 1;
    }
    if (*(int *)(param_2 + 8) == 0x40f) {
      return 1;
    }
    if (*(int *)(param_2 + 8) == 0x410) {
      return 1;
    }
    if (*(int *)(param_2 + 4) != 4) {
      return 1;
    }
  }
  if (((param_2 == 0) || (iVar1 = *(int *)(param_2 + 8), iVar1 == 0x40f)) ||
     ((iVar1 == 0x410 || (*(int *)(param_2 + 4) != 4)))) {
    switch(*(undefined4 *)(param_1 + 8)) {
    case 0x400:
      return 2;
    case 0x401:
      return 3;
    case 0x402:
    case 0x403:
      goto switchD_0061a29e_caseD_402;
    case 0x404:
      return 5;
    case 0x405:
      return 6;
    case 0x406:
      return 0xc;
    case 0x407:
      return 0x13;
    case 0x408:
      return 0xd;
    case 0x409:
      return 0x14;
    default:
      FUN_0044a580(local_100,&DAT_009ccf9c,s_INVALID_WEAPON_in_Right_Hand__009cceec);
      FUN_00797b80(local_100);
      return 1;
    case 0x40b:
      return 8;
    case 0x40c:
      return 9;
    case 0x40d:
      return 0xb;
    case 0x40f:
    case 0x410:
      return 1;
    case 0x411:
      return 0x15;
    case 0x412:
      return 0x16;
    case 0x413:
      return 0x17;
    case 0x414:
      return 0x18;
    }
  }
  if (((param_1 == 0) || (iVar2 = *(int *)(param_1 + 8), iVar2 == 0x40f)) ||
     ((iVar2 == 0x410 || (*(int *)(param_1 + 4) != 4)))) {
    if (iVar1 == 0x40a) {
      return 7;
    }
    if (iVar1 == 0x40e) {
      return 0xe;
    }
    FUN_0044a580(local_100,&DAT_009ccf9c,s_INVALID_WEAPON_in_Left_Hand__009ccf0c);
    FUN_00797b80(local_100);
    return 1;
  }
  if (iVar1 != 0x40e) {
    if (((iVar2 != 0x401) && (iVar2 != 0x406)) && (iVar2 != 0x408)) {
      FUN_0044a670(s_Right_Hand_Weapon_is_not_for_Dua_009ccf44);
      FUN_00797b80(local_100);
      return 1;
    }
    if (((iVar1 != 0x401) && (iVar1 != 0x406)) && (iVar1 != 0x408)) {
      FUN_0044a670(s_Left_Hand_Weapon_is_not_for_Dual_009ccf70);
      FUN_00797b80(local_100);
      return 1;
    }
    uVar3 = 10;
switchD_0061a29e_caseD_402:
    return uVar3;
  }
  if (iVar2 == 0x400) {
    return 0xf;
  }
  if (iVar2 == 0x401) {
    return 0x10;
  }
  if (iVar2 == 0x406) {
    return 0x11;
  }
  if (iVar2 == 0x408) {
    return 0x12;
  }
  FUN_0044a670(s_Cannot_Use_with_Shield_009ccf2c);
  FUN_00797b80(local_100);
  return 1;
}


// ==== FUN_0061a5d0 @ 0x0061a5d0 ====

void FUN_0061a5d0(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  short *psVar5;
  undefined4 uVar6;
  int in_ECX;
  undefined2 extraout_var;
  int iVar7;
  
  iVar3 = FUN_00803725(*(undefined4 *)(in_ECX + 4),0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 0x18) + 0x14))();
  psVar5 = (short *)(**(code **)(*piVar4 + 8))();
  sVar1 = psVar5[1];
  iVar3 = 0;
  iVar7 = 0;
  if (*psVar5 != 0) {
    piVar4 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(CONCAT22(extraout_var,*psVar5));
    iVar3 = (**(code **)(*piVar4 + 4))();
    iVar3 = iVar3 + 4;
  }
  if (sVar1 != 0) {
    piVar4 = (int *)(**(code **)(*DAT_00b5a738 + 0x10))(sVar1);
    iVar7 = (**(code **)(*piVar4 + 4))();
    iVar7 = iVar7 + 4;
  }
  iVar2 = *(int *)(in_ECX + 8);
  uVar6 = FUN_0061a200(iVar7,iVar3);
  (**(code **)(iVar2 + 0x14))(uVar6);
  return;
}


// ==== FUN_0061a670 @ 0x0061a670 ====

void FUN_0061a670(byte param_1)

{
  void *in_ECX;
  
  FUN_00619f00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061a690 @ 0x0061a690 ====

void FUN_0061a690(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009889d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccfc8;
  local_4 = 0;
  FUN_0063d3b0();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061a6e0 @ 0x0061a6e0 ====

int FUN_0061a6e0(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0061a6f0 @ 0x0061a6f0 ====

void FUN_0061a6f0(void)

{
  return;
}


// ==== FUN_0061a700 @ 0x0061a700 ====

void FUN_0061a700(uint *param_1)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 8) < *param_1) {
    *(undefined4 *)(in_ECX + 8) = 0;
    return;
  }
  *(uint *)(in_ECX + 8) = *(uint *)(in_ECX + 8) - *param_1;
  return;
}


// ==== FUN_0061a720 @ 0x0061a720 ====

int FUN_0061a720(void)

{
  int in_ECX;
  
  FUN_0063d450(*(undefined4 *)(in_ECX + 4));
  return in_ECX + 0xc;
}


// ==== FUN_0061a740 @ 0x0061a740 ====

int FUN_0061a740(void)

{
  int in_ECX;
  
  FUN_0063d450(*(undefined4 *)(in_ECX + 4));
  return in_ECX + 0xc;
}


// ==== FUN_0061a770 @ 0x0061a770 ====

void FUN_0061a770(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009889f5;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccfc8;
  FUN_0063d510();
  local_4 = CONCAT31(local_4._1_3_,1);
  FUN_00797a50(in_ECX + 2,0,4);
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061a7d0 @ 0x0061a7d0 ====

void FUN_0061a7d0(void)

{
  int *piVar1;
  int iVar2;
  undefined2 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  
  iVar2 = FUN_00803725(*(undefined4 *)(in_ECX + 4),0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  if (*(int **)(iVar2 + 4) != (int *)0x0) {
    (**(code **)(**(int **)(iVar2 + 4) + 0x18))();
  }
  piVar1 = DAT_00b5abb0;
  puVar3 = (undefined2 *)(**(code **)(*(int *)(in_ECX + 0xc) + 8))();
  uVar4 = (**(code **)(*piVar1 + 8))(*puVar3);
  (**(code **)(*(int *)(in_ECX + 0xc) + 0x10))(uVar4);
  return;
}


// ==== FUN_0061a830 @ 0x0061a830 ====

void FUN_0061a830(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = *param_1;
  FUN_0061a7d0();
  return;
}


// ==== FUN_0061a850 @ 0x0061a850 ====

int FUN_0061a850(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined2 *puVar3;
  ushort *puVar4;
  ushort *puVar5;
  int *piVar6;
  short *psVar7;
  undefined4 uVar8;
  int in_ECX;
  undefined4 uStack_4;
  
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + *param_1;
  piVar1 = (int *)(in_ECX + 0xc);
  iVar2 = (**(code **)(*(int *)(in_ECX + 0xc) + 0xc))();
  if (iVar2 == 0) {
    FUN_0061a7d0();
  }
  puVar3 = (undefined2 *)(**(code **)(*piVar1 + 8))();
  piVar6 = DAT_00b5a6b8;
  uStack_4 = CONCAT22((short)((uint)in_ECX >> 0x10),*puVar3);
  puVar4 = (ushort *)(**(code **)(*piVar1 + 8))();
  puVar5 = (ushort *)(**(code **)(*piVar6 + 4))();
  if (*puVar4 < *puVar5) {
    do {
      piVar6 = (int *)(**(code **)(*piVar1 + 0xc))();
      iVar2 = (**(code **)(*piVar6 + 4))();
      if (*(uint *)(in_ECX + 8) < *(uint *)(iVar2 + 4)) break;
      psVar7 = (short *)(**(code **)(*piVar1 + 8))();
      param_1 = (int *)CONCAT22((short)((uint)psVar7 >> 0x10),*psVar7 + 1);
      (**(code **)(*piVar1 + 0x14))(&param_1);
      piVar6 = (int *)(**(code **)(*piVar1 + 0xc))();
      iVar2 = (**(code **)(*piVar6 + 4))();
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) - *(int *)(iVar2 + 4);
      iVar2 = FUN_00803725(*(undefined4 *)(in_ECX + 4),0,&Framework::ICreature::RTTI_Type_Descriptor
                           ,&Framework::Creature::IPC::RTTI_Type_Descriptor,0);
      if (*(int **)(iVar2 + 4) != (int *)0x0) {
        (**(code **)(**(int **)(iVar2 + 4) + 0x18))();
      }
      piVar6 = DAT_00b5abb0;
      puVar3 = (undefined2 *)(**(code **)(*piVar1 + 8))();
      uVar8 = (**(code **)(*piVar6 + 8))(*puVar3);
      (**(code **)(*piVar1 + 0x10))(uVar8);
      piVar6 = DAT_00b5a6b8;
      puVar4 = (ushort *)(**(code **)(*piVar1 + 8))();
      puVar5 = (ushort *)(**(code **)(*piVar6 + 4))();
    } while (*puVar4 < *puVar5);
  }
  puVar3 = (undefined2 *)(**(code **)(*piVar1 + 8))();
  return CONCAT22((short)((uint)puVar3 >> 0x10),*puVar3) - uStack_4;
}


// ==== FUN_0061a980 @ 0x0061a980 ====

void FUN_0061a980(byte param_1)

{
  void *in_ECX;
  
  FUN_0061a690();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061a9a0 @ 0x0061a9a0 ====

void FUN_0061a9a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988a08;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccff8;
  local_4 = 0;
  FUN_0063d540();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061a9f0 @ 0x0061a9f0 ====

void FUN_0061a9f0(void)

{
  return;
}


// ==== FUN_0061aa00 @ 0x0061aa00 ====

int FUN_0061aa00(void)

{
  int in_ECX;
  
  FUN_0063d7b0(*(undefined4 *)(in_ECX + 4));
  return in_ECX + 8;
}


// ==== FUN_0061aa20 @ 0x0061aa20 ====

int FUN_0061aa20(void)

{
  int in_ECX;
  
  FUN_0063d7b0(*(undefined4 *)(in_ECX + 4));
  return in_ECX + 8;
}


// ==== FUN_0061aa40 @ 0x0061aa40 ====

void FUN_0061aa40(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x5c) = param_1;
  return;
}


// ==== FUN_0061aa50 @ 0x0061aa50 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0061aa50(uint param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int *piVar5;
  int in_ECX;
  int iVar6;
  undefined4 unaff_retaddr;
  
  cVar4 = FUN_005c8e90();
  if (cVar4 == '\x01') {
    piVar5 = (int *)(**(code **)(**(int **)(in_ECX + 4) + 0x10))();
    (**(code **)(*piVar5 + 0x20))();
    (**(code **)(*piVar5 + 0x30))(param_1);
    return;
  }
  if (*(int *)(in_ECX + 0x5c) + 500U < param_1) {
    iVar6 = param_1 - *(int *)(in_ECX + 0x5c);
    fVar3 = (float)iVar6;
    if (iVar6 < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    fVar3 = fVar3 * DAT_0099d0ec;
    piVar5 = (int *)(in_ECX + 8);
    iVar6 = (**(code **)(*(int *)(in_ECX + 8) + 0xc))();
    fVar1 = *(float *)(iVar6 + 8);
    iVar6 = (**(code **)(*piVar5 + 0xc))();
    fVar2 = *(float *)(iVar6 + 4);
    (**(code **)(*piVar5 + 0xc))();
    (**(code **)(*piVar5 + 0xc))();
    (**(code **)(*piVar5 + 0x14))(fVar3 * fVar1 + fVar2);
    (**(code **)(*piVar5 + 0x20))(unaff_retaddr);
    *(uint *)(in_ECX + 0x5c) = param_1;
  }
  return;
}


// ==== FUN_0061ab30 @ 0x0061ab30 ====

int FUN_0061ab30(void)

{
  int in_ECX;
  
  return in_ECX + 0x5c;
}


// ==== FUN_0061ab40 @ 0x0061ab40 ====

void FUN_0061ab40(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988a1a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009ccff8;
  FUN_0063d7c0();
  in_ECX[0x17] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061ab90 @ 0x0061ab90 ====

void FUN_0061ab90(byte param_1)

{
  void *in_ECX;
  
  FUN_0061a9a0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061abb0 @ 0x0061abb0 ====

void FUN_0061abb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988a38;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd024;
  local_4 = 0;
  FUN_0063d830();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061ac00 @ 0x0061ac00 ====

int FUN_0061ac00(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0061ac10 @ 0x0061ac10 ====

int FUN_0061ac10(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0061ac20 @ 0x0061ac20 ====

void FUN_0061ac20(void)

{
  return;
}


// ==== FUN_0061acb0 @ 0x0061acb0 ====

void FUN_0061acb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988a4a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd024;
  FUN_0063d970();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061ad00 @ 0x0061ad00 ====

void FUN_0061ad00(void)

{
  undefined1 uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  undefined2 *puVar6;
  int *piVar7;
  int iVar8;
  int in_ECX;
  int *piVar9;
  undefined4 uVar10;
  
  iVar3 = FUN_00803725(*(undefined4 *)(in_ECX + 4),0,&Framework::ICreature::RTTI_Type_Descriptor,
                       &Framework::Creature::IPC::RTTI_Type_Descriptor,0);
  piVar9 = *(int **)(iVar3 + 0x24);
  piVar4 = (int *)0x0;
  if (*(int **)(iVar3 + 4) != (int *)0x0) {
    piVar4 = (int *)(**(code **)(**(int **)(iVar3 + 4) + 0x18))();
  }
  puVar5 = (undefined1 *)(**(code **)(*piVar4 + 8))();
  uVar1 = *puVar5;
  FUN_0063d870();
  FUN_0063d8d0(uVar1);
  FUN_0063d8e0(0,0);
  FUN_0063d8e0(1,0);
  piVar4 = (int *)(**(code **)(*piVar9 + 0x2c))(8);
  if (piVar4 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar4 + 0x14))();
    FUN_0063d8b0(2,*puVar6);
  }
  piVar4 = (int *)(**(code **)(*piVar9 + 0x2c))(9);
  if (piVar4 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar4 + 0x14))();
    FUN_0063d8b0(3,*puVar6);
  }
  piVar4 = (int *)(**(code **)(*piVar9 + 0x2c))(10);
  if (piVar4 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar4 + 0x14))();
    FUN_0063d8b0(4,*puVar6);
  }
  piVar4 = (int *)(**(code **)(*piVar9 + 0x2c))(0xc);
  if (piVar4 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar4 + 0x14))();
    FUN_0063d8b0(6,*puVar6);
  }
  piVar4 = (int *)(**(code **)(*piVar9 + 0x2c))(0xb);
  if (piVar4 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar4 + 0x14))();
    FUN_0063d8b0(5,*puVar6);
  }
  piVar4 = (int *)(**(code **)(*piVar9 + 0x2c))(6);
  if (piVar4 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar4 + 0x14))();
    FUN_0063d8b0(7,*puVar6);
  }
  piVar4 = (int *)(**(code **)(*piVar9 + 0x2c))(7);
  if (piVar4 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar4 + 0x14))();
    FUN_0063d8b0(8,*puVar6);
  }
  piVar4 = (int *)(**(code **)(*piVar9 + 0x2c))(0x13);
  if (piVar4 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar4 + 0x14))();
    FUN_0063d8b0(9,*puVar6);
  }
  piVar4 = (int *)(**(code **)(*piVar9 + 0x2c))(0x14);
  if (piVar4 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar4 + 0x14))();
    FUN_0063d8b0(10,*puVar6);
  }
  uVar10 = 0x12;
  piVar4 = (int *)(**(code **)(*piVar9 + 0x2c))(0x12);
  if (piVar4 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar4 + 0x14))();
    FUN_0063d8b0(0xb,*puVar6);
  }
  iVar3 = 4;
  piVar4 = (int *)(**(code **)(*piVar9 + 0x2c))();
  (**(code **)(*piVar9 + 0x60))(piVar4,uVar1);
  piVar7 = (int *)(**(code **)(*piVar9 + 0x2c))(5);
  (**(code **)(*piVar9 + 0x60))(piVar7,uVar10);
  piVar9 = piVar7;
  if (piVar7 == (int *)0x0) {
LAB_0061af2c:
    if (piVar4 != (int *)0x0) {
      iVar8 = (**(code **)(*piVar4 + 0x2c))();
      if ((*(int *)(iVar8 + 8) == 0x40a) || (*(int *)(iVar8 + 8) == 0x40e)) goto LAB_0061af4d;
    }
  }
  else {
    iVar8 = (**(code **)(*piVar7 + 0x2c))();
    if ((*(int *)(iVar8 + 8) != 0x40a) && (*(int *)(iVar8 + 8) != 0x40e)) {
      iVar8 = (**(code **)(*piVar7 + 0x2c))();
      uVar2 = *(uint *)(iVar8 + 8);
      if ((uVar2 >> 8 == 4) && (((uVar2 != 0x40f && (uVar2 != 0x410)) && (uVar2 != 0x40e))))
      goto LAB_0061af4d;
      goto LAB_0061af2c;
    }
  }
  piVar9 = piVar4;
  piVar4 = piVar7;
LAB_0061af4d:
  if (piVar9 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar9 + 0x14))();
    FUN_0063d8b0(1,*puVar6);
    FUN_0063d8e0(1,piVar9);
  }
  if (piVar4 != (int *)0x0) {
    puVar6 = (undefined2 *)(**(code **)(*piVar4 + 0x14))();
    FUN_0063d8b0(0,*puVar6);
    FUN_0063d8e0(0,piVar4);
  }
                    /* WARNING: Could not recover jumptable at 0x0061afa2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(iVar3 + 0x74) + 0x18))();
  return;
}


// ==== FUN_0061afb0 @ 0x0061afb0 ====

void FUN_0061afb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061abb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061afd0 @ 0x0061afd0 ====

void FUN_0061afd0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988a68;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd048;
  local_4 = 0;
  FUN_0063d9e0();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061b020 @ 0x0061b020 ====

int FUN_0061b020(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0061b030 @ 0x0061b030 ====

int FUN_0061b030(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0061b040 @ 0x0061b040 ====

void FUN_0061b040(void)

{
  return;
}


// ==== FUN_0061b050 @ 0x0061b050 ====

void FUN_0061b050(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988a7a;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd048;
  FUN_0063da30();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061b0a0 @ 0x0061b0a0 ====

void FUN_0061b0a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061afd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061b0c0 @ 0x0061b0c0 ====

void FUN_0061b0c0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988a98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd068;
  local_4 = 0;
  FUN_0063da60();
  *in_ECX = &PTR_FUN_009cc234;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061b110 @ 0x0061b110 ====

int FUN_0061b110(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0061b120 @ 0x0061b120 ====

int FUN_0061b120(void)

{
  int in_ECX;
  
  return in_ECX + 8;
}


// ==== FUN_0061b130 @ 0x0061b130 ====

void FUN_0061b130(void)

{
  return;
}


// ==== FUN_0061b140 @ 0x0061b140 ====

void FUN_0061b140(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988aaa;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd068;
  FUN_0063dab0();
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061b190 @ 0x0061b190 ====

void FUN_0061b190(byte param_1)

{
  void *in_ECX;
  
  FUN_0061b0c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061b1b0 @ 0x0061b1b0 ====

void FUN_0061b1b0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00988b02;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(0xc);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00640d90();
  }
  local_4 = 0xffffffff;
  *in_ECX = uVar2;
  pvVar1 = operator_new(0x18);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00640000();
  }
  local_4 = 0xffffffff;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0063f710();
  }
  local_4 = 0xffffffff;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0063f000();
  }
  local_4 = 0xffffffff;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0x14);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0063ec10();
  }
  local_4 = 0xffffffff;
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 5;
  if (pvVar1 == (void *)0x0) {
    in_ECX[6] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0063dc60();
  in_ECX[6] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061b300 @ 0x0061b300 ====

void FUN_0061b300(void)

{
  int *in_ECX;
  
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
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
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*in_ECX)(1);
  }
  *in_ECX = 0;
  return;
}


// ==== FUN_0061b370 @ 0x0061b370 ====

void FUN_0061b370(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988b1f;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd088;
  pvVar1 = operator_new(0x1c);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0061b1b0();
  in_ECX[1] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061b3f0 @ 0x0061b3f0 ====

void FUN_0061b3f0(void)

{
  int *_Memory;
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_00988b31;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd088;
  _Memory = (int *)in_ECX[1];
  local_4 = 0;
  if (_Memory == (int *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_009c3574;
    ExceptionList = pvVar1;
    return;
  }
  if ((undefined4 *)_Memory[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)_Memory[6])(1);
  }
  _Memory[6] = 0;
  if ((undefined4 *)_Memory[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)_Memory[5])(1);
  }
  _Memory[5] = 0;
  if ((undefined4 *)_Memory[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)_Memory[4])(1);
  }
  _Memory[4] = 0;
  if ((undefined4 *)_Memory[3] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)_Memory[3])(1);
  }
  _Memory[3] = 0;
  if ((undefined4 *)_Memory[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)_Memory[2])(1);
  }
  _Memory[2] = 0;
  if ((undefined4 *)*_Memory != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*_Memory)(1);
  }
  *_Memory = 0;
  _free(_Memory);
  return;
}


// ==== FUN_0061b4b0 @ 0x0061b4b0 ====

void FUN_0061b4b0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061b3f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061b4d0 @ 0x0061b4d0 ====

void FUN_0061b4d0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00988bae;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(8);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00647990();
  }
  local_4 = 0xffffffff;
  *in_ECX = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00646d80();
  }
  local_4 = 0xffffffff;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00646390();
  }
  local_4 = 0xffffffff;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_006453c0();
  }
  local_4 = 0xffffffff;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00644740();
  }
  local_4 = 0xffffffff;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00643c20();
  }
  local_4 = 0xffffffff;
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00643180();
  }
  local_4 = 0xffffffff;
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00642790();
  }
  local_4 = 0xffffffff;
  in_ECX[7] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 8;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00641ca0();
  }
  local_4 = 0xffffffff;
  in_ECX[8] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 9;
  if (pvVar1 == (void *)0x0) {
    in_ECX[9] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_00641130();
  in_ECX[9] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061b6d0 @ 0x0061b6d0 ====

void FUN_0061b6d0(void)

{
  int *in_ECX;
  
  if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[7])(1);
  }
  in_ECX[7] = 0;
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
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
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
  }
  in_ECX[8] = 0;
  if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[9])(1);
  }
  in_ECX[9] = 0;
  return;
}


// ==== FUN_0061b780 @ 0x0061b780 ====

void FUN_0061b780(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988bcb;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd090;
  pvVar1 = operator_new(0x28);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_0061b4d0();
  in_ECX[1] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061b800 @ 0x0061b800 ====

void FUN_0061b800(void)

{
  void *_Memory;
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_00988bdd;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd090;
  _Memory = (void *)in_ECX[1];
  local_4 = 0;
  if (_Memory == (void *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_009c3574;
    ExceptionList = pvVar1;
    return;
  }
  FUN_0061b6d0();
  _free(_Memory);
  return;
}


// ==== FUN_0061b870 @ 0x0061b870 ====

void FUN_0061b870(byte param_1)

{
  void *in_ECX;
  
  FUN_0061b800();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061b890 @ 0x0061b890 ====

void FUN_0061b890(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd0dc;
  return;
}


// ==== FUN_0061b8a0 @ 0x0061b8a0 ====

void FUN_0061b8a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd0dc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061b8c0 @ 0x0061b8c0 ====

void FUN_0061b8c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd0ec;
  return;
}


// ==== FUN_0061b8d0 @ 0x0061b8d0 ====

void FUN_0061b8d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd104;
  return;
}


// ==== FUN_0061b8e0 @ 0x0061b8e0 ====

void FUN_0061b8e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd15c;
  return;
}


// ==== FUN_0061b8f0 @ 0x0061b8f0 ====

void FUN_0061b8f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd0ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061b910 @ 0x0061b910 ====

void FUN_0061b910(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd104;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061b930 @ 0x0061b930 ====

void FUN_0061b930(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd15c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061b950 @ 0x0061b950 ====

undefined4 FUN_0061b950(undefined2 param_1)

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


// ==== FUN_0061b980 @ 0x0061b980 ====

void FUN_0061b980(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988bf8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cd17c;
  DAT_00b5aa24 = 0;
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
  *in_ECX = &PTR_FUN_009cd0dc;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0061ba20 @ 0x0061ba20 ====

void FUN_0061ba20(void)

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
  puStack_8 = &LAB_00988c10;
  pvStack_c = ExceptionList;
  piVar6 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar3 = operator_new(0x27c);
  pvStack_c = (void *)0x0;
  if (pvVar3 != (void *)0x0) {
    piVar6 = (int *)FUN_00647f70();
  }
  puVar1 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar6 + 8))(puStack_4);
  *puVar2 = *puVar1;
  *(int **)(puVar2 + 2) = piVar6;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009cd0c4,
                         s___Support_Exchange_Flyweight_Con_009cd098,0x38);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_0061baf0 @ 0x0061baf0 ====

void FUN_0061baf0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00988c38;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd17c;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0061bc00();
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
    uVar3 = FUN_0061c170(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aa24 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa24 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061bbc0 @ 0x0061bbc0 ====

void FUN_0061bbc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd174;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0061bbe0 @ 0x0061bbe0 ====

void FUN_0061bbe0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061bbc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061bc00 @ 0x0061bc00 ====

void FUN_0061bc00(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988c58;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd18c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cd174;
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


// ==== FUN_0061bcb0 @ 0x0061bcb0 ====

void FUN_0061bcb0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061bcd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061bcd0 @ 0x0061bcd0 ====

void FUN_0061bcd0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988c83;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd18c;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cd174;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cd0ec;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_0061bd50 @ 0x0061bd50 ====

void * FUN_0061bd50(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd1a0,0x85);
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


// ==== FUN_0061be00 @ 0x0061be00 ====

undefined4 FUN_0061be00(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd1a0,0xa9);
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


// ==== FUN_0061be80 @ 0x0061be80 ====

void FUN_0061be80(byte param_1)

{
  void *in_ECX;
  
  FUN_0061b980();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061bea0 @ 0x0061bea0 ====

void FUN_0061bea0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd21c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0061bec0 @ 0x0061bec0 ====

void FUN_0061bec0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988ca3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd224;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cd21c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cd15c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_0061bf40 @ 0x0061bf40 ====

undefined4 FUN_0061bf40(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd1a0,0xa9);
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


// ==== FUN_0061bfc0 @ 0x0061bfc0 ====

undefined4 * FUN_0061bfc0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd1a0,0x85);
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


// ==== FUN_0061c080 @ 0x0061c080 ====

void FUN_0061c080(byte param_1)

{
  void *in_ECX;
  
  FUN_0061bea0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061c0a0 @ 0x0061c0a0 ====

void FUN_0061c0a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061bec0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061c0c0 @ 0x0061c0c0 ====

void FUN_0061c0c0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988cb8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd224;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cd21c;
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


// ==== FUN_0061c170 @ 0x0061c170 ====

void FUN_0061c170(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988cd8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd23c;
  FUN_0061c0c0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061c1d0 @ 0x0061c1d0 ====

void FUN_0061c1d0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0061c1f0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0061c1f0 @ 0x0061c1f0 ====

void FUN_0061c1f0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0061c1f0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0061c1f0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0061c230 @ 0x0061c230 ====

void FUN_0061c230(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0061c250(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0061c250 @ 0x0061c250 ====

void FUN_0061c250(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_0061c250(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_0061c250(param_1[3]);
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


// ==== FUN_0061c2c0 @ 0x0061c2c0 ====

void FUN_0061c2c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061c2e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061c2e0 @ 0x0061c2e0 ====

void FUN_0061c2e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00988d03;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd23c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_0061c250(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0061bec0();
  *in_ECX = &PTR_FUN_009cd104;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061c350 @ 0x0061c350 ====

void FUN_0061c350(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd2e0;
  return;
}


// ==== FUN_0061c360 @ 0x0061c360 ====

void FUN_0061c360(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd2e0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061c380 @ 0x0061c380 ====

void FUN_0061c380(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd2f0;
  return;
}


// ==== FUN_0061c390 @ 0x0061c390 ====

void FUN_0061c390(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd30c;
  return;
}


// ==== FUN_0061c3a0 @ 0x0061c3a0 ====

void FUN_0061c3a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd364;
  return;
}


// ==== FUN_0061c3b0 @ 0x0061c3b0 ====

void FUN_0061c3b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd2f0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061c3d0 @ 0x0061c3d0 ====

void FUN_0061c3d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd30c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061c3f0 @ 0x0061c3f0 ====

void FUN_0061c3f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd364;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061c410 @ 0x0061c410 ====

undefined4 FUN_0061c410(undefined2 param_1)

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


// ==== FUN_0061c440 @ 0x0061c440 ====

void FUN_0061c440(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988d18;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cd384;
  DAT_00b5ab20 = 0;
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
  *in_ECX = &PTR_FUN_009cd2e0;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0061c4e0 @ 0x0061c4e0 ====

void FUN_0061c4e0(void)

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
  puStack_8 = &LAB_00988d30;
  pvStack_c = ExceptionList;
  piVar6 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar3 = operator_new(0x10c);
  pvStack_c = (void *)0x0;
  if (pvVar3 != (void *)0x0) {
    piVar6 = (int *)FUN_00648130();
  }
  puVar1 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar6 + 8))(puStack_4);
  *puVar2 = *puVar1;
  *(int **)(puVar2 + 2) = piVar6;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009cd2c8,
                         s___Support_Location_Portal_Flywei_009cd294,0x38);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_0061c5b0 @ 0x0061c5b0 ====

void FUN_0061c5b0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00988d58;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd384;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0061c6d0();
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
    uVar3 = FUN_0061cc40(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab20 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab20 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061c680 @ 0x0061c680 ====

void FUN_0061c680(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd37c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0061c6a0 @ 0x0061c6a0 ====

void FUN_0061c6a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061c680();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061c6c0 @ 0x0061c6c0 ====

void FUN_0061c6c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  return;
}


// ==== FUN_0061c6d0 @ 0x0061c6d0 ====

void FUN_0061c6d0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988d78;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd394;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cd37c;
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


// ==== FUN_0061c780 @ 0x0061c780 ====

undefined4 FUN_0061c780(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd3a8,0xa9);
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


// ==== FUN_0061c800 @ 0x0061c800 ====

void FUN_0061c800(byte param_1)

{
  void *in_ECX;
  
  FUN_0061c820();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061c820 @ 0x0061c820 ====

void FUN_0061c820(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988da3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd394;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cd37c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cd2f0;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_0061c8a0 @ 0x0061c8a0 ====

void * FUN_0061c8a0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd3a8,0x85);
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


// ==== FUN_0061c950 @ 0x0061c950 ====

void FUN_0061c950(byte param_1)

{
  void *in_ECX;
  
  FUN_0061c440();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061c970 @ 0x0061c970 ====

void FUN_0061c970(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd430;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0061c990 @ 0x0061c990 ====

void FUN_0061c990(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988dc3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd438;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cd430;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cd364;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_0061ca10 @ 0x0061ca10 ====

undefined4 FUN_0061ca10(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd3a8,0xa9);
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


// ==== FUN_0061ca90 @ 0x0061ca90 ====

undefined4 * FUN_0061ca90(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd3a8,0x85);
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


// ==== FUN_0061cb50 @ 0x0061cb50 ====

void FUN_0061cb50(byte param_1)

{
  void *in_ECX;
  
  FUN_0061c970();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061cb70 @ 0x0061cb70 ====

void FUN_0061cb70(byte param_1)

{
  void *in_ECX;
  
  FUN_0061c990();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061cb90 @ 0x0061cb90 ====

void FUN_0061cb90(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988dd8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd438;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cd430;
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


// ==== FUN_0061cc40 @ 0x0061cc40 ====

void FUN_0061cc40(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988df8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd454;
  FUN_0061cb90();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061cca0 @ 0x0061cca0 ====

void FUN_0061cca0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0061ccc0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0061ccc0 @ 0x0061ccc0 ====

void FUN_0061ccc0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0061ccc0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0061ccc0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0061cd00 @ 0x0061cd00 ====

void FUN_0061cd00(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0061cd20(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0061cd20 @ 0x0061cd20 ====

void FUN_0061cd20(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_0061cd20(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_0061cd20(param_1[3]);
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


// ==== FUN_0061cd90 @ 0x0061cd90 ====

void FUN_0061cd90(byte param_1)

{
  void *in_ECX;
  
  FUN_0061cdb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061cdb0 @ 0x0061cdb0 ====

void FUN_0061cdb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00988e23;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd454;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_0061cd20(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0061c990();
  *in_ECX = &PTR_FUN_009cd30c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061ce20 @ 0x0061ce20 ====

void FUN_0061ce20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd4f8;
  return;
}


// ==== FUN_0061ce30 @ 0x0061ce30 ====

void FUN_0061ce30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd4f8;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061ce50 @ 0x0061ce50 ====

void FUN_0061ce50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd508;
  return;
}


// ==== FUN_0061ce60 @ 0x0061ce60 ====

void FUN_0061ce60(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd524;
  return;
}


// ==== FUN_0061ce70 @ 0x0061ce70 ====

void FUN_0061ce70(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd57c;
  return;
}


// ==== FUN_0061ce80 @ 0x0061ce80 ====

void FUN_0061ce80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd508;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061cea0 @ 0x0061cea0 ====

void FUN_0061cea0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd524;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061cec0 @ 0x0061cec0 ====

void FUN_0061cec0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd57c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061cee0 @ 0x0061cee0 ====

undefined4 FUN_0061cee0(undefined2 param_1)

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


// ==== FUN_0061cf10 @ 0x0061cf10 ====

void FUN_0061cf10(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988e38;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cd59c;
  DAT_00b5ab28 = 0;
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
  *in_ECX = &PTR_FUN_009cd4f8;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0061cfb0 @ 0x0061cfb0 ====

void FUN_0061cfb0(void)

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
  puStack_8 = &LAB_00988e50;
  pvStack_c = ExceptionList;
  piVar6 = (int *)0x0;
  ExceptionList = &pvStack_c;
  puVar2 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  pvVar3 = operator_new(0x10c);
  pvStack_c = (void *)0x0;
  if (pvVar3 != (void *)0x0) {
    piVar6 = (int *)FUN_006481b0();
  }
  puVar1 = puStack_4;
  pvStack_c = (void *)0xffffffff;
  (**(code **)(*piVar6 + 8))(puStack_4);
  *puVar2 = *puVar1;
  *(int **)(puVar2 + 2) = piVar6;
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar2);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009cd4e0,
                         s___Support_Location_Chaotic_Flywe_009cd4ac,0x38);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_0061d080 @ 0x0061d080 ====

void FUN_0061d080(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00988e78;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd59c;
  pvVar2 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0061d190();
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
    uVar3 = FUN_0061d700(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab28 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab28 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061d150 @ 0x0061d150 ====

void FUN_0061d150(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd594;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0061d170 @ 0x0061d170 ====

void FUN_0061d170(byte param_1)

{
  void *in_ECX;
  
  FUN_0061d150();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061d190 @ 0x0061d190 ====

void FUN_0061d190(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988e98;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd5ac;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cd594;
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


// ==== FUN_0061d240 @ 0x0061d240 ====

undefined4 FUN_0061d240(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd5c0,0xa9);
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


// ==== FUN_0061d2c0 @ 0x0061d2c0 ====

void FUN_0061d2c0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061d2e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061d2e0 @ 0x0061d2e0 ====

void FUN_0061d2e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988ec3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd5ac;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cd594;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cd508;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_0061d360 @ 0x0061d360 ====

void * FUN_0061d360(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd5c0,0x85);
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


// ==== FUN_0061d410 @ 0x0061d410 ====

void FUN_0061d410(byte param_1)

{
  void *in_ECX;
  
  FUN_0061cf10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061d430 @ 0x0061d430 ====

void FUN_0061d430(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd648;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0061d450 @ 0x0061d450 ====

void FUN_0061d450(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988ee3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd650;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cd648;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cd57c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_0061d4d0 @ 0x0061d4d0 ====

undefined4 FUN_0061d4d0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd5c0,0xa9);
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


// ==== FUN_0061d550 @ 0x0061d550 ====

undefined4 * FUN_0061d550(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd5c0,0x85);
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


// ==== FUN_0061d610 @ 0x0061d610 ====

void FUN_0061d610(byte param_1)

{
  void *in_ECX;
  
  FUN_0061d430();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061d630 @ 0x0061d630 ====

void FUN_0061d630(byte param_1)

{
  void *in_ECX;
  
  FUN_0061d450();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061d650 @ 0x0061d650 ====

void FUN_0061d650(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988ef8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd650;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cd648;
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


// ==== FUN_0061d700 @ 0x0061d700 ====

void FUN_0061d700(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988f18;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd66c;
  FUN_0061d650();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061d760 @ 0x0061d760 ====

void FUN_0061d760(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0061d780(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0061d780 @ 0x0061d780 ====

void FUN_0061d780(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0061d780(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0061d780(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0061d7c0 @ 0x0061d7c0 ====

void FUN_0061d7c0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0061d7e0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0061d7e0 @ 0x0061d7e0 ====

void FUN_0061d7e0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_0061d7e0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_0061d7e0(param_1[3]);
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


// ==== FUN_0061d850 @ 0x0061d850 ====

void FUN_0061d850(byte param_1)

{
  void *in_ECX;
  
  FUN_0061d870();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061d870 @ 0x0061d870 ====

void FUN_0061d870(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00988f43;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd66c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_0061d7e0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0061d450();
  *in_ECX = &PTR_FUN_009cd524;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061d8e0 @ 0x0061d8e0 ====

void FUN_0061d8e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd70c;
  return;
}


// ==== FUN_0061d8f0 @ 0x0061d8f0 ====

void FUN_0061d8f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd70c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061d910 @ 0x0061d910 ====

void FUN_0061d910(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd71c;
  return;
}


// ==== FUN_0061d920 @ 0x0061d920 ====

void FUN_0061d920(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd734;
  return;
}


// ==== FUN_0061d930 @ 0x0061d930 ====

void FUN_0061d930(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd78c;
  return;
}


// ==== FUN_0061d940 @ 0x0061d940 ====

void FUN_0061d940(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd71c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061d960 @ 0x0061d960 ====

void FUN_0061d960(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd734;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061d980 @ 0x0061d980 ====

void FUN_0061d980(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd78c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061d9a0 @ 0x0061d9a0 ====

undefined4 FUN_0061d9a0(undefined4 *param_1)

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


// ==== FUN_0061d9e0 @ 0x0061d9e0 ====

void FUN_0061d9e0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988f58;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cd7ac;
  DAT_00b5ab24 = 0;
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
  *in_ECX = &PTR_FUN_009cd70c;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0061da80 @ 0x0061da80 ====

void FUN_0061da80(void)

{
  void *pvVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined1 auStack_10e [242];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 *local_4;
  
  local_4 = (undefined4 *)0xffffffff;
  puStack_8 = &LAB_00988f70;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(8);
  local_4 = (undefined4 *)0x0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00648290();
  }
  local_4 = (undefined4 *)0xffffffff;
  puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = *local_4;
  puVar3[1] = local_4[1];
  puVar3[2] = piVar2;
  (**(code **)(*piVar2 + 8))(unaff_retaddr);
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009cd6f4,
                         s___Support_ItemSellPrice_Flyweigh_009cd6c4,0x39);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_0061db60 @ 0x0061db60 ====

void FUN_0061db60(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00988f98;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd7ac;
  pvVar2 = operator_new(0x108);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0061dc70();
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
    uVar3 = FUN_0061e2b0(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5ab24 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5ab24 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061dc30 @ 0x0061dc30 ====

void FUN_0061dc30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd7a4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x18,10,FUN_006ef6d0);
  return;
}


// ==== FUN_0061dc50 @ 0x0061dc50 ====

void FUN_0061dc50(byte param_1)

{
  void *in_ECX;
  
  FUN_0061dc30();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061dc70 @ 0x0061dc70 ====

void FUN_0061dc70(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988fb8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd7bc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cd7a4;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x18,10,FUN_00419fa0,FUN_006ef6d0);
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


// ==== FUN_0061dd80 @ 0x0061dd80 ====

undefined4 FUN_0061dd80(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xfc);
}


// ==== FUN_0061dd90 @ 0x0061dd90 ====

void FUN_0061dd90(byte param_1)

{
  void *in_ECX;
  
  FUN_0061ddb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061ddb0 @ 0x0061ddb0 ====

void FUN_0061ddb0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00988fe3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd7bc;
  local_4 = 1;
  if ((void *)in_ECX[0x40] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cd7a4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x18,10,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cd71c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x40]);
  return;
}


// ==== FUN_0061de30 @ 0x0061de30 ====

void * FUN_0061de30(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x14) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd7d0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x14) = *(int *)((int)param_2 + 0x14) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x104);
  *(int *)(in_ECX + 0xfc) = *(int *)(in_ECX + 0xfc) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x18);
    *(undefined4 *)((int)pvVar2 + 0x10) = *(undefined4 *)(in_ECX + 0x100);
    *(void **)(in_ECX + 0x100) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x104) = *(undefined4 *)((int)pvVar2 + 0xc);
  }
  *(undefined4 *)((int)pvVar2 + 0xc) = 0;
  *(int *)((int)pvVar2 + 0x14) = param_1;
  return pvVar2;
}


// ==== FUN_0061dee0 @ 0x0061dee0 ====

undefined4 FUN_0061dee0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x14) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd7d0,0xa9);
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


// ==== FUN_0061df60 @ 0x0061df60 ====

void FUN_0061df60(byte param_1)

{
  void *in_ECX;
  
  FUN_0061d9e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061df80 @ 0x0061df80 ====

void FUN_0061df80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd854;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,10,FUN_006ef6d0);
  return;
}


// ==== FUN_0061dfa0 @ 0x0061dfa0 ====

void FUN_0061dfa0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989003;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd85c;
  local_4 = 1;
  if ((void *)in_ECX[0x54] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cd854;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,10,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cd78c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x54]);
  return;
}


// ==== FUN_0061e020 @ 0x0061e020 ====

undefined4 FUN_0061e020(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd7d0,0xa9);
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


// ==== FUN_0061e0a0 @ 0x0061e0a0 ====

undefined4 * FUN_0061e0a0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd7d0,0x85);
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


// ==== FUN_0061e160 @ 0x0061e160 ====

void FUN_0061e160(byte param_1)

{
  void *in_ECX;
  
  FUN_0061df80();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061e180 @ 0x0061e180 ====

void FUN_0061e180(byte param_1)

{
  void *in_ECX;
  
  FUN_0061dfa0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061e1a0 @ 0x0061e1a0 ====

void FUN_0061e1a0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989018;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd85c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cd854;
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


// ==== FUN_0061e2b0 @ 0x0061e2b0 ====

void FUN_0061e2b0(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989038;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd874;
  FUN_0061e1a0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061e310 @ 0x0061e310 ====

void FUN_0061e310(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0061e330(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0061e330 @ 0x0061e330 ====

void FUN_0061e330(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0061e330(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0061e330(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0061e370 @ 0x0061e370 ====

undefined4 * FUN_0061e370(void)

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
  iVar4 = FUN_0061e420(iVar1,*puVar2);
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
        goto LAB_0061e409;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
LAB_0061e409:
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_0061e420(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_0061e420 @ 0x0061e420 ====

undefined4 FUN_0061e420(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *param_2;
  if ((iVar1 < iVar2) || ((iVar1 <= iVar2 && (param_1[1] < param_2[1])))) {
    return 0xffffffff;
  }
  if ((iVar2 < iVar1) || ((iVar2 <= iVar1 && (param_2[1] < param_1[1])))) {
    return 1;
  }
  return 0;
}


// ==== FUN_0061e490 @ 0x0061e490 ====

void FUN_0061e490(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0061e4b0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0061e4b0 @ 0x0061e4b0 ====

void FUN_0061e4b0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_0061e4b0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_0061e4b0(param_1[3]);
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


// ==== FUN_0061e530 @ 0x0061e530 ====

int * FUN_0061e530(int *param_1)

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
    iVar2 = *(int *)*piVar3;
    if ((*param_1 < iVar2) || ((*param_1 <= iVar2 && (param_1[1] < ((int *)*piVar3)[1])))) {
      iVar2 = -1;
    }
    else {
      cVar1 = FUN_0061e5b0(param_1);
      if (cVar1 == '\0') {
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return piVar3;
      }
      iVar2 = 1;
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


// ==== FUN_0061e5b0 @ 0x0061e5b0 ====

int FUN_0061e5b0(int *param_1)

{
  int iVar1;
  uint3 uVar2;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if (iVar1 < *param_1) {
    return CONCAT31(uVar2,1);
  }
  if (*param_1 < iVar1) {
    return (uint)uVar2 << 8;
  }
  return CONCAT31((int3)((uint)in_ECX[1] >> 8),in_ECX[1] < param_1[1]);
}


// ==== FUN_0061e5e0 @ 0x0061e5e0 ====

void FUN_0061e5e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061e600();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061e600 @ 0x0061e600 ====

void FUN_0061e600(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00989063;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd874;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_0061e4b0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0061dfa0();
  *in_ECX = &PTR_FUN_009cd734;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061e670 @ 0x0061e670 ====

void FUN_0061e670(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd918;
  return;
}


// ==== FUN_0061e680 @ 0x0061e680 ====

void FUN_0061e680(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd918;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061e6a0 @ 0x0061e6a0 ====

void FUN_0061e6a0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd928;
  return;
}


// ==== FUN_0061e6b0 @ 0x0061e6b0 ====

void FUN_0061e6b0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd944;
  return;
}


// ==== FUN_0061e6c0 @ 0x0061e6c0 ====

void FUN_0061e6c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd99c;
  return;
}


// ==== FUN_0061e6d0 @ 0x0061e6d0 ====

void FUN_0061e6d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd928;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061e6f0 @ 0x0061e6f0 ====

void FUN_0061e6f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd944;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061e710 @ 0x0061e710 ====

void FUN_0061e710(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd99c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061e730 @ 0x0061e730 ====

undefined4 FUN_0061e730(undefined4 *param_1)

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


// ==== FUN_0061e770 @ 0x0061e770 ====

void FUN_0061e770(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989078;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cd9bc;
  DAT_00b5aa20 = 0;
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
  *in_ECX = &PTR_FUN_009cd918;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0061e810 @ 0x0061e810 ====

void FUN_0061e810(void)

{
  void *pvVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined1 auStack_10e [242];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 *local_4;
  
  local_4 = (undefined4 *)0xffffffff;
  puStack_8 = &LAB_00989090;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x10);
  local_4 = (undefined4 *)0x0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_00648320();
  }
  local_4 = (undefined4 *)0xffffffff;
  puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = *local_4;
  puVar3[1] = local_4[1];
  puVar3[2] = piVar2;
  (**(code **)(*piVar2 + 8))(unaff_retaddr);
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009cd900,
                         s___Support_ItemRemoveStone_FlyWei_009cd8cc,0x39);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_0061e8f0 @ 0x0061e8f0 ====

void FUN_0061e8f0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009890b8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd9bc;
  pvVar2 = operator_new(0x1818);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0061ea00();
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
    uVar3 = FUN_0061ef70(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aa20 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa20 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061e9c0 @ 0x0061e9c0 ====

void FUN_0061e9c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cd9b4;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x18,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0061e9e0 @ 0x0061e9e0 ====

void FUN_0061e9e0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061e9c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061ea00 @ 0x0061ea00 ====

void FUN_0061ea00(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009890d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd9cc;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cd9b4;
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


// ==== FUN_0061eab0 @ 0x0061eab0 ====

undefined4 FUN_0061eab0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x14) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd9e0,0xa9);
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


// ==== FUN_0061eb30 @ 0x0061eb30 ====

void FUN_0061eb30(byte param_1)

{
  void *in_ECX;
  
  FUN_0061eb50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061eb50 @ 0x0061eb50 ====

void FUN_0061eb50(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989103;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cd9cc;
  local_4 = 1;
  if ((void *)in_ECX[0x604] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cd9b4;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x18,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cd928;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x604]);
  return;
}


// ==== FUN_0061ebd0 @ 0x0061ebd0 ====

void * FUN_0061ebd0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x14) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd9e0,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x14) = *(int *)((int)param_2 + 0x14) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x1814);
  *(int *)(in_ECX + 0x180c) = *(int *)(in_ECX + 0x180c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x18);
    *(undefined4 *)((int)pvVar2 + 0x10) = *(undefined4 *)(in_ECX + 0x1810);
    *(void **)(in_ECX + 0x1810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1814) = *(undefined4 *)((int)pvVar2 + 0xc);
  }
  *(undefined4 *)((int)pvVar2 + 0xc) = 0;
  *(int *)((int)pvVar2 + 0x14) = param_1;
  return pvVar2;
}


// ==== FUN_0061ec80 @ 0x0061ec80 ====

void FUN_0061ec80(byte param_1)

{
  void *in_ECX;
  
  FUN_0061e770();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061eca0 @ 0x0061eca0 ====

void FUN_0061eca0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cda64;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0061ecc0 @ 0x0061ecc0 ====

void FUN_0061ecc0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989123;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cda6c;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cda64;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cd99c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_0061ed40 @ 0x0061ed40 ====

undefined4 FUN_0061ed40(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd9e0,0xa9);
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


// ==== FUN_0061edc0 @ 0x0061edc0 ====

undefined4 * FUN_0061edc0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cd9e0,0x85);
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


// ==== FUN_0061ee80 @ 0x0061ee80 ====

void FUN_0061ee80(byte param_1)

{
  void *in_ECX;
  
  FUN_0061eca0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061eea0 @ 0x0061eea0 ====

void FUN_0061eea0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061ecc0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061eec0 @ 0x0061eec0 ====

void FUN_0061eec0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989138;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cda6c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cda64;
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


// ==== FUN_0061ef70 @ 0x0061ef70 ====

void FUN_0061ef70(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989158;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cda84;
  FUN_0061eec0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061efd0 @ 0x0061efd0 ====

void FUN_0061efd0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0061eff0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0061eff0 @ 0x0061eff0 ====

void FUN_0061eff0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0061eff0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0061eff0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0061f030 @ 0x0061f030 ====

undefined4 * FUN_0061f030(void)

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
  iVar4 = FUN_0061fc50(iVar1,*puVar2);
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
        goto LAB_0061f0c9;
      }
    }
    else {
      puVar5 = (undefined4 *)puVar2[3];
      if (puVar5 == (undefined4 *)0x0) {
        piVar3[4] = (int)puVar2;
        puVar2[3] = piVar3;
LAB_0061f0c9:
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return (undefined4 *)0x0;
      }
    }
    iVar4 = FUN_0061fc50(iVar1,*puVar5);
    puVar2 = puVar5;
  } while( true );
}


// ==== FUN_0061f0e0 @ 0x0061f0e0 ====

void FUN_0061f0e0(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = *(int *)(param_2 + 0x10);
  iVar2 = *(int *)(param_1 + 0x10);
  do {
    if (iVar2 == iVar1) {
      if (param_2 == *(int *)(in_ECX + 4)) {
        *(int *)(in_ECX + 4) = param_1;
      }
      return;
    }
    iVar3 = *(int *)(iVar2 + 0x10);
    if (iVar3 == iVar1) {
      if (*(int *)(iVar2 + 8) != param_1) goto LAB_0061f121;
      FUN_005f61b0(iVar2);
    }
    else if (*(int *)(iVar2 + 8) == param_1) {
      if (*(int *)(iVar3 + 8) != iVar2) {
        FUN_005f61b0(iVar2);
        goto LAB_0061f121;
      }
      FUN_005f61b0(iVar3);
      FUN_005f61b0(iVar2);
    }
    else if (*(int *)(iVar3 + 8) == iVar2) {
      FUN_006384e0(iVar2);
      FUN_005f61b0(iVar2);
    }
    else {
      FUN_006384e0(iVar3);
LAB_0061f121:
      FUN_006384e0(iVar2);
    }
    iVar2 = *(int *)(param_1 + 0x10);
  } while( true );
}


// ==== FUN_0061f170 @ 0x0061f170 ====

void FUN_0061f170(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0061f190(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0061f190 @ 0x0061f190 ====

void FUN_0061f190(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_0061f190(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_0061f190(param_1[3]);
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


// ==== FUN_0061f200 @ 0x0061f200 ====

void FUN_0061f200(byte param_1)

{
  void *in_ECX;
  
  FUN_0061f220();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061f220 @ 0x0061f220 ====

void FUN_0061f220(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_00989183;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cda84;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_0061f190(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0061ecc0();
  *in_ECX = &PTR_FUN_009cd944;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061f290 @ 0x0061f290 ====

void FUN_0061f290(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdb24;
  return;
}


// ==== FUN_0061f2a0 @ 0x0061f2a0 ====

void FUN_0061f2a0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdb24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061f2c0 @ 0x0061f2c0 ====

void FUN_0061f2c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdb34;
  return;
}


// ==== FUN_0061f2d0 @ 0x0061f2d0 ====

void FUN_0061f2d0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdb4c;
  return;
}


// ==== FUN_0061f2e0 @ 0x0061f2e0 ====

void FUN_0061f2e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdba4;
  return;
}


// ==== FUN_0061f2f0 @ 0x0061f2f0 ====

void FUN_0061f2f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdb34;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061f310 @ 0x0061f310 ====

void FUN_0061f310(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdb4c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061f330 @ 0x0061f330 ====

void FUN_0061f330(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdba4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061f350 @ 0x0061f350 ====

undefined4 FUN_0061f350(undefined4 *param_1)

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


// ==== FUN_0061f390 @ 0x0061f390 ====

void FUN_0061f390(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989198;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cdbc4;
  DAT_00b5aa28 = 0;
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
  *in_ECX = &PTR_FUN_009cdb24;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_0061f430 @ 0x0061f430 ====

void FUN_0061f430(void)

{
  void *pvVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 unaff_retaddr;
  undefined1 auStack_10e [242];
  void *pvStack_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 *local_4;
  
  local_4 = (undefined4 *)0xffffffff;
  puStack_8 = &LAB_009891b0;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  pvVar1 = operator_new(0x10);
  local_4 = (undefined4 *)0x0;
  if (pvVar1 == (void *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)FUN_006483b0();
  }
  local_4 = (undefined4 *)0xffffffff;
  puVar3 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = *local_4;
  puVar3[1] = local_4[1];
  puVar3[2] = piVar2;
  (**(code **)(*piVar2 + 8))(unaff_retaddr);
  iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  if (iVar4 != 0) {
    uVar5 = FUN_0044a580(auStack_10e + -0xe,s_File___s__Line___d_009cdb0c,
                         s___Support_ItemAddSocket_Flyweigh_009cdadc,0x39);
    FUN_00797b80(uVar5);
    FUN_00797a40();
  }
  ExceptionList = pvStack_1c;
  return;
}


// ==== FUN_0061f510 @ 0x0061f510 ====

void FUN_0061f510(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_009891d8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cdbc4;
  pvVar2 = operator_new(0x1818);
  local_4._0_1_ = 1;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0061f620();
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
    uVar3 = FUN_0061fb90(*puVar1);
  }
  in_ECX[2] = uVar3;
  if (puVar1 == (undefined4 *)0x0) {
    DAT_00b5aa28 = (undefined4 *)0x0;
    ExceptionList = local_c;
    return;
  }
  DAT_00b5aa28 = in_ECX;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061f5e0 @ 0x0061f5e0 ====

void FUN_0061f5e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdbbc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x18,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0061f600 @ 0x0061f600 ====

void FUN_0061f600(byte param_1)

{
  void *in_ECX;
  
  FUN_0061f5e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061f620 @ 0x0061f620 ====

void FUN_0061f620(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009891f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cdbd4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cdbbc;
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


// ==== FUN_0061f6d0 @ 0x0061f6d0 ====

void FUN_0061f6d0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061f6f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061f6f0 @ 0x0061f6f0 ====

void FUN_0061f6f0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989223;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cdbd4;
  local_4 = 1;
  if ((void *)in_ECX[0x604] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cdbbc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x18,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cdb34;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x604]);
  return;
}


// ==== FUN_0061f770 @ 0x0061f770 ====

void * FUN_0061f770(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x14) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cdbe8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x14) = *(int *)((int)param_2 + 0x14) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x1814);
  *(int *)(in_ECX + 0x180c) = *(int *)(in_ECX + 0x180c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x18);
    *(undefined4 *)((int)pvVar2 + 0x10) = *(undefined4 *)(in_ECX + 0x1810);
    *(void **)(in_ECX + 0x1810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x1814) = *(undefined4 *)((int)pvVar2 + 0xc);
  }
  *(undefined4 *)((int)pvVar2 + 0xc) = 0;
  *(int *)((int)pvVar2 + 0x14) = param_1;
  return pvVar2;
}


// ==== FUN_0061f820 @ 0x0061f820 ====

undefined4 FUN_0061f820(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x14) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cdbe8,0xa9);
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


// ==== FUN_0061f8a0 @ 0x0061f8a0 ====

void FUN_0061f8a0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061f390();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061f8c0 @ 0x0061f8c0 ====

void FUN_0061f8c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdc6c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_0061f8e0 @ 0x0061f8e0 ====

void FUN_0061f8e0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989243;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cdc74;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009cdc6c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009cdba4;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_0061f960 @ 0x0061f960 ====

undefined4 FUN_0061f960(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cdbe8,0xa9);
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


// ==== FUN_0061f9e0 @ 0x0061f9e0 ====

undefined4 * FUN_0061f9e0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009cdbe8,0x85);
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


// ==== FUN_0061faa0 @ 0x0061faa0 ====

void FUN_0061faa0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061f8c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061fac0 @ 0x0061fac0 ====

void FUN_0061fac0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061f8e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061fae0 @ 0x0061fae0 ====

void FUN_0061fae0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989258;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cdc74;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009cdc6c;
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


// ==== FUN_0061fb90 @ 0x0061fb90 ====

void FUN_0061fb90(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00989278;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cdc8c;
  FUN_0061fae0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061fbf0 @ 0x0061fbf0 ====

void FUN_0061fbf0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0061fc10(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0061fc10 @ 0x0061fc10 ====

void FUN_0061fc10(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_0061fc10(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_0061fc10(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_0061fc50 @ 0x0061fc50 ====

undefined4 FUN_0061fc50(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = *param_2;
  if ((iVar1 < iVar2) || ((iVar1 <= iVar2 && ((uint)param_1[1] < (uint)param_2[1])))) {
    return 0xffffffff;
  }
  if ((iVar2 < iVar1) || ((iVar2 <= iVar1 && ((uint)param_2[1] < (uint)param_1[1])))) {
    return 1;
  }
  return 0;
}


// ==== FUN_0061fca0 @ 0x0061fca0 ====

void FUN_0061fca0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_0061fcc0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_0061fcc0 @ 0x0061fcc0 ====

void FUN_0061fcc0(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_0061fcc0(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_0061fcc0(param_1[3]);
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


// ==== FUN_0061fd40 @ 0x0061fd40 ====

int * FUN_0061fd40(int *param_1)

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
    iVar2 = *(int *)*piVar3;
    if ((*param_1 < iVar2) ||
       ((*param_1 <= iVar2 && ((uint)param_1[1] < (uint)((int *)*piVar3)[1])))) {
      iVar2 = -1;
    }
    else {
      cVar1 = FUN_0061fdc0(param_1);
      if (cVar1 == '\0') {
        FUN_0061f0e0(piVar3,*(undefined4 *)(in_ECX + 4));
        return piVar3;
      }
      iVar2 = 1;
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


// ==== FUN_0061fdc0 @ 0x0061fdc0 ====

int FUN_0061fdc0(int *param_1)

{
  int iVar1;
  uint3 uVar2;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  uVar2 = (uint3)((uint)iVar1 >> 8);
  if (iVar1 < *param_1) {
    return CONCAT31(uVar2,1);
  }
  if (*param_1 < iVar1) {
    return (uint)uVar2 << 8;
  }
  return CONCAT31((int3)((uint)in_ECX[1] >> 8),(uint)in_ECX[1] < (uint)param_1[1]);
}


// ==== FUN_0061fdf0 @ 0x0061fdf0 ====

void FUN_0061fdf0(byte param_1)

{
  void *in_ECX;
  
  FUN_0061fe10();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061fe10 @ 0x0061fe10 ====

void FUN_0061fe10(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009892a3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009cdc8c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_0061fcc0(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_0061f8e0();
  *in_ECX = &PTR_FUN_009cdb4c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_0061fe80 @ 0x0061fe80 ====

void FUN_0061fe80(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdd2c;
  return;
}


// ==== FUN_0061fe90 @ 0x0061fe90 ====

void FUN_0061fe90(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdd2c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061feb0 @ 0x0061feb0 ====

void FUN_0061feb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdd3c;
  return;
}


// ==== FUN_0061fec0 @ 0x0061fec0 ====

void FUN_0061fec0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdd54;
  return;
}


// ==== FUN_0061fed0 @ 0x0061fed0 ====

void FUN_0061fed0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cddac;
  return;
}


// ==== FUN_0061fee0 @ 0x0061fee0 ====

void FUN_0061fee0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdd3c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061ff00 @ 0x0061ff00 ====

void FUN_0061ff00(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cdd54;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061ff20 @ 0x0061ff20 ====

void FUN_0061ff20(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009cddac;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_0061ff40 @ 0x0061ff40 ====

undefined4 FUN_0061ff40(undefined4 param_1,undefined2 param_2)

{
  int *piVar1;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = param_1;
  local_10 = CONCAT22(local_10._2_2_,param_2);
  local_8 = local_10;
  piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x30))(&local_c);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*piVar1 + 8);
}


// ==== FUN_0061ff80 @ 0x0061ff80 ====

void FUN_0061ff80(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009892b8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009cddcc;
  DAT_00b5ab2c = 0;
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
  *in_ECX = &PTR_FUN_009cdd2c;
  ExceptionList = pvStack_c;
  return;
}


