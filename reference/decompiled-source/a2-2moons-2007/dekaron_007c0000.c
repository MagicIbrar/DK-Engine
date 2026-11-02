// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x7c0000-0x7cffff

// ==== FUN_007c0090 @ 0x007c0090 ====

void FUN_007c0090(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *puVar9;
  uint uVar10;
  int local_10;
  int local_c;
  
  iVar1 = param_1;
  do {
    iVar8 = (param_3 + 1) * 0x10 + *(int *)(iVar1 + 0xc);
    iVar5 = iVar8 + -0x20;
    param_1 = 2;
    if (((*(int *)(iVar8 + -0x20) == 4) || (iVar2 = FUN_007bf890(iVar1,iVar5), iVar2 != 0)) &&
       ((*(int *)(iVar8 + -0x10) == 4 || (iVar2 = FUN_007bf890(iVar1,iVar8 + -0x10), iVar2 != 0))))
    {
      iVar5 = *(int *)(*(int *)(iVar8 + -8) + 0xc);
      if (iVar5 != 0) {
        uVar10 = *(int *)(*(int *)(iVar8 + -0x18) + 0xc) + iVar5;
        if (2 < param_2) {
          piVar3 = (int *)(iVar8 + -0x30);
          do {
            if ((*piVar3 != 4) && (iVar5 = FUN_007bf890(iVar1,piVar3), iVar5 == 0)) break;
            uVar10 = uVar10 + *(int *)(piVar3[2] + 0xc);
            param_1 = param_1 + 1;
            piVar3 = piVar3 + -4;
          } while (param_1 < param_2);
        }
        if (0xfffffffd < uVar10) {
          FUN_007be950(iVar1,s_string_size_overflow_009fe460);
        }
        iVar5 = FUN_007c2e40(iVar1,*(int *)(iVar1 + 0x10) + 0x18,uVar10);
        local_10 = 0;
        if (0 < param_1) {
          piVar3 = (int *)(iVar8 + param_1 * -0x10 + 8);
          local_c = param_1;
          do {
            uVar10 = *(uint *)(*piVar3 + 0xc);
            puVar9 = (undefined4 *)(*piVar3 + 0x10);
            puVar4 = (undefined4 *)(local_10 + iVar5);
            for (uVar7 = uVar10 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
              *puVar4 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar4 = puVar4 + 1;
            }
            for (uVar7 = uVar10 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
              *(undefined1 *)puVar4 = *(undefined1 *)puVar9;
              puVar9 = (undefined4 *)((int)puVar9 + 1);
              puVar4 = (undefined4 *)((int)puVar4 + 1);
            }
            local_10 = local_10 + uVar10;
            piVar3 = piVar3 + 4;
            local_c = local_c + -1;
          } while (local_c != 0);
        }
        puVar9 = (undefined4 *)(iVar8 + param_1 * -0x10);
        *puVar9 = 4;
        uVar6 = FUN_007c1d70(iVar1,iVar5,local_10);
        puVar9[2] = uVar6;
      }
    }
    else {
      iVar2 = *(int *)(iVar1 + 0x1c);
      piVar3 = (int *)FUN_007bf7f0(iVar1,iVar5,0xd);
      if (*piVar3 == 0) {
        piVar3 = (int *)FUN_007bf7f0(iVar1,iVar8 + -0x10,0xd);
      }
      if (*piVar3 == 6) {
        FUN_007bf9e0();
        puVar9 = *(undefined4 **)(iVar1 + 8);
        puVar4 = (undefined4 *)(*(int *)(iVar1 + 0x1c) + (iVar8 - iVar2) + -0x20);
        *puVar4 = *puVar9;
        puVar4[2] = puVar9[2];
        puVar4[3] = puVar9[3];
      }
      else {
        FUN_007bec00(iVar1,iVar5,iVar8 + -0x10);
      }
    }
    param_2 = param_2 + (1 - param_1);
    param_3 = param_3 + (1 - param_1);
    if (param_2 < 2) {
      return;
    }
  } while( true );
}


// ==== FUN_007c0280 @ 0x007c0280 ====

void FUN_007c0280(int *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *in_ECX;
  int in_EDX;
  int *local_34;
  int *local_30 [2];
  int local_28 [4];
  int local_18 [5];
  
  if (*in_EAX == 3) {
    local_34 = in_EAX;
LAB_007c02e0:
    if (*param_1 != 3) {
      if ((*param_1 != 4) || (iVar2 = FUN_007c1710(param_1[2] + 0x10,local_30), iVar2 == 0))
      goto LAB_007c03fe;
      local_18[0] = 3;
      param_1 = local_18;
    }
    switch(param_2) {
    case 5:
      *in_ECX = 3;
      *(double *)(in_ECX + 2) = *(double *)(param_1 + 2) + *(double *)(local_34 + 2);
      return;
    case 6:
      *in_ECX = 3;
      *(double *)(in_ECX + 2) = *(double *)(local_34 + 2) - *(double *)(param_1 + 2);
      return;
    case 7:
      *in_ECX = 3;
      *(double *)(in_ECX + 2) = *(double *)(param_1 + 2) * *(double *)(local_34 + 2);
      return;
    case 8:
      *in_ECX = 3;
      *(double *)(in_ECX + 2) = *(double *)(local_34 + 2) / *(double *)(param_1 + 2);
      return;
    case 9:
      local_30[0] = (int *)FUN_007c2670(*(undefined4 *)(in_EDX + 0x48),
                                        *(undefined4 *)(*(int *)(in_EDX + 0x10) + 0xa4));
      iVar2 = *(int *)(in_EDX + 0x1c);
      if (*local_30[0] != 6) {
        FUN_007be950();
      }
      FUN_007bf9e0();
      puVar1 = *(undefined4 **)(in_EDX + 8);
      puVar3 = (undefined4 *)((int)in_ECX + (*(int *)(in_EDX + 0x1c) - iVar2));
      *puVar3 = *puVar1;
      puVar3[2] = puVar1[2];
      puVar3[3] = puVar1[3];
      return;
    }
  }
  else {
    if ((*in_EAX == 4) && (iVar2 = FUN_007c1710(in_EAX[2] + 0x10,local_30), iVar2 != 0)) {
      local_34 = local_28;
      local_28[0] = 3;
      goto LAB_007c02e0;
    }
LAB_007c03fe:
    iVar2 = FUN_007bfcb0(param_1,param_2);
    if (iVar2 == 0) {
      FUN_007bec20();
    }
  }
  return;
}


// ==== FUN_007c0440 @ 0x007c0440 ====

undefined4 * FUN_007c0440(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(*(int *)(param_2 + 8) + 8);
  if ((*(byte *)(iVar1 + 6) & 1) == 0) {
    piVar2 = (int *)FUN_007bf7c0(iVar1,0,*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x80));
    if (piVar2 != (int *)0x0) {
      if (*piVar2 == 6) {
        FUN_007bf9e0();
        return *(undefined4 **)(param_1 + 8);
      }
      puVar3 = (undefined4 *)FUN_007bfb60(param_1,piVar2,param_3,param_4);
      return puVar3;
    }
  }
  return &DAT_009fe508;
}


// ==== FUN_007c04b0 @ 0x007c04b0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_007c04b0(int param_1)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  int *piVar12;
  int *piVar13;
  int iVar14;
  uint *local_54;
  int *local_50;
  int *local_4c;
  int local_48;
  int *local_44;
  double local_40;
  double local_38;
  undefined8 local_30;
  undefined8 local_28;
  undefined8 local_20;
  int local_18 [2];
  undefined8 local_10;
  
LAB_007c04c0:
  *(uint ***)(*(int *)(param_1 + 0x14) + 0x10) = &local_54;
  if ((*(byte *)(param_1 + 0x30) & 1) != 0) {
    FUN_007bd4a0(param_1,0,0xffffffff);
  }
LAB_007c04e0:
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 8) = 2;
  local_54 = *(uint **)(*(int *)(param_1 + 0x14) + 0xc);
  local_48 = *(int *)(*(int *)(param_1 + 0xc) + -8);
  local_4c = *(int **)(*(int *)(local_48 + 0xc) + 8);
switchD_007c0564_default:
  uVar6 = *local_54;
  local_54 = local_54 + 1;
  if ((*(byte *)(param_1 + 0x30) & 0xc) != 0) {
    piVar13 = (int *)(param_1 + 0x38);
    *piVar13 = *piVar13 + -1;
    if (((*piVar13 == 0) || ((*(byte *)(param_1 + 0x30) & 4) != 0)) &&
       (FUN_007bf920(), (*(byte *)(*(int *)(param_1 + 0x14) + 8) & 0x10) != 0)) {
      *(uint **)(*(int *)(param_1 + 0x14) + 0xc) = local_54 + -1;
      *(undefined4 *)(*(int *)(param_1 + 0x14) + 8) = 0x18;
      return (int *)0x0;
    }
  }
  local_50 = *(int **)(param_1 + 0xc);
  local_40 = (double)CONCAT44(local_40._4_4_,uVar6 >> 0x18);
  local_44 = (int *)((uVar6 >> 0x18) * 0x10);
  piVar13 = (int *)((int)local_44 + (int)local_50);
  switch(uVar6 & 0x3f) {
  case 0:
    uVar6 = uVar6 >> 0xf & 0x1ff;
    piVar3 = local_50;
    goto LAB_007c0578;
  case 1:
    uVar6 = uVar6 >> 6 & 0x3ffff;
    piVar3 = local_4c;
LAB_007c0578:
    piVar3 = piVar3 + uVar6 * 4;
    *piVar13 = *piVar3;
    piVar13[2] = piVar3[2];
    piVar13[3] = piVar3[3];
    goto switchD_007c0564_default;
  case 2:
    *piVar13 = 1;
    piVar13[2] = uVar6 >> 0xf & 0x1ff;
    if ((uVar6 & 0x7fc0) != 0) {
      local_54 = local_54 + 1;
    }
    goto switchD_007c0564_default;
  case 3:
    piVar3 = local_50 + (uVar6 >> 0xf & 0x1ff) * 4;
    do {
      *piVar3 = 0;
      piVar3 = piVar3 + -4;
    } while (piVar13 <= piVar3);
    goto switchD_007c0564_default;
  case 4:
    piVar3 = *(int **)(*(int *)(local_48 + 0x20 + (uVar6 >> 0xf & 0x1ff) * 4) + 8);
    *piVar13 = *piVar3;
    piVar13[2] = piVar3[2];
    piVar13[3] = piVar3[3];
    goto switchD_007c0564_default;
  case 5:
    piVar12 = local_4c + (uVar6 >> 6 & 0x3ffff) * 4;
    piVar3 = (int *)FUN_007c2670(*(undefined4 *)(local_48 + 0x18),piVar12[2]);
    if (*piVar3 == 0) {
      local_38 = (double)CONCAT44(local_38._4_4_,local_48 + 0x10);
      iVar5 = *(int *)(*(int *)(local_48 + 0x18) + 8);
      if (((*(byte *)(iVar5 + 6) & 1) == 0) &&
         (piVar13 = (int *)FUN_007bf7c0(iVar5,0,*(undefined4 *)(*(int *)(param_1 + 0x10) + 0x80)),
         piVar13 != (int *)0x0)) {
        if (*piVar13 == 6) {
          FUN_007bf9e0();
          piVar3 = *(int **)(param_1 + 8);
        }
        else {
          if (*piVar13 != 5) goto LAB_007c06d5;
          piVar3 = (int *)FUN_007c26b0(piVar13[2],piVar12);
          iVar5 = *piVar3;
joined_r0x007c07c3:
          if (iVar5 == 0) {
            piVar3 = (int *)FUN_007c0440(param_1,piVar13,piVar12,1);
          }
        }
      }
      else {
        piVar3 = &DAT_009fe508;
      }
      goto LAB_007c06ea;
    }
    *piVar13 = *piVar3;
    piVar13[2] = piVar3[2];
    piVar13[3] = piVar3[3];
    goto switchD_007c0564_default;
  case 6:
    piVar3 = local_50 + (uVar6 >> 0xf & 0x1ff) * 4;
    uVar6 = uVar6 >> 6 & 0x1ff;
    if (0xf9 < uVar6) {
      uVar6 = uVar6 - 0xfa;
      local_50 = local_4c;
    }
    piVar12 = local_50 + uVar6 * 4;
    local_50 = piVar3;
    if (*piVar3 == 5) {
      piVar3 = (int *)FUN_007c26b0(piVar3[2],piVar12);
      if (*piVar3 == 0) {
        if (((*(byte *)(*(int *)(local_50[2] + 8) + 6) & 1) == 0) &&
           (piVar13 = (int *)FUN_007bf7c0(*(int *)(local_50[2] + 8),0,
                                          *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x80)),
           piVar13 != (int *)0x0)) goto LAB_007c09ea;
        piVar3 = &DAT_009fe508;
        goto LAB_007c06ea;
      }
      *piVar13 = *piVar3;
      piVar13[2] = piVar3[2];
      piVar13[3] = piVar3[3];
      goto switchD_007c0564_default;
    }
    piVar13 = (int *)FUN_007bf7f0(param_1,piVar3,0);
    if (*piVar13 == 0) {
      FUN_007beb70(param_1,local_50,s_index_009fe430);
    }
    iVar5 = *piVar13;
    if (iVar5 != 6) goto LAB_007c07a9;
    FUN_007bf9e0();
    piVar3 = *(int **)(param_1 + 8);
    goto LAB_007c06ea;
  case 7:
    FUN_007bfbd0(param_1,local_48 + 0x10,local_4c + (uVar6 >> 6 & 0x3ffff) * 4,piVar13);
    goto switchD_007c0564_default;
  case 8:
    piVar3 = *(int **)(*(int *)(local_48 + 0x20 + (uVar6 >> 0xf & 0x1ff) * 4) + 8);
    *piVar3 = *piVar13;
    piVar3[2] = piVar13[2];
    piVar3[3] = piVar13[3];
    goto switchD_007c0564_default;
  case 9:
    uVar1 = uVar6 >> 6 & 0x1ff;
    if (uVar1 < 0xfa) {
      piVar3 = local_50;
    }
    else {
      uVar1 = uVar1 - 0xfa;
      piVar3 = local_4c;
    }
    uVar6 = uVar6 >> 0xf & 0x1ff;
    if (uVar6 < 0xfa) {
      piVar12 = local_50;
    }
    else {
      uVar6 = uVar6 - 0xfa;
      piVar12 = local_4c;
    }
    FUN_007bfbd0(param_1,piVar13,piVar12 + uVar6 * 4,piVar3 + uVar1 * 4);
    goto switchD_007c0564_default;
  case 10:
    *piVar13 = 5;
    iVar5 = FUN_007c24d0(param_1,(uVar6 >> 0xf & 7) <<
                                 ((byte)((int)(uVar6 >> 0xf & 0x1ff) >> 3) & 0x1f),
                         uVar6 >> 6 & 0x1ff);
    piVar13[2] = iVar5;
    goto LAB_007c08f4;
  case 0xb:
    piVar3 = local_50 + (uVar6 >> 0xf & 0x1ff) * 4;
    uVar6 = uVar6 >> 6 & 0x1ff;
    if (0xf9 < uVar6) {
      uVar6 = uVar6 - 0xfa;
      local_50 = local_4c;
    }
    piVar12 = local_50 + uVar6 * 4;
    if (*piVar12 != 4) {
      return (int *)0x0;
    }
    piVar13[4] = *piVar3;
    piVar13[6] = piVar3[2];
    piVar13[7] = piVar3[3];
    local_50 = piVar3;
    if (*piVar3 == 5) {
      piVar3 = (int *)FUN_007c2670(piVar3[2],piVar12[2]);
      if (*piVar3 == 0) {
        puVar4 = (undefined4 *)FUN_007c0440(param_1,local_50,piVar12,0);
        puVar8 = (undefined4 *)(*(int *)(param_1 + 0xc) + (int)local_44);
        *puVar8 = *puVar4;
        puVar8[2] = puVar4[2];
        puVar8[3] = puVar4[3];
      }
      else {
        *piVar13 = *piVar3;
        piVar13[2] = piVar3[2];
        piVar13[3] = piVar3[3];
      }
      goto switchD_007c0564_default;
    }
    piVar13 = (int *)FUN_007bf7f0(param_1,piVar3,0);
    if (*piVar13 == 0) {
      FUN_007beb70(param_1,local_50,s_index_009fe430);
    }
LAB_007c09ea:
    iVar5 = *piVar13;
    if (iVar5 == 6) {
      FUN_007bf9e0();
      piVar3 = *(int **)(param_1 + 8);
    }
    else {
LAB_007c07a9:
      if (iVar5 == 5) {
        piVar3 = (int *)FUN_007c26b0(piVar13[2],piVar12);
        iVar5 = *piVar3;
        goto joined_r0x007c07c3;
      }
LAB_007c06d5:
      piVar3 = (int *)FUN_007bfb00(piVar12,1);
    }
LAB_007c06ea:
    piVar13 = (int *)(*(int *)(param_1 + 0xc) + (int)local_44);
LAB_007c06f1:
    *piVar13 = *piVar3;
    piVar13[2] = piVar3[2];
    piVar13[3] = piVar3[3];
    goto switchD_007c0564_default;
  case 0xc:
    uVar1 = uVar6 >> 0xf & 0x1ff;
    if (uVar1 < 0xfa) {
      piVar3 = local_50;
    }
    else {
      uVar1 = uVar1 - 0xfa;
      piVar3 = local_4c;
    }
    uVar6 = uVar6 >> 6 & 0x1ff;
    if (uVar6 < 0xfa) {
      piVar12 = local_50 + uVar6 * 4;
    }
    else {
      piVar12 = local_4c + (uVar6 - 0xfa) * 4;
    }
    if ((piVar3[uVar1 * 4] == 3) && (*piVar12 == 3)) {
      *piVar13 = 3;
      *(double *)(piVar13 + 2) = *(double *)(piVar12 + 2) + *(double *)(piVar3 + uVar1 * 4 + 2);
    }
    else {
      FUN_007c0280(piVar12,5);
    }
    goto switchD_007c0564_default;
  case 0xd:
    uVar1 = uVar6 >> 0xf & 0x1ff;
    if (uVar1 < 0xfa) {
      piVar3 = local_50;
    }
    else {
      uVar1 = uVar1 - 0xfa;
      piVar3 = local_4c;
    }
    uVar6 = uVar6 >> 6 & 0x1ff;
    if (uVar6 < 0xfa) {
      piVar12 = local_50 + uVar6 * 4;
    }
    else {
      piVar12 = local_4c + (uVar6 - 0xfa) * 4;
    }
    if ((piVar3[uVar1 * 4] == 3) && (*piVar12 == 3)) {
      *piVar13 = 3;
      *(double *)(piVar13 + 2) = *(double *)(piVar3 + uVar1 * 4 + 2) - *(double *)(piVar12 + 2);
    }
    else {
      FUN_007c0280(piVar12,6);
    }
    goto switchD_007c0564_default;
  case 0xe:
    uVar1 = uVar6 >> 0xf & 0x1ff;
    if (uVar1 < 0xfa) {
      piVar3 = local_50;
    }
    else {
      uVar1 = uVar1 - 0xfa;
      piVar3 = local_4c;
    }
    uVar6 = uVar6 >> 6 & 0x1ff;
    if (uVar6 < 0xfa) {
      piVar12 = local_50 + uVar6 * 4;
    }
    else {
      piVar12 = local_4c + (uVar6 - 0xfa) * 4;
    }
    if ((piVar3[uVar1 * 4] == 3) && (*piVar12 == 3)) {
      *piVar13 = 3;
      *(double *)(piVar13 + 2) = *(double *)(piVar12 + 2) * *(double *)(piVar3 + uVar1 * 4 + 2);
    }
    else {
      FUN_007c0280(piVar12,7);
    }
    goto switchD_007c0564_default;
  case 0xf:
    uVar1 = uVar6 >> 0xf & 0x1ff;
    if (uVar1 < 0xfa) {
      piVar3 = local_50;
    }
    else {
      uVar1 = uVar1 - 0xfa;
      piVar3 = local_4c;
    }
    uVar6 = uVar6 >> 6 & 0x1ff;
    if (uVar6 < 0xfa) {
      piVar12 = local_50 + uVar6 * 4;
    }
    else {
      piVar12 = local_4c + (uVar6 - 0xfa) * 4;
    }
    if ((piVar3[uVar1 * 4] == 3) && (*piVar12 == 3)) {
      *piVar13 = 3;
      *(double *)(piVar13 + 2) = *(double *)(piVar3 + uVar1 * 4 + 2) / *(double *)(piVar12 + 2);
    }
    else {
      FUN_007c0280(piVar12,8);
    }
    goto switchD_007c0564_default;
  case 0x10:
    uVar6 = uVar6 >> 6 & 0x1ff;
    if (uVar6 < 0xfa) {
      piVar13 = local_50;
    }
    else {
      uVar6 = uVar6 - 0xfa;
      piVar13 = local_4c;
    }
    FUN_007c0280(piVar13 + uVar6 * 4,9);
    goto switchD_007c0564_default;
  case 0x11:
    uVar6 = uVar6 >> 0xf & 0x1ff;
    piVar3 = local_50 + uVar6 * 4;
    if (local_50[uVar6 * 4] == 3) {
LAB_007c0cc8:
      *piVar13 = 3;
      *(double *)(piVar13 + 2) = -*(double *)(piVar3 + 2);
    }
    else {
      if ((local_50[uVar6 * 4] == 4) &&
         (iVar5 = FUN_007c1710(piVar3[2] + 0x10,&local_30), iVar5 != 0)) {
        local_18[0] = 3;
        local_10 = local_30;
        piVar3 = local_18;
        goto LAB_007c0cc8;
      }
      iVar5 = *(int *)(param_1 + 0x1c);
      local_18[0] = 0;
      piVar12 = (int *)FUN_007bf7f0(param_1,piVar3,10);
      if (*piVar12 == 0) {
        piVar12 = (int *)FUN_007bf7f0(param_1,local_18,10);
      }
      if (*piVar12 == 6) {
        FUN_007bf9e0();
        piVar3 = *(int **)(param_1 + 8);
        piVar13 = (int *)((int)piVar13 + (*(int *)(param_1 + 0x1c) - iVar5));
        goto LAB_007c06f1;
      }
      FUN_007bec20(param_1,piVar3,local_18);
    }
    goto switchD_007c0564_default;
  case 0x12:
    iVar5 = local_50[(uVar6 >> 0xf & 0x1ff) * 4];
    if ((iVar5 == 0) || ((iVar5 == 1 && ((local_50 + (uVar6 >> 0xf & 0x1ff) * 4)[2] == 0)))) {
      *piVar13 = 1;
      piVar13[2] = 1;
    }
    else {
      *piVar13 = 1;
      piVar13[2] = 0;
    }
    goto switchD_007c0564_default;
  case 0x13:
    uVar1 = uVar6 >> 6 & 0x1ff;
    uVar6 = uVar6 >> 0xf & 0x1ff;
    FUN_007c0090(param_1,(uVar1 - uVar6) + 1,uVar1);
    iVar5 = *(int *)(param_1 + 0xc);
    iVar11 = uVar6 * 0x10;
    iVar14 = iVar11 + iVar5;
    *(undefined4 *)((int)local_44 + iVar5) = *(undefined4 *)(iVar11 + iVar5);
    *(undefined4 *)((int)local_44 + iVar5 + 8) = *(undefined4 *)(iVar14 + 8);
    *(undefined4 *)((int)local_44 + iVar5 + 0xc) = *(undefined4 *)(iVar14 + 0xc);
    goto LAB_007c08f4;
  case 0x14:
    local_54 = local_54 + ((uVar6 >> 6 & 0x3ffff) - 0x1ffff);
    goto switchD_007c0564_default;
  case 0x15:
    uVar1 = uVar6 >> 0xf & 0x1ff;
    if (uVar1 < 0xfa) {
      piVar13 = local_50;
      uVar10 = uVar1;
    }
    else {
      uVar10 = uVar1 - 0xfa;
      piVar13 = local_4c;
    }
    uVar6 = uVar6 >> 6 & 0x1ff;
    if (uVar6 < 0xfa) {
      uVar9 = uVar6;
      piVar3 = local_50;
    }
    else {
      uVar9 = uVar6 - 0xfa;
      piVar3 = local_4c;
    }
    if (piVar13[uVar10 * 4] == piVar3[uVar9 * 4]) {
      if (uVar6 < 0xfa) {
        piVar13 = local_50;
      }
      else {
        uVar6 = uVar6 - 0xfa;
        piVar13 = local_4c;
      }
      if (uVar1 < 0xfa) {
        piVar3 = local_50;
      }
      else {
        uVar1 = uVar1 - 0xfa;
        piVar3 = local_4c;
      }
      iVar5 = FUN_007bffb0(param_1,piVar3 + uVar1 * 4,piVar13 + uVar6 * 4);
      if (iVar5 == 0) goto LAB_007c0e88;
      iVar5 = 1;
    }
    else {
LAB_007c0e88:
      iVar5 = 0;
    }
    if ((undefined4 *)iVar5 != local_40._0_4_) {
      local_54 = local_54 + 1;
      goto switchD_007c0564_default;
    }
    break;
  case 0x16:
    uVar1 = uVar6 >> 6 & 0x1ff;
    if (uVar1 < 0xfa) {
      piVar13 = local_50;
    }
    else {
      uVar1 = uVar1 - 0xfa;
      piVar13 = local_4c;
    }
    uVar6 = uVar6 >> 0xf & 0x1ff;
    if (uVar6 < 0xfa) {
      piVar3 = local_50;
    }
    else {
      uVar6 = uVar6 - 0xfa;
      piVar3 = local_4c;
    }
    iVar5 = FUN_007bfe80(param_1,piVar3 + uVar6 * 4,piVar13 + uVar1 * 4);
    if ((undefined4 *)iVar5 != local_40._0_4_) {
      local_54 = local_54 + 1;
      goto switchD_007c0564_default;
    }
    break;
  case 0x17:
    iVar5 = FUN_007bff10(param_1);
    if ((undefined4 *)iVar5 != local_40._0_4_) {
      local_54 = local_54 + 1;
      goto switchD_007c0564_default;
    }
    break;
  case 0x18:
    piVar3 = local_50 + (uVar6 >> 0xf & 0x1ff) * 4;
    iVar5 = *piVar3;
    if ((iVar5 == 0) || ((iVar5 == 1 && (piVar3[2] == 0)))) {
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
    if (uVar1 == (uVar6 >> 6 & 0x1ff)) {
      local_54 = local_54 + 1;
      goto switchD_007c0564_default;
    }
    *piVar13 = iVar5;
    piVar13[2] = piVar3[2];
    piVar13[3] = piVar3[3];
    break;
  case 0x19:
  case 0x1a:
    uVar1 = uVar6 >> 0xf & 0x1ff;
    if (uVar1 != 0) {
      *(int **)(param_1 + 8) = piVar13 + uVar1 * 4;
    }
    local_38 = (double)CONCAT44(local_38._4_4_,(uVar6 >> 6 & 0x1ff) - 1);
    uVar1 = FUN_007bd750(param_1,piVar13);
    if (uVar1 == 0) {
      if (((byte)uVar6 & 0x3f) == 0x19) {
        *(uint **)(*(int *)(param_1 + 0x14) + -0xc) = local_54;
        *(undefined4 *)(*(int *)(param_1 + 0x14) + -0x10) = 0xc;
      }
      else {
        piVar13 = *(int **)(*(int *)(param_1 + 0x14) + -0x18);
        local_38 = (double)CONCAT44(local_38._4_4_,piVar13 + (uVar6 >> 0x18) * 4);
        local_50 = piVar13;
        if (*(int *)(param_1 + 0x50) != 0) {
          FUN_007c1f30(param_1,piVar13);
        }
        iVar5 = 0;
        if (local_38._0_4_ < *(int **)(param_1 + 8)) {
          piVar13 = piVar13 + -4;
          piVar3 = local_38._0_4_;
          do {
            *piVar13 = *piVar3;
            piVar13[2] = piVar3[2];
            piVar13[3] = piVar3[3];
            piVar3 = piVar3 + 4;
            iVar5 = iVar5 + 1;
            piVar13 = piVar13 + 4;
          } while (piVar3 < *(int **)(param_1 + 8));
          piVar13 = local_50;
        }
        *(int **)(param_1 + 8) = piVar13 + iVar5 * 4;
        *(int **)(*(int *)(param_1 + 0x14) + -0x14) = piVar13 + iVar5 * 4;
        *(undefined4 *)(*(int *)(param_1 + 0x14) + -0xc) =
             *(undefined4 *)(*(int *)(param_1 + 0x14) + 0xc);
        piVar13 = (int *)(*(int *)(param_1 + 0x14) + -4);
        *piVar13 = *piVar13 + 1;
        *(undefined4 *)(*(int *)(param_1 + 0x14) + -0x10) = 8;
        puVar4 = (undefined4 *)(*(int *)(param_1 + 0x14) + -0x18);
        *(undefined4 **)(param_1 + 0x14) = puVar4;
        *(undefined4 *)(param_1 + 0xc) = *puVar4;
      }
      goto LAB_007c04c0;
    }
    if (*(uint *)(param_1 + 8) < uVar1) {
      *(uint **)(*(int *)(param_1 + 0x14) + -0xc) = local_54;
      *(undefined4 *)(*(int *)(param_1 + 0x14) + -0x10) = 8;
      return (int *)0x0;
    }
    iVar5 = (int)local_38._0_4_;
    FUN_007bd950(param_1,local_38._0_4_,uVar1);
    if (-1 < iVar5) {
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 4);
    }
    goto switchD_007c0564_default;
  case 0x1b:
    goto switchD_007c0564_caseD_1b;
  case 0x1c:
    local_44 = piVar13 + 8;
    local_50 = piVar13 + 4;
    if (*piVar13 != 3) {
      FUN_007be950(param_1,s__for__initial_value_must_be_a_nu_009fe4e0);
    }
    if (*local_50 != 3) {
      if ((*local_50 == 4) && (iVar5 = FUN_007c1710(local_50[2] + 0x10,&local_28), iVar5 != 0)) {
        *(undefined8 *)(local_50 + 2) = local_28;
        *local_50 = 3;
      }
      else {
        local_50 = (int *)0x0;
        FUN_007be950(param_1,s__for__limit_must_be_a_number_009fe4c0);
      }
    }
    if (*local_44 != 3) {
      if ((*local_44 == 4) && (iVar5 = FUN_007c1710(local_44[2] + 0x10,&local_20), iVar5 != 0)) {
        *(undefined8 *)(local_44 + 2) = local_20;
        *local_44 = 3;
      }
      else {
        local_44 = (int *)0x0;
        FUN_007be950(param_1,s__for__step_must_be_a_number_009fe4a4);
      }
    }
    local_38 = *(double *)(local_44 + 2) + *(double *)(piVar13 + 2);
    local_40 = *(double *)(local_50 + 2);
    if (*(double *)(local_44 + 2) <= _DAT_0099d098) {
      if (local_38 < local_40) goto switchD_007c0564_default;
    }
    else if ((NAN(local_38) || NAN(local_40)) || local_38 < local_40 == (local_38 == local_40))
    goto switchD_007c0564_default;
    local_54 = local_54 + ((uVar6 >> 6 & 0x3ffff) - 0x1ffff);
    *(double *)(piVar13 + 2) = local_38;
    goto switchD_007c0564_default;
  case 0x1d:
    uVar6 = uVar6 >> 6 & 0x1ff;
    iVar11 = uVar6 + 1;
    iVar5 = uVar6 + 3;
    piVar13[iVar5 * 4] = *piVar13;
    piVar3 = piVar13 + iVar5 * 4;
    piVar3[2] = piVar13[2];
    piVar3[3] = piVar13[3];
    piVar3[4] = piVar13[4];
    piVar3[6] = piVar13[6];
    piVar3[7] = piVar13[7];
    piVar3[8] = piVar13[8];
    piVar3[10] = piVar13[10];
    piVar3[0xb] = piVar13[0xb];
    *(int **)(param_1 + 8) = piVar3 + 0xc;
    FUN_007bd9d0(param_1,piVar3,iVar11);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 4);
    piVar12 = (int *)(((int)local_40._0_4_ + 2) * 0x10 + *(int *)(param_1 + 0xc));
    piVar13 = piVar12 + iVar11 * 8;
    piVar3 = piVar12 + iVar11 * 4 + 2;
    iVar5 = iVar11;
    while( true ) {
      piVar13 = piVar13 + -4;
      piVar2 = piVar3 + -4;
      local_38 = (double)CONCAT44(local_38._4_4_,piVar13);
      piVar3[-6] = *piVar13;
      iVar5 = iVar5 + -1;
      *piVar2 = piVar2[iVar11 * 4];
      piVar3[-3] = piVar2[iVar11 * 4 + 1];
      if (iVar5 < 1) break;
      piVar3 = piVar2;
    }
    if (*piVar12 == 0) {
      local_54 = local_54 + 1;
    }
    else {
      local_54 = local_54 + ((*local_54 >> 6 & 0x3ffff) - 0x1fffe);
    }
    goto switchD_007c0564_default;
  case 0x1e:
    if (*piVar13 == 5) {
      piVar13[4] = 5;
      piVar13[6] = piVar13[2];
      piVar13[7] = piVar13[3];
      uVar7 = FUN_007c1d70(param_1,&DAT_009fdc24,4);
      piVar3 = (int *)FUN_007c2670(*(undefined4 *)(param_1 + 0x48),uVar7);
      *piVar13 = *piVar3;
      piVar13[2] = piVar3[2];
      piVar13[3] = piVar3[3];
    }
    local_54 = local_54 + ((uVar6 >> 6 & 0x3ffff) - 0x1ffff);
    goto switchD_007c0564_default;
  case 0x1f:
  case 0x20:
    if (*piVar13 != 5) {
      return (int *)0x0;
    }
    iVar5 = piVar13[2];
    local_38 = (double)CONCAT44(local_38._4_4_,iVar5);
    if ((uVar6 & 0x3f) == 0x1f) {
      iVar11 = (uVar6 >> 6 & 0x1f) + 1;
    }
    else {
      iVar11 = (*(int *)(param_1 + 8) - (int)piVar13 >> 4) + -1;
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 4);
    }
    local_44 = (int *)(uVar6 >> 6 & 0x3ffe0);
    if (0 < iVar11) {
      local_40 = (double)CONCAT44(local_40._4_4_,piVar13 + iVar11 * 4);
      do {
        puVar4 = (undefined4 *)FUN_007c2c90(param_1,iVar5,(int)local_44 + iVar11);
        *puVar4 = *local_40._0_4_;
        puVar4[2] = local_40._0_4_[2];
        iVar11 = iVar11 + -1;
        puVar4[3] = local_40._0_4_[3];
        local_40 = (double)CONCAT44(local_40._4_4_,local_40._0_4_ + -4);
      } while (0 < iVar11);
    }
    goto switchD_007c0564_default;
  case 0x21:
    FUN_007c1f30(param_1,piVar13);
    goto switchD_007c0564_default;
  case 0x22:
    iVar5 = *(int *)(*(int *)(*(int *)(local_48 + 0xc) + 0x10) + (uVar6 >> 6 & 0x3ffff) * 4);
    local_40 = (double)CONCAT44(local_40._4_4_,iVar5);
    piVar12 = (int *)(uint)*(byte *)(iVar5 + 0x44);
    iVar5 = FUN_007c1e80(param_1,piVar12,local_48 + 0x10);
    piVar3 = local_50;
    local_38 = (double)CONCAT44(local_38._4_4_,iVar5);
    *(undefined4 **)(iVar5 + 0xc) = local_40._0_4_;
    if (piVar12 != (int *)0x0) {
      local_40 = (double)CONCAT44(local_40._4_4_,iVar5 + 0x20);
      local_44 = piVar12;
      do {
        uVar6 = *local_54 >> 0xf & 0x1ff;
        if (((byte)*local_54 & 0x3f) == 4) {
          *local_40._0_4_ = *(undefined4 *)(local_48 + 0x20 + uVar6 * 4);
        }
        else {
          uVar7 = FUN_007c1ee0(param_1,piVar3 + uVar6 * 4);
          *local_40._0_4_ = uVar7;
        }
        local_40 = (double)CONCAT44(local_40._4_4_,(int)local_40._0_4_ + 4);
        local_54 = local_54 + 1;
        local_44 = (int *)((int)local_44 + -1);
      } while (local_44 != (int *)0x0);
    }
    *piVar13 = 6;
    piVar13[2] = (int)local_38._0_4_;
LAB_007c08f4:
    if (*(uint *)(*(int *)(param_1 + 0x10) + 0x20) <= *(uint *)(*(int *)(param_1 + 0x10) + 0x24)) {
      FUN_007bf6e0(param_1);
    }
  default:
    goto switchD_007c0564_default;
  }
  local_54 = local_54 + ((*local_54 >> 6 & 0x3ffff) - 0x1fffe);
  goto switchD_007c0564_default;
switchD_007c0564_caseD_1b:
  iVar5 = *(int *)(param_1 + 0x14) + -0x18;
  uVar6 = uVar6 >> 0xf & 0x1ff;
  local_38 = (double)CONCAT44(local_38._4_4_,iVar5);
  if (uVar6 != 0) {
    *(int **)(param_1 + 8) = piVar13 + uVar6 * 4 + -4;
  }
  if (*(int *)(param_1 + 0x50) != 0) {
    FUN_007c1f30(param_1,local_50);
    iVar5 = (int)local_38._0_4_;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x14) + 8) = 8;
  *(uint **)(*(int *)(param_1 + 0x14) + 0xc) = local_54;
  if ((*(byte *)(iVar5 + 8) & 4) == 0) {
    return piVar13;
  }
  iVar5 = (*(uint *)(*(int *)((int)local_38._0_4_ + 0xc) + -4) >> 6 & 0x1ff) - 1;
  FUN_007bd950(param_1,iVar5,piVar13);
  if (-1 < iVar5) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 4);
  }
  goto LAB_007c04e0;
}


// ==== FUN_007c1640 @ 0x007c1640 ====

uint FUN_007c1640(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; 7 < param_1; param_1 = param_1 + 1 >> 1) {
    iVar1 = iVar1 + 1;
  }
  return iVar1 << 3 | param_1;
}


// ==== FUN_007c1660 @ 0x007c1660 ====

uint FUN_007c1660(uint param_1)

{
  if (0xffff < param_1) {
    if (param_1 < 0x1000000) {
      return *(byte *)((int)&DAT_009fe514 + (param_1 >> 0x10 & 0xff) + 3) + 0x10;
    }
    return *(byte *)((int)&DAT_009fe514 + (param_1 >> 0x18) + 3) + 0x18;
  }
  if (0xff < param_1) {
    return *(byte *)((int)&DAT_009fe514 + (param_1 >> 8 & 0xff) + 3) + 8;
  }
  if (param_1 == 0) {
    return 0xffffffff;
  }
  return (uint)*(byte *)((int)&DAT_009fe514 + (param_1 & 0xff) + 3);
}


// ==== FUN_007c16c0 @ 0x007c16c0 ====

bool FUN_007c16c0(int *param_1,int *param_2)

{
  if (*param_1 != *param_2) {
    return false;
  }
  switch(*param_1) {
  case 0:
    goto switchD_007c16d3_caseD_0;
  default:
    return param_1[2] == param_2[2];
  case 3:
    if (*(double *)(param_1 + 2) != *(double *)(param_2 + 2)) {
      return false;
    }
switchD_007c16d3_caseD_0:
    return true;
  }
}


// ==== FUN_007c1710 @ 0x007c1710 ====

undefined4 FUN_007c1710(byte *param_1,double *param_2)

{
  byte *pbVar1;
  int iVar2;
  double dVar3;
  
  pbVar1 = param_1;
  dVar3 = _strtod((char *)param_1,(char **)&param_1);
  if (param_1 != pbVar1) {
    iVar2 = _isspace((uint)*param_1);
    while (iVar2 != 0) {
      param_1 = param_1 + 1;
      iVar2 = _isspace((uint)*param_1);
    }
    if (*param_1 == 0) {
      *param_2 = dVar3;
      return 1;
    }
  }
  return 0;
}


// ==== FUN_007c1780 @ 0x007c1780 ====

void FUN_007c1780(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  char *in_EDX;
  int unaff_ESI;
  
  puVar2 = *(undefined4 **)(unaff_ESI + 8);
  *puVar2 = 4;
  do {
    cVar1 = *in_EDX;
    in_EDX = in_EDX + 1;
  } while (cVar1 != '\0');
  uVar3 = FUN_007c1d70();
  puVar2[2] = uVar3;
  if (*(int *)(unaff_ESI + 0x18) - *(int *)(unaff_ESI + 8) < 0x11) {
    FUN_007bd420();
  }
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 0x10;
  return;
}


// ==== FUN_007c17d0 @ 0x007c17d0 ====

int FUN_007c17d0(int param_1,char *param_2,int param_3)

{
  byte *pbVar1;
  int *piVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  char *pcVar7;
  undefined4 *puVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  undefined8 *local_c;
  char *local_8;
  int local_4;
  
  iVar4 = param_1;
  puVar8 = *(undefined4 **)(param_1 + 8);
  iVar9 = 1;
  local_4 = 1;
  *puVar8 = 4;
  uVar5 = FUN_007c1d70(param_1,&DAT_0099cf70,0);
  puVar8[2] = uVar5;
  if (*(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 8) < 0x11) {
    FUN_007bd420(iVar4,1);
  }
  pcVar11 = param_2;
  *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x10;
  local_8 = _strchr(param_2,0x25);
  if (local_8 == (char *)0x0) {
LAB_007c19aa:
    puVar8 = *(undefined4 **)(iVar4 + 8);
    *puVar8 = 4;
    pcVar7 = pcVar11;
    do {
      cVar3 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar3 != '\0');
    uVar5 = FUN_007c1d70(iVar4,pcVar11,(int)pcVar7 - (int)(pcVar11 + 1));
    puVar8[2] = uVar5;
    if (*(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 8) < 0x11) {
      FUN_007bd420(iVar4,1);
    }
    iVar10 = *(int *)(iVar4 + 8) + 0x10;
    *(int *)(iVar4 + 8) = iVar10;
    FUN_007c0090(iVar4,iVar9 + 1,(iVar10 - *(int *)(iVar4 + 0xc) >> 4) + -1);
    iVar9 = *(int *)(iVar4 + 8) + iVar9 * -0x10;
    *(int *)(iVar4 + 8) = iVar9;
    return *(int *)(iVar9 + -8) + 0x10;
  }
  local_c = (undefined8 *)(param_3 + -8);
  iVar10 = param_3 + -4;
  do {
    puVar8 = *(undefined4 **)(iVar4 + 8);
    *puVar8 = 4;
    uVar5 = FUN_007c1d70(iVar4,pcVar11,(int)local_8 - (int)pcVar11);
    puVar8[2] = uVar5;
    if (*(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 8) < 0x11) {
      FUN_007bd420(iVar4,1);
    }
    iVar9 = *(int *)(iVar4 + 8);
    puVar8 = (undefined4 *)(iVar9 + 0x10);
    *(undefined4 **)(iVar4 + 8) = puVar8;
    switch(local_8[1]) {
    case '%':
      iVar6 = 1;
      *puVar8 = 4;
      puVar8 = (undefined4 *)&DAT_009fe618;
      goto LAB_007c1959;
    default:
      goto switchD_007c18a9_caseD_26;
    case 'c':
      pbVar1 = (byte *)(iVar10 + 4);
      iVar10 = iVar10 + 4;
      local_c = (undefined8 *)((int)local_c + 4);
      pcVar11 = (char *)&param_1;
      param_1._0_2_ = (ushort)*pbVar1;
      *puVar8 = 4;
      do {
        cVar3 = *pcVar11;
        pcVar11 = pcVar11 + 1;
      } while (cVar3 != '\0');
      iVar6 = (int)pcVar11 - ((int)&param_1 + 1);
      puVar8 = &param_1;
LAB_007c1959:
      uVar5 = FUN_007c1d70(iVar4,puVar8,iVar6);
      *(undefined4 *)(iVar9 + 0x18) = uVar5;
      iVar9 = *(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 8);
      bVar14 = SBORROW4(iVar9,0x10);
      bVar13 = iVar9 + -0x10 < 0;
      bVar12 = iVar9 == 0x10;
      break;
    case 'd':
      *puVar8 = 3;
      piVar2 = (int *)(iVar10 + 4);
      iVar10 = iVar10 + 4;
      local_c = (undefined8 *)((int)local_c + 4);
      *(double *)(iVar9 + 0x18) = (double)*piVar2;
      iVar9 = *(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 8);
      bVar14 = SBORROW4(iVar9,0x10);
      bVar13 = iVar9 + -0x10 < 0;
      bVar12 = iVar9 == 0x10;
      break;
    case 'f':
      local_c = local_c + 1;
      *puVar8 = 3;
      *(undefined8 *)(iVar9 + 0x18) = *local_c;
      iVar9 = *(int *)(iVar4 + 0x18) - *(int *)(iVar4 + 8);
      iVar10 = iVar10 + 8;
      bVar14 = SBORROW4(iVar9,0x10);
      bVar13 = iVar9 + -0x10 < 0;
      bVar12 = iVar9 == 0x10;
      break;
    case 's':
      iVar10 = iVar10 + 4;
      local_c = (undefined8 *)((int)local_c + 4);
      FUN_007c1780();
      goto switchD_007c18a9_caseD_26;
    }
    if (bVar12 || bVar14 != bVar13) {
      FUN_007bd420(iVar4,1);
    }
    *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + 0x10;
switchD_007c18a9_caseD_26:
    iVar9 = local_4 + 2;
    pcVar11 = local_8 + 2;
    local_8 = _strchr(pcVar11,0x25);
    if (local_8 == (char *)0x0) goto LAB_007c19aa;
    local_4 = iVar9;
  } while( true );
}


// ==== FUN_007c1aa0 @ 0x007c1aa0 ====

void FUN_007c1aa0(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_007c17d0(param_1,param_2,&param_3);
  return;
}


// ==== FUN_007c1ac0 @ 0x007c1ac0 ====

void FUN_007c1ac0(char *param_1,char *param_2,size_t param_3)

{
  char cVar1;
  char *pcVar2;
  size_t _Count;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  if (*param_2 == '=') {
    _strncpy(param_1,param_2 + 1,param_3);
    param_1[param_3 - 1] = '\0';
    return;
  }
  if (*param_2 == '@') {
    pcVar4 = param_2 + 1;
    pcVar2 = pcVar4;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    *param_1 = '\0';
    if ((int)(param_3 - 8) < (int)pcVar2 - (int)(param_2 + 2)) {
      pcVar4 = pcVar4 + (((int)pcVar2 - (int)(param_2 + 2)) - (param_3 - 8));
      pcVar2 = param_1 + -1;
      do {
        pcVar5 = pcVar2 + 1;
        pcVar2 = pcVar2 + 1;
      } while (*pcVar5 != '\0');
      *(undefined4 *)pcVar2 = DAT_009fe62c;
    }
    pcVar2 = pcVar4;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    param_1 = param_1 + -1;
    do {
      pcVar5 = param_1 + 1;
      param_1 = param_1 + 1;
    } while (*pcVar5 != '\0');
    pcVar5 = pcVar4;
    for (uVar3 = (uint)((int)pcVar2 - (int)pcVar4) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)param_1 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      param_1 = param_1 + 4;
    }
    for (uVar3 = (int)pcVar2 - (int)pcVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *param_1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      param_1 = param_1 + 1;
    }
    return;
  }
  _Count = _strcspn(param_2,&DAT_009fd0b4);
  if ((int)(param_3 - 0x11) < (int)_Count) {
    _Count = param_3 - 0x11;
  }
  *(undefined4 *)param_1 = s__string___009fe620._0_4_;
  *(undefined4 *)(param_1 + 4) = s__string___009fe620._4_4_;
  *(undefined2 *)(param_1 + 8) = s__string___009fe620._8_2_;
  if (param_2[_Count] == '\0') {
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar4 = param_1 + -1;
    do {
      pcVar5 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
    } while (*pcVar5 != '\0');
    pcVar5 = param_2;
    for (uVar3 = (uint)((int)pcVar2 - (int)param_2) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined4 *)pcVar4 = *(undefined4 *)pcVar5;
      pcVar5 = pcVar5 + 4;
      pcVar4 = pcVar4 + 4;
    }
    for (uVar3 = (int)pcVar2 - (int)param_2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar4 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      pcVar4 = pcVar4 + 1;
    }
  }
  else {
    _strncat(param_1,param_2,_Count);
    pcVar2 = param_1 + -1;
    do {
      pcVar4 = pcVar2 + 1;
      pcVar2 = pcVar2 + 1;
    } while (*pcVar4 != '\0');
    *(undefined4 *)pcVar2 = DAT_009fe62c;
  }
  pcVar2 = param_1 + -1;
  do {
    pcVar4 = pcVar2;
    pcVar2 = pcVar4 + 1;
  } while (pcVar4[1] != '\0');
  *(undefined2 *)(pcVar4 + 1) = DAT_009fe61c;
  pcVar4[3] = DAT_009fe61e;
  return;
}


// ==== FUN_007c1c10 @ 0x007c1c10 ====

void FUN_007c1c10(int param_1)

{
  FUN_007c3420(param_1,**(undefined4 **)(param_1 + 0x10),(*(undefined4 **)(param_1 + 0x10))[2] << 2,
               0);
  return;
}


// ==== FUN_007c1c30 @ 0x007c1c30 ====

void FUN_007c1c30(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  undefined4 *puVar7;
  int local_4;
  
  puVar3 = (undefined4 *)FUN_007c3420(param_1,0,0,param_2 * 4);
  piVar1 = *(int **)(param_1 + 0x10);
  if (0 < param_2) {
    puVar7 = puVar3;
    for (iVar5 = param_2; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
  }
  local_4 = 0;
  if (0 < piVar1[2]) {
    do {
      piVar4 = *(int **)(*piVar1 + local_4 * 4);
      if (piVar4 != (int *)0x0) {
        do {
          piVar2 = (int *)*piVar4;
          uVar6 = piVar4[2] & param_2 - 1U;
          *piVar4 = puVar3[uVar6];
          puVar3[uVar6] = piVar4;
          piVar4 = piVar2;
        } while (piVar2 != (int *)0x0);
      }
      local_4 = local_4 + 1;
    } while (local_4 < piVar1[2]);
  }
  FUN_007c3420(param_1,*piVar1,piVar1[2] << 2,0);
  *piVar1 = (int)puVar3;
  piVar1[2] = param_2;
  return;
}


// ==== FUN_007c1cd0 @ 0x007c1cd0 ====

undefined4 * FUN_007c1cd0(int param_1,undefined4 *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint in_EAX;
  undefined4 *puVar4;
  uint uVar5;
  undefined4 *puVar6;
  
  puVar4 = (undefined4 *)FUN_007c3420(param_1,0,0,param_3 + 0x11);
  puVar4[3] = param_3;
  puVar4[2] = in_EAX;
  *(undefined1 *)((int)puVar4 + 5) = 0;
  *(undefined1 *)(puVar4 + 1) = 4;
  *(undefined1 *)((int)puVar4 + 6) = 0;
  puVar6 = puVar4 + 4;
  for (uVar5 = param_3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *puVar6 = *param_2;
    param_2 = param_2 + 1;
    puVar6 = puVar6 + 1;
  }
  for (uVar5 = param_3 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar6 = *(undefined1 *)param_2;
    param_2 = (undefined4 *)((int)param_2 + 1);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
  }
  *(undefined1 *)(param_3 + 0x10 + (int)puVar4) = 0;
  piVar1 = *(int **)(param_1 + 0x10);
  uVar5 = in_EAX & piVar1[2] - 1U;
  *puVar4 = *(undefined4 *)(*piVar1 + uVar5 * 4);
  *(undefined4 **)(*piVar1 + uVar5 * 4) = puVar4;
  iVar2 = piVar1[1];
  piVar1[1] = iVar2 + 1;
  iVar3 = piVar1[2];
  if ((iVar3 < iVar2 + 1) && (iVar3 < 0x3fffffff)) {
    FUN_007c1c30(param_1,iVar3 * 2);
  }
  return puVar4;
}


// ==== FUN_007c1d70 @ 0x007c1d70 ====

void FUN_007c1d70(int param_1,char *param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  char *pcVar6;
  bool bVar7;
  
  uVar3 = (param_3 >> 5) + 1;
  uVar4 = param_3;
  for (uVar2 = param_3; uVar3 <= uVar2; uVar2 = uVar2 - uVar3) {
    uVar4 = uVar4 ^ (uint)(byte)param_2[uVar2 - 1] + uVar4 * 0x20 + (uVar4 >> 2);
  }
  puVar1 = *(undefined4 **)
            (**(int **)(param_1 + 0x10) + ((*(int **)(param_1 + 0x10))[2] - 1U & uVar4) * 4);
  do {
    if (puVar1 == (undefined4 *)0x0) {
      FUN_007c1cd0(param_1,param_2,param_3);
      return;
    }
    if (puVar1[3] == param_3) {
      bVar7 = true;
      uVar2 = param_3;
      pcVar5 = param_2;
      pcVar6 = (char *)(puVar1 + 4);
      do {
        if (uVar2 == 0) break;
        uVar2 = uVar2 - 1;
        bVar7 = *pcVar5 == *pcVar6;
        pcVar5 = pcVar5 + 1;
        pcVar6 = pcVar6 + 1;
      } while (bVar7);
      if (bVar7) {
        return;
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}


// ==== FUN_007c1e00 @ 0x007c1e00 ====

void FUN_007c1e00(int param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_007c3420(param_1,0,0,param_2 + 0x10);
  puVar1[3] = param_2;
  *(undefined1 *)((int)puVar1 + 5) = 2;
  *(undefined1 *)(puVar1 + 1) = 7;
  puVar1[2] = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x48);
  *puVar1 = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x10);
  *(undefined4 **)(*(int *)(param_1 + 0x10) + 0x10) = puVar1;
  return;
}


// ==== FUN_007c1e40 @ 0x007c1e40 ====

int FUN_007c1e40(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = FUN_007c3420(param_1,0,0,(param_2 + 1) * 0x10);
  FUN_007bf730(param_1,iVar1,6);
  *(char *)(iVar1 + 7) = (char)param_2;
  *(undefined1 *)(iVar1 + 6) = 1;
  return iVar1;
}


// ==== FUN_007c1e80 @ 0x007c1e80 ====

int FUN_007c1e80(undefined4 param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = FUN_007c3420(param_1,0,0,param_2 * 4 + 0x24);
  FUN_007bf730(param_1,iVar2,6);
  *(undefined1 *)(iVar2 + 6) = 0;
  *(undefined4 *)(iVar2 + 0x10) = *param_3;
  *(undefined4 *)(iVar2 + 0x14) = param_3[1];
  *(undefined4 *)(iVar2 + 0x18) = param_3[2];
  uVar1 = param_3[3];
  *(char *)(iVar2 + 7) = (char)param_2;
  *(undefined4 *)(iVar2 + 0x1c) = uVar1;
  return iVar2;
}


// ==== FUN_007c1ee0 @ 0x007c1ee0 ====

void FUN_007c1ee0(int param_1,uint param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = *(undefined4 **)(param_1 + 0x50);
  puVar2 = (undefined4 *)(param_1 + 0x50);
  while ((puVar1 = puVar3, puVar1 != (undefined4 *)0x0 && (param_2 <= (uint)puVar1[2]))) {
    if (puVar1[2] == param_2) {
      return;
    }
    puVar2 = puVar1;
    puVar3 = (undefined4 *)*puVar1;
  }
  puVar3 = (undefined4 *)FUN_007c3420(param_1,0,0,0x20);
  *(undefined1 *)(puVar3 + 1) = 10;
  *(undefined1 *)((int)puVar3 + 5) = 1;
  puVar3[2] = param_2;
  *puVar3 = *puVar2;
  *puVar2 = puVar3;
  return;
}


// ==== FUN_007c1f30 @ 0x007c1f30 ====

void FUN_007c1f30(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x50);
  while ((puVar1 != (undefined4 *)0x0 && (puVar2 = (undefined4 *)puVar1[2], param_2 <= puVar2))) {
    puVar1[4] = *puVar2;
    puVar1[6] = puVar2[2];
    puVar1[7] = puVar2[3];
    puVar1[2] = puVar1 + 4;
    *(undefined4 *)(param_1 + 0x50) = *puVar1;
    FUN_007bf730(param_1,puVar1,10);
    puVar1 = *(undefined4 **)(param_1 + 0x50);
  }
  return;
}


// ==== FUN_007c1f80 @ 0x007c1f80 ====

int FUN_007c1f80(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_007c3420(param_1,0,0,0x48);
  FUN_007bf730(param_1,iVar1,9);
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  *(undefined4 *)(iVar1 + 0x30) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  *(undefined1 *)(iVar1 + 0x44) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined1 *)(iVar1 + 0x45) = 0;
  *(undefined1 *)(iVar1 + 0x46) = 0;
  *(undefined1 *)(iVar1 + 0x47) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x38) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x3c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  return iVar1;
}


// ==== FUN_007c1fe0 @ 0x007c1fe0 ====

void FUN_007c1fe0(undefined4 param_1,int param_2)

{
  FUN_007c3420(param_1,*(undefined4 *)(param_2 + 0xc),*(int *)(param_2 + 0x2c) << 2,0);
  FUN_007c3420(param_1,*(undefined4 *)(param_2 + 0x10),*(int *)(param_2 + 0x34) << 2,0);
  FUN_007c3420(param_1,*(undefined4 *)(param_2 + 8),*(int *)(param_2 + 0x28) << 4,0);
  FUN_007c3420(param_1,*(undefined4 *)(param_2 + 0x14),*(int *)(param_2 + 0x30) << 2,0);
  FUN_007c3420(param_1,*(undefined4 *)(param_2 + 0x18),*(int *)(param_2 + 0x38) * 0xc,0);
  FUN_007c3420(param_1,*(undefined4 *)(param_2 + 0x1c),*(int *)(param_2 + 0x24) << 2,0);
  FUN_007c3420(param_1,param_2,0x48,0);
  return;
}


// ==== FUN_007c2080 @ 0x007c2080 ====

void FUN_007c2080(undefined4 param_1,int param_2)

{
  if (*(char *)(param_2 + 6) == '\0') {
    FUN_007c3420(param_1,param_2,(uint)*(byte *)(param_2 + 7) * 4 + 0x24,0);
    return;
  }
  FUN_007c3420(param_1,param_2,(*(byte *)(param_2 + 7) + 1) * 0x10,0);
  return;
}


// ==== FUN_007c20c0 @ 0x007c20c0 ====

int FUN_007c20c0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < *(int *)(param_1 + 0x38)) {
    piVar1 = (int *)(*(int *)(param_1 + 0x18) + 8);
    do {
      if (param_3 < piVar1[-1]) {
        return 0;
      }
      if ((param_3 < *piVar1) && (param_2 = param_2 + -1, param_2 == 0)) {
        return *(int *)(*(int *)(param_1 + 0x18) + iVar2 * 0xc) + 0x10;
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 3;
    } while (iVar2 < *(int *)(param_1 + 0x38));
  }
  return 0;
}


// ==== FUN_007c2110 @ 0x007c2110 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_007c2110(double param_1)

{
  double dVar1;
  int unaff_ESI;
  
  dVar1 = param_1 + _DAT_0099d0a0;
  param_1._4_4_ = (int)((ulonglong)dVar1 >> 0x20);
  param_1._0_4_ = SUB84(dVar1,0);
  return *(int *)(unaff_ESI + 0x10) +
         ((uint)(param_1._0_4_ + param_1._4_4_) %
         ((1 << (*(byte *)(unaff_ESI + 7) & 0x1f)) - 1U | 1)) * 0x28;
}


// ==== FUN_007c2150 @ 0x007c2150 ====

int FUN_007c2150(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  switch(*param_2) {
  case 1:
    return *(int *)(param_1 + 0x10) +
           ((1 << (*(byte *)(param_1 + 7) & 0x1f)) - 1U & param_2[2]) * 0x28;
  case 2:
    return *(int *)(param_1 + 0x10) +
           ((uint)param_2[2] % ((1 << (*(byte *)(param_1 + 7) & 0x1f)) - 1U | 1)) * 0x28;
  case 3:
    iVar1 = FUN_007c2110(*(undefined8 *)(param_2 + 2));
    return iVar1;
  case 4:
    return *(int *)(param_1 + 0x10) +
           ((1 << (*(byte *)(param_1 + 7) & 0x1f)) - 1U & *(uint *)(param_2[2] + 8)) * 0x28;
  default:
    return *(int *)(param_1 + 0x10) +
           ((uint)param_2[2] % ((1 << (*(byte *)(param_1 + 7) & 0x1f)) - 1U | 1)) * 0x28;
  }
}


// ==== FUN_007c2220 @ 0x007c2220 ====

void FUN_007c2220(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_EDX;
  int iVar4;
  int local_4;
  
  iVar1 = *in_EDX;
  iVar2 = (iVar1 != 0) - 1;
  local_4 = iVar1;
  if (iVar1 < *param_2) {
    iVar3 = 0;
    do {
      in_EDX = in_EDX + 1;
      iVar4 = 1 << ((byte)iVar3 & 0x1f);
      if (*param_2 < iVar4) break;
      if ((0 < *in_EDX) && (iVar1 = iVar1 + *in_EDX, iVar4 <= iVar1)) {
        iVar2 = iVar3 + 1;
        local_4 = iVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar1 < *param_2);
  }
  *param_3 = param_1 - local_4;
  if (iVar2 == -1) {
    *param_2 = 0;
    return;
  }
  *param_2 = 1 << ((byte)iVar2 & 0x1f);
  return;
}


// ==== FUN_007c22b0 @ 0x007c22b0 ====

void FUN_007c22b0(int param_1,int *param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int local_68;
  int local_64 [25];
  
  piVar1 = param_2;
  iVar6 = 0;
  iVar8 = *(int *)(param_1 + 0x1c);
  iVar4 = 0;
  local_68 = 0;
  iVar5 = 0;
  piVar7 = local_64;
  do {
    iVar2 = 1 << ((byte)iVar5 & 0x1f);
    if ((iVar8 < iVar2) && (iVar2 = iVar8, iVar8 <= iVar4)) {
      if (iVar5 < 0x19) {
        piVar7 = local_64 + iVar5;
        for (iVar8 = 0x19 - iVar5; iVar8 != 0; iVar8 = iVar8 + -1) {
          *piVar7 = 0;
          piVar7 = piVar7 + 1;
        }
      }
      break;
    }
    *piVar7 = 0;
    if (iVar4 < iVar2) {
      piVar3 = (int *)(iVar4 * 0x10 + *(int *)(param_1 + 0xc));
      iVar2 = iVar2 - iVar4;
      iVar4 = iVar4 + iVar2;
      do {
        if (*piVar3 != 0) {
          *piVar7 = *piVar7 + 1;
          local_68 = local_68 + 1;
        }
        piVar3 = piVar3 + 4;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      iVar6 = local_68;
    }
    iVar5 = iVar5 + 1;
    piVar7 = piVar7 + 1;
  } while (iVar5 < 0x19);
  *param_2 = iVar6;
  param_2 = (int *)(1 << (*(byte *)(param_1 + 7) & 0x1f));
  if (param_2 != (int *)0x0) {
    iVar8 = (int)param_2 * 0x28;
    do {
      iVar8 = iVar8 + -0x28;
      piVar7 = (int *)(*(int *)(param_1 + 0x10) + iVar8);
      if (*(int *)(*(int *)(param_1 + 0x10) + 0x10 + iVar8) != 0) {
        if ((((*piVar7 == 3) && (iVar4 = FUN_00802534(), *(double *)(piVar7 + 2) == (double)iVar4))
            && (0 < iVar4)) && (((iVar4 - 1U & 0xff000000) == 0 && (-1 < iVar4)))) {
          iVar4 = FUN_007c1660(iVar4 + -1);
          local_64[iVar4 + 1] = local_64[iVar4 + 1] + 1;
          *piVar1 = *piVar1 + 1;
        }
        iVar6 = iVar6 + 1;
      }
      param_2 = (int *)((int)param_2 + -1);
    } while (param_2 != (int *)0x0);
  }
  FUN_007c2220(iVar6,piVar1,param_3);
  return;
}


// ==== FUN_007c23f0 @ 0x007c23f0 ====

void FUN_007c23f0(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar1 = FUN_007c3420(param_1,*(undefined4 *)(unaff_ESI + 0xc),*(int *)(unaff_ESI + 0x1c) << 4,
                       unaff_EDI << 4);
  iVar3 = *(int *)(unaff_ESI + 0x1c);
  *(undefined4 *)(unaff_ESI + 0xc) = uVar1;
  if (iVar3 < unaff_EDI) {
    iVar2 = iVar3 << 4;
    iVar3 = unaff_EDI - iVar3;
    do {
      *(undefined4 *)(iVar2 + *(int *)(unaff_ESI + 0xc)) = 0;
      iVar2 = iVar2 + 0x10;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  *(int *)(unaff_ESI + 0x1c) = unaff_EDI;
  return;
}


// ==== FUN_007c2440 @ 0x007c2440 ====

void FUN_007c2440(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int unaff_EBX;
  int unaff_ESI;
  int iVar4;
  
  iVar4 = 1 << ((byte)param_1 & 0x1f);
  if (0x18 < param_1) {
    FUN_007be950();
  }
  if (param_1 == 0) {
    *(int *)(unaff_ESI + 0x10) = *(int *)(unaff_EBX + 0x10) + 0x58;
  }
  else {
    uVar1 = FUN_007c3420();
    *(undefined4 *)(unaff_ESI + 0x10) = uVar1;
    if (0 < iVar4) {
      iVar2 = 0;
      iVar3 = iVar4;
      do {
        *(undefined4 *)(*(int *)(unaff_ESI + 0x10) + 0x20 + iVar2) = 0;
        *(undefined4 *)(iVar2 + *(int *)(unaff_ESI + 0x10)) = 0;
        *(undefined4 *)(*(int *)(unaff_ESI + 0x10) + 0x10 + iVar2) = 0;
        iVar2 = iVar2 + 0x28;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  *(byte *)(unaff_ESI + 7) = (byte)param_1;
  *(int *)(unaff_ESI + 0x14) = *(int *)(unaff_ESI + 0x10) + -0x28 + iVar4 * 0x28;
  return;
}


// ==== FUN_007c24d0 @ 0x007c24d0 ====

int FUN_007c24d0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = FUN_007c3420(param_1,0,0,0x20);
  FUN_007bf730(param_1,iVar1,5);
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x48);
  *(undefined1 *)(iVar1 + 6) = 0xff;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined1 *)(iVar1 + 7) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  FUN_007c23f0(param_1);
  FUN_007c2440(param_3);
  return iVar1;
}


// ==== FUN_007c2530 @ 0x007c2530 ====

void FUN_007c2530(undefined4 param_1,int param_2)

{
  if (*(byte *)(param_2 + 7) != 0) {
    FUN_007c3420(param_1,*(undefined4 *)(param_2 + 0x10),
                 (1 << (*(byte *)(param_2 + 7) & 0x1f)) * 0x28,0);
  }
  FUN_007c3420(param_1,*(undefined4 *)(param_2 + 0xc),*(int *)(param_2 + 0x1c) << 4,0);
  FUN_007c3420(param_1,param_2,0x20,0);
  return;
}


// ==== FUN_007c2590 @ 0x007c2590 ====

undefined4 * FUN_007c2590(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *unaff_EDI;
  
  if (*unaff_EDI == 0) {
    return &DAT_009fe508;
  }
  iVar1 = FUN_007c2150(param_1);
  do {
    iVar2 = FUN_007c16c0(iVar1);
    if (iVar2 != 0) {
      return (undefined4 *)(iVar1 + 0x10);
    }
    iVar1 = *(int *)(iVar1 + 0x20);
  } while (iVar1 != 0);
  return &DAT_009fe508;
}


// ==== FUN_007c25e0 @ 0x007c25e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_007c25e0(int param_1,int param_2)

{
  double dVar1;
  int *piVar2;
  int local_8;
  int iStack_4;
  
  if ((0 < param_2) && (param_2 <= *(int *)(param_1 + 0x1c))) {
    return (int *)(*(int *)(param_1 + 0xc) + -0x10 + param_2 * 0x10);
  }
  dVar1 = _DAT_0099d0a0 + (double)param_2;
  iStack_4 = (int)((ulonglong)dVar1 >> 0x20);
  local_8 = SUB84(dVar1,0);
  piVar2 = (int *)(*(int *)(param_1 + 0x10) +
                  ((uint)(local_8 + iStack_4) % ((1 << (*(byte *)(param_1 + 7) & 0x1f)) - 1U | 1)) *
                  0x28);
  while ((*piVar2 != 3 || (*(double *)(piVar2 + 2) != (double)param_2))) {
    piVar2 = (int *)piVar2[8];
    if (piVar2 == (int *)0x0) {
      return &DAT_009fe508;
    }
  }
  return piVar2 + 4;
}


// ==== FUN_007c2670 @ 0x007c2670 ====

int * FUN_007c2670(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(*(int *)(param_1 + 0x10) +
                  ((1 << (*(byte *)(param_1 + 7) & 0x1f)) - 1U & *(uint *)(param_2 + 8)) * 0x28);
  while ((*piVar1 != 4 || (piVar1[2] != param_2))) {
    piVar1 = (int *)piVar1[8];
    if (piVar1 == (int *)0x0) {
      return &DAT_009fe508;
    }
  }
  return piVar1 + 4;
}


// ==== FUN_007c26b0 @ 0x007c26b0 ====

void FUN_007c26b0(undefined4 param_1,int *param_2)

{
  int iVar1;
  
  if (*param_2 == 3) {
    iVar1 = FUN_00802534();
    if (*(double *)(param_2 + 2) == (double)iVar1) {
      FUN_007c25e0();
      return;
    }
  }
  else if (*param_2 == 4) {
    FUN_007c2670();
    return;
  }
  FUN_007c2590(param_1);
  return;
}


// ==== FUN_007c2710 @ 0x007c2710 ====

void FUN_007c2710(undefined4 param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  char *pcVar2;
  
  puVar1 = (undefined4 *)FUN_007c26b0(param_2,param_3);
  *(undefined1 *)(param_2 + 6) = 0;
  if (puVar1 != &DAT_009fe508) {
    return;
  }
  if (*param_3 == 0) {
    pcVar2 = s_table_index_is_nil_009fe654;
  }
  else {
    if ((*param_3 != 3) || (!NAN(*(double *)(param_3 + 2)))) goto LAB_007c2764;
    pcVar2 = s_table_index_is_NaN_009fe640;
  }
  FUN_007be950(param_1,pcVar2);
LAB_007c2764:
  FUN_007c2ba0(param_1,param_2,param_3);
  return;
}


// ==== FUN_007c2780 @ 0x007c2780 ====

uint FUN_007c2780(undefined4 param_1)

{
  int *in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int unaff_EDI;
  
  if (*in_EAX == 0) {
    return 0xffffffff;
  }
  if ((((*in_EAX == 3) && (iVar1 = FUN_00802534(), *(double *)(in_EAX + 2) == (double)iVar1)) &&
      (0 < iVar1)) &&
     ((((iVar1 - 1U & 0xff000000) == 0 && (-1 < iVar1)) && (iVar1 <= *(int *)(unaff_EDI + 0x1c)))))
  {
    return iVar1 - 1U;
  }
  puVar2 = (undefined4 *)FUN_007c26b0();
  if (puVar2 == &DAT_009fe508) {
    FUN_007be950(param_1,s_invalid_key_for__next__009fe668);
  }
  return (uint)((int)puVar2 + (-0x10 - *(int *)(unaff_EDI + 0x10))) / 0x28 +
         *(int *)(unaff_EDI + 0x1c);
}


// ==== FUN_007c2810 @ 0x007c2810 ====

undefined4 FUN_007c2810(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar2 = FUN_007c2780(param_1);
  iVar4 = *(int *)(param_2 + 0x1c);
  iVar2 = iVar2 + 1;
  if (iVar2 < iVar4) {
    piVar3 = (int *)(iVar2 * 0x10 + *(int *)(param_2 + 0xc));
    do {
      if (*piVar3 != 0) {
        *param_3 = 3;
        *(double *)(param_3 + 2) = (double)(iVar2 + 1);
        iVar4 = iVar2 * 0x10 + *(int *)(param_2 + 0xc);
        param_3[4] = *(undefined4 *)(iVar2 * 0x10 + *(int *)(param_2 + 0xc));
        param_3[6] = *(undefined4 *)(iVar4 + 8);
        param_3[7] = *(undefined4 *)(iVar4 + 0xc);
        return 1;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 4;
    } while (iVar2 < iVar4);
  }
  iVar2 = iVar2 - iVar4;
  iVar4 = 1 << (*(byte *)(param_2 + 7) & 0x1f);
  if (iVar2 < iVar4) {
    iVar1 = *(int *)(param_2 + 0x10);
    piVar3 = (int *)(iVar1 + 0x10 + iVar2 * 0x28);
    do {
      if (*piVar3 != 0) {
        iVar2 = iVar2 * 0x28;
        *param_3 = *(undefined4 *)(iVar1 + iVar2);
        param_3[2] = *(undefined4 *)(iVar1 + 8 + iVar2);
        param_3[3] = *(undefined4 *)(iVar1 + 0xc + iVar2);
        iVar4 = *(int *)(param_2 + 0x10) + 0x10 + iVar2;
        param_3[4] = *(undefined4 *)(*(int *)(param_2 + 0x10) + 0x10 + iVar2);
        param_3[6] = *(undefined4 *)(iVar4 + 8);
        param_3[7] = *(undefined4 *)(iVar4 + 0xc);
        return 1;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 10;
    } while (iVar2 < iVar4);
  }
  return 0;
}


// ==== FUN_007c28f0 @ 0x007c28f0 ====

void FUN_007c28f0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  double *pdVar1;
  byte bVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  double *pdVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  char *pcVar13;
  undefined4 *local_44;
  undefined4 local_38 [2];
  double local_30;
  undefined4 local_28 [10];
  
  iVar3 = param_2;
  bVar2 = *(byte *)(param_2 + 7);
  iVar7 = *(int *)(param_2 + 0x1c);
  if (bVar2 == 0) {
    puVar10 = *(undefined4 **)(param_2 + 0x10);
    puVar11 = local_28;
    for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
    local_44 = local_28;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x58) = 0;
    *(undefined4 *)(*(int *)(param_1 + 0x10) + 0x68) = 0;
  }
  else {
    local_44 = *(undefined4 **)(param_2 + 0x10);
  }
  if (iVar7 < param_3) {
    FUN_007c23f0(param_1);
  }
  FUN_007c2440(param_4);
  if (param_3 < iVar7) {
    iVar8 = param_3 << 4;
    *(int *)(param_2 + 0x1c) = param_3;
    iVar12 = iVar7 - param_3;
    param_2 = iVar8;
    do {
      param_3 = param_3 + 1;
      piVar6 = (int *)(*(int *)(iVar3 + 0xc) + param_2);
      if (*piVar6 != 0) {
        piVar4 = (int *)FUN_007c25e0(iVar3,param_3);
        if (piVar4 == &DAT_009fe508) {
          local_30 = (double)param_3;
          local_38[0] = 3;
          piVar4 = (int *)FUN_007c2ba0(param_1,iVar3,local_38);
        }
        *piVar4 = *piVar6;
        piVar4[2] = piVar6[2];
        piVar4[3] = piVar6[3];
      }
      param_2 = param_2 + 0x10;
      iVar12 = iVar12 + -1;
    } while (iVar12 != 0);
    uVar5 = FUN_007c3420(param_1,*(undefined4 *)(iVar3 + 0xc),iVar7 << 4,iVar8);
    *(undefined4 *)(iVar3 + 0xc) = uVar5;
  }
  iVar7 = 1 << (bVar2 & 0x1f);
  if (-1 < iVar7 + -1) {
    pdVar9 = (double *)(local_44 + (iVar7 + -1) * 10 + 2);
    param_3 = iVar7;
    do {
      pdVar1 = pdVar9 + -1;
      if (*(int *)(pdVar9 + 1) != 0) {
        iVar8 = *(int *)pdVar1;
        if (iVar8 == 3) {
          iVar12 = FUN_00802534();
          if (*pdVar9 != (double)iVar12) goto LAB_007c2ae4;
          piVar6 = (int *)FUN_007c25e0(iVar3,iVar12);
        }
        else {
          if (iVar8 == 4) {
            piVar6 = (int *)(*(int *)(iVar3 + 0x10) +
                            ((1 << (*(byte *)(iVar3 + 7) & 0x1f)) - 1U &
                            *(uint *)(*(int *)pdVar9 + 8)) * 0x28);
            do {
              if ((*piVar6 == 4) && (piVar6[2] == *(int *)pdVar9)) {
                piVar6 = piVar6 + 4;
                goto LAB_007c2a96;
              }
              piVar6 = (int *)piVar6[8];
            } while (piVar6 != (int *)0x0);
          }
          else {
LAB_007c2ae4:
            if (iVar8 != 0) {
              iVar8 = FUN_007c2150(iVar3,pdVar1);
              do {
                iVar12 = FUN_007c16c0(iVar8,pdVar1);
                if (iVar12 != 0) {
                  piVar6 = (int *)(iVar8 + 0x10);
                  goto LAB_007c2a96;
                }
                iVar8 = *(int *)(iVar8 + 0x20);
              } while (iVar8 != 0);
            }
          }
          piVar6 = &DAT_009fe508;
        }
LAB_007c2a96:
        *(undefined1 *)(iVar3 + 6) = 0;
        if (piVar6 == &DAT_009fe508) {
          if (*(int *)pdVar1 == 0) {
            pcVar13 = s_table_index_is_nil_009fe654;
LAB_007c2b2f:
            FUN_007be950(param_1,pcVar13);
          }
          else if ((*(int *)pdVar1 == 3) && (NAN(*pdVar9))) {
            pcVar13 = s_table_index_is_NaN_009fe640;
            goto LAB_007c2b2f;
          }
          piVar6 = (int *)FUN_007c2ba0(param_1,iVar3,pdVar1);
        }
        *piVar6 = *(int *)(pdVar9 + 1);
        piVar6[2] = *(int *)(pdVar9 + 2);
        piVar6[3] = *(int *)((int)pdVar9 + 0x14);
      }
      pdVar9 = pdVar9 + -5;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  if (bVar2 != 0) {
    FUN_007c3420(param_1,local_44,iVar7 * 0x28,0);
  }
  return;
}


// ==== FUN_007c2ba0 @ 0x007c2ba0 ====

undefined4 * FUN_007c2ba0(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  
  puVar7 = param_3;
  iVar1 = param_2;
  puVar2 = (undefined4 *)FUN_007c2150(param_2,param_3);
  puVar5 = puVar2;
  if (puVar2[4] != 0) {
    puVar3 = (undefined4 *)FUN_007c2150(iVar1,puVar2);
    puVar5 = *(undefined4 **)(iVar1 + 0x14);
    if (puVar3 == puVar2) {
      puVar5[8] = puVar2[8];
      puVar2[8] = puVar5;
    }
    else {
      puVar7 = (undefined4 *)puVar3[8];
      while (puVar7 != puVar2) {
        puVar3 = (undefined4 *)puVar3[8];
        puVar7 = (undefined4 *)puVar3[8];
      }
      puVar3[8] = puVar5;
      puVar7 = puVar2;
      for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar5 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar5 = puVar5 + 1;
      }
      puVar2[8] = 0;
      puVar2[4] = 0;
      puVar5 = puVar2;
      puVar7 = param_3;
    }
  }
  *puVar5 = *puVar7;
  puVar5[2] = puVar7[2];
  puVar5[3] = puVar7[3];
  if (**(int **)(iVar1 + 0x14) != 0) {
    do {
      if (*(int *)(iVar1 + 0x14) == *(int *)(iVar1 + 0x10)) {
        puVar5[4] = 1;
        puVar5[6] = 0;
        FUN_007c22b0(iVar1,&param_2,&param_3);
        iVar6 = FUN_007c1660(param_3);
        FUN_007c28f0(param_1,iVar1,param_2,iVar6 + 1);
        puVar5 = (undefined4 *)FUN_007c26b0(iVar1,puVar7);
        *puVar5 = 0;
        return puVar5;
      }
      piVar4 = (int *)(*(int *)(iVar1 + 0x14) + -0x28);
      *(int **)(iVar1 + 0x14) = piVar4;
    } while (*piVar4 != 0);
  }
  return puVar5 + 4;
}


// ==== FUN_007c2c90 @ 0x007c2c90 ====

void FUN_007c2c90(undefined4 param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  undefined4 local_10 [2];
  double local_8;
  
  puVar1 = (undefined4 *)FUN_007c25e0(param_2,param_3);
  if (puVar1 == &DAT_009fe508) {
    local_8 = (double)param_3;
    local_10[0] = 3;
    FUN_007c2ba0(param_1,param_2,local_10);
  }
  return;
}


// ==== FUN_007c2ce0 @ 0x007c2ce0 ====

uint FUN_007c2ce0(int *param_1)

{
  byte bVar1;
  int *piVar2;
  byte *pbVar3;
  
  piVar2 = param_1;
  pbVar3 = (byte *)(*(code *)param_1[2])(0,param_1[3],&param_1);
  if ((pbVar3 == (byte *)0x0) || (param_1 == (int *)0x0)) {
    return 0xffffffff;
  }
  piVar2[1] = (int)pbVar3;
  *piVar2 = (int)param_1 + -1;
  bVar1 = *pbVar3;
  piVar2[1] = (int)(pbVar3 + 1);
  return (uint)bVar1;
}


// ==== FUN_007c2d20 @ 0x007c2d20 ====

uint FUN_007c2d20(int *param_1)

{
  byte bVar1;
  int *piVar2;
  byte *pbVar3;
  
  piVar2 = param_1;
  if (*param_1 != 0) {
LAB_007c2d65:
    return (uint)*(byte *)piVar2[1];
  }
  pbVar3 = (byte *)(*(code *)param_1[2])(0,param_1[3],&param_1);
  if ((pbVar3 != (byte *)0x0) && (param_1 != (int *)0x0)) {
    piVar2[1] = (int)pbVar3;
    *piVar2 = (int)param_1 + -1;
    bVar1 = *pbVar3;
    piVar2[1] = (int)(pbVar3 + 1);
    if (bVar1 != 0xffffffff) {
      *piVar2 = (int)param_1;
      piVar2[1] = (int)pbVar3;
      goto LAB_007c2d65;
    }
  }
  return 0xffffffff;
}


// ==== FUN_007c2d70 @ 0x007c2d70 ====

void FUN_007c2d70(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  param_1[2] = param_2;
  param_1[3] = param_3;
  param_1[4] = param_4;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


// ==== FUN_007c2da0 @ 0x007c2da0 ====

uint FUN_007c2da0(uint *param_1,undefined4 *param_2,uint param_3)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  uVar5 = param_3;
  do {
    if (uVar5 == 0) {
      return 0;
    }
    if (*param_1 == 0) {
      pbVar2 = (byte *)(*(code *)param_1[2])(0,param_1[3],&param_3);
      if ((pbVar2 == (byte *)0x0) || (param_3 == 0)) {
        return uVar5;
      }
      param_1[1] = (uint)pbVar2;
      *param_1 = param_3 - 1;
      bVar1 = *pbVar2;
      param_1[1] = (uint)(pbVar2 + 1);
      if (bVar1 == 0xffffffff) {
        return uVar5;
      }
      *param_1 = param_3;
      param_1[1] = (uint)pbVar2;
    }
    uVar3 = *param_1;
    if (uVar5 <= *param_1) {
      uVar3 = uVar5;
    }
    puVar6 = (undefined4 *)param_1[1];
    puVar7 = param_2;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    for (uVar4 = uVar3 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
      puVar6 = (undefined4 *)((int)puVar6 + 1);
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    param_2 = (undefined4 *)((int)param_2 + uVar3);
    uVar5 = uVar5 - uVar3;
    *param_1 = *param_1 - uVar3;
    param_1[1] = param_1[1] + uVar3;
  } while( true );
}


// ==== FUN_007c2e40 @ 0x007c2e40 ====

undefined4 FUN_007c2e40(undefined4 param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  
  if ((uint)param_2[1] < param_3) {
    if (param_3 < 0x20) {
      param_3 = 0x20;
    }
    uVar1 = FUN_007c3420(param_1,*param_2,param_2[1],param_3);
    *param_2 = uVar1;
    param_2[1] = param_3;
  }
  return *param_2;
}


// ==== FUN_007c2e80 @ 0x007c2e80 ====

void FUN_007c2e80(void)

{
  int in_EAX;
  undefined4 *unaff_ESI;
  int iVar1;
  int local_4;
  
  if ((in_EAX == 0) || (in_EAX + 0x10 == 0)) {
    local_4 = 0;
    (*(code *)unaff_ESI[1])(*unaff_ESI,&local_4,4,unaff_ESI[2]);
    return;
  }
  iVar1 = *(int *)(in_EAX + 0xc) + 1;
  local_4 = iVar1;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&local_4,4,unaff_ESI[2]);
  (*(code *)unaff_ESI[1])(*unaff_ESI,in_EAX + 0x10,iVar1,unaff_ESI[2]);
  return;
}


// ==== FUN_007c2ee0 @ 0x007c2ee0 ====

void FUN_007c2ee0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  int iVar3;
  int iStack_8;
  int iStack_4;
  
  iVar1 = param_1;
  iVar3 = *(int *)(param_1 + 0x38);
  param_1 = iVar3;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&param_1,4,unaff_ESI[2]);
  if (0 < iVar3) {
    iVar2 = 0;
    param_1 = iVar3;
    do {
      iVar3 = *(int *)(iVar2 + *(int *)(iVar1 + 0x18));
      if ((iVar3 == 0) || (iStack_4 = iVar3 + 0x10, iStack_4 == 0)) {
        iStack_4 = 0;
        (*(code *)unaff_ESI[1])(*unaff_ESI,&iStack_4,4,unaff_ESI[2]);
      }
      else {
        iVar3 = *(int *)(iVar3 + 0xc) + 1;
        iStack_8 = iVar3;
        (*(code *)unaff_ESI[1])(*unaff_ESI,&iStack_8,4,unaff_ESI[2]);
        (*(code *)unaff_ESI[1])(*unaff_ESI,iStack_4,iVar3,unaff_ESI[2]);
      }
      iStack_4 = *(int *)(*(int *)(iVar1 + 0x18) + 4 + iVar2);
      (*(code *)unaff_ESI[1])(*unaff_ESI,&iStack_4,4,unaff_ESI[2]);
      iStack_4 = *(int *)(*(int *)(iVar1 + 0x18) + 8 + iVar2);
      (*(code *)unaff_ESI[1])(*unaff_ESI,&iStack_4,4,unaff_ESI[2]);
      iVar2 = iVar2 + 0xc;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  return;
}


// ==== FUN_007c2fd0 @ 0x007c2fd0 ====

void FUN_007c2fd0(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  int iVar3;
  int local_8;
  int local_4;
  
  iVar3 = *(int *)(param_1 + 0x24);
  local_8 = iVar3;
  local_4 = iVar3;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&local_8,4,unaff_ESI[2]);
  iVar2 = 0;
  if (0 < iVar3) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + iVar2 * 4);
      if ((iVar1 == 0) || (iVar1 + 0x10 == 0)) {
        local_8 = 0;
        (*(code *)unaff_ESI[1])(*unaff_ESI,&local_8,4,unaff_ESI[2]);
      }
      else {
        iVar3 = *(int *)(iVar1 + 0xc) + 1;
        local_8 = iVar3;
        (*(code *)unaff_ESI[1])(*unaff_ESI,&local_8,4,unaff_ESI[2]);
        (*(code *)unaff_ESI[1])(*unaff_ESI,iVar1 + 0x10,iVar3,unaff_ESI[2]);
        iVar3 = local_4;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar3);
  }
  return;
}


// ==== FUN_007c3070 @ 0x007c3070 ====

void FUN_007c3070(int param_1)

{
  int iVar1;
  undefined4 *unaff_ESI;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined1 uStack_19;
  int iStack_18;
  int local_14;
  undefined8 uStack_10;
  
  iVar1 = *(int *)(param_1 + 0x28);
  local_14 = iVar1;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&local_14,4,unaff_ESI[2]);
  if (0 < iVar1) {
    iStack_18 = 0;
    local_14 = iVar1;
    do {
      uStack_19 = *(undefined1 *)(*(int *)(param_1 + 8) + iStack_18);
      piVar2 = (int *)(*(int *)(param_1 + 8) + iStack_18);
      (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_19,1,unaff_ESI[2]);
      if (*piVar2 == 3) {
        uVar5 = unaff_ESI[2];
        uStack_10 = *(longlong *)(piVar2 + 2);
        uVar4 = 8;
LAB_007c313e:
        (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_10,uVar4,uVar5);
      }
      else if (*piVar2 == 4) {
        iVar1 = piVar2[2];
        if ((iVar1 == 0) || (iVar1 + 0x10 == 0)) {
          uVar5 = unaff_ESI[2];
          uStack_10 = (ulonglong)uStack_10._4_4_ << 0x20;
          uVar4 = 4;
          goto LAB_007c313e;
        }
        iVar3 = *(int *)(iVar1 + 0xc) + 1;
        uStack_10 = CONCAT44(uStack_10._4_4_,iVar3);
        (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_10,4,unaff_ESI[2]);
        (*(code *)unaff_ESI[1])(*unaff_ESI,iVar1 + 0x10,iVar3,unaff_ESI[2]);
      }
      iStack_18 = iStack_18 + 0x10;
      local_14 = local_14 + -1;
    } while (local_14 != 0);
  }
  iVar1 = *(int *)(param_1 + 0x34);
  uStack_10 = CONCAT44(uStack_10._4_4_,iVar1);
  (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_10,4,unaff_ESI[2]);
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      FUN_007c31b0(*(undefined4 *)(*(int *)(param_1 + 0x10) + iVar3 * 4),
                   *(undefined4 *)(param_1 + 0x20));
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return;
}


// ==== FUN_007c31b0 @ 0x007c31b0 ====

void FUN_007c31b0(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_3;
  iVar1 = param_1;
  FUN_007c2e80();
  param_1 = *(undefined4 *)(iVar1 + 0x3c);
  (*(code *)puVar2[1])(*puVar2,&param_1,4,puVar2[2]);
  param_1._0_1_ = *(undefined1 *)(iVar1 + 0x44);
  (*(code *)puVar2[1])(*puVar2,&param_1,1,puVar2[2]);
  param_1._0_1_ = *(undefined1 *)(iVar1 + 0x45);
  (*(code *)puVar2[1])(*puVar2,&param_1,1,puVar2[2]);
  param_1._0_1_ = *(undefined1 *)(iVar1 + 0x46);
  (*(code *)puVar2[1])(*puVar2,&param_1,1,puVar2[2]);
  param_1 = CONCAT31(param_1._1_3_,*(undefined1 *)(iVar1 + 0x47));
  (*(code *)puVar2[1])(*puVar2,&param_1,1,puVar2[2]);
  param_1 = *(undefined4 *)(iVar1 + 0x30);
  (*(code *)puVar2[1])(*puVar2,&param_1,4,puVar2[2]);
  (*(code *)puVar2[1])(*puVar2,*(undefined4 *)(iVar1 + 0x14),*(int *)(iVar1 + 0x30) << 2,puVar2[2]);
  FUN_007c2ee0(iVar1);
  FUN_007c2fd0(iVar1);
  FUN_007c3070(iVar1);
  param_1 = *(undefined4 *)(iVar1 + 0x2c);
  (*(code *)puVar2[1])(*puVar2,&param_1,4,puVar2[2]);
  (*(code *)puVar2[1])(*puVar2,*(undefined4 *)(iVar1 + 0xc),*(int *)(iVar1 + 0x2c) << 2,puVar2[2]);
  return;
}


// ==== FUN_007c32c0 @ 0x007c32c0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007c32c0(void)

{
  undefined4 *unaff_ESI;
  undefined1 uStack_9;
  undefined8 uStack_8;
  
  (*(code *)unaff_ESI[1])(*unaff_ESI,&DAT_009fe688,4,unaff_ESI[2]);
  uStack_9 = 0x50;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_9,1,unaff_ESI[2]);
  uStack_9 = FUN_005fe0e0();
  (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_9,1,unaff_ESI[2]);
  uStack_9 = 4;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_9,1,unaff_ESI[2]);
  uStack_9 = 4;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_9,1,unaff_ESI[2]);
  uStack_9 = 4;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_9,1,unaff_ESI[2]);
  uStack_9 = 6;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_9,1,unaff_ESI[2]);
  uStack_9 = 8;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_9,1,unaff_ESI[2]);
  uStack_9 = 9;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_9,1,unaff_ESI[2]);
  uStack_9 = 9;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_9,1,unaff_ESI[2]);
  uStack_9 = 8;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_9,1,unaff_ESI[2]);
  uStack_8 = _DAT_009fe680;
  (*(code *)unaff_ESI[1])(*unaff_ESI,&uStack_8,8,unaff_ESI[2]);
  return;
}


// ==== FUN_007c33e0 @ 0x007c33e0 ====

void FUN_007c33e0(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_c = param_1;
  local_8 = param_3;
  local_4 = param_4;
  FUN_007c32c0();
  FUN_007c31b0(param_2,0,&local_c);
  return;
}


// ==== FUN_007c3420 @ 0x007c3420 ====

void * FUN_007c3420(int param_1,void *param_2,int param_3,uint param_4)

{
  int *piVar1;
  void *extraout_EAX;
  
  if (param_4 == 0) {
    if (param_2 == (void *)0x0) {
      return (void *)0x0;
    }
    _free(param_2);
    return extraout_EAX;
  }
  if (param_4 < 0xfffffffd) {
    param_2 = (void *)FUN_00806326(param_2,param_4);
    if (param_2 == (void *)0x0) {
      if (param_1 == 0) {
        return (void *)0x0;
      }
      FUN_007bd240(param_1,4);
    }
  }
  else {
    FUN_007be950(param_1,s_memory_allocation_error__block_t_009fe690);
  }
  if (param_1 != 0) {
    *(int *)(*(int *)(param_1 + 0x10) + 0x24) = *(int *)(*(int *)(param_1 + 0x10) + 0x24) - param_3;
    piVar1 = (int *)(*(int *)(param_1 + 0x10) + 0x24);
    *piVar1 = *piVar1 + param_4;
  }
  return param_2;
}


// ==== FUN_007c34b0 @ 0x007c34b0 ====

void FUN_007c34b0(undefined4 param_1,undefined4 param_2,int *param_3,int param_4,int param_5,
                 undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_3;
  iVar2 = iVar1 * 2;
  if (iVar2 < 4) {
    iVar3 = 4;
  }
  else {
    iVar3 = iVar2;
    if ((param_5 / 2 <= iVar1) && (iVar3 = param_5, param_5 + -4 <= iVar1)) {
      FUN_007be950(param_1,param_6);
      iVar3 = iVar2;
    }
  }
  FUN_007c3420(param_1,param_2,*param_3 * param_4,iVar3 * param_4);
  *param_3 = iVar3;
  return;
}


// ==== FUN_007c3520 @ 0x007c3520 ====

void FUN_007c3520(undefined4 param_1)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  
  iVar5 = 0;
  do {
    pcVar1 = (&PTR_DAT_009fe6b8)[iVar5];
    pcVar2 = pcVar1;
    do {
      cVar4 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar4 != '\0');
    iVar3 = FUN_007c1d70(param_1,pcVar1,(int)pcVar2 - (int)(pcVar1 + 1));
    *(byte *)(iVar3 + 5) = *(byte *)(iVar3 + 5) | 0x10;
    cVar4 = (char)iVar5;
    iVar5 = iVar5 + 1;
    *(char *)(iVar3 + 6) = cVar4 + '\x01';
  } while (iVar5 < 0x15);
  return;
}


// ==== FUN_007c3570 @ 0x007c3570 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007c3570(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 local_54 [80];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  uVar1 = *(undefined4 *)(param_1 + 0x34);
  FUN_007c1ac0(local_54,*(int *)(param_1 + 0x40) + 0x10,0x50);
  FUN_007c1aa0(uVar1,s__s__d___s_near___s__009fe7bc,local_54,param_4,param_2,param_3);
  FUN_007bd240(uVar1,3);
  return;
}


// ==== FUN_007c35e0 @ 0x007c35e0 ====

undefined4 FUN_007c35e0(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x101) {
    uVar1 = FUN_007c1aa0(*(undefined4 *)(param_1 + 0x34),&DAT_009fd94c,param_2);
    return uVar1;
  }
  return *(undefined4 *)(s_attempt_to__s__s___s___a__s_valu_009fe298 + param_2 * 4 + 0x1c);
}


// ==== FUN_007c3610 @ 0x007c3610 ====

void FUN_007c3610(uint param_1,uint *param_2,int *param_3,uint param_4)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  
  param_2[0xd] = param_1;
  param_2[1] = 1;
  param_2[2] = 1;
  param_2[8] = 0x11f;
  param_2[0xe] = (uint)param_3;
  param_2[0xc] = 0;
  param_2[0x10] = param_4;
  iVar1 = *param_3;
  *param_3 = iVar1 + -1;
  if (iVar1 == 0) {
    uVar3 = FUN_007c2ce0(param_2[0xe]);
  }
  else {
    pbVar2 = *(byte **)(param_2[0xe] + 4);
    uVar3 = (uint)*pbVar2;
    *(byte **)(param_2[0xe] + 4) = pbVar2 + 1;
  }
  *param_2 = uVar3;
  if (uVar3 == 0x23) {
    do {
      iVar1 = *(int *)param_2[0xe];
      *(int *)param_2[0xe] = iVar1 + -1;
      if (iVar1 == 0) {
        uVar3 = FUN_007c2ce0(param_2[0xe]);
      }
      else {
        pbVar2 = *(byte **)(param_2[0xe] + 4);
        uVar3 = (uint)*pbVar2;
        *(byte **)(param_2[0xe] + 4) = pbVar2 + 1;
      }
      *param_2 = uVar3;
    } while ((uVar3 != 10) && (uVar3 != 0xffffffff));
  }
  return;
}


// ==== FUN_007c36b0 @ 0x007c36b0 ====

int FUN_007c36b0(void)

{
  byte *pbVar1;
  uint _C;
  int iVar2;
  uint *unaff_ESI;
  int iVar3;
  
  iVar3 = 0;
  if (*(uint *)(unaff_ESI[0xf] + 4) < 5) {
    FUN_007c2e40(unaff_ESI[0xd],unaff_ESI[0xf],0x20);
  }
  do {
    if (*(uint *)(unaff_ESI[0xf] + 4) < iVar3 + 5U) {
      FUN_007c2e40(unaff_ESI[0xd],unaff_ESI[0xf],iVar3 + 0x20);
    }
    *(char *)(iVar3 + *(int *)unaff_ESI[0xf]) = (char)*unaff_ESI;
    iVar2 = *(int *)unaff_ESI[0xe];
    iVar3 = iVar3 + 1;
    *(int *)unaff_ESI[0xe] = iVar2 + -1;
    if (iVar2 == 0) {
      _C = FUN_007c2ce0(unaff_ESI[0xe]);
    }
    else {
      pbVar1 = *(byte **)(unaff_ESI[0xe] + 4);
      _C = (uint)*pbVar1;
      *(byte **)(unaff_ESI[0xe] + 4) = pbVar1 + 1;
    }
    *unaff_ESI = _C;
    iVar2 = _isalnum(_C);
  } while ((iVar2 != 0) || (*unaff_ESI == 0x5f));
  *(undefined1 *)(iVar3 + *(int *)unaff_ESI[0xf]) = 0;
  return iVar3;
}


// ==== FUN_007c3750 @ 0x007c3750 ====

void FUN_007c3750(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint *unaff_ESI;
  uint uVar5;
  
  if (*(uint *)(unaff_ESI[0xf] + 4) < 5) {
    FUN_007c2e40(unaff_ESI[0xd],unaff_ESI[0xf],0x20);
  }
  if (param_1 != 0) {
    **(undefined1 **)unaff_ESI[0xf] = 0x2e;
  }
  uVar5 = (uint)(param_1 != 0);
  iVar2 = _isdigit(*unaff_ESI);
  while (iVar2 != 0) {
    if (*(uint *)(unaff_ESI[0xf] + 4) < uVar5 + 5) {
      FUN_007c2e40(unaff_ESI[0xd],unaff_ESI[0xf],uVar5 + 0x20);
    }
    *(char *)(uVar5 + *(int *)unaff_ESI[0xf]) = (char)*unaff_ESI;
    iVar2 = *(int *)unaff_ESI[0xe];
    uVar5 = uVar5 + 1;
    *(int *)unaff_ESI[0xe] = iVar2 + -1;
    if (iVar2 == 0) {
      uVar3 = FUN_007c2ce0(unaff_ESI[0xe]);
    }
    else {
      pbVar1 = *(byte **)(unaff_ESI[0xe] + 4);
      uVar3 = (uint)*pbVar1;
      *(byte **)(unaff_ESI[0xe] + 4) = pbVar1 + 1;
    }
    *unaff_ESI = uVar3;
    iVar2 = _isdigit(uVar3);
  }
  uVar3 = uVar5;
  if (*unaff_ESI == 0x2e) {
    *(char *)(uVar5 + *(int *)unaff_ESI[0xf]) = (char)*unaff_ESI;
    iVar2 = *(int *)unaff_ESI[0xe];
    uVar3 = uVar5 + 1;
    *(int *)unaff_ESI[0xe] = iVar2 + -1;
    if (iVar2 == 0) {
      uVar4 = FUN_007c2ce0(unaff_ESI[0xe]);
    }
    else {
      pbVar1 = *(byte **)(unaff_ESI[0xe] + 4);
      uVar4 = (uint)*pbVar1;
      *(byte **)(unaff_ESI[0xe] + 4) = pbVar1 + 1;
    }
    *unaff_ESI = uVar4;
    if (uVar4 == 0x2e) {
      *(undefined1 *)(uVar3 + *(int *)unaff_ESI[0xf]) = 0x2e;
      iVar2 = *(int *)unaff_ESI[0xe];
      *(int *)unaff_ESI[0xe] = iVar2 + -1;
      if (iVar2 == 0) {
        uVar3 = FUN_007c2ce0(unaff_ESI[0xe]);
      }
      else {
        pbVar1 = *(byte **)(unaff_ESI[0xe] + 4);
        uVar3 = (uint)*pbVar1;
        *(byte **)(unaff_ESI[0xe] + 4) = pbVar1 + 1;
      }
      *unaff_ESI = uVar3;
      *(undefined1 *)(uVar5 + 2 + *(int *)unaff_ESI[0xf]) = 0;
      uVar3 = uVar5 + 3;
      FUN_007c3570();
    }
  }
  iVar2 = _isdigit(*unaff_ESI);
  while (iVar2 != 0) {
    if (*(uint *)(unaff_ESI[0xf] + 4) < uVar3 + 5) {
      FUN_007c2e40(unaff_ESI[0xd],unaff_ESI[0xf],uVar3 + 0x20);
    }
    *(char *)(uVar3 + *(int *)unaff_ESI[0xf]) = (char)*unaff_ESI;
    iVar2 = *(int *)unaff_ESI[0xe];
    uVar3 = uVar3 + 1;
    *(int *)unaff_ESI[0xe] = iVar2 + -1;
    if (iVar2 == 0) {
      uVar5 = FUN_007c2ce0(unaff_ESI[0xe]);
    }
    else {
      pbVar1 = *(byte **)(unaff_ESI[0xe] + 4);
      uVar5 = (uint)*pbVar1;
      *(byte **)(unaff_ESI[0xe] + 4) = pbVar1 + 1;
    }
    *unaff_ESI = uVar5;
    iVar2 = _isdigit(uVar5);
  }
  if ((*unaff_ESI == 0x65) || (*unaff_ESI == 0x45)) {
    *(char *)(uVar3 + *(int *)unaff_ESI[0xf]) = (char)*unaff_ESI;
    iVar2 = *(int *)unaff_ESI[0xe];
    uVar5 = uVar3 + 1;
    *(int *)unaff_ESI[0xe] = iVar2 + -1;
    if (iVar2 == 0) {
      uVar4 = FUN_007c2ce0(unaff_ESI[0xe]);
    }
    else {
      pbVar1 = *(byte **)(unaff_ESI[0xe] + 4);
      uVar4 = (uint)*pbVar1;
      *(byte **)(unaff_ESI[0xe] + 4) = pbVar1 + 1;
    }
    *unaff_ESI = uVar4;
    if ((uVar4 == 0x2b) || (uVar4 == 0x2d)) {
      *(char *)(uVar5 + *(int *)unaff_ESI[0xf]) = (char)*unaff_ESI;
      iVar2 = *(int *)unaff_ESI[0xe];
      uVar5 = uVar3 + 2;
      *(int *)unaff_ESI[0xe] = iVar2 + -1;
      if (iVar2 == 0) {
        uVar3 = FUN_007c2ce0(unaff_ESI[0xe]);
      }
      else {
        pbVar1 = *(byte **)(unaff_ESI[0xe] + 4);
        uVar3 = (uint)*pbVar1;
        *(byte **)(unaff_ESI[0xe] + 4) = pbVar1 + 1;
      }
      *unaff_ESI = uVar3;
    }
    iVar2 = _isdigit(*unaff_ESI);
    uVar3 = uVar5;
    while (iVar2 != 0) {
      if (*(uint *)(unaff_ESI[0xf] + 4) < uVar3 + 5) {
        FUN_007c2e40(unaff_ESI[0xd],unaff_ESI[0xf],uVar3 + 0x20);
      }
      *(char *)(uVar3 + *(int *)unaff_ESI[0xf]) = (char)*unaff_ESI;
      iVar2 = *(int *)unaff_ESI[0xe];
      uVar3 = uVar3 + 1;
      *(int *)unaff_ESI[0xe] = iVar2 + -1;
      if (iVar2 == 0) {
        uVar5 = FUN_007c2ce0(unaff_ESI[0xe]);
      }
      else {
        pbVar1 = *(byte **)(unaff_ESI[0xe] + 4);
        uVar5 = (uint)*pbVar1;
        *(byte **)(unaff_ESI[0xe] + 4) = pbVar1 + 1;
      }
      *unaff_ESI = uVar5;
      iVar2 = _isdigit(uVar5);
    }
  }
  *(undefined1 *)(uVar3 + *(int *)unaff_ESI[0xf]) = 0;
  iVar2 = FUN_007c1710(*(undefined4 *)unaff_ESI[0xf],param_2);
  if (iVar2 == 0) {
    FUN_007c3570();
  }
  return;
}


// ==== FUN_007c3a40 @ 0x007c3a40 ====

void FUN_007c3a40(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x116) {
    FUN_007c3570(param_1,param_2,*(int *)(param_1 + 0x18) + 0x10,*(undefined4 *)(param_1 + 4));
    return;
  }
  if ((0x11c < iVar1) && (iVar1 < 0x11f)) {
    FUN_007c3570(param_1,param_2,**(undefined4 **)(param_1 + 0x3c),*(undefined4 *)(param_1 + 4));
    return;
  }
  if (iVar1 < 0x101) {
    uVar2 = FUN_007c1aa0(*(undefined4 *)(param_1 + 0x34),&DAT_009fd94c,iVar1);
    FUN_007c3570(param_1,param_2,uVar2,*(undefined4 *)(param_1 + 4));
    return;
  }
  FUN_007c3570(param_1,param_2,
               *(undefined4 *)(s_attempt_to__s__s___s___a__s_valu_009fe298 + iVar1 * 4 + 0x1c),
               *(undefined4 *)(param_1 + 4));
  return;
}


// ==== FUN_007c3ae0 @ 0x007c3ae0 ====

void FUN_007c3ae0(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_3 < param_2) {
    uVar1 = FUN_007c1aa0(*(undefined4 *)(param_1 + 0x34),s_too_many__s__limit__d__009fe81c,param_4,
                         param_3);
    FUN_007c3a40(param_1,uVar1);
  }
  return;
}


// ==== FUN_007c3b10 @ 0x007c3b10 ====

void FUN_007c3b10(void)

{
  int iVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  uint *unaff_ESI;
  
  iVar1 = *(int *)unaff_ESI[0xe];
  *(int *)unaff_ESI[0xe] = iVar1 + -1;
  if (iVar1 == 0) {
    uVar4 = FUN_007c2ce0(unaff_ESI[0xe]);
  }
  else {
    pbVar2 = *(byte **)(unaff_ESI[0xe] + 4);
    uVar4 = (uint)*pbVar2;
    *(byte **)(unaff_ESI[0xe] + 4) = pbVar2 + 1;
  }
  uVar3 = unaff_ESI[1];
  *unaff_ESI = uVar4;
  unaff_ESI[1] = uVar3 + 1;
  if (0x7ffffffd < (int)(uVar3 + 1)) {
    FUN_007c1aa0(unaff_ESI[0xd],s_too_many__s__limit__d__009fe81c,s_lines_in_a_chunk_009fe834,
                 0x7ffffffd);
    FUN_007c3a40();
  }
  return;
}


// ==== FUN_007c3b70 @ 0x007c3b70 ====

void FUN_007c3b70(undefined4 *param_1)

{
  byte bVar1;
  byte *pbVar2;
  uint *in_EAX;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar6 = 0;
  if (*(uint *)(in_EAX[0xf] + 4) < 5) {
    FUN_007c2e40(in_EAX[0xd],in_EAX[0xf],0x20);
  }
  **(undefined1 **)in_EAX[0xf] = 0x5b;
  *(char *)(*(int *)in_EAX[0xf] + 1) = (char)*in_EAX;
  iVar8 = *(int *)in_EAX[0xe];
  *(int *)in_EAX[0xe] = iVar8 + -1;
  if (iVar8 == 0) {
    uVar3 = FUN_007c2ce0(in_EAX[0xe]);
  }
  else {
    pbVar2 = *(byte **)(in_EAX[0xe] + 4);
    uVar3 = (uint)*pbVar2;
    *(byte **)(in_EAX[0xe] + 4) = pbVar2 + 1;
  }
  *in_EAX = uVar3;
  iVar8 = 2;
  if (uVar3 == 10) {
    FUN_007c3b10();
  }
LAB_007c3be2:
  iVar7 = iVar8;
  if (*(uint *)(in_EAX[0xf] + 4) < iVar7 + 5U) {
    FUN_007c2e40(in_EAX[0xd],in_EAX[0xf],iVar7 + 0x20);
  }
  switch(*in_EAX) {
  default:
    *(char *)(iVar7 + *(int *)in_EAX[0xf]) = (char)*in_EAX;
    iVar8 = iVar7;
    break;
  case 10:
    *(undefined1 *)(iVar7 + *(int *)in_EAX[0xf]) = 10;
    FUN_007c3b10();
    iVar8 = iVar7 + 1;
    if (param_1 == (undefined4 *)0x0) {
      iVar8 = 0;
    }
    goto LAB_007c3be2;
  case 0x5b:
    *(char *)(iVar7 + *(int *)in_EAX[0xf]) = (char)*in_EAX;
    iVar5 = *(int *)in_EAX[0xe];
    iVar8 = iVar7 + 1;
    *(int *)in_EAX[0xe] = iVar5 + -1;
    if (iVar5 == 0) {
      uVar3 = FUN_007c2ce0(in_EAX[0xe]);
    }
    else {
      pbVar2 = *(byte **)(in_EAX[0xe] + 4);
      uVar3 = (uint)*pbVar2;
      *(byte **)(in_EAX[0xe] + 4) = pbVar2 + 1;
    }
    *in_EAX = uVar3;
    if (uVar3 != 0x5b) goto LAB_007c3be2;
    iVar6 = iVar6 + 1;
    *(undefined1 *)(iVar8 + *(int *)in_EAX[0xf]) = 0x5b;
    break;
  case 0x5d:
    goto switchD_007c3c13_caseD_5d;
  case 0xffffffff:
    *(undefined1 *)(iVar7 + *(int *)in_EAX[0xf]) = 0;
    FUN_007c3570();
    iVar8 = iVar7 + 1;
    goto LAB_007c3be2;
  }
  iVar5 = *(int *)in_EAX[0xe];
  *(int *)in_EAX[0xe] = iVar5 + -1;
  goto LAB_007c3c9b;
switchD_007c3c13_caseD_5d:
  *(char *)(iVar7 + *(int *)in_EAX[0xf]) = (char)*in_EAX;
  iVar5 = *(int *)in_EAX[0xe];
  iVar8 = iVar7 + 1;
  *(int *)in_EAX[0xe] = iVar5 + -1;
  if (iVar5 == 0) {
    uVar3 = FUN_007c2ce0(in_EAX[0xe]);
  }
  else {
    pbVar2 = *(byte **)(in_EAX[0xe] + 4);
    uVar3 = (uint)*pbVar2;
    *(byte **)(in_EAX[0xe] + 4) = pbVar2 + 1;
  }
  *in_EAX = uVar3;
  if (uVar3 == 0x5d) {
    *(undefined1 *)(iVar8 + *(int *)in_EAX[0xf]) = 0x5d;
    iVar5 = *(int *)in_EAX[0xe];
    *(int *)in_EAX[0xe] = iVar5 + -1;
    if (iVar6 == 0) {
      if (iVar5 == 0) {
        uVar3 = FUN_007c2ce0(in_EAX[0xe]);
      }
      else {
        pbVar2 = *(byte **)(in_EAX[0xe] + 4);
        uVar3 = (uint)*pbVar2;
        *(byte **)(in_EAX[0xe] + 4) = pbVar2 + 1;
      }
      *in_EAX = uVar3;
      *(undefined1 *)(iVar7 + 2 + *(int *)in_EAX[0xf]) = 0;
      if (param_1 != (undefined4 *)0x0) {
        uVar4 = FUN_007c1d70(in_EAX[0xd],*(int *)in_EAX[0xf] + 2,iVar7 + -2);
        *param_1 = uVar4;
      }
      return;
    }
    iVar6 = iVar6 + -1;
LAB_007c3c9b:
    if (iVar5 == 0) {
      uVar3 = FUN_007c2ce0(in_EAX[0xe]);
      *in_EAX = uVar3;
      iVar8 = iVar8 + 1;
    }
    else {
      pbVar2 = *(byte **)(in_EAX[0xe] + 4);
      bVar1 = *pbVar2;
      *(byte **)(in_EAX[0xe] + 4) = pbVar2 + 1;
      *in_EAX = (uint)bVar1;
      iVar8 = iVar8 + 1;
    }
  }
  goto LAB_007c3be2;
}


// ==== FUN_007c3e10 @ 0x007c3e10 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007c3e10(uint param_1,undefined4 *param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint uVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint *in_ECX;
  uint uVar9;
  int iVar10;
  int iVar11;
  int local_5c;
  undefined1 local_54 [80];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (*(uint *)(in_ECX[0xf] + 4) < 5) {
    FUN_007c2e40(in_ECX[0xd],in_ECX[0xf],0x20);
  }
  **(undefined1 **)in_ECX[0xf] = (char)*in_ECX;
  iVar11 = *(int *)in_ECX[0xe];
  iVar10 = 1;
  *(int *)in_ECX[0xe] = iVar11 + -1;
  if (iVar11 == 0) {
    uVar5 = FUN_007c2ce0(in_ECX[0xe]);
  }
  else {
    pbVar2 = *(byte **)(in_ECX[0xe] + 4);
    uVar5 = (uint)*pbVar2;
    *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
  }
  *in_ECX = uVar5;
  if (uVar5 != param_1) {
    uVar5 = 6;
    iVar11 = iVar10;
    do {
      if (*(uint *)(in_ECX[0xf] + 4) < uVar5) {
        FUN_007c2e40(in_ECX[0xd],in_ECX[0xf],iVar11 + 0x20);
      }
      uVar6 = *in_ECX;
      if (uVar6 == 0xffffffff) {
        *(undefined1 *)(iVar11 + *(int *)in_ECX[0xf]) = 0;
        puVar4 = PTR_s_<eof>_009fe730;
        uVar6 = in_ECX[1];
        uVar3 = in_ECX[0xd];
        iVar10 = iVar11 + 1;
        uVar9 = uVar5 + 1;
        FUN_007c1ac0(local_54,in_ECX[0x10] + 0x10,0x50);
        FUN_007c1aa0(uVar3,s__s__d___s_near___s__009fe7bc,local_54,uVar6,
                     s_unfinished_string_009fe878,puVar4);
        FUN_007bd240(uVar3,3);
      }
      else if (uVar6 == 10) {
        *(undefined1 *)(iVar11 + *(int *)in_ECX[0xf]) = 0;
        iVar10 = iVar11 + 1;
        uVar9 = uVar5 + 1;
        FUN_007c3570();
      }
      else if (uVar6 == 0x5c) {
        iVar10 = *(int *)in_ECX[0xe];
        *(int *)in_ECX[0xe] = iVar10 + -1;
        if (iVar10 == 0) {
          uVar6 = FUN_007c2ce0(in_ECX[0xe]);
        }
        else {
          pbVar2 = *(byte **)(in_ECX[0xe] + 4);
          uVar6 = (uint)*pbVar2;
          *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
        }
        *in_ECX = uVar6;
        uVar9 = uVar5;
        iVar10 = iVar11;
        switch(uVar6) {
        default:
          iVar10 = _isdigit(uVar6);
          if (iVar10 == 0) {
            *(char *)(iVar11 + *(int *)in_ECX[0xf]) = (char)*in_ECX;
            iVar7 = *(int *)in_ECX[0xe];
            iVar10 = iVar11 + 1;
            uVar9 = uVar5 + 1;
            *(int *)in_ECX[0xe] = iVar7 + -1;
            if (iVar7 == 0) goto LAB_007c40ce;
            pbVar2 = *(byte **)(in_ECX[0xe] + 4);
            bVar1 = *pbVar2;
            *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
            *in_ECX = (uint)bVar1;
          }
          else {
            iVar10 = 0;
            local_5c = 0;
            do {
              iVar10 = (*in_ECX - 0x30) + iVar10 * 10;
              iVar7 = *(int *)in_ECX[0xe];
              *(int *)in_ECX[0xe] = iVar7 + -1;
              if (iVar7 == 0) {
                uVar6 = FUN_007c2ce0(in_ECX[0xe]);
              }
              else {
                pbVar2 = *(byte **)(in_ECX[0xe] + 4);
                uVar6 = (uint)*pbVar2;
                *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
              }
              local_5c = local_5c + 1;
              *in_ECX = uVar6;
            } while ((local_5c < 3) && (iVar7 = _isdigit(uVar6), iVar7 != 0));
            if (0xff < iVar10) {
              *(undefined1 *)(iVar11 + *(int *)in_ECX[0xf]) = 0;
              iVar11 = iVar11 + 1;
              uVar5 = uVar5 + 1;
              FUN_007c3570();
            }
            *(char *)(iVar11 + *(int *)in_ECX[0xf]) = (char)iVar10;
            iVar10 = iVar11 + 1;
            uVar9 = uVar5 + 1;
          }
          break;
        case 10:
          *(undefined1 *)(iVar11 + *(int *)in_ECX[0xf]) = 10;
          iVar10 = iVar11 + 1;
          uVar9 = uVar5 + 1;
          FUN_007c3b10();
          break;
        case 0x61:
          *(undefined1 *)(iVar11 + *(int *)in_ECX[0xf]) = 7;
          iVar7 = *(int *)in_ECX[0xe];
          iVar10 = iVar11 + 1;
          uVar9 = uVar5 + 1;
          *(int *)in_ECX[0xe] = iVar7 + -1;
          if (iVar7 == 0) {
LAB_007c40ce:
            uVar6 = FUN_007c2ce0(in_ECX[0xe]);
            *in_ECX = uVar6;
            uVar9 = uVar5 + 1;
            iVar10 = iVar11 + 1;
          }
          else {
            pbVar2 = *(byte **)(in_ECX[0xe] + 4);
            bVar1 = *pbVar2;
            *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
            *in_ECX = (uint)bVar1;
          }
          break;
        case 0x62:
          *(undefined1 *)(iVar11 + *(int *)in_ECX[0xf]) = 8;
          iVar7 = *(int *)in_ECX[0xe];
          iVar10 = iVar11 + 1;
          uVar9 = uVar5 + 1;
          *(int *)in_ECX[0xe] = iVar7 + -1;
          if (iVar7 == 0) goto LAB_007c40ce;
          pbVar2 = *(byte **)(in_ECX[0xe] + 4);
          bVar1 = *pbVar2;
          *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
          *in_ECX = (uint)bVar1;
          break;
        case 0x66:
          *(undefined1 *)(iVar11 + *(int *)in_ECX[0xf]) = 0xc;
          iVar7 = *(int *)in_ECX[0xe];
          iVar10 = iVar11 + 1;
          uVar9 = uVar5 + 1;
          *(int *)in_ECX[0xe] = iVar7 + -1;
          if (iVar7 == 0) goto LAB_007c40ce;
          pbVar2 = *(byte **)(in_ECX[0xe] + 4);
          bVar1 = *pbVar2;
          *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
          *in_ECX = (uint)bVar1;
          break;
        case 0x6e:
          *(undefined1 *)(iVar11 + *(int *)in_ECX[0xf]) = 10;
          iVar7 = *(int *)in_ECX[0xe];
          iVar10 = iVar11 + 1;
          uVar9 = uVar5 + 1;
          *(int *)in_ECX[0xe] = iVar7 + -1;
          if (iVar7 == 0) goto LAB_007c40ce;
          pbVar2 = *(byte **)(in_ECX[0xe] + 4);
          bVar1 = *pbVar2;
          *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
          *in_ECX = (uint)bVar1;
          break;
        case 0x72:
          *(undefined1 *)(iVar11 + *(int *)in_ECX[0xf]) = 0xd;
          iVar7 = *(int *)in_ECX[0xe];
          iVar10 = iVar11 + 1;
          uVar9 = uVar5 + 1;
          *(int *)in_ECX[0xe] = iVar7 + -1;
          if (iVar7 == 0) goto LAB_007c40ce;
          pbVar2 = *(byte **)(in_ECX[0xe] + 4);
          bVar1 = *pbVar2;
          *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
          *in_ECX = (uint)bVar1;
          break;
        case 0x74:
          *(undefined1 *)(iVar11 + *(int *)in_ECX[0xf]) = 9;
          iVar7 = *(int *)in_ECX[0xe];
          iVar10 = iVar11 + 1;
          uVar9 = uVar5 + 1;
          *(int *)in_ECX[0xe] = iVar7 + -1;
          if (iVar7 == 0) goto LAB_007c40ce;
          pbVar2 = *(byte **)(in_ECX[0xe] + 4);
          bVar1 = *pbVar2;
          *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
          *in_ECX = (uint)bVar1;
          break;
        case 0x76:
          *(undefined1 *)(iVar11 + *(int *)in_ECX[0xf]) = 0xb;
          iVar7 = *(int *)in_ECX[0xe];
          iVar10 = iVar11 + 1;
          uVar9 = uVar5 + 1;
          *(int *)in_ECX[0xe] = iVar7 + -1;
          if (iVar7 == 0) goto LAB_007c40ce;
          pbVar2 = *(byte **)(in_ECX[0xe] + 4);
          bVar1 = *pbVar2;
          *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
          *in_ECX = (uint)bVar1;
          break;
        case 0xffffffff:
          break;
        }
      }
      else {
        *(char *)(iVar11 + *(int *)in_ECX[0xf]) = (char)*in_ECX;
        iVar10 = *(int *)in_ECX[0xe];
        *(int *)in_ECX[0xe] = iVar10 + -1;
        if (iVar10 == 0) goto LAB_007c40ce;
        pbVar2 = *(byte **)(in_ECX[0xe] + 4);
        bVar1 = *pbVar2;
        *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
        *in_ECX = (uint)bVar1;
        uVar9 = uVar5 + 1;
        iVar10 = iVar11 + 1;
      }
      uVar5 = uVar9;
      iVar11 = iVar10;
    } while (*in_ECX != param_1);
  }
  *(char *)(iVar10 + *(int *)in_ECX[0xf]) = (char)*in_ECX;
  iVar11 = *(int *)in_ECX[0xe];
  *(int *)in_ECX[0xe] = iVar11 + -1;
  if (iVar11 == 0) {
    uVar5 = FUN_007c2ce0(in_ECX[0xe]);
  }
  else {
    pbVar2 = *(byte **)(in_ECX[0xe] + 4);
    uVar5 = (uint)*pbVar2;
    *(byte **)(in_ECX[0xe] + 4) = pbVar2 + 1;
  }
  *in_ECX = uVar5;
  *(undefined1 *)(iVar10 + 1 + *(int *)in_ECX[0xf]) = 0;
  uVar8 = FUN_007c1d70(in_ECX[0xd],*(int *)in_ECX[0xf] + 1,iVar10 + -1);
  *param_2 = uVar8;
  return;
}


// ==== FUN_007c4310 @ 0x007c4310 ====

uint FUN_007c4310(uint *param_1,int *param_2)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  do {
    switch(*param_1) {
    default:
      iVar3 = _isspace(*param_1);
      if (iVar3 == 0) {
        iVar3 = _isdigit(*param_1);
        if (iVar3 != 0) {
          FUN_007c3750(0,param_2);
          return 0x11d;
        }
        iVar3 = _isalpha(*param_1);
        if ((iVar3 != 0) || (uVar4 = *param_1, uVar4 == 0x5f)) {
          uVar5 = FUN_007c36b0();
          iVar3 = FUN_007c1d70(param_1[0xd],*(undefined4 *)param_1[0xf],uVar5);
          if (*(byte *)(iVar3 + 6) == 0) {
            *param_2 = iVar3;
            return 0x116;
          }
          return *(byte *)(iVar3 + 6) + 0x100;
        }
        iVar3 = _iscntrl(uVar4);
        if (iVar3 != 0) {
          uVar5 = FUN_007c1aa0(param_1[0xd],s_char__d__009fe8c0,uVar4);
          FUN_007c3570(param_1,s_invalid_control_char_009fe8a8,uVar5,param_1[1]);
        }
        iVar3 = *(int *)param_1[0xe];
        *(int *)param_1[0xe] = iVar3 + -1;
        if (iVar3 == 0) {
          uVar6 = FUN_007c2ce0(param_1[0xe]);
          *param_1 = uVar6;
          return uVar4;
        }
        pbVar2 = *(byte **)(param_1[0xe] + 4);
        bVar1 = *pbVar2;
        *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
        *param_1 = (uint)bVar1;
        return uVar4;
      }
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
        *param_1 = uVar4;
      }
      else {
        pbVar2 = *(byte **)(param_1[0xe] + 4);
        bVar1 = *pbVar2;
        *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
        *param_1 = (uint)bVar1;
      }
      break;
    case 10:
      FUN_007c3b10();
      break;
    case 0x22:
    case 0x27:
      FUN_007c3e10(*param_1,param_2);
      return 0x11e;
    case 0x2d:
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
      }
      else {
        pbVar2 = *(byte **)(param_1[0xe] + 4);
        uVar4 = (uint)*pbVar2;
        *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      }
      *param_1 = uVar4;
      if (uVar4 != 0x2d) {
        return 0x2d;
      }
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
      }
      else {
        pbVar2 = *(byte **)(param_1[0xe] + 4);
        uVar4 = (uint)*pbVar2;
        *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      }
      *param_1 = uVar4;
      if (uVar4 == 0x5b) {
        iVar3 = *(int *)param_1[0xe];
        *(int *)param_1[0xe] = iVar3 + -1;
        if (iVar3 == 0) {
          uVar4 = FUN_007c2ce0(param_1[0xe]);
        }
        else {
          pbVar2 = *(byte **)(param_1[0xe] + 4);
          uVar4 = (uint)*pbVar2;
          *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
        }
        *param_1 = uVar4;
        if (uVar4 != 0x5b) goto LAB_007c43dd;
        FUN_007c3b70(0);
      }
      else {
LAB_007c43dd:
        uVar4 = *param_1;
        while ((uVar4 != 10 && (*param_1 != 0xffffffff))) {
          iVar3 = *(int *)param_1[0xe];
          *(int *)param_1[0xe] = iVar3 + -1;
          if (iVar3 == 0) {
            uVar4 = FUN_007c2ce0(param_1[0xe]);
          }
          else {
            pbVar2 = *(byte **)(param_1[0xe] + 4);
            uVar4 = (uint)*pbVar2;
            *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
          }
          *param_1 = uVar4;
        }
      }
      break;
    case 0x2e:
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
      }
      else {
        pbVar2 = *(byte **)(param_1[0xe] + 4);
        uVar4 = (uint)*pbVar2;
        *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      }
      *param_1 = uVar4;
      if (uVar4 != 0x2e) {
        iVar3 = _isdigit(uVar4);
        if (iVar3 == 0) {
          return 0x2e;
        }
        FUN_007c3750(1,param_2);
        return 0x11d;
      }
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
      }
      else {
        pbVar2 = *(byte **)(param_1[0xe] + 4);
        uVar4 = (uint)*pbVar2;
        *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      }
      *param_1 = uVar4;
      if (uVar4 != 0x2e) {
        return 0x117;
      }
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
        *param_1 = uVar4;
        return 0x118;
      }
      pbVar2 = *(byte **)(param_1[0xe] + 4);
      bVar1 = *pbVar2;
      *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      *param_1 = (uint)bVar1;
      return 0x118;
    case 0x3c:
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
      }
      else {
        pbVar2 = *(byte **)(param_1[0xe] + 4);
        uVar4 = (uint)*pbVar2;
        *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      }
      *param_1 = uVar4;
      if (uVar4 != 0x3d) {
        return 0x3c;
      }
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
        *param_1 = uVar4;
        return 0x11b;
      }
      pbVar2 = *(byte **)(param_1[0xe] + 4);
      bVar1 = *pbVar2;
      *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      *param_1 = (uint)bVar1;
      return 0x11b;
    case 0x3d:
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
      }
      else {
        pbVar2 = *(byte **)(param_1[0xe] + 4);
        uVar4 = (uint)*pbVar2;
        *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      }
      *param_1 = uVar4;
      if (uVar4 != 0x3d) {
        return 0x3d;
      }
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
        *param_1 = uVar4;
        return 0x119;
      }
      pbVar2 = *(byte **)(param_1[0xe] + 4);
      bVar1 = *pbVar2;
      *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      *param_1 = (uint)bVar1;
      return 0x119;
    case 0x3e:
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
      }
      else {
        pbVar2 = *(byte **)(param_1[0xe] + 4);
        uVar4 = (uint)*pbVar2;
        *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      }
      *param_1 = uVar4;
      if (uVar4 != 0x3d) {
        return 0x3e;
      }
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
        *param_1 = uVar4;
        return 0x11a;
      }
      pbVar2 = *(byte **)(param_1[0xe] + 4);
      bVar1 = *pbVar2;
      *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      *param_1 = (uint)bVar1;
      return 0x11a;
    case 0x5b:
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
      }
      else {
        pbVar2 = *(byte **)(param_1[0xe] + 4);
        uVar4 = (uint)*pbVar2;
        *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      }
      *param_1 = uVar4;
      if (uVar4 == 0x5b) {
        FUN_007c3b70(param_2);
        return 0x11e;
      }
      return 0x5b;
    case 0x7e:
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
      }
      else {
        pbVar2 = *(byte **)(param_1[0xe] + 4);
        uVar4 = (uint)*pbVar2;
        *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      }
      *param_1 = uVar4;
      if (uVar4 != 0x3d) {
        return 0x7e;
      }
      iVar3 = *(int *)param_1[0xe];
      *(int *)param_1[0xe] = iVar3 + -1;
      if (iVar3 == 0) {
        uVar4 = FUN_007c2ce0(param_1[0xe]);
        *param_1 = uVar4;
        return 0x11c;
      }
      pbVar2 = *(byte **)(param_1[0xe] + 4);
      bVar1 = *pbVar2;
      *(byte **)(param_1[0xe] + 4) = pbVar2 + 1;
      *param_1 = (uint)bVar1;
      return 0x11c;
    case 0xffffffff:
      return 0x11f;
    }
  } while( true );
}


// ==== FUN_007c48f0 @ 0x007c48f0 ====

void FUN_007c48f0(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
  if (*(int *)(in_EAX + 0x20) == 0x11f) {
    uVar1 = FUN_007c4310();
    *(undefined4 *)(in_EAX + 0x10) = uVar1;
    return;
  }
  *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_EAX + 0x20);
  *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
  *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
  *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
  *(undefined4 *)(in_EAX + 0x20) = 0x11f;
  return;
}


// ==== FUN_007c4940 @ 0x007c4940 ====

void FUN_007c4940(void)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  if (*(int *)(unaff_ESI + 0x10) == unaff_EDI) {
    FUN_007c48f0();
    return;
  }
  if (in_EAX == *(int *)(unaff_ESI + 4)) {
    uVar1 = FUN_007c35e0();
    FUN_007c1aa0(*(undefined4 *)(unaff_ESI + 0x34),s___s__expected_009fe8e8,uVar1);
    FUN_007c3a40();
    return;
  }
  uVar1 = FUN_007c35e0();
  uVar2 = FUN_007c35e0();
  FUN_007c1aa0(*(undefined4 *)(unaff_ESI + 0x34),s___s__expected__to_close___s__at_l_009fe8f8,uVar2,
               uVar1);
  FUN_007c3a40();
  return;
}


// ==== FUN_007c49b0 @ 0x007c49b0 ====

undefined4 FUN_007c49b0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x10) != 0x116) {
    FUN_007c3a40();
  }
  uVar1 = *(undefined4 *)(unaff_ESI + 0x18);
  *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(unaff_ESI + 4);
  if (*(int *)(unaff_ESI + 0x20) == 0x11f) {
    uVar2 = FUN_007c4310();
    *(undefined4 *)(unaff_ESI + 0x10) = uVar2;
    return uVar1;
  }
  *(undefined4 *)(unaff_ESI + 0x10) = *(undefined4 *)(unaff_ESI + 0x20);
  *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_ESI + 0x24);
  *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(unaff_ESI + 0x28);
  *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x2c);
  *(undefined4 *)(unaff_ESI + 0x20) = 0x11f;
  return uVar1;
}


// ==== FUN_007c4a20 @ 0x007c4a20 ====

void FUN_007c4a20(void)

{
  undefined4 uVar1;
  int in_ECX;
  undefined4 *unaff_ESI;
  
  uVar1 = FUN_007c8650(*(undefined4 *)(in_ECX + 0x30));
  unaff_ESI[3] = 0xffffffff;
  unaff_ESI[4] = 0xffffffff;
  *unaff_ESI = 4;
  unaff_ESI[1] = uVar1;
  return;
}


// ==== FUN_007c4a40 @ 0x007c4a40 ====

void FUN_007c4a40(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x30);
  iVar2 = *piVar1;
  if (*(int *)(iVar2 + 0x38) < piVar1[0xc] + 1) {
    uVar3 = FUN_007c34b0(*(undefined4 *)(in_ECX + 0x34),*(undefined4 *)(iVar2 + 0x18),iVar2 + 0x38,
                         0xc,0x7ffffffd,&DAT_0099cf70);
    *(undefined4 *)(iVar2 + 0x18) = uVar3;
  }
  *(undefined4 *)(*(int *)(iVar2 + 0x18) + piVar1[0xc] * 0xc) = param_1;
  piVar1[0xc] = piVar1[0xc] + 1;
  return;
}


// ==== FUN_007c4aa0 @ 0x007c4aa0 ====

void FUN_007c4aa0(void)

{
  int *piVar1;
  int in_EAX;
  int in_EDX;
  
  piVar1 = *(int **)(in_EAX + 0x30);
  piVar1[0xd] = piVar1[0xd] + in_EDX;
  for (; in_EDX != 0; in_EDX = in_EDX + -1) {
    *(int *)(*(int *)(*piVar1 + 0x18) + 4 + piVar1[(piVar1[0xd] - in_EDX) + 0xae] * 0xc) = piVar1[6]
    ;
  }
  return;
}


// ==== FUN_007c4ae0 @ 0x007c4ae0 ====

void FUN_007c4ae0(void)

{
  int *piVar1;
  int iVar2;
  int in_EAX;
  int in_EDX;
  
  piVar1 = *(int **)(in_EAX + 0x30);
  iVar2 = piVar1[0xd];
  while (in_EDX < iVar2) {
    iVar2 = piVar1[0xd];
    piVar1[0xd] = iVar2 + -1;
    *(int *)(*(int *)(*piVar1 + 0x18) + 8 + piVar1[iVar2 + 0xad] * 0xc) = piVar1[6];
    iVar2 = piVar1[0xd];
  }
  return;
}


// ==== FUN_007c4b20 @ 0x007c4b20 ====

void FUN_007c4b20(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  char *in_EDX;
  int unaff_EDI;
  
  do {
    cVar1 = *in_EDX;
    in_EDX = in_EDX + 1;
  } while (cVar1 != '\0');
  uVar3 = FUN_007c1d70(*(undefined4 *)(unaff_EDI + 0x34));
  iVar2 = *(int *)(unaff_EDI + 0x30);
  FUN_007c3ae0();
  uVar3 = FUN_007c4a40(uVar3);
  *(undefined4 *)(iVar2 + 0x2b8 + (*(int *)(iVar2 + 0x34) + param_1) * 4) = uVar3;
  return;
}


// ==== FUN_007c4b80 @ 0x007c4b80 ====

uint FUN_007c4b80(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int *piVar6;
  int *unaff_EBX;
  int *unaff_EDI;
  
  iVar2 = *unaff_EDI;
  uVar4 = 0;
  if (*(byte *)(iVar2 + 0x44) != 0) {
    piVar6 = unaff_EDI + 0xf;
    do {
      if ((piVar6[-1] == *unaff_EBX) && (*piVar6 == unaff_EBX[1])) {
        return uVar4;
      }
      uVar4 = uVar4 + 1;
      piVar6 = piVar6 + 5;
    } while ((int)uVar4 < (int)(uint)*(byte *)(iVar2 + 0x44));
  }
  FUN_007c3ae0(unaff_EDI[3],*(byte *)(iVar2 + 0x44) + 1,0x20,s_upvalues_009fe944);
  iVar3 = *unaff_EDI;
  if (*(int *)(iVar3 + 0x24) < (int)(*(byte *)(iVar2 + 0x44) + 1)) {
    uVar5 = FUN_007c34b0(unaff_EDI[4],*(undefined4 *)(iVar3 + 0x1c),iVar3 + 0x24,4,0x7ffffffd,
                         &DAT_0099cf70);
    *(undefined4 *)(*unaff_EDI + 0x1c) = uVar5;
  }
  *(undefined4 *)(*(int *)(*unaff_EDI + 0x1c) + (uint)*(byte *)(iVar2 + 0x44) * 4) = param_1;
  piVar6 = unaff_EDI + (uint)*(byte *)(iVar2 + 0x44) * 5 + 0xe;
  *piVar6 = *unaff_EBX;
  piVar6[1] = unaff_EBX[1];
  piVar6[2] = unaff_EBX[2];
  piVar6[3] = unaff_EBX[3];
  piVar6[4] = unaff_EBX[4];
  bVar1 = *(byte *)(iVar2 + 0x44);
  *(byte *)(iVar2 + 0x44) = bVar1 + 1;
  return (uint)bVar1;
}


// ==== FUN_007c4c40 @ 0x007c4c40 ====

void FUN_007c4c40(int *param_1,int param_2,int *param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == (int *)0x0) {
    param_3[3] = -1;
    param_3[4] = -1;
    *param_3 = 7;
    param_3[1] = 0xff;
    return;
  }
  iVar1 = param_1[0xd] + -1;
  if (-1 < iVar1) {
    piVar2 = param_1 + param_1[0xd] + 0xad;
    do {
      if (param_2 == *(int *)(*(int *)(*param_1 + 0x18) + *piVar2 * 0xc)) {
        if (-1 < iVar1) {
          param_3[3] = -1;
          param_3[4] = -1;
          *param_3 = 5;
          param_3[1] = iVar1;
          if (param_4 != 0) {
            return;
          }
          piVar2 = (int *)param_1[5];
          if (piVar2 == (int *)0x0) {
            return;
          }
          do {
            if (piVar2[2] <= iVar1) {
              piVar2[3] = 1;
              return;
            }
            piVar2 = (int *)*piVar2;
          } while (piVar2 != (int *)0x0);
          return;
        }
        break;
      }
      iVar1 = iVar1 + -1;
      piVar2 = piVar2 + -1;
    } while (-1 < iVar1);
  }
  FUN_007c4c40(param_1[2],param_2,param_3,0);
  if (*param_3 == 7) {
    if (param_4 != 0) {
      iVar1 = FUN_007c8650(param_1,param_2);
      param_3[1] = iVar1;
      return;
    }
  }
  else {
    iVar1 = FUN_007c4b80(param_2);
    *param_3 = 6;
    param_3[1] = iVar1;
  }
  return;
}


// ==== FUN_007c4d20 @ 0x007c4d20 ====

void FUN_007c4d20(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_EAX;
  int *in_ECX;
  int in_EDX;
  
  iVar1 = *(int *)(in_EAX + 0x30);
  param_1 = param_1 - in_EDX;
  if (*in_ECX != 0xc) {
    if (*in_ECX != 0) {
      FUN_007c8d80(iVar1);
    }
    if (0 < param_1) {
      uVar2 = *(undefined4 *)(iVar1 + 0x24);
      FUN_007c8560(iVar1,param_1);
      FUN_007c88e0(iVar1,uVar2,param_1);
    }
    return;
  }
  if (param_1 + 1 < 1) {
    FUN_007c86f0(iVar1);
    return;
  }
  FUN_007c8560(iVar1,param_1);
  FUN_007c86f0(iVar1);
  return;
}


// ==== FUN_007c4da0 @ 0x007c4da0 ====

void FUN_007c4da0(void)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int in_EAX;
  int unaff_EBX;
  
  piVar1 = *(int **)(in_EAX + 0x30);
  FUN_007c4aa0();
  FUN_007c3ae0();
  *(char *)(*piVar1 + 0x45) = (char)piVar1[0xd];
  *(char *)(*piVar1 + 0x46) = (char)unaff_EBX;
  if (unaff_EBX != 0) {
    FUN_007c4b20(0);
    piVar2 = *(int **)(in_EAX + 0x30);
    iVar3 = piVar2[0xd];
    piVar2[0xd] = iVar3 + 1;
    *(int *)(*(int *)(*piVar2 + 0x18) + 4 + piVar2[iVar3 + 0xae] * 0xc) = piVar2[6];
  }
  FUN_007c8560(piVar1,piVar1[0xd]);
  return;
}


// ==== FUN_007c4e10 @ 0x007c4e10 ====

void FUN_007c4e10(int *param_1)

{
  int *piVar1;
  undefined4 *in_EAX;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  
  piVar1 = *(int **)(in_ECX + 0x30);
  iVar3 = *piVar1;
  if (*(int *)(iVar3 + 0x34) < piVar1[0xb] + 1) {
    uVar2 = FUN_007c34b0(*(undefined4 *)(in_ECX + 0x34),*(undefined4 *)(iVar3 + 0x10),
                         (int *)(iVar3 + 0x34),4,0x3ffff,s_constant_table_overflow_009fe960);
    *(undefined4 *)(iVar3 + 0x10) = uVar2;
  }
  *(int *)(*(int *)(iVar3 + 0x10) + piVar1[0xb] * 4) = *param_1;
  iVar3 = piVar1[0xb];
  piVar1[0xb] = iVar3 + 1;
  uVar2 = FUN_007c88b0(piVar1,0x22,0,iVar3);
  in_EAX[3] = 0xffffffff;
  in_EAX[4] = 0xffffffff;
  *in_EAX = 10;
  in_EAX[1] = uVar2;
  iVar3 = 0;
  if (*(char *)(*param_1 + 0x44) != '\0') {
    piVar4 = param_1 + 0xe;
    do {
      FUN_007c8870(piVar1,(*piVar4 == 5) - 1U & 4,0,piVar4[1],0);
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 5;
    } while (iVar3 < (int)(uint)*(byte *)(*param_1 + 0x44));
  }
  return;
}


// ==== FUN_007c4ed0 @ 0x007c4ed0 ====

void FUN_007c4ed0(void)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  int unaff_EDI;
  
  iVar1 = FUN_007c1f80(*(undefined4 *)(unaff_EDI + 0x34));
  *unaff_ESI = iVar1;
  unaff_ESI[2] = *(int *)(unaff_EDI + 0x30);
  unaff_ESI[3] = unaff_EDI;
  unaff_ESI[4] = *(int *)(unaff_EDI + 0x34);
  *(int **)(unaff_EDI + 0x30) = unaff_ESI;
  unaff_ESI[6] = 0;
  unaff_ESI[7] = 0;
  unaff_ESI[8] = -1;
  unaff_ESI[9] = 0;
  unaff_ESI[10] = 0;
  iVar2 = FUN_007c24d0(*(undefined4 *)(unaff_EDI + 0x34),0,0);
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = 0;
  unaff_ESI[0xd] = 0;
  unaff_ESI[5] = 0;
  unaff_ESI[1] = iVar2;
  *(undefined4 *)(iVar1 + 0x20) = *(undefined4 *)(unaff_EDI + 0x40);
  *(undefined1 *)(iVar1 + 0x47) = 2;
  return;
}


// ==== FUN_007c4f30 @ 0x007c4f30 ====

void FUN_007c4f30(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 extraout_EDX;
  
  uVar4 = *(undefined4 *)(param_1 + 0x34);
  piVar1 = *(int **)(param_1 + 0x30);
  iVar2 = *piVar1;
  FUN_007c4ae0();
  FUN_007c8870(piVar1,0x1b,extraout_EDX,1,extraout_EDX);
  uVar3 = FUN_007c3420(uVar4,*(undefined4 *)(iVar2 + 0xc),*(int *)(iVar2 + 0x2c) << 2,piVar1[6] << 2
                      );
  *(undefined4 *)(iVar2 + 0xc) = uVar3;
  *(int *)(iVar2 + 0x2c) = piVar1[6];
  uVar3 = FUN_007c3420(uVar4,*(undefined4 *)(iVar2 + 0x14),*(int *)(iVar2 + 0x30) << 2,
                       piVar1[6] << 2);
  *(undefined4 *)(iVar2 + 0x14) = uVar3;
  *(int *)(iVar2 + 0x30) = piVar1[6];
  uVar3 = FUN_007c3420(uVar4,*(undefined4 *)(iVar2 + 8),*(int *)(iVar2 + 0x28) << 4,piVar1[10] << 4)
  ;
  *(undefined4 *)(iVar2 + 8) = uVar3;
  *(int *)(iVar2 + 0x28) = piVar1[10];
  uVar3 = FUN_007c3420(uVar4,*(undefined4 *)(iVar2 + 0x10),*(int *)(iVar2 + 0x34) << 2,
                       piVar1[0xb] << 2);
  *(undefined4 *)(iVar2 + 0x10) = uVar3;
  *(int *)(iVar2 + 0x34) = piVar1[0xb];
  uVar3 = FUN_007c3420(uVar4,*(undefined4 *)(iVar2 + 0x18),*(int *)(iVar2 + 0x38) * 0xc,
                       piVar1[0xc] * 0xc);
  *(undefined4 *)(iVar2 + 0x18) = uVar3;
  *(int *)(iVar2 + 0x38) = piVar1[0xc];
  uVar4 = FUN_007c3420(uVar4,*(undefined4 *)(iVar2 + 0x1c),*(int *)(iVar2 + 0x24) << 2,
                       (uint)*(byte *)(iVar2 + 0x44) << 2);
  *(undefined4 *)(iVar2 + 0x1c) = uVar4;
  *(uint *)(iVar2 + 0x24) = (uint)*(byte *)(iVar2 + 0x44);
  *(int *)(param_1 + 0x30) = piVar1[2];
  return;
}


// ==== FUN_007c5040 @ 0x007c5040 ====

void FUN_007c5040(void)

{
  undefined4 uVar1;
  int in_EAX;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(in_EAX + 0x30);
  FUN_007c8e00(uVar1);
  *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
  if (*(int *)(in_EAX + 0x20) == 0x11f) {
    uVar2 = FUN_007c4310();
    *(undefined4 *)(in_EAX + 0x10) = uVar2;
  }
  else {
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_EAX + 0x20);
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
    *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
    *(undefined4 *)(in_EAX + 0x20) = 0x11f;
  }
  uVar2 = FUN_007c49b0();
  FUN_007c8650(*(undefined4 *)(in_EAX + 0x30),uVar2);
  FUN_007c9370(uVar1);
  return;
}


// ==== FUN_007c50e0 @ 0x007c50e0 ====

void FUN_007c50e0(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(unaff_ESI + 4);
  piVar1 = (int *)(unaff_ESI + 0x10);
  if (*(int *)(unaff_ESI + 0x20) == 0x11f) {
    iVar2 = FUN_007c4310();
    *piVar1 = iVar2;
  }
  else {
    *piVar1 = *(int *)(unaff_ESI + 0x20);
    *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_ESI + 0x24);
    *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(unaff_ESI + 0x28);
    *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x2c);
    *(int *)(unaff_ESI + 0x20) = 0x11f;
  }
  FUN_007c5fd0();
  FUN_007c8e50(*(undefined4 *)(unaff_ESI + 0x30));
  if (*piVar1 == 0x5d) {
    FUN_007c48f0();
    return;
  }
  uVar3 = FUN_007c35e0();
  FUN_007c1aa0(*(undefined4 *)(unaff_ESI + 0x34),s___s__expected_009fe8e8,uVar3);
  FUN_007c3a40();
  return;
}


// ==== FUN_007c5180 @ 0x007c5180 ====

void FUN_007c5180(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_EAX;
  undefined4 uVar3;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [20];
  
  iVar1 = *(int *)(in_EAX + 0x30);
  uVar2 = *(undefined4 *)(iVar1 + 0x24);
  if (*(int *)(in_EAX + 0x10) == 0x116) {
    FUN_007c3ae0();
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
    uVar3 = FUN_007c49b0();
    local_24 = FUN_007c8650(*(undefined4 *)(in_EAX + 0x30),uVar3);
    local_1c = 0xffffffff;
    local_18 = 0xffffffff;
    local_28 = 4;
  }
  else {
    FUN_007c50e0();
  }
  if (*(int *)(in_EAX + 0x10) == 0x3d) {
    FUN_007c48f0();
  }
  else {
    uVar3 = FUN_007c35e0();
    FUN_007c1aa0(*(undefined4 *)(in_EAX + 0x34),s___s__expected_009fe8e8,uVar3);
    FUN_007c3a40();
  }
  FUN_007c8e70(iVar1,&local_28);
  FUN_007c5fd0();
  uVar3 = FUN_007c8e70(iVar1,local_14);
  uVar3 = FUN_007c8e70(iVar1,&local_28,uVar3);
  FUN_007c8870(iVar1,9,*(undefined4 *)(*(int *)(param_1 + 0x14) + 4),uVar3);
  *(undefined4 *)(iVar1 + 0x24) = uVar2;
  return;
}


// ==== FUN_007c5280 @ 0x007c5280 ====

void FUN_007c5280(void)

{
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_ESI[8] != 0) {
    if (*unaff_ESI == 0xc) {
      FUN_007c86f0();
      FUN_007c88b0();
      *(int *)(unaff_EDI + 0x24) = *(int *)(unaff_ESI[5] + 4) + 1;
      return;
    }
    if (*unaff_ESI != 0) {
      FUN_007c8d80();
    }
    FUN_007c88b0();
    *(int *)(unaff_EDI + 0x24) = *(int *)(unaff_ESI[5] + 4) + 1;
  }
  return;
}


// ==== FUN_007c52f0 @ 0x007c52f0 ====

void FUN_007c52f0(void)

{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  undefined4 *in_EAX;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  int in_ECX;
  int local_24 [3];
  undefined4 local_18;
  undefined4 local_14;
  undefined4 *local_10;
  undefined4 local_c;
  int local_8;
  int local_4;
  
  piVar4 = *(int **)(in_ECX + 0x30);
  iVar6 = FUN_007c8870(piVar4,10,0,0,0);
  in_EAX[3] = 0xffffffff;
  in_EAX[4] = 0xffffffff;
  *in_EAX = 10;
  in_EAX[1] = iVar6;
  local_18 = 0xffffffff;
  local_14 = 0xffffffff;
  local_4 = 0;
  local_c = 0;
  local_8 = 0;
  local_24[0] = 0;
  local_24[1] = 0;
  local_10 = in_EAX;
  FUN_007c8d80(*(undefined4 *)(in_ECX + 0x30));
  piVar1 = (int *)(in_ECX + 0x10);
  if (*(int *)(in_ECX + 0x10) == 0x7b) {
    FUN_007c48f0();
  }
  else {
    uVar7 = FUN_007c35e0();
    FUN_007c1aa0(*(undefined4 *)(in_ECX + 0x34),s___s__expected_009fe8e8,uVar7);
    FUN_007c3a40();
  }
  while( true ) {
    if (*piVar1 == 0x3b) {
      *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
      if (*(int *)(in_ECX + 0x20) == 0x11f) {
        iVar8 = FUN_007c4310();
        *piVar1 = iVar8;
      }
      else {
        *piVar1 = *(int *)(in_ECX + 0x20);
        *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x24);
        *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x28);
        *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 0x2c);
        *(int *)(in_ECX + 0x20) = 0x11f;
      }
    }
    if (*piVar1 == 0x7d) break;
    if (local_24[0] != 0) {
      FUN_007c8d80(piVar4,local_24);
      local_24[0] = 0;
      if (local_4 == 0x20) {
        FUN_007c88b0(piVar4,0x1f,local_10[1],local_8 + -1);
        local_4 = 0;
        piVar4[9] = local_10[1] + 1;
      }
    }
    if (*piVar1 == 0x5b) {
LAB_007c5496:
      FUN_007c5180(local_24);
    }
    else {
      if (*piVar1 == 0x116) {
        iVar8 = FUN_007c4310();
        *(int *)(in_ECX + 0x20) = iVar8;
        if (iVar8 == 0x3d) goto LAB_007c5496;
      }
      FUN_007c5fd0();
      FUN_007c3ae0();
      local_8 = local_8 + 1;
      local_4 = local_4 + 1;
    }
    if ((*piVar1 != 0x2c) && (*piVar1 != 0x3b)) break;
    piVar2 = (int *)(in_ECX + 0x20);
    *(undefined4 *)(in_ECX + 8) = *(undefined4 *)(in_ECX + 4);
    if (*piVar2 == 0x11f) {
      iVar8 = FUN_007c4310();
      *piVar1 = iVar8;
    }
    else {
      *piVar1 = *piVar2;
      *(undefined4 *)(in_ECX + 0x14) = *(undefined4 *)(in_ECX + 0x24);
      *(undefined4 *)(in_ECX + 0x18) = *(undefined4 *)(in_ECX + 0x28);
      *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(in_ECX + 0x2c);
      *piVar2 = 0x11f;
    }
  }
  FUN_007c4940(0x7b);
  FUN_007c5280();
  puVar3 = (uint *)(*(int *)(*piVar4 + 0xc) + iVar6 * 4);
  iVar8 = FUN_007c1640(local_8);
  uVar5 = *puVar3;
  *puVar3 = uVar5 ^ (iVar8 << 0xf ^ uVar5) & 0xff8000;
  puVar3 = (uint *)(*(int *)(*piVar4 + 0xc) + iVar6 * 4);
  iVar6 = FUN_007c1660(local_c);
  uVar5 = *puVar3;
  *puVar3 = uVar5 ^ ((iVar6 + 1) * 0x40 ^ uVar5) & 0x7fc0;
  return;
}


// ==== FUN_007c5570 @ 0x007c5570 ====

void FUN_007c5570(void)

{
  int iVar1;
  int in_EAX;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_c;
  
  local_c = 0;
  if (*(int *)(in_EAX + 0x10) == 0x29) {
LAB_007c56fc:
    FUN_007c4da0();
    return;
  }
LAB_007c5592:
  piVar6 = (int *)(in_EAX + 0x10);
  if (*piVar6 == 0x116) {
    uVar3 = FUN_007c49b0();
    iVar4 = *(int *)(in_EAX + 0x30);
    FUN_007c3ae0();
    piVar6 = *(int **)(in_EAX + 0x30);
    iVar1 = *piVar6;
    if (*(int *)(iVar1 + 0x38) < piVar6[0xc] + 1) {
      uVar2 = FUN_007c34b0(*(undefined4 *)(in_EAX + 0x34),*(undefined4 *)(iVar1 + 0x18),iVar1 + 0x38
                           ,0xc,0x7ffffffd,&DAT_0099cf70);
      *(undefined4 *)(iVar1 + 0x18) = uVar2;
    }
    *(undefined4 *)(*(int *)(iVar1 + 0x18) + piVar6[0xc] * 0xc) = uVar3;
    iVar1 = piVar6[0xc];
    piVar6[0xc] = iVar1 + 1;
    iVar5 = *(int *)(iVar4 + 0x34) + local_c;
    local_c = local_c + 1;
    *(int *)(iVar4 + 0x2b8 + iVar5 * 4) = iVar1;
  }
  else {
    if (*piVar6 == 0x118) {
      *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
      if (*(int *)(in_EAX + 0x20) != 0x11f) {
        *piVar6 = *(int *)(in_EAX + 0x20);
        *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
        *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
        *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
        *(int *)(in_EAX + 0x20) = 0x11f;
        FUN_007c4da0();
        return;
      }
      iVar4 = FUN_007c4310();
      *piVar6 = iVar4;
      goto LAB_007c56fc;
    }
    FUN_007c3a40();
  }
  if (*(int *)(in_EAX + 0x10) != 0x2c) goto LAB_007c56fc;
  *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
  if (*(int *)(in_EAX + 0x20) == 0x11f) {
    uVar3 = FUN_007c4310();
    *(undefined4 *)(in_EAX + 0x10) = uVar3;
  }
  else {
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_EAX + 0x20);
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
    *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
    *(undefined4 *)(in_EAX + 0x20) = 0x11f;
  }
  goto LAB_007c5592;
}


// ==== FUN_007c5710 @ 0x007c5710 ====

void FUN_007c5710(undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EBX;
  int local_5d8 [374];
  
  FUN_007c4ed0();
  *(undefined4 *)(local_5d8[0] + 0x3c) = param_3;
  if (*(int *)(unaff_EBX + 0x10) == 0x28) {
    FUN_007c48f0();
  }
  else {
    uVar3 = FUN_007c35e0();
    FUN_007c1aa0(*(undefined4 *)(unaff_EBX + 0x34),s___s__expected_009fe8e8,uVar3);
    FUN_007c3a40();
  }
  if (param_2 != 0) {
    FUN_007c4b20(0);
    piVar1 = *(int **)(unaff_EBX + 0x30);
    iVar2 = piVar1[0xd];
    piVar1[0xd] = iVar2 + 1;
    *(int *)(*(int *)(*piVar1 + 0x18) + 4 + piVar1[iVar2 + 0xae] * 0xc) = piVar1[6];
  }
  FUN_007c5570();
  if (*(int *)(unaff_EBX + 0x10) == 0x29) {
    FUN_007c48f0();
  }
  else {
    uVar3 = FUN_007c35e0();
    FUN_007c1aa0(*(undefined4 *)(unaff_EBX + 0x34),s___s__expected_009fe8e8,uVar3);
    FUN_007c3a40();
  }
  FUN_007c7640();
  FUN_007c4940(0x109);
  FUN_007c4f30();
  FUN_007c4e10(local_5d8);
  return;
}


// ==== FUN_007c5820 @ 0x007c5820 ====

int FUN_007c5820(void)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  int local_4;
  
  local_4 = 1;
  FUN_007c5fd0();
  piVar1 = (int *)(unaff_ESI + 0x10);
  while (*piVar1 == 0x2c) {
    *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(unaff_ESI + 4);
    if (*(int *)(unaff_ESI + 0x20) == 0x11f) {
      iVar2 = FUN_007c4310();
      *piVar1 = iVar2;
    }
    else {
      *piVar1 = *(int *)(unaff_ESI + 0x20);
      *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_ESI + 0x24);
      *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(unaff_ESI + 0x28);
      *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x2c);
      *(int *)(unaff_ESI + 0x20) = 0x11f;
    }
    FUN_007c8d80(*(undefined4 *)(unaff_ESI + 0x30));
    FUN_007c5fd0();
    local_4 = local_4 + 1;
  }
  return local_4;
}


// ==== FUN_007c58c0 @ 0x007c58c0 ====

void FUN_007c58c0(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_EAX;
  int iVar4;
  undefined4 uVar5;
  int local_14;
  undefined4 local_10;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(in_EAX + 0x10);
  iVar2 = *(int *)(in_EAX + 0x30);
  iVar3 = *(int *)(in_EAX + 4);
  if (iVar1 == 0x28) {
    if (iVar3 != *(int *)(in_EAX + 8)) {
      FUN_007c3a40();
    }
    FUN_007c48f0();
    if (*(int *)(in_EAX + 0x10) == 0x29) {
      local_14 = 0;
    }
    else {
      FUN_007c5820();
      FUN_007c86f0(iVar2,&local_14,0xffffffff);
    }
    FUN_007c4940(0x28);
  }
  else if (iVar1 == 0x7b) {
    FUN_007c52f0();
  }
  else {
    if (iVar1 != 0x11e) {
      FUN_007c3a40();
      return;
    }
    local_10 = FUN_007c8650(iVar2,*(undefined4 *)(in_EAX + 0x18));
    local_8 = 0xffffffff;
    local_4 = 0xffffffff;
    local_14 = 4;
    FUN_007c48f0();
  }
  iVar1 = param_1[1];
  if (local_14 == 0xc) {
    iVar4 = -1;
  }
  else {
    if (local_14 != 0) {
      FUN_007c8d80(iVar2,&local_14);
    }
    iVar4 = (*(int *)(iVar2 + 0x24) - iVar1) + -1;
  }
  uVar5 = FUN_007c8870(iVar2,0x19,iVar1,iVar4 + 1,2);
  param_1[3] = 0xffffffff;
  param_1[4] = 0xffffffff;
  *param_1 = 0xc;
  param_1[1] = uVar5;
  FUN_007c87a0(iVar2,iVar3);
  *(int *)(iVar2 + 0x24) = iVar1 + 1;
  return;
}


// ==== FUN_007c5a00 @ 0x007c5a00 ====

void FUN_007c5a00(void)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (*(int *)(in_EAX + 0x10) == 0x28) {
    FUN_007c48f0();
    FUN_007c5fd0();
    FUN_007c4940(0x28);
    FUN_007c8a30(*(undefined4 *)(in_EAX + 0x30));
    return;
  }
  if (*(int *)(in_EAX + 0x10) == 0x116) {
    uVar1 = FUN_007c49b0();
    FUN_007c4c40(*(undefined4 *)(in_EAX + 0x30),uVar1);
    return;
  }
  FUN_007c3a40();
  return;
}


// ==== FUN_007c5a70 @ 0x007c5a70 ====

void FUN_007c5a70(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_EAX;
  undefined4 uVar3;
  
  uVar1 = *(undefined4 *)(in_EAX + 0x30);
  FUN_007c5a00();
  iVar2 = *(int *)(in_EAX + 0x10);
  while (iVar2 - 0x28U < 0xf7) {
    switch(iVar2 - 0x28U) {
    case 0x28:
    case 0x7b:
    case 0x11e:
                    /* WARNING: This code block may not be properly labeled as switch case */
      FUN_007c8d80(uVar1);
      FUN_007c58c0();
      break;
    default:
      goto switchD_007c5aa7_caseD_29;
    case 0x2e:
      FUN_007c5040();
      break;
    case 0x3a:
      *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
      if (*(int *)(in_EAX + 0x20) == 0x11f) {
        uVar3 = FUN_007c4310();
        *(undefined4 *)(in_EAX + 0x10) = uVar3;
      }
      else {
        *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_EAX + 0x20);
        *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
        *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
        *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
        *(undefined4 *)(in_EAX + 0x20) = 0x11f;
      }
      uVar3 = FUN_007c49b0();
      FUN_007c8650(*(undefined4 *)(in_EAX + 0x30),uVar3);
      FUN_007c8fd0(uVar1);
      FUN_007c58c0();
      break;
    case 0x5b:
      FUN_007c8e00(uVar1);
      FUN_007c50e0();
      FUN_007c9370(uVar1);
    }
    iVar2 = *(int *)(in_EAX + 0x10);
  }
switchD_007c5aa7_caseD_29:
                    /* WARNING: This code block may not be properly labeled as switch case */
  return;
}


// ==== FUN_007c5ca0 @ 0x007c5ca0 ====

void FUN_007c5ca0(void)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  int in_ECX;
  
  switch(*(undefined4 *)(in_ECX + 0x10)) {
  case 0x7b:
    FUN_007c52f0();
    return;
  default:
    FUN_007c5a70();
    return;
  case 0x107:
    *in_EAX = 3;
    break;
  case 0x109:
    FUN_007c48f0();
    FUN_007c5710();
    return;
  case 0x10d:
    *in_EAX = 1;
    break;
  case 0x113:
    *in_EAX = 2;
    break;
  case 0x11d:
    uVar1 = FUN_007c8680(*(undefined4 *)(in_ECX + 0x30),*(undefined8 *)(in_ECX + 0x18));
    in_EAX[1] = uVar1;
    *in_EAX = 4;
    in_EAX[3] = 0xffffffff;
    in_EAX[4] = 0xffffffff;
    FUN_007c48f0();
    return;
  case 0x11e:
    FUN_007c4a20();
    FUN_007c48f0();
    return;
  }
  in_EAX[1] = 0;
  in_EAX[3] = 0xffffffff;
  in_EAX[4] = 0xffffffff;
  FUN_007c48f0();
  return;
}


// ==== FUN_007c5e30 @ 0x007c5e30 ====

undefined4 FUN_007c5e30(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0x2a:
    return 2;
  case 0x2b:
    return 0;
  default:
    return 0xe;
  case 0x2d:
    return 1;
  case 0x2f:
    return 3;
  case 0x3c:
    return 8;
  case 0x3e:
    return 10;
  case 0x5e:
    return 4;
  case 0x101:
    return 0xc;
  case 0x10f:
    return 0xd;
  case 0x117:
    return 5;
  case 0x119:
    return 7;
  case 0x11a:
    return 0xb;
  case 0x11b:
    return 9;
  case 0x11c:
    return 6;
  }
}


// ==== FUN_007c5fd0 @ 0x007c5fd0 ====

int FUN_007c5fd0(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_14 [20];
  
  iVar2 = *(int *)(param_1 + 0x44) + 1;
  *(int *)(param_1 + 0x44) = iVar2;
  if (200 < iVar2) {
    FUN_007c3a40(param_1,s_too_many_syntax_levels_009fea18);
  }
  if (*(int *)(param_1 + 0x10) == 0x2d) {
    uVar3 = 0;
  }
  else {
    if (*(int *)(param_1 + 0x10) != 0x10e) {
      FUN_007c5ca0();
      goto LAB_007c6041;
    }
    uVar3 = 1;
  }
  FUN_007c48f0();
  FUN_007c5fd0(param_1,param_2,8);
  FUN_007c9390(*(undefined4 *)(param_1 + 0x30),uVar3,param_2);
LAB_007c6041:
  iVar2 = FUN_007c5e30();
  while ((iVar2 != 0xe && (param_3 < (int)(uint)(byte)(&DAT_009fe8cc)[iVar2 * 2]))) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
    if (*(int *)(param_1 + 0x20) == 0x11f) {
      uVar3 = FUN_007c4310(param_1,param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x10) = uVar3;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x20) = 0x11f;
    }
    FUN_007c9450(*(undefined4 *)(param_1 + 0x30),iVar2,param_2);
    iVar1 = FUN_007c5fd0(param_1,local_14,(&DAT_009fe8cd)[iVar2 * 2]);
    FUN_007c9560(*(undefined4 *)(param_1 + 0x30),iVar2,param_2,local_14);
    iVar2 = iVar1;
  }
  *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + -1;
  return iVar2;
}


// ==== FUN_007c6110 @ 0x007c6110 ====

void FUN_007c6110(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EAX;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(in_EAX + 0x30);
  local_10 = 0xffffffff;
  local_4 = 0;
  local_c = *(undefined4 *)(iVar1 + 0x34);
  local_8 = 0;
  local_14 = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 **)(iVar1 + 0x14) = &local_14;
  FUN_007c7640();
  puVar2 = *(undefined4 **)(iVar1 + 0x14);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  FUN_007c4ae0();
  if (puVar2[3] != 0) {
    FUN_007c8870(iVar1,0x21,puVar2[2],0,0);
  }
  *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x34);
  FUN_007c8a10(iVar1,puVar2[1]);
  return;
}


// ==== FUN_007c61a0 @ 0x007c61a0 ====

void FUN_007c61a0(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int *in_EAX;
  int in_ECX;
  int unaff_EDI;
  
  iVar1 = *(int *)(in_ECX + 0x30);
  iVar2 = *(int *)(iVar1 + 0x24);
  bVar3 = false;
  if (in_EAX != (int *)0x0) {
    do {
      if (in_EAX[1] == 8) {
        if (in_EAX[2] == *(int *)(unaff_EDI + 4)) {
          bVar3 = true;
          in_EAX[2] = iVar2;
        }
        if (in_EAX[3] == *(int *)(unaff_EDI + 4)) {
          bVar3 = true;
          in_EAX[3] = iVar2;
        }
      }
      in_EAX = (int *)*in_EAX;
    } while (in_EAX != (int *)0x0);
    if (bVar3) {
      FUN_007c8870(iVar1,0,*(undefined4 *)(iVar1 + 0x24),*(undefined4 *)(unaff_EDI + 4),0);
      FUN_007c8560(iVar1,1);
    }
  }
  return;
}


// ==== FUN_007c6200 @ 0x007c6200 ====

void FUN_007c6200(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_2c;
  int local_28;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  
  if ((*(int *)(param_2 + 4) < 5) || (8 < *(int *)(param_2 + 4))) {
    FUN_007c3a40(param_1,s_syntax_error_009fea30);
  }
  if (*(int *)(param_1 + 0x10) == 0x2c) {
    FUN_007c48f0();
    local_18 = param_2;
    FUN_007c5a70();
    if (local_14 == 5) {
      FUN_007c61a0();
    }
    FUN_007c6200(param_1,&local_18,param_3 + 1);
  }
  else {
    if (*(int *)(param_1 + 0x10) == 0x3d) {
      FUN_007c48f0();
    }
    else {
      uVar1 = FUN_007c35e0(param_1,0x3d);
      uVar1 = FUN_007c1aa0(*(undefined4 *)(param_1 + 0x34),s___s__expected_009fe8e8,uVar1);
      FUN_007c3a40(param_1,uVar1);
    }
    iVar2 = FUN_007c5820();
    if (iVar2 == param_3) {
      FUN_007c86f0(*(undefined4 *)(param_1 + 0x30),&local_2c,1);
      FUN_007c8ef0(*(undefined4 *)(param_1 + 0x30),param_2 + 4,&local_2c);
      return;
    }
    FUN_007c4d20(param_3);
    if (param_3 < iVar2) {
      *(int *)(*(int *)(param_1 + 0x30) + 0x24) =
           *(int *)(*(int *)(param_1 + 0x30) + 0x24) + (param_3 - iVar2);
    }
  }
  local_28 = *(int *)(*(int *)(param_1 + 0x30) + 0x24) + -1;
  local_20 = 0xffffffff;
  local_1c = 0xffffffff;
  local_2c = 0xb;
  FUN_007c8ef0(*(int *)(param_1 + 0x30),param_2 + 4,&local_2c);
  return;
}


// ==== FUN_007c6330 @ 0x007c6330 ====

void FUN_007c6330(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 *puVar9;
  int iVar10;
  undefined4 *puVar11;
  char *pcVar12;
  int local_1e8;
  int local_1dc [3];
  int local_1d0;
  int local_1cc;
  undefined4 local_1c8;
  int local_1c4 [3];
  undefined4 local_1b8;
  undefined4 local_1b4;
  undefined4 local_1b0 [107];
  
  piVar2 = *(int **)(param_1 + 0x30);
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
  if (*(int *)(param_1 + 0x20) == 0x11f) {
    uVar7 = FUN_007c4310(param_1,param_1 + 0x18);
    *(undefined4 *)(param_1 + 0x10) = uVar7;
  }
  else {
    *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
    *(undefined4 *)(param_1 + 0x20) = 0x11f;
  }
  local_1c8 = FUN_007c8970(piVar2);
  iVar4 = FUN_007c8300(piVar2);
  FUN_007c5fd0(param_1,local_1dc,0xffffffff);
  if (local_1dc[0] == 4) {
    local_1dc[0] = 2;
  }
  uVar7 = *(undefined4 *)(param_1 + 4);
  FUN_007c91f0(piVar2,local_1dc);
  FUN_007c84d0(piVar2,&local_1cc,piVar2[8]);
  iVar10 = piVar2[6] - iVar4;
  piVar2[8] = -1;
  if (100 < iVar10) {
    FUN_007c3a40(param_1,s__while__condition_too_complex_009fea40);
  }
  if (0 < iVar10) {
    puVar9 = (undefined4 *)(*(int *)(*piVar2 + 0xc) + iVar4 * 4);
    puVar11 = local_1b0;
    for (iVar8 = iVar10; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar11 = *puVar9;
      puVar9 = puVar9 + 1;
      puVar11 = puVar11 + 1;
    }
  }
  piVar2[6] = iVar4;
  local_1c4[1] = 0xffffffff;
  local_1b4 = 1;
  local_1c4[2] = piVar2[0xd];
  local_1b8 = 0;
  local_1c4[0] = piVar2[5];
  piVar2[5] = (int)local_1c4;
  if (*(int *)(param_1 + 0x10) == 0x103) {
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
    if (*(int *)(param_1 + 0x20) == 0x11f) {
      uVar5 = FUN_007c4310(param_1,param_1 + 0x18);
      *(undefined4 *)(param_1 + 0x10) = uVar5;
    }
    else {
      *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
      *(undefined4 *)(param_1 + 0x20) = 0x11f;
    }
  }
  else {
    uVar5 = FUN_007c35e0(param_1,0x103);
    uVar5 = FUN_007c1aa0(*(undefined4 *)(param_1 + 0x34),s___s__expected_009fe8e8,uVar5);
    FUN_007c3a40(param_1,uVar5);
  }
  uVar5 = FUN_007c8300(piVar2);
  FUN_007c6110();
  FUN_007c8a10(piVar2,local_1c8);
  if (local_1d0 != -1) {
    local_1d0 = local_1d0 + (piVar2[6] - iVar4);
  }
  if (local_1cc != -1) {
    local_1cc = local_1cc + (piVar2[6] - iVar4);
  }
  local_1e8 = 0;
  if (0 < iVar10) {
    do {
      FUN_007c87c0(piVar2,local_1b0[local_1e8],uVar7);
      local_1e8 = local_1e8 + 1;
    } while (local_1e8 < iVar10);
  }
  if (*(int *)(param_1 + 0x10) == 0x106) {
    piVar1 = (int *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
    if (*piVar1 == 0x11f) {
      iVar4 = FUN_007c4310(param_1,param_1 + 0x18);
      *(int *)(param_1 + 0x10) = iVar4;
    }
    else {
      *(int *)(param_1 + 0x10) = *piVar1;
      *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
      *piVar1 = 0x11f;
    }
  }
  else {
    if (param_2 == *(int *)(param_1 + 4)) {
      uVar6 = FUN_007c35e0(param_1,0x106);
      uVar7 = *(undefined4 *)(param_1 + 0x34);
      pcVar12 = s___s__expected_009fe8e8;
    }
    else {
      uVar7 = FUN_007c35e0(param_1,0x115,param_2);
      uVar6 = FUN_007c35e0(param_1,0x106,uVar7);
      uVar7 = *(undefined4 *)(param_1 + 0x34);
      pcVar12 = s___s__expected__to_close___s__at_l_009fe8f8;
    }
    uVar7 = FUN_007c1aa0(uVar7,pcVar12,uVar6);
    FUN_007c3a40(param_1,uVar7);
  }
  piVar1 = (int *)piVar2[5];
  piVar2[5] = *piVar1;
  piVar3 = *(int **)(piVar2[3] + 0x30);
  iVar4 = piVar1[2];
  iVar10 = piVar3[0xd];
  while (iVar4 < iVar10) {
    iVar10 = piVar3[0xd];
    piVar3[0xd] = iVar10 + -1;
    *(int *)(*(int *)(*piVar3 + 0x18) + 8 + piVar3[iVar10 + 0xad] * 0xc) = piVar3[6];
    iVar10 = piVar3[0xd];
  }
  if (piVar1[3] != 0) {
    FUN_007c8870(piVar2,0x21,piVar1[2],0,0);
  }
  piVar2[9] = piVar2[0xd];
  FUN_007c8a10(piVar2,piVar1[1]);
  FUN_007c9760(piVar2,local_1d0,uVar5);
  FUN_007c8a10(piVar2,local_1cc);
  return;
}


// ==== FUN_007c6690 @ 0x007c6690 ====

void FUN_007c6690(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EAX;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14 [3];
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(in_EAX + 0x30);
  uVar3 = FUN_007c8300(iVar1);
  local_24 = 0xffffffff;
  local_18 = 1;
  local_20 = *(undefined4 *)(iVar1 + 0x34);
  local_1c = 0;
  local_28 = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 **)(iVar1 + 0x14) = &local_28;
  *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
  if (*(int *)(in_EAX + 0x20) == 0x11f) {
    uVar4 = FUN_007c4310();
    *(undefined4 *)(in_EAX + 0x10) = uVar4;
  }
  else {
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_EAX + 0x20);
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
    *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
    *(undefined4 *)(in_EAX + 0x20) = 0x11f;
  }
  FUN_007c6110();
  FUN_007c4940(0x110);
  FUN_007c5fd0();
  if (local_14[0] == 1) {
    local_14[0] = 3;
  }
  FUN_007c9140(*(undefined4 *)(in_EAX + 0x30),local_14);
  FUN_007c8a10(*(undefined4 *)(in_EAX + 0x30),local_8);
  FUN_007c9760(iVar1,local_4,uVar3);
  puVar2 = *(undefined4 **)(iVar1 + 0x14);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  FUN_007c4ae0();
  if (puVar2[3] != 0) {
    FUN_007c8870(iVar1,0x21,puVar2[2],0,0);
  }
  *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x34);
  FUN_007c8a10(iVar1,puVar2[1]);
  return;
}


// ==== FUN_007c67d0 @ 0x007c67d0 ====

void FUN_007c67d0(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EAX;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = *(int *)(in_ECX + 0x30);
  FUN_007c4aa0();
  if (*(int *)(in_ECX + 0x10) == 0x103) {
    FUN_007c48f0();
  }
  else {
    uVar4 = FUN_007c35e0();
    FUN_007c1aa0(*(undefined4 *)(in_ECX + 0x34),s___s__expected_009fe8e8,uVar4);
    FUN_007c3a40();
  }
  local_10 = 0xffffffff;
  local_4 = 1;
  local_c = *(undefined4 *)(iVar1 + 0x34);
  local_8 = 0;
  local_14 = *(undefined4 *)(iVar1 + 0x14);
  *(undefined4 **)(iVar1 + 0x14) = &local_14;
  iVar3 = FUN_007c8300(iVar1);
  FUN_007c6110();
  FUN_007c8a10(iVar1,iVar3 + -1);
  if (param_3 == 0) {
    uVar4 = FUN_007c8870(iVar1,0x1d,param_1,0,in_EAX + -3);
  }
  else {
    uVar4 = FUN_007c88b0(iVar1,0x1c,param_1,0x1fffe);
  }
  FUN_007c87a0(iVar1,param_2);
  if (param_3 == 0) {
    uVar4 = FUN_007c8970(iVar1);
  }
  FUN_007c9760(iVar1,uVar4,iVar3);
  puVar2 = *(undefined4 **)(iVar1 + 0x14);
  *(undefined4 *)(iVar1 + 0x14) = *puVar2;
  FUN_007c4ae0();
  if (puVar2[3] != 0) {
    FUN_007c8870(iVar1,0x21,puVar2[2],0,0);
  }
  *(undefined4 *)(iVar1 + 0x24) = *(undefined4 *)(iVar1 + 0x34);
  FUN_007c8a10(iVar1,puVar2[1]);
  return;
}


// ==== FUN_007c6920 @ 0x007c6920 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007c6920(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_EAX;
  undefined4 uVar4;
  undefined8 uVar5;
  undefined1 local_14 [20];
  
  iVar2 = *(int *)(in_EAX + 0x30);
  uVar3 = *(undefined4 *)(iVar2 + 0x24);
  FUN_007c3ae0();
  uVar4 = FUN_007c4a40(param_1);
  *(undefined4 *)(iVar2 + 0x2b8 + *(int *)(iVar2 + 0x34) * 4) = uVar4;
  FUN_007c4b20(1);
  FUN_007c4b20(2);
  if (*(int *)(in_EAX + 0x10) == 0x3d) {
    FUN_007c48f0();
  }
  else {
    uVar5 = CONCAT44(0x3d,in_EAX);
    uVar4 = FUN_007c35e0();
    FUN_007c1aa0(*(undefined4 *)(in_EAX + 0x34),s___s__expected_009fe8e8,uVar4,uVar5);
    FUN_007c3a40();
  }
  FUN_007c5fd0();
  FUN_007c8d80(*(undefined4 *)(in_EAX + 0x30),local_14);
  if (*(int *)(in_EAX + 0x10) == 0x2c) {
    FUN_007c48f0();
  }
  else {
    uVar5 = CONCAT44(0x2c,in_EAX);
    uVar4 = FUN_007c35e0();
    FUN_007c1aa0(*(undefined4 *)(in_EAX + 0x34),s___s__expected_009fe8e8,uVar4,uVar5);
    FUN_007c3a40();
  }
  FUN_007c5fd0();
  FUN_007c8d80(*(undefined4 *)(in_EAX + 0x30),local_14);
  if (*(int *)(in_EAX + 0x10) == 0x2c) {
    FUN_007c48f0();
    FUN_007c5fd0();
    FUN_007c8d80(*(undefined4 *)(in_EAX + 0x30),local_14);
  }
  else {
    uVar4 = FUN_007c8680(iVar2,_DAT_0099d0a0);
    FUN_007c88b0(iVar2,1,*(undefined4 *)(iVar2 + 0x24),uVar4);
    FUN_007c8560(iVar2,1);
  }
  iVar1 = *(int *)(iVar2 + 0x24) + -3;
  FUN_007c8870(iVar2,0xd,iVar1,iVar1,*(int *)(iVar2 + 0x24) + -1);
  FUN_007c8970(iVar2);
  FUN_007c67d0(uVar3,param_2,1);
  return;
}


// ==== FUN_007c6ab0 @ 0x007c6ab0 ====

void FUN_007c6ab0(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int in_EAX;
  undefined4 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int local_24;
  
  iVar3 = *(int *)(in_EAX + 0x30);
  uVar4 = *(undefined4 *)(iVar3 + 0x24);
  FUN_007c4b20(0);
  FUN_007c4b20(1);
  iVar7 = *(int *)(in_EAX + 0x30);
  FUN_007c3ae0();
  uVar6 = FUN_007c4a40(param_1);
  *(undefined4 *)(iVar7 + 0x2c0 + *(int *)(iVar7 + 0x34) * 4) = uVar6;
  local_24 = 3;
  while (piVar1 = (int *)(in_EAX + 0x10), *(int *)(in_EAX + 0x10) == 0x2c) {
    piVar2 = (int *)(in_EAX + 0x20);
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
    if (*(int *)(in_EAX + 0x20) == 0x11f) {
      iVar7 = FUN_007c4310();
      *piVar1 = iVar7;
    }
    else {
      *piVar1 = *piVar2;
      *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
      *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
      *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
      *piVar2 = 0x11f;
    }
    if (*piVar1 != 0x116) {
      FUN_007c3a40();
    }
    uVar6 = *(undefined4 *)(in_EAX + 0x18);
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
    if (*piVar2 == 0x11f) {
      iVar7 = FUN_007c4310();
      *piVar1 = iVar7;
    }
    else {
      *piVar1 = *piVar2;
      *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
      *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
      *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
      *piVar2 = 0x11f;
    }
    iVar7 = *(int *)(in_EAX + 0x30);
    FUN_007c3ae0();
    piVar1 = *(int **)(in_EAX + 0x30);
    iVar5 = *piVar1;
    if (*(int *)(iVar5 + 0x38) < piVar1[0xc] + 1) {
      uVar8 = FUN_007c34b0(*(undefined4 *)(in_EAX + 0x34),*(undefined4 *)(iVar5 + 0x18),iVar5 + 0x38
                           ,0xc,0x7ffffffd,&DAT_0099cf70);
      *(undefined4 *)(iVar5 + 0x18) = uVar8;
    }
    *(undefined4 *)(*(int *)(iVar5 + 0x18) + piVar1[0xc] * 0xc) = uVar6;
    iVar5 = piVar1[0xc];
    piVar1[0xc] = iVar5 + 1;
    iVar9 = *(int *)(iVar7 + 0x34) + local_24;
    local_24 = local_24 + 1;
    *(int *)(iVar7 + 0x2b8 + iVar9 * 4) = iVar5;
  }
  if (*piVar1 == 0x10b) {
    FUN_007c48f0();
  }
  else {
    uVar6 = FUN_007c35e0();
    FUN_007c1aa0(*(undefined4 *)(in_EAX + 0x34),s___s__expected_009fe8e8,uVar6);
    FUN_007c3a40();
  }
  uVar6 = *(undefined4 *)(in_EAX + 4);
  FUN_007c5820();
  FUN_007c4d20(local_24);
  FUN_007c8520(iVar3,3);
  FUN_007c88b0(iVar3,0x1e,uVar4,0x1fffe);
  FUN_007c67d0(uVar4,uVar6,0);
  return;
}


// ==== FUN_007c6cf0 @ 0x007c6cf0 ====

void FUN_007c6cf0(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_EAX;
  int iVar5;
  undefined4 uVar6;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar3 = *(int *)(in_EAX + 0x30);
  local_4 = 0;
  local_10 = 0xffffffff;
  local_c = *(undefined4 *)(iVar3 + 0x34);
  local_8 = 0;
  local_14 = *(undefined4 *)(iVar3 + 0x14);
  *(undefined4 **)(iVar3 + 0x14) = &local_14;
  piVar1 = (int *)(in_EAX + 0x20);
  *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
  piVar2 = (int *)(in_EAX + 0x10);
  if (*piVar1 == 0x11f) {
    iVar5 = FUN_007c4310();
    *piVar2 = iVar5;
  }
  else {
    *piVar2 = *piVar1;
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
    *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
    *piVar1 = 0x11f;
  }
  uVar6 = FUN_007c49b0();
  iVar5 = *piVar2;
  if (iVar5 != 0x2c) {
    if (iVar5 == 0x3d) {
      FUN_007c6920(uVar6,param_1);
      goto LAB_007c6daf;
    }
    if (iVar5 != 0x10b) {
      FUN_007c3a40();
      goto LAB_007c6daf;
    }
  }
  FUN_007c6ab0(uVar6);
LAB_007c6daf:
  FUN_007c4940(0x108);
  puVar4 = *(undefined4 **)(iVar3 + 0x14);
  *(undefined4 *)(iVar3 + 0x14) = *puVar4;
  FUN_007c4ae0();
  if (puVar4[3] != 0) {
    FUN_007c8870(iVar3,0x21,puVar4[2],0,0);
  }
  *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(iVar3 + 0x34);
  FUN_007c8a10(iVar3,puVar4[1]);
  return;
}


// ==== FUN_007c6e10 @ 0x007c6e10 ====

void FUN_007c6e10(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *unaff_EBX;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 8) = *(undefined4 *)(unaff_ESI + 4);
  piVar1 = (int *)(unaff_ESI + 0x10);
  if (*(int *)(unaff_ESI + 0x20) == 0x11f) {
    iVar2 = FUN_007c4310();
    *piVar1 = iVar2;
  }
  else {
    *piVar1 = *(int *)(unaff_ESI + 0x20);
    *(undefined4 *)(unaff_ESI + 0x14) = *(undefined4 *)(unaff_ESI + 0x24);
    *(undefined4 *)(unaff_ESI + 0x18) = *(undefined4 *)(unaff_ESI + 0x28);
    *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(unaff_ESI + 0x2c);
    *(int *)(unaff_ESI + 0x20) = 0x11f;
  }
  FUN_007c5fd0();
  if (*unaff_EBX == 1) {
    *unaff_EBX = 3;
  }
  FUN_007c9140(*(undefined4 *)(unaff_ESI + 0x30));
  FUN_007c8a10(*(undefined4 *)(unaff_ESI + 0x30),unaff_EBX[3]);
  if (*piVar1 == 0x112) {
    FUN_007c48f0();
    FUN_007c6110();
    return;
  }
  uVar3 = FUN_007c35e0();
  FUN_007c1aa0(*(undefined4 *)(unaff_ESI + 0x34),s___s__expected_009fe8e8,uVar3);
  FUN_007c3a40();
  FUN_007c6110();
  return;
}


// ==== FUN_007c6ee0 @ 0x007c6ee0 ====

void FUN_007c6ee0(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_EAX;
  undefined4 uVar3;
  undefined4 local_18 [5];
  undefined4 local_4;
  
  uVar1 = *(undefined4 *)(in_EAX + 0x30);
  local_18[0] = 0xffffffff;
  FUN_007c6e10();
  iVar2 = *(int *)(in_EAX + 0x10);
  while (iVar2 == 0x105) {
    uVar3 = FUN_007c8970(uVar1);
    FUN_007c84d0(uVar1,local_18,uVar3);
    FUN_007c8a10(uVar1,local_4);
    FUN_007c6e10();
    iVar2 = *(int *)(in_EAX + 0x10);
  }
  if (*(int *)(in_EAX + 0x10) == 0x104) {
    uVar3 = FUN_007c8970(uVar1);
    FUN_007c84d0(uVar1,local_18,uVar3);
    FUN_007c8a10(uVar1,local_4);
    FUN_007c48f0();
    FUN_007c6110();
  }
  else {
    FUN_007c84d0(uVar1,local_18,local_4);
  }
  FUN_007c8a10(uVar1,local_18[0]);
  FUN_007c4940(0x10a);
  return;
}


// ==== FUN_007c6fb0 @ 0x007c6fb0 ====

void FUN_007c6fb0(void)

{
  int iVar1;
  int *piVar2;
  int in_EAX;
  undefined4 uVar3;
  undefined4 local_28;
  int local_24;
  undefined4 local_1c;
  undefined4 local_18;
  undefined1 local_14 [20];
  
  uVar3 = FUN_007c49b0();
  iVar1 = *(int *)(in_EAX + 0x30);
  FUN_007c3ae0();
  uVar3 = FUN_007c4a40(uVar3);
  *(undefined4 *)(iVar1 + 0x2b8 + *(int *)(iVar1 + 0x34) * 4) = uVar3;
  local_24 = *(int *)(*(int *)(in_EAX + 0x30) + 0x24);
  *(int *)(*(int *)(in_EAX + 0x30) + 0x24) = local_24 + 1;
  local_1c = 0xffffffff;
  local_18 = 0xffffffff;
  piVar2 = *(int **)(in_EAX + 0x30);
  local_28 = 5;
  iVar1 = piVar2[0xd];
  piVar2[0xd] = iVar1 + 1;
  *(int *)(*(int *)(*piVar2 + 0x18) + 4 + piVar2[iVar1 + 0xae] * 0xc) = piVar2[6];
  FUN_007c5710(local_14,0,*(undefined4 *)(in_EAX + 4));
  FUN_007c8ef0(*(undefined4 *)(in_EAX + 0x30),&local_28,local_14);
  return;
}


// ==== FUN_007c7060 @ 0x007c7060 ====

void FUN_007c7060(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int in_EAX;
  undefined4 uVar4;
  int iVar5;
  int local_1c;
  
  local_1c = 0;
  while( true ) {
    if (*(int *)(in_EAX + 0x10) != 0x116) {
      FUN_007c3a40();
    }
    uVar2 = *(undefined4 *)(in_EAX + 0x18);
    piVar1 = (int *)(in_EAX + 0x20);
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
    if (*piVar1 == 0x11f) {
      iVar5 = FUN_007c4310();
      *(int *)(in_EAX + 0x10) = iVar5;
    }
    else {
      *(int *)(in_EAX + 0x10) = *piVar1;
      *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
      *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
      *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
      *piVar1 = 0x11f;
    }
    iVar5 = *(int *)(in_EAX + 0x30);
    FUN_007c3ae0();
    piVar1 = *(int **)(in_EAX + 0x30);
    iVar3 = *piVar1;
    if (*(int *)(iVar3 + 0x38) < piVar1[0xc] + 1) {
      uVar4 = FUN_007c34b0(*(undefined4 *)(in_EAX + 0x34),*(undefined4 *)(iVar3 + 0x18),iVar3 + 0x38
                           ,0xc,0x7ffffffd,&DAT_0099cf70);
      *(undefined4 *)(iVar3 + 0x18) = uVar4;
    }
    *(undefined4 *)(*(int *)(iVar3 + 0x18) + piVar1[0xc] * 0xc) = uVar2;
    iVar3 = piVar1[0xc];
    piVar1[0xc] = iVar3 + 1;
    piVar1 = (int *)(in_EAX + 0x10);
    *(int *)(iVar5 + 0x2b8 + (*(int *)(iVar5 + 0x34) + local_1c) * 4) = iVar3;
    local_1c = local_1c + 1;
    if (*piVar1 != 0x2c) break;
    *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
    if (*(int *)(in_EAX + 0x20) == 0x11f) {
      iVar5 = FUN_007c4310();
      *piVar1 = iVar5;
    }
    else {
      *piVar1 = *(int *)(in_EAX + 0x20);
      *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
      *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
      *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
      *(int *)(in_EAX + 0x20) = 0x11f;
    }
  }
  if (*piVar1 == 0x3d) {
    FUN_007c48f0();
    FUN_007c5820();
  }
  FUN_007c4d20(local_1c);
  FUN_007c4aa0();
  return;
}


// ==== FUN_007c71f0 @ 0x007c71f0 ====

undefined4 FUN_007c71f0(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  uVar2 = FUN_007c49b0();
  FUN_007c4c40(*(undefined4 *)(in_ECX + 0x30),uVar2);
  iVar1 = *(int *)(in_ECX + 0x10);
  while (iVar1 == 0x2e) {
    FUN_007c5040();
    iVar1 = *(int *)(in_ECX + 0x10);
  }
  if (*(int *)(in_ECX + 0x10) == 0x3a) {
    FUN_007c5040();
    return 1;
  }
  return 0;
}


// ==== FUN_007c7250 @ 0x007c7250 ====

void FUN_007c7250(void)

{
  int in_EAX;
  undefined4 uVar1;
  undefined1 local_28 [20];
  undefined1 local_14 [20];
  
  *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
  if (*(int *)(in_EAX + 0x20) == 0x11f) {
    uVar1 = FUN_007c4310();
    *(undefined4 *)(in_EAX + 0x10) = uVar1;
  }
  else {
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(in_EAX + 0x20);
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
    *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
    *(undefined4 *)(in_EAX + 0x20) = 0x11f;
  }
  uVar1 = FUN_007c71f0();
  FUN_007c5710(local_28,uVar1);
  FUN_007c8ef0(*(undefined4 *)(in_EAX + 0x30),local_14,local_28);
  FUN_007c87a0(*(undefined4 *)(in_EAX + 0x30));
  return;
}


// ==== FUN_007c72e0 @ 0x007c72e0 ====

void FUN_007c72e0(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  int local_14 [5];
  
  uVar1 = *(undefined4 *)(unaff_ESI + 0x30);
  FUN_007c5a70();
  if (local_14[0] == 0xc) {
    FUN_007c86f0(uVar1,local_14,0);
    return;
  }
  FUN_007c6200();
  return;
}


// ==== FUN_007c7330 @ 0x007c7330 ====

void FUN_007c7330(void)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int local_14;
  int local_10;
  
  piVar2 = *(int **)(in_EAX + 0x30);
  *(undefined4 *)(in_EAX + 8) = *(undefined4 *)(in_EAX + 4);
  piVar1 = (int *)(in_EAX + 0x10);
  if (*(int *)(in_EAX + 0x20) == 0x11f) {
    iVar3 = FUN_007c4310();
    *piVar1 = iVar3;
  }
  else {
    *piVar1 = *(int *)(in_EAX + 0x20);
    *(undefined4 *)(in_EAX + 0x14) = *(undefined4 *)(in_EAX + 0x24);
    *(undefined4 *)(in_EAX + 0x18) = *(undefined4 *)(in_EAX + 0x28);
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x2c);
    *(int *)(in_EAX + 0x20) = 0x11f;
  }
  switch(*piVar1) {
  case 0x104:
  case 0x105:
  case 0x106:
  case 0x114:
  case 0x11f:
    break;
  default:
    if (*piVar1 != 0x3b) {
      iVar3 = FUN_007c5820();
      if (local_14 == 0xc) {
        FUN_007c86f0(piVar2,&local_14,0xffffffff);
        if (iVar3 == 1) {
          *(uint *)(*(int *)(*piVar2 + 0xc) + local_10 * 4) =
               *(uint *)(*(int *)(*piVar2 + 0xc) + local_10 * 4) & 0xffffffda | 0x1a;
        }
        iVar4 = piVar2[0xd];
        iVar3 = -1;
      }
      else if (iVar3 == 1) {
        iVar4 = FUN_007c8e00(piVar2,&local_14);
      }
      else {
        FUN_007c8d80(piVar2,&local_14);
        iVar4 = piVar2[0xd];
      }
      goto LAB_007c7415;
    }
  }
  iVar3 = 0;
  iVar4 = 0;
LAB_007c7415:
  FUN_007c8870(piVar2,0x1b,iVar4,iVar3 + 1,0);
  return;
}


// ==== FUN_007c7460 @ 0x007c7460 ====

void FUN_007c7460(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  uint uVar4;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x30);
  puVar2 = *(undefined4 **)(iVar1 + 0x14);
  *(undefined4 *)(unaff_EDI + 8) = *(undefined4 *)(unaff_EDI + 4);
  uVar4 = 0;
  if (*(int *)(unaff_EDI + 0x20) == 0x11f) {
    uVar3 = FUN_007c4310();
    *(undefined4 *)(unaff_EDI + 0x10) = uVar3;
  }
  else {
    *(undefined4 *)(unaff_EDI + 0x10) = *(undefined4 *)(unaff_EDI + 0x20);
    *(undefined4 *)(unaff_EDI + 0x14) = *(undefined4 *)(unaff_EDI + 0x24);
    *(undefined4 *)(unaff_EDI + 0x18) = *(undefined4 *)(unaff_EDI + 0x28);
    *(undefined4 *)(unaff_EDI + 0x1c) = *(undefined4 *)(unaff_EDI + 0x2c);
    *(undefined4 *)(unaff_EDI + 0x20) = 0x11f;
  }
  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    if (puVar2[4] != 0) goto LAB_007c74e0;
    uVar4 = uVar4 | puVar2[3];
  }
  FUN_007c3a40();
LAB_007c74e0:
  if (uVar4 != 0) {
    FUN_007c8870(iVar1,0x21,puVar2[2],0,0);
  }
  uVar3 = FUN_007c8970(iVar1);
  FUN_007c84d0(iVar1,puVar2 + 1,uVar3);
  return;
}


// ==== FUN_007c7510 @ 0x007c7510 ====

undefined4 FUN_007c7510(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  
  uVar1 = *(undefined4 *)(unaff_EBX + 4);
  switch(*(undefined4 *)(unaff_EBX + 0x10)) {
  case 0x102:
    FUN_007c7460();
    return 1;
  case 0x103:
    FUN_007c48f0();
    FUN_007c6110();
    FUN_007c4940(0x103);
    return 0;
  default:
    FUN_007c72e0();
    return 0;
  case 0x108:
    FUN_007c6cf0(uVar1);
    return 0;
  case 0x109:
    FUN_007c7250();
    return 0;
  case 0x10a:
    FUN_007c6ee0(uVar1);
    return 0;
  case 0x10c:
    break;
  case 0x110:
    FUN_007c6690(uVar1);
    return 0;
  case 0x111:
    FUN_007c7330();
    return 1;
  case 0x115:
    FUN_007c6330();
    return 0;
  }
  FUN_007c48f0();
  if (*(int *)(unaff_EBX + 0x10) == 0x109) {
    FUN_007c48f0();
    FUN_007c6fb0();
    return 0;
  }
  FUN_007c7060();
  return 0;
}


// ==== FUN_007c7640 @ 0x007c7640 ====

void FUN_007c7640(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x44) + 1;
  *(int *)(param_1 + 0x44) = iVar4;
  if (200 < iVar4) {
    FUN_007c3a40(param_1,s_too_many_syntax_levels_009fea18);
  }
  piVar1 = (int *)(param_1 + 0x10);
  do {
    switch(*piVar1) {
    case 0x104:
    case 0x105:
    case 0x106:
    case 0x114:
    case 0x11f:
      goto switchD_007c7683_caseD_104;
    }
    iVar4 = FUN_007c7510();
    if (*piVar1 == 0x3b) {
      piVar2 = (int *)(param_1 + 0x20);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(param_1 + 4);
      if (*piVar2 == 0x11f) {
        iVar3 = FUN_007c4310(param_1,param_1 + 0x18);
        *piVar1 = iVar3;
      }
      else {
        *piVar1 = *piVar2;
        *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x24);
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x28);
        *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x2c);
        *piVar2 = 0x11f;
      }
    }
    *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x24) =
         *(undefined4 *)(*(int *)(param_1 + 0x30) + 0x34);
  } while (iVar4 == 0);
switchD_007c7683_caseD_104:
  *(int *)(param_1 + 0x44) = *(int *)(param_1 + 0x44) + -1;
  return;
}


// ==== FUN_007c7720 @ 0x007c7720 ====

undefined4 FUN_007c7720(undefined4 param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  undefined4 uVar4;
  undefined1 local_620 [4];
  undefined4 local_61c;
  undefined4 local_618;
  int local_610;
  undefined4 local_60c;
  undefined4 local_608;
  undefined4 local_604;
  int local_600;
  undefined4 local_5fc;
  undefined4 local_5f8;
  undefined4 local_5f4;
  undefined4 local_5e4;
  undefined4 local_5dc;
  undefined4 local_5d8;
  
  pcVar2 = *(char **)(param_2 + 0x10);
  local_5e4 = param_3;
  local_5dc = 0;
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  uVar4 = FUN_007c1d70(param_1,pcVar2,(int)pcVar3 - (int)(pcVar2 + 1));
  FUN_007c3610(param_1,local_620,param_2,uVar4);
  FUN_007c4ed0();
  local_618 = local_61c;
  if (local_600 == 0x11f) {
    local_610 = FUN_007c4310(local_620,&local_608);
  }
  else {
    local_610 = local_600;
    local_60c = local_5fc;
    local_608 = local_5f8;
    local_604 = local_5f4;
    local_600 = 0x11f;
  }
  FUN_007c7640(local_620);
  if (local_610 != 0x11f) {
    FUN_007c3a40(local_620,s_<eof>_expected_009feac0);
  }
  FUN_007c4f30(local_620);
  return local_5d8;
}


// ==== FUN_007c7810 @ 0x007c7810 ====

void FUN_007c7810(void)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int in_ECX;
  uint uVar3;
  undefined4 *unaff_ESI;
  undefined1 *puVar4;
  
  if (unaff_ESI[3] == 0) {
    iVar2 = FUN_007c2da0(unaff_ESI[1]);
    if (iVar2 != 0) {
      FUN_007be950(*unaff_ESI,s_unexpected_end_of_file_in__s_009fead0,unaff_ESI[4]);
      return;
    }
  }
  else {
    puVar4 = (undefined1 *)(in_ECX + -1 + in_EAX);
    if (in_EAX != 0) {
      do {
        iVar2 = *(int *)unaff_ESI[1];
        *(int *)unaff_ESI[1] = iVar2 + -1;
        iVar1 = unaff_ESI[1];
        if (iVar2 == 0) {
          uVar3 = FUN_007c2ce0(iVar1);
        }
        else {
          uVar3 = (uint)**(byte **)(iVar1 + 4);
          *(byte **)(iVar1 + 4) = *(byte **)(iVar1 + 4) + 1;
        }
        if (uVar3 == 0xffffffff) {
          FUN_007be950(*unaff_ESI,s_unexpected_end_of_file_in__s_009fead0,unaff_ESI[4]);
        }
        *puVar4 = (char)uVar3;
        puVar4 = puVar4 + -1;
        in_EAX = in_EAX + -1;
      } while (in_EAX != 0);
    }
  }
  return;
}


// ==== FUN_007c78a0 @ 0x007c78a0 ====

void FUN_007c78a0(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int in_ECX;
  uint uVar3;
  undefined4 *unaff_ESI;
  undefined1 *puVar4;
  int local_c;
  undefined1 *local_8;
  int local_4;
  
  if (unaff_ESI[3] == 0) {
    iVar2 = FUN_007c2da0(unaff_ESI[1]);
    if (iVar2 != 0) {
      FUN_007be950(*unaff_ESI,s_unexpected_end_of_file_in__s_009fead0,unaff_ESI[4]);
    }
  }
  else if (in_EAX != 0) {
    local_8 = (undefined1 *)(in_ECX + param_1 + -1);
    local_4 = in_EAX;
    do {
      if (param_1 != 0) {
        local_c = param_1;
        puVar4 = local_8;
        do {
          iVar2 = *(int *)unaff_ESI[1];
          *(int *)unaff_ESI[1] = iVar2 + -1;
          iVar1 = unaff_ESI[1];
          if (iVar2 == 0) {
            uVar3 = FUN_007c2ce0(iVar1);
          }
          else {
            uVar3 = (uint)**(byte **)(iVar1 + 4);
            *(byte **)(iVar1 + 4) = *(byte **)(iVar1 + 4) + 1;
          }
          if (uVar3 == 0xffffffff) {
            FUN_007be950(*unaff_ESI,s_unexpected_end_of_file_in__s_009fead0,unaff_ESI[4]);
          }
          *puVar4 = (char)uVar3;
          puVar4 = puVar4 + -1;
          local_c = local_c + -1;
        } while (local_c != 0);
      }
      local_8 = local_8 + param_1;
      local_4 = local_4 + -1;
    } while (local_4 != 0);
    return;
  }
  return;
}


// ==== FUN_007c7980 @ 0x007c7980 ====

undefined4 FUN_007c7980(void)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  FUN_007c7810();
  if (in_ECX == 0) {
    return 0;
  }
  uVar1 = FUN_007c2e40(*in_EAX,in_EAX[2],in_ECX);
  iVar2 = FUN_007c2da0(in_EAX[1],uVar1,in_ECX);
  if (iVar2 != 0) {
    FUN_007be950(*in_EAX,s_unexpected_end_of_file_in__s_009fead0,in_EAX[4]);
  }
  uVar1 = FUN_007c1d70(*in_EAX,uVar1,in_ECX + -1);
  return uVar1;
}


// ==== FUN_007c79f0 @ 0x007c79f0 ====

void FUN_007c79f0(void)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  int in_ECX;
  int unaff_EBX;
  
  FUN_007c7810();
  if (in_ECX < 0) {
    FUN_007be950(*in_EAX,s_bad_integer_in__s_009feaf0,in_EAX[4]);
  }
  uVar1 = FUN_007c3420(*in_EAX,0,0,in_ECX * 4);
  *(undefined4 *)(unaff_EBX + 0xc) = uVar1;
  *(int *)(unaff_EBX + 0x2c) = in_ECX;
  FUN_007c78a0(4);
  return;
}


// ==== FUN_007c7a50 @ 0x007c7a50 ====

void FUN_007c7a50(void)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  int unaff_EBX;
  int iVar2;
  int iVar3;
  int local_8;
  int local_4;
  
  FUN_007c7810();
  if (local_8 < 0) {
    FUN_007be950(*in_EAX,s_bad_integer_in__s_009feaf0,in_EAX[4]);
  }
  uVar1 = FUN_007c3420(*in_EAX,0,0,local_8 * 0xc);
  *(undefined4 *)(unaff_EBX + 0x18) = uVar1;
  *(int *)(unaff_EBX + 0x38) = local_8;
  if (0 < local_8) {
    iVar3 = 0;
    iVar2 = local_8;
    do {
      uVar1 = FUN_007c7980();
      *(undefined4 *)(iVar3 + *(int *)(unaff_EBX + 0x18)) = uVar1;
      FUN_007c7810();
      if (local_8 < 0) {
        FUN_007be950(*in_EAX,s_bad_integer_in__s_009feaf0,in_EAX[4]);
      }
      *(int *)(*(int *)(unaff_EBX + 0x18) + 4 + iVar3) = local_8;
      FUN_007c7810();
      if (local_4 < 0) {
        FUN_007be950(*in_EAX,s_bad_integer_in__s_009feaf0,in_EAX[4]);
      }
      *(int *)(*(int *)(unaff_EBX + 0x18) + 8 + iVar3) = local_4;
      iVar3 = iVar3 + 0xc;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


// ==== FUN_007c7b40 @ 0x007c7b40 ====

void FUN_007c7b40(void)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  int in_ECX;
  int unaff_EBX;
  
  FUN_007c7810();
  if (in_ECX < 0) {
    FUN_007be950(*in_EAX,s_bad_integer_in__s_009feaf0,in_EAX[4]);
  }
  uVar1 = FUN_007c3420(*in_EAX,0,0,in_ECX * 4);
  *(undefined4 *)(unaff_EBX + 0x14) = uVar1;
  *(int *)(unaff_EBX + 0x30) = in_ECX;
  FUN_007c78a0(4);
  return;
}


// ==== FUN_007c7ba0 @ 0x007c7ba0 ====

void FUN_007c7ba0(uint param_1)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  int iVar2;
  
  FUN_007c7810();
  if ((int)param_1 < 0) {
    FUN_007be950(*in_EAX,s_bad_integer_in__s_009feaf0,in_EAX[4]);
  }
  if ((param_1 != 0) && (param_1 != *(byte *)(param_1 + 0x44))) {
    FUN_007be950(*in_EAX,s_bad_nupvalues_in__s__read__d__ex_009feb04,in_EAX[4],param_1,
                 (uint)*(byte *)(param_1 + 0x44));
  }
  uVar1 = FUN_007c3420(*in_EAX,0,0,param_1 * 4);
  iVar2 = 0;
  *(undefined4 *)(param_1 + 0x1c) = uVar1;
  *(uint *)(param_1 + 0x24) = param_1;
  if (0 < (int)param_1) {
    do {
      uVar1 = FUN_007c7980();
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + iVar2 * 4) = uVar1;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)param_1);
  }
  return;
}


// ==== FUN_007c7c40 @ 0x007c7c40 ====

void FUN_007c7c40(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 *in_EAX;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_c;
  undefined8 local_8;
  
  iVar2 = param_1;
  FUN_007c7810();
  if (param_1 < 0) {
    FUN_007be950(*in_EAX,s_bad_integer_in__s_009feaf0,in_EAX[4]);
  }
  uVar3 = FUN_007c3420(*in_EAX,0,0,param_1 << 4);
  *(undefined4 *)(param_1 + 8) = uVar3;
  *(int *)(param_1 + 0x28) = param_1;
  if (0 < param_1) {
    param_1 = 0;
    local_c = iVar2;
    do {
      puVar5 = (undefined4 *)(*(int *)(iVar2 + 8) + param_1);
      iVar6 = *(int *)in_EAX[1];
      *(int *)in_EAX[1] = iVar6 + -1;
      iVar1 = in_EAX[1];
      if (iVar6 == 0) {
        uVar4 = FUN_007c2ce0(iVar1);
      }
      else {
        uVar4 = (uint)**(byte **)(iVar1 + 4);
        *(byte **)(iVar1 + 4) = *(byte **)(iVar1 + 4) + 1;
      }
      if (uVar4 == 0xffffffff) {
        FUN_007be950(*in_EAX,s_unexpected_end_of_file_in__s_009fead0,in_EAX[4]);
      }
      uVar4 = uVar4 & 0xff;
      if (uVar4 == 0) {
        *puVar5 = 0;
      }
      else if (uVar4 == 3) {
        *puVar5 = 3;
        FUN_007c7810();
        *(undefined8 *)(puVar5 + 2) = local_8;
      }
      else if (uVar4 == 4) {
        *puVar5 = 4;
        uVar3 = FUN_007c7980();
        puVar5[2] = uVar3;
      }
      else {
        FUN_007be950(*in_EAX,s_bad_constant_type___d__in__s_009feb30,uVar4,in_EAX[4]);
      }
      param_1 = param_1 + 0x10;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  FUN_007c7810();
  if (param_1 < 0) {
    FUN_007be950(*in_EAX,s_bad_integer_in__s_009feaf0,in_EAX[4]);
  }
  uVar3 = FUN_007c3420(*in_EAX,0,0,param_1 * 4);
  iVar6 = 0;
  *(undefined4 *)(iVar2 + 0x10) = uVar3;
  *(int *)(iVar2 + 0x34) = param_1;
  if (0 < param_1) {
    do {
      uVar3 = FUN_007c7df0();
      *(undefined4 *)(*(int *)(iVar2 + 0x10) + iVar6 * 4) = uVar3;
      iVar6 = iVar6 + 1;
    } while (iVar6 < param_1);
  }
  return;
}


// ==== FUN_007c7df0 @ 0x007c7df0 ====

int FUN_007c7df0(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = FUN_007c1f80(*param_1);
  iVar3 = FUN_007c7980();
  *(int *)(iVar2 + 0x20) = iVar3;
  if (iVar3 == 0) {
    *(undefined4 *)(iVar2 + 0x20) = param_2;
  }
  FUN_007c7810();
  if ((int)param_1 < 0) {
    FUN_007be950(*param_1,s_bad_integer_in__s_009feaf0,param_1[4]);
  }
  *(undefined4 **)(iVar2 + 0x3c) = param_1;
  iVar3 = *(int *)param_1[1];
  *(int *)param_1[1] = iVar3 + -1;
  iVar1 = param_1[1];
  if (iVar3 == 0) {
    uVar4 = FUN_007c2ce0(iVar1);
  }
  else {
    uVar4 = (uint)**(byte **)(iVar1 + 4);
    *(byte **)(iVar1 + 4) = *(byte **)(iVar1 + 4) + 1;
  }
  if (uVar4 == 0xffffffff) {
    FUN_007be950(*param_1,s_unexpected_end_of_file_in__s_009fead0,param_1[4]);
  }
  *(char *)(iVar2 + 0x44) = (char)uVar4;
  iVar3 = *(int *)param_1[1];
  *(int *)param_1[1] = iVar3 + -1;
  iVar1 = param_1[1];
  if (iVar3 == 0) {
    uVar4 = FUN_007c2ce0(iVar1);
  }
  else {
    uVar4 = (uint)**(byte **)(iVar1 + 4);
    *(byte **)(iVar1 + 4) = *(byte **)(iVar1 + 4) + 1;
  }
  if (uVar4 == 0xffffffff) {
    FUN_007be950(*param_1,s_unexpected_end_of_file_in__s_009fead0,param_1[4]);
  }
  *(char *)(iVar2 + 0x45) = (char)uVar4;
  iVar3 = *(int *)param_1[1];
  *(int *)param_1[1] = iVar3 + -1;
  iVar1 = param_1[1];
  if (iVar3 == 0) {
    uVar4 = FUN_007c2ce0(iVar1);
  }
  else {
    uVar4 = (uint)**(byte **)(iVar1 + 4);
    *(byte **)(iVar1 + 4) = *(byte **)(iVar1 + 4) + 1;
  }
  if (uVar4 == 0xffffffff) {
    FUN_007be950(*param_1,s_unexpected_end_of_file_in__s_009fead0,param_1[4]);
  }
  *(char *)(iVar2 + 0x46) = (char)uVar4;
  iVar3 = *(int *)param_1[1];
  *(int *)param_1[1] = iVar3 + -1;
  iVar1 = param_1[1];
  if (iVar3 == 0) {
    uVar4 = FUN_007c2ce0(iVar1);
  }
  else {
    uVar4 = (uint)**(byte **)(iVar1 + 4);
    *(byte **)(iVar1 + 4) = *(byte **)(iVar1 + 4) + 1;
  }
  if (uVar4 == 0xffffffff) {
    FUN_007be950(*param_1,s_unexpected_end_of_file_in__s_009fead0,param_1[4]);
  }
  *(char *)(iVar2 + 0x47) = (char)uVar4;
  FUN_007c7b40();
  FUN_007c7a50();
  FUN_007c7ba0(iVar2);
  FUN_007c7c40(iVar2);
  FUN_007c79f0();
  iVar3 = FUN_007be630(iVar2);
  if (iVar3 == 0) {
    FUN_007be950(*param_1,s_bad_code_in__s_009feb50,param_1[4]);
  }
  return iVar2;
}


// ==== FUN_007c7fb0 @ 0x007c7fb0 ====

void FUN_007c7fb0(void)

{
  char *pcVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *unaff_ESI;
  uint uVar5;
  
  pcVar4 = &DAT_009fe688;
  while( true ) {
    iVar2 = *(int *)unaff_ESI[1];
    *(int *)unaff_ESI[1] = iVar2 + -1;
    iVar3 = unaff_ESI[1];
    if (iVar2 == 0) {
      uVar5 = FUN_007c2ce0(iVar3);
    }
    else {
      uVar5 = (uint)**(byte **)(iVar3 + 4);
      *(byte **)(iVar3 + 4) = *(byte **)(iVar3 + 4) + 1;
    }
    if (uVar5 == 0xffffffff) {
      FUN_007be950(*unaff_ESI,s_unexpected_end_of_file_in__s_009fead0,unaff_ESI[4]);
    }
    if (uVar5 != (int)*pcVar4) break;
    pcVar1 = pcVar4 + 1;
    pcVar4 = pcVar4 + 1;
    if (*pcVar1 == '\0') {
      return;
    }
  }
  if (*pcVar4 != '\0') {
    FUN_007be950(*unaff_ESI,s_bad_signature_in__s_009feb60,unaff_ESI[4]);
  }
  return;
}


// ==== FUN_007c8030 @ 0x007c8030 ====

void FUN_007c8030(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *unaff_ESI;
  uint unaff_EDI;
  
  iVar1 = *(int *)unaff_ESI[1];
  *(int *)unaff_ESI[1] = iVar1 + -1;
  iVar2 = unaff_ESI[1];
  if (iVar1 == 0) {
    uVar3 = FUN_007c2ce0(iVar2);
  }
  else {
    uVar3 = (uint)**(byte **)(iVar2 + 4);
    *(byte **)(iVar2 + 4) = *(byte **)(iVar2 + 4) + 1;
  }
  if (uVar3 == 0xffffffff) {
    FUN_007be950(*unaff_ESI,s_unexpected_end_of_file_in__s_009fead0,unaff_ESI[4]);
  }
  if ((uVar3 & 0xff) != unaff_EDI) {
    FUN_007be950(*unaff_ESI,s_virtual_machine_mismatch_in__s__s_009feb74,unaff_ESI[4],param_1);
  }
  return;
}


// ==== FUN_007c80a0 @ 0x007c80a0 ====

/* WARNING: Removing unreachable block (ram,0x007c8103) */
/* WARNING: Removing unreachable block (ram,0x007c813b) */

void FUN_007c80a0(void)

{
  int iVar1;
  undefined4 *in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  FUN_007c7fb0();
  iVar2 = *(int *)in_EAX[1];
  *(int *)in_EAX[1] = iVar2 + -1;
  iVar1 = in_EAX[1];
  if (iVar2 == 0) {
    uVar3 = FUN_007c2ce0(iVar1);
  }
  else {
    uVar3 = (uint)**(byte **)(iVar1 + 4);
    *(byte **)(iVar1 + 4) = *(byte **)(iVar1 + 4) + 1;
  }
  if (uVar3 == 0xffffffff) {
    FUN_007be950(*in_EAX,s_unexpected_end_of_file_in__s_009fead0,in_EAX[4]);
  }
  uVar4 = uVar3 & 0xff;
  if (0x50 < uVar4) {
    FUN_007be950(*in_EAX,s__s_too_new__read_version__d__d__e_009fec2c,in_EAX[4],(int)uVar4 >> 4,
                 uVar3 & 0xf,5,0);
  }
  if (uVar4 < 0x50) {
    FUN_007be950(*in_EAX,s__s_too_old__read_version__d__d__e_009febf4,in_EAX[4],(int)uVar4 >> 4,
                 uVar3 & 0xf,5,0);
  }
  iVar2 = *(int *)in_EAX[1];
  *(int *)in_EAX[1] = iVar2 + -1;
  iVar1 = in_EAX[1];
  if (iVar2 == 0) {
    uVar3 = FUN_007c2ce0(iVar1);
  }
  else {
    uVar3 = (uint)**(byte **)(iVar1 + 4);
    *(byte **)(iVar1 + 4) = *(byte **)(iVar1 + 4) + 1;
  }
  if (uVar3 == 0xffffffff) {
    FUN_007be950(*in_EAX,s_unexpected_end_of_file_in__s_009fead0,in_EAX[4]);
  }
  in_EAX[3] = (uint)((char)uVar3 != '\x01');
  FUN_007c8030(&DAT_009febf0);
  FUN_007c8030(s_size_t_009febe8);
  FUN_007c8030(s_Instruction_009febdc);
  FUN_007c8030(&DAT_009febd8);
  FUN_007c8030(&DAT_009febd4);
  FUN_007c8030(&DAT_009febd0);
  FUN_007c8030(&DAT_009fe224);
  FUN_007c8030(s_number_009fe414);
  FUN_007c7810();
  iVar2 = FUN_00802534();
  if (iVar2 != 0x1df5e76) {
    FUN_007be950(*in_EAX,s_unknown_number_format_in__s_009febb4,in_EAX[4]);
  }
  return;
}


// ==== FUN_007c8250 @ 0x007c8250 ====

void FUN_007c8250(undefined4 param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  char *local_4;
  
  local_4 = *(char **)(param_2 + 0x10);
  cVar1 = *local_4;
  if ((cVar1 == '@') || (cVar1 == '=')) {
    local_4 = local_4 + 1;
  }
  else if (cVar1 == '\x1b') {
    local_4 = s_binary_string_009fec64;
  }
  local_14 = param_1;
  local_10 = param_2;
  local_c = param_3;
  FUN_007c80a0();
  FUN_007c7df0(&local_14,0);
  return;
}


// ==== FUN_007c82b0 @ 0x007c82b0 ====

void FUN_007c82b0(void)

{
  uint *puVar1;
  int in_EAX;
  uint uVar2;
  int in_ECX;
  uint uVar3;
  int *unaff_EBX;
  
  uVar2 = (in_EAX - in_ECX) - 1;
  puVar1 = (uint *)(*(int *)(*unaff_EBX + 0xc) + in_ECX * 4);
  uVar3 = (int)uVar2 >> 0x1f;
  if (0x1ffff < (int)((uVar2 ^ uVar3) - uVar3)) {
    FUN_007c3a40(unaff_EBX[3],s_control_structure_too_long_009fecb0);
  }
  uVar2 = *puVar1;
  *puVar1 = uVar2 ^ (((in_EAX - in_ECX) + 0x1fffe) * 0x40 ^ uVar2) & 0xffffc0;
  return;
}


// ==== FUN_007c8300 @ 0x007c8300 ====

void FUN_007c8300(int param_1)

{
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x18);
  return;
}


// ==== FUN_007c8310 @ 0x007c8310 ====

undefined4 FUN_007c8310(uint param_1)

{
  uint *puVar1;
  int *in_EAX;
  uint *puVar2;
  int iVar3;
  int in_ECX;
  
  if (in_ECX != -1) {
    do {
      puVar1 = (uint *)(*(int *)(*in_EAX + 0xc) + in_ECX * 4);
      if ((in_ECX < 1) ||
         (puVar2 = puVar1 + -1, (s__a___a4A_009fec74[puVar1[-1] & 0x3f] & 0x80U) == 0)) {
        puVar2 = puVar1;
      }
      if ((((byte)*puVar2 & 0x3f) != 0x18) || ((*puVar2 >> 6 & 0x1ff) != param_1)) {
        return 1;
      }
      iVar3 = (*puVar1 >> 6 & 0x3ffff) - 0x1ffff;
    } while ((iVar3 != -1) && (in_ECX = in_ECX + 1 + iVar3, in_ECX != -1));
  }
  return 0;
}


// ==== FUN_007c8390 @ 0x007c8390 ====

void FUN_007c8390(int param_1,uint param_2,int param_3,uint param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  int in_EDX;
  int *unaff_EBX;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int local_4;
  
  do {
    if (in_EDX == -1) {
      return;
    }
    iVar6 = in_EDX * 4;
    puVar5 = (uint *)(*(int *)(*unaff_EBX + 0xc) + iVar6);
    uVar1 = *(uint *)(*(int *)(*unaff_EBX + 0xc) + iVar6) >> 6 & 0x3ffff;
    if (uVar1 == 0x1fffe) {
      local_4 = -1;
    }
    else {
      local_4 = (uVar1 - 0x1fffe) + in_EDX;
    }
    if ((in_EDX < 1) || (puVar3 = puVar5 + -1, -1 < s__a___a4A_009fec74[puVar5[-1] & 0x3f])) {
      puVar3 = puVar5;
    }
    uVar1 = *puVar3;
    if (((byte)uVar1 & 0x3f) == 0x18) {
      if ((uVar1 & 0x7fc0) == 0) {
        uVar2 = param_4;
        if (param_4 == 0xff) {
          uVar2 = uVar1 >> 0xf & 0x1ff;
        }
        *puVar3 = uVar1 & 0xffffff | uVar2 << 0x18;
        iVar4 = param_3;
      }
      else {
        uVar2 = param_2;
        if (param_2 == 0xff) {
          uVar2 = uVar1 >> 0xf & 0x1ff;
        }
        *puVar3 = uVar1 & 0xffffff | uVar2 << 0x18;
        iVar4 = param_1;
      }
      puVar5 = (uint *)(*(int *)(*unaff_EBX + 0xc) + iVar6);
      uVar1 = (iVar4 - in_EDX) - 1;
      if (0x1ffff < (int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f))) {
        iVar6 = unaff_EBX[3];
        goto LAB_007c8494;
      }
    }
    else {
      uVar1 = (param_5 - in_EDX) - 1;
      if (0x1ffff < (int)((uVar1 ^ (int)uVar1 >> 0x1f) - ((int)uVar1 >> 0x1f))) {
        iVar6 = unaff_EBX[3];
LAB_007c8494:
        FUN_007c3a40(iVar6,s_control_structure_too_long_009fecb0);
      }
    }
    *puVar5 = *puVar5 ^ ((uVar1 + 0x1ffff) * 0x40 ^ *puVar5) & 0xffffc0;
    in_EDX = local_4;
  } while( true );
}


// ==== FUN_007c84d0 @ 0x007c84d0 ====

void FUN_007c84d0(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (param_3 != -1) {
    iVar1 = *param_2;
    if (iVar1 == -1) {
      *param_2 = param_3;
      return;
    }
    do {
      uVar2 = *(uint *)(*(int *)(*param_1 + 0xc) + iVar1 * 4) >> 6 & 0x3ffff;
      if (uVar2 == 0x1fffe) break;
      iVar1 = (uVar2 - 0x1fffe) + iVar1;
    } while (iVar1 != -1);
    FUN_007c82b0();
  }
  return;
}


// ==== FUN_007c8520 @ 0x007c8520 ====

void FUN_007c8520(int *param_1,int param_2)

{
  param_2 = param_1[9] + param_2;
  if ((int)(uint)*(byte *)(*param_1 + 0x47) < param_2) {
    if (0xf9 < param_2) {
      FUN_007c3a40(param_1[3],s_function_or_expression_too_compl_009feccc);
    }
    *(char *)(*param_1 + 0x47) = (char)param_2;
  }
  return;
}


// ==== FUN_007c8560 @ 0x007c8560 ====

void FUN_007c8560(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = param_1[9] + param_2;
  if ((int)(uint)*(byte *)(*param_1 + 0x47) < iVar1) {
    if (0xf9 < iVar1) {
      FUN_007c3a40(param_1[3],s_function_or_expression_too_compl_009feccc);
    }
    *(char *)(*param_1 + 0x47) = (char)iVar1;
  }
  param_1[9] = param_1[9] + param_2;
  return;
}


// ==== FUN_007c85b0 @ 0x007c85b0 ====

void FUN_007c85b0(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int *unaff_ESI;
  undefined4 *unaff_EDI;
  
  piVar2 = (int *)FUN_007c26b0(unaff_ESI[1],param_1);
  if (*piVar2 == 3) {
    FUN_00802534();
    return;
  }
  iVar1 = *unaff_ESI;
  if (*(int *)(iVar1 + 0x28) < unaff_ESI[10] + 1) {
    uVar3 = FUN_007c34b0(unaff_ESI[4],*(undefined4 *)(iVar1 + 8),iVar1 + 0x28,0x10,0x3ffff,
                         s_constant_table_overflow_009fe960);
    *(undefined4 *)(iVar1 + 8) = uVar3;
  }
  puVar4 = (undefined4 *)(unaff_ESI[10] * 0x10 + *(int *)(iVar1 + 8));
  *puVar4 = *unaff_EDI;
  puVar4[2] = unaff_EDI[2];
  puVar4[3] = unaff_EDI[3];
  puVar4 = (undefined4 *)FUN_007c2710(unaff_ESI[4],unaff_ESI[1],param_1);
  *puVar4 = 3;
  *(double *)(puVar4 + 2) = (double)unaff_ESI[10];
  unaff_ESI[10] = unaff_ESI[10] + 1;
  return;
}


// ==== FUN_007c8650 @ 0x007c8650 ====

void FUN_007c8650(undefined4 param_1,undefined4 param_2)

{
  undefined4 local_10 [2];
  undefined4 local_8;
  
  local_10[0] = 4;
  local_8 = param_2;
  FUN_007c85b0(local_10);
  return;
}


// ==== FUN_007c8680 @ 0x007c8680 ====

void FUN_007c8680(undefined4 param_1,undefined8 param_2)

{
  undefined4 local_10 [2];
  undefined8 local_8;
  
  local_8 = param_2;
  local_10[0] = 3;
  FUN_007c85b0(local_10);
  return;
}


// ==== FUN_007c86b0 @ 0x007c86b0 ====

void FUN_007c86b0(void)

{
  int in_EAX;
  undefined4 local_20 [2];
  undefined4 local_18;
  undefined4 local_10;
  
  local_18 = *(undefined4 *)(in_EAX + 4);
  local_10 = 0;
  local_20[0] = 5;
  FUN_007c85b0(local_20);
  return;
}


// ==== FUN_007c86f0 @ 0x007c86f0 ====

void FUN_007c86f0(int *param_1,int *param_2,int param_3)

{
  uint uVar1;
  
  if ((*param_2 == 0xc) &&
     (uVar1 = *(uint *)(*(int *)(*param_1 + 0xc) + param_2[1] * 4),
     *(uint *)(*(int *)(*param_1 + 0xc) + param_2[1] * 4) =
          uVar1 ^ ((param_3 + 1) * 0x40 ^ uVar1) & 0x7fc0, param_3 == 1)) {
    *param_2 = 0xb;
    param_2[1] = (uint)*(byte *)(*(int *)(*param_1 + 0xc) + 3 + param_2[1] * 4);
  }
  return;
}


// ==== FUN_007c8750 @ 0x007c8750 ====

void FUN_007c8750(void)

{
  int in_EAX;
  int *in_ECX;
  uint *puVar1;
  
  puVar1 = (uint *)(*(int *)(*in_ECX + 0xc) + *(int *)(in_EAX + 4) * 4);
  if (0 < *(int *)(in_EAX + 4)) {
    if (s__a___a4A_009fec74[puVar1[-1] & 0x3f] < '\0') {
      puVar1 = puVar1 + -1;
    }
  }
  *puVar1 = (uint)((*puVar1 & 0xff000000) == 0) * 0x1000000 | *puVar1 & 0xffffff;
  return;
}


// ==== FUN_007c87a0 @ 0x007c87a0 ====

void FUN_007c87a0(int *param_1,undefined4 param_2)

{
  *(undefined4 *)(*(int *)(*param_1 + 0x14) + -4 + param_1[6] * 4) = param_2;
  return;
}


// ==== FUN_007c87c0 @ 0x007c87c0 ====

void FUN_007c87c0(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = param_1[6];
  iVar2 = *param_1;
  FUN_007c8390(iVar1,0xff,iVar1,0xff,iVar1);
  param_1[8] = -1;
  if (*(int *)(iVar2 + 0x2c) < param_1[6] + 1) {
    uVar3 = FUN_007c34b0(param_1[4],*(undefined4 *)(iVar2 + 0xc),(int *)(iVar2 + 0x2c),4,0x7ffffffd,
                         s_code_size_overflow_009fecf0);
    *(undefined4 *)(iVar2 + 0xc) = uVar3;
  }
  *(undefined4 *)(*(int *)(iVar2 + 0xc) + param_1[6] * 4) = param_2;
  if (*(int *)(iVar2 + 0x30) < param_1[6] + 1) {
    uVar3 = FUN_007c34b0(param_1[4],*(undefined4 *)(iVar2 + 0x14),iVar2 + 0x30,4,0x7ffffffd,
                         s_code_size_overflow_009fecf0);
    *(undefined4 *)(iVar2 + 0x14) = uVar3;
  }
  *(undefined4 *)(*(int *)(iVar2 + 0x14) + param_1[6] * 4) = param_3;
  param_1[6] = param_1[6] + 1;
  return;
}


// ==== FUN_007c8870 @ 0x007c8870 ====

void FUN_007c8870(int param_1,uint param_2,int param_3,uint param_4,uint param_5)

{
  FUN_007c87c0(param_1,((param_3 << 9 | param_4) << 9 | param_5) << 6 | param_2,
               *(undefined4 *)(*(int *)(param_1 + 0xc) + 8));
  return;
}


// ==== FUN_007c88b0 @ 0x007c88b0 ====

void FUN_007c88b0(int param_1,uint param_2,int param_3,uint param_4)

{
  FUN_007c87c0(param_1,(param_3 << 0x12 | param_4) << 6 | param_2,
               *(undefined4 *)(*(int *)(param_1 + 0xc) + 8));
  return;
}


// ==== FUN_007c88e0 @ 0x007c88e0 ====

void FUN_007c88e0(int *param_1,int param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_1[7] < param_1[6]) {
    puVar1 = (uint *)(*(int *)(*param_1 + 0xc) + -4 + param_1[6] * 4);
    uVar2 = *puVar1;
    if (((((byte)uVar2 & 0x3f) == 3) &&
        (uVar3 = uVar2 >> 0xf & 0x1ff, (int)(uVar2 >> 0x18) <= param_2)) &&
       (param_2 <= (int)(uVar3 + 1))) {
      if ((int)uVar3 < param_2 + -1 + param_3) {
        *puVar1 = ((param_2 + -1 + param_3) * 0x8000 ^ uVar2) & 0xff8000 ^ uVar2;
        return;
      }
      return;
    }
  }
  FUN_007c87c0(param_1,(param_2 + -1 + param_3 | param_2 << 9) << 0xf | 3,
               *(undefined4 *)(param_1[3] + 8));
  return;
}


// ==== FUN_007c8970 @ 0x007c8970 ====

undefined4 FUN_007c8970(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1;
  uVar1 = *(undefined4 *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x20) = 0xffffffff;
  param_1 = FUN_007c87c0(param_1,0x7fff94,*(undefined4 *)(*(int *)(param_1 + 0xc) + 8));
  FUN_007c84d0(iVar2,&param_1,uVar1);
  return param_1;
}


// ==== FUN_007c89b0 @ 0x007c89b0 ====

undefined4 FUN_007c89b0(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  FUN_007c87c0();
  *(undefined4 *)(unaff_ESI + 0x20) = 0xffffffff;
  uVar1 = FUN_007c87c0();
  FUN_007c84d0();
  return uVar1;
}


// ==== FUN_007c8a10 @ 0x007c8a10 ====

void FUN_007c8a10(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x18);
  FUN_007c84d0(param_1,param_1 + 0x20,param_2);
  return;
}


// ==== FUN_007c8a30 @ 0x007c8a30 ====

void FUN_007c8a30(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  switch(*param_2) {
  case 5:
    *param_2 = 0xb;
    return;
  case 6:
    uVar3 = param_2[1];
    uVar1 = 0;
    uVar2 = 4;
    break;
  case 7:
    uVar1 = FUN_007c88b0(param_1,5,0,param_2[1]);
    param_2[1] = uVar1;
    *param_2 = 10;
    return;
  case 8:
    if ((*(int *)(param_1 + 0x34) <= (int)param_2[2]) && ((int)param_2[2] < 0xfa)) {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
    }
    if ((*(int *)(param_1 + 0x34) <= (int)param_2[1]) && ((int)param_2[1] < 0xfa)) {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
    }
    uVar1 = param_2[2];
    uVar3 = param_2[1];
    uVar2 = 6;
    break;
  default:
    return;
  case 0xc:
    FUN_007c86f0(param_1,param_2,1);
    return;
  }
  uVar1 = FUN_007c8870(param_1,uVar2,0,uVar3,uVar1);
  param_2[1] = uVar1;
  *param_2 = 10;
  return;
}


// ==== FUN_007c8b00 @ 0x007c8b00 ====

void FUN_007c8b00(void)

{
  uint *puVar1;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  int *unaff_EDI;
  
  FUN_007c8a30();
  switch(*unaff_EBX) {
  case 1:
    FUN_007c88e0();
    unaff_EBX[1] = unaff_ESI;
    *unaff_EBX = 0xb;
    return;
  case 2:
  case 3:
    FUN_007c8870();
    unaff_EBX[1] = unaff_ESI;
    *unaff_EBX = 0xb;
    return;
  case 4:
    FUN_007c88b0();
    unaff_EBX[1] = unaff_ESI;
    *unaff_EBX = 0xb;
    return;
  case 10:
    puVar1 = (uint *)(*(int *)(*unaff_EDI + 0xc) + unaff_EBX[1] * 4);
    *puVar1 = *puVar1 & 0xffffff | unaff_ESI << 0x18;
    unaff_EBX[1] = unaff_ESI;
    *unaff_EBX = 0xb;
    return;
  case 0xb:
    if (unaff_ESI != unaff_EBX[1]) {
      FUN_007c8870();
    }
    unaff_EBX[1] = unaff_ESI;
    *unaff_EBX = 0xb;
  }
  return;
}


// ==== FUN_007c8bf0 @ 0x007c8bf0 ====

void FUN_007c8bf0(int *param_1)

{
  int *in_EAX;
  int iVar1;
  
  if (*param_1 != 0xb) {
    iVar1 = in_EAX[9] + 1;
    if ((int)(uint)*(byte *)(*in_EAX + 0x47) < iVar1) {
      if (0xf9 < iVar1) {
        FUN_007c3a40(in_EAX[3],s_function_or_expression_too_compl_009feccc);
      }
      *(char *)(*in_EAX + 0x47) = (char)iVar1;
    }
    in_EAX[9] = in_EAX[9] + 1;
    FUN_007c8b00();
  }
  return;
}


// ==== FUN_007c8c50 @ 0x007c8c50 ====

void FUN_007c8c50(int *param_1,int param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  undefined4 uVar4;
  
  piVar2 = param_1;
  FUN_007c8b00();
  if (*param_1 == 9) {
    FUN_007c84d0();
  }
  if (param_1[3] == param_1[4]) goto LAB_007c8d5c;
  uVar4 = 0xffffffff;
  param_1 = (int *)0xffffffff;
  iVar3 = FUN_007c8310(1);
  if (iVar3 == 0) {
    iVar3 = FUN_007c8310(0);
    if (iVar3 != 0) goto LAB_007c8cb3;
  }
  else {
LAB_007c8cb3:
    if (*piVar2 != 9) {
      FUN_007c8970();
    }
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x18);
    uVar4 = FUN_007c87c0();
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x18);
    param_1 = (int *)FUN_007c87c0();
    *(undefined4 *)(in_EAX + 0x1c) = *(undefined4 *)(in_EAX + 0x18);
    FUN_007c84d0();
  }
  uVar1 = *(undefined4 *)(in_EAX + 0x18);
  *(undefined4 *)(in_EAX + 0x1c) = uVar1;
  FUN_007c8390(uVar4,0xff,uVar1,param_2,uVar4);
  FUN_007c8390(uVar1,param_2,param_1,0xff,param_1);
LAB_007c8d5c:
  piVar2[3] = -1;
  piVar2[4] = -1;
  piVar2[1] = param_2;
  *piVar2 = 0xb;
  return;
}


// ==== FUN_007c8d80 @ 0x007c8d80 ====

void FUN_007c8d80(int *param_1,int *param_2)

{
  int iVar1;
  
  FUN_007c8a30(param_1,param_2);
  if (((*param_2 == 0xb) && (param_1[0xd] <= param_2[1])) && (param_2[1] < 0xfa)) {
    param_1[9] = param_1[9] + -1;
  }
  iVar1 = param_1[9] + 1;
  if ((int)(uint)*(byte *)(*param_1 + 0x47) < iVar1) {
    if (0xf9 < iVar1) {
      FUN_007c3a40(param_1[3],s_function_or_expression_too_compl_009feccc);
    }
    *(char *)(*param_1 + 0x47) = (char)iVar1;
  }
  iVar1 = param_1[9];
  param_1[9] = iVar1 + 1;
  FUN_007c8c50(param_2,iVar1);
  return;
}


// ==== FUN_007c8e00 @ 0x007c8e00 ====

int FUN_007c8e00(int param_1,int *param_2)

{
  int iVar1;
  
  FUN_007c8a30(param_1,param_2);
  if (*param_2 == 0xb) {
    iVar1 = param_2[1];
    if (param_2[3] == param_2[4]) {
      return iVar1;
    }
    if (*(int *)(param_1 + 0x34) <= iVar1) {
      FUN_007c8c50(param_2,iVar1);
      return param_2[1];
    }
  }
  FUN_007c8d80(param_1,param_2);
  return param_2[1];
}


// ==== FUN_007c8e50 @ 0x007c8e50 ====

void FUN_007c8e50(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0xc) == *(int *)(param_2 + 0x10)) {
    FUN_007c8a30();
    return;
  }
  FUN_007c8e00();
  return;
}


// ==== FUN_007c8e70 @ 0x007c8e70 ====

int FUN_007c8e70(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_2[3] == param_2[4]) {
    FUN_007c8a30(param_1,param_2);
  }
  else {
    FUN_007c8e00();
  }
  if (*param_2 == 1) {
    if (*(int *)(param_1 + 0x28) + 0xfa < 0x200) {
      iVar1 = FUN_007c86b0();
      param_2[1] = iVar1;
      *param_2 = 4;
      return iVar1 + 0xfa;
    }
  }
  else if ((*param_2 == 4) && (param_2[1] + 0xfa < 0x200)) {
    return param_2[1] + 0xfa;
  }
  iVar1 = FUN_007c8e00(param_1,param_2);
  return iVar1;
}


// ==== FUN_007c8ef0 @ 0x007c8ef0 ====

void FUN_007c8ef0(int param_1,undefined4 *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  switch(*param_2) {
  case 5:
    if (((*param_3 == 0xb) && (*(int *)(param_1 + 0x34) <= param_3[1])) && (param_3[1] < 0xfa)) {
      *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
    }
    FUN_007c8c50(param_3,param_2[1]);
    return;
  case 6:
    uVar1 = FUN_007c8e00(param_1,param_3);
    uVar5 = param_2[1];
    uVar3 = 0;
    uVar4 = 8;
    break;
  case 7:
    iVar2 = FUN_007c8e00(param_1,param_3);
    FUN_007c87c0(param_1,(iVar2 << 0x12 | param_2[1]) << 6 | 7,
                 *(undefined4 *)(*(int *)(param_1 + 0xc) + 8));
    goto switchD_007c8f0d_default;
  case 8:
    uVar3 = FUN_007c8e70(param_1,param_3);
    uVar1 = param_2[1];
    uVar5 = param_2[2];
    uVar4 = 9;
    break;
  default:
    goto switchD_007c8f0d_default;
  }
  FUN_007c8870(param_1,uVar4,uVar1,uVar5,uVar3);
switchD_007c8f0d_default:
  if (((*param_3 == 0xb) && (*(int *)(param_1 + 0x34) <= param_3[1])) && (param_3[1] < 0xfa)) {
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
  }
  return;
}


// ==== FUN_007c8fd0 @ 0x007c8fd0 ====

void FUN_007c8fd0(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  FUN_007c8a30(param_1,param_2);
  if (*param_2 == 0xb) {
    if (param_2[3] == param_2[4]) goto LAB_007c9012;
    if (param_1[0xd] <= param_2[1]) {
      FUN_007c8c50(param_2,param_2[1]);
      goto LAB_007c9012;
    }
  }
  FUN_007c8d80(param_1,param_2);
LAB_007c9012:
  if (((*param_2 == 0xb) && (param_1[0xd] <= param_2[1])) && (param_2[1] < 0xfa)) {
    param_1[9] = param_1[9] + -1;
  }
  iVar2 = param_1[9];
  iVar1 = iVar2 + 2;
  if ((int)(uint)*(byte *)(*param_1 + 0x47) < iVar1) {
    if (0xf9 < iVar1) {
      FUN_007c3a40(param_1[3],s_function_or_expression_too_compl_009feccc);
    }
    *(char *)(*param_1 + 0x47) = (char)iVar1;
  }
  param_1[9] = param_1[9] + 2;
  uVar3 = FUN_007c8e70(param_1,param_3);
  FUN_007c87c0(param_1,((iVar2 << 9 | param_2[1]) << 9 | uVar3) << 6 | 0xb,
               *(undefined4 *)(param_1[3] + 8));
  if (((*param_3 == 0xb) && (param_1[0xd] <= param_3[1])) && (param_3[1] < 0xfa)) {
    param_1[9] = param_1[9] + -1;
  }
  param_2[1] = iVar2;
  *param_2 = 0xb;
  return;
}


// ==== FUN_007c90c0 @ 0x007c90c0 ====

void FUN_007c90c0(void)

{
  uint uVar1;
  int *in_EAX;
  int unaff_EBX;
  int *unaff_EDI;
  
  if ((*unaff_EDI == 10) &&
     (uVar1 = *(uint *)(*(int *)(*in_EAX + 0xc) + unaff_EDI[1] * 4), ((byte)uVar1 & 0x3f) == 0x12))
  {
    in_EAX[6] = in_EAX[6] + -1;
    FUN_007c89b0(0x18,uVar1 >> 0xf & 0x1ff,unaff_EBX == 0);
    return;
  }
  FUN_007c8bf0();
  if ((*unaff_EDI == 0xb) && ((in_EAX[0xd] <= unaff_EDI[1] && (unaff_EDI[1] < 0xfa)))) {
    in_EAX[9] = in_EAX[9] + -1;
  }
  FUN_007c89b0(0x18,unaff_EDI[1]);
  return;
}


// ==== FUN_007c9140 @ 0x007c9140 ====

void FUN_007c9140(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  FUN_007c8a30(param_1,param_2);
  switch(*param_2) {
  case 2:
  case 4:
    FUN_007c84d0(param_1,param_2 + 4,0xffffffff);
    return;
  case 3:
    uVar1 = FUN_007c8970(param_1);
    FUN_007c84d0(param_1,param_2 + 4,uVar1);
    return;
  default:
    uVar1 = FUN_007c90c0();
    FUN_007c84d0(param_1,param_2 + 4,uVar1);
    return;
  case 9:
    FUN_007c8750();
    FUN_007c84d0(param_1,param_2 + 4,param_2[1]);
    return;
  }
}


// ==== FUN_007c91f0 @ 0x007c91f0 ====

void FUN_007c91f0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  FUN_007c8a30(param_1,param_2);
  switch(*param_2) {
  case 1:
  case 3:
    FUN_007c84d0(param_1,param_2 + 3,0xffffffff);
    return;
  case 2:
    uVar1 = FUN_007c8970(param_1);
    FUN_007c84d0(param_1,param_2 + 3,uVar1);
    return;
  default:
    uVar1 = FUN_007c90c0();
    FUN_007c84d0(param_1,param_2 + 3,uVar1);
    return;
  case 9:
    FUN_007c84d0(param_1,param_2 + 3,param_2[1]);
    return;
  }
}


// ==== FUN_007c92a0 @ 0x007c92a0 ====

void FUN_007c92a0(void)

{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;
  
  FUN_007c8a30();
  switch(*unaff_ESI) {
  case 1:
  case 3:
    iVar1 = unaff_ESI[4];
    *unaff_ESI = 2;
    unaff_ESI[4] = unaff_ESI[3];
    unaff_ESI[3] = iVar1;
    return;
  case 2:
  case 4:
    iVar1 = unaff_ESI[4];
    *unaff_ESI = 3;
    unaff_ESI[4] = unaff_ESI[3];
    unaff_ESI[3] = iVar1;
    return;
  case 9:
    FUN_007c8750();
    iVar1 = unaff_ESI[4];
    unaff_ESI[4] = unaff_ESI[3];
    unaff_ESI[3] = iVar1;
    return;
  case 10:
  case 0xb:
    FUN_007c8bf0();
    if (((*unaff_ESI == 0xb) && (*(int *)(unaff_EDI + 0x34) <= unaff_ESI[1])) &&
       (unaff_ESI[1] < 0xfa)) {
      *(int *)(unaff_EDI + 0x24) = *(int *)(unaff_EDI + 0x24) + -1;
    }
    iVar1 = FUN_007c8870();
    unaff_ESI[1] = iVar1;
    *unaff_ESI = 10;
  }
  iVar1 = unaff_ESI[4];
  unaff_ESI[4] = unaff_ESI[3];
  unaff_ESI[3] = iVar1;
  return;
}


// ==== FUN_007c9370 @ 0x007c9370 ====

void FUN_007c9370(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_007c8e70(param_1,param_3);
  param_2[2] = uVar1;
  *param_2 = 8;
  return;
}


// ==== FUN_007c9390 @ 0x007c9390 ====

void FUN_007c9390(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 != 0) {
    FUN_007c92a0();
    return;
  }
  if (param_3[3] == param_3[4]) {
    FUN_007c8a30(param_1,param_3);
  }
  else {
    FUN_007c8e00();
  }
  if ((*param_3 == 4) &&
     (piVar1 = (int *)(*(int *)(*param_1 + 8) + param_3[1] * 0x10), *piVar1 == 3)) {
    iVar2 = FUN_007c8680(param_1,-*(double *)(piVar1 + 2));
    param_3[1] = iVar2;
    return;
  }
  FUN_007c8e00(param_1,param_3);
  if ((*param_3 == 0xb) && ((param_1[0xd] <= param_3[1] && (param_3[1] < 0xfa)))) {
    param_1[9] = param_1[9] + -1;
  }
  iVar2 = FUN_007c87c0(param_1,param_3[1] << 0xf | 0x11,*(undefined4 *)(param_1[3] + 8));
  param_3[1] = iVar2;
  *param_3 = 10;
  return;
}


// ==== FUN_007c9450 @ 0x007c9450 ====

void FUN_007c9450(int param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  
  if (param_2 == 5) {
    FUN_007c8d80(param_1,param_3);
    return;
  }
  if (param_2 == 0xc) {
    FUN_007c9140(param_1,param_3);
    uVar1 = *(undefined4 *)(param_3 + 0xc);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x18);
    FUN_007c84d0(param_1,param_1 + 0x20,uVar1);
    *(undefined4 *)(param_3 + 0xc) = 0xffffffff;
    return;
  }
  if (param_2 == 0xd) {
    FUN_007c91f0(param_1,param_3);
    uVar1 = *(undefined4 *)(param_3 + 0x10);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x18);
    FUN_007c84d0(param_1,param_1 + 0x20,uVar1);
    *(undefined4 *)(param_3 + 0x10) = 0xffffffff;
    return;
  }
  FUN_007c8e70(param_1,param_3);
  return;
}


// ==== FUN_007c94f0 @ 0x007c94f0 ====

void FUN_007c94f0(int param_1)

{
  uint in_EAX;
  undefined4 uVar1;
  uint in_ECX;
  uint uVar2;
  int in_EDX;
  undefined4 *unaff_EDI;
  
  if (in_EDX < 5) {
    uVar1 = FUN_007c87c0(param_1,(in_ECX << 9 | in_EAX) << 6 | in_EDX + 0xcU,
                         *(undefined4 *)(*(int *)(param_1 + 0xc) + 8));
    *unaff_EDI = 10;
    unaff_EDI[1] = uVar1;
    return;
  }
  uVar2 = in_ECX;
  if (9 < in_EDX) {
    uVar2 = in_EAX;
    in_EAX = in_ECX;
  }
  uVar1 = FUN_007c89b0(*(undefined4 *)(&DAT_009fec80 + in_EDX * 4),uVar2,in_EAX);
  *unaff_EDI = 9;
  unaff_EDI[1] = uVar1;
  return;
}


// ==== FUN_007c9560 @ 0x007c9560 ====

void FUN_007c9560(int *param_1,int param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  
  if (param_2 == 5) {
    if (param_4[3] == param_4[4]) {
      FUN_007c8a30(param_1,param_4);
    }
    else {
      FUN_007c8e00();
    }
    if ((*param_4 == 10) &&
       (((byte)*(undefined4 *)(*(int *)(*param_1 + 0xc) + param_4[1] * 4) & 0x3f) == 0x13)) {
      if (((*param_3 == 0xb) && (param_1[0xd] <= param_3[1])) && (param_3[1] < 0xfa)) {
        param_1[9] = param_1[9] + -1;
      }
      iVar2 = *(int *)(*param_1 + 0xc);
      uVar1 = *(uint *)(iVar2 + param_4[1] * 4);
      *(uint *)(iVar2 + param_4[1] * 4) = uVar1 ^ (param_3[1] << 0xf ^ uVar1) & 0xff8000;
      *param_3 = *param_4;
      param_3[1] = param_4[1];
      return;
    }
    FUN_007c8d80(param_1,param_4);
    if ((*param_4 == 0xb) && ((param_1[0xd] <= param_4[1] && (param_4[1] < 0xfa)))) {
      param_1[9] = param_1[9] + -1;
    }
    if (((*param_3 == 0xb) && (param_1[0xd] <= param_3[1])) && (param_3[1] < 0xfa)) {
      param_1[9] = param_1[9] + -1;
    }
    iVar2 = FUN_007c87c0(param_1,(param_3[1] << 9 | param_4[1]) << 6 | 0x13,
                         *(undefined4 *)(param_1[3] + 8));
    param_3[1] = iVar2;
    *param_3 = 10;
    return;
  }
  if (param_2 == 0xc) {
    FUN_007c8a30(param_1,param_4);
    FUN_007c84d0(param_1,param_3 + 4,param_4[4]);
    *param_3 = *param_4;
    param_3[1] = param_4[1];
    param_3[2] = param_4[2];
    param_3[3] = param_4[3];
    return;
  }
  if (param_2 == 0xd) {
    FUN_007c8a30(param_1,param_4);
    FUN_007c84d0(param_1,param_3 + 3,param_4[3]);
    *param_3 = *param_4;
    param_3[1] = param_4[1];
    param_3[2] = param_4[2];
    param_3[4] = param_4[4];
    return;
  }
  FUN_007c8e70(param_1,param_3);
  FUN_007c8e70(param_1,param_4);
  if (((*param_4 == 0xb) && (param_1[0xd] <= param_4[1])) && (param_4[1] < 0xfa)) {
    param_1[9] = param_1[9] + -1;
  }
  if (((*param_3 == 0xb) && (param_1[0xd] <= param_3[1])) && (param_3[1] < 0xfa)) {
    param_1[9] = param_1[9] + -1;
  }
  FUN_007c94f0(param_1);
  return;
}


// ==== FUN_007c9760 @ 0x007c9760 ====

void FUN_007c9760(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 == *(int *)(param_1 + 0x18)) {
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x18);
    FUN_007c84d0(param_1,param_1 + 0x20,param_2);
    return;
  }
  FUN_007c8390(param_3,0xff,param_3,0xff,param_3);
  return;
}


// ==== FUN_007c97b0 @ 0x007c97b0 ====

void FUN_007c97b0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1[2];
  if (param_1[1] == iVar2) {
    param_1[2] = iVar2 * 2;
    iVar2 = FUN_00806326(*param_1,iVar2 * 0x18);
    *param_1 = iVar2;
  }
  iVar2 = param_1[1];
  iVar1 = *param_1;
  *(undefined4 *)(iVar1 + iVar2 * 0xc) = param_2;
  *(undefined4 *)(iVar1 + 4 + iVar2 * 0xc) = param_3;
  *(undefined4 *)(*param_1 + 8 + param_1[1] * 0xc) = param_4;
  param_1[1] = param_1[1] + 1;
  return;
}


// ==== FUN_007c9810 @ 0x007c9810 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_007c9810(void)

{
  BOOL BVar1;
  int unaff_EBX;
  tagMSG local_1c;
  
  while( true ) {
    if (unaff_EBX == 0) {
      BVar1 = PeekMessageA(&local_1c,(HWND)0x0,0,0,1);
      if (BVar1 == 0) {
        return 1;
      }
    }
    else {
      BVar1 = GetMessageA(&local_1c,(HWND)0x0,0,0);
      if (BVar1 < 1) {
        return 0;
      }
    }
    if (local_1c.message == 0x464) break;
    if (local_1c.message != 0x465) {
      return 1;
    }
    DAT_00b5c348 = local_1c.lParam;
    _DAT_00b5c21e = local_1c.lParam;
  }
  return 0;
}


// ==== FUN_007c9c50 @ 0x007c9c50 ====

undefined1 * FUN_007c9c50(char *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  do {
    param_4 = param_4 + -1;
    if (param_4 < 0) {
      return &DAT_0099cf70;
    }
    iVar1 = __stricmp(*(char **)(param_2 + param_4 * 4),param_1);
  } while (iVar1 != 0);
  return *(undefined1 **)(param_3 + param_4 * 4);
}


// ==== FUN_007c9d40 @ 0x007c9d40 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007c9d40(int *param_1,int param_2)

{
  char cVar1;
  undefined4 uVar2;
  undefined4 extraout_EAX;
  void *pvVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 local_91c;
  int local_918;
  int local_914;
  undefined4 local_910;
  int local_90c;
  int local_908;
  char local_904 [255];
  undefined1 local_805;
  undefined1 local_804 [2048];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  local_914 = 0;
  if (0 < param_1[1]) {
    local_918 = 0;
    do {
      iVar4 = *param_1;
      uVar8 = *(undefined4 *)(local_918 + iVar4);
      uVar2 = *(undefined4 *)(local_918 + 4 + iVar4);
      local_90c = *(int *)(local_918 + iVar4 + 8);
      if ((*(uint *)(param_2 + 0x1188) < local_90c + 0x400U) ||
         (pvVar3 = *(void **)(param_2 + 0x118c), pvVar3 == (void *)0x0)) {
        *(uint *)(param_2 + 0x1188) = local_90c + 0x400U;
        if (*(void **)(param_2 + 0x118c) != (void *)0x0) {
          _free(*(void **)(param_2 + 0x118c));
          return extraout_EAX;
        }
        pvVar3 = _malloc(*(size_t *)(param_2 + 0x1188));
        *(void **)(param_2 + 0x118c) = pvVar3;
        if (pvVar3 == (void *)0x0) {
          *(undefined4 *)(param_2 + 0x1188) = 0;
          return 0;
        }
      }
      local_908 = *(int *)(param_2 + 0x1188);
      if (local_908 == 0) {
        return 0;
      }
      iVar4 = FUN_007cd090(param_2 + 0x10,uVar8,uVar2,0,&local_908,pvVar3,local_804,&LAB_007c9c90,
                           param_2);
      if (iVar4 != 0) {
        uVar8 = 1;
        goto LAB_007c9f78;
      }
      FUN_007cb470(local_804,&local_910);
      uVar5 = FUN_007cb5e0(local_910,s_celldescriptors_009feef8,&DAT_009fee74);
      __snprintf(local_904,0x100,s_UPDATE_content_SET_descriptor__s_009fefb8,uVar5,uVar8,uVar2);
      local_805 = 0;
      FUN_007cdb70(DAT_00b5c238,local_904,0,0,0);
      __snprintf(local_904,0x100,s_UPDATE_content_SET_data___WHERE_c_009fef84,uVar8,uVar2);
      local_805 = 0;
      FUN_007cb590(local_910);
      pcVar6 = local_904;
      local_91c = 0;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_007ceac0(DAT_00b5c238,local_904,(int)pcVar6 - (int)(local_904 + 1),&local_91c,0);
      FUN_007cd730(DAT_00b5c238);
      FUN_007ce3c0(local_91c,1,*(undefined4 *)(param_2 + 0x118c),local_90c,0);
      iVar7 = FUN_007ce0a0(local_91c);
      for (iVar4 = 3; (iVar7 == 5 && (0 < iVar4)); iVar4 = iVar4 + -1) {
        Sleep(0x5dc);
        iVar7 = FUN_007ce0a0(local_91c);
      }
      FUN_007cd7b0(local_91c);
      local_918 = local_918 + 0xc;
      local_914 = local_914 + 1;
    } while (local_914 < param_1[1]);
  }
  uVar8 = 0;
LAB_007c9f78:
  *(undefined4 *)(param_2 + 0x1168) = 0;
  *(undefined4 *)(param_2 + 0x116c) = 0;
  return uVar8;
}


// ==== FUN_007c9fc0 @ 0x007c9fc0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007c9fc0(void)

{
  BOOL BVar1;
  HANDLE hObject;
  int iVar2;
  char local_804 [1024];
  char local_404 [1024];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  __snprintf(local_404,0x3ff,&DAT_009ff01c,&DAT_00b5c378,s_imcontent_cache_009ff024);
  __snprintf(local_804,0x3ff,&DAT_009ff01c,&DAT_00b5c378,s_imcontentQ_cache_009ff008);
  iVar2 = 0;
  do {
    BVar1 = MoveFileA(local_404,local_804);
    if (BVar1 != 0) break;
    Sleep(0xfa);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  hObject = CreateFileA(local_804,0x80000000,0,(LPSECURITY_ATTRIBUTES)0x0,3,0x8000080,(HANDLE)0x0);
  if (hObject != (HANDLE)0xffffffff) {
    iVar2 = FUN_007cd100(&DAT_00b5b1f8,hObject);
    CloseHandle(hObject);
    if (iVar2 != 0) {
      return iVar2;
    }
    DeleteFileA(local_804);
    FUN_007cee50(DAT_00b5c222);
    DAT_00b5c222 = 0xffffffff;
  }
  return 0;
}


// ==== FUN_007ca0f0 @ 0x007ca0f0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_007ca0f0(void)

{
  tm *_Tm;
  uint uVar1;
  int iVar2;
  int iVar3;
  time_t tVar4;
  __time32_t local_208;
  char local_204 [511];
  undefined1 local_5;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  local_208 = FID_conflict___time32((__time32_t *)0x0);
  _Tm = _localtime((time_t *)&local_208);
  tVar4 = _mktime(_Tm);
  uVar1 = (uint)tVar4;
  iVar3 = (int)uVar1 >> 0x1f;
  __snprintf(local_204,0x200,s_UPDATE_content_SET_active_1_WHER_009ff128,uVar1,iVar3,uVar1,iVar3,
             uVar1,iVar3);
  local_5 = 0;
  while (iVar2 = FUN_007cdb70(DAT_00b5c238,local_204,0,0,0), iVar2 == 5) {
    Sleep(1);
  }
  if (iVar2 != 0) {
    return 0;
  }
  __snprintf(local_204,0x200,s_UPDATE_content_SET_active__1_exp_009ff070,uVar1 + 0x127500,
             iVar3 + (uint)(0xffed8aff < uVar1),uVar1,iVar3);
  local_5 = 0;
  while (iVar2 = FUN_007cdb70(DAT_00b5c238,local_204,0,0,0), iVar2 == 5) {
    Sleep(1);
  }
  if (iVar2 != 0) {
    __snprintf(local_204,0x200,s_DELETE_FROM_content_WHERE_active_009ff034,uVar1,iVar3);
    local_5 = 0;
    while (iVar3 = FUN_007cdb70(DAT_00b5c238,local_204,0,0,0), iVar3 == 5) {
      Sleep(1);
    }
    if (iVar3 != 0) {
      return 0;
    }
  }
  return 1;
}


// ==== FUN_007ca260 @ 0x007ca260 ====

void FUN_007ca260(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (DAT_00b5c230 != (void *)0x0) {
    _free(DAT_00b5c230);
    return;
  }
  DeleteCriticalSection((LPCRITICAL_SECTION)&DAT_00b5c358);
  FUN_007cd1b0(DAT_00b5c23c);
  FUN_007cd1b0(DAT_00b5c238);
  puVar2 = &DAT_00b5b1e8;
  for (iVar1 = 0x464; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  return;
}


// ==== FUN_007ca6b0 @ 0x007ca6b0 ====

int FUN_007ca6b0(void)

{
  undefined1 *in_EAX;
  int iVar1;
  undefined1 *in_ECX;
  uint in_EDX;
  int iVar2;
  
  iVar1 = 0;
  if (1 < in_EDX) {
    iVar1 = in_EDX - 1;
    iVar2 = iVar1;
    do {
      *in_ECX = *in_EAX;
      in_ECX = in_ECX + 1;
      in_EAX = in_EAX + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  *in_ECX = 0;
  return iVar1;
}


// ==== FUN_007ca6e0 @ 0x007ca6e0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007ca6e0(undefined4 param_1,int param_2,undefined4 *param_3)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  uint local_ac;
  char *local_a8;
  uint local_a4;
  undefined4 local_a0 [12];
  undefined4 local_70 [2];
  char local_68 [8];
  undefined1 local_60;
  undefined4 local_58 [14];
  char local_20 [8];
  undefined1 local_18;
  undefined4 local_c;
  
  local_c = DAT_00b49670;
  if (param_2 < 2) {
    uVar8 = 0;
  }
  else {
    pcVar4 = (char *)FUN_007cdf50(*param_3);
    local_a8 = (char *)FUN_007cdf50(param_3[1]);
    puVar7 = local_a0;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = 0x30303030;
      puVar7 = puVar7 + 1;
    }
    puVar7 = local_58;
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar7 = 0x30303030;
      puVar7 = puVar7 + 1;
    }
    local_60 = 0;
    local_18 = 0;
    pcVar1 = pcVar4 + 1;
    do {
      cVar3 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar3 != '\0');
    pcVar2 = local_a8 + 1;
    pcVar6 = local_a8;
    do {
      cVar3 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar3 != '\0');
    if (((uint)((int)pcVar4 - (int)pcVar1) < 0x41) && ((uint)((int)pcVar6 - (int)pcVar2) < 0x41)) {
      if (pcVar4 != pcVar1) {
        FUN_007ca6b0();
      }
      if (pcVar6 != pcVar2) {
        FUN_007ca6b0();
      }
      iVar5 = 0;
      do {
        _sscanf(local_68 + iVar5,&DAT_009ff28c,&local_ac);
        _sscanf(local_20 + iVar5,&DAT_009ff28c,&local_a4);
        if ((local_a4 & local_ac) != local_a4) {
          uVar8 = 0;
          goto LAB_007ca81b;
        }
        puVar7 = (undefined4 *)((int)local_70 + iVar5);
        local_68[iVar5] = '\0';
        local_20[iVar5] = '\0';
        iVar5 = iVar5 + -8;
      } while (local_a0 <= puVar7);
      uVar8 = 1;
    }
    else {
      uVar8 = 1;
    }
  }
LAB_007ca81b:
  FUN_007cdfe0(param_1,uVar8);
  return;
}


// ==== FUN_007ca890 @ 0x007ca890 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4
FUN_007ca890(undefined4 param_1,undefined2 param_2,undefined4 *param_3,uint param_4,char *param_5)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  bool bVar8;
  char local_404 [1024];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (DAT_00b5c478 != '\0') {
    return 0xffffff9c;
  }
  iVar2 = 4;
  bVar8 = true;
  piVar5 = &DAT_00b5b1e8;
  piVar6 = &DAT_009ff494;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar8 = *piVar5 == *piVar6;
    piVar5 = piVar5 + 1;
    piVar6 = piVar6 + 1;
  } while (bVar8);
  if (bVar8) {
    return 0;
  }
  __snprintf(local_404,0x3ff,&DAT_009ff01c,&DAT_00b5c378,s_icontent_cache_009ff484);
  FUN_008065d4(local_404,0x180);
  iVar2 = thunk_FUN_007cd8e0(local_404,&DAT_00b5c238);
  if (iVar2 == 0) {
    iVar2 = thunk_FUN_007cd8e0(local_404,&DAT_00b5c23c);
    if (iVar2 == 0) {
      FUN_007cdb70(DAT_00b5c23c,s_CREATE_TABLE_contentlist__record_009ff3e8,0,0,0);
      FUN_007cdb70(DAT_00b5c23c,s_CREATE_TABLE_content__contentId_I_009ff2e8,0,0,0);
      FUN_007cdb70(DAT_00b5c23c,s_PRAGMA_synchronous_OFF_009ff2cc,0,0,0);
      FUN_007cdb70(DAT_00b5c23c,s_PRAGMA_temp_store_memory_009ff2b0,0,0,0);
      FUN_007cd550(DAT_00b5c23c,s_checkdayparts_009ff2a0,2,1,0,&LAB_007ca630,0,0);
      FUN_007cd550(DAT_00b5c23c,s_desccmp_009ff298,2,1,0,FUN_007ca6e0,0,0);
      FUN_007cd550(DAT_00b5c23c,s_bitor_009ff290,2,1,0,&LAB_007ca840,0,0);
      if ((param_3 == (undefined4 *)0x0) || (param_4 == 0)) {
        DAT_00b5c230 = (undefined4 *)0x0;
        DAT_00b5c234 = 0;
      }
      else {
        DAT_00b5c230 = _malloc(param_4 * 4);
        puVar7 = DAT_00b5c230;
        for (uVar3 = param_4 & 0x3fffffff; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar7 = *param_3;
          param_3 = param_3 + 1;
          puVar7 = puVar7 + 1;
        }
        for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
          *(undefined1 *)puVar7 = *(undefined1 *)param_3;
          param_3 = (undefined4 *)((int)param_3 + 1);
          puVar7 = (undefined4 *)((int)puVar7 + 1);
        }
        DAT_00b5c234 = param_4;
      }
      DAT_00b5c22e = param_2;
      FUN_007cb680();
      _DAT_00b5c210 = 3;
      DAT_00b5c22a = param_1;
      if (param_5 == (char *)0x0) {
        param_5 = &DAT_0099cf70;
      }
      pcVar4 = &DAT_00b5c240;
      do {
        cVar1 = *param_5;
        param_5 = param_5 + 1;
        *pcVar4 = cVar1;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      DAT_00b5c348 = 0xffffffff;
      _DAT_00b5c370 = 0;
      DAT_00b5c374 = 0;
      _DAT_00b5c350 = 0;
      _DAT_00b5c354 = 0;
      DAT_00b5c34c = 0;
      InitializeCriticalSection((LPCRITICAL_SECTION)&DAT_00b5c358);
      DAT_00b5c340 = CreateThread((LPSECURITY_ATTRIBUTES)0x0,0,(LPTHREAD_START_ROUTINE)&LAB_007ca2c0
                                  ,(LPVOID)0x0,0,&DAT_00b5c344);
      if (DAT_00b5c340 == (HANDLE)0x0) {
        thunk_FUN_007ced10();
        FUN_007cd1b0(DAT_00b5c23c);
        FUN_007cd1b0(DAT_00b5c238);
        return 0xfffffff6;
      }
      DAT_00b5b1e8 = DAT_009ff494;
      DAT_00b5b1ec._0_1_ = s_c3igamagic77_009ff498[0];
      DAT_00b5b1ec._1_1_ = s_c3igamagic77_009ff498[1];
      DAT_00b5b1ec._2_1_ = s_c3igamagic77_009ff498[2];
      DAT_00b5b1ec._3_1_ = s_c3igamagic77_009ff498[3];
      DAT_00b5b1f0 = s_c3igamagic77_009ff498[4];
      DAT_00b5b1f0_1._0_1_ = s_c3igamagic77_009ff498[5];
      DAT_00b5b1f0_1._1_1_ = s_c3igamagic77_009ff498[6];
      DAT_00b5b1f0_1._2_1_ = s_c3igamagic77_009ff498[7];
      DAT_00b5b1f4 = s_c3igamagic77_009ff498[8];
      DAT_00b5b1f4_1._0_1_ = s_c3igamagic77_009ff498[9];
      DAT_00b5b1f4_1._1_1_ = s_c3igamagic77_009ff498[10];
      DAT_00b5b1f4_1._2_1_ = s_c3igamagic77_009ff498[0xb];
      FUN_007ceea0();
      return 0;
    }
    FUN_007cd1b0(DAT_00b5c238);
  }
  return 0xfffffff7;
}


// ==== FUN_007cab90 @ 0x007cab90 ====

void FUN_007cab90(void)

{
  HANDLE hObject;
  int iVar1;
  int *piVar2;
  int *piVar3;
  bool bVar4;
  
  iVar1 = 4;
  bVar4 = true;
  piVar2 = &DAT_00b5b1e8;
  piVar3 = &DAT_009ff494;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *piVar2 == *piVar3;
    piVar2 = piVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (bVar4);
  if (bVar4) {
    PostThreadMessageA(DAT_00b5c344,0x464,0,0);
    hObject = DAT_00b5c340;
    WaitForSingleObject(DAT_00b5c340,10000);
    CloseHandle(hObject);
    thunk_FUN_007ced10();
    return;
  }
  return;
}


// ==== FUN_007cabe0 @ 0x007cabe0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_007cabe0(undefined4 param_1,undefined4 param_2,int *param_3,uint *param_4,undefined4 *param_5,
            char *param_6)

{
  char cVar1;
  tm *_Tm;
  uint uVar2;
  char *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  int *piVar9;
  bool bVar10;
  time_t tVar11;
  undefined4 local_42c;
  __time32_t local_428;
  undefined4 *local_424;
  undefined4 *local_420;
  uint local_41c;
  undefined4 local_418;
  int local_414;
  int local_410;
  int local_408;
  char local_404 [255];
  undefined1 local_305;
  undefined1 local_5;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (DAT_00b5c478 != '\0') {
    return 0xfffffff8;
  }
  iVar5 = 4;
  bVar10 = true;
  piVar8 = &DAT_00b5b1e8;
  piVar9 = &DAT_009ff494;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar10 = *piVar8 == *piVar9;
    piVar8 = piVar8 + 1;
    piVar9 = piVar9 + 1;
  } while (bVar10);
  if (!bVar10) {
    return 0xfffffff4;
  }
  if (param_3 == (int *)0x0) {
    return 0xfffffffc;
  }
  if ((param_5 != (undefined4 *)0x0) && (param_4 == (uint *)0x0)) {
    return 0xfffffffc;
  }
  if (*param_3 == 0 && param_3[1] == 0) {
    local_428 = FID_conflict___time32((__time32_t *)0x0);
    _Tm = _localtime((time_t *)&local_428);
    tVar11 = _mktime(_Tm);
    iVar5 = (int)tVar11;
    iVar7 = iVar5 >> 0x1f;
    __snprintf(local_404,0x400,s_SELECT_contentlist_contentId_FRO_009ff530,DAT_00b5c22a,param_1,
               &DAT_00b49158,param_2,&DAT_00b5c240,iVar5,iVar7,iVar5,iVar7,iVar5,iVar7);
    local_5 = 0;
    local_424 = &DAT_00b5b1e8;
    local_420 = param_5;
    local_418 = 0;
    local_408 = 0;
    if (param_4 == (uint *)0x0) {
      local_41c = 0;
    }
    else {
      local_41c = *param_4;
    }
    while (iVar5 = FUN_007cdb70(DAT_00b5c23c,local_404,&LAB_007ca5f0,&local_424,0), iVar5 != 0) {
      if ((iVar5 != 6) && (iVar5 != 5)) {
        return 0xfffffff7;
      }
    }
    if (local_408 == 0) {
      return 0xfffffff8;
    }
    *param_3 = local_414;
    param_3[1] = local_410;
  }
  else {
    local_414 = *param_3;
    local_410 = param_3[1];
  }
  if (param_5 == (undefined4 *)0x0) {
    __snprintf(local_404,0x100,s_SELECT_size_FROM_content_WHERE_c_009ff4b0,local_414,local_410);
    local_305 = 0;
    FUN_007ceac0(DAT_00b5c23c,local_404,0xffffffff,&local_42c,0);
    iVar5 = FUN_007ce0a0(local_42c);
    if (iVar5 != 100) {
      FUN_007cd7b0(local_42c);
      return 0xfffffff8;
    }
    if (param_4 != (uint *)0x0) {
      uVar2 = FUN_007ce2c0(local_42c,0);
      *param_4 = uVar2;
    }
    FUN_007cd7b0(local_42c);
  }
  else {
    __snprintf(local_404,0x100,s_SELECT_data_props_FROM_content_W_009ff4f4,local_414,local_410);
    local_305 = 0;
    FUN_007ceac0(DAT_00b5c23c,local_404,0xffffffff,&local_42c,0);
    iVar5 = FUN_007ce0a0(local_42c);
    if (iVar5 != 100) {
      FUN_007cd7b0(local_42c);
      return 0xfffffff8;
    }
    iVar5 = FUN_007ce2a0(local_42c,0);
    if ((int)*param_4 < iVar5) {
      FUN_007cd7b0(local_42c);
      return 0xfffffff9;
    }
    uVar2 = FUN_007ce2a0(local_42c,0);
    *param_4 = uVar2;
    if (param_6 != (char *)0x0) {
      pcVar3 = (char *)FUN_007ce2e0(local_42c,1);
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        *param_6 = cVar1;
        param_6 = param_6 + 1;
      } while (cVar1 != '\0');
    }
    uVar2 = *param_4;
    puVar4 = (undefined4 *)FUN_007ce420(local_42c,0);
    for (uVar6 = uVar2 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
      *param_5 = *puVar4;
      puVar4 = puVar4 + 1;
      param_5 = param_5 + 1;
    }
    for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)param_5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      param_5 = (undefined4 *)((int)param_5 + 1);
    }
    FUN_007cd7b0(local_42c);
  }
  return 0;
}


// ==== FUN_007caf70 @ 0x007caf70 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_007caf70(undefined2 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,float param_7,float param_8,int param_9)

{
  char cVar1;
  HANDLE hFile;
  DWORD lDistanceToMove;
  int iVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  undefined4 local_c58;
  char *local_c54;
  DWORD local_c50 [12];
  undefined2 local_c20;
  undefined4 local_c1e;
  undefined4 local_c1a;
  undefined4 local_c16;
  undefined4 local_c12;
  undefined4 local_c0e;
  char local_c04 [1024];
  char local_804 [1024];
  char local_404 [1024];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (DAT_00b5c478 != '\0') {
    return 0;
  }
  iVar2 = 4;
  bVar5 = true;
  piVar3 = &DAT_00b5b1e8;
  piVar4 = &DAT_009ff494;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar5 = *piVar3 == *piVar4;
    piVar3 = piVar3 + 1;
    piVar4 = piVar4 + 1;
  } while (bVar5);
  if (!bVar5) {
    return 0xfffffff4;
  }
  __snprintf(local_404,0x400,s_UPDATE_content_SET_viewcount_vie_009ff73c,param_3);
  do {
    iVar2 = FUN_007cdb70(DAT_00b5c23c,local_404,0,0);
    if (iVar2 != 0) {
      Sleep(1);
    }
  } while (iVar2 == 5);
  if (iVar2 != 0) {
    return 0xfffffff7;
  }
  __snprintf(local_c04,0x3ff,&DAT_009ff01c,&DAT_00b5c378);
  FUN_008065d4(local_c04,0x180);
  hFile = CreateFileA(local_c04,0x40000000,0,(LPSECURITY_ATTRIBUTES)0x0,4,0x8000080,(HANDLE)0x0);
  if ((hFile == (HANDLE)0xffffffff) &&
     (hFile = CreateFileA(local_c04,0x40000000,1,(LPSECURITY_ATTRIBUTES)0x0,4,0x8000080,(HANDLE)0x0)
     , hFile == (HANDLE)0xffffffff)) {
    return 0xfffffff7;
  }
  lDistanceToMove = GetFileSize(hFile,(LPDWORD)0x0);
  SetFilePointer(hFile,lDistanceToMove,(PLONG)0x0,0);
  local_c58 = 0;
  if (param_9 != 0) {
    FUN_007cb470(param_9,&local_c58);
  }
  __snprintf(local_c04,0x3ff,&DAT_009ff734,(double)param_7);
  FUN_007cb300(&local_c58,&DAT_009ff72c,local_c04);
  __snprintf(local_c04,0x3ff,&DAT_009ff734,(double)param_8);
  FUN_007cb300(&local_c58,s_Deflection_009ff720,local_c04);
  FUN_007cb360(local_c58,local_804,0x3ff);
  FUN_007cb590(local_c58);
  local_c20 = param_1;
  local_c0e = param_6;
  local_c54 = local_804;
  local_c12 = param_5;
  local_c1e = param_2;
  local_c1a = param_3;
  local_c16 = param_4;
  do {
    cVar1 = *local_c54;
    local_c54 = local_c54 + 1;
  } while (cVar1 != '\0');
  local_c54 = local_c54 + (1 - (int)(local_804 + 1));
  WriteFile(hFile,&local_c20,0x16,local_c50,(LPOVERLAPPED)0x0);
  WriteFile(hFile,&local_c54,2,local_c50,(LPOVERLAPPED)0x0);
  if ((short)local_c54 != 0) {
    WriteFile(hFile,local_804,(uint)local_c54 & 0xffff,local_c50,(LPOVERLAPPED)0x0);
  }
  CloseHandle(hFile);
  return 0;
}


// ==== FUN_007cb250 @ 0x007cb250 ====

char * FUN_007cb250(char *param_1)

{
  int iVar1;
  char cVar2;
  int in_EAX;
  int *in_EDX;
  char *pcVar3;
  char *pcVar4;
  
  if ((in_EAX != 0) && (in_EAX != -1)) {
    *in_EDX = in_EAX;
    *(undefined1 *)(in_EDX + 1) = 0xff;
  }
  if ((char)in_EDX[1] != -1) {
    *(char *)*in_EDX = (char)in_EDX[1];
  }
  if (in_EAX != -1) {
    cVar2 = *(char *)*in_EDX;
    while (cVar2 != '\0') {
      cVar2 = *param_1;
      pcVar3 = param_1;
      if (cVar2 != '\0') {
        while (cVar2 != *(char *)*in_EDX) {
          cVar2 = pcVar3[1];
          pcVar3 = pcVar3 + 1;
          if (cVar2 == '\0') goto LAB_007cb29c;
        }
      }
      if (*pcVar3 == '\0') {
LAB_007cb29c:
        pcVar3 = (char *)*in_EDX;
        cVar2 = *pcVar3;
        do {
          if (cVar2 == '\0') {
            *(undefined1 *)(in_EDX + 1) = 0xff;
            return pcVar3;
          }
          cVar2 = *param_1;
          pcVar4 = param_1;
          if (cVar2 == '\0') {
LAB_007cb2d7:
            if (*pcVar4 != '\0') {
              *(undefined1 *)(in_EDX + 1) = *(undefined1 *)*in_EDX;
              *(undefined1 *)*in_EDX = 0;
              return pcVar3;
            }
          }
          else {
            do {
              if (cVar2 == *(char *)*in_EDX) goto LAB_007cb2d7;
              cVar2 = pcVar4[1];
              pcVar4 = pcVar4 + 1;
            } while (cVar2 != '\0');
          }
          iVar1 = *in_EDX;
          *in_EDX = iVar1 + 1;
          cVar2 = *(char *)(iVar1 + 1);
        } while( true );
      }
      iVar1 = *in_EDX;
      *in_EDX = iVar1 + 1;
      cVar2 = *(char *)(iVar1 + 1);
    }
  }
  return (char *)0x0;
}


// ==== FUN_007cb300 @ 0x007cb300 ====

void FUN_007cb300(int *param_1,char *param_2,char *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  
  puVar3 = _malloc(0x10);
  puVar3[3] = 0;
  puVar3[2] = 0;
  pcVar4 = __strdup(param_2);
  *puVar3 = pcVar4;
  pcVar4 = __strdup(param_3);
  puVar3[1] = pcVar4;
  iVar1 = *param_1;
  if (iVar1 == 0) {
    *param_1 = (int)puVar3;
    return;
  }
  iVar2 = *(int *)(iVar1 + 8);
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar1 + 8);
    iVar2 = *(int *)(iVar1 + 8);
  }
  *(undefined4 **)(iVar1 + 8) = puVar3;
  puVar3[3] = iVar1;
  return;
}


// ==== FUN_007cb360 @ 0x007cb360 ====

void FUN_007cb360(undefined4 *param_1,char *param_2,int param_3)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  uint uVar4;
  uint _Count;
  char *pcVar5;
  
  _Count = param_3 - 1;
  bVar2 = true;
  *param_2 = '\0';
  while ((param_1 != (undefined4 *)0x0 && (_Count != 0))) {
    if (!bVar2) {
      pcVar5 = param_2 + -1;
      do {
        pcVar3 = pcVar5 + 1;
        pcVar5 = pcVar5 + 1;
      } while (*pcVar3 != '\0');
      *(undefined2 *)pcVar5 = DAT_009ff780;
      _Count = _Count - 1;
    }
    bVar2 = false;
    if (_Count != 0) {
      _strncat(param_2,(char *)*param_1,_Count);
      pcVar5 = (char *)*param_1;
      pcVar3 = pcVar5;
      do {
        cVar1 = *pcVar3;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      if (_Count < (uint)((int)pcVar3 - (int)(pcVar5 + 1))) {
        uVar4 = _Count;
      }
      else {
        pcVar3 = pcVar5 + 1;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        uVar4 = (int)pcVar5 - (int)pcVar3;
      }
      _Count = _Count - uVar4;
      if (_Count != 0) {
        pcVar5 = param_2 + -1;
        do {
          pcVar3 = pcVar5 + 1;
          pcVar5 = pcVar5 + 1;
        } while (*pcVar3 != '\0');
        _Count = _Count - 1;
        *(undefined2 *)pcVar5 = DAT_009ff77c;
        if (_Count != 0) {
          _strncat(param_2,(char *)param_1[1],_Count);
          pcVar5 = (char *)param_1[1];
          pcVar3 = pcVar5;
          do {
            cVar1 = *pcVar3;
            pcVar3 = pcVar3 + 1;
          } while (cVar1 != '\0');
          if (_Count < (uint)((int)pcVar3 - (int)(pcVar5 + 1))) {
            uVar4 = _Count;
          }
          else {
            pcVar3 = pcVar5 + 1;
            do {
              cVar1 = *pcVar5;
              pcVar5 = pcVar5 + 1;
            } while (cVar1 != '\0');
            uVar4 = (int)pcVar5 - (int)pcVar3;
          }
          _Count = _Count - uVar4;
        }
      }
    }
    param_1 = (undefined4 *)param_1[2];
  }
  return;
}


// ==== FUN_007cb470 @ 0x007cb470 ====

/* WARNING: Removing unreachable block (ram,0x007cb552) */
/* WARNING: Removing unreachable block (ram,0x007cb560) */

void FUN_007cb470(char *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  char *_Memory;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  
  _Memory = __strdup(param_1);
  iVar2 = FUN_007cb250(&DAT_009ff780);
  puVar1 = (undefined4 *)0x0;
  while ((iVar2 != 0 && (pcVar3 = (char *)FUN_007cb250(&DAT_009ff77c), pcVar3 != (char *)0x0))) {
    puVar4 = _malloc(0x10);
    puVar4[3] = 0;
    puVar4[2] = 0;
    pcVar3 = __strdup(pcVar3);
    *puVar4 = pcVar3;
    pcVar3 = (char *)FUN_007cb250(&DAT_009ff77c);
    if (pcVar3 == (char *)0x0) {
      pcVar3 = &DAT_0099cf70;
    }
    pcVar3 = __strdup(pcVar3);
    puVar4[1] = pcVar3;
    if (puVar1 == (undefined4 *)0x0) {
      *param_2 = puVar4;
    }
    else {
      puVar4[3] = puVar1;
      puVar1[2] = puVar4;
    }
    iVar2 = FUN_007cb250(&DAT_009ff780);
    puVar1 = puVar4;
  }
  if (puVar1 == (undefined4 *)0x0) {
    *param_2 = 0;
  }
  if (_Memory == (char *)0x0) {
    return;
  }
  _free(_Memory);
  return;
}


// ==== FUN_007cb590 @ 0x007cb590 ====

void FUN_007cb590(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    return;
  }
  if ((void *)*param_1 != (void *)0x0) {
    _free((void *)*param_1);
    return;
  }
  if ((void *)param_1[1] == (void *)0x0) {
    _free(param_1);
    return;
  }
  _free((void *)param_1[1]);
  return;
}


// ==== FUN_007cb5e0 @ 0x007cb5e0 ====

undefined4 FUN_007cb5e0(char *param_1,char *param_2,undefined4 param_3)

{
  char *pcVar1;
  int iVar2;
  
  pcVar1 = param_2;
  if (param_1 != (char *)0x0) {
    while (pcVar1 != (char *)0x0) {
      iVar2 = __stricmp(param_2,*(char **)param_1);
      if (iVar2 == 0) {
        return *(undefined4 *)(param_1 + 4);
      }
      param_1 = *(char **)(param_1 + 8);
      pcVar1 = param_1;
    }
  }
  return param_3;
}


// ==== FUN_007cb620 @ 0x007cb620 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007cb620(void)

{
  undefined1 uVar1;
  int iVar2;
  int unaff_EDI;
  undefined1 local_220 [8];
  LARGE_INTEGER local_218;
  undefined1 local_210 [524];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  QueryPerformanceCounter(&local_218);
  FUN_007cefb0(local_210,local_220,0x10);
  iVar2 = 0;
  do {
    uVar1 = FUN_007cf090(local_210);
    *(undefined1 *)(iVar2 + unaff_EDI) = uVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  return;
}


// ==== FUN_007cb680 @ 0x007cb680 ====

void FUN_007cb680(void)

{
  LARGE_INTEGER local_8;
  
  QueryPerformanceCounter(&local_8);
  FUN_00801d2d(local_8.s.LowPart);
  FUN_007cde30();
  FUN_007cecc0();
  FUN_007ceea0();
  return;
}


// ==== FUN_007cb6c0 @ 0x007cb6c0 ====

uint FUN_007cb6c0(int param_1)

{
  int unaff_EBX;
  uint uVar1;
  uint unaff_EDI;
  int local_4;
  
  uVar1 = 0;
  if (unaff_EDI != 0) {
    do {
      FUN_007cef00(uVar1 + param_1,&local_4,uVar1 + unaff_EBX,0x80);
      uVar1 = uVar1 + local_4;
    } while (uVar1 < unaff_EDI);
  }
  return uVar1;
}


// ==== FUN_007cb700 @ 0x007cb700 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_007cb700(int param_1,int param_2,undefined2 param_3,undefined4 *param_4,undefined4 param_5,
            undefined4 param_6,char *param_7,char *param_8,undefined4 param_9,undefined4 param_10,
            char *param_11)

{
  char cVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  undefined2 uVar7;
  undefined2 uVar8;
  char *pcVar9;
  undefined4 uVar10;
  int iVar11;
  int iVar12;
  uint uVar13;
  undefined4 *in_EDX;
  undefined4 *puVar14;
  char *pcVar15;
  undefined4 local_11d8;
  undefined4 local_11d4;
  undefined4 local_11d0;
  undefined4 local_11cc;
  undefined4 local_11c8;
  char *local_11c4;
  undefined4 *local_11c0;
  undefined4 local_11bc;
  undefined4 local_11b8;
  undefined1 local_11b4 [4];
  undefined4 local_11b0;
  undefined2 local_11ac;
  undefined2 uStack_11aa;
  undefined2 local_11a8;
  undefined2 uStack_11a6;
  undefined2 uStack_11a4;
  undefined4 local_11a2;
  undefined2 local_119e;
  undefined2 uStack_119c;
  undefined4 local_119a;
  undefined2 local_1196;
  char local_1194 [2436];
  char local_810 [254];
  undefined1 local_712;
  undefined4 local_c;
  
  local_c = DAT_00b49670;
  iVar12 = 0x271;
  puVar14 = &local_11d8;
  while( true ) {
    uVar6 = local_119e;
    uVar5 = local_11a2._2_2_;
    uVar4 = (undefined2)local_11a2;
    uVar8 = local_11a8;
    uVar2 = uStack_11aa;
    if (iVar12 == 0) break;
    *puVar14 = 0;
    iVar12 = iVar12 + -1;
    puVar14 = puVar14 + 1;
  }
  local_11d4 = *in_EDX;
  local_11d0 = in_EDX[1];
  local_11cc = in_EDX[2];
  local_11d8._0_2_ = param_3;
  local_11c8 = in_EDX[3];
  local_11d8._2_2_ = 3;
  uStack_11aa = (undefined2)param_6;
  uVar3 = uStack_11aa;
  local_11a8 = (undefined2)((uint)param_6 >> 0x10);
  local_11a2._2_2_ = SUB42(param_8,0);
  local_119e = (undefined2)((uint)param_8 >> 0x10);
  uVar7 = local_119e;
  local_11a2._0_2_ = (undefined2)((uint)param_7 >> 0x10);
  uStack_11aa = (undefined2)((uint)param_5 >> 0x10);
  switch(param_3) {
  case 100:
    local_11c0 = param_4;
    local_11b8 = param_6;
    local_11bc = param_5;
    pcVar9 = param_7;
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    pcVar9 = pcVar9 + (1 - (int)(param_7 + 1));
    if ((char *)0x800 < pcVar9) {
      pcVar9 = (char *)0x800;
    }
    local_11b4._0_2_ = (short)pcVar9;
    pcVar15 = local_11b4 + 2;
    uStack_11aa = uVar2;
    local_11a8 = uVar8;
    local_11a2._0_2_ = uVar4;
    local_11a2._2_2_ = uVar5;
    local_119e = uVar6;
    for (uVar13 = (uint)pcVar9 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(undefined4 *)pcVar15 = *(undefined4 *)param_7;
      param_7 = param_7 + 4;
      pcVar15 = pcVar15 + 4;
    }
    for (uVar13 = (uint)pcVar9 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar15 = *param_7;
      param_7 = param_7 + 1;
      pcVar15 = pcVar15 + 1;
    }
    local_11c4 = local_11b4 + (int)(pcVar9 + 2);
    uVar8 = local_11a8;
    break;
  case 0x65:
    local_11c0 = (undefined4 *)*param_4;
    local_11bc = param_4[1];
    local_11b8 = param_4[2];
    local_11b4 = (undefined1  [4])param_4[3];
    local_11b0 = param_4[4];
    local_11c4 = (char *)&local_11ac;
    uStack_11aa = uVar2;
    local_11a2._0_2_ = uVar4;
    local_11a2._2_2_ = uVar5;
    local_119e = uVar6;
    break;
  default:
    return 0xfffffffd;
  case 200:
    local_11c0 = (undefined4 *)*param_4;
    local_11bc = param_4[1];
    local_11b8 = param_4[2];
    local_11b4 = (undefined1  [4])param_4[3];
    local_11b0 = param_4[4];
    local_11ac = (undefined2)param_5;
    uStack_11a6 = param_7._0_2_;
    pcVar9 = param_8;
    do {
      cVar1 = *pcVar9;
      pcVar9 = pcVar9 + 1;
    } while (cVar1 != '\0');
    pcVar9 = pcVar9 + (1 - (int)(param_8 + 1));
    if ((char *)0x800 < pcVar9) {
      pcVar9 = (char *)0x800;
    }
    uStack_11a4 = SUB42(pcVar9,0);
    pcVar15 = (char *)&local_11a2;
    local_11a2._0_2_ = uVar4;
    local_11a2._2_2_ = uVar5;
    local_119e = uVar6;
    for (uVar13 = (uint)pcVar9 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(undefined4 *)pcVar15 = *(undefined4 *)param_8;
      param_8 = param_8 + 4;
      pcVar15 = pcVar15 + 4;
    }
    for (uVar13 = (uint)pcVar9 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar15 = *param_8;
      param_8 = param_8 + 1;
      pcVar15 = pcVar15 + 1;
    }
    local_11c4 = local_1194 + (int)(pcVar9 + -0xe);
    uStack_11aa = uVar3;
    uVar8 = local_11a8;
    break;
  case 0xd2:
    local_11c0 = (undefined4 *)*param_4;
    local_11bc = param_4[1];
    local_11b8 = param_4[2];
    local_11b4 = (undefined1  [4])param_4[3];
    local_11b0 = param_4[4];
    local_11c4 = (char *)&uStack_119c;
    local_11ac = (undefined2)param_5;
    uVar8 = uVar3;
    uStack_11a6 = local_11a8;
    uStack_11a4 = param_7._0_2_;
    break;
  case 300:
    local_11c0 = (undefined4 *)*param_4;
    local_11bc = param_4[1];
    local_11b8 = param_4[2];
    local_11b4 = (undefined1  [4])param_4[3];
    local_11b0 = param_4[4];
    local_11ac = (undefined2)param_5;
    local_119e = (undefined2)param_9;
    uStack_119c = (undefined2)((uint)param_9 >> 0x10);
    local_119a = param_10;
    if (param_11 == (char *)0x0) {
      param_11 = &DAT_0099cf70;
    }
    local_11c4 = param_11;
    do {
      cVar1 = *local_11c4;
      local_11c4 = local_11c4 + 1;
    } while (cVar1 != '\0');
    local_11c4 = local_11c4 + (1 - (int)(param_11 + 1));
    if ((char *)0x800 < local_11c4) {
      local_11c4 = (char *)0x800;
    }
    local_1196 = SUB42(local_11c4,0);
    pcVar9 = local_1194;
    for (uVar13 = (uint)local_11c4 >> 2; uVar13 != 0; uVar13 = uVar13 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)param_11;
      param_11 = param_11 + 4;
      pcVar9 = pcVar9 + 4;
    }
    for (uVar13 = (uint)local_11c4 & 3; uVar13 != 0; uVar13 = uVar13 - 1) {
      *pcVar9 = *param_11;
      param_11 = param_11 + 1;
      pcVar9 = pcVar9 + 1;
    }
    local_11c4 = local_1194 + (int)local_11c4;
    uStack_11aa = uVar3;
    uVar8 = local_11a8;
    uStack_11a6 = param_7._0_2_;
    uStack_11a4 = (undefined2)local_11a2;
    local_11a2._0_2_ = local_11a2._2_2_;
    local_11a2._2_2_ = uVar7;
    break;
  case 0x12d:
    local_11c0 = (undefined4 *)*param_4;
    local_11bc = param_4[1];
    local_11b8 = param_4[2];
    local_11b4 = (undefined1  [4])param_4[3];
    local_11b0 = param_4[4];
    local_11c4 = (char *)&local_11a8;
    local_11ac = (undefined2)param_5;
    local_11a2._0_2_ = uVar4;
    local_11a2._2_2_ = uVar5;
    local_119e = uVar6;
  }
  local_11a8 = uVar8;
  local_11c4 = local_11c4 + (-0x18 - (int)&local_11d8);
  uVar10 = FUN_007cb6c0(&local_11d8);
  iVar12 = __snprintf(local_810,0xff,s__s_u_009ff860,s_POST___HTTP_1_0_Content_Type__ap_009ff788,
                      uVar10);
  local_712 = 0;
  if (*(int *)(param_1 + 0x102a) != -1) {
LAB_007cba7e:
    iVar12 = FUN_007cee80(*(undefined4 *)(param_1 + 0x102a),local_810,iVar12);
    if ((iVar12 == -1) ||
       (iVar12 = FUN_007cee80(*(undefined4 *)(param_1 + 0x102a),&local_11d8,uVar10), iVar12 == -1))
    {
      FUN_007cee50(*(undefined4 *)(param_1 + 0x102a));
      *(undefined4 *)(param_1 + 0x102a) = 0xffffffff;
      return 0xffffffff;
    }
    return 0;
  }
  if (param_2 == 1) {
    iVar11 = FUN_007ced20(&DAT_00b5a850,DAT_00b5a848);
    *(int *)(param_1 + 0x102a) = iVar11;
    if (-1 < iVar11) goto LAB_007cba7e;
  }
  else {
    if (param_2 == 0) {
      uVar2 = *(undefined2 *)(param_1 + 0x814);
      iVar11 = param_1 + 0x14;
    }
    else {
      uVar2 = *(undefined2 *)(param_1 + 0x1016);
      iVar11 = param_1 + 0x816;
    }
    iVar11 = FUN_007ced20(iVar11,uVar2);
    *(int *)(param_1 + 0x102a) = iVar11;
    if (iVar11 != -1) goto LAB_007cba7e;
    iVar11 = -1;
  }
  FUN_007cee50(iVar11);
  *(undefined4 *)(param_1 + 0x102a) = 0xffffffff;
  return 0xfffffffe;
}


// ==== FUN_007cbc00 @ 0x007cbc00 ====

int FUN_007cbc00(SOCKET param_1,int param_2,uint param_3,uint param_4,uint *param_5,code *param_6,
                undefined4 param_7,int param_8)

{
  byte *pbVar1;
  uint uVar2;
  byte bVar3;
  char cVar4;
  int iVar5;
  uint uVar6;
  int *unaff_ESI;
  uint len;
  int iVar7;
  int local_114;
  uint local_10c;
  int local_108;
  fd_set local_104;
  
  uVar2 = unaff_ESI[1];
  local_114 = 0;
  if (uVar2 == 0) {
    return 0;
  }
  if (param_3 == 0) {
    param_3 = 1;
  }
  if (uVar2 < param_3) {
    return 0;
  }
  iVar5 = FUN_007cf230();
  if (iVar5 < (int)param_3) {
    while (iVar5 = FUN_007cf230(), iVar5 < (int)uVar2) {
      uVar6 = *param_5 / 10;
      if (0x19000 < uVar6) {
        uVar6 = 0x19000;
      }
      iVar5 = FUN_007cf230();
      len = uVar2 - iVar5;
      iVar5 = FUN_007cf260();
      if (iVar5 < (int)len) {
        len = FUN_007cf260();
      }
      if ((int)uVar6 < (int)len) {
        len = uVar6;
      }
      iVar5 = recv(param_1,(char *)(unaff_ESI[2] + *unaff_ESI),len,0);
      if (iVar5 < 0) {
        iVar5 = WSAGetLastError();
        if (iVar5 != 0x2733) {
          return -1;
        }
LAB_007cbdc9:
        Sleep(100);
        local_104.fd_array[0] = param_1;
        local_10c = param_4 / 1000;
        local_104.fd_count = 1;
        local_108 = (param_4 % 1000) * 1000;
        iVar5 = select(0,&local_104,(fd_set *)0x0,(fd_set *)0x0,
                       (timeval *)(-(uint)(param_4 != 0) & (uint)&local_10c));
        if (iVar5 != 1) {
          return -6;
        }
      }
      else {
        if (iVar5 == 0) {
          return -6;
        }
        local_114 = local_114 + iVar5;
        if ((param_2 != 0) && (iVar7 = 0, 0 < iVar5)) {
          do {
            pbVar1 = (byte *)((uint)(unaff_ESI[2] + iVar7) % (uint)unaff_ESI[1] + *unaff_ESI);
            bVar3 = FUN_007cf090(param_2);
            iVar7 = iVar7 + 1;
            *pbVar1 = *pbVar1 ^ bVar3;
          } while (iVar7 < iVar5);
        }
        if (param_6 != (code *)0x0) {
          if (param_8 == 0) {
            uVar6 = 0;
            iVar7 = 0;
            iVar5 = 0;
          }
          else {
            iVar5 = *unaff_ESI;
            iVar7 = local_114;
            uVar6 = param_3;
          }
          cVar4 = (*param_6)(iVar5,iVar7,uVar6,param_7);
          if (cVar4 < '\0') {
            return -0xb;
          }
        }
        FUN_007cf290();
        iVar5 = FUN_007cf230();
        if ((iVar5 < (int)param_3) && (iVar5 = FUN_007cf230(), iVar5 < (int)uVar2)) {
          Sleep(100);
          goto LAB_007cbdc9;
        }
      }
      iVar5 = FUN_007cf230();
      if ((int)param_3 <= iVar5) {
        return local_114;
      }
    }
  }
  return local_114;
}


// ==== FUN_007cbe70 @ 0x007cbe70 ====

long FUN_007cbe70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *in_EAX;
  int iVar1;
  uint uVar2;
  char *pcVar3;
  long lVar4;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  do {
    do {
      iVar1 = FUN_007cbc00(param_1,0,0,10000,&local_4,param_2,param_3,0);
      if (iVar1 < 1) {
        return -6;
      }
      uVar2 = FUN_007cf230();
    } while (uVar2 < 0x8d);
    iVar1 = *in_EAX;
    pcVar3 = _strstr((char *)(iVar1 + 0x87),&DAT_009ff86c);
  } while (pcVar3 == (char *)0x0);
  lVar4 = _atol((char *)(iVar1 + 0x87));
  FUN_007cf350();
  return lVar4;
}


// ==== FUN_007cbf10 @ 0x007cbf10 ====

undefined4 FUN_007cbf10(undefined4 param_1,undefined4 param_2,undefined4 *param_3,int param_4)

{
  int iVar1;
  ushort *puVar2;
  ushort local_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  iVar1 = FUN_007cbc00(param_1,param_2,2,10000,&local_4);
  if (-1 < iVar1) {
    FUN_007cf350();
    if (param_4 != 0) {
      puVar2 = _malloc(local_8 + 2);
      *param_3 = puVar2;
      *puVar2 = local_8;
    }
    iVar1 = FUN_007cbc00(param_1,param_2,local_8,10000,&local_4);
    if (-1 < iVar1) {
      FUN_007cf350();
      return 0;
    }
  }
  return 0xfffffffa;
}


// ==== FUN_007cbfd0 @ 0x007cbfd0 ====

undefined4
FUN_007cbfd0(undefined4 param_1,undefined4 param_2,undefined1 param_3,undefined4 param_4,
            undefined4 param_5)

{
  uint in_EAX;
  int iVar1;
  
  if (in_EAX < 0x46) {
    return 0xfffffff9;
  }
  iVar1 = FUN_007cbc00(param_1,param_2,0x46,10000,&param_3);
  if (iVar1 < 0) {
    return 0xfffffffa;
  }
  FUN_007cf350();
  return 0;
}


// ==== FUN_007cc030 @ 0x007cc030 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4
FUN_007cc030(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4,int param_5
            ,code *param_6)

{
  int iVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  undefined4 *puVar5;
  uint in_ECX;
  undefined4 local_81c;
  undefined4 *local_818;
  int local_814;
  undefined1 *local_810;
  undefined4 *local_80c;
  undefined1 local_808 [2052];
  undefined4 local_4;
  
  pcVar2 = param_6;
  iVar1 = param_5;
  local_4 = DAT_00b49670;
  local_810 = local_808;
  local_818 = (undefined4 *)0x0;
  local_80c = (undefined4 *)0x0;
  if (in_ECX < 0x20) {
    return 0xfffffff9;
  }
  iVar4 = FUN_007cbc00(param_1,param_3,0x1c,10000,&param_4,param_6);
  if (iVar4 < 0) {
    return 0xfffffffa;
  }
  FUN_007cf350(param_2,iVar1,0x1c);
  local_814 = 0;
  if (0 < *(int *)(iVar1 + 0x18)) {
    do {
      iVar4 = FUN_007cbf10(param_1,param_3,&local_810,0);
      if (iVar4 < 0) {
        return 0xfffffffa;
      }
      FUN_007cb470(local_810 + 2,&local_81c);
      if ((pcVar2 != (code *)0x0) &&
         (cVar3 = (*pcVar2)(local_81c,local_814,*(undefined4 *)(iVar1 + 0x18)), cVar3 < '\0')) {
        FUN_007cb590(local_81c);
        return 0xfffffff5;
      }
      if (*(int *)(iVar1 + 0x1c) == 0) {
        puVar5 = _malloc(0xc);
        *puVar5 = local_81c;
        puVar5[2] = 0;
        puVar5[1] = 0;
        if (local_818 == (undefined4 *)0x0) {
          local_818 = puVar5;
          local_80c = puVar5;
        }
        else {
          local_80c[1] = puVar5;
          puVar5[2] = local_80c;
          local_80c = puVar5;
        }
      }
      else {
        FUN_007cb590(local_81c);
      }
      local_814 = local_814 + 1;
    } while (local_814 < *(int *)(iVar1 + 0x18));
  }
  *(undefined4 **)(iVar1 + 0x1c) = local_818;
  return 0;
}


// ==== FUN_007cc220 @ 0x007cc220 ====

int FUN_007cc220(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                int param_5)

{
  uint uVar1;
  char cVar2;
  uint in_EAX;
  int iVar3;
  undefined4 uVar4;
  code *in_EDX;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (0x27 < in_EAX) {
    iVar3 = FUN_007cbc00(param_1,param_3,0x20,10000,param_4);
    if (iVar3 < 0) {
      return -6;
    }
    uVar1 = *(uint *)(param_5 + 0x1c);
    FUN_007cf350(param_2,param_5,0x20);
    if (*(uint *)(param_5 + 0x1c) <= uVar1) {
      FUN_007cbf10(param_1,param_3,param_5 + 0x20,1);
      local_10 = *(undefined4 *)(param_5 + 0x24);
      local_c = *(int *)(param_5 + 0x1c) + 1;
      local_4 = 0;
      local_8 = 0;
      uVar4 = FUN_007cf230(param_2);
      FUN_007cf4e0(&local_10,param_2,uVar4);
      iVar3 = FUN_007cbc00(param_1,param_3,*(undefined4 *)(param_5 + 0x1c),10000,param_4);
      if (-1 < iVar3) {
        if (in_EDX != (code *)0x0) {
          cVar2 = (*in_EDX)(*(undefined4 *)(param_5 + 0x24),0,0);
          if (cVar2 < '\0') {
            return -0xb;
          }
        }
        iVar3 = 0;
      }
      return iVar3;
    }
  }
  return -7;
}


// ==== FUN_007cc340 @ 0x007cc340 ====

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007cc340(undefined4 param_1,int param_2,uint param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 *puVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int unaff_EDI;
  undefined1 *local_1228;
  uint local_1224;
  undefined4 local_1220;
  int local_121c;
  short local_1218 [2];
  int local_1214;
  undefined1 local_1210 [524];
  undefined1 local_1004 [4096];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (param_3 < 0x18) {
    return -7;
  }
  FUN_007cefb0(local_1210,param_1,0x10);
  local_1228 = local_1004;
  iVar5 = 0;
  local_1224 = 0x1000;
  local_121c = 0;
  local_1220 = 0;
  iVar4 = FUN_007cbe70(*(undefined4 *)(unaff_EDI + 0x102a),param_4,param_5);
  if (iVar4 < 0) {
    FUN_007cee50(*(undefined4 *)(unaff_EDI + 0x102a));
    *(undefined4 *)(unaff_EDI + 0x102a) = 0xffffffff;
    return iVar4;
  }
  local_1214 = FUN_007cf230(&local_1228);
  if (0 < local_1214) {
    do {
      pbVar2 = local_1228 + (uint)(iVar5 + local_121c) % local_1224;
      bVar3 = FUN_007cf090(local_1210);
      iVar5 = iVar5 + 1;
      *pbVar2 = *pbVar2 ^ bVar3;
    } while (iVar5 < local_1214);
  }
  puVar1 = (undefined4 *)(unaff_EDI + 0x1026);
  iVar4 = FUN_007cbc00(*(undefined4 *)(unaff_EDI + 0x102a),local_1210,0x18,10000,puVar1,param_4,
                       param_5,0);
  if (iVar4 < 0) {
    if ((iVar4 == -6) || (iVar4 == -1)) {
      FUN_007cee50(*(undefined4 *)(unaff_EDI + 0x102a));
      *(undefined4 *)(unaff_EDI + 0x102a) = 0xffffffff;
      return iVar4;
    }
  }
  else {
    FUN_007cf420(&local_1228,local_1218,2);
    if (0x262 < local_1218[0]) {
      if ((local_1218[0] != 900) && (local_1218[0] == 0x3de)) {
        FUN_007cf350(&local_1228,param_2,0x18);
        return -100;
      }
LAB_007cc656:
      FUN_007cf350(&local_1228,param_2,0x18);
      return 0;
    }
    if (local_1218[0] == 0x262) {
      if (*(int *)(param_2 + 0x24) == 0) {
        return -7;
      }
      iVar4 = FUN_007cc220(*(undefined4 *)(unaff_EDI + 0x102a),&local_1228,local_1210,puVar1,param_2
                          );
    }
    else if (local_1218[0] == 500) {
      iVar4 = FUN_007cbfd0(*(undefined4 *)(unaff_EDI + 0x102a),local_1210,*puVar1,param_2,param_5);
    }
    else {
      if (local_1218[0] != 600) goto LAB_007cc656;
      iVar4 = FUN_007cc030(*(undefined4 *)(unaff_EDI + 0x102a),&local_1228,local_1210,*puVar1,
                           param_2,param_4);
    }
    if ((iVar4 == -6) || (iVar4 == -1)) {
      FUN_007cee50(*(undefined4 *)(unaff_EDI + 0x102a));
      *(undefined4 *)(unaff_EDI + 0x102a) = 0xffffffff;
    }
  }
  return iVar4;
}


// ==== FUN_007cc680 @ 0x007cc680 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007cc680(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_864;
  undefined4 local_860;
  short local_85c [12];
  undefined4 local_844;
  undefined4 local_840;
  undefined4 local_83c;
  undefined4 local_838;
  undefined4 local_834;
  undefined2 local_830;
  uint local_82e;
  undefined4 local_82a;
  undefined4 local_826;
  undefined4 local_822;
  undefined2 local_81e;
  undefined2 local_81c;
  uint local_81a;
  undefined1 local_814 [16];
  undefined1 local_804 [2048];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (DAT_00b5c478 != '\0') {
    return -100;
  }
  if (*(int *)((int)param_2 + 0x102a) != -1) {
    FUN_007cee50(*(int *)((int)param_2 + 0x102a));
    *(undefined4 *)((int)param_2 + 0x102a) = 0xffffffff;
  }
  FUN_007cf780(s_userid_009ff8a4,&local_864,0,0);
  FUN_007cf7a0(s_userinfo_009ff894,local_804,0x800,&DAT_009ff8a0);
  FUN_007cb620();
  iVar1 = FUN_007cb700(param_2,1,100,param_1,local_864,local_860,local_804);
  if (iVar1 != 0) {
    FUN_007cee50(*(undefined4 *)((int)param_2 + 0x102a));
    *(undefined4 *)((int)param_2 + 0x102a) = 0xffffffff;
    return iVar1;
  }
  *(undefined4 *)((int)param_2 + 0x1026) = 0xffffffff;
  iVar1 = FUN_007cc340(local_814,local_85c,0x46,0,0);
  if (iVar1 == -100) {
    return -100;
  }
  if (iVar1 < 0) {
    return -6;
  }
  FUN_007cee50(*(undefined4 *)((int)param_2 + 0x102a));
  *(undefined4 *)((int)param_2 + 0x102a) = 0xffffffff;
  if (local_85c[0] == 500) {
    *param_2 = local_844;
    param_2[1] = local_840;
    param_2[2] = local_83c;
    param_2[3] = local_838;
    param_2[4] = local_834;
    *(undefined2 *)(param_2 + 0x205) = local_830;
    *(undefined2 *)((int)param_2 + 0x1016) = local_81c;
    *(undefined4 *)((int)param_2 + 0x101e) = local_826;
    *(undefined4 *)((int)param_2 + 0x101a) = local_82a;
    *(undefined4 *)((int)param_2 + 0x1022) = local_822;
    *(undefined2 *)(param_2 + 0x406) = local_81e;
    _sprintf((char *)(param_2 + 5),s__d__d__d__d_009ff888,local_82e >> 0x18,local_82e >> 0x10 & 0xff
             ,local_82e >> 8 & 0xff,local_82e & 0xff);
    _sprintf((char *)((int)param_2 + 0x816),s__d__d__d__d_009ff888,local_81a >> 0x18,
             local_81a >> 0x10 & 0xff,local_81a >> 8 & 0xff,local_81a & 0xff);
    FUN_007cf800(s_userid_009ff8a4,*(undefined4 *)((int)param_2 + 0x101e),
                 *(undefined4 *)((int)param_2 + 0x1022));
    FUN_007cf7e0(s_default_min_time_009ff874,*(undefined2 *)(param_2 + 0x406));
    return 0;
  }
  if (local_85c[0] == 0x3b6) {
    return -3;
  }
  if (local_85c[0] == 0x3b7) {
    return -4;
  }
  return -5;
}


// ==== FUN_007cc950 @ 0x007cc950 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007cc950(int param_1)

{
  int iVar1;
  undefined1 local_2c [16];
  short local_1c [12];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (DAT_00b5c478 != '\0') {
    return 0;
  }
  if (*(int *)(param_1 + 0x102a) != -1) {
    FUN_007cee50(*(int *)(param_1 + 0x102a));
    *(undefined4 *)(param_1 + 0x102a) = 0xffffffff;
  }
  iVar1 = FUN_007ced20(&DAT_00b5a850,DAT_00b5a848);
  *(int *)(param_1 + 0x102a) = iVar1;
  if (iVar1 == -1) {
    return -2;
  }
  FUN_007cb620();
  iVar1 = FUN_007cb700(param_1,1,0x65,param_1);
  if (iVar1 == 0) {
    iVar1 = FUN_007cc340(local_2c,local_1c,0x18,0,0);
    if (iVar1 < 0) {
      return -6;
    }
    FUN_007cee50(*(undefined4 *)(param_1 + 0x102a));
    *(undefined4 *)(param_1 + 0x102a) = 0xffffffff;
    if (local_1c[0] != 900) {
      if (local_1c[0] == 0x3b6) {
        return -3;
      }
      if (local_1c[0] == 0x3b7) {
        return -4;
      }
      return -5;
    }
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_007ccaa0 @ 0x007ccaa0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007ccaa0(int param_1,undefined2 param_2,undefined4 param_3,undefined2 param_4,
                undefined4 param_5,undefined4 *param_6,int *param_7,undefined4 param_8,
                undefined4 param_9)

{
  int iVar1;
  undefined1 local_34 [16];
  short local_24 [12];
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (DAT_00b5c478 != '\0') {
    return -8;
  }
  FUN_007cb620();
  iVar1 = FUN_007cb700(param_1,0,200,param_1,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    local_8 = (param_7 != (int *)0x0) - 1;
    iVar1 = FUN_007cc340(local_34,local_24,0x20,param_8,param_9);
    if (iVar1 != 0) {
      FUN_007cee50(*(undefined4 *)(param_1 + 0x102a));
      *(undefined4 *)(param_1 + 0x102a) = 0xffffffff;
      return iVar1;
    }
    if (local_24[0] != 600) {
      return ((local_24[0] == 0x385) - 1 & 3) - 8;
    }
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = local_c;
    }
    if (param_7 != (int *)0x0) {
      *param_7 = local_8;
    }
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_007ccbd0 @ 0x007ccbd0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x007ccd7c) */
/* WARNING: Removing unreachable block (ram,0x007ccd66) */
/* WARNING: Removing unreachable block (ram,0x007ccd0a) */
/* WARNING: Removing unreachable block (ram,0x007ccd83) */
/* WARNING: Removing unreachable block (ram,0x007ccd11) */
/* WARNING: Removing unreachable block (ram,0x007ccd99) */

int FUN_007ccbd0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 *param_5,
                int param_6,int param_7,undefined4 param_8,undefined4 param_9)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int extraout_EAX;
  undefined4 uVar4;
  undefined1 auStack_3c [16];
  short asStack_2c [14];
  undefined4 uStack_10;
  void *pvStack_c;
  int iStack_8;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (DAT_00b5c478 != '\0') {
    return -8;
  }
  if ((((param_1 == 0) || (param_2 == 0 && param_3 == 0)) || (param_6 == 0)) ||
     (param_5 == (undefined4 *)0x0)) {
    return -4;
  }
  FUN_007cb620();
  iVar2 = FUN_007cb700(param_1,0,0xd2,param_1,param_2,param_3,param_4,*param_5);
  if (iVar2 == 0) {
    uStack_10 = *param_5;
    iStack_8 = param_6;
    iVar2 = FUN_007cc340(auStack_3c,asStack_2c,0x28,param_8,param_9);
    if (iVar2 == 0) {
      if (asStack_2c[0] != 0x262) {
        return ((asStack_2c[0] == 0x385) - 1 & 3) - 8;
      }
      *param_5 = uStack_10;
      if (param_7 != 0) {
        pcVar3 = (char *)((int)pvStack_c + 2);
        param_7 = param_7 - (int)pcVar3;
        do {
          cVar1 = *pcVar3;
          pcVar3[param_7] = cVar1;
          pcVar3 = pcVar3 + 1;
        } while (cVar1 != '\0');
      }
      _free(pvStack_c);
      return extraout_EAX;
    }
    uVar4 = *(undefined4 *)(param_1 + 0x102a);
  }
  else {
    uVar4 = *(undefined4 *)(param_1 + 0x102a);
  }
  FUN_007cee50(uVar4);
  *(undefined4 *)(param_1 + 0x102a) = 0xffffffff;
  return iVar2;
}


// ==== FUN_007ccbf7 @ 0x007ccbf7 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Removing unreachable block (ram,0x007ccd7c) */
/* WARNING: Removing unreachable block (ram,0x007ccd66) */
/* WARNING: Removing unreachable block (ram,0x007ccd0a) */
/* WARNING: Removing unreachable block (ram,0x007ccd83) */
/* WARNING: Removing unreachable block (ram,0x007ccd11) */
/* WARNING: Removing unreachable block (ram,0x007ccd99) */

int FUN_007ccbf7(void)

{
  char cVar1;
  undefined4 *puVar2;
  int iVar3;
  char *pcVar4;
  int extraout_EAX;
  int iVar5;
  undefined1 local_res0;
  undefined2 uStack00000010;
  undefined4 in_stack_0000002c;
  void *in_stack_00000030;
  int in_stack_00000034;
  int in_stack_00000040;
  int in_stack_00000044;
  int in_stack_00000048;
  undefined4 in_stack_0000004c;
  undefined4 *in_stack_00000050;
  int in_stack_00000054;
  int in_stack_00000058;
  undefined4 in_stack_0000005c;
  undefined4 in_stack_00000060;
  undefined4 uVar6;
  
  puVar2 = in_stack_00000050;
  iVar3 = in_stack_00000044;
  iVar5 = in_stack_00000040;
  if ((((in_stack_00000040 == 0) || (in_stack_00000044 == 0 && in_stack_00000048 == 0)) ||
      (in_stack_00000054 == 0)) || (in_stack_00000050 == (undefined4 *)0x0)) {
    return -4;
  }
  FUN_007cb620();
  iVar3 = FUN_007cb700(iVar5,0,0xd2,iVar5,iVar3,in_stack_00000048,in_stack_0000004c,*puVar2);
  if (iVar3 == 0) {
    in_stack_0000002c = *puVar2;
    in_stack_00000034 = in_stack_00000054;
    iVar3 = FUN_007cc340(&local_res0,&uStack00000010,0x28,in_stack_0000005c,in_stack_00000060);
    if (iVar3 == 0) {
      if (uStack00000010 != 0x262) {
        return ((uStack00000010 == 0x385) - 1 & 3) - 8;
      }
      *puVar2 = in_stack_0000002c;
      if (in_stack_00000058 != 0) {
        pcVar4 = (char *)((int)in_stack_00000030 + 2);
        iVar5 = in_stack_00000058 - (int)pcVar4;
        do {
          cVar1 = *pcVar4;
          pcVar4[iVar5] = cVar1;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
      }
      _free(in_stack_00000030);
      return extraout_EAX;
    }
    uVar6 = *(undefined4 *)(iVar5 + 0x102a);
  }
  else {
    uVar6 = *(undefined4 *)(iVar5 + 0x102a);
  }
  FUN_007cee50(uVar6);
  *(undefined4 *)(iVar5 + 0x102a) = 0xffffffff;
  return iVar3;
}


// ==== FUN_007ccdd0 @ 0x007ccdd0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007ccdd0(int param_1,HANDLE param_2)

{
  DWORD DVar1;
  int iVar2;
  DWORD DStack_640;
  DWORD DStack_63c;
  undefined1 auStack_638 [16];
  short asStack_628 [12];
  undefined1 auStack_610 [524];
  undefined1 auStack_404 [1024];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (DAT_00b5c478 != '\0') {
    return 0;
  }
  FUN_007cb620();
  DVar1 = GetFileSize(param_2,&DStack_63c);
  iVar2 = FUN_007cb700(param_1,2,0x12d,param_1,DVar1);
  if (iVar2 != 0) {
    FUN_007cee50(*(undefined4 *)(param_1 + 0x102a));
    *(undefined4 *)(param_1 + 0x102a) = 0xffffffff;
    return iVar2;
  }
  FUN_007cefb0(auStack_610,auStack_638,0x10);
  iVar2 = ReadFile(param_2,auStack_404,0x400,&DStack_640,(LPOVERLAPPED)0x0);
  while ((iVar2 != 0 && (DStack_640 != 0))) {
    FUN_007cf160(auStack_610,auStack_404,DStack_640);
    iVar2 = FUN_007cee80(*(undefined4 *)(param_1 + 0x102a),auStack_404,DStack_640);
    if (iVar2 == -1) {
      FUN_007cee50(*(undefined4 *)(param_1 + 0x102a));
      *(undefined4 *)(param_1 + 0x102a) = 0xffffffff;
      return -1;
    }
    iVar2 = ReadFile(param_2,auStack_404,0x400,&DStack_640,(LPOVERLAPPED)0x0);
  }
  iVar2 = FUN_007cc340(auStack_638,asStack_628,0x18,0,0);
  if (iVar2 == 0) {
    if (asStack_628[0] != 900) {
      if (asStack_628[0] == 0x385) {
        return -8;
      }
      return -5;
    }
    iVar2 = 0;
  }
  return iVar2;
}


// ==== FUN_007cce00 @ 0x007cce00 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007cce00(DWORD param_1)

{
  int iVar1;
  undefined1 local_res0;
  short in_stack_00000018;
  int in_stack_00000644;
  HANDLE in_stack_00000648;
  undefined1 auStackY_7ffffffe [2147483614];
  
  FUN_007cb620();
  GetFileSize(in_stack_00000648,&param_1);
  iVar1 = FUN_007cb700();
  if (iVar1 != 0) {
    FUN_007cee50();
    *(undefined4 *)(in_stack_00000644 + 0x102a) = 0xffffffff;
    return iVar1;
  }
  FUN_007cefb0();
  iVar1 = ReadFile(in_stack_00000648,(LPVOID)((int)register0x00000010 + 0x23c),0x400,
                   (LPDWORD)&local_res0,(LPOVERLAPPED)0x0);
  while ((iVar1 != 0 && (_local_res0 != 0))) {
    FUN_007cf160();
    iVar1 = FUN_007cee80();
    if (iVar1 == -1) {
      FUN_007cee50();
      *(undefined4 *)(in_stack_00000644 + 0x102a) = 0xffffffff;
      return -1;
    }
    iVar1 = ReadFile(in_stack_00000648,(LPVOID)((int)register0x00000010 + 0x23c),0x400,
                     (LPDWORD)&local_res0,(LPOVERLAPPED)0x0);
  }
  iVar1 = FUN_007cc340();
  if (iVar1 == 0) {
    if (in_stack_00000018 != 900) {
      if (in_stack_00000018 == 0x385) {
        return -8;
      }
      return -5;
    }
    iVar1 = 0;
  }
  return iVar1;
}


// ==== FUN_007ccfb0 @ 0x007ccfb0 ====

void FUN_007ccfb0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_007cc680(param_1,param_2);
    if (iVar1 != -6) {
      if (iVar1 == -2) {
        iVar2 = iVar2 + 1;
      }
      else if (iVar1 != -1) {
        return;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return;
}


// ==== FUN_007ccff0 @ 0x007ccff0 ====

void FUN_007ccff0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_007cc950(param_1);
    if (iVar1 != -6) {
      if (iVar1 == -2) {
        iVar2 = iVar2 + 1;
      }
      else if (iVar1 != -1) {
        return;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return;
}


// ==== FUN_007cd020 @ 0x007cd020 ====

void FUN_007cd020(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int iVar1;
  int local_4;
  
  local_4 = 0;
  do {
    iVar1 = FUN_007ccaa0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    if (iVar1 != -6) {
      if (iVar1 == -2) {
        local_4 = local_4 + 1;
      }
      else if (iVar1 != -1) {
        return;
      }
    }
    local_4 = local_4 + 1;
  } while (local_4 < 3);
  return;
}


// ==== FUN_007cd090 @ 0x007cd090 ====

void FUN_007cd090(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  int iVar1;
  int local_4;
  
  local_4 = 0;
  do {
    iVar1 = FUN_007ccbd0(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    if (iVar1 != -6) {
      if (iVar1 == -2) {
        local_4 = local_4 + 1;
      }
      else if (iVar1 != -1) {
        return;
      }
    }
    local_4 = local_4 + 1;
  } while (local_4 < 3);
  return;
}


// ==== FUN_007cd100 @ 0x007cd100 ====

void FUN_007cd100(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = FUN_007ccdd0(param_1,param_2);
    if (iVar1 != -6) {
      if (iVar1 == -2) {
        iVar2 = iVar2 + 1;
      }
      else if (iVar1 != -1) {
        return;
      }
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return;
}


// ==== FUN_007cd140 @ 0x007cd140 ====

undefined4 FUN_007cd140(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x6c) == 0) {
    uVar1 = FUN_007cfdf0();
    *(undefined4 *)(param_1 + 0x6c) = uVar1;
  }
  return *(undefined4 *)(param_1 + 0x6c);
}


// ==== FUN_007cd160 @ 0x007cd160 ====

int FUN_007cd160(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = param_2;
  if (param_4 <= param_2) {
    iVar1 = param_4;
  }
  iVar1 = FUN_007d0930(param_3,param_5,iVar1);
  if (iVar1 == 0) {
    iVar1 = param_2 - param_4;
  }
  return iVar1;
}


// ==== FUN_007cd190 @ 0x007cd190 ====

undefined8 FUN_007cd190(int param_1)

{
  return *(undefined8 *)(param_1 + 0x20);
}


// ==== FUN_007cd1a0 @ 0x007cd1a0 ====

undefined4 FUN_007cd1a0(int param_1)

{
  return *(undefined4 *)(param_1 + 0x38);
}


// ==== FUN_007cd1b0 @ 0x007cd1b0 ====

undefined4 FUN_007cd1b0(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  if (param_1 != (int *)0x0) {
    iVar4 = FUN_007d0ee0(param_1);
    if (iVar4 != 0) {
      return 0x15;
    }
    if (param_1[0x12] != 0) {
      FUN_007d07b0(param_1,5,s_Unable_to_close_due_to_unfinalis_009ff968);
      return 5;
    }
    if ((param_1[0xc] != -0x60c3d2cd) && (iVar4 = FUN_007d0e60(param_1), iVar4 != 0)) {
      return 1;
    }
    iVar4 = 0;
    if (0 < *param_1) {
      iVar5 = 0;
      do {
        iVar1 = param_1[1];
        iVar2 = *(int *)(iVar1 + 4 + iVar5);
        if (iVar2 != 0) {
          FUN_007db2b0(iVar2);
          *(undefined4 *)(iVar1 + iVar5 + 4) = 0;
        }
        iVar4 = iVar4 + 1;
        iVar5 = iVar5 + 0x70;
      } while (iVar4 < *param_1);
    }
    FUN_007d3fc0(param_1,0);
    piVar6 = (int *)param_1[0x27];
    if (piVar6 != (int *)0x0) {
      do {
        iVar4 = piVar6[2];
        while (iVar4 != 0) {
          iVar5 = *(int *)(iVar4 + 0x10);
          FUN_007d05b0(iVar4);
          iVar4 = iVar5;
        }
        piVar6 = (int *)*piVar6;
      } while (piVar6 != (int *)0x0);
    }
    piVar6 = (int *)param_1[0x2c];
    if (piVar6 != (int *)0x0) {
      do {
        FUN_007d05b0(piVar6[2]);
        piVar6 = (int *)*piVar6;
      } while (piVar6 != (int *)0x0);
    }
    FUN_007d1b80(param_1 + 0x2a);
    FUN_007d1b80(param_1 + 0x25);
    FUN_007d07b0(param_1,0,0);
    if (param_1[0x1b] != 0) {
      FUN_007cfe40(param_1[0x1b]);
    }
    if (param_1[0x1c] != 0) {
      FUN_007cfe40(param_1[0x1c]);
    }
    FUN_007d1ae0();
    piVar6 = DAT_00b5c47c;
    do {
      piVar3 = piVar6;
      if (piVar3 == (int *)0x0) {
        DAT_00b5c47c = (int *)param_1[0x24];
        goto LAB_007cd31c;
      }
      piVar6 = (int *)piVar3[0x24];
    } while ((int *)piVar3[0x24] != param_1);
    piVar3[0x24] = param_1[0x24];
LAB_007cd31c:
    FUN_007d1af0();
    param_1[0xc] = -0x4aca86d0;
    FUN_007d05b0(param_1);
  }
  return 0;
}


// ==== FUN_007cd350 @ 0x007cd350 ====

void FUN_007cd350(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  if (0 < *param_1) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(iVar3 + 4 + param_1[1]);
      if (iVar1 != 0) {
        FUN_007d6f50(iVar1);
        *(undefined1 *)(iVar3 + 0x5e + param_1[1]) = 0;
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x70;
    } while (iVar2 < *param_1);
  }
  FUN_007d3fc0(param_1,0);
  return;
}


// ==== FUN_007cd3a0 @ 0x007cd3a0 ====

char * FUN_007cd3a0(undefined4 param_1)

{
  switch(param_1) {
  case 0:
  case 100:
  case 0x65:
    return s_not_an_error_009ffc90;
  case 1:
    return s_SQL_logic_error_or_missing_datab_009ffc6c;
  case 2:
    return s_internal_SQLite_implementation_f_009ffc48;
  case 3:
    return s_access_permission_denied_009ffc2c;
  case 4:
    return s_callback_requested_query_abort_009ffc0c;
  case 5:
    return s_database_is_locked_009ffbf8;
  case 6:
    return s_database_table_is_locked_009ffbdc;
  case 7:
    return s_out_of_memory_009ffbcc;
  case 8:
    return s_attempt_to_write_a_readonly_data_009ffba4;
  case 9:
    return s_interrupted_009ffb98;
  case 10:
    return s_disk_I_O_error_009ffb88;
  case 0xb:
    return s_database_disk_image_is_malformed_009ffb64;
  case 0xc:
    return s_table_or_record_not_found_009ffb48;
  case 0xd:
    return s_database_is_full_009ffb34;
  case 0xe:
    return s_unable_to_open_database_file_009ffb14;
  case 0xf:
    return s_database_locking_protocol_failur_009ffaf0;
  case 0x10:
    return s_table_contains_no_data_009ffad8;
  case 0x11:
    return s_database_schema_has_changed_009ffabc;
  case 0x12:
    return s_too_much_data_for_one_table_row_009ffa9c;
  case 0x13:
    return s_constraint_failed_009ffa88;
  case 0x14:
    return s_datatype_mismatch_009ffa74;
  case 0x15:
    return s_library_routine_called_out_of_se_009ffa4c;
  case 0x16:
    return s_kernel_lacks_large_file_support_009ffa2c;
  case 0x17:
    return s_authorization_denied_009ffa14;
  case 0x18:
    return s_auxiliary_database_format_error_009ff9f4;
  case 0x19:
    return s_bind_or_column_index_out_of_rang_009ff9d0;
  case 0x1a:
    return s_file_is_encrypted_or_is_not_a_da_009ff9a8;
  default:
    return s_unknown_error_009ff998;
  }
}


// ==== FUN_007cd550 @ 0x007cd550 ====

int FUN_007cd550(int param_1,char *param_2,int param_3,uint param_4,undefined4 param_5,int param_6,
                int param_7,int param_8)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar2 = FUN_007d0ee0(param_1);
  if (iVar2 != 0) {
    return 0x15;
  }
  if (param_2 == (char *)0x0) {
    return 1;
  }
  if (param_6 == 0) {
    if (param_8 != 0) {
      if (param_7 == 0) {
        return 1;
      }
      goto LAB_007cd58e;
    }
  }
  else if (param_8 != 0) {
    return 1;
  }
  if (param_7 != 0) {
    return 1;
  }
LAB_007cd58e:
  if ((-2 < param_3) && (param_3 < 0x80)) {
    pcVar3 = param_2;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    iVar2 = (int)pcVar3 - (int)(param_2 + 1);
    if (iVar2 < 0x100) {
      if (param_4 == 4) {
        param_4 = 2;
      }
      else if (param_4 == 5) {
        iVar4 = FUN_007cd550(param_1,param_2,param_3,1,param_5,param_6,param_7,param_8);
        if (iVar4 != 0) {
          return iVar4;
        }
        iVar4 = FUN_007cd550(param_1,param_2,param_3,2,param_5,param_6,param_7,param_8);
        if (iVar4 != 0) {
          return iVar4;
        }
        param_4 = 3;
      }
      iVar4 = FUN_007de2e0(param_1,param_2,iVar2,param_3,param_4,0);
      if (((iVar4 != 0) && (*(byte *)(iVar4 + 8) == param_4)) && (*(int *)(iVar4 + 4) == param_3)) {
        if (*(int *)(param_1 + 0x4c) != 0) {
          FUN_007d07b0(param_1,5,s_Unable_to_delete_modify_user_fun_009ffca0);
          return 5;
        }
        FUN_007dda50(param_1);
      }
      iVar2 = FUN_007de2e0(param_1,param_2,iVar2,param_3,param_4,1);
      if (iVar2 == 0) {
        return 7;
      }
      *(int *)(iVar2 + 0x14) = param_6;
      *(int *)(iVar2 + 0x18) = param_7;
      *(int *)(iVar2 + 0x1c) = param_8;
      *(undefined4 *)(iVar2 + 0xc) = param_5;
      return 0;
    }
  }
  return 1;
}


// ==== FUN_007cd6c0 @ 0x007cd6c0 ====

int FUN_007cd6c0(int param_1,char *param_2,int param_3,undefined4 param_4,undefined4 *param_5)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = param_3 != 0;
  if ((*(uint *)(param_1 + 8) & 0x1000) != 0) {
    bVar2 = bVar2 | 2;
  }
  if ((param_2 == (char *)0x0) && (*(char *)(param_1 + 0x13) == '\x02')) {
    param_2 = s__memory__009ffce0;
  }
  iVar1 = FUN_007d6470(param_2,param_5,bVar2);
  if (iVar1 == 0) {
    FUN_007d6620(*param_5,param_1 + 0xbc);
    FUN_007d6640(*param_5,param_4);
  }
  return iVar1;
}


// ==== FUN_007cd730 @ 0x007cd730 ====

char * FUN_007cd730(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  if (DAT_00b5c4c4 != 0) {
    return s_out_of_memory_009ffbcc;
  }
  iVar1 = FUN_007d0ee0(param_1);
  if ((iVar1 == 0) && (*(int *)(param_1 + 0xc) != 0x15)) {
    pcVar2 = (char *)FUN_007cdf50(*(undefined4 *)(param_1 + 0x70));
    if (pcVar2 == (char *)0x0) {
      pcVar2 = (char *)FUN_007cd3a0();
      return pcVar2;
    }
  }
  else {
    pcVar2 = s_library_routine_called_out_of_se_009ffa4c;
  }
  return pcVar2;
}


// ==== FUN_007cd780 @ 0x007cd780 ====

undefined4 FUN_007cd780(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (DAT_00b5c4c4 != 0) {
    return 7;
  }
  iVar1 = FUN_007d0ee0(param_1);
  uVar2 = 0x15;
  if (iVar1 == 0) {
    uVar2 = *(undefined4 *)(param_1 + 0xc);
  }
  return uVar2;
}


// ==== FUN_007cd7b0 @ 0x007cd7b0 ====

void FUN_007cd7b0(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  FUN_007de120();
  return;
}


// ==== FUN_007cd7d0 @ 0x007cd7d0 ====

undefined4 FUN_007cd7d0(int param_1,char *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  iVar2 = FUN_007d0ee0(param_1);
  if (iVar2 != 0) {
    return 0x15;
  }
  if (param_3 == 4) {
    param_3 = 2;
  }
  else if (((param_3 != 1) && (param_3 != 2)) && (param_3 != 3)) {
    FUN_007d07b0(param_1,1,s_Param_3_to_sqlite3_create_collat_009ffcf0);
    return 1;
  }
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  iVar2 = FUN_007de2b0(param_1,param_3,param_2,(int)pcVar3 - (int)(param_2 + 1),0);
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0xc) != 0)) {
    if (*(int *)(param_1 + 0x4c) != 0) {
      FUN_007d07b0(param_1,5,s_Unable_to_delete_modify_collatio_009ffd68);
      return 5;
    }
    FUN_007dda50(param_1);
  }
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  iVar2 = FUN_007de2b0(param_1,param_3,param_2,(int)pcVar3 - (int)(param_2 + 1),1);
  if (iVar2 == 0) {
    FUN_007d07b0(param_1,7,0);
    return 7;
  }
  *(undefined4 *)(iVar2 + 0xc) = param_5;
  *(undefined4 *)(iVar2 + 8) = param_4;
  *(char *)(iVar2 + 4) = (char)param_3;
  FUN_007d07b0(param_1,0,0);
  return 0;
}


// ==== FUN_007cd8e0 @ 0x007cd8e0 ====

int FUN_007cd8e0(char *param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  piVar1 = (int *)FUN_007d0550(0x1a8);
  if (piVar1 != (int *)0x0) {
    piVar1[1] = (int)(piVar1 + 0x32);
    piVar1[10] = 0;
    piVar1[0xb] = 0;
    piVar1[0xc] = -0xfc486fa;
    *piVar1 = 2;
    *(undefined1 *)(piVar1 + 4) = 1;
    *(undefined1 *)((int)piVar1 + 0x11) = 1;
    piVar1[2] = piVar1[2] | 0x40;
    FUN_007d1b60(piVar1 + 0x25,3,0);
    FUN_007d1b60(piVar1 + 0x2a,3,0);
    iVar3 = 0;
    if (0 < *piVar1) {
      iVar4 = 0;
      do {
        FUN_007d1b60(piVar1[1] + 0xc + iVar4,3,0);
        FUN_007d1b60(piVar1[1] + 0x20 + iVar4,3,0);
        FUN_007d1b60(piVar1[1] + 0x34 + iVar4,3,0);
        FUN_007d1b60(piVar1[1] + 0x48 + iVar4,3,1);
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 0x70;
      } while (iVar3 < *piVar1);
    }
    iVar3 = FUN_007cd7d0(piVar1,s_BINARY_009ffdbc,1,0,&LAB_007d7060);
    if ((iVar3 == 0) &&
       (iVar3 = FUN_007cd7d0(piVar1,s_BINARY_009ffdbc,4,0,&LAB_007d7060), iVar3 == 0)) {
      iVar3 = FUN_007de2b0(piVar1,(char)piVar1[4],s_BINARY_009ffdbc,6,0);
      piVar1[6] = iVar3;
      if (iVar3 != 0) {
        FUN_007cd7d0(piVar1,s_NOCASE_009ffdb4,1,0,FUN_007cd160);
        puVar5 = (undefined4 *)(piVar1[1] + 4);
        uVar2 = 0;
        if ((piVar1[2] & 0x1000U) != 0) {
          uVar2 = 2;
        }
        if ((param_1 == (char *)0x0) && (*(char *)((int)piVar1 + 0x13) == '\x02')) {
          param_1 = s__memory__009ffce0;
        }
        iVar3 = FUN_007d6470(param_1,puVar5,uVar2);
        if (iVar3 == 0) {
          FUN_007d6620(*puVar5,piVar1 + 0x2f);
          FUN_007d6640(*puVar5,2000);
          *(undefined **)piVar1[1] = &DAT_009fe21c;
          *(undefined1 *)(piVar1[1] + 0x5f) = 3;
          *(undefined **)(piVar1[1] + 0x70) = &DAT_009ffdac;
          *(undefined1 *)(piVar1[1] + 0xcf) = 1;
          FUN_007df440(piVar1);
          FUN_007d07b0(piVar1,0,0);
          piVar1[0xc] = -0x5fd65969;
          goto LAB_007cdad2;
        }
        FUN_007d07b0(piVar1,iVar3,0);
      }
    }
    piVar1[0xc] = -0x60c3d2cd;
  }
LAB_007cdad2:
  if ((((DAT_00b5c4c4 == 0) && (iVar3 = FUN_007d0ee0(piVar1), iVar3 == 0)) && (piVar1[3] == 0)) &&
     (DAT_00b5c4c4 != 0)) {
    FUN_007d07b0(piVar1,7,0);
  }
  *param_2 = piVar1;
  if (piVar1 != (int *)0x0) {
    FUN_007d1ae0();
    piVar1[0x24] = (int)DAT_00b5c47c;
    DAT_00b5c47c = piVar1;
    FUN_007d1af0();
  }
  if (DAT_00b5c4c4 != 0) {
    return 7;
  }
  iVar4 = FUN_007d0ee0(piVar1);
  iVar3 = 0x15;
  if (iVar4 == 0) {
    iVar3 = piVar1[3];
  }
  return iVar3;
}


// ==== FUN_007cdb70 @ 0x007cdb70 ====

int FUN_007cdb70(int param_1,byte *param_2,code *param_3,undefined4 param_4,undefined4 *param_5)

{
  byte *pbVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  void *pvVar6;
  char *pcVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  byte *local_4;
  
  iVar9 = 0;
  local_18 = 0;
  local_10 = 0;
  local_8 = 0;
  if (param_2 == (byte *)0x0) {
    return 0;
  }
  while( true ) {
    while( true ) {
      while( true ) {
        iVar3 = 0;
        iVar8 = 0;
        if (((iVar9 != 0) && ((iVar9 != 0x11 || (local_10 = local_10 + 1, 1 < local_10)))) ||
           (*param_2 == 0)) goto LAB_007cdd82;
        local_18 = 0;
        iVar9 = FUN_007ceac0(param_1,param_2,0xffffffff,&local_18,&local_4);
        if (iVar9 == 0) break;
        if (local_18 != 0) {
          FUN_007cd7b0(local_18);
        }
      }
      if (local_18 != 0) break;
      param_2 = local_4;
    }
    *(int *)(param_1 + 0x34) = *(int *)(param_1 + 0x34) + local_8;
    local_14 = 0;
    iVar9 = FUN_007ce220(local_18);
    iVar3 = FUN_007d0550(iVar9 * 8);
    if ((iVar9 != 0) && (iVar3 == 0)) break;
    do {
      local_c = FUN_007ce0a0(local_18);
      if (param_3 != (code *)0x0) {
        if (local_c == 100) {
          if (local_14 == 0) goto LAB_007cdc8d;
LAB_007cdcba:
          iVar10 = 0;
          iVar8 = iVar3 + iVar9 * 4;
          if (0 < iVar9) {
            do {
              uVar4 = FUN_007ce2e0(local_18,iVar10);
              *(undefined4 *)(iVar8 + iVar10 * 4) = uVar4;
              iVar10 = iVar10 + 1;
            } while (iVar10 < iVar9);
          }
        }
        else {
          if (local_c != 0x65) goto LAB_007cdcf9;
          if ((local_14 != 0) || ((*(uint *)(param_1 + 8) & 0x100) == 0)) break;
LAB_007cdc8d:
          iVar10 = 0;
          if (0 < iVar9) {
            do {
              uVar4 = FUN_007ce300(local_18,iVar10);
              *(undefined4 *)(iVar3 + iVar10 * 4) = uVar4;
              iVar10 = iVar10 + 1;
            } while (iVar10 < iVar9);
          }
          local_14 = 1;
          if (local_c == 100) goto LAB_007cdcba;
        }
        iVar10 = (*param_3)(param_4,iVar9,iVar8,iVar3);
        if (iVar10 != 0) {
          iVar9 = 4;
          goto LAB_007cdd82;
        }
      }
LAB_007cdcf9:
    } while (local_c == 100);
    iVar9 = FUN_007cd7b0(local_18);
    pbVar1 = local_4;
    local_18 = 0;
    if (*(int *)(param_1 + 0x48) == 0) {
      local_8 = *(int *)(param_1 + 0x34);
    }
    if (iVar9 != 0x11) {
      local_10 = 0;
      iVar8 = _isspace((uint)*local_4);
      param_2 = pbVar1;
      while (iVar8 != 0) {
        pbVar1 = param_2 + 1;
        param_2 = param_2 + 1;
        iVar8 = _isspace((uint)*pbVar1);
      }
    }
    FUN_007d05b0(iVar3);
  }
  iVar9 = 7;
LAB_007cdd82:
  if (local_18 != 0) {
    FUN_007cd7b0(local_18);
  }
  if (iVar3 != 0) {
    FUN_007d05b0(iVar3);
  }
  if (DAT_00b5c4c4 == 0) {
    if (iVar9 == 0) goto LAB_007cde18;
  }
  else {
    iVar9 = 7;
  }
  iVar8 = FUN_007cd780(param_1);
  if (iVar9 == iVar8) {
    if (param_5 == (undefined4 *)0x0) {
      return iVar9;
    }
    pcVar5 = (char *)FUN_007cd730(param_1);
    pcVar7 = pcVar5 + 1;
    do {
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    pvVar6 = _malloc((size_t)(pcVar5 + (1 - (int)pcVar7)));
    *param_5 = pvVar6;
    if (pvVar6 == (void *)0x0) {
      return iVar9;
    }
    pcVar5 = (char *)FUN_007cd730(param_1);
    pcVar7 = (char *)*param_5;
    do {
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
      *pcVar7 = cVar2;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    return iVar9;
  }
LAB_007cde18:
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  return iVar9;
}


// ==== FUN_007cde30 @ 0x007cde30 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007cde30(void)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined4 local_214;
  undefined1 local_210 [524];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  local_214 = 0xf6283ef1;
  FUN_007cefb0(local_210,&local_214,4);
  puVar2 = &DAT_00b60b00;
  do {
    uVar1 = FUN_007cf130(local_210);
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0xb60d00);
  return;
}


// ==== FUN_007cdea0 @ 0x007cdea0 ====

void FUN_007cdea0(byte *param_1,int param_2,short *param_3)

{
  short sVar1;
  short sVar2;
  
  sVar2 = param_3[1];
  sVar1 = *param_3;
  if ((param_1 != (byte *)0x0) && (param_2 != 0)) {
    do {
      sVar1 = sVar1 + (&DAT_00b60b00)[*param_1];
      param_1 = param_1 + 1;
      sVar2 = sVar2 + sVar1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    *param_3 = sVar1;
    param_3[1] = sVar2;
  }
  return;
}


// ==== FUN_007cdf00 @ 0x007cdf00 ====

void FUN_007cdf00(undefined4 param_1)

{
  FUN_007d0350(param_1,1);
  return;
}


// ==== FUN_007cdf10 @ 0x007cdf10 ====

void FUN_007cdf10(undefined4 param_1)

{
  FUN_007d0350(param_1,(DAT_009ff8b0 == '\0') + '\x02');
  return;
}


// ==== FUN_007cdf50 @ 0x007cdf50 ====

void FUN_007cdf50(undefined4 param_1)

{
  FUN_007d0100(param_1,1);
  return;
}


// ==== FUN_007cdf60 @ 0x007cdf60 ====

void FUN_007cdf60(undefined4 param_1)

{
  FUN_007d0100(param_1,(DAT_009ff8b0 == '\0') + '\x02');
  return;
}


// ==== FUN_007cdf80 @ 0x007cdf80 ====

undefined1 FUN_007cdf80(int param_1)

{
  return *(undefined1 *)(param_1 + 0xe);
}


// ==== FUN_007cdf90 @ 0x007cdf90 ====

void FUN_007cdf90(int param_1,undefined8 param_2)

{
  FUN_007cfa90(param_1 + 8,param_2);
  return;
}


// ==== FUN_007cdfb0 @ 0x007cdfb0 ====

void FUN_007cdfb0(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined1 *)(param_1 + 0x4c) = 1;
  FUN_007cfbe0(param_1 + 8,param_2,param_3,1,0xffffffff);
  return;
}


// ==== FUN_007cdfe0 @ 0x007cdfe0 ====

void FUN_007cdfe0(int param_1,int param_2)

{
  FUN_007cfa40(param_1 + 8,param_2,param_2 >> 0x1f);
  return;
}


// ==== FUN_007ce000 @ 0x007ce000 ====

void FUN_007ce000(int param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_007cfa40(param_1 + 8,param_2,param_3);
  return;
}


// ==== FUN_007ce020 @ 0x007ce020 ====

void FUN_007ce020(void)

{
  FUN_007cfa00();
  return;
}


// ==== FUN_007ce030 @ 0x007ce030 ====

void FUN_007ce030(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_007cfbe0(param_1 + 8,param_2,param_3,1,param_4);
  return;
}


// ==== FUN_007ce060 @ 0x007ce060 ====

void FUN_007ce060(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_007cfbe0(param_1 + 8,param_2,param_3,(DAT_009ff8b0 == '\0') + '\x02',param_4);
  return;
}


// ==== FUN_007ce090 @ 0x007ce090 ====

void FUN_007ce090(void)

{
  FUN_007cfb20();
  return;
}


// ==== FUN_007ce0a0 @ 0x007ce0a0 ====

undefined4 FUN_007ce0a0(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((param_1 == (int *)0x0) || (param_1[0x16] != -0x420df25d)) {
    return 0x15;
  }
  if (*(char *)((int)param_1 + 0x23f) != '\0') {
    return 4;
  }
  if ((param_1[0x21] < 1) && ((char)param_1[0x90] != '\0')) {
    if (param_1[0x22] == 0) {
      param_1[0x22] = 0x11;
    }
    return 1;
  }
  iVar3 = *param_1;
  iVar1 = FUN_007d0e60(iVar3);
  if (iVar1 != 0) {
LAB_007ce10a:
    param_1[0x22] = 0x15;
    return 0x15;
  }
  if (param_1[0x21] < 0) {
    iVar3 = *param_1;
    if ((*(int *)(iVar3 + 0x50) != 0) && (*(char *)(iVar3 + 0x44) == '\0')) {
      FUN_007d0ea0(iVar3);
      (**(code **)(iVar3 + 0x50))
                (*(undefined4 *)(iVar3 + 0x54),*(undefined4 *)(param_1[6] + -8 + param_1[4] * 0x14))
      ;
      iVar1 = FUN_007d0e60(iVar3);
      if (iVar1 != 0) goto LAB_007ce10a;
    }
    *(int *)(iVar3 + 0x4c) = *(int *)(iVar3 + 0x4c) + 1;
    param_1[0x21] = 0;
  }
  if (*(char *)((int)param_1 + 0x23d) == '\0') {
    uVar2 = FUN_007df870(param_1);
  }
  else {
    uVar2 = FUN_007dc7f0();
  }
  iVar3 = FUN_007d0ea0(iVar3);
  if (iVar3 != 0) {
    uVar2 = 0x15;
  }
  FUN_007d07b0(*param_1,uVar2,param_1[0x8e]);
  return uVar2;
}


// ==== FUN_007ce1c0 @ 0x007ce1c0 ====

undefined4 FUN_007ce1c0(int *param_1)

{
  return *(undefined4 *)(*param_1 + 0xc);
}


// ==== FUN_007ce1d0 @ 0x007ce1d0 ====

undefined4 FUN_007ce1d0(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (*(int *)(param_1 + 0x48) == 0) {
    if ((int)param_2 < 0x21) {
      *(undefined4 **)(param_1 + 0x48) = *(undefined4 **)(param_1 + 0x20);
      puVar3 = *(undefined4 **)(param_1 + 0x20);
      for (uVar2 = param_2 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      for (param_2 = param_2 & 3; param_2 != 0; param_2 = param_2 - 1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
      return *(undefined4 *)(param_1 + 0x48);
    }
    uVar1 = FUN_007d0550(param_2);
    *(undefined4 *)(param_1 + 0x48) = uVar1;
  }
  return *(undefined4 *)(param_1 + 0x48);
}


// ==== FUN_007ce220 @ 0x007ce220 ====

undefined4 FUN_007ce220(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x22c);
}


// ==== FUN_007ce240 @ 0x007ce240 ====

undefined * FUN_007ce240(void)

{
  int in_EAX;
  undefined4 *in_ECX;
  int iVar1;
  
  if ((in_ECX == (undefined4 *)0x0) || (*(char *)(in_ECX + 0x8f) == '\0')) {
    iVar1 = 0;
  }
  else {
    iVar1 = in_ECX[0x8b];
  }
  if ((in_EAX < iVar1) && (-1 < in_EAX)) {
    return (undefined *)(((in_EAX - iVar1) + 1) * 0x40 + in_ECX[0xb]);
  }
  if (DAT_00b5c48c == 0) {
    DAT_00b5c48c = 1;
  }
  FUN_007d07b0(*in_ECX,0x19,0);
  return &DAT_00b5c480;
}


// ==== FUN_007ce2a0 @ 0x007ce2a0 ====

void FUN_007ce2a0(void)

{
  FUN_007ce240();
  FUN_007d0350();
  return;
}


// ==== FUN_007ce2c0 @ 0x007ce2c0 ====

void FUN_007ce2c0(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_007ce240();
  FUN_007cff80(uVar1);
  return;
}


// ==== FUN_007ce2e0 @ 0x007ce2e0 ====

void FUN_007ce2e0(void)

{
  FUN_007ce240();
  FUN_007d0100();
  return;
}


// ==== FUN_007ce300 @ 0x007ce300 ====

undefined4 FUN_007ce300(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (((param_1 == 0) || (*(int *)(param_1 + 0x22c) <= param_2)) || (param_2 < 0)) {
    return 0;
  }
  uVar1 = FUN_007d0100();
  return uVar1;
}


// ==== FUN_007ce340 @ 0x007ce340 ====

undefined4 FUN_007ce340(void)

{
  int iVar1;
  int in_EAX;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI != (undefined4 *)0x0) {
    if ((unaff_ESI[0x16] == -0x420df25d) && ((int)unaff_ESI[0x21] < 0)) {
      if ((in_EAX < 1) || ((int)unaff_ESI[0x12] < in_EAX)) {
        FUN_007d07b0(*unaff_ESI,0x19,0);
        return 0x19;
      }
      iVar1 = unaff_ESI[0x13] + -0x40 + in_EAX * 0x40;
      FUN_007cf9b0(iVar1);
      *(undefined2 *)(iVar1 + 0xc) = 1;
      FUN_007d07b0(*unaff_ESI,0,0);
      return 0;
    }
    FUN_007d07b0(*unaff_ESI,0x15,0);
  }
  return 0x15;
}


// ==== FUN_007ce3c0 @ 0x007ce3c0 ====

void FUN_007ce3c0(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  
  iVar1 = FUN_007ce340();
  if ((iVar1 == 0) && (param_3 != 0)) {
    FUN_007cfbe0(*(int *)(param_1 + 0x4c) + -0x40 + param_2 * 0x40,param_3,param_4,0,param_5);
  }
  return;
}


// ==== FUN_007ce400 @ 0x007ce400 ====

undefined4 FUN_007ce400(int param_1)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_1 + 0xc) & 0x12) == 0) {
    uVar1 = FUN_007d0100(param_1,1);
    return uVar1;
  }
  return *(undefined4 *)(param_1 + 0x18);
}


// ==== FUN_007ce420 @ 0x007ce420 ====

undefined4 FUN_007ce420(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_007ce240();
  if ((*(byte *)(iVar1 + 0xc) & 0x12) == 0) {
    uVar2 = FUN_007d0100();
    return uVar2;
  }
  return *(undefined4 *)(iVar1 + 0x18);
}


// ==== FUN_007ce450 @ 0x007ce450 ====

void FUN_007ce450(int param_1)

{
  undefined *puVar1;
  char *in_ECX;
  
  if (DAT_00b5c4c4 == 0) {
    if ((in_ECX == (char *)0x0) || (*in_ECX == '\0')) {
      puVar1 = (undefined *)0x0;
    }
    else {
      puVar1 = &DAT_009ffec0;
    }
    FUN_007d0700(*(undefined4 *)(param_1 + 4),s_malformed_database_schema_009ffea4,puVar1);
  }
  return;
}


// ==== FUN_007ce490 @ 0x007ce490 ====

int FUN_007ce490(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  long lVar3;
  int iVar4;
  int iVar5;
  
  puVar2 = param_3;
  piVar1 = param_1;
  iVar5 = *param_1;
  if (param_3 != (undefined4 *)0x0) {
    if ((param_3[1] == 0) || ((char *)param_3[3] == (char *)0x0)) {
      if (DAT_00b5c4c4 == 0) {
        FUN_007d0700(param_1[1],s_malformed_database_schema_009ffea4,0,0,0);
      }
      return 1;
    }
    lVar3 = _atol((char *)param_3[3]);
    if (((char *)puVar2[2] == (char *)0x0) || (*(char *)puVar2[2] == '\0')) {
      iVar5 = FUN_007d23d0(iVar5,*puVar2,*(undefined4 *)(lVar3 * 0x70 + *(int *)(iVar5 + 4)));
      if ((iVar5 != 0) && (*(int *)(iVar5 + 0x10) == 0)) {
        lVar3 = _atol((char *)puVar2[1]);
        *(long *)(iVar5 + 0x10) = lVar3;
      }
    }
    else {
      *(long *)(iVar5 + 0x3c) = lVar3;
      lVar3 = _atol((char *)puVar2[1]);
      *(long *)(iVar5 + 0x40) = lVar3;
      iVar4 = FUN_007cdb70(iVar5,puVar2[2],0,0,&param_1);
      *(undefined4 *)(iVar5 + 0x3c) = 0;
      if (iVar4 != 0) {
        FUN_007ce450(piVar1);
        _free(param_1);
        return iVar4;
      }
    }
  }
  return 0;
}


// ==== FUN_007ce580 @ 0x007ce580 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007ce580(int param_1,undefined4 param_2)

{
  byte *pbVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  int unaff_ESI;
  undefined4 local_74;
  char *local_70;
  undefined4 local_6c;
  undefined4 local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  char *local_38;
  undefined *local_34;
  char *local_30;
  char *local_2c;
  undefined4 local_28;
  char local_24 [32];
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  if (param_1 == 1) {
    pcVar6 = s_CREATE_TEMP_TABLE_sqlite_temp_ma_009ffe30;
    local_70 = s_sqlite_temp_master_009fff68;
  }
  else {
    pcVar6 = s_CREATE_TABLE_sqlite_master__type_009ffdc8;
    local_70 = s_sqlite_master_009fff58;
  }
  FUN_007d0ea0();
  local_38 = local_70;
  local_34 = &DAT_009fee70;
  local_30 = pcVar6;
  _sprintf(local_24,&DAT_009fff54,param_1);
  local_2c = local_24;
  local_28 = 0;
  iVar3 = FUN_007ce490(local_24 + -0x44,4,&local_38,0);
  if (iVar3 != 0) {
    FUN_007d0e60();
    return iVar3;
  }
  iVar7 = param_1 * 0x70;
  iVar3 = FUN_007d22b0();
  if (iVar3 != 0) {
    *(undefined1 *)(iVar3 + 0x1c) = 1;
  }
  FUN_007d0e60();
  iVar3 = *(int *)(*(int *)(unaff_ESI + 4) + 4 + iVar7);
  if (iVar3 == 0) {
    if (param_1 == 1) {
      pbVar1 = (byte *)(*(int *)(unaff_ESI + 4) + 0xcc);
      *pbVar1 = *pbVar1 | 1;
    }
    return 0;
  }
  iVar3 = FUN_007db700(iVar3,1,0,0,0,&local_74);
  if (iVar3 == 0) {
    local_6c = &local_60;
    uVar5 = 0;
    iVar3 = 0;
    do {
      if (9 < uVar5) {
        bVar2 = false;
        if (iVar3 == 0) goto LAB_007ce789;
        break;
      }
      uVar5 = uVar5 + 1;
      iVar3 = FUN_007da670(*(undefined4 *)(*(int *)(unaff_ESI + 4) + 4 + iVar7),uVar5,local_6c);
      local_6c = local_6c + 1;
    } while (iVar3 == 0);
    uVar4 = FUN_007cd3a0(iVar3,0);
    FUN_007d0700(param_2,uVar4);
    FUN_007d70a0(local_74);
    return iVar3;
  }
  if (iVar3 != 0x10) {
    uVar4 = FUN_007cd3a0(iVar3,0);
    FUN_007d0700(param_2,uVar4);
    return iVar3;
  }
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  bVar2 = true;
LAB_007ce789:
  *(undefined4 *)(*(int *)(unaff_ESI + 4) + 8 + iVar7) = local_60;
  if (local_50 != 0) {
    if (param_1 == 0) {
      *(char *)(unaff_ESI + 0x10) = (char)local_50;
      uVar4 = FUN_007de2b0();
      *(undefined4 *)(unaff_ESI + 0x18) = uVar4;
    }
    else if (local_50 != *(byte *)(unaff_ESI + 0x10)) {
      FUN_007d70a0(local_74);
      pcVar6 = s_attached_databases_must_use_the_s_009ffef8;
      goto LAB_007ce81f;
    }
  }
  iVar3 = local_58;
  if (local_58 == 0) {
    iVar3 = 2000;
  }
  *(int *)(*(int *)(unaff_ESI + 4) + 0x60 + iVar7) = iVar3;
  if (param_1 == 0) {
    *(char *)(unaff_ESI + 0x12) = (char)local_5c;
    if ((char)local_5c == '\0') {
      *(undefined1 *)(unaff_ESI + 0x12) = 1;
    }
    if ((*(char *)(unaff_ESI + 0x12) == '\x02') || (*(char *)(unaff_ESI + 0x12) == '\x03')) {
      *(undefined1 *)(unaff_ESI + 0x12) = 1;
    }
  }
  if (local_5c < 4) {
    FUN_007d6640(*(undefined4 *)(*(int *)(unaff_ESI + 4) + iVar7 + 4),
                 *(undefined4 *)(*(int *)(unaff_ESI + 4) + 0x60 + iVar7));
    if (bVar2) {
      iVar3 = 0;
    }
    else {
      uVar4 = FUN_007e4830(s_SELECT_name__rootpage__sql____s__009ffec4,local_24,
                           *(undefined4 *)(*(int *)(unaff_ESI + 4) + iVar7),local_70);
      FUN_007d0ea0();
      iVar3 = FUN_007cdb70();
      FUN_007d0e60();
      FUN_007d05b0(uVar4);
      FUN_007d70a0(local_74);
    }
    if (DAT_00b5c4c4 == 0) {
      if (iVar3 == 0) {
        pbVar1 = (byte *)(*(int *)(unaff_ESI + 4) + 0x5c + iVar7);
        *pbVar1 = *pbVar1 | 1;
        return 0;
      }
    }
    else {
      FUN_007d0700(param_2,s_out_of_memory_009ffbcc,0);
      iVar3 = 7;
      FUN_007d3fc0();
    }
    FUN_007d3fc0();
    return iVar3;
  }
  FUN_007d70a0(local_74);
  pcVar6 = s_unsupported_file_format_009fff3c;
LAB_007ce81f:
  FUN_007d0700(param_2,pcVar6,0);
  return 1;
}


// ==== FUN_007ce930 @ 0x007ce930 ====

int FUN_007ce930(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((char)param_1[0x11] != '\0') {
    return 0;
  }
  iVar3 = 0;
  iVar2 = 0;
  *(undefined1 *)(param_1 + 0x11) = 1;
  iVar1 = 0;
  do {
    if (*param_1 <= iVar2) {
      if ((((iVar3 == 0) && (1 < *param_1)) && ((*(byte *)(param_1[1] + 0xcc) & 1) == 0)) &&
         (iVar3 = FUN_007ce580(1,param_2), iVar3 != 0)) {
        FUN_007d3fc0(param_1,1);
      }
      break;
    }
    if ((((*(byte *)(param_1[1] + 0x5c + iVar1) & 1) == 0) && (iVar1 != 0x70)) &&
       (iVar3 = FUN_007ce580(iVar2,param_2), iVar3 != 0)) {
      FUN_007d3fc0(param_1,iVar2);
    }
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0x70;
  } while (iVar3 == 0);
  *(undefined1 *)(param_1 + 0x11) = 0;
  if (iVar3 == 0) {
    param_1[2] = param_1[2] | 2;
    FUN_007d2570(param_1);
    return 0;
  }
  param_1[2] = param_1[2] & 0xfffffffd;
  return iVar3;
}


// ==== FUN_007ce9f0 @ 0x007ce9f0 ====

int FUN_007ce9f0(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  iVar2 = 0;
  if ((*(char *)(iVar1 + 0x44) == '\0') && ((*(byte *)(iVar1 + 8) & 2) == 0)) {
    iVar2 = FUN_007ce930(iVar1,param_1 + 2);
    if (iVar2 != 0) {
      param_1[1] = iVar2;
      param_1[6] = param_1[6] + 1;
    }
  }
  return iVar2;
}


// ==== FUN_007cea30 @ 0x007cea30 ====

int FUN_007cea30(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_8;
  undefined4 local_4;
  
  iVar4 = 0;
  iVar3 = 1;
  iVar5 = 0;
  do {
    if (*param_1 <= iVar4) {
      return iVar3;
    }
    iVar2 = *(int *)(param_1[1] + 4 + iVar5);
    if ((iVar2 != 0) && (iVar1 = FUN_007db700(iVar2,1,0,0,0,&local_4), iVar1 == 0)) {
      iVar2 = FUN_007da670(iVar2,1,&local_8);
      if ((iVar2 == 0) && (local_8 != *(int *)(param_1[1] + 8 + iVar5))) {
        iVar3 = 0;
      }
      FUN_007d70a0(local_4);
    }
    iVar4 = iVar4 + 1;
    iVar5 = iVar5 + 0x70;
  } while (iVar3 != 0);
  return 0;
}


// ==== FUN_007ceac0 @ 0x007ceac0 ====

int FUN_007ceac0(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,undefined4 *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_c4;
  int local_c0 [4];
  char local_ae;
  char local_4c;
  undefined4 local_2c;
  
  local_c4 = 0;
  if (DAT_00b5c4c4 != 0) {
    return 7;
  }
  *param_4 = 0;
  iVar1 = FUN_007d0e60(param_1);
  if (iVar1 != 0) {
    return 0x15;
  }
  piVar3 = local_c0;
  for (iVar1 = 0x2d; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = 0;
    piVar3 = piVar3 + 1;
  }
  local_c0[0] = param_1;
  FUN_007e50b0(local_c0,param_2,&local_c4);
  if (DAT_00b5c4c4 == 0) {
    if (local_c0[1] == 0x65) {
      local_c0[1] = 0;
    }
    else {
      if (((local_c0[1] == 0) || (local_ae == '\0')) || (iVar1 = FUN_007cea30(param_1), iVar1 != 0))
      {
        if (local_c0[1] != 0x11) goto LAB_007cebb1;
      }
      else {
        local_c0[1] = 0x11;
      }
      FUN_007d3fc0(param_1,0);
    }
LAB_007cebb1:
    iVar1 = local_c0[1];
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = local_2c;
    }
    if (((local_c0[1] == 0) && (local_c0[3] != 0)) && (local_4c != '\0')) {
      FUN_007dccf0(local_c0[3],5);
      FUN_007dcd30(local_c0[3],0,&DAT_009fff90,0xfffffffe);
      FUN_007dcd30(local_c0[3],1,s_opcode_009fff88,0xfffffffe);
      FUN_007dcd30(local_c0[3],2,&DAT_009fff84,0xfffffffe);
      FUN_007dcd30(local_c0[3],3,&DAT_009fff80,0xfffffffe);
      FUN_007dcd30(local_c0[3],4,&DAT_009fff7c,0xfffffffe);
    }
  }
  else {
    iVar1 = 7;
    FUN_007cd350(param_1);
    FUN_007d3fc0(param_1,0);
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffff7;
  }
  iVar2 = FUN_007d0ea0(param_1);
  if (iVar2 == 0) {
    if (iVar1 == 0) {
      *param_4 = local_c0[3];
      goto LAB_007cec69;
    }
  }
  else {
    iVar1 = 0x15;
  }
  if (local_c0[3] != 0) {
    FUN_007cd7b0(local_c0[3]);
  }
LAB_007cec69:
  if (local_c4 == 0) {
    FUN_007d07b0(param_1,iVar1,0);
    return iVar1;
  }
  FUN_007d07b0(param_1,iVar1,&DAT_009d5e14,local_c4);
  FUN_007d05b0(local_c4);
  return iVar1;
}


// ==== FUN_007cecc0 @ 0x007cecc0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_007cecc0(void)

{
  int iVar1;
  bool bVar2;
  WSADATA local_194;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  iVar1 = DAT_00b5c4c0 + 1;
  bVar2 = DAT_00b5c4c0 == 0;
  DAT_00b5c4c0 = iVar1;
  if (bVar2) {
    WSAStartup(2,&local_194);
  }
  return;
}


// ==== FUN_007ced10 @ 0x007ced10 ====

void FUN_007ced10(void)

{
  DAT_00b5c4c0 = DAT_00b5c4c0 + -1;
  if (DAT_00b5c4c0 == 0) {
                    /* WARNING: Could not recover jumptable at 0x007ced18. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    WSACleanup();
    return;
  }
  return;
}


// ==== FUN_007ced20 @ 0x007ced20 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

SOCKET FUN_007ced20(char *param_1,u_short param_2)

{
  u_short uVar1;
  SOCKET s;
  int iVar2;
  hostent *phVar3;
  char local_18 [4];
  sockaddr local_14;
  undefined4 local_4;
  
  local_4 = DAT_00b49670;
  local_18[0] = '\x01';
  local_18[1] = '\0';
  local_18[2] = '\0';
  local_18[3] = '\0';
  s = socket(2,1,0);
  if (s == 0xffffffff) {
    return 0xffffffff;
  }
  iVar2 = setsockopt(s,0xffff,4,local_18,4);
  if (iVar2 != -1) {
    iVar2 = setsockopt(s,0xffff,-0x81,local_18,4);
    if (iVar2 != -1) {
      iVar2 = setsockopt(s,6,1,local_18,4);
      if (iVar2 != -1) {
        local_14.sa_data[2] = '\0';
        local_14.sa_data[3] = '\0';
        local_14.sa_data[4] = '\0';
        local_14.sa_data[5] = '\0';
        local_14.sa_data[6] = '\0';
        local_14.sa_data[7] = '\0';
        local_14.sa_data[8] = '\0';
        local_14.sa_data[9] = '\0';
        local_14.sa_data[10] = '\0';
        local_14.sa_data[0xb] = '\0';
        local_14.sa_data[0xc] = '\0';
        local_14.sa_data[0xd] = '\0';
        local_14.sa_family = 2;
        local_14.sa_data[0] = '\0';
        local_14.sa_data[1] = '\0';
        local_14.sa_data._2_4_ = inet_addr(param_1);
        if (local_14.sa_data._2_4_ == 0xffffffff) {
          phVar3 = gethostbyname(param_1);
          if ((phVar3 == (hostent *)0x0) || (phVar3->h_addr_list == (char **)0x0)) {
            return 0xfffffffe;
          }
          local_14.sa_data._2_4_ = *(undefined4 *)*phVar3->h_addr_list;
        }
        uVar1 = htons(param_2);
        local_14.sa_data[0] = (char)uVar1;
        local_14.sa_data[1] = (char)(uVar1 >> 8);
        iVar2 = connect(s,&local_14,0x10);
        if (iVar2 != -1) {
          return s;
        }
      }
    }
  }
  return 0xffffffff;
}


// ==== FUN_007cee50 @ 0x007cee50 ====

SOCKET FUN_007cee50(SOCKET param_1)

{
  if ((int)param_1 < 0) {
    return param_1;
  }
  shutdown(param_1,2);
  closesocket(param_1);
  return 0xffffffff;
}


// ==== FUN_007cee80 @ 0x007cee80 ====

void FUN_007cee80(SOCKET param_1,char *param_2,int param_3)

{
  send(param_1,param_2,param_3,0);
  return;
}


// ==== FUN_007ceea0 @ 0x007ceea0 ====

void FUN_007ceea0(void)

{
  FUN_007e5fc0(&DAT_00b60ad0,0x21);
  FUN_007e5fc0(&DAT_00b60ae0,0x21);
  FUN_007e5f50(&DAT_00b60ae0,&DAT_00b491a4,0x80);
  FUN_007e5f50(&DAT_00b60ad0,&DAT_00b49224,0x80);
  FUN_007e5f10(&DAT_00b60ae0);
  FUN_007e5f10(&DAT_00b60ad0);
  return;
}


// ==== FUN_007cef00 @ 0x007cef00 ====

undefined4 FUN_007cef00(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  FUN_007e5fc0(local_10,0x21);
  FUN_007e5fc0(local_20,0x21);
  FUN_007e5f50(local_20,param_3,param_4);
  iVar1 = FUN_007e6310(local_20,&DAT_00b60ae0);
  if (-1 < iVar1) {
    return 0xffffffff;
  }
  iVar1 = FUN_007e61b0(local_20,&DAT_00b60ad0,&DAT_00b60ae0,local_10);
  if (iVar1 == 0) {
    uVar2 = DAT_00b491a0 + 7U >> 3;
    *param_2 = uVar2;
    FUN_007e6100(local_10,param_1,uVar2);
    FUN_007e6040(local_20,local_10,0);
  }
  return 0;
}


// ==== FUN_007cefb0 @ 0x007cefb0 ====

void FUN_007cefb0(int param_1,int param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  uint uVar3;
  
  *(undefined4 *)(param_1 + 0x200) = 0;
  do {
    *(char *)(param_1 + *(int *)(param_1 + 0x200)) = (char)*(int *)(param_1 + 0x200);
    *(undefined1 *)(*(int *)(param_1 + 0x200) + 0x100 + param_1) =
         *(undefined1 *)(*(int *)(param_1 + 0x200) % param_3 + param_2);
    iVar2 = *(int *)(param_1 + 0x200) + 1;
    *(int *)(param_1 + 0x200) = iVar2;
  } while (iVar2 < 0x100);
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  do {
    pbVar1 = (byte *)(param_1 + *(int *)(param_1 + 0x200));
    uVar3 = (uint)pbVar1[0x100] + (uint)*(byte *)(param_1 + *(int *)(param_1 + 0x200)) +
            *(int *)(param_1 + 0x204) & 0x800000ff;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xffffff00) + 1;
    }
    *(uint *)(param_1 + 0x204) = uVar3;
    *(uint *)(param_1 + 0x208) = (uint)*pbVar1;
    *pbVar1 = *(byte *)(param_1 + *(int *)(param_1 + 0x204));
    *(undefined1 *)(param_1 + *(int *)(param_1 + 0x204)) = *(undefined1 *)(param_1 + 0x208);
    iVar2 = *(int *)(param_1 + 0x200) + 1;
    *(int *)(param_1 + 0x200) = iVar2;
  } while (iVar2 < 0x100);
  *(undefined4 *)(param_1 + 0x204) = 0;
  *(undefined4 *)(param_1 + 0x200) = 0;
  return;
}


// ==== FUN_007cf090 @ 0x007cf090 ====

/* WARNING: Removing unreachable block (ram,0x007cf117) */

undefined1 FUN_007cf090(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(int *)(param_1 + 0x200) + 1U & 0x800000ff;
  if ((int)uVar1 < 0) {
    uVar1 = (uVar1 - 1 | 0xffffff00) + 1;
  }
  *(uint *)(param_1 + 0x200) = uVar1;
  uVar2 = (uint)*(byte *)(uVar1 + param_1) + *(int *)(param_1 + 0x204) & 0x800000ff;
  if ((int)uVar2 < 0) {
    uVar2 = (uVar2 - 1 | 0xffffff00) + 1;
  }
  *(uint *)(param_1 + 0x204) = uVar2;
  *(uint *)(param_1 + 0x208) = (uint)*(byte *)(uVar1 + param_1);
  *(undefined1 *)(uVar1 + param_1) = *(undefined1 *)(param_1 + *(int *)(param_1 + 0x204));
  *(undefined1 *)(param_1 + *(int *)(param_1 + 0x204)) = *(undefined1 *)(param_1 + 0x208);
  uVar1 = (uint)*(byte *)(*(int *)(param_1 + 0x204) + param_1) +
          (uint)*(byte *)(param_1 + *(int *)(param_1 + 0x200)) & 0x800000ff;
  *(uint *)(param_1 + 0x208) = uVar1;
  return *(undefined1 *)(uVar1 + param_1);
}


// ==== FUN_007cf130 @ 0x007cf130 ====

undefined2 FUN_007cf130(undefined4 param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  
  uVar1 = FUN_007cf090(param_1);
  uVar2 = FUN_007cf090(param_1);
  return CONCAT11(uVar1,uVar2);
}


// ==== FUN_007cf160 @ 0x007cf160 ====

/* WARNING: Removing unreachable block (ram,0x007cf202) */

void FUN_007cf160(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (0 < param_3) {
    do {
      uVar1 = *(int *)(param_1 + 0x200) + 1U & 0x800000ff;
      if ((int)uVar1 < 0) {
        uVar1 = (uVar1 - 1 | 0xffffff00) + 1;
      }
      *(uint *)(param_1 + 0x200) = uVar1;
      uVar2 = (uint)*(byte *)(uVar1 + param_1) + *(int *)(param_1 + 0x204) & 0x800000ff;
      if ((int)uVar2 < 0) {
        uVar2 = (uVar2 - 1 | 0xffffff00) + 1;
      }
      *(uint *)(param_1 + 0x204) = uVar2;
      *(uint *)(param_1 + 0x208) = (uint)*(byte *)(uVar1 + param_1);
      *(undefined1 *)(uVar1 + param_1) = *(undefined1 *)(param_1 + *(int *)(param_1 + 0x204));
      *(undefined1 *)(param_1 + *(int *)(param_1 + 0x204)) = *(undefined1 *)(param_1 + 0x208);
      uVar1 = (uint)*(byte *)(*(int *)(param_1 + 0x204) + param_1) +
              (uint)*(byte *)(*(int *)(param_1 + 0x200) + param_1) & 0x800000ff;
      *(uint *)(param_1 + 0x208) = uVar1;
      *(byte *)(iVar3 + param_2) = *(byte *)(iVar3 + param_2) ^ *(byte *)(uVar1 + param_1);
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3);
  }
  return;
}


// ==== FUN_007cf230 @ 0x007cf230 ====

int FUN_007cf230(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 8);
  uVar2 = *(uint *)(param_1 + 0xc);
  if (uVar1 == uVar2) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    return 0;
  }
  if (uVar2 < uVar1) {
    return uVar1 - uVar2;
  }
  return (*(int *)(param_1 + 4) - uVar2) + uVar1;
}


// ==== FUN_007cf260 @ 0x007cf260 ====

int FUN_007cf260(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(param_1 + 8);
  uVar2 = *(uint *)(param_1 + 0xc);
  if (uVar1 == uVar2) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    return *(int *)(param_1 + 4) + -1;
  }
  if (uVar2 < uVar1) {
    return (*(int *)(param_1 + 4) - uVar1) + -1;
  }
  return uVar2 - uVar1;
}


// ==== FUN_007cf290 @ 0x007cf290 ====

uint FUN_007cf290(int *param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (0 < (int)param_3) {
    uVar1 = param_1[2];
    uVar3 = param_1[3];
    if (uVar1 == uVar3) {
      iVar4 = 0;
      param_1[3] = 0;
      param_1[2] = 0;
    }
    else if (uVar3 < uVar1) {
      iVar4 = uVar1 - uVar3;
    }
    else {
      iVar4 = (param_1[1] - uVar3) + uVar1;
    }
    uVar1 = param_1[1];
    if ((int)param_3 <= (int)(uVar1 - iVar4)) {
      iVar4 = param_1[2];
      if (iVar4 + param_3 <= uVar1) {
        if (param_2 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)(*param_1 + iVar4);
          for (uVar1 = param_3 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar5 = *param_2;
            param_2 = param_2 + 1;
            puVar5 = puVar5 + 1;
          }
          for (uVar1 = param_3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
            *(undefined1 *)puVar5 = *(undefined1 *)param_2;
            param_2 = (undefined4 *)((int)param_2 + 1);
            puVar5 = (undefined4 *)((int)puVar5 + 1);
          }
        }
        param_1[2] = param_1[2] + param_3;
        return param_3;
      }
      uVar1 = uVar1 - iVar4;
      uVar3 = param_3 - uVar1;
      if (param_2 != (undefined4 *)0x0) {
        puVar5 = param_2;
        puVar6 = (undefined4 *)(*param_1 + iVar4);
        for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar2 = uVar1 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        puVar5 = (undefined4 *)((int)param_2 + uVar1);
        puVar6 = (undefined4 *)*param_1;
        for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar1 = uVar3 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
      }
      param_1[2] = uVar3;
      return param_3;
    }
  }
  return 0;
}


// ==== FUN_007cf350 @ 0x007cf350 ====

uint FUN_007cf350(int *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  if (0 < (int)param_3) {
    uVar2 = param_1[2];
    uVar4 = param_1[3];
    if (uVar2 == uVar4) {
      iVar1 = 0;
      param_1[3] = 0;
      param_1[2] = 0;
    }
    else if (uVar4 < uVar2) {
      iVar1 = uVar2 - uVar4;
    }
    else {
      iVar1 = (param_1[1] - uVar4) + uVar2;
    }
    if ((int)param_3 <= iVar1) {
      iVar1 = param_1[3];
      if (iVar1 + param_3 <= (uint)param_1[1]) {
        if (param_2 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)(*param_1 + iVar1);
          for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *param_2 = *puVar5;
            puVar5 = puVar5 + 1;
            param_2 = param_2 + 1;
          }
          for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *(undefined1 *)param_2 = *(undefined1 *)puVar5;
            puVar5 = (undefined4 *)((int)puVar5 + 1);
            param_2 = (undefined4 *)((int)param_2 + 1);
          }
        }
        param_1[3] = param_1[3] + param_3;
        return param_3;
      }
      uVar2 = param_1[1] - iVar1;
      uVar4 = param_3 - uVar2;
      if (param_2 != (undefined4 *)0x0) {
        puVar5 = (undefined4 *)(*param_1 + iVar1);
        puVar6 = param_2;
        for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
        puVar5 = (undefined4 *)*param_1;
        puVar6 = (undefined4 *)((int)param_2 + uVar2);
        for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        for (uVar2 = uVar4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)puVar6 = *(undefined1 *)puVar5;
          puVar5 = (undefined4 *)((int)puVar5 + 1);
          puVar6 = (undefined4 *)((int)puVar6 + 1);
        }
      }
      param_1[3] = uVar4;
      return param_3;
    }
  }
  return 0;
}


// ==== FUN_007cf420 @ 0x007cf420 ====

uint FUN_007cf420(int *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if (0 < (int)param_3) {
    uVar2 = param_1[2];
    uVar3 = param_1[3];
    if (uVar2 == uVar3) {
      iVar1 = 0;
      param_1[3] = 0;
      param_1[2] = 0;
    }
    else if (uVar3 < uVar2) {
      iVar1 = uVar2 - uVar3;
    }
    else {
      iVar1 = (param_1[1] - uVar3) + uVar2;
    }
    if ((int)param_3 <= iVar1) {
      iVar1 = param_1[3];
      if ((uint)param_1[1] < param_3 + iVar1) {
        uVar2 = param_1[1] - iVar1;
        if (param_2 != (undefined4 *)0x0) {
          puVar4 = (undefined4 *)(*param_1 + iVar1);
          puVar5 = param_2;
          for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          for (uVar3 = uVar2 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
            puVar4 = (undefined4 *)((int)puVar4 + 1);
            puVar5 = (undefined4 *)((int)puVar5 + 1);
          }
          puVar4 = (undefined4 *)*param_1;
          puVar5 = (undefined4 *)(uVar2 + (int)param_2);
          for (uVar3 = param_3 - uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          for (uVar2 = param_3 - uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
            puVar4 = (undefined4 *)((int)puVar4 + 1);
            puVar5 = (undefined4 *)((int)puVar5 + 1);
          }
          return param_3;
        }
      }
      else if (param_2 != (undefined4 *)0x0) {
        puVar4 = (undefined4 *)(*param_1 + iVar1);
        for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
          *param_2 = *puVar4;
          puVar4 = puVar4 + 1;
          param_2 = param_2 + 1;
        }
        for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
          *(undefined1 *)param_2 = *(undefined1 *)puVar4;
          puVar4 = (undefined4 *)((int)puVar4 + 1);
          param_2 = (undefined4 *)((int)param_2 + 1);
        }
      }
      return param_3;
    }
  }
  return 0;
}


// ==== FUN_007cf4e0 @ 0x007cf4e0 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

int FUN_007cf4e0(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined1 local_404 [1024];
  undefined4 local_4;
  
  uVar1 = *(uint *)(param_2 + 8);
  uVar2 = *(uint *)(param_2 + 0xc);
  local_4 = DAT_00b49670;
  if (uVar1 == uVar2) {
    *(undefined4 *)(param_2 + 0xc) = 0;
    *(undefined4 *)(param_2 + 8) = 0;
    iVar3 = 0;
  }
  else {
    if (uVar2 < uVar1) {
      iVar3 = -uVar2;
    }
    else {
      iVar3 = *(int *)(param_2 + 4) - uVar2;
    }
    iVar3 = uVar1 + iVar3;
  }
  if (iVar3 < param_3) {
    uVar1 = *(uint *)(param_2 + 8);
    uVar2 = *(uint *)(param_2 + 0xc);
    if (uVar1 == uVar2) {
      *(undefined4 *)(param_2 + 0xc) = 0;
      *(undefined4 *)(param_2 + 8) = 0;
      param_3 = 0;
    }
    else if (uVar2 < uVar1) {
      param_3 = uVar1 - uVar2;
    }
    else {
      param_3 = (*(int *)(param_2 + 4) - uVar2) + uVar1;
    }
  }
  uVar1 = *(uint *)(param_1 + 8);
  uVar2 = *(uint *)(param_1 + 0xc);
  if (uVar1 == uVar2) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined4 *)(param_1 + 8) = 0;
    iVar3 = 0;
  }
  else if (uVar2 < uVar1) {
    iVar3 = uVar1 - uVar2;
  }
  else {
    iVar3 = (*(int *)(param_1 + 4) - uVar2) + uVar1;
  }
  iVar4 = *(int *)(param_1 + 4);
  if ((iVar4 - iVar3) + -1 < param_3) {
    uVar1 = *(uint *)(param_1 + 8);
    uVar2 = *(uint *)(param_1 + 0xc);
    if (uVar1 == uVar2) {
      iVar3 = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      *(undefined4 *)(param_1 + 8) = 0;
    }
    else if (uVar2 < uVar1) {
      iVar3 = uVar1 - uVar2;
    }
    else {
      iVar3 = (iVar4 - uVar2) + uVar1;
    }
    param_3 = (iVar4 - iVar3) + -1;
  }
  iVar3 = param_3;
  if (0 < param_3) {
    while( true ) {
      iVar4 = iVar3;
      if (0x400 < iVar3) {
        iVar4 = 0x400;
      }
      FUN_007cf350(param_2,local_404,iVar4);
      FUN_007cf290(param_1,local_404,iVar4);
      if (iVar3 - iVar4 < 1) break;
      iVar3 = iVar3 - iVar4;
    }
  }
  return param_3;
}


// ==== FUN_007cf610 @ 0x007cf610 ====

bool FUN_007cf610(LPCSTR param_1,BYTE *param_2,DWORD param_3,DWORD param_4)

{
  LSTATUS LVar1;
  HKEY hKey;
  DWORD local_8;
  HKEY local_4;
  
  local_8 = 0;
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,s_Software_IGA_009fff98,0,(LPSTR)0x0,0,0xf003f,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_4,&local_8);
  hKey = (HKEY)(~-(uint)(LVar1 != 0) & (uint)local_4);
  LVar1 = RegSetValueExA(hKey,param_1,0,param_4,param_2,param_3);
  RegCloseKey(hKey);
  return LVar1 == 0;
}


// ==== FUN_007cf690 @ 0x007cf690 ====

bool FUN_007cf690(LPCSTR param_1,LPBYTE param_2,DWORD param_3,void *param_4,size_t param_5,
                 DWORD param_6)

{
  LSTATUS LVar1;
  HKEY hKey;
  DWORD local_10 [2];
  HKEY local_8;
  DWORD local_4;
  
  local_10[0] = 0;
  local_10[1] = 0;
  LVar1 = RegCreateKeyExA((HKEY)0x80000001,s_Software_IGA_009fff98,0,(LPSTR)0x0,0,0xf003f,
                          (LPSECURITY_ATTRIBUTES)0x0,&local_8,local_10 + 1);
  hKey = (HKEY)(~-(uint)(LVar1 != 0) & (uint)local_8);
  LVar1 = RegQueryValueExA(hKey,param_1,(LPDWORD)0x0,&local_4,param_2,local_10);
  if (LVar1 != 0xea) {
    FUN_007cf610(param_1,param_4,param_5,param_6);
    _memmove(param_2,param_4,param_5);
    RegCloseKey(hKey);
    return true;
  }
  if (local_4 == param_6) {
    local_10[0] = param_3;
    LVar1 = RegQueryValueExA(hKey,param_1,(LPDWORD)0x0,&param_6,param_2,local_10);
    RegCloseKey(hKey);
    return LVar1 == 0;
  }
  RegCloseKey(hKey);
  return false;
}


// ==== FUN_007cf780 @ 0x007cf780 ====

void FUN_007cf780(undefined4 param_1,undefined4 param_2,undefined1 param_3)

{
  FUN_007cf690(param_1,param_2,8,&param_3,8,0xb);
  return;
}


// ==== FUN_007cf7a0 @ 0x007cf7a0 ====

void FUN_007cf7a0(undefined4 param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_4;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_007cf690(param_1,param_2,param_3,param_4,pcVar2 + (1 - (int)(param_4 + 1)),1);
  return;
}


// ==== FUN_007cf7e0 @ 0x007cf7e0 ====

void FUN_007cf7e0(undefined4 param_1,undefined1 param_2)

{
  FUN_007cf610(param_1,&param_2,4,0xb);
  return;
}


// ==== FUN_007cf800 @ 0x007cf800 ====

void FUN_007cf800(undefined4 param_1,undefined1 param_2)

{
  FUN_007cf610(param_1,&param_2,8,0xb);
  return;
}


// ==== FUN_007cf820 @ 0x007cf820 ====

undefined4 FUN_007cf820(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar1 = *(uint *)(param_1 + 8);
  if ((*(ushort *)(param_1 + 0xc) & 0x380) != 0) {
    puVar2 = (undefined4 *)FUN_007d0590(uVar1 + 2);
    if (puVar2 == (undefined4 *)0x0) {
      return 7;
    }
    *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 0x60;
    *(undefined4 *)(param_1 + 0x1c) = 0;
    puVar4 = *(undefined4 **)(param_1 + 0x18);
    puVar5 = puVar2;
    for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    for (uVar3 = uVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
      puVar4 = (undefined4 *)((int)puVar4 + 1);
      puVar5 = (undefined4 *)((int)puVar5 + 1);
    }
    *(undefined1 *)((int)puVar2 + uVar1) = 0;
    *(undefined1 *)((int)puVar2 + uVar1 + 1) = 0;
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) & 0xfc7f;
    *(undefined4 **)(param_1 + 0x18) = puVar2;
  }
  return 0;
}


// ==== FUN_007cf890 @ 0x007cf890 ====

undefined4 FUN_007cf890(int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if ((*(ushort *)(param_1 + 0xc) & 0x180) == 0) {
    return 0;
  }
  uVar1 = *(uint *)(param_1 + 8);
  if (uVar1 + 2 < 0x20) {
    puVar2 = (undefined4 *)(param_1 + 0x20);
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | 0x220;
  }
  else {
    puVar2 = (undefined4 *)FUN_007d0590(uVar1 + 2);
    if (puVar2 == (undefined4 *)0x0) {
      return 7;
    }
    *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 0x60;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  puVar4 = *(undefined4 **)(param_1 + 0x18);
  puVar5 = puVar2;
  for (uVar3 = uVar1 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  for (uVar3 = uVar1 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
    puVar4 = (undefined4 *)((int)puVar4 + 1);
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  *(undefined1 *)((int)puVar2 + uVar1) = 0;
  *(undefined1 *)((int)puVar2 + uVar1 + 1) = 0;
  *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) & 0xfe7f;
  *(undefined4 **)(param_1 + 0x18) = puVar2;
  return 0;
}


// ==== FUN_007cf920 @ 0x007cf920 ====

undefined4 FUN_007cf920(int param_1)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  uVar1 = *(ushort *)(param_1 + 0xc);
  if (((uVar1 & 0x20) != 0) || ((uVar1 & 2) == 0)) {
    return 0;
  }
  if ((uVar1 & 0x180) != 0) {
    uVar2 = FUN_007cf890(param_1);
    return uVar2;
  }
  puVar3 = (undefined4 *)FUN_007d0550(*(int *)(param_1 + 8) + 2);
  if (puVar3 == (undefined4 *)0x0) {
    return 7;
  }
  uVar5 = *(uint *)(param_1 + 8);
  puVar6 = *(undefined4 **)(param_1 + 0x18);
  puVar7 = puVar3;
  for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
    puVar6 = (undefined4 *)((int)puVar6 + 1);
    puVar7 = (undefined4 *)((int)puVar7 + 1);
  }
  *(undefined1 *)((int)puVar3 + *(int *)(param_1 + 8)) = 0;
  *(undefined1 *)(*(int *)(param_1 + 8) + 1 + (int)puVar3) = 0;
  (**(code **)(param_1 + 0x1c))(*(undefined4 *)(param_1 + 0x18));
  *(undefined4 **)(param_1 + 0x18) = puVar3;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return 0;
}


// ==== FUN_007cf9b0 @ 0x007cf9b0 ====

void FUN_007cf9b0(int param_1)

{
  if ((*(byte *)(param_1 + 0xc) & 0x40) != 0) {
    if (*(code **)(param_1 + 0x1c) != (code *)0x0) {
      (**(code **)(param_1 + 0x1c))(*(undefined4 *)(param_1 + 0x18));
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
      return;
    }
    FUN_007d05b0(*(undefined4 *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  return;
}


// ==== FUN_007cfa00 @ 0x007cfa00 ====

void FUN_007cfa00(int param_1)

{
  if ((*(byte *)(param_1 + 0xc) & 0x40) != 0) {
    if (*(code **)(param_1 + 0x1c) == (code *)0x0) {
      FUN_007d05b0(*(undefined4 *)(param_1 + 0x18));
    }
    else {
      (**(code **)(param_1 + 0x1c))(*(undefined4 *)(param_1 + 0x18));
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  *(undefined2 *)(param_1 + 0xc) = 1;
  *(undefined1 *)(param_1 + 0xe) = 5;
  return;
}


// ==== FUN_007cfa40 @ 0x007cfa40 ====

void FUN_007cfa40(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  if ((*(byte *)(param_1 + 3) & 0x40) != 0) {
    if ((code *)param_1[7] == (code *)0x0) {
      FUN_007d05b0(param_1[6]);
    }
    else {
      (*(code *)param_1[7])(param_1[6]);
    }
    param_1[6] = 0;
    param_1[7] = 0;
  }
  *param_1 = param_2;
  param_1[1] = param_3;
  *(undefined2 *)(param_1 + 3) = 4;
  *(undefined1 *)((int)param_1 + 0xe) = 1;
  return;
}


// ==== FUN_007cfa90 @ 0x007cfa90 ====

void FUN_007cfa90(int param_1,undefined8 param_2)

{
  if ((*(byte *)(param_1 + 0xc) & 0x40) != 0) {
    if (*(code **)(param_1 + 0x1c) == (code *)0x0) {
      FUN_007d05b0(*(undefined4 *)(param_1 + 0x18));
    }
    else {
      (**(code **)(param_1 + 0x1c))(*(undefined4 *)(param_1 + 0x18));
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  *(undefined2 *)(param_1 + 0xc) = 8;
  *(undefined8 *)(param_1 + 0x10) = param_2;
  *(undefined1 *)(param_1 + 0xe) = 2;
  return;
}


// ==== FUN_007cfae0 @ 0x007cfae0 ====

void FUN_007cfae0(undefined4 *param_1,undefined4 *param_2,ushort param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_1;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  param_1[7] = 0;
  if ((*(ushort *)(param_1 + 3) & 0x12) != 0) {
    *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) & 0xfc3f | param_3;
  }
  return;
}


// ==== FUN_007cfb20 @ 0x007cfb20 ====

undefined4 FUN_007cfb20(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((*(byte *)(param_1 + 3) & 0x40) != 0) {
    FUN_007cf9b0(param_1);
  }
  puVar3 = param_1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = *param_2;
    param_2 = param_2 + 1;
    puVar3 = puVar3 + 1;
  }
  param_1[7] = 0;
  if ((*(ushort *)(param_1 + 3) & 0x12) != 0) {
    *(ushort *)(param_1 + 3) = *(ushort *)(param_1 + 3) & 0xfd3f | 0x100;
  }
  if ((*(byte *)((int)param_1 + 0xd) & 1) == 0) {
    return 0;
  }
  uVar1 = FUN_007cf890(param_1);
  return uVar1;
}


// ==== FUN_007cfb80 @ 0x007cfb80 ====

undefined4 FUN_007cfb80(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  if ((*(byte *)(param_1 + 3) & 0x40) != 0) {
    FUN_007cf9b0(param_1);
  }
  puVar3 = param_2;
  puVar4 = param_1;
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  if ((*(byte *)((int)param_2 + 0xd) & 2) != 0) {
    param_1[6] = param_1 + 8;
  }
  *(undefined2 *)(param_2 + 3) = 1;
  param_2[7] = 0;
  if ((*(byte *)((int)param_1 + 0xd) & 1) == 0) {
    return 0;
  }
  uVar1 = FUN_007cf890(param_1);
  return uVar1;
}


// ==== FUN_007cfbe0 @ 0x007cfbe0 ====

undefined4 FUN_007cfbe0(int param_1,char *param_2,int param_3,char param_4,int param_5)

{
  char *pcVar1;
  char cVar2;
  undefined4 uVar3;
  int iVar4;
  
  if ((*(byte *)(param_1 + 0xc) & 0x40) != 0) {
    if (*(code **)(param_1 + 0x1c) == (code *)0x0) {
      FUN_007d05b0(*(undefined4 *)(param_1 + 0x18));
    }
    else {
      (**(code **)(param_1 + 0x1c))(*(undefined4 *)(param_1 + 0x18));
    }
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(undefined4 *)(param_1 + 0x1c) = 0;
  }
  if (param_2 == (char *)0x0) {
    *(undefined2 *)(param_1 + 0xc) = 1;
    *(undefined1 *)(param_1 + 0xe) = 5;
  }
  else {
    *(char **)(param_1 + 0x18) = param_2;
    if (param_5 == 0) {
      *(undefined2 *)(param_1 + 0xc) = 0x80;
    }
    else if (param_5 == -1) {
      *(undefined2 *)(param_1 + 0xc) = 0x100;
    }
    else {
      *(undefined2 *)(param_1 + 0xc) = 0x40;
      *(int *)(param_1 + 0x1c) = param_5;
    }
    *(char *)(param_1 + 0xf) = param_4;
    *(char *)(param_1 + 0xe) = (param_4 == '\0') + '\x03';
    *(int *)(param_1 + 8) = param_3;
    switch(param_4) {
    case '\0':
      *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 0x10;
      break;
    case '\x01':
      *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 2;
      if (param_3 < 0) {
        pcVar1 = param_2 + 1;
        do {
          cVar2 = *param_2;
          param_2 = param_2 + 1;
        } while (cVar2 != '\0');
        *(int *)(param_1 + 8) = (int)param_2 - (int)pcVar1;
        *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | 0x20;
      }
      break;
    case '\x02':
    case '\x03':
      *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 2;
      if (param_3 < 0) {
        uVar3 = FUN_007e5c70(param_2,0xffffffff);
        *(byte *)(param_1 + 0xc) = *(byte *)(param_1 + 0xc) | 0x20;
        *(undefined4 *)(param_1 + 8) = uVar3;
      }
      iVar4 = FUN_007e5b90(param_1);
      if (iVar4 != 0) {
        return 7;
      }
    }
    if ((*(byte *)(param_1 + 0xd) & 1) != 0) {
      uVar3 = FUN_007cf890(param_1);
      return uVar3;
    }
  }
  return 0;
}


// ==== FUN_007cfd00 @ 0x007cfd00 ====

int FUN_007cfd00(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  if (param_4 == 0) {
    iVar1 = FUN_007d7440(param_1,&local_4);
  }
  else {
    iVar1 = FUN_007d73d0(param_1,&local_4);
  }
  *(int *)(param_5 + 8) = param_3;
  if (local_4 < param_2 + param_3) {
    if (param_3 < 0x1f) {
      iVar1 = param_5 + 0x20;
      *(undefined2 *)(param_5 + 0xc) = 0x230;
    }
    else {
      iVar1 = FUN_007d0590(param_3 + 2);
      if (iVar1 == 0) {
        return 7;
      }
      *(undefined2 *)(param_5 + 0xc) = 0x70;
      *(undefined4 *)(param_5 + 0x1c) = 0;
    }
    *(int *)(param_5 + 0x18) = iVar1;
    *(undefined1 *)(param_5 + 0xf) = 0;
    *(undefined1 *)(param_5 + 0xe) = 4;
    if (param_4 == 0) {
      iVar2 = FUN_007d73b0(param_1,param_2,param_3,iVar1);
    }
    else {
      iVar2 = FUN_007d7380(param_1);
    }
    *(undefined1 *)(iVar1 + param_3) = 0;
    *(undefined1 *)(iVar1 + 1 + param_3) = 0;
    if (iVar2 != 0) {
      if (0x1e < param_3) {
        FUN_007d05b0(iVar1);
      }
      return iVar2;
    }
  }
  else {
    *(int *)(param_5 + 0x18) = iVar1 + param_2;
    *(undefined2 *)(param_5 + 0xc) = 0x110;
  }
  return 0;
}


// ==== FUN_007cfdf0 @ 0x007cfdf0 ====

void FUN_007cfdf0(void)

{
  int iVar1;
  
  iVar1 = FUN_007d0550(0x40);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0xc) = 1;
    *(undefined1 *)(iVar1 + 0xe) = 5;
  }
  return;
}


// ==== FUN_007cfe10 @ 0x007cfe10 ====

void FUN_007cfe10(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  if (param_1 != 0) {
    FUN_007cfbe0(param_1,param_3,param_2,param_4,param_5);
  }
  return;
}


// ==== FUN_007cfe40 @ 0x007cfe40 ====

void FUN_007cfe40(int param_1)

{
  if (param_1 != 0) {
    if ((*(byte *)(param_1 + 0xc) & 0x40) != 0) {
      if (*(code **)(param_1 + 0x1c) == (code *)0x0) {
        FUN_007d05b0(*(undefined4 *)(param_1 + 0x18));
      }
      else {
        (**(code **)(param_1 + 0x1c))(*(undefined4 *)(param_1 + 0x18));
      }
      *(undefined4 *)(param_1 + 0x18) = 0;
      *(undefined4 *)(param_1 + 0x1c) = 0;
    }
    *(undefined2 *)(param_1 + 0xc) = 1;
    *(undefined1 *)(param_1 + 0xe) = 5;
    FUN_007d05b0(param_1);
  }
  return;
}


// ==== FUN_007cfe90 @ 0x007cfe90 ====

int FUN_007cfe90(int param_1,uint param_2)

{
  int iVar1;
  
  if (((*(byte *)(param_1 + 0xc) & 2) == 0) || (*(byte *)(param_1 + 0xf) == param_2)) {
    return 0;
  }
  iVar1 = FUN_007e54f0(param_1,param_2);
  if (iVar1 == 7) {
    FUN_007cf9b0(param_1);
    *(undefined2 *)(param_1 + 0xc) = 1;
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  return iVar1;
}


// ==== FUN_007cfee0 @ 0x007cfee0 ====

undefined4 FUN_007cfee0(undefined8 *param_1,int param_2)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  char *pcVar4;
  undefined8 uVar5;
  
  pcVar1 = (char *)(param_1 + 4);
  if ((*(byte *)((int)param_1 + 0xc) & 8) == 0) {
    uVar5 = *param_1;
    pcVar4 = &DAT_009fffa8;
  }
  else {
    uVar5 = param_1[2];
    pcVar4 = s___15g_009fffb0;
  }
  FUN_007e4880(0x20,pcVar1,pcVar4,uVar5);
  pcVar4 = pcVar1;
  do {
    cVar2 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar2 != '\0');
  *(ushort *)((int)param_1 + 0xc) = *(ushort *)((int)param_1 + 0xc) | 0x222;
  *(int *)(param_1 + 1) = (int)pcVar4 - ((int)param_1 + 0x21);
  *(char **)(param_1 + 3) = pcVar1;
  *(undefined1 *)((int)param_1 + 0xf) = 1;
  if (((*(byte *)((int)param_1 + 0xc) & 2) != 0) && (param_2 != 1)) {
    iVar3 = FUN_007e54f0(param_1,param_2);
    if (iVar3 == 7) {
      FUN_007cf9b0();
      *(undefined2 *)((int)param_1 + 0xc) = 1;
      *(undefined4 *)(param_1 + 3) = 0;
    }
  }
  return 0;
}


// ==== FUN_007cff80 @ 0x007cff80 ====

undefined8 FUN_007cff80(undefined8 *param_1)

{
  ushort uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 local_8;
  
  uVar1 = *(ushort *)((int)param_1 + 0xc);
  if ((uVar1 & 4) != 0) {
    return *param_1;
  }
  if ((uVar1 & 8) != 0) {
    uVar3 = FUN_00802534();
    return uVar3;
  }
  if ((uVar1 & 0x12) == 0) {
    return 0;
  }
  iVar2 = FUN_007cfe90(param_1,1);
  if (iVar2 == 0) {
    iVar2 = FUN_007cf920(param_1);
    if (iVar2 == 0) {
      FUN_007d0cb0(*(undefined4 *)(param_1 + 3),&local_8);
      return local_8;
    }
  }
  return 7;
}


