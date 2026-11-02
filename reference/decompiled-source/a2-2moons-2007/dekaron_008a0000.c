// dekaron.exe (2Moons Open Beta 2007-07-30) Ghidra decompile, range 0x8a0000-0x8affff

// ==== FUN_008a00b4 @ 0x008a00b4 ====

int FUN_008a00b4(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int *in_EAX;
  int iVar1;
  undefined1 local_e0 [180];
  int local_2c;
  
  FUN_008a1c00();
  FUN_008aa201();
  if ((param_1 == (int *)0x0) || (in_EAX == (int *)0x0)) {
    iVar1 = -0x7789f794;
  }
  else {
    iVar1 = FUN_008aa3d5(local_e0,in_EAX,param_3,param_4,0,1);
    if (((-1 < iVar1) && (iVar1 = FUN_008a1c95(local_e0), -1 < iVar1)) &&
       (iVar1 = FUN_008a649d(param_1,param_2,param_5), -1 < iVar1)) {
      (**(code **)(*in_EAX + 0x30))();
      if (local_2c == 0) {
        (**(code **)(*in_EAX + 0xc))();
        iVar1 = (**(code **)(*param_1 + 0xc))(param_1);
        (**(code **)(*param_1 + 8))(param_1);
        if (iVar1 != 0) {
          iVar1 = -0x7789f798;
          goto LAB_008a0174;
        }
      }
      iVar1 = 0;
    }
  }
LAB_008a0174:
  thunk_FUN_008aa2f3();
  FUN_008a1c19();
  return iVar1;
}


// ==== FUN_008a018e @ 0x008a018e ====

void FUN_008a018e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_008a00b4(param_1,param_2,param_4,param_5,0);
  return;
}


// ==== FUN_008a01ad @ 0x008a01ad ====

int FUN_008a01ad(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined4 param_8,undefined4 *param_9,
                int param_10,undefined4 param_11)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_bc [72];
  undefined4 local_74;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58 [6];
  undefined4 local_40 [8];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  FUN_008a6876();
  FUN_008aa3a6();
  if (((param_1 == 0) || (param_4 == 0)) || (param_9 == (undefined4 *)0x0)) {
    iVar1 = -0x7789f794;
  }
  else {
    if (param_10 == -1) {
      param_10 = 0x80004;
    }
    iVar1 = FUN_008aa8c9(local_bc,param_1,param_2,param_3,0,0);
    if (-1 < iVar1) {
      local_64 = param_5;
      local_60 = param_6;
      local_5c = param_7;
      local_68 = param_4;
      iVar4 = 6;
      puVar2 = param_9;
      puVar3 = local_58;
      for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = local_40;
      for (; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar2 = *param_9;
        param_9 = param_9 + 1;
        puVar2 = puVar2 + 1;
      }
      local_20 = local_74;
      local_1c = param_11;
      local_18 = param_8;
      iVar1 = FUN_008aa0c4(local_bc,&local_68,param_10);
      if (-1 < iVar1) {
        iVar1 = 0;
      }
    }
  }
  thunk_FUN_008aa3ac();
  FUN_008a6880();
  return iVar1;
}


// ==== FUN_008a0289 @ 0x008a0289 ====

undefined4
FUN_008a0289(uint *param_1,uint *param_2,uint *param_3,uint *param_4,uint param_5,int *param_6,
            int param_7,uint param_8)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int *in_EDX;
  uint uVar5;
  uint local_10c;
  uint local_f0;
  uint local_ec;
  uint local_e8;
  int local_e0;
  uint local_18;
  int local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  if (in_EDX == (int *)0x0) {
    return 0x8876086c;
  }
  if (param_5 == 0xffffffff) {
    param_5 = 0;
  }
  if (((param_5 & 0xffe039ec) != 0) ||
     ((((param_7 != 0 && (param_7 != 1)) && (param_7 != 2)) && (param_7 != 3)))) {
    return 0x8876086c;
  }
  if (param_6 == (int *)0x0) {
    local_14 = 0;
  }
  else {
    local_14 = *param_6;
  }
  if (param_7 == 3) {
    if (local_14 == 0) {
      local_14 = 0x15;
    }
  }
  else {
    uVar1 = FUN_0089fd60(local_14);
    local_14 = FUN_0089fe73(in_EDX,param_5,param_8,uVar1);
    if (local_14 == 0) {
      return 0x8876086a;
    }
  }
  if (param_1 == (uint *)0x0) {
    local_c = 0xffffffff;
  }
  else {
    local_c = *param_1;
  }
  if (param_2 == (uint *)0x0) {
    local_8 = 0xffffffff;
  }
  else {
    local_8 = *param_2;
  }
  if (param_3 == (uint *)0x0) {
    local_10 = 0xffffffff;
  }
  else {
    local_10 = *param_3;
  }
  if (param_4 == (uint *)0x0) {
    local_18 = 0xffffffff;
  }
  else {
    local_18 = *param_4;
  }
  if (local_c == 0xffffffff) {
    if (local_8 != 0xffffffff) {
      local_c = local_8;
      goto LAB_008a0398;
    }
    local_8 = 0x100;
    local_c = 0x100;
  }
  else {
    if (local_8 == 0xffffffff) {
      local_8 = local_c;
    }
LAB_008a0398:
    if (local_c == 0) {
      local_c = 1;
    }
    if (local_8 == 0) {
      local_8 = 1;
    }
  }
  if (param_8 == 5) {
    if (local_8 < local_c) {
      local_8 = local_c;
    }
    local_c = local_8;
  }
  if ((local_10 == 0xffffffff) || (local_10 == 0)) {
    local_10 = 1;
  }
  if (param_7 == 3) goto LAB_008a0509;
  (**(code **)(*in_EDX + 0x1c))();
  if (param_8 == 4) {
    if (local_e8 < local_10) {
      local_10 = local_e8;
    }
    if (local_e8 < local_c) {
      local_c = local_e8;
    }
LAB_008a0468:
    if (local_e8 < local_8) {
      local_8 = local_e8;
    }
  }
  else {
    if (local_f0 < local_c) {
      local_c = local_f0;
    }
    if (local_ec < local_8) {
      local_8 = local_ec;
    }
    if (param_8 == 3) {
      if ((local_10c & 0x20) != 0) {
        local_e0 = 1;
      }
      if (local_e0 != 0) {
        if (local_e0 * local_8 < local_c) {
          local_c = local_e0 * local_8;
        }
        local_e8 = local_e0 * local_c;
        goto LAB_008a0468;
      }
    }
  }
  uVar4 = local_8;
  uVar3 = local_c;
  uVar5 = local_10;
  if (param_8 == 3) {
    uVar2 = 2;
  }
  else if (param_8 == 4) {
    uVar2 = 0x40000;
  }
  else if (param_8 == 5) {
    uVar2 = 0x20000;
  }
  else {
    uVar2 = param_8;
  }
  if ((((local_18 == 1) && ((local_10c & 0x100) != 0)) &&
      ((local_14 != 0x31545844 &&
       (((local_14 != 0x32545844 && (local_14 != 0x33545844)) && (local_14 != 0x34545844)))))) &&
     (local_14 != 0x35545844)) {
    uVar2 = 0;
  }
  if ((local_10c & uVar2) != 0) {
    local_c = 1;
    if (1 < uVar3) {
      do {
        local_c = local_c << 1;
      } while (local_c < uVar3);
    }
    local_8 = 1;
    if (1 < uVar4) {
      do {
        local_8 = local_8 << 1;
      } while (local_8 < uVar4);
    }
    local_10 = 1;
    if (1 < uVar5) {
      do {
        local_10 = local_10 << 1;
      } while (local_10 < uVar5);
    }
  }
LAB_008a0509:
  if (((local_14 == 0x31545844) || (local_14 == 0x32545844)) ||
     ((local_14 == 0x33545844 || ((local_14 == 0x34545844 || (local_14 == 0x35545844)))))) {
    local_c = local_c + 3 & 0xfffffffc;
    local_8 = local_8 + 3 & 0xfffffffc;
  }
  if (param_8 == 3) {
    uVar5 = 0x4000;
  }
  else if (param_8 == 4) {
    uVar5 = 0x8000;
  }
  else if (param_8 == 5) {
    uVar5 = 0x10000;
  }
  else {
    uVar5 = param_8;
  }
  if ((param_7 == 3) ||
     (((local_10c & uVar5) != 0 &&
      (((local_10c & 0x100) == 0 ||
       ((((local_c & local_c - 1) == 0 && ((local_8 & local_8 - 1) == 0)) &&
        ((local_10 & local_10 - 1) == 0)))))))) {
    uVar5 = 0;
    for (uVar3 = local_c; uVar3 != 0; uVar3 = uVar3 >> 1) {
      uVar5 = uVar5 + 1;
    }
    uVar3 = 0;
    for (uVar4 = local_8; uVar4 != 0; uVar4 = uVar4 >> 1) {
      uVar3 = uVar3 + 1;
    }
    uVar2 = 0;
    for (uVar4 = local_10; uVar4 != 0; uVar4 = uVar4 >> 1) {
      uVar2 = uVar2 + 1;
    }
    if (uVar5 <= uVar3) {
      uVar5 = uVar3;
    }
    if ((param_8 == 4) && (uVar5 < uVar2)) {
      uVar5 = uVar2;
    }
    if ((uVar5 < local_18) || (local_18 == 0)) {
      local_18 = uVar5;
    }
    if ((local_18 != 1) && ((param_5 & 0x400) != 0)) {
      local_18 = 0;
    }
  }
  else {
    local_18 = 1;
  }
  if (param_1 != (uint *)0x0) {
    *param_1 = local_c;
  }
  if (param_2 != (uint *)0x0) {
    *param_2 = local_8;
  }
  if (param_3 != (uint *)0x0) {
    *param_3 = local_10;
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = local_18;
  }
  if (param_6 != (int *)0x0) {
    *param_6 = local_14;
  }
  return 0;
}


// ==== FUN_008a063e @ 0x008a063e ====

void FUN_008a063e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  FUN_008a0289(param_2,param_3,0,param_4,param_5,param_6,param_7,3);
  return;
}


// ==== FUN_008a0665 @ 0x008a0665 ====

int FUN_008a0665(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,uint param_5,
                undefined4 param_6,undefined4 param_7,int param_8)

{
  int iVar1;
  uint uVar2;
  
  if ((param_1 == (int *)0x0) || (param_8 == 0)) {
    iVar1 = -0x7789f794;
  }
  else {
    uVar2 = param_5;
    if (param_5 == 0xffffffff) {
      uVar2 = 0;
    }
    iVar1 = FUN_008a063e(param_1,&param_2,&param_3,&param_4,uVar2,&param_6,param_7);
    if ((-1 < iVar1) &&
       (iVar1 = (**(code **)(*param_1 + 0x5c))
                          (param_1,param_2,param_3,param_4,uVar2 & 0xffe07fff,param_6,param_7,
                           param_8,0), -1 < iVar1)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}


// ==== FUN_008a06d5 @ 0x008a06d5 ====

int FUN_008a06d5(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
                uint param_7,int param_8)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  bool bVar6;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  undefined1 local_a4 [64];
  undefined1 local_64 [12];
  int local_58;
  int local_4c;
  int local_48;
  undefined1 local_44 [12];
  int local_38;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_008aa201();
  piVar1 = param_4;
  if (param_1 == (int *)0x0) {
    iVar3 = -0x7789f794;
    goto LAB_008a08da;
  }
  if (param_4 == (int *)0x0) {
    iVar3 = -0x7789f794;
    goto LAB_008a08da;
  }
  (**(code **)(*param_1 + 0x30))(param_1,local_64);
  (**(code **)(*piVar1 + 0x30))(piVar1,local_44);
  if (((param_7 & 0xffff) == 5) || (param_8 != 0)) {
LAB_008a0840:
    uVar2 = 1;
    if (param_1 == piVar1) {
      uVar2 = 0x10001;
    }
    iVar3 = FUN_008aa3d5(&local_cc,piVar1,param_5,param_6,0,uVar2);
    if ((iVar3 < 0) ||
       (iVar3 = FUN_0089ffcc(param_1,param_2,param_3,local_cc,local_c8,local_c4,param_5,local_a4,
                             param_7,param_8), iVar3 < 0)) goto LAB_008a08da;
    if ((local_38 == 0) && (local_58 != 0)) {
      (**(code **)(*piVar1 + 0xc))(piVar1,&param_1);
      iVar3 = (**(code **)(*param_1 + 0xc))(param_1);
      (**(code **)(*param_1 + 8))(param_1);
      if (iVar3 != 0) {
        iVar3 = -0x7789f798;
        goto LAB_008a08da;
      }
    }
  }
  else {
    if (param_2 != param_5) {
      if ((param_2 != (int *)0x0) && (param_5 != (int *)0x0)) {
        iVar3 = 0x100;
        bVar6 = true;
        piVar4 = param_2;
        piVar5 = param_5;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar6 = *piVar4 == *piVar5;
          piVar4 = piVar4 + 1;
          piVar5 = piVar5 + 1;
        } while (bVar6);
        if (bVar6) goto LAB_008a0765;
      }
      goto LAB_008a0840;
    }
LAB_008a0765:
    if (param_3 == (int *)0x0) {
      local_14 = 0;
      local_10 = 0;
      local_c = local_4c;
      local_8 = local_48;
    }
    else {
      local_14 = *param_3;
      local_10 = param_3[1];
      local_c = param_3[2];
      local_8 = param_3[3];
    }
    if (param_6 == (int *)0x0) {
      local_24 = 0;
      local_20 = 0;
      local_1c = local_2c;
      local_18 = local_28;
    }
    else {
      local_24 = *param_6;
      local_20 = param_6[1];
      local_1c = param_6[2];
      local_18 = param_6[3];
    }
    if ((local_c - local_14 != local_1c - local_24) || (local_8 - local_10 != local_18 - local_20))
    goto LAB_008a0840;
    (**(code **)(*piVar1 + 0xc))(piVar1,&param_4);
    FUN_007a41ff(1);
    iVar3 = -0x7fffbffb;
    if (local_58 == 0) {
      if (local_38 == 0) {
        iVar3 = (**(code **)(*param_4 + 0x88))(param_4,piVar1,&local_24,param_1,&local_14,0);
      }
      else if (local_38 == 2) {
        iVar3 = (**(code **)(*param_4 + 0x78))(param_4,piVar1,&local_24,param_1,&local_14);
      }
    }
    FUN_007a41ff(0);
    (**(code **)(*param_4 + 8))(param_4);
    if (iVar3 < 0) goto LAB_008a0840;
  }
  iVar3 = 0;
LAB_008a08da:
  thunk_FUN_008aa2f3();
  return iVar3;
}


// ==== FUN_008a08e9 @ 0x008a08e9 ====

int FUN_008a08e9(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined1 local_34 [48];
  
  FUN_008aa3a6();
  if ((param_1 == 0) || (param_4 == 0)) {
    iVar3 = -0x7789f794;
  }
  else {
    uVar1 = 1;
    if (param_1 == param_4) {
      uVar1 = 0x10001;
    }
    iVar2 = FUN_008aa8c9(&local_5c,param_4,param_5,param_6,0,uVar1);
    if (-1 < iVar2) {
      iVar2 = FUN_008a01ad(param_1,param_2,param_3,local_5c,local_58,local_54,local_50,param_5,
                           local_34,param_7,param_8);
      iVar3 = 0;
      if (-1 < iVar2) goto LAB_008a0962;
    }
    iVar3 = iVar2;
  }
LAB_008a0962:
  thunk_FUN_008aa3ac();
  return iVar3;
}


// ==== FUN_008a0971 @ 0x008a0971 ====

uint FUN_008a0971(int *param_1,undefined4 param_2,uint param_3,uint param_4)

{
  int *piVar1;
  uint uVar2;
  int **ppiVar3;
  uint uVar4;
  undefined1 local_64 [24];
  uint local_4c;
  uint local_48;
  undefined1 local_44 [16];
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int local_20;
  int *local_1c;
  uint local_18;
  int local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  piVar1 = param_1;
  if ((param_1 == (int *)0x0) ||
     (((local_14 = (**(code **)(*param_1 + 0x28))(param_1), local_14 != 3 && (local_14 != 4)) &&
      (local_14 != 5)))) {
    return 0x8876086c;
  }
  local_1c = piVar1;
  if (param_4 != 0xffffffff) goto LAB_008a0a11;
  if (local_14 == 3) {
    (**(code **)(*piVar1 + 0x44))(piVar1,0,local_64);
    if (((local_4c & local_4c - 1) != 0) || ((local_48 & local_48 - 1) != 0)) {
      param_4 = 0;
LAB_008a0a4b:
      if (param_4 == 0) goto LAB_008a0a0a;
    }
LAB_008a0a50:
    param_4 = 5;
  }
  else {
    if (local_14 == 4) {
      (**(code **)(*piVar1 + 0x44))(piVar1,0,local_44);
      if (((local_34 & local_34 - 1) == 0) && ((local_30 & local_30 - 1) == 0)) {
        local_48 = local_2c;
LAB_008a0a03:
        if ((local_48 & local_48 - 1) == 0) goto LAB_008a0a50;
      }
    }
    else {
      if (local_14 != 5) goto LAB_008a0a4b;
      (**(code **)(*piVar1 + 0x44))(piVar1,0,local_64);
      if ((local_4c & local_4c - 1) == 0) goto LAB_008a0a03;
    }
LAB_008a0a0a:
    param_4 = 0x80004;
  }
LAB_008a0a11:
  if (local_14 == 5) {
    param_4 = param_4 | 0x70000;
  }
  if ((param_4 & 0x400000) == 0) {
    param_4 = param_4 & 0xff9fffff;
  }
  else {
    param_4 = param_4 | 0x600000;
  }
  local_24 = (**(code **)(*piVar1 + 0x34))(piVar1);
  if (param_3 == 0xffffffff) {
    param_3 = 0;
  }
  if (param_3 < local_24) {
    param_1 = (int *)0x0;
    local_c = (int *)0x0;
    local_8 = (int *)0x0;
    local_10 = (int *)0x0;
    local_28 = ((local_14 != 5) - 1 & 5) + 1;
    if (((param_4 & 0xff) == 2) || (local_20 = 0, (param_4 & 0xff) == 5)) {
      local_20 = 1;
    }
    local_18 = 0;
    if (local_28 != 0) {
      uVar2 = param_4;
      do {
        if (local_14 == 3) {
          ppiVar3 = &param_1;
LAB_008a0aea:
          uVar2 = (**(code **)(*local_1c + 0x48))(local_1c,param_3,ppiVar3);
        }
        else {
          if (local_14 == 4) {
            ppiVar3 = &local_c;
            goto LAB_008a0aea;
          }
          if (local_14 == 5) {
            uVar2 = (**(code **)(*local_1c + 0x48))(local_1c,local_18,param_3,&param_1);
          }
        }
        if ((int)uVar2 < 0) goto LAB_008a0c1d;
        uVar4 = param_3;
LAB_008a0be2:
        uVar4 = uVar4 + 1;
        if (uVar4 < local_24) {
          if (local_14 == 3) {
            ppiVar3 = &local_8;
LAB_008a0b32:
            uVar2 = (**(code **)(*local_1c + 0x48))(local_1c,uVar4,ppiVar3);
          }
          else {
            if (local_14 == 4) {
              ppiVar3 = &local_10;
              goto LAB_008a0b32;
            }
            if (local_14 == 5) {
              uVar2 = (**(code **)(*local_1c + 0x48))(local_1c,local_18,uVar4,&local_8);
            }
          }
          if (-1 < (int)uVar2) {
            if (local_14 == 3) {
LAB_008a0b55:
              uVar2 = FUN_008a06d5(local_8,param_2,0,param_1,param_2,0,param_4,0);
            }
            else if (local_14 == 4) {
              uVar2 = FUN_008a08e9(local_10,param_2,0,local_c,param_2,0,param_4,0);
            }
            else if (local_14 == 5) goto LAB_008a0b55;
            if (-1 < (int)uVar2) {
              if (local_20 == 0) goto LAB_008a0bc2;
              if (param_1 != (int *)0x0) {
                (**(code **)(*param_1 + 8))(param_1);
                param_1 = (int *)0x0;
              }
              if (local_c != (int *)0x0) {
                (**(code **)(*local_c + 8))(local_c);
              }
              param_1 = local_8;
              local_8 = (int *)0x0;
              local_c = local_10;
              goto LAB_008a0bdf;
            }
          }
          goto LAB_008a0c1d;
        }
        if (param_1 != (int *)0x0) {
          (**(code **)(*param_1 + 8))(param_1);
          param_1 = (int *)0x0;
        }
        if (local_c != (int *)0x0) {
          (**(code **)(*local_c + 8))(local_c);
          local_c = (int *)0x0;
        }
        local_18 = local_18 + 1;
      } while (local_18 < local_28);
    }
    uVar2 = 0;
LAB_008a0c1d:
    if (param_1 != (int *)0x0) {
      (**(code **)(*param_1 + 8))(param_1);
      param_1 = (int *)0x0;
    }
    if (local_c != (int *)0x0) {
      (**(code **)(*local_c + 8))(local_c);
      local_c = (int *)0x0;
    }
    if (local_8 != (int *)0x0) {
      (**(code **)(*local_8 + 8))(local_8);
      local_8 = (int *)0x0;
    }
    if (local_10 != (int *)0x0) {
      (**(code **)(*local_10 + 8))(local_10);
    }
  }
  else {
    uVar2 = 0x8876086c;
  }
  return uVar2;
LAB_008a0bc2:
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
    local_8 = (int *)0x0;
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
LAB_008a0bdf:
    local_10 = (int *)0x0;
  }
  goto LAB_008a0be2;
}


// ==== FUN_008a0c63 @ 0x008a0c63 ====

int FUN_008a0c63(int *param_1,uint param_2,uint param_3,uint param_4,int *param_5,uint param_6,
                uint param_7,uint param_8,uint param_9,int param_10,uint param_11,uint param_12,
                uint param_13,int *param_14,undefined4 *param_15,int param_16,undefined4 *param_17)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int **ppiVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  int iVar8;
  uint *puVar9;
  undefined4 *puVar10;
  undefined4 local_4dc;
  int local_dc [7];
  int local_c0 [2];
  int local_b8;
  uint local_b4;
  int *local_b0;
  uint local_ac;
  int local_74;
  int local_70;
  uint local_6c [14];
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  piVar5 = param_14;
  uVar3 = param_4;
  FUN_008a1c00();
  local_8 = (int *)0x0;
  param_14 = (int *)0x0;
  local_c = (int *)0x0;
  local_10 = (int *)0x0;
  if ((((param_1 == (int *)0x0) || (param_2 == 0)) || (param_3 == 0)) ||
     (param_17 == (undefined4 *)0x0)) {
    iVar8 = -0x7789f794;
    goto LAB_008a1497;
  }
  local_6c[0xd] = (uint)(uVar3 == 0xfffffffd);
  local_28 = (uint)(param_5 == (int *)0xfffffffd);
  local_20 = (uint)(param_6 == 0xfffffffd);
  local_30 = (uint)(param_7 == 0xfffffffd);
  local_1c = (uint)(param_9 == 0xfffffffd);
  if ((piVar5 == (int *)0x0) && (param_16 == -1)) {
    piVar5 = local_dc;
  }
  iVar8 = FUN_008a61eb(param_2,param_3,piVar5,1);
  if (iVar8 < 0) goto LAB_008a1497;
  if (param_16 == -1) {
    param_16 = piVar5[5];
  }
  param_3 = 1;
  for (; local_74 != 0; local_74 = *(int *)(local_74 + 0x4c)) {
    param_3 = param_3 + 1;
  }
  param_2 = 1;
  if (param_16 == 5) {
    if (local_70 != 0) {
      do {
        local_70 = *(int *)(local_70 + 0x50);
        param_2 = param_2 + 1;
      } while (local_70 != 0);
      if (param_2 == 6) goto LAB_008a0d63;
    }
    iVar8 = -0x7fffbffb;
    goto LAB_008a1497;
  }
LAB_008a0d63:
  if (param_7 == 0xfffffffd) {
    param_7 = param_3;
  }
  if (((uVar3 == 0xfffffffe) || (uVar3 == 0xfffffffd)) || ((int)local_b4 < 0)) {
    param_4 = local_b4;
  }
  else if (((uVar3 == 0) || (uVar3 == 0xffffffff)) && (param_4 = 1, 1 < local_b4)) {
    do {
      param_4 = param_4 << 1;
    } while (param_4 < local_b4);
  }
  if (((param_5 == (int *)0xfffffffe) || (param_5 == (int *)0xfffffffd)) || ((int)local_b0 < 0)) {
    param_5 = local_b0;
  }
  else if (((param_5 == (int *)0x0) || (param_5 == (int *)0xffffffff)) &&
          (param_5 = (int *)0x1, (int *)0x1 < local_b0)) {
    do {
      param_5 = (int *)((int)param_5 << 1);
    } while (param_5 < local_b0);
  }
  if (((param_6 == 0xfffffffe) || (param_6 == 0xfffffffd)) || ((int)local_ac < 0)) {
    param_6 = local_ac;
  }
  else if (((param_6 == 0) || (param_6 == 0xffffffff)) && (param_6 = 1, 1 < local_ac)) {
    do {
      param_6 = param_6 << 1;
    } while (param_6 < local_ac);
  }
  if (param_11 == 0xffffffff) {
    param_11 = 0x80004;
  }
  if (param_12 == 0xffffffff) {
    param_12 = 5;
  }
  if (param_16 == 5) {
    param_11 = param_11 | 0x70000;
    param_12 = param_12 | 0x70000;
  }
  if ((((char)param_11 == '\x01') || ((param_12 & 0xff) == 2)) || ((param_12 & 0xff) == 5)) {
    local_18 = 1;
  }
  else {
    local_18 = 0;
  }
  if (local_b8 == 0) {
    puVar6 = &local_4dc;
    for (iVar8 = 0x100; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar6 = 0xffffffff;
      puVar6 = puVar6 + 1;
    }
  }
  else {
    uVar3 = 0;
    do {
      uVar2 = *(uint *)(local_b8 + uVar3 * 4);
      (&local_4dc)[uVar3] =
           -(uint)(uVar2 != (param_13 >> 0x10 & 0xff | (param_13 & 0xff) << 0x10 |
                            param_13 & 0xff00ff00)) & uVar2;
      uVar3 = uVar3 + 1;
    } while (uVar3 < 0x100);
    param_13 = 0;
    if ((param_9 != 0x29) && (local_c0[0] == 0x29)) {
      uVar3 = 0;
      do {
        if ((&local_4dc)[uVar3] != (((uVar3 | 0xffffff00) << 8 | uVar3) << 8 | uVar3)) break;
        uVar3 = uVar3 + 1;
      } while (uVar3 < 0x100);
      if (uVar3 == 0x100) {
        local_c0[0] = 0x32;
      }
      else {
        local_6c[3] = 0xff;
        local_6c[0xc] = 0xff;
        local_6c[0] = 0;
        local_6c[1] = 0x55;
        local_6c[2] = 0xaa;
        local_6c[5] = 0;
        local_6c[6] = 0x24;
        local_6c[7] = 0x49;
        local_6c[8] = 0x6d;
        local_6c[9] = 0x92;
        local_6c[10] = 0xb6;
        local_6c[0xb] = 0xdb;
        uVar3 = 0;
        do {
          if ((&local_4dc)[uVar3] !=
              (((local_6c[uVar3 & 3] | 0xffffff00) << 8 | local_6c[(uVar3 >> 2 & 7) + 5]) << 8 |
              local_6c[(uVar3 >> 5) + 5])) break;
          uVar3 = uVar3 + 1;
        } while (uVar3 < 0x100);
        if (uVar3 == 0x100) {
          local_c0[0] = 0x1b;
        }
      }
    }
  }
  iVar8 = local_c0[0];
  if ((param_9 == 0) || (param_9 == 0xfffffffd)) {
    if (param_13 != 0) {
      puVar1 = (uint *)FUN_0089fd60(local_c0[0]);
      uVar3 = puVar1[1];
      if ((((uVar3 == 0) || (uVar3 == 1)) || (uVar3 == 2)) && (puVar1[4] == 0)) {
        puVar9 = local_6c + 4;
        for (iVar8 = 9; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar9 = *puVar1;
          puVar1 = puVar1 + 1;
          puVar9 = puVar9 + 1;
        }
        local_6c[4] = 0;
        local_6c[8] = 1;
        iVar8 = FUN_0089fe73(0,param_8,param_16,local_6c + 4);
        if (iVar8 == 0) {
          iVar8 = local_c0[0];
        }
      }
    }
    param_9 = FUN_0089ff71(iVar8);
    if ((param_10 != 3) && (param_9 == 0x14)) {
      param_9 = 0x16;
    }
  }
  piVar5 = param_5;
  uVar3 = param_4;
  if (param_15 == (undefined4 *)0x0) {
LAB_008a102d:
    if ((local_1c == 0) || ((param_9 != 0x28 && (param_9 != 0x29)))) {
      if (param_9 == 0x28) {
LAB_008a106e:
        param_9 = 0x15;
      }
      else if (param_9 == 0x29) {
        param_9 = 0x16;
        uVar2 = 0;
        do {
          if (*(char *)((int)&local_4dc + uVar2 * 4 + 3) != -1) goto LAB_008a106e;
          uVar2 = uVar2 + 1;
        } while (uVar2 < 0x100);
      }
      goto LAB_008a1075;
    }
    iVar8 = -0x7789f794;
  }
  else {
    puVar6 = &local_4dc;
    puVar10 = param_15;
    for (iVar8 = 0x100; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar10 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar10 = puVar10 + 1;
    }
    if (local_b8 == 0) goto LAB_008a102d;
LAB_008a1075:
    if ((param_10 != 0) || (local_14 = 1, (param_8 & 0x200) != 0)) {
      local_14 = 0;
    }
    local_34 = param_6;
    local_2c = param_7;
    local_24 = param_9;
    iVar8 = FUN_008a0289(&param_4,&param_5,&param_6,&param_7,param_8,&param_9,param_10,param_16);
    uVar2 = param_9;
    if (-1 < iVar8) {
      if ((((((local_6c[0xd] == 0) || (uVar3 == param_4)) &&
            ((local_28 == 0 || (piVar5 == param_5)))) && ((local_20 == 0 || (local_34 == param_6))))
          && ((local_30 == 0 || (local_2c == param_7)))) &&
         ((local_1c == 0 || (local_24 == param_9)))) {
        if (param_16 == 3) {
          iVar8 = (**(code **)(*param_1 + 0x5c))
                            (param_1,param_4,param_5,param_7,param_8 & 0xffe07fff,param_9,param_10,
                             &local_c,0);
        }
        else if (param_16 == 4) {
          iVar8 = (**(code **)(*param_1 + 0x60))
                            (param_1,param_4,param_5,param_6,param_7,param_8 & 0xffe07fff,param_9,
                             param_10,&local_c,0);
        }
        else if (param_16 == 5) {
          iVar8 = (**(code **)(*param_1 + 100))
                            (param_1,param_4,param_7,param_8 & 0xffe07fff,param_9,param_10,&local_c,
                             0);
        }
        if (-1 < iVar8) {
          if (local_14 == 0) {
            piVar5 = local_c;
          }
          else {
            if (param_16 == 3) {
              iVar8 = (**(code **)(*param_1 + 0x5c))
                                (param_1,param_4,param_5,param_7,0,uVar2,2,&local_10,0);
            }
            else if (param_16 == 4) {
              iVar8 = (**(code **)(*param_1 + 0x60))
                                (param_1,param_4,param_5,param_6,param_7,0,uVar2,2,&local_10,0);
            }
            else if (param_16 == 5) {
              iVar8 = (**(code **)(*param_1 + 100))(param_1,param_4,param_7,0,uVar2,2,&local_10,0);
            }
            if (iVar8 < 0) goto LAB_008a1454;
            piVar5 = local_10;
          }
          param_4 = 0;
          param_5 = local_c0;
          if (param_2 != 0) {
            do {
              param_9 = 0;
              piVar7 = param_5;
              if (param_3 != 0) {
                while (param_9 < param_7) {
                  if (param_16 == 3) {
                    ppiVar4 = &param_14;
LAB_008a1273:
                    iVar8 = (**(code **)(*piVar5 + 0x48))(piVar5,param_9,ppiVar4);
                  }
                  else {
                    if (param_16 == 4) {
                      ppiVar4 = &local_8;
                      goto LAB_008a1273;
                    }
                    if (param_16 == 5) {
                      iVar8 = (**(code **)(*piVar5 + 0x48))(piVar5,param_4,param_9,&param_14);
                    }
                  }
                  if (iVar8 < 0) goto LAB_008a1454;
                  if (param_16 == 3) {
LAB_008a1295:
                    iVar8 = FUN_0089ffcc(param_14,param_15,0,piVar7[1],*piVar7,piVar7[0xc],
                                         &local_4dc,piVar7 + 6,param_11,param_13);
                  }
                  else if (param_16 == 4) {
                    iVar8 = FUN_008a01ad(local_8,param_15,0,piVar7[1],*piVar7,piVar7[0xc],
                                         piVar7[0xd],&local_4dc,piVar7 + 6,param_11,param_13);
                  }
                  else if (param_16 == 5) goto LAB_008a1295;
                  if (iVar8 < 0) goto LAB_008a1454;
                  if (local_8 != (int *)0x0) {
                    (**(code **)(*local_8 + 8))(local_8);
                    local_8 = (int *)0x0;
                  }
                  if (param_14 != (int *)0x0) {
                    (**(code **)(*param_14 + 8))(param_14);
                    param_14 = (int *)0x0;
                  }
                  param_9 = param_9 + 1;
                  if (param_3 <= param_9) break;
                  piVar7 = (int *)piVar7[0x13];
                }
              }
              if ((local_18 == 0) && (param_9 < param_7)) {
                do {
                  if (param_16 == 3) {
                    ppiVar4 = &param_14;
LAB_008a1363:
                    iVar8 = (**(code **)(*piVar5 + 0x48))(piVar5,param_9,ppiVar4);
                  }
                  else {
                    if (param_16 == 4) {
                      ppiVar4 = &local_8;
                      goto LAB_008a1363;
                    }
                    if (param_16 == 5) {
                      iVar8 = (**(code **)(*piVar5 + 0x48))(piVar5,param_4,param_9,&param_14);
                    }
                  }
                  if (iVar8 < 0) goto LAB_008a1454;
                  if (param_16 == 3) {
LAB_008a1389:
                    iVar8 = FUN_0089ffcc(param_14,param_15,0,piVar7[1],*piVar7,piVar7[0xc],
                                         &local_4dc,piVar7 + 6,param_11,param_13);
                  }
                  else if (param_16 == 4) {
                    iVar8 = FUN_008a01ad(local_8,param_15,0,piVar7[1],*piVar7,piVar7[0xc],
                                         piVar7[0xd],&local_4dc,piVar7 + 6,param_11,param_13);
                  }
                  else if (param_16 == 5) goto LAB_008a1389;
                  if (iVar8 < 0) goto LAB_008a1454;
                  if (local_8 != (int *)0x0) {
                    (**(code **)(*local_8 + 8))(local_8);
                    local_8 = (int *)0x0;
                  }
                  if (param_14 != (int *)0x0) {
                    (**(code **)(*param_14 + 8))(param_14);
                    param_14 = (int *)0x0;
                  }
                  param_9 = param_9 + 1;
                } while (param_9 < param_7);
              }
              param_5 = (int *)param_5[0x14];
              param_4 = param_4 + 1;
            } while (param_4 < param_2);
          }
          if ((((local_18 == 0) || (param_7 <= param_3)) ||
              (iVar8 = FUN_008a0971(piVar5,&local_4dc,param_3 - 1,param_12), -1 < iVar8)) &&
             ((local_14 == 0 ||
              (iVar8 = (**(code **)(*param_1 + 0x7c))(param_1,local_10,local_c), -1 < iVar8)))) {
            piVar5 = local_c;
            local_c = (int *)0x0;
            *param_17 = piVar5;
            iVar8 = 0;
          }
        }
      }
      else {
        iVar8 = -0x7789f796;
      }
    }
  }
LAB_008a1454:
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
    local_8 = (int *)0x0;
  }
  if (param_14 != (int *)0x0) {
    (**(code **)(*param_14 + 8))(param_14);
    param_14 = (int *)0x0;
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
    local_c = (int *)0x0;
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
    local_10 = (int *)0x0;
  }
LAB_008a1497:
  FUN_008a1c19();
  return iVar8;
}


// ==== FUN_008a14d8 @ 0x008a14d8 ====

void FUN_008a14d8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14,undefined4 param_15)

{
  FUN_008a0c63(param_1,param_2,param_3,param_4,param_5,1,param_6,param_7,param_8,param_9,param_10,
               param_11,param_12,param_13,param_14,3,param_15);
  return;
}


// ==== FUN_008a1517 @ 0x008a1517 ====

void FUN_008a1517(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9,undefined4 param_10,undefined4 param_11,undefined4 param_12,
                 undefined4 param_13,undefined4 param_14)

{
  FUN_008a0c63(param_1,param_2,param_3,param_4,param_4,1,param_5,param_6,param_7,param_8,param_9,
               param_10,param_11,param_12,param_13,5,param_14);
  return;
}


// ==== FUN_008a1556 @ 0x008a1556 ====

void FUN_008a1556(byte param_1)

{
  void *in_ECX;
  
  FUN_008b6b12();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008a1577 @ 0x008a1577 ====

void FUN_008a1577(byte param_1)

{
  void *in_ECX;
  
  FUN_008b8935();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008a1598 @ 0x008a1598 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

uint FUN_008a1598(void)

{
  _OSVERSIONINFOA local_9c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  if (DAT_00b5de84 == 0) {
    DAT_00b5de84 = 1;
    local_9c.dwOSVersionInfoSize = 0x94;
    GetVersionExA(&local_9c);
    DAT_00b5de80 = (uint)(local_9c.dwPlatformId == 2);
  }
  return DAT_00b5de80;
}


// ==== FUN_008a15f7 @ 0x008a15f7 ====

int FUN_008a15f7(int param_1,int *param_2)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  if (param_1 == 0) {
    iVar1 = -0x7789f794;
  }
  else if (param_2 == (int *)0x0) {
    iVar1 = -0x7789f794;
  }
  else {
    pvVar2 = operator_new(0xf0);
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_008b8239();
    }
    if (iVar3 == 0) {
      iVar1 = -0x7ff8fff2;
    }
    else {
      iVar1 = FUN_008b6c26(param_1);
      if (iVar1 < 0) {
        FUN_008a1556(1);
      }
      else {
        *param_2 = iVar3;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ==== FUN_008a1669 @ 0x008a1669 ====

int FUN_008a1669(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  
  if (param_3 == (int *)0x0) {
    iVar1 = -0x7789f794;
  }
  else {
    pvVar2 = operator_new(0x584);
    if (pvVar2 == (void *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = FUN_008b9b47();
    }
    if (iVar3 == 0) {
      iVar1 = -0x7ff8fff2;
    }
    else {
      iVar1 = FUN_008b8afa(param_1,param_2,0);
      if (iVar1 < 0) {
        FUN_008a1577(1);
      }
      else {
        *param_3 = iVar3;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}


// ==== FUN_008a16d3 @ 0x008a16d3 ====

int FUN_008a16d3(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 *param_6,undefined4 *param_7)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_8;
  
  piVar4 = (int *)0x0;
  local_8 = 0;
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  if ((param_1 == 0) || (param_6 == (undefined4 *)0x0)) {
    iVar3 = -0x7789f794;
  }
  else {
    pvVar1 = operator_new(0x360);
    if (pvVar1 == (void *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = (int *)FUN_008c84e1();
    }
    if (piVar4 == (int *)0x0) {
      iVar3 = -0x7ff8fff2;
      goto LAB_008a17c9;
    }
    iVar3 = FUN_008c1604(param_1,param_2,param_3,param_4);
    if (-1 < iVar3) {
      iVar3 = FUN_008d4d44(piVar4 + 4,param_5,&local_8);
      if (-1 < iVar3) {
        iVar3 = FUN_008bcde3();
        if (iVar3 == 0) {
          iVar3 = FUN_008c9274(local_8);
          if (-1 < iVar3) {
            local_8 = 0;
            iVar2 = FUN_008bcde3();
            if (iVar2 != 0) goto LAB_008a1773;
            *param_6 = piVar4;
            (**(code **)(*piVar4 + 4))(piVar4);
          }
        }
        else {
LAB_008a1773:
          iVar3 = -0x7789f4a7;
        }
      }
    }
  }
  if (piVar4 != (int *)0x0) {
    FUN_008bf855();
    if (param_7 != (undefined4 *)0x0) {
      FUN_008bcd75(param_7);
    }
  }
LAB_008a17c9:
  if (local_8 != 0) {
    local_8 = 0;
  }
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  return iVar3;
}


// ==== FUN_008a17e4 @ 0x008a17e4 ====

int FUN_008a17e4(int param_1,int *param_2,uint param_3,undefined4 param_4,undefined4 param_5,
                uint param_6,undefined4 param_7,undefined4 *param_8,int *param_9)

{
  undefined4 *puVar1;
  void *pvVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  int *local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  piVar6 = param_9;
  puVar1 = param_8;
  local_8 = 0;
  local_14 = (int *)0x0;
  local_10 = (int *)0x0;
  local_c = (int *)0x0;
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = 0;
  }
  if (param_9 != (int *)0x0) {
    *param_9 = 0;
  }
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    local_8 = -0x7789f794;
    goto LAB_008a1946;
  }
  pvVar2 = operator_new(0x130);
  if (pvVar2 == (void *)0x0) {
    local_10 = (int *)0x0;
  }
  else {
    local_10 = (int *)FUN_008df4d1();
  }
  uVar4 = param_6;
  uVar5 = param_3;
  if (local_10 == (int *)0x0) {
    local_8 = -0x7ff8fff2;
    goto LAB_008a1953;
  }
  if (param_3 < 4) {
    local_8 = -0x7fffbffb;
    goto LAB_008a1953;
  }
  if (*param_2 == -0x100f6ff) {
    if ((puVar1 == (undefined4 *)0x0) ||
       (local_8 = FUN_008eb3df(param_3,&local_c), piVar6 = param_2, local_8 < 0)) goto LAB_008a1953;
    piVar3 = (int *)(**(code **)(*local_c + 0xc))(local_c);
    for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *piVar3 = *piVar6;
      piVar6 = piVar6 + 1;
      piVar3 = piVar3 + 1;
    }
    for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
      *(char *)piVar3 = (char)*piVar6;
      piVar6 = (int *)((int)piVar6 + 1);
      piVar3 = (int *)((int)piVar3 + 1);
    }
LAB_008a18fe:
    piVar6 = local_10;
    puVar1 = param_8;
    if (param_8 != (undefined4 *)0x0) {
      param_2 = (int *)0x0;
      local_8 = FUN_008e9b1a(param_1,param_7,local_c,&param_2);
      if ((-1 < local_8) && (local_8 = FUN_008e5464(), -1 < local_8)) {
        *puVar1 = piVar6;
        (**(code **)(*piVar6 + 4))(piVar6);
      }
    }
  }
  else {
    local_8 = FUN_008a16d3(param_2,param_3,param_4,param_5,param_6,&local_14,piVar6);
    if (-1 < local_8) {
      if ((piVar6 != (int *)0x0) && (piVar3 = (int *)*piVar6, piVar3 != (int *)0x0)) {
        (**(code **)(*piVar3 + 8))(piVar3);
        *piVar6 = 0;
      }
      local_8 = (**(code **)(*local_14 + 0xf4))(local_14,uVar4 & 0xffffffe7,&local_c,piVar6);
      if (-1 < local_8) goto LAB_008a18fe;
    }
  }
LAB_008a1946:
  if (local_14 != (int *)0x0) {
    (**(code **)(*local_14 + 8))(local_14);
  }
LAB_008a1953:
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
    local_c = (int *)0x0;
  }
  if (local_10 != (int *)0x0) {
    (**(code **)(*local_10 + 8))(local_10);
  }
  return local_8;
}


// ==== FUN_008a197b @ 0x008a197b ====

void FUN_008a197b(void)

{
  int in_ECX;
  
  FUN_008b64c2();
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  return;
}


// ==== FUN_008a199a @ 0x008a199a ====

int FUN_008a199a(undefined4 *param_1,int param_2)

{
  int iVar1;
  void *pvVar2;
  int in_ECX;
  undefined4 uVar3;
  
  uVar3 = 1;
  if ((param_2 == 0) || (param_2 == 1)) {
    pvVar2 = operator_new(0x10000);
    *(void **)(in_ECX + 0x18) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      return -0x7ff8fff2;
    }
    iVar1 = FUN_008b663e(param_1,param_2 == 1);
    if (iVar1 < 0) {
      return iVar1;
    }
  }
  else {
    uVar3 = 2;
    if (param_2 != 2) {
      return -0x7fffbffb;
    }
    iVar1 = FUN_008eb37d(0x400,param_1);
    if (iVar1 < 0) {
      return iVar1;
    }
    *(undefined4 *)(in_ECX + 0x14) = *param_1;
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  return 0;
}


// ==== FUN_008a1a14 @ 0x008a1a14 ====

int FUN_008a1a14(undefined4 *param_1,uint param_2,LPDWORD param_3)

{
  uint uVar1;
  int iVar2;
  BOOL BVar3;
  DWORD nNumberOfBytesToWrite;
  undefined4 *in_ECX;
  undefined4 *puVar4;
  undefined4 *puVar5;
  uint local_8;
  
  local_8 = 0;
  iVar2 = in_ECX[4];
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      iVar2 = in_ECX[7];
      if (iVar2 + param_2 < 0x10001) {
        puVar4 = (undefined4 *)(in_ECX[6] + iVar2);
        for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
          *puVar4 = *param_1;
          param_1 = param_1 + 1;
          puVar4 = puVar4 + 1;
        }
        for (uVar1 = param_2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
          *(undefined1 *)puVar4 = *(undefined1 *)param_1;
          param_1 = (undefined4 *)((int)param_1 + 1);
          puVar4 = (undefined4 *)((int)puVar4 + 1);
        }
        in_ECX[7] = in_ECX[7] + param_2;
      }
      else {
        if ((iVar2 != 0x10000) && (iVar2 != 0)) {
          puVar4 = param_1;
          puVar5 = (undefined4 *)(in_ECX[6] + iVar2);
          for (uVar1 = 0x10000U - iVar2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          for (uVar1 = 0x10000U - iVar2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
            *(undefined1 *)puVar5 = *(undefined1 *)puVar4;
            puVar4 = (undefined4 *)((int)puVar4 + 1);
            puVar5 = (undefined4 *)((int)puVar5 + 1);
          }
          iVar2 = in_ECX[7];
          param_1 = (undefined4 *)((int)param_1 + (0x10000 - iVar2));
        }
        if (iVar2 != 0) {
          BVar3 = WriteFile((HANDLE)*in_ECX,(LPCVOID)in_ECX[6],0x10000,param_3,(LPOVERLAPPED)0x0);
          if (BVar3 == 0) {
            return -0x7fffbffb;
          }
          in_ECX[8] = in_ECX[8] + 0x10000;
          local_8 = 0x10000 - in_ECX[7];
          in_ECX[7] = 0;
        }
        uVar1 = param_2 - local_8 >> 0x10;
        if (uVar1 != 0) {
          nNumberOfBytesToWrite = uVar1 * 0x10000;
          BVar3 = WriteFile((HANDLE)*in_ECX,param_1,nNumberOfBytesToWrite,param_3,(LPOVERLAPPED)0x0)
          ;
          if (BVar3 == 0) {
            return -0x7fffbffb;
          }
          in_ECX[8] = in_ECX[8] + nNumberOfBytesToWrite;
          local_8 = local_8 + nNumberOfBytesToWrite;
          param_1 = param_1 + uVar1 * 0x4000;
        }
        if (local_8 < param_2) {
          local_8 = param_2 - local_8;
          puVar4 = (undefined4 *)in_ECX[6];
          for (uVar1 = local_8 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
            *puVar4 = *param_1;
            param_1 = param_1 + 1;
            puVar4 = puVar4 + 1;
          }
          for (uVar1 = local_8 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
            *(undefined1 *)puVar4 = *(undefined1 *)param_1;
            param_1 = (undefined4 *)((int)param_1 + 1);
            puVar4 = (undefined4 *)((int)puVar4 + 1);
          }
          in_ECX[7] = local_8;
        }
      }
      *param_3 = param_2;
    }
    else {
      if (iVar2 != 2) {
        return -0x7fffbffb;
      }
      uVar1 = (**(code **)(*(int *)in_ECX[5] + 0x10))((int *)in_ECX[5]);
      if (uVar1 < in_ECX[8] + param_2) {
        uVar1 = in_ECX[8] + param_2;
        iVar2 = (**(code **)(*(int *)in_ECX[5] + 0x10))((int *)in_ECX[5]);
        if (uVar1 <= (uint)(iVar2 * 2)) {
          iVar2 = (**(code **)(*(int *)in_ECX[5] + 0x10))((int *)in_ECX[5]);
          uVar1 = iVar2 << 1;
        }
        iVar2 = FUN_008eb29f(uVar1);
        if (iVar2 < 0) {
          return iVar2;
        }
      }
      iVar2 = (**(code **)(*(int *)in_ECX[5] + 0xc))((int *)in_ECX[5]);
      puVar4 = (undefined4 *)(iVar2 + in_ECX[8]);
      for (uVar1 = param_2 >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
        *puVar4 = *param_1;
        param_1 = param_1 + 1;
        puVar4 = puVar4 + 1;
      }
      for (uVar1 = param_2 & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
        *(undefined1 *)puVar4 = *(undefined1 *)param_1;
        param_1 = (undefined4 *)((int)param_1 + 1);
        puVar4 = (undefined4 *)((int)puVar4 + 1);
      }
      *param_3 = param_2;
      in_ECX[8] = in_ECX[8] + param_2;
    }
  }
  return 0;
}


// ==== FUN_008a1bb6 @ 0x008a1bb6 ====

undefined4 FUN_008a1bb6(void)

{
  int iVar1;
  BOOL BVar2;
  undefined4 *in_ECX;
  DWORD local_8;
  
  iVar1 = in_ECX[4];
  if (iVar1 != 0) {
    if (iVar1 == 1) {
      if (in_ECX[7] != 0) {
        BVar2 = WriteFile((HANDLE)*in_ECX,(LPCVOID)in_ECX[6],in_ECX[7],&local_8,(LPOVERLAPPED)0x0);
        if (BVar2 == 0) {
          return 0x80004005;
        }
        in_ECX[8] = in_ECX[8] + in_ECX[7];
        in_ECX[7] = 0;
      }
    }
    else if (iVar1 != 2) {
      return 0x80004005;
    }
  }
  return 0;
}


// ==== FUN_008a1c00 @ 0x008a1c00 ====

void FUN_008a1c00(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  return;
}


// ==== FUN_008a1c19 @ 0x008a1c19 ====

void FUN_008a1c19(void)

{
  void *pvVar1;
  int in_ECX;
  
  if ((*(void **)(in_ECX + 4) != (void *)0x0) && (*(int *)(in_ECX + 0x38) != 0)) {
    _free(*(void **)(in_ECX + 4));
    return;
  }
  if ((*(void **)(in_ECX + 8) != (void *)0x0) && (*(int *)(in_ECX + 0x3c) != 0)) {
    _free(*(void **)(in_ECX + 8));
    return;
  }
  pvVar1 = *(void **)(in_ECX + 0x4c);
  if (pvVar1 != (void *)0x0) {
    FUN_008a1c19();
    _free(pvVar1);
    return;
  }
  pvVar1 = *(void **)(in_ECX + 0x50);
  if (pvVar1 == (void *)0x0) {
    return;
  }
  FUN_008a1c19();
  _free(pvVar1);
  return;
}


// ==== FUN_008a1c74 @ 0x008a1c74 ====

void FUN_008a1c74(byte param_1)

{
  void *in_ECX;
  
  FUN_008a1c19();
  if ((param_1 & 1) == 0) {
    return;
  }
  _free(in_ECX);
  return;
}


// ==== FUN_008a1c95 @ 0x008a1c95 ====

undefined4 FUN_008a1c95(int *param_1)

{
  uint *puVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int *in_ECX;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  
  if (((void *)in_ECX[1] != (void *)0x0) && (in_ECX[0xe] != 0)) {
    _free((void *)in_ECX[1]);
    return extraout_EAX;
  }
  if (((void *)in_ECX[2] != (void *)0x0) && (in_ECX[0xf] != 0)) {
    _free((void *)in_ECX[2]);
    return extraout_EAX_00;
  }
  *in_ECX = param_1[1];
  in_ECX[1] = *param_1;
  in_ECX[2] = param_1[0x14];
  puVar1 = (uint *)(in_ECX + 6);
  puVar3 = (uint *)(param_1 + 10);
  puVar4 = puVar1;
  for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  in_ECX[0xc] = param_1[2];
  in_ECX[0xd] = param_1[3];
  iVar2 = *in_ECX;
  if (iVar2 < 0x34545845) {
    if (((iVar2 != 0x34545844) && (iVar2 != 0x31545844)) && (iVar2 != 0x32545844)) {
      if (iVar2 == 0x32595559) goto LAB_008a1d6a;
      if (iVar2 != 0x33545844) goto LAB_008a1d25;
    }
  }
  else if (iVar2 != 0x35545844) {
    if (((iVar2 != 0x42475247) && (iVar2 != 0x47424752)) && (iVar2 != 0x59565955))
    goto LAB_008a1d25;
LAB_008a1d6a:
    *puVar1 = *puVar1 & 0xfffffffe;
    goto LAB_008a1d25;
  }
  *puVar1 = *puVar1 & 0xfffffffc;
  in_ECX[7] = in_ECX[7] & 0xfffffffc;
LAB_008a1d25:
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  in_ECX[3] = in_ECX[8] - *puVar1;
  in_ECX[4] = in_ECX[9] - in_ECX[7];
  in_ECX[5] = in_ECX[0xb] - in_ECX[10];
  return 0;
}


// ==== FUN_008a1d6f @ 0x008a1d6f ====

uint FUN_008a1d6f(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_2 != 0) {
    do {
      if (*(char *)(uVar1 + param_1) == '\n') {
        return uVar1;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < param_2);
  }
  return 0;
}


// ==== FUN_008a1d90 @ 0x008a1d90 ====

float10 FUN_008a1d90(uint param_1)

{
  return (float10)(float)(((param_1 & 0xff00) + param_1 * 0x10000) * 0x100 +
                          (param_1 >> 0x10 & 0xff) * 0x100 + (param_1 >> 0x18));
}


// ==== FUN_008a1dc0 @ 0x008a1dc0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008a1dc0(uint *param_1,byte *param_2)

{
  undefined1 uVar1;
  byte bVar2;
  ushort uVar3;
  short sVar4;
  float fVar5;
  uint uVar6;
  void *pvVar7;
  undefined1 *puVar8;
  uint3 *puVar9;
  byte bVar10;
  int *in_ECX;
  int iVar11;
  byte *pbVar12;
  byte *pbVar13;
  uint *puVar14;
  byte *pbVar15;
  ushort *puVar16;
  uint3 *puVar17;
  uint uVar18;
  byte *pbVar19;
  int local_98 [4];
  uint local_88;
  int local_84;
  int local_80;
  undefined2 local_7c;
  undefined2 local_7a;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  float local_60 [4];
  uint local_50 [4];
  uint3 *local_40;
  uint3 *local_3c;
  uint *local_38;
  uint local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  byte *local_24;
  uint local_20;
  byte *local_1c;
  byte *local_18;
  uint local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  if (param_2 < 4) {
    return 0x80004005;
  }
  uVar18 = *param_1;
  local_38 = param_1;
  if (param_2 < uVar18) {
    return 0x80004005;
  }
  if (uVar18 == 0xc) {
    local_84 = (int)(short)param_1[1];
    local_80 = (int)*(short *)((int)param_1 + 6);
    local_7c = (short)param_1[2];
    local_88 = 0xc;
    local_7a = *(undefined2 *)((int)param_1 + 10);
    local_78 = 0;
    local_74 = 0;
    local_70 = 0;
    local_6c = 0;
    local_68 = 0;
    local_64 = 0;
    local_38 = &local_88;
    puVar14 = &local_88;
  }
  else {
    puVar14 = param_1;
    if (uVar18 < 0x28) {
      return 0x80004005;
    }
  }
  local_20 = puVar14[1];
  local_30 = puVar14[2];
  if ((int)local_30 < 1) {
    local_30 = -local_30;
  }
  uVar18 = *puVar14;
  uVar3 = *(ushort *)((int)puVar14 + 0xe);
  uVar6 = puVar14[8];
  local_c = (uVar18 != 0xc) + 3;
  if ((uVar3 < 9) && (uVar6 == 0)) {
    uVar6 = 1 << ((byte)uVar3 & 0x1f);
  }
  local_24 = (byte *)(local_c * uVar6 + uVar18);
  if (param_2 < local_24) {
    return 0x80004005;
  }
  if ((short)puVar14[3] != 1) {
    return 0x80004005;
  }
  if (puVar14[4] < 3) {
    local_2c = (uint)uVar3;
    if (((local_2c == 1) || (local_2c == 4)) || (local_2c == 8)) {
      local_8 = 0x29;
      goto LAB_008a222b;
    }
    if (local_2c == 0x10) goto LAB_008a213d;
    if (local_2c == 0x18) goto LAB_008a20b1;
    if (local_2c != 0x20) {
      return 0x80004005;
    }
  }
  else {
    if (puVar14[4] != 3) {
      return 0x80004005;
    }
    if (uVar18 < 0x34) {
      return 0x80004005;
    }
    local_14 = puVar14[0xb];
    local_34 = puVar14[0xc];
    local_10 = puVar14[10];
    if (uVar18 < 0x38) {
      local_28 = 0;
    }
    else {
      local_28 = puVar14[0xd];
    }
    local_2c = (uint)*(ushort *)((int)puVar14 + 0xe);
    local_8 = 0x74;
    if (local_2c == 0x10) {
      if (local_34 == 0xff) {
        if (((local_14 == 0xff) && (local_10 == 0xff)) && (local_28 == 0xff00)) {
          local_8 = 0x33;
        }
        goto LAB_008a222b;
      }
      if (local_34 != 0x1f) {
        if (local_34 == 0xf) {
          if ((local_14 == 0xf0) && (local_10 == 0xf00)) {
            if (local_28 == 0xf000) {
              local_8 = 0x1a;
            }
            else if (local_28 == 0) {
              local_8 = 0x1e;
            }
          }
        }
        else if (local_34 == 3) {
          if (((local_14 == 0x1c) && (local_10 == 0xe0)) && (local_28 == 0xff00)) {
            local_8 = 0x1d;
          }
        }
        else if (((local_34 == 0xffff) && (local_14 == 0xffff)) &&
                ((local_10 == 0xffff && (local_28 == 0)))) {
          local_8 = 0x51;
        }
        goto LAB_008a222b;
      }
      if (local_14 == 0x7e0) {
        if ((local_10 == 0xf800) && (local_28 == 0)) {
          local_8 = 0x17;
        }
        goto LAB_008a222b;
      }
      if ((local_14 != 0x3e0) || (local_10 != 0x7c00)) goto LAB_008a222b;
      if (local_28 != 0) {
        if (local_28 == 0x8000) {
          local_8 = 0x19;
        }
        goto LAB_008a222b;
      }
LAB_008a213d:
      local_8 = 0x18;
      goto LAB_008a222b;
    }
    if (local_2c == 0x18) {
      if ((((local_34 != 0xff) || (local_14 != 0xff00)) || (local_10 != 0xff0000)) ||
         (local_28 != 0)) goto LAB_008a222b;
LAB_008a20b1:
      local_8 = 0x14;
      goto LAB_008a222b;
    }
    if (local_2c != 0x20) {
      return 0x80004005;
    }
    if (local_34 != 0xff) {
      if (local_34 == 0x3ff00000) {
        if (((local_14 == 0xffc00) && (local_10 == 0x3ff)) && (local_28 == 0xc0000000)) {
          local_8 = 0x1f;
        }
      }
      else if (local_34 == 0xff0000) {
        if ((local_14 == 0xff00) && (local_10 == 0xff)) {
          if (local_28 == 0xff000000) {
            local_8 = 0x20;
          }
          else if (local_28 == 0) {
            local_8 = 0x21;
          }
        }
      }
      else if (local_34 == 0) {
        if (((local_14 == 0xffff0000) && (local_10 == 0xffff)) && (local_28 == 0)) {
          local_8 = 0x22;
        }
      }
      else if (local_34 == 0x3ff) {
        if (((local_14 == 0xffc00) && (local_10 == 0x3ff00000)) && (local_28 == 0xc0000000)) {
          local_8 = 0x23;
        }
      }
      else if (((local_34 == 0xff00) && (local_14 == 0xff0000)) &&
              ((local_10 == 0xff000000 && (local_28 == 0)))) {
        local_8 = 0x16;
        local_24 = (byte *)((int)local_24 + 1);
      }
      goto LAB_008a222b;
    }
    if ((local_14 != 0xff00) || (local_10 != 0xff0000)) goto LAB_008a222b;
    if (local_28 != 0) {
      if (local_28 == 0xff000000) {
        local_8 = 0x15;
      }
      goto LAB_008a222b;
    }
  }
  local_8 = 0x16;
LAB_008a222b:
  local_38 = puVar14;
  if ((in_ECX[0x10] != 0) && (local_8 == 0x29)) {
    uVar18 = puVar14[8];
    if (uVar18 == 0) {
      uVar18 = 1 << ((byte)local_2c & 0x1f);
    }
    in_ECX[0xf] = 1;
    pvVar7 = operator_new(0x400);
    in_ECX[2] = (int)pvVar7;
    if (pvVar7 == (void *)0x0) {
      return 0x8007000e;
    }
    puVar8 = (undefined1 *)(*puVar14 + (int)param_1);
    local_18 = (byte *)0x0;
    if (uVar18 != 0) {
      do {
        iVar11 = (int)local_18 * 4;
        *(undefined1 *)(iVar11 + in_ECX[2]) = puVar8[2];
        *(undefined1 *)(iVar11 + 1 + in_ECX[2]) = puVar8[1];
        uVar1 = *puVar8;
        puVar8 = puVar8 + local_c;
        local_18 = (byte *)((int)local_18 + 1);
        *(undefined1 *)(iVar11 + 2 + in_ECX[2]) = uVar1;
        *(undefined1 *)(iVar11 + 3 + in_ECX[2]) = 0xff;
        puVar14 = local_38;
      } while (local_18 < uVar18);
    }
    for (; uVar18 < 0x100; uVar18 = uVar18 + 1) {
      iVar11 = uVar18 * 4;
      *(undefined1 *)(iVar11 + in_ECX[2]) = 0xff;
      *(undefined1 *)(iVar11 + 1 + in_ECX[2]) = 0xff;
      *(undefined1 *)(iVar11 + 2 + in_ECX[2]) = 0xff;
      *(undefined1 *)(iVar11 + 3 + in_ECX[2]) = 0xff;
    }
  }
  uVar3 = *(ushort *)((int)puVar14 + 0xe);
  if (uVar3 == 1) {
    local_18 = (byte *)local_20;
    uVar18 = local_20 + 7 >> 3;
  }
  else if (uVar3 == 4) {
    local_18 = (byte *)local_20;
    uVar18 = local_20 + 1 >> 1;
  }
  else {
    uVar18 = (uVar3 >> 3) * local_20;
    local_18 = (byte *)uVar18;
  }
  if (local_8 == 0x74) {
    local_18 = (byte *)(local_20 << 4);
  }
  local_2c = uVar18 + 3 & 0xfffffffc;
  if (((puVar14[4] == 0) || (puVar14[4] == 3)) &&
     (param_2 < (local_30 - 1) * local_2c + uVar18 + (int)local_24)) {
    return 0x80004005;
  }
  if (((puVar14[4] == 0) && (local_8 == 0x16)) && (local_1c = (byte *)0x0, local_30 != 0)) {
    local_c = (int)local_24 + (int)param_1;
    do {
      uVar18 = 0;
      if (local_20 != 0) {
        do {
          if (*(char *)(local_c + 3 + uVar18 * 4) != '\0') {
            local_8 = 0x15;
            break;
          }
          uVar18 = uVar18 + 1;
        } while (uVar18 < local_20);
        if (uVar18 < local_20) break;
      }
      local_1c = (byte *)((int)local_1c + 1);
      local_c = local_c + local_2c;
    } while (local_1c < local_30);
  }
  in_ECX[0xd] = 0;
  uVar18 = (int)local_18 + 3U & 0xfffffffc;
  *in_ECX = local_8;
  in_ECX[0xc] = uVar18;
  in_ECX[3] = local_20;
  in_ECX[4] = local_30;
  in_ECX[5] = 1;
  if (in_ECX[0x10] != 0) {
    if (((puVar14[4] == 0) || (puVar14[4] == 3)) &&
       (((int)puVar14[2] < 0 && ((7 < *(ushort *)((int)puVar14 + 0xe) && (local_8 != 0x74)))))) {
      in_ECX[0xe] = 0;
      in_ECX[1] = (int)local_24 + (int)param_1;
    }
    else {
      in_ECX[0xe] = 1;
      local_1c = operator_new(uVar18 * local_30);
      in_ECX[1] = (int)local_1c;
      if (local_1c == (byte *)0x0) {
        return 0x8007000e;
      }
      iVar11 = in_ECX[0xc];
      local_40 = (uint3 *)((int)local_24 + (int)param_1);
      local_24 = (byte *)((int)param_1 + (int)param_2);
      local_3c = local_40;
      if ((int)puVar14[2] < 0) {
        local_c = iVar11;
        pbVar12 = local_1c;
      }
      else {
        local_c = -iVar11;
        pbVar12 = local_1c + (local_30 - 1) * iVar11;
      }
      pbVar15 = local_1c + iVar11 * local_30;
      puVar9 = local_40;
      param_2 = pbVar12;
      if (puVar14[4] == 2) {
        while ((local_1c <= param_2 && (param_2 < pbVar15))) {
          if (puVar9 < local_40) {
            return 0x80004005;
          }
          pbVar13 = (byte *)((int)puVar9 + 1);
          if (local_24 <= pbVar13) {
            return 0x80004005;
          }
          bVar10 = (byte)*puVar9;
          if (bVar10 == 0) {
            bVar10 = *pbVar13;
            uVar18 = (uint)bVar10;
            if (bVar10 == 0) {
              pbVar12 = param_2 + local_c;
              param_2 = pbVar12;
            }
            else if (uVar18 == 1) {
              param_2 = pbVar15;
            }
            else if (uVar18 == 2) {
              pbVar13 = (byte *)((int)puVar9 + 3);
              if (local_24 <= pbVar13) {
                return 0x80004005;
              }
              puVar9 = (uint3 *)((int)puVar9 + 2);
              pbVar12 = pbVar12 + (uint)*pbVar13 * local_c + (uint)*(byte *)puVar9;
            }
            else {
              if (pbVar12 < local_1c) {
                return 0x80004005;
              }
              if (pbVar15 < pbVar12 + uVar18) {
                return 0x80004005;
              }
              if ((bVar10 != 0) &&
                 (local_24 <= (byte *)(((int)(uVar18 - 1) >> 1) + 2 + (int)puVar9))) {
                return 0x80004005;
              }
              uVar18 = 0;
              if (bVar10 != 0) {
                do {
                  bVar10 = *(byte *)(((int)uVar18 >> 1) + 2 + (int)puVar9);
                  if ((uVar18 & 1) == 0) {
                    bVar10 = bVar10 >> 4;
                  }
                  else {
                    bVar10 = bVar10 & 0xf;
                  }
                  pbVar12[uVar18] = bVar10;
                  uVar18 = uVar18 + 1;
                } while ((int)uVar18 < (int)(uint)*pbVar13);
              }
              pbVar12 = pbVar12 + *pbVar13;
              puVar9 = (uint3 *)((int)puVar9 + ((*pbVar13 >> 1) + 1 & 0xfffffffe));
            }
          }
          else {
            if (pbVar12 < local_1c) {
              return 0x80004005;
            }
            if (pbVar15 < pbVar12 + bVar10) {
              return 0x80004005;
            }
            uVar18 = 0;
            if (bVar10 != 0) {
              do {
                if ((uVar18 & 1) == 0) {
                  bVar10 = *pbVar13 >> 4;
                }
                else {
                  bVar10 = *pbVar13 & 0xf;
                }
                pbVar12[uVar18] = bVar10;
                uVar18 = uVar18 + 1;
              } while ((int)uVar18 < (int)(uint)(byte)*puVar9);
            }
            pbVar12 = pbVar12 + (byte)*puVar9;
          }
          puVar9 = (uint3 *)((int)puVar9 + 2);
        }
      }
      else if (puVar14[4] == 1) {
        while ((local_1c <= param_2 && (param_2 < pbVar15))) {
          if (puVar9 < local_40) {
            return 0x80004005;
          }
          pbVar13 = (byte *)((int)puVar9 + 1);
          if (local_24 <= pbVar13) {
            return 0x80004005;
          }
          bVar10 = (byte)*puVar9;
          if (bVar10 == 0) {
            uVar18 = (uint)*pbVar13;
            if (uVar18 == 0) {
              pbVar12 = param_2 + local_c;
              param_2 = pbVar12;
            }
            else if (uVar18 == 1) {
              param_2 = pbVar15;
            }
            else {
              if (uVar18 != 2) {
                if (pbVar12 < local_1c) {
                  return 0x80004005;
                }
                if (pbVar15 < pbVar12 + uVar18) {
                  return 0x80004005;
                }
                if (local_24 < (byte *)(uVar18 + 2 + (int)puVar9)) {
                  return 0x80004005;
                }
                uVar6 = (uint)(*pbVar13 >> 2);
                puVar16 = (ushort *)((int)puVar9 + 2);
                pbVar13 = pbVar12;
                for (; uVar6 != 0; uVar6 = uVar6 - 1) {
                  *(undefined4 *)pbVar13 = *(undefined4 *)puVar16;
                  puVar16 = puVar16 + 2;
                  pbVar13 = pbVar13 + 4;
                }
                for (uVar18 = uVar18 & 3; uVar18 != 0; uVar18 = uVar18 - 1) {
                  *pbVar13 = (byte)*puVar16;
                  puVar16 = (ushort *)((int)puVar16 + 1);
                  pbVar13 = pbVar13 + 1;
                }
                uVar18 = (uint)*(byte *)((int)puVar9 + 1);
                puVar9 = (uint3 *)((int)puVar9 + (uVar18 + 1 & 0xfffffffe));
                goto LAB_008a26a0;
              }
              pbVar13 = (byte *)((int)puVar9 + 3);
              if (local_24 <= pbVar13) {
                return 0x80004005;
              }
              puVar9 = (uint3 *)((int)puVar9 + 2);
              pbVar12 = pbVar12 + (uint)*pbVar13 * local_c + (uint)*(byte *)puVar9;
            }
          }
          else {
            if (pbVar12 < local_1c) {
              return 0x80004005;
            }
            if (pbVar15 < pbVar12 + bVar10) {
              return 0x80004005;
            }
            bVar2 = *pbVar13;
            pbVar13 = pbVar12;
            for (uVar18 = (uint)(bVar10 >> 2); uVar18 != 0; uVar18 = uVar18 - 1) {
              *(uint *)pbVar13 = CONCAT22(CONCAT11(bVar2,bVar2),CONCAT11(bVar2,bVar2));
              pbVar13 = pbVar13 + 4;
            }
            for (uVar18 = bVar10 & 3; uVar18 != 0; uVar18 = uVar18 - 1) {
              *pbVar13 = bVar2;
              pbVar13 = pbVar13 + 1;
            }
            uVar18 = (uint)(byte)*puVar9;
LAB_008a26a0:
            pbVar12 = pbVar12 + uVar18;
          }
          puVar9 = (uint3 *)((int)puVar9 + 2);
        }
      }
      else if (*(short *)((int)puVar14 + 0xe) == 1) {
        for (; (local_1c <= pbVar12 && (pbVar12 < pbVar15)); pbVar12 = pbVar12 + local_c) {
          param_2 = (byte *)0x0;
          if (local_20 != 0) {
            do {
              pbVar12[(int)param_2] =
                   *(byte *)(((uint)param_2 >> 3) + (int)local_40) >>
                   (7 - ((byte)param_2 & 7) & 0x1f) & 1;
              param_2 = (byte *)((int)param_2 + 1);
            } while (param_2 < local_20);
          }
          local_40 = (uint3 *)((int)local_40 + local_2c);
        }
      }
      else if (*(short *)((int)puVar14 + 0xe) == 4) {
        for (; (local_1c <= pbVar12 && (pbVar12 < pbVar15)); pbVar12 = pbVar12 + local_c) {
          uVar18 = 0;
          if (local_20 != 0) {
            do {
              bVar10 = *(byte *)((uVar18 >> 1) + (int)local_40);
              if ((uVar18 & 1) == 0) {
                bVar10 = bVar10 >> 4;
              }
              else {
                bVar10 = bVar10 & 0xf;
              }
              pbVar12[uVar18] = bVar10;
              uVar18 = uVar18 + 1;
            } while (uVar18 < local_20);
          }
          local_40 = (uint3 *)((int)local_40 + local_2c);
        }
      }
      else if (local_8 == 0x74) {
        local_50[0] = local_10;
        local_50[1] = local_14;
        local_50[2] = local_34;
        local_50[3] = local_28;
        uVar18 = 0;
        do {
          puVar14 = (uint *)((int)local_50 + uVar18);
          *(int *)((int)local_98 + uVar18) = 0;
          if (*puVar14 != 0) {
            if ((*puVar14 & 1) == 0) {
              iVar11 = 0;
              do {
                *puVar14 = *puVar14 >> 1;
                iVar11 = iVar11 + 1;
              } while ((*puVar14 & 1) == 0);
              *(int *)((int)local_98 + uVar18) = iVar11;
            }
            param_2 = (byte *)*puVar14;
            fVar5 = (float)(int)param_2;
            if ((int)param_2 < 0) {
              fVar5 = fVar5 + _DAT_0099d104;
            }
            *(float *)((int)local_60 + uVar18) = DAT_0099d080 / fVar5;
          }
          uVar18 = uVar18 + 4;
        } while (uVar18 < 0x10);
        if (((local_10 == 0) && (local_14 == 0)) && (local_34 == 0)) {
          local_60[2] = 0.0;
          local_50[2] = 1;
          local_50[1] = 1;
          local_60[1] = 0.0;
          local_50[0] = 1;
          local_60[0] = 0.0;
        }
        for (; (local_1c <= pbVar12 && (pbVar12 < pbVar15)); pbVar12 = pbVar12 + local_c) {
          local_18 = pbVar12;
          if (local_20 != 0) {
            local_34 = local_20;
            puVar9 = local_40;
            do {
              sVar4 = *(short *)((int)local_38 + 0xe);
              if (sVar4 == 0x10) {
                param_2 = (byte *)(uint)(ushort)*puVar9;
                puVar9 = (uint3 *)((int)puVar9 + 2);
              }
              else if (sVar4 == 0x18) {
                param_2 = (byte *)(uint)*puVar9;
                puVar9 = (uint3 *)((int)puVar9 + 3);
              }
              else if (sVar4 == 0x20) {
                param_2 = *(byte **)puVar9;
                puVar9 = puVar9 + 1;
              }
              uVar18 = 0;
              do {
                if (*(int *)((int)local_50 + uVar18) == 0) {
                  fVar5 = 1.0;
                }
                else {
                  local_3c = (uint3 *)((uint)param_2 >>
                                       ((byte)*(undefined4 *)((int)local_98 + uVar18) & 0x1f) &
                                      *(uint *)((int)local_50 + uVar18));
                  fVar5 = (float)(int)local_3c;
                  if ((int)local_3c < 0) {
                    fVar5 = fVar5 + _DAT_0099d104;
                  }
                  fVar5 = fVar5 * *(float *)((int)local_60 + uVar18);
                }
                *(float *)(local_18 + uVar18) = fVar5;
                uVar18 = uVar18 + 4;
              } while (uVar18 < 0x10);
              local_18 = local_18 + 0x10;
              local_34 = local_34 - 1;
            } while (local_34 != 0);
          }
          local_40 = (uint3 *)((int)local_40 + local_2c);
        }
      }
      else {
        while ((local_1c <= pbVar12 && (pbVar12 < pbVar15))) {
          puVar9 = (uint3 *)((int)local_40 + local_2c);
          pbVar13 = pbVar12 + local_c;
          for (uVar18 = (uint)local_18 >> 2; uVar18 != 0; uVar18 = uVar18 - 1) {
            *(undefined4 *)pbVar12 = *(undefined4 *)local_40;
            local_40 = local_40 + 1;
            pbVar12 = pbVar12 + 4;
          }
          uVar18 = (uint)local_18 & 3;
          puVar17 = local_40;
          pbVar19 = pbVar12;
          while( true ) {
            local_40 = puVar9;
            pbVar12 = pbVar13;
            if (uVar18 == 0) break;
            *pbVar19 = (byte)*puVar17;
            uVar18 = uVar18 - 1;
            puVar17 = (uint3 *)((int)puVar17 + 1);
            pbVar19 = pbVar19 + 1;
          }
        }
      }
    }
  }
  return 0;
}


// ==== FUN_008a28f4 @ 0x008a28f4 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008a28f4(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 uVar3;
  int *in_ECX;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  int *piVar8;
  undefined1 local_4a8 [1024];
  undefined2 local_a8;
  int local_a6;
  undefined2 uStack_a2;
  undefined2 uStack_a0;
  int local_9e;
  int local_98;
  uint local_94;
  uint local_90;
  int local_8c [3];
  undefined2 local_80;
  ushort local_7e;
  undefined4 local_7c;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1d;
  undefined4 local_1c;
  int local_18;
  undefined1 local_14 [8];
  uint local_c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_1c = param_1;
  piVar8 = local_8c;
  for (iVar4 = 0x1b; iVar4 != 0; iVar4 = iVar4 + -1) {
    *piVar8 = 0;
    piVar8 = piVar8 + 1;
  }
  iVar4 = *in_ECX;
  uVar6 = 0;
  local_20 = 0;
  local_1f = 0;
  local_1e = 0;
  local_1d = 0;
  local_14[0] = 0;
  local_14[1] = 0x55;
  local_14[2] = 0xaa;
  local_14[3] = 0xff;
  local_14[4] = 0;
  local_14[5] = 0x24;
  local_14[6] = 0x49;
  local_14[7] = 0x6d;
  local_c = 0xffdbb692;
  local_18 = 0;
  if (0x29 < iVar4) {
    if (iVar4 == 0x32) {
      local_8c[0] = 0x28;
      local_7c = 0;
      local_7e = 8;
      local_18 = 0x400;
      uVar6 = 0;
      do {
        iVar4 = uVar6 * 4;
        uVar3 = (undefined1)uVar6;
        local_4a8[iVar4 + 2] = uVar3;
        local_4a8[iVar4 + 1] = uVar3;
        local_4a8[iVar4] = uVar3;
        uVar6 = uVar6 + 1;
        local_4a8[iVar4 + 3] = 0;
      } while (uVar6 < 0x100);
    }
    else {
      if (iVar4 == 0x33) {
        local_64 = 0xff;
        local_60 = 0xff;
        local_5c = 0xff;
        goto LAB_008a2b20;
      }
      if (iVar4 != 0x51) goto switchD_008a2986_caseD_1c;
      local_8c[0] = 0x34;
      local_7c = 3;
      local_7e = 0x10;
      local_64 = 0xffff;
      local_60 = 0xffff;
      local_5c = 0xffff;
    }
    goto LAB_008a2d14;
  }
  if (iVar4 == 0x29) {
    iVar4 = in_ECX[2];
    local_7c = 0;
    puVar7 = (undefined1 *)(iVar4 + 2);
    uVar6 = 0;
    local_8c[0] = 0x28;
    local_7e = 8;
    local_18 = 0x400;
    do {
      iVar1 = uVar6 * 4;
      local_4a8[iVar1 + 2] = *(undefined1 *)(iVar4 + iVar1);
      local_4a8[iVar1 + 1] = puVar7[-1];
      uVar3 = *puVar7;
      uVar6 = uVar6 + 1;
      puVar7 = puVar7 + 4;
      local_4a8[iVar1] = uVar3;
      local_4a8[iVar1 + 3] = 0;
    } while (uVar6 < 0x100);
    goto LAB_008a2d14;
  }
  switch(iVar4) {
  case 0x14:
    local_8c[0] = 0x28;
    local_7c = 0;
    local_7e = 0x18;
    break;
  case 0x15:
  case 0x16:
    local_8c[0] = 0x28;
    local_7c = 0;
    local_7e = 0x20;
    break;
  case 0x17:
    local_8c[0] = 0x34;
    local_7c = 3;
    local_7e = 0x10;
    local_64 = 0xf800;
    local_60 = 0x7e0;
    local_5c = 0x1f;
    break;
  case 0x18:
    local_8c[0] = 0x28;
    local_7c = 0;
    local_7e = 0x10;
    break;
  case 0x19:
    local_8c[0] = 0x38;
    local_7c = 3;
    local_7e = 0x10;
    local_64 = 0x7c00;
    local_60 = 0x3e0;
    local_5c = 0x1f;
    local_58 = 0x8000;
    break;
  case 0x1a:
    local_8c[0] = 0x38;
    local_7c = 3;
    local_7e = 0x10;
    local_64 = 0xf00;
    local_60 = 0xf0;
    local_5c = 0xf;
    local_58 = 0xf000;
    break;
  case 0x1b:
    local_8c[0] = 0x28;
    local_7c = 0;
    local_7e = 8;
    local_18 = 0x400;
    do {
      iVar4 = uVar6 * 4;
      local_4a8[iVar4 + 2] = local_14[(uVar6 >> 5) + 4];
      local_4a8[iVar4 + 1] = local_14[(uVar6 >> 2 & 7) + 4];
      uVar5 = uVar6 & 3;
      uVar6 = uVar6 + 1;
      local_4a8[iVar4] = local_14[uVar5];
      local_4a8[iVar4 + 3] = 0;
    } while (uVar6 < 0x100);
    break;
  default:
    goto switchD_008a2986_caseD_1c;
  case 0x1d:
    local_64 = 0xe0;
    local_60 = 0x1c;
    local_5c = 3;
LAB_008a2b20:
    local_7c = 3;
    local_8c[0] = 0x38;
    local_7e = 0x10;
    local_58 = 0xff00;
    break;
  case 0x1e:
    local_8c[0] = 0x34;
    local_7c = 3;
    local_7e = 0x10;
    local_64 = 0xf00;
    local_60 = 0xf0;
    local_5c = 0xf;
    break;
  case 0x1f:
    local_64 = 0x3ff;
    local_5c = 0x3ff00000;
    goto LAB_008a2bbb;
  case 0x20:
    local_8c[0] = 0x38;
    local_7c = 3;
    local_7e = 0x20;
    local_64 = 0xff;
    local_60 = 0xff00;
    local_5c = 0xff0000;
    local_58 = 0xff000000;
    break;
  case 0x21:
    local_8c[0] = 0x34;
    local_7c = 3;
    local_7e = 0x20;
    local_64 = 0xff;
    local_60 = 0xff00;
    local_5c = 0xff0000;
    break;
  case 0x22:
    local_8c[0] = 0x34;
    local_7c = 3;
    local_7e = 0x20;
    local_64 = 0xffff;
    local_60 = 0xffff0000;
    local_5c = 0;
    break;
  case 0x23:
    local_64 = 0x3ff00000;
    local_5c = 0x3ff;
LAB_008a2bbb:
    local_8c[0] = 0x38;
    local_7c = 3;
    local_7e = 0x20;
    local_60 = 0xffc00;
    local_58 = 0xc0000000;
  }
LAB_008a2d14:
  local_8c[1] = in_ECX[3];
  local_8c[2] = in_ECX[4];
  local_74 = 0xb12;
  local_70 = 0xb12;
  local_c = (uint)(local_7e >> 3);
  local_90 = local_8c[1] * local_c;
  local_94 = local_90 + 3 & 0xfffffffc;
  local_a6 = local_8c[2] * local_94 + local_8c[0] + 0xe + local_18;
  uStack_a2 = 0;
  uStack_a0 = 0;
  iVar4 = (local_a6 + 3U & 0xfffffffc) - local_a6;
  local_a6 = iVar4 + local_a6;
  local_9e = local_8c[0] + 0xe + local_18;
  local_80 = 1;
  local_98 = local_8c[0];
  local_a8 = 0x4d42;
  if (param_2 == 0) {
LAB_008a2dc4:
    if (local_98 != 0) {
      iVar1 = FUN_008a1a14(local_8c,local_98,local_14);
      if (iVar1 < 0) goto switchD_008a2986_caseD_1c;
    }
    if (local_18 != 0) {
      iVar1 = FUN_008a1a14(local_4a8,local_18,local_14);
      if (iVar1 < 0) goto switchD_008a2986_caseD_1c;
    }
    iVar1 = in_ECX[0xc];
    local_c = in_ECX[6] * local_c + in_ECX[7] * iVar1 + in_ECX[1];
    uVar6 = (in_ECX[4] * iVar1 - iVar1) + local_c;
    if (local_c <= uVar6) {
      do {
        iVar1 = FUN_008a1a14(uVar6,local_90,local_14);
        if (iVar1 < 0) goto switchD_008a2986_caseD_1c;
        if (local_90 < local_94) {
          iVar1 = FUN_008a1a14(&local_20,local_94 - local_90,local_14);
          if (iVar1 < 0) goto switchD_008a2986_caseD_1c;
        }
        uVar6 = uVar6 - in_ECX[0xc];
      } while (local_c <= uVar6);
    }
    if (iVar4 != 0) {
      iVar4 = FUN_008a1a14(&local_20,iVar4,local_14);
      if (iVar4 < 0) goto switchD_008a2986_caseD_1c;
    }
    uVar2 = 0;
  }
  else {
    iVar1 = FUN_008a1a14(&local_a8,0xe,local_14);
    if (-1 < iVar1) goto LAB_008a2dc4;
switchD_008a2986_caseD_1c:
    uVar2 = 0x80004005;
  }
  return uVar2;
}


// ==== FUN_008a2ef3 @ 0x008a2ef3 ====

void FUN_008a2ef3(int *param_1)

{
  (**(code **)(*param_1 + 8))(param_1);
                    /* WARNING: Subroutine does not return */
  _longjmp((int *)(*param_1 + 0x84),1);
}


// ==== FUN_008a2f12 @ 0x008a2f12 ====

void FUN_008a2f12(void)

{
  return;
}


// ==== FUN_008a2f15 @ 0x008a2f15 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008a2f15(int *param_1)

{
  undefined1 local_d0 [200];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  (**(code **)(*param_1 + 0xc))(param_1,local_d0);
  return;
}


// ==== FUN_008a2f44 @ 0x008a2f44 ====

undefined4 FUN_008a2f44(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  *puVar1 = puVar1[7];
  puVar1[1] = puVar1[8];
  return 1;
}


// ==== FUN_008a2f61 @ 0x008a2f61 ====

void FUN_008a2f61(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x18);
  *piVar1 = *piVar1 + param_2;
  piVar1[1] = piVar1[1] - param_2;
  return;
}


// ==== FUN_008a2f78 @ 0x008a2f78 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008a2f78(int param_1,int param_2)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  uint *puVar3;
  undefined1 uVar4;
  int iVar5;
  void *pvVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  int *in_ECX;
  uint uVar9;
  undefined4 uVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  uint *puVar13;
  undefined4 *puVar14;
  code *local_2a4 [2];
  code *local_29c;
  undefined1 local_220 [64];
  undefined4 local_1e0;
  undefined4 *local_1dc;
  undefined4 *local_1c8;
  undefined4 local_198;
  uint local_170;
  uint local_16c;
  int local_164;
  uint local_154;
  undefined4 local_8;
  
  uVar10 = 0;
  local_8 = DAT_00b49670;
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0x80004005;
  }
  local_1e0 = FUN_008ed450(local_2a4);
  local_2a4[0] = FUN_008a2ef3;
  local_29c = FUN_008a2f12;
  iVar5 = __setjmp3(local_220,0);
  if (iVar5 == 0) {
    FUN_008eb5d0(&local_1e0,0x3e,0x1d8);
    local_1c8 = (undefined4 *)(*(code *)*local_1dc)(&local_1e0,0,0x24);
    local_1c8[8] = param_2;
    local_1c8[2] = FUN_008a2f12;
    local_1c8[3] = FUN_008a2f44;
    local_1c8[4] = FUN_008a2f61;
    local_1c8[5] = FUN_008ed110;
    local_1c8[6] = FUN_008a2f12;
    local_1c8[1] = 0;
    *local_1c8 = 0;
    local_1c8[7] = param_1;
    FUN_008eb9b0(&local_1e0,1);
    iVar5 = FUN_007a3436();
    if (iVar5 == 0) {
      local_198 = 1;
    }
    local_29c = FUN_008a2f15;
    FUN_008eb4f0(&local_1e0);
    if (local_164 == 1) {
      *in_ECX = 0x32;
      in_ECX[0xc] = local_170;
    }
    else {
      if (local_164 != 3) goto LAB_008a2fe1;
      *in_ECX = 0x16;
      in_ECX[0xc] = local_170 << 2;
    }
    in_ECX[3] = local_170;
    in_ECX[0xd] = 0;
    in_ECX[4] = local_16c;
    in_ECX[5] = 1;
    if (in_ECX[0x10] != 0) {
      in_ECX[0xe] = 1;
      pvVar6 = operator_new(in_ECX[0xc] * local_16c);
      in_ECX[1] = (int)pvVar6;
      if ((pvVar6 == (void *)0x0) ||
         (puVar7 = (undefined4 *)(*(code *)local_1dc[2])(&local_1e0,1,local_170 * local_164,1),
         puVar7 == (undefined4 *)0x0)) {
        uVar10 = 0x8007000e;
      }
      else {
        if (*in_ECX == 0x32) {
          puVar11 = (undefined4 *)in_ECX[1];
          if (local_154 < local_16c) {
            do {
              FUN_008eb460(&local_1e0,puVar7,1);
              puVar12 = (undefined4 *)*puVar7;
              puVar14 = puVar11;
              for (uVar9 = local_170 >> 2; uVar9 != 0; uVar9 = uVar9 - 1) {
                *puVar14 = *puVar12;
                puVar12 = puVar12 + 1;
                puVar14 = puVar14 + 1;
              }
              for (uVar9 = local_170 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
                *(undefined1 *)puVar14 = *(undefined1 *)puVar12;
                puVar12 = (undefined4 *)((int)puVar12 + 1);
                puVar14 = (undefined4 *)((int)puVar14 + 1);
              }
              puVar11 = (undefined4 *)((int)puVar11 + local_170);
            } while (local_154 < local_16c);
          }
        }
        else if (*in_ECX == 0x16) {
          puVar13 = (uint *)in_ECX[1];
          while (local_154 < local_16c) {
            FUN_008eb460(&local_1e0,puVar7,1);
            puVar8 = (undefined1 *)*puVar7;
            puVar3 = puVar13 + local_170;
            for (; puVar13 < puVar3; puVar13 = puVar13 + 1) {
              puVar1 = puVar8 + 1;
              uVar4 = *puVar8;
              puVar2 = puVar8 + 2;
              puVar8 = puVar8 + 3;
              *puVar13 = (uint)CONCAT21(CONCAT11(uVar4,*puVar1),*puVar2);
            }
          }
        }
        uVar10 = 0;
        FUN_008eb8f0(&local_1e0);
      }
    }
  }
  else {
LAB_008a2fe1:
    uVar10 = 0x80004005;
  }
  FUN_008ed570(&local_1e0);
  return uVar10;
}


// ==== FUN_008a3219 @ 0x008a3219 ====

void FUN_008a3219(int param_1)

{
  undefined4 *puVar1;
  void *pvVar2;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  pvVar2 = operator_new(0x1000);
  puVar1[6] = pvVar2;
  *puVar1 = pvVar2;
  puVar1[1] = 0x1000;
  return;
}


// ==== FUN_008a3241 @ 0x008a3241 ====

undefined4 FUN_008a3241(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x18);
  FUN_008a1a14(puVar1[6],0x1000,&param_1);
  *puVar1 = puVar1[6];
  puVar1[1] = 0x1000;
  return 1;
}


// ==== FUN_008a3275 @ 0x008a3275 ====

void FUN_008a3275(int param_1)

{
  int iVar1;
  
  iVar1 = 0x1000 - *(int *)(*(int *)(param_1 + 0x18) + 4);
  if (iVar1 != 0) {
    FUN_008a1a14(*(undefined4 *)(*(int *)(param_1 + 0x18) + 0x18),iVar1,&param_1);
  }
  return;
}


// ==== FUN_008a329e @ 0x008a329e ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008a329e(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *in_ECX;
  uint uVar3;
  undefined1 local_280 [8];
  code *local_278;
  code *local_274;
  code *local_270;
  undefined4 local_26c;
  undefined4 local_268;
  uint local_264;
  undefined4 *local_260;
  undefined4 local_25c;
  uint local_258;
  uint local_254;
  void *local_250;
  code *local_24c [2];
  code *local_244;
  undefined1 local_1c8 [64];
  undefined4 local_188 [6];
  undefined1 *local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_164;
  undefined4 local_160;
  undefined8 local_158;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_25c = 0;
  local_250 = (void *)0x0;
  local_26c = param_1;
  local_268 = 0;
  local_278 = FUN_008a3219;
  local_274 = FUN_008a3241;
  local_270 = FUN_008a3275;
  local_260 = in_ECX;
  iVar2 = FUN_0089fd60(*in_ECX);
  local_264 = *(uint *)(iVar2 + 8) >> 3;
  FUN_008ed4b0(local_188,0x3e,0x180);
  local_188[0] = FUN_008ed450(local_24c);
  local_24c[0] = FUN_008a2ef3;
  local_244 = FUN_008a2f12;
  iVar2 = __setjmp3(local_1c8,0);
  if (iVar2 == 0) {
    local_160 = 2;
    FUN_008edf50(local_188);
    local_158 = _DAT_00a16888;
    local_16c = local_260[3];
    local_168 = local_260[4];
    local_170 = local_280;
    local_164 = 3;
    FUN_008ed6d0(local_188,1);
    local_250 = operator_new(local_260[3] * 3);
    if (local_250 == (void *)0x0) {
      local_25c = 0x8007000e;
    }
    else {
      local_258 = local_260[7] * local_260[0xc] + local_260[6] * local_264 + local_260[1];
      uVar3 = local_260[4] * local_260[0xc] + local_258;
      for (; local_258 < uVar3; local_258 = local_258 + local_260[0xc]) {
        local_254 = 0;
        if (local_260[3] != 0) {
          iVar2 = 0;
          do {
            uVar1 = *(undefined4 *)(local_258 + local_254 * 4);
            *(char *)(iVar2 + (int)local_250) = (char)((uint)uVar1 >> 0x10);
            local_254 = local_254 + 1;
            *(char *)(iVar2 + 1 + (int)local_250) = (char)((uint)uVar1 >> 8);
            *(char *)(iVar2 + 2 + (int)local_250) = (char)uVar1;
            iVar2 = iVar2 + 3;
          } while (local_254 < (uint)local_260[3]);
        }
        FUN_008ed740(local_188,&local_250,1);
      }
      FUN_008ed5f0(local_188);
      FUN_008ed570(local_188);
    }
  }
  else {
    local_25c = 0x80004005;
  }
  _free(local_250);
  return;
}


// ==== FUN_008a34d3 @ 0x008a34d3 ====

undefined4 FUN_008a34d3(uint *param_1,uint param_2)

{
  byte *pbVar1;
  undefined1 *puVar2;
  byte bVar3;
  ushort uVar4;
  bool bVar5;
  byte *pbVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  undefined1 *puVar12;
  int *in_ECX;
  uint uVar13;
  int iVar14;
  uint *puVar15;
  uint uVar16;
  uint *puVar17;
  uint *puVar18;
  bool bVar19;
  bool bVar20;
  uint local_2c;
  uint local_28;
  undefined1 *local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  uint *local_14;
  int local_10;
  uint local_c;
  
  pbVar6 = (byte *)param_1;
  if (param_2 < 0x12) {
    return 0x80004005;
  }
  if ((*(byte *)((int)param_1 + 1) & 0xfe) != 0) {
    return 0x80004005;
  }
  bVar3 = *(byte *)((int)param_1 + 2);
  if ((bVar3 & 0xf4) != 0) {
    return 0x80004005;
  }
  if (*(short *)((int)param_1 + 0xc) == 0) {
    return 0x80004005;
  }
  if (*(short *)((int)param_1 + 0xe) == 0) {
    return 0x80004005;
  }
  uVar8 = (uint)*(byte *)((int)param_1 + 7);
  local_18 = 0;
  if (*(byte *)((int)param_1 + 1) != 0) {
    if (uVar8 == 0xf) {
      local_18 = 0x18;
    }
    else if (uVar8 == 0x10) {
      local_18 = 0x19;
    }
    else if (uVar8 == 0x18) {
      local_18 = 0x14;
    }
    else {
      if (uVar8 != 0x20) {
        return 0x80004005;
      }
      local_18 = 0x15;
    }
  }
  uVar13 = (uint)*(byte *)((int)param_1 + 0x10);
  uVar9 = uVar13 + 7 >> 3;
  bVar7 = bVar3 & 3;
  if (bVar7 == 1) {
    if (*(byte *)((int)param_1 + 1) == 0) {
      return 0x80004005;
    }
    if (*(byte *)((int)param_1 + 0x10) != 8) {
      return 0x80004005;
    }
    local_10 = 0x29;
  }
  else if (bVar7 == 2) {
    if (uVar13 == 0xf) {
      local_10 = 0x18;
    }
    else if (uVar13 == 0x10) {
      local_10 = 0x19;
    }
    else if (uVar13 == 0x18) {
      local_10 = 0x14;
    }
    else {
      if (uVar13 != 0x20) {
        return 0x80004005;
      }
      local_10 = 0x15;
    }
  }
  else {
    if (bVar7 != 3) {
      return 0x80004005;
    }
    if (*(byte *)((int)param_1 + 0x10) != 8) {
      return 0x80004005;
    }
    local_10 = 0x32;
  }
  bVar19 = (*(byte *)((int)param_1 + 0x11) & 0x20) != 0x20;
  bVar20 = (*(byte *)((int)param_1 + 0x11) & 0x10) == 0x10;
  uVar10 = (uint)*(byte *)param_1;
  if (param_2 - 0x12 < uVar10) {
    return 0x80004005;
  }
  param_2 = (param_2 - 0x12) - uVar10;
  puVar15 = (uint *)((int)param_1 + uVar10 + 0x12);
  uVar8 = (uint)*(ushort *)((int)param_1 + 5) * (uVar8 + 7 >> 3);
  if (param_2 < uVar8) {
    return 0x80004005;
  }
  if ((in_ECX[0x10] != 0) && (local_10 == 0x29)) {
    if (0x100 < (uint)*(ushort *)((int)param_1 + 3) + (uint)*(ushort *)((int)param_1 + 5)) {
      return 0x80004005;
    }
    puVar11 = operator_new(0x400);
    in_ECX[2] = (int)puVar11;
    if (puVar11 == (undefined4 *)0x0) {
      return 0x8007000e;
    }
    bVar5 = false;
    in_ECX[0xf] = 1;
    for (iVar14 = 0x100; iVar14 != 0; iVar14 = iVar14 + -1) {
      *puVar11 = 0xffffffff;
      puVar11 = puVar11 + 1;
    }
    local_24 = (undefined1 *)(in_ECX[2] + (uint)*(ushort *)((int)param_1 + 3) * 4);
    puVar2 = local_24 + (uint)*(ushort *)((int)param_1 + 5) * 4;
    if (local_24 < puVar2) {
      uVar10 = param_2;
      puVar17 = puVar15;
      local_14 = puVar15;
      do {
        if (local_18 == 0x14) {
          local_c = (uint)(byte)*puVar17;
          uVar10 = (uint)*(byte *)((int)puVar17 + 2);
          local_1c = (uint)*(byte *)((int)puVar17 + 1);
          puVar17 = (uint *)((int)puVar17 + 3);
LAB_008a37b9:
          local_20 = 0xff;
LAB_008a37c0:
          local_14 = puVar17;
        }
        else {
          if (local_18 == 0x15) {
            uVar10 = *puVar17;
            local_20 = uVar10 >> 0x18;
            local_1c = uVar10 >> 8 & 0xff;
            local_c = uVar10 & 0xff;
            uVar10 = uVar10 >> 0x10 & 0xff;
            puVar17 = puVar17 + 1;
            goto LAB_008a37c0;
          }
          if (local_18 == 0x18) {
            uVar4 = (ushort)*puVar17;
            uVar10 = uVar4 >> 10 & 0x1f;
            uVar16 = uVar4 >> 5 & 0x1f;
            uVar10 = uVar10 >> 2 | uVar10 << 3;
            local_1c = uVar16 >> 2 | uVar16 << 3;
            local_c = (uVar4 & 0x1f) >> 2 | (uVar4 & 0x1f) << 3;
            puVar17 = (uint *)((int)local_14 + 2);
            goto LAB_008a37b9;
          }
          if (local_18 == 0x19) {
            uVar4 = (ushort)*puVar17;
            local_20 = (uint)(uVar4 >> 0xf) * 0xff;
            uVar10 = uVar4 >> 10 & 0x1f;
            uVar16 = uVar4 >> 5 & 0x1f;
            uVar10 = uVar10 >> 2 | uVar10 << 3;
            local_1c = uVar16 >> 2 | uVar16 << 3;
            local_c = (uVar4 & 0x1f) >> 2 | (uVar4 & 0x1f) << 3;
            puVar17 = (uint *)((int)local_14 + 2);
            goto LAB_008a37c0;
          }
        }
        local_24[1] = (char)local_1c;
        local_24[2] = (undefined1)local_c;
        local_24[3] = (char)local_20;
        *local_24 = (char)uVar10;
        local_24 = local_24 + 4;
        bVar5 = (bool)(bVar5 | local_20 != 0);
      } while (local_24 < puVar2);
      if (bVar5) goto LAB_008a3812;
    }
    for (puVar12 = (undefined1 *)(in_ECX[2] + (uint)*(ushort *)((int)param_1 + 3) * 4);
        puVar12 < puVar2; puVar12 = puVar12 + 4) {
      puVar12[3] = 0xff;
    }
  }
LAB_008a3812:
  param_2 = param_2 - uVar8;
  puVar15 = (uint *)((int)puVar15 + uVar8);
  uVar8 = (uint)*(ushort *)((int)param_1 + 0xe) * (uint)*(ushort *)((int)param_1 + 0xc) * uVar9;
  *in_ECX = local_10;
  in_ECX[1] = (int)puVar15;
  in_ECX[0xc] = *(ushort *)((int)param_1 + 0xc) * uVar9;
  in_ECX[0xd] = 0;
  in_ECX[3] = (uint)*(ushort *)((int)param_1 + 0xc);
  in_ECX[4] = (uint)*(ushort *)((int)param_1 + 0xe);
  in_ECX[5] = 1;
  if (in_ECX[0x10] != 0) {
    if ((((bVar3 & 8) != 0) || (bVar19)) || (bVar20)) {
      puVar17 = operator_new(uVar8);
      in_ECX[1] = (int)puVar17;
      if (puVar17 == (uint *)0x0) {
        return 0x8007000e;
      }
      in_ECX[0xe] = 1;
      if (bVar19) {
        puVar17 = (uint *)((*(ushort *)((int)param_1 + 0xe) - 1) * in_ECX[0xc] + (int)puVar17);
      }
      pbVar1 = (byte *)((int)param_1 + 0xe);
      local_24 = (undefined1 *)0x0;
      param_1 = puVar15;
      if (*(short *)pbVar1 != 0) {
        do {
          if (bVar20) {
            local_14 = (uint *)((in_ECX[0xc] - uVar9) + (int)puVar17);
          }
          else {
            local_14 = puVar17;
          }
          uVar8 = (uint)*(ushort *)(pbVar6 + 0xc);
          local_28 = 0;
          if (uVar8 != 0) {
            do {
              if ((bVar3 & 8) == 0) {
                local_2c = 0;
              }
              else {
                if (param_2 == 0) {
                  return 0x80004005;
                }
                local_2c = (byte)*param_1 & 0x80;
                uVar8 = ((byte)*param_1 & 0x7f) + 1;
                param_1 = (uint *)((int)param_1 + 1);
                param_2 = param_2 - 1;
              }
              local_28 = local_28 + uVar8;
              while (uVar8 != 0) {
                uVar8 = uVar8 - 1;
                if (param_2 < uVar9) {
                  return 0x80004005;
                }
                puVar15 = param_1;
                puVar18 = local_14;
                for (uVar10 = uVar13 + 7 >> 5; uVar10 != 0; uVar10 = uVar10 - 1) {
                  *puVar18 = *puVar15;
                  puVar15 = puVar15 + 1;
                  puVar18 = puVar18 + 1;
                }
                for (uVar10 = uVar9 & 3; uVar10 != 0; uVar10 = uVar10 - 1) {
                  *(byte *)puVar18 = (byte)*puVar15;
                  puVar15 = (uint *)((int)puVar15 + 1);
                  puVar18 = (uint *)((int)puVar18 + 1);
                }
                if (local_2c == 0) {
                  param_1 = (uint *)((int)param_1 + uVar9);
                  param_2 = param_2 - uVar9;
                }
                uVar10 = uVar9;
                if (bVar20) {
                  uVar10 = -uVar9;
                }
                local_14 = (uint *)((int)local_14 + uVar10);
              }
              if (local_2c != 0) {
                param_1 = (uint *)((int)param_1 + uVar9);
                param_2 = param_2 - uVar9;
              }
              uVar8 = (uint)*(ushort *)(pbVar6 + 0xc);
            } while (local_28 < uVar8);
          }
          if (bVar19) {
            iVar14 = -in_ECX[0xc];
          }
          else {
            iVar14 = in_ECX[0xc];
          }
          puVar17 = (uint *)((int)puVar17 + iVar14);
          local_24 = (undefined1 *)((int)local_24 + 1);
        } while (local_24 < (uint)*(ushort *)(pbVar6 + 0xe));
      }
    }
    else {
      if (param_2 < uVar8) {
        return 0x80004005;
      }
      in_ECX[1] = (int)puVar15;
      in_ECX[0xe] = 0;
    }
    if (*in_ECX == 0x19) {
      uVar8 = in_ECX[1];
      uVar9 = in_ECX[4] * in_ECX[0xc] + uVar8;
      if (uVar8 < uVar9) {
        do {
          uVar13 = in_ECX[3] * 2 + uVar8;
          uVar10 = uVar8;
          if (uVar8 < uVar13) {
            do {
              if ((*(byte *)(uVar10 + 1) & 0x80) != 0) break;
              uVar10 = uVar10 + 2;
            } while (uVar10 < uVar13);
            if (uVar10 < uVar13) break;
          }
          uVar8 = uVar8 + in_ECX[0xc];
        } while (uVar8 < uVar9);
      }
      if (uVar8 == uVar9) {
        *in_ECX = 0x18;
      }
    }
  }
  return 0;
}


// ==== FUN_008a39fd @ 0x008a39fd ====

void FUN_008a39fd(void)

{
  int iVar1;
  int *in_ECX;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined2 local_19;
  undefined2 local_17;
  undefined1 local_15;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  byte local_c;
  undefined1 local_b;
  undefined4 local_8;
  
  local_10 = (undefined2)in_ECX[3];
  local_e = (undefined2)in_ECX[4];
  local_1c = 0xd;
  local_1b = 0;
  local_1a = 2;
  local_19 = 0;
  local_17 = 0;
  local_15 = 0;
  local_14 = 0;
  local_12 = 0;
  if (*in_ECX == 0x15) {
    local_c = 0x20;
    local_b = 0x28;
  }
  else {
    local_c = 0x18;
    local_b = 0x20;
  }
  local_8 = 0;
  iVar1 = FUN_008a1a14(&local_1c,0x12,&local_8);
  if (-1 < iVar1) {
    iVar1 = FUN_008a1a14(s_GSaved_by_D3DX_00a16817 + 1,0xd,&local_8);
    if (-1 < iVar1) {
      FUN_008a1a14(in_ECX[1],(uint)(local_c >> 3) * in_ECX[3] * in_ECX[4],&local_8);
    }
  }
  return;
}


// ==== FUN_008a3aa5 @ 0x008a3aa5 ====

uint FUN_008a3aa5(uint *param_1,uint param_2)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  int iVar4;
  undefined4 *in_ECX;
  uint uVar5;
  byte *pbVar6;
  uint local_18;
  uint *local_14;
  uint local_c;
  int local_8;
  
  if (param_2 < 2) {
    return 0x80004005;
  }
  if ((char)*param_1 == 'P') {
    if (*(char *)((int)param_1 + 1) == '3') {
      bVar2 = true;
    }
    else {
      if (*(char *)((int)param_1 + 1) != '6') {
        return 0x80004005;
      }
      bVar2 = false;
    }
    pbVar6 = (byte *)((int)param_1 + 2);
    param_2 = param_2 - 2;
    local_8 = 0;
    local_18 = 0;
    local_c = 0xff;
    pbVar3 = pbVar6;
    while (param_2 != 0) {
      uVar5 = 0;
      if ((!bVar2) && (local_8 == 3)) {
        if (0xff < local_c) {
          return 0x80004005;
        }
        if ((1 < param_2) && (*pbVar6 == 0xd)) {
          pbVar6 = pbVar6 + 1;
          param_2 = param_2 - 1;
        }
        iVar4 = param_2 - 1;
        pbVar6 = pbVar6 + 1;
        for (; (iVar4 != 0 && (param_1 < local_14)); param_1 = param_1 + 1) {
          *param_1 = ((((uint)*pbVar6 * 0xff) / local_c | 0xffffff00) << 8 |
                     ((uint)pbVar6[1] * 0xff) / local_c) << 8 | ((uint)pbVar6[2] * 0xff) / local_c;
          iVar4 = iVar4 + -3;
          pbVar6 = pbVar6 + 3;
        }
        return -(uint)(param_1 != local_14) & 0x80004005;
      }
      iVar4 = _isspace((uint)*pbVar6);
      if (iVar4 == 0) {
        if (*pbVar6 == 0x23) {
          for (; (param_2 != 0 && (*pbVar6 != 10)); pbVar6 = pbVar6 + 1) {
            param_2 = param_2 - 1;
          }
          goto LAB_008a3b31;
        }
        while ((param_2 != 0 && (iVar4 = _isspace((uint)*pbVar6), iVar4 == 0))) {
          iVar4 = _isdigit((uint)*pbVar6);
          if (iVar4 == 0) {
            return 0x80004005;
          }
          bVar1 = *pbVar6;
          pbVar6 = pbVar6 + 1;
          param_2 = param_2 - 1;
          uVar5 = (bVar1 - 0x30) + uVar5 * 10;
          pbVar3 = pbVar6;
        }
        if (local_8 == 0) {
          local_18 = uVar5;
LAB_008a3c76:
          if (uVar5 == 0) {
            return 0x80004005;
          }
        }
        else if (local_8 == 1) {
          if (uVar5 == 0) {
            return 0x80004005;
          }
          param_1 = operator_new(uVar5 * local_18 * 4);
          in_ECX[1] = param_1;
          if (param_1 == (uint *)0x0) {
            return 0x8007000e;
          }
          local_14 = param_1 + uVar5 * local_18;
          in_ECX[0xd] = 0;
          in_ECX[0xe] = 1;
          *in_ECX = 0x16;
          in_ECX[0xc] = local_18 << 2;
          in_ECX[3] = local_18;
          in_ECX[4] = uVar5;
          in_ECX[5] = 1;
          pbVar6 = pbVar3;
        }
        else {
          if (local_8 == 2) {
            local_c = uVar5;
            goto LAB_008a3c76;
          }
          if (local_8 == 3) {
            if (local_14 <= param_1) {
              return 0x80004005;
            }
            *param_1 = ((uVar5 * 0xff) / local_c | 0xffffff00) << 0x10;
          }
          else if (local_8 == 4) {
            *param_1 = *param_1 | (uVar5 * 0xff) / local_c << 8;
          }
          else if (local_8 == 5) {
            *param_1 = *param_1 | (uVar5 * 0xff) / local_c;
            param_1 = param_1 + 1;
            if (param_1 == local_14) {
              return 0;
            }
            local_8 = 2;
          }
        }
        local_8 = local_8 + 1;
      }
      else {
LAB_008a3b31:
        pbVar6 = pbVar6 + 1;
        param_2 = param_2 - 1;
        pbVar3 = pbVar6;
      }
    }
  }
  return 0x80004005;
}


// ==== FUN_008a3d2d @ 0x008a3d2d ====

void FUN_008a3d2d(int param_1,undefined4 *param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  piVar1 = *(int **)(param_1 + 0x54);
  if ((uint)piVar1[1] < param_3) {
    FUN_008ee0f5(param_1,s__read_error_00a1688f + 1);
  }
  puVar3 = (undefined4 *)*piVar1;
  for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *param_2 = *puVar3;
    puVar3 = puVar3 + 1;
    param_2 = param_2 + 1;
  }
  for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined1 *)param_2 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  *piVar1 = *piVar1 + param_3;
  piVar1[1] = piVar1[1] - param_3;
  return;
}


// ==== FUN_008a3d70 @ 0x008a3d70 ====

void FUN_008a3d70(int *param_1)

{
                    /* WARNING: Subroutine does not return */
  _longjmp(param_1,1);
}


// ==== FUN_008a3d80 @ 0x008a3d80 ====

void FUN_008a3d80(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_8;
  
  FUN_008ee2b7(param_1);
  local_8 = 0;
  FUN_008a1a14(param_2,param_3,&local_8);
  return;
}


// ==== FUN_008a3da5 @ 0x008a3da5 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008a3da5(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined1 *puVar4;
  int *in_ECX;
  uint uVar5;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  void *local_8;
  
  local_c = 0;
  local_10 = 0;
  local_8 = (void *)0x0;
  local_c = FUN_008ee903(s_1_0_5_00a1689c,0,FUN_008a3d70,FUN_0095cf1d);
  if (((local_c != 0) && (local_10 = FUN_008ee2c6(), local_10 != 0)) &&
     (iVar2 = __setjmp3(local_c), iVar2 == 0)) {
    uVar5 = (uint)(*in_ECX == 0x24) * 8 + 8;
    FUN_008eeaae(local_c,local_10,in_ECX[3],in_ECX[4],uVar5,2,0,0,0);
    FUN_008eea8e(local_c,local_10,_DAT_00a16888);
    local_8 = operator_new((uVar5 >> 3) * in_ECX[3] * 3);
    if (local_8 != (void *)0x0) {
      FUN_008eea4b(local_c,param_1,FUN_008a3d80,FUN_0095cf1d);
      FUN_008ee2f3(local_c,local_10);
      local_14 = 0;
      if (uVar5 == 8) {
        if (in_ECX[4] != 0) {
          do {
            puVar3 = (undefined4 *)(in_ECX[0xc] * local_14 + in_ECX[1]);
            local_18 = 0;
            if (in_ECX[3] != 0) {
              iVar2 = 0;
              do {
                uVar1 = *puVar3;
                *(char *)(iVar2 + (int)local_8) = (char)((uint)uVar1 >> 0x10);
                local_18 = local_18 + 1;
                *(char *)(iVar2 + 1 + (int)local_8) = (char)((uint)uVar1 >> 8);
                *(char *)(iVar2 + 2 + (int)local_8) = (char)uVar1;
                iVar2 = iVar2 + 3;
                puVar3 = puVar3 + 1;
              } while (local_18 < (uint)in_ECX[3]);
            }
            FUN_008ee99b(local_c,&local_8,1);
            local_14 = local_14 + 1;
          } while (local_14 < (uint)in_ECX[4]);
        }
      }
      else if (in_ECX[4] != 0) {
        do {
          uVar5 = 0;
          puVar4 = (undefined1 *)(in_ECX[0xc] * local_14 + in_ECX[1]);
          if (in_ECX[3] != 0) {
            iVar2 = 0;
            do {
              *(undefined1 *)(iVar2 + (int)local_8) = puVar4[1];
              *(undefined1 *)(iVar2 + 1 + (int)local_8) = *puVar4;
              *(undefined1 *)(iVar2 + 2 + (int)local_8) = puVar4[3];
              *(undefined1 *)(iVar2 + 3 + (int)local_8) = puVar4[2];
              *(undefined1 *)(iVar2 + 4 + (int)local_8) = puVar4[5];
              *(undefined1 *)(iVar2 + 5 + (int)local_8) = puVar4[4];
              uVar5 = uVar5 + 1;
              iVar2 = iVar2 + 6;
              puVar4 = puVar4 + 8;
            } while (uVar5 < (uint)in_ECX[3]);
          }
          FUN_008ee99b(local_c,&local_8,1);
          local_14 = local_14 + 1;
        } while (local_14 < (uint)in_ECX[4]);
      }
      FUN_008ee357(local_c,local_10);
    }
  }
  if (local_c != 0) {
    FUN_008ee9c2(&local_c,&local_10);
  }
  _free(local_8);
  return;
}


// ==== FUN_008a3fa7 @ 0x008a3fa7 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008a3fa7(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 extraout_EAX;
  int *in_ECX;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined8 local_15c;
  int local_13c;
  int local_138;
  int local_134;
  int local_130;
  int local_12c;
  int local_128;
  uint local_124;
  int local_120;
  void *local_11c;
  int local_118;
  uint local_114;
  int local_110;
  int local_10c;
  undefined1 auStack_108 [256];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_10c = 0;
  local_110 = 0;
  local_11c = (void *)0x0;
  iVar3 = FUN_008ee195();
  if (iVar3 != 0) {
    return 0x80004005;
  }
  local_10c = FUN_008eec1d(s_1_0_5_00a1689c,0,FUN_008a3d70,FUN_0095cf1d);
  if ((local_10c == 0) || (local_110 = FUN_008ee2c6(), local_110 == 0)) goto LAB_008a44d7;
  iVar3 = __setjmp3(local_10c);
  if (iVar3 == 0) {
    FUN_008f0de5();
    FUN_008eed13(local_10c,local_110);
    FUN_008ef4c8(local_10c,local_110,&local_138,&local_124,&local_12c,&local_134,0,0,0);
    if (local_134 == 0) {
      *in_ECX = 0x32;
    }
    else if (local_134 == 2) {
      *in_ECX = 0x14;
    }
    else if (local_134 == 3) {
      *in_ECX = 0x29;
    }
    else if (local_134 == 4) {
      *in_ECX = 0x33;
    }
    else if (local_134 == 6) {
      *in_ECX = 0x15;
    }
    if (local_12c == 0x10) {
      FUN_008ef64e();
      iVar3 = *in_ECX;
      if (iVar3 == 0x14) {
        *in_ECX = 0x36315220;
      }
      else if (iVar3 == 0x15) {
        *in_ECX = 0x24;
      }
      else if (iVar3 == 0x32) {
        *in_ECX = 0x51;
      }
      else {
        if (iVar3 != 0x33) {
          return 0x80004005;
        }
        *in_ECX = 0x36314c41;
      }
    }
    if (local_12c < 8) {
      FUN_008ef667();
    }
    if ((local_134 == 0) && (local_12c < 8)) {
      FUN_008ef82b();
    }
    iVar3 = FUN_008ef497();
    if (iVar3 == 0) {
      iVar3 = FUN_008ef468();
      if (iVar3 != 0) {
        FUN_008ef7f0(local_10c,_DAT_00a16888,local_15c);
      }
    }
    else {
      FUN_008eeb79();
    }
    if ((*in_ECX != 0x29) && (iVar3 = FUN_008ef40e(), iVar3 != 0)) {
      FUN_008ef82b();
      iVar3 = *in_ECX;
      if (iVar3 == 0x14) {
        *in_ECX = 0x15;
      }
      else if (iVar3 == 0x32) {
        *in_ECX = 0x33;
      }
      else if (iVar3 == 0x51) {
        *in_ECX = 0x36314c41;
      }
      else if (iVar3 == 0x36315220) {
        *in_ECX = 0x24;
      }
    }
    iVar3 = *in_ECX;
    if (((iVar3 == 0x14) || (iVar3 == 0x36315220)) || (iVar3 == 0x15)) {
      FUN_008ef63e();
    }
    if (*in_ECX == 0x14) {
      FUN_008ef6a8();
      *in_ECX = 0x16;
    }
    FUN_008eee83(local_10c,local_110);
    iVar3 = *in_ECX;
    if (iVar3 < 0x33) {
      if (iVar3 == 0x32) {
LAB_008a4299:
        local_114 = 1;
      }
      else if (iVar3 == 0x14) {
LAB_008a42c2:
        local_114 = 3;
      }
      else if (((iVar3 == 0x15) || (iVar3 == 0x16)) || (iVar3 == 0x24)) {
        local_114 = 4;
      }
      else if (iVar3 == 0x29) goto LAB_008a4299;
    }
    else {
      if (iVar3 != 0x33) {
        if (iVar3 == 0x51) goto LAB_008a4299;
        if (iVar3 != 0x36314c41) {
          if (iVar3 != 0x36315220) goto LAB_008a42d4;
          goto LAB_008a42c2;
        }
      }
      local_114 = 2;
    }
LAB_008a42d4:
    uVar4 = FUN_008ef44b(local_10c,local_110);
    if (local_114 == (uVar4 & 0xff)) {
      in_ECX[3] = local_138;
      in_ECX[4] = local_124;
      in_ECX[5] = 1;
      iVar3 = FUN_008ef42e(local_10c,local_110);
      in_ECX[0xc] = iVar3;
      in_ECX[0xd] = 0;
      if (in_ECX[0x10] == 0) goto LAB_008a45fa;
      pvVar5 = operator_new(iVar3 * local_124);
      in_ECX[1] = (int)pvVar5;
      if (pvVar5 != (void *)0x0) {
        in_ECX[0xe] = 1;
        local_11c = operator_new(local_124 << 2);
        if (local_11c != (void *)0x0) {
          uVar4 = 0;
          if (local_124 != 0) {
            do {
              *(uint *)((int)local_11c + uVar4 * 4) = in_ECX[0xc] * uVar4 + in_ECX[1];
              uVar4 = uVar4 + 1;
            } while (uVar4 < local_124);
          }
          FUN_008ef22b(local_10c,local_11c);
          if (*in_ECX == 0x29) {
            local_130 = 0;
            local_128 = 0;
            iVar3 = FUN_008ef40e();
            if (iVar3 != 0) {
              FUN_008ef59b(local_10c,local_110,&local_118,&local_128);
            }
            iVar3 = FUN_008ef40e();
            if (iVar3 != 0) {
              FUN_008ef5d3(local_10c,local_110,&local_13c,&local_130,0);
            }
            if ((*(float *)(local_10c + 0x130) <= (float)_DAT_00a168b8) ||
               (*(float *)(local_10c + 0x134) <= (float)_DAT_00a168b8)) {
              iVar3 = 0;
              do {
                auStack_108[iVar3] = (char)iVar3;
                iVar3 = iVar3 + 1;
              } while (iVar3 < 0x100);
            }
            else {
              local_120 = 0;
              do {
                FUN_00801f40();
                uVar2 = __ftol();
                iVar3 = local_120 + 1;
                auStack_108[local_120] = uVar2;
                local_120 = iVar3;
              } while (iVar3 < 0x100);
            }
            pvVar5 = operator_new(0x400);
            in_ECX[2] = (int)pvVar5;
            if (pvVar5 == (void *)0x0) goto LAB_008a44d7;
            iVar3 = 0;
            in_ECX[0xf] = 1;
            if (0 < local_130) {
              iVar8 = 0;
              do {
                iVar6 = iVar3 * 4;
                *(undefined1 *)(iVar6 + in_ECX[2]) = auStack_108[*(byte *)(iVar8 + local_118)];
                *(undefined1 *)(iVar6 + 1 + in_ECX[2]) =
                     auStack_108[*(byte *)(iVar8 + 1 + local_118)];
                *(undefined1 *)(iVar6 + 2 + in_ECX[2]) =
                     auStack_108[*(byte *)(iVar8 + 2 + local_118)];
                puVar1 = (undefined1 *)(iVar3 + local_13c);
                iVar3 = iVar3 + 1;
                *(undefined1 *)(iVar6 + 3 + in_ECX[2]) = *puVar1;
                iVar8 = iVar8 + 3;
              } while (iVar3 < local_130);
            }
            if (iVar3 < local_128) {
              iVar8 = iVar3 * 3;
              do {
                iVar6 = iVar3 * 4;
                *(undefined1 *)(iVar6 + in_ECX[2]) = auStack_108[*(byte *)(iVar8 + local_118)];
                *(undefined1 *)(iVar6 + 1 + in_ECX[2]) =
                     auStack_108[*(byte *)(iVar8 + 1 + local_118)];
                *(undefined1 *)(iVar6 + 2 + in_ECX[2]) =
                     auStack_108[*(byte *)(iVar8 + 2 + local_118)];
                iVar3 = iVar3 + 1;
                *(undefined1 *)(iVar6 + 3 + in_ECX[2]) = 0xff;
                iVar8 = iVar8 + 3;
              } while (iVar3 < local_128);
            }
            if (iVar3 < 0x100) {
              iVar3 = iVar3 << 2;
              do {
                *(undefined1 *)(iVar3 + in_ECX[2]) = 0xff;
                *(undefined1 *)(iVar3 + 1 + in_ECX[2]) = 0xff;
                *(undefined1 *)(iVar3 + 2 + in_ECX[2]) = 0xff;
                *(undefined1 *)(iVar3 + 3 + in_ECX[2]) = 0xff;
                iVar3 = iVar3 + 4;
              } while (iVar3 < 0x400);
            }
          }
LAB_008a45fa:
          uVar7 = 0;
          goto LAB_008a45fc;
        }
      }
LAB_008a44d7:
      uVar7 = 0x8007000e;
      goto LAB_008a45fc;
    }
  }
  uVar7 = 0x80004005;
LAB_008a45fc:
  if (local_10c != 0) {
    FUN_008ef38f();
  }
  if (local_11c == (void *)0x0) {
    return uVar7;
  }
  _free(local_11c);
  return extraout_EAX;
}


// ==== FUN_008a463f @ 0x008a463f ====

undefined4 FUN_008a463f(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int *in_ECX;
  int iVar6;
  int *piVar7;
  uint uVar8;
  int *local_2c;
  uint local_24;
  int *local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  int *local_8;
  
  if (((param_2 < 4) || (*param_1 != 0x20534444)) || ((int)param_2 - 4U < 0x7c)) {
    return 0x80004005;
  }
  local_8 = param_1 + 0x20;
  in_ECX[3] = param_1[4];
  in_ECX[4] = param_1[3];
  if ((*(byte *)((int)param_1 + 10) & 0x80) == 0) {
    iVar1 = 1;
  }
  else {
    iVar1 = param_1[6];
  }
  in_ECX[5] = iVar1;
  if (iVar1 == 0) {
    in_ECX[5] = 1;
  }
  if ((param_1[0x1c] & 0xfc00U) == 0xfc00) {
    local_1c = 6;
  }
  else {
    if ((param_1[0x1c] & 0xfc00U) != 0) {
      return 0x80004005;
    }
    local_1c = 1;
  }
  local_24 = param_1[7];
  if (local_24 == 0) {
    local_24 = 1;
  }
  uVar8 = param_1[0x14];
  if ((uVar8 & 4) != 0) {
    uVar8 = 4;
  }
  local_20 = (int *)(uVar8 & 0xc4040);
  piVar2 = &DAT_00b537f0;
  iVar1 = DAT_00b537f0;
  while ((iVar1 != 0 &&
         ((((((param_1[0x13] != 0x20 || (piVar2[2] != uVar8)) ||
             (((uVar8 & 4) != 0 && (param_1[0x15] != piVar2[3])))) ||
            (((uVar8 & 0xc4462) != 0 && (param_1[0x16] != piVar2[4])))) ||
           (((uVar8 & 0xe4040) != 0 && (param_1[0x17] != piVar2[5])))) ||
          (((((uVar8 & 0xc4440) != 0 && (param_1[0x18] != piVar2[6])) ||
            ((local_20 != (int *)0x0 && (param_1[0x19] != piVar2[7])))) ||
           (((uVar8 & 0x80003) != 0 && (param_1[0x1a] != piVar2[8]))))))))) {
    piVar2 = piVar2 + 9;
    iVar1 = *piVar2;
  }
  iVar1 = *piVar2;
  if (iVar1 == 0) {
    return 0x80004005;
  }
  iVar3 = FUN_0089fd60(iVar1);
  if ((*(byte *)((int)param_1 + 10) & 0x80) == 0) {
    in_ECX[0x11] = (uint)(local_1c == 6) * 2 + 3;
  }
  else {
    in_ECX[0x11] = 4;
  }
  if (*(int *)(iVar3 + 4) == 1) {
    if ((int *)((int)param_2 - 0x80U) < (int *)0x400) {
      return 0x80004005;
    }
    param_2 = (int *)((int)param_2 - 0x480);
    local_2c = local_8;
    local_8 = param_1 + 0x120;
  }
  else {
    local_2c = (int *)0x0;
    param_2 = (int *)((int)param_2 - 0x80U);
  }
  local_18 = 0;
  if (local_1c != 0) {
    piVar2 = param_2;
    do {
      local_10 = in_ECX[4];
      uVar8 = in_ECX[3];
      param_1 = (int *)in_ECX[5];
      if (local_18 == 0) {
        local_20 = in_ECX;
      }
      else {
        pvVar4 = operator_new(0x54);
        if (pvVar4 == (void *)0x0) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = (int *)FUN_008a1c00();
        }
        if (piVar7 == (int *)0x0) {
          return 0x8007000e;
        }
        local_20[0x14] = (int)piVar7;
        local_20 = piVar7;
      }
      local_14 = 0;
      if (local_24 != 0) {
        piVar7 = piVar2;
        do {
          if (local_14 == 0) {
            piVar2 = local_20;
          }
          else {
            pvVar4 = operator_new(0x54);
            if (pvVar4 == (void *)0x0) {
              piVar2 = (int *)0x0;
            }
            else {
              piVar2 = (int *)FUN_008a1c00();
            }
            if (piVar2 == (int *)0x0) {
              return 0x8007000e;
            }
            piVar7[0x13] = (int)piVar2;
          }
          if (iVar1 < 0x34545845) {
            if (iVar1 == 0x34545844) {
LAB_008a48b2:
              iVar5 = (uVar8 + 3 >> 2) << 4;
            }
            else {
              if (iVar1 != 0x31545844) {
                if (iVar1 != 0x32545844) {
                  if (iVar1 == 0x32595559) goto LAB_008a4947;
                  if (iVar1 != 0x33545844) goto LAB_008a4939;
                }
                goto LAB_008a48b2;
              }
              iVar5 = (uVar8 + 3 >> 2) << 3;
            }
            iVar6 = (local_10 + 3 >> 2) * iVar5;
          }
          else {
            if (iVar1 == 0x35545844) goto LAB_008a48b2;
            if (((iVar1 == 0x42475247) || (iVar1 == 0x47424752)) || (iVar1 == 0x59565955)) {
LAB_008a4947:
              iVar5 = (uVar8 + 1 >> 1) << 2;
            }
            else {
LAB_008a4939:
              iVar5 = (*(uint *)(iVar3 + 8) >> 3) * uVar8;
            }
            iVar6 = iVar5 * local_10;
          }
          piVar2[0xe] = 0;
          piVar2[0xf] = 0;
          piVar7 = (int *)(iVar6 * (int)param_1);
          *piVar2 = iVar1;
          piVar2[0xc] = iVar5;
          piVar2[1] = (int)local_8;
          piVar2[5] = (int)param_1;
          piVar2[0xd] = iVar6;
          piVar2[3] = uVar8;
          piVar2[4] = local_10;
          piVar2[2] = (int)local_2c;
          if (param_2 < piVar7) {
            return 0x80004005;
          }
          local_8 = (int *)((int)local_8 + (int)piVar7);
          param_2 = (int *)((int)param_2 - (int)piVar7);
          if (uVar8 == 1) {
            uVar8 = 1;
          }
          else {
            uVar8 = uVar8 >> 1;
          }
          if (local_10 == 1) {
            local_10 = 1;
          }
          else {
            local_10 = local_10 >> 1;
          }
          if (param_1 == (int *)0x1) {
            param_1 = (int *)0x1;
          }
          else {
            param_1 = (int *)((uint)param_1 >> 1);
          }
          local_14 = local_14 + 1;
          piVar7 = piVar2;
        } while (local_14 < local_24);
      }
      local_18 = local_18 + 1;
    } while (local_18 < local_1c);
  }
  return 0;
}


// ==== FUN_008a49ad @ 0x008a49ad ====

undefined4 FUN_008a49ad(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  uint uVar8;
  uint local_98 [5];
  uint local_84;
  int local_80;
  int local_50 [8];
  uint local_30;
  byte local_2b;
  byte local_2a;
  undefined4 local_1c;
  int local_18;
  int *local_14;
  undefined1 local_10 [4];
  uint local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  for (piVar4 = in_ECX; piVar4 != (int *)0x0; piVar4 = (int *)piVar4[0x13]) {
    local_8 = (int *)((int)local_8 + 1);
  }
  piVar4 = &DAT_00b537f0;
  if (DAT_00b537f0 != 0) {
    iVar2 = DAT_00b537f0;
    do {
      if (iVar2 == *in_ECX) break;
      piVar4 = piVar4 + 9;
      iVar2 = *piVar4;
    } while (iVar2 != 0);
  }
  if (*piVar4 != 0) {
    local_14 = in_ECX;
    local_18 = FUN_0089fd60(*in_ECX);
    local_c = *(uint *)(local_18 + 8) >> 3;
    local_1c = 0x20534444;
    iVar2 = FUN_008a1a14(&local_1c,4,local_10);
    if (-1 < iVar2) {
      puVar6 = local_98;
      for (iVar2 = 0x1f; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      local_98[2] = in_ECX[4];
      local_98[3] = in_ECX[3];
      uVar5 = piVar4[2];
      local_98[0] = 0x7c;
      local_98[1] = 0x1007;
      piVar7 = local_50;
      for (iVar2 = 8; piVar1 = local_14, piVar4 = piVar4 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar7 = *piVar4;
        piVar7 = piVar7 + 1;
      }
      local_30 = 0x1000;
      if ((uVar5 & 3) != 0) {
        local_30 = 0x1002;
      }
      if ((uVar5 & 0x20) != 0) {
        local_30 = local_30 | 0x100;
      }
      if (local_14[0x13] != 0) {
        local_30 = local_30 | 0x400008;
        local_98[1] = 0x21007;
        local_80 = (int)local_8;
      }
      if (local_14[0x14] != 0) {
        local_30 = local_30 | 8;
        local_2b = local_2b | 0xfe;
      }
      if (1 < (uint)local_14[5]) {
        local_98[1] = local_98[1] | 0x800000;
        local_2a = local_2a | 0x20;
        local_84 = local_14[5];
      }
      iVar2 = FUN_008a1a14(local_98,0x7c,local_10);
      if ((iVar2 < 0) ||
         ((*(int *)(local_18 + 4) == 1 &&
          (iVar2 = FUN_008a1a14(piVar1[2],0x400,local_10), iVar2 < 0)))) {
        return 0x80004005;
      }
      local_8 = piVar1;
      do {
        for (piVar4 = local_8; uVar5 = 0, piVar4 != (int *)0x0; piVar4 = (int *)piVar4[0x13]) {
          if (piVar4[5] != 0) {
            do {
              uVar8 = 0;
              if (piVar4[4] != 0) {
                do {
                  iVar2 = *local_14;
                  if (iVar2 < 0x34545845) {
                    if (iVar2 == 0x34545844) {
LAB_008a4b6c:
                      iVar2 = (piVar4[7] + uVar8 >> 2) * piVar4[0xc] +
                              (piVar4[10] + uVar5) * piVar4[0xd] + ((uint)piVar4[6] >> 2) * 0x10;
                      iVar3 = (piVar4[3] + 3U >> 2) << 4;
                    }
                    else {
                      if (iVar2 != 0x31545844) {
                        if (iVar2 != 0x32545844) {
                          if (iVar2 == 0x32595559) goto LAB_008a4c6e;
                          if (iVar2 != 0x33545844) goto LAB_008a4c42;
                        }
                        goto LAB_008a4b6c;
                      }
                      iVar2 = (piVar4[7] + uVar8 >> 2) * piVar4[0xc] +
                              (piVar4[10] + uVar5) * piVar4[0xd] + ((uint)piVar4[6] >> 2) * 8;
                      iVar3 = (piVar4[3] + 3U >> 2) << 3;
                    }
                    iVar2 = iVar2 + piVar4[1];
                    uVar8 = uVar8 + 3;
                  }
                  else {
                    if (iVar2 == 0x35545844) goto LAB_008a4b6c;
                    if (((iVar2 == 0x42475247) || (iVar2 == 0x47424752)) || (iVar2 == 0x59565955)) {
LAB_008a4c6e:
                      iVar2 = (piVar4[7] + uVar8) * piVar4[0xc] + (piVar4[10] + uVar5) * piVar4[0xd]
                              + piVar4[6] * local_c + piVar4[1];
                      iVar3 = (piVar4[3] + 1U >> 1) << 2;
                    }
                    else {
LAB_008a4c42:
                      iVar2 = (piVar4[7] + uVar8) * piVar4[0xc] + (piVar4[10] + uVar5) * piVar4[0xd]
                              + piVar4[6] * local_c + piVar4[1];
                      iVar3 = piVar4[3] * local_c;
                    }
                  }
                  iVar2 = FUN_008a1a14(iVar2,iVar3,local_10);
                  if (iVar2 < 0) {
                    return 0x80004005;
                  }
                  uVar8 = uVar8 + 1;
                } while (uVar8 < (uint)piVar4[4]);
              }
              uVar5 = uVar5 + 1;
            } while (uVar5 < (uint)piVar4[5]);
          }
        }
        local_8 = (int *)local_8[0x14];
        if (local_8 == (int *)0x0) {
          return 0;
        }
      } while( true );
    }
  }
  return 0x80004005;
}


// ==== _StringCopyWorkerA@12 @ 0x008a4c9c ====

/* Library Function - Single Match
    _StringCopyWorkerA@12
   
   Library: Visual Studio 2005 Release */

undefined4 _StringCopyWorkerA_12(char *param_1,int param_2,char *param_3)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 == 0) {
    uVar1 = 0x80070057;
  }
  else {
    do {
      if (*param_3 == '\0') break;
      *param_1 = *param_3;
      param_1 = param_1 + 1;
      param_3 = param_3 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
    if (param_2 == 0) {
      param_1 = param_1 + -1;
      uVar1 = 0x8007007a;
    }
    *param_1 = '\0';
  }
  return uVar1;
}


// ==== _StringVPrintfWorkerA@16 @ 0x008a4cd9 ====

/* Library Function - Single Match
    _StringVPrintfWorkerA@16
   
   Library: Visual Studio 2005 Release */

undefined4 _StringVPrintfWorkerA_16(char *param_1,int param_2,char *param_3,va_list param_4)

{
  uint _Count;
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_2 == 0) {
    uVar2 = 0x80070057;
  }
  else {
    _Count = param_2 - 1;
    uVar1 = __vsnprintf(param_1,_Count,param_3,param_4);
    if (((int)uVar1 < 0) || (_Count < uVar1)) {
      uVar2 = 0x8007007a;
    }
    else if (uVar1 != _Count) {
      return 0;
    }
    param_1[_Count] = '\0';
  }
  return uVar2;
}


// ==== FUN_008a4d25 @ 0x008a4d25 ====

void FUN_008a4d25(void)

{
  int in_ECX;
  
  FUN_008a1bb6();
  if (*(int *)(in_ECX + 0x14) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x14) + 8))(*(int **)(in_ECX + 0x14));
  }
  if (*(void **)(in_ECX + 0x18) == (void *)0x0) {
    FUN_008b67a3();
    return;
  }
  _free(*(void **)(in_ECX + 0x18));
  return;
}


// ==== FUN_008a4d54 @ 0x008a4d54 ====

undefined4 FUN_008a4d54(short *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (((param_2 < 0xe) || (*param_1 != 0x4d42)) || (param_2 < *(uint *)(param_1 + 1))) {
    uVar1 = 0x80004005;
  }
  else {
    uVar1 = FUN_008a1dc0(param_1 + 7,param_2 - 0xe);
  }
  return uVar1;
}


// ==== FID_conflict:_StringCchCopyA@12 @ 0x008a4d88 ====

/* Library Function - Multiple Matches With Different Base Names
    _StringCbCopyA@12
    _StringCchCopyA@12
   
   Library: Visual Studio 2005 Release */

undefined4 FID_conflict__StringCchCopyA_12(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (param_2 < 0x80000000) {
    uVar1 = _StringCopyWorkerA_12();
    return uVar1;
  }
  return 0x80070057;
}


// ==== FID_conflict:_StringCbPrintfA @ 0x008a4da5 ====

/* Library Function - Multiple Matches With Different Base Names
    _StringCbPrintfA
    _StringCchPrintfA
   
   Library: Visual Studio 2005 Release */

HRESULT FID_conflict__StringCbPrintfA
                  (STRSAFE_LPSTR pszDest,size_t cbDest,STRSAFE_LPCSTR pszFormat,...)

{
  HRESULT HVar1;
  undefined1 uStack00000010;
  
  if (cbDest < 0x80000000) {
    HVar1 = _StringVPrintfWorkerA_16(pszDest,cbDest,pszFormat,&uStack00000010);
    return HVar1;
  }
  return -0x7ff8ffa9;
}


// ==== FUN_008a4dce @ 0x008a4dce ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008a4dce(char *param_1,uint param_2)

{
  float fVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 *in_ECX;
  int iVar5;
  char *pcVar6;
  float *pfVar7;
  float *pfVar8;
  char *pcVar9;
  float *pfVar10;
  bool bVar11;
  float10 fVar12;
  float local_224;
  float *local_220;
  int local_21c;
  int local_218;
  int local_214;
  int local_210;
  char *local_20c;
  undefined1 local_208 [256];
  char local_108 [256];
  undefined4 local_8;
  
  iVar5 = 3;
  local_8 = DAT_00b49670;
  if (param_2 < 4) {
    return 0x80004005;
  }
  bVar11 = true;
  pcVar6 = &DAT_00a168d4;
  pcVar9 = param_1;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    bVar11 = *pcVar6 == *pcVar9;
    pcVar6 = pcVar6 + 1;
    pcVar9 = pcVar9 + 1;
  } while (bVar11);
  if (bVar11) {
    local_214 = 0;
  }
  else {
    iVar5 = 3;
    bVar11 = true;
    pcVar6 = &DAT_00a168d0;
    pcVar9 = param_1;
    do {
      if (iVar5 == 0) break;
      iVar5 = iVar5 + -1;
      bVar11 = *pcVar6 == *pcVar9;
      pcVar6 = pcVar6 + 1;
      pcVar9 = pcVar9 + 1;
    } while (bVar11);
    if (!bVar11) {
      return 0x80004005;
    }
    local_214 = 1;
  }
  local_20c = param_1 + 3;
  param_2 = param_2 - 3;
  uVar3 = 0x100;
  if (param_2 < 0x101) {
    uVar3 = param_2;
  }
  iVar5 = FUN_008a1d6f(local_20c,uVar3);
  if (iVar5 != 0) {
    FID_conflict__StringCchCopyA_12(local_108,iVar5 + 1,local_20c);
    iVar2 = _sscanf(local_108,s__u__u_s_00a168c8,&local_218,&local_21c,local_208);
    if (iVar2 == 2) {
      local_20c = local_20c + iVar5 + 1;
      param_2 = param_2 + (-1 - iVar5);
      if (param_2 != 0) {
        uVar3 = 0x100;
        if (param_2 < 0x101) {
          uVar3 = param_2;
        }
        local_210 = FUN_008a1d6f(local_20c,uVar3);
        pcVar6 = local_20c;
        if (local_210 != 0) {
          FID_conflict__StringCchCopyA_12(local_108,local_210 + 1,local_20c);
          iVar5 = _sscanf(local_108,&DAT_00a168c0,&local_224,local_208);
          if ((iVar5 == 1) &&
             (local_20c = (char *)(uint)(DAT_0099cdc8 <= local_224),
             ((uint)(local_214 == 0) * 2 + 1) * local_218 * local_21c * 4 <=
             (param_2 - local_210) - 1)) {
            in_ECX[0xd] = 0;
            in_ECX[0xc] = local_218 * 0x10;
            in_ECX[3] = local_218;
            *in_ECX = 0x74;
            in_ECX[4] = local_21c;
            in_ECX[5] = 1;
            in_ECX[0xe] = 1;
            pvVar4 = operator_new(local_218 * 0x10 * local_21c);
            in_ECX[1] = pvVar4;
            if (pvVar4 == (void *)0x0) {
              return 0x8007000e;
            }
            pfVar10 = (float *)(pcVar6 + local_210 + 1);
            while (local_210 = local_21c + -1, -1 < local_210) {
              pfVar7 = (float *)(local_210 * local_218 * 0x10 + in_ECX[1]);
              local_220 = pfVar7 + local_218 * 4;
              local_21c = local_210;
              if (local_214 == 0) {
                if (local_20c == (char *)0x0) {
                  for (; pfVar7 != local_220; pfVar7 = pfVar7 + 4) {
                    *pfVar7 = *pfVar10;
                    pfVar7[1] = pfVar10[1];
                    fVar1 = pfVar10[2];
                    pfVar7[3] = 1.0;
                    pfVar7[2] = fVar1;
                    pfVar10 = pfVar10 + 3;
                  }
                }
                else if (pfVar7 != local_220) {
                  do {
                    fVar12 = (float10)FUN_008a1d90(*pfVar10);
                    *pfVar7 = (float)fVar12;
                    fVar12 = (float10)FUN_008a1d90(pfVar10[1]);
                    pfVar7[1] = (float)fVar12;
                    fVar12 = (float10)FUN_008a1d90(pfVar10[2]);
                    pfVar7[2] = (float)fVar12;
                    pfVar8 = pfVar7 + 4;
                    pfVar10 = pfVar10 + 3;
                    pfVar7[3] = 1.0;
                    pfVar7 = pfVar8;
                    local_21c = local_210;
                  } while (pfVar8 != local_220);
                }
              }
              else if (local_20c == (char *)0x0) {
                for (; pfVar7 != local_220; pfVar7 = pfVar7 + 4) {
                  fVar1 = *pfVar10;
                  pfVar10 = pfVar10 + 1;
                  pfVar7[2] = fVar1;
                  pfVar7[1] = fVar1;
                  *pfVar7 = fVar1;
                  pfVar7[3] = 1.0;
                }
              }
              else if (pfVar7 != local_220) {
                do {
                  fVar12 = (float10)FUN_008a1d90(*pfVar10);
                  pfVar7[2] = (float)fVar12;
                  pfVar10 = pfVar10 + 1;
                  pfVar7[1] = (float)fVar12;
                  *pfVar7 = (float)fVar12;
                  pfVar8 = pfVar7 + 4;
                  pfVar7[3] = 1.0;
                  pfVar7 = pfVar8;
                  local_21c = local_210;
                } while (pfVar8 != local_220);
              }
            }
            return 0;
          }
        }
      }
    }
  }
  return 0x80004005;
}


// ==== FUN_008a50dd @ 0x008a50dd ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008a50dd(void)

{
  char cVar1;
  undefined4 *_Memory;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 extraout_EAX;
  int *in_ECX;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  undefined4 local_10c;
  char local_108 [256];
  undefined4 local_8;
  
  local_10c = 0;
  local_8 = DAT_00b49670;
  _Memory = operator_new(in_ECX[3] * 0xc);
  if (_Memory == (undefined4 *)0x0) {
    return 0x8007000e;
  }
  if (*in_ECX == 0x74) {
    puVar8 = &DAT_00a168d4;
  }
  else {
    if (*in_ECX != 0x72) goto LAB_008a5267;
    puVar8 = &DAT_00a168d0;
  }
  iVar2 = FUN_008a1a14(puVar8,3,&local_10c);
  if (-1 < iVar2) {
    FID_conflict__StringCbPrintfA(local_108,0x100,s__u__u__1_000000_00a168d8,in_ECX[3],in_ECX[4]);
    pcVar3 = local_108;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    iVar2 = FUN_008a1a14(local_108,(int)pcVar3 - (int)(local_108 + 1),&local_10c);
    if (-1 < iVar2) {
      iVar2 = in_ECX[4] + -1;
      puVar7 = (undefined4 *)(in_ECX[0xc] * iVar2 + in_ECX[1]);
      for (; -1 < iVar2; iVar2 = iVar2 + -1) {
        if (*in_ECX == 0x74) {
          iVar5 = in_ECX[3];
          if (puVar7 != puVar7 + iVar5 * 4) {
            puVar4 = _Memory + 2;
            puVar6 = puVar7;
            do {
              puVar4[-2] = *puVar6;
              puVar4[-1] = puVar6[1];
              *puVar4 = puVar6[2];
              puVar6 = puVar6 + 4;
              puVar4 = puVar4 + 3;
            } while (puVar6 != puVar7 + iVar5 * 4);
          }
          iVar5 = in_ECX[3] * 0xc;
          puVar6 = _Memory;
        }
        else {
          iVar5 = in_ECX[3] << 2;
          puVar6 = puVar7;
        }
        iVar5 = FUN_008a1a14(puVar6,iVar5,&local_10c);
        if (iVar5 < 0) break;
        puVar7 = (undefined4 *)((int)puVar7 - in_ECX[0xc]);
      }
    }
  }
LAB_008a5267:
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_008a5287 @ 0x008a5287 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008a5287(undefined4 param_1)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  char *pcVar4;
  int iVar5;
  float fVar6;
  uint uVar7;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int in_ECX;
  byte *pbVar8;
  float *pfVar9;
  undefined4 local_140;
  int local_13c;
  uint local_138;
  char *local_134;
  undefined4 local_130;
  uint local_12c;
  void *local_128;
  char local_124;
  char local_123;
  undefined1 local_122;
  undefined1 local_121;
  byte local_11d;
  float local_11c;
  float local_118;
  undefined4 local_114;
  float local_110;
  byte local_109;
  char local_108 [256];
  undefined4 local_8;
  
  local_114 = 0;
  local_8 = DAT_00b49670;
  local_130 = param_1;
  local_140 = 0x80004005;
  if ((*(uint *)(in_ECX + 0x10) < 0x8000) && (*(uint *)(in_ECX + 0xc) < 0x8000)) {
    local_128 = operator_new(*(uint *)(in_ECX + 0xc) * *(uint *)(in_ECX + 0x10) * 4);
    local_134 = operator_new(0x80);
    if ((local_128 == (void *)0x0) || (local_134 == (char *)0x0)) {
      local_140 = 0x8007000e;
    }
    else {
      pcVar4 = PTR_s___RADIANCE__File_created_by_Micr_00b537ec;
      do {
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      iVar5 = FUN_008a1a14(PTR_s___RADIANCE__File_created_by_Micr_00b537ec,
                           (int)pcVar4 - (int)(PTR_s___RADIANCE__File_created_by_Micr_00b537ec + 1),
                           &local_114);
      if (-1 < iVar5) {
        __strtime(local_108);
        pcVar4 = local_108;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        iVar5 = FUN_008a1a14(local_108,(int)pcVar4 - (int)(local_108 + 1),&local_114);
        if ((-1 < iVar5) && (iVar5 = FUN_008a1a14(&DAT_00a018f8,1,&local_114), -1 < iVar5)) {
          __strdate(local_108);
          pcVar4 = local_108;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          iVar5 = FUN_008a1a14(local_108,(int)pcVar4 - (int)(local_108 + 1),&local_114);
          if ((-1 < iVar5) && (iVar5 = FUN_008a1a14(&DAT_00a065f0,2,&local_114), -1 < iVar5)) {
            FID_conflict__StringCbPrintfA(local_108,0x100,s__Y__u__X__u_00a168f8);
            pcVar4 = local_108;
            do {
              cVar1 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            iVar5 = FUN_008a1a14(local_108,(int)pcVar4 - (int)(local_108 + 1),&local_114);
            if (-1 < iVar5) {
              local_12c = 0;
              if (*(int *)(in_ECX + 0x10) != 0) {
                do {
                  pfVar9 = (float *)(*(int *)(in_ECX + 0x30) * local_12c + *(int *)(in_ECX + 4));
                  local_138 = 0;
                  pbVar8 = (byte *)((int)local_128 + *(int *)(in_ECX + 0xc) * local_12c * 4);
                  if (*(int *)(in_ECX + 0xc) != 0) {
                    do {
                      if (*pfVar9 <= DAT_0099cdc8) {
                        local_11c = 0.0;
                      }
                      else {
                        local_11c = *pfVar9;
                      }
                      if (pfVar9[1] <= DAT_0099cdc8) {
                        local_118 = 0.0;
                      }
                      else {
                        local_118 = pfVar9[1];
                      }
                      if (pfVar9[2] <= DAT_0099cdc8) {
                        fVar6 = 0.0;
                      }
                      else {
                        fVar6 = pfVar9[2];
                      }
                      local_110 = local_11c;
                      if (local_11c <= local_118) {
                        local_110 = local_118;
                      }
                      if (local_110 <= fVar6) {
                        local_110 = fVar6;
                      }
                      if (local_110 <= (float)_DAT_00a168f0) {
                        pbVar8[3] = 0;
                        pbVar8[2] = 0;
                        pbVar8[1] = 0;
                        *pbVar8 = 0;
                      }
                      else {
                        _frexp((double)local_110,&local_13c);
                        local_13c = local_13c + 0x80;
                        local_109 = __ftol();
                        *pbVar8 = local_109;
                        local_11d = __ftol();
                        pbVar8[1] = local_11d;
                        bVar3 = __ftol();
                        pbVar8[2] = bVar3;
                        if (((local_109 != 0) || (local_11d != 0)) || (bVar2 = false, bVar3 != 0)) {
                          bVar2 = true;
                        }
                        pbVar8[3] = !bVar2 - 1U & (byte)local_13c;
                      }
                      local_138 = local_138 + 1;
                      pfVar9 = pfVar9 + 4;
                      pbVar8 = pbVar8 + 4;
                    } while (local_138 < *(uint *)(in_ECX + 0xc));
                  }
                  local_12c = local_12c + 1;
                } while (local_12c < *(uint *)(in_ECX + 0x10));
              }
              local_11c = 0.0;
              if (*(int *)(in_ECX + 0x10) != 0) {
                do {
                  local_122 = (undefined1)((uint)*(undefined4 *)(in_ECX + 0xc) >> 8);
                  local_121 = *(undefined1 *)(in_ECX + 0xc);
                  local_124 = '\x02';
                  local_123 = '\x02';
                  iVar5 = FUN_008a1a14(&local_124,4,&local_114);
                  if (iVar5 < 0) goto LAB_008a57ee;
                  local_118 = 0.0;
                  do {
                    fVar6 = *(float *)(in_ECX + 0xc);
                    local_110 = 0.0;
                    pcVar4 = (char *)((int)local_118 + (int)fVar6 * (int)local_11c * 4 +
                                     (int)local_128);
                    if (fVar6 != 0.0) {
                      do {
                        bVar3 = 1;
                        if ((int)local_110 + 1U < (uint)fVar6) {
                          do {
                            if ((0x7e < bVar3) || (pcVar4[(uint)bVar3 * 4] != *pcVar4)) break;
                            bVar3 = bVar3 + 1;
                          } while ((uint)bVar3 + (int)local_110 < (uint)fVar6);
                          if (bVar3 < 2) goto LAB_008a56fd;
                          local_124 = bVar3 + 0x80;
                          local_123 = *pcVar4;
                          iVar5 = FUN_008a1a14(&local_124,2,&local_114);
                          if (iVar5 < 0) goto LAB_008a57ee;
                        }
                        else {
LAB_008a56fd:
                          local_109 = 1;
                          *local_134 = *pcVar4;
                          if ((int)local_110 + 1U < (uint)*(float *)(in_ECX + 0xc)) {
                            do {
                              if (0x7e < local_109) break;
                              uVar7 = (uint)local_109;
                              if (pcVar4[uVar7 * 4 + -4] == pcVar4[uVar7 * 4]) break;
                              local_134[uVar7] = pcVar4[uVar7 * 4];
                              local_109 = local_109 + 1;
                            } while ((uint)local_109 + (int)local_110 < *(uint *)(in_ECX + 0xc));
                          }
                          iVar5 = FUN_008a1a14(&local_109,1,&local_114);
                          if ((iVar5 < 0) ||
                             (iVar5 = FUN_008a1a14(local_134,local_109,&local_114), iVar5 < 0))
                          goto LAB_008a57ee;
                          bVar3 = local_109;
                        }
                        local_110 = (float)((int)local_110 + (uint)bVar3);
                        pcVar4 = pcVar4 + (uint)bVar3 * 4;
                        fVar6 = *(float *)(in_ECX + 0xc);
                      } while ((uint)local_110 < (uint)fVar6);
                    }
                    local_118 = (float)((int)local_118 + 1);
                  } while ((int)local_118 < 4);
                  local_11c = (float)((int)local_11c + 1);
                } while ((uint)local_11c < *(uint *)(in_ECX + 0x10));
              }
              local_140 = 0;
            }
          }
        }
      }
    }
LAB_008a57ee:
    if (local_128 != (void *)0x0) {
      _free(local_128);
      return extraout_EAX;
    }
    if (local_134 != (char *)0x0) {
      _free(local_134);
      return extraout_EAX_00;
    }
  }
  return local_140;
}


// ==== FUN_008a582d @ 0x008a582d ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

undefined4 FUN_008a582d(short *param_1,uint param_2)

{
  char cVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  char *pcVar10;
  char *pcVar11;
  uint uVar12;
  float *pfVar13;
  uint uVar14;
  undefined4 extraout_EAX;
  byte bVar16;
  undefined4 *in_ECX;
  int iVar15;
  int iVar17;
  uint *puVar18;
  uint *puVar19;
  uint uVar20;
  short *psVar21;
  bool bVar22;
  double dVar23;
  float local_268;
  int local_264;
  int local_260;
  float *local_25c;
  uint local_258;
  uint local_254;
  int local_250;
  float local_24c;
  float *local_248;
  undefined4 local_240;
  char local_239;
  uint local_238;
  char local_232;
  char local_231;
  uint local_230;
  uint *local_22c;
  char local_128;
  char local_127;
  char local_126;
  char local_125 [253];
  char local_28 [4];
  char acStack_24 [4];
  char acStack_20 [4];
  char acStack_1c [4];
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined *puStack_c;
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  local_230 = param_2;
  local_22c = (uint *)param_1;
  if (param_2 < 0xb) {
    return 0x80004005;
  }
  iVar15 = 5;
  bVar22 = true;
  psVar21 = (short *)s___RADIANCE_00a16940;
  do {
    if (iVar15 == 0) break;
    iVar15 = iVar15 + -1;
    bVar22 = *param_1 == *psVar21;
    param_1 = param_1 + 1;
    psVar21 = psVar21 + 1;
  } while (bVar22);
  if (!bVar22) {
    return 0x80004005;
  }
  local_250 = 0;
  local_24c = 1.0;
  if ((int)param_2 < 1) {
    return 0x80004005;
  }
  do {
    puVar18 = local_22c;
    if ((char)*local_22c == '\n') {
      local_22c = (uint *)((int)local_22c + 1);
      local_230 = local_230 - 1;
      break;
    }
    pcVar11 = s_FORMAT__00a16938;
    do {
      pcVar10 = pcVar11;
      pcVar11 = pcVar10 + 1;
    } while (*pcVar10 != '\0');
    if ((int)(pcVar10 + -0xa16938) < (int)local_230) {
      pcVar11 = s_FORMAT__00a16938;
      do {
        pcVar10 = pcVar11;
        pcVar11 = pcVar10 + 1;
      } while (*pcVar10 != '\0');
      pcVar10 = pcVar10 + -0xa16938;
      bVar22 = true;
      puVar19 = local_22c;
      pcVar11 = s_FORMAT__00a16938;
      do {
        if (pcVar10 == (char *)0x0) break;
        pcVar10 = pcVar10 + -1;
        bVar22 = (char)*(short *)puVar19 == *pcVar11;
        puVar19 = (uint *)((int)puVar19 + 1);
        pcVar11 = pcVar11 + 1;
      } while (bVar22);
      if (!bVar22) goto LAB_008a5995;
      pcVar11 = s_FORMAT__00a16938;
      do {
        pcVar10 = pcVar11;
        pcVar11 = pcVar10 + 1;
      } while (*pcVar10 != '\0');
      local_22c = (uint *)((int)local_22c + (int)(pcVar10 + -0xa16938));
      pcVar11 = s_FORMAT__00a16938;
      do {
        pcVar10 = pcVar11;
        pcVar11 = pcVar10 + 1;
      } while (*pcVar10 != '\0');
      local_230 = local_230 - (int)(pcVar10 + -0xa16938);
      for (; ((char)*local_22c == ' ' || ((char)*local_22c == '\t'));
          local_22c = (uint *)((int)local_22c + 1)) {
        local_230 = local_230 + -1;
        if (local_230 == 0) {
          return 0x80004005;
        }
      }
      local_18 = DAT_00a16928;
      uStack_14 = DAT_00a1692c;
      uStack_10 = DAT_00a16930;
      puStack_c = PTR_LAB_00656265_2_00a16934;
      local_28[0] = s_32_bit_rle_xyze_00a16918[0];
      local_28[1] = s_32_bit_rle_xyze_00a16918[1];
      local_28[2] = s_32_bit_rle_xyze_00a16918[2];
      local_28[3] = s_32_bit_rle_xyze_00a16918[3];
      acStack_24[0] = s_32_bit_rle_xyze_00a16918[4];
      acStack_24[1] = s_32_bit_rle_xyze_00a16918[5];
      acStack_24[2] = s_32_bit_rle_xyze_00a16918[6];
      acStack_24[3] = s_32_bit_rle_xyze_00a16918[7];
      acStack_20[0] = s_32_bit_rle_xyze_00a16918[8];
      acStack_20[1] = s_32_bit_rle_xyze_00a16918[9];
      acStack_20[2] = s_32_bit_rle_xyze_00a16918[10];
      acStack_20[3] = s_32_bit_rle_xyze_00a16918[0xb];
      acStack_1c[0] = s_32_bit_rle_xyze_00a16918[0xc];
      acStack_1c[1] = s_32_bit_rle_xyze_00a16918[0xd];
      acStack_1c[2] = s_32_bit_rle_xyze_00a16918[0xe];
      acStack_1c[3] = s_32_bit_rle_xyze_00a16918[0xf];
      if ((int)local_230 < 0x10) {
        return 0x80004005;
      }
      iVar15 = 0xf;
      bVar22 = true;
      puVar18 = local_22c;
      pcVar11 = (char *)&local_18;
      do {
        if (iVar15 == 0) break;
        iVar15 = iVar15 + -1;
        bVar22 = *(char *)puVar18 == *pcVar11;
        puVar18 = (uint *)((int)puVar18 + 1);
        pcVar11 = pcVar11 + 1;
      } while (bVar22);
      if (!bVar22) {
        iVar15 = 0xf;
        bVar22 = true;
        puVar18 = local_22c;
        pcVar11 = local_28;
        do {
          if (iVar15 == 0) break;
          iVar15 = iVar15 + -1;
          bVar22 = *(char *)puVar18 == *pcVar11;
          puVar18 = (uint *)((int)puVar18 + 1);
          pcVar11 = pcVar11 + 1;
        } while (bVar22);
        if (!bVar22) {
          return 0x80004005;
        }
      }
      local_22c = (uint *)((int)local_22c + 0x10);
      local_230 = local_230 - 0x10;
      local_250 = 1;
    }
    else {
LAB_008a5995:
      pcVar11 = s_EXPOSURE__00a1690c;
      do {
        pcVar10 = pcVar11;
        pcVar11 = pcVar10 + 1;
      } while (*pcVar10 != '\0');
      if ((int)(pcVar10 + -0xa1690c) < (int)local_230) {
        pcVar11 = s_EXPOSURE__00a1690c;
        do {
          pcVar10 = pcVar11;
          pcVar11 = pcVar10 + 1;
        } while (*pcVar10 != '\0');
        pcVar10 = pcVar10 + -0xa1690c;
        bVar22 = true;
        puVar19 = local_22c;
        pcVar11 = s_EXPOSURE__00a1690c;
        do {
          if (pcVar10 == (char *)0x0) break;
          pcVar10 = pcVar10 + -1;
          bVar22 = (char)*(short *)puVar19 == *pcVar11;
          puVar19 = (uint *)((int)puVar19 + 1);
          pcVar11 = pcVar11 + 1;
        } while (bVar22);
        if (bVar22) {
          pcVar11 = s_EXPOSURE__00a1690c;
          do {
            pcVar10 = pcVar11;
            pcVar11 = pcVar10 + 1;
          } while (*pcVar10 != '\0');
          local_22c = (uint *)((int)local_22c + (int)(pcVar10 + -0xa1690c));
          pcVar11 = s_EXPOSURE__00a1690c;
          do {
            pcVar10 = pcVar11;
            pcVar11 = pcVar10 + 1;
          } while (*pcVar10 != '\0');
          local_230 = local_230 - (int)(pcVar10 + -0xa1690c);
          while( true ) {
            puVar18 = local_22c;
            if (((char)*local_22c != ' ') && ((char)*local_22c != '\t')) break;
            local_230 = local_230 + -1;
            if (local_230 == 0) {
              return 0x80004005;
            }
            local_22c = (uint *)((int)local_22c + 1);
          }
          iVar15 = FUN_008a1d6f();
          if (iVar15 == 0) {
            return 0x80004005;
          }
          FID_conflict__StringCchCopyA_12(&local_128,iVar15 + 1,puVar18);
          iVar17 = _sscanf(&local_128,&DAT_00a168c0);
          if (iVar17 != 1) {
            return 0x80004005;
          }
          local_22c = (uint *)((int)puVar18 + iVar15 + 1);
          local_24c = local_268 * local_24c;
          local_230 = local_230 + (-1 - iVar15);
          goto LAB_008a5ad8;
        }
      }
      iVar15 = FUN_008a1d6f();
      local_22c = (uint *)((int)puVar18 + iVar15 + 1);
      local_230 = local_230 + (-1 - iVar15);
    }
LAB_008a5ad8:
  } while (0 < (int)local_230);
  if (local_250 == 0) {
    return 0x80004005;
  }
  local_238 = FUN_008a1d6f();
  if (local_238 < 3) {
    return 0x80004005;
  }
  FID_conflict__StringCchCopyA_12(&local_128,local_238 + 1,local_22c);
  if (local_127 == 'Y') {
    local_232 = '\x01';
    puVar18 = &local_254;
    if (local_128 == '-') {
      local_231 = '\0';
    }
    else {
      if (local_128 != '+') {
        return 0x80004005;
      }
      local_231 = '\x01';
    }
  }
  else {
    if (local_127 != 'X') {
      return 0x80004005;
    }
    local_232 = '\0';
    puVar18 = &local_258;
    if (local_128 == '-') {
      local_239 = '\0';
    }
    else {
      if (local_128 != '+') {
        return 0x80004005;
      }
      local_239 = '\x01';
    }
  }
  iVar15 = _sscanf(&local_126,&DAT_00a16908,puVar18);
  if (iVar15 != 1) {
    return 0x80004005;
  }
  pcVar11 = &local_126;
  if (local_126 == '\0') {
    return 0x80004005;
  }
  do {
    if ((local_126 == '-') || (local_126 == '+')) break;
    pcVar11 = pcVar11 + 1;
    local_126 = *pcVar11;
  } while (local_126 != '\0');
  cVar1 = *pcVar11;
  if (cVar1 == '\0') {
    return 0x80004005;
  }
  if (local_232 == '\0') {
    local_231 = cVar1 == '+';
    puVar18 = &local_254;
  }
  else {
    local_239 = cVar1 == '+';
    puVar18 = &local_258;
  }
  cVar1 = pcVar11[1];
  if (cVar1 == '\0') {
    return 0x80004005;
  }
  if ((cVar1 != 'Y') && (cVar1 != 'X')) {
    return 0x80004005;
  }
  iVar15 = _sscanf(pcVar11 + 2,&DAT_00a16908,puVar18);
  if (iVar15 != 1) {
    return 0x80004005;
  }
  in_ECX[0xd] = 0;
  local_22c = (uint *)((int)local_22c + local_238 + 1);
  local_230 = local_230 + (-1 - local_238);
  in_ECX[3] = local_258;
  *in_ECX = 0x74;
  in_ECX[0xc] = local_258 * 0x10;
  in_ECX[4] = local_254;
  in_ECX[5] = 1;
  if (local_258 * local_254 == 0) {
    return 0x80004005;
  }
  in_ECX[0xe] = 1;
  local_25c = operator_new(local_258 * 0x10 * local_254);
  in_ECX[1] = local_25c;
  if (local_25c == (float *)0x0) {
    return 0x8007000e;
  }
  if (local_232 != '\0') {
    uVar12 = in_ECX[0xc];
    uVar8 = local_254;
    uVar9 = local_258;
    if (local_239 == '\0') {
      uVar20 = 0xfffffffc;
      if (local_231 != '\0') {
        iVar15 = uVar12 * local_254 + -0x10;
        goto LAB_008a5d4e;
      }
      iVar15 = uVar12 - 0x10;
    }
    else {
      uVar20 = 4;
      if (local_231 == '\0') {
        uVar12 = uVar12 >> 2;
        goto LAB_008a5da7;
      }
      iVar15 = (local_254 - 1) * uVar12;
LAB_008a5d4e:
      uVar12 = -uVar12;
    }
    local_25c = (float *)(iVar15 + (int)local_25c);
    uVar12 = uVar12 >> 2;
    goto LAB_008a5da9;
  }
  uVar20 = in_ECX[0xc];
  uVar8 = local_258;
  uVar9 = local_254;
  if (local_239 == '\0') {
    if (local_231 != '\0') {
      iVar15 = uVar20 * local_254 + -0x10;
      uVar12 = 0xfffffffc;
      goto LAB_008a5d7f;
    }
    iVar15 = uVar20 - 0x10;
    uVar12 = 0xfffffffc;
  }
  else {
    uVar12 = 4;
    if (local_231 == '\0') {
      uVar20 = uVar20 >> 2;
LAB_008a5da7:
      goto LAB_008a5da9;
    }
    iVar15 = (local_254 - 1) * uVar20;
LAB_008a5d7f:
    uVar20 = -uVar20;
  }
  local_25c = (float *)(iVar15 + (int)local_25c);
  uVar20 = uVar20 >> 2;
LAB_008a5da9:
  local_264 = 0;
  if (0 < (int)uVar8) {
    do {
      if ((int)local_230 < 4) {
LAB_008a61ca:
        _free((void *)in_ECX[1]);
        return extraout_EAX;
      }
      pfVar13 = (float *)*local_22c;
      local_22c = local_22c + 1;
      local_230 = local_230 + -4;
      local_240._3_1_ = (byte)((uint)pfVar13 >> 0x18);
      local_240._2_1_ = (byte)((uint)pfVar13 >> 0x10);
      local_240 = pfVar13;
      if (((char)pfVar13 == '\x02') ||
         ((bVar16 = (byte)((uint)pfVar13 >> 8), bVar16 == 2 && (local_240._2_1_ < 0x80)))) {
        uVar7 = CONCAT11(local_240._2_1_,local_240._3_1_);
        if (uVar7 != uVar9) goto LAB_008a61ca;
        local_260 = 0;
        local_248 = local_25c;
        do {
          iVar15 = 0;
          local_240 = local_248;
          if (0 < (int)uVar9) {
            do {
              if ((int)local_230 < 2) goto LAB_008a61ca;
              bVar16 = (byte)*local_22c;
              if (bVar16 < 0x81) {
                uVar14 = (uint)bVar16;
                if ((int)local_230 < (int)(uVar14 + 1)) goto LAB_008a61ca;
                iVar15 = iVar15 + uVar14;
                if ((int)uVar9 < iVar15) goto LAB_008a61ca;
                if (bVar16 != 0) {
                  puVar18 = local_22c;
                  local_238 = uVar14;
                  do {
                    puVar18 = (uint *)((int)puVar18 + 1);
                    pfVar13 = local_240 + uVar20;
                    local_238 = local_238 - 1;
                    *local_240 = (float)*(byte *)puVar18;
                    local_240 = pfVar13;
                  } while (local_238 != 0);
                  local_238 = 0;
                }
                local_230 = local_230 + (-1 - uVar14);
                local_22c = (uint *)((int)local_22c + uVar14 + 1);
              }
              else {
                uVar14 = bVar16 & 0x7f;
                iVar15 = iVar15 + uVar14;
                if ((int)uVar9 < iVar15) goto LAB_008a61ca;
                local_238 = (uint)*(byte *)((int)local_22c + 1);
                if ((bVar16 & 0x7f) != 0) {
                  do {
                    pfVar13 = local_240 + uVar20;
                    *local_240 = (float)local_238;
                    uVar14 = uVar14 - 1;
                    local_240 = pfVar13;
                  } while (uVar14 != 0);
                }
                local_22c = (uint *)((int)local_22c + 2);
                local_230 = local_230 + -2;
              }
            } while (iVar15 < (int)uVar9);
          }
          local_260 = local_260 + 1;
          local_248 = local_248 + 1;
        } while (local_260 < 4);
      }
      else {
        local_248 = (float *)0x0;
        iVar15 = 1;
        fVar3 = (float)((uint)pfVar13 & 0xff);
        fVar4 = (float)bVar16;
        local_238 = (uint)local_240._3_1_;
        fVar5 = (float)local_240._2_1_;
        fVar6 = (float)local_238;
        pfVar13 = local_25c;
        if (1 < (int)uVar9) {
          do {
            if ((int)local_230 < 4) goto LAB_008a61ca;
            pfVar2 = (float *)*local_22c;
            local_22c = local_22c + 1;
            local_230 = local_230 + -4;
            bVar16 = (byte)((uint)pfVar2 >> 8);
            local_240._2_1_ = (byte)((uint)pfVar2 >> 0x10);
            local_240._3_1_ = (byte)((uint)pfVar2 >> 0x18);
            local_240 = pfVar2;
            if ((((char)pfVar2 == '\x01') && (bVar16 == 1)) && (local_240._2_1_ == 1)) {
              iVar17 = (uint)local_240._3_1_ << ((byte)local_248 & 0x1f);
              iVar15 = iVar15 + iVar17;
              if ((int)uVar9 < iVar15) goto LAB_008a61ca;
              if (0 < iVar17) {
                do {
                  *pfVar13 = fVar3;
                  pfVar13[1] = fVar4;
                  pfVar13[2] = fVar5;
                  pfVar13[3] = fVar6;
                  pfVar13 = pfVar13 + uVar20;
                  iVar17 = iVar17 + -1;
                } while (iVar17 != 0);
              }
              local_248 = local_248 + 2;
            }
            else {
              local_248 = (float *)0x0;
              fVar3 = (float)((uint)pfVar2 & 0xff);
              *pfVar13 = fVar3;
              fVar4 = (float)bVar16;
              local_238 = (uint)local_240._3_1_;
              pfVar13[1] = fVar4;
              fVar5 = (float)local_240._2_1_;
              iVar15 = iVar15 + 1;
              pfVar13[2] = fVar5;
              fVar6 = (float)local_238;
              pfVar13[3] = fVar6;
              pfVar13 = pfVar13 + uVar20;
            }
          } while (iVar15 < (int)uVar9);
        }
      }
      local_264 = local_264 + 1;
      local_25c = local_25c + uVar12;
    } while (local_264 < (int)uVar8);
  }
  uVar12 = 0;
  if (local_258 * local_254 != 0) {
    local_24c = 1.0 / local_24c;
    pfVar13 = (float *)(in_ECX[1] + 8);
    do {
      iVar15 = __ftol();
      iVar15 = iVar15 + -0x88;
      dVar23 = _ldexp((double)(pfVar13[-2] + DAT_0099d0b4),iVar15);
      pfVar13[-2] = (float)dVar23 * local_24c;
      dVar23 = _ldexp((double)(pfVar13[-1] + DAT_0099d0b4),iVar15);
      pfVar13[-1] = (float)dVar23 * local_24c;
      dVar23 = _ldexp((double)(*pfVar13 + DAT_0099d0b4),iVar15);
      uVar12 = uVar12 + 1;
      *pfVar13 = (float)dVar23 * local_24c;
      pfVar13[1] = 1.0;
      pfVar13 = pfVar13 + 4;
    } while (uVar12 < local_258 * local_254);
  }
  return 0;
}


// ==== FUN_008a61eb @ 0x008a61eb ====

undefined4 FUN_008a61eb(int param_1,int param_2,undefined4 *param_3,int param_4)

{
  char *pcVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  undefined4 extraout_EAX_01;
  undefined4 uVar2;
  undefined4 *in_ECX;
  int iVar3;
  undefined4 *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  bool bVar7;
  char *local_30 [10];
  uint local_8;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return 0x8876086c;
  }
  if ((param_3 == (undefined4 *)0x0) && (param_4 == 0)) {
    return 0;
  }
  local_30[0] = (char *)0x0;
  local_30[1] = (char *)0x5;
  local_30[2] = (char *)0x4;
  local_30[3] = (char *)0x1;
  local_30[4] = (char *)0x3;
  local_30[5] = (char *)0x8;
  local_30[6] = (char *)0x7;
  local_30[7] = (char *)0x2;
  local_30[8] = (char *)0x6;
  pcVar1 = (char *)FUN_008015fc(4,0);
  local_30[9] = __strdup(pcVar1);
  if (local_30[9] != (char *)0x0) {
    iVar3 = 2;
    bVar7 = true;
    pcVar1 = local_30[9];
    pcVar5 = &DAT_009fe224;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pcVar1 == *pcVar5;
      pcVar1 = pcVar1 + 1;
      pcVar5 = pcVar5 + 1;
    } while (bVar7);
    if (bVar7) goto LAB_008a628e;
  }
  FUN_008015fc(4,&DAT_009fe224);
LAB_008a628e:
  local_8 = 0;
  iVar3 = param_2;
  do {
    in_ECX[0x10] = param_4;
    pcVar1 = local_30[local_8];
    in_ECX[0x11] = 3;
    in_ECX[0x12] = pcVar1;
    switch(pcVar1) {
    case (char *)0x0:
      iVar3 = FUN_008a4d54(param_1,param_2);
      break;
    case (char *)0x1:
      iVar3 = FUN_008a2f78(param_1,param_2);
      break;
    case (char *)0x2:
      iVar3 = FUN_008a34d3(param_1,param_2);
      break;
    case (char *)0x3:
      iVar3 = FUN_008a3fa7(param_1,param_2);
      break;
    case (char *)0x4:
      iVar3 = FUN_008a463f(param_1,param_2);
      break;
    case (char *)0x5:
      iVar3 = FUN_008a3aa5(param_1,param_2);
      break;
    case (char *)0x6:
      iVar3 = FUN_008a1dc0(param_1,param_2);
      break;
    case (char *)0x7:
      iVar3 = FUN_008a582d(param_1,param_2);
      break;
    case (char *)0x8:
      iVar3 = FUN_008a4dce(param_1,param_2);
    }
    if (-1 < iVar3) break;
    if (((void *)in_ECX[1] != (void *)0x0) && (in_ECX[0xe] != 0)) {
      _free((void *)in_ECX[1]);
      return extraout_EAX;
    }
    if (((void *)in_ECX[2] != (void *)0x0) && (in_ECX[0xf] != 0)) {
      _free((void *)in_ECX[2]);
      return extraout_EAX_00;
    }
    if (in_ECX[0x13] != 0) {
      FUN_008a1c74(1);
    }
    if (in_ECX[0x14] != 0) {
      FUN_008a1c74(1);
    }
    local_8 = local_8 + 1;
    in_ECX[1] = 0;
    in_ECX[2] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
    in_ECX[0x13] = 0;
    in_ECX[0x14] = 0;
  } while (local_8 < 9);
  if (local_30[9] == (char *)0x0) {
    if (local_8 == 9) {
      return 0x88760b59;
    }
    puVar4 = in_ECX;
    if (param_3 != (undefined4 *)0x0) {
      puVar6 = param_3;
      for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      *param_3 = in_ECX[3];
      param_3[1] = in_ECX[4];
      param_3[2] = in_ECX[5];
      param_3[3] = 1;
      uVar2 = FUN_0089ff71(*in_ECX);
      param_3[4] = uVar2;
      param_3[5] = in_ECX[0x11];
      param_3[6] = in_ECX[0x12];
      for (puVar6 = in_ECX; puVar6[0x13] != 0; puVar6 = (undefined4 *)puVar6[0x13]) {
        param_3[3] = param_3[3] + 1;
      }
    }
    do {
      for (; in_ECX != (undefined4 *)0x0; in_ECX = (undefined4 *)in_ECX[0x13]) {
        in_ECX[8] = in_ECX[3];
        in_ECX[9] = in_ECX[4];
        in_ECX[6] = 0;
        in_ECX[7] = 0;
        in_ECX[10] = 0;
        in_ECX[0xb] = in_ECX[5];
      }
      in_ECX = (undefined4 *)puVar4[0x14];
      puVar4 = in_ECX;
    } while (in_ECX != (undefined4 *)0x0);
    return 0;
  }
  iVar3 = 2;
  bVar7 = true;
  pcVar1 = local_30[9];
  pcVar5 = &DAT_009fe224;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pcVar1 == *pcVar5;
    pcVar1 = pcVar1 + 1;
    pcVar5 = pcVar5 + 1;
  } while (bVar7);
  if (!bVar7) {
    FUN_008015fc(4,local_30[9]);
  }
  _free(local_30[9]);
  return extraout_EAX_01;
}


// ==== FUN_008a649d @ 0x008a649d ====

int FUN_008a649d(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  char *pcVar2;
  int extraout_EAX;
  int extraout_EAX_00;
  int *in_ECX;
  int *piVar3;
  int iVar4;
  undefined *puVar5;
  int *piVar6;
  char *pcVar7;
  bool bVar8;
  int iVar9;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0 [6];
  int local_c8 [6];
  undefined4 local_b0;
  undefined4 local_a4;
  int local_a0;
  void *local_9c;
  int local_98;
  int local_94;
  int local_90;
  int local_8c [4];
  undefined4 local_7c;
  int local_78;
  int local_74 [6];
  undefined4 local_5c;
  undefined4 local_50;
  int local_4c;
  int local_18;
  void *local_10;
  int *local_c;
  char *local_8;
  
  FUN_008a197b();
  switch(param_2) {
  case 0:
  case 6:
    puVar5 = &DAT_00b536a8;
    break;
  case 1:
    puVar5 = &DAT_00b53704;
    break;
  case 2:
    puVar5 = &DAT_00b536f8;
    break;
  case 3:
    puVar5 = &DAT_00b5370c;
    break;
  case 4:
    puVar5 = &DAT_00b53728;
    break;
  default:
    goto switchD_008a64c4_caseD_5;
  case 7:
  case 8:
    puVar5 = &DAT_00b5371c;
  }
  uVar1 = FUN_0089fd60(*in_ECX);
  iVar4 = FUN_0089fe02(puVar5,in_ECX[2],uVar1);
  local_18 = iVar4;
  if (iVar4 == 0) {
switchD_008a64c4_caseD_5:
    iVar4 = -0x7789f794;
LAB_008a681d:
    FUN_008a4d25();
    return iVar4;
  }
  if (iVar4 != *in_ECX) {
    FUN_008a6876();
    iVar4 = FUN_0089fd60(iVar4);
    pcVar2 = (char *)(*(uint *)(iVar4 + 8) >> 3);
    local_c = in_ECX;
    local_8 = pcVar2;
    do {
      for (; in_ECX != (int *)0x0; in_ECX = (int *)in_ECX[0x13]) {
        local_10 = operator_new(in_ECX[4] * in_ECX[5] * in_ECX[3] * (int)pcVar2);
        if (local_10 == (void *)0x0) {
          FUN_008a6880();
          iVar4 = -0x7ff8fff2;
          goto LAB_008a681d;
        }
        local_f0 = in_ECX[1];
        local_ec = *in_ECX;
        local_e8 = in_ECX[0xc];
        local_e4 = in_ECX[0xd];
        iVar9 = 6;
        piVar3 = in_ECX + 6;
        piVar6 = local_e0;
        for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar6 = *piVar3;
          piVar3 = piVar3 + 1;
          piVar6 = piVar6 + 1;
        }
        piVar3 = in_ECX + 6;
        piVar6 = local_c8;
        for (; iVar9 != 0; iVar9 = iVar9 + -1) {
          *piVar6 = *piVar3;
          piVar3 = piVar3 + 1;
          piVar6 = piVar6 + 1;
        }
        local_a4 = 0;
        local_b0 = 1;
        local_a0 = in_ECX[2];
        local_9c = local_10;
        local_98 = local_18;
        local_94 = in_ECX[3] * (int)local_8;
        local_90 = in_ECX[4] * in_ECX[3] * (int)local_8;
        local_8c[0] = 0;
        local_8c[1] = 0;
        local_8c[2] = in_ECX[3];
        local_8c[3] = in_ECX[4];
        local_7c = 0;
        local_78 = in_ECX[5];
        piVar3 = local_8c;
        piVar6 = local_74;
        for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar6 = *piVar3;
          piVar3 = piVar3 + 1;
          piVar6 = piVar6 + 1;
        }
        local_50 = 0;
        local_5c = 1;
        local_4c = in_ECX[2];
        iVar4 = FUN_008aa0c4(&local_9c,&local_f0,0x80001);
        if (iVar4 < 0) {
          _free(local_10);
          return extraout_EAX_00;
        }
        if (((void *)in_ECX[1] != (void *)0x0) && (in_ECX[0xe] != 0)) {
          _free((void *)in_ECX[1]);
          return extraout_EAX;
        }
        *in_ECX = local_18;
        in_ECX[1] = (int)local_10;
        piVar3 = local_74;
        piVar6 = in_ECX + 6;
        for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
          *piVar6 = *piVar3;
          piVar3 = piVar3 + 1;
          piVar6 = piVar6 + 1;
        }
        in_ECX[0xc] = local_94;
        in_ECX[0xd] = local_90;
        in_ECX[0xe] = 1;
        pcVar2 = local_8;
      }
      local_c = (int *)local_c[0x14];
      in_ECX = local_c;
    } while (local_c != (int *)0x0);
    FUN_008a6880();
  }
  iVar4 = FUN_008a199a(param_1,param_3);
  if (iVar4 < 0) goto LAB_008a681d;
  pcVar2 = (char *)FUN_008015fc(4,0);
  local_8 = __strdup(pcVar2);
  if (local_8 != (char *)0x0) {
    iVar4 = 2;
    bVar8 = true;
    pcVar2 = local_8;
    pcVar7 = &DAT_009fe224;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar8 = *pcVar2 == *pcVar7;
      pcVar2 = pcVar2 + 1;
      pcVar7 = pcVar7 + 1;
    } while (bVar8);
    if (bVar8) goto LAB_008a6732;
  }
  FUN_008015fc(4,&DAT_009fe224);
LAB_008a6732:
                    /* WARNING: Could not recover jumptable at 0x008a6735. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar4 = (**(code **)(&DAT_008a6852 + param_2 * 4))();
  return iVar4;
}


// ==== FUN_008a6876 @ 0x008a6876 ====

void FUN_008a6876(void)

{
  undefined4 *in_ECX;
  
  in_ECX[1] = 0;
  *in_ECX = 0;
  return;
}


// ==== FUN_008a6880 @ 0x008a6880 ====

void FUN_008a6880(void)

{
  int *in_ECX;
  
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
  }
  if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*in_ECX)(1);
  }
  return;
}


// ==== FUN_008a68a0 @ 0x008a68a0 ====

void FUN_008a68a0(float param_1)

{
  FUN_008044f0((double)param_1);
  return;
}


// ==== FUN_008a68b8 @ 0x008a68b8 ====

void FUN_008a68b8(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  return;
}


// ==== FUN_008a68ce @ 0x008a68ce ====

/* WARNING: Removing unreachable block (ram,0x008a6945) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * FUN_008a68ce(uint param_1,int param_2,int param_3)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  int iVar10;
  int *piVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int local_28;
  float local_24;
  uint local_1c;
  float local_18;
  uint local_10;
  float local_c;
  float local_8;
  
  uVar17 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    fVar2 = (float)param_2;
    if (param_2 < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    fVar3 = (float)(int)param_1;
    if ((int)param_1 < 0) {
      fVar3 = fVar3 + _DAT_0099d104;
    }
    fVar4 = fVar2 / fVar3;
    uVar15 = 0x10;
    fVar5 = DAT_0099d0b4 / fVar4;
    if (param_1 != 0) {
      do {
        iVar10 = __ftol();
        uVar17 = uVar17 + 1;
        uVar15 = uVar15 + 0xc + iVar10 * 0x10;
      } while (uVar17 < param_1);
    }
    piVar11 = operator_new(uVar15);
    if (piVar11 != (int *)0x0) {
      iVar14 = 0;
      local_1c = 0;
      iVar10 = 4;
      iVar16 = iVar10;
      if (param_1 != 0) {
        do {
          local_8 = 0.0;
          local_10 = 0;
          fVar6 = (float)(int)local_1c;
          iVar10 = iVar16 + 4;
          if ((int)local_1c < 0) {
            fVar6 = fVar6 + _DAT_0099d104;
          }
          do {
            fVar7 = (float)(int)local_10;
            if ((int)local_10 < 0) {
              fVar7 = fVar7 + _DAT_0099d104;
            }
            fVar7 = (fVar7 + fVar6) - DAT_0099d0b4;
            local_24 = fVar7 * fVar4;
            local_c = fVar4 + local_24;
            if (param_3 == 0) {
              if (local_24 < DAT_0099cdc8) {
                local_24 = 0.0;
              }
              if (fVar2 < local_c) {
                local_c = fVar2;
              }
            }
            FUN_008a68a0(local_24);
            iVar12 = __ftol();
            fVar8 = (float)iVar12;
            if (fVar8 < local_c) {
              local_28 = iVar12 - param_2;
              do {
                local_18 = DAT_0099d080 + fVar8;
                if (iVar12 < 0) {
                  iVar13 = iVar12 + param_2;
                }
                else {
                  iVar13 = local_28;
                  if (iVar12 < param_2) {
                    iVar13 = iVar12;
                  }
                }
                if (iVar13 != iVar14) {
                  if (_DAT_00a1694c < local_8) {
                    piVar1 = (int *)(iVar10 + (int)piVar11);
                    *piVar1 = iVar14;
                    iVar10 = iVar10 + 8;
                    piVar1[1] = (int)local_8;
                  }
                  local_8 = 0.0;
                  iVar14 = iVar13;
                }
                if (fVar8 < local_24) {
                  fVar8 = local_24;
                }
                if (local_c < local_18) {
                  local_18 = local_c;
                }
                if (param_3 == 0) {
                  if (DAT_0099cdc8 <= fVar7) {
                    if (fVar7 + DAT_0099d080 < fVar3) goto LAB_008a6af4;
                    fVar9 = 0.0;
                  }
                  else {
                    fVar9 = 1.0;
                  }
                }
                else {
LAB_008a6af4:
                  fVar9 = (local_18 + fVar8) * fVar5 - fVar7;
                }
                if (local_10 != 0) {
                  fVar9 = 1.0 - fVar9;
                }
                iVar12 = iVar12 + 1;
                local_28 = local_28 + 1;
                local_8 = (local_18 - fVar8) * fVar9 + local_8;
                fVar8 = (float)iVar12;
              } while (fVar8 < local_c);
            }
            local_10 = local_10 + 1;
          } while (local_10 < 2);
          if (_DAT_00a1694c < local_8) {
            piVar1 = (int *)(iVar10 + (int)piVar11);
            iVar10 = iVar10 + 8;
            *piVar1 = iVar14;
            piVar1[1] = (int)local_8;
          }
          local_1c = local_1c + 1;
          *(int *)(iVar16 + (int)piVar11) = iVar10 - iVar16;
          iVar16 = iVar10;
        } while (local_1c < param_1);
      }
      *piVar11 = iVar10;
      return piVar11;
    }
  }
  return (int *)0x0;
}


// ==== FUN_008a6b8c @ 0x008a6b8c ====

undefined4 FUN_008a6b8c(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *local_14;
  uint local_10;
  undefined4 *local_c;
  uint local_8;
  
  iVar4 = *in_ECX;
  if (((*(uint *)(iVar4 + 0x48) | *(uint *)(iVar4 + 0x44) | *(uint *)(iVar4 + 0x3c) |
       *(uint *)(iVar4 + 0x40)) & 3) != 0) {
    return 0x80004005;
  }
  iVar1 = in_ECX[1];
  if (((*(uint *)(iVar1 + 0x48) | *(uint *)(iVar1 + 0x44) | *(uint *)(iVar1 + 0x40) |
       *(uint *)(iVar1 + 0x3c)) & 3) == 0) {
    iVar1 = *(int *)(in_ECX[1] + 4);
    if (iVar1 == 0x31545844) {
      local_8 = 8;
    }
    else {
      if ((((iVar1 != 0x32545844) && (iVar1 != 0x33545844)) && (iVar1 != 0x34545844)) &&
         (iVar1 != 0x35545844)) goto LAB_008a6bd1;
      local_8 = 0x10;
    }
    iVar1 = in_ECX[1];
    uVar5 = (*(uint *)(iVar1 + 0x68) >> 2) * local_8;
    local_10 = 0;
    puVar6 = (undefined4 *)
             ((*(uint *)(iVar1 + 0x40) >> 2) * *(int *)(iVar1 + 0x60) +
              *(int *)(iVar1 + 100) * *(int *)(iVar1 + 0x4c) +
              (*(uint *)(iVar1 + 0x3c) >> 2) * local_8 + *(int *)(iVar1 + 0x20));
    local_c = (undefined4 *)
              ((*(uint *)(iVar4 + 0x40) >> 2) * *(int *)(iVar4 + 0x60) +
               *(int *)(iVar4 + 100) * *(int *)(iVar4 + 0x4c) +
               (*(uint *)(iVar4 + 0x3c) >> 2) * local_8 + *(int *)(iVar4 + 0x20));
    if (*(int *)(in_ECX[1] + 0x70) != 0) {
      uVar3 = *(uint *)(in_ECX[1] + 0x6c);
      do {
        local_8 = 0;
        puVar8 = local_c;
        local_14 = puVar6;
        if (uVar3 != 0) {
          do {
            local_8 = local_8 + 4;
            puVar7 = puVar8;
            puVar9 = local_14;
            for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
              *puVar9 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar9 = puVar9 + 1;
            }
            for (iVar4 = 0; iVar4 != 0; iVar4 = iVar4 + -1) {
              *(undefined1 *)puVar9 = *(undefined1 *)puVar7;
              puVar7 = (undefined4 *)((int)puVar7 + 1);
              puVar9 = (undefined4 *)((int)puVar9 + 1);
            }
            local_14 = (undefined4 *)((int)local_14 + *(int *)(in_ECX[1] + 0x60));
            puVar8 = (undefined4 *)((int)puVar8 + *(int *)(*in_ECX + 0x60));
            uVar3 = *(uint *)(in_ECX[1] + 0x6c);
          } while (local_8 < uVar3);
        }
        local_c = (undefined4 *)((int)local_c + *(int *)(*in_ECX + 100));
        puVar6 = (undefined4 *)((int)puVar6 + *(int *)(in_ECX[1] + 100));
        local_10 = local_10 + 1;
      } while (local_10 < *(uint *)(in_ECX[1] + 0x70));
    }
    uVar2 = 0;
  }
  else {
LAB_008a6bd1:
    uVar2 = 0x80004005;
  }
  return uVar2;
}


// ==== FUN_008a6ce4 @ 0x008a6ce4 ====

undefined4 FUN_008a6ce4(uint *param_1,uint param_2,int param_3,uint param_4,int param_5,int param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int local_14;
  uint *local_10;
  uint *local_8;
  
  uVar5 = param_4 * param_5 + param_2;
  if (param_2 < uVar5) {
    param_4 = param_2 + param_3 * 4;
    do {
      local_8 = param_1;
      if (param_2 < param_4) {
        local_10 = (uint *)(param_2 + 4);
        local_14 = ((param_4 - param_2) - 1 >> 3) + 1;
        do {
          uVar1 = *(uint *)((int)local_10 + param_5);
          uVar2 = *(uint *)(param_5 + -4 + (int)local_10);
          uVar3 = *local_10;
          uVar4 = local_10[-1];
          *local_8 = ((uVar4 >> 2 & 0xffc03fc0) + (uVar2 >> 2 & 0xffc03fc0) +
                      (uVar1 >> 2 & 0xffc03fc0) + -0x7fff80 + (uVar3 >> 2 & 0xffc03fc0) ^
                     (uVar4 & 0xff00ff) + (uVar2 & 0xff00ff) + (uVar1 & 0xff00ff) + 0x20002 +
                     (uVar3 & 0xff00ff) >> 2) & 0xff00ff ^
                     (uVar4 >> 2 & 0x3fc03fc0) + (uVar2 >> 2 & 0x3fc03fc0) +
                     (uVar1 >> 2 & 0x3fc03fc0) + 0x800080 + (uVar3 >> 2 & 0x3fc03fc0);
          local_10 = local_10 + 2;
          local_14 = local_14 + -1;
          local_8 = local_8 + 1;
        } while (local_14 != 0);
      }
      param_1 = (uint *)((int)param_1 + param_6);
      param_4 = param_4 + param_5 * 2;
      param_2 = param_2 + param_5 * 2;
    } while (param_2 < uVar5);
  }
  return 0;
}


// ==== FUN_008a6e0e @ 0x008a6e0e ====

void FUN_008a6e0e(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  (*(code *)PTR_FUN_00b53ed4)
            (*(undefined4 *)(in_ECX[1] + 0x20),*(undefined4 *)(iVar1 + 0x20),
             *(undefined4 *)(iVar1 + 0x68),*(undefined4 *)(iVar1 + 0x6c),
             *(undefined4 *)(iVar1 + 0x60),*(undefined4 *)(in_ECX[1] + 0x60));
  return;
}


// ==== FUN_008a6e30 @ 0x008a6e30 ====

undefined4
FUN_008a6e30(uint *param_1,uint param_2,uint *param_3,uint param_4,int param_5,int param_6)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int local_10;
  
  uVar5 = param_4 * param_5 + param_2;
  if (param_2 < uVar5) {
    param_4 = param_2 + (int)param_3 * 4;
    do {
      param_3 = param_1;
      if (param_2 < param_4) {
        local_10 = ((param_4 - param_2) - 1 >> 3) + 1;
        puVar6 = (uint *)(param_2 + 4);
        do {
          puVar2 = (uint *)((int)puVar6 + param_5);
          uVar3 = *puVar6;
          uVar4 = *(uint *)(param_5 + -4 + (int)puVar6);
          puVar1 = puVar6 + -1;
          puVar6 = puVar6 + 2;
          local_10 = local_10 + -1;
          *param_3 = ((*puVar1 & 0xff00ff) + (uVar4 & 0xff00ff) + (*puVar2 & 0xff00ff) + 0x20002 +
                      (uVar3 & 0xff00ff) & 0x3fc03fc |
                     (*puVar1 & 0xff00) + (uVar4 & 0xff00) + (*puVar2 & 0xff00) + 0x200 +
                     (uVar3 & 0xff00) & 0x3fc00) >> 2;
          param_3 = param_3 + 1;
        } while (local_10 != 0);
      }
      param_1 = (uint *)((int)param_1 + param_6);
      param_4 = param_4 + param_5 * 2;
      param_2 = param_2 + param_5 * 2;
    } while (param_2 < uVar5);
  }
  return 0;
}


// ==== FUN_008a6f1c @ 0x008a6f1c ====

undefined4
FUN_008a6f1c(undefined8 *param_1,undefined8 *param_2,uint param_3,int param_4,int param_5,
            int param_6)

{
  undefined8 uVar1;
  undefined8 uVar2;
  short sVar3;
  short sVar4;
  short sVar5;
  short sVar6;
  short sVar7;
  short sVar8;
  short sVar9;
  short sVar10;
  undefined8 *puVar11;
  undefined4 uVar12;
  undefined8 *puVar13;
  undefined8 *puVar14;
  undefined8 *puVar15;
  undefined8 uVar16;
  undefined8 uVar17;
  
  if ((param_3 & 3) == 0) {
    puVar13 = (undefined8 *)(param_4 * param_5 + (int)param_2);
    for (; (int)param_2 < (int)puVar13; param_2 = (undefined8 *)((int)param_2 + param_5 * 2)) {
      puVar14 = (undefined8 *)((int)param_2 + param_5);
      puVar15 = param_2;
      puVar11 = param_1;
      while ((int)puVar15 < (int)((int)param_2 + param_3 * 4)) {
        uVar16 = *puVar15;
        uVar17 = *puVar14;
        uVar1 = puVar15[1];
        uVar2 = puVar14[1];
        puVar15 = puVar15 + 2;
        puVar14 = puVar14 + 2;
        uVar16 = psraw(CONCAT26(((ushort)((ulonglong)uVar16 >> 0x18) & 0xff) +
                                (ushort)(byte)((ulonglong)uVar16 >> 0x38) +
                                ((ushort)((ulonglong)uVar17 >> 0x18) & 0xff) +
                                (ushort)(byte)((ulonglong)uVar17 >> 0x38) + 2,
                                CONCAT24((ushort)(byte)((ulonglong)uVar16 >> 0x10) +
                                         (ushort)(byte)((ulonglong)uVar16 >> 0x30) +
                                         (ushort)(byte)((ulonglong)uVar17 >> 0x10) +
                                         (ushort)(byte)((ulonglong)uVar17 >> 0x30) + 2,
                                         CONCAT22((ushort)(byte)((ulonglong)uVar16 >> 8) +
                                                  (ushort)(byte)((ulonglong)uVar16 >> 0x28) +
                                                  (ushort)(byte)((ulonglong)uVar17 >> 8) +
                                                  (ushort)(byte)((ulonglong)uVar17 >> 0x28) + 2,
                                                  (ushort)(byte)uVar16 +
                                                  (ushort)(byte)((ulonglong)uVar16 >> 0x20) +
                                                  (ushort)(byte)uVar17 +
                                                  (ushort)(byte)((ulonglong)uVar17 >> 0x20) + 2))),2
                      );
        uVar17 = psraw(CONCAT26(((ushort)((ulonglong)uVar1 >> 0x18) & 0xff) +
                                (ushort)(byte)((ulonglong)uVar1 >> 0x38) +
                                ((ushort)((ulonglong)uVar2 >> 0x18) & 0xff) +
                                (ushort)(byte)((ulonglong)uVar2 >> 0x38) + 2,
                                CONCAT24((ushort)(byte)((ulonglong)uVar1 >> 0x10) +
                                         (ushort)(byte)((ulonglong)uVar1 >> 0x30) +
                                         (ushort)(byte)((ulonglong)uVar2 >> 0x10) +
                                         (ushort)(byte)((ulonglong)uVar2 >> 0x30) + 2,
                                         CONCAT22((ushort)(byte)((ulonglong)uVar1 >> 8) +
                                                  (ushort)(byte)((ulonglong)uVar1 >> 0x28) +
                                                  (ushort)(byte)((ulonglong)uVar2 >> 8) +
                                                  (ushort)(byte)((ulonglong)uVar2 >> 0x28) + 2,
                                                  (ushort)(byte)uVar1 +
                                                  (ushort)(byte)((ulonglong)uVar1 >> 0x20) +
                                                  (ushort)(byte)uVar2 +
                                                  (ushort)(byte)((ulonglong)uVar2 >> 0x20) + 2))),2)
        ;
        sVar3 = (short)uVar16;
        sVar4 = (short)((ulonglong)uVar16 >> 0x10);
        sVar5 = (short)((ulonglong)uVar16 >> 0x20);
        sVar6 = (short)((ulonglong)uVar16 >> 0x30);
        sVar7 = (short)uVar17;
        sVar8 = (short)((ulonglong)uVar17 >> 0x10);
        sVar9 = (short)((ulonglong)uVar17 >> 0x20);
        sVar10 = (short)((ulonglong)uVar17 >> 0x30);
        *puVar11 = CONCAT17((0 < sVar10) * (sVar10 < 0x100) * (char)((ulonglong)uVar17 >> 0x30) -
                            (0xff < sVar10),
                            CONCAT16((0 < sVar9) * (sVar9 < 0x100) *
                                     (char)((ulonglong)uVar17 >> 0x20) - (0xff < sVar9),
                                     CONCAT15((0 < sVar8) * (sVar8 < 0x100) *
                                              (char)((ulonglong)uVar17 >> 0x10) - (0xff < sVar8),
                                              CONCAT14((0 < sVar7) * (sVar7 < 0x100) * (char)uVar17
                                                       - (0xff < sVar7),
                                                       CONCAT13((0 < sVar6) * (sVar6 < 0x100) *
                                                                (char)((ulonglong)uVar16 >> 0x30) -
                                                                (0xff < sVar6),
                                                                CONCAT12((0 < sVar5) *
                                                                         (sVar5 < 0x100) *
                                                                         (char)((ulonglong)uVar16 >>
                                                                               0x20) -
                                                                         (0xff < sVar5),
                                                                         CONCAT11((0 < sVar4) *
                                                                                  (sVar4 < 0x100) *
                                                                                  (char)((ulonglong)
                                                                                         uVar16 >>
                                                                                        0x10) -
                                                                                  (0xff < sVar4),
                                                                                  (0 < sVar3) *
                                                                                  (sVar3 < 0x100) *
                                                                                  (char)uVar16 -
                                                                                  (0xff < sVar3)))))
                                             )));
        puVar11 = puVar11 + 1;
      }
      param_1 = (undefined8 *)((int)param_1 + param_6);
    }
    uVar12 = 0;
  }
  else {
    uVar12 = FUN_008a6ce4(param_1,param_2,param_3,param_4,param_5,param_6);
  }
  return uVar12;
}


// ==== FUN_008a7036 @ 0x008a7036 ====

void FUN_008a7036(void)

{
  int iVar1;
  
  iVar1 = FUN_007a3436();
  if (iVar1 == 0) {
    PTR_FUN_00b53ed4 = FUN_008a6ce4;
    PTR_FUN_00b53ed8 = FUN_008a6e30;
  }
  else {
    PTR_FUN_00b53ed4 = FUN_008a6f1c;
    PTR_FUN_00b53ed8 = FUN_008a6f1c;
  }
                    /* WARNING: Could not recover jumptable at 0x008a706a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_FUN_00b53ed4)();
  return;
}


// ==== FUN_008a7070 @ 0x008a7070 ====

void FUN_008a7070(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = FUN_007a3436();
  if (iVar1 == 0) {
    PTR_FUN_00b53ed4 = FUN_008a6ce4;
    UNRECOVERED_JUMPTABLE = FUN_008a6e30;
  }
  else {
    UNRECOVERED_JUMPTABLE = FUN_008a6f1c;
    PTR_FUN_00b53ed4 = FUN_008a6f1c;
  }
  PTR_FUN_00b53ed8 = UNRECOVERED_JUMPTABLE;
                    /* WARNING: Could not recover jumptable at 0x008a709f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}


// ==== FUN_008a70a1 @ 0x008a70a1 ====

void FUN_008a70a1(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  (*(code *)PTR_FUN_00b53ed8)
            (*(undefined4 *)(in_ECX[1] + 0x20),*(undefined4 *)(iVar1 + 0x20),
             *(undefined4 *)(iVar1 + 0x68),*(undefined4 *)(iVar1 + 0x6c),
             *(undefined4 *)(iVar1 + 0x60),*(undefined4 *)(in_ECX[1] + 0x60));
  return;
}


// ==== FUN_008a70c3 @ 0x008a70c3 ====

undefined4 FUN_008a70c3(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  int *in_ECX;
  uint uVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  ushort *puVar12;
  
  iVar4 = *in_ECX;
  puVar9 = *(ushort **)(in_ECX[1] + 0x20);
  puVar5 = *(ushort **)(iVar4 + 0x20);
  puVar11 = (ushort *)(*(int *)(iVar4 + 0x6c) * *(int *)(iVar4 + 0x60) + (int)puVar5);
  for (; puVar5 < puVar11; puVar5 = puVar5 + *(int *)(iVar4 + 0x60)) {
    iVar6 = *(int *)(iVar4 + 0x68);
    puVar12 = (ushort *)(*(int *)(iVar4 + 0x60) + (int)puVar5);
    puVar7 = puVar9;
    for (puVar10 = puVar5; puVar10 < puVar5 + iVar6; puVar10 = puVar10 + 2) {
      uVar8 = (uint)*puVar12;
      uVar1 = puVar12[1];
      uVar2 = puVar10[1];
      uVar3 = *puVar10;
      *puVar7 = (ushort)(((uint)(uVar1 & 0xf81f) + (uint)(uVar3 & 0xf81f) + (uVar8 & 0xfffff81f) +
                          0x1002 + (uint)(uVar2 & 0xf81f) ^
                         (uVar1 & 0xffff07e0) + (uVar3 & 0xffff07e0) + (uVar8 & 0xffff07e0) + 0x40 +
                         (uVar2 & 0xffff07e0)) >> 2) & 0x7e0 ^
                (ushort)((uVar1 & 0xf81f) + (uVar3 & 0xf81f) + (uVar8 & 0xf81f) + 0x1002 +
                         (uVar2 & 0xf81f) >> 2);
      puVar12 = puVar12 + 2;
      puVar7 = puVar7 + 1;
    }
    puVar9 = (ushort *)((int)puVar9 + *(int *)(in_ECX[1] + 0x60));
    iVar4 = *in_ECX;
  }
  return 0;
}


// ==== FUN_008a71f7 @ 0x008a71f7 ====

undefined4 FUN_008a71f7(void)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  ushort *puVar6;
  int *in_ECX;
  ushort *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  
  iVar3 = *in_ECX;
  puVar7 = *(ushort **)(in_ECX[1] + 0x20);
  puVar4 = *(ushort **)(iVar3 + 0x20);
  puVar9 = (ushort *)(*(int *)(iVar3 + 0x6c) * *(int *)(iVar3 + 0x60) + (int)puVar4);
  for (; puVar4 < puVar9; puVar4 = puVar4 + *(int *)(iVar3 + 0x60)) {
    iVar5 = *(int *)(iVar3 + 0x68);
    puVar10 = (ushort *)(*(int *)(iVar3 + 0x60) + (int)puVar4);
    puVar6 = puVar7;
    for (puVar8 = puVar4; puVar8 < puVar4 + iVar5; puVar8 = puVar8 + 2) {
      uVar2 = *puVar10;
      puVar1 = puVar10 + 1;
      puVar10 = puVar10 + 2;
      *puVar6 = (ushort)((*puVar1 & 0xffff03e0) + (*puVar8 & 0xffff03e0) + (uVar2 & 0xffff03e0) +
                         0x40 + (puVar8[1] & 0xffff03e0) >> 2) & 0x3e0 |
                (ushort)((*puVar1 & 0x7c1f) + (*puVar8 & 0x7c1f) + (uVar2 & 0x7c1f) + 0x802 +
                         (puVar8[1] & 0x7c1f) >> 2) & 0x7c1f;
      puVar6 = puVar6 + 1;
    }
    puVar7 = (ushort *)((int)puVar7 + *(int *)(in_ECX[1] + 0x60));
    iVar3 = *in_ECX;
  }
  return 0;
}


// ==== FUN_008a72fc @ 0x008a72fc ====

undefined4 FUN_008a72fc(void)

{
  int iVar1;
  ushort *puVar2;
  int iVar3;
  ushort *puVar4;
  ushort *puVar5;
  int *in_ECX;
  uint uVar6;
  uint uVar7;
  ushort *puVar8;
  uint uVar9;
  ushort *puVar10;
  ushort *puVar11;
  uint uVar12;
  
  iVar1 = *in_ECX;
  puVar2 = *(ushort **)(iVar1 + 0x20);
  puVar10 = *(ushort **)(in_ECX[1] + 0x20);
  puVar5 = (ushort *)(*(int *)(iVar1 + 0x6c) * *(int *)(iVar1 + 0x60) + (int)puVar2);
  for (; puVar2 < puVar5; puVar2 = puVar2 + *(int *)(iVar1 + 0x60)) {
    iVar3 = *(int *)(iVar1 + 0x68);
    puVar11 = (ushort *)(*(int *)(iVar1 + 0x60) + (int)puVar2);
    puVar4 = puVar10;
    for (puVar8 = puVar2; puVar8 < puVar2 + iVar3; puVar8 = puVar8 + 2) {
      uVar6 = (uint)puVar8[1];
      uVar9 = (uint)puVar11[1];
      uVar7 = (uint)*puVar11;
      uVar12 = (uint)*puVar8;
      puVar11 = puVar11 + 2;
      *puVar4 = (ushort)(((uVar9 & 0x83e0) + (uVar12 & 0x83e0) + (uVar7 & 0x83e0) + 0x10040 +
                          (uVar6 & 0x83e0) ^
                         (uVar9 & 0x7c1f) + (uVar12 & 0x7c1f) + (uVar7 & 0x7c1f) + 0x802 +
                         (uVar6 & 0x7c1f)) >> 2) & 0x7c1f ^
                (ushort)((uVar9 & 0x83e0) + (uVar12 & 0x83e0) + (uVar7 & 0x83e0) + 0x10040 +
                         (uVar6 & 0x83e0) >> 2);
      puVar4 = puVar4 + 1;
    }
    puVar10 = (ushort *)((int)puVar10 + *(int *)(in_ECX[1] + 0x60));
    iVar1 = *in_ECX;
  }
  return 0;
}


// ==== FUN_008a7425 @ 0x008a7425 ====

undefined4 FUN_008a7425(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  int *in_ECX;
  uint uVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  ushort *puVar12;
  
  iVar4 = *in_ECX;
  puVar9 = *(ushort **)(in_ECX[1] + 0x20);
  puVar5 = *(ushort **)(iVar4 + 0x20);
  puVar11 = (ushort *)(*(int *)(iVar4 + 0x6c) * *(int *)(iVar4 + 0x60) + (int)puVar5);
  for (; puVar5 < puVar11; puVar5 = puVar5 + *(int *)(iVar4 + 0x60)) {
    iVar6 = *(int *)(iVar4 + 0x68);
    puVar12 = (ushort *)(*(int *)(iVar4 + 0x60) + (int)puVar5);
    puVar7 = puVar9;
    for (puVar10 = puVar5; puVar10 < puVar5 + iVar6; puVar10 = puVar10 + 2) {
      uVar8 = (uint)*puVar12;
      uVar1 = puVar12[1];
      uVar2 = puVar10[1];
      uVar3 = *puVar10;
      *puVar7 = (ushort)(((uint)(uVar1 & 0xf0f0) + (uint)(uVar3 & 0xf0f0) + (uVar8 & 0xfffff0f0) +
                          0x2020 + (uint)(uVar2 & 0xf0f0) ^
                         (uVar1 & 0xffff0f0f) + (uVar3 & 0xffff0f0f) + (uVar8 & 0xffff0f0f) + 0x202
                         + (uVar2 & 0xffff0f0f)) >> 2) & 0xf0f ^
                (ushort)((uVar1 & 0xf0f0) + (uVar3 & 0xf0f0) + (uVar8 & 0xf0f0) + 0x2020 +
                         (uVar2 & 0xf0f0) >> 2);
      puVar12 = puVar12 + 2;
      puVar7 = puVar7 + 1;
    }
    puVar9 = (ushort *)((int)puVar9 + *(int *)(in_ECX[1] + 0x60));
    iVar4 = *in_ECX;
  }
  return 0;
}


// ==== FUN_008a755c @ 0x008a755c ====

undefined4 FUN_008a755c(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  int *in_ECX;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  
  pbVar9 = *(byte **)(in_ECX[1] + 0x20);
  iVar4 = *in_ECX;
  pbVar5 = *(byte **)(iVar4 + 0x20);
  pbVar12 = pbVar5 + *(int *)(iVar4 + 0x6c) * *(int *)(iVar4 + 0x60);
  for (; pbVar5 < pbVar12; pbVar5 = pbVar5 + *(int *)(iVar4 + 0x60) * 2) {
    iVar6 = *(int *)(iVar4 + 0x68);
    pbVar10 = pbVar5 + *(int *)(iVar4 + 0x60);
    pbVar7 = pbVar9;
    for (pbVar11 = pbVar5; pbVar11 < pbVar5 + iVar6; pbVar11 = pbVar11 + 2) {
      uVar8 = (uint)*pbVar10;
      bVar1 = pbVar10[1];
      bVar2 = pbVar11[1];
      bVar3 = *pbVar11;
      *pbVar7 = ((byte)((bVar1 & 0x1c) + (bVar3 & 0x1c) + (uVar8 & 0x1c) + 8 + (bVar2 & 0x1c) >> 2)
                ^ (byte)((uint)(bVar1 & 0xe3) + (uint)(bVar3 & 0xe3) + (uVar8 & 0xffff00e3) + 0x42 +
                         (uint)(bVar2 & 0xe3) >> 2)) & 0x1c ^
                (byte)((uint)(bVar1 & 0xe3) + (bVar3 & 0xffff00e3) + (uVar8 & 0xffff00e3) + 0x42 +
                       (uint)(bVar2 & 0xe3) >> 2);
      pbVar10 = pbVar10 + 2;
      pbVar7 = pbVar7 + 1;
    }
    pbVar9 = pbVar9 + *(int *)(in_ECX[1] + 0x60);
    iVar4 = *in_ECX;
  }
  return 0;
}


// ==== FUN_008a767a @ 0x008a767a ====

undefined4 FUN_008a767a(void)

{
  byte *pbVar1;
  byte *pbVar2;
  byte bVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int *in_ECX;
  byte *pbVar7;
  undefined1 *puVar8;
  byte *pbVar9;
  byte *pbVar10;
  
  puVar8 = *(undefined1 **)(in_ECX[1] + 0x20);
  iVar6 = *in_ECX;
  pbVar9 = *(byte **)(iVar6 + 0x20);
  pbVar10 = pbVar9 + *(int *)(iVar6 + 0x6c) * *(int *)(iVar6 + 0x60);
  for (; pbVar9 < pbVar10; pbVar9 = pbVar9 + *(int *)(iVar6 + 0x60) * 2) {
    iVar4 = *(int *)(iVar6 + 0x68);
    pbVar7 = pbVar9 + *(int *)(iVar6 + 0x60);
    puVar5 = puVar8;
    for (pbVar2 = pbVar9; pbVar2 < pbVar9 + iVar4; pbVar2 = pbVar2 + 2) {
      pbVar1 = pbVar7 + 1;
      bVar3 = *pbVar7;
      pbVar7 = pbVar7 + 2;
      *puVar5 = (char)((uint)*pbVar1 + (uint)pbVar2[1] + (uint)bVar3 + 2 + (uint)*pbVar2 >> 2);
      puVar5 = puVar5 + 1;
    }
    puVar8 = puVar8 + *(int *)(in_ECX[1] + 0x60);
    iVar6 = *in_ECX;
  }
  return 0;
}


// ==== FUN_008a7706 @ 0x008a7706 ====

undefined4 FUN_008a7706(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  int *in_ECX;
  uint uVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  ushort *puVar12;
  
  puVar9 = *(ushort **)(in_ECX[1] + 0x20);
  iVar4 = *in_ECX;
  puVar5 = *(ushort **)(iVar4 + 0x20);
  puVar12 = (ushort *)(*(int *)(iVar4 + 0x6c) * *(int *)(iVar4 + 0x60) + (int)puVar5);
  for (; puVar5 < puVar12; puVar5 = puVar5 + *(int *)(iVar4 + 0x60)) {
    iVar6 = *(int *)(iVar4 + 0x68);
    puVar10 = (ushort *)(*(int *)(iVar4 + 0x60) + (int)puVar5);
    puVar7 = puVar9;
    for (puVar11 = puVar5; puVar11 < puVar5 + iVar6; puVar11 = puVar11 + 2) {
      uVar1 = puVar10[1];
      uVar8 = (uint)*puVar10;
      uVar2 = *puVar11;
      uVar3 = puVar11[1];
      *puVar7 = (byte)((byte)((uint)(uVar1 & 0xe3) + (uint)(uVar2 & 0xe3) + (uVar8 & 0xffff00e3) +
                              0x42 + (uint)(uVar3 & 0xe3) >> 2) ^
                      (byte)((uint)(uVar1 & 0xff1c) + (uVar2 & 0xffffff1c) + (uVar8 & 0xffffff1c) +
                             0x208 + (uint)(uVar3 & 0xff1c) >> 2)) & 0xe3 ^
                (ushort)((uVar1 & 0xff1c) + (uVar2 & 0xff1c) + (uVar8 & 0xff1c) + 0x208 +
                         (uVar3 & 0xff1c) >> 2);
      puVar10 = puVar10 + 2;
      puVar7 = puVar7 + 1;
    }
    puVar9 = (ushort *)((int)puVar9 + *(int *)(in_ECX[1] + 0x60));
    iVar4 = *in_ECX;
  }
  return 0;
}


// ==== FUN_008a7834 @ 0x008a7834 ====

undefined4 FUN_008a7834(void)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  ushort *puVar6;
  int *in_ECX;
  ushort *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  
  puVar10 = *(ushort **)(in_ECX[1] + 0x20);
  iVar3 = *in_ECX;
  puVar4 = *(ushort **)(iVar3 + 0x20);
  puVar7 = (ushort *)(*(int *)(iVar3 + 0x6c) * *(int *)(iVar3 + 0x60) + (int)puVar4);
  for (; puVar4 < puVar7; puVar4 = puVar4 + *(int *)(iVar3 + 0x60)) {
    iVar5 = *(int *)(iVar3 + 0x68);
    puVar9 = (ushort *)(*(int *)(iVar3 + 0x60) + (int)puVar4);
    puVar6 = puVar10;
    for (puVar8 = puVar4; puVar8 < puVar4 + iVar5; puVar8 = puVar8 + 2) {
      puVar1 = puVar9 + 1;
      uVar2 = *puVar9;
      puVar9 = puVar9 + 2;
      *puVar6 = (ushort)((*puVar1 & 0xffff00f0) + (*puVar8 & 0xffff00f0) + (uVar2 & 0xffff00f0) +
                         0x20 + (puVar8[1] & 0xffff00f0) >> 2) & 0xf0 |
                (ushort)((*puVar1 & 0xffff0f0f) + (*puVar8 & 0xffff0f0f) + (uint)(uVar2 & 0xf0f) +
                         0x202 + (uint)(puVar8[1] & 0xf0f) >> 2) & 0xf0f;
      puVar6 = puVar6 + 1;
    }
    puVar10 = (ushort *)((int)puVar10 + *(int *)(in_ECX[1] + 0x60));
    iVar3 = *in_ECX;
  }
  return 0;
}


// ==== FUN_008a793d @ 0x008a793d ====

undefined4 FUN_008a793d(void)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  ushort *puVar5;
  int iVar6;
  ushort *puVar7;
  int *in_ECX;
  uint uVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  ushort *puVar12;
  
  puVar9 = *(ushort **)(in_ECX[1] + 0x20);
  iVar4 = *in_ECX;
  puVar5 = *(ushort **)(iVar4 + 0x20);
  puVar12 = (ushort *)(*(int *)(iVar4 + 0x6c) * *(int *)(iVar4 + 0x60) + (int)puVar5);
  for (; puVar5 < puVar12; puVar5 = puVar5 + *(int *)(iVar4 + 0x60)) {
    iVar6 = *(int *)(iVar4 + 0x68);
    puVar10 = (ushort *)(*(int *)(iVar4 + 0x60) + (int)puVar5);
    puVar7 = puVar9;
    for (puVar11 = puVar5; puVar11 < puVar5 + iVar6; puVar11 = puVar11 + 2) {
      uVar1 = puVar10[1];
      uVar8 = (uint)*puVar10;
      uVar2 = *puVar11;
      uVar3 = puVar11[1];
      *puVar7 = (ushort)(byte)((byte)((uint)(uVar1 & 0xff) + (uint)(uVar2 & 0xff) +
                                      (uVar8 & 0xffff00ff) + 2 + (uint)(uVar3 & 0xff) >> 2) ^
                              (byte)((uint)(uVar1 & 0xff00) + (uVar2 & 0xffffff00) +
                                     (uVar8 & 0xffffff00) + 0x200 + (uint)(uVar3 & 0xff00) >> 2)) ^
                (ushort)((uVar1 & 0xff00) + (uVar2 & 0xff00) + (uVar8 & 0xff00) + 0x200 +
                         (uVar3 & 0xff00) >> 2);
      puVar10 = puVar10 + 2;
      puVar7 = puVar7 + 1;
    }
    puVar9 = (ushort *)((int)puVar9 + *(int *)(in_ECX[1] + 0x60));
    iVar4 = *in_ECX;
  }
  return 0;
}


// ==== FUN_008a7a6b @ 0x008a7a6b ====

undefined4 FUN_008a7a6b(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  int *in_ECX;
  uint uVar8;
  byte *pbVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  
  pbVar9 = *(byte **)(in_ECX[1] + 0x20);
  iVar4 = *in_ECX;
  pbVar5 = *(byte **)(iVar4 + 0x20);
  pbVar12 = pbVar5 + *(int *)(iVar4 + 0x6c) * *(int *)(iVar4 + 0x60);
  for (; pbVar5 < pbVar12; pbVar5 = pbVar5 + *(int *)(iVar4 + 0x60) * 2) {
    iVar6 = *(int *)(iVar4 + 0x68);
    pbVar10 = pbVar5 + *(int *)(iVar4 + 0x60);
    pbVar7 = pbVar9;
    for (pbVar11 = pbVar5; pbVar11 < pbVar5 + iVar6; pbVar11 = pbVar11 + 2) {
      uVar8 = (uint)*pbVar10;
      bVar1 = pbVar10[1];
      bVar2 = pbVar11[1];
      bVar3 = *pbVar11;
      *pbVar7 = ((byte)((bVar1 & 0xf) + (bVar3 & 0xf) + (uVar8 & 0xf) + 2 + (bVar2 & 0xf) >> 2) ^
                (byte)((uint)(bVar1 & 0xf0) + (uint)(bVar3 & 0xf0) + (uVar8 & 0xffff00f0) + 0x20 +
                       (uint)(bVar2 & 0xf0) >> 2)) & 0xf ^
                (byte)((uint)(bVar1 & 0xf0) + (bVar3 & 0xffff00f0) + (uVar8 & 0xffff00f0) + 0x20 +
                       (uint)(bVar2 & 0xf0) >> 2);
      pbVar10 = pbVar10 + 2;
      pbVar7 = pbVar7 + 1;
    }
    pbVar9 = pbVar9 + *(int *)(in_ECX[1] + 0x60);
    iVar4 = *in_ECX;
  }
  return 0;
}


// ==== FUN_008a7b89 @ 0x008a7b89 ====

undefined4 FUN_008a7b89(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *in_ECX;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int iVar10;
  int *piVar11;
  undefined4 *puVar12;
  bool bVar13;
  uint local_c;
  uint local_8;
  
  iVar4 = in_ECX[1];
  iVar10 = *in_ECX;
  if ((*(int *)(iVar4 + 4) != *(int *)(iVar10 + 4)) || (*(int *)(iVar10 + 0x18) != 0)) {
    return 0x80004005;
  }
  if ((((*(int *)(iVar4 + 0x68) == *(int *)(iVar10 + 0x68)) &&
       (*(int *)(iVar4 + 0x6c) == *(int *)(iVar10 + 0x6c))) &&
      (*(int *)(iVar4 + 0x70) == *(int *)(iVar10 + 0x70))) &&
     (*(int *)(iVar4 + 0x10) == *(int *)(iVar10 + 0x10))) {
    if (*(int *)(iVar4 + 0xc) == 0) {
      uVar1 = FUN_008a6b8c();
      return uVar1;
    }
    if (*(int *)(iVar4 + 0x1c) != 0) {
      if (*(int **)(iVar4 + 0x38) != *(int **)(iVar10 + 0x38)) {
        iVar3 = 0x100;
        bVar13 = true;
        piVar8 = *(int **)(iVar4 + 0x38);
        piVar11 = *(int **)(iVar10 + 0x38);
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar13 = *piVar8 == *piVar11;
          piVar8 = piVar8 + 1;
          piVar11 = piVar11 + 1;
        } while (bVar13);
        if (!bVar13) goto LAB_008a7c89;
      }
    }
    *(undefined4 *)(iVar4 + 0x10) = 0;
    *(undefined4 *)(*in_ECX + 0x10) = 0;
    iVar4 = in_ECX[1];
    local_8 = 0;
    if (*(int *)(iVar4 + 0x70) != 0) {
      iVar10 = *in_ECX;
      uVar6 = *(uint *)(iVar4 + 0x6c);
      do {
        puVar2 = (undefined4 *)(*(int *)(in_ECX[1] + 100) * local_8 + *(int *)(in_ECX[1] + 0x20));
        puVar7 = (undefined4 *)(*(int *)(iVar10 + 100) * local_8 + *(int *)(iVar10 + 0x20));
        local_c = 0;
        if (uVar6 != 0) {
          do {
            uVar6 = *(uint *)(iVar4 + 0x74);
            puVar9 = puVar7;
            puVar12 = puVar2;
            for (uVar5 = uVar6 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
              *puVar12 = *puVar9;
              puVar9 = puVar9 + 1;
              puVar12 = puVar12 + 1;
            }
            for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
              *(undefined1 *)puVar12 = *(undefined1 *)puVar9;
              puVar9 = (undefined4 *)((int)puVar9 + 1);
              puVar12 = (undefined4 *)((int)puVar12 + 1);
            }
            iVar4 = in_ECX[1];
            iVar10 = *in_ECX;
            puVar2 = (undefined4 *)((int)puVar2 + *(int *)(iVar4 + 0x60));
            puVar7 = (undefined4 *)((int)puVar7 + *(int *)(iVar10 + 0x60));
            local_c = local_c + 1;
            uVar6 = *(uint *)(iVar4 + 0x6c);
          } while (local_c < uVar6);
        }
        local_8 = local_8 + 1;
        iVar4 = in_ECX[1];
      } while (local_8 < *(uint *)(iVar4 + 0x70));
    }
    uVar1 = 0;
  }
  else {
LAB_008a7c89:
    uVar1 = 0x80004005;
  }
  return uVar1;
}


// ==== FUN_008a7c93 @ 0x008a7c93 ====

undefined4 FUN_008a7c93(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 extraout_EAX;
  int *in_ECX;
  uint uVar5;
  uint uVar6;
  void *local_8;
  
  iVar1 = in_ECX[1];
  iVar2 = *in_ECX;
  iVar3 = *(int *)(iVar1 + 0x68);
  if (((iVar3 == *(int *)(iVar2 + 0x68)) && (*(int *)(iVar1 + 0x6c) == *(int *)(iVar2 + 0x6c))) &&
     (*(int *)(iVar1 + 0x70) == *(int *)(iVar2 + 0x70))) {
    local_8 = operator_new(iVar3 << 4);
    if (local_8 == (void *)0x0) {
      local_8 = (void *)0x0;
    }
    else {
      FUN_0040d030(local_8,0x10,iVar3,FUN_0079e14e);
    }
    if (local_8 != (void *)0x0) {
      if ((*(int *)(in_ECX[1] + 0x10) != 0) && (*(int *)(*in_ECX + 0x10) != 0)) {
        *(undefined4 *)(in_ECX[1] + 0x10) = 0;
        *(undefined4 *)(*in_ECX + 0x10) = 0;
      }
      uVar5 = 0;
      if (*(int *)(in_ECX[1] + 0x70) != 0) {
        uVar4 = *(uint *)(in_ECX[1] + 0x6c);
        do {
          uVar6 = 0;
          if (uVar4 != 0) {
            do {
              (**(code **)(*(int *)*in_ECX + 4))(uVar6,uVar5,local_8);
              (**(code **)(*(int *)in_ECX[1] + 8))(uVar6,uVar5,local_8);
              uVar4 = *(uint *)(in_ECX[1] + 0x6c);
              uVar6 = uVar6 + 1;
            } while (uVar6 < uVar4);
          }
          uVar5 = uVar5 + 1;
        } while (uVar5 < *(uint *)(in_ECX[1] + 0x70));
      }
      _free(local_8);
      return extraout_EAX;
    }
  }
  return 0x80004005;
}


// ==== FUN_008a7d66 @ 0x008a7d66 ====

undefined4 FUN_008a7d66(void)

{
  int iVar1;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int *in_ECX;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  uint local_18;
  uint local_14;
  undefined4 *local_10;
  uint local_c;
  undefined4 *local_8;
  
  if ((char)in_ECX[2] == '\x01') {
    iVar2 = in_ECX[1];
    iVar1 = *in_ECX;
    local_10 = (undefined4 *)*(uint *)(iVar2 + 0x68);
    if (*(uint *)(iVar2 + 0x68) <= *(uint *)(iVar1 + 0x68)) {
      local_10 = (undefined4 *)*(uint *)(iVar1 + 0x68);
    }
    puVar3 = local_10;
    local_18 = *(uint *)(iVar2 + 0x6c);
    if (*(uint *)(iVar1 + 0x6c) <= *(uint *)(iVar2 + 0x6c)) {
      local_18 = *(uint *)(iVar1 + 0x6c);
    }
    local_14 = *(uint *)(iVar2 + 0x70);
    if (*(uint *)(iVar1 + 0x70) <= *(uint *)(iVar2 + 0x70)) {
      local_14 = *(uint *)(iVar1 + 0x70);
    }
    local_8 = operator_new((int)local_10 << 4);
    if (local_8 == (undefined4 *)0x0) {
      local_8 = (undefined4 *)0x0;
    }
    else {
      FUN_0040d030(local_8,0x10,local_10,FUN_0079e14e);
    }
    if (local_8 != (undefined4 *)0x0) {
      iVar2 = *(int *)(in_ECX[1] + 0x68);
      local_10 = operator_new(iVar2 << 4);
      if (local_10 == (undefined4 *)0x0) {
        local_10 = (undefined4 *)0x0;
      }
      else {
        FUN_0040d030(local_10,0x10,iVar2,FUN_0079e14e);
      }
      if (local_10 == (undefined4 *)0x0) {
        _free(local_8);
        return extraout_EAX;
      }
      iVar2 = ((uint)puVar3 & 0xfffffff) << 2;
      puVar3 = local_8;
      for (; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
      puVar3 = local_10;
      for (iVar2 = (*(uint *)(in_ECX[1] + 0x68) & 0xfffffff) << 2; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar3 = 0;
        puVar3 = puVar3 + 1;
      }
      for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
        *(undefined1 *)puVar3 = 0;
        puVar3 = (undefined4 *)((int)puVar3 + 1);
      }
      if ((*(int *)(in_ECX[1] + 0x10) != 0) && (*(int *)(*in_ECX + 0x10) != 0)) {
        *(undefined4 *)(in_ECX[1] + 0x10) = 0;
        *(undefined4 *)(*in_ECX + 0x10) = 0;
      }
      local_c = 0;
      if (local_14 != 0) {
        do {
          uVar4 = 0;
          if (local_18 != 0) {
            do {
              (**(code **)(*(int *)*in_ECX + 4))(uVar4,local_c,local_8);
              (**(code **)(*(int *)in_ECX[1] + 8))(uVar4,local_c,local_8);
              uVar4 = uVar4 + 1;
            } while (uVar4 < local_18);
          }
          uVar4 = local_18;
          if (local_18 < *(uint *)(in_ECX[1] + 0x6c)) {
            do {
              (**(code **)(*(int *)in_ECX[1] + 8))(uVar4,local_c,local_10);
              uVar4 = uVar4 + 1;
            } while (uVar4 < *(uint *)(in_ECX[1] + 0x6c));
          }
          local_c = local_c + 1;
        } while (local_c < local_14);
      }
      if (local_14 < *(uint *)(in_ECX[1] + 0x70)) {
        uVar4 = *(uint *)(in_ECX[1] + 0x6c);
        do {
          uVar5 = 0;
          if (uVar4 != 0) {
            do {
              (**(code **)(*(int *)in_ECX[1] + 8))(uVar5,local_14,local_10);
              uVar4 = *(uint *)(in_ECX[1] + 0x6c);
              uVar5 = uVar5 + 1;
            } while (uVar5 < uVar4);
          }
          local_14 = local_14 + 1;
        } while (local_14 < *(uint *)(in_ECX[1] + 0x70));
      }
      _free(local_8);
      return extraout_EAX_00;
    }
  }
  return 0x80004005;
}


// ==== FUN_008a7f39 @ 0x008a7f39 ====

undefined4 FUN_008a7f39(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 extraout_EAX;
  int iVar8;
  undefined4 *puVar9;
  undefined4 extraout_EAX_00;
  int *in_ECX;
  undefined4 *puVar10;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  undefined4 *local_c;
  void *local_8;
  
  if ((char)in_ECX[2] == '\x02') {
    iVar1 = *(int *)(*in_ECX + 0x68);
    local_8 = operator_new(iVar1 << 4);
    if (local_8 == (void *)0x0) {
      local_8 = (void *)0x0;
    }
    else {
      FUN_0040d030(local_8,0x10,iVar1,FUN_0079e14e);
    }
    if (local_8 != (void *)0x0) {
      iVar1 = *(int *)(in_ECX[1] + 0x68);
      local_c = operator_new(iVar1 << 4);
      if (local_c == (undefined4 *)0x0) {
        local_c = (undefined4 *)0x0;
      }
      else {
        FUN_0040d030(local_c,0x10,iVar1,FUN_0079e14e);
      }
      if (local_c == (undefined4 *)0x0) {
        _free(local_8);
        return extraout_EAX;
      }
      if ((*(int *)(in_ECX[1] + 0x10) != 0) && (*(int *)(*in_ECX + 0x10) != 0)) {
        *(undefined4 *)(in_ECX[1] + 0x10) = 0;
        *(undefined4 *)(*in_ECX + 0x10) = 0;
      }
      iVar1 = *in_ECX;
      iVar8 = in_ECX[1];
      iVar2 = *(int *)(iVar1 + 0x68);
      uVar3 = *(uint *)(iVar8 + 0x68);
      local_20 = 0;
      local_14 = 0;
      iVar4 = *(int *)(iVar1 + 0x6c);
      uVar5 = *(uint *)(iVar8 + 0x6c);
      iVar1 = *(int *)(iVar1 + 0x70);
      uVar6 = *(uint *)(iVar8 + 0x70);
      if (*(int *)(iVar8 + 0x70) != 0) {
        do {
          local_24 = 0xffffffff;
          local_28 = 0;
          local_10 = 0;
          if (*(int *)(iVar8 + 0x6c) != 0) {
            do {
              local_18 = 0;
              local_1c = 0;
              if (((local_24 ^ local_28) & 0xffff0000) != 0) {
                (**(code **)(*(int *)*in_ECX + 4))(local_28 >> 0x10,local_20 >> 0x10,local_8);
                local_24 = local_28;
              }
              if (*(int *)(in_ECX[1] + 0x68) != 0) {
                puVar9 = local_c;
                do {
                  puVar10 = (undefined4 *)((local_18 >> 0x10) * 0x10 + (int)local_8);
                  local_1c = local_1c + 1;
                  *puVar9 = *puVar10;
                  puVar9[1] = puVar10[1];
                  puVar9[2] = puVar10[2];
                  puVar9[3] = puVar10[3];
                  puVar9 = puVar9 + 4;
                  local_18 = local_18 + (uint)(iVar2 << 0x10) / uVar3;
                } while (local_1c < *(uint *)(in_ECX[1] + 0x68));
              }
              (**(code **)(*(int *)in_ECX[1] + 8))(local_10,local_14,local_c);
              local_28 = local_28 + (uint)(iVar4 << 0x10) / uVar5;
              local_10 = local_10 + 1;
            } while (local_10 < *(uint *)(in_ECX[1] + 0x6c));
          }
          local_20 = local_20 + (uint)(iVar1 << 0x10) / uVar6;
          local_14 = local_14 + 1;
          iVar8 = in_ECX[1];
        } while (local_14 < *(uint *)(iVar8 + 0x70));
      }
      _free(local_8);
      return extraout_EAX_00;
    }
    uVar7 = 0x8007000e;
  }
  else {
    uVar7 = 0x80004005;
  }
  return uVar7;
}


// ==== FUN_008a810f @ 0x008a810f ====

undefined4 FUN_008a810f(void)

{
  int *piVar1;
  uint *puVar2;
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
  int iVar15;
  float fVar16;
  void *pvVar17;
  float *pfVar18;
  float *pfVar19;
  float *pfVar20;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int *in_ECX;
  float *pfVar21;
  uint uVar22;
  int iVar23;
  void *local_1c;
  float *local_18;
  float *local_14;
  uint local_10;
  void *local_c;
  void *local_8;
  
  if ((char)in_ECX[2] != '\x05') {
    return 0x80004005;
  }
  iVar23 = *in_ECX;
  uVar22 = *(uint *)(iVar23 + 0x68);
  iVar15 = in_ECX[1];
  if ((((*(uint *)(iVar15 + 0x68) != uVar22 >> 1) &&
       ((*(uint *)(iVar15 + 0x68) != 1 || (uVar22 != 1)))) ||
      ((*(uint *)(iVar15 + 0x6c) != *(uint *)(iVar23 + 0x6c) >> 1 &&
       ((*(uint *)(iVar15 + 0x6c) != 1 || (*(int *)(iVar23 + 0x6c) != 1)))))) ||
     ((*(int *)(iVar15 + 0x70) != 1 || (*(int *)(iVar23 + 0x70) != 1)))) {
    return 0x80004005;
  }
  if ((1 < uVar22) && ((uVar22 & 1) != 0)) {
    *(uint *)(iVar23 + 0x68) = *(uint *)(iVar23 + 0x68) & 0xfffffffe;
    piVar1 = (int *)(*in_ECX + 0x74);
    *piVar1 = *piVar1 - *(int *)(*in_ECX + 0x78);
  }
  if (1 < *(uint *)(*in_ECX + 0x6c)) {
    puVar2 = (uint *)(*in_ECX + 0x6c);
    *puVar2 = *puVar2 & 0xfffffffe;
  }
  if ((*(byte *)((int)in_ECX + 10) & 8) != 0) goto switchD_008a81fa_caseD_14;
  iVar23 = *in_ECX;
  iVar15 = *(int *)(iVar23 + 4);
  if ((((iVar15 != *(int *)(in_ECX[1] + 4)) || (*(uint *)(iVar23 + 0x68) < 2)) ||
      (*(uint *)(iVar23 + 0x6c) < 2)) ||
     ((*(int *)(in_ECX[1] + 0x10) != 0 || (*(int *)(iVar23 + 0x10) != 0))))
  goto switchD_008a81fa_caseD_14;
  if (iVar15 < 0x1e) {
    if (iVar15 == 0x1d) {
      iVar23 = FUN_008a7706();
    }
    else {
      switch(iVar15) {
      default:
        goto switchD_008a81fa_caseD_14;
      case 0x15:
switchD_008a81fa_caseD_15:
        iVar23 = FUN_008a6e0e();
        break;
      case 0x16:
switchD_008a81fa_caseD_16:
        iVar23 = FUN_008a70a1();
        break;
      case 0x17:
        iVar23 = FUN_008a70c3();
        break;
      case 0x18:
        iVar23 = FUN_008a71f7();
        break;
      case 0x19:
        iVar23 = FUN_008a72fc();
        break;
      case 0x1a:
        iVar23 = FUN_008a7425();
        break;
      case 0x1b:
        iVar23 = FUN_008a755c();
        break;
      case 0x1c:
switchD_008a81fa_caseD_1c:
        iVar23 = FUN_008a767a();
      }
    }
  }
  else if (iVar15 < 0x2a) {
    if (iVar15 == 0x29) goto switchD_008a81fa_caseD_14;
    if (iVar15 != 0x1e) {
      if (iVar15 != 0x20) {
        if (iVar15 != 0x21) goto switchD_008a81fa_caseD_14;
        goto switchD_008a81fa_caseD_16;
      }
      goto switchD_008a81fa_caseD_15;
    }
    iVar23 = FUN_008a7834();
  }
  else {
    if (iVar15 == 0x32) goto switchD_008a81fa_caseD_1c;
    if (iVar15 == 0x33) {
      iVar23 = FUN_008a793d();
    }
    else {
      if (iVar15 != 0x34) goto switchD_008a81fa_caseD_14;
      iVar23 = FUN_008a7a6b();
    }
  }
  if (-1 < iVar23) {
    return 0;
  }
switchD_008a81fa_caseD_14:
  iVar23 = *(int *)(in_ECX[1] + 0x68);
  local_14 = operator_new(iVar23 << 4);
  if (local_14 == (float *)0x0) {
    local_14 = (float *)0x0;
  }
  else {
    FUN_0040d030(local_14,0x10,iVar23,FUN_0079e14e);
  }
  if (local_14 == (float *)0x0) {
    return 0x8007000e;
  }
  iVar23 = *(int *)(*in_ECX + 0x68);
  if (*(int *)(*in_ECX + 0x6c) == 1) {
    local_8 = operator_new(iVar23 << 4);
    if (local_8 == (void *)0x0) {
      local_8 = (void *)0x0;
    }
    else {
      FUN_0040d030(local_8,0x10,iVar23,FUN_0079e14e);
    }
    local_c = local_8;
  }
  else {
    local_8 = operator_new(iVar23 << 5);
    if (local_8 == (void *)0x0) {
      local_8 = (void *)0x0;
    }
    else {
      FUN_0040d030(local_8,0x10,iVar23 << 1,FUN_0079e14e);
    }
    local_c = (void *)(*(int *)(*in_ECX + 0x68) * 0x10 + (int)local_8);
  }
  if (local_8 == (void *)0x0) {
    _free(local_14);
    return extraout_EAX_00;
  }
  if (*(int *)(*in_ECX + 0x68) == 1) {
    pvVar17 = local_c;
    local_1c = local_8;
  }
  else {
    local_1c = (void *)((int)local_8 + 0x10);
    pvVar17 = (void *)((int)local_c + 0x10);
  }
  local_10 = 0;
  if (*(int *)(in_ECX[1] + 0x6c) != 0) {
    do {
      (**(code **)(*(int *)*in_ECX + 4))(local_10 * 2,0,local_8);
      if (local_c != local_8) {
        (**(code **)(*(int *)*in_ECX + 4))(local_10 * 2 + 1,0,local_c);
      }
      fVar16 = DAT_009fc7a0;
      uVar22 = 0;
      if (*(int *)(in_ECX[1] + 0x68) != 0) {
        local_18 = local_14;
        do {
          iVar23 = uVar22 * 0x20;
          pfVar18 = (float *)((int)local_1c + iVar23);
          pfVar21 = (float *)((int)local_8 + iVar23);
          fVar3 = pfVar18[1];
          fVar4 = pfVar21[1];
          fVar5 = pfVar18[2];
          fVar6 = pfVar21[2];
          fVar7 = pfVar18[3];
          fVar8 = pfVar21[3];
          pfVar19 = (float *)((int)local_c + iVar23);
          fVar9 = pfVar19[1];
          fVar10 = pfVar19[2];
          fVar11 = pfVar19[3];
          pfVar20 = (float *)((int)pvVar17 + iVar23);
          uVar22 = uVar22 + 1;
          fVar12 = pfVar20[1];
          fVar13 = pfVar20[2];
          fVar14 = pfVar20[3];
          *local_18 = (*pfVar18 + *pfVar21 + *pfVar19 + *pfVar20) * fVar16;
          local_18[1] = (fVar3 + fVar4 + fVar9 + fVar12) * fVar16;
          local_18[2] = (fVar5 + fVar6 + fVar10 + fVar13) * fVar16;
          local_18[3] = (fVar7 + fVar8 + fVar11 + fVar14) * fVar16;
          local_18 = local_18 + 4;
        } while (uVar22 < *(uint *)(in_ECX[1] + 0x68));
      }
      (**(code **)(*(int *)in_ECX[1] + 8))(local_10,0,local_14);
      local_10 = local_10 + 1;
    } while (local_10 < *(uint *)(in_ECX[1] + 0x6c));
  }
  _free(local_8);
  return extraout_EAX;
}


// ==== FUN_008a84d7 @ 0x008a84d7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008a84d7(void)

{
  uint *puVar1;
  float *pfVar2;
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
  uint uVar27;
  int iVar28;
  float fVar29;
  undefined4 uVar30;
  void *pvVar31;
  int iVar32;
  float *pfVar33;
  undefined4 extraout_EAX;
  undefined4 extraout_EAX_00;
  int *in_ECX;
  int *piVar34;
  float *pfVar35;
  float *pfVar36;
  float *pfVar37;
  float *pfVar38;
  float *pfVar39;
  void *pvVar40;
  float *pfVar41;
  void *local_34;
  void *local_30;
  float *local_2c;
  void *local_28;
  void *local_24;
  uint local_20;
  void *local_1c;
  uint local_18;
  float *local_14;
  uint local_c;
  void *local_8;
  
  if ((char)in_ECX[2] == '\x05') {
    iVar32 = *in_ECX;
    uVar27 = *(uint *)(iVar32 + 0x68);
    iVar28 = in_ECX[1];
    if ((((*(uint *)(iVar28 + 0x68) == uVar27 >> 1) ||
         ((*(uint *)(iVar28 + 0x68) == 1 && (uVar27 == 1)))) &&
        ((*(uint *)(iVar28 + 0x6c) == *(uint *)(iVar32 + 0x6c) >> 1 ||
         ((*(uint *)(iVar28 + 0x6c) == 1 && (*(int *)(iVar32 + 0x6c) == 1)))))) &&
       (*(uint *)(iVar28 + 0x70) == *(uint *)(iVar32 + 0x70) >> 1)) {
      if ((1 < uVar27) && ((uVar27 & 1) != 0)) {
        *(uint *)(iVar32 + 0x68) = *(uint *)(iVar32 + 0x68) & 0xfffffffe;
        piVar34 = (int *)(*in_ECX + 0x74);
        *piVar34 = *piVar34 - *(int *)(*in_ECX + 0x78);
      }
      if (1 < *(uint *)(*in_ECX + 0x6c)) {
        puVar1 = (uint *)(*in_ECX + 0x6c);
        *puVar1 = *puVar1 & 0xfffffffe;
      }
      if (1 < *(uint *)(*in_ECX + 0x70)) {
        puVar1 = (uint *)(*in_ECX + 0x70);
        *puVar1 = *puVar1 & 0xfffffffe;
      }
      iVar32 = *(int *)(in_ECX[1] + 0x68);
      local_14 = operator_new(iVar32 << 4);
      if (local_14 == (float *)0x0) {
        local_14 = (float *)0x0;
      }
      else {
        FUN_0040d030(local_14,0x10,iVar32,FUN_0079e14e);
      }
      if (local_14 != (float *)0x0) {
        iVar32 = *(int *)(*in_ECX + 0x68);
        if (*(int *)(*in_ECX + 0x6c) == 1) {
          local_8 = operator_new(iVar32 << 5);
          if (local_8 == (void *)0x0) {
            local_8 = (void *)0x0;
          }
          else {
            FUN_0040d030(local_8,0x10,iVar32 << 1,FUN_0079e14e);
          }
          piVar34 = (int *)(*in_ECX + 0x68);
          local_28 = (void *)(*piVar34 * 0x10 + (int)local_8);
          local_1c = local_8;
          local_24 = local_28;
        }
        else {
          local_8 = operator_new(iVar32 << 6);
          if (local_8 == (void *)0x0) {
            local_8 = (void *)0x0;
          }
          else {
            FUN_0040d030(local_8,0x10,iVar32 << 2,FUN_0079e14e);
          }
          piVar34 = (int *)(*in_ECX + 0x68);
          iVar32 = *piVar34;
          local_28 = (void *)(iVar32 * 0x10 + (int)local_8);
          local_1c = (void *)(iVar32 * 0x20 + (int)local_8);
          local_24 = (void *)(iVar32 * 0x30 + (int)local_8);
        }
        if (local_8 == (void *)0x0) {
          _free(local_14);
          return extraout_EAX_00;
        }
        if (*piVar34 == 1) {
          local_34 = local_8;
          pvVar31 = local_1c;
          pvVar40 = local_24;
          local_30 = local_28;
        }
        else {
          local_34 = (void *)((int)local_8 + 0x10);
          local_30 = (void *)((int)local_28 + 0x10);
          pvVar31 = (void *)((int)local_1c + 0x10);
          pvVar40 = (void *)((int)local_24 + 0x10);
        }
        local_18 = 0;
        iVar32 = in_ECX[1];
        if (*(int *)(iVar32 + 0x70) != 0) {
          do {
            local_c = 0;
            if (*(int *)(iVar32 + 0x6c) != 0) {
              do {
                iVar32 = local_18 * 2;
                (**(code **)(*(int *)*in_ECX + 4))(local_c * 2,iVar32,local_8);
                if (local_28 != local_8) {
                  (**(code **)(*(int *)*in_ECX + 4))(local_c * 2,iVar32 + 1,local_28);
                }
                if (local_1c != local_8) {
                  (**(code **)(*(int *)*in_ECX + 4))(local_c * 2 + 1,iVar32,local_1c);
                }
                if ((local_24 != local_28) && (local_24 != local_1c)) {
                  (**(code **)(*(int *)*in_ECX + 4))(local_c * 2 + 1,iVar32 + 1,local_24);
                }
                fVar29 = _DAT_009b0e90;
                local_20 = 0;
                if (*(int *)(in_ECX[1] + 0x68) != 0) {
                  local_2c = local_14;
                  do {
                    iVar32 = local_20 * 0x20;
                    pfVar35 = (float *)((int)local_34 + iVar32);
                    pfVar41 = (float *)((int)local_8 + iVar32);
                    fVar3 = pfVar35[1];
                    fVar4 = pfVar41[1];
                    fVar5 = pfVar35[2];
                    fVar6 = pfVar41[2];
                    fVar7 = pfVar35[3];
                    pfVar2 = (float *)(iVar32 + (int)local_28);
                    fVar8 = pfVar41[3];
                    fVar9 = pfVar2[1];
                    fVar10 = pfVar2[2];
                    fVar11 = pfVar2[3];
                    pfVar36 = (float *)((int)local_30 + iVar32);
                    fVar12 = pfVar36[1];
                    fVar13 = pfVar36[2];
                    fVar14 = pfVar36[3];
                    pfVar37 = (float *)((int)local_1c + iVar32);
                    fVar15 = pfVar37[1];
                    fVar16 = pfVar37[2];
                    fVar17 = pfVar37[3];
                    pfVar38 = (float *)((int)pvVar31 + iVar32);
                    fVar18 = pfVar38[1];
                    fVar19 = pfVar38[2];
                    fVar20 = pfVar38[3];
                    pfVar39 = (float *)((int)local_24 + iVar32);
                    fVar21 = pfVar39[1];
                    fVar22 = pfVar39[2];
                    fVar23 = pfVar39[3];
                    pfVar33 = (float *)(iVar32 + (int)pvVar40);
                    local_20 = local_20 + 1;
                    fVar24 = pfVar33[1];
                    fVar25 = pfVar33[2];
                    fVar26 = pfVar33[3];
                    *local_2c = (*pfVar35 + *pfVar41 + *pfVar2 + *pfVar36 + *pfVar37 + *pfVar38 +
                                 *pfVar39 + *pfVar33) * fVar29;
                    local_2c[1] = (fVar3 + fVar4 + fVar9 + fVar12 + fVar15 + fVar18 + fVar21 +
                                  fVar24) * fVar29;
                    local_2c[2] = (fVar5 + fVar6 + fVar10 + fVar13 + fVar16 + fVar19 + fVar22 +
                                  fVar25) * fVar29;
                    local_2c[3] = (fVar7 + fVar8 + fVar11 + fVar14 + fVar17 + fVar20 + fVar23 +
                                  fVar26) * fVar29;
                    local_2c = local_2c + 4;
                  } while (local_20 < *(uint *)(in_ECX[1] + 0x68));
                }
                (**(code **)(*(int *)in_ECX[1] + 8))(local_c,local_18,local_14);
                local_c = local_c + 1;
              } while (local_c < *(uint *)(in_ECX[1] + 0x6c));
            }
            local_18 = local_18 + 1;
            iVar32 = in_ECX[1];
          } while (local_18 < *(uint *)(iVar32 + 0x70));
        }
        _free(local_8);
        return extraout_EAX;
      }
      uVar30 = 0x8007000e;
    }
    else {
      uVar30 = 0x80004005;
    }
  }
  else {
    uVar30 = 0x80004005;
  }
  return uVar30;
}


// ==== FUN_008a88df @ 0x008a88df ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint * FUN_008a88df(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint unaff_ESI;
  uint unaff_EDI;
  uint local_8;
  
  puVar4 = operator_new(unaff_EDI << 4);
  if (puVar4 != (uint *)0x0) {
    fVar1 = (float)(int)unaff_ESI;
    if ((int)unaff_ESI < 0) {
      fVar1 = fVar1 + _DAT_0099d104;
    }
    fVar2 = (float)(int)unaff_EDI;
    if ((int)unaff_EDI < 0) {
      fVar2 = fVar2 + _DAT_0099d104;
    }
    local_8 = 0;
    puVar6 = puVar4;
    if (unaff_EDI != 0) {
      do {
        fVar3 = (float)(int)local_8;
        if ((int)local_8 < 0) {
          fVar3 = fVar3 + _DAT_0099d104;
        }
        fVar3 = (fVar3 + DAT_0099d0b4) * (fVar1 / fVar2) + DAT_0099d0b4;
        uVar5 = (uint)ROUND(fVar3);
        uVar7 = uVar5 - 1;
        fVar3 = ((float)(int)uVar5 + DAT_0099d080) - fVar3;
        if ((int)uVar7 < 0) {
          uVar7 = -(uint)(param_1 != 0) & unaff_ESI - 1;
        }
        if (unaff_ESI <= uVar5) {
          uVar5 = ~-(uint)(param_1 != 0) & unaff_ESI - 1;
        }
        puVar6[1] = (uint)fVar3;
        *puVar6 = uVar7;
        puVar6[2] = uVar5;
        local_8 = local_8 + 1;
        puVar6[3] = (uint)(1.0 - fVar3);
        puVar6 = puVar6 + 4;
      } while (local_8 < unaff_EDI);
    }
  }
  return puVar4;
}


// ==== FUN_008a89cb @ 0x008a89cb ====

undefined4 FUN_008a89cb(void)

{
  float *pfVar1;
  float *pfVar2;
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
  uint uVar21;
  int iVar22;
  void *_Memory;
  int iVar23;
  int *piVar24;
  undefined4 extraout_EAX;
  int *in_ECX;
  float *pfVar25;
  float *pfVar26;
  void *pvVar27;
  void *pvVar28;
  uint local_34;
  int local_30;
  float *local_2c;
  void *local_24;
  uint local_20;
  int local_1c;
  void *local_14;
  void *local_10;
  float *local_c;
  int *local_8;
  
  uVar21 = in_ECX[2];
  if ((((char)uVar21 != '\x03') || (*(int *)(in_ECX[1] + 0x70) != 1)) ||
     (*(int *)(*in_ECX + 0x70) != 1)) {
    return 0x80004005;
  }
  _Memory = (void *)FUN_008a88df(~(uVar21 >> 0x10) & 1);
  iVar23 = FUN_008a88df(~(uVar21 >> 0x11) & 1);
  if ((_Memory != (void *)0x0) && (iVar23 != 0)) {
    iVar22 = *(int *)(in_ECX[1] + 0x68);
    local_c = operator_new(iVar22 << 4);
    if (local_c == (float *)0x0) {
      local_c = (float *)0x0;
    }
    else {
      FUN_0040d030(local_c,0x10,iVar22,FUN_0079e14e);
    }
    if (local_c != (float *)0x0) {
      iVar22 = *(int *)(*in_ECX + 0x68);
      local_14 = operator_new(iVar22 << 5);
      if (local_14 == (void *)0x0) {
        local_14 = (void *)0x0;
      }
      else {
        FUN_0040d030(local_14,0x10,iVar22 << 1,FUN_0079e14e);
      }
      if (local_14 != (void *)0x0) {
        local_20 = 0;
        local_30 = -1;
        local_1c = -1;
        pvVar27 = (void *)(*(int *)(*in_ECX + 0x68) * 0x10 + (int)local_14);
        local_24 = local_14;
        if (*(int *)(in_ECX[1] + 0x6c) != 0) {
          local_8 = (int *)(iVar23 + 8);
          local_10 = pvVar27;
          do {
            iVar22 = local_1c;
            iVar23 = local_8[-2];
            local_34 = 0;
            pvVar28 = pvVar27;
            if (iVar23 != local_30) {
              if (iVar23 == local_1c) {
                local_1c = -1;
                local_30 = iVar22;
                local_10 = local_24;
                pvVar28 = local_24;
                local_24 = pvVar27;
              }
              else {
                (**(code **)(*(int *)*in_ECX + 4))(iVar23,0,local_24);
                local_30 = iVar23;
              }
            }
            iVar23 = *local_8;
            if (iVar23 != local_1c) {
              (**(code **)(*(int *)*in_ECX + 4))(iVar23,0,pvVar28);
              local_1c = iVar23;
            }
            pvVar27 = pvVar28;
            if (*(int *)(in_ECX[1] + 0x68) != 0) {
              piVar24 = (int *)((int)_Memory + 8);
              local_2c = local_c;
              do {
                fVar3 = (float)piVar24[1];
                pfVar1 = (float *)(*piVar24 * 0x10 + (int)pvVar28);
                fVar4 = pfVar1[1];
                fVar5 = pfVar1[2];
                fVar6 = pfVar1[3];
                fVar7 = (float)piVar24[-1];
                pfVar2 = (float *)(piVar24[-2] * 0x10 + (int)pvVar28);
                pfVar25 = (float *)(*piVar24 * 0x10 + (int)local_24);
                fVar8 = pfVar2[1];
                pfVar26 = (float *)(piVar24[-2] * 0x10 + (int)local_24);
                fVar9 = pfVar2[2];
                fVar10 = pfVar2[3];
                fVar11 = (float)local_8[1];
                fVar12 = (float)piVar24[1];
                fVar13 = pfVar25[1];
                fVar14 = pfVar25[2];
                fVar15 = pfVar25[3];
                fVar16 = (float)piVar24[-1];
                fVar17 = pfVar26[1];
                fVar18 = pfVar26[2];
                fVar19 = pfVar26[3];
                piVar24 = piVar24 + 4;
                local_34 = local_34 + 1;
                fVar20 = (float)local_8[-1];
                *local_2c = (fVar16 * *pfVar26 + fVar12 * *pfVar25) * fVar20 +
                            (fVar7 * *pfVar2 + fVar3 * *pfVar1) * fVar11;
                local_2c[1] = (fVar16 * fVar17 + fVar12 * fVar13) * fVar20 +
                              (fVar7 * fVar8 + fVar3 * fVar4) * fVar11;
                local_2c[2] = (fVar16 * fVar18 + fVar12 * fVar14) * fVar20 +
                              (fVar7 * fVar9 + fVar3 * fVar5) * fVar11;
                local_2c[3] = (fVar12 * fVar15 + fVar16 * fVar19) * fVar20 +
                              (fVar3 * fVar6 + fVar7 * fVar10) * fVar11;
                pvVar28 = local_10;
                pvVar27 = local_10;
                local_2c = local_2c + 4;
              } while (local_34 < *(uint *)(in_ECX[1] + 0x68));
            }
            (**(code **)(*(int *)in_ECX[1] + 8))(local_20,0,local_c);
            local_8 = local_8 + 4;
            local_20 = local_20 + 1;
          } while (local_20 < *(uint *)(in_ECX[1] + 0x6c));
        }
      }
    }
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_008a8d6d @ 0x008a8d6d ====

undefined4 FUN_008a8d6d(void)

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
  float fVar33;
  float fVar34;
  float fVar35;
  float fVar36;
  float fVar37;
  float fVar38;
  float fVar39;
  uint uVar40;
  int iVar41;
  void *pvVar42;
  void *_Memory;
  int iVar43;
  int iVar44;
  int iVar45;
  int *piVar46;
  undefined4 extraout_EAX;
  int *in_ECX;
  float *pfVar47;
  float *pfVar48;
  float *pfVar49;
  float *pfVar50;
  void *pvVar51;
  void *pvVar52;
  float *pfVar53;
  float *pfVar54;
  float *pfVar55;
  uint local_48;
  float *local_3c;
  void *local_38;
  void *local_30;
  void *local_2c;
  void *local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  void *local_18;
  int local_14;
  float *local_10;
  undefined4 *local_c;
  int *local_8;
  
  uVar40 = in_ECX[2];
  if ((char)uVar40 != '\x03') {
    return 0x80004005;
  }
  _Memory = (void *)FUN_008a88df(~(uVar40 >> 0x10) & 1);
  iVar43 = FUN_008a88df(~(uVar40 >> 0x11) & 1);
  iVar44 = FUN_008a88df(~(uVar40 >> 0x12) & 1);
  if (((_Memory != (void *)0x0) && (iVar43 != 0)) && (iVar44 != 0)) {
    iVar41 = *(int *)(in_ECX[1] + 0x68);
    local_10 = operator_new(iVar41 << 4);
    if (local_10 == (float *)0x0) {
      local_10 = (float *)0x0;
    }
    else {
      FUN_0040d030(local_10,0x10,iVar41,FUN_0079e14e);
    }
    if (local_10 != (float *)0x0) {
      iVar41 = *(int *)(*in_ECX + 0x68);
      local_28 = operator_new(iVar41 << 6);
      if (local_28 == (void *)0x0) {
        local_28 = (void *)0x0;
      }
      else {
        FUN_0040d030(local_28,0x10,iVar41 << 2,FUN_0079e14e);
      }
      if (local_28 != (void *)0x0) {
        iVar41 = *(int *)(*in_ECX + 0x68);
        local_24 = 0;
        local_18 = (void *)(iVar41 * 0x10 + (int)local_28);
        iVar45 = in_ECX[1];
        local_2c = (void *)(iVar41 * 0x20 + (int)local_28);
        pvVar51 = (void *)(iVar41 * 0x30 + (int)local_28);
        local_38 = local_28;
        if (*(int *)(iVar45 + 0x70) != 0) {
          local_c = (undefined4 *)(iVar44 + 8);
          local_30 = pvVar51;
          do {
            local_20 = 0;
            local_1c = -1;
            local_14 = -1;
            if (*(int *)(iVar45 + 0x6c) != 0) {
              local_8 = (int *)(iVar43 + 8);
              do {
                iVar41 = local_14;
                pvVar42 = local_18;
                iVar44 = local_8[-2];
                local_48 = 0;
                pvVar52 = pvVar51;
                if (iVar44 != local_1c) {
                  if (iVar44 == local_14) {
                    local_14 = -1;
                    local_1c = iVar41;
                    local_18 = local_38;
                    local_38 = pvVar42;
                    local_30 = local_2c;
                    pvVar52 = local_2c;
                    local_2c = pvVar51;
                  }
                  else {
                    (**(code **)(*(int *)*in_ECX + 4))(iVar44,local_c[-2],local_38);
                    (**(code **)(*(int *)*in_ECX + 4))(iVar44,*local_c,local_2c);
                    local_1c = iVar44;
                  }
                }
                iVar44 = *local_8;
                if (iVar44 != local_14) {
                  (**(code **)(*(int *)*in_ECX + 4))(iVar44,local_c[-2],local_18);
                  (**(code **)(*(int *)*in_ECX + 4))(iVar44,*local_c,pvVar52);
                  local_14 = iVar44;
                }
                pvVar51 = pvVar52;
                if (*(int *)(in_ECX[1] + 0x68) != 0) {
                  piVar46 = (int *)((int)_Memory + 8);
                  local_3c = local_10;
                  do {
                    fVar2 = (float)piVar46[1];
                    pfVar1 = (float *)(*piVar46 * 0x10 + (int)local_30);
                    fVar3 = pfVar1[1];
                    fVar4 = pfVar1[2];
                    fVar5 = pfVar1[3];
                    fVar6 = (float)piVar46[-1];
                    iVar44 = piVar46[-2] * 0x10;
                    pfVar48 = (float *)((int)local_30 + iVar44);
                    fVar7 = pfVar48[1];
                    fVar8 = pfVar48[2];
                    fVar9 = pfVar48[3];
                    pfVar53 = (float *)(*piVar46 * 0x10 + (int)local_2c);
                    pfVar49 = (float *)((int)local_2c + iVar44);
                    fVar10 = (float)local_8[1];
                    fVar11 = (float)piVar46[1];
                    fVar12 = pfVar53[1];
                    fVar13 = pfVar53[2];
                    fVar14 = pfVar53[3];
                    fVar15 = (float)piVar46[-1];
                    fVar16 = pfVar49[1];
                    fVar17 = pfVar49[2];
                    fVar18 = pfVar49[3];
                    fVar19 = (float)local_8[-1];
                    fVar20 = (float)local_c[1];
                    pfVar54 = (float *)((int)local_18 + *piVar46 * 0x10);
                    fVar21 = (float)piVar46[1];
                    fVar22 = pfVar54[1];
                    fVar23 = pfVar54[2];
                    fVar24 = pfVar54[3];
                    fVar25 = (float)piVar46[-1];
                    pfVar55 = (float *)((int)local_18 + iVar44);
                    fVar26 = pfVar55[1];
                    fVar27 = pfVar55[2];
                    fVar28 = pfVar55[3];
                    pfVar50 = (float *)(*piVar46 * 0x10 + (int)local_38);
                    pfVar47 = (float *)(iVar44 + (int)local_38);
                    fVar29 = (float)local_8[1];
                    fVar30 = (float)piVar46[1];
                    fVar31 = pfVar50[1];
                    fVar32 = pfVar50[2];
                    fVar33 = pfVar50[3];
                    fVar34 = (float)piVar46[-1];
                    fVar35 = pfVar47[1];
                    fVar36 = pfVar47[2];
                    fVar37 = pfVar47[3];
                    fVar38 = (float)local_8[-1];
                    fVar39 = (float)local_c[-1];
                    piVar46 = piVar46 + 4;
                    local_48 = local_48 + 1;
                    *local_3c = ((fVar34 * *pfVar47 + fVar30 * *pfVar50) * fVar38 +
                                (fVar25 * *pfVar55 + fVar21 * *pfVar54) * fVar29) * fVar39 +
                                ((fVar15 * *pfVar49 + fVar11 * *pfVar53) * fVar19 +
                                (fVar6 * *pfVar48 + fVar2 * *pfVar1) * fVar10) * fVar20;
                    local_3c[1] = ((fVar34 * fVar35 + fVar30 * fVar31) * fVar38 +
                                  (fVar25 * fVar26 + fVar21 * fVar22) * fVar29) * fVar39 +
                                  ((fVar15 * fVar16 + fVar11 * fVar12) * fVar19 +
                                  (fVar6 * fVar7 + fVar2 * fVar3) * fVar10) * fVar20;
                    local_3c[2] = ((fVar34 * fVar36 + fVar30 * fVar32) * fVar38 +
                                  (fVar25 * fVar27 + fVar21 * fVar23) * fVar29) * fVar39 +
                                  ((fVar15 * fVar17 + fVar11 * fVar13) * fVar19 +
                                  (fVar6 * fVar8 + fVar2 * fVar4) * fVar10) * fVar20;
                    local_3c[3] = ((fVar30 * fVar33 + fVar34 * fVar37) * fVar38 +
                                  (fVar21 * fVar24 + fVar25 * fVar28) * fVar29) * fVar39 +
                                  ((fVar11 * fVar14 + fVar15 * fVar18) * fVar19 +
                                  (fVar2 * fVar5 + fVar6 * fVar9) * fVar10) * fVar20;
                    local_3c = local_3c + 4;
                  } while (local_48 < *(uint *)(in_ECX[1] + 0x68));
                  pvVar51 = local_30;
                }
                (**(code **)(*(int *)in_ECX[1] + 8))(local_20,local_24,local_10);
                local_8 = local_8 + 4;
                local_20 = local_20 + 1;
              } while (local_20 < *(uint *)(in_ECX[1] + 0x6c));
            }
            local_c = local_c + 4;
            local_24 = local_24 + 1;
            iVar45 = in_ECX[1];
          } while (local_24 < *(uint *)(iVar45 + 0x70));
        }
      }
    }
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_008a942f @ 0x008a942f ====

undefined4 * FUN_008a942f(byte param_1)

{
  undefined4 *_Memory;
  undefined4 *extraout_EAX;
  undefined4 *extraout_EAX_00;
  undefined4 *in_ECX;
  
  if ((param_1 & 2) == 0) {
    _free((void *)*in_ECX);
    return extraout_EAX_00;
  }
  _Memory = in_ECX + -1;
  FUN_0049b480(in_ECX,0xc,*_Memory,&DAT_008a68c5);
  if ((param_1 & 1) == 0) {
    return _Memory;
  }
  _free(_Memory);
  return extraout_EAX;
}


// ==== FUN_008a947e @ 0x008a947e ====

void FUN_008a947e(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  int *piVar8;
  void *pvVar9;
  int *piVar10;
  int iVar11;
  int *in_ECX;
  int *piVar12;
  int iVar13;
  int *piVar14;
  int *piVar15;
  float *pfVar16;
  uint uVar17;
  int *piVar18;
  int *piVar19;
  undefined4 *puVar20;
  float *pfVar21;
  int local_38;
  int *local_34;
  int local_2c;
  int *local_28;
  int *local_1c;
  int *local_18;
  void *local_10;
  int *local_c;
  int *local_8;
  
  uVar17 = in_ECX[2];
  local_1c = (int *)0x0;
  local_c = (int *)0x0;
  local_18 = (int *)0x0;
  piVar6 = (int *)FUN_008a68ce(*(undefined4 *)(*in_ECX + 0x68),*(undefined4 *)(in_ECX[1] + 0x68),
                               ~(uVar17 >> 0x10) & 1);
  if (((piVar6 != (int *)0x0) &&
      (piVar7 = (int *)FUN_008a68ce(*(undefined4 *)(*in_ECX + 0x6c),
                                    *(undefined4 *)(in_ECX[1] + 0x6c),~(uVar17 >> 0x11) & 1),
      piVar7 != (int *)0x0)) &&
     (local_1c = (int *)FUN_008a68ce(*(undefined4 *)(*in_ECX + 0x70),
                                     *(undefined4 *)(in_ECX[1] + 0x70),~(uVar17 >> 0x12) & 1),
     local_1c != (int *)0x0)) {
    iVar3 = *piVar6;
    iVar4 = *piVar7;
    piVar18 = (int *)(*local_1c + (int)local_1c);
    iVar13 = *(int *)(in_ECX[1] + 0x70);
    local_c = operator_new(iVar13 * 0xc + 4);
    if (local_c == (int *)0x0) {
      local_c = (int *)0x0;
    }
    else {
      *local_c = iVar13;
      local_c = local_c + 1;
      FUN_0040d030(local_c,0xc,iVar13,FUN_008a68b8);
    }
    if (local_c != (int *)0x0) {
      iVar13 = *(int *)(*in_ECX + 0x68);
      local_10 = operator_new(iVar13 << 4);
      if (local_10 == (void *)0x0) {
        local_10 = (void *)0x0;
      }
      else {
        FUN_0040d030(local_10,0x10,iVar13,FUN_0079e14e);
      }
      if (local_10 != (void *)0x0) {
        piVar8 = local_1c + 1;
        piVar10 = piVar8;
        while (piVar10 < piVar18) {
          piVar15 = (int *)(*piVar10 + (int)piVar10);
          for (piVar12 = piVar10 + 1; piVar10 = piVar15, piVar12 < piVar15; piVar12 = piVar12 + 2) {
            local_c[*piVar12 * 3 + 2] = local_c[*piVar12 * 3 + 2] + 1;
          }
        }
        local_38 = 0;
        if (piVar8 < piVar18) {
          fVar2 = DAT_0099d0dc;
          do {
            piVar12 = (int *)(*piVar8 + (int)piVar8);
            piVar8 = piVar8 + 1;
            for (piVar10 = piVar8; piVar10 < piVar12; piVar10 = piVar10 + 2) {
              piVar15 = local_c + *piVar10 * 3;
              if (*piVar15 == 0) {
                if (local_18 == (int *)0x0) {
                  iVar13 = *(int *)(in_ECX[1] + 0x6c) * *(int *)(in_ECX[1] + 0x68);
                  pvVar9 = operator_new(iVar13 * 0x10);
                  if (pvVar9 == (void *)0x0) {
                    pvVar9 = (void *)0x0;
                  }
                  else {
                    FUN_0040d030(pvVar9,0x10,iVar13,FUN_0079e14e);
                  }
                  *piVar15 = (int)pvVar9;
                  if (pvVar9 == (void *)0x0) goto LAB_008a9ac5;
                  fVar2 = DAT_0099d0dc;
                }
                else {
                  *piVar15 = *local_18;
                  *local_18 = 0;
                  local_18 = (int *)local_18[1];
                }
                puVar20 = (undefined4 *)*piVar15;
                for (iVar13 = (*(int *)(in_ECX[1] + 0x6c) * *(int *)(in_ECX[1] + 0x68) & 0xfffffffU)
                              << 2; iVar13 != 0; iVar13 = iVar13 + -1) {
                  *puVar20 = 0;
                  puVar20 = puVar20 + 1;
                }
                for (iVar13 = 0; iVar13 != 0; iVar13 = iVar13 + -1) {
                  *(undefined1 *)puVar20 = 0;
                  puVar20 = (undefined4 *)((int)puVar20 + 1);
                }
              }
            }
            local_2c = 0;
            local_34 = piVar7 + 1;
            if (local_34 < (int *)(iVar4 + (int)piVar7)) {
              do {
                piVar10 = (int *)(*local_34 + (int)local_34);
                (**(code **)(*(int *)*in_ECX + 4))(local_2c,local_38,local_10);
                if (piVar6 + 1 < (int *)(iVar3 + (int)piVar6)) {
                  pfVar16 = (float *)((int)local_10 + 8);
                  local_28 = piVar6 + 1;
                  do {
                    piVar15 = (int *)(*local_28 + (int)local_28);
                    for (local_8 = piVar8; local_8 < piVar12; local_8 = local_8 + 2) {
                      for (piVar19 = local_34 + 1; piVar19 < piVar10; piVar19 = piVar19 + 2) {
                        iVar13 = *(int *)(in_ECX[1] + 0x68) * *piVar19 * 0x10 +
                                 local_c[*local_8 * 3];
                        for (piVar14 = local_28 + 1; piVar14 < piVar15; piVar14 = piVar14 + 2) {
                          pfVar21 = (float *)(*piVar14 * 0x10 + iVar13);
                          fVar2 = (float)piVar14[1] * (float)local_8[1] * (float)piVar19[1];
                          *pfVar21 = fVar2 * pfVar16[-2] + *pfVar21;
                          pfVar21 = (float *)(*piVar14 * 0x10 + 4 + iVar13);
                          *pfVar21 = fVar2 * pfVar16[-1] + *pfVar21;
                          pfVar21 = (float *)(*piVar14 * 0x10 + 8 + iVar13);
                          *pfVar21 = fVar2 * *pfVar16 + *pfVar21;
                          pfVar21 = (float *)(*piVar14 * 0x10 + 0xc + iVar13);
                          *pfVar21 = fVar2 * pfVar16[1] + *pfVar21;
                        }
                      }
                    }
                    pfVar16 = pfVar16 + 4;
                    local_28 = piVar15;
                  } while (piVar15 < (int *)(iVar3 + (int)piVar6));
                }
                local_2c = local_2c + 1;
                local_34 = piVar10;
              } while (piVar10 < (int *)(iVar4 + (int)piVar7));
              fVar2 = DAT_0099d0dc;
            }
            for (; piVar8 < piVar12; piVar8 = piVar8 + 2) {
              piVar15 = local_c + *piVar8 * 3;
              piVar10 = piVar15 + 2;
              *piVar10 = *piVar10 + -1;
              if (*piVar10 == 0) {
                iVar13 = in_ECX[1];
                local_8 = (int *)0x0;
                if (*(int *)(iVar13 + 0x6c) != 0) {
                  do {
                    fVar1 = DAT_0099d080;
                    iVar13 = *(int *)(iVar13 + 0x68);
                    iVar5 = *(int *)(*in_ECX + 8);
                    iVar11 = iVar13 * (int)local_8 * 0x10 + *piVar15;
                    if (iVar5 == 1) {
                      uVar17 = 0;
                      if (iVar13 != 0) {
                        pfVar16 = (float *)(iVar11 + 8);
                        do {
                          if (0.0 <= pfVar16[-2]) {
                            if (fVar1 <= pfVar16[-2]) {
                              fVar2 = 1.0;
                            }
                            else {
                              fVar2 = pfVar16[-2];
                            }
                          }
                          else {
                            fVar2 = 0.0;
                          }
                          pfVar16[-2] = fVar2;
                          if (0.0 <= pfVar16[-1]) {
                            if (fVar1 <= pfVar16[-1]) {
                              fVar2 = 1.0;
                            }
                            else {
                              fVar2 = pfVar16[-1];
                            }
                          }
                          else {
                            fVar2 = 0.0;
                          }
                          pfVar16[-1] = fVar2;
                          if (0.0 <= *pfVar16) {
                            if (fVar1 <= *pfVar16) {
                              fVar2 = 1.0;
                            }
                            else {
                              fVar2 = *pfVar16;
                            }
                          }
                          else {
                            fVar2 = 0.0;
                          }
                          *pfVar16 = fVar2;
                          if (0.0 <= pfVar16[1]) {
                            if (fVar1 <= pfVar16[1]) {
                              fVar2 = 1.0;
                            }
                            else {
                              fVar2 = pfVar16[1];
                            }
                          }
                          else {
                            fVar2 = 0.0;
                          }
                          pfVar16[1] = fVar2;
                          uVar17 = uVar17 + 1;
                          pfVar16 = pfVar16 + 4;
                        } while (uVar17 < *(uint *)(in_ECX[1] + 0x68));
                      }
                    }
                    else if (iVar5 == 2) {
                      uVar17 = 0;
                      if (iVar13 != 0) {
                        pfVar16 = (float *)(iVar11 + 8);
                        do {
                          if (fVar2 <= pfVar16[-2]) {
                            if (DAT_0099d080 <= pfVar16[-2]) {
                              fVar1 = 1.0;
                            }
                            else {
                              fVar1 = pfVar16[-2];
                            }
                          }
                          else {
                            fVar1 = fVar2;
                          }
                          pfVar16[-2] = fVar1;
                          if (fVar2 <= pfVar16[-1]) {
                            if (DAT_0099d080 <= pfVar16[-1]) {
                              fVar1 = 1.0;
                            }
                            else {
                              fVar1 = pfVar16[-1];
                            }
                          }
                          else {
                            fVar1 = fVar2;
                          }
                          pfVar16[-1] = fVar1;
                          if (fVar2 <= *pfVar16) {
                            if (DAT_0099d080 <= *pfVar16) {
                              fVar1 = 1.0;
                            }
                            else {
                              fVar1 = *pfVar16;
                            }
                          }
                          else {
                            fVar1 = fVar2;
                          }
                          *pfVar16 = fVar1;
                          if (0.0 <= pfVar16[1]) {
                            if (DAT_0099d080 <= pfVar16[1]) {
                              fVar1 = 1.0;
                            }
                            else {
                              fVar1 = pfVar16[1];
                            }
                          }
                          else {
                            fVar1 = 0.0;
                          }
                          pfVar16[1] = fVar1;
                          uVar17 = uVar17 + 1;
                          pfVar16 = pfVar16 + 4;
                        } while (uVar17 < *(uint *)(in_ECX[1] + 0x68));
                      }
                    }
                    else if ((iVar5 == 3) && (uVar17 = 0, iVar13 != 0)) {
                      pfVar16 = (float *)(iVar11 + 8);
                      do {
                        if (fVar2 <= pfVar16[-2]) {
                          if (DAT_0099d080 <= pfVar16[-2]) {
                            fVar1 = 1.0;
                          }
                          else {
                            fVar1 = pfVar16[-2];
                          }
                        }
                        else {
                          fVar1 = fVar2;
                        }
                        pfVar16[-2] = fVar1;
                        if (fVar2 <= pfVar16[-1]) {
                          if (DAT_0099d080 <= pfVar16[-1]) {
                            fVar1 = 1.0;
                          }
                          else {
                            fVar1 = pfVar16[-1];
                          }
                        }
                        else {
                          fVar1 = fVar2;
                        }
                        pfVar16[-1] = fVar1;
                        if (fVar2 <= *pfVar16) {
                          if (DAT_0099d080 <= *pfVar16) {
                            fVar1 = 1.0;
                          }
                          else {
                            fVar1 = *pfVar16;
                          }
                        }
                        else {
                          fVar1 = fVar2;
                        }
                        *pfVar16 = fVar1;
                        if (fVar2 <= pfVar16[1]) {
                          if (DAT_0099d080 <= pfVar16[1]) {
                            fVar1 = 1.0;
                          }
                          else {
                            fVar1 = pfVar16[1];
                          }
                        }
                        else {
                          fVar1 = fVar2;
                        }
                        pfVar16[1] = fVar1;
                        uVar17 = uVar17 + 1;
                        pfVar16 = pfVar16 + 4;
                      } while (uVar17 < *(uint *)(in_ECX[1] + 0x68));
                    }
                    (**(code **)(*(int *)in_ECX[1] + 8))
                              (local_8,*piVar8,
                               ((int *)in_ECX[1])[0x1a] * (int)local_8 * 0x10 + *piVar15);
                    local_8 = (int *)((int)local_8 + 1);
                    iVar13 = in_ECX[1];
                    fVar2 = DAT_0099d0dc;
                  } while (local_8 < *(uint *)(iVar13 + 0x6c));
                }
                piVar15[1] = (int)local_18;
                local_18 = piVar15;
              }
            }
            local_38 = local_38 + 1;
            piVar8 = piVar12;
          } while (piVar12 < piVar18);
        }
      }
    }
  }
LAB_008a9ac5:
  if (local_c != (int *)0x0) {
    FUN_008a942f(3);
  }
  _free(local_1c);
  return;
}


// ==== FUN_008a9b04 @ 0x008a9b04 ====

undefined4 FUN_008a9b04(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int *piVar6;
  void *pvVar7;
  int *piVar8;
  int *piVar9;
  undefined4 extraout_EAX;
  int *in_ECX;
  int iVar10;
  int *piVar11;
  float *pfVar12;
  float *pfVar13;
  undefined4 *puVar14;
  int *piVar15;
  uint uVar16;
  int *piVar17;
  int local_20;
  int *local_1c;
  int *local_18;
  void *local_10;
  int *local_c;
  int *local_8;
  
  local_1c = (int *)0x0;
  local_c = (int *)0x0;
  local_18 = (int *)0x0;
  if ((*(int *)(in_ECX[1] + 0x70) != 1) || (*(int *)(*in_ECX + 0x70) != 1)) {
    return 0x80004005;
  }
  uVar16 = in_ECX[2];
  piVar6 = (int *)FUN_008a68ce(*(undefined4 *)(*in_ECX + 0x68),*(undefined4 *)(in_ECX[1] + 0x68),
                               ~(uVar16 >> 0x10) & 1);
  if ((piVar6 != (int *)0x0) &&
     (local_1c = (int *)FUN_008a68ce(*(undefined4 *)(*in_ECX + 0x6c),
                                     *(undefined4 *)(in_ECX[1] + 0x6c),~(uVar16 >> 0x11) & 1),
     local_1c != (int *)0x0)) {
    iVar3 = *piVar6;
    iVar4 = *local_1c;
    iVar10 = *(int *)(in_ECX[1] + 0x6c);
    local_c = operator_new(iVar10 * 0xc + 4);
    if (local_c == (int *)0x0) {
      local_c = (int *)0x0;
    }
    else {
      *local_c = iVar10;
      local_c = local_c + 1;
      FUN_0040d030(local_c,0xc,iVar10,FUN_008a68b8);
    }
    if (local_c != (int *)0x0) {
      iVar10 = *(int *)(*in_ECX + 0x68);
      local_10 = operator_new(iVar10 << 4);
      if (local_10 == (void *)0x0) {
        local_10 = (void *)0x0;
      }
      else {
        FUN_0040d030(local_10,0x10,iVar10,FUN_0079e14e);
      }
      if (local_10 != (void *)0x0) {
        piVar17 = local_1c + 1;
        while (piVar17 < (int *)(iVar4 + (int)local_1c)) {
          piVar11 = (int *)(*piVar17 + (int)piVar17);
          for (piVar8 = piVar17 + 1; piVar17 = piVar11, piVar8 < piVar11; piVar8 = piVar8 + 2) {
            local_c[*piVar8 * 3 + 2] = local_c[*piVar8 * 3 + 2] + 1;
          }
        }
        local_20 = 0;
        piVar17 = local_1c + 1;
        while (piVar17 < (int *)(iVar4 + (int)local_1c)) {
          piVar11 = (int *)(*piVar17 + (int)piVar17);
          piVar17 = piVar17 + 1;
          for (piVar8 = piVar17; piVar8 < piVar11; piVar8 = piVar8 + 2) {
            piVar15 = local_c + *piVar8 * 3;
            if (*piVar15 == 0) {
              if (local_18 == (int *)0x0) {
                iVar10 = *(int *)(in_ECX[1] + 0x68);
                pvVar7 = operator_new(iVar10 << 4);
                if (pvVar7 == (void *)0x0) {
                  pvVar7 = (void *)0x0;
                }
                else {
                  FUN_0040d030(pvVar7,0x10,iVar10,FUN_0079e14e);
                }
                *piVar15 = (int)pvVar7;
                if (pvVar7 == (void *)0x0) goto LAB_008aa086;
              }
              else {
                *piVar15 = *local_18;
                *local_18 = 0;
                local_18 = (int *)local_18[1];
              }
              puVar14 = (undefined4 *)*piVar15;
              for (iVar10 = (*(uint *)(in_ECX[1] + 0x68) & 0xfffffff) << 2; iVar10 != 0;
                  iVar10 = iVar10 + -1) {
                *puVar14 = 0;
                puVar14 = puVar14 + 1;
              }
              for (iVar10 = 0; iVar10 != 0; iVar10 = iVar10 + -1) {
                *(undefined1 *)puVar14 = 0;
                puVar14 = (undefined4 *)((int)puVar14 + 1);
              }
            }
          }
          (**(code **)(*(int *)*in_ECX + 4))(local_20,0,local_10);
          if (piVar6 + 1 < (int *)(iVar3 + (int)piVar6)) {
            pfVar12 = (float *)((int)local_10 + 8);
            piVar8 = piVar6 + 1;
            do {
              piVar15 = (int *)(*piVar8 + (int)piVar8);
              if (piVar17 < piVar11) {
                local_8 = piVar17;
                do {
                  iVar10 = local_c[*local_8 * 3];
                  for (piVar9 = piVar8 + 1; piVar9 < piVar15; piVar9 = piVar9 + 2) {
                    fVar5 = (float)piVar9[1] * (float)local_8[1];
                    pfVar13 = (float *)(*piVar9 * 0x10 + iVar10);
                    *pfVar13 = fVar5 * pfVar12[-2] + *pfVar13;
                    pfVar13 = (float *)(*piVar9 * 0x10 + 4 + iVar10);
                    *pfVar13 = fVar5 * pfVar12[-1] + *pfVar13;
                    pfVar13 = (float *)(*piVar9 * 0x10 + 8 + iVar10);
                    *pfVar13 = fVar5 * *pfVar12 + *pfVar13;
                    pfVar13 = (float *)(*piVar9 * 0x10 + 0xc + iVar10);
                    *pfVar13 = fVar5 * pfVar12[1] + *pfVar13;
                  }
                  local_8 = local_8 + 2;
                } while (local_8 < piVar11);
              }
              pfVar12 = pfVar12 + 4;
              piVar8 = piVar15;
            } while (piVar15 < (int *)(iVar3 + (int)piVar6));
          }
          for (; piVar17 < piVar11; piVar17 = piVar17 + 2) {
            piVar15 = local_c + *piVar17 * 3;
            piVar8 = piVar15 + 2;
            *piVar8 = *piVar8 + -1;
            fVar2 = DAT_0099d0dc;
            fVar5 = DAT_0099d080;
            if (*piVar8 == 0) {
              iVar10 = *(int *)(*in_ECX + 8);
              if (iVar10 == 1) {
                iVar10 = 0;
                uVar16 = 0;
                if (*(int *)(in_ECX[1] + 0x68) != 0) {
                  do {
                    pfVar12 = (float *)(*piVar15 + iVar10);
                    if (0.0 <= *pfVar12) {
                      if (fVar5 <= *pfVar12) {
                        fVar2 = 1.0;
                      }
                      else {
                        fVar2 = *pfVar12;
                      }
                    }
                    else {
                      fVar2 = 0.0;
                    }
                    *pfVar12 = fVar2;
                    pfVar12 = (float *)(*piVar15 + 4 + iVar10);
                    if (0.0 <= *pfVar12) {
                      if (fVar5 <= *pfVar12) {
                        fVar2 = 1.0;
                      }
                      else {
                        fVar2 = *pfVar12;
                      }
                    }
                    else {
                      fVar2 = 0.0;
                    }
                    *pfVar12 = fVar2;
                    pfVar12 = (float *)(*piVar15 + 8 + iVar10);
                    if (0.0 <= *pfVar12) {
                      if (fVar5 <= *pfVar12) {
                        fVar2 = 1.0;
                      }
                      else {
                        fVar2 = *pfVar12;
                      }
                    }
                    else {
                      fVar2 = 0.0;
                    }
                    *pfVar12 = fVar2;
                    pfVar12 = (float *)(*piVar15 + 0xc + iVar10);
                    if (0.0 <= *pfVar12) {
                      if (fVar5 <= *pfVar12) {
                        fVar2 = 1.0;
                      }
                      else {
                        fVar2 = *pfVar12;
                      }
                    }
                    else {
                      fVar2 = 0.0;
                    }
                    *pfVar12 = fVar2;
                    uVar16 = uVar16 + 1;
                    iVar10 = iVar10 + 0x10;
                  } while (uVar16 < *(uint *)(in_ECX[1] + 0x68));
                }
              }
              else if (iVar10 == 2) {
                iVar10 = 0;
                uVar16 = 0;
                if (*(int *)(in_ECX[1] + 0x68) != 0) {
                  do {
                    pfVar12 = (float *)(*piVar15 + iVar10);
                    if (fVar2 <= *pfVar12) {
                      if (fVar5 <= *pfVar12) {
                        fVar1 = 1.0;
                      }
                      else {
                        fVar1 = *pfVar12;
                      }
                    }
                    else {
                      fVar1 = fVar2;
                    }
                    *pfVar12 = fVar1;
                    pfVar12 = (float *)(*piVar15 + 4 + iVar10);
                    if (fVar2 <= *pfVar12) {
                      if (fVar5 <= *pfVar12) {
                        fVar1 = 1.0;
                      }
                      else {
                        fVar1 = *pfVar12;
                      }
                    }
                    else {
                      fVar1 = fVar2;
                    }
                    *pfVar12 = fVar1;
                    pfVar12 = (float *)(*piVar15 + 8 + iVar10);
                    if (fVar2 <= *pfVar12) {
                      if (fVar5 <= *pfVar12) {
                        fVar1 = 1.0;
                      }
                      else {
                        fVar1 = *pfVar12;
                      }
                    }
                    else {
                      fVar1 = fVar2;
                    }
                    *pfVar12 = fVar1;
                    pfVar12 = (float *)(*piVar15 + 0xc + iVar10);
                    if (0.0 <= *pfVar12) {
                      if (fVar5 <= *pfVar12) {
                        fVar1 = 1.0;
                      }
                      else {
                        fVar1 = *pfVar12;
                      }
                    }
                    else {
                      fVar1 = 0.0;
                    }
                    *pfVar12 = fVar1;
                    uVar16 = uVar16 + 1;
                    iVar10 = iVar10 + 0x10;
                  } while (uVar16 < *(uint *)(in_ECX[1] + 0x68));
                }
              }
              else if (iVar10 == 3) {
                iVar10 = 0;
                uVar16 = 0;
                if (*(int *)(in_ECX[1] + 0x68) != 0) {
                  do {
                    pfVar12 = (float *)(*piVar15 + iVar10);
                    if (fVar2 <= *pfVar12) {
                      if (fVar5 <= *pfVar12) {
                        fVar1 = 1.0;
                      }
                      else {
                        fVar1 = *pfVar12;
                      }
                    }
                    else {
                      fVar1 = fVar2;
                    }
                    *pfVar12 = fVar1;
                    pfVar12 = (float *)(*piVar15 + 4 + iVar10);
                    if (fVar2 <= *pfVar12) {
                      if (fVar5 <= *pfVar12) {
                        fVar1 = 1.0;
                      }
                      else {
                        fVar1 = *pfVar12;
                      }
                    }
                    else {
                      fVar1 = fVar2;
                    }
                    *pfVar12 = fVar1;
                    pfVar12 = (float *)(*piVar15 + 8 + iVar10);
                    if (fVar2 <= *pfVar12) {
                      if (fVar5 <= *pfVar12) {
                        fVar1 = 1.0;
                      }
                      else {
                        fVar1 = *pfVar12;
                      }
                    }
                    else {
                      fVar1 = fVar2;
                    }
                    *pfVar12 = fVar1;
                    pfVar12 = (float *)(*piVar15 + 0xc + iVar10);
                    if (fVar2 <= *pfVar12) {
                      if (fVar5 <= *pfVar12) {
                        fVar1 = 1.0;
                      }
                      else {
                        fVar1 = *pfVar12;
                      }
                    }
                    else {
                      fVar1 = fVar2;
                    }
                    *pfVar12 = fVar1;
                    uVar16 = uVar16 + 1;
                    iVar10 = iVar10 + 0x10;
                  } while (uVar16 < *(uint *)(in_ECX[1] + 0x68));
                }
              }
              (**(code **)(*(int *)in_ECX[1] + 8))(*piVar17,0,*piVar15);
              piVar15[1] = (int)local_18;
              local_18 = piVar15;
            }
          }
          local_20 = local_20 + 1;
          piVar17 = piVar11;
        }
      }
    }
  }
LAB_008aa086:
  if (local_c != (int *)0x0) {
    FUN_008a942f(3);
  }
  _free(local_1c);
  return extraout_EAX;
}


// ==== FUN_008aa0c4 @ 0x008aa0c4 ====

int FUN_008aa0c4(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int *in_ECX;
  
  in_ECX[1] = 0;
  *in_ECX = 0;
  in_ECX[2] = param_3;
  if ((((param_3 & 0xffff) == 0) || (5 < (param_3 & 0xffff))) || ((param_3 & 0xff800000) != 0)) {
    return -0x7789f794;
  }
  *(uint *)(param_2 + 0x48) = param_3 & 0x200000;
  *(uint *)(param_1 + 0x48) = param_3 & 0x400000;
  *(uint *)(param_1 + 0x40) = param_3 & 0x80000;
  *(uint *)(param_1 + 0x44) = param_3 & 0x100000;
  iVar1 = FUN_008b521e(param_1);
  in_ECX[1] = iVar1;
  if (iVar1 != 0) {
    iVar1 = FUN_008b521e(param_2);
    *in_ECX = iVar1;
    if (iVar1 != 0) {
      iVar1 = FUN_008abed9(iVar1);
      if (iVar1 < 0) goto LAB_008aa1d2;
      iVar1 = FUN_008a7b89();
      if ((((-1 < iVar1) || (iVar1 = FUN_008a7c93(), -1 < iVar1)) ||
          ((iVar1 = FUN_008a7d66(), -1 < iVar1 ||
           ((iVar1 = FUN_008a7f39(), -1 < iVar1 || (iVar1 = FUN_008a810f(), -1 < iVar1)))))) ||
         ((iVar1 = FUN_008a84d7(), -1 < iVar1 ||
          ((((iVar1 = FUN_008a89cb(), -1 < iVar1 || (iVar1 = FUN_008a8d6d(), -1 < iVar1)) ||
            (iVar1 = FUN_008a9b04(), -1 < iVar1)) || (iVar1 = FUN_008a947e(), -1 < iVar1)))))) {
        iVar1 = 0;
        goto LAB_008aa1d2;
      }
    }
  }
  iVar1 = -0x7fffbffb;
LAB_008aa1d2:
  if ((undefined4 *)in_ECX[1] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)in_ECX[1])(1);
    in_ECX[1] = 0;
  }
  if ((undefined4 *)*in_ECX != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)*in_ECX)(1);
    *in_ECX = 0;
  }
  return iVar1;
}


// ==== FUN_008aa201 @ 0x008aa201 ====

void FUN_008aa201(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  in_ECX[4] = 0;
  return;
}


// ==== FUN_008aa214 @ 0x008aa214 ====

int FUN_008aa214(int *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int local_3c [7];
  uint local_20;
  uint local_1c;
  undefined4 *local_18;
  uint local_14;
  undefined4 *local_10;
  uint local_c;
  uint local_8;
  
  (**(code **)(*param_1 + 0x30))(param_1,local_3c);
  iVar1 = (**(code **)(*param_1 + 0x34))(param_1,&local_14,0,0);
  if (-1 < iVar1) {
    iVar1 = (**(code **)(*param_2 + 0x34))(param_2,&local_1c,0,0);
    if (-1 < iVar1) {
      if ((((local_3c[0] == 0x31545844) || (local_3c[0] == 0x32545844)) ||
          (local_3c[0] == 0x33545844)) ||
         ((local_3c[0] == 0x34545844 || (local_3c[0] == 0x35545844)))) {
        local_20 = local_20 + 3 >> 2;
      }
      local_c = local_1c;
      if ((int)local_14 <= (int)local_1c) {
        local_c = local_14;
      }
      local_8 = 0;
      if (local_20 != 0) {
        do {
          puVar3 = local_10;
          puVar4 = local_18;
          for (uVar2 = local_c >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
            *puVar4 = *puVar3;
            puVar3 = puVar3 + 1;
            puVar4 = puVar4 + 1;
          }
          for (uVar2 = local_c & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
            *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
            puVar3 = (undefined4 *)((int)puVar3 + 1);
            puVar4 = (undefined4 *)((int)puVar4 + 1);
          }
          local_10 = (undefined4 *)((int)local_10 + local_14);
          local_18 = (undefined4 *)((int)local_18 + local_1c);
          local_8 = local_8 + 1;
        } while (local_8 < local_20);
      }
      iVar1 = 0;
      (**(code **)(*param_2 + 0x38))(param_2);
    }
    (**(code **)(*param_1 + 0x38))(param_1);
  }
  return iVar1;
}


// ==== FUN_008aa2f3 @ 0x008aa2f3 ====

undefined4 FUN_008aa2f3(void)

{
  int *piVar1;
  int iVar2;
  byte *in_ECX;
  
  piVar1 = *(int **)(in_ECX + 8);
  if ((piVar1 != (int *)0x0) || (piVar1 = *(int **)(in_ECX + 4), piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 0x38))(piVar1);
  }
  if ((((*(int *)(in_ECX + 4) != 0) && (*(int *)(in_ECX + 8) != 0)) &&
      (*(int *)(in_ECX + 0x10) != 0)) && ((*in_ECX & 1) == 0)) {
    FUN_007a41ff(1);
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x10) + 0x78))
                      (*(int **)(in_ECX + 0x10),*(undefined4 *)(in_ECX + 8),0,
                       *(undefined4 *)(in_ECX + 4),0);
    FUN_007a41ff(0);
    if (iVar2 < 0) {
      FUN_007a41ff(1);
      FUN_008aa214(*(undefined4 *)(in_ECX + 8),*(undefined4 *)(in_ECX + 4));
      FUN_007a41ff(0);
    }
  }
  piVar1 = *(int **)(in_ECX + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[8] = 0;
    in_ECX[9] = 0;
    in_ECX[10] = 0;
    in_ECX[0xb] = 0;
  }
  piVar1 = *(int **)(in_ECX + 0xc);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0xc] = 0;
    in_ECX[0xd] = 0;
    in_ECX[0xe] = 0;
    in_ECX[0xf] = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x10);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[0x10] = 0;
    in_ECX[0x11] = 0;
    in_ECX[0x12] = 0;
    in_ECX[0x13] = 0;
  }
  piVar1 = *(int **)(in_ECX + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    in_ECX[4] = 0;
    in_ECX[5] = 0;
    in_ECX[6] = 0;
    in_ECX[7] = 0;
  }
  return 0;
}


// ==== FUN_008aa3a6 @ 0x008aa3a6 ====

void FUN_008aa3a6(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = 0;
  return;
}


// ==== FUN_008aa3ac @ 0x008aa3ac ====

undefined4 FUN_008aa3ac(void)

{
  int *piVar1;
  int *in_ECX;
  
  piVar1 = (int *)*in_ECX;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x28))(piVar1);
    piVar1 = (int *)*in_ECX;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *in_ECX = 0;
    }
  }
  return 0;
}


// ==== FUN_008aa3d5 @ 0x008aa3d5 ====

int FUN_008aa3d5(undefined4 *param_1,int *param_2,undefined4 param_3,uint *param_4,
                undefined4 param_5,uint param_6)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  int local_74 [2];
  byte local_6b;
  int local_68;
  uint local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  undefined4 local_34;
  undefined4 local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  int *local_20;
  uint local_1c;
  uint *local_18;
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_008aa2f3();
  (**(code **)(*param_2 + 0x30))(param_2,local_74);
  puVar5 = local_18;
  if (param_4 == (uint *)0x0) {
    local_3c = local_5c;
    local_38 = local_58;
    local_44 = 0;
    local_40 = 0;
    local_8 = 0;
    local_1c = ~param_6 & 1;
  }
  else {
    local_44 = *param_4;
    local_40 = param_4[1];
    local_3c = param_4[2];
    local_38 = param_4[3];
    if (((((int)local_44 < 0) || (local_5c < local_3c)) || ((int)local_3c < (int)local_44)) ||
       ((((int)local_40 < 0 || (local_58 < local_38)) || ((int)local_38 < (int)local_40)))) {
      return -0x7789f794;
    }
    local_1c = 1;
    if (((local_44 != 0) || (local_3c != local_5c)) ||
       ((local_40 != 0 || (local_8 = 0, local_38 != local_58)))) {
      local_8 = 1;
    }
    if (((param_6 & 1) != 0) || (local_8 != 0)) {
      local_1c = 0;
    }
  }
  local_2c = param_6 & 0x10000;
  if (local_2c != 0) {
    local_28 = local_5c;
    local_24 = local_58;
    local_10 = 0;
    if ((((local_74[0] == 0x31545844) || (local_74[0] == 0x32545844)) || (local_74[0] == 0x33545844)
        ) || ((local_74[0] == 0x34545844 || (local_74[0] == 0x35545844)))) {
      uVar4 = local_58 | local_5c;
      while ((uVar4 & 3) != 0) {
        local_10 = local_10 + 1;
        uVar4 = (local_58 | local_5c) << ((byte)local_10 & 0x1f);
      }
    }
    puVar1 = local_18 + 4;
    (**(code **)(*param_2 + 0xc))(param_2,puVar1);
    puVar5 = puVar5 + 3;
    local_c = (**(code **)(*(int *)*puVar1 + 0x5c))
                        ((int *)*puVar1,local_28 << ((byte)local_10 & 0x1f),
                         local_24 << ((byte)local_10 & 0x1f),local_10 + 1,0,local_74[0],
                         (local_68 == 3) + '\x02',puVar5,0);
    if (-1 < local_c) {
      puVar6 = local_18 + 2;
      local_c = (**(code **)(*(int *)*puVar5 + 0x48))((int *)*puVar5,local_10,puVar6);
      if (-1 < local_c) {
        if (local_1c == 0) {
          local_14 = (int *)0x0;
          FUN_007a41ff(1);
          local_c = FUN_008aa214(param_2,*puVar6);
          FUN_007a41ff(0);
          if (local_c < 0) {
            if ((local_10 == 0) &&
               (local_c = (**(code **)(*(int *)*puVar1 + 0x70))
                                    ((int *)*puVar1,local_28,local_24,local_74[0],0,0,1,&local_14,0)
               , -1 < local_c)) {
              local_c = (**(code **)(*(int *)*puVar1 + 0x88))((int *)*puVar1,param_2,0,local_14,0,0)
              ;
              if (local_c < 0) {
                (**(code **)(*local_14 + 8))(local_14);
              }
              else {
                local_c = FUN_008aa214(local_14,*puVar6);
                (**(code **)(*local_14 + 8))(local_14);
                if (-1 < local_c) goto LAB_008aa61d;
              }
            }
            piVar2 = (int *)*puVar6;
            if (piVar2 != (int *)0x0) {
              (**(code **)(*piVar2 + 8))(piVar2);
              *puVar6 = 0;
            }
            goto LAB_008aa5f7;
          }
        }
LAB_008aa61d:
        local_14 = (int *)*puVar6;
        goto LAB_008aa63d;
      }
    }
    piVar2 = (int *)local_18[2];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      local_18[2] = 0;
    }
LAB_008aa5f7:
    piVar2 = (int *)*puVar5;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *puVar5 = 0;
    }
    piVar2 = (int *)*puVar1;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *puVar1 = 0;
    }
    return local_c;
  }
  local_14 = param_2;
LAB_008aa63d:
  uVar4 = (param_6 & 1 | 0x80) << 4;
  if (((local_1c == 0) || (local_2c != 0)) || ((local_6b & 2) == 0)) {
LAB_008aa6c0:
    if (local_8 != 0) {
      if (local_74[0] < 0x34545845) {
        if (((local_74[0] != 0x34545844) && (local_74[0] != 0x31545844)) &&
           (local_74[0] != 0x32545844)) {
          if (local_74[0] == 0x32595559) goto LAB_008aa777;
          if (local_74[0] != 0x33545844) goto LAB_008aa76b;
        }
LAB_008aa6f8:
        local_4c = local_3c + 3 & 0xfffffffc;
        local_54 = local_44 & 0xfffffffc;
        local_50 = local_40 & 0xfffffffc;
        local_48 = local_38 + 3 & 0xfffffffc;
        if (local_5c < local_4c) {
          local_4c = local_5c;
        }
        if (local_58 < local_48) {
          local_48 = local_58;
        }
      }
      else {
        if (local_74[0] == 0x35545844) goto LAB_008aa6f8;
        if (((local_74[0] != 0x42475247) && (local_74[0] != 0x47424752)) &&
           (local_74[0] != 0x59565955)) {
LAB_008aa76b:
          local_54 = local_44;
          local_50 = local_40;
          local_4c = local_3c;
          local_48 = local_38;
          goto LAB_008aa7ba;
        }
LAB_008aa777:
        local_54 = local_44 & 0xfffffffe;
        local_4c = local_3c + 1 & 0xfffffffe;
        local_50 = local_40;
        local_48 = local_38;
        if (local_5c < local_4c) {
          local_4c = local_5c;
        }
      }
      if ((((local_54 == 0) && (local_4c == local_5c)) && (local_50 == 0)) && (local_48 == local_58)
         ) {
        local_8 = 0;
      }
      else {
        local_8 = 1;
      }
    }
LAB_008aa7ba:
    if (local_2c != 0) {
      iVar3 = (**(code **)(*local_14 + 0x34))
                        (local_14,&local_34,-(uint)(local_8 != 0) & (uint)&local_54,uVar4);
      if (iVar3 < 0) {
        return iVar3;
      }
      goto LAB_008aa837;
    }
  }
  else {
    if ((param_6 & 0x20000) == 0) {
      FUN_007a41ff(1);
      iVar3 = (**(code **)(*param_2 + 0x2c))(param_2,&DAT_00a24fdc,&local_20);
      if (-1 < iVar3) {
        iVar3 = (**(code **)(*local_20 + 0x34))(local_20);
        if (iVar3 == 1) {
          uVar4 = uVar4 | 0x2000;
          local_8 = 0;
        }
        if (local_20 != (int *)0x0) {
          (**(code **)(*local_20 + 8))(local_20);
          local_20 = (int *)0x0;
        }
      }
      FUN_007a41ff(0);
      goto LAB_008aa6c0;
    }
    uVar4 = uVar4 | 0x2000;
    local_8 = 0;
  }
  FUN_007a41ff(1);
  iVar3 = (**(code **)(*local_14 + 0x34))
                    (local_14,&local_34,-(uint)(local_8 != 0) & (uint)&local_54,uVar4);
  FUN_007a41ff(0);
  if (iVar3 < 0) {
    iVar3 = FUN_008aa3d5(param_1,param_2,param_3,param_4,param_5,param_6 | 0x10000);
    return iVar3;
  }
LAB_008aa837:
  if (local_8 != 0) {
    local_44 = local_44 - local_54;
    local_3c = local_3c - local_54;
    local_40 = local_40 - local_50;
    local_38 = local_38 - local_50;
  }
  *param_1 = local_30;
  param_1[1] = local_74[0];
  param_1[2] = local_34;
  param_1[6] = local_5c;
  param_1[7] = local_58;
  param_1[10] = local_44;
  param_1[9] = 1;
  param_1[0xb] = local_40;
  param_1[0xf] = 1;
  param_1[0x10] = 1;
  param_1[0x13] = param_5;
  param_1[0xc] = local_3c;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[0xe] = 0;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x14] = param_3;
  param_1[0xd] = local_38;
  local_18[1] = (uint)param_2;
  *local_18 = param_6;
  (**(code **)(*param_2 + 4))(param_2);
  return 0;
}


// ==== FUN_008aa8c9 @ 0x008aa8c9 ====

int FUN_008aa8c9(undefined4 *param_1,int *param_2,undefined4 param_3,uint *param_4,
                undefined4 param_5,uint param_6)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  int *in_ECX;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  int local_68 [2];
  uint local_60;
  int local_5c;
  uint local_58;
  uint local_54;
  uint local_50;
  uint local_4c [4];
  uint local_3c;
  uint local_38;
  uint local_34 [4];
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int *local_10;
  uint local_c;
  int *local_8;
  
  local_10 = in_ECX;
  if (*in_ECX != 0) {
    FUN_008aa3ac();
  }
  (**(code **)(*param_2 + 0x20))(param_2,local_68);
  if (param_4 == (uint *)0x0) {
    bVar1 = false;
    local_34[2] = local_58;
    local_34[3] = local_54;
    uVar3 = ~param_6 & 1;
    local_34[0] = 0;
    local_34[1] = 0;
    local_24 = 0;
    local_20 = local_50;
  }
  else {
    puVar6 = local_34;
    for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *param_4;
      param_4 = param_4 + 1;
      puVar6 = puVar6 + 1;
    }
    if (local_58 < local_34[2]) {
      return -0x7789f794;
    }
    if (local_34[2] < local_34[0]) {
      return -0x7789f794;
    }
    if (local_54 < local_34[3]) {
      return -0x7789f794;
    }
    if (local_34[3] < local_34[1]) {
      return -0x7789f794;
    }
    if (local_50 < local_20) {
      return -0x7789f794;
    }
    if (local_20 < local_24) {
      return -0x7789f794;
    }
    if (((((local_34[0] != 0) || (local_34[2] != local_58)) || (local_34[1] != 0)) ||
        ((local_34[3] != local_54 || (local_24 != 0)))) || (bVar1 = false, local_20 != local_50)) {
      bVar1 = true;
    }
    if (((param_6 & 1) != 0) || (bVar1)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
  }
  uVar2 = local_20;
  if ((local_5c == 0) && ((local_60 & 0x200) == 0)) {
    return -0x7789f794;
  }
  uVar5 = (param_6 & 1 | 0x80) << 4;
  local_c = uVar5;
  if ((uVar3 == 0) || ((local_60 & 0x200) == 0)) {
LAB_008aaa31:
    if (bVar1) {
      if (local_68[0] < 0x34545845) {
        if (((local_68[0] == 0x34545844) || (local_68[0] == 0x31545844)) ||
           (local_68[0] == 0x32545844)) {
LAB_008aaa74:
          local_4c[0] = local_34[0] & 0xfffffffc;
          local_4c[2] = local_34[2] + 3 & 0xfffffffc;
          local_4c[1] = local_34[1] & 0xfffffffc;
          local_4c[3] = local_34[3] + 3 & 0xfffffffc;
          local_3c = local_24;
          if (local_58 < local_4c[2]) {
            local_4c[2] = local_58;
          }
          if (local_54 < local_4c[3]) {
            local_4c[3] = local_54;
          }
          local_38 = uVar2;
          if (((local_4c[0] == 0) && (local_4c[2] == local_58)) &&
             ((local_4c[1] == 0 &&
              (((local_4c[3] == local_54 && (local_24 == 0)) && (uVar2 == local_50)))))) {
            uVar5 = local_c;
            goto LAB_008aaaeb;
          }
          goto LAB_008aaade;
        }
        if (local_68[0] != 0x32595559) {
          if (local_68[0] != 0x33545844) goto LAB_008aab2c;
          goto LAB_008aaa74;
        }
LAB_008aab39:
        local_4c[0] = local_34[0] & 0xfffffffe;
        local_4c[2] = local_34[2] + 1 & 0xfffffffe;
        local_4c[3] = local_34[3];
        local_4c[1] = local_34[1];
        local_3c = local_24;
        if (local_58 < local_4c[2]) {
          local_4c[2] = local_58;
        }
        local_38 = uVar2;
        if (((local_4c[0] == 0) && (local_4c[2] == local_58)) &&
           (((local_34[1] == 0 && ((local_34[3] == local_54 && (local_24 == 0)))) &&
            (uVar2 == local_50)))) goto LAB_008aaaeb;
      }
      else {
        if (local_68[0] == 0x35545844) goto LAB_008aaa74;
        if (((local_68[0] == 0x42475247) || (local_68[0] == 0x47424752)) ||
           (local_68[0] == 0x59565955)) goto LAB_008aab39;
LAB_008aab2c:
        puVar6 = local_34;
        puVar7 = local_4c;
        for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
          *puVar7 = *puVar6;
          puVar6 = puVar6 + 1;
          puVar7 = puVar7 + 1;
        }
LAB_008aaade:
        uVar5 = local_c;
      }
      iVar4 = (**(code **)(*param_2 + 0x24))(param_2,&local_1c,local_4c,uVar5);
      if (iVar4 < 0) {
        return iVar4;
      }
      local_34[0] = local_34[0] - local_4c[0];
      local_34[2] = local_34[2] - local_4c[0];
      local_34[1] = local_34[1] - local_4c[1];
      local_34[3] = local_34[3] - local_4c[1];
      local_24 = local_24 - local_3c;
      local_20 = uVar2 - local_3c;
      goto LAB_008aabca;
    }
  }
  else {
    if ((param_6 & 0x20000) == 0) {
      FUN_007a41ff(1);
      iVar4 = (**(code **)(*param_2 + 0x1c))(param_2,&DAT_00a24fcc,&local_8);
      if (-1 < iVar4) {
        iVar4 = (**(code **)(*local_8 + 0x34))(local_8);
        if (iVar4 == 1) {
          uVar5 = uVar5 | 0x2000;
          bVar1 = false;
          local_c = uVar5;
        }
        if (local_8 != (int *)0x0) {
          (**(code **)(*local_8 + 8))(local_8);
          local_8 = (int *)0x0;
        }
      }
      FUN_007a41ff(0);
      goto LAB_008aaa31;
    }
    uVar5 = uVar5 | 0x2000;
  }
LAB_008aaaeb:
  iVar4 = (**(code **)(*param_2 + 0x24))(param_2,&local_1c,0,uVar5);
  if (iVar4 < 0) {
    return iVar4;
  }
LAB_008aabca:
  *param_1 = local_14;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[1] = local_68[0];
  param_1[2] = local_1c;
  param_1[3] = local_18;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[9] = local_50;
  puVar6 = local_34;
  puVar7 = param_1 + 10;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar7 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar7 = puVar7 + 1;
  }
  param_1[0x13] = param_5;
  param_1[6] = local_58;
  param_1[0x14] = param_3;
  param_1[7] = local_54;
  param_1[0x10] = 1;
  *local_10 = (int)param_2;
  (**(code **)(*param_2 + 4))(param_2);
  return 0;
}


// ==== FUN_008aac3e @ 0x008aac3e ====

void FUN_008aac3e(void)

{
  undefined4 *in_ECX;
  
  *in_ECX = &PTR_FUN_00a17150;
  _free((void *)in_ECX[0xe]);
  return;
}


// ==== FUN_008aac66 @ 0x008aac66 ====

void FUN_008aac66(void)

{
  return;
}


// ==== FUN_008aac69 @ 0x008aac69 ====

undefined4 FUN_008aac69(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined4 *puVar5;
  float *pfVar6;
  int in_ECX;
  int iVar7;
  uint uVar8;
  
  fVar4 = DAT_0099d0f8;
  fVar3 = DAT_0099d0dc;
  fVar1 = DAT_0099d0b4;
  fVar2 = DAT_0099d080;
  iVar7 = *(int *)(in_ECX + 8);
  if (iVar7 == 1) {
    iVar7 = *(int *)(in_ECX + 0x54);
    if (iVar7 == 2) {
      uVar8 = 0;
      if (*(int *)(in_ECX + 0x68) != 0) {
        pfVar6 = (float *)(param_1 + 8);
        iVar7 = 0;
        do {
          uVar8 = uVar8 + 1;
          *(float *)(iVar7 + *(int *)(in_ECX + 0x58)) = (pfVar6[-2] + fVar2) * fVar1;
          *(float *)(iVar7 + 4 + *(int *)(in_ECX + 0x58)) = (pfVar6[-1] + fVar2) * fVar1;
          *(float *)(iVar7 + 8 + *(int *)(in_ECX + 0x58)) = (*pfVar6 + fVar2) * fVar1;
          *(float *)(iVar7 + 0xc + *(int *)(in_ECX + 0x58)) = pfVar6[1];
          pfVar6 = pfVar6 + 4;
          iVar7 = iVar7 + 0x10;
        } while (uVar8 < *(uint *)(in_ECX + 0x68));
      }
    }
    else if (iVar7 == 3) {
      uVar8 = 0;
      if (*(int *)(in_ECX + 0x68) != 0) {
        pfVar6 = (float *)(param_1 + 8);
        iVar7 = 0;
        do {
          uVar8 = uVar8 + 1;
          *(float *)(iVar7 + *(int *)(in_ECX + 0x58)) = (pfVar6[-2] + fVar2) * fVar1;
          *(float *)(iVar7 + 4 + *(int *)(in_ECX + 0x58)) = (pfVar6[-1] + fVar2) * fVar1;
          *(float *)(iVar7 + 8 + *(int *)(in_ECX + 0x58)) = (*pfVar6 + fVar2) * fVar1;
          *(float *)(iVar7 + 0xc + *(int *)(in_ECX + 0x58)) = (pfVar6[1] + fVar2) * fVar1;
          pfVar6 = pfVar6 + 4;
          iVar7 = iVar7 + 0x10;
        } while (uVar8 < *(uint *)(in_ECX + 0x68));
      }
    }
    else if ((iVar7 == 4) && (uVar8 = 0, *(int *)(in_ECX + 0x68) != 0)) {
      pfVar6 = (float *)(param_1 + 8);
      param_1 = -param_1;
      do {
        if (0.0 <= pfVar6[-2]) {
          if (fVar2 <= pfVar6[-2]) {
            fVar1 = 1.0;
          }
          else {
            fVar1 = pfVar6[-2];
          }
        }
        else {
          fVar1 = 0.0;
        }
        *(float *)((int)pfVar6 + *(int *)(in_ECX + 0x58) + param_1 + -8) = fVar1;
        if (0.0 <= pfVar6[-1]) {
          if (fVar2 <= pfVar6[-1]) {
            fVar1 = 1.0;
          }
          else {
            fVar1 = pfVar6[-1];
          }
        }
        else {
          fVar1 = 0.0;
        }
        *(float *)((int)pfVar6 + *(int *)(in_ECX + 0x58) + param_1 + -4) = fVar1;
        if (0.0 <= *pfVar6) {
          if (fVar2 <= *pfVar6) {
            fVar1 = 1.0;
          }
          else {
            fVar1 = *pfVar6;
          }
        }
        else {
          fVar1 = 0.0;
        }
        *(float *)((int)pfVar6 + *(int *)(in_ECX + 0x58) + param_1) = fVar1;
        if (0.0 <= pfVar6[1]) {
          if (fVar2 <= pfVar6[1]) {
            fVar1 = 1.0;
          }
          else {
            fVar1 = pfVar6[1];
          }
        }
        else {
          fVar1 = 0.0;
        }
        uVar8 = uVar8 + 1;
        *(float *)((int)pfVar6 + *(int *)(in_ECX + 0x58) + param_1 + 4) = fVar1;
        pfVar6 = pfVar6 + 4;
      } while (uVar8 < *(uint *)(in_ECX + 0x68));
    }
  }
  else if (iVar7 == 2) {
    iVar7 = *(int *)(in_ECX + 0x54);
    if (iVar7 == 1) {
      uVar8 = 0;
      if (*(int *)(in_ECX + 0x68) != 0) {
        pfVar6 = (float *)(param_1 + 8);
        iVar7 = 0;
        do {
          uVar8 = uVar8 + 1;
          *(float *)(iVar7 + *(int *)(in_ECX + 0x58)) = pfVar6[-2] * fVar4 - fVar2;
          *(float *)(iVar7 + 4 + *(int *)(in_ECX + 0x58)) = pfVar6[-1] * fVar4 - fVar2;
          *(float *)(iVar7 + 8 + *(int *)(in_ECX + 0x58)) = *pfVar6 * fVar4 - fVar2;
          *(float *)(iVar7 + 0xc + *(int *)(in_ECX + 0x58)) = pfVar6[1];
          pfVar6 = pfVar6 + 4;
          iVar7 = iVar7 + 0x10;
        } while (uVar8 < *(uint *)(in_ECX + 0x68));
      }
    }
    else if (iVar7 == 3) {
      uVar8 = 0;
      if (*(int *)(in_ECX + 0x68) != 0) {
        puVar5 = (undefined4 *)(param_1 + 8);
        iVar7 = 0;
        do {
          *(undefined4 *)(iVar7 + *(int *)(in_ECX + 0x58)) = puVar5[-2];
          uVar8 = uVar8 + 1;
          *(undefined4 *)(iVar7 + 4 + *(int *)(in_ECX + 0x58)) = puVar5[-1];
          *(undefined4 *)(iVar7 + 8 + *(int *)(in_ECX + 0x58)) = *puVar5;
          pfVar6 = (float *)(puVar5 + 1);
          puVar5 = puVar5 + 4;
          *(float *)(iVar7 + 0xc + *(int *)(in_ECX + 0x58)) =
               (*pfVar6 + DAT_0099d080) * DAT_0099d0b4;
          iVar7 = iVar7 + 0x10;
        } while (uVar8 < *(uint *)(in_ECX + 0x68));
      }
    }
    else if ((iVar7 == 4) && (uVar8 = 0, *(int *)(in_ECX + 0x68) != 0)) {
      pfVar6 = (float *)(param_1 + 8);
      param_1 = -param_1;
      do {
        if (fVar3 <= pfVar6[-2]) {
          if (fVar2 <= pfVar6[-2]) {
            fVar1 = 1.0;
          }
          else {
            fVar1 = pfVar6[-2];
          }
        }
        else {
          fVar1 = fVar3;
        }
        *(float *)((int)pfVar6 + *(int *)(in_ECX + 0x58) + param_1 + -8) = fVar1;
        if (fVar3 <= pfVar6[-1]) {
          if (fVar2 <= pfVar6[-1]) {
            fVar1 = 1.0;
          }
          else {
            fVar1 = pfVar6[-1];
          }
        }
        else {
          fVar1 = fVar3;
        }
        *(float *)((int)pfVar6 + *(int *)(in_ECX + 0x58) + param_1 + -4) = fVar1;
        if (fVar3 <= *pfVar6) {
          if (fVar2 <= *pfVar6) {
            fVar1 = 1.0;
          }
          else {
            fVar1 = *pfVar6;
          }
        }
        else {
          fVar1 = fVar3;
        }
        *(float *)((int)pfVar6 + *(int *)(in_ECX + 0x58) + param_1) = fVar1;
        if (0.0 <= pfVar6[1]) {
          if (fVar2 <= pfVar6[1]) {
            fVar1 = 1.0;
          }
          else {
            fVar1 = pfVar6[1];
          }
        }
        else {
          fVar1 = 0.0;
        }
        uVar8 = uVar8 + 1;
        *(float *)((int)pfVar6 + *(int *)(in_ECX + 0x58) + param_1 + 4) = fVar1;
        pfVar6 = pfVar6 + 4;
      } while (uVar8 < *(uint *)(in_ECX + 0x68));
    }
  }
  else if (iVar7 == 3) {
    iVar7 = *(int *)(in_ECX + 0x54);
    if (iVar7 == 1) {
      uVar8 = 0;
      if (*(int *)(in_ECX + 0x68) != 0) {
        pfVar6 = (float *)(param_1 + 8);
        iVar7 = 0;
        do {
          uVar8 = uVar8 + 1;
          *(float *)(iVar7 + *(int *)(in_ECX + 0x58)) = pfVar6[-2] * fVar4 - fVar2;
          *(float *)(iVar7 + 4 + *(int *)(in_ECX + 0x58)) = pfVar6[-1] * fVar4 - fVar2;
          *(float *)(iVar7 + 8 + *(int *)(in_ECX + 0x58)) = *pfVar6 * fVar4 - fVar2;
          *(float *)(iVar7 + 0xc + *(int *)(in_ECX + 0x58)) = pfVar6[1] * fVar4 - fVar2;
          pfVar6 = pfVar6 + 4;
          iVar7 = iVar7 + 0x10;
        } while (uVar8 < *(uint *)(in_ECX + 0x68));
      }
    }
    else if (iVar7 == 2) {
      uVar8 = 0;
      if (*(int *)(in_ECX + 0x68) != 0) {
        puVar5 = (undefined4 *)(param_1 + 8);
        iVar7 = 0;
        do {
          *(undefined4 *)(iVar7 + *(int *)(in_ECX + 0x58)) = puVar5[-2];
          uVar8 = uVar8 + 1;
          *(undefined4 *)(iVar7 + 4 + *(int *)(in_ECX + 0x58)) = puVar5[-1];
          *(undefined4 *)(iVar7 + 8 + *(int *)(in_ECX + 0x58)) = *puVar5;
          pfVar6 = (float *)(puVar5 + 1);
          puVar5 = puVar5 + 4;
          *(float *)(iVar7 + 0xc + *(int *)(in_ECX + 0x58)) = (*pfVar6 + *pfVar6) - DAT_0099d080;
          iVar7 = iVar7 + 0x10;
        } while (uVar8 < *(uint *)(in_ECX + 0x68));
      }
    }
    else if ((iVar7 == 4) && (uVar8 = 0, *(int *)(in_ECX + 0x68) != 0)) {
      pfVar6 = (float *)(param_1 + 8);
      param_1 = -param_1;
      do {
        if (fVar3 <= pfVar6[-2]) {
          if (fVar2 <= pfVar6[-2]) {
            fVar1 = 1.0;
          }
          else {
            fVar1 = pfVar6[-2];
          }
        }
        else {
          fVar1 = fVar3;
        }
        *(float *)((int)pfVar6 + *(int *)(in_ECX + 0x58) + param_1 + -8) = fVar1;
        if (fVar3 <= pfVar6[-1]) {
          if (fVar2 <= pfVar6[-1]) {
            fVar1 = 1.0;
          }
          else {
            fVar1 = pfVar6[-1];
          }
        }
        else {
          fVar1 = fVar3;
        }
        *(float *)((int)pfVar6 + *(int *)(in_ECX + 0x58) + param_1 + -4) = fVar1;
        if (fVar3 <= *pfVar6) {
          if (fVar2 <= *pfVar6) {
            fVar1 = 1.0;
          }
          else {
            fVar1 = *pfVar6;
          }
        }
        else {
          fVar1 = fVar3;
        }
        *(float *)((int)pfVar6 + *(int *)(in_ECX + 0x58) + param_1) = fVar1;
        if (fVar3 <= pfVar6[1]) {
          if (fVar2 <= pfVar6[1]) {
            fVar1 = 1.0;
          }
          else {
            fVar1 = pfVar6[1];
          }
        }
        else {
          fVar1 = fVar3;
        }
        uVar8 = uVar8 + 1;
        *(float *)((int)pfVar6 + *(int *)(in_ECX + 0x58) + param_1 + 4) = fVar1;
        pfVar6 = pfVar6 + 4;
      } while (uVar8 < *(uint *)(in_ECX + 0x68));
    }
  }
  return *(undefined4 *)(in_ECX + 0x58);
}


// ==== FUN_008ab181 @ 0x008ab181 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_008ab181(void)

{
  float *pfVar1;
  float *pfVar2;
  int iVar3;
  int in_ECX;
  float *pfVar4;
  int iVar5;
  ushort *puVar6;
  undefined2 in_FPUControlWord;
  uint local_10;
  uint local_c;
  int local_8;
  
  if (*(int *)(in_ECX + 0xa0) == 0) {
    return 0;
  }
  if (*(int *)(in_ECX + 0xa4) == 0) {
    return 0;
  }
  pfVar4 = *(float **)(in_ECX + 0x80);
  puVar6 = (ushort *)
           (*(int *)(in_ECX + 0x94) * *(int *)(in_ECX + 100) +
            *(int *)(in_ECX + 0x88) * *(int *)(in_ECX + 0x60) + *(int *)(in_ECX + 0x84) * 2 +
           *(int *)(in_ECX + 0x20));
  local_10 = CONCAT22(local_10._2_2_,in_FPUControlWord);
  *(uint *)(in_ECX + 0x7c) = local_10;
  iVar3 = *(int *)(in_ECX + 4);
  if (iVar3 != 0x32595559) {
    if ((iVar3 == 0x42475247) || (iVar3 == 0x47424752)) {
      local_c = *(uint *)(in_ECX + 0x84);
      while (local_c < *(uint *)(in_ECX + 0x8c)) {
        *puVar6 = (ushort)((int)ROUND(pfVar4[1] * DAT_0099d0b8 + DAT_0099d0b4) <<
                          ((byte)*(undefined4 *)(in_ECX + 0xa8) & 0x1f)) |
                  (ushort)((int)ROUND(*pfVar4 * DAT_0099d0b8 + DAT_0099d0b4) <<
                          ((byte)*(undefined4 *)(in_ECX + 0xac) & 0x1f));
        pfVar1 = pfVar4 + 5;
        pfVar2 = pfVar4 + 2;
        pfVar4 = pfVar4 + 8;
        local_c = local_c + 2;
        puVar6[1] = (ushort)((int)ROUND(*pfVar1 * DAT_0099d0b8 + DAT_0099d0b4) <<
                            ((byte)*(undefined4 *)(in_ECX + 0xa8) & 0x1f)) |
                    (ushort)((int)ROUND(*pfVar2 * DAT_0099d0b8 + DAT_0099d0b4) <<
                            ((byte)*(undefined4 *)(in_ECX + 0xac) & 0x1f));
        puVar6 = puVar6 + 2;
      }
      goto LAB_008ab46d;
    }
    if (iVar3 != 0x59565955) goto LAB_008ab46d;
  }
  local_10 = *(uint *)(in_ECX + 0x84);
  while (local_10 < *(uint *)(in_ECX + 0x8c)) {
    iVar3 = (int)ROUND(pfVar4[2] * _DAT_00a17178 +
                       pfVar4[1] * _DAT_00a17174 + *pfVar4 * _DAT_00a1717c + DAT_0099d0b4) + 0x10;
    local_8 = (int)ROUND(pfVar4[5] * _DAT_00a17174 +
                         pfVar4[6] * _DAT_00a17178 + pfVar4[4] * _DAT_00a1717c + DAT_0099d0b4) +
              0x10;
    iVar5 = (int)ROUND(((pfVar4[2] * _DAT_00a17170 - pfVar4[1] * _DAT_00a1716c) -
                       *pfVar4 * _DAT_00a17168) + DAT_0099d0b4) + 0x80;
    local_c = (int)ROUND((*pfVar4 * _DAT_00a17170 -
                         (pfVar4[2] * _DAT_00a17160 + pfVar4[1] * _DAT_00a17164)) + DAT_0099d0b4) +
              0x80;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    else if (0xff < iVar3) {
      iVar3 = 0xff;
    }
    if (local_8 < 0) {
      local_8 = 0;
    }
    else if (0xff < local_8) {
      local_8 = 0xff;
    }
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    else if (0xff < iVar5) {
      iVar5 = 0xff;
    }
    if ((int)local_c < 0) {
      local_c = 0;
    }
    else if (0xff < (int)local_c) {
      local_c = 0xff;
    }
    pfVar4 = pfVar4 + 8;
    *puVar6 = (ushort)(iVar3 << ((byte)*(undefined4 *)(in_ECX + 0xa8) & 0x1f)) |
              (ushort)(iVar5 << ((byte)*(undefined4 *)(in_ECX + 0xac) & 0x1f));
    local_10 = local_10 + 2;
    puVar6[1] = (ushort)(local_8 << ((byte)*(undefined4 *)(in_ECX + 0xa8) & 0x1f)) |
                (ushort)(local_c << ((byte)*(undefined4 *)(in_ECX + 0xac) & 0x1f));
    puVar6 = puVar6 + 2;
  }
LAB_008ab46d:
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  return 0;
}


// ==== FUN_008ab484 @ 0x008ab484 ====

/* WARNING: Removing unreachable block (ram,0x008ab7d5) */
/* WARNING: Removing unreachable block (ram,0x008ab86b) */
/* WARNING: Removing unreachable block (ram,0x008ab9c3) */
/* WARNING: Removing unreachable block (ram,0x008ab913) */
/* WARNING: Removing unreachable block (ram,0x008ab73e) */
/* WARNING: Removing unreachable block (ram,0x008aba23) */
/* WARNING: Removing unreachable block (ram,0x008ab789) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int FUN_008ab484(uint param_1,float *param_2,uint param_3)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort uVar3;
  undefined2 uVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  byte bVar12;
  int iVar13;
  int in_ECX;
  uint uVar14;
  float *pfVar15;
  ushort *puVar16;
  
  if (*(int *)(in_ECX + 0xa4) == 0) {
    return -0x7ff8fff2;
  }
  if ((((param_1 < *(uint *)(in_ECX + 0x88)) || (*(uint *)(in_ECX + 0x90) <= param_1)) ||
      (param_2 < *(uint *)(in_ECX + 0x94))) || (*(uint *)(in_ECX + 0x98) <= param_2)) {
    iVar13 = FUN_008ab181();
    if (iVar13 < 0) {
      return iVar13;
    }
    *(uint *)(in_ECX + 0x90) = param_1 + 1;
    *(uint *)(in_ECX + 0x88) = param_1;
    *(float **)(in_ECX + 0x94) = param_2;
    *(uint *)(in_ECX + 0x98) = (int)param_2 + 1;
    fVar11 = DAT_009b2d78;
    fVar7 = DAT_0099d0b0;
    fVar10 = DAT_0099d080;
    fVar9 = DAT_0099cdc8;
    if (param_3 != 0) {
      param_3 = *(uint *)(in_ECX + 0x84);
      pfVar15 = *(float **)(in_ECX + 0x80);
      uVar14 = *(uint *)(in_ECX + 0x68);
      puVar16 = (ushort *)
                (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * (int)param_2 +
                 param_3 * 2 + *(int *)(in_ECX + 0x20));
      if ((uVar14 & 1) != 0) {
        uVar14 = uVar14 + 1;
      }
      iVar13 = *(int *)(in_ECX + 4);
      if (iVar13 != 0x32595559) {
        if ((iVar13 == 0x42475247) || (iVar13 == 0x47424752)) {
          param_2 = (float *)param_3;
          if (*(uint *)(in_ECX + 0x8c) <= param_3) {
            return 0;
          }
          do {
            uVar2 = *(undefined2 *)(in_ECX + 0xa8);
            uVar1 = *puVar16;
            param_2 = (float *)((int)param_2 + 2);
            uVar3 = puVar16[1];
            fVar9 = (float)(uVar1 >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff) * fVar7;
            uVar4 = *(undefined2 *)(in_ECX + 0xac);
            pfVar15[5] = (float)(uVar3 >> ((byte)*(undefined2 *)(in_ECX + 0xa8) & 0x1f) & 0xff) *
                         fVar7;
            fVar10 = (float)(uVar3 >> ((byte)uVar4 & 0x1f) & 0xff) * fVar7;
            *pfVar15 = fVar9;
            pfVar15[1] = (float)(uVar1 >> ((byte)uVar2 & 0x1f) & 0xff) * fVar7;
            pfVar15[2] = fVar10;
            pfVar15[3] = 1.0;
            pfVar15[4] = fVar9;
            pfVar15[6] = fVar10;
            pfVar15[7] = 1.0;
            pfVar15 = pfVar15 + 8;
            puVar16 = puVar16 + 2;
          } while (param_2 < *(uint *)(in_ECX + 0x8c));
          return 0;
        }
        if (iVar13 != 0x59565955) {
          return 0;
        }
      }
      if (param_3 < *(uint *)(in_ECX + 0x8c)) {
        param_2 = pfVar15;
        do {
          uVar1 = *puVar16;
          if ((param_3 & 1) == 0) {
            bVar12 = (byte)*(undefined2 *)(in_ECX + 0xac);
            fVar7 = (float)(uVar1 >> (bVar12 & 0x1f) & 0xff) - fVar11;
            fVar6 = (float)(puVar16[1] >> (bVar12 & 0x1f) & 0xff);
          }
          else if (((param_3 & 1) == 1) && (uVar14 == 2)) {
            bVar12 = (byte)*(undefined2 *)(in_ECX + 0xac);
            fVar7 = (float)(puVar16[-1] >> (bVar12 & 0x1f) & 0xff) - fVar11;
            fVar6 = (float)(uVar1 >> (bVar12 & 0x1f) & 0xff);
          }
          else if ((param_3 == 1) && (uVar14 == 4)) {
            fVar7 = (float)((puVar16[1] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff) * 8
                            + (puVar16[-1] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff)
                              * 8 + 8 >> 4) - fVar11;
            fVar6 = (float)((uVar1 >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff) * 8 +
                            (puVar16[2] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff) * 8
                            + 8 >> 4);
          }
          else if (param_3 == uVar14 - 1) {
            bVar12 = (byte)*(undefined2 *)(in_ECX + 0xac);
            fVar7 = (float)(((puVar16[-1] >> (bVar12 & 0x1f) & 0xff) * 0x11 -
                            (puVar16[-3] >> (bVar12 & 0x1f) & 0xff)) + 8 >> 4) - fVar11;
            bVar12 = (byte)*(undefined2 *)(in_ECX + 0xac);
            fVar6 = (float)(((uVar1 >> (bVar12 & 0x1f) & 0xff) * 0x11 -
                            (puVar16[-2] >> (bVar12 & 0x1f) & 0xff)) + 8 >> 4);
          }
          else if (param_3 == 1) {
            fVar7 = (float)((((puVar16[1] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff) *
                              9 + (puVar16[-1] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) &
                                  0xff) * 8) -
                            (puVar16[3] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff)) +
                            8 >> 4) - fVar11;
            fVar6 = (float)((((puVar16[2] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff) *
                              9 + (uVar1 >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff) *
                                  8) -
                            (puVar16[4] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff)) +
                            8 >> 4);
          }
          else if (param_3 == uVar14 - 3) {
            fVar7 = (float)((((puVar16[-1] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff)
                              * 9 + (puVar16[1] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) &
                                    0xff) * 8) -
                            (puVar16[-3] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff)) +
                            8 >> 4) - fVar11;
            bVar12 = (byte)*(undefined2 *)(in_ECX + 0xac);
            fVar6 = (float)((((puVar16[2] >> (bVar12 & 0x1f) & 0xff) * 8 + 8) -
                            (puVar16[-2] >> (bVar12 & 0x1f) & 0xff)) +
                            (uVar1 >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff) * 9 >> 4
                           );
          }
          else {
            bVar12 = (byte)*(undefined2 *)(in_ECX + 0xac);
            fVar7 = (float)(((((puVar16[-1] >> (bVar12 & 0x1f) & 0xff) +
                              (puVar16[1] >> (bVar12 & 0x1f) & 0xff)) * 9 -
                             (puVar16[-3] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff))
                            - (puVar16[3] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff))
                            + 8 >> 4) - fVar11;
            bVar12 = (byte)*(undefined2 *)(in_ECX + 0xac);
            fVar6 = (float)(((((puVar16[2] >> (bVar12 & 0x1f) & 0xff) +
                              (uVar1 >> (bVar12 & 0x1f) & 0xff)) * 9 -
                             (puVar16[4] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff)) -
                            (puVar16[-2] >> ((byte)*(undefined2 *)(in_ECX + 0xac) & 0x1f) & 0xff)) +
                            8 >> 4);
          }
          fVar8 = ((float)(uVar1 >> ((byte)*(undefined2 *)(in_ECX + 0xa8) & 0x1f) & 0xff) -
                  _DAT_009e4eac) * _DAT_00a17190;
          fVar5 = (fVar6 - fVar11) * _DAT_00a1718c + fVar8;
          *param_2 = fVar5;
          fVar6 = (fVar8 - fVar7 * _DAT_00a17188) - (fVar6 - fVar11) * _DAT_00a17184;
          param_2[1] = fVar6;
          fVar8 = fVar7 * _DAT_00a17180 + fVar8;
          param_2[2] = fVar8;
          param_2[3] = 1.0;
          if (fVar9 <= fVar5) {
            if (fVar10 < fVar5) {
              fVar5 = 1.0;
            }
          }
          else {
            fVar5 = 0.0;
          }
          *param_2 = fVar5;
          if (fVar9 <= fVar6) {
            if (fVar10 < fVar6) {
              fVar6 = 1.0;
            }
          }
          else {
            fVar6 = 0.0;
          }
          param_2[1] = fVar6;
          if (fVar9 <= fVar8) {
            if (fVar10 < fVar8) {
              fVar8 = 1.0;
            }
          }
          else {
            fVar8 = 0.0;
          }
          param_2[2] = fVar8;
          puVar16 = puVar16 + 1;
          param_3 = param_3 + 1;
          param_2 = param_2 + 4;
        } while (param_3 < *(uint *)(in_ECX + 0x8c));
      }
    }
  }
  return 0;
}


// ==== FUN_008abb0b @ 0x008abb0b ====

void FUN_008abb0b(void)

{
  undefined4 *in_ECX;
  uint uVar1;
  
  *in_ECX = &PTR_FUN_00a17194;
  if (((in_ECX[0x3d] != 0) && (in_ECX[0x3e] != 0)) &&
     (uVar1 = in_ECX[0x35], uVar1 < (uint)in_ECX[0x36])) {
    do {
      if ((uint)in_ECX[0x32] < (uint)in_ECX[0x34]) {
        _free(*(void **)(in_ECX[0x3e] + 4));
        return;
      }
      uVar1 = uVar1 + 1;
    } while (uVar1 < (uint)in_ECX[0x36]);
  }
  _free((void *)in_ECX[0x3c]);
  return;
}


// ==== FUN_008abb90 @ 0x008abb90 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008abb90(void)

{
  float fVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 4) == 0x32545844) || (*(int *)(in_ECX + 4) == 0x33545844)) {
    fVar1 = DAT_009bfa74;
  }
  else {
    fVar1 = DAT_0099d0b8;
  }
  *(float *)(in_ECX + 0x80) = fVar1;
  *(float *)(in_ECX + 0x84) = 1.0 / fVar1;
  *(float *)(in_ECX + 0x24) =
       (float)(int)ROUND(*(float *)(in_ECX + 0x24) * _DAT_00a171ac + DAT_0099d0b4) * _DAT_00a171a8;
  *(float *)(in_ECX + 0x28) =
       (float)(int)ROUND(*(float *)(in_ECX + 0x28) * DAT_00a10a2c + DAT_0099d0b4) * _DAT_00a171a4;
  *(float *)(in_ECX + 0x2c) =
       (float)(int)ROUND(*(float *)(in_ECX + 0x2c) * _DAT_00a171ac + DAT_0099d0b4) * _DAT_00a171a8;
  *(float *)(in_ECX + 0x30) =
       (float)(int)ROUND(*(float *)(in_ECX + 0x80) * *(float *)(in_ECX + 0x30) + DAT_0099d0b4) *
       *(float *)(in_ECX + 0x84);
  return;
}


// ==== FUN_008abc72 @ 0x008abc72 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_008abc72(float param_1)

{
  int iVar1;
  float fVar2;
  float10 fVar3;
  
  fVar3 = (float10)FUN_007a3f2f(param_1);
  fVar2 = (float)(fVar3 * (float10)param_1 * (float10)_DAT_00a171b0);
  iVar1 = (int)ROUND(fVar2);
  fVar3 = (float10)iVar1;
  if (iVar1 < 0) {
    fVar3 = fVar3 + (float10)_DAT_0099d104;
  }
  return ((float10)fVar2 - fVar3) *
         ((float10)*(float *)(&DAT_00a16954 + iVar1 * 4) -
         (float10)*(float *)(&DAT_00a16950 + iVar1 * 4)) +
         (float10)*(float *)(&DAT_00a16950 + iVar1 * 4);
}


// ==== FUN_008abcc4 @ 0x008abcc4 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_008abcc4(float param_1)

{
  int iVar1;
  float fVar2;
  float10 fVar3;
  
  fVar2 = param_1 * param_1 * _DAT_00a171b0;
  iVar1 = (int)ROUND(fVar2);
  fVar3 = (float10)iVar1;
  if (iVar1 < 0) {
    fVar3 = fVar3 + (float10)_DAT_0099d104;
  }
  return ((float10)fVar2 - fVar3) *
         ((float10)*(float *)(&DAT_00a16d54 + iVar1 * 4) -
         (float10)*(float *)(&DAT_00a16d50 + iVar1 * 4)) +
         (float10)*(float *)(&DAT_00a16d50 + iVar1 * 4);
}


// ==== FUN_008abd0d @ 0x008abd0d ====

void FUN_008abd0d(undefined4 *param_1,uint param_2,int param_3)

{
  uint uVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  undefined *puVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *in_ECX;
  int iVar9;
  undefined4 *puVar10;
  
  *in_ECX = &PTR_FUN_00a17150;
  in_ECX[8] = *param_1;
  in_ECX[1] = param_1[1];
  in_ECX[0x18] = param_1[2];
  in_ECX[0x19] = param_1[3];
  puVar8 = param_1 + 10;
  puVar10 = in_ECX + 0xf;
  for (iVar9 = 6; iVar9 != 0; iVar9 = iVar9 + -1) {
    *puVar10 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar10 = puVar10 + 1;
  }
  puVar5 = &DAT_00b53f60;
  if (param_1[0x10] == 0) {
    puVar5 = &DAT_00b53ee0;
  }
  in_ECX[0xd] = puVar5;
  uVar6 = param_2 >> 3;
  in_ECX[0x1e] = uVar6;
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  in_ECX[3] = (uint)(param_2 != 0);
  in_ECX[2] = param_3;
  in_ECX[6] = param_1[0x13];
  if ((in_ECX[1] == 0x29) || (in_ECX[1] == 0x28)) {
    uVar7 = 1;
  }
  else {
    uVar7 = 0;
  }
  in_ECX[7] = uVar7;
  in_ECX[0xe] = 0;
  in_ECX[4] = param_1[0x12];
  in_ECX[5] = 0;
  in_ECX[0x17] = 0;
  if (in_ECX[6] != 0) {
    uVar1 = param_1[0x13];
    fVar2 = (float)(uVar1 >> 8 & 0xff) * DAT_0099d0b0;
    fVar3 = (float)(uVar1 & 0xff) * DAT_0099d0b0;
    fVar4 = (float)(uVar1 >> 0x18) * DAT_0099d0b0;
    in_ECX[9] = (float)(uVar1 >> 0x10 & 0xff) * DAT_0099d0b0;
    in_ECX[10] = fVar2;
    in_ECX[0xb] = fVar3;
    in_ECX[0xc] = fVar4;
  }
  if (param_3 == 2) {
    if (in_ECX[1] == 0x3d) goto LAB_008abe21;
    in_ECX[4] = 0;
  }
  if (param_3 == 3) {
    in_ECX[4] = 0;
  }
LAB_008abe21:
  iVar9 = in_ECX[0x11] - in_ECX[0xf];
  in_ECX[0x1a] = iVar9;
  in_ECX[0x1b] = in_ECX[0x12] - in_ECX[0x10];
  in_ECX[0x1d] = iVar9 * uVar6;
  in_ECX[0x1c] = in_ECX[0x14] - in_ECX[0x13];
  if ((param_2 != 0) != 0) {
    in_ECX[8] = in_ECX[8] +
                in_ECX[0xf] * uVar6 + in_ECX[0x18] * in_ECX[0x10] + in_ECX[0x19] * in_ECX[0x13];
    in_ECX[0x11] = in_ECX[0x1a];
    in_ECX[0x12] = in_ECX[0x1b];
    in_ECX[0xf] = 0;
    in_ECX[0x10] = 0;
    in_ECX[0x13] = 0;
    in_ECX[0x14] = in_ECX[0x1c];
  }
  if (param_1[0x11] != 0) {
    iVar9 = in_ECX[0x1a];
    puVar8 = operator_new((iVar9 + 2) * 0x10);
    if (puVar8 == (undefined4 *)0x0) {
      puVar8 = (undefined4 *)0x0;
    }
    else {
      FUN_0040d030(puVar8,0x10,iVar9 + 2,FUN_0079e14e);
    }
    in_ECX[0x17] = puVar8;
    if (puVar8 != (undefined4 *)0x0) {
      for (iVar9 = (in_ECX[0x1a] + 2 & 0xfffffff) << 2; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      for (iVar9 = 0; iVar9 != 0; iVar9 = iVar9 + -1) {
        *(undefined1 *)puVar8 = 0;
        puVar8 = (undefined4 *)((int)puVar8 + 1);
      }
    }
  }
  return;
}


// ==== FUN_008abed9 @ 0x008abed9 ====

undefined4 FUN_008abed9(int param_1)

{
  int iVar1;
  void *pvVar2;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 8) != *(int *)(param_1 + 8)) && (*(int *)(in_ECX + 8) != 4)) {
    *(int *)(in_ECX + 0x54) = *(int *)(param_1 + 8);
  }
  if ((*(int *)(in_ECX + 0x54) != 0) || (*(int *)(in_ECX + 0x10) != 0)) {
    iVar1 = *(int *)(in_ECX + 0x68);
    pvVar2 = operator_new(iVar1 << 4);
    if (pvVar2 == (void *)0x0) {
      pvVar2 = (void *)0x0;
    }
    else {
      FUN_0040d030(pvVar2,0x10,iVar1,FUN_0079e14e);
    }
    *(void **)(in_ECX + 0x58) = pvVar2;
    if (pvVar2 == (void *)0x0) {
      return 0x8007000e;
    }
    if ((*(int *)(in_ECX + 0x10) != 0) && (*(int *)(param_1 + 0x10) != 0)) {
      *(undefined4 *)(param_1 + 0x14) = 1;
      *(undefined4 *)(in_ECX + 0x14) = 1;
    }
  }
  return 0;
}


// ==== FUN_008abf5c @ 0x008abf5c ====

undefined4 FUN_008abf5c(int param_1)

{
  float fVar1;
  void *pvVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  int in_ECX;
  int iVar6;
  
  pvVar2 = operator_new(0x1000);
  if (pvVar2 == (void *)0x0) {
    pvVar2 = (void *)0x0;
  }
  else {
    FUN_0040d030(pvVar2,0x10,0x100,FUN_0079e14e);
  }
  iVar6 = 0;
  *(void **)(in_ECX + 0x38) = pvVar2;
  fVar1 = DAT_0099d0b0;
  if (pvVar2 == (void *)0x0) {
    uVar3 = 0x8007000e;
  }
  else {
    uVar4 = 0;
    if (*(int *)(param_1 + 0x50) == 0) {
      do {
        *(undefined4 *)(uVar4 + 0xc + *(int *)(in_ECX + 0x38)) = 0x3f800000;
        *(undefined4 *)(uVar4 + 8 + *(int *)(in_ECX + 0x38)) = 0x3f800000;
        *(undefined4 *)(uVar4 + 4 + *(int *)(in_ECX + 0x38)) = 0x3f800000;
        *(undefined4 *)(uVar4 + *(int *)(in_ECX + 0x38)) = 0x3f800000;
        uVar4 = uVar4 + 0x10;
      } while (uVar4 < 0x1000);
    }
    else {
      do {
        uVar5 = uVar4 + 4;
        *(float *)(iVar6 + *(int *)(in_ECX + 0x38)) =
             (float)*(byte *)(uVar4 + *(int *)(param_1 + 0x50)) * fVar1;
        *(float *)(iVar6 + 4 + *(int *)(in_ECX + 0x38)) =
             (float)*(byte *)(uVar4 + 1 + *(int *)(param_1 + 0x50)) * fVar1;
        *(float *)(iVar6 + 8 + *(int *)(in_ECX + 0x38)) =
             (float)*(byte *)(uVar4 + 2 + *(int *)(param_1 + 0x50)) * fVar1;
        *(float *)(iVar6 + 0xc + *(int *)(in_ECX + 0x38)) =
             (float)*(byte *)(uVar4 + 3 + *(int *)(param_1 + 0x50)) * fVar1;
        uVar4 = uVar5;
        iVar6 = iVar6 + 0x10;
      } while (uVar5 < 0x400);
    }
    uVar3 = 0;
  }
  return uVar3;
}


// ==== FUN_008ac051 @ 0x008ac051 ====

/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */

void FUN_008ac051(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *in_ECX;
  undefined1 local_18 [16];
  undefined4 local_8;
  
  local_8 = DAT_00b49670;
  iVar1 = in_ECX[8];
  iVar2 = in_ECX[0x1d];
  iVar3 = in_ECX[0xd];
  iVar4 = in_ECX[6];
  in_ECX[6] = 0;
  in_ECX[0x1d] = in_ECX[0x1e];
  in_ECX[8] = (int)local_18;
  iVar5 = in_ECX[0x1a];
  in_ECX[0x1a] = 1;
  in_ECX[0xd] = (int)&DAT_00b53ee0;
  if ((in_ECX[2] != 1) && (in_ECX[2] != 4)) {
    iVar6 = in_ECX[0x15];
    iVar7 = in_ECX[0x16];
    in_ECX[0x15] = 1;
    in_ECX[0x16] = (int)(in_ECX + 9);
    FUN_008aac69(in_ECX + 9);
    in_ECX[0x15] = iVar6;
    in_ECX[0x16] = iVar7;
  }
  (**(code **)(*in_ECX + 8))(0,0,in_ECX + 9);
  (**(code **)(*in_ECX + 4))(0,0,in_ECX + 9);
  in_ECX[8] = iVar1;
  in_ECX[0xd] = iVar3;
  in_ECX[0x1a] = iVar5;
  in_ECX[0x1d] = iVar2;
  in_ECX[6] = iVar4;
  return;
}


// ==== FUN_008ac113 @ 0x008ac113 ====

void FUN_008ac113(uint param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  float *pfVar3;
  
  uVar1 = *(int *)(in_ECX + 0x68) * 0x10 + param_1;
  if (param_1 < uVar1) {
    iVar2 = ((uVar1 - param_1) - 1 >> 4) + 1;
    pfVar3 = (float *)(param_1 + 8);
    do {
      if ((((pfVar3[-2] == *(float *)(in_ECX + 0x24)) && (pfVar3[-1] == *(float *)(in_ECX + 0x28)))
          && (*pfVar3 == *(float *)(in_ECX + 0x2c))) && (pfVar3[1] == *(float *)(in_ECX + 0x30))) {
        pfVar3[1] = 0.0;
        *pfVar3 = 0.0;
        pfVar3[-1] = 0.0;
        pfVar3[-2] = 0.0;
      }
      pfVar3 = pfVar3 + 4;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}


// ==== FUN_008ac18d @ 0x008ac18d ====

undefined4 FUN_008ac18d(int param_1)

{
  int in_ECX;
  int iVar1;
  float *pfVar2;
  undefined4 *puVar3;
  undefined2 in_FPUControlWord;
  float10 fVar4;
  undefined4 local_8;
  
  iVar1 = 0;
  if (*(int *)(in_ECX + 0x14) == 0) {
    local_8 = CONCAT22((short)((uint)in_ECX >> 0x10),in_FPUControlWord);
    *(uint *)(in_ECX + 0x7c) = local_8;
    if ((*(int *)(in_ECX + 8) == 1) || (*(int *)(in_ECX + 8) == 4)) {
      local_8 = 0;
      if (*(int *)(in_ECX + 0x68) != 0) {
        puVar3 = (undefined4 *)(param_1 + 8);
        do {
          fVar4 = (float10)FUN_008abc72(puVar3[-2]);
          *(float *)(iVar1 + *(int *)(in_ECX + 0x58)) = (float)fVar4;
          fVar4 = (float10)FUN_008abc72(puVar3[-1]);
          *(float *)(iVar1 + 4 + *(int *)(in_ECX + 0x58)) = (float)fVar4;
          fVar4 = (float10)FUN_008abc72(*puVar3);
          local_8 = local_8 + 1;
          *(float *)(iVar1 + 8 + *(int *)(in_ECX + 0x58)) = (float)fVar4;
          *(undefined4 *)(iVar1 + 0xc + *(int *)(in_ECX + 0x58)) = puVar3[1];
          iVar1 = iVar1 + 0x10;
          puVar3 = puVar3 + 4;
        } while (local_8 < *(uint *)(in_ECX + 0x68));
      }
    }
    else {
      local_8 = 0;
      if (*(int *)(in_ECX + 0x68) != 0) {
        puVar3 = (undefined4 *)(param_1 + 8);
        do {
          *(undefined4 *)(iVar1 + *(int *)(in_ECX + 0x58)) = puVar3[-2];
          *(undefined4 *)(iVar1 + 4 + *(int *)(in_ECX + 0x58)) = puVar3[-1];
          *(undefined4 *)(iVar1 + 8 + *(int *)(in_ECX + 0x58)) = *puVar3;
          fVar4 = (float10)FUN_008abc72(puVar3[1]);
          local_8 = local_8 + 1;
          *(float *)(iVar1 + 0xc + *(int *)(in_ECX + 0x58)) = (float)fVar4;
          iVar1 = iVar1 + 0x10;
          puVar3 = puVar3 + 4;
        } while (local_8 < *(uint *)(in_ECX + 0x68));
      }
    }
  }
  else if ((*(int *)(in_ECX + 8) == 1) || (*(int *)(in_ECX + 8) == 4)) {
    local_8 = 0;
    if (*(int *)(in_ECX + 0x68) != 0) {
      iVar1 = -param_1;
      pfVar2 = (float *)(param_1 + 8);
      do {
        fVar4 = (float10)FUN_007a3f2f(pfVar2[-2]);
        *(float *)((int)pfVar2 + *(int *)(in_ECX + 0x58) + iVar1 + -8) =
             (float)(fVar4 * (float10)pfVar2[-2]);
        fVar4 = (float10)FUN_007a3f2f(pfVar2[-1]);
        *(float *)((int)pfVar2 + *(int *)(in_ECX + 0x58) + iVar1 + -4) =
             (float)(fVar4 * (float10)pfVar2[-1]);
        fVar4 = (float10)FUN_007a3f2f(*pfVar2);
        local_8 = local_8 + 1;
        *(float *)((int)pfVar2 + *(int *)(in_ECX + 0x58) + iVar1) =
             (float)(fVar4 * (float10)*pfVar2);
        *(float *)((int)pfVar2 + *(int *)(in_ECX + 0x58) + iVar1 + 4) = pfVar2[1];
        pfVar2 = pfVar2 + 4;
      } while (local_8 < *(uint *)(in_ECX + 0x68));
    }
  }
  else {
    local_8 = 0;
    if (*(int *)(in_ECX + 0x68) != 0) {
      iVar1 = -0xc - param_1;
      pfVar2 = (float *)(param_1 + 0xc);
      do {
        *(float *)((int)pfVar2 + *(int *)(in_ECX + 0x58) + iVar1) = pfVar2[-3];
        *(float *)((int)pfVar2 + *(int *)(in_ECX + 0x58) + 4 + iVar1) = pfVar2[-2];
        *(float *)((int)pfVar2 + *(int *)(in_ECX + 0x58) + 8 + iVar1) = pfVar2[-1];
        fVar4 = (float10)FUN_007a3f2f(*pfVar2);
        local_8 = local_8 + 1;
        *(float *)((int)pfVar2 + *(int *)(in_ECX + 0x58) + 0xc + iVar1) =
             (float)(fVar4 * (float10)*pfVar2);
        pfVar2 = pfVar2 + 4;
      } while (local_8 < *(uint *)(in_ECX + 0x68));
    }
  }
  return *(undefined4 *)(in_ECX + 0x58);
}


// ==== FUN_008ac380 @ 0x008ac380 ====

void FUN_008ac380(uint param_1)

{
  uint uVar1;
  float *pfVar2;
  int in_ECX;
  uint uVar3;
  int iVar4;
  undefined2 in_FPUControlWord;
  float10 fVar5;
  
  uVar1 = param_1;
  uVar3 = *(int *)(in_ECX + 0x68) * 0x10 + param_1;
  if (*(int *)(in_ECX + 0x14) == 0) {
    param_1 = CONCAT22(param_1._2_2_,in_FPUControlWord);
    *(uint *)(in_ECX + 0x7c) = param_1;
    if ((*(int *)(in_ECX + 8) == 1) || (*(int *)(in_ECX + 8) == 4)) {
      if (uVar1 < uVar3) {
        iVar4 = ((uVar3 - uVar1) - 1 >> 4) + 1;
        pfVar2 = (float *)(uVar1 + 8);
        do {
          fVar5 = (float10)FUN_008abcc4(pfVar2[-2]);
          pfVar2[-2] = (float)fVar5;
          fVar5 = (float10)FUN_008abcc4(pfVar2[-1]);
          pfVar2[-1] = (float)fVar5;
          fVar5 = (float10)FUN_008abcc4(*pfVar2);
          *pfVar2 = (float)fVar5;
          pfVar2 = pfVar2 + 4;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
    }
    else if (uVar1 < uVar3) {
      iVar4 = ((uVar3 - uVar1) - 1 >> 4) + 1;
      pfVar2 = (float *)(uVar1 + 0xc);
      do {
        fVar5 = (float10)FUN_008abcc4(*pfVar2);
        *pfVar2 = (float)fVar5;
        pfVar2 = pfVar2 + 4;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  else if ((*(int *)(in_ECX + 8) == 1) || (*(int *)(in_ECX + 8) == 4)) {
    if (param_1 < uVar3) {
      pfVar2 = (float *)(param_1 + 8);
      iVar4 = ((uVar3 - param_1) - 1 >> 4) + 1;
      do {
        pfVar2[-2] = pfVar2[-2] * pfVar2[-2];
        pfVar2[-1] = pfVar2[-1] * pfVar2[-1];
        *pfVar2 = *pfVar2 * *pfVar2;
        pfVar2 = pfVar2 + 4;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  else if (param_1 < uVar3) {
    pfVar2 = (float *)(param_1 + 0xc);
    iVar4 = ((uVar3 - param_1) - 1 >> 4) + 1;
    do {
      *pfVar2 = *pfVar2 * *pfVar2;
      pfVar2 = pfVar2 + 4;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}


// ==== FUN_008ac4a9 @ 0x008ac4a9 ====

void FUN_008ac4a9(int param_1)

{
  float *pfVar1;
  float *pfVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  
  uVar4 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    pfVar2 = (float *)(param_1 + 8);
    do {
      pfVar1 = (float *)((int)pfVar2 + *(int *)(in_ECX + 0x5c) + (8 - param_1));
      uVar4 = uVar4 + 1;
      pfVar2[-2] = *pfVar1 + pfVar2[-2];
      pfVar2[-1] = pfVar1[1] + pfVar2[-1];
      *pfVar2 = pfVar1[2] + *pfVar2;
      pfVar2[1] = pfVar1[3] + pfVar2[1];
      pfVar2 = pfVar2 + 4;
    } while (uVar4 < *(uint *)(in_ECX + 0x68));
  }
  puVar5 = *(undefined4 **)(in_ECX + 0x5c);
  for (iVar3 = (*(int *)(in_ECX + 0x68) + 2U & 0xfffffff) << 2; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
    *(undefined1 *)puVar5 = 0;
    puVar5 = (undefined4 *)((int)puVar5 + 1);
  }
  return;
}


// ==== FUN_008ac51b @ 0x008ac51b ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008ac51b(uint param_1,uint param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  uint uVar10;
  int iVar11;
  int iVar12;
  undefined1 uVar13;
  int iVar14;
  int iVar15;
  int iVar16;
  undefined1 *puVar17;
  undefined2 in_FPUControlWord;
  float local_54;
  float local_50;
  float local_4c;
  int local_34;
  int local_30;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  uVar10 = param_1 & 3;
  uVar8 = param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  puVar17 = (undefined1 *)
            ((*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 3 + *(int *)(in_ECX + 0x60) * param_1
             + *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  if ((param_1 & 1) == 0) {
    iVar15 = 0;
    iVar14 = 1;
    param_1 = 1;
  }
  else {
    iVar15 = *(int *)(in_ECX + 0x68) + -1;
    param_1 = -1;
    iVar14 = -1;
  }
  param_2 = CONCAT22(param_2._2_2_,in_FPUControlWord);
  *(uint *)(in_ECX + 0x7c) = param_2;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
    iVar14 = param_1;
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar14 * 0x10;
    iVar9 = iVar15 * 0x10;
    iVar12 = (iVar14 + iVar15) * 0x10;
    param_2 = (iVar15 - iVar14) * 0x10;
    param_3 = (float *)(iVar9 + 8 + (int)param_3);
    do {
      fVar7 = DAT_0099d0b0;
      fVar2 = *(float *)(iVar3 + (uVar8 + uVar10 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_54 + param_3[-2]) * DAT_0099d0b8;
      fVar5 = (local_50 + param_3[-1]) * DAT_0099d0b8;
      fVar6 = (local_4c + *param_3) * DAT_0099d0b8;
      local_34 = (int)ROUND(fVar4 + fVar2);
      local_30 = (int)ROUND(fVar5 + fVar2);
      iVar15 = (int)ROUND(fVar6 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + param_2);
        local_54 = (fVar4 - (float)local_34) * DAT_0099d0b0;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar12);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + param_2);
        local_54 = local_54 * (float)_DAT_00a171b8;
        local_50 = (fVar5 - (float)local_30) * fVar7;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar12);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + param_2);
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar7 = (fVar6 - (float)iVar15) * fVar7;
        *pfVar1 = _DAT_00a171c4 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar9);
        *pfVar1 = _DAT_00a171c0 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar12);
        *pfVar1 = DAT_009af898 * fVar7 + *pfVar1;
        local_4c = fVar7 * (float)_DAT_00a171b8;
      }
      uVar13 = 0xff;
      iVar16 = local_34;
      if (0xfe < local_34) {
        iVar16 = 0xff;
      }
      if (iVar16 < 1) {
        local_34 = 0;
      }
      else if (0xfe < local_34) {
        local_34 = 0xff;
      }
      iVar16 = local_30;
      if (0xfe < local_30) {
        iVar16 = 0xff;
      }
      if (iVar16 < 1) {
        local_30 = 0;
      }
      else if (0xfe < local_30) {
        local_30 = 0xff;
      }
      iVar16 = iVar15;
      if (0xfe < iVar15) {
        iVar16 = 0xff;
      }
      if (iVar16 < 1) {
        uVar13 = 0;
      }
      else if (iVar15 < 0xff) {
        uVar13 = (undefined1)iVar15;
      }
      *puVar17 = uVar13;
      puVar17[1] = (undefined1)local_30;
      puVar17[2] = (undefined1)local_34;
      param_3 = param_3 + iVar14 * 4;
      param_2 = param_2 + iVar11;
      puVar17 = puVar17 + iVar14 * 3;
      iVar9 = iVar9 + iVar11;
      iVar12 = iVar12 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008ac818 @ 0x008ac818 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008ac818(uint param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  ushort in_FPUControlWord;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_58 = 0.0;
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
                     *(int *)(in_ECX + 100) * (int)param_2 + *(int *)(in_ECX + 0x20));
  uVar9 = param_1 & 3;
  uVar13 = (uint)param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar18 = 0;
    iVar15 = 1;
  }
  else {
    iVar18 = *(int *)(in_ECX + 0x68) + -1;
    iVar15 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar15 * 0x10;
    iVar10 = iVar18 * 0x10;
    param_2 = (float *)(iVar10 + 8 + param_3);
    iVar12 = (iVar15 + iVar18) * 0x10;
    iVar18 = (iVar18 - iVar15) * 0x10;
    do {
      fVar8 = DAT_0099d0b0;
      fVar2 = *(float *)(iVar3 + (uVar13 + uVar9 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_58 + param_2[-2]) * DAT_0099d0b8;
      fVar5 = (local_54 + param_2[-1]) * DAT_0099d0b8;
      fVar6 = (local_50 + *param_2) * DAT_0099d0b8;
      fVar7 = (local_4c + param_2[1]) * DAT_0099d0b8;
      local_38 = (uint)ROUND(fVar4 + fVar2);
      local_34 = (uint)ROUND(fVar5 + fVar2);
      local_30 = (uint)ROUND(fVar6 + fVar2);
      iVar14 = (int)ROUND(fVar7 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar18);
        local_58 = (fVar4 - (float)(int)local_38) * DAT_0099d0b0;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar12);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar18);
        local_58 = local_58 * (float)_DAT_00a171b8;
        local_54 = (fVar5 - (float)(int)local_34) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar12);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar18);
        local_54 = local_54 * (float)_DAT_00a171b8;
        local_50 = (fVar6 - (float)(int)local_30) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar12);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar18);
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar8 = (fVar7 - (float)iVar14) * fVar8;
        *pfVar1 = _DAT_00a171c4 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar10);
        *pfVar1 = _DAT_00a171c0 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar12);
        *pfVar1 = DAT_009af898 * fVar8 + *pfVar1;
        local_4c = fVar8 * (float)_DAT_00a171b8;
      }
      uVar16 = local_38;
      if (0xfe < (int)local_38) {
        uVar16 = 0xff;
      }
      if ((int)uVar16 < 1) {
        local_38 = 0;
      }
      else if (0xfe < (int)local_38) {
        local_38 = 0xff;
      }
      uVar16 = local_34;
      if (0xfe < (int)local_34) {
        uVar16 = 0xff;
      }
      if ((int)uVar16 < 1) {
        local_34 = 0;
      }
      else if (0xfe < (int)local_34) {
        local_34 = 0xff;
      }
      uVar16 = local_30;
      if (0xfe < (int)local_30) {
        uVar16 = 0xff;
      }
      if ((int)uVar16 < 1) {
        local_30 = 0;
      }
      else if (0xfe < (int)local_30) {
        local_30 = 0xff;
      }
      iVar17 = iVar14;
      if (0xfe < iVar14) {
        iVar17 = 0xff;
      }
      if (iVar17 < 1) {
        iVar14 = 0;
      }
      else if (0xfe < iVar14) {
        iVar14 = 0xff;
      }
      *local_8 = ((iVar14 << 8 | local_38) << 8 | local_34) << 8 | local_30;
      local_8 = local_8 + iVar15;
      param_2 = param_2 + iVar15 * 4;
      iVar10 = iVar10 + iVar11;
      iVar18 = iVar18 + iVar11;
      iVar12 = iVar12 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008acbc7 @ 0x008acbc7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008acbc7(uint param_1,uint param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  ushort in_FPUControlWord;
  float local_54;
  float local_50;
  float local_4c;
  uint local_30;
  uint local_2c;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  uVar8 = param_1 & 3;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
                     *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar14 = 0;
    iVar13 = 1;
  }
  else {
    iVar14 = *(int *)(in_ECX + 0x68) + -1;
    iVar13 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar10 = iVar13 * 0x10;
    iVar9 = iVar14 * 0x10;
    iVar11 = (iVar13 + iVar14) * 0x10;
    iVar14 = (iVar14 - iVar13) * 0x10;
    param_3 = (float *)(iVar9 + 8 + (int)param_3);
    do {
      fVar7 = DAT_0099d0b0;
      fVar2 = *(float *)(iVar3 + ((param_2 & 3) + uVar8 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_54 + param_3[-2]) * DAT_0099d0b8;
      fVar5 = (local_50 + param_3[-1]) * DAT_0099d0b8;
      fVar6 = (local_4c + *param_3) * DAT_0099d0b8;
      iVar12 = (int)ROUND(fVar4 + fVar2);
      local_30 = (uint)ROUND(fVar5 + fVar2);
      local_2c = (uint)ROUND(fVar6 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar14);
        local_54 = (fVar4 - (float)iVar12) * DAT_0099d0b0;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar11);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar14);
        local_54 = local_54 * (float)_DAT_00a171b8;
        local_50 = (fVar5 - (float)(int)local_30) * fVar7;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar11);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar14);
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar7 = (fVar6 - (float)(int)local_2c) * fVar7;
        *pfVar1 = _DAT_00a171c4 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar9);
        *pfVar1 = _DAT_00a171c0 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar11);
        *pfVar1 = DAT_009af898 * fVar7 + *pfVar1;
        local_4c = fVar7 * (float)_DAT_00a171b8;
      }
      iVar15 = iVar12;
      if (0xfe < iVar12) {
        iVar15 = 0xff;
      }
      if (iVar15 < 1) {
        iVar12 = 0;
      }
      else if (0xfe < iVar12) {
        iVar12 = 0xff;
      }
      uVar16 = local_30;
      if (0xfe < (int)local_30) {
        uVar16 = 0xff;
      }
      if ((int)uVar16 < 1) {
        local_30 = 0;
      }
      else if (0xfe < (int)local_30) {
        local_30 = 0xff;
      }
      uVar16 = local_2c;
      if (0xfe < (int)local_2c) {
        uVar16 = 0xff;
      }
      if ((int)uVar16 < 1) {
        local_2c = 0;
      }
      else if (0xfe < (int)local_2c) {
        local_2c = 0xff;
      }
      *local_8 = (iVar12 << 8 | local_30) << 8 | local_2c;
      local_8 = local_8 + iVar13;
      param_3 = param_3 + iVar13 * 4;
      iVar9 = iVar9 + iVar10;
      iVar14 = iVar14 + iVar10;
      iVar11 = iVar11 + iVar10;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008acedd @ 0x008acedd ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008acedd(uint param_1,uint param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  ushort in_FPUControlWord;
  float local_54;
  float local_50;
  float local_4c;
  uint local_30;
  int local_2c;
  ushort *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  uVar8 = param_1 & 3;
  local_8 = (ushort *)
            (*(int *)(in_ECX + 0x60) * param_1 + (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2
             + *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar14 = 0;
    iVar13 = 1;
  }
  else {
    iVar14 = *(int *)(in_ECX + 0x68) + -1;
    iVar13 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar10 = iVar13 * 0x10;
    iVar9 = iVar14 * 0x10;
    iVar11 = (iVar13 + iVar14) * 0x10;
    iVar14 = (iVar14 - iVar13) * 0x10;
    param_3 = (float *)(iVar9 + 8 + (int)param_3);
    do {
      fVar7 = _DAT_00a171a8;
      fVar2 = *(float *)(iVar3 + ((param_2 & 3) + uVar8 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_54 + param_3[-2]) * _DAT_00a171ac;
      fVar5 = (local_50 + param_3[-1]) * DAT_00a10a2c;
      fVar6 = (local_4c + *param_3) * _DAT_00a171ac;
      iVar12 = (int)ROUND(fVar4 + fVar2);
      local_30 = (uint)ROUND(fVar5 + fVar2);
      local_2c = (int)ROUND(fVar6 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar14);
        local_54 = (fVar4 - (float)iVar12) * _DAT_00a171a8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar11);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar14);
        local_54 = local_54 * (float)_DAT_00a171b8;
        local_50 = (fVar5 - (float)(int)local_30) * _DAT_00a171a4;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar11);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar14);
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar7 = (fVar6 - (float)local_2c) * fVar7;
        *pfVar1 = _DAT_00a171c4 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar9);
        *pfVar1 = _DAT_00a171c0 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar11);
        *pfVar1 = DAT_009af898 * fVar7 + *pfVar1;
        local_4c = fVar7 * (float)_DAT_00a171b8;
      }
      if (iVar12 < 0x1f) {
        iVar16 = iVar12;
      }
      else {
        iVar16 = 0x1f;
      }
      if (iVar16 < 1) {
        iVar12 = 0;
      }
      else if (0x1e < iVar12) {
        iVar12 = 0x1f;
      }
      uVar15 = local_30;
      if (0x3e < (int)local_30) {
        uVar15 = 0x3f;
      }
      if ((int)uVar15 < 1) {
        local_30 = 0;
      }
      else if (0x3e < (int)local_30) {
        local_30 = 0x3f;
      }
      iVar16 = local_2c;
      if (0x1e < local_2c) {
        iVar16 = 0x1f;
      }
      if (iVar16 < 1) {
        local_2c = 0;
      }
      else if (0x1e < local_2c) {
        local_2c = 0x1f;
      }
      *local_8 = (ushort)((iVar12 << 6 | local_30) << 5) | (ushort)local_2c;
      local_8 = local_8 + iVar13;
      param_3 = param_3 + iVar13 * 4;
      iVar9 = iVar9 + iVar10;
      iVar14 = iVar14 + iVar10;
      iVar11 = iVar11 + iVar10;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008ad1e0 @ 0x008ad1e0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008ad1e0(uint param_1,uint param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  ushort in_FPUControlWord;
  float local_54;
  float local_50;
  float local_4c;
  uint local_30;
  int local_2c;
  ushort *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  uVar8 = param_1 & 3;
  local_8 = (ushort *)
            (*(int *)(in_ECX + 0x60) * param_1 + (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2
             + *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar14 = 0;
    iVar13 = 1;
  }
  else {
    iVar14 = *(int *)(in_ECX + 0x68) + -1;
    iVar13 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar10 = iVar13 * 0x10;
    iVar9 = iVar14 * 0x10;
    iVar11 = (iVar13 + iVar14) * 0x10;
    iVar14 = (iVar14 - iVar13) * 0x10;
    param_3 = (float *)(iVar9 + 8 + (int)param_3);
    do {
      fVar7 = _DAT_00a171a8;
      fVar2 = *(float *)(iVar3 + ((param_2 & 3) + uVar8 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_54 + param_3[-2]) * _DAT_00a171ac;
      fVar5 = (local_50 + param_3[-1]) * _DAT_00a171ac;
      fVar6 = (local_4c + *param_3) * _DAT_00a171ac;
      iVar12 = (int)ROUND(fVar4 + fVar2);
      local_30 = (uint)ROUND(fVar5 + fVar2);
      local_2c = (int)ROUND(fVar6 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar14);
        local_54 = (fVar4 - (float)iVar12) * _DAT_00a171a8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar11);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar14);
        local_54 = local_54 * (float)_DAT_00a171b8;
        local_50 = (fVar5 - (float)(int)local_30) * fVar7;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar11);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar14);
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar7 = (fVar6 - (float)local_2c) * fVar7;
        *pfVar1 = _DAT_00a171c4 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar9);
        *pfVar1 = _DAT_00a171c0 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar11);
        *pfVar1 = DAT_009af898 * fVar7 + *pfVar1;
        local_4c = fVar7 * (float)_DAT_00a171b8;
      }
      if (iVar12 < 0x1f) {
        iVar16 = iVar12;
      }
      else {
        iVar16 = 0x1f;
      }
      if (iVar16 < 1) {
        iVar12 = 0;
      }
      else if (0x1e < iVar12) {
        iVar12 = 0x1f;
      }
      uVar15 = local_30;
      if (0x1e < (int)local_30) {
        uVar15 = 0x1f;
      }
      if ((int)uVar15 < 1) {
        local_30 = 0;
      }
      else if (0x1e < (int)local_30) {
        local_30 = 0x1f;
      }
      iVar16 = local_2c;
      if (0x1e < local_2c) {
        iVar16 = 0x1f;
      }
      if (iVar16 < 1) {
        local_2c = 0;
      }
      else if (0x1e < local_2c) {
        local_2c = 0x1f;
      }
      *local_8 = (ushort)((iVar12 << 5 | local_30) << 5) | (ushort)local_2c;
      local_8 = local_8 + iVar13;
      param_3 = param_3 + iVar13 * 4;
      iVar9 = iVar9 + iVar10;
      iVar14 = iVar14 + iVar10;
      iVar11 = iVar11 + iVar10;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008ad4df @ 0x008ad4df ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008ad4df(uint param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  ushort in_FPUControlWord;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  uint local_38;
  uint local_34;
  int local_30;
  ushort *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_58 = 0.0;
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  local_8 = (ushort *)
            (*(int *)(in_ECX + 0x60) * param_1 + (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2
             + *(int *)(in_ECX + 100) * (int)param_2 + *(int *)(in_ECX + 0x20));
  uVar9 = param_1 & 3;
  uVar13 = (uint)param_2 & 3;
  iVar4 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar18 = 0;
    iVar15 = 1;
  }
  else {
    iVar18 = *(int *)(in_ECX + 0x68) + -1;
    iVar15 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar15 * 0x10;
    iVar10 = iVar18 * 0x10;
    param_2 = (float *)(iVar10 + 8 + param_3);
    iVar12 = (iVar15 + iVar18) * 0x10;
    iVar18 = (iVar18 - iVar15) * 0x10;
    do {
      fVar8 = _DAT_00a171a8;
      fVar2 = *(float *)(iVar4 + (uVar13 + uVar9 * 8) * 4 + (param_1 & 3) * 4);
      fVar5 = (local_58 + param_2[-2]) * _DAT_00a171ac;
      fVar6 = (local_54 + param_2[-1]) * _DAT_00a171ac;
      fVar7 = (local_50 + *param_2) * _DAT_00a171ac;
      fVar3 = param_2[1];
      local_38 = (uint)ROUND(fVar5 + fVar2);
      local_34 = (uint)ROUND(fVar6 + fVar2);
      local_30 = (int)ROUND(fVar7 + fVar2);
      iVar14 = (int)ROUND(local_4c + fVar3 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar18);
        local_58 = (fVar5 - (float)(int)local_38) * _DAT_00a171a8;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar12);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar18);
        local_58 = local_58 * (float)_DAT_00a171b8;
        local_54 = (fVar6 - (float)(int)local_34) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar12);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar18);
        local_54 = local_54 * (float)_DAT_00a171b8;
        fVar8 = (fVar7 - (float)local_30) * fVar8;
        *pfVar1 = _DAT_00a171c4 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar10);
        *pfVar1 = _DAT_00a171c0 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar12);
        *pfVar1 = DAT_009af898 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar18);
        local_50 = fVar8 * (float)_DAT_00a171b8;
        local_4c = (local_4c + fVar3) - (float)iVar14;
        *pfVar1 = _DAT_00a171c4 * local_4c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_4c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar12);
        *pfVar1 = DAT_009af898 * local_4c + *pfVar1;
        local_4c = local_4c * (float)_DAT_00a171b8;
      }
      uVar16 = local_38;
      if (0x1e < (int)local_38) {
        uVar16 = 0x1f;
      }
      if ((int)uVar16 < 1) {
        local_38 = 0;
      }
      else if (0x1e < (int)local_38) {
        local_38 = 0x1f;
      }
      uVar16 = local_34;
      if (0x1e < (int)local_34) {
        uVar16 = 0x1f;
      }
      if ((int)uVar16 < 1) {
        local_34 = 0;
      }
      else if (0x1e < (int)local_34) {
        local_34 = 0x1f;
      }
      iVar17 = local_30;
      if (0x1e < local_30) {
        iVar17 = 0x1f;
      }
      if (iVar17 < 1) {
        local_30 = 0;
      }
      else if (0x1e < local_30) {
        local_30 = 0x1f;
      }
      if (iVar14 < 1) {
        iVar17 = iVar14;
      }
      else {
        iVar17 = 1;
      }
      if (iVar17 < 1) {
        iVar14 = 0;
      }
      else if (0 < iVar14) {
        iVar14 = 1;
      }
      *local_8 = (ushort)(((iVar14 << 5 | local_38) << 5 | local_34) << 5) | (ushort)local_30;
      local_8 = local_8 + iVar15;
      param_2 = param_2 + iVar15 * 4;
      iVar10 = iVar10 + iVar11;
      iVar18 = iVar18 + iVar11;
      iVar12 = iVar12 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008ad86f @ 0x008ad86f ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008ad86f(uint param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  ushort in_FPUControlWord;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  uint local_38;
  uint local_34;
  int local_30;
  ushort *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_58 = 0.0;
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  local_8 = (ushort *)
            (*(int *)(in_ECX + 0x60) * param_1 + (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2
             + *(int *)(in_ECX + 100) * (int)param_2 + *(int *)(in_ECX + 0x20));
  uVar9 = param_1 & 3;
  uVar13 = (uint)param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar18 = 0;
    iVar15 = 1;
  }
  else {
    iVar18 = *(int *)(in_ECX + 0x68) + -1;
    iVar15 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar15 * 0x10;
    iVar10 = iVar18 * 0x10;
    param_2 = (float *)(iVar10 + 8 + param_3);
    iVar12 = (iVar15 + iVar18) * 0x10;
    iVar18 = (iVar18 - iVar15) * 0x10;
    do {
      fVar8 = _DAT_00a171c8;
      fVar2 = *(float *)(iVar3 + (uVar13 + uVar9 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_58 + param_2[-2]) * DAT_009bfa74;
      fVar5 = (local_54 + param_2[-1]) * DAT_009bfa74;
      fVar6 = (local_50 + *param_2) * DAT_009bfa74;
      fVar7 = (local_4c + param_2[1]) * DAT_009bfa74;
      local_38 = (uint)ROUND(fVar4 + fVar2);
      local_34 = (uint)ROUND(fVar5 + fVar2);
      local_30 = (int)ROUND(fVar6 + fVar2);
      iVar14 = (int)ROUND(fVar7 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar18);
        local_58 = (fVar4 - (float)(int)local_38) * _DAT_00a171c8;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar12);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar18);
        local_58 = local_58 * (float)_DAT_00a171b8;
        local_54 = (fVar5 - (float)(int)local_34) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar12);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar18);
        local_54 = local_54 * (float)_DAT_00a171b8;
        local_50 = (fVar6 - (float)local_30) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar12);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar18);
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar8 = (fVar7 - (float)iVar14) * fVar8;
        *pfVar1 = _DAT_00a171c4 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar10);
        *pfVar1 = _DAT_00a171c0 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar12);
        *pfVar1 = DAT_009af898 * fVar8 + *pfVar1;
        local_4c = fVar8 * (float)_DAT_00a171b8;
      }
      uVar16 = local_38;
      if (0xe < (int)local_38) {
        uVar16 = 0xf;
      }
      if ((int)uVar16 < 1) {
        local_38 = 0;
      }
      else if (0xe < (int)local_38) {
        local_38 = 0xf;
      }
      uVar16 = local_34;
      if (0xe < (int)local_34) {
        uVar16 = 0xf;
      }
      if ((int)uVar16 < 1) {
        local_34 = 0;
      }
      else if (0xe < (int)local_34) {
        local_34 = 0xf;
      }
      iVar17 = local_30;
      if (0xe < local_30) {
        iVar17 = 0xf;
      }
      if (iVar17 < 1) {
        local_30 = 0;
      }
      else if (0xe < local_30) {
        local_30 = 0xf;
      }
      if (iVar14 < 0xf) {
        iVar17 = iVar14;
      }
      else {
        iVar17 = 0xf;
      }
      if (iVar17 < 1) {
        iVar14 = 0;
      }
      else if (0xe < iVar14) {
        iVar14 = 0xf;
      }
      *local_8 = (ushort)(((iVar14 << 4 | local_38) << 4 | local_34) << 4) | (ushort)local_30;
      local_8 = local_8 + iVar15;
      param_2 = param_2 + iVar15 * 4;
      iVar10 = iVar10 + iVar11;
      iVar18 = iVar18 + iVar11;
      iVar12 = iVar12 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008adbff @ 0x008adbff ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008adbff(uint param_1,uint param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  undefined2 in_FPUControlWord;
  float local_58;
  float local_54;
  float local_50;
  int local_34;
  int local_30;
  byte *local_10;
  int local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_58 = 0.0;
  local_54 = 0.0;
  local_50 = 0.0;
  uVar8 = param_1 & 3;
  uVar10 = param_2 & 3;
  local_10 = (byte *)((*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) +
                      *(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
                     *(int *)(in_ECX + 0x20));
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    local_8 = 0;
    param_1 = 1;
  }
  else {
    local_8 = *(int *)(in_ECX + 0x68) + -1;
    param_1 = -1;
  }
  param_2 = CONCAT22(param_2._2_2_,in_FPUControlWord);
  *(uint *)(in_ECX + 0x7c) = param_2;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_2 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = param_1 * 0x10;
    iVar9 = local_8 * 0x10;
    iVar14 = (param_1 + local_8) * 0x10;
    local_8 = (local_8 - param_1) * 0x10;
    param_3 = (float *)(iVar9 + 8 + (int)param_3);
    do {
      fVar7 = _DAT_00a171cc;
      fVar2 = *(float *)(iVar3 + (uVar10 + uVar8 * 8) * 4 + (param_2 & 3) * 4);
      fVar4 = (local_58 + param_3[-2]) * _DAT_009b0ec0;
      fVar5 = (local_54 + param_3[-1]) * _DAT_009b0ec0;
      fVar6 = (local_50 + *param_3) * DAT_009b0300;
      iVar12 = (int)ROUND(fVar4 + fVar2);
      local_34 = (int)ROUND(fVar5 + fVar2);
      local_30 = (int)ROUND(fVar6 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + local_8);
        local_58 = (fVar4 - (float)iVar12) * _DAT_00a171cc;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar14);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + local_8);
        local_58 = local_58 * (float)_DAT_00a171b8;
        fVar7 = (fVar5 - (float)local_34) * fVar7;
        *pfVar1 = _DAT_00a171c4 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar9);
        *pfVar1 = _DAT_00a171c0 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar14);
        *pfVar1 = DAT_009af898 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + local_8);
        local_54 = fVar7 * (float)_DAT_00a171b8;
        local_50 = (fVar6 - (float)local_30) * _DAT_009fc7c8;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar14);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        local_50 = local_50 * (float)_DAT_00a171b8;
      }
      if (iVar12 < 7) {
        iVar13 = iVar12;
      }
      else {
        iVar13 = 7;
      }
      if (iVar13 < 1) {
        iVar12 = 0;
      }
      else if (6 < iVar12) {
        iVar12 = 7;
      }
      if (local_34 < 7) {
        iVar13 = local_34;
      }
      else {
        iVar13 = 7;
      }
      if (iVar13 < 1) {
        local_34 = 0;
      }
      else if (6 < local_34) {
        local_34 = 7;
      }
      if (local_30 < 3) {
        iVar13 = local_30;
      }
      else {
        iVar13 = 3;
      }
      if (iVar13 < 1) {
        local_30 = 0;
      }
      else if (2 < local_30) {
        local_30 = 3;
      }
      *local_10 = ((char)iVar12 << 3 | (byte)local_34) << 2 | (byte)local_30;
      local_10 = local_10 + param_1;
      param_3 = param_3 + param_1 * 4;
      local_8 = local_8 + iVar11;
      iVar9 = iVar9 + iVar11;
      iVar14 = iVar14 + iVar11;
      param_2 = param_2 + 1;
    } while (param_2 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008adf14 @ 0x008adf14 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008adf14(uint param_1,uint param_2,float *param_3)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined2 in_FPUControlWord;
  float local_2c;
  int local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_2c = 0.0;
  uVar4 = param_1 & 3;
  uVar6 = param_2 & 3;
  iVar2 = *(int *)(in_ECX + 0x34);
  puVar11 = (undefined1 *)
            ((*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) + *(int *)(in_ECX + 0x60) * param_1 +
             *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  if ((param_1 & 1) == 0) {
    iVar9 = 0;
    param_1 = 1;
  }
  else {
    iVar9 = *(int *)(in_ECX + 0x68) + -1;
    param_1 = -1;
  }
  param_2 = CONCAT22(param_2._2_2_,in_FPUControlWord);
  *(uint *)(in_ECX + 0x7c) = param_2;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_2 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar7 = param_1 * 0x10;
    iVar5 = iVar9 * 0x10;
    iVar8 = (param_1 + iVar9) * 0x10;
    local_8 = (iVar9 - param_1) * 0x10;
    param_3 = (float *)(iVar5 + 0xc + (int)param_3);
    do {
      fVar3 = (local_2c + *param_3) * DAT_0099d0b8;
      iVar9 = (int)ROUND(fVar3 + *(float *)(iVar2 + (uVar6 + uVar4 * 8) * 4 + (param_2 & 3) * 4));
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(local_8 + 0x1c + *(int *)(in_ECX + 0x5c));
        local_2c = (fVar3 - (float)iVar9) * DAT_0099d0b0;
        *pfVar1 = _DAT_00a171c4 * local_2c + *pfVar1;
        pfVar1 = (float *)(iVar5 + 0x1c + *(int *)(in_ECX + 0x5c));
        *pfVar1 = _DAT_00a171c0 * local_2c + *pfVar1;
        pfVar1 = (float *)(iVar8 + 0x1c + *(int *)(in_ECX + 0x5c));
        *pfVar1 = DAT_009af898 * local_2c + *pfVar1;
        local_2c = local_2c * (float)_DAT_00a171b8;
      }
      iVar10 = iVar9;
      if (0xfe < iVar9) {
        iVar10 = 0xff;
      }
      if (iVar10 < 1) {
        iVar9 = 0;
      }
      else if (0xfe < iVar9) {
        iVar9 = 0xff;
      }
      *puVar11 = (char)iVar9;
      param_3 = param_3 + param_1 * 4;
      local_8 = local_8 + iVar7;
      puVar11 = puVar11 + param_1;
      iVar5 = iVar5 + iVar7;
      iVar8 = iVar8 + iVar7;
      param_2 = param_2 + 1;
    } while (param_2 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008ae0d5 @ 0x008ae0d5 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008ae0d5(uint param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  int iVar18;
  ushort in_FPUControlWord;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  uint local_38;
  uint local_34;
  int local_30;
  ushort *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_58 = 0.0;
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  local_8 = (ushort *)
            (*(int *)(in_ECX + 0x60) * param_1 + (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2
             + *(int *)(in_ECX + 100) * (int)param_2 + *(int *)(in_ECX + 0x20));
  uVar9 = param_1 & 3;
  uVar13 = (uint)param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar18 = 0;
    iVar14 = 1;
  }
  else {
    iVar18 = *(int *)(in_ECX + 0x68) + -1;
    iVar14 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar14 * 0x10;
    iVar10 = iVar18 * 0x10;
    iVar12 = (iVar14 + iVar18) * 0x10;
    iVar18 = (iVar18 - iVar14) * 0x10;
    param_2 = (float *)(iVar10 + 8 + param_3);
    do {
      fVar8 = _DAT_00a171cc;
      fVar2 = *(float *)(iVar3 + (uVar13 + uVar9 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_58 + param_2[-2]) * _DAT_009b0ec0;
      fVar5 = (local_54 + param_2[-1]) * _DAT_009b0ec0;
      fVar6 = (local_50 + *param_2) * DAT_009b0300;
      fVar7 = (local_4c + param_2[1]) * DAT_0099d0b8;
      local_38 = (uint)ROUND(fVar4 + fVar2);
      local_34 = (uint)ROUND(fVar5 + fVar2);
      local_30 = (int)ROUND(fVar6 + fVar2);
      iVar17 = (int)ROUND(fVar7 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar18);
        local_58 = (fVar4 - (float)(int)local_38) * _DAT_00a171cc;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar12);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar18);
        local_58 = local_58 * (float)_DAT_00a171b8;
        fVar8 = (fVar5 - (float)(int)local_34) * fVar8;
        *pfVar1 = _DAT_00a171c4 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar10);
        *pfVar1 = _DAT_00a171c0 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar12);
        *pfVar1 = DAT_009af898 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar18);
        local_54 = fVar8 * (float)_DAT_00a171b8;
        local_50 = (fVar6 - (float)local_30) * _DAT_009fc7c8;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar12);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar18);
        local_50 = local_50 * (float)_DAT_00a171b8;
        local_4c = (fVar7 - (float)iVar17) * DAT_0099d0b0;
        *pfVar1 = _DAT_00a171c4 * local_4c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_4c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar12);
        *pfVar1 = DAT_009af898 * local_4c + *pfVar1;
        local_4c = local_4c * (float)_DAT_00a171b8;
      }
      if ((int)local_38 < 7) {
        uVar15 = local_38;
      }
      else {
        uVar15 = 7;
      }
      if ((int)uVar15 < 1) {
        local_38 = 0;
      }
      else if (6 < (int)local_38) {
        local_38 = 7;
      }
      uVar15 = local_34;
      if (6 < (int)local_34) {
        uVar15 = 7;
      }
      if ((int)uVar15 < 1) {
        local_34 = 0;
      }
      else if (6 < (int)local_34) {
        local_34 = 7;
      }
      iVar16 = local_30;
      if (2 < local_30) {
        iVar16 = 3;
      }
      if (iVar16 < 1) {
        local_30 = 0;
      }
      else if (2 < local_30) {
        local_30 = 3;
      }
      iVar16 = iVar17;
      if (0xfe < iVar17) {
        iVar16 = 0xff;
      }
      if (iVar16 < 1) {
        iVar17 = 0;
      }
      else if (0xfe < iVar17) {
        iVar17 = 0xff;
      }
      *local_8 = (ushort)(((iVar17 << 3 | local_38) << 3 | local_34) << 2) | (ushort)local_30;
      local_8 = local_8 + iVar14;
      param_2 = param_2 + iVar14 * 4;
      iVar10 = iVar10 + iVar11;
      iVar18 = iVar18 + iVar11;
      iVar12 = iVar12 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008ae46d @ 0x008ae46d ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008ae46d(uint param_1,uint param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  ushort in_FPUControlWord;
  float local_54;
  float local_50;
  float local_4c;
  uint local_30;
  int local_2c;
  ushort *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  uVar8 = param_1 & 3;
  local_8 = (ushort *)
            (*(int *)(in_ECX + 0x60) * param_1 + (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 2
             + *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar14 = 0;
    iVar13 = 1;
  }
  else {
    iVar14 = *(int *)(in_ECX + 0x68) + -1;
    iVar13 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar10 = iVar13 * 0x10;
    iVar9 = iVar14 * 0x10;
    iVar11 = (iVar13 + iVar14) * 0x10;
    iVar14 = (iVar14 - iVar13) * 0x10;
    param_3 = (float *)(iVar9 + 8 + (int)param_3);
    do {
      fVar7 = _DAT_00a171c8;
      fVar2 = *(float *)(iVar3 + ((param_2 & 3) + uVar8 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_54 + param_3[-2]) * DAT_009bfa74;
      fVar5 = (local_50 + param_3[-1]) * DAT_009bfa74;
      fVar6 = (local_4c + *param_3) * DAT_009bfa74;
      iVar12 = (int)ROUND(fVar4 + fVar2);
      local_30 = (uint)ROUND(fVar5 + fVar2);
      local_2c = (int)ROUND(fVar6 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar14);
        local_54 = (fVar4 - (float)iVar12) * _DAT_00a171c8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar11);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar14);
        local_54 = local_54 * (float)_DAT_00a171b8;
        local_50 = (fVar5 - (float)(int)local_30) * fVar7;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar11);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar14);
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar7 = (fVar6 - (float)local_2c) * fVar7;
        *pfVar1 = _DAT_00a171c4 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar9);
        *pfVar1 = _DAT_00a171c0 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar11);
        *pfVar1 = DAT_009af898 * fVar7 + *pfVar1;
        local_4c = fVar7 * (float)_DAT_00a171b8;
      }
      if (iVar12 < 0xf) {
        iVar16 = iVar12;
      }
      else {
        iVar16 = 0xf;
      }
      if (iVar16 < 1) {
        iVar12 = 0;
      }
      else if (0xe < iVar12) {
        iVar12 = 0xf;
      }
      uVar15 = local_30;
      if (0xe < (int)local_30) {
        uVar15 = 0xf;
      }
      if ((int)uVar15 < 1) {
        local_30 = 0;
      }
      else if (0xe < (int)local_30) {
        local_30 = 0xf;
      }
      iVar16 = local_2c;
      if (0xe < local_2c) {
        iVar16 = 0xf;
      }
      if (iVar16 < 1) {
        local_2c = 0;
      }
      else if (0xe < local_2c) {
        local_2c = 0xf;
      }
      *local_8 = (ushort)((iVar12 << 4 | local_30) << 4) | (ushort)local_2c;
      local_8 = local_8 + iVar13;
      param_3 = param_3 + iVar13 * 4;
      iVar9 = iVar9 + iVar10;
      iVar14 = iVar14 + iVar10;
      iVar11 = iVar11 + iVar10;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008ae76c @ 0x008ae76c ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008ae76c(uint param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  ushort in_FPUControlWord;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_58 = 0.0;
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
                     *(int *)(in_ECX + 100) * (int)param_2 + *(int *)(in_ECX + 0x20));
  uVar9 = param_1 & 3;
  uVar13 = (uint)param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar18 = 0;
    iVar15 = 1;
  }
  else {
    iVar18 = *(int *)(in_ECX + 0x68) + -1;
    iVar15 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar15 * 0x10;
    iVar10 = iVar18 * 0x10;
    param_2 = (float *)(iVar10 + 8 + param_3);
    iVar12 = (iVar15 + iVar18) * 0x10;
    iVar18 = (iVar18 - iVar15) * 0x10;
    do {
      fVar8 = _DAT_00a171d0;
      fVar2 = *(float *)(iVar3 + (uVar13 + uVar9 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_58 + param_2[-2]) * _DAT_00a171d4;
      fVar5 = (local_54 + param_2[-1]) * _DAT_00a171d4;
      fVar6 = (local_50 + *param_2) * _DAT_00a171d4;
      fVar7 = (local_4c + param_2[1]) * DAT_009b0300;
      local_38 = (uint)ROUND(fVar4 + fVar2);
      local_34 = (uint)ROUND(fVar5 + fVar2);
      local_30 = (uint)ROUND(fVar6 + fVar2);
      iVar14 = (int)ROUND(fVar7 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar18);
        local_58 = (fVar4 - (float)(int)local_38) * _DAT_00a171d0;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar12);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar18);
        local_58 = local_58 * (float)_DAT_00a171b8;
        local_54 = (fVar5 - (float)(int)local_34) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar12);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar18);
        local_54 = local_54 * (float)_DAT_00a171b8;
        fVar8 = (fVar6 - (float)(int)local_30) * fVar8;
        *pfVar1 = _DAT_00a171c4 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar10);
        *pfVar1 = _DAT_00a171c0 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar12);
        *pfVar1 = DAT_009af898 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar18);
        local_50 = fVar8 * (float)_DAT_00a171b8;
        local_4c = (fVar7 - (float)iVar14) * _DAT_009fc7c8;
        *pfVar1 = _DAT_00a171c4 * local_4c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_4c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar12);
        *pfVar1 = DAT_009af898 * local_4c + *pfVar1;
        local_4c = local_4c * (float)_DAT_00a171b8;
      }
      uVar16 = local_38;
      if (0x3fe < (int)local_38) {
        uVar16 = 0x3ff;
      }
      if ((int)uVar16 < 1) {
        local_38 = 0;
      }
      else if (0x3fe < (int)local_38) {
        local_38 = 0x3ff;
      }
      uVar16 = local_34;
      if (0x3fe < (int)local_34) {
        uVar16 = 0x3ff;
      }
      if ((int)uVar16 < 1) {
        local_34 = 0;
      }
      else if (0x3fe < (int)local_34) {
        local_34 = 0x3ff;
      }
      uVar16 = local_30;
      if (0x3fe < (int)local_30) {
        uVar16 = 0x3ff;
      }
      if ((int)uVar16 < 1) {
        local_30 = 0;
      }
      else if (0x3fe < (int)local_30) {
        local_30 = 0x3ff;
      }
      if (iVar14 < 3) {
        iVar17 = iVar14;
      }
      else {
        iVar17 = 3;
      }
      if (iVar17 < 1) {
        iVar14 = 0;
      }
      else if (2 < iVar14) {
        iVar14 = 3;
      }
      *local_8 = ((iVar14 << 10 | local_30) << 10 | local_34) << 10 | local_38;
      local_8 = local_8 + iVar15;
      param_2 = param_2 + iVar15 * 4;
      iVar10 = iVar10 + iVar11;
      iVar18 = iVar18 + iVar11;
      iVar12 = iVar12 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008aeb21 @ 0x008aeb21 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008aeb21(uint param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  ushort in_FPUControlWord;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_58 = 0.0;
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
                     *(int *)(in_ECX + 100) * (int)param_2 + *(int *)(in_ECX + 0x20));
  uVar9 = param_1 & 3;
  uVar13 = (uint)param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar18 = 0;
    iVar15 = 1;
  }
  else {
    iVar18 = *(int *)(in_ECX + 0x68) + -1;
    iVar15 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar15 * 0x10;
    iVar10 = iVar18 * 0x10;
    param_2 = (float *)(iVar10 + 8 + param_3);
    iVar12 = (iVar15 + iVar18) * 0x10;
    iVar18 = (iVar18 - iVar15) * 0x10;
    do {
      fVar8 = DAT_0099d0b0;
      fVar2 = *(float *)(iVar3 + (uVar13 + uVar9 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_58 + param_2[-2]) * DAT_0099d0b8;
      fVar5 = (local_54 + param_2[-1]) * DAT_0099d0b8;
      fVar6 = (local_50 + *param_2) * DAT_0099d0b8;
      fVar7 = (local_4c + param_2[1]) * DAT_0099d0b8;
      local_38 = (uint)ROUND(fVar4 + fVar2);
      local_34 = (uint)ROUND(fVar5 + fVar2);
      local_30 = (uint)ROUND(fVar6 + fVar2);
      iVar14 = (int)ROUND(fVar7 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar18);
        local_58 = (fVar4 - (float)(int)local_38) * DAT_0099d0b0;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar12);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar18);
        local_58 = local_58 * (float)_DAT_00a171b8;
        local_54 = (fVar5 - (float)(int)local_34) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar12);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar18);
        local_54 = local_54 * (float)_DAT_00a171b8;
        local_50 = (fVar6 - (float)(int)local_30) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar12);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar18);
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar8 = (fVar7 - (float)iVar14) * fVar8;
        *pfVar1 = _DAT_00a171c4 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar10);
        *pfVar1 = _DAT_00a171c0 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar12);
        *pfVar1 = DAT_009af898 * fVar8 + *pfVar1;
        local_4c = fVar8 * (float)_DAT_00a171b8;
      }
      uVar16 = local_38;
      if (0xfe < (int)local_38) {
        uVar16 = 0xff;
      }
      if ((int)uVar16 < 1) {
        local_38 = 0;
      }
      else if (0xfe < (int)local_38) {
        local_38 = 0xff;
      }
      uVar16 = local_34;
      if (0xfe < (int)local_34) {
        uVar16 = 0xff;
      }
      if ((int)uVar16 < 1) {
        local_34 = 0;
      }
      else if (0xfe < (int)local_34) {
        local_34 = 0xff;
      }
      uVar16 = local_30;
      if (0xfe < (int)local_30) {
        uVar16 = 0xff;
      }
      if ((int)uVar16 < 1) {
        local_30 = 0;
      }
      else if (0xfe < (int)local_30) {
        local_30 = 0xff;
      }
      iVar17 = iVar14;
      if (0xfe < iVar14) {
        iVar17 = 0xff;
      }
      if (iVar17 < 1) {
        iVar14 = 0;
      }
      else if (0xfe < iVar14) {
        iVar14 = 0xff;
      }
      *local_8 = ((iVar14 << 8 | local_30) << 8 | local_34) << 8 | local_38;
      local_8 = local_8 + iVar15;
      param_2 = param_2 + iVar15 * 4;
      iVar10 = iVar10 + iVar11;
      iVar18 = iVar18 + iVar11;
      iVar12 = iVar12 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008aeed0 @ 0x008aeed0 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008aeed0(uint param_1,uint param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  ushort in_FPUControlWord;
  float local_54;
  float local_50;
  float local_4c;
  uint local_34;
  uint local_30;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  uVar8 = param_1 & 3;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
                     *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar14 = 0;
    iVar13 = 1;
  }
  else {
    iVar14 = *(int *)(in_ECX + 0x68) + -1;
    iVar13 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar10 = iVar13 * 0x10;
    iVar9 = iVar14 * 0x10;
    iVar11 = (iVar13 + iVar14) * 0x10;
    iVar14 = (iVar14 - iVar13) * 0x10;
    param_3 = (float *)(iVar9 + 8 + (int)param_3);
    do {
      fVar7 = DAT_0099d0b0;
      fVar2 = *(float *)(iVar3 + ((param_2 & 3) + uVar8 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_54 + param_3[-2]) * DAT_0099d0b8;
      fVar5 = (local_50 + param_3[-1]) * DAT_0099d0b8;
      fVar6 = (local_4c + *param_3) * DAT_0099d0b8;
      local_34 = (uint)ROUND(fVar4 + fVar2);
      local_30 = (uint)ROUND(fVar5 + fVar2);
      iVar12 = (int)ROUND(fVar6 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar14);
        local_54 = (fVar4 - (float)(int)local_34) * DAT_0099d0b0;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar11);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar14);
        local_54 = local_54 * (float)_DAT_00a171b8;
        local_50 = (fVar5 - (float)(int)local_30) * fVar7;
        *pfVar1 = _DAT_00a171c4 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar9);
        *pfVar1 = _DAT_00a171c0 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar11);
        *pfVar1 = DAT_009af898 * local_50 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar14);
        local_50 = local_50 * (float)_DAT_00a171b8;
        fVar7 = (fVar6 - (float)iVar12) * fVar7;
        *pfVar1 = _DAT_00a171c4 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar9);
        *pfVar1 = _DAT_00a171c0 * fVar7 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar11);
        *pfVar1 = DAT_009af898 * fVar7 + *pfVar1;
        local_4c = fVar7 * (float)_DAT_00a171b8;
      }
      uVar15 = local_34;
      if (0xfe < (int)local_34) {
        uVar15 = 0xff;
      }
      if ((int)uVar15 < 1) {
        local_34 = 0;
      }
      else if (0xfe < (int)local_34) {
        local_34 = 0xff;
      }
      uVar15 = local_30;
      if (0xfe < (int)local_30) {
        uVar15 = 0xff;
      }
      if ((int)uVar15 < 1) {
        local_30 = 0;
      }
      else if (0xfe < (int)local_30) {
        local_30 = 0xff;
      }
      iVar16 = iVar12;
      if (0xfe < iVar12) {
        iVar16 = 0xff;
      }
      if (iVar16 < 1) {
        iVar12 = 0;
      }
      else if (0xfe < iVar12) {
        iVar12 = 0xff;
      }
      *local_8 = (iVar12 << 8 | local_30) << 8 | local_34;
      local_8 = local_8 + iVar13;
      param_3 = param_3 + iVar13 * 4;
      iVar9 = iVar9 + iVar10;
      iVar14 = iVar14 + iVar10;
      iVar11 = iVar11 + iVar10;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008af1e6 @ 0x008af1e6 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008af1e6(uint param_1,uint param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  uint uVar8;
  int iVar9;
  int in_ECX;
  uint uVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  int iVar15;
  ushort in_FPUControlWord;
  float local_54;
  float local_50;
  uint local_34;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_54 = 0.0;
  local_50 = 0.0;
  uVar8 = param_1 & 3;
  uVar10 = param_2 & 3;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
                     *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar13 = 0;
    param_2 = 1;
  }
  else {
    iVar13 = *(int *)(in_ECX + 0x68) + -1;
    param_2 = -1;
  }
  iVar7 = param_2;
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = param_2 * 0x10;
    iVar9 = iVar13 << 4;
    iVar12 = (param_2 + iVar13) * 0x10;
    param_2 = (iVar13 - param_2) * 0x10;
    do {
      fVar6 = _DAT_00a171d8;
      fVar2 = *(float *)(iVar3 + (uVar10 + uVar8 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_54 + *(float *)(param_3 + iVar9)) * _DAT_00a16814;
      fVar5 = (local_50 + ((float *)(param_3 + iVar9))[1]) * _DAT_00a16814;
      local_34 = (uint)ROUND(fVar4 + fVar2);
      iVar13 = (int)ROUND(fVar5 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(param_2 + 0x10 + *(int *)(in_ECX + 0x5c));
        local_54 = (fVar4 - (float)(int)local_34) * _DAT_00a171d8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(iVar9 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(iVar12 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(param_2 + 0x14 + *(int *)(in_ECX + 0x5c));
        local_54 = local_54 * (float)_DAT_00a171b8;
        fVar6 = (fVar5 - (float)iVar13) * fVar6;
        *pfVar1 = _DAT_00a171c4 * fVar6 + *pfVar1;
        pfVar1 = (float *)(iVar9 + 0x14 + *(int *)(in_ECX + 0x5c));
        *pfVar1 = _DAT_00a171c0 * fVar6 + *pfVar1;
        pfVar1 = (float *)(iVar12 + 0x14 + *(int *)(in_ECX + 0x5c));
        *pfVar1 = DAT_009af898 * fVar6 + *pfVar1;
        local_50 = fVar6 * (float)_DAT_00a171b8;
      }
      uVar14 = local_34;
      if (0xfffe < (int)local_34) {
        uVar14 = 0xffff;
      }
      if ((int)uVar14 < 1) {
        local_34 = 0;
      }
      else if (0xfffe < (int)local_34) {
        local_34 = 0xffff;
      }
      iVar15 = iVar13;
      if (0xfffe < iVar13) {
        iVar15 = 0xffff;
      }
      if (iVar15 < 1) {
        iVar13 = 0;
      }
      else if (0xfffe < iVar13) {
        iVar13 = 0xffff;
      }
      *local_8 = iVar13 << 0x10 | local_34;
      local_8 = local_8 + iVar7;
      param_2 = param_2 + iVar11;
      iVar9 = iVar9 + iVar11;
      iVar12 = iVar12 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008af45b @ 0x008af45b ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008af45b(uint param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  int iVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  int iVar18;
  ushort in_FPUControlWord;
  float local_58;
  float local_54;
  float local_50;
  float local_4c;
  uint local_38;
  uint local_34;
  uint local_30;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_58 = 0.0;
  local_54 = 0.0;
  local_50 = 0.0;
  local_4c = 0.0;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 4 +
                     *(int *)(in_ECX + 100) * (int)param_2 + *(int *)(in_ECX + 0x20));
  uVar9 = param_1 & 3;
  uVar13 = (uint)param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar18 = 0;
    iVar15 = 1;
  }
  else {
    iVar18 = *(int *)(in_ECX + 0x68) + -1;
    iVar15 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar11 = iVar15 * 0x10;
    iVar10 = iVar18 * 0x10;
    param_2 = (float *)(iVar10 + 8 + param_3);
    iVar12 = (iVar15 + iVar18) * 0x10;
    iVar18 = (iVar18 - iVar15) * 0x10;
    do {
      fVar8 = _DAT_00a171d0;
      fVar2 = *(float *)(iVar3 + (uVar13 + uVar9 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_58 + param_2[-2]) * _DAT_00a171d4;
      fVar5 = (local_54 + param_2[-1]) * _DAT_00a171d4;
      fVar6 = (local_50 + *param_2) * _DAT_00a171d4;
      fVar7 = (local_4c + param_2[1]) * DAT_009b0300;
      local_38 = (uint)ROUND(fVar4 + fVar2);
      local_34 = (uint)ROUND(fVar5 + fVar2);
      local_30 = (uint)ROUND(fVar6 + fVar2);
      iVar14 = (int)ROUND(fVar7 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar18);
        local_58 = (fVar4 - (float)(int)local_38) * _DAT_00a171d0;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar12);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar18);
        local_58 = local_58 * (float)_DAT_00a171b8;
        local_54 = (fVar5 - (float)(int)local_34) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar12);
        *pfVar1 = DAT_009af898 * local_54 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar18);
        local_54 = local_54 * (float)_DAT_00a171b8;
        fVar8 = (fVar6 - (float)(int)local_30) * fVar8;
        *pfVar1 = _DAT_00a171c4 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar10);
        *pfVar1 = _DAT_00a171c0 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar12);
        *pfVar1 = DAT_009af898 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar18);
        local_50 = fVar8 * (float)_DAT_00a171b8;
        local_4c = (fVar7 - (float)iVar14) * _DAT_009fc7c8;
        *pfVar1 = _DAT_00a171c4 * local_4c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar10);
        *pfVar1 = _DAT_00a171c0 * local_4c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar12);
        *pfVar1 = DAT_009af898 * local_4c + *pfVar1;
        local_4c = local_4c * (float)_DAT_00a171b8;
      }
      uVar16 = local_38;
      if (0x3fe < (int)local_38) {
        uVar16 = 0x3ff;
      }
      if ((int)uVar16 < 1) {
        local_38 = 0;
      }
      else if (0x3fe < (int)local_38) {
        local_38 = 0x3ff;
      }
      uVar16 = local_34;
      if (0x3fe < (int)local_34) {
        uVar16 = 0x3ff;
      }
      if ((int)uVar16 < 1) {
        local_34 = 0;
      }
      else if (0x3fe < (int)local_34) {
        local_34 = 0x3ff;
      }
      uVar16 = local_30;
      if (0x3fe < (int)local_30) {
        uVar16 = 0x3ff;
      }
      if ((int)uVar16 < 1) {
        local_30 = 0;
      }
      else if (0x3fe < (int)local_30) {
        local_30 = 0x3ff;
      }
      if (iVar14 < 3) {
        iVar17 = iVar14;
      }
      else {
        iVar17 = 3;
      }
      if (iVar17 < 1) {
        iVar14 = 0;
      }
      else if (2 < iVar14) {
        iVar14 = 3;
      }
      *local_8 = ((iVar14 << 10 | local_38) << 10 | local_34) << 10 | local_30;
      local_8 = local_8 + iVar15;
      param_2 = param_2 + iVar15 * 4;
      iVar10 = iVar10 + iVar11;
      iVar18 = iVar18 + iVar11;
      iVar12 = iVar12 + iVar11;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008af810 @ 0x008af810 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008af810(uint param_1,float *param_2,int param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  uint uVar9;
  int iVar10;
  int in_ECX;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  int iVar15;
  ushort in_FPUControlWord;
  float local_60;
  float local_5c;
  float local_58;
  float local_54;
  uint local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  int local_10;
  int local_c;
  uint *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  local_60 = 0.0;
  local_5c = 0.0;
  local_58 = 0.0;
  local_54 = 0.0;
  local_8 = (uint *)(*(int *)(in_ECX + 0x60) * param_1 +
                     (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) * 8 +
                     *(int *)(in_ECX + 100) * (int)param_2 + *(int *)(in_ECX + 0x20));
  uVar9 = param_1 & 3;
  uVar12 = (uint)param_2 & 3;
  iVar3 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar15 = 0;
    iVar14 = 1;
  }
  else {
    iVar15 = *(int *)(in_ECX + 0x68) + -1;
    iVar14 = -1;
  }
  param_1 = (uint)in_FPUControlWord;
  *(uint *)(in_ECX + 0x7c) = param_1;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar10 = iVar14 * 0x10;
    iVar11 = iVar15 * 0x10;
    local_10 = (iVar14 + iVar15) * 0x10;
    local_c = (iVar15 - iVar14) * 0x10;
    param_2 = (float *)(iVar11 + 8 + param_3);
    do {
      fVar8 = _DAT_00a171d8;
      fVar2 = *(float *)(iVar3 + (uVar12 + uVar9 * 8) * 4 + (param_1 & 3) * 4);
      fVar4 = (local_60 + param_2[-2]) * _DAT_00a16814;
      fVar5 = (local_5c + param_2[-1]) * _DAT_00a16814;
      fVar6 = (local_58 + *param_2) * _DAT_00a16814;
      fVar7 = (local_54 + param_2[1]) * _DAT_00a16814;
      local_40 = (uint)ROUND(fVar4 + fVar2);
      local_3c = (uint)ROUND(fVar5 + fVar2);
      local_38 = (uint)ROUND(fVar6 + fVar2);
      local_34 = (int)ROUND(fVar7 + fVar2);
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + local_c);
        local_60 = (fVar4 - (float)(int)local_40) * _DAT_00a171d8;
        *pfVar1 = _DAT_00a171c4 * local_60 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + iVar11);
        *pfVar1 = _DAT_00a171c0 * local_60 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x10 + local_10);
        *pfVar1 = DAT_009af898 * local_60 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + local_c);
        local_60 = local_60 * (float)_DAT_00a171b8;
        local_5c = (fVar5 - (float)(int)local_3c) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_5c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + iVar11);
        *pfVar1 = _DAT_00a171c0 * local_5c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x14 + local_10);
        *pfVar1 = DAT_009af898 * local_5c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + local_c);
        local_5c = local_5c * (float)_DAT_00a171b8;
        local_58 = (fVar6 - (float)(int)local_38) * fVar8;
        *pfVar1 = _DAT_00a171c4 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + iVar11);
        *pfVar1 = _DAT_00a171c0 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x18 + local_10);
        *pfVar1 = DAT_009af898 * local_58 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + local_c);
        local_58 = local_58 * (float)_DAT_00a171b8;
        fVar8 = (fVar7 - (float)local_34) * fVar8;
        *pfVar1 = _DAT_00a171c4 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar11);
        *pfVar1 = _DAT_00a171c0 * fVar8 + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + local_10);
        *pfVar1 = DAT_009af898 * fVar8 + *pfVar1;
        local_54 = fVar8 * (float)_DAT_00a171b8;
      }
      uVar13 = local_40;
      if (0xfffe < (int)local_40) {
        uVar13 = 0xffff;
      }
      if ((int)uVar13 < 1) {
        local_40 = 0;
      }
      else if (0xfffe < (int)local_40) {
        local_40 = 0xffff;
      }
      uVar13 = local_3c;
      if (0xfffe < (int)local_3c) {
        uVar13 = 0xffff;
      }
      if ((int)uVar13 < 1) {
        local_3c = 0;
      }
      else if (0xfffe < (int)local_3c) {
        local_3c = 0xffff;
      }
      uVar13 = local_38;
      if (0xfffe < (int)local_38) {
        uVar13 = 0xffff;
      }
      if ((int)uVar13 < 1) {
        local_38 = 0;
      }
      else if (0xfffe < (int)local_38) {
        local_38 = 0xffff;
      }
      iVar15 = local_34;
      if (0xfffe < local_34) {
        iVar15 = 0xffff;
      }
      if (iVar15 < 1) {
        local_34 = 0;
      }
      else if (0xfffe < local_34) {
        local_34 = 0xffff;
      }
      *local_8 = local_3c << 0x10 | local_40;
      local_8[1] = ((local_34 << 0x10 | local_38) >> 0x10 | (int)local_3c >> 0x1f) << 0x10 |
                   (local_38 << 0x10 | local_3c) >> 0x10 | (int)local_40 >> 0x1f;
      local_8 = local_8 + iVar14 * 2;
      param_2 = param_2 + iVar14 * 4;
      local_c = local_c + iVar10;
      local_10 = local_10 + iVar10;
      iVar11 = iVar11 + iVar10;
      param_1 = param_1 + 1;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008afbc7 @ 0x008afbc7 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008afbc7(float *param_1,uint param_2,uint param_3)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int in_ECX;
  uint uVar9;
  int iVar10;
  uint uVar11;
  ushort *puVar12;
  int iVar13;
  undefined2 in_FPUControlWord;
  float local_3c;
  int local_1c;
  uint local_18;
  float local_14;
  float *local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  iVar5 = param_3;
  local_3c = 0.0;
  uVar6 = (uint)param_1 & 3;
  uVar9 = param_2 & 3;
  iVar2 = *(int *)(in_ECX + 0x34);
  puVar12 = (ushort *)
            (*(int *)(in_ECX + 0x60) * (int)param_1 +
             (*(int *)(in_ECX + 0x68) + -1) * ((uint)param_1 & 1) * 2 +
             *(int *)(in_ECX + 100) * param_2 + *(int *)(in_ECX + 0x20));
  if (((uint)param_1 & 1) == 0) {
    iVar13 = 0;
    param_1 = (float *)0x1;
  }
  else {
    iVar13 = *(int *)(in_ECX + 0x68) + -1;
    param_1 = (float *)0xffffffff;
  }
  iVar4 = (int)param_1;
  param_2 = CONCAT22(param_2._2_2_,in_FPUControlWord);
  *(uint *)(in_ECX + 0x7c) = param_2;
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_2 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar7 = (int)param_1 * 0x10;
    iVar10 = (int)param_1 + iVar13;
    local_1c = (iVar13 - (int)param_1) * 0x10;
    param_1 = (float *)(iVar13 * 0x10 + 8 + param_3);
    iVar10 = iVar10 * 0x10;
    do {
      local_8 = *(float **)(in_ECX + 0x38);
      local_18 = 0;
      param_3 = 0;
      local_14 = 3.4028235e+38;
      do {
        fVar3 = (param_1[-2] - *local_8) * (param_1[-2] - *local_8) +
                (param_1[-1] - local_8[1]) * (param_1[-1] - local_8[1]) +
                (*param_1 - local_8[2]) * (*param_1 - local_8[2]);
        if (fVar3 < local_14) {
          local_18 = param_3;
          local_14 = fVar3;
        }
        param_3 = param_3 + 1;
        local_8 = local_8 + 4;
      } while (param_3 < 0x100);
      fVar3 = (local_3c + param_1[1]) * DAT_0099d0b8;
      uVar8 = (uint)ROUND(fVar3 + *(float *)(iVar2 + (uVar9 + uVar6 * 8) * 4 + (param_2 & 3) * 4));
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + local_1c);
        local_3c = (fVar3 - (float)(int)uVar8) * DAT_0099d0b0;
        *pfVar1 = _DAT_00a171c4 * local_3c + *pfVar1;
        pfVar1 = (float *)((*(int *)(in_ECX + 0x5c) - iVar5) + 0x14 + (int)param_1);
        *pfVar1 = _DAT_00a171c0 * local_3c + *pfVar1;
        pfVar1 = (float *)(*(int *)(in_ECX + 0x5c) + 0x1c + iVar10);
        *pfVar1 = DAT_009af898 * local_3c + *pfVar1;
        local_3c = local_3c * (float)_DAT_00a171b8;
      }
      uVar11 = uVar8;
      if (0xfe < (int)uVar8) {
        uVar11 = 0xff;
      }
      if ((int)uVar11 < 1) {
        uVar8 = 0;
      }
      else if (0xfe < (int)uVar8) {
        uVar8 = 0xff;
      }
      param_1 = param_1 + iVar4 * 4;
      iVar10 = iVar10 + iVar7;
      *puVar12 = (ushort)((uVar8 & 0xff) << 8) | (ushort)local_18;
      local_1c = local_1c + iVar7;
      puVar12 = puVar12 + iVar4;
      param_2 = param_2 + 1;
    } while (param_2 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008afe0f @ 0x008afe0f ====

void FUN_008afe0f(uint param_1,float param_2,uint param_3)

{
  float fVar1;
  int in_ECX;
  undefined1 *puVar2;
  float *pfVar3;
  uint uVar4;
  float *pfVar5;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = FUN_008ac18d(param_3);
  }
  puVar2 = (undefined1 *)
           (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * (int)param_2 +
           *(int *)(in_ECX + 0x20));
  param_1 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    pfVar5 = (float *)(param_3 + 8);
    do {
      pfVar3 = *(float **)(in_ECX + 0x38);
      uVar4 = 0;
      param_3 = 0;
      param_2 = 3.4028235e+38;
      do {
        fVar1 = (pfVar5[-2] - *pfVar3) * (pfVar5[-2] - *pfVar3) +
                (pfVar5[-1] - pfVar3[1]) * (pfVar5[-1] - pfVar3[1]) +
                (*pfVar5 - pfVar3[2]) * (*pfVar5 - pfVar3[2]) +
                (pfVar5[1] - pfVar3[3]) * (pfVar5[1] - pfVar3[3]);
        if (fVar1 < param_2) {
          uVar4 = param_3;
          param_2 = fVar1;
        }
        param_3 = param_3 + 1;
        pfVar3 = pfVar3 + 4;
      } while (param_3 < 0x100);
      *puVar2 = (char)uVar4;
      puVar2 = puVar2 + 1;
      param_1 = param_1 + 1;
      pfVar5 = pfVar5 + 4;
    } while (param_1 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


// ==== FUN_008afed6 @ 0x008afed6 ====

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_008afed6(uint param_1,uint param_2,float *param_3)

{
  int iVar1;
  float fVar2;
  uint uVar3;
  float *pfVar4;
  int iVar5;
  int in_ECX;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  undefined1 *puVar12;
  undefined2 in_FPUControlWord;
  float local_38;
  int local_8;
  
  if (*(int *)(in_ECX + 0x54) != 0) {
    param_3 = (float *)FUN_008aac69(param_3);
  }
  if (*(int *)(in_ECX + 0x10) != 0) {
    param_3 = (float *)FUN_008ac18d(param_3);
  }
  local_38 = 0.0;
  uVar3 = param_1 & 3;
  uVar6 = param_2 & 3;
  puVar12 = (undefined1 *)
            (*(int *)(in_ECX + 0x60) * param_1 + *(int *)(in_ECX + 100) * param_2 +
             (*(int *)(in_ECX + 0x68) + -1) * (param_1 & 1) + *(int *)(in_ECX + 0x20));
  iVar1 = *(int *)(in_ECX + 0x34);
  if ((param_1 & 1) == 0) {
    iVar10 = 0;
    param_1 = 1;
  }
  else {
    iVar10 = *(int *)(in_ECX + 0x68) + -1;
    param_1 = -1;
  }
  param_2 = CONCAT22(param_2._2_2_,in_FPUControlWord);
  *(uint *)(in_ECX + 0x7c) = param_2;
  uVar7 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    pfVar4 = param_3;
    do {
      uVar7 = uVar7 + 1;
      *pfVar4 = *pfVar4 * _DAT_009fc7b4 + pfVar4[1] * _DAT_009fc7ac + pfVar4[2] * _DAT_009fc7b0;
      pfVar4 = pfVar4 + 4;
    } while (uVar7 < *(uint *)(in_ECX + 0x68));
  }
  if (*(int *)(in_ECX + 0x5c) != 0) {
    FUN_008ac4a9(param_3);
  }
  param_2 = 0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    iVar8 = param_1 * 0x10;
    iVar5 = iVar10 << 4;
    iVar9 = (param_1 + iVar10) * 0x10;
    local_8 = (iVar10 - param_1) * 0x10;
    do {
      fVar2 = (local_38 + *(float *)(iVar5 + (int)param_3)) * DAT_0099d0b8;
      iVar10 = (int)ROUND(fVar2 + *(float *)(iVar1 + (uVar6 + uVar3 * 8) * 4 + (param_2 & 3) * 4));
      if (*(int *)(in_ECX + 0x5c) != 0) {
        pfVar4 = (float *)(local_8 + 0x10 + *(int *)(in_ECX + 0x5c));
        local_38 = (fVar2 - (float)iVar10) * DAT_0099d0b0;
        *pfVar4 = _DAT_00a171c4 * local_38 + *pfVar4;
        pfVar4 = (float *)(iVar5 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar4 = _DAT_00a171c0 * local_38 + *pfVar4;
        pfVar4 = (float *)(iVar9 + 0x10 + *(int *)(in_ECX + 0x5c));
        *pfVar4 = DAT_009af898 * local_38 + *pfVar4;
        local_38 = local_38 * (float)_DAT_00a171b8;
      }
      iVar11 = iVar10;
      if (0xfe < iVar10) {
        iVar11 = 0xff;
      }
      if (iVar11 < 1) {
        iVar10 = 0;
      }
      else if (0xfe < iVar10) {
        iVar10 = 0xff;
      }
      *puVar12 = (char)iVar10;
      local_8 = local_8 + iVar8;
      puVar12 = puVar12 + param_1;
      iVar5 = iVar5 + iVar8;
      iVar9 = iVar9 + iVar8;
      param_2 = param_2 + 1;
    } while (param_2 < *(uint *)(in_ECX + 0x68));
  }
  return;
}


