// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x5b0000-0x5bffff

// ==== FUN_005b0200 @ 0x005b0200 ====

void FUN_005b0200(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xc);
  uVar2 = *(undefined4 *)(in_ECX + 0x70);
  uVar3 = *(undefined4 *)(in_ECX + 0x74);
  *param_1 = *(undefined4 *)(in_ECX + 0x6c);
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  return;
}


// ==== FUN_005b0240 @ 0x005b0240 ====

void FUN_005b0240(void)

{
  int in_ECX;
  
  if (*(undefined4 **)(in_ECX + 0x128) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x128))(1);
  }
  *(undefined4 *)(in_ECX + 0x128) = 0;
  *(undefined1 *)(in_ECX + 0x7d) = 0;
  return;
}


// ==== FUN_005b0270 @ 0x005b0270 ====

void FUN_005b0270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1c64;
  if ((undefined4 *)in_ECX[0x4a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x4a])(1);
  }
  in_ECX[0x4a] = 0;
  *(undefined1 *)((int)in_ECX + 0x7d) = 0;
  if (in_ECX[0x7a] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x7a]);
    in_ECX[0x7a] = 0;
  }
  if (in_ECX[0x7b] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x7b]);
    in_ECX[0x7b] = 0;
  }
  if ((void *)in_ECX[0x6c] == (void *)0x0) {
    in_ECX[0x6c] = 0;
    in_ECX[0x6d] = 0;
    in_ECX[0x6e] = 0;
    FUN_005caa70();
    *in_ECX = &PTR_FUN_009c1afc;
    return;
  }
  _free((void *)in_ECX[0x6c]);
  return;
}


// ==== FUN_005b0310 @ 0x005b0310 ====

void FUN_005b0310(int param_1)

{
  char cVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 auStack_74 [4];
  undefined1 auStack_70 [4];
  undefined1 local_6c;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 auStack_54 [4];
  undefined1 local_50;
  undefined4 local_40;
  undefined4 local_3c;
  undefined1 local_34;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 uStack_18;
  int local_8;
  undefined4 local_4;
  
  *(undefined1 *)(in_ECX + 0x7d) = 1;
  if (*(undefined4 **)(in_ECX + 0x128) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)(in_ECX + 0x128))(1);
  }
  local_58 = 0xf;
  local_3c = 0xf;
  local_20 = 0xf;
  local_4 = 0xf;
  *(undefined4 *)(in_ECX + 0x128) = 0;
  local_5c = 0;
  local_6c = 0;
  local_40 = 0;
  local_50 = 0;
  local_24 = 0;
  local_34 = 0;
  local_8 = 0;
  uStack_18 = 0;
  auStack_74[0] = *(undefined1 *)(*(int *)(param_1 + 0x1c) + 0x5c);
  FUN_00401660(*(int *)(param_1 + 0x1c) + 0x24,0,0xffffffff);
  FUN_00401660(*(int *)(param_1 + 0x20) + 0x24,0,0xffffffff);
  FUN_00401660(*(int *)(param_1 + 0x1c) + 0x40,0,0xffffffff);
  FUN_00401660(*(int *)(param_1 + 0x1c) + 8,0,0xffffffff);
  if (local_8 != 0) {
    *(undefined1 *)(in_ECX + 0x7e) = 1;
  }
  pvVar2 = operator_new(0x98);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005cad30();
  }
  *(undefined4 *)(in_ECX + 0x128) = uVar3;
  cVar1 = FUN_005cad90(auStack_74);
  if (cVar1 == '\0') {
    if (*(undefined4 **)(in_ECX + 0x128) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(in_ECX + 0x128))(1);
    }
    *(undefined4 *)(in_ECX + 0x128) = 0;
  }
  *(undefined1 *)(in_ECX + 0x7f) = 0;
  uVar3 = FUN_005b1c00(auStack_70);
  *(undefined4 *)(in_ECX + 0x1e8) = uVar3;
  uVar3 = FUN_005aa220(auStack_54);
  *(undefined4 *)(in_ECX + 0x1ec) = uVar3;
  FUN_005b1b00();
  return;
}


// ==== FUN_005b0450 @ 0x005b0450 ====

void FUN_005b0450(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  int extraout_ECX;
  
  *(undefined1 *)(in_ECX + 0x7d) = 0;
  FUN_005afd60(param_1);
  *(undefined4 *)(extraout_ECX + 4) = param_2;
  FUN_005b0310(param_1);
  return;
}


// ==== FUN_005b0470 @ 0x005b0470 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b0470(uint param_1)

{
  undefined4 uVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int in_ECX;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float *pfVar10;
  float10 fVar11;
  float fVar12;
  float local_e4;
  float local_e0;
  float local_dc;
  int local_d8;
  float local_d4;
  float local_d0 [4];
  undefined4 local_c0 [12];
  undefined1 auStack_90 [16];
  undefined4 local_80 [12];
  float afStack_50 [4];
  undefined4 auStack_40 [16];
  
  if (*(char *)(in_ECX + 0x7d) == '\0') {
    return;
  }
  if (param_1 < *(uint *)(in_ECX + 0x8c)) {
    *(uint *)(in_ECX + 0x8c) = *(uint *)(in_ECX + 0x8c) - param_1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x8c) = 0;
  }
  iVar7 = *(int *)(in_ECX + 0x8c);
  iVar3 = *(int *)(in_ECX + 0x88);
  fVar12 = (float)iVar7;
  if (iVar7 < 0) {
    fVar12 = fVar12 + _DAT_0099d104;
  }
  fVar2 = (float)iVar3;
  if (iVar3 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  fVar12 = DAT_0099d080 - fVar12 / fVar2;
  if (DAT_0099d080 <= fVar12) {
    fVar12 = DAT_0099d080;
  }
  else {
    if (fVar12 < 0.0) {
      fVar12 = 0.0;
    }
  }
  iVar3 = iVar3 - iVar7;
  iVar7 = (int)(fVar12 * DAT_009bf5a0);
  local_e4 = DAT_0099d080;
  local_e0 = DAT_0099d080;
  local_dc = DAT_0099d080;
  local_d8 = iVar3;
  local_d4 = DAT_0099d080;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x58) != 0) {
    fVar11 = (float10)FUN_005aa2a0(iVar7,iVar3);
    local_d4 = (float)fVar11;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0x90) != 0) {
    pfVar4 = (float *)FUN_005aa3a0(local_d0,iVar7,iVar3);
    local_e4 = *pfVar4;
    local_e0 = pfVar4[1];
    local_dc = pfVar4[2];
  }
  local_d0[0] = local_e4;
  local_d0[1] = local_e0;
  local_d0[2] = local_dc;
  local_d0[3] = local_d4;
  uVar5 = FUN_0040ead0(local_d0);
  *(undefined4 *)(in_ECX + 0x94) = uVar5;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x40) != 0) {
    fVar11 = (float10)FUN_005aa2a0(iVar7,iVar3);
    *(float *)(in_ECX + 0x9c) = (float)(fVar11 * (float10)_DAT_00af4f90);
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0x70) != 0) {
    puVar6 = (undefined4 *)FUN_005aa3a0(local_d0,iVar7,iVar3);
    *(undefined4 *)(in_ECX + 0xb8) = *puVar6;
    *(undefined4 *)(in_ECX + 0xbc) = puVar6[1];
    *(undefined4 *)(in_ECX + 0xc0) = puVar6[2];
    thunk_FUN_0079f761(local_80,*(undefined4 *)(in_ECX + 0xb8),*(undefined4 *)(in_ECX + 0xbc),
                       *(undefined4 *)(in_ECX + 0xc0));
    puVar6 = local_80;
    puVar8 = (undefined4 *)(in_ECX + 0x16c);
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    iVar3 = local_d8;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0xb0) != 0) {
    puVar6 = (undefined4 *)FUN_005aa3a0(local_d0,iVar7,iVar3);
    *(undefined4 *)(in_ECX + 0x60) = *puVar6;
    *(undefined4 *)(in_ECX + 100) = puVar6[1];
    *(undefined4 *)(in_ECX + 0x68) = puVar6[2];
  }
  if (*(char *)(in_ECX + 0x1d4) == '\0') {
    iVar7 = *(int *)(in_ECX + 4);
    local_e4 = *(float *)(iVar7 + 0xbc);
    local_e0 = *(float *)(iVar7 + 0xc0);
    local_dc = *(float *)(iVar7 + 0xc4);
    if (((local_e4 == 0.0) && (local_e0 == 0.0)) && (local_dc == 0.0)) {
      puVar6 = (undefined4 *)(in_ECX + 300);
    }
    else {
      FUN_0040d620(local_d0,&local_e4);
      thunk_FUN_0079fb96(local_80,local_d0);
      puVar6 = auStack_40;
      puVar8 = local_80;
      puVar9 = auStack_40;
      for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar9 = *puVar8;
        puVar8 = puVar8 + 1;
        puVar9 = puVar9 + 1;
      }
    }
    thunk_FUN_0079ee7b(local_c0,(undefined4 *)(in_ECX + 0x16c),puVar6);
    puVar6 = local_c0;
    puVar8 = (undefined4 *)(in_ECX + 0x16c);
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
  }
  if (*(char *)(*(int *)(in_ECX + 8) + 0x30) != '\0') {
    local_e4 = *(float *)(in_ECX + 0x6c) - *(float *)(in_ECX + 0x1bc);
    local_e0 = *(float *)(in_ECX + 0x70) - *(float *)(in_ECX + 0x1c0);
    local_dc = *(float *)(in_ECX + 0x74) - *(float *)(in_ECX + 0x1c4);
    if (DAT_0099d0ec < SQRT(local_e4 * local_e4 + local_e0 * local_e0 + local_dc * local_dc)) {
      thunk_FUN_0079e1ba(in_ECX + 0x1c8,&local_e4);
      FUN_0040d620(&local_d8,in_ECX + 0x1c8);
      thunk_FUN_0079fb96(local_d0 + 2,&local_d8);
      pfVar4 = local_d0;
      pfVar10 = afStack_50;
      for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *pfVar10 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar10 = pfVar10 + 1;
      }
      thunk_FUN_0079ee7b(auStack_90,(undefined4 *)(in_ECX + 0x16c),afStack_50);
      uVar5 = *(undefined4 *)(in_ECX + 0x70);
      uVar1 = *(undefined4 *)(in_ECX + 0x74);
      puVar6 = local_80;
      puVar8 = (undefined4 *)(in_ECX + 0x16c);
      for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      *(undefined4 *)(in_ECX + 0x1bc) = *(undefined4 *)(in_ECX + 0x6c);
      *(undefined4 *)(in_ECX + 0x1c0) = uVar5;
      *(undefined4 *)(in_ECX + 0x1c4) = uVar1;
    }
  }
  fVar12 = (float)(int)param_1;
  if ((int)param_1 < 0) {
    fVar12 = fVar12 + _DAT_0099d104;
  }
  if (**(int **)(in_ECX + 0xd0) == 0) {
    fVar2 = (float)*(int *)(in_ECX + 0x90);
    if (*(int *)(in_ECX + 0x90) < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar12 = (fVar12 * DAT_0099d0ec) / (fVar2 * DAT_0099d0ec) + *(float *)(in_ECX + 0x80);
    *(float *)(in_ECX + 0x80) = fVar12;
    if (fVar12 <= DAT_0099d080) goto LAB_005b08d6;
    fVar12 = 0.0;
  }
  else {
    fVar2 = (float)*(int *)(in_ECX + 0x88);
    if (*(int *)(in_ECX + 0x88) < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar12 = (fVar12 * DAT_0099d0ec) / (fVar2 * DAT_0099d0ec) + *(float *)(in_ECX + 0x80);
    *(float *)(in_ECX + 0x80) = fVar12;
    if (fVar12 <= DAT_0099d080) goto LAB_005b08d6;
    fVar12 = DAT_0099d080;
  }
  *(float *)(in_ECX + 0x80) = fVar12;
LAB_005b08d6:
  if (*(int *)(in_ECX + 0x128) != 0) {
    FUN_005cac00(*(undefined4 *)(in_ECX + 0x94),*(undefined4 *)(in_ECX + 0xb8));
    FUN_005cac80(*(undefined4 *)(in_ECX + 0x80));
  }
  return;
}


// ==== FUN_005b0910 @ 0x005b0910 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_005b0910(int *param_1,char param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  int in_ECX;
  int iVar9;
  int *piVar10;
  int iVar11;
  int *local_38;
  float fStack_34;
  int local_10;
  int iStack_c;
  int iStack_8;
  float fStack_4;
  
  local_38 = *(int **)(in_ECX + 0xdc);
  if (*local_38 != 0) {
    local_38 = (int *)0x0;
    if ((*(int *)(in_ECX + 0x1b0) != 0) &&
       (iVar9 = *(int *)(in_ECX + 0x1b4) - *(int *)(in_ECX + 0x1b0),
       local_38 = (int *)(iVar9 * 0x2aaaaaab), iVar9 / 0x60 != 0)) {
      if (*(int *)(in_ECX + 0x1b0) == 0) {
        piVar10 = (int *)0x0;
      }
      else {
        piVar10 = (int *)((*(int *)(in_ECX + 0x1b4) - *(int *)(in_ECX + 0x1b0)) / 0x60);
      }
      local_38 = (int *)FUN_0040ec60(&local_10,*(undefined4 *)(in_ECX + 0x94));
      iVar9 = *local_38;
      iVar2 = local_38[1];
      iVar3 = local_38[2];
      if (0 < (int)piVar10) {
        iVar11 = (int)piVar10 * 0x60;
        local_38 = piVar10;
        do {
          iVar11 = iVar11 + -0x60;
          iVar4 = *(int *)(in_ECX + 0x1b0);
          if ((iVar4 == 0) ||
             ((uint)((*(int *)(in_ECX + 0x1b4) - iVar4) / 0x60) <= (int)local_38 - 1U)) {
                    /* WARNING: Subroutine does not return */
            FUN_0085b340();
          }
          puVar7 = (undefined4 *)(**(code **)(*param_1 + 0x70))();
          puVar1 = (undefined4 *)(iVar4 + 0x50 + iVar11);
          *puVar7 = *puVar1;
          puVar7[1] = puVar1[1];
          puVar7[2] = puVar1[2];
          puVar7[3] = 0;
          puVar7[4] = 0;
          fStack_34 = DAT_0099d080;
          puVar7[5] = 0;
          puVar7[6] = fStack_34;
          puVar7[7] = *(undefined4 *)(in_ECX + 0x98);
          *(undefined1 *)(puVar7 + 8) = 0;
          *(undefined1 *)((int)puVar7 + 0x26) = 0;
          *(undefined1 *)((int)puVar7 + 0x21) = 0xc;
          *(undefined1 *)((int)puVar7 + 0x23) = 0;
          fVar5 = (float)*(int *)(iVar4 + 4 + iVar11);
          if (*(int *)(iVar4 + 4 + iVar11) < 0) {
            fVar5 = fVar5 + _DAT_0099d104;
          }
          fVar6 = (float)*(int *)(iVar4 + iVar11);
          if (*(int *)(iVar4 + iVar11) < 0) {
            fVar6 = fVar6 + _DAT_0099d104;
          }
          fStack_4 = (fVar5 / fVar6) * *(float *)(iVar4 + 8 + iVar11);
          if (*(char *)(*(int *)(in_ECX + 0xdc) + 0x10) != '\0') {
            fStack_34 = fVar5 / fVar6;
          }
          local_10 = iVar9;
          iStack_c = iVar2;
          iStack_8 = iVar3;
          uVar8 = FUN_0040ead0(&local_10);
          FUN_005cac00(uVar8,fStack_34);
          FUN_005cafa0(iVar4 + 0x10 + iVar11,param_1,puVar7,*(undefined4 *)(iVar4 + 0x5c + iVar11));
          if (param_2 == '\0') {
            (**(code **)(*param_1 + 0x98))(puVar7);
          }
          else {
            (**(code **)(*param_1 + 0x11c))();
          }
          local_38 = (int *)((int)local_38 + -1);
        } while (0 < (int)local_38);
      }
    }
  }
  return local_38;
}


// ==== FUN_005b0b90 @ 0x005b0b90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b0b90(int param_1,float param_2,int param_3)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *in_ECX;
  int iVar4;
  int iVar5;
  float10 fVar6;
  
  in_ECX[0x20] = 0;
  in_ECX[2] = param_1;
  in_ECX[0x15] = *(int *)(param_1 + 8);
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  in_ECX[0x18] = *(int *)(param_1 + 0x18);
  in_ECX[0x19] = *(int *)(param_1 + 0x1c);
  in_ECX[0x1a] = *(int *)(param_1 + 0x20);
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  *(undefined1 *)(in_ECX + 0x75) = *(undefined1 *)(param_1 + 0x31);
  fVar1 = (float)*(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[0x16] = (int)ROUND(fVar1 * param_2);
  fVar1 = (float)*(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x10) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[0x38] = (int)ROUND(fVar1 * param_2);
  if (*(char *)(param_1 + 0x32) != '\0') {
    fVar1 = (float)in_ECX[0x16];
    if (in_ECX[0x16] < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar6 = (float10)FUN_0040d0a0(0,fVar1 * DAT_0099d0ec);
    in_ECX[0x16] = (int)ROUND(fVar6 * (float10)DAT_009b012c);
  }
  iVar5 = in_ECX[2];
  in_ECX[0x39] = (int)ROUND(param_2 * DAT_009b012c);
  iVar3 = FUN_00802534();
  iVar4 = param_3 - in_ECX[0x16];
  in_ECX[0x22] = iVar3;
  if (iVar4 < 1) {
    in_ECX[0x23] = iVar3;
  }
  else if (iVar4 < iVar3) {
    in_ECX[0x23] = iVar3 - iVar4;
  }
  else {
    in_ECX[0x23] = 0;
  }
  in_ECX[0x17] = param_3;
  in_ECX[0x6f] = in_ECX[0x1b];
  in_ECX[0x70] = in_ECX[0x1c];
  in_ECX[0x71] = in_ECX[0x1d];
  iVar5 = *(int *)(iVar5 + 0x34);
  if (((in_ECX[0x36] != iVar5) && (in_ECX[0x36] = iVar5, *(int *)(iVar5 + 0x18) != 0)) &&
     (*(int *)(iVar5 + 0x34) != 0)) {
    FUN_005ca850(iVar5 + 4);
    FUN_005caad0();
    FUN_005cab40(in_ECX[0x36] + 0x20);
  }
  iVar5 = *(int *)(in_ECX[2] + 0x14);
  if (iVar5 == 0) {
    in_ECX[0x22] = in_ECX[0x24];
    in_ECX[0x23] = in_ECX[0x24];
  }
  else {
    fVar1 = (float)in_ECX[0x23];
    if (in_ECX[0x23] < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar2 = (float)iVar5;
    if (iVar5 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    in_ECX[0x24] = (int)ROUND(fVar1 / fVar2);
  }
  iVar3 = in_ECX[0x6d];
  for (iVar5 = in_ECX[0x6c]; iVar5 != iVar3; iVar5 = iVar5 + 0x60) {
    (**(code **)(*DAT_00b5aff4 + 8))(*(undefined4 *)(iVar5 + 0x5c));
  }
  if ((void *)in_ECX[0x6c] == (void *)0x0) {
    in_ECX[0x6c] = 0;
    in_ECX[0x6d] = 0;
    in_ECX[0x6e] = 0;
    (**(code **)(*in_ECX + 0x44))();
    FUN_005b0470(0);
    return;
  }
  _free((void *)in_ECX[0x6c]);
  return;
}


// ==== FUN_005b0e80 @ 0x005b0e80 ====

void FUN_005b0e80(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1c64;
  *(undefined1 *)((int)in_ECX + 0x7d) = 0;
  *(undefined1 *)((int)in_ECX + 0x7e) = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x35] = 0;
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  FUN_005caa30();
  uVar1 = DAT_0099d080;
  in_ECX[0x4a] = 0;
  in_ECX[0x6c] = 0;
  in_ECX[0x6d] = 0;
  in_ECX[0x6e] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x17] = 0;
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  *(undefined1 *)(in_ECX + 0x1f) = 1;
  in_ECX[0x59] = 0;
  in_ECX[0x58] = 0;
  in_ECX[0x57] = 0;
  in_ECX[0x56] = 0;
  in_ECX[0x54] = 0;
  in_ECX[0x53] = 0;
  in_ECX[0x52] = 0;
  in_ECX[0x51] = 0;
  in_ECX[0x4f] = 0;
  in_ECX[0x4e] = 0;
  in_ECX[0x4d] = 0;
  in_ECX[0x4c] = 0;
  in_ECX[0x5a] = uVar1;
  in_ECX[0x55] = uVar1;
  in_ECX[0x50] = uVar1;
  in_ECX[0x4b] = uVar1;
  in_ECX[0x69] = 0;
  in_ECX[0x68] = 0;
  in_ECX[0x67] = 0;
  in_ECX[0x66] = 0;
  in_ECX[100] = 0;
  in_ECX[99] = 0;
  in_ECX[0x62] = 0;
  in_ECX[0x61] = 0;
  in_ECX[0x5f] = 0;
  in_ECX[0x5e] = 0;
  in_ECX[0x5d] = 0;
  in_ECX[0x5c] = 0;
  in_ECX[0x6a] = uVar1;
  in_ECX[0x65] = uVar1;
  in_ECX[0x60] = uVar1;
  in_ECX[0x5b] = uVar1;
  in_ECX[0x77] = 0;
  in_ECX[0x78] = 0;
  in_ECX[0x7a] = 0;
  in_ECX[0x7b] = 0;
  in_ECX[0x76] = 0;
  in_ECX[0x79] = 0;
  return;
}


// ==== FUN_005b1050 @ 0x005b1050 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_005b1050(int *param_1,char param_2)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *piVar6;
  int in_ECX;
  int iVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  float fVar11;
  float local_12c;
  float local_128;
  float local_124;
  int iStack_11c;
  float fStack_108;
  float fStack_104;
  undefined4 auStack_100 [16];
  undefined4 auStack_c0 [16];
  undefined4 auStack_80 [16];
  undefined4 auStack_40 [16];
  
  piVar6 = *(int **)(in_ECX + 0xdc);
  if (*piVar6 != 0) {
    piVar6 = (int *)0x0;
    if ((*(int *)(in_ECX + 0x1b0) != 0) &&
       (iVar7 = *(int *)(in_ECX + 0x1b4) - *(int *)(in_ECX + 0x1b0),
       piVar6 = (int *)(iVar7 * 0x2aaaaaab), iVar7 / 0x60 != 0)) {
      if (*(int *)(in_ECX + 0x1b0) == 0) {
        iStack_11c = 0;
      }
      else {
        iStack_11c = (*(int *)(in_ECX + 0x1b4) - *(int *)(in_ECX + 0x1b0)) / 0x60;
      }
      local_12c = *(float *)(in_ECX + 0x6c);
      local_128 = *(float *)(in_ECX + 0x70);
      local_124 = *(float *)(in_ECX + 0x74);
      piVar6 = (int *)(**(code **)(*param_1 + 0xe8))();
      *(undefined1 *)(piVar6 + 2) = *(undefined1 *)(*(int *)(in_ECX + 0xd0) + 0x5c);
      piVar6[4] = *(int *)(in_ECX + 0x98);
      *piVar6 = *(int *)(in_ECX + 0x1e8);
      piVar6[1] = *(int *)(in_ECX + 0x1ec);
      piVar6[3] = *(int *)(in_ECX + 0x94);
      if (0 < iStack_11c) {
        iVar7 = iStack_11c * 0x60;
        do {
          iVar7 = iVar7 + -0x60;
          iVar2 = *(int *)(in_ECX + 0x1b0);
          if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0x1b4) - iVar2) / 0x60) <= iStack_11c - 1U)
             ) {
                    /* WARNING: Subroutine does not return */
            FUN_0085b340();
          }
          fVar11 = *(float *)(*(int *)(in_ECX + 0xdc) + 8);
          if ((DAT_0099cdc8 < fVar11) &&
             (fVar3 = *(float *)(iVar2 + 0x50 + iVar7) - local_12c,
             fVar5 = *(float *)(iVar2 + 0x54 + iVar7) - local_128,
             fVar4 = *(float *)(iVar2 + 0x58 + iVar7) - local_124,
             fVar3 = SQRT(fVar3 * fVar3 + fVar5 * fVar5 + fVar4 * fVar4),
             *(float *)(*(int *)(in_ECX + 0xdc) + 8) < fVar3)) {
            fVar11 = fVar11 / fVar3;
            *(float *)(iVar2 + 0x50 + iVar7) =
                 (*(float *)(iVar2 + 0x50 + iVar7) - local_12c) * fVar11 + local_12c;
            *(float *)(iVar2 + 0x54 + iVar7) =
                 (*(float *)(iVar2 + 0x54 + iVar7) - local_128) * fVar11 + local_128;
            *(float *)(iVar2 + 0x58 + iVar7) =
                 (*(float *)(iVar2 + 0x58 + iVar7) - local_124) * fVar11 + local_124;
          }
          pfVar1 = (float *)(iVar2 + 0x50 + iVar7);
          local_12c = *pfVar1;
          local_128 = pfVar1[1];
          local_124 = pfVar1[2];
          thunk_FUN_0079f7f5(auStack_40,*pfVar1,pfVar1[1],pfVar1[2]);
          puVar9 = auStack_40;
          puVar10 = auStack_c0;
          for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          thunk_FUN_0079ee7b(auStack_80,iVar2 + 0x10 + iVar7,auStack_c0);
          fVar11 = (float)*(int *)(iVar2 + 4 + iVar7);
          puVar9 = auStack_80;
          puVar10 = auStack_100;
          for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          if (*(int *)(iVar2 + 4 + iVar7) < 0) {
            fVar11 = fVar11 + _DAT_0099d104;
          }
          fVar3 = (float)*(int *)(iVar2 + iVar7);
          if (*(int *)(iVar2 + iVar7) < 0) {
            fVar3 = fVar3 + _DAT_0099d104;
          }
          fStack_104 = (fVar11 / fVar3) * *(float *)(iVar2 + 8 + iVar7);
          fStack_108 = fVar11 / fVar3;
          if (*(char *)(*(int *)(in_ECX + 0xdc) + 0x10) == '\0') {
            fStack_108 = DAT_0099d080;
          }
          FUN_005b22f0(&fStack_108);
          iStack_11c = iStack_11c + -1;
        } while (0 < iStack_11c);
      }
      if (param_2 == '\0') {
        piVar6 = (int *)(**(code **)(*param_1 + 0x7c))(piVar6);
      }
    }
  }
  return piVar6;
}


// ==== FUN_005b1370 @ 0x005b1370 ====

void FUN_005b1370(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  undefined4 *puVar7;
  uint *puVar8;
  undefined4 *puVar9;
  uint *puVar10;
  undefined1 local_140 [2];
  undefined1 auStack_13e [10];
  undefined1 auStack_134 [4];
  undefined1 local_130 [4];
  float fStack_12c;
  uint auStack_124 [19];
  undefined4 uStack_d8;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8 [2];
  undefined1 local_c0 [44];
  uint auStack_94 [3];
  undefined1 auStack_88 [64];
  undefined4 auStack_48 [18];
  
  uVar4 = 0;
  if (*(int *)(in_ECX + 0x1b0) != 0) {
    uVar4 = (*(int *)(in_ECX + 0x1b4) - *(int *)(in_ECX + 0x1b0)) / 0x60;
  }
  puVar8 = *(uint **)(in_ECX + 0xdc);
  if (((uVar4 < *puVar8) &&
      (*(int *)(in_ECX + 0x1d8) = *(int *)(in_ECX + 0x1d8) + param_1,
      puVar8[1] <= *(uint *)(in_ECX + 0x1d8))) &&
     (((float)puVar8[2] <= DAT_0099cdc8 ||
      (fVar1 = *(float *)(in_ECX + 0x6c) - *(float *)(in_ECX + 0x1dc),
      fVar2 = *(float *)(in_ECX + 0x70) - *(float *)(in_ECX + 0x1e0),
      fVar3 = *(float *)(in_ECX + 0x74) - *(float *)(in_ECX + 0x1e4),
      (float)puVar8[2] <= SQRT(fVar2 * fVar2 + fVar1 * fVar1 + fVar3 * fVar3))))) {
    auStack_124[1] = puVar8[3];
    local_c8[1] = 0;
    auStack_124[2] = auStack_124[1];
    uVar5 = FUN_0040d600(local_130,*(undefined4 *)(in_ECX + 0x9c));
    FUN_0040d690(local_140,uVar5);
    local_d0 = *(undefined4 *)(in_ECX + 0x6c);
    local_cc = *(undefined4 *)(in_ECX + 0x70);
    local_c8[0] = *(undefined4 *)(in_ECX + 0x74);
    thunk_FUN_0079fb96(local_c0,local_140);
    puVar7 = local_c8;
    puVar9 = auStack_48;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    thunk_FUN_0079ee7b(auStack_88,in_ECX + 0x16c,auStack_48);
    puVar8 = auStack_94;
    puVar10 = auStack_124;
    for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar10 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar10 = puVar10 + 1;
    }
    iVar6 = FUN_0040ec60(local_140 + -4,*(undefined4 *)(in_ECX + 0x94));
    fStack_12c = DAT_009c1cac;
    if (*(float *)(iVar6 + 0xc) <= DAT_009c1cac) {
      fStack_12c = *(float *)(iVar6 + 0xc);
    }
    if (*(char *)(in_ECX + 0x7e) != '\0') {
      uStack_d8 = (**(code **)(**(int **)(*(int *)(in_ECX + 0x128) + 0x94) + 0x18))();
    }
    FUN_005b2380(auStack_134);
    *(undefined4 *)(in_ECX + 0x1d8) = 0;
    *(undefined4 *)(in_ECX + 0x1dc) = *(undefined4 *)(in_ECX + 0x6c);
    *(undefined4 *)(in_ECX + 0x1e0) = *(undefined4 *)(in_ECX + 0x70);
    *(undefined4 *)(in_ECX + 0x1e4) = *(undefined4 *)(in_ECX + 0x74);
  }
  return;
}


// ==== FUN_005b1560 @ 0x005b1560 ====

void FUN_005b1560(int *param_1,undefined4 param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 auStack_18 [8];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if ((((*(uint *)(in_ECX + 0x58) <= *(uint *)(in_ECX + 0x5c)) && (*(char *)(in_ECX + 0x7d) != '\0')
       ) && (*(int *)(in_ECX + 0x128) != 0)) && (cVar1 = FUN_005afe60(), cVar1 != '\0')) {
    puVar2 = (undefined4 *)(**(code **)(*param_1 + 0x70))();
    uVar3 = FUN_0040d600(auStack_18,*(undefined4 *)(in_ECX + 0x9c));
    FUN_0040d690(&uStack_10,uVar3);
    *puVar2 = *(undefined4 *)(in_ECX + 0x6c);
    puVar2[1] = *(undefined4 *)(in_ECX + 0x70);
    puVar2[2] = *(undefined4 *)(in_ECX + 0x74);
    puVar2[3] = uStack_10;
    puVar2[4] = uStack_c;
    puVar2[5] = uStack_8;
    puVar2[6] = uStack_4;
    uVar3 = *(undefined4 *)(in_ECX + 0x98);
    *(undefined1 *)(puVar2 + 8) = 0;
    *(undefined1 *)((int)puVar2 + 0x26) = 0;
    *(undefined1 *)((int)puVar2 + 0x23) = 0;
    puVar2[7] = uVar3;
    *(undefined1 *)((int)puVar2 + 0x21) = 0xc;
    puVar2[0xd] = *(undefined4 *)(in_ECX + 0xa4);
    puVar2[0xe] = *(undefined4 *)(in_ECX + 0xa8);
    puVar2[0xb] = *(undefined4 *)(in_ECX + 0xa0);
    FUN_005cae40(in_ECX + 0x16c,param_1,puVar2,param_2);
    (**(code **)(*param_1 + 0x98))(puVar2);
    if (*(char *)(in_ECX + 0x7e) == '\x01') {
      FUN_005b0910(param_1,param_2);
      return;
    }
    FUN_005b1050(param_1,param_2);
  }
  return;
}


// ==== FUN_005b1680 @ 0x005b1680 ====

void FUN_005b1680(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (((*(int *)(in_ECX + 0x1b0) != 0) &&
      ((*(int *)(in_ECX + 0x1b4) - *(int *)(in_ECX + 0x1b0)) / 0x60 != 0)) &&
     (puVar6 = *(undefined4 **)(in_ECX + 0x1b0), puVar6 != *(undefined4 **)(in_ECX + 0x1b4))) {
    do {
      if ((uint)puVar6[1] < param_1) {
        (**(code **)(*DAT_00b5aff4 + 8))(puVar6[0x17]);
        puVar1 = *(undefined4 **)(in_ECX + 0x1b4);
        if (puVar6 + 0x18 != puVar1) {
          puVar2 = puVar6 + 0x18;
          puVar5 = puVar6;
          do {
            puVar3 = puVar2 + 0x18;
            puVar7 = puVar5;
            for (iVar4 = 0x18; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar7 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar2 = puVar3;
            puVar5 = puVar5 + 0x18;
          } while (puVar3 != puVar1);
        }
        *(int *)(in_ECX + 0x1b4) = *(int *)(in_ECX + 0x1b4) + -0x60;
      }
      else {
        puVar6[1] = puVar6[1] - param_1;
        puVar6 = puVar6 + 0x18;
      }
    } while (puVar6 != *(undefined4 **)(in_ECX + 0x1b4));
  }
  FUN_005b1370(param_1);
  return;
}


// ==== FUN_005b1750 @ 0x005b1750 ====

uint FUN_005b1750(int param_1)

{
  int iVar1;
  uint in_EAX;
  int *in_ECX;
  
  if (in_ECX[0x23] == 0) {
    *(undefined1 *)((int)in_ECX + 0x79) = 1;
    return in_EAX & 0xffffff00;
  }
  in_ECX[0x17] = in_ECX[0x17] + param_1;
  if ((uint)in_ECX[0x17] < (uint)in_ECX[0x16]) {
    return CONCAT31((int3)((uint)in_ECX[0x17] >> 8),1);
  }
  in_ECX[0x69] = 0;
  in_ECX[0x68] = 0;
  in_ECX[0x67] = 0;
  in_ECX[0x66] = 0;
  in_ECX[100] = 0;
  in_ECX[99] = 0;
  in_ECX[0x62] = 0;
  in_ECX[0x61] = 0;
  in_ECX[0x5f] = 0;
  in_ECX[0x5e] = 0;
  in_ECX[0x5d] = 0;
  in_ECX[0x5c] = 0;
  iVar1 = DAT_0099d080;
  in_ECX[0x6a] = DAT_0099d080;
  in_ECX[0x65] = iVar1;
  in_ECX[0x60] = iVar1;
  in_ECX[0x5b] = iVar1;
  (**(code **)(*in_ECX + 0x44))();
  FUN_005b0470(param_1);
  if (*(int *)in_ECX[0x37] != 0) {
    FUN_005b1680(param_1);
  }
  return (uint)(*(char *)((int)in_ECX + 0x79) == '\0');
}


// ==== FUN_005b1840 @ 0x005b1840 ====

int FUN_005b1840(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x60;
}


// ==== FUN_005b1860 @ 0x005b1860 ====

void FUN_005b1860(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_40 [16];
  
  thunk_FUN_0079f7f5(local_40,*param_2,param_2[1],param_2[2]);
  puVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_005b18a0 @ 0x005b18a0 ====

void FUN_005b18a0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 0x18;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 0x18; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_005b18d0 @ 0x005b18d0 ====

void FUN_005b18d0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -0x18;
    param_3 = param_3 + -0x18;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_005b1900 @ 0x005b1900 ====

void FUN_005b1900(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (iVar1 = 0x18; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_005b1920 @ 0x005b1920 ====

int FUN_005b1920(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982810;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x48) {
    FUN_008686b0(param_3,param_1);
    param_3 = param_3 + 0x48;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005b1986 @ 0x005b1986 ====

void Catch_005b1986(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005b1990 @ 0x005b1990 ====

void FUN_005b1990(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982820;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_008686b0(param_1,param_3);
    param_1 = param_1 + 0x48;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005b19f6 @ 0x005b19f6 ====

void Catch_005b19f6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005b1a00 @ 0x005b1a00 ====

int FUN_005b1a00(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982830;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x60) {
    FUN_005b1900(param_3,param_1);
    param_3 = param_3 + 0x60;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005b1a66 @ 0x005b1a66 ====

void Catch_005b1a66(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005b1a70 @ 0x005b1a70 ====

void FUN_005b1a70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005b1920(param_1,param_2,param_3);
  return;
}


// ==== FUN_005b1a90 @ 0x005b1a90 ====

void FUN_005b1a90(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982840;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005b1900(param_1,param_3);
    param_1 = param_1 + 0x60;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005b1af6 @ 0x005b1af6 ====

void Catch_005b1af6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005b1b00 @ 0x005b1b00 ====

void FUN_005b1b00(void)

{
  int in_ECX;
  
  if (0xf < *(uint *)(in_ECX + 0x70)) {
    _free(*(void **)(in_ECX + 0x5c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x70) = 0xf;
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined1 *)(in_ECX + 0x5c) = 0;
  if (0xf < *(uint *)(in_ECX + 0x54)) {
    _free(*(void **)(in_ECX + 0x40));
    return;
  }
  *(undefined4 *)(in_ECX + 0x54) = 0xf;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined1 *)(in_ECX + 0x40) = 0;
  if (0xf < *(uint *)(in_ECX + 0x38)) {
    _free(*(void **)(in_ECX + 0x24));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0xf;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  if (*(uint *)(in_ECX + 0x1c) < 0x10) {
    *(undefined4 *)(in_ECX + 0x1c) = 0xf;
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined1 *)(in_ECX + 8) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 8));
  return;
}


// ==== FUN_005b1b80 @ 0x005b1b80 ====

int FUN_005b1b80(int param_1,int param_2,undefined4 param_3)

{
  FUN_005b1990(param_1,param_2,param_3);
  return param_1 + param_2 * 0x48;
}


// ==== FUN_005b1bb0 @ 0x005b1bb0 ====

void FUN_005b1bb0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005b1a00(param_1,param_2,param_3);
  return;
}


// ==== FUN_005b1bd0 @ 0x005b1bd0 ====

int FUN_005b1bd0(int param_1,int param_2,undefined4 param_3)

{
  FUN_005b1a90(param_1,param_2,param_3);
  return param_2 * 0x60 + param_1;
}


// ==== FUN_005b1c00 @ 0x005b1c00 ====

undefined4 FUN_005b1c00(undefined4 param_1)

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
  local_4 = 8;
  uVar2 = (**(code **)(*piVar1 + 0xc))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_005b1c60 @ 0x005b1c60 ====

void FUN_005b1c60(byte param_1)

{
  void *in_ECX;
  
  FUN_005b0270();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005b1c80 @ 0x005b1c80 ====

void FUN_005b1c80(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  uint extraout_ECX;
  undefined4 *puVar4;
  undefined4 local_7c;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982850;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x88);
  puVar4 = &local_7c;
  for (iVar3 = 0x12; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_3;
    param_3 = param_3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x48;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x48;
    }
    ExceptionList = &local_10;
    if (0x38e38e3U - iVar1 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_20 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x48;
    }
    if (local_20 < iVar1 + param_2) {
      if (0x38e38e3 - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x48;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_00868440();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0x48;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_005b1a70(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_005b1b80(local_1c,param_2,&local_7c);
      FUN_005b1a70(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x48;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0x48);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0x48) < param_2) {
      local_24 = param_2 * 0x48;
      FUN_005b1920(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_005b1b80(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x48,&local_7c)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_008684d0(param_1,*(int *)(in_ECX + 8) - local_24,&local_7c);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x48;
    uVar2 = FUN_005b1920(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    FUN_00868660(param_1,local_2c,local_28);
    FUN_008684d0(param_1,param_2 * 0x48 + param_1,&local_7c);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005b1e28 @ 0x005b1e28 ====

void Catch_005b1e28(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005b1f30 @ 0x005b1f30 ====

void FUN_005b1f30(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  int extraout_ECX;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 local_90;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982860;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x9c);
  puVar4 = &local_90;
  for (iVar3 = 0x18; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_3;
    param_3 = param_3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x60;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x60;
    }
    ExceptionList = &local_10;
    if (0x2aaaaaaU - iVar1 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      iVar3 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x60;
    }
    if (uVar5 < iVar1 + param_2) {
      if (0x2aaaaaa - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x60;
      }
      if (uVar5 < iVar3 + param_2) {
        iVar3 = FUN_005b1840();
        uVar5 = iVar3 + param_2;
      }
      local_18 = operator_new(uVar5 * 0x60);
      local_8 = 0;
      local_1c = FUN_005b1bb0(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_005b1bd0(local_1c,param_2,&local_90);
      FUN_005b1bb0(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      iVar3 = *(int *)(in_ECX + 4);
      if (iVar3 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x60;
      }
      if (iVar3 == 0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 0x60 + (int)local_18);
        *(void **)(in_ECX + 8) = (void *)((param_2 + iVar1) * 0x60 + (int)local_18);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      for (; iVar3 != *(int *)(in_ECX + 8); iVar3 = iVar3 + 0x60) {
      }
      _free(*(void **)(in_ECX + 4));
      return;
    }
    local_24 = *(int *)(in_ECX + 8);
    if ((uint)((local_24 - param_1) / 0x60) < param_2) {
      local_20 = param_2 * 0x60;
      FUN_005b1a00(param_1,local_24,local_20 + param_1);
      local_8 = 2;
      FUN_005b1bd0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x60,&local_90)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_20;
      FUN_005b18a0(param_1,*(int *)(in_ECX + 8) - local_20,&local_90);
      ExceptionList = local_10;
      return;
    }
    local_28 = local_24 + param_2 * -0x60;
    uVar2 = FUN_005b1a00(local_28,local_24,local_24);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    FUN_005b18d0(param_1,local_28,local_24);
    FUN_005b18a0(param_1,param_2 * 0x60 + param_1,&local_90);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005b20f6 @ 0x005b20f6 ====

void Catch_005b20f6(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005b2210 @ 0x005b2210 ====

void FUN_005b2210(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x48 != 0) {
      iVar1 = (param_2 - iVar1) / 0x48;
      goto LAB_005b2255;
    }
  }
  iVar1 = 0;
LAB_005b2255:
  FUN_005b1c80(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x48;
  return;
}


// ==== FUN_005b2280 @ 0x005b2280 ====

void FUN_005b2280(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x60 != 0) {
      iVar1 = (param_2 - iVar1) / 0x60;
      goto LAB_005b22c5;
    }
  }
  iVar1 = 0;
LAB_005b22c5:
  FUN_005b1f30(param_2,1,param_3);
  *param_1 = iVar1 * 0x60 + *(int *)(in_ECX + 4);
  return;
}


// ==== FUN_005b22f0 @ 0x005b22f0 ====

void FUN_005b22f0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x48) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x48))) {
    FUN_005b2210(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005b1990(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x48;
  return;
}


// ==== FUN_005b2380 @ 0x005b2380 ====

void FUN_005b2380(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x60) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x60))) {
    FUN_005b2280(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005b1a90(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x60;
  return;
}


// ==== FUN_005b2410 @ 0x005b2410 ====

void FUN_005b2410(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_8 = *(float *)(in_ECX + 0x6c) - *(float *)(in_ECX + 0x98);
  local_4 = *(float *)(in_ECX + 0x74) - *(float *)(in_ECX + 0x9c);
  local_10 = *(float *)(in_ECX + 0x98) + *(float *)(in_ECX + 0x6c);
  local_c = *(float *)(in_ECX + 0x9c) + *(float *)(in_ECX + 0x74);
  FUN_004a8890(&local_8,&local_10,param_2);
  return;
}


// ==== FUN_005b24a0 @ 0x005b24a0 ====

void FUN_005b24a0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x79) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(in_ECX + 0x88);
  return;
}


// ==== FUN_005b24c0 @ 0x005b24c0 ====

bool FUN_005b24c0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_10 [16];
  
  uVar1 = (**(code **)(*in_ECX + 0x40))(local_10,param_1);
  iVar2 = FUN_0040d570(uVar1);
  return iVar2 != 1;
}


// ==== FUN_005b2520 @ 0x005b2520 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b2520(void)

{
  int iVar1;
  float fVar2;
  char cVar3;
  uint uVar4;
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x148) != '\x01') {
    if (*(int **)(in_ECX + 0xe4) == (int *)0x0) {
      cVar3 = (**(code **)(**(int **)(in_ECX + 0xe8) + 0x2c))();
      if (cVar3 == '\0') {
        return 0;
      }
      uVar4 = FUN_004b3b40();
      *(uint *)(in_ECX + 0x140) = uVar4;
      if (1 < uVar4) {
        iVar1 = **(int **)(in_ECX + 0xa8);
        cVar3 = '\0';
        if (iVar1 != 0) {
          cVar3 = (iVar1 != 1) + '\x01';
        }
        fVar2 = (float)(int)uVar4;
        if ((int)uVar4 < 0) {
          fVar2 = fVar2 + _DAT_0099d104;
        }
        FUN_0081d860(cVar3,0,fVar2,(*(int **)(in_ECX + 0xa8))[0x10]);
      }
    }
    else {
      cVar3 = (**(code **)(**(int **)(in_ECX + 0xe4) + 0x2c))();
      if (cVar3 == '\0') {
        return 0;
      }
    }
    *(undefined1 *)(in_ECX + 0x148) = 1;
  }
  return 1;
}


// ==== FUN_005b25c0 @ 0x005b25c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b25c0(void)

{
  float *pfVar1;
  int *piVar2;
  float fVar3;
  float fVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  float10 fVar11;
  float fVar12;
  undefined1 auStack_e6 [10];
  float fStack_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  float fStack_c8;
  float fStack_c4;
  undefined4 local_c0 [16];
  undefined1 local_80 [64];
  undefined4 local_40 [16];
  
  FUN_005ba1f0(local_c0);
  piVar2 = *(int **)(in_ECX + 0xac);
  if (*piVar2 != 0) {
    uVar6 = piVar2[0x10];
    uVar8 = *(uint *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x58);
    if (uVar6 == 0) {
      if ((char)piVar2[0xf] == '\x01') {
        uVar6 = *(uint *)(in_ECX + 0x144);
        uVar8 = *(uint *)(in_ECX + 0x5c);
      }
      else {
        uVar6 = *(uint *)(in_ECX + 0x88);
      }
    }
    if (piVar2[0x11] != 0) {
      uVar8 = uVar8 % uVar6;
    }
    fVar3 = (float)(int)uVar8;
    if ((int)uVar8 < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    fVar4 = (float)(int)uVar6;
    if ((int)uVar6 < 0) {
      fVar4 = fVar4 + _DAT_0099d104;
    }
    fVar12 = fVar3 / fVar4;
    if (DAT_0099d080 <= fVar3 / fVar4) {
      fVar12 = DAT_0099d080;
    }
    FUN_005ca8b0(fVar12,0x3f800000,0);
    FUN_005ca9e0(**(undefined4 **)(in_ECX + 0xac),local_80);
    thunk_FUN_0079ee7b(local_40,local_80,local_c0);
    puVar9 = local_40;
    puVar10 = local_c0;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
  }
  if (*(char *)(in_ECX + 0x149) == '\0') {
    fStack_d0 = *(float *)(in_ECX + 0xd8) + *(float *)(in_ECX + 0x60);
    fStack_cc = *(float *)(in_ECX + 0xdc) + *(float *)(in_ECX + 100);
    fStack_c8 = *(float *)(in_ECX + 0xe0) + *(float *)(in_ECX + 0x68);
    fStack_dc = fStack_d0;
    fStack_d8 = fStack_cc;
    fStack_d4 = fStack_c8;
  }
  else {
    fStack_d0 = *(float *)(in_ECX + 0x60);
    fStack_cc = *(float *)(in_ECX + 100);
    fStack_c8 = *(float *)(in_ECX + 0x68);
  }
  fStack_c4 = DAT_0099d080;
  thunk_FUN_0079ebf5(&fStack_d0,&fStack_d0);
  pfVar1 = (float *)(in_ECX + 0x6c);
  *pfVar1 = fStack_dc;
  *(float *)(in_ECX + 0x70) = fStack_d8;
  *(float *)(in_ECX + 0x74) = fStack_d4;
  if (*(char *)(in_ECX + 0x149) != '\0') {
    *pfVar1 = *(float *)(in_ECX + 0xd8) + *pfVar1;
    *(float *)(in_ECX + 0x70) = *(float *)(in_ECX + 0xdc) + *(float *)(in_ECX + 0x70);
    *(float *)(in_ECX + 0x74) = *(float *)(in_ECX + 0xe0) + *(float *)(in_ECX + 0x74);
  }
  if (*(int *)(in_ECX + 0x80) == 2) {
    uVar5 = FUN_005b94b0(auStack_e6 + -0xe);
    fVar11 = (float10)FUN_0040d5f0(uVar5);
    *(float *)(in_ECX + 0x14c) = (float)fVar11;
  }
  return;
}


// ==== FUN_005b2830 @ 0x005b2830 ====

void FUN_005b2830(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xc);
  uVar2 = *(undefined4 *)(in_ECX + 0x70);
  uVar3 = *(undefined4 *)(in_ECX + 0x74);
  *param_1 = *(undefined4 *)(in_ECX + 0x6c);
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  return;
}


// ==== FUN_005b2870 @ 0x005b2870 ====

void FUN_005b2870(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1d0c;
  if (in_ECX[0x3a] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x3a]);
    in_ECX[0x3a] = 0;
  }
  if (in_ECX[0x39] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x39]);
    in_ECX[0x39] = 0;
  }
  if ((void *)in_ECX[0x4c] == (void *)0x0) {
    in_ECX[0x4c] = 0;
    in_ECX[0x4d] = 0;
    in_ECX[0x4e] = 0;
    FUN_005caa70();
    *in_ECX = &PTR_FUN_009c1afc;
    return;
  }
  _free((void *)in_ECX[0x4c]);
  return;
}


// ==== FUN_005b28f0 @ 0x005b28f0 ====

void FUN_005b28f0(int param_1)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  uint local_4;
  
  uVar3 = DAT_0099d080;
  *(undefined1 *)(in_ECX + 0x148) = 0;
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(param_1 + 4);
  *(undefined4 *)(in_ECX + 0xb0) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0xa8) = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 0xa4) = 0xff000000;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0x94) = *(undefined4 *)(param_1 + 8);
  *(undefined4 *)(in_ECX + 0x98) = uVar3;
  *(undefined4 *)(in_ECX + 0x9c) = uVar3;
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  *(undefined4 *)(in_ECX + 0xd4) = 0;
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0x94);
  iVar1 = *(int *)(param_1 + 0x20);
  if (*(int *)(iVar1 + 0x1c) != 0) {
    uVar3 = FUN_005aa1b0(iVar1 + 8);
    *(undefined4 *)(in_ECX + 0xe4) = uVar3;
    *(undefined4 *)(in_ECX + 0x140) = 1;
    return;
  }
  if (*(int *)(iVar1 + 0x38) != 0) {
    uVar3 = FUN_005aa220(iVar1 + 0x24);
    *(undefined4 *)(in_ECX + 0xe8) = uVar3;
    *(undefined4 *)(in_ECX + 0x140) = 1;
    return;
  }
  FUN_00401830(s_false_009c1cb4);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005b2a10 @ 0x005b2a10 ====

void FUN_005b2a10(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_005b28f0(param_1);
  *(undefined4 *)(in_ECX + 4) = param_2;
  return;
}


// ==== FUN_005b2a30 @ 0x005b2a30 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b2a30(float param_1)

{
  int iVar1;
  float *pfVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  uint uVar5;
  int in_ECX;
  int iVar6;
  float10 fVar7;
  float fVar8;
  float fVar9;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  uVar5 = (uint)param_1;
  if ((uint)param_1 < *(uint *)(in_ECX + 0x8c)) {
    *(uint *)(in_ECX + 0x8c) = *(uint *)(in_ECX + 0x8c) - (int)param_1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x8c) = 0;
  }
  iVar6 = *(int *)(in_ECX + 0x8c);
  iVar1 = *(int *)(in_ECX + 0x88);
  fVar8 = (float)iVar6;
  if (iVar6 < 0) {
    fVar8 = fVar8 + _DAT_0099d104;
  }
  fVar9 = (float)iVar1;
  if (iVar1 < 0) {
    fVar9 = fVar9 + _DAT_0099d104;
  }
  fVar8 = DAT_0099d080 - fVar8 / fVar9;
  if (DAT_0099d080 <= fVar8) {
    fVar8 = DAT_0099d080;
  }
  else {
    if (fVar8 < 0.0) {
      fVar8 = 0.0;
    }
  }
  iVar1 = iVar1 - iVar6;
  iVar6 = (int)(fVar8 * DAT_009bf5a0);
  param_1 = DAT_0099d080;
  local_c = DAT_0099d080;
  local_8 = DAT_0099d080;
  local_4 = DAT_0099d080;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x58) != 0) {
    fVar7 = (float10)FUN_005aa2a0(iVar6,iVar1);
    param_1 = (float)fVar7;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0x90) != 0) {
    pfVar2 = (float *)FUN_005aa3a0(&local_1c,iVar6,iVar1);
    local_c = *pfVar2;
    local_8 = pfVar2[1];
    local_4 = pfVar2[2];
  }
  local_1c = local_c;
  local_18 = local_8;
  local_14 = local_4;
  local_10 = param_1;
  uVar3 = FUN_0040ead0(&local_1c);
  fVar8 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0xa4) = uVar3;
  fVar9 = fVar8;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x70) != 0) {
    FUN_005aa3a0(&local_c,iVar6,iVar1);
    local_1c = local_c;
    local_18 = local_4;
    fVar8 = local_4;
    fVar9 = local_c;
  }
  local_c = *(float *)(in_ECX + 0x94) * fVar9;
  local_8 = fVar8 * *(float *)(in_ECX + 0x94);
  *(float *)(in_ECX + 0x98) = local_c;
  *(float *)(in_ECX + 0x9c) = local_8;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x40) == 0) {
    *(undefined4 *)(in_ECX + 0xa0) = *(undefined4 *)(in_ECX + 0x14c);
  }
  else {
    fVar7 = (float10)FUN_005aa2a0(iVar6,iVar1);
    *(float *)(in_ECX + 0xa0) =
         (float)(fVar7 * (float10)_DAT_00af4f94 + (float10)*(float *)(in_ECX + 0x14c));
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0xb0) != 0) {
    puVar4 = (undefined4 *)FUN_005aa3a0(&local_c,iVar6,iVar1);
    *(undefined4 *)(in_ECX + 0x60) = *puVar4;
    *(undefined4 *)(in_ECX + 100) = puVar4[1];
    *(undefined4 *)(in_ECX + 0x68) = puVar4[2];
  }
  fVar8 = local_8;
  if ((*(int *)(in_ECX + 0x80) == 2) && (*(char *)(in_ECX + 0x149) == '\0')) {
    iVar6 = *(int *)(in_ECX + 4);
    local_c = *(float *)(iVar6 + 0xbc);
    local_8 = *(float *)(iVar6 + 0xc4);
    local_4 = local_8;
    if ((local_c != 0.0) ||
       ((*(float *)(iVar6 + 0xc0) != 0.0 || (fVar8 = *(float *)(iVar6 + 0xc0), local_8 != 0.0)))) {
      fVar7 = (float10)FUN_0040d5f0(&local_c);
      *(float *)(in_ECX + 0xa0) =
           (float)(fVar7 + (float10)_DAT_009c1d04 + (float10)*(float *)(in_ECX + 0xa0));
      fVar8 = local_8;
    }
  }
  local_8 = fVar8;
  if (1 < *(uint *)(in_ECX + 0x140)) {
    FUN_0081d6b0(uVar5);
    uVar5 = FUN_00802534();
    *(uint *)(in_ECX + 0xd4) = uVar5;
    if (*(uint *)(in_ECX + 0x140) <= uVar5) {
      *(uint *)(in_ECX + 0xd4) = *(uint *)(in_ECX + 0x140) - 1;
    }
  }
  return;
}


// ==== FUN_005b2d40 @ 0x005b2d40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_005b2d40(int *param_1,char param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float *pfVar5;
  float fVar6;
  int in_ECX;
  int iVar7;
  float fVar8;
  int *local_5c;
  float local_40;
  float local_3c;
  float local_38;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  undefined1 auStack_10 [12];
  float fStack_4;
  
  local_5c = *(int **)(in_ECX + 0xb0);
  if (*local_5c != 0) {
    local_5c = (int *)0x0;
    if ((*(int *)(in_ECX + 0x130) != 0) &&
       (iVar7 = *(int *)(in_ECX + 0x134) - *(int *)(in_ECX + 0x130),
       local_5c = (int *)(iVar7 * 0x38e38e39), iVar7 / 0x24 != 0)) {
      fVar4 = *(float *)(in_ECX + 0xe4);
      if (fVar4 == 0.0) {
        fVar4 = (float)FUN_004b3ff0(*(undefined4 *)(in_ECX + 0xd4));
      }
      local_5c = (int *)0x0;
      if (*(int *)(in_ECX + 0x130) != 0) {
        local_5c = (int *)((*(int *)(in_ECX + 0x134) - *(int *)(in_ECX + 0x130)) / 0x24);
      }
      local_40 = *(float *)(in_ECX + 0x6c);
      local_3c = *(float *)(in_ECX + 0x70);
      local_38 = *(float *)(in_ECX + 0x74);
      if (0 < (int)local_5c) {
        iVar7 = (int)local_5c * 0x24;
        do {
          iVar7 = iVar7 + -0x24;
          pfVar5 = (float *)(**(code **)(*param_1 + 0xc0))();
          pfVar5[3] = fVar4;
          pfVar5[8] = *(float *)(in_ECX + 0x80);
          pfVar5[9] = *(float *)(*(int *)(in_ECX + 0xa8) + 4);
          *(undefined1 *)((int)pfVar5 + 0x29) = *(undefined1 *)(*(int *)(in_ECX + 0xa8) + 0x44);
          iVar3 = *(int *)(in_ECX + 0x130);
          if ((iVar3 == 0) ||
             ((uint)((*(int *)(in_ECX + 0x134) - iVar3) / 0x24) <= (int)local_5c - 1U)) {
                    /* WARNING: Subroutine does not return */
            FUN_0085b340();
          }
          fVar6 = (float)*(int *)(iVar3 + 4 + iVar7);
          if (*(int *)(iVar3 + 4 + iVar7) < 0) {
            fVar6 = fVar6 + _DAT_0099d104;
          }
          fVar2 = (float)*(int *)(iVar3 + iVar7);
          if (*(int *)(iVar3 + iVar7) < 0) {
            fVar2 = fVar2 + _DAT_0099d104;
          }
          fVar6 = fVar6 / fVar2;
          FUN_0040ec60(auStack_10,*(undefined4 *)(iVar3 + 8 + iVar7));
          fStack_4 = fStack_4 * fVar6;
          pfVar1 = (float *)(iVar3 + 0x18 + iVar7);
          fVar2 = SQRT((*pfVar1 - local_40) * (*pfVar1 - local_40) +
                       (pfVar1[1] - local_3c) * (pfVar1[1] - local_3c) +
                       (pfVar1[2] - local_38) * (pfVar1[2] - local_38));
          if ((*(float *)(*(int *)(in_ECX + 0xb0) + 8) < fVar2) &&
             (fVar8 = *(float *)(*(int *)(in_ECX + 0xb0) + 8), DAT_0099cdc8 < fVar8)) {
            fVar8 = fVar8 / fVar2;
            *pfVar1 = (*pfVar1 - local_40) * fVar8 + local_40;
            pfVar1[1] = (pfVar1[1] - local_3c) * fVar8 + local_3c;
            pfVar1[2] = (pfVar1[2] - local_38) * fVar8 + local_38;
          }
          local_40 = *pfVar1;
          local_3c = pfVar1[1];
          local_38 = pfVar1[2];
          *pfVar5 = *pfVar1;
          pfVar5[1] = pfVar1[1];
          pfVar5[2] = pfVar1[2];
          if (*(char *)(*(int *)(in_ECX + 0xb0) + 0x10) == '\0') {
            pfVar5[4] = *(float *)(iVar3 + 0x10 + iVar7);
            pfVar5[5] = *(float *)(iVar3 + 0x14 + iVar7);
          }
          else {
            fVar2 = *(float *)(iVar3 + 0x14 + iVar7);
            pfVar5[4] = *(float *)(iVar3 + 0x10 + iVar7) * fVar6;
            pfVar5[5] = fVar2 * fVar6;
          }
          fVar6 = (float)FUN_0040ead0(auStack_10);
          pfVar5[6] = fVar6;
          pfVar5[7] = *(float *)(iVar3 + 0xc + iVar7);
          if (*(char *)((int)pfVar5 + 0x29) != '\0') {
            fStack_28 = *pfVar5 - *(float *)(in_ECX + 0x150);
            fStack_24 = pfVar5[1] - *(float *)(in_ECX + 0x154);
            fStack_20 = pfVar5[2] - *(float *)(in_ECX + 0x158);
            thunk_FUN_0079e1ba(&fStack_1c,&fStack_28);
            fVar6 = pfVar5[5] * DAT_0099d0b4;
            *pfVar5 = fStack_1c * fVar6 + *pfVar5;
            pfVar5[1] = fStack_18 * fVar6 + pfVar5[1];
            pfVar5[2] = pfVar5[2] + fStack_14 * fVar6;
          }
          if (param_2 == '\0') {
            (**(code **)(*param_1 + 0x88))(pfVar5);
          }
          else {
            (**(code **)(*param_1 + 0x118))();
          }
          local_5c = (int *)((int)local_5c + -1);
        } while (0 < (int)local_5c);
      }
    }
  }
  return local_5c;
}


// ==== FUN_005b3100 @ 0x005b3100 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b3100(int param_1,float param_2,int param_3)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int *in_ECX;
  int iVar4;
  float10 fVar5;
  
  in_ECX[2] = param_1;
  in_ECX[0x15] = *(int *)(param_1 + 8);
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  *(undefined1 *)((int)in_ECX + 0x149) = *(undefined1 *)(param_1 + 0x31);
  in_ECX[0x35] = 0;
  in_ECX[0x18] = *(int *)(param_1 + 0x18);
  in_ECX[0x19] = *(int *)(param_1 + 0x1c);
  in_ECX[0x1a] = *(int *)(param_1 + 0x20);
  in_ECX[0x36] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  if (*(char *)(param_1 + 0x32) != '\0') {
    fVar2 = (float)in_ECX[0x16];
    if (in_ECX[0x16] < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar5 = (float10)FUN_0040d0a0(0,fVar2 * DAT_0099d0ec);
    in_ECX[0x16] = (int)ROUND(fVar5 * (float10)DAT_009b012c);
  }
  iVar1 = in_ECX[2];
  fVar2 = (float)*(int *)(iVar1 + 0xc);
  if (*(int *)(iVar1 + 0xc) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  in_ECX[0x16] = (int)ROUND(fVar2 * param_2);
  iVar4 = *(int *)(iVar1 + 0x10) - *(int *)(iVar1 + 0xc);
  fVar2 = (float)iVar4;
  if (iVar4 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  iVar4 = (int)ROUND(fVar2 * param_2);
  in_ECX[0x22] = iVar4;
  in_ECX[0x51] = (int)ROUND(param_2 * DAT_009b012c);
  iVar3 = param_3 - in_ECX[0x16];
  if (iVar3 < 0) {
    in_ECX[0x23] = iVar4;
  }
  else if (iVar3 < iVar4) {
    in_ECX[0x23] = iVar4 - iVar3;
  }
  else {
    in_ECX[0x23] = 0;
  }
  iVar1 = *(int *)(iVar1 + 0x34);
  in_ECX[0x2b] = iVar1;
  if ((*(int *)(iVar1 + 0x18) != 0) && (*(int *)(iVar1 + 0x34) != 0)) {
    FUN_005ca850(iVar1 + 4);
    FUN_005caad0();
    FUN_005cab40(in_ECX[0x2b] + 0x20);
  }
  if ((void *)in_ECX[0x4c] == (void *)0x0) {
    in_ECX[0x4c] = 0;
    in_ECX[0x4d] = 0;
    in_ECX[0x4e] = 0;
    in_ECX[0x17] = param_3;
    (**(code **)(*in_ECX + 0x44))();
    FUN_005b2a30(0);
    return;
  }
  _free((void *)in_ECX[0x4c]);
  return;
}


// ==== FUN_005b3310 @ 0x005b3310 ====

void FUN_005b3310(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1d0c;
  in_ECX[0x24] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x39] = 0;
  in_ECX[0x3a] = 0;
  FUN_005caa30();
  in_ECX[0x4c] = 0;
  in_ECX[0x4d] = 0;
  in_ECX[0x4e] = 0;
  in_ECX[0x57] = 0;
  in_ECX[0x58] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x4f] = 0;
  in_ECX[0x59] = 0;
  in_ECX[0x53] = 0;
  return;
}


// ==== FUN_005b33b0 @ 0x005b33b0 ====

void FUN_005b33b0(int *param_1,undefined4 param_2)

{
  char cVar1;
  float *pfVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  float fVar6;
  undefined4 uStack_18;
  float fStack_14;
  undefined1 auStack_10 [4];
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((*(int *)(in_ECX + 0x88) != 0) && (*(uint *)(in_ECX + 0x58) <= *(uint *)(in_ECX + 0x5c))) {
    cVar1 = FUN_005b2520();
    if (cVar1 != '\0') {
      pfVar2 = (float *)(**(code **)(*param_1 + 0xc0))();
      pfVar2[8] = *(float *)(in_ECX + 0x80);
      pfVar2[9] = *(float *)(*(int *)(in_ECX + 0xa8) + 4);
      *pfVar2 = *(float *)(in_ECX + 0x6c);
      pfVar2[1] = *(float *)(in_ECX + 0x70);
      pfVar2[2] = *(float *)(in_ECX + 0x74);
      pfVar2[4] = *(float *)(in_ECX + 0x98);
      pfVar2[5] = *(float *)(in_ECX + 0x9c);
      pfVar2[6] = *(float *)(in_ECX + 0xa4);
      pfVar2[7] = *(float *)(in_ECX + 0xa0);
      cVar1 = *(char *)(*(int *)(in_ECX + 0xa8) + 0x44);
      *(char *)((int)pfVar2 + 0x29) = cVar1;
      if (cVar1 != '\0') {
        if ((char)param_2 == '\0') {
          iVar4 = (**(code **)(*DAT_00b5a988 + 0x14))();
          puVar3 = (undefined4 *)(iVar4 + 0x28);
          *(undefined4 *)(in_ECX + 0x150) = *puVar3;
          uVar5 = *(undefined4 *)(iVar4 + 0x2c);
        }
        else {
          puVar3 = (undefined4 *)(**(code **)(*DAT_00b5afa8 + 0xc))(&uStack_18);
          *(undefined4 *)(in_ECX + 0x150) = *puVar3;
          uVar5 = puVar3[1];
        }
        *(undefined4 *)(in_ECX + 0x154) = uVar5;
        *(undefined4 *)(in_ECX + 0x158) = puVar3[2];
        uStack_18 = *(float *)(in_ECX + 0x70) - *(float *)(in_ECX + 0x154);
        fStack_14 = *(float *)(in_ECX + 0x74) - *(float *)(in_ECX + 0x158);
        thunk_FUN_0079e1ba(auStack_10,auStack_10 + -0xc);
        fVar6 = pfVar2[5] * DAT_0099d0b4;
        *pfVar2 = *pfVar2 + fStack_c * fVar6;
        pfVar2[1] = pfVar2[1] + fStack_8 * fVar6;
        pfVar2[2] = pfVar2[2] + fStack_4 * fVar6;
      }
      fVar6 = *(float *)(in_ECX + 0xe4);
      if (fVar6 == 0.0) {
        fVar6 = (float)FUN_004b3ff0(*(undefined4 *)(in_ECX + 0xd4));
      }
      pfVar2[3] = fVar6;
      if ((char)param_2 != '\0') {
        (**(code **)(*param_1 + 0x118))();
        FUN_005b2d40(param_1,param_2);
        return;
      }
      (**(code **)(*param_1 + 0x88))(pfVar2);
      FUN_005b2d40(param_1,param_2);
    }
  }
  return;
}


// ==== FUN_005b35a0 @ 0x005b35a0 ====

void FUN_005b35a0(int param_1)

{
  uint *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  uint uVar5;
  int in_ECX;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  uVar5 = 0;
  if (*(int *)(in_ECX + 0x130) != 0) {
    uVar5 = (*(int *)(in_ECX + 0x134) - *(int *)(in_ECX + 0x130)) / 0x24;
  }
  puVar1 = *(uint **)(in_ECX + 0xb0);
  if (((uVar5 < *puVar1) &&
      (*(int *)(in_ECX + 0x13c) = *(int *)(in_ECX + 0x13c) + param_1,
      puVar1[1] <= *(uint *)(in_ECX + 0x13c))) &&
     (((float)puVar1[2] <= DAT_0099cdc8 ||
      (fVar2 = *(float *)(in_ECX + 0x6c) - *(float *)(in_ECX + 0x15c),
      fVar3 = *(float *)(in_ECX + 0x70) - *(float *)(in_ECX + 0x160),
      fVar4 = *(float *)(in_ECX + 0x74) - *(float *)(in_ECX + 0x164),
      (float)puVar1[2] <= SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4))))) {
    local_24 = puVar1[3];
    local_14 = *(undefined4 *)(in_ECX + 0x98);
    local_18 = *(undefined4 *)(in_ECX + 0xa0);
    local_10 = *(undefined4 *)(in_ECX + 0x9c);
    local_1c = *(undefined4 *)(in_ECX + 0xa4);
    local_c = *(undefined4 *)(in_ECX + 0x6c);
    local_8 = *(undefined4 *)(in_ECX + 0x70);
    local_4 = *(undefined4 *)(in_ECX + 0x74);
    local_20 = local_24;
    FUN_005b3c30(&local_24);
    *(undefined4 *)(in_ECX + 0x15c) = *(undefined4 *)(in_ECX + 0x6c);
    *(undefined4 *)(in_ECX + 0x160) = *(undefined4 *)(in_ECX + 0x70);
    *(undefined4 *)(in_ECX + 0x164) = *(undefined4 *)(in_ECX + 0x74);
    *(undefined4 *)(in_ECX + 0x13c) = 0;
  }
  return;
}


// ==== FUN_005b36c0 @ 0x005b36c0 ====

void FUN_005b36c0(uint param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  if (((*(int *)(in_ECX + 0x130) != 0) &&
      ((*(int *)(in_ECX + 0x134) - *(int *)(in_ECX + 0x130)) / 0x24 != 0)) &&
     (puVar6 = *(undefined4 **)(in_ECX + 0x130), puVar6 != *(undefined4 **)(in_ECX + 0x134))) {
    do {
      if ((uint)puVar6[1] < param_1) {
        puVar1 = *(undefined4 **)(in_ECX + 0x134);
        if (puVar6 + 9 != puVar1) {
          puVar2 = puVar6 + 9;
          puVar5 = puVar6;
          do {
            puVar3 = puVar2 + 9;
            puVar7 = puVar5;
            for (iVar4 = 9; iVar4 != 0; iVar4 = iVar4 + -1) {
              *puVar7 = *puVar2;
              puVar2 = puVar2 + 1;
              puVar7 = puVar7 + 1;
            }
            puVar2 = puVar3;
            puVar5 = puVar5 + 9;
          } while (puVar3 != puVar1);
        }
        *(int *)(in_ECX + 0x134) = *(int *)(in_ECX + 0x134) + -0x24;
      }
      else {
        puVar6[1] = puVar6[1] - param_1;
        puVar6 = puVar6 + 9;
      }
    } while (puVar6 != *(undefined4 **)(in_ECX + 0x134));
  }
  FUN_005b35a0();
  return;
}


// ==== FUN_005b3760 @ 0x005b3760 ====

uint FUN_005b3760(int param_1)

{
  uint in_EAX;
  int *in_ECX;
  
  if (in_ECX[0x23] == 0) {
    *(undefined1 *)((int)in_ECX + 0x79) = 1;
    return in_EAX & 0xffffff00;
  }
  in_ECX[0x17] = in_ECX[0x17] + param_1;
  if ((uint)in_ECX[0x17] < (uint)in_ECX[0x16]) {
    return CONCAT31((int3)((uint)in_ECX[0x17] >> 8),1);
  }
  (**(code **)(*in_ECX + 0x44))();
  FUN_005b2a30(param_1);
  if (*(int *)in_ECX[0x2c] != 0) {
    FUN_005b36c0(param_1);
  }
  return (uint)(*(char *)((int)in_ECX + 0x79) == '\0');
}


// ==== FUN_005b37c0 @ 0x005b37c0 ====

int FUN_005b37c0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982870;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x24) {
    FUN_00868690(param_3,param_1);
    param_3 = param_3 + 0x24;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005b3826 @ 0x005b3826 ====

void Catch_005b3826(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005b3830 @ 0x005b3830 ====

void FUN_005b3830(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982880;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00868690(param_1,param_3);
    param_1 = param_1 + 0x24;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005b3896 @ 0x005b3896 ====

void Catch_005b3896(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005b38a0 @ 0x005b38a0 ====

void FUN_005b38a0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005b37c0(param_1,param_2,param_3);
  return;
}


// ==== FUN_005b38c0 @ 0x005b38c0 ====

int FUN_005b38c0(int param_1,int param_2,undefined4 param_3)

{
  FUN_005b3830(param_1,param_2,param_3);
  return param_1 + param_2 * 0x24;
}


// ==== FUN_005b38f0 @ 0x005b38f0 ====

void FUN_005b38f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005b2870();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005b3910 @ 0x005b3910 ====

void FUN_005b3910(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  uint extraout_ECX;
  undefined4 *puVar4;
  undefined4 local_58;
  int local_2c;
  int local_28;
  int local_24;
  uint local_20;
  undefined4 local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982890;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -100);
  puVar4 = &local_58;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *param_3;
    param_3 = param_3 + 1;
    puVar4 = puVar4 + 1;
  }
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 == 0) {
    local_20 = 0;
  }
  else {
    local_20 = (*(int *)(in_ECX + 0xc) - iVar3) / 0x24;
  }
  if (param_2 != 0) {
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
    }
    ExceptionList = &local_10;
    if (0x71c71c7U - iVar1 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_20 = extraout_ECX;
    }
    if (iVar3 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
    }
    if (local_20 < iVar1 + param_2) {
      if (0x71c71c7 - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar3 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - iVar3) / 0x24;
      }
      if (local_20 < iVar3 + param_2) {
        iVar3 = FUN_0066e7e0();
        local_20 = iVar3 + param_2;
      }
      local_20 = local_20 * 0x24;
      local_18 = operator_new(local_20);
      local_8 = 0;
      local_1c = FUN_005b38a0(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_005b38c0(local_1c,param_2,&local_58);
      FUN_005b38a0(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x24;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)local_18;
        *(void **)(in_ECX + 8) = (void *)((int)local_18 + (param_2 + iVar3) * 0x24);
        *(void **)(in_ECX + 4) = local_18;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)((local_28 - param_1) / 0x24) < param_2) {
      local_24 = param_2 * 0x24;
      FUN_005b37c0(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_005b38c0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x24,&local_58)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_008684a0(param_1,*(int *)(in_ECX + 8) - local_24,&local_58);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x24;
    uVar2 = FUN_005b37c0(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    FUN_004ab860(param_1,local_2c,local_28);
    FUN_008684a0(param_1,param_2 * 0x24 + param_1,&local_58);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005b3ab6 @ 0x005b3ab6 ====

void Catch_005b3ab6(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005b3bc0 @ 0x005b3bc0 ====

void FUN_005b3bc0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x24 != 0) {
      iVar1 = (param_2 - iVar1) / 0x24;
      goto LAB_005b3c05;
    }
  }
  iVar1 = 0;
LAB_005b3c05:
  FUN_005b3910(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x24;
  return;
}


// ==== FUN_005b3c30 @ 0x005b3c30 ====

void FUN_005b3c30(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x24) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x24))) {
    FUN_005b3bc0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005b3830(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x24;
  return;
}


// ==== FUN_005b3cc0 @ 0x005b3cc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b3cc0(int param_1,float param_2,int param_3)

{
  float fVar1;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  
  *(int *)(in_ECX + 8) = param_1;
  *(undefined4 *)(in_ECX + 0x54) = *(undefined4 *)(param_1 + 8);
  *(undefined1 *)(in_ECX + 0x79) = 0;
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  fVar1 = (float)*(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  *(int *)(in_ECX + 0x58) = (int)ROUND(fVar1 * param_2);
  uVar2 = FUN_00802534();
  uVar3 = param_3 - *(int *)(in_ECX + 0x58);
  *(uint *)(in_ECX + 0x7c) = uVar2;
  *(int *)(in_ECX + 0x5c) = param_3;
  if (uVar3 < uVar2) {
    *(uint *)(in_ECX + 0x80) = uVar2 - uVar3;
    return;
  }
  *(undefined4 *)(in_ECX + 0x80) = 0;
  return;
}


// ==== FUN_005b3d80 @ 0x005b3d80 ====

void FUN_005b3d80(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x79) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(in_ECX + 0x7c);
  return;
}


// ==== FUN_005b3da0 @ 0x005b3da0 ====

undefined1 FUN_005b3da0(void)

{
  return 1;
}


// ==== FUN_005b3db0 @ 0x005b3db0 ====

bool FUN_005b3db0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_10 [16];
  
  uVar1 = (**(code **)(*in_ECX + 0x40))(local_10,param_1);
  iVar2 = FUN_0040d570(uVar1);
  return iVar2 != 1;
}


// ==== FUN_005b3de0 @ 0x005b3de0 ====

void FUN_005b3de0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xc);
  uVar2 = *(undefined4 *)(in_ECX + 0x70);
  uVar3 = *(undefined4 *)(in_ECX + 0x74);
  *param_1 = *(undefined4 *)(in_ECX + 0x6c);
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  return;
}


// ==== FUN_005b3e20 @ 0x005b3e20 ====

void FUN_005b3e20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1d5c;
  if (in_ECX[0x2f] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0x2f]);
    in_ECX[0x2f] = 0;
  }
  if ((uint)in_ECX[0x2d] < 0x10) {
    in_ECX[0x2d] = 0xf;
    in_ECX[0x2c] = 0;
    *(undefined1 *)(in_ECX + 0x28) = 0;
    *in_ECX = &PTR_FUN_009c1afc;
    return;
  }
  _free((void *)in_ECX[0x28]);
  return;
}


// ==== FUN_005b3e90 @ 0x005b3e90 ====

void FUN_005b3e90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1d5c;
  in_ECX[0x2d] = 0xf;
  in_ECX[0x2c] = 0;
  *(undefined1 *)(in_ECX + 0x28) = 0;
  in_ECX[0x2f] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x17] = 0;
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  return;
}


// ==== FUN_005b3ed0 @ 0x005b3ed0 ====

void FUN_005b3ed0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xb8) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
  *(undefined4 *)(in_ECX + 0x7c) = 0;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x8c) = 0;
  *(undefined4 *)(in_ECX + 0x90) = 0;
  *(undefined4 *)(in_ECX + 0x94) = 0;
  *(undefined4 *)(in_ECX + 0x88) = 0;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  *(undefined4 *)(in_ECX + 0x98) = 0xff000000;
  uVar1 = FUN_005aa1b0(*(int *)(param_1 + 0x20) + 8);
  *(undefined4 *)(in_ECX + 0xbc) = uVar1;
  return;
}


// ==== FUN_005b3f60 @ 0x005b3f60 ====

void FUN_005b3f60(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_005b3ed0(param_1);
  *(undefined4 *)(in_ECX + 4) = param_2;
  return;
}


// ==== FUN_005b3f80 @ 0x005b3f80 ====

void FUN_005b3f80(byte param_1)

{
  void *in_ECX;
  
  FUN_005b3e20();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005b3fa0 @ 0x005b3fa0 ====

void FUN_005b3fa0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x79) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x174) = 0;
  *(undefined4 *)(in_ECX + 0x178) = 0;
  *(undefined4 *)(in_ECX + 0x17c) = 0;
  *(undefined4 *)(in_ECX + 0x168) = *(undefined4 *)(in_ECX + 0x164);
  return;
}


// ==== FUN_005b3ff0 @ 0x005b3ff0 ====

void FUN_005b3ff0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x58) <= *(uint *)(in_ECX + 0x5c)) {
    (**(code **)(**(int **)(in_ECX + 0x104) + 4))
              (in_ECX + 0x114,param_1,*(undefined4 *)(in_ECX + 0x160),param_2);
  }
  return;
}


// ==== FUN_005b4030 @ 0x005b4030 ====

bool FUN_005b4030(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_10 [16];
  
  uVar1 = (**(code **)(*in_ECX + 0x40))(local_10,param_1);
  iVar2 = FUN_0040d570(uVar1);
  return iVar2 != 1;
}


// ==== FUN_005b4060 @ 0x005b4060 ====

void FUN_005b4060(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_8 = *(float *)(in_ECX + 0x6c) - DAT_0099d080;
  local_4 = *(float *)(in_ECX + 0x74) - DAT_0099d080;
  local_10 = *(float *)(in_ECX + 0x6c) + DAT_0099d080;
  local_c = *(float *)(in_ECX + 0x74) + DAT_0099d080;
  FUN_004a8890(&local_8,&local_10,param_2);
  return;
}


// ==== FUN_005b40e0 @ 0x005b40e0 ====

void FUN_005b40e0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x94) = 0;
  return;
}


// ==== FUN_005b40f0 @ 0x005b40f0 ====

void FUN_005b40f0(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  undefined4 uVar5;
  int in_ECX;
  float10 fVar6;
  undefined1 local_c [12];
  
  fVar6 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x30),
                                *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x2c));
  *(float *)(param_1 + 0xb8) = (float)fVar6;
  fVar6 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x28),
                                *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x24));
  fVar3 = (float)fVar6;
  *(float *)(param_1 + 0xbc) = (float)fVar6;
  pfVar4 = (float *)FUN_0040ecc0(local_c);
  fVar1 = pfVar4[1];
  fVar2 = pfVar4[2];
  *(float *)(param_1 + 0xc) = *pfVar4 * fVar3;
  *(float *)(param_1 + 0x10) = fVar1 * fVar3;
  *(float *)(param_1 + 0x14) = fVar2 * fVar3;
  fVar1 = *(float *)(in_ECX + 400);
  fVar2 = *(float *)(in_ECX + 0x194);
  *(float *)(param_1 + 0xc0) = *(float *)(in_ECX + 0x18c) + *(float *)(param_1 + 0xc);
  *(float *)(param_1 + 0xc4) = fVar1 + *(float *)(param_1 + 0x10);
  *(float *)(param_1 + 200) = fVar2 + *(float *)(param_1 + 0x14);
  uVar5 = FUN_00802534();
  *(undefined4 *)(param_1 + 0xb0) = uVar5;
  *(undefined4 *)(param_1 + 0xb4) = uVar5;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  *(undefined1 *)(param_1 + 0xac) = 1;
  *(undefined4 *)(param_1 + 0xd8) = 0;
  return;
}


// ==== FUN_005b4250 @ 0x005b4250 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b4250(uint *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  
  if (*param_1 < *(uint *)(param_2 + 0xb4)) {
    *(uint *)(param_2 + 0xb4) = *(uint *)(param_2 + 0xb4) - *param_1;
  }
  else {
    *(undefined4 *)(param_2 + 0xb4) = 0;
  }
  fVar1 = (float)*(int *)(param_2 + 0xb4);
  if (*(int *)(param_2 + 0xb4) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar2 = (float)*(int *)(param_2 + 0xb0);
  if (*(int *)(param_2 + 0xb0) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  *(float *)(param_2 + 0x34) = fVar1 / fVar2;
  return;
}


// ==== FUN_005b42e0 @ 0x005b42e0 ====

void FUN_005b42e0(float *param_1,int param_2)

{
  float fVar1;
  int iVar2;
  int in_ECX;
  float fVar3;
  float fVar4;
  
  fVar3 = *(float *)(param_2 + 0xcc) - *(float *)(*(int *)(in_ECX + 0xf4) + 0x34) * *param_1;
  if (fVar3 < 0.0) {
    fVar3 = 0.0;
  }
  *(float *)(param_2 + 0xcc) = fVar3;
  iVar2 = *(int *)(in_ECX + 0xf4);
  fVar3 = *param_1;
  fVar4 = *(float *)(iVar2 + 0x50);
  fVar1 = *(float *)(iVar2 + 0x54);
  *(float *)(param_2 + 0xdc) = *(float *)(param_2 + 0xdc) + *(float *)(iVar2 + 0x4c) * fVar3;
  *(float *)(param_2 + 0xe0) = *(float *)(param_2 + 0xe0) + fVar4 * fVar3;
  *(float *)(param_2 + 0xe4) = *(float *)(param_2 + 0xe4) + fVar1 * fVar3;
  fVar4 = *param_1 * *(float *)(param_2 + 0xcc);
  fVar3 = *param_1;
  *(float *)(param_2 + 0xc) =
       *(float *)(param_2 + 0xc) + *(float *)(param_2 + 0xd0) * fVar4 +
       *(float *)(param_2 + 0xdc) * fVar3;
  *(float *)(param_2 + 0x10) =
       *(float *)(param_2 + 0x10) + *(float *)(param_2 + 0xd4) * fVar4 +
       *(float *)(param_2 + 0xe0) * fVar3;
  *(float *)(param_2 + 0x14) =
       *(float *)(param_2 + 0x14) + *(float *)(param_2 + 0xd8) * fVar4 +
       *(float *)(param_2 + 0xe4) * fVar3;
  return;
}


// ==== FUN_005b4430 @ 0x005b4430 ====

void FUN_005b4430(float *param_1,int param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float fVar7;
  
  iVar4 = *(int *)(in_ECX + 0xf4);
  fVar1 = *(float *)(iVar4 + 0x5c);
  fVar2 = *(float *)(iVar4 + 0x60);
  fVar3 = *param_1;
  fVar7 = DAT_0099d080 - *param_1;
  *(float *)(param_2 + 0xc) = *(float *)(param_2 + 0xc0) * fVar7 + *(float *)(iVar4 + 0x58) * fVar3;
  *(float *)(param_2 + 0x10) = *(float *)(param_2 + 0xc4) * fVar7 + fVar1 * fVar3;
  *(float *)(param_2 + 0x14) = *(float *)(param_2 + 200) * fVar7 + fVar2 * fVar3;
  puVar5 = (undefined4 *)(in_ECX + 0x198);
  puVar6 = (undefined4 *)(param_2 + 0xe8);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  return;
}


// ==== FUN_005b4570 @ 0x005b4570 ====

void FUN_005b4570(int param_1)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x104) + 8))(param_1);
  *(undefined4 *)(in_ECX + 0xec) = 0;
  *(undefined4 *)(in_ECX + 0xe8) = 0;
  *(undefined4 *)(in_ECX + 0xe4) = 0;
  *(undefined4 *)(in_ECX + 0xe0) = 0;
  *(undefined4 *)(in_ECX + 0xd8) = 0;
  *(undefined4 *)(in_ECX + 0xd4) = 0;
  *(undefined4 *)(in_ECX + 0xd0) = 0;
  *(undefined4 *)(in_ECX + 0xcc) = 0;
  *(undefined4 *)(in_ECX + 0xc4) = 0;
  *(undefined4 *)(in_ECX + 0xc0) = 0;
  *(undefined4 *)(in_ECX + 0xbc) = 0;
  *(undefined4 *)(in_ECX + 0xb8) = 0;
  uVar3 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0xf0) = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0xdc) = uVar3;
  *(undefined4 *)(in_ECX + 200) = uVar3;
  *(undefined4 *)(in_ECX + 0xb4) = uVar3;
  *(undefined4 *)(in_ECX + 0x90) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x40);
  *(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 0x24);
  *(int *)(in_ECX + 0xf4) = iVar1;
  *(undefined4 *)(in_ECX + 0xfc) = *(undefined4 *)(param_1 + 0x14);
  *(undefined4 *)(in_ECX + 0x94) = 0;
  *(undefined4 *)(in_ECX + 0xc) = uVar3;
  fVar2 = SQRT(*(float *)(iVar1 + 0x40) * *(float *)(iVar1 + 0x40) +
               *(float *)(iVar1 + 0x44) * *(float *)(iVar1 + 0x44) +
               *(float *)(iVar1 + 0x48) * *(float *)(iVar1 + 0x48));
  *(float *)(in_ECX + 0x170) = fVar2;
  if (fVar2 == DAT_0099cdc8) {
    *(undefined4 *)(in_ECX + 0x170) = uVar3;
  }
  return;
}


// ==== FUN_005b46a0 @ 0x005b46a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b46a0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int *piVar3;
  float fVar4;
  float fVar5;
  uint uVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  float fVar11;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  float fStack_d0;
  undefined4 uStack_cc;
  undefined4 uStack_c8;
  float fStack_c4;
  undefined4 local_c0 [9];
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 auStack_8c [19];
  undefined1 local_40 [64];
  
  FUN_005ba1f0(local_c0,*(undefined4 *)(in_ECX + 0x54));
  piVar3 = *(int **)(in_ECX + 0xf8);
  if (*piVar3 != 0) {
    uVar7 = piVar3[0x10];
    uVar6 = *(uint *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x58);
    if (uVar7 == 0) {
      if ((char)piVar3[0xf] == '\x01') {
        uVar7 = *(uint *)(in_ECX + 0x16c);
        uVar6 = *(uint *)(in_ECX + 0x5c);
      }
      else {
        uVar7 = *(uint *)(in_ECX + 0x164);
      }
    }
    if (piVar3[0x11] != 0) {
      uVar6 = uVar6 % uVar7;
    }
    fVar4 = (float)(int)uVar6;
    if ((int)uVar6 < 0) {
      fVar4 = fVar4 + _DAT_0099d104;
    }
    fVar5 = (float)(int)uVar7;
    if ((int)uVar7 < 0) {
      fVar5 = fVar5 + _DAT_0099d104;
    }
    fVar11 = fVar4 / fVar5;
    if (DAT_0099d080 <= fVar4 / fVar5) {
      fVar11 = DAT_0099d080;
    }
    FUN_005ca8b0(fVar11,0x3f800000,0);
    FUN_005ca9e0(**(undefined4 **)(in_ECX + 0xf8),local_40);
    thunk_FUN_0079ee7b(auStack_8c + 3,local_40,local_c0);
    puVar9 = auStack_8c + 3;
    puVar10 = local_c0;
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
  }
  puVar9 = local_c0;
  puVar10 = (undefined4 *)(in_ECX + 0xb4);
  for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar10 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
  }
  puVar9 = local_c0;
  puVar10 = (undefined4 *)(in_ECX + 0x1d8);
  for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
    *puVar10 = *puVar9;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
  }
  *(undefined4 *)(in_ECX + 0x210) = 0;
  *(undefined4 *)(in_ECX + 0x20c) = 0;
  *(undefined4 *)(in_ECX + 0x208) = 0;
  fStack_d0 = *(float *)(in_ECX + 0x60);
  uStack_cc = *(undefined4 *)(in_ECX + 100);
  uStack_c8 = *(undefined4 *)(in_ECX + 0x68);
  fStack_c4 = DAT_0099d080;
  thunk_FUN_0079ebf5(&fStack_d0,&fStack_d0,local_c0);
  *(undefined4 *)(in_ECX + 0x6c) = uStack_dc;
  *(undefined4 *)(in_ECX + 0x70) = uStack_d8;
  *(undefined4 *)(in_ECX + 0x74) = uStack_d4;
  if (*(int *)(*(int *)(in_ECX + 0xf4) + 4) == 3) {
    thunk_FUN_0079f7f5(auStack_8c,uStack_9c,uStack_98,uStack_94);
    fVar4 = DAT_0099d080;
    uStack_dc = *(undefined4 *)(in_ECX + 0x60);
    uVar1 = *(undefined4 *)(in_ECX + 100);
    uVar2 = *(undefined4 *)(in_ECX + 0x68);
    puVar9 = auStack_8c;
    puVar10 = (undefined4 *)(in_ECX + 0x198);
    for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar10 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar10 = puVar10 + 1;
    }
    fStack_d0 = fVar4;
    uStack_d8 = uVar1;
    uStack_d4 = uVar2;
    thunk_FUN_0079ebf5(&uStack_dc,&uStack_dc,(undefined4 *)(in_ECX + 0x1d8));
    *(undefined4 *)(in_ECX + 0x18c) = uVar1;
    *(undefined4 *)(in_ECX + 400) = uVar2;
    *(float *)(in_ECX + 0x194) = fVar4;
  }
  return;
}


// ==== FUN_005b4940 @ 0x005b4940 ====

void FUN_005b4940(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xc);
  uVar2 = *(undefined4 *)(in_ECX + 0x70);
  uVar3 = *(undefined4 *)(in_ECX + 0x74);
  *param_1 = *(undefined4 *)(in_ECX + 0x6c);
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  return;
}


// ==== FUN_005b4980 @ 0x005b4980 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b4980(int param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  undefined4 uVar7;
  int in_ECX;
  float10 fVar8;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float fStack_8;
  float fStack_4;
  
  pfVar1 = (float *)(param_1 + 0xc);
  *pfVar1 = *(float *)(in_ECX + 0x6c);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(in_ECX + 0x70);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(in_ECX + 0x74);
  if ((((param_2 == 1) || (param_2 == 5)) || (param_2 == 7)) || (param_2 == 6)) {
    fVar8 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x28),
                                  *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x24));
    fVar4 = (float)fVar8;
    pfVar6 = (float *)FUN_0040ecc0(&local_c);
    fVar2 = pfVar6[1];
    fVar3 = pfVar6[2];
    *pfVar1 = *pfVar6 * fVar4 + *pfVar1;
    *(float *)(param_1 + 0x10) = fVar2 * fVar4 + *(float *)(param_1 + 0x10);
    *(float *)(param_1 + 0x14) = fVar3 * fVar4 + *(float *)(param_1 + 0x14);
    if ((param_2 == 5) || (param_2 == 6)) {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(in_ECX + 0x70);
    }
  }
  iVar5 = *(int *)(in_ECX + 0xf4);
  fVar2 = (float)*(int *)(iVar5 + 0xc);
  if (*(int *)(iVar5 + 0xc) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  fVar3 = (float)*(int *)(iVar5 + 0x10);
  if (*(int *)(iVar5 + 0x10) < 0) {
    fVar3 = fVar3 + _DAT_0099d104;
  }
  FUN_0040d0a0(fVar3,fVar2);
  uVar7 = FUN_00802534();
  pfVar1 = (float *)(param_1 + 0xd0);
  local_18 = *pfVar1;
  *(undefined4 *)(param_1 + 0xb0) = uVar7;
  *(undefined4 *)(param_1 + 0xb4) = uVar7;
  local_14 = *(float *)(param_1 + 0xd4);
  local_10 = *(float *)(param_1 + 0xd8);
  if (((param_2 == 2) || (param_2 == 7)) || (param_2 == 6)) {
    pfVar6 = (float *)FUN_0040ecc0(&local_c);
    local_18 = *pfVar6 + local_18;
    local_14 = pfVar6[1] + local_14;
    local_10 = pfVar6[2] + local_10;
  }
  if (_DAT_009c1e48 < local_10 * local_10 + local_14 * local_14 + local_18 * local_18) {
    thunk_FUN_0079e1ba(&local_18,&local_18);
  }
  if (((*(float *)(in_ECX + 0x174) == 0.0) && (*(float *)(in_ECX + 0x178) == 0.0)) &&
     (*(float *)(in_ECX + 0x17c) == 0.0)) {
    if (*(char *)(*(int *)(in_ECX + 0xf4) + 10) == '\0') {
      thunk_FUN_0079e6b3(pfVar1,&local_18,in_ECX + 0xb4);
      fStack_4 = *(float *)(in_ECX + 0x170);
      local_c = *pfVar1 * fStack_4;
      fStack_8 = *(float *)(param_1 + 0xd4) * fStack_4;
      fStack_4 = *(float *)(param_1 + 0xd8) * fStack_4;
    }
    else {
      fStack_4 = *(float *)(in_ECX + 0x170);
      local_c = fStack_4 * local_18;
      fStack_8 = local_14 * fStack_4;
      fStack_4 = local_10 * fStack_4;
    }
  }
  else {
    fStack_4 = *(float *)(in_ECX + 0x170);
    local_c = *(float *)(in_ECX + 0x174) * fStack_4;
    fStack_8 = *(float *)(in_ECX + 0x178) * fStack_4;
    fStack_4 = *(float *)(in_ECX + 0x17c) * fStack_4;
  }
  *pfVar1 = local_c;
  *(float *)(param_1 + 0xd4) = fStack_8;
  *(float *)(param_1 + 0xd8) = fStack_4;
  fVar8 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x30),
                                *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x2c));
  *(float *)(param_1 + 0xcc) = (float)fVar8;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  return;
}


// ==== FUN_005b4ca0 @ 0x005b4ca0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b4ca0(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float *pfVar4;
  undefined4 uVar5;
  int in_ECX;
  float unaff_EBP;
  float10 fVar6;
  undefined4 local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  *(float *)(param_1 + 0xc) = *(float *)(in_ECX + 0x6c);
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(in_ECX + 0x70);
  *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(in_ECX + 0x74);
  fVar6 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x28),
                                *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x24));
  fVar2 = (float)fVar6;
  *(float *)(param_1 + 0xbc) = (float)fVar6;
  pfVar4 = (float *)FUN_0040ecc0(&local_c);
  fVar1 = pfVar4[2];
  local_c = *(float *)(in_ECX + 0x6c) + *pfVar4 * fVar2;
  local_8 = *(float *)(in_ECX + 0x70) + pfVar4[1] * fVar2;
  local_4 = *(float *)(in_ECX + 0x74);
  *(float *)(param_1 + 0xc) = local_c;
  *(float *)(param_1 + 0x10) = local_8;
  local_4 = local_4 + fVar1 * fVar2;
  *(float *)(param_1 + 0x14) = local_4;
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(in_ECX + 0x70);
  iVar3 = *(int *)(in_ECX + 0xf4);
  fVar1 = (float)*(int *)(iVar3 + 0xc);
  if (*(int *)(iVar3 + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar2 = (float)*(int *)(iVar3 + 0x10);
  if (*(int *)(iVar3 + 0x10) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  FUN_0040d0a0(fVar2,fVar1);
  uVar5 = FUN_00802534();
  *(undefined4 *)(param_1 + 0xb0) = uVar5;
  *(undefined4 *)(param_1 + 0xb4) = uVar5;
  pfVar4 = (float *)FUN_0040ecc0(&local_c);
  local_14 = *(float *)(param_1 + 0xd4) + pfVar4[1];
  local_10 = *(float *)(param_1 + 0xd8) + pfVar4[2];
  local_18 = *pfVar4 + *(float *)(param_1 + 0xd0);
  pfVar4 = (float *)(param_1 + 0xd0);
  if (_DAT_009c1e48 < local_14 * local_14 + local_10 * local_10 + local_18 * local_18) {
    thunk_FUN_0079e1ba(&local_18,&local_18);
  }
  thunk_FUN_0079e1ba(&local_18,&local_18);
  local_c = local_18;
  local_10 = 0.0;
  if (((*(float *)(in_ECX + 0x174) == 0.0) && (*(float *)(in_ECX + 0x178) == 0.0)) &&
     (*(float *)(in_ECX + 0x17c) == 0.0)) {
    if (*(char *)(*(int *)(in_ECX + 0xf4) + 10) == '\0') {
      thunk_FUN_0079e6b3(pfVar4,(int)register0x00000010 + -0x20,in_ECX + 0xb4);
      local_c = *(float *)(in_ECX + 0x170);
      local_14 = *pfVar4 * local_c;
      local_10 = *(float *)(param_1 + 0xd4) * local_c;
      local_c = *(float *)(param_1 + 0xd8) * local_c;
    }
    else {
      local_c = *(float *)(in_ECX + 0x170);
      local_14 = local_c * unaff_EBP;
      local_10 = local_c * 0.0;
      local_c = local_c * local_18;
    }
  }
  else {
    local_c = *(float *)(in_ECX + 0x170);
    local_14 = local_c * *(float *)(in_ECX + 0x174);
    local_10 = *(float *)(in_ECX + 0x178) * local_c;
    local_c = *(float *)(in_ECX + 0x17c) * local_c;
  }
  *pfVar4 = local_14;
  *(float *)(param_1 + 0xd4) = local_10;
  *(float *)(param_1 + 0xd8) = local_c;
  fVar6 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x30),
                                *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x2c));
  *(float *)(param_1 + 0xcc) = (float)fVar6;
  *(undefined4 *)(param_1 + 0xdc) = 0;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined4 *)(param_1 + 0xe4) = 0;
  return;
}


// ==== FUN_005b4fe0 @ 0x005b4fe0 ====

void FUN_005b4fe0(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x100) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x100));
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x118);
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 0x118) + 4) = *(int *)(in_ECX + 0x118);
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  if (pvVar2 != *(void **)(in_ECX + 0x118)) {
    _free(pvVar2);
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x10c);
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 0x10c) + 4) = *(int *)(in_ECX + 0x10c);
  *(undefined4 *)(in_ECX + 0x110) = 0;
  if (pvVar2 == *(void **)(in_ECX + 0x10c)) {
    return;
  }
  _free(pvVar2);
  return;
}


// ==== FUN_005b5080 @ 0x005b5080 ====

void FUN_005b5080(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1e54;
  if ((undefined4 *)in_ECX[0x41] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x41])(1);
    in_ECX[0x41] = 0;
  }
  FUN_005b4fe0();
  FUN_005caa70();
  FUN_008984a0();
  FUN_008984a0();
  *in_ECX = &PTR_FUN_009c1afc;
  return;
}


// ==== FUN_005b50e0 @ 0x005b50e0 ====

void FUN_005b50e0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1e54;
  in_ECX[0x1f] = 0;
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  uVar1 = FUN_005b6400();
  in_ECX[0x43] = uVar1;
  in_ECX[0x44] = 0;
  uVar1 = FUN_005b6400();
  in_ECX[0x46] = uVar1;
  in_ECX[0x47] = 0;
  FUN_005caa30();
  in_ECX[0x5d] = 0;
  in_ECX[0x5e] = 0;
  in_ECX[0x58] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x17] = 0;
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  in_ECX[0x5f] = 0;
  *(undefined1 *)(in_ECX + 0x86) = 0;
  return;
}


// ==== FUN_005b51a0 @ 0x005b51a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b51a0(undefined4 *param_1)

{
  float *pfVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  char cVar4;
  float *pfVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float10 fVar10;
  float fVar11;
  float fVar12;
  undefined1 auStack_5e [2];
  float local_5c;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  undefined4 auStack_40 [16];
  
  puVar3 = param_1;
  fVar12 = DAT_0099d080;
  pfVar1 = (float *)(param_1 + 9);
  param_1[0xd] = 0;
  param_1[0xc] = 0;
  *pfVar1 = fVar12;
  param_1[10] = fVar12;
  param_1[0x11] = 0;
  param_1[0xf] = 0;
  param_1[0xb] = fVar12;
  param_1[0xe] = *(undefined4 *)(in_ECX + 0x98);
  *(undefined1 *)(param_1 + 0x12) = 0;
  *(undefined1 *)(param_1 + 0x2b) = 0;
  iVar7 = *(int *)(in_ECX + 0xf4);
  param_1[0x34] = *(undefined4 *)(iVar7 + 0x40);
  param_1[0x35] = *(undefined4 *)(iVar7 + 0x44);
  param_1[0x36] = *(undefined4 *)(iVar7 + 0x48);
  local_5c = 0.0;
  param_1[6] = 0;
  local_58 = 0.0;
  param_1[7] = 0;
  local_54 = 0.0;
  param_1[8] = 0;
  if ((0.0 < *(float *)(*(int *)(in_ECX + 0xf4) + 0x3c)) ||
     (0.0 < *(float *)(*(int *)(in_ECX + 0xf4) + 0x38))) {
    fVar10 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x3c),
                                   *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x38));
    param_1[0xe] = (float)fVar10;
    fVar12 = DAT_0099d080;
  }
  if (*(float *)(*(int *)(in_ECX + 0xf4) + 0x1c) != 0.0) {
    fVar10 = (float10)FUN_0040d0a0(0,*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x1c));
    param_1[0xc] = (float)fVar10;
    fVar12 = DAT_0099d080;
  }
  param_1 = (undefined4 *)fVar12;
  local_5c = fVar12;
  local_58 = fVar12;
  local_54 = fVar12;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x58) != 0) {
    fVar10 = (float10)FUN_005aa2a0(0,0);
    param_1 = (undefined4 *)(float)fVar10;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0x90) != 0) {
    pfVar5 = (float *)FUN_005aa3a0(&local_50,0,0);
    local_5c = *pfVar5;
    local_58 = pfVar5[1];
    local_54 = pfVar5[2];
  }
  iVar7 = *(int *)(in_ECX + 0xf4);
  if (*(float *)(iVar7 + 0x20) <= 0.0) goto LAB_005b53da;
  fVar10 = (float10)FUN_0040d0a0(0.0 - *(float *)(iVar7 + 0x20),*(undefined4 *)(iVar7 + 0x20));
  fVar12 = (float)fVar10;
  fVar11 = local_5c + fVar12;
  if (fVar11 < DAT_0099d080) {
    local_5c = 0.0;
    if (0.0 <= fVar11) goto LAB_005b538c;
  }
  else {
    fVar11 = DAT_0099d080;
LAB_005b538c:
    local_5c = fVar11;
  }
  fVar11 = local_58 + fVar12;
  if (fVar11 < DAT_0099d080) {
    local_58 = 0.0;
    if (0.0 <= fVar11) goto LAB_005b53b1;
  }
  else {
    fVar11 = DAT_0099d080;
LAB_005b53b1:
    local_58 = fVar11;
  }
  fVar12 = local_54 + fVar12;
  fVar11 = DAT_0099d080;
  if ((DAT_0099d080 <= fVar12) || (local_54 = 0.0, fVar11 = fVar12, 0.0 <= fVar12)) {
    local_54 = fVar11;
  }
LAB_005b53da:
  local_50 = local_5c;
  local_4c = local_58;
  local_48 = local_54;
  local_44 = (float)param_1;
  uVar6 = FUN_0040ead0(&local_50);
  puVar3[0x10] = uVar6;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x70) != 0) {
    pfVar5 = (float *)FUN_005aa3a0(&local_50,0,0);
    *pfVar1 = *pfVar5;
    puVar3[10] = pfVar5[1];
    puVar3[0xb] = pfVar5[2];
  }
  uVar6 = *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 4);
  switch(uVar6) {
  case 1:
  case 2:
  case 5:
  case 6:
  case 7:
    FUN_005b4980(puVar3,uVar6);
    break;
  case 3:
    FUN_005b40f0(puVar3);
    break;
  case 4:
    FUN_005b4ca0(puVar3);
  }
  iVar7 = *(int *)(in_ECX + 0xf4);
  if (*(char *)(iVar7 + 9) != '\0') {
    local_54 = (float)puVar3[5] - *(float *)(iVar7 + 0x60);
    local_58 = (float)puVar3[4] - *(float *)(iVar7 + 0x5c);
    local_5c = (float)puVar3[3] - *(float *)(iVar7 + 0x58);
    thunk_FUN_0079e1ba(&local_5c,&local_5c);
    FUN_0040d620(&local_58,auStack_5e + -6);
    thunk_FUN_0079fb96(&local_48,&local_58);
    uVar6 = puVar3[3];
    uVar2 = puVar3[4];
    puVar8 = auStack_40;
    puVar9 = puVar3 + 0x13;
    for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
      *puVar9 = *puVar8;
      puVar8 = puVar8 + 1;
      puVar9 = puVar9 + 1;
    }
    *puVar3 = uVar6;
    puVar3[1] = uVar2;
    puVar3[2] = puVar3[5];
  }
  iVar7 = (**(code **)(**(int **)(in_ECX + 0x104) + 0xc))();
  fVar12 = (float)iVar7;
  if (iVar7 < 0) {
    fVar12 = fVar12 + _DAT_0099d104;
  }
  if ((**(int **)(in_ECX + 0xf4) == 0) && (DAT_0099d080 < fVar12)) {
    if (*(int *)(in_ECX + 0x90) != 0) {
      cVar4 = '\0';
      if (*(int *)(in_ECX + 0x84) != 0) {
        cVar4 = (*(int *)(in_ECX + 0x84) != 1) + '\x01';
      }
      FUN_0081d860(cVar4,0,fVar12,*(int *)(in_ECX + 0x90));
      return;
    }
    fVar10 = (float10)FUN_0040d0a0(0,fVar12);
    puVar3[0x11] = (int)ROUND(fVar10);
  }
  return;
}


// ==== FUN_005b55e0 @ 0x005b55e0 ====

void FUN_005b55e0(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int in_ECX;
  float10 fVar2;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  float local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  FUN_0040ec60(&local_10,*(undefined4 *)(param_3 + 0x40));
  if (*(int *)(*(int *)(in_ECX + 8) + 0x58) != 0) {
    fVar2 = (float10)FUN_005aa2a0(param_1,param_2);
    local_4 = (float)fVar2;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0x90) != 0) {
    FUN_005aa3a0(&local_2c,param_1,param_2);
    local_20 = local_2c;
    local_1c = local_28;
    local_18 = local_24;
    local_14 = local_4;
    local_10 = local_2c;
    local_c = local_28;
    local_8 = local_24;
  }
  uVar1 = FUN_0040ead0(&local_10);
  *(undefined4 *)(param_3 + 0x40) = uVar1;
  return;
}


// ==== FUN_005b56f0 @ 0x005b56f0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b56f0(int *param_1,float *param_2)

{
  code *pcVar1;
  float fVar2;
  float *pfVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  int iVar5;
  float *pfVar6;
  float fVar7;
  float fVar8;
  int in_ECX;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  float *pfVar12;
  float fVar13;
  float local_6c;
  float local_68;
  float local_64;
  float local_60;
  undefined1 local_5c [4];
  void *local_58;
  float *local_48;
  uint local_44;
  undefined4 local_40 [12];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  pfVar3 = param_2;
  if (param_2 == (float *)0x0) {
    local_44 = 0xf;
    local_48 = param_2;
    local_58 = (void *)((uint)local_58 & 0xffffff00);
    FUN_00401740(s_i_pElement____NULL_009c1dec,0x12);
    FUN_00406880(local_5c);
    if (local_44 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    _free(local_58);
    return extraout_EAX;
  }
  fVar7 = param_2[0x2d];
  if (fVar7 == 0.0) {
    return 0;
  }
  fVar8 = param_2[0x2c];
  fVar13 = (float)(int)fVar7;
  if ((int)fVar7 < 0) {
    fVar13 = fVar13 + _DAT_0099d104;
  }
  fVar2 = (float)(int)fVar8;
  if ((int)fVar8 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  fVar13 = DAT_0099d080 - fVar13 / fVar2;
  if (DAT_0099d080 <= fVar13) {
    fVar13 = DAT_0099d080;
  }
  else {
    param_2 = (float *)0x0;
    if (fVar13 < 0.0) goto LAB_005b57b6;
  }
  param_2 = (float *)fVar13;
LAB_005b57b6:
  iVar5 = (int)fVar8 - (int)fVar7;
  local_6c = (float)*param_1;
  iVar9 = (int)((float)param_2 * DAT_009bf5a0);
  if (*param_1 < 0) {
    local_6c = local_6c + _DAT_0099d104;
  }
  local_6c = local_6c * DAT_0099d0ec;
  FUN_005b4250(param_1,pfVar3);
  FUN_005b55e0(iVar9,iVar5,pfVar3);
  if (*(int *)(*(int *)(in_ECX + 8) + 0x70) != 0) {
    pfVar6 = (float *)FUN_005aa3a0(&local_68,iVar9,iVar5);
    pfVar3[9] = *pfVar6;
    pfVar3[10] = pfVar6[1];
    pfVar3[0xb] = pfVar6[2];
  }
  fVar7 = *(float *)(*(int *)(in_ECX + 0xf4) + 0x1c);
  if (fVar7 != DAT_0099cdc8) {
    pfVar3[0xc] = fVar7 * (float)param_2;
  }
  switch(*(int *)(*(int *)(in_ECX + 0xf4) + 4) + -1) {
  case 0:
  case 1:
  case 4:
  case 5:
  case 6:
    FUN_005b42e0(&local_6c,pfVar3);
    break;
  case 2:
    FUN_005b4430(&param_2,pfVar3);
    break;
  case 3:
    FUN_005b42e0(&local_6c,pfVar3);
    pfVar3[4] = *(float *)(in_ECX + 0x70);
    break;
  default:
    return 0;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0xb0) != 0) {
    if (*(char *)(in_ECX + 0x8c) == '\0') {
      FUN_005aa3a0(&local_68,iVar9,iVar5);
      puVar10 = (undefined4 *)(in_ECX + 0xb4);
      puVar11 = local_40;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
      }
      local_8 = 0;
      local_c = 0;
      local_10 = 0;
      thunk_FUN_0079e5a0(pfVar3 + 6,&local_68,local_40);
    }
    else {
      pfVar6 = (float *)FUN_005aa3a0(&local_68,iVar9,iVar5);
      pfVar3[6] = *pfVar6;
      pfVar3[7] = pfVar6[1];
      pfVar3[8] = pfVar6[2];
    }
  }
  if (*(char *)(*(int *)(in_ECX + 0xf4) + 9) != '\0') {
    local_68 = pfVar3[3] - *pfVar3;
    local_64 = pfVar3[4] - pfVar3[1];
    local_60 = pfVar3[5] - pfVar3[2];
    if (DAT_009a09b8 < SQRT(local_68 * local_68 + local_64 * local_64 + local_60 * local_60)) {
      thunk_FUN_0079e1ba(&local_68,&local_68);
      FUN_0040d620(local_5c,&local_68);
      pfVar6 = (float *)FUN_005acde0(local_40,local_5c);
      fVar7 = pfVar3[3];
      pfVar12 = pfVar3 + 0x13;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *pfVar12 = *pfVar6;
        pfVar6 = pfVar6 + 1;
        pfVar12 = pfVar12 + 1;
      }
      *pfVar3 = fVar7;
      pfVar3[1] = pfVar3[4];
      pfVar3[2] = pfVar3[5];
    }
  }
  fVar7 = (float)(**(code **)(**(int **)(in_ECX + 0x104) + 0xc))();
  if (((**(int **)(in_ECX + 0xf4) == 0) && (1 < (uint)fVar7)) && (*(int *)(in_ECX + 0x90) != 0)) {
    FUN_0081d6b0(*param_1);
    fVar8 = (float)FUN_00802534();
    pfVar3[0x11] = fVar8;
    if ((uint)fVar7 <= (uint)fVar8) {
      pfVar3[0x11] = (float)((int)fVar7 + -1);
    }
  }
  if (*(int *)(*(int *)(in_ECX + 0xf4) + 4) == 3) {
    if (((*(float *)(in_ECX + 0x174) == 0.0) && (*(float *)(in_ECX + 0x178) == 0.0)) &&
       (*(float *)(in_ECX + 0x17c) == 0.0)) {
      return 1;
    }
    FUN_0040d620(local_5c,in_ECX + 0x174);
    FUN_005acde0(local_40,local_5c);
    thunk_FUN_0079e5a0(pfVar3 + 3,pfVar3 + 3,local_40);
  }
  return 1;
}


// ==== FUN_005b5ad0 @ 0x005b5ad0 ====

void FUN_005b5ad0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int local_4;
  
  FUN_005b4fe0();
  uVar2 = FUN_005b6530(param_1);
  *(undefined4 *)(in_ECX + 0x100) = uVar2;
  if (param_1 != 0) {
    iVar4 = 0;
    do {
      iVar1 = *(int *)(in_ECX + 0x10c);
      local_4 = *(int *)(in_ECX + 0x100) + iVar4;
      iVar3 = FUN_005b6490(iVar1,*(undefined4 *)(iVar1 + 4),&local_4);
      FUN_00517200(1);
      *(int *)(iVar1 + 4) = iVar3;
      iVar4 = iVar4 + 0x128;
      param_1 = param_1 + -1;
      **(int **)(iVar3 + 4) = iVar3;
    } while (param_1 != 0);
  }
  return;
}


// ==== __break @ 0x005b5b5b ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_005b5b60 @ 0x005b5b60 ====

void FUN_005b5b60(void)

{
  int iVar1;
  undefined4 *puVar2;
  void *_Memory;
  int iVar3;
  int in_ECX;
  int *piVar4;
  int local_c;
  int *local_8;
  int local_4;
  
  if (*(int *)(in_ECX + 0x11c) != 0) {
    local_8 = *(int **)(in_ECX + 0x118);
    piVar4 = (int *)*local_8;
    local_4 = in_ECX;
    if (piVar4 != local_8) {
      do {
        iVar1 = *(int *)(in_ECX + 0x10c);
        local_c = piVar4[2];
        iVar3 = FUN_005b6490(iVar1,*(undefined4 *)(iVar1 + 4),&local_c);
        FUN_00517200(1);
        *(int *)(iVar1 + 4) = iVar3;
        **(int **)(iVar3 + 4) = iVar3;
        piVar4 = (int *)*piVar4;
      } while (piVar4 != local_8);
      in_ECX = local_4;
    }
    puVar2 = *(undefined4 **)(in_ECX + 0x118);
    _Memory = (void *)*puVar2;
    *puVar2 = puVar2;
    *(int *)(*(int *)(in_ECX + 0x118) + 4) = *(int *)(in_ECX + 0x118);
    *(undefined4 *)(in_ECX + 0x11c) = 0;
    if (_Memory != *(void **)(in_ECX + 0x118)) {
      _free(_Memory);
      return;
    }
  }
  return;
}


// ==== FUN_005b5c10 @ 0x005b5c10 ====

void FUN_005b5c10(int param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int in_ECX;
  int *local_2c;
  int local_28;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  piVar1 = *(int **)(in_ECX + 0x10c);
  local_28 = 0;
  local_2c = (int *)*piVar1;
  if (0 < param_1) {
    do {
      if (local_2c == piVar1) {
        return;
      }
      local_20 = local_2c[2];
      if (local_20 == 0) {
        local_4 = 0xf;
        local_8 = 0;
        local_18 = (void *)((uint)local_18 & 0xffffff00);
        FUN_00401740(s_pElement____NULL_009c1dd8,0x10);
        FUN_00406880(local_1c);
        if (local_4 < 0x10) {
          local_4 = 0xf;
          local_8 = 0;
          local_18 = (void *)((uint)local_18 & 0xffffff00);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        _free(local_18);
        return;
      }
      FUN_005b51a0(local_20);
      iVar2 = *(int *)(in_ECX + 0x118);
      iVar4 = FUN_005b6490(iVar2,*(undefined4 *)(iVar2 + 4),&local_20);
      FUN_00517200(1);
      *(int *)(iVar2 + 4) = iVar4;
      **(int **)(iVar4 + 4) = iVar4;
      if (local_2c != *(int **)(in_ECX + 0x10c)) {
        *(int *)local_2c[1] = *local_2c;
        *(int *)(*local_2c + 4) = local_2c[1];
        _free(local_2c);
        return;
      }
      local_28 = local_28 + 1;
      local_2c = (int *)*local_2c;
    } while (local_28 < param_1);
  }
  return;
}


// ==== FUN_005b5d40 @ 0x005b5d40 ====

void FUN_005b5d40(int param_1,undefined4 param_2)

{
  code *pcVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  int local_8;
  uint local_4;
  
  local_8 = 0;
  if (**(int **)(param_1 + 0x24) == 0) {
    pvVar2 = operator_new(0x24);
    if (pvVar2 != (void *)0x0) {
      local_8 = FUN_005cb190();
      goto LAB_005b5d8b;
    }
  }
  else {
    if (**(int **)(param_1 + 0x24) != 1) goto LAB_005b5d8b;
    pvVar2 = operator_new(100);
    if (pvVar2 != (void *)0x0) {
      local_8 = FUN_005cb6a0();
      goto LAB_005b5d8b;
    }
  }
  local_8 = 0;
LAB_005b5d8b:
  *(int *)(in_ECX + 0x104) = local_8;
  if (local_8 != 0) {
    FUN_005b4570(param_1);
    *(undefined4 *)(in_ECX + 4) = param_2;
    FUN_005b5ad0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x18));
    return;
  }
  local_4 = 0xf;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_m_pRenderElement____NULL_009c1da8,0x18);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005b5e00 @ 0x005b5e00 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b5e00(int param_1,float param_2,int param_3)

{
  int iVar1;
  float fVar2;
  int *in_ECX;
  float10 fVar3;
  
  *(undefined1 *)(in_ECX + 0x86) = 1;
  FUN_005b5b60();
  iVar1 = DAT_0099d080;
  in_ECX[0x84] = 0;
  in_ECX[0x83] = 0;
  in_ECX[0x82] = 0;
  in_ECX[0x81] = 0;
  in_ECX[0x7f] = 0;
  in_ECX[0x7e] = 0;
  in_ECX[0x7d] = 0;
  in_ECX[0x7c] = 0;
  in_ECX[0x7a] = 0;
  in_ECX[0x79] = 0;
  in_ECX[0x78] = 0;
  in_ECX[0x77] = 0;
  in_ECX[0x85] = iVar1;
  in_ECX[0x80] = iVar1;
  in_ECX[0x7b] = iVar1;
  in_ECX[0x76] = iVar1;
  in_ECX[2] = param_1;
  in_ECX[0x15] = *(int *)(param_1 + 8);
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  in_ECX[0x18] = *(int *)(param_1 + 0x18);
  in_ECX[0x19] = *(int *)(param_1 + 0x1c);
  in_ECX[0x1a] = *(int *)(param_1 + 0x20);
  fVar2 = (float)*(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xc) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  in_ECX[0x16] = (int)ROUND(fVar2 * param_2);
  fVar2 = (float)*(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x10) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  in_ECX[0x25] = (int)ROUND(fVar2 * param_2);
  in_ECX[99] = 0;
  in_ECX[100] = 0;
  in_ECX[0x65] = 0;
  *(undefined1 *)(in_ECX + 0x23) = *(undefined1 *)(param_1 + 0x31);
  if (*(char *)(param_1 + 0x32) != '\0') {
    fVar2 = (float)in_ECX[0x16];
    if (in_ECX[0x16] < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar3 = (float10)FUN_0040d0a0(0,fVar2 * DAT_0099d0ec);
    in_ECX[0x16] = (int)ROUND(fVar3 * (float10)DAT_009b012c);
  }
  param_2 = param_2 * DAT_009b012c;
  in_ECX[0x17] = param_3;
  in_ECX[0x5b] = (int)ROUND(param_2);
  in_ECX[0x59] = in_ECX[0x25] - in_ECX[0x16];
  in_ECX[0x5a] = in_ECX[0x25] - in_ECX[0x16];
  in_ECX[0x5d] = 0;
  in_ECX[0x5e] = 0;
  in_ECX[0x5f] = 0;
  if (0 < *(int *)(in_ECX[0x3d] + 0x14)) {
    in_ECX[0x1f] = *(int *)(in_ECX[0x3d] + 0x14);
  }
  iVar1 = *(int *)(in_ECX[2] + 0x34);
  in_ECX[0x3e] = iVar1;
  if ((*(int *)(iVar1 + 0x18) != 0) && (*(int *)(iVar1 + 0x34) != 0)) {
    FUN_005ca850(iVar1 + 4);
    FUN_005caad0();
    FUN_005cab40(in_ECX[0x3e] + 0x20);
  }
  (**(code **)(*in_ECX + 0x44))();
  return;
}


// ==== FUN_005b60a0 @ 0x005b60a0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b60a0(uint *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  float fVar6;
  int in_ECX;
  uint uVar7;
  float10 fVar8;
  float fVar9;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  uVar2 = *(uint *)(*(int *)(in_ECX + 0xf4) + 0x14);
  if (uVar2 != 0) {
    if ((int)uVar2 < 0) {
      uVar7 = -uVar2;
    }
    else {
      *(int *)(in_ECX + 0x7c) = *(int *)(in_ECX + 0x7c) + *param_1;
      uVar3 = *(uint *)(in_ECX + 0x7c);
      if (uVar3 < uVar2) {
        return;
      }
      uVar7 = uVar3 / uVar2;
      *(uint *)(in_ECX + 0x7c) = uVar3 % uVar2;
    }
    if (10 < uVar7) {
      uVar7 = 10;
    }
    if (*(int *)(in_ECX + 8) != 0) {
      if (*(int *)(*(int *)(in_ECX + 8) + 0x40) != 0) {
        if (*param_1 < *(uint *)(in_ECX + 0x168)) {
          *(uint *)(in_ECX + 0x168) = *(uint *)(in_ECX + 0x168) - *param_1;
        }
        else {
          *(undefined4 *)(in_ECX + 0x168) = 0;
        }
        iVar4 = *(int *)(in_ECX + 0x168);
        iVar5 = *(int *)(in_ECX + 0x164);
        fVar9 = (float)iVar4;
        if (iVar4 < 0) {
          fVar9 = fVar9 + _DAT_0099d104;
        }
        fVar6 = (float)iVar5;
        if (iVar5 < 0) {
          fVar6 = fVar6 + _DAT_0099d104;
        }
        fVar9 = DAT_0099d080 - fVar9 / fVar6;
        if (DAT_0099d080 <= fVar9) {
          fVar9 = DAT_0099d080;
        }
        else if (fVar9 < 0.0) {
          fVar9 = 0.0;
        }
        fVar8 = (float10)FUN_005aa2a0((int)(fVar9 * DAT_009bf5a0),iVar5 - iVar4);
        FUN_0040d600(&local_24,(float)(fVar8 * (float10)_DAT_00af4f98));
        local_1c = local_24;
        local_18 = 0;
        puVar1 = (undefined4 *)(in_ECX + 0x174);
        local_14 = local_20;
        *puVar1 = local_24;
        *(undefined4 *)(in_ECX + 0x178) = 0;
        *(undefined4 *)(in_ECX + 0x17c) = local_20;
        local_10 = *puVar1;
        local_c = *(undefined4 *)(in_ECX + 0x178);
        local_8 = *(undefined4 *)(in_ECX + 0x17c);
        local_4 = DAT_0099d080;
        thunk_FUN_0079ebf5(&local_10,&local_10,in_ECX + 0x1d8);
        local_1c = local_10;
        local_18 = local_c;
        local_14 = local_8;
        *puVar1 = local_10;
        *(undefined4 *)(in_ECX + 0x178) = local_c;
        *(undefined4 *)(in_ECX + 0x17c) = local_8;
      }
      FUN_005b5c10(uVar7);
    }
  }
  return;
}


// ==== FUN_005b6290 @ 0x005b6290 ====

uint FUN_005b6290(int param_1)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  char cVar4;
  uint extraout_EAX;
  uint uVar5;
  int iVar6;
  uint extraout_EAX_00;
  int *in_ECX;
  int *piStack_28;
  int iStack_24;
  int *piStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  int iStack_8;
  uint uStack_4;
  
  in_ECX[0x17] = in_ECX[0x17] + param_1;
  in_ECX[0x58] = param_1;
  (**(code **)(*in_ECX + 0x44))();
  if (((uint)in_ECX[0x16] < (uint)in_ECX[0x17]) && ((uint)in_ECX[0x17] < (uint)in_ECX[0x25])) {
    FUN_005b60a0(&param_1);
  }
  piStack_20 = (int *)in_ECX[0x46];
  piStack_28 = (int *)*piStack_20;
  if (piStack_28 != piStack_20) {
    do {
      iStack_24 = piStack_28[2];
      if (iStack_24 == 0) {
        uStack_4 = 0xf;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        iStack_8 = iStack_24;
        FUN_00401740(s_pElement____NULL_009c1dc4,0x10);
        FUN_00406880(auStack_1c);
        if (uStack_4 < 0x10) {
          uStack_4 = 0xf;
          iStack_8 = 0;
          pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
          pcVar2 = (code *)swi(3);
          uVar5 = (*pcVar2)();
          return uVar5;
        }
        _free(pvStack_18);
        return extraout_EAX;
      }
      cVar4 = FUN_005b56f0(&param_1,iStack_24);
      if (cVar4 == '\0') {
        iVar1 = in_ECX[0x43];
        iVar6 = FUN_005b6490(iVar1,*(undefined4 *)(iVar1 + 4),&iStack_24);
        FUN_00517200(1);
        *(int *)(iVar1 + 4) = iVar6;
        **(int **)(iVar6 + 4) = iVar6;
        piVar3 = (int *)*piStack_28;
        if (piStack_28 != (int *)in_ECX[0x46]) {
          *(int *)piStack_28[1] = *piStack_28;
          *(int *)(*piStack_28 + 4) = piStack_28[1];
          _free(piStack_28);
          return extraout_EAX_00;
        }
      }
      else {
        piVar3 = (int *)*piStack_28;
      }
      piStack_28 = piVar3;
    } while (piStack_28 != piStack_20);
  }
  if (((uint)in_ECX[0x16] < (uint)in_ECX[0x17]) && (in_ECX[0x47] == 0)) {
    *(undefined1 *)((int)in_ECX + 0x79) = 1;
  }
  return (uint)(*(char *)((int)in_ECX + 0x79) == '\0');
}


// ==== FUN_005b6400 @ 0x005b6400 ====

void FUN_005b6400(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009828a0;
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


// ==== Catch@005b646f @ 0x005b646f ====

void Catch_005b646f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005b6490 @ 0x005b6490 ====

void FUN_005b6490(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009828b0;
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


// ==== Catch@005b64f9 @ 0x005b64f9 ====

void Catch_005b64f9(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005b6510 @ 0x005b6510 ====

void FUN_005b6510(byte param_1)

{
  void *in_ECX;
  
  FUN_005b5080();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005b6530 @ 0x005b6530 ====

void FUN_005b6530(int param_1)

{
  code *pcVar1;
  void *pvVar2;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  pvVar2 = operator_new(param_1 * 0x128);
  if (pvVar2 != (void *)0x0) {
    return;
  }
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_4 = 0xf;
  FUN_00401740(&DAT_0099e358,2);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005b65a0 @ 0x005b65a0 ====

void FUN_005b65a0(int param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_2;
  iVar1 = *(int *)(param_1 + 0x10);
  *(int *)(in_ECX + 0x7c) = iVar1;
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(iVar1 + 8);
  return;
}


// ==== FUN_005b65c0 @ 0x005b65c0 ====

void FUN_005b65c0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x79) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined1 *)(in_ECX + 0x8c) = 0;
  return;
}


// ==== FUN_005b65d0 @ 0x005b65d0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b65d0(int param_1,float param_2,int param_3)

{
  float fVar1;
  int *in_ECX;
  float10 fVar2;
  
  in_ECX[2] = param_1;
  in_ECX[0x15] = *(int *)(param_1 + 8);
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  in_ECX[0x18] = *(int *)(param_1 + 0x18);
  in_ECX[0x19] = *(int *)(param_1 + 0x1c);
  in_ECX[0x1a] = *(int *)(param_1 + 0x20);
  fVar1 = (float)*(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[0x16] = (int)ROUND(fVar1 * param_2);
  fVar1 = (float)*(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x10) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  in_ECX[0x24] = (int)ROUND(fVar1 * param_2);
  if (*(char *)(param_1 + 0x32) != '\0') {
    fVar1 = (float)in_ECX[0x16];
    if (in_ECX[0x16] < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar2 = (float10)FUN_0040d0a0(0,fVar1 * DAT_0099d0ec);
    in_ECX[0x16] = (int)ROUND(fVar2 * (float10)DAT_009b012c);
  }
  in_ECX[0x17] = param_3;
  *(undefined1 *)(in_ECX + 0x23) = 0;
  (**(code **)(*in_ECX + 0x44))();
  return;
}


// ==== FUN_005b66e0 @ 0x005b66e0 ====

bool FUN_005b66e0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined1 local_10 [16];
  
  uVar1 = (**(code **)(*in_ECX + 0x40))(local_10,param_1);
  iVar2 = FUN_0040d570(uVar1);
  return iVar2 != 1;
}


// ==== FUN_005b6710 @ 0x005b6710 ====

void FUN_005b6710(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1ecc;
  *(undefined1 *)(in_ECX + 0x23) = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x17] = 0;
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  return;
}


// ==== FUN_005b6730 @ 0x005b6730 ====

void FUN_005b6730(void)

{
  int in_ECX;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  FUN_005ba1f0(local_40,*(undefined4 *)(in_ECX + 0x54));
  local_50 = *(undefined4 *)(in_ECX + 0x60);
  local_4c = *(undefined4 *)(in_ECX + 100);
  local_48 = *(undefined4 *)(in_ECX + 0x68);
  local_44 = DAT_0099d080;
  thunk_FUN_0079ebf5(&local_50,&local_50,local_40);
  *(undefined4 *)(in_ECX + 0x6c) = uStack_5c;
  *(undefined4 *)(in_ECX + 0x70) = uStack_58;
  *(undefined4 *)(in_ECX + 0x74) = uStack_54;
  return;
}


// ==== FUN_005b67d0 @ 0x005b67d0 ====

void FUN_005b67d0(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xc);
  uVar2 = *(undefined4 *)(in_ECX + 0x70);
  uVar3 = *(undefined4 *)(in_ECX + 0x74);
  *param_1 = *(undefined4 *)(in_ECX + 0x6c);
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  return;
}


// ==== FUN_005b6810 @ 0x005b6810 ====

void FUN_005b6810(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *in_ECX;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  
  if (in_ECX[1] == 0) {
    return;
  }
  if (param_1 == 0) {
    puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar3 == (undefined4 *)0x0) {
      return;
    }
    uVar4 = (**(code **)(*(int *)(in_ECX[1] + 0x20) + 0xc))();
    puVar3[1] = uVar4;
    *puVar3 = &PTR_FUN_009c1eb4;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    (**(code **)(*in_ECX + 0x44))();
    iVar5 = in_ECX[0x24] - in_ECX[0x16];
    in_ECX[0x20] = in_ECX[0x1b];
    in_ECX[0x21] = in_ECX[0x1c];
    in_ECX[0x22] = in_ECX[0x1d];
    iVar1 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar1 == 0) {
      return;
    }
    uVar4 = *(undefined4 *)(in_ECX[0x1f] + 8);
    uVar8 = *(undefined4 *)(in_ECX[0x1f] + 4);
    iVar1 = in_ECX[0x1b];
    iVar6 = in_ECX[0x1c];
    iVar7 = in_ECX[0x1d];
    uVar2 = (**(code **)(*(int *)(in_ECX[1] + 0x20) + 0xc))(iVar1,iVar6,iVar7,iVar5,uVar8,uVar4);
    puVar3 = (undefined4 *)FUN_005b6a20(uVar2,iVar1,iVar6,iVar7,iVar5,uVar8,uVar4);
  }
  if (puVar3 != (undefined4 *)0x0) {
    FUN_00797a20(puVar3);
  }
  return;
}


// ==== FUN_005b68e0 @ 0x005b68e0 ====

uint FUN_005b68e0(int param_1)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int in_ECX;
  
  *(int *)(in_ECX + 0x5c) = *(int *)(in_ECX + 0x5c) + param_1;
  uVar1 = *(uint *)(in_ECX + 0x5c);
  if (uVar1 < *(uint *)(in_ECX + 0x58)) {
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  if (*(uint *)(in_ECX + 0x90) <= uVar1) {
    FUN_005b6810(0);
    *(undefined1 *)(in_ECX + 0x79) = 1;
  }
  if (*(char *)(in_ECX + 0x8c) == '\0') {
    FUN_005b6810(1);
    *(undefined1 *)(in_ECX + 0x8c) = 1;
    return (uint)(*(char *)(in_ECX + 0x79) == '\0');
  }
  fVar2 = *(float *)(in_ECX + 0x6c) - *(float *)(in_ECX + 0x80);
  fVar3 = *(float *)(in_ECX + 0x70) - *(float *)(in_ECX + 0x84);
  fVar4 = *(float *)(in_ECX + 0x74) - *(float *)(in_ECX + 0x88);
  if (DAT_009a000c < SQRT(fVar3 * fVar3 + fVar2 * fVar2 + fVar4 * fVar4)) {
    FUN_005b6810(1);
  }
  return (uint)(*(char *)(in_ECX + 0x79) == '\0');
}


// ==== FUN_005b6990 @ 0x005b6990 ====

void FUN_005b6990(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) != 0) &&
     (puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))(), puVar1 != (undefined4 *)0x0)) {
    uVar2 = (**(code **)(*(int *)(*(int *)(in_ECX + 4) + 0x20) + 0xc))();
    *puVar1 = &PTR_FUN_009c1eb4;
    puVar1[1] = uVar2;
    FUN_00797a20(puVar1);
  }
  *(undefined1 *)(in_ECX + 0x79) = 1;
  return;
}


// ==== FUN_005b6a20 @ 0x005b6a20 ====

void FUN_005b6a20(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_1;
  in_ECX[2] = param_2;
  in_ECX[3] = param_3;
  in_ECX[4] = param_4;
  in_ECX[6] = param_6;
  *in_ECX = &PTR_FUN_009c1ea0;
  in_ECX[5] = param_5;
  in_ECX[7] = param_7;
  return;
}


// ==== FUN_005b6a70 @ 0x005b6a70 ====

undefined4 FUN_005b6a70(void)

{
  return 0x60030010;
}


// ==== FUN_005b6a80 @ 0x005b6a80 ====

undefined4 FUN_005b6a80(void)

{
  return 0x60030011;
}


// ==== FUN_005b6a90 @ 0x005b6a90 ====

void FUN_005b6a90(byte param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1ecc;
  if ((in_ECX[1] != 0) &&
     (puVar1 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))(), puVar1 != (undefined4 *)0x0)) {
    uVar2 = (**(code **)(*(int *)(in_ECX[1] + 0x20) + 0xc))();
    *puVar1 = &PTR_FUN_009c1eb4;
    puVar1[1] = uVar2;
    FUN_00797a20(puVar1);
  }
  *in_ECX = &PTR_FUN_009c1afc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005b6af0 @ 0x005b6af0 ====

void FUN_005b6af0(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(int *)(in_ECX + 4) = param_2;
  uVar2 = (**(code **)(*(int *)(param_2 + 0x20) + 0xc))();
  *(undefined4 *)(in_ECX + 0x98) = uVar2;
  iVar1 = *(int *)(param_1 + 0x28);
  *(int *)(in_ECX + 0x7c) = iVar1;
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(iVar1 + 0x24);
  return;
}


// ==== FUN_005b6b20 @ 0x005b6b20 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b6b20(int param_1,undefined4 param_2,int param_3)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  in_ECX[2] = param_1;
  in_ECX[0x18] = *(int *)(param_1 + 0x18);
  in_ECX[0x19] = *(int *)(param_1 + 0x1c);
  in_ECX[0x1a] = *(int *)(param_1 + 0x20);
  in_ECX[0x15] = *(int *)(param_1 + 8);
  in_ECX[0x18] = *(int *)(param_1 + 0x18);
  in_ECX[0x19] = *(int *)(param_1 + 0x1c);
  in_ECX[0x1a] = *(int *)(param_1 + 0x20);
  iVar2 = FUN_00802534();
  in_ECX[0x16] = iVar2;
  if (*(char *)(param_1 + 0x32) != '\0') {
    fVar1 = (float)iVar2;
    if (iVar2 < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar3 = (float10)FUN_0040d0a0(0,fVar1 * DAT_0099d0ec);
    in_ECX[0x16] = (int)ROUND(fVar3 * (float10)DAT_009b012c);
  }
  iVar2 = *(int *)(in_ECX[0x1f] + 0x28) * *(int *)(in_ECX[0x1f] + 0x1c);
  in_ECX[0x25] = iVar2;
  in_ECX[0x24] = in_ECX[0x16] + iVar2;
  in_ECX[0x17] = param_3;
  in_ECX[0x20] = in_ECX[0x1b];
  in_ECX[0x21] = in_ECX[0x1c];
  in_ECX[0x22] = in_ECX[0x1d];
  *(undefined1 *)(in_ECX + 0x23) = 0;
  (**(code **)(*in_ECX + 0x44))();
  (**(code **)(*in_ECX + 0x18))(0);
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  return;
}


// ==== FUN_005b6c30 @ 0x005b6c30 ====

undefined1 FUN_005b6c30(void)

{
  return 1;
}


// ==== FUN_005b6c40 @ 0x005b6c40 ====

void FUN_005b6c40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1f1c;
  *(undefined1 *)(in_ECX + 0x23) = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x17] = 0;
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  return;
}


// ==== FUN_005b6c60 @ 0x005b6c60 ====

void FUN_005b6c60(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xc);
  uVar2 = *(undefined4 *)(in_ECX + 0x70);
  uVar3 = *(undefined4 *)(in_ECX + 0x74);
  *param_1 = *(undefined4 *)(in_ECX + 0x6c);
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  return;
}


// ==== FUN_005b6ca0 @ 0x005b6ca0 ====

void FUN_005b6ca0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 local_40 [64];
  
  piVar1 = DAT_00b5a97c;
  if (DAT_00b5a97c != (int *)0x0) {
    iVar2 = (**(code **)(*(int *)(*(int *)(in_ECX + 4) + 0x20) + 8))();
    iVar3 = (**(code **)(*piVar1 + 0xc))();
    if (iVar3 == iVar2) {
      *(undefined4 *)(in_ECX + 0x6c) = 0;
      *(undefined4 *)(in_ECX + 0x70) = 0;
      *(undefined4 *)(in_ECX + 0x74) = 0;
      return;
    }
  }
  FUN_005ba1f0(local_40,*(undefined4 *)(in_ECX + 0x54));
  uStack_50 = *(undefined4 *)(in_ECX + 0x60);
  uStack_4c = *(undefined4 *)(in_ECX + 100);
  uStack_48 = *(undefined4 *)(in_ECX + 0x68);
  uStack_44 = DAT_0099d080;
  thunk_FUN_0079ebf5(&uStack_50,&uStack_50,local_40);
  *(undefined4 *)(in_ECX + 0x6c) = uStack_5c;
  *(undefined4 *)(in_ECX + 0x70) = uStack_58;
  *(undefined4 *)(in_ECX + 0x74) = uStack_54;
  return;
}


// ==== FUN_005b6d90 @ 0x005b6d90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b6d90(int param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 in_stack_ffffffcc;
  undefined4 in_stack_ffffffd0;
  undefined4 in_stack_ffffffd4;
  
  if (param_1 == 0) {
    if ((char)in_ECX[0x23] != '\0') {
      iVar2 = (**(code **)(*DAT_00b5a6a8 + 4))();
      if (iVar2 == 0) {
        uVar3 = 0;
      }
      else {
        FUN_00765c50(in_ECX[0x1f]);
        uVar3 = FUN_005ad9a0(in_ECX[0x26]);
      }
      FUN_00797a20(uVar3);
      *(undefined1 *)(in_ECX + 0x23) = 0;
    }
  }
  else if (param_1 == 1) {
    if ((char)in_ECX[0x23] == '\0') {
      (**(code **)(*in_ECX + 0x44))();
      iVar2 = (**(code **)(*DAT_00b5a6a8 + 4))();
      if (iVar2 == 0) {
        FUN_00797a20(0);
        *(undefined1 *)(in_ECX + 0x23) = 1;
        return;
      }
      iVar2 = in_ECX[0x1f];
      FUN_00765c50(iVar2);
      fVar1 = (float)*(int *)(iVar2 + 0x20);
      if (*(int *)(iVar2 + 0x20) < 0) {
        fVar1 = fVar1 + _DAT_0099d104;
      }
      uVar3 = FUN_005ad8e0(in_ECX[0x26],in_ECX[0x1b],in_ECX[0x1c],in_ECX[0x1d],
                           *(undefined4 *)(iVar2 + 0x1c),fVar1,*(undefined4 *)(iVar2 + 0x24));
      FUN_00797a20(uVar3);
      *(undefined1 *)(in_ECX + 0x23) = 1;
      return;
    }
  }
  else if (((param_1 == 2) && ((char)in_ECX[0x23] == '\x01')) &&
          (((float)in_ECX[0x1b] != 0.0 ||
           (((float)in_ECX[0x1c] != 0.0 || ((float)in_ECX[0x1d] != 0.0)))))) {
    iVar2 = (**(code **)(*DAT_00b5a6a8 + 4))();
    if (iVar2 == 0) {
      FUN_00797a20(0);
      return;
    }
    FUN_00765c50(in_ECX[0x1f]);
    uVar3 = FUN_005b70b0(in_ECX[0x26],in_stack_ffffffcc,in_stack_ffffffd0,in_stack_ffffffd4);
    FUN_00797a20(uVar3);
    return;
  }
  return;
}


// ==== FUN_005b6f50 @ 0x005b6f50 ====

void FUN_005b6f50(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x79) = 0;
  if ((*(uint *)(in_ECX + 0x90) <= *(uint *)(in_ECX + 0x5c)) && (*(int *)(in_ECX + 0x94) != 0)) {
    FUN_005b6d90(0);
    FUN_005b6d90(1);
    *(undefined4 *)(in_ECX + 0x5c) = 0;
  }
  return;
}


// ==== FUN_005b6f90 @ 0x005b6f90 ====

uint FUN_005b6f90(int param_1)

{
  uint uVar1;
  uint in_EAX;
  int *in_ECX;
  
  if (*(char *)((int)in_ECX + 0x79) == '\x01') {
    return in_EAX & 0xffffff00;
  }
  in_ECX[0x17] = in_ECX[0x17] + param_1;
  uVar1 = in_ECX[0x17];
  if (uVar1 < (uint)in_ECX[0x16]) {
    return CONCAT31((int3)(uVar1 >> 8),1);
  }
  if (((uint)in_ECX[0x24] <= uVar1) && (in_ECX[0x25] != 0)) {
    FUN_005b6d90(0);
    *(undefined1 *)((int)in_ECX + 0x79) = 1;
    return (uint)(*(char *)((int)in_ECX + 0x79) == '\0');
  }
  (**(code **)(*in_ECX + 0x44))();
  FUN_005b6d90(1);
  if (DAT_009b02a8 <
      SQRT(((float)in_ECX[0x1c] - (float)in_ECX[0x21]) * ((float)in_ECX[0x1c] - (float)in_ECX[0x21])
           + ((float)in_ECX[0x1b] - (float)in_ECX[0x20]) *
             ((float)in_ECX[0x1b] - (float)in_ECX[0x20]) +
             ((float)in_ECX[0x1d] - (float)in_ECX[0x22]) *
             ((float)in_ECX[0x1d] - (float)in_ECX[0x22]))) {
    FUN_005b6d90(2);
    in_ECX[0x20] = in_ECX[0x1b];
    in_ECX[0x21] = in_ECX[0x1c];
    in_ECX[0x22] = in_ECX[0x1d];
  }
  return (uint)(*(char *)((int)in_ECX + 0x79) == '\0');
}


// ==== FUN_005b7060 @ 0x005b7060 ====

void FUN_005b7060(void)

{
  int in_ECX;
  
  if ((*(uint *)(in_ECX + 0x90) <= *(uint *)(in_ECX + 0x5c)) || (*(int *)(in_ECX + 0x94) == 0)) {
    FUN_005b6d90(0);
  }
  *(undefined1 *)(in_ECX + 0x79) = 1;
  return;
}


// ==== FUN_005b7090 @ 0x005b7090 ====

void FUN_005b7090(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1f1c;
  FUN_005b6d90(0);
  *in_ECX = &PTR_FUN_009c1afc;
  return;
}


// ==== FUN_005b70b0 @ 0x005b70b0 ====

void FUN_005b70b0(undefined4 param_1,undefined1 param_2,void *param_3)

{
  undefined4 *in_ECX;
  uint in_stack_00000020;
  undefined4 in_stack_00000024;
  undefined4 in_stack_00000028;
  undefined4 in_stack_0000002c;
  
  in_ECX[1] = param_1;
  *in_ECX = &PTR_FUN_009c1f68;
  in_ECX[8] = 0xf;
  in_ECX[7] = 0;
  *(undefined1 *)(in_ECX + 3) = 0;
  FUN_00401660(&param_2,0,0xffffffff);
  in_ECX[9] = in_stack_00000024;
  in_ECX[10] = in_stack_00000028;
  in_ECX[0xb] = in_stack_0000002c;
  if (in_stack_00000020 < 0x10) {
    return;
  }
  _free(param_3);
  return;
}


// ==== FUN_005b7110 @ 0x005b7110 ====

undefined4 FUN_005b7110(void)

{
  return 0x60050003;
}


// ==== FUN_005b7120 @ 0x005b7120 ====

void FUN_005b7120(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1f68;
                    /* WARNING: Subroutine does not return */
  FUN_00446f10();
}


// ==== FUN_005b7150 @ 0x005b7150 ====

void FUN_005b7150(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c1f1c;
  FUN_005b6d90(0);
  *in_ECX = &PTR_FUN_009c1afc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005b7180 @ 0x005b7180 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b7180(int param_1,float param_2,undefined4 param_3)

{
  float fVar1;
  int in_ECX;
  
  *(int *)(in_ECX + 8) = param_1;
  *(undefined1 *)(in_ECX + 0x79) = 0;
  *(undefined4 *)(in_ECX + 0x60) = *(undefined4 *)(param_1 + 0x18);
  *(undefined4 *)(in_ECX + 100) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(in_ECX + 0x68) = *(undefined4 *)(param_1 + 0x20);
  fVar1 = (float)*(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  *(int *)(in_ECX + 0x58) = (int)ROUND(fVar1 * param_2);
  fVar1 = (float)*(int *)(param_1 + 0x10);
  if (*(int *)(param_1 + 0x10) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  *(undefined4 *)(in_ECX + 0x5c) = param_3;
  *(int *)(in_ECX + 0x94) = (int)ROUND(fVar1 * param_2);
  return;
}


// ==== FUN_005b7230 @ 0x005b7230 ====

void FUN_005b7230(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x79) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  return;
}


// ==== FUN_005b7240 @ 0x005b7240 ====

void FUN_005b7240(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_8 = *(float *)(in_ECX + 0x6c) - DAT_0099d0f8;
  local_4 = *(float *)(in_ECX + 0x74) - DAT_0099d0f8;
  local_10 = *(float *)(in_ECX + 0x6c) + DAT_0099d0f8;
  local_c = *(float *)(in_ECX + 0x74) + DAT_0099d0f8;
  FUN_004a8890(&local_8,&local_10,param_2);
  return;
}


// ==== FUN_005b72f0 @ 0x005b72f0 ====

void FUN_005b72f0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 auStack_c8 [8];
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  
  iVar1 = (**(code **)(*DAT_00b5a988 + 0x14))();
  *(undefined4 *)(in_ECX + 0x118) = *(undefined4 *)(iVar1 + 0x28);
  *(undefined4 *)(in_ECX + 0x11c) = *(undefined4 *)(iVar1 + 0x2c);
  *(undefined4 *)(in_ECX + 0x120) = *(undefined4 *)(iVar1 + 0x30);
  iVar1 = (**(code **)(*DAT_00b5a988 + 0x14))();
  *(float *)(in_ECX + 0x124) = *(float *)(iVar1 + 0x34);
  *(undefined4 *)(in_ECX + 0x128) = *(undefined4 *)(iVar1 + 0x38);
  *(undefined4 *)(in_ECX + 300) = *(undefined4 *)(iVar1 + 0x3c);
  *(float *)(in_ECX + 0x6c) = *(float *)(in_ECX + 0x124) + *(float *)(in_ECX + 0x60);
  *(float *)(in_ECX + 0x70) = *(float *)(in_ECX + 100) + *(float *)(in_ECX + 0x128);
  *(float *)(in_ECX + 0x74) = *(float *)(in_ECX + 0x68) + *(float *)(in_ECX + 300);
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  *(undefined4 *)(in_ECX + 0x128) = 0;
  puVar2 = (undefined4 *)(**(code **)(*DAT_00b5afd0 + 0xc))();
  puVar3 = auStack_c8;
  for (iVar1 = 0x30; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  *(undefined4 *)(in_ECX + 0x130) = uStack_88;
  *(undefined4 *)(in_ECX + 0x134) = uStack_84;
  *(undefined4 *)(in_ECX + 0x138) = uStack_80;
  *(undefined4 *)(in_ECX + 0x13c) = uStack_7c;
  *(undefined4 *)(in_ECX + 0x140) = uStack_a8;
  *(undefined4 *)(in_ECX + 0x144) = uStack_a4;
  *(undefined4 *)(in_ECX + 0x148) = uStack_a0;
  *(undefined4 *)(in_ECX + 0x14c) = uStack_9c;
  *(undefined4 *)(in_ECX + 0x150) = uStack_98;
  *(undefined4 *)(in_ECX + 0x154) = uStack_94;
  *(undefined4 *)(in_ECX + 0x158) = uStack_90;
  *(undefined4 *)(in_ECX + 0x15c) = uStack_8c;
  return;
}


// ==== FUN_005b7430 @ 0x005b7430 ====

void FUN_005b7430(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xc);
  uVar2 = *(undefined4 *)(in_ECX + 0x70);
  uVar3 = *(undefined4 *)(in_ECX + 0x74);
  *param_1 = *(undefined4 *)(in_ECX + 0x6c);
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  return;
}


// ==== FUN_005b7470 @ 0x005b7470 ====

void FUN_005b7470(int param_1)

{
  int in_ECX;
  float fVar1;
  float fVar2;
  float fVar3;
  float local_18;
  float local_10;
  
  if (param_1 != 0) {
    fVar2 = *(float *)(*(int *)(in_ECX + 0xf4) + 0x24);
    local_18 = *(float *)(param_1 + 0xc);
    local_10 = *(float *)(param_1 + 0x14);
    fVar3 = *(float *)(in_ECX + 0x6c) + fVar2;
    fVar1 = *(float *)(in_ECX + 0x6c) - fVar2;
    if (local_18 <= fVar3) {
      if (local_18 < fVar1) {
        local_18 = fVar3;
      }
    }
    else {
      local_18 = fVar1;
    }
    fVar1 = *(float *)(in_ECX + 0x74) + fVar2;
    fVar2 = *(float *)(in_ECX + 0x74) - fVar2;
    if (local_10 <= fVar1) {
      if (local_10 < fVar2) {
        local_10 = fVar1;
      }
    }
    else {
      local_10 = fVar2;
    }
    *(float *)(param_1 + 0xc) = local_18;
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x10);
    *(float *)(param_1 + 0x14) = local_10;
  }
  return;
}


// ==== FUN_005b7530 @ 0x005b7530 ====

void FUN_005b7530(void)

{
  undefined4 *puVar1;
  void *pvVar2;
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x170) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x170));
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x194);
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 0x194) + 4) = *(int *)(in_ECX + 0x194);
  *(undefined4 *)(in_ECX + 0x198) = 0;
  if (pvVar2 != *(void **)(in_ECX + 0x194)) {
    _free(pvVar2);
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x188);
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 0x188) + 4) = *(int *)(in_ECX + 0x188);
  *(undefined4 *)(in_ECX + 0x18c) = 0;
  if (pvVar2 != *(void **)(in_ECX + 0x188)) {
    _free(pvVar2);
    return;
  }
  puVar1 = *(undefined4 **)(in_ECX + 0x1a0);
  pvVar2 = (void *)*puVar1;
  *puVar1 = puVar1;
  *(int *)(*(int *)(in_ECX + 0x1a0) + 4) = *(int *)(in_ECX + 0x1a0);
  *(undefined4 *)(in_ECX + 0x1a4) = 0;
  if (pvVar2 == *(void **)(in_ECX + 0x1a0)) {
    return;
  }
  _free(pvVar2);
  return;
}


// ==== FUN_005b7600 @ 0x005b7600 ====

void FUN_005b7600(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  int *piVar2;
  
  piVar1 = (int *)in_ECX[0x5f];
  piVar2 = (int *)in_ECX[0x5e];
  *in_ECX = &PTR_FUN_009c205c;
  if (piVar2 != piVar1) {
    do {
      if ((undefined4 *)*piVar2 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar2)(1);
      }
      *piVar2 = 0;
      piVar2 = piVar2 + 1;
    } while (piVar2 != piVar1);
  }
  if ((void *)in_ECX[0x5e] != (void *)0x0) {
    _free((void *)in_ECX[0x5e]);
    return;
  }
  in_ECX[0x5e] = 0;
  in_ECX[0x5f] = 0;
  in_ECX[0x60] = 0;
  FUN_005b7530();
  FUN_008984a0();
  FUN_008984a0();
  FUN_008984a0();
  if ((void *)in_ECX[0x5e] == (void *)0x0) {
    in_ECX[0x5e] = 0;
    in_ECX[0x5f] = 0;
    in_ECX[0x60] = 0;
    *in_ECX = &PTR_FUN_009c1afc;
    return;
  }
  _free((void *)in_ECX[0x5e]);
  return;
}


// ==== FUN_005b76c0 @ 0x005b76c0 ====

void FUN_005b76c0(int param_1)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  int *piVar4;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  piVar1 = *(int **)(in_ECX + 0x17c);
  piVar4 = *(int **)(in_ECX + 0x178);
  while( true ) {
    if (piVar4 == piVar1) {
      *(undefined4 *)(in_ECX + 0xec) = 0;
      *(undefined4 *)(in_ECX + 0xe8) = 0;
      *(undefined4 *)(in_ECX + 0xe4) = 0;
      *(undefined4 *)(in_ECX + 0xe0) = 0;
      *(undefined4 *)(in_ECX + 0xd8) = 0;
      *(undefined4 *)(in_ECX + 0xd4) = 0;
      *(undefined4 *)(in_ECX + 0xd0) = 0;
      *(undefined4 *)(in_ECX + 0xcc) = 0;
      *(undefined4 *)(in_ECX + 0xc4) = 0;
      *(undefined4 *)(in_ECX + 0xc0) = 0;
      *(undefined4 *)(in_ECX + 0xbc) = 0;
      *(undefined4 *)(in_ECX + 0xb8) = 0;
      uVar3 = DAT_0099d080;
      *(undefined4 *)(in_ECX + 0xf0) = DAT_0099d080;
      *(undefined4 *)(in_ECX + 0xdc) = uVar3;
      *(undefined4 *)(in_ECX + 200) = uVar3;
      *(undefined4 *)(in_ECX + 0xb4) = uVar3;
      *(undefined4 *)(in_ECX + 0x90) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x40);
      *(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(in_ECX + 0xf4) = *(undefined4 *)(param_1 + 0x24);
      return;
    }
    if ((int *)*piVar4 == (int *)0x0) break;
    (**(code **)(*(int *)*piVar4 + 8))(param_1);
    piVar4 = piVar4 + 1;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_pRenderElement____NULL_009c1fa0,0x16);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005b7810 @ 0x005b7810 ====

void FUN_005b7810(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  code *pcVar2;
  int in_ECX;
  int *piVar3;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  piVar1 = *(int **)(in_ECX + 0x17c);
  piVar3 = *(int **)(in_ECX + 0x178);
  if (piVar3 != piVar1) {
    do {
      if ((int *)*piVar3 == (int *)0x0) {
        local_4 = 0xf;
        local_8 = 0;
        local_18 = (void *)((uint)local_18 & 0xffffff00);
        FUN_00401740(s_pRenderElement____NULL_009c1fcc,0x16);
        FUN_00406880(local_1c);
        if (local_4 < 0x10) {
          local_4 = 0xf;
          local_8 = 0;
          local_18 = (void *)((uint)local_18 & 0xffffff00);
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        _free(local_18);
        return;
      }
      (**(code **)(*(int *)*piVar3 + 4))(in_ECX + 0x19c,param_1,0,param_2);
      piVar3 = piVar3 + 1;
    } while (piVar3 != piVar1);
  }
  return;
}


// ==== FUN_005b78c0 @ 0x005b78c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b78c0(float param_1)

{
  float fVar1;
  float fVar2;
  undefined4 *puVar3;
  int iVar4;
  char cVar5;
  float *pfVar6;
  undefined4 uVar7;
  float *pfVar8;
  int iVar9;
  int in_ECX;
  float10 fVar10;
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
  float local_4;
  
  iVar4 = (int)param_1;
  local_1c = DAT_0099d080;
  *(undefined4 *)((int)param_1 + 0x34) = 0;
  *(undefined4 *)((int)param_1 + 0x30) = 0;
  *(undefined4 *)((int)param_1 + 0x44) = 0;
  *(undefined1 *)((int)param_1 + 0x48) = 0;
  *(undefined1 *)((int)param_1 + 0xac) = 0;
  pfVar8 = (float *)((int)param_1 + 0x24);
  *pfVar8 = local_1c;
  *(float *)((int)param_1 + 0x28) = local_1c;
  *(float *)((int)param_1 + 0x2c) = local_1c;
  *(undefined4 *)((int)param_1 + 0x18) = 0;
  *(undefined4 *)((int)param_1 + 0x1c) = 0;
  *(undefined4 *)((int)param_1 + 0x20) = 0;
  *(undefined4 *)((int)param_1 + 0x38) = *(undefined4 *)(in_ECX + 0x98);
  iVar9 = *(int *)(in_ECX + 0xf4);
  *(undefined4 *)((int)param_1 + 0xd0) = *(undefined4 *)(iVar9 + 0x40);
  *(undefined4 *)((int)param_1 + 0xd4) = *(undefined4 *)(iVar9 + 0x44);
  *(undefined4 *)((int)param_1 + 0xd8) = *(undefined4 *)(iVar9 + 0x48);
  *(undefined4 *)((int)param_1 + 0x84) = 0;
  *(undefined4 *)((int)param_1 + 0x80) = 0;
  *(undefined4 *)((int)param_1 + 0x7c) = 0;
  *(undefined4 *)((int)param_1 + 0x78) = 0;
  *(undefined4 *)((int)param_1 + 0x70) = 0;
  *(undefined4 *)((int)param_1 + 0x6c) = 0;
  *(undefined4 *)((int)param_1 + 0x68) = 0;
  *(undefined4 *)((int)param_1 + 100) = 0;
  *(undefined4 *)((int)param_1 + 0x5c) = 0;
  *(undefined4 *)((int)param_1 + 0x58) = 0;
  *(undefined4 *)((int)param_1 + 0x54) = 0;
  *(undefined4 *)((int)param_1 + 0x50) = 0;
  *(float *)((int)param_1 + 0x88) = local_1c;
  *(float *)((int)param_1 + 0x74) = local_1c;
  *(float *)((int)param_1 + 0x60) = local_1c;
  *(float *)((int)param_1 + 0x4c) = local_1c;
  param_1 = local_1c;
  local_18 = local_1c;
  local_14 = local_1c;
  if ((0.0 < *(float *)(*(int *)(in_ECX + 0xf4) + 0x3c)) ||
     (0.0 < *(float *)(*(int *)(in_ECX + 0xf4) + 0x38))) {
    fVar10 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x3c),
                                   *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x38));
    *(float *)(iVar4 + 0x38) = (float)fVar10;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0x58) != 0) {
    fVar10 = (float10)FUN_005aa2a0(0,0);
    param_1 = (float)fVar10;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0x90) != 0) {
    pfVar6 = (float *)FUN_005aa3a0(&local_10,0,0);
    local_1c = *pfVar6;
    local_18 = pfVar6[1];
    local_14 = pfVar6[2];
  }
  local_10 = local_1c;
  local_c = local_18;
  local_8 = local_14;
  local_4 = param_1;
  uVar7 = FUN_0040ead0(&local_10);
  *(undefined4 *)(iVar4 + 0x40) = uVar7;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x40) != 0) {
    fVar10 = (float10)FUN_005aa2a0(0,0);
    *(float *)(iVar4 + 0x30) = (float)fVar10;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0x70) != 0) {
    pfVar6 = (float *)FUN_005aa3a0(&local_10,0,0);
    *pfVar8 = *pfVar6;
    *(float *)(iVar4 + 0x28) = pfVar6[1];
    *(float *)(iVar4 + 0x2c) = pfVar6[2];
  }
  iVar9 = *(int *)(in_ECX + 0xf4);
  fVar1 = (float)*(int *)(iVar9 + 0xc);
  if (*(int *)(iVar9 + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar2 = (float)*(int *)(iVar9 + 0x10);
  if (*(int *)(iVar9 + 0x10) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  FUN_0040d0a0(fVar2,fVar1);
  uVar7 = FUN_00802534();
  *(undefined4 *)(iVar4 + 0xb0) = uVar7;
  *(undefined4 *)(iVar4 + 0xb4) = uVar7;
  fVar10 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x28),
                                 *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x24));
  fVar2 = (float)fVar10;
  pfVar8 = (float *)FUN_0040edc0(&local_10);
  fVar1 = pfVar8[2];
  local_1c = *(float *)(in_ECX + 0x6c) + *pfVar8 * fVar2;
  local_18 = *(float *)(in_ECX + 0x70) + pfVar8[1] * fVar2;
  local_14 = *(float *)(in_ECX + 0x74);
  *(float *)(iVar4 + 0xc) = local_1c;
  *(float *)(iVar4 + 0x10) = local_18;
  local_14 = local_14 + fVar1 * fVar2;
  *(float *)(iVar4 + 0x14) = local_14;
  *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(in_ECX + 0x70);
  fVar10 = (float10)FUN_0040d0a0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x30),
                                 *(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x2c));
  *(float *)(iVar4 + 0xcc) = (float)fVar10;
  iVar9 = *(int *)(in_ECX + 0xf4);
  if (((*(float *)(iVar9 + 0x4c) == 0.0) && (*(float *)(iVar9 + 0x50) == 0.0)) &&
     (*(float *)(iVar9 + 0x54) == 0.0)) {
    local_1c = 0.0;
    *(undefined4 *)(iVar4 + 0xdc) = 0;
    local_18 = 0.0;
    *(undefined4 *)(iVar4 + 0xe0) = 0;
    *(undefined4 *)(iVar4 + 0xe4) = 0;
  }
  else {
    local_1c = 0.0;
    fVar10 = (float10)FUN_0040d0a0(0x3a83126f,0x3f800000);
    local_18 = (float)fVar10;
    *(float *)(iVar4 + 0xdc) = local_1c;
    *(float *)(iVar4 + 0xe0) = local_18;
    *(undefined4 *)(iVar4 + 0xe4) = 0;
  }
  local_14 = 0.0;
  iVar9 = *(int *)(in_ECX + 0xf4);
  local_34 = *(float *)(iVar9 + 0x40);
  local_30 = *(float *)(iVar9 + 0x44);
  local_2c = *(float *)(iVar9 + 0x48);
  FUN_0040edc0(&local_28);
  if (_DAT_009c2054 < SQRT(local_28 * local_28 + local_24 * local_24 + local_20 * local_20)) {
    local_34 = local_34 * local_28;
    local_30 = local_30 * local_24;
    local_2c = local_2c * local_20;
  }
  if (_DAT_009c2054 < SQRT(local_34 * local_34 + local_30 * local_30 + local_2c * local_2c)) {
    thunk_FUN_0079e1ba(&local_34,&local_34);
  }
  thunk_FUN_0079e6b3(iVar4 + 0xd0,&local_34,in_ECX + 0xb4);
  puVar3 = *(undefined4 **)(in_ECX + 0x178);
  if ((puVar3 == (undefined4 *)0x0) ||
     (local_8 = (float)(*(int *)(in_ECX + 0x17c) - (int)puVar3 >> 2), local_8 == 0.0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  iVar9 = (**(code **)(*(int *)*puVar3 + 0xc))();
  local_8 = (float)iVar9;
  if (iVar9 < 0) {
    local_8 = local_8 + _DAT_0099d104;
  }
  if (DAT_0099d080 < local_8) {
    if (*(int *)(in_ECX + 0x90) != 0) {
      cVar5 = '\0';
      if (*(int *)(in_ECX + 0x84) != 0) {
        cVar5 = (*(int *)(in_ECX + 0x84) != 1) + '\x01';
      }
      FUN_0081d860(cVar5,0,local_8,*(int *)(in_ECX + 0x90));
      return;
    }
    fVar10 = (float10)FUN_0040d0a0(0,local_8);
    *(int *)(iVar4 + 0x44) = (int)ROUND(fVar10);
  }
  return;
}


// ==== FUN_005b7e20 @ 0x005b7e20 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005b7e20(uint *param_1,float param_2)

{
  code *pcVar1;
  float fVar2;
  int iVar3;
  undefined4 extraout_EAX;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  int in_ECX;
  int iVar9;
  float10 fVar10;
  float fVar11;
  float fVar12;
  float fVar13;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  void *local_18;
  float local_14;
  float local_10;
  undefined4 local_8;
  uint local_4;
  
  iVar3 = (int)param_2;
  if (param_2 == 0.0) {
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(s_i_pElement____NULL_009c1ff8,0x12);
    FUN_00406880(&local_1c);
    if (local_4 < 0x10) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
    _free(local_18);
    return extraout_EAX;
  }
  uVar7 = *(uint *)((int)param_2 + 0xb4);
  if (uVar7 == 0) {
    return 0;
  }
  if (*param_1 < uVar7) {
    *(uint *)((int)param_2 + 0xb4) = uVar7 - *param_1;
  }
  else {
    *(undefined4 *)((int)param_2 + 0xb4) = 0;
  }
  iVar9 = *(int *)((int)param_2 + 0xb4);
  iVar5 = *(int *)((int)param_2 + 0xb0);
  fVar12 = (float)iVar9;
  if (iVar9 < 0) {
    fVar12 = fVar12 + _DAT_0099d104;
  }
  fVar11 = (float)iVar5;
  if (iVar5 < 0) {
    fVar11 = fVar11 + _DAT_0099d104;
  }
  *(float *)((int)param_2 + 0x34) = fVar12 / fVar11;
  fVar2 = (float)(int)*param_1;
  if ((int)*param_1 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  fVar2 = fVar2 * DAT_0099d0ec;
  fVar11 = DAT_0099d080 - fVar12 / fVar11;
  fVar12 = DAT_0099d080;
  if ((DAT_0099d080 <= fVar11) || (param_2 = 0.0, fVar12 = fVar11, 0.0 <= fVar11)) {
    param_2 = fVar12;
  }
  iVar5 = iVar5 - iVar9;
  iVar9 = (int)(param_2 * DAT_009bf5a0);
  FUN_0040ec60(&local_2c,*(undefined4 *)(iVar3 + 0x40));
  if (*(int *)(*(int *)(in_ECX + 8) + 0x58) != 0) {
    fVar10 = (float10)FUN_005aa2a0(iVar9,iVar5);
    local_20 = (float)fVar10;
  }
  if (*(int *)(*(int *)(in_ECX + 8) + 0x90) != 0) {
    FUN_005aa3a0(&local_38,iVar9,iVar5);
    local_1c = local_38;
    local_18 = (void *)local_34;
    local_14 = local_30;
    local_10 = local_20;
    local_2c = local_38;
    local_28 = local_34;
    local_24 = local_30;
  }
  uVar4 = FUN_0040ead0(&local_2c);
  *(undefined4 *)(iVar3 + 0x40) = uVar4;
  if (*(int *)(*(int *)(in_ECX + 8) + 0x70) != 0) {
    puVar6 = (undefined4 *)FUN_005aa3a0(&local_38,iVar9,iVar5);
    *(undefined4 *)(iVar3 + 0x24) = *puVar6;
    *(undefined4 *)(iVar3 + 0x28) = puVar6[1];
    *(undefined4 *)(iVar3 + 0x2c) = puVar6[2];
  }
  fVar12 = *(float *)(*(int *)(in_ECX + 0xf4) + 0x1c);
  if (fVar12 != 0.0) {
    *(float *)(iVar3 + 0x30) = fVar12 * param_2;
  }
  fVar12 = *(float *)(iVar3 + 0xcc) - *(float *)(*(int *)(in_ECX + 0xf4) + 0x34) * fVar2;
  if (fVar12 < 0.0) {
    fVar12 = 0.0;
  }
  *(float *)(iVar3 + 0xcc) = fVar12;
  iVar9 = *(int *)(in_ECX + 0xf4);
  fVar12 = *(float *)(iVar9 + 0x50);
  fVar11 = *(float *)(iVar9 + 0x54);
  *(float *)(iVar3 + 0xdc) = *(float *)(iVar9 + 0x4c) * fVar2 + *(float *)(iVar3 + 0xdc);
  *(float *)(iVar3 + 0xe0) = *(float *)(iVar3 + 0xe0) + fVar12 * fVar2;
  *(float *)(iVar3 + 0xe4) = *(float *)(iVar3 + 0xe4) + fVar11 * fVar2;
  fVar12 = *(float *)(iVar3 + 0xcc) * fVar2;
  fVar13 = *(float *)(iVar3 + 0xd4) * fVar12;
  fVar11 = *(float *)(iVar3 + 0xe0) * fVar2;
  if (*(char *)(iVar3 + 0x48) == '\0') {
    local_38 = *(float *)(iVar3 + 0xd0) * fVar12 + *(float *)(iVar3 + 0xc) +
               *(float *)(iVar3 + 0xdc) * fVar2;
    local_34 = *(float *)(iVar3 + 0x10) + fVar13 + fVar11;
    local_30 = *(float *)(iVar3 + 0x14) + *(float *)(iVar3 + 0xd8) * fVar12 +
               *(float *)(iVar3 + 0xe4) * fVar2;
    *(float *)(iVar3 + 0xc) = local_38;
    *(float *)(iVar3 + 0x10) = local_34;
    *(float *)(iVar3 + 0x14) = local_30;
  }
  else {
    *(float *)(iVar3 + 0x10) = fVar11 + fVar13 + *(float *)(iVar3 + 0x10);
  }
  FUN_005b7470(iVar3);
  puVar6 = *(undefined4 **)(in_ECX + 0x178);
  if ((puVar6 == (undefined4 *)0x0) || (*(int *)(in_ECX + 0x17c) - (int)puVar6 >> 2 == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0085b340();
  }
  uVar7 = (**(code **)(*(int *)*puVar6 + 0xc))();
  if ((1 < uVar7) && (*(int *)(in_ECX + 0x90) != 0)) {
    FUN_0081d6b0(*param_1);
    uVar8 = FUN_00802534();
    *(uint *)(iVar3 + 0x44) = uVar8;
    if (uVar7 <= uVar8) {
      *(uint *)(iVar3 + 0x44) = uVar7 - 1;
    }
  }
  return 1;
}


// ==== FUN_005b81f0 @ 0x005b81f0 ====

void FUN_005b81f0(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c205c;
  in_ECX[0x1f] = 0;
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x5c] = 0;
  in_ECX[0x5e] = 0;
  in_ECX[0x5f] = 0;
  in_ECX[0x60] = 0;
  uVar1 = FUN_005b6400();
  in_ECX[0x62] = uVar1;
  in_ECX[99] = 0;
  uVar1 = FUN_005b6400();
  in_ECX[0x65] = uVar1;
  in_ECX[0x66] = 0;
  uVar1 = FUN_005b6400();
  in_ECX[0x68] = uVar1;
  in_ECX[0x69] = 0;
  in_ECX[0x40] = 0;
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x43] = 0;
  in_ECX[0x44] = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x17] = 0;
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  in_ECX[0x45] = 0;
  return;
}


// ==== FUN_005b82e0 @ 0x005b82e0 ====

void FUN_005b82e0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int local_4;
  
  FUN_005b7530();
  uVar2 = FUN_005b6530(param_1);
  *(undefined4 *)(in_ECX + 0x170) = uVar2;
  if (param_1 != 0) {
    iVar4 = 0;
    do {
      iVar1 = *(int *)(in_ECX + 0x188);
      local_4 = *(int *)(in_ECX + 0x170) + iVar4;
      iVar3 = FUN_005b6490(iVar1,*(undefined4 *)(iVar1 + 4),&local_4);
      FUN_00517200(1);
      *(int *)(iVar1 + 4) = iVar3;
      iVar4 = iVar4 + 0x128;
      param_1 = param_1 + -1;
      **(int **)(iVar3 + 4) = iVar3;
    } while (param_1 != 0);
  }
  return;
}


// ==== FUN_005b8370 @ 0x005b8370 ====

void FUN_005b8370(int param_1)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int in_ECX;
  int *local_2c;
  int local_28;
  int local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  piVar1 = *(int **)(in_ECX + 0x188);
  local_28 = 0;
  local_2c = (int *)*piVar1;
  if (0 < param_1) {
    do {
      if (local_2c == piVar1) {
        return;
      }
      local_20 = local_2c[2];
      if (local_20 == 0) {
        local_4 = 0xf;
        local_8 = 0;
        local_18 = (void *)((uint)local_18 & 0xffffff00);
        FUN_00401740(s_pElement____NULL_009c1fe4,0x10);
        FUN_00406880(local_1c);
        if (local_4 < 0x10) {
          local_4 = 0xf;
          local_8 = 0;
          local_18 = (void *)((uint)local_18 & 0xffffff00);
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        _free(local_18);
        return;
      }
      FUN_005b78c0(local_20);
      iVar2 = *(int *)(in_ECX + 0x194);
      iVar4 = FUN_005b6490(iVar2,*(undefined4 *)(iVar2 + 4),&local_20);
      FUN_00517200(1);
      *(int *)(iVar2 + 4) = iVar4;
      **(int **)(iVar4 + 4) = iVar4;
      if (local_2c != *(int **)(in_ECX + 0x188)) {
        *(int *)local_2c[1] = *local_2c;
        *(int *)(*local_2c + 4) = local_2c[1];
        _free(local_2c);
        return;
      }
      local_28 = local_28 + 1;
      local_2c = (int *)*local_2c;
    } while (local_28 < param_1);
  }
  return;
}


// ==== FUN_005b84a0 @ 0x005b84a0 ====

void FUN_005b84a0(int *param_1)

{
  void *pvVar1;
  
  if (*param_1 == 8) {
    pvVar1 = operator_new(0x24);
    if (pvVar1 != (void *)0x0) {
      param_1 = (int *)FUN_005cb190();
      FUN_005b8aa0(&param_1);
      return;
    }
    param_1 = (int *)0x0;
    FUN_005b8aa0(&param_1);
  }
  else if (*param_1 == 9) {
    pvVar1 = operator_new(0x24);
    if (pvVar1 == (void *)0x0) {
      param_1 = (int *)0x0;
    }
    else {
      param_1 = (int *)FUN_005cb190();
    }
    FUN_005b8aa0(&param_1);
    pvVar1 = operator_new(0x38);
    if (pvVar1 == (void *)0x0) {
      param_1 = (int *)0x0;
      FUN_005b8aa0(&param_1);
      return;
    }
    param_1 = (int *)FUN_005cbb20();
    FUN_005b8aa0(&param_1);
    return;
  }
  return;
}


// ==== FUN_005b8580 @ 0x005b8580 ====

void FUN_005b8580(int *param_1)

{
  uint uVar1;
  uint uVar2;
  int in_ECX;
  
  uVar1 = *(uint *)(*(int *)(in_ECX + 0xf4) + 0x14);
  if (uVar1 != 0) {
    *(int *)(in_ECX + 0x7c) = *(int *)(in_ECX + 0x7c) + *param_1;
    uVar2 = *(uint *)(in_ECX + 0x7c);
    if (uVar1 <= uVar2) {
      *(uint *)(in_ECX + 0x7c) = uVar2 % uVar1;
      if (uVar2 / uVar1 == 0) {
        FUN_005b8370();
        return;
      }
      FUN_005b8370();
      return;
    }
  }
  return;
}


// ==== FUN_005b85d0 @ 0x005b85d0 ====

void FUN_005b85d0(int param_1,undefined4 param_2)

{
  code *pcVar1;
  int in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  FUN_005b84a0(*(int *)(param_1 + 0x24) + 4);
  if ((*(int *)(in_ECX + 0x178) != 0) &&
     (*(int *)(in_ECX + 0x17c) - *(int *)(in_ECX + 0x178) >> 2 != 0)) {
    FUN_005b76c0(param_1);
    *(undefined4 *)(in_ECX + 4) = param_2;
    FUN_005b82e0(*(undefined4 *)(*(int *)(in_ECX + 0xf4) + 0x18));
    return;
  }
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  local_4 = 0xf;
  FUN_00401740(s_m_vecRenderElement_empty______FA_009c1f7c,0x23);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005b8670 @ 0x005b8670 ====

uint FUN_005b8670(int param_1)

{
  int iVar1;
  code *pcVar2;
  int *piVar3;
  char cVar4;
  uint extraout_EAX;
  uint uVar5;
  int iVar6;
  uint extraout_EAX_00;
  int *in_ECX;
  int *piStack_28;
  int iStack_24;
  int *piStack_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  int iStack_8;
  uint uStack_4;
  
  in_ECX[0x17] = in_ECX[0x17] + param_1;
  (**(code **)(*in_ECX + 0x44))();
  if ((uint)in_ECX[0x17] < (uint)in_ECX[0x25]) {
    FUN_005b8580(&param_1);
  }
  if (in_ECX[0x69] != 0) {
    FUN_00510b80();
  }
  piStack_20 = (int *)in_ECX[0x65];
  piStack_28 = (int *)*piStack_20;
  if (piStack_28 != piStack_20) {
    do {
      iVar1 = piStack_28[2];
      iStack_24 = iVar1;
      if (iVar1 == 0) {
        uStack_4 = 0xf;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        iStack_8 = iVar1;
        FUN_00401740(s_pElement____NULL_009c1fb8,0x10);
        FUN_00406880(auStack_1c);
        if (uStack_4 < 0x10) {
          uStack_4 = 0xf;
          iStack_8 = 0;
          pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
          pcVar2 = (code *)swi(3);
          uVar5 = (*pcVar2)();
          return uVar5;
        }
        _free(pvStack_18);
        return extraout_EAX;
      }
      cVar4 = FUN_005b7e20(&param_1,iVar1);
      if (cVar4 == '\0') {
        iVar1 = in_ECX[0x62];
        iVar6 = FUN_005b6490(iVar1,*(undefined4 *)(iVar1 + 4),&iStack_24);
        FUN_00517200(1);
        *(int *)(iVar1 + 4) = iVar6;
        **(int **)(iVar6 + 4) = iVar6;
        piVar3 = (int *)*piStack_28;
        if (piStack_28 != (int *)in_ECX[0x65]) {
          *(int *)piStack_28[1] = *piStack_28;
          *(int *)(*piStack_28 + 4) = piStack_28[1];
          _free(piStack_28);
          return extraout_EAX_00;
        }
      }
      else {
        cVar4 = FUN_0040f420(iVar1 + 0xc,in_ECX + 0x4c);
        if (cVar4 == '\0') {
          iVar1 = in_ECX[0x68];
          iVar6 = FUN_005b6490(iVar1,*(undefined4 *)(iVar1 + 4),&iStack_24);
          FUN_00517200(1);
          *(int *)(iVar1 + 4) = iVar6;
          **(int **)(iVar6 + 4) = iVar6;
        }
        piVar3 = (int *)*piStack_28;
      }
      piStack_28 = piVar3;
    } while (piStack_28 != piStack_20);
  }
  if (in_ECX[0x66] == 0) {
    *(undefined1 *)((int)in_ECX + 0x79) = 1;
  }
  return (uint)(*(char *)((int)in_ECX + 0x79) == '\0');
}


// ==== FUN_005b8830 @ 0x005b8830 ====

void FUN_005b8830(byte param_1)

{
  void *in_ECX;
  
  FUN_005b7600();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005b8850 @ 0x005b8850 ====

void FUN_005b8850(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_009828c0;
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


// ==== Catch@005b89b1 @ 0x005b89b1 ====

void Catch_005b89b1(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005b8aa0 @ 0x005b8aa0 ====

void FUN_005b8aa0(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_005b8850(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_005b8af0 @ 0x005b8af0 ====

void FUN_005b8af0(void)

{
  return;
}


// ==== FUN_005b8b00 @ 0x005b8b00 ====

undefined1 FUN_005b8b00(void)

{
  return 1;
}


// ==== FUN_005b8bd0 @ 0x005b8bd0 ====

void FUN_005b8bd0(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x79) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(in_ECX + 0x84);
  if ((((*(char *)(in_ECX + 0x7c) == '\0') && (*(int *)(in_ECX + 4) != 0)) &&
      (iVar2 = *(int *)(*(int *)(in_ECX + 4) + 0x108), iVar2 != 0)) &&
     (piVar1 = (int *)(**(code **)(*DAT_00b5afbc + 0xc))(*(undefined4 *)(iVar2 + 4)),
     piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 == 0) {
      FUN_005c9110(*(undefined1 *)(in_ECX + 0x9c),*(undefined4 *)(in_ECX + 0xa0));
    }
    *(undefined1 *)(in_ECX + 0x7c) = 1;
  }
  return;
}


// ==== FUN_005b8c40 @ 0x005b8c40 ====

void FUN_005b8c40(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  if (((*(int *)(in_ECX + 4) != 0) && (iVar2 = *(int *)(*(int *)(in_ECX + 4) + 0x108), iVar2 != 0))
     && (piVar1 = (int *)(**(code **)(*DAT_00b5afbc + 0xc))(*(undefined4 *)(iVar2 + 4)),
        piVar1 != (int *)0x0)) {
    iVar2 = (**(code **)(*piVar1 + 0x30))();
    if (iVar2 == 0) {
      FUN_005c9140(*(undefined1 *)(in_ECX + 0x9c));
    }
    *(undefined1 *)(in_ECX + 0x7c) = 0;
    *(undefined1 *)(in_ECX + 0x79) = 1;
  }
  return;
}


// ==== FUN_005b8c90 @ 0x005b8c90 ====

void FUN_005b8c90(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_ECX;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xc);
  uVar2 = *(undefined4 *)(in_ECX + 0x70);
  uVar3 = *(undefined4 *)(in_ECX + 0x74);
  *param_1 = *(undefined4 *)(in_ECX + 0x6c);
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  param_1[3] = uVar1;
  return;
}


// ==== FUN_005b8cd0 @ 0x005b8cd0 ====

void FUN_005b8cd0(void)

{
  void *pvVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c20f4;
  *(undefined1 *)(in_ECX + 0x1f) = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0x17] = 0;
  *(undefined1 *)((int)in_ECX + 0x79) = 0;
  *(undefined1 *)(in_ECX + 0x1e) = 0;
  pvVar1 = operator_new(0x20);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar1 + 0x1c) = 0xf;
    *(undefined4 *)((int)pvVar1 + 0x18) = 0;
    *(undefined1 *)((int)pvVar1 + 8) = 0;
  }
  in_ECX[0x28] = pvVar1;
  pvVar1 = operator_new(0x24);
  *(void **)in_ECX[0x28] = pvVar1;
  *(undefined4 *)(*(int *)in_ECX[0x28] + 0x20) = 0;
  return;
}


// ==== FUN_005b8d40 @ 0x005b8d40 ====

void FUN_005b8d40(void)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c20f4;
  if (((DAT_00b5afbc != (int *)0x0) && (in_ECX[1] != 0)) &&
     (iVar2 = *(int *)(in_ECX[1] + 0x108), iVar2 != 0)) {
    piVar1 = (int *)(**(code **)(*DAT_00b5afbc + 0xc))(*(undefined4 *)(iVar2 + 4));
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x30))();
      if (iVar2 == 0) {
        FUN_005c9140(*(undefined1 *)(in_ECX + 0x27));
      }
      *(undefined1 *)(in_ECX + 0x1f) = 0;
      *(undefined1 *)((int)in_ECX + 0x79) = 1;
    }
  }
  if (*(int *)(*(int *)in_ECX[0x28] + 0x20) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(*(int *)in_ECX[0x28] + 0x20));
    *(undefined4 *)(*(int *)in_ECX[0x28] + 0x20) = 0;
  }
  _free(*(void **)in_ECX[0x28]);
  return;
}


// ==== FUN_005b8e20 @ 0x005b8e20 ====

void FUN_005b8e20(int param_1,undefined4 param_2)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  *(undefined4 *)(in_ECX + 4) = param_2;
  uVar1 = *(undefined1 *)(*(int *)(param_1 + 0xc) + 0x1c);
  *(undefined1 *)(in_ECX + 0x9c) = uVar1;
  *(undefined1 *)**(undefined4 **)(in_ECX + 0xa0) = uVar1;
  iVar4 = **(int **)(in_ECX + 0xa0);
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  *(undefined4 *)(iVar4 + 0x14) = *puVar2;
  *(undefined4 *)(iVar4 + 0x18) = puVar2[1];
  *(undefined4 *)(**(int **)(in_ECX + 0xa0) + 0x1c) =
       *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x18);
  FUN_00401660(*(int *)(param_1 + 0xc) + 0x20,0,0xffffffff);
  iVar4 = *(int *)(param_1 + 0xc);
  *(undefined4 *)(in_ECX + 0x8c) = *(undefined4 *)(iVar4 + 8);
  *(undefined4 *)(in_ECX + 0x90) = *(undefined4 *)(iVar4 + 0xc);
  *(undefined4 *)(in_ECX + 0x94) = *(undefined4 *)(iVar4 + 0x10);
  local_10 = *(undefined4 *)(in_ECX + 0x8c);
  local_c = *(undefined4 *)(in_ECX + 0x90);
  local_8 = *(undefined4 *)(in_ECX + 0x94);
  *(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x14);
  local_4 = *(undefined4 *)(in_ECX + 0x98);
  uVar3 = FUN_0040ead0(&local_10);
  *(undefined4 *)(**(int **)(in_ECX + 0xa0) + 0xc) = uVar3;
  *(undefined4 *)(**(int **)(in_ECX + 0xa0) + 4) = *(undefined4 *)(*(int *)(param_1 + 0x20) + 4);
  *(undefined1 *)(**(int **)(in_ECX + 0xa0) + 8) = *(undefined1 *)(*(int *)(param_1 + 0x20) + 0x44);
  *(undefined4 *)(**(int **)(in_ECX + 0xa0) + 0x10) = *(undefined4 *)(param_1 + 8);
  iVar4 = FUN_00403620(0,*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1c),&DAT_009c20a6,0);
  if (iVar4 != 0) {
    uVar3 = FUN_004b4e70(*(int *)(param_1 + 0x20) + 8);
    *(undefined4 *)(**(int **)(in_ECX + 0xa0) + 0x20) = uVar3;
  }
  return;
}


// ==== FUN_005b8f70 @ 0x005b8f70 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b8f70(float param_1)

{
  int iVar1;
  float fVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  float10 fVar7;
  float fVar8;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  if ((uint)param_1 < *(uint *)(in_ECX + 0x88)) {
    *(uint *)(in_ECX + 0x88) = *(uint *)(in_ECX + 0x88) - (int)param_1;
  }
  else {
    *(undefined4 *)(in_ECX + 0x88) = 0;
  }
  iVar6 = *(int *)(in_ECX + 0x88);
  iVar3 = *(int *)(in_ECX + 0x84);
  fVar2 = (float)iVar6;
  if (iVar6 < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  fVar8 = (float)iVar3;
  if (iVar3 < 0) {
    fVar8 = fVar8 + _DAT_0099d104;
  }
  fVar2 = DAT_0099d080 - fVar2 / fVar8;
  if (DAT_0099d080 <= fVar2) {
    fVar2 = DAT_0099d080;
  }
  else {
    fVar8 = 0.0;
    if (fVar2 < 0.0) goto LAB_005b8ff7;
  }
  fVar8 = fVar2;
LAB_005b8ff7:
  iVar3 = iVar3 - iVar6;
  iVar6 = (int)(fVar8 * DAT_009bf5a0);
  if (*(int *)(*(int *)(in_ECX + 8) + 0x70) != 0) {
    FUN_005aa3a0(&local_1c,iVar6,iVar3);
    *(undefined4 *)(**(int **)(in_ECX + 0xa0) + 0x10) = local_1c;
  }
  iVar1 = *(int *)(in_ECX + 8);
  if ((*(int *)(iVar1 + 0x90) != 0) || (*(int *)(iVar1 + 0x58) != 0)) {
    param_1 = *(float *)(in_ECX + 0x98);
    local_1c = *(undefined4 *)(in_ECX + 0x8c);
    local_18 = *(undefined4 *)(in_ECX + 0x90);
    local_14 = *(undefined4 *)(in_ECX + 0x94);
    if (*(int *)(iVar1 + 0x58) != 0) {
      fVar7 = (float10)FUN_005aa2a0(iVar6,iVar3);
      param_1 = (float)fVar7;
    }
    if (*(int *)(*(int *)(in_ECX + 8) + 0x90) != 0) {
      puVar4 = (undefined4 *)FUN_005aa3a0(&local_10,iVar6,iVar3);
      local_1c = *puVar4;
      local_18 = puVar4[1];
      local_14 = puVar4[2];
    }
    local_10 = local_1c;
    local_c = local_18;
    local_8 = local_14;
    local_4 = param_1;
    uVar5 = FUN_0040ead0(&local_10);
    *(undefined4 *)(**(int **)(in_ECX + 0xa0) + 0xc) = uVar5;
  }
  return;
}


// ==== FUN_005b9120 @ 0x005b9120 ====

uint FUN_005b9120(int param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  
  if (*(uint *)(in_ECX + 0x80) <= *(uint *)(in_ECX + 0x5c)) {
    uVar2 = 0;
    if ((*(int *)(in_ECX + 4) != 0) &&
       (iVar3 = *(int *)(*(int *)(in_ECX + 4) + 0x108), uVar2 = 0, iVar3 != 0)) {
      piVar1 = (int *)(**(code **)(*DAT_00b5afbc + 0xc))(*(undefined4 *)(iVar3 + 4));
      uVar2 = 0;
      if (piVar1 != (int *)0x0) {
        uVar2 = (**(code **)(*piVar1 + 0x30))();
        if (uVar2 == 0) {
          uVar2 = FUN_005c9140(*(undefined1 *)(in_ECX + 0x9c));
        }
        *(undefined1 *)(in_ECX + 0x7c) = 0;
        *(undefined1 *)(in_ECX + 0x79) = 1;
      }
    }
    *(undefined1 *)(in_ECX + 0x79) = 1;
    return uVar2 & 0xffffff00;
  }
  uVar2 = *(uint *)(in_ECX + 0x5c) + param_1;
  *(uint *)(in_ECX + 0x5c) = uVar2;
  if (uVar2 < *(uint *)(in_ECX + 0x58)) {
    return CONCAT31((int3)(uVar2 >> 8),1);
  }
  FUN_005b8f70(param_1);
  if (((*(char *)(in_ECX + 0x7c) == '\0') && (*(int *)(in_ECX + 4) != 0)) &&
     (iVar3 = *(int *)(*(int *)(in_ECX + 4) + 0x108), iVar3 != 0)) {
    piVar1 = (int *)(**(code **)(*DAT_00b5afbc + 0xc))(*(undefined4 *)(iVar3 + 4));
    if (piVar1 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar1 + 0x30))();
      if (iVar3 == 0) {
        FUN_005c9110(*(undefined1 *)(in_ECX + 0x9c),*(undefined4 *)(in_ECX + 0xa0));
      }
      *(undefined1 *)(in_ECX + 0x7c) = 1;
    }
  }
  return (uint)(*(char *)(in_ECX + 0x79) == '\0');
}


// ==== FUN_005b9200 @ 0x005b9200 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b9200(int param_1,float param_2,undefined4 param_3)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int in_ECX;
  float10 fVar5;
  
  *(int *)(in_ECX + 8) = param_1;
  *(undefined1 *)(in_ECX + 0x79) = 0;
  fVar1 = (float)*(int *)(param_1 + 0xc);
  if (*(int *)(param_1 + 0xc) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  *(int *)(in_ECX + 0x58) = (int)ROUND(fVar1 * param_2);
  iVar2 = FUN_00802534();
  iVar4 = *(int *)(in_ECX + 0x58);
  *(int *)(in_ECX + 0x80) = iVar2;
  *(int *)(in_ECX + 0x84) = iVar2 - iVar4;
  if (*(char *)(param_1 + 0x32) != '\0') {
    fVar1 = (float)iVar4;
    if (iVar4 < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar5 = (float10)FUN_0040d0a0(0,fVar1 * DAT_0099d0ec);
    *(int *)(in_ECX + 0x58) = (int)ROUND(fVar5 * (float10)DAT_009b012c);
  }
  *(undefined4 *)(in_ECX + 0x88) = *(undefined4 *)(in_ECX + 0x84);
  *(undefined4 *)(in_ECX + 0x5c) = param_3;
  FUN_005b8f70(0);
  iVar4 = *(int *)(in_ECX + 4);
  if (*(char *)(in_ECX + 0x78) == '\0') {
    if (((iVar4 != 0) && (*(int *)(iVar4 + 0x108) != 0)) &&
       (piVar3 = (int *)(**(code **)(*DAT_00b5afbc + 0xc))
                                  (*(undefined4 *)(*(int *)(iVar4 + 0x108) + 4)),
       piVar3 != (int *)0x0)) {
      iVar4 = (**(code **)(*piVar3 + 0x30))();
      if (iVar4 == 0) {
        FUN_005c9140(*(undefined1 *)(in_ECX + 0x9c));
      }
      *(undefined1 *)(in_ECX + 0x7c) = 0;
      *(undefined1 *)(in_ECX + 0x79) = 1;
    }
  }
  else if (((iVar4 != 0) && (*(int *)(iVar4 + 0x108) != 0)) &&
          (piVar3 = (int *)(**(code **)(*DAT_00b5afbc + 0xc))
                                     (*(undefined4 *)(*(int *)(iVar4 + 0x108) + 4)),
          piVar3 != (int *)0x0)) {
    iVar4 = (**(code **)(*piVar3 + 0x30))();
    if (iVar4 == 0) {
      FUN_005c9110(*(undefined1 *)(in_ECX + 0x9c),*(undefined4 *)(in_ECX + 0xa0));
    }
    *(undefined1 *)(in_ECX + 0x7c) = 1;
    return;
  }
  return;
}


// ==== FUN_005b9390 @ 0x005b9390 ====

void FUN_005b9390(byte param_1)

{
  void *in_ECX;
  
  FUN_005b8d40();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005b93b0 @ 0x005b93b0 ====

void FUN_005b93b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c217c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005b93d0 @ 0x005b93d0 ====

void FUN_005b93d0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xac) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  FUN_005cc220();
  return;
}


// ==== FUN_005b93f0 @ 0x005b93f0 ====

void FUN_005b93f0(undefined4 param_1)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x50) != '\0') {
    FUN_005cc180(param_1,*(undefined4 *)(in_ECX + 0x24));
  }
  return;
}


// ==== FUN_005b9410 @ 0x005b9410 ====

void FUN_005b9410(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_c = DAT_009b0120;
  if (DAT_0099cdc8 < *(float *)(in_ECX + 0xf0)) {
    local_c = *(float *)(in_ECX + 0xf0);
  }
  local_8 = *(float *)(in_ECX + 0xf4) - local_c;
  local_4 = *(float *)(in_ECX + 0xfc) - local_c;
  local_10 = *(float *)(in_ECX + 0xf4) + local_c;
  local_c = *(float *)(in_ECX + 0xfc) + local_c;
  FUN_004a8890(&local_8,&local_10,param_2);
  return;
}


// ==== FUN_005b94b0 @ 0x005b94b0 ====

void FUN_005b94b0(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x94);
  param_1[1] = *(undefined4 *)(in_ECX + 0x98);
  return;
}


// ==== FUN_005b94d0 @ 0x005b94d0 ====

void FUN_005b94d0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x1c))(param_1,param_2,param_3,param_4);
  *(undefined1 *)(in_ECX + 0x2b) = 1;
  in_ECX[0x2a] = 4;
  *(undefined1 *)((int)in_ECX + 0xad) = 0;
  return;
}


// ==== FUN_005b9510 @ 0x005b9510 ====

void FUN_005b9510(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x1c))(param_1,param_2,param_3,param_4);
  in_ECX[0x2a] = 5;
  return;
}


// ==== FUN_005b9540 @ 0x005b9540 ====

void FUN_005b9540(int *param_1,int *param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6)

{
  int *in_ECX;
  
  in_ECX[0x21] = *param_1;
  in_ECX[0x22] = param_1[1];
  in_ECX[0x23] = param_1[2];
  in_ECX[0x24] = *param_2;
  in_ECX[0x25] = param_2[1];
  in_ECX[0x26] = param_2[2];
  in_ECX[0x1f] = *param_6;
  (**(code **)(*in_ECX + 0x1c))(0,*param_3,param_4,param_5);
  *(undefined1 *)(in_ECX + 0x2b) = 1;
  in_ECX[0x2a] = 1;
  return;
}


// ==== FUN_005b95b0 @ 0x005b95b0 ====

void FUN_005b95b0(int *param_1,int *param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6)

{
  int *in_ECX;
  
  in_ECX[0x21] = *param_1;
  in_ECX[0x22] = param_1[1];
  in_ECX[0x23] = param_1[2];
  in_ECX[0x20] = *param_2;
  in_ECX[0x1f] = *param_6;
  (**(code **)(*in_ECX + 0x1c))(0,*param_3,param_4,param_5);
  *(undefined1 *)(in_ECX + 0x2b) = 1;
  in_ECX[0x2a] = 2;
  return;
}


// ==== FUN_005b9660 @ 0x005b9660 ====

void FUN_005b9660(void)

{
  short sVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  
  iVar2 = (**(code **)(*DAT_00b5acf4 + 4))(*(undefined4 *)(in_ECX + 0x40));
  if (iVar2 == 0) {
    return;
  }
  *(undefined4 *)(in_ECX + 0xf0) = *(undefined4 *)(iVar2 + 0x1c);
  sVar1 = *(short *)(in_ECX + 0x42);
  if ((sVar1 == 3) || (sVar1 == 4)) {
    uVar3 = DAT_009bac80;
  }
  else {
    if (sVar1 != 9) goto LAB_005b96b6;
    uVar3 = DAT_0099de80;
  }
  *(undefined4 *)(in_ECX + 0xf0) = uVar3;
LAB_005b96b6:
  FUN_005cc450(in_ECX + 0x40,*(undefined4 *)(in_ECX + 0xd0),in_ECX);
  *(int *)(in_ECX + 0x104) = iVar2 + 0x30;
  return;
}


// ==== FUN_005b96e0 @ 0x005b96e0 ====

void FUN_005b96e0(undefined1 *param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  
  piVar2 = (int *)FUN_005cc2e0(*(int *)(param_1 + 4) << 0x10);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(*param_1);
    cVar1 = (**(code **)(*piVar2 + 4))();
    if (cVar1 != '\0') {
      (**(code **)(*piVar2 + 0x2c))(param_1,param_2,param_1);
      return;
    }
    (**(code **)(*piVar2 + 0x34))();
  }
  return;
}


// ==== FUN_005b9740 @ 0x005b9740 ====

bool FUN_005b9740(undefined4 param_1)

{
  undefined1 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  float local_4;
  
  local_4 = *(float *)(in_ECX + 0xf0);
  if (DAT_0099cdc8 < local_4) {
    local_10 = *(undefined4 *)(in_ECX + 0xf4);
    local_c = *(undefined4 *)(in_ECX + 0xf8);
    local_8 = *(undefined4 *)(in_ECX + 0xfc);
    iVar2 = FUN_0040d570(&local_10,param_1);
    return iVar2 != 1;
  }
  uVar1 = FUN_005cc1e0(param_1);
  return (bool)uVar1;
}


// ==== FUN_005b97b0 @ 0x005b97b0 ====

void FUN_005b97b0(int param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  int in_ECX;
  int iVar3;
  float unaff_EBP;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 auStack_100 [14];
  undefined4 auStack_c8 [2];
  undefined1 local_c0 [52];
  undefined4 uStack_8c;
  undefined1 auStack_88 [8];
  undefined1 auStack_80 [64];
  undefined4 auStack_40 [16];
  
  local_110 = DAT_0099d080;
  if (*(char *)(in_ECX + 0xcd) == '\0') {
    puVar5 = (undefined4 *)(in_ECX + 0x54);
    puVar2 = (undefined4 *)(param_1 + 0x1c);
    puVar4 = puVar5;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    if (local_110 < *(float *)(param_1 + 0x18) || local_110 == *(float *)(param_1 + 0x18)) {
      local_110 = *(float *)(param_1 + 0x18);
    }
    if (param_2 != -1) {
      cVar1 = (**(code **)(**(int **)(in_ECX + 0x108) + 8))(param_2,local_c0);
      if (cVar1 == '\0') {
        puVar2 = (undefined4 *)FUN_005b1860(auStack_88,auStack_100 + -5);
        puVar4 = auStack_c8;
        for (iVar3 = 0x10; local_110 = unaff_EBP, iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar4 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar4 = puVar4 + 1;
        }
      }
      thunk_FUN_0079ee7b(&local_108,auStack_c8,puVar5);
      puVar2 = auStack_100;
      puVar4 = puVar5;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar4 = puVar4 + 1;
      }
    }
    *(undefined4 *)(in_ECX + 0x94) = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(in_ECX + 0x98) = *(undefined4 *)(param_1 + 0x14);
    local_108 = 0;
    local_104 = *(undefined4 *)(in_ECX + 0x98);
    *(undefined4 *)(in_ECX + 0xbc) = *(undefined4 *)(in_ECX + 0x94);
    *(undefined4 *)(in_ECX + 0xc0) = 0;
    *(undefined4 *)(in_ECX + 0xc4) = local_104;
    if (*(char *)(in_ECX + 0xe8) == '\0') {
      thunk_FUN_0079f761(auStack_100,local_110,local_110,local_110);
      puVar2 = auStack_100;
      puVar4 = auStack_40;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar4 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar4 = puVar4 + 1;
      }
      thunk_FUN_0079ee7b(auStack_80,auStack_40,puVar5);
      puVar2 = &uStack_8c;
      for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar5 = puVar5 + 1;
      }
    }
    *(undefined1 *)(in_ECX + 0xcd) = 1;
  }
  return;
}


// ==== FUN_005b9950 @ 0x005b9950 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b9950(void)

{
  float fVar1;
  float fVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  float local_e0;
  float local_dc;
  float local_d8 [2];
  undefined4 auStack_d0 [16];
  undefined4 auStack_90 [2];
  undefined1 auStack_88 [44];
  undefined4 auStack_5c [3];
  undefined1 auStack_50 [80];
  
  local_e0 = 0.0 - (*(float *)(in_ECX + 0xa4) - *(float *)(in_ECX + 0xb0));
  local_dc = 0.0 - (*(float *)(in_ECX + 0xa8) - *(float *)(in_ECX + 0xb4));
  local_d8[0] = 0.0 - (*(float *)(in_ECX + 0xac) - *(float *)(in_ECX + 0xb8));
  thunk_FUN_0079e1ba(in_ECX + 0xbc,&local_e0);
  fVar1 = (float)*(int *)(in_ECX + 0x44);
  if (*(int *)(in_ECX + 0x44) < 0) {
    fVar1 = fVar1 + _DAT_0099d104;
  }
  fVar2 = (float)*(int *)(in_ECX + 0x9c);
  if (*(int *)(in_ECX + 0x9c) < 0) {
    fVar2 = fVar2 + _DAT_0099d104;
  }
  fVar1 = fVar1 / fVar2;
  puVar6 = (undefined4 *)(in_ECX + 0x54);
  local_e0 = (*(float *)(in_ECX + 0xb8) - *(float *)(in_ECX + 0xac)) * fVar1 +
             *(float *)(in_ECX + 0xac);
  thunk_FUN_0079f7f5(puVar6,(*(float *)(in_ECX + 0xb0) - *(float *)(in_ECX + 0xa4)) * fVar1 +
                            *(float *)(in_ECX + 0xa4),
                     (*(float *)(in_ECX + 0xb4) - *(float *)(in_ECX + 0xa8)) * fVar1 +
                     *(float *)(in_ECX + 0xa8),local_e0);
  FUN_0040d620(local_d8,in_ECX + 0xbc);
  thunk_FUN_0079fb96(auStack_88,local_d8);
  puVar4 = auStack_90;
  puVar5 = auStack_d0;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  thunk_FUN_0079ee7b(auStack_50,auStack_d0,puVar6);
  puVar4 = auStack_5c;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  return;
}


// ==== FUN_005b9ab0 @ 0x005b9ab0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b9ab0(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  int in_ECX;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  float fVar10;
  float fVar11;
  undefined1 auStack_12a [10];
  float fStack_120;
  float fStack_11c;
  undefined4 auStack_118 [2];
  undefined1 auStack_110 [8];
  undefined4 auStack_108 [12];
  undefined4 auStack_d8 [20];
  undefined1 auStack_88 [36];
  undefined4 auStack_64 [3];
  undefined1 auStack_58 [84];
  int *piStack_4;
  
  iVar5 = (**(code **)(*DAT_00b5afd4 + 0xc))(*(undefined4 *)(in_ECX + 0xa0));
  if (iVar5 != 0) {
    if (*(char *)(iVar5 + 0x10) != '\0') {
      puVar9 = (undefined4 *)(in_ECX + 0x54);
      puVar7 = (undefined4 *)(iVar5 + 0x20);
      puVar8 = puVar9;
      for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      (**(code **)(*DAT_00b5afd4 + 0x10))(iVar5);
      if (*piStack_4 != -1) {
        cVar4 = (**(code **)(**(int **)(in_ECX + 0x108) + 8))(*piStack_4,auStack_88);
        if (cVar4 != '\0') {
          thunk_FUN_0079ee7b(auStack_108,auStack_88,puVar9);
          puVar7 = auStack_108;
          puVar8 = puVar9;
          for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar8 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar8 = puVar8 + 1;
          }
        }
      }
      fStack_120 = *(float *)(in_ECX + 0x88);
      fVar1 = *(float *)(in_ECX + 0x84);
      fStack_11c = *(float *)(in_ECX + 0x8c);
      fVar10 = *(float *)(in_ECX + 0xa8) - fStack_120;
      fVar11 = *(float *)(in_ECX + 0xac) - fStack_11c;
      thunk_FUN_0079e1ba(in_ECX + 0xbc,auStack_12a + -6);
      fVar2 = (float)*(int *)(in_ECX + 0x44);
      if (*(int *)(in_ECX + 0x44) < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      fVar3 = (float)*(int *)(in_ECX + 0x9c);
      if (*(int *)(in_ECX + 0x9c) < 0) {
        fVar3 = fVar3 + _DAT_0099d104;
      }
      fVar2 = fVar2 / fVar3;
      thunk_FUN_0079f7f5(puVar9,((0.0 - fVar10) - *(float *)(in_ECX + 0xa4)) * fVar2 +
                                *(float *)(in_ECX + 0xa4),
                         ((0.0 - fVar11) - *(float *)(in_ECX + 0xa8)) * fVar2 +
                         *(float *)(in_ECX + 0xa8),
                         (fVar1 - *(float *)(in_ECX + 0xac)) * fVar2 + *(float *)(in_ECX + 0xac));
      FUN_0040d620(&fStack_120,in_ECX + 0xbc);
      thunk_FUN_0079fb96(auStack_110,&fStack_120);
      puVar7 = auStack_118;
      puVar8 = auStack_d8;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      thunk_FUN_0079ee7b(auStack_58,auStack_d8,puVar9);
      puVar7 = auStack_64;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      return;
    }
    (**(code **)(*DAT_00b5afd4 + 0x10))(iVar5);
  }
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(in_ECX + 0x9c);
  return;
}


// ==== FUN_005b9df0 @ 0x005b9df0 ====

void FUN_005b9df0(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined1 auStack_46 [2];
  int aiStack_44 [17];
  
  (**(code **)(*in_ECX + 0x1c))(param_1,param_2,param_3,param_4);
  thunk_FUN_0079f7f5(auStack_46 + -10,*param_1,param_1[1],param_1[2]);
  piVar2 = (int *)(auStack_46 + -10);
  piVar3 = in_ECX + 0xd;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar2;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  }
  iVar1 = param_2[2];
  in_ECX[0x1d] = *param_2;
  in_ECX[0x1e] = iVar1;
  *(undefined1 *)(in_ECX + 0x2b) = 1;
  in_ECX[0x2a] = 3;
  return;
}


// ==== FUN_005b9e80 @ 0x005b9e80 ====

undefined4 FUN_005b9e80(undefined4 *param_1,undefined4 *param_2,uint *param_3,char param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  *(undefined4 *)(in_ECX + 100) = 0;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  uVar1 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x70) = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x5c) = uVar1;
  *(undefined4 *)(in_ECX + 0x48) = uVar1;
  *(undefined4 *)(in_ECX + 0x34) = uVar1;
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = *param_2;
  *(undefined1 *)(in_ECX + 0xac) = 0;
  *(uint *)(in_ECX + 0x20) = *param_3;
  if ((code *)(*param_3 & 0xffff0000) == FUN_00640000) {
    *(undefined1 *)(in_ECX + 200) = 1;
  }
  if (param_4 != '\0') {
    *(undefined4 *)(in_ECX + 0xcc) = 3;
  }
  iVar3 = (**(code **)(*DAT_00b5afd4 + 0xc))(*(undefined4 *)(in_ECX + 4));
  *(int *)(in_ECX + 0xe8) = iVar3;
  if (iVar3 == 0) {
    return 0;
  }
  if (*(char *)(iVar3 + 0x10) != '\0') {
    uVar1 = *(undefined4 *)(iVar3 + 0x54);
    uVar2 = *(undefined4 *)(iVar3 + 0x58);
    *(undefined4 *)(in_ECX + 0xd4) = *(undefined4 *)(iVar3 + 0x50);
    *(undefined4 *)(in_ECX + 0xd8) = uVar1;
    *(undefined4 *)(in_ECX + 0xdc) = uVar2;
  }
  FUN_005b9660();
  (**(code **)(*DAT_00b5afac + 4))(*param_2,in_ECX + -0x20,*(undefined4 *)(in_ECX + 0xcc));
  return 1;
}


// ==== FUN_005b9fc0 @ 0x005b9fc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005b9fc0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  undefined1 uVar7;
  undefined4 *puVar8;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 4);
  if (*(uint *)(in_ECX + 0x30) != 0) {
    fVar5 = (float)*(int *)(in_ECX + 0x44);
    if (*(int *)(in_ECX + 0x44) < 0) {
      fVar5 = fVar5 + _DAT_0099d104;
    }
    fVar6 = (float)*(int *)(in_ECX + 0x2c);
    if (*(int *)(in_ECX + 0x2c) < 0) {
      fVar6 = fVar6 + _DAT_0099d104;
    }
    if ((*(uint *)(in_ECX + 0x30) < (uint)(int)ROUND(fVar5 / fVar6)) &&
       (*(char *)(in_ECX + 0x51) == '\x01')) {
      puVar8 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
      if (puVar8 == (undefined4 *)0x0) {
        FUN_00797a20(0);
        *(undefined1 *)(in_ECX + 0x50) = 0;
        return;
      }
      uVar2 = *(undefined4 *)(in_ECX + 0x24);
      uVar3 = *(undefined4 *)(in_ECX + 0x28);
      *puVar8 = &PTR_FUN_009c21b8;
      puVar8[1] = uVar3;
      puVar8[2] = uVar2;
      FUN_00797a20(puVar8);
      *(undefined1 *)(in_ECX + 0x50) = 0;
      return;
    }
  }
  *(undefined1 *)(in_ECX + 0x51) = 1;
  uVar7 = FUN_005cc260(iVar1);
  *(undefined1 *)(in_ECX + 0x51) = uVar7;
  uVar4 = *(uint *)(in_ECX + 0x2c);
  if (uVar4 != 0) {
    if ((uVar4 < *(uint *)(in_ECX + 0x38)) &&
       ((*(int *)(in_ECX + 0x30) == 0 ||
        (*(uint *)(in_ECX + 0x44) < uVar4 * *(int *)(in_ECX + 0x30))))) {
      FUN_005cc2b0();
      *(uint *)(in_ECX + 0x38) = *(uint *)(in_ECX + 0x38) % *(uint *)(in_ECX + 0x2c);
    }
    *(int *)(in_ECX + 0x44) = *(int *)(in_ECX + 0x44) + iVar1;
    *(int *)(in_ECX + 0x38) = *(int *)(in_ECX + 0x38) + iVar1;
    if ((((*(int *)(in_ECX + 200) == 1) || (*(int *)(in_ECX + 200) == 2)) &&
        (*(uint *)(in_ECX + 0x9c) < *(uint *)(in_ECX + 0x44))) && (*(char *)(in_ECX + 0xcc) != '\0')
       ) {
      *(undefined1 *)(in_ECX + 0xcc) = 0;
      FUN_005cc220();
    }
  }
  return;
}


// ==== FUN_005ba0f0 @ 0x005ba0f0 ====

undefined4 FUN_005ba0f0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float fVar6;
  float local_84;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  iVar3 = *(int *)(in_ECX + 0x108);
  iVar1 = *(int *)(in_ECX + 200);
  if (iVar1 == 4) {
    FUN_005b97b0(iVar3 + 4);
    return 1;
  }
  if (iVar1 == 1) {
    FUN_005b9950();
    return 0;
  }
  if (iVar1 == 2) {
    FUN_005b9ab0();
    return 0;
  }
  if (iVar1 != 3) {
    return 1;
  }
  fVar6 = DAT_0099d0f8;
  if (*(float *)(iVar3 + 0x1c) <= DAT_0099d0f8 && DAT_0099d0f8 != *(float *)(iVar3 + 0x1c)) {
    fVar6 = *(float *)(iVar3 + 0x1c);
    local_84 = DAT_0099d080;
    if (fVar6 < DAT_0099d080) goto LAB_005ba192;
  }
  local_84 = fVar6;
LAB_005ba192:
  uVar2 = FUN_005bab60(local_40,local_84,local_84,local_84);
  thunk_FUN_0079ee7b(local_80,uVar2,(undefined4 *)(in_ECX + 0x54));
  puVar4 = local_80 + -3;
  puVar5 = (undefined4 *)(in_ECX + 0x54);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  return 0;
}


// ==== FUN_005ba1d0 @ 0x005ba1d0 ====

void FUN_005ba1d0(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 0x30) == '\0') {
    return;
  }
  FUN_005b9fc0();
  return;
}


// ==== FUN_005ba1f0 @ 0x005ba1f0 ====

void FUN_005ba1f0(undefined4 *param_1,int param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 local_d4;
  float local_d0;
  undefined4 local_cc;
  int *local_c8;
  float local_c4;
  int local_c0 [16];
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  piVar7 = *(int **)(in_ECX + 0x108);
  local_c8 = piVar7;
  if (((piVar7 == (int *)0x0) || ((char)piVar7[2] == '\0')) || ((char)piVar7[4] == '\0')) {
    FUN_005cc220();
    goto LAB_005ba3cd;
  }
  if (*(char *)(in_ECX + 0xcc) == '\0') {
    local_d4 = 0;
    *(undefined4 *)(in_ECX + 0xbc) = 0;
    local_d0 = 0.0;
    *(undefined4 *)(in_ECX + 0xc0) = 0;
    local_cc = 0;
    *(undefined4 *)(in_ECX + 0xc4) = 0;
    piVar10 = (int *)(in_ECX + 0x54);
    iVar5 = *(int *)(in_ECX + 0xd0);
    piVar6 = piVar7 + 8;
    piVar8 = piVar10;
    for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
      *piVar8 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar8 = piVar8 + 1;
    }
    if (iVar5 != 0) {
      param_2 = *(int *)(in_ECX + 0xd4);
    }
    local_c4 = DAT_0099d080;
    if (DAT_0099d080 < (float)piVar7[7] || DAT_0099d080 == (float)piVar7[7]) {
      local_c4 = (float)piVar7[7];
    }
    if (param_2 != -1) {
      if (*(int *)(in_ECX + 0x48) == param_2) {
        local_d0 = local_c4 * DAT_0099d0f8;
        local_d4 = 0;
        local_cc = 0;
        puVar2 = (undefined4 *)FUN_005b1860(local_c0,&local_d4);
        puVar9 = local_80;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar9 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar9 = puVar9 + 1;
        }
      }
      else if (*(int *)(in_ECX + 0x4c) == param_2) {
        local_d4 = 0;
        local_cc = 0;
        local_d0 = local_c4;
        puVar2 = (undefined4 *)FUN_005b1860(local_c0,&local_d4);
        puVar9 = local_80;
        for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar9 = *puVar2;
          puVar2 = puVar2 + 1;
          puVar9 = puVar9 + 1;
        }
      }
      else {
        cVar1 = (**(code **)(*piVar7 + 8))(param_2,local_80);
        if (cVar1 == '\0') goto LAB_005ba370;
      }
      thunk_FUN_0079ee7b(local_c0,local_80,piVar10);
      piVar7 = local_c0;
      piVar6 = piVar10;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar6 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar6 = piVar6 + 1;
      }
    }
LAB_005ba370:
    if (*(int *)(in_ECX + 200) == 5) {
      uVar3 = FUN_005bab60(local_40,local_c4,local_c4,local_c4);
      thunk_FUN_0079ee7b(local_c0,uVar3,piVar10);
      piVar7 = local_c0;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar10 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar10 = piVar10 + 1;
      }
    }
  }
  else {
    cVar1 = FUN_005ba0f0(param_2);
    local_c8 = piVar7;
    if (cVar1 != '\0') goto LAB_005ba3cd;
  }
  *(int *)(in_ECX + 0x94) = local_c8[5];
  *(int *)(in_ECX + 0x98) = local_c8[6];
LAB_005ba3cd:
  puVar2 = (undefined4 *)(in_ECX + 0x54);
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_005ba3f0 @ 0x005ba3f0 ====

void FUN_005ba3f0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2208;
  in_ECX[8] = &PTR_FUN_009c21cc;
  if (in_ECX[0x42] != 0) {
    (**(code **)(*DAT_00b5afd4 + 0x10))(in_ECX[0x42]);
  }
  (**(code **)(*DAT_00b5afac + 8))(in_ECX[10],in_ECX[0x3b]);
  FUN_005cc540();
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    uVar1 = in_ECX[9];
    uVar2 = in_ECX[10];
    *puVar3 = &PTR_FUN_009c21b8;
    puVar3[1] = uVar2;
    puVar3[2] = uVar1;
  }
  FUN_00797a20(puVar3);
  if ((void *)in_ECX[0x37] == (void *)0x0) {
    in_ECX[0x37] = 0;
    in_ECX[0x38] = 0;
    in_ECX[0x39] = 0;
    in_ECX[8] = &PTR_FUN_009c217c;
    *in_ECX = &PTR_FUN_009bf514;
    return;
  }
  _free((void *)in_ECX[0x37]);
  return;
}


// ==== FUN_005ba4b0 @ 0x005ba4b0 ====

void FUN_005ba4b0(undefined1 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int in_ECX;
  uint uVar5;
  uint local_8;
  
  uVar5 = 0;
  local_8 = 0;
  if (*(int *)(in_ECX + 0xd0) != 0) {
    do {
      piVar4 = (int *)FUN_005cc2e0(*(int *)(param_1 + 4) << 0x10 | uVar5 + 1);
      if (piVar4 != (int *)0x0) {
        (**(code **)(*piVar4 + 8))(*param_1);
        cVar3 = (**(code **)(*piVar4 + 4))();
        if (cVar3 == '\0') {
          (**(code **)(*piVar4 + 0x34))();
        }
        else {
          (**(code **)(*piVar4 + 0x2c))(param_1,param_2,param_1);
          iVar2 = *(int *)(in_ECX + 0xdc);
          if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0xe0) - iVar2) / 0x1c) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
            FUN_0085b340();
          }
          puVar1 = (undefined4 *)(iVar2 + uVar5 * 0x1c);
          (**(code **)(*piVar4 + 0x10))(*puVar1,puVar1[1],puVar1[2]);
        }
      }
      local_8 = local_8 + 1;
      uVar5 = local_8 & 0xffff;
    } while (uVar5 < *(uint *)(in_ECX + 0xd0));
  }
  return;
}


// ==== FUN_005ba5b0 @ 0x005ba5b0 ====

void FUN_005ba5b0(void)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *in_ECX;
  void *local_20;
  void *local_1c;
  undefined1 local_18;
  uint uStack_c;
  uint local_8;
  undefined4 local_4;
  
  uVar1 = DAT_0099d080;
  in_ECX[8] = &PTR_FUN_009c217c;
  *in_ECX = &PTR_FUN_009c2208;
  in_ECX[8] = &PTR_FUN_009c21cc;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0xb] = 1;
  *(undefined1 *)((int)in_ECX + 0x51) = 1;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  *(undefined1 *)(in_ECX + 0x33) = 0;
  in_ECX[0x34] = 0;
  in_ECX[0x37] = 0;
  in_ECX[0x38] = 0;
  in_ECX[0x39] = 0;
  *(undefined1 *)(in_ECX + 0x3a) = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3d] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x3f] = 0;
  local_20 = (void *)0x0;
  *(undefined1 *)(in_ECX + 7) = 1;
  in_ECX[0x26] = 0;
  in_ECX[0x41] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x25] = uVar1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = 0;
  FUN_00401740(&DAT_009c2140,3);
  uVar1 = (**(code **)(*DAT_00b5a7e4 + 4))(&local_1c);
  in_ECX[0x12] = uVar1;
  if (0xf < local_8) {
    _free(local_1c);
    return;
  }
  local_8 = 0xf;
  uStack_c = 0;
  local_1c = (void *)((uint)local_1c & 0xffffff00);
  FUN_00401740(s_center_009c2144,6);
  uVar1 = (**(code **)(*DAT_00b5a7e4 + 4))(&local_20);
  in_ECX[0x13] = uVar1;
  if (0xf < uStack_c) {
    _free(local_20);
    return;
  }
  in_ECX[0x3b] = 4;
  pvVar2 = operator_new(0x28);
  if (pvVar2 == (void *)0x0) {
    in_ECX[0x40] = 0;
    return;
  }
  uVar1 = FUN_005cc400();
  in_ECX[0x40] = uVar1;
  return;
}


// ==== FUN_005ba790 @ 0x005ba790 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005ba790(undefined4 param_1,uint param_2,undefined4 *param_3,uint *param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  code *pcVar4;
  float fVar5;
  undefined4 uVar6;
  char ******ppppppcVar7;
  int in_ECX;
  char ******ppppppcVar8;
  undefined1 local_38 [4];
  void *local_34;
  undefined4 local_24;
  uint local_20;
  undefined1 local_1c [4];
  char ******local_18 [5];
  uint local_4;
  
  iVar2 = *(int *)(in_ECX + 0xe4);
  if (iVar2 != 0) {
    *(undefined1 *)(in_ECX + 0xac) = 0;
    *(undefined4 *)(in_ECX + 0xa8) = 0;
    *(undefined1 *)(in_ECX + 0x30) = 1;
    param_4 = (uint *)*param_4;
    if (param_4 == (uint *)0x0) {
      param_4 = (uint *)0x1;
    }
    *(uint **)(in_ECX + 0xc) = param_4;
    *(uint *)(in_ECX + 0x24) = param_2;
    *(uint *)(in_ECX + 0x14) = param_2;
    fVar5 = (float)(int)param_4;
    *(uint *)(in_ECX + 0x18) = param_2 % (uint)param_4;
    *(undefined4 *)(in_ECX + 0x10) = param_1;
    *(undefined4 *)(in_ECX + 0x1c) = *param_3;
    if ((int)param_4 < 0) {
      fVar5 = fVar5 + _DAT_0099d104;
    }
    fVar5 = fVar5 * DAT_0099d0ec;
    FUN_005babb0(&param_4,param_3);
    if (param_4 == (uint *)*(uint *)(iVar2 + 4)) {
      FUN_00401740(s_Scene____d_Effect_Play_Fail____009c214c,0x1f);
      FUN_00404230(local_1c);
      ppppppcVar8 = local_18[0];
      if (local_4 < 0x10) {
        ppppppcVar8 = (char ******)local_18;
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = (void *)((uint)local_34 & 0xffffff00);
      ppppppcVar7 = ppppppcVar8;
      do {
        cVar1 = *(char *)ppppppcVar7;
        ppppppcVar7 = (char ******)((int)ppppppcVar7 + 1);
      } while (cVar1 != '\0');
      FUN_00401740(ppppppcVar8,(int)ppppppcVar7 - (int)((int)ppppppcVar8 + 1));
      FUN_00796d50(local_38);
      if (0xf < local_20) {
        _free(local_34);
        return;
      }
      *(undefined1 *)(in_ECX + 0x30) = 0;
      if (0xf < local_4) {
        _free(local_18[0]);
        return;
      }
    }
    else {
      piVar3 = *(int **)((int)param_4 + 0x34);
      for (param_4 = *(uint **)((int)param_4 + 0x30); param_4 != (uint *)piVar3;
          param_4 = param_4 + 1) {
        iVar2 = *param_4;
        if (iVar2 == 0) {
          local_20 = 0xf;
          local_24 = 0;
          local_34 = (void *)((uint)local_34 & 0xffffff00);
          FUN_00401740(s_pControl_009c216c,8);
          FUN_00406880(local_38);
          if (local_20 < 0x10) {
            local_20 = 0xf;
            local_24 = 0;
            local_34 = (void *)((uint)local_34 & 0xffffff00);
            pcVar4 = (code *)swi(3);
            (*pcVar4)();
            return;
          }
          _free(local_34);
          return;
        }
        if (*(int *)(in_ECX + 0xb0) == 0) {
          FUN_005b96e0(iVar2,param_2,fVar5);
        }
        else {
          FUN_005ba4b0(iVar2,param_2,fVar5);
        }
      }
      *(undefined4 *)(in_ECX + 0x6c) = 0;
      *(undefined4 *)(in_ECX + 0x68) = 0;
      *(undefined4 *)(in_ECX + 100) = 0;
      *(undefined4 *)(in_ECX + 0x60) = 0;
      *(undefined4 *)(in_ECX + 0x58) = 0;
      *(undefined4 *)(in_ECX + 0x54) = 0;
      *(undefined4 *)(in_ECX + 0x50) = 0;
      *(undefined4 *)(in_ECX + 0x4c) = 0;
      *(undefined4 *)(in_ECX + 0x44) = 0;
      *(undefined4 *)(in_ECX + 0x40) = 0;
      *(undefined4 *)(in_ECX + 0x3c) = 0;
      *(undefined4 *)(in_ECX + 0x38) = 0;
      uVar6 = DAT_0099d080;
      *(undefined4 *)(in_ECX + 0x70) = DAT_0099d080;
      *(undefined4 *)(in_ECX + 0x5c) = uVar6;
      *(undefined4 *)(in_ECX + 0x48) = uVar6;
      *(undefined4 *)(in_ECX + 0x34) = uVar6;
    }
  }
  return;
}


// ==== FUN_005baa00 @ 0x005baa00 ====

/* WARNING: Removing unreachable block (ram,0x005baad4) */
/* WARNING: Removing unreachable block (ram,0x005baaec) */
/* WARNING: Removing unreachable block (ram,0x005baaff) */
/* WARNING: Removing unreachable block (ram,0x005baafb) */
/* WARNING: Removing unreachable block (ram,0x005bab17) */

undefined4 FUN_005baa00(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  undefined1 auStack_4a [22];
  int iStack_34;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = *param_2;
  *(undefined1 *)(in_ECX + 0xac) = 0;
  *(undefined4 *)(in_ECX + 0x20) = *param_3;
  piVar1 = (int *)(**(code **)(*DAT_00b5afd4 + 0xc))(*(undefined4 *)(in_ECX + 4));
  *(int **)(in_ECX + 0xe8) = piVar1;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  (**(code **)(*piVar1 + 4))(param_3,auStack_4a + -6);
  iVar2 = iStack_34 + -0xf >> 4;
  if (iVar2 == 0) {
    FUN_004bce20();
    return 1;
  }
  if (iVar2 == 0) {
                    /* WARNING: Subroutine does not return */
    FUN_00438a40();
  }
  FUN_00439790(0xf);
                    /* WARNING: Subroutine does not return */
  FUN_0042f370();
}


// ==== FUN_005bab60 @ 0x005bab60 ====

void FUN_005bab60(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 local_40 [16];
  
  thunk_FUN_0079f761(local_40,param_2,param_3,param_4);
  puVar2 = local_40;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_005baba0 @ 0x005baba0 ====

undefined4 FUN_005baba0(void)

{
  return 0x60010011;
}


// ==== FUN_005babb0 @ 0x005babb0 ====

void FUN_005babb0(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x3d) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x3d) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_005bac20 @ 0x005bac20 ====

undefined4 FUN_005bac20(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x20);
}


// ==== FUN_005bac30 @ 0x005bac30 ====

void FUN_005bac30(void)

{
  FUN_005bac40();
  return;
}


// ==== FUN_005bac40 @ 0x005bac40 ====

void FUN_005bac40(byte param_1)

{
  void *in_ECX;
  
  FUN_005ba3f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005bac60 @ 0x005bac60 ====

void FUN_005bac60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c222c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005bac80 @ 0x005bac80 ====

void FUN_005bac80(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005bac82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 8))();
  return;
}


// ==== FUN_005bac90 @ 0x005bac90 ====

void FUN_005bac90(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x3c) = param_1;
  return;
}


// ==== FUN_005baca0 @ 0x005baca0 ====

undefined4 FUN_005baca0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_005bacf0 @ 0x005bacf0 ====

undefined4 FUN_005bacf0(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) == '\0') {
    uVar1 = (**(code **)(*DAT_00b5affc + 4))(param_1,0);
    *(undefined4 *)(in_ECX + 8) = uVar1;
    uVar1 = (**(code **)(*DAT_00b5aff4 + 4))();
    *(undefined4 *)(in_ECX + 0xc) = uVar1;
    if (*(int **)(in_ECX + 8) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x14))(uVar1);
      *(undefined1 *)(in_ECX + 4) = 1;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005bad40 @ 0x005bad40 ====

void FUN_005bad40(void)

{
  int in_ECX;
  
  if (*(char *)(in_ECX + 4) != '\0') {
    (**(code **)(*DAT_00b5affc + 8))(*(undefined4 *)(in_ECX + 8));
    (**(code **)(*DAT_00b5aff4 + 8))(*(undefined4 *)(in_ECX + 0xc));
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005bad80 @ 0x005bad80 ====

void FUN_005bad80(float param_1,float param_2,undefined4 param_3,float param_4)

{
  byte bVar1;
  float fVar2;
  undefined4 in_EAX;
  uint3 uVar4;
  int iVar3;
  int in_ECX;
  float fVar5;
  float fVar6;
  
  fVar2 = DAT_0099d080;
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    bVar1 = *(byte *)(in_ECX + 0x3c);
    fVar6 = DAT_009c2224;
    if ((bVar1 != 0) && (fVar6 = DAT_009a09b8, bVar1 < 2)) {
      fVar6 = DAT_0099d0ec;
    }
    fVar5 = *(float *)(in_ECX + 0x34) - param_1;
    if (fVar5 <= 0.0) {
      fVar5 = 0.0 - fVar5;
    }
    if (fVar6 <= fVar5) {
      fVar6 = DAT_0099d080;
      if (param_1 <= DAT_0099d080) {
        fVar6 = param_1;
      }
      *(float *)(in_ECX + 0x34) = fVar6;
      param_2 = *(float *)(in_ECX + 0x38) + param_2;
      if (fVar2 < param_2) {
        param_2 = fVar2;
      }
      *(float *)(in_ECX + 0x38) = param_2;
      uVar4 = (uint3)(CONCAT22((short)((uint)in_EAX >> 0x10),
                               CONCAT11((param_4 == 0.0) << 6 | NAN(param_4) << 2 | 2U |
                                        param_4 < 0.0,bVar1)) >> 8);
      if (param_4 == 0.0) {
        iVar3 = (uint)uVar4 << 8;
      }
      else {
        iVar3 = CONCAT31(uVar4,1);
      }
      (**(code **)(**(int **)(in_ECX + 8) + 0x18))
                (in_ECX + 0x30,*(undefined4 *)(in_ECX + 0xc),0,iVar3);
    }
  }
  return;
}


// ==== FUN_005bae40 @ 0x005bae40 ====

void FUN_005bae40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2250;
  (*(code *)PTR_FUN_009c2258)();
  if ((uint)in_ECX[0xb] < 0x10) {
    in_ECX[0xb] = 0xf;
    in_ECX[10] = 0;
    *(undefined1 *)(in_ECX + 6) = 0;
    *in_ECX = &PTR_FUN_009c222c;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_005bae80 @ 0x005bae80 ====

void FUN_005bae80(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  FUN_00401740(&DAT_009c221e,0);
  *(undefined1 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  return;
}


// ==== FUN_005baec0 @ 0x005baec0 ====

void FUN_005baec0(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  if (in_ECX[2] != 0) {
    if (*(uint *)(param_1 + 0x18) < 0x10) {
      iVar1 = param_1 + 4;
    }
    else {
      iVar1 = *(int *)(param_1 + 4);
    }
    iVar1 = FUN_00403620(0,in_ECX[10],iVar1,*(undefined4 *)(param_1 + 0x14));
    if ((iVar1 != 0) || (in_ECX[0xc] == -1)) {
      if (in_ECX[0xc] != -1) {
        (**(code **)(*(int *)in_ECX[2] + 0x10))(in_ECX + 5);
      }
      iVar1 = (**(code **)(*(int *)in_ECX[2] + 0xc))(param_1);
      in_ECX[0xc] = iVar1;
      FUN_00401660(param_1,0,0xffffffff);
      in_ECX[0xe] = 0;
    }
    if ((char)in_ECX[4] == '\0') {
      in_ECX[0xe] = 0;
      return;
    }
    (**(code **)(*in_ECX + 0x18))(0,0x3f800000,0,0);
    *(undefined1 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005baf60 @ 0x005baf60 ====

void FUN_005baf60(void)

{
  undefined4 uVar1;
  int in_ECX;
  void *local_1c;
  undefined1 local_18;
  uint local_8;
  undefined4 local_4;
  
  if (*(int **)(in_ECX + 8) != (int *)0x0) {
    if (*(int *)(in_ECX + 0x30) != -1) {
      (**(code **)(**(int **)(in_ECX + 8) + 0x10))(in_ECX + 0x14);
    }
    local_4 = 0xf;
    local_8 = 0;
    local_18 = 0;
    FUN_00401740(&DAT_009c221f,0);
    uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0xc))(&local_1c);
    *(undefined4 *)(in_ECX + 0x30) = uVar1;
    if (0xf < local_8) {
      _free(local_1c);
      return;
    }
    FUN_00401740(&DAT_009c2220,0);
    *(undefined1 *)(in_ECX + 0x10) = 1;
  }
  return;
}


// ==== FUN_005bafe0 @ 0x005bafe0 ====

void FUN_005bafe0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2250;
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401740(&DAT_009c221e,0);
  *(undefined1 *)(in_ECX + 0xf) = 0;
  in_ECX[0xc] = 0xffffffff;
  in_ECX[0xe] = 0;
  return;
}


// ==== FUN_005bb030 @ 0x005bb030 ====

void FUN_005bb030(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2250;
  (*(code *)PTR_FUN_009c2258)();
  if (0xf < (uint)in_ECX[0xb]) {
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  *in_ECX = &PTR_FUN_009c222c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005bb080 @ 0x005bb080 ====

void FUN_005bb080(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2284;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005bb0a0 @ 0x005bb0a0 ====

int FUN_005bb0a0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return *(int *)(in_ECX + 8) - *(int *)(in_ECX + 4) >> 2;
}


// ==== FUN_005bb0c0 @ 0x005bb0c0 ====

void FUN_005bb0c0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  *in_ECX = param_1;
  in_ECX[1] = param_2;
  in_ECX[2] = param_3;
  in_ECX[3] = *param_4;
  in_ECX[4] = param_4[1];
  in_ECX[5] = param_4[2];
  in_ECX[6] = param_4[3];
  *(undefined1 *)(in_ECX + 7) = param_5;
  *(undefined1 *)((int)in_ECX + 0x1d) = 0;
  return;
}


// ==== FUN_005bb110 @ 0x005bb110 ====

void FUN_005bb110(void *param_1)

{
  if (*(char *)((int)param_1 + 0x1d) == '\0') {
    FUN_005bb110(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_005bb150 @ 0x005bb150 ====

void FUN_005bb150(void)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009828d0;
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


// ==== Catch@005bb1bf @ 0x005bb1bf ====

void Catch_005bb1bf(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005bb1e0 @ 0x005bb1e0 ====

void FUN_005bb1e0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009828e0;
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


// ==== Catch@005bb249 @ 0x005bb249 ====

void Catch_005bb249(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005bb260 @ 0x005bb260 ====

undefined4 * FUN_005bb260(undefined4 param_1)

{
  undefined4 *puVar1;
  char cVar2;
  int in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  puVar3 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar2 = *(char *)((int)puVar3 + 0x35);
  puVar1 = *(undefined4 **)(in_ECX + 4);
  while (cVar2 == '\0') {
    cVar2 = FUN_00415da0(puVar3 + 3,param_1);
    if (cVar2 == '\0') {
      puVar4 = (undefined4 *)*puVar3;
    }
    else {
      puVar4 = (undefined4 *)puVar3[2];
      puVar3 = puVar1;
    }
    puVar1 = puVar3;
    puVar3 = puVar4;
    cVar2 = *(char *)((int)puVar4 + 0x35);
  }
  return puVar1;
}


// ==== FUN_005bb2a0 @ 0x005bb2a0 ====

void * FUN_005bb2a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009828f0;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x20);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_005bb0c0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@005bb315 @ 0x005bb315 ====

void Catch_005bb315(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005bb330 @ 0x005bb330 ====

void FUN_005bb330(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982900;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x38);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 0xd) = 1;
  *(undefined1 *)((int)puVar1 + 0x35) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@005bb3ba @ 0x005bb3ba ====

void Catch_005bb3ba(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005bb3d0 @ 0x005bb3d0 ====

void FUN_005bb3d0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982910;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = operator_new(0x20);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
  }
  if (puVar1 + 1 != (undefined4 *)0x0) {
    puVar1[1] = 0;
  }
  if (puVar1 + 2 != (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  *(undefined1 *)(puVar1 + 7) = 1;
  *(undefined1 *)((int)puVar1 + 0x1d) = 0;
  ExceptionList = local_10;
  return;
}


// ==== Catch@005bb45a @ 0x005bb45a ====

void Catch_005bb45a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005bb470 @ 0x005bb470 ====

undefined1 FUN_005bb470(undefined4 *param_1,undefined4 *param_2,undefined1 param_3)

{
  void *_Memory;
  undefined1 extraout_AL;
  
  while( true ) {
    if (param_1 == param_2) {
      return param_3;
    }
    _Memory = (void *)*param_1;
    if (_Memory != (void *)0x0) break;
    param_1 = param_1 + 1;
  }
  FUN_005ccc00();
  _free(_Memory);
  return extraout_AL;
}


// ==== FUN_005bb4b0 @ 0x005bb4b0 ====

undefined4 FUN_005bb4b0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0x6c)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0x10);
}


// ==== FUN_005bb4e0 @ 0x005bb4e0 ====

int FUN_005bb4e0(void)

{
  int iVar1;
  int *piVar2;
  int *_Memory;
  int extraout_EAX;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) == 0) {
    iVar1 = *(int *)(in_ECX + 0x4c);
    *(int *)(in_ECX + 0x4c) = iVar1 + 1;
    return iVar1;
  }
  piVar2 = *(int **)(in_ECX + 0x44);
  _Memory = (int *)piVar2[1];
  if (_Memory == piVar2) {
    return *(int *)(piVar2[1] + 8);
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_005bb530 @ 0x005bb530 ====

void FUN_005bb530(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(in_ECX + 0x34);
  if ((iVar1 != 0) && (*(int *)(in_ECX + 0x38) - iVar1 >> 2 != 0)) {
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(int *)(in_ECX + 0x38) - iVar1 >> 2;
    }
    uVar3 = 0;
    if (uVar2 != 0) {
      do {
        if ((*(int *)(in_ECX + 0x34) == 0) ||
           ((uint)(*(int *)(in_ECX + 0x38) - *(int *)(in_ECX + 0x34) >> 2) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        FUN_005ccc60(param_1);
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
    }
  }
  if (*(int *)(in_ECX + 0x24) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 2;
  }
  uVar3 = 0;
  if (uVar2 != 0) {
    do {
      if ((*(int *)(in_ECX + 0x24) == 0) ||
         ((uint)(*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 2) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      FUN_005ccc60(param_1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}


// ==== FUN_005bb5f0 @ 0x005bb5f0 ====

void FUN_005bb5f0(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8 [8];
  
  local_10 = param_1;
  local_c = param_2;
  FUN_00458d90(local_8,&local_10);
  return;
}


// ==== FUN_005bb620 @ 0x005bb620 ====

void FUN_005bb620(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  uint uVar3;
  
  iVar1 = *(int *)(in_ECX + 0x34);
  if ((iVar1 != 0) && (*(int *)(in_ECX + 0x38) - iVar1 >> 2 != 0)) {
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(int *)(in_ECX + 0x38) - iVar1 >> 2;
    }
    uVar3 = 0;
    if (uVar2 != 0) {
      do {
        if ((*(int *)(in_ECX + 0x34) == 0) ||
           ((uint)(*(int *)(in_ECX + 0x38) - *(int *)(in_ECX + 0x34) >> 2) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        FUN_005ccf30(param_2,param_1);
        uVar3 = uVar3 + 1;
      } while (uVar3 < uVar2);
    }
  }
  if (*(int *)(in_ECX + 0x24) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 2;
  }
  uVar3 = 0;
  if (uVar2 != 0) {
    do {
      if ((*(int *)(in_ECX + 0x24) == 0) ||
         ((uint)(*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 2) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      FUN_005ccf30(param_2,param_1);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar2);
  }
  return;
}


// ==== FUN_005bb6e0 @ 0x005bb6e0 ====

void FUN_005bb6e0(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  int local_c;
  int local_8;
  int local_4;
  
  iVar2 = param_1;
  local_4 = in_ECX + 0x50;
  local_8 = in_ECX;
  param_1 = FUN_005bb260(param_1);
  if ((param_1 == *(uint *)(in_ECX + 0x54)) ||
     (cVar3 = FUN_00415da0(iVar2,param_1 + 0xc), cVar3 != '\0')) {
    local_c = *(int *)(in_ECX + 0x54);
    piVar4 = &local_c;
  }
  else {
    piVar4 = (int *)&param_1;
  }
  iVar2 = *piVar4;
  if (((iVar2 != *(int *)(in_ECX + 0x54)) && (*(int *)(iVar2 + 0x30) != 0)) &&
     (iVar5 = *(int *)(iVar2 + 0x30) + -1, *(int *)(iVar2 + 0x30) = iVar5, iVar5 == 0)) {
    puVar1 = (undefined4 *)(iVar2 + 0x2c);
    local_c = iVar2;
    FUN_00558e00(&param_1,puVar1);
    if (param_1 == *(uint *)(in_ECX + 0x60)) {
      if (*(int *)(iVar2 + 0x28) != 0) {
        param_1 = FUN_005bb0a0();
        uVar7 = 0;
        if (param_1 != 0) {
          do {
            if ((*(int *)(in_ECX + 0x24) == 0) ||
               ((uint)(*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 2) <= uVar7))
            goto LAB_005bb88b;
            FUN_005ccda0(*puVar1);
            uVar7 = uVar7 + 1;
          } while (uVar7 < param_1);
        }
        iVar2 = *(int *)(in_ECX + 0x34);
        if ((iVar2 != 0) && (param_1 = *(int *)(in_ECX + 0x38) - iVar2 >> 2, param_1 != 0)) {
          if (iVar2 == 0) {
            uVar7 = 0;
          }
          else {
            uVar7 = *(int *)(in_ECX + 0x38) - iVar2 >> 2;
          }
          uVar8 = 0;
          if (uVar7 != 0) {
            do {
              if ((*(int *)(in_ECX + 0x34) == 0) ||
                 ((uint)(*(int *)(in_ECX + 0x38) - *(int *)(in_ECX + 0x34) >> 2) <= uVar8)) {
LAB_005bb88b:
                    /* WARNING: Subroutine does not return */
                FUN_0085b340();
              }
              FUN_005ccda0(*puVar1);
              uVar8 = uVar8 + 1;
            } while (uVar8 < uVar7);
          }
          in_ECX = local_8;
        }
      }
    }
    else {
      FUN_004e1ac0(&param_1,param_1);
    }
    iVar2 = *(int *)(in_ECX + 0x44);
    iVar6 = FUN_005bb1e0(iVar2,*(undefined4 *)(iVar2 + 4),puVar1);
    FUN_00517200(1);
    iVar5 = local_c;
    *(int *)(iVar2 + 4) = iVar6;
    **(int **)(iVar6 + 4) = iVar6;
    if (*(int *)(local_c + 0x28) != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(local_c + 0x28));
      *(undefined4 *)(iVar5 + 0x28) = 0;
    }
    FUN_005bc520(&param_1,iVar5);
  }
  return;
}


// ==== FUN_005bb8a0 @ 0x005bb8a0 ====

undefined1 FUN_005bb8a0(undefined4 *param_1,undefined4 param_2,char param_3,char param_4)

{
  int iVar1;
  char cVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int local_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  FUN_00558e00(&local_54,param_1);
  iVar1 = local_54;
  if (local_54 != *(int *)(in_ECX + 0x60)) {
    cVar2 = (**(code **)(**(int **)(local_54 + 0x10) + 0x2c))();
    if (cVar2 == '\0') {
      return 0;
    }
    FUN_005bb620(*(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x10));
    FUN_004e1ac0(&local_54,iVar1);
  }
  iVar1 = *(int *)(in_ECX + 0x34);
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_30 = 0;
  local_38 = 0;
  local_3c = 0;
  local_40 = 0;
  local_44 = 0;
  local_c = DAT_0099d080;
  uStack_20 = DAT_0099d080;
  uStack_34 = DAT_0099d080;
  uStack_48 = DAT_0099d080;
  uStack_50 = param_1[1];
  uStack_4c = param_1[2];
  if (((iVar1 != 0) && (local_54 = *(int *)(in_ECX + 0x38) - iVar1 >> 2, local_54 != 0)) &&
     (param_3 != '\0')) {
    if (iVar1 == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(int *)(in_ECX + 0x38) - iVar1 >> 2;
    }
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        if ((*(int *)(in_ECX + 0x34) == 0) ||
           ((uint)(*(int *)(in_ECX + 0x38) - *(int *)(in_ECX + 0x34) >> 2) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        FUN_005cce10(*param_1,&uStack_50,&uStack_48,param_2);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
    }
  }
  if (((param_3 == '\0') || (*(int *)(in_ECX + 0x34) == 0)) ||
     ((local_54 = *(int *)(in_ECX + 0x38) - *(int *)(in_ECX + 0x34) >> 2, local_54 == 0 ||
      (param_4 != '\0')))) {
    if (*(int *)(in_ECX + 0x24) == 0) {
      uVar3 = 0;
    }
    else {
      uVar3 = *(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 2;
    }
    uVar4 = 0;
    if (uVar3 != 0) {
      do {
        if ((*(int *)(in_ECX + 0x24) == 0) ||
           ((uint)(*(int *)(in_ECX + 0x28) - *(int *)(in_ECX + 0x24) >> 2) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        FUN_005cce10(*param_1,&uStack_50,&uStack_48,param_2);
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar3);
    }
  }
  return 1;
}


// ==== FUN_005bba80 @ 0x005bba80 ====

void FUN_005bba80(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int local_30;
  uint local_2c;
  int local_24;
  uint local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  iVar7 = param_1;
  FUN_00402220(local_1c,param_1,&DAT_009c2274);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  FUN_00401660(iVar7,0,0xffffffff);
  uVar2 = FUN_005bc0f0(iVar7);
  if (uVar2 == 0) {
    return;
  }
  local_30 = 0;
  local_2c = 0;
  local_20 = uVar2;
  while( true ) {
    uVar8 = local_20;
    if ((*(int *)(uVar2 + 0x40) == 0) ||
       ((uint)((*(int *)(uVar2 + 0x44) - *(int *)(uVar2 + 0x40)) / 0x74) <= local_2c)) break;
    iVar7 = *(int *)(uVar2 + 0x40);
    if ((iVar7 == 0) || ((uint)((*(int *)(uVar2 + 0x44) - iVar7) / 0x74) <= local_2c))
    goto LAB_005bbd3e;
    pvVar3 = operator_new(0x110);
    if (pvVar3 == (void *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_005ccef0();
    }
    *(undefined1 *)(iVar4 + 0x10c) = 1;
    local_24 = iVar4;
    FUN_005cd040(iVar7 + local_30,0,in_ECX);
    iVar7 = *(int *)(in_ECX + 0x24);
    if ((iVar7 == 0) ||
       ((uint)(*(int *)(in_ECX + 0x2c) - iVar7 >> 2) <= (uint)(*(int *)(in_ECX + 0x28) - iVar7 >> 2)
       )) {
      FUN_005bc8c0(*(undefined4 *)(in_ECX + 0x28),1,&local_24);
    }
    else {
      piVar1 = *(int **)(in_ECX + 0x28);
      *piVar1 = iVar4;
      *(int **)(in_ECX + 0x28) = piVar1 + 1;
    }
    local_30 = local_30 + 0x74;
    local_2c = local_2c + 1;
    iVar7 = param_1;
  }
  if ((char)param_2 != '\0') {
    uVar5 = FUN_004022a0(local_1c,&PTR_LAB_009c227c,iVar7);
    uVar2 = FUN_005bc0f0(uVar5);
    local_20 = uVar2;
    if (0xf < local_4) {
      _free(local_18);
      return;
    }
    uVar6 = 0;
    local_4 = 0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    if (uVar2 != 0) {
      param_2 = 0;
      while( true ) {
        uVar8 = local_20;
        if ((*(int *)(uVar2 + 0x40) == 0) ||
           ((uint)((*(int *)(uVar2 + 0x44) - *(int *)(uVar2 + 0x40)) / 0x74) <= uVar6)) break;
        iVar7 = *(int *)(uVar2 + 0x40);
        local_2c = local_20;
        if ((iVar7 == 0) || ((uint)((*(int *)(uVar2 + 0x44) - iVar7) / 0x74) <= uVar6))
        goto LAB_005bbd3e;
        iVar7 = iVar7 + param_2;
        pvVar3 = operator_new(0x110);
        if (pvVar3 == (void *)0x0) {
          iVar4 = 0;
        }
        else {
          iVar4 = FUN_005ccef0();
        }
        *(undefined1 *)(iVar4 + 0x10c) = 1;
        param_1 = iVar4;
        FUN_005cd040(iVar7,0,in_ECX);
        iVar7 = *(int *)(in_ECX + 0x34);
        if ((iVar7 == 0) ||
           ((uint)(*(int *)(in_ECX + 0x3c) - iVar7 >> 2) <=
            (uint)(*(int *)(in_ECX + 0x38) - iVar7 >> 2))) {
          FUN_005bc8c0(*(undefined4 *)(in_ECX + 0x38),1,&param_1);
          uVar6 = uVar6 + 1;
          param_2 = param_2 + 0x74;
        }
        else {
          piVar1 = *(int **)(in_ECX + 0x38);
          *piVar1 = iVar4;
          uVar6 = uVar6 + 1;
          param_2 = param_2 + 0x74;
          *(int **)(in_ECX + 0x38) = piVar1 + 1;
        }
      }
    }
  }
LAB_005bbd46:
  (**(code **)(*DAT_00b5a7cc + 0x14))(uVar8);
  return;
LAB_005bbd3e:
  FUN_004cbea0();
  uVar8 = local_2c;
  goto LAB_005bbd46;
}


// ==== FUN_005bbd60 @ 0x005bbd60 ====

undefined4 FUN_005bbd60(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  int in_ECX;
  int *piVar5;
  int local_50;
  int local_4c [2];
  int *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 uStack_38;
  int *piStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 local_28 [4];
  void *local_24;
  undefined4 local_14;
  uint local_10;
  int *local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = param_1;
  local_50 = FUN_005bb260(param_1);
  if (local_50 != *(int *)(in_ECX + 0x54)) {
    cVar3 = FUN_00415da0(iVar2,local_50 + 0xc);
    if (cVar3 == '\0') {
      piVar5 = &local_50;
      goto LAB_005bbda1;
    }
  }
  local_4c[0] = *(int *)(in_ECX + 0x54);
  piVar5 = local_4c;
LAB_005bbda1:
  iVar1 = *piVar5;
  if (iVar1 != *(int *)(in_ECX + 0x54)) {
    *(int *)(iVar1 + 0x30) = *(int *)(iVar1 + 0x30) + 1;
    return *(undefined4 *)(iVar1 + 0x2c);
  }
  if (*(int *)(iVar2 + 0x14) == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = (int *)FUN_005bc150(iVar2);
  }
  local_44 = piVar5;
  uVar4 = FUN_005bb4e0();
  local_3c = 1;
  local_10 = 0xf;
  local_14 = 0;
  local_24 = (void *)((uint)local_24 & 0xffffff00);
  local_40 = uVar4;
  FUN_00401660(param_1,0,0xffffffff);
  local_4 = local_3c;
  local_c = piVar5;
  local_8 = uVar4;
  FUN_005bce40(local_4c,local_28);
  if (0xf < local_10) {
    _free(local_24);
    return extraout_EAX;
  }
  if (piVar5 != (int *)0x0) {
    FUN_00558e00(&param_1,&local_40);
    if (param_1 != *(int *)(in_ECX + 0x60)) {
      FUN_004e1ac0(&param_1,param_1);
    }
    cVar3 = (**(code **)(*piVar5 + 0x2c))();
    if (cVar3 == '\0') {
      uStack_2c = local_3c;
      uStack_38 = uVar4;
      piStack_34 = piVar5;
      uStack_30 = uVar4;
      FUN_005bc800(local_4c,&uStack_38);
      return uVar4;
    }
    FUN_005bb620(uVar4,piVar5);
  }
  return uVar4;
}


// ==== FUN_005bbed0 @ 0x005bbed0 ====

void FUN_005bbed0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009c22a8;
  FUN_005bc0a0(in_ECX + 8);
  FUN_005bc0a0(in_ECX + 0xc);
  FUN_00458e50(local_4,*(undefined4 *)in_ECX[0x1b],(undefined4 *)in_ECX[0x1b]);
  _free((void *)in_ECX[0x1b]);
  return;
}


// ==== FUN_005bbfe0 @ 0x005bbfe0 ====

void FUN_005bbfe0(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c22a8;
  in_ECX[7] = 0xf;
  in_ECX[6] = 0;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  uVar1 = FUN_005bb150();
  in_ECX[0x11] = uVar1;
  in_ECX[0x12] = 0;
  in_ECX[0x13] = 0;
  iVar2 = FUN_005bb330();
  in_ECX[0x15] = iVar2;
  *(undefined1 *)(iVar2 + 0x35) = 1;
  *(undefined4 *)(in_ECX[0x15] + 4) = in_ECX[0x15];
  *(undefined4 *)in_ECX[0x15] = in_ECX[0x15];
  *(undefined4 *)(in_ECX[0x15] + 8) = in_ECX[0x15];
  in_ECX[0x16] = 0;
  iVar2 = FUN_005bb3d0();
  in_ECX[0x18] = iVar2;
  *(undefined1 *)(iVar2 + 0x1d) = 1;
  *(undefined4 *)(in_ECX[0x18] + 4) = in_ECX[0x18];
  *(undefined4 *)in_ECX[0x18] = in_ECX[0x18];
  *(undefined4 *)(in_ECX[0x18] + 8) = in_ECX[0x18];
  in_ECX[0x19] = 0;
  iVar2 = FUN_0058d7c0();
  in_ECX[0x1b] = iVar2;
  *(undefined1 *)(iVar2 + 0x15) = 1;
  *(undefined4 *)(in_ECX[0x1b] + 4) = in_ECX[0x1b];
  *(undefined4 *)in_ECX[0x1b] = in_ECX[0x1b];
  *(undefined4 *)(in_ECX[0x1b] + 8) = in_ECX[0x1b];
  in_ECX[0x1c] = 0;
  return;
}


// ==== FUN_005bc0a0 @ 0x005bc0a0 ====

void FUN_005bc0a0(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1;
  iVar2 = *(int *)(param_1 + 4);
  if (iVar2 != 0) {
    piVar1 = (int *)(param_1 + 8);
    iVar4 = *piVar1 - iVar2;
    if (iVar4 >> 2 != 0) {
      param_1._1_3_ = (uint3)(iVar4 >> 10);
      param_1 = (uint)param_1._1_3_ << 8;
      FUN_005bb470(iVar2,*piVar1,param_1);
      if (*(void **)(iVar3 + 4) != (void *)0x0) {
        _free(*(void **)(iVar3 + 4));
        return;
      }
      *(undefined4 *)(iVar3 + 4) = 0;
      *(undefined4 *)(iVar3 + 8) = 0;
      *(undefined4 *)(iVar3 + 0xc) = 0;
    }
  }
  return;
}


// ==== FUN_005bc0f0 @ 0x005bc0f0 ====

undefined4 FUN_005bc0f0(undefined4 param_1)

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
  local_4 = 7;
  uVar2 = (**(code **)(*piVar1 + 8))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_005bc150 @ 0x005bc150 ====

undefined4 FUN_005bc150(undefined4 param_1)

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
  local_4 = 9;
  uVar2 = (**(code **)(*piVar1 + 0x10))(&local_20);
  if (local_c < 0x10) {
    return uVar2;
  }
  _free(local_20);
  return extraout_EAX;
}


// ==== FUN_005bc1b0 @ 0x005bc1b0 ====

void FUN_005bc1b0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0xffffffd < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_005bb2a0(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x1c);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x1c) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[7] == '\0') {
LAB_005bc2b5:
        *(undefined1 *)(*piVar5 + 0x1c) = 1;
        *(undefined1 *)(piVar6 + 7) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x1c) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_0046a370(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x1c) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1c) = 0;
        FUN_004e1270(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[7] == '\0') goto LAB_005bc2b5;
      if (piVar7 == (int *)*piVar2) {
        FUN_004e1270(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x1c) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x1c) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x1d) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x1c);
  } while( true );
}


// ==== FUN_005bc450 @ 0x005bc450 ====

void FUN_005bc450(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = param_2;
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  FUN_00401660(param_4,0,0xffffffff);
  in_ECX[10] = *(undefined4 *)(param_4 + 0x1c);
  in_ECX[0xb] = *(undefined4 *)(param_4 + 0x20);
  in_ECX[0xc] = *(undefined4 *)(param_4 + 0x24);
  *(undefined1 *)(in_ECX + 0xd) = param_5;
  *(undefined1 *)((int)in_ECX + 0x35) = 0;
  return;
}


// ==== FUN_005bc4c0 @ 0x005bc4c0 ====

void FUN_005bc4c0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x35) != '\0') {
    return;
  }
  FUN_005bc4c0(*(undefined4 *)((int)param_1 + 8));
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


// ==== FUN_005bc520 @ 0x005bc520 ====

/* WARNING: Removing unreachable block (ram,0x005bc639) */
/* WARNING: Removing unreachable block (ram,0x005bc64a) */
/* WARNING: Removing unreachable block (ram,0x005bc653) */
/* WARNING: Removing unreachable block (ram,0x005bc656) */
/* WARNING: Removing unreachable block (ram,0x005bc646) */
/* WARNING: Removing unreachable block (ram,0x005bc664) */
/* WARNING: Removing unreachable block (ram,0x005bc671) */
/* WARNING: Removing unreachable block (ram,0x005bc67c) */
/* WARNING: Removing unreachable block (ram,0x005bc678) */
/* WARNING: Removing unreachable block (ram,0x005bc66c) */
/* WARNING: Removing unreachable block (ram,0x005bc67f) */

void FUN_005bc520(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x35) != '\0') {
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
  FUN_00411640();
  piVar6 = (int *)*param_2;
  if (*(char *)((int)piVar6 + 0x35) == '\0') {
    if (*(char *)(param_2[2] + 0x35) == '\0') {
      piVar6 = (int *)param_2[2];
    }
  }
  else {
    piVar6 = (int *)param_2[2];
  }
  piVar5 = (int *)param_2[1];
  if (*(char *)((int)piVar6 + 0x35) == '\0') {
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
    if (*(char *)((int)piVar6 + 0x35) == '\0') {
      piVar3 = (int *)FUN_0087c940(piVar6);
    }
    else {
      piVar3 = piVar5;
    }
    *puVar1 = piVar3;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (*(int **)(iVar2 + 8) == param_2) {
    if (*(char *)((int)piVar6 + 0x35) == '\0') {
      uVar4 = FUN_00868480(piVar6);
      *(undefined4 *)(iVar2 + 8) = uVar4;
    }
    else {
      *(int **)(iVar2 + 8) = piVar5;
    }
  }
  if ((char)param_2[0xd] == '\x01') {
    if (piVar6 != *(int **)(*(int *)(in_ECX + 4) + 4)) {
      do {
        piVar3 = piVar5;
        if ((char)piVar6[0xd] != '\x01') break;
        piVar5 = (int *)*piVar3;
        if (piVar6 == piVar5) {
          piVar5 = (int *)piVar3[2];
          if ((char)piVar5[0xd] == '\0') {
            *(undefined1 *)(piVar5 + 0xd) = 1;
            *(undefined1 *)(piVar3 + 0xd) = 0;
            FUN_008685b0(piVar3);
            piVar5 = (int *)piVar3[2];
          }
          if (*(char *)((int)piVar5 + 0x35) == '\0') {
            if ((*(char *)(*piVar5 + 0x34) == '\x01') && (*(char *)(piVar5[2] + 0x34) == '\x01'))
            goto LAB_005bc754;
            if (*(char *)(piVar5[2] + 0x34) == '\x01') {
              *(undefined1 *)(*piVar5 + 0x34) = 1;
              *(undefined1 *)(piVar5 + 0xd) = 0;
              FUN_00868600(piVar5);
              piVar5 = (int *)piVar3[2];
            }
            *(char *)(piVar5 + 0xd) = (char)piVar3[0xd];
            *(undefined1 *)(piVar3 + 0xd) = 1;
            *(undefined1 *)(piVar5[2] + 0x34) = 1;
            FUN_008685b0(piVar3);
            break;
          }
        }
        else {
          if ((char)piVar5[0xd] == '\0') {
            *(undefined1 *)(piVar5 + 0xd) = 1;
            *(undefined1 *)(piVar3 + 0xd) = 0;
            FUN_00868600(piVar3);
            piVar5 = (int *)*piVar3;
          }
          if (*(char *)((int)piVar5 + 0x35) == '\0') {
            if ((*(char *)(piVar5[2] + 0x34) != '\x01') || (*(char *)(*piVar5 + 0x34) != '\x01')) {
              if (*(char *)(*piVar5 + 0x34) == '\x01') {
                *(undefined1 *)(piVar5[2] + 0x34) = 1;
                *(undefined1 *)(piVar5 + 0xd) = 0;
                FUN_008685b0(piVar5);
                piVar5 = (int *)*piVar3;
              }
              *(char *)(piVar5 + 0xd) = (char)piVar3[0xd];
              *(undefined1 *)(piVar3 + 0xd) = 1;
              *(undefined1 *)(*piVar5 + 0x34) = 1;
              FUN_00868600(piVar3);
              break;
            }
LAB_005bc754:
            *(undefined1 *)(piVar5 + 0xd) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xd) = 1;
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


// ==== FUN_005bc800 @ 0x005bc800 ====

void FUN_005bc800(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x1d) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x1d) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_005bc1b0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0046a3c0();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_005bc1b0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_005bc8c0 @ 0x005bc8c0 ====

void FUN_005bc8c0(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982920;
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


// ==== Catch@005bca21 @ 0x005bca21 ====

void Catch_005bca21(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005bcb10 @ 0x005bcb10 ====

void * FUN_005bcb10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982930;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x38);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_005bc450(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@005bcb85 @ 0x005bcb85 ====

void Catch_005bcb85(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005bcba0 @ 0x005bcba0 ====

void FUN_005bcba0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  
  if (0x6666664 < *(uint *)(in_ECX + 8)) {
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
  piVar4 = (int *)FUN_005bcb10(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
  cVar1 = *(char *)(piVar4[1] + 0x34);
  piVar7 = piVar4;
  do {
    if (cVar1 != '\0') {
      *(undefined1 *)(*(int *)(*(int *)(in_ECX + 4) + 4) + 0x34) = 1;
      *param_1 = piVar4;
      return;
    }
    piVar5 = piVar7 + 1;
    piVar2 = (int *)*piVar5;
    piVar6 = *(int **)piVar2[1];
    if (piVar2 == piVar6) {
      piVar6 = (int *)((undefined4 *)piVar2[1])[2];
      if ((char)piVar6[0xd] == '\0') {
LAB_005bcca5:
        *(undefined1 *)(*piVar5 + 0x34) = 1;
        *(undefined1 *)(piVar6 + 0xd) = 1;
        *(undefined1 *)(*(int *)(*piVar5 + 4) + 0x34) = 0;
        piVar7 = *(int **)(*piVar5 + 4);
      }
      else {
        if (piVar7 == (int *)piVar2[2]) {
          FUN_008685b0(piVar2);
          piVar7 = piVar2;
        }
        *(undefined1 *)(piVar7[1] + 0x34) = 1;
        *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x34) = 0;
        FUN_00868600(*(undefined4 *)(piVar7[1] + 4));
      }
    }
    else {
      if ((char)piVar6[0xd] == '\0') goto LAB_005bcca5;
      if (piVar7 == (int *)*piVar2) {
        FUN_00868600(piVar2);
        piVar7 = piVar2;
      }
      *(undefined1 *)(piVar7[1] + 0x34) = 1;
      *(undefined1 *)(*(int *)(piVar7[1] + 4) + 0x34) = 0;
      iVar3 = *(int *)(piVar7[1] + 4);
      piVar2 = *(int **)(iVar3 + 8);
      *(int *)(iVar3 + 8) = *piVar2;
      if (*(char *)(*piVar2 + 0x35) == '\0') {
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
    cVar1 = *(char *)(piVar7[1] + 0x34);
  } while( true );
}


// ==== FUN_005bce40 @ 0x005bce40 ====

void FUN_005bce40(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  char cVar3;
  char cVar4;
  undefined4 *puVar5;
  int in_ECX;
  undefined4 *puVar6;
  
  uVar2 = param_2;
  puVar5 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar3 = '\x01';
  cVar4 = *(char *)((int)puVar5 + 0x35);
  puVar1 = *(undefined4 **)(in_ECX + 4);
  while (cVar4 == '\0') {
    cVar3 = FUN_00415da0(uVar2,puVar5 + 3);
    if (cVar3 == '\0') {
      puVar6 = (undefined4 *)puVar5[2];
    }
    else {
      puVar6 = (undefined4 *)*puVar5;
    }
    puVar1 = puVar5;
    puVar5 = puVar6;
    cVar4 = *(char *)((int)puVar6 + 0x35);
  }
  param_2 = puVar1;
  if (cVar3 != '\0') {
    if (puVar1 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar5 = (undefined4 *)FUN_005bcba0(&param_2,1,puVar1,uVar2);
      *param_1 = *puVar5;
      *(undefined1 *)(param_1 + 1) = 1;
      return;
    }
    FUN_00885cd0();
  }
  puVar5 = param_2;
  cVar4 = FUN_00415da0(param_2 + 3,uVar2);
  if (cVar4 == '\0') {
    *param_1 = puVar5;
    *(undefined1 *)(param_1 + 1) = 0;
    return;
  }
  puVar5 = (undefined4 *)FUN_005bcba0(&param_2,cVar3,puVar1,uVar2);
  *param_1 = *puVar5;
  *(undefined1 *)(param_1 + 1) = 1;
  return;
}


// ==== FUN_005bcf10 @ 0x005bcf10 ====

void FUN_005bcf10(byte param_1)

{
  void *in_ECX;
  
  FUN_005bbed0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005bcf30 @ 0x005bcf30 ====

void FUN_005bcf30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c22d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005bcf50 @ 0x005bcf50 ====

void FUN_005bcf50(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + 0x34);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    if (*(int *)(in_ECX + 0x38) != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x38));
      *(undefined4 *)(in_ECX + 0x38) = 0;
    }
    *(undefined1 *)(in_ECX + 0x30) = 0;
  }
  return;
}


// ==== FUN_005bcf80 @ 0x005bcf80 ====

int FUN_005bcf80(void)

{
  int iVar1;
  char cVar2;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x30) == '\0') && (*(int **)(in_ECX + 0x38) != (int *)0x0)) {
    cVar2 = (**(code **)(**(int **)(in_ECX + 0x38) + 0x2c))();
    if (cVar2 != '\0') {
      iVar1 = *(int *)(in_ECX + 0x38);
      *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(iVar1 + 0x58);
      *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(iVar1 + 0x5c);
      *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(iVar1 + 0x60);
      *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(iVar1 + 100);
      *(undefined1 *)(in_ECX + 0x30) = 1;
    }
  }
  return in_ECX + 4;
}


// ==== FUN_005bcfc0 @ 0x005bcfc0 ====

void FUN_005bcfc0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c22ec;
  if ((uint)in_ECX[0xb] < 0x10) {
    in_ECX[0xb] = 0xf;
    in_ECX[10] = 0;
    *(undefined1 *)(in_ECX + 6) = 0;
    *in_ECX = &PTR_FUN_009c22d4;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_005bd000 @ 0x005bd000 ====

void FUN_005bd000(float *param_1,float param_2)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  int in_ECX;
  float fVar6;
  float fVar7;
  float fVar8;
  int local_10 [2];
  float local_8;
  float local_4;
  
  if (*(char *)(in_ECX + 0x30) != '\0') {
LAB_005bd03b:
    iVar3 = *(int *)(in_ECX + 0x38);
    local_8 = param_2;
    local_4 = param_2;
    FUN_005bd240(local_10,&local_8);
    iVar4 = local_10[0];
    iVar3 = *(int *)(iVar3 + 0x6c);
    if (local_10[0] == iVar3) {
      *param_1 = 0.0;
      param_1[1] = 0.0;
      return;
    }
    pfVar1 = (float *)(local_10[0] + 0x14);
    FUN_004dde50();
    if ((local_10[0] != iVar3) &&
       (fVar6 = *(float *)(local_10[0] + 0x14) - *pfVar1, DAT_009c22cc <= fVar6)) {
      fVar2 = *(float *)(local_10[0] + 0x1c);
      fVar6 = (param_2 - *pfVar1) / fVar6;
      fVar7 = *(float *)(iVar4 + 0x1c);
      fVar8 = DAT_0099d080 - fVar6;
      *param_1 = fVar8 * *(float *)(iVar4 + 0x18) + *(float *)(local_10[0] + 0x18) * fVar6;
      param_1[1] = fVar7 * fVar8 + fVar2 * fVar6;
      return;
    }
    *param_1 = *(float *)(iVar4 + 0x18);
    param_1[1] = *(float *)(iVar4 + 0x1c);
    return;
  }
  if (*(int **)(in_ECX + 0x38) != (int *)0x0) {
    cVar5 = (**(code **)(**(int **)(in_ECX + 0x38) + 0x2c))();
    if (cVar5 != '\0') {
      iVar3 = *(int *)(in_ECX + 0x38);
      *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(iVar3 + 0x58);
      *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(iVar3 + 0x5c);
      *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(iVar3 + 0x60);
      *(undefined4 *)(in_ECX + 0x10) = *(undefined4 *)(iVar3 + 100);
      *(undefined1 *)(in_ECX + 0x30) = 1;
      goto LAB_005bd03b;
    }
  }
  fVar6 = *(float *)(in_ECX + 0x10);
  fVar2 = *(float *)(in_ECX + 8);
  fVar7 = DAT_0099d080 - param_2;
  *param_1 = *(float *)(in_ECX + 4) * fVar7 + *(float *)(in_ECX + 0xc) * param_2;
  param_1[1] = fVar2 * fVar7 + fVar6 * param_2;
  return;
}


// ==== FUN_005bd190 @ 0x005bd190 ====

void FUN_005bd190(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c22ec;
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  return;
}


// ==== FUN_005bd1b0 @ 0x005bd1b0 ====

void FUN_005bd1b0(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + 1;
  if (*(char *)(in_ECX + 0x30) != '\x01') {
    if (*(int *)(in_ECX + 0x28) == 0) {
      *(undefined4 *)(in_ECX + 0x38) = 0;
      return;
    }
    if (*(int *)(in_ECX + 0x34) == 1) {
      uVar1 = FUN_005bc150(in_ECX + 0x14);
      *(undefined4 *)(in_ECX + 0x38) = uVar1;
    }
  }
  return;
}


// ==== FUN_005bd1f0 @ 0x005bd1f0 ====

void FUN_005bd1f0(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  FUN_00401660(param_1 + 4,0,0xffffffff);
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  return;
}


// ==== FUN_005bd240 @ 0x005bd240 ====

void FUN_005bd240(undefined4 *param_1,float *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar1 = *(char *)((int)puVar4 + 0x21);
  puVar2 = *(undefined4 **)(in_ECX + 4);
  while (cVar1 == '\0') {
    if ((*param_2 < (float)puVar4[3] || *param_2 == (float)puVar4[3]) ||
       (param_2[1] < (float)puVar4[4] || param_2[1] == (float)puVar4[4])) {
      puVar3 = (undefined4 *)*puVar4;
    }
    else {
      puVar3 = (undefined4 *)puVar4[2];
      puVar4 = puVar2;
    }
    puVar2 = puVar4;
    puVar4 = puVar3;
    cVar1 = *(char *)((int)puVar3 + 0x21);
  }
  if ((puVar2 != *(undefined4 **)(in_ECX + 4)) &&
     (((float)puVar2[3] < *param_2 || (float)puVar2[3] == *param_2 ||
      ((float)puVar2[4] < param_2[1] || (float)puVar2[4] == param_2[1])))) {
    *param_1 = puVar2;
    return;
  }
  *param_1 = *(undefined4 **)(in_ECX + 4);
  return;
}


// ==== FUN_005bd2c0 @ 0x005bd2c0 ====

void FUN_005bd2c0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c22ec;
  if (0xf < (uint)in_ECX[0xb]) {
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[0xb] = 0xf;
  in_ECX[10] = 0;
  *(undefined1 *)(in_ECX + 6) = 0;
  *in_ECX = &PTR_FUN_009c22d4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005bd310 @ 0x005bd310 ====

void FUN_005bd310(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2338;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005bd330 @ 0x005bd330 ====

void FUN_005bd330(void *param_1)

{
  if (*(char *)((int)param_1 + 0x15) == '\0') {
    FUN_005bd330(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_005bd370 @ 0x005bd370 ====

void * FUN_005bd370(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982940;
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


// ==== Catch@005bd3e5 @ 0x005bd3e5 ====

void Catch_005bd3e5(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005bd400 @ 0x005bd400 ====

void FUN_005bd400(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982950;
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


// ==== Catch@005bd48a @ 0x005bd48a ====

void Catch_005bd48a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005bd4a0 @ 0x005bd4a0 ====

undefined4 FUN_005bd4a0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0x10);
}


// ==== FUN_005bd4d0 @ 0x005bd4d0 ====

undefined4 FUN_005bd4d0(undefined1 param_1)

{
  int in_ECX;
  int local_4;
  
  local_4 = in_ECX;
  FUN_0079bba0(&local_4,&param_1);
  if (local_4 == *(int *)(in_ECX + 0xc)) {
    return 0;
  }
  return *(undefined4 *)(local_4 + 0x10);
}


// ==== FUN_005bd500 @ 0x005bd500 ====

undefined4 FUN_005bd500(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x10) == 0) {
    return 0;
  }
  iVar1 = **(int **)(in_ECX + 0xc);
  *(int *)(in_ECX + 4) = iVar1;
  return *(undefined4 *)(iVar1 + 0x10);
}


// ==== FUN_005bd520 @ 0x005bd520 ====

int * FUN_005bd520(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int in_ECX;
  
  piVar6 = (int *)(**(code **)(*DAT_00b5aff4 + 4))();
  puVar2 = *(undefined4 **)(in_ECX + 0xc);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    (**(code **)(*piVar6 + 4))(puVar3[4]);
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
        puVar5 = (undefined4 *)puVar3[1];
        puVar4 = puVar3;
        while ((puVar3 = puVar5, cVar1 == '\0' && (puVar4 == (undefined4 *)puVar3[2]))) {
          cVar1 = *(char *)((int)puVar3[1] + 0x15);
          puVar5 = (undefined4 *)puVar3[1];
          puVar4 = puVar3;
        }
      }
    }
  }
  return piVar6;
}


// ==== FUN_005bd5a0 @ 0x005bd5a0 ====

void FUN_005bd5a0(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 local_2c [4];
  char local_28;
  undefined4 local_24;
  undefined4 *local_20;
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_Node__FACTORY___>Create___009c2304,0x19);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  puVar2 = (undefined4 *)FUN_005bda10();
  puVar1 = param_1;
  puVar5 = param_1;
  puVar6 = puVar2;
  for (iVar4 = 0x48; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_m_mapNode_insert_009c2320,0x10);
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_24 = *puVar1;
  local_20 = puVar2;
  FUN_005bdac0(local_2c,&local_24);
  if (local_28 == '\0') {
    iVar4 = *(int *)(DAT_00b5a9d4 + 8);
    param_1 = puVar2;
    iVar3 = FUN_00595920(iVar4,*(undefined4 *)(iVar4 + 4),&param_1);
    FUN_00517200(1);
    *(int *)(iVar4 + 4) = iVar3;
    **(int **)(iVar3 + 4) = iVar3;
  }
  return;
}


// ==== FUN_005bd6a0 @ 0x005bd6a0 ====

void FUN_005bd6a0(void)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  void *_Memory;
  int *piVar4;
  int iVar5;
  int in_ECX;
  int *piVar6;
  int *piVar7;
  int local_c;
  int *local_8;
  int local_4;
  
  piVar6 = *(int **)(in_ECX + 0xc);
  piVar7 = (int *)*piVar6;
  local_8 = piVar6;
  local_4 = in_ECX;
  if (piVar7 != piVar6) {
    do {
      local_c = piVar7[4];
      if (local_c != 0) {
        iVar2 = *(int *)(DAT_00b5a9d4 + 8);
        iVar5 = FUN_00595920(iVar2,*(undefined4 *)(iVar2 + 4),&local_c);
        FUN_00517200(1);
        *(int *)(iVar2 + 4) = iVar5;
        **(int **)(iVar5 + 4) = iVar5;
        piVar6 = local_8;
      }
      if (*(char *)((int)piVar7 + 0x15) == '\0') {
        piVar3 = (int *)piVar7[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar1 = *(char *)(*piVar3 + 0x15);
          piVar7 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar3 + 0x15);
            piVar7 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar1 = *(char *)(piVar7[1] + 0x15);
          piVar4 = (int *)piVar7[1];
          piVar3 = piVar7;
          while ((piVar7 = piVar4, cVar1 == '\0' && (piVar3 == (int *)piVar7[2]))) {
            cVar1 = *(char *)(piVar7[1] + 0x15);
            piVar4 = (int *)piVar7[1];
            piVar3 = piVar7;
          }
        }
      }
    } while (piVar7 != piVar6);
    in_ECX = local_4;
  }
  _Memory = *(void **)(*(int *)(in_ECX + 0xc) + 4);
  if (*(char *)((int)_Memory + 0x15) == '\0') {
    FUN_005bd330(*(undefined4 *)((int)_Memory + 8));
    _free(_Memory);
    return;
  }
  *(int *)(*(int *)(in_ECX + 0xc) + 4) = *(int *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)*(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0xc);
  *(int *)(*(int *)(in_ECX + 0xc) + 8) = *(int *)(in_ECX + 0xc);
  return;
}


// ==== FUN_005bd7a0 @ 0x005bd7a0 ====

void FUN_005bd7a0(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2390;
  in_ECX[1] = 0;
  iVar1 = FUN_005bd400();
  in_ECX[3] = iVar1;
  *(undefined1 *)(iVar1 + 0x15) = 1;
  *(undefined4 *)(in_ECX[3] + 4) = in_ECX[3];
  *(undefined4 *)in_ECX[3] = in_ECX[3];
  *(undefined4 *)(in_ECX[3] + 8) = in_ECX[3];
  in_ECX[4] = 0;
  return;
}


// ==== FUN_005bd830 @ 0x005bd830 ====

void FUN_005bd830(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_005bd370(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_005bd935:
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
      if ((char)piVar6[5] == '\0') goto LAB_005bd935;
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


// ==== FUN_005bda10 @ 0x005bda10 ====

/* WARNING: Removing unreachable block (ram,0x005bda76) */
/* WARNING: Removing unreachable block (ram,0x005bda44) */

void * FUN_005bda10(void)

{
  int *piVar1;
  int *_Memory;
  void *pvVar2;
  void *extraout_EAX;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xc) == 0) {
    FUN_00401740(s_T___pNew___new_T_009c2378,0x12);
    pvVar2 = operator_new(0x120);
    return pvVar2;
  }
  FUN_00401740(s_T___pItem___m_listItem_back___009c2354,0x20);
  piVar1 = *(int **)(in_ECX + 8);
  _Memory = (int *)piVar1[1];
  if (_Memory == piVar1) {
    return *(void **)(piVar1[1] + 8);
  }
  *(int *)_Memory[1] = *_Memory;
  *(int *)(*_Memory + 4) = _Memory[1];
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_005bdac0 @ 0x005bdac0 ====

void FUN_005bdac0(undefined4 *param_1,uint *param_2)

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
      puVar4 = (undefined4 *)FUN_005bd830(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0058d720();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_005bd830(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_005bdb80 @ 0x005bdb80 ====

void FUN_005bdb80(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_005bd330(piVar6[1]);
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


// ==== FUN_005bdc40 @ 0x005bdc40 ====

void FUN_005bdc40(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009c2390;
  FUN_005bd6a0();
  FUN_005bdb80(local_4,*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_005bdca0 @ 0x005bdca0 ====

void FUN_005bdca0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c23b0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005bdcc0 @ 0x005bdcc0 ====

void FUN_005bdcc0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_3 = *param_1;
    param_1 = param_1 + 1;
    param_3 = param_3 + 1;
  }
  return;
}


// ==== FUN_005bdce0 @ 0x005bdce0 ====

float10 FUN_005bdce0(float *param_1)

{
  return (float10)*param_1;
}


// ==== FUN_005bdcf0 @ 0x005bdcf0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005bdcf0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c23c4;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b004 = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b004 = in_ECX;
  return;
}


// ==== FUN_005bdd40 @ 0x005bdd40 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005bdd40(byte param_1)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b004 = 0;
  *in_ECX = &PTR_FUN_009c23b0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005bdd70 @ 0x005bdd70 ====

void FUN_005bdd70(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_3;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  param_3[6] = *(undefined4 *)(in_ECX + 4);
  return;
}


// ==== FUN_005bdd90 @ 0x005bdd90 ====

float10 FUN_005bdd90(float *param_1)

{
  return (float10)*param_1;
}


// ==== FUN_005bdda0 @ 0x005bdda0 ====

void FUN_005bdda0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c23d8;
  in_ECX[1] = 0;
  if (in_ECX + 1 == (undefined4 *)0x0) {
    DAT_00b5b008 = (undefined4 *)0x0;
    return;
  }
  DAT_00b5b008 = in_ECX;
  return;
}


// ==== FUN_005bddf0 @ 0x005bddf0 ====

void FUN_005bddf0(float param_1)

{
  int in_ECX;
  
  *(float *)(in_ECX + 4) = param_1 + *(float *)(in_ECX + 4);
  return;
}


// ==== FUN_005bde10 @ 0x005bde10 ====

void FUN_005bde10(byte param_1)

{
  undefined4 *in_ECX;
  
  DAT_00b5b008 = 0;
  *in_ECX = &PTR_FUN_009c23b0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005bde90 @ 0x005bde90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005bde90(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c2414;
  if (in_ECX == (undefined4 *)0xfffffffc) {
    _DAT_00b5b00c = (undefined4 *)0x0;
    return;
  }
  _DAT_00b5b00c = in_ECX;
  return;
}


// ==== FUN_005bdec0 @ 0x005bdec0 ====

float10 FUN_005bdec0(float param_1,float param_2,float param_3)

{
  float10 fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  if (DAT_0099d080 <= param_2) goto LAB_005bdfb5;
  if (param_3 <= DAT_0099d0e4) {
    fVar2 = DAT_009a09b8;
    if (DAT_009a09b8 <= param_3) goto LAB_005bdeff;
  }
  else {
    param_3 = DAT_0099d0e4;
LAB_005bdeff:
    fVar2 = param_3;
  }
  fVar2 = DAT_0099d0b4 - fVar2 * DAT_0099d0b4;
  fVar3 = fVar2 * DAT_0099d0f8 - DAT_0099d0b4;
  fVar2 = DAT_0099d0f8 - fVar2 * DAT_009b0ec8;
  if (param_1 <= DAT_0099d080) {
    param_3 = 0.0;
    if (0.0 <= param_1) goto LAB_005bdf60;
  }
  else {
    param_1 = DAT_0099d080;
LAB_005bdf60:
    param_3 = param_1;
  }
  fVar4 = DAT_0099d080 / fVar2;
  fVar1 = (float10)FUN_0040d540((fVar3 * fVar3) / (fVar2 * fVar2) + fVar4 * param_3);
  fVar1 = fVar1 - (float10)fVar4 * (float10)fVar3;
  if ((float10)param_2 < fVar1) {
    param_2 = (float)fVar1 - param_2;
    fVar2 = (param_2 * fVar2 + fVar3 * DAT_0099d0f8) * param_2;
    if (param_3 < fVar2) {
      fVar2 = param_3;
    }
    param_2 = 0.0;
    if (0.0 <= fVar2) {
      param_2 = fVar2;
    }
    return (float10)param_2;
  }
LAB_005bdfb5:
  return (float10)DAT_0099cdc8;
}


// ==== FUN_005be040 @ 0x005be040 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005be040(float *param_1,float *param_2,float *param_3)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  float *pfVar4;
  float10 fVar5;
  
  pfVar2 = param_2;
  fVar3 = (float)(**(code **)(*DAT_00b5a6ac + 0x18))();
  if ((uint)param_2[6] <= (uint)fVar3) {
    pfVar4 = (float *)(**(code **)(*DAT_00b5add8 + 0x14))();
    fVar1 = (float)((int)fVar3 - (int)param_2[6]);
    if ((int)fVar3 - (int)param_2[6] < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    param_2 = (float *)(*param_2 - *param_1);
    if ((float)param_2 <= 0.0) {
      param_2 = (float *)(0.0 - (float)param_2);
    }
    fVar5 = (float10)FUN_005bdec0((float)param_2 / *pfVar4,(fVar1 / pfVar4[2]) * DAT_0099d0ec,
                                  pfVar4[1]);
    if (*param_1 <= *pfVar2 && *pfVar2 != *param_1) {
      *param_3 = *param_1 + (float)(fVar5 * (float10)*pfVar4);
      return;
    }
    *param_3 = *param_1 - (float)(fVar5 * (float10)*pfVar4);
  }
  return;
}


// ==== FUN_005be120 @ 0x005be120 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005be120(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float unaff_retaddr;
  float fStack_10;
  float fStack_c;
  undefined1 auStack_8 [8];
  
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  if (*(uint *)(param_2 + 0x18) <= uVar3) {
    iVar4 = (**(code **)(*DAT_00b5add8 + 0x14))();
    iVar5 = uVar3 - *(int *)(param_2 + 0x18);
    fVar1 = (float)iVar5;
    if (iVar5 < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar2 = (fVar1 / *(float *)(iVar4 + 0x14)) * DAT_0099d0ec;
    fVar6 = (float10)FUN_0040ef90(*(undefined4 *)(param_1 + 8),*(undefined4 *)(param_2 + 8));
    fStack_10 = (float)fVar6;
    fVar6 = (float10)FUN_0040ef90(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_2 + 4));
    fStack_c = (float)fVar6;
    fVar1 = (float)(SQRT((float10)fStack_10 * (float10)fStack_10 + fVar6 * (float10)fStack_c) /
                   (float10)*(float *)(iVar4 + 0xc));
    FUN_005bdec0(fVar1,fVar2,*(undefined4 *)(iVar4 + 0x10));
    thunk_FUN_0079de77(auStack_8,&fStack_10);
    *(float *)((int)fVar1 + 8) = *(float *)(param_1 + 8) + fStack_10 * unaff_retaddr;
    *(float *)((int)fVar1 + 4) = *(float *)(param_1 + 4) + fStack_c * unaff_retaddr;
  }
  return;
}


// ==== FUN_005be240 @ 0x005be240 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005be240(int param_1,float param_2,float *param_3)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int iVar4;
  float unaff_EBX;
  int iVar5;
  float fVar6;
  float unaff_retaddr;
  float afStack_18 [3];
  undefined4 uStack_c;
  float fStack_8;
  undefined4 uStack_4;
  
  uVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))();
  if (*(uint *)((int)param_2 + 0x18) <= uVar3) {
    iVar4 = (**(code **)(*DAT_00b5add8 + 0x14))();
    iVar5 = uVar3 - *(int *)((int)param_2 + 0x18);
    fVar2 = (float)iVar5;
    if (iVar5 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fStack_8 = *(float *)((int)param_2 + 0x20) - *(float *)(param_1 + 0x18);
    uStack_c = 0;
    uStack_4 = 0;
    fVar6 = *(float *)(iVar4 + 0x18) * *param_3;
    param_2 = DAT_009a09bc;
    fVar2 = (fVar2 / *(float *)(iVar4 + 0x20)) * DAT_0099d0ec;
    if (DAT_009a09bc <= fVar6) {
      param_2 = fVar6;
    }
    FUN_005bdec0(SQRT(fStack_8 * fStack_8) / param_2,fVar2,*(undefined4 *)(iVar4 + 0x1c));
    thunk_FUN_0079e1ba(afStack_18,&uStack_c);
    fVar6 = *(float *)(param_1 + 0x18);
    fVar1 = *(float *)(param_1 + 0x1c);
    param_3[5] = *(float *)(param_1 + 0x14) + unaff_EBX * unaff_retaddr;
    param_3[6] = fVar6 + fVar2 * unaff_retaddr;
    param_3[7] = fVar1 + afStack_18[0] * unaff_retaddr;
  }
  return;
}


// ==== FUN_005be3b0 @ 0x005be3b0 ====

void FUN_005be3b0(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar2 = param_1;
  puVar3 = param_3;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  FUN_005be040(param_1,param_2,param_3);
  FUN_005be120(param_1,param_2,param_3);
  FUN_005be240(param_1,param_2,param_3);
  return;
}


// ==== FUN_005be400 @ 0x005be400 ====

float10 FUN_005be400(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float fVar5;
  float fVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  undefined1 *puVar9;
  void *_Memory;
  undefined1 *puStack_fc;
  float fStack_f8;
  float fStack_f4;
  undefined1 auStack_e6 [14];
  void *pvStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  undefined1 auStack_b8 [4];
  undefined4 auStack_b4 [2];
  undefined4 uStack_ac;
  float fStack_a8;
  float fStack_a4;
  undefined1 *puStack_a0;
  void *pvStack_9c;
  undefined1 auStack_98 [4];
  float fStack_94;
  undefined4 uStack_8c;
  uint uStack_88;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  undefined1 auStack_4c [12];
  undefined1 local_40 [44];
  float *pfStack_14;
  
  fStack_f4 = (float)param_2;
  fStack_f8 = 0.0;
  puStack_fc = local_40;
  thunk_FUN_0079f3a1();
  puVar9 = auStack_4c;
  puVar7 = &uStack_ac;
  puVar8 = auStack_b8;
  uStack_ac = 0;
  fStack_a8 = (float)DAT_009c2424;
  fStack_a4 = 0.0;
  thunk_FUN_0079e5a0(puVar8,puVar7,puVar9);
  puStack_fc = (undefined1 *)pfStack_14[0xd];
  fStack_f8 = pfStack_14[0xe];
  fStack_f4 = pfStack_14[0xf];
  thunk_FUN_0079e1ba(&fStack_d0);
  fVar6 = (float)puVar7 - (float)pvStack_d8 * DAT_00a0fd50;
  fStack_a4 = (float)puVar9 - fStack_d4 * DAT_00a0fd50;
  puStack_fc = (undefined1 *)((float)puStack_fc - fStack_d0 * DAT_00a0fd50);
  fStack_94 = fStack_d0;
  puVar7 = auStack_b4;
  auStack_b4[0] = 8;
  pvStack_9c = pvStack_d8;
  fStack_a8 = fVar6;
  puStack_a0 = puStack_fc;
  cVar2 = (**(code **)(*DAT_00b5a6b4 + 0xc))(puVar7,&fStack_74);
  if ((cVar2 == '\0') ||
     (fStack_74 = fStack_74 - (float)(auStack_e6 + -6),
     _Memory = (void *)SQRT(fStack_74 * fStack_74 +
                            (fStack_70 - (float)puVar8) * (fStack_70 - (float)puVar8) +
                            (fStack_6c - fVar6) * (fStack_6c - fVar6)),
     fVar5 = fStack_d4 - (float)(auStack_e6 + -6),
     SQRT(fVar5 * fVar5 + (fStack_d0 - (float)puVar8) * (fStack_d0 - (float)puVar8) +
          (fStack_cc - fVar6) * (fStack_cc - fVar6)) <= (float)_Memory)) {
    return (float10)*pfStack_14;
  }
  puVar3 = (undefined4 *)(**(code **)(*DAT_00b5ae24 + 8))();
  puStack_fc = (undefined1 *)*puVar3;
  fStack_f4 = (float)puVar3[2];
  uVar1 = puVar3[4];
  fStack_f8 = (float)(puVar3[1] & 0xffffff00);
  FUN_00401740(s_CamAdj_009c2408,6);
  FUN_00401740(s_Collision_Dist___2f____2f__009c23ec,0x1b);
  uVar4 = FUN_00404230(auStack_98);
  (**(code **)(*DAT_00b5a688 + 8))(&puStack_fc,uVar4);
  if (0xf < uStack_88) {
    _free(pvStack_9c);
    return extraout_ST0;
  }
  uStack_88 = 0xf;
  uStack_8c = 0;
  pvStack_9c = (void *)((uint)pvStack_9c & 0xffffff00);
  if (uVar1 < 0x10) {
    return (float10)(float)puVar7;
  }
  _free(_Memory);
  return extraout_ST0_00;
}


// ==== FUN_005be750 @ 0x005be750 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005be750(byte param_1)

{
  undefined4 *in_ECX;
  
  _DAT_00b5b00c = 0;
  *in_ECX = &PTR_FUN_009c23b0;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005be780 @ 0x005be780 ====

void FUN_005be780(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c242c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005be7a0 @ 0x005be7a0 ====

void FUN_005be7a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,
                 undefined1 param_5)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = param_1;
  in_ECX[2] = param_3;
  in_ECX[1] = param_2;
  puVar2 = in_ECX + 3;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_4;
    param_4 = param_4 + 1;
    puVar2 = puVar2 + 1;
  }
  *(undefined1 *)(in_ECX + 0xb) = param_5;
  *(undefined1 *)((int)in_ECX + 0x2d) = 0;
  return;
}


// ==== FUN_005be800 @ 0x005be800 ====

void FUN_005be800(int param_1)

{
  int in_ECX;
  
  *(float *)(param_1 + 0x28) = *(float *)(in_ECX + 8) + *(float *)(param_1 + 0x28);
  *(float *)(param_1 + 0x2c) = *(float *)(in_ECX + 0xc) + *(float *)(param_1 + 0x2c);
  *(float *)(param_1 + 0x30) = *(float *)(in_ECX + 0x10) + *(float *)(param_1 + 0x30);
  *(float *)(param_1 + 0x34) = *(float *)(in_ECX + 8) + *(float *)(param_1 + 0x34);
  *(float *)(param_1 + 0x38) = *(float *)(in_ECX + 0xc) + *(float *)(param_1 + 0x38);
  *(float *)(param_1 + 0x3c) = *(float *)(in_ECX + 0x10) + *(float *)(param_1 + 0x3c);
  return;
}


// ==== FUN_005be870 @ 0x005be870 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005be870(float param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float *pfVar5;
  int in_ECX;
  int local_20;
  undefined1 local_c [12];
  
  iVar4 = (int)param_1;
  *(float *)(in_ECX + 8) = 0.0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  if (*(int *)(in_ECX + 0x1c) != 0) {
    local_20 = **(int **)(in_ECX + 0x18);
    if ((int *)local_20 != *(int **)(in_ECX + 0x18)) {
      do {
        if (*(uint *)(iVar4 + 4) < *(uint *)(local_20 + 0x28)) {
          *(uint *)(local_20 + 0x28) = *(uint *)(local_20 + 0x28) - *(uint *)(iVar4 + 4);
          pfVar5 = (float *)(**(code **)(*DAT_00b5ad14 + 0x14))();
          fVar1 = *pfVar5 - *(float *)(local_20 + 0x10);
          fVar3 = pfVar5[1] - *(float *)(local_20 + 0x14);
          fVar2 = pfVar5[2] - *(float *)(local_20 + 0x18);
          fVar1 = SQRT(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2);
          if (fVar1 <= *(float *)(local_20 + 0x20)) {
            fVar2 = (float)*(int *)(local_20 + 0x28);
            if (*(int *)(local_20 + 0x28) < 0) {
              fVar2 = fVar2 + _DAT_0099d104;
            }
            fVar3 = (float)*(int *)(local_20 + 0x24);
            if (*(int *)(local_20 + 0x24) < 0) {
              fVar3 = fVar3 + _DAT_0099d104;
            }
            *(float *)(in_ECX + 4) =
                 ((*(float *)(local_20 + 0x20) - fVar1) / *(float *)(local_20 + 0x20)) *
                 (fVar2 / fVar3) * *(float *)(local_20 + 0x1c) + *(float *)(in_ECX + 4);
          }
          FUN_00699bf0();
        }
        else {
          local_20 = FUN_005bee70(&param_1,local_20);
          local_20 = *(int *)local_20;
        }
      } while (local_20 != *(int *)(in_ECX + 0x18));
    }
    param_1 = DAT_009a000c;
    if (*(float *)(in_ECX + 4) <= DAT_009a000c) {
      param_1 = *(float *)(in_ECX + 4);
    }
    *(float *)(in_ECX + 4) = param_1;
    pfVar5 = (float *)FUN_0040ecc0(local_c);
    fVar1 = pfVar5[1];
    fVar2 = pfVar5[2];
    *(float *)(in_ECX + 8) = *pfVar5 * param_1;
    *(float *)(in_ECX + 0xc) = fVar1 * param_1;
    *(float *)(in_ECX + 0x10) = fVar2 * param_1;
  }
  return;
}


// ==== FUN_005bea50 @ 0x005bea50 ====

void FUN_005bea50(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_44 [2];
  undefined4 local_3c [4];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c [7];
  
  iVar2 = param_1;
  uVar1 = *(undefined4 *)(param_1 + 4);
  param_1 = uVar1;
  FUN_005beda0(local_44,&param_1);
  if (local_44[0] != *(int *)(in_ECX + 0x18)) {
    *(undefined4 *)(local_44[0] + 0x10) = *(undefined4 *)(iVar2 + 8);
    *(undefined4 *)(local_44[0] + 0x14) = *(undefined4 *)(iVar2 + 0xc);
    *(undefined4 *)(local_44[0] + 0x18) = *(undefined4 *)(iVar2 + 0x10);
    uVar1 = *(undefined4 *)(iVar2 + 0x14);
    *(undefined4 *)(local_44[0] + 0x24) = uVar1;
    *(undefined4 *)(local_44[0] + 0x28) = uVar1;
    return;
  }
  local_3c[0] = *(undefined4 *)(iVar2 + 8);
  local_3c[1] = *(undefined4 *)(iVar2 + 0xc);
  local_3c[3] = *(undefined4 *)(iVar2 + 0x18);
  local_28 = *(undefined4 *)(iVar2 + 0x14);
  local_24 = *(undefined4 *)(iVar2 + 0x14);
  local_3c[2] = *(undefined4 *)(iVar2 + 0x10);
  local_2c = *(undefined4 *)(iVar2 + 0x1c);
  local_20 = uVar1;
  puVar3 = local_3c;
  puVar4 = local_1c;
  for (iVar2 = 7; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  FUN_005bf3c0(local_44,&local_20);
  return;
}


// ==== FUN_005beb30 @ 0x005beb30 ====

void FUN_005beb30(void)

{
  int iVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c243c;
  iVar1 = FUN_005beca0();
  in_ECX[6] = iVar1;
  *(undefined1 *)(iVar1 + 0x2d) = 1;
  *(undefined4 *)(in_ECX[6] + 4) = in_ECX[6];
  *(undefined4 *)in_ECX[6] = in_ECX[6];
  *(undefined4 *)(in_ECX[6] + 8) = in_ECX[6];
  in_ECX[7] = 0;
  return;
}


// ==== FUN_005beb70 @ 0x005beb70 ====

undefined4 FUN_005beb70(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1;
  iVar2 = (**(code **)(*param_1 + 4))();
  if (iVar2 == 0x40001) {
    FUN_005be870(piVar1);
  }
  else {
    if (iVar2 == 0x60030010) {
      FUN_005bea50(piVar1);
      return 1;
    }
    if (iVar2 == 0x60030011) {
      param_1 = (int *)piVar1[1];
      FUN_005bf480(&param_1);
      return 1;
    }
  }
  return 0;
}


// ==== FUN_005bebd0 @ 0x005bebd0 ====

void FUN_005bebd0(void *param_1)

{
  if (*(char *)((int)param_1 + 0x2d) == '\0') {
    FUN_005bebd0(*(undefined4 *)((int)param_1 + 8));
    _free(param_1);
    return;
  }
  return;
}


// ==== FUN_005bec10 @ 0x005bec10 ====

void * FUN_005bec10(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                   undefined4 param_5)

{
  void *pvVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982960;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  pvVar1 = operator_new(0x30);
  local_8 = 0;
  if (pvVar1 != (void *)0x0) {
    FUN_005be7a0(param_1,param_2,param_3,param_4,param_5);
  }
  ExceptionList = local_10;
  return pvVar1;
}


// ==== Catch@005bec85 @ 0x005bec85 ====

void Catch_005bec85(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005beca0 @ 0x005beca0 ====

void FUN_005beca0(void)

{
  undefined4 *puVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982970;
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


// ==== Catch@005bed2a @ 0x005bed2a ====

void Catch_005bed2a(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005bed40 @ 0x005bed40 ====

void FUN_005bed40(int *param_1,int *param_2,int *param_3)

{
  char cVar1;
  int *piVar2;
  int *piVar3;
  
  while (param_1 != param_2) {
    *param_3 = *param_3 + 1;
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
  return;
}


// ==== FUN_005beda0 @ 0x005beda0 ====

void FUN_005beda0(undefined4 *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar3[1] + 0x2d) == '\0') {
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
    } while (*(char *)((int)puVar2 + 0x2d) == '\0');
  }
  if ((puVar3 == *(undefined4 **)(in_ECX + 4)) || (*param_2 < (uint)puVar3[3])) {
    *param_1 = *(undefined4 **)(in_ECX + 4);
    return;
  }
  *param_1 = puVar3;
  return;
}


// ==== FUN_005bee10 @ 0x005bee10 ====

void FUN_005bee10(int *param_1,uint *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar4 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar4[1] + 0x2d) == '\0') {
    puVar1 = (undefined4 *)puVar4[1];
    do {
      if (*param_2 < (uint)puVar1[3]) {
        puVar2 = (undefined4 *)*puVar1;
        puVar4 = puVar1;
      }
      else {
        puVar2 = (undefined4 *)puVar1[2];
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x2d) == '\0');
  }
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if (*(char *)((int)puVar1[1] + 0x2d) == '\0') {
    puVar2 = (undefined4 *)puVar1[1];
    do {
      if ((uint)puVar2[3] < *param_2) {
        puVar3 = (undefined4 *)puVar2[2];
      }
      else {
        puVar3 = (undefined4 *)*puVar2;
        puVar1 = puVar2;
      }
      puVar2 = puVar3;
    } while (*(char *)((int)puVar3 + 0x2d) == '\0');
  }
  *param_1 = (int)puVar1;
  param_1[1] = (int)puVar4;
  return;
}


// ==== FUN_005bee70 @ 0x005bee70 ====

/* WARNING: Removing unreachable block (ram,0x005bef8c) */
/* WARNING: Removing unreachable block (ram,0x005bef9c) */
/* WARNING: Removing unreachable block (ram,0x005befa5) */
/* WARNING: Removing unreachable block (ram,0x005befa8) */
/* WARNING: Removing unreachable block (ram,0x005bef98) */
/* WARNING: Removing unreachable block (ram,0x005befb6) */
/* WARNING: Removing unreachable block (ram,0x005befc3) */
/* WARNING: Removing unreachable block (ram,0x005befce) */
/* WARNING: Removing unreachable block (ram,0x005befca) */
/* WARNING: Removing unreachable block (ram,0x005befbe) */
/* WARNING: Removing unreachable block (ram,0x005befd1) */

void FUN_005bee70(undefined4 param_1,int *param_2)

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
  
  if (*(char *)((int)param_2 + 0x2d) != '\0') {
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
            goto LAB_005bf0a0;
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
LAB_005bf0a0:
            *(undefined1 *)(piVar5 + 0xb) = 0;
          }
        }
        piVar5 = (int *)piVar3[1];
        piVar6 = piVar3;
      } while (piVar3 != *(int **)(*(int *)(in_ECX + 4) + 4));
    }
    *(undefined1 *)(piVar6 + 0xb) = 1;
  }
  _free(param_2);
  return;
}


// ==== FUN_005bf120 @ 0x005bf120 ====

void FUN_005bf120(undefined4 *param_1,int *param_2,int *param_3)

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
    FUN_005bebd0(piVar6[1]);
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
    FUN_005bee70(&param_2,piVar3);
    piVar3 = piVar6;
  }
  *param_1 = piVar3;
  return;
}


// ==== FUN_005bf1e0 @ 0x005bf1e0 ====

void FUN_005bf1e0(undefined4 *param_1,char param_2,undefined4 *param_3,undefined4 param_4)

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
  piVar4 = (int *)FUN_005bec10(*(undefined4 *)(in_ECX + 4),param_3,*(undefined4 *)(in_ECX + 4),
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
LAB_005bf2e5:
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
      if ((char)piVar6[0xb] == '\0') goto LAB_005bf2e5;
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


// ==== FUN_005bf3c0 @ 0x005bf3c0 ====

void FUN_005bf3c0(undefined4 *param_1,uint *param_2)

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
  if (*(char *)((int)puVar4[1] + 0x2d) == '\0') {
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
    } while (*(char *)((int)puVar3 + 0x2d) == '\0');
  }
  param_2 = puVar4;
  if (bVar5) {
    if (puVar4 == (undefined4 *)**(int **)(in_ECX + 4)) {
      puVar4 = (undefined4 *)FUN_005bf1e0(&param_2,1,puVar4,puVar2);
      uVar1 = *puVar4;
      *(undefined1 *)(param_1 + 1) = 1;
      *param_1 = uVar1;
      return;
    }
    FUN_0079c420();
  }
  if (param_2[3] < *puVar2) {
    puVar4 = (undefined4 *)FUN_005bf1e0(&param_2,bVar5,puVar4,puVar2);
    *param_1 = *puVar4;
    *(undefined1 *)(param_1 + 1) = 1;
    return;
  }
  *(undefined1 *)(param_1 + 1) = 0;
  *param_1 = param_2;
  return;
}


// ==== FUN_005bf480 @ 0x005bf480 ====

undefined4 FUN_005bf480(undefined4 param_1)

{
  undefined4 local_8;
  undefined4 local_4;
  
  FUN_005bee10(&local_8,param_1);
  param_1 = 0;
  FUN_005bed40(local_8,local_4,&param_1,0);
  FUN_005bf120(&local_8,local_8,local_4);
  return param_1;
}


// ==== FUN_005bf4e0 @ 0x005bf4e0 ====

void FUN_005bf4e0(void)

{
  undefined4 *in_ECX;
  undefined1 local_4 [4];
  
  *in_ECX = &PTR_FUN_009c243c;
  FUN_005bf120(local_4,*(undefined4 *)in_ECX[6],(undefined4 *)in_ECX[6]);
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_005bf540 @ 0x005bf540 ====

undefined4 FUN_005bf540(undefined4 param_1)

{
  void *pvVar1;
  undefined4 uVar2;
  
  pvVar1 = operator_new(0x54);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  uVar2 = FUN_005cda40(param_1);
  return uVar2;
}


// ==== FUN_005bf560 @ 0x005bf560 ====

void FUN_005bf560(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    (**(code **)*param_1)(1);
  }
  return;
}


// ==== FUN_005bf570 @ 0x005bf570 ====

void FUN_005bf570(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005bf575. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0xc))();
  return;
}


// ==== FUN_005bf580 @ 0x005bf580 ====

void FUN_005bf580(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005bf585. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 8) + 0x10))();
  return;
}


// ==== FUN_005bf590 @ 0x005bf590 ====

void FUN_005bf590(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = param_1;
  return;
}


// ==== FUN_005bf5b0 @ 0x005bf5b0 ====

void FUN_005bf5b0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x50) = param_1;
  return;
}


// ==== FUN_005bf5c0 @ 0x005bf5c0 ====

void FUN_005bf5c0(float *param_1)

{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  int iVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  
  iVar1 = *(int *)(in_ECX + 0x14);
  bVar4 = false;
  for (iVar8 = *(int *)(in_ECX + 0x10); iVar8 != iVar1; iVar8 = iVar8 + 0x60) {
    fVar10 = *(float *)(iVar8 + 0x10);
    uVar5 = FUN_004b9c10();
    fVar9 = DAT_009b0318;
    if (uVar5 == 0) {
      if (bVar4) {
        if (DAT_009b0318 < *param_1 || DAT_009b0318 == *param_1) {
          fVar10 = DAT_009b0318;
        }
        else {
          fVar10 = *param_1;
        }
        bVar2 = DAT_009b0318 == param_1[1];
        bVar3 = DAT_009b0318 < param_1[1];
        *param_1 = fVar10;
        if (bVar3 || bVar2) {
          fVar10 = fVar9;
        }
        else {
          fVar10 = param_1[1];
        }
        param_1[1] = fVar10;
        if (param_1[2] <= fVar9 && fVar9 != param_1[2]) {
          fVar9 = param_1[2];
        }
        param_1[2] = fVar9;
        fVar9 = DAT_0099d0b4;
        fVar10 = param_1[3];
        if (fVar10 <= DAT_0099d0b4) {
          fVar10 = DAT_0099d0b4;
        }
        param_1[3] = fVar10;
        fVar10 = param_1[4];
        if (fVar10 <= fVar9) {
          fVar10 = fVar9;
        }
        param_1[4] = fVar10;
        if (fVar9 < param_1[5]) {
          fVar9 = param_1[5];
        }
        param_1[5] = fVar9;
      }
      else {
        *param_1 = DAT_009b0318;
        param_1[1] = fVar9;
        fVar10 = DAT_0099d0b4;
        param_1[2] = fVar9;
        param_1[3] = fVar10;
        param_1[4] = fVar10;
        param_1[5] = fVar10;
        bVar4 = true;
      }
    }
    else {
      uVar7 = 0;
      if (uVar5 != 0) {
        do {
          iVar6 = FUN_004ba010(uVar7);
          if (iVar6 != 0) {
            if (bVar4) {
              fVar9 = *(float *)(iVar6 + 0x10) * fVar10;
              fVar11 = *(float *)(iVar6 + 0x14) * fVar10;
              fVar12 = *(float *)(iVar6 + 0x18) * fVar10;
              if (*param_1 <= fVar9 && fVar9 != *param_1) {
                fVar9 = *param_1;
              }
              *param_1 = fVar9;
              if (param_1[1] <= fVar11 && fVar11 != param_1[1]) {
                fVar11 = param_1[1];
              }
              param_1[1] = fVar11;
              if (param_1[2] <= fVar12 && fVar12 != param_1[2]) {
                fVar12 = param_1[2];
              }
              param_1[2] = fVar12;
              fVar9 = *(float *)(iVar6 + 0x1c) * fVar10;
              fVar11 = *(float *)(iVar6 + 0x20) * fVar10;
              fVar12 = *(float *)(iVar6 + 0x24) * fVar10;
              if (fVar9 < param_1[3]) {
                fVar9 = param_1[3];
              }
              param_1[3] = fVar9;
              if (fVar11 < param_1[4]) {
                fVar11 = param_1[4];
              }
              param_1[4] = fVar11;
              if (fVar12 < param_1[5]) {
                fVar12 = param_1[5];
              }
              param_1[5] = fVar12;
            }
            else {
              fVar9 = *(float *)(iVar6 + 0x14);
              fVar11 = *(float *)(iVar6 + 0x18);
              *param_1 = *(float *)(iVar6 + 0x10) * fVar10;
              param_1[1] = fVar9 * fVar10;
              param_1[2] = fVar11 * fVar10;
              fVar9 = *(float *)(iVar6 + 0x20);
              fVar11 = *(float *)(iVar6 + 0x24);
              param_1[3] = *(float *)(iVar6 + 0x1c) * fVar10;
              param_1[4] = fVar9 * fVar10;
              param_1[5] = fVar11 * fVar10;
              bVar4 = true;
            }
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < uVar5);
      }
    }
  }
  return;
}


// ==== FUN_005bf880 @ 0x005bf880 ====

undefined4 FUN_005bf880(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  iVar3 = *(int *)(in_ECX + 0x10);
  iVar1 = *(int *)(in_ECX + 0x14);
  while( true ) {
    if (iVar3 == iVar1) {
      return 0;
    }
    iVar2 = FUN_004b9e30(param_1);
    if (iVar2 != 0) break;
    iVar3 = iVar3 + 0x60;
  }
  return 1;
}


// ==== FUN_005bf8c0 @ 0x005bf8c0 ====

undefined4 FUN_005bf8c0(undefined4 *param_1,undefined4 param_2,char param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x14);
  puVar3 = *(undefined4 **)(in_ECX + 0x10);
  while( true ) {
    if (puVar3 == puVar1) {
      return 0;
    }
    if (param_3 == '\0') {
      iVar2 = FUN_004b9df0(param_2);
    }
    else if (param_3 == '\x01') {
      iVar2 = FUN_004b9e30(param_2);
    }
    else {
      iVar2 = FUN_004b9e70(param_2);
    }
    if (iVar2 != 0) break;
    puVar3 = puVar3 + 0x18;
  }
  for (iVar2 = 0x18; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *puVar3;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  }
  return 1;
}


// ==== FUN_005bf920 @ 0x005bf920 ====

void FUN_005bf920(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  (**(code **)(**(int **)(in_ECX + 8) + 8))();
  puVar1 = *(undefined4 **)(in_ECX + 0x14);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x10); puVar2 != puVar1; puVar2 = puVar2 + 0x18) {
    (**(code **)(**(int **)(in_ECX + 8) + 4))(*puVar2);
  }
  return;
}


// ==== FUN_005bf950 @ 0x005bf950 ====

void FUN_005bf950(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  if (*(int *)(param_2 + 4) == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = (*(int *)(param_2 + 8) - *(int *)(param_2 + 4)) / 0x24;
  }
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = (*(int *)(param_1 + 8) - iVar5) / 0x60;
  }
  if (iVar4 == iVar2) {
    iVar4 = *(int *)(param_1 + 8);
    uVar3 = 0;
    if (iVar5 != iVar4) {
      iVar2 = 0;
      do {
        iVar1 = *(int *)(param_2 + 4);
        if ((iVar1 == 0) || ((uint)((*(int *)(param_2 + 8) - iVar1) / 0x24) <= uVar3)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        if (*(char *)(iVar2 + iVar1) == '\x01') {
          *(undefined4 *)(iVar5 + 0x5c) = *(undefined4 *)(iVar2 + 4 + iVar1);
        }
        *(undefined1 *)(iVar5 + 0x58) = *(undefined1 *)(iVar2 + iVar1);
        iVar5 = iVar5 + 0x60;
        uVar3 = uVar3 + 1;
        iVar2 = iVar2 + 0x24;
      } while (iVar5 != iVar4);
    }
    *(undefined1 *)(in_ECX + 0x4e) = 0;
  }
  return;
}


// ==== FUN_005bfb00 @ 0x005bfb00 ====

uint FUN_005bfb00(undefined4 *param_1,char *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint extraout_EAX;
  undefined4 uVar3;
  uint extraout_EAX_00;
  int in_ECX;
  byte bVar4;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  if (*(char *)(in_ECX + 0x50) != '\0') {
    iVar1 = (**(code **)(*DAT_00b5af48 + 8))();
    if (*(char *)(iVar1 + 1) != '\0') {
      bVar4 = 0;
      if (*param_2 != '\0') {
        uVar2 = FUN_004022a0(auStack_1c,&PTR_LAB_009c2464,param_2 + 0xc);
        uVar2 = FUN_005b1c00(uVar2);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return extraout_EAX;
        }
        uVar3 = FUN_004022a0(auStack_1c,&PTR_LAB_009c2468,param_2 + 0x28);
        iVar1 = FUN_005aa220(uVar3);
        if (0xf < uStack_4) {
          _free(pvStack_18);
          return extraout_EAX_00;
        }
        uStack_4 = 0xf;
        uStack_8 = 0;
        pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
        if (*(char *)(iVar1 + 0x88) == '\0') {
          *param_1 = uVar2;
          param_1[1] = iVar1;
        }
        bVar4 = 1;
      }
      *(undefined1 *)((int)param_1 + 0x59) = 1;
      FUN_005c1360(param_1);
      return (uint)bVar4;
    }
  }
  return 0;
}


// ==== FUN_005bfbf0 @ 0x005bfbf0 ====

void FUN_005bfbf0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  int in_ECX;
  int iVar8;
  void *local_a0;
  undefined1 local_9c;
  undefined4 uStack_90;
  uint local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined1 uStack_80;
  void *pvStack_7c;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  uint uStack_68;
  int iStack_64;
  undefined4 uStack_60;
  int iStack_5c;
  undefined1 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_8;
  undefined1 local_7;
  undefined4 uStack_4;
  
  iVar8 = *(int *)(param_1 + 4);
  iVar1 = *(int *)(param_1 + 8);
  local_58 = 0;
  local_54 = 0xffffffff;
  local_4c = 0;
  local_4b = 0;
  local_8 = 0;
  local_7 = 0;
  local_50 = DAT_0099d080;
  piVar3 = DAT_00b5a7cc;
  do {
    DAT_00b5a7cc = piVar3;
    if (iVar8 == iVar1) {
      (**(code **)(**(int **)(in_ECX + 8) + 8))();
      puVar2 = *(undefined4 **)(in_ECX + 0x14);
      for (puVar7 = *(undefined4 **)(in_ECX + 0x10); puVar7 != puVar2; puVar7 = puVar7 + 0x18) {
        (**(code **)(**(int **)(in_ECX + 8) + 4))(*puVar7);
      }
      return;
    }
    local_88 = 0xf;
    local_8c = 0;
    local_9c = 0;
    FUN_00401660(iVar8 + 0xc,0,0xffffffff);
    local_84 = 8;
    iVar5 = (**(code **)(*piVar3 + 0xc))(&local_a0);
    piVar3 = DAT_00b5a7cc;
    if (0xf < local_8c) {
      _free(local_a0);
      return;
    }
    local_8c = 0xf;
    uStack_90 = 0;
    local_a0 = (void *)((uint)local_a0 & 0xffffff00);
    uStack_6c = 0xf;
    uStack_70 = 0;
    uStack_80 = 0;
    iStack_64 = iVar5;
    FUN_00401660(iVar8 + 0x28,0,0xffffffff);
    uStack_68 = 0x10;
    iVar6 = (**(code **)(*piVar3 + 0xc))(&local_84);
    if (0xf < uStack_68) {
      _free(pvStack_7c);
      return;
    }
    uStack_68 = 0xf;
    uStack_6c = 0;
    pvStack_7c = (void *)((uint)pvStack_7c & 0xffffff00);
    iStack_5c = iVar6;
    if (iVar5 == 0) {
LAB_005bfdd3:
      if (iVar6 != 0) {
        (**(code **)(*DAT_00b5a7cc + 0x14))(iVar6);
        iStack_5c = 0;
      }
    }
    else {
      if ((iVar6 == 0) || (*(int *)(in_ECX + 4) == 0)) {
        (**(code **)(*DAT_00b5a7cc + 0x14))(iVar5);
        uStack_60 = 0;
        goto LAB_005bfdd3;
      }
      local_58 = *(undefined1 *)(iVar8 + 1);
      local_54 = *(undefined4 *)(iVar8 + 4);
      local_50 = *(undefined4 *)(iVar8 + 8);
      local_4c = *(undefined1 *)(iVar8 + 2);
      local_8 = 0;
      uStack_4 = 0;
      local_7 = 0;
      if (*(char *)(iVar8 + 3) != '\0') {
        puVar7 = (undefined4 *)
                 FUN_005c85e0(CONCAT31((int3)((uint)local_54 >> 8),*(char *)(iVar8 + 3)));
        if (puVar7 != (undefined4 *)0x0) {
          uStack_4 = *puVar7;
          local_8 = 1;
        }
        *(undefined1 *)(in_ECX + 0x4f) = 1;
      }
      FUN_005c1360(&uStack_60);
      cVar4 = FUN_005bfb00(&uStack_60,iVar8);
      if (cVar4 == '\0') {
        *(undefined1 *)(*(int *)(in_ECX + 4) + 0x39) = 0;
      }
    }
    iVar8 = iVar8 + 0x44;
    piVar3 = DAT_00b5a7cc;
  } while( true );
}


// ==== FUN_005bfe30 @ 0x005bfe30 ====

void FUN_005bfe30(int param_1)

{
  code *pcVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009c2470;
  in_ECX[1] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[8] = 0;
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  *(undefined1 *)(in_ECX + 0x13) = 0;
  *(undefined1 *)((int)in_ECX + 0x4d) = 0;
  *(undefined1 *)((int)in_ECX + 0x4e) = 0;
  *(undefined1 *)((int)in_ECX + 0x4f) = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  in_ECX[2] = param_1;
  if (param_1 != 0) {
    return;
  }
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_m_pIntersect____NULL_009c244c,0x14);
  FUN_00406880(local_1c);
  if (local_4 < 0x10) {
    pcVar1 = (code *)swi(3);
    (*pcVar1)();
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005bfed0 @ 0x005bfed0 ====

void FUN_005bfed0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  int iVar5;
  uint local_10;
  int local_4;
  
  uVar4 = 0;
  if (*(int *)(in_ECX + 0x10) == 0) {
    local_10 = 0;
  }
  else {
    local_10 = (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10)) / 0x60;
  }
  if ((*(int *)(in_ECX + 0x20) == 0) ||
     (local_4 = (*(int *)(in_ECX + 0x24) - *(int *)(in_ECX + 0x20)) / 0x60, local_4 == 0)) {
    uVar4 = 0;
    if (local_10 != 0) {
      iVar5 = 0;
      do {
        iVar1 = *(int *)(in_ECX + 0x10);
        if ((iVar1 == 0) || ((uint)((*(int *)(in_ECX + 0x14) - iVar1) / 0x60) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        if (*(int *)(iVar5 + iVar1) != 0) {
          (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(iVar5 + iVar1));
          *(undefined4 *)(iVar5 + iVar1) = 0;
        }
        iVar2 = *(int *)(iVar5 + 4 + iVar1);
        if (iVar2 != 0) {
          (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
          *(undefined4 *)(iVar5 + 4 + iVar1) = 0;
        }
        uVar4 = uVar4 + 1;
        iVar5 = iVar5 + 0x60;
      } while (uVar4 < local_10);
    }
  }
  else {
    if (local_10 != 0) {
      iVar5 = 0;
      do {
        iVar1 = *(int *)(in_ECX + 0x10);
        if ((iVar1 == 0) || ((uint)((*(int *)(in_ECX + 0x14) - iVar1) / 0x60) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        iVar2 = *(int *)(in_ECX + 0x20);
        if ((iVar2 == 0) || ((uint)((*(int *)(in_ECX + 0x24) - iVar2) / 0x60) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
          FUN_0085b340();
        }
        iVar3 = *(int *)(iVar5 + iVar2);
        if (*(int *)(iVar5 + iVar1) != iVar3) {
          if (iVar3 != 0) {
            (**(code **)(*DAT_00b5a7cc + 0x14))(iVar3);
            *(undefined4 *)(iVar5 + iVar2) = 0;
          }
          iVar3 = *(int *)(iVar5 + 4 + iVar2);
          if (iVar3 != 0) {
            (**(code **)(*DAT_00b5a7cc + 0x14))(iVar3);
            *(undefined4 *)(iVar5 + 4 + iVar2) = 0;
          }
        }
        if (*(int *)(iVar5 + iVar1) != 0) {
          (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(iVar5 + iVar1));
          *(undefined4 *)(iVar5 + iVar1) = 0;
        }
        iVar2 = *(int *)(iVar5 + 4 + iVar1);
        if (iVar2 != 0) {
          (**(code **)(*DAT_00b5a7cc + 0x14))(iVar2);
          *(undefined4 *)(iVar5 + 4 + iVar1) = 0;
        }
        uVar4 = uVar4 + 1;
        iVar5 = iVar5 + 0x60;
      } while (uVar4 < local_10);
    }
    if (*(void **)(in_ECX + 0x20) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x20));
      return;
    }
    *(undefined4 *)(in_ECX + 0x20) = 0;
    *(undefined4 *)(in_ECX + 0x24) = 0;
    *(undefined4 *)(in_ECX + 0x28) = 0;
  }
  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x39) = 1;
  if (*(void **)(in_ECX + 0x10) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x10));
    return;
  }
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined1 *)(in_ECX + 0x4f) = 0;
  (**(code **)(**(int **)(in_ECX + 8) + 8))();
  if (*(int *)(in_ECX + 0x30) != 0) {
    FUN_0069d3a0(*(int *)(in_ECX + 0x30),*(undefined4 *)(in_ECX + 0x34),in_ECX + 0x2c,local_4);
    _free(*(void **)(in_ECX + 0x30));
    return;
  }
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  if (*(int *)(in_ECX + 0x40) == 0) {
    *(undefined4 *)(in_ECX + 0x40) = 0;
    *(undefined4 *)(in_ECX + 0x44) = 0;
    *(undefined4 *)(in_ECX + 0x48) = 0;
    return;
  }
  FUN_0069d3a0(*(int *)(in_ECX + 0x40),*(undefined4 *)(in_ECX + 0x44),in_ECX + 0x3c,local_4);
  _free(*(void **)(in_ECX + 0x40));
  return;
}


