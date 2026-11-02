// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x5d0000-0x5dffff

// ==== FUN_005d0010 @ 0x005d0010 ====

undefined4 FUN_005d0010(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x005d001b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return uVar1;
}


// ==== __break @ 0x005d002c ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


// ==== FUN_005d0030 @ 0x005d0030 ====

int FUN_005d0030(undefined4 param_1,int param_2)

{
  switch(param_1) {
  case 0:
    return 0;
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return (-(uint)(param_2 != 0) & 0xfffffffa) + 9;
  case 4:
    return 8 - (uint)(param_2 != 0);
  case 5:
    return 4;
  case 6:
    return 6;
  default:
    return 3;
  }
}


// ==== FUN_005d00b0 @ 0x005d00b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_005d00b0(int *param_1)

{
  int iVar1;
  float *pfVar2;
  float fVar3;
  int *piVar4;
  int in_ECX;
  int iVar5;
  int *piVar6;
  int *piVar7;
  float unaff_ESI;
  int unaff_EDI;
  float10 fVar8;
  float fVar9;
  int *piStack_60;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  int *local_4c;
  float fStack_40;
  float fStack_3c;
  int *piStack_38;
  float fStack_34;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float afStack_1c [3];
  float fStack_10;
  float fStack_c;
  float fStack_8;
  int *piStack_4;
  
  piVar4 = (int *)0x0;
  if ((*(int *)(in_ECX + 0x10) != 0) &&
     (piVar4 = (int *)0x0, (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10)) / 0x44 != 0)) {
    piVar4 = (int *)0x0;
    if (*(int *)(in_ECX + 0x10) != 0) {
      iVar5 = *(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10);
      piVar4 = (int *)(iVar5 * 0x78787879);
      local_4c = (int *)(iVar5 / 0x44);
      if (local_4c != (int *)0x0) {
        iVar5 = (**(code **)(*DAT_00b5a988 + 0x14))();
        piStack_60 = *(int **)(in_ECX + 0x10);
        local_4c = *(int **)(in_ECX + 0x14);
        fStack_40 = *(float *)(iVar5 + 0x28);
        fStack_3c = *(float *)(iVar5 + 0x2c);
        piVar4 = *(int **)(iVar5 + 0x30);
        if (piStack_60 != local_4c) {
          piVar6 = piStack_60 + 0xe;
          piStack_38 = piVar4;
          while( true ) {
            piVar4 = (int *)(**(code **)(*param_1 + 0xf4))();
            iVar5 = piVar6[-0xd];
            fStack_54 = (float)*piStack_60;
            fVar9 = (float)iVar5;
            if (iVar5 < 0) {
              fVar9 = fVar9 + _DAT_0099d104;
            }
            fVar3 = (float)(int)fStack_54;
            if ((int)fStack_54 < 0) {
              fVar3 = fVar3 + _DAT_0099d104;
            }
            iVar5 = (int)fStack_54 - iVar5;
            iVar1 = (int)ROUND((DAT_0099d080 - fVar9 / fVar3) * DAT_009bf5a0);
            fVar8 = (float10)FUN_005aa2a0(iVar1,iVar5);
            piVar7 = (int *)(float)fVar8;
            FUN_005aa2a0(iVar1,iVar5);
            fVar8 = (float10)FUN_005aa2a0(iVar1,iVar5);
            fStack_58 = (float)fVar8;
            fVar8 = (float10)FUN_005aa2a0(iVar1,iVar5);
            fStack_54 = (float)fVar8;
            FUN_00430ad0(piVar6 + -5);
            fStack_10 = DAT_0099d080;
            *piVar4 = piVar6[-6];
            fStack_c = fStack_10;
            fStack_8 = fStack_10;
            piStack_4 = piVar7;
            iVar5 = FUN_0040ead0(&fStack_10);
            piVar4[6] = iVar5;
            pfVar2 = (float *)(piVar4 + 1);
            *pfVar2 = (float)piVar6[-9];
            piVar4[2] = piVar6[-8];
            piVar4[3] = piVar6[-7];
            piVar4[2] = (int)(fStack_58 + (float)piVar4[2]);
            fStack_28 = *pfVar2 - fStack_40;
            fStack_24 = (float)piVar4[2] - fStack_3c;
            fStack_20 = (float)piVar4[3] - (float)piStack_38;
            thunk_FUN_0079e1ba(afStack_1c,&fStack_28);
            fStack_3c = *pfVar2 + fStack_24 * (float)piVar7;
            piStack_38 = (int *)((float)piVar4[2] + fStack_20 * (float)piVar7);
            fStack_34 = (float)piVar4[3] + afStack_1c[0] * (float)piVar7;
            *pfVar2 = fStack_3c;
            piVar4[2] = (int)piStack_38;
            piVar4[3] = (int)fStack_34;
            piVar7 = (int *)0x0;
            if ((*piVar6 != 0) &&
               (piStack_60 = (int *)(piVar6[1] - *piVar6 >> 2), piStack_60 != (int *)0x0)) {
              do {
                iVar5 = *piVar6;
                if ((iVar5 == 0) || ((int *)(piVar6[1] - iVar5 >> 2) <= piVar7)) {
                    /* WARNING: Subroutine does not return */
                  FUN_0042f370();
                }
                iVar1 = piVar4[8];
                fStack_58 = *(float *)(iVar5 + (int)piVar7 * 4) * unaff_ESI * _DAT_009c3138;
                if ((iVar1 == 0) ||
                   ((uint)(piVar4[10] - iVar1 >> 2) <= (uint)(piVar4[9] - iVar1 >> 2))) {
                  FUN_00446120(piVar4[9],1,&fStack_58);
                }
                else {
                  pfVar2 = (float *)piVar4[9];
                  *pfVar2 = fStack_58;
                  piVar4[9] = (int)(pfVar2 + 1);
                }
                piVar7 = (int *)((int)piVar7 + 1);
              } while (piVar7 < piStack_60);
            }
            if ((piVar6[-6] == 7) || (piVar6[-6] == 8)) {
              fVar9 = *(float *)(*(int *)(unaff_EDI + 0x48) + 8) * unaff_ESI;
            }
            else {
              fVar9 = unaff_ESI;
            }
            fStack_50 = (float)piVar6[-0xb] * _DAT_009c3138 * fVar9;
            local_4c = (int *)((float)piVar6[-10] * _DAT_009c3138 * fVar9);
            piVar4[4] = (int)fStack_50;
            piVar4[5] = (int)local_4c;
            (**(code **)(*piStack_4 + 0x78))(piVar4);
            piVar4 = piStack_60 + 0x11;
            piVar6 = piVar6 + 0x11;
            if (piVar4 == local_4c) break;
            piStack_60 = piVar4;
          }
        }
      }
    }
  }
  return piVar4;
}


// ==== FUN_005d0460 @ 0x005d0460 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d0460(int param_1)

{
  int iVar1;
  float *pfVar2;
  uint *puVar3;
  float fVar4;
  undefined4 uVar5;
  uint uVar6;
  int in_ECX;
  uint uVar7;
  float local_10;
  int local_c;
  uint local_8 [2];
  
  local_c = 0;
  uVar7 = *(uint *)(param_1 + 8);
  while( true ) {
    uVar6 = uVar7 / 10;
    uVar7 = uVar7 % 10;
    iVar1 = *(int *)(in_ECX + 0x3c);
    local_8[0] = uVar7;
    if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x40) - iVar1 >> 2) <= uVar7)) break;
    local_10 = (float)*(int *)(iVar1 + uVar7 * 4);
    if (*(int *)(iVar1 + uVar7 * 4) < 0) {
      local_10 = local_10 + _DAT_0099d104;
    }
    iVar1 = *(int *)(param_1 + 0x38);
    if ((iVar1 == 0) ||
       ((uint)(*(int *)(param_1 + 0x40) - iVar1 >> 2) <=
        (uint)(*(int *)(param_1 + 0x3c) - iVar1 >> 2))) {
      FUN_00446120(*(undefined4 *)(param_1 + 0x3c),1,&local_10);
    }
    else {
      pfVar2 = *(float **)(param_1 + 0x3c);
      *pfVar2 = local_10;
      *(float **)(param_1 + 0x3c) = pfVar2 + 1;
    }
    iVar1 = *(int *)(param_1 + 0x28);
    if ((iVar1 == 0) ||
       ((uint)(*(int *)(param_1 + 0x30) - iVar1 >> 2) <=
        (uint)(*(int *)(param_1 + 0x2c) - iVar1 >> 2))) {
      FUN_0042f3e0(*(undefined4 *)(param_1 + 0x2c),1,local_8);
    }
    else {
      puVar3 = *(uint **)(param_1 + 0x2c);
      *puVar3 = uVar7;
      *(uint **)(param_1 + 0x2c) = puVar3 + 1;
    }
    uVar5 = DAT_009c3160;
    iVar1 = *(int *)(in_ECX + 0x3c);
    if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x40) - iVar1 >> 2) <= uVar7)) break;
    local_c = local_c + *(int *)(iVar1 + uVar7 * 4);
    uVar7 = uVar6;
    if (uVar6 == 0) {
      fVar4 = (float)local_c;
      if (local_c < 0) {
        fVar4 = fVar4 + _DAT_0099d104;
      }
      *(float *)(param_1 + 0xc) = fVar4;
      *(undefined4 *)(param_1 + 0x10) = uVar5;
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0042f370();
}


// ==== FUN_005d05d0 @ 0x005d05d0 ====

/* WARNING: Removing unreachable block (ram,0x005d061b) */
/* WARNING: Removing unreachable block (ram,0x005d0627) */
/* WARNING: Removing unreachable block (ram,0x005d0633) */

void FUN_005d05d0(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  in_ECX[2] = param_1;
  *in_ECX = &PTR_FUN_009c3168;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0xf;
  *(undefined1 *)(in_ECX + 8) = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  param_1 = 0xe;
  FUN_0042f3e0(in_ECX[0x10],1,&param_1);
  iVar1 = in_ECX[0xf];
  param_1 = 10;
  if ((iVar1 == 0) || ((uint)(in_ECX[0x11] - iVar1 >> 2) <= (uint)(in_ECX[0x10] - iVar1 >> 2))) {
    FUN_0042f3e0(in_ECX[0x10],1,&param_1);
  }
  else {
    puVar2 = (undefined4 *)in_ECX[0x10];
    *puVar2 = 10;
    in_ECX[0x10] = puVar2 + 1;
  }
  iVar1 = in_ECX[0xf];
  param_1 = 0xf;
  if ((iVar1 == 0) || ((uint)(in_ECX[0x11] - iVar1 >> 2) <= (uint)(in_ECX[0x10] - iVar1 >> 2))) {
    FUN_0042f3e0(in_ECX[0x10],1,&param_1);
  }
  else {
    puVar2 = (undefined4 *)in_ECX[0x10];
    *puVar2 = 0xf;
    in_ECX[0x10] = puVar2 + 1;
  }
  iVar1 = in_ECX[0xf];
  param_1 = 0xe;
  if ((iVar1 == 0) || ((uint)(in_ECX[0x11] - iVar1 >> 2) <= (uint)(in_ECX[0x10] - iVar1 >> 2))) {
    FUN_0042f3e0(in_ECX[0x10],1,&param_1);
  }
  else {
    puVar2 = (undefined4 *)in_ECX[0x10];
    *puVar2 = 0xe;
    in_ECX[0x10] = puVar2 + 1;
  }
  iVar1 = in_ECX[0xf];
  param_1 = 0xe;
  if ((iVar1 == 0) || ((uint)(in_ECX[0x11] - iVar1 >> 2) <= (uint)(in_ECX[0x10] - iVar1 >> 2))) {
    FUN_0042f3e0(in_ECX[0x10],1,&param_1);
  }
  else {
    puVar2 = (undefined4 *)in_ECX[0x10];
    *puVar2 = 0xe;
    in_ECX[0x10] = puVar2 + 1;
  }
  iVar1 = in_ECX[0xf];
  param_1 = 0x10;
  if ((iVar1 == 0) || ((uint)(in_ECX[0x11] - iVar1 >> 2) <= (uint)(in_ECX[0x10] - iVar1 >> 2))) {
    FUN_0042f3e0(in_ECX[0x10],1,&param_1);
  }
  else {
    puVar2 = (undefined4 *)in_ECX[0x10];
    *puVar2 = 0x10;
    in_ECX[0x10] = puVar2 + 1;
  }
  iVar1 = in_ECX[0xf];
  param_1 = 0xe;
  if ((iVar1 == 0) || ((uint)(in_ECX[0x11] - iVar1 >> 2) <= (uint)(in_ECX[0x10] - iVar1 >> 2))) {
    FUN_0042f3e0(in_ECX[0x10],1,&param_1);
  }
  else {
    puVar2 = (undefined4 *)in_ECX[0x10];
    *puVar2 = 0xe;
    in_ECX[0x10] = puVar2 + 1;
  }
  iVar1 = in_ECX[0xf];
  param_1 = 0xe;
  if ((iVar1 == 0) || ((uint)(in_ECX[0x11] - iVar1 >> 2) <= (uint)(in_ECX[0x10] - iVar1 >> 2))) {
    FUN_0042f3e0(in_ECX[0x10],1,&param_1);
  }
  else {
    puVar2 = (undefined4 *)in_ECX[0x10];
    *puVar2 = 0xe;
    in_ECX[0x10] = puVar2 + 1;
  }
  iVar1 = in_ECX[0xf];
  param_1 = 0xd;
  if ((iVar1 == 0) || ((uint)(in_ECX[0x11] - iVar1 >> 2) <= (uint)(in_ECX[0x10] - iVar1 >> 2))) {
    FUN_0042f3e0(in_ECX[0x10],1,&param_1);
  }
  else {
    puVar2 = (undefined4 *)in_ECX[0x10];
    *puVar2 = 0xd;
    in_ECX[0x10] = puVar2 + 1;
  }
  iVar1 = in_ECX[0xf];
  param_1 = 0xe;
  if ((iVar1 == 0) || ((uint)(in_ECX[0x11] - iVar1 >> 2) <= (uint)(in_ECX[0x10] - iVar1 >> 2))) {
    FUN_0042f3e0(in_ECX[0x10],1,&param_1);
  }
  else {
    puVar2 = (undefined4 *)in_ECX[0x10];
    *puVar2 = 0xe;
    in_ECX[0x10] = puVar2 + 1;
  }
  uVar3 = (**(code **)(*DAT_00b5afb8 + 0x1c))();
  in_ECX[0x12] = uVar3;
  return;
}


// ==== FUN_005d0900 @ 0x005d0900 ====

/* WARNING: Removing unreachable block (ram,0x005d095c) */

void FUN_005d0900(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3168;
  if (in_ECX[4] != 0) {
    FUN_005d0d30(in_ECX[4],in_ECX[5],in_ECX + 3);
    _free((void *)in_ECX[4]);
    return;
  }
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  if ((void *)in_ECX[0xf] != (void *)0x0) {
    _free((void *)in_ECX[0xf]);
    return;
  }
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  if (0xf < (uint)in_ECX[0xd]) {
    _free((void *)in_ECX[8]);
    return;
  }
  in_ECX[0xd] = 0xf;
  in_ECX[0xc] = 0;
  *(undefined1 *)(in_ECX + 8) = 0;
  if (in_ECX[4] == 0) {
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    return;
  }
  FUN_005d0d30(in_ECX[4],in_ECX[5],in_ECX + 3);
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_005d09c0 @ 0x005d09c0 ====

undefined4 FUN_005d09c0(uint param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  int iVar3;
  int local_8;
  
  iVar3 = *(int *)(in_ECX + 0x10);
  local_8 = 1;
  if (iVar3 != *(int *)(in_ECX + 0x14)) {
    do {
      if (param_1 < *(uint *)(iVar3 + 4)) {
        uVar2 = *(uint *)(iVar3 + 4) - param_1;
        *(uint *)(iVar3 + 4) = uVar2;
        if ((((*(int *)(in_ECX + 0x10) != 0) &&
             (iVar1 = (*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10)) / 0x44, 1 < iVar1)) &&
            (local_8 < iVar1)) && (param_1 < uVar2)) {
          *(uint *)(iVar3 + 4) = uVar2 - param_1;
        }
        local_8 = local_8 + 1;
        iVar3 = iVar3 + 0x44;
      }
      else {
        FUN_005d0df0(iVar3 + 0x44,*(undefined4 *)(in_ECX + 0x14),iVar3,param_1);
        FUN_005d0d30(*(int *)(in_ECX + 0x14) + -0x44,*(int *)(in_ECX + 0x14),in_ECX + 0xc,param_1);
        *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + -0x44;
        local_8 = local_8 + -1;
      }
    } while (iVar3 != *(int *)(in_ECX + 0x14));
  }
  return 1;
}


// ==== FUN_005d0a80 @ 0x005d0a80 ====

void FUN_005d0a80(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_009c3184;
  if (param_1 == 0) {
    uVar2 = DAT_009c3188;
  }
  else {
    if (param_1 != 1) {
      if (param_1 != 5) {
        FUN_005d0460(param_2);
        return;
      }
      uVar2 = DAT_009c317c;
      goto LAB_005d0a97;
    }
    uVar2 = DAT_009c3180;
  }
LAB_005d0a97:
  *(undefined4 *)(param_2 + 0xc) = uVar2;
  *(undefined4 *)(param_2 + 0x10) = uVar1;
  return;
}


// ==== FUN_005d0af0 @ 0x005d0af0 ====

void FUN_005d0af0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  float unaff_ESI;
  float10 fVar3;
  float fVar4;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_4c;
  undefined4 uStack_48;
  undefined4 auStack_44 [2];
  uint uStack_3c;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  undefined4 uStack_24;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar2 = (**(code **)(*DAT_00b5af48 + 8))();
  if (*(char *)(iVar2 + 2) == '\0') {
    return;
  }
  iVar2 = *(int *)(param_1 + 8);
  iVar1 = *(int *)(param_1 + 0xc);
  uStack_3c = *(uint *)(param_1 + 0x10);
  uStack_48 = *(undefined4 *)(param_1 + 0x14);
  if (1000000000 < uStack_3c) {
    return;
  }
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  FUN_005d0a80(iVar2,auStack_44);
  uStack_24 = FUN_005d0030(iVar2,iVar1);
  (**(code **)(**(int **)(in_ECX + 8) + 0x3c))(&fStack_68);
  fVar3 = (float10)(**(code **)(**(int **)(in_ECX + 8) + 0x40))();
  fVar4 = (float)fVar3;
  if (iVar1 == 2) {
    (**(code **)(**(int **)(in_ECX + 8) + 0x38))(&fStack_64);
    if (DAT_0099d0b4 < fStack_4c) {
      unaff_ESI = fStack_64 * (fStack_4c - DAT_0099d0b4) + unaff_ESI;
      fStack_68 = fStack_60 * (fStack_4c - DAT_0099d0b4) + fStack_68;
      fVar4 = fVar4 + DAT_009b0ec8;
    }
  }
  else {
    fVar3 = (float10)(**(code **)(**(int **)(in_ECX + 8) + 0x44))();
    fVar4 = (float)(fVar3 + fVar3 + (float10)fVar4);
  }
  fStack_5c = fStack_68;
  fStack_2c = fStack_68;
  if ((iVar2 == 7) || (iVar2 == 8)) {
    uStack_48 = *(undefined4 *)(*(int *)(in_ECX + 0x48) + 4);
  }
  else {
    uStack_48 = **(undefined4 **)(in_ECX + 0x48);
  }
  fStack_64 = unaff_ESI;
  fStack_60 = fVar4;
  auStack_44[0] = uStack_48;
  fStack_34 = unaff_ESI;
  fStack_30 = fVar4;
  FUN_005d14c0(&uStack_48);
  FUN_005d0cb0();
  return;
}


// ==== FUN_005d0c90 @ 0x005d0c90 ====

int FUN_005d0c90(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  return (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x44;
}


// ==== FUN_005d0cb0 @ 0x005d0cb0 ====

void FUN_005d0cb0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x38) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x38));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  if (*(void **)(in_ECX + 0x28) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x28) = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    *(undefined4 *)(in_ECX + 0x30) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x28));
  return;
}


// ==== FUN_005d0cf0 @ 0x005d0cf0 ====

void FUN_005d0cf0(int param_1)

{
  if (*(void **)(param_1 + 0x38) != (void *)0x0) {
    _free(*(void **)(param_1 + 0x38));
    return;
  }
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  if (*(void **)(param_1 + 0x28) == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
    *(undefined4 *)(param_1 + 0x30) = 0;
    return;
  }
  _free(*(void **)(param_1 + 0x28));
  return;
}


// ==== FUN_005d0d30 @ 0x005d0d30 ====

void FUN_005d0d30(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (undefined4 *)(param_1 + 0x38);
    do {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
        return;
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      if ((void *)puVar1[-4] != (void *)0x0) {
        _free((void *)puVar1[-4]);
        return;
      }
      puVar1[-4] = 0;
      puVar1[-3] = 0;
      puVar1[-2] = 0;
      param_1 = param_1 + 0x44;
      puVar1 = puVar1 + 0x11;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_005d0d90 @ 0x005d0d90 ====

void FUN_005d0d90(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  in_ECX[8] = param_1[8];
  FUN_00430c20(param_1 + 9);
  FUN_00430c20(param_1 + 0xd);
  return;
}


// ==== FUN_005d0df0 @ 0x005d0df0 ====

undefined4 * FUN_005d0df0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    param_3[3] = param_1[3];
    param_3[4] = param_1[4];
    param_3[5] = param_1[5];
    param_3[6] = param_1[6];
    param_3[7] = param_1[7];
    param_3[8] = param_1[8];
    FUN_00430ad0(param_1 + 9);
    FUN_00430ad0(param_1 + 0xd);
    param_1 = param_1 + 0x11;
    param_3 = param_3 + 0x11;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_005d0e70 @ 0x005d0e70 ====

int FUN_005d0e70(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x44;
    *(undefined4 *)(param_3 + -0x44) = *(undefined4 *)(param_2 + -0x44);
    iVar2 = param_3 + -0x44;
    *(undefined4 *)(param_3 + -0x40) = *(undefined4 *)(param_2 + -0x40);
    *(undefined4 *)(param_3 + -0x3c) = *(undefined4 *)(param_2 + -0x3c);
    *(undefined4 *)(param_3 + -0x38) = *(undefined4 *)(param_2 + -0x38);
    *(undefined4 *)(param_3 + -0x34) = *(undefined4 *)(param_2 + -0x34);
    *(undefined4 *)(param_3 + -0x30) = *(undefined4 *)(param_2 + -0x30);
    *(undefined4 *)(param_3 + -0x2c) = *(undefined4 *)(param_2 + -0x2c);
    *(undefined4 *)(param_3 + -0x28) = *(undefined4 *)(param_2 + -0x28);
    *(undefined4 *)(param_3 + -0x24) = *(undefined4 *)(param_2 + -0x24);
    FUN_00430ad0(param_2 + -0x20);
    FUN_00430ad0(param_2 + -0x10);
    param_2 = iVar1;
    param_3 = iVar2;
  } while (iVar1 != param_1);
  return iVar2;
}


// ==== FUN_005d0ef0 @ 0x005d0ef0 ====

void FUN_005d0ef0(undefined4 param_1,undefined4 param_2)

{
  FUN_005d0d30(param_1,param_2);
  return;
}


// ==== FUN_005d0f10 @ 0x005d0f10 ====

void FUN_005d0f10(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      param_1[2] = param_3[2];
      param_1[3] = param_3[3];
      param_1[4] = param_3[4];
      param_1[5] = param_3[5];
      param_1[6] = param_3[6];
      param_1[7] = param_3[7];
      param_1[8] = param_3[8];
      FUN_00430ad0(param_3 + 9);
      FUN_00430ad0(param_3 + 0xd);
      param_1 = param_1 + 0x11;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_005d0f90 @ 0x005d0f90 ====

void FUN_005d0f90(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    FUN_005d0d90(param_2);
  }
  return;
}


// ==== FUN_005d0fb0 @ 0x005d0fb0 ====

int FUN_005d0fb0(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982c20;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x44) {
    FUN_005d0f90(param_3,param_1);
    param_3 = param_3 + 0x44;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005d101a @ 0x005d101a ====

void Catch_005d101a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x44) {
    FUN_005d0cf0(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d1040 @ 0x005d1040 ====

void FUN_005d1040(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982c30;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005d0f90(param_1,param_3);
    param_1 = param_1 + 0x44;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005d10aa @ 0x005d10aa ====

void Catch_005d10aa(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x44) {
    FUN_005d0cf0(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d10d0 @ 0x005d10d0 ====

void FUN_005d10d0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005d0fb0(param_1,param_2,param_3);
  return;
}


// ==== FUN_005d10f0 @ 0x005d10f0 ====

void FUN_005d10f0(byte param_1)

{
  void *in_ECX;
  
  FUN_005d0900();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005d1110 @ 0x005d1110 ====

int FUN_005d1110(int param_1,int param_2,undefined4 param_3)

{
  FUN_005d1040(param_1,param_2,param_3);
  return param_1 + param_2 * 0x44;
}


// ==== FUN_005d1140 @ 0x005d1140 ====

void FUN_005d1140(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined1 local_80 [2];
  undefined1 auStack_7e [38];
  void *local_58;
  void *local_48;
  undefined4 local_3c;
  int local_2c;
  uint local_28;
  void *local_20;
  int local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982c40;
  local_10 = ExceptionList;
  local_14 = local_80 + -0xc;
  ExceptionList = &local_10;
  FUN_005d0d90(param_3);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x44;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
    }
    if (0x3c3c3c3U - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x3c3c3c3 - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
      }
      if (uVar4 < iVar2 + param_2) {
        iVar2 = FUN_005d0c90();
        uVar4 = iVar2 + param_2;
      }
      local_28 = uVar4 * 0x44;
      local_20 = operator_new(local_28);
      local_8 = 0;
      local_18 = local_20;
      local_18 = (void *)FUN_005d10d0(*(undefined4 *)(in_ECX + 4),param_1,local_20);
      local_18 = (void *)FUN_005d1110(local_18,param_2,local_80);
      FUN_005d10d0(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x44;
      }
      if (iVar2 != 0) {
        FUN_005d0d30(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_28 + (int)local_20;
      *(void **)(in_ECX + 8) = (void *)((int)local_20 + (param_2 + iVar1) * 0x44);
      *(void **)(in_ECX + 4) = local_20;
    }
    else {
      local_2c = *(int *)(in_ECX + 8);
      if ((uint)((local_2c - param_1) / 0x44) < param_2) {
        local_1c = param_2 * 0x44;
        FUN_005d0fb0(param_1,local_2c,local_1c + param_1);
        local_8 = 2;
        FUN_005d1110(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x44,local_80
                    );
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_1c;
        FUN_005d0f10(param_1,*(int *)(in_ECX + 8) - local_1c,local_80);
      }
      else {
        local_1c = param_2 * 0x44;
        iVar2 = local_2c + param_2 * -0x44;
        uVar3 = FUN_005d0fb0(iVar2,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_005d0e70(param_1,iVar2,local_2c,local_3c);
        FUN_005d0f10(param_1,local_1c + param_1,local_80);
      }
    }
  }
  if (local_48 != (void *)0x0) {
    _free(local_48);
    return;
  }
  if (local_58 == (void *)0x0) {
    ExceptionList = local_10;
    return;
  }
  _free(local_58);
  return;
}


// ==== Catch@005d12f7 @ 0x005d12f7 ====

void Catch_005d12f7(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x1c);
  FUN_005d0ef0(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@005d13af @ 0x005d13af ====

void Catch_005d13af(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x44;
  FUN_005d0ef0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x20) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d1450 @ 0x005d1450 ====

void FUN_005d1450(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x44 != 0) {
      iVar1 = (param_2 - iVar1) / 0x44;
      goto LAB_005d1495;
    }
  }
  iVar1 = 0;
LAB_005d1495:
  FUN_005d1140(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x44;
  return;
}


// ==== FUN_005d14c0 @ 0x005d14c0 ====

void FUN_005d14c0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x44) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x44))) {
    FUN_005d1450(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005d1040(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x44;
  return;
}


// ==== FUN_005d1550 @ 0x005d1550 ====

undefined4 FUN_005d1550(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x005d155b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return uVar1;
}


// ==== FUN_005d1570 @ 0x005d1570 ====

undefined4 FUN_005d1570(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x28) + 4))(param_1);
  (**(code **)(**(int **)(in_ECX + 0x2c) + 4))(param_1);
  (**(code **)(**(int **)(in_ECX + 0x30) + 4))(param_1);
  (**(code **)(**(int **)(in_ECX + 0x34) + 4))(param_1);
  return 1;
}


// ==== FUN_005d15b0 @ 0x005d15b0 ====

void FUN_005d15b0(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0xd2) = 0;
  *(undefined1 *)(in_ECX + 0xd3) = 0;
  *(undefined1 *)(in_ECX + 0xd0) = 0;
  *(undefined1 *)(in_ECX + 0xd1) = 0;
  (**(code **)(**(int **)(in_ECX + 0x28) + 0x14))();
  (**(code **)(**(int **)(in_ECX + 0x2c) + 0x14))();
  (**(code **)(**(int **)(in_ECX + 0x30) + 0x14))();
                    /* WARNING: Could not recover jumptable at 0x005d15eb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x34) + 0x14))();
  return;
}


// ==== FUN_005d15f0 @ 0x005d15f0 ====

void FUN_005d15f0(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x28) + 8))(param_1,param_2);
  (**(code **)(**(int **)(in_ECX + 0x2c) + 8))(param_1,param_2);
  (**(code **)(**(int **)(in_ECX + 0x30) + 8))(param_1,param_2);
  (**(code **)(**(int **)(in_ECX + 0x34) + 8))(param_1,param_2);
  return;
}


// ==== FUN_005d1630 @ 0x005d1630 ====

void FUN_005d1630(int param_1,undefined1 param_2)

{
  int in_ECX;
  
  if (param_1 == 0) {
    *(undefined1 *)(in_ECX + 0xd2) = param_2;
    return;
  }
  *(undefined1 *)(in_ECX + 0xd3) = param_2;
  return;
}


// ==== FUN_005d1660 @ 0x005d1660 ====

undefined1 FUN_005d1660(int param_1)

{
  int in_ECX;
  
  if (param_1 == 0) {
    return *(undefined1 *)(in_ECX + 0xd2);
  }
  return *(undefined1 *)(in_ECX + 0xd3);
}


// ==== FUN_005d1680 @ 0x005d1680 ====

void FUN_005d1680(undefined4 *param_1,int param_2)

{
  int in_ECX;
  
  if (param_2 == 0) {
    *param_1 = *(undefined4 *)(in_ECX + 0xb8);
    param_1[1] = *(undefined4 *)(in_ECX + 0xbc);
    param_1[2] = *(undefined4 *)(in_ECX + 0xc0);
    return;
  }
  *param_1 = *(undefined4 *)(in_ECX + 0xc4);
  param_1[1] = *(undefined4 *)(in_ECX + 200);
  param_1[2] = *(undefined4 *)(in_ECX + 0xcc);
  return;
}


// ==== FUN_005d16d0 @ 0x005d16d0 ====

void FUN_005d16d0(undefined4 *param_1,int param_2)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(in_ECX + 0x38);
  if (param_2 != 0) {
    puVar2 = (undefined4 *)(in_ECX + 0x78);
  }
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_005d1710 @ 0x005d1710 ====

void FUN_005d1710(void)

{
  int in_ECX;
  undefined4 *unaff_retaddr;
  undefined1 local_40 [44];
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0x2c))(local_40);
  *unaff_retaddr = uStack_14;
  unaff_retaddr[1] = uStack_10;
  unaff_retaddr[2] = uStack_c;
  return;
}


// ==== FUN_005d1750 @ 0x005d1750 ====

undefined4 FUN_005d1750(undefined4 param_1)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 8) + 0x38))(param_1);
  return param_1;
}


// ==== FUN_005d1770 @ 0x005d1770 ====

void FUN_005d1770(undefined4 param_1)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 uVar3;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c319c;
  in_ECX[2] = param_1;
  in_ECX[9] = 0xf;
  in_ECX[8] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  *(undefined1 *)(in_ECX + 0x34) = 0;
  *(undefined1 *)((int)in_ECX + 0xd1) = 0;
  *(undefined1 *)((int)in_ECX + 0xd2) = 0;
  *(undefined1 *)((int)in_ECX + 0xd3) = 0;
  in_ECX[0x35] = 0;
  pvVar2 = operator_new(0x4c);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005da860(in_ECX);
  }
  in_ECX[10] = uVar3;
  pvVar2 = operator_new(0xd4);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005d8eb0(in_ECX);
  }
  in_ECX[0xb] = uVar3;
  pvVar2 = operator_new(0xa0);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005d7e00(in_ECX);
  }
  in_ECX[0xc] = uVar3;
  pvVar2 = operator_new(0x1c);
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_005d73b0(in_ECX);
  }
  uVar1 = DAT_0099d080;
  in_ECX[0xd] = uVar3;
  in_ECX[0x2c] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x27] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x22] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x2d] = uVar1;
  in_ECX[0x28] = uVar1;
  in_ECX[0x23] = uVar1;
  in_ECX[0x1e] = uVar1;
  in_ECX[0x1c] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x1d] = uVar1;
  in_ECX[0x18] = uVar1;
  in_ECX[0x13] = uVar1;
  in_ECX[0xe] = uVar1;
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  in_ECX[0x31] = 0;
  in_ECX[0x32] = 0;
  in_ECX[0x33] = 0;
  return;
}


// ==== FUN_005d1970 @ 0x005d1970 ====

void FUN_005d1970(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c319c;
  if ((undefined4 *)in_ECX[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[10])(1);
  }
  in_ECX[10] = 0;
  if ((undefined4 *)in_ECX[0xb] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xb])(1);
  }
  in_ECX[0xb] = 0;
  if ((undefined4 *)in_ECX[0xc] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xc])(1);
  }
  in_ECX[0xc] = 0;
  if ((undefined4 *)in_ECX[0xd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xd])(1);
  }
  in_ECX[0xd] = 0;
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[8] = 0;
    in_ECX[9] = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_005d19e0 @ 0x005d19e0 ====

void FUN_005d19e0(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iStack_60;
  int iStack_5c;
  undefined1 *puStack_58;
  int iStack_54;
  int iStack_50;
  undefined1 *puStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  undefined1 local_30 [12];
  undefined4 auStack_24 [4];
  int iStack_14;
  int iStack_10;
  
  iStack_48 = *(int *)(param_1 + 4);
  if (iStack_48 != 0) {
    if ((*(int *)(param_1 + 8) - iStack_48) / 0x1c != 0) {
      iVar2 = in_ECX + 0x38;
      puStack_4c = local_30;
      iStack_50 = 0x5d1a28;
      uStack_44 = iVar2;
      thunk_FUN_0079e5a0();
      iStack_54 = *(int *)(param_1 + 4);
      if ((iStack_54 == 0) || ((uint)((*(int *)(param_1 + 8) - iStack_54) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
        iStack_50 = 0x5d1a53;
        FUN_0085b340();
      }
      iStack_54 = iStack_54 + 0x1c;
      puStack_58 = local_30;
      iStack_5c = 0x5d1a62;
      iStack_50 = iVar2;
      thunk_FUN_0079e5a0();
      iStack_60 = *(int *)(iStack_10 + 4);
      if (iStack_60 != 0) {
        iStack_14 = (*(int *)(iStack_10 + 8) - iStack_60) / 0x1c;
        if (iStack_14 != 0) {
          iStack_5c = iVar2;
          thunk_FUN_0079e5a0(auStack_24);
          iVar1 = *(int *)(iStack_10 + 4);
          if ((iVar1 == 0) || ((uint)((*(int *)(iStack_10 + 8) - iVar1) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
            FUN_0085b340();
          }
          thunk_FUN_0079e5a0(local_30 + -0xc,iVar1 + 0x1c,iVar2);
          if (*(char *)(in_ECX + 0xd0) == '\x01') {
            (**(code **)(**(int **)(in_ECX + 0x34) + 0xc))(&iStack_60,&iStack_54,auStack_24[0]);
            *(undefined1 *)(in_ECX + 0xd0) = 0;
          }
          iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
          if ((uint)(iVar2 - *(int *)(in_ECX + 0xd4)) < 600) {
            (**(code **)(**(int **)(in_ECX + 0x28) + 0xc))(&iStack_60,&iStack_54,auStack_24[0]);
            if (1 < *(byte *)(*(int *)(in_ECX + 0xd8) + 4)) {
              (**(code **)(**(int **)(in_ECX + 0x30) + 0xc))(&iStack_60,&iStack_54,auStack_24[0]);
            }
          }
          if (*(char *)(*(int *)(in_ECX + 0xd8) + 1) != '\0') {
            (**(code **)(**(int **)(in_ECX + 0x2c) + 0xc))(local_30 + -0xc,&iStack_48,auStack_24[0])
            ;
          }
          *(int *)(in_ECX + 0xb8) = iStack_60;
          *(int *)(in_ECX + 0xbc) = iStack_5c;
          *(undefined1 **)(in_ECX + 0xc0) = puStack_58;
          return;
        }
      }
                    /* WARNING: Subroutine does not return */
      iStack_5c = 0x5d1a92;
      FUN_0085b340();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0085b340();
}


// ==== FUN_005d1b90 @ 0x005d1b90 ====

void FUN_005d1b90(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iStack_60;
  int iStack_5c;
  undefined1 *puStack_58;
  int iStack_54;
  int iStack_50;
  undefined1 *puStack_4c;
  int iStack_48;
  undefined4 uStack_44;
  undefined1 local_30 [12];
  undefined4 auStack_24 [4];
  int iStack_14;
  int iStack_10;
  
  iStack_48 = *(int *)(param_1 + 4);
  if (iStack_48 != 0) {
    if ((*(int *)(param_1 + 8) - iStack_48) / 0x1c != 0) {
      iVar2 = in_ECX + 0x78;
      puStack_4c = local_30;
      iStack_50 = 0x5d1bd8;
      uStack_44 = iVar2;
      thunk_FUN_0079e5a0();
      iStack_54 = *(int *)(param_1 + 4);
      if ((iStack_54 == 0) || ((uint)((*(int *)(param_1 + 8) - iStack_54) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
        iStack_50 = 0x5d1c03;
        FUN_0085b340();
      }
      iStack_54 = iStack_54 + 0x1c;
      puStack_58 = local_30;
      iStack_5c = 0x5d1c12;
      iStack_50 = iVar2;
      thunk_FUN_0079e5a0();
      iStack_60 = *(int *)(iStack_10 + 4);
      if (iStack_60 != 0) {
        iStack_14 = (*(int *)(iStack_10 + 8) - iStack_60) / 0x1c;
        if (iStack_14 != 0) {
          iStack_5c = iVar2;
          thunk_FUN_0079e5a0(auStack_24);
          iVar1 = *(int *)(iStack_10 + 4);
          if ((iVar1 == 0) || ((uint)((*(int *)(iStack_10 + 8) - iVar1) / 0x1c) < 2)) {
                    /* WARNING: Subroutine does not return */
            FUN_0085b340();
          }
          thunk_FUN_0079e5a0(local_30 + -0xc,iVar1 + 0x1c,iVar2);
          if (*(char *)(in_ECX + 0xd1) == '\x01') {
            (**(code **)(**(int **)(in_ECX + 0x34) + 0x10))(&iStack_60,&iStack_54,auStack_24[0]);
            *(undefined1 *)(in_ECX + 0xd1) = 0;
          }
          iVar2 = (**(code **)(*DAT_00b5a6ac + 0x20))();
          if ((uint)(iVar2 - *(int *)(in_ECX + 0xd4)) < 600) {
            (**(code **)(**(int **)(in_ECX + 0x28) + 0x10))(&iStack_60,&iStack_54,auStack_24[0]);
            if (1 < *(byte *)(*(int *)(in_ECX + 0xd8) + 4)) {
              (**(code **)(**(int **)(in_ECX + 0x30) + 0x10))(&iStack_60,&iStack_54,auStack_24[0]);
            }
          }
          if (*(char *)(*(int *)(in_ECX + 0xd8) + 1) != '\0') {
            (**(code **)(**(int **)(in_ECX + 0x2c) + 0x10))
                      (local_30 + -0xc,&iStack_48,auStack_24[0]);
          }
          *(int *)(in_ECX + 0xc4) = iStack_60;
          *(int *)(in_ECX + 200) = iStack_5c;
          *(undefined1 **)(in_ECX + 0xcc) = puStack_58;
          return;
        }
      }
                    /* WARNING: Subroutine does not return */
      iStack_5c = 0x5d1c42;
      FUN_0085b340();
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_0085b340();
}


// ==== FUN_005d1d40 @ 0x005d1d40 ====

void FUN_005d1d40(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_ECX;
  void *unaff_EBX;
  undefined4 *puVar6;
  undefined4 *_Memory;
  undefined4 uStack_170;
  undefined4 *puStack_16c;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined4 uStack_150;
  undefined4 uStack_14c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  undefined4 uStack_12c;
  undefined4 uStack_128;
  int local_110;
  uint local_10c;
  undefined4 uStack_104;
  undefined4 local_fc;
  undefined4 local_f8;
  undefined4 local_f0;
  undefined4 *local_ec;
  int local_e8;
  undefined4 local_e0;
  void *local_dc;
  undefined4 local_d8;
  int local_d0 [4];
  undefined1 auStack_c0 [4];
  void *pvStack_bc;
  undefined1 auStack_b0 [8];
  undefined1 auStack_a8 [8];
  undefined4 auStack_a0 [3];
  undefined1 auStack_94 [44];
  undefined1 auStack_68 [20];
  undefined1 auStack_54 [84];
  
  *(int *)(in_ECX + 0xd8) = param_2;
  if (*(int *)(param_2 + 8) == 0) {
    puStack_16c = (undefined4 *)0x5d1d65;
    (**(code **)(**(int **)(in_ECX + 0x2c) + 0x14))();
    return;
  }
  if (*(int *)(param_2 + 8) == 2) {
    *(undefined1 *)(in_ECX + 0xd0) = 1;
    *(undefined1 *)(in_ECX + 0xd1) = 1;
  }
  puStack_16c = (undefined4 *)0x0;
  uStack_170 = (int *)&DAT_009c318e;
  *(undefined1 *)(in_ECX + 0xd2) = 1;
  *(undefined1 *)(in_ECX + 0xd3) = 1;
  local_f8 = 0xf;
  local_fc = 0;
  local_10c = local_10c & 0xffffff00;
  local_f0 = 0;
  local_ec = (undefined4 *)0x0;
  local_e8 = 0;
  local_e0 = 0;
  local_dc = (void *)0x0;
  local_d8 = 0;
  local_d0[0] = 0;
  local_d0[1] = 0;
  local_d0[2] = 0;
  local_15c = 0;
  local_158 = 0;
  local_154 = 0;
  FUN_00401740();
  puStack_16c = &local_160;
  uStack_170 = &local_110;
  (**(code **)(**(int **)(in_ECX + 8) + 0x14))();
  iVar2 = FUN_00403620(0,uStack_104);
  if (iVar2 == 0) {
    if (unaff_EBX == (void *)0x0) {
      local_160 = 0;
      local_15c = 0;
      FUN_004bce20();
      return;
    }
    _free(unaff_EBX);
    return;
  }
  (**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
  if ((local_ec == (undefined4 *)0x0) ||
     (local_d0[0] = local_e8 - (int)local_ec >> 2, local_d0[0] == 0)) {
                    /* WARNING: Subroutine does not return */
    FUN_0042f370();
  }
  _Memory = &local_15c;
  cVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x18))(*local_ec);
  if (cVar1 == '\0') {
    uStack_12c = 0;
    uStack_130 = 0;
    uStack_134 = 0;
    uStack_138 = 0;
    uStack_140 = 0;
    uStack_144 = 0;
    uStack_148 = 0;
    uStack_14c = 0;
    local_154 = 0;
    local_158 = 0;
    local_15c = 0;
    local_160 = 0;
    uStack_128 = DAT_0099d080;
    uStack_13c = DAT_0099d080;
    uStack_150 = DAT_0099d080;
  }
  thunk_FUN_0079ee7b(auStack_94,(int)register0x00000010 + -0x164,auStack_54);
  puVar5 = auStack_a0;
  puVar6 = (undefined4 *)(in_ECX + 0x38);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  if ((local_110 != 0) && (uVar3 = (int)(local_10c - local_110) >> 4, 1 < uVar3)) {
    if (uVar3 == 0) {
                    /* WARNING: Subroutine does not return */
      FUN_00438a40();
    }
    FUN_00439260(local_110);
    if ((local_110 == 0) || ((uint)((int)(local_10c - local_110) >> 4) < 2)) {
                    /* WARNING: Subroutine does not return */
      FUN_00438a40();
    }
    FUN_00439260(local_110 + 0x10);
    uVar4 = FUN_005c0d80(0);
    FUN_005d19e0(auStack_c0,&local_e0,uVar4);
    cVar1 = FUN_004036a0(&uStack_130,s_double_009c3190);
    if (cVar1 != '\0') {
      uVar3 = FUN_005b1840();
      if (((1 < uVar3) && (local_110 != 0)) && (3 < (uint)((int)(local_10c - local_110) >> 4))) {
        puVar5 = (undefined4 *)FUN_00430610(1);
        cVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x18))(*puVar5,&uStack_170);
        if (cVar1 == '\0') {
          uStack_140 = 0;
          uStack_144 = 0;
          uStack_148 = 0;
          uStack_14c = 0;
          local_154 = 0;
          local_158 = 0;
          local_15c = 0;
          local_160 = 0;
          puStack_16c = (undefined4 *)0x0;
          uStack_170 = (int *)0x0;
          uStack_13c = DAT_0099d080;
          uStack_150 = DAT_0099d080;
        }
        thunk_FUN_0079ee7b(auStack_a8,(int)register0x00000010 + -0x178,auStack_68);
        puVar5 = auStack_a0;
        puVar6 = (undefined4 *)(in_ECX + 0x78);
        for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        uVar4 = FUN_0043a730(2);
        FUN_00439260(uVar4);
        uVar4 = FUN_0043a730(3);
        FUN_00439260(uVar4);
        uVar4 = FUN_005c0d80(1);
        FUN_005d1b90(local_d0,auStack_b0,uVar4);
        FUN_00412dc0();
        FUN_00412dc0();
      }
    }
    if (_Memory != (undefined4 *)0x0) {
      _free(_Memory);
      return;
    }
    _Memory = (undefined4 *)0x0;
    uVar4 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(undefined4 *)(in_ECX + 0xd4) = uVar4;
    if (local_dc != (void *)0x0) {
      _free(local_dc);
      return;
    }
    if (pvStack_bc != (void *)0x0) {
      _free(pvStack_bc);
      return;
    }
  }
  if (_Memory == (undefined4 *)0x0) {
    FUN_004bce20();
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_005d21e0 @ 0x005d21e0 ====

void FUN_005d21e0(byte param_1)

{
  void *in_ECX;
  
  FUN_005d1970();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005d2200 @ 0x005d2200 ====

undefined4 FUN_005d2200(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) == 0) {
    return 0xffffffff;
  }
                    /* WARNING: Could not recover jumptable at 0x005d220b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x20))();
  return uVar1;
}


// ==== FUN_005d2260 @ 0x005d2260 ====

void FUN_005d2260(float *param_1,float *param_2,float *param_3)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  float fVar4;
  float fVar5;
  
  if (*param_3 < *param_2 || *param_3 == *param_2) {
    fVar5 = *param_2;
    fVar4 = *param_3;
  }
  else {
    fVar4 = *param_2;
    fVar5 = *param_3;
  }
  fVar1 = (float10)FUN_0040d0a0(fVar4,fVar5);
  if (param_3[1] < param_2[1] || param_3[1] == param_2[1]) {
    fVar5 = param_2[1];
    fVar4 = param_3[1];
  }
  else {
    fVar4 = param_2[1];
    fVar5 = param_3[1];
  }
  fVar2 = (float10)FUN_0040d0a0(fVar4,fVar5);
  if (param_3[2] < param_2[2] || param_3[2] == param_2[2]) {
    fVar5 = param_2[2];
    fVar4 = param_3[2];
  }
  else {
    fVar4 = param_2[2];
    fVar5 = param_3[2];
  }
  fVar3 = (float10)FUN_0040d0a0(fVar4,fVar5);
  *param_1 = (float)fVar1;
  param_1[1] = (float)fVar2;
  param_1[2] = (float)fVar3;
  return;
}


// ==== FUN_005d2330 @ 0x005d2330 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d2330(int *param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  int *piVar5;
  int iVar6;
  int in_ECX;
  int *piVar7;
  float10 fVar8;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (((*(int *)(in_ECX + 0x30) != 0) &&
      (*(int *)(in_ECX + 0x34) - *(int *)(in_ECX + 0x30) >> 5 != 0)) &&
     (cVar4 = (**(code **)(**(int **)(in_ECX + 0x3c) + 0x2c))(), cVar4 != '\0')) {
    piVar1 = *(int **)(in_ECX + 0x34);
    for (piVar7 = *(int **)(in_ECX + 0x30); piVar7 != piVar1; piVar7 = piVar7 + 8) {
      piVar5 = (int *)(**(code **)(*param_1 + 0xb4))();
      piVar5[6] = 1;
      fVar2 = (float)piVar7[1];
      if (piVar7[1] < 0) {
        fVar2 = fVar2 + _DAT_0099d104;
      }
      fVar3 = (float)*piVar7;
      if (*piVar7 < 0) {
        fVar3 = fVar3 + _DAT_0099d104;
      }
      fStack_10 = DAT_0099d080;
      fStack_c = DAT_0099d080;
      fStack_8 = DAT_0099d080;
      fVar8 = (float10)FUN_0040d4c0(DAT_00af5e9c * (fVar2 / fVar3));
      fStack_4 = (float)((float10)DAT_0099d080 - fVar8);
      iVar6 = FUN_0040ead0(&fStack_10);
      fVar2 = (fVar2 / fVar3) * DAT_009c16c0;
      piVar5[5] = iVar6;
      piVar5[2] = (int)(fVar2 + (float)piVar7[3]);
      iVar6 = FUN_004b3ff0((char)piVar7[2]);
      piVar5[3] = iVar6;
      iVar6 = piVar7[7];
      *piVar5 = piVar7[5];
      piVar5[1] = iVar6;
      piVar5[4] = piVar7[4];
      (**(code **)(*param_1 + 0x8c))(piVar5);
    }
  }
  return;
}


// ==== FUN_005d2470 @ 0x005d2470 ====

/* WARNING: Removing unreachable block (ram,0x005d24b1) */

void FUN_005d2470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c31e0;
  if (in_ECX[0xf] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0xf]);
    in_ECX[0xf] = 0;
  }
  if ((void *)in_ECX[0xc] != (void *)0x0) {
    _free((void *)in_ECX[0xc]);
    return;
  }
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  if ((uint)in_ECX[9] < 0x10) {
    in_ECX[8] = 0;
    in_ECX[9] = 0xf;
    *(undefined1 *)(in_ECX + 4) = 0;
    return;
  }
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_005d24f0 @ 0x005d24f0 ====

undefined4 FUN_005d24f0(int param_1)

{
  uint *puVar1;
  undefined3 uVar4;
  uint *puVar2;
  uint *puVar3;
  int in_ECX;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  
  puVar7 = *(uint **)(in_ECX + 0x30);
  uVar4 = (undefined3)((uint)puVar7 >> 8);
  if ((puVar7 == (uint *)0x0) || (*(int *)(in_ECX + 0x34) - (int)puVar7 >> 5 == 0)) {
    return CONCAT31(uVar4,1);
  }
  if (puVar7 == *(uint **)(in_ECX + 0x34)) {
    return CONCAT31(uVar4,1);
  }
  do {
    puVar7[1] = puVar7[1] + param_1;
    puVar3 = (uint *)puVar7[1];
    if ((uint *)*puVar7 < puVar3) {
      puVar1 = *(uint **)(in_ECX + 0x34);
      puVar3 = puVar7 + 8;
      if (puVar3 != puVar1) {
        puVar2 = puVar3;
        puVar6 = puVar7;
        do {
          puVar3 = puVar2 + 8;
          puVar8 = puVar6;
          for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar8 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar8 = puVar8 + 1;
          }
          puVar2 = puVar3;
          puVar6 = puVar6 + 8;
        } while (puVar3 != puVar1);
      }
      *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + -0x20;
    }
    else {
      puVar7 = puVar7 + 8;
    }
  } while (puVar7 != *(uint **)(in_ECX + 0x34));
  return CONCAT31((int3)((uint)puVar3 >> 8),1);
}


// ==== FUN_005d2580 @ 0x005d2580 ====

void FUN_005d2580(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  in_ECX[2] = param_1;
  *in_ECX = &PTR_FUN_009c31e0;
  in_ECX[8] = 0;
  in_ECX[9] = 0xf;
  *(undefined1 *)(in_ECX + 4) = 0;
  in_ECX[10] = 0;
  local_4 = 0xf;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_effect_hit_eff_blooddecal_tpack_009c31b8,0x1f);
  uVar1 = FUN_005aa220(local_1c);
  in_ECX[0xf] = uVar1;
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005d2600 @ 0x005d2600 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d2600(undefined4 param_1,char param_2)

{
  float fVar1;
  byte bVar2;
  undefined4 uVar3;
  int iVar4;
  float *pfVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined2 in_FPUControlWord;
  float10 fVar7;
  float *pfStack_70;
  undefined4 uStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float *pfStack_4c;
  undefined4 uStack_48;
  char cStack_44;
  float fStack_40;
  float fStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_4;
  
  if (param_2 != '\0') {
    pfStack_70 = (float *)0x5d261e;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x18))();
    *(undefined4 *)(in_ECX + 0x28) = uVar3;
    pfStack_70 = &fStack_40;
    (**(code **)(**(int **)(in_ECX + 8) + 0x2c))();
    iVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x38))((int)register0x00000010 + -0x68);
    fVar1 = *(float *)(iVar4 + 4);
    pfVar5 = (float *)(**(code **)(**(int **)(in_ECX + 8) + 0x38))(&fStack_60);
    fStack_58 = *pfVar5 * fVar1 + fStack_1c;
    fStack_54 = fVar1 * DAT_0099cdc8 + fStack_18;
    fStack_50 = fStack_4 * fVar1 + fStack_14;
    uStack_64 = fStack_1c - *pfVar5 * fVar1;
    fStack_60 = fStack_18 - fVar1 * DAT_0099cdc8;
    fStack_5c = fStack_14 - fStack_4 * fVar1;
    fVar7 = (float10)FUN_0040d0a0(0x41100000,0x41700000);
    fStack_4 = (float)CONCAT22(fStack_4._2_2_,in_FPUControlWord);
    uStack_48 = 0;
    pfStack_70 = (float *)(int)ROUND(fVar7 * (float10)DAT_009b012c);
    pfStack_4c = pfStack_70;
    fVar7 = (float10)FUN_0040d0a0((fVar1 + DAT_009b02a8) * DAT_0099d0b4,fVar1 * DAT_0099d0f8);
    fStack_40 = (float)fVar7;
    if ((float10)DAT_0099d0f8 <= fVar7) {
      fStack_40 = DAT_0099d0f8;
    }
    cStack_44 = param_2;
    puVar6 = (undefined4 *)FUN_005d2260(&pfStack_70,&fStack_58,&uStack_64);
    uStack_38 = *puVar6;
    uStack_34 = puVar6[1];
    uStack_30 = puVar6[2];
    FUN_0040d0a0(0,0x42900000);
    bVar2 = FUN_00802534();
    fStack_3c = DAT_00af5e9c / ((float)bVar2 * _DAT_009c31f8);
    FUN_005d2c00(&pfStack_4c);
  }
  return;
}


// ==== FUN_005d27e0 @ 0x005d27e0 ====

void FUN_005d27e0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  while (param_1 != param_2) {
    puVar1 = param_1 + 8;
    puVar3 = param_3;
    puVar4 = param_1;
    for (iVar2 = 8; param_1 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


// ==== FUN_005d2810 @ 0x005d2810 ====

void FUN_005d2810(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  while (param_1 != param_2) {
    param_2 = param_2 + -8;
    param_3 = param_3 + -8;
    puVar2 = param_2;
    puVar3 = param_3;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  return;
}


// ==== FUN_005d2840 @ 0x005d2840 ====

void FUN_005d2840(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_005d2860 @ 0x005d2860 ====

int FUN_005d2860(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982c50;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    FUN_005d2840(param_3,param_1);
    param_3 = param_3 + 0x20;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005d28c6 @ 0x005d28c6 ====

void Catch_005d28c6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d28d0 @ 0x005d28d0 ====

void FUN_005d28d0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982c60;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005d2840(param_1,param_3);
    param_1 = param_1 + 0x20;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005d2936 @ 0x005d2936 ====

void Catch_005d2936(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d2940 @ 0x005d2940 ====

void FUN_005d2940(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005d2860(param_1,param_2,param_3);
  return;
}


// ==== FUN_005d2960 @ 0x005d2960 ====

int FUN_005d2960(int param_1,int param_2,undefined4 param_3)

{
  FUN_005d28d0(param_1,param_2,param_3);
  return param_2 * 0x20 + param_1;
}


// ==== FUN_005d2990 @ 0x005d2990 ====

void FUN_005d2990(byte param_1)

{
  void *in_ECX;
  
  FUN_005d2470();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005d29b0 @ 0x005d29b0 ====

void FUN_005d29b0(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 local_50;
  int local_28;
  void *local_24;
  uint local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982c70;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x5c);
  puVar5 = &local_50;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_3;
    param_3 = param_3 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar4 >> 5;
  }
  uVar6 = CONCAT44(iVar4,iVar1);
  if (param_2 != 0) {
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 5;
    }
    ExceptionList = &local_10;
    if (0x7ffffffU - iVar4 < param_2) {
      ExceptionList = &local_10;
      uVar6 = FUN_0085b3b0();
    }
    iVar4 = (int)((ulonglong)uVar6 >> 0x20);
    local_20 = (uint)uVar6;
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar4 >> 5;
    }
    if (local_20 < iVar1 + param_2) {
      if (0x7ffffff - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar4 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar4 >> 5;
      }
      if (local_20 < iVar1 + param_2) {
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 5;
        }
        local_20 = iVar4 + param_2;
      }
      local_20 = local_20 << 5;
      pvVar2 = operator_new(local_20);
      local_8 = 0;
      local_24 = pvVar2;
      local_1c = FUN_005d2940(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      local_1c = FUN_005d2960(local_1c,param_2,&local_50);
      FUN_005d2940(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8) - (int)_Memory >> 5;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)pvVar2;
        *(void **)(in_ECX + 8) = (void *)((param_2 + iVar4) * 0x20 + (int)pvVar2);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)(local_28 - param_1 >> 5) < param_2) {
      local_18 = param_2 * 0x20;
      FUN_005d2860(param_1,local_28,local_18 + param_1);
      local_8 = 2;
      FUN_005d2960(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 5),&local_50);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_005d27e0(param_1,*(int *)(in_ECX + 8) - local_18,&local_50);
      ExceptionList = local_10;
      return;
    }
    local_18 = param_2 * 0x20;
    iVar4 = local_28 + param_2 * -0x20;
    uVar3 = FUN_005d2860(iVar4,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_005d2810(param_1,iVar4,local_28);
    FUN_005d27e0(param_1,local_18 + param_1,&local_50);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005d2b14 @ 0x005d2b14 ====

void Catch_005d2b14(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x20));
  return;
}


// ==== FUN_005d2c00 @ 0x005d2c00 ====

void FUN_005d2c00(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 5) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 5))) {
    FUN_005d29b0(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005d28d0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x20;
  return;
}


// ==== FUN_005d2c80 @ 0x005d2c80 ====

void FUN_005d2c80(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005d2c88. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc0) + 0x30))();
  return;
}


// ==== FUN_005d2c90 @ 0x005d2c90 ====

void FUN_005d2c90(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xd0);
  param_1[1] = *(undefined4 *)(in_ECX + 0xd4);
  param_1[2] = *(undefined4 *)(in_ECX + 0xd8);
  param_1[3] = *(undefined4 *)(in_ECX + 0xdc);
  param_1[4] = *(undefined4 *)(in_ECX + 0xe0);
  param_1[5] = *(undefined4 *)(in_ECX + 0xe4);
  return;
}


// ==== FUN_005d2cc0 @ 0x005d2cc0 ====

void FUN_005d2cc0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005d2cc8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc0) + 0x24))();
  return;
}


// ==== FUN_005d2cd0 @ 0x005d2cd0 ====

void FUN_005d2cd0(void)

{
  return;
}


// ==== FUN_005d2ce0 @ 0x005d2ce0 ====

void FUN_005d2ce0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005d2ce8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc0) + 0x18))();
  return;
}


// ==== FUN_005d2cf0 @ 0x005d2cf0 ====

void FUN_005d2cf0(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005d2cf8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0xc0) + 0x2c))();
  return;
}


// ==== FUN_005d2d00 @ 0x005d2d00 ====

void FUN_005d2d00(void)

{
  return;
}


// ==== FUN_005d2d10 @ 0x005d2d10 ====

undefined4 FUN_005d2d10(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 4))();
  if (iVar1 == 0x61) {
    (**(code **)(**(int **)(in_ECX + 0xc0) + 4))(param_1);
    *(undefined1 *)(in_ECX + 0xe8) = 1;
    return 1;
  }
  return 0;
}


// ==== FUN_005d2d50 @ 0x005d2d50 ====

void FUN_005d2d50(void)

{
  float fVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int *in_ECX;
  float fVar7;
  float fVar8;
  float fVar9;
  undefined4 uVar10;
  undefined1 auStack_4c [44];
  float fStack_20;
  undefined4 uStack_1c;
  float fStack_18;
  
  bVar2 = *(byte *)((int)in_ECX + 0xe9);
  piVar4 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  iVar5 = (**(code **)(*piVar4 + 4))(0,s___Doll_Human_SplitHumanBody_cpp_009c3220,0x72);
  in_ECX[0x3c] = iVar5;
  puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    iVar5 = in_ECX[0x3c];
    iVar3 = in_ECX[3];
    *puVar6 = &PTR_FUN_009b1860;
    puVar6[1] = bVar2 + 0x50 | 0x60000;
    puVar6[2] = iVar3;
    puVar6[3] = iVar5;
    *(undefined1 *)(puVar6 + 4) = 0;
  }
  FUN_00797a20(puVar6);
  (**(code **)(*in_ECX + 0x2c))(auStack_4c);
  fVar9 = (float)in_ECX[0x1c];
  uVar10 = 0;
  fVar1 = (float)in_ECX[0x1d];
  puVar6 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
  if (puVar6 == (undefined4 *)0x0) {
    FUN_00797a20(0);
    return;
  }
  fVar7 = fVar9 * DAT_0099d0b4;
  fVar8 = fVar1 * DAT_0099d0b4;
  puVar6[1] = in_ECX[0x3c];
  puVar6[3] = fStack_20 - fVar7;
  puVar6[4] = uStack_1c;
  puVar6[5] = fStack_18 - fVar8;
  puVar6[6] = fVar9;
  puVar6[7] = uVar10;
  *puVar6 = &PTR_FUN_009c32ac;
  puVar6[2] = 1;
  puVar6[8] = fVar1;
  puVar6[9] = 1;
  puVar6[10] = 0;
  puVar6[0xb] = 5000;
  FUN_00797a20(puVar6);
  return;
}


// ==== FUN_005d2ef0 @ 0x005d2ef0 ====

void FUN_005d2ef0(int *param_1)

{
  undefined4 uVar1;
  int *in_ECX;
  
  if ((in_ECX[0x2d] != 0) && (in_ECX[0x2e] - in_ECX[0x2d] >> 2 != 0)) {
    uVar1 = (**(code **)(*param_1 + 0x70))();
    (**(code **)(*in_ECX + 0xc))(param_1,uVar1);
    (**(code **)(*param_1 + 0x98))(uVar1);
    if ((char)in_ECX[2] != '\0') {
      (**(code **)(*(int *)in_ECX[0x30] + 0x50))(param_1);
    }
  }
  return;
}


// ==== FUN_005d2f50 @ 0x005d2f50 ====

undefined4 FUN_005d2f50(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 extraout_EAX;
  int in_ECX;
  int iVar5;
  void *_Memory;
  undefined4 local_1c;
  int local_18;
  int local_14;
  undefined1 local_10 [4];
  void *local_c;
  undefined4 *local_8;
  int local_4;
  
  local_14 = *(int *)(param_2 + 0x84);
  iVar5 = 0;
  _Memory = (void *)0x0;
  local_c = (void *)0x0;
  local_8 = (undefined4 *)0x0;
  local_4 = 0;
  local_18 = in_ECX;
  if (0 < local_14) {
    do {
      puVar2 = local_8;
      iVar1 = local_18;
      pvVar3 = operator_new(0x168);
      if (pvVar3 == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = FUN_005dcb80(iVar1,*(undefined1 *)(iVar1 + 0xe9));
      }
      local_1c = uVar4;
      FUN_005dd580(param_2,iVar5);
      if ((_Memory == (void *)0x0) ||
         ((uint)(local_4 - (int)_Memory >> 2) <= (uint)((int)puVar2 - (int)_Memory >> 2))) {
        FUN_005d4a30(puVar2,1,&local_1c);
        _Memory = local_c;
      }
      else {
        *puVar2 = uVar4;
        local_8 = puVar2 + 1;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < local_14);
  }
  FUN_005d4ea0(local_10);
  if (_Memory == (void *)0x0) {
    return param_1;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_005d3040 @ 0x005d3040 ====

undefined4 FUN_005d3040(undefined4 param_1,int param_2)

{
  int *piVar1;
  void *_Memory;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  uint uVar4;
  int iStack_70;
  int local_6c;
  undefined1 local_68 [4];
  void *local_64;
  int *local_60;
  int local_5c;
  undefined1 auStack_58 [4];
  void *pvStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  local_6c = *(int *)(param_2 + 0x14);
  uVar4 = 0;
  local_64 = (void *)0x0;
  local_60 = (int *)0x0;
  local_5c = 0;
  if (0 < local_6c) {
    do {
      if (*(uint *)(param_2 + 0x14) <= uVar4) {
        FUN_0079dba3();
      }
      FUN_00401740(s__s__c_mesh_009c3240,10);
      FUN_00404230(auStack_58);
      piVar1 = DAT_00b5a7cc;
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401660(auStack_58,0,0xffffffff);
      uStack_4 = 8;
      iVar2 = (**(code **)(*piVar1 + 0xc))(auStack_20);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return extraout_EAX;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      if (iVar2 == 0) {
        uVar3 = FUN_004022a0(auStack_3c,s_No_Splite_Mesh_009c324c,auStack_58);
        FUN_00796d50(uVar3);
        if (0xf < uStack_24) {
          _free(pvStack_38);
          return extraout_EAX_00;
        }
        uStack_24 = 0xf;
        uStack_28 = 0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      }
      else {
        iStack_70 = iVar2;
        if ((local_64 == (void *)0x0) ||
           ((uint)(local_5c - (int)local_64 >> 2) <= (uint)((int)local_60 - (int)local_64 >> 2))) {
          FUN_005c2140(local_60,1,&iStack_70);
        }
        else {
          *local_60 = iVar2;
          local_60 = local_60 + 1;
        }
      }
      if (0xf < uStack_40) {
        _free(pvStack_54);
        return extraout_EAX_01;
      }
      uVar4 = uVar4 + 1;
      uStack_40 = 0xf;
      uStack_44 = 0;
      pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
    } while ((int)uVar4 < local_6c);
  }
  _Memory = local_64;
  FUN_005d4ea0(local_68);
  if (_Memory == (void *)0x0) {
    return param_1;
  }
  _free(_Memory);
  return extraout_EAX_02;
}


// ==== FUN_005d3240 @ 0x005d3240 ====

undefined4 FUN_005d3240(undefined4 param_1,int param_2)

{
  int *piVar1;
  void *_Memory;
  int iVar2;
  undefined4 extraout_EAX;
  undefined4 uVar3;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 extraout_EAX_02;
  uint uVar4;
  int iStack_70;
  int local_6c;
  undefined1 local_68 [4];
  void *local_64;
  int *local_60;
  int local_5c;
  undefined1 auStack_58 [4];
  void *pvStack_54;
  undefined4 uStack_44;
  uint uStack_40;
  undefined1 auStack_3c [4];
  void *pvStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  undefined1 auStack_20 [4];
  void *pvStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  undefined4 uStack_4;
  
  local_6c = *(int *)(param_2 + 0x14);
  uVar4 = 0;
  local_64 = (void *)0x0;
  local_60 = (int *)0x0;
  local_5c = 0;
  if (0 < local_6c) {
    do {
      if (*(uint *)(param_2 + 0x14) <= uVar4) {
        FUN_0079dba3();
      }
      FUN_00401740(s__s__c_tpack_009c325c,0xb);
      FUN_00404230(auStack_58);
      piVar1 = DAT_00b5a7cc;
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      FUN_00401660(auStack_58,0,0xffffffff);
      uStack_4 = 0x10;
      iVar2 = (**(code **)(*piVar1 + 0xc))(auStack_20);
      if (0xf < uStack_8) {
        _free(pvStack_1c);
        return extraout_EAX;
      }
      uStack_8 = 0xf;
      uStack_c = 0;
      pvStack_1c = (void *)((uint)pvStack_1c & 0xffffff00);
      if (iVar2 == 0) {
        uVar3 = FUN_004022a0(auStack_3c,s_Texture_Pack_Missing_009c3268,auStack_58);
        FUN_00796d50(uVar3);
        if (0xf < uStack_24) {
          _free(pvStack_38);
          return extraout_EAX_00;
        }
        uStack_24 = 0xf;
        uStack_28 = 0;
        pvStack_38 = (void *)((uint)pvStack_38 & 0xffffff00);
      }
      else {
        iStack_70 = iVar2;
        if ((local_64 == (void *)0x0) ||
           ((uint)(local_5c - (int)local_64 >> 2) <= (uint)((int)local_60 - (int)local_64 >> 2))) {
          FUN_005d4a30(local_60,1,&iStack_70);
        }
        else {
          *local_60 = iVar2;
          local_60 = local_60 + 1;
        }
      }
      if (0xf < uStack_40) {
        _free(pvStack_54);
        return extraout_EAX_01;
      }
      uVar4 = uVar4 + 1;
      uStack_40 = 0xf;
      uStack_44 = 0;
      pvStack_54 = (void *)((uint)pvStack_54 & 0xffffff00);
    } while ((int)uVar4 < local_6c);
  }
  _Memory = local_64;
  FUN_005d4ea0(local_68);
  if (_Memory == (void *)0x0) {
    return param_1;
  }
  _free(_Memory);
  return extraout_EAX_02;
}


// ==== FUN_005d3440 @ 0x005d3440 ====

void FUN_005d3440(int param_1)

{
  undefined4 uVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  int in_ECX;
  uint uVar5;
  float *pfVar6;
  undefined4 *puVar7;
  int unaff_EDI;
  undefined4 *puVar8;
  int local_84;
  int local_80;
  undefined4 *local_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  void *pvStack_6c;
  undefined4 uStack_5c;
  uint uStack_58;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined1 local_40 [64];
  
  puVar7 = *(undefined4 **)(param_1 + 0x38);
  local_7c = *(undefined4 **)(param_1 + 0x3c);
  local_84 = in_ECX;
  if (puVar7 != local_7c) {
    do {
      local_80 = 0;
      pfVar6 = (float *)(puVar7 + 6);
      do {
        uVar5 = (uint)*pfVar6;
        if (*(int *)(param_1 + 0x58) == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(param_1 + 0x5c) - *(int *)(param_1 + 0x58) >> 2;
        }
        if ((int)uVar5 < iVar4) {
          iVar4 = *(int *)(param_1 + 0x58);
          if ((iVar4 == 0) || ((uint)(*(int *)(param_1 + 0x5c) - iVar4 >> 2) <= uVar5)) {
                    /* WARNING: Subroutine does not return */
            FUN_0042f370();
          }
          uVar1 = *(undefined4 *)(iVar4 + uVar5 * 4);
          cVar3 = (**(code **)(**(int **)(local_84 + 0xc0) + 0x1c))(uVar1,local_40);
          if (cVar3 == '\0') {
            uStack_58 = 0xf;
            uStack_5c = 0;
            pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
            FUN_00401740(s_bResult_009c3298,7);
            FUN_00406880(&uStack_70);
            if (uStack_58 < 0x10) {
              uStack_58 = 0xf;
              uStack_5c = 0;
              pvStack_6c = (void *)((uint)pvStack_6c & 0xffffff00);
              pcVar2 = (code *)swi(3);
              (*pcVar2)();
              return;
            }
            _free(pvStack_6c);
            return;
          }
          iVar4 = (**(code **)(*(int *)**(undefined4 **)(unaff_EDI + 0x50) + 0xc))(uVar1);
          thunk_FUN_0079e43e(&local_84,puVar7,iVar4 + 0xe0);
          uStack_4c = uStack_78;
          uStack_48 = uStack_74;
          puVar8 = &uStack_4c;
          uStack_44 = uStack_70;
        }
        else {
          puVar8 = puVar7;
        }
        FUN_005c2400(puVar8);
        local_80 = local_80 + 1;
        pfVar6 = pfVar6 + 1;
      } while (local_80 < 2);
      puVar7 = puVar7 + 10;
    } while (puVar7 != local_7c);
  }
  return;
}


// ==== FUN_005d35d0 @ 0x005d35d0 ====

/* WARNING: Removing unreachable block (ram,0x005d38c0) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d35d0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  float fVar4;
  void *pvVar5;
  char cVar6;
  undefined4 *puVar7;
  int in_ECX;
  int iVar8;
  undefined4 *puVar9;
  float10 fVar10;
  int *local_90;
  int *local_88;
  int *local_84;
  undefined1 local_6c [4];
  void *local_68;
  undefined4 local_64;
  undefined4 uStack_60;
  undefined1 local_5c [4];
  void *local_58;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  iVar1 = *(int *)(param_1 + 4);
  fVar4 = (float)iVar1;
  if (iVar1 < 0) {
    fVar4 = fVar4 + _DAT_0099d104;
  }
  local_90 = *(int **)(in_ECX + 0xb4);
  fVar4 = fVar4 * *(float *)(in_ECX + 0xec) * DAT_0099d0ec *
          *(float *)(*(int *)(in_ECX + 0xc0) + 0x88);
  local_84 = *(int **)(in_ECX + 0xb8);
  if (local_90 != local_84) {
    local_88 = local_90 + 1;
    do {
      puVar2 = (undefined4 *)*local_90;
      FUN_005db530(param_1);
      puVar2[4] = (float)puVar2[0x4d] * fVar4 + (float)puVar2[4];
      puVar7 = (undefined4 *)FUN_005db3c0(local_4c);
      puVar2[6] = *puVar7;
      puVar2[7] = puVar7[1];
      uVar3 = puVar7[2];
      puVar2[5] = puVar2[5] + iVar1;
      puVar2[8] = uVar3;
      fVar10 = (float10)FUN_005db470();
      puVar2[9] = (float)fVar10;
      puVar7 = (undefined4 *)FUN_005db770(local_40);
      cVar6 = *(char *)(puVar2 + 0x1a);
      puVar9 = puVar2 + 10;
      for (iVar8 = 0x10; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar9 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar9 = puVar9 + 1;
      }
      if ((cVar6 == '\0') || (cVar6 = FUN_005dba80(), cVar6 == '\0')) {
        fVar10 = (float10)FUN_005db9e0();
        puVar2[2] = (float)(fVar10 + (float10)(float)puVar2[2]);
LAB_005d387f:
        local_90 = local_90 + 1;
        local_88 = local_88 + 1;
      }
      else {
        if (puVar2[0x50] == 0) {
          if ((int)puVar2[0x4f] < 1) {
LAB_005d37c4:
            FUN_005dd8d0();
          }
          else {
            FUN_005dd970();
          }
          goto LAB_005d387f;
        }
        if (puVar2[0x50] == 1) {
          if ((uint)puVar2[0x21] < 2) {
            if ((int)puVar2[0x4f] < 2) goto LAB_005d37c4;
            FUN_005dd970();
          }
          else {
            if ((int)puVar2[0x4f] < 2) {
              FUN_005d2f50(local_5c,puVar2);
              pvVar5 = local_58;
              FUN_005d4740(0,local_58,local_54,fVar4);
              (**(code **)*puVar2)(1);
              _memmove(local_90,local_88,(*(int *)(in_ECX + 0xb8) - (int)local_88 >> 2) * 4);
              *(int *)(in_ECX + 0xb8) = *(int *)(in_ECX + 0xb8) + -4;
              local_84 = *(int **)(in_ECX + 0xb8);
              if (pvVar5 != (void *)0x0) {
                _free(pvVar5);
                return;
              }
              local_58 = (void *)0x0;
              local_54 = 0;
              uStack_50 = 0;
              goto LAB_005d388c;
            }
            FUN_005dd970();
          }
          goto LAB_005d387f;
        }
        if ((uint)puVar2[0x21] < 2) {
          if ((int)puVar2[0x4f] < 2) goto LAB_005d37c4;
          FUN_005db520();
          goto LAB_005d387f;
        }
        FUN_005d2f50(local_6c,puVar2);
        pvVar5 = local_68;
        FUN_005d4740(0,local_68,local_64,fVar4);
        (**(code **)*puVar2)(1);
        _memmove(local_90,local_88,(*(int *)(in_ECX + 0xb8) - (int)local_88 >> 2) * 4);
        *(int *)(in_ECX + 0xb8) = *(int *)(in_ECX + 0xb8) + -4;
        local_84 = *(int **)(in_ECX + 0xb8);
        if (pvVar5 != (void *)0x0) {
          _free(pvVar5);
          return;
        }
        local_68 = (void *)0x0;
        local_64 = 0;
        uStack_60 = 0;
      }
LAB_005d388c:
    } while (local_90 != local_84);
  }
  FUN_005d4740(*(undefined4 *)(in_ECX + 0xb8),0,0,fVar4);
  return;
}


// ==== FUN_005d38e0 @ 0x005d38e0 ====

undefined4 FUN_005d38e0(undefined4 param_1,int param_2)

{
  int iVar1;
  void *_Memory;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  uint uVar2;
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar1 = *(int *)(param_2 + 0x14);
  uVar2 = 0;
  local_28 = (void *)0x0;
  local_24 = 0;
  local_20 = 0;
  if (0 < iVar1) {
    do {
      if (*(uint *)(param_2 + 0x14) <= uVar2) {
        FUN_0079dba3();
      }
      FUN_00401740(s__s__c_mesh_009c3280,10);
      FUN_00404230(auStack_1c);
      FUN_00406720(auStack_1c);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return extraout_EAX;
      }
      uVar2 = uVar2 + 1;
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    } while ((int)uVar2 < iVar1);
  }
  _Memory = local_28;
  FUN_00406600(local_2c);
  if (_Memory == (void *)0x0) {
    return param_1;
  }
  FUN_00405de0(_Memory,local_24,local_2c,param_2);
  _free(_Memory);
  return extraout_EAX_00;
}


// ==== FUN_005d3a00 @ 0x005d3a00 ====

undefined4 FUN_005d3a00(undefined4 param_1,int param_2)

{
  int iVar1;
  void *_Memory;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  uint uVar2;
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  iVar1 = *(int *)(param_2 + 0x14);
  uVar2 = 0;
  local_28 = (void *)0x0;
  local_24 = 0;
  local_20 = 0;
  if (0 < iVar1) {
    do {
      if (*(uint *)(param_2 + 0x14) <= uVar2) {
        FUN_0079dba3();
      }
      FUN_00401740(s__s__c_tpack_009c328c,0xb);
      FUN_00404230(auStack_1c);
      FUN_00406720(auStack_1c);
      if (0xf < uStack_4) {
        _free(pvStack_18);
        return extraout_EAX;
      }
      uVar2 = uVar2 + 1;
      uStack_4 = 0xf;
      uStack_8 = 0;
      pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    } while ((int)uVar2 < iVar1);
  }
  _Memory = local_28;
  FUN_00406600(local_2c);
  if (_Memory == (void *)0x0) {
    return param_1;
  }
  FUN_00405de0(_Memory,local_24,local_2c,param_2);
  _free(_Memory);
  return extraout_EAX_00;
}


// ==== FUN_005d3b30 @ 0x005d3b30 ====

void FUN_005d3b30(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  char cVar1;
  char *pcVar2;
  void *pvVar3;
  int in_ECX;
  uint uVar4;
  void *pvVar5;
  uint local_e4;
  int local_e0;
  undefined1 local_dc [4];
  void *local_d8;
  int iStack_d4;
  undefined4 local_c8;
  uint local_c4;
  undefined1 auStack_c0 [4];
  void *pvStack_bc;
  int iStack_b8;
  int iStack_b0;
  undefined1 uStack_ac;
  undefined1 uStack_ab;
  undefined1 uStack_aa;
  undefined1 uStack_a9;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  void *pvStack_a0;
  undefined1 uStack_9c;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined4 uStack_88;
  void *pvStack_84;
  undefined1 uStack_80;
  undefined4 uStack_74;
  uint uStack_70;
  undefined4 uStack_6c;
  undefined1 auStack_68 [32];
  undefined4 uStack_48;
  undefined1 local_34 [32];
  undefined4 local_14;
  
  if (param_2 != 0) {
    pvVar3 = operator_new(0x168);
    if (pvVar3 == (void *)0x0) {
      local_e4 = 0;
    }
    else {
      local_e4 = FUN_005dcb80(in_ECX,*(undefined1 *)(in_ECX + 0xe9));
    }
    FUN_005dd230(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    FUN_005d4f70(&local_e4);
    return;
  }
  local_e0 = in_ECX;
  if (*(char *)(in_ECX + 8) == '\0') {
    local_c4 = 0xf;
    local_c8 = 0;
    local_d8 = (void *)((uint)local_d8 & 0xffffff00);
    pcVar2 = PTR_DAT_00af5ea0;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    FUN_00401740(PTR_DAT_00af5ea0,(int)pcVar2 - (int)(PTR_DAT_00af5ea0 + 1));
    FUN_0058f1f0(local_dc);
    if (0xf < local_c4) {
      _free(local_d8);
      return;
    }
    local_14 = 2;
    (**(code **)(**(int **)(in_ECX + 0xc0) + 4))(local_34);
    *(undefined1 *)(in_ECX + 8) = 1;
    FUN_0058f230();
  }
  local_c4 = 0xf;
  local_c8 = 0;
  local_d8 = (void *)((uint)local_d8 & 0xffffff00);
  pcVar2 = PTR_DAT_00af5ea0;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00401740(PTR_DAT_00af5ea0,(int)pcVar2 - (int)(PTR_DAT_00af5ea0 + 1));
  FUN_0058f1f0(local_dc);
  if (0xf < local_c4) {
    _free(local_d8);
    return;
  }
  uStack_48 = 0;
  uStack_88 = 0xf;
  uStack_8c = 0;
  uStack_9c = 0;
  uStack_6c = 0xf;
  uStack_70 = 0;
  uStack_80 = 0;
  uStack_a9 = 0;
  uStack_ac = 0;
  uStack_ab = 0;
  uStack_aa = 0;
  uStack_a4 = DAT_0099d080;
  uStack_a8 = 0xffffffff;
  FUN_005d38e0(auStack_c0,param_1);
  FUN_005d3a00(local_dc,param_1);
  pvVar3 = local_d8;
  if (pvStack_bc == (void *)0x0) {
    local_e4 = 0;
  }
  else {
    local_e4 = (iStack_b8 - (int)pvStack_bc) / 0x1c;
  }
  uVar4 = 0;
  if (local_e4 != 0) {
    iStack_b0 = (int)pvStack_bc - (int)local_d8;
    pvVar5 = local_d8;
    do {
      if ((pvStack_bc == (void *)0x0) || ((uint)((iStack_b8 - (int)pvStack_bc) / 0x1c) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00401660(iStack_b0 + (int)pvVar5,0,0xffffffff);
      if ((pvVar3 == (void *)0x0) || ((uint)((iStack_d4 - (int)pvVar3) / 0x1c) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_00405ca0();
      }
      FUN_00401660(pvVar5,0,0xffffffff);
      FUN_004ff800(&uStack_ac);
      uVar4 = uVar4 + 1;
      pvVar5 = (void *)((int)pvVar5 + 0x1c);
    } while (uVar4 < local_e4);
  }
  pvVar5 = pvStack_bc;
  (**(code **)(**(int **)(local_e0 + 0xc0) + 4))(auStack_68);
  if (pvVar3 != (void *)0x0) {
    FUN_00405de0(pvVar3,local_d8,&local_e0,local_e4);
    _free(pvVar3);
    return;
  }
  if (pvVar5 != (void *)0x0) {
    FUN_00405de0(pvVar5,pvStack_bc,&local_c4,local_e4);
    _free(pvVar5);
    return;
  }
  if (0xf < uStack_70) {
    _free(pvStack_84);
    return;
  }
  uStack_70 = 0xf;
  uStack_74 = 0;
  pvStack_84 = (void *)((uint)pvStack_84 & 0xffffff00);
  if (uStack_8c < 0x10) {
    uStack_8c = 0xf;
    uStack_90 = 0;
    pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
    FUN_0058f230();
    return;
  }
  _free(pvStack_a0);
  return;
}


// ==== FUN_005d3ee0 @ 0x005d3ee0 ====

uint FUN_005d3ee0(int *param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (**(code **)(*param_1 + 4))();
  if (uVar1 == 0x40001) {
    FUN_005d35d0(param_1);
    uVar1 = (**(code **)(**(int **)(in_ECX + 0xc0) + 0x4c))(param_1);
  }
  return uVar1 & 0xffffff00;
}


// ==== FUN_005d3f20 @ 0x005d3f20 ====

void FUN_005d3f20(void)

{
  undefined4 *puVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(in_ECX + 0x54);
  for (puVar2 = *(undefined4 **)(in_ECX + 0x50); puVar2 != puVar1; puVar2 = puVar2 + 0x16) {
    (**(code **)(*DAT_00b5aff4 + 8))(*puVar2);
    *puVar2 = 0;
  }
  if (*(int *)(in_ECX + 0x50) == 0) {
    *(undefined4 *)(in_ECX + 0x50) = 0;
    *(undefined4 *)(in_ECX + 0x54) = 0;
    *(undefined4 *)(in_ECX + 0x58) = 0;
    return;
  }
  FUN_005c4350(*(int *)(in_ECX + 0x50),*(undefined4 *)(in_ECX + 0x54),in_ECX + 0x4c,in_ECX);
  _free(*(void **)(in_ECX + 0x50));
  return;
}


// ==== FUN_005d3f90 @ 0x005d3f90 ====

void FUN_005d3f90(void)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  uVar1 = DAT_0099d080;
  *in_ECX = &PTR_FUN_009c32c4;
  *(undefined1 *)(in_ECX + 2) = 0;
  in_ECX[0xb] = uVar1;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  *(undefined1 *)((int)in_ECX + 0x31) = 0;
  *(undefined1 *)((int)in_ECX + 0x32) = 0xff;
  *(undefined1 *)((int)in_ECX + 0x33) = 0;
  *(undefined1 *)(in_ECX + 0xd) = 1;
  *(undefined1 *)((int)in_ECX + 0x35) = 0;
  *(undefined1 *)((int)in_ECX + 0x36) = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  in_ECX[0x11] = 0;
  in_ECX[0x12] = 0;
  in_ECX[0x14] = 0;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[0x17] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0xf;
  *(undefined1 *)(in_ECX + 0x1f) = 0;
  in_ECX[0x2b] = 0xf;
  in_ECX[0x2a] = 0;
  *(undefined1 *)(in_ECX + 0x26) = 0;
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  in_ECX[0x30] = 0;
  *(undefined1 *)(in_ECX + 0x3a) = 0;
  in_ECX[0x3b] = uVar1;
  in_ECX[1] = 5;
  return;
}


// ==== FUN_005d4050 @ 0x005d4050 ====

void FUN_005d4050(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c32c4;
  piVar1 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
  (**(code **)(*piVar1 + 8))(s___Doll_Human_SplitHumanBody_cpp_009c3200,0x18,0,in_ECX[0x3c]);
  if ((undefined4 *)in_ECX[0x30] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x30])(1);
  }
  in_ECX[0x30] = 0;
  FUN_004eb890(in_ECX + 0x2c);
  FUN_005d3f20();
  if ((void *)in_ECX[0x2d] != (void *)0x0) {
    _free((void *)in_ECX[0x2d]);
    return;
  }
  in_ECX[0x2d] = 0;
  in_ECX[0x2e] = 0;
  in_ECX[0x2f] = 0;
  if (0xf < (uint)in_ECX[0x2b]) {
    _free((void *)in_ECX[0x26]);
    return;
  }
  in_ECX[0x2b] = 0xf;
  in_ECX[0x2a] = 0;
  *(undefined1 *)(in_ECX + 0x26) = 0;
  if ((uint)in_ECX[0x24] < 0x10) {
    in_ECX[0x24] = 0xf;
    in_ECX[0x23] = 0;
    *(undefined1 *)(in_ECX + 0x1f) = 0;
    FUN_005d50f0();
    *in_ECX = &PTR_FUN_009c2504;
    return;
  }
  _free((void *)in_ECX[0x1f]);
  return;
}


// ==== FUN_005d4130 @ 0x005d4130 ====

void FUN_005d4130(undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  undefined1 local_60 [8];
  undefined1 local_58;
  uint local_54;
  undefined4 local_50;
  undefined1 local_4c;
  undefined1 local_4b;
  undefined1 local_8;
  undefined1 local_7;
  
  FUN_005d5430(in_ECX + 0x10);
  piVar1 = *(int **)(in_ECX + 0xb8);
  piVar3 = *(int **)(in_ECX + 0xb4);
  local_54 = 0xffffffff;
  local_8 = 0;
  local_7 = 0;
  local_58 = 0;
  local_4b = 1;
  local_4c = 0;
  local_50 = DAT_0099d080;
  for (; piVar3 != piVar1; piVar3 = piVar3 + 1) {
    if (*(char *)(*piVar3 + 0x69) != '\0') {
      if (*(char *)(in_ECX + 0xe8) == '\0') {
        local_54 = 0xffffffff;
      }
      else {
        *(undefined1 *)(param_2 + 0x23) = 1;
        iVar2 = FUN_00802534();
        local_54 = iVar2 << 0x18 | 0xffffff;
      }
      FUN_005dd9c0(param_1,param_2,local_60);
    }
  }
  return;
}


// ==== FUN_005d4200 @ 0x005d4200 ====

undefined4 FUN_005d4200(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int *piVar2;
  undefined1 local_60 [60];
  undefined1 auStack_24 [4];
  int *local_20;
  int *local_1c;
  void *pvStack_c;
  
  FUN_005d54e0(param_2);
  for (piVar2 = local_20; piVar2 != local_1c; piVar2 = piVar2 + 0x16) {
    if ((int *)*piVar2 != (int *)0x0) {
      iVar1 = (**(code **)(*(int *)*piVar2 + 0x18))();
      *piVar2 = iVar1;
    }
  }
  FUN_005d54e0(local_60);
  if (pvStack_c != (void *)0x0) {
    _free(pvStack_c);
    return extraout_EAX;
  }
  if (local_20 == (int *)0x0) {
    return param_1;
  }
  FUN_005c4350(local_20,local_1c,auStack_24,param_2);
  _free(local_20);
  return extraout_EAX_00;
}


// ==== FUN_005d4280 @ 0x005d4280 ====

undefined4
FUN_005d4280(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,undefined1 param_6)

{
  int iVar1;
  void *_Memory;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 *puVar3;
  undefined4 extraout_EAX_02;
  undefined4 extraout_EAX_03;
  undefined4 extraout_EAX_04;
  int in_ECX;
  float10 fVar4;
  undefined4 *local_7c;
  void *pvStack_78;
  undefined4 uStack_68;
  uint uStack_64;
  undefined1 local_60 [96];
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  *(undefined4 *)(in_ECX + 0x70) = *param_5;
  *(undefined4 *)(in_ECX + 0x74) = param_5[1];
  *(undefined1 *)(in_ECX + 0xe9) = param_6;
  _Memory = operator_new(0x60);
  if (_Memory == (void *)0x0) {
    _Memory = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)_Memory + 0x1c) = DAT_0099d080;
    *(undefined1 *)((int)_Memory + 0x20) = 0;
    *(undefined1 *)((int)_Memory + 0x21) = 0;
    *(undefined1 *)((int)_Memory + 0x22) = 0xff;
    *(undefined1 *)((int)_Memory + 0x23) = 0;
    *(undefined1 *)((int)_Memory + 0x24) = 1;
    *(undefined1 *)((int)_Memory + 0x25) = 0;
    *(undefined1 *)((int)_Memory + 0x26) = 0;
    *(undefined4 *)((int)_Memory + 0x2c) = 0;
    *(undefined4 *)((int)_Memory + 0x30) = 0;
    *(undefined4 *)((int)_Memory + 0x34) = 0;
    *(undefined4 *)((int)_Memory + 0x38) = 0;
    *(undefined4 *)((int)_Memory + 0x40) = 0;
    *(undefined4 *)((int)_Memory + 0x44) = 0;
    *(undefined4 *)((int)_Memory + 0x48) = 0;
    *(undefined4 *)((int)_Memory + 0x4c) = 0;
    *(undefined4 *)((int)_Memory + 0x54) = 0;
    *(undefined4 *)((int)_Memory + 0x58) = 0;
    *(undefined4 *)((int)_Memory + 0x5c) = 0;
  }
  FUN_005c66b0(_Memory);
  uVar2 = FUN_005d4200(local_60,_Memory);
  FUN_005d5430(uVar2);
  FUN_005d50f0();
  if (_Memory != (void *)0x0) {
    if (*(void **)((int)_Memory + 0x54) != (void *)0x0) {
      _free(*(void **)((int)_Memory + 0x54));
      return extraout_EAX;
    }
    *(undefined4 *)((int)_Memory + 0x54) = 0;
    *(undefined4 *)((int)_Memory + 0x58) = 0;
    *(undefined4 *)((int)_Memory + 0x5c) = 0;
    if (*(int *)((int)_Memory + 0x40) == 0) {
      *(undefined4 *)((int)_Memory + 0x40) = 0;
      *(undefined4 *)((int)_Memory + 0x44) = 0;
      *(undefined4 *)((int)_Memory + 0x48) = 0;
      _free(_Memory);
      return extraout_EAX_01;
    }
    FUN_005c4350(*(int *)((int)_Memory + 0x40),*(undefined4 *)((int)_Memory + 0x44),
                 (int)_Memory + 0x3c,local_7c);
    _free(*(void **)((int)_Memory + 0x40));
    return extraout_EAX_00;
  }
  puVar3 = (undefined4 *)FUN_0040d690(&local_7c,in_ECX + 0x70);
  *(undefined4 *)(in_ECX + 0x1c) = *puVar3;
  *(undefined4 *)(in_ECX + 0x20) = puVar3[1];
  *(undefined4 *)(in_ECX + 0x24) = puVar3[2];
  *(undefined4 *)(in_ECX + 0x28) = puVar3[3];
  *(undefined1 *)(in_ECX + 0x31) = 0xc;
  *(undefined1 *)(in_ECX + 0x30) = 0;
  *(undefined1 *)(in_ECX + 0x33) = 0;
  *(undefined1 *)(in_ECX + 0x36) = 0;
  if ((*(int *)(in_ECX + 0x50) == 0) ||
     (local_7c = (undefined4 *)((*(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50)) / 0x58),
     local_7c == (undefined4 *)0x0)) {
    return 0;
  }
  if ((*(int *)(in_ECX + 0x50) != 0) &&
     (1 < (uint)((*(int *)(in_ECX + 0x54) - *(int *)(in_ECX + 0x50)) / 0x58))) {
    local_7c = *(undefined4 **)(in_ECX + 0x54);
    puVar3 = (undefined4 *)(*(int *)(in_ECX + 0x50) + 0x58);
    if (puVar3 != local_7c) {
      do {
        (**(code **)(*DAT_00b5aff4 + 8))(*puVar3);
        *puVar3 = 0;
        puVar3 = puVar3 + 0x16;
      } while (puVar3 != local_7c);
    }
    puVar3 = (undefined4 *)(*(int *)(in_ECX + 0x50) + 0x58);
    if (puVar3 != local_7c) {
      uVar2 = FUN_005c4300(local_7c,*(undefined4 *)(in_ECX + 0x54),puVar3,local_7c);
      FUN_005c4350(uVar2,*(undefined4 *)(in_ECX + 0x54),in_ECX + 0x4c,local_7c);
      *(undefined4 *)(in_ECX + 0x54) = uVar2;
    }
  }
  iVar1 = *(int *)(in_ECX + 0x50);
  if (*(void **)(iVar1 + 0x4c) != (void *)0x0) {
    _free(*(void **)(iVar1 + 0x4c));
    return extraout_EAX_02;
  }
  *(undefined4 *)(iVar1 + 0x4c) = 0;
  *(undefined4 *)(iVar1 + 0x50) = 0;
  *(undefined4 *)(iVar1 + 0x54) = 0;
  FUN_00401660(param_3,0,0xffffffff);
  uStack_64 = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  FUN_00401660(in_ECX + 0x78,0,*(int *)(in_ECX + 0x8c) + -5);
  FUN_00401660(&local_7c,0,0xffffffff);
  if (0xf < uStack_64) {
    _free(pvStack_78);
    return extraout_EAX_03;
  }
  FUN_00401660(param_4,0,0xffffffff);
  uStack_64 = 0xf;
  uStack_68 = 0;
  pvStack_78 = (void *)((uint)pvStack_78 & 0xffffff00);
  FUN_00401660(in_ECX + 0x94,0,*(int *)(in_ECX + 0xa8) + -6);
  FUN_00401660(&local_7c,0,0xffffffff);
  if (uStack_64 < 0x10) {
    puVar3 = (undefined4 *)(**(code **)(*param_2 + 0x3c))(&local_7c);
    *(undefined4 *)(in_ECX + 0xc4) = *puVar3;
    *(undefined4 *)(in_ECX + 200) = puVar3[1];
    fVar4 = (float10)(**(code **)(*param_2 + 0x40))();
    *(float *)(in_ECX + 0xcc) = (float)fVar4;
    (**(code **)(*param_2 + 0x10))(in_ECX + 0xd0);
    *(int **)(in_ECX + 0xc0) = param_2;
    FUN_005d2d50();
    return 1;
  }
  _free(pvStack_78);
  return extraout_EAX_04;
}


// ==== FUN_005d45c0 @ 0x005d45c0 ====

undefined4 FUN_005d45c0(void)

{
  return 0x60010009;
}


// ==== FUN_005d45d0 @ 0x005d45d0 ====

void FUN_005d45d0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  while (param_1 != param_2) {
    puVar3 = param_1 + 0x10;
    puVar1 = param_3 + 0x10;
    puVar4 = param_1;
    puVar5 = param_3;
    for (iVar2 = 0x10; param_1 = puVar3, param_3 = puVar1, iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  return;
}


// ==== FUN_005d4600 @ 0x005d4600 ====

void FUN_005d4600(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_005d4620 @ 0x005d4620 ====

int FUN_005d4620(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982c90;
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


// ==== Catch@005d4686 @ 0x005d4686 ====

void Catch_005d4686(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d4690 @ 0x005d4690 ====

int FUN_005d4690(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982c80;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x40) {
    FUN_005d4600(param_3,param_1);
    param_3 = param_3 + 0x40;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005d46f6 @ 0x005d46f6 ====

void Catch_005d46f6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d4700 @ 0x005d4700 ====

void FUN_005d4700(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005d4690(param_1,param_2,param_3);
  return;
}


// ==== FUN_005d4720 @ 0x005d4720 ====

void FUN_005d4720(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005d4620(param_1,param_2,param_3);
  return;
}


// ==== FUN_005d4740 @ 0x005d4740 ====

void FUN_005d4740(int param_1,int param_2,int param_3)

{
  void *_Memory;
  uint uVar1;
  uint uVar2;
  void *pvVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  uint extraout_ECX;
  int iVar6;
  int iVar7;
  undefined8 uVar8;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982ca0;
  local_10 = ExceptionList;
  uVar1 = param_3 - param_2 >> 2;
  iVar6 = *(int *)(in_ECX + 4);
  uVar8 = CONCAT44(iVar6,uVar1);
  if (iVar6 == 0) {
    uVar5 = 0;
  }
  else {
    uVar5 = *(int *)(in_ECX + 0xc) - iVar6 >> 2;
  }
  if (uVar1 != 0) {
    if (iVar6 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = *(int *)(in_ECX + 8) - iVar6 >> 2;
    }
    ExceptionList = &local_10;
    if (0x3fffffffU - iVar6 < uVar1) {
      ExceptionList = &local_10;
      uVar8 = FUN_0085b3b0();
      uVar5 = extraout_ECX;
    }
    iVar6 = (int)((ulonglong)uVar8 >> 0x20);
    uVar2 = (uint)uVar8;
    if (iVar6 == 0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(in_ECX + 8) - iVar6 >> 2;
    }
    if (uVar5 < iVar7 + uVar2) {
      if (0x3fffffff - (uVar5 >> 1) < uVar5) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar5 + (uVar5 >> 1);
      }
      if (iVar6 == 0) {
        iVar7 = 0;
      }
      else {
        iVar7 = *(int *)(in_ECX + 8) - iVar6 >> 2;
      }
      if (uVar5 < iVar7 + uVar2) {
        if (iVar6 == 0) {
          iVar6 = 0;
        }
        else {
          iVar6 = *(int *)(in_ECX + 8) - iVar6 >> 2;
        }
        uVar5 = iVar6 + uVar2;
      }
      pvVar3 = operator_new(uVar5 * 4);
      local_8 = 0;
      uVar4 = FUN_005a6d90(*(undefined4 *)(in_ECX + 4),param_1,pvVar3);
      uVar4 = FUN_005d4720(param_2,param_3,uVar4);
      FUN_005a6d90(param_1,*(undefined4 *)(in_ECX + 8),uVar4);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
      }
      if (_Memory == (void *)0x0) {
        *(void **)(in_ECX + 0xc) = (void *)(uVar5 * 4 + (int)pvVar3);
        *(void **)(in_ECX + 8) = (void *)((int)pvVar3 + (uVar1 + iVar6) * 4);
        *(void **)(in_ECX + 4) = pvVar3;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    iVar6 = *(int *)(in_ECX + 8);
    if ((uint)(iVar6 - param_1 >> 2) < uVar2) {
      FUN_005a6d90(param_1,iVar6,uVar2 * 4 + param_1);
      iVar6 = param_2 + (*(int *)(in_ECX + 8) - param_1 >> 2) * 4;
      local_8 = 2;
      FUN_005d4720(iVar6,param_3,*(undefined4 *)(in_ECX + 8));
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + uVar2 * 4;
      FUN_004cf710(param_2,iVar6,param_1);
      ExceptionList = local_10;
      return;
    }
    iVar7 = iVar6 + uVar2 * -4;
    uVar4 = FUN_005a6d90(iVar7,iVar6,iVar6);
    *(undefined4 *)(in_ECX + 8) = uVar4;
    FUN_00822d20(param_1,iVar7,iVar6);
    FUN_004cf710(param_2,param_3,param_1);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005d48a2 @ 0x005d48a2 ====

void Catch_005d48a2(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x20));
  return;
}


// ==== FUN_005d4980 @ 0x005d4980 ====

undefined4 FUN_005d4980(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x2e8ba2e < param_1) {
    param_1 = FUN_0085b3b0();
  }
  pvVar1 = operator_new(param_1 * 0x58);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x58 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_005d49e0 @ 0x005d49e0 ====

undefined4 FUN_005d49e0(uint param_1)

{
  void *pvVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (param_1 == 0) {
    return 0;
  }
  if (0x3ffffff < param_1) {
    param_1 = FUN_0085b3b0();
  }
  pvVar1 = operator_new(param_1 * 0x40);
  *(void **)(in_ECX + 0xc) = (void *)(param_1 * 0x40 + (int)pvVar1);
  *(void **)(in_ECX + 4) = pvVar1;
  *(void **)(in_ECX + 8) = pvVar1;
  return 1;
}


// ==== FUN_005d4a30 @ 0x005d4a30 ====

void FUN_005d4a30(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982cb0;
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


// ==== Catch@005d4b91 @ 0x005d4b91 ====

void Catch_005d4b91(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x24));
  return;
}


// ==== FUN_005d4c80 @ 0x005d4c80 ====

void FUN_005d4c80(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982cc0;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 6;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x3ffffff < uVar1) {
      uVar1 = FUN_0085b3b0();
    }
    pvVar2 = operator_new(uVar1 * 0x40);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 0x40 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_005d4700(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005d4d37 @ 0x005d4d37 ====

void Catch_005d4d37(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d4d50 @ 0x005d4d50 ====

void FUN_005d4d50(int param_1)

{
  void *_Memory;
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  
  if (in_ECX == param_1) {
    return;
  }
  iVar3 = *(int *)(param_1 + 4);
  if (iVar3 != 0) {
    uVar5 = *(int *)(param_1 + 8) - iVar3 >> 6;
    if (uVar5 != 0) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(int *)(in_ECX + 8) - (int)_Memory >> 6;
      }
      if (uVar5 <= uVar2) {
        FUN_005d45d0(iVar3,*(int *)(param_1 + 8),_Memory);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 6) * 0x40 + *(int *)(in_ECX + 4);
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar2 = 0;
      }
      else {
        uVar2 = *(int *)(in_ECX + 0xc) - (int)_Memory >> 6;
      }
      if (uVar5 <= uVar2) {
        if (_Memory == (void *)0x0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 6;
        }
        iVar3 = iVar3 * 0x40 + *(int *)(param_1 + 4);
        FUN_005d45d0(*(int *)(param_1 + 4),iVar3,_Memory);
        uVar4 = FUN_005d4690(iVar3,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar4;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      if (*(int *)(param_1 + 4) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 6;
      }
      cVar1 = FUN_005d49e0(iVar3);
      if (cVar1 == '\0') {
        return;
      }
      uVar4 = FUN_005d4700(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar4;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_005d4ea0 @ 0x005d4ea0 ====

void FUN_005d4ea0(int param_1)

{
  uint uVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982cd0;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 4) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
  }
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  if (uVar1 != 0) {
    if (0x3fffffff < uVar1) {
      uVar1 = FUN_0085b3b0();
    }
    pvVar2 = operator_new(uVar1 * 4);
    *(void **)(in_ECX + 4) = pvVar2;
    *(void **)(in_ECX + 8) = pvVar2;
    *(void **)(in_ECX + 0xc) = (void *)(uVar1 * 4 + (int)pvVar2);
    local_8 = 0;
    uVar3 = FUN_005d4720(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005d4f59 @ 0x005d4f59 ====

void Catch_005d4f59(void)

{
  FUN_00412dc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d4f70 @ 0x005d4f70 ====

void FUN_005d4f70(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 2) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 2))) {
    FUN_005d4a30(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  puVar2 = *(undefined4 **)(in_ECX + 8);
  *puVar2 = *param_1;
  *(undefined4 **)(in_ECX + 8) = puVar2 + 1;
  return;
}


// ==== FUN_005d4fc0 @ 0x005d4fc0 ====

void FUN_005d4fc0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) == 0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  FUN_005c4350(*(int *)(in_ECX + 4),*(undefined4 *)(in_ECX + 8));
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_005d5000 @ 0x005d5000 ====

int FUN_005d5000(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982ce0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x58) {
    FUN_005c4510(param_3,param_1);
    param_3 = param_3 + 0x58;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005d506a @ 0x005d506a ====

void Catch_005d506a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x58) {
    FUN_005c4250(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d5090 @ 0x005d5090 ====

void FUN_005d5090(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1c) = DAT_0099d080;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  *(undefined1 *)(in_ECX + 0x21) = 0;
  *(undefined1 *)(in_ECX + 0x22) = 0xff;
  *(undefined1 *)(in_ECX + 0x23) = 0;
  *(undefined1 *)(in_ECX + 0x24) = 1;
  *(undefined1 *)(in_ECX + 0x25) = 0;
  *(undefined1 *)(in_ECX + 0x26) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  return;
}


// ==== FUN_005d50f0 @ 0x005d50f0 ====

void FUN_005d50f0(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x54) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x54));
    return;
  }
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  if (*(int *)(in_ECX + 0x40) == 0) {
    *(undefined4 *)(in_ECX + 0x40) = 0;
    *(undefined4 *)(in_ECX + 0x44) = 0;
    *(undefined4 *)(in_ECX + 0x48) = 0;
    return;
  }
  FUN_005c4350(*(int *)(in_ECX + 0x40),*(undefined4 *)(in_ECX + 0x44),in_ECX + 0x3c);
  _free(*(void **)(in_ECX + 0x40));
  return;
}


// ==== FUN_005d5150 @ 0x005d5150 ====

void FUN_005d5150(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005d5000(param_1,param_2,param_3);
  return;
}


// ==== FUN_005d5170 @ 0x005d5170 ====

void FUN_005d5170(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xc4);
  param_1[1] = *(undefined4 *)(in_ECX + 200);
  return;
}


// ==== FUN_005d5190 @ 0x005d5190 ====

void FUN_005d5190(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x70);
  param_1[1] = *(undefined4 *)(in_ECX + 0x74);
  return;
}


// ==== FUN_005d51b0 @ 0x005d51b0 ====

float10 FUN_005d51b0(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0xcc);
}


// ==== FUN_005d51c0 @ 0x005d51c0 ====

void FUN_005d51c0(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982cf0;
  local_10 = ExceptionList;
  iVar2 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    iVar2 = (*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x58;
  }
  ExceptionList = &local_10;
  cVar1 = FUN_005d4980(iVar2);
  if (cVar1 != '\0') {
    local_8 = 0;
    uVar3 = FUN_005d5150(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                         *(undefined4 *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 8) = uVar3;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005d5257 @ 0x005d5257 ====

void Catch_005d5257(void)

{
  FUN_005d4fc0();
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d5270 @ 0x005d5270 ====

void FUN_005d5270(int param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  
  if (in_ECX == param_1) {
    return;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar6 = *(int *)(param_1 + 8) - iVar1;
    iVar2 = iVar6 >> 0x1f;
    iVar6 = iVar6 / 0x58 + iVar2;
    uVar7 = iVar6 - iVar2;
    if (iVar6 != iVar2) {
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (*(int *)(in_ECX + 8) - iVar2) / 0x58;
      }
      if (uVar7 <= uVar4) {
        uVar5 = FUN_005c4300(iVar1,*(undefined4 *)(param_1 + 8),iVar2,param_1);
        FUN_005c4350(uVar5,*(undefined4 *)(in_ECX + 8));
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0x58) * 0x58;
        return;
      }
      if (iVar2 == 0) {
        uVar4 = 0;
      }
      else {
        uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x58;
      }
      if (uVar7 <= uVar4) {
        iVar6 = FUN_006dc7b0();
        iVar6 = iVar1 + iVar6 * 0x58;
        FUN_005c4300(iVar1,iVar6,iVar2,iVar6);
        uVar5 = FUN_005c4550(iVar6,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar5;
        return;
      }
      if (iVar2 != 0) {
        FUN_005c45e0(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      uVar5 = FUN_006dc7b0();
      cVar3 = FUN_005d4980(uVar5);
      if (cVar3 == '\0') {
        return;
      }
      uVar5 = FUN_005c46e0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar5;
      return;
    }
  }
  FUN_005d4fc0();
  return;
}


// ==== FUN_005d5410 @ 0x005d5410 ====

void FUN_005d5410(byte param_1)

{
  void *in_ECX;
  
  FUN_005d4050();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005d5430 @ 0x005d5430 ====

void FUN_005d5430(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  *(undefined1 *)(in_ECX + 8) = *(undefined1 *)(param_1 + 8);
  *(undefined1 *)((int)in_ECX + 0x21) = *(undefined1 *)((int)param_1 + 0x21);
  *(undefined1 *)((int)in_ECX + 0x22) = *(undefined1 *)((int)param_1 + 0x22);
  *(undefined1 *)((int)in_ECX + 0x23) = *(undefined1 *)((int)param_1 + 0x23);
  *(undefined1 *)(in_ECX + 9) = *(undefined1 *)(param_1 + 9);
  *(undefined1 *)((int)in_ECX + 0x25) = *(undefined1 *)((int)param_1 + 0x25);
  *(undefined1 *)((int)in_ECX + 0x26) = *(undefined1 *)((int)param_1 + 0x26);
  in_ECX[10] = param_1[10];
  in_ECX[0xb] = param_1[0xb];
  in_ECX[0xc] = param_1[0xc];
  in_ECX[0xd] = param_1[0xd];
  in_ECX[0xe] = param_1[0xe];
  FUN_005d5270(param_1 + 0xf);
  in_ECX[0x13] = param_1[0x13];
  FUN_005d4d50(param_1 + 0x14);
  return;
}


// ==== FUN_005d54e0 @ 0x005d54e0 ====

void FUN_005d54e0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[2] = param_1[2];
  in_ECX[3] = param_1[3];
  in_ECX[4] = param_1[4];
  in_ECX[5] = param_1[5];
  in_ECX[6] = param_1[6];
  in_ECX[7] = param_1[7];
  *(undefined1 *)(in_ECX + 8) = *(undefined1 *)(param_1 + 8);
  *(undefined1 *)((int)in_ECX + 0x21) = *(undefined1 *)((int)param_1 + 0x21);
  *(undefined1 *)((int)in_ECX + 0x22) = *(undefined1 *)((int)param_1 + 0x22);
  *(undefined1 *)((int)in_ECX + 0x23) = *(undefined1 *)((int)param_1 + 0x23);
  *(undefined1 *)(in_ECX + 9) = *(undefined1 *)(param_1 + 9);
  *(undefined1 *)((int)in_ECX + 0x25) = *(undefined1 *)((int)param_1 + 0x25);
  *(undefined1 *)((int)in_ECX + 0x26) = *(undefined1 *)((int)param_1 + 0x26);
  in_ECX[10] = param_1[10];
  in_ECX[0xb] = param_1[0xb];
  in_ECX[0xc] = param_1[0xc];
  in_ECX[0xd] = param_1[0xd];
  in_ECX[0xe] = param_1[0xe];
  FUN_005d51c0(param_1 + 0xf);
  in_ECX[0x13] = param_1[0x13];
  FUN_005d4c80(param_1 + 0x14);
  return;
}


// ==== FUN_005d5590 @ 0x005d5590 ====

void FUN_005d5590(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  *in_ECX = &PTR_FUN_009c3338;
  puVar2 = in_ECX;
  for (iVar1 = 0x18; puVar2 = puVar2 + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
  }
  *(undefined1 *)(in_ECX + 0x1a) = 1;
  in_ECX[0x1b] = 0;
  return;
}


// ==== FUN_005d55f0 @ 0x005d55f0 ====

void FUN_005d55f0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 100) = 0;
  return;
}


// ==== FUN_005d5600 @ 0x005d5600 ====

void FUN_005d5600(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int *piVar8;
  char cVar9;
  int in_ECX;
  int *piVar10;
  
  iVar1 = (int)param_1;
  if (param_1 == (undefined4 *)0x0) {
    *(undefined4 *)(in_ECX + 100) = 0;
    return;
  }
  FUN_0079bba0(&param_1,in_ECX + 4);
  if (param_1 == (undefined4 *)*(int *)(iVar1 + 0x40)) {
    *(undefined4 *)(in_ECX + 100) = 0;
    return;
  }
  iVar1 = *(int *)((int)param_1 + 0x10);
  *(int *)(in_ECX + 100) = iVar1;
  puVar2 = *(undefined4 **)(iVar1 + 8);
  param_1 = (undefined4 *)*puVar2;
  do {
    if (param_1 == puVar2) {
LAB_005d569f:
      cVar9 = FUN_005d5820(in_ECX + 0x24);
      if (cVar9 == '\0') {
        *(undefined4 *)(in_ECX + 0x6c) = 1;
      }
      piVar3 = *(int **)(*(int *)(in_ECX + 100) + 0x20);
      piVar10 = (int *)*piVar3;
      if (piVar10 != piVar3) {
        while (cVar9 = FUN_005d5970(piVar10 + 5,in_ECX + 0x24), cVar9 != '\0') {
          if (*(char *)((int)piVar10 + 0x59) == '\0') {
            piVar4 = (int *)piVar10[2];
            if (*(char *)((int)piVar4 + 0x59) == '\0') {
              cVar9 = *(char *)(*piVar4 + 0x59);
              piVar10 = piVar4;
              piVar4 = (int *)*piVar4;
              while (cVar9 == '\0') {
                cVar9 = *(char *)(*piVar4 + 0x59);
                piVar10 = piVar4;
                piVar4 = (int *)*piVar4;
              }
            }
            else {
              cVar9 = *(char *)(piVar10[1] + 0x59);
              piVar8 = (int *)piVar10[1];
              piVar4 = piVar10;
              while ((piVar10 = piVar8, cVar9 == '\0' && (piVar4 == (int *)piVar10[2]))) {
                cVar9 = *(char *)(piVar10[1] + 0x59);
                piVar8 = (int *)piVar10[1];
                piVar4 = piVar10;
              }
            }
          }
          if (piVar10 == piVar3) {
            return;
          }
        }
        *(undefined4 *)(in_ECX + 0x6c) = 2;
      }
      return;
    }
    fVar5 = *(float *)(in_ECX + 8) - (float)param_1[5];
    fVar7 = *(float *)(in_ECX + 0xc) - (float)param_1[6];
    fVar6 = *(float *)(in_ECX + 0x10) - (float)param_1[7];
    if (DAT_009c3330 < SQRT(fVar5 * fVar5 + fVar7 * fVar7 + fVar6 * fVar6)) {
      *(undefined1 *)(in_ECX + 0x68) = 0;
      goto LAB_005d569f;
    }
    FUN_0051b6b0();
  } while( true );
}


// ==== FUN_005d5730 @ 0x005d5730 ====

void FUN_005d5730(undefined4 *param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 unaff_retaddr;
  undefined1 local_50 [4];
  undefined4 auStack_4c [3];
  undefined1 local_40 [64];
  
  uVar1 = param_1[1];
  puVar3 = (undefined4 *)(param_3 + 4);
  uVar2 = *param_1;
  FUN_005d6160(uVar2,uVar1,puVar3,puVar3);
  FUN_005d5cb0(uVar2,local_50);
  iVar4 = param_3 + 0x10;
  thunk_FUN_007a0dd0(iVar4,iVar4,local_50,uVar1);
  if (*(int *)(in_ECX + 0x6c) == 0) {
    thunk_FUN_0079fb96(param_3 + 0x60,iVar4);
    *(undefined4 *)(param_3 + 0x90) = *puVar3;
    *(undefined4 *)(param_3 + 0x94) = *(undefined4 *)(param_3 + 8);
    *(undefined4 *)(param_3 + 0x98) = *(undefined4 *)(param_3 + 0xc);
    thunk_FUN_0079ee7b(param_3 + 0xa0,param_3 + 0x60,unaff_retaddr);
    return;
  }
  iVar4 = param_3 + 0x20;
  FUN_005d6220(uVar2,uVar1,iVar4,iVar4);
  puVar3 = (undefined4 *)FUN_005cd200(local_40,puVar3,param_3 + 0x10,iVar4);
  puVar5 = (undefined4 *)(param_3 + 0x60);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  thunk_FUN_0079ee7b(local_40,(undefined4 *)(param_3 + 0x60),param_2);
  puVar3 = auStack_4c;
  puVar5 = (undefined4 *)(param_3 + 0xa0);
  for (iVar4 = 0x10; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  return;
}


// ==== FUN_005d5820 @ 0x005d5820 ====

undefined4 FUN_005d5820(float *param_1)

{
  if (((((*param_1 == DAT_0099d080) && (param_1[1] == 0.0)) && (param_1[2] == 0.0)) &&
      (((param_1[3] == 0.0 && (param_1[4] == 0.0)) &&
       ((param_1[5] == DAT_0099d080 && ((param_1[6] == 0.0 && (param_1[7] == 0.0)))))))) &&
     ((param_1[8] == 0.0 &&
      (((((param_1[9] == 0.0 && (param_1[10] == DAT_0099d080)) && (param_1[0xb] == 0.0)) &&
        ((param_1[0xc] == 0.0 && (param_1[0xd] == 0.0)))) &&
       ((param_1[0xe] == 0.0 && (param_1[0xf] == DAT_0099d080)))))))) {
    return 1;
  }
  return 0;
}


// ==== FUN_005d5950 @ 0x005d5950 ====

void FUN_005d5950(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3338;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005d5970 @ 0x005d5970 ====

uint FUN_005d5970(int param_1,float *param_2)

{
  float *pfVar1;
  uint uVar2;
  uint uVar3;
  float fVar4;
  
  uVar3 = 0;
  param_1 = param_1 - (int)param_2;
  do {
    uVar2 = 0;
    pfVar1 = param_2;
    do {
      fVar4 = *(float *)(param_1 + (int)pfVar1) - *pfVar1;
      if (fVar4 <= 0.0) {
        fVar4 = 0.0 - fVar4;
      }
      if (DAT_009c3330 < fVar4) {
        return (uint)pfVar1 & 0xffffff00;
      }
      uVar2 = uVar2 + 1;
      pfVar1 = pfVar1 + 1;
    } while (uVar2 < 4);
    uVar3 = uVar3 + 1;
    param_2 = param_2 + 4;
    if (3 < uVar3) {
      return CONCAT31((int3)((uint)pfVar1 >> 8),1);
    }
  } while( true );
}


// ==== FUN_005d59e0 @ 0x005d59e0 ====

void FUN_005d59e0(undefined4 *param_1,float *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar1 = *(char *)((int)puVar4 + 0x25);
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
    cVar1 = *(char *)((int)puVar3 + 0x25);
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


// ==== FUN_005d5a60 @ 0x005d5a60 ====

void FUN_005d5a60(undefined4 *param_1,float *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar1 = *(char *)((int)puVar4 + 0x29);
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
    cVar1 = *(char *)((int)puVar3 + 0x29);
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


// ==== FUN_005d5ae0 @ 0x005d5ae0 ====

void FUN_005d5ae0(undefined4 *param_1,float *param_2)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(in_ECX + 4))[1];
  cVar1 = *(char *)((int)puVar4 + 0x59);
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
    cVar1 = *(char *)((int)puVar3 + 0x59);
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


// ==== FUN_005d5b60 @ 0x005d5b60 ====

void FUN_005d5b60(float param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  float fVar8;
  float fVar9;
  int local_10;
  float local_c;
  float local_8;
  
  iVar6 = *(int *)(in_ECX + 100);
  if (iVar6 == 0) {
    *param_2 = *(float *)(in_ECX + 8);
    param_2[1] = *(float *)(in_ECX + 0xc);
    param_2[2] = *(float *)(in_ECX + 0x10);
    return;
  }
  local_8 = param_1;
  local_c = param_1;
  FUN_005d59e0(&local_10,&local_c);
  iVar7 = local_10;
  iVar6 = *(int *)(iVar6 + 8);
  if (local_10 == iVar6) {
    *param_2 = *(float *)(in_ECX + 8);
    param_2[1] = *(float *)(in_ECX + 0xc);
    param_2[2] = *(float *)(in_ECX + 0x10);
    return;
  }
  pfVar1 = (float *)(local_10 + 0x14);
  FUN_0051b6b0();
  if (local_10 == iVar6) {
    *param_2 = *pfVar1;
    param_2[1] = *(float *)(iVar7 + 0x18);
    param_2[2] = *(float *)(iVar7 + 0x1c);
    return;
  }
  fVar2 = *(float *)(local_10 + 0x18);
  fVar3 = *(float *)(local_10 + 0x1c);
  fVar4 = *(float *)(iVar7 + 0x18);
  fVar5 = *(float *)(iVar7 + 0x1c);
  fVar9 = (param_1 - *(float *)(iVar7 + 0x20)) /
          (*(float *)(local_10 + 0x20) - *(float *)(iVar7 + 0x20));
  fVar8 = DAT_0099d080 - fVar9;
  *param_2 = *pfVar1 * fVar8 + *(float *)(local_10 + 0x14) * fVar9;
  param_2[1] = fVar4 * fVar8 + fVar2 * fVar9;
  param_2[2] = fVar5 * fVar8 + fVar3 * fVar9;
  return;
}


// ==== FUN_005d5cb0 @ 0x005d5cb0 ====

void FUN_005d5cb0(float param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int local_c;
  float local_8;
  float local_4;
  
  iVar2 = *(int *)(in_ECX + 100);
  if (iVar2 == 0) {
    *param_2 = *(undefined4 *)(in_ECX + 0x14);
    param_2[1] = *(undefined4 *)(in_ECX + 0x18);
    param_2[2] = *(undefined4 *)(in_ECX + 0x1c);
    param_2[3] = *(undefined4 *)(in_ECX + 0x20);
    return;
  }
  local_4 = param_1;
  local_8 = param_1;
  FUN_005d5a60(&local_c,&local_8);
  iVar3 = local_c;
  iVar2 = *(int *)(iVar2 + 0x14);
  if (local_c == iVar2) {
    *param_2 = *(undefined4 *)(in_ECX + 0x14);
    param_2[1] = *(undefined4 *)(in_ECX + 0x18);
    param_2[2] = *(undefined4 *)(in_ECX + 0x1c);
    param_2[3] = *(undefined4 *)(in_ECX + 0x20);
    return;
  }
  puVar1 = (undefined4 *)(local_c + 0x14);
  FUN_00798b00();
  if (local_c == iVar2) {
    *param_2 = *puVar1;
    param_2[1] = *(undefined4 *)(iVar3 + 0x18);
    param_2[2] = *(undefined4 *)(iVar3 + 0x1c);
    param_2[3] = *(undefined4 *)(iVar3 + 0x20);
    return;
  }
  thunk_FUN_007a0dd0(param_2,puVar1,local_c + 0x14,
                     (param_1 - *(float *)(iVar3 + 0x24)) /
                     (*(float *)(local_c + 0x24) - *(float *)(iVar3 + 0x24)));
  return;
}


// ==== FUN_005d5db0 @ 0x005d5db0 ====

void FUN_005d5db0(float param_1,float *param_2)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  float *pfVar3;
  float fVar4;
  float fVar5;
  int local_cc [17];
  float local_88;
  float local_84;
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
  float local_4;
  
  iVar2 = *(int *)(in_ECX + 100);
  if (iVar2 != 0) {
    local_84 = param_1;
    local_88 = param_1;
    FUN_005d5ae0(local_cc,&local_88);
    iVar1 = local_cc[0];
    iVar2 = *(int *)(iVar2 + 0x20);
    if (local_cc[0] != iVar2) {
      pfVar3 = (float *)(local_cc[0] + 0x14);
      FUN_004c92b0();
      if (local_cc[0] != iVar2) {
        fVar5 = (param_1 - *(float *)(iVar1 + 0x54)) /
                (*(float *)(local_cc[0] + 0x54) - *(float *)(iVar1 + 0x54));
        fVar4 = DAT_0099d080 - fVar5;
        local_28 = *(float *)(iVar1 + 0x2c) * fVar4 + *(float *)(local_cc[0] + 0x2c) * fVar5;
        local_24 = *(float *)(iVar1 + 0x30) * fVar4 + *(float *)(local_cc[0] + 0x30) * fVar5;
        local_20 = *(float *)(iVar1 + 0x34) * fVar4 + *(float *)(local_cc[0] + 0x34) * fVar5;
        local_1c = *(float *)(iVar1 + 0x38) * fVar4 + *(float *)(local_cc[0] + 0x38) * fVar5;
        local_18 = *(float *)(iVar1 + 0x3c) * fVar4 + *(float *)(local_cc[0] + 0x3c) * fVar5;
        local_14 = *(float *)(iVar1 + 0x40) * fVar4 + *(float *)(local_cc[0] + 0x40) * fVar5;
        local_10 = *(float *)(iVar1 + 0x44) * fVar4 + *(float *)(local_cc[0] + 0x44) * fVar5;
        local_c = *(float *)(iVar1 + 0x48) * fVar4 + *(float *)(local_cc[0] + 0x48) * fVar5;
        local_40 = *pfVar3 * fVar4 + *(float *)(local_cc[0] + 0x14) * fVar5;
        local_3c = *(float *)(iVar1 + 0x18) * fVar4 + *(float *)(local_cc[0] + 0x18) * fVar5;
        local_38 = *(float *)(iVar1 + 0x1c) * fVar4 + *(float *)(local_cc[0] + 0x1c) * fVar5;
        local_34 = *(float *)(iVar1 + 0x20) * fVar4 + *(float *)(local_cc[0] + 0x20) * fVar5;
        local_30 = *(float *)(iVar1 + 0x24) * fVar4 + *(float *)(local_cc[0] + 0x24) * fVar5;
        local_2c = *(float *)(iVar1 + 0x28) * fVar4 + *(float *)(local_cc[0] + 0x28) * fVar5;
        local_8 = *(float *)(iVar1 + 0x4c) * fVar4 + *(float *)(local_cc[0] + 0x4c) * fVar5;
        local_4 = *(float *)(iVar1 + 0x50) * fVar4 + *(float *)(local_cc[0] + 0x50) * fVar5;
        pfVar3 = &local_40;
      }
      goto LAB_005d613c;
    }
  }
  pfVar3 = (float *)(in_ECX + 0x24);
LAB_005d613c:
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_2 = *pfVar3;
    pfVar3 = pfVar3 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


// ==== FUN_005d6160 @ 0x005d6160 ====

void FUN_005d6160(undefined4 param_1,float param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  int in_ECX;
  float fVar3;
  float local_c;
  float local_8;
  float local_4;
  
  if (*(char *)(in_ECX + 0x68) == '\0') {
    FUN_005d5b60(param_1,&local_c);
    fVar1 = param_3[1];
    fVar2 = param_3[2];
    fVar3 = DAT_0099d080 - param_2;
    *param_4 = *param_3 * fVar3 + local_c * param_2;
    param_4[1] = fVar1 * fVar3 + local_8 * param_2;
    param_4[2] = fVar2 * fVar3 + local_4 * param_2;
    return;
  }
  *param_4 = *(float *)(in_ECX + 8);
  param_4[1] = *(float *)(in_ECX + 0xc);
  param_4[2] = *(float *)(in_ECX + 0x10);
  return;
}


// ==== FUN_005d6220 @ 0x005d6220 ====

void FUN_005d6220(undefined4 param_1,float param_2,float *param_3,float *param_4)

{
  int in_ECX;
  int iVar1;
  float *pfVar2;
  float fVar3;
  float local_c0;
  float local_bc;
  float local_b8;
  float local_b4;
  float local_b0;
  float local_ac;
  float local_a8;
  float local_a4;
  float local_a0;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
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
  float local_4;
  
  if (*(int *)(in_ECX + 0x6c) == 1) {
    pfVar2 = (float *)(in_ECX + 0x24);
  }
  else {
    FUN_005d5db0(param_1,&local_c0);
    fVar3 = DAT_0099d080 - param_2;
    local_28 = param_3[6] * fVar3 + local_a8 * param_2;
    local_24 = param_3[7] * fVar3 + local_a4 * param_2;
    local_20 = param_3[8] * fVar3 + local_a0 * param_2;
    local_1c = param_3[9] * fVar3 + local_9c * param_2;
    local_18 = param_3[10] * fVar3 + local_98 * param_2;
    local_14 = param_3[0xb] * fVar3 + local_94 * param_2;
    local_10 = param_3[0xc] * fVar3 + local_90 * param_2;
    local_c = param_3[0xd] * fVar3 + local_8c * param_2;
    local_40 = *param_3 * fVar3 + local_c0 * param_2;
    local_3c = param_3[1] * fVar3 + local_bc * param_2;
    local_38 = param_3[2] * fVar3 + local_b8 * param_2;
    local_34 = param_3[3] * fVar3 + local_b4 * param_2;
    local_30 = param_3[4] * fVar3 + local_b0 * param_2;
    local_2c = param_3[5] * fVar3 + local_ac * param_2;
    local_8 = param_3[0xe] * fVar3 + local_88 * param_2;
    local_4 = param_3[0xf] * fVar3 + local_84 * param_2;
    pfVar2 = &local_40;
  }
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_4 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    param_4 = param_4 + 1;
  }
  return;
}


// ==== FUN_005d6580 @ 0x005d6580 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d6580(undefined4 param_1,float param_2,float param_3,undefined4 param_4,
                 undefined4 *param_5,float *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  float fVar3;
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
  void *local_18;
  uint local_4;
  
  local_3c = *param_6;
  local_38 = param_6[1];
  local_34 = param_6[2];
  local_30 = param_6[3];
  if (param_2 - param_3 != DAT_0099cdc8) {
    puVar1 = (undefined4 *)(in_ECX + 0x14);
    FUN_005ced90(&local_54,puVar1,param_2,param_3);
    if (*(int *)(in_ECX + 0x24) == 1) {
      FUN_005cee80(&local_2c);
      local_40 = SQRT((local_24 - local_2c) * (local_24 - local_2c) +
                      (local_20 - local_28) * (local_20 - local_28));
      if (_DAT_009c3340 <= local_40) {
        local_40 = *(float *)(in_ECX + 0x28) / local_40;
        local_44 = local_54 * local_40;
        local_40 = local_50 * local_40;
      }
      else {
        local_44 = 0.0;
        local_40 = 0.0;
      }
      local_54 = local_44;
      local_50 = local_40;
      if (0xf < local_4) {
        _free(local_18);
        return;
      }
    }
    else if (*(int *)(in_ECX + 0x24) == 2) {
      FUN_005ced90(&local_4c,puVar1,0,param_2);
      FUN_005ced90(&local_44,puVar1,0,param_3);
      fVar3 = SQRT(local_4c * local_4c + local_48 * local_48);
      if (*(float *)(in_ECX + 0x28) < fVar3) {
        fVar3 = *(float *)(in_ECX + 0x28) / fVar3;
        local_4c = local_4c * fVar3;
        local_48 = local_48 * fVar3;
      }
      fVar3 = SQRT(local_44 * local_44 + local_40 * local_40);
      if (*(float *)(in_ECX + 0x28) < fVar3) {
        fVar3 = *(float *)(in_ECX + 0x28) / fVar3;
        local_44 = local_44 * fVar3;
        local_40 = local_40 * fVar3;
      }
      local_54 = local_44 - local_4c;
      local_50 = local_40 - local_48;
      local_44 = local_54;
      local_40 = local_50;
    }
    iVar2 = (**(code **)(*DAT_00b5a6b4 + 0x30))(&local_54,param_6);
    *param_5 = *puVar1;
    param_5[1] = *(undefined4 *)(in_ECX + 0x18);
    if (DAT_009c3038 <=
        SQRT((param_6[2] - local_3c) * (param_6[2] - local_3c) +
             (param_6[3] - local_38) * (param_6[3] - local_38))) {
      if (iVar2 != 2) {
        return;
      }
    }
    else {
      if (iVar2 != 2) {
        return;
      }
      if (*(uint *)(in_ECX + 0x20) < 5) {
        *(uint *)(in_ECX + 0x20) = *(uint *)(in_ECX + 0x20) + 1;
        return;
      }
    }
    if (*(char *)(in_ECX + 0x1d) != '\0') {
      FUN_005c5c60(2);
    }
  }
  return;
}


// ==== FUN_005d6810 @ 0x005d6810 ====

void FUN_005d6810(undefined4 *param_1,undefined4 *param_2,undefined1 param_3,undefined1 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = *param_1;
  *(undefined4 *)(in_ECX + 8) = param_1[1];
  *(undefined4 *)(in_ECX + 0xc) = param_1[2];
  *(undefined4 *)(in_ECX + 0x10) = param_1[3];
  *(undefined4 *)(in_ECX + 0x14) = *param_2;
  *(undefined4 *)(in_ECX + 0x18) = param_2[1];
  *(undefined1 *)(in_ECX + 0x1c) = param_3;
  *(undefined1 *)(in_ECX + 0x1d) = param_4;
  *(undefined4 *)(in_ECX + 0x24) = param_5;
  *(undefined4 *)(in_ECX + 0x28) = param_6;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  if (*(void **)(in_ECX + 0x30) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x30) = 0;
    *(undefined4 *)(in_ECX + 0x34) = 0;
    *(undefined4 *)(in_ECX + 0x38) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x30));
  return;
}


// ==== FUN_005d6890 @ 0x005d6890 ====

void FUN_005d6890(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_18 = *param_1;
  local_14 = param_1[1];
  local_10 = param_1[2];
  local_c = param_1[3];
  local_4 = param_2[1];
  local_8 = *param_2;
  (**(code **)(*DAT_00b5a6b4 + 0x24))(&local_18,param_3);
  return;
}


// ==== FUN_005d68e0 @ 0x005d68e0 ====

float10 FUN_005d68e0(float *param_1,int param_2)

{
  float *pfVar1;
  float fVar2;
  float10 fVar3;
  float10 fVar4;
  float *pfVar5;
  float10 fVar6;
  float local_8;
  float local_4;
  
  local_8 = *param_1;
  local_4 = param_1[1];
  pfVar5 = *(float **)(param_2 + 4);
  if (pfVar5 == *(float **)(param_2 + 8)) {
    return (float10)0.0;
  }
  fVar6 = (float10)0.0;
  do {
    fVar2 = *pfVar5;
    fVar3 = (float10)local_8;
    pfVar1 = pfVar5 + 1;
    fVar4 = (float10)local_4;
    local_8 = *pfVar5;
    local_4 = pfVar5[1];
    pfVar5 = pfVar5 + 2;
    fVar6 = SQRT(((float10)fVar2 - fVar3) * ((float10)fVar2 - fVar3) +
                 ((float10)*pfVar1 - fVar4) * ((float10)*pfVar1 - fVar4)) + fVar6;
  } while (pfVar5 != *(float **)(param_2 + 8));
  return fVar6;
}


// ==== FUN_005d6960 @ 0x005d6960 ====

/* WARNING: Removing unreachable block (ram,0x005d698b) */

void FUN_005d6960(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3350;
  if ((void *)in_ECX[6] == (void *)0x0) {
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 0;
    in_ECX[8] = 0;
    *in_ECX = &PTR_FUN_009c26fc;
    return;
  }
  _free((void *)in_ECX[6]);
  return;
}


// ==== FUN_005d69b0 @ 0x005d69b0 ====

void FUN_005d69b0(undefined4 param_1,undefined4 param_2,float param_3,undefined4 param_4,
                 undefined4 param_5,float *param_6,undefined4 param_7)

{
  float *pfVar1;
  undefined4 *puVar2;
  float *pfVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined4 *puVar7;
  float10 fVar8;
  undefined4 uStack_30;
  float fStack_2c;
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
  
  fVar8 = (float10)FUN_005ced20(param_2,param_3);
  pfVar3 = param_6;
  param_3 = (float)fVar8;
  local_28 = *param_6;
  local_24 = param_6[1];
  local_20 = param_6[2];
  local_1c = param_6[3];
  if (DAT_009c3348 <= param_3) {
    if (*(char *)(in_ECX + 0xd) == '\0') {
      if (((float)(int)*(float *)(in_ECX + 4) != *param_6) ||
         ((float)(int)*(float *)(in_ECX + 8) != param_6[1])) {
        FUN_00412dc0();
        local_18 = *pfVar3;
        local_14 = pfVar3[1];
        local_10 = pfVar3[2];
        local_c = pfVar3[3];
        local_8 = *(float *)(in_ECX + 4);
        local_4 = *(float *)(in_ECX + 8);
        uVar4 = (**(code **)(*DAT_00b5a6b4 + 0x24))(&local_18,in_ECX + 0x14);
        *(undefined1 *)(in_ECX + 0xd) = uVar4;
      }
      if (*(char *)(in_ECX + 0xd) == '\0') {
        local_18 = *pfVar3;
        local_14 = pfVar3[1];
        local_10 = pfVar3[2];
        local_4 = *(float *)(in_ECX + 8);
        local_c = pfVar3[3];
        local_8 = *(float *)(in_ECX + 4);
        iVar5 = (**(code **)(*DAT_00b5a6b4 + 0x2c))(&local_18,&param_3);
        *pfVar3 = local_20;
        pfVar3[1] = local_1c;
        pfVar3[2] = local_18;
        pfVar3[3] = local_14;
        if (iVar5 != 0) {
          thunk_FUN_0079de77(param_5,(int)register0x00000010 + -0x38);
        }
        if (((SQRT((pfVar3[2] - local_28) * (pfVar3[2] - local_28) +
                   (pfVar3[3] - local_24) * (pfVar3[3] - local_24)) < DAT_009c3038) && (iVar5 == 2))
           && (*(uint *)(in_ECX + 0x10) < 5)) {
          *(uint *)(in_ECX + 0x10) = *(uint *)(in_ECX + 0x10) + 1;
          return;
        }
        if (*(char *)(in_ECX + 0xc) == '\0') {
          return;
        }
        FUN_005c5c60(iVar5);
        return;
      }
    }
    while ((pfVar1 = *(float **)(in_ECX + 0x18), pfVar1 != (float *)0x0 &&
           (*(int *)(in_ECX + 0x1c) - (int)pfVar1 >> 3 != 0))) {
      local_8 = *pfVar1;
      local_4 = pfVar1[1];
      local_18 = *pfVar3;
      local_14 = pfVar3[1];
      local_10 = pfVar3[2];
      local_c = pfVar3[3];
      iVar5 = (**(code **)(*DAT_00b5a6b4 + 0x2c))(&local_18,&param_3);
      *pfVar3 = local_18;
      pfVar3[1] = local_14;
      pfVar3[2] = local_10;
      pfVar3[3] = local_c;
      if (iVar5 != 0) {
        uStack_30 = local_8 - local_10;
        fStack_2c = local_4 - local_c;
        thunk_FUN_0079de77(param_7,&uStack_30);
      }
      if (iVar5 == 1) {
        if (SQRT((pfVar3[2] - local_20) * (pfVar3[2] - local_20) +
                 (pfVar3[3] - local_1c) * (pfVar3[3] - local_1c)) < DAT_0099d0ec) {
          *(undefined1 *)(in_ECX + 0xd) = 0;
          return;
        }
        return;
      }
      puVar7 = *(undefined4 **)(in_ECX + 0x18);
      puVar2 = *(undefined4 **)(in_ECX + 0x1c);
      puVar6 = puVar7 + 2;
      if (puVar6 != puVar2) {
        do {
          *puVar7 = *puVar6;
          puVar7[1] = puVar6[1];
          puVar6 = puVar6 + 2;
          puVar7 = puVar7 + 2;
        } while (puVar6 != puVar2);
      }
      *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + -8;
      if ((iVar5 == 2) && (*(char *)(in_ECX + 0xc) != '\0')) {
        FUN_005c5c60(2);
        return;
      }
      if (param_3 < DAT_009c3348) {
        return;
      }
    }
    if (*(char *)(in_ECX + 0xc) == '\x01') {
      FUN_005c5c60(3);
    }
  }
  return;
}


// ==== FUN_005d6ce0 @ 0x005d6ce0 ====

void FUN_005d6ce0(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined1 *)(in_ECX + 0xc) = 0;
  *(undefined1 *)(in_ECX + 0xd) = 0;
  if (*(void **)(in_ECX + 0x18) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    *(undefined4 *)(in_ECX + 0x20) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_005d6d30 @ 0x005d6d30 ====

void FUN_005d6d30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3350;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_005d6d50 @ 0x005d6d50 ====

void FUN_005d6d50(undefined4 *param_1,undefined4 *param_2,undefined1 param_3)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int in_ECX;
  int iVar4;
  float10 fVar5;
  undefined4 unaff_retaddr;
  undefined4 uStack_40;
  int iStack_3c;
  float local_38;
  float local_34;
  undefined1 auStack_30 [4];
  void *pvStack_2c;
  int local_28 [5];
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  local_38 = *(float *)(in_ECX + 4);
  local_34 = *(float *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 4) = *param_2;
  *(undefined4 *)(in_ECX + 8) = param_2[1];
  *(undefined1 *)(in_ECX + 0xc) = param_3;
  local_28[4] = *param_1;
  local_14 = param_1[1];
  local_10 = param_1[2];
  local_4 = *(int *)(in_ECX + 8);
  local_c = param_1[3];
  local_8 = *(undefined4 *)(in_ECX + 4);
  local_28[1] = 0;
  local_28[2] = 0;
  local_28[3] = 0;
  cVar3 = (**(code **)(*DAT_00b5a6b4 + 0x24))(local_28 + 4,local_28);
  if (*(char *)(in_ECX + 0xd) == '\0') {
LAB_005d6f39:
    FUN_005d7000(auStack_30);
    *(char *)(in_ECX + 0xd) = cVar3;
    if (pvStack_2c == (void *)0x0) {
      return;
    }
    _free(pvStack_2c);
    return;
  }
  if ((*(int *)(in_ECX + 0x18) == 0) ||
     (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18) >> 3 == 0)) goto LAB_005d6f39;
  if (cVar3 == '\x01') {
    if ((pvStack_2c != (void *)0x0) && (local_28[0] - (int)pvStack_2c >> 3 == 1)) {
      FUN_005d7000(auStack_30);
      *(undefined1 *)(in_ECX + 0xd) = 0;
      goto LAB_005d6e28;
    }
  }
  else if (cVar3 == '\0') {
    *(int *)(in_ECX + 4) = uStack_40;
    *(int *)(in_ECX + 8) = iStack_3c;
    FUN_00412dc0();
    return;
  }
  if ((*(char *)(in_ECX + 0xd) == '\x01') &&
     ((*(int *)(in_ECX + 0x18) != 0 && (*(int *)(in_ECX + 0x1c) - *(int *)(in_ECX + 0x18) >> 3 == 1)
      ))) {
LAB_005d6e28:
    FUN_00412dc0();
    return;
  }
  iVar4 = local_4 + 8;
  fVar5 = (float10)FUN_005d68e0(iVar4,auStack_30);
  fVar1 = **(float **)(in_ECX + 0x18);
  fVar2 = (*(float **)(in_ECX + 0x18))[1];
  FUN_00412dc0();
  iStack_3c = (int)fVar2;
  uStack_40 = (int)fVar1;
  local_38 = fVar1;
  local_34 = fVar2;
  cVar3 = FUN_005d6890(&uStack_40,unaff_retaddr,in_ECX + 0x14);
  if (cVar3 != '\0') {
    FUN_0058abb0(&local_4,*(undefined4 *)(in_ECX + 0x18),auStack_30 + -0x18);
    fVar1 = (float)fVar5 * DAT_009b2dc0;
    fVar5 = (float10)FUN_005d68e0(iVar4,in_ECX + 0x14);
    if (fVar5 <= (float10)fVar1) goto LAB_005d6f26;
  }
  FUN_005d7000(auStack_30);
  *(undefined1 *)(in_ECX + 0xd) = 1;
LAB_005d6f26:
  FUN_00412dc0();
  return;
}


// ==== FUN_005d6f70 @ 0x005d6f70 ====

void FUN_005d6f70(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  for (; param_1 != param_2; param_1 = param_1 + 2) {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3 = param_3 + 2;
  }
  return;
}


// ==== FUN_005d6fa0 @ 0x005d6fa0 ====

/* WARNING: Removing unreachable block (ram,0x005d6fcb) */

void FUN_005d6fa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3350;
  if ((void *)in_ECX[6] != (void *)0x0) {
    _free((void *)in_ECX[6]);
    return;
  }
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  in_ECX[8] = 0;
  *in_ECX = &PTR_FUN_009c26fc;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005d7000 @ 0x005d7000 ====

void FUN_005d7000(int param_1)

{
  void *_Memory;
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  if (in_ECX == param_1) {
    return;
  }
  iVar5 = *(int *)(param_1 + 4);
  if (iVar5 != 0) {
    uVar4 = *(int *)(param_1 + 8) - iVar5 >> 3;
    if (uVar4 != 0) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
      }
      if (uVar4 <= uVar3) {
        FUN_005d6f70(iVar5,*(int *)(param_1 + 8),_Memory);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3) * 8;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(int *)(in_ECX + 0xc) - (int)_Memory >> 3;
      }
      if (uVar4 <= uVar3) {
        if (_Memory == (void *)0x0) {
          iVar5 = 0;
        }
        else {
          iVar5 = *(int *)(in_ECX + 8) - (int)_Memory >> 3;
        }
        iVar5 = *(int *)(param_1 + 4) + iVar5 * 8;
        FUN_005d6f70(*(int *)(param_1 + 4),iVar5,_Memory);
        uVar2 = FUN_00751a10(iVar5,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar2;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      if (*(int *)(param_1 + 4) == 0) {
        iVar5 = 0;
      }
      else {
        iVar5 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 3;
      }
      cVar1 = FUN_005947a0(iVar5);
      if (cVar1 == '\0') {
        return;
      }
      uVar2 = FUN_0058a8d0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar2;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_005d7150 @ 0x005d7150 ====

void FUN_005d7150(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3380;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005d71a0 @ 0x005d71a0 ====

void FUN_005d71a0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int in_ECX;
  int iVar7;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (((*(int *)(in_ECX + 0xc) != 0) && (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc) >> 5 != 0)
      ) && (cVar3 = (**(code **)(**(int **)(in_ECX + 0x18) + 0x2c))(), uVar2 = DAT_009b02a8,
           cVar3 != '\0')) {
    iVar1 = *(int *)(in_ECX + 0x10);
    for (iVar7 = *(int *)(in_ECX + 0xc); iVar7 != iVar1; iVar7 = iVar7 + 0x20) {
      puVar4 = (undefined4 *)(**(code **)(*param_1 + 0xc0))();
      puVar4[9] = 0;
      uVar6 = *(undefined4 *)(iVar7 + 0xc);
      puVar4[8] = 3;
      uVar5 = FUN_004b3ff0(0);
      puVar4[3] = uVar5;
      puVar4[7] = *(undefined4 *)(iVar7 + 0x10);
      *puVar4 = *(undefined4 *)(iVar7 + 0x14);
      puVar4[1] = *(undefined4 *)(iVar7 + 0x18);
      puVar4[2] = *(undefined4 *)(iVar7 + 0x1c);
      uStack_10 = DAT_0099d080;
      puVar4[4] = uVar2;
      puVar4[5] = uVar6;
      uStack_c = uStack_10;
      uStack_8 = uStack_10;
      uStack_4 = uStack_10;
      uVar6 = FUN_0040ead0(&uStack_10);
      puVar4[6] = uVar6;
      (**(code **)(*param_1 + 0x88))(puVar4);
    }
  }
  return;
}


// ==== FUN_005d72c0 @ 0x005d72c0 ====

/* WARNING: Removing unreachable block (ram,0x005d7301) */

void FUN_005d72c0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c339c;
  if (in_ECX[6] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[6]);
    in_ECX[6] = 0;
  }
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009c3380;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_005d7320 @ 0x005d7320 ====

undefined4 FUN_005d7320(int param_1)

{
  uint *puVar1;
  undefined3 uVar4;
  uint *puVar2;
  uint *puVar3;
  int in_ECX;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint *puVar8;
  
  puVar7 = *(uint **)(in_ECX + 0xc);
  uVar4 = (undefined3)((uint)puVar7 >> 8);
  if ((puVar7 == (uint *)0x0) || (*(int *)(in_ECX + 0x10) - (int)puVar7 >> 5 == 0)) {
    return CONCAT31(uVar4,1);
  }
  if (puVar7 == *(uint **)(in_ECX + 0x10)) {
    return CONCAT31(uVar4,1);
  }
  do {
    puVar7[1] = puVar7[1] + param_1;
    puVar3 = (uint *)puVar7[1];
    if ((uint *)*puVar7 < puVar3) {
      puVar1 = *(uint **)(in_ECX + 0x10);
      puVar3 = puVar7 + 8;
      if (puVar3 != puVar1) {
        puVar2 = puVar3;
        puVar6 = puVar7;
        do {
          puVar3 = puVar2 + 8;
          puVar8 = puVar6;
          for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar8 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar8 = puVar8 + 1;
          }
          puVar2 = puVar3;
          puVar6 = puVar6 + 8;
        } while (puVar3 != puVar1);
      }
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + -0x20;
    }
    else {
      puVar7 = puVar7 + 8;
    }
  } while (puVar7 != *(uint **)(in_ECX + 0x10));
  return CONCAT31((int3)((uint)puVar3 >> 8),1);
}


// ==== FUN_005d73b0 @ 0x005d73b0 ====

void FUN_005d73b0(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009c339c;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[1] = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_effect_hit_eff_slash_tpack_009c335c,0x1a);
  uVar1 = FUN_005aa220(local_1c);
  in_ECX[6] = uVar1;
  if (local_4 < 0x10) {
    return;
  }
  _free(local_18);
  return;
}


// ==== FUN_005d7420 @ 0x005d7420 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d7420(float *param_1,undefined4 param_2,float *param_3)

{
  int in_ECX;
  float10 fVar1;
  float *local_70;
  float local_68;
  float local_60;
  float local_5c;
  undefined4 local_58;
  undefined4 uStack_54;
  float local_50;
  float *local_4c;
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
  undefined1 uStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float fStack_c;
  
  local_70 = &local_60;
  FUN_005d1750();
  local_70 = &local_50;
  FUN_005d1710();
  local_44 = local_60;
  local_70 = &local_60;
  local_40 = 0.0;
  local_3c = local_5c;
  fVar1 = (float10)FUN_0040d5f0();
  local_70 = (float *)(float)((float10)_DAT_00af6038 * (float10)DAT_0099d0b4 + fVar1);
  FUN_0040d600(&local_58);
  local_68 = *(float *)(*(int *)(*(int *)(in_ECX + 4) + 0xd8) + 0xc);
  if (DAT_009b2dc0 <= local_68) {
    if (DAT_009b6df8 <= local_68) {
      local_68 = DAT_009b6df8;
    }
  }
  else {
    local_68 = DAT_009b2dc0;
  }
  local_50 = local_50 + local_44;
  local_34 = local_40 + (float)local_4c;
  local_48 = local_48 + local_3c;
  local_4c = (float *)(local_34 + local_68);
  local_70 = param_3;
  local_38 = local_50;
  local_30 = local_48;
  FUN_005d1680(&local_2c);
  local_38 = *param_1 - local_2c;
  local_34 = param_1[1] - local_28;
  local_70 = &local_38;
  local_30 = param_1[2] - local_24;
  thunk_FUN_0079e1ba(&local_44);
  fStack_1c = (float)local_70 * DAT_009b6df8;
  local_28 = 3.50325e-43;
  local_24 = 0.0;
  if (DAT_009b0ec4 <= fStack_1c) {
    fStack_1c = DAT_009b0ec4;
  }
  local_70 = local_4c;
  fVar1 = (float10)FUN_0040d5f0(&local_70);
  fStack_18 = (float)fVar1;
  uStack_14 = local_58;
  uStack_20 = 0;
  uStack_10 = uStack_54;
  fStack_c = local_50;
  FUN_005d79d0(&local_28);
  return;
}


// ==== FUN_005d7610 @ 0x005d7610 ====

void FUN_005d7610(void)

{
  undefined4 uStack0000000c;
  
  uStack0000000c = 0;
  FUN_005d7420();
  return;
}


// ==== FUN_005d7620 @ 0x005d7620 ====

void FUN_005d7620(void)

{
  undefined4 uStack0000000c;
  
  uStack0000000c = 1;
  FUN_005d7420();
  return;
}


// ==== FUN_005d7630 @ 0x005d7630 ====

int FUN_005d7630(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982d00;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x20) {
    FUN_005d2840(param_3,param_1);
    param_3 = param_3 + 0x20;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005d7696 @ 0x005d7696 ====

void Catch_005d7696(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d76a0 @ 0x005d76a0 ====

void FUN_005d76a0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982d10;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005d2840(param_1,param_3);
    param_1 = param_1 + 0x20;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005d7706 @ 0x005d7706 ====

void Catch_005d7706(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d7710 @ 0x005d7710 ====

void FUN_005d7710(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005d7630(param_1,param_2,param_3);
  return;
}


// ==== FUN_005d7730 @ 0x005d7730 ====

int FUN_005d7730(int param_1,int param_2,undefined4 param_3)

{
  FUN_005d76a0(param_1,param_2,param_3);
  return param_2 * 0x20 + param_1;
}


// ==== FUN_005d7760 @ 0x005d7760 ====

void FUN_005d7760(byte param_1)

{
  void *in_ECX;
  
  FUN_005d72c0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005d7780 @ 0x005d7780 ====

void FUN_005d7780(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined8 uVar6;
  undefined4 local_50;
  int local_28;
  void *local_24;
  uint local_20;
  undefined4 local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982d20;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x5c);
  puVar5 = &local_50;
  for (iVar4 = 8; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_3;
    param_3 = param_3 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar4 = *(int *)(in_ECX + 4);
  if (iVar4 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(in_ECX + 0xc) - iVar4 >> 5;
  }
  uVar6 = CONCAT44(iVar4,iVar1);
  if (param_2 != 0) {
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 5;
    }
    ExceptionList = &local_10;
    if (0x7ffffffU - iVar4 < param_2) {
      ExceptionList = &local_10;
      uVar6 = FUN_0085b3b0();
    }
    iVar4 = (int)((ulonglong)uVar6 >> 0x20);
    local_20 = (uint)uVar6;
    if (iVar4 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(in_ECX + 8) - iVar4 >> 5;
    }
    if (local_20 < iVar1 + param_2) {
      if (0x7ffffff - (local_20 >> 1) < local_20) {
        local_20 = 0;
      }
      else {
        local_20 = local_20 + (local_20 >> 1);
      }
      if (iVar4 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = *(int *)(in_ECX + 8) - iVar4 >> 5;
      }
      if (local_20 < iVar1 + param_2) {
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(in_ECX + 8) - iVar4 >> 5;
        }
        local_20 = iVar4 + param_2;
      }
      local_20 = local_20 << 5;
      pvVar2 = operator_new(local_20);
      local_8 = 0;
      local_24 = pvVar2;
      local_1c = FUN_005d7710(*(undefined4 *)(in_ECX + 4),param_1,pvVar2);
      local_1c = FUN_005d7730(local_1c,param_2,&local_50);
      FUN_005d7710(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar4 = 0;
      }
      else {
        iVar4 = *(int *)(in_ECX + 8) - (int)_Memory >> 5;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_20 + (int)pvVar2;
        *(void **)(in_ECX + 8) = (void *)((param_2 + iVar4) * 0x20 + (int)pvVar2);
        *(void **)(in_ECX + 4) = pvVar2;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_28 = *(int *)(in_ECX + 8);
    if ((uint)(local_28 - param_1 >> 5) < param_2) {
      local_18 = param_2 * 0x20;
      FUN_005d7630(param_1,local_28,local_18 + param_1);
      local_8 = 2;
      FUN_005d7730(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1 >> 5),&local_50);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_005d27e0(param_1,*(int *)(in_ECX + 8) - local_18,&local_50);
      ExceptionList = local_10;
      return;
    }
    local_18 = param_2 * 0x20;
    iVar4 = local_28 + param_2 * -0x20;
    uVar3 = FUN_005d7630(iVar4,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar3;
    FUN_005d2810(param_1,iVar4,local_28);
    FUN_005d27e0(param_1,local_18 + param_1,&local_50);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005d78e4 @ 0x005d78e4 ====

void Catch_005d78e4(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x20));
  return;
}


// ==== FUN_005d79d0 @ 0x005d79d0 ====

void FUN_005d79d0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)(*(int *)(in_ECX + 0xc) - iVar1 >> 5) <= (uint)(*(int *)(in_ECX + 8) - iVar1 >> 5))) {
    FUN_005d7780(*(undefined4 *)(in_ECX + 8),1,param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005d76a0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x20;
  return;
}


// ==== FUN_005d7a50 @ 0x005d7a50 ====

/* WARNING: Removing unreachable block (ram,0x005d7af2) */

void FUN_005d7a50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c33c4;
  if (in_ECX[2] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[2]);
    in_ECX[2] = 0;
  }
  if (in_ECX[3] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[3]);
    in_ECX[3] = 0;
  }
  if (in_ECX[0xe] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0xe]);
    in_ECX[0xe] = 0;
  }
  if (in_ECX[0xf] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[0xf]);
    in_ECX[0xf] = 0;
  }
  if ((void *)in_ECX[0x1b] != (void *)0x0) {
    _free((void *)in_ECX[0x1b]);
    return;
  }
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  if ((void *)in_ECX[0x1f] != (void *)0x0) {
    _free((void *)in_ECX[0x1f]);
    return;
  }
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  if ((void *)in_ECX[0x1b] != (void *)0x0) {
    _free((void *)in_ECX[0x1b]);
    return;
  }
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  if (0xf < (uint)in_ECX[0x19]) {
    _free((void *)in_ECX[0x14]);
    return;
  }
  in_ECX[0x19] = 0xf;
  in_ECX[0x18] = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  if ((uint)in_ECX[0xd] < 0x10) {
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0xf;
    *(undefined1 *)(in_ECX + 8) = 0;
    *in_ECX = &PTR_FUN_009c3380;
    return;
  }
  _free((void *)in_ECX[8]);
  return;
}


// ==== FUN_005d7b70 @ 0x005d7b70 ====

undefined4 FUN_005d7b70(int param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  int in_ECX;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  uint *puVar8;
  int local_c;
  int local_8;
  
  if (*(int *)(in_ECX + 0x6c) != 0) {
    if ((*(int *)(in_ECX + 0x70) - *(int *)(in_ECX + 0x6c)) / 0x48 != 0) {
      uVar1 = 0;
      if (*(int *)(in_ECX + 0x6c) != 0) {
        uVar1 = (*(int *)(in_ECX + 0x70) - *(int *)(in_ECX + 0x6c)) / 0x48;
      }
      iVar7 = 0;
      local_c = 0;
      if (0x14 < uVar1) {
        local_c = 10;
        iVar7 = 10;
      }
      puVar4 = *(uint **)(in_ECX + 0x6c);
      if (puVar4 != *(uint **)(in_ECX + 0x70)) {
        local_8 = 0;
        do {
          puVar4[1] = puVar4[1] + param_1;
          if (iVar7 != 0) {
            puVar4[1] = local_8 + puVar4[1];
          }
          if (*puVar4 < puVar4[1]) {
            puVar5 = *(uint **)(in_ECX + 0x70);
            if (puVar4 + 0x12 != puVar5) {
              puVar2 = puVar4 + 0x12;
              puVar3 = puVar4;
              do {
                puVar8 = puVar2 + 0x12;
                puVar6 = puVar3;
                for (iVar7 = 0x12; iVar7 != 0; iVar7 = iVar7 + -1) {
                  *puVar6 = *puVar2;
                  puVar2 = puVar2 + 1;
                  puVar6 = puVar6 + 1;
                }
                puVar2 = puVar8;
                puVar3 = puVar3 + 0x12;
              } while (puVar8 != puVar5);
              iVar7 = local_c;
            }
            *(int *)(in_ECX + 0x70) = *(int *)(in_ECX + 0x70) + -0x48;
          }
          else {
            puVar4 = puVar4 + 0x12;
          }
          local_8 = local_8 + iVar7;
        } while (puVar4 != *(uint **)(in_ECX + 0x70));
      }
    }
  }
  puVar4 = (uint *)0x0;
  if (*(int *)(in_ECX + 0x7c) != 0) {
    iVar7 = *(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c);
    puVar4 = (uint *)(iVar7 * 0x38e38e39);
    if (iVar7 / 0x48 != 0) {
      puVar4 = (uint *)0x0;
      if (*(int *)(in_ECX + 0x7c) != 0) {
        puVar4 = (uint *)((*(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c)) / 0x48);
      }
      iVar7 = 0;
      local_8 = 0;
      if ((uint *)0x14 < puVar4) {
        local_8 = 10;
        iVar7 = 10;
      }
      puVar5 = *(uint **)(in_ECX + 0x7c);
      if (puVar5 != *(uint **)(in_ECX + 0x80)) {
        local_c = 0;
        do {
          puVar5[1] = puVar5[1] + param_1;
          if (iVar7 != 0) {
            puVar5[1] = local_c + puVar5[1];
          }
          puVar4 = (uint *)puVar5[1];
          if ((uint *)*puVar5 < puVar4) {
            puVar2 = *(uint **)(in_ECX + 0x80);
            puVar4 = puVar5 + 0x12;
            if (puVar4 != puVar2) {
              puVar3 = puVar4;
              puVar6 = puVar5;
              do {
                puVar4 = puVar3 + 0x12;
                puVar8 = puVar6;
                for (iVar7 = 0x12; iVar7 != 0; iVar7 = iVar7 + -1) {
                  *puVar8 = *puVar3;
                  puVar3 = puVar3 + 1;
                  puVar8 = puVar8 + 1;
                }
                puVar3 = puVar4;
                puVar6 = puVar6 + 0x12;
              } while (puVar4 != puVar2);
              iVar7 = local_8;
            }
            *(int *)(in_ECX + 0x80) = *(int *)(in_ECX + 0x80) + -0x48;
          }
          else {
            puVar5 = puVar5 + 0x12;
          }
          local_c = local_c + iVar7;
        } while (puVar5 != *(uint **)(in_ECX + 0x80));
      }
    }
  }
  return CONCAT31((int3)((uint)puVar4 >> 8),1);
}


// ==== FUN_005d7d40 @ 0x005d7d40 ====

void FUN_005d7d40(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 8));
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  if (*(int *)(in_ECX + 0xc) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0xc));
    *(undefined4 *)(in_ECX + 0xc) = 0;
  }
  if (*(int *)(in_ECX + 0x38) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x38));
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  if (*(int *)(in_ECX + 0x3c) != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(*(int *)(in_ECX + 0x3c));
    *(undefined4 *)(in_ECX + 0x3c) = 0;
  }
  FUN_00401740(&DAT_009c33b8,0);
  FUN_00401740(&DAT_009c33b9,0);
  if (*(void **)(in_ECX + 0x6c) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x6c));
    return;
  }
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  *(undefined4 *)(in_ECX + 0x74) = 0;
  if (*(void **)(in_ECX + 0x7c) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x7c) = 0;
    *(undefined4 *)(in_ECX + 0x80) = 0;
    *(undefined4 *)(in_ECX + 0x84) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x7c));
  return;
}


// ==== FUN_005d7e00 @ 0x005d7e00 ====

void FUN_005d7e00(undefined4 param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c33c4;
  in_ECX[0xc] = 0;
  in_ECX[0xd] = 0xf;
  *(undefined1 *)(in_ECX + 8) = 0;
  in_ECX[0x19] = 0xf;
  in_ECX[0x18] = 0;
  *(undefined1 *)(in_ECX + 0x14) = 0;
  in_ECX[0x1b] = 0;
  in_ECX[0x1c] = 0;
  in_ECX[0x1d] = 0;
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  in_ECX[1] = param_1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  FUN_00401740(&DAT_009c33b6,0);
  FUN_00401740(&DAT_009c33b7,0);
  in_ECX[0x22] = 0;
  in_ECX[0x23] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x27] = 0;
  return;
}


// ==== FUN_005d7ee0 @ 0x005d7ee0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d7ee0(int *param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  undefined4 *puVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  float10 fVar10;
  int *piStack_58;
  undefined4 uStack_48;
  float fStack_44;
  int aiStack_40 [16];
  
  if ((((*(int *)(in_ECX + 0x6c) != 0) &&
       ((*(int *)(in_ECX + 0x70) - *(int *)(in_ECX + 0x6c)) / 0x48 != 0)) &&
      (*(int *)(in_ECX + 8) != 0)) &&
     (((cVar4 = (**(code **)(**(int **)(in_ECX + 8) + 0x2c))(), cVar4 != '\0' &&
       (*(int *)(in_ECX + 0xc) != 0)) &&
      (cVar4 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x2c))(), cVar4 != '\0')))) {
    puVar5 = (undefined4 *)(**(code **)(*param_1 + 0xe8))();
    *(undefined1 *)(puVar5 + 2) = *(undefined1 *)(in_ECX + 0x10);
    puVar5[4] = *(undefined4 *)(in_ECX + 0x18);
    *puVar5 = *(undefined4 *)(in_ECX + 8);
    puVar5[1] = *(undefined4 *)(in_ECX + 0xc);
    puVar5[3] = *(undefined4 *)(in_ECX + 0x14);
    piVar1 = *(int **)(in_ECX + 0x70);
    piVar7 = *(int **)(in_ECX + 0x6c);
    if (piVar7 != piVar1) {
      piStack_58 = piVar7 + 2;
      do {
        fVar2 = (float)piStack_58[-1];
        if (piStack_58[-1] < 0) {
          fVar2 = fVar2 + _DAT_0099d104;
        }
        fVar3 = (float)*piVar7;
        if (*piVar7 < 0) {
          fVar3 = fVar3 + _DAT_0099d104;
        }
        fVar10 = (float10)FUN_0040d4c0(_DAT_00af6084 * (fVar2 / fVar3));
        fStack_44 = DAT_009a09bc;
        if ((float10)DAT_009a09bc <= (float10)DAT_009b2dbc - fVar10) {
          fStack_44 = (float)((float10)DAT_009b2dbc - fVar10);
        }
        uStack_48 = *(undefined4 *)(*(int *)(*(int *)(in_ECX + 4) + 0xd8) + 0x10);
        piVar8 = piStack_58;
        piVar9 = aiStack_40;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar9 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar9 = piVar9 + 1;
        }
        FUN_005b22f0(&uStack_48);
        piStack_58 = piStack_58 + 0x12;
        piVar7 = piVar7 + 0x12;
      } while (piVar7 != piVar1);
    }
    (**(code **)(*param_1 + 0x7c))(puVar5);
  }
  return;
}


// ==== FUN_005d8060 @ 0x005d8060 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d8060(int *param_1)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  undefined4 *puVar5;
  int in_ECX;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  float10 fVar10;
  int *piStack_58;
  undefined4 uStack_48;
  float fStack_44;
  int aiStack_40 [16];
  
  if ((((*(int *)(in_ECX + 0x7c) != 0) &&
       ((*(int *)(in_ECX + 0x80) - *(int *)(in_ECX + 0x7c)) / 0x48 != 0)) &&
      (*(int *)(in_ECX + 0x38) != 0)) &&
     (((cVar4 = (**(code **)(**(int **)(in_ECX + 0x38) + 0x2c))(), cVar4 != '\0' &&
       (*(int *)(in_ECX + 0x3c) != 0)) &&
      (cVar4 = (**(code **)(**(int **)(in_ECX + 0x3c) + 0x2c))(), cVar4 != '\0')))) {
    puVar5 = (undefined4 *)(**(code **)(*param_1 + 0xe8))();
    *(undefined1 *)(puVar5 + 2) = *(undefined1 *)(in_ECX + 0x40);
    puVar5[4] = *(undefined4 *)(in_ECX + 0x48);
    *puVar5 = *(undefined4 *)(in_ECX + 0x38);
    puVar5[1] = *(undefined4 *)(in_ECX + 0x3c);
    puVar5[3] = *(undefined4 *)(in_ECX + 0x44);
    piVar1 = *(int **)(in_ECX + 0x80);
    piVar7 = *(int **)(in_ECX + 0x7c);
    if (piVar7 != piVar1) {
      piStack_58 = piVar7 + 2;
      do {
        fVar2 = (float)piStack_58[-1];
        if (piStack_58[-1] < 0) {
          fVar2 = fVar2 + _DAT_0099d104;
        }
        fVar3 = (float)*piVar7;
        if (*piVar7 < 0) {
          fVar3 = fVar3 + _DAT_0099d104;
        }
        fVar10 = (float10)FUN_0040d4c0(_DAT_00af6084 * (fVar2 / fVar3));
        fStack_44 = DAT_009a09bc;
        if ((float10)DAT_009a09bc <= (float10)DAT_009b2dbc - fVar10) {
          fStack_44 = (float)((float10)DAT_009b2dbc - fVar10);
        }
        uStack_48 = *(undefined4 *)(*(int *)(*(int *)(in_ECX + 4) + 0xd8) + 0x10);
        piVar8 = piStack_58;
        piVar9 = aiStack_40;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *piVar9 = *piVar8;
          piVar8 = piVar8 + 1;
          piVar9 = piVar9 + 1;
        }
        FUN_005b22f0(&uStack_48);
        piStack_58 = piStack_58 + 0x12;
        piVar7 = piVar7 + 0x12;
      } while (piVar7 != piVar1);
    }
    (**(code **)(*param_1 + 0x7c))(puVar5);
  }
  return;
}


// ==== FUN_005d81e0 @ 0x005d81e0 ====

void FUN_005d81e0(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80 [16];
  undefined1 local_40 [64];
  
  local_88 = 0x17c;
  local_84 = 0;
  puVar1 = (undefined4 *)FUN_005d16d0(local_40,param_1);
  puVar3 = local_80;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *puVar1;
    puVar1 = puVar1 + 1;
    puVar3 = puVar3 + 1;
  }
  if (param_1 == 0) {
    FUN_005d8ab0(&local_88);
    return;
  }
  FUN_005d8ab0(&local_88);
  return;
}


// ==== FUN_005d8260 @ 0x005d8260 ====

void FUN_005d8260(undefined4 param_1)

{
  FUN_005d7ee0(param_1);
  FUN_005d8060(param_1);
  return;
}


// ==== FUN_005d8280 @ 0x005d8280 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d8280(float *param_1,undefined4 param_2,undefined4 *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined4 *puVar7;
  undefined1 auStack_c0 [4];
  void *pvStack_bc;
  undefined4 uStack_ac;
  uint uStack_a8;
  undefined1 auStack_a4 [4];
  void *pvStack_a0;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 auStack_80 [16];
  undefined1 auStack_40 [64];
  
  fVar1 = *param_1 - *(float *)(in_ECX + 0x88);
  fVar3 = param_1[1] - *(float *)(in_ECX + 0x8c);
  fVar2 = param_1[2] - *(float *)(in_ECX + 0x90);
  if (_DAT_009c33dc <= SQRT(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2)) {
    *(float *)(in_ECX + 0x88) = *param_1;
    *(float *)(in_ECX + 0x8c) = param_1[1];
    *(float *)(in_ECX + 0x90) = param_1[2];
    uVar4 = (**(code **)(*(int *)*param_3 + 4))();
    uStack_8c = 0xf;
    uStack_90 = 0;
    pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
    FUN_00401660(uVar4,0,0xffffffff);
    uVar4 = (**(code **)(*(int *)param_3[1] + 4))();
    uStack_a8 = 0xf;
    uStack_ac = 0;
    pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
    FUN_00401660(uVar4,0,0xffffffff);
    if (*(uint *)(in_ECX + 0x34) < 0x10) {
      iVar5 = in_ECX + 0x20;
    }
    else {
      iVar5 = *(int *)(in_ECX + 0x20);
    }
    iVar5 = FUN_00403620(0,uStack_ac,iVar5,*(undefined4 *)(in_ECX + 0x30));
    if (iVar5 == 0) {
      uStack_88 = 0x17c;
      uStack_84 = 0;
      puVar6 = (undefined4 *)FUN_005d16d0(auStack_40,0);
      puVar7 = auStack_80;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      FUN_005d8ab0(&uStack_88);
    }
    else {
      iVar5 = FUN_005b1c00(auStack_a4);
      *(int *)(in_ECX + 8) = iVar5;
      if (iVar5 != 0) {
        iVar5 = FUN_005aa220(auStack_c0);
        *(int *)(in_ECX + 0xc) = iVar5;
        if (iVar5 != 0) {
          FUN_00401660(auStack_c0,0,0xffffffff);
          *(undefined1 *)(in_ECX + 0x10) = *(undefined1 *)(param_3 + 2);
          *(undefined4 *)(in_ECX + 0x18) = param_3[4];
          *(undefined4 *)(in_ECX + 0x14) = param_3[3];
          FUN_005d81e0(0);
        }
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    if (0xf < uStack_a8) {
      _free(pvStack_bc);
      return;
    }
    uStack_a8 = 0xf;
    uStack_ac = 0;
    pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
    if (0xf < uStack_8c) {
      _free(pvStack_a0);
      return;
    }
  }
  return;
}


// ==== FUN_005d8460 @ 0x005d8460 ====

void FUN_005d8460(float *param_1,undefined4 param_2,undefined4 *param_3)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int in_ECX;
  undefined4 *puVar7;
  undefined1 auStack_c0 [4];
  void *pvStack_bc;
  undefined4 uStack_ac;
  uint uStack_a8;
  undefined1 auStack_a4 [4];
  void *pvStack_a0;
  undefined4 uStack_90;
  uint uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 auStack_80 [16];
  undefined1 auStack_40 [64];
  
  fVar1 = *param_1 - *(float *)(in_ECX + 0x94);
  fVar3 = param_1[1] - *(float *)(in_ECX + 0x98);
  fVar2 = param_1[2] - *(float *)(in_ECX + 0x9c);
  if (DAT_009a09bc <= SQRT(fVar1 * fVar1 + fVar3 * fVar3 + fVar2 * fVar2)) {
    *(float *)(in_ECX + 0x94) = *param_1;
    *(float *)(in_ECX + 0x98) = param_1[1];
    *(float *)(in_ECX + 0x9c) = param_1[2];
    uVar4 = (**(code **)(*(int *)*param_3 + 4))();
    uStack_8c = 0xf;
    uStack_90 = 0;
    pvStack_a0 = (void *)((uint)pvStack_a0 & 0xffffff00);
    FUN_00401660(uVar4,0,0xffffffff);
    uVar4 = (**(code **)(*(int *)param_3[1] + 4))();
    uStack_a8 = 0xf;
    uStack_ac = 0;
    pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
    FUN_00401660(uVar4,0,0xffffffff);
    if (*(uint *)(in_ECX + 100) < 0x10) {
      iVar5 = in_ECX + 0x50;
    }
    else {
      iVar5 = *(int *)(in_ECX + 0x50);
    }
    iVar5 = FUN_00403620(0,uStack_ac,iVar5,*(undefined4 *)(in_ECX + 0x60));
    if (iVar5 == 0) {
      uStack_88 = 0x17c;
      uStack_84 = 0;
      puVar6 = (undefined4 *)FUN_005d16d0(auStack_40,1);
      puVar7 = auStack_80;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
      FUN_005d8ab0(&uStack_88);
    }
    else {
      iVar5 = FUN_005b1c00(auStack_a4);
      *(int *)(in_ECX + 0x38) = iVar5;
      if (iVar5 != 0) {
        iVar5 = FUN_005aa220(auStack_c0);
        *(int *)(in_ECX + 0x3c) = iVar5;
        if (iVar5 != 0) {
          FUN_00401660(auStack_c0,0,0xffffffff);
          *(undefined1 *)(in_ECX + 0x40) = *(undefined1 *)(param_3 + 2);
          *(undefined4 *)(in_ECX + 0x48) = param_3[4];
          *(undefined4 *)(in_ECX + 0x44) = param_3[3];
          FUN_005d81e0(1);
        }
                    /* WARNING: Subroutine does not return */
        FUN_00446f10();
      }
    }
    if (0xf < uStack_a8) {
      _free(pvStack_bc);
      return;
    }
    uStack_a8 = 0xf;
    uStack_ac = 0;
    pvStack_bc = (void *)((uint)pvStack_bc & 0xffffff00);
    if (0xf < uStack_8c) {
      _free(pvStack_a0);
      return;
    }
  }
  return;
}


// ==== FUN_005d8640 @ 0x005d8640 ====

int FUN_005d8640(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982d30;
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


// ==== Catch@005d86a6 @ 0x005d86a6 ====

void Catch_005d86a6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d86b0 @ 0x005d86b0 ====

void FUN_005d86b0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982d40;
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


// ==== Catch@005d8716 @ 0x005d8716 ====

void Catch_005d8716(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d8720 @ 0x005d8720 ====

void FUN_005d8720(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005d8640(param_1,param_2,param_3);
  return;
}


// ==== FUN_005d8740 @ 0x005d8740 ====

int FUN_005d8740(int param_1,int param_2,undefined4 param_3)

{
  FUN_005d86b0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x48;
}


// ==== FUN_005d8770 @ 0x005d8770 ====

void FUN_005d8770(byte param_1)

{
  void *in_ECX;
  
  FUN_005d7a50();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005d8790 @ 0x005d8790 ====

void FUN_005d8790(int param_1,uint param_2,undefined4 *param_3)

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
  puStack_c = &LAB_00982d50;
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
      local_1c = FUN_005d8720(*(undefined4 *)(in_ECX + 4),param_1,local_18);
      local_1c = FUN_005d8740(local_1c,param_2,&local_7c);
      FUN_005d8720(param_1,*(undefined4 *)(in_ECX + 8),local_1c);
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
      FUN_005d8640(param_1,local_28,local_24 + param_1);
      local_8 = 2;
      FUN_005d8740(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x48,&local_7c)
      ;
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_24;
      FUN_008684d0(param_1,*(int *)(in_ECX + 8) - local_24,&local_7c);
      ExceptionList = local_10;
      return;
    }
    local_2c = local_28 + param_2 * -0x48;
    uVar2 = FUN_005d8640(local_2c,local_28,local_28);
    *(undefined4 *)(in_ECX + 8) = uVar2;
    FUN_00868660(param_1,local_2c,local_28);
    FUN_008684d0(param_1,param_2 * 0x48 + param_1,&local_7c);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005d8938 @ 0x005d8938 ====

void Catch_005d8938(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x14));
  return;
}


// ==== FUN_005d8a40 @ 0x005d8a40 ====

void FUN_005d8a40(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x48 != 0) {
      iVar1 = (param_2 - iVar1) / 0x48;
      goto LAB_005d8a85;
    }
  }
  iVar1 = 0;
LAB_005d8a85:
  FUN_005d8790(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x48;
  return;
}


// ==== FUN_005d8ab0 @ 0x005d8ab0 ====

void FUN_005d8ab0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x48) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x48))) {
    FUN_005d8a40(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005d86b0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x48;
  return;
}


// ==== FUN_005d8b40 @ 0x005d8b40 ====

void FUN_005d8b40(int *param_1,int param_2)

{
  int in_ECX;
  
  FUN_0042ea00(param_2 + 0xc,*(undefined4 *)(in_ECX + 8),param_2,param_2);
  *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + -0xc;
  *param_1 = param_2;
  return;
}


// ==== FUN_005d8b70 @ 0x005d8b70 ====

void FUN_005d8b70(void)

{
  int in_ECX;
  
  if (*(void **)(in_ECX + 0x38) != (void *)0x0) {
    _free(*(void **)(in_ECX + 0x38));
    return;
  }
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  if (*(void **)(in_ECX + 0x60) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 0x60) = 0;
    *(undefined4 *)(in_ECX + 100) = 0;
    *(undefined4 *)(in_ECX + 0x68) = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    *(undefined4 *)(in_ECX + 0x54) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 0x60));
  return;
}


// ==== FUN_005d8bc0 @ 0x005d8bc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d8bc0(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  char cVar7;
  int iVar8;
  undefined4 uVar9;
  int in_ECX;
  int *piVar10;
  float10 fVar11;
  
  if (((*(int *)(in_ECX + 0x10) != 0) &&
      ((*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10)) / 0x28 != 0)) &&
     (cVar7 = (**(code **)(**(int **)(in_ECX + 8) + 0x2c))(), cVar7 != '\0')) {
    piVar2 = *(int **)(in_ECX + 0x14);
    for (piVar10 = *(int **)(in_ECX + 0x10); piVar10 != piVar2; piVar10 = piVar10 + 10) {
      iVar8 = (**(code **)(*param_1 + 0xdc))();
      iVar3 = piVar10[1];
      iVar4 = *piVar10;
      fVar5 = (float)iVar3;
      if (iVar3 < 0) {
        fVar5 = fVar5 + _DAT_0099d104;
      }
      fVar6 = (float)iVar4;
      if (iVar4 < 0) {
        fVar6 = fVar6 + _DAT_0099d104;
      }
      fVar5 = DAT_0099d080 - fVar5 / fVar6;
      iVar1 = (int)ROUND(fVar5 * DAT_009bf5a0);
      fVar11 = (float10)FUN_005aa2a0(iVar1,iVar4 - iVar3);
      *(float *)(iVar8 + 0x1c) = (float)fVar11;
      *(float *)(iVar8 + 0x14) = fVar5 * (float)piVar10[2];
      fVar11 = (float10)FUN_005aa2a0(iVar1,iVar4 - iVar3);
      *(float *)(iVar8 + 0x18) = (float)fVar11;
      uVar9 = FUN_004b3ff0((char)piVar10[5]);
      *(undefined4 *)(iVar8 + 0x10) = uVar9;
      FUN_005d9b50(piVar10 + 6);
      (**(code **)(*param_1 + 0x80))(iVar8);
    }
  }
  return;
}


// ==== FUN_005d8d00 @ 0x005d8d00 ====

void FUN_005d8d00(float *param_1,float *param_2,float *param_3,float *param_4,float param_5,
                 float param_6)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float local_3c;
  float local_38;
  float local_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (DAT_009b9f98 <= param_5) {
    iVar1 = (int)(param_5 * DAT_009a000c + DAT_0099d0b4);
    iVar2 = 1;
    if (0 < iVar1) {
      do {
        fVar3 = (float)iVar2 / (float)(iVar1 + 1);
        local_3c = (*param_2 - *param_4) * fVar3 + *param_4;
        local_38 = (param_2[1] - param_4[1]) * fVar3 + param_4[1];
        local_34 = (param_2[2] - param_4[2]) * fVar3 + param_4[2];
        local_24 = ((*param_1 - *param_3) * fVar3 + *param_3) - local_3c;
        local_20 = ((param_1[1] - param_3[1]) * fVar3 + param_3[1]) - local_38;
        local_1c = ((param_1[2] - param_3[2]) * fVar3 + param_3[2]) - local_34;
        thunk_FUN_0079e1ba(&local_18,&local_24);
        fStack_30 = local_18 * param_6 + local_3c;
        fStack_28 = fStack_10 * param_6 + local_34;
        fStack_2c = fStack_14 * param_6 + local_38;
        fStack_c = fStack_30;
        fStack_8 = fStack_2c;
        fStack_4 = fStack_28;
        FUN_005c2400(&fStack_c);
        FUN_005c2400(&local_3c);
        iVar2 = iVar2 + 1;
      } while (iVar2 <= iVar1);
    }
  }
  return;
}


// ==== FUN_005d8eb0 @ 0x005d8eb0 ====

void FUN_005d8eb0(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  int iVar3;
  void *_Memory;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 local_1c [4];
  void *local_18;
  int local_14;
  int local_10;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009c3434;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  puVar2 = in_ECX + 0xf;
  iVar3 = 2;
  do {
    puVar2[-1] = 0;
    *puVar2 = 0;
    puVar2[1] = 0;
    puVar2 = puVar2 + 10;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  iVar3 = FUN_0058b910();
  in_ECX[0x1c] = iVar3;
  *(undefined1 *)(iVar3 + 0x19) = 1;
  *(undefined4 *)(in_ECX[0x1c] + 4) = in_ECX[0x1c];
  *(undefined4 *)in_ECX[0x1c] = in_ECX[0x1c];
  *(undefined4 *)(in_ECX[0x1c] + 8) = in_ECX[0x1c];
  in_ECX[0x1d] = 0;
  iVar3 = FUN_0058b910();
  in_ECX[0x22] = iVar3;
  *(undefined1 *)(iVar3 + 0x19) = 1;
  *(undefined4 *)(in_ECX[0x22] + 4) = in_ECX[0x22];
  *(undefined4 *)in_ECX[0x22] = in_ECX[0x22];
  *(undefined4 *)(in_ECX[0x22] + 8) = in_ECX[0x22];
  in_ECX[0x23] = 0;
  in_ECX[1] = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_effect_hit_eff_bloodtrace_tpack_009c33e4,0x1f);
  uVar1 = FUN_005aa220(local_1c);
  in_ECX[2] = uVar1;
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  local_20 = 0;
  param_1 = 4;
  puVar2 = in_ECX + 0x27;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    param_1 = param_1 + -1;
    puVar2[2] = 0;
    puVar2 = puVar2 + 3;
  } while (param_1 != 0);
  local_18 = (void *)0x0;
  local_14 = 0;
  local_10 = 0;
  local_28 = 0;
  local_24 = DAT_0099d080;
  FUN_004b9740(0,1,&local_28);
  local_28 = 800;
  local_24 = DAT_009c1cac;
  if ((local_18 == (void *)0x0) ||
     ((uint)(local_10 - (int)local_18 >> 3) <= (uint)(local_14 - (int)local_18 >> 3))) {
    FUN_004b9740(local_14,1,&local_28);
  }
  else {
    FUN_00429bc0(local_14,1,&local_28,local_1c,0);
    local_14 = local_14 + 8;
  }
  local_28 = 999;
  local_24 = 0;
  if ((local_18 == (void *)0x0) ||
     ((uint)(local_10 - (int)local_18 >> 3) <= (uint)(local_14 - (int)local_18 >> 3))) {
    FUN_004b9740(local_14,1,&local_28);
  }
  else {
    FUN_00429bc0(local_14,1,&local_28,local_1c,0);
    local_14 = local_14 + 8;
  }
  FUN_004b9a80(0,1000,local_1c);
  if (local_18 != (void *)0x0) {
    _free(local_18);
    return;
  }
  local_18 = (void *)0x0;
  local_14 = 0;
  local_10 = 0;
  local_28 = 0;
  local_24 = DAT_009c342c;
  FUN_004b9740(0,1,&local_28);
  _Memory = local_18;
  local_28 = 200;
  local_24 = 0;
  if ((local_18 == (void *)0x0) ||
     ((uint)(local_10 - (int)local_18 >> 3) <= (uint)(local_14 - (int)local_18 >> 3))) {
    FUN_004b9740(local_14,1,&local_28);
    _Memory = local_18;
  }
  else {
    FUN_00429bc0(local_14,1,&local_28,local_1c,0);
    local_14 = local_14 + 8;
  }
  local_28 = 999;
  local_24 = DAT_009c3428;
  if ((_Memory == (void *)0x0) ||
     ((uint)(local_10 - (int)_Memory >> 3) <= (uint)(local_14 - (int)_Memory >> 3))) {
    FUN_004b9740(local_14,1,&local_28);
    _Memory = local_18;
  }
  else {
    FUN_00429bc0(local_14,1,&local_28,local_1c,0);
    local_14 = local_14 + 8;
  }
  FUN_004b9a80(0,1000,local_1c);
  in_ECX[0x33] = 0;
  in_ECX[0x34] = 0;
  if (_Memory == (void *)0x0) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_005d9230 @ 0x005d9230 ====

void FUN_005d9230(void)

{
  undefined4 *in_ECX;
  undefined4 *puStack_4;
  
  *in_ECX = &PTR_FUN_009c3434;
  puStack_4 = in_ECX;
  if (in_ECX[2] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[2]);
    in_ECX[2] = 0;
  }
  if ((void *)in_ECX[0xe] != (void *)0x0) {
    _free((void *)in_ECX[0xe]);
    return;
  }
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x10] = 0;
  if ((void *)in_ECX[0x18] != (void *)0x0) {
    _free((void *)in_ECX[0x18]);
    return;
  }
  in_ECX[0x18] = 0;
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  if (in_ECX[4] == 0) {
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    FUN_004b9680(&puStack_4,*(undefined4 *)in_ECX[0x22],(undefined4 *)in_ECX[0x22]);
    _free((void *)in_ECX[0x22]);
    return;
  }
  FUN_005d9d30(in_ECX[4],in_ECX[5],in_ECX + 3,puStack_4);
  _free((void *)in_ECX[4]);
  return;
}


// ==== FUN_005d9380 @ 0x005d9380 ====

undefined4 FUN_005d9380(uint param_1)

{
  undefined4 extraout_EAX;
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  if ((*(int *)(in_ECX + 0x10) == 0) ||
     ((*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10)) / 0x28 == 0)) {
    return 1;
  }
  iVar1 = *(int *)(in_ECX + 0x10);
  if (iVar1 == *(int *)(in_ECX + 0x14)) {
    return 1;
  }
  puVar2 = (undefined4 *)(iVar1 + 0x1c);
  do {
    if (param_1 < (uint)puVar2[-6]) {
      puVar2[-6] = puVar2[-6] - param_1;
      iVar1 = iVar1 + 0x28;
      puVar2 = puVar2 + 10;
    }
    else {
      if ((void *)*puVar2 != (void *)0x0) {
        _free((void *)*puVar2);
        return extraout_EAX;
      }
      *puVar2 = 0;
      puVar2[1] = 0;
      puVar2[2] = 0;
      puVar2[-3] = 0;
      FUN_005d9cd0(puVar2 + 3,*(undefined4 *)(in_ECX + 0x14),iVar1,param_1);
      FUN_005d9d30(*(int *)(in_ECX + 0x14) + -0x28,*(int *)(in_ECX + 0x14),in_ECX + 0xc,param_1);
      *(int *)(in_ECX + 0x14) = *(int *)(in_ECX + 0x14) + -0x28;
      if ((*(int *)(in_ECX + 0x10) == 0) ||
         ((*(int *)(in_ECX + 0x14) - *(int *)(in_ECX + 0x10)) / 0x28 == 0)) {
        *(undefined4 *)(in_ECX + 0x9c) = 0;
        *(undefined4 *)(in_ECX + 0xa0) = 0;
        *(undefined4 *)(in_ECX + 0xa4) = 0;
        *(undefined4 *)(in_ECX + 0xa8) = 0;
        *(undefined4 *)(in_ECX + 0xac) = 0;
        *(undefined4 *)(in_ECX + 0xb0) = 0;
        *(undefined4 *)(in_ECX + 0xb4) = 0;
        *(undefined4 *)(in_ECX + 0xb8) = 0;
        *(undefined4 *)(in_ECX + 0xbc) = 0;
        *(undefined4 *)(in_ECX + 0xc0) = 0;
        *(undefined4 *)(in_ECX + 0xc4) = 0;
        *(undefined4 *)(in_ECX + 200) = 0;
      }
    }
  } while (iVar1 != *(int *)(in_ECX + 0x14));
  return 1;
}


// ==== FUN_005d9550 @ 0x005d9550 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005d9550(float *param_1,undefined4 param_2,float *param_3,float *param_4)

{
  float fVar1;
  char cVar2;
  undefined4 uVar3;
  float *pfVar4;
  int iVar5;
  float unaff_EBP;
  int unaff_ESI;
  undefined2 in_FPUControlWord;
  float fVar6;
  float fVar7;
  float fVar8;
  float *unaff_retaddr;
  undefined1 local_3c [2];
  undefined1 auStack_3a [2];
  float local_38;
  float fStack_34;
  float local_30;
  float local_2c;
  float local_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  undefined1 local_18 [4];
  float fStack_14;
  float fStack_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_30 = *param_1 - *param_3;
  local_2c = param_1[1] - param_3[1];
  local_28 = param_1[2] - param_3[2];
  local_38 = SQRT(local_30 * local_30 + local_2c * local_2c + local_28 * local_28);
  if (local_38 <= DAT_009b02b0) {
    return;
  }
  local_c = *param_3 - *param_4;
  local_8 = param_3[1] - param_4[1];
  local_4 = param_3[2] - param_4[2];
  thunk_FUN_0079e1ba(local_18,&local_c);
  fStack_14 = *param_1 - *unaff_retaddr;
  fStack_10 = param_1[1] - unaff_retaddr[1];
  local_c = param_1[2] - unaff_retaddr[2];
  thunk_FUN_0079e1ba(&local_2c,&fStack_14);
  local_4 = SQRT((*unaff_retaddr - *param_1) * (*unaff_retaddr - *param_1) +
                 (unaff_retaddr[1] - param_1[1]) * (unaff_retaddr[1] - param_1[1]) +
                 (unaff_retaddr[2] - param_1[2]) * (unaff_retaddr[2] - param_1[2]));
  cVar2 = FUN_005d1660(param_1);
  if ((cVar2 == '\x01') &&
     (iVar5 = unaff_ESI + (int)param_1 * 0x28,
     DAT_009a000c <= *(float *)(unaff_ESI + 0x2c + (int)param_1 * 0x28))) {
    fVar6 = local_4 * _DAT_009c3454;
    local_c = (float)CONCAT22(local_c._2_2_,in_FPUControlWord);
    *(float *)(iVar5 + 0x24) = local_4 * _DAT_009c3450;
    local_8 = (float)(int)ROUND(fVar6);
    *(int *)(iVar5 + 0x1c) = 0x122 - (int)local_8;
    *(int *)(iVar5 + 0x20) = 0x122 - (int)local_8;
    *(undefined1 *)(iVar5 + 0x30) = *(undefined1 *)(*(int *)(*(int *)(unaff_ESI + 4) + 0xd8) + 1);
    FUN_005da3b0((int *)(iVar5 + 0x1c));
    fVar6 = local_4 * DAT_0099d0f8;
    *(int *)(iVar5 + 0x20) = *(int *)(iVar5 + 0x20) + -200;
    *(float *)(iVar5 + 0x24) = fVar6;
    FUN_005da3b0(iVar5 + 0x1c);
    FUN_00412dc0();
    *(undefined4 *)(iVar5 + 0x2c) = 0;
    uVar3 = (**(code **)(*DAT_00b5a6ac + 0x20))();
    *(undefined4 *)(unaff_ESI + 0xcc + (int)param_1 * 4) = uVar3;
  }
  fVar1 = DAT_009b0ec8;
  fVar6 = (float)(unaff_ESI + (int)param_1 * 0x28);
  local_c = fVar6;
  if (((*(int *)((int)fVar6 + 0x38) != 0) &&
      (0x13 < (uint)((*(int *)((int)fVar6 + 0x3c) - *(int *)((int)fVar6 + 0x38)) / 0xc))) ||
     (DAT_009c344c <= unaff_EBP)) {
    if (*(void **)((int)fVar6 + 0x38) != (void *)0x0) {
      _free(*(void **)((int)fVar6 + 0x38));
      return;
    }
    *(undefined4 *)((int)fVar6 + 0x38) = 0;
    *(undefined4 *)((int)fVar6 + 0x3c) = 0;
    *(undefined4 *)((int)fVar6 + 0x40) = 0;
    *(undefined4 *)((int)fVar6 + 0x2c) = 0;
    goto LAB_005d995e;
  }
  fVar7 = local_2c * fStack_20 + local_30 * fStack_24 + fStack_34 * local_28;
  fVar8 = (DAT_0099d080 - fVar7) + *(float *)((int)fVar6 + 0x2c);
  *(float *)((int)fVar6 + 0x2c) = fVar8;
  if (fVar1 < fVar8) {
    FUN_005d8b40(&local_8,*(undefined4 *)((int)fVar6 + 0x38));
    FUN_005d8b40(&local_8,*(undefined4 *)((int)local_c + 0x38));
  }
  if (*(int *)((int)fVar6 + 0x38) != 0) {
    local_8 = (float)((*(int *)((int)fVar6 + 0x3c) - *(int *)((int)fVar6 + 0x38)) / 0xc);
    if (1 < (uint)local_8) {
      thunk_FUN_0079e1ba(&local_28,local_3c + -4);
      pfVar4 = (float *)FUN_00430730((int)fStack_10 + -2);
      fStack_1c = param_3[2] - pfVar4[2];
      fStack_20 = param_3[1] - pfVar4[1];
      fStack_24 = *param_3 - *pfVar4;
      thunk_FUN_0079e1ba(local_3c,&fStack_24);
      if (local_2c * fStack_20 + local_30 * fStack_24 + fStack_34 * local_28 <= DAT_009b0318) {
        FUN_00412dc0();
        *(float *)((int)local_c + 0x2c) = fVar7;
        goto LAB_005d9909;
      }
    }
    if (local_8 == 1.4013e-45) {
      FUN_005c2400(param_3);
      FUN_005c2400(unaff_retaddr);
    }
  }
LAB_005d9909:
  FUN_005d8d00(param_1,unaff_retaddr,param_3,unaff_retaddr,unaff_EBP,local_4,(int)fVar6 + 0x34);
  FUN_005c2400(param_1);
  FUN_005c2400(unaff_retaddr);
LAB_005d995e:
  *param_3 = *param_1;
  param_3[1] = param_1[1];
  param_3[2] = param_1[2];
  *unaff_retaddr = *unaff_retaddr;
  unaff_retaddr[1] = unaff_retaddr[1];
  unaff_retaddr[2] = unaff_retaddr[2];
  iVar5 = (**(code **)(*DAT_00b5a6ac + 0x20))();
  if (200 < (uint)(iVar5 - *(int *)(unaff_ESI + 0xcc + (int)param_1 * 4))) {
    FUN_005d1630(param_1,0);
  }
  return;
}


// ==== FUN_005d99c0 @ 0x005d99c0 ====

void FUN_005d99c0(undefined4 *param_1,undefined4 *param_2)

{
  int in_ECX;
  
  if (((*(float *)(in_ECX + 0x9c) == 0.0) && (*(float *)(in_ECX + 0xa0) == 0.0)) &&
     (*(float *)(in_ECX + 0xa4) == 0.0)) {
    *(undefined4 *)(in_ECX + 0x9c) = *param_1;
    *(undefined4 *)(in_ECX + 0xa0) = param_1[1];
    *(undefined4 *)(in_ECX + 0xa4) = param_1[2];
    *(undefined4 *)(in_ECX + 0xa8) = *param_2;
    *(undefined4 *)(in_ECX + 0xac) = param_2[1];
    *(undefined4 *)(in_ECX + 0xb0) = param_2[2];
    if (*(void **)(in_ECX + 0x38) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x38));
      return;
    }
    *(undefined4 *)(in_ECX + 0x38) = 0;
    *(undefined4 *)(in_ECX + 0x3c) = 0;
    *(undefined4 *)(in_ECX + 0x40) = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 0;
  }
  FUN_005d9550(param_1,param_2,(undefined4 *)(in_ECX + 0x9c),in_ECX + 0xa8,0);
  return;
}


// ==== FUN_005d9a70 @ 0x005d9a70 ====

void FUN_005d9a70(undefined4 *param_1,undefined4 *param_2)

{
  int in_ECX;
  
  if (((*(float *)(in_ECX + 0xb4) == 0.0) && (*(float *)(in_ECX + 0xb8) == 0.0)) &&
     (*(float *)(in_ECX + 0xbc) == 0.0)) {
    *(undefined4 *)(in_ECX + 0xb4) = *param_1;
    *(undefined4 *)(in_ECX + 0xb8) = param_1[1];
    *(undefined4 *)(in_ECX + 0xbc) = param_1[2];
    *(undefined4 *)(in_ECX + 0xc0) = *param_2;
    *(undefined4 *)(in_ECX + 0xc4) = param_2[1];
    *(undefined4 *)(in_ECX + 200) = param_2[2];
    if (*(void **)(in_ECX + 0x60) != (void *)0x0) {
      _free(*(void **)(in_ECX + 0x60));
      return;
    }
    *(undefined4 *)(in_ECX + 0x60) = 0;
    *(undefined4 *)(in_ECX + 100) = 0;
    *(undefined4 *)(in_ECX + 0x68) = 0;
    *(undefined4 *)(in_ECX + 0x54) = 0;
  }
  FUN_005d9550(param_1,param_2,(undefined4 *)(in_ECX + 0xb4),in_ECX + 0xc0,1);
  return;
}


// ==== FUN_005d9b20 @ 0x005d9b20 ====

void FUN_005d9b20(int param_1)

{
  if (*(void **)(param_1 + 0x1c) == (void *)0x0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    *(undefined4 *)(param_1 + 0x24) = 0;
    return;
  }
  _free(*(void **)(param_1 + 0x1c));
  return;
}


// ==== FUN_005d9b50 @ 0x005d9b50 ====

void FUN_005d9b50(int param_1)

{
  int iVar1;
  void *_Memory;
  char cVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  uint uVar7;
  
  if (in_ECX == param_1) {
    return;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != 0) {
    iVar6 = *(int *)(param_1 + 8) - iVar1;
    iVar4 = iVar6 >> 0x1f;
    iVar6 = iVar6 / 0xc + iVar4;
    uVar7 = iVar6 - iVar4;
    if (iVar6 != iVar4) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0xc;
      }
      if (uVar7 <= uVar3) {
        FUN_0042ea00(iVar1,*(undefined4 *)(param_1 + 8),_Memory,param_1);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + ((*(int *)(param_1 + 8) - *(int *)(param_1 + 4)) / 0xc) * 0xc;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar3 = 0;
      }
      else {
        uVar3 = (*(int *)(in_ECX + 0xc) - (int)_Memory) / 0xc;
      }
      if (uVar7 <= uVar3) {
        iVar4 = FUN_004a3750();
        iVar1 = iVar1 + iVar4 * 0xc;
        FUN_0042ea00(*(undefined4 *)(param_1 + 4),iVar1,_Memory,param_1);
        uVar5 = FUN_0042eab0(iVar1,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar5;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      uVar5 = FUN_004a3750();
      cVar2 = FUN_00413110(uVar5);
      if (cVar2 == '\0') {
        return;
      }
      uVar5 = FUN_0042edd0(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar5;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_005d9cd0 @ 0x005d9cd0 ====

undefined4 * FUN_005d9cd0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    param_3[3] = param_1[3];
    param_3[4] = param_1[4];
    *(undefined1 *)(param_3 + 5) = *(undefined1 *)(param_1 + 5);
    FUN_005d9b50(param_1 + 6);
    param_1 = param_1 + 10;
    param_3 = param_3 + 10;
  } while (param_1 != param_2);
  return param_3;
}


// ==== FUN_005d9d30 @ 0x005d9d30 ====

void FUN_005d9d30(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  if (param_1 != param_2) {
    puVar1 = (undefined4 *)(param_1 + 0x1c);
    do {
      if ((void *)*puVar1 != (void *)0x0) {
        _free((void *)*puVar1);
        return;
      }
      *puVar1 = 0;
      puVar1[1] = 0;
      puVar1[2] = 0;
      param_1 = param_1 + 0x28;
      puVar1 = puVar1 + 10;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_005d9d70 @ 0x005d9d70 ====

undefined4 * FUN_005d9d70(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == param_2) {
    return param_3;
  }
  do {
    iVar1 = param_2 + -0x28;
    puVar2 = param_3 + -10;
    *puVar2 = *(undefined4 *)(param_2 + -0x28);
    param_3[-9] = *(undefined4 *)(param_2 + -0x24);
    param_3[-8] = *(undefined4 *)(param_2 + -0x20);
    param_3[-7] = *(undefined4 *)(param_2 + -0x1c);
    param_3[-6] = *(undefined4 *)(param_2 + -0x18);
    *(undefined1 *)(param_3 + -5) = *(undefined1 *)(param_2 + -0x14);
    FUN_005d9b50(param_2 + -0x10);
    param_2 = iVar1;
    param_3 = puVar2;
  } while (iVar1 != param_1);
  return puVar2;
}


// ==== FUN_005d9dd0 @ 0x005d9dd0 ====

void FUN_005d9dd0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != param_2) {
    do {
      *param_1 = *param_3;
      param_1[1] = param_3[1];
      param_1[2] = param_3[2];
      param_1[3] = param_3[3];
      param_1[4] = param_3[4];
      *(undefined1 *)(param_1 + 5) = *(undefined1 *)(param_3 + 5);
      FUN_005d9b50(param_3 + 6);
      param_1 = param_1 + 10;
    } while (param_1 != param_2);
  }
  return;
}


// ==== FUN_005d9e20 @ 0x005d9e20 ====

void FUN_005d9e20(undefined4 *param_1,undefined4 *param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = *param_2;
    param_1[1] = param_2[1];
    param_1[2] = param_2[2];
    param_1[3] = param_2[3];
    param_1[4] = param_2[4];
    *(undefined1 *)(param_1 + 5) = *(undefined1 *)(param_2 + 5);
    FUN_00430d30(param_2 + 6);
  }
  return;
}


// ==== FUN_005d9e60 @ 0x005d9e60 ====

int FUN_005d9e60(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982d60;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x28) {
    FUN_005d9e20(param_3,param_1);
    param_3 = param_3 + 0x28;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005d9eca @ 0x005d9eca ====

void Catch_005d9eca(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 0x10);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x28) {
    FUN_005d9b20(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d9ef0 @ 0x005d9ef0 ====

void FUN_005d9ef0(undefined4 param_1,undefined4 param_2)

{
  FUN_005d9d30(param_1,param_2);
  return;
}


// ==== FUN_005d9f10 @ 0x005d9f10 ====

void FUN_005d9f10(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982d70;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005d9e20(param_1,param_3);
    param_1 = param_1 + 0x28;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005d9f7a @ 0x005d9f7a ====

void Catch_005d9f7a(void)

{
  int iVar1;
  int unaff_EBP;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBP + 8);
  for (iVar2 = *(int *)(unaff_EBP + -0x14); iVar2 != iVar1; iVar2 = iVar2 + 0x28) {
    FUN_005d9b20(iVar2);
  }
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005d9fa0 @ 0x005d9fa0 ====

void FUN_005d9fa0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005d9e60(param_1,param_2,param_3);
  return;
}


// ==== FUN_005d9fc0 @ 0x005d9fc0 ====

int FUN_005d9fc0(int param_1,int param_2,undefined4 param_3)

{
  FUN_005d9f10(param_1,param_2,param_3);
  return param_1 + param_2 * 0x28;
}


// ==== FUN_005d9ff0 @ 0x005d9ff0 ====

void FUN_005d9ff0(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint extraout_ECX;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_54;
  void *local_4c;
  undefined4 local_40;
  int local_30;
  int local_2c;
  int local_28;
  uint local_24;
  void *local_1c;
  void *local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982d80;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x74);
  local_68 = *param_3;
  local_64 = param_3[1];
  local_60 = param_3[2];
  local_5c = param_3[3];
  local_58 = param_3[4];
  local_54 = *(undefined1 *)(param_3 + 5);
  ExceptionList = &local_10;
  FUN_00430d30(param_3 + 6);
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x28;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
    }
    if (0x6666666U - iVar1 < param_2) {
      FUN_0085b3b0();
      uVar4 = extraout_ECX;
    }
    if (iVar2 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
    }
    if (uVar4 < iVar1 + param_2) {
      if (0x6666666 - (uVar4 >> 1) < uVar4) {
        uVar4 = 0;
      }
      else {
        uVar4 = uVar4 + (uVar4 >> 1);
      }
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
      }
      if (uVar4 < iVar2 + param_2) {
        iVar2 = FUN_00436560();
        uVar4 = iVar2 + param_2;
      }
      local_24 = uVar4 * 0x28;
      local_1c = operator_new(local_24);
      local_8 = 0;
      local_18 = local_1c;
      local_18 = (void *)FUN_005d9fa0(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_18 = (void *)FUN_005d9fc0(local_18,param_2,&local_68);
      FUN_005d9fa0(param_1,*(undefined4 *)(in_ECX + 8),local_18);
      local_8 = 0xffffffff;
      iVar2 = *(int *)(in_ECX + 4);
      if (iVar2 == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = (*(int *)(in_ECX + 8) - iVar2) / 0x28;
      }
      if (iVar2 != 0) {
        FUN_005d9d30(iVar2,*(undefined4 *)(in_ECX + 8));
        _free(*(void **)(in_ECX + 4));
        return;
      }
      *(uint *)(in_ECX + 0xc) = local_24 + (int)local_1c;
      *(void **)(in_ECX + 8) = (void *)((int)local_1c + (param_2 + iVar1) * 0x28);
      *(void **)(in_ECX + 4) = local_1c;
    }
    else {
      local_2c = *(int *)(in_ECX + 8);
      if ((uint)((local_2c - param_1) / 0x28) < param_2) {
        local_28 = param_2 * 0x28;
        FUN_005d9e60(param_1,local_2c,local_28 + param_1);
        local_8 = 2;
        FUN_005d9fc0(*(int *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x28,
                     &local_68);
        local_8 = 0xffffffff;
        *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_28;
        FUN_005d9dd0(param_1,*(int *)(in_ECX + 8) - local_28,&local_68);
      }
      else {
        local_30 = local_2c + param_2 * -0x28;
        uVar3 = FUN_005d9e60(local_30,local_2c,local_2c);
        *(undefined4 *)(in_ECX + 8) = uVar3;
        FUN_005d9d70(param_1,local_30,local_2c,local_40);
        FUN_005d9dd0(param_1,param_2 * 0x28 + param_1,&local_68);
      }
    }
  }
  if (local_4c == (void *)0x0) {
    ExceptionList = local_10;
    return;
  }
  _free(local_4c);
  return;
}


// ==== Catch@005da1d3 @ 0x005da1d3 ====

void Catch_005da1d3(void)

{
  void *_Memory;
  int unaff_EBP;
  
  _Memory = *(void **)(unaff_EBP + -0x18);
  FUN_005d9ef0(_Memory,*(undefined4 *)(unaff_EBP + -0x14));
  _free(_Memory);
  return;
}


// ==== Catch@005da289 @ 0x005da289 ====

void Catch_005da289(void)

{
  int iVar1;
  int unaff_EBP;
  
  iVar1 = *(int *)(unaff_EBP + 0xc) * 0x28;
  FUN_005d9ef0(iVar1 + *(int *)(unaff_EBP + 8),*(int *)(*(int *)(unaff_EBP + -0x1c) + 8) + iVar1);
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005da320 @ 0x005da320 ====

void FUN_005da320(byte param_1)

{
  void *in_ECX;
  
  FUN_005d9230();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005da340 @ 0x005da340 ====

void FUN_005da340(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x28 != 0) {
      iVar1 = (param_2 - iVar1) / 0x28;
      goto LAB_005da385;
    }
  }
  iVar1 = 0;
LAB_005da385:
  FUN_005d9ff0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x28;
  return;
}


// ==== FUN_005da3b0 @ 0x005da3b0 ====

void FUN_005da3b0(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x28) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x28))) {
    FUN_005da340(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005d9f10(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x28;
  return;
}


// ==== FUN_005da450 @ 0x005da450 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005da450(int *param_1)

{
  int *piVar1;
  float fVar2;
  char cVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int in_ECX;
  int *piVar7;
  float10 fVar8;
  float fVar9;
  int *piStack_c;
  
  if (((*(int *)(in_ECX + 0xc) != 0) &&
      ((*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x3c != 0)) &&
     (cVar3 = (**(code **)(**(int **)(in_ECX + 0x18) + 0x2c))(), cVar3 != '\0')) {
    piVar1 = *(int **)(in_ECX + 0x10);
    cVar3 = **(char **)(*(int *)(in_ECX + 4) + 0xd8);
    piStack_c = *(int **)(in_ECX + 0xc);
    if (piStack_c != piVar1) {
      piVar7 = piStack_c + 2;
      do {
        piVar4 = (int *)(**(code **)(*param_1 + 0xd0))();
        fVar9 = (float)piVar7[-1];
        if (piVar7[-1] < 0) {
          fVar9 = fVar9 + _DAT_0099d104;
        }
        fVar2 = (float)*piStack_c;
        if (*piStack_c < 0) {
          fVar2 = fVar2 + _DAT_0099d104;
        }
        fVar8 = (float10)FUN_0040d4c0(_DAT_00af6120 * (fVar9 / fVar2));
        fVar9 = DAT_009c3038;
        if ((float10)DAT_009c3038 <= (float10)DAT_009be92c - fVar8) {
          fVar9 = (float)((float10)DAT_009be92c - fVar8);
        }
        piVar4[0xd] = (int)fVar9;
        iVar5 = FUN_004b3ff0((char)piVar7[0xc]);
        piVar4[0xc] = iVar5;
        *piVar4 = *piVar7;
        piVar4[1] = piVar7[1];
        piVar4[2] = piVar7[2];
        piVar4[3] = piVar7[3];
        piVar4[4] = piVar7[4];
        piVar4[5] = piVar7[5];
        piVar4[6] = piVar7[6];
        piVar4[7] = piVar7[7];
        piVar4[8] = piVar7[8];
        piVar4[9] = piVar7[9];
        piVar4[10] = piVar7[10];
        piVar4[0xb] = piVar7[0xb];
        if (*(byte *)(piVar7 + 0xc) < 6) {
          piVar4[0xe] = 0;
        }
        if (cVar3 != '\0') {
          piVar6 = (int *)(**(code **)(*param_1 + 0xd0))();
          piVar6[0xe] = piVar4[0xe];
          piVar6[0xd] = piVar4[0xd];
          piVar6[0xc] = piVar4[0xc];
          *piVar6 = *piVar4;
          piVar6[1] = piVar4[1];
          piVar6[2] = piVar4[2];
          piVar6[3] = piVar4[3];
          piVar6[4] = piVar4[4];
          piVar6[5] = piVar4[5];
          piVar6[6] = piVar4[6];
          piVar6[7] = piVar4[7];
          piVar6[8] = piVar4[8];
          piVar6[9] = piVar4[9];
          piVar6[10] = piVar4[10];
          piVar6[0xb] = piVar4[0xb];
          (**(code **)(*param_1 + 0x84))(piVar6);
        }
        (**(code **)(*param_1 + 0x84))(piVar4);
        piStack_c = piStack_c + 0xf;
        piVar7 = piVar7 + 0xf;
      } while (piStack_c != piVar1);
    }
  }
  return;
}


// ==== FUN_005da670 @ 0x005da670 ====

/* WARNING: Removing unreachable block (ram,0x005da6b1) */

void FUN_005da670(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3484;
  if (in_ECX[6] != 0) {
    (**(code **)(*DAT_00b5a7cc + 0x14))(in_ECX[6]);
    in_ECX[6] = 0;
  }
  if ((void *)in_ECX[3] == (void *)0x0) {
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[3] = 0;
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    *in_ECX = &PTR_FUN_009c3380;
    return;
  }
  _free((void *)in_ECX[3]);
  return;
}


// ==== FUN_005da6d0 @ 0x005da6d0 ====

undefined4 FUN_005da6d0(int param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int in_ECX;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint *local_14;
  
  if ((*(int *)(in_ECX + 0xc) == 0) ||
     (iVar5 = (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x3c, iVar5 == 0)) {
    return 1;
  }
  puVar6 = *(uint **)(in_ECX + 0xc);
  local_14 = puVar6;
  if (puVar6 == *(uint **)(in_ECX + 0x10)) {
    return CONCAT31((int3)((uint)iVar5 >> 8),1);
  }
  do {
    puVar6[1] = puVar6[1] + param_1;
    uVar4 = puVar6[1];
    if (*puVar6 < uVar4) {
      puVar1 = *(uint **)(in_ECX + 0x10);
      if (puVar6 + 0xf != puVar1) {
        puVar2 = puVar6 + 0xf;
        do {
          puVar3 = puVar2 + 0xf;
          puVar7 = puVar6;
          for (iVar5 = 0xf; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar7 = *puVar2;
            puVar2 = puVar2 + 1;
            puVar7 = puVar7 + 1;
          }
          puVar2 = puVar3;
          puVar6 = puVar6 + 0xf;
        } while (puVar3 != puVar1);
        puVar6 = local_14;
      }
      *(int *)(in_ECX + 0x10) = *(int *)(in_ECX + 0x10) + -0x3c;
      if ((*(int *)(in_ECX + 0xc) == 0) ||
         (uVar4 = (*(int *)(in_ECX + 0x10) - *(int *)(in_ECX + 0xc)) / 0x3c, uVar4 == 0)) {
        *(undefined4 *)(in_ECX + 0x1c) = 0;
        *(undefined4 *)(in_ECX + 0x20) = 0;
        *(undefined4 *)(in_ECX + 0x24) = 0;
        *(undefined4 *)(in_ECX + 0x28) = 0;
        *(undefined4 *)(in_ECX + 0x2c) = 0;
        *(undefined4 *)(in_ECX + 0x30) = 0;
        *(undefined4 *)(in_ECX + 0x34) = 0;
        *(undefined4 *)(in_ECX + 0x38) = 0;
        *(undefined4 *)(in_ECX + 0x3c) = 0;
        *(undefined4 *)(in_ECX + 0x40) = 0;
        uVar4 = 0;
        *(undefined4 *)(in_ECX + 0x44) = 0;
        *(undefined4 *)(in_ECX + 0x48) = 0;
      }
    }
    else {
      puVar6 = puVar6 + 0xf;
      local_14 = puVar6;
    }
  } while (puVar6 != *(uint **)(in_ECX + 0x10));
  return CONCAT31((int3)(uVar4 >> 8),1);
}


// ==== FUN_005da860 @ 0x005da860 ====

void FUN_005da860(undefined4 param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  uint local_4;
  
  *in_ECX = &PTR_FUN_009c3484;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  in_ECX[5] = 0;
  in_ECX[1] = param_1;
  local_4 = 0xf;
  local_8 = 0;
  local_18 = (void *)((uint)local_18 & 0xffffff00);
  FUN_00401740(s_effect_hit_eff_swordtrace_tpack_009c345c,0x1f);
  uVar1 = FUN_005aa220(local_1c);
  in_ECX[6] = uVar1;
  if (0xf < local_4) {
    _free(local_18);
    return;
  }
  iVar3 = 4;
  puVar2 = in_ECX + 7;
  do {
    *puVar2 = 0;
    puVar2[1] = 0;
    iVar3 = iVar3 + -1;
    puVar2[2] = 0;
    puVar2 = puVar2 + 3;
  } while (iVar3 != 0);
  return;
}


// ==== FUN_005da910 @ 0x005da910 ====

void FUN_005da910(float *param_1,float *param_2,float *param_3,float *param_4,char param_5)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  float fVar3;
  float local_9c;
  float local_98;
  float local_94;
  float local_90;
  float local_8c;
  float local_88;
  float local_84;
  float fStack_80;
  float fStack_7c;
  int local_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float local_5c;
  int iStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  undefined1 uStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fVar3 = *(float *)(*(int *)(*(int *)(in_ECX + 4) + 0xd8) + 0x10);
  local_5c = SQRT((param_2[1] - param_1[1]) * (param_2[1] - param_1[1]) +
                  (*param_2 - *param_1) * (*param_2 - *param_1) +
                  (param_2[2] - param_1[2]) * (param_2[2] - param_1[2]));
  local_78 = in_ECX;
  if (fVar3 <= DAT_0099d080) {
    local_90 = *param_1;
    local_8c = param_1[1];
    local_88 = param_1[2];
  }
  else {
    local_9c = *param_1 - *param_2;
    local_98 = param_1[1] - param_2[1];
    local_94 = param_1[2] - param_2[2];
    thunk_FUN_0079e1ba(&local_84,&local_9c);
    local_5c = local_5c * fVar3;
    local_9c = *param_2 + local_84 * local_5c;
    local_98 = param_2[1] + fStack_80 * local_5c;
    local_94 = param_2[2] + fStack_7c * local_5c;
    local_90 = local_9c;
    local_8c = local_98;
    local_88 = local_94;
  }
  if (((*param_3 == 0.0) && (param_3[1] == 0.0)) && (param_3[2] == 0.0)) {
    *param_3 = local_90;
    param_3[1] = local_8c;
    param_3[2] = local_88;
    *param_4 = *param_2;
    param_4[1] = param_2[1];
    param_4[2] = param_2[2];
  }
  fVar3 = SQRT((*param_1 - *param_3) * (*param_1 - *param_3) +
               (param_1[1] - param_3[1]) * (param_1[1] - param_3[1]) +
               (param_1[2] - param_3[2]) * (param_1[2] - param_3[2]));
  if (DAT_009c3038 < fVar3) {
    if (fVar3 < DAT_009b0ec8) {
      iVar2 = *(int *)(*(int *)(local_78 + 4) + 0xd8);
      iStack_58 = (int)(fVar3 + DAT_0099d0b4);
      if (param_5 == '\0') {
        uStack_1c = *(undefined1 *)(iVar2 + 3);
      }
      else {
        uStack_1c = *(undefined1 *)(iVar2 + 2);
      }
      fStack_68 = *param_3;
      fStack_64 = param_3[1];
      fStack_60 = param_3[2];
      local_84 = *param_4;
      fStack_80 = param_4[1];
      fStack_7c = param_4[2];
      iVar2 = 1;
      uStack_54 = 300;
      uStack_50 = 0;
      if (0 < iStack_58) {
        iVar1 = iStack_58 + 1;
        do {
          fVar3 = (float)iVar2 / (float)iVar1;
          fStack_74 = (*param_2 - *param_4) * fVar3 + *param_4;
          fStack_70 = (param_2[1] - param_4[1]) * fVar3 + param_4[1];
          fStack_6c = (param_2[2] - param_4[2]) * fVar3 + param_4[2];
          fStack_c = ((local_90 - *param_3) * fVar3 + *param_3) - fStack_74;
          fStack_8 = ((local_8c - param_3[1]) * fVar3 + param_3[1]) - fStack_70;
          fStack_4 = ((local_88 - param_3[2]) * fVar3 + param_3[2]) - fStack_6c;
          thunk_FUN_0079e1ba(&fStack_18,&fStack_c);
          fStack_4c = fStack_68;
          fStack_40 = local_84;
          local_9c = fStack_18 * local_5c + fStack_74;
          fStack_48 = fStack_64;
          fStack_44 = fStack_60;
          local_98 = fStack_14 * local_5c + fStack_70;
          local_94 = fStack_10 * local_5c + fStack_6c;
          fStack_28 = fStack_74;
          fStack_3c = fStack_80;
          fStack_38 = fStack_7c;
          fStack_24 = fStack_70;
          fStack_20 = fStack_6c;
          fStack_34 = local_9c;
          fStack_30 = local_98;
          fStack_2c = local_94;
          FUN_005db330(&uStack_54);
          fStack_68 = local_9c;
          fStack_64 = local_98;
          fStack_60 = local_94;
          iVar2 = iVar2 + 1;
          local_84 = fStack_74;
          fStack_80 = fStack_70;
          fStack_7c = fStack_6c;
        } while (iVar2 <= iStack_58);
      }
      fStack_4c = fStack_68;
      fStack_48 = fStack_64;
      fStack_40 = local_84;
      fStack_44 = fStack_60;
      fStack_3c = fStack_80;
      fStack_34 = local_90;
      fStack_38 = fStack_7c;
      fStack_30 = local_8c;
      fStack_2c = local_88;
      fStack_28 = *param_2;
      fStack_24 = param_2[1];
      fStack_20 = param_2[2];
      FUN_005db330(&uStack_54);
    }
    *param_3 = local_90;
    param_3[1] = local_8c;
    param_3[2] = local_88;
    *param_4 = *param_2;
    param_4[1] = param_2[1];
    param_4[2] = param_2[2];
  }
  return;
}


// ==== FUN_005dae20 @ 0x005dae20 ====

void FUN_005dae20(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_005da910(param_1,param_2,in_ECX + 0x1c,in_ECX + 0x28,1);
  return;
}


// ==== FUN_005dae40 @ 0x005dae40 ====

void FUN_005dae40(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  FUN_005da910(param_1,param_2,in_ECX + 0x34,in_ECX + 0x40,0);
  return;
}


// ==== FUN_005dae60 @ 0x005dae60 ====

void FUN_005dae60(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
    }
  }
  return;
}


// ==== FUN_005dae80 @ 0x005dae80 ====

int FUN_005dae80(int param_1,int param_2,int param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982d90;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_1 != param_2; param_1 = param_1 + 0x3c) {
    FUN_005dae60(param_3,param_1);
    param_3 = param_3 + 0x3c;
  }
  ExceptionList = local_10;
  return param_3;
}


// ==== Catch@005daee6 @ 0x005daee6 ====

void Catch_005daee6(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005daef0 @ 0x005daef0 ====

void FUN_005daef0(int param_1,int param_2,undefined4 param_3)

{
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00982da0;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_005dae60(param_1,param_3);
    param_1 = param_1 + 0x3c;
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005daf56 @ 0x005daf56 ====

void Catch_005daf56(void)

{
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(0,0);
}


// ==== FUN_005daf60 @ 0x005daf60 ====

void FUN_005daf60(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005dae80(param_1,param_2,param_3);
  return;
}


// ==== FUN_005daf80 @ 0x005daf80 ====

int FUN_005daf80(int param_1,int param_2,undefined4 param_3)

{
  FUN_005daef0(param_1,param_2,param_3);
  return param_1 + param_2 * 0x3c;
}


// ==== FUN_005dafb0 @ 0x005dafb0 ====

void FUN_005dafb0(byte param_1)

{
  void *in_ECX;
  
  FUN_005da670();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005dafd0 @ 0x005dafd0 ====

void FUN_005dafd0(int param_1,uint param_2,undefined4 *param_3)

{
  void *_Memory;
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  uint extraout_ECX;
  undefined4 *puVar3;
  undefined4 local_70;
  int local_2c;
  int local_28;
  uint local_24;
  undefined4 local_20;
  void *local_1c;
  int local_18;
  undefined1 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00982db0;
  local_10 = ExceptionList;
  local_14 = (undefined1 *)((int)register0x00000010 + -0x7c);
  puVar3 = &local_70;
  for (iVar2 = 0xf; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_3;
    param_3 = param_3 + 1;
    puVar3 = puVar3 + 1;
  }
  iVar2 = *(int *)(in_ECX + 4);
  if (iVar2 == 0) {
    local_24 = 0;
  }
  else {
    local_24 = (*(int *)(in_ECX + 0xc) - iVar2) / 0x3c;
  }
  if (param_2 != 0) {
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
    }
    ExceptionList = &local_10;
    if (0x4444444U - iVar2 < param_2) {
      ExceptionList = &local_10;
      FUN_0085b3b0();
      local_24 = extraout_ECX;
    }
    if (*(int *)(in_ECX + 4) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
    }
    if (local_24 < iVar2 + param_2) {
      if (0x4444444 - (local_24 >> 1) < local_24) {
        local_24 = 0;
      }
      else {
        local_24 = local_24 + (local_24 >> 1);
      }
      if (*(int *)(in_ECX + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - *(int *)(in_ECX + 4)) / 0x3c;
      }
      if (local_24 < iVar2 + param_2) {
        iVar2 = FUN_004297e0();
        local_24 = iVar2 + param_2;
      }
      local_24 = local_24 * 0x3c;
      local_1c = operator_new(local_24);
      local_8 = 0;
      local_20 = FUN_005daf60(*(undefined4 *)(in_ECX + 4),param_1,local_1c);
      local_20 = FUN_005daf80(local_20,param_2,&local_70);
      FUN_005daf60(param_1,*(undefined4 *)(in_ECX + 8),local_20);
      local_8 = 0xffffffff;
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = (*(int *)(in_ECX + 8) - (int)_Memory) / 0x3c;
      }
      if (_Memory == (void *)0x0) {
        *(uint *)(in_ECX + 0xc) = local_24 + (int)local_1c;
        *(void **)(in_ECX + 8) = (void *)((int)local_1c + (param_2 + iVar2) * 0x3c);
        *(void **)(in_ECX + 4) = local_1c;
        ExceptionList = local_10;
        return;
      }
      _free(_Memory);
      return;
    }
    local_2c = *(int *)(in_ECX + 8);
    local_28 = local_2c - param_1;
    if ((uint)(local_28 / 0x3c) < param_2) {
      local_18 = param_2 * 0x3c;
      FUN_005dae80(param_1,local_2c,local_18 + param_1);
      local_8 = 2;
      FUN_005daf80(*(undefined4 *)(in_ECX + 8),param_2 - (*(int *)(in_ECX + 8) - param_1) / 0x3c,
                   &local_70);
      local_8 = 0xffffffff;
      *(int *)(in_ECX + 8) = *(int *)(in_ECX + 8) + local_18;
      FUN_00427640(param_1,*(int *)(in_ECX + 8) - local_18,&local_70);
      ExceptionList = local_10;
      return;
    }
    local_18 = param_2 * 0x3c;
    iVar2 = local_2c + param_2 * -0x3c;
    uVar1 = FUN_005dae80(iVar2,local_2c,local_2c);
    *(undefined4 *)(in_ECX + 8) = uVar1;
    FUN_00427bc0(param_1,iVar2,local_2c);
    FUN_00427640(param_1,local_18 + param_1,&local_70);
  }
  ExceptionList = local_10;
  return;
}


// ==== Catch@005db18f @ 0x005db18f ====

void Catch_005db18f(void)

{
  int unaff_EBP;
  
  _free(*(void **)(unaff_EBP + -0x18));
  return;
}


// ==== FUN_005db2b0 @ 0x005db2b0 ====

void FUN_005db2b0(int *param_1,int param_2,undefined4 param_3)

{
  int in_ECX;
  int iVar1;
  
  iVar1 = *(int *)(in_ECX + 4);
  if (iVar1 != 0) {
    if ((*(int *)(in_ECX + 8) - iVar1) / 0x3c != 0) {
      iVar1 = (param_2 - iVar1) / 0x3c;
      goto LAB_005db2f9;
    }
  }
  iVar1 = 0;
LAB_005db2f9:
  FUN_005dafd0(param_2,1,param_3);
  *param_1 = *(int *)(in_ECX + 4) + iVar1 * 0x3c;
  return;
}


// ==== FUN_005db330 @ 0x005db330 ====

void FUN_005db330(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 4);
  if ((iVar1 == 0) ||
     ((uint)((*(int *)(in_ECX + 0xc) - iVar1) / 0x3c) <=
      (uint)((*(int *)(in_ECX + 8) - iVar1) / 0x3c))) {
    FUN_005db2b0(&param_1,*(undefined4 *)(in_ECX + 8),param_1);
    return;
  }
  iVar1 = *(int *)(in_ECX + 8);
  FUN_005daef0(iVar1,1,param_1);
  *(int *)(in_ECX + 8) = iVar1 + 0x3c;
  return;
}


// ==== FUN_005db3c0 @ 0x005db3c0 ====

void FUN_005db3c0(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int in_ECX;
  float fVar9;
  
  fVar1 = *(float *)(in_ECX + 0xb4);
  fVar9 = *(float *)(in_ECX + 0xb0) * DAT_009b0ec8;
  fVar2 = *(float *)(in_ECX + 0x10);
  fVar3 = *(float *)(in_ECX + 0xbc);
  fVar4 = *(float *)(in_ECX + 0x10);
  fVar5 = *(float *)(in_ECX + 0xb4);
  fVar6 = *(float *)(in_ECX + 0x10);
  fVar7 = *(float *)(in_ECX + 0xc);
  fVar8 = *(float *)(in_ECX + 8);
  *param_1 = *(float *)(in_ECX + 4) + *(float *)(in_ECX + 0xb8) * *(float *)(in_ECX + 0x10);
  param_1[1] = fVar8 + ((fVar9 / fVar5) * fVar6 - (fVar9 / (fVar1 * fVar1)) * fVar2 * fVar2);
  param_1[2] = fVar7 + fVar3 * fVar4;
  return;
}


// ==== FUN_005db470 @ 0x005db470 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005db470(void)

{
  int in_ECX;
  float10 fVar1;
  float fVar2;
  float local_4;
  
  if (*(char *)(in_ECX + 0x68) == '\0') {
    return (float10)*(float *)(in_ECX + 0x24);
  }
  if (DAT_0099cdc8 < *(float *)(in_ECX + 0x130)) {
    fVar2 = *(float *)(in_ECX + 0x10) / *(float *)(in_ECX + 0xb4);
    local_4 = DAT_0099d080;
    if (fVar2 <= DAT_0099d080) {
      local_4 = fVar2;
    }
    return (float10)*(float *)(in_ECX + 0x130) * (float10)_DAT_009a4474 * (float10)local_4;
  }
  fVar1 = (float10)*(int *)(in_ECX + 0x14);
  if (*(int *)(in_ECX + 0x14) < 0) {
    fVar1 = fVar1 + (float10)_DAT_0099d104;
  }
  return fVar1 * (float10)*(float *)(in_ECX + 0x130) * (float10)_DAT_009a4474 *
         (float10)DAT_0099d0ec;
}


// ==== FUN_005db520 @ 0x005db520 ====

void FUN_005db520(void)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x68) = 0;
  *(undefined1 *)(in_ECX + 0x69) = 0;
  return;
}


// ==== FUN_005db530 @ 0x005db530 ====

void FUN_005db530(void)

{
  return;
}


// ==== FUN_005db570 @ 0x005db570 ====

void FUN_005db570(undefined4 param_1,float *param_2)

{
  int iVar1;
  float unaff_ESI;
  float *pfVar2;
  float unaff_EDI;
  float fVar3;
  float unaff_retaddr;
  float local_58;
  float local_54;
  float local_50;
  float afStack_48 [4];
  float local_38;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float *pfStack_4;
  
  afStack_48[2] = (param_2[3] - *param_2) * DAT_0099d0b4 + *param_2;
  afStack_48[3] = (param_2[4] - param_2[1]) * DAT_0099d0b4 + param_2[1];
  local_38 = (param_2[5] - param_2[2]) * DAT_0099d0b4 + param_2[2];
  local_58 = param_2[3] - *param_2;
  local_54 = param_2[4] - param_2[1];
  local_50 = param_2[5] - param_2[2];
  thunk_FUN_0079e1ba(&local_58,&local_58);
  fVar3 = unaff_retaddr * DAT_0099d0b4;
  fStack_14 = unaff_ESI * fVar3;
  fStack_10 = local_58 * fVar3;
  fStack_18 = unaff_EDI * fVar3;
  pfVar2 = afStack_48;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfStack_4 = *pfVar2;
    pfVar2 = pfVar2 + 1;
    pfStack_4 = pfStack_4 + 1;
  }
  return;
}


// ==== FUN_005db6b0 @ 0x005db6b0 ====

void FUN_005db6b0(void)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_150;
  undefined4 local_14c [14];
  undefined1 auStack_114 [12];
  undefined1 auStack_108 [52];
  undefined4 auStack_d4 [19];
  undefined1 auStack_88 [8];
  undefined1 local_80 [32];
  undefined4 auStack_60 [3];
  undefined1 auStack_54 [56];
  undefined4 *puStack_1c;
  
  iVar1 = *(int *)(in_ECX + 0x6c);
  local_150 = *(undefined4 *)(iVar1 + 0x1c);
  local_14c[0] = *(undefined4 *)(iVar1 + 0x20);
  local_14c[1] = *(undefined4 *)(iVar1 + 0x24);
  local_14c[2] = *(undefined4 *)(iVar1 + 0x28);
  thunk_FUN_0079fb96(local_80,&local_150);
  iVar1 = *(int *)(in_ECX + 0x6c);
  thunk_FUN_0079f7f5(auStack_108,*(undefined4 *)(iVar1 + 0x10),*(undefined4 *)(iVar1 + 0x14),
                     *(undefined4 *)(iVar1 + 0x18));
  thunk_FUN_0079ee7b(local_14c + 1,in_ECX + 0x28,auStack_88);
  puVar2 = local_14c + -2;
  puVar3 = auStack_d4;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  thunk_FUN_0079ee7b(auStack_54,auStack_d4,auStack_114);
  puVar2 = auStack_60;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puStack_1c = *puVar2;
    puVar2 = puVar2 + 1;
    puStack_1c = puStack_1c + 1;
  }
  return;
}


// ==== FUN_005db770 @ 0x005db770 ====

void FUN_005db770(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  float local_24c;
  float local_248;
  float local_244;
  undefined1 local_240 [52];
  undefined4 auStack_20c [13];
  undefined4 auStack_1d8 [3];
  undefined1 auStack_1cc [64];
  undefined4 auStack_18c [3];
  undefined1 local_180 [40];
  undefined1 auStack_158 [24];
  undefined1 local_140 [64];
  undefined1 local_100 [40];
  undefined4 auStack_d8 [22];
  undefined1 local_80 [40];
  undefined1 auStack_58 [24];
  undefined4 auStack_40 [16];
  
  if (*(char *)(in_ECX + 0x68) == '\0') {
    puVar2 = (undefined4 *)(in_ECX + 0x28);
  }
  else {
    local_24c = -*(float *)(in_ECX + 0x118);
    local_248 = -*(float *)(in_ECX + 0x11c);
    local_244 = -*(float *)(in_ECX + 0x120);
    thunk_FUN_0079f7f5(local_100,local_24c,local_248,local_244);
    thunk_FUN_0079f7f5(local_240,*(undefined4 *)(in_ECX + 0x118),*(undefined4 *)(in_ECX + 0x11c),
                       *(undefined4 *)(in_ECX + 0x120));
    thunk_FUN_0079fa6c(local_80,in_ECX + 0x124,*(undefined4 *)(in_ECX + 0x24));
    thunk_FUN_0079f7f5(local_140,*(undefined4 *)(in_ECX + 0x18),*(undefined4 *)(in_ECX + 0x1c),
                       *(undefined4 *)(in_ECX + 0x20));
    thunk_FUN_0079ee7b(local_180,local_100,local_80);
    puVar2 = auStack_18c;
    puVar3 = auStack_20c;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    thunk_FUN_0079ee7b(auStack_1cc,auStack_20c,&local_24c);
    puVar2 = auStack_1d8;
    puVar3 = auStack_d8;
    for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    thunk_FUN_0079ee7b(auStack_58,auStack_d8,auStack_158);
    puVar2 = auStack_40;
  }
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_005db8c0 @ 0x005db8c0 ====

void FUN_005db8c0(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int in_ECX;
  undefined4 local_6c;
  undefined4 local_68;
  float local_64;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  undefined1 auStack_48 [8];
  undefined1 local_40 [48];
  float *pfStack_10;
  
  iVar1 = *(int *)(in_ECX + 0x6c);
  local_5c = *(float *)(in_ECX + 0x18) +
             (*(float *)(in_ECX + 0xc0) + *(float *)(in_ECX + 0xcc)) * DAT_0099d0b4;
  local_58 = *(float *)(in_ECX + 0x1c) +
             (*(float *)(in_ECX + 0xc4) + *(float *)(in_ECX + 0xd0)) * DAT_0099d0b4;
  local_54 = *(float *)(in_ECX + 0x20) +
             (*(float *)(in_ECX + 200) + *(float *)(in_ECX + 0xd4)) * DAT_0099d0b4;
  local_6c = *(undefined4 *)(iVar1 + 0x1c);
  local_68 = *(undefined4 *)(iVar1 + 0x20);
  local_64 = *(float *)(iVar1 + 0x24);
  local_60 = *(float *)(iVar1 + 0x28);
  thunk_FUN_0079fb96(local_40,&local_6c);
  thunk_FUN_0079e43e(&local_58,&local_64,auStack_48);
  iVar1 = *(int *)(in_ECX + 0x6c);
  fVar2 = *(float *)(iVar1 + 0x14);
  fVar3 = *(float *)(iVar1 + 0x18);
  *pfStack_10 = *(float *)(iVar1 + 0x10) + local_64;
  pfStack_10[1] = fVar2 + local_60;
  pfStack_10[2] = fVar3 + local_5c;
  return;
}


// ==== FUN_005db9e0 @ 0x005db9e0 ====

float10 FUN_005db9e0(void)

{
  int in_ECX;
  float10 fVar1;
  int iStack_64;
  undefined1 *puStack_60;
  float fStack_58;
  float fStack_50;
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  puStack_60 = local_40;
  iStack_64 = 0x5db9f0;
  puStack_60 = (undefined1 *)FUN_005db6b0();
  iStack_64 = in_ECX + 0xd8;
  thunk_FUN_0079e5a0(local_4c);
  puStack_60 = (undefined1 *)fStack_50;
  fVar1 = (float10)(**(code **)(*DAT_00b5a6b4 + 0x14))(&iStack_64);
  if ((float)puStack_60 < (float)fVar1) {
    return ABS((float10)(float)fVar1 -
               ((float10)fStack_58 - (float10)*(float *)(in_ECX + 0x138) * (float10)DAT_009b2dbc));
  }
  return (float10)DAT_0099cdc8;
}


// ==== FUN_005dba80 @ 0x005dba80 ====

undefined4 FUN_005dba80(void)

{
  int in_ECX;
  float10 extraout_ST0;
  undefined1 *puVar1;
  undefined1 *puStack_60;
  float fStack_54;
  undefined1 local_4c [12];
  undefined1 local_40 [64];
  
  puStack_60 = local_40;
  FUN_005db6b0();
  puStack_60 = local_40;
  puStack_60 = (undefined1 *)FUN_005db6b0();
  puVar1 = local_4c;
  thunk_FUN_0079e5a0(puVar1,in_ECX + 0xd8);
  (**(code **)(*DAT_00b5a6b4 + 0x14))(&puStack_60,puVar1,fStack_54 - *(float *)(in_ECX + 0x138));
  if ((float10)(float)puVar1 < extraout_ST0) {
    return 1;
  }
  return 0;
}


// ==== FUN_005dbb00 @ 0x005dbb00 ====

void FUN_005dbb00(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined1 auStack_8c [12];
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_44;
  undefined1 local_40 [56];
  int *piStack_8;
  
  local_44 = 0xf0f0f0f0;
  uVar1 = FUN_005db6b0(local_40);
  thunk_FUN_0079e5a0(&local_80,in_ECX + 0xd8,uVar1);
  uStack_5c = *(undefined4 *)(in_ECX + 0x108);
  uStack_58 = *(undefined4 *)(in_ECX + 0x10c);
  uStack_54 = *(undefined4 *)(in_ECX + 0x110);
  uStack_7c = 0;
  uStack_78 = 0;
  local_80 = DAT_0099d080;
  uStack_70 = DAT_0099d080;
  uStack_6c = 0;
  uStack_74 = 0;
  uStack_64 = 0;
  uStack_60 = DAT_0099d080;
  uStack_68 = 0;
  (**(code **)(*piStack_8 + 0x94))(auStack_8c);
  return;
}


// ==== FUN_005dc4c0 @ 0x005dc4c0 ====

void FUN_005dc4c0(float *param_1,int param_2)

{
  float fVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float local_18;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  local_14 = DAT_0099d0f0;
  local_18 = DAT_0099d0f0;
  local_8 = DAT_0099d0e8;
  local_c = DAT_0099d0e8;
  pfVar2 = *(float **)(param_2 + 4);
  local_10 = DAT_0099d0f0;
  local_4 = DAT_0099d0e8;
  if (pfVar2 != *(float **)(param_2 + 8)) {
    fVar3 = DAT_0099d0e8;
    fVar4 = DAT_0099d0e8;
    fVar5 = DAT_0099d0e8;
    fVar6 = DAT_0099d0f0;
    fVar7 = DAT_0099d0f0;
    fVar8 = DAT_0099d0f0;
    do {
      if (*pfVar2 <= fVar8 && fVar8 != *pfVar2) {
        fVar8 = *pfVar2;
        local_18 = fVar8;
      }
      if (pfVar2[1] <= fVar7 && fVar7 != pfVar2[1]) {
        fVar7 = pfVar2[1];
        local_14 = fVar7;
      }
      if (pfVar2[2] <= fVar6 && fVar6 != pfVar2[2]) {
        fVar6 = pfVar2[2];
        local_10 = fVar6;
      }
      fVar1 = *pfVar2;
      if (fVar5 < fVar1) {
        fVar5 = fVar1;
        local_c = fVar1;
      }
      fVar1 = pfVar2[1];
      if (fVar4 < fVar1) {
        fVar4 = fVar1;
        local_8 = fVar1;
      }
      fVar1 = pfVar2[2];
      if (fVar3 < fVar1) {
        fVar3 = fVar1;
        local_4 = fVar1;
      }
      pfVar2 = pfVar2 + 3;
    } while (pfVar2 != *(float **)(param_2 + 8));
  }
  *param_1 = local_18;
  param_1[1] = local_14;
  param_1[2] = local_10;
  param_1[3] = local_c;
  param_1[4] = local_8;
  param_1[5] = local_4;
  return;
}


// ==== FUN_005dc610 @ 0x005dc610 ====

void FUN_005dc610(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  float local_8;
  
  uVar1 = *(undefined4 *)(in_ECX + 0xd8);
  local_8 = *(float *)(in_ECX + 0xdc);
  uVar2 = *(undefined4 *)(in_ECX + 0xe0);
  iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),&DAT_009c34e0,3);
  if (iVar3 == 0) {
    local_8 = SQRT(*(float *)(in_ECX + 0x110) * *(float *)(in_ECX + 0x110) +
                   *(float *)(in_ECX + 0x10c) * *(float *)(in_ECX + 0x10c) +
                   *(float *)(in_ECX + 0x108) * *(float *)(in_ECX + 0x108)) +
              *(float *)(in_ECX + 0xdc);
  }
  else {
    iVar3 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),s_bottom_009c34e4,6);
    if (iVar3 == 0) {
      local_8 = *(float *)(in_ECX + 0xdc) -
                SQRT(*(float *)(in_ECX + 0x110) * *(float *)(in_ECX + 0x110) +
                     *(float *)(in_ECX + 0x10c) * *(float *)(in_ECX + 0x10c) +
                     *(float *)(in_ECX + 0x108) * *(float *)(in_ECX + 0x108));
    }
  }
  *param_1 = uVar1;
  param_1[1] = local_8;
  param_1[2] = uVar2;
  return;
}


// ==== FUN_005dc6f0 @ 0x005dc6f0 ====

void FUN_005dc6f0(undefined4 *param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),&DAT_009c34ec,2);
  if (iVar2 == 0) {
    local_c = DAT_0099d080;
  }
  else {
    iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),&DAT_009c34f0,2);
    if (iVar2 != 0) {
      iVar2 = FUN_00403620(0,*(undefined4 *)(param_2 + 0x14),&DAT_009c34f4,2);
      if (iVar2 == 0) {
        local_c = 0;
        local_8 = DAT_0099d080;
        local_4 = 0;
      }
      else {
        cVar1 = FUN_004036a0(param_2,&DAT_009c34f8);
        if (cVar1 == '\0') {
          cVar1 = FUN_004036a0(param_2,&DAT_009c34fc);
          if (cVar1 == '\0') {
            cVar1 = FUN_004036a0(param_2,&DAT_009c3500);
            if (cVar1 != '\0') {
              local_c = 0;
              local_8 = 0;
              local_4 = DAT_0099d0dc;
            }
          }
          else {
            local_c = 0;
            local_8 = 0;
            local_4 = DAT_0099d080;
          }
        }
        else {
          local_c = 0;
          local_8 = DAT_0099d0dc;
          local_4 = 0;
        }
      }
      goto LAB_005dc805;
    }
    local_c = DAT_0099d0dc;
  }
  local_8 = 0;
  local_4 = 0;
LAB_005dc805:
  *param_1 = local_c;
  param_1[1] = local_8;
  param_1[2] = local_4;
  return;
}


// ==== FUN_005dc830 @ 0x005dc830 ====

void FUN_005dc830(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *in_ECX;
  undefined4 *puVar4;
  
  puVar1 = (undefined4 *)in_ECX[0x58];
  puVar4 = (undefined4 *)in_ECX[0x57];
  *in_ECX = &PTR_FUN_009c3568;
  if (puVar4 != puVar1) {
    do {
      piVar3 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
      (**(code **)(*piVar3 + 8))(s___Doll_Human_SplitMesh_cpp_009c34a0,0x17,0,*puVar4);
      puVar4 = puVar4 + 1;
    } while (puVar4 != puVar1);
  }
  piVar2 = (int *)in_ECX[0x25];
  for (piVar3 = (int *)in_ECX[0x24]; piVar3 != piVar2; piVar3 = piVar3 + 1) {
    if (*piVar3 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*piVar3);
    }
  }
  if ((void *)in_ECX[0x24] != (void *)0x0) {
    _free((void *)in_ECX[0x24]);
    return;
  }
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  piVar2 = (int *)in_ECX[0x29];
  for (piVar3 = (int *)in_ECX[0x28]; piVar3 != piVar2; piVar3 = piVar3 + 1) {
    if (*piVar3 != 0) {
      (**(code **)(*DAT_00b5a7cc + 0x14))(*piVar3);
    }
  }
  if ((void *)in_ECX[0x28] != (void *)0x0) {
    _free((void *)in_ECX[0x28]);
    return;
  }
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  if ((void *)in_ECX[0x57] != (void *)0x0) {
    _free((void *)in_ECX[0x57]);
    return;
  }
  in_ECX[0x57] = 0;
  in_ECX[0x58] = 0;
  in_ECX[0x59] = 0;
  if ((void *)in_ECX[0x28] != (void *)0x0) {
    _free((void *)in_ECX[0x28]);
    return;
  }
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  if ((void *)in_ECX[0x24] != (void *)0x0) {
    _free((void *)in_ECX[0x24]);
    return;
  }
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  if ((uint)in_ECX[0x22] < 0x10) {
    in_ECX[0x21] = 0;
    in_ECX[0x22] = 0xf;
    *(undefined1 *)(in_ECX + 0x1d) = 0;
    return;
  }
  _free((void *)in_ECX[0x1d]);
  return;
}


// ==== FUN_005dc9b0 @ 0x005dc9b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005dc9b0(undefined4 *param_1,undefined4 param_2)

{
  code *pcVar1;
  float *pfVar2;
  float *pfVar3;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28 [2];
  float local_20;
  undefined1 local_1c [4];
  void *local_18;
  undefined4 local_8;
  undefined4 *local_4;
  
  FUN_0040ecc0(local_28);
  pfVar3 = &local_38;
  pfVar2 = &local_38;
  local_30 = local_28[0] * DAT_009b02a8;
  local_20 = local_20 * DAT_009b02a8;
  switch(param_2) {
  case 0:
    *param_1 = 0;
    param_1[1] = 0;
    return;
  case 1:
    local_30 = local_30 + _DAT_009c356c;
    local_2c = local_20 + DAT_0099d0b4;
    break;
  case 2:
    local_30 = local_30 + DAT_0099d0b4;
    local_2c = local_20 + _DAT_009c356c;
    break;
  case 3:
    local_2c = local_20 + DAT_0099d080;
    break;
  case 4:
    local_30 = local_30 - DAT_0099d0b4;
    local_2c = local_20 + _DAT_009c356c;
    break;
  case 5:
    local_30 = local_30 - _DAT_009c356c;
    local_2c = local_20 + DAT_0099d0b4;
    break;
  default:
    local_4 = (undefined4 *)0xf;
    local_8 = 0;
    local_18 = (void *)((uint)local_18 & 0xffffff00);
    FUN_00401740(&DAT_009c34d4,1);
    FUN_00406880(local_1c);
    if (local_4 < 0x10) {
      local_4 = (undefined4 *)0xf;
      local_8 = 0;
      local_18 = (void *)((uint)local_18 & 0xffffff00);
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    _free(local_18);
    return;
  }
  local_38 = local_30;
  local_34 = local_2c;
  thunk_FUN_0079de77();
  *local_4 = pfVar2;
  local_4[1] = pfVar3;
  return;
}


// ==== FUN_005dcb80 @ 0x005dcb80 ====

void FUN_005dcb80(undefined4 param_1,byte param_2)

{
  undefined4 uVar1;
  undefined4 *in_ECX;
  
  in_ECX[0x1b] = param_1;
  *in_ECX = &PTR_FUN_009c3568;
  in_ECX[0x21] = 0;
  uVar1 = DAT_0099d080;
  in_ECX[0x22] = 0xf;
  *(undefined1 *)(in_ECX + 0x1d) = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x57] = 0;
  in_ECX[0x58] = 0;
  in_ECX[0x59] = 0;
  in_ECX[0x55] = uVar1;
  *(byte *)(in_ECX + 0x51) = ~-(6 < param_2) & param_2;
  return;
}


// ==== FUN_005dcc10 @ 0x005dcc10 ====

undefined4 * FUN_005dcc10(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  void *_Memory;
  undefined4 uVar3;
  char cVar4;
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  undefined4 *extraout_EAX_01;
  int *piVar5;
  undefined1 local_2c [4];
  void *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined1 auStack_1c [4];
  void *pvStack_18;
  undefined4 uStack_8;
  uint uStack_4;
  
  piVar1 = *(int **)(param_2 + 8);
  piVar5 = *(int **)(param_2 + 4);
  local_28 = (void *)0x0;
  local_24 = 0;
  local_20 = 0;
  _Memory = local_28;
  while( true ) {
    local_28 = _Memory;
    if (piVar5 == piVar1) {
      FUN_005dc4c0(param_1,local_2c);
      if (_Memory == (void *)0x0) {
        return param_1;
      }
      _free(_Memory);
      return extraout_EAX_00;
    }
    piVar2 = (int *)*piVar5;
    if ((piVar2 == (int *)0x0) || (cVar4 = (**(code **)(*piVar2 + 0x2c))(), cVar4 == '\0')) break;
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    FUN_00401740(s_EXBOX_009c34d8,5);
    FUN_0069a470(&param_2,auStack_1c);
    if (0xf < uStack_4) {
      _free(pvStack_18);
      return extraout_EAX;
    }
    uStack_4 = 0xf;
    uStack_8 = 0;
    pvStack_18 = (void *)((uint)pvStack_18 & 0xffffff00);
    if ((param_2 == piVar2[0x10]) || (*(int *)(param_2 + 0x28) == 0)) break;
    FUN_005d3440(*(int *)(param_2 + 0x28),local_2c);
    piVar5 = piVar5 + 1;
    _Memory = local_28;
  }
  *param_1 = 0;
  uVar3 = DAT_0099d080;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = uVar3;
  param_1[4] = uVar3;
  param_1[5] = uVar3;
  if (local_28 == (void *)0x0) {
    return param_1;
  }
  _free(local_28);
  return extraout_EAX_01;
}


// ==== FUN_005dcd90 @ 0x005dcd90 ====

void FUN_005dcd90(void)

{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 unaff_EDI;
  float fVar6;
  undefined1 auStack_9a [14];
  undefined1 auStack_8c [48];
  undefined4 uStack_5c;
  float fStack_58;
  undefined1 auStack_4c [44];
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  bVar1 = *(byte *)(in_ECX + 0x144);
  if (bVar1 != 0) {
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    uVar3 = (**(code **)(*piVar2 + 4))(0,s___Doll_Human_SplitMesh_cpp_009c3504,0x221);
    puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      uVar5 = (**(code **)(**(int **)(in_ECX + 0x6c) + 0x20))();
      *puVar4 = &PTR_FUN_009b1860;
      puVar4[1] = bVar1 + 0x32 | 0x60000;
      puVar4[2] = uVar5;
      puVar4[3] = uVar3;
      *(undefined1 *)(puVar4 + 4) = 0;
    }
    FUN_00797a20(puVar4);
    FUN_005db6b0(auStack_8c);
    fVar6 = fStack_58 + DAT_009c16c0;
    (**(code **)(**(int **)(in_ECX + 0x6c) + 0x2c))(auStack_4c);
    puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[3] = uStack_20;
      puVar4[4] = uStack_1c;
      puVar4[5] = uStack_18;
      puVar4[6] = unaff_EDI;
      puVar4[7] = uStack_5c;
      puVar4[8] = fVar6;
      *puVar4 = &PTR_FUN_009b2b5c;
      puVar4[1] = uVar3;
      puVar4[2] = 1;
      puVar4[9] = 0;
      puVar4[10] = 500;
      puVar4[0xb] = 500;
    }
    FUN_00797a20(puVar4);
    FUN_00430ce0(auStack_9a + -6);
  }
  return;
}


// ==== FUN_005dcf10 @ 0x005dcf10 ====

void FUN_005dcf10(void)

{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 unaff_EDI;
  undefined4 *puStack_88;
  undefined4 uStack_84;
  char *pcStack_80;
  undefined4 uStack_7c;
  undefined1 auStack_66 [2];
  undefined1 auStack_64 [12];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 auStack_4c [12];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  bVar1 = *(byte *)(in_ECX + 0x144);
  if (bVar1 != 0) {
    uStack_7c = 0x5dcf3e;
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    uStack_7c = 0x23c;
    pcStack_80 = s___Doll_Human_SplitMesh_cpp_009c3520;
    uStack_84 = 0;
    puStack_88 = (undefined4 *)0x5dcf51;
    uVar3 = (**(code **)(*piVar2 + 4))();
    puStack_88 = (undefined4 *)0x5dcf62;
    puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puStack_88 = (undefined4 *)0x5dcf70;
      uVar5 = (**(code **)(**(int **)(in_ECX + 0x6c) + 0x20))();
      *puVar4 = &PTR_FUN_009b1860;
      puVar4[1] = bVar1 + 0x3c | 0x60000;
      puVar4[2] = uVar5;
      puVar4[3] = uVar3;
      *(undefined1 *)(puVar4 + 4) = 0;
    }
    puStack_88 = puVar4;
    FUN_00797a20();
    puStack_88 = auStack_4c;
    FUN_005db6b0();
    uVar5 = uStack_1c;
    puStack_88 = auStack_4c;
    uStack_14 = 0;
    uStack_18 = 0;
    uStack_1c = 0;
    uStack_58 = 0;
    uStack_54 = 0;
    uStack_50 = DAT_0099d080;
    thunk_FUN_0079e5a0(auStack_64,&uStack_58);
    thunk_FUN_0079e1ba(auStack_66 + -10,auStack_66 + -10);
    puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[3] = uStack_84;
      puVar4[4] = pcStack_80;
      puVar4[5] = uStack_7c;
      *puVar4 = &PTR_FUN_009c32ac;
      puVar4[1] = uVar3;
      puVar4[2] = 1;
      puVar4[6] = unaff_EDI;
      puVar4[7] = uVar3;
      puVar4[8] = uVar5;
      puVar4[9] = 1;
      puVar4[10] = 0;
      puVar4[0xb] = 4000;
    }
    FUN_00797a20(puVar4);
    FUN_00430ce0(&puStack_88);
  }
  return;
}


// ==== FUN_005dd0a0 @ 0x005dd0a0 ====

void FUN_005dd0a0(void)

{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 unaff_EDI;
  undefined4 *puStack_88;
  undefined4 uStack_84;
  char *pcStack_80;
  undefined4 uStack_7c;
  undefined1 auStack_66 [2];
  undefined1 auStack_64 [12];
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 auStack_4c [12];
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  bVar1 = *(byte *)(in_ECX + 0x144);
  if (bVar1 != 0) {
    uStack_7c = 0x5dd0ce;
    piVar2 = (int *)(**(code **)(*DAT_00b5a688 + 0x14))();
    uStack_7c = 600;
    pcStack_80 = s___Doll_Human_SplitMesh_cpp_009c353c;
    uStack_84 = 0;
    puStack_88 = (undefined4 *)0x5dd0e1;
    uVar3 = (**(code **)(*piVar2 + 4))();
    puStack_88 = (undefined4 *)0x5dd0f2;
    puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puStack_88 = (undefined4 *)0x5dd100;
      uVar5 = (**(code **)(**(int **)(in_ECX + 0x6c) + 0x20))();
      *puVar4 = &PTR_FUN_009b1860;
      puVar4[1] = bVar1 + 0x46 | 0x60000;
      puVar4[2] = uVar5;
      puVar4[3] = uVar3;
      *(undefined1 *)(puVar4 + 4) = 0;
    }
    puStack_88 = puVar4;
    FUN_00797a20();
    puStack_88 = auStack_4c;
    FUN_005db6b0();
    uVar5 = uStack_1c;
    puStack_88 = auStack_4c;
    uStack_14 = 0;
    uStack_18 = 0;
    uStack_1c = 0;
    uStack_58 = 0;
    uStack_54 = 0;
    uStack_50 = DAT_0099d080;
    thunk_FUN_0079e5a0(auStack_64,&uStack_58);
    thunk_FUN_0079e1ba(auStack_66 + -10,auStack_66 + -10);
    puVar4 = (undefined4 *)(**(code **)(*DAT_00b5a6a8 + 4))();
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[3] = uStack_84;
      puVar4[4] = pcStack_80;
      puVar4[5] = uStack_7c;
      *puVar4 = &PTR_FUN_009c32ac;
      puVar4[1] = uVar3;
      puVar4[2] = 1;
      puVar4[6] = unaff_EDI;
      puVar4[7] = uVar3;
      puVar4[8] = uVar5;
      puVar4[9] = 1;
      puVar4[10] = 0;
      puVar4[0xb] = 3000;
    }
    FUN_00797a20(puVar4);
    FUN_00430ce0(&puStack_88);
  }
  return;
}


// ==== FUN_005dd230 @ 0x005dd230 ====

void FUN_005dd230(undefined4 param_1,int param_2,float param_3,float param_4,undefined4 param_5,
                 int param_6,undefined4 param_7,float param_8,int param_9)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  undefined4 *puVar6;
  float fVar7;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined1 local_74 [12];
  undefined1 local_68 [4];
  void *local_64;
  undefined1 local_58 [24];
  undefined1 local_40 [64];
  
  FUN_00401660(param_1,0,0xffffffff);
  uVar3 = FUN_005d3040(local_68,param_1);
  FUN_005ddad0(uVar3);
  if (local_64 != (void *)0x0) {
    _free(local_64);
    return;
  }
  uVar3 = FUN_005d3240(local_68,param_1);
  FUN_005ddad0(uVar3);
  if (local_64 != (void *)0x0) {
    _free(local_64);
    return;
  }
  puVar4 = (undefined4 *)FUN_005dc9b0(&local_80,param_2);
  *(undefined4 *)(in_ECX + 0xb8) = *puVar4;
  *(undefined4 *)(in_ECX + 0xbc) = puVar4[1];
  *(bool *)(in_ECX + 0x68) = param_2 != 0;
  *(undefined1 *)(in_ECX + 0x69) = 1;
  puVar4 = (undefined4 *)FUN_005dcc10(local_58,in_ECX + 0x8c);
  *(undefined4 *)(in_ECX + 0xc0) = *puVar4;
  *(undefined4 *)(in_ECX + 0xc4) = puVar4[1];
  *(undefined4 *)(in_ECX + 200) = puVar4[2];
  *(undefined4 *)(in_ECX + 0xcc) = puVar4[3];
  *(undefined4 *)(in_ECX + 0xd0) = puVar4[4];
  *(undefined4 *)(in_ECX + 0xd4) = puVar4[5];
  puVar4 = (undefined4 *)FUN_005db570(local_40,(undefined4 *)(in_ECX + 0xc0));
  puVar6 = (undefined4 *)(in_ECX + 0xd8);
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  puVar4 = (undefined4 *)FUN_005dc610(local_74,param_7);
  *(undefined4 *)(in_ECX + 0x118) = *puVar4;
  *(undefined4 *)(in_ECX + 0x11c) = puVar4[1];
  *(undefined4 *)(in_ECX + 0x120) = puVar4[2];
  puVar4 = (undefined4 *)FUN_005dc6f0(local_68,param_5);
  *(undefined4 *)(in_ECX + 0x124) = *puVar4;
  *(undefined4 *)(in_ECX + 0x128) = puVar4[1];
  *(undefined4 *)(in_ECX + 300) = puVar4[2];
  fVar2 = DAT_0099d0b4;
  fVar1 = SQRT(*(float *)(in_ECX + 0x110) * *(float *)(in_ECX + 0x110) +
               *(float *)(in_ECX + 0x10c) * *(float *)(in_ECX + 0x10c) +
               *(float *)(in_ECX + 0x108) * *(float *)(in_ECX + 0x108)) * DAT_0099d0b4;
  fVar7 = DAT_009b02a8 / fVar1;
  *(float *)(in_ECX + 0x138) = fVar1;
  if ((fVar7 < fVar2) || (fVar2 = DAT_0099d080, DAT_0099d080 <= fVar7)) {
    fVar7 = fVar2;
  }
  *(float *)(in_ECX + 0x154) = fVar7;
  *(float *)(in_ECX + 0x134) = fVar7 * param_8;
  *(undefined4 *)(in_ECX + 4) = 0;
  *(undefined4 *)(in_ECX + 8) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  local_80 = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  local_7c = 0;
  local_78 = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x13c) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  iVar5 = FUN_00403620(0,*(undefined4 *)(param_9 + 0x14),s_preserve_009c34bc,8);
  if (iVar5 == 0) {
    *(undefined4 *)(in_ECX + 0x140) = 0;
  }
  else {
    iVar5 = FUN_00403620(0,*(undefined4 *)(param_9 + 0x14),s_reaction_009c34c8,8);
    *(uint *)(in_ECX + 0x140) = (iVar5 != 0) + 1;
  }
  fVar1 = DAT_0099d080;
  *(undefined4 *)(in_ECX + 0x60) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x44) = 0;
  *(undefined4 *)(in_ECX + 0x40) = 0;
  *(undefined4 *)(in_ECX + 0x38) = 0;
  *(undefined4 *)(in_ECX + 0x34) = 0;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  *(float *)(in_ECX + 100) = fVar1;
  *(float *)(in_ECX + 0x50) = fVar1;
  *(float *)(in_ECX + 0x3c) = fVar1;
  *(float *)(in_ECX + 0x28) = fVar1;
  *(undefined4 *)(in_ECX + 0xac) = 0;
  *(float *)(in_ECX + 0x130) = (float)param_6 * *(float *)(in_ECX + 0x154);
  *(float *)(in_ECX + 0xb0) = *(float *)(in_ECX + 0x154) * param_4;
  *(float *)(in_ECX + 0xb4) = *(float *)(in_ECX + 0x154) * param_3;
  return;
}


// ==== FUN_005dd580 @ 0x005dd580 ====

void FUN_005dd580(int param_1,uint param_2)

{
  float fVar1;
  undefined1 uVar2;
  int *piVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  float *pfVar6;
  int in_ECX;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  float10 fVar10;
  float fVar11;
  float fVar12;
  float fStack_58;
  void *pvStack_54;
  undefined4 uStack_50;
  undefined1 auStack_40 [64];
  
  if (*(uint *)(param_1 + 0x84) <= param_2) {
    FUN_0079dba3();
  }
  if (*(uint *)(param_1 + 0x88) < 0x10) {
    iVar7 = param_1 + 0x74;
  }
  else {
    iVar7 = *(int *)(param_1 + 0x74);
  }
  uVar2 = *(undefined1 *)(iVar7 + param_2);
  if (*(int *)(in_ECX + 0x88) == 0) {
    FUN_00401410(1,*(undefined4 *)(in_ECX + 0x84));
  }
  piVar8 = (int *)(in_ECX + 0x74);
  if (*(uint *)(in_ECX + 0x88) < 0x10) {
    piVar3 = piVar8;
  }
  else {
    piVar3 = (int *)*piVar8;
  }
  *(undefined1 *)piVar3 = uVar2;
  *(undefined4 *)(in_ECX + 0x84) = 1;
  if (0xf < *(uint *)(in_ECX + 0x88)) {
    piVar8 = (int *)*piVar8;
  }
  *(undefined1 *)((int)piVar8 + 1) = 0;
  uVar4 = FUN_005d3040(&fStack_58,in_ECX + 0x70);
  FUN_005ddad0(uVar4);
  if (pvStack_54 != (void *)0x0) {
    _free(pvStack_54);
    return;
  }
  uVar4 = FUN_005d3240(&fStack_58,in_ECX + 0x70);
  FUN_005ddad0(uVar4);
  if (pvStack_54 != (void *)0x0) {
    _free(pvStack_54);
    return;
  }
  *(undefined4 *)(in_ECX + 0xac) = 0;
  *(undefined1 *)(in_ECX + 0x68) = *(undefined1 *)(param_1 + 0x68);
  *(undefined1 *)(in_ECX + 0x69) = *(undefined1 *)(param_1 + 0x69);
  puVar5 = (undefined4 *)FUN_005dcc10(&fStack_58,in_ECX + 0x8c);
  *(undefined4 *)(in_ECX + 0xc0) = *puVar5;
  *(undefined4 *)(in_ECX + 0xc4) = puVar5[1];
  *(undefined4 *)(in_ECX + 200) = puVar5[2];
  *(undefined4 *)(in_ECX + 0xcc) = puVar5[3];
  *(undefined4 *)(in_ECX + 0xd0) = puVar5[4];
  *(undefined4 *)(in_ECX + 0xd4) = puVar5[5];
  puVar5 = (undefined4 *)FUN_005db570(auStack_40,(undefined4 *)(in_ECX + 0xc0));
  puVar9 = (undefined4 *)(in_ECX + 0xd8);
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  *(undefined4 *)(in_ECX + 0x118) = *(undefined4 *)(in_ECX + 0xd8);
  *(undefined4 *)(in_ECX + 0x11c) = *(undefined4 *)(in_ECX + 0xdc);
  *(undefined4 *)(in_ECX + 0x120) = *(undefined4 *)(in_ECX + 0xe0);
  *(undefined4 *)(in_ECX + 0x124) = *(undefined4 *)(param_1 + 0x124);
  *(undefined4 *)(in_ECX + 0x128) = *(undefined4 *)(param_1 + 0x128);
  *(undefined4 *)(in_ECX + 300) = *(undefined4 *)(param_1 + 300);
  fStack_58 = 0.0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  pvStack_54 = (void *)0x0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  uStack_50 = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  puVar5 = (undefined4 *)(param_1 + 0x28);
  puVar9 = (undefined4 *)(in_ECX + 0x28);
  for (iVar7 = 0x10; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar9 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar9 = puVar9 + 1;
  }
  *(undefined4 *)(in_ECX + 0x140) = *(undefined4 *)(param_1 + 0x140);
  fVar11 = DAT_0099d0b4;
  fVar1 = SQRT(*(float *)(in_ECX + 0x110) * *(float *)(in_ECX + 0x110) +
               *(float *)(in_ECX + 0x10c) * *(float *)(in_ECX + 0x10c) +
               *(float *)(in_ECX + 0x108) * *(float *)(in_ECX + 0x108)) * DAT_0099d0b4;
  fVar12 = DAT_009b02a8 / fVar1;
  *(float *)(in_ECX + 0x138) = fVar1;
  if ((fVar11 <= fVar12) && (fVar11 = fVar12, DAT_0099d080 <= fVar12)) {
    fVar11 = DAT_0099d080;
  }
  *(float *)(in_ECX + 0x154) = fVar11;
  *(float *)(in_ECX + 0x130) = *(float *)(param_1 + 0x130) * fVar11;
  *(float *)(in_ECX + 0xb0) = *(float *)(param_1 + 0xb0) * fVar11;
  *(float *)(in_ECX + 0xb4) = *(float *)(param_1 + 0xb4) * fVar11;
  *(float *)(in_ECX + 0x134) = *(float *)(param_1 + 0x134) * fVar11;
  pfVar6 = (float *)FUN_0040ecc0(&fStack_58);
  fStack_58 = *(float *)(param_1 + 0xb8) + *pfVar6 * DAT_0099d0b4;
  pvStack_54 = (void *)(*(float *)(param_1 + 0xbc) + pfVar6[2] * DAT_0099d0b4);
  thunk_FUN_0079de77(in_ECX + 0xb8,&fStack_58);
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  fVar10 = (float10)FUN_005db9e0();
  fVar1 = *(float *)(param_1 + 0x1c);
  fStack_58 = *(float *)(param_1 + 0x20);
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(param_1 + 0x18);
  *(float *)(in_ECX + 8) = (float)(fVar10 + (float10)fVar1);
  *(float *)(in_ECX + 0xc) = fStack_58;
  *(int *)(in_ECX + 0x13c) = *(int *)(param_1 + 0x13c) + 1;
  FUN_005dcd90();
  FUN_005dd0a0();
  return;
}


// ==== FUN_005dd8d0 @ 0x005dd8d0 ====

void FUN_005dd8d0(void)

{
  int in_ECX;
  float fVar1;
  
  fVar1 = *(float *)(in_ECX + 0xb0) * DAT_00a0fd50;
  *(int *)(in_ECX + 0x13c) = *(int *)(in_ECX + 0x13c) + 1;
  *(undefined4 *)(in_ECX + 4) = *(undefined4 *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 0x1c);
  *(undefined4 *)(in_ECX + 0xc) = *(undefined4 *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(float *)(in_ECX + 0xb0) = fVar1;
  fVar1 = *(float *)(in_ECX + 0xb4) * DAT_0099d0b4;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  *(undefined4 *)(in_ECX + 0xac) = 0;
  *(float *)(in_ECX + 0xb4) = fVar1;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  FUN_005dd0a0();
  return;
}


// ==== FUN_005dd970 @ 0x005dd970 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005dd970(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  undefined1 local_40 [64];
  
  if (DAT_0099cdc8 < *(float *)(in_ECX + 0x130)) {
    *(float *)(in_ECX + 0x24) = *(float *)(in_ECX + 0x130) * _DAT_009a4474;
    puVar1 = (undefined4 *)FUN_005db770(local_40);
    puVar3 = (undefined4 *)(in_ECX + 0x28);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  *(undefined1 *)(in_ECX + 0x68) = 0;
  FUN_005dcf10();
  return;
}


// ==== FUN_005dd9c0 @ 0x005dd9c0 ====

void FUN_005dd9c0(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int in_ECX;
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  if (*(int *)(in_ECX + 0x90) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(int *)(in_ECX + 0x94) - *(int *)(in_ECX + 0x90) >> 2;
  }
  puVar3 = (undefined4 *)(in_ECX + 0x28);
  puVar5 = param_3 + 6;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      iVar1 = *(int *)(in_ECX + 0x90);
      if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0x94) - iVar1 >> 2) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      *param_3 = *(undefined4 *)(iVar1 + uVar4 * 4);
      iVar1 = *(int *)(in_ECX + 0xa0);
      if ((iVar1 == 0) || ((uint)(*(int *)(in_ECX + 0xa4) - iVar1 >> 2) <= uVar4)) {
                    /* WARNING: Subroutine does not return */
        FUN_0085b340();
      }
      param_3[1] = *(undefined4 *)(iVar1 + uVar4 * 4);
      FUN_005c1360(param_3);
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  FUN_005dbb00(param_1);
  return;
}


// ==== FUN_005dda80 @ 0x005dda80 ====

void * FUN_005dda80(void *param_1,int param_2,void *param_3)

{
  size_t _Size;
  void *pvVar1;
  
  _Size = (param_2 - (int)param_1 >> 2) * 4;
  pvVar1 = _memmove(param_3,param_1,_Size);
  return (void *)((int)pvVar1 + _Size);
}


// ==== FUN_005ddab0 @ 0x005ddab0 ====

void FUN_005ddab0(byte param_1)

{
  void *in_ECX;
  
  FUN_005dc830();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ddad0 @ 0x005ddad0 ====

void FUN_005ddad0(int param_1)

{
  void *_Src;
  void *_Memory;
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  
  if (in_ECX == param_1) {
    return;
  }
  _Src = *(void **)(param_1 + 4);
  if (_Src != (void *)0x0) {
    uVar5 = *(int *)(param_1 + 8) - (int)_Src >> 2;
    if (uVar5 != 0) {
      _Memory = *(void **)(in_ECX + 4);
      if (_Memory == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
      }
      if (uVar5 <= uVar4) {
        _memmove(_Memory,_Src,(*(int *)(param_1 + 8) - (int)_Src >> 2) * 4);
        if (*(int *)(param_1 + 4) == 0) {
          *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
          return;
        }
        *(int *)(in_ECX + 8) =
             *(int *)(in_ECX + 4) + (*(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2) * 4;
        return;
      }
      if (_Memory == (void *)0x0) {
        uVar4 = 0;
      }
      else {
        uVar4 = *(int *)(in_ECX + 0xc) - (int)_Memory >> 2;
      }
      if (uVar5 <= uVar4) {
        if (_Memory == (void *)0x0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(in_ECX + 8) - (int)_Memory >> 2;
        }
        iVar2 = *(int *)(param_1 + 4) + iVar2 * 4;
        FUN_005dda80(*(int *)(param_1 + 4),iVar2,_Memory);
        uVar3 = FUN_005a6d90(iVar2,*(undefined4 *)(param_1 + 8),*(undefined4 *)(in_ECX + 8));
        *(undefined4 *)(in_ECX + 8) = uVar3;
        return;
      }
      if (_Memory != (void *)0x0) {
        _free(_Memory);
        return;
      }
      if (*(int *)(param_1 + 4) == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *(int *)(param_1 + 8) - *(int *)(param_1 + 4) >> 2;
      }
      cVar1 = FUN_005c20f0(iVar2);
      if (cVar1 == '\0') {
        return;
      }
      uVar3 = FUN_005a6d90(*(undefined4 *)(param_1 + 4),*(undefined4 *)(param_1 + 8),
                           *(undefined4 *)(in_ECX + 4));
      *(undefined4 *)(in_ECX + 8) = uVar3;
      return;
    }
  }
  if (*(void **)(in_ECX + 4) == (void *)0x0) {
    *(undefined4 *)(in_ECX + 4) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
    *(undefined4 *)(in_ECX + 0xc) = 0;
    return;
  }
  _free(*(void **)(in_ECX + 4));
  return;
}


// ==== FUN_005ddc20 @ 0x005ddc20 ====

void FUN_005ddc20(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3574;
  return;
}


// ==== FUN_005ddc30 @ 0x005ddc30 ====

void FUN_005ddc30(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3574;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005ddc50 @ 0x005ddc50 ====

void FUN_005ddc50(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00982f8e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  pvVar1 = operator_new(8);
  local_4 = 0;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f7bd0();
  }
  local_4 = 0xffffffff;
  *in_ECX = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f7530();
  }
  local_4 = 0xffffffff;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(4);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f6940();
  }
  local_4 = 0xffffffff;
  in_ECX[2] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 3;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f63d0();
  }
  local_4 = 0xffffffff;
  in_ECX[3] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 4;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f5200();
  }
  local_4 = 0xffffffff;
  in_ECX[5] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 5;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f46b0();
  }
  local_4 = 0xffffffff;
  in_ECX[6] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 6;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f3ed0();
  }
  local_4 = 0xffffffff;
  in_ECX[4] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 7;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f3600();
  }
  local_4 = 0xffffffff;
  in_ECX[7] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 8;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f2b40();
  }
  local_4 = 0xffffffff;
  in_ECX[8] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 9;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f2090();
  }
  local_4 = 0xffffffff;
  in_ECX[9] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f1580();
  }
  local_4 = 0xffffffff;
  in_ECX[10] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0xb;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f0a70();
  }
  local_4 = 0xffffffff;
  in_ECX[0xb] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0xc;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005f0320();
  }
  local_4 = 0xffffffff;
  in_ECX[0xc] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0xd;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005efdf0();
  }
  local_4 = 0xffffffff;
  in_ECX[0xd] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0xe;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005ef550();
  }
  local_4 = 0xffffffff;
  in_ECX[0xe] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0xf;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005eee10();
  }
  local_4 = 0xffffffff;
  in_ECX[0xf] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0x10;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005ee490();
  }
  local_4 = 0xffffffff;
  in_ECX[0x10] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0x11;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005edda0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x11] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0x12;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005ed7a0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x12] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x13;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005eced0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x13] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0x14;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005ec2b0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x14] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0x15;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005eb7d0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x15] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0x16;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005eb130();
  }
  local_4 = 0xffffffff;
  in_ECX[0x16] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x17;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005ea890();
  }
  local_4 = 0xffffffff;
  in_ECX[0x17] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x18;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e9d60();
  }
  local_4 = 0xffffffff;
  in_ECX[0x18] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x19;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e9220();
  }
  local_4 = 0xffffffff;
  in_ECX[0x19] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0x1a;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e8660();
  }
  local_4 = 0xffffffff;
  in_ECX[0x1a] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0x1b;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e7bb0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x1b] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x1c;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e7100();
  }
  local_4 = 0xffffffff;
  in_ECX[0x1c] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x1d;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e6600();
  }
  local_4 = 0xffffffff;
  in_ECX[0x1d] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x1e;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e5b50();
  }
  local_4 = 0xffffffff;
  in_ECX[0x1e] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0x1f;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e57d0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x1f] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x20;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e48d0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x20] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x21;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e3dc0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x21] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0x22;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e36b0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x22] = uVar2;
  pvVar1 = operator_new(0x10);
  local_4 = 0x23;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e2d80();
  }
  local_4 = 0xffffffff;
  in_ECX[0x23] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0x24;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e2610();
  }
  local_4 = 0xffffffff;
  in_ECX[0x24] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0x25;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e2090();
  }
  local_4 = 0xffffffff;
  in_ECX[0x25] = uVar2;
  pvVar1 = operator_new(0xc);
  local_4 = 0x26;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e16e0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x26] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0x27;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e13c0();
  }
  local_4 = 0xffffffff;
  in_ECX[0x27] = uVar2;
  pvVar1 = operator_new(0x14);
  local_4 = 0x28;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e0f90();
  }
  local_4 = 0xffffffff;
  in_ECX[0x28] = uVar2;
  pvVar1 = operator_new(8);
  local_4 = 0x29;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005e0e70();
  }
  in_ECX[0x29] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005de3e0 @ 0x005de3e0 ====

void FUN_005de3e0(void)

{
  void *_Memory;
  int *in_ECX;
  
  if ((undefined4 *)in_ECX[0x29] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x29])(1);
  }
  _Memory = (void *)in_ECX[0x28];
  in_ECX[0x29] = 0;
  if (_Memory != (void *)0x0) {
    FUN_005e0fa0();
    _free(_Memory);
    return;
  }
  in_ECX[0x28] = 0;
  if ((undefined4 *)in_ECX[0x27] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x27])(1);
  }
  in_ECX[0x27] = 0;
  if ((undefined4 *)in_ECX[0x26] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x26])(1);
  }
  in_ECX[0x26] = 0;
  if ((undefined4 *)in_ECX[0x25] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x25])(1);
  }
  in_ECX[0x25] = 0;
  if ((undefined4 *)in_ECX[0x24] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x24])(1);
  }
  in_ECX[0x24] = 0;
  if ((undefined4 *)in_ECX[0x23] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x23])(1);
  }
  in_ECX[0x23] = 0;
  if ((undefined4 *)in_ECX[0x22] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x22])(1);
  }
  in_ECX[0x22] = 0;
  if ((undefined4 *)in_ECX[0x21] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x21])(1);
  }
  in_ECX[0x21] = 0;
  if ((undefined4 *)in_ECX[0x20] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x20])(1);
  }
  in_ECX[0x20] = 0;
  if ((undefined4 *)in_ECX[0x1f] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1f])(1);
  }
  in_ECX[0x1f] = 0;
  if ((undefined4 *)in_ECX[0x1c] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1c])(1);
  }
  in_ECX[0x1c] = 0;
  if ((undefined4 *)in_ECX[0x1e] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1e])(1);
  }
  in_ECX[0x1e] = 0;
  if ((undefined4 *)in_ECX[0x1d] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1d])(1);
  }
  in_ECX[0x1d] = 0;
  if ((undefined4 *)in_ECX[0x1a] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1a])(1);
  }
  in_ECX[0x1a] = 0;
  if ((undefined4 *)in_ECX[0x1b] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x1b])(1);
  }
  in_ECX[0x1b] = 0;
  if ((undefined4 *)in_ECX[0x19] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x19])(1);
  }
  in_ECX[0x19] = 0;
  if ((undefined4 *)in_ECX[0x18] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x18])(1);
  }
  in_ECX[0x18] = 0;
  if ((undefined4 *)in_ECX[0x17] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x17])(1);
  }
  in_ECX[0x17] = 0;
  if ((undefined4 *)in_ECX[0x16] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x16])(1);
  }
  in_ECX[0x16] = 0;
  if ((undefined4 *)in_ECX[0x15] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x15])(1);
  }
  in_ECX[0x15] = 0;
  if ((undefined4 *)in_ECX[0x14] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x14])(1);
  }
  in_ECX[0x14] = 0;
  if ((undefined4 *)in_ECX[0x13] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x13])(1);
  }
  in_ECX[0x13] = 0;
  if ((undefined4 *)in_ECX[0x12] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x12])(1);
  }
  in_ECX[0x12] = 0;
  if ((undefined4 *)in_ECX[0x11] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x11])(1);
  }
  in_ECX[0x11] = 0;
  if ((undefined4 *)in_ECX[0x10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x10])(1);
  }
  in_ECX[0x10] = 0;
  if ((undefined4 *)in_ECX[0xf] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xf])(1);
  }
  in_ECX[0xf] = 0;
  if ((undefined4 *)in_ECX[0xe] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0xe])(1);
  }
  in_ECX[0xe] = 0;
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
  if ((undefined4 *)in_ECX[10] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[10])(1);
  }
  in_ECX[10] = 0;
  if ((undefined4 *)in_ECX[9] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[9])(1);
  }
  in_ECX[9] = 0;
  if ((undefined4 *)in_ECX[8] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[8])(1);
  }
  in_ECX[8] = 0;
  if ((undefined4 *)in_ECX[7] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[7])(1);
  }
  in_ECX[7] = 0;
  if ((undefined4 *)in_ECX[4] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[4])(1);
  }
  in_ECX[4] = 0;
  if ((undefined4 *)in_ECX[6] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[6])(1);
  }
  in_ECX[6] = 0;
  if ((undefined4 *)in_ECX[5] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[5])(1);
  }
  in_ECX[5] = 0;
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
  return;
}


// ==== FUN_005de6d0 @ 0x005de6d0 ====

void FUN_005de6d0(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00982fab;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c357c;
  pvVar1 = operator_new(0xa8);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (pvVar1 == (void *)0x0) {
    in_ECX[1] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_005ddc50();
  in_ECX[1] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005de750 @ 0x005de750 ====

void FUN_005de750(void)

{
  void *_Memory;
  void *pvVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  pvVar1 = ExceptionList;
  puStack_8 = &LAB_00982fbd;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c357c;
  _Memory = (void *)in_ECX[1];
  local_4 = 0;
  if (_Memory == (void *)0x0) {
    in_ECX[1] = 0;
    *in_ECX = &PTR_FUN_009c3574;
    ExceptionList = pvVar1;
    return;
  }
  FUN_005de3e0();
  _free(_Memory);
  return;
}


// ==== FUN_005de7c0 @ 0x005de7c0 ====

void FUN_005de7c0(byte param_1)

{
  void *in_ECX;
  
  FUN_005de750();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005de7e0 @ 0x005de7e0 ====

void FUN_005de7e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3610;
  return;
}


// ==== FUN_005de7f0 @ 0x005de7f0 ====

void FUN_005de7f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3610;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005de810 @ 0x005de810 ====

void FUN_005de810(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10) = *param_1;
  *(undefined4 *)(in_ECX + 0x14) = param_1[1];
  *(undefined4 *)(in_ECX + 0x18) = param_1[2];
  *(undefined4 *)(in_ECX + 0x1c) = param_1[3];
  return;
}


// ==== FUN_005de830 @ 0x005de830 ====

int FUN_005de830(void)

{
  int in_ECX;
  
  return in_ECX + 0x10;
}


// ==== FUN_005de840 @ 0x005de840 ====

void FUN_005de840(void)

{
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00982fd8;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c36b4;
  local_4 = 0;
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c3610;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005de8b0 @ 0x005de8b0 ====

undefined4 FUN_005de8b0(undefined2 param_1)

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


// ==== FUN_005de8e0 @ 0x005de8e0 ====

void FUN_005de8e0(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 *puVar3;
  int in_ECX;
  undefined2 local_108;
  undefined1 auStack_106 [2];
  undefined1 auStack_104 [256];
  undefined4 uStack_4;
  
  local_108 = param_1;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x30))(&local_108);
  if (iVar1 != 0) {
    auStack_104[0] = 0;
    uVar2 = FUN_0044a580(auStack_104,s_File___s__Line___d_009c35b4,
                         s___PartyWar_Field_Result_Flyweigh_009c3584,0x1c);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  puVar3 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))(1,0);
  *puVar3 = param_1;
  *(undefined4 *)(puVar3 + 2) = uStack_4;
  iVar1 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar3);
  if (iVar1 != 0) {
    uVar2 = FUN_0044a580(auStack_106 + -10,s_File___s__Line___d_009c35f8,
                         s___PartyWar_Field_Result_Flyweigh_009c35c8,0x24);
    FUN_00797b80(uVar2);
    FUN_00797a40();
  }
  return;
}


// ==== FUN_005de990 @ 0x005de990 ====

void FUN_005de990(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00983000;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c36b4;
  pvVar1 = operator_new(0x2818);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005deb20();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x4028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005df090(in_ECX[1]);
  }
  in_ECX[2] = uVar2;
  in_ECX[3] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005dea30 @ 0x005dea30 ====

void FUN_005dea30(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c362c;
  return;
}


// ==== FUN_005dea40 @ 0x005dea40 ====

void FUN_005dea40(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3684;
  return;
}


// ==== FUN_005dea50 @ 0x005dea50 ====

void FUN_005dea50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c369c;
  return;
}


// ==== FUN_005dea60 @ 0x005dea60 ====

void FUN_005dea60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c362c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005dea80 @ 0x005dea80 ====

void FUN_005dea80(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3684;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005deaa0 @ 0x005deaa0 ====

void FUN_005deaa0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c369c;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005deac0 @ 0x005deac0 ====

void FUN_005deac0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c36cc;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_005deae0 @ 0x005deae0 ====

void FUN_005deae0(byte param_1)

{
  void *in_ECX;
  
  FUN_005deac0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005deb00 @ 0x005deb00 ====

void FUN_005deb00(byte param_1)

{
  void *in_ECX;
  
  FUN_005de840();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005deb20 @ 0x005deb20 ====

void FUN_005deb20(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983018;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c36d4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c36cc;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x14,0x200,FUN_00419fa0,FUN_006ef6d0);
  in_ECX[0xa02] = 0;
  in_ECX[0xa02] = in_ECX[0xa02] + 0x200;
  in_ECX[0xa05] = in_ECX + 2;
  in_ECX[0xa03] = 0;
  in_ECX[0xa04] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[4] = puVar1 + 7;
    puVar1[5] = 0;
    puVar1[6] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 5;
  } while (iVar2 != 0);
  in_ECX[0x9ff] = 0;
  in_ECX[0xa00] = 0;
  in_ECX[0xa01] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005debd0 @ 0x005debd0 ====

undefined4 FUN_005debd0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x280c);
}


// ==== FUN_005debe0 @ 0x005debe0 ====

void FUN_005debe0(byte param_1)

{
  void *in_ECX;
  
  FUN_005dec00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005dec00 @ 0x005dec00 ====

void FUN_005dec00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983043;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c36d4;
  local_4 = 1;
  if ((void *)in_ECX[0xa04] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c36cc;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x200,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c3684;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0xa04]);
  return;
}


// ==== FUN_005dec80 @ 0x005dec80 ====

void * FUN_005dec80(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c36e8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    *(int *)((int)param_2 + 0x10) = *(int *)((int)param_2 + 0x10) + param_1;
    return param_2;
  }
  pvVar2 = *(void **)(in_ECX + 0x2814);
  *(int *)(in_ECX + 0x280c) = *(int *)(in_ECX + 0x280c) + 1;
  if (pvVar2 == (void *)0x0) {
    pvVar2 = operator_new(0x14);
    *(undefined4 *)((int)pvVar2 + 0xc) = *(undefined4 *)(in_ECX + 0x2810);
    *(void **)(in_ECX + 0x2810) = pvVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x2814) = *(undefined4 *)((int)pvVar2 + 8);
  }
  *(undefined4 *)((int)pvVar2 + 8) = 0;
  *(int *)((int)pvVar2 + 0x10) = param_1;
  return pvVar2;
}


// ==== FUN_005ded30 @ 0x005ded30 ====

undefined4 FUN_005ded30(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c36e8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x10);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x10);
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(in_ECX + 0x2814);
    *(int *)(in_ECX + 0x280c) = *(int *)(in_ECX + 0x280c) + -1;
    *(int *)(in_ECX + 0x2814) = param_2;
  }
  return 0;
}


// ==== FUN_005dedb0 @ 0x005dedb0 ====

void FUN_005dedb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c376c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x200,FUN_006ef6d0);
  return;
}


// ==== FUN_005dedd0 @ 0x005dedd0 ====

void FUN_005dedd0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983063;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3774;
  local_4 = 1;
  if ((void *)in_ECX[0x1004] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c376c;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x200,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c369c;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x1004]);
  return;
}


// ==== FUN_005dee50 @ 0x005dee50 ====

undefined4 FUN_005dee50(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x400c);
}


// ==== FUN_005dee60 @ 0x005dee60 ====

undefined4 FUN_005dee60(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x1c) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c36e8,0xa9);
      FUN_00797b80(uVar2);
      FUN_00797a40();
    }
    piVar1 = (int *)(param_2 + 0x1c);
    *piVar1 = *piVar1 - param_1;
    if (*piVar1 != 0) {
      return *(undefined4 *)(param_2 + 0x1c);
    }
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x4014);
    *(int *)(in_ECX + 0x400c) = *(int *)(in_ECX + 0x400c) + -1;
    *(int *)(in_ECX + 0x4014) = param_2;
  }
  return 0;
}


// ==== FUN_005deee0 @ 0x005deee0 ====

undefined4 * FUN_005deee0(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (undefined4 *)0x0) {
    if (param_2[7] == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c36e8,0x85);
      FUN_00797b80(uVar1);
      FUN_00797a40();
    }
    param_2[7] = param_2[7] + param_1;
    return param_2;
  }
  puVar2 = *(undefined4 **)(in_ECX + 0x4014);
  *(int *)(in_ECX + 0x400c) = *(int *)(in_ECX + 0x400c) + 1;
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = operator_new(0x20);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      *puVar2 = 0;
    }
    puVar2[6] = *(undefined4 *)(in_ECX + 0x4010);
    *(undefined4 **)(in_ECX + 0x4010) = puVar2;
  }
  else {
    *(undefined4 *)(in_ECX + 0x4014) = puVar2[5];
  }
  puVar2[5] = 0;
  puVar2[7] = param_1;
  return puVar2;
}


// ==== FUN_005defa0 @ 0x005defa0 ====

void FUN_005defa0(byte param_1)

{
  void *in_ECX;
  
  FUN_005dedb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005defc0 @ 0x005defc0 ====

void FUN_005defc0(byte param_1)

{
  void *in_ECX;
  
  FUN_005dedd0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005defe0 @ 0x005defe0 ====

void FUN_005defe0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983078;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3774;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c376c;
  _eh_vector_constructor_iterator_(in_ECX + 2,0x20,0x200,FUN_00607500,FUN_006ef6d0);
  in_ECX[0x1002] = 0;
  in_ECX[0x1002] = in_ECX[0x1002] + 0x200;
  in_ECX[0x1005] = in_ECX + 2;
  in_ECX[0x1003] = 0;
  in_ECX[0x1004] = 0;
  iVar2 = 0x1ff;
  puVar1 = in_ECX;
  do {
    puVar1[7] = puVar1 + 10;
    puVar1[8] = 0;
    puVar1[9] = 0;
    iVar2 = iVar2 + -1;
    puVar1 = puVar1 + 8;
  } while (iVar2 != 0);
  in_ECX[0xfff] = 0;
  in_ECX[0x1000] = 0;
  in_ECX[0x1001] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005df090 @ 0x005df090 ====

void FUN_005df090(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983098;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c378c;
  FUN_005defe0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005df0f0 @ 0x005df0f0 ====

void FUN_005df0f0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005df110(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005df110 @ 0x005df110 ====

void FUN_005df110(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005df110(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005df110(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005df150 @ 0x005df150 ====

void FUN_005df150(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005df170(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005df170 @ 0x005df170 ====

void FUN_005df170(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005df170(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005df170(param_1[3]);
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


// ==== FUN_005df1e0 @ 0x005df1e0 ====

void FUN_005df1e0(byte param_1)

{
  void *in_ECX;
  
  FUN_005df200();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005df200 @ 0x005df200 ====

void FUN_005df200(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009830c3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c378c;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005df170(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005dedd0();
  *in_ECX = &PTR_FUN_009c362c;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005df270 @ 0x005df270 ====

void FUN_005df270(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c37e4;
  return;
}


// ==== FUN_005df280 @ 0x005df280 ====

void FUN_005df280(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c37e4;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005df2a0 @ 0x005df2a0 ====

void FUN_005df2a0(undefined4 *param_1)

{
  undefined4 *in_ECX;
  int iVar1;
  
  for (iVar1 = 0x14; in_ECX = in_ECX + 1, iVar1 != 0; iVar1 = iVar1 + -1) {
    *in_ECX = *param_1;
    param_1 = param_1 + 1;
  }
  return;
}


// ==== FUN_005df2c0 @ 0x005df2c0 ====

int FUN_005df2c0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}


// ==== FUN_005df2d0 @ 0x005df2d0 ====

void FUN_005df2d0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009830d8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3808;
  local_4 = 0;
  if ((undefined4 *)in_ECX[0x15] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[0x15])(1);
  }
  in_ECX[0x15] = 0;
  *in_ECX = &PTR_FUN_009c37e4;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005df330 @ 0x005df330 ====

void FUN_005df330(undefined2 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(*(int *)(in_ECX + 0x54) + 0x68);
  *piVar1 = *piVar1 + 1;
  *(undefined2 *)(*(int *)(in_ECX + 0x54) + 2 + *(int *)(*(int *)(in_ECX + 0x54) + 0x68) * 2) =
       param_1;
  return;
}


// ==== FUN_005df350 @ 0x005df350 ====

undefined4 FUN_005df350(int param_1)

{
  int in_ECX;
  
  return CONCAT22((short)((uint)*(int *)(in_ECX + 0x54) >> 0x10),
                  *(undefined2 *)(*(int *)(in_ECX + 0x54) + 4 + param_1 * 2));
}


// ==== FUN_005df360 @ 0x005df360 ====

undefined4 FUN_005df360(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x54) + 0x68);
}


// ==== FUN_005df370 @ 0x005df370 ====

void FUN_005df370(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009830ea;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3808;
  FUN_004761a0();
  FUN_00797a50(in_ECX + 1,0,0x50);
  puVar1 = operator_new(0x6c);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009c3800;
    puVar1[0x1a] = 0;
  }
  in_ECX[0x15] = puVar1;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005df3f0 @ 0x005df3f0 ====

void FUN_005df3f0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3800;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005df410 @ 0x005df410 ====

void FUN_005df410(byte param_1)

{
  void *in_ECX;
  
  FUN_005df2d0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005df430 @ 0x005df430 ====

void FUN_005df430(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3868;
  return;
}


// ==== FUN_005df440 @ 0x005df440 ====

void FUN_005df440(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3868;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005df460 @ 0x005df460 ====

void FUN_005df460(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3878;
  return;
}


// ==== FUN_005df470 @ 0x005df470 ====

void FUN_005df470(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3894;
  return;
}


// ==== FUN_005df480 @ 0x005df480 ====

void FUN_005df480(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c38ec;
  return;
}


// ==== FUN_005df490 @ 0x005df490 ====

void FUN_005df490(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3878;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005df4b0 @ 0x005df4b0 ====

void FUN_005df4b0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3894;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005df4d0 @ 0x005df4d0 ====

void FUN_005df4d0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c38ec;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005df4f0 @ 0x005df4f0 ====

void FUN_005df4f0(void)

{
  int *piVar1;
  undefined4 *in_ECX;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983108;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *in_ECX = &PTR_FUN_009c3904;
  local_4 = 0;
  piVar1 = (int *)(**(code **)(*(int *)in_ECX[2] + 8))();
  if (piVar1 != (int *)0x0) {
    _free(*(void **)(*piVar1 + 4));
    return;
  }
  if ((undefined4 *)in_ECX[2] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[2])(1);
  }
  in_ECX[2] = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c3868;
  ExceptionList = pvStack_c;
  return;
}


// ==== FUN_005df590 @ 0x005df590 ====

int FUN_005df590(ushort param_1,ushort param_2)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 8))();
  while( true ) {
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    iVar1 = *(int *)(*piVar2 + 4);
    if (((iVar1 != 0) && (*(int *)(iVar1 + 4) <= (int)((uint)param_2 - (uint)param_1))) &&
       ((int)((uint)param_2 - (uint)param_1) <= *(int *)(iVar1 + 8))) break;
    piVar2 = (int *)(**(code **)(**(int **)(in_ECX + 8) + 0x48))(piVar2);
  }
  return iVar1;
}


// ==== FUN_005df5e0 @ 0x005df5e0 ====

void FUN_005df5e0(void)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint auStack_10c [2];
  undefined2 *puStack_4;
  
  auStack_10c[1] = 0;
  auStack_10c[0] = 1;
  puVar1 = (undefined2 *)(**(code **)(**(int **)(in_ECX + 4) + 0xc))();
  *puVar1 = *puStack_4;
  *(undefined2 **)(puVar1 + 2) = puStack_4;
  iVar2 = (**(code **)(**(int **)(in_ECX + 8) + 0x28))(puVar1);
  if (iVar2 != 0) {
    auStack_10c[0] = auStack_10c[0] & 0xffffff00;
    uVar3 = FUN_0044a580(auStack_10c,s_File___s__Line___d_009c3850,
                         s___Support_LevelCap_Flyweight_Pro_009c3824,0x52);
    FUN_00797b80(uVar3);
    FUN_00797a40();
  }
  return;
}


// ==== FUN_005df650 @ 0x005df650 ====

void FUN_005df650(void)

{
  void *pvVar1;
  undefined4 uVar2;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_00983130;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3904;
  pvVar1 = operator_new(0x1418);
  local_4._0_1_ = 1;
  if (pvVar1 == (void *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_005df740();
  }
  local_4 = (uint)local_4._1_3_ << 8;
  in_ECX[1] = uVar2;
  pvVar1 = operator_new(0x2028);
  local_4 = CONCAT31(local_4._1_3_,2);
  if (pvVar1 == (void *)0x0) {
    in_ECX[2] = 0;
    ExceptionList = local_c;
    return;
  }
  uVar2 = FUN_005dfb70(in_ECX[1]);
  in_ECX[2] = uVar2;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005df700 @ 0x005df700 ====

void FUN_005df700(byte param_1)

{
  void *in_ECX;
  
  FUN_005df4f0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005df720 @ 0x005df720 ====

void FUN_005df720(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3914;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x14,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_005df740 @ 0x005df740 ====

void FUN_005df740(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983148;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c391c;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c3914;
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


// ==== FUN_005df7f0 @ 0x005df7f0 ====

void * FUN_005df7f0(int param_1,void *param_2)

{
  undefined4 uVar1;
  void *pvVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != (void *)0x0) {
    if (*(int *)((int)param_2 + 0x10) == 0) {
      local_100[0] = 0;
      uVar1 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3930,0x85);
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


// ==== FUN_005df8a0 @ 0x005df8a0 ====

undefined4 FUN_005df8a0(uint param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined1 local_100 [256];
  
  if (param_2 != 0) {
    if (*(uint *)(param_2 + 0x10) < param_1) {
      local_100[0] = 0;
      uVar2 = FUN_0044a580(local_100,s_File___s__Line___d_0099f0a0,
                           s_d__usa_24_0_1_2__develop_share_l_009c3930,0xa9);
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


// ==== FUN_005df920 @ 0x005df920 ====

void FUN_005df920(byte param_1)

{
  void *in_ECX;
  
  FUN_005df720();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005df940 @ 0x005df940 ====

void FUN_005df940(byte param_1)

{
  void *in_ECX;
  
  FUN_005df960();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005df960 @ 0x005df960 ====

void FUN_005df960(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983173;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c391c;
  local_4 = 1;
  if ((void *)in_ECX[0x504] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c3914;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x14,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c3878;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x504]);
  return;
}


// ==== FUN_005df9e0 @ 0x005df9e0 ====

void FUN_005df9e0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c39ac;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x100,FUN_006ef6d0);
  return;
}


// ==== FUN_005dfa00 @ 0x005dfa00 ====

void FUN_005dfa00(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983193;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c39b4;
  local_4 = 1;
  if ((void *)in_ECX[0x804] == (void *)0x0) {
    local_4 = 0;
    in_ECX[1] = &PTR_FUN_009c39ac;
    _eh_vector_destructor_iterator_(in_ECX + 2,0x20,0x100,FUN_006ef6d0);
    *in_ECX = &PTR_FUN_009c38ec;
    ExceptionList = local_c;
    return;
  }
  _free((void *)in_ECX[0x804]);
  return;
}


// ==== FUN_005dfa80 @ 0x005dfa80 ====

void FUN_005dfa80(byte param_1)

{
  void *in_ECX;
  
  FUN_005df9e0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005dfaa0 @ 0x005dfaa0 ====

void FUN_005dfaa0(byte param_1)

{
  void *in_ECX;
  
  FUN_005dfa00();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005dfac0 @ 0x005dfac0 ====

void FUN_005dfac0(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  int iVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009831a8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c39b4;
  local_4 = 0;
  in_ECX[1] = &PTR_FUN_009c39ac;
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


// ==== FUN_005dfb70 @ 0x005dfb70 ====

void FUN_005dfb70(undefined4 param_1)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_009831c8;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c39cc;
  FUN_005dfac0();
  in_ECX[2] = param_1;
  in_ECX[1] = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005dfbd0 @ 0x005dfbd0 ====

void FUN_005dfbd0(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005dfbf0(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005dfbf0 @ 0x005dfbf0 ====

void FUN_005dfbf0(int param_1)

{
  int in_ECX;
  
  if (*(int *)(param_1 + 8) != 0) {
    FUN_005dfbf0(*(int *)(param_1 + 8));
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    FUN_005dfbf0(*(int *)(param_1 + 0xc));
  }
  (**(code **)(*(int *)(in_ECX + 0x10) + 0x10))(1,param_1);
  return;
}


// ==== FUN_005dfc30 @ 0x005dfc30 ====

void FUN_005dfc30(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 4) != 0) {
    FUN_005dfc50(*(int *)(in_ECX + 4));
    *(undefined4 *)(in_ECX + 4) = 0;
  }
  return;
}


// ==== FUN_005dfc50 @ 0x005dfc50 ====

void FUN_005dfc50(undefined4 *param_1)

{
  void *_Memory;
  int in_ECX;
  
  if (param_1[2] != 0) {
    FUN_005dfc50(param_1[2]);
  }
  if (param_1[3] != 0) {
    FUN_005dfc50(param_1[3]);
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


// ==== FUN_005dfcc0 @ 0x005dfcc0 ====

void FUN_005dfcc0(byte param_1)

{
  void *in_ECX;
  
  FUN_005dfce0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005dfce0 @ 0x005dfce0 ====

void FUN_005dfce0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  uint local_4;
  
  puStack_8 = &LAB_009831f3;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c39cc;
  local_4 = 1;
  if (in_ECX[1] != 0) {
    FUN_005dfc50(in_ECX[1]);
    in_ECX[1] = 0;
  }
  local_4 = local_4 & 0xffffff00;
  FUN_005dfa00();
  *in_ECX = &PTR_FUN_009c3894;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005dfd50 @ 0x005dfd50 ====

void FUN_005dfd50(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3a24;
  return;
}


// ==== FUN_005dfd60 @ 0x005dfd60 ====

void FUN_005dfd60(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3a24;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005dfd80 @ 0x005dfd80 ====

void FUN_005dfd80(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 8) = param_1;
  return;
}


// ==== FUN_005dfd90 @ 0x005dfd90 ====

undefined4 FUN_005dfd90(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 8);
}


// ==== FUN_005dfda0 @ 0x005dfda0 ====

void FUN_005dfda0(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc) = param_1;
  return;
}


// ==== FUN_005dfdb0 @ 0x005dfdb0 ====

undefined4 FUN_005dfdb0(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xc);
}


// ==== FUN_005dfdc0 @ 0x005dfdc0 ====

void FUN_005dfdc0(undefined1 param_1)

{
  int in_ECX;
  
  *(undefined1 *)(in_ECX + 0x10) = param_1;
  return;
}


// ==== FUN_005dfdd0 @ 0x005dfdd0 ====

undefined1 FUN_005dfdd0(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10);
}


// ==== FUN_005dfde0 @ 0x005dfde0 ====

void FUN_005dfde0(void)

{
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983208;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3a50;
  local_4 = 0;
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  in_ECX[1] = 0;
  *in_ECX = &PTR_FUN_009c3a24;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005dfe40 @ 0x005dfe40 ====

undefined4 FUN_005dfe40(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 4) + 0x404);
}


// ==== FUN_005dfe50 @ 0x005dfe50 ====

int FUN_005dfe50(ushort param_1)

{
  int in_ECX;
  
  return (uint)param_1 * 0x20 + 4 + *(int *)(in_ECX + 4);
}


// ==== FUN_005dfe70 @ 0x005dfe70 ====

void FUN_005dfe70(void)

{
  undefined4 *puVar1;
  undefined4 *in_ECX;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  puStack_8 = &LAB_00983225;
  local_c = ExceptionList;
  local_4 = 0;
  ExceptionList = &local_c;
  *in_ECX = &PTR_FUN_009c3a50;
  puVar1 = operator_new(0x408);
  local_4 = CONCAT31(local_4._1_3_,1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR_FUN_009c3a7c;
    _eh_vector_constructor_iterator_(puVar1 + 1,0x20,0x20,FUN_00479840,FUN_006ef6d0);
    puVar1[0x101] = 0;
  }
  in_ECX[1] = puVar1;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  *(undefined1 *)(in_ECX + 4) = 0;
  ExceptionList = local_c;
  return;
}


// ==== FUN_005dff00 @ 0x005dff00 ====

void FUN_005dff00(void)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(*(int *)(in_ECX + 4) + 0x404);
  *piVar1 = *piVar1 + 1;
  FUN_005dff50();
  return;
}


// ==== FUN_005dff30 @ 0x005dff30 ====

void FUN_005dff30(byte param_1)

{
  void *in_ECX;
  
  FUN_005dfde0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005dff50 @ 0x005dff50 ====

void FUN_005dff50(undefined2 *param_1)

{
  char cVar1;
  undefined2 *in_ECX;
  uint uVar2;
  
  *in_ECX = *param_1;
  uVar2 = 0;
  do {
    cVar1 = *(char *)((int)param_1 + uVar2 + 2);
    *(char *)(uVar2 + 2 + (int)in_ECX) = cVar1;
    if (cVar1 == '\0') goto LAB_005dff78;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x19);
  *(undefined1 *)(in_ECX + 1) = 0;
LAB_005dff78:
  in_ECX[0xe] = param_1[0xe];
  in_ECX[0xf] = param_1[0xf];
  return;
}


// ==== FUN_005dff90 @ 0x005dff90 ====

void FUN_005dff90(byte param_1)

{
  void *in_ECX;
  
  FUN_005dffb0();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_005dffb0 @ 0x005dffb0 ====

void FUN_005dffb0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3a7c;
  _eh_vector_destructor_iterator_(in_ECX + 1,0x20,0x20,FUN_006ef6d0);
  return;
}


// ==== FUN_005dffd0 @ 0x005dffd0 ====

void FUN_005dffd0(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3a84;
  return;
}


// ==== FUN_005dffe0 @ 0x005dffe0 ====

void FUN_005dffe0(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_009c3a84;
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== __break @ 0x005dffff ====

void __break(void)

{
  code *pcVar1;
  
  pcVar1 = (code *)swi(3);
  (*pcVar1)();
  return;
}


