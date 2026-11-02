// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x7a0000-0x7affff

// ==== FUN_007a0015 @ 0x007a0015 ====

float * FUN_007a0015(float *param_1,float *param_2,float param_3,float *param_4,float *param_5,
                    float param_6,float *param_7)

{
  float fVar1;
  undefined1 local_d0 [64];
  undefined1 local_90 [64];
  float local_50 [6];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  if (param_4 == (float *)0x0) {
    param_1[0xe] = 0.0;
    param_1[0xd] = 0.0;
    param_1[0xc] = 0.0;
    param_1[0xb] = 0.0;
    param_1[9] = 0.0;
    param_1[8] = 0.0;
    param_1[7] = 0.0;
    param_1[6] = 0.0;
    param_1[4] = 0.0;
    param_1[3] = 0.0;
    param_1[2] = 0.0;
    param_1[1] = 0.0;
    param_1[0xf] = 1.0;
    param_1[10] = 1.0;
    param_1[5] = 1.0;
    *param_1 = 1.0;
  }
  else if (DAT_0099cdc8 == param_3) {
    if (param_2 == (float *)0x0) {
      param_1[0xe] = 0.0;
      param_1[0xd] = 0.0;
      param_1[0xc] = 0.0;
      param_1[0xb] = 0.0;
      param_1[9] = 0.0;
      param_1[8] = 0.0;
      param_1[7] = 0.0;
      param_1[6] = 0.0;
      param_1[4] = 0.0;
      param_1[3] = 0.0;
      param_1[2] = 0.0;
      param_1[1] = 0.0;
      *param_1 = *param_4;
      fVar1 = param_4[1];
      param_1[10] = 1.0;
      param_1[5] = fVar1;
    }
    else {
      param_1[0xb] = 0.0;
      param_1[9] = 0.0;
      param_1[8] = 0.0;
      param_1[7] = 0.0;
      param_1[6] = 0.0;
      param_1[4] = 0.0;
      param_1[3] = 0.0;
      param_1[2] = 0.0;
      param_1[1] = 0.0;
      *param_1 = *param_4;
      fVar1 = param_4[1];
      param_1[10] = 1.0;
      param_1[5] = fVar1;
      param_1[0xc] = (1.0 - *param_4) * *param_2;
      param_1[0xd] = (1.0 - param_4[1]) * param_2[1];
      param_1[0xe] = 0.0;
    }
    param_1[0xf] = 1.0;
  }
  else {
    local_18 = 0;
    local_50[0] = *param_4;
    local_1c = 0;
    local_50[5] = param_4[1];
    local_20 = 0;
    local_24 = 0;
    local_2c = 0;
    local_30 = 0;
    local_34 = 0;
    local_38 = 0;
    local_50[4] = 0.0;
    local_50[3] = 0.0;
    local_50[2] = 0.0;
    local_50[1] = 0.0;
    local_28 = 0x3f800000;
    local_14 = 0x3f800000;
    thunk_FUN_0079f9c8(local_90,param_3);
    if (param_2 == (float *)0x0) {
      thunk_FUN_0079f0cc(param_1,local_90);
      thunk_FUN_0079ee7b(param_1,param_1,local_50);
      thunk_FUN_0079ee7b(param_1,param_1,local_90);
    }
    else {
      thunk_FUN_0079f0cc(local_d0,local_90);
      param_1[0xe] = 0.0;
      param_1[0xd] = 0.0;
      param_1[0xc] = 0.0;
      param_1[0xb] = 0.0;
      param_1[9] = 0.0;
      param_1[8] = 0.0;
      param_1[7] = 0.0;
      param_1[6] = 0.0;
      param_1[4] = 0.0;
      param_1[3] = 0.0;
      param_1[2] = 0.0;
      param_1[1] = 0.0;
      param_1[0xf] = 1.0;
      param_1[10] = 1.0;
      param_1[5] = 1.0;
      *param_1 = 1.0;
      param_1[0xc] = -*param_2;
      param_1[0xd] = -param_2[1];
      thunk_FUN_0079ee7b(param_1,param_1,local_d0);
      thunk_FUN_0079ee7b(param_1,param_1,local_50);
      thunk_FUN_0079ee7b(param_1,param_1,local_90);
      param_1[0xc] = *param_2 + param_1[0xc];
      param_1[0xd] = param_2[1] + param_1[0xd];
    }
  }
  if (DAT_0099cdc8 != param_6) {
    thunk_FUN_0079f9c8(local_90,param_6);
    if (param_5 == (float *)0x0) {
      thunk_FUN_0079ee7b(param_1,param_1,local_90);
    }
    else {
      param_1[0xc] = param_1[0xc] - *param_5;
      param_1[0xd] = param_1[0xd] - param_5[1];
      thunk_FUN_0079ee7b(param_1,param_1,local_90);
      param_1[0xc] = *param_5 + param_1[0xc];
      param_1[0xd] = param_5[1] + param_1[0xd];
    }
  }
  if (param_7 != (float *)0x0) {
    param_1[0xc] = *param_7 + param_1[0xc];
    param_1[0xd] = param_7[1] + param_1[0xd];
  }
  return param_1;
}


// ==== FUN_007a030e @ 0x007a030e ====

void FUN_007a030e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a38)(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_007a0337 @ 0x007a0337 ====

undefined4 *
FUN_007a0337(undefined4 *param_1,undefined4 param_2,float *param_3,int param_4,float *param_5)

{
  undefined1 local_50 [64];
  
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = param_2;
  param_1[5] = param_2;
  param_1[10] = param_2;
  param_1[0xf] = 0x3f800000;
  if (param_4 != 0) {
    thunk_FUN_0079fb96(local_50,param_4);
    if (param_3 == (float *)0x0) {
      thunk_FUN_0079ee7b(param_1,param_1,local_50);
    }
    else {
      param_1[0xc] = (float)param_1[0xc] - *param_3;
      param_1[0xd] = (float)param_1[0xd] - param_3[1];
      param_1[0xe] = (float)param_1[0xe] - param_3[2];
      thunk_FUN_0079ee7b(param_1,param_1,local_50);
      param_1[0xc] = *param_3 + (float)param_1[0xc];
      param_1[0xd] = (float)param_1[0xd] + param_3[1];
      param_1[0xe] = param_3[2] + (float)param_1[0xe];
    }
  }
  if (param_5 != (float *)0x0) {
    param_1[0xc] = *param_5 + (float)param_1[0xc];
    param_1[0xd] = param_5[1] + (float)param_1[0xd];
    param_1[0xe] = param_5[2] + (float)param_1[0xe];
  }
  return param_1;
}


// ==== FUN_007a0427 @ 0x007a0427 ====

void FUN_007a0427(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44ab4)(param_1,param_2,param_3,param_4,param_5);
  return;
}


// ==== FUN_007a0454 @ 0x007a0454 ====

undefined4 *
FUN_007a0454(undefined4 *param_1,undefined4 param_2,float *param_3,float param_4,float *param_5)

{
  undefined1 local_50 [64];
  
  param_1[0xe] = 0;
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  param_1[0xb] = 0;
  param_1[9] = 0;
  param_1[8] = 0;
  param_1[7] = 0;
  param_1[6] = 0;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = param_2;
  param_1[5] = param_2;
  param_1[10] = 0x3f800000;
  param_1[0xf] = 0x3f800000;
  if (DAT_0099cdc8 != param_4) {
    thunk_FUN_0079f9c8(local_50,param_4);
    if (param_3 == (float *)0x0) {
      thunk_FUN_0079ee7b(param_1,param_1,local_50);
    }
    else {
      param_1[0xc] = (float)param_1[0xc] - *param_3;
      param_1[0xd] = (float)param_1[0xd] - param_3[1];
      thunk_FUN_0079ee7b(param_1,param_1,local_50);
      param_1[0xc] = *param_3 + (float)param_1[0xc];
      param_1[0xd] = (float)param_1[0xd] + param_3[1];
    }
  }
  if (param_5 != (float *)0x0) {
    param_1[0xc] = *param_5 + (float)param_1[0xc];
    param_1[0xd] = param_5[1] + (float)param_1[0xd];
  }
  return param_1;
}


// ==== FUN_007a053b @ 0x007a053b ====

void FUN_007a053b(float *param_1,float *param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_10 = *param_3 - *param_2;
  local_c = param_3[1] - param_2[1];
  local_8 = param_3[2] - param_2[2];
  thunk_FUN_0079e1ba(&local_10,&local_10);
  local_1c = local_8 * param_4[1] - local_c * param_4[2];
  local_18 = local_10 * param_4[2] - local_8 * *param_4;
  local_14 = local_c * *param_4 - local_10 * param_4[1];
  thunk_FUN_0079e1ba(&local_1c,&local_1c);
  param_1[4] = local_18;
  param_1[8] = local_14;
  fVar4 = local_c * local_14 - local_8 * local_18;
  fVar5 = local_8 * local_1c - local_10 * local_14;
  fVar6 = local_10 * local_18 - local_c * local_1c;
  *param_1 = local_1c;
  fVar1 = param_2[1];
  fVar2 = *param_2;
  fVar3 = param_2[2];
  param_1[1] = fVar4;
  param_1[5] = fVar5;
  param_1[9] = fVar6;
  param_1[0xc] = -(local_14 * fVar3 + local_1c * fVar2 + local_18 * fVar1);
  fVar1 = param_2[1];
  fVar2 = *param_2;
  fVar3 = param_2[2];
  param_1[2] = local_10;
  param_1[6] = local_c;
  param_1[10] = local_8;
  param_1[0xd] = -(fVar6 * fVar3 + fVar4 * fVar2 + fVar5 * fVar1);
  param_1[0xe] = -(local_8 * param_2[2] + local_10 * *param_2 + local_c * param_2[1]);
  param_1[3] = 0.0;
  param_1[7] = 0.0;
  param_1[0xb] = 0.0;
  param_1[0xf] = 1.0;
  return;
}


// ==== FUN_007a0693 @ 0x007a0693 ====

void FUN_007a0693(float *param_1,float param_2,float param_3,float param_4,float param_5)

{
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)fcos((float10)(param_2 * DAT_0099d0b4));
  fVar2 = (float10)fsin((float10)(param_2 * DAT_0099d0b4));
  *param_1 = ((float)fVar1 / (float)fVar2) / param_3;
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  param_1[3] = 0.0;
  param_1[4] = 0.0;
  param_1[5] = (float)fVar1 / (float)fVar2;
  param_1[6] = 0.0;
  param_1[7] = 0.0;
  param_1[8] = 0.0;
  param_1[9] = 0.0;
  param_5 = param_5 / (param_5 - param_4);
  param_1[10] = param_5;
  param_1[0xb] = 1.0;
  param_1[0xc] = 0.0;
  param_1[0xd] = 0.0;
  param_1[0xe] = -(param_5 * param_4);
  param_1[0xf] = 0.0;
  return;
}


// ==== FUN_007a0729 @ 0x007a0729 ====

void FUN_007a0729(float *param_1,float param_2,float param_3,float param_4,float param_5)

{
  float fVar1;
  
  *param_1 = DAT_0099d0f8 / param_2;
  param_1[1] = 0.0;
  param_1[2] = 0.0;
  param_1[3] = 0.0;
  param_1[4] = 0.0;
  param_1[5] = DAT_0099d0f8 / param_3;
  param_1[6] = 0.0;
  param_1[7] = 0.0;
  param_1[8] = 0.0;
  param_1[9] = 0.0;
  fVar1 = DAT_0099d080 / (param_5 - param_4);
  param_1[10] = fVar1;
  param_1[0xb] = 0.0;
  param_1[0xc] = 0.0;
  param_1[0xd] = 0.0;
  param_1[0xe] = -(fVar1 * param_4);
  param_1[0xf] = 1.0;
  return;
}


// ==== FUN_007a079f @ 0x007a079f ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a079f(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a07ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a00)();
  return;
}


// ==== FUN_007a0810 @ 0x007a0810 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a0810(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a081d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449f4)();
  return;
}


// ==== FUN_007a095f @ 0x007a095f ====

void FUN_007a095f(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a08)(param_1,param_2,param_3);
  return;
}


// ==== FUN_007a09e6 @ 0x007a09e6 ====

void FUN_007a09e6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b449f8)(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_007a0af7 @ 0x007a0af7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a0af7(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a0b04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449e0)();
  return;
}


// ==== FUN_007a0ba8 @ 0x007a0ba8 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a0ba8(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a0bb5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449e4)();
  return;
}


// ==== FUN_007a0bbb @ 0x007a0bbb ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a0bbb(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a0bc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a44)();
  return;
}


// ==== FUN_007a0c87 @ 0x007a0c87 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a0c87(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a0c94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a70)();
  return;
}


// ==== FUN_007a0d1d @ 0x007a0d1d ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a0d1d(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a0d2a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a74)();
  return;
}


// ==== FUN_007a0dd0 @ 0x007a0dd0 ====

void FUN_007a0dd0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a20)(param_1,param_2,param_3,param_4);
  return;
}


// ==== FUN_007a0ee1 @ 0x007a0ee1 ====

void FUN_007a0ee1(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  FUN_007a3599(1);
  (*(code *)PTR_FUN_00b44a40)(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}


// ==== FUN_007a0f0d @ 0x007a0f0d ====

undefined4
FUN_007a0f0d(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,float param_6)

{
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  thunk_FUN_007a0dd0(local_24,param_2,param_5,param_6);
  thunk_FUN_007a0dd0(local_14,param_3,param_4,param_6);
  param_6 = (1.0 - param_6) * param_6;
  thunk_FUN_007a0dd0(param_1,local_24,local_14,param_6 + param_6);
  return param_1;
}


// ==== FUN_007a0f66 @ 0x007a0f66 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a0f66(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a0f73. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a48)();
  return;
}


// ==== FUN_007a0faa @ 0x007a0faa ====

undefined4 *
FUN_007a0faa(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            float param_5,float param_6)

{
  int iVar1;
  undefined1 local_24 [16];
  undefined1 local_14 [16];
  
  param_5 = param_5 + param_6;
  iVar1 = FUN_0079dcc8(param_5,0);
  if (iVar1 == 0) {
    thunk_FUN_007a0dd0(local_24,param_2,param_3,param_5);
    thunk_FUN_007a0dd0(local_14,param_2,param_4,param_5);
    thunk_FUN_007a0dd0(param_1,local_24,local_14,param_6 / param_5);
  }
  else if (param_1 != param_2) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
  }
  return param_1;
}


// ==== FUN_007a1034 @ 0x007a1034 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a1034(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a1041. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449e8)();
  return;
}


// ==== FUN_007a10f0 @ 0x007a10f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a10f0(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a10fd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449ec)();
  return;
}


// ==== FUN_007a11b9 @ 0x007a11b9 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a11b9(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a11c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449c4)();
  return;
}


// ==== FUN_007a1207 @ 0x007a1207 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a1207(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a1214. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b449c8)();
  return;
}


// ==== FUN_007a12be @ 0x007a12be ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a12be(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a12cb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44a1c)();
  return;
}


// ==== FUN_007a1372 @ 0x007a1372 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a1372(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a137f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44aa4)();
  return;
}


// ==== FUN_007a1446 @ 0x007a1446 ====

float10 FUN_007a1446(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  float10 extraout_ST0;
  float10 fVar16;
  float10 extraout_ST0_00;
  float10 fVar17;
  float10 extraout_ST0_01;
  float10 fVar18;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 fVar19;
  float10 fVar20;
  float10 fVar21;
  
  uVar11 = __ftol();
  fVar16 = (float10)DAT_0099d080;
  uVar12 = __ftol();
  fVar17 = extraout_ST0_00 - (float10)(int)uVar12;
  uVar12 = uVar12 & 0xff;
  uVar15 = uVar12 + 1 & 0xff;
  fVar4 = (float)(fVar17 - (float10)DAT_0099d080);
  fVar21 = extraout_ST1;
  uVar13 = __ftol();
  uVar14 = uVar13 & 0xff;
  fVar18 = extraout_ST0_01 - (float10)(int)uVar13;
  uVar13 = uVar14 + 1 & 0xff;
  fVar5 = (float)fVar18;
  fVar6 = (float)(fVar18 - (float10)DAT_0099d080);
  fVar7 = (float)(((float10)DAT_009b0300 - (fVar21 + fVar21)) * fVar21 * fVar21);
  fVar8 = (float)(((float10)DAT_009b0300 - (extraout_ST1_00 + extraout_ST1_00)) * extraout_ST1_00 *
                 extraout_ST1_00);
  iVar1 = (*(int *)(&DAT_009fa778 + (*(int *)(&DAT_009fa778 + (uVar11 & 0xff) * 4) + uVar12) * 4) +
          uVar14) * 0xc;
  fVar19 = fVar21 * (float10)*(float *)(&DAT_009faf80 + iVar1) +
           extraout_ST1_00 * (float10)*(float *)(&DAT_009faf84 + iVar1) +
           fVar18 * (float10)*(float *)(&DAT_009faf88 + iVar1);
  iVar1 = (*(int *)(&DAT_009fa778 +
                   (uVar12 + *(int *)(&DAT_009fa778 + ((uVar11 & 0xff) + 1 & 0xff) * 4)) * 4) +
          uVar14) * 0xc;
  iVar2 = (*(int *)(&DAT_009fa778 + (*(int *)(&DAT_009fa778 + (uVar11 & 0xff) * 4) + uVar15) * 4) +
          uVar14) * 0xc;
  iVar3 = (uVar14 + *(int *)(&DAT_009fa778 +
                            (*(int *)(&DAT_009fa778 + ((uVar11 & 0xff) + 1 & 0xff) * 4) + uVar15) *
                            4)) * 0xc;
  fVar19 = ((fVar17 * (float10)*(float *)(&DAT_009faf80 + iVar1) +
            extraout_ST1_00 * (float10)*(float *)(&DAT_009faf84 + iVar1) +
            fVar18 * (float10)*(float *)(&DAT_009faf88 + iVar1)) - fVar19) * (float10)fVar7 + fVar19
  ;
  fVar20 = fVar21 * (float10)*(float *)(&DAT_009faf80 + iVar2) +
           (float10)fVar4 * (float10)*(float *)(&DAT_009faf84 + iVar2) +
           fVar18 * (float10)*(float *)(&DAT_009faf88 + iVar2);
  iVar1 = (*(int *)(&DAT_009fa778 + (*(int *)(&DAT_009fa778 + (uVar11 & 0xff) * 4) + uVar12) * 4) +
          uVar13) * 0xc;
  fVar9 = (float)(((((fVar17 * (float10)*(float *)(&DAT_009faf80 + iVar3) +
                     (float10)fVar4 * (float10)*(float *)(&DAT_009faf84 + iVar3) +
                     fVar18 * (float10)*(float *)(&DAT_009faf88 + iVar3)) - fVar20) * (float10)fVar7
                   + fVar20) - fVar19) * (float10)fVar8 + fVar19);
  fVar18 = fVar21 * (float10)*(float *)(&DAT_009faf80 + iVar1) +
           extraout_ST1_00 * (float10)*(float *)(&DAT_009faf84 + iVar1) +
           (float10)fVar6 * (float10)*(float *)(&DAT_009faf88 + iVar1);
  iVar1 = (*(int *)(&DAT_009fa778 +
                   (uVar12 + *(int *)(&DAT_009fa778 + ((uVar11 & 0xff) + 1 & 0xff) * 4)) * 4) +
          uVar13) * 0xc;
  iVar2 = (*(int *)(&DAT_009fa778 + (*(int *)(&DAT_009fa778 + (uVar11 & 0xff) * 4) + uVar15) * 4) +
          uVar13) * 0xc;
  iVar3 = (uVar13 + *(int *)(&DAT_009fa778 +
                            (*(int *)(&DAT_009fa778 + ((uVar11 & 0xff) + 1 & 0xff) * 4) + uVar15) *
                            4)) * 0xc;
  fVar10 = (float)(((fVar17 * (float10)*(float *)(&DAT_009faf80 + iVar1) +
                    extraout_ST1_00 * (float10)*(float *)(&DAT_009faf84 + iVar1) +
                    (float10)fVar6 * (float10)*(float *)(&DAT_009faf88 + iVar1)) - fVar18) *
                   (float10)fVar7 + fVar18);
  fVar21 = fVar21 * (float10)*(float *)(&DAT_009faf80 + iVar2) +
           (float10)fVar4 * (float10)*(float *)(&DAT_009faf84 + iVar2) +
           (float10)fVar6 * (float10)*(float *)(&DAT_009faf88 + iVar2);
  return (((float10)DAT_009b0300 - ((float10)fVar5 + (float10)fVar5)) * (float10)fVar5 *
          (float10)fVar5 *
          (((((((float10)(float)((extraout_ST0 - (float10)(int)uVar11) - fVar16) *
                (float10)*(float *)(&DAT_009faf80 + iVar3) +
               (float10)fVar4 * (float10)*(float *)(&DAT_009faf84 + iVar3) +
               (float10)fVar6 * (float10)*(float *)(&DAT_009faf88 + iVar3)) - fVar21) *
              (float10)fVar7 + fVar21) - (float10)fVar10) * (float10)fVar8 + (float10)fVar10) -
          (float10)fVar9) + (float10)fVar9) * (float10)DAT_009a000c;
}


// ==== FUN_007a16b1 @ 0x007a16b1 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a16b1(void)

{
  FUN_007a3599(1);
                    /* WARNING: Could not recover jumptable at 0x007a16be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*_DAT_00b44aa8)();
  return;
}


// ==== FUN_007a1763 @ 0x007a1763 ====

void FUN_007a1763(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  fVar1 = param_3[1];
  fVar2 = *param_2;
  fVar3 = param_3[5];
  fVar4 = param_2[1];
  fVar5 = param_3[0xd];
  fVar6 = param_3[2];
  fVar7 = *param_2;
  fVar8 = param_3[6];
  fVar9 = param_2[1];
  fVar10 = param_3[0xe];
  fVar11 = param_3[3];
  fVar12 = *param_2;
  fVar13 = param_3[7];
  fVar14 = param_2[1];
  fVar15 = param_3[0xf];
  *param_1 = *param_2 * *param_3 + param_3[4] * param_2[1] + param_3[0xc];
  param_1[1] = fVar3 * fVar4 + fVar1 * fVar2 + fVar5;
  param_1[2] = fVar8 * fVar9 + fVar6 * fVar7 + fVar10;
  param_1[3] = fVar13 * fVar14 + fVar11 * fVar12 + fVar15;
  return;
}


// ==== FUN_007a17d0 @ 0x007a17d0 ====

float * FUN_007a17d0(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float *pfVar18;
  
  if (param_6 != 0) {
    pfVar18 = param_1;
    do {
      pfVar1 = param_3 + 1;
      fVar2 = *param_3;
      fVar3 = param_5[1];
      fVar4 = *param_3;
      fVar5 = param_5[5];
      fVar6 = param_3[1];
      fVar7 = param_5[0xd];
      fVar8 = param_5[2];
      fVar9 = *param_3;
      fVar10 = param_5[6];
      fVar11 = param_3[1];
      fVar12 = param_5[0xe];
      fVar13 = *param_3;
      fVar14 = param_5[3];
      fVar15 = param_3[1];
      param_3 = (float *)((int)param_3 + param_4);
      param_6 = param_6 + -1;
      fVar16 = param_5[7];
      fVar17 = param_5[0xf];
      *pfVar18 = fVar2 * *param_5 + param_5[4] * *pfVar1 + param_5[0xc];
      pfVar18[1] = fVar5 * fVar6 + fVar3 * fVar4 + fVar7;
      pfVar18[2] = fVar10 * fVar11 + fVar8 * fVar9 + fVar12;
      pfVar18[3] = fVar15 * fVar16 + fVar13 * fVar14 + fVar17;
      pfVar18 = (float *)((int)pfVar18 + param_2);
    } while (param_6 != 0);
  }
  return param_1;
}


// ==== FUN_007a1855 @ 0x007a1855 ====

void FUN_007a1855(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  
  fVar1 = *param_2;
  fVar2 = param_3[1];
  fVar3 = param_2[1];
  fVar4 = param_3[5];
  fVar5 = param_3[0xd];
  fVar6 = param_3[0xf] + param_2[1] * param_3[7] + *param_2 * param_3[3];
  *param_1 = param_3[0xc] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar5 + fVar3 * fVar4 + fVar1 * fVar2;
  iVar7 = FUN_0079dcc8(fVar6,0x3f800000);
  if (iVar7 == 0) {
    fVar6 = 1.0 / fVar6;
    *param_1 = fVar6 * *param_1;
    param_1[1] = fVar6 * param_1[1];
  }
  return;
}


// ==== FUN_007a18d4 @ 0x007a18d4 ====

float * FUN_007a18d4(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float *extraout_ECX;
  float *pfVar7;
  undefined8 uVar8;
  
  if (param_6 != 0) {
    pfVar7 = param_1;
    do {
      fVar1 = param_5[1];
      fVar2 = *param_3;
      fVar3 = param_5[5];
      fVar4 = param_3[1];
      fVar5 = param_5[0xd];
      fVar6 = param_5[7] * param_3[1] + param_5[3] * *param_3 + param_5[0xf];
      *pfVar7 = *param_3 * *param_5 + param_5[4] * param_3[1] + param_5[0xc];
      pfVar7[1] = fVar3 * fVar4 + fVar1 * fVar2 + fVar5;
      uVar8 = FUN_0079dcc8(fVar6,0x3f800000);
      if ((int)uVar8 == 0) {
        fVar6 = 1.0 / fVar6;
        *pfVar7 = fVar6 * *pfVar7;
        pfVar7[1] = fVar6 * pfVar7[1];
      }
      param_3 = (float *)((int)((ulonglong)uVar8 >> 0x20) + param_4);
      pfVar7 = (float *)((int)pfVar7 + param_2);
      param_6 = param_6 + -1;
      param_5 = extraout_ECX;
    } while (param_6 != 0);
  }
  return param_1;
}


// ==== FUN_007a196e @ 0x007a196e ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a196e(float *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float local_10;
  float local_c;
  float local_8;
  
  fVar2 = param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  iVar3 = FUN_0079dcc8(fVar2,0x3f800000);
  if (iVar3 == 0) {
    if (fVar2 <= _DAT_009fc7a4) {
      *param_1 = 0.0;
      param_1[1] = 0.0;
      param_1[2] = 0.0;
      return;
    }
    fVar2 = DAT_0099d080 / SQRT(fVar2);
    local_10 = fVar2 * *param_2;
    local_c = fVar2 * param_2[1];
    pfVar1 = param_2 + 2;
    param_2 = &local_10;
    local_8 = fVar2 * *pfVar1;
  }
  else if (param_1 == param_2) {
    return;
  }
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  return;
}


// ==== FUN_007a1a0d @ 0x007a1a0d ====

void FUN_007a1a0d(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  int iVar16;
  
  fVar1 = *param_2;
  fVar2 = param_3[2];
  fVar3 = *param_2;
  fVar4 = param_3[1];
  fVar5 = param_2[1];
  fVar6 = param_3[6];
  fVar7 = param_2[1];
  fVar8 = param_3[5];
  fVar9 = param_2[2];
  fVar10 = param_3[10];
  fVar11 = param_2[2];
  fVar12 = param_3[9];
  fVar13 = param_3[0xd];
  fVar14 = param_3[0xe];
  fVar15 = param_3[0xf] +
           param_2[2] * param_3[0xb] + param_2[1] * param_3[7] + *param_2 * param_3[3];
  *param_1 = param_3[0xc] + param_2[2] * param_3[8] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar13 + fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4;
  param_1[2] = fVar14 + fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2;
  iVar16 = FUN_0079dcc8(fVar15,0x3f800000);
  if (iVar16 == 0) {
    fVar15 = 1.0 / fVar15;
    *param_1 = fVar15 * *param_1;
    param_1[1] = fVar15 * param_1[1];
    param_1[2] = fVar15 * param_1[2];
  }
  return;
}


// ==== FUN_007a1acb @ 0x007a1acb ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_007a1acb(float *param_1,undefined4 param_2,int *param_3,undefined4 *param_4,
                    undefined4 *param_5,undefined4 *param_6)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  puVar3 = &local_60;
  switch(((param_6 != (undefined4 *)0x0) << 1 | param_5 != (undefined4 *)0x0) << 1 |
         param_4 != (undefined4 *)0x0) {
  case '\0':
    local_28 = 0;
    local_2c = 0;
    local_30 = 0;
    local_34 = 0;
    local_3c = 0;
    local_40 = 0;
    local_44 = 0;
    local_48 = 0;
    local_50 = 0;
    local_54 = 0;
    local_58 = 0;
    local_5c = 0;
    local_24 = 0x3f800000;
    local_38 = 0x3f800000;
    local_4c = 0x3f800000;
    local_60 = 0x3f800000;
    break;
  case '\x01':
    puVar3 = param_4;
    break;
  case '\x02':
    puVar3 = param_5;
    break;
  case '\x03':
    param_6 = param_5;
    goto LAB_007a1b98;
  case '\x04':
    puVar3 = param_6;
    break;
  case '\x05':
    goto LAB_007a1b98;
  case '\x06':
    param_4 = param_5;
    goto LAB_007a1b98;
  case '\a':
    thunk_FUN_0079ee7b(&local_60,param_6,param_5);
    param_6 = &local_60;
LAB_007a1b98:
    thunk_FUN_0079ee7b(&local_60,param_6,param_4);
  }
  thunk_FUN_0079e5a0(param_1,param_2,puVar3);
  if (param_3 != (int *)0x0) {
    fVar2 = (float)param_3[2];
    if (param_3[2] < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar1 = (float)*param_3;
    if (*param_3 < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    *param_1 = fVar1 + fVar2 * (*param_1 + DAT_0099d080) * DAT_0099d0b4;
    fVar2 = (float)param_3[3];
    if (param_3[3] < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar1 = (float)param_3[1];
    if (param_3[1] < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    param_1[1] = fVar1 + fVar2 * (1.0 - param_1[1]) * DAT_0099d0b4;
    param_1[2] = ((float)param_3[5] - (float)param_3[4]) * param_1[2] + (float)param_3[4];
  }
  return param_1;
}


// ==== FUN_007a21fa @ 0x007a21fa ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a21fa(float *param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  fVar2 = param_2[3] * param_2[3] +
          param_2[2] * param_2[2] + param_2[1] * param_2[1] + *param_2 * *param_2;
  iVar3 = FUN_0079dcc8(fVar2,0x3f800000);
  if (iVar3 == 0) {
    if (fVar2 <= _DAT_009fc7a4) {
      *param_1 = 0.0;
      param_1[1] = 0.0;
      param_1[2] = 0.0;
      param_1[3] = 0.0;
      return;
    }
    fVar2 = DAT_0099d080 / SQRT(fVar2);
    local_14 = fVar2 * *param_2;
    local_10 = fVar2 * param_2[1];
    local_c = fVar2 * param_2[2];
    pfVar1 = param_2 + 3;
    param_2 = &local_14;
    local_8 = fVar2 * *pfVar1;
  }
  else if (param_1 == param_2) {
    return;
  }
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  return;
}


// ==== FUN_007a22b2 @ 0x007a22b2 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007a22b2(float *param_1,int param_2,float *param_3,float *param_4)

{
  float **ppfVar1;
  float *pfVar2;
  float *pfVar3;
  float *pfVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  undefined4 uVar9;
  float10 fVar10;
  float local_88 [10];
  float *local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined4 local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 local_40;
  float local_3c;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  float local_18;
  float local_14;
  float *local_10 [3];
  
  local_88[0] = 1.0;
  local_88[1] = 0.0;
  local_88[2] = 0.0;
  local_88[3] = 0.0;
  local_88[4] = 1.0;
  local_88[5] = 0.0;
  local_88[6] = 0.0;
  *param_3 = param_4[0xc];
  local_24 = 0;
  local_88[7] = 0.0;
  local_28 = 0;
  local_88[8] = 1.0;
  local_2c = 0;
  param_3[1] = param_4[0xd];
  local_30 = 0;
  param_3[2] = param_4[0xe];
  local_40 = 0;
  local_10[0] = &local_5c;
  local_50 = 0;
  local_10[1] = &local_4c;
  local_20 = 0x3f800000;
  local_5c = *param_4;
  local_58 = param_4[1];
  local_54 = param_4[2];
  local_4c = param_4[4];
  local_48 = param_4[5];
  local_44 = param_4[6];
  local_3c = param_4[8];
  local_38 = param_4[9];
  local_34 = param_4[10];
  local_10[2] = &local_3c;
  fVar5 = SQRT(local_5c * local_5c + local_58 * local_58 + local_54 * local_54);
  *param_1 = fVar5;
  fVar6 = SQRT(local_4c * local_4c + local_48 * local_48 + local_44 * local_44);
  param_1[1] = fVar6;
  fVar7 = SQRT(local_3c * local_3c + local_38 * local_38 + local_34 * local_34);
  param_1[2] = fVar7;
  if (fVar6 <= fVar5) {
    if (fVar7 <= fVar5) {
      iVar8 = 0;
      if (fVar7 <= fVar6) {
        param_3 = (float *)0x2;
        goto LAB_007a2450;
      }
      param_4 = (float *)0x2;
    }
    else {
      param_4 = (float *)0x0;
      iVar8 = 2;
    }
    param_3 = (float *)0x1;
  }
  else if (fVar7 <= fVar6) {
    iVar8 = 1;
    if (fVar7 <= fVar5) {
      param_4 = (float *)0x0;
      param_3 = (float *)0x2;
    }
    else {
      param_3 = (float *)0x0;
      param_4 = (float *)0x2;
    }
  }
  else {
    param_3 = (float *)0x0;
    iVar8 = 2;
LAB_007a2450:
    param_4 = (float *)0x1;
  }
  local_60 = param_1 + iVar8;
  if (*local_60 < _DAT_009fc7b8) {
    pfVar2 = local_10[iVar8];
    *pfVar2 = local_88[iVar8 * 3];
    pfVar2[1] = local_88[iVar8 * 3 + 1];
    pfVar2[2] = local_88[iVar8 * 3 + 2];
  }
  ppfVar1 = local_10 + iVar8;
  thunk_FUN_0079e1ba(*ppfVar1,*ppfVar1);
  if (_DAT_009fc7b8 <= param_1[(int)param_4]) goto LAB_007a254e;
  pfVar2 = *ppfVar1;
  fVar5 = ABS(*pfVar2);
  local_88[9] = ABS(pfVar2[1]);
  fVar6 = ABS(pfVar2[2]);
  if (local_88[9] <= fVar5) {
    if ((fVar6 <= fVar5) && (fVar6 <= local_88[9])) goto LAB_007a2508;
    iVar8 = 1;
  }
  else if ((local_88[9] < fVar6) || (fVar5 < fVar6)) {
    iVar8 = 0;
  }
  else {
LAB_007a2508:
    iVar8 = 2;
  }
  pfVar3 = local_10[(int)param_4];
  local_1c = local_88[iVar8 * 3 + 2] * pfVar2[1] - pfVar2[2] * local_88[iVar8 * 3 + 1];
  local_18 = pfVar2[2] * local_88[iVar8 * 3] - *pfVar2 * local_88[iVar8 * 3 + 2];
  local_14 = *pfVar2 * local_88[iVar8 * 3 + 1] - local_88[iVar8 * 3] * pfVar2[1];
  *pfVar3 = local_1c;
  pfVar3[1] = local_18;
  pfVar3[2] = local_14;
LAB_007a254e:
  pfVar2 = local_10[(int)param_4];
  thunk_FUN_0079e1ba(pfVar2,pfVar2);
  if (param_1[(int)param_3] < _DAT_009fc7b8) {
    pfVar2 = local_10[(int)param_4];
    pfVar3 = *ppfVar1;
    pfVar4 = local_10[(int)param_3];
    local_1c = pfVar2[2] * pfVar3[1] - pfVar3[2] * pfVar2[1];
    local_18 = *pfVar2 * pfVar3[2] - pfVar2[2] * *pfVar3;
    local_14 = pfVar2[1] * *pfVar3 - *pfVar2 * pfVar3[1];
    *pfVar4 = local_1c;
    pfVar4[1] = local_18;
    pfVar4[2] = local_14;
  }
  thunk_FUN_0079e1ba(local_10[(int)param_3],local_10[(int)param_3]);
  fVar10 = (float10)thunk_FUN_0079ed83(&local_5c);
  if (fVar10 < (float10)DAT_0099cdc8) {
    pfVar2 = *ppfVar1;
    *local_60 = -*local_60;
    local_1c = -*pfVar2;
    local_18 = -pfVar2[1];
    local_14 = -pfVar2[2];
    *pfVar2 = local_1c;
    pfVar2[1] = local_18;
    fVar10 = -fVar10;
    pfVar2[2] = local_14;
  }
  if ((fVar10 - (float10)DAT_0099d080) * (fVar10 - (float10)DAT_0099d080) <= (float10)_DAT_009fc7b8)
  {
    thunk_FUN_007a0810(param_2,&local_5c);
    uVar9 = 0;
    *(float *)(param_2 + 0xc) = -*(float *)(param_2 + 0xc);
  }
  else {
    uVar9 = 0x8876086c;
  }
  return uVar9;
}


// ==== FUN_007a2642 @ 0x007a2642 ====

undefined4 FUN_007a2642(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_14 [16];
  
  thunk_FUN_007a09e6(local_14,param_2,param_3,param_4);
  thunk_FUN_0079fb96(param_1,local_14);
  return param_1;
}


// ==== FUN_007a267d @ 0x007a267d ====

void FUN_007a267d(float *param_1,float *param_2,undefined4 param_3)

{
  float fVar1;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  thunk_FUN_007a1034(&local_14,param_3);
  fVar1 = local_c * param_2[2] + local_8 * param_2[3] + local_14 * *param_2 + local_10 * param_2[1];
  local_14 = -local_14;
  local_10 = -local_10;
  local_c = -local_c;
  local_8 = -local_8;
  *param_1 = local_14 * *param_2 + fVar1;
  param_1[4] = local_10 * *param_2;
  param_1[8] = local_c * *param_2;
  param_1[0xc] = local_8 * *param_2;
  param_1[1] = local_14 * param_2[1];
  param_1[5] = local_10 * param_2[1] + fVar1;
  param_1[9] = local_c * param_2[1];
  param_1[0xd] = local_8 * param_2[1];
  param_1[2] = local_14 * param_2[2];
  param_1[6] = local_10 * param_2[2];
  param_1[10] = local_c * param_2[2] + fVar1;
  param_1[0xe] = local_8 * param_2[2];
  param_1[3] = local_14 * param_2[3];
  param_1[7] = local_10 * param_2[3];
  param_1[0xb] = local_c * param_2[3];
  param_1[0xf] = local_8 * param_2[3] + fVar1;
  return;
}


// ==== FUN_007a277b @ 0x007a277b ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a277b(float *param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  thunk_FUN_007a1034(&local_14,param_2);
  fVar4 = DAT_0099d080;
  fVar1 = local_14 * _DAT_009fc7bc;
  fVar3 = local_10 * _DAT_009fc7bc;
  fVar2 = local_c * _DAT_009fc7bc;
  *param_1 = local_14 * fVar1 + DAT_0099d080;
  param_1[1] = fVar3 * local_14;
  param_1[2] = fVar2 * local_14;
  param_1[3] = 0.0;
  param_1[4] = local_10 * fVar1;
  param_1[5] = local_10 * fVar3 + fVar4;
  param_1[6] = fVar2 * local_10;
  param_1[7] = 0.0;
  param_1[8] = local_c * fVar1;
  param_1[9] = local_c * fVar3;
  param_1[10] = local_c * fVar2 + fVar4;
  param_1[0xb] = 0.0;
  param_1[0xc] = local_8 * fVar1;
  param_1[0xd] = local_8 * fVar3;
  param_1[0xe] = local_8 * fVar2;
  param_1[0xf] = 1.0;
  return;
}


// ==== FUN_007a283c @ 0x007a283c ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a283c(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                 float *param_6,float *param_7)

{
  undefined1 local_a4 [16];
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float fStack_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_84 = *param_4;
  local_80 = param_4[1];
  local_7c = param_4[2];
  local_78 = param_4[3];
  local_54 = *param_5;
  local_50 = param_5[1];
  local_4c = param_5[2];
  local_48 = param_5[3];
  local_24 = *param_6;
  local_20 = param_6[1];
  local_1c = param_6[2];
  local_18 = param_6[3];
  local_74 = *param_7;
  local_70 = param_7[1];
  local_6c = param_7[2];
  local_68 = param_7[3];
  if ((local_54 + local_84) * (local_54 + local_84) +
      (local_50 + local_80) * (local_50 + local_80) +
      (local_4c + local_7c) * (local_4c + local_7c) + (local_48 + local_78) * (local_48 + local_78)
      < (local_84 - local_54) * (local_84 - local_54) +
        (local_80 - local_50) * (local_80 - local_50) +
        (local_7c - local_4c) * (local_7c - local_4c) +
        (local_78 - local_48) * (local_78 - local_48)) {
    local_84 = -local_84;
    local_80 = -local_80;
    local_7c = -local_7c;
    local_78 = -local_78;
    local_34 = local_84;
    local_30 = local_80;
    local_2c = local_7c;
    local_28 = local_78;
  }
  if ((local_24 + local_54) * (local_24 + local_54) +
      (local_20 + local_50) * (local_20 + local_50) +
      (local_1c + local_4c) * (local_1c + local_4c) + (local_18 + local_48) * (local_18 + local_48)
      < (local_54 - local_24) * (local_54 - local_24) +
        (local_50 - local_20) * (local_50 - local_20) +
        (local_4c - local_1c) * (local_4c - local_1c) +
        (local_48 - local_18) * (local_48 - local_18)) {
    local_34 = -local_24;
    local_30 = -local_20;
    local_2c = -local_1c;
    local_28 = -local_18;
    local_24 = local_34;
    local_20 = local_30;
    local_1c = local_2c;
    local_18 = local_28;
  }
  local_10 = local_20 - local_70;
  local_c = local_1c - local_6c;
  local_8 = local_18 - local_68;
  if ((local_74 + local_24) * (local_74 + local_24) +
      (local_70 + local_20) * (local_70 + local_20) +
      (local_6c + local_1c) * (local_6c + local_1c) + (local_68 + local_18) * (local_68 + local_18)
      < (local_24 - local_74) * (local_24 - local_74) +
        local_10 * local_10 + local_c * local_c + local_8 * local_8) {
    local_74 = -local_74;
    local_70 = -local_70;
    local_6c = -local_6c;
    local_68 = -local_68;
    local_34 = local_74;
    local_30 = local_70;
    local_2c = local_6c;
    local_28 = local_68;
  }
  thunk_FUN_007a0bbb(&local_34,&local_54);
  thunk_FUN_007a0af7(&local_44,&local_34,&local_84);
  local_64 = local_44;
  local_60 = local_40;
  local_5c = local_3c;
  local_58 = fStack_38;
  thunk_FUN_007a0c87(&local_94,&local_64);
  thunk_FUN_007a0af7(&local_44,&local_34,&local_24);
  local_64 = local_44;
  local_60 = local_40;
  local_5c = local_3c;
  local_58 = fStack_38;
  thunk_FUN_007a0c87(&local_14,&local_64);
  local_40 = local_90 + local_10;
  local_3c = local_8c + local_c;
  local_64 = (local_94 + local_14) * _DAT_009fc7c0;
  local_60 = local_40 * _DAT_009fc7c0;
  local_5c = local_3c * _DAT_009fc7c0;
  local_58 = (local_88 + local_8) * _DAT_009fc7c0;
  thunk_FUN_007a0d1d(local_a4,&local_64);
  thunk_FUN_007a0af7(&local_44,&local_54,local_a4);
  *param_1 = local_44;
  param_1[1] = local_40;
  param_1[2] = local_3c;
  param_1[3] = fStack_38;
  thunk_FUN_007a0bbb(&local_34,&local_24);
  thunk_FUN_007a0af7(&local_44,&local_34,&local_54);
  local_64 = local_44;
  local_60 = local_40;
  local_5c = local_3c;
  local_58 = fStack_38;
  thunk_FUN_007a0c87(&local_94,&local_64);
  thunk_FUN_007a0af7(&local_44,&local_34,&local_74);
  local_64 = local_44;
  local_60 = local_40;
  local_5c = local_3c;
  local_58 = fStack_38;
  thunk_FUN_007a0c87(&local_14,&local_64);
  local_40 = local_90 + local_10;
  local_3c = local_8c + local_c;
  local_64 = (local_94 + local_14) * _DAT_009fc7c0;
  local_60 = local_40 * _DAT_009fc7c0;
  local_5c = local_3c * _DAT_009fc7c0;
  local_58 = (local_88 + local_8) * _DAT_009fc7c0;
  thunk_FUN_007a0d1d(local_a4,&local_64);
  thunk_FUN_007a0af7(&local_44,&local_24,local_a4);
  *param_2 = local_44;
  param_2[1] = local_40;
  param_2[2] = local_3c;
  param_2[3] = fStack_38;
  *param_3 = local_24;
  param_3[1] = local_20;
  param_3[2] = local_1c;
  param_3[3] = local_18;
  return;
}


// ==== FUN_007a2c3d @ 0x007a2c3d ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a2c3d(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,uint param_5,
                 uint param_6,float *param_7,int *param_8,char *param_9,float param_10,
                 float *param_11)

{
  int *piVar1;
  undefined4 *puVar2;
  byte bVar3;
  float *pfVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  float *pfVar9;
  float fVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  float local_33c [195];
  uint local_30;
  uint local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float *local_c;
  float local_8;
  
  local_30 = (int)param_10 * 0xc;
  local_2c = (uint)((int)param_10 * 0xc != param_6);
  if (param_2 == 0) {
    param_2 = param_1;
  }
  if (param_10 == 2.8026e-45) {
    if ((*param_9 == '\0') && (param_9[1] == '\x03')) {
      local_1c = *param_7;
      local_8 = param_7[1];
      local_c = (float *)param_8[1];
      pfVar9 = (float *)*param_8;
    }
    else {
      if ((param_9[1] != '\0') || (*param_9 != '\x03')) goto LAB_007a2e2c;
      local_1c = param_7[1];
      local_8 = *param_7;
      pfVar9 = (float *)param_8[1];
      local_c = (float *)*param_8;
    }
    if (local_1c != 0.0) {
      if (param_5 == 0) {
        return;
      }
      param_7 = (float *)param_5;
      do {
        if (local_2c != 0) {
          puVar2 = (undefined4 *)((int)param_4 + param_6);
          puVar11 = param_3;
          for (uVar7 = param_6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
            *param_4 = *puVar11;
            puVar11 = puVar11 + 1;
            param_4 = param_4 + 1;
          }
          param_3 = (undefined4 *)((int)param_3 + param_6);
          puVar12 = param_4;
          for (uVar7 = param_6 & 3; param_4 = puVar2, uVar7 != 0; uVar7 = uVar7 - 1) {
            *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
            puVar11 = (undefined4 *)((int)puVar11 + 1);
            puVar12 = (undefined4 *)((int)puVar12 + 1);
          }
        }
        *pfVar9 = 0.0;
        pfVar9[1] = 0.0;
        pfVar9[2] = 0.0;
        *local_c = 0.0;
        local_c[1] = 0.0;
        local_c[2] = 0.0;
        if (DAT_0099cdc8 <= *param_11) {
          do {
            uVar7 = __ftol();
            iVar5 = (uVar7 >> 1) * 2;
            fVar10 = (float)iVar5;
            if (iVar5 < 0) {
              fVar10 = fVar10 + _DAT_0099d104;
            }
            fVar10 = *param_11 - fVar10;
            iVar5 = (uVar7 >> 1) * 0x40;
            thunk_FUN_0079e5a0(&local_18,local_1c,param_1 + iVar5);
            thunk_FUN_0079e6b3(&local_28,local_8,iVar5 + param_2);
            local_18 = local_18 * fVar10;
            param_11 = param_11 + 1;
            local_14 = local_14 * fVar10;
            local_10 = local_10 * fVar10;
            local_28 = local_28 * fVar10;
            local_24 = local_24 * fVar10;
            local_20 = local_20 * fVar10;
            *pfVar9 = local_18 + *pfVar9;
            pfVar9[1] = local_14 + pfVar9[1];
            pfVar9[2] = local_10 + pfVar9[2];
            *local_c = local_28 + *local_c;
            local_c[1] = local_24 + local_c[1];
            local_c[2] = local_20 + local_c[2];
          } while (DAT_0099cdc8 <= *param_11);
        }
        local_1c = (float)((int)local_1c + param_6);
        local_8 = (float)((int)local_8 + param_6);
        local_c = (float *)((int)local_c + param_6);
        param_11 = param_11 + 1;
        pfVar9 = (float *)((int)pfVar9 + param_6);
        param_7 = (float *)((int)param_7 - 1);
      } while (param_7 != (float *)0x0);
      return;
    }
  }
LAB_007a2e2c:
  local_c = (float *)0x0;
  if (param_5 != 0) {
    do {
      uVar7 = local_30;
      pfVar9 = local_33c;
      for (uVar8 = local_30 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *pfVar9 = 0.0;
        pfVar9 = pfVar9 + 1;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *(undefined1 *)pfVar9 = 0;
        pfVar9 = (float *)((int)pfVar9 + 1);
      }
      for (; DAT_0099cdc8 <= *param_11; param_11 = param_11 + 1) {
        uVar7 = __ftol();
        uVar7 = uVar7 >> 1;
        local_8 = (float)(int)(uVar7 * 2);
        if ((int)(uVar7 * 2) < 0) {
          local_8 = local_8 + _DAT_0099d104;
        }
        local_8 = *param_11 - local_8;
        fVar10 = 0.0;
        if (param_10 != 0.0) {
          pfVar9 = local_33c + 2;
          do {
            bVar3 = param_9[(int)fVar10];
            if (bVar3 == 0) {
              thunk_FUN_0079e5a0(&local_18,param_7[(int)fVar10],uVar7 * 0x40 + param_1);
            }
            else {
              if (bVar3 == 3) {
                iVar5 = uVar7 * 0x40 + param_2;
              }
              else {
                if (bVar3 < 6) {
                  return;
                }
                if (7 < bVar3) {
                  return;
                }
                iVar5 = uVar7 * 0x40 + param_1;
              }
              thunk_FUN_0079e6b3(&local_18,param_7[(int)fVar10],iVar5);
            }
            fVar10 = (float)((int)fVar10 + 1);
            local_18 = local_18 * local_8;
            local_14 = local_14 * local_8;
            local_10 = local_10 * local_8;
            pfVar9[-2] = local_18 + pfVar9[-2];
            pfVar9[-1] = local_14 + pfVar9[-1];
            *pfVar9 = local_10 + *pfVar9;
            pfVar9 = pfVar9 + 3;
          } while ((uint)fVar10 < (uint)param_10);
        }
      }
      if (local_2c != 0) {
        puVar2 = (undefined4 *)((int)param_4 + param_6);
        puVar11 = param_3;
        for (uVar7 = param_6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
          *param_4 = *puVar11;
          puVar11 = puVar11 + 1;
          param_4 = param_4 + 1;
        }
        param_3 = (undefined4 *)((int)param_3 + param_6);
        puVar12 = param_4;
        for (uVar7 = param_6 & 3; param_4 = puVar2, uVar7 != 0; uVar7 = uVar7 - 1) {
          *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
          puVar11 = (undefined4 *)((int)puVar11 + 1);
          puVar12 = (undefined4 *)((int)puVar12 + 1);
        }
      }
      if (param_10 != 0.0) {
        pfVar9 = local_33c;
        local_8 = param_10;
        piVar6 = param_8;
        do {
          pfVar4 = (float *)*piVar6;
          *pfVar4 = *pfVar9;
          pfVar4[1] = pfVar9[1];
          pfVar4[2] = pfVar9[2];
          *piVar6 = *piVar6 + param_6;
          piVar1 = (int *)(((int)param_7 - (int)param_8) + (int)piVar6);
          *piVar1 = *piVar1 + param_6;
          pfVar9 = pfVar9 + 3;
          piVar6 = piVar6 + 1;
          local_8 = (float)((int)local_8 + -1);
        } while (local_8 != 0.0);
      }
      param_11 = param_11 + 1;
      local_c = (float *)((int)local_c + 1);
    } while (local_c < param_5);
  }
  return;
}


// ==== FUN_007a2fb7 @ 0x007a2fb7 ====

void FUN_007a2fb7(float *param_1,float *param_2,float *param_3,float param_4,float *param_5)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  *param_5 = *param_1;
  param_5[1] = param_1[1];
  param_5[2] = param_1[2];
  *param_5 = *param_5 - *param_2;
  param_5[1] = param_5[1] - param_2[1];
  fVar3 = param_5[2] - param_2[2];
  param_5[2] = fVar3;
  fVar4 = param_5[1] * param_3[1] + *param_3 * *param_5 + fVar3 * param_3[2];
  fVar1 = *param_3;
  fVar2 = param_3[1];
  param_5[2] = fVar3 - fVar4 * param_3[2];
  fVar1 = (*param_5 - fVar4 * fVar1) * param_4;
  *param_5 = fVar1;
  fVar2 = (param_5[1] - fVar4 * fVar2) * param_4;
  param_5[1] = fVar2;
  param_5[2] = param_4 * param_5[2];
  *param_5 = fVar1 + *param_2;
  param_5[1] = fVar2 + param_2[1];
  param_5[2] = param_2[2] + param_5[2];
  return;
}


// ==== FUN_007a3056 @ 0x007a3056 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a3056(uint param_1,int param_2,uint param_3,float *param_4,float *param_5,float *param_6
                 ,float *param_7,uint param_8)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float *pfVar6;
  uint uVar7;
  int iVar8;
  float *pfVar9;
  float local_1cc [68];
  float local_bc [10];
  float local_94;
  float local_8c;
  float local_84;
  float local_80;
  float local_7c;
  float local_78;
  float local_74;
  float local_70;
  float fStack_6c;
  float fStack_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  float local_40;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  
  local_7c = *param_5;
  local_78 = param_5[1];
  local_74 = param_5[2];
  local_34 = *param_6;
  local_30 = param_6[1];
  local_2c = param_6[2];
  local_10 = *param_7;
  local_c = param_7[1];
  local_8 = param_7[2];
  FUN_007a2fb7(&local_34,&local_7c,param_1,_DAT_009fc7c8,&local_70);
  FUN_007a2fb7(&local_10,&local_7c,param_1,_DAT_009fc7c8,&local_64);
  FUN_007a2fb7(&local_7c,&local_34,param_1 + 0xc,_DAT_009fc7c8,&local_58);
  FUN_007a2fb7(&local_7c,&local_10,param_1 + 0x18,_DAT_009fc7c8,&local_40);
  FUN_007a2fb7(&local_10,&local_34,param_1 + 0xc,_DAT_009fc7c8,&local_28);
  FUN_007a2fb7(&local_34,&local_10,param_1 + 0x18,_DAT_009fc7c8,&local_1c);
  fVar5 = DAT_009b0300;
  local_94 = local_10 + local_34 + local_7c;
  local_8c = local_8 + local_2c + local_74;
  param_1 = 0;
  local_84 = (local_c + local_30 + local_78) * _DAT_009fc7c4;
  local_80 = local_8c * _DAT_009fc7c4;
  local_4c = (local_1c + local_28 + local_40 + local_58 + local_64 + local_70) * DAT_009fc7a0 -
             local_94 * _DAT_009fc7c4;
  local_48 = (local_18 + local_24 + local_3c + local_54 + local_60 + fStack_6c) * DAT_009fc7a0 -
             local_84;
  local_44 = (local_14 + local_20 + local_38 + local_50 + local_5c + fStack_68) * DAT_009fc7a0 -
             local_80;
  if (param_3 != 0) {
    do {
      fVar1 = *(float *)(param_1 * 8 + param_2);
      uVar7 = 0;
      fVar2 = *(float *)(param_1 * 8 + 4 + param_2);
      fVar3 = (1.0 - fVar1) - fVar2;
      local_bc[0] = fVar2 * fVar2 * fVar2;
      local_bc[1] = fVar3 * fVar2 * fVar2 * fVar5;
      local_bc[2] = fVar2 * fVar2 * fVar1 * fVar5;
      fVar4 = fVar3 * fVar3;
      local_bc[3] = fVar4 * fVar2 * fVar5;
      local_bc[4] = fVar3 * fVar2 * fVar1 * DAT_009b0ec4;
      local_bc[5] = fVar2 * fVar1 * fVar1 * fVar5;
      local_bc[6] = fVar4 * fVar3;
      local_bc[7] = fVar4 * fVar1 * fVar5;
      local_bc[8] = fVar3 * fVar1 * fVar1 * fVar5;
      local_bc[9] = fVar1 * fVar1 * fVar1;
      local_1cc[0] = 0.0;
      local_1cc[1] = 0.0;
      local_1cc[2] = 0.0;
      pfVar6 = &local_78;
      do {
        pfVar9 = local_bc + uVar7;
        uVar7 = uVar7 + 1;
        local_1cc[0] = pfVar6[-1] * *pfVar9 + local_1cc[0];
        local_1cc[1] = *pfVar9 * *pfVar6 + local_1cc[1];
        local_1cc[2] = pfVar6[1] * *pfVar9 + local_1cc[2];
        pfVar6 = pfVar6 + 3;
      } while (uVar7 < 10);
      if (3 < param_8) {
        pfVar6 = param_6 + 3;
        iVar8 = param_8 - 3;
        do {
          *(float *)(((int)local_1cc - (int)param_6) + (int)pfVar6) =
               fVar3 * *pfVar6 +
               fVar2 * *(float *)(((int)param_5 - (int)param_6) + (int)pfVar6) +
               fVar1 * *(float *)(((int)param_7 - (int)param_6) + (int)pfVar6);
          pfVar6 = pfVar6 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      pfVar6 = local_1cc;
      pfVar9 = param_4;
      for (uVar7 = param_8 & 0x3fffffff; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pfVar9 = *pfVar6;
        pfVar6 = pfVar6 + 1;
        pfVar9 = pfVar9 + 1;
      }
      param_1 = param_1 + 1;
      for (iVar8 = 0; iVar8 != 0; iVar8 = iVar8 + -1) {
        *(undefined1 *)pfVar9 = *(undefined1 *)pfVar6;
        pfVar6 = (float *)((int)pfVar6 + 1);
        pfVar9 = (float *)((int)pfVar9 + 1);
      }
      param_4 = param_4 + param_8;
    } while (param_1 < param_3);
  }
  return;
}


// ==== FUN_007a33af @ 0x007a33af ====

undefined4 FUN_007a33af(LPBYTE param_1,LPCSTR param_2,LPBYTE param_3,DWORD param_4)

{
  LSTATUS LVar1;
  HKEY local_8;
  
  local_8 = (HKEY)0x0;
  LVar1 = RegOpenKeyA((HKEY)0x80000002,s_>Software_Microsoft_Direct3D_009fc7cb + 1,&local_8);
  if (LVar1 == 0) {
    LVar1 = RegQueryValueExA(local_8,param_2,(LPDWORD)0x0,(LPDWORD)&param_3,param_3,&param_4);
    RegCloseKey(local_8);
    if ((LVar1 == 0) && (param_3 == param_1)) {
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007a340e @ 0x007a340e ====

/* WARNING: Removing unreachable block (ram,0x007a341f) */
/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 FUN_007a340e(void)

{
  int iVar1;
  undefined4 in_EDX;
  
  iVar1 = cpuid_Version_info(1);
  return CONCAT44(in_EDX,(uint)((*(uint *)(iVar1 + 8) & 0x800000) != 0));
}


// ==== FUN_007a3436 @ 0x007a3436 ====

int FUN_007a3436(void)

{
  LSTATUS LVar1;
  int iVar2;
  _union_530 local_38 [8];
  ushort local_18;
  int local_14;
  DWORD local_10 [2];
  HKEY local_8;
  
  LVar1 = RegOpenKeyA((HKEY)0x80000002,s_>Software_Microsoft_Direct3D_009fc7cb + 1,&local_8);
  if (LVar1 == 0) {
    local_10[1] = 4;
    LVar1 = RegQueryValueExA(local_8,s_DisableMMX_009fc7e8,(LPDWORD)0x0,local_10,(LPBYTE)&local_14,
                             local_10 + 1);
    if (((LVar1 == 0) && (local_10[0] == 4)) && (local_14 != 0)) {
      RegCloseKey(local_8);
      DAT_00b44be0 = 0;
      return 0;
    }
    RegCloseKey(local_8);
  }
  if (DAT_00b44be0 < 0) {
    DAT_00b44be0 = 0;
    GetSystemInfo((LPSYSTEM_INFO)&local_38[0].s);
    if (((local_38[0].s.wProcessorArchitecture == 0) && (4 < local_18)) &&
       (iVar2 = FUN_007a340e(), iVar2 != 0)) {
      DAT_00b44be0 = 1;
    }
  }
  return DAT_00b44be0;
}


// ==== FUN_007a34e8 @ 0x007a34e8 ====

/* WARNING: Removing unreachable block (ram,0x007a351a) */

void FUN_007a34e8(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int unaff_EBP;
  undefined1 auStack_c0 [128];
  
  FUN_00804050();
  *(undefined4 *)(unaff_EBP + -0x18) = DAT_00b49670;
  *(undefined1 **)(unaff_EBP + -0x10) = auStack_c0 + 0x80;
  *(undefined4 *)(unaff_EBP + -0x14) = 0;
  *(undefined4 *)(unaff_EBP + -0x28) = s_GenuineIntel_009fc7f4._0_4_;
  *(undefined4 *)(unaff_EBP + -0x24) = s_GenuineIntel_009fc7f4._4_4_;
  *(undefined4 *)(unaff_EBP + -0x20) = s_GenuineIntel_009fc7f4._8_4_;
  *(char *)(unaff_EBP + -0x1c) = s_GenuineIntel_009fc7f4[0xc];
  *(undefined4 *)(unaff_EBP + -4) = 0;
  puVar1 = (undefined4 *)cpuid_basic_info(0);
  uVar4 = puVar1[1];
  uVar3 = puVar1[2];
  uVar2 = puVar1[3];
  *(undefined4 *)(unaff_EBP + -0x30) = *puVar1;
  *(undefined4 *)(unaff_EBP + -0x3c) = uVar4;
  *(undefined4 *)(unaff_EBP + -0x38) = uVar3;
  *(undefined4 *)(unaff_EBP + -0x34) = uVar2;
  FUN_007a3536();
  return;
}


// ==== Catch@007a352a @ 0x007a352a ====

undefined * Catch_007a352a(void)

{
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -0x40) = *(undefined4 *)(unaff_EBP + -0x14);
  return &DAT_007a353c;
}


// ==== FUN_007a3536 @ 0x007a3536 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x007a3551) */

undefined4 FUN_007a3536(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int unaff_EBP;
  
  *(undefined4 *)(unaff_EBP + -4) = 0xffffffff;
  if (*(int *)(unaff_EBP + -0x30) == 0) {
    uVar2 = *(undefined4 *)(unaff_EBP + -0x14);
  }
  else {
    puVar1 = (undefined4 *)cpuid_Version_info(1);
    uVar2 = puVar1[2];
    *(undefined4 *)(unaff_EBP + -0x30) = *puVar1;
    *(undefined4 *)(unaff_EBP + -0x2c) = uVar2;
    if ((*(uint *)(unaff_EBP + -0x2c) & 0x2000000) != 0) {
      *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 4;
    }
    if ((*(uint *)(unaff_EBP + -0x2c) & 0x4000000) != 0) {
      *(uint *)(unaff_EBP + -0x14) = *(uint *)(unaff_EBP + -0x14) | 8;
    }
    uVar2 = *(undefined4 *)(unaff_EBP + -0x14);
  }
  ExceptionList = *(void **)(unaff_EBP + -0xc);
  return uVar2;
}


// ==== FUN_007a3599 @ 0x007a3599 ====

int FUN_007a3599(int param_1)

{
  BOOL BVar1;
  uint uVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  int local_8;
  
  FUN_007a42e8();
  if (param_1 == 0) {
    DAT_00b44be4 = 0xffff;
    ppuVar4 = &PTR_FUN_00b44ab8;
    ppuVar5 = &PTR_FUN_00b44990;
    for (iVar3 = 0x4a; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppuVar5 = *ppuVar4;
      ppuVar4 = ppuVar4 + 1;
      ppuVar5 = ppuVar5 + 1;
    }
  }
  else if (DAT_00b44be4 == 0xffff) {
    DAT_00b44be4 = 0;
    ppuVar4 = &PTR_FUN_00b44ab8;
    ppuVar5 = &PTR_FUN_00b44990;
    for (iVar3 = 0x4a; iVar3 != 0; iVar3 = iVar3 + -1) {
      *ppuVar5 = *ppuVar4;
      ppuVar4 = ppuVar4 + 1;
      ppuVar5 = ppuVar5 + 1;
    }
    FUN_007a41b5(&PTR_FUN_00b44990);
    iVar3 = FUN_007a33af(4,s_DisablePSGP_009fc814,&param_1,4);
    if (iVar3 == 0) {
      param_1 = 0;
    }
    iVar3 = FUN_007a33af(4,s_DisableD3DXPSGP_009fc804,&local_8,4);
    if (iVar3 != 0) {
      param_1 = local_8;
    }
    if (param_1 != 1) {
      if ((param_1 == 2) || (BVar1 = IsProcessorFeaturePresent(7), BVar1 == 0)) {
        uVar2 = FUN_007a34e8();
        if ((uVar2 & 8) == 0) {
          BVar1 = IsProcessorFeaturePresent(6);
          if (BVar1 != 0) {
            FUN_007a369c(&PTR_FUN_00b44990);
            DAT_00b44be4 = 3;
          }
        }
        else {
          FUN_007a380f(&PTR_FUN_00b44990);
          DAT_00b44be4 = 2;
        }
      }
      else {
        FUN_007a3a6e(&PTR_FUN_00b44990);
        DAT_00b44be4 = 1;
      }
    }
  }
  return DAT_00b44be4;
}


// ==== FUN_007a369c @ 0x007a369c ====

void FUN_007a369c(undefined4 *param_1)

{
  param_1[2] = FUN_007a47cf;
  param_1[0x23] = FUN_007a47cf;
  *param_1 = FUN_007a46fd;
  param_1[1] = FUN_007a5d70;
  param_1[3] = FUN_007a488f;
  param_1[4] = FUN_007a7c7e;
  param_1[5] = FUN_007a4796;
  param_1[6] = FUN_007a8143;
  param_1[9] = FUN_007a473d;
  param_1[10] = FUN_007a5e37;
  param_1[7] = FUN_007a49c5;
  param_1[8] = FUN_007a4e68;
  param_1[0x16] = FUN_007a4a59;
  param_1[0x11] = &LAB_007a4da7;
  param_1[0x15] = FUN_007a43f2;
  param_1[0x14] = FUN_007a4377;
  param_1[0x19] = FUN_007a45d1;
  param_1[0x1a] = &LAB_007a4512;
  param_1[0x17] = FUN_007a53b4;
  param_1[0x13] = &LAB_007a4afb;
  param_1[0x32] = FUN_007a50e6;
  param_1[0x33] = FUN_007a4f04;
  param_1[0x34] = FUN_007a52bf;
  param_1[0x35] = FUN_007a519b;
  param_1[0x36] = FUN_007a503f;
  param_1[0x37] = FUN_007a531b;
  param_1[0x12] = FUN_007a5237;
  param_1[0x30] = FUN_007a4fb8;
  param_1[0x31] = FUN_007a5363;
  param_1[0xb] = &LAB_007a5464;
  param_1[0x1c] = &LAB_007a5628;
  param_1[0xe] = &LAB_007a553c;
  param_1[0x1d] = &LAB_007a5720;
  param_1[0x3b] = FUN_007a6d33;
  param_1[0x3c] = &LAB_007a6264;
  param_1[0x3d] = &LAB_007a63e4;
  param_1[0x3e] = &LAB_007a6540;
  param_1[0x3f] = &LAB_007a6091;
  param_1[0x40] = &LAB_007a6a05;
  param_1[0x41] = &LAB_007a6851;
  param_1[0x42] = &LAB_007a6651;
  param_1[0x45] = &LAB_007a6651;
  param_1[0x47] = &LAB_007a57f8;
  param_1[0x2d] = &LAB_007a448e;
  return;
}


// ==== FUN_007a380f @ 0x007a380f ====

void FUN_007a380f(undefined4 *param_1)

{
  param_1[2] = FUN_007a47cf;
  param_1[0x23] = FUN_007a47cf;
  *param_1 = FUN_007a46fd;
  param_1[1] = FUN_007a5d70;
  param_1[3] = FUN_007a488f;
  param_1[4] = FUN_007a7c7e;
  param_1[5] = FUN_007a4796;
  param_1[6] = FUN_007a8143;
  param_1[9] = FUN_007a473d;
  param_1[10] = FUN_007a5e37;
  param_1[7] = FUN_007a7b48;
  param_1[8] = FUN_007a4e68;
  param_1[0x16] = FUN_007a7bdc;
  param_1[0x11] = &LAB_007a7dc6;
  param_1[0x15] = FUN_007a43f2;
  param_1[0x14] = FUN_007a4377;
  param_1[0x19] = FUN_007a82ce;
  param_1[0x1a] = &LAB_007a820f;
  param_1[0x17] = FUN_007a53b4;
  param_1[0x13] = &LAB_007a4afb;
  param_1[0x32] = FUN_007a50e6;
  param_1[0x33] = FUN_007a4f04;
  param_1[0x34] = FUN_007a52bf;
  param_1[0x35] = FUN_007a519b;
  param_1[0x36] = FUN_007a503f;
  param_1[0x37] = FUN_007a531b;
  param_1[0x12] = FUN_007a5237;
  param_1[0x30] = FUN_007a4fb8;
  param_1[0x31] = FUN_007a5363;
  param_1[0xb] = &LAB_007a5464;
  param_1[0x1c] = &LAB_007a7f73;
  param_1[0xe] = &LAB_007a7e87;
  param_1[0x1d] = &LAB_007a806b;
  param_1[0x3b] = FUN_007a7a74;
  param_1[0x3c] = &LAB_007a6fdc;
  param_1[0x3d] = &LAB_007a715c;
  param_1[0x3e] = &LAB_007a72b8;
  param_1[0x3f] = &LAB_007a6e09;
  param_1[0x40] = &LAB_007a777d;
  param_1[0x41] = &LAB_007a75c9;
  param_1[0x42] = &LAB_007a73c9;
  param_1[0x45] = &LAB_007a73c9;
  param_1[0x47] = &LAB_007a57f8;
  return;
}


// ==== FUN_007a3978 @ 0x007a3978 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x007a3a10) */
/* WARNING: Removing unreachable block (ram,0x007a39fe) */
/* WARNING: Removing unreachable block (ram,0x007a39d2) */
/* WARNING: Removing unreachable block (ram,0x007a39b6) */
/* WARNING: Removing unreachable block (ram,0x007a39ab) */

undefined8 FUN_007a3978(void)

{
  char cVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int *piVar6;
  uint local_2c;
  char local_28 [4];
  char acStack_24 [4];
  char acStack_20 [4];
  char cStack_1c;
  int local_18;
  uint local_14;
  int local_10;
  char cStack_c;
  undefined4 local_8;
  
  cStack_c = s_UnknownVendr_009fc950[0xc];
  local_28 = (char  [4])s_AuthenticAMD_009fc940._0_4_;
  acStack_24 = (char  [4])s_AuthenticAMD_009fc940._4_4_;
  acStack_20 = (char  [4])s_AuthenticAMD_009fc940._8_4_;
  local_8 = DAT_00b49670;
  cStack_1c = s_AuthenticAMD_009fc940[0xc];
  cpuid_basic_info(0);
  local_2c = 1;
  piVar6 = (int *)cpuid_basic_info(0);
  local_14 = piVar6[2];
  local_18 = piVar6[1];
  local_10 = piVar6[3];
  if (*piVar6 != 0) {
    iVar4 = cpuid_Version_info(1);
    local_2c = -(uint)((*(uint *)(iVar4 + 8) & 0x800000) != 0) & 0x20 | 3 |
               -(uint)((*(uint *)(iVar4 + 8) & 0x2000000) != 0) & 0x40;
    puVar2 = (uint *)cpuid(0x80000000);
    local_14 = puVar2[2];
    if (0x80000000 < *puVar2) {
      iVar4 = cpuid(0x80000001);
      local_14 = *(uint *)(iVar4 + 8);
      iVar4 = 0xc;
      pcVar5 = local_28;
      piVar6 = &local_18;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        iVar3 = *piVar6;
        cVar1 = *pcVar5;
        pcVar5 = pcVar5 + 1;
        piVar6 = (int *)((int)piVar6 + 1);
      } while (cVar1 == (char)iVar3);
      local_2c = local_2c | 4 | -(uint)((local_14 & 0x80000000) != 0) & 0x80 |
                 -(uint)((local_14 & 0x40000000) != 0) & 0x100 |
                 -(uint)((local_14 & 0x400000) != 0) & 0x200;
    }
  }
  return CONCAT44(local_14,local_2c);
}


// ==== FUN_007a3a6e @ 0x007a3a6e ====

void FUN_007a3a6e(undefined4 *param_1)

{
  byte bVar1;
  byte extraout_AH;
  
  bVar1 = FUN_007a3978();
  if (((bVar1 & 0x20) != 0) && ((char)bVar1 < '\0')) {
    *param_1 = FUN_007b32bb;
    param_1[1] = FUN_007b1964;
    param_1[2] = FUN_007b3582;
    param_1[3] = &LAB_007adb19;
    param_1[5] = FUN_007b3312;
    param_1[6] = FUN_007b19d7;
    param_1[7] = FUN_007b1a40;
    param_1[8] = &LAB_007b3606;
    param_1[9] = FUN_007b334d;
    param_1[10] = FUN_007b1f24;
    param_1[0xb] = &LAB_007add4b;
    param_1[0xd] = &LAB_007b39b0;
    param_1[0xe] = &LAB_007b39f3;
    param_1[0xf] = FUN_007b1f2f;
    param_1[0x10] = FUN_007b20bb;
    param_1[0x11] = &LAB_007b3665;
    param_1[0x12] = &LAB_007b33b3;
    param_1[0x13] = FUN_007b1946;
    param_1[0x14] = &LAB_007ac63c;
    param_1[0x15] = &LAB_007ac6d5;
    param_1[0x16] = FUN_007b3b95;
    param_1[0x17] = &LAB_007b3ad7;
    param_1[0x18] = FUN_007ac732;
    param_1[0x19] = &LAB_007ac776;
    param_1[0x1a] = &LAB_007acba7;
    param_1[0x1b] = &LAB_007ade1a;
    param_1[0x1c] = &LAB_007ade6a;
    param_1[0x1d] = &LAB_007adf55;
    param_1[0x1e] = FUN_007acc6c;
    param_1[0x1f] = &LAB_007ae031;
    param_1[0x20] = &LAB_007ae096;
    param_1[0x21] = &LAB_007ae0f6;
    param_1[0x22] = &LAB_007ae151;
    param_1[0x23] = &LAB_007b3bf9;
    param_1[0x24] = FUN_007accd8;
    param_1[0x25] = FUN_007ace0f;
    param_1[0x26] = &LAB_007ae198;
    param_1[0x27] = &LAB_007ae207;
    param_1[0x28] = FUN_007ae38e;
    param_1[0x29] = FUN_007af58a;
    param_1[0x2a] = &LAB_007af72f;
    param_1[0x2b] = FUN_007afc63;
    param_1[0x2c] = FUN_007ace9c;
    param_1[0x2d] = &LAB_007acf2e;
    param_1[0x37] = &LAB_007b3799;
    param_1[0x34] = &LAB_007b1a9f;
    param_1[0x31] = &LAB_007b344b;
    param_1[0x2f] = &LAB_007b3494;
    param_1[0x35] = &LAB_007b380a;
    param_1[0x32] = &LAB_007b1b10;
    param_1[0x38] = FUN_007acf92;
    param_1[0x39] = &LAB_007ad039;
    param_1[0x36] = &LAB_007b38d2;
    param_1[0x30] = &LAB_007b34d7;
    param_1[0x33] = &LAB_007b1be4;
    param_1[4] = &LAB_007b1218;
    param_1[0x2e] = FUN_007ad0de;
    param_1[0x3b] = FUN_007b3000;
    param_1[0x3a] = &LAB_007b3140;
    if (((extraout_AH & 1) != 0) && ((extraout_AH & 2) != 0)) {
      param_1[0x10] = FUN_007b22d8;
      param_1[0x13] = FUN_007b0f36;
      param_1[0x27] = &LAB_007ae2d9;
      param_1[0x28] = FUN_007afd7e;
      param_1[0x19] = &LAB_007ac992;
    }
  }
  if ((bVar1 & 0x40) != 0) {
    param_1[0x3f] = FUN_007ac000;
    param_1[0x40] = &LAB_007ac0a0;
    param_1[0x41] = &LAB_007ac3c0;
    param_1[0x3c] = &LAB_007ab000;
    param_1[0x3d] = &LAB_007ab260;
    param_1[0x3e] = &LAB_007ab4c0;
    param_1[0x42] = FUN_007aa000;
    param_1[0x45] = FUN_007a9000;
  }
  return;
}


// ==== FUN_007a3d04 @ 0x007a3d04 ====

float * FUN_007a3d04(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  
  fVar1 = *param_2;
  fVar2 = param_3[2];
  fVar3 = *param_2;
  fVar4 = param_3[1];
  fVar5 = *param_2;
  fVar6 = param_3[3];
  fVar7 = param_2[1];
  fVar8 = param_3[6];
  fVar9 = param_2[1];
  fVar10 = param_3[5];
  fVar11 = param_2[1];
  fVar12 = param_3[7];
  fVar13 = param_3[0xd];
  fVar14 = param_3[0xe];
  fVar15 = param_3[0xf];
  *param_1 = param_3[0xc] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar13 + fVar9 * fVar10 + fVar3 * fVar4;
  param_1[2] = fVar14 + fVar7 * fVar8 + fVar1 * fVar2;
  param_1[3] = fVar15 + fVar11 * fVar12 + fVar5 * fVar6;
  return param_1;
}


// ==== FUN_007a3d6f @ 0x007a3d6f ====

float * FUN_007a3d6f(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = *param_2;
  fVar2 = param_3[1];
  fVar3 = param_2[1];
  fVar4 = param_3[5];
  *param_1 = param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar3 * fVar4 + fVar1 * fVar2;
  return param_1;
}


// ==== FUN_007a3da6 @ 0x007a3da6 ====

float * FUN_007a3da6(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  
  fVar1 = *param_2;
  fVar2 = param_3[2];
  fVar3 = *param_2;
  fVar4 = param_3[1];
  fVar5 = *param_2;
  fVar6 = param_3[3];
  fVar7 = param_2[1];
  fVar8 = param_3[6];
  fVar9 = param_2[1];
  fVar10 = param_3[5];
  fVar11 = param_2[1];
  fVar12 = param_3[7];
  fVar13 = param_2[2];
  fVar14 = param_3[10];
  fVar15 = param_2[2];
  fVar16 = param_3[9];
  fVar17 = param_2[2];
  fVar18 = param_3[0xb];
  fVar19 = param_3[0xd];
  fVar20 = param_3[0xe];
  fVar21 = param_3[0xf];
  *param_1 = param_3[0xc] + param_2[2] * param_3[8] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar19 + fVar15 * fVar16 + fVar9 * fVar10 + fVar3 * fVar4;
  param_1[2] = fVar20 + fVar13 * fVar14 + fVar7 * fVar8 + fVar1 * fVar2;
  param_1[3] = fVar21 + fVar17 * fVar18 + fVar11 * fVar12 + fVar5 * fVar6;
  return param_1;
}


// ==== FUN_007a3e33 @ 0x007a3e33 ====

float * FUN_007a3e33(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  fVar1 = *param_2;
  fVar2 = param_3[1];
  fVar3 = *param_2;
  fVar4 = param_3[2];
  fVar5 = param_2[1];
  fVar6 = param_3[5];
  fVar7 = param_2[1];
  fVar8 = param_3[6];
  fVar9 = param_2[2];
  fVar10 = param_3[9];
  fVar11 = param_2[2];
  fVar12 = param_3[10];
  *param_1 = param_2[2] * param_3[8] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar9 * fVar10 + fVar5 * fVar6 + fVar1 * fVar2;
  param_1[2] = fVar11 * fVar12 + fVar7 * fVar8 + fVar3 * fVar4;
  return param_1;
}


// ==== FUN_007a3e94 @ 0x007a3e94 ====

float * FUN_007a3e94(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  
  fVar1 = *param_2;
  fVar2 = param_3[2];
  fVar3 = *param_2;
  fVar4 = param_3[1];
  fVar5 = *param_2;
  fVar6 = param_3[3];
  fVar7 = param_2[1];
  fVar8 = param_3[6];
  fVar9 = param_2[1];
  fVar10 = param_3[5];
  fVar11 = param_2[1];
  fVar12 = param_3[7];
  fVar13 = param_2[2];
  fVar14 = param_3[10];
  fVar15 = param_2[2];
  fVar16 = param_3[9];
  fVar17 = param_2[2];
  fVar18 = param_3[0xb];
  fVar19 = param_2[3];
  fVar20 = param_3[0xe];
  fVar21 = param_2[3];
  fVar22 = param_3[0xd];
  fVar23 = param_2[3];
  fVar24 = param_3[0xf];
  *param_1 = param_2[3] * param_3[0xc] +
             param_2[2] * param_3[8] + param_2[1] * param_3[4] + *param_2 * *param_3;
  param_1[1] = fVar21 * fVar22 + fVar15 * fVar16 + fVar9 * fVar10 + fVar3 * fVar4;
  param_1[2] = fVar19 * fVar20 + fVar13 * fVar14 + fVar7 * fVar8 + fVar1 * fVar2;
  param_1[3] = fVar23 * fVar24 + fVar17 * fVar18 + fVar11 * fVar12 + fVar5 * fVar6;
  return param_1;
}


// ==== FUN_007a3f2f @ 0x007a3f2f ====

float10 FUN_007a3f2f(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 >> 0xc & 0xff8;
  return ((float10)(float)(param_1 & 0xffffff | 0x3f000000) *
          (float10)*(float *)(&DAT_00b44be8 + uVar1) + (float10)*(float *)(&DAT_00b44bec + uVar1)) *
         (float10)(float)(0xbeffffff - param_1 >> 1 & 0xff800000);
}


// ==== FUN_007a3f74 @ 0x007a3f74 ====

float * FUN_007a3f74(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  float10 fVar5;
  
  fVar5 = (float10)*param_2 * (float10)*param_2 + (float10)param_2[1] * (float10)param_2[1] +
          (float10)param_2[2] * (float10)param_2[2];
  fVar1 = (float)fVar5;
  if (fVar1 == 0.0) {
    ffree(fVar5);
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
  }
  else if ((uint)ABS((float)(fVar5 - (float10)1)) < 0x3727c5ad) {
    if (param_1 != param_2) {
      *param_1 = *param_2;
      param_1[1] = param_2[1];
      param_1[2] = param_2[2];
    }
  }
  else {
    uVar4 = (uint)fVar1 >> 0xc & 0xff8;
    fVar3 = ((float)((uint)fVar1 & 0xffffff | 0x3f000000) * *(float *)(&DAT_00b44be8 + uVar4) +
            *(float *)(&DAT_00b44bec + uVar4)) * (float)(0xbeffffffU - (int)fVar1 >> 1 & 0xff800000)
    ;
    fVar1 = param_2[1];
    fVar2 = param_2[2];
    *param_1 = *param_2 * fVar3;
    param_1[1] = fVar1 * fVar3;
    param_1[2] = fVar2 * fVar3;
  }
  return param_1;
}


// ==== FUN_007a4040 @ 0x007a4040 ====

void FUN_007a4040(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  float local_44 [16];
  
  if (param_3 == param_1) {
    if (param_2 != param_1) {
      iVar6 = -4;
      do {
        iVar5 = -0x10;
        fVar1 = param_3[iVar6 + 4];
        fVar2 = param_3[iVar6 + 8];
        fVar3 = param_3[iVar6 + 0xc];
        fVar4 = param_3[iVar6 + 0x10];
        do {
          param_1[iVar5 + 0x10] =
               (float)((float10)fVar4 * (float10)param_2[iVar5 + 0x13] +
                       (float10)fVar2 * (float10)param_2[iVar5 + 0x11] +
                      (float10)fVar1 * (float10)param_2[iVar5 + 0x10] +
                      (float10)fVar3 * (float10)param_2[iVar5 + 0x12]);
          iVar5 = iVar5 + 4;
        } while (iVar5 != 0);
        ffree((float10)fVar1);
        ffree((float10)fVar2);
        ffree((float10)fVar3);
        ffree((float10)fVar4);
        param_1 = param_1 + 1;
        iVar6 = iVar6 + 1;
      } while (iVar6 != 0);
      return;
    }
    pfVar7 = local_44;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pfVar7 = *param_3;
      param_3 = param_3 + 1;
      pfVar7 = pfVar7 + 1;
    }
    param_3 = local_44;
  }
  iVar6 = -4;
  do {
    iVar5 = -4;
    fVar1 = *param_2;
    fVar2 = param_2[1];
    fVar3 = param_2[2];
    fVar4 = param_2[3];
    do {
      param_1[iVar5 + 4] =
           (float)((float10)fVar4 * (float10)param_3[iVar5 + 0x10] +
                   (float10)fVar2 * (float10)param_3[iVar5 + 8] +
                  (float10)fVar1 * (float10)param_3[iVar5 + 4] +
                  (float10)fVar3 * (float10)param_3[iVar5 + 0xc]);
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0);
    ffree((float10)fVar1);
    ffree((float10)fVar2);
    ffree((float10)fVar3);
    ffree((float10)fVar4);
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
    iVar6 = iVar6 + 1;
  } while (iVar6 != 0);
  return;
}


// ==== FUN_007a4125 @ 0x007a4125 ====

void FUN_007a4125(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float *pfVar5;
  float *pfVar6;
  int iVar7;
  int iVar8;
  float local_48 [17];
  
  if ((param_1 == param_2) || (pfVar5 = param_1, param_1 == param_3)) {
    pfVar5 = local_48;
  }
  iVar8 = -4;
  do {
    iVar7 = -4;
    pfVar6 = pfVar5 + iVar8 + 4;
    fVar1 = *param_2;
    fVar2 = param_2[1];
    fVar3 = param_2[2];
    fVar4 = param_2[3];
    do {
      *pfVar6 = (float)((float10)fVar4 * (float10)param_3[iVar7 + 0x10] +
                        (float10)fVar2 * (float10)param_3[iVar7 + 8] +
                       (float10)fVar1 * (float10)param_3[iVar7 + 4] +
                       (float10)fVar3 * (float10)param_3[iVar7 + 0xc]);
      pfVar6 = pfVar6 + 4;
      iVar7 = iVar7 + 1;
    } while (iVar7 != 0);
    ffree((float10)fVar1);
    ffree((float10)fVar2);
    ffree((float10)fVar3);
    ffree((float10)fVar4);
    param_2 = param_2 + 4;
    iVar8 = iVar8 + 1;
  } while (iVar8 != 0);
  if (pfVar5 != param_1) {
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *param_1 = *pfVar5;
      pfVar5 = pfVar5 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_007a41b5 @ 0x007a41b5 ====

void FUN_007a41b5(undefined4 *param_1)

{
  *param_1 = FUN_007a3d04;
  param_1[1] = FUN_007a3da6;
  param_1[2] = FUN_007a3e94;
  param_1[3] = FUN_007a4040;
  param_1[4] = FUN_007a4125;
  param_1[5] = FUN_007a3d6f;
  param_1[6] = FUN_007a3e33;
  param_1[7] = FUN_007a3f74;
  param_1[0x23] = FUN_007a3e94;
  return;
}


// ==== FUN_007a41ff @ 0x007a41ff ====

undefined4 FUN_007a41ff(undefined4 param_1)

{
  undefined4 uVar1;
  HMODULE pHVar2;
  int iVar3;
  
  uVar1 = DAT_00b5b1d0;
  DAT_00b5b1d0 = param_1;
  if ((DAT_00b5b1d8 == (FARPROC)0x0) && (DAT_00b5b1d4 == (FARPROC)0x0)) {
    pHVar2 = GetModuleHandleA(s_d3d9_dll_009fc98c);
    if ((pHVar2 != (HMODULE)0x0) &&
       (pHVar2 = LoadLibraryA(s_d3d9_dll_009fc98c), pHVar2 != (HMODULE)0x0)) {
      DAT_00b5b1d8 = GetProcAddress(pHVar2,s_DebugSetMute_009fc97c);
    }
    pHVar2 = GetModuleHandleA(s_d3d9d_dll_009fc970);
    if ((pHVar2 != (HMODULE)0x0) &&
       (pHVar2 = LoadLibraryA(s_d3d9d_dll_009fc970), pHVar2 != (HMODULE)0x0)) {
      DAT_00b5b1d4 = GetProcAddress(pHVar2,s_DebugSetMute_009fc97c);
    }
  }
  if (DAT_00b45bf0 == -1) {
    iVar3 = FUN_007a33af(4,s_D3DXDoNotMute_009fc960,&DAT_00b45bf0,4);
    if (iVar3 == 0) {
      DAT_00b45bf0 = 0;
    }
    if (DAT_00b45bf0 == 0) goto LAB_007a42c3;
    DAT_00b45bf0 = 1;
  }
  if (DAT_00b45bf0 != 0) {
    return uVar1;
  }
LAB_007a42c3:
  if (DAT_00b5b1d8 != (FARPROC)0x0) {
    (*DAT_00b5b1d8)(param_1);
  }
  if (DAT_00b5b1d4 != (FARPROC)0x0) {
    (*DAT_00b5b1d4)(param_1);
  }
  return uVar1;
}


// ==== FUN_007a42e8 @ 0x007a42e8 ====

void FUN_007a42e8(void)

{
  void *_Memory;
  void *_Memory_00;
  
  if (DAT_00b5b1dc != 0) {
    return;
  }
  DAT_00b5b1dc = 1;
  _Memory = operator_new(0);
  _Memory_00 = operator_new(0);
  if (_Memory != (void *)0x0) {
    _free(_Memory);
    return;
  }
  if ((_Memory_00 == (void *)0x0) || (_Memory_00 == (void *)0x0)) {
    _free((void *)0x0);
    return;
  }
  _free(_Memory_00);
  return;
}


// ==== FUN_007a4377 @ 0x007a4377 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 * FUN_007a4377(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  uVar5 = (uint)*param_3;
  uVar6 = (uint)((ulonglong)*param_3 >> 0x20);
  uVar7 = (uint)param_3[1];
  fVar8 = (float)((ulonglong)param_3[1] >> 0x20);
  fVar1 = (float)*param_2;
  fVar2 = (float)((ulonglong)*param_2 >> 0x20);
  fVar3 = (float)param_2[1];
  fVar4 = (float)((ulonglong)param_2[1] >> 0x20);
  fVar9 = (float)(uVar5 ^ uRam009fcb08);
  fVar11 = (float)(uVar5 ^ uRam009fcb0c);
  fVar13 = (float)(uVar6 ^ uRam009fcaf8);
  fVar14 = (float)(uVar6 ^ uRam009fcafc);
  fVar10 = (float)(uVar7 ^ uRam009fcae8);
  fVar12 = (float)(uVar7 ^ uRam009fcaec);
  *param_1 = CONCAT44(fVar8 * fVar2 + (float)(uVar5 ^ uRam009fcb04) * fVar3 +
                      (float)(uVar6 ^ uRam009fcaf4) * fVar4 + (float)(uVar7 ^ uRam009fcae4) * fVar1,
                      fVar8 * fVar1 + (float)(uVar5 ^ _DAT_009fcb00) * fVar4 +
                      (float)(uVar6 ^ _DAT_009fcaf0) * fVar3 +
                      (float)(uVar7 ^ _DAT_009fcae0) * fVar2);
  param_1[1] = CONCAT44(fVar8 * fVar4 + fVar11 * fVar1 + fVar14 * fVar2 + fVar12 * fVar3,
                        fVar8 * fVar3 + fVar9 * fVar2 + fVar13 * fVar1 + fVar10 * fVar4);
  return param_1;
}


// ==== FUN_007a43f2 @ 0x007a43f2 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_007a43f2(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 in_register_00001304 [12];
  float fVar6;
  undefined1 in_XMM5 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = param_2[3];
  auVar7._4_12_ = in_XMM5._4_12_;
  auVar7._0_4_ = fVar2 * fVar2;
  fVar5 = fVar1 * fVar1 + auVar7._0_4_ + fVar3 * fVar3 + fVar4 * fVar4;
  auVar8._4_12_ = in_register_00001304;
  auVar8._0_4_ = fVar5;
  auVar8 = rsqrtss(auVar7,auVar8);
  fVar6 = auVar8._0_4_;
  fVar6 = (DAT_00b45c10 - fVar5 * fVar6 * fVar6) * _DAT_00b45c00 * fVar6;
  *param_1 = fVar1 * fVar6;
  param_1[1] = fVar2 * fVar6;
  param_1[2] = fVar3 * fVar6;
  param_1[3] = fVar4 * fVar6;
  return param_1;
}


// ==== FUN_007a45d1 @ 0x007a45d1 ====

void FUN_007a45d1(float *param_1,float *param_2)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  float local_18 [4];
  int local_8;
  
  pfVar4 = param_2;
  fVar3 = param_2[5] + *param_2 + param_2[10];
  if (fVar3 <= DAT_0099cdc8) {
    local_18[1] = param_2[5];
    pfVar1 = param_2 + 10;
    local_18[0] = *param_2;
    local_18[2] = *pfVar1;
    param_2 = (float *)(uint)(*param_2 < param_2[5]);
    if (local_18[(int)param_2] < *pfVar1) {
      param_2 = (float *)0x2;
    }
    iVar5 = (int)param_2 * 4;
    iVar2 = *(int *)(&DAT_009fcb84 + iVar5);
    iVar6 = iVar2 * 4;
    local_8 = *(int *)(&DAT_009fcb84 + iVar6);
    fVar3 = SQRT(((local_18[(int)param_2] - local_18[iVar2]) - local_18[local_8]) + DAT_0099d080) *
            DAT_0099d0b4;
    param_1[(int)param_2] = fVar3;
    fVar3 = DAT_009fc7a0 / fVar3;
    param_1[iVar2] = (pfVar4[(int)param_2 + iVar6] + pfVar4[iVar2 + iVar5]) * fVar3;
    param_1[local_8] = (pfVar4[(int)param_2 + local_8 * 4] + pfVar4[iVar5 + local_8]) * fVar3;
    param_1[3] = (pfVar4[iVar6 + local_8] - pfVar4[local_8 * 4 + iVar2]) * fVar3;
  }
  else {
    fVar3 = SQRT(fVar3 + DAT_0099d080) * DAT_0099d0b4;
    param_1[3] = fVar3;
    fVar3 = DAT_009fc7a0 / fVar3;
    *param_1 = (param_2[6] - param_2[9]) * fVar3;
    param_1[1] = (param_2[8] - param_2[2]) * fVar3;
    param_1[2] = (param_2[1] - param_2[4]) * fVar3;
  }
  return;
}


// ==== FUN_007a46fd @ 0x007a46fd ====

float * FUN_007a46fd(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  
  fVar3 = param_3[1];
  fVar4 = param_3[2];
  fVar5 = param_3[3];
  fVar1 = *param_2;
  fVar6 = param_3[5];
  fVar7 = param_3[6];
  fVar8 = param_3[7];
  fVar2 = param_2[1];
  fVar9 = param_3[0xd];
  fVar10 = param_3[0xe];
  fVar11 = param_3[0xf];
  *param_1 = fVar1 * *param_3 + param_3[0xc] + fVar2 * param_3[4];
  param_1[1] = fVar1 * fVar3 + fVar9 + fVar2 * fVar6;
  param_1[2] = fVar1 * fVar4 + fVar10 + fVar2 * fVar7;
  param_1[3] = fVar1 * fVar5 + fVar11 + fVar2 * fVar8;
  return param_1;
}


// ==== FUN_007a473d @ 0x007a473d ====

undefined8 * FUN_007a473d(undefined8 *param_1,float *param_2,float *param_3)

{
  float fVar1;
  undefined1 in_XMM0 [16];
  undefined1 auVar2 [16];
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar3 = *param_2;
  fVar1 = param_2[1];
  fVar4 = fVar3 * *param_3 + param_3[0xc] + fVar1 * param_3[4];
  fVar5 = fVar3 * param_3[1] + param_3[0xd] + fVar1 * param_3[5];
  fVar6 = fVar3 * param_3[3] + param_3[0xf] + fVar1 * param_3[7];
  auVar2._4_4_ = fVar5;
  auVar2._0_4_ = fVar4;
  auVar2._8_4_ = fVar3 * param_3[2] + param_3[0xe] + fVar1 * param_3[6];
  auVar2._12_4_ = fVar6;
  auVar2 = rcpps(in_XMM0,auVar2);
  fVar3 = auVar2._12_4_;
  fVar3 = (fVar3 + fVar3) - fVar3 * fVar3 * fVar6;
  *param_1 = CONCAT44(fVar5 * fVar3,fVar4 * fVar3);
  return param_1;
}


// ==== FUN_007a4796 @ 0x007a4796 ====

undefined8 * FUN_007a4796(undefined8 *param_1,float *param_2,float *param_3)

{
  *param_1 = CONCAT44(*param_2 * param_3[1] + param_2[1] * param_3[5],
                      *param_2 * *param_3 + param_2[1] * param_3[4]);
  return param_1;
}


// ==== FUN_007a47cf @ 0x007a47cf ====

void FUN_007a47cf(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar7 = param_2[2];
  fVar8 = param_2[3];
  if (((uint)param_3 & 0xf) == 0) {
    fVar11 = param_3[8] * fVar7 + param_3[0xc] * fVar8;
    fVar12 = param_3[9] * fVar7 + param_3[0xd] * fVar8;
    fVar13 = param_3[10] * fVar7 + param_3[0xe] * fVar8;
    fVar14 = param_3[0xb] * fVar7 + param_3[0xf] * fVar8;
    fVar7 = param_3[4];
    fVar8 = param_3[5];
    fVar9 = param_3[6];
    fVar10 = param_3[7];
    fVar3 = *param_3;
    fVar4 = param_3[1];
    fVar5 = param_3[2];
    fVar6 = param_3[3];
  }
  else {
    fVar11 = (float)*(undefined8 *)(param_3 + 8) * fVar7 +
             (float)*(undefined8 *)(param_3 + 0xc) * fVar8;
    fVar12 = (float)((ulonglong)*(undefined8 *)(param_3 + 8) >> 0x20) * fVar7 +
             (float)((ulonglong)*(undefined8 *)(param_3 + 0xc) >> 0x20) * fVar8;
    fVar13 = (float)*(undefined8 *)(param_3 + 10) * fVar7 +
             (float)*(undefined8 *)(param_3 + 0xe) * fVar8;
    fVar14 = (float)((ulonglong)*(undefined8 *)(param_3 + 10) >> 0x20) * fVar7 +
             (float)((ulonglong)*(undefined8 *)(param_3 + 0xe) >> 0x20) * fVar8;
    fVar7 = (float)*(undefined8 *)(param_3 + 4);
    fVar8 = (float)((ulonglong)*(undefined8 *)(param_3 + 4) >> 0x20);
    fVar9 = (float)*(undefined8 *)(param_3 + 6);
    fVar10 = (float)((ulonglong)*(undefined8 *)(param_3 + 6) >> 0x20);
    fVar3 = (float)*(undefined8 *)param_3;
    fVar4 = (float)((ulonglong)*(undefined8 *)param_3 >> 0x20);
    fVar5 = (float)*(undefined8 *)(param_3 + 2);
    fVar6 = (float)((ulonglong)*(undefined8 *)(param_3 + 2) >> 0x20);
  }
  *param_1 = fVar3 * fVar1 + fVar7 * fVar2 + fVar11;
  param_1[1] = fVar4 * fVar1 + fVar8 * fVar2 + fVar12;
  param_1[2] = fVar5 * fVar1 + fVar9 * fVar2 + fVar13;
  param_1[3] = fVar6 * fVar1 + fVar10 * fVar2 + fVar14;
  return;
}


// ==== FUN_007a488f @ 0x007a488f ====

undefined8 * FUN_007a488f(undefined8 *param_1,float *param_2,undefined8 *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = param_2[3];
  fVar17 = (float)*param_3;
  fVar18 = (float)((ulonglong)*param_3 >> 0x20);
  fVar19 = (float)param_3[1];
  fVar20 = (float)((ulonglong)param_3[1] >> 0x20);
  fVar21 = (float)param_3[2];
  fVar22 = (float)((ulonglong)param_3[2] >> 0x20);
  fVar23 = (float)param_3[3];
  fVar24 = (float)((ulonglong)param_3[3] >> 0x20);
  fVar25 = (float)param_3[4];
  fVar26 = (float)((ulonglong)param_3[4] >> 0x20);
  fVar27 = (float)param_3[5];
  fVar28 = (float)((ulonglong)param_3[5] >> 0x20);
  fVar29 = (float)param_3[6];
  fVar30 = (float)((ulonglong)param_3[6] >> 0x20);
  fVar31 = (float)param_3[7];
  fVar32 = (float)((ulonglong)param_3[7] >> 0x20);
  fVar5 = param_2[4];
  fVar6 = param_2[5];
  fVar7 = param_2[6];
  fVar8 = param_2[7];
  fVar9 = param_2[8];
  fVar10 = param_2[9];
  fVar11 = param_2[10];
  fVar12 = param_2[0xb];
  fVar13 = param_2[0xc];
  fVar14 = param_2[0xd];
  fVar15 = param_2[0xe];
  fVar16 = param_2[0xf];
  *param_1 = CONCAT44(fVar1 * fVar18 + fVar2 * fVar22 + fVar3 * fVar26 + fVar4 * fVar30,
                      fVar1 * fVar17 + fVar2 * fVar21 + fVar3 * fVar25 + fVar4 * fVar29);
  param_1[1] = CONCAT44(fVar1 * fVar20 + fVar2 * fVar24 + fVar3 * fVar28 + fVar4 * fVar32,
                        fVar1 * fVar19 + fVar2 * fVar23 + fVar3 * fVar27 + fVar4 * fVar31);
  param_1[2] = CONCAT44(fVar5 * fVar18 + fVar6 * fVar22 + fVar7 * fVar26 + fVar8 * fVar30,
                        fVar5 * fVar17 + fVar6 * fVar21 + fVar7 * fVar25 + fVar8 * fVar29);
  param_1[3] = CONCAT44(fVar5 * fVar20 + fVar6 * fVar24 + fVar7 * fVar28 + fVar8 * fVar32,
                        fVar5 * fVar19 + fVar6 * fVar23 + fVar7 * fVar27 + fVar8 * fVar31);
  param_1[4] = CONCAT44(fVar9 * fVar18 + fVar10 * fVar22 + fVar11 * fVar26 + fVar12 * fVar30,
                        fVar9 * fVar17 + fVar10 * fVar21 + fVar11 * fVar25 + fVar12 * fVar29);
  param_1[5] = CONCAT44(fVar9 * fVar20 + fVar10 * fVar24 + fVar11 * fVar28 + fVar12 * fVar32,
                        fVar9 * fVar19 + fVar10 * fVar23 + fVar11 * fVar27 + fVar12 * fVar31);
  param_1[6] = CONCAT44(fVar18 * fVar13 + fVar22 * fVar14 + fVar26 * fVar15 + fVar30 * fVar16,
                        fVar17 * fVar13 + fVar21 * fVar14 + fVar25 * fVar15 + fVar29 * fVar16);
  param_1[7] = CONCAT44(fVar20 * fVar13 + fVar24 * fVar14 + fVar28 * fVar15 + fVar32 * fVar16,
                        fVar19 * fVar13 + fVar23 * fVar14 + fVar27 * fVar15 + fVar31 * fVar16);
  return param_1;
}


// ==== FUN_007a49c5 @ 0x007a49c5 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_007a49c5(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 in_XMM6 [16];
  undefined1 auVar6 [16];
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (_DAT_009fcb50 <= fVar4) {
    auVar6 = rsqrtss(in_XMM6,ZEXT416((uint)fVar4));
    fVar5 = auVar6._0_4_;
    fVar4 = (DAT_009fcb30 - fVar5 * fVar4 * fVar5) * fVar5 * DAT_009fcb40;
    *param_1 = fVar1 * fVar4;
    param_1[1] = fVar2 * fVar4;
    param_1[2] = fVar3 * fVar4;
  }
  else {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
  }
  return param_1;
}


// ==== FUN_007a4a59 @ 0x007a4a59 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_007a4a59(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 in_XMM6 [16];
  undefined1 auVar6 [16];
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (_DAT_009fcb50 <= fVar4) {
    auVar6 = rsqrtss(in_XMM6,ZEXT416((uint)fVar4));
    fVar5 = auVar6._0_4_;
    fVar5 = (DAT_009fcb30 - fVar5 * fVar4 * fVar5) * fVar5 * DAT_009fcb40;
    fVar4 = param_2[3];
    *param_1 = fVar1 * fVar5;
    param_1[1] = fVar2 * fVar5;
    param_1[2] = fVar3 * fVar5;
    param_1[3] = fVar5 * fVar4;
  }
  else {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
    param_1[3] = 0.0;
  }
  return param_1;
}


// ==== FUN_007a4e68 @ 0x007a4e68 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_007a4e68(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 in_register_00001304 [12];
  float fVar6;
  undefined1 in_XMM5 [16];
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = param_2[3];
  auVar7._4_12_ = in_XMM5._4_12_;
  auVar7._0_4_ = fVar2 * fVar2;
  fVar5 = fVar1 * fVar1 + auVar7._0_4_ + fVar3 * fVar3 + fVar4 * fVar4;
  auVar8._4_12_ = in_register_00001304;
  auVar8._0_4_ = fVar5;
  auVar8 = rsqrtss(auVar7,auVar8);
  fVar6 = auVar8._0_4_;
  fVar6 = (DAT_00b45da0 - fVar5 * fVar6 * fVar6) * _DAT_00b45d90 * fVar6;
  *param_1 = fVar1 * fVar6;
  param_1[1] = fVar2 * fVar6;
  param_1[2] = fVar3 * fVar6;
  param_1[3] = fVar4 * fVar6;
  return param_1;
}


// ==== FUN_007a4f04 @ 0x007a4f04 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_007a4f04(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            undefined8 *param_5,float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar7 = param_6 * param_6;
  fVar8 = param_6 * fVar7;
  fVar3 = param_6 * _DAT_00b45c90 + _DAT_00b45ca0 + fVar7 * _DAT_00b45c80 + fVar8 * _DAT_00b45c70;
  fVar4 = param_6 * fRam00b45c94 + fRam00b45ca4 + fVar7 * fRam00b45c84 + fVar8 * fRam00b45c74;
  fVar5 = param_6 * fRam00b45c98 + fRam00b45ca8 + fVar7 * fRam00b45c88 + fVar8 * fRam00b45c78;
  fVar6 = param_6 * fRam00b45c9c + fRam00b45cac + fVar7 * fRam00b45c8c + fVar8 * fRam00b45c7c;
  fVar7 = *(float *)(param_2 + 1);
  fVar8 = *(float *)(param_3 + 1);
  fVar1 = *(float *)(param_4 + 1);
  fVar2 = *(float *)(param_5 + 1);
  *param_1 = CONCAT44((float)((ulonglong)*param_2 >> 0x20) * fVar3 +
                      (float)((ulonglong)*param_3 >> 0x20) * fVar4 +
                      (float)((ulonglong)*param_4 >> 0x20) * fVar5 +
                      (float)((ulonglong)*param_5 >> 0x20) * fVar6,
                      (float)*param_2 * fVar3 + (float)*param_3 * fVar4 + (float)*param_4 * fVar5 +
                      (float)*param_5 * fVar6);
  *(float *)(param_1 + 1) = fVar7 * fVar3 + fVar8 * fVar4 + fVar1 * fVar5 + fVar2 * fVar6;
  return param_1;
}


// ==== FUN_007a4fb8 @ 0x007a4fb8 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_007a4fb8(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            undefined8 *param_5,float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar4 = param_6 * param_6;
  fVar5 = param_6 * fVar4;
  fVar1 = param_6 * _DAT_00b45c90 + _DAT_00b45ca0 + fVar4 * _DAT_00b45c80 + fVar5 * _DAT_00b45c70;
  fVar2 = param_6 * fRam00b45c94 + fRam00b45ca4 + fVar4 * fRam00b45c84 + fVar5 * fRam00b45c74;
  fVar3 = param_6 * fRam00b45c98 + fRam00b45ca8 + fVar4 * fRam00b45c88 + fVar5 * fRam00b45c78;
  fVar4 = param_6 * fRam00b45c9c + fRam00b45cac + fVar4 * fRam00b45c8c + fVar5 * fRam00b45c7c;
  *param_1 = CONCAT44((float)((ulonglong)*param_2 >> 0x20) * fVar1 +
                      (float)((ulonglong)*param_4 >> 0x20) * fVar3 +
                      (float)((ulonglong)*param_3 >> 0x20) * fVar2 +
                      (float)((ulonglong)*param_5 >> 0x20) * fVar4,
                      (float)*param_2 * fVar1 + (float)*param_4 * fVar3 +
                      (float)*param_3 * fVar2 + (float)*param_5 * fVar4);
  return param_1;
}


// ==== FUN_007a503f @ 0x007a503f ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_007a503f(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                    float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  
  fVar15 = param_6 * param_6;
  fVar16 = param_6 * fVar15;
  fVar11 = param_6 * _DAT_00b45c90 + _DAT_00b45ca0 + fVar15 * _DAT_00b45c80 + fVar16 * _DAT_00b45c70
  ;
  fVar12 = param_6 * fRam00b45c94 + fRam00b45ca4 + fVar15 * fRam00b45c84 + fVar16 * fRam00b45c74;
  fVar13 = param_6 * fRam00b45c98 + fRam00b45ca8 + fVar15 * fRam00b45c88 + fVar16 * fRam00b45c78;
  fVar14 = param_6 * fRam00b45c9c + fRam00b45cac + fVar15 * fRam00b45c8c + fVar16 * fRam00b45c7c;
  fVar15 = param_2[1];
  fVar16 = param_2[2];
  fVar1 = param_2[3];
  fVar2 = param_3[1];
  fVar3 = param_3[2];
  fVar4 = param_3[3];
  fVar5 = param_4[1];
  fVar6 = param_4[2];
  fVar7 = param_4[3];
  fVar8 = param_5[1];
  fVar9 = param_5[2];
  fVar10 = param_5[3];
  *param_1 = *param_2 * fVar11 + *param_3 * fVar12 + *param_4 * fVar13 + *param_5 * fVar14;
  param_1[1] = fVar15 * fVar11 + fVar2 * fVar12 + fVar5 * fVar13 + fVar8 * fVar14;
  param_1[2] = fVar16 * fVar11 + fVar3 * fVar12 + fVar6 * fVar13 + fVar9 * fVar14;
  param_1[3] = fVar1 * fVar11 + fVar4 * fVar12 + fVar7 * fVar13 + fVar10 * fVar14;
  return param_1;
}


// ==== FUN_007a50e6 @ 0x007a50e6 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_007a50e6(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            undefined8 *param_5,float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar7 = param_6 * param_6;
  fVar8 = param_6 * fVar7;
  fVar3 = param_6 * _DAT_00b45c50 + _DAT_00b45c60 + fVar7 * _DAT_00b45c40 + fVar8 * _DAT_00b45c30;
  fVar4 = param_6 * fRam00b45c54 + fVar7 * fRam00b45c44 + fVar8 * fRam00b45c34;
  fVar5 = param_6 * fRam00b45c58 + fVar7 * fRam00b45c48 + fVar8 * fRam00b45c38;
  fVar6 = param_6 * fRam00b45c5c + fVar7 * fRam00b45c4c + fVar8 * fRam00b45c3c;
  fVar7 = *(float *)(param_2 + 1);
  fVar8 = *(float *)(param_3 + 1);
  fVar1 = *(float *)(param_4 + 1);
  fVar2 = *(float *)(param_5 + 1);
  *param_1 = CONCAT44((float)((ulonglong)*param_2 >> 0x20) * fVar3 +
                      (float)((ulonglong)*param_3 >> 0x20) * fVar4 +
                      (float)((ulonglong)*param_4 >> 0x20) * fVar5 +
                      (float)((ulonglong)*param_5 >> 0x20) * fVar6,
                      (float)*param_2 * fVar3 + (float)*param_3 * fVar4 + (float)*param_4 * fVar5 +
                      (float)*param_5 * fVar6);
  *(float *)(param_1 + 1) = fVar7 * fVar3 + fVar8 * fVar4 + fVar1 * fVar5 + fVar2 * fVar6;
  return param_1;
}


// ==== FUN_007a519b @ 0x007a519b ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_007a519b(float *param_1,float *param_2,float *param_3,float *param_4,float *param_5,
                    float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  
  fVar15 = param_6 * param_6;
  fVar16 = param_6 * fVar15;
  fVar11 = param_6 * _DAT_00b45c50 + _DAT_00b45c60 + fVar15 * _DAT_00b45c40 + fVar16 * _DAT_00b45c30
  ;
  fVar12 = param_6 * fRam00b45c54 + fVar15 * fRam00b45c44 + fVar16 * fRam00b45c34;
  fVar13 = param_6 * fRam00b45c58 + fVar15 * fRam00b45c48 + fVar16 * fRam00b45c38;
  fVar14 = param_6 * fRam00b45c5c + fVar15 * fRam00b45c4c + fVar16 * fRam00b45c3c;
  fVar15 = param_2[1];
  fVar16 = param_2[2];
  fVar1 = param_2[3];
  fVar2 = param_3[1];
  fVar3 = param_3[2];
  fVar4 = param_3[3];
  fVar5 = param_4[1];
  fVar6 = param_4[2];
  fVar7 = param_4[3];
  fVar8 = param_5[1];
  fVar9 = param_5[2];
  fVar10 = param_5[3];
  *param_1 = *param_2 * fVar11 + *param_3 * fVar12 + *param_4 * fVar13 + *param_5 * fVar14;
  param_1[1] = fVar15 * fVar11 + fVar2 * fVar12 + fVar5 * fVar13 + fVar8 * fVar14;
  param_1[2] = fVar16 * fVar11 + fVar3 * fVar12 + fVar6 * fVar13 + fVar9 * fVar14;
  param_1[3] = fVar1 * fVar11 + fVar4 * fVar12 + fVar7 * fVar13 + fVar10 * fVar14;
  return param_1;
}


// ==== FUN_007a5237 @ 0x007a5237 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_007a5237(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            undefined8 *param_5,float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  fVar4 = param_6 * param_6;
  fVar5 = param_6 * fVar4;
  fVar1 = param_6 * _DAT_00b45c50 + _DAT_00b45c60 + fVar4 * _DAT_00b45c40 + fVar5 * _DAT_00b45c30;
  fVar2 = param_6 * fRam00b45c54 + fVar4 * fRam00b45c44 + fVar5 * fRam00b45c34;
  fVar3 = param_6 * fRam00b45c58 + fVar4 * fRam00b45c48 + fVar5 * fRam00b45c38;
  fVar4 = param_6 * fRam00b45c5c + fVar4 * fRam00b45c4c + fVar5 * fRam00b45c3c;
  *param_1 = CONCAT44((float)((ulonglong)*param_2 >> 0x20) * fVar1 +
                      (float)((ulonglong)*param_4 >> 0x20) * fVar3 +
                      (float)((ulonglong)*param_3 >> 0x20) * fVar2 +
                      (float)((ulonglong)*param_5 >> 0x20) * fVar4,
                      (float)*param_2 * fVar1 + (float)*param_4 * fVar3 +
                      (float)*param_3 * fVar2 + (float)*param_5 * fVar4);
  return param_1;
}


// ==== FUN_007a52bf @ 0x007a52bf ====

undefined8 *
FUN_007a52bf(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            float param_5,float param_6)

{
  float fVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  float fVar4;
  float fVar5;
  
  fVar1 = *(float *)(param_2 + 1);
  uVar2 = *param_3;
  fVar4 = (float)*param_2;
  fVar5 = (float)((ulonglong)*param_2 >> 0x20);
  uVar3 = *param_4;
  *(float *)(param_1 + 1) =
       (*(float *)(param_3 + 1) - fVar1) * param_5 + fVar1 +
       (*(float *)(param_4 + 1) - fVar1) * param_6;
  *param_1 = CONCAT44(((float)((ulonglong)uVar2 >> 0x20) - fVar5) * param_5 + fVar5 +
                      ((float)((ulonglong)uVar3 >> 0x20) - fVar5) * param_6,
                      ((float)uVar2 - fVar4) * param_5 + fVar4 + ((float)uVar3 - fVar4) * param_6);
  return param_1;
}


// ==== FUN_007a531b @ 0x007a531b ====

float * FUN_007a531b(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
                    float param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = param_2[3];
  fVar5 = param_3[1];
  fVar6 = param_3[2];
  fVar7 = param_3[3];
  fVar8 = param_4[1];
  fVar9 = param_4[2];
  fVar10 = param_4[3];
  *param_1 = (*param_3 - fVar1) * param_5 + fVar1 + (*param_4 - fVar1) * param_6;
  param_1[1] = (fVar5 - fVar2) * param_5 + fVar2 + (fVar8 - fVar2) * param_6;
  param_1[2] = (fVar6 - fVar3) * param_5 + fVar3 + (fVar9 - fVar3) * param_6;
  param_1[3] = (fVar7 - fVar4) * param_5 + fVar4 + (fVar10 - fVar4) * param_6;
  return param_1;
}


// ==== FUN_007a5363 @ 0x007a5363 ====

undefined8 *
FUN_007a5363(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,undefined8 *param_4,
            float param_5,float param_6)

{
  float fVar1;
  float fVar2;
  
  fVar1 = (float)*param_2;
  fVar2 = (float)((ulonglong)*param_2 >> 0x20);
  *param_1 = CONCAT44(((float)((ulonglong)*param_3 >> 0x20) - fVar2) * param_5 + fVar2 +
                      ((float)((ulonglong)*param_4 >> 0x20) - fVar2) * param_6,
                      ((float)*param_3 - fVar1) * param_5 + fVar1 +
                      ((float)*param_4 - fVar1) * param_6);
  return param_1;
}


// ==== FUN_007a53b4 @ 0x007a53b4 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 *
FUN_007a53b4(undefined8 *param_1,float *param_2,undefined8 *param_3,undefined8 *param_4)

{
  float fVar1;
  float fVar2;
  undefined1 auVar3 [16];
  float fVar6;
  float fVar7;
  undefined1 auVar4 [16];
  undefined1 auVar5 [16];
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float in_XMM6_Dc;
  float in_XMM6_Dd;
  
  fVar12 = param_2[3];
  fVar1 = *(float *)(param_3 + 1);
  fVar2 = *(float *)(param_4 + 1);
  fVar8 = (float)*param_3;
  fVar9 = (float)((ulonglong)*param_3 >> 0x20);
  fVar14 = fVar9 * param_2[1];
  fVar10 = (float)*param_4;
  fVar6 = *param_2 * fVar10;
  fVar11 = (float)((ulonglong)*param_4 >> 0x20);
  fVar7 = param_2[1] * fVar11;
  fVar13 = fVar12 * 0.0 + fVar14;
  auVar5._0_4_ = param_2[2] * fVar2 + fVar6;
  auVar5._4_4_ = fVar12 * 0.0 + fVar7;
  auVar5._8_4_ = fVar6 + in_XMM6_Dc;
  auVar5._12_4_ = fVar7 + in_XMM6_Dd;
  fVar6 = fVar1 * param_2[2] + fVar8 * *param_2 + fVar14;
  auVar4._4_12_ = auVar5._4_12_;
  auVar4._0_4_ = auVar5._0_4_ + fVar7;
  fVar7 = fVar6 - auVar4._0_4_;
  if (fVar7 == _DAT_00b5b1e0) {
    param_1 = (undefined8 *)0x0;
  }
  else {
    auVar3._4_4_ = fVar14;
    auVar3._0_4_ = fVar7;
    auVar3._8_4_ = fVar13;
    auVar3._12_4_ = fVar13;
    auVar5 = rcpss(auVar4,auVar3);
    fVar13 = auVar5._0_4_;
    fVar12 = (fVar6 + fVar12) * ((fVar13 + fVar13) - fVar7 * fVar13 * fVar13);
    *param_1 = CONCAT44(fVar9 + fVar12 * (fVar11 - fVar9),fVar8 + fVar12 * (fVar10 - fVar8));
    *(float *)(param_1 + 1) = fVar1 + fVar12 * (fVar2 - fVar1);
  }
  return param_1;
}


// ==== FUN_007a5d70 @ 0x007a5d70 ====

void FUN_007a5d70(float *param_1,undefined8 *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  
  fVar1 = (float)*param_2;
  fVar3 = (float)((ulonglong)*param_2 >> 0x20);
  fVar7 = *(float *)(param_2 + 1);
  if (((uint)param_3 & 0xf) == 0) {
    fVar11 = param_3[8] * fVar7 + param_3[0xc];
    fVar12 = param_3[9] * fVar7 + param_3[0xd];
    fVar13 = param_3[10] * fVar7 + param_3[0xe];
    fVar14 = param_3[0xb] * fVar7 + param_3[0xf];
    fVar7 = param_3[4];
    fVar8 = param_3[5];
    fVar9 = param_3[6];
    fVar10 = param_3[7];
    fVar2 = *param_3;
    fVar4 = param_3[1];
    fVar5 = param_3[2];
    fVar6 = param_3[3];
  }
  else {
    fVar11 = (float)*(undefined8 *)(param_3 + 8) * fVar7 + (float)*(undefined8 *)(param_3 + 0xc);
    fVar12 = (float)((ulonglong)*(undefined8 *)(param_3 + 8) >> 0x20) * fVar7 +
             (float)((ulonglong)*(undefined8 *)(param_3 + 0xc) >> 0x20);
    fVar13 = (float)*(undefined8 *)(param_3 + 10) * fVar7 + (float)*(undefined8 *)(param_3 + 0xe);
    fVar14 = (float)((ulonglong)*(undefined8 *)(param_3 + 10) >> 0x20) * fVar7 +
             (float)((ulonglong)*(undefined8 *)(param_3 + 0xe) >> 0x20);
    fVar7 = (float)*(undefined8 *)(param_3 + 4);
    fVar8 = (float)((ulonglong)*(undefined8 *)(param_3 + 4) >> 0x20);
    fVar9 = (float)*(undefined8 *)(param_3 + 6);
    fVar10 = (float)((ulonglong)*(undefined8 *)(param_3 + 6) >> 0x20);
    fVar2 = (float)*(undefined8 *)param_3;
    fVar4 = (float)((ulonglong)*(undefined8 *)param_3 >> 0x20);
    fVar5 = (float)*(undefined8 *)(param_3 + 2);
    fVar6 = (float)((ulonglong)*(undefined8 *)(param_3 + 2) >> 0x20);
  }
  *param_1 = fVar2 * fVar1 + fVar7 * fVar3 + fVar11;
  param_1[1] = fVar4 * fVar1 + fVar8 * fVar3 + fVar12;
  param_1[2] = fVar5 * fVar1 + fVar9 * fVar3 + fVar13;
  param_1[3] = fVar6 * fVar1 + fVar10 * fVar3 + fVar14;
  return;
}


// ==== FUN_007a5e37 @ 0x007a5e37 ====

void FUN_007a5e37(undefined8 *param_1,undefined8 *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined1 auVar7 [16];
  undefined1 auVar8 [16];
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  
  fVar1 = (float)*param_2;
  fVar3 = (float)((ulonglong)*param_2 >> 0x20);
  fVar9 = *(float *)(param_2 + 1);
  if (((uint)param_3 & 0xf) == 0) {
    fVar13 = param_3[8] * fVar9 + param_3[0xc];
    fVar14 = param_3[9] * fVar9 + param_3[0xd];
    fVar15 = param_3[10] * fVar9 + param_3[0xe];
    fVar16 = param_3[0xb] * fVar9 + param_3[0xf];
    fVar9 = param_3[4];
    fVar10 = param_3[5];
    fVar11 = param_3[6];
    fVar12 = param_3[7];
    fVar2 = *param_3;
    fVar4 = param_3[1];
    fVar5 = param_3[2];
    fVar6 = param_3[3];
  }
  else {
    fVar13 = (float)*(undefined8 *)(param_3 + 8) * fVar9 + param_3[0xc];
    fVar14 = (float)((ulonglong)*(undefined8 *)(param_3 + 8) >> 0x20) * fVar9 + param_3[0xd];
    fVar15 = (float)*(undefined8 *)(param_3 + 10) * fVar9 + param_3[0xe];
    fVar16 = (float)((ulonglong)*(undefined8 *)(param_3 + 10) >> 0x20) * fVar9 + param_3[0xf];
    fVar9 = (float)*(undefined8 *)(param_3 + 4);
    fVar10 = (float)((ulonglong)*(undefined8 *)(param_3 + 4) >> 0x20);
    fVar11 = (float)*(undefined8 *)(param_3 + 6);
    fVar12 = (float)((ulonglong)*(undefined8 *)(param_3 + 6) >> 0x20);
    fVar2 = (float)*(undefined8 *)param_3;
    fVar4 = (float)((ulonglong)*(undefined8 *)param_3 >> 0x20);
    fVar5 = (float)*(undefined8 *)(param_3 + 2);
    fVar6 = (float)((ulonglong)*(undefined8 *)(param_3 + 2) >> 0x20);
  }
  auVar7._4_4_ = fVar1;
  auVar7._0_4_ = fVar1;
  auVar7._8_4_ = fVar1;
  auVar7._12_4_ = fVar1;
  fVar13 = fVar2 * fVar1 + fVar9 * fVar3 + fVar13;
  fVar14 = fVar4 * fVar1 + fVar10 * fVar3 + fVar14;
  fVar15 = fVar5 * fVar1 + fVar11 * fVar3 + fVar15;
  fVar16 = fVar6 * fVar1 + fVar12 * fVar3 + fVar16;
  auVar8._4_4_ = fVar14;
  auVar8._0_4_ = fVar13;
  auVar8._8_4_ = fVar15;
  auVar8._12_4_ = fVar16;
  auVar8 = rcpps(auVar7,auVar8);
  fVar9 = auVar8._12_4_;
  fVar9 = (fVar9 + fVar9) - fVar9 * fVar16 * fVar9;
  *param_1 = CONCAT44(fVar14 * fVar9,fVar13 * fVar9);
  *(float *)(param_1 + 1) = fVar15 * fVar9;
  return;
}


// ==== FUN_007a5f2b @ 0x007a5f2b ====

void FUN_007a5f2b(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = *param_1;
  *in_ECX = uVar1;
  in_ECX[1] = uVar1;
  in_ECX[2] = uVar1;
  in_ECX[3] = uVar1;
  uVar1 = param_1[4];
  in_ECX[0x10] = uVar1;
  in_ECX[0x11] = uVar1;
  in_ECX[0x12] = uVar1;
  in_ECX[0x13] = uVar1;
  uVar1 = param_1[8];
  in_ECX[0x20] = uVar1;
  in_ECX[0x21] = uVar1;
  in_ECX[0x22] = uVar1;
  in_ECX[0x23] = uVar1;
  uVar1 = param_1[0xc];
  in_ECX[0x30] = uVar1;
  in_ECX[0x31] = uVar1;
  in_ECX[0x32] = uVar1;
  in_ECX[0x33] = uVar1;
  uVar1 = param_1[1];
  in_ECX[4] = uVar1;
  in_ECX[5] = uVar1;
  in_ECX[6] = uVar1;
  in_ECX[7] = uVar1;
  uVar1 = param_1[5];
  in_ECX[0x14] = uVar1;
  in_ECX[0x15] = uVar1;
  in_ECX[0x16] = uVar1;
  in_ECX[0x17] = uVar1;
  uVar1 = param_1[9];
  in_ECX[0x24] = uVar1;
  in_ECX[0x25] = uVar1;
  in_ECX[0x26] = uVar1;
  in_ECX[0x27] = uVar1;
  uVar1 = param_1[0xd];
  in_ECX[0x34] = uVar1;
  in_ECX[0x35] = uVar1;
  in_ECX[0x36] = uVar1;
  in_ECX[0x37] = uVar1;
  uVar1 = param_1[2];
  in_ECX[8] = uVar1;
  in_ECX[9] = uVar1;
  in_ECX[10] = uVar1;
  in_ECX[0xb] = uVar1;
  uVar1 = param_1[6];
  in_ECX[0x18] = uVar1;
  in_ECX[0x19] = uVar1;
  in_ECX[0x1a] = uVar1;
  in_ECX[0x1b] = uVar1;
  uVar1 = param_1[10];
  in_ECX[0x28] = uVar1;
  in_ECX[0x29] = uVar1;
  in_ECX[0x2a] = uVar1;
  in_ECX[0x2b] = uVar1;
  uVar1 = param_1[0xe];
  in_ECX[0x38] = uVar1;
  in_ECX[0x39] = uVar1;
  in_ECX[0x3a] = uVar1;
  in_ECX[0x3b] = uVar1;
  uVar1 = param_1[3];
  in_ECX[0xc] = uVar1;
  in_ECX[0xd] = uVar1;
  in_ECX[0xe] = uVar1;
  in_ECX[0xf] = uVar1;
  uVar1 = param_1[7];
  in_ECX[0x1c] = uVar1;
  in_ECX[0x1d] = uVar1;
  in_ECX[0x1e] = uVar1;
  in_ECX[0x1f] = uVar1;
  uVar1 = param_1[0xb];
  in_ECX[0x2c] = uVar1;
  in_ECX[0x2d] = uVar1;
  in_ECX[0x2e] = uVar1;
  in_ECX[0x2f] = uVar1;
  uVar1 = param_1[0xf];
  in_ECX[0x3c] = uVar1;
  in_ECX[0x3d] = uVar1;
  in_ECX[0x3e] = uVar1;
  in_ECX[0x3f] = uVar1;
  return;
}


// ==== FUN_007a6c09 @ 0x007a6c09 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a6c09(void)

{
  return;
}


// ==== FUN_007a6d33 @ 0x007a6d33 ====

/* WARNING: Removing unreachable block (ram,0x007a6dea) */

int FUN_007a6d33(int param_1,int param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 *extraout_ECX;
  uint uVar3;
  int extraout_EDX;
  uint uVar4;
  uint uVar5;
  undefined8 in_XMM0_Qa;
  undefined8 in_XMM0_Qb;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM3_Qb;
  
  iVar2 = param_1;
  if (7 < param_3) {
    uVar5 = param_3 & 0xfffffff8;
    do {
      FUN_007a6c09();
      *extraout_ECX = in_XMM0_Qa;
      extraout_ECX[1] = in_XMM0_Qb;
      extraout_ECX[2] = in_XMM3_Qa;
      extraout_ECX[3] = in_XMM3_Qb;
    } while (extraout_EDX != 8);
    param_3 = param_3 - uVar5;
    param_2 = param_2 + uVar5 * 2;
    param_1 = param_1 + uVar5 * 4;
  }
  uVar5 = 0;
  if (param_3 != 0) {
    do {
      uVar1 = *(ushort *)(param_2 + uVar5 * 2);
      uVar3 = (uint)uVar1;
      uVar4 = uVar3 & 0x7c00;
      if (uVar4 < 0x401) {
        uVar4 = 0x400;
      }
      *(float *)(param_1 + uVar5 * 4) =
           (float)(-(uint)((uVar1 & 0x7c00) != 0) & 0x400 | uVar3 & 0x3ff) *
           (float)((uVar4 + 0x19800) * 0x2000 | (uVar3 & 0xffff8000) << 0x10);
      uVar5 = uVar5 + 1;
    } while (uVar5 < param_3);
  }
  return iVar2;
}


// ==== FUN_007a7981 @ 0x007a7981 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007a7981(void)

{
  ushort in_XMM0_Wa;
  ushort in_XMM0_Wb;
  ushort in_XMM0_Wc;
  ushort in_XMM0_Wd;
  ushort in_XMM0_We;
  ushort in_XMM0_Wf;
  ushort in_XMM0_Wg;
  ushort in_XMM0_Wh;
  undefined1 auVar1 [16];
  
  auVar1._0_2_ = -(ushort)((_DAT_00b45e90 & in_XMM0_Wa) == 0);
  auVar1._2_2_ = -(ushort)((uRam00b45e92 & in_XMM0_Wb) == 0);
  auVar1._4_2_ = -(ushort)((uRam00b45e94 & in_XMM0_Wc) == 0);
  auVar1._6_2_ = -(ushort)((uRam00b45e96 & in_XMM0_Wd) == 0);
  auVar1._8_2_ = -(ushort)((uRam00b45e98 & in_XMM0_We) == 0);
  auVar1._10_2_ = -(ushort)((uRam00b45e9a & in_XMM0_Wf) == 0);
  auVar1._12_2_ = -(ushort)((uRam00b45e9c & in_XMM0_Wg) == 0);
  auVar1._14_2_ = -(ushort)((uRam00b45e9e & in_XMM0_Wh) == 0);
  if ((((((((((((((((SUB161(auVar1 >> 7,0) & 1) == 0 && (SUB161(auVar1 >> 0xf,0) & 1) == 0) &&
                  (SUB161(auVar1 >> 0x17,0) & 1) == 0) && (SUB161(auVar1 >> 0x1f,0) & 1) == 0) &&
                (SUB161(auVar1 >> 0x27,0) & 1) == 0) && (SUB161(auVar1 >> 0x2f,0) & 1) == 0) &&
              (SUB161(auVar1 >> 0x37,0) & 1) == 0) && (SUB161(auVar1 >> 0x3f,0) & 1) == 0) &&
            (SUB161(auVar1 >> 0x47,0) & 1) == 0) && (SUB161(auVar1 >> 0x4f,0) & 1) == 0) &&
          (SUB161(auVar1 >> 0x57,0) & 1) == 0) && (SUB161(auVar1 >> 0x5f,0) & 1) == 0) &&
        (SUB161(auVar1 >> 0x67,0) & 1) == 0) && (SUB161(auVar1 >> 0x6f,0) & 1) == 0) &&
      (auVar1._14_2_ >> 7 & 1) == 0) && (auVar1._14_2_ & 0x8000) == 0) {
    return;
  }
  return;
}


// ==== FUN_007a7a74 @ 0x007a7a74 ====

/* WARNING: Removing unreachable block (ram,0x007a7b29) */

int FUN_007a7a74(int param_1,undefined8 *param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  undefined8 *puVar3;
  undefined8 *extraout_ECX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  undefined8 in_XMM3_Qa;
  undefined8 in_XMM3_Qb;
  undefined8 uVar9;
  
  iVar2 = param_1;
  if (7 < param_3) {
    uVar6 = param_3 & 0xfffffff8;
    puVar3 = param_2;
    do {
      uVar7 = *puVar3;
      uVar8 = puVar3[1];
      uVar9 = FUN_007a7981();
      puVar3 = (undefined8 *)uVar9;
      *extraout_ECX = uVar7;
      extraout_ECX[1] = uVar8;
      extraout_ECX[2] = in_XMM3_Qa;
      extraout_ECX[3] = in_XMM3_Qb;
    } while ((int)((ulonglong)uVar9 >> 0x20) != 8);
    param_3 = param_3 - uVar6;
    param_2 = (undefined8 *)((int)param_2 + uVar6 * 2);
    param_1 = param_1 + uVar6 * 4;
  }
  uVar6 = 0;
  if (param_3 != 0) {
    do {
      uVar1 = *(ushort *)((int)param_2 + uVar6 * 2);
      uVar4 = (uint)uVar1;
      uVar5 = uVar4 & 0x7c00;
      if (uVar5 < 0x401) {
        uVar5 = 0x400;
      }
      *(float *)(param_1 + uVar6 * 4) =
           (float)(-(uint)((uVar1 & 0x7c00) != 0) & 0x400 | uVar4 & 0x3ff) *
           (float)((uVar5 + 0x19800) * 0x2000 | (uVar4 & 0xffff8000) << 0x10);
      uVar6 = uVar6 + 1;
    } while (uVar6 < param_3);
  }
  return iVar2;
}


// ==== FUN_007a7b48 @ 0x007a7b48 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_007a7b48(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 in_XMM6 [16];
  undefined1 auVar6 [16];
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (_DAT_009fcb80 <= fVar4) {
    auVar6 = rsqrtss(in_XMM6,ZEXT416((uint)fVar4));
    fVar5 = auVar6._0_4_;
    fVar4 = (DAT_009fcb60 - fVar5 * fVar4 * fVar5) * fVar5 * DAT_009fcb70;
    *param_1 = fVar1 * fVar4;
    param_1[1] = fVar2 * fVar4;
    param_1[2] = fVar3 * fVar4;
  }
  else {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
  }
  return param_1;
}


// ==== FUN_007a7bdc @ 0x007a7bdc ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float * FUN_007a7bdc(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  undefined1 in_XMM6 [16];
  undefined1 auVar6 [16];
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3;
  if (_DAT_009fcb80 <= fVar4) {
    auVar6 = rsqrtss(in_XMM6,ZEXT416((uint)fVar4));
    fVar5 = auVar6._0_4_;
    fVar5 = (DAT_009fcb60 - fVar5 * fVar4 * fVar5) * fVar5 * DAT_009fcb70;
    fVar4 = param_2[3];
    *param_1 = fVar1 * fVar5;
    param_1[1] = fVar2 * fVar5;
    param_1[2] = fVar3 * fVar5;
    param_1[3] = fVar5 * fVar4;
  }
  else {
    *param_1 = 0.0;
    param_1[1] = 0.0;
    param_1[2] = 0.0;
    param_1[3] = 0.0;
  }
  return param_1;
}


// ==== FUN_007a7c7e @ 0x007a7c7e ====

undefined8 * FUN_007a7c7e(undefined8 *param_1,float *param_2,undefined8 *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float fVar22;
  float fVar23;
  float fVar24;
  float fVar25;
  float fVar26;
  float fVar27;
  float fVar28;
  float fVar29;
  float fVar30;
  float fVar31;
  float fVar32;
  
  fVar1 = *param_2;
  fVar2 = param_2[1];
  fVar3 = param_2[2];
  fVar4 = param_2[3];
  fVar17 = (float)*param_3;
  fVar18 = (float)((ulonglong)*param_3 >> 0x20);
  fVar19 = (float)param_3[1];
  fVar20 = (float)((ulonglong)param_3[1] >> 0x20);
  fVar21 = (float)param_3[2];
  fVar22 = (float)((ulonglong)param_3[2] >> 0x20);
  fVar23 = (float)param_3[3];
  fVar24 = (float)((ulonglong)param_3[3] >> 0x20);
  fVar25 = (float)param_3[4];
  fVar26 = (float)((ulonglong)param_3[4] >> 0x20);
  fVar27 = (float)param_3[5];
  fVar28 = (float)((ulonglong)param_3[5] >> 0x20);
  fVar29 = (float)param_3[6];
  fVar30 = (float)((ulonglong)param_3[6] >> 0x20);
  fVar31 = (float)param_3[7];
  fVar32 = (float)((ulonglong)param_3[7] >> 0x20);
  fVar5 = param_2[4];
  fVar6 = param_2[5];
  fVar7 = param_2[6];
  fVar8 = param_2[7];
  fVar9 = param_2[8];
  fVar10 = param_2[9];
  fVar11 = param_2[10];
  fVar12 = param_2[0xb];
  fVar13 = param_2[0xc];
  fVar14 = param_2[0xd];
  fVar15 = param_2[0xe];
  fVar16 = param_2[0xf];
  *param_1 = CONCAT44(fVar5 * fVar17 + fVar6 * fVar21 + fVar7 * fVar25 + fVar8 * fVar29,
                      fVar1 * fVar17 + fVar2 * fVar21 + fVar3 * fVar25 + fVar4 * fVar29);
  param_1[1] = CONCAT44(fVar17 * fVar13 + fVar21 * fVar14 + fVar25 * fVar15 + fVar29 * fVar16,
                        fVar9 * fVar17 + fVar10 * fVar21 + fVar11 * fVar25 + fVar12 * fVar29);
  param_1[2] = CONCAT44(fVar5 * fVar18 + fVar6 * fVar22 + fVar7 * fVar26 + fVar8 * fVar30,
                        fVar1 * fVar18 + fVar2 * fVar22 + fVar3 * fVar26 + fVar4 * fVar30);
  param_1[3] = CONCAT44(fVar18 * fVar13 + fVar22 * fVar14 + fVar26 * fVar15 + fVar30 * fVar16,
                        fVar9 * fVar18 + fVar10 * fVar22 + fVar11 * fVar26 + fVar12 * fVar30);
  param_1[4] = CONCAT44(fVar5 * fVar19 + fVar6 * fVar23 + fVar7 * fVar27 + fVar8 * fVar31,
                        fVar1 * fVar19 + fVar2 * fVar23 + fVar3 * fVar27 + fVar4 * fVar31);
  param_1[5] = CONCAT44(fVar19 * fVar13 + fVar23 * fVar14 + fVar27 * fVar15 + fVar31 * fVar16,
                        fVar9 * fVar19 + fVar10 * fVar23 + fVar11 * fVar27 + fVar12 * fVar31);
  param_1[6] = CONCAT44(fVar5 * fVar20 + fVar6 * fVar24 + fVar7 * fVar28 + fVar8 * fVar32,
                        fVar1 * fVar20 + fVar2 * fVar24 + fVar3 * fVar28 + fVar4 * fVar32);
  param_1[7] = CONCAT44(fVar20 * fVar13 + fVar24 * fVar14 + fVar28 * fVar15 + fVar32 * fVar16,
                        fVar9 * fVar20 + fVar10 * fVar24 + fVar11 * fVar28 + fVar12 * fVar32);
  return param_1;
}


// ==== FUN_007a8143 @ 0x007a8143 ====

void FUN_007a8143(undefined8 *param_1,undefined8 *param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  
  if (((uint)param_3 & 0xf) == 0) {
    fVar3 = *(float *)(param_2 + 1);
    fVar1 = fVar3 * param_3[8];
    fVar2 = fVar3 * param_3[9];
    fVar3 = fVar3 * param_3[10];
    fVar9 = (float)*param_2;
    fVar6 = (float)((ulonglong)*param_2 >> 0x20);
    fVar4 = fVar6 * param_3[4];
    fVar5 = fVar6 * param_3[5];
    fVar6 = fVar6 * param_3[6];
    fVar7 = fVar9 * *param_3;
    fVar8 = fVar9 * param_3[1];
    fVar9 = fVar9 * param_3[2];
  }
  else {
    fVar3 = *(float *)(param_2 + 1);
    fVar1 = (float)*(undefined8 *)(param_3 + 8) * fVar3;
    fVar2 = (float)((ulonglong)*(undefined8 *)(param_3 + 8) >> 0x20) * fVar3;
    fVar3 = (float)*(undefined8 *)(param_3 + 10) * fVar3;
    fVar9 = (float)*param_2;
    fVar6 = (float)((ulonglong)*param_2 >> 0x20);
    fVar4 = (float)*(undefined8 *)(param_3 + 4) * fVar6;
    fVar5 = (float)((ulonglong)*(undefined8 *)(param_3 + 4) >> 0x20) * fVar6;
    fVar6 = (float)*(undefined8 *)(param_3 + 6) * fVar6;
    fVar7 = (float)*(undefined8 *)param_3 * fVar9;
    fVar8 = (float)((ulonglong)*(undefined8 *)param_3 >> 0x20) * fVar9;
    fVar9 = (float)*(undefined8 *)(param_3 + 2) * fVar9;
  }
  *param_1 = CONCAT44(fVar8 + fVar5 + fVar2,fVar7 + fVar4 + fVar1);
  *(float *)(param_1 + 1) = fVar9 + fVar6 + fVar3;
  return;
}


// ==== FUN_007a82ce @ 0x007a82ce ====

void FUN_007a82ce(float *param_1,float *param_2)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float *pfVar4;
  int iVar5;
  int iVar6;
  float local_18 [4];
  int local_8;
  
  pfVar4 = param_2;
  fVar3 = param_2[5] + *param_2 + param_2[10];
  if (fVar3 <= DAT_0099cdc8) {
    local_18[1] = param_2[5];
    pfVar1 = param_2 + 10;
    local_18[0] = *param_2;
    local_18[2] = *pfVar1;
    param_2 = (float *)(uint)(*param_2 < param_2[5]);
    if (local_18[(int)param_2] < *pfVar1) {
      param_2 = (float *)0x2;
    }
    iVar5 = (int)param_2 * 4;
    iVar2 = *(int *)(&DAT_009fcb84 + iVar5);
    iVar6 = iVar2 * 4;
    local_8 = *(int *)(&DAT_009fcb84 + iVar6);
    fVar3 = SQRT(((local_18[(int)param_2] - local_18[iVar2]) - local_18[local_8]) + DAT_0099d080) *
            DAT_0099d0b4;
    param_1[(int)param_2] = fVar3;
    fVar3 = DAT_009fc7a0 / fVar3;
    param_1[iVar2] = (pfVar4[(int)param_2 + iVar6] + pfVar4[iVar2 + iVar5]) * fVar3;
    param_1[local_8] = (pfVar4[(int)param_2 + local_8 * 4] + pfVar4[iVar5 + local_8]) * fVar3;
    param_1[3] = (pfVar4[iVar6 + local_8] - pfVar4[local_8 * 4 + iVar2]) * fVar3;
  }
  else {
    fVar3 = SQRT(fVar3 + DAT_0099d080) * DAT_0099d0b4;
    param_1[3] = fVar3;
    fVar3 = DAT_009fc7a0 / fVar3;
    *param_1 = (param_2[6] - param_2[9]) * fVar3;
    param_1[1] = (param_2[8] - param_2[2]) * fVar3;
    param_1[2] = (param_2[1] - param_2[4]) * fVar3;
  }
  return;
}


// ==== FUN_007a9000 @ 0x007a9000 ====

float * FUN_007a9000(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float *pfVar22;
  int iVar23;
  
  if (0 < param_6) {
    fVar6 = *param_5;
    fVar7 = param_5[1];
    fVar8 = param_5[2];
    fVar9 = param_5[3];
    fVar10 = param_5[4];
    fVar11 = param_5[5];
    fVar12 = param_5[6];
    fVar13 = param_5[7];
    fVar14 = param_5[8];
    fVar15 = param_5[9];
    fVar16 = param_5[10];
    fVar17 = param_5[0xb];
    fVar18 = param_5[0xc];
    fVar19 = param_5[0xd];
    fVar20 = param_5[0xe];
    fVar21 = param_5[0xf];
    pfVar22 = param_1;
    do {
      fVar1 = *param_3;
      fVar2 = param_3[1];
      fVar3 = param_3[2];
      fVar4 = param_3[3];
      param_3 = (float *)(param_4 + (int)param_3);
      *pfVar22 = fVar1 * fVar6 + fVar2 * fVar10 + fVar3 * fVar14 + fVar4 * fVar18;
      pfVar22[1] = fVar1 * fVar7 + fVar2 * fVar11 + fVar3 * fVar15 + fVar4 * fVar19;
      pfVar22[2] = fVar1 * fVar8 + fVar2 * fVar12 + fVar3 * fVar16 + fVar4 * fVar20;
      pfVar22[3] = fVar1 * fVar9 + fVar2 * fVar13 + fVar3 * fVar17 + fVar4 * fVar21;
      pfVar22 = (float *)(param_2 + (int)pfVar22);
      iVar23 = param_6 + -1;
      bVar5 = 0 < param_6;
      param_6 = iVar23;
    } while (iVar23 != 0 && bVar5);
  }
  return param_1;
}


// ==== __break @ 0x007a97c7 ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_007aa000 @ 0x007aa000 ====

float * FUN_007aa000(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  bool bVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float fVar21;
  float *pfVar22;
  int iVar23;
  
  if (0 < param_6) {
    fVar6 = *param_5;
    fVar7 = param_5[1];
    fVar8 = param_5[2];
    fVar9 = param_5[3];
    fVar10 = param_5[4];
    fVar11 = param_5[5];
    fVar12 = param_5[6];
    fVar13 = param_5[7];
    fVar14 = param_5[8];
    fVar15 = param_5[9];
    fVar16 = param_5[10];
    fVar17 = param_5[0xb];
    fVar18 = param_5[0xc];
    fVar19 = param_5[0xd];
    fVar20 = param_5[0xe];
    fVar21 = param_5[0xf];
    pfVar22 = param_1;
    do {
      fVar1 = *param_3;
      fVar2 = param_3[1];
      fVar3 = param_3[2];
      fVar4 = param_3[3];
      param_3 = (float *)(param_4 + (int)param_3);
      *pfVar22 = fVar1 * fVar6 + fVar2 * fVar10 + fVar3 * fVar14 + fVar4 * fVar18;
      pfVar22[1] = fVar1 * fVar7 + fVar2 * fVar11 + fVar3 * fVar15 + fVar4 * fVar19;
      pfVar22[2] = fVar1 * fVar8 + fVar2 * fVar12 + fVar3 * fVar16 + fVar4 * fVar20;
      pfVar22[3] = fVar1 * fVar9 + fVar2 * fVar13 + fVar3 * fVar17 + fVar4 * fVar21;
      pfVar22 = (float *)(param_2 + (int)pfVar22);
      iVar23 = param_6 + -1;
      bVar5 = 0 < param_6;
      param_6 = iVar23;
    } while (iVar23 != 0 && bVar5);
  }
  return param_1;
}


// ==== FUN_007ac000 @ 0x007ac000 ====

float * FUN_007ac000(float *param_1,int param_2,float *param_3,int param_4,float *param_5,
                    int param_6)

{
  float fVar1;
  float fVar2;
  float fVar3;
  bool bVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float fVar14;
  float fVar15;
  float fVar16;
  float fVar17;
  float fVar18;
  float fVar19;
  float fVar20;
  float *pfVar21;
  int iVar22;
  
  if (0 < param_6) {
    fVar5 = *param_5;
    fVar6 = param_5[1];
    fVar7 = param_5[2];
    fVar8 = param_5[3];
    fVar9 = param_5[4];
    fVar10 = param_5[5];
    fVar11 = param_5[6];
    fVar12 = param_5[7];
    fVar13 = param_5[8];
    fVar14 = param_5[9];
    fVar15 = param_5[10];
    fVar16 = param_5[0xb];
    fVar17 = param_5[0xc];
    fVar18 = param_5[0xd];
    fVar19 = param_5[0xe];
    fVar20 = param_5[0xf];
    pfVar21 = param_1;
    do {
      fVar1 = *param_3;
      fVar2 = param_3[1];
      fVar3 = param_3[2];
      param_3 = (float *)(param_4 + (int)param_3);
      *pfVar21 = fVar1 * fVar5 + fVar2 * fVar9 + fVar3 * fVar13 + fVar17;
      pfVar21[1] = fVar1 * fVar6 + fVar2 * fVar10 + fVar3 * fVar14 + fVar18;
      pfVar21[2] = fVar1 * fVar7 + fVar2 * fVar11 + fVar3 * fVar15 + fVar19;
      pfVar21[3] = fVar1 * fVar8 + fVar2 * fVar12 + fVar3 * fVar16 + fVar20;
      pfVar21 = (float *)(param_2 + (int)pfVar21);
      iVar22 = param_6 + -1;
      bVar4 = 0 < param_6;
      param_6 = iVar22;
    } while (iVar22 != 0 && bVar4);
  }
  return param_1;
}


// ==== FUN_007ac732 @ 0x007ac732 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007ac732(undefined8 *param_1,undefined8 *param_2,undefined4 *param_3)

{
  undefined8 uVar1;
  
  uVar1 = param_1[1];
  if (param_2 != (undefined8 *)0x0) {
    *param_2 = *param_1;
    *(int *)(param_2 + 1) = (int)uVar1;
  }
  if (param_3 != (undefined4 *)0x0) {
    uVar1 = FUN_007b41c0();
    uVar1 = PackedFloatingMUL(uVar1,_DAT_009fc848);
    *param_3 = (int)uVar1;
  }
  FastExitMediaState();
  return;
}


// ==== FUN_007acc6c @ 0x007acc6c ====

void FUN_007acc6c(undefined8 *param_1,undefined4 param_2,uint param_3)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined4 uVar4;
  undefined8 local_18;
  uint local_10;
  
  FastExitMediaState();
  FUN_007b1a40(&local_18,param_2);
  PackedFloatingMUL((ulonglong)param_3,DAT_009fc8d0);
  uVar1 = FUN_007b47a0();
  uVar4 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar3 = CONCAT44(uVar4,uVar4);
  uVar2 = PackedFloatingMUL(local_18,uVar3);
  uVar3 = PackedFloatingMUL((ulonglong)local_10,uVar3);
  *param_1 = uVar2;
  param_1[1] = CONCAT44((int)uVar1,(int)uVar3);
  FastExitMediaState();
  return;
}


// ==== FUN_007accd8 @ 0x007accd8 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007accd8(undefined8 *param_1,undefined8 *param_2,undefined8 *param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  uint uVar9;
  uint uVar10;
  
  FastExitMediaState();
  uVar3 = PackedFloatingMUL(*param_2,*param_3);
  uVar5 = PackedFloatingMUL(param_2[1],param_3[1]);
  uVar5 = PackedFloatingADD(uVar3,uVar5);
  uVar3 = PackedFloatingSUB((ulonglong)DAT_009fc8c8,(ulonglong)param_4);
  uVar1 = (uint)uVar3;
  uVar4 = PackedFloatingAccumulate(uVar5,uVar5);
  uVar8 = PackedFloatingCompareGE(0,uVar4);
  uVar8 = uVar8 & _DAT_009fc910;
  uVar4 = uVar4 ^ uVar8;
  uVar5 = PackedFloatingCompareGE(DAT_009fc928,uVar4);
  uVar3 = PackedFloatingMUL(uVar4,uVar4);
  uVar3 = PackedFloatingSUBR(uVar3,CONCAT44(uRam009fc8cc,DAT_009fc8c8));
  if ((int)uVar5 != 0) {
    uVar6 = PackedFloatingReciprocalSQRAprox((ulonglong)param_4,uVar3);
    uVar5 = PackedFloatingMUL(uVar6,uVar6);
    uVar3 = PackedFloatingReciprocalSQRIter1(uVar3,uVar5);
    uVar6 = PackedFloatingReciprocalIter2(uVar3,uVar6);
    uVar3 = FloatingReciprocalAprox(uVar5,uVar6);
    uVar5 = PackedFloatingReciprocalIter1(uVar6,uVar3);
    PackedFloatingReciprocalIter2(uVar5,uVar3);
    uVar9 = (uint)uVar6;
    uVar3 = FUN_007b40c0();
    uVar10 = (uint)uVar3;
    PackedFloatingMUL(uVar3,(ulonglong)param_4);
    uVar2 = FUN_007b48a0(uVar1,uVar9,uVar10);
    PackedFloatingMUL((ulonglong)uVar10,(ulonglong)uVar1);
    uVar3 = FUN_007b48a0();
    uVar8 = uVar8 & 0xffffffff;
    uVar3 = PackedFloatingMUL(uVar3,(ulonglong)uVar9);
    uVar1 = (uint)uVar3;
    uVar3 = PackedFloatingMUL((ulonglong)uVar2,(ulonglong)uVar9);
    param_4 = (uint)uVar3;
  }
  param_4 = param_4 ^ (uint)uVar8;
  uVar5 = CONCAT44(param_4,param_4);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),*param_2);
  uVar6 = PackedFloatingMUL(uVar5,*param_3);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),param_2[1]);
  uVar5 = PackedFloatingMUL(uVar5,param_3[1]);
  uVar3 = PackedFloatingADD(uVar3,uVar6);
  uVar5 = PackedFloatingADD(uVar7,uVar5);
  *param_1 = uVar3;
  param_1[1] = uVar5;
  FastExitMediaState();
  return;
}


// ==== FUN_007ace0f @ 0x007ace0f ====

undefined4
FUN_007ace0f(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            uint param_5,uint param_6)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined8 in_MM2;
  undefined8 uVar3;
  undefined1 local_28 [16];
  undefined1 local_18 [20];
  
  FastExitMediaState();
  uVar1 = PackedFloatingADD((ulonglong)param_5,(ulonglong)param_6);
  FUN_007accd8(local_28,param_2,param_3,(int)uVar1);
  FUN_007accd8(local_18,param_2,param_4,(int)uVar1);
  uVar3 = FloatingReciprocalAprox(in_MM2,uVar1 & 0xffffffff);
  uVar2 = PackedFloatingReciprocalIter1(uVar1 & 0xffffffff,uVar3);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar3);
  uVar2 = PackedFloatingMUL(uVar2,(ulonglong)param_6);
  FUN_007accd8(param_1,local_28,local_18,(int)uVar2);
  FastExitMediaState();
  return param_1;
}


// ==== FUN_007ace9c @ 0x007ace9c ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007ace9c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,uint param_6)

{
  ulonglong uVar1;
  undefined8 uVar2;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  FUN_007accd8(local_20,param_2,param_5,param_6);
  FUN_007accd8(local_10,param_3,param_4,param_6);
  uVar1 = (ulonglong)param_6;
  uVar2 = PackedFloatingMUL(uVar1,uVar1);
  uVar2 = PackedFloatingSUB(uVar1,uVar2);
  uVar2 = PackedFloatingMUL(uVar2,_DAT_009fc848);
  FUN_007accd8(param_1,local_20,local_10,(int)uVar2);
  FastExitMediaState();
  return;
}


// ==== FUN_007acf92 @ 0x007acf92 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007acf92(undefined8 *param_1,undefined8 *param_2)

{
  undefined4 uVar1;
  ulonglong uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 in_MM4;
  undefined8 uVar6;
  
  FastExitMediaState();
  uVar3 = *param_2;
  uVar4 = param_2[1];
  uVar1 = (undefined4)(uVar4 >> 0x20);
  uVar5 = PackedFloatingCompareGE(CONCAT44(uVar1,uVar1),_DAT_009fc8c8);
  if ((int)uVar5 == 0) {
    uVar1 = FUN_007b41c0();
    uVar2 = FUN_007b48a0();
    uVar5 = PackedFloatingCompareGE(uVar2 & _DAT_009fc880,DAT_009fc888);
    uVar3 = *param_2;
    uVar4 = param_2[1];
    if ((int)uVar5 != 0) {
      uVar6 = FloatingReciprocalAprox(in_MM4,uVar2);
      uVar5 = PackedFloatingReciprocalIter1(uVar2,uVar6);
      uVar5 = PackedFloatingReciprocalIter2(uVar5,uVar6);
      uVar5 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar5);
      uVar3 = PackedFloatingMUL(uVar3,uVar5);
      uVar4 = PackedFloatingMUL(uVar4,uVar5);
    }
  }
  uVar4 = uVar4 & _DAT_009fc890;
  *param_1 = uVar3;
  param_1[1] = uVar4;
  FastExitMediaState();
  return;
}


// ==== FUN_007ad0de @ 0x007ad0de ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007ad0de(undefined8 *param_1,undefined8 *param_2,ulonglong *param_3,ulonglong *param_4,
                 ulonglong *param_5,ulonglong *param_6,ulonglong *param_7)

{
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 uVar1;
  undefined8 uVar2;
  ulonglong uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined8 uVar6;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 uVar9;
  ulonglong uVar10;
  undefined8 uVar11;
  undefined8 uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  undefined8 uVar15;
  ulonglong local_a8;
  ulonglong local_a0;
  ulonglong local_88;
  ulonglong local_80;
  ulonglong local_78;
  ulonglong local_70;
  undefined4 local_20;
  
  local_a8 = *param_4;
  local_a0 = param_4[1];
  uVar8 = *param_5;
  uVar14 = param_5[1];
  uVar2 = PackedFloatingADD(local_a8,uVar8);
  uVar4 = PackedFloatingADD(local_a0,uVar14);
  uVar6 = PackedFloatingSUB(local_a8,uVar8);
  uVar2 = PackedFloatingMUL(uVar2,uVar2);
  uVar9 = PackedFloatingSUB(local_a0,uVar14);
  uVar4 = PackedFloatingMUL(uVar4,uVar4);
  uVar6 = PackedFloatingMUL(uVar6,uVar6);
  uVar9 = PackedFloatingMUL(uVar9,uVar9);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar6 = PackedFloatingADD(uVar6,uVar9);
  local_88 = *param_6;
  local_80 = param_6[1];
  uVar11 = PackedFloatingADD(uVar8,local_88);
  uVar12 = PackedFloatingADD(uVar14,local_80);
  uVar4 = PackedFloatingSUB(uVar8,local_88);
  uVar9 = PackedFloatingSUB(uVar14,local_80);
  uVar11 = PackedFloatingMUL(uVar11,uVar11);
  uVar12 = PackedFloatingMUL(uVar12,uVar12);
  uVar4 = PackedFloatingMUL(uVar4,uVar4);
  uVar9 = PackedFloatingMUL(uVar9,uVar9);
  uVar11 = PackedFloatingADD(uVar11,uVar12);
  uVar4 = PackedFloatingADD(uVar4,uVar9);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar11);
  uVar4 = PackedFloatingAccumulate(uVar6,uVar4);
  uVar2 = PackedFloatingCompareGT(uVar4,uVar2);
  uVar7 = packsswb(uVar2,uVar2);
  if ((uVar7 & 1) != 0) {
    local_a8 = DAT_009fc868 ^ *param_4;
    local_a0 = DAT_009fc868 ^ param_4[1];
  }
  if ((uVar7 & 0x10000) != 0) {
    local_88 = DAT_009fc868 ^ *param_6;
    local_80 = DAT_009fc868 ^ param_6[1];
  }
  local_78 = *param_7;
  uVar7 = param_7[1];
  uVar6 = PackedFloatingADD(local_88,local_78);
  uVar9 = PackedFloatingADD(local_80,uVar7);
  uVar2 = PackedFloatingSUB(local_88,local_78);
  uVar4 = PackedFloatingSUB(local_80,uVar7);
  uVar6 = PackedFloatingMUL(uVar6,uVar6);
  uVar9 = PackedFloatingMUL(uVar9,uVar9);
  uVar2 = PackedFloatingMUL(uVar2,uVar2);
  uVar4 = PackedFloatingMUL(uVar4,uVar4);
  uVar6 = PackedFloatingADD(uVar6,uVar9);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar4 = PackedFloatingAccumulate(uVar6,uVar6);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar10 = PackedFloatingCompareGT(uVar2,uVar4);
  local_70 = uVar7;
  if ((uVar10 & 1) != 0) {
    local_78 = DAT_009fc868 ^ *param_7;
    local_70 = DAT_009fc868 ^ param_7[1];
  }
  uVar2 = PackedFloatingMUL(uVar8,uVar8);
  uVar4 = PackedFloatingMUL(uVar14,uVar14);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar4 = FloatingReciprocalAprox(uVar7,uVar2);
  uVar7 = PackedFloatingCompareGT(uVar2,_DAT_009fc8b0);
  uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar4);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar4);
  uVar4 = PackedFloatingMUL((uVar8 ^ _DAT_009fc910) & uVar7,uVar2);
  uVar11 = PackedFloatingMUL((uVar14 ^ _DAT_009fc858) & uVar7,uVar2);
  uVar10 = CONCAT44((int)local_a8,(int)(local_a8 >> 0x20));
  uVar3 = CONCAT44((int)local_a0,(int)(local_a0 >> 0x20));
  uVar7 = PackedFloatingMUL(local_a8,uVar11);
  uVar2 = PackedFloatingMUL(local_a0,uVar4);
  uVar9 = PackedFloatingMUL(uVar3 ^ _DAT_009fc858,uVar4);
  uVar6 = PackedFloatingMUL(uVar10,uVar11);
  uVar2 = PackedFloatingADD(uVar7 ^ _DAT_009fc858,uVar2);
  uVar6 = PackedFloatingSUB(uVar6,uVar9);
  uVar15 = PackedFloatingMUL(uVar3,uVar11);
  uVar6 = PackedFloatingAccumulate(uVar6,uVar2);
  uVar12 = PackedFloatingMUL(uVar10 ^ _DAT_009fc858,uVar4);
  uVar2 = PackedFloatingMUL(local_a8,uVar4);
  uVar9 = PackedFloatingMUL(local_a0 ^ _DAT_009fc858,uVar11);
  uVar12 = PackedFloatingADD(uVar12,uVar15);
  uVar2 = PackedFloatingSUB(uVar9,uVar2);
  uVar10 = PackedFloatingAccumulate(uVar12,uVar2);
  uVar3 = CONCAT44((int)local_88,(int)(local_88 >> 0x20));
  uVar13 = CONCAT44((int)local_80,(int)(local_80 >> 0x20));
  uVar7 = PackedFloatingMUL(local_88,uVar11);
  uVar2 = PackedFloatingMUL(local_80,uVar4);
  uVar12 = PackedFloatingMUL(uVar13 ^ _DAT_009fc858,uVar4);
  uVar9 = PackedFloatingMUL(uVar3,uVar11);
  uVar2 = PackedFloatingADD(uVar7 ^ _DAT_009fc858,uVar2);
  uVar9 = PackedFloatingSUB(uVar9,uVar12);
  uVar15 = PackedFloatingMUL(uVar13,uVar11);
  uVar9 = PackedFloatingAccumulate(uVar9,uVar2);
  uVar12 = PackedFloatingMUL(uVar3 ^ _DAT_009fc858,uVar4);
  uVar2 = PackedFloatingMUL(local_88,uVar4);
  uVar4 = PackedFloatingMUL(local_80 ^ _DAT_009fc858,uVar11);
  uVar11 = PackedFloatingADD(uVar12,uVar15);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar7 = PackedFloatingAccumulate(uVar11,uVar2);
  uVar1 = (undefined4)(uVar10 >> 0x20);
  uVar4 = PackedFloatingCompareGE(CONCAT44(uVar1,uVar1),_DAT_009fc8c8);
  uVar2 = uVar9;
  if ((int)uVar4 == 0) {
    uVar1 = FUN_007b41c0();
    uVar3 = FUN_007b48a0();
    uVar4 = PackedFloatingCompareGE(uVar3 & _DAT_009fc880,DAT_009fc888);
    if ((int)uVar4 != 0) {
      uVar2 = FloatingReciprocalAprox(uVar2,uVar3);
      uVar4 = PackedFloatingReciprocalIter1(uVar3,uVar2);
      uVar4 = PackedFloatingReciprocalIter2(uVar4,uVar2);
      uVar4 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar4);
      uVar6 = PackedFloatingMUL(uVar6,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,uVar4);
    }
  }
  uVar10 = uVar10 & _DAT_009fc890;
  uVar1 = (undefined4)(uVar7 >> 0x20);
  uVar4 = PackedFloatingCompareGE(CONCAT44(uVar1,uVar1),_DAT_009fc8c8);
  if ((int)uVar4 == 0) {
    uVar1 = FUN_007b41c0();
    uVar3 = FUN_007b48a0(uVar1,unaff_ESI,unaff_EBX);
    uVar4 = PackedFloatingCompareGE(uVar3 & _DAT_009fc880,DAT_009fc888);
    if ((int)uVar4 != 0) {
      uVar4 = FloatingReciprocalAprox(uVar2,uVar3);
      uVar2 = PackedFloatingReciprocalIter1(uVar3,uVar4);
      uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar4);
      uVar2 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar2);
      uVar9 = PackedFloatingMUL(uVar9,uVar2);
      uVar7 = PackedFloatingMUL(uVar7,uVar2);
    }
  }
  uVar2 = PackedFloatingADD(uVar6,uVar9);
  uVar4 = PackedFloatingADD(uVar10,uVar7 & _DAT_009fc890);
  uVar2 = PackedFloatingMUL(uVar2,_DAT_009fcb90);
  uVar3 = PackedFloatingMUL(uVar4,_DAT_009fcb90);
  local_20 = (undefined4)uVar3;
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar6 = PackedFloatingMUL(uVar3 & 0xffffffff,uVar3 & 0xffffffff);
  uVar4 = PackedFloatingADD(uVar4,uVar6);
  uVar4 = PackedFloatingAccumulate(uVar4,uVar4);
  uVar6 = PackedFloatingReciprocalSQRAprox(uVar6,uVar4);
  uVar9 = PackedFloatingMUL(uVar6,uVar6);
  uVar9 = PackedFloatingReciprocalSQRIter1(uVar9,uVar4);
  uVar6 = PackedFloatingReciprocalIter2(uVar9,uVar6);
  uVar1 = (undefined4)uVar6;
  PackedFloatingMUL(uVar4,uVar6);
  uVar7 = FUN_007b47a0(uVar1,unaff_ESI,unaff_EBX);
  uVar10 = PackedFloatingCompareGE(uVar7 & _DAT_009fc878,DAT_009fc888);
  uVar5 = (undefined4)(uVar7 >> 0x20);
  uVar4 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),CONCAT44(unaff_ESI,uVar1));
  if ((uVar10 & 0x100000000) != 0) {
    uVar4 = CONCAT44((int)uVar4,(int)uVar4);
    uVar6 = PackedFloatingMUL(uVar3 & 0xffffffff,uVar4);
    local_20 = (undefined4)uVar6;
    uVar2 = PackedFloatingMUL(uVar2,uVar4);
  }
  uVar10 = CONCAT44((int)uVar7,local_20);
  uVar3 = CONCAT44((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  uVar13 = CONCAT44(local_20,(int)uVar7);
  uVar7 = PackedFloatingMUL(uVar2,uVar14);
  uVar4 = PackedFloatingMUL(uVar10,uVar8);
  uVar9 = PackedFloatingMUL(uVar13 ^ _DAT_009fc858,uVar8);
  uVar6 = PackedFloatingMUL(uVar3,uVar14);
  uVar4 = PackedFloatingADD(uVar7 ^ _DAT_009fc858,uVar4);
  uVar6 = PackedFloatingSUB(uVar6,uVar9);
  uVar11 = PackedFloatingMUL(uVar13,uVar14);
  uVar6 = PackedFloatingAccumulate(uVar6,uVar4);
  uVar9 = PackedFloatingMUL(uVar3 ^ _DAT_009fc858,uVar8);
  uVar10 = uVar10 ^ _DAT_009fc858;
  uVar2 = PackedFloatingMUL(uVar2,uVar8);
  *param_1 = uVar6;
  uVar4 = PackedFloatingMUL(uVar10,uVar14);
  uVar9 = PackedFloatingADD(uVar9,uVar11);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar2 = PackedFloatingAccumulate(uVar9,uVar2);
  param_1[1] = uVar2;
  uVar2 = PackedFloatingMUL(local_88,local_88);
  uVar4 = PackedFloatingMUL(local_80,local_80);
  uVar2 = PackedFloatingADD(uVar2,uVar4);
  uVar2 = PackedFloatingAccumulate(uVar2,uVar2);
  uVar4 = FloatingReciprocalAprox(uVar6,uVar2);
  uVar7 = PackedFloatingCompareGT(uVar2,_DAT_009fc8b0);
  uVar2 = PackedFloatingReciprocalIter1(uVar2,uVar4);
  uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar4);
  uVar4 = PackedFloatingMUL((local_88 ^ _DAT_009fc910) & uVar7,uVar2);
  uVar11 = PackedFloatingMUL((local_80 ^ _DAT_009fc858) & uVar7,uVar2);
  uVar10 = CONCAT44((int)uVar8,(int)(uVar8 >> 0x20));
  uVar3 = CONCAT44((int)uVar14,(int)(uVar14 >> 0x20));
  uVar7 = PackedFloatingMUL(uVar8,uVar11);
  uVar2 = PackedFloatingMUL(uVar14,uVar4);
  uVar9 = PackedFloatingMUL(uVar3 ^ _DAT_009fc858,uVar4);
  uVar6 = PackedFloatingMUL(uVar10,uVar11);
  uVar2 = PackedFloatingADD(uVar7 ^ _DAT_009fc858,uVar2);
  uVar6 = PackedFloatingSUB(uVar6,uVar9);
  uVar15 = PackedFloatingMUL(uVar3,uVar11);
  uVar6 = PackedFloatingAccumulate(uVar6,uVar2);
  uVar12 = PackedFloatingMUL(uVar10 ^ _DAT_009fc858,uVar4);
  uVar2 = PackedFloatingMUL(uVar8,uVar4);
  uVar9 = PackedFloatingMUL(uVar14 ^ _DAT_009fc858,uVar11);
  uVar12 = PackedFloatingADD(uVar12,uVar15);
  uVar2 = PackedFloatingSUB(uVar9,uVar2);
  uVar14 = PackedFloatingAccumulate(uVar12,uVar2);
  uVar7 = CONCAT44((int)local_78,(int)(local_78 >> 0x20));
  uVar10 = CONCAT44((int)local_70,(int)(local_70 >> 0x20));
  uVar8 = PackedFloatingMUL(local_78,uVar11);
  uVar2 = PackedFloatingMUL(local_70,uVar4);
  uVar12 = PackedFloatingMUL(uVar10 ^ _DAT_009fc858,uVar4);
  uVar9 = PackedFloatingMUL(uVar7,uVar11);
  uVar2 = PackedFloatingADD(uVar8 ^ _DAT_009fc858,uVar2);
  uVar9 = PackedFloatingSUB(uVar9,uVar12);
  uVar15 = PackedFloatingMUL(uVar10,uVar11);
  uVar9 = PackedFloatingAccumulate(uVar9,uVar2);
  uVar12 = PackedFloatingMUL(uVar7 ^ _DAT_009fc858,uVar4);
  uVar2 = PackedFloatingMUL(local_78,uVar4);
  uVar4 = PackedFloatingMUL(local_70 ^ _DAT_009fc858,uVar11);
  uVar11 = PackedFloatingADD(uVar12,uVar15);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar8 = PackedFloatingAccumulate(uVar11,uVar2);
  uVar1 = (undefined4)(uVar14 >> 0x20);
  uVar4 = PackedFloatingCompareGE(CONCAT44(uVar1,uVar1),_DAT_009fc8c8);
  uVar2 = uVar9;
  if ((int)uVar4 == 0) {
    uVar1 = FUN_007b41c0();
    uVar7 = FUN_007b48a0(uVar1,unaff_ESI,unaff_EBX);
    uVar4 = PackedFloatingCompareGE(uVar7 & _DAT_009fc880,DAT_009fc888);
    if ((int)uVar4 != 0) {
      uVar2 = FloatingReciprocalAprox(uVar2,uVar7);
      uVar4 = PackedFloatingReciprocalIter1(uVar7,uVar2);
      uVar4 = PackedFloatingReciprocalIter2(uVar4,uVar2);
      uVar4 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar4);
      uVar6 = PackedFloatingMUL(uVar6,uVar4);
      uVar14 = PackedFloatingMUL(uVar14,uVar4);
    }
  }
  uVar14 = uVar14 & _DAT_009fc890;
  uVar1 = (undefined4)(uVar8 >> 0x20);
  uVar4 = PackedFloatingCompareGE(CONCAT44(uVar1,uVar1),_DAT_009fc8c8);
  if ((int)uVar4 == 0) {
    uVar1 = FUN_007b41c0();
    uVar7 = FUN_007b48a0(uVar1,unaff_ESI,unaff_EBX);
    uVar4 = PackedFloatingCompareGE(uVar7 & _DAT_009fc880,DAT_009fc888);
    if ((int)uVar4 != 0) {
      uVar4 = FloatingReciprocalAprox(uVar2,uVar7);
      uVar2 = PackedFloatingReciprocalIter1(uVar7,uVar4);
      uVar2 = PackedFloatingReciprocalIter2(uVar2,uVar4);
      uVar2 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar2);
      uVar9 = PackedFloatingMUL(uVar9,uVar2);
      uVar8 = PackedFloatingMUL(uVar8,uVar2);
    }
  }
  uVar2 = PackedFloatingADD(uVar6,uVar9);
  uVar4 = PackedFloatingADD(uVar14,uVar8 & _DAT_009fc890);
  uVar2 = PackedFloatingMUL(uVar2,_DAT_009fcb90);
  uVar7 = PackedFloatingMUL(uVar4,_DAT_009fcb90);
  local_20 = (undefined4)uVar7;
  uVar4 = PackedFloatingMUL(uVar2,uVar2);
  uVar6 = PackedFloatingMUL(uVar7 & 0xffffffff,uVar7 & 0xffffffff);
  uVar4 = PackedFloatingADD(uVar4,uVar6);
  uVar4 = PackedFloatingAccumulate(uVar4,uVar4);
  uVar6 = PackedFloatingReciprocalSQRAprox(uVar6,uVar4);
  uVar9 = PackedFloatingMUL(uVar6,uVar6);
  uVar9 = PackedFloatingReciprocalSQRIter1(uVar9,uVar4);
  uVar6 = PackedFloatingReciprocalIter2(uVar9,uVar6);
  uVar1 = (undefined4)uVar6;
  PackedFloatingMUL(uVar4,uVar6);
  uVar8 = FUN_007b47a0(uVar1,unaff_ESI,unaff_EBX);
  uVar14 = PackedFloatingCompareGE(uVar8 & _DAT_009fc878,DAT_009fc888);
  uVar5 = (undefined4)(uVar8 >> 0x20);
  uVar4 = PackedFloatingMUL(CONCAT44(uVar5,uVar5),CONCAT44(unaff_ESI,uVar1));
  if ((uVar14 & 0x100000000) != 0) {
    uVar4 = CONCAT44((int)uVar4,(int)uVar4);
    uVar6 = PackedFloatingMUL(uVar7 & 0xffffffff,uVar4);
    local_20 = (undefined4)uVar6;
    uVar2 = PackedFloatingMUL(uVar2,uVar4);
  }
  uVar14 = CONCAT44((int)uVar8,local_20);
  uVar7 = CONCAT44((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  uVar10 = CONCAT44(local_20,(int)uVar8);
  uVar8 = PackedFloatingMUL(uVar2,local_80);
  uVar4 = PackedFloatingMUL(uVar14,local_88);
  uVar9 = PackedFloatingMUL(uVar10 ^ _DAT_009fc858,local_88);
  uVar6 = PackedFloatingMUL(uVar7,local_80);
  uVar4 = PackedFloatingADD(uVar8 ^ _DAT_009fc858,uVar4);
  uVar6 = PackedFloatingSUB(uVar6,uVar9);
  uVar9 = PackedFloatingMUL(uVar10,local_80);
  uVar4 = PackedFloatingAccumulate(uVar6,uVar4);
  uVar6 = PackedFloatingMUL(uVar7 ^ _DAT_009fc858,local_88);
  uVar14 = uVar14 ^ _DAT_009fc858;
  uVar2 = PackedFloatingMUL(uVar2,local_88);
  *param_2 = uVar4;
  uVar4 = PackedFloatingMUL(uVar14,local_80);
  uVar6 = PackedFloatingADD(uVar6,uVar9);
  uVar2 = PackedFloatingSUB(uVar4,uVar2);
  uVar2 = PackedFloatingAccumulate(uVar6,uVar2);
  param_2[1] = uVar2;
  *param_3 = local_88;
  param_3[1] = local_80;
  FastExitMediaState();
  return;
}


// ==== FUN_007ae38e @ 0x007ae38e ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007ae38e(ulonglong *param_1,undefined8 *param_2,undefined8 *param_3,ulonglong *param_4,
                 undefined8 *param_5,undefined8 *param_6,undefined8 *param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  longlong lVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined4 uVar9;
  ulonglong uVar7;
  ulonglong uVar8;
  undefined8 uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  ulonglong uVar14;
  ulonglong uVar15;
  undefined4 uVar18;
  ulonglong uVar16;
  undefined8 uVar17;
  ulonglong uVar19;
  undefined8 uVar20;
  longlong lVar21;
  undefined8 uVar22;
  undefined8 uVar23;
  undefined8 uVar24;
  uint uVar27;
  undefined8 uVar25;
  undefined8 uVar26;
  undefined4 uVar28;
  undefined8 uVar29;
  undefined4 uVar32;
  ulonglong uVar30;
  ulonglong uVar31;
  
  uVar14 = DAT_009fc820;
  if (param_4 == (ulonglong *)0x0) {
    uVar14 = (ulonglong)DAT_009fc830;
    *param_1 = uVar14;
    param_1[1] = 0;
    param_1[2] = uVar14 << 0x20;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = uVar14;
    param_1[6] = 0;
    param_1[7] = uVar14 << 0x20;
  }
  else if (param_3 == (undefined8 *)0x0) {
    if (param_2 == (undefined8 *)0x0) {
      uVar30 = *param_4;
      uVar6 = param_4[1];
      *param_1 = uVar30 & 0xffffffff;
      param_1[1] = 0;
      param_1[2] = uVar30 & 0xffffffff00000000;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = (ulonglong)(uint)uVar6;
      param_1[6] = 0;
      param_1[7] = uVar14;
    }
    else {
      uVar5 = CONCAT44(_DAT_009fc844,DAT_009fc840);
      uVar24 = *param_2;
      uVar14 = *param_4;
      uVar30 = param_4[1];
      uVar4 = CONCAT44(DAT_009fc840,*(undefined4 *)(param_2 + 1));
      uVar2 = PackedFloatingSUB(uVar5,uVar14);
      param_1[5] = (ulonglong)(uint)uVar30;
      uVar5 = PackedFloatingSUB(uVar5,(ulonglong)(uint)uVar30);
      param_1[1] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      uVar30 = PackedFloatingMUL(uVar2,uVar24);
      uVar6 = PackedFloatingMUL(uVar5,uVar4);
      *param_1 = uVar14 & 0xffffffff;
      param_1[2] = uVar14 & 0xffffffff00000000;
      param_1[6] = uVar30;
      param_1[7] = uVar6;
    }
  }
  else {
    uVar15 = (ulonglong)(uint)param_4[1];
    uVar31 = *param_4 & 0xffffffff;
    uVar19 = *param_4 & 0xffffffff00000000;
    uVar24 = *param_3;
    uVar5 = param_3[1];
    uVar2 = PackedFloatingADD(uVar24,uVar24);
    uVar4 = PackedFloatingADD(uVar5,uVar5);
    uVar9 = (undefined4)((ulonglong)uVar24 >> 0x20);
    uVar18 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar29 = CONCAT44(uVar18,uVar18);
    uVar10 = PackedFloatingMUL(uVar24,uVar2);
    uVar24 = CONCAT44((int)uVar2,(int)uVar4);
    uVar20 = PackedFloatingMUL(uVar2,uVar29);
    uVar4 = PackedFloatingMUL(CONCAT44((int)uVar5,(int)uVar5),uVar24);
    uVar5 = PackedFloatingMUL(uVar24,CONCAT44(uVar9,uVar9));
    uVar24 = PackedFloatingMUL(uVar24,uVar29);
    uVar2 = CONCAT44((int)((ulonglong)uVar4 >> 0x20),(int)((ulonglong)uVar5 >> 0x20));
    uVar29 = PackedFloatingADD(CONCAT44((int)uVar4,(int)uVar4),uVar10);
    uVar4 = PackedFloatingAccumulate(uVar10,uVar10);
    uVar24 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),(int)uVar24);
    uVar11 = PackedFloatingSUBR(uVar4,CONCAT44(_DAT_009fc844,DAT_009fc840));
    uVar10 = PackedFloatingSUBR(uVar29,CONCAT44(_DAT_009fc844,DAT_009fc840));
    uVar12 = uVar11 & 0xffffffff;
    uVar4 = PackedFloatingADD(uVar2,uVar24);
    uVar16 = PackedFloatingSUB(uVar2,uVar24);
    uVar7 = PackedFloatingADD(uVar5,uVar20);
    uVar13 = PackedFloatingSUB(uVar5,uVar20);
    uVar8 = uVar7 & 0xffffffff;
    uVar18 = (undefined4)uVar16;
    uVar28 = (undefined4)uVar10;
    uVar5 = CONCAT44(uVar28,uVar18);
    uVar9 = (undefined4)uVar4;
    uVar30 = uVar16 >> 0x20;
    uVar6 = (ulonglong)DAT_009fc840;
    lVar3 = uVar6 << 0x20;
    uVar27 = (uint)((ulonglong)uVar4 >> 0x20);
    uVar32 = (undefined4)((ulonglong)uVar10 >> 0x20);
    uVar24 = CONCAT44(uVar9,uVar32);
    uVar2 = CONCAT44((int)uVar13,uVar27);
    uVar1 = (undefined4)(uVar16 >> 0x20);
    if (param_2 == (undefined8 *)0x0) {
      *param_1 = CONCAT44(uVar18,uVar32);
      param_1[2] = CONCAT44(uVar28,uVar9);
      param_1[5] = uVar11 & 0xffffffff;
      param_1[7] = uVar6 << 0x20;
      param_1[4] = CONCAT44((int)uVar7,uVar1);
      param_1[6] = 0;
      param_1[3] = uVar13 & 0xffffffff;
      param_1[1] = (ulonglong)uVar27;
      uVar9 = (undefined4)(*param_1 >> 0x20);
      uVar18 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar31,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,0);
      uVar23 = PackedFloatingMUL(uVar19,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,0);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(0,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar15);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,uVar14);
      uVar13 = PackedFloatingADD(uVar26,uVar20);
      uVar6 = PackedFloatingADD(uVar10,uVar4);
      *param_1 = uVar13;
      param_1[1] = uVar6;
      uVar9 = (undefined4)(param_1[2] >> 0x20);
      uVar18 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar31,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,0);
      uVar23 = PackedFloatingMUL(uVar19,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,0);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(0,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar15);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,uVar14);
      uVar13 = PackedFloatingADD(uVar26,uVar20);
      uVar6 = PackedFloatingADD(uVar10,uVar4);
      param_1[2] = uVar13;
      param_1[3] = uVar6;
      uVar9 = (undefined4)(param_1[4] >> 0x20);
      uVar18 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar31,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,0);
      uVar23 = PackedFloatingMUL(uVar19,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,0);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(0,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar15);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,uVar14);
      uVar13 = PackedFloatingADD(uVar26,uVar20);
      uVar6 = PackedFloatingADD(uVar10,uVar4);
      param_1[4] = uVar13;
      param_1[5] = uVar6;
      uVar9 = (undefined4)(param_1[6] >> 0x20);
      uVar18 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar31,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,0);
      uVar23 = PackedFloatingMUL(uVar19,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,0);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(0,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar15);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,uVar14);
      uVar6 = PackedFloatingADD(uVar26,uVar20);
      uVar14 = PackedFloatingADD(uVar10,uVar4);
      param_1[6] = uVar6;
      param_1[7] = uVar14;
      uVar9 = (undefined4)(*param_1 >> 0x20);
      uVar18 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar24,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar30);
      uVar23 = PackedFloatingMUL(uVar5,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar8);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar2,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar12);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar3);
      uVar6 = PackedFloatingADD(uVar26,uVar20);
      uVar14 = PackedFloatingADD(uVar10,uVar4);
      *param_1 = uVar6;
      param_1[1] = uVar14;
      uVar9 = (undefined4)(param_1[2] >> 0x20);
      uVar18 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar24,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar30);
      uVar23 = PackedFloatingMUL(uVar5,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar8);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar2,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar12);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar3);
      uVar6 = PackedFloatingADD(uVar26,uVar20);
      uVar14 = PackedFloatingADD(uVar10,uVar4);
      param_1[2] = uVar6;
      param_1[3] = uVar14;
      uVar9 = (undefined4)(param_1[4] >> 0x20);
      uVar18 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar24,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar30);
      uVar23 = PackedFloatingMUL(uVar5,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar8);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar2,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar12);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar3);
      uVar6 = PackedFloatingADD(uVar26,uVar20);
      uVar14 = PackedFloatingADD(uVar10,uVar4);
      param_1[4] = uVar6;
      param_1[5] = uVar14;
      uVar9 = (undefined4)(param_1[6] >> 0x20);
      uVar18 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar4 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar29 = PackedFloatingMUL(uVar24,uVar4);
      uVar24 = CONCAT44(uVar9,uVar9);
      uVar4 = PackedFloatingMUL(uVar4,uVar30);
      uVar20 = PackedFloatingMUL(uVar5,uVar24);
      uVar5 = CONCAT44(uVar18,uVar18);
      uVar24 = PackedFloatingMUL(uVar24,uVar8);
      uVar29 = PackedFloatingADD(uVar20,uVar29);
      uVar20 = PackedFloatingMUL(uVar2,uVar10);
      uVar2 = PackedFloatingADD(uVar24,uVar4);
      uVar24 = PackedFloatingMUL(uVar10,uVar12);
      uVar4 = PackedFloatingADD(uVar20,uVar29);
      uVar10 = PackedFloatingMUL(0,uVar5);
      uVar24 = PackedFloatingADD(uVar2,uVar24);
      uVar5 = PackedFloatingMUL(uVar5,lVar3);
      uVar30 = PackedFloatingADD(uVar10,uVar4);
      uVar14 = PackedFloatingADD(uVar5,uVar24);
      param_1[6] = uVar30;
      param_1[7] = uVar14;
    }
    else {
      uVar29 = CONCAT44(uVar18,uVar32);
      uVar23 = CONCAT44(uVar28,uVar9);
      uVar11 = uVar11 & 0xffffffff;
      lVar21 = (ulonglong)DAT_009fc840 << 0x20;
      uVar25 = CONCAT44((int)uVar7,uVar1);
      uVar13 = uVar13 & 0xffffffff;
      uVar7 = (ulonglong)uVar27;
      uVar4 = *param_2;
      uVar27 = *(uint *)(param_2 + 1);
      uVar6 = (ulonglong)DAT_009fc830;
      *param_1 = uVar6;
      param_1[1] = 0;
      param_1[2] = uVar6 << 0x20;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = uVar6;
      uVar16 = PackedFloatingSUB(uVar6 << 0x20,(ulonglong)uVar27);
      uVar6 = PackedFloatingSUB(0,uVar4);
      param_1[7] = uVar16;
      param_1[6] = uVar6;
      uVar9 = (undefined4)(*param_1 >> 0x20);
      uVar18 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar26 = CONCAT44(uVar1,uVar1);
      uVar17 = PackedFloatingMUL(uVar29,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar20 = PackedFloatingMUL(uVar10,uVar7);
      uVar22 = PackedFloatingMUL(uVar23,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar13);
      uVar17 = PackedFloatingADD(uVar22,uVar17);
      uVar22 = PackedFloatingMUL(uVar25,uVar26);
      uVar20 = PackedFloatingADD(uVar4,uVar20);
      uVar4 = PackedFloatingMUL(uVar26,uVar11);
      uVar26 = PackedFloatingADD(uVar22,uVar17);
      uVar17 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar20,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar21);
      uVar16 = PackedFloatingADD(uVar17,uVar26);
      uVar6 = PackedFloatingADD(uVar10,uVar4);
      *param_1 = uVar16;
      param_1[1] = uVar6;
      uVar9 = (undefined4)(param_1[2] >> 0x20);
      uVar18 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar26 = CONCAT44(uVar1,uVar1);
      uVar17 = PackedFloatingMUL(uVar29,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar20 = PackedFloatingMUL(uVar10,uVar7);
      uVar22 = PackedFloatingMUL(uVar23,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar13);
      uVar17 = PackedFloatingADD(uVar22,uVar17);
      uVar22 = PackedFloatingMUL(uVar25,uVar26);
      uVar20 = PackedFloatingADD(uVar4,uVar20);
      uVar4 = PackedFloatingMUL(uVar26,uVar11);
      uVar26 = PackedFloatingADD(uVar22,uVar17);
      uVar17 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar20,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar21);
      uVar16 = PackedFloatingADD(uVar17,uVar26);
      uVar6 = PackedFloatingADD(uVar10,uVar4);
      param_1[2] = uVar16;
      param_1[3] = uVar6;
      uVar9 = (undefined4)(param_1[4] >> 0x20);
      uVar18 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar26 = CONCAT44(uVar1,uVar1);
      uVar17 = PackedFloatingMUL(uVar29,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar20 = PackedFloatingMUL(uVar10,uVar7);
      uVar22 = PackedFloatingMUL(uVar23,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar13);
      uVar17 = PackedFloatingADD(uVar22,uVar17);
      uVar22 = PackedFloatingMUL(uVar25,uVar26);
      uVar20 = PackedFloatingADD(uVar4,uVar20);
      uVar4 = PackedFloatingMUL(uVar26,uVar11);
      uVar26 = PackedFloatingADD(uVar22,uVar17);
      uVar17 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar20,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar21);
      uVar16 = PackedFloatingADD(uVar17,uVar26);
      uVar6 = PackedFloatingADD(uVar10,uVar4);
      param_1[4] = uVar16;
      param_1[5] = uVar6;
      uVar9 = (undefined4)(param_1[6] >> 0x20);
      uVar18 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar29,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar7);
      uVar23 = PackedFloatingMUL(uVar23,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar13);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar25,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar11);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar21);
      uVar13 = PackedFloatingADD(uVar26,uVar20);
      uVar6 = PackedFloatingADD(uVar10,uVar4);
      param_1[6] = uVar13;
      param_1[7] = uVar6;
      uVar9 = (undefined4)(*param_1 >> 0x20);
      uVar18 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar31,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,0);
      uVar23 = PackedFloatingMUL(uVar19,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,0);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(0,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar15);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,uVar14);
      uVar13 = PackedFloatingADD(uVar26,uVar20);
      uVar6 = PackedFloatingADD(uVar10,uVar4);
      *param_1 = uVar13;
      param_1[1] = uVar6;
      uVar9 = (undefined4)(param_1[2] >> 0x20);
      uVar18 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar31,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,0);
      uVar23 = PackedFloatingMUL(uVar19,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,0);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(0,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar15);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,uVar14);
      uVar13 = PackedFloatingADD(uVar26,uVar20);
      uVar6 = PackedFloatingADD(uVar10,uVar4);
      param_1[2] = uVar13;
      param_1[3] = uVar6;
      uVar9 = (undefined4)(param_1[4] >> 0x20);
      uVar18 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar31,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,0);
      uVar23 = PackedFloatingMUL(uVar19,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,0);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(0,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar15);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,uVar14);
      uVar13 = PackedFloatingADD(uVar26,uVar20);
      uVar6 = PackedFloatingADD(uVar10,uVar4);
      param_1[4] = uVar13;
      param_1[5] = uVar6;
      uVar9 = (undefined4)(param_1[6] >> 0x20);
      uVar18 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar31,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,0);
      uVar23 = PackedFloatingMUL(uVar19,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,0);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(0,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar15);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,uVar14);
      uVar6 = PackedFloatingADD(uVar26,uVar20);
      uVar14 = PackedFloatingADD(uVar10,uVar4);
      param_1[6] = uVar6;
      param_1[7] = uVar14;
      uVar9 = (undefined4)(*param_1 >> 0x20);
      uVar18 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar24,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar30);
      uVar23 = PackedFloatingMUL(uVar5,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar8);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar2,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar12);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar3);
      uVar6 = PackedFloatingADD(uVar26,uVar20);
      uVar14 = PackedFloatingADD(uVar10,uVar4);
      *param_1 = uVar6;
      param_1[1] = uVar14;
      uVar9 = (undefined4)(param_1[2] >> 0x20);
      uVar18 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar24,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar30);
      uVar23 = PackedFloatingMUL(uVar5,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar8);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar2,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar12);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar3);
      uVar6 = PackedFloatingADD(uVar26,uVar20);
      uVar14 = PackedFloatingADD(uVar10,uVar4);
      param_1[2] = uVar6;
      param_1[3] = uVar14;
      uVar9 = (undefined4)(param_1[4] >> 0x20);
      uVar18 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar24,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar30);
      uVar23 = PackedFloatingMUL(uVar5,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar8);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar2,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar12);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar3);
      uVar6 = PackedFloatingADD(uVar26,uVar20);
      uVar14 = PackedFloatingADD(uVar10,uVar4);
      param_1[4] = uVar6;
      param_1[5] = uVar14;
      uVar9 = (undefined4)(param_1[6] >> 0x20);
      uVar18 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar4 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar29 = PackedFloatingMUL(uVar24,uVar4);
      uVar24 = CONCAT44(uVar9,uVar9);
      uVar4 = PackedFloatingMUL(uVar4,uVar30);
      uVar20 = PackedFloatingMUL(uVar5,uVar24);
      uVar5 = CONCAT44(uVar18,uVar18);
      uVar24 = PackedFloatingMUL(uVar24,uVar8);
      uVar29 = PackedFloatingADD(uVar20,uVar29);
      uVar20 = PackedFloatingMUL(uVar2,uVar10);
      uVar2 = PackedFloatingADD(uVar24,uVar4);
      uVar24 = PackedFloatingMUL(uVar10,uVar12);
      uVar4 = PackedFloatingADD(uVar20,uVar29);
      uVar10 = PackedFloatingMUL(0,uVar5);
      uVar24 = PackedFloatingADD(uVar2,uVar24);
      uVar5 = PackedFloatingMUL(uVar5,lVar3);
      uVar30 = PackedFloatingADD(uVar10,uVar4);
      uVar14 = PackedFloatingADD(uVar5,uVar24);
      param_1[6] = uVar30;
      param_1[7] = uVar14;
      uVar14 = PackedFloatingADD(*param_2,param_1[6]);
      uVar24 = PackedFloatingADD((ulonglong)*(uint *)(param_2 + 1),(ulonglong)(uint)param_1[7]);
      param_1[6] = uVar14;
      *(int *)(param_1 + 7) = (int)uVar24;
    }
  }
  if (param_6 != (undefined8 *)0x0) {
    uVar24 = *param_6;
    uVar5 = param_6[1];
    uVar2 = PackedFloatingADD(uVar24,uVar24);
    uVar4 = PackedFloatingADD(uVar5,uVar5);
    uVar9 = (undefined4)((ulonglong)uVar24 >> 0x20);
    uVar18 = (undefined4)((ulonglong)uVar5 >> 0x20);
    uVar29 = CONCAT44(uVar18,uVar18);
    uVar10 = PackedFloatingMUL(uVar24,uVar2);
    uVar24 = CONCAT44((int)uVar2,(int)uVar4);
    uVar20 = PackedFloatingMUL(uVar2,uVar29);
    uVar4 = PackedFloatingMUL(CONCAT44((int)uVar5,(int)uVar5),uVar24);
    uVar5 = PackedFloatingMUL(uVar24,CONCAT44(uVar9,uVar9));
    uVar24 = PackedFloatingMUL(uVar24,uVar29);
    uVar2 = CONCAT44((int)((ulonglong)uVar4 >> 0x20),(int)((ulonglong)uVar5 >> 0x20));
    uVar29 = PackedFloatingADD(CONCAT44((int)uVar4,(int)uVar4),uVar10);
    uVar4 = PackedFloatingAccumulate(uVar10,uVar10);
    uVar24 = CONCAT44((int)((ulonglong)uVar20 >> 0x20),(int)uVar24);
    uVar6 = PackedFloatingSUBR(uVar4,CONCAT44(_DAT_009fc844,DAT_009fc840));
    uVar10 = PackedFloatingSUBR(uVar29,CONCAT44(_DAT_009fc844,DAT_009fc840));
    uVar6 = uVar6 & 0xffffffff;
    uVar4 = PackedFloatingADD(uVar2,uVar24);
    uVar14 = PackedFloatingSUB(uVar2,uVar24);
    uVar30 = PackedFloatingADD(uVar5,uVar20);
    uVar5 = PackedFloatingSUB(uVar5,uVar20);
    uVar30 = uVar30 & 0xffffffff;
    uVar2 = CONCAT44((int)uVar10,(int)uVar14);
    uVar14 = uVar14 >> 0x20;
    lVar3 = (ulonglong)DAT_009fc840 << 0x20;
    uVar24 = CONCAT44((int)uVar4,(int)((ulonglong)uVar10 >> 0x20));
    uVar5 = CONCAT44((int)uVar5,(int)((ulonglong)uVar4 >> 0x20));
    if (param_5 == (undefined8 *)0x0) {
      uVar9 = (undefined4)(*param_1 >> 0x20);
      uVar18 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar24,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar14);
      uVar23 = PackedFloatingMUL(uVar2,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar30);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar5,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar6);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar3);
      uVar31 = PackedFloatingADD(uVar26,uVar20);
      uVar13 = PackedFloatingADD(uVar10,uVar4);
      *param_1 = uVar31;
      param_1[1] = uVar13;
      uVar9 = (undefined4)(param_1[2] >> 0x20);
      uVar18 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar24,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar14);
      uVar23 = PackedFloatingMUL(uVar2,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar30);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar5,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar6);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar3);
      uVar31 = PackedFloatingADD(uVar26,uVar20);
      uVar13 = PackedFloatingADD(uVar10,uVar4);
      param_1[2] = uVar31;
      param_1[3] = uVar13;
      uVar9 = (undefined4)(param_1[4] >> 0x20);
      uVar18 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar24,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar14);
      uVar23 = PackedFloatingMUL(uVar2,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar30);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar5,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar6);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar3);
      uVar31 = PackedFloatingADD(uVar26,uVar20);
      uVar13 = PackedFloatingADD(uVar10,uVar4);
      param_1[4] = uVar31;
      param_1[5] = uVar13;
      uVar9 = (undefined4)(param_1[6] >> 0x20);
      uVar18 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar4 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar29 = PackedFloatingMUL(uVar24,uVar4);
      uVar24 = CONCAT44(uVar9,uVar9);
      uVar4 = PackedFloatingMUL(uVar4,uVar14);
      uVar20 = PackedFloatingMUL(uVar2,uVar24);
      uVar2 = CONCAT44(uVar18,uVar18);
      uVar24 = PackedFloatingMUL(uVar24,uVar30);
      uVar29 = PackedFloatingADD(uVar20,uVar29);
      uVar20 = PackedFloatingMUL(uVar5,uVar10);
      uVar5 = PackedFloatingADD(uVar24,uVar4);
      uVar24 = PackedFloatingMUL(uVar10,uVar6);
      uVar4 = PackedFloatingADD(uVar20,uVar29);
      uVar10 = PackedFloatingMUL(0,uVar2);
      uVar24 = PackedFloatingADD(uVar5,uVar24);
      uVar5 = PackedFloatingMUL(uVar2,lVar3);
      uVar30 = PackedFloatingADD(uVar10,uVar4);
      uVar14 = PackedFloatingADD(uVar5,uVar24);
      param_1[6] = uVar30;
      param_1[7] = uVar14;
    }
    else {
      uVar13 = PackedFloatingSUB(param_1[6],*param_5);
      uVar4 = PackedFloatingSUB((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_5 + 1));
      param_1[6] = uVar13;
      *(int *)(param_1 + 7) = (int)uVar4;
      uVar9 = (undefined4)(*param_1 >> 0x20);
      uVar18 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar24,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar14);
      uVar23 = PackedFloatingMUL(uVar2,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar30);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar5,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar6);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar3);
      uVar31 = PackedFloatingADD(uVar26,uVar20);
      uVar13 = PackedFloatingADD(uVar10,uVar4);
      *param_1 = uVar31;
      param_1[1] = uVar13;
      uVar9 = (undefined4)(param_1[2] >> 0x20);
      uVar18 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar24,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar14);
      uVar23 = PackedFloatingMUL(uVar2,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar30);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar5,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar6);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar3);
      uVar31 = PackedFloatingADD(uVar26,uVar20);
      uVar13 = PackedFloatingADD(uVar10,uVar4);
      param_1[2] = uVar31;
      param_1[3] = uVar13;
      uVar9 = (undefined4)(param_1[4] >> 0x20);
      uVar18 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar20 = CONCAT44(uVar1,uVar1);
      uVar26 = PackedFloatingMUL(uVar24,uVar10);
      uVar4 = CONCAT44(uVar9,uVar9);
      uVar29 = PackedFloatingMUL(uVar10,uVar14);
      uVar23 = PackedFloatingMUL(uVar2,uVar4);
      uVar10 = CONCAT44(uVar18,uVar18);
      uVar4 = PackedFloatingMUL(uVar4,uVar30);
      uVar26 = PackedFloatingADD(uVar23,uVar26);
      uVar23 = PackedFloatingMUL(uVar5,uVar20);
      uVar29 = PackedFloatingADD(uVar4,uVar29);
      uVar4 = PackedFloatingMUL(uVar20,uVar6);
      uVar20 = PackedFloatingADD(uVar23,uVar26);
      uVar26 = PackedFloatingMUL(0,uVar10);
      uVar4 = PackedFloatingADD(uVar29,uVar4);
      uVar10 = PackedFloatingMUL(uVar10,lVar3);
      uVar31 = PackedFloatingADD(uVar26,uVar20);
      uVar13 = PackedFloatingADD(uVar10,uVar4);
      param_1[4] = uVar31;
      param_1[5] = uVar13;
      uVar9 = (undefined4)(param_1[6] >> 0x20);
      uVar18 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar4 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar29 = PackedFloatingMUL(uVar24,uVar4);
      uVar24 = CONCAT44(uVar9,uVar9);
      uVar4 = PackedFloatingMUL(uVar4,uVar14);
      uVar20 = PackedFloatingMUL(uVar2,uVar24);
      uVar2 = CONCAT44(uVar18,uVar18);
      uVar24 = PackedFloatingMUL(uVar24,uVar30);
      uVar29 = PackedFloatingADD(uVar20,uVar29);
      uVar20 = PackedFloatingMUL(uVar5,uVar10);
      uVar5 = PackedFloatingADD(uVar24,uVar4);
      uVar24 = PackedFloatingMUL(uVar10,uVar6);
      uVar4 = PackedFloatingADD(uVar20,uVar29);
      uVar10 = PackedFloatingMUL(0,uVar2);
      uVar24 = PackedFloatingADD(uVar5,uVar24);
      uVar5 = PackedFloatingMUL(uVar2,lVar3);
      uVar30 = PackedFloatingADD(uVar10,uVar4);
      uVar14 = PackedFloatingADD(uVar5,uVar24);
      param_1[6] = uVar30;
      param_1[7] = uVar14;
      uVar14 = PackedFloatingADD(param_1[6],*param_5);
      uVar24 = PackedFloatingADD((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_5 + 1));
      param_1[6] = uVar14;
      *(int *)(param_1 + 7) = (int)uVar24;
    }
  }
  if (param_7 != (undefined8 *)0x0) {
    uVar14 = PackedFloatingADD(param_1[6],*param_7);
    uVar24 = PackedFloatingADD((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_7 + 1));
    param_1[6] = uVar14;
    *(int *)(param_1 + 7) = (int)uVar24;
  }
  FastExitMediaState();
  return;
}


// ==== FUN_007af58a @ 0x007af58a ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007af58a(undefined8 *param_1,undefined8 param_2,undefined8 param_3)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined8 uVar5;
  ulonglong uVar6;
  undefined4 uVar9;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 uVar12;
  
  PackedFloatingMUL(DAT_009fc8d0,param_3);
  PackedFloatingMUL(DAT_009fc8d0,param_2);
  uVar2 = FUN_007b47a0();
  uVar3 = FUN_007b47a0();
  uVar4 = FUN_007b47a0();
  uVar1 = (undefined4)uVar4;
  uVar9 = (undefined4)((ulonglong)uVar4 >> 0x20);
  uVar4 = CONCAT44((int)uVar3,(int)uVar3);
  uVar12 = (undefined4)((ulonglong)uVar3 >> 0x20);
  uVar10 = CONCAT44(uVar12,uVar12);
  uVar3 = PackedFloatingMUL(CONCAT44(uVar1,uVar1) ^ DAT_009fc860,uVar10);
  uVar5 = PackedFloatingMUL(CONCAT44(uVar1,uVar1),uVar4);
  uVar7 = PackedFloatingMUL(CONCAT44(uVar9,uVar9),uVar4);
  uVar10 = PackedFloatingMUL(CONCAT44(uVar9,uVar9) ^ DAT_009fc860 >> 0x20,uVar10);
  uVar11 = CONCAT44((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
  uVar3 = PackedFloatingMUL(uVar3,uVar2);
  uVar4 = PackedFloatingMUL(uVar5,uVar11);
  uVar5 = PackedFloatingMUL(uVar7,uVar11);
  uVar7 = PackedFloatingMUL(uVar10,uVar2);
  uVar2 = PackedFloatingADD(uVar3,uVar5);
  uVar5 = PackedFloatingADD(uVar4,uVar7);
  uVar3 = PackedFloatingADD(uVar2,uVar2);
  uVar4 = PackedFloatingADD(uVar5,uVar5);
  uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
  uVar9 = (undefined4)((ulonglong)uVar5 >> 0x20);
  uVar10 = CONCAT44(uVar9,uVar9);
  uVar7 = PackedFloatingMUL(uVar2,uVar3);
  uVar2 = CONCAT44((int)uVar3,(int)uVar4);
  uVar11 = PackedFloatingMUL(uVar3,uVar10);
  uVar5 = PackedFloatingMUL(CONCAT44((int)uVar5,(int)uVar5),uVar2);
  uVar3 = PackedFloatingMUL(uVar2,CONCAT44(uVar1,uVar1));
  uVar2 = PackedFloatingMUL(uVar2,uVar10);
  uVar4 = CONCAT44((int)((ulonglong)uVar5 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
  param_1[6] = 0;
  uVar10 = PackedFloatingADD(CONCAT44((int)uVar5,(int)uVar5),uVar7);
  uVar5 = PackedFloatingAccumulate(uVar7,uVar7);
  uVar2 = CONCAT44((int)((ulonglong)uVar11 >> 0x20),(int)uVar2);
  uVar6 = PackedFloatingSUBR(uVar5,CONCAT44(_DAT_009fc844,DAT_009fc840));
  uVar7 = PackedFloatingSUBR(uVar10,CONCAT44(_DAT_009fc844,DAT_009fc840));
  uVar5 = PackedFloatingADD(uVar4,uVar2);
  param_1[5] = uVar6 & 0xffffffff;
  uVar8 = PackedFloatingSUB(uVar4,uVar2);
  uVar6 = PackedFloatingADD(uVar3,uVar11);
  uVar2 = PackedFloatingSUB(uVar3,uVar11);
  param_1[3] = uVar6 & 0xffffffff;
  uVar6 = (ulonglong)DAT_009fc840;
  param_1[1] = uVar8 >> 0x20;
  param_1[2] = CONCAT44((int)uVar7,(int)uVar8);
  *param_1 = CONCAT44((int)uVar5,(int)((ulonglong)uVar7 >> 0x20));
  param_1[4] = CONCAT44((int)uVar2,(int)((ulonglong)uVar5 >> 0x20));
  param_1[7] = uVar6 << 0x20;
  FastExitMediaState();
  return;
}


// ==== FUN_007afc63 @ 0x007afc63 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007afc63(undefined8 *param_1,undefined8 *param_2)

{
  undefined8 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  ulonglong uVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined4 uVar9;
  undefined8 local_20;
  uint local_18;
  
  local_20 = *param_2;
  local_18 = *(uint *)(param_2 + 1);
  FUN_007b1a40(&local_20,&local_20);
  uVar1 = FUN_007b47a0();
  uVar2 = PackedFloatingSUBR(uVar1,CONCAT44(_DAT_009fc844,DAT_009fc840));
  uVar9 = (undefined4)((ulonglong)uVar1 >> 0x20);
  uVar4 = (ulonglong)local_18;
  uVar5 = PackedFloatingMUL(CONCAT44(local_18,local_18),local_20);
  uVar2 = CONCAT44((int)uVar2,(int)uVar2);
  uVar3 = PackedFloatingMUL(CONCAT44(local_18,(int)((ulonglong)local_20 >> 0x20)),local_20);
  uVar1 = CONCAT44((int)uVar1,(int)uVar1);
  uVar3 = PackedFloatingMUL(uVar3,uVar2);
  uVar5 = PackedFloatingMUL(uVar5,uVar2);
  uVar6 = PackedFloatingMUL(local_20,local_20);
  uVar7 = PackedFloatingMUL(uVar4,uVar4);
  uVar6 = PackedFloatingMUL(uVar6,uVar2);
  uVar7 = PackedFloatingMUL(uVar7,uVar2);
  uVar2 = PackedFloatingADD(uVar6,uVar1);
  uVar8 = PackedFloatingADD(uVar7,uVar1);
  uVar1 = CONCAT44(uVar9,uVar9);
  uVar6 = PackedFloatingMUL(local_20,uVar1);
  uVar1 = PackedFloatingMUL(uVar4,uVar1);
  param_1[6] = 0;
  uVar7 = CONCAT44((int)uVar6,(int)uVar1);
  uVar9 = (undefined4)((ulonglong)uVar6 >> 0x20);
  uVar6 = CONCAT44(uVar9,uVar9);
  param_1[5] = uVar8 & 0xffffffff;
  uVar1 = PackedFloatingSUB(uVar3,uVar7);
  uVar8 = PackedFloatingADD(uVar3,uVar7);
  uVar4 = PackedFloatingSUB(uVar5,uVar6);
  *param_1 = CONCAT44((int)uVar8,(int)uVar2);
  param_1[1] = uVar4 & 0xffffffff;
  uVar4 = (ulonglong)_DAT_009fc844;
  uVar3 = PackedFloatingADD(CONCAT44((int)uVar5,(int)uVar5),uVar6);
  param_1[3] = uVar8 >> 0x20;
  param_1[7] = uVar4 << 0x20;
  param_1[4] = CONCAT44((int)((ulonglong)uVar1 >> 0x20),(int)((ulonglong)uVar3 >> 0x20));
  param_1[2] = CONCAT44((int)((ulonglong)uVar2 >> 0x20),(int)uVar1);
  FastExitMediaState();
  return;
}


// ==== FUN_007afd7e @ 0x007afd7e ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007afd7e(ulonglong *param_1,undefined8 *param_2,undefined8 *param_3,ulonglong *param_4,
                 undefined8 *param_5,undefined8 *param_6,undefined8 *param_7)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined8 in_MM2;
  ulonglong uVar9;
  undefined8 uVar10;
  ulonglong uVar11;
  ulonglong uVar12;
  ulonglong uVar13;
  uint uVar14;
  ulonglong in_MM3;
  undefined8 uVar15;
  undefined8 uVar16;
  ulonglong uVar17;
  ulonglong uVar18;
  ulonglong uVar19;
  undefined8 uVar20;
  ulonglong uVar21;
  undefined8 uVar22;
  ulonglong uVar23;
  ulonglong uVar24;
  longlong lVar25;
  undefined8 uVar26;
  undefined8 uVar27;
  undefined4 uVar29;
  undefined8 uVar28;
  undefined4 uVar30;
  longlong lVar31;
  ulonglong uVar32;
  
  uVar18 = DAT_009fc820;
  if (param_4 == (ulonglong *)0x0) {
    uVar18 = (ulonglong)DAT_009fc830;
    uVar32 = PackedSwapDWords(in_MM2,uVar18);
    *param_1 = uVar18;
    param_1[1] = 0;
    param_1[2] = uVar32;
    param_1[3] = 0;
    param_1[4] = 0;
    param_1[5] = uVar18;
    param_1[6] = 0;
    param_1[7] = uVar32;
  }
  else if (param_3 == (undefined8 *)0x0) {
    if (param_2 == (undefined8 *)0x0) {
      in_MM3 = *param_4;
      uVar32 = param_4[1];
      *param_1 = in_MM3 & 0xffffffff;
      param_1[1] = 0;
      param_1[2] = in_MM3 & 0xffffffff00000000;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = (ulonglong)(uint)uVar32;
      param_1[6] = 0;
      param_1[7] = uVar18;
    }
    else {
      uVar20 = CONCAT44(_DAT_009fc844,DAT_009fc840);
      uVar4 = *param_2;
      uVar18 = *param_4;
      in_MM3 = (ulonglong)(uint)param_4[1];
      uVar3 = CONCAT44(DAT_009fc840,*(undefined4 *)(param_2 + 1));
      uVar2 = PackedFloatingSUB(uVar20,uVar18);
      param_1[5] = in_MM3;
      uVar20 = PackedFloatingSUB(uVar20,in_MM3);
      param_1[1] = 0;
      param_1[3] = 0;
      param_1[4] = 0;
      uVar32 = PackedFloatingMUL(uVar2,uVar4);
      uVar13 = PackedFloatingMUL(uVar20,uVar3);
      *param_1 = uVar18 & 0xffffffff;
      param_1[2] = uVar18 & 0xffffffff00000000;
      param_1[6] = uVar32;
      param_1[7] = uVar13;
    }
  }
  else {
    uVar32 = *param_4;
    uVar19 = (ulonglong)(uint)param_4[1];
    uVar9 = uVar32 & 0xffffffff;
    uVar23 = uVar32 & 0xffffffff00000000;
    uVar4 = *param_3;
    uVar20 = param_3[1];
    uVar15 = PackedSwapDWords(uVar32,uVar4);
    uVar2 = PackedFloatingADD(uVar4,uVar4);
    uVar7 = PackedFloatingADD(uVar20,uVar20);
    uVar3 = PackedFloatingMUL(uVar2,uVar4);
    uVar10 = PackedFloatingMUL(uVar4,uVar7);
    uVar16 = PackedFloatingMUL(uVar15,uVar7);
    uVar15 = PackedFloatingMUL(uVar7,uVar20);
    uVar2 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar20 >> 0x20),
                                       (int)((ulonglong)uVar4 >> 0x20)),
                              CONCAT44((int)uVar7,(int)uVar2));
    uVar4 = PackedFloatingSUBR(uVar3,CONCAT44(_DAT_009fc844,DAT_009fc840));
    uVar17 = PackedFloatingPosNegAccumulate(uVar16,uVar16);
    uVar20 = PackedFloatingAccumulate(uVar3,uVar3);
    uVar3 = PackedFloatingPosNegAccumulate(uVar2,uVar2);
    uVar11 = PackedFloatingPosNegAccumulate(uVar10,uVar10);
    uVar4 = PackedFloatingSUB(uVar4,CONCAT44((int)uVar15,(int)uVar15));
    uVar24 = PackedSwapDWords(uVar15,uVar11);
    uVar21 = PackedFloatingSUBR(uVar20,CONCAT44(_DAT_009fc844,DAT_009fc840));
    uVar2 = CONCAT44((int)uVar17,(int)uVar24);
    uVar12 = uVar11 & 0xffffffff;
    uVar32 = uVar21 >> 0x20;
    uVar5 = (undefined4)((ulonglong)uVar4 >> 0x20);
    uVar29 = (undefined4)((ulonglong)uVar3 >> 0x20);
    uVar20 = CONCAT44(uVar29,uVar5);
    uVar13 = uVar17 >> 0x20;
    uVar6 = (undefined4)uVar4;
    uVar1 = (undefined4)uVar3;
    uVar4 = CONCAT44(uVar6,uVar1);
    uVar8 = (ulonglong)DAT_009fc840;
    lVar31 = uVar8 << 0x20;
    uVar30 = (undefined4)(uVar17 >> 0x20);
    uVar14 = (uint)(uVar21 >> 0x20);
    if (param_2 == (undefined8 *)0x0) {
      *param_1 = CONCAT44(uVar1,uVar5);
      param_1[2] = CONCAT44(uVar6,uVar29);
      param_1[5] = (ulonglong)uVar14;
      param_1[7] = uVar8 << 0x20;
      param_1[4] = CONCAT44(uVar30,(int)uVar11);
      param_1[6] = 0;
      param_1[3] = uVar17 & 0xffffffff;
      param_1[1] = uVar24 & 0xffffffff;
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar9,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,0);
      uVar27 = PackedFloatingMUL(uVar23,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(0,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar19);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,uVar18);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar17;
      param_1[1] = uVar8;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar9,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,0);
      uVar27 = PackedFloatingMUL(uVar23,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(0,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar19);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,uVar18);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar17;
      param_1[3] = uVar8;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar9,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,0);
      uVar27 = PackedFloatingMUL(uVar23,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(0,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar19);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,uVar18);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar17;
      param_1[5] = uVar8;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar9,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,0);
      uVar27 = PackedFloatingMUL(uVar23,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(0,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar19);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,uVar18);
      uVar8 = PackedFloatingADD(uVar16,uVar10);
      uVar18 = PackedFloatingADD(uVar7,uVar3);
      param_1[6] = uVar8;
      param_1[7] = uVar18;
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar20,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar12);
      uVar27 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar13);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar2,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar32);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar31);
      uVar8 = PackedFloatingADD(uVar16,uVar10);
      uVar18 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar8;
      param_1[1] = uVar18;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar20,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar12);
      uVar27 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar13);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar2,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar32);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar31);
      uVar8 = PackedFloatingADD(uVar16,uVar10);
      uVar18 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar8;
      param_1[3] = uVar18;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar20,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar12);
      uVar27 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar13);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar2,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar32);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar31);
      uVar8 = PackedFloatingADD(uVar16,uVar10);
      uVar18 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar8;
      param_1[5] = uVar18;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar3 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar15 = PackedFloatingMUL(uVar20,uVar3);
      uVar20 = CONCAT44(uVar5,uVar5);
      uVar3 = PackedFloatingMUL(uVar3,uVar12);
      uVar10 = PackedFloatingMUL(uVar4,uVar20);
      uVar4 = CONCAT44(uVar6,uVar6);
      uVar20 = PackedFloatingMUL(uVar20,uVar13);
      uVar15 = PackedFloatingADD(uVar10,uVar15);
      uVar10 = PackedFloatingMUL(uVar2,uVar7);
      uVar2 = PackedFloatingADD(uVar20,uVar3);
      uVar20 = PackedFloatingMUL(uVar7,uVar32);
      uVar3 = PackedFloatingADD(uVar10,uVar15);
      uVar7 = PackedFloatingMUL(0,uVar4);
      uVar20 = PackedFloatingADD(uVar2,uVar20);
      uVar4 = PackedFloatingMUL(uVar4,lVar31);
      uVar18 = PackedFloatingADD(uVar7,uVar3);
      in_MM3 = PackedFloatingADD(uVar4,uVar20);
      param_1[6] = uVar18;
      param_1[7] = in_MM3;
    }
    else {
      uVar15 = CONCAT44(uVar1,uVar5);
      uVar27 = CONCAT44(uVar6,uVar29);
      uVar21 = (ulonglong)uVar14;
      lVar25 = (ulonglong)DAT_009fc840 << 0x20;
      uVar28 = CONCAT44(uVar30,(int)uVar11);
      uVar17 = uVar17 & 0xffffffff;
      uVar24 = uVar24 & 0xffffffff;
      uVar3 = *param_2;
      uVar14 = *(uint *)(param_2 + 1);
      uVar8 = (ulonglong)DAT_009fc830;
      uVar11 = PackedSwapDWords(uVar24,uVar8);
      *param_1 = uVar8;
      param_1[1] = 0;
      param_1[2] = uVar11;
      param_1[3] = 0;
      param_1[4] = 0;
      param_1[5] = uVar8;
      uVar11 = PackedFloatingSUB(uVar11,(ulonglong)uVar14);
      uVar8 = PackedFloatingSUB(0,uVar3);
      param_1[7] = uVar11;
      param_1[6] = uVar8;
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar16 = CONCAT44(uVar1,uVar1);
      uVar22 = PackedFloatingMUL(uVar15,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar10 = PackedFloatingMUL(uVar7,uVar24);
      uVar26 = PackedFloatingMUL(uVar27,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar17);
      uVar22 = PackedFloatingADD(uVar26,uVar22);
      uVar26 = PackedFloatingMUL(uVar28,uVar16);
      uVar10 = PackedFloatingADD(uVar3,uVar10);
      uVar3 = PackedFloatingMUL(uVar16,uVar21);
      uVar16 = PackedFloatingADD(uVar26,uVar22);
      uVar22 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar10,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar25);
      uVar11 = PackedFloatingADD(uVar22,uVar16);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar11;
      param_1[1] = uVar8;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar16 = CONCAT44(uVar1,uVar1);
      uVar22 = PackedFloatingMUL(uVar15,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar10 = PackedFloatingMUL(uVar7,uVar24);
      uVar26 = PackedFloatingMUL(uVar27,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar17);
      uVar22 = PackedFloatingADD(uVar26,uVar22);
      uVar26 = PackedFloatingMUL(uVar28,uVar16);
      uVar10 = PackedFloatingADD(uVar3,uVar10);
      uVar3 = PackedFloatingMUL(uVar16,uVar21);
      uVar16 = PackedFloatingADD(uVar26,uVar22);
      uVar22 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar10,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar25);
      uVar11 = PackedFloatingADD(uVar22,uVar16);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar11;
      param_1[3] = uVar8;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar16 = CONCAT44(uVar1,uVar1);
      uVar22 = PackedFloatingMUL(uVar15,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar10 = PackedFloatingMUL(uVar7,uVar24);
      uVar26 = PackedFloatingMUL(uVar27,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar17);
      uVar22 = PackedFloatingADD(uVar26,uVar22);
      uVar26 = PackedFloatingMUL(uVar28,uVar16);
      uVar10 = PackedFloatingADD(uVar3,uVar10);
      uVar3 = PackedFloatingMUL(uVar16,uVar21);
      uVar16 = PackedFloatingADD(uVar26,uVar22);
      uVar22 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar10,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar25);
      uVar11 = PackedFloatingADD(uVar22,uVar16);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar11;
      param_1[5] = uVar8;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar15,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar24);
      uVar27 = PackedFloatingMUL(uVar27,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar17);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar28,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar21);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar25);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      param_1[6] = uVar17;
      param_1[7] = uVar8;
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar9,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,0);
      uVar27 = PackedFloatingMUL(uVar23,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(0,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar19);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,uVar18);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar17;
      param_1[1] = uVar8;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar9,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,0);
      uVar27 = PackedFloatingMUL(uVar23,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(0,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar19);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,uVar18);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar17;
      param_1[3] = uVar8;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar9,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,0);
      uVar27 = PackedFloatingMUL(uVar23,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(0,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar19);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,uVar18);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar17;
      param_1[5] = uVar8;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar9,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,0);
      uVar27 = PackedFloatingMUL(uVar23,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,0);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(0,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar19);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,uVar18);
      uVar8 = PackedFloatingADD(uVar16,uVar10);
      uVar18 = PackedFloatingADD(uVar7,uVar3);
      param_1[6] = uVar8;
      param_1[7] = uVar18;
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar20,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar12);
      uVar27 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar13);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar2,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar32);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar31);
      uVar8 = PackedFloatingADD(uVar16,uVar10);
      uVar18 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar8;
      param_1[1] = uVar18;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar20,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar12);
      uVar27 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar13);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar2,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar32);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar31);
      uVar8 = PackedFloatingADD(uVar16,uVar10);
      uVar18 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar8;
      param_1[3] = uVar18;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar20,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar12);
      uVar27 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar13);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar2,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar32);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar31);
      uVar8 = PackedFloatingADD(uVar16,uVar10);
      uVar18 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar8;
      param_1[5] = uVar18;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar3 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar15 = PackedFloatingMUL(uVar20,uVar3);
      uVar20 = CONCAT44(uVar5,uVar5);
      uVar3 = PackedFloatingMUL(uVar3,uVar12);
      uVar10 = PackedFloatingMUL(uVar4,uVar20);
      uVar4 = CONCAT44(uVar6,uVar6);
      uVar20 = PackedFloatingMUL(uVar20,uVar13);
      uVar15 = PackedFloatingADD(uVar10,uVar15);
      uVar10 = PackedFloatingMUL(uVar2,uVar7);
      uVar2 = PackedFloatingADD(uVar20,uVar3);
      uVar20 = PackedFloatingMUL(uVar7,uVar32);
      uVar3 = PackedFloatingADD(uVar10,uVar15);
      uVar7 = PackedFloatingMUL(0,uVar4);
      uVar20 = PackedFloatingADD(uVar2,uVar20);
      uVar4 = PackedFloatingMUL(uVar4,lVar31);
      uVar32 = PackedFloatingADD(uVar7,uVar3);
      uVar18 = PackedFloatingADD(uVar4,uVar20);
      param_1[6] = uVar32;
      param_1[7] = uVar18;
      in_MM3 = (ulonglong)(uint)param_1[7];
      uVar18 = PackedFloatingADD(*param_2,param_1[6]);
      uVar4 = PackedFloatingADD((ulonglong)*(uint *)(param_2 + 1),in_MM3);
      param_1[6] = uVar18;
      *(int *)(param_1 + 7) = (int)uVar4;
    }
  }
  if (param_6 != (undefined8 *)0x0) {
    uVar4 = *param_6;
    uVar20 = param_6[1];
    uVar15 = PackedSwapDWords(in_MM3,uVar4);
    uVar2 = PackedFloatingADD(uVar4,uVar4);
    uVar7 = PackedFloatingADD(uVar20,uVar20);
    uVar3 = PackedFloatingMUL(uVar2,uVar4);
    uVar10 = PackedFloatingMUL(uVar4,uVar7);
    uVar16 = PackedFloatingMUL(uVar15,uVar7);
    uVar15 = PackedFloatingMUL(uVar7,uVar20);
    uVar2 = PackedFloatingMUL(CONCAT44((int)((ulonglong)uVar20 >> 0x20),
                                       (int)((ulonglong)uVar4 >> 0x20)),
                              CONCAT44((int)uVar7,(int)uVar2));
    uVar4 = PackedFloatingSUBR(uVar3,CONCAT44(_DAT_009fc844,DAT_009fc840));
    uVar32 = PackedFloatingPosNegAccumulate(uVar16,uVar16);
    uVar20 = PackedFloatingAccumulate(uVar3,uVar3);
    uVar3 = PackedFloatingPosNegAccumulate(uVar2,uVar2);
    uVar13 = PackedFloatingPosNegAccumulate(uVar10,uVar10);
    uVar4 = PackedFloatingSUB(uVar4,CONCAT44((int)uVar15,(int)uVar15));
    uVar2 = PackedSwapDWords(uVar15,uVar13);
    uVar18 = PackedFloatingSUBR(uVar20,CONCAT44(_DAT_009fc844,DAT_009fc840));
    uVar2 = CONCAT44((int)uVar32,(int)uVar2);
    uVar13 = uVar13 & 0xffffffff;
    uVar18 = uVar18 >> 0x20;
    uVar20 = CONCAT44((int)((ulonglong)uVar3 >> 0x20),(int)((ulonglong)uVar4 >> 0x20));
    uVar32 = uVar32 >> 0x20;
    uVar4 = CONCAT44((int)uVar4,(int)uVar3);
    lVar31 = (ulonglong)DAT_009fc840 << 0x20;
    if (param_5 == (undefined8 *)0x0) {
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar20,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar13);
      uVar27 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar32);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar2,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar18);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar31);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar17;
      param_1[1] = uVar8;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar20,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar13);
      uVar27 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar32);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar2,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar18);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar31);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar17;
      param_1[3] = uVar8;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar20,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar13);
      uVar27 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar32);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar2,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar18);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar31);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar17;
      param_1[5] = uVar8;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar3 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar15 = PackedFloatingMUL(uVar20,uVar3);
      uVar20 = CONCAT44(uVar5,uVar5);
      uVar3 = PackedFloatingMUL(uVar3,uVar13);
      uVar10 = PackedFloatingMUL(uVar4,uVar20);
      uVar4 = CONCAT44(uVar6,uVar6);
      uVar20 = PackedFloatingMUL(uVar20,uVar32);
      uVar15 = PackedFloatingADD(uVar10,uVar15);
      uVar10 = PackedFloatingMUL(uVar2,uVar7);
      uVar2 = PackedFloatingADD(uVar20,uVar3);
      uVar20 = PackedFloatingMUL(uVar7,uVar18);
      uVar3 = PackedFloatingADD(uVar10,uVar15);
      uVar7 = PackedFloatingMUL(0,uVar4);
      uVar20 = PackedFloatingADD(uVar2,uVar20);
      uVar4 = PackedFloatingMUL(uVar4,lVar31);
      uVar32 = PackedFloatingADD(uVar7,uVar3);
      uVar18 = PackedFloatingADD(uVar4,uVar20);
      param_1[6] = uVar32;
      param_1[7] = uVar18;
    }
    else {
      uVar8 = PackedFloatingSUB(param_1[6],*param_5);
      uVar3 = PackedFloatingSUB((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_5 + 1));
      param_1[6] = uVar8;
      *(int *)(param_1 + 7) = (int)uVar3;
      uVar5 = (undefined4)(*param_1 >> 0x20);
      uVar6 = (undefined4)(param_1[1] >> 0x20);
      uVar1 = (undefined4)*param_1;
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[1];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar20,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar13);
      uVar27 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar32);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar2,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar18);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar31);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      *param_1 = uVar17;
      param_1[1] = uVar8;
      uVar5 = (undefined4)(param_1[2] >> 0x20);
      uVar6 = (undefined4)(param_1[3] >> 0x20);
      uVar1 = (undefined4)param_1[2];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[3];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar20,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar13);
      uVar27 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar32);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar2,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar18);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar31);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      param_1[2] = uVar17;
      param_1[3] = uVar8;
      uVar5 = (undefined4)(param_1[4] >> 0x20);
      uVar6 = (undefined4)(param_1[5] >> 0x20);
      uVar1 = (undefined4)param_1[4];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[5];
      uVar10 = CONCAT44(uVar1,uVar1);
      uVar16 = PackedFloatingMUL(uVar20,uVar7);
      uVar3 = CONCAT44(uVar5,uVar5);
      uVar15 = PackedFloatingMUL(uVar7,uVar13);
      uVar27 = PackedFloatingMUL(uVar4,uVar3);
      uVar7 = CONCAT44(uVar6,uVar6);
      uVar3 = PackedFloatingMUL(uVar3,uVar32);
      uVar16 = PackedFloatingADD(uVar27,uVar16);
      uVar27 = PackedFloatingMUL(uVar2,uVar10);
      uVar15 = PackedFloatingADD(uVar3,uVar15);
      uVar3 = PackedFloatingMUL(uVar10,uVar18);
      uVar10 = PackedFloatingADD(uVar27,uVar16);
      uVar16 = PackedFloatingMUL(0,uVar7);
      uVar3 = PackedFloatingADD(uVar15,uVar3);
      uVar7 = PackedFloatingMUL(uVar7,lVar31);
      uVar17 = PackedFloatingADD(uVar16,uVar10);
      uVar8 = PackedFloatingADD(uVar7,uVar3);
      param_1[4] = uVar17;
      param_1[5] = uVar8;
      uVar5 = (undefined4)(param_1[6] >> 0x20);
      uVar6 = (undefined4)(param_1[7] >> 0x20);
      uVar1 = (undefined4)param_1[6];
      uVar3 = CONCAT44(uVar1,uVar1);
      uVar1 = (undefined4)param_1[7];
      uVar7 = CONCAT44(uVar1,uVar1);
      uVar15 = PackedFloatingMUL(uVar20,uVar3);
      uVar20 = CONCAT44(uVar5,uVar5);
      uVar3 = PackedFloatingMUL(uVar3,uVar13);
      uVar10 = PackedFloatingMUL(uVar4,uVar20);
      uVar4 = CONCAT44(uVar6,uVar6);
      uVar20 = PackedFloatingMUL(uVar20,uVar32);
      uVar15 = PackedFloatingADD(uVar10,uVar15);
      uVar10 = PackedFloatingMUL(uVar2,uVar7);
      uVar2 = PackedFloatingADD(uVar20,uVar3);
      uVar20 = PackedFloatingMUL(uVar7,uVar18);
      uVar3 = PackedFloatingADD(uVar10,uVar15);
      uVar7 = PackedFloatingMUL(0,uVar4);
      uVar20 = PackedFloatingADD(uVar2,uVar20);
      uVar4 = PackedFloatingMUL(uVar4,lVar31);
      uVar32 = PackedFloatingADD(uVar7,uVar3);
      uVar18 = PackedFloatingADD(uVar4,uVar20);
      param_1[6] = uVar32;
      param_1[7] = uVar18;
      uVar18 = PackedFloatingADD(param_1[6],*param_5);
      uVar4 = PackedFloatingADD((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_5 + 1));
      param_1[6] = uVar18;
      *(int *)(param_1 + 7) = (int)uVar4;
    }
  }
  if (param_7 != (undefined8 *)0x0) {
    uVar18 = PackedFloatingADD(param_1[6],*param_7);
    uVar4 = PackedFloatingADD((ulonglong)(uint)param_1[7],(ulonglong)*(uint *)(param_7 + 1));
    param_1[6] = uVar18;
    *(int *)(param_1 + 7) = (int)uVar4;
  }
  FastExitMediaState();
  return;
}


